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

 
#if !defined _JDFAutoImageReplacementParams_H_
#define _JDFAutoImageReplacementParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFFileSpec;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoImageReplacementParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoImageReplacementParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFImageReplacementParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoImageReplacementParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoImageReplacementParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoImageReplacementParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoImageReplacementParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoImageReplacementParams(){};
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
* Enumeration for attribute ImageReplacementStrategy
*/

	enum EnumImageReplacementStrategy{ImageReplacementStrategy_Unknown,ImageReplacementStrategy_Omit,ImageReplacementStrategy_Proxy,ImageReplacementStrategy_Replace,ImageReplacementStrategy_AttemptReplacement};
/**
* Enumeration for attribute ResolutionReductionStrategy
*/

	enum EnumResolutionReductionStrategy{ResolutionReductionStrategy_Unknown,ResolutionReductionStrategy_Downsample,ResolutionReductionStrategy_Subsample,ResolutionReductionStrategy_Bicubic};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for ImageReplacementStrategy
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ImageReplacementStrategyString();
/**
* Enumeration string for enum value
* @param EnumImageReplacementStrategy value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ImageReplacementStrategyString(EnumImageReplacementStrategy value);
/**
* Set attribute ImageReplacementStrategy
* @param EnumImageReplacementStrategy value the value to set the attribute to
*/
	virtual void SetImageReplacementStrategy( EnumImageReplacementStrategy value);

/**
* Typesafe enumerated attribute ImageReplacementStrategy
* @return EnumImageReplacementStrategythe enumeration value of the attribute
*/
	virtual EnumImageReplacementStrategy GetImageReplacementStrategy() const;

/**
* Typesafe attribute validation of ImageReplacementStrategy
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidImageReplacementStrategy(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImagePreScanStrategy
*@param WString value: the value to set the attribute to
*/
	virtual void SetImagePreScanStrategy(const WString& value);
/**
* Get string attribute ImagePreScanStrategy
* @return WString the vaue of the attribute 
*/
	virtual WString GetImagePreScanStrategy() const;
/**
* Typesafe attribute validation of ImagePreScanStrategy
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImagePreScanStrategy(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxResolution
*@param double value: the value to set the attribute to
*/
	virtual void SetMaxResolution(double value);
/**
* Get double attribute MaxResolution
* @return double the vaue of the attribute 
*/
	virtual double GetMaxResolution() const;
/**
* Typesafe attribute validation of MaxResolution
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxResolution(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MinResolution
*@param double value: the value to set the attribute to
*/
	virtual void SetMinResolution(double value);
/**
* Get double attribute MinResolution
* @return double the vaue of the attribute 
*/
	virtual double GetMinResolution() const;
/**
* Typesafe attribute validation of MinResolution
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMinResolution(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ResolutionReductionStrategy
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ResolutionReductionStrategyString();
/**
* Enumeration string for enum value
* @param EnumResolutionReductionStrategy value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ResolutionReductionStrategyString(EnumResolutionReductionStrategy value);
/**
* Set attribute ResolutionReductionStrategy
* @param EnumResolutionReductionStrategy value the value to set the attribute to
*/
	virtual void SetResolutionReductionStrategy( EnumResolutionReductionStrategy value);

/**
* Typesafe enumerated attribute ResolutionReductionStrategy
* @return EnumResolutionReductionStrategythe enumeration value of the attribute
*/
	virtual EnumResolutionReductionStrategy GetResolutionReductionStrategy() const;

/**
* Typesafe attribute validation of ResolutionReductionStrategy
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidResolutionReductionStrategy(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnoreExtensions
*@param vWString value: the value to set the attribute to
*/
	virtual void SetIgnoreExtensions(const vWString& value);
/**
* Get string attribute IgnoreExtensions
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetIgnoreExtensions() const;
/**
* Typesafe attribute validation of IgnoreExtensions
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnoreExtensions(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxSearchRecursion
*@param int value: the value to set the attribute to
*/
	virtual void SetMaxSearchRecursion(int value);
/**
* Get integer attribute MaxSearchRecursion
* @return int the vaue of the attribute 
*/
	virtual int GetMaxSearchRecursion() const;
/**
* Typesafe attribute validation of MaxSearchRecursion
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxSearchRecursion(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element FileSpec
* 
* @param int iSkip number of elements to skip
* @return JDFFileSpec The element
*/
	JDFFileSpec GetCreateFileSpec(int iSkip=0);

/**
* const get element FileSpec
* @param int iSkip number of elements to skip
* @return JDFFileSpec The element
*/
	JDFFileSpec GetFileSpec(int iSkip=0)const;
/**
* Append element FileSpec
 */
	JDFFileSpec AppendFileSpec();
/**
* create inter-resource link to refTarget
* @param JDFFileSpec& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefFileSpec(JDFFileSpec& refTarget);

/** Get Element SearchPath
* 
* @param int iSkip number of elements to skip
* @return JDFElement The element
*/
	JDFElement GetCreateSearchPath(int iSkip=0);

/**
* const get element SearchPath
* @param int iSkip number of elements to skip
* @return JDFElement The element
*/
	JDFElement GetSearchPath(int iSkip=0)const;
/**
* Append element SearchPath
 */
	JDFElement AppendSearchPath();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoImageReplacementParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoImageReplacementParams_H_
