/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2006 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoPerformance_H_
#define _JDFAutoPerformance_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPerformance : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPerformance class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPerformance should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPerformance : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPerformance():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoPerformance(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPerformance &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPerformance(){};
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
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute AverageAmount
*@param double value: the value to set the attribute to
*/
	virtual void SetAverageAmount(double value);
/**
* Get double attribute AverageAmount
* @return double the vaue of the attribute 
*/
	virtual double GetAverageAmount() const;
/**
* Typesafe attribute validation of AverageAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAverageAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AverageCleanup
*@param JDFDuration value: the value to set the attribute to
*/
	virtual void SetAverageCleanup(JDFDuration value=JDFDuration());
/**
* Get string attribute AverageCleanup
* @return JDFDuration the vaue of the attribute 
*/
	virtual JDFDuration GetAverageCleanup() const;
/**
* Typesafe attribute validation of AverageCleanup
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAverageCleanup(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AverageSetup
*@param JDFDuration value: the value to set the attribute to
*/
	virtual void SetAverageSetup(JDFDuration value=JDFDuration());
/**
* Get string attribute AverageSetup
* @return JDFDuration the vaue of the attribute 
*/
	virtual JDFDuration GetAverageSetup() const;
/**
* Typesafe attribute validation of AverageSetup
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAverageSetup(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxAmount
*@param double value: the value to set the attribute to
*/
	virtual void SetMaxAmount(double value);
/**
* Get double attribute MaxAmount
* @return double the vaue of the attribute 
*/
	virtual double GetMaxAmount() const;
/**
* Typesafe attribute validation of MaxAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxCleanup
*@param JDFDuration value: the value to set the attribute to
*/
	virtual void SetMaxCleanup(JDFDuration value=JDFDuration());
/**
* Get string attribute MaxCleanup
* @return JDFDuration the vaue of the attribute 
*/
	virtual JDFDuration GetMaxCleanup() const;
/**
* Typesafe attribute validation of MaxCleanup
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxCleanup(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxSetup
*@param JDFDuration value: the value to set the attribute to
*/
	virtual void SetMaxSetup(JDFDuration value=JDFDuration());
/**
* Get string attribute MaxSetup
* @return JDFDuration the vaue of the attribute 
*/
	virtual JDFDuration GetMaxSetup() const;
/**
* Typesafe attribute validation of MaxSetup
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxSetup(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MinAmount
*@param double value: the value to set the attribute to
*/
	virtual void SetMinAmount(double value);
/**
* Get double attribute MinAmount
* @return double the vaue of the attribute 
*/
	virtual double GetMinAmount() const;
/**
* Typesafe attribute validation of MinAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMinAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MinCleanup
*@param JDFDuration value: the value to set the attribute to
*/
	virtual void SetMinCleanup(JDFDuration value=JDFDuration());
/**
* Get string attribute MinCleanup
* @return JDFDuration the vaue of the attribute 
*/
	virtual JDFDuration GetMinCleanup() const;
/**
* Typesafe attribute validation of MinCleanup
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMinCleanup(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MinSetup
*@param JDFDuration value: the value to set the attribute to
*/
	virtual void SetMinSetup(JDFDuration value=JDFDuration());
/**
* Get string attribute MinSetup
* @return JDFDuration the vaue of the attribute 
*/
	virtual JDFDuration GetMinSetup() const;
/**
* Typesafe attribute validation of MinSetup
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMinSetup(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Name
*@param WString value: the value to set the attribute to
*/
	virtual void SetName(const WString& value);
/**
* Get string attribute Name
* @return WString the vaue of the attribute 
*/
	virtual WString GetName() const;
/**
* Typesafe attribute validation of Name
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DevCapsRef
*@param WString value: the value to set the attribute to
*/
	virtual void SetDevCapsRef(const WString& value);
/**
* Get string attribute DevCapsRef
* @return WString the vaue of the attribute 
*/
	virtual WString GetDevCapsRef() const;
/**
* Typesafe attribute validation of DevCapsRef
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDevCapsRef(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Unit
*@param WString value: the value to set the attribute to
*/
	virtual void SetUnit(const WString& value);
/**
* Get string attribute Unit
* @return WString the vaue of the attribute 
*/
	virtual WString GetUnit() const;
/**
* Typesafe attribute validation of Unit
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidUnit(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoPerformance

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPerformance_H_
