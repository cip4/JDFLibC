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

#ifndef I_JDF_CHARACTERDECODER_H
#define I_JDF_CHARACTERDECODER_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <jdf/lang/Exception.h>


namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 
	class WString;
	class ByteBuffer;
	class InputStream;
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
 * This class defines the decoding half of character encoders.
 * A character decoder is an algorithm for transforming 8 bit
 * binary data that has been encoded into text by a character
 * encoder, back into original binary form.
 * 
 * The character encoders, in general, have been structured 
 * around a central theme that binary data can be encoded into
 * text that has the form:
 *
 * @code
 *	[Buffer Prefix]
 *	[Line Prefix][encoded data atoms][Line Suffix]
 *	[Buffer Suffix]
 * @endcode
 *
 * Of course in the simplest encoding schemes, the buffer has no
 * distinct prefix of suffix, however all have some fixed relationship
 * between the text in an 'atom' and the binary data itself.
 *
 * In the CharacterEncoder and CharacterDecoder classes, one complete
 * chunk of data is referred to as a <i>buffer</i>. Encoded buffers 
 * are all text, and decoded buffers (sometimes just referred to as 
 * buffers) are binary octets.
 *
 * To create a custom decoder, you must, at a minimum,  overide three
 * abstract methods in this class.
 * <DL>
 * <DD>bytesPerAtom which tells the decoder how many bytes to 
 * expect from decodeAtom
 * <DD>decodeAtom which decodes the bytes sent to it as text.
 * <DD>bytesPerLine which tells the encoder the maximum number of
 * bytes per line.
 * </DL>
 *
 * Several useful decoders have already been written and are 
 * referenced in the See Also list below.
 *
 * @see		CharacterEncoder
 * @see		BASE64Decoder
 * @see		QPDecoder
 * @ingroup io
 */

class JDFTOOLS_EXPORT CharacterDecoder 
{
public:

	virtual ~CharacterDecoder() {}
    /**
     * Decode the text from the InputStream and write the decoded
     * octets to the OutputStream. This method runs until the stream
     * is exhausted.
     * @exception CEFormatException An error has occured while decoding
     * @exception CEStreamExhausted The input stream is unexpectedly out of data
     */
    virtual void decodeBuffer(InputStream& aStream, OutputStream& bStream);

    /**
     * Alternate decode interface that takes a WString containing the encoded
     * buffer and returns a byte array containing the data.
     * @exception CEFormatException An error has occured while decoding
     */
	virtual ByteBuffer* decodeBuffer(const WString& inputString);

    /**
     * Decode the contents of the inputstream into a buffer.
     */
    virtual ByteBuffer* decodeBuffer(InputStream& in);


protected:

    /** 
	 * Return the number of bytes per atom of decoding 
	 */
    virtual int bytesPerAtom() = 0;

    /** 
	 * Return the maximum number of bytes that can be encoded per line 
	 */
    virtual int bytesPerLine() = 0;

    /** 
	 * decode the beginning of the buffer, by default this is a NOP. 
	 */
    virtual void decodeBufferPrefix(InputStream& aStream, OutputStream& bStream) { }

    /** 
	 * decode the buffer suffix, again by default it is a NOP. 
	 */
    virtual void decodeBufferSuffix(InputStream& aStream, OutputStream& bStream) { }

    /**
     * This method should return, if it knows, the number of bytes
     * that will be decoded. Many formats such as uuencoding provide
     * this information. By default we return the maximum bytes that
     * could have been encoded on the line.
     */
    virtual int decodeLinePrefix(InputStream& aStream, OutputStream& bStream) { return (bytesPerLine());}

    /**
     * This method post processes the line, if there are error detection
     * or correction codes in a line, they are generally processed by
     * this method. The simplest version of this method looks for the
     * (newline) character. 
     */
    virtual void decodeLineSuffix(InputStream& aStream, OutputStream& bStream) { }

    /**
     * This method does an actual decode. It takes the decoded bytes and
     * writes them to the OuputStream. The integer <i>l</i> tells the
     * method how many bytes are required. This is always <= bytesPerAtom().
     */
    virtual void decodeAtom(InputStream& aStream, OutputStream& bStream, int l) { 
	throw CEStreamExhausted();
    }

    /**
     * This method works around the bizarre semantics of BufferedInputStream's
     * read method.
     */
    virtual int readFully(InputStream& in, char* buffer, int blen, int offset, int len); 


};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_CHARACTERDECODER_H */
