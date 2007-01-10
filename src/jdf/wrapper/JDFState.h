#if !defined(_JDFState_H__)
#define _JDFState_H__

/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2004 The International Cooperation for the Integration of 
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
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created  141101
// 080802 RP Modified for JDF 1.1a
// 160802 RP type typo for Name attribute - now WString
//        RP removed all init() routines. They became redundant in JDF 1.1 since DataType is no longer required
// 250104 ES Modified for JDF 1.2 
// 270104 ES removed all typesafe classes, but their template is still here
// 081206 NB added FixVersion(), needed for handling "unbounded"
// 
//
// JDFState.h: interface for the JDFState class.
// defines the generic State attributes and sub-elements
//
// ////////////////////////////////////////////////////////////////////

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFElement.h"
#include "JDFDevCaps.h"
#include "JDFLoc.h"



namespace JDF{

	
/**
* defines the data type independent parts of a ranged State resource
	*/
	class JDF_WRAPPERCORE_EXPORT JDFStateBase: public JDFElement{
	public:

	/**
	* Empty constructor
		*/
		inline JDFStateBase():JDFElement(){};
		
		/**
		* Copy constructor
		*/
		inline JDFStateBase(const KElement & other):JDFElement(){
			*this=other;
		};
		
		/**
		* Equivalence copy constructor
		*/
		JDFStateBase&operator =(const KElement& other);
		
		/**
		* Destructor
		*/
		virtual ~JDFStateBase(){};
		
		
		/**
		* enum for datatype enumeration 
		*/
		enum EnumDataType{DataType_Unknown,DataType_IntegerState,DataType_NumberState,DataType_BooleanState,DataType_NameState,DataType_EnumerationState,DataType_StringState,DataType_XYPairState,DataType_MatrixState,DataType_ShapeState,DataType_DateTimeState,DataType_DurationState,DataType_PDFPathState,DataType_RectangleState};

		//@{
		/**
		* Enumeration for attribute UserDisplay
		*/
		enum EnumUserDisplay{UserDisplay_Unknown,UserDisplay_Display,UserDisplay_Hide,UserDisplay_Dependent};

		/**
		* Enumeration strings for UserDisplay
		*
		* @return const WString&: comma separated list of enumerated string values 
		*/
		static const WString& UserDisplayString();

		/**
		* Enumeration string for enum value
		*
		* @param EnumUserDisplay value: the enumeration to translate
		* @return WString: the string representation of the enumeration
		*/
		static const WString UserDisplayString(EnumUserDisplay value);
		//@}

		//@{
		/**
		* Enumeration for attribute ListType
		*/
		enum EnumListType{ListType_Unknown,ListType_CompleteList,ListType_CompleteOrderedList,ListType_ContainedList,ListType_List,ListType_OrderedList,ListType_OrderedRangeList,ListType_RangeList,ListType_SingleValue,ListType_Span,ListType_UniqueList,ListType_UniqueRangeList,ListType_UniqueOrderedList,ListType_UniqueOrderedRangeList};

		/**
		* Enumeration strings for ListType
		*
		* @return const WString&: comma separated list of enumerated string values 
		*/
		static const WString& ListTypeString();

		/**
		* Enumeration string for enum value
		*
		* @param EnumListType value: the enumeration to translate
		* @return WString: the string representation of the enumeration
		*/
		static const WString ListTypeString(EnumListType value);
		//@}

		/**
		* definition of optional attributes in the JDF namespace
		*
		* @return WString: list of optional attributes
		*/
		virtual WString OptionalAttributes()const;
		
		/**
		* definition of required attributes in the JDF namespace
		*
		* @return WString: list of required attributes
		*/
		virtual WString RequiredAttributes()const;
		
		/**
		* typesafe validator
		*
		* @param EnumValidationLevel level: validation level
		* @param bool bIgnorePrivate: if true, do not worry about attributes in other namespaces
		* @param int nMax: maximum size of the returned vector
		* @return vWString: a vector of invalid attribute names
		*/
		virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;		

		
		/**
		* definition of optional elements in the JDF namespace
		*
		* @return WString: list of optional elements
		*/
		virtual WString OptionalElements()const;
		
