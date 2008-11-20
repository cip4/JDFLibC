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

 
#if !defined _JDFAutoLayoutPreparationParams_H_
#define _JDFAutoLayoutPreparationParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFImageShift;
class JDFInsertSheet;
class JDFDeviceMark;
class JDFExternalImpositionTemplate;
class JDFFitPolicy;
class JDFJobField;
class JDFMedia;
class JDFPageCell;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoLayoutPreparationParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoLayoutPreparationParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFLayoutPreparationParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoLayoutPreparationParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoLayoutPreparationParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoLayoutPreparationParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoLayoutPreparationParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoLayoutPreparationParams(){};
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
* Enumeration for attribute FinishingOrder
*/

	enum EnumFinishingOrder{FinishingOrder_Unknown,FinishingOrder_FoldGather,FinishingOrder_FoldCollect,FinishingOrder_Gather,FinishingOrder_GatherFold};
/**
* Enumeration for attribute Rotate
*/

	enum EnumRotate{Rotate_Unknown,Rotate_Rotate0,Rotate_Rotate90,Rotate_Rotate180,Rotate_Rotate270};
/**
* Enumeration for attribute Sides
*/

	enum EnumSides{Sides_Unknown,Sides_OneSidedBackFlipX,Sides_OneSidedBackFlipY,Sides_OneSidedFront,Sides_TwoSidedFlipX,Sides_TwoSidedFlipY};
/**
* Enumeration for attribute BindingEdge
*/

	enum EnumBindingEdge{BindingEdge_Unknown,BindingEdge_Left,BindingEdge_Right,BindingEdge_Top,BindingEdge_Bottom,BindingEdge_None};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for FinishingOrder
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& FinishingOrderString();
/**
* Enumeration string for enum value
* @param EnumFinishingOrder value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString FinishingOrderString(EnumFinishingOrder value);
/**
* Set attribute FinishingOrder
* @param EnumFinishingOrder value the value to set the attribute to
*/
	virtual void SetFinishingOrder( EnumFinishingOrder value);

/**
* Typesafe enumerated attribute FinishingOrder; defaults to GatherFold
* @return EnumFinishingOrderthe enumeration value of the attribute
*/
	virtual EnumFinishingOrder GetFinishingOrder() const;

/**
* Typesafe attribute validation of FinishingOrder
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidFinishingOrder(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FoldCatalogOrientation
* @param EnumOrientation value the value to set the attribute to
*/
	virtual void SetFoldCatalogOrientation( EnumOrientation value);

/**
* Typesafe enumerated attribute FoldCatalogOrientation; defaults to Rotate0
* @return EnumFoldCatalogOrientationthe enumeration value of the attribute
*/
	virtual EnumOrientation GetFoldCatalogOrientation() const;

/**
* Typesafe attribute validation of FoldCatalogOrientation
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidFoldCatalogOrientation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PageDistributionScheme
*@param WString value: the value to set the attribute to
*/
	virtual void SetPageDistributionScheme(const WString& value);
/**
* Get string attribute PageDistributionScheme
* @return WString the vaue of the attribute ; defaults to Sequential
*/
	virtual WString GetPageDistributionScheme() const;
/**
* Typesafe attribute validation of PageDistributionScheme
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPageDistributionScheme(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PageOrder
*@param WString value: the value to set the attribute to
*/
	virtual void SetPageOrder(const WString& value);
/**
* Get string attribute PageOrder
* @return WString the vaue of the attribute ; defaults to Reader
*/
	virtual WString GetPageOrder() const;
/**
* Typesafe attribute validation of PageOrder
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPageOrder(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Rotate
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& RotateString();
/**
* Enumeration string for enum value
* @param EnumRotate value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString RotateString(EnumRotate value);
/**
* Set attribute Rotate
* @param EnumRotate value the value to set the attribute to
*/
	virtual void SetRotate( EnumRotate value);

/**
* Typesafe enumerated attribute Rotate; defaults to Rotate0
* @return EnumRotatethe enumeration value of the attribute
*/
	virtual EnumRotate GetRotate() const;

