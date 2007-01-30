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

 
#if !defined _JDFAutoFitPolicy_H_
#define _JDFAutoFitPolicy_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoFitPolicy : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoFitPolicy class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFFitPolicy should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoFitPolicy : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoFitPolicy():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoFitPolicy(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoFitPolicy &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoFitPolicy(){};
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
* Enumeration for attribute GutterPolicy
*/

	enum EnumGutterPolicy{GutterPolicy_Unknown,GutterPolicy_Distribute,GutterPolicy_Fixed};
/**
* Enumeration for attribute RotatePolicy
*/

	enum EnumRotatePolicy{RotatePolicy_Unknown,RotatePolicy_NoRotate,RotatePolicy_RotateOrthogonal,RotatePolicy_RotateClockwise,RotatePolicy_RotateCounterClockwise};
/**
* Enumeration for attribute SizePolicy
*/

	enum EnumSizePolicy{SizePolicy_Unknown,SizePolicy_ClipToMaxPage,SizePolicy_Abort,SizePolicy_FitToPage,SizePolicy_ReduceToFit,SizePolicy_Tile};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for GutterPolicy
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& GutterPolicyString();
/**
* Enumeration string for enum value
* @param EnumGutterPolicy value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString GutterPolicyString(EnumGutterPolicy value);
/**
* Set attribute GutterPolicy
* @param EnumGutterPolicy value the value to set the attribute to
*/
	virtual void SetGutterPolicy( EnumGutterPolicy value);

/**
* Typesafe enumerated attribute GutterPolicy; defaults to Fixed
* @return EnumGutterPolicythe enumeration value of the attribute
*/
	virtual EnumGutterPolicy GetGutterPolicy() const;

/**
* Typesafe attribute validation of GutterPolicy
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidGutterPolicy(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ClipOffset
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetClipOffset(const JDFXYPair& value);
/**
* Get string attribute ClipOffset
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetClipOffset() const;
/**
* Typesafe attribute validation of ClipOffset
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidClipOffset(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MinGutter
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetMinGutter(const JDFXYPair& value);
/**
* Get string attribute MinGutter
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetMinGutter() const;
/**
* Typesafe attribute validation of MinGutter
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMinGutter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for RotatePolicy
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& RotatePolicyString();
/**
* Enumeration string for enum value
* @param EnumRotatePolicy value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString RotatePolicyString(EnumRotatePolicy value);
/**
* Set attribute RotatePolicy
* @param EnumRotatePolicy value the value to set the attribute to
*/
	virtual void SetRotatePolicy( EnumRotatePolicy value);

/**
* Typesafe enumerated attribute RotatePolicy
* @return EnumRotatePolicythe enumeration value of the attribute
*/
	virtual EnumRotatePolicy GetRotatePolicy() const;

/**
* Typesafe attribute validation of RotatePolicy
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidRotatePolicy(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for SizePolicy
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SizePolicyString();
/**
* Enumeration string for enum value
* @param EnumSizePolicy value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SizePolicyString(EnumSizePolicy value);
/**
* Set attribute SizePolicy
* @param EnumSizePolicy value the value to set the attribute to
*/
	virtual void SetSizePolicy( EnumSizePolicy value);

/**
* Typesafe enumerated attribute SizePolicy
* @return EnumSizePolicythe enumeration value of the attribute
*/
	virtual EnumSizePolicy GetSizePolicy() const;

/**
* Typesafe attribute validation of SizePolicy
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSizePolicy(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoFitPolicy

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoFitPolicy_H_
