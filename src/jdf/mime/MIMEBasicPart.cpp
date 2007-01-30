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
#include <jdf/mime/MIMEBasicPart.h>
#include <jdf/io/ByteArrayInputStream.h>
#include <jdf/io/FileOutputStream.h>
#include <jdf/io/BASE64Encoder.h>
#include <jdf/io/QPEncoder.h>
#include <jdf/lang/ByteBuffer.h>
#include <jdf/lang/Janitor.h>
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
	
	const int MIMEBasicPart::TEXT = 0;
	const int MIMEBasicPart::AUDIO =1;
	const int MIMEBasicPart::IMAGE =2;
	const int MIMEBasicPart::VIDEO =3;
	const int MIMEBasicPart::APPLICATION =4;
	
	const int MIMEBasicPart::BASE64          = MIMEBodyPart::BASE64;
	const int MIMEBasicPart::QP              = MIMEBodyPart::QP;
	const int MIMEBasicPart::BINARY          = MIMEBodyPart::BINARY;
	const int MIMEBasicPart::E7BIT           = MIMEBodyPart::E7BIT;
	const int MIMEBasicPart::E8BIT           = MIMEBodyPart::E8BIT;
	const int MIMEBasicPart::EIGNORE         = 99;
	const int MIMEBasicPart::UNINITIALIZED   = -1;
	const int MIMEBasicPart::MAXDATABUFSIZE  = 1111111;
	
	static const int DATABUFSZ=64000;
	
	
	const JDFCh* MIMEBasicPart::m_StringContentTypes[] = 
	{
		Unicode::MIMECONTENTTYPETEXT, 
			Unicode::MIMECONTENTTYPEAUDIO,
			Unicode::MIMECONTENTTYPEIMAGE, 
			Unicode::MIMECONTENTTYPEVIDEO,
			Unicode::MIMECONTENTTYPEAPPLICATION
	};
	
	const JDFCh* MIMEBasicPart::m_StringEncoding[] = 
	{
		Unicode::MIMEENCODINGBASE64, 
			Unicode::MIMEENCODINGQP,
			Unicode::MIMEENCODINGBINARY, 
			Unicode::MIMEENCODING7BIT,
			Unicode::MIMEENCODING8BIT
	};
	
	const JDFCh* MIMEBasicPart::m_StringDisposition[] = 
	{
		Unicode::MIMEDISPATTACHMENT, 
			Unicode::MIMEDISPINLINE
	};
	
	MIMEBasicPart::MIMEBasicPart(int contentType) :
		m_contentMD5(false,"")
		{
			if (contentType == TEXT)		
				m_contentType = TEXT;
			else if (contentType == AUDIO)		 
				m_contentType = AUDIO;
			else if (contentType == IMAGE)		 
				m_contentType = IMAGE;
			else if (contentType == VIDEO)		 
				m_contentType = VIDEO;
			else if (contentType == APPLICATION) 
				m_contentType = APPLICATION;
			else
				throw MIMEException("Invalid content-type:");
			
			m_parsedPart			  = 0;
			m_contentDisposition	  = UNINITIALIZED;
			m_contentTransferEncoding = UNINITIALIZED;
			m_databuf				  = NULL;
			m_readbuf				  = NULL;
			m_dataStream			  = NULL;
			m_charStream			  = NULL;
			m_nStartMessageDataIndex  = UNINITIALIZED;
			m_nEndMessageDataIndex    = UNINITIALIZED;
			m_nMessageDataLen         = 0;
			m_bDecodedData            = false;
			mimeObjType             = MIMEObjType_BasicPart;
		}
		
		MIMEBasicPart::MIMEBasicPart(const MIMEBasicPart& part) : MIMEBodyPart(part),
			m_contentMD5(false,"")
		{
			m_mimeHeadersTable        = part.m_mimeHeadersTable; 
			m_dataStream              = NULL;
			m_charStream              = NULL;
			m_databuf                 = NULL;
			m_readbuf				  = NULL;
			m_contentDisposition      = UNINITIALIZED;
			// use the content transfer encoding of the original part
			m_contentTransferEncoding = part.m_contentTransferEncoding;
			mimeObjType             = MIMEObjType_BasicPart;

			
			if (part.m_databuf)
			{
				m_databuf = new ByteBuffer(*part.m_databuf);
			}
			else if (part.m_dataStream != NULL)
			{
				m_databuf = getStreamData(*part.m_dataStream);
			}
			m_contentType            = part.m_contentType;
			m_contentMD5			 = part.m_contentMD5;
			m_nStartMessageDataIndex = part.m_nStartMessageDataIndex;
			m_nEndMessageDataIndex   = part.m_nEndMessageDataIndex;
			m_nMessageDataLen        = part.m_nMessageDataLen;
			m_bDecodedData           = part.m_bDecodedData;
		}
		
		MIMEBodyPart::value_pair MIMEBasicPart::getContentType()
		{
			return value_pair(true,m_StringContentTypes[m_contentType]);
		}
		
		MIMEBodyPart::value_pair MIMEBasicPart::getContentMD5()
		{
			return m_contentMD5;
		}
		
		void MIMEBasicPart::setContentMD5(const WString& md5)
		{
			m_contentMD5.first = true;
			m_contentMD5.second = md5;
		}
		
		InputStream& MIMEBasicPart::getBodyData()
		{
			if (m_databuf == NULL && m_dataStream == NULL)
				throw MIMEException("getBodyData(): NO BodyData present.");
			
			if (m_databuf)
			{
				if (m_charStream)
					m_charStream->reset();
				else
					m_charStream = new ByteArrayInputStream(m_databuf->bytes(),m_databuf->size());
				return *m_charStream;
			}
			if (m_dataStream->markSupported())
			{
				m_dataStream->reset();
			}
			return *m_dataStream;
		}
		
		ByteBuffer* MIMEBasicPart::getDataBuf()
		{
			return m_databuf;
		}
		
		void MIMEBasicPart::setBodyData(InputStream* is,bool takeOwnership)
		{
			if (m_databuf != NULL || m_dataStream != NULL)
				throw MIMEException("setBodyData(): BodyData already set.");
			
			if (is == NULL)
				throw MIMEException("setBodyData(): NULL inputStream");

			// cannot set reliable data length for streams
			m_nMessageDataLen = 0;
			m_dataStream = is;
			m_dataStreamOwnerShip = takeOwnership;

			/*
			setMessageDataLen(is->available());
			
			if (m_nMessageDataLen <= 0)
			{
				m_nMessageDataLen = 0;
				throw MIMEException("setBodyData(): no data in inputStream");
			}
			if (m_nMessageDataLen > MAXDATABUFSIZE)
			{
				m_dataStream = is;
				if (is->markSupported())
					is->mark(2*m_nMessageDataLen);
			}
			else
			{
				// smaller than limit 
				// cache everything in a data buffer
				char* inbuf = new char[DATABUFSZ];
				ArrayJanitor<char> inbufJanitor(inbuf);
				
				int bytesRead = is->read(inbuf,DATABUFSZ,0,DATABUFSZ);
				if (bytesRead > 0)
				{
					m_databuf = new ByteBuffer(DATABUFSZ); // initial size
				}
				else
					throw MIMEException("setBodyData(): InputStream empty.");
				while (bytesRead > 0)
				{
					m_databuf->append(inbuf,bytesRead);
					bytesRead = is->read(inbuf,DATABUFSZ,0,DATABUFSZ);
				}
			}
			*/
		}
		
		void MIMEBasicPart::setBodyData(const WString& s)
		{
			if (m_databuf != NULL && m_dataStream != NULL)
			{
				throw MIMEException("setBodyData() : BodyData already set.");
			}
			char* data = s.getBytes();
			int len = strlen(data);
			// don't copy
			m_databuf = new ByteBuffer(data,len);
			setMessageDataLen(len);
		}
		
		void MIMEBasicPart::setBodyData(ByteBuffer* data)
		{
			if(m_databuf != NULL && m_dataStream != NULL)
			{
				throw MIMEException("setBodyData() : BodyData already set.");
			}
			if (data != NULL)
			{
				m_databuf = data;
				setMessageDataLen(data->size());
			}
		}
		
		void MIMEBasicPart::setBodyData(char* s, int len)
		{
			if (m_databuf != NULL && m_dataStream != NULL)
			{
				throw MIMEException("setBodyData() : BodyData already set.");
			}
			// don't copy
			m_databuf = new ByteBuffer(s,len);
			setMessageDataLen(len);
			
		}
		
		MIMEBasicPart::~MIMEBasicPart()
		{
			deleteBodyPart();
		}
		
		void MIMEBasicPart::deleteBodyPart()
		{
			delete m_databuf;
			delete[] m_readbuf;
			if (m_dataStreamOwnerShip)
				delete m_dataStream;
			delete m_charStream;
			
			m_databuf    = NULL;
			m_readbuf    = NULL;
			m_dataStream = NULL;
			m_charStream = NULL;
			
		}
		
		void MIMEBasicPart::putByteStream(const WString& fullFileName)
		{
			FileOutputStream fos(fullFileName);
			putByteStream(fos);
		}
		
		

		void MIMEBasicPart::putByteStream(OutputStream& os)
		{
			if (m_databuf == NULL && m_dataStream == NULL)
			{
				throw MIMEException("MIMEBasicPart.putByteStream() : No BodyData!");
			}
			// write out the headers first
			
			WString l_hdrbuf;
			
			// headers in member variables
			
			if (m_contentType == TEXT)
			{
				l_hdrbuf.append("Content-Type: text/");
				if (m_contentSubType.first)
					l_hdrbuf.append(m_contentSubType.second);
				else
					l_hdrbuf.append("plain");
				if (m_contentTypeParams.first && m_contentTypeParams.second.length() > 0)
				{
					l_hdrbuf.append("; ");
					l_hdrbuf.append(m_contentTypeParams.second);
					l_hdrbuf.append("\r\n");
				}
				else
					l_hdrbuf.append("\r\n");
			}
			else if (m_contentType == AUDIO)
			{
				l_hdrbuf.append("Content-Type: audio/");
				if (m_contentSubType.first)
					l_hdrbuf.append(m_contentSubType.second);
				else
					throw MIMEException("putByteStream: No Content-subtype.");
				if (m_contentTypeParams.first && m_contentTypeParams.second.length() > 0)
				{
					l_hdrbuf.append("; ");
					l_hdrbuf.append(m_contentTypeParams.second);
					l_hdrbuf.append("\r\n");
				}
				else
					l_hdrbuf.append("\r\n");
			}
			else if (m_contentType == IMAGE)
			{
				l_hdrbuf.append("Content-Type: image/");
				if (m_contentSubType.first)
					l_hdrbuf.append(m_contentSubType.second);
				else
					throw MIMEException("putByteStream: No Content-subtype.");
				if (m_contentTypeParams.first && m_contentTypeParams.second.length() > 0)
				{
					l_hdrbuf.append("; ");
					l_hdrbuf.append(m_contentTypeParams.second);
					l_hdrbuf.append("\r\n");
				}
				else
					l_hdrbuf.append("\r\n");
			}
			else if (m_contentType == VIDEO)
			{
				l_hdrbuf.append("Content-Type: video/");
				if (m_contentSubType.first)
					l_hdrbuf.append(m_contentSubType.second);
				else
					throw MIMEException("putByteStream: No Content-subtype.");
				if (m_contentTypeParams.first && m_contentTypeParams.second.length() > 0)
				{
					l_hdrbuf.append("; ");
					l_hdrbuf.append(m_contentTypeParams.second);
					l_hdrbuf.append("\r\n");
				}
				else
					l_hdrbuf.append("\r\n");
			}
			else if (m_contentType == APPLICATION)
			{
				l_hdrbuf.append("Content-Type: application/");
				if (m_contentSubType.first)
					l_hdrbuf.append(m_contentSubType.second);
				else
					l_hdrbuf.append("octet-stream");
				if (m_contentTypeParams.first && m_contentTypeParams.second.length() > 0)
				{
					l_hdrbuf.append("; ");
					l_hdrbuf.append(m_contentTypeParams.second);
					l_hdrbuf.append("\r\n");
				}
				else
					l_hdrbuf.append("\r\n");
			}
			else
				throw MIMEException("Invalid content-type:" + m_contentType);
			
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
				l_hdrbuf = "Content-ID: " + m_contentID.second;
				l_hdrbuf.append("\r\n");
				
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
			
			// contentMD5
			if (m_contentMD5.first)
			{
				l_hdrbuf = "Content-MD5: " + m_contentMD5.second;
				l_hdrbuf.append("\r\n");
				
				try
				{
					char* data = l_hdrbuf.getBytes("ASCII");
					ArrayJanitor<char> dataJanitor(data);
					// unicode to ascii conversion
					os.write(data,strlen(data));
				} 
				catch (Exception& e)
				{
					throw MIMEException("Content-MD5: " + e.getMessage());
				}
			}
			
			// contentDisposition
			if (m_contentDisposition != UNINITIALIZED)
			{
				std::string contentDisposition= "Content-Disposition: ";
				JDF::WString content = m_StringDisposition[m_contentDisposition];
				contentDisposition.append(content.getBytes(L"ASCII"));
			
				if (m_contentDispParams.first)
				{
					WString tmp(L"; ");
					tmp.append(m_contentDispParams.second);
					contentDisposition.append(encodeContDispParams(tmp));
				}
				
				contentDisposition.append("\r\n");
				
				try
				{
					os.write(contentDisposition.data(),contentDisposition.length());
				} 
				catch (Exception& e)
				{
					throw MIMEException("Content-Disposition: " + e.getMessage());
				}
			}
			
			// contentDescription
			if (m_contentDescription.first)
			{
				l_hdrbuf = "Content-Description: ";
				l_hdrbuf.append(m_contentDescription.second);
				l_hdrbuf.append("\r\n");
				
				try
				{
					char* data = l_hdrbuf.getBytes("ASCII");
					ArrayJanitor<char> dataJanitor(data);
					// unicode to ascii conversion
					os.write(data,strlen(data));
				} 
				catch (Exception& e)
				{
					throw MIMEException("Content-MD5: " + e.getMessage());
				}
			}
			if (m_contentTransferEncoding != EIGNORE && m_contentTransferEncoding != UNINITIALIZED)
			{
				l_hdrbuf = "Content-Transfer-Encoding: ";
				l_hdrbuf.append(m_StringEncoding[m_contentTransferEncoding]);
				l_hdrbuf.append("\r\n");
				
				try
				{
					char* data = l_hdrbuf.getBytes("ASCII");
					ArrayJanitor<char> dataJanitor(data);
					// unicode to ascii conversion
					os.write(data,strlen(data));
				} 
				catch (Exception& e)
				{
					throw MIMEException("Content-MD5: " + e.getMessage());
				}
			}
			
			// Do all the other headers
			std::vector<MIMEHeader> hdrs = getAllHeaders();
			if (hdrs.size())
			{
				std::vector<MIMEHeader>::iterator it;
				
				for (it = hdrs.begin(); it != hdrs.end(); it++)
				{
					try
					{
						WString s = (*it).getLine();
						char* data = s.getBytes("ASCII");
						ArrayJanitor<char> dataJanitor(data);
						// unicode to ascii conversion
						os.write(data,strlen(data));
					}
					catch (Exception& e)
					{
						throw MIMEException((*it).getLine() + ">" + e.getMessage());
					}
				}
			}
			// blank line after headers
			os.write(CRLF,strlen(CRLF));
			
			int encoding = m_contentTransferEncoding;
			if (encoding == UNINITIALIZED || encoding == EIGNORE)
				encoding = E7BIT;
			
			// write out the bodydata encoding if needed.
			if (encoding == BASE64)
			{
				if (m_databuf)
				{
					ByteArrayInputStream isb(m_databuf->bytes(),m_databuf->size());
					BASE64Encoder enc;
					enc.encodeBuffer(isb,os);
				}
				else
				{
					if (m_dataStream->markSupported())
						m_dataStream->reset();
					BASE64Encoder enc;
					enc.encodeBuffer(*m_dataStream,os);
				}
			}
			else if (encoding == QP)
			{
				if (m_databuf)
				{
					ByteArrayInputStream isb(m_databuf->bytes(),m_databuf->size());
					QPEncoder enc;
					enc.encodeBuffer(isb,os);
				}
				else
				{
					if (m_dataStream->markSupported())
						m_dataStream->reset();
					QPEncoder enc;
					enc.encodeBuffer(*m_dataStream,os);
				}
			}
			else if (encoding == BINARY || encoding == E7BIT || encoding == E8BIT || encoding == EIGNORE)
			{
				if (m_databuf)
				{
					os.write(m_databuf->bytes(),m_databuf->size());
				}
				else
				{
					if (m_dataStream->markSupported())
						m_dataStream->reset();
					if (m_readbuf == NULL)
						m_readbuf = new char[DATABUFSZ];
					
					int l_read = m_dataStream->read(m_readbuf,DATABUFSZ,0,DATABUFSZ);
					while (l_read > 0)
					{
						os.write(m_readbuf,l_read);
						l_read = m_dataStream->read(m_readbuf,DATABUFSZ,0,DATABUFSZ);
					}
				}
			}
			else
				throw MIMEException("Invalid Content Transfer Encoding : " + m_contentTransferEncoding);
} // putByteStream

