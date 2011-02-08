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

 
#if !defined _JDFAutoPart_H_
#define _JDFAutoPart_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPart : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPart class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPart should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPart : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPart():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoPart(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPart &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPart(){};
public:

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid attribute names
*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

protected:
/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	virtual WString ValidNodeNames()const;
public:

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */

/**
* Enumeration for attribute PreviewType
*/

	enum EnumPreviewType{PreviewType_Unknown,PreviewType_Separation,PreviewType_SeparatedThumbNail,PreviewType_SeparationRaw,PreviewType_ThumbNail,PreviewType_Viewable};
/**
* Enumeration for attribute Side
*/

	enum EnumSide{Side_Unknown,Side_Front,Side_Back};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute Sorting
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetSorting(const JDFIntegerRangeList& value);
/**
* Get range attribute Sorting
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetSorting() const;
/**
* Typesafe attribute validation of Sorting
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSorting(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SortAmount
*@param bool value: the value to set the attribute to
*/
	virtual void SetSortAmount(bool value);
/**
* Get bool attribute SortAmount
* @return bool the vaue of the attribute 
*/
	virtual bool GetSortAmount() const;
/**
* Typesafe attribute validation of SortAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSortAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute BinderySignaturePaginationIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetBinderySignaturePaginationIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute BinderySignaturePaginationIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetBinderySignaturePaginationIndex() const;
/**
* Typesafe attribute validation of BinderySignaturePaginationIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBinderySignaturePaginationIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute DocCopies
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetDocCopies(const JDFIntegerRangeList& value);
/**
* Get range attribute DocCopies
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetDocCopies() const;
/**
* Typesafe attribute validation of DocCopies
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDocCopies(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DocIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetDocIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute DocIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetDocIndex() const;
/**
* Typesafe attribute validation of DocIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDocIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DocRunIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetDocRunIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute DocRunIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetDocRunIndex() const;
/**
* Typesafe attribute validation of DocRunIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDocRunIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DocSheetIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetDocSheetIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute DocSheetIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetDocSheetIndex() const;
/**
* Typesafe attribute validation of DocSheetIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDocSheetIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute FountainNumber
*@param int value: the value to set the attribute to
*/
	virtual void SetFountainNumber(int value);
/**
* Get integer attribute FountainNumber
* @return int the vaue of the attribute 
*/
	virtual int GetFountainNumber() const;
/**
* Typesafe attribute validation of FountainNumber
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFountainNumber(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute LayerIDs
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetLayerIDs(const JDFIntegerRangeList& value);
/**
* Get range attribute LayerIDs
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetLayerIDs() const;
/**
* Typesafe attribute validation of LayerIDs
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLayerIDs(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Location
*@param WString value: the value to set the attribute to
*/
	virtual void SetLocation(const WString& value);
/**
* Get string attribute Location
* @return WString the vaue of the attribute 
*/
	virtual WString GetLocation() const;
/**
* Typesafe attribute validation of Location
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLocation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Metadata0
*@param NameRangeList value: the value to set the attribute to
*/
	virtual void SetMetadata0(const NameRangeList& value);
/**
* Get range attribute Metadata0
* @return NameRangeList the vaue of the attribute 
*/
	virtual NameRangeList GetMetadata0() const;
/**
* Typesafe attribute validation of Metadata0
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMetadata0(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Metadata1
*@param NameRangeList value: the value to set the attribute to
*/
	virtual void SetMetadata1(const NameRangeList& value);
/**
* Get range attribute Metadata1
* @return NameRangeList the vaue of the attribute 
*/
	virtual NameRangeList GetMetadata1() const;
/**
* Typesafe attribute validation of Metadata1
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMetadata1(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Metadata2
*@param NameRangeList value: the value to set the attribute to
*/
	virtual void SetMetadata2(const NameRangeList& value);
/**
* Get range attribute Metadata2
* @return NameRangeList the vaue of the attribute 
*/
	virtual NameRangeList GetMetadata2() const;
