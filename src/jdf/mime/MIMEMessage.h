/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2007 The International Cooperation for the Integration of 
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

/*******************************************************************************
* 
* Description:
*
*
******************************************************************************/

#ifndef I_JDF_MIMEMESSAGE_H
#define I_JDF_MIMEMESSAGE_H

/******************************************************************************
*	Includes
******************************************************************************/ 

#include "MIMEComponent.h"

#include "MIMEHeader.h"

#include <jdf/util/hmap.h>
#include <jdf/util/hashfun.h>

#include <utility>


namespace JDF
{
	
/******************************************************************************
*	Forward declarations
	******************************************************************************/ 
	class MIMEBasicPart;
	class MIMEBodyPart;
	class MIMEMessagePart;
	class MIMEMultiPart;
	class InputStream;
	class OutputStream;
	class MIMEParser;
	
	/******************************************************************************
	*	Defines and constants
	******************************************************************************/ 
	
	
	/******************************************************************************
	*	Typedefs
	******************************************************************************/ 
	
	
	/******************************************************************************
	*	Classes
	******************************************************************************/ 
	
	/**
	* The MIMEMessage class represents the MIME message.
	* A MIME Message is made up of a set of headers and message content.
	* The message content itself comprises one of the MIMEBody types:
	* MIMEBasicPart, MIMEMultiPart and MIMEMessagePart
	* @ingroup mime
	* @nosubgrouping
	*/
	
	class JDFTOOLS_EXPORT MIMEMessage : public MIMEComponent
	{
	public:
		
		typedef std::pair<bool,WString> value_pair;
		
		/**
		* BodyPart is a MIMEBasicPart object.
		*/
		static const int BASICPART;
		
		/** 
		* BodyPart is a MIMEMultiPart object.
		*/
		static const int MULTIPART;
		
		/** 
		* BodyPart is a MIMEMessagePart object.
		*/
		static const int MESSAGEPART;
		
		/** 
		* @name Constructors
		*/
		/*@{*/
		/**
		* Default constructor for the MIMEMessage class.
		*/
		MIMEMessage();
		
		/**
		* Constructs a MIMEMessage object given a set of RFC822 headers.
		* @param headers List of rfc822 headers to set in the message.
		* @exception MIMEException If the headers are malformed.
		*/
		MIMEMessage(const std::vector<MIMEHeader>& headers);
		
		/**
		* Constructs a (multi-part) MIMEMessage with given text and file.
		* If filename parameter is empty, builds a text message with textIS. 
		* Encoding will be E7BIT.
		* If textIS is NULL, builds a message with only the filename file as an attachment.
		* if both textIS and filename are NULL<, an exception is thrown.
		* @param textIS InputStream to text that becomes text part of the message. Can be NULL.
		* @param filename Full name of file that becomes a part of the message. Can be empty.
		* @param encoding  Encoding for the file attachment. To pick default value pass -1.
		* @see MIMEBodyPart#BASE64
		* @see MIMEBodyPart#QP
		* @see MIMEBodyPart#BINARY
		* @see MIMEBodyPart#E7BIT
		* @see MIMEBodyPart#E8BIT
		* @exception MIMEException If both textIS and filename are NULL or encoding is invalid.
		* @exception FileNotFoundException if filename does not exist.
		* @exception IOException On IO Errors on filename or textIS
		*/
		MIMEMessage(InputStream* textIS, WString filename, int encoding);
		
		/**
		* Copy Constructor
		* Takes a copy of a MIMEMessage. 
		*/
		MIMEMessage(const MIMEMessage& m);
		
		/*@}*/
		/**
		* Destructs this message
		* Deletes the body container
		*/
		~MIMEMessage();
		
		/**
		* Sets any RFC-822 headers including x-headers. Overwrites the existing
		* value if header exists already.
		* @param name Name of the header field.
		* @param value Value of the header field to be added.
		*/
		void setHeader(const WString& name, const WString& value);
		
		/**
		* Appends the value to an existing RC822 header. Creates new header if
		* one does not exist already.
		* @param name Name of the header field.
		* @param value Value of the header field to be added.
		*/
		void addHeader(const WString& name, const WString& value);
		
		/**
		* Returns the value of the requested header. The first field is set to
		* false if the header is not present.
		* @param name Name of the header 
		*/
		value_pair getHeader(const WString& name);
		
		/**
		* Deletes the requested header. Ignores if the header specified does not 
		* exist.
		* @param name Name of the header field to delete.
		*/
		void deleteHeader(const WString& name);
		
		/**
		* Returns all the RFC-822 headers in the Message as an array of MIMEHeader objects
		* Content-Type is not returned by this Method, as separate methods to get
		* Content primary type, sub-type and parameters exist.
		* @see MIMEMessage#getContentType()
		* @see MIMEMessage#getContentSubType()
		* @see MIMEMessage#getContentTypeParams()
		*/
		std::vector<MIMEHeader> getAllHeaders();
		
		/**
		* Returns the type of the body of the Message.
		* @exception MIMEException If no Body exists for the message.
		* @see MIMEMessage#BASICPART
		* @see MIMEMessage#MULTIPART
		* @see MIMEMessage#MESSAGEPART
		*/
		int getBodyType();
		
		/**
		* Returns the content-type of the Message.
		* The content-type returned is the MIME content-type.
		* @exception MIMEException if no Body exists.
		*/
		
		value_pair getContentType();
		
		/**
		* Returns Content SubType of the Message.
		* @return value_pair with first set to true and second containing the Content-SubType or first set to
		* false if Content-SubType cannot be determined.
		* @exception MIMEException If no Body exists for the message.
		*/
		value_pair getContentSubType();
		
