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

 
#include "jdf/wrapper/AutoJDF/JDFAutoGangElement.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFRunList.h"
#include "jdf/wrapper/JDFSeparationList.h"
#include "jdf/wrapper/JDFSeparationList.h"
#include "jdf/wrapper/JDFStrippingParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoGangElement : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoGangElement& JDFAutoGangElement::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoGangElement: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoGangElement::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoGangElement::ValidNodeNames()const{
	return L"*:,GangElement";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoGangElement::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",GangElementID,OrderQuantity";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoGangElement::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",AssemblyIDs,CollapseBleeds,Dimension,DueDate,FillPriority,GrainDirection,GroupCode,JobID,MaxQuantity,MinQuantity,NPage,NumColors,NumberUp,OneSheet,PageDimension,Priority,ProductID");
};

/**
 typesafe validator
*/
	vWString JDFAutoGangElement::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAssemblyIDs(level)) {
			vAtts.push_back(atr_AssemblyIDs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCollapseBleeds(level)) {
			vAtts.push_back(atr_CollapseBleeds);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDimension(level)) {
			vAtts.push_back(atr_Dimension);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDueDate(level)) {
			vAtts.push_back(atr_DueDate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFillPriority(level)) {
			vAtts.push_back(atr_FillPriority);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGangElementID(level)) {
			vAtts.push_back(atr_GangElementID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGrainDirection(level)) {
			vAtts.push_back(atr_GrainDirection);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGroupCode(level)) {
			vAtts.push_back(atr_GroupCode);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJobID(level)) {
			vAtts.push_back(atr_JobID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxQuantity(level)) {
			vAtts.push_back(atr_MaxQuantity);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMinQuantity(level)) {
			vAtts.push_back(atr_MinQuantity);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNPage(level)) {
			vAtts.push_back(atr_NPage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNumColors(level)) {
			vAtts.push_back(atr_NumColors);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNumberUp(level)) {
			vAtts.push_back(atr_NumberUp);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOneSheet(level)) {
			vAtts.push_back(atr_OneSheet);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrderQuantity(level)) {
			vAtts.push_back(atr_OrderQuantity);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageDimension(level)) {
			vAtts.push_back(atr_PageDimension);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPriority(level)) {
			vAtts.push_back(atr_Priority);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProductID(level)) {
			vAtts.push_back(atr_ProductID);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AssemblyIDs
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetAssemblyIDs(const vWString& value){
	SetAttribute(atr_AssemblyIDs,value);
};
/**
* Get string attribute AssemblyIDs
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoGangElement::GetAssemblyIDs() const {
	return GetAttribute(atr_AssemblyIDs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidAssemblyIDs(EnumValidationLevel level) const {
		return ValidAttribute(atr_AssemblyIDs,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute CollapseBleeds
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetCollapseBleeds(bool value){
	SetAttribute(atr_CollapseBleeds,WString::valueOf(value));
};
/**
* Get bool attribute CollapseBleeds
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoGangElement::GetCollapseBleeds() const {return GetBoolAttribute(atr_CollapseBleeds,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidCollapseBleeds(EnumValidationLevel level) const {
		return ValidAttribute(atr_CollapseBleeds,AttributeType_boolean,false);
	};
/**
* Set attribute Dimension
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetDimension(const JDFXYPair& value){
	SetAttribute(atr_Dimension,value);
};
/**
* Get string attribute Dimension
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoGangElement::GetDimension() const {
	return GetAttribute(atr_Dimension,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidDimension(EnumValidationLevel level) const {
		return ValidAttribute(atr_Dimension,AttributeType_XYPair,false);
	};
/**
* Set attribute DueDate
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetDueDate(JDFDate value){
	SetAttribute(atr_DueDate,value.DateTimeISO());
};
/**
* Get string attribute DueDate
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoGangElement::GetDueDate() const {
	return GetAttribute(atr_DueDate,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidDueDate(EnumValidationLevel level) const {
		return ValidAttribute(atr_DueDate,AttributeType_dateTime,false);
	};
/**
* Set attribute FillPriority
*@param int value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetFillPriority(int value){
	SetAttribute(atr_FillPriority,WString::valueOf(value));
};
/**
* Get integer attribute FillPriority
* @return int the vaue of the attribute 
*/
	 int JDFAutoGangElement::GetFillPriority() const {
	return GetIntAttribute(atr_FillPriority,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidFillPriority(EnumValidationLevel level) const {
		return ValidAttribute(atr_FillPriority,AttributeType_integer,false);
	};
/**
* Set attribute GangElementID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetGangElementID(const WString& value){
	SetAttribute(atr_GangElementID,value);
};
/**
* Get string attribute GangElementID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoGangElement::GetGangElementID() const {
	return GetAttribute(atr_GangElementID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidGangElementID(EnumValidationLevel level) const {
		return ValidAttribute(atr_GangElementID,AttributeType_ID,RequiredLevel(level));
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoGangElement::GrainDirectionString(){
		static const WString enums=WString(L"Unknown,Any,ShortEdge,LongEdge,SameDirection,XDirection,YDirection");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoGangElement::GrainDirectionString(EnumGrainDirection value){
		return GrainDirectionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoGangElement::SetGrainDirection( EnumGrainDirection value){
	SetEnumAttribute(atr_GrainDirection,value,GrainDirectionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoGangElement::EnumGrainDirection JDFAutoGangElement:: GetGrainDirection() const {
	return (EnumGrainDirection) GetEnumAttribute(atr_GrainDirection,GrainDirectionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidGrainDirection(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_GrainDirection,GrainDirectionString(),false);
	};
/**
* Set attribute GroupCode
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetGroupCode(const WString& value){
	SetAttribute(atr_GroupCode,value);
};
/**
* Get string attribute GroupCode
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoGangElement::GetGroupCode() const {
	return GetAttribute(atr_GroupCode,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidGroupCode(EnumValidationLevel level) const {
		return ValidAttribute(atr_GroupCode,AttributeType_string,false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoGangElement::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_string,false);
	};
/**
* Set attribute MaxQuantity
*@param int value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetMaxQuantity(int value){
	SetAttribute(atr_MaxQuantity,WString::valueOf(value));
};
/**
* Get integer attribute MaxQuantity
* @return int the vaue of the attribute 
*/
	 int JDFAutoGangElement::GetMaxQuantity() const {
	return GetIntAttribute(atr_MaxQuantity,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidMaxQuantity(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxQuantity,AttributeType_integer,false);
	};
/**
* Set attribute MinQuantity
*@param int value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetMinQuantity(int value){
	SetAttribute(atr_MinQuantity,WString::valueOf(value));
};
/**
* Get integer attribute MinQuantity
* @return int the vaue of the attribute 
*/
	 int JDFAutoGangElement::GetMinQuantity() const {
	return GetIntAttribute(atr_MinQuantity,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidMinQuantity(EnumValidationLevel level) const {
		return ValidAttribute(atr_MinQuantity,AttributeType_integer,false);
	};
/**
* Set attribute NPage
*@param int value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetNPage(int value){
	SetAttribute(atr_NPage,WString::valueOf(value));
};
/**
* Get integer attribute NPage
* @return int the vaue of the attribute 
*/
	 int JDFAutoGangElement::GetNPage() const {
	return GetIntAttribute(atr_NPage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidNPage(EnumValidationLevel level) const {
		return ValidAttribute(atr_NPage,AttributeType_integer,false);
	};
/**
* Set attribute NumColors
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetNumColors(const JDFXYPair& value){
	SetAttribute(atr_NumColors,value);
};
/**
* Get string attribute NumColors
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoGangElement::GetNumColors() const {
	return GetAttribute(atr_NumColors,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidNumColors(EnumValidationLevel level) const {
		return ValidAttribute(atr_NumColors,AttributeType_XYPair,false);
	};
/**
* Set attribute NumberUp
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetNumberUp(const JDFXYPair& value){
	SetAttribute(atr_NumberUp,value);
};
/**
* Get string attribute NumberUp
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoGangElement::GetNumberUp() const {
	return GetAttribute(atr_NumberUp,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidNumberUp(EnumValidationLevel level) const {
		return ValidAttribute(atr_NumberUp,AttributeType_XYPair,false);
	};
/**
* Set attribute OneSheet
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetOneSheet(const WString& value){
	SetAttribute(atr_OneSheet,value);
};
/**
* Get string attribute OneSheet
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoGangElement::GetOneSheet() const {
	return GetAttribute(atr_OneSheet,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidOneSheet(EnumValidationLevel level) const {
		return ValidAttribute(atr_OneSheet,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute OrderQuantity
*@param int value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetOrderQuantity(int value){
	SetAttribute(atr_OrderQuantity,WString::valueOf(value));
};
/**
* Get integer attribute OrderQuantity
* @return int the vaue of the attribute 
*/
	 int JDFAutoGangElement::GetOrderQuantity() const {
	return GetIntAttribute(atr_OrderQuantity,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidOrderQuantity(EnumValidationLevel level) const {
		return ValidAttribute(atr_OrderQuantity,AttributeType_integer,RequiredLevel(level));
	};
/**
* Set attribute PageDimension
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetPageDimension(const JDFXYPair& value){
	SetAttribute(atr_PageDimension,value);
};
/**
* Get string attribute PageDimension
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoGangElement::GetPageDimension() const {
	return GetAttribute(atr_PageDimension,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidPageDimension(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageDimension,AttributeType_XYPair,false);
	};
/**
* Set attribute Priority
*@param int value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetPriority(int value){
	SetAttribute(atr_Priority,WString::valueOf(value));
};
/**
* Get integer attribute Priority
* @return int the vaue of the attribute 
*/
	 int JDFAutoGangElement::GetPriority() const {
	return GetIntAttribute(atr_Priority,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidPriority(EnumValidationLevel level) const {
		return ValidAttribute(atr_Priority,AttributeType_integer,false);
	};
/**
* Set attribute ProductID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoGangElement::SetProductID(const WString& value){
	SetAttribute(atr_ProductID,value);
};
/**
* Get string attribute ProductID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoGangElement::GetProductID() const {
	return GetAttribute(atr_ProductID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGangElement::ValidProductID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProductID,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFMedia JDFAutoGangElement::GetMedia(int iSkip)const{
	JDFMedia e=GetElement(elm_Media,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoGangElement::GetCreateMedia(int iSkip){
	JDFMedia e=GetCreateElement(elm_Media,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoGangElement::AppendMedia(){
	JDFMedia e=AppendElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoGangElement::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFRunList JDFAutoGangElement::GetRunList(int iSkip)const{
	JDFRunList e=GetElement(elm_RunList,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRunList JDFAutoGangElement::GetCreateRunList(int iSkip){
	JDFRunList e=GetCreateElement(elm_RunList,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRunList JDFAutoGangElement::AppendRunList(){
	JDFRunList e=AppendElement(elm_RunList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoGangElement::RefRunList(JDFRunList& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoGangElement::GetSeparationListBack(int iSkip)const{
	JDFSeparationList e=GetElement(elm_SeparationListBack,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoGangElement::GetCreateSeparationListBack(int iSkip){
	JDFSeparationList e=GetCreateElement(elm_SeparationListBack,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoGangElement::AppendSeparationListBack(){
	JDFSeparationList e=AppendElement(elm_SeparationListBack);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoGangElement::GetSeparationListFront(int iSkip)const{
	JDFSeparationList e=GetElement(elm_SeparationListFront,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoGangElement::GetCreateSeparationListFront(int iSkip){
	JDFSeparationList e=GetCreateElement(elm_SeparationListFront,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoGangElement::AppendSeparationListFront(){
	JDFSeparationList e=AppendElement(elm_SeparationListFront);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStrippingParams JDFAutoGangElement::GetStrippingParams(int iSkip)const{
	JDFStrippingParams e=GetElement(elm_StrippingParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStrippingParams JDFAutoGangElement::GetCreateStrippingParams(int iSkip){
	JDFStrippingParams e=GetCreateElement(elm_StrippingParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStrippingParams JDFAutoGangElement::AppendStrippingParams(){
	JDFStrippingParams e=AppendElement(elm_StrippingParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoGangElement::RefStrippingParams(JDFStrippingParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoGangElement::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Media);

		for(i=0;i<nElem;i++){
			if (!GetMedia(i).IsValid(level)) {
				vElem.AppendUnique(elm_Media);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_RunList);

		for(i=0;i<nElem;i++){
			if (!GetRunList(i).IsValid(level)) {
				vElem.AppendUnique(elm_RunList);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SeparationListBack);

		for(i=0;i<nElem;i++){
			if (!GetSeparationListBack(i).IsValid(level)) {
				vElem.AppendUnique(elm_SeparationListBack);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SeparationListFront);

		for(i=0;i<nElem;i++){
			if (!GetSeparationListFront(i).IsValid(level)) {
				vElem.AppendUnique(elm_SeparationListFront);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_StrippingParams);

		for(i=0;i<nElem;i++){
			if (!GetStrippingParams(i).IsValid(level)) {
				vElem.AppendUnique(elm_StrippingParams);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoGangElement::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Media,RunList,SeparationListBack,SeparationListFront,StrippingParams";
	};
}; // end namespace JDF
