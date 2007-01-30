#if !defined _JDFDevCap_H_
#define _JDFDevCap_H_

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
// 181206 NB GetDevCapVector(): changed typeid to GetLocalName()
//
// JDFDevCap.h: interface for the JDFDevCap class.
//
//////////////////////////////////////////////////////////////////////

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "AutoJDF/JDFAutoDevCap.h"
#include "JDFDeviceCap.h"

namespace JDF{
	class JDFBooleanState;
	class JDFDateTimeState;
	class JDFDurationState;	
	class JDFEnumerationState;
	class JDFIntegerState;
	class JDFMatrixState;
	class JDFNameState;
	class JDFNumberState;
	class JDFPDFPathState;
	class JDFRectangleState;
	class JDFShapeState;
	class JDFStringState;
	class JDFXYPairState;
	

	
	/*
	*********************************************************************
	class JDFDevCap : public JDFAutoDevCap
	
	  *********************************************************************
	*/
	/**
	* Typesafe resource wrapper calss JDFDevCap 
	*
	* This file is hand edited and will not be regenerated
	*/
	class JDF_WRAPPERCORE_EXPORT JDFDevCap : public JDFAutoDevCap{
	public:
		
		
		// Constructors / Destructors  
		
		
		/**
		* null ctor
		*/
		inline JDFDevCap():JDFAutoDevCap(){};
		/**
		* copy ctor
		*/
		inline JDFDevCap(const KElement & other):JDFAutoDevCap(){
			*this=other;
		};
		/**
		* copy equivalance operator
		*/
		JDFDevCap &operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFDevCap(){};
		
		/**
		* typesafe validator utility
		* @param EnumValidationLevel level validation level
		* @param bool bIgnorePrivate ignore objects in foreign namespaces
		* @param int nMax size of the returned vector
		* @return vWString vector of invalid attribute names
		*/
		virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;

		/**
		* typesafe validator utility
		* @param EnumValidationLevel level validation level
		* @param bool bIgnorePrivate ignore objects in foreign namespaces
		* @param int nMax size of the returned vector
		* @return vWString vector of invalid element names
		*/
		virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;
		
		/**
		* definition of optional attributes in the JDF namespace
		*/
		virtual WString OptionalAttributes()const;
		
		/**
		* definition of optional elements in the JDF namespace
		*/
		virtual WString OptionalElements()const;

		/**
		* Sets attribute ID
		* @param WString value: the value to set the attribute to
		*/
		void SetID(const WString& value);
		
		/**
		* Gets attribute ID
		* @return WString: the value of attribute ID
		*/
		WString GetID() const;
	    
		/**
		* Typesafe attribute validation of ID
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidID(EnumValidationLevel level) const;


		/**
		* Sets IDREFS attribute DevCapRefs
		* @param vWString value: the value to set the attribute to
		*/
		void SetDevCapRefs(const vWString& value);
		
		/**
		* Gets IDREFS attribute DevCapRefs
		* @return vWString: the value of attribute DevCapRefs
		*/
		vWString GetDevCapRefs() const;
	    
		/**
		* Typesafe attribute validation of DevCapRefs
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidDevCapRefs(EnumValidationLevel level) const;

		/**
		* Get of this DevCap the value of attribute Name. Default = the value of the parent DevCaps element
		*
		* @return WString the value of the attribute Name
		*/
		WString GetName() const;

		/**
		* typesafe validator for name
		*
		* @return boolean true if Name is valid
		*/
		bool ValidName(EnumValidationLevel level) const;

		/**
		* Gets the NamePath of this DevCap in form 
		* "DevCapsName[Context=bbb, LinkUsage=ccc]/SubelemName1/SubelemName2/..."
		* If this DevCap is located in DevCapPool and not in a DevCaps - it describes the reusable resource 
		* and DevCap root will have the attribute "Name" = value of DevCaps/@Name 
		* but will have no info about DevCaps/@Context or DevCaps/@LinkUsage 
		*
		* @param boolean onlyNames - if true, returns "DevCapsName/SubelemName1/SubelemName2/..."
		* @return String - NamePath of this DevCap
		* 
		* default: getNamePath(false)  
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
		VString getNamePathVector(bool bRecurse);
		
		/**
		* Gets of this the Vector of all direct child DevCap elements plus 
		* the referenced (by attribute DevCapRefs) reusable DevCap elements, 
		* that are located in DevCapPool
		* 
		* @return vElement: vector of all direct child DevCap elements plus 
		* the referenced reusable DevCap elements, that are located in DevCapPool. 
		*/ 
		vElement GetDevCapVector(vElement devCaps=vElement::emptyVector, bool bDirect=true) const;

