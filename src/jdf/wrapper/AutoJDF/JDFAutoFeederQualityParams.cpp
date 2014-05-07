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

 
#include "jdf/wrapper/AutoJDF/JDFAutoFeederQualityParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoFeederQualityParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoFeederQualityParams& JDFAutoFeederQualityParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoFeederQualityParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoFeederQualityParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoFeederQualityParams::ValidNodeNames()const{
	return L"*:,FeederQualityParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoFeederQualityParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",IncorrectComponentQuality,IncorrectComponents,DoubleFeedQuality,DoubleFeeds,BadFeedQuality,BadFeeds");
};

/**
 typesafe validator
*/
	vWString JDFAutoFeederQualityParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidIncorrectComponentQuality(level)) {
			vAtts.push_back(atr_IncorrectComponentQuality);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIncorrectComponents(level)) {
			vAtts.push_back(atr_IncorrectComponents);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDoubleFeedQuality(level)) {
			vAtts.push_back(atr_DoubleFeedQuality);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDoubleFeeds(level)) {
			vAtts.push_back(atr_DoubleFeeds);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBadFeedQuality(level)) {
			vAtts.push_back(atr_BadFeedQuality);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBadFeeds(level)) {
			vAtts.push_back(atr_BadFeeds);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoFeederQualityParams::IncorrectComponentQualityString(){
		static const WString enums=WString(L"Unknown,NotActive,Check,Waste,StopNoWaste,StopWaste");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoFeederQualityParams::IncorrectComponentQualityString(EnumIncorrectComponentQuality value){
		return IncorrectComponentQualityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoFeederQualityParams::SetIncorrectComponentQuality( EnumIncorrectComponentQuality value){
	SetEnumAttribute(atr_IncorrectComponentQuality,value,IncorrectComponentQualityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoFeederQualityParams::EnumIncorrectComponentQuality JDFAutoFeederQualityParams:: GetIncorrectComponentQuality() const {
	return (EnumIncorrectComponentQuality) GetEnumAttribute(atr_IncorrectComponentQuality,IncorrectComponentQualityString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFeederQualityParams::ValidIncorrectComponentQuality(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_IncorrectComponentQuality,IncorrectComponentQualityString(),false);
	};
/**
* Set attribute IncorrectComponents
*@param int value: the value to set the attribute to
*/
	 void JDFAutoFeederQualityParams::SetIncorrectComponents(int value){
	SetAttribute(atr_IncorrectComponents,WString::valueOf(value));
};
/**
* Get integer attribute IncorrectComponents
* @return int the vaue of the attribute 
*/
	 int JDFAutoFeederQualityParams::GetIncorrectComponents() const {
	return GetIntAttribute(atr_IncorrectComponents,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFeederQualityParams::ValidIncorrectComponents(EnumValidationLevel level) const {
		return ValidAttribute(atr_IncorrectComponents,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoFeederQualityParams::DoubleFeedQualityString(){
		static const WString enums=WString(L"Unknown,NotActive,Check,Waste,StopNoWaste,StopWaste");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoFeederQualityParams::DoubleFeedQualityString(EnumDoubleFeedQuality value){
		return DoubleFeedQualityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoFeederQualityParams::SetDoubleFeedQuality( EnumDoubleFeedQuality value){
	SetEnumAttribute(atr_DoubleFeedQuality,value,DoubleFeedQualityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoFeederQualityParams::EnumDoubleFeedQuality JDFAutoFeederQualityParams:: GetDoubleFeedQuality() const {
	return (EnumDoubleFeedQuality) GetEnumAttribute(atr_DoubleFeedQuality,DoubleFeedQualityString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFeederQualityParams::ValidDoubleFeedQuality(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DoubleFeedQuality,DoubleFeedQualityString(),false);
	};
/**
* Set attribute DoubleFeeds
*@param int value: the value to set the attribute to
*/
	 void JDFAutoFeederQualityParams::SetDoubleFeeds(int value){
	SetAttribute(atr_DoubleFeeds,WString::valueOf(value));
};
/**
* Get integer attribute DoubleFeeds
* @return int the vaue of the attribute 
*/
	 int JDFAutoFeederQualityParams::GetDoubleFeeds() const {
	return GetIntAttribute(atr_DoubleFeeds,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFeederQualityParams::ValidDoubleFeeds(EnumValidationLevel level) const {
		return ValidAttribute(atr_DoubleFeeds,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoFeederQualityParams::BadFeedQualityString(){
		static const WString enums=WString(L"Unknown,NotActive,Check,Waste,StopNoWaste,StopWaste");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoFeederQualityParams::BadFeedQualityString(EnumBadFeedQuality value){
		return BadFeedQualityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoFeederQualityParams::SetBadFeedQuality( EnumBadFeedQuality value){
	SetEnumAttribute(atr_BadFeedQuality,value,BadFeedQualityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoFeederQualityParams::EnumBadFeedQuality JDFAutoFeederQualityParams:: GetBadFeedQuality() const {
	return (EnumBadFeedQuality) GetEnumAttribute(atr_BadFeedQuality,BadFeedQualityString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFeederQualityParams::ValidBadFeedQuality(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BadFeedQuality,BadFeedQualityString(),false);
	};
/**
* Set attribute BadFeeds
*@param int value: the value to set the attribute to
*/
	 void JDFAutoFeederQualityParams::SetBadFeeds(int value){
	SetAttribute(atr_BadFeeds,WString::valueOf(value));
};
/**
* Get integer attribute BadFeeds
* @return int the vaue of the attribute 
*/
	 int JDFAutoFeederQualityParams::GetBadFeeds() const {
	return GetIntAttribute(atr_BadFeeds,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFeederQualityParams::ValidBadFeeds(EnumValidationLevel level) const {
		return ValidAttribute(atr_BadFeeds,AttributeType_integer,false);
	};
}; // end namespace JDF
