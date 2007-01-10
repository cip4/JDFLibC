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

 
#if !defined _JDFAutoDisjointing_H_
#define _JDFAutoDisjointing_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFInsertSheet;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoDisjointing : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoDisjointing class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFDisjointing should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoDisjointing : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoDisjointing():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoDisjointing(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoDisjointing &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoDisjointing(){};
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
* Enumeration for attribute OffsetDirection
*/

	enum EnumOffsetDirection{OffsetDirection_Unknown,OffsetDirection_Alternate,OffsetDirection_Left,OffsetDirection_None,OffsetDirection_Right,OffsetDirection_Straight,OffsetDirection_SystemSpecified};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute Number
*@param int value: the value to set the attribute to
*/
	virtual void SetNumber(int value);
/**
* Get integer attribute Number
* @return int the vaue of the attribute 
*/
	virtual int GetNumber() const;
/**
* Typesafe attribute validation of Number
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNumber(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Offset
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetOffset(const JDFXYPair& value);
/**
* Get string attribute Offset
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetOffset() const;
/**
* Typesafe attribute validation of Offset
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOffset(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OffsetAmount
*@param int value: the value to set the attribute to
*/
	virtual void SetOffsetAmount(int value);
/**
* Get integer attribute OffsetAmount
* @return int the vaue of the attribute 
*/
	virtual int GetOffsetAmount() const;
/**
* Typesafe attribute validation of OffsetAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOffsetAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for OffsetDirection
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& OffsetDirectionString();
/**
* Enumeration string for enum value
* @param EnumOffsetDirection value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString OffsetDirectionString(EnumOffsetDirection value);
/**
* Set attribute OffsetDirection
* @param EnumOffsetDirection value the value to set the attribute to
*/
	virtual void SetOffsetDirection( EnumOffsetDirection value);

/**
* Typesafe enumerated attribute OffsetDirection
* @return EnumOffsetDirectionthe enumeration value of the attribute
*/
	virtual EnumOffsetDirection GetOffsetDirection() const;

/**
* Typesafe attribute validation of OffsetDirection
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidOffsetDirection(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Overfold
*@param double value: the value to set the attribute to
*/
	virtual void SetOverfold(double value);
/**
* Get double attribute Overfold
* @return double the vaue of the attribute 
*/
	virtual double GetOverfold() const;
/**
* Typesafe attribute validation of Overfold
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOverfold(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element InsertSheet
* 
* @param int iSkip number of elements to skip
* @return JDFInsertSheet The element
*/
	JDFInsertSheet GetCreateInsertSheet(int iSkip=0);

/**
* const get element InsertSheet
* @param int iSkip number of elements to skip
* @return JDFInsertSheet The element
*/
	JDFInsertSheet GetInsertSheet(int iSkip=0)const;
/**
* Append element InsertSheet
 */
	JDFInsertSheet AppendInsertSheet();
/**
* create inter-resource link to refTarget
* @param JDFInsertSheet& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefInsertSheet(JDFInsertSheet& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoDisjointing

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoDisjointing_H_
