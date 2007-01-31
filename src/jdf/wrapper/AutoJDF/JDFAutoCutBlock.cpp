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

 
#include "jdf/wrapper/AutoJDF/JDFAutoCutBlock.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCutBlock : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoCutBlock& JDFAutoCutBlock::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoCutBlock: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoCutBlock::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoCutBlock::ValidNodeNames()const{
	return L"*:,CutBlock";
};

bool JDFAutoCutBlock::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoCutBlock::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoCutBlock::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",BlockName,BlockSize,BlockType";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoCutBlock::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",BlockSubdivision,BlockTrf,AssemblyIDs,BlockElementSize,BlockElementType");
};

/**
 typesafe validator
*/
	vWString JDFAutoCutBlock::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBlockName(level)) {
			vAtts.push_back(atr_BlockName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlockSize(level)) {
			vAtts.push_back(atr_BlockSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlockSubdivision(level)) {
			vAtts.push_back(atr_BlockSubdivision);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlockTrf(level)) {
			vAtts.push_back(atr_BlockTrf);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlockType(level)) {
			vAtts.push_back(atr_BlockType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAssemblyIDs(level)) {
			vAtts.push_back(atr_AssemblyIDs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlockElementSize(level)) {
			vAtts.push_back(atr_BlockElementSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlockElementType(level)) {
			vAtts.push_back(atr_BlockElementType);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute BlockName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCutBlock::SetBlockName(const WString& value){
	SetAttribute(atr_BlockName,value);
};
/**
* Get string attribute BlockName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCutBlock::GetBlockName() const {
	return GetAttribute(atr_BlockName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCutBlock::ValidBlockName(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlockName,AttributeType_NMTOKEN,RequiredLevel(level));
	};
/**
* Set attribute BlockSize
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoCutBlock::SetBlockSize(const JDFXYPair& value){
	SetAttribute(atr_BlockSize,value);
};
/**
* Get string attribute BlockSize
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoCutBlock::GetBlockSize() const {
	return GetAttribute(atr_BlockSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCutBlock::ValidBlockSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlockSize,AttributeType_XYPair,RequiredLevel(level));
	};
/**
* Set attribute BlockSubdivision
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoCutBlock::SetBlockSubdivision(const JDFXYPair& value){
	SetAttribute(atr_BlockSubdivision,value);
};
/**
* Get string attribute BlockSubdivision
* @return JDFXYPair the vaue of the attribute ; defaults to 1 1
*/
	 JDFXYPair JDFAutoCutBlock::GetBlockSubdivision() const {
	return GetAttribute(atr_BlockSubdivision,WString::emptyStr,L"1 1");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCutBlock::ValidBlockSubdivision(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlockSubdivision,AttributeType_XYPair,false);
	};
/**
* Set attribute BlockTrf
*@param JDFMatrix value: the value to set the attribute to
*/
	 void JDFAutoCutBlock::SetBlockTrf(const JDFMatrix& value){
	SetAttribute(atr_BlockTrf,value);
};
/**
* Get string attribute BlockTrf
* @return JDFMatrix the vaue of the attribute ; defaults to 1 0 0 1 0 0
*/
	 JDFMatrix JDFAutoCutBlock::GetBlockTrf() const {
	return GetAttribute(atr_BlockTrf,WString::emptyStr,L"1 0 0 1 0 0");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCutBlock::ValidBlockTrf(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlockTrf,AttributeType_matrix,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoCutBlock::BlockTypeString(){
		static const WString enums=WString(L"Unknown,CutBlock,SaveBlock,TempBlock,MarkBlock");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoCutBlock::BlockTypeString(EnumBlockType value){
		return BlockTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoCutBlock::SetBlockType( EnumBlockType value){
	SetEnumAttribute(atr_BlockType,value,BlockTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoCutBlock::EnumBlockType JDFAutoCutBlock:: GetBlockType() const {
	return (EnumBlockType) GetEnumAttribute(atr_BlockType,BlockTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCutBlock::ValidBlockType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BlockType,BlockTypeString(),RequiredLevel(level));
	};
/**
* Set attribute AssemblyIDs
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoCutBlock::SetAssemblyIDs(const vWString& value){
	SetAttribute(atr_AssemblyIDs,value);
};
/**
* Get string attribute AssemblyIDs
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoCutBlock::GetAssemblyIDs() const {
	return GetAttribute(atr_AssemblyIDs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCutBlock::ValidAssemblyIDs(EnumValidationLevel level) const {
		return ValidAttribute(atr_AssemblyIDs,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute BlockElementSize
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoCutBlock::SetBlockElementSize(const JDFXYPair& value){
	SetAttribute(atr_BlockElementSize,value);
};
/**
* Get string attribute BlockElementSize
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoCutBlock::GetBlockElementSize() const {
	return GetAttribute(atr_BlockElementSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCutBlock::ValidBlockElementSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlockElementSize,AttributeType_XYPair,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoCutBlock::BlockElementTypeString(){
		static const WString enums=WString(L"Unknown,CutElement,PunchElement");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoCutBlock::BlockElementTypeString(EnumBlockElementType value){
		return BlockElementTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoCutBlock::SetBlockElementType( EnumBlockElementType value){
	SetEnumAttribute(atr_BlockElementType,value,BlockElementTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoCutBlock::EnumBlockElementType JDFAutoCutBlock:: GetBlockElementType() const {
	return (EnumBlockElementType) GetEnumAttribute(atr_BlockElementType,BlockElementTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCutBlock::ValidBlockElementType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BlockElementType,BlockElementTypeString(),false);
	};
}; // end namespace JDF
