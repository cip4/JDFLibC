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

 
#if !defined _JDFAutoThreadSewingParams_H_
#define _JDFAutoThreadSewingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFGlueLine;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoThreadSewingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoThreadSewingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFThreadSewingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoThreadSewingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoThreadSewingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoThreadSewingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoThreadSewingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoThreadSewingParams(){};
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
* Enumeration for attribute CastingMaterial
*/

	enum EnumCastingMaterial{CastingMaterial_Unknown,CastingMaterial_Cotton,CastingMaterial_Nylon,CastingMaterial_Polyester};
/**
* Enumeration for attribute CoreMaterial
*/

	enum EnumCoreMaterial{CoreMaterial_Unknown,CoreMaterial_Cotton,CoreMaterial_Nylon,CoreMaterial_Polyester};
/**
* Enumeration for attribute SewingPattern
*/

	enum EnumSewingPattern{SewingPattern_Unknown,SewingPattern_Normal,SewingPattern_Staggered,SewingPattern_CombinedStaggered,SewingPattern_Side};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute BlindStitch
*@param bool value: the value to set the attribute to
*/
	virtual void SetBlindStitch(bool value);
/**
* Get bool attribute BlindStitch
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetBlindStitch() const;
/**
* Typesafe attribute validation of BlindStitch
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBlindStitch(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for CastingMaterial
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& CastingMaterialString();
/**
* Enumeration string for enum value
* @param EnumCastingMaterial value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString CastingMaterialString(EnumCastingMaterial value);
/**
* Set attribute CastingMaterial
* @param EnumCastingMaterial value the value to set the attribute to
*/
	virtual void SetCastingMaterial( EnumCastingMaterial value);

/**
* Typesafe enumerated attribute CastingMaterial
* @return EnumCastingMaterialthe enumeration value of the attribute
*/
	virtual EnumCastingMaterial GetCastingMaterial() const;

/**
* Typesafe attribute validation of CastingMaterial
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidCastingMaterial(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for CoreMaterial
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& CoreMaterialString();
/**
* Enumeration string for enum value
* @param EnumCoreMaterial value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString CoreMaterialString(EnumCoreMaterial value);
/**
* Set attribute CoreMaterial
* @param EnumCoreMaterial value the value to set the attribute to
*/
	virtual void SetCoreMaterial( EnumCoreMaterial value);

/**
* Typesafe enumerated attribute CoreMaterial
* @return EnumCoreMaterialthe enumeration value of the attribute
*/
	virtual EnumCoreMaterial GetCoreMaterial() const;

/**
* Typesafe attribute validation of CoreMaterial
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidCoreMaterial(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute GlueLineRefSheets
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetGlueLineRefSheets(const JDFIntegerList& value);
/**
* Get string attribute GlueLineRefSheets
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetGlueLineRefSheets() const;
/**
* Typesafe attribute validation of GlueLineRefSheets
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGlueLineRefSheets(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Offset
*@param double value: the value to set the attribute to
*/
	virtual void SetOffset(double value);
/**
* Get double attribute Offset
* @return double the vaue of the attribute 
*/
	virtual double GetOffset() const;
/**
* Typesafe attribute validation of Offset
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOffset(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NeedlePositions
*@param JDFNumberList value: the value to set the attribute to
*/
	virtual void SetNeedlePositions(const JDFNumberList& value);
/**
* Get string attribute NeedlePositions
* @return JDFNumberList the vaue of the attribute 
*/
	virtual JDFNumberList GetNeedlePositions() const;
/**
* Typesafe attribute validation of NeedlePositions
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNeedlePositions(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NumberOfNeedles
*@param int value: the value to set the attribute to
*/
	virtual void SetNumberOfNeedles(int value);
/**
* Get integer attribute NumberOfNeedles
* @return int the vaue of the attribute 
*/
	virtual int GetNumberOfNeedles() const;
/**
* Typesafe attribute validation of NumberOfNeedles
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNumberOfNeedles(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Sealing
*@param bool value: the value to set the attribute to
*/
	virtual void SetSealing(bool value);
/**
* Get bool attribute Sealing
* @return bool the vaue of the attribute 
*/
	virtual bool GetSealing() const;
/**
* Typesafe attribute validation of Sealing
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSealing(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for SewingPattern
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SewingPatternString();
/**
* Enumeration string for enum value
* @param EnumSewingPattern value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SewingPatternString(EnumSewingPattern value);
/**
* Set attribute SewingPattern
* @param EnumSewingPattern value the value to set the attribute to
*/
	virtual void SetSewingPattern( EnumSewingPattern value);

/**
* Typesafe enumerated attribute SewingPattern
* @return EnumSewingPatternthe enumeration value of the attribute
*/
	virtual EnumSewingPattern GetSewingPattern() const;

/**
* Typesafe attribute validation of SewingPattern
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSewingPattern(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ThreadThickness
*@param double value: the value to set the attribute to
*/
	virtual void SetThreadThickness(double value);
/**
* Get double attribute ThreadThickness
* @return double the vaue of the attribute 
*/
	virtual double GetThreadThickness() const;
/**
* Typesafe attribute validation of ThreadThickness
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidThreadThickness(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ThreadBrand
*@param WString value: the value to set the attribute to
*/
	virtual void SetThreadBrand(const WString& value);
/**
* Get string attribute ThreadBrand
* @return WString the vaue of the attribute 
*/
	virtual WString GetThreadBrand() const;
/**
* Typesafe attribute validation of ThreadBrand
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidThreadBrand(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element GlueLine
* 
* @param int iSkip number of elements to skip
* @return JDFGlueLine The element
*/
	JDFGlueLine GetCreateGlueLine(int iSkip=0);

/**
* const get element GlueLine
* @param int iSkip number of elements to skip
* @return JDFGlueLine The element
*/
	JDFGlueLine GetGlueLine(int iSkip=0)const;
/**
* Append element GlueLine
 */
	JDFGlueLine AppendGlueLine();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoThreadSewingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoThreadSewingParams_H_
