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

//EndCopyRight
//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
//      ALL RIGHTS RESERVED 
//
//  Authors: Dr. Elena Skobchenko
// 
// Revision history:
// created  11.03.2005
//
// JDFModule.cpp: interface for the JDFModule class. 
//
//////////////////////////////////////////////////////////////////////

#if !defined _JDFModule_H_
#define _JDFModule_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
#include "JDFDeviceCap.h"

namespace JDF{
	
	/*
	*********************************************************************
	class JDFModule : public JDFElement
	
	  *********************************************************************
	*/
	/**
	* Typesafe resource wrapper calss JDFModule 
	*
	* This file is hand edited and will not be regenerated
	*/
	class JDF_WRAPPERCORE_EXPORT JDFModule : public JDFElement{
	public:
		
		
		// Constructors / Destructors  
		
		
		/**
		* null ctor
		*/
		inline JDFModule():JDFElement(){};
		/**
		* copy ctor
		*/
		inline JDFModule(const KElement & other):JDFElement(){
			*this=other;
		};
		/**
		* copy equivalance operator
		*/
		JDFModule &operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFModule(){};
		
		
		/**
		* typesafe validator utility
		* @param EnumValidationLevel level validation level
		* @param bool bIgnorePrivate ignore objects in foreign namespaces
		* @param int nMax size of the returned vector
		* @return vWString vector of invalid element names
		*/
		virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;
		
		/**
		* typesafe validator utility
		* @param EnumValidationLevel level validation level
		* @param bool bIgnorePrivate ignore objects in foreign namespaces
		* @param int nMax size of the returned vector
		* @return vWString vector of invalid attribute names
		*/
		virtual  vWString GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const;

		/**
		* definition of the required attributes in the JDF namespace
		*/
		virtual WString RequiredAttributes()const;
		
		/**
		* definition of the optional attributes in the JDF namespace
		*/
		virtual WString OptionalAttributes()const;
		
		/**
		* definition of the optional elements in the JDF namespace
		*/
		virtual WString OptionalElements()const;
		

		/* ******************************************************
		// Attributes Getter / Setter
		**************************************************************** */
		
		/**
		* Typesafe attribute validation
		* @param EnumValidationLevel level - attribute validation level
		* @return bool - true if valid
		*/
		bool ValidAvailability(EnumValidationLevel level) const;
		
		/**
		* Typesafe enumerated attribute Availability; 
		*
		* @param EnumAvailability - the enumeration value of the attribute
		*/
		
		void SetAvailability(JDFDevCaps::EnumAvailability value);
		
		/**
		* Typesafe enumerated attribute Availability; 
		*
		* @return EnumAvailability - the enumeration value of the attribute
		*/
		JDFDevCaps::EnumAvailability GetAvailability() const;


		/**
		* Sets attribute ID
		* @param WString value: the value to set the attribute to
		*/
		void SetID(const WString& value);

		/**
		* Gets string attribute ID
		* @return WString the vaue of the attribute 
		*/
		WString GetID() const;

		/**
		* Typesafe attribute validation of ID
		* @param EnumValidationLevel level of attribute validation 
		* @return bool - true if valid
		*/
		bool ValidID(EnumValidationLevel level=ValidationLevel_Complete) const;


		/* ******************************************************
		// Element Getter / Setter
		**************************************************************** */


		/** 
		* Gets element Device
		* @return JDFDevice - the element
		*/
		JDFDevice GetCreateDevice();
		
		/**
		* Gets element Device
		* @return JDFDevice - the element
		*/
		JDFDevice GetDevice()const;
		
		/**
		* Appends element Device
		* @return JDFDevice - the element
		*/
		JDFDevice AppendDevice();
		
		
	
	}; // end JDFModule
	
	// ******************************************************
}; // end namespace JDF
#endif //_JDFModule_H_