/**
* Typesafe attribute validation of Rotate
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidRotate(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Sides
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SidesString();
/**
* Enumeration string for enum value
* @param EnumSides value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SidesString(EnumSides value);
/**
* Set attribute Sides
* @param EnumSides value the value to set the attribute to
*/
	virtual void SetSides( EnumSides value);

/**
* Typesafe enumerated attribute Sides; defaults to OneSidedFront
* @return EnumSidesthe enumeration value of the attribute
*/
	virtual EnumSides GetSides() const;

/**
* Typesafe attribute validation of Sides
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSides(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for BindingEdge
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& BindingEdgeString();
/**
* Enumeration string for enum value
* @param EnumBindingEdge value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString BindingEdgeString(EnumBindingEdge value);
/**
* Set attribute BindingEdge
* @param EnumBindingEdge value the value to set the attribute to
*/
	virtual void SetBindingEdge( EnumBindingEdge value);

/**
* Typesafe enumerated attribute BindingEdge
* @return EnumBindingEdgethe enumeration value of the attribute
*/
	virtual EnumBindingEdge GetBindingEdge() const;

/**
* Typesafe attribute validation of BindingEdge
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBindingEdge(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BackMarkList
*@param vWString value: the value to set the attribute to
*/
	virtual void SetBackMarkList(const vWString& value);
/**
* Get string attribute BackMarkList
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetBackMarkList() const;
/**
* Typesafe attribute validation of BackMarkList
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBackMarkList(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CreepValue
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetCreepValue(const JDFXYPair& value);
/**
* Get string attribute CreepValue
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetCreepValue() const;
/**
* Typesafe attribute validation of CreepValue
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCreepValue(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FoldCatalog
*@param WString value: the value to set the attribute to
*/
	virtual void SetFoldCatalog(const WString& value);
/**
* Get string attribute FoldCatalog
* @return WString the vaue of the attribute 
*/
	virtual WString GetFoldCatalog() const;
/**
* Typesafe attribute validation of FoldCatalog
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFoldCatalog(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FrontMarkList
*@param vWString value: the value to set the attribute to
*/
	virtual void SetFrontMarkList(const vWString& value);
/**
* Get string attribute FrontMarkList
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetFrontMarkList() const;
/**
* Typesafe attribute validation of FrontMarkList
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFrontMarkList(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Gutter
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetGutter(const JDFXYPair& value);
/**
* Get string attribute Gutter
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetGutter() const;
/**
* Typesafe attribute validation of Gutter
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGutter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute GutterMinimumLimit
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetGutterMinimumLimit(const JDFXYPair& value);
/**
* Get string attribute GutterMinimumLimit
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetGutterMinimumLimit() const;
/**
* Typesafe attribute validation of GutterMinimumLimit
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGutterMinimumLimit(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HorizontalCreep
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetHorizontalCreep(const JDFIntegerList& value);
/**
* Get string attribute HorizontalCreep
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetHorizontalCreep() const;
/**
* Typesafe attribute validation of HorizontalCreep
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHorizontalCreep(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImplicitGutter
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetImplicitGutter(const JDFXYPair& value);
/**
* Get string attribute ImplicitGutter
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetImplicitGutter() const;
/**
* Typesafe attribute validation of ImplicitGutter
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImplicitGutter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImplicitGutterMinimumLimit
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetImplicitGutterMinimumLimit(const JDFXYPair& value);
/**
* Get string attribute ImplicitGutterMinimumLimit
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetImplicitGutterMinimumLimit() const;
/**
* Typesafe attribute validation of ImplicitGutterMinimumLimit
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImplicitGutterMinimumLimit(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute PresentationDirection
*@param WString value: the value to set the attribute to
*/
	virtual void SetPresentationDirection(const WString& value);
/**
* Get string attribute PresentationDirection
* @return WString the vaue of the attribute 
*/
	virtual WString GetPresentationDirection() const;
/**
* Typesafe attribute validation of PresentationDirection
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPresentationDirection(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StackDepth
*@param int value: the value to set the attribute to
*/
	virtual void SetStackDepth(int value);
/**
* Get integer attribute StackDepth
* @return int the vaue of the attribute 
*/
	virtual int GetStackDepth() const;
