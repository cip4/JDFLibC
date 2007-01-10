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

 
#include "jdf/wrapper/AutoJDF/JDFAutoMoveResource.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoMoveResource : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoMoveResource& JDFAutoMoveResource::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoMoveResource: "+other.GetNodeName());
	return *this;
};

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoMoveResource::ValidNodeNames()const{
	return L"*:,MoveResource";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoMoveResource::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",ResourceID,ParentJobID,ParentJobPartID";
};

/**
 typesafe validator
*/
	vWString JDFAutoMoveResource::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidResourceID(level)) {
			vAtts.push_back(atr_ResourceID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidParentJobID(level)) {
			vAtts.push_back(atr_ParentJobID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidParentJobPartID(level)) {
			vAtts.push_back(atr_ParentJobPartID);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ResourceID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMoveResource::SetResourceID(const WString& value){
	SetAttribute(atr_ResourceID,value);
};
/**
* Get string attribute ResourceID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMoveResource::GetResourceID() const {
	return GetAttribute(atr_ResourceID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMoveResource::ValidResourceID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ResourceID,AttributeType_NMTOKEN,RequiredLevel(level));
	};
/**
* Set attribute ParentJobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMoveResource::SetParentJobID(const WString& value){
	SetAttribute(atr_ParentJobID,value);
};
/**
* Get string attribute ParentJobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMoveResource::GetParentJobID() const {
	return GetAttribute(atr_ParentJobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMoveResource::ValidParentJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ParentJobID,AttributeType_string,RequiredLevel(level));
	};
/**
* Set attribute ParentJobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMoveResource::SetParentJobPartID(const WString& value){
	SetAttribute(atr_ParentJobPartID,value);
};
/**
* Get string attribute ParentJobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMoveResource::GetParentJobPartID() const {
	return GetAttribute(atr_ParentJobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMoveResource::ValidParentJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ParentJobPartID,AttributeType_string,RequiredLevel(level));
	};
}; // end namespace JDF
