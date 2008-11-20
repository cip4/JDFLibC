/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoCylinderPosition.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCylinderPosition : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoCylinderPosition& JDFAutoCylinderPosition::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoCylinderPosition: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoCylinderPosition::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoCylinderPosition::ValidNodeNames()const{
	return L"*:,CylinderPosition";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoCylinderPosition::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",PlatePosition,DeviceModuleIndex";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoCylinderPosition::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",PlateType,PlateUsage");
};

/**
 typesafe validator
*/
	vWString JDFAutoCylinderPosition::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidPlatePosition(level)) {
			vAtts.push_back(atr_PlatePosition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPlateType(level)) {
			vAtts.push_back(atr_PlateType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPlateUsage(level)) {
			vAtts.push_back(atr_PlateUsage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeviceModuleIndex(level)) {
			vAtts.push_back(atr_DeviceModuleIndex);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute PlatePosition
*@param JDFXYPairRangeList value: the value to set the attribute to
*/
	 void JDFAutoCylinderPosition::SetPlatePosition(const JDFXYPairRangeList& value){
	SetAttribute(atr_PlatePosition,value.GetString());
};
/**
* Get range attribute PlatePosition
* @return JDFXYPairRangeList the vaue of the attribute 
*/
	 JDFXYPairRangeList JDFAutoCylinderPosition::GetPlatePosition() const {
	return GetAttribute(atr_PlatePosition,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCylinderPosition::ValidPlatePosition(EnumValidationLevel level) const {
		return ValidAttribute(atr_PlatePosition,AttributeType_Any,RequiredLevel(level));
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoCylinderPosition::PlateTypeString(){
		static const WString enums=WString(L"Unknown,Content,Dummy");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoCylinderPosition::PlateTypeString(EnumPlateType value){
		return PlateTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoCylinderPosition::SetPlateType( EnumPlateType value){
	SetEnumAttribute(atr_PlateType,value,PlateTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoCylinderPosition::EnumPlateType JDFAutoCylinderPosition:: GetPlateType() const {
	return (EnumPlateType) GetEnumAttribute(atr_PlateType,PlateTypeString(),WString::emptyStr,PlateType_Content);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCylinderPosition::ValidPlateType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PlateType,PlateTypeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoCylinderPosition::PlateUsageString(){
		static const WString enums=WString(L"Unknown,Original,Reuse");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoCylinderPosition::PlateUsageString(EnumPlateUsage value){
		return PlateUsageString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoCylinderPosition::SetPlateUsage( EnumPlateUsage value){
	SetEnumAttribute(atr_PlateUsage,value,PlateUsageString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoCylinderPosition::EnumPlateUsage JDFAutoCylinderPosition:: GetPlateUsage() const {
	return (EnumPlateUsage) GetEnumAttribute(atr_PlateUsage,PlateUsageString(),WString::emptyStr,PlateUsage_Original);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCylinderPosition::ValidPlateUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PlateUsage,PlateUsageString(),false);
	};
/**
* Set attribute DeviceModuleIndex
*@param int value: the value to set the attribute to
*/
	 void JDFAutoCylinderPosition::SetDeviceModuleIndex(int value){
	SetAttribute(atr_DeviceModuleIndex,WString::valueOf(value));
};
/**
* Get integer attribute DeviceModuleIndex
* @return int the vaue of the attribute 
*/
	 int JDFAutoCylinderPosition::GetDeviceModuleIndex() const {
	return GetIntAttribute(atr_DeviceModuleIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCylinderPosition::ValidDeviceModuleIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeviceModuleIndex,AttributeType_integer,RequiredLevel(level));
	};
}; // end namespace JDF
