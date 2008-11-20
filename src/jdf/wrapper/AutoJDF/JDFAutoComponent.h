/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoComponent_H_
#define _JDFAutoComponent_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFAssembly;
class JDFBundle;
class JDFDisjointing;
class JDFSheet;
class JDFLayout;
class JDFMedia;
class JDFPageList;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoComponent : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoComponent class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFComponent should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoComponent : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoComponent():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoComponent(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoComponent &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoComponent(){};
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
* Enumeration for attribute ComponentType
*/

	enum EnumComponentType{ComponentType_Unknown,ComponentType_Block,ComponentType_Other,ComponentType_Ribbon,ComponentType_Sheet,ComponentType_Web,ComponentType_FinalProduct,ComponentType_PartialProduct,ComponentType_Proof};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for ComponentType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ComponentTypeString();
/**
* Enumeration string for enum value
* @param EnumComponentType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ComponentTypeString(EnumComponentType value);
/**
* Append value to the attribute ComponentType
* @param EnumComponentType value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint AddComponentType( EnumComponentType value);
/**
* Remove value from the attribute ComponentType
* @param EnumComponentType value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint RemoveComponentType( EnumComponentType value);
/**
* Typesafe enumerated attribute ComponentType
* @return EnumComponentTypethe enumeration value of the attribute
*/
	virtual vint GetComponentType() const;
/**
* Set value of the attribute ComponentType
* @param EnumComponentType value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetComponentType( EnumComponentType value);
/**
* Set value of the attribute ComponentType to a list
* @param vint value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetComponentType( const vint& value);
/**
* Typesafe attribute validation of ComponentType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidComponentType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AssemblyIDs
*@param vWString value: the value to set the attribute to
*/
	virtual void SetAssemblyIDs(const vWString& value);
/**
* Get string attribute AssemblyIDs
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetAssemblyIDs() const;
/**
* Typesafe attribute validation of AssemblyIDs
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAssemblyIDs(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CartonTopFlaps
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetCartonTopFlaps(const JDFXYPair& value);
/**
* Get string attribute CartonTopFlaps
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetCartonTopFlaps() const;
/**
* Typesafe attribute validation of CartonTopFlaps
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCartonTopFlaps(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Dimensions
*@param JDFShape value: the value to set the attribute to
*/
	virtual void SetDimensions(const JDFShape& value);
/**
* Get string attribute Dimensions
* @return JDFShape the vaue of the attribute 
*/
	virtual JDFShape GetDimensions() const;
/**
* Typesafe attribute validation of Dimensions
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDimensions(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IsWaste
*@param bool value: the value to set the attribute to
*/
	virtual void SetIsWaste(bool value);
/**
* Get bool attribute IsWaste
* @return bool the vaue of the attribute 
*/
	virtual bool GetIsWaste() const;
/**
* Typesafe attribute validation of IsWaste
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIsWaste(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxHeat
*@param double value: the value to set the attribute to
*/
	virtual void SetMaxHeat(double value);
/**
* Get double attribute MaxHeat
* @return double the vaue of the attribute 
*/
	virtual double GetMaxHeat() const;
/**
* Typesafe attribute validation of MaxHeat
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxHeat(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Overfold
*@param double value: the value to set the attribute to
*/
	virtual void SetOverfold(double value);
/**
* Get double attribute Overfold
* @return double the vaue of the attribute 
*/
	virtual double GetOverfold() const;
/**
* Typesafe attribute validation of Overfold
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOverfold(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OverfoldSide
*@param WString value: the value to set the attribute to
*/
	virtual void SetOverfoldSide(const WString& value);
/**
* Get string attribute OverfoldSide
* @return WString the vaue of the attribute 
*/
	virtual WString GetOverfoldSide() const;
/**
* Typesafe attribute validation of OverfoldSide
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOverfoldSide(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute ProductType
*@param WString value: the value to set the attribute to
*/
	virtual void SetProductType(const WString& value);
/**
* Get string attribute ProductType
* @return WString the vaue of the attribute 
*/
	virtual WString GetProductType() const;
/**
* Typesafe attribute validation of ProductType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidProductType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ProductTypeDetails
*@param WString value: the value to set the attribute to
*/
	virtual void SetProductTypeDetails(const WString& value);
/**
* Get string attribute ProductTypeDetails
* @return WString the vaue of the attribute 
*/
	virtual WString GetProductTypeDetails() const;
/**
* Typesafe attribute validation of ProductTypeDetails
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidProductTypeDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ReaderPageCount
*@param int value: the value to set the attribute to
*/
	virtual void SetReaderPageCount(int value);
/**
* Get integer attribute ReaderPageCount
* @return int the vaue of the attribute 
*/
	virtual int GetReaderPageCount() const;
/**
* Typesafe attribute validation of ReaderPageCount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidReaderPageCount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SheetPart
*@param JDFRectangle value: the value to set the attribute to
*/
	virtual void SetSheetPart(const JDFRectangle& value);
/**
* Get string attribute SheetPart
* @return JDFRectangle the vaue of the attribute 
*/
	virtual JDFRectangle GetSheetPart() const;
/**
* Typesafe attribute validation of SheetPart
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSheetPart(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SourceRibbon
*@param WString value: the value to set the attribute to
*/
	virtual void SetSourceRibbon(const WString& value);
/**
* Get string attribute SourceRibbon
* @return WString the vaue of the attribute 
*/
	virtual WString GetSourceRibbon() const;
/**
* Typesafe attribute validation of SourceRibbon
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSourceRibbon(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SourceSheet
*@param WString value: the value to set the attribute to
*/
	virtual void SetSourceSheet(const WString& value);
/**
* Get string attribute SourceSheet
* @return WString the vaue of the attribute 
*/
	virtual WString GetSourceSheet() const;
/**
* Typesafe attribute validation of SourceSheet
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSourceSheet(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SourceWeb
*@param WString value: the value to set the attribute to
*/
	virtual void SetSourceWeb(const WString& value);
/**
* Get string attribute SourceWeb
* @return WString the vaue of the attribute 
*/
	virtual WString GetSourceWeb() const;
/**
* Typesafe attribute validation of SourceWeb
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSourceWeb(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SpineThickness
*@param double value: the value to set the attribute to
*/
	virtual void SetSpineThickness(double value);
/**
* Get double attribute SpineThickness
* @return double the vaue of the attribute 
*/
	virtual double GetSpineThickness() const;
/**
* Typesafe attribute validation of SpineThickness
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSpineThickness(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SurfaceCount
*@param int value: the value to set the attribute to
*/
	virtual void SetSurfaceCount(int value);
/**
* Get integer attribute SurfaceCount
* @return int the vaue of the attribute 
*/
	virtual int GetSurfaceCount() const;
/**
* Typesafe attribute validation of SurfaceCount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSurfaceCount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Transformation
*@param JDFMatrix value: the value to set the attribute to
*/
	virtual void SetTransformation(const JDFMatrix& value);
/**
* Get string attribute Transformation
* @return JDFMatrix the vaue of the attribute 
*/
	virtual JDFMatrix GetTransformation() const;
/**
* Typesafe attribute validation of Transformation
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTransformation(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Assembly
* 
* @return JDFAssembly The element
*/
	JDFAssembly GetCreateAssembly();

/**
* const get element Assembly
*@return  JDFAssembly The element
*/
	JDFAssembly GetAssembly()const;
/**
* Append element Assembly
 * 
*/
	JDFAssembly AppendAssembly();
/**
* create inter-resource link to refTarget
* @param JDFAssembly& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefAssembly(JDFAssembly& refTarget);

/** Get Element Bundle
* 
* @return JDFBundle The element
*/
	JDFBundle GetCreateBundle();

/**
* const get element Bundle
*@return  JDFBundle The element
*/
	JDFBundle GetBundle()const;
/**
* Append element Bundle
 * 
*/
	JDFBundle AppendBundle();
/**
* create inter-resource link to refTarget
* @param JDFBundle& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefBundle(JDFBundle& refTarget);

/** Get Element Disjointing
* 
* @return JDFDisjointing The element
*/
	JDFDisjointing GetCreateDisjointing();

/**
* const get element Disjointing
*@return  JDFDisjointing The element
*/
	JDFDisjointing GetDisjointing()const;
/**
* Append element Disjointing
 * 
*/
	JDFDisjointing AppendDisjointing();

/** Get Element Sheet
* 
* @return JDFSheet The element
*/
	JDFSheet GetCreateSheet();

/**
* const get element Sheet
*@return  JDFSheet The element
*/
	JDFSheet GetSheet()const;
/**
* Append element Sheet
 * 
*/
	JDFSheet AppendSheet();
/**
* create inter-resource link to refTarget
* @param JDFSheet& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefSheet(JDFSheet& refTarget);

/** Get Element Layout
* 
* @return JDFLayout The element
*/
	JDFLayout GetCreateLayout();

/**
* const get element Layout
*@return  JDFLayout The element
*/
	JDFLayout GetLayout()const;
/**
* Append element Layout
 * 
*/
	JDFLayout AppendLayout();
/**
* create inter-resource link to refTarget
* @param JDFLayout& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefLayout(JDFLayout& refTarget);

/** Get Element Media
* 
* @return JDFMedia The element
*/
	JDFMedia GetCreateMedia();

/**
* const get element Media
*@return  JDFMedia The element
*/
	JDFMedia GetMedia()const;
/**
* Append element Media
 * 
*/
	JDFMedia AppendMedia();
/**
* create inter-resource link to refTarget
* @param JDFMedia& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefMedia(JDFMedia& refTarget);

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
}; // endJDFAutoComponent

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoComponent_H_
