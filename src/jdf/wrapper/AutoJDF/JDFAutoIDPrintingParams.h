/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2009 The International Cooperation for the Integration of 
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


///////////////////////////////////////////////////////////////////

 
#if !defined _JDFAutoIDPrintingParams_H_
#define _JDFAutoIDPrintingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFIDPCover;
class JDFIDPFinishing;
class JDFIDPLayout;
class JDFIDPJobSheet;
class JDFMediaIntent;
class JDFMediaSource;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoIDPrintingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoIDPrintingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFIDPrintingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoIDPrintingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoIDPrintingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoIDPrintingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoIDPrintingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoIDPrintingParams(){};
public:

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid attribute names
*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid element names
*/
	virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;

protected:
/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	virtual WString ValidNodeNames()const;
public:

/**
* Checks if the node is abstract, i.e. is not completely described
* utility used by GetUnknownElements, GetUnknownAttributes
* @return boolean: true, if the node is abstract
*/
	virtual bool IsAbstract()const;


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */

/** 
 * Typesafe attribute validation of Class
* @return true if class is valid
*/
virtual bool ValidClass(EnumValidationLevel level) const;

/** 
 * Typesafe initialization
 * @return true if succcessful
*/
virtual bool init();

/**
* Enumeration for attribute PageDelivery
*/

	enum EnumPageDelivery{PageDelivery_Unknown,PageDelivery_SameOrderFaceUp,PageDelivery_SameOrderFaceDown,PageDelivery_ReverseOrderFaceUp,PageDelivery_ReverseOrderFaceDown,PageDelivery_SystemSpecified};
/**
* Enumeration for attribute PrintQuality
*/

	enum EnumPrintQuality{PrintQuality_Unknown,PrintQuality_High,PrintQuality_Normal,PrintQuality_Draft};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute AttributesNaturalLang
*@param WString value: the value to set the attribute to
*/
	virtual void SetAttributesNaturalLang(const WString& value);
/**
* Get string attribute AttributesNaturalLang
* @return WString the vaue of the attribute ; defaults to US
*/
	virtual WString GetAttributesNaturalLang() const;
/**
* Typesafe attribute validation of AttributesNaturalLang
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAttributesNaturalLang(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IDPAttributeFidelity
*@param bool value: the value to set the attribute to
*/
	virtual void SetIDPAttributeFidelity(bool value);
/**
* Get bool attribute IDPAttributeFidelity
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetIDPAttributeFidelity() const;
/**
* Typesafe attribute validation of IDPAttributeFidelity
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIDPAttributeFidelity(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IPPJobPriority
*@param int value: the value to set the attribute to
*/
	virtual void SetIPPJobPriority(int value);
/**
* Get integer attribute IPPJobPriority
* @return int the vaue of the attribute ; defaults to 50
*/
	virtual int GetIPPJobPriority() const;
/**
* Typesafe attribute validation of IPPJobPriority
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIPPJobPriority(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IPPVersion
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetIPPVersion(const JDFXYPair& value);
/**
* Get string attribute IPPVersion
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetIPPVersion() const;
/**
* Typesafe attribute validation of IPPVersion
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIPPVersion(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OutputBin
*@param WString value: the value to set the attribute to
*/
	virtual void SetOutputBin(const WString& value);
/**
* Get string attribute OutputBin
* @return WString the vaue of the attribute 
*/
	virtual WString GetOutputBin() const;
/**
* Typesafe attribute validation of OutputBin
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOutputBin(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PageDelivery
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PageDeliveryString();
/**
* Enumeration string for enum value
* @param EnumPageDelivery value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PageDeliveryString(EnumPageDelivery value);
/**
* Set attribute PageDelivery
* @param EnumPageDelivery value the value to set the attribute to
*/
	virtual void SetPageDelivery( EnumPageDelivery value);

