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

 
#include "jdf/wrapper/AutoJDF/JDFAutoTrigger.h"
#include "jdf/wrapper/JDFChangedAttribute.h"
#include "jdf/wrapper/JDFAdded.h"
#include "jdf/wrapper/JDFChangedPath.h"
#include "jdf/wrapper/JDFRemoved.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoTrigger : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoTrigger& JDFAutoTrigger::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoTrigger: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoTrigger::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoTrigger::ValidNodeNames()const{
	return L"*:,Trigger";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoTrigger::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",RepeatStep,RepeatTime");
};

/**
 typesafe validator
*/
	vWString JDFAutoTrigger::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidRepeatStep(level)) {
			vAtts.push_back(atr_RepeatStep);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRepeatTime(level)) {
			vAtts.push_back(atr_RepeatTime);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute RepeatStep
*@param int value: the value to set the attribute to
*/
	 void JDFAutoTrigger::SetRepeatStep(int value){
	SetAttribute(atr_RepeatStep,WString::valueOf(value));
};
/**
* Get integer attribute RepeatStep
* @return int the vaue of the attribute 
*/
	 int JDFAutoTrigger::GetRepeatStep() const {
	return GetIntAttribute(atr_RepeatStep,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrigger::ValidRepeatStep(EnumValidationLevel level) const {
		return ValidAttribute(atr_RepeatStep,AttributeType_integer,false);
	};
/**
* Set attribute RepeatTime
*@param double value: the value to set the attribute to
*/
	 void JDFAutoTrigger::SetRepeatTime(double value){
	SetAttribute(atr_RepeatTime,WString::valueOf(value));
};
/**
* Get double attribute RepeatTime
* @return double the vaue of the attribute 
*/
	 double JDFAutoTrigger::GetRepeatTime() const {
	return GetRealAttribute(atr_RepeatTime,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrigger::ValidRepeatTime(EnumValidationLevel level) const {
		return ValidAttribute(atr_RepeatTime,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFChangedAttribute JDFAutoTrigger::GetChangedAttribute(int iSkip)const{
	JDFChangedAttribute e=GetElement(elm_ChangedAttribute,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFChangedAttribute JDFAutoTrigger::GetCreateChangedAttribute(int iSkip){
	JDFChangedAttribute e=GetCreateElement(elm_ChangedAttribute,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFChangedAttribute JDFAutoTrigger::AppendChangedAttribute(){
	JDFChangedAttribute e=AppendElement(elm_ChangedAttribute);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAdded JDFAutoTrigger::GetAdded(int iSkip)const{
	JDFAdded e=GetElement(elm_Added,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAdded JDFAutoTrigger::GetCreateAdded(int iSkip){
	JDFAdded e=GetCreateElement(elm_Added,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAdded JDFAutoTrigger::AppendAdded(){
	JDFAdded e=AppendElement(elm_Added);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFChangedPath JDFAutoTrigger::GetChangedPath(int iSkip)const{
	JDFChangedPath e=GetElement(elm_ChangedPath,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFChangedPath JDFAutoTrigger::GetCreateChangedPath(int iSkip){
	JDFChangedPath e=GetCreateElement(elm_ChangedPath,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFChangedPath JDFAutoTrigger::AppendChangedPath(){
	JDFChangedPath e=AppendElement(elm_ChangedPath);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRemoved JDFAutoTrigger::GetRemoved(int iSkip)const{
	JDFRemoved e=GetElement(elm_Removed,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRemoved JDFAutoTrigger::GetCreateRemoved(int iSkip){
	JDFRemoved e=GetCreateElement(elm_Removed,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRemoved JDFAutoTrigger::AppendRemoved(){
	JDFRemoved e=AppendElement(elm_Removed);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoTrigger::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ChangedAttribute);

		for(i=0;i<nElem;i++){
			if (!GetChangedAttribute(i).IsValid(level)) {
				vElem.AppendUnique(elm_ChangedAttribute);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Added);

		for(i=0;i<nElem;i++){
			if (!GetAdded(i).IsValid(level)) {
				vElem.AppendUnique(elm_Added);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ChangedPath);

		for(i=0;i<nElem;i++){
			if (!GetChangedPath(i).IsValid(level)) {
				vElem.AppendUnique(elm_ChangedPath);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Removed);

		for(i=0;i<nElem;i++){
			if (!GetRemoved(i).IsValid(level)) {
				vElem.AppendUnique(elm_Removed);
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
	WString JDFAutoTrigger::OptionalElements()const{
		return JDFElement::OptionalElements()+L",ChangedAttribute,Added,ChangedPath,Removed";
	};
}; // end namespace JDF
