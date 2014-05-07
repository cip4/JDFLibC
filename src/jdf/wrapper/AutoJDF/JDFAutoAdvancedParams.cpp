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

 
#include "jdf/wrapper/AutoJDF/JDFAutoAdvancedParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoAdvancedParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoAdvancedParams& JDFAutoAdvancedParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoAdvancedParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoAdvancedParams::ValidNodeNames()const{
	return L"*:,AdvancedParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoAdvancedParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",AllowPSXObjects,AllowTransparency,AutoPositionEPSInfo,EmbedJobOptions,EmitDSCWarnings,LockDistillerParams,ParseDSCComments,ParseDSCCommentsForDocInfo,PassThroughJPEGImages,PreserveCopyPage,PreserveEPSInfo,PreserveHalftoneInfo,PreserveOverprintSettings,PreserveOPIComments,TransferFunctionInfo,UCRandBGInfo,UsePrologue");
};

/**
 typesafe validator
*/
	vWString JDFAutoAdvancedParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAllowPSXObjects(level)) {
			vAtts.push_back(atr_AllowPSXObjects);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAllowTransparency(level)) {
			vAtts.push_back(atr_AllowTransparency);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAutoPositionEPSInfo(level)) {
			vAtts.push_back(atr_AutoPositionEPSInfo);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEmbedJobOptions(level)) {
			vAtts.push_back(atr_EmbedJobOptions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEmitDSCWarnings(level)) {
			vAtts.push_back(atr_EmitDSCWarnings);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLockDistillerParams(level)) {
			vAtts.push_back(atr_LockDistillerParams);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidParseDSCComments(level)) {
			vAtts.push_back(atr_ParseDSCComments);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidParseDSCCommentsForDocInfo(level)) {
			vAtts.push_back(atr_ParseDSCCommentsForDocInfo);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPassThroughJPEGImages(level)) {
			vAtts.push_back(atr_PassThroughJPEGImages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPreserveCopyPage(level)) {
			vAtts.push_back(atr_PreserveCopyPage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPreserveEPSInfo(level)) {
			vAtts.push_back(atr_PreserveEPSInfo);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPreserveHalftoneInfo(level)) {
			vAtts.push_back(atr_PreserveHalftoneInfo);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPreserveOverprintSettings(level)) {
			vAtts.push_back(atr_PreserveOverprintSettings);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPreserveOPIComments(level)) {
			vAtts.push_back(atr_PreserveOPIComments);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTransferFunctionInfo(level)) {
			vAtts.push_back(atr_TransferFunctionInfo);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUCRandBGInfo(level)) {
			vAtts.push_back(atr_UCRandBGInfo);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUsePrologue(level)) {
			vAtts.push_back(atr_UsePrologue);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AllowPSXObjects
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAdvancedParams::SetAllowPSXObjects(bool value){
	SetAttribute(atr_AllowPSXObjects,WString::valueOf(value));
};
/**
* Get bool attribute AllowPSXObjects
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoAdvancedParams::GetAllowPSXObjects() const {return GetBoolAttribute(atr_AllowPSXObjects,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::ValidAllowPSXObjects(EnumValidationLevel level) const {
		return ValidAttribute(atr_AllowPSXObjects,AttributeType_boolean,false);
	};
/**
* Set attribute AllowTransparency
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAdvancedParams::SetAllowTransparency(bool value){
	SetAttribute(atr_AllowTransparency,WString::valueOf(value));
};
/**
* Get bool attribute AllowTransparency
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoAdvancedParams::GetAllowTransparency() const {return GetBoolAttribute(atr_AllowTransparency,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::ValidAllowTransparency(EnumValidationLevel level) const {
		return ValidAttribute(atr_AllowTransparency,AttributeType_boolean,false);
	};
/**
* Set attribute AutoPositionEPSInfo
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAdvancedParams::SetAutoPositionEPSInfo(bool value){
	SetAttribute(atr_AutoPositionEPSInfo,WString::valueOf(value));
};
/**
* Get bool attribute AutoPositionEPSInfo
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoAdvancedParams::GetAutoPositionEPSInfo() const {return GetBoolAttribute(atr_AutoPositionEPSInfo,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::ValidAutoPositionEPSInfo(EnumValidationLevel level) const {
		return ValidAttribute(atr_AutoPositionEPSInfo,AttributeType_boolean,false);
	};
/**
* Set attribute EmbedJobOptions
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAdvancedParams::SetEmbedJobOptions(bool value){
	SetAttribute(atr_EmbedJobOptions,WString::valueOf(value));
};
/**
* Get bool attribute EmbedJobOptions
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoAdvancedParams::GetEmbedJobOptions() const {return GetBoolAttribute(atr_EmbedJobOptions,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::ValidEmbedJobOptions(EnumValidationLevel level) const {
		return ValidAttribute(atr_EmbedJobOptions,AttributeType_boolean,false);
	};
/**
* Set attribute EmitDSCWarnings
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAdvancedParams::SetEmitDSCWarnings(bool value){
	SetAttribute(atr_EmitDSCWarnings,WString::valueOf(value));
};
/**
* Get bool attribute EmitDSCWarnings
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoAdvancedParams::GetEmitDSCWarnings() const {return GetBoolAttribute(atr_EmitDSCWarnings,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::ValidEmitDSCWarnings(EnumValidationLevel level) const {
		return ValidAttribute(atr_EmitDSCWarnings,AttributeType_boolean,false);
	};
/**
* Set attribute LockDistillerParams
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAdvancedParams::SetLockDistillerParams(bool value){
	SetAttribute(atr_LockDistillerParams,WString::valueOf(value));
};
/**
* Get bool attribute LockDistillerParams
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoAdvancedParams::GetLockDistillerParams() const {return GetBoolAttribute(atr_LockDistillerParams,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::ValidLockDistillerParams(EnumValidationLevel level) const {
		return ValidAttribute(atr_LockDistillerParams,AttributeType_boolean,false);
	};
/**
* Set attribute ParseDSCComments
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAdvancedParams::SetParseDSCComments(bool value){
	SetAttribute(atr_ParseDSCComments,WString::valueOf(value));
};
/**
* Get bool attribute ParseDSCComments
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoAdvancedParams::GetParseDSCComments() const {return GetBoolAttribute(atr_ParseDSCComments,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::ValidParseDSCComments(EnumValidationLevel level) const {
		return ValidAttribute(atr_ParseDSCComments,AttributeType_boolean,false);
	};
/**
* Set attribute ParseDSCCommentsForDocInfo
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAdvancedParams::SetParseDSCCommentsForDocInfo(bool value){
	SetAttribute(atr_ParseDSCCommentsForDocInfo,WString::valueOf(value));
};
/**
* Get bool attribute ParseDSCCommentsForDocInfo
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoAdvancedParams::GetParseDSCCommentsForDocInfo() const {return GetBoolAttribute(atr_ParseDSCCommentsForDocInfo,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::ValidParseDSCCommentsForDocInfo(EnumValidationLevel level) const {
		return ValidAttribute(atr_ParseDSCCommentsForDocInfo,AttributeType_boolean,false);
	};
/**
* Set attribute PassThroughJPEGImages
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAdvancedParams::SetPassThroughJPEGImages(bool value){
	SetAttribute(atr_PassThroughJPEGImages,WString::valueOf(value));
};
/**
* Get bool attribute PassThroughJPEGImages
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoAdvancedParams::GetPassThroughJPEGImages() const {return GetBoolAttribute(atr_PassThroughJPEGImages,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::ValidPassThroughJPEGImages(EnumValidationLevel level) const {
		return ValidAttribute(atr_PassThroughJPEGImages,AttributeType_boolean,false);
	};
/**
* Set attribute PreserveCopyPage
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAdvancedParams::SetPreserveCopyPage(bool value){
	SetAttribute(atr_PreserveCopyPage,WString::valueOf(value));
};
/**
* Get bool attribute PreserveCopyPage
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoAdvancedParams::GetPreserveCopyPage() const {return GetBoolAttribute(atr_PreserveCopyPage,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::ValidPreserveCopyPage(EnumValidationLevel level) const {
		return ValidAttribute(atr_PreserveCopyPage,AttributeType_boolean,false);
	};
/**
* Set attribute PreserveEPSInfo
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAdvancedParams::SetPreserveEPSInfo(bool value){
	SetAttribute(atr_PreserveEPSInfo,WString::valueOf(value));
};
/**
* Get bool attribute PreserveEPSInfo
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoAdvancedParams::GetPreserveEPSInfo() const {return GetBoolAttribute(atr_PreserveEPSInfo,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::ValidPreserveEPSInfo(EnumValidationLevel level) const {
		return ValidAttribute(atr_PreserveEPSInfo,AttributeType_boolean,false);
	};
/**
* Set attribute PreserveHalftoneInfo
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAdvancedParams::SetPreserveHalftoneInfo(bool value){
	SetAttribute(atr_PreserveHalftoneInfo,WString::valueOf(value));
};
/**
* Get bool attribute PreserveHalftoneInfo
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoAdvancedParams::GetPreserveHalftoneInfo() const {return GetBoolAttribute(atr_PreserveHalftoneInfo,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::ValidPreserveHalftoneInfo(EnumValidationLevel level) const {
		return ValidAttribute(atr_PreserveHalftoneInfo,AttributeType_boolean,false);
	};
/**
* Set attribute PreserveOverprintSettings
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAdvancedParams::SetPreserveOverprintSettings(bool value){
	SetAttribute(atr_PreserveOverprintSettings,WString::valueOf(value));
};
/**
* Get bool attribute PreserveOverprintSettings
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoAdvancedParams::GetPreserveOverprintSettings() const {return GetBoolAttribute(atr_PreserveOverprintSettings,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::ValidPreserveOverprintSettings(EnumValidationLevel level) const {
		return ValidAttribute(atr_PreserveOverprintSettings,AttributeType_boolean,false);
	};
/**
* Set attribute PreserveOPIComments
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAdvancedParams::SetPreserveOPIComments(bool value){
	SetAttribute(atr_PreserveOPIComments,WString::valueOf(value));
};
/**
* Get bool attribute PreserveOPIComments
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoAdvancedParams::GetPreserveOPIComments() const {return GetBoolAttribute(atr_PreserveOPIComments,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::ValidPreserveOPIComments(EnumValidationLevel level) const {
		return ValidAttribute(atr_PreserveOPIComments,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoAdvancedParams::TransferFunctionInfoString(){
		static const WString enums=WString(L"Unknown,Preserve,Remove,Apply");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoAdvancedParams::TransferFunctionInfoString(EnumTransferFunctionInfo value){
		return TransferFunctionInfoString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoAdvancedParams::SetTransferFunctionInfo( EnumTransferFunctionInfo value){
	SetEnumAttribute(atr_TransferFunctionInfo,value,TransferFunctionInfoString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoAdvancedParams::EnumTransferFunctionInfo JDFAutoAdvancedParams:: GetTransferFunctionInfo() const {
	return (EnumTransferFunctionInfo) GetEnumAttribute(atr_TransferFunctionInfo,TransferFunctionInfoString(),WString::emptyStr,TransferFunctionInfo_Preserve);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::ValidTransferFunctionInfo(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_TransferFunctionInfo,TransferFunctionInfoString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoAdvancedParams::UCRandBGInfoString(){
		static const WString enums=WString(L"Unknown,Preserve,Remove");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoAdvancedParams::UCRandBGInfoString(EnumUCRandBGInfo value){
		return UCRandBGInfoString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoAdvancedParams::SetUCRandBGInfo( EnumUCRandBGInfo value){
	SetEnumAttribute(atr_UCRandBGInfo,value,UCRandBGInfoString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoAdvancedParams::EnumUCRandBGInfo JDFAutoAdvancedParams:: GetUCRandBGInfo() const {
	return (EnumUCRandBGInfo) GetEnumAttribute(atr_UCRandBGInfo,UCRandBGInfoString(),WString::emptyStr,UCRandBGInfo_Preserve);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::ValidUCRandBGInfo(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_UCRandBGInfo,UCRandBGInfoString(),false);
	};
/**
* Set attribute UsePrologue
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAdvancedParams::SetUsePrologue(bool value){
	SetAttribute(atr_UsePrologue,WString::valueOf(value));
};
/**
* Get bool attribute UsePrologue
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoAdvancedParams::GetUsePrologue() const {return GetBoolAttribute(atr_UsePrologue,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdvancedParams::ValidUsePrologue(EnumValidationLevel level) const {
		return ValidAttribute(atr_UsePrologue,AttributeType_boolean,false);
	};
}; // end namespace JDF
