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

 /*******************************************************************************
 * 
 * Description:
 *
 *
 ******************************************************************************/

#ifndef I_JDF_MIMEPARSER_H
#define I_JDF_MIMEPARSER_H


/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <jdf/lang/ByteBuffer.h>
#include <jdf/io/OutputStream.h>
#include <jdf/mime/MIMEResourceFactory.h>

#include <vector>


namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 
	class MIMEMessage;
	class MIMEComponent;
	class MIMEBodyPart;
	class MIMEBasicPart;
	class MIMEMessagePart;
	class MIMEMultiPart;
	class InputStream;
	class WString;

/******************************************************************************
 *	Defines and constants
 ******************************************************************************/ 


/******************************************************************************
 *	Typedefs
 ******************************************************************************/ 


/******************************************************************************
 *	Classes
 ******************************************************************************/ 

class MIMEByteBuffer : public ByteBuffer
{
public:

	void setSize(int size) { mSize = size;}
};

class LineBufferOutputStream : public OutputStream
{
public:

	LineBufferOutputStream(OutputStream* os);
	~LineBufferOutputStream() { 	delete mOs; delete mRealOs; }

	void flush();
	void write(char* b, int blen);
	void write(char* b, int blen, int off, int len);
	void write(int b);
	void removeLast2Bytes();
	void close();

private:

	OutputStream* mOs;
	OutputStream* mRealOs;
	char last2Bytes[2];
	int nrBytes;
};
/**
 * The MIMEParser class represents a MIME Parser.
 * This generic parser takes an email message encoded in 
 * MIME and decodes it into a set of usable structures.
 * @ingroup mime
 * @nosubgrouping
 */
class JDFTOOLS_EXPORT MIMEParser
{
public:

	static const int MIME_INFO_CONTENT_TYPE;
	static const int MIME_INFO_CONTENT_SUBTYPE;
	static const int MIME_INFO_CONTENT_TRANSFER_ENCODING;
	static const int MIME_INFO_CONTENT_DISPOSITION;
	static const int MIME_INFO_CONTENT_ID;
	static const int MIME_INFO_CONTENT_DESCRIPTION;
	static const int MIME_INFO_CONTENT_BASE;
	static const int MIME_INFO_MIME_VERSION;

	static const int BUFFER_SIZE;
	static const int SUBTYPE_RFC822;
	static const int SUBTYPE_EXTERNAL_BODY;

	static const char* mb_MultiPart;
	static const char* mb_MessagePart;
	static const char* mb_TextPart;
	static const char* mb_AudioPart;
	static const char* mb_VideoPart;
	static const char* mb_ImagePart;
	static const char* mb_ApplPart;
	static const char* CRLF;
	
/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * General constructor
	 * @param m User's MimeMessage object. Will populate data into this object.
	 */
	MIMEParser(MIMEResourceFactory* mFactory = NULL, MIMEMessage* m = NULL);

/*@}*/

	~MIMEParser();

	/** 
	 * Parses an entire message from an input stream.
	 * @param input User's input stream; source of message to parse.
	 * @return New parsed MIMEMessage object.
	 */
	MIMEMessage* parseEntireMessage(InputStream& input);



protected:

	/**
	 * General constructor method
	 * @param m User's MimeMessage object. Will populate data into this object.
	 */
	void init(MIMEMessage* m);

	void reInit(MIMEMessage* m);
	/**
	 * Begin parse/reset parser
	 * Only used for callbacks
	 */
	void beginParse();

	void endParse();

	/**
	 * Parse incoming data. Only used for callbacks
	 *
	 * @param input User's inputstream. Data will be read off this inputstream.
	 */
	void parse(InputStream& input);

	/** 
	 * Parse user inputstream and return a populated data structure
	 * @param input User's inputstream
	 * @param nMessageType <PRE> 
	 *          MIME_CONTENT_PARSE_ALL   if you want to parse the entire message
	 *          MIMEMessage::BASICPART   for basicPart
	 *          MIMEMessage::MULTIPART   for multiPart
	 *          MIMEMessage::MESSAGEPART for messagePart</PRE>
	 * @return <PRE>MIMEMEssage object if nMessageType = MIME_CONTENT_PARSE_ALL
	 *MIMEBASICPART object if nMessageType = MIMEMessage::BASICPART;
	 *MIMEMULTIPART object if nMessageType = MIMEMessage::MULTIPART;
	 *MIMEMESSAGEPART object if nMessageType = MIMEMessage::MESSAGEPART;</PRE>
	 */

