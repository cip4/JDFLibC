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
*
******************************************************************************/

#ifndef I_JDF_BYTEARRAYINPUTSTREAM_H
#define I_JDF_BYTEARRAYINPUTSTREAM_H

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
	* A <code>ByteArrayInputStream</code> contains an internal buffer that
	* contains bytes that may be read from the stream. An internal counter 
	* keeps track of the next byte to be supplied by the read method. 
	*
	* @author nverbove
	* @ingroup io
	* @nosubgrouping
	*/
	
	class JDFTOOLS_EXPORT ByteArrayInputStream : public InputStream
	{
	public:
		
	/** 
	* @name Constructors
		*/
		/*@{*/
		
		/**
		* Creates a <code>ByteArrayInputStream</code> so that it uses buf as its buffer array.
		* The buffer array is not copied. The initial value of <code>mPos</code> is <code>0</code> and the 
		* initial value of <code>mCount</code> is <code>blen</code>.
		* 
		* @param buf the input buffer.
		* @param blen the size of the buffer.
		*/
		
	ByteArrayInputStream(char* buf, int blen, bool takeOwnership = false);
		
		/**
		* Creates a <code>ByteArrayInputStream</code> that uses buf as its buffer array.
		* The initial value of <code>mPos</code> is <code>off</code> and the
		* initial value of <code>mCount</code> is <code>off+len</code>. 
		* The buffer array is not copied. 
		* <p>
		* Note that if bytes are simply read from the resulting input stream, 
		* elements <code>buf[mPos]</code> through <code>buf[mPos+len-1]</code> will be read; 
		* however, if a <code>reset</code> operation is performed, 
		* then bytes buf[0] through buf[pos-1] will then become available for input.
		* 
		* @param buf the input buffer.
		* @param blen the size of the input buffer.
		* @param off the offset in the buffer of the first byte to read.
		* @param len the maximum number of bytes to read from the buffer.
		*/
		
	ByteArrayInputStream(char* buf, int blen, int off, int len, bool takeOwnership =false);
		
		/*@}*/ 
		
		/**
		* Destructs this character input stream.
		*/
		
		~ByteArrayInputStream();
		
		///////////////////////////////////////////////////////////////////////////
		// Public Instance Methods
		///////////////////////////////////////////////////////////////////////////
		
		/**
		* Returns the number of bytes that can be read from this input stream 
		* without blocking. The value returned is <code>count - pos</code>, 
		* which is the number of bytes remaining to be read from the input buffer.
		* 
		* @return the number of bytes that can be read from the input stream without blocking.
		*/
		
		int  available();
		
		/**
		* Closes this input stream and releases any system resources 
		* associated with the stream. 
		*/
		
		void close();
		
		/**
		* Set the current marked position in the stream. 
		* <code>ByteArrayInputStream</code> objects are marked at position 
		* zero by default when constructed. They may be marked at another 
		* position within the buffer by this method.
		* 
		* @param readAheadLimit the maximum limit of bytes that can be read before the mark position becomes invalid.
		*/
		
		void mark(int readAheadLimit);
		
		/**
		* Tests if ByteArrayInputStream supports mark/reset.
		*/
		
		bool markSupported();
		
		/**
		* Reads the next byte of data from this input stream. 
		* The value byte is returned as an int in the range <code>0</code> to <code>255</code>.
		* If no byte is available because the end of the stream has been reached,
		* the value <code>-1</code> is returned. 
		* This <code>read</code> method cannot block.
		* 
		* @return the next byte of data, or -1 if the end of the stream has been reached.
		*/
		
		int  read();
		
		/**
		* Reads up to <code>blen</code> bytes of data into an array of bytes from this input stream.
		* This method hs the same effect as calling <code>read(b,blen,0,blen)</code>.
		* 
		* @return the total number of bytes read into the buffer, or -1 if there is no more data because the end of the stream has been reached. 
		* @param b the buffer into which the data is read.
		* @param blen the size of the buffer.
		*/
		
		int  read(char* b, int blen);
		
		/**
		* Reads up to <code>len</code> bytes of data into an array of bytes from this input stream.
		* If <code>mPos</code> equals <code>mCount</code>, then <code>-1</code> is 
		* returned to indicate end of file. 
		* Otherwise, the number <code>k</code> of bytes read is equal to the 
		* smaller of <code>len</code> and <code>mCount-mPos</code>. 
		* If <code>k</code> is positive, 
		* then bytes <code>mBuf[mPos]</code> through <code>mBuf[pos+k-1]</code> 
		* are copied into <code>b[off]</code> through <code>b[off+k-1]</code>.
		* This read method cannot block.
		* 
		* @return the total number of bytes read into the buffer, or -1 if there is no more data because the end of the stream has been reached.
		* @param b the buffer into which the data is read.
		* @param blen the size of the buffer.
		* @param off the start offset of the data.
		* @param len the maximum number of bytes read.
		*/
		
		int  read(char* b, int blen, int off, int len);
		
		/**
		* Resets the buffer to the marked position. 
		* The marked position is the beginning unless another position 
		* was marked. The value of <code>mPos</code> is set to <code>0</code>.
		*/
		
		void reset();
		
		/**
		* Skips <code>n</code> bytes of input from this input stream. 
		* Fewer bytes might be skipped if the end of the input stream is reached. 
		* The actual number <code>k</code. of bytes to be skipped is equal to the smaller of 
		* <code>n</code> and <code>mCount-mPos</code>.
		* 
		* @return the actual number of bytes skipped.
		* @param n the number of bytes to be skipped.
		*/
		
		long skip(long n);
		
protected:
	
/**
* An array of bytes that was provided by the creator of the stream. 
* Elements <code>buf[0]</code> through <code>buf[mCount-1]</code> are
* the only bytes that can ever be read from the stream; 
* element <code>buf[mPos]</code> is the next byte to be read.
	*/
	
	char* mBuf;
	
	/**
	*The index one greater than the last valid character in the input stream
	* buffer. This value should always be nonnegative and not larger 
	* than the length of <code>mBuf</code>. It is one greater than the position of the
	* last byte within <code>mBuf</code> that can ever be read from the input stream buffer.
	*/
	
	int   mCount;
	
	/**
	* The currently marked position in the stream. CharArrayInputStream 
	* objects are marked at position zero by default when constructed. 
	* They may be marked at another position within the buffer by the <code>
	* mark()</code> method. The current buffer position is set to this point
	* by the <code>reset()</code> method.
	*/
	
	int   mMark;
	
	/**
	* The index of the next character to read from the input stream buffer.
	* This value should always be nonnegative and not larger than the value
	* of <code>mCount</code>. The next byte to be read from the input stream buffer will be 
	* <code>buf[pos]</code>.
	*/
	
	int	  mPos;
	
	/**
	* <code>true</code> if this stream has been closed; <code>false</code> otherwise.
	*/
	
	bool  mClosed;

	bool  mOwner;
};


/******************************************************************************
*	Prototypes
******************************************************************************/ 


/******************************************************************************
*	Implementation
******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_BYTEARRAYINPUTSTREAM_H */


/* end of file */
