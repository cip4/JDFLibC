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

#ifndef I_JDF_INPUTSTREAM_H
#define I_JDF_INPUTSTREAM_H

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
 * This abstract class is the superclass of all classes representing an input stream of bytes. 
 * Applications that need to define a subclass of <code>InputStream</code> must always provide 
 * a method that returns the next byte of input. 
 *
 * @author nverbove    
 * @see BufferedInputStream
 * @see InputStream#read()  
 * @see OutputStream
 * @ingroup io
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT InputStream
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	InputStream() {}

/*@}*/ 

	virtual ~InputStream() {}

	///////////////////////////////////////////////////////////////////////////
	// Public Instance Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Returns the number of bytes that can be read (or skipped over) from this input stream without blocking by the next caller of a method for this input stream.
	 * The next caller might be the same thread or another thread. 
	 * <p>
	 * The <code>available</code> method for class <code>InputStream</code> always returns 0. 
	 * <p>
	 * This method should be overridden by subclasses.
	 * 
	 * @return the number of bytes that can be read from this input stream without blocking.
	 * @exception IOException if an I/O error occurs.
	 */

	virtual int  available();

	/**
	 * Closes this input stream and releases any system resources associated with the stream. 
	 * <p>
	 * The <code>close</code> method of <code>InputStream</code> does nothing.
	 * 
	 * @exception IOException if an I/O error occurs.
	 */

	virtual void close();

	/**
	 * Marks the current position in this input stream. 
	 * A subsequent call to the <code>reset</code> method repositions this stream at the  
	 * last marked position so that subsequent reads re-read the same bytes. 
	 * <p>
	 * The <code>readlimit</code> arguments tells this input stream to allow that 
	 * many bytes to be read before the mark position gets invalidated. 
	 * <p>
	 * The general contract of <code>mark</code> is that, if the method <code>markSupported</code> returns <code>true</code>,
	 * the stream somehow remembers all the bytes read after the call to mark and 
	 * stands ready to supply those same bytes again if and whenever the method <code>reset</code>
	 * is called. However, the stream is not required to remember any data at all 
	 * if more than <code>readlimit</code> bytes are read from the stream before <code>reset</code> is called. 
	 * <p>
	 * The <code>mark</code> method of <code>InputStream</code> does nothing.
	 * 
	 * @param readlimit the maximum limit of bytes that can be read before the mark position becomes invalid.
	 * @see InputStream#reset()    
	 */

	virtual void mark(int readlimit);

	/**
	 * Tests if this input stream supports the <code>mark</code> and <code>reset</code> methods.
	 * The <code>markSupported</code> method of <code>InputStream</code> returns false.
	 *
	 * @return <code>true</code> if this stream type supports the <code>mark</code> and </code>reset</code> method; <code>false</code> otherwise.
	 * @see InputStream#mark()
     * @see InputStream#reset()
	 */

	virtual bool markSupported();

	/**
	 * Reads the next byte of data from the input stream. 
	 * The value byte is returned as an int in the range 0 to 255.
	 * If no byte is available because the end of the stream has been reached, 
	 * the value -1 is returned. 
	 * This method blocks until input data is available, the end of the stream is 
	 * detected, or an exception is thrown. 
	 * A subclass must provide an implementation of this method.
	 * 
	 * @return the next byte of data, or -1 if the end of the stream is reached.
	 * @exception IOException if an I/O error occurs.
	 */

	virtual int  read() = 0;

	/**
	 * Reads some number of bytes from the input stream and stores them into the buffer array b.
	 * The number of bytes actually read is returned as an integer. 
	 * This method blocks until input data is available, end of file is detected, or an exception
	 * is thrown. 
	 * <p>
	 * If b is <code>null</code>, a <code>NullPointerException</code> is thrown. 
	 * If the length of b is zero, then no bytes are read and 0 is returned; otherwise,
	 * there is an attempt to read at least one byte. If no byte is available because the stream
	 * is at end of file, the value -1 is returned; otherwise, at least one byte is read and stored into b. 
	 * <p>
	 * The first byte read is stored into element b[0], the next one into b[1], and so on.
	 * The number of bytes read is, at most, equal to the length of b. Let <i>k</i> be the number
	 * of bytes actually read; these bytes will be stored in elements b[0] through b[<i>k</i>-1], 
	 * leaving elements b[<i>k</i>] through b[b.length-1] unaffected. 
	 * <p>
	 * If the first byte cannot be read for any reason other than end of file, 
	 * then an <code>IOException</code> is thrown. In particular, an <code>IOException</code> is
	 * thrown if the input stream has been closed. 
	 * <p>
	 * The <code>read(b,length)</code> method for class <code>InputStream</code> has the same effect as: 
	 * <p><blockquote><pre>
	 * read(b, blen, 0, blen) 
	 * </pre></blockquote>
     * <p>
	 * @return the total number of bytes read into the buffer, or -1 is there is no more data because the end of the stream has been reached.
	 * @param b the buffer into which the data is read.
	 * @param blen the size of the buffer
	 * @see read(char*,int,int,int)     
	 */

	virtual int  read(char* b, int blen);

	/**
	 * Reads up to len bytes of data from the input stream into an array of bytes.
	 * An attempt is made to read as many as len bytes, but a smaller number may be read,
	 * possibly zero. The number of bytes actually read is returned as an integer. 
	 * <p>
	 * This method blocks until input data is available, end of file is detected, or an exception is thrown. 
	 * <p>
	 * If b is <code>null</code>, a <code>NullPointerException</code> is thrown. 
	 * <p>	
	 * If <code>offset</code> is negative, or <code>len</code> is negative, or <code>offset+len</code> is greater than <code>blen</code>, 
	 * then an <code>IndexOutOfBoundsException</code> is thrown. 
	 * <p>
	 * If <code>len</code> is zero, then no bytes are read and 0 is returned; 
	 * otherwise, there is an attempt to read at least one byte. 
	 * If no byte is available because the stream is at end of file, the value <code>-1</code> is returned; otherwise, 
	 * at least one byte is read and stored into b. 
	 * <p>
	 * The first byte read is stored into element <code>b[offset]</code>, the next one 
	 * into <code>b[off+1]</code>, and so on. The number of bytes read is, at most,
	 * equal to <code>len</code>. Let <i>k</i> be the number of bytes actually read; 
	 * these bytes will be stored in elements <code>b[offset]</code> through <code>b[offset+<i>k</i>-1]</code>, 
	 * leaving elements <code>b[offset+<i>k</i>]</code> through <code>b[offset+len-1]</code> unaffected. 
	 * <p>
	 * In every case, elements <code>b[0]</code> through <code>b[offset]</code> and 
	 * elements <code>b[off+len]</code> through <code>b[blen-1]</code> are unaffected. 
	 * <p>
	 * If the first byte cannot be read for any reason other than end of file, 
	 * then an <code>IOException</code> is thrown. In particular, an <code>IOException</code> is thrown
	 * if the input stream has been closed. 
	 * <p>
	 * The <code>read(b, blen, offset, len)</code> method for class <code>InputStream</code> simply 
	 * calls the method <code>read()</code> repeatedly. If the first such call results in
	 * an <code>IOException</code>, that exception is returned from the call 
	 * to the <code>read(b, blen, offset, len)</code> method. If any subsequent call 
	 * to <code>read()</code> results in a <code>IOException</code>, the exception is 
	 * caught and treated as if it were end of file; the bytes read up to that point 
	 * are stored into b and the number of bytes read before the exception occurred is
	 * returned. Subclasses are encouraged to provide a more efficient implementation of
	 * this method.
	 *
	 * @return the total number of bytes read into the buffer, or -1 if there is no more data because the end of the stream has been reached.
	 * @param b the buffer into which the data is read.
	 * @param blen the size of the buffer
	 * @param offset the start offset in array b at which the data is written.
	 * @param len the maximum number of bytes to read.
	 * @exception IOException - if an I/O error occurs.
	 * @see read()    
	 */

	virtual int  read(char* b, int blen, int offset, int len);

	/**
	 * Repositions this stream to the position at the time the <CODE>mark</CODE> method was last called on this input stream. 
     *<P>The general contract of <CODE>reset</CODE> is: 
	 * <P>
	 * <UL>
	 *	<LI>If the method <CODE>markSupported</CODE> returns <CODE>true</CODE>, 
	 *	then: 
	 *	<UL>
	 *	  <LI>If the method <CODE>mark</CODE> has not been called since the stream 
	 *	  was created, or the number of bytes read from the stream since 
	 *	  <CODE>mark</CODE> was last called is larger than the argument to 
	 *	  <CODE>mark</CODE> at that last call, then an <CODE>IOException</CODE> 
	 *	  might be thrown. 
	 *	  <LI>If such an <CODE>IOException</CODE> is not thrown, then the stream is 
	 *	  reset to a state such that all the bytes read since the most recent call 
	 *	  to <CODE>mark</CODE> (or since the start of the file, if <CODE>mark</CODE> 
	 *	  has not been called) will be resupplied to subsequent callers of the 
	 *	  <CODE>read</CODE> method, followed by any bytes that otherwise would have 
	 *	  been the next input data as of the time of the call to <CODE>reset</CODE>. 
	 *	  </LI></UL>
	 *	<LI>If the method <CODE>markSupported</CODE> returns <CODE>false</CODE>, 
	 *	then: 
	 *	<UL>
	 *	  <LI>The call to <CODE>reset</CODE> may throw an <CODE>IOException</CODE>. 
	 *	  <LI>If an <CODE>IOException</CODE> is not thrown, then the stream is reset 
	 *	  to a fixed state that depends on the particular type of the input stream 
	 *	  and how it was created. The bytes that will be supplied to subsequent 
	 *	  callers of the <CODE>read</CODE> method depend on the particular type of 
	 *	  the input stream. </LI></UL></LI></UL>
	 *  <P>The method <CODE>reset</CODE> for class <CODE>InputStream</CODE> does 
	 *  nothing and always throws an <CODE>IOException</CODE>.</P>
	 * 
	 * @exception IOException if this stream has not been marked or if the mark has been invalidated.
	 * @see InputStream#mark()
	 * @see IOException
	 */

	virtual void reset();

	/**
	 * Skips over and discards <CODE>n</CODE> bytes of data from this input 
     * stream. The <CODE>skip</CODE> method may, for a variety of reasons, end up 
	 * skipping over some smaller number of bytes, possibly <CODE>0</CODE>. This may 
	 * result from any of a number of conditions; reaching end of file before 
	 * <CODE>n</CODE> bytes have been skipped is only one possibility. The actual 
	 * number of bytes skipped is returned. If <CODE>n</CODE> is negative, no bytes 
	 * are skipped. 
	 * <P>
	 * The <CODE>skip</CODE> method of <CODE>InputStream</CODE> creates a byte 
	 * array and then repeatedly reads into it until <CODE>n</CODE> bytes have been 
	 * read or the end of the stream has been reached. Subclasses are encouraged to 
	 * provide a more efficient implementation of this method.
	 * </P>
	 * @return the actual number of bytes skipped.
	 * @param n the number of bytes to be skipped.
	 * @exception IOException if an I/O error occurs.
	 */

	virtual long skip(long n);

private:

	//
	// Hide copy constructor and assignment operator.
	//

	InputStream(const InputStream&);
	InputStream& operator=(const InputStream&);
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_INPUTSTREAM_H */