		/**
		* Checks if the attributes and subelements of the tested elements
		* match the corresponding States and DevCap subelements of this DevCap
		* Composes a detailed report of the found errors in XML form. 
		* If XMLDoc equals null - there are no errors
		* 
		* @param VElement vElem: vector of elements to test
		* @param EnumFitsValue testlists: FitsValue_Allowed or FitsValue_Present testlists
		* that are specified for the State elements. (Will be used in fitsValue method of the State element)
		* @param EnumValidationLevel level: validation level
		* @return XMLDoc: XMLDoc output of the error messages. If XMLDoc equals null - there are no errors,
		* every element of vElem fits the corresponding States and DevCap subelements of this DevCap
		*/
		XMLDoc StateReport(vElement vElem, EnumFitsValue testlists, EnumValidationLevel level) const; 
		
		
	private:

		/**
		* Tests if there are any subelements of vElem elements that are not described by DevCap
		* Composes a detailed report of the found errors in XML form. If XMLDoc equals null - there are no errors.
		* 
		* @param vElement vElem: the vector of elements we test
		* @return XMLDoc: XMLDoc output of the error messages. If XMLDoc equals null - there are no errors
		*/
		XMLDoc MissingDevCapInfo(vElement vElem)const;
		
		/**
		* Tests if there are any subelements of the element elem that are not described by DevCap
		* Composes a detailed report of the found errors in XML form. If XMLDoc equals null - there are no errors.
		*  
		* @param JDFElement elem: element we test
		* @return XMLDoc: XMLDoc output of the error messages. If XMLDoc equals null - there are no errors
		*/ 
		XMLDoc MissingDevCap(JDFElement elem)const;

		/**
		* Tests subelements of the element 'e'
		* whether they fit the corresponding DevCap elements of 'this' DevCap.
		* ! Recursive returns to stateReport to test the attributes of the subelements.
		* Composes a detailed report of the found errors in XML form. 
		* If XMLDoc equals null - there are no errors
		* 
		* @param JDFElement e: element to test
		* @param EnumFitsValue testlists: FitsValue_Allowed or FitsValue_Present testlists
		* that are specified for the State elements. (Will be used in fitsValue method of the State element)
		* @param EnumValidationLevel level: validation level
		* @return XMLDoc: XMLDoc output of the error messages. If XMLDoc equals null - there are no errors,
		* 'e' fits the corresponding DevCap elements of 'this' DevCap
		*/
		XMLDoc SubelementsTest(const JDFElement& e, EnumFitsValue testlists, EnumValidationLevel level)const;

		/**
		* Tests attributes and span elements (if 'e' is a intent resource) of the element 'e'.
		* Checks, whether they fit the corresponding State elements of 'this' DevCap.
		* Composes a detailed report of the found errors in XML form. 
		* If XMLDoc equals null - there are no errors.
		* 
		* @param JDFElement e: element to test
		* @param EnumFitsValue testlists: FitsValue_Allowed or FitsValue_Present testlists
		* that are specified for the State elements. (Will be used in fitsValue method of the State element)
		* @param EnumValidationLevel level: validation level
		* @return XMLDoc: XMLDoc output of the error messages. If XMLDoc equals null - there are no errors, 
		* 'e' fits the corresponding State elements of 'this' DevCap
		*/
		XMLDoc SpanAndAttributesTest(const JDFElement& e, EnumFitsValue testlists, EnumValidationLevel level)const;

		/**
		* Gets of the element 'e' a map of Attributes, Comments and Span key-value pairs.
		* All of them must be described as State elements
		* 
		* @param JDFElement e: element to get the attribute map of
		* @return JDFAttributeMap: a myp of Attributes, Comments and Span key-value pairs
		*/
		mAttribute GetSpanAndAttributesMap(const JDFElement& e) const;

		/**
		* Gets of the intent resource 'r' 
		* a map of key-value pairs, where key is a Span NodeName
		* and value is a combiantion of actual, preferred and range values
		* 
		* @param JDFResource& r: intent resource to get the SpanValueMap of
		* @return JDFAttributeMap: SpanValueMap
		*/
		mAttribute GetSpanValueMap(const JDFResource& r) const; 

