/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2006 The International Cooperation for the Integration of 
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

#include <jdf/util/PlatformUtils.h>
#include <jdf/lang/Exception.h>
#include <jdf/net/Platforms/Win32/Win32SocketFactoryService.h>
#include <jdf/net/Platforms/Win32/Win32InetAddressImpl.h>
#include <jdf/io/Platforms/Win32/Win32FileSystem.h>
#include <jdf/lang/Exception.h>

#include <windows.h>

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLUniDefs.hpp>
#include <xercesc/util/XMLString.hpp>

XERCES_CPP_NAMESPACE_USE

namespace JDF
{

	/******************************************************************************
	*	Forward declarations
	******************************************************************************/ 


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

	static bool gOnNT = false;

	SocketFactoryService* PlatformUtils::makeSocketFactoryService()
	{
		return new Win32SocketFactoryService();
	}

	InetAddressImpl* PlatformUtils::makeInetAddressImpl()
	{
		return new Win32InetAddressImpl();
	}

	FileSystem* PlatformUtils::makeFileSystem()
	{
		return new Win32FileSystem();
	}

	void PlatformUtils::platformInit()
	{
		OSVERSIONINFO   OSVer;
		OSVer.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
		::GetVersionEx(&OSVer);
		gOnNT = (OSVer.dwPlatformId == VER_PLATFORM_WIN32_NT);
	}

	void PlatformUtils::platformTerm()
	{
	}

	void PlatformUtils::SystemPropertiesInit()
	{
		setProperty(JDFStrL("line.separator"),JDFStrL("\r\n"));

		{
			unsigned int endianTest = 0xff000000; 
			if (((char*)(&endianTest))[0] != 0) 
			{
				setProperty(JDFStrL("cpu.endianness"),JDFStrL("big"));
			} else 
			{
				setProperty(JDFStrL("cpu.endianness"),JDFStrL("little"));
			}
		}

	}

	unsigned int PlatformUtils::curFilePos(JDFFileHandle theFile)
	{
		try
		{
			return XMLPlatformUtils::curFilePos(theFile);
		}
		catch (XMLException&)
		{
			throw IOException("Failed to get current file position");
		}
	}

	void PlatformUtils::seekFile(JDFFileHandle theFile, size_t pos, int movemethod)
	{
		int whence = 0;

		if (movemethod == 1)
			whence = FILE_BEGIN; 
		else if (movemethod == 2)
			whence = FILE_END; 
		else if (movemethod == 3)
			whence = FILE_CURRENT;

		const size_t res  = SetFilePointer (theFile,pos, 0, whence);

		if (res == 0xFFFFFFFF)
			throw IOException("Failed to set file position");
	}


	void PlatformUtils::closeFile(JDFFileHandle theFile)
	{
		try
		{
			XMLPlatformUtils::closeFile(theFile);
		} catch (XMLException&)
		{
			throw IOException("Failed to open file");
		}
	}

	size_t PlatformUtils::fileSize(JDFFileHandle theFile)
	{
		return XMLPlatformUtils::fileSize(theFile);
	}

	JDFFileHandle PlatformUtils::openFile(const char* const fileName)
	{
		int oldMode = SetErrorMode(SEM_FAILCRITICALERRORS);
		JDFFileHandle handle =  XMLPlatformUtils::openFile(fileName);
		SetErrorMode(oldMode);
		return handle;
	}

	JDFFileHandle PlatformUtils::openFile(const WString& fileName)
	{
		int oldMode = SetErrorMode(SEM_FAILCRITICALERRORS);
		JDFFileHandle handle = XMLPlatformUtils::openFile(fileName.c_str());
		SetErrorMode(oldMode);
		return handle;
	}

	JDFFileHandle PlatformUtils::createFile(const char* const fileName)
	{
		int oldMode = SetErrorMode(SEM_FAILCRITICALERRORS);
		JDFFileHandle retVal = ::CreateFileA
			(
			fileName
			, GENERIC_WRITE
			, FILE_SHARE_READ | FILE_SHARE_WRITE
			, 0
			, CREATE_ALWAYS
			, FILE_ATTRIBUTE_NORMAL
			, 0
			);
		SetErrorMode(oldMode);
		if (retVal == INVALID_HANDLE_VALUE)
			return 0;

		return retVal;
	}