int MIMEBasicPart::getSize()
{
	if (m_databuf)
	{
		return m_databuf->size();
	}
	else if (m_dataStream != NULL)
	{
		return m_nMessageDataLen;
	}
	return -1;
}

void MIMEBasicPart::setContentEncoding(int encoding)
{
	if (encoding == BASE64 || encoding == QP || encoding == BINARY ||
		encoding == E7BIT || encoding == E8BIT)
	{
		m_contentTransferEncoding = encoding;
	}
	else
		throw MIMEException("Invalid Content Transfer Encoding : " + encoding);
}

int MIMEBasicPart::getContentEncoding()
{
	if (m_contentTransferEncoding == UNINITIALIZED || m_contentTransferEncoding == EIGNORE)
		return (-1);
	
	return m_contentTransferEncoding;
}

void MIMEBasicPart::setHeader(const WString& name, const WString& value)
{
	if (name.find_first_of(chColon) > -1)
		throw MIMEException("Invalid ':' in Header name");
	
	// check if the header is one of those they need to specify with other methods
	value_pair result = isOKtoset(name);
	if (result.first == false)
		throw MIMEException("Invalid setHeader(). Use Method: " + result.second);
	
	WString l_hashkey = name.toUpperCase();
	m_mimeHeadersTable.insert(hmap<WString,MIMEHeader,ElfHash>::value_type(l_hashkey,MIMEHeader(name,value)) );
}

