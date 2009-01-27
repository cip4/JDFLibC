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

 
#include "jdf/wrapper/AutoJDF/JDFAutoIDPFinishing.h"
#include "jdf/wrapper/JDFIDPFolding.h"
#include "jdf/wrapper/JDFIDPHoleMaking.h"
#include "jdf/wrapper/JDFIDPStitching.h"
#include "jdf/wrapper/JDFIDPTrimming.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoIDPFinishing : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoIDPFinishing& JDFAutoIDPFinishing::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoIDPFinishing: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoIDPFinishing::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoIDPFinishing::ValidNodeNames()const{
	return L"*:,IDPFinishing";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoIDPFinishing::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Finishings");
};

/**
 typesafe validator
*/
	vWString JDFAutoIDPFinishing::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidFinishings(level)) {
			vAtts.push_back(atr_Finishings);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Finishings
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoIDPFinishing::SetFinishings(const JDFIntegerList& value){
	SetAttribute(atr_Finishings,value.GetString());
};
/**
* Get string attribute Finishings
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoIDPFinishing::GetFinishings() const {
	return GetAttribute(atr_Finishings,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPFinishing::ValidFinishings(EnumValidationLevel level) const {
		return ValidAttribute(atr_Finishings,AttributeType_IntegerList,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFIDPFolding JDFAutoIDPFinishing::GetIDPFolding(int iSkip)const{
	JDFIDPFolding e=GetElement(elm_IDPFolding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPFolding JDFAutoIDPFinishing::GetCreateIDPFolding(int iSkip){
	JDFIDPFolding e=GetCreateElement(elm_IDPFolding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPFolding JDFAutoIDPFinishing::AppendIDPFolding(){
	JDFIDPFolding e=AppendElement(elm_IDPFolding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPHoleMaking JDFAutoIDPFinishing::GetIDPHoleMaking(int iSkip)const{
	JDFIDPHoleMaking e=GetElement(elm_IDPHoleMaking,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPHoleMaking JDFAutoIDPFinishing::GetCreateIDPHoleMaking(int iSkip){
	JDFIDPHoleMaking e=GetCreateElement(elm_IDPHoleMaking,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPHoleMaking JDFAutoIDPFinishing::AppendIDPHoleMaking(){
	JDFIDPHoleMaking e=AppendElement(elm_IDPHoleMaking);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPStitching JDFAutoIDPFinishing::GetIDPStitching(int iSkip)const{
	JDFIDPStitching e=GetElement(elm_IDPStitching,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPStitching JDFAutoIDPFinishing::GetCreateIDPStitching(int iSkip){
	JDFIDPStitching e=GetCreateElement(elm_IDPStitching,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPStitching JDFAutoIDPFinishing::AppendIDPStitching(){
	JDFIDPStitching e=AppendElement(elm_IDPStitching);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPTrimming JDFAutoIDPFinishing::GetIDPTrimming(int iSkip)const{
	JDFIDPTrimming e=GetElement(elm_IDPTrimming,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPTrimming JDFAutoIDPFinishing::GetCreateIDPTrimming(int iSkip){
	JDFIDPTrimming e=GetCreateElement(elm_IDPTrimming,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPTrimming JDFAutoIDPFinishing::AppendIDPTrimming(){
	JDFIDPTrimming e=AppendElement(elm_IDPTrimming);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoIDPFinishing::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_IDPFolding);

		for(i=0;i<nElem;i++){
			if (!GetIDPFolding(i).IsValid(level)) {
				vElem.AppendUnique(elm_IDPFolding);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_IDPHoleMaking);

		for(i=0;i<nElem;i++){
			if (!GetIDPHoleMaking(i).IsValid(level)) {
				vElem.AppendUnique(elm_IDPHoleMaking);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_IDPStitching);

		for(i=0;i<nElem;i++){
			if (!GetIDPStitching(i).IsValid(level)) {
				vElem.AppendUnique(elm_IDPStitching);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_IDPTrimming);

		for(i=0;i<nElem;i++){
			if (!GetIDPTrimming(i).IsValid(level)) {
				vElem.AppendUnique(elm_IDPTrimming);
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
	WString JDFAutoIDPFinishing::OptionalElements()const{
		return JDFElement::OptionalElements()+L",IDPFolding,IDPHoleMaking,IDPStitching,IDPTrimming";
	};
}; // end namespace JDF
