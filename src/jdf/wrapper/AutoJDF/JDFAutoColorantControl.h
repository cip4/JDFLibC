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

 
#if !defined _JDFAutoColorantControl_H_
#define _JDFAutoColorantControl_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFColorantAlias;
class JDFSeparationList;
class JDFSeparationList;
class JDFSeparationList;
class JDFColorPool;
class JDFColorSpaceSubstitute;
class JDFSeparationList;
class JDFDeviceNSpace;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoColorantControl : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoColorantControl class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFColorantControl should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoColorantControl : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoColorantControl():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoColorantControl(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoColorantControl &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoColorantControl(){};
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
* Enumeration for attribute InternalColorModel
*/

	enum EnumInternalColorModel{InternalColorModel_Unknown,InternalColorModel_Basic,InternalColorModel_Enhanced,InternalColorModel_Explicit};
/**
* Enumeration for attribute MappingSelection
*/

	enum EnumMappingSelection{MappingSelection_Unknown,MappingSelection_UsePDLValues,MappingSelection_UseLocalPrinterValues,MappingSelection_UseProcessColorValues};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute ForceSeparations
*@param bool value: the value to set the attribute to
*/
	virtual void SetForceSeparations(bool value);
/**
* Get bool attribute ForceSeparations
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetForceSeparations() const;
/**
* Typesafe attribute validation of ForceSeparations
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidForceSeparations(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for InternalColorModel
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& InternalColorModelString();
/**
* Enumeration string for enum value
* @param EnumInternalColorModel value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString InternalColorModelString(EnumInternalColorModel value);
/**
* Set attribute InternalColorModel
* @param EnumInternalColorModel value the value to set the attribute to
*/
	virtual void SetInternalColorModel( EnumInternalColorModel value);

/**
* Typesafe enumerated attribute InternalColorModel
* @return EnumInternalColorModelthe enumeration value of the attribute
*/
	virtual EnumInternalColorModel GetInternalColorModel() const;

/**
* Typesafe attribute validation of InternalColorModel
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidInternalColorModel(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for MappingSelection
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& MappingSelectionString();
/**
* Enumeration string for enum value
* @param EnumMappingSelection value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString MappingSelectionString(EnumMappingSelection value);
/**
* Set attribute MappingSelection
* @param EnumMappingSelection value the value to set the attribute to
*/
	virtual void SetMappingSelection( EnumMappingSelection value);

/**
* Typesafe enumerated attribute MappingSelection
* @return EnumMappingSelectionthe enumeration value of the attribute
*/
	virtual EnumMappingSelection GetMappingSelection() const;

/**
* Typesafe attribute validation of MappingSelection
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMappingSelection(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ProcessColorModel
*@param WString value: the value to set the attribute to
*/
	virtual void SetProcessColorModel(const WString& value);
/**
* Get string attribute ProcessColorModel
* @return WString the vaue of the attribute 
*/
	virtual WString GetProcessColorModel() const;
/**
* Typesafe attribute validation of ProcessColorModel
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidProcessColorModel(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element ColorantAlias
* 
* @param int iSkip number of elements to skip
* @return JDFColorantAlias The element
*/
	JDFColorantAlias GetCreateColorantAlias(int iSkip=0);

/**
* const get element ColorantAlias
* @param int iSkip number of elements to skip
* @return JDFColorantAlias The element
*/
	JDFColorantAlias GetColorantAlias(int iSkip=0)const;
/**
* Append element ColorantAlias
 */
	JDFColorantAlias AppendColorantAlias();
/**
* create inter-resource link to refTarget
* @param JDFColorantAlias& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefColorantAlias(JDFColorantAlias& refTarget);

/** Get Element ColorantConvertProcess
* 
* @return JDFSeparationList The element
*/
	JDFSeparationList GetCreateColorantConvertProcess();

/**
* const get element ColorantConvertProcess
*@return  JDFSeparationList The element
*/
	JDFSeparationList GetColorantConvertProcess()const;
/**
* Append element ColorantConvertProcess
 * 
*/
	JDFSeparationList AppendColorantConvertProcess();

/** Get Element ColorantOrder
* 
* @return JDFSeparationList The element
*/
	JDFSeparationList GetCreateColorantOrder();

/**
* const get element ColorantOrder
*@return  JDFSeparationList The element
*/
	JDFSeparationList GetColorantOrder()const;
/**
* Append element ColorantOrder
 * 
*/
	JDFSeparationList AppendColorantOrder();

/** Get Element ColorantParams
* 
* @return JDFSeparationList The element
*/
	JDFSeparationList GetCreateColorantParams();

/**
* const get element ColorantParams
*@return  JDFSeparationList The element
*/
	JDFSeparationList GetColorantParams()const;
/**
* Append element ColorantParams
 * 
*/
	JDFSeparationList AppendColorantParams();

/** Get Element ColorPool
* 
* @return JDFColorPool The element
*/
	JDFColorPool GetCreateColorPool();

/**
* const get element ColorPool
*@return  JDFColorPool The element
*/
	JDFColorPool GetColorPool()const;
/**
* Append element ColorPool
 * 
*/
	JDFColorPool AppendColorPool();
/**
* create inter-resource link to refTarget
* @param JDFColorPool& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefColorPool(JDFColorPool& refTarget);

/** Get Element ColorSpaceSubstitute
* 
* @param int iSkip number of elements to skip
* @return JDFColorSpaceSubstitute The element
*/
	JDFColorSpaceSubstitute GetCreateColorSpaceSubstitute(int iSkip=0);

/**
* const get element ColorSpaceSubstitute
* @param int iSkip number of elements to skip
* @return JDFColorSpaceSubstitute The element
*/
	JDFColorSpaceSubstitute GetColorSpaceSubstitute(int iSkip=0)const;
/**
* Append element ColorSpaceSubstitute
 */
	JDFColorSpaceSubstitute AppendColorSpaceSubstitute();

/** Get Element DeviceColorantOrder
* 
* @return JDFSeparationList The element
*/
	JDFSeparationList GetCreateDeviceColorantOrder();

/**
* const get element DeviceColorantOrder
*@return  JDFSeparationList The element
*/
	JDFSeparationList GetDeviceColorantOrder()const;
/**
* Append element DeviceColorantOrder
 * 
*/
	JDFSeparationList AppendDeviceColorantOrder();

/** Get Element DeviceNSpace
* 
* @param int iSkip number of elements to skip
* @return JDFDeviceNSpace The element
*/
	JDFDeviceNSpace GetCreateDeviceNSpace(int iSkip=0);

/**
* const get element DeviceNSpace
* @param int iSkip number of elements to skip
* @return JDFDeviceNSpace The element
*/
	JDFDeviceNSpace GetDeviceNSpace(int iSkip=0)const;
/**
* Append element DeviceNSpace
 */
	JDFDeviceNSpace AppendDeviceNSpace();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoColorantControl

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoColorantControl_H_
