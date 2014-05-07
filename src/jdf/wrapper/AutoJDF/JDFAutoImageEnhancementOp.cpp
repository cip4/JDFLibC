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

 
#include "jdf/wrapper/AutoJDF/JDFAutoImageEnhancementOp.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoImageEnhancementOp : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoImageEnhancementOp& JDFAutoImageEnhancementOp::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoImageEnhancementOp: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoImageEnhancementOp::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoImageEnhancementOp::ValidNodeNames()const{
	return L"*:,ImageEnhancementOp";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoImageEnhancementOp::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",Operation";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoImageEnhancementOp::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",ObjectTags,OperationDetails,SourceObjects");
};

/**
 typesafe validator
*/
	vWString JDFAutoImageEnhancementOp::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidObjectTags(level)) {
			vAtts.push_back(atr_ObjectTags);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOperation(level)) {
			vAtts.push_back(atr_Operation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOperationDetails(level)) {
			vAtts.push_back(atr_OperationDetails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceObjects(level)) {
			vAtts.push_back(atr_SourceObjects);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ObjectTags
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoImageEnhancementOp::SetObjectTags(const vWString& value){
	SetAttribute(atr_ObjectTags,value);
};
/**
* Get string attribute ObjectTags
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoImageEnhancementOp::GetObjectTags() const {
	return GetAttribute(atr_ObjectTags,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageEnhancementOp::ValidObjectTags(EnumValidationLevel level) const {
		return ValidAttribute(atr_ObjectTags,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute Operation
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoImageEnhancementOp::SetOperation(const WString& value){
	SetAttribute(atr_Operation,value);
};
/**
* Get string attribute Operation
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoImageEnhancementOp::GetOperation() const {
	return GetAttribute(atr_Operation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageEnhancementOp::ValidOperation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Operation,AttributeType_NMTOKEN,RequiredLevel(level));
	};
/**
* Set attribute OperationDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoImageEnhancementOp::SetOperationDetails(const WString& value){
	SetAttribute(atr_OperationDetails,value);
};
/**
* Get string attribute OperationDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoImageEnhancementOp::GetOperationDetails() const {
	return GetAttribute(atr_OperationDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageEnhancementOp::ValidOperationDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_OperationDetails,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoImageEnhancementOp::SourceObjectsString(){
		static const WString enums=WString(L"Unknown,All,ImagePhotographic,ImageScreenShot,LineArt,SmoothShades,Text");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoImageEnhancementOp::SourceObjectsString(EnumSourceObjects value){
		return SourceObjectsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoImageEnhancementOp::AddSourceObjects( EnumSourceObjects value){
	return AddEnumerationsAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoImageEnhancementOp::RemoveSourceObjects( EnumSourceObjects value){
	return RemoveEnumerationsAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoImageEnhancementOp::GetSourceObjects() const {
	return GetEnumerationsAttribute(atr_SourceObjects,SourceObjectsString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoImageEnhancementOp::SetSourceObjects( EnumSourceObjects value){
	SetEnumAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoImageEnhancementOp::SetSourceObjects( const vint& value){
	SetEnumerationsAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/**
* Typesafe attribute validation of SourceObjects
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageEnhancementOp::ValidSourceObjects(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_SourceObjects,SourceObjectsString(),false);
	};
}; // end namespace JDF
