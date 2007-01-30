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

#ifndef I_JDF_OUTPUTSTREAM_H
#define I_JDF_OUTPUTSTREAM_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <jdf/lang/JDFToolsDefs.h>


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

/**
 * This abstract class is the superclass of all classes representing an output stream of bytes.
 * An output stream accepts output bytes and sends them to some sink. 
 * <p>
 * Applications that need to define a subclass of <code>OutputStream</code> must always
 * provide at least a method that writes one byte of output. 
 *
 * @author nverbove     
 * @see BufferedOutputStream
 * @see OutputStream#write()
 * @see InputStream
 * @ingroup io
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT OutputStream
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * Constructs a new OutputStream Object.
	 */

	OutputStream() ;

/*@}*/ 

	/**
	 * Destructs this output stream.
	 */

	virtual ~OutputStream() ;

	///////////////////////////////////////////////////////////////////////////
	// Public Instance Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Closes this output stream and releases any system resources associated with this stream. 
	 * The general contract of <code>close</code> is that it closes the output stream.
	 * A closed stream cannot perform output operations and cannot be reopened. 
	 * <p>
	 * The <code>close</code> method of <code>OutputStream</code> does nothing.
	 * 
	 * @exception IOException if an I/O error occurs.
	 */

	virtual void close();

	/**
	 * Writes <code>blen</code< bytes from the specified byte array to this output stream.
	 * The general contract for <code>write(b)</code> is that it should have exactly the same effect
	 * as the call <code>write(b, blen, 0, blen)</code>.
	 * 
	 * @exception IOException if an I/O error occurs.
	 * @see OutputStream#write(char*,int,int,int)    
	 */

	virtual void write(const char* b, int blen);

	/**
	 * Writes <code>len</code> bytes from the specified byte array starting at offset <code>offset</code> to this output stream. 
	 * The general contract for <code>write(b, off, len)</code> is that some of the bytes in the array b 
	 * are written to the output stream in order; element <code>b[offset]</code> is the first byte written 
	 * and <code>b[offset+len-1]</code> is the last byte written by this operation. 
	 * <p>
	 * The <code>write</code> method of <code>OutputStream</code> calls the <code>write</code> method of
	 * one argument on each of the bytes to be written out. 
	 * Subclasses are encouraged to override this method and provide a more efficient implementation. 
	 * <p>
	 * If b is <code>NULL</code>, a NullPointerException is thrown. 
	 * <p>
	 * If <code>offset</code> is negative, or <code>len</code> is negative, or <code>off+len</code> is
	 * greater than <code>blen</code>, length of the array <code>b</code>, then an
	 * IndexOutOfBoundsException is thrown.
	 * 
	 * @param b the data buffer
	 * @param blen the length of the data buffer
	 * @param offset the start offset in the data.
	 * @param len the number of bytes to write.
	 * @exception IOException - if an I/O error occurs. In particular, an <code>IOException</code> is thrown if the output stream is closed.
	 */

	virtual void write(const char* b, int blen, int offset, int len);

	/**
	 * Writes the specified byte to this output stream. 
	 * The general contract for <code>write</code> is that one byte is written to the output stream.
	 * The byte to be written is the eight low-order bits of the argument b. 
	 * The 24 high-order bits of b are ignored. 
	 * <p>
	 * Subclasses of <code>OutputStream must provide an implementation for this method.
	 * 
	 * @param b the byte 
	 * @exception IOException if an I/O error occurs. In particular, an <code>IOException</code> may be thrown if the output stream has been closed.
	 * @see     
	 */

	virtual void write(int b) = 0;

	/**
	 * Flushes this output stream and forces any buffered output bytes to be written out.
	 * The general contract of flush is that calling it is an indication that, 
	 * if any bytes previously written have been buffered by the implementation of the 
	 * output stream, such bytes should immediately be written to their intended destination. 
	 *
	 * The <code>flush</code> method of <code>OutputStream</code> does nothing.
	 *
	 * @exception IOException if an I/O error occurs.
	 */

	virtual void flush();

private:

	//
	// Hide copy constructor and assignment operator.
	//

	OutputStream(const OutputStream&);
	OutputStream& operator=(const OutputStream&);
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_OUTPUTSTREAM_H */