		/**
		* Checks if the attributes key of the tested element is a generic attribute.
		* Gets this attribute of DeviceCap element
		* 
		* @param WString & key: attribute key to test
		* @return bool: true if the key is a generic attribute
		*/
		bool IsGenericAttribute(const WString & key)const;

		/**
		* Moves ChildElementVector of the second element into the first
		* 
		* @param KElement moveToElement: the first element - new parent for the children of the second element
		* @param KElement moveFromElement:  the second element - element whose children will be removed
		*/
		static void MoveChildElementVector(KElement moveToElement, KElement moveFromElement);

    /**
      * gets the matching elements in node that match this devcap
      * 
      * @param node the node to search in
      * @return VElement the element vector of matching elements, 
      * null if none were found
      */
	vElement getMatchingElementsFromParent(const KElement& parent)const;

		     /**
     * return the vector of all states
     * @param bDirect if false, recurse into child elements, else return only direct child states
     * @param id ID attribute of the requested string
     * @return
     */
	vElement getStates(bool bDirect, const WString& id=WString::emptyStr) const;

	public:
	  /**
      * sets the element and attribute defaults
      * @param element
      * @return
      */
	bool setDefaultsFromCaps(KElement element)const;

		/**
		* Typesafe enumerated attribute Availability; defaults to Installed
		*
		* @return EnumAvailabilitythe enumeration value of the attribute
		*/
	EnumAvailability GetAvailability() const;


		/* ******************************************************
		// Element Getter / Setter
		**************************************************************** */


		/** 
		* Gets element DevCap
		* @param int iSkip number of elements to skip
		* @return JDFDevCap The element
		*/
		JDFDevCap GetCreateDevCap(int iSkip=0);
		
		/**
		* Gets element DevCap
		* @param int iSkip number of elements to skip
		* @return JDFDevCap - DevCap element
		*/
		JDFDevCap GetDevCap(int iSkip=0)const;
		
		/**
		* Appends element DevCap
		* @return JDFDevCap - appended DevCap element
		*/
		JDFDevCap AppendDevCap();
		
		
		/** 
		* Gets element Loc
		* @param int iSkip number of elements to skip
		* @return JDFLoc - Loc element
		*/
		JDFLoc GetCreateLoc(int iSkip=0);
		
		/**
		* Gets element Loc
		* @param int iSkip number of elements to skip
		* @return JDFLoc - Loc element
		*/
		JDFLoc GetLoc(int iSkip=0)const;
		
		/**
		* Appends element Loc
		* @return JDFLoc - Loc element
		*/
		JDFLoc AppendLoc();
		

		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFBooleanState GetCreateBooleanState(int iSkip=0);

		/**
		* gets a BooleanState with @Name="name", appends it if it does not yet exist
		* @param name the Name attribute of the newly appended BooleanState
		* @return JDFBooleanState the existing or newly appended BooleanState
		*/
		JDFBooleanState GetCreateBooleanState(WString name = "");
		
		/**
		* const get element BooleanState
		* @param int iSkip number of elements to skip
		* @return JDFBooleanState The element
		*/
		JDFBooleanState GetBooleanState(int iSkip=0)const;

		/**
		* gets an existing  BooleanState with @Name="name"
		* @param name the Name attribute of the newly appended BooleanState
		* @return JDFBooleanState the existing BooleanState
		*/
		JDFBooleanState GetBooleanState(WString name = "");
		
		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFBooleanState AppendBooleanState();

		/**
		* appends a BooleanState with @Name="name"
		* @param name the Name attribute of the newly appended BooleanState
		* @return JDFBooleanState the newly appended BooleanState
		*/
		JDFBooleanState AppendBooleanState(WString name);
				

		
		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFDateTimeState GetCreateDateTimeState(int iSkip=0);

		/**
		* gets a DateTimeState with @Name="name", appends it if it does not yet exist
		* @param name the Name attribute of the newly appended DateTimeState
		* @return JDFDateTimeState the existing or newly appended DateTimeState
		*/
		JDFDateTimeState GetCreateDateTimeState(WString name = "");
		
		/**
		* const get element DateTimeState
		* @param int iSkip number of elements to skip
		* @return JDFDateTimeState The element
		*/
		JDFDateTimeState GetDateTimeState(int iSkip=0)const;

