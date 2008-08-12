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

/*******************************************************************************
 * 
 * Description:
 *
 *
 ******************************************************************************/

#ifndef I_JDF_MIMEBODYPART_H
#define I_JDF_MIMEBODYPART_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include "MIMEComponent.h"

#include <jdf/lang/WString.h>

#include <utility>


namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 
	class OutputStream;

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
 * The MIMEBodyPart class represents a body-part of a MIME message.
 * MIMEBodyPart is the base class for all MIME BodyPart classes:
 * MIMEBasicPart, MIMEMessagePart, and MIMEMultiPart.
 *
 * @author Nico Verboven
 * @ingroup mime
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT MIMEBodyPart : public MIMEComponent
{
public:

	typedef std::pair<bool,WString> value_pair;
	/**
	 * Content Disposition is Attachment.
	 */

	static const int ATTACHMENT;

	/**
	 * Content Disposition is inline.
	 */
	static const int INLINE;

	/** 
	 * Base64 Transfer Encoding.
	 */
	static const int BASE64;

	/**
	 * Quoted Printable Transfer Encoding.
	 */
	static const int QP;

	/**
	 * Binary Data with no Transfer Encoding.
	 */
	static const int BINARY;

	/** 
	 * 7bit Data with No Transfer Encoding.
	 */
	static const int E7BIT;

	/**
	 * 8bit Data with No Transfer Encoding.
	 */
	static const int E8BIT;

	/**
	 * @internal
	 */
	static const int UNINITIALIZED;

/** 
 * @name Constructors
 */
/*@{*/

	MIMEBodyPart();
	MIMEBodyPart(const MIMEBodyPart& part);
/*@}*/ 

	virtual ~MIMEBodyPart();




	/**
	 * Returns Content-Type of this MIME Part.
	 * Note: The primary content-type is determined by the
	 * actual MIMEPart class and thus cannot be set.
	 * @return value_pair with first set to true and second containing the Content-Type or first set to
	 * false if the Content-Type cannot be determined.
	 */
	virtual value_pair getContentType() = 0;

	/**
	 * Returns Content SubType of this MIME Part.
	 * @return value_pair with first set to true and second containing the Content-SubType or first set to
	 * false if Content-SubType cannot be determined.
	 */
	virtual value_pair getContentSubType();

	/**
	 * Sets the Content SubType of this MIME Part.
	 * @param subType string to use as sub-type for this part.
	 */
	void setContentSubType(WString subType);

	/**
	 * Returns Content-Type Parameters of this MIME Part.
	 * @return value_pair with first set to true and second containing the Content-Type Parameters or first set to
	 * false if no parameters exist,
	 */
	value_pair getContentTypeParams();

	/**
	 * Sets Content-Type Parameters of this MIME Part.
	 * @param params string to use as Content-Type Parameters.
	 */
	void setContentTypeParams(WString params);

	/** 
	 * Returns Content-ID of this MIME Part.
	 * @return value_pair with first set to true and second containing the Content-ID or first set to
	 * false if Content-ID cannot be determined.
	 */
	value_pair getContentID();

	/**
	 * Sets Content-ID of this MIME Part
	 * @param cid string to use as Content-ID.
	 */
	void setContentID(WString cid);

	/**
	 * Returns Content-Disposition of this MIME Part.
	 * @return Content-Disposition of this MIME Part or -1 if none present.
	 * @see MIMEBodyPart#ATTACHMENT
	 * @see MIMEBodyPart#INLINE
	 */
	int getContentDisposition();

	/**
	 * Sets ContentDisposition of this MIME Part.
	 * @param disposition value of this Content-Disposition. Must be ATTACHMENT or INLINE.
	 * @see MIMEBodyPart#ATTACHMENT
	 * @see MIMEBodyPart#INLINE
	 * @exception MIMEException if invalid disposition value is passed.
	 */
	void setContentDisposition(int disposition);

	/**
	 * Returns Content-Disposition Parameters of this MIME Part.
	 * @return value_pair with first set to true and second containing the Content Disposition or first set to
	 * false if none exist.
	 */
	value_pair getContentDispParams();

	/** 
	 * Sets Content-Disposition Parameters of this MIME Part.
	 * @param params string to be used as Content-Disposition Parameters.
	 */
	void setContentDispParams(WString params);

	/**
	 * Returns Content-Description of this MIME Part.
 	 * @return value_pair with first set to true and second containing the Content-Description or first set to
	 * false if none exist.
	 */
	value_pair getContentDescription();

	/**
	 * Sets Content-Description of this MIME Part
	 * @param description string to be used as Content-Description.
	 */
	void setContentDescription(WString description);

	virtual MIMEBodyPart* clone() = 0;

	virtual void putByteStream(OutputStream& os) = 0;

protected:

	std::string encodeContDispParams(WString contDispParams);
	
	static const int DATABUFSZ;
	static const int HDRBUFSZ;

#pragma warning(push)
#pragma warning(disable: 4251)
	value_pair m_contentSubType;
	value_pair m_contentTypeParams;
	value_pair m_contentID;
	int		   m_contentDisposition;
	value_pair m_contentDispParams;
	value_pair m_contentDescription;
#pragma warning(pop)

	/**
	 * Byte characters representing CRLF
	 */
	static char* CRLF;
	static char* LF;

	static void initMIMEBodyPart();
	static void terminateMIMEBodyPart();

	friend class PlatformUtils;
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_MIMEBODYPART_H */
