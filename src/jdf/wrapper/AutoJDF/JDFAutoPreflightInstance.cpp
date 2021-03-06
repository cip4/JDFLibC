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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPreflightInstance.h"
#include "jdf/wrapper/JDFPreflightInstanceDetail.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPreflightInstance : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPreflightInstance& JDFAutoPreflightInstance::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPreflightInstance: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPreflightInstance::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPreflightInstance::ValidNodeNames()const{
	return L"*:,PreflightInstance";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPreflightInstance::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Identifier,PageRefs");
};

/**
 typesafe validator
*/
	vWString JDFAutoPreflightInstance::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidIdentifier(level)) {
			vAtts.push_back(atr_Identifier);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageRefs(level)) {
			vAtts.push_back(atr_PageRefs);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Identifier
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreflightInstance::SetIdentifier(const WString& value){
	SetAttribute(atr_Identifier,value);
};
/**
* Get string attribute Identifier
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreflightInstance::GetIdentifier() const {
	return GetAttribute(atr_Identifier,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreflightInstance::ValidIdentifier(EnumValidationLevel level) const {
		return ValidAttribute(atr_Identifier,AttributeType_string,false);
	};
/**
* Set attribute PageRefs
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPreflightInstance::SetPageRefs(const JDFIntegerRangeList& value){
	SetAttribute(atr_PageRefs,value.GetString());
};
/**
* Get range attribute PageRefs
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPreflightInstance::GetPageRefs() const {
	return GetAttribute(atr_PageRefs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreflightInstance::ValidPageRefs(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageRefs,AttributeType_IntegerRangeList,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPreflightInstanceDetail JDFAutoPreflightInstance::GetPreflightInstanceDetail(int iSkip)const{
	JDFPreflightInstanceDetail e=GetElement(elm_PreflightInstanceDetail,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightInstanceDetail JDFAutoPreflightInstance::GetCreatePreflightInstanceDetail(int iSkip){
	JDFPreflightInstanceDetail e=GetCreateElement(elm_PreflightInstanceDetail,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightInstanceDetail JDFAutoPreflightInstance::AppendPreflightInstanceDetail(){
	JDFPreflightInstanceDetail e=AppendElement(elm_PreflightInstanceDetail);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPreflightInstance::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_PreflightInstanceDetail);

		for(i=0;i<nElem;i++){
			if (!GetPreflightInstanceDetail(i).IsValid(level)) {
				vElem.AppendUnique(elm_PreflightInstanceDetail);
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
	WString JDFAutoPreflightInstance::OptionalElements()const{
		return JDFElement::OptionalElements()+L",PreflightInstanceDetail";
	};
}; // end namespace JDF
