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

 
#include "jdf/wrapper/AutoJDF/JDFAutoTabDimensions.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoTabDimensions : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoTabDimensions& JDFAutoTabDimensions::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoTabDimensions: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoTabDimensions::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoTabDimensions::ValidNodeNames()const{
	return L"*:,TabDimensions";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoTabDimensions::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",TabEdge,TabExtensionDistance,TabOffset,TabsPerBank,TabSetCollationOrder,TabWidth");
};

/**
 typesafe validator
*/
	vWString JDFAutoTabDimensions::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidTabEdge(level)) {
			vAtts.push_back(atr_TabEdge);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTabExtensionDistance(level)) {
			vAtts.push_back(atr_TabExtensionDistance);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTabOffset(level)) {
			vAtts.push_back(atr_TabOffset);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTabsPerBank(level)) {
			vAtts.push_back(atr_TabsPerBank);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTabSetCollationOrder(level)) {
			vAtts.push_back(atr_TabSetCollationOrder);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTabWidth(level)) {
			vAtts.push_back(atr_TabWidth);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoTabDimensions::TabEdgeString(){
		static const WString enums=WString(L"Unknown,Left,Rigth,Top,Bottom");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoTabDimensions::TabEdgeString(EnumTabEdge value){
		return TabEdgeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoTabDimensions::SetTabEdge( EnumTabEdge value){
	SetEnumAttribute(atr_TabEdge,value,TabEdgeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoTabDimensions::EnumTabEdge JDFAutoTabDimensions:: GetTabEdge() const {
	return (EnumTabEdge) GetEnumAttribute(atr_TabEdge,TabEdgeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTabDimensions::ValidTabEdge(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_TabEdge,TabEdgeString(),false);
	};
/**
* Set attribute TabExtensionDistance
*@param double value: the value to set the attribute to
*/
	 void JDFAutoTabDimensions::SetTabExtensionDistance(double value){
	SetAttribute(atr_TabExtensionDistance,WString::valueOf(value));
};
/**
* Get double attribute TabExtensionDistance
* @return double the vaue of the attribute 
*/
	 double JDFAutoTabDimensions::GetTabExtensionDistance() const {
	return GetRealAttribute(atr_TabExtensionDistance,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTabDimensions::ValidTabExtensionDistance(EnumValidationLevel level) const {
		return ValidAttribute(atr_TabExtensionDistance,AttributeType_double,false);
	};
/**
* Set attribute TabOffset
*@param double value: the value to set the attribute to
*/
	 void JDFAutoTabDimensions::SetTabOffset(double value){
	SetAttribute(atr_TabOffset,WString::valueOf(value));
};
/**
* Get double attribute TabOffset
* @return double the vaue of the attribute 
*/
	 double JDFAutoTabDimensions::GetTabOffset() const {
	return GetRealAttribute(atr_TabOffset,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTabDimensions::ValidTabOffset(EnumValidationLevel level) const {
		return ValidAttribute(atr_TabOffset,AttributeType_double,false);
	};
/**
* Set attribute TabsPerBank
*@param int value: the value to set the attribute to
*/
	 void JDFAutoTabDimensions::SetTabsPerBank(int value){
	SetAttribute(atr_TabsPerBank,WString::valueOf(value));
};
/**
* Get integer attribute TabsPerBank
* @return int the vaue of the attribute 
*/
	 int JDFAutoTabDimensions::GetTabsPerBank() const {
	return GetIntAttribute(atr_TabsPerBank,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTabDimensions::ValidTabsPerBank(EnumValidationLevel level) const {
		return ValidAttribute(atr_TabsPerBank,AttributeType_integer,false);
	};
/**
* Set attribute TabSetCollationOrder
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoTabDimensions::SetTabSetCollationOrder(const WString& value){
	SetAttribute(atr_TabSetCollationOrder,value);
};
/**
* Get string attribute TabSetCollationOrder
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoTabDimensions::GetTabSetCollationOrder() const {
	return GetAttribute(atr_TabSetCollationOrder,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTabDimensions::ValidTabSetCollationOrder(EnumValidationLevel level) const {
		return ValidAttribute(atr_TabSetCollationOrder,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute TabWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoTabDimensions::SetTabWidth(double value){
	SetAttribute(atr_TabWidth,WString::valueOf(value));
};
/**
* Get double attribute TabWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoTabDimensions::GetTabWidth() const {
	return GetRealAttribute(atr_TabWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTabDimensions::ValidTabWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_TabWidth,AttributeType_double,false);
	};
}; // end namespace JDF
