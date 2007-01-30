/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2005 The International Cooperation for the Integration of 
 * Processes in  Prepress, Press and Postpress (CIP4).  All rights
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end- documentation included with the redistribution,
 *    if any, must include the following acknowledgment:  
 *       "This product includes software developed by the
 *        The International Cooperation for the Integration of 
 *        Processes in  Prepress, Press and Postpress (www.cip4.org)"
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "CIP4" and "The International Cooperation for the Integration of
 *    Processes in  Prepress, Press and Postpress" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact info@cip4.org.
 *
 * 5. Products derived from this software may not be called "CIP4",
 *    nor may "CIP4" appear in their name, without prior written
 *    permission of the CIP4 organization
 *
 * Usage of this software in commercial products is subject to restrictions. For
 * details please consult info@cip4.org.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE INTERNATIONAL COOPERATION FOR
 * THE INTEGRATION OF PROCESSES IN PREPRESS, PRESS AND POSTPRESS OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the The International Cooperation for the Integration
 * of Processes in Prepress, Press and Postpress and was
 * originally based on software
 * copyright (c) 1999-2001, Heidelberger Druckmaschinen AG
 * copyright (c) 1999-2001, Agfa-Gevaert N.V.
 *
 * For more information on The International Cooperation for the
 * Integration of Processes in  Prepress, Press and Postpress , please see
 * <http://www.cip4.org/>.
 *
 *
 */
/******************************************************************************
 *                     Copyright 1998 Agfa-Gevaert N.V.                       *
 *                           All rights reserved                              *
 *                                                                            *
 * The material contained herein may not be reproduced in whole or in part,   *
 *        without the prior written consent of Agfa-Gevaert N.V.              *
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
 *  Includes
 ******************************************************************************/

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <dirent.h>
#include <utime.h>

#include <stat.h>
#include <time.h>

#include <xercesc/util/XMLUniDefs.hpp>

//John.Klippenstein@kodak.com - Exception.h has moved to a new location
#include <jdf/lang/Exception.h>
#include <jdf/io/File.h>
#include <jdf/lang/Janitor.h>

#include <jdf/io/Platforms/Carbon/CarbonFileSystem.h>


#ifndef MAX_PATH
#   define MAX_PATH 65535
#endif


XERCES_CPP_NAMESPACE_USE