		/**
		* typesafe validator
		*
		* @param EnumValidationLevel level: validation level
		* @param bool bIgnorePrivate: if true, do not worry about elements in other namespaces
		* @param int nMax: maximum size of the returned vector
		* @return vWString: a vector of invalid element names
		*/
		virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;
		

		/**
		* Typesafe attribute validation of DefaultValue
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidDefaultValue(EnumValidationLevel level)const;

    
    /**
     * set the default values specified in this in element
     * @param element the element to set the defaults on
     * @return true if successful
     */
		bool setDefaultsFromCaps(KElement element)const;

   /**
     * gets the matching Attribute value String or AbstractSpan object from the parent, 
     * depending on the type of the state
     * 
     * @param element the parent in which to search
     * @return Object either a String or AbstractSpan
     */
	bool hasMatchingObjectInNode(const KElement& element)const;
		/**
		* Typesafe attribute validation of CurrentValue
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidCurrentValue(EnumValidationLevel level)const;

		/**
		* Tests, if the defined value matches Allowed test lists or Present test lists,
		* specified for this State
		*
		* @param const WString& value: value to test
		* @param EnumFitsValue valuelist: Switches between Allowed test lists and Present test lists.
		* Has two values: Allowed and Present.
		* @return bool: true, if the value matches test lists or if Allowed testlists are not specified
		*/
		virtual bool FitsValue(const WString& value, EnumFitsValue testlists) const;


		/**
		* Gets the NamePath of this State in form 
		* "DevCapsName[Context=aaa, LinkUsage=ccc]/DevCapName1/DevCapName2../@StateName"
		* 
		* @param bool onlyNames: if true returns "DevCapsName/SubelemName1/SubelemName2/../@StateName". Default=false
		* @return WString: NamePath of this State
		*/
		virtual WString GetNamePath(bool onlyNames=false)const;


		/* ******************************************************
		// Attribute Getter / Setter
		**************************************************************** */

		//@{
		/**
		* Sets attribute Availability
		*
		* @param EnumAvailability value: the value to set the attribute to
		*/
		virtual void SetAvailability( JDFDevCaps::EnumAvailability value);

		/**
		* Gets typesafe enumerated attribute Availability
		*
		* @return EnumAvailability: the enumeration value of the attribute
		*/
		virtual JDFDevCaps::EnumAvailability GetAvailability() const;
			
		/**
		* Typesafe attribute validation of Availability
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidAvailability(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}
		

		//@{
		/**
		* Sets attribute DevNS
		*
		* @param WString value: the value to set the attribute to
		*/
		virtual void SetDevNS(WString value);

		/**
		* Gets URI attribute DevNS, default = "http://www.cip4.org/JDFSchema_1_1"
		*
		* @return WString: the attribute value
		*/
		virtual WString GetDevNS() const;

		/**
		* Typesafe attribute validation of DevNS
		*
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidDevNS(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}
		

		//@{
		/**
		* Sets attribute ID
		*
		* @param WString& value: value to set the attribute to
		*/
		virtual void SetID(const WString& value);
		
		/**
		* Gets string attribute ID
		*
		* @return WString: the attribute value
		*/
		virtual WString GetID() const;

		/**
		* Typesafe attribute validation of ID
		*
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidID(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}
		
		
		//@{
		/**
		* Sets attribute HasDefault
		*
		* @param bool value: the value to set the attribute to
		*/
		virtual void SetHasDefault(bool value);
		
		/**
		* Gets bool attribute HasDefault, default=true
		*
		* @return bool: the attribute value
		*/
		virtual bool GetHasDefault() const;
		
		/**
		* Typesafe attribute validation of HasDefault
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidHasDefault(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}
	

		//@{
		/**
		* Sets attribute MaxOccurs
		*
		* @param int value: the value to set the attribute to
		*/
		virtual void SetMaxOccurs(int value);
		
