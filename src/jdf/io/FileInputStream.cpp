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

#include "FileInputStream.h"

#include "File.h"
#include <jdf/lang/Exception.h>

#include <jdf/util/PlatformUtils.h>



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

FileInputStream::FileInputStream()
{
	m_handle = 0;
	mMarkPosition = 0;
}

FileInputStream::FileInputStream(File& file)
{
	m_handle = 0;
	mMarkPosition = 0;
	open(file);
}

FileInputStream::FileInputStream(const WString& fileName)
{
	m_handle = 0;
	mMarkPosition = 0;
	open(fileName);
}

FileInputStream::FileInputStream(const char* const fileName)
{
	m_handle = 0;
	mMarkPosition = 0;
	open(fileName);
}

FileInputStream::FileInputStream(const JDFCh* const fileName)
{
	m_handle = 0;
	mMarkPosition = 0;
	open(fileName);
}

FileInputStream::FileInputStream(JDFFileHandle handle)
{
	m_handle = handle;
	mMarkPosition = 0;
}


void FileInputStream::open(File& file)
{
	open(file.getPath());
}

void FileInputStream::open(const WString& fileName)
{
	if (m_handle)
		throw IOException("File is already opened");

	m_handle = PlatformUtils::openFile(fileName);
	if (!m_handle)
		throw FileNotFoundException("failed to open file");
}

void FileInputStream::open(const char* const fileName)
{
	if (m_handle)
		throw IOException("File is already opened");

	m_handle = PlatformUtils::openFile(fileName);
	if (!m_handle)
		throw FileNotFoundException("failed to open file");
}

void FileInputStream::open(const JDFCh* const fileName)
{
	if (m_handle)
		throw IOException("File is already opened");

	m_handle = PlatformUtils::openFile(WString(fileName));
	if (!m_handle)
		throw FileNotFoundException("failed to open file");
}

void FileInputStream::open(JDFFileHandle handle)
{
	m_handle = handle;
	mMarkPosition = 0;
}

FileInputStream::~FileInputStream()
{
	close();
}

void FileInputStream::close()
{
	if (m_handle)
	{
		PlatformUtils::closeFile(m_handle);
		m_handle = 0;
	}
}

long FileInputStream::skip(long n)
{
	return InputStream::skip(n);
}

int FileInputStream::read()
{
	char ch;

	if (read(&ch,1,0,1) == -1)
		return -1;

	return (unsigned char) ch;
}

int FileInputStream::read(char* b, int blen)
{
	return read(b,blen,0,blen);
}

int FileInputStream::read(char* b, int blen, int off, int len)
{
	return PlatformUtils::readFileBuffer(m_handle,len,(unsigned char* const) b+off);
}

void FileInputStream::reset()
{
	PlatformUtils::seekFile(m_handle,mMarkPosition,1);
}

void FileInputStream::mark(int readlimit)
{
	mMarkPosition = PlatformUtils::curFilePos(m_handle);
}

bool FileInputStream::markSupported()
{
	return true;
}

int FileInputStream::available()
{
	return PlatformUtils::fileSize(m_handle) - PlatformUtils::curFilePos(m_handle);
}

bool FileInputStream::seekSupported()
{
	return true;
}

JDFUInt64 FileInputStream::length()
{
	return PlatformUtils::fileSize(m_handle);
}

JDFUInt64 FileInputStream::seek(JDFUInt64 pos, int moveMethod)
{
	PlatformUtils::seekFile(m_handle,pos,moveMethod);
	return PlatformUtils::curFilePos(m_handle);
}


} // namespace JDF
