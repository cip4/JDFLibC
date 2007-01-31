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

 
#if !defined _JDFAutoTrappingDetails_H_
#define _JDFAutoTrappingDetails_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFTrappingOrder;
class JDFTrappingParams;
class JDFObjectResolution;
class JDFTrapRegion;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoTrappingDetails : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoTrappingDetails class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFTrappingDetails should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoTrappingDetails : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoTrappingDetails():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoTrappingDetails(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoTrappingDetails &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoTrappingDetails(){};
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
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute DefaultTrapping
*@param bool value: the value to set the attribute to
*/
	virtual void SetDefaultTrapping(bool value);
/**
* Get bool attribute DefaultTrapping
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetDefaultTrapping() const;
/**
* Typesafe attribute validation of DefaultTrapping
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDefaultTrapping(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnoreFileParams
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnoreFileParams(bool value);
/**
* Get bool attribute IgnoreFileParams
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetIgnoreFileParams() const;
/**
* Typesafe attribute validation of IgnoreFileParams
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnoreFileParams(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Trapping
*@param bool value: the value to set the attribute to
*/
	virtual void SetTrapping(bool value);
/**
* Get bool attribute Trapping
* @return bool the vaue of the attribute 
*/
	virtual bool GetTrapping() const;
/**
* Typesafe attribute validation of Trapping
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrapping(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrappingType
*@param int value: the value to set the attribute to
*/
	virtual void SetTrappingType(int value);
/**
* Get integer attribute TrappingType
* @return int the vaue of the attribute 
*/
	virtual int GetTrappingType() const;
/**
* Typesafe attribute validation of TrappingType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrappingType(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element TrappingOrder
* 
* @return JDFTrappingOrder The element
*/
	JDFTrappingOrder GetCreateTrappingOrder();

/**
* const get element TrappingOrder
*@return  JDFTrappingOrder The element
*/
	JDFTrappingOrder GetTrappingOrder()const;
/**
* Append element TrappingOrder
 * 
*/
	JDFTrappingOrder AppendTrappingOrder();

/** Get Element TrappingParams
* 
* @return JDFTrappingParams The element
*/
	JDFTrappingParams GetCreateTrappingParams();

/**
* const get element TrappingParams
*@return  JDFTrappingParams The element
*/
	JDFTrappingParams GetTrappingParams()const;
/**
* Append element TrappingParams
 * 
*/
	JDFTrappingParams AppendTrappingParams();
/**
* create inter-resource link to refTarget
* @param JDFTrappingParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefTrappingParams(JDFTrappingParams& refTarget);

/** Get Element ObjectResolution
* 
* @param int iSkip number of elements to skip
* @return JDFObjectResolution The element
*/
	JDFObjectResolution GetCreateObjectResolution(int iSkip=0);

/**
* const get element ObjectResolution
* @param int iSkip number of elements to skip
* @return JDFObjectResolution The element
*/
	JDFObjectResolution GetObjectResolution(int iSkip=0)const;
/**
* Append element ObjectResolution
 */
	JDFObjectResolution AppendObjectResolution();
/**
* create inter-resource link to refTarget
* @param JDFObjectResolution& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefObjectResolution(JDFObjectResolution& refTarget);

/** Get Element TrapRegion
* 
* @param int iSkip number of elements to skip
* @return JDFTrapRegion The element
*/
	JDFTrapRegion GetCreateTrapRegion(int iSkip=0);

/**
* const get element TrapRegion
* @param int iSkip number of elements to skip
* @return JDFTrapRegion The element
*/
	JDFTrapRegion GetTrapRegion(int iSkip=0)const;
/**
* Append element TrapRegion
 */
	JDFTrapRegion AppendTrapRegion();
/**
* create inter-resource link to refTarget
* @param JDFTrapRegion& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefTrapRegion(JDFTrapRegion& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoTrappingDetails

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoTrappingDetails_H_
