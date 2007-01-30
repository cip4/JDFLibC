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
#include <jdf/mime/MIMEMessage.h>
#include <jdf/mime/MIMEMessagePart.h>

#include <jdf/lang/Janitor.h>
#include <jdf/util/Unicode.h>
#include <jdf/io/InputStream.h>
#include <jdf/io/OutputStream.h>

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

	const int MIMEMessagePart::BINARY = MIMEBodyPart::BINARY;
	const int MIMEMessagePart::E7BIT  = MIMEBodyPart::E7BIT;
	const int MIMEMessagePart::E8BIT  = MIMEBodyPart::E8BIT;
	const int MIMEMessagePart::UNINITIALIZED = -1;

	static const int DATABUFSZ=64000;

	const JDFCh* MIMEMessagePart::m_StringEncoding[] = 
	{
		Unicode::MIMEENCODINGBASE64, 
			Unicode::MIMEENCODINGQP,
			Unicode::MIMEENCODINGBINARY, 
			Unicode::MIMEENCODING7BIT,
			Unicode::MIMEENCODING8BIT
	};

	const JDFCh* MIMEMessagePart::m_StringDisposition[] = 
	{
		Unicode::MIMEDISPATTACHMENT, 
			Unicode::MIMEDISPINLINE
	};

	const JDFCh* MIMEMessagePart::MESSAGE = Unicode::MIMEMESSAGE;

	MIMEMessagePart::MIMEMessagePart()
	{
		m_parsedPart              = 0;
		m_contentDisposition      = UNINITIALIZED;
		m_contentTransferEncoding = UNINITIALIZED;
		m_theMessage              = NULL;
		m_partial                 = NULL;
		mimeObjType             = MIMEObjType_MessagePart;
	}

	MIMEMessagePart::MIMEMessagePart(MIMEMessage* msg)
	{
		m_parsedPart              = 0;
		m_contentDisposition      = UNINITIALIZED;
		m_contentTransferEncoding = UNINITIALIZED;
		m_theMessage              = NULL;
		m_partial                 = NULL;
		mimeObjType               = MIMEObjType_MessagePart;

		if (msg != NULL)
		{
			m_theMessage = (MIMEMessage*) msg->clone();
		}
		else
			throw MIMEException("MIMEMessagePart(): NULL message passed.");
	}

	MIMEMessagePart::MIMEMessagePart(const MIMEMessagePart& part) : MIMEBodyPart(part)
	{
		m_parsedPart              = 0;
		m_contentDisposition      = UNINITIALIZED;
		m_contentTransferEncoding = UNINITIALIZED;
		m_theMessage              = NULL;
		m_partial                 = NULL;
		mimeObjType             = MIMEObjType_MessagePart;

		if (part.m_theMessage != NULL)
		{
			m_theMessage = (MIMEMessage*) part.m_theMessage->clone();
		}
	}

	MIMEMessagePart::~MIMEMessagePart()
	{
		delete m_theMessage;
		deletePartial();
	}

	MIMEMessagePart::value_pair MIMEMessagePart::getContentType()
	{
		return value_pair(true,MESSAGE);
	}

	void MIMEMessagePart::setContentEncoding(int encoding)
	{
		if (encoding == BINARY || encoding == E7BIT || encoding == E8BIT)
			m_contentTransferEncoding = encoding;
		else
			throw MIMEException("Invalid/Inacceptable Content-Transfer-Encoding:" + WString::valueOf(encoding));
	}

	int MIMEMessagePart::getContentEncoding()
	{
		if (m_contentTransferEncoding == UNINITIALIZED)
			return (-1);
		else
			return (m_contentTransferEncoding);
	}

	void MIMEMessagePart::setMessage(MIMEMessage* msg)
	{
		setMessage(msg,true);
	}

	void MIMEMessagePart::setMessage(MIMEMessage* msg, bool clone)
	{
		if (m_theMessage != NULL)
			throw MIMEException("setMessage(): already set!");

		if (msg != NULL)
			m_theMessage = (MIMEMessage*) (clone ? msg->clone() : msg);
		else
			throw MIMEException("setMessage():NULL message passed");
	}

	MIMEMessage* MIMEMessagePart::getMessage()
	{
		return getMessage(true);
	}

	MIMEMessage* MIMEMessagePart::getMessage(bool clone)
	{
		if (m_theMessage == NULL)
			throw MIMEException("getMessage():  null Message in Body!");

		MIMEMessage* l_msg = (MIMEMessage*) (clone ? m_theMessage->clone() : m_theMessage);
		return l_msg;
	}

	void MIMEMessagePart::deleteMessage()
	{
		delete m_theMessage;
		m_theMessage=0;
		m_ExtBodyHeadersTable.clear();
	}

	void MIMEMessagePart::setExtBodyHeader(const WString& name, const WString& value)
	{
		if (name.find_first_of(chColon) > -1)
			throw MIMEException("Invalid ':' in Header name");

		WString l_hashKey = name.toUpperCase();
		m_ExtBodyHeadersTable.insert(hmap<WString,MIMEHeader,ElfHash>::value_type(l_hashKey,MIMEHeader(name,value)) );
	}

	MIMEMessagePart::value_pair MIMEMessagePart::getExtBodyHeader(const WString& name)
	{
		WString l_hashkey = name.toUpperCase();

		hmap<WString,MIMEHeader,ElfHash>::iterator it = m_ExtBodyHeadersTable.find(l_hashkey);
		if (it == m_ExtBodyHeadersTable.end())
		{
			return value_pair(false,JDFStrL(""));
		}
		else
		{
			return value_pair(true,(*it).second.getValue());
		}		
	}

	std::vector<MIMEHeader> MIMEMessagePart::getAllHeaders()
	{
		std::vector<MIMEHeader> hdrs;

		hmap<WString,MIMEHeader,ElfHash>::iterator it = m_ExtBodyHeadersTable.begin();
		while (it != m_ExtBodyHeadersTable.end())
		{
			hdrs.push_back((*it).second);
			it++;
		}
		return hdrs;
	}

	void MIMEMessagePart::setPartial(InputStream* instream)
	{
		if (m_partial != NULL)
			throw MIMEException("Partial already set.");

		if ((m_contentSubType.first == true) && 
			(!m_contentSubType.second.equalsIgnoreCase("partial")))
			throw MIMEException("Content-Subtype partial expected");

		m_partial = instream;
	}

	void MIMEMessagePart::deletePartial()
	{
		delete m_partial;
		m_partial = NULL;
	}

	void MIMEMessagePart::putByteStream(OutputStream& os)
	{
		bool l_external_body   = false;
		bool l_message_partial = false;
		WString l_contentSubType(JDFStrL(""));

		if (m_contentSubType.first)
			l_contentSubType = m_contentSubType.second.trim();

		if (l_contentSubType.equalsIgnoreCase(JDFStrL("external-body")))
		{
			l_external_body = true;
		}
		else if (l_contentSubType.equalsIgnoreCase(JDFStrL("partial")))
		{
			l_message_partial = true;
			if (m_partial == NULL)
				throw MIMEException("Message partial not set");
			if (m_contentTransferEncoding != E7BIT && m_contentTransferEncoding != UNINITIALIZED)
				throw MIMEException("Bad content-encoding for message/partial");
		}
		if (m_theMessage == NULL && (!l_external_body) && (!l_message_partial))
			throw MIMEException("putBytesStream(): null Message body!");

		// write out the headers first
		WString l_hdrbuf;

		// content-type
		l_hdrbuf.append(JDFStrL("Content-Type: message/"));
		if (m_contentSubType.first)
			l_hdrbuf.append(m_contentSubType.second);
		else
		{
			if (m_theMessage)
				l_hdrbuf.append(JDFStrL("rfc822")); // default
			else
				throw MIMEException("putByteStream(): no content-subtype.");
		}
		if (m_contentTypeParams.first && m_contentTypeParams.second.length() > 0)
		{
			l_hdrbuf.append(JDFStrL("; "));
			l_hdrbuf.append(m_contentTypeParams.second);
		}
		l_hdrbuf.append(JDFStrL("\r\n"));

		// write the header out to os

		try
		{
			char* data = l_hdrbuf.getBytes("ASCII");
			ArrayJanitor<char> dataJanitor(data);
			// unicode to ascii conversion
			os.write(data,strlen(data));
		} 
		catch (Exception& e)
		{
			throw MIMEException("Content-Type: " + e.getMessage());
		}

		// contentID

		if (m_contentID.first)
		{
			l_hdrbuf = JDFStrL("");
			l_hdrbuf.append(JDFStrL("Content-ID: ") + m_contentID.second);
			l_hdrbuf.append(JDFStrL("\r\n"));

			try
			{
				char* data = l_hdrbuf.getBytes("ASCII");
				ArrayJanitor<char> dataJanitor(data);
				// unicode to ascii conversion
				os.write(data,strlen(data));
			} 
			catch (Exception& e)
			{
				throw MIMEException("Content-ID: " + e.getMessage());
			}
		}

		// contentDisposition

		if (m_contentDisposition != UNINITIALIZED)
		{
			l_hdrbuf = JDFStrL("");
			l_hdrbuf.append("Content-Disposition: ");
			l_hdrbuf.append(m_StringDisposition[m_contentDisposition]);

			if (m_contentDispParams.first)
			{
				l_hdrbuf.append("; ");
				l_hdrbuf.append(m_contentDispParams.second);
			}
			l_hdrbuf.append(JDFStrL("\r\n"));
			try
			{
				char* data = l_hdrbuf.getBytes("ASCII");
				ArrayJanitor<char> dataJanitor(data);
				// unicode to ascii conversion
				os.write(data,strlen(data));
			} 
			catch (Exception& e)
			{
				throw MIMEException("Content-Disposition: " + e.getMessage());
			}
		}

		if (m_contentDescription.first)
		{
			l_hdrbuf = JDFStrL("");
			l_hdrbuf.append(JDFStrL("Content-Description: ") + m_contentDescription.second);
			l_hdrbuf.append(JDFStrL("\r\n"));

			try
			{
				char* data = l_hdrbuf.getBytes("ASCII");
				ArrayJanitor<char> dataJanitor(data);
				// unicode to ascii conversion
				os.write(data,strlen(data));
			} 
			catch (Exception& e)
			{
				throw MIMEException("Content-Description: " + e.getMessage());
			}
		}

		if (m_contentSubType.first)
		{
			if ((l_message_partial || l_external_body) && m_contentTransferEncoding != UNINITIALIZED)
				m_contentTransferEncoding = E7BIT; // As mandated by MIME standard
		}

		if (m_contentTransferEncoding != UNINITIALIZED)
		{
			if (l_external_body)
				m_contentTransferEncoding = E7BIT;

			l_hdrbuf=JDFStrL("");
			l_hdrbuf.append(JDFStrL("Content-Transfer-Encoding: "));
			l_hdrbuf.append(m_StringEncoding[m_contentTransferEncoding]);
			l_hdrbuf.append(JDFStrL("\r\n"));
			try
			{
				char* data = l_hdrbuf.getBytes("ASCII");
				ArrayJanitor<char> dataJanitor(data);
				// unicode to ascii conversion
				os.write(data,strlen(data));
			} 
			catch (Exception& e)
			{
				throw MIMEException("Content-Transfer-Encoding: " + e.getMessage());
			}
		}

		// blank line after headers
		os.write(CRLF,strlen(CRLF));

		// write out the message part if it is not external-body
		if ((m_theMessage != NULL) && (!l_external_body) && (!l_message_partial))
			m_theMessage->putByteStream(os);
		else if (l_external_body)
		{
			if (m_ExtBodyHeadersTable.size())
			{
				hmap<WString,MIMEHeader,ElfHash>::iterator it = m_ExtBodyHeadersTable.begin();
				while (it != m_ExtBodyHeadersTable.end())
				{
					try
					{
						l_hdrbuf = (*it).second.getLine();
						char* data = l_hdrbuf.getBytes("ASCII");
						ArrayJanitor<char> dataJanitor(data);
						// unicode to ascii conversion
						os.write(data,strlen(data));
					} 
					catch (Exception& e)
					{
						throw MIMEException("Content-Transfer-Encoding: " + e.getMessage());
					}
					it++;
				} // while
				os.write(CRLF,strlen(CRLF));
			} // if m_ExtBodyHeadersTable
		} //  if l_external_body
		else if (l_message_partial)
		{
			os.write(CRLF,strlen(CRLF));
			char* readbuf = new char[DATABUFSZ];
			int l_len;
			try
			{
				while ((l_len = m_partial->read(readbuf,DATABUFSZ,0,DATABUFSZ)) > 0)
				{
					os.write(readbuf,DATABUFSZ,0,l_len);
				}
			} catch (Exception& e)
			{
				delete readbuf;
				throw e;
			}
		} // l_message__partial
		os.write(CRLF,strlen(CRLF)); // terminate the part
	} // end putByteStream

	MIMEBodyPart* MIMEMessagePart::clone()
	{
		return new MIMEMessagePart(*this);
	}

} // namespace JDF