	MIMEMessage* parseMimeMessage(InputStream& input, int nMessageType);
	
	
private:

	/**
	 * Helper class
	 * Used internally by parser to track information
	 */
	class mimeInfo
	{
	public:
		int m_type;
		std::string m_name;
		std::string m_value;
		std::vector<mimeInfo> m_param;

		mimeInfo(int type1, const char* name, const char* value)
		{
			m_type = type1;
			m_name = name;
			m_value = value;
		}
		mimeInfo()
		{
			m_type = 0;
		}
		void clear()
		{
			m_type=0;
			m_name ="";
			m_value="";
			m_param.clear();
		}
		mimeInfo(int type1, char* name)
		{
			m_type = type1;
			m_name = name;
		}
	};


    /**
     * Parse one line of data
     *
     * @param  s input line
     * @param len length of line
     * @param type line type for the previous line<PRE>
     *   MIME_HEADER     header line
     *   MIME_INFO       mime info line</PRE>
     *
     * @return line type for current line
     * @exception MIMEException
     */
	int parseLine(char* s, int len, int type, bool lastLine);

	/**
	 * Save decoded data
	 * @param byteBuffer data buffer
	 * @param len number of bytes in the data buffer to save
	 * @param mimeBasicPart save data to this mimeBasicPart
	 * @exception MIMEException
	 */
	void saveBodyData(ByteBuffer* buf, int len, MIMEBasicPart* mimeBasicPart);
	void saveBodyData(InputStream* in, MIMEBasicPart* mimeBasicPart);

	/**
	 * Decode Message Data
	 */
	void decodeDataBuffer();

	int getCurrentParentType();

	void appToLastHdrOnQueue(const std::string& value);

	//add cont * headers to the bodypart. used by MessagePart only at this point.
	void addContHeader (MIMEBodyPart* bp, mimeInfo mi);

    /**
     * add header
     *
     * @param name header name
     * @param value header value
     * @return none
     * @exception MIMEException
     */
	void addHeader( const std::string& name, const std::string& value, bool addToQueue );

    /**
     * fill in data fields from pMimeinfo
     *
     * @param  mi mimeInfo structure
     * @return none
     * @exception MIMEException
     */
	void setData( const mimeInfo& mi );

    /**
     * Parse a line into name, value, parameters and store it in a mimeInfo structure
     *
     * @param  mi mimeInfo structure to be parsed
     * @return none
     * @exception MIMEException
     */
	void parseMimeInfo( mimeInfo& mi );

    /**
     * create new message structure based on content type
     * the input string will be parsed to determine the content type
     *
     * @param s input line
     * @return none
     * @exception MIMEException
     */
	void newMessageStructure(const std::string& s );

	const char* getBytecontType(int nMessageType, int basicPartcontType);

    /**
     * add a new message ( part ) to a multipart message, mimeMessage of messagePart
     *
     * @param  message input message
     * @param  nMessageType message type
     * @return none
     * @exception MIMEException
     */
	void addMessage( MIMEComponent* message, int nMessageType );

    /**
     * Set current mesage
     *
     * @param  message input message
     * @param  nMessageType message type
     * @return MIME_OK if successful, an error code otherwise
     * @exception none
     */
	int setCurrentMessage( MIMEComponent* message, int nMessageType );

    /**
     * Determine if line is a boundary
     *
     * @param  s input string
     * @param len size of input string
     * @return : START_BOUNDARY if it's a start boundary, END_BOUNDARY if it's a end boundary, NOT_A_BOUNDARY if it's not a boundary
     * @exception none
     */
	int boundaryCheck( char*, int len );

    /**
     * check what kind of line this is
     *
     * @param  s input string
     * @param len size of input string
     * @return line type can be MIME_INFO, MIME_XHEADER, MIME_CRLF, MIME_HEADER
     * @exception none
     */
	int checkForLineType( char* s, int len, bool startData );

    /**
     * Get message type, subtype, content type parameters and content type
     *
     * @param  s input string
     * @param param (output) returns subtype in param[0], parameters in param[1]
     * @param contentType (output) returns content type in contentType[0]
     * @return message type, returns subtype in param[0], parameters in param[1]
     * @exception none
     */
	int nGetMessageType(const std::string& s, std::string param[], int& contentType );

    /**
     * Parse an input string for boundary
     * default to "-----" if none is found
     *
     * @param  s input string
     * @return boundary string
     * @exception none
     */
	WString parseForBoundary(const WString& s );

