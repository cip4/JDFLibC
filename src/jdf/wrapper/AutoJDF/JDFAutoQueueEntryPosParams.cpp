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

 
#include "jdf/wrapper/AutoJDF/JDFAutoQueueEntryPosParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoQueueEntryPosParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoQueueEntryPosParams& JDFAutoQueueEntryPosParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoQueueEntryPosParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoQueueEntryPosParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoQueueEntryPosParams::ValidNodeNames()const{
	return L"*:,QueueEntryPosParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoQueueEntryPosParams::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",QueueEntryID";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoQueueEntryPosParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",NextQueueEntryID,PrevQueueEntryID,Position");
};

/**
 typesafe validator
*/
	vWString JDFAutoQueueEntryPosParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidNextQueueEntryID(level)) {
			vAtts.push_back(atr_NextQueueEntryID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidQueueEntryID(level)) {
			vAtts.push_back(atr_QueueEntryID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPrevQueueEntryID(level)) {
			vAtts.push_back(atr_PrevQueueEntryID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPosition(level)) {
			vAtts.push_back(atr_Position);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute NextQueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueEntryPosParams::SetNextQueueEntryID(const WString& value){
	SetAttribute(atr_NextQueueEntryID,value);
};
/**
* Get string attribute NextQueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueEntryPosParams::GetNextQueueEntryID() const {
	return GetAttribute(atr_NextQueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueEntryPosParams::ValidNextQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_NextQueueEntryID,AttributeType_shortString,false);
	};
/**
* Set attribute QueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueEntryPosParams::SetQueueEntryID(const WString& value){
	SetAttribute(atr_QueueEntryID,value);
};
/**
* Get string attribute QueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueEntryPosParams::GetQueueEntryID() const {
	return GetAttribute(atr_QueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueEntryPosParams::ValidQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_QueueEntryID,AttributeType_shortString,RequiredLevel(level));
	};
/**
* Set attribute PrevQueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueEntryPosParams::SetPrevQueueEntryID(const WString& value){
	SetAttribute(atr_PrevQueueEntryID,value);
};
/**
* Get string attribute PrevQueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueEntryPosParams::GetPrevQueueEntryID() const {
	return GetAttribute(atr_PrevQueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueEntryPosParams::ValidPrevQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_PrevQueueEntryID,AttributeType_shortString,false);
	};
/**
* Set attribute Position
*@param int value: the value to set the attribute to
*/
	 void JDFAutoQueueEntryPosParams::SetPosition(int value){
	SetAttribute(atr_Position,WString::valueOf(value));
};
/**
* Get integer attribute Position
* @return int the vaue of the attribute 
*/
	 int JDFAutoQueueEntryPosParams::GetPosition() const {
	return GetIntAttribute(atr_Position,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueEntryPosParams::ValidPosition(EnumValidationLevel level) const {
		return ValidAttribute(atr_Position,AttributeType_integer,false);
	};
}; // end namespace JDF