/**
* Typesafe attribute validation of StackDepth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStackDepth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StepDocs
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetStepDocs(const JDFXYPair& value);
/**
* Get string attribute StepDocs
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetStepDocs() const;
/**
* Typesafe attribute validation of StepDocs
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStepDocs(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StepRepeat
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetStepRepeat(const JDFIntegerList& value);
/**
* Get string attribute StepRepeat
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetStepRepeat() const;
/**
* Typesafe attribute validation of StepRepeat
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStepRepeat(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SurfaceContentsBox
*@param JDFRectangle value: the value to set the attribute to
*/
	virtual void SetSurfaceContentsBox(const JDFRectangle& value);
/**
* Get string attribute SurfaceContentsBox
* @return JDFRectangle the vaue of the attribute 
*/
	virtual JDFRectangle GetSurfaceContentsBox() const;
/**
* Typesafe attribute validation of SurfaceContentsBox
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSurfaceContentsBox(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute VerticalCreep
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetVerticalCreep(const JDFIntegerList& value);
/**
* Get string attribute VerticalCreep
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetVerticalCreep() const;
/**
* Typesafe attribute validation of VerticalCreep
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidVerticalCreep(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element ImageShift
* 
* @return JDFImageShift The element
*/
	JDFImageShift GetCreateImageShift();

/**
* const get element ImageShift
*@return  JDFImageShift The element
*/
	JDFImageShift GetImageShift()const;
/**
* Append element ImageShift
 * 
*/
	JDFImageShift AppendImageShift();

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

/** Get Element DeviceMark
* 
* @return JDFDeviceMark The element
*/
	JDFDeviceMark GetCreateDeviceMark();

/**
* const get element DeviceMark
*@return  JDFDeviceMark The element
*/
	JDFDeviceMark GetDeviceMark()const;
/**
* Append element DeviceMark
 * 
*/
	JDFDeviceMark AppendDeviceMark();
/**
* create inter-resource link to refTarget
* @param JDFDeviceMark& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefDeviceMark(JDFDeviceMark& refTarget);

/** Get Element ExternalImpositionTemplate
* 
* @return JDFExternalImpositionTemplate The element
*/
	JDFExternalImpositionTemplate GetCreateExternalImpositionTemplate();

/**
* const get element ExternalImpositionTemplate
*@return  JDFExternalImpositionTemplate The element
*/
	JDFExternalImpositionTemplate GetExternalImpositionTemplate()const;
/**
* Append element ExternalImpositionTemplate
 * 
*/
	JDFExternalImpositionTemplate AppendExternalImpositionTemplate();
/**
* create inter-resource link to refTarget
* @param JDFExternalImpositionTemplate& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefExternalImpositionTemplate(JDFExternalImpositionTemplate& refTarget);

/** Get Element FitPolicy
* 
* @return JDFFitPolicy The element
*/
	JDFFitPolicy GetCreateFitPolicy();

/**
* const get element FitPolicy
*@return  JDFFitPolicy The element
*/
	JDFFitPolicy GetFitPolicy()const;
/**
* Append element FitPolicy
 * 
*/
	JDFFitPolicy AppendFitPolicy();
/**
* create inter-resource link to refTarget
* @param JDFFitPolicy& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefFitPolicy(JDFFitPolicy& refTarget);

/** Get Element JobField
* 
* @param int iSkip number of elements to skip
* @return JDFJobField The element
*/
	JDFJobField GetCreateJobField(int iSkip=0);

/**
* const get element JobField
* @param int iSkip number of elements to skip
* @return JDFJobField The element
*/
	JDFJobField GetJobField(int iSkip=0)const;
/**
* Append element JobField
 */
	JDFJobField AppendJobField();
/**
* create inter-resource link to refTarget
* @param JDFJobField& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefJobField(JDFJobField& refTarget);

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

/** Get Element PageCell
* 
* @return JDFPageCell The element
*/
	JDFPageCell GetCreatePageCell();

/**
* const get element PageCell
*@return  JDFPageCell The element
*/
	JDFPageCell GetPageCell()const;
/**
* Append element PageCell
 * 
*/
	JDFPageCell AppendPageCell();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoLayoutPreparationParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoLayoutPreparationParams_H_
