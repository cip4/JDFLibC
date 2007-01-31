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

#include "FileOutputStream.h"

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

FileOutputStream::FileOutputStream()
{
	m_handle = 0;
}

FileOutputStream::FileOutputStream(File file)
{
	m_handle = 0;
	open(file);
}

FileOutputStream::FileOutputStream(const WString& fileName)
{
	m_handle = 0;
	open(fileName);
}

FileOutputStream::FileOutputStream(const char* const fileName)
{
	m_handle = 0;
	open(fileName);
}


FileOutputStream::FileOutputStream(const JDFCh* const fileName)
{
	m_handle = 0;
	open(fileName);
}

FileOutputStream::FileOutputStream(JDFFileHandle handle)
{
	m_handle = handle;
}



FileOutputStream::~FileOutputStream()
{
	close();
}

void FileOutputStream::open(File file)
{
	file.getParentFile().mkdirs();
	open(file.getPath());
}

void FileOutputStream::open(const char* const fileName)
{
	if (m_handle)
		throw IOException("File is already opened");

	File(fileName).getParentFile().mkdirs();
	m_handle = PlatformUtils::createFile(fileName);
	if (!m_handle)
		throw FileNotFoundException("failed to open file");
}

void FileOutputStream::open(const JDFCh* const fileName)
{
	if (m_handle)
		throw IOException("File is already opened");

	File(fileName).getParentFile().mkdirs();
	m_handle = PlatformUtils::createFile(WString(fileName));
	if (!m_handle)
		throw FileNotFoundException("failed to open file");
}

void FileOutputStream::open(const WString& fileName)
{
	if (m_handle)
		throw IOException("File is already opened");
        
	JDF::File(fileName).getParentFile().mkdirs();

//	File(WString(fileName)).getParentFile().mkdirs();
	m_handle = PlatformUtils::createFile(fileName);
	if (!m_handle)
		throw FileNotFoundException("failed to open file");
}

void FileOutputStream::open(JDFFileHandle handle)
{
	m_handle = handle;
}


void FileOutputStream::close()
{
	if (m_handle)
	{
		PlatformUtils::closeFile(m_handle);
		m_handle = 0;
	}
}

void FileOutputStream::write(int c)
{
	char ch = (char) c;

	write(&ch, 1, 0, 1);
}

void FileOutputStream::write(const char* b, int blen)
{
	write(b, blen, 0, blen);
}

void FileOutputStream::write(const char* b, int blen, int off, int len)
{
	PlatformUtils::writeFileBuffer(m_handle,len,(unsigned char* const) b+off);
}

void FileOutputStream::flush()
{
	PlatformUtils::flushFile(m_handle);
}

bool FileOutputStream::seekSupported()
{
	return false; //  for now
}

JDFUInt64 FileOutputStream::length()
{
	return PlatformUtils::curFilePos(m_handle); // for now
}

JDFUInt64 FileOutputStream::seek(JDFUInt64 pos,int moveMethod)
{
	return ((JDFUInt64) -1);
}



} // namespace JDF

/* end of file */
