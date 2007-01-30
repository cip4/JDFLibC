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

#ifndef I_JDF_URLENCODER_H
#define I_JDF_URLENCODER_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <jdf/lang/JDFToolsDefs.h>


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
 * The class contains a utility method for converting a
 * WString into a MIME format called
 * "<code>x-www-form-urlencoded</code>" format.
 * <p>
 * Differences between local operating systems can cause problems with URLs.
 * For example, some operating systems allow spaces in filenames; URLs don't.
 * Most operating systems won't complain about a '#' sign in a filename; in a
 * To convert a WString, each character is examined in turn:
 * <ul>
 * <li>The ASCII characters '<code>a</code>' through '<code>z</code>',
 *     '<code>A</code>' through '<code>Z</code>', '<code>0</code>'
 *     through '<code>9</code>', and &quot;.&quot;, &quot;-&quot;, 
 * &quot;*&quot;, &quot;_&quot; remain the same.
 * <li>The space character '<code>' '</code>' is converted into a
 *     plus sign '<code>+</code>'.
 * <li>All other characters are converted into the 3-character string
 *     "<code>%<i>xy</i></code>", where <i>xy</i> is the two-digit
 *     hexadecimal representation of the lower 8-bits of the character.
 * </ul>
 * <p>
 * The URLEncoder class consists of a single static method encode() that
 * encodes a WString according to these rules, changing any non-alphanumeric
 * characters (except the space and underscore characters) into % sequences.
 *
 * @author nverbove
 * @ingroup net
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT URLEncoder
{
public:

    /**
     * Translates a string into <code>x-www-form-urlencoded</code> format.
     *
     * @param   s  WString to be translated.
     * @return  the translated WString.
     */
	static WString encode(WString s);

	static WString encodePath(const WString& path);

	static WString encodePath(const File& path);

	/**
     * You can't call the constructor.
     */
	URLEncoder();
};

/** @example TestURLEncoder.cpp
 * This examples demonstrates using URLEncoder to create a query string class
 * for posting data to CGI programs.
 * A CGI query string is composed of successive name+value pairs.
 * You separate names from values by an equal sign (=), and
 * successive pairs by an ampersand (&).
 */

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_URLENCODER_H */

