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

#ifndef I_JDF_UNICODE_H
#define I_JDF_UNICODE_H


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
 * Static commonly used Unicode strings.
 * @ingroup util
 */
class JDFTOOLS_EXPORT Unicode
{
public:

	static const JDFCh THROWABLE_NAME[];
	static const JDFCh EXCEPTION_NAME[];
	static const JDFCh ERROR_NAME[];
	static const JDFCh RUNTIMEEXCEPTION_NAME[];
	static const JDFCh ILLEGALARGUMENTEXCEPTION_NAME[];
	static const JDFCh NULLPOINTEREXCEPTION_NAME[];
	static const JDFCh INTERNALERROR_NAME[];
	static const JDFCh OUTOFMEMORYERROR_NAME[];
	static const JDFCh ILLEGALACCESSERROR_NAME[];
	static const JDFCh ILLEGALSTATEEXCEPTION_NAME[];
	static const JDFCh INDEXOUTOFBOUNDSEXCEPTION_NAME[];	
	static const JDFCh ARRAYINDEXOUTOFBOUNDSEXCEPTION_NAME[];
	static const JDFCh IOEXCEPTION_NAME[];
	static const JDFCh INTERRUPTEDIOEXCEPTION_NAME[];
	static const JDFCh FILENOTFOUNDEXCEPTION_NAME[];
	static const JDFCh EOFEXCEPTION_NAME[];
	static const JDFCh CESTREAMEXHAUSTED_NAME[];
	static const JDFCh CEFORMATEXCEPTION_NAME[];
	static const JDFCh SOCKETEXCEPTION_NAME[];
	static const JDFCh PIPEEXCEPTION_NAME[];
	static const JDFCh BINDEXCEPTION_NAME[];
	static const JDFCh CONNECTEXCEPTION_NAME[];
	static const JDFCh NOROUTETOHOSTEXCEPTION_NAME[];
	static const JDFCh UNKNOWNHOSTEXCEPTION_NAME[];
	static const JDFCh MALFORMEDURLEXCEPTION_NAME[];
	static const JDFCh DIGESTEXCEPTION_NAME[];
	static const JDFCh PROTOCOLEXCEPTION_NAME[];
	static const JDFCh UNKNOWNSERVICEEXCEPTION_NAME[];
	static const JDFCh NOSUCHELEMENTEXCEPTION_NAME[];
	static const JDFCh PLATFORMUTILSEXCEPTION_NAME[];
	static const JDFCh MIMEEXCEPTION_NAME[];
	static const JDFCh MIMECONTENTTYPETEXT[];
	static const JDFCh MIMECONTENTTYPEAUDIO[];
	static const JDFCh MIMECONTENTTYPEIMAGE[];
	static const JDFCh MIMECONTENTTYPEVIDEO[];
	static const JDFCh MIMECONTENTTYPEAPPLICATION[];
	static const JDFCh MIMEENCODINGBASE64[];
	static const JDFCh MIMEENCODINGQP[];
	static const JDFCh MIMEENCODING7BIT[];
	static const JDFCh MIMEENCODING8BIT[];
	static const JDFCh MIMEENCODINGBINARY[];
	static const JDFCh MIMEDISPATTACHMENT[];
	static const JDFCh MIMEDISPINLINE[];
	static const JDFCh MIMEMESSAGE[];
	static const JDFCh MIMEMULTIPART[];
	static const JDFCh URLCONTENTENCODING[];
	static const JDFCh URLCONTENTLENGTH[];
	static const JDFCh URLCONTENTTYPE[];
	static const JDFCh URLCONTENTTYPEHTML[];
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_UNICODE_H */
