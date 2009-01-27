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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPerforate.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPerforate : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPerforate& JDFAutoPerforate::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPerforate: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPerforate::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPerforate::ValidNodeNames()const{
	return L"*:,Perforate";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoPerforate::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",WorkingDirection";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPerforate::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Depth,RelativeStartPosition,RelativeWorkingPath,StartPosition,WorkingPath,TeethPerDimension");
};

/**
 typesafe validator
*/
	vWString JDFAutoPerforate::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDepth(level)) {
			vAtts.push_back(atr_Depth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRelativeStartPosition(level)) {
			vAtts.push_back(atr_RelativeStartPosition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRelativeWorkingPath(level)) {
			vAtts.push_back(atr_RelativeWorkingPath);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStartPosition(level)) {
			vAtts.push_back(atr_StartPosition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWorkingPath(level)) {
			vAtts.push_back(atr_WorkingPath);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWorkingDirection(level)) {
			vAtts.push_back(atr_WorkingDirection);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTeethPerDimension(level)) {
			vAtts.push_back(atr_TeethPerDimension);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Depth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPerforate::SetDepth(double value){
	SetAttribute(atr_Depth,WString::valueOf(value));
};
/**
* Get double attribute Depth
* @return double the vaue of the attribute 
*/
	 double JDFAutoPerforate::GetDepth() const {
	return GetRealAttribute(atr_Depth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerforate::ValidDepth(EnumValidationLevel level) const {
		return ValidAttribute(atr_Depth,AttributeType_double,false);
	};
/**
* Set attribute RelativeStartPosition
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPerforate::SetRelativeStartPosition(const JDFXYPair& value){
	SetAttribute(atr_RelativeStartPosition,value);
};
/**
* Get string attribute RelativeStartPosition
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPerforate::GetRelativeStartPosition() const {
	return GetAttribute(atr_RelativeStartPosition,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerforate::ValidRelativeStartPosition(EnumValidationLevel level) const {
		return ValidAttribute(atr_RelativeStartPosition,AttributeType_XYPair,false);
	};
/**
* Set attribute RelativeWorkingPath
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPerforate::SetRelativeWorkingPath(const JDFXYPair& value){
	SetAttribute(atr_RelativeWorkingPath,value);
};
/**
* Get string attribute RelativeWorkingPath
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPerforate::GetRelativeWorkingPath() const {
	return GetAttribute(atr_RelativeWorkingPath,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerforate::ValidRelativeWorkingPath(EnumValidationLevel level) const {
		return ValidAttribute(atr_RelativeWorkingPath,AttributeType_XYPair,false);
	};
/**
* Set attribute StartPosition
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPerforate::SetStartPosition(const JDFXYPair& value){
	SetAttribute(atr_StartPosition,value);
};
/**
* Get string attribute StartPosition
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPerforate::GetStartPosition() const {
	return GetAttribute(atr_StartPosition,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerforate::ValidStartPosition(EnumValidationLevel level) const {
		return ValidAttribute(atr_StartPosition,AttributeType_XYPair,false);
	};
/**
* Set attribute WorkingPath
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPerforate::SetWorkingPath(const JDFXYPair& value){
	SetAttribute(atr_WorkingPath,value);
};
/**
* Get string attribute WorkingPath
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPerforate::GetWorkingPath() const {
	return GetAttribute(atr_WorkingPath,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerforate::ValidWorkingPath(EnumValidationLevel level) const {
		return ValidAttribute(atr_WorkingPath,AttributeType_XYPair,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPerforate::WorkingDirectionString(){
		static const WString enums=WString(L"Unknown,Top,Bottom");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPerforate::WorkingDirectionString(EnumWorkingDirection value){
		return WorkingDirectionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPerforate::SetWorkingDirection( EnumWorkingDirection value){
	SetEnumAttribute(atr_WorkingDirection,value,WorkingDirectionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPerforate::EnumWorkingDirection JDFAutoPerforate:: GetWorkingDirection() const {
	return (EnumWorkingDirection) GetEnumAttribute(atr_WorkingDirection,WorkingDirectionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerforate::ValidWorkingDirection(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_WorkingDirection,WorkingDirectionString(),RequiredLevel(level));
	};
/**
* Set attribute TeethPerDimension
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPerforate::SetTeethPerDimension(double value){
	SetAttribute(atr_TeethPerDimension,WString::valueOf(value));
};
/**
* Get double attribute TeethPerDimension
* @return double the vaue of the attribute 
*/
	 double JDFAutoPerforate::GetTeethPerDimension() const {
	return GetRealAttribute(atr_TeethPerDimension,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerforate::ValidTeethPerDimension(EnumValidationLevel level) const {
		return ValidAttribute(atr_TeethPerDimension,AttributeType_double,false);
	};
}; // end namespace JDF
