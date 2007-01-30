#ifndef _STRINGUTIL_H_
#define _STRINGUTIL_H_

/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2002 The International Cooperation for the Integration of 
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
//EndCopyRight
// ////////////////////////////////////////////////////////////////////
//
//  Author: Dr. Rainer Prosi (JDFLib-J), ported to JDFLIB-C by Niels Boeger
// 
// Revision history:
// created before 07.Sep.2006
// 070906 NB created, added matchesAttribute
// 071206 NB added formatInteger, formatDouble
// 211206 NB moved to WrapperCore
// 250107 NB removed unreferenced variables
//
// StringUtil.h: interface for the StringUtil class. Contains various methods
//               for string manipulation and comparison.
//
// ////////////////////////////////////////////////////////////////////

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <jdf/lang/JDFToolsDefs.h>
#include "jdf/wrappercore/KElement.h"

namespace JDF{
	class WString;

	class JDF_WRAPPERCORE_EXPORT StringUtil{
	public:
		/////////////////////////////////////
		// constructors / destructors
		/////////////////////////////////////
		inline StringUtil() {};
		inline ~StringUtil() {};

		/////////////////////////////////////
		// static methods
		/////////////////////////////////////
		/**
		* checks whether smallAtt is a matching subset of bigAtt depending on datatype
		* 
		* @param smallAtt the small att to test
		* @param bigAtt the big att, e.g. list to test against
		* @param dataType the datatype of the big att
		* 
		* @return true if smallAtt is a matching subset of bigAtt
		*/
		static bool matchesAttribute(const WString& smallAtt, const WString& bigAtt, KElement::EnumAttributeType dataType);

		/**
		* returns a formatted integer, 
		* replaces string constants with according int constants
		* @param i the integer to format
		* @return the formatted WString that represents i
		*/
		static WString formatInteger(int i);

		/**
		* returns a formatted double. 
		* Truncates to 8 digits after the "." <br>
		* If the double is representable as an integer, any ".0" is stripped.
		* 
		* @param d the double to format
		* @return the formatted string that represents d
		*/
		static WString formatDouble(double d);

	}; // class StringUtil

}; // namespace JDF

#endif // _STRINGUTIL_H_