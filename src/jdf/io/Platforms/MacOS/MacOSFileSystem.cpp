/*
 * The CIP4 Software License, Version 0.1
 *
 *
 * Copyright (c) 2001-2007 The International Cooperation for the Integration of
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
 * copyright (c) 1999-2007, Heidelberger Druckmaschinen AG
 * copyright (c) 1999-2007, Agfa-Gevaert N.V.
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
 *	Includes
 ******************************************************************************/

#include <CoreServices/CoreServices.h>

#include "MacOSFileSystem.h"

#include <jdf/io/File.h>

#include <jdf/lang/Exception.h>
#include <jdf/lang/Janitor.h>

#include <xercesc/util/XMLUniDefs.hpp>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <dirent.h>
#include <utime.h>

#ifndef MAX_PATH
#   define MAX_PATH 65535
#endif


XERCES_CPP_NAMESPACE_USE


namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/

// helper functions
static void addUNCPrefetch    (WString& s);
static void replaceYenWonSigns(WString& s);


/******************************************************************************
 *	Defines and constants
 ******************************************************************************/


/******************************************************************************
 *	Typedefs
 ******************************************************************************/


/******************************************************************************
 *	Classes
 ******************************************************************************/

/******************************************************************************
 *	Prototypes
 ******************************************************************************/


/******************************************************************************
 *	Implementation
 ******************************************************************************/


FileSystem* FileSystem::getFileSystem()
{
	return new MacOSFileSystem();
}


MacOSFileSystem::MacOSFileSystem()
    : slash    (chForwardSlash),
	  altSlash (chForwardSlash),
	  semicolon(chSemiColon)
{
}


bool MacOSFileSystem::checkAccess(const File& file, bool flag)
{
	bool bRes = false;

	WString absolutePath(file.getAbsolutePath());

	if (access(absolutePath.peekBytes(), R_OK) == 0)
	{
		if (flag)
			bRes = !(access(absolutePath.peekBytes(), W_OK));
		else
			bRes = true;
	}

	return bRes;
}


int MacOSFileSystem::compare(const File& f1, const File& f2)
{
	return (f1.getPath().toUpperCase() == f2.getPath().toUpperCase());
}


void replaceYenWonSigns(WString& s)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		if ((s[i] == chYenSign) || (s[i] == chWonSign))
			s[i] = chForwardSlash;
	}
}


bool MacOSFileSystem::createDirectory(const File& file)
{
	WString absolutePath = file.getAbsolutePath();

	if (mkdir(absolutePath.peekBytes(), (S_IRUSR | S_IWUSR | S_IXUSR)) != 0)
	    return (errno == EEXIST);

	return true;
}


bool MacOSFileSystem::createFileExclusively(WString pathname)
{
    bool bRes = false;

	FILE* fd = fopen(pathname.peekBytes(), "r");  // try first to open the named file, if it's possible abort and return false

	if (!fd)
    {
    	if ((fd = fopen(pathname.peekBytes(), "w")))
    	    bRes = true;
	}

    if (fd)	fclose(fd);

	return bRes;
}


bool MacOSFileSystem::deleteFile(const File& file)
{
	WString absolutePath = file.getAbsolutePath();

	if (remove(absolutePath.peekBytes()) != 0)
	    return false;

	return true;
}


bool MacOSFileSystem::deleteDirectory(const File& file)
{
	WString absolutePath = file.getAbsolutePath();

	if (remove(absolutePath.peekBytes()) != 0)
	    return false;

	return true;
}


File MacOSFileSystem::createAliasFile(const File& path, const File& file)
{

	WString aliasFileName = file.getName() + L".lnk";

	File aliasFile(path, aliasFileName);

    WString srcFile = file.getAbsolutePath();
	WString dstPath = aliasFile.getAbsolutePath();

	int iVal = symlink(srcFile.peekBytes(), dstPath.peekBytes());
	
	if (iVal != 0)
		throw IOException("Failed to create alias");

	return aliasFile;

}


File MacOSFileSystem::resolveAliasFile(const File& file)
{
	WString absolutePath = file.getAbsolutePath();

	char buf[MAX_PATH + 1];

	int iVal = readlink(absolutePath.peekBytes(), buf, MAX_PATH);

	if (iVal < 0)
		throw IOException("Failed to create alias");

	return File(buf);
}


bool MacOSFileSystem::checkAliasFile(const File& file)
{
	WString absolutePath = file.getAbsolutePath();

	char buf[MAX_PATH + 1];

	int iVal = readlink(absolutePath.peekBytes(), buf, MAX_PATH);

	if (iVal < 0)
		return false;

	return true;
}


