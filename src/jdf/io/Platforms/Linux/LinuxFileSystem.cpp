/*
 * The CIP4 Software License, Version 0.1
 *
 *
 * Copyright (c) 2001 The International Cooperation for the Integration of 
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
 *	Includes
 ******************************************************************************/
#include "LinuxFileSystem.h"

#include <jdf/io/Exception.h>
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
#define MAX_PATH 65535
#endif

namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/

// helper functions
void addUNCPrefetch(WString& s);
void replaceYenWonSigns(WString& s);


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

static bool gOnNT = true;

FileSystem* FileSystem::getFileSystem()
{
	return new LinuxFileSystem();
}

LinuxFileSystem::LinuxFileSystem() :
	slash(chBackSlash),
	altSlash(chForwardSlash),
	semicolon(chSemiColon)
{
    // TBD: to be implemented when necessary, otherwise trash
    //OSVERSIONINFO   OSVer;
    //OSVer.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    //::GetVersionEx(&OSVer);
    //gOnNT = (OSVer.dwPlatformId == VER_PLATFORM_WIN32_NT);
}

bool LinuxFileSystem::checkAccess(const File& file, bool flag)
{
	//BY_HANDLE_FILE_INFORMATION info;
	bool retVal= false;
	char *tmpName = file.getAbsolutePath().getBytes();
	if (access(tmpName,R_OK) == 0)
	{
		if (flag)
			retVal = !(access(tmpName,W_OK));
		else
			retVal = true;
	}
	delete[] tmpName;
	return retVal;
}

int LinuxFileSystem::compare(const File& f1, const File& f2)
{
	return (f1.getPath().toUpperCase() == f2.getPath().toUpperCase());
}

void replaceYenWonSigns(WString& s)
{
	for (int i=0;i<s.length(); i++)
	{
		if (s[i] == chYenSign || s[i] == chWonSign)
			s[i] = chForwardSlash;
	}
}

bool LinuxFileSystem::createDirectory(const File& file)
{
	// handle paths longer than 255 characters;
	WString absolutePath = file.getAbsolutePath();

	int retVal;
	int errVal;
	char* tmpName = absolutePath.getBytes();
	retVal = mkdir(tmpName,S_IRUSR|S_IWUSR);
	errVal = errno;
	delete[] tmpName;

	if (retVal != 0){
		if (errVal == EEXIST){
			return true;
		}
		return false;
	}

	return true;

}

bool LinuxFileSystem::createFileExclusively(WString pathname)
{
	bool retVal = false;
	char* tmpName = pathname.getBytes();

	FILE* fd = fopen(tmpName,"r");  // try frist to open the named file, if it's possible abort and return false
	if ( fd ) {
		fclose(fd);
		delete[] tmpName;
		return false;
	}

	fd = fopen(tmpName,"w");  // try frist to open the named file, if it's possible abort and return false
	if ( fd ) {
		fclose(fd);
		retVal = true;
	}
	delete[] tmpName;
	return retVal;

}

bool LinuxFileSystem::deleteFile(const File& file)
{
	char* pathname = file.getAbsolutePath().getBytes();
	bool bRet = false;
	int errVal;

	if (remove(pathname)){
		errVal = errno;
		bRet = true;
	}

	delete[] pathname;
	return bRet;
}

bool LinuxFileSystem::deleteDirectory(const File& file)
{

	char* pathname = file.getAbsolutePath().getBytes();
	bool bRet = false;
	int errVal;

	if (remove(pathname)){
		errVal = errno;
		bRet = true;
	}

	delete[] pathname;
	return bRet;
}

File LinuxFileSystem::createAliasFile(const File& path, const File& file)
{

	WString aliasFileName = file.getName() + ".lnk";
	File aliasFile= File(path,aliasFileName);

	char * src = file.getAbsolutePath().getBytes();
	char * dst = aliasFile.getAbsolutePath().getBytes();

	int iVal =symlink(src,dst);
	delete[] src;
	delete[] dst;
	if (iVal != 0){
		throw IOException("Failed to create alias");
	}

	return aliasFile;

}

File LinuxFileSystem::resolveAliasFile(const File& file)
{
	char buffer[MAX_PATH+1];
	char* tmpName = file.getName().getBytes();
	int iVal = readlink(tmpName,buffer,MAX_PATH);

	delete[] tmpName;


	if ( iVal < 0 ){
		throw IOException("Failed to create alias");
	}
	return File(buffer);
}