/**
* Typesafe attribute validation of Metadata2
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMetadata2(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Metadata3
*@param NameRangeList value: the value to set the attribute to
*/
	virtual void SetMetadata3(const NameRangeList& value);
/**
* Get range attribute Metadata3
* @return NameRangeList the vaue of the attribute 
*/
	virtual NameRangeList GetMetadata3() const;
/**
* Typesafe attribute validation of Metadata3
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMetadata3(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Metadata4
*@param NameRangeList value: the value to set the attribute to
*/
	virtual void SetMetadata4(const NameRangeList& value);
/**
* Get range attribute Metadata4
* @return NameRangeList the vaue of the attribute 
*/
	virtual NameRangeList GetMetadata4() const;
/**
* Typesafe attribute validation of Metadata4
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMetadata4(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Metadata5
*@param NameRangeList value: the value to set the attribute to
*/
	virtual void SetMetadata5(const NameRangeList& value);
/**
* Get range attribute Metadata5
* @return NameRangeList the vaue of the attribute 
*/
	virtual NameRangeList GetMetadata5() const;
/**
* Typesafe attribute validation of Metadata5
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMetadata5(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Metadata6
*@param NameRangeList value: the value to set the attribute to
*/
	virtual void SetMetadata6(const NameRangeList& value);
/**
* Get range attribute Metadata6
* @return NameRangeList the vaue of the attribute 
*/
	virtual NameRangeList GetMetadata6() const;
/**
* Typesafe attribute validation of Metadata6
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMetadata6(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Metadata7
*@param NameRangeList value: the value to set the attribute to
*/
	virtual void SetMetadata7(const NameRangeList& value);
/**
* Get range attribute Metadata7
* @return NameRangeList the vaue of the attribute 
*/
	virtual NameRangeList GetMetadata7() const;
/**
* Typesafe attribute validation of Metadata7
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMetadata7(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Metadata8
*@param NameRangeList value: the value to set the attribute to
*/
	virtual void SetMetadata8(const NameRangeList& value);
/**
* Get range attribute Metadata8
* @return NameRangeList the vaue of the attribute 
*/
	virtual NameRangeList GetMetadata8() const;
/**
* Typesafe attribute validation of Metadata8
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMetadata8(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Metadata9
*@param NameRangeList value: the value to set the attribute to
*/
	virtual void SetMetadata9(const NameRangeList& value);
/**
* Get range attribute Metadata9
* @return NameRangeList the vaue of the attribute 
*/
	virtual NameRangeList GetMetadata9() const;
/**
* Typesafe attribute validation of Metadata9
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMetadata9(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Option
*@param WString value: the value to set the attribute to
*/
	virtual void SetOption(const WString& value);
/**
* Get string attribute Option
* @return WString the vaue of the attribute 
*/
	virtual WString GetOption() const;
/**
* Typesafe attribute validation of Option
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOption(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute PartVersion
*@param vWString value: the value to set the attribute to
*/
	virtual void SetPartVersion(const vWString& value);
/**
* Get string attribute PartVersion
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetPartVersion() const;
/**
* Typesafe attribute validation of PartVersion
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPartVersion(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Enumeration strings for PreviewType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PreviewTypeString();
/**
* Enumeration string for enum value
* @param EnumPreviewType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PreviewTypeString(EnumPreviewType value);
/**
* Set attribute PreviewType
* @param EnumPreviewType value the value to set the attribute to
*/
	virtual void SetPreviewType( EnumPreviewType value);

/**
* Typesafe enumerated attribute PreviewType
* @return EnumPreviewTypethe enumeration value of the attribute
*/
	virtual EnumPreviewType GetPreviewType() const;

/**
* Typesafe attribute validation of PreviewType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPreviewType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RibbonName
*@param WString value: the value to set the attribute to
*/
	virtual void SetRibbonName(const WString& value);
