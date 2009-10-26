/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2003 The International Cooperation for the Integration of 
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

// 280303 RP set members to NULL after deleting 

/*******************************************************************************
 * 
 * Description:
 *
 *
 ******************************************************************************/

#ifndef I_JDF_MIMEBASICPART_H
#define I_JDF_MIMEBASICPART_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include "MIMEBodyPart.h"

#include "MIMEHeader.h"

#include <jdf/util/hashfun.h>
#include <jdf/util/hmap.h>


namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 
	class InputStream;
	class ByteBuffer;
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
 * The MIMEBasicPart class is a common class used for all Basic
 * MIME BodyPart types:
 * Text, Image, Audio, Video, and Application. It does not represent structured
 * parts such as MIMEMessagePart and MIMEMultiPart.
 * @ingroup mime
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT MIMEBasicPart : public MIMEBodyPart
{
public:

	/** 
	 * Content (primary) type Text.
	 */

	static const int TEXT;

	/**
	 * Content (primary) type Audio.
	 */

	static const int AUDIO;

	/**
	 * Content (primary) type Image.
	 */

	static const int IMAGE;

	/** 
	 * Content (primary) type Video.
	 */

	static const int VIDEO;

	/**
	 * Content (primary) type Application.
	 */

	static const int APPLICATION;

public:

/** 
 * @name Constructors
 */
/*@{*/
	/**
	 * Constructs a MIMEBasicPart object with the given content-type.
	 * Possible values are :  TEXT, AUDIO, IMAGE,VIDEO,APPLICATION
	 *
	 * @param contentType Content type
	 * @see MIMEBasicPart#TEXT
	 * @see MIMEBasicPart#AUDIO
	 * @see MIMEBasicPart#IMAGE
	 * @see MIMEBasicPart#VIDEO
	 * @see MIMEBasicPart#APPLICATION
	 * @exception MIMEException if ContentType passed is invalid.
	 */
	MIMEBasicPart(int contentType = TEXT);

	/**
	 * Makes a copy the BasicPart
	 */
	MIMEBasicPart(const MIMEBasicPart& part);
/*@}*/ 


	~MIMEBasicPart();

	/**
	 * Returns Content-Type of this MIME Part
	 * @see MIMEBodyPart#getContentType()
	 */
	value_pair getContentType();

	/**
	 * Returns Content-MD5 of this MIME Part as a value_pair.
	 * If Content-MD5 is not present then the first field is false.
	 * @see MIMEBasicPart#setContentMD5()
	 */
	value_pair getContentMD5();

	/**
	 * Sets Content-MD5 of this MIME Part.
	 * @param md5 string to use as Content-MD5
	 * @see MIMEBasicPart#setContentMD5()
	 */
	void setContentMD5(const WString& md5);

	/**
	 * Returns an InputStream to this Part's Data after decoding any
	 * transfer encoding.
	 * @exception IOException if an IO error occurs
	 * @exception MIMEException If the BodyData is not present or an error is 
	 * detected during decoding.
	 * MIMEBasicPart#setBodyData()
	 */
	InputStream& getBodyData();

	/** 
	 * Sets BodyData of this MIME Part. 
	 * @param is Stream to read input data from. This data must be un-encoded raw data.
	 * @param takeOwnership if true this MIME part becomes the owner of the stream.
	 * @exception MIMEException if already set
	 * @exception IOException if an IO Error occurs
	 * @see MIMEBasicPart#getDataBuf()
	 */
	void setBodyData(InputStream* is,bool takeOwnership= true);

	/**
	 * Sets BodyData of this MIME Part.
	 * @param s source string for input data. Must be un-encoded raw data.
	 * @exception MIMEException if already set
	 */
	void setBodyData(const WString& s);

	/**
	 * Sets BodyData of this MIME Part.
	 * This method saves a reference to the passed byte buffer and becomes
	 * the owner of the byte buffer passed.
	 * Does not copy the data.
	 * @param s un-encoded raw data.
	 * @exception MIMEException If already set or if s parameter is NULL.
	 */
	void setBodyData(char* s, int len);


	/**
	 * Deletes BodyData of this MIME Part.
	 * If no BodyData is present, this method has no effect.
	 */
	void deleteBodyPart();

	/**
	 * Outputs a byte-stream for this part with its MIME part headers and 
	 * encoded body data.
	 * @param fullfilename FileName including full path of where to write the byte-stream.
	 * @exception IOException If an IO error occurs.
	 * @exception MIMEException If any required fields in the bodyPart are not set-up
	 */
	void putByteStream(const WString& fullFileName);

	/** 
	 * Outputs a byte-stream for this part with its MIME part headers and encoded
	 * body data.
	 * @param os OutputStream to write to.
	 * @exception IOException If an IO error occurs.
	 * @exception MIMEException If any required fields in the bodyPart are not set-up
	 */
	void putByteStream(OutputStream& os);

	/**
	 * Returns the size of this Part's BodyData
	 * @return size of BodyData or -1 if this part does not have bodyData.
	 */
	int getSize();

	/**
	 * Sets Content-Transfer-Encoding of this MIME Part.
	 * @param encoding Value that represents the encoding.
	 * @see MIMEBodyPart#BASE64
	 * @see MIMEBodyPart#QP
	 * @see MIMEBodyPart#BINARY
	 * @see MIMEBodyPart#E7BIT
	 * @see MIMEBodyPart#E8BIT
	 * @exception MIMEException if encoding is invalid
	 */
	void setContentEncoding(int encoding);

	/**
	 * Returns value of Content-Transfer-Encoding of this MIME Part. -1 if none present.
	 * @see MIMEBodyPart#BASE64
	 * @see MIMEBodyPart#QP
	 * @see MIMEBodyPart#BINARY
	 * @see MIMEBodyPart#E7BIT
	 * @see MIMEBodyPart#E8BIT
	 */
	int getContentEncoding();

	/**
	 * Sets a header of this body-part given name and value.
	 * To be used to set any header that is not explicitly supported with a
	 * set method, such as X=headers, Multiple invocations on the header to
	 * replace the old value.
	 * @param name Name of the header field. Should not include ':'
	 * @param value Value of the header field to be added
	 */
	void setHeader(const WString& name, const WString& value);

	/**
	 * Appends the value to an existing header. Creates a new header if one
	 * does not exist already.
	 * @param name Name of the header field.
	 * @param value Value of the header field to be added.
	 */
	void addHeader(const WString& name, const WString& value);

	/**
	 * Returns the value of the requested header.
	 * The first field is false if the header is not present.
	 * @param name Name of the header field
	 */
	value_pair getHeader(const WString& name);

	/**
	 * Returns all the headers in this Part as an array of Header objects.
	 */
	std::vector<MIMEHeader> getAllHeaders();

	/**
	 * Deletes the requested header from this Part.
	 * @param name Name of the header field.
	 */
	void deleteHeader(const WString& name);

	/**
	 * Checks if it is OK to set the header with the setHeader().
	 * @return the first field is true if it is ok to set. The second is the name of the method to use if it not ok.
	 */
	value_pair isOKtoset(WString name);

	int getMessageDataLen() { return getSize(); }

	MIMEBodyPart* clone();

private:

	static const int BASE64;
	static const int QP;
	static const int BINARY;
	static const int E7BIT;
	static const int E8BIT;
	static const int EIGNORE;
	static const int UNINITIALIZED ;
	static const int MAXDATABUFSIZE;

	static const JDFCh* m_StringContentTypes[];
	static const JDFCh* m_StringEncoding[];
	static const JDFCh* m_StringDisposition[];

	int			m_contentType;
#pragma warning(push)
#pragma warning(disable: 4251)
	value_pair  m_contentMD5;
#pragma warning(pop)
	int			m_contentTransferEncoding;
	int			m_parsedPart;

	ByteBuffer* getStreamData(InputStream& is);

	// The key to the hashtable below is the name of the header field.
	// To make sure we handle case differences in the header -name, we
	// must convert the header name to lower-case always prior to the 
	// hash look-up. The entries added to the hash table are objects of
	// class Header.
#pragma warning(push)
#pragma warning(disable: 4251)
	hmap<WString,MIMEHeader,ElfHash> m_mimeHeadersTable;
#pragma warning(pop)

	// Buffer to hold body-part (not encoded). We always store un-encoded.
	// Buffer stores data as parsed from input message or as given by the user
	// when constructing this bodyPart.
	ByteBuffer*  m_databuf;
	char* m_readbuf;
	InputStream* m_dataStream;
	InputStream* m_charStream;

	int m_nStartMessageDataIndex;
	int m_nEndMessageDataIndex;
	int m_nMessageDataLen;

	bool m_dataStreamOwnerShip;

protected:

	/** 
	 * Returns a ByteBuffer object, return null if no data
	 * used by parser
	 */

	ByteBuffer* getDataBuf();

	inline int getStartMessageDataIndex() { return m_nStartMessageDataIndex;}
	inline void setStartMessageDataIndex(int i) { m_nStartMessageDataIndex = i;}

	inline int getEndMessageDataIndex() { return m_nEndMessageDataIndex;}
	inline void setEndMessageDataIndex(int i) { m_nEndMessageDataIndex = i;}

	void setMessageDataLen(int len) { setSize(len); }
	void setContentType(int contentType) { m_contentType = contentType;}
	bool getDecodedData() { return m_bDecodedData;}
	void setDecodedData(bool decodedData) { m_bDecodedData = decodedData;}
	void setSize(int len);

	/**
	 * Non clone version
	 */
	void setBodyData(ByteBuffer* data);

	bool m_bDecodedData;
	bool m_endData;

	friend class MIMEParser;
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_MIMEBASICPART_H */