bool LinuxFileSystem::checkAliasFile(const File& file)
{
	char buffer[MAX_PATH+1];
	char* tmpName = file.getName().getBytes();
	int iVal = readlink(tmpName,buffer,MAX_PATH);

	delete[] tmpName;

	if ( iVal < 0 ){
		return false;
	}
	return true;
}

JDFUInt32 LinuxFileSystem::getBooleanAttributes(const File& file)
{



//	// TBD:
	JDFUInt32 attribs = 0;
	struct stat buf;
	mode_t myMode;
	char *tmpName = file.getName().getBytes();

	if (stat (tmpName,&buf)==0){
  		myMode = buf.st_mode;
		attribs |= BA_EXISTS;
		if (myMode & S_IFDIR)
			attribs |= BA_DIRECTORY;
		else
			attribs |= BA_REGULAR;

//		if (info.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)
//			attribs |= BA_HIDDEN;
//
//		if (!(info.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
//			attribs |= BA_REGULAR;
	}



	delete[] tmpName;



///	BY_HANDLE_FILE_INFORMATION info;
//
//	WString path(file.getAbsolutePath());
//	if (getFileInformation(path, &info) == TRUE)
//	{
//		attribs |= BA_EXISTS;
//		if (info.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
//			attribs |= BA_DIRECTORY;
//
//		if (info.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)
//			attribs |= BA_HIDDEN;
//
//		if (!(info.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
//			attribs |= BA_REGULAR;
//	}
	return attribs;
}

WString LinuxFileSystem::getDefaultParent()
{
	return WString(1,slash);
}

JDFUInt64 LinuxFileSystem::getLastModifiedTime(const File& file)
{
	struct stat buf;
	time_t lmtime;
	char *tmpName = file.getName().getBytes();

	stat (tmpName,&buf);
	lmtime = buf.st_mtime;

	delete[] tmpName;
	return (JDFUInt64)lmtime;
}

JDFUInt64 LinuxFileSystem::getCreationTime(const File& file)
{
	struct stat buf;
	time_t lctime;
	char *tmpName = file.getName().getBytes();

	stat (tmpName,&buf);
	lctime = buf.st_ctime;

	delete[] tmpName;
	return (JDFUInt64)lctime;
}

JDFUInt64 LinuxFileSystem::getLength(const File& file)
{
	struct stat buf;
	off_t fileSize;
	char *tmpName = file.getName().getBytes();

	stat (tmpName,&buf);
	fileSize = buf.st_size;

	delete[] tmpName;
	return (JDFUInt64)fileSize;
}

JDFCh LinuxFileSystem::getPathSeparator()
{
	return semicolon;
}

JDFCh LinuxFileSystem::getSeparator()
{
    return slash;
}

bool LinuxFileSystem::isAbsolute(const File& file)
{
     int i = getPrefixLength(file);
     return (i == 2 && file.getPath().at(0) == slash) || (i == 3);
}

std::list<WString> LinuxFileSystem::list(const File& file)
{

	File searchDir(file,"*");
	std::list<WString>  fileList;

	char* absolutePath = searchDir.getAbsolutePath().getBytes();

	DIR* myDir;
	dirent *myDirEntry = (dirent*)NULL;

	myDir = opendir(absolutePath);
	if (!myDir){
		delete[] absolutePath;
		throw IOException("Cannot open directory.");
	}

	rewinddir(myDir);

   	while ((myDirEntry = readdir(myDir)) != NULL){
        	if (strcmp(myDirEntry->d_name,".") == 0 || strcmp(myDirEntry->d_name,"..")== 0)
            		continue;

		fileList.push_back(WString(myDirEntry->d_name));
	}


/*
    int Result1 = 0;
    int ret_cd2 = 0;
    DIR *dp = (DIR *) NULL;
    Dirent *dirp = (Dirent *) NULL;
    char buff[BUFSIZ];

    if ((dp = opendir(path)) == (DIR *) NULL){
        fprintf(stderr,"Unable to open %s - %s\n",path,strerror(errno));
        return(1);
    }

    while ((dirp = readdir(dp)) != NULL){
        if (strcmp(dirp->d_name,".") == 0 || strcmp(dirp->d_name,"..")== 0)
            continue;

        if (strcmp(path,"/") == 0)
            sprintf(buff,"/%s",dirp->d_name);
        else
            sprintf(buff,"%s/%s",path,dirp->d_name);

        Result1 = isdir(buff);
        if (Result1 == 0){
            fprintf(stdout,"%s\n",buff);
            fflush(stdout);
        }
        else if (Result1 == 1){
            ret_cd2 = process_dir(buff);
            if (ret_cd2 != 0){
                fprintf(stderr,
                        "dir: ERROR: Cannot read dir %s: Permission "
                        "denied\n",
                        buff);
            }
            else{
                fprintf(stdout,"%s\n",buff);
                fflush(stdout);
            }
        }
        else;
    }
    Result1 = 0;
    ret_cd2 = 0;
    closedir(dp);
    return(0);

*/

	delete[] absolutePath;
	closedir(myDir); // release the structure DIR* myDir too


//
//	else
//	{
//		HANDLE hSearch;
//		WIN32_FIND_DATA findData;
//		char* tmp = absolutePath.getBytes();
//
//		hSearch = ::FindFirstFile(tmp, &findData);
//		if (hSearch == INVALID_HANDLE_VALUE)
//			return fileList;
//
//		std::string fileFound(findData.cFileName);
//
//		if (fileFound != "." && fileFound != "..")
//			fileList.push_back(WString(fileFound));
//
//		while (::FindNextFile(hSearch,&findData))
//		{
//			fileFound = findData.cFileName;
//			if (fileFound != "." && fileFound != "..")
//				fileList.push_back(WString(fileFound));
//		}
//		::FindClose(hSearch);
//		delete[] tmp;
//	}
	return fileList;
}

