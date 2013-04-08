/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2013 The International Cooperation for the Integration of 
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
#include <jdf/mime/FileMIMEType.h>
#include <jdf/mime/FileNameMap.h>
#include <jdf/mime/MIMEBasicPart.h>
#include <jdf/mime/MIMEMessagePart.h>
#include <jdf/mime/MIMEMultiPart.h>

#include <jdf/net/URLConnection.h>
#include <jdf/io/FilterOutputStream.h>
#include <jdf/io/FileInputStream.h>
#include <jdf/io/File.h>
#include <jdf/util/Unicode.h>
#include <jdf/util/Random.h>
#include <jdf/lang/Integer.h>
#include <jdf/lang/Integer64.h>
#include <jdf/lang/Janitor.h>


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
	
	const int MIMEMultiPart::UNINITIALIZED   = -1;
	
	const JDFCh* MIMEMultiPart::m_StringEncoding[] = 
	{
		Unicode::MIMEENCODINGBASE64, 
			Unicode::MIMEENCODINGQP,
			Unicode::MIMEENCODINGBINARY, 
			Unicode::MIMEENCODING7BIT,
			Unicode::MIMEENCODING8BIT
	};
	
	const JDFCh* MIMEMultiPart::m_StringDisposition[] = 
	{
		Unicode::MIMEDISPATTACHMENT, 
			Unicode::MIMEDISPINLINE
	};
	
	const JDFCh* MIMEMultiPart::MULTIPART = Unicode::MIMEMULTIPART;
	
	
	class CRLFOutputStream : public FilterOutputStream
	{
	public:
		
		CRLFOutputStream(OutputStream& out);
		CRLFOutputStream(OutputStream& out, unsigned int size);
		virtual ~CRLFOutputStream();
		void flush();
		void write(const char* b, size_t blen);
		void write(const char* b, size_t blen, size_t off, size_t len);
		void write(int b);
		bool crlfSeen(void) { 
			return m_CRLFSeen; 
		}
		
	private:
		
		//
		// Hide copy constructor and assignment operator.
		//
		
		CRLFOutputStream(const CRLFOutputStream&);
		CRLFOutputStream& operator=(const CRLFOutputStream&);
		
		bool m_CRLFSeen;
		int m_previousChar;
	};
	
	CRLFOutputStream::CRLFOutputStream(OutputStream& out) :
	FilterOutputStream(out),
		m_CRLFSeen(false),
		m_previousChar('a')
	{
	}
	
	CRLFOutputStream::~CRLFOutputStream()
	{
	}
	
	void CRLFOutputStream::flush()
	{
		mOut->flush();
	}
	
	void CRLFOutputStream::write(const char* b, size_t blen)
	{
		write(b,blen,0,blen);
	}
	
	void CRLFOutputStream::write(const char* b, size_t blen, size_t off, size_t len)
	{
		if (len == 0)
			return;
		m_CRLFSeen = false;
		
		if (len == 1 && b[off] == '\n' && m_previousChar == '\r')
			m_CRLFSeen = true;
		else if (b[off+len-1] == '\n' && b[off+len-2] == '\r')
			m_CRLFSeen = true;
		
		m_previousChar = b[off+len-1];
		
		mOut->write(b,blen,off,len);
	}
	
	void CRLFOutputStream::write(int b)
	{
		if ((char)b == '\n' && m_previousChar == '\r')
		{
			m_CRLFSeen = true;
		}
		else
			m_CRLFSeen = false;
		m_previousChar = b;
		mOut->write(b);
	}
	
	
	MIMEMultiPart::MIMEMultiPart() :
	m_preamble(false,"")
	{
		m_parsedPart              = 0;
		m_endPart                 = false;
		m_contentDisposition      = UNINITIALIZED;
		m_contentTransferEncoding = UNINITIALIZED;
		m_needPreamble            = false;
		m_boundary                = "";
		mimeObjType               = MIMEObjType_MultiPart;
	}
	
	MIMEMultiPart::MIMEMultiPart(InputStream* textIS, const WString& fileName, int encoding) :
	m_preamble(false,"")
	{
		MIMEBasicPart*   l_txtPart;
		MIMEBasicPart*   l_filePart;
		FileInputStream* l_fis;
		FileMIMEType     l_fmt;
		
		m_parsedPart              = 0;
		m_contentDisposition      = UNINITIALIZED;
		m_contentTransferEncoding = UNINITIALIZED;
		m_needPreamble            = false;
		mimeObjType               = MIMEObjType_MultiPart;
		
		if (textIS == NULL)
			throw MIMEException("Invalid NULL inputStream");
		
		if ((encoding != -1) && (encoding < MIMEBodyPart::BASE64 || encoding > MIMEBodyPart::E8BIT))
			throw MIMEException("Invalid MIME Encoding:" + Integer::toString(encoding));
		
		this->setContentSubType("mixed");
		l_fis = new FileInputStream(fileName);
		
		// the text-part!
		l_txtPart = new MIMEBasicPart(MIMEBasicPart::TEXT);
		l_txtPart->setContentSubType("plain");
		l_txtPart->setContentTypeParams("charset-us-ascii");
		l_txtPart->setContentEncoding(MIMEBodyPart::E7BIT);
		l_txtPart->setBodyData(textIS);
		
		// the file-part

		l_fmt = URLConnection::getFileNameMap()->getContentTypeFor(fileName);
		l_filePart = new MIMEBasicPart(l_fmt.content_type);
		l_filePart->setContentSubType(l_fmt.content_subtype);
		if (l_fmt.content_params.length())
			l_filePart->setContentTypeParams(l_fmt.content_params);
		if (encoding == -1)
			l_filePart->setContentEncoding(l_fmt.mime_encoding);
		else
			l_filePart->setContentEncoding(encoding);
		
		if (l_fmt.content_type == MIMEBasicPart::TEXT)
			; 
		else
			l_filePart->setContentDispParams(WString("filename=")+l_fmt.file_shortname);
		// set body-data of this part
		// transfer of ownership of l_fis
		l_filePart->setBodyData(l_fis);
		// add this part to multi-part
		// prevent cloning
		this->addBodyPart(l_txtPart,false);
		this->addBodyPart(l_filePart,false);
	}
	
	MIMEMultiPart::MIMEMultiPart(const MIMEMultiPart& m) : MIMEBodyPart(m)
	{
		m_needPreamble = false;
		mimeObjType = MIMEObjType_MultiPart;
		
		std::vector<MIMEBodyPart*>::const_iterator it = m.m_bodyParts.begin();
		while (it != m.m_bodyParts.end())
		{
			m_bodyParts.push_back((*it)->clone());
			it++;
		}
	}
	
	MIMEMultiPart::~MIMEMultiPart()
	{
		std::vector<MIMEBodyPart*>::iterator it;
		
		for (it = m_bodyParts.begin();it != m_bodyParts.end();it++)
		{
			delete (*it);
		}
		m_bodyParts.clear();
	}
	
	
	MIMEBodyPart::value_pair MIMEMultiPart::getContentType()
	{
		return value_pair(true,MULTIPART);
	}
	
	int MIMEMultiPart::getBodyPartCount()
	{
		return m_bodyParts.size();
	}
	
	MIMEBodyPart* MIMEMultiPart::getBodyPart(unsigned int index, bool clone)
	{
		if (index >= m_bodyParts.size())
			throw MIMEException("getBodyPart(). Index out of range: "  + Integer::toString(index));
		
		MIMEBodyPart* obj = m_bodyParts[index];
		
		if (obj->mimeObjType == MIMEObjType_BodyPart)
		{
			MIMEBasicPart* part = (MIMEBasicPart*) obj;
			if (clone)
				return part->clone();
			else
				return part;
		}
		else if (mimeObjType == MIMEObjType_MessagePart)
		{
			MIMEMessagePart* part = (MIMEMessagePart*) obj;
			if (clone)
				return part->clone();
			else
				return part;
		}
		else if (mimeObjType == MIMEObjType_MultiPart)
		{
			MIMEMultiPart* part = (MIMEMultiPart*) obj;
			if (clone)
				return part->clone();
			else
				return part;
		}
		else
			throw MIMEException("Invalid bodyPart!");
	}
	
	
	MIMEBodyPart* MIMEMultiPart::getBodyPart(const WString& cid, bool clone)
	{
		std::vector<MIMEBodyPart*>::iterator it;
		value_pair contentID;
		
		for (it = m_bodyParts.begin(); it != m_bodyParts.end(); it++)
		{
			contentID = (*it)->getContentID();
			if (contentID.first && contentID.second == cid)
				break;
		}
		if (it == m_bodyParts.end())
			throw MIMEException("Invalid bodyPart!");
		
		MIMEBodyPart* obj = (*it);
		
		if (obj->mimeObjType == MIMEObjType_BasicPart)
		{
			MIMEBasicPart* part = (MIMEBasicPart*) obj;
			if (clone)
				return part->clone();
			else
				return part;
		}
		else if (obj->mimeObjType == MIMEObjType_MessagePart)
		{
			MIMEMessagePart* part = (MIMEMessagePart*) obj;
			if (clone)
				return part->clone();
			else
				return part;
		}
		else if (obj->mimeObjType == MIMEObjType_MultiPart)
		{
			MIMEMultiPart* part = (MIMEMultiPart*) obj;
			if (clone)
				return part->clone();
			else
				return part;
		}
		else
			throw MIMEException("Invalid bodyPart!");
	}
	
	MIMEBodyPart* getBodyPart(const WString& cid, bool clone);
	
	
	void MIMEMultiPart::putByteStream(OutputStream& os, bool needPreamble)
	{
		if (needPreamble)
			m_needPreamble = true;
		else
			m_needPreamble = false; // in case we did not reset last pass due exception
		
		putByteStream(os);
		m_needPreamble = false; // reset after done.
	}
	

	void MIMEMultiPart::putByteStream(OutputStream& os)
	{
		int l_bpCount = m_bodyParts.size();
		if (l_bpCount == 0)
			throw MIMEException(L"MIMEMultiPart.putByteStream(). No bodyparts!");
		
		// headers first
		WString l_hdrbuf;
		WString l_boundary;
		bool l_fQBounds = false;
		
		if (m_boundary.length() > 0)
		{
			l_boundary = m_boundary;
			l_fQBounds = true;
		}
		else
			l_boundary = generateBoundary();
		
		// content-type
		l_hdrbuf.append(L"Content-Type: multipart/");
		if (m_contentSubType.first)
			l_hdrbuf.append(m_contentSubType.second);
		else
			throw MIMEException(L"putByteStream: No content-subtype.");
		
		if (m_contentTypeParams.first && !m_contentTypeParams.second.startsWith("boundary") )
		{
			l_hdrbuf.append(L"; ");
			l_hdrbuf.append(m_contentTypeParams.second);
			l_hdrbuf.append(L"; boundary=");
			if (l_fQBounds)
				l_hdrbuf.append(1,L'"');
			l_hdrbuf.append(l_boundary);
			if (l_fQBounds)
				l_hdrbuf.append(1,L'"');
			l_hdrbuf.append(L"\r\n");
		}
		else
		{
			l_hdrbuf.append(L"; boundary=");
			if (l_fQBounds)
				l_hdrbuf.append(1,L'"');
			l_hdrbuf.append(l_boundary);
			if (l_fQBounds)
				l_hdrbuf.append(1,L'"');
			l_hdrbuf.append(L"\r\n");
		}
		
		// write out the header to os
		try
		{
			// unicode to ascii conversion
			char* data = l_hdrbuf.getBytes(L"ASCII");
			ArrayJanitor<char> dataJanitor(data);
			// unicode to ascii conversion
			os.write(data,strlen(data));
		} 
		catch (Exception& e)
		{
			throw MIMEException(L"Content-Type: " + e.getMessage());
		}
		
		// contentID
		if (m_contentID.first)
		{
			l_hdrbuf = L"Content-ID: " + m_contentID.second;
			l_hdrbuf.append("\r\n");
			
			try
			{
				char* data = l_hdrbuf.getBytes(L"ASCII");
				ArrayJanitor<char> dataJanitor(data);
				// unicode to ascii conversion
				os.write(data,strlen(data));
			} 
			catch (Exception& e)
			{
				throw MIMEException(L"Content-ID: " + e.getMessage());
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
			l_hdrbuf = L"Content-Description: ";
			l_hdrbuf.append(m_contentDescription.second);
			l_hdrbuf.append(L"\r\n");
			
			try
			{
				char* data = l_hdrbuf.getBytes(L"ASCII");
				ArrayJanitor<char> dataJanitor(data);
				// unicode to ascii conversion
				os.write(data,strlen(data));
			} 
			catch (Exception& e)
			{
				throw MIMEException(L"Content-MD5: " + e.getMessage());
			}
		}
		// This is the top-level multi-part. Add content-encoding
		if (m_needPreamble == true && m_contentTransferEncoding != UNINITIALIZED)
		{
			if (m_contentTransferEncoding == BINARY || 
				m_contentTransferEncoding == E7BIT  ||
				m_contentTransferEncoding == E8BIT)
			{
				l_hdrbuf = L"Content-Transfer-Encoding: ";
				l_hdrbuf.append(m_StringEncoding[m_contentTransferEncoding]);
				l_hdrbuf.append(L"\r\n");
				
				try
				{
					char* data = l_hdrbuf.getBytes(L"ASCII");
					ArrayJanitor<char> dataJanitor(data);
					// unicode to ascii conversion
					os.write(data,strlen(data));
				} 
				catch (Exception& e)
				{
					throw MIMEException(L"Content-Encoding: " + e.getMessage());
				}
			}
		}
		
		CRLFOutputStream crlfos(os);
		
		// blank line after headers
		crlfos.write(CRLF,strlen(CRLF));
		
		if (m_preamble.first)
		{
			l_hdrbuf = m_preamble.second;
			
			try
			{
				char* data = l_hdrbuf.getBytes("ASCII");
				ArrayJanitor<char> dataJanitor(data);
				// unicode to ascii conversion
				os.write(data,strlen(data));
			} 
			catch (Exception& e)
			{
				throw MIMEException(L"Preamble: " + e.getMessage());
			}
		}
		// write the line "This is a multi-part message in MIME format
		// This needs to be done only if it is the body of the message.
		// Not when it is embedded part of another part (like another
		// multi-part or a MessagePart).
		// This is accomplished by passing a flag to putByteStream() by 
		// Message class
		else if (m_needPreamble == true && m_parsedPart==0)
		{
			WString l_preamble(L"\r\nThis is a multi-part message in MIME format\r\n");
			char* data = l_preamble.getBytes("ASCII");
			ArrayJanitor<char> dataJanitor(data);
			// unicode to ascii conversion
			os.write(data,strlen(data));
			m_needPreamble = false;
		}
		WString l_trailBoundary = "--" + l_boundary + "--\r\n";
		l_boundary = "--" + l_boundary + "\r\n";
		
		std::vector<MIMEBodyPart*>::iterator it = m_bodyParts.begin();
		
		while (it != m_bodyParts.end())
		{
			MIMEBodyPart* obj = (*it);
			if (obj->mimeObjType == MIMEObjType_BasicPart)
			{
				//if (!crlfos.crlfSeen())
				if (it!=m_bodyParts.begin())
					crlfos.write(CRLF,strlen(CRLF));
				
				{
					char* data = l_boundary.getBytes("ASCII");
					ArrayJanitor<char> dataJanitor(data);
					// unicode to ascii conversion
					crlfos.write(data,strlen(data));
				}
				MIMEBasicPart* part = (MIMEBasicPart*) obj;
				part->putByteStream(crlfos);
			}
			else if (obj->mimeObjType == MIMEObjType_MessagePart)
			{
				//if (!crlfos.crlfSeen())
				if (it!=m_bodyParts.begin())
					crlfos.write(CRLF,strlen(CRLF));
				
				{
					char* data = l_boundary.getBytes("ASCII");
					ArrayJanitor<char> dataJanitor(data);
					// unicode to ascii conversion
					crlfos.write(data,strlen(data));
				}
				MIMEMessagePart* part = (MIMEMessagePart*) obj;
				part->putByteStream(crlfos);
			}
			else if (obj->mimeObjType == MIMEObjType_MultiPart)
			{
				//if (!crlfos.crlfSeen())
				if (it!=m_bodyParts.begin())
					crlfos.write(CRLF,strlen(CRLF));
				{
					char* data = l_boundary.getBytes("ASCII");
					ArrayJanitor<char> dataJanitor(data);
					// unicode to ascii conversion
					crlfos.write(data,strlen(data));
				}
				MIMEMultiPart* part = (MIMEMultiPart*) obj;
				part->putByteStream(crlfos);
			}
			else
				throw MIMEException("putByteStream(). Invalid bodyPart!");
			it++;
		} // end for
		//if (!crlfos.crlfSeen())
		crlfos.write(CRLF,strlen(CRLF));
		
		{
			char* data = l_trailBoundary.getBytes("ASCII");
			ArrayJanitor<char> dataJanitor(data);
			// unicode to ascii conversion
			os.write(data,strlen(data));
		}
}

void MIMEMultiPart::deleteBodyPart(int index)
{
	if (index > m_bodyParts.size())
		throw MIMEException("deleteBodyParts().Index out of range: " + Integer::toString(index));
	
	int i;
	std::vector<MIMEBodyPart*>::iterator it;
	
	for (i=0,it = m_bodyParts.begin();i <= index && it != m_bodyParts.end();
	i++,it++)
	{
		if (i == index)
		{
			delete (*it);
			m_bodyParts.erase(it);
			break;
		}
	}
}

int MIMEMultiPart::addBodyPart(const WString& filename, int encoding)
{
	MIMEBasicPart*   l_filePart;
	FileInputStream* l_fis;
	FileMIMEType     l_fmt;
	
	if ((encoding != -1) && (encoding < MIMEBodyPart::BASE64 || encoding > MIMEBodyPart::E8BIT))
		throw MIMEException("Invalid MIME Encoding:" + Integer::toString(encoding));
	
	l_fis      = new FileInputStream(filename);
	l_fmt      = URLConnection::getFileNameMap()->getContentTypeFor(filename);
	l_filePart = new MIMEBasicPart(l_fmt.content_type);
	l_filePart->setContentSubType(l_fmt.content_subtype);
	

	if (l_fmt.content_params.length())
		l_filePart->setContentTypeParams(l_fmt.content_params);
	
	if (encoding == -1)
		l_filePart->setContentEncoding(l_fmt.mime_encoding);
	else
		l_filePart->setContentEncoding(encoding);
	
	if (l_fmt.content_type == MIMEBasicPart::TEXT)
		l_filePart->setContentDisposition(MIMEBodyPart::INLINE);
	else
	{
		l_filePart->setContentDisposition(MIMEBodyPart::ATTACHMENT);
		l_filePart->setContentDispParams(WString("filename=")+l_fmt.file_shortname);
	}
	
	// set body-data of this part
	l_filePart->setBodyData(l_fis);
	
	// add this part to multi-part
	return addBodyPart(l_filePart, false);
}

int MIMEMultiPart::addBodyPart(MIMEBodyPart* part, bool clone)
{
	if (part == NULL)
		throw MIMEException("addBodyPart() : NULL part passed!");
	
	if (part->mimeObjType == MIMEObjType_BasicPart ||
		part->mimeObjType == MIMEObjType_MultiPart ||
		part->mimeObjType == MIMEObjType_MessagePart)		
	{
		MIMEBodyPart* l_part = (clone ? part->clone() : part);
		m_bodyParts.push_back(l_part);
		return m_bodyParts.size()-1; // RP 050404 added the -1, since the index is zero based
	}
	else
		throw MIMEException("addBodyPart() : Invalid part");
}

void MIMEMultiPart::setContentEncoding(int encoding)
{
	if (encoding == BINARY || encoding == E7BIT || encoding == E8BIT)
		m_contentTransferEncoding = encoding;
}

MIMEBodyPart::value_pair MIMEMultiPart::getPreamble()
{
	return m_preamble;
}

void MIMEMultiPart::setPreamble(const WString& preamble)
{
	m_preamble.first  = true;
	m_preamble.second = preamble;
}

void MIMEMultiPart::addPreamble(char* preamble, int len)
{
	m_preamble.first  = true;
	m_preamble.second.append(preamble,len);
}

void MIMEMultiPart::addPreamble(char* preamble)
{
	m_preamble.first  = true;
	m_preamble.second.append(preamble);
}

WString MIMEMultiPart::generateBoundary()
{
	Random l_rand;
	
	JDFInt64 l_numboundary = l_rand.nextLong();
	WString l_boundary = WString("-----") +
		Integer64::toString(l_numboundary,16);
	return (l_boundary);
}

MIMEBodyPart* MIMEMultiPart::clone()
{
	return new MIMEMultiPart(*this);
}

} // namespace JDF
