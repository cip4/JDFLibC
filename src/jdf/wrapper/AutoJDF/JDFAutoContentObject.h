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

 
#if !defined _JDFAutoContentObject_H_
#define _JDFAutoContentObject_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFPlacedObject.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoContentObject : public JDFPlacedObject

*********************************************************************
*/
/**
* automatically generated header for JDFAutoContentObject class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFContentObject should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoContentObject : public JDFPlacedObject{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoContentObject():JDFPlacedObject(){};
/**
* copy ctor
*/
	inline JDFAutoContentObject(const KElement & other):JDFPlacedObject(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoContentObject &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoContentObject(){};
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
* Enumeration for attribute Type
*/

	enum EnumType{Type_Unknown,Type_Content,Type_Mark};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute DocOrd
*@param int value: the value to set the attribute to
*/
	virtual void SetDocOrd(int value);
/**
* Get integer attribute DocOrd
* @return int the vaue of the attribute 
*/
	virtual int GetDocOrd() const;
/**
* Typesafe attribute validation of DocOrd
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDocOrd(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Ord
*@param int value: the value to set the attribute to
*/
	virtual void SetOrd(int value);
/**
* Get integer attribute Ord
* @return int the vaue of the attribute 
*/
	virtual int GetOrd() const;
/**
* Typesafe attribute validation of Ord
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOrd(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OrdExpression
*@param WString value: the value to set the attribute to
*/
	virtual void SetOrdExpression(const WString& value);
/**
* Get string attribute OrdExpression
* @return WString the vaue of the attribute 
*/
	virtual WString GetOrdExpression() const;
/**
* Typesafe attribute validation of OrdExpression
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOrdExpression(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SetOrd
*@param int value: the value to set the attribute to
*/
	virtual void SetSetOrd(int value);
/**
* Get integer attribute SetOrd
* @return int the vaue of the attribute 
*/
	virtual int GetSetOrd() const;
/**
* Typesafe attribute validation of SetOrd
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSetOrd(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ClipBox
*@param JDFRectangle value: the value to set the attribute to
*/
	virtual void SetClipBox(const JDFRectangle& value);
/**
* Get string attribute ClipBox
* @return JDFRectangle the vaue of the attribute 
*/
	virtual JDFRectangle GetClipBox() const;
/**
* Typesafe attribute validation of ClipBox
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidClipBox(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ClipPath
*@param WString value: the value to set the attribute to
*/
	virtual void SetClipPath(const WString& value);
/**
* Get string attribute ClipPath
* @return WString the vaue of the attribute 
*/
	virtual WString GetClipPath() const;
/**
* Typesafe attribute validation of ClipPath
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidClipPath(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CTM
*@param JDFMatrix value: the value to set the attribute to
*/
	virtual void SetCTM(const JDFMatrix& value);
/**
* Get string attribute CTM
* @return JDFMatrix the vaue of the attribute 
*/
	virtual JDFMatrix GetCTM() const;
/**
* Typesafe attribute validation of CTM
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCTM(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HalfTonePhaseOrigin
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetHalfTonePhaseOrigin(const JDFXYPair& value);
/**
* Get string attribute HalfTonePhaseOrigin
* @return JDFXYPair the vaue of the attribute ; defaults to 0 0
*/
	virtual JDFXYPair GetHalfTonePhaseOrigin() const;
/**
* Typesafe attribute validation of HalfTonePhaseOrigin
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHalfTonePhaseOrigin(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LayerID
*@param int value: the value to set the attribute to
*/
	virtual void SetLayerID(int value);
/**
* Get integer attribute LayerID
* @return int the vaue of the attribute 
*/
	virtual int GetLayerID() const;
/**
* Typesafe attribute validation of LayerID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLayerID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OrdID
*@param int value: the value to set the attribute to
*/
	virtual void SetOrdID(int value);
/**
* Get integer attribute OrdID
* @return int the vaue of the attribute 
*/
	virtual int GetOrdID() const;
/**
* Typesafe attribute validation of OrdID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOrdID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SourceClipPath
*@param WString value: the value to set the attribute to
*/
	virtual void SetSourceClipPath(const WString& value);
/**
* Get string attribute SourceClipPath
* @return WString the vaue of the attribute 
*/
	virtual WString GetSourceClipPath() const;
/**
* Typesafe attribute validation of SourceClipPath
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSourceClipPath(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrimCTM
*@param JDFMatrix value: the value to set the attribute to
*/
	virtual void SetTrimCTM(const JDFMatrix& value);
/**
* Get string attribute TrimCTM
* @return JDFMatrix the vaue of the attribute 
*/
	virtual JDFMatrix GetTrimCTM() const;
/**
* Typesafe attribute validation of TrimCTM
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrimCTM(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Enumeration strings for Type
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& TypeString();
/**
* Enumeration string for enum value
* @param EnumType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString TypeString(EnumType value);
/**
* Set attribute Type
* @param EnumType value the value to set the attribute to
*/
	virtual void SetType( EnumType value);

/**
* Typesafe enumerated attribute Type
* @return EnumTypethe enumeration value of the attribute
*/
	virtual EnumType GetType() const;

/**
* Typesafe attribute validation of Type
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidType(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoContentObject

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoContentObject_H_
