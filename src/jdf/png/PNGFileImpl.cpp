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

#include <jdf/png/PNGFileImpl.h>

namespace JDF
{

PNGFileImpl::PNGFileImpl()
{
	input		= NULL;
	output		= NULL;
	m_rowsReady = 0;
	m_Info      = false;
}

void PNGFileImpl::open(OutputStream& out,const PNGInfo& info)
{
	if ( input || output ) 
		close();

	output      = &out;
	pngInfo     = info;
	m_rowsReady = 0;
	m_Info      = true;
	init_write();
}

bool PNGFileImpl::init_write()
{
	if ( !output || m_rowsReady ) 
		return false;
	
	if (pngInfo.m_bitDepth!=1 && pngInfo.m_bitDepth!=8) 
		return false;

    // prepare the standard PNG structures

    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL,
      (png_error_ptr)my_error_fn, (png_error_ptr)my_warning_fn);
    if (!png_ptr)
    {
		output->close();
        return false;
    }
    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
		output->close();
        png_destroy_write_struct(&png_ptr, (png_infopp) NULL);
        return false;
    }
    try
    { 
        // initialize the png structure
        png_set_write_fn(png_ptr, (png_voidp)output, my_write_data, my_flush_data);
        png_set_IHDR(png_ptr, info_ptr, pngInfo.m_imageWidth, pngInfo.m_imageHeight, pngInfo.m_bitDepth,
            PNG_COLOR_TYPE_GRAY, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE,
            PNG_FILTER_TYPE_BASE);
        
        // write the file header information
        png_write_info(png_ptr, info_ptr);
    }
    catch (...)
    {
		close_output();
    }
	m_Info = true;
    return true;
}

void PNGFileImpl::open(InputStream& in)
{
	if ( input || output ) 
		close();

	input       = &in;
	m_rowsReady = 0;
	m_Info      = false;
}

bool PNGFileImpl::init_read()
{

	if ( !input || m_Info ) 
		return false;
	
	// Read Signature from stream
    png_byte pbSig[8];
	input->read((char*)pbSig,8);
    if (!png_check_sig(pbSig, 8))
        return false;

    // create the two png(-info) structures
    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL,
      (png_error_ptr)my_error_fn, (png_error_ptr)my_warning_fn);
    if (!png_ptr)
        return false;

    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
    {
        png_destroy_read_struct(&png_ptr, NULL, NULL);
        return false;
    }

    try
    {
        
        // initialize the png structure
        png_set_read_fn(png_ptr, (png_voidp)input, my_read_data);
        
        png_set_sig_bytes(png_ptr, 8);
        
        // read all PNG info up to image data
        png_read_info(png_ptr, info_ptr);
        
        // get width, height, bit-depth and color-type
	    int ColorType;
        png_get_IHDR(png_ptr, info_ptr, &pngInfo.m_imageWidth, &pngInfo.m_imageHeight, (int*) &pngInfo.m_bitDepth,
            &ColorType, NULL, NULL, NULL);
        
		if (ColorType != PNG_COLOR_TYPE_GRAY)
			return false;

        //
		png_timep mod_time;
        if (png_get_tIME(png_ptr, info_ptr, &mod_time))
        {
			pngInfo.m_modificationTime=PNGInfo::png_time_class(
										mod_time->year, mod_time->month,  mod_time->day,
										mod_time->hour, mod_time->minute, mod_time->second);
        }

        if (png_get_pHYs(png_ptr, info_ptr, NULL, NULL, NULL))
        {
			pngInfo.m_xresolution = ((float)png_get_x_pixels_per_meter(png_ptr,
								            info_ptr)*.0254 +.5);
			pngInfo.m_yresolution = ((float)png_get_y_pixels_per_meter(png_ptr, 
								            info_ptr)*.0254 +.5);
			//float res_x = png_get_x_pixels_per_inch(png_ptr,info_ptr);
			//float res_y = png_get_y_pixels_per_inch(png_ptr,info_ptr);
        }

		// expand images of all color-type and bit-depth to 3x8 bit RGB images
        // let the library process things like alpha, transparency, background
/*        
        if (pngInfo.m_bitDepth == 16)
            png_set_strip_16(png_ptr);
        if (pngInfo.m_bitDepth < 8 && pngInfo.m_bitDepth > 1)
            png_set_packing(png_ptr);

		if (ColorType == PNG_COLOR_TYPE_PALETTE ||
			ColorType & PNG_COLOR_MASK_ALPHA)
			png_set_strip_alpha(png_ptr);

        if (ColorType == PNG_COLOR_TYPE_RGB ||
			ColorType == PNG_COLOR_TYPE_PALETTE ||
            ColorType == PNG_COLOR_TYPE_RGB_ALPHA)
            png_set_rgb_to_gray_fixed(png_ptr,1,NULL,-1);
        

        double screen_gamma = 2.0 ; // This is for PC; for MAC must be 1.7 or 1.0
		double gamma;

//		if (png_get_gAMA(png_ptr,info_ptr,&gamma))
//			  png_set_gamma(png_ptr,screen_gamma,gamma);
//		else  png_set_gamma(png_ptr,screen_gamma,0.45455);

        // after the transformations have been registered update *info_ptr data
        png_read_update_info(png_ptr, info_ptr);
        // get again width, height and the new bit-depth and color-type
        png_get_IHDR(png_ptr, info_ptr, &pngInfo.m_imageWidth, &pngInfo.m_imageHeight, (int*) &pngInfo.m_bitDepth,
            &ColorType, NULL, NULL, NULL);
*/
		//pngInfo.Channels  = png_get_channels(png_ptr, info_ptr);
        // row_bytes is the width x number of channels
//      pngInfo.m_bytesPerRow  = png_get_rowbytes(png_ptr, info_ptr); 
//		pngInfo.m_bytesPerRow *= sizeof(png_byte);
    }
    catch (.../*msg*/)
    {
        close_input();
    }
	m_Info = true;
    return true;
}