		/**
		* Gets integer attribute MaxOccurs, default=1
		*
		* @return bool: the attribute value 
		*/
		virtual int GetMaxOccurs() const;
		
		/**
		* Typesafe attribute validation of MaxOccurs
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidMaxOccurs(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute MinOccurs
		*
		* @param int value: the value to set the attribute to
		*/
		virtual void SetMinOccurs(int value);
		
		/**
		* Get integer attribute MinOccurs, default=1
		*
		* @return bool: the attribute value 
		*/
		virtual int GetMinOccurs() const;
		
		/**
		* Typesafe attribute validation of MinOccurs
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidMinOccurs(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets WString attribute Name
		* Since name is independent of the data type of the State element, the setter is defined here
		*
		* @param WString value: the value to set the attribute to
		*/
		virtual void SetName(const WString& value);

		/**
		* Gets WString attribute Name
		* Since name is independent of the data type of the State element,the getter is defined here
		*
		* @return bool: the attribute value
		*/
		virtual WString GetName() const;
		
		/**
		* Typesafe attribute validation of Name
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidName(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}
		

		//@{
		/**
		* Sets attribute Required
		*
		* @param bool value: the value to set the attribute to
		*/
		virtual void SetRequired(bool value);
		
		/**
		* Gets bool attribute Required
		*
		* @return bool: the attribute value 
		*/
		virtual bool GetRequired() const;
		
		/**
		* Typesafe attribute validation of Required
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidRequired(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute ListType, 
		*
		* @param EnumListType value: the value to set the attribute to
		*/
		virtual void SetListType( EnumListType value);

		/**
		* Gets typesafe enumerated attribute ListType, default = ListType_SingleValue
		*
		* @return EnumListType: the enumeration value of the attribute
		*/
		virtual EnumListType GetListType() const;
			
		/**
		* Typesafe attribute validation of ListType
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidListType(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}
		

		//@{
		/**
		* Sets attribute ActionRefs
		*
		* @param vWString value: vector of ActionRefs
		*/
		virtual void SetActionRefs(vWString value);
		
		/**
		* Gets NMTOKENS attribute ActionRefs
		*
		* @return vWString: the attribute value
		*/
		virtual vWString GetActionRefs() const;
		
		/**
		* Typesafe attribute validation of ActionRefs
		*
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidActionRefs(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute Editable
		*
		* @param bool value: the value to set the attribute to
		*/
		virtual void SetEditable(bool value);
		
		/**
		* Gets bool attribute Editable
		*
		* @return bool: the attribute value 
		*/
		virtual bool GetEditable() const;
		
		/**
		* Typesafe attribute validation of Editable
		*
		* @param EnumValidationLevel level of attribute validation 
		* @return bool true if valid
		*/
		virtual bool ValidEditable(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}

		
		//@{
		/**
		* Sets attribute MacroRefs
		*
		* @param vWString value: vector of MacroRefs
		*/
		virtual void SetMacroRefs(vWString value);
		
		/**
		* Get NMTOKENS attribute MacroRefs
		*
		* @return vWString: the attribute value
		*/
		virtual vWString GetMacroRefs() const;
		
		/**
		* Typesafe attribute validation of MacroRefs
		*
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidMacroRefs(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute DependentMacroRef
		*
		* @param WString& value: vector of DependentMacroRef
		*/
		virtual void SetDependentMacroRef(const WString &value);
		
		/**
		* Get string attribute DependentMacroRef
		*
		* @return WString: the attribute value
		*/
		virtual WString GetDependentMacroRef() const;
		
		/**
		* Typesafe attribute validation of DependentMacroRef
		*
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidDependentMacroRef(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute UserDisplay
		*
		* @param EnumUserDisplay value: the value to set the attribute to
		*/
		virtual void SetUserDisplay( EnumUserDisplay value);

		/**
		* Gets typesafe enumerated attribute UserDisplay, default = UserDisplay_Display
		*
		* @return EnumUserDisplay: the enumeration value of the attribute
		*/
		virtual EnumUserDisplay GetUserDisplay() const;
			