namespace JDF
{

/******************************************************************************
 *  Implementation
 ******************************************************************************/
FileSystem* FileSystem::getFileSystem()
{
    return new CarbonFileSystem();
}

CarbonFileSystem::CarbonFileSystem()
    : slash    (chColon),
      altSlash (chColon),
      semicolon(chSemiColon)
{
}


bool CarbonFileSystem::checkAccess(const File& file, bool flag)
{
    JDF::ArrayJanitor<const char> path(file.getAbsolutePath().getBytes());

    return (access(path.get(), ((flag) ? W_OK : R_OK)) == 0);
}


int CarbonFileSystem::compare(const File& f1, const File& f2)
{
    return (f1.getPath().toUpperCase() == f2.getPath().toUpperCase());
}


bool CarbonFileSystem::createDirectory(const File& file)
{
    JDF::ArrayJanitor<const char> path(file.getAbsolutePath().getBytes());

    if (mkdir(path.get(), S_IRUSR | S_IWUSR) == 0)
        return true;

    return (errno == EEXIST);
}


bool CarbonFileSystem::createFileExclusively(WString fileName)
{
    JDF::ArrayJanitor<const char> path(fileName.getBytes());

    {
        FILE* fd = fopen(path.get(), "r"); // try first to open the named file, if it's possible abort and return false

        if (fd)
        {
            fclose(fd);
            return false;
        }
    }

    {
        FILE* fd = fopen(path.get(), "w"); // try fist to open the named file, if it's possible abort and return false

        if (fd)
        {
            fclose(fd);
            return true;
        }
    }

    return false;
}


bool CarbonFileSystem::deleteFile(const File& file)
{
    JDF::ArrayJanitor<const char> path(file.getAbsolutePath().getBytes());

    return (remove(path.get()) == 0);
}


bool CarbonFileSystem::deleteDirectory(const File& file)
{
    JDF::ArrayJanitor<const char> path(file.getAbsolutePath().getBytes());
  
    return (rmdir(path.get()) == 0);
}


File CarbonFileSystem::createAliasFile(const File& path, const File& file)
{
    throw IOException("Failed to create alias");

    return file;
}


File CarbonFileSystem::resolveAliasFile(const File& file)
{
    throw IOException("resolveAliasFile() failed!");

    return file;
}


bool CarbonFileSystem::checkAliasFile(const File& file)
{
    return false;
}


JDFUInt32 CarbonFileSystem::getBooleanAttributes(const File& file)
{
    JDF::ArrayJanitor<const char> path(file.getPath().getBytes());

    JDFUInt32 attribs = 0;

    struct stat buf;

    if (stat(path.get(), &buf) == 0)
    {
        attribs |= BA_EXISTS;

        if (buf.st_mode & S_IFDIR)
            attribs |= BA_DIRECTORY;
        else
            attribs |= BA_REGULAR;
    }

    return attribs;
}


WString CarbonFileSystem::getDefaultParent()
{
    return WString(1, slash);
}


JDFUInt64 CarbonFileSystem::getLastModifiedTime(const File& file)
{
    JDF::ArrayJanitor<const char> path(file.getPath().getBytes());

    time_t t = 0;

    struct stat buf;

    if (stat(path.get(), &buf) == 0)
        t = buf.st_mtime;

    return (JDFUInt64) t;
}


JDFUInt64 CarbonFileSystem::getCreationTime(const File& file)
{
    JDF::ArrayJanitor<const char> path(file.getPath().getBytes());

    time_t t = 0;

    struct stat buf;

    if (stat(path.get(), &buf) == 0)
        t = buf.st_ctime;

    return (JDFUInt64) t;
}


JDFUInt64 CarbonFileSystem::getLength(const File& file)
{
    JDF::ArrayJanitor<const char> path(file.getPath().getBytes());

    off_t l = 0;

    struct stat buf;

    if (stat(path.get(), &buf) == 0)
        l = buf.st_size;

    return (JDFUInt64) l;
}


JDFCh CarbonFileSystem::getPathSeparator()
{
    return semicolon;
}


JDFCh CarbonFileSystem::getSeparator()
{
    return slash;
}


bool CarbonFileSystem::isAbsolute(const File& file)
{
     int i = getPrefixLength(file);
     return (i == 2 && file.getPath().at(0) == slash) || (i == 3);
}


std::list<WString> CarbonFileSystem::list(const File& file)
{
    File searchDir(file, "*");

    JDF::ArrayJanitor<const char> path(file.getAbsolutePath().getBytes());

    std::list<WString> fileList;

    DIR* myDir = opendir(path.get());

    if (!myDir)
        throw IOException("Cannot open directory.");

    rewinddir(myDir);

    dirent* myDirEntry = (dirent*) NULL;

    while ((myDirEntry = readdir(myDir)) != NULL)
    {
        if ((strcmp(myDirEntry->d_name,".") == 0) || (strcmp(myDirEntry->d_name, "..") == 0))
                continue;

        fileList.push_back(WString(myDirEntry->d_name));
    }

    closedir(myDir); // release the structure DIR* myDir too

    return fileList;
}


std::list<File> CarbonFileSystem::listRoots()
{
    std::list<File> rootList;

    return rootList;
}


WString CarbonFileSystem::normalize(const WString& s)
{
    return s; // nothing to do
}


WString CarbonFileSystem::normalize(const WString& s, int i, int j)
{
    return s; // nothing to do
}


int CarbonFileSystem::normalizePrefix(const WString& s, int i, WString& stringbuffer)
{
    int j;
    
    for(j = 0; j < i && isSlash(s.at(j)); j++) {}
    
    JDFCh c;
    if(i - j >= 2 && isLetter(c = s.at(j)) && s.at(j + 1) == chColon)
    {
        stringbuffer.append(1,c);
        stringbuffer.append(1,chColon);
        j += 2;
    }
    else
    {
        j = 0;
        if(i >= 2 && isSlash(s.at(0)) && isSlash(s.at(1)))
        {
            j = 1;
            stringbuffer.append(1,slash);
        }
    }
    return j;
}


int CarbonFileSystem::prefixLength(const WString& s)
{
    JDFCh c = slash;
    int i = s.length();
    if(i == 0)
        return 0;
    JDFCh c1 = s.at(0);
    JDFCh c2 = i <= 1 ? chNull : s.at(1);
    if(c1 == c)
        return c2 != c ? 1 : 2;
    if(isLetter(c1) && c2 == chColon)
        return i <= 2 || s.at(2) != c ? 2 : 3;
    else
        return 0;
}


bool CarbonFileSystem::isSlash(JDFCh c)
{
    return ((c == chBackSlash) || (c == chForwardSlash));
}


bool CarbonFileSystem::isLetter(JDFCh c)
{
    return ((c >= chLatin_a) && (c <= chLatin_z) || (c >= chLatin_A) || (c <= chLatin_Z));
}


WString CarbonFileSystem::slashify(const WString& s)
{
    if ((s.length() == 0) || isSlash(s.at(0)))
        return s;

    return slash + s;
}


WString CarbonFileSystem::getDrive(const WString& s)
{
    int i = prefixLength(s);
    return i != 3 ? "" : s.substr(0, 2);
}


bool CarbonFileSystem::rename(File& src, File& target)
{
    File targetParentFile = target.getParentFile();

    if (targetParentFile.getPath().length() == 0)
    {
        char* srcPath = src.getAbsolutePath().getBytes();
        char* destPath = File(src.getParentFile(),target.getName()).getAbsolutePath().getBytes();
        bool ret = !((bool)::rename(srcPath,destPath));
        delete[] srcPath;
        delete[] destPath;
        return ret;
    }

    if (src.getParentFile() == target.getParentFile())
    {
        char* srcPath = src.getAbsolutePath().getBytes();
        char* destPath = target.getAbsolutePath().getBytes();
        bool ret = !((bool)::rename(srcPath,destPath));
        delete[] srcPath;
        delete[] destPath;
        return ret;
    }
    else
        return false;
}


bool CarbonFileSystem::moveTo(const File& src, const File& dst)
{
    File targetParentFile = dst.getParentFile();
    if (targetParentFile.getPath().length() == 0)
    {
        char* srcPath = src.getAbsolutePath().getBytes();
        char* destPath = File(src.getParentFile(),dst.getName()).getAbsolutePath().getBytes();
        bool ret = !((bool)::rename(srcPath,destPath));
        delete[] srcPath;
        delete[] destPath;
        return ret;
    }

    if (src.getParentFile() == dst.getParentFile())
    {
        char* srcPath = src.getAbsolutePath().getBytes();
        char* destPath = dst.getAbsolutePath().getBytes();
        bool ret = !((bool)::rename(srcPath,destPath));
        delete[] srcPath;
        delete[] destPath;
        return ret;
    }
    else
        return false;

}

WString CarbonFileSystem::getUserPath()
{
    char* temp = new char[MAX_PATH+1];
//  if (gOnNT)
//  {
//      JDFCh cwd[ MAX_PATH ];
//      GetCurrentDirectoryW(MAX_PATH, cwd);
//      return WString(cwd);
//  }
//  else
//  {
//      char cwd[ MAX_PATH ];
//      GetCurrentDirectory(MAX_PATH, cwd);
//      return WString(cwd);
//  }
#if 0
    return WString(getcwd(temp));
#endif

    return WString("");
}


WString CarbonFileSystem::getDriveDirectory(JDFCh c)
{
    return WString(JDFStrL(""));
}


WString CarbonFileSystem::resolve(const File& file)
{
    WString s = file.getPath();
    return s; // SF250202
    int i = getPrefixLength(file);

    if(i == 2 && s.at(0) == slash)
        return s;

    if(i == 3)
        return s;

    if(i == 0)
        return getUserPath() + slashify(s);

    if(i == 1)
    {
        WString s1 = getUserPath();
        WString s3 = getDrive(s1);
        if(s3 != JDFStrL(""))
            return s3 + s;
        else
            return s1 + s;
    }
    if(i == 2)
    {
        WString s2 = getUserPath();
        WString s4 = getDrive(s2);
        if(s4 != "" && (s.substr(0,2) == s4))
            return s2 + slashify(s.substr(2));

        JDFCh c = s.at(0);
        WString  s5 = getDriveDirectory(c);
        if(s5 != "")
        {
            WString s6(1,c);
            s6+= ":" + s5 + slashify(s.substr(2));
            return s6;
        }
        else
        {
            return WString(1,c) + ":" + slashify(s.substr(2));
        }
    }
    else
    {
//        throw new InternalError("Unresolvable path: " + s);
        return WString(JDFStrL(""));
    }
}


WString CarbonFileSystem::resolve(const WString& s, const WString& s1)
{
    JDFCh c = slash;
    int i  = s.length();

    if(i == 0)
        return s1;

    int j = s1.length();
    if(j == 0)
        return s;

    WString s2 = s1;

    if(j > 1 && s2.at(0) == c)
        if(s2.at(1) == c)
            s2 = s2.substr(2);
        else
            s2 = s2.substr(1);

    WString s3 = s;
    if(s3.at(i - 1) == c)
        s3 = s3.substr(0, i - 1);
    return s3 + slashify(s2);
}

// add By Okada
WString CarbonFileSystem::fromURIPath(const WString& host,const WString& path)
{
	return WString::emptyStr;
}

bool CarbonFileSystem::setLastModifiedTime(const File& file, JDFUInt64 time)
{
    JDF::ArrayJanitor<const char> path(file.getPath().getBytes());

    struct utimbuf times;

    times.modtime = time;

    return (utime(path.get(), &times) == 0);
}


bool CarbonFileSystem::setReadOnly(const File& file)
{
    JDF::ArrayJanitor<const char> path(file.getPath().getBytes());

    struct stat buf;

    if (!stat(path.get(), &buf)){
        return false;
    }

    mode_t protection = (buf.st_mode & (0xFFFFFFFF & S_IWUSR));

    return (chmod(path.get(), protection) == 0);
}


WString CarbonFileSystem::canonicalize(const WString& s) // throw IOException
{
//  if (gOnNT)
//  {
//      JDFCh fullPath[MAX_PATH];
//      JDFCh* filePart;
//      if (GetFullPathNameW(s.c_str(),MAX_PATH,fullPath, &filePart) == 0)
//          throw IOException("invalid path name");
//      return WString(fullPath);
//  }
//  else
//  {
//      char fullPath[MAX_PATH];
//      char* filePart;
//      char* tmp = s.getBytes();
//      if (GetFullPathName(tmp,MAX_PATH,fullPath, &filePart) == 0)
//      {
//          delete[] tmp;
//          throw IOException("invalid path name");
//      }
//      delete[] tmp;
//      return WString(fullPath);
//  }
    return s;
}


JDFUInt64 CarbonFileSystem::getLastAccessedTime(const File& file)
{
    JDF::ArrayJanitor<const char> path(file.getPath().getBytes());

    time_t t = 0;

    struct stat buf;

    if (stat(path.get(), &buf) == 0)
        t = buf.st_atime;

    return (JDFUInt64) t;
}


bool CarbonFileSystem::copyTo(const File& src, const File& dst)
{
// TODO: check if destination is readonly

#   define COPYTO_BUFFER_SIZE 4096

    JDF::ArrayJanitor<const char> pathDst(dst.getAbsolutePath().getBytes());
    JDF::ArrayJanitor<const char> pathSrc(src.getAbsolutePath().getBytes());

	FILE* in = fopen(pathSrc.get(), "r");

    if (!in)
		return false;

    FILE* out = fopen(pathDst.get(), "w");

    if (!out)
    {
		fclose(in);
		return false;
	}

	char buf[COPYTO_BUFFER_SIZE];

    bool bRes = false;
    
    for (;;)
    {
        int iRead = ::fread(buf, sizeof(buf), 1, in);

        if (iRead == -1)
           break;

        if (iRead == 0)
        {
            bRes = true;
            break;
        }

        int iWrite = ::fwrite(buf, iRead, 1, out);

        if (iWrite == -1)
            break;
    }

    fclose(in);
    fclose(out);

    return bRes;
}


bool CarbonFileSystem::makeWritable(const File& file)
{
    struct stat fprop;
    char* tmpName = file.getName().getBytes();
    mode_t protection;

    if (!stat (tmpName, &fprop)){
        delete(tmpName);
        return false;
    }

    protection = fprop.st_mode | S_IWUSR;

    if (!chmod(tmpName,protection)){
        delete[] tmpName;
        return false;
    }

    delete(tmpName);
    return true;
}


// check if a path is a root
//
// returns:
//  TRUE for "\" "X:\" "\\foo\asdf" "\\foo\" 
//  FALSE for others 
 
bool CarbonFileSystem::isRoot(const File& file)
{
    return (getPrefixLength(file) && getPrefixLength(file) == file.getPath().length() && !isSlash(file.getPath()[0]) );
}


#include <CFBundle.h>
#include <Folders.h>

static WString getSystemVolumeName()
{
    static WString strSystemVolumeName;
    
    if (!strSystemVolumeName.empty())
        return strSystemVolumeName;    	

    SInt16 vRefNum; 
    SInt32 foundDirID;

    OSErr err = FindFolder(kOnSystemDisk, kSystemFolderType, kDontCreateFolder, &vRefNum, &foundDirID);

    if (err != 0)
        return strSystemVolumeName;

    // Get its name, Unicode
    HFSUniStr255 volumeName;
    
    err = FSGetVolumeInfo(vRefNum, 0, NULL, kFSVolInfoNone, NULL, &volumeName, NULL); 

    if (err != 0)
        return strSystemVolumeName;

    for (int i = 0; i < volumeName.length; i++)
    {
       strSystemVolumeName += (char) volumeName.unicode[i];
    }

    return strSystemVolumeName;
}


File CarbonFileSystem::tempFilePath()
{
    WString path(L":"); // default

    WString strSystemVolumeName = getSystemVolumeName();

    if (!strSystemVolumeName.empty())
    {
    	path = strSystemVolumeName + L":private:tmp";
    }

    return path;
}


} // namespace JDF

/* end of file */
