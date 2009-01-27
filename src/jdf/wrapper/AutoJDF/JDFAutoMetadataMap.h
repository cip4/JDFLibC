/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2009 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoMetadataMap_H_
#define _JDFAutoMetadataMap_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFRefElement;
/*
*********************************************************************
class JDFAutoMetadataMap : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoMetadataMap class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFMetadataMap should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoMetadataMap : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoMetadataMap():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoMetadataMap(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoMetadataMap &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoMetadataMap(){};
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
* Enumeration for attribute DataType
*/

	enum EnumDataType{DataType_Unknown,DataType_BinderySignatureName,DataType_BlockName,DataType_BundleItemIndex,DataType_CellIndex,DataType_Condition,DataType_DeliveryUnit0,DataType_DeliveryUnit1,DataType_DeliveryUnit2,DataType_DeliveryUnit3,DataType_DeliveryUnit4,DataType_DeliveryUnit5,DataType_DeliveryUnit6,DataType_DeliveryUnit7,DataType_DeliveryUnit8,DataType_DeliveryUnit9,DataType_DocCopies,DataType_DocIndex,DataType_DocRunIndex,DataType_DocSheetIndex,DataType_DocTags,DataType_Edition,DataType_EditionVersion,DataType_FountainNumber,DataType_ItemNames,DataType_LayerIDs,DataType_Location,DataType_Option,DataType_PageNumber,DataType_PageTags,DataType_PlateLayout,DataType_PartVersion,DataType_PreflightRule,DataType_PreviewType,DataType_RibbonName,DataType_Run,DataType_RunIndex,DataType_RunPage,DataType_RunTags,DataType_RunSet,DataType_SectionIndex,DataType_Separation,DataType_SetDocIndex,DataType_SetIndex,DataType_SetRunIndex,DataType_SetSheetIndex,DataType_SetTags,DataType_SheetIndex,DataType_SheetName,DataType_Side,DataType_SignatureName,DataType_StationName,DataType_SubRun,DataType_TileID,DataType_WebName,DataType_WebProduct,DataType_WebSetup};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for DataType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& DataTypeString();
/**
* Enumeration string for enum value
* @param EnumDataType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString DataTypeString(EnumDataType value);
/**
* Append value to the attribute DataType
* @param EnumDataType value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint AddDataType( EnumDataType value);
/**
* Remove value from the attribute DataType
* @param EnumDataType value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint RemoveDataType( EnumDataType value);
/**
* Typesafe enumerated attribute DataType
* @return EnumDataTypethe enumeration value of the attribute
*/
	virtual vint GetDataType() const;
/**
* Set value of the attribute DataType
* @param EnumDataType value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetDataType( EnumDataType value);
/**
* Set value of the attribute DataType to a list
* @param vint value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetDataType( const vint& value);
/**
* Typesafe attribute validation of DataType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidDataType(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute ValueFormat
*@param WString value: the value to set the attribute to
*/
	virtual void SetValueFormat(const WString& value);
/**
* Get string attribute ValueFormat
* @return WString the vaue of the attribute 
*/
	virtual WString GetValueFormat() const;
/**
* Typesafe attribute validation of ValueFormat
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidValueFormat(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ValueTemplate
*@param WString value: the value to set the attribute to
*/
	virtual void SetValueTemplate(const WString& value);
/**
* Get string attribute ValueTemplate
* @return WString the vaue of the attribute 
*/
	virtual WString GetValueTemplate() const;
/**
* Typesafe attribute validation of ValueTemplate
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidValueTemplate(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/**
 definition of required elements in the JDF namespace
*/
	virtual WString RequiredElements()const;
}; // endJDFAutoMetadataMap

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoMetadataMap_H_