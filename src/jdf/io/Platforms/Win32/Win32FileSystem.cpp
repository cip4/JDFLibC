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
* 3. The end-user documentation included with the redistribution,
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

#include "Win32FileSystem.h"

#include "Win32Shortcut.h"

#include <jdf/io/File.h>
#include <jdf/lang/Exception.h>
#include <jdf/lang/Janitor.h>

#include <string>
#include <io.h> // for 8-bit _access routine


#include <xercesc/util/XMLUniDefs.hpp>

#include <windows.h>


XERCES_CPP_NAMESPACE_USE

namespace JDF
{

	/******************************************************************************
	*	Forward declarations
	******************************************************************************/ 

	// helper functions

	bool getFileInformation(WString pathName, LPBY_HANDLE_FILE_INFORMATION info);
	void addUNCPrefetch(WString& s);
	void replaceYenWonSigns(WString& s);
	JDFUInt64 BiasTime(FILETIME intime);
	FILETIME BiasTimeNative(JDFUInt64 intime);


	/******************************************************************************
	*	Defines and constants
	******************************************************************************/ 

	const JDFCh ILLEGALCHARS[] =
	{
		chBackSlash, chForwardSlash, chColon, chAsterisk, 
			chQuestion, chDoubleQuote, chOpenAngle, chCloseAngle, chPipe   	
	};

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
		return new Win32FileSystem();
	}

	Win32FileSystem::Win32FileSystem() :
	slash(chBackSlash),
		altSlash(chForwardSlash),
		semicolon(chSemiColon)
	{
		OSVERSIONINFO   OSVer;
		OSVer.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
		::GetVersionEx(&OSVer);
		gOnNT = (OSVer.dwPlatformId == VER_PLATFORM_WIN32_NT);
	}

	bool Win32FileSystem::checkAccess(const File& file, bool flag)
	{
		BY_HANDLE_FILE_INFORMATION info;

		if (getFileInformation(file.getAbsolutePath(),&info) == true)
		{
			if (flag)
				return !(info.dwFileAttributes & FILE_ATTRIBUTE_READONLY);
			else
				return true;
		}
		return false;
	}

	int Win32FileSystem::compare(const File& f1, const File& f2)
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

	bool Win32FileSystem::createDirectory(const File& file)
	{
		// handle paths longer than 255 characters;
		WString absolutePath = file.getAbsolutePath();

		BOOL retVal;

#ifdef UNICODE
		if (gOnNT)
		{
			addUNCPrefetch(absolutePath);
			replaceYenWonSigns(absolutePath);
			retVal = ::CreateDirectoryW((LPCWSTR)absolutePath.c_str(),NULL);
		}
		else
		{
			char* tmpName = absolutePath.getBytes();
			retVal = ::CreateDirectoryA(tmpName, NULL);
			delete[] tmpName;
		}
#else
		char* tmpName = absolutePath.getBytes();
		retVal = ::CreateDirectoryA(tmpName, NULL);
		delete[] tmpName;
#endif
		if (retVal == FALSE)
		{
			if (::GetLastError() == ERROR_ALREADY_EXISTS)
				return true;
			return false;
		}
		else
			return true;
	}

	bool Win32FileSystem::createFileExclusively(WString pathname)
	{
		HANDLE	hFile; 

#ifdef UNICODE
		if (gOnNT)
		{
			addUNCPrefetch(pathname);
			replaceYenWonSigns(pathname);
			// get a handle to the file
			hFile = ::CreateFileW((LPCWSTR)pathname.c_str(), 
				GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 
				NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		}
		else
		{
			char* tmpName = pathname.getBytes();
			hFile = ::CreateFileA(tmpName, 
				GENERIC_WRITE,
				FILE_SHARE_READ | FILE_SHARE_WRITE,
				NULL,
				OPEN_ALWAYS,
				FILE_ATTRIBUTE_NORMAL,
				NULL);
			delete[] tmpName;
		}
#else
		char* tmpName = pathname.getBytes();
		hFile = ::CreateFileA(tmpName, 
			GENERIC_WRITE,
			FILE_SHARE_READ | FILE_SHARE_WRITE,
			NULL,
			OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL,
			NULL);	delete[] tmpName;
#endif

		// check for already exists
		if (hFile == INVALID_HANDLE_VALUE)
		{
			DWORD err = ::GetLastError();

			if (err == ERROR_FILE_EXISTS)
			{
				return false;
			}
			else
			{
				throw IOException("Failed to create file",err);
			}
		}
		else
		{
			::CloseHandle(hFile);
			return true;
		}
	}

	bool Win32FileSystem::deleteFile(const File& file)
	{
		WString pathname = file.getAbsolutePath();

#ifdef UNICODE
		if (gOnNT)
		{
			addUNCPrefetch(pathname);
			replaceYenWonSigns(pathname);
			return (::DeleteFileW(pathname.c_str()) == TRUE);
		}
		else
		{
			char* tmpName = pathname.getBytes();
			BOOL ret = ::DeleteFileA(tmpName);
			delete[] tmpName;
			return (ret == TRUE);
		}
#else
		char* tmpName = pathname.getBytes();
		BOOL ret = ::DeleteFileA(tmpName);
		delete[] tmpName;
		return (ret == TRUE);
#endif
	}

	bool Win32FileSystem::deleteDirectory(const File& file)
	{
		WString pathname = file.getAbsolutePath();

#ifdef UNICODE
		if (gOnNT)
		{
			addUNCPrefetch(pathname);
			replaceYenWonSigns(pathname);
			return (::RemoveDirectoryW(pathname.c_str()) == TRUE);
		}
		else
		{
			char* tmpName = pathname.getBytes();
			BOOL ret = ::RemoveDirectoryA(tmpName);
			delete[] tmpName;
			return (ret == TRUE);
		}
#else
		char* tmpName = pathname.getBytes();
		BOOL ret = ::RemoveDirectoryA(tmpName);
		delete[] tmpName;
		return (ret == TRUE);
#endif
	}

	File Win32FileSystem::createAliasFile(const File& path, const File& file)
	{

		WString aliasFileName = file.getName() + ".lnk";
		File aliasFile= File(path,aliasFileName);

		if (0)
		{
			//@vigo
			//char* bytes = aliasFile.getAbsolutePath().getBytes();
			HRESULT hres = LLCreateLinkW(file.getAbsolutePath().c_str(),aliasFile.getAbsolutePath().c_str());
			//delete[] bytes;
			if(!SUCCEEDED(hres))
				throw IOException("Failed to create alias");
			return aliasFile;
		}
		else
		{
			char * src = file.getAbsolutePath().getBytes();
			char * dst = aliasFile.getAbsolutePath().getBytes();
			HRESULT hres = LLCreateLink(src,dst);
			delete[] src;
			delete[] dst;
			if(!SUCCEEDED(hres))
				throw IOException("Failed to create alias");
			return aliasFile;
		}
	}

	File Win32FileSystem::resolveAliasFile(const File& file)
	{
		if (0)
		{
			JDFCh buf[MAX_PATH+1];
			HRESULT hres = LLResolveLinkW(buf, file.getAbsolutePath().c_str());
			if (!SUCCEEDED(hres))
				throw IOException("Failed to create alias");
			return File(buf);
		}
		else
		{
			char buf[MAX_PATH+1];
			char* tmp = file.getAbsolutePath().getBytes();
			HRESULT hres = LLResolveLink(buf, tmp);
			delete[] tmp;
			if (!SUCCEEDED(hres))
				throw IOException("Failed to create alias");
			return File(buf);
		}
	}

	bool Win32FileSystem::checkAliasFile(const File& file)
	{
		WString name = file.getName();
		int pos = name.rfind(chPeriod);
		if (pos != std::string::npos)
		{
			WString ext = name.substr(pos,name.length());
			return (ext  == JDFStrL(".lnk"));
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////
	// 050628 RP added so that a test for exist does not fail on single access files
	bool Win32FileSystem::exists(const File& file)
	{
		bool bExists=false;
		WString pathName(file.getAbsolutePath());
#ifdef UNICODE
		if (gOnNT)
		{
			addUNCPrefetch(pathName);
			replaceYenWonSigns(pathName);

			bExists= !_waccess(pathName.c_str(),00);
		}
		else
		{
			char* tmp = pathName.getBytes();
			bExists= !_access(tmp,00);
			delete[] tmp;
		}

#else
		char* tmp = pathName.getBytes();
		bExists= !_access(tmp,00);
		delete[] tmp;
#endif

		return bExists;

	}

	JDFUInt32 Win32FileSystem::getBooleanAttributes(const File& file)
	{
		JDFUInt32 attribs = 0;
		BY_HANDLE_FILE_INFORMATION info;

		WString path(file.getAbsolutePath());
		if (getFileInformation(path, &info) == TRUE)
		{
			attribs |= BA_EXISTS;
			if (info.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				attribs |= BA_DIRECTORY;

			if (info.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)
				attribs |= BA_HIDDEN;

			if (!(info.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
				attribs |= BA_REGULAR;
		}
		// check alias
		//	if (LLCheckLink(path.data()) == true)
		//	{
		//		attribs |= BA_ALIAS;
		//	}
		return attribs;
	}

	WString Win32FileSystem::getDefaultParent()
	{
		return WString(1,slash);
	}

	JDFUInt64 Win32FileSystem::getLastModifiedTime(const File& file)
	{
		BY_HANDLE_FILE_INFORMATION info;

		if (getFileInformation(file.getAbsolutePath(), &info) == TRUE)
		{
			return BiasTime(info.ftLastWriteTime);
		}
		return 0;
	}

	JDFUInt64 Win32FileSystem::getCreationTime(const File& file)
	{
		BY_HANDLE_FILE_INFORMATION info;

		if (getFileInformation(file.getAbsolutePath(), &info) == TRUE)
		{
			return BiasTime(info.ftCreationTime);
		}
		return 0;
	}

	JDFUInt64 Win32FileSystem::getLength(const File& file) 
	{
		BY_HANDLE_FILE_INFORMATION info;
		JDFUInt64 fileSize = 0;

		if (getFileInformation(file.getAbsolutePath(), &info) == TRUE)
		{
			fileSize   = info.nFileSizeHigh;
			fileSize <<= 32;
			fileSize  += info.nFileSizeLow;
		}
		return fileSize;
	}

	JDFCh Win32FileSystem::getPathSeparator()
	{
		return semicolon;
	}

	JDFCh Win32FileSystem::getSeparator() 
	{
		return slash;
	}

	bool Win32FileSystem::isAbsolute(const File& file)
	{
		int i = getPrefixLength(file);
		return (i == 2 && file.getPath().at(0) == slash) || (i == 3);
	}

	bool Win32FileSystem::containsIllegalCharacter(WString& fileName)
	{
		if (fileName.find_first_of(ILLEGALCHARS,0) != WString::npos)
			return true;
		return false;
	}

	std::list<WString> Win32FileSystem::list(const File& file)
	{
		File searchDir(file,"*");
		std::list<WString>  fileList;

		WString absolutePath = searchDir.getAbsolutePath();

		// handle long filenames
#ifdef UNICODE
		if (gOnNT)
		{
			addUNCPrefetch(absolutePath);
			replaceYenWonSigns(absolutePath);

			HANDLE hSearch;
			WIN32_FIND_DATAW findData;

			hSearch = ::FindFirstFileW((LPCWSTR)absolutePath.c_str(), &findData);	
			if (hSearch == INVALID_HANDLE_VALUE)
				return fileList;

			WString fileName(findData.cFileName);

			if (containsIllegalCharacter(fileName))
				fileName = findData.cAlternateFileName;

			if (fileName != JDFStrL(".") && fileName != JDFStrL(".."))
				fileList.push_back(fileName);

			while (::FindNextFileW(hSearch,&findData))
			{
				fileName = findData.cFileName;
				if (containsIllegalCharacter(fileName))
					fileName = findData.cAlternateFileName;

				if (fileName != JDFStrL(".") && fileName != JDFStrL(".."))
					fileList.push_back(fileName);
			}
			::FindClose(hSearch);
		}
		else
		{
			HANDLE hSearch;
			WIN32_FIND_DATAA findData;
			char* tmp = absolutePath.getBytes();

			hSearch = ::FindFirstFileA(tmp, &findData);	
			if (hSearch == INVALID_HANDLE_VALUE){
				delete[] tmp;
				return fileList;
			}

			std::string fileFound(findData.cFileName);

			//@vigo -- WString(string) didn't work
			if (fileFound != "." && fileFound != "..")
				fileList.push_back(fileFound.c_str());

			while (::FindNextFileA(hSearch,&findData))
			{
				fileFound = findData.cFileName;
				if (fileFound != "." && fileFound != "..")
					fileList.push_back(fileFound.c_str());
			}
			::FindClose(hSearch);
			delete[] tmp;
		}
#else
		HANDLE hSearch;
		WIN32_FIND_DATAA findData;
		char* tmp = absolutePath.getBytes();

		hSearch = ::FindFirstFileA(tmp, &findData);	
		if (hSearch == INVALID_HANDLE_VALUE)
			return fileList;

		std::string fileFound(findData.cFileName);

		if (fileFound != "." && fileFound != "..")
			fileList.push_back(WString(fileFound.c_str()));

		while (::FindNextFileA(hSearch,&findData))
		{
			fileFound = findData.cFileName;
			if (fileFound != "." && fileFound != "..")
				fileList.push_back(WString(fileFound.c_str()));
		}
		::FindClose(hSearch);
		delete[] tmp;
#endif
		return fileList;
	}

	std::list<File> Win32FileSystem::listRoots()
	{
		unsigned int size = MAX_PATH;

		std::list<File> rootList;
		WString deviceStrings;

#ifdef UNICODE
		if (gOnNT)
		{
			JDFCh *temp = new JDFCh[size];
			unsigned int retSize;

			if ((retSize = ::GetLogicalDriveStringsW(size,temp)) > size)
			{
				size =  retSize;
				delete[] temp;
				temp = new JDFCh[size];
				retSize = ::GetLogicalDriveStringsW(size,temp);
			}
			deviceStrings = temp;
			delete[] temp;
		}
		else
		{
			char *temp = new char[size];
			unsigned int retSize;

			if ((retSize = ::GetLogicalDriveStringsA(size,temp)) > size)
			{
				size =  retSize;
				delete[] temp;
				temp = new char[size];
				retSize = ::GetLogicalDriveStringsA(size,temp);
			}
			deviceStrings = temp;
			delete[] temp;
		}
#else
		char *temp = new char[size];
		unsigned int retSize;

		if ((retSize = ::GetLogicalDriveStringsA(size,temp)) > size)
		{
			size =  retSize;
			delete[] temp;
			temp = new char[size];
			retSize = ::GetLogicalDriveStringsA(size,temp);
		}
		deviceStrings = temp;
		delete[] temp;
#endif
		std::string::size_type pos(0), next;

		next = deviceStrings.find(chNull,pos);
		while (next != WString::npos)
		{
			if (next == (pos+1))
				break;

			rootList.push_back(File(deviceStrings.substr(pos,next-pos)));
			pos = next+1;
			next = deviceStrings.find(chNull,pos);
		}
		return rootList;
	}

	WString	Win32FileSystem::normalize(const WString& s)
	{
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

	WString Win32FileSystem::normalize(const WString& s, int i, int j)
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

	int Win32FileSystem::normalizePrefix(const WString& s, int i, WString& stringbuffer)
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

	int Win32FileSystem::prefixLength(const WString& s)
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

	bool Win32FileSystem::isSlash(JDFCh c)
	{
		return c == chBackSlash || c == chForwardSlash;
	}

	bool Win32FileSystem::isLetter(JDFCh c)
	{
		return (c >= chLatin_a && c <= chLatin_z) || (c >= chLatin_A && c <= chLatin_Z);
	}

	WString Win32FileSystem::slashify(const WString& s)
	{
		if(s.length() > 0 && s.at(0) != slash)
			return slash + s;
		else
			return s;
	}

	WString Win32FileSystem::getDrive(const WString& s)
	{
		int i = prefixLength(s);
		return i != 3 ? "" : s.substr(0, 2);
	}

	bool Win32FileSystem::rename(File& src, File& target)
	{
		File targetParentFile = target.getParentFile();

#ifdef UNICODE
		if (gOnNT)
		{
			if (targetParentFile.getPath().length() == 0)
			{
				WString srcPath = src.getAbsolutePath();
				WString destPath = File(src.getParentFile(),target.getName()).getAbsolutePath();

				addUNCPrefetch(srcPath);
				addUNCPrefetch(destPath);
				replaceYenWonSigns(srcPath);
				replaceYenWonSigns(destPath);
				return (::MoveFileW(srcPath.c_str(), destPath.c_str()) == TRUE);
			}

			if (src.getParentFile() == target.getParentFile())
			{
				WString srcPath = src.getAbsolutePath();
				WString destPath = target.getAbsolutePath();
				addUNCPrefetch(srcPath);
				addUNCPrefetch(destPath);
				replaceYenWonSigns(srcPath);
				replaceYenWonSigns(destPath);
				return (::MoveFileW(srcPath.c_str(), destPath.c_str()) == TRUE);
			}
			else
				return false;
		}
		else
		{
			if (targetParentFile.getPath().length() == 0)
			{
				char* srcPath = src.getAbsolutePath().getBytes();
				char* destPath = File(src.getParentFile(),target.getName()).getAbsolutePath().getBytes();
				BOOL ret = ::MoveFileA(srcPath,destPath);
				delete[] srcPath;
				delete[] destPath;
				return (ret == TRUE);
			}

			if (src.getParentFile() == target.getParentFile())
			{
				char* srcPath = src.getAbsolutePath().getBytes();
				char* destPath = target.getAbsolutePath().getBytes();
				BOOL ret = ::MoveFileA(srcPath,destPath);
				delete[] srcPath;
				delete[] destPath;
				return (ret == TRUE);
			}
			else
				return false;
		}
#else
		if (targetParentFile.getPath().length() == 0)
		{
			char* srcPath = src.getAbsolutePath().getBytes();
			char* destPath = File(src.getParentFile(),target.getName()).getAbsolutePath().getBytes();
			BOOL ret = ::MoveFileA(srcPath,destPath);
			delete[] srcPath;
			delete[] destPath;
			return (ret == TRUE);
		}

		if (src.getParentFile() == target.getParentFile())
		{
			char* srcPath = src.getAbsolutePath().getBytes();
			char* destPath = target.getAbsolutePath().getBytes();
			BOOL ret = ::MoveFileA(srcPath,destPath);
			delete[] srcPath;
			delete[] destPath;
			return (ret == TRUE);
		}
		else
			return false;
#endif
	}

	bool Win32FileSystem::moveTo(const File& src, const File& dst)
	{
#ifdef UNICODE
		if (gOnNT)
		{
			WString srcPath = src.getAbsolutePath();
			WString dstPath = dst.getAbsolutePath();
			addUNCPrefetch(srcPath);
			addUNCPrefetch(dstPath);
			replaceYenWonSigns(srcPath);
			replaceYenWonSigns(dstPath);
			return (::MoveFileExW(srcPath.c_str(),dstPath.c_str(),MOVEFILE_COPY_ALLOWED | MOVEFILE_WRITE_THROUGH) == TRUE);
		}
		else
		{
			char* srcPath = src.getAbsolutePath().getBytes();
			char* dstPath = dst.getAbsolutePath().getBytes();
			BOOL ret = ::MoveFileExA(srcPath,dstPath,MOVEFILE_COPY_ALLOWED | MOVEFILE_WRITE_THROUGH);
			delete[] srcPath;
			delete[] dstPath;
			return (ret == TRUE);
		}
#else
		char* srcPath = src.getAbsolutePath().getBytes();
		char* dstPath = dst.getAbsolutePath().getBytes();
		BOOL ret = ::MoveFileExA(srcPath,dstPath,MOVEFILE_COPY_ALLOWED | MOVEFILE_WRITE_THROUGH);
		delete[] srcPath;
		delete[] dstPath;
		return (ret == TRUE);
#endif
	}

	WString Win32FileSystem::getUserPath()
	{
#ifdef UNICODE
		if (gOnNT)
		{
			JDFCh cwd[ MAX_PATH ];
			GetCurrentDirectoryW(MAX_PATH, cwd);
			return WString(cwd);
		}
		else
		{
			char cwd[ MAX_PATH ];
			GetCurrentDirectoryA(MAX_PATH, cwd);
			return WString(cwd);
		}
#else
		char cwd[ MAX_PATH ];
		GetCurrentDirectoryA(MAX_PATH, cwd);
		return WString(cwd);
#endif
	}

	WString Win32FileSystem::getDriveDirectory(JDFCh c)
	{
		JDFCh full[ _MAX_PATH ];

		if ( _wgetdcwd (towupper( c ) - 'A' + 1, full, sizeof full ) != 0 )
		{
			WString s(full);

			// strip drive
			if (s.at(s.length()-1) != chBackSlash)
				// not root 
				return s.substr(3,s.length());
			else
				return WString(JDFStrL(""));
		}
		return WString(JDFStrL(""));
	}

	WString Win32FileSystem::resolve(const File& file)
	{
		WString s = file.getPath();
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

	WString Win32FileSystem::resolve(const WString& parent, const WString& child)
	{
		int i  = parent.length();

		if(i == 0)
			return child;

		int j = child.length();
		if(j == 0)
			return parent;

		WString s2 = child;

		if(j > 1 && s2.at(0) == slash)
			/* Drop prefix when child is a UNC pathname */
			if(s2.at(1) == slash)
				s2 = s2.substr(2);
			else
				/* Drop prefix when child is drive-relative */
				s2 = s2.substr(1);

		WString s3 = parent;
		if(s3.at(i - 1) == slash)
			s3 = s3.substr(0, i - 1);
		return s3 + slashify(s2);
	}

	WString Win32FileSystem::fromURIPath(const WString& host,const WString& path)
	{
		WString s = path;

		if ((s.length() > 2) && (s.at(2) == chColon))
		{
			// "/c:/foo" --> "c:/foo"
			s = s.substring(1);
			// "c:/foo/" --> "c:/foo", but "c:/" --> "c:/"
			if ((s.length() > 3) && s.endsWith(JDFStrL("/")))
				s = s.substring(0, s.length() - 1);

			if (!host.empty() && host != JDFStrL("localhost"))
				throw IllegalArgumentException("URI path cannot be resolved");

			return s;
		}
		else if ((s.length() > 1) && s.endsWith(JDFStrL("/"))) 
		{
			// "/foo/" --> "/foo"
			s = s.substring(0, s.length() - 1);
		}
		if (!host.empty() && host != JDFStrL("localhost"))
			s = JDFStrL("//") + host + s;

		return s;
	}

	bool Win32FileSystem::setLastModifiedTime(const File& file, JDFUInt64 time)
	{
		HANDLE hFile;

		WString absolutePath = file.getAbsolutePath();

#ifdef UNICODE
		if (gOnNT)
		{
			addUNCPrefetch(absolutePath);
			replaceYenWonSigns(absolutePath);
			hFile = ::CreateFileW((LPCWSTR)absolutePath.c_str(), 
				GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 
				NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
		}
		else
		{
			char* tmp = absolutePath.getBytes();
			hFile = ::CreateFileA(tmp, 
				GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 
				NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
			delete[] tmp;
		}
#else
		char* tmp = absolutePath.getBytes();
		hFile = ::CreateFileA(tmp, 
			GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 
			NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
		delete[] tmp;
#endif

		// invalid path

		if (hFile == INVALID_HANDLE_VALUE) 
			return false;

		FILETIME modificationTime = BiasTimeNative(time);
		BOOL res = ::SetFileTime(hFile, NULL, NULL, &modificationTime);
		::CloseHandle(hFile);
		return (res == TRUE);
	}

	bool Win32FileSystem::setReadOnly(const File& file)
	{
		WString absolutePath = file.getAbsolutePath();

		// keep old attributes

		// solve MAX_PATH limit
#ifdef UNICODE
		if (gOnNT)
		{
			addUNCPrefetch(absolutePath);
			replaceYenWonSigns(absolutePath);
			DWORD fileAttributes = ::GetFileAttributesW((LPCWSTR)absolutePath.c_str());
			return (::SetFileAttributesW((LPCWSTR)absolutePath.c_str(), fileAttributes | FILE_ATTRIBUTE_READONLY) != 0);
		}
		else
		{
			char* tmp = absolutePath.getBytes();
			DWORD fileAttributes = ::GetFileAttributesA(tmp);
			BOOL ret = ::SetFileAttributesA(tmp, fileAttributes | FILE_ATTRIBUTE_READONLY);
			delete[] tmp;
			return (ret == TRUE);
		}
#else
		char* tmp = absolutePath.getBytes();
		DWORD fileAttributes = ::GetFileAttributesA(tmp);
		BOOL ret = ::SetFileAttributesA(tmp, fileAttributes | FILE_ATTRIBUTE_READONLY);
		delete[] tmp;
		return (ret == TRUE);
#endif
	}

	WString Win32FileSystem::canonicalize(const WString& s) // throw IOException
	{
#ifdef UNICODE
		if (gOnNT)
		{
			JDFCh fullPath[MAX_PATH];
			JDFCh* filePart;
			if (GetFullPathNameW(s.c_str(),MAX_PATH,fullPath, &filePart) == 0)
				throw IOException("invalid path name");
			return WString(fullPath);
		}
		else
		{
			char fullPath[MAX_PATH];
			char* filePart;
			char* tmp = s.getBytes();
			if (GetFullPathNameA(tmp,MAX_PATH,fullPath, &filePart) == 0)
			{
				delete[] tmp;
				throw IOException("invalid path name");
			}
			delete[] tmp;
			return WString(fullPath);
		}
#else
		char fullPath[MAX_PATH];
		char* filePart;
		char* tmp = s.getBytes();
		if (GetFullPathNameA(tmp,MAX_PATH,fullPath, &filePart) == 0)
		{
			delete[] tmp;
			throw IOException("invalid path name");
		}
		delete[] tmp;
		return WString(fullPath);
#endif
	}

	bool getFileInformation(WString pathName, LPBY_HANDLE_FILE_INFORMATION info)
	{
		// get a handle to the file

		HANDLE hFile;

#ifdef UNICODE
		if (gOnNT)
		{
			addUNCPrefetch(pathName);
			replaceYenWonSigns(pathName);

			hFile = ::CreateFileW((LPCWSTR)pathName.c_str(), 
				GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 
				NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
		}
		else
		{
			char* tmp = pathName.getBytes();
			hFile = ::CreateFileA(tmp, 
				GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 
				NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
			delete[] tmp;
		}
#else
		char* tmp = pathName.getBytes();
		hFile = ::CreateFileA(tmp, 
			GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 
			NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
		delete[] tmp;
#endif

		// invalid path

		if (hFile == INVALID_HANDLE_VALUE) 
			return false;

		if (!::GetFileInformationByHandle(hFile, info)) 
		{
			::CloseHandle(hFile);
			return false;
		}
		::CloseHandle(hFile);
		return true;
	}

	//@vigo
	JDFUInt64 BiasTime(FILETIME intime)
	{
		LARGE_INTEGER x = { intime.dwLowDateTime, intime.dwHighDateTime };

		return (x.QuadPart - 116444736000000000) / 10000;

		/*
		LARGE_INTEGER m;
		m.LowPart  = intime.dwLowDateTime;
		m.HighPart = intime.dwHighDateTime;

		LARGE_INTEGER s;

		s.QuadPart = 116444736000000000;


		LARGE_INTEGER r = LargeIntegerSubtract (m,s);
		LARGE_INTEGER rest;
		LARGE_INTEGER divident;
		divident.QuadPart = 10000;
		r = LargeIntegerDivide(r,divident,&rest);

		return r.QuadPart;
		*/
	}

	FILETIME BiasTimeNative(JDFUInt64 intime)
	{
		LARGE_INTEGER x = { 0, 0 };
		x.QuadPart = intime * 10000 + 116444736000000000;

		FILETIME t;
		t.dwHighDateTime = x.HighPart;
		t.dwLowDateTime = x.LowPart;

		return t;

		/*
		LARGE_INTEGER m;
		m.QuadPart = intime;
		m =  ExtendedIntegerMultiply(m,10000);

		LARGE_INTEGER s;
		s.QuadPart = 116444736000000000;
		LARGE_INTEGER r = LargeIntegerAdd (m,s);

		FILETIME nativetime;
		nativetime.dwLowDateTime = r.LowPart;
		nativetime.dwHighDateTime = r.HighPart;
		return nativetime;
		*/
	}

	JDFUInt64 Win32FileSystem::getLastAccessedTime(const File& file)
	{
		BY_HANDLE_FILE_INFORMATION info;

		if (getFileInformation(file.getAbsolutePath(), &info) == TRUE)
		{
			return BiasTime(info.ftLastAccessTime);
		}
		return 0;
	}

	bool Win32FileSystem::copyTo(const File& src, const File& dst)
	{
		// check if destination is readonly

#ifdef UNICODE
		if (gOnNT)
		{
			WString srcFile = src.getAbsolutePath();
			WString dstFile = dst.getAbsolutePath();
			addUNCPrefetch(srcFile);
			replaceYenWonSigns(srcFile);
			addUNCPrefetch(dstFile);
			replaceYenWonSigns(dstFile);
			return (::CopyFileW(srcFile.c_str(),dstFile.c_str(),false) == TRUE);

		}
		else
		{
			char* srcFile = src.getAbsolutePath().getBytes();
			char* dstFile = dst.getAbsolutePath().getBytes();
			BOOL ret = ::CopyFileA(srcFile,dstFile,false);
			delete[] srcFile;
			delete[] dstFile;
			return (ret == TRUE);
		}
#else
		char* srcFile = src.getAbsolutePath().getBytes();
		char* dstFile = dst.getAbsolutePath().getBytes();
		BOOL ret = ::CopyFileA(srcFile,dstFile,false);
		delete[] srcFile;
		delete[] dstFile;
		return (ret == TRUE);
#endif
	}

	bool Win32FileSystem::makeWritable(const File& file)
	{
		WString absolutePath = file.getAbsolutePath();

		// keep old attributes

		// solve MAX_PATH limit
#ifdef UNICODE
		if (gOnNT)
		{
			addUNCPrefetch(absolutePath);
			replaceYenWonSigns(absolutePath);
			DWORD fileAttributes = ::GetFileAttributesW((LPCWSTR) absolutePath.c_str());
			fileAttributes &= ~FILE_ATTRIBUTE_READONLY; 
			return (::SetFileAttributesW((LPCWSTR)absolutePath.c_str(), fileAttributes) == TRUE);
		}
		else
		{
			char* tmp = absolutePath.getBytes();
			DWORD fileAttributes = ::GetFileAttributesA(tmp);
			fileAttributes &= ~FILE_ATTRIBUTE_READONLY; 
			BOOL ret= ::SetFileAttributesA(tmp, fileAttributes );
			delete[] tmp;
			return (ret == TRUE);
		}
#else
		char* tmp = absolutePath.getBytes();
		DWORD fileAttributes = ::GetFileAttributesA(tmp);
		fileAttributes &= ~FILE_ATTRIBUTE_READONLY; 
		BOOL ret= ::SetFileAttributesA(tmp, fileAttributes );
		delete[] tmp;
		return (ret == TRUE);
#endif
	}

	File Win32FileSystem::tempFilePath() 
	{
		unsigned int retSize;

#ifdef UNICODE
		if (gOnNT)
		{
			JDFCh *tempPath;

			retSize = ::GetTempPathW(0,NULL);
			tempPath = new JDFCh[retSize];
			ArrayJanitor<JDFCh> tempPathJanitor(tempPath);
			::GetTempPathW(retSize,tempPath);
			return File(tempPath);		
		}
		else
		{
			char *tempPath;

			retSize = ::GetTempPathA(0,NULL);
			tempPath = new char[retSize];
			ArrayJanitor<char> tempPathJanitor(tempPath);
			::GetTempPathA(retSize,tempPath);
			return File(WString(tempPath));		
		}
#else
		char *tempPath;

		retSize = ::GetTempPathA(0,NULL);
		tempPath = new char[retSize];
		ArrayJanitor<char> tempPathJanitor(tempPath);
		::GetTempPathA(retSize,tempPath);
		return File(WString(tempPath));		
#endif
	}

	void addUNCPrefetch(WString& s)
	{
		if (s.substr(0,2) == JDFStrL("\\\\"))
			s.replace(0,2,WString("\\\\?\\UNC\\"));
		else
			s.insert(0,JDFStrL("\\\\?\\"));
	}

	// check if a path is a root 
	// 
	// returns: 
	//  TRUE for "\" "X:\" "\\foo\asdf" "\\foo\" 
	//  FALSE for others 

	bool Win32FileSystem::isRoot(const File& file)
	{
		return (getPrefixLength(file) && getPrefixLength(file) == file.getPath().length() && !isSlash(file.getPath()[0]) );
	}



} // namespace JDF

/* end of file */
