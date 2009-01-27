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

 
#include "jdf/wrapper/AutoJDF/JDFAutoSignatureCell.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoSignatureCell : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoSignatureCell& JDFAutoSignatureCell::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoSignatureCell: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoSignatureCell::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoSignatureCell::ValidNodeNames()const{
	return L"*:,SignatureCell";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoSignatureCell::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",BackFacePages,BackPages,BottleAngle,BottleAxis,FaceCells,FrontFacePages,FrontPages,Orientation,SectionIndex,StationName");
};

/**
 typesafe validator
*/
	vWString JDFAutoSignatureCell::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBackFacePages(level)) {
			vAtts.push_back(atr_BackFacePages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBackPages(level)) {
			vAtts.push_back(atr_BackPages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBottleAngle(level)) {
			vAtts.push_back(atr_BottleAngle);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBottleAxis(level)) {
			vAtts.push_back(atr_BottleAxis);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFaceCells(level)) {
			vAtts.push_back(atr_FaceCells);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFrontFacePages(level)) {
			vAtts.push_back(atr_FrontFacePages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFrontPages(level)) {
			vAtts.push_back(atr_FrontPages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrientation(level)) {
			vAtts.push_back(atr_Orientation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSectionIndex(level)) {
			vAtts.push_back(atr_SectionIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStationName(level)) {
			vAtts.push_back(atr_StationName);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute BackFacePages
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoSignatureCell::SetBackFacePages(const JDFIntegerList& value){
	SetAttribute(atr_BackFacePages,value.GetString());
};
/**
* Get string attribute BackFacePages
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoSignatureCell::GetBackFacePages() const {
	return GetAttribute(atr_BackFacePages,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSignatureCell::ValidBackFacePages(EnumValidationLevel level) const {
		return ValidAttribute(atr_BackFacePages,AttributeType_IntegerList,false);
	};
/**
* Set attribute BackPages
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoSignatureCell::SetBackPages(const JDFIntegerList& value){
	SetAttribute(atr_BackPages,value.GetString());
};
/**
* Get string attribute BackPages
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoSignatureCell::GetBackPages() const {
	return GetAttribute(atr_BackPages,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSignatureCell::ValidBackPages(EnumValidationLevel level) const {
		return ValidAttribute(atr_BackPages,AttributeType_IntegerList,false);
	};
/**
* Set attribute BottleAngle
*@param double value: the value to set the attribute to
*/
	 void JDFAutoSignatureCell::SetBottleAngle(double value){
	SetAttribute(atr_BottleAngle,WString::valueOf(value));
};
/**
* Get double attribute BottleAngle
* @return double the vaue of the attribute 
*/
	 double JDFAutoSignatureCell::GetBottleAngle() const {
	return GetRealAttribute(atr_BottleAngle,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSignatureCell::ValidBottleAngle(EnumValidationLevel level) const {
		return ValidAttribute(atr_BottleAngle,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoSignatureCell::BottleAxisString(){
		static const WString enums=WString(L"Unknown,SpineHead,SpineFoot,FaceHead,FaceFoot");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoSignatureCell::BottleAxisString(EnumBottleAxis value){
		return BottleAxisString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoSignatureCell::SetBottleAxis( EnumBottleAxis value){
	SetEnumAttribute(atr_BottleAxis,value,BottleAxisString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoSignatureCell::EnumBottleAxis JDFAutoSignatureCell:: GetBottleAxis() const {
	return (EnumBottleAxis) GetEnumAttribute(atr_BottleAxis,BottleAxisString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSignatureCell::ValidBottleAxis(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BottleAxis,BottleAxisString(),false);
	};
/**
* Set attribute FaceCells
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoSignatureCell::SetFaceCells(const JDFIntegerList& value){
	SetAttribute(atr_FaceCells,value.GetString());
};
/**
* Get string attribute FaceCells
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoSignatureCell::GetFaceCells() const {
	return GetAttribute(atr_FaceCells,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSignatureCell::ValidFaceCells(EnumValidationLevel level) const {
		return ValidAttribute(atr_FaceCells,AttributeType_IntegerList,false);
	};
/**
* Set attribute FrontFacePages
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoSignatureCell::SetFrontFacePages(const JDFIntegerList& value){
	SetAttribute(atr_FrontFacePages,value.GetString());
};
/**
* Get string attribute FrontFacePages
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoSignatureCell::GetFrontFacePages() const {
	return GetAttribute(atr_FrontFacePages,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSignatureCell::ValidFrontFacePages(EnumValidationLevel level) const {
		return ValidAttribute(atr_FrontFacePages,AttributeType_IntegerList,false);
	};
/**
* Set attribute FrontPages
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoSignatureCell::SetFrontPages(const JDFIntegerList& value){
	SetAttribute(atr_FrontPages,value.GetString());
};
/**
* Get string attribute FrontPages
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoSignatureCell::GetFrontPages() const {
	return GetAttribute(atr_FrontPages,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSignatureCell::ValidFrontPages(EnumValidationLevel level) const {
		return ValidAttribute(atr_FrontPages,AttributeType_IntegerList,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoSignatureCell::OrientationString(){
		static const WString enums=WString(L"Unknown,Up,Down,Left,Right");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoSignatureCell::OrientationString(EnumOrientation value){
		return OrientationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoSignatureCell::SetOrientation( EnumOrientation value){
	SetEnumAttribute(atr_Orientation,value,OrientationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoSignatureCell::EnumOrientation JDFAutoSignatureCell:: GetOrientation() const {
	return (EnumOrientation) GetEnumAttribute(atr_Orientation,OrientationString(),WString::emptyStr,Orientation_Up);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSignatureCell::ValidOrientation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Orientation,OrientationString(),false);
	};
/**
* Set attribute SectionIndex
*@param int value: the value to set the attribute to
*/
	 void JDFAutoSignatureCell::SetSectionIndex(int value){
	SetAttribute(atr_SectionIndex,WString::valueOf(value));
};
/**
* Get integer attribute SectionIndex
* @return int the vaue of the attribute ; defaults to 0
*/
	 int JDFAutoSignatureCell::GetSectionIndex() const {
	return GetIntAttribute(atr_SectionIndex,WString::emptyStr,0);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSignatureCell::ValidSectionIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SectionIndex,AttributeType_integer,false);
	};
/**
* Set attribute StationName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSignatureCell::SetStationName(const WString& value){
	SetAttribute(atr_StationName,value);
};
/**
* Get string attribute StationName
* @return WString the vaue of the attribute ; defaults to 0
*/
	 WString JDFAutoSignatureCell::GetStationName() const {
	return GetAttribute(atr_StationName,WString::emptyStr,L"0");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSignatureCell::ValidStationName(EnumValidationLevel level) const {
		return ValidAttribute(atr_StationName,AttributeType_string,false);
	};
}; // end namespace JDF
