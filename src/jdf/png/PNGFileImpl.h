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

#include <png.h>
#include <jdf/png/PNGInfo.h>
#include <jdf/io/InputStream.h>
#include <jdf/io/OutputStream.h>

namespace JDF
{

class JDFTOOLS_EXPORT PNGFileImpl
{
public:

	PNGFileImpl();

	void open(InputStream&  in);
	void open(OutputStream& out, const PNGInfo& info);

	void*     allocRow();
	void**    allocRows(unsigned long number);
	void*     allocImage();
	
	PNGInfo& getInfo();

	bool readImage(void  *&data);
	bool readRows (void **&data, unsigned long number);
	bool readRow  (void  *&data);

	bool writeImage    (void  *data);
	bool writeImageRows(void **data, unsigned long number);
	bool writeRow      (void  *data);

	void close();

protected:

	InputStream*  input;
	OutputStream* output;

	PNGInfo       pngInfo;               // Png Parametrs
	unsigned long m_rowsReady;           // Number of rows already read
	bool          m_Info;                // true = Png Header already exist

	png_structp   png_ptr;               // Need for png-library
	png_infop     info_ptr;              // Need for png-library

private:
	bool   init_read();
	bool   init_write();

	void   close_input();
	void   close_output();

	void** make_Rows_from_Image(void *image);

	static void my_read_data( png_structp png_ptr, 
							  png_bytep   data, 
							  png_size_t  length);

	static void my_error_fn(  png_structp png_ptr,
							  png_const_charp error_msg);

	static void my_warning_fn(png_structp png_ptr,
							  png_const_charp warning_msg);


    static void my_write_data(png_structp png_ptr,
							  png_bytep data, 
							  png_size_t length);
    
	static void my_flush_data(png_structp png_ptr);
};

} // namespace JDF
