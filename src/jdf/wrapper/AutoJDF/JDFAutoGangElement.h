/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2014 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoGangElement_H_
#define _JDFAutoGangElement_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFMedia;
class JDFRunList;
class JDFSeparationList;
class JDFSeparationList;
class JDFStrippingParams;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoGangElement : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoGangElement class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFGangElement should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoGangElement : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoGangElement():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoGangElement(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoGangElement &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoGangElement(){};
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
* Enumeration for attribute GrainDirection
*/

	enum EnumGrainDirection{GrainDirection_Unknown,GrainDirection_Any,GrainDirection_ShortEdge,GrainDirection_LongEdge,GrainDirection_SameDirection,GrainDirection_XDirection,GrainDirection_YDirection};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

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
* Set attribute CollapseBleeds
*@param bool value: the value to set the attribute to
*/
	virtual void SetCollapseBleeds(bool value);
/**
* Get bool attribute CollapseBleeds
* @return bool the vaue of the attribute 
*/
	virtual bool GetCollapseBleeds() const;
/**
* Typesafe attribute validation of CollapseBleeds
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCollapseBleeds(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Dimension
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetDimension(const JDFXYPair& value);
/**
* Get string attribute Dimension
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetDimension() const;
/**
* Typesafe attribute validation of Dimension
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDimension(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DueDate
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetDueDate(JDFDate value=JDFDate());
/**
* Get string attribute DueDate
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetDueDate() const;
/**
* Typesafe attribute validation of DueDate
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDueDate(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FillPriority
*@param int value: the value to set the attribute to
*/
	virtual void SetFillPriority(int value);
/**
* Get integer attribute FillPriority
* @return int the vaue of the attribute 
*/
	virtual int GetFillPriority() const;
/**
* Typesafe attribute validation of FillPriority
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFillPriority(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute GangElementID
*@param WString value: the value to set the attribute to
*/
	virtual void SetGangElementID(const WString& value);
/**
* Get string attribute GangElementID
* @return WString the vaue of the attribute 
*/
	virtual WString GetGangElementID() const;
/**
* Typesafe attribute validation of GangElementID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGangElementID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for GrainDirection
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& GrainDirectionString();
/**
* Enumeration string for enum value
* @param EnumGrainDirection value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString GrainDirectionString(EnumGrainDirection value);
/**
* Set attribute GrainDirection
* @param EnumGrainDirection value the value to set the attribute to
*/
	virtual void SetGrainDirection( EnumGrainDirection value);

/**
* Typesafe enumerated attribute GrainDirection
* @return EnumGrainDirectionthe enumeration value of the attribute
*/
	virtual EnumGrainDirection GetGrainDirection() const;

/**
* Typesafe attribute validation of GrainDirection
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidGrainDirection(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute GroupCode
*@param WString value: the value to set the attribute to
*/
	virtual void SetGroupCode(const WString& value);
/**
* Get string attribute GroupCode
* @return WString the vaue of the attribute 
*/
	virtual WString GetGroupCode() const;
/**
* Typesafe attribute validation of GroupCode
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGroupCode(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	virtual void SetJobID(const WString& value);
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	virtual WString GetJobID() const;
/**
* Typesafe attribute validation of JobID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidJobID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxQuantity
*@param int value: the value to set the attribute to
*/
	virtual void SetMaxQuantity(int value);
/**
* Get integer attribute MaxQuantity
* @return int the vaue of the attribute 
*/
	virtual int GetMaxQuantity() const;
/**
* Typesafe attribute validation of MaxQuantity
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxQuantity(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MinQuantity
*@param int value: the value to set the attribute to
*/
	virtual void SetMinQuantity(int value);
/**
* Get integer attribute MinQuantity
* @return int the vaue of the attribute 
*/
	virtual int GetMinQuantity() const;
/**
* Typesafe attribute validation of MinQuantity
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMinQuantity(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute NumColors
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetNumColors(const JDFXYPair& value);
/**
* Get string attribute NumColors
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetNumColors() const;
/**
* Typesafe attribute validation of NumColors
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNumColors(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NumberUp
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetNumberUp(const JDFXYPair& value);
/**
* Get string attribute NumberUp
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetNumberUp() const;
/**
* Typesafe attribute validation of NumberUp
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNumberUp(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OneSheet
*@param WString value: the value to set the attribute to
*/
	virtual void SetOneSheet(const WString& value);
/**
* Get string attribute OneSheet
* @return WString the vaue of the attribute 
*/
	virtual WString GetOneSheet() const;
/**
* Typesafe attribute validation of OneSheet
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOneSheet(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OrderQuantity
*@param int value: the value to set the attribute to
*/
	virtual void SetOrderQuantity(int value);
/**
* Get integer attribute OrderQuantity
* @return int the vaue of the attribute 
*/
	virtual int GetOrderQuantity() const;
/**
* Typesafe attribute validation of OrderQuantity
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOrderQuantity(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PageDimension
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetPageDimension(const JDFXYPair& value);
/**
* Get string attribute PageDimension
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetPageDimension() const;
/**
* Typesafe attribute validation of PageDimension
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPageDimension(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Priority
*@param int value: the value to set the attribute to
*/
	virtual void SetPriority(int value);
/**
* Get integer attribute Priority
* @return int the vaue of the attribute 
*/
	virtual int GetPriority() const;
/**
* Typesafe attribute validation of Priority
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPriority(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ProductID
*@param WString value: the value to set the attribute to
*/
	virtual void SetProductID(const WString& value);
/**
* Get string attribute ProductID
* @return WString the vaue of the attribute 
*/
	virtual WString GetProductID() const;
/**
* Typesafe attribute validation of ProductID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidProductID(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Media
* 
* @param int iSkip number of elements to skip
* @return JDFMedia The element
*/
	JDFMedia GetCreateMedia(int iSkip=0);

/**
* const get element Media
* @param int iSkip number of elements to skip
* @return JDFMedia The element
*/
	JDFMedia GetMedia(int iSkip=0)const;
/**
* Append element Media
 */
	JDFMedia AppendMedia();
/**
* create inter-resource link to refTarget
* @param JDFMedia& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefMedia(JDFMedia& refTarget);

/** Get Element RunList
* 
* @param int iSkip number of elements to skip
* @return JDFRunList The element
*/
	JDFRunList GetCreateRunList(int iSkip=0);

/**
* const get element RunList
* @param int iSkip number of elements to skip
* @return JDFRunList The element
*/
	JDFRunList GetRunList(int iSkip=0)const;
/**
* Append element RunList
 */
	JDFRunList AppendRunList();
/**
* create inter-resource link to refTarget
* @param JDFRunList& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefRunList(JDFRunList& refTarget);

/** Get Element SeparationListBack
* 
* @param int iSkip number of elements to skip
* @return JDFSeparationList The element
*/
	JDFSeparationList GetCreateSeparationListBack(int iSkip=0);

/**
* const get element SeparationListBack
* @param int iSkip number of elements to skip
* @return JDFSeparationList The element
*/
	JDFSeparationList GetSeparationListBack(int iSkip=0)const;
/**
* Append element SeparationListBack
 */
	JDFSeparationList AppendSeparationListBack();

/** Get Element SeparationListFront
* 
* @param int iSkip number of elements to skip
* @return JDFSeparationList The element
*/
	JDFSeparationList GetCreateSeparationListFront(int iSkip=0);

/**
* const get element SeparationListFront
* @param int iSkip number of elements to skip
* @return JDFSeparationList The element
*/
	JDFSeparationList GetSeparationListFront(int iSkip=0)const;
/**
* Append element SeparationListFront
 */
	JDFSeparationList AppendSeparationListFront();

/** Get Element StrippingParams
* 
* @param int iSkip number of elements to skip
* @return JDFStrippingParams The element
*/
	JDFStrippingParams GetCreateStrippingParams(int iSkip=0);

/**
* const get element StrippingParams
* @param int iSkip number of elements to skip
* @return JDFStrippingParams The element
*/
	JDFStrippingParams GetStrippingParams(int iSkip=0)const;
/**
* Append element StrippingParams
 */
	JDFStrippingParams AppendStrippingParams();
/**
* create inter-resource link to refTarget
* @param JDFStrippingParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefStrippingParams(JDFStrippingParams& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoGangElement

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoGangElement_H_
