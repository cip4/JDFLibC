/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2004 The International Cooperation for the Integration of 
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
* 20040405 RP addBodyPart reduced return value by 1
*
*
******************************************************************************/

#ifndef I_JDF_MIMEMULTIPART_H
#define I_JDF_MIMEMULTIPART_H


/******************************************************************************
*	Includes
******************************************************************************/ 

#include "MIMEBodyPart.h"

#include <vector>


namespace JDF
{
	
/******************************************************************************
*	Forward declarations
	******************************************************************************/ 
	class InputStream;
	
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
	* The MIMEMultiPart class implements the MIME multi-part Content-Type.
	* <p>
	* The multi-part content type represents messages with multiple attachment
	* of potentially different media. This content type describes a message
	* that is made up of one or more sub-body parts.
	* The Multipart type has several subtypes that describe how the 
	* sub-parts relate to each other. These include mixed, alternative,
	* digest, and parallel.
	* @ingroup mime
	* @nosubgrouping
	*/
	class JDFTOOLS_EXPORT MIMEMultiPart : public MIMEBodyPart
	{
	public:
		
	/** 
	* @name Constructors
		*/
		/*@{*/
		/** 
		* Constructs a MIMEMultiPart object
		* Default constructor for the MIMEMultiPart
		*/
		MIMEMultiPart();
		
		/** 
		* Constructs a MIMEMultiPart object with the specified text and filename.
		* Both textIS and fileName need to be valid objects.
		* See MIMEMessage if you need textIS or fileName to be empty
		* @param textIS InputStream to text that becomes (first) text part of the multi-part
		* @param filename Name of the file that becomes second part of the multi-part.
		* @param Encoding Encoding for the file attachment. To select a default encoding, use -1.
		* @see MIMEMessage
		* @see MIMEBodyPart#BASE64
		* @see MIMEBodyPart#QP
		* @see MIMEBodyPart#BINARY
		* @see MIMEBodyPart#E7BIT
		* @see MIMEBodyPart#E8BIT
		* @exception MIMEException if encoding is invalid
		* @exception FileNotFoundException If filename file does not exist.
		* @exception IOException On IO Errors on filename or textIS.
		*/
		MIMEMultiPart(InputStream* textIS, const WString& fileName, int encoding);
		
		MIMEMultiPart(const MIMEMultiPart& m);
		/*@}*/
		~MIMEMultiPart();
		
		/**
		* Returns Content-Type of this MIME Part. Always returns the
		* string "MultiPart".
		*/
		value_pair getContentType();
		
		/**
		* Returns the count of BodyParts in this MultiPart or <code>0</code>
		* if no parts exist.
		*/
		int getBodyPartCount();
		
		/**
		* Returns an object of corresponding MIME BodyPart type at the 
		* specified index of this MultiPart.
		* @param index Index for the BodyPart to return. Index ranges from 0 to (count_of_parts-1).
		* @param clone If false a reference to the internal BodyPart is returned else a cloned copy.
		* @exception MIMEException If invalid index.
		* @see MIMEBasicPart
		* @see MIMEMessagePart
		* @see MIMEMultiPart
		* @see MIMEMultiPart#getBodyPartCount
		*/
		MIMEBodyPart* getBodyPart(unsigned int index, bool clone);
		
		/**
		* Returns an object of corresponding MIME BodyPart type wit hthe
		* the specified Content-ID.
		* This method can be used in conjunction with a CID URL, to reference
		* a MIMEBodyPart. A CID-URL uses a URL scheme to reference MIME bodyparts
		* in a multipart MIME object.
		* 
		* @param cid the Content-ID of the BodyPart to return. 
		* @param clone If false a reference to the internal BodyPart is returned else a cloned copy.
		* @exception MIMEException If there is no BodyPart with the specified content-ID.
		* @see MIMEBasicPart
		* @see MIMEMessagePart
		* @see MIMEMultiPart
		*/
		MIMEBodyPart* getBodyPart(const WString& cid, bool clone);
		
