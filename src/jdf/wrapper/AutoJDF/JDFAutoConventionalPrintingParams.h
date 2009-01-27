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

 
#if !defined _JDFAutoConventionalPrintingParams_H_
#define _JDFAutoConventionalPrintingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFInk;
class JDFApprovalParams;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoConventionalPrintingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoConventionalPrintingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFConventionalPrintingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoConventionalPrintingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoConventionalPrintingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoConventionalPrintingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoConventionalPrintingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoConventionalPrintingParams(){};
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
* Enumeration for attribute Drying
*/

	enum EnumDrying{Drying_Unknown,Drying_UV,Drying_Heatset,Drying_IR,Drying_On,Drying_Off};
/**
* Enumeration for attribute FirstSurface
*/

	enum EnumFirstSurface{FirstSurface_Unknown,FirstSurface_Either,FirstSurface_Front,FirstSurface_Back};
/**
* Enumeration for attribute FountainSolution
*/

	enum EnumFountainSolution{FountainSolution_Unknown,FountainSolution_On,FountainSolution_Off};
/**
* Enumeration for attribute PrintingType
*/

	enum EnumPrintingType{PrintingType_Unknown,PrintingType_ContinuousFed,PrintingType_SheetFed,PrintingType_WebFed,PrintingType_WebMultiple,PrintingType_WebSingle};
/**
* Enumeration for attribute SheetLay
*/

	enum EnumSheetLay{SheetLay_Unknown,SheetLay_Left,SheetLay_Right,SheetLay_Center};
/**
* Enumeration for attribute WorkStyle
*/

	enum EnumWorkStyle{WorkStyle_Unknown,WorkStyle_Simplex,WorkStyle_Perfecting,WorkStyle_WorkAndBack,WorkStyle_WorkAndTurn,WorkStyle_WorkAndTumble,WorkStyle_WorkAndTwist};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute DirectProof
*@param bool value: the value to set the attribute to
*/
	virtual void SetDirectProof(bool value);
/**
* Get bool attribute DirectProof
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetDirectProof() const;
/**
* Typesafe attribute validation of DirectProof
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDirectProof(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Drying
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& DryingString();
/**
* Enumeration string for enum value
* @param EnumDrying value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString DryingString(EnumDrying value);
/**
* Set attribute Drying
* @param EnumDrying value the value to set the attribute to
*/
	virtual void SetDrying( EnumDrying value);

/**
* Typesafe enumerated attribute Drying
* @return EnumDryingthe enumeration value of the attribute
*/
	virtual EnumDrying GetDrying() const;

/**
* Typesafe attribute validation of Drying
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidDrying(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for FirstSurface
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& FirstSurfaceString();
/**
* Enumeration string for enum value
* @param EnumFirstSurface value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString FirstSurfaceString(EnumFirstSurface value);
/**
* Set attribute FirstSurface
* @param EnumFirstSurface value the value to set the attribute to
*/
	virtual void SetFirstSurface( EnumFirstSurface value);

/**
* Typesafe enumerated attribute FirstSurface
* @return EnumFirstSurfacethe enumeration value of the attribute
*/
	virtual EnumFirstSurface GetFirstSurface() const;

/**
* Typesafe attribute validation of FirstSurface
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidFirstSurface(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for FountainSolution
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& FountainSolutionString();
/**
* Enumeration string for enum value
* @param EnumFountainSolution value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString FountainSolutionString(EnumFountainSolution value);
/**
* Set attribute FountainSolution
* @param EnumFountainSolution value the value to set the attribute to
*/
	virtual void SetFountainSolution( EnumFountainSolution value);

/**
* Typesafe enumerated attribute FountainSolution
* @return EnumFountainSolutionthe enumeration value of the attribute
*/
	virtual EnumFountainSolution GetFountainSolution() const;

/**
* Typesafe attribute validation of FountainSolution
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidFountainSolution(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MediaLocation
*@param WString value: the value to set the attribute to
*/
	virtual void SetMediaLocation(const WString& value);
/**
* Get string attribute MediaLocation
* @return WString the vaue of the attribute 
*/
	virtual WString GetMediaLocation() const;
/**
* Typesafe attribute validation of MediaLocation
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMediaLocation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ModuleAvailableIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetModuleAvailableIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute ModuleAvailableIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetModuleAvailableIndex() const;
/**
* Typesafe attribute validation of ModuleAvailableIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidModuleAvailableIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ModuleDrying
* @param EnumDrying value the value to set the attribute to
*/
	virtual void SetModuleDrying( EnumDrying value);

/**
* Typesafe enumerated attribute ModuleDrying
* @return EnumModuleDryingthe enumeration value of the attribute
*/
	virtual EnumDrying GetModuleDrying() const;

/**
* Typesafe attribute validation of ModuleDrying
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidModuleDrying(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ModuleIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetModuleIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute ModuleIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetModuleIndex() const;
/**
* Typesafe attribute validation of ModuleIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidModuleIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NonPrintableMarginBottom
*@param double value: the value to set the attribute to
*/
	virtual void SetNonPrintableMarginBottom(double value);
