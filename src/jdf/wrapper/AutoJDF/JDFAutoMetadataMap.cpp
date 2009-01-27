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

 
#include "jdf/wrapper/AutoJDF/JDFAutoMetadataMap.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoMetadataMap : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoMetadataMap& JDFAutoMetadataMap::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoMetadataMap: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoMetadataMap::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoMetadataMap::ValidNodeNames()const{
	return L"*:,MetadataMap";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoMetadataMap::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",DataType,Name,ValueFormat,ValueTemplate");
};

/**
 typesafe validator
*/
	vWString JDFAutoMetadataMap::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDataType(level)) {
			vAtts.push_back(atr_DataType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidName(level)) {
			vAtts.push_back(atr_Name);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidValueFormat(level)) {
			vAtts.push_back(atr_ValueFormat);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidValueTemplate(level)) {
			vAtts.push_back(atr_ValueTemplate);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMetadataMap::DataTypeString(){
		static const WString enums=WString(L"Unknown,BinderySignatureName,BlockName,BundleItemIndex,CellIndex,Condition,DeliveryUnit0,DeliveryUnit1,DeliveryUnit2,DeliveryUnit3")
	+WString(L",DeliveryUnit4,DeliveryUnit5,DeliveryUnit6,DeliveryUnit7,DeliveryUnit8,DeliveryUnit9,DocCopies,DocIndex,DocRunIndex,DocSheetIndex")
	+WString(L",DocTags,Edition,EditionVersion,FountainNumber,ItemNames,LayerIDs,Location,Option,PageNumber,PageTags")
	+WString(L",PlateLayout,PartVersion,PreflightRule,PreviewType,RibbonName,Run,RunIndex,RunPage,RunTags,RunSet")
	+WString(L",SectionIndex,Separation,SetDocIndex,SetIndex,SetRunIndex,SetSheetIndex,SetTags,SheetIndex,SheetName,Side")
	+WString(L",SignatureName,StationName,SubRun,TileID,WebName,WebProduct,WebSetup");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMetadataMap::DataTypeString(EnumDataType value){
		return DataTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoMetadataMap::AddDataType( EnumDataType value){
	return AddEnumerationsAttribute(atr_DataType,value,DataTypeString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoMetadataMap::RemoveDataType( EnumDataType value){
	return RemoveEnumerationsAttribute(atr_DataType,value,DataTypeString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoMetadataMap::GetDataType() const {
	return GetEnumerationsAttribute(atr_DataType,DataTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoMetadataMap::SetDataType( EnumDataType value){
	SetEnumAttribute(atr_DataType,value,DataTypeString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoMetadataMap::SetDataType( const vint& value){
	SetEnumerationsAttribute(atr_DataType,value,DataTypeString());
};
/**
* Typesafe attribute validation of DataType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMetadataMap::ValidDataType(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_DataType,DataTypeString(),false);
	};
/**
* Set attribute Name
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMetadataMap::SetName(const WString& value){
	SetAttribute(atr_Name,value);
};
/**
* Get string attribute Name
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMetadataMap::GetName() const {
	return GetAttribute(atr_Name,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMetadataMap::ValidName(EnumValidationLevel level) const {
		return ValidAttribute(atr_Name,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute ValueFormat
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMetadataMap::SetValueFormat(const WString& value){
	SetAttribute(atr_ValueFormat,value);
};
/**
* Get string attribute ValueFormat
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMetadataMap::GetValueFormat() const {
	return GetAttribute(atr_ValueFormat,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMetadataMap::ValidValueFormat(EnumValidationLevel level) const {
		return ValidAttribute(atr_ValueFormat,AttributeType_string,false);
	};
/**
* Set attribute ValueTemplate
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMetadataMap::SetValueTemplate(const WString& value){
	SetAttribute(atr_ValueTemplate,value);
};
/**
* Get string attribute ValueTemplate
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMetadataMap::GetValueTemplate() const {
	return GetAttribute(atr_ValueTemplate,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMetadataMap::ValidValueTemplate(EnumValidationLevel level) const {
		return ValidAttribute(atr_ValueTemplate,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoMetadataMap::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoMetadataMap::RequiredElements()const{
		return JDFElement::RequiredElements()+L",Expr";
	};
}; // end namespace JDF
