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

 
#if !defined _JDFAutoPackingParams_H_
#define _JDFAutoPackingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPackingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPackingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPackingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPackingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPackingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoPackingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPackingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPackingParams(){};
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
* Enumeration for attribute PalletWrapping
*/

	enum EnumPalletWrapping{PalletWrapping_Unknown,PalletWrapping_StretchWrap,PalletWrapping_Banding,PalletWrapping_None};
/**
* Enumeration for attribute PalletType
*/

	enum EnumPalletType{PalletType_Unknown,PalletType_2Way,PalletType_4Way,PalletType_Euro};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for PalletWrapping
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PalletWrappingString();
/**
* Enumeration string for enum value
* @param EnumPalletWrapping value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PalletWrappingString(EnumPalletWrapping value);
/**
* Set attribute PalletWrapping
* @param EnumPalletWrapping value the value to set the attribute to
*/
	virtual void SetPalletWrapping( EnumPalletWrapping value);

/**
* Typesafe enumerated attribute PalletWrapping; defaults to None
* @return EnumPalletWrappingthe enumeration value of the attribute
*/
	virtual EnumPalletWrapping GetPalletWrapping() const;

/**
* Typesafe attribute validation of PalletWrapping
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPalletWrapping(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute WrappingMaterial
*@param WString value: the value to set the attribute to
*/
	virtual void SetWrappingMaterial(const WString& value);
/**
* Get string attribute WrappingMaterial
* @return WString the vaue of the attribute ; defaults to None
*/
	virtual WString GetWrappingMaterial() const;
/**
* Typesafe attribute validation of WrappingMaterial
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWrappingMaterial(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BoxedQuantity
*@param int value: the value to set the attribute to
*/
	virtual void SetBoxedQuantity(int value);
/**
* Get integer attribute BoxedQuantity
* @return int the vaue of the attribute 
*/
	virtual int GetBoxedQuantity() const;
/**
* Typesafe attribute validation of BoxedQuantity
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBoxedQuantity(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BoxShape
*@param JDFShape value: the value to set the attribute to
*/
	virtual void SetBoxShape(const JDFShape& value);
/**
* Get string attribute BoxShape
* @return JDFShape the vaue of the attribute 
*/
	virtual JDFShape GetBoxShape() const;
/**
* Typesafe attribute validation of BoxShape
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBoxShape(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CartonQuantity
*@param int value: the value to set the attribute to
*/
	virtual void SetCartonQuantity(int value);
/**
* Get integer attribute CartonQuantity
* @return int the vaue of the attribute 
*/
	virtual int GetCartonQuantity() const;
/**
* Typesafe attribute validation of CartonQuantity
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCartonQuantity(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CartonShape
*@param JDFShape value: the value to set the attribute to
*/
	virtual void SetCartonShape(const JDFShape& value);
/**
* Get string attribute CartonShape
* @return JDFShape the vaue of the attribute 
*/
	virtual JDFShape GetCartonShape() const;
/**
* Typesafe attribute validation of CartonShape
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCartonShape(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CartonMaxWeight
*@param double value: the value to set the attribute to
*/
	virtual void SetCartonMaxWeight(double value);
/**
* Get double attribute CartonMaxWeight
* @return double the vaue of the attribute 
*/
	virtual double GetCartonMaxWeight() const;
/**
* Typesafe attribute validation of CartonMaxWeight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCartonMaxWeight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CartonStrength
*@param double value: the value to set the attribute to
*/
	virtual void SetCartonStrength(double value);
/**
* Get double attribute CartonStrength
* @return double the vaue of the attribute 
*/
	virtual double GetCartonStrength() const;
/**
* Typesafe attribute validation of CartonStrength
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCartonStrength(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PalletQuantity
*@param int value: the value to set the attribute to
*/
	virtual void SetPalletQuantity(int value);
/**
* Get integer attribute PalletQuantity
* @return int the vaue of the attribute 
*/
	virtual int GetPalletQuantity() const;
/**
* Typesafe attribute validation of PalletQuantity
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPalletQuantity(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PalletSize
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetPalletSize(const JDFXYPair& value);
/**
* Get string attribute PalletSize
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetPalletSize() const;
/**
* Typesafe attribute validation of PalletSize
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPalletSize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PalletMaxHeight
*@param double value: the value to set the attribute to
*/
	virtual void SetPalletMaxHeight(double value);
/**
* Get double attribute PalletMaxHeight
* @return double the vaue of the attribute 
*/
	virtual double GetPalletMaxHeight() const;
/**
* Typesafe attribute validation of PalletMaxHeight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPalletMaxHeight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PalletMaxWeight
*@param double value: the value to set the attribute to
*/
	virtual void SetPalletMaxWeight(double value);
/**
* Get double attribute PalletMaxWeight
* @return double the vaue of the attribute 
*/
	virtual double GetPalletMaxWeight() const;
/**
* Typesafe attribute validation of PalletMaxWeight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPalletMaxWeight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PalletType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PalletTypeString();
/**
* Enumeration string for enum value
* @param EnumPalletType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PalletTypeString(EnumPalletType value);
/**
* Set attribute PalletType
* @param EnumPalletType value the value to set the attribute to
*/
	virtual void SetPalletType( EnumPalletType value);

/**
* Typesafe enumerated attribute PalletType
* @return EnumPalletTypethe enumeration value of the attribute
*/
	virtual EnumPalletType GetPalletType() const;

/**
* Typesafe attribute validation of PalletType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPalletType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute WrappedQuantity
*@param int value: the value to set the attribute to
*/
	virtual void SetWrappedQuantity(int value);
/**
* Get integer attribute WrappedQuantity
* @return int the vaue of the attribute 
*/
	virtual int GetWrappedQuantity() const;
/**
* Typesafe attribute validation of WrappedQuantity
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWrappedQuantity(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoPackingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPackingParams_H_
