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

#ifndef I_JDF_FILEOUTPUTSTREAM_H
#define I_JDF_FILEOUTPUTSTREAM_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include "RandomAccessOutputStream.h"

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
 * A file output stream is an output stream for writing data to a <code>File</code>
 * What files are available or may be created depends on the host environment.
 *
 * @author nverbove
 * @see File
 * @see FileInputStream
 * @ingroup io
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT FileOutputStream : public RandomAccessOutputStream
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	FileOutputStream();

	/**
	 * Creates a file output stream to write to the file represented by the
	 * specified <code>File</code> object.
	 * <p>
	 * If the file exists but is a directory rather than a regular file, does
	 * not exist or cannot be created, or cannot be opened for any other reason
	 * then a <code.FileNotFoundException</code> is thrown.
	 * 
	 * @param file the file to be opened for writing
	 * @exception FileNotFoundException if the file exists but is a directory rather 
	 * than a regular, does not exist but cannot be created, or cannot be opened for
	 * any other reason.
	 * @see File#getPath()
	 */

	FileOutputStream(File file);

	/**
	 * Creates an output file stream to write to the file with the specified name.
	 * <p>
	 * If the file exists but is a directory rather than a regular file, does
	 * not exist or cannot be created, or cannot be opened for any other reason
	 * then a <code.FileNotFoundException</code> is thrown.
	 * 
	 * @param fileName the system-dependent filename
	 * @exception FileNotFoundException if the file exists but is a directory rather 
	 * than a regular, does not exist but cannot be created, or cannot be opened for
	 * any other reason.
	 */

	FileOutputStream(const WString& fileName);
	FileOutputStream(const char* const fileName);
	FileOutputStream(const JDFCh* const fileName);
	FileOutputStream(JDFFileHandle handle);

/*@}*/ 

	void open(File file);
	void open(const WString& fileName);
	void open(const char* const fileName);
	void open(const JDFCh* const fileName);
	void open(JDFFileHandle handle);

	/**
	 * Cleans up the connection to the file, and ensures that the <code>close</close>
	 * method fo this file output stream is called.
	 */

	virtual ~FileOutputStream();

	/**
	 * Closes this file output stream and releases any system resources associated with
	 * this stream. This file output stream may no longer be used for writing bytes.
	 *
	 * @exception IOException if an I/O error occurs.
	 */

	void close();

	/**
	 * Writes the specified byte to this file output stream. Implements the <code>write</code>
	 * method of <code>OutputStream</code>.
	 *
	 * @param b the byte to be written
	 * @exception IOException if an I/O error occurs.
	 */

	void write(int c);
	void write(const char* b, int blen);
	void write(const char* b, int blen, int off, int len);
	void flush();
	bool seekSupported();
	JDFUInt64 length();
	JDFUInt64 seek(JDFUInt64 pos,int moveMethod);

private:

	JDFFileHandle m_handle;
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_FILEOUTPUTSTREAM_H */


/* end of file */