		/**
		* Outputs a byte stream for this Message in MIME format.
		* Applies transfer encoding all bodyParts as applicable.
		* @param os OutputStream to be written to
		* #exception MIMEException If an error occurs during encoding
		* #exception IOException if an IO error occurs.
		*/
		void putByteStream(OutputStream& os);
		
		/**
		* Deletes the bodyPart at the requested index from this Multipart
		* Adjusts indices of any parts after the deleted part upwards
		* as needed.
		* @param index The index of the bodyPart to remove.
		* @exception MIMEException if invalid index.
		*/
		void deleteBodyPart(int index);
		
		/** 
		* Add the specified filename as a (MIMEBasicPart) BodyPart to this MultiPart.
		* @param filename Name of the file to add as bodyPart
		* @param encoding Preferred MIME encoding for this part, To select default, use -1.
		* @return The index at which this bodyPart is added.
		* @see MIMEBodyPart#BASE64
		* @see MIMEBodyPart#QP
		* @see MIMEBodyPart#BINARY
		* @see MIMEBodyPart#E7BIT
		* @see MIMEBodyPart#E8BIT
		* @exception MIMEException If <code>filename</code> file is inaccessible or I/O errors
		* @exception FileNotFoundException If <code>filename</code> file does not exist.
		* @exception IOException On IO errors on filename
		* @since 20040405 reduced return value by 1
		*/
		int addBodyPart(const WString& filename, int encoding);
		
		/**
		* Adds a MIMEBodyPart to this MultiPart. This part must already be constructed
		* and fully set-up. As MIMEBodyPart is an abstract class, the object passed in
		* the part parameters must be one of three concrete classes: 
		* <code>MIMEBasicPart</code>, <code>MIMEMultiPart</code>, or <code>MIMEMessagePart</code>
		* If not, a MIMEException is thrown.
		* @param part BodyPart to add.
		* @param clone If true a copy of the passed object is stored, else stores a reference to the passed object.
		* @return The index at which to add this BodyPart.
		* @exception MIMEException If part is malformed or is not an object of one of three classes:
		* MIMEBasicPart,MIMEMultiPart, or MIMEMessagePart.
		* @see MIMEBasicPart
		* @see MIMEMultiPart
		* @see MIMEMessagePart
		* @since 20040405 reduced return value by 1
		*/
		int addBodyPart(MIMEBodyPart* part, bool clone);
		
		/**
		* Returns the preamble for this multi-part if present.
		* The first field of the value_pair is false if preamble does not exist;
		* If preamble exists first is true and second is the value.
		*/
		value_pair getPreamble();
		
		/**
		* Sets the preamble for this multi-part.
		*/
		void setPreamble(const WString& preamble);
		
		/**
		* Clones an instance of this MultiPart object.
		*/
		MIMEBodyPart* clone();
		
protected:
	
/**
* The following is an internal routine. Not to be exposed at the API.
* #exception MIMEException If the multipart is malformed.
* #exception IOException if an IO error occurs.
* @internal
	*/
	void putByteStream(OutputStream& os, bool needPreamble);
	
	void setContentEncoding(int encoding);
	
	void addPreamble(char* preamble, int len);
	void addPreamble(char* preamble);
	
	void setBoundary(const WString& boundary) { m_boundary = boundary;}
	WString getBoundary() { return m_boundary;}
	
private:
	
/**
* Generates and returns a boundary string that can be used in multi-parts etc.
* @return The boundary string.
	*/
	WString generateBoundary();
	
protected:
	
	int m_parsedPart;
	
private:
	
	static const int UNINITIALIZED;
	
	static const JDFCh* m_StringEncoding[];
	static const JDFCh* m_StringDisposition[];
	static const JDFCh* MULTIPART;
	
	int	 m_bpCount; // count of body parts
	bool m_needPreamble;
	bool m_endPart;
	std::vector<MIMEBodyPart*> m_bodyParts;
	WString     m_boundary;
	value_pair  m_preamble;
	int			m_contentTransferEncoding;
	
	friend class MIMEParser;
	
	
};

/******************************************************************************
*	Prototypes
******************************************************************************/ 


/******************************************************************************
*	Implementation
******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_MIMEMULTIPART_H */
