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

 
#if !defined _JDFAutoSaddleStitchingParams_H_
#define _JDFAutoSaddleStitchingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoSaddleStitchingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoSaddleStitchingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFSaddleStitchingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoSaddleStitchingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoSaddleStitchingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoSaddleStitchingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoSaddleStitchingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoSaddleStitchingParams(){};
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
* Enumeration for attribute StapleShape
*/

	enum EnumStapleShape{StapleShape_Unknown,StapleShape_Crown,StapleShape_Overlap,StapleShape_Butted,StapleShape_ClinchOut,StapleShape_Eyelet};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute NumberOfStitches
*@param int value: the value to set the attribute to
*/
	virtual void SetNumberOfStitches(int value);
/**
* Get integer attribute NumberOfStitches
* @return int the vaue of the attribute 
*/
	virtual int GetNumberOfStitches() const;
/**
* Typesafe attribute validation of NumberOfStitches
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNumberOfStitches(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StitchPositions
*@param JDFNumberList value: the value to set the attribute to
*/
	virtual void SetStitchPositions(const JDFNumberList& value);
/**
* Get string attribute StitchPositions
* @return JDFNumberList the vaue of the attribute 
*/
	virtual JDFNumberList GetStitchPositions() const;
/**
* Typesafe attribute validation of StitchPositions
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStitchPositions(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for StapleShape
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& StapleShapeString();
/**
* Enumeration string for enum value
* @param EnumStapleShape value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString StapleShapeString(EnumStapleShape value);
/**
* Set attribute StapleShape
* @param EnumStapleShape value the value to set the attribute to
*/
	virtual void SetStapleShape( EnumStapleShape value);

/**
* Typesafe enumerated attribute StapleShape
* @return EnumStapleShapethe enumeration value of the attribute
*/
	virtual EnumStapleShape GetStapleShape() const;

/**
* Typesafe attribute validation of StapleShape
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidStapleShape(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StitchWidth
*@param double value: the value to set the attribute to
*/
	virtual void SetStitchWidth(double value);
/**
* Get double attribute StitchWidth
* @return double the vaue of the attribute 
*/
	virtual double GetStitchWidth() const;
/**
* Typesafe attribute validation of StitchWidth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStitchWidth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute WireGauge
*@param double value: the value to set the attribute to
*/
	virtual void SetWireGauge(double value);
/**
* Get double attribute WireGauge
* @return double the vaue of the attribute 
*/
	virtual double GetWireGauge() const;
/**
* Typesafe attribute validation of WireGauge
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWireGauge(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute WireBrand
*@param WString value: the value to set the attribute to
*/
	virtual void SetWireBrand(const WString& value);
/**
* Get string attribute WireBrand
* @return WString the vaue of the attribute 
*/
	virtual WString GetWireBrand() const;
/**
* Typesafe attribute validation of WireBrand
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWireBrand(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoSaddleStitchingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoSaddleStitchingParams_H_
