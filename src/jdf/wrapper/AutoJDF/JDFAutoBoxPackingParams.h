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

 
#if !defined _JDFAutoBoxPackingParams_H_
#define _JDFAutoBoxPackingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoBoxPackingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoBoxPackingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFBoxPackingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoBoxPackingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoBoxPackingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoBoxPackingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoBoxPackingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoBoxPackingParams(){};
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
* Enumeration for attribute ComponentOrientation
*/

	enum EnumComponentOrientation{ComponentOrientation_Unknown,ComponentOrientation_XY,ComponentOrientation_XZ,ComponentOrientation_YZ};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute ComponentsPerRow
*@param int value: the value to set the attribute to
*/
	virtual void SetComponentsPerRow(int value);
/**
* Get integer attribute ComponentsPerRow
* @return int the vaue of the attribute 
*/
	virtual int GetComponentsPerRow() const;
/**
* Typesafe attribute validation of ComponentsPerRow
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidComponentsPerRow(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Columns
*@param int value: the value to set the attribute to
*/
	virtual void SetColumns(int value);
/**
* Get integer attribute Columns
* @return int the vaue of the attribute 
*/
	virtual int GetColumns() const;
/**
* Typesafe attribute validation of Columns
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidColumns(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ComponentOrientation
* @param EnumOrientation value the value to set the attribute to
*/
	virtual void SetComponentOrientation( EnumOrientation value);

/**
* Typesafe enumerated attribute ComponentOrientation
* @return EnumComponentOrientationthe enumeration value of the attribute
*/
	virtual EnumOrientation GetComponentOrientation() const;

/**
* Typesafe attribute validation of ComponentOrientation
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidComponentOrientation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Copies
*@param int value: the value to set the attribute to
*/
	virtual void SetCopies(int value);
/**
* Get integer attribute Copies
* @return int the vaue of the attribute 
*/
	virtual int GetCopies() const;
/**
* Typesafe attribute validation of Copies
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCopies(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FillMaterial
*@param WString value: the value to set the attribute to
*/
	virtual void SetFillMaterial(const WString& value);
/**
* Get string attribute FillMaterial
* @return WString the vaue of the attribute 
*/
	virtual WString GetFillMaterial() const;
/**
* Typesafe attribute validation of FillMaterial
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFillMaterial(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Layers
*@param int value: the value to set the attribute to
*/
	virtual void SetLayers(int value);
/**
* Get integer attribute Layers
* @return int the vaue of the attribute 
*/
	virtual int GetLayers() const;
/**
* Typesafe attribute validation of Layers
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLayers(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxWeight
*@param double value: the value to set the attribute to
*/
	virtual void SetMaxWeight(double value);
/**
* Get double attribute MaxWeight
* @return double the vaue of the attribute 
*/
	virtual double GetMaxWeight() const;
/**
* Typesafe attribute validation of MaxWeight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxWeight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Pattern
*@param WString value: the value to set the attribute to
*/
	virtual void SetPattern(const WString& value);
/**
* Get string attribute Pattern
* @return WString the vaue of the attribute 
*/
	virtual WString GetPattern() const;
/**
* Typesafe attribute validation of Pattern
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPattern(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Rows
*@param int value: the value to set the attribute to
*/
	virtual void SetRows(int value);
/**
* Get integer attribute Rows
* @return int the vaue of the attribute 
*/
	virtual int GetRows() const;
/**
* Typesafe attribute validation of Rows
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRows(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Ties
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetTies(const JDFIntegerList& value);
/**
* Get string attribute Ties
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetTies() const;
/**
* Typesafe attribute validation of Ties
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTies(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute UnderLays
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetUnderLays(const JDFIntegerList& value);
/**
* Get string attribute UnderLays
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetUnderLays() const;
/**
* Typesafe attribute validation of UnderLays
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidUnderLays(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoBoxPackingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoBoxPackingParams_H_