/**
* Get double attribute NonPrintableMarginBottom
* @return double the vaue of the attribute 
*/
	virtual double GetNonPrintableMarginBottom() const;
/**
* Typesafe attribute validation of NonPrintableMarginBottom
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNonPrintableMarginBottom(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NonPrintableMarginLeft
*@param double value: the value to set the attribute to
*/
	virtual void SetNonPrintableMarginLeft(double value);
/**
* Get double attribute NonPrintableMarginLeft
* @return double the vaue of the attribute 
*/
	virtual double GetNonPrintableMarginLeft() const;
/**
* Typesafe attribute validation of NonPrintableMarginLeft
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNonPrintableMarginLeft(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NonPrintableMarginRight
*@param double value: the value to set the attribute to
*/
	virtual void SetNonPrintableMarginRight(double value);
/**
* Get double attribute NonPrintableMarginRight
* @return double the vaue of the attribute 
*/
	virtual double GetNonPrintableMarginRight() const;
/**
* Typesafe attribute validation of NonPrintableMarginRight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNonPrintableMarginRight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NonPrintableMarginTop
*@param double value: the value to set the attribute to
*/
	virtual void SetNonPrintableMarginTop(double value);
/**
* Get double attribute NonPrintableMarginTop
* @return double the vaue of the attribute 
*/
	virtual double GetNonPrintableMarginTop() const;
/**
* Typesafe attribute validation of NonPrintableMarginTop
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNonPrintableMarginTop(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PerfectingModule
*@param int value: the value to set the attribute to
*/
	virtual void SetPerfectingModule(int value);
/**
* Get integer attribute PerfectingModule
* @return int the vaue of the attribute 
*/
	virtual int GetPerfectingModule() const;
/**
* Typesafe attribute validation of PerfectingModule
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPerfectingModule(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Powder
*@param double value: the value to set the attribute to
*/
	virtual void SetPowder(double value);
/**
* Get double attribute Powder
* @return double the vaue of the attribute 
*/
	virtual double GetPowder() const;
/**
* Typesafe attribute validation of Powder
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPowder(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PrintingType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PrintingTypeString();
/**
* Enumeration string for enum value
* @param EnumPrintingType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PrintingTypeString(EnumPrintingType value);
/**
* Set attribute PrintingType
* @param EnumPrintingType value the value to set the attribute to
*/
	virtual void SetPrintingType( EnumPrintingType value);

/**
* Typesafe enumerated attribute PrintingType
* @return EnumPrintingTypethe enumeration value of the attribute
*/
	virtual EnumPrintingType GetPrintingType() const;

/**
* Typesafe attribute validation of PrintingType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPrintingType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for SheetLay
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SheetLayString();
/**
* Enumeration string for enum value
* @param EnumSheetLay value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SheetLayString(EnumSheetLay value);
/**
* Set attribute SheetLay
* @param EnumSheetLay value the value to set the attribute to
*/
	virtual void SetSheetLay( EnumSheetLay value);

/**
* Typesafe enumerated attribute SheetLay
* @return EnumSheetLaythe enumeration value of the attribute
*/
	virtual EnumSheetLay GetSheetLay() const;

/**
* Typesafe attribute validation of SheetLay
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSheetLay(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Speed
*@param double value: the value to set the attribute to
*/
	virtual void SetSpeed(double value);
/**
* Get double attribute Speed
* @return double the vaue of the attribute 
*/
	virtual double GetSpeed() const;
/**
* Typesafe attribute validation of Speed
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSpeed(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for WorkStyle
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& WorkStyleString();
/**
* Enumeration string for enum value
* @param EnumWorkStyle value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString WorkStyleString(EnumWorkStyle value);
/**
* Set attribute WorkStyle
* @param EnumWorkStyle value the value to set the attribute to
*/
	virtual void SetWorkStyle( EnumWorkStyle value);

/**
* Typesafe enumerated attribute WorkStyle
* @return EnumWorkStylethe enumeration value of the attribute
*/
	virtual EnumWorkStyle GetWorkStyle() const;

/**
* Typesafe attribute validation of WorkStyle
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidWorkStyle(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Ink
* 
* @param int iSkip number of elements to skip
* @return JDFInk The element
*/
	JDFInk GetCreateInk(int iSkip=0);

/**
* const get element Ink
* @param int iSkip number of elements to skip
* @return JDFInk The element
*/
	JDFInk GetInk(int iSkip=0)const;
/**
* Append element Ink
 */
	JDFInk AppendInk();
/**
* create inter-resource link to refTarget
* @param JDFInk& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefInk(JDFInk& refTarget);

/** Get Element ApprovalParams
* 
* @return JDFApprovalParams The element
*/
	JDFApprovalParams GetCreateApprovalParams();

/**
* const get element ApprovalParams
*@return  JDFApprovalParams The element
*/
	JDFApprovalParams GetApprovalParams()const;
/**
* Append element ApprovalParams
 * 
*/
	JDFApprovalParams AppendApprovalParams();
/**
* create inter-resource link to refTarget
* @param JDFApprovalParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefApprovalParams(JDFApprovalParams& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoConventionalPrintingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoConventionalPrintingParams_H_
