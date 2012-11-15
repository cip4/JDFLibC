/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2012 The International Cooperation for the Integration of 
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

#ifndef I_JDF_FILTEROUTPUTSTREAM_H
#define I_JDF_FILTEROUTPUTSTREAM_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include "OutputStream.h"


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
 * This class is the superclass of all classes that filter output streams.
 * These streams sit on top of an already existing output stream 
 * (the <i>underlying</i> output stream) which it uses as its basic sink of data,
 * but possibly transforming the data along the way or providing additional
 * functionality. 
 * <p>
 * The class <code>FilterOutputStream</code> itself simply overrides all methods of 
 * OutputStream with versions that pass all requests to the underlying
 * output stream. Subclasses of <code>FilterOutputStream</code> may further override
 * some of these methods as well as provide additional methods and fields. 
 *
 * @author nverbove     
 * @ingroup io
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT FilterOutputStream : public OutputStream
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * Creates an output stream filter with no underlying output stream
	 * 
	 */

	FilterOutputStream();

	/**
	 * Creates an output stream filter built on top of the specified underlying output stream.
	 * 
	 * @param out the underlying output stream to be assigned to the field this.out for later use,
	 */

	FilterOutputStream(OutputStream& out);

/*@}*/ 

	/**
	 * Destructs this FilterOutputStream.
	 */

	virtual ~FilterOutputStream();

	///////////////////////////////////////////////////////////////////////////
	// Public Instance Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Closes this output stream and releases any system resources associated with the stream. 
	 * The <code>close</code> method of <code>FilterOutputStream</code> calls its <code>flush</code> method, 
	 * and then calls the <code>close</code> method of its underlying output stream.
	 * 
	 * @exception IOException if an I/O error occurs.
	 * @see FilterOutputStream#flush()    
	 * @see FilterOutputStream#mOut
	 */

	virtual void close();

	/**
	 * Flushes this output stream and forces any buffered output bytes to be written out to the stream. 
	 * The <code>flush</code> method of <code>FilterOutputStream</code> calls the <code>flush</code> method of 
	 * its underlying output stream.
	 *
	 * @exception IOException if an I/O error occurs.
	 * @see FilterOutputStream#mOut
	 */

	virtual void flush();

	/**
	 * Writes <code>blen</code> bytes to this output stream. 
	 * The <code>write</code> method of <code>FilterOutputStream</code> calls its <code>write</code> method of 
	 * three arguments with the arguments <code>b</code>, <code>blen</code>, <code>0</code>, and <code>blen</code>.
	 * <p>
	 * Note that this method does not call the one-argument <code>write</code> method 
	 * of its underlying stream with the single argument <code>b</code>.
	 * 
	 * @param b the data buffer to be written.
	 * @param blen the number of bytes to write
	 * @exception IOException if an I/O error occurs.
	 * @see FilterInputStream#write(char,int,int)    
	 */

	virtual void write(const char* b, size_t blen);

	/**
	 * Writes <code>len</code> bytes from the specified byte array starting
	 * at offset <code>off</code> to this output stream. 
	 * The <code>write</code> method of <code>FilterOutputStream</code> calls the <code>write</code> method
	 * of one argument on each byte to output. 
	 * <p>
	 * Note that this method does not call the <code>write</code> method of its underlying output stream with
	 * the same arguments. Subclasses of <code>FilterOutputStream</code> should provide a more efficient 
	 * implementation of this method.
	 * 
	 * @param b the data buffer to be written.
	 * @param blen the size of the data buffer.
	 * @param off the start offset in the data buffer.
	 * @param len the number of bytes to be written.
	 * @exception IOException if an I/O error occurs.
	 * @see FilterOutputStream#write(int)    
	 */

	virtual void write(const char* b, size_t blen, size_t off, size_t len);


	/**
	 * Writes the specified byte to this output stream.
	 * The <code>write</code> method of <code>FilterOutputStream</code> calls 
	 * the <code>write</code> method of its underlying output stream, that is,
	 * it performs <code>mOut.write(b)</code>. 
	 * <p>
	 * Implements the abstract <code>write</code> method of <code>OutputStream</code>.
	 * 
	 * @param b the byte.
	 * @exception IOException if an I/O error occurs.
	 */

	virtual void write(int b);

protected:

	///////////////////////////////////////////////////////////////////////////
	// Protected Instance Variables
	///////////////////////////////////////////////////////////////////////////

	/**
	 * The output stream to be filtered.
	 */

	OutputStream* mOut;

private:

	//
	// Hide copy constructor and assignment operator.
	//

	FilterOutputStream(const FilterOutputStream&);
	FilterOutputStream& operator=(const FilterOutputStream&);
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_FILTEROUTPUTSTREAM_H */


/* end of file */
