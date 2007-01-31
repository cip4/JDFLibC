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

#include <jdf/png/PNGInfo.h>

namespace JDF
{

PNGInfo::png_time_class::png_time_class()
{
    year   =0;    
    month  =0;   
    day    =0;     
    hour   =0;    
    minute =0;  
    second =0;  
}

PNGInfo::png_time_class::png_time_class(const unsigned int year , const char month,
										 const char day,   const char hour,
										 const char minute, const char second)
{
    this->year   = year;    
    this->month  = month;   
    this->day    = day;     
    this->hour   = hour;    
    this->minute = minute;  
    this->second = second;  
}

PNGInfo::PNGInfo()
{
    m_imageWidth       = 0;
    m_imageHeight      = 0;
    m_bitDepth         = 0;
	m_xresolution      = 0;
	m_yresolution      = 0;
	m_modificationTime = PNGInfo::png_time_class();
}

PNGInfo::~PNGInfo()
{
}

PNGInfo& PNGInfo::operator = (const PNGInfo &info)
{
    m_imageWidth       = info.m_imageWidth;
    m_imageHeight      = info.m_imageHeight;
    m_bitDepth         = info.m_bitDepth;
	m_xresolution      = info.m_xresolution;
	m_yresolution      = info.m_yresolution;
	m_modificationTime = info.m_modificationTime;
	return *this;
}


unsigned long PNGInfo::rowSize() const 
{
	return ((m_imageWidth * 1 /*m_samplesPerPixel*/ * m_bitDepth+7)/8);
}

unsigned long PNGInfo::imageSize() const 
{
	return m_imageHeight * m_imageHeight ;
}


} // namespace JDF