		/**
		* gets an existing  DateTimeState with @Name="name"
		* @param name the Name attribute of the newly appended DateTimeState
		* @return JDFDateTimeState the existing DateTimeState
		*/
		JDFDateTimeState GetDateTimeState(WString name = "");
		
		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFDateTimeState AppendDateTimeState();

		/**
		* appends a DateTimeState with @Name="name"
		* @param name the Name attribute of the newly appended DateTimeState
		* @return JDFDateTimeState the newly appended DateTimeState
		*/
		JDFDateTimeState AppendDateTimeState(WString name);	
		

		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFDurationState GetCreateDurationState(int iSkip=0);

		/**
		* gets a DurationState with @Name="name", appends it if it does not yet exist
		* @param name the Name attribute of the newly appended DurationState
		* @return JDFDurationState the existing or newly appended DurationState
		*/
		JDFDurationState GetCreateDurationState(WString name = "");
	
		/**
		* const get element DurationState
		* @param int iSkip number of elements to skip
		* @return JDFDurationState The element
		*/
		JDFDurationState GetDurationState(int iSkip=0)const;

		/**
		* gets an existing  DurationState with @Name="name"
		* @param name the Name attribute of the newly appended DurationState
		* @return JDFDurationState the existing DurationState
		*/
		JDFDurationState GetDurationState(WString name = "");
	
		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFDurationState AppendDurationState();

		/**
		* appends a DurationState with @Name="name"
		* @param name the Name attribute of the newly appended DurationState
		* @return JDFDurationState the newly appended DurationState
		*/
		JDFDurationState AppendDurationState(WString name);
		
		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFEnumerationState GetCreateEnumerationState(int iSkip=0);

		/**
		* gets a EnumerationState with @Name="name", appends it if it does not yet exist
		* @param name the Name attribute of the newly appended EnumerationState
		* @return JDFEnumerationState the existing or newly appended EnumerationState
		*/
		JDFEnumerationState GetCreateEnumerationState(WString name = "");
		
		/**
		* const get element EnumerationState
		* @param int iSkip number of elements to skip
		* @return JDFEnumerationState The element
		*/
		JDFEnumerationState GetEnumerationState(int iSkip=0)const;
		
		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFEnumerationState AppendEnumerationState();

		/**
		* appends a EnumerationState with @Name="name"
		* @param name the Name attribute of the newly appended EnumerationState
		* @return JDFEnumerationState the newly appended EnumerationState
		*/
		JDFEnumerationState AppendEnumerationState(WString name);

		/**
		* gets an existing  EnumerationState with @Name="name"
		* @param name the Name attribute of the newly appended EnumerationState
		* @return JDFEnumerationState the existing EnumerationState
		*/
		JDFEnumerationState GetEnumerationState(WString name = "");
		
						
		/** Get Element IntegerState
		* 
		* @param int iSkip number of elements to skip
		* @return JDFIntegerState The element
		*/
		JDFIntegerState GetCreateIntegerState(int iSkip=0);

		/**
		* gets a IntegerState with @Name="name", appends it if it does not yet exist
		* @param name the Name attribute of the newly appended IntegerState
		* @return JDFIntegerState the existing or newly appended IntegerState
		*/
		JDFIntegerState GetCreateIntegerState(WString name = "");
		
		/**
		* const get element IntegerState
		* @param int iSkip number of elements to skip
		* @return JDFIntegerState The element
		*/
		JDFIntegerState GetIntegerState(int iSkip=0)const;

		/**
		* gets an existing  IntegerState with @Name="name"
		* @param name the Name attribute of the newly appended IntegerState
		* @return JDFIntegerState the existing IntegerState
		*/
		JDFIntegerState GetIntegerState(WString name = "");
		
		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFIntegerState AppendIntegerState();

		/**
		* appends a IntegerState with @Name="name"
		* @param name the Name attribute of the newly appended IntegerState
		* @return JDFIntegerState the newly appended IntegerState
		*/
		JDFIntegerState AppendIntegerState(WString name);
		

		
		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFMatrixState GetCreateMatrixState(int iSkip=0);

		/**
		* gets a MatrixState with @Name="name", appends it if it does not yet exist
		* @param name the Name attribute of the newly appended MatrixState
		* @return JDFMatrixState the existing or newly appended MatrixState
		*/
		JDFMatrixState GetCreateMatrixState(WString name = "");
		
