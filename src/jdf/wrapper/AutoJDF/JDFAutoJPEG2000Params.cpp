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

 
#include "jdf/wrapper/AutoJDF/JDFAutoJPEG2000Params.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoJPEG2000Params : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoJPEG2000Params& JDFAutoJPEG2000Params::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoJPEG2000Params: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoJPEG2000Params::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoJPEG2000Params::ValidNodeNames()const{
	return L"*:,JPEG2000Params";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoJPEG2000Params::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",CodeBlockSize,LayersPerTile,LayerRates,NumResolutions,ProgressionOrder,TileSize");
};

/**
 typesafe validator
*/
	vWString JDFAutoJPEG2000Params::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCodeBlockSize(level)) {
			vAtts.push_back(atr_CodeBlockSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLayersPerTile(level)) {
			vAtts.push_back(atr_LayersPerTile);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLayerRates(level)) {
			vAtts.push_back(atr_LayerRates);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNumResolutions(level)) {
			vAtts.push_back(atr_NumResolutions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProgressionOrder(level)) {
			vAtts.push_back(atr_ProgressionOrder);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTileSize(level)) {
			vAtts.push_back(atr_TileSize);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute CodeBlockSize
*@param int value: the value to set the attribute to
*/
	 void JDFAutoJPEG2000Params::SetCodeBlockSize(int value){
	SetAttribute(atr_CodeBlockSize,WString::valueOf(value));
};
/**
* Get integer attribute CodeBlockSize
* @return int the vaue of the attribute 
*/
	 int JDFAutoJPEG2000Params::GetCodeBlockSize() const {
	return GetIntAttribute(atr_CodeBlockSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJPEG2000Params::ValidCodeBlockSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_CodeBlockSize,AttributeType_integer,false);
	};
/**
* Set attribute LayersPerTile
*@param int value: the value to set the attribute to
*/
	 void JDFAutoJPEG2000Params::SetLayersPerTile(int value){
	SetAttribute(atr_LayersPerTile,WString::valueOf(value));
};
/**
* Get integer attribute LayersPerTile
* @return int the vaue of the attribute ; defaults to 1
*/
	 int JDFAutoJPEG2000Params::GetLayersPerTile() const {
	return GetIntAttribute(atr_LayersPerTile,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJPEG2000Params::ValidLayersPerTile(EnumValidationLevel level) const {
		return ValidAttribute(atr_LayersPerTile,AttributeType_integer,false);
	};
/**
* Set attribute LayerRates
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoJPEG2000Params::SetLayerRates(const JDFNumberList& value){
	SetAttribute(atr_LayerRates,value.GetString());
};
/**
* Get string attribute LayerRates
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoJPEG2000Params::GetLayerRates() const {
	return GetAttribute(atr_LayerRates,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJPEG2000Params::ValidLayerRates(EnumValidationLevel level) const {
		return ValidAttribute(atr_LayerRates,AttributeType_NumberList,false);
	};
/**
* Set attribute NumResolutions
*@param int value: the value to set the attribute to
*/
	 void JDFAutoJPEG2000Params::SetNumResolutions(int value){
	SetAttribute(atr_NumResolutions,WString::valueOf(value));
};
/**
* Get integer attribute NumResolutions
* @return int the vaue of the attribute 
*/
	 int JDFAutoJPEG2000Params::GetNumResolutions() const {
	return GetIntAttribute(atr_NumResolutions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJPEG2000Params::ValidNumResolutions(EnumValidationLevel level) const {
		return ValidAttribute(atr_NumResolutions,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoJPEG2000Params::ProgressionOrderString(){
		static const WString enums=WString(L"Unknown,LRCP,RLCP,RPCL,PCRL,CPRL");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoJPEG2000Params::ProgressionOrderString(EnumProgressionOrder value){
		return ProgressionOrderString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoJPEG2000Params::SetProgressionOrder( EnumProgressionOrder value){
	SetEnumAttribute(atr_ProgressionOrder,value,ProgressionOrderString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoJPEG2000Params::EnumProgressionOrder JDFAutoJPEG2000Params:: GetProgressionOrder() const {
	return (EnumProgressionOrder) GetEnumAttribute(atr_ProgressionOrder,ProgressionOrderString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJPEG2000Params::ValidProgressionOrder(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ProgressionOrder,ProgressionOrderString(),false);
	};
/**
* Set attribute TileSize
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoJPEG2000Params::SetTileSize(const JDFXYPair& value){
	SetAttribute(atr_TileSize,value);
};
/**
* Get string attribute TileSize
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoJPEG2000Params::GetTileSize() const {
	return GetAttribute(atr_TileSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJPEG2000Params::ValidTileSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_TileSize,AttributeType_XYPair,false);
	};
}; // end namespace JDF
