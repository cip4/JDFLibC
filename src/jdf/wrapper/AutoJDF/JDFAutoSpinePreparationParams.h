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

 
#if !defined _JDFAutoSpinePreparationParams_H_
#define _JDFAutoSpinePreparationParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoSpinePreparationParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoSpinePreparationParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFSpinePreparationParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoSpinePreparationParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoSpinePreparationParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoSpinePreparationParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoSpinePreparationParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoSpinePreparationParams(){};
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
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute StartPosition
*@param double value: the value to set the attribute to
*/
	virtual void SetStartPosition(double value);
/**
* Get double attribute StartPosition
* @return double the vaue of the attribute ; defaults to 0
*/
	virtual double GetStartPosition() const;
/**
* Typesafe attribute validation of StartPosition
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStartPosition(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FlexValue
*@param double value: the value to set the attribute to
*/
	virtual void SetFlexValue(double value);
/**
* Get double attribute FlexValue
* @return double the vaue of the attribute 
*/
	virtual double GetFlexValue() const;
/**
* Typesafe attribute validation of FlexValue
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFlexValue(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute NotchingDepth
*@param double value: the value to set the attribute to
*/
	virtual void SetNotchingDepth(double value);
/**
* Get double attribute NotchingDepth
* @return double the vaue of the attribute 
*/
	virtual double GetNotchingDepth() const;
/**
* Typesafe attribute validation of NotchingDepth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNotchingDepth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NotchingDistance
*@param double value: the value to set the attribute to
*/
	virtual void SetNotchingDistance(double value);
/**
* Get double attribute NotchingDistance
* @return double the vaue of the attribute 
*/
	virtual double GetNotchingDistance() const;
/**
* Typesafe attribute validation of NotchingDistance
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNotchingDistance(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Operations
*@param vWString value: the value to set the attribute to
*/
	virtual void SetOperations(const vWString& value);
/**
* Get string attribute Operations
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetOperations() const;
/**
* Typesafe attribute validation of Operations
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOperations(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PullOutValue
*@param double value: the value to set the attribute to
*/
	virtual void SetPullOutValue(double value);
/**
* Get double attribute PullOutValue
* @return double the vaue of the attribute 
*/
	virtual double GetPullOutValue() const;
/**
* Typesafe attribute validation of PullOutValue
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPullOutValue(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute WorkingLength
*@param double value: the value to set the attribute to
*/
	virtual void SetWorkingLength(double value);
/**
* Get double attribute WorkingLength
* @return double the vaue of the attribute 
*/
	virtual double GetWorkingLength() const;
/**
* Typesafe attribute validation of WorkingLength
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWorkingLength(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoSpinePreparationParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoSpinePreparationParams_H_
