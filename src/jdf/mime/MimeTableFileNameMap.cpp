
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

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include "MimeTableFileNameMap.h"

#include "MIMEBasicPart.h"
#include "FileMIMEType.h"

#include <jdf/io/File.h>

#include <xercesc/util/XMLUniDefs.hpp>


XERCES_CPP_NAMESPACE_USE

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

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

// TODO 
// the table should come from a file

FileMIMEType MimeTableFileNameMap::getContentTypeFor(const WString& fileName)
{
	FileMIMEType fmt;
	WString      filename;
	WString      extn;

	// get extension
	filename = fileName.trim();
	int i = filename.find_last_of(chPound); //'#'
	if (i > 0)
		filename = filename.substring(0,i-1);

	i = filename.find_last_of(chPeriod); // '.'

	int tmp = filename.find_last_of(chForwardSlash);
	i = (i<tmp ? tmp : i);
	tmp = filename.find_last_of(chQuestion);
	i = (i<tmp ? tmp : i);
	
	if (i != -1 && fileName[i] == chPeriod)
		extn = filename.substr(i+1,filename.length()-i).toUpperCase();

	fmt.file_extn = extn;

	// get shortname
	File f(fileName);
	fmt.file_shortname = f.getName();

	if (extn.equalsIgnoreCase("txt") || extn.equalsIgnoreCase("java")||
		extn.equalsIgnoreCase("c")   || extn.equalsIgnoreCase("C")   ||
		extn.equalsIgnoreCase("cc")  || extn.equalsIgnoreCase("CC")  ||
		extn.equalsIgnoreCase("h")   || extn.equalsIgnoreCase("hxx") ||
		extn.equalsIgnoreCase("bat") || extn.equalsIgnoreCase("rc")  ||
		extn.equalsIgnoreCase("ini") || extn.equalsIgnoreCase("cmd") ||
		extn.equalsIgnoreCase("awk") || extn.equalsIgnoreCase("html")||
		extn.equalsIgnoreCase("sh")  || extn.equalsIgnoreCase("ksh") ||
		extn.equalsIgnoreCase("pl")  || extn.equalsIgnoreCase("DIC") ||
		extn.equalsIgnoreCase("EXC") || extn.equalsIgnoreCase("LOG") ||
		extn.equalsIgnoreCase("SCP") || extn.equalsIgnoreCase("WT")  ||
		extn.equalsIgnoreCase("mk")  || extn.equalsIgnoreCase("htm"))
	{
		fmt.content_type = MIMEBasicPart::TEXT;
		if (extn.equalsIgnoreCase("html") || extn.equalsIgnoreCase("htm"))
			fmt.content_subtype = JDFStrL("html");
		else
			fmt.content_subtype = JDFStrL("plain");
		fmt.content_params = JDFStrL("us-ascii");
		fmt.mime_encoding = MIMEBodyPart::E7BIT;
	}
	else if (extn.equalsIgnoreCase("xml"))
	{
		fmt.content_type    = MIMEBasicPart::APPLICATION;
		fmt.content_subtype = JDFStrL("xml");
		fmt.mime_encoding = MIMEBodyPart::QP;
	}
	else if (extn.equalsIgnoreCase("pdf"))
	{
		fmt.content_type    = MIMEBasicPart::APPLICATION;
		fmt.content_subtype = JDFStrL("pdf");
	}
	else if (extn.equalsIgnoreCase("AIF") || extn.equalsIgnoreCase("AIFC") ||
		     extn.equalsIgnoreCase("AIFF"))
	{
		fmt.content_type    = MIMEBasicPart::AUDIO;
		fmt.content_subtype = JDFStrL("aiff");
	}
	else if (extn.equalsIgnoreCase("AU") || extn.equalsIgnoreCase("SND"))
	{
		fmt.content_type    = MIMEBasicPart::AUDIO;
		fmt.content_subtype = JDFStrL("basic");
	}
	else if (extn.equalsIgnoreCase("WAV"))
	{
		fmt.content_type    = MIMEBasicPart::AUDIO;
		fmt.content_subtype = JDFStrL("wav");
	}
	else if (extn.equalsIgnoreCase("gif"))
	{
		fmt.content_type    = MIMEBasicPart::IMAGE;
		fmt.content_subtype = JDFStrL("gif");
	}
	else if (extn.equalsIgnoreCase("jpg"))
	{
		fmt.content_type    = MIMEBasicPart::IMAGE;
		fmt.content_subtype = JDFStrL("jpeg");
	}
	else if (extn.equalsIgnoreCase("jpeg"))
	{
		fmt.content_type    = MIMEBasicPart::IMAGE;
		fmt.content_subtype = JDFStrL("jpeg");
	}
	else if (extn.equalsIgnoreCase("tif") || extn.equalsIgnoreCase("tiff"))
	{
		fmt.content_type    = MIMEBasicPart::IMAGE;
		fmt.content_subtype = JDFStrL("tiff");
	}
	else if (extn.equalsIgnoreCase("xbm"))
	{
		fmt.content_type    = MIMEBasicPart::IMAGE;
		fmt.content_subtype = JDFStrL("x-xbitmap");
	}
	else if (extn.equalsIgnoreCase("png"))
	{
		fmt.content_type    = MIMEBasicPart::IMAGE;
		fmt.content_subtype = JDFStrL("png");
	}
	else if (extn.equalsIgnoreCase("avi"))
	{
		fmt.content_type    = MIMEBasicPart::VIDEO;
		fmt.content_subtype = JDFStrL("avi");
	}
	else if (extn.equalsIgnoreCase("mpeg"))
	{
		fmt.content_type    = MIMEBasicPart::VIDEO;
		fmt.content_subtype = JDFStrL("mpeg");
	}
	else if (extn.equalsIgnoreCase("ps") || extn.equalsIgnoreCase("EPS"))
	{
		fmt.content_type    = MIMEBasicPart::APPLICATION;
		fmt.content_subtype = JDFStrL("postscript");
	}
	else if (extn.equalsIgnoreCase("tar"))
	{
		fmt.content_type    = MIMEBasicPart::APPLICATION;
		fmt.content_subtype = JDFStrL("x-tar");
	}
	else if (extn.equalsIgnoreCase("zip"))
	{
		fmt.content_type    = MIMEBasicPart::APPLICATION;
		fmt.content_subtype = JDFStrL("zip");
	}
	else if (extn.equalsIgnoreCase("js"))
	{
		fmt.content_type    = MIMEBasicPart::APPLICATION;
		fmt.content_subtype = JDFStrL("x-javascript");
	}
	else if (extn.equalsIgnoreCase("doc"))
	{
		fmt.content_type    = MIMEBasicPart::APPLICATION;
		fmt.content_subtype = JDFStrL("msword");
	}
	else if (extn.equalsIgnoreCase("nsc"))
	{
		fmt.content_type    = MIMEBasicPart::APPLICATION;
		fmt.content_subtype = JDFStrL("x-conference");
	}
	else if (extn.equalsIgnoreCase("rtf"))
	{
		fmt.content_type    = MIMEBasicPart::APPLICATION;
		fmt.content_subtype = JDFStrL("rtf");
	}
	else if (extn.equalsIgnoreCase("ARC") || extn.equalsIgnoreCase("ARJ") || 
		     extn.equalsIgnoreCase("B64") || extn.equalsIgnoreCase("BHX") ||
			 extn.equalsIgnoreCase("GZ")  || extn.equalsIgnoreCase("HQX"))
	{
		fmt.content_type    = MIMEBasicPart::APPLICATION;
		fmt.content_subtype = JDFStrL("x-gzip");
	}
	else if (extn.equalsIgnoreCase("jdf"))
	{
		fmt.content_type    = MIMEBasicPart::APPLICATION;
		fmt.content_subtype = JDFStrL("vnd.cip4-jdf+xml");
	}
	else if (extn.equalsIgnoreCase("jmf"))
	{
		fmt.content_type    = MIMEBasicPart::APPLICATION;
		fmt.content_subtype = JDFStrL("vnd.cip4-jmf+xml");
	}

	else 
	{
		fmt.content_type    = MIMEBasicPart::APPLICATION;
		fmt.content_subtype = JDFStrL("octet-stream");
	}
	return fmt;
}



