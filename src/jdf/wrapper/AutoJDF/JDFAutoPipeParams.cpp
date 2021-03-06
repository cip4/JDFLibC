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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPipeParams.h"
#include "jdf/wrapper/JDFAmountPool.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPipeParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPipeParams& JDFAutoPipeParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPipeParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPipeParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPipeParams::ValidNodeNames()const{
	return L"*:,PipeParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoPipeParams::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",PipeID";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPipeParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",JobID,JobPartID,ProjectID,Status,UpdatedStatus");
};

/**
 typesafe validator
*/
	vWString JDFAutoPipeParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidJobID(level)) {
			vAtts.push_back(atr_JobID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJobPartID(level)) {
			vAtts.push_back(atr_JobPartID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPipeID(level)) {
			vAtts.push_back(atr_PipeID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProjectID(level)) {
			vAtts.push_back(atr_ProjectID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStatus(level)) {
			vAtts.push_back(atr_Status);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUpdatedStatus(level)) {
			vAtts.push_back(atr_UpdatedStatus);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPipeParams::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPipeParams::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPipeParams::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,false);
	};
/**
* Set attribute JobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPipeParams::SetJobPartID(const WString& value){
	SetAttribute(atr_JobPartID,value);
};
/**
* Get string attribute JobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPipeParams::GetJobPartID() const {
	return GetAttribute(atr_JobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPipeParams::ValidJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobPartID,AttributeType_shortString,false);
	};
/**
* Set attribute PipeID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPipeParams::SetPipeID(const WString& value){
	SetAttribute(atr_PipeID,value);
};
/**
* Get string attribute PipeID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPipeParams::GetPipeID() const {
	return GetAttribute(atr_PipeID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPipeParams::ValidPipeID(EnumValidationLevel level) const {
		return ValidAttribute(atr_PipeID,AttributeType_shortString,RequiredLevel(level));
	};
/**
* Set attribute ProjectID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPipeParams::SetProjectID(const WString& value){
	SetAttribute(atr_ProjectID,value);
};
/**
* Get string attribute ProjectID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPipeParams::GetProjectID() const {
	return GetAttribute(atr_ProjectID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPipeParams::ValidProjectID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProjectID,AttributeType_shortString,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoPipeParams::SetStatus( EnumStatus value){
	SetEnumAttribute(atr_Status,value,StatusString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPipeParams::EnumStatus JDFAutoPipeParams:: GetStatus() const {
	return (EnumStatus) GetEnumAttribute(atr_Status,StatusString(),WString::emptyStr,Status_InProgress);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPipeParams::ValidStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Status,StatusString(),false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoPipeParams::SetUpdatedStatus( JDFResource::EnumStatus value){
	SetEnumAttribute(atr_UpdatedStatus,value,JDFResource::StatusString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFResource::EnumStatus JDFAutoPipeParams::GetUpdatedStatus() const {
	return (JDFResource::EnumStatus) GetEnumAttribute(atr_UpdatedStatus,JDFResource::StatusString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPipeParams::ValidUpdatedStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_UpdatedStatus,JDFResource::StatusString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFAmountPool JDFAutoPipeParams::GetAmountPool()const{
	JDFAmountPool e=GetElement(elm_AmountPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAmountPool JDFAutoPipeParams::GetCreateAmountPool(){
	JDFAmountPool e=GetCreateElement(elm_AmountPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAmountPool JDFAutoPipeParams::AppendAmountPool(){
	JDFAmountPool e=AppendElementN(elm_AmountPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPipeParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_AmountPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_AmountPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetAmountPool().IsValid(level)) {
				vElem.AppendUnique(elm_AmountPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoPipeParams::UniqueElements()const{
		return JDFElement::UniqueElements()+L",AmountPool";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoPipeParams::OptionalElements()const{
		return JDFElement::OptionalElements()+L",AmountPool";
	};
}; // end namespace JDF
