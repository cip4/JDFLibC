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

 
#if !defined _JDFAutoStripCellParams_H_
#define _JDFAutoStripCellParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoStripCellParams : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoStripCellParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFStripCellParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoStripCellParams : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoStripCellParams():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoStripCellParams(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoStripCellParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoStripCellParams(){};
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
* Enumeration for attribute Sides
*/

	enum EnumSides{Sides_Unknown,Sides_OneSided,Sides_TwoSidedHeadToHead,Sides_TwoSidedHeadToFoot};
/**
* Enumeration for attribute Mask
*/

	enum EnumMask{Mask_Unknown,Mask_None,Mask_TrimBox,Mask_BleedBox,Mask_SourceTrimBox,Mask_SourceBleedBox,Mask_PDL,Mask_DieCut,Mask_DieBleed};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute BleedFace
*@param double value: the value to set the attribute to
*/
	virtual void SetBleedFace(double value);
/**
* Get double attribute BleedFace
* @return double the vaue of the attribute 
*/
	virtual double GetBleedFace() const;
/**
* Typesafe attribute validation of BleedFace
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBleedFace(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BleedSpine
*@param double value: the value to set the attribute to
*/
	virtual void SetBleedSpine(double value);
/**
* Get double attribute BleedSpine
* @return double the vaue of the attribute 
*/
	virtual double GetBleedSpine() const;
/**
* Typesafe attribute validation of BleedSpine
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBleedSpine(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BleedHead
*@param double value: the value to set the attribute to
*/
	virtual void SetBleedHead(double value);
/**
* Get double attribute BleedHead
* @return double the vaue of the attribute 
*/
	virtual double GetBleedHead() const;
/**
* Typesafe attribute validation of BleedHead
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBleedHead(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BleedFoot
*@param double value: the value to set the attribute to
*/
	virtual void SetBleedFoot(double value);
/**
* Get double attribute BleedFoot
* @return double the vaue of the attribute 
*/
	virtual double GetBleedFoot() const;
/**
* Typesafe attribute validation of BleedFoot
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBleedFoot(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrimFace
*@param double value: the value to set the attribute to
*/
	virtual void SetTrimFace(double value);
/**
* Get double attribute TrimFace
* @return double the vaue of the attribute 
*/
	virtual double GetTrimFace() const;
/**
* Typesafe attribute validation of TrimFace
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrimFace(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Spine
*@param double value: the value to set the attribute to
*/
	virtual void SetSpine(double value);
/**
* Get double attribute Spine
* @return double the vaue of the attribute 
*/
	virtual double GetSpine() const;
/**
* Typesafe attribute validation of Spine
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSpine(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrimHead
*@param double value: the value to set the attribute to
*/
	virtual void SetTrimHead(double value);
/**
* Get double attribute TrimHead
* @return double the vaue of the attribute 
*/
	virtual double GetTrimHead() const;
/**
* Typesafe attribute validation of TrimHead
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrimHead(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrimFoot
*@param double value: the value to set the attribute to
*/
	virtual void SetTrimFoot(double value);
/**
* Get double attribute TrimFoot
* @return double the vaue of the attribute 
*/
	virtual double GetTrimFoot() const;
/**
* Typesafe attribute validation of TrimFoot
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrimFoot(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FrontOverfold
*@param double value: the value to set the attribute to
*/
	virtual void SetFrontOverfold(double value);
/**
* Get double attribute FrontOverfold
* @return double the vaue of the attribute 
*/
	virtual double GetFrontOverfold() const;
/**
* Typesafe attribute validation of FrontOverfold
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFrontOverfold(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BackOverfold
*@param double value: the value to set the attribute to
*/
	virtual void SetBackOverfold(double value);
/**
* Get double attribute BackOverfold
* @return double the vaue of the attribute 
*/
	virtual double GetBackOverfold() const;
/**
* Typesafe attribute validation of BackOverfold
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBackOverfold(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MillingDepth
*@param double value: the value to set the attribute to
*/
	virtual void SetMillingDepth(double value);
/**
* Get double attribute MillingDepth
* @return double the vaue of the attribute 
*/
	virtual double GetMillingDepth() const;
/**
* Typesafe attribute validation of MillingDepth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMillingDepth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CutWidthHead
*@param double value: the value to set the attribute to
*/
	virtual void SetCutWidthHead(double value);
/**
* Get double attribute CutWidthHead
* @return double the vaue of the attribute 
*/
	virtual double GetCutWidthHead() const;
/**
* Typesafe attribute validation of CutWidthHead
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCutWidthHead(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CutWidthFoot
*@param double value: the value to set the attribute to
*/
	virtual void SetCutWidthFoot(double value);
/**
* Get double attribute CutWidthFoot
* @return double the vaue of the attribute 
*/
	virtual double GetCutWidthFoot() const;
/**
* Typesafe attribute validation of CutWidthFoot
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCutWidthFoot(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrimSize
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetTrimSize(const JDFXYPair& value);
/**
* Get string attribute TrimSize
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetTrimSize() const;
/**
* Typesafe attribute validation of TrimSize
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrimSize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Creep
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetCreep(const JDFXYPair& value);
/**
* Get string attribute Creep
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetCreep() const;
/**
* Typesafe attribute validation of Creep
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCreep(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Typesafe enumerated attribute Sides
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
* Set attribute MaskBleed
*@param double value: the value to set the attribute to
*/
	virtual void SetMaskBleed(double value);
/**
* Get double attribute MaskBleed
* @return double the vaue of the attribute 
*/
	virtual double GetMaskBleed() const;
/**
* Typesafe attribute validation of MaskBleed
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaskBleed(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaskSeparation
*@param WString value: the value to set the attribute to
*/
	virtual void SetMaskSeparation(const WString& value);
/**
* Get string attribute MaskSeparation
* @return WString the vaue of the attribute 
*/
	virtual WString GetMaskSeparation() const;
/**
* Typesafe attribute validation of MaskSeparation
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaskSeparation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Mask
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& MaskString();
/**
* Enumeration string for enum value
* @param EnumMask value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString MaskString(EnumMask value);
/**
* Set attribute Mask
* @param EnumMask value the value to set the attribute to
*/
	virtual void SetMask( EnumMask value);

/**
* Typesafe enumerated attribute Mask
* @return EnumMaskthe enumeration value of the attribute
*/
	virtual EnumMask GetMask() const;

/**
* Typesafe attribute validation of Mask
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMask(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoStripCellParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoStripCellParams_H_
