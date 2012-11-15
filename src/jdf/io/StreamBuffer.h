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
 *                     Copyright 2000 Agfa-Gevaert N.V.                       *
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

#ifndef I_JDF_STREAMBUFFER_H
#define I_JDF_STREAMBUFFER_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 


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

#include <jdf/lang/JDFToolsDefs.h>

#include <iostream>


namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 
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
 * Implementation of a streambuf based on JDF Input/OutputStreams. 
 * The <code>StreamBuffer</code> is a bridge from JDF streaming classes  to C++ streams. 
 * By creating a <code>StreamBuffer</code> object you can pass
 * the streambuf object to an istream or ostream.
 * The <code>StreamBuffer</code> will map the C++ streaming on the <code>InputStream</code>/<code>OutputStream</code>
 * methods.
 * <p>
 * Here is one example of using StreamBuffer on a Socket
 * <p><blockquote><pre>
 * Socket s;
 * 
 * // create a StreamBuffer for our Socket
 * StreamBuffer strbuf(s,getInputStream(),s.getOutputStream());
 * // create an ostream using the streambuf
 * ostream os(&strbuf);
 * // create an istream using the streambuf
 * istream is(&strbuf);
 * </pre></blockquote><p>
 * The In/OutputStream of the Socket are used to create an istream and ostream
 * using the StreamBuffer object.
 * 
 * @author nverbove   
 * @ingroup io
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT StreamBuffer : public std::streambuf
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * Create a new <code>StreamBuffer</code> object with an <code>InputStream</code> and <code>OutputStream</code>.
	 * <p>
	 * The <code>StreamBuffer</code> will read its input from <code>in</code> and write its output
	 * to <code>out</code>. This <code>StreamBuffer</code> can be passed as an argument 
	 * to an <code>istream</code> and/or an <code>ostream</code>.
	 * 
	 * @param in <code>InputStream</code> for this streambuf.
	 * @param out <code>OutputStream</code> for this streambuf.
	 * @see InputStream
	 * @see OutputStream
	 */

	StreamBuffer(InputStream& in, OutputStream& out);

	/**
	 * Create a new <code>StreamBuffer</code> object with an <code>InputStream</code>.
	 * <p>
	 * The <code>StreamBuffer</code> will read its input from <code>in</code>.
	 * It can only be used for reading, and thus can be passed as an argument to
	 * an <code>istream</code>. When used with an ostream it will always flag EOF.
	 * 
	 * @param in <code>InputStream</code> for this streambuf.
	 * @see InputStream
	 */

	StreamBuffer(InputStream& in);

	/**
	 * Create a new <code>StreamBuffer</code> object with an <code>OutputStream</code>.
	 * <p>
	 * The <code>StreamBuffer</code> will write its output to <code>out</code>.
	 * It can only be used for writing, and thus can be passed as an argument to
	 * an <code>ostream</code>. When used with an istream it will always flag EOF.
	 * 
	 * @param out <code>OutputStream</code> for this streambuf.
	 * @see OutputStream
	 */

	StreamBuffer(OutputStream& out);

/*@}*/ 

protected:

	///////////////////////////////////////////////////////////////////////////
	// Protected Instance Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Fill the streambuffer.
	 * Called by the C++ istream when the streambuf get area is empty, i.e.
	 * there are no more available bytes in the streambuf input buffer.
	 * The <code>StreamBuffer</code> must be constructed with an <code>InputStream</code>.	  	
	 * This method will return the following results:
	 * <UL>
	 * <LI> <code>EOF</code>, if there isn't a connected <code>InputStream</code>. This will happen when the <code>StreamBuffer</code> has not been constructed with an <code>InputStream</code>.
	 * <LI> <code>EOF</code>, if the connected <code>InputStream</code> returns <code>-1</code>, meaning <code>EOF</code>.
	 * <LI> <code>EOF</code>, if the connected <code>InputStream</code> throws an <code>IOException</code>.
	 * <LI> <code>0</code>, if the <code>InputStream</code> throws an <code>InterruptedIOException</code>. 
	 * meaning <code>0</code> bytes have been read. </LI></UL>
	 * 
	 * @return <code>EOF</code> when there isn't a connected <code>InputStream</code>, the connected <code>InputStream</code> returns -1 or throws an IOException. If the <code>InputStream</code> throws an <code>InterruptedIOException</code> then <code>0</code> is returned meaning <code>0</code> bytes have been read.
	 * @see InputStream
	 */

	virtual int		underflow(void);

	/**
	 * Empty the streambuffer.
	 * Called by the C++ ostream when the streambuf put area is full, i.e.
	 * when the stream output buffer is full.
	 * The <code>StreamBuffer</code> must be constructed with an <code>OutputStream</code>.	  	
	 * This method will return the following results:
	 * <UL>
	 * <LI> <code>EOF</code>, if there isn't a connected <code>OutputStream</code>. This will happen when the <code>StreamBuffer</code> has not been constructed with an <code>OutputStream</code>.
	 * <LI> <code>EOF</code>, if the connected <code>OutputStream</code> throws an IOException.
	 * <LI> <code>0</code>, if the write to the <code>OutputStream</code> is successful.
	 * <LI> <code>0</code>, if the <code>OutputStream</code> throws an <code>InterruptedIOException</code>.
	 * If <code>InterruptedIOException</code> is thrown the put area of the streambuf
	 * is unchanged, it is still full.
	 * </LI></UL>
	 * 
	 * @return <code>EOF</code> when there isn't a connected <code>OutputStream</code> or when an IOException is thrown; returns <code>0</code> when the output is successful or when an <code>InterruptedIOException</code> is thrown.
	 * @param c the character to output or <code>EOF</code>. If not EOF, this character is put into the output buffer so that it will be consumed on the next call to <code>overflow</code> or <code>sync</code>.
	 * @see OutputStream    
	 */

	virtual int		overflow(int c=EOF);

	/**
	 * Flushes the put area. 
	 * It also empties the get area and, in the process,
	 * sends any unprocessed characters back to the source, if necessary.
	 * @return <code>0</code> if the get area is empty and there are no more characters to output; otherwise; it returns <b>EOF</b>.
	 */

	virtual int		sync();

	///////////////////////////////////////////////////////////////////////////
	// Protected Instance Variables
	///////////////////////////////////////////////////////////////////////////

	/**
	 * buffer for input data.
	 */

	char	gbuf[4096];

	/**
	 * buffer for output data.
	 */

	char	pbuf[4096];

	/**
	 * <code>InputStream</code> for this streambuf; or <code>NULL</code> if no <code>InputStream</code> available.
	 */

	InputStream*  mInputStream;

	/**
	 * <code>OutputStream</code> for this streambuf; or <code>NULL</code> if no <code>OutputStream</code>. available.
	 */

	OutputStream* mOutputStream;

private:

	//
	// Hide copy constructor and assignment operator.
	//

	StreamBuffer(const StreamBuffer&);
	StreamBuffer& operator=(const StreamBuffer&);
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_STREAMBUFFER_H */