		/**
		* Typesafe attribute validation of UserDisplay
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidUserDisplay(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}

	
		/* ******************************************************
		// Element Getter / Setter
		**************************************************************** */
		//@{
		/**
		* Gets the iSkip-th element Loc. If doesn't exist, creates it
		*
		* @param int iSkip: number of elements to skip
		* @return JDFLoc: the matching element
		*/
		JDFLoc GetCreateLoc(int iSkip=0);

		/**
		* Gets the iSkip-th element Loc
		*
		* @param int iSkip: number of elements to skip
		* @return JDFLoc: the matching element
		*/
		JDFLoc GetLoc(int iSkip=0)const;

		/**
		* Appends element Loc to the end of 'this'
		*
		* @return JDFLoc: newly created Loc element
		*/
		JDFLoc AppendLoc();
		//@}

		bool FixVersion(JDFElement::EnumVersion version);

	}; // class JDFStateBase
	
	
	
	/**
	* Datatype dependent TEMPLATE class for States <br>
	*
	* Defines the data type dependent parts of a ranged State resource
	*/
	template<class RangeType> 
		class JDF_WRAPPERCORE_EXPORT JDFState : public JDFStateBase{
	

	public:
	/**
	* Empty constructor
		*/
		inline JDFState():JDFStateBase(){};
		/**
		* Copy constructor
		*/
		inline JDFState(const KElement & other):JDFStateBase(){*this=other;};
		/**
		* Equivalence copy ctor
		*/
		inline JDFState&operator =(const KElement& other){
			KElement::operator=(other);
			if(!IsValid(ValidationLevel_Construct)) 
				throw JDFException(L"Invalid constructor for JDFState: "+other.GetNodeName()); 
			return *this;
		};
		/**
		* Destructor
		*/
		virtual ~JDFState(){};
		
		
		//@{
		/**
		* Gets the value of attribute DefaultValue
		*
		* @return RangeType: the attribute value
		*/
		inline RangeType GetDefaultValue(){return GetAttribute(atr_DefaultValue);}
		
		/**
		* Sets the DefaultValue attribute
		*
		* @param RangeType: the value to set the attribute to
		*/
		inline void SetDefaultValue(RangeType n){SetAttribute(atr_DefaultValue,n);}
		
		/**
		* Typesafe attribute validation of DefaultValue
		*
		* @return bool: true, if DefaultValue is valid
		*/
		virtual bool ValidDefaultValue(EnumValidationLevel level)const{
			try{
				if(!HasAttribute(atr_DefaultValue)) 
					return true;
				RangeType nr=GetAttribute(atr_DefaultValue);
			}catch (IllegalArgumentException e){
				return false;
			}catch (JDFException e){
				return false;
			}
			return true;
		};
		//@}
		
		
		//@{
		/**
		* Gets the value of attribute CurrentValue
		*
		* @return RangeType: the attribute value
		*/
		inline RangeType GetCurrentValue(){
			return GetAttribute(atr_CurrentValue);
		}
		
		/**
		* Sets the CurrentValue attribute
		*
		* @param RangeType: the value to set the attribute to
		*/
		inline void SetCurrentValue(RangeType n){
			SetAttribute(atr_CurrentValue,n);
		}
		
		/**
		* Typesafe attribute validation of CurrentValue
		*
		* @return bool: true, if CurrentValue is valid
		*/
		virtual bool ValidCurrentValue(EnumValidationLevel level)const{
			try{
				if(!HasAttribute(atr_CurrentValue)) 
					return true;
				RangeType nr=GetAttribute(atr_CurrentValue);
			}catch (IllegalArgumentException e){
				return false;
			}catch (JDFException e){
				return false;
			}
			return true;
		};
		//@}

	}; // class JDFStateBase / template


}; // namespace JDF


//////////////////////////////////////////////////////////////////////////////////
#endif // !defined(_JDFState_H__)
