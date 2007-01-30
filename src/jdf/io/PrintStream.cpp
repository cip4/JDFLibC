/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2002 The International Cooperation for the Integration of 
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

#include <jdf/lang/Exception.h>
#include <jdf/util/PlatformUtils.h>

#include <jdf/io/PrintStream.h>


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
	
	PrintStream::PrintStream(OutputStream& out) :FilterOutputStream(out)
	{
		autoFlush = false;
		PlatformUtils::value_pair v  = PlatformUtils::getProperty(JDFStrL("line.separator"));
		separatorChars=0;
		if (v.first)
			separatorChars = v.second.getBytes();
		else
			throw IOException("line.separator property is undefined");
	}
	
	////////////////////////////////////////////////////////////////////////////////////
	
	PrintStream::PrintStream(OutputStream& out, bool autoFlush) :
	FilterOutputStream(out)
	{
		this->autoFlush =  autoFlush;
		PlatformUtils::value_pair v  = PlatformUtils::getProperty(JDFStrL("line.separator"));
		separatorChars=0;
		if (v.first)
			separatorChars = v.second.getBytes();
		else
			throw IOException("line.separator property is undefined");
	}
	
	////////////////////////////////////////////////////////////////////////////////////
	
	
	PrintStream::~PrintStream(){
		delete[]separatorChars;
	}
	
	
	////////////////////////////////////////////////////////////////////////////////////
	
	bool PrintStream::checkError()
	{
		return false;
	}
	
	void PrintStream::close()
	{
		FilterOutputStream::close();
	}
	
	void PrintStream::print(int i)
	{
		print(WString::valueOf(i));
	}
	
	void PrintStream::print(const WString& s)
	{
		char* bytes = s.getBytes();
		write(bytes,strlen(bytes));
		delete[] bytes;
	}
	
	void PrintStream::print(double d)
	{
		print(WString::valueOf(d));
	}
	
	void PrintStream::print(float f)
	{
		print(WString::valueOf(f));
	}
	
	void PrintStream::print(long l)
	{
		print(WString::valueOf(l));
	}
	
	
	void PrintStream::println()
	{
		write(separatorChars, strlen(separatorChars));
	}
	
	void PrintStream::println(int i)
	{
		print(i);
		write(separatorChars, strlen(separatorChars));
	}
	
	void PrintStream::write(const char* buf, int blen)
	{
		FilterOutputStream::write(buf,blen);
	}
	
	void PrintStream::write(const char* buf, int blen, int off, int len)
	{
		FilterOutputStream::write(buf,blen,off,len);
		if (autoFlush) 
		{
			const char* start = buf + off;
			for (int i = 0; i < len; i++)
				if (start[i] == '\n')
					mOut->flush();
		}
	}
	
	void PrintStream::write(int b)
	{
		FilterOutputStream::write(b);
		if ((b == '\n') && autoFlush)
			mOut->flush();
	}
	
	void PrintStream::flush()
	{
		FilterOutputStream::flush();
	}
	
	
} // namespace JDF
