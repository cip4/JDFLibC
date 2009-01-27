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

 
#include "jdf/wrapper/AutoJDF/JDFAutoBoxPackingParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoBoxPackingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoBoxPackingParams& JDFAutoBoxPackingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoBoxPackingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoBoxPackingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoBoxPackingParams::ValidNodeNames()const{
	return L"*:,BoxPackingParams";
};

bool JDFAutoBoxPackingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoBoxPackingParams::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoBoxPackingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ComponentsPerRow,Columns,ComponentOrientation,Copies,FillMaterial,Layers,MaxWeight,Pattern,Rows,Ties,UnderLays");
};

/**
 typesafe validator
*/
	vWString JDFAutoBoxPackingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidComponentsPerRow(level)) {
			vAtts.push_back(atr_ComponentsPerRow);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidColumns(level)) {
			vAtts.push_back(atr_Columns);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidComponentOrientation(level)) {
			vAtts.push_back(atr_ComponentOrientation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCopies(level)) {
			vAtts.push_back(atr_Copies);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFillMaterial(level)) {
			vAtts.push_back(atr_FillMaterial);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLayers(level)) {
			vAtts.push_back(atr_Layers);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxWeight(level)) {
			vAtts.push_back(atr_MaxWeight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPattern(level)) {
			vAtts.push_back(atr_Pattern);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRows(level)) {
			vAtts.push_back(atr_Rows);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTies(level)) {
			vAtts.push_back(atr_Ties);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUnderLays(level)) {
			vAtts.push_back(atr_UnderLays);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ComponentsPerRow
*@param int value: the value to set the attribute to
*/
	 void JDFAutoBoxPackingParams::SetComponentsPerRow(int value){
	SetAttribute(atr_ComponentsPerRow,WString::valueOf(value));
};
/**
* Get integer attribute ComponentsPerRow
* @return int the vaue of the attribute 
*/
	 int JDFAutoBoxPackingParams::GetComponentsPerRow() const {
	return GetIntAttribute(atr_ComponentsPerRow,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxPackingParams::ValidComponentsPerRow(EnumValidationLevel level) const {
		return ValidAttribute(atr_ComponentsPerRow,AttributeType_integer,false);
	};
/**
* Set attribute Columns
*@param int value: the value to set the attribute to
*/
	 void JDFAutoBoxPackingParams::SetColumns(int value){
	SetAttribute(atr_Columns,WString::valueOf(value));
};
/**
* Get integer attribute Columns
* @return int the vaue of the attribute 
*/
	 int JDFAutoBoxPackingParams::GetColumns() const {
	return GetIntAttribute(atr_Columns,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxPackingParams::ValidColumns(EnumValidationLevel level) const {
		return ValidAttribute(atr_Columns,AttributeType_integer,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoBoxPackingParams::SetComponentOrientation( EnumOrientation value){
	SetEnumAttribute(atr_ComponentOrientation,value,OrientationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoBoxPackingParams::EnumOrientation JDFAutoBoxPackingParams:: GetComponentOrientation() const {
	return (EnumOrientation) GetEnumAttribute(atr_ComponentOrientation,OrientationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxPackingParams::ValidComponentOrientation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ComponentOrientation,OrientationString(),false);
	};
/**
* Set attribute Copies
*@param int value: the value to set the attribute to
*/
	 void JDFAutoBoxPackingParams::SetCopies(int value){
	SetAttribute(atr_Copies,WString::valueOf(value));
};
/**
* Get integer attribute Copies
* @return int the vaue of the attribute 
*/
	 int JDFAutoBoxPackingParams::GetCopies() const {
	return GetIntAttribute(atr_Copies,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxPackingParams::ValidCopies(EnumValidationLevel level) const {
		return ValidAttribute(atr_Copies,AttributeType_integer,false);
	};
/**
* Set attribute FillMaterial
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoBoxPackingParams::SetFillMaterial(const WString& value){
	SetAttribute(atr_FillMaterial,value);
};
/**
* Get string attribute FillMaterial
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoBoxPackingParams::GetFillMaterial() const {
	return GetAttribute(atr_FillMaterial,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxPackingParams::ValidFillMaterial(EnumValidationLevel level) const {
		return ValidAttribute(atr_FillMaterial,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Layers
*@param int value: the value to set the attribute to
*/
	 void JDFAutoBoxPackingParams::SetLayers(int value){
	SetAttribute(atr_Layers,WString::valueOf(value));
};
/**
* Get integer attribute Layers
* @return int the vaue of the attribute 
*/
	 int JDFAutoBoxPackingParams::GetLayers() const {
	return GetIntAttribute(atr_Layers,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxPackingParams::ValidLayers(EnumValidationLevel level) const {
		return ValidAttribute(atr_Layers,AttributeType_integer,false);
	};
/**
* Set attribute MaxWeight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoBoxPackingParams::SetMaxWeight(double value){
	SetAttribute(atr_MaxWeight,WString::valueOf(value));
};
/**
* Get double attribute MaxWeight
* @return double the vaue of the attribute 
*/
	 double JDFAutoBoxPackingParams::GetMaxWeight() const {
	return GetRealAttribute(atr_MaxWeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxPackingParams::ValidMaxWeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxWeight,AttributeType_double,false);
	};
/**
* Set attribute Pattern
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoBoxPackingParams::SetPattern(const WString& value){
	SetAttribute(atr_Pattern,value);
};
/**
* Get string attribute Pattern
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoBoxPackingParams::GetPattern() const {
	return GetAttribute(atr_Pattern,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxPackingParams::ValidPattern(EnumValidationLevel level) const {
		return ValidAttribute(atr_Pattern,AttributeType_string,false);
	};
/**
* Set attribute Rows
*@param int value: the value to set the attribute to
*/
	 void JDFAutoBoxPackingParams::SetRows(int value){
	SetAttribute(atr_Rows,WString::valueOf(value));
};
/**
* Get integer attribute Rows
* @return int the vaue of the attribute 
*/
	 int JDFAutoBoxPackingParams::GetRows() const {
	return GetIntAttribute(atr_Rows,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxPackingParams::ValidRows(EnumValidationLevel level) const {
		return ValidAttribute(atr_Rows,AttributeType_integer,false);
	};
/**
* Set attribute Ties
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoBoxPackingParams::SetTies(const JDFIntegerList& value){
	SetAttribute(atr_Ties,value.GetString());
};
/**
* Get string attribute Ties
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoBoxPackingParams::GetTies() const {
	return GetAttribute(atr_Ties,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxPackingParams::ValidTies(EnumValidationLevel level) const {
		return ValidAttribute(atr_Ties,AttributeType_IntegerList,false);
	};
/**
* Set attribute UnderLays
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoBoxPackingParams::SetUnderLays(const JDFIntegerList& value){
	SetAttribute(atr_UnderLays,value.GetString());
};
/**
* Get string attribute UnderLays
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoBoxPackingParams::GetUnderLays() const {
	return GetAttribute(atr_UnderLays,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxPackingParams::ValidUnderLays(EnumValidationLevel level) const {
		return ValidAttribute(atr_UnderLays,AttributeType_IntegerList,false);
	};
}; // end namespace JDF
