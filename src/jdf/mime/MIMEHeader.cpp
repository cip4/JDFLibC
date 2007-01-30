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
#include <jdf/mime/MIMEHeader.h>

#include <xercesc/util/XMLUniDefs.hpp>


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

	const JDFCh MIMEHeader::BCC[] =
	{
		chLatin_B, chLatin_c, chLatin_c,chNull
	};

	const JDFCh MIMEHeader::TO[] =
	{
		chLatin_T, chLatin_o, chNull
	};

	const JDFCh MIMEHeader::DATE[] =
	{
		chLatin_D, chLatin_a, chLatin_t, chLatin_e, chNull
	};

	const JDFCh MIMEHeader::FROM[] =
	{
		chLatin_F, chLatin_r, chLatin_o, chLatin_m, chNull
	};

	const JDFCh MIMEHeader::ORGANIZATION[] =
	{
		chLatin_O, chLatin_r, chLatin_g, chLatin_a, 
			chLatin_n, chLatin_i, chLatin_s, chLatin_a, 		
			chLatin_t, chLatin_i, chLatin_o, chLatin_n, 		
			chNull
	};

	const JDFCh MIMEHeader::PRIORITY[] =
	{
		chLatin_P, chLatin_r, chLatin_i, chLatin_o, 
			chLatin_r, chLatin_i, chLatin_t, chLatin_y, 		
			chNull
	};

	const JDFCh MIMEHeader::REPLY_TO[] = 
	{
		chLatin_R, chLatin_e, chLatin_p, chLatin_l, 
			chLatin_y, chDash, chLatin_T, chLatin_o, 		
			chNull
	};

	const JDFCh MIMEHeader::SUBJECT[] =
	{
		chLatin_S, chLatin_u, chLatin_b, chLatin_j, 
			chLatin_e, chLatin_c, chLatin_t, 		
			chNull
	};


	MIMEHeader::MIMEHeader(const WString& name, const WString& value) :
		m_headerName	(name),
			m_headerValue	(value)
		{
		}

		MIMEHeader::MIMEHeader(const WString& s)
		{
			int sepIndex = -1, strLen;
			WString tmp;

			tmp = s.trim();
			strLen = tmp.length();

			while (strLen > 0)
			{
				if ((tmp.find_last_of(chLF, strLen-1) > 0) ||
					(tmp.find_last_of(chCR, strLen-1) > 0))
					strLen--;
				else
					break;
			}
			if (strLen <= 3)
				throw MIMEException("string in <name>:<value> form expected.");

			sepIndex = tmp.find_first_of(chColon);
			if ((sepIndex == -1) || (sepIndex == strLen-1))
				throw MIMEException("String in <name>:<value> form expected.");

			m_headerName  = tmp.substring(0,sepIndex);
			m_headerValue = tmp.substring(sepIndex+1,strLen);
		}

		MIMEHeader::MIMEHeader(char* line, int len)
		{

			int sepIndex = -1;

			// trime trailing spaces and CRLFs
			while ((len > 0) && ((line[len-1] == '\n') ||
				(line[len-1] == '\r') || (line[len-1] == ' ')))
				len--;
			if (len <= 3)
				throw MIMEException("char[] in <name>:<value> form expected.");

			for (int i = 0;i<len;i++)
			{
				if (line[i] == ':')
				{
					sepIndex=i;
					break;
				}
			}
			if (sepIndex == -1 ||  sepIndex == len-1)
				throw MIMEException("byte[] in <name>:<value> form expected.");

			m_headerName  = WString(line,sepIndex);
			m_headerValue = WString(line+(sepIndex+1), (len - (sepIndex+1) ));
		}

		MIMEHeader::MIMEHeader(const MIMEHeader& m)
		{
			m_headerName  = m.m_headerName;
			m_headerValue = m.m_headerValue;
		}

		MIMEHeader& MIMEHeader::operator=(const MIMEHeader& m)
		{
			if (&m == this)
				return *this;
			m_headerName  = m.m_headerName;
			m_headerValue = m.m_headerValue;
			return *this;
		}

		WString MIMEHeader::getName() const
		{
			return m_headerName.trim();
		}

		WString MIMEHeader::getValue() const
		{
			return m_headerValue.trim();
		}

		WString MIMEHeader::getLine() const
		{
			WString line;
			line = m_headerName.trim();
			line.append(1,chColon);
			line.append(1,chSpace);
			line.append(m_headerValue.trim());
			line.append(1,chCR);
			line.append(1,chLF);
			return line;
		}

		void MIMEHeader::setName(const WString& name)
		{
			m_headerName = name;
		}

		void MIMEHeader::setValue(const WString& value)
		{
			m_headerValue = value;
		}

} // namespace JDF
