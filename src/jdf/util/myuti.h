#if !defined(MYUTI_H_INCLUDED_)
#define MYUTI_H_INCLUDED_
/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2005 The International Cooperation for the Integration of 
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
//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2005
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
// 170700 RP added ifdef around definition of PI
//
// 161000 RP GetTmpFile added default to $TEMP env variable
// ... many undocumented 
// 150802 RP min and max templates are only defined for WIN32. Any predefined min/max macros are explicitely undefined 
// 150802 RP #pragma warnings are #ifdef WIN32
// 150903 RP ifdefs for min/max now check for DINKUMWARE
// 061003 SB Added missing guard _MyMinMax
//
//////////////////////////////////////////////////////////////////////



#ifdef STLPORT
#define _STLP_DONT_FORCE_MSVC_LIB_NAME

#define _Bidit bidirectional_iterator
#endif


#ifndef PI
#ifndef PI_DEFINED
#define PI_DEFINED
const double PI=3.1415926535897932384626433832795;
#endif
#endif



#ifdef WIN32

#pragma warning( disable : 4786 ) // long debug names from stl
#pragma warning( disable : 4804 ) // bool checking
#pragma warning( disable : 4018 ) // signed unsigned compare warning

#   include <cctype>
#   include <cwchar>

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// only needed on WIN32 platforms where the min and max templates are undefined
// _MSC_VER = 1300 ==> vc7 
#if (_MSC_VER<1300) && !defined(STLPORT) && !defined(USING_DINKUMWARE_STL) && !defined(_MyMinMax)
#define _MyMinMax

namespace std {
    // just in case min and max are defined
#undef min
#undef max
    
	template <class _T> 
	inline const _T& min(const _T& __a, const _T& __b)
{
		return ((__b < __a) ? __b : __a);
}

template <class _T> 
inline const _T& max(const _T& __a, const _T& __b) 
{
    return  ((__a < __b) ? __b : __a);
}

};
#endif



#else

#   include <cctype>
#   include <cwchar>

#   ifndef __int64
        typedef long long __int64;
#   endif

#   ifndef _wcsicmp
        int _wcsicmp(const wchar_t* str1, const wchar_t* str2);
#   endif

#   ifndef _wcsupr
        wchar_t* _wcsupr( wchar_t* buffer);
#   endif

#   ifndef _wcslwr 
        wchar_t* _wcslwr( wchar_t* buffer);
#   endif

#   ifndef _ui64tow
        wchar_t* _ui64tow( unsigned long long value, wchar_t* buffer, int radix);
#   endif

#   ifndef _ultow
        wchar_t* _ultow( unsigned long value, wchar_t* buffer, int radix);
#   endif

#   ifndef _ltow
        wchar_t* _ltow( long value, wchar_t* buffer, int radix);
#   endif

#   ifndef _itow
        wchar_t* _itow( int value, wchar_t* buffer, int radix);
#   endif

#   ifndef itoa
        char *itoa( int value, char *s, int radix );
#   endif

#   ifndef wcsupr
#       define wcsupr _wcsupr
#   endif

#   ifndef wcslwr
#       define wcslwr _wcslwr
#   endif

#   ifndef _i64tow
        wchar_t* _i64tow( unsigned long long value, wchar_t* buffer, int radix);
#   endif

#   ifndef _wtoi64
        __int64 _wtoi64(const wchar_t* str);
#   endif

#   ifndef _wtoi
        int _wtoi(const wchar_t* str);
#   endif

#ifndef __MWERKS__
#   ifndef wcstok
        wchar_t* wcstok(wchar_t* strToken, const wchar_t* strDelimit, wchar_t** tok2);
#   endif
#endif

#ifndef __MWERKS__
#   ifndef wcstod
        double wcstod(const wchar_t *nptr, wchar_t **endptr);
#   endif
#endif

#ifndef __MWERKS__
#   if ! defined( wcstol)
        long wcstol(const wchar_t *nptr, wchar_t** endptr, int base);
#   endif
#endif

#   ifndef _atoi64
        long long _atoi64(const char* str);
#   endif

#ifdef __MWERKS__
#ifndef towlower
		int towlower(int c);
#endif
#endif

#endif // end of #else

#endif // !defined(MYUTI_H_INCLUDED_)