	JDFFileHandle PlatformUtils::createFile(const WString& fileName)
	{
		WString s(fileName);

		int oldMode = SetErrorMode(SEM_FAILCRITICALERRORS);

		JDFFileHandle retVal = 0;
		if (gOnNT)
		{

			if (s.substr(0,2) == L"\\\\"){
				s.replace(0,2,WString("\\\\?\\UNC\\"));
			}else{
				//			s.insert(0,JDFStrL("\\\\?\\"));
			}

			retVal = ::CreateFileW
				(
				s.c_str()
				, GENERIC_WRITE
				, FILE_SHARE_READ | FILE_SHARE_WRITE
				, 0
				, CREATE_ALWAYS
				, FILE_ATTRIBUTE_NORMAL
				, 0
				);
		}
		else
		{
			//
			//  We are Win 95 / 98.  Take the Unicode file name back to (char *)
			//    so that we can open it.
			//
			char* tmpName = fileName.getBytes();
			retVal = ::CreateFileA
				(
				tmpName
				, GENERIC_WRITE
				, FILE_SHARE_READ | FILE_SHARE_WRITE
				, 0
				, CREATE_ALWAYS
				, FILE_ATTRIBUTE_NORMAL
				, 0
				);
			delete [] tmpName;
		}
		SetErrorMode(oldMode);

		if (retVal == INVALID_HANDLE_VALUE)
			return 0;

		return retVal;
	}

	JDFFileHandle PlatformUtils::openStdOutHandle()
	{
		//
		//  Get the standard input handle. Duplicate it and return that copy
		//  since the outside world cannot tell the difference and will shut
		//  down this handle when its done with it. If we gave out the orignal,
		//  shutting it would prevent any further output.
		//
		HANDLE stdOutOrg = ::GetStdHandle(STD_OUTPUT_HANDLE);
		if (stdOutOrg == INVALID_HANDLE_VALUE)
			throw PlatformUtilsException("Failed to open stdouthandle");

		HANDLE retHandle;
		if (!::DuplicateHandle
			(
			::GetCurrentProcess()
			, stdOutOrg
			, ::GetCurrentProcess()
			, &retHandle
			, 0
			, FALSE
			, DUPLICATE_SAME_ACCESS))
		{
			throw PlatformUtilsException("Failed to duplicate stdouthandle");
		}
		return retHandle;
	}

	JDFFileHandle PlatformUtils::openStdInHandle()
	{
		try
		{
			return XMLPlatformUtils::openStdInHandle();
		} catch (XMLPlatformUtilsException&)
		{
			throw PlatformUtilsException("Failed to open stdinhandle");
		}
	}

	ssize_t PlatformUtils::readFileBuffer(
		JDFFileHandle   theFile
		, const size_t   toRead
		,       JDFByte* const  toFill
		)
	{
		try
		{
			size_t bytesRead = XMLPlatformUtils::readFileBuffer(theFile,toRead,toFill);
			if (bytesRead == 0)
				return -1;
			return bytesRead;
		} catch (XMLException&)
		{
			throw IOException("Failed to read from file");
		}
	}

	size_t PlatformUtils::writeFileBuffer(
		JDFFileHandle   theFile
		, const size_t    toWrite
		,       JDFByte* const  buffer
		)
	{
		unsigned long bytesWritten = 0;
		if (!::WriteFile(theFile, buffer, toWrite, &bytesWritten, 0))
		{
			//
			//  Check specially for a broken pipe error. If we get this, it just
			//  means no more data from the pipe, so return zero.
			//
			if (::GetLastError() != ERROR_BROKEN_PIPE)
				throw IOException("Failed to write to file");
		}
		return (size_t)bytesWritten;
	}

	void PlatformUtils::resetFile(JDFFileHandle theFile)
	{
		try
		{
			XMLPlatformUtils::resetFile(theFile);
		} catch (XMLException&)
		{
			throw IOException("Failed to reset file");
		}

	}

	void PlatformUtils::flushFile(JDFFileHandle theFile)
	{
		FlushFileBuffers(theFile);
	}

	void PlatformUtils::lowerCase(JDFCh* const toLowerCase)
	{
		_wcslwr(toLowerCase);
	}

	void PlatformUtils::sleep(int millis)
	{
		::Sleep(millis);
	}

	WString PlatformUtils::weavePaths(const WString&  basePath
		, const WString&  relativePath)
	{
		XMLCh* tmp = XMLPlatformUtils::weavePaths(basePath.c_str(),relativePath.c_str());
		WString res (tmp);
		XMLString::release(&tmp);
		return res;
	}

	WString PlatformUtils::createUID()
	{
		UUID myUniqueID;
		wchar_t* myUniqueIDString;
		::UuidCreate(&myUniqueID);
		::UuidToStringW(&myUniqueID, (RPC_WSTR*)&myUniqueIDString);
		WString s = myUniqueIDString;
		::RpcStringFreeW((RPC_WSTR*)&myUniqueIDString);
		return s;
	}



} // namespace JDF