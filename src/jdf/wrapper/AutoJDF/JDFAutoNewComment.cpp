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

 
#include "jdf/wrapper/AutoJDF/JDFAutoNewComment.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoNewComment : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoNewComment& JDFAutoNewComment::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoNewComment: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoNewComment::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoNewComment::ValidNodeNames()const{
	return L"*:,NewComment";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoNewComment::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",Action,refID";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoNewComment::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",CommentID");
};

/**
 typesafe validator
*/
	vWString JDFAutoNewComment::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAction(level)) {
			vAtts.push_back(atr_Action);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCommentID(level)) {
			vAtts.push_back(atr_CommentID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidrefID(level)) {
			vAtts.push_back(atr_refID);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoNewComment::ActionString(){
		static const WString enums=WString(L"Unknown,Add,Concat,Replace,Remove");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoNewComment::ActionString(EnumAction value){
		return ActionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoNewComment::SetAction( EnumAction value){
	SetEnumAttribute(atr_Action,value,ActionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoNewComment::EnumAction JDFAutoNewComment:: GetAction() const {
	return (EnumAction) GetEnumAttribute(atr_Action,ActionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNewComment::ValidAction(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Action,ActionString(),RequiredLevel(level));
	};
/**
* Set attribute CommentID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNewComment::SetCommentID(const WString& value){
	SetAttribute(atr_CommentID,value);
};
/**
* Get string attribute CommentID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNewComment::GetCommentID() const {
	return GetAttribute(atr_CommentID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNewComment::ValidCommentID(EnumValidationLevel level) const {
		return ValidAttribute(atr_CommentID,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute refID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNewComment::SetrefID(const WString& value){
	SetAttribute(atr_refID,value);
};
/**
* Get string attribute refID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNewComment::GetrefID() const {
	return GetAttribute(atr_refID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNewComment::ValidrefID(EnumValidationLevel level) const {
		return ValidAttribute(atr_refID,AttributeType_NMTOKEN,RequiredLevel(level));
	};
}; // end namespace JDF
