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
//  Authors: Dr. Rainer Prosi, Elena Skobchenko
// 
// Revision history:
// created  08.07.2002
//
// JDFDevCaps.h: interface for the JDFDevCaps class. 
//
//////////////////////////////////////////////////////////////////////


#if !defined _JDFDevCaps_H_
#define _JDFDevCaps_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "AutoJDF/JDFAutoDevCaps.h"

namespace JDF{
	/*
	*********************************************************************
	class JDFDevCaps : public JDFAutoDevCaps

	*********************************************************************
	*/
	/**
	* Typesafe resource wrapper class JDFDevCaps 
	*
	* This file is hand edited and will not be regenerated
	*/
	class JDF_WRAPPERCORE_EXPORT JDFDevCaps : public JDFAutoDevCaps{
	public:


		// Constructors / Destructors  


		/**
		* null ctor
		*/
		inline JDFDevCaps():JDFAutoDevCaps(){};
		/**
		* copy ctor
		*/
		inline JDFDevCaps(const KElement & other):JDFAutoDevCaps(){
			*this=other;
		};
		/**
		* copy equivalance operator
		*/
		JDFDevCaps &operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFDevCaps(){};


		/**
		* definition of optional attributes in the JDF namespace
		*/
		WString OptionalAttributes()const;

		/**
		* typesafe validator
		*/
		vWString GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const;

		/**
		* Sets IDREF attribute DevCapRef
		* @param WString value: the value to set the attribute to
		*/
		void SetDevCapRef(const WString& value);

		/**
		* Gets IDREF attribute DevCapRef
		* @return WString: the value of attribute DevCapRef
		*/
		WString GetDevCapRef() const;

		/**
		* Typesafe attribute validation of DevCapRef
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidDevCapRef(EnumValidationLevel level) const;

		/**
		* Sets IDREFS attribute ModuleRefs
		* @param vWString value: the value to set the attribute to
		*/
		void SetModuleRefs(const vWString& value);

		/**
		* Gets IDREFS attribute ModuleRefs
		* @return vWString: the value of attribute ModuleRefs
		*/
		vWString GetModuleRefs() const;

		/**
		* Typesafe attribute validation of ModuleRefs
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidModuleRefs(EnumValidationLevel level) const;

		/**
		* Gets the NamePath of this DevCaps in form "DevCapsName[Context=bbb, LinkUsage=ccc]/"
		*
		* @param bool onlyNames: if true, returns only DevCapsName. Default=false
		* @return WString: NamePath of this DevCaps  
		*/
		WString GetNamePath(bool onlyNames=false)const;

		/**
		* Gets the NamePath of this DevCap in form 
		* "DevCapsName/SubelemName1/SubelemName2/..."
		* If this DevCap is located in DevCapPool and not in a DevCaps - it describes the reusable resource 
		* and DevCap root will have the attribute "Name" = value of DevCaps/@Name 
		* but will have no info about DevCaps/@Context or DevCaps/@LinkUsage 
		*
		* @param bRecurse - if true, returns "DevCapsName/SubelemName1/SubelemName2/..."
		* @return String - NamePath of this DevCap
		* 
		* default: getNamePath(false)  
		*/
		VString getNamePathVector();

		/**
		* devCapReport - tests if the elements in vElem fit any (logical OR) DevCap element 
		* that DevCaps consists of. Composes a detailed report in XML form of the found errors.
		* If XMLDoc equals null - there are no errors.
		* 
		* DevCap that will be checked are direct children of this and referenced DevCap in DevCapPool.
		* 
		* @param VElement vElem: vector of the elements to test
		* @param EnumFitsValue testlists: FitsValue_Allowed or FitsValue_Present testlists 
		* that are specified for the State elements. (Will be used in fitsValue method of the State element)
		* @param EnumValidationLevel level: validation level
		* @return XMLDoc: XMLDoc output of the error messages.
		* If XMLDoc equals null - there are no errors, every element of vElem fits any DevCap element of this DevCaps
		* @throws JDFException if DevCaps/@DevCapRef refers to the DevCap elements in a non-existent DevCapPool
		* @throws JDFException if DevCaps/@DevCapRef refers to the non-existent DevCap 
		*/
		XMLDoc DevCapReport (vElement vElem, EnumFitsValue testlists, EnumValidationLevel level) const; 

		void Correction(KElement root) const;

		void XPathCorrection(KElement elem, const WString& originalPath) const;

		void RemovePoolElements(KElement root)const;


		/**
		* Moves ChildElementVector of the second element into the first
		* 
		* @param KElement moveToElement: the first element - new parent for the children of the second element
		* @param KElement moveFromElement:  the second element - element whose children will be removed
		*/
		static void MoveChildElementVector(KElement moveToElement, KElement moveFromElement);

		/**
		* fix spelling of TypeOccurenceNum
		*/
		virtual bool FixVersion(EnumVersion version);

		/**
		* sets default elements and adds them if therw are less than minorrurs
		*/
		bool setDefaultsFromCaps(JDFNode node) const;
		/**
		* append elements that match this devCap to node, if they do not yet exist
		* 
		* @param node the node to append the elements to
		* 
		* @return KElement the last element that was appended
		*/
		KElement appendMatchingElementsToNode(JDFNode node)const;
		/**
		* gets the matching elements in node that match this devcap
		* 
		* @param node the node to search in
		* @return VElement the element vector of matching elements, 
		* null if none were found
		*/
		vElement getMatchingElementsFromNode(JDFNode node)const;
		/**
		* get the one and only devCap - note that the spec allows * but recommends only one + additional actions
		* also search devCapPool for a matching element to DevCapRef
		* @return the devCap
		*/
		JDFDevCap getDevCap()const;

		VElement getDevCapVector();

		/**
		* return the highest maxOccurs of all devCap elements
		* @return int the highest maxOccurs of all devCap elements
		*/
		int getMaxOccurs();

		/**
		* return the lowest minOccurs of all devCap elements
		* @return int the lowest minOccurs of all devCap elements
		*/
		int getMinOccurs();

	private:
		WString getDevCapsName();
	}; // endJDFDevCaps

	// ******************************************************
}; // end namespace JDF
#endif //_JDFDevCaps_H_
