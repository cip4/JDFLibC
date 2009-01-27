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

 
#if !defined _JDFAutoLayoutElement_H_
#define _JDFAutoLayoutElement_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFColorPool;
class JDFContentList;
class JDFDependencies;
class JDFElementColorParams;
class JDFFileSpec;
class JDFImageCompressionParams;
class JDFPageList;
class JDFScreeningParams;
class JDFSeparationSpec;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoLayoutElement : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoLayoutElement class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFLayoutElement should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoLayoutElement : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoLayoutElement():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoLayoutElement(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoLayoutElement &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoLayoutElement(){};
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
* Enumeration for attribute ElementType
*/

	enum EnumElementType{ElementType_Unknown,ElementType_Auxiliary,ElementType_Barcode,ElementType_Composed,ElementType_Document,ElementType_Graphic,ElementType_IdentificationField,ElementType_Image,ElementType_MultiDocument,ElementType_MultiSet,ElementType_Page,ElementType_Reservation,ElementType_Surface,ElementType_Text,ElementType_Tile};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute IgnorePDLCopies
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnorePDLCopies(bool value);
/**
* Get bool attribute IgnorePDLCopies
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetIgnorePDLCopies() const;
/**
* Typesafe attribute validation of IgnorePDLCopies
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnorePDLCopies(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnorePDLImposition
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnorePDLImposition(bool value);
/**
* Get bool attribute IgnorePDLImposition
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetIgnorePDLImposition() const;
/**
* Typesafe attribute validation of IgnorePDLImposition
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnorePDLImposition(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ClipPath
*@param WString value: the value to set the attribute to
*/
	virtual void SetClipPath(const WString& value);
/**
* Get string attribute ClipPath
* @return WString the vaue of the attribute 
*/
	virtual WString GetClipPath() const;
/**
* Typesafe attribute validation of ClipPath
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidClipPath(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ContentDataRefs
*@param vWString value: the value to set the attribute to
*/
	virtual void SetContentDataRefs(const vWString& value);
/**
* Get string attribute ContentDataRefs
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetContentDataRefs() const;
/**
* Typesafe attribute validation of ContentDataRefs
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidContentDataRefs(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ElementType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ElementTypeString();
/**
* Enumeration string for enum value
* @param EnumElementType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ElementTypeString(EnumElementType value);
/**
* Set attribute ElementType
* @param EnumElementType value the value to set the attribute to
*/
	virtual void SetElementType( EnumElementType value);

/**
* Typesafe enumerated attribute ElementType
* @return EnumElementTypethe enumeration value of the attribute
*/
	virtual EnumElementType GetElementType() const;

/**
* Typesafe attribute validation of ElementType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidElementType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HasBleeds
*@param bool value: the value to set the attribute to
*/
	virtual void SetHasBleeds(bool value);
/**
* Get bool attribute HasBleeds
* @return bool the vaue of the attribute 
*/
	virtual bool GetHasBleeds() const;
/**
* Typesafe attribute validation of HasBleeds
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHasBleeds(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IsBlank
*@param bool value: the value to set the attribute to
*/
	virtual void SetIsBlank(bool value);
/**
* Get bool attribute IsBlank
* @return bool the vaue of the attribute 
*/
	virtual bool GetIsBlank() const;
/**
* Typesafe attribute validation of IsBlank
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIsBlank(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IsPrintable
*@param bool value: the value to set the attribute to
*/
	virtual void SetIsPrintable(bool value);
/**
* Get bool attribute IsPrintable
* @return bool the vaue of the attribute 
*/
	virtual bool GetIsPrintable() const;
/**
* Typesafe attribute validation of IsPrintable
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIsPrintable(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IsTrapped
*@param bool value: the value to set the attribute to
*/
	virtual void SetIsTrapped(bool value);
/**
* Get bool attribute IsTrapped
* @return bool the vaue of the attribute 
*/
	virtual bool GetIsTrapped() const;
/**
* Typesafe attribute validation of IsTrapped
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIsTrapped(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute SourceBleedBox
*@param JDFRectangle value: the value to set the attribute to
*/
	virtual void SetSourceBleedBox(const JDFRectangle& value);
/**
* Get string attribute SourceBleedBox
* @return JDFRectangle the vaue of the attribute 
*/
	virtual JDFRectangle GetSourceBleedBox() const;
/**
* Typesafe attribute validation of SourceBleedBox
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSourceBleedBox(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SourceClipBox
*@param JDFRectangle value: the value to set the attribute to
*/
	virtual void SetSourceClipBox(const JDFRectangle& value);
/**
* Get string attribute SourceClipBox
* @return JDFRectangle the vaue of the attribute 
*/
	virtual JDFRectangle GetSourceClipBox() const;
/**
* Typesafe attribute validation of SourceClipBox
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSourceClipBox(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SourceMediaBox
*@param JDFRectangle value: the value to set the attribute to
*/
	virtual void SetSourceMediaBox(const JDFRectangle& value);
/**
* Get string attribute SourceMediaBox
* @return JDFRectangle the vaue of the attribute 
*/
	virtual JDFRectangle GetSourceMediaBox() const;
/**
* Typesafe attribute validation of SourceMediaBox
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSourceMediaBox(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SourceTrimBox
*@param JDFRectangle value: the value to set the attribute to
*/
	virtual void SetSourceTrimBox(const JDFRectangle& value);
/**
* Get string attribute SourceTrimBox
* @return JDFRectangle the vaue of the attribute 
*/
	virtual JDFRectangle GetSourceTrimBox() const;
/**
* Typesafe attribute validation of SourceTrimBox
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSourceTrimBox(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Template
*@param bool value: the value to set the attribute to
*/
	virtual void SetTemplate(bool value);
/**
* Get bool attribute Template
* @return bool the vaue of the attribute 
*/
	virtual bool GetTemplate() const;
/**
* Typesafe attribute validation of Template
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTemplate(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element ColorPool
* 
* @return JDFColorPool The element
*/
	JDFColorPool GetCreateColorPool();

/**
* const get element ColorPool
*@return  JDFColorPool The element
*/
	JDFColorPool GetColorPool()const;
/**
* Append element ColorPool
 * 
*/
	JDFColorPool AppendColorPool();
/**
* create inter-resource link to refTarget
* @param JDFColorPool& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefColorPool(JDFColorPool& refTarget);

/** Get Element ContentList
* 
* @param int iSkip number of elements to skip
* @return JDFContentList The element
*/
	JDFContentList GetCreateContentList(int iSkip=0);

/**
* const get element ContentList
* @param int iSkip number of elements to skip
* @return JDFContentList The element
*/
	JDFContentList GetContentList(int iSkip=0)const;
/**
* Append element ContentList
 */
	JDFContentList AppendContentList();
/**
* create inter-resource link to refTarget
* @param JDFContentList& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefContentList(JDFContentList& refTarget);

/** Get Element Dependencies
* 
* @return JDFDependencies The element
*/
	JDFDependencies GetCreateDependencies();

/**
* const get element Dependencies
*@return  JDFDependencies The element
*/
	JDFDependencies GetDependencies()const;
/**
* Append element Dependencies
 * 
*/
	JDFDependencies AppendDependencies();

/** Get Element ElementColorParams
* 
* @return JDFElementColorParams The element
*/
	JDFElementColorParams GetCreateElementColorParams();

/**
* const get element ElementColorParams
*@return  JDFElementColorParams The element
*/
	JDFElementColorParams GetElementColorParams()const;
/**
* Append element ElementColorParams
 * 
*/
	JDFElementColorParams AppendElementColorParams();
/**
* create inter-resource link to refTarget
* @param JDFElementColorParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefElementColorParams(JDFElementColorParams& refTarget);

/** Get Element FileSpec
* 
* @return JDFFileSpec The element
*/
	JDFFileSpec GetCreateFileSpec();

/**
* const get element FileSpec
*@return  JDFFileSpec The element
*/
	JDFFileSpec GetFileSpec()const;
/**
* Append element FileSpec
 * 
*/
	JDFFileSpec AppendFileSpec();
/**
* create inter-resource link to refTarget
* @param JDFFileSpec& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefFileSpec(JDFFileSpec& refTarget);

/** Get Element ImageCompressionParams
* 
* @return JDFImageCompressionParams The element
*/
	JDFImageCompressionParams GetCreateImageCompressionParams();

/**
* const get element ImageCompressionParams
*@return  JDFImageCompressionParams The element
*/
	JDFImageCompressionParams GetImageCompressionParams()const;
/**
* Append element ImageCompressionParams
 * 
*/
	JDFImageCompressionParams AppendImageCompressionParams();
/**
* create inter-resource link to refTarget
* @param JDFImageCompressionParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefImageCompressionParams(JDFImageCompressionParams& refTarget);

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

/** Get Element ScreeningParams
* 
* @return JDFScreeningParams The element
*/
	JDFScreeningParams GetCreateScreeningParams();

/**
* const get element ScreeningParams
*@return  JDFScreeningParams The element
*/
	JDFScreeningParams GetScreeningParams()const;
/**
* Append element ScreeningParams
 * 
*/
	JDFScreeningParams AppendScreeningParams();
/**
* create inter-resource link to refTarget
* @param JDFScreeningParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefScreeningParams(JDFScreeningParams& refTarget);

/** Get Element SeparationSpec
* 
* @param int iSkip number of elements to skip
* @return JDFSeparationSpec The element
*/
	JDFSeparationSpec GetCreateSeparationSpec(int iSkip=0);

/**
* const get element SeparationSpec
* @param int iSkip number of elements to skip
* @return JDFSeparationSpec The element
*/
	JDFSeparationSpec GetSeparationSpec(int iSkip=0)const;
/**
* Append element SeparationSpec
 */
	JDFSeparationSpec AppendSeparationSpec();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoLayoutElement

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoLayoutElement_H_
