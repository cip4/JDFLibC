/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoThinPDFParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoThinPDFParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoThinPDFParams& JDFAutoThinPDFParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoThinPDFParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoThinPDFParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoThinPDFParams::ValidNodeNames()const{
	return L"*:,ThinPDFParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoThinPDFParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",FilePerPage,SidelineEPS,SidelineFonts,SidelineImages");
};

/**
 typesafe validator
*/
	vWString JDFAutoThinPDFParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidFilePerPage(level)) {
			vAtts.push_back(atr_FilePerPage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSidelineEPS(level)) {
			vAtts.push_back(atr_SidelineEPS);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSidelineFonts(level)) {
			vAtts.push_back(atr_SidelineFonts);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSidelineImages(level)) {
			vAtts.push_back(atr_SidelineImages);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute FilePerPage
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoThinPDFParams::SetFilePerPage(bool value){
	SetAttribute(atr_FilePerPage,WString::valueOf(value));
};
/**
* Get bool attribute FilePerPage
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoThinPDFParams::GetFilePerPage() const {return GetBoolAttribute(atr_FilePerPage,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThinPDFParams::ValidFilePerPage(EnumValidationLevel level) const {
		return ValidAttribute(atr_FilePerPage,AttributeType_boolean,false);
	};
/**
* Set attribute SidelineEPS
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoThinPDFParams::SetSidelineEPS(bool value){
	SetAttribute(atr_SidelineEPS,WString::valueOf(value));
};
/**
* Get bool attribute SidelineEPS
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoThinPDFParams::GetSidelineEPS() const {return GetBoolAttribute(atr_SidelineEPS,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThinPDFParams::ValidSidelineEPS(EnumValidationLevel level) const {
		return ValidAttribute(atr_SidelineEPS,AttributeType_boolean,false);
	};
/**
* Set attribute SidelineFonts
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoThinPDFParams::SetSidelineFonts(bool value){
	SetAttribute(atr_SidelineFonts,WString::valueOf(value));
};
/**
* Get bool attribute SidelineFonts
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoThinPDFParams::GetSidelineFonts() const {return GetBoolAttribute(atr_SidelineFonts,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThinPDFParams::ValidSidelineFonts(EnumValidationLevel level) const {
		return ValidAttribute(atr_SidelineFonts,AttributeType_boolean,false);
	};
/**
* Set attribute SidelineImages
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoThinPDFParams::SetSidelineImages(bool value){
	SetAttribute(atr_SidelineImages,WString::valueOf(value));
};
/**
* Get bool attribute SidelineImages
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoThinPDFParams::GetSidelineImages() const {return GetBoolAttribute(atr_SidelineImages,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThinPDFParams::ValidSidelineImages(EnumValidationLevel level) const {
		return ValidAttribute(atr_SidelineImages,AttributeType_boolean,false);
	};
}; // end namespace JDF