		/**
		* Returns Content-Type Parameters of the Message..
		* @return value_pair with first set to true and second containing the Content-Type Parameters or first set to
		* false if no parameters exist.
		* @exception MIMEException If no Body exists for the message.
		*/
		value_pair getContentTypeParams();
		
		/**
		* Returns an object of corresponding MIMEBodyPart type that is 
		* the body of this Message.
		* @param clone Whether to return a reference to the internal object or a cloned copy; if true; cloned copy; 
		* if false reference to the object
		* @exception MIMEException If no Body exists.
		* @see MIMEBasicPart
		* @see MIMEMultiPart
		* @see MIMEMessagePart
		*/
		MIMEBodyPart* getBody(bool clone);
		
		/**
		* Deletes the body of the Message. Has no effect if no body is present.
		*/
		void deleteBody();
		
		/**
		* Sets the MIMEBodyPart as Body of this Message. This part must already
		* be constructed and fully set-up. Sets the content-type of the message
		* based on the type of the part being added. This MIMEBodyPart must be 
		* an object of one of the three concrete classes: MIMEBasicPart, MIMEMultiPart and
		* MIMEMessagePart.
		* @param part BodyPart to add
		* @param clone If false stores reference to passed object instead of cloning a copy.
		* @exception MIMEException If body is already set (or) part is NULL, or if part
		* is not an object of one of the three concrete classes:
		* MIMEBasicPart, MIMEMultiPart, or MIMEMessagePart.
		* @see MIMEBasicPart
		* @see MIMEMultiPart
		* @see MIMEMessagePart
		*/
		void setBody(MIMEBodyPart* part,bool clone=true);
		
		/**
		* Outputs a byte-stream for this Message in MIME format with transfer encoding
		* applied to all bodyParts as applicable.
		* @param fullfilename Filename, including full path to write the byte-stream to.
		* @exception IOException If an IO error occurs.
		* @exception MIMEException If any required fields in the bodyPart are not set-up.
		*/
		void putByteStream(const WString& fullfilename);
		
		/**
		* Outputs a byte-stream for this Message in MIME format with transfer encoding
		* applied to all bodyParts as applicable.
		* @param os OutputStream to write to
		* @exception IOException If an IO error occurs.
		* @exception MIMEException If an error occurs during encoding.
		*/
		void putByteStream(OutputStream& os);
		
		/**
        * This method sends the contents of this MIMEMessage to the URL <code>strURL</code> and
        * receives the response in the returned MIMEMessage*.
		*
        * @param  WString strURL				the URL to write to
        * @return MIMEMessage* docResponse		the response received from URL. A Null document if no response was received
		*/
	    MIMEMessage* Write2URL(const WString& strURL);
		/**
		* Clones an instance of this MIMEMessage object.
		*/		
		MIMEMessage* clone()const;
		
protected:
	
	void addRHeader(const WString& name, const WString& value);
	
	/** 
	* Returns an object of corresponding MIME BodyPart type that is the
	* the body of this Message.
	* @exception MIMEException If no Body exists.
	*/
	MIMEBodyPart* getBody();
	
	/**
	* Sets the MIMEBasicPart as Body of this Message. This part must already
	* be constructed and fully set-up. Sets the content-type of the message
	* based on the type of the part being added.
	* @param part BodyPart to add
	* @param clone If false stores reference to passed object instead of cloning a copy.
	* @exception MIMEException If body is already set (or) part is NULL.
	* @see MIMEBasicPart
	*/
	void setBodyPart(MIMEBasicPart* part,bool clone);
	
	/**
	* Sets the MIMEMultiPart as Body of this Message. This part must already
	* be constructed and fully set-up. Sets the content-type of the message
	* based on the type of the part being added.
	* @param part MultiPart to add
	* @param clone If false stores reference to passed object instead of cloning a copy.
	* @exception MIMEException If body is already set (or) part is NULL.
	* @see MIMEMultiPart
	*/
	void setBodyPart(MIMEMultiPart* part,bool clone);
	
	/**
	* Sets the MIMEMessagePart as Body of this Message. This part must already
	* be constructed and fully set-up. Sets the content-type of the message
	* based on the type of the part being added.
	* @param part MessagePart to add
	* @param clone If false stores reference to passed object instead of cloning a copy.
	* @exception MIMEException If body is already set (or) part is NULL.
	* @see MIMEMessagePart
	*/
	void setBodyPart(MIMEMessagePart* part,bool clone);
	
private:
	
	void addHeader2(const WString& name, const WString& value);
	
	static const int UNINITIALIZED;
	
	int m_contentTransferEncoding;
	int m_parsedPart;
	bool m_fplaceTwo;
	
	// The key to the hashTable below is the name of the header field.
	// To make sure we handle case differences in the header-name, we
	// must convert the header name to lower-case always prior to the
	// hash look-up. The entries added to the hash table are objects of class
	// MIMEHeader
	
#pragma warning(push)
#pragma warning(disable: 4251)
	hmap<WString,MIMEHeader,ElfHash> m_822HeadersTable;
	std::vector<MIMEHeader>	m_repeatHdrs;
#pragma warning(pop)
	
	// Body
	
	int m_bodyType; // one of BASICPART, MULTIPART, MESSAGEPART
	MIMEBodyPart* m_theBody; // must be one of BASICPART, MULTIPART, MESSAGEPART
	
	friend class MIMEParser;
};


/******************************************************************************
*	Prototypes
******************************************************************************/ 


/******************************************************************************
*	Implementation
******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_MIMEMESSAGE_H */
