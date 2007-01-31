#if !defined(_JDFELEMENT_H__)
#define _JDFELEMENT_H__

/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2006 The International Cooperation for the Integration of 
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
/* *******************************************************************
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
// 110700 | RP | added SetURL
// 180700 RP MyString -> WString : all strings now 16 bit
// 170800 | RP | converted typedef mAttribute to MapWString
// 220800 | RP | threw out some obsolete corpses and reordered / commented this header
// 041000 RP JDFElement now based on KElement : 
// 300401 RP move refElement support from JDFResource to JDFElement since refelements can also 
// 011001 RP added AttributeType_NMTOKENS (note the "S"), AttributeType_enumeration, AttributeType_enumerations
// 021001 RP added enumerationS handling routines for sets of enumerations
// 230102 RP added MergeNode and made it virtual
// 280102 RP added RemoveRefElement, UpDaterRefs
// 280102 RP added AppendComment
// 040202 RP added IncludesAttribute
// 150302 RP added IsResourceUpdate
// 180302 RP added GetValidNodeNames, protected ValidNodeNames
// 230302 RP removed GetElementNameVector
//           added GetChildElementVector
// 300402 RP add SettingsPolicy Support
// 300402 RP removed AppendElement - it is now only in KElement
// 020502 RP added IsJDFNode()
// 070502 RP added RemoveChild() / RemoveChildren
// 080502 RP GetEnumerationsAttribute() bug fix in loop counter
// 160502 RP removed GetTarget(int id,const WString & attrib) const;
// 180502 RP GetJDFRoot, GetJMFRoot now const
// 290502 RP GetLinks added rSubRef check to map of checked attributes
// 300502 RP added NamedColor support
// 300502 RP GetElement - added a check that returns the refElement if a refElement is explicitly required
// 180602 RP added GetSchemaURL()
// 190602 RP ValidAttribute() added catch IllegalArgumentException where appropriate
// 200602 RP ValidAttribute() added enumeration types AttributeType_dateTime,AttributeType_duration
// 210602 RP RemoveChild(), RemoveChildren() - fix for inheritance from JDFResource and partitioning
// 260602 RP RefElement() return type is JDFRefElement and modified usage for parts
// 260602 RP added TestRunInProgress to the valid Status enumerations
// 260602 RP added GetRefElements()
// 260602 RP modified InlineRefElements()
// 010702 RP RefElement bug fix for ResourceElements
// 020702 RP added GetRefString()
// 020702 RP reintroduced GetNameVector()
// 020702 RP GetChildElementVector() now does not follow references
// 050702 RP GetInvalidElements() bug fix for refElement
// 200802 RP EnumNamedColor typo fix for clearlightgray
// 260802 RP GetComment(iSkip) implemented iSkip support
// 300802 RP GetChildElementVector() now skips invalid refelements
// 040902 RP IncludesAttribute() added support for NMTOKENS
// 050902 RP GetChildIds() added ! to throwNull check
// 060902 RP moved all remaining refElement handling from JDFResource to JDFElement and cleaned up refElement
// 060902 RP UniqueID made string a bit longer for uniqueness
// 120902 RP IsAudit() added
// 120902 RP GetHRefs() fixed handling of references in audit elements
// 250902 RP UniqueID() addeed "_" between time and number generated part
// 291002 RP IsRefElement() removed check for rRef
// 291002 RP GetChildElementVector() returns invalid refElements as refElements and does not simply skip them
// 051102 RP added GetLinkRoot();
// 051102 RP GetParentJDF() gets the parent and not this in case this is a JDF node
// 051102 RP IsResource(),IsAudit() now returns false for comments
// 081102 RP IsValid() handle incorrectly specified namespaces gracefully
// 201102 RP InlineRefElements() implement recursion
// 161202 RP GetLinkRoot() added check fir IsResourceRoot() when retrieving from the cache
// 100603 RP added integerlist to attribute types
// 300703 RP removed GetAttribute()
// 041103 RP 
// 290404 RP split off static strings to JDFStrings
// 150605 RP added RequiredOneOfAttribute()
// 090806 NB extended IncludesMatchingAttribute() -> added support for IntegerList and NumberList
// 010906 NB changed UniqueID() access to static public
// 080906 NB added isJDFJMF(), isJDFNodeInfo(), isJDFCustomerInfo()
// 121206 NB GetChildWithMatchingAttribute() fixed, now uses elements instead of refs
// 211206 NB moved EnumAttributeType from JDFElement to KElement (allows StringUtil to move to WrapperCore)
// 250107 NB removed unreferenced variables
// 310107 NB added SetValue() methods for JDFDate and JDFDuration
//
// JDFElement.h: interface for the JDFElement class.
// JDFElement contains generic JDF element functionality
//
********************************************************************/

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include <jdf/wrappercore/KElement.h>
#include <jdf/wrappercore/MyDate.h>

#include "jdf/wrapper/JDFRangeList.h"
#include "jdf/wrapper/JDFIntegerRangeList.h"
#include "jdf/wrapper/JDFNumberRangeList.h" 
#include "jdf/wrapper/JDFNameRangeList.h" 
#include "jdf/wrapper/JDFDateTimeRangeList.h"
#include "jdf/wrapper/JDFDurationRangeList.h"
#include "jdf/wrapper/JDFXYPairRangeList.h" 
#include "jdf/wrapper/JDFStrings.h" 
#include "jdf/wrapper/JDFNumTypeList.h" // this will link in all range types
#include "jdf/wrapper/JDFDate.h"
#include "jdf/wrapper/JDFDuration.h"

#include "jdf/wrappercore/vElement.h"


namespace JDF{

	typedef MapWString mAttribute;  // simple rename

	class JDFDoc;
	class JDFJMF; 
	class JDFNodeList;
	class JDFNode;
	class JDFComment;
	class JDFResource;
	class VoidSet;


	/**
	* JDFElement contains generic JDF element functionality
	* It also inherits from JDFStrings to provide a set of frequently used static strings
	* @Deprecated: The use of JDFElement::atr_xyz is deprecated, use JDFStrings::atr_xyz instead
	*/
	class JDF_WRAPPERCORE_EXPORT JDFElement : public KElement, public JDFStrings{
	public:
		friend class JDFRefElement;
		/**
		* Construction / Destruction
		*/
		//@{		
		/**
		* Empty constructor
		*/
		inline JDFElement():KElement(){};

		/** 
		* Copy constructor <br>
		* Creates a new JDFElement object by copying the KElement object 'other'
		*/
		inline JDFElement(const KElement & other):KElement(){
			*this=other;
		};

		/**
		* Equivalence copy constructor <br>
		* Assignment of KElement object 'other' to the current JDFElement object
		*
		* @param KElement& other: KElement object to assign
		* @throws JDFException if constructor for JDFElement is invalid
		*/
		JDFElement &operator =(const KElement& other);

		/**
		* Destructor
		*/
		virtual ~JDFElement(){};
		//@}

		/**
		* Mother of all validators
		* @param EnumValidationLevel level: validation level
		* level ValidationLevel_None: always return true;
		* level ValidationLevel_Construct: incomplete and null elements are valid. 
		*									Checks for legal element names as defined by @see GetValidNodeNames()
		* level ValidationLevel_Incomplete: incomplete  elements are valid
		* level ValidationLevel_Complete: full validation
		* level ValidationLevel_RecursiveIncomplete: incomplete validation but follow links
		* level ValidationLevel_RecursiveComplete: full validation and follow links downward
		* @return bool: the validity of the node
		*/
		virtual bool IsValid(EnumValidationLevel level=ValidationLevel_Complete)const;

		


		/**
		* Version to identify the version of a node or resource 
		*
		* NOTE: If not specified the version defaults to Version 1.3
		*/
		enum EnumVersion{Version_Unknown,Version_1_0,Version_1_1,Version_1_2,Version_1_3,Version_1_4,Version_1_5,Version_1_6,Version_1_7,Version_1_8,Version_1_9};

		/**
		* Enumeration strings for Version
		*
		* @return WString&: comma separated list of enumerated string values 
		*/
		static const WString& VersionString();