/*









	if (ext == ".saveme" || ext == ".dump" || ext == ".hqx" || ext == ".arc" ||
		ext == ".obj" || ext == ".lib" || ext == ".bin" || ext == ".exe" || 
		ext == ".zip" || ext == ".gz")
		return "application/octet-stream";

	if (ext == ".oda")
		return "application/oda";

	if (ext == ".pdf")
		return "application/pdf";

	if (ext == ".eps" || ext == ".ai" || ext == ".ps")
		return "application/postscript";

	if (ext == ".rtf")
		return "application/rtf";

	if (ext == ".dvi")
		return "application/x-dvi";

	if (ext == ".hdf")
		return "application/x-hdf";

	if (ext == ".latex")
		return "application/x-tex";

	if (ext == ".texinfo" || ext == ".texi")
		return "application/x-texinfo";

	if (ext == ".t" || ext == ".tr" || ext == ".roff")
		return "application/x-troff";

	if (ext == ".man")
		return "application/x-troff-man";

	if (ext == ".me")
		return "application/x-troff-me";

	if (ext == ".ms")
		return "application/x-troff-ms";

	if (ext == ".src" || ext == ".wsrc")
		return "application/x-wais-source";

	if (ext == ".zip")
		return "application/zip";

	if (ext == ".bcpio")
		return "application/x-bcpio";

	if (ext == ".cpio")
		return "application/x-cpio";

	if (ext == ".gtar")
		return "application/x-gtar";

	if (ext == ".sh" || ext == ".shar")
		return "application/x-shar";

	if (ext == ".sv4cpio")
		return "application/x-sv4cpio";

	if (ext == ".sv4crc")
		return "application/x-sv4crc";

	if (ext == ".tar")
		return "application/x-tar";

	if (ext == ".ustar")
		return "application/x-ustar";

	if (ext == ".snd" || ext == ".au")
		return "audio/basic";

	if (ext == ".aifc" || ext == ".aif" || ext == ".aiff")
		return "audio/x-aiff";

	if (ext == ".wav")
		return "audio/x-wav";

	if (ext == ".tif" || ext == ".tiff")
		return "image/tiff";

	if (ext == ".fpx" || ext == ".fpix")
		return "image/vnd.fpx";

	if (ext == ".ras")
		return "image/x-cmu-rast";

	if (ext == ".pnm")
		return "image/x-portable-anymap";

	if (ext == ".pbm")
		return "image/x-portable-bitmap";

	if (ext == ".pgm")
		return "image/x-portable-graymap";

	if (ext == "rgb")
		return "image/x-rgb";

	if (ext == ".xbm" || ext == ".xpm")
		return "image/x-xbitmap";

	if (ext == "xwd")
		return "image/x-xwindowdump";

	if (ext == ".png")
		return "image/png";

	if (ext == ".htm" || ext == ".html")
		return "text/html";

	if (ext == ".text" || ext == ".c" || ext == ".cc" || ext == ".c++"
		|| ext == ".h" || ext == ".cpp" || ext == ".pl" || ext == ".txt" ||
		ext == ".java" || ext == ".el")
		return "text/plain";

	if (ext == ".tsv")
		return "text/tab-separated-values";

	if (ext == ".etx")
		return "text/x-setext";

	if (ext == ".mpg" || ext == ".mpe" || ext == ".mpeg")
		return "video/mpeg";

	if (ext == ".mov" || ext == ".qt")
		return "video/quicktime";

	if (ext == ".avi")
		return "application/x-troff-msvideo";

	if (ext == ".movie" || ext == ".mv")
		return "video/x-sgi-movie";

	if (ext == ".mime")
		return "message/rfc822";

	if (ext == ".xml")
		return "application/xml";

	return ext;
}
*/

} // namespace JDF