void* PNGFileImpl::allocRow()
{
	if ( !m_Info ) return NULL;
	return (void*) (new char[pngInfo.rowSize()]);
}

void** PNGFileImpl::allocRows(unsigned long number)
{
	if ( !m_Info ) return NULL;

	char** imageRows;
	imageRows = new char*[number];
	for(unsigned long i=0; i<number; i++)
		imageRows[i] = new char[pngInfo.rowSize()];

	return (void**) imageRows;
}

void* PNGFileImpl::allocImage()
{
	if ( !m_Info ) return NULL;
	return (void*) (new char[pngInfo.rowSize() * pngInfo.m_imageHeight]);
}

/*
void CPngFileImpl::set_AllocRead(bool flag )
{
	m_Alloc_before_read = flag;
}

void CPngFileImpl::set_FreeWrite(bool flag )
{
	m_Free_after_write = flag;
}
*/

void** PNGFileImpl::make_Rows_from_Image(void *image)
{
	if ( !m_Info ) return NULL;

	char** imageRows;
	imageRows = new char*[pngInfo.m_imageHeight];
	for(unsigned long i=0; i<pngInfo.m_imageHeight; i++)
		imageRows[i] = (char*)image + i * pngInfo.rowSize();

	return (void**) imageRows;

}

bool PNGFileImpl::readImage(void *&data)
{
	if ( !input || m_rowsReady) return false;
	
	if ( !m_Info ) init_read();

	void** imageRows;
	imageRows = make_Rows_from_Image(data);
	
	// now we can go ahead and just read the whole image
    png_read_image(png_ptr, (unsigned char**) imageRows);
	delete [] imageRows;

    // read the additional chunks in the PNG file (not really needed)
    png_read_end(png_ptr, NULL);

	m_rowsReady = pngInfo.m_imageHeight;
	close_input();

	return true;
}

bool PNGFileImpl::readRow(void *&data)
{
	if ( !input ) return false;
	
	if ( !m_Info ) init_read();

	if (m_rowsReady > pngInfo.m_imageHeight) return false;

	unsigned char* deb = (unsigned char*) data;

	png_read_row(png_ptr, (unsigned char*) data, NULL);
	

	m_rowsReady++;

	if (m_rowsReady==pngInfo.m_imageHeight) 
	{
        // read the additional chunks in the PNG file (not really needed)
        png_read_end(png_ptr, NULL);
		close_input();
	}
	
	return true;
}