/**
* Get string attribute RibbonName
* @return WString the vaue of the attribute 
*/
	virtual WString GetRibbonName() const;
/**
* Typesafe attribute validation of RibbonName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRibbonName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Run
*@param WString value: the value to set the attribute to
*/
	virtual void SetRun(const WString& value);
/**
* Get string attribute Run
* @return WString the vaue of the attribute 
*/
	virtual WString GetRun() const;
/**
* Typesafe attribute validation of Run
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRun(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RunIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetRunIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute RunIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetRunIndex() const;
/**
* Typesafe attribute validation of RunIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRunIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RunPage
*@param int value: the value to set the attribute to
*/
	virtual void SetRunPage(int value);
/**
* Get integer attribute RunPage
* @return int the vaue of the attribute 
*/
	virtual int GetRunPage() const;
/**
* Typesafe attribute validation of RunPage
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRunPage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RunPageRange
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetRunPageRange(const JDFIntegerRangeList& value);
/**
* Get range attribute RunPageRange
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetRunPageRange() const;
/**
* Typesafe attribute validation of RunPageRange
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRunPageRange(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute RunTags
*@param NameRangeList value: the value to set the attribute to
*/
	virtual void SetRunTags(const NameRangeList& value);
/**
* Get range attribute RunTags
* @return NameRangeList the vaue of the attribute 
*/
	virtual NameRangeList GetRunTags() const;
/**
* Typesafe attribute validation of RunTags
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRunTags(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute Separation
*@param WString value: the value to set the attribute to
*/
	virtual void SetSeparation(const WString& value);
/**
* Get string attribute Separation
* @return WString the vaue of the attribute 
*/
	virtual WString GetSeparation() const;
/**
* Typesafe attribute validation of Separation
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSeparation(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute SetIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetSetIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute SetIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetSetIndex() const;
/**
* Typesafe attribute validation of SetIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSetIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SheetIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetSheetIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute SheetIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetSheetIndex() const;
/**
* Typesafe attribute validation of SheetIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSheetIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SheetName
*@param WString value: the value to set the attribute to
*/
	virtual void SetSheetName(const WString& value);
/**
* Get string attribute SheetName
* @return WString the vaue of the attribute 
*/
	virtual WString GetSheetName() const;
/**
* Typesafe attribute validation of SheetName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSheetName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Side
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SideString();
/**
* Enumeration string for enum value
* @param EnumSide value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SideString(EnumSide value);
/**
* Set attribute Side
* @param EnumSide value the value to set the attribute to
*/
	virtual void SetSide( EnumSide value);

/**
* Typesafe enumerated attribute Side
* @return EnumSidethe enumeration value of the attribute
*/
	virtual EnumSide GetSide() const;

/**
* Typesafe attribute validation of Side
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSide(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SignatureName
*@param WString value: the value to set the attribute to
*/
	virtual void SetSignatureName(const WString& value);
/**
* Get string attribute SignatureName
* @return WString the vaue of the attribute 
*/
	virtual WString GetSignatureName() const;
/**
* Typesafe attribute validation of SignatureName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSignatureName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StationName
*@param WString value: the value to set the attribute to
*/
	virtual void SetStationName(const WString& value);
/**
* Get string attribute StationName
* @return WString the vaue of the attribute 
*/
	virtual WString GetStationName() const;
/**
* Typesafe attribute validation of StationName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStationName(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute TileID
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetTileID(const JDFXYPair& value);
/**
* Get string attribute TileID
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetTileID() const;
/**
* Typesafe attribute validation of TileID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTileID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute WebName
*@param WString value: the value to set the attribute to
*/
	virtual void SetWebName(const WString& value);
/**
* Get string attribute WebName
* @return WString the vaue of the attribute 
*/
	virtual WString GetWebName() const;
/**
* Typesafe attribute validation of WebName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWebName(EnumValidationLevel level=ValidationLevel_Complete) const;
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

}; // endJDFAutoPart

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPart_H_
