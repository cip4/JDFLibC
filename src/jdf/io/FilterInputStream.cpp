/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2009 The International Cooperation for the Integration of 
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

#include "FilterInputStream.h"

#include <jdf/lang/Exception.h>

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

	FilterInputStream::FilterInputStream(InputStream& in) :
mIn	(&in)
{
	bKillInStream=false;
}

FilterInputStream::FilterInputStream() :
mIn(NULL)
{
	bKillInStream=false;
}

FilterInputStream::~FilterInputStream() 
{
	if(bKillInStream)
	{
		delete(mIn);
		mIn=0;
	}

}

void FilterInputStream::setOwnsMember(bool ownsMember)
{
	bKillInStream=ownsMember;
}
int  FilterInputStream::available()
{
	if (mIn)
		return mIn->available();
	else
		throw NullPointerException("input stream is NULL");

	return 0;
}

void FilterInputStream::close()
{
	if (mIn)
		mIn->close();
	else
		throw NullPointerException("input stream is NULL");
}

void FilterInputStream::mark(int readlimit)
{
	if (mIn)
		mIn->mark(readlimit);
	else
		throw NullPointerException("input stream is NULL");
}

bool FilterInputStream::markSupported()
{
	if (mIn)
		return mIn->markSupported();
	else
		throw NullPointerException("input stream is NULL");

	return false;
}

int  FilterInputStream::read()
{
	if (mIn)
		return mIn->read();

	throw NullPointerException("input stream is NULL");
	return 0;
}

int  FilterInputStream::read(char* b, int blen)
{
	return read(b, blen,0,blen);
}

int  FilterInputStream::read(char* b, int blen, int off, int len)
{
	if (mIn)
		return mIn->read(b, blen, off, len);

	throw NullPointerException("input stream is NULL");
	return 0;
}

void FilterInputStream::reset()
{
	if (mIn)
		mIn->reset();
	else
		InputStream::reset();
}

long FilterInputStream::skip(long n)
{
	if (mIn)
		return mIn->skip(n);

	throw NullPointerException("input stream is NULL");
}

} // namespace JDF
