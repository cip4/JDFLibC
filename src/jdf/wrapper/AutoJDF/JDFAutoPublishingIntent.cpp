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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPublishingIntent.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPublishingIntent : public JDFIntentResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPublishingIntent& JDFAutoPublishingIntent::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPublishingIntent: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPublishingIntent::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPublishingIntent::ValidNodeNames()const{
	return L"*:,PublishingIntent";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoPublishingIntent::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFIntentResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFTimeSpan JDFAutoPublishingIntent::GetIssueDate()const{
	JDFTimeSpan e=GetElement(elm_IssueDate);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTimeSpan JDFAutoPublishingIntent::GetCreateIssueDate(){
	JDFTimeSpan e=GetCreateElement(elm_IssueDate);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTimeSpan JDFAutoPublishingIntent::AppendIssueDate(){
	JDFTimeSpan e=AppendElementN(elm_IssueDate,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoPublishingIntent::GetIssueName()const{
	JDFStringSpan e=GetElement(elm_IssueName);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoPublishingIntent::GetCreateIssueName(){
	JDFStringSpan e=GetCreateElement(elm_IssueName);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoPublishingIntent::AppendIssueName(){
	JDFStringSpan e=AppendElementN(elm_IssueName,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPublishingIntent::GetIssueType()const{
	JDFNameSpan e=GetElement(elm_IssueType);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPublishingIntent::GetCreateIssueType(){
	JDFNameSpan e=GetCreateElement(elm_IssueType);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPublishingIntent::AppendIssueType(){
	JDFNameSpan e=AppendElementN(elm_IssueType,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoPublishingIntent::GetCirculation()const{
	JDFIntegerSpan e=GetElement(elm_Circulation);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoPublishingIntent::GetCreateCirculation(){
	JDFIntegerSpan e=GetCreateElement(elm_Circulation);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoPublishingIntent::AppendCirculation(){
	JDFIntegerSpan e=AppendElementN(elm_Circulation,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPublishingIntent::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFIntentResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_IssueDate);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_IssueDate);
			if (++n>=nMax)
			return vElem;
		}
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_IssueDate);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetIssueDate().IsValid(level)) {
				vElem.AppendUnique(elm_IssueDate);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_IssueName);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_IssueName);
			if (++n>=nMax)
			return vElem;
		}
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_IssueName);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetIssueName().IsValid(level)) {
				vElem.AppendUnique(elm_IssueName);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_IssueType);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_IssueType);
			if (++n>=nMax)
			return vElem;
		}
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_IssueType);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetIssueType().IsValid(level)) {
				vElem.AppendUnique(elm_IssueType);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Circulation);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Circulation);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetCirculation().IsValid(level)) {
				vElem.AppendUnique(elm_Circulation);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoPublishingIntent::UniqueElements()const{
		return JDFIntentResource::UniqueElements()+L",IssueDate,IssueName,IssueType,Circulation";
	};

/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoPublishingIntent::RequiredElements()const{
		return JDFIntentResource::RequiredElements()+L",IssueDate,IssueName,IssueType";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoPublishingIntent::OptionalElements()const{
		return JDFIntentResource::OptionalElements()+L",Circulation";
	};
}; // end namespace JDF