void MIMEBasicPart::addHeader(const WString& name, const WString& value)
{
	WString l_hashkey = name.toUpperCase();
	
	hmap<WString,MIMEHeader,ElfHash>::iterator it = m_mimeHeadersTable.find(l_hashkey);
	if (it == m_mimeHeadersTable.end())
	{
		setHeader(name,value);
	}
	else
	{
		WString oldValue = (*it).second.getValue();
		oldValue.append(value);
		m_mimeHeadersTable.erase(l_hashkey);
		m_mimeHeadersTable.insert(hmap<WString,MIMEHeader,ElfHash>::value_type(l_hashkey,MIMEHeader(name,oldValue)) );
	}
}

MIMEBodyPart::value_pair MIMEBasicPart::getHeader(const WString& name)
{
	WString l_hashkey = name.toUpperCase();
	
	hmap<WString,MIMEHeader,ElfHash>::iterator it = m_mimeHeadersTable.find(l_hashkey);
	if (it != m_mimeHeadersTable.end())
		return value_pair(true,(*it).second.getValue());
	else
		return value_pair(false,"");
}

void MIMEBasicPart::deleteHeader(const WString& name)
{
	WString l_hashkey = name.toUpperCase();
	m_mimeHeadersTable.erase(l_hashkey);
}