    /**
     * translate encoding type to an integer
     *
     * @param s input string
     * @return encoding type
     * @exception none
     */
	int mime_translateMimeEncodingType(const std::string& s );

	/**
	 * translate disposition type to an integer
	 *
	 * @param  s input string
	 * @param param return content disposition parameters in param[0]
	 * @return <PRE>
	 *   NSMAIL_ERR_INVALIDPARAM     if parameters are invalid
	 *   MIMEBodyPart::INLINE         disposition type is inline
	 *   MIMEBodyPart::ATTACHMENT     disposition type is an attachment</PRE>
	 *
	 * @exception MIMEException
	 */
	int translateDispType( const std::string& s, std::vector<std::string>& param);

	int translateDispType (const std::string& s);

    /**
     * get the boundary corresponding to the current multiPart message
     *
     * @param  none
     * @return current boundary string
     * @exception none
     */
	const WString& getCurrentBoundary()const;

	void unwindCurrentParent( char* s, int len, bool deleteIt);

	/**
     * check for empty messages in all basicparts
     *
     * @param o any mime message structure, usually MIMEMessage
     *
     * @return none
     * @exception MIMEException
     */
	void checkForEmptyMessages( MIMEComponent* o );

private:

	static const int MIME_INFO;
	static const int MIME_HEADER;
	static const int MIME_XHEADER;
	static const int MIME_MESSAGE_DATA;
	static const int MIME_PARAM;
	static const int MIME_BOUNDARY;
	static const int MIME_CRLF;

	static const int MIME_UNINITIALIZED;
	static const int MIME_CONTENT_PARSE_ALL;

	static const int NSMAIL_ERR_INVALIDPARAM;
	static const int NSMAIL_ERR_OUTOFMEMORY;
	static const int NSMAIL_OK;

	static const int NOT_A_BOUNDARY;
	static const int START_BOUNDARY;
	static const int END_BOUNDARY;

	std::vector<std::string>		m_messageData; // text buffer
	std::vector<mimeInfo>			m_mimeInfo; // message info
	//MIMEByteBuffer*					m_messageByteData;
	std::vector<MIMEMessagePart*>	m_msgParts; // message info
	int m_nMessageDataIndex;


	MIMEResourceFactory* m_Factory; // factory for creating mime message data resource
	MIMEResource*		 m_Resource; // current resource 
	LineBufferOutputStream*		 m_ResourceStream; // outputstream on the current resource;

	MIMEMessage* m_mimeMessage; // entire decoded mime message
	int			 m_nMessageType; // message type, ie: message,basicpart,etc.

	MIMEComponent*		m_currentMessage; // current message being processed
	MIMEBasicPart*		m_currentBasicPart;
	MIMEMultiPart*		m_currentMultiPart;
	MIMEMessagePart*	m_currentMessagePart;

	int					m_nCurrentMessageType; // current message type
	bool				m_bStartData; // TRUE if start of data
	int					m_emptyLineNo; // TRUE if current line is empty
	char*				m_leftoverBuffer; // leftover buffer
	char*				m_inputBuffer; // inputbuffer
	int					m_leftoverBytes; //left over bytes from previous parse
	int					m_out_byte; // state info
	int					m_out_bits; // state info
	bool				m_bParseEntireFile; // false if parsing in chunks
	char*				m_QPLeftoverBuffer; // leftover buffer
	int					m_QPLeftoverBytes; // left over bytes from previous parse

	std::vector<MIMEComponent*> m_currentParent; // current message parent
	MIMEMessage*				m_currentMimeMessage; // current mime message

	bool					m_bDecodedData;
	bool					m_bLocalStorage;
	MIMEMessage*			m_nextMimeMessage;
	int						m_lastBoundry;
	std::vector<mimeInfo>	m_mimeInfoQueue;
	std::vector<mimeInfo>	m_headerQueue;
	bool					m_qp; 
	bool					m_binary;

	bool			m_readCR;
	MIMEComponent*	m_headerParent;
	MIMEComponent*	m_nextHeaderParent;
	std::string		m_previousHeaderName;
	int				m_messagePartSubType;
	bool			m_fSeenBoundary;
	bool			m_fEndMessageHeader;

	bool			m_myDelete;
};

/** @example TestMIMEParser.cpp
 * This is an example of how to use the MIMEParser to read
 * a MIME file from disk and parse it. The example writes
 * the parsed MIMEMessage back to disk.
 */


/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_MIMEPARSER_H */
