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

#ifndef I_JDF_FILTERINPUTSTREAM_H
#define I_JDF_FILTERINPUTSTREAM_H


/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include "InputStream.h"


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
 * A <code>FilterInputStream</code> contains some other input stream, which it 
 * uses as its basic source of data, possibly transforming the data along the
 * way or providing additional functionality. 
 * The class <code>FilterInputStream</code> itself simply overrides all methods of
 * <code>InputStream</code> with versions that pass all requests to the contained input stream.
 * Subclasses of <code>FilterInputStream</code> may further override some of these methods 
 * and may also provide additional methods and fields. 
 *
 * @author nverbove     
 * @ingroup io
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT FilterInputStream : public InputStream
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * Creates a <code>FilterInputStream</code> by assigning the argument <code>in</code> to the field <code>this.in</code> so as to remember it for later use.
	 * 
	 * @param in the underlying input strea
	 */

	FilterInputStream(InputStream& in);

	/**
	 * Creates a <code>FilterInputStream</code> without an underlying stream.
	 */

	FilterInputStream();

/*@}*/ 

	/**
	 * Deallocates the FilterInputStream.
	 */

	virtual ~FilterInputStream();

	///////////////////////////////////////////////////////////////////////////
	// Public Instance Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Returns the number of bytes that can be read from this input stream without blocking. 
	 * This method simply performs <code>mIn.available(n)</code> and returns the result.
	 * 
	 * @return the number of bytes that can be read from the input stream without blocking.
	 * @exception IOException if an I/O error occurs.
	 * @see FilterInputStream#mIn
	 */

	virtual int  available();

	/**
	 * Closes this input stream and releases any system resources associated with the stream.
	 * This method simply performs <code>mIn.close()</code>.
	 * @exception IOException if an I/O error occurs.
	 * @see FilterInputStream#mIn
	 */

	virtual void close();

	/**
	 * Marks the current position in this input stream. 
	 * A subsequent call to the <code>reset</code> method
	 * repositions this stream at the last marked position so that 
	 * subsequent reads re-read the same bytes. 
	 * <p>
	 * The <code>readlimit</code> argument tells this input stream to 
	 * allow that many bytes to be read before the mark position gets invalidated. 
	 * <p>
	 * This method simply performs <code>mIn.mark(readlimit)</code>.
	 *
	 * @param readlimit the maximum limit of bytes that can be read before the mark position becomes invalid.
	 * @see InputStream#reset()     
	 */

	virtual void mark(int readlimit);

	/**
	 * Tests if this input stream supports the mark and reset methods. 
	 * This method simply performs <code>mIn.markSupported()</code>.
	 * 
	 * @return <code>true</code> if this stream type supports the <code>mark</code> and <code>reset</code> method; <code>false</code> otherwise.
	 * @see FilterInputStream#mIn
	 * @see InputStream#mark()
	 * @see InputStream#reset()
	 */

	virtual bool markSupported();

	/**
	 * Reads the next byte of data from this input stream. 
	 * The value byte is returned as an int in the range <code>0</code> to <code>255</code>. 
	 * If no byte is available because the end of the stream has been reached, 
	 * the value <code>-1</code> is returned. This method blocks until input data is available,
	 * the end of the stream is detected, or an exception is thrown. 
	 *
	 * This method simply performs <code>mIn.read()</code> and returns the result.
	 *
	 * @return the next byte of data, or <code>-1</code> if the end of the stream is reached.
	 * @exception IOException if an I/O error occurs.
	 * @see FilterInputStream#mIn
	 */

	virtual int  read();

	/**
	 * Reads up to <code>blen</code> bytes of data from this input stream into an array of bytes.
	 * This method blocks until some input is available. 
	 * <p>
	 * This method simply performs the call <code>read(b, blen, 0, blen)</code> and returns
	 * the result. It is important that it does not do <code>mIn.read(b,blen)</code> instead; 
	 * certain subclasses of <code>FilterInputStream</code> depend on the implementation
	 * strategy actually used.
	 * 
	 * @return the total number of bytes read into the buffer, or <code>-1</code> if there is no more data because the end of the stream has been reached.
	 * @param b the buffer into which the data is read.
	 * @param blen the size of the buffer.
	 * @see FilterInputStream#read(char*,int,int,int)
	 * @exception IOException if an I/O error occurs.	 
	 */

	virtual int  read(char* b, int blen);

	/**
	 * Reads up to len bytes of data from this input stream into an array of bytes.
	 * This method blocks until some input is available. 
	 * <p>
	 * This method simply performs <code>mIn.read(b, blen, off, len)</code> and returns the result.
	 * 
	 * @return the total number of bytes read into the buffer, or <code>-1</code> if there is no more data because the end of the stream has been reached.
	 * @param b the buffer into which the data is read.
	 * @param blen the size of the buffer.
	 * @param off the start offset of the data.
	 * @param len the maximum number of bytes read.
	 * @exception IOException if an I/O error occurs.	 
	 * @see FilterInputStream#mIn
	 */

	virtual int  read(char* b, int blen, int off, int len);

	/**
	 * Repositions this stream to the position at the time the <code>mark</code> method was last called on this input stream. 
	 * <p>
	 * This method simply performs <code>mIn.reset()</code>. 
	 * <p>
	 * Stream marks are intended to be used in situations where you need to 
	 * read ahead a little to see what's in the stream. Often this is most
	 * easily done by invoking some general parser. If the stream is of the
	 * type handled by the parse, it just chugs along happily. 
	 * If the stream is not of that type, the parser should toss an exception 
	 * when it fails. If this happens within readlimit bytes, it allows the 
	 * outer code to reset the stream and try another parser.
	 *
	 * @exception IOException if the stream has not been marked or if the mark has been invalidated.
	 * @see FilterInputStream#mIn
	 * @see FilterInputStream#mark(int)
	 */

	virtual void reset();

	/**
	 * Skips over and discards <code>n</code> bytes of data from the input stream. 
	 * The <code>skip</code> method may, for a variety of reasons, end up skipping over
	 * some smaller number of bytes, possibly <code>0</code>. The actual number of bytes 
	 * skipped is returned. 
	 * <p>
	 * This method simply performs <code>mIn.skip(n)</code>.
	 * 
	 * @return the actual number of bytes skipped.
	 * @param n the number of bytes to be skipped.
	 * @exception IOException if an I/O error occurs.
	 */

	virtual long skip(long n);

protected:

	///////////////////////////////////////////////////////////////////////////
	// Protected Instance Variables
	///////////////////////////////////////////////////////////////////////////

	/**
	 * The input stream to be filtered.
	 */

	InputStream* mIn;

private:

	//
	// Hide copy constructor and assignment operator.
	//

	FilterInputStream(const FilterInputStream&);
	FilterInputStream& operator=(const FilterInputStream&);
};


} // namespace JDF

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 


#endif /* I_JDF_FILTERINPUTSTREAM_H */