		/**
		* Enumeration string for enum value Version
		* Converts the value of type EnumVersion into corresponding string value,  
		* f.e. for EnumVersion with value 'Version_1_1' returns '1.1' 
		*
		* @param EnumVersion value: Version enumeration value to convert
		* @return WString: Version string value
		*/
		static WString VersionString(EnumVersion value);

		/**
		* Get string attribute Version from closest element that may legally have a version
		* @param bool bInherit: recurse through ancestors when searching
		* @return WString: the value of the attribute 
		*/
		virtual WString GetVersion(bool bInherit=false) const;

		/**
		* Get enum attribute Version from closest element that may legally have a version
		* @param bool bInherit: recurse through ancestors when searching
		* @return JDFElement::EnumVersion: the enum representative of the attribute 
		*/
		virtual JDFElement::EnumVersion GetEnumVersion(bool bInherit=false) const;

		/**
		* Mother of all version fixing routines
		*
		* uses heuristics to modify this element and its children to be compatible with a given version
		* in general, it will be able to move from low to high versions but potentially fail 
		* when attempting to move from higher to lower versions
		*
		* @param EnumVersion version: version that the resulting element should correspond to
		* @param bool true if successful
		*/
		virtual bool FixVersion(EnumVersion version);


		/** 
		* Access to SettingsPolicy enumerations used by both JDFResource and JDFNode
		*/
		enum EnumSettingsPolicy{SettingsPolicy_Unknown,SettingsPolicy_BestEffort,SettingsPolicy_MustHonor,SettingsPolicy_OperatorIntervention};


		//@{
		/**
		* Enumeration  for Orientation
		*/
		enum EnumOrientation{Orientation_Unknown,Orientation_Flip0,Orientation_Flip90,Orientation_Flip180,Orientation_Flip270,Orientation_Rotate0,Orientation_Rotate90,Orientation_Rotate180,Orientation_Rotate270};

		/**
		* Enumeration strings for Orientation
		*
		* @return WString&: comma separated list of enumerated string values 
		*/
		static const WString& OrientationString();

		/**
		* Enumeration string for enum value Orientation
		* Converts the value of type EnumOrientation into corresponding string value,  
		* f.e. for EnumOrientation with value 'Orientation_Flip90' returns 'Flip90' 
		*
		* @param EnumOrientation value: Orientation enumeration value to convert
		* @return WString: Orientation string value
		*/
		static WString OrientationString(EnumOrientation value);
		//@}


		//@{
		/**
		* Enumeration for attribute NamedColor
		*/
		enum EnumNamedColor { NamedColor_Unknown,NamedColor_White,NamedColor_Black,NamedColor_Gray,NamedColor_Red,NamedColor_Yellow,NamedColor_Green,NamedColor_Blue,NamedColor_Turquoise,NamedColor_Violet,NamedColor_Orange,NamedColor_Brown,NamedColor_Gold,NamedColor_Silver,NamedColor_Pink,NamedColor_Buff,NamedColor_Ivory,NamedColor_Goldenrod,NamedColor_Mustard,NamedColor_MultiColor,NamedColor_Cyan,NamedColor_Magenta,
			NamedColor_DarkWhite,NamedColor_DarkBlack,NamedColor_DarkGray,NamedColor_DarkRed,NamedColor_DarkYellow,NamedColor_DarkGreen,NamedColor_DarkBlue,NamedColor_DarkTurquoise,NamedColor_DarkViolet,NamedColor_DarkOrange,NamedColor_DarkBrown,NamedColor_DarkGold,NamedColor_DarkSilver,NamedColor_DarkPink,NamedColor_DarkBuff,NamedColor_DarkIvory,NamedColor_DarkGoldenrod,NamedColor_DarkMustard,NamedColor_DarkMultiColor,NamedColor_DarkCyan,NamedColor_DarkMagenta,
			NamedColor_LightWhite,NamedColor_LightBlack,NamedColor_LightGray,NamedColor_LightRed,NamedColor_LightYellow,NamedColor_LightGreen,NamedColor_LightBlue,NamedColor_LightTurquoise,NamedColor_LightViolet,NamedColor_LightOrange,NamedColor_LightBrown,NamedColor_LightGold,NamedColor_LightSilver,NamedColor_LightPink,NamedColor_LightBuff,NamedColor_LightIvory,NamedColor_LightGoldenrod,NamedColor_LightMustard,NamedColor_LightMultiColor,NamedColor_LightCyan,NamedColor_LightMagenta,
			NamedColor_ClearWhite,NamedColor_ClearBlack,NamedColor_ClearGray,NamedColor_ClearRed,NamedColor_ClearYellow,NamedColor_ClearGreen,NamedColor_ClearBlue,NamedColor_ClearTurquoise,NamedColor_ClearViolet,NamedColor_ClearOrange,NamedColor_ClearBrown,NamedColor_ClearGold,NamedColor_ClearSilver,NamedColor_ClearPink,NamedColor_ClearBuff,NamedColor_ClearIvory,NamedColor_ClearGoldenrod,NamedColor_ClearMustard,NamedColor_ClearMultiColor,NamedColor_ClearCyan,NamedColor_ClearMagenta,
			NamedColor_ClearDarkWhite,NamedColor_ClearDarkBlack,NamedColor_ClearDarkGray,NamedColor_ClearDarkRed,NamedColor_ClearDarkYellow,NamedColor_ClearDarkGreen,NamedColor_ClearDarkBlue,NamedColor_ClearDarkTurquoise,NamedColor_ClearDarkViolet,NamedColor_ClearDarkOrange,NamedColor_ClearDarkBrown,NamedColor_ClearDarkGold,NamedColor_ClearDarkSilver,NamedColor_ClearDarkPink,NamedColor_ClearDarkBuff,
			NamedColor_ClearDarkIvory,NamedColor_ClearDarkGoldenrod,NamedColor_ClearDarkMustard,NamedColor_ClearDarkMultiColor,NamedColor_ClearDarkCyan,NamedColor_ClearDarkMagenta,NamedColor_ClearLightWhite,NamedColor_ClearLightBlack,NamedColor_ClearLightGray,NamedColor_ClearLightRed,NamedColor_ClearLightYellow,NamedColor_ClearLightGreen,NamedColor_ClearLightBlue,NamedColor_ClearLightTurquoise,NamedColor_ClearLightViolet,NamedColor_ClearLightOrange,NamedColor_ClearLightBrown,NamedColor_ClearLightGold,
			NamedColor_ClearLightSilver,NamedColor_ClearLightPink,NamedColor_ClearLightBuff,NamedColor_ClearLightIvory,NamedColor_ClearLightGoldenrod,NamedColor_ClearLightMustard,NamedColor_ClearLightMultiColor,NamedColor_ClearLightCyan,NamedColor_ClearLightMagenta,NamedColor_NoColor
		};

		/**
		* Enumeration strings for NamedColors
		*
		* @return WString&: comma separated list of enumerated string values 
		*/
		static const WString& NamedColorString();

		/**
		* Enumeration string for enum value <br>
		* Converts the value of type EnumNamedColor into corresponding string value,  
		* f.e. for EnumNamedColor with value 'NamedColor_White' returns 'White' 
		*
		* @param EnumNamedColor value: NamedColor enumeration value to convert
		* @return WString: NamedColor string value
		*/
		static WString NamedColorString(EnumNamedColor value);
		//@}


		//@{
		/**
		* Enumeration for attribute Status of nodes audits etc.
		*/	
		enum EnumStatus{Status_Unknown,Status_Waiting,Status_TestRunInProgress,Status_Ready,Status_FailedTestRun,Status_Setup,Status_InProgress,Status_Cleanup,Status_Spawned,Status_Suspended,Status_Stopped,Status_Completed,Status_Aborted,Status_Pool,Status_Part};

		/**
		* Enumeration strings for Status. 
		* Status is for node status and message execution status
		* the Resource status enumeration is defined in @see JDFResource
		*
		* @return WString&: comma separated list of enumerated string values
		*/
		static const WString& StatusString();

		/**
		* Enumeration string for enum value. 
		* Converts the value of type EnumStatus into corresponding string value
		* f.e. for EnumStatus with value 'Status_Waiting' returns 'Waiting'
		*
		* @param EnumStatus value: Status enumeration value to convert
		* @return WString: Status string value
		*/
		static WString StatusString(EnumStatus value);

