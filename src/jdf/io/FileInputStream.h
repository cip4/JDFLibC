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

#ifndef I_JDF_FILEINPUTSTREAM_H
#define I_JDF_FILEINPUTSTREAM_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include "RandomAccessInputStream.h"


namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 
	class WString;
	class File;

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
 * A <code>FileInputStream</code> obtains bytes from a file in a file system.
 * What files are available depends on the host environment.
 *
 * @author nverbove
 * @see File
 * @see FileOutputStream
 * @ingroup io
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT FileInputStream : public RandomAccessInputStream
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	FileInputStream();
	/**
	 * Creates a <code>FileInputStream</code> by opening a connection to an actual file,
	 * the file named by the <code>File</code> object <code>f</code> in the file system.
	 *
	 * If the named file does not exist, is a directory rather than a regular file, or for
	 * some other reason cannot be opened for reading then a <code>FileNotFoundException</code> is
	 * thrown.
	 *
	 * @param f the file to be opened for reading
	 * @exception FileNotFoundExcepton if the file does not exist, is a directory rather than
	 * a regular file, or for some reason cannot be opened for reading.
	 * @see File#getPath()
	 */

	explicit FileInputStream(File& f);

	/**
	 * Creates a <code>FileInputStream</code> by opening a connection to an actual file,
	 * the file named by the path name <code>name</code> in the file system.
	 * <p>
	 * If the named file does not exist, is a directory rather than a regular file, or for
	 * some other reason cannot be opened for reading then a <code>FileNotFoundException</code> is
	 * thrown.
	 * @param name the system-dependent file name.
	 * @exception FileNotFoundExcepton if the file does not exist, is a directory rather than
	 * a regular file, or for some reason cannot be opened for reading.
	 */
	FileInputStream(const WString& fileName);
	FileInputStream(const char* const fileName);
	FileInputStream(const JDFCh* const fileName);
	FileInputStream(JDFFileHandle handle);

/*@}*/ 

	void open(File& file);
	void open(const WString& fileName);
	void open(const char* const fileName);
	void open(const JDFCh* const fileName);
	void open(JDFFileHandle handle);

	/**
	 * Ensures that the <code>close</code> method of this file input stream is called when there
	 * are no more references to it.
	 * 
	 * @exception IOException if an I/O error occurs.
	 * @see close()
	 */

	virtual ~FileInputStream();

	/**
	 * Returns the number of bytes that can be read from this file input stream without blocking
	 * 
	 * @return the number of bytes that can be read from this file input stream without blocking
	 * @exception IOException if an I/O error occurs.
	 */

	int  available();

	/** 
	 * Closes this file input stream and releases any system resources associated with the stream.
	 * @exception IOException if an I/O error occurs.
	 */

	void close();

	/**
	 * Skips over and discards <code>n</code> bytes of data from the input stream. 
	 * The <code>skip</code> method may, for a variety of reasons, end up skipping over some
	 * smaller number of bytes, possibly 0. The actual number of bytes skipped is returned.
	 * 
	 * @param n the number of bytes to be skipped.
	 * @return the actual number of bytes skipped
	 * @exception IOException if an I/O error occurs.	 
	 */

	long skip(long n);

	/**
	 * Reads a byte of data from this input stream. This method blocks if no input is
	 * yet available.
	 * 
	 * @return the next byte, or <code>-1</code> if the end of the file is reached.
	 * @exception IOException of an I/O error occurs.
	 */

	int  read();

	/**
	 * Reads up to <code>blen</code> bytes of data from this input stream into an array of bytes.
	 * This method blocks until some input is available
	 *
	 * @param b the buffer into which the data is read.
	 * @param blen the size of the buffer
	 * @return the total number of bytes read into the buffer, or <code>-1</code> if there 
	 * is no more data because the end of file has been reached.
	 * @exception IOException if an I/O error occurs.	 
	 */

	int  read(char* b, int blen);

	/**
	 * Reads up to <code>len</code> from this input stream into an array of bytes.
	 * This method blocks until some input is available.
	 *
	 * @param b the buffer into which the data is read.
	 * @param blen the size of the buffer.
	 * @param off the start offset of the data.
	 * @param len the maximum number of bytes read
	 * @return the total number of bytes read into the buffer, or <code>-1</code> if there 
	 * is no more data because the end of file has been reached.
	 * @exception IOException if an I/O error occurs.	 
	 */

	int  read(char* b, int blen, int off, int len);

	/**
	 * See the general contract of the <code>mark</code> method of <code>InputStream</code>.
	 * The parameter <code>readAheadLimit</code> is ignored. 
	 * 
	 * @param readAheadLimit the maximum limit of bytes that can be read before the mark position becomes invalid.
	 * @see FileInputStream#reset
	 * @see InputStream#mark
	 */

	void mark(int readlimit);

	/**
	 * Tests if this input stream supports the <code>mark</code> and <code>reset</code> methods. 
	 * The <code>markSupported</code> method of <code>FileInputStream</code> returns <code>true</code>.
	 * 
	 * @return a boolean indicating if this stream type supports the mark and reset methods.
	 * @see FileInputStream#mark
	 * @see FileInputStream#reset
	 */

	bool markSupported();

	/**
	 * See the general contract of the <code>reset</code> method of <code>InputStream</code>. 
	 * Resets the file input location to the last set mark. if no mark has been set
	 * the reset jumps to the start of the file.
	 * 
	 * @see FileInputStream#mark    
	 */

	void reset();

	bool seekSupported();
	JDFUInt64 length();
	JDFUInt64 seek(JDFUInt64 pos,int moveMethod);

private:

	FileHandle m_handle;
	unsigned int mMarkPosition;

};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_FILEINPUTSTREAM_H */


/* end of file */