/**
* Typesafe enumerated attribute PageDelivery
* @return EnumPageDeliverythe enumeration value of the attribute
*/
	virtual EnumPageDelivery GetPageDelivery() const;

/**
* Typesafe attribute validation of PageDelivery
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPageDelivery(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PrintQuality
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PrintQualityString();
/**
* Enumeration string for enum value
* @param EnumPrintQuality value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PrintQualityString(EnumPrintQuality value);
/**
* Set attribute PrintQuality
* @param EnumPrintQuality value the value to set the attribute to
*/
	virtual void SetPrintQuality( EnumPrintQuality value);

/**
* Typesafe enumerated attribute PrintQuality
* @return EnumPrintQualitythe enumeration value of the attribute
*/
	virtual EnumPrintQuality GetPrintQuality() const;

/**
* Typesafe attribute validation of PrintQuality
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPrintQuality(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SheetCollate
*@param bool value: the value to set the attribute to
*/
	virtual void SetSheetCollate(bool value);
/**
* Get bool attribute SheetCollate
* @return bool the vaue of the attribute 
*/
	virtual bool GetSheetCollate() const;
/**
* Typesafe attribute validation of SheetCollate
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSheetCollate(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Cover
* 
* @param int iSkip number of elements to skip
* @return JDFIDPCover The element
*/
	JDFIDPCover GetCreateCover(int iSkip=0);

/**
* const get element Cover
* @param int iSkip number of elements to skip
* @return JDFIDPCover The element
*/
	JDFIDPCover GetCover(int iSkip=0)const;
/**
* Append element Cover
 */
	JDFIDPCover AppendCover();

/** Get Element IDPFinishing
* 
* @return JDFIDPFinishing The element
*/
	JDFIDPFinishing GetCreateIDPFinishing();

/**
* const get element IDPFinishing
*@return  JDFIDPFinishing The element
*/
	JDFIDPFinishing GetIDPFinishing()const;
/**
* Append element IDPFinishing
 * 
*/
	JDFIDPFinishing AppendIDPFinishing();

/** Get Element IDPLayout
* 
* @return JDFIDPLayout The element
*/
	JDFIDPLayout GetCreateIDPLayout();

/**
* const get element IDPLayout
*@return  JDFIDPLayout The element
*/
	JDFIDPLayout GetIDPLayout()const;
/**
* Append element IDPLayout
 * 
*/
	JDFIDPLayout AppendIDPLayout();

/** Get Element JobSheet
* 
* @param int iSkip number of elements to skip
* @return JDFIDPJobSheet The element
*/
	JDFIDPJobSheet GetCreateJobSheet(int iSkip=0);

/**
* const get element JobSheet
* @param int iSkip number of elements to skip
* @return JDFIDPJobSheet The element
*/
	JDFIDPJobSheet GetJobSheet(int iSkip=0)const;
/**
* Append element JobSheet
 */
	JDFIDPJobSheet AppendJobSheet();

/** Get Element MediaIntent
* 
* @return JDFMediaIntent The element
*/
	JDFMediaIntent GetCreateMediaIntent();

/**
* const get element MediaIntent
*@return  JDFMediaIntent The element
*/
	JDFMediaIntent GetMediaIntent()const;
/**
* Append element MediaIntent
 * 
*/
	JDFMediaIntent AppendMediaIntent();
/**
* create inter-resource link to refTarget
* @param JDFMediaIntent& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefMediaIntent(JDFMediaIntent& refTarget);

/** Get Element MediaSource
* 
* @return JDFMediaSource The element
*/
	JDFMediaSource GetCreateMediaSource();

/**
* const get element MediaSource
*@return  JDFMediaSource The element
*/
	JDFMediaSource GetMediaSource()const;
/**
* Append element MediaSource
 * 
*/
	JDFMediaSource AppendMediaSource();
/**
* create inter-resource link to refTarget
* @param JDFMediaSource& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefMediaSource(JDFMediaSource& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoIDPrintingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoIDPrintingParams_H_
