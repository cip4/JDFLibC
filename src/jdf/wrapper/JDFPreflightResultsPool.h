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
/*
*
*
* COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
*      ALL RIGHTS RESERVED 
*
*  Author: Dr. Rainer Prosi using JDFSchema code generator 
* 
* Warning! preliminary version. Interface subject to change without prior notice!
* Revision history:
* created 2001-12-17
* 030902 RP IsValid() removed erroneous check for maxOccurs=1 of  PreflightDetail PreflightInstance
*
* based on JDF Schema version JDFCore_1_0_0.xsd
*
*/
#if !defined _JDFPreflightResultsPool_H_
#define _JDFPreflightResultsPool_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFPool.h"
namespace JDF{
	class JDFPreflightDetail;
	class JDFPreflightInstance;
	/*
	*********************************************************************
	class JDFPreflightResultsPool : public JDFPool
	
	  *********************************************************************
	*/
	/**
	* automatically generated header for JDFPreflightResultsPool class
	* 
	* Warning! Do not edit! This file may be regenerated
	* The child Class: @see JDFImagesConstraintsPool should be edited instead
	*/
	class JDF_WRAPPERCORE_EXPORT JDFPreflightResultsPool : public JDFPool{
	public:
		
		
		// Constructors / Destructors  
		
		
		/**
		* null ctor
		*/
		inline JDFPreflightResultsPool():JDFPool(){};
		/**
		* copy ctor
		*/
		inline JDFPreflightResultsPool(const KElement & other):JDFPool(){
			*this=other;
		};
		/**
		* copy equivalance operator
		*/
		JDFPreflightResultsPool &operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFPreflightResultsPool(){};
		
		
		/**
		* typesafe validator utility
		* @param EnumValidationLevel level validation level
		* @param bool bIgnorePrivate ignore objects in foreign namespaces
		* @param int nMax size of the returned vector
		* @return vWString vector of invalid element names
		*/
		virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;
		
		/**
		* typesafe validator utility - list of valid node names for this class 
		* @return WString& comma separated list of valid node names
		*/
		
		virtual WString ValidNodeNames()const;
		
		/* ******************************************************
		// Attribute Getter / Setter
		****************************************************** */
		
		
		/* ******************************************************
		// Element Getter / Setter
		**************************************************************** */
		
		
		/** Get Element PreflightInstance
		* @param int iSkip number of elements to skip
		* @return JDFPreflightInstance The element
		*/
		JDFPreflightInstance GetCreatePreflightInstance(int iSkip=0);
		/**
		* Remove element PreflightInstance
		* @param int iSkip number of elements to skip
		*/
		inline void RemovePreflightInstance(int iSkip=0){RemoveChild(L"PreflightInstance", L"", iSkip);};
		/**
		* Append element PreflightInstance
		*/
		JDFPreflightInstance AppendPreflightInstance();
		/**
		* const get first element PreflightInstance
		* @param int iSkip number of elements to skip
		*@return  JDFPreflightInstance The element
		*/
		JDFPreflightInstance GetPreflightInstance(int iSkip=0)const;
		/**
		* Number of PreflightInstance elements
		* @return int number of matching elements
		*/
		inline int NumPreflightInstances() const {
			return NumChildElements(L"PreflightInstance");
		};
		/**
		* test element PreflightInstance existance
		* @return bool true if a matching element exists 
		*/
		inline bool HasPreflightInstance() const {
			return NumChildElements(L"PreflightInstance")>0;
		};
		
		/** Get Element PreflightDetail
		* @param int iSkip number of elements to skip
		* @return JDFPreflightDetail The element
		*/
		JDFPreflightDetail GetCreatePreflightDetail(int iSkip=0);
		/**
		* Remove element PreflightDetail
		* @param int iSkip number of elements to skip
		*/
		inline void RemovePreflightDetail(int iSkip=0){
			RemoveChild(L"PreflightDetail", L"", iSkip);
		};
		/**
		* Append element PreflightDetail
		*/
		JDFPreflightDetail AppendPreflightDetail();
		/**
		* const get first element PreflightDetail
		*@return  JDFPreflightDetail The element
		*/
		JDFPreflightDetail GetPreflightDetail(int iSkip=0)const;
		/**
		* Number of PreflightDetail elements
		* @return int number of matching elements
		*/
		inline int NumPreflightDetails() const {
			return NumChildElements(L"PreflightDetail");
		};
		/**
		* test element PreflightDetail existance
		* @return bool true if a matching element exists 
		*/
		inline bool HasPreflightDetail() const {
			return NumChildElements(L"PreflightDetail")>0;
		};
		/**
		definition of optional elements in the JDF namespace
		*/
		virtual WString OptionalElements()const;
	}; // endJDFPreflightResultsPool
	
	// ******************************************************
}; // end namespace JDF
#endif //_JDFPreflightResultsPool_H_