std::vector<MIMEHeader> MIMEBasicPart::getAllHeaders()
{
	std::vector<MIMEHeader> hdrs;
	
	hmap<WString,MIMEHeader,ElfHash>::iterator it = m_mimeHeadersTable.begin();
	while (it != m_mimeHeadersTable.end())
	{
		hdrs.push_back((*it).second);
		it++;
	}
	
	//	std::copy(m_mimeHeadersTable.begin(),m_mimeHeadersTable.end(),hdrs.begin());
	return hdrs;
}

MIMEBodyPart::value_pair MIMEBasicPart::isOKtoset(WString name)
{
	if (name.equalsIgnoreCase("Content-Type"))
		return value_pair(false,"setContentType()");
	
	if (name.equalsIgnoreCase("Content-ID"))
		return value_pair(false,"setContentID()");
	
	if (name.equalsIgnoreCase("Content-MD5"))
		return value_pair(false,"setContentMD5()");
	
	if (name.equalsIgnoreCase("Content-Disposition"))
		return value_pair(false,"setContentDisposition()");
	
	if (name.equalsIgnoreCase("Content-Description"))
		return value_pair(false,"setContentDescription()");
	
	if (name.equalsIgnoreCase("Content-Transfer-Encoding"))
		return value_pair(false,"setContentEncoding()");
	
	return value_pair(true,"");
}

ByteBuffer* MIMEBasicPart::getStreamData(InputStream& is)
{
	ByteBuffer* buf = NULL;
	char* readbuf;
	readbuf = new char[DATABUFSZ];
	try
	{
		if (is.markSupported())
			is.reset();
		
		int l_read = is.read(readbuf,DATABUFSZ,0,DATABUFSZ);
		if (l_read > 0)
		{
			buf = new ByteBuffer(DATABUFSZ);
		}
		else
		{
			delete[] readbuf;
			readbuf=NULL;
			return NULL;
		}
		
		while (l_read > 0)
		{
			buf->append(readbuf,l_read);
			l_read = is.read(readbuf,DATABUFSZ,0,DATABUFSZ);
		}
		if (is.markSupported())
			is.reset();
		return buf;
	}
	catch (IOException& )
	{
		delete[] readbuf;
		delete buf;
		readbuf=NULL;
		buf=NULL;
		return NULL;
	}
}

void MIMEBasicPart::setSize(int len)
{
	m_nMessageDataLen = len;
	// should this resize the data buffer
}

MIMEBodyPart* MIMEBasicPart::clone()
{
	return new MIMEBasicPart(*this);
}



} // namespace JDF