JDFUInt32 MacOSFileSystem::getBooleanAttributes(const File& file)
{
	JDFUInt32 attribs = 0;

	WString     absolutePath(file.getAbsolutePath());
	struct stat buf;
	const char * pb = absolutePath.peekBytes();
	int ex = stat(pb,&buf);

	if (stat(absolutePath.peekBytes(),&buf) == 0)
	{
		attribs |= BA_EXISTS;

		if (buf.st_mode & S_IFDIR)
			attribs |= BA_DIRECTORY;
		else
			attribs |= BA_REGULAR;
	}

	return attribs;
}


WString MacOSFileSystem::getDefaultParent()
{
	return WString(1, slash);
}


JDFUInt64 MacOSFileSystem::getLastModifiedTime(const File& file)
{
	time_t lmtime = (time_t) 0;

	WString     absolutePath = file.getAbsolutePath();
	struct stat buf;

	if (stat(absolutePath.peekBytes(), &buf) == 0)
    	lmtime = buf.st_mtime;

	return (JDFUInt64) lmtime;
}


JDFUInt64 MacOSFileSystem::getCreationTime(const File& file)
{
	time_t lctime = 0;

	WString     absolutePath = file.getAbsolutePath();
	struct stat buf;

	if (stat(absolutePath.peekBytes(), &buf) == 0)
    	lctime = buf.st_ctime;

	return (JDFUInt64) lctime;
}


JDFUInt64 MacOSFileSystem::getLength(const File& file)
{
	off_t fileSize = 0;

	WString     absolutePath = file.getAbsolutePath();
	struct stat buf;

	if (stat(absolutePath.peekBytes(), &buf) == 0)
    	fileSize = buf.st_size;

	return (JDFUInt64) fileSize;
}


JDFCh MacOSFileSystem::getPathSeparator()
{
	return semicolon;
}


JDFCh MacOSFileSystem::getSeparator()
{
    return slash;
}


bool MacOSFileSystem::isAbsolute(const File& file)
{
     int i = getPrefixLength(file);

     return ((i == 2) && (file.getPath().at(0) == slash) || (i == 3));
}


std::list<WString> MacOSFileSystem::list(const File& file)
{
	std::list<WString> fileList;

	File    searchDir   (file, "*");
	WString absolutePath(file.getAbsolutePath());

	dirent* pDirEntry = NULL;

	DIR* pDir = opendir(absolutePath.peekBytes());

	if (!pDir)
		throw IOException("Cannot open directory.");

	rewinddir(pDir);

   	while ((pDirEntry = readdir(pDir)) != NULL)
   	{
    	if ((strcmp(pDirEntry->d_name, ".") == 0) || (strcmp(pDirEntry->d_name, "..") == 0))
        		continue;

		fileList.push_back(WString(pDirEntry->d_name));
	}

    closedir(pDir);

    return fileList;
}


std::list<File> MacOSFileSystem::listRoots()
{
	// unsigned int size = MAX_PATH;

	std::list<File> rootList;
	WString deviceStrings;

//	if (gOnNT)
///	{
//		unsigned short *temp = new unsigned short[size];
//		unsigned int retSize;
//
//		if ((retSize = ::GetLogicalDriveStringsW(size,temp)) > size)
//		{
//			size =  retSize;
//			delete[] temp;
//			temp = new unsigned short[size];
//			retSize = ::GetLogicalDriveStringsW(size,temp);
//		}
//		deviceStrings = temp;
//		delete[] temp;
//	}
//	else
///	{
///		char *temp = new char[size];
//		unsigned int retSize;
//
//		if ((retSize = ::GetLogicalDriveStrings(size,temp)) > size)
//		{
//			size =  retSize;
//			delete[] temp;
//			temp = new char[size];
//			retSize = ::GetLogicalDriveStrings(size,temp);
///		}
//		deviceStrings = temp;
//		delete[] temp;
//	}
///	std::string::size_type pos(0), next;
//
//	next = deviceStrings.find(chNull,pos);
//	while (next != WString::npos)
//	{
//		if (next == (pos+1))
//			break;
//
		rootList.push_back(/*File(deviceStrings.substr(pos,next-1))*/WString("\\"));
//		pos = next+1;
//	next = deviceStrings.find(chNull,pos);
//	}

	return rootList;
}


WString	MacOSFileSystem::normalize(const WString& s)
{
	return s; //SF250202
}


