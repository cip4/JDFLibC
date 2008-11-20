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

 
#include "jdf/wrapper/AutoJDF/JDFAutoTool.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoTool : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoTool& JDFAutoTool::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoTool: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoTool::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoTool::ValidNodeNames()const{
	return L"*:,Tool";
};

bool JDFAutoTool::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Handling;
};

bool JDFAutoTool::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Handling);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoTool::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ToolID,ToolAmount,ToolType");
};

/**
 typesafe validator
*/
	vWString JDFAutoTool::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidToolID(level)) {
			vAtts.push_back(atr_ToolID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidToolAmount(level)) {
			vAtts.push_back(atr_ToolAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidToolType(level)) {
			vAtts.push_back(atr_ToolType);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ToolID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoTool::SetToolID(const WString& value){
	SetAttribute(atr_ToolID,value);
};
/**
* Get string attribute ToolID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoTool::GetToolID() const {
	return GetAttribute(atr_ToolID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTool::ValidToolID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ToolID,AttributeType_shortString,false);
	};
/**
* Set attribute ToolAmount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoTool::SetToolAmount(int value){
	SetAttribute(atr_ToolAmount,WString::valueOf(value));
};
/**
* Get integer attribute ToolAmount
* @return int the vaue of the attribute 
*/
	 int JDFAutoTool::GetToolAmount() const {
	return GetIntAttribute(atr_ToolAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTool::ValidToolAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_ToolAmount,AttributeType_integer,false);
	};
/**
* Set attribute ToolType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoTool::SetToolType(const WString& value){
	SetAttribute(atr_ToolType,value);
};
/**
* Get string attribute ToolType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoTool::GetToolType() const {
	return GetAttribute(atr_ToolType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTool::ValidToolType(EnumValidationLevel level) const {
		return ValidAttribute(atr_ToolType,AttributeType_NMTOKEN,false);
	};
}; // end namespace JDF