std::list<File> LinuxFileSystem::listRoots()
{
	unsigned int size = MAX_PATH;

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

WString	LinuxFileSystem::normalize(const WString& s)
{
	return s; //SF250202
    int i = s.length();
    JDFCh c = slash;
    JDFCh c1 = altSlash;
    int j = 0;
    for(int k = 0; k < i; k++)
    {
        JDFCh c2 = s.at(k);
        if(c2 == c1)
            return normalize(s, i, j != c ? k : k - 1);
        if(c2 == c && j == c && k > 1)
            return normalize(s, i, k - 1);
        if(c2 == chColon && k > 1)
            return normalize(s, i, 0);
        j = c2;
    }
    if(j == c)
        return normalize(s, i, i - 1);
    else
        return s;
}

WString LinuxFileSystem::normalize(const WString& s, int i, int j)
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

int LinuxFileSystem::normalizePrefix(const WString& s, int i, WString& stringbuffer)
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

int LinuxFileSystem::prefixLength(const WString& s)
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

bool LinuxFileSystem::isSlash(JDFCh c)
{
	return c == chBackSlash || c == chForwardSlash;
}

bool LinuxFileSystem::isLetter(JDFCh c)
{
    return c >= chLatin_a && c <= chLatin_z || c >= chLatin_A || c <= chLatin_Z;
}

WString LinuxFileSystem::slashify(const WString& s)
{
	if(s.length() > 0 && s.at(0) != slash)
        return slash + s;
    else
        return s;
}

WString LinuxFileSystem::getDrive(const WString& s)
{
    int i = prefixLength(s);
    return i != 3 ? "" : s.substr(0, 2);
}

bool LinuxFileSystem::rename(File& src, File& target)
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

bool LinuxFileSystem::moveTo(const File& src, const File& dst)
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

WString LinuxFileSystem::getUserPath()
{
	char* temp = new char[MAX_PATH+1];
//	if (gOnNT)
//	{
//		JDFCh cwd[ MAX_PATH ];
//		GetCurrentDirectoryW(MAX_PATH, cwd);
//		return WString(cwd);
//	}
//	else
//	{
//	    char cwd[ MAX_PATH ];
//		GetCurrentDirectory(MAX_PATH, cwd);
//		return WString(cwd);
//	}
	return WString(getwd(temp));
}

WString LinuxFileSystem::getDriveDirectory(JDFCh c)
{
	return WString(JDFStrL(""));
}

WString LinuxFileSystem::resolve(const File& file)
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

WString LinuxFileSystem::resolve(const WString& s, const WString& s1)
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

bool LinuxFileSystem::setLastModifiedTime(const File& file, JDFUInt64 time)
{
	char* tmpName = file.getAbsolutePath().getBytes();
	struct utimbuf myUtimbuf;

	myUtimbuf.modtime = time;

	bool bRet = (bool) !utime(tmpName,&myUtimbuf);


	delete[] tmpName;
	return bRet;

//	HANDLE hFile;
//
//	WString absolutePath = file.getAbsolutePath();
//
//	if (gOnNT)
//	{
//		addUNCPrefetch(absolutePath);
//		replaceYenWonSigns(absolutePath);
//		hFile = ::CreateFileW((LPCWSTR)absolutePath.c_str(),
//						GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
//						NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
//	}
//	else
//	{
//		char* tmp = absolutePath.getBytes();
//		hFile = ::CreateFile(tmp,
//						GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
//						NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
//		delete[] tmp;
//	}
//
//	// invalid path
//
//	if (hFile == INVALID_HANDLE_VALUE)
//		return false;
//
//	FILETIME modificationTime = BiasTimeNative(time);
//	BOOL res = ::SetFileTime(hFile, NULL, NULL, &modificationTime);
//	::CloseHandle(hFile);
//	return (res == TRUE);
	return true;
}

bool LinuxFileSystem::setReadOnly(const File& file)
{
	struct stat fprop;
	char* tmpName = file.getName().getBytes();
	mode_t protection;

	if (!stat (tmpName, &fprop)){
		delete(tmpName);
		return false;
	}

	protection = fprop.st_mode & (0xFFFFFFFF & S_IWUSR);

	if (!chmod(tmpName,protection)){
		delete[] tmpName;
		return false;
	}

	delete(tmpName);
	return true;
//	WString absolutePath = file.getAbsolutePath();
//
//	// keep old attributes
//
//	// solve MAX_PATH limit
//	if (gOnNT)
//	{
//		addUNCPrefetch(absolutePath);
//		replaceYenWonSigns(absolutePath);
//		DWORD fileAttributes = ::GetFileAttributesW((LPCWSTR)absolutePath.c_str());
//		return (::SetFileAttributesW((LPCWSTR)absolutePath.c_str(), fileAttributes | FILE_ATTRIBUTE_READONLY) != 0);
//	}
//	else
//	{
//		char* tmp = absolutePath.getBytes();
//		DWORD fileAttributes = ::GetFileAttributes(tmp);
//		BOOL ret = ::SetFileAttributes(tmp, fileAttributes | FILE_ATTRIBUTE_READONLY);
//		delete[] tmp;
//		return (ret == TRUE);
//	}
	return true;
}

WString LinuxFileSystem::canonicalize(const WString& s) // throw IOException
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



JDFUInt64 LinuxFileSystem::getLastAccessedTime(const File& file)
{
	struct stat buf;
	time_t lctime;
	char *tmpName = file.getName().getBytes();

	stat (tmpName,&buf);
	lctime = buf.st_atime;

	delete[] tmpName;
	return (JDFUInt64)lctime;
}

bool LinuxFileSystem::copyTo(const File& src, const File& dst)
{
	// check if destination is readonly

	char* srcFile = src.getAbsolutePath().getBytes();
	char* dstFile = dst.getAbsolutePath().getBytes();

	int c;
	FILE *in, *out;

	in  =  fopen(srcFile, "r");
	if (!in){
		return false;
	}
	out  =  fopen(dstFile, "w");
	if (!out){
		fclose(in);
		return false;
	}

	while((c = fgetc(in)) != EOF) fputc(c,out);
	fclose(in);
	fclose(out);
	delete[] srcFile;
	delete[] dstFile;
	return true;
}

bool LinuxFileSystem::makeWritable(const File& file)
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

File LinuxFileSystem::tempFilePath()
{
	WString path = getUserPath()+WString("\\temp");
	createDirectory(path);
//	unsigned int retSize;
//
//	if (gOnNT)
//	{
//		unsigned short *tempPath;
//
//		retSize = ::GetTempPathW(0,NULL);
//		tempPath = new unsigned short[retSize];
//		ArrayJanitor<unsigned short> tempPathJanitor(tempPath);
//		::GetTempPathW(retSize,tempPath);
//		return File(tempPath);
//	}
//	else
//	{
//		char *tempPath;
//
//		retSize = ::GetTempPath(0,NULL);
//		tempPath = new char[retSize];
//		ArrayJanitor<char> tempPathJanitor(tempPath);
//		::GetTempPath(retSize,tempPath);
//		return File(WString(tempPath));
//	}
	return File(path);
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
 
bool LinuxFileSystem::isRoot(const File& file)
{
	return (getPrefixLength(file) && getPrefixLength(file) == file.getPath().length() && !isSlash(file.getPath()[0]) );
}



} // namespace JDF

/* end of file */
