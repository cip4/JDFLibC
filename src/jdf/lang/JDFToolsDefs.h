#ifndef I_JDFTOOLSDEFS_H
#define I_JDFTOOLSDEFS_H
/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2014 The International Cooperation for the Integration of 
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


/******************************************************************************
 *	Includes
 ******************************************************************************/ 

// the XERCES platform Compiler headers takes care of all 
// platform specific settings

#include <jdf/util/myuti.h>

#include <xercesc/util/XercesDefs.hpp>

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 


/******************************************************************************
 *	Defines and constants
 ******************************************************************************/ 


/******************************************************************************
 *	Typedefs
 ******************************************************************************/ 

typedef unsigned char       JDFByte;
typedef XMLCh				JDFCh;

// need to inline xerces definition
typedef void* FileHandle; 
typedef FileHandle			JDFFileHandle;

// ---------------------------------------------------------------------------
//  Define unsigned 16 and 32 bits integers
// ---------------------------------------------------------------------------

typedef XMLUInt16  JDFUInt16;
typedef XMLUInt32  JDFUInt32;
#ifndef _WIN32
typedef unsigned long long JDFUInt64;
typedef long long JDFInt64;
#else
#pragma warning( disable : 4786 ) // long debug names from stl
#pragma warning( disable : 4804 ) // bool checking
#pragma warning( disable : 4996 ) // deprecated printf etc.
typedef unsigned __int64 JDFUInt64;
typedef __int64 JDFInt64;
#pragma warning( disable : 4251 ) // dll crap - 
#pragma warning( disable : 4275 ) // dll crap - exporting of private members

#ifndef _SSIZE_T_DEFINED
#ifdef  _WIN64
typedef __int64  ssize_t;
#else
typedef _W64 int  ssize_t;
#endif
#define _SSIZE_T_DEFINED
#endif

#endif



#ifndef _CRT_NON_CONFORMING_SWPRINTFS
#define _CRT_NON_CONFORMING_SWPRINTFS
#endif

#ifndef null
#define null 0
#endif


#define JDFStrL(str)  XMLStrL(str)

#ifndef PLATFORM_EXPORT
#define PLATFORM_EXPORT XERCES_PLATFORM_EXPORT
#endif

#ifndef PLATFORM_IMPORT
#define PLATFORM_IMPORT XERCES_PLATFORM_IMPORT
#endif

//@vigo
#if defined JDF_TOOLS
#define JDFTOOLS_EXPORT PLATFORM_EXPORT
#elif defined JDF_TOOLS_LIB
#define JDFTOOLS_EXPORT
#else
#define JDFTOOLS_EXPORT PLATFORM_IMPORT
#endif

#if defined JDF_WRAPPERCORE
#define JDF_WRAPPERCORE_EXPORT PLATFORM_EXPORT
#elif defined JDF_WRAPPERCORE_LIB
#define JDF_WRAPPERCORE_EXPORT
#else
#define JDF_WRAPPERCORE_EXPORT PLATFORM_IMPORT
#endif




#if defined(XERCES_TMPLSINC)
#define JDF_TMPLSINC
#endif

#if XERCES_VERSION_MAJOR > 2
#define JDF_NEW_XERCES
#else
// some forward definitions from xerces 3
#undef XMLSize_t
#define XMLSize_t unsigned int
#define XMLFilePos unsigned int
#endif


/******************************************************************************
 *	Classes
 ******************************************************************************/ 


/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 


#endif /* I_JDFTOOLSDEFS_H */

