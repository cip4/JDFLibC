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

 
#if !defined _JDFAutoPreview_H_
#define _JDFAutoPreview_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFComment;
class JDFQualityControlResult;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoPreview : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPreview class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPreview should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPreview : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPreview():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoPreview(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPreview &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPreview(){};
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
* Enumeration for attribute PreviewFileType
*/

	enum EnumPreviewFileType{PreviewFileType_Unknown,PreviewFileType_PNG,PreviewFileType_CIP3Multiple,PreviewFileType_CIP3Single};
/**
* Enumeration for attribute PreviewUsage
*/

	enum EnumPreviewUsage{PreviewUsage_Unknown,PreviewUsage_Separation,PreviewUsage_SeparatedThumbNail,PreviewUsage_SeparationRaw,PreviewUsage_ThumbNail,PreviewUsage_Viewable};
/**
* Enumeration for attribute PartUsage
*/

	enum EnumPartUsage{PartUsage_Unknown,PartUsage_Explicit,PartUsage_Implicit,PartUsage_Sparse};
/**
* Enumeration for attribute Compensation
*/

	enum EnumCompensation{Compensation_Unknown,Compensation_None,Compensation_Film,Compensation_Plate,Compensation_Press};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for PreviewFileType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PreviewFileTypeString();
/**
* Enumeration string for enum value
* @param EnumPreviewFileType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PreviewFileTypeString(EnumPreviewFileType value);
/**
* Set attribute PreviewFileType
* @param EnumPreviewFileType value the value to set the attribute to
*/
	virtual void SetPreviewFileType( EnumPreviewFileType value);

/**
* Typesafe enumerated attribute PreviewFileType; defaults to PNG
* @return EnumPreviewFileTypethe enumeration value of the attribute
*/
	virtual EnumPreviewFileType GetPreviewFileType() const;

/**
* Typesafe attribute validation of PreviewFileType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPreviewFileType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PreviewUsage
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PreviewUsageString();
/**
* Enumeration string for enum value
* @param EnumPreviewUsage value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PreviewUsageString(EnumPreviewUsage value);
/**
* Set attribute PreviewUsage
* @param EnumPreviewUsage value the value to set the attribute to
*/
	virtual void SetPreviewUsage( EnumPreviewUsage value);

/**
* Typesafe enumerated attribute PreviewUsage; defaults to Separation
* @return EnumPreviewUsagethe enumeration value of the attribute
*/
	virtual EnumPreviewUsage GetPreviewUsage() const;

/**
* Typesafe attribute validation of PreviewUsage
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPreviewUsage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute URL
*@param WString value: the value to set the attribute to
*/
	virtual void SetURL(const WString& value);
/**
* Get string attribute URL
* @return WString the vaue of the attribute 
*/
	virtual WString GetURL() const;
/**
* Typesafe attribute validation of URL
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidURL(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NoOp
*@param bool value: the value to set the attribute to
*/
	virtual void SetNoOp(bool value);
/**
* Get bool attribute NoOp
* @return bool the vaue of the attribute 
*/
	virtual bool GetNoOp() const;
/**
* Typesafe attribute validation of NoOp
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNoOp(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Class
*@param WString value: the value to set the attribute to
*/
	virtual void SetClass(const WString& value);
/**
* Get string attribute Class
* @return WString the vaue of the attribute 
*/
	virtual WString GetClass() const;
/**
* Typesafe attribute validation of Class
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidClass(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PartUsage
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PartUsageString();
/**
* Enumeration string for enum value
* @param EnumPartUsage value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PartUsageString(EnumPartUsage value);
/**
* Set attribute PartUsage
* @param EnumPartUsage value the value to set the attribute to
*/
	virtual void SetPartUsage( EnumPartUsage value);

/**
* Typesafe enumerated attribute PartUsage
* @return EnumPartUsagethe enumeration value of the attribute
*/
	virtual EnumPartUsage GetPartUsage() const;

/**
* Typesafe attribute validation of PartUsage
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPartUsage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Compensation
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& CompensationString();
/**
* Enumeration string for enum value
* @param EnumCompensation value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString CompensationString(EnumCompensation value);
/**
* Set attribute Compensation
* @param EnumCompensation value the value to set the attribute to
*/
	virtual void SetCompensation( EnumCompensation value);

/**
* Typesafe enumerated attribute Compensation
* @return EnumCompensationthe enumeration value of the attribute
*/
	virtual EnumCompensation GetCompensation() const;

/**
* Typesafe attribute validation of Compensation
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidCompensation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CTM
*@param JDFMatrix value: the value to set the attribute to
*/
	virtual void SetCTM(const JDFMatrix& value);
/**
* Get string attribute CTM
* @return JDFMatrix the vaue of the attribute 
*/
	virtual JDFMatrix GetCTM() const;
/**
* Typesafe attribute validation of CTM
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCTM(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Directory
*@param WString value: the value to set the attribute to
*/
	virtual void SetDirectory(const WString& value);
/**
* Get string attribute Directory
* @return WString the vaue of the attribute 
*/
	virtual WString GetDirectory() const;
/**
* Typesafe attribute validation of Directory
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDirectory(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MimeTypeDetails
*@param WString value: the value to set the attribute to
*/
	virtual void SetMimeTypeDetails(const WString& value);
/**
* Get string attribute MimeTypeDetails
* @return WString the vaue of the attribute 
*/
	virtual WString GetMimeTypeDetails() const;
/**
* Typesafe attribute validation of MimeTypeDetails
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMimeTypeDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BinderySignatureName
*@param WString value: the value to set the attribute to
*/
	virtual void SetBinderySignatureName(const WString& value);
/**
* Get string attribute BinderySignatureName
* @return WString the vaue of the attribute 
*/
	virtual WString GetBinderySignatureName() const;
/**
* Typesafe attribute validation of BinderySignatureName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBinderySignatureName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BlockName
*@param WString value: the value to set the attribute to
*/
	virtual void SetBlockName(const WString& value);
/**
* Get string attribute BlockName
* @return WString the vaue of the attribute 
*/
	virtual WString GetBlockName() const;
/**
* Typesafe attribute validation of BlockName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBlockName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BundleItemIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetBundleItemIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute BundleItemIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetBundleItemIndex() const;
/**
* Typesafe attribute validation of BundleItemIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBundleItemIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CellIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetCellIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute CellIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetCellIndex() const;
/**
* Typesafe attribute validation of CellIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCellIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Condition
*@param WString value: the value to set the attribute to
*/
	virtual void SetCondition(const WString& value);
/**
* Get string attribute Condition
* @return WString the vaue of the attribute 
*/
	virtual WString GetCondition() const;
/**
* Typesafe attribute validation of Condition
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCondition(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DeliveryUnit0
*@param WString value: the value to set the attribute to
*/
	virtual void SetDeliveryUnit0(const WString& value);
/**
* Get string attribute DeliveryUnit0
* @return WString the vaue of the attribute 
*/
	virtual WString GetDeliveryUnit0() const;
/**
* Typesafe attribute validation of DeliveryUnit0
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDeliveryUnit0(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DeliveryUnit1
*@param WString value: the value to set the attribute to
*/
	virtual void SetDeliveryUnit1(const WString& value);
/**
* Get string attribute DeliveryUnit1
* @return WString the vaue of the attribute 
*/
	virtual WString GetDeliveryUnit1() const;
/**
* Typesafe attribute validation of DeliveryUnit1
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDeliveryUnit1(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DeliveryUnit2
*@param WString value: the value to set the attribute to
*/
	virtual void SetDeliveryUnit2(const WString& value);
/**
* Get string attribute DeliveryUnit2
* @return WString the vaue of the attribute 
*/
	virtual WString GetDeliveryUnit2() const;
/**
* Typesafe attribute validation of DeliveryUnit2
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDeliveryUnit2(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DeliveryUnit3
*@param WString value: the value to set the attribute to
*/
	virtual void SetDeliveryUnit3(const WString& value);
/**
* Get string attribute DeliveryUnit3
* @return WString the vaue of the attribute 
*/
	virtual WString GetDeliveryUnit3() const;
/**
* Typesafe attribute validation of DeliveryUnit3
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDeliveryUnit3(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DeliveryUnit4
*@param WString value: the value to set the attribute to
*/
	virtual void SetDeliveryUnit4(const WString& value);
/**
* Get string attribute DeliveryUnit4
* @return WString the vaue of the attribute 
*/
	virtual WString GetDeliveryUnit4() const;
/**
* Typesafe attribute validation of DeliveryUnit4
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDeliveryUnit4(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DeliveryUnit5
*@param WString value: the value to set the attribute to
*/
	virtual void SetDeliveryUnit5(const WString& value);
/**
* Get string attribute DeliveryUnit5
* @return WString the vaue of the attribute 
*/
	virtual WString GetDeliveryUnit5() const;
/**
* Typesafe attribute validation of DeliveryUnit5
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDeliveryUnit5(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DeliveryUnit6
*@param WString value: the value to set the attribute to
*/
	virtual void SetDeliveryUnit6(const WString& value);
/**
* Get string attribute DeliveryUnit6
* @return WString the vaue of the attribute 
*/
	virtual WString GetDeliveryUnit6() const;
/**
* Typesafe attribute validation of DeliveryUnit6
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDeliveryUnit6(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DeliveryUnit7
*@param WString value: the value to set the attribute to
*/
	virtual void SetDeliveryUnit7(const WString& value);
/**
* Get string attribute DeliveryUnit7
* @return WString the vaue of the attribute 
*/
	virtual WString GetDeliveryUnit7() const;
/**
* Typesafe attribute validation of DeliveryUnit7
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDeliveryUnit7(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DeliveryUnit8
*@param WString value: the value to set the attribute to
*/
	virtual void SetDeliveryUnit8(const WString& value);
/**
* Get string attribute DeliveryUnit8
* @return WString the vaue of the attribute 
*/
	virtual WString GetDeliveryUnit8() const;
/**
* Typesafe attribute validation of DeliveryUnit8
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDeliveryUnit8(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DeliveryUnit9
*@param WString value: the value to set the attribute to
*/
	virtual void SetDeliveryUnit9(const WString& value);
/**
* Get string attribute DeliveryUnit9
* @return WString the vaue of the attribute 
*/
	virtual WString GetDeliveryUnit9() const;
/**
* Typesafe attribute validation of DeliveryUnit9
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDeliveryUnit9(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DocTags
*@param NameRangeList value: the value to set the attribute to
*/
	virtual void SetDocTags(const NameRangeList& value);
/**
* Get range attribute DocTags
* @return NameRangeList the vaue of the attribute 
*/
	virtual NameRangeList GetDocTags() const;
/**
* Typesafe attribute validation of DocTags
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDocTags(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Edition
*@param WString value: the value to set the attribute to
*/
	virtual void SetEdition(const WString& value);
/**
* Get string attribute Edition
* @return WString the vaue of the attribute 
*/
	virtual WString GetEdition() const;
/**
* Typesafe attribute validation of Edition
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEdition(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EditionVersion
*@param WString value: the value to set the attribute to
*/
	virtual void SetEditionVersion(const WString& value);
/**
* Get string attribute EditionVersion
* @return WString the vaue of the attribute 
*/
	virtual WString GetEditionVersion() const;
/**
* Typesafe attribute validation of EditionVersion
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEditionVersion(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ItemNames
*@param vWString value: the value to set the attribute to
*/
	virtual void SetItemNames(const vWString& value);
/**
* Get string attribute ItemNames
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetItemNames() const;
/**
* Typesafe attribute validation of ItemNames
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidItemNames(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PageNumber
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetPageNumber(const JDFIntegerRangeList& value);
/**
* Get range attribute PageNumber
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetPageNumber() const;
/**
* Typesafe attribute validation of PageNumber
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPageNumber(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PageTags
*@param NameRangeList value: the value to set the attribute to
*/
	virtual void SetPageTags(const NameRangeList& value);
/**
* Get range attribute PageTags
* @return NameRangeList the vaue of the attribute 
*/
	virtual NameRangeList GetPageTags() const;
/**
* Typesafe attribute validation of PageTags
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPageTags(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PlateLayout
*@param WString value: the value to set the attribute to
*/
	virtual void SetPlateLayout(const WString& value);
/**
* Get string attribute PlateLayout
* @return WString the vaue of the attribute 
*/
	virtual WString GetPlateLayout() const;
/**
* Typesafe attribute validation of PlateLayout
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPlateLayout(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PreflightRule
*@param WString value: the value to set the attribute to
*/
	virtual void SetPreflightRule(const WString& value);
/**
* Get string attribute PreflightRule
* @return WString the vaue of the attribute 
*/
	virtual WString GetPreflightRule() const;
/**
* Typesafe attribute validation of PreflightRule
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPreflightRule(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RunSet
*@param WString value: the value to set the attribute to
*/
	virtual void SetRunSet(const WString& value);
/**
* Get string attribute RunSet
* @return WString the vaue of the attribute 
*/
	virtual WString GetRunSet() const;
/**
* Typesafe attribute validation of RunSet
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRunSet(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SectionIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetSectionIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute SectionIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetSectionIndex() const;
/**
* Typesafe attribute validation of SectionIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSectionIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SetDocIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetSetDocIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute SetDocIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetSetDocIndex() const;
/**
* Typesafe attribute validation of SetDocIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSetDocIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SetRunIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetSetRunIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute SetRunIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetSetRunIndex() const;
/**
* Typesafe attribute validation of SetRunIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSetRunIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SetSheetIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetSetSheetIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute SetSheetIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetSetSheetIndex() const;
/**
* Typesafe attribute validation of SetSheetIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSetSheetIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SetTags
*@param NameRangeList value: the value to set the attribute to
*/
	virtual void SetSetTags(const NameRangeList& value);
/**
* Get range attribute SetTags
* @return NameRangeList the vaue of the attribute 
*/
	virtual NameRangeList GetSetTags() const;
/**
* Typesafe attribute validation of SetTags
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSetTags(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SubRun
*@param WString value: the value to set the attribute to
*/
	virtual void SetSubRun(const WString& value);
/**
* Get string attribute SubRun
* @return WString the vaue of the attribute 
*/
	virtual WString GetSubRun() const;
/**
* Typesafe attribute validation of SubRun
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSubRun(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute WebProduct
*@param WString value: the value to set the attribute to
*/
	virtual void SetWebProduct(const WString& value);
/**
* Get string attribute WebProduct
* @return WString the vaue of the attribute 
*/
	virtual WString GetWebProduct() const;
/**
* Typesafe attribute validation of WebProduct
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWebProduct(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute WebSetup
*@param WString value: the value to set the attribute to
*/
	virtual void SetWebSetup(const WString& value);
/**
* Get string attribute WebSetup
* @return WString the vaue of the attribute 
*/
	virtual WString GetWebSetup() const;
/**
* Typesafe attribute validation of WebSetup
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWebSetup(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Comment
* 
* @param int iSkip number of elements to skip
* @return JDFComment The element
*/
	JDFComment GetCreateComment(int iSkip=0);

/**
* const get element Comment
* @param int iSkip number of elements to skip
* @return JDFComment The element
*/
	JDFComment GetComment(int iSkip=0)const;
/**
* Append element Comment
 */
	JDFComment AppendComment();

/** Get Element QualityControlResult
* 
* @param int iSkip number of elements to skip
* @return JDFQualityControlResult The element
*/
	JDFQualityControlResult GetCreateQualityControlResult(int iSkip=0);

/**
* const get element QualityControlResult
* @param int iSkip number of elements to skip
* @return JDFQualityControlResult The element
*/
	JDFQualityControlResult GetQualityControlResult(int iSkip=0)const;
/**
* Append element QualityControlResult
 */
	JDFQualityControlResult AppendQualityControlResult();
/**
* create inter-resource link to refTarget
* @param JDFQualityControlResult& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefQualityControlResult(JDFQualityControlResult& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoPreview

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPreview_H_
