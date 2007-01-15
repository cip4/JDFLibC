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
#include <jdf/mime/FileMIMEType.h>
#include <jdf/mime/FileNameMap.h>
#include <jdf/mime/MIMEBasicPart.h>
#include <jdf/mime/MIMEMessage.h>
#include <jdf/mime/MIMEMessagePart.h>
#include <jdf/mime/MIMEMultiPart.h>

#include <jdf/net/URLConnection.h>
#include <jdf/net/URI.h>
#include <jdf/io/FileInputStream.h>
#include <jdf/io/FileOutputStream.h>
#include <jdf/io/File.h>

#include <jdf/lang/Exception.h>
#include <jdf/lang/Integer.h>
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
	
	const int MIMEMessage::BASICPART     = 0;
	const int MIMEMessage::MULTIPART     = 1;
	const int MIMEMessage::MESSAGEPART   = 2;
	const int MIMEMessage::UNINITIALIZED = -1;
	
	MIMEMessage::MIMEMessage()
	{
		m_contentTransferEncoding  = UNINITIALIZED;
		m_bodyType                 = UNINITIALIZED;
		m_parsedPart               = false; 
		m_fplaceTwo                = false;
		m_theBody                  = NULL;
		mimeObjType                = MIMEObjType_Message;
	}
	
	MIMEMessage::MIMEMessage(const std::vector<MIMEHeader>& headers)
	{
		m_contentTransferEncoding  = UNINITIALIZED;
		m_bodyType                 = UNINITIALIZED;
		m_parsedPart               = false; 
		m_fplaceTwo                = false;
		m_theBody                  = NULL;
		mimeObjType                = MIMEObjType_Message;
		
		std::vector<MIMEHeader>::const_iterator it = headers.begin();
		
		while (it != headers.end())
		{
			try
			{
				setHeader((*it).getName(), (*it).getValue());
			}
			catch (Exception& e)
			{
				throw MIMEException(e.getMessage());
			}
		}
	}
	
	MIMEMessage::~MIMEMessage()
	{
		delete m_theBody;
	}
	
	MIMEMessage::MIMEMessage(InputStream* textIS, WString filename, int encoding)
	{
		MIMEBasicPart*   l_txtPart;
		MIMEBasicPart*   l_filePart;
		FileInputStream* l_fis;
		FileMIMEType     l_fmt;
		
		m_contentTransferEncoding  = UNINITIALIZED;
		m_bodyType                 = UNINITIALIZED;
		m_parsedPart               = false; 
		m_fplaceTwo                = false;
		m_theBody                  = NULL;
		mimeObjType                = MIMEObjType_Message;
		
		if (textIS == NULL && filename == JDFStrL(""))
			throw MIMEException("Invalid empty filename:" + filename);
		
		if ((encoding != -1) && (encoding < MIMEBodyPart::BASE64 || encoding > MIMEBodyPart::E8BIT))
			throw MIMEException("Invalid MIME encoding: " + Integer::toString(encoding));
		
		if (textIS != NULL && filename !=JDFStrL(""))
		{
			MIMEMultiPart* l_mmp  = new MIMEMultiPart(textIS,filename,encoding);
			this->setBody(l_mmp,false);
		}
		else if(textIS != NULL) // text part only
		{
			l_txtPart = new MIMEBasicPart(MIMEBasicPart::TEXT);
			l_txtPart->setContentSubType("plain");
			l_txtPart->setContentTypeParams("charset=us-ascii");
			l_txtPart->setContentEncoding(MIMEBodyPart::E7BIT);
			l_txtPart->setBodyData(textIS);
			this->setBody(l_txtPart,false);
		}
		else if (filename != "") // file part only
		{
			l_fis = new FileInputStream(filename);
			
			// The file-part
			l_fmt = URLConnection::getFileNameMap()->getContentTypeFor(filename);
			
			// TODO 
			// check if l_fmt has been successfull
			// something like if (l_fmt)
			l_filePart = new MIMEBasicPart(l_fmt.content_type);
			l_filePart->setContentSubType(l_fmt.content_subtype);
			if (l_fmt.content_params != "")
				l_filePart->setContentTypeParams(l_fmt.content_params);
			else
				l_filePart->setContentTypeParams("name=" + filename);
			
			if (encoding == -1)
				l_filePart->setContentEncoding(l_fmt.mime_encoding);
			else
				l_filePart->setContentEncoding(encoding);
			
			if (l_fmt.content_type == MIMEBasicPart::TEXT)
			{
			}
			else
			{
				l_filePart->setContentDispParams("filename=" + l_fmt.file_shortname);
				l_filePart->setContentDescription(l_fmt.file_shortname);
			}
			l_filePart->setBodyData(l_fis);
			this->setBody(l_filePart,false);
		} // filePart
	} // MIMEMessage
	
	MIMEMessage::MIMEMessage(const MIMEMessage& m)
	{
		m_contentTransferEncoding  = UNINITIALIZED;
		m_bodyType                 = UNINITIALIZED;
		m_parsedPart               = false; 
		m_fplaceTwo                = false;
		m_theBody                  = NULL;
		mimeObjType                = MIMEObjType_Message;
		
		m_822HeadersTable          = m.m_822HeadersTable;
		m_repeatHdrs               = m.m_repeatHdrs;
		
		if (m.m_theBody != NULL)
		{
			m_theBody = m.m_theBody->clone();
		}
	}
	
	void MIMEMessage::setHeader(const WString& name, const WString& value)
	{
		WString l_hashKey = name.toUpperCase();
		m_822HeadersTable.insert(hmap<WString,MIMEHeader,ElfHash>::value_type(l_hashKey,MIMEHeader(name,value)) );
	}
	
	void MIMEMessage::addHeader(const WString& name, const WString& value)
	{
		if (m_fplaceTwo == true)
		{
			addHeader2(name,value);
			return;
		}
		WString l_hashkey = name.toUpperCase();
		
		hmap<WString,MIMEHeader,ElfHash>::iterator it = m_822HeadersTable.find(l_hashkey);
		if (it == m_822HeadersTable.end())
		{
			// add a new one
			m_822HeadersTable.insert(hmap<WString,MIMEHeader,ElfHash>::value_type(l_hashkey,MIMEHeader(name,value)) );
		}
		else
		{
			WString oldValue = (*it).second.getValue();
			oldValue.append(value);
			m_822HeadersTable.erase(l_hashkey);
			m_822HeadersTable.insert(hmap<WString,MIMEHeader,ElfHash>::value_type(l_hashkey,MIMEHeader(name,oldValue)) );
		}
	}
	
	void MIMEMessage::addHeader2(const WString& name, const WString& value)
	{
		MIMEHeader l_oldHdr, l_newHdr;
		int idx = m_repeatHdrs.size()-1;
		
		if (idx>=0)
			l_oldHdr = m_repeatHdrs[idx];
		
		if (!(l_oldHdr.getName().equalsIgnoreCase(name)))
		{
			m_repeatHdrs.push_back(MIMEHeader(name,value)); 
			m_fplaceTwo = true;
		}
		else
		{
			//TODO check this rbegin
			m_repeatHdrs.pop_back();
			WString oldValue = l_oldHdr.getValue();
			oldValue.append(value);
			m_repeatHdrs.push_back(MIMEHeader(name,oldValue)); 
			m_fplaceTwo = true;
		}
	}
	
	// add a potential repeat header to the message
	void MIMEMessage::addRHeader(const WString& name, const WString& value)
	{
		WString l_hashkey = name.toUpperCase();
		
		hmap<WString,MIMEHeader,ElfHash>::iterator it = m_822HeadersTable.find(l_hashkey);
		if (it == m_822HeadersTable.end())
		{
			// add a new one
			m_822HeadersTable.insert(hmap<WString,MIMEHeader,ElfHash>::value_type(l_hashkey,MIMEHeader(name,value)) );
			m_fplaceTwo = false;
		}
		else
		{
			// It's a repeat header
			m_repeatHdrs.push_back(MIMEHeader(name,value)); 
			m_fplaceTwo = true;
		}		
	}
	
	MIMEMessage::value_pair MIMEMessage::getHeader(const WString& name)
	{
		WString l_hashkey = name.toUpperCase();
		
		hmap<WString,MIMEHeader,ElfHash>::iterator it = m_822HeadersTable.find(l_hashkey);
		if (it == m_822HeadersTable.end())
		{
			return value_pair(false,"");
		}
		else
		{
			return value_pair(true,(*it).second.getValue());
		}		
	}
	
	void MIMEMessage::deleteHeader(const WString& name)
	{
		WString l_hashkey = name.toUpperCase();
		
		hmap<WString,MIMEHeader,ElfHash>::iterator it = m_822HeadersTable.find(l_hashkey);
		
		// keys are always lowercase
		if (it !=  m_822HeadersTable.end())
		{
			m_822HeadersTable.erase(it);
		}
	}
	
	std::vector<MIMEHeader> MIMEMessage::getAllHeaders()
	{
		std::vector<MIMEHeader> hdrs;
		
		hmap<WString,MIMEHeader,ElfHash>::iterator it = m_822HeadersTable.begin();
		while (it != m_822HeadersTable.end())
		{
			hdrs.push_back((*it).second);
			it++;
		}
		std::vector<MIMEHeader>::iterator itr = m_repeatHdrs.begin();
		while (itr != m_repeatHdrs.end())
		{
			hdrs.push_back((*itr));
			itr++;
		}
		return hdrs;
	}
	
	int MIMEMessage::getBodyType()
	{
		if (m_bodyType != UNINITIALIZED)
			return m_bodyType;
		else
			throw MIMEException("getBodyType(): No body present!");
	}
	
	MIMEMessage::value_pair MIMEMessage::getContentType()
	{
		if (m_theBody == NULL)
			throw MIMEException("getContentType(): No body present!");
		
		return m_theBody->getContentType();
	}
	
	MIMEMessage::value_pair MIMEMessage::getContentSubType()
	{
		if (m_theBody == NULL)
			throw MIMEException("getContentType(): No body present!");
		
		return m_theBody->getContentSubType();
	}
	
	MIMEMessage::value_pair MIMEMessage::getContentTypeParams()
	{
		if (m_theBody == NULL)
			throw MIMEException("getContentType(): No body present!");
		
		return m_theBody->getContentTypeParams();
	}
	
	MIMEBodyPart* MIMEMessage::getBody(bool clone)
	{
		if (m_theBody == NULL)
			throw MIMEException("getBody(): No body present!");
		
		if (clone == true)
			return m_theBody->clone();
		else 
			return m_theBody;
	}
	
	MIMEBodyPart* MIMEMessage::getBody()
	{
		return getBody(true);
	}
	
	void MIMEMessage::deleteBody()
	{
		if (m_theBody != NULL)
		{
			delete m_theBody;
			m_theBody = NULL;
			m_bodyType = UNINITIALIZED;
		}
	}
	
	void MIMEMessage::setBody(MIMEBodyPart* part,bool clone)
	{
		if (part == NULL)
			throw MIMEException("setBody(): NULL part passed!");
		
		if (part->mimeObjType == MIMEComponent::MIMEObjType_BasicPart)
		{
			setBodyPart((MIMEBasicPart* )part, clone);
		}
		else if (part->mimeObjType == MIMEComponent::MIMEObjType_MessagePart)
		{
			setBodyPart((MIMEMessagePart* )part, clone);
		}
		else if (part->mimeObjType == MIMEComponent::MIMEObjType_MultiPart)
		{
			setBodyPart((MIMEMultiPart* )part, clone);
		}
		else
			throw MIMEException("setBody(): Invalid part ");
	}
	
	void MIMEMessage::setBodyPart(MIMEBasicPart* part,bool clone)
	{
		MIMEBasicPart* l_part = NULL;
		
		if (m_theBody != NULL)
			throw MIMEException("setBody(): Body already set!");
		
		if (part == NULL)
			throw MIMEException("setBody(): NULL part passed!");
		
		
		l_part = (clone ? (MIMEBasicPart*)part->clone() : part);
		
		m_theBody = l_part;
		m_bodyType = BASICPART;
	}
	
	void MIMEMessage::setBodyPart(MIMEMultiPart* part,bool clone)
	{
		MIMEMultiPart* l_part = NULL;
		
		if (m_theBody != NULL)
			throw MIMEException("setBody(): Body already set!");
		
		if (part == NULL)
			throw MIMEException("setBody(): NULL part passed!");
		
		
		l_part = (clone ? (MIMEMultiPart*)part->clone() : part);
		
		m_theBody = l_part;
		m_bodyType = MULTIPART;
	}
	
	void MIMEMessage::setBodyPart(MIMEMessagePart* part,bool clone)
	{
		MIMEMessagePart* l_part = NULL;
		
		if (m_theBody != NULL)
			throw MIMEException("setBody(): Body already set!");
		
		if (part == NULL)
			throw MIMEException("setBody(): NULL part passed!");
		
		
		l_part = (clone ? (MIMEMessagePart*) part->clone() : part);
		
		m_theBody = l_part;
		m_bodyType = MESSAGEPART;
	}
	
	void MIMEMessage::putByteStream(const WString& fullfilename)
	{
		FileOutputStream fos(fullfilename);
		putByteStream(fos);
	}
	
	void MIMEMessage::putByteStream(OutputStream& os)
	{
		// don't write content-type here. The Body will do that. That is,
		// if it were a multi-part, it would do that.If it were a basic-part, it
		// would do that etc.
		
		if (m_theBody == NULL)
			throw MIMEException("MIMEMessage.putByteStream(): No Body()!");
		
		// write out all the headers.
		
		bool l_fMIMEVersionWritten = false;
		
		std::vector<MIMEHeader> hdrs = getAllHeaders();	
		std::vector<MIMEHeader>::iterator it;
		
		for (it = hdrs.begin(); it != hdrs.end(); it++)
		{
			try
			{
				if (l_fMIMEVersionWritten == false &&
					( (*it).getName().equalsIgnoreCase("MIME-Version")))
					l_fMIMEVersionWritten = true;
				WString line = (*it).getLine();
				char* data = line.getBytes("ASCII");
				ArrayJanitor<char> dataJanitor(data);
				// unicode to ascii conversion
				os.write(data,strlen(data));
			} 
			catch (IOException& e)
			{
				throw MIMEException((*it).getLine() + "> " + e.getMessage());
			}
		} // for
		
		// Now put the MIME Version.
		
		if (!l_fMIMEVersionWritten && m_parsedPart == 0)
		{
			std::string line("MIME-Version: 1.0\r\n");
			os.write((char*)line.c_str(),line.length());
		}
		/// call theBody.putByteStream
		// TODO check body, must be one of BASIC,MESSAGE,MULTI
		
		m_theBody->putByteStream(os);
	}
	
	MIMEMessage* MIMEMessage::clone()const
	{
		return new MIMEMessage(*this);
	}
	
	/////////////////////////////////////////////////////////////////////////
	
    MIMEMessage* MIMEMessage::Write2URL(const WString& strURL) 
    {
        try
        {
            JDF::URI uri(strURL);
			
			WString protocol=uri.getScheme();
			if(protocol.compareToIgnoreCase(L"File")==0){
				
				// workaround for buggy url file handler
				WString path=JDF::File(uri).getAbsolutePath();
				if((path[0]==L'/')&&(path[2]==L':'))
					path=path.substr(1,path.npos);
				
				putByteStream(path);
				// a file returns an empty response
				return 0;
			}
			
            JDF::Janitor<JDF::URLConnection> pURLConnection(uri.toURL().openConnection());
			
            pURLConnection->setDoOutput(true);
            pURLConnection->setRequestProperty(L"Connection",   L"close");
            pURLConnection->setRequestProperty(L"Content-Type", L"mime");
			
            putByteStream(pURLConnection->getOutputStream());
			InputStream* inStr=&(pURLConnection->getInputStream());
            return new MIMEMessage(inStr,WString::emptyStr,-1);
        }
        catch (const XMLException&)
        {
			throw JDF::Exception(L"MIMEMessage::Write2URL: error writing URL "+strURL);
        }
        catch (const JDF::Exception&)
        {
			throw JDF::Exception(L"MIMEMessage::Write2URL: error writing URL "+strURL);
		}
		
        return 0;
    }
	
	
	
} // namespace JDF
