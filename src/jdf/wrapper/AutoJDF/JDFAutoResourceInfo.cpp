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

 
#include "jdf/wrapper/AutoJDF/JDFAutoResourceInfo.h"
#include "jdf/wrapper/JDFAmountPool.h"
#include "jdf/wrapper/JDFCostCenter.h"
#include "jdf/wrapper/JDFMISDetails.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoResourceInfo : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoResourceInfo& JDFAutoResourceInfo::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoResourceInfo: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoResourceInfo::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoResourceInfo::ValidNodeNames()const{
	return L"*:,ResourceInfo";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoResourceInfo::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",ActualAmount,Amount,AvailableAmount,Level,Location,ModuleID,ModuleIndex,ProcessUsage,ProductID,ResourceID,ResourceName,Status,Unit,Usage");
};

/**
 typesafe validator
*/
	vWString JDFAutoResourceInfo::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidActualAmount(level)) {
			vAtts.push_back(atr_ActualAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAmount(level)) {
			vAtts.push_back(atr_Amount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAvailableAmount(level)) {
			vAtts.push_back(atr_AvailableAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLevel(level)) {
			vAtts.push_back(atr_Level);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLocation(level)) {
			vAtts.push_back(atr_Location);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModuleID(level)) {
			vAtts.push_back(atr_ModuleID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModuleIndex(level)) {
			vAtts.push_back(atr_ModuleIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProcessUsage(level)) {
			vAtts.push_back(atr_ProcessUsage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProductID(level)) {
			vAtts.push_back(atr_ProductID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResourceID(level)) {
			vAtts.push_back(atr_ResourceID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResourceName(level)) {
			vAtts.push_back(atr_ResourceName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStatus(level)) {
			vAtts.push_back(atr_Status);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUnit(level)) {
			vAtts.push_back(atr_Unit);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUsage(level)) {
			vAtts.push_back(atr_Usage);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ActualAmount
*@param double value: the value to set the attribute to
*/
	 void JDFAutoResourceInfo::SetActualAmount(double value){
	SetAttribute(atr_ActualAmount,WString::valueOf(value));
};
/**
* Get double attribute ActualAmount
* @return double the vaue of the attribute 
*/
	 double JDFAutoResourceInfo::GetActualAmount() const {
	return GetRealAttribute(atr_ActualAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceInfo::ValidActualAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_ActualAmount,AttributeType_double,false);
	};
/**
* Set attribute Amount
*@param double value: the value to set the attribute to
*/
	 void JDFAutoResourceInfo::SetAmount(double value){
	SetAttribute(atr_Amount,WString::valueOf(value));
};
/**
* Get double attribute Amount
* @return double the vaue of the attribute 
*/
	 double JDFAutoResourceInfo::GetAmount() const {
	return GetRealAttribute(atr_Amount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceInfo::ValidAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_Amount,AttributeType_double,false);
	};
/**
* Set attribute AvailableAmount
*@param double value: the value to set the attribute to
*/
	 void JDFAutoResourceInfo::SetAvailableAmount(double value){
	SetAttribute(atr_AvailableAmount,WString::valueOf(value));
};
/**
* Get double attribute AvailableAmount
* @return double the vaue of the attribute 
*/
	 double JDFAutoResourceInfo::GetAvailableAmount() const {
	return GetRealAttribute(atr_AvailableAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceInfo::ValidAvailableAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_AvailableAmount,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoResourceInfo::LevelString(){
		static const WString enums=WString(L"Unknown,Empty,Low,OK");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoResourceInfo::LevelString(EnumLevel value){
		return LevelString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoResourceInfo::SetLevel( EnumLevel value){
	SetEnumAttribute(atr_Level,value,LevelString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoResourceInfo::EnumLevel JDFAutoResourceInfo:: GetLevel() const {
	return (EnumLevel) GetEnumAttribute(atr_Level,LevelString(),WString::emptyStr,Level_OK);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceInfo::ValidLevel(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Level,LevelString(),false);
	};
/**
* Set attribute Location
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceInfo::SetLocation(const WString& value){
	SetAttribute(atr_Location,value);
};
/**
* Get string attribute Location
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceInfo::GetLocation() const {
	return GetAttribute(atr_Location,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceInfo::ValidLocation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Location,AttributeType_string,false);
	};
/**
* Set attribute ModuleID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceInfo::SetModuleID(const WString& value){
	SetAttribute(atr_ModuleID,value);
};
/**
* Get string attribute ModuleID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceInfo::GetModuleID() const {
	return GetAttribute(atr_ModuleID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceInfo::ValidModuleID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleID,AttributeType_string,false);
	};
/**
* Set attribute ModuleIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoResourceInfo::SetModuleIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_ModuleIndex,value.GetString());
};
/**
* Get range attribute ModuleIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoResourceInfo::GetModuleIndex() const {
	return GetAttribute(atr_ModuleIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceInfo::ValidModuleIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute ProcessUsage
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceInfo::SetProcessUsage(const WString& value){
	SetAttribute(atr_ProcessUsage,value);
};
/**
* Get string attribute ProcessUsage
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceInfo::GetProcessUsage() const {
	return GetAttribute(atr_ProcessUsage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceInfo::ValidProcessUsage(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProcessUsage,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute ProductID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceInfo::SetProductID(const WString& value){
	SetAttribute(atr_ProductID,value);
};
/**
* Get string attribute ProductID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceInfo::GetProductID() const {
	return GetAttribute(atr_ProductID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceInfo::ValidProductID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProductID,AttributeType_shortString,false);
	};
/**
* Set attribute ResourceID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceInfo::SetResourceID(const WString& value){
	SetAttribute(atr_ResourceID,value);
};
/**
* Get string attribute ResourceID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceInfo::GetResourceID() const {
	return GetAttribute(atr_ResourceID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceInfo::ValidResourceID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ResourceID,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute ResourceName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceInfo::SetResourceName(const WString& value){
	SetAttribute(atr_ResourceName,value);
};
/**
* Get string attribute ResourceName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceInfo::GetResourceName() const {
	return GetAttribute(atr_ResourceName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceInfo::ValidResourceName(EnumValidationLevel level) const {
		return ValidAttribute(atr_ResourceName,AttributeType_NMTOKEN,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoResourceInfo::SetStatus( JDFResource::EnumStatus value){
	SetEnumAttribute(atr_Status,value,JDFResource::StatusString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFResource::EnumStatus JDFAutoResourceInfo::GetStatus() const {
	return (JDFResource::EnumStatus) GetEnumAttribute(atr_Status,JDFResource::StatusString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceInfo::ValidStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Status,JDFResource::StatusString(),false);
	};
/**
* Set attribute Unit
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceInfo::SetUnit(const WString& value){
	SetAttribute(atr_Unit,value);
};
/**
* Get string attribute Unit
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceInfo::GetUnit() const {
	return GetAttribute(atr_Unit,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceInfo::ValidUnit(EnumValidationLevel level) const {
		return ValidAttribute(atr_Unit,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoResourceInfo::UsageString(){
		static const WString enums=WString(L"Unknown,Input,Output");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoResourceInfo::UsageString(EnumUsage value){
		return UsageString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoResourceInfo::SetUsage( EnumUsage value){
	SetEnumAttribute(atr_Usage,value,UsageString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoResourceInfo::EnumUsage JDFAutoResourceInfo:: GetUsage() const {
	return (EnumUsage) GetEnumAttribute(atr_Usage,UsageString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceInfo::ValidUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Usage,UsageString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFAmountPool JDFAutoResourceInfo::GetAmountPool()const{
	JDFAmountPool e=GetElement(elm_AmountPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAmountPool JDFAutoResourceInfo::GetCreateAmountPool(){
	JDFAmountPool e=GetCreateElement(elm_AmountPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAmountPool JDFAutoResourceInfo::AppendAmountPool(){
	JDFAmountPool e=AppendElementN(elm_AmountPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCostCenter JDFAutoResourceInfo::GetCostCenter()const{
	JDFCostCenter e=GetElement(elm_CostCenter);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCostCenter JDFAutoResourceInfo::GetCreateCostCenter(){
	JDFCostCenter e=GetCreateElement(elm_CostCenter);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCostCenter JDFAutoResourceInfo::AppendCostCenter(){
	JDFCostCenter e=AppendElementN(elm_CostCenter,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoResourceInfo::GetMISDetails()const{
	JDFMISDetails e=GetElement(elm_MISDetails);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoResourceInfo::GetCreateMISDetails(){
	JDFMISDetails e=GetCreateElement(elm_MISDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoResourceInfo::AppendMISDetails(){
	JDFMISDetails e=AppendElementN(elm_MISDetails,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoResourceInfo::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoResourceInfo::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoResourceInfo::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoResourceInfo::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoResourceInfo::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoResourceInfo::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoResourceInfo::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoResourceInfo::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

/**
 typesafe validator
*/
	vWString JDFAutoResourceInfo::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_AmountPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_AmountPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetAmountPool().IsValid(level)) {
				vElem.AppendUnique(elm_AmountPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_CostCenter);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_CostCenter);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetCostCenter().IsValid(level)) {
				vElem.AppendUnique(elm_CostCenter);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_MISDetails);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_MISDetails);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMISDetails().IsValid(level)) {
				vElem.AppendUnique(elm_MISDetails);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoResourceInfo::UniqueElements()const{
		return JDFElement::UniqueElements()+L",AmountPool,CostCenter,MISDetails";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoResourceInfo::OptionalElements()const{
		return JDFElement::OptionalElements()+L",AmountPool,CostCenter,MISDetails,Part";
	};
}; // end namespace JDF
