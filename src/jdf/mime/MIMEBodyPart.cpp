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

#include <jdf/lang/Exception.h>
#include <jdf/mime/MIMEBodyPart.h>
#include <jdf/net/URLEncoder.h>
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

const int MIMEBodyPart::ATTACHMENT = 0;
const int MIMEBodyPart::INLINE = 1;
const int MIMEBodyPart::BASE64 =0;
const int MIMEBodyPart::QP = 1;
const int MIMEBodyPart::BINARY = 2;
const int MIMEBodyPart::E7BIT = 3;
const int MIMEBodyPart::E8BIT =4;
const int MIMEBodyPart::UNINITIALIZED = -1;
const int MIMEBodyPart::DATABUFSZ = 8192;
const int MIMEBodyPart::HDRBUFSZ = 1024;
char* MIMEBodyPart::CRLF = NULL;
char* MIMEBodyPart::LF = NULL;

void MIMEBodyPart::initMIMEBodyPart()
{
	CRLF = WString("\r\n").getBytes();
	LF   = WString("\n").getBytes();
}

void MIMEBodyPart::terminateMIMEBodyPart()
{
	delete[] CRLF;
	delete[] LF;
	CRLF=LF=0;
}

MIMEBodyPart::MIMEBodyPart() :
	m_contentDisposition	(UNINITIALIZED),
	m_contentSubType		(false,""),
	m_contentTypeParams		(false,""),
	m_contentID				(false,""),
	m_contentDispParams		(false,""),
	m_contentDescription	(false,"")
{
	mimeObjType = MIMEObjType_BodyPart;
}

MIMEBodyPart::~MIMEBodyPart()
{
}

MIMEBodyPart::MIMEBodyPart(const MIMEBodyPart& part)
{
	m_contentDisposition = part.m_contentDisposition;
	m_contentSubType     = part.m_contentSubType;
	m_contentTypeParams  = part.m_contentTypeParams;
	m_contentID          = part.m_contentID;
	m_contentDispParams  = part.m_contentDispParams;
	m_contentDescription = part.m_contentDescription;
	mimeObjType        = MIMEObjType_BodyPart;
}



MIMEBodyPart::value_pair MIMEBodyPart::getContentSubType()
{
	return m_contentSubType;
}

void MIMEBodyPart::setContentSubType(WString subType)
{
	m_contentSubType.second  = subType;
	m_contentSubType.first   = true;
}

MIMEBodyPart::value_pair MIMEBodyPart::getContentTypeParams()
{
	return m_contentTypeParams;
}

void MIMEBodyPart::setContentTypeParams(WString params)
{
	m_contentTypeParams.first  = true;
	m_contentTypeParams.second = params;
}

MIMEBodyPart::value_pair MIMEBodyPart::getContentID()
{
	return m_contentID;
}

void MIMEBodyPart::setContentID(WString cid)
{
	m_contentID.first  = true;
	m_contentID.second = cid;
}

int MIMEBodyPart::getContentDisposition()
{
	return m_contentDisposition;
}

void MIMEBodyPart::setContentDisposition(int disposition)
{
	if (disposition != MIMEBodyPart::ATTACHMENT && disposition != MIMEBodyPart::INLINE)
		throw MIMEException("Invalid ContentDisposition:");

	m_contentDisposition = disposition;
}

MIMEBodyPart::value_pair MIMEBodyPart::getContentDispParams()
{
	return m_contentDispParams;
}

void MIMEBodyPart::setContentDispParams(WString params)
{
	m_contentDispParams.first  = true;
	m_contentDispParams.second = params;
}

MIMEBodyPart::value_pair MIMEBodyPart::getContentDescription()
{
	return m_contentDescription;
}

void MIMEBodyPart::setContentDescription(WString description)
{
	m_contentDescription.first  = true;
	m_contentDescription.second = description;
}

std::string MIMEBodyPart::encodeContDispParams(WString contDispParams)
{
	std::string newcontDispParams;
	//contDispParams = L"filename=éclair.pdf";
	int startidx = contDispParams.find (L"filename=");
	if (startidx!= -1)
	{

		while (contDispParams[startidx] != L';') 
			startidx--;

		int endidx = contDispParams.find(L';',startidx+1);
		if (endidx == -1)
			endidx = contDispParams.length();

		int idx2 = contDispParams.find(L'=',startidx);
		JDF::WString filename =contDispParams.substr(idx2+1,endidx);
		filename = filename.trim();
		if (filename.startsWith(L'"'))
		{
			int subidx = filename.find(L'"',1);
			if (subidx == -1)
				subidx = filename.length();
			filename = filename.substr(1,subidx-1);
		}
		newcontDispParams = contDispParams.erase(startidx,endidx-startidx).getBytes(L"ASCII");

		int i;
		// only use the filename
		// check if we need to perform encoding for non-ASCII
		for (i = 0; i < filename.length(); i++)
		{
 			if (filename[i] > 0x7F)
				break;
		}
		if (i<filename.length())
		{
			newcontDispParams += "; filename*=UTF-8''";
			newcontDispParams += filename.getBytes(L"UTF-8");
		}
		else
		{
			newcontDispParams += "; filename=\"";
			newcontDispParams += filename.getBytes("ASCII");
			newcontDispParams += "\"";
		}
		return newcontDispParams;
	}
	else
		return contDispParams.getBytes(L"ASCII");
}
} // namespace JDF