		/**
		* Sets attribute Status
		*
		* @param EnumStatus value: value to set the attribute to
		*/
		void SetStatus( EnumStatus value);

		/**
		* Gets typesafe enumerated value of attribute Status
		*
		* @return EnumStatus: the attribute value
		*/
		EnumStatus GetStatus() const;

		/** 
		* Typesafe attribute validation of Status
		* note that this is JDF/@Status and derived stati. 
		* Resource/@Status is defined in JDFResource
		*
		* @param EnumValidationLevel level: attribute validation level
		* @return bool: true, if valid
		*/
		virtual bool ValidStatus(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/** 
		* Enumeration for attribute XYRelation
		*/
		enum EnumXYRelation{XYRelation_Unknown,XYRelation_gt,XYRelation_ge,XYRelation_eq,XYRelation_le,XYRelation_lt,XYRelation_ne};

		/**
		* Enumeration strings for XYRelations
		*
		* @return WString&: comma separated list of enumerated string values 
		*/
		static const WString& XYRelationString();

		/**
		* Enumeration string for enum value <br>
		* Converts the value of type EnumXYRelation into corresponding string value,  
		* f.e. for EnumXYRelation with value 'XYRelation_gt' returns 'gt' 
		*
		* @param EnumXYRelation value: XYRelation enumeration value to convert
		* @return WString: XYRelation string value
		*/
		static WString XYRelationString(EnumXYRelation value);

		/** 
		* Tests if relation x/y matches XYRelation enumeration value
		*
		* @param EnumXYRelation value: XYRelation enumeration value to compare x/y with
		* @param double x: x in XYRelation ( x/y )
		* @param double y: y in XYRelation ( x/y )
		* @param double nt: negative tolerance
		* @param double pt: positive tolerance
		* @return bool: true if relation x/y matches specified enumerated value 
		*/
		bool XYRelation(EnumXYRelation value, double x, double y, double nt=0, double pt=0 ) const ;
		//@}


		/**
		* typesafe separation support
		*/
		//@{		
		/**
		* Enumeration the predefined separations
		*/	
		enum EnumSeparation{Separation_Unknown,Separation_Cyan,Separation_Magenta,Separation_Yellow,Separation_Black,Separation_Red,Separation_Green,Separation_Blue,Separation_Orange,Separation_Spot,Separation_Varnish};

		/**
		* Enumeration strings for separations
		*
		* @return WString&: a comma separated list of enumerated string values
		*/
		static const WString& SeparationString();

		/**
		* Enumeration string for enum value <br>
		* Converts the value of type EnumSeparation into corresponding string value,  
		* f.e. for EnumSeparation with value 'Separation_Cyan' returns 'Cyan' 
		*
		* @param EnumSeparation value: Separation enumeration value to convert
		* @return WString: Separation string value 
		*/
		static WString SeparationString(EnumSeparation value);
		//@}

		//@{
		/**
		* enum for FitsValue method, switches between Allowed and Present testlists 
		*/
		enum EnumFitsValue{FitsValue_Unknown,FitsValue_Allowed,FitsValue_Present};

		/**
		* Enumeration strings for FitsValue
		*
		* @return const WString&: comma separated list of enumerated string values 
		*/
		static const WString& FitsValueString();

		/**
		* Enumeration string for enum value
		*
		* @param EnumFitsValue value: the enumeration to translate
		* @return WString: the string representation of the enumeration
		*/
		static const WString FitsValueString(EnumFitsValue value);
		//@}

		/**
		* definition of optional elements in the JDF namespace
		*
		* @return WString: comma separated list of optional element names
		*/
		virtual WString OptionalElements()const;

		/**
		* definition of optional attributes in the JDF namespace
		*
		* @return WString: comma separated list of optional attribute names
		*/
		virtual WString OptionalAttributes()const;

		/**
		* definition of the allowed node names for elements of this type
		*
		* @return vWString: vector of valid node names, * if any
		*/
		virtual vWString GetValidNodeNames()const;

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
		* typesafe validator
		*
		* @param EnumValidationLevel level: validation level
		* @param bool bIgnorePrivate: if true, do not worry about elements in other namespaces
		* @param int nMax: maximum size of the returned vector
		* @return vWString: a vector of invalid element names
		*/
		virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;

		/**
		* check whether this matches a simple xpath also recursively follows rRefs
		* @param path
		* @return
		*/
		bool matchesPath(WString path, bool bFollowRefs);


	protected:

		/**    
		* Enumeration strings for attribute SettingsPolicy <br>
		* SettingsPolicy is for node SettingsPolicy and message execution SettingsPolicy
		* the Resource SettingsPolicy enumeration is defined in @see JDFResource
		*
		* @return WString&: comma separated list of enumerated string values
		*/
		static const WString& SettingsPolicyString();

		/**
		* Enumeration string for enum value <br>
		* Converts the value of type EnumSettingsPolicy into corresponding string value,
		* f.e. for EnumSettingsPolicy with value 'SettingsPolicy_BestEffort' returns 'BestEffort'
		* 
		* @param EnumSettingsPolicy value: SettingsPolicy enumeration value to convert
		* @return WString: SettingsPolicy string value
		*/
		static WString SettingsPolicyString(EnumSettingsPolicy value);

		/**
		* Sets attribute SettingsPolicy 
		*
		* @param EnumSettingsPolicy value: the enumeration value of attribute SettingsPolicy to be set
		*/
		virtual void SetSettingsPolicy( EnumSettingsPolicy value);

		/**
		* Gets typesafe enumerated value of attribute SettingsPolicy 
		*
		* @param bool bInherit: if true, searches recursive through ancestors. default=false
		* @return EnumSettingsPolicy: the enumeration value of attribute SettingsPolicy 
		*/
		EnumSettingsPolicy GetSettingsPolicy(bool bInherit=false) const;

		/** 
		* Typesafe attribute validation of SettingsPolicy
		*
		* @param EnumValidationLevel level: level of validation
		* @return bool: true, if valid
		*/
		virtual bool ValidSettingsPolicy(EnumValidationLevel level=ValidationLevel_Complete) const;

	public:
		/**
		* Gets the root resource of the target
		* returns a null JDFResource if it does not exist or the name mangling is illegal
		*
		* @param WString id: the id of the resource to search. if null, get from the rRef attribute
		* @return JDFResource: the resource root of the resource referenced by this resource link
		*/
		JDFResource GetLinkRoot(const WString& id=WString::emptyStr)const;

		/**
		* Gets typesafe enumerated value of attribute with name 'key'
		*
		* @param WString& key: name of attribute to search 
		*/
		EnumSettingsPolicy GetAttributeSettingsPolicy(const WString& key) const;


		//@{
		/**
		* Sets attribute BestEffortExceptions with the vector of values
		*
		* @param vWString& value: the vector of BestEffortExceptions tokens
		*/
		virtual void SetBestEffortExceptions( const vWString& value);

		/**
		* Appends a token to attribute BestEffortExceptions
		*
		* @param WString& value: the new token of BestEffortExceptions 
		*/
		virtual void AppendBestEffortExceptions( const WString& value);

		/**
		* Removes a token from attribute BestEffortExceptions
		*
		* @param WString& value: the new token of BestEffortExceptions 
		*/
		virtual void RemoveFromBestEffortExceptions( const WString& value);

		/**
		* Gets typesafe enumerated value of attribute BestEffortExceptions
		*
		* @return vWString: the attribute value
		*/
		virtual vWString GetBestEffortExceptions() const;

		/** 
		* Typesafe attribute validation of BestEffortExceptions
		* 
		* @param EnumValidationLevel level: validation level
		* @return bool: true, if valid
		*/
		virtual bool ValidBestEffortExceptions(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute MustHonorExceptions with the vector of values
		*
		* @param vWString& value: the vector of MustHonorExceptions tokens
		*/
		virtual void SetMustHonorExceptions( const vWString& value);

		/**
		* Appends a token to attribute MustHonorExceptions
		*
		* @param WString& value: the new token of MustHonorExceptions 
		*/
		virtual void AppendMustHonorExceptions( const WString& value);

		/**
		* Removes a token from attribute MustHonorExceptions
		*
		* @param WString& value: the new token of MustHonorExceptions 
		*/
		virtual void RemoveFromMustHonorExceptions( const WString& value);

		/**
		* Gets typesafe enumerated value of attribute MustHonorExceptions
		*
		* @return vWString: the attribute value
		*/
		virtual vWString GetMustHonorExceptions() const ;

		/** 
		* Typesafe attribute validation of MustHonorExceptions
		*
		* @param EnumValidationLevel level: validation level
		* @return bool: true, if valid
		*/
		virtual bool ValidMustHonorExceptions(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute OperatorInterventionExceptions with the vector of values
		*
		* @param vWString& value: the vector of OperatorInterventionExceptions tokens
		*/
		virtual void SetOperatorInterventionExceptions( const vWString& value);

		/**
		* Appends a token to attribute OperatorInterventionExceptions
		*
		* @param WString& value: the new of OperatorInterventionExceptions token
		*/
		virtual void AppendOperatorInterventionExceptions( const WString& value);

		/**
		* Removes a token from attribute OperatorInterventionExceptions
		*
		* @param WString& value: the new of OperatorInterventionExceptions token
		*/
		virtual void RemoveFromOperatorInterventionExceptions( const WString& value);

		/**
		* Gets typesafe enumerated value of attribute OperatorInterventionExceptions
		*
		* @return vWString: the attribute value
		*/
		virtual vWString GetOperatorInterventionExceptions() const;

		/** 
		* Typesafe attribute validation of OperatorInterventionExceptions
		*
		* @param EnumValidationLevel level: validation level
		* @return bool: true, if valid
		*/
		virtual bool ValidOperatorInterventionExceptions(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute CommentURL
		*
		* @param WString value: value to set the attribute to
		*/
		inline void SetCommentURL(WString value){SetAttribute(JDFStrings::atr_CommentURL,value);}

		/**
		* Gets string attribute CommentURL
		*
		* @return WString: the attribute value
		*/
		inline WString GetCommentURL() const {return GetAttribute(JDFStrings::atr_CommentURL);}

		/**
		* Typesafe attribute validation of CommentURL
		*
		* @param EnumValidationLevel level: attribute validation level
		* @return bool: true, if valid
		*/
		virtual bool ValidCommentURL(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Sets attribute DescriptiveName
		*
		* @param WString value: value to set the attribute to
		*/
		virtual void SetDescriptiveName(WString value);

		/**
		* Gets string attribute DescriptiveName
		*
		* @return WString: the attribute value
		*/
		virtual WString GetDescriptiveName() const;

		/**
		* Typesafe attribute validation of DescriptiveName
		* 
		* @param EnumValidationLevel level: attribute validation level
		* @return bool: true, if valid
		*/
		virtual bool ValidDescriptiveName(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/** 
		* Appends element Comment to the end of 'this'
		*
		* @return JDFComment: newly created Comment element		
		*/
		JDFComment AppendComment();

		/**
		* Gets the iSkip-th element Comment. If doesn't exist, creates it
		*
		* @param int iSkip: number of elements to skip
		* @return JDFComment: the matching element
		*/
		JDFComment GetCreateComment(int iSkip=0);

		/** 
		* Gets the iSkip-th element Comment
		*
		* @param int iSkip: number of elements to skip
		* @return JDFComment: the matching element		
		*/
		JDFComment GetComment(int iSkip=0)const;
		//@}



		/**
		* Mother of all initializers
		* @return bool: true if successful
		*/
		virtual bool init();




		/**
		* Gets the one and reference to an ID
		*
		* @return WString: the rRef attribute
		*/
		inline WString GetHRef()const{
			return GetAttribute(JDFStrings::atr_rRef);
		};

		/**
		* Appends a reference to a target node
		* automatically generate a unique ID attribute for target, if it does not exist
		*
		* @param JDFElement target: the element to reference
		* @param WString& refAttribute: name of the refering attribute, e.g. hRef, rRef
		* @param WString& preSet: value of the ID attribute - defaults to autogenerated
		*/
		void AppendHRef(JDFElement target, const WString & refAttribute=JDFStrings::atr_rRef, const WString & preSet=WString::emptyStr);

		/**
		* appends a reference with a specific id
		*
		* @param WString& idRef: value of the ID-IDREF pair
		* @param WString refAttribute: value of the IDREF tag
		* @param WString& nameSpaceURI: nameSpaceURI of the IDREF tag
		*/
		void AppendHRef(const WString & idRef, WString refAttribute=JDFStrings::atr_rRef,const WString & nameSpaceURI=WString::emptyStr);

		/**
		*   Mother of all Attribute setters
		* Adds a new attribute. If an attribute with that name is already present in
		* the element, its value is changed to be that of the value parameter. This
		* value is a simple string; it is not parsed as it is being set. So any
		* markup (such as syntax to be recognized as an entity reference) is treated
		* as literal text, and needs to be appropriately escaped by the
		* implementation when it is written out. In order to assign an attribute
		* value that contains entity references, the user must create an Attr node
		* plus any Text and EntityReference nodes, build the appropriate subtree,
		* and use setAttributeNode to assign it as the value of an attribute.
		*
		* @param WString& key: the name of the attribute to create or alter.
		* @param WString& value: value to set in string form.
		* @param WString& nameSpaceURI: the namespace of the attribute 
		*/
		virtual void SetAttribute(const WString & key, const WString & value, const WString & nameSpaceURI=WString::emptyStr);

		/**
		* Sets an element attribute
		*
		* @param WString& key: the name of the attribute to set
		* @param unsigned int value: the value for the attribute
		* @param WString& nameSpaceURI: the namespace the element is in
		*/
		inline void SetAttribute(const WString & key, const unsigned int value, const WString & nameSpaceURI=WString::emptyStr){
			KElement::SetAttribute(key,WString::valueOf(value),nameSpaceURI);
		}

		/**
		* Sets an element attribute
		*
		* @param WString& key: the name of the attribute to set
		* @param int value: the value for the attribute
		* @param WString& nameSpaceURI: the namespace the element is in
		*/
		inline void SetAttribute(const WString & key, const int value, const WString & nameSpaceURI=WString::emptyStr){
			KElement::SetAttribute(key,WString::valueOf(value),nameSpaceURI);
		}


		/**
		* Sets an element attribute
		*
		* @param WString& key: the name of the attribute to set
		* @param double value: the value for the attribute
		* @param WString& nameSpaceURI: the namespace the element is in
		*/
		inline void SetAttribute(const WString & key, const double value, const WString & nameSpaceURI=WString::emptyStr){
			KElement::SetAttribute(key,WString::valueOf(value),nameSpaceURI);
		}


		/**
		* Sets an element attribute
		*
		* @param WString& key: the name of the attribute to set
		* @param bool b: value of the boolean attribute (true or false)
		* @param WString& nameSpaceURI: the nameSpace the attribute is in
		*/
		inline void SetAttribute(const WString & key, const bool b, const WString & nameSpaceURI=WString::emptyStr){
			KElement::SetAttribute(key,b?JDFStrings::atr_true:JDFStrings::atr_false,nameSpaceURI);
		}

		/**
		* Adds a new attribute. If an attribute with that name is already present in
		* the element, its value is changed to be that of the value parameter. This
		* value is a simple string; it is not parsed as it is being set. So any
		* markup (such as syntax to be recognized as an entity reference) is treated
		* as literal text, and needs to be appropriately escaped by the
		* implementation when it is written out. In order to assign an attribute
		* value that contains entity references, the user must create an Attr node
		* plus any Text and EntityReference nodes, build the appropriate subtree,
		* and use setAttributeNode to assign it as the value of an attribute.
		* To set an attribute with a qualified name and namespace URI, use the
		* setAttributeNS method.
		*
		* @param WString& key: the name of the attribute to create or alter.
		* @param char* value: value to set in string form
		* @param WString& nameSpaceURI: the nameSpace the attribute is in
		*/
		inline void SetAttribute(const WString & key, const char* value, const WString & nameSpaceURI=WString::emptyStr){
			KElement::SetAttribute(key,WString(value),nameSpaceURI);
		}

		/**
		* Sets an element attribute
		*
		* @param WString& key: the name of the attribute to set
		* @param wchar_t* value: the value for the attribute
		* @param WString& nameSpaceURI: the namespace the element is in
		*/		
		inline void SetAttribute(const WString & key, const wchar_t* value, const WString & nameSpaceURI=WString::emptyStr){
			KElement::SetAttribute(key,WString(value),nameSpaceURI);
		}


		/**
		* Sets an element attribute
		*
		* @param WString& key: the name of the attribute to set
		* @param JDFNumList& value: the value for the attribute
		* @param WString& nameSpaceURI: the namespace the element is in
		*
		* @deprecated use SetAttribute(key,value.GetString(),nameSpaceURI)
		*/		
		void SetAttribute(const WString & key, const JDFNumList& value, const WString & nameSpaceURI=WString::emptyStr);

		/**
		* Sets an element attribute
		*
		* @param WString& key: the name of the attribute to set
		* @param NumberRange& value: the value for the attribute
		* @param WString& nameSpaceURI: the namespace the element is in
		*
		* @deprecated use SetAttribute(key,value.GetString(),nameSpaceURI)
		*/
		void SetAttribute(const WString & key, const NumberRange& value, const WString & nameSpaceURI=WString::emptyStr);

		/**
		* Sets an element attribute
		*
		* @param WString& key: the name of the attribute to set
		* @param IntegerRange& value: the value for the attribute
		* @param WString& nameSpaceURI: the namespace the element is in
		*
		* @deprecated use SetAttribute(key,value.GetString(),nameSpaceURI)
		*/
		void SetAttribute(const WString & key, const IntegerRange& value, const WString & nameSpaceURI=WString::emptyStr);		

		/**
		* Sets an element attribute
		*
		* @param WString& key: the name of the attribute to set
		* @param NameRange& value: the value for the attribute
		* @param WString& nameSpaceURI: the namespace the element is in
		*
		* @deprecated use SetAttribute(key,value.GetString(),nameSpaceURI)
		*/
		void SetAttribute(const WString & key, const NameRange& value, const WString & nameSpaceURI=WString::emptyStr);

		/**
		* Sets an element attribute
		*
		* @param WString& key: the name of the attribute to set
		* @param JDFDate& value: the value for the attribute
		* @param WString& nameSpaceURI: the namespace the element is in
		*
		* @deprecated use SetAttribute(key,value.GetString(),nameSpaceURI)
		*/
		void SetAttribute(const WString & key, const JDFDate& value, const WString & nameSpaceURI=WString::emptyStr);

		/**
		* Sets an element attribute
		*
		* @param WString& key: the name of the attribute to set
		* @param JDFDuration& value: the value for the attribute
		* @param WString& nameSpaceURI: the namespace the element is in
		*
		* @deprecated use SetAttribute(key,value.GetString(),nameSpaceURI)
		*/
		void SetAttribute(const WString & key, const JDFDuration& value, const WString & nameSpaceURI=WString::emptyStr);

		/**
		* Sets an element attribute
		*
		* @param WString& key: the name of the attribute to set
		* @param NumberRangeList& value: the value for the attribute
		* @param WString& nameSpaceURI: the namespace the element is in
		*
		* @deprecated use SetAttribute(key,value.GetString(),nameSpaceURI)
		*/
		void SetAttribute(const WString & key, const JDFNumberRangeList& value, const WString & nameSpaceURI=WString::emptyStr);

		/**
		* Sets an element attribute
		*
		* @param WString& key: the name of the attribute to set
		* @param IntegerRangeList& value: the value for the attribute
		* @param WString& nameSpaceURI: the namespace the element is in
		*
		* @deprecated use SetAttribute(key,value.GetString(),nameSpaceURI)
		*/
		void SetAttribute(const WString & key, const JDFIntegerRangeList& value, const WString & nameSpaceURI=WString::emptyStr);

		/**
		* Sets an element attribute
		*
		* @param WString& key: the name of the attribute to set
		* @param XYPairRange& value: the value for the attribute
		* @param WString& nameSpaceURI: the namespace the element is in
		*
		* @deprecated use SetAttribute(key,value.GetString(),nameSpaceURI)
		*/
		void SetAttribute(const WString & key, const JDFXYPairRange& value, const WString & nameSpaceURI=WString::emptyStr);

		/**
		* Sets an element attribute
		*
		* @param WString& key: the name of the attribute to set
		* @param JDFXYPairRangeList& value: the value for the attribute
		* @param WString& nameSpaceURI: the namespace the element is in
		*
		* @deprecated use SetAttribute(key,value.GetString(),nameSpaceURI)
		*/
		void SetAttribute(const WString & key, const JDFXYPairRangeList& value, const WString & nameSpaceURI=WString::emptyStr);



		/**
		// link support using ID as a generic id attribute name
		*/
		//@{

		/**
		* Sets attribute ID
		*
		* @param WString value: value to set the attribute to
		*/
		virtual void SetID(WString value);

		/**
		* Gets string attribute ID
		*
		* @return WString: the attribute value
		*/
		virtual WString GetID() const;

		/**
		* Typesafe attribute validation of ID
		*
		* @param EnumValidationLevel level: attribute validation level
		* @return bool: true, if valid
		*/
		virtual bool ValidID(EnumValidationLevel level=ValidationLevel_Complete) const;

		/**
		* Gets a vector of all known id's in child nodes
		*
		* @param WString& attrib: attribute name of the ID attribute, defaults to "ID"
		* @param WString& element: name of the elements to be searched
		* @param WString& nameSpaceURI: attribute namespace uri of the elements to include in the list
		* @return vWString: a set of all known ID elements
		*/
		vWString GetChildIds(const WString & attrib=atr_ID,const WString & element=WString::star,const WString & nameSpaceURI=WString::emptyStr)const;

		/**
		* Gets all elements that link to 'this'
		*
		* @param WString& elementName: name of the elements you are searching for
		* @param WString& nameSpaceURI: attribute namespace you are searching in
		* @return vElement vector: vector of all elements that have a reference to 'this'
		*/
		virtual vElement GetLinks(const WString &elementName=WString::star,const WString & nameSpaceURI=WString::emptyStr)const;

		/**
		* Gets the target element of a link (string id)
		*
		* @return JDFElement: the element that this reference refers to
		*/
		JDFElement GetTarget()const;

		/**
		* &%$§! ms compiler forgets inherited functions
		* overwrites KElement
		*
		* @param String id: value of the ID to search
		* @param String attrib: name of the ID tag, defaults to "ID"
		* @return JDFElement: the element that this reference refers to
		*/
		JDFElement GetTarget(const WString & id, const WString & attrib=atr_ID) const;


		/**
		* Gets the jdf root, document
		* 
		* @return JDFNode: The root of the JDF File
		*/
		JDFNode GetJDFRoot()const;

		/**
		* Gets the jmf root
		*
		* @return JMFRoot: JMF Root 
		*/
		JDFJMF GetJMFRoot()const;

		/**
		* Tests, if 'this' is a refElement
		*
		* @return bool: true if 'this' is a refElement
		*/
		bool IsRefElement()const;

		/**
		* Tests, if 'this' is a Resource
		*
		* @param bool createFactory if true generate a factory class and recursively check 
		* internally required in order to avoid infinite loops
		* @return bool: true if 'this' is a resource and a resource root
		*/
		virtual bool IsResource(bool createFactory=true)const;

		/**
		* Tests, if 'this' is a Span
		*
		* @return bool: true if 'this' is a Span
		*/
		bool IsSpan()const;

		/**
		* Tests, if 'this' is an Audit
		*
		* @return bool: true if 'this' is an Audit
		*/
		bool IsAudit()const;

		/**
		* Tests, if 'this' is a ResourceUpdate
		*
		* @return bool: true if 'this' is a ResourceUpdate 
		*/
		bool IsResourceUpdate()const;

		/**
		* Tests, if 'this' is a ResourceLink
		*
		* @return bool: true if 'this' is a ResourceLink 
		*/
		bool IsResourceLink()const;

		/**
		* Tests, if 'this' is a Comment
		*
		* @return bool: true if 'this' is a Comment 
		*/
		bool IsComment()const;

		/**
		* Tests, if 'this' a JDF Node
		*
		* @return bool: true if 'this' is a JDF Node
		*/
		bool IsJDFNode()const;

		/**
		* Tests, if 'this' a JDF JMF
		*
		* @return bool: true if 'this' is a JDF JMF
		*/
		bool isJDFJMF()const;

		/**
		* Tests, if 'this' a JDFNodeInfo
		*
		* @return bool: true if 'this' is a JDFNodeInfo
		*/
		bool isJDFNodeInfo()const;

		/**
		* Tests, if 'this' a JDFCustomerInfo
		*
		* @return bool: true if 'this' is a JDFCustomerInfo
		*/
		bool isJDFCustomerInfo()const;

		/**
		* Tests, if this element is in the JDF namespace
		*
		* @return bool: true if 'this' is in a JDF namespace
		*/
		bool IsInJDFNameSpace()const;

		/** 
		* Creates an inter resource link from child to target.
		* also handles filling of rrefs etc.<br>
		* note that the implementor of the target is potentially modified 
		*
		* @param JDFResource& target: the target resource of the refelement
		* @return JDFRefElement: the newly created refelement
		*
		* @throws JDFException if you are trying to add references NOT from a resource, NodeInfo or CustomerInfo
		* @throws JDFException if target is not a resource or resource element
		*/
		JDFRefElement RefElement(const JDFResource& target);

		/**
		* ID manipulation: adds resID to the rRefs attribute of the root resource 
		* checks for double values
		*
		* @param WString & resID: 
		* @return vWString: 
		*
		* @deprecated 
		*/
		vWString AddResID(const WString & resID);

		/**
		* Gets inter-resource linked resource ids
		*
		* @param vWString vDoneRefs:									
		* @param bool bRecurse: if true, also return recursively linked IDS
		* @return vWString: the vector of referenced resource ids
		*/
		vWString GetHRefs(const vWString& vDoneRefs=vWString::emptyvStr, bool bRecurse=false, bool bExpand=false)const;

		/**
		* Gets inter-resource linked resource ids
		*
		* @param vElement vDoneRefs:									
		* @param bool bRecurse: if true, also return recursively linked IDS
		* @return vElement: the vector of all refElements
		*/
		virtual VoidSet* GetAllRefs(VoidSet* vDoneRefs, bool bRecurse=false)const;

		/**
		* Gets inter-resource linked resource vector
		*
		* @param bRecurse: if true, also return recursively linked IDS
		* @return vElement: inter-resource linked resource vector
		*/
		vElement GetvHRefRes(bool bRecurse=false)const;

		/** 
		* Removes an inter resource link from child to target.
		* also handles filling of rrefs etc.
		*
		* @param JDFElement& target: the target of the refelement to remove
		*
		* @throws JDFException if target has no id
		*/		
		void RemoveRefElement(const JDFElement& target);

		/** 
		* Gets vector of all refelements
		*
		* @return vElement the vector of all refelements 
		* (the refelements themselves, not the referenced objects)
		*/		
		vElement GetRefElements()const;


		//@{
		/**
		* Sets attribute rRefs
		*
		* @param vWString value: value to set the attribute to
		*/
		virtual void SetrRefs(vWString value);

		/**
		* Appends token to attribute rRefs if it is not yet in the list
		*
		* @param WString& value: the rRef token to append
		*/
		inline void AppendrRefs(const WString& value){
			AppendAttribute(JDFStrings::atr_rRefs,value,WString::emptyStr,WString::blank,true);
		};

		/**
		* Removes value from attribute rRefs if it is in the list
		*
		* @param WString& value: the rRef token to remove from the NMTOKENS list
		*/
		inline int RemoveFromrRefs(const WString& value){
			return RemoveFromAttribute(JDFStrings::atr_rRefs,value);
		};

		/**
		* Gets string attribute rRefs
		*
		* @return vWString: the attribute value
		*/
		inline vWString GetrRefs() const {
			return GetAttribute(JDFStrings::atr_rRefs);
		};

		/**
		* Typesafe attribute validation of rRefs
		*
		* @param EnumValidationLevel level: attribute validation level
		* @return bool: true, if valid
		*/
		virtual bool ValidrRefs(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		/** 
		* Recreates the rRefs attribute
		* also handles filling of rrefs etc.
		*
		* @return vWString: 
		*/
		vWString UpDaterRefs()const;

		/**
		* inline refelements
		*
		* @param WString& elementName: name of the refElement to inline w/o the "Ref" extension
		* @param WString& nameSpaceURI: nameSpace of the new element
		* @param bool bDirect: if false, also recurse sub elements
		*/
		void InlineRefElements(const WString& nodeName=WString::emptyStr,const WString & nameSpaceURI=WString::emptyStr, bool bDirect=false);


		/**
		* Gets all children from the actual element matching the given conditions<br>
		* does NOT get refElement targets although the attributes are checked in the target elements in case of refElements
		*
		* @param String nodeName: element name you are searching for
		* @param String nameSpaceURI: nameSpace you are searching for
		* @param mAttribute& mAttrib: attribute map you are searching for
		* @param boolean bAnd: if true, a child is only added if it has all attributes
		* specified in Attributes map 'mAttrib'
		* @param int maxSize: maximum size of the element vector
		* @param bool bResolveTarget: if true, IDRef elements are followed. Default is false
		* @return vElement: vector with all found elements
		*/
		virtual vElement GetChildElementVector(const WString & nodeName=WString::star, const WString & nameSpaceURI=WString::emptyStr, const mAttribute& mAttrib=mAttribute::emptyMap, bool bAnd=true, unsigned int maxSize=0,bool bResolveTarget=false)const;

		/**
		* Gets a list of all names of elements
		* the "Ref" is stripped from refElement names 
		*
		* @param bLocal: if true, get the local name, else the qualified names
		* @return vWString: list of all direct child element names
		*
		* @tbd namespace handling
		*/
		virtual vWString GetElementNameVector(bool bLocal=false)const;

		/**
		* same as KElement::GetElement but also follows References<br>
		* thus the returned value is the target of the refElement unless the requested element is explicitely a refElement
		* which is specified by requesting an element with nodeName="XXXRef"<br>
		* invalid refelements are simply skipped and are not filled into the vector
		*
		* @param WString& nodeName: name of the child node to get
		* @param WString& nameSpaceURI: namespace to search for
		* @param int iSkip: get the iSkipth element that fits
		* @return KElement: the matching element
		*/
		virtual KElement GetElement(const WString& nodeName, const WString & nameSpaceURI=WString::emptyStr, int iSkip=0)const;

		/**
		* same as @see KElement::NumChildElements but also follows References
		* invalid refelements are simply skipped 
		*
		* @param WString& node: the nodes to count
		* @param WString& nameSpaceURI: the nameSpace to look in
		* @return int: the number of child elements
		*/
		virtual int NumChildElements(const WString& nodeName=WString::emptyStr,const WString & nameSpaceURI=WString::emptyStr)const;

		/**
		* Removes children that match nodeName and nameSpaceURI
		*
		* @param WString& nodeName: name of the child node to get, if empty or "*" remove all
		* @param WString& nameSpaceURI: namespace to search for
		*/
		virtual void RemoveChildren(const WString& nodeName=WString::emptyStr,const WString & nameSpaceURI=WString::emptyStr);

		/**
		* Removes child node that matches nodeName and nameSpaceURI
		*
		* @param WString& nodeName: name of the child node to remove,f empty or "*" remove all
		* @param WString& nameSpaceURI: namespace to search for
		* @param int n: number of nodes to skip before deleting
		* @return KElement: the removed node
		*/
		virtual KElement RemoveChild(const WString & nodeName,const WString & nameSpaceURI=WString::emptyStr,unsigned int n=0);

		/**
		* Tests, whether the attributes described by attName and attVal exist<br>
		* also checking ranges and NMTOKENS etc.
		*
		* @param WString& attName: the name of the attribute you are searching for
		* @param WString& attVal: the value of the attribute you are searching for;
		* a values of "*" is treated as true when the attribute exists, regardless of its value
		* @param EnumAttributeType datatype: datatype to be matched
		* @return bool: true, if such attribute exists
		*
		* @tbd allow for regular expressions in attVal
		*/
		bool IncludesMatchingAttribute(const WString & attName, const WString & attVal=WString::star,EnumAttributeType dataType=AttributeType_Any)const;

		/**
		* Gets a child with matching attributes
		*
		* @param WString& nodeName: name of the child node to search for
		* @param WString& attName: attribute name to search for
		* @param WString& nameSpaceURI: namespace to search for
		* @param WString& attVal: a special value to search for
		* @param int index: if more then one child meets the condition, you can specify the one to return via an index
		* @param bool bDirect: if true, look only in direct children, else search through all children, grandchildren etc.
		* @param EnumAttributeType datatype: datatype to be matched
		* @return JDFElement: the element which matches the above conditions
		*/
		JDFElement GetChildWithMatchingAttribute(const WString & nodeName,const WString & attName, const WString & nameSpaceURI=WString::emptyStr, const WString &attVal=WString::star, int index=0, bool bDirect=true,EnumAttributeType dataType=AttributeType_Any)const;
		//@}

		/**
		* Creates and appends the unique id, keeps the existing one if it already exists
		*
		* @return WString: the value of the ID attribute after setting
		*/
		WString AppendAnchor(const WString & Name=WString::emptyStr);

		/**
		* timestamp a node with the current local time in ISO format
		*
		* @param WString& label: the attribute name to timestamp
		*/
		void SetTimeStamp(const WString & label=atr_TimeStamp);

		/**
		* Creates a string link from an integer
		*
		* @param int id: the integer value to convert to an ID
		* @return WString: a unique ID string 
		*/
		WString IDString(int id)const;

		/**
		* Gets the local JDF node that 'this' resides in
		* if 'this' is a JDF node, returns it's parent<br>
		* if 'this' is the root JDF node returns a null reference
		*
		* @return JDFNode: the local parent of 'this'
		*/
		JDFNode GetParentJDF()const;

		/**
		* Gets the qualified name of a refElement that references 'this'
		*
		* @return WString: the qualified name of a refelement to 'this'
		*/
		WString GetRefString()const;

		/**
		* returns the official JDF version string
		*
		* @since label 2.1.3BLD068, this is 1.3
		* @return WString: the version "1.3"
		*/
		WString Version() const;

		/**
		* returns the JDFElement::EnumVersion that new elements will be generated in by default
		* @return JDFElement::EnumVersion
		*/
		static JDFElement::EnumVersion getDefaultJDFVersion();
		
		//////////////////////////////////////////////////////////////////////
		/**
		* sets the JDFElement::EnumVersion that new elements will be generated in by default
		* @param JDFElement::EnumVersion vers the new default version
		*/
		static void setDefaultJDFVersion(JDFElement::EnumVersion vers);

		/**
		* returns the official JDF schema URI for a particular version
		*
		* @param int majorVersion: the major version - only 1 is supported
		* @param int minorVersion: the minor version - only 0 or 1 are supported
		* @return WString: the URI that fits to majorVersion and minorVersion - empty string if not supported
		*/
		static const WString& GetSchemaURL(int majorVersion, int minorVersion);

	protected:
		/**
		* returns true if the specified name fits the node name of 'this'
		*
		* @param JDFCh* nodeName: the name of the node to test. may be either local or qualified
		* @param JDFCh* nameSpaceURI: the namespace of the node to test.
		* @return bool: true if ok
		*/
		virtual bool FitsName(const JDFCh* nodeName, const JDFCh* nameSpaceURI)const;

		/**
		* returns true if the specified name fits the node name of 'this'
		*
		* @param JDFCh* nodeName: the name of the node to test. may be either local or qualified
		* @param JDFCh* nameSpaceURI: the namespace of the node to test.
		* @return bool: true if ok
		*/
		virtual bool FitsName(const JDFCh* nodeName)const;

		/**
		* gets a prefix for ID creation for the element
		*
		* @return WString: the prefix, e.g. of the created link ID
		*/
		virtual WString GetIDPrefix() const;

		/**
		* gets a new ID for the element
		*
		* @param WString& lastID: the highest ID that has been created before
		* @return WString: the unique ID string 
		*
		* @tbd implement the name mangling as described in the @see JDF spec 1.0 chapter 4.5
		*/
		WString NewID(const WString& lastID);

		/**
		* Create a new ID of the type IDParent.xyz 
		* @param key the attribute name to be replaced
		* @param JDFCh* nameSpaceURI: the namespace of the element to create.
		* @return WString the new ID
		*/
		WString GenerateDotID(const WString& key, const WString& nameSpaceURI=WString::emptyStr);

	public:
		/**
		* creates a not quite so unique but readable id
		*
		* @param int ID: the starting id of the ID, if negative the absolute increment is added to the existing ID
		* @return WString: the ID string value
		*/
		static WString UniqueID(int ID=0);

		/**
		* Defines an enumerated list of attributes	; used by the automated code generator
		*
		* @param WString& key: the attribute name to get
		* @param WString& allowedValues: comma separated string of allowed values
		* @param WString& nameSpaceURI: attribute namespace uri
		* @param unsigned int def: the default enum, if it does not exist
		* @since 300402
		* @param bool bInherit: if true also recurse into parent elements when searching the attribute
		* @return unsigned int: the enumeration equivalent of the attribute
		*/
		unsigned int GetEnumAttribute(const WString &  key, const WString & allowedValues, const WString & nameSpaceURI=WString::emptyStr,unsigned int def=0, bool bInherit=false)const;


		/**
		* defines an enumerated list of attributes	; used by the automated code generator
		*
		* @param WString& key: the attribute name
		* @param WString& allowedValues: comma separated string of allowed values
		* @param WString& nameSpaceURI: attribute namespace uri
		* @param unsigned int: def the default enum if it does not exist
		* @since 300402
		* @param bool bInherit: if true also recurse into parent elements when searching the attribute
		* @return vint: the vector of enumeration equivalents of the attribute
		*/
		vint GetEnumerationsAttribute(const WString &  key, const WString & allowedValues, const WString & nameSpaceURI=WString::emptyStr,unsigned int def=-1,bool bInherit=false)const;

		/**
		* Sets an enumerated list of attributes	; used by the automated code generator
		* throws an exception if value=0="Unknown" or value>number of tokens in allowedValues
		*
		* @param WString & key: the attribute name
		* @param int value: the enumeration equivalent of the attribute
		* @param WString& allowedValues: comma separated string of allowed values
		* @param WString& nameSpaceURI: attribute namespace uri
		* @param bool bAllowUnknown: if true, allow the explicit value "Unknown", else false
		*
		* @throws JDFException if there is an attempt to set attribute with illegal value 
		*/
		void SetEnumAttribute(const WString & key, unsigned int value,const WString& allowedValues,const WString & nameSpaceURI=WString::emptyStr, bool bAllowUnknown=false);

		/**
		* sets an enumerated list of attributes	; used by the automated code generator
		* removes the attribute if the list is empty
		*
		* @param WString& key: the attribute name
		* @param vint& value: the enumeration equivalent of the attribute
		* @param WString& allowedValues: comma separated string of allowed values
		* @param WString& nameSpaceURI attribute namespace uri
		*
		* @throws JDFException if there is an attempt to set attribute with illegal value 
		*/
		void SetEnumerationsAttribute(const WString & key, const vint& value,const WString& allowedValues,const WString & nameSpaceURI=WString::emptyStr);

		/**
		* checks for an attribute to an enumerated list of attributes	; used by the automated code generator
		*
		* @param WString& key: the attribute name
		* @param int value: the enumeration equivalent of the attribute
		* @param WString& allowedValues: comma separated string of allowed values
		* @param WString& nameSpaceURI: attribute namespace uri
		*/
		bool HasEnumerationsAttribute(const WString & key, int value,const WString& allowedValues,const WString & nameSpaceURI=WString::emptyStr)const;

		/**
		* adds an attribute to an enumerated list of attributes	; used by the automated code generator
		*
		* @param WString& key: the attribute name
		* @param int value: the enumeration equivalent of the attribute
		* @param WString& allowedValues: comma separated string of allowed values
		* @param WString& nameSpaceURI: attribute namespace uri
		*/
		vint AddEnumerationsAttribute(const WString & key, int value,const WString& allowedValues,const WString & nameSpaceURI=WString::emptyStr);

		/**
		* adds an attribute to an enumerated list of attributes	; used by the automated code generator
		*
		* @param WString& key: the attribute name
		* @param int value: the enumeration equivalent of the attribute
		* @param WString& allowedValues: comma separated string of allowed values
		* @param WString& nameSpaceURI: attribute namespace uri
		*/
		vint RemoveEnumerationsAttribute(const WString & key, int value,const WString& allowedValues,const WString & nameSpaceURI=WString::emptyStr);

		/**
		* is the attribute valid and of type iType. iType is of type EnumAttributeType but may be expanded in child classes
		*
		* @param WString& key: the attribute name
		* @param EnumAttributeType iType:  the attributes type
		* @param bool bRequired: true if this attribute is required
		* @param WString& nameSpaceURI: attribute namespace uri
		* @return bool: true if the attribute is valid
		*
		* @tbd implement URL validation
		*/
		bool ValidAttribute(const WString & key,EnumAttributeType iType,bool bRequired,const WString & nameSpaceURI=WString::emptyStr) const;

		/**
		* is the attribute valid and does it fit allowedValues. iType is of type EnumAttributeType but may be expanded in child classes
		*
		* @param WString& key: the attribute name
		* @param WString& allowedValues: comma separated string of allowed values
		* @param bool bRequired: true if this attribute is required
		* @param WString& nameSpaceURI: attribute namespace uri
		* @param bool bAllowUnknown: if true, allow the explicit value "Unknown", else false
		* @return bool: true if the attribute is valid
		*/
		bool ValidEnumAttribute(const WString & key,const WString& allowedValues,bool bRequired,const WString & nameSpaceURI=WString::emptyStr,bool bAllowUnknown=false)const;

		/**
		* is the attribute valid and does it fit allowedValues. iType is of type EnumAttributeType but may be expanded in child classes
		*
		* @param WString& key: the attribute name
		* @param WString& allowedValues: comma separated string of allowed values
		* @param bool bRequired: true if this attribute is required
		* @param WString& nameSpaceURI: attribute namespace uri
		* @return bool: true if the attribute is valid
		*/
		bool ValidEnumerationsAttribute(const WString & key,const WString& allowedValues,bool bRequired,const WString & nameSpaceURI=WString::emptyStr)const;

		/**
		* gets the string value from an enumerated set of values
		*	
		* @param unsigned int value: the enum that is to be translated to a string
		* @param WString& allowedValues: comma separated string of allowed values
		* @return WString: the string for the enum
		*/
		WString GetEnumString(unsigned int value,const WString& allowedValues)const;

		/**
		* gets the vector of string values from an enumerated set of values
		*
		* @param vint& value: the enumerations that are to be translated to a string
		* @param WString & allowedValues: comma separated string of allowed values
		* @return vWString: the vector of string for the enumerations
		*/
		vWString GetEnumerationsvString(const vint& value,const WString& allowedValues)const;

		/**
		* maps a node name to an enumeration defined by allowedValues
		*
		* @param WString& allowedValues: comma separated string of allowed values
		* @return unsigned int: the enum that corresponds to the nodename
		*/
		unsigned int GetEnumNodeName(const WString& allowedValues)const;


		//@{
		/**
		* gets part map vector
		*
		* @return vector of mAttribute, one for each part
		*/
		vmAttribute GetPartMapVector()const;

		/**
		* sets all parts to those define in vParts
		*
		* @param vmAttribute& vParts: vector of attribute maps for the parts
		*/
		void SetPartMapVector(const vmAttribute & vParts);

		/**
		* sets part to mPart
		*
		* @param mAttribute& mPart: attribute map for the part to set
		*/
		void SetPartMap(const mAttribute & mPart);

		/**
		* removes the part defined in mPart
		*
		* @param mAttribute& mPart: attribute map for the part to remove
		*/
		void RemovePartMap(const mAttribute & mPart);

		/**
		* checks whether the part defined in mPart is included
		*
		* @param mAttribute& mPart: attribute map for the part to remove
		* @return bool: if the part exists
		*/
		bool HasPartMap(const mAttribute & mPart);
		//@}

	protected:
		/**
		* definition of the allowed node names for elements of this type<br>
		* note that this may be name mangled for certain classes, e.g. JDFResource
		*
		* @return WString: comma separated list of valid node names, * if any
		*/
		virtual WString ValidNodeNames()const;

		/**
		* is the ressource r linkable by this?
		* used by ResorceLink and refElement
		* 
		* @param r the resource to link to
		* @return boolean true if r is at a valid position
		*/
		bool ValidResourcePosition(const JDFResource & r)const;
		/** 
		* level to required converter 
		*
		* @param EnumValidationLevel level: validation level
		* @return bool: true if validation level is one of: Complete or RecursiveComplete
		*/
		virtual bool RequiredLevel(EnumValidationLevel level)const;

		/**
		* return true if at least one of att1 or att2 exists or 
		*
		* @param EnumValidationLevel level: validation level, if level allows optional, no attribute also returns true
		* @param WString att1 name of first attribute
		* @param WString att2 name of second attribute
		* @param WString att3 name of third optional attribute
		* @param WString att4 name of fourth optional attribute
		* @return bool: true combination is valid
		*/
		bool RequiredOneOfAttribute(EnumValidationLevel level, const WString& att1, const WString& att2, const WString& att3=WString::emptyStr, const WString& att4=WString::emptyStr)const;

		/** 
		* return true if no more than one of att1 or att2 exists or 
		* exactly one of att1 or att2 exists depending on level
		*
		* @param EnumValidationLevel level: validation level, if level allows optional, no attribute also returns true
		* @param WString att1 name of first attribute
		* @param WString att2 name of second attribute
		* @param WString att3 name of third optional attribute
		* @param WString att4 name of fourth optional attribute
		* @return bool: true combination is valid
		*/
		bool ExclusiveOneOfAttribute(EnumValidationLevel level, const WString& att1, const WString& att2, const WString& att3=WString::emptyStr, const WString& att4=WString::emptyStr)const;

		/** 
		* return true if at least one of att1 or att2 exists or 
		*
		* @param EnumValidationLevel level: validation level, if level allows optional, no attribute also returns true
		* @param WString elm1 name of first attribute
		* @param WString ns1 namespace URI of first attribute
		* @param WString elm2 name of first attribute
		* @param WString ns2 namespace URI of first attribute
		* @return bool: true combination is valid
		*/
		bool RequiredOneOfElement(EnumValidationLevel level, const WString& elm1, const WString& ns1, const WString& elm2, const WString& ns2)const;

		/** 
		* return true if no more than one of att1 or att2 exists or 
		* exactly one of att1 or att2 exists depending on level
		*
		* @param EnumValidationLevel level: validation level, if level allows optional, no attribute also returns true
		* @param WString elm1 name of first attribute
		* @param WString ns1 namespace URI of first attribute
		* @param WString elm2 name of first attribute
		* @param WString ns2 namespace URI of first attribute
		* @return bool: true combination is valid
		*/
		bool ExclusiveOneOfElement(EnumValidationLevel level, const WString& elm1, const WString& ns1, const WString& elm2, const WString& ns2)const;

		/**
		* Enumeration various pool types
		*/
		enum EnumPoolType {PoolType_Unknown,PoolType_ResourcePool,PoolType_ResourceLinkPool,PoolType_AncestorPool,PoolType_AuditPool,PoolType_ProductionIntent,PoolType_PipeParams};

		/**
		* get unknown elements for a specific pool
		*/
		vWString GetUnknownPoolElements(EnumPoolType poolType, bool bIgnorePrivate, int nMax=99999, const vWString& exceptStrings=vWString::emptyvStr)const;

	};
};

#endif // !defined(_JDFELEMENT_H__)