bool PNGFileImpl::readRows(void **&data, unsigned long number)
{
	if ( !input ) return false;
	
	if ( !m_Info ) init_read();

	if (m_rowsReady > pngInfo.m_imageHeight) return false;

	unsigned long i = 0;

	while ( m_rowsReady < pngInfo.m_imageHeight )
	{
		data[i] = allocRow();	 
		png_read_row(png_ptr, (unsigned char*) data[i], NULL);
		m_rowsReady++;
		i++;
	}

	if (m_rowsReady==pngInfo.m_imageHeight) 
	{
        // read the additional chunks in the PNG file (not really needed)
        png_read_end(png_ptr, NULL);
		close_input();
	}
	return true;
}

bool PNGFileImpl::writeImage(void *data)
{
	if ( !output || m_rowsReady) return false;
	
	if ( !m_Info ) init_write();

	void** imageRows;
	imageRows = make_Rows_from_Image(data);

    png_write_image (png_ptr, (unsigned char**) imageRows);
    png_write_end(png_ptr, info_ptr);
	m_rowsReady = pngInfo.m_imageHeight;

	close_output();
	return true;
}

bool PNGFileImpl::writeImageRows(void **data, unsigned long number)
{
	if ( !output ) return false;
	
	if (m_rowsReady > pngInfo.m_imageHeight) return false;

	unsigned long i = 0;

	while ( m_rowsReady < pngInfo.m_imageHeight )
	{
		png_read_row(png_ptr, (unsigned char*) data[i], NULL);
		m_rowsReady++;
		i++;
	}

	if (m_rowsReady==pngInfo.m_imageHeight) 
	{
        // read the additional chunks in the PNG file (not really needed)
        png_write_end(png_ptr, info_ptr);
		close_output();
	}
	return true;
}


bool PNGFileImpl::writeRow(void *data)
{
	if ( !output ) return false;
	
	if ( !m_rowsReady ) init_write();

	if (m_rowsReady > pngInfo.m_imageHeight) return false;

	unsigned char* deb = (unsigned char*) data;
	
	png_write_row(png_ptr, (unsigned char*) data);
	
	m_rowsReady++;

	if (m_rowsReady==pngInfo.m_imageHeight) 
	{
		png_write_end(png_ptr, info_ptr);
		close_output();
		//outImage.clear_all_data();
	}

	return true;
}


void PNGFileImpl::close_output()
{
	if (png_ptr)
	{
		png_destroy_info_struct(png_ptr, &info_ptr);
        png_destroy_write_struct(&png_ptr, (png_infopp) NULL);
	}

	output->close();
	output = NULL;
}

void PNGFileImpl::close()
{
	if (input)
		close_input();
	if (output) 
		close_output();
}

void PNGFileImpl::close_input()
{
	if (!png_ptr)
	{
		png_destroy_info_struct(png_ptr, &info_ptr);
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	}
	input->close();
	input = NULL;
}

PNGInfo& PNGFileImpl::getInfo()
{
	if ( !m_Info && input) init_read();
	return pngInfo;
}

void PNGFileImpl::my_read_data(png_structp png_ptr, png_bytep data, png_size_t length)
{
  char *ptr=new char[length];
  InputStream* pSourceInfo=(InputStream*)png_get_io_ptr(png_ptr);
  pSourceInfo->read(ptr,length);
  memcpy(data,ptr,length);
  delete [] ptr;
}

void PNGFileImpl::my_error_fn
    ( png_structp png_ptr,
      png_const_charp error_msg
    )
{
  //raiseError (ERR_FORMAT_UNKNOWN, (char *)error_msg);
}

void PNGFileImpl::my_warning_fn
    ( png_structp png_ptr,
      png_const_charp warning_msg
    )
{
  //TRACE (warning_msg);
}

void PNGFileImpl::my_write_data(png_structp png_ptr,
				   png_bytep   data, 
				   png_size_t  length)
{
   OutputStream* pDestinationInfo=(OutputStream*)png_get_io_ptr(png_ptr);
   try {
     pDestinationInfo->write((char*)data,length);
   }
   catch(...) {
	   png_error(png_ptr, "Write Error");
   }
}

void PNGFileImpl::my_flush_data(png_structp png_ptr)
{
	int debug=true;
}

} // namespace JDF
