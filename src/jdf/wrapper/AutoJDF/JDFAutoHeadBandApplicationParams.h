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

 
#if !defined _JDFAutoHeadBandApplicationParams_H_
#define _JDFAutoHeadBandApplicationParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFGlueLine;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoHeadBandApplicationParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoHeadBandApplicationParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFHeadBandApplicationParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoHeadBandApplicationParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoHeadBandApplicationParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoHeadBandApplicationParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoHeadBandApplicationParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoHeadBandApplicationParams(){};
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
* Enumeration for attribute StripMaterial
*/

	enum EnumStripMaterial{StripMaterial_Unknown,StripMaterial_Calico,StripMaterial_Cardboard,StripMaterial_CrepePaper,StripMaterial_Gauze,StripMaterial_Paper,StripMaterial_PaperlinedMules,StripMaterial_Tape};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute BottomBrand
*@param WString value: the value to set the attribute to
*/
	virtual void SetBottomBrand(const WString& value);
/**
* Get string attribute BottomBrand
* @return WString the vaue of the attribute 
*/
	virtual WString GetBottomBrand() const;
/**
* Typesafe attribute validation of BottomBrand
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBottomBrand(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BottomColor
* @param EnumNamedColor value the value to set the attribute to
*/
	virtual void SetBottomColor( EnumNamedColor value);

/**
* Typesafe enumerated attribute BottomColor
* @return EnumBottomColorthe enumeration value of the attribute
*/
	virtual EnumNamedColor GetBottomColor() const;

/**
* Typesafe attribute validation of BottomColor
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBottomColor(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BottomColorDetails
*@param WString value: the value to set the attribute to
*/
	virtual void SetBottomColorDetails(const WString& value);
/**
* Get string attribute BottomColorDetails
* @return WString the vaue of the attribute 
*/
	virtual WString GetBottomColorDetails() const;
/**
* Typesafe attribute validation of BottomColorDetails
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBottomColorDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BottomLength
*@param double value: the value to set the attribute to
*/
	virtual void SetBottomLength(double value);
/**
* Get double attribute BottomLength
* @return double the vaue of the attribute 
*/
	virtual double GetBottomLength() const;
/**
* Typesafe attribute validation of BottomLength
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBottomLength(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TopBrand
*@param WString value: the value to set the attribute to
*/
	virtual void SetTopBrand(const WString& value);
/**
* Get string attribute TopBrand
* @return WString the vaue of the attribute 
*/
	virtual WString GetTopBrand() const;
/**
* Typesafe attribute validation of TopBrand
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTopBrand(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TopColor
* @param EnumNamedColor value the value to set the attribute to
*/
	virtual void SetTopColor( EnumNamedColor value);

/**
* Typesafe enumerated attribute TopColor
* @return EnumTopColorthe enumeration value of the attribute
*/
	virtual EnumNamedColor GetTopColor() const;

/**
* Typesafe attribute validation of TopColor
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidTopColor(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TopColorDetails
*@param WString value: the value to set the attribute to
*/
	virtual void SetTopColorDetails(const WString& value);
/**
* Get string attribute TopColorDetails
* @return WString the vaue of the attribute 
*/
	virtual WString GetTopColorDetails() const;
/**
* Typesafe attribute validation of TopColorDetails
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTopColorDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TopLength
*@param double value: the value to set the attribute to
*/
	virtual void SetTopLength(double value);
/**
* Get double attribute TopLength
* @return double the vaue of the attribute 
*/
	virtual double GetTopLength() const;
/**
* Typesafe attribute validation of TopLength
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTopLength(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for StripMaterial
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& StripMaterialString();
/**
* Enumeration string for enum value
* @param EnumStripMaterial value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString StripMaterialString(EnumStripMaterial value);
/**
* Set attribute StripMaterial
* @param EnumStripMaterial value the value to set the attribute to
*/
	virtual void SetStripMaterial( EnumStripMaterial value);

/**
* Typesafe enumerated attribute StripMaterial
* @return EnumStripMaterialthe enumeration value of the attribute
*/
	virtual EnumStripMaterial GetStripMaterial() const;

/**
* Typesafe attribute validation of StripMaterial
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidStripMaterial(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Width
*@param double value: the value to set the attribute to
*/
	virtual void SetWidth(double value);
/**
* Get double attribute Width
* @return double the vaue of the attribute 
*/
	virtual double GetWidth() const;
/**
* Typesafe attribute validation of Width
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWidth(EnumValidationLevel level=ValidationLevel_Complete) const;

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
* create inter-resource link to refTarget
* @param JDFGlueLine& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefGlueLine(JDFGlueLine& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoHeadBandApplicationParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoHeadBandApplicationParams_H_