WString MacOSFileSystem::normalize(const WString& s, int i, int j)
{
    if(i == 0)
        return s;

    if(j < 3)
        j = 0;

    JDFCh c = slash;

	WString stringbuffer;

    int k;
    if(j == 0)
    {
        k = normalizePrefix(s, i, stringbuffer);
    }
    else
    {
        k = j;
        stringbuffer.append(s.substr(0, j));
    }
    while(k < i)
    {
        JDFCh c1 = s.at(k++);
        if(isSlash(c1))
        {
            for(; k < i && isSlash(s.at(k)); k++);
            if(k == i)
            {
                int l = stringbuffer.length();
                if(l == 2 && stringbuffer.at(1) == ':')
                    stringbuffer.append(1,c);
                else
                if(l == 0)
                    stringbuffer.append(1,c);
                else
                if(l == 1 && isSlash(stringbuffer.at(0)))
                    stringbuffer.append(1,c);
                break;
            }
            stringbuffer.append(1,c);
        }
        else
        {
            stringbuffer.append(1,c1);
        }
    }

	return stringbuffer;
}


int MacOSFileSystem::normalizePrefix(const WString& s, int i, WString& stringbuffer)
{
    int j;
    for(j = 0; j < i && isSlash(s.at(j)); j++);
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


int MacOSFileSystem::prefixLength(const WString& s)
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


bool MacOSFileSystem::isSlash(JDFCh c)
{
	return ((c == chBackSlash) || (c == chForwardSlash));
}


bool MacOSFileSystem::isLetter(JDFCh c)
{
    return ((c >= chLatin_a) && (c <= chLatin_z) || (c >= chLatin_A) || (c <= chLatin_Z));
}


WString MacOSFileSystem::slashify(const WString& s)
{
	if((s.length() > 0) && (s.at(0) != slash))
        return (slash + s);

    return s;
}


WString MacOSFileSystem::getDrive(const WString& s)
{
    int i = prefixLength(s);

    return ((i != 3) ? L"" : s.substr(0, 2));
}


bool MacOSFileSystem::rename(File& src, File& dst)
{
	File dstParentFile = dst.getParentFile();

	if (dstParentFile.getPath().length() == 0)
	{
		WString srcPath  = src.getAbsolutePath();
		WString destPath = File(src.getParentFile(), dst.getName()).getAbsolutePath();

        int iRes = ::rename(srcPath.peekBytes(), destPath.peekBytes());

		return (iRes == 0);
	}


	if (src.getParentFile() == dst.getParentFile())
	{
		WString srcPath  = src.getAbsolutePath();
		WString destPath = dst.getAbsolutePath();

        int iRes = ::rename(srcPath.peekBytes(), destPath.peekBytes());

		return (iRes == 0);
	}

    return false;
}


bool MacOSFileSystem::moveTo(const File& src, const File& dst)
{
	File dstParentFile = dst.getParentFile();

	if (dstParentFile.getPath().length() == 0)
	{
		WString srcPath  = src.getAbsolutePath();
		WString destPath = File(src.getParentFile(), dst.getName()).getAbsolutePath();

        int iRes = ::rename(srcPath.peekBytes(), destPath.peekBytes());

		return (iRes == 0);
	}

	if (src.getParentFile() == dst.getParentFile())
	{
		WString srcPath  = src.getAbsolutePath();
		WString destPath = dst.getAbsolutePath();

        int iRes = ::rename(srcPath.peekBytes(), destPath.peekBytes());

		return (iRes == 0);
	}

    return false;
}


WString MacOSFileSystem::getUserPath()
{
	char temp[MAX_PATH + 1] = "";

	return WString(getwd(temp));
}


WString MacOSFileSystem::getDriveDirectory(JDFCh c)
{
	return WString(JDFStrL(""));
}


WString MacOSFileSystem::resolve(const File& file)
{
	WString ret = WString::emptyStr;
	
	WString relPath = file.getPath();
	WString workingDir = getwd(NULL);
	
	if (!relPath.startsWith(WString::slash))
		workingDir.append(WString::slash);	

	ret = workingDir + relPath;

	return ret;
	
}


WString MacOSFileSystem::resolve(const WString& s, const WString& s1)
{
	JDFCh c = slash;
	int   i = s.length();

	if (i == 0)
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

	return (s3 + slashify(s2));
}


WString MacOSFileSystem::fromURIPath(const WString& host,const WString& path)
{
	WString s = path;

	if ((s.length() > 1) && s.endsWith(JDFStrL("/"))) 
	{
	    // "/foo/" --> "/foo"
	    s = s.substring(0, s.length() - 1);
	}
	if (!host.empty() && host != JDFStrL("localhost"))
	{
		s = JDFStrL("//") + host + s;
	}

	return s;
}


bool MacOSFileSystem::setLastModifiedTime(const File& file, JDFUInt64 time)
{
	WString        absolutePath(file.getAbsolutePath());
	struct utimbuf buf;

	buf.modtime = time;

	if (utime(absolutePath.peekBytes(), &buf) != 0)
        return false;

	return true;
}


bool MacOSFileSystem::setReadOnly(const File& file)
{
	WString     absolutePath(file.getAbsolutePath());
	struct stat buf;

	if (stat(absolutePath.peekBytes(),&buf) != 0)
        return false;

	mode_t pmode = (buf.st_mode & (0xFFFFFFFF & S_IWUSR));

	if (chmod(absolutePath.peekBytes(), pmode) != 0)
		return false;

	return true;
}


WString MacOSFileSystem::canonicalize(const WString& s) // throw IOException
{
//	if (gOnNT)
//	{
//		JDFCh fullPath[MAX_PATH];
//		JDFCh* filePart;
//		if (GetFullPathNameW(s.c_str(),MAX_PATH,fullPath, &filePart) == 0)
//			throw IOException("invalid path name");
//		return WString(fullPath);
//	}
//	else
//	{
//		char fullPath[MAX_PATH];
//		char* filePart;
//		char* tmp = s.getBytes();
//		if (GetFullPathName(tmp,MAX_PATH,fullPath, &filePart) == 0)
//		{
//			delete[] tmp;
//			throw IOException("invalid path name");
//		}
//		delete[] tmp;
//		return WString(fullPath);
//	}
	return s;
}



JDFUInt64 MacOSFileSystem::getLastAccessedTime(const File& file)
{
	time_t lctime = 0;

	WString     absolutePath(file.getAbsolutePath());
	struct stat buf;

	if (stat(absolutePath.peekBytes(),&buf) == 0)
    	lctime = buf.st_atime;

	return (JDFUInt64)lctime;
}


bool MacOSFileSystem::copyTo(const File& src, const File& dst)
{
	// TODO: check if destination is readonly
	
	WString dstFile = dst.getAbsolutePath();
	WString srcFile = src.getAbsolutePath();

	FILE* fin = fopen(srcFile.peekBytes(), "r");

	if (!fin)
		return false;

	FILE* fout = fopen(dstFile.peekBytes(), "w");

	if (!fout)
	{
	    fclose(fout);
	    return false;
	}
	
    bool bRes = true;

    int c = 0;
    
	while ((c = fgetc(fin)) != EOF)
    {
	    if (fputc(c, fout) == EOF)
	    {
	        bRes = false;
	        break;
	    }
	}
	    
	fclose(fin);
	fclose(fout);

	return bRes;
}


bool MacOSFileSystem::makeWritable(const File& file)
{
	WString     absolutePath(file.getAbsolutePath());
	struct stat buf;

	if (stat(absolutePath.peekBytes(),&buf) != 0)
        return false;

	mode_t pmode = buf.st_mode | S_IWUSR;

	if (chmod(absolutePath.peekBytes(), pmode) != 0)
		return false;

	return true;
}


File MacOSFileSystem::tempFilePath()
{
	WString tmpDirName(L"/private/var/tmp"); // default
	FSRef   tmpDirRef;
	
	OSErr err = FSFindFolder(kOnAppropriateDisk, kTemporaryFolderType, kDontCreateFolder,  &tmpDirRef);

	if (err == noErr)
	{
		CFURLRef    tmpDirURL    = CFURLCreateFromFSRef   (kCFAllocatorSystemDefault, &tmpDirRef);
		CFStringRef tempDirPath  = CFURLCopyFileSystemPath(tmpDirURL, kCFURLPOSIXPathStyle);
		const char* pTempDirName = CFStringGetCStringPtr  (tempDirPath, CFStringGetSystemEncoding());

		if (pTempDirName != NULL)
			tmpDirName = pTempDirName;
		if (tempDirPath)
			CFRelease(tempDirPath);    
		if (tmpDirURL)
			CFRelease(tmpDirURL);    
	}

	return File(tmpDirName);
}


void addUNCPrefetch(WString& s)
{
	if (s.substr(0,2) == JDFStrL("\\\\"))
		s.replace(0,2,WString("\\\\?\\UNC\\"));
	else
		s.insert(0,L"\\\\?\\");
}

// check if a path is a root
//
// returns:
//  TRUE for "\" "X:\" "\\foo\asdf" "\\foo\" 
//  FALSE for others 
 
bool MacOSFileSystem::isRoot(const File& file)
{
	return (getPrefixLength(file) && (getPrefixLength(file) == static_cast<int>(file.getPath().length())) && !isSlash(file.getPath()[0]));
}


} // namespace JDF

/* end of file */
