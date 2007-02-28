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

 
#if !defined _JDFAutoAutomatedOverPrintParams_H_
#define _JDFAutoAutomatedOverPrintParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoAutomatedOverPrintParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoAutomatedOverPrintParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFAutomatedOverPrintParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoAutomatedOverPrintParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoAutomatedOverPrintParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoAutomatedOverPrintParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoAutomatedOverPrintParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoAutomatedOverPrintParams(){};
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
* Set attribute KnockOutCMYKWhite
*@param bool value: the value to set the attribute to
*/
	virtual void SetKnockOutCMYKWhite(bool value);
/**
* Get bool attribute KnockOutCMYKWhite
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetKnockOutCMYKWhite() const;
/**
* Typesafe attribute validation of KnockOutCMYKWhite
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidKnockOutCMYKWhite(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OverPrintBlackText
*@param bool value: the value to set the attribute to
*/
	virtual void SetOverPrintBlackText(bool value);
/**
* Get bool attribute OverPrintBlackText
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetOverPrintBlackText() const;
/**
* Typesafe attribute validation of OverPrintBlackText
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOverPrintBlackText(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OverPrintBlackLineArt
*@param bool value: the value to set the attribute to
*/
	virtual void SetOverPrintBlackLineArt(bool value);
/**
* Get bool attribute OverPrintBlackLineArt
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetOverPrintBlackLineArt() const;
/**
* Typesafe attribute validation of OverPrintBlackLineArt
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOverPrintBlackLineArt(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TextBlackLevel
*@param double value: the value to set the attribute to
*/
	virtual void SetTextBlackLevel(double value);
/**
* Get double attribute TextBlackLevel
* @return double the vaue of the attribute ; defaults to 1
*/
	virtual double GetTextBlackLevel() const;
/**
* Typesafe attribute validation of TextBlackLevel
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTextBlackLevel(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LineArtBlackLevel
*@param double value: the value to set the attribute to
*/
	virtual void SetLineArtBlackLevel(double value);
/**
* Get double attribute LineArtBlackLevel
* @return double the vaue of the attribute 
*/
	virtual double GetLineArtBlackLevel() const;
/**
* Typesafe attribute validation of LineArtBlackLevel
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLineArtBlackLevel(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TextSizeThreshold
*@param int value: the value to set the attribute to
*/
	virtual void SetTextSizeThreshold(int value);
/**
* Get integer attribute TextSizeThreshold
* @return int the vaue of the attribute 
*/
	virtual int GetTextSizeThreshold() const;
/**
* Typesafe attribute validation of TextSizeThreshold
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTextSizeThreshold(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoAutomatedOverPrintParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoAutomatedOverPrintParams_H_
