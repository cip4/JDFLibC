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

 
#include "jdf/wrapper/AutoJDF/JDFAutoInkZoneCalculationParams.h"
#include "jdf/wrapper/JDFDevice.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoInkZoneCalculationParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoInkZoneCalculationParams& JDFAutoInkZoneCalculationParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoInkZoneCalculationParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoInkZoneCalculationParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoInkZoneCalculationParams::ValidNodeNames()const{
	return L"*:,InkZoneCalculationParams";
};

bool JDFAutoInkZoneCalculationParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoInkZoneCalculationParams::init(){
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
	WString JDFAutoInkZoneCalculationParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",FountainPositions,PrintableArea,ZoneWidth,Zones,ZonesY,ZoneHeight");
};

/**
 typesafe validator
*/
	vWString JDFAutoInkZoneCalculationParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidFountainPositions(level)) {
			vAtts.push_back(atr_FountainPositions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPrintableArea(level)) {
			vAtts.push_back(atr_PrintableArea);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidZoneWidth(level)) {
			vAtts.push_back(atr_ZoneWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidZones(level)) {
			vAtts.push_back(atr_Zones);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidZonesY(level)) {
			vAtts.push_back(atr_ZonesY);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidZoneHeight(level)) {
			vAtts.push_back(atr_ZoneHeight);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute FountainPositions
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoInkZoneCalculationParams::SetFountainPositions(const JDFNumberList& value){
	SetAttribute(atr_FountainPositions,value.GetString());
};
/**
* Get string attribute FountainPositions
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoInkZoneCalculationParams::GetFountainPositions() const {
	return GetAttribute(atr_FountainPositions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInkZoneCalculationParams::ValidFountainPositions(EnumValidationLevel level) const {
		return ValidAttribute(atr_FountainPositions,AttributeType_NumberList,false);
	};
/**
* Set attribute PrintableArea
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoInkZoneCalculationParams::SetPrintableArea(const JDFRectangle& value){
	SetAttribute(atr_PrintableArea,value);
};
/**
* Get string attribute PrintableArea
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoInkZoneCalculationParams::GetPrintableArea() const {
	return GetAttribute(atr_PrintableArea,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInkZoneCalculationParams::ValidPrintableArea(EnumValidationLevel level) const {
		return ValidAttribute(atr_PrintableArea,AttributeType_rectangle,false);
	};
/**
* Set attribute ZoneWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoInkZoneCalculationParams::SetZoneWidth(double value){
	SetAttribute(atr_ZoneWidth,WString::valueOf(value));
};
/**
* Get double attribute ZoneWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoInkZoneCalculationParams::GetZoneWidth() const {
	return GetRealAttribute(atr_ZoneWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInkZoneCalculationParams::ValidZoneWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_ZoneWidth,AttributeType_double,false);
	};
/**
* Set attribute Zones
*@param int value: the value to set the attribute to
*/
	 void JDFAutoInkZoneCalculationParams::SetZones(int value){
	SetAttribute(atr_Zones,WString::valueOf(value));
};
/**
* Get integer attribute Zones
* @return int the vaue of the attribute 
*/
	 int JDFAutoInkZoneCalculationParams::GetZones() const {
	return GetIntAttribute(atr_Zones,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInkZoneCalculationParams::ValidZones(EnumValidationLevel level) const {
		return ValidAttribute(atr_Zones,AttributeType_integer,false);
	};
/**
* Set attribute ZonesY
*@param int value: the value to set the attribute to
*/
	 void JDFAutoInkZoneCalculationParams::SetZonesY(int value){
	SetAttribute(atr_ZonesY,WString::valueOf(value));
};
/**
* Get integer attribute ZonesY
* @return int the vaue of the attribute 
*/
	 int JDFAutoInkZoneCalculationParams::GetZonesY() const {
	return GetIntAttribute(atr_ZonesY,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInkZoneCalculationParams::ValidZonesY(EnumValidationLevel level) const {
		return ValidAttribute(atr_ZonesY,AttributeType_integer,false);
	};
/**
* Set attribute ZoneHeight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoInkZoneCalculationParams::SetZoneHeight(double value){
	SetAttribute(atr_ZoneHeight,WString::valueOf(value));
};
/**
* Get double attribute ZoneHeight
* @return double the vaue of the attribute 
*/
	 double JDFAutoInkZoneCalculationParams::GetZoneHeight() const {
	return GetRealAttribute(atr_ZoneHeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInkZoneCalculationParams::ValidZoneHeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_ZoneHeight,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFDevice JDFAutoInkZoneCalculationParams::GetDevice()const{
	JDFDevice e=GetElement(elm_Device);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoInkZoneCalculationParams::GetCreateDevice(){
	JDFDevice e=GetCreateElement(elm_Device);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoInkZoneCalculationParams::AppendDevice(){
	JDFDevice e=AppendElementN(elm_Device,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoInkZoneCalculationParams::RefDevice(JDFDevice& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoInkZoneCalculationParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Device);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Device);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDevice().IsValid(level)) {
				vElem.AppendUnique(elm_Device);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoInkZoneCalculationParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",Device";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoInkZoneCalculationParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Device";
	};
}; // end namespace JDF
