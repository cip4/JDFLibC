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


///////////////////////////////////////////////////////////////////

 
#if !defined _JDFAutoRunList_H_
#define _JDFAutoRunList_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFByteMap;
class JDFDynamicInput;
class JDFInsertSheet;
class JDFLayoutElement;
class JDFInterpretedPDLData;
class JDFDisposition;
class JDFPageList;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoRunList : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoRunList class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFRunList should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoRunList : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoRunList():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoRunList(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoRunList &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoRunList(){};
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
* Enumeration for attribute ComponentGranularity
*/

	enum EnumComponentGranularity{ComponentGranularity_Unknown,ComponentGranularity_Page,ComponentGranularity_Document,ComponentGranularity_Set,ComponentGranularity_All,ComponentGranularity_BundleItem};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for ComponentGranularity
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ComponentGranularityString();
/**
* Enumeration string for enum value
* @param EnumComponentGranularity value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ComponentGranularityString(EnumComponentGranularity value);
/**
* Set attribute ComponentGranularity
* @param EnumComponentGranularity value the value to set the attribute to
*/
	virtual void SetComponentGranularity( EnumComponentGranularity value);

/**
* Typesafe enumerated attribute ComponentGranularity; defaults to Document
* @return EnumComponentGranularitythe enumeration value of the attribute
*/
	virtual EnumComponentGranularity GetComponentGranularity() const;

/**
* Typesafe attribute validation of ComponentGranularity
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidComponentGranularity(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IsPage
*@param bool value: the value to set the attribute to
*/
	virtual void SetIsPage(bool value);
/**
* Get bool attribute IsPage
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetIsPage() const;
/**
* Typesafe attribute validation of IsPage
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIsPage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PageCopies
*@param int value: the value to set the attribute to
*/
	virtual void SetPageCopies(int value);
/**
* Get integer attribute PageCopies
* @return int the vaue of the attribute ; defaults to 1
*/
	virtual int GetPageCopies() const;
/**
* Typesafe attribute validation of PageCopies
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPageCopies(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SetCopies
*@param int value: the value to set the attribute to
*/
	virtual void SetSetCopies(int value);
/**
* Get integer attribute SetCopies
* @return int the vaue of the attribute ; defaults to 1
*/
	virtual int GetSetCopies() const;
/**
* Typesafe attribute validation of SetCopies
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSetCopies(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute DocNames
*@param NameRangeList value: the value to set the attribute to
*/
	virtual void SetDocNames(const NameRangeList& value);
/**
* Get range attribute DocNames
* @return NameRangeList the vaue of the attribute 
*/
	virtual NameRangeList GetDocNames() const;
/**
* Typesafe attribute validation of DocNames
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDocNames(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Docs
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetDocs(const JDFIntegerRangeList& value);
/**
* Get range attribute Docs
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetDocs() const;
/**
* Typesafe attribute validation of Docs
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDocs(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EndOfBundleItem
*@param bool value: the value to set the attribute to
*/
	virtual void SetEndOfBundleItem(bool value);
/**
* Get bool attribute EndOfBundleItem
* @return bool the vaue of the attribute 
*/
	virtual bool GetEndOfBundleItem() const;
/**
* Typesafe attribute validation of EndOfBundleItem
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEndOfBundleItem(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EndOfDocument
*@param bool value: the value to set the attribute to
*/
	virtual void SetEndOfDocument(bool value);
/**
* Get bool attribute EndOfDocument
* @return bool the vaue of the attribute 
*/
	virtual bool GetEndOfDocument() const;
/**
* Typesafe attribute validation of EndOfDocument
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEndOfDocument(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EndOfSet
*@param bool value: the value to set the attribute to
*/
	virtual void SetEndOfSet(bool value);
/**
* Get bool attribute EndOfSet
* @return bool the vaue of the attribute 
*/
	virtual bool GetEndOfSet() const;
/**
* Typesafe attribute validation of EndOfSet
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEndOfSet(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FirstPage
*@param int value: the value to set the attribute to
*/
	virtual void SetFirstPage(int value);
/**
* Get integer attribute FirstPage
* @return int the vaue of the attribute 
*/
	virtual int GetFirstPage() const;
/**
* Typesafe attribute validation of FirstPage
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFirstPage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LogicalPage
*@param int value: the value to set the attribute to
*/
	virtual void SetLogicalPage(int value);
/**
* Get integer attribute LogicalPage
* @return int the vaue of the attribute 
*/
	virtual int GetLogicalPage() const;
/**
* Typesafe attribute validation of LogicalPage
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLogicalPage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NDoc
*@param int value: the value to set the attribute to
*/
	virtual void SetNDoc(int value);
/**
* Get integer attribute NDoc
* @return int the vaue of the attribute 
*/
	virtual int GetNDoc() const;
/**
* Typesafe attribute validation of NDoc
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNDoc(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NPage
*@param int value: the value to set the attribute to
*/
	virtual void SetNPage(int value);
/**
* Get integer attribute NPage
* @return int the vaue of the attribute 
*/
	virtual int GetNPage() const;
/**
* Typesafe attribute validation of NPage
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNPage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NSet
*@param int value: the value to set the attribute to
*/
	virtual void SetNSet(int value);
/**
* Get integer attribute NSet
* @return int the vaue of the attribute 
*/
	virtual int GetNSet() const;
/**
* Typesafe attribute validation of NSet
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNSet(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PageListIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetPageListIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute PageListIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetPageListIndex() const;
/**
* Typesafe attribute validation of PageListIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPageListIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PageNames
*@param NameRangeList value: the value to set the attribute to
*/
	virtual void SetPageNames(const NameRangeList& value);
/**
* Get range attribute PageNames
* @return NameRangeList the vaue of the attribute 
*/
	virtual NameRangeList GetPageNames() const;
/**
* Typesafe attribute validation of PageNames
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPageNames(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Pages
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetPages(const JDFIntegerRangeList& value);
/**
* Get range attribute Pages
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetPages() const;
/**
* Typesafe attribute validation of Pages
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPages(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RunTag
*@param WString value: the value to set the attribute to
*/
	virtual void SetRunTag(const WString& value);
/**
* Get string attribute RunTag
* @return WString the vaue of the attribute 
*/
	virtual WString GetRunTag() const;
/**
* Typesafe attribute validation of RunTag
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRunTag(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SetNames
*@param NameRangeList value: the value to set the attribute to
*/
	virtual void SetSetNames(const NameRangeList& value);
/**
* Get range attribute SetNames
* @return NameRangeList the vaue of the attribute 
*/
	virtual NameRangeList GetSetNames() const;
/**
* Typesafe attribute validation of SetNames
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSetNames(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Sets
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetSets(const JDFIntegerRangeList& value);
/**
* Get range attribute Sets
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetSets() const;
/**
* Typesafe attribute validation of Sets
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSets(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SkipPage
*@param int value: the value to set the attribute to
*/
	virtual void SetSkipPage(int value);
/**
* Get integer attribute SkipPage
* @return int the vaue of the attribute 
*/
	virtual int GetSkipPage() const;
/**
* Typesafe attribute validation of SkipPage
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSkipPage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Sorted
*@param bool value: the value to set the attribute to
*/
	virtual void SetSorted(bool value);
/**
* Get bool attribute Sorted
* @return bool the vaue of the attribute 
*/
	virtual bool GetSorted() const;
/**
* Typesafe attribute validation of Sorted
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSorted(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element ByteMap
* 
* @return JDFByteMap The element
*/
	JDFByteMap GetCreateByteMap();

/**
* const get element ByteMap
*@return  JDFByteMap The element
*/
	JDFByteMap GetByteMap()const;
/**
* Append element ByteMap
 * 
*/
	JDFByteMap AppendByteMap();
/**
* create inter-resource link to refTarget
* @param JDFByteMap& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefByteMap(JDFByteMap& refTarget);

/** Get Element DynamicInput
* 
* @param int iSkip number of elements to skip
* @return JDFDynamicInput The element
*/
	JDFDynamicInput GetCreateDynamicInput(int iSkip=0);

/**
* const get element DynamicInput
* @param int iSkip number of elements to skip
* @return JDFDynamicInput The element
*/
	JDFDynamicInput GetDynamicInput(int iSkip=0)const;
/**
* Append element DynamicInput
 */
	JDFDynamicInput AppendDynamicInput();

/** Get Element InsertSheet
* 
* @param int iSkip number of elements to skip
* @return JDFInsertSheet The element
*/
	JDFInsertSheet GetCreateInsertSheet(int iSkip=0);

/**
* const get element InsertSheet
* @param int iSkip number of elements to skip
* @return JDFInsertSheet The element
*/
	JDFInsertSheet GetInsertSheet(int iSkip=0)const;
/**
* Append element InsertSheet
 */
	JDFInsertSheet AppendInsertSheet();
/**
* create inter-resource link to refTarget
* @param JDFInsertSheet& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefInsertSheet(JDFInsertSheet& refTarget);

/** Get Element LayoutElement
* 
* @return JDFLayoutElement The element
*/
	JDFLayoutElement GetCreateLayoutElement();

/**
* const get element LayoutElement
*@return  JDFLayoutElement The element
*/
	JDFLayoutElement GetLayoutElement()const;
/**
* Append element LayoutElement
 * 
*/
	JDFLayoutElement AppendLayoutElement();
/**
* create inter-resource link to refTarget
* @param JDFLayoutElement& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefLayoutElement(JDFLayoutElement& refTarget);

/** Get Element InterpretedPDLData
* 
* @return JDFInterpretedPDLData The element
*/
	JDFInterpretedPDLData GetCreateInterpretedPDLData();

/**
* const get element InterpretedPDLData
*@return  JDFInterpretedPDLData The element
*/
	JDFInterpretedPDLData GetInterpretedPDLData()const;
/**
* Append element InterpretedPDLData
 * 
*/
	JDFInterpretedPDLData AppendInterpretedPDLData();
/**
* create inter-resource link to refTarget
* @param JDFInterpretedPDLData& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefInterpretedPDLData(JDFInterpretedPDLData& refTarget);

/** Get Element Disposition
* 
* @return JDFDisposition The element
*/
	JDFDisposition GetCreateDispositionElem();

/**
* const get element Disposition
*@return  JDFDisposition The element
*/
	JDFDisposition GetDispositionElem()const;
/**
* Append element Disposition
 * 
*/
	JDFDisposition AppendDispositionElem();
/**
* create inter-resource link to refTarget
* @param JDFDisposition& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefDispositionElem(JDFDisposition& refTarget);

/** Get Element PageList
* 
* @return JDFPageList The element
*/
	JDFPageList GetCreatePageList();

/**
* const get element PageList
*@return  JDFPageList The element
*/
	JDFPageList GetPageList()const;
/**
* Append element PageList
 * 
*/
	JDFPageList AppendPageList();
/**
* create inter-resource link to refTarget
* @param JDFPageList& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefPageList(JDFPageList& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoRunList

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoRunList_H_
