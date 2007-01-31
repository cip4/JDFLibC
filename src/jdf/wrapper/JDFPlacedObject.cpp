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


#include "jdf/wrapper/JDFPlacedObject.h"
namespace JDF{
	/*
	*********************************************************************
	class JDFPlacedObject : public JDFElement

	*********************************************************************
	*/
	/**
	* copy equivalance operator
	*/
	JDFPlacedObject& JDFPlacedObject::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFPlacedObject: "+other.GetNodeName());
		return *this;
	};

	/////////////////////////////////////////////////////
	bool JDFPlacedObject::IsAbstract()const{
		return true;
	}

	/**
	* typesafe validator utility - list of valid node names for this class 
	* @return WString& comma separated list of valid node names
	*/

	WString JDFPlacedObject::ValidNodeNames()const{
		return L"*:,ContentObject,MarkObject";
	};


	/* ******************************************************
	// Attribute Getter / Setter
	****************************************************** */



	/**
	* Set attribute Ord
	*@param int value: the value to set the attribute to
	*/
	void JDFPlacedObject::SetOrd(int value){
		SetAttribute(atr_Ord,WString::valueOf(value));
	};
	/**
	* Get integer attribute Ord
	* @return int the vaue of the attribute 
	*/
	int JDFPlacedObject::GetOrd() const {
		return GetIntAttribute(atr_Ord,WString::emptyStr);
	};
	/**
	* Set attribute OrdExpression
	*@param WString value: the value to set the attribute to
	*/
	void JDFPlacedObject::SetOrdExpression(const WString& value){
		SetAttribute(atr_OrdExpression,value);
	};
	/**
	* Get string attribute OrdExpression
	* @return WString the vaue of the attribute 
	*/
	WString JDFPlacedObject::GetOrdExpression() const {
		return GetAttribute(atr_OrdExpression,WString::emptyStr);
	};

	/**
	* Set attribute ClipBox
	*@param JDFRectangle value: the value to set the attribute to
	*/
	void JDFPlacedObject::SetClipBox(const JDFRectangle& value){
		SetAttribute(atr_ClipBox,value);
	};
	/**
	* Get string attribute ClipBox
	* @return JDFRectangle the vaue of the attribute 
	*/
	JDFRectangle JDFPlacedObject::GetClipBox() const {
		return GetAttribute(atr_ClipBox,WString::emptyStr);
	};
	/**
	* Set attribute ClipPath
	*@param WString value: the value to set the attribute to
	*/
	void JDFPlacedObject::SetClipPath(const WString& value){
		SetAttribute(atr_ClipPath,value);
	};
	/**
	* Get string attribute ClipPath
	* @return WString the vaue of the attribute 
	*/
	WString JDFPlacedObject::GetClipPath() const {
		return GetAttribute(atr_ClipPath,WString::emptyStr);
	};

	/**
	* Set attribute CTM
	*@param JDFMatrix value: the value to set the attribute to
	*/
	void JDFPlacedObject::SetCTM(const JDFMatrix& value){
		SetAttribute(atr_CTM,value);
	};
	/**
	* Get string attribute CTM
	* @return JDFMatrix the vaue of the attribute 
	*/
	JDFMatrix JDFPlacedObject::GetCTM() const {
		return GetAttribute(atr_CTM,WString::emptyStr);
	};
	/**
	* Set attribute HalfTonePhaseOrigin
	*@param JDFXYPair value: the value to set the attribute to
	*/
	void JDFPlacedObject::SetHalfTonePhaseOrigin(const JDFXYPair& value){
		SetAttribute(atr_HalfTonePhaseOrigin,value);
	};
	/**
	* Get string attribute HalfTonePhaseOrigin
	* @return JDFXYPair the vaue of the attribute ; defaults to 0 0
	*/
	JDFXYPair JDFPlacedObject::GetHalfTonePhaseOrigin() const {
		return GetAttribute(atr_HalfTonePhaseOrigin,WString::emptyStr,L"0 0");
	};
	/**
	* Set attribute LayerID
	*@param int value: the value to set the attribute to
	*/
	void JDFPlacedObject::SetLayerID(int value){
		SetAttribute(atr_LayerID,WString::valueOf(value));
	};
	/**
	* Get integer attribute LayerID
	* @return int the vaue of the attribute 
	*/
	int JDFPlacedObject::GetLayerID() const {
		return GetIntAttribute(atr_LayerID,WString::emptyStr);
	};
	/**
	* Set attribute OrdID
	*@param int value: the value to set the attribute to
	*/
	void JDFPlacedObject::SetOrdID(int value){
		SetAttribute(atr_OrdID,WString::valueOf(value));
	};
	/**
	* Get integer attribute OrdID
	* @return int the vaue of the attribute 
	*/
	int JDFPlacedObject::GetOrdID() const {
		return GetIntAttribute(atr_OrdID,WString::emptyStr);
	};

	/**
	* Set attribute SourceClipPath
	*@param WString value: the value to set the attribute to
	*/
	void JDFPlacedObject::SetSourceClipPath(const WString& value){
		SetAttribute(atr_SourceClipPath,value);
	};
	/**
	* Get string attribute SourceClipPath
	* @return WString the vaue of the attribute 
	*/
	WString JDFPlacedObject::GetSourceClipPath() const {
		return GetAttribute(atr_SourceClipPath,WString::emptyStr);
	};

	/**
	* Set attribute TrimCTM
	*@param JDFMatrix value: the value to set the attribute to
	*/
	void JDFPlacedObject::SetTrimCTM(const JDFMatrix& value){
		SetAttribute(atr_TrimCTM,value);
	};
	/**
	* Get string attribute TrimCTM
	* @return JDFMatrix the vaue of the attribute 
	*/
	JDFMatrix JDFPlacedObject::GetTrimCTM() const {
		return GetAttribute(atr_TrimCTM,WString::emptyStr);
	};

	/**
	* Set attribute TrimSize
	*@param JDFXYPair value: the value to set the attribute to
	*/
	void JDFPlacedObject::SetTrimSize(const JDFXYPair& value){
		SetAttribute(atr_TrimSize,value);
	};
	/**
	* Get string attribute TrimSize
	* @return JDFXYPair the vaue of the attribute 
	*/
	JDFXYPair JDFPlacedObject::GetTrimSize() const {
		return GetAttribute(atr_TrimSize,WString::emptyStr);
	};


}; // end namespace JDF
