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

 
#if !defined _JDFAutoInsertSheet_H_
#define _JDFAutoInsertSheet_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFRunList;
class JDFLayout;
class JDFSheet;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoInsertSheet : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoInsertSheet class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFInsertSheet should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoInsertSheet : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoInsertSheet():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoInsertSheet(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoInsertSheet &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoInsertSheet(){};
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
* Enumeration for attribute SheetType
*/

	enum EnumSheetType{SheetType_Unknown,SheetType_AccountingSheet,SheetType_ErrorSheet,SheetType_FillSheet,SheetType_InsertSheet,SheetType_JobSheet,SheetType_SeparatorSheet};
/**
* Enumeration for attribute SheetUsage
*/

	enum EnumSheetUsage{SheetUsage_Unknown,SheetUsage_FillForceBack,SheetUsage_FillForceFront,SheetUsage_FillSheet,SheetUsage_FillSignature,SheetUsage_FillSurface,SheetUsage_Header,SheetUsage_Interleaved,SheetUsage_InterleavedBefore,SheetUsage_OnError,SheetUsage_Slip,SheetUsage_SlipCopy,SheetUsage_Trailer};
/**
* Enumeration for attribute IncludeInBundleItem
*/

	enum EnumIncludeInBundleItem{IncludeInBundleItem_Unknown,IncludeInBundleItem_After,IncludeInBundleItem_Before,IncludeInBundleItem_None,IncludeInBundleItem_New};
/**
* Enumeration for attribute Usage
*/

	enum EnumUsage{Usage_Unknown,Usage_FillForceBack,Usage_FillForceFront,Usage_FillSheet,Usage_FillSignature,Usage_FillSurface,Usage_Header,Usage_Interleaved,Usage_InterleavedBefore,Usage_OnError,Usage_Slip,Usage_SlipCopy,Usage_Trailer};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for SheetType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SheetTypeString();
/**
* Enumeration string for enum value
* @param EnumSheetType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SheetTypeString(EnumSheetType value);
/**
* Set attribute SheetType
* @param EnumSheetType value the value to set the attribute to
*/
	virtual void SetSheetType( EnumSheetType value);

/**
* Typesafe enumerated attribute SheetType
* @return EnumSheetTypethe enumeration value of the attribute
*/
	virtual EnumSheetType GetSheetType() const;

/**
* Typesafe attribute validation of SheetType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSheetType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for SheetUsage
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SheetUsageString();
/**
* Enumeration string for enum value
* @param EnumSheetUsage value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SheetUsageString(EnumSheetUsage value);
/**
* Set attribute SheetUsage
* @param EnumSheetUsage value the value to set the attribute to
*/
	virtual void SetSheetUsage( EnumSheetUsage value);

/**
* Typesafe enumerated attribute SheetUsage
* @return EnumSheetUsagethe enumeration value of the attribute
*/
	virtual EnumSheetUsage GetSheetUsage() const;

/**
* Typesafe attribute validation of SheetUsage
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSheetUsage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for IncludeInBundleItem
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& IncludeInBundleItemString();
/**
* Enumeration string for enum value
* @param EnumIncludeInBundleItem value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString IncludeInBundleItemString(EnumIncludeInBundleItem value);
/**
* Set attribute IncludeInBundleItem
* @param EnumIncludeInBundleItem value the value to set the attribute to
*/
	virtual void SetIncludeInBundleItem( EnumIncludeInBundleItem value);

/**
* Typesafe enumerated attribute IncludeInBundleItem
* @return EnumIncludeInBundleItemthe enumeration value of the attribute
*/
	virtual EnumIncludeInBundleItem GetIncludeInBundleItem() const;

/**
* Typesafe attribute validation of IncludeInBundleItem
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidIncludeInBundleItem(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IsWaste
*@param bool value: the value to set the attribute to
*/
	virtual void SetIsWaste(bool value);
/**
* Get bool attribute IsWaste
* @return bool the vaue of the attribute 
*/
	virtual bool GetIsWaste() const;
/**
* Typesafe attribute validation of IsWaste
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIsWaste(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MarkList
*@param vWString value: the value to set the attribute to
*/
	virtual void SetMarkList(const vWString& value);
/**
* Get string attribute MarkList
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetMarkList() const;
/**
* Typesafe attribute validation of MarkList
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMarkList(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SheetFormat
*@param WString value: the value to set the attribute to
*/
	virtual void SetSheetFormat(const WString& value);
/**
* Get string attribute SheetFormat
* @return WString the vaue of the attribute 
*/
	virtual WString GetSheetFormat() const;
/**
* Typesafe attribute validation of SheetFormat
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSheetFormat(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Usage
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& UsageString();
/**
* Enumeration string for enum value
* @param EnumUsage value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString UsageString(EnumUsage value);
/**
* Set attribute Usage
* @param EnumUsage value the value to set the attribute to
*/
	virtual void SetUsage( EnumUsage value);

/**
* Typesafe enumerated attribute Usage
* @return EnumUsagethe enumeration value of the attribute
*/
	virtual EnumUsage GetUsage() const;

/**
* Typesafe attribute validation of Usage
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidUsage(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element RunList
* 
* @return JDFRunList The element
*/
	JDFRunList GetCreateRunList();

/**
* const get element RunList
*@return  JDFRunList The element
*/
	JDFRunList GetRunList()const;
/**
* Append element RunList
 * 
*/
	JDFRunList AppendRunList();
/**
* create inter-resource link to refTarget
* @param JDFRunList& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefRunList(JDFRunList& refTarget);

/** Get Element Layout
* 
* @return JDFLayout The element
*/
	JDFLayout GetCreateLayout();

/**
* const get element Layout
*@return  JDFLayout The element
*/
	JDFLayout GetLayout()const;
/**
* Append element Layout
 * 
*/
	JDFLayout AppendLayout();
/**
* create inter-resource link to refTarget
* @param JDFLayout& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefLayout(JDFLayout& refTarget);

/** Get Element Sheet
* 
* @return JDFSheet The element
*/
	JDFSheet GetCreateSheet();

/**
* const get element Sheet
*@return  JDFSheet The element
*/
	JDFSheet GetSheet()const;
/**
* Append element Sheet
 * 
*/
	JDFSheet AppendSheet();
/**
* create inter-resource link to refTarget
* @param JDFSheet& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefSheet(JDFSheet& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoInsertSheet

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoInsertSheet_H_