		/**
		* const get element MatrixState
		* @param int iSkip number of elements to skip
		* @return JDFMatrixState The element
		*/
		JDFMatrixState GetMatrixState(int iSkip=0)const;

		/**
		* gets an existing  MatrixState with @Name="name"
		* @param name the Name attribute of the newly appended MatrixState
		* @return JDFMatrixState the existing MatrixState
		*/
		JDFMatrixState GetMatrixState(WString name = "");

		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFMatrixState AppendMatrixState();

		/**
		* appends a MatrixState with @Name="name"
		* @param name the Name attribute of the newly appended MatrixState
		* @return JDFMatrixState the newly appended MatrixState
		*/
		JDFMatrixState AppendMatrixState(WString name);


		
		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFNameState GetCreateNameState(int iSkip=0);

		/**
		* gets a NameState with @Name="name", appends it if it does not yet exist
		* @param name the Name attribute of the newly appended NameState
		* @return JDFNameState the existing or newly appended NameState
		*/
		JDFNameState GetCreateNameState(WString name = "");
		
		/**
		* const get element NameState
		* @param int iSkip number of elements to skip
		* @return JDFNameState The element
		*/
		JDFNameState GetNameState(int iSkip=0)const;

		/**
		* gets an existing  NameState with @Name="name"
		* @param name the Name attribute of the newly appended NameState
		* @return JDFNameState the existing NameState
		*/
		JDFNameState GetNameState(WString name = "");
		
		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFNameState AppendNameState();

		/**
		* appends a NameState with @Name="name"
		* @param name the Name attribute of the newly appended NameState
		* @return JDFNameState the newly appended NameState
		*/
		JDFNameState AppendNameState(WString name);
			


		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFNumberState GetCreateNumberState(int iSkip=0);

		/**
		* gets a NumberState with @Name="name", appends it if it does not yet exist
		* @param name the Name attribute of the newly appended NumberState
		* @return JDFNumberState the existing or newly appended NumberState
		*/
		JDFNumberState GetCreateNumberState(WString name = "");
		
		/**
		* const get element NumberState
		* @param int iSkip number of elements to skip
		* @return JDFNumberState The element
		*/
		JDFNumberState GetNumberState(int iSkip=0)const;

		/**
		* gets an existing  NumberState with @Name="name"
		* @param name the Name attribute of the newly appended NumberState
		* @return JDFNumberState the existing NumberState
		*/
		JDFNumberState GetNumberState(WString name = "");
		
		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFNumberState AppendNumberState();

		/**
		* appends a NumberState with @Name="name"
		* @param name the Name attribute of the newly appended NumberState
		* @return JDFNumberState the newly appended NumberState
		*/
		JDFNumberState AppendNumberState(WString name);
		
			

		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFPDFPathState GetCreatePDFPathState(int iSkip=0);

		/**
		* gets a PDFPathState with @Name="name", appends it if it does not yet exist
		* @param name the Name attribute of the newly appended PDFPathState
		* @return JDFPDFPathState the existing or newly appended PDFPathState
		*/
		JDFPDFPathState GetCreatePDFPathState(WString name = "");
		
		/**
		* const get element PDFPathState
		* @param int iSkip number of elements to skip
		* @return JDFPDFPathState The element
		*/
		JDFPDFPathState GetPDFPathState(int iSkip=0)const;

		/**
		* gets an existing  PDFPathState with @Name="name"
		* @param name the Name attribute of the newly appended PDFPathState
		* @return JDFPDFPathState the existing PDFPathState
		*/
		JDFPDFPathState GetPDFPathState(WString name = "");
	
		/**
		* Append element PDFPathState
		*/
		JDFPDFPathState AppendPDFPathState();

		/**
		* appends a PDFPathState with @Name="name"
		* @param name the Name attribute of the newly appended PDFPathState
		* @return JDFPDFPathState the newly appended PDFPathState
		*/
		JDFPDFPathState AppendPDFPathState(WString name);
		
		

		/** Get Element RectangleState
		* 
		* @param int iSkip number of elements to skip
		* @return JDFRectangleState The element
		*/
		JDFRectangleState GetCreateRectangleState(int iSkip=0);

		/**
		* gets a RectangleState with @Name="name", appends it if it does not yet exist
		* @param name the Name attribute of the newly appended RectangleState
		* @return JDFRectangleState the existing or newly appended RectangleState
		*/
		JDFRectangleState GetCreateRectangleState(WString name = "");
		
		/**
		* const get element RectangleState
		* @param int iSkip number of elements to skip
		* @return JDFRectangleState The element
		*/
		JDFRectangleState GetRectangleState(int iSkip=0)const;

		/**
		* gets an existing  RectangleState with @Name="name"
		* @param name the Name attribute of the newly appended RectangleState
		* @return JDFRectangleState the existing RectangleState
		*/
		JDFRectangleState GetRectangleState(WString name = "");
		
		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFRectangleState AppendRectangleState();
		
		/**
		* appends a RectangleState with @Name="name"
		* @param name the Name attribute of the newly appended RectangleState
		* @return JDFRectangleState the newly appended RectangleState
		*/
		JDFRectangleState AppendRectangleState(WString name);
		

		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFShapeState GetCreateShapeState(int iSkip=0);

		/**
		* gets a ShapeState with @Name="name", appends it if it does not yet exist
		* @param name the Name attribute of the newly appended ShapeState
		* @return JDFShapeState the existing or newly appended ShapeState
		*/
		JDFShapeState GetCreateShapeState(WString name = "");
		
		/**
		* const get element ShapeState
		* @param int iSkip number of elements to skip
		* @return JDFShapeState The element
		*/
		JDFShapeState GetShapeState(int iSkip=0)const;


		/**
		* gets an existing  ShapeState with @Name="name"
		* @param name the Name attribute of the newly appended ShapeState
		* @return JDFShapeState the existing ShapeState
		*/
		JDFShapeState GetShapeState(WString name = "");
		
		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFShapeState AppendShapeState();

		/**
		* appends a ShapeState with @Name="name"
		* @param name the Name attribute of the newly appended ShapeState
		* @return JDFShapeState the newly appended ShapeState
		*/
		JDFShapeState AppendShapeState(WString name);
		

		
		/** Get Element StringState
		* 
		* @param int iSkip number of elements to skip
		* @return JDFStringState The element
		*/
		JDFStringState GetCreateStringState(int iSkip=0);

		/**
		* gets a StringState with @Name="name", appends it if it does not yet exist
		* @param name the Name attribute of the newly appended StringState
		* @return JDFStringState the existing or newly appended StringState
		*/
		JDFStringState GetCreateStringState(WString name = "");
		
		/**
		* const get element StringState
		* @param int iSkip number of elements to skip
		* @return JDFStringState The element
		*/
		JDFStringState GetStringState(int iSkip=0)const;

		/**
		* gets an existing  StringState with @Name="name"
		* @param name the Name attribute of the newly appended StringState
		* @return JDFStringState the existing StringState
		*/
		JDFStringState GetStringState(WString name = "");
		
		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFStringState AppendStringState();

		/**
		* appends a StringState with @Name="name"
		* @param name the Name attribute of the newly appended StringState
		* @return JDFStringState the newly appended StringState
		*/
		JDFStringState AppendStringState(WString name);
		
		
				
		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFXYPairState GetCreateXYPairState(int iSkip=0);

		/**
		* gets a XYPairState with @Name="name", appends it if it does not yet exist
		* @param name the Name attribute of the newly appended XYPairState
		* @return JDFXYPairState the existing or newly appended XYPairState
		*/
		JDFXYPairState GetCreateXYPairState(WString name = "");
		
		/**
		* const get element XYPairState
		* @param int iSkip number of elements to skip
		* @return JDFXYPairState The element
		*/
		JDFXYPairState GetXYPairState(int iSkip=0)const;

		/**
		* gets an existing  XYPairState with @Name="name"
		* @param name the Name attribute of the newly appended XYPairState
		* @return JDFXYPairState the existing XYPairState
		*/
		JDFXYPairState GetXYPairState(WString name = "");
		
		/**
		* @deprecated use method with parameter (WString) instead
		* @return
		*/
		JDFXYPairState AppendXYPairState();

		/**
		* appends a XYPairState with @Name="name"
		* @param name the Name attribute of the newly appended XYPairState
		* @return JDFXYPairState the newly appended XYPairState
		*/
		JDFXYPairState AppendXYPairState(WString name);
	
	}; // endJDFDevCap
	
	// ******************************************************
}; // end namespace JDF
#endif //_JDFDevCap_H_
