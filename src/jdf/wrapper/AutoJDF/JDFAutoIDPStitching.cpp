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

 
#include "jdf/wrapper/AutoJDF/JDFAutoIDPStitching.h"
#include "jdf/wrapper/JDFStitchingParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoIDPStitching : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoIDPStitching& JDFAutoIDPStitching::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoIDPStitching: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoIDPStitching::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoIDPStitching::ValidNodeNames()const{
	return L"*:,IDPStitching";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoIDPStitching::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",StitchingPosition,StitchingReferenceEdge");
};

/**
 typesafe validator
*/
	vWString JDFAutoIDPStitching::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidStitchingPosition(level)) {
			vAtts.push_back(atr_StitchingPosition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStitchingReferenceEdge(level)) {
			vAtts.push_back(atr_StitchingReferenceEdge);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoIDPStitching::StitchingPositionString(){
		static const WString enums=WString(L"Unknown,None,TopLeft,BottomLeft,TopRight,BottomRight,LeftEdge,TopEdge,RightEdge,BottomEdge")
	+WString(L",DualLeftEdge,DualTopEdge,DualRightEdge,DualBottomEdge");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoIDPStitching::StitchingPositionString(EnumStitchingPosition value){
		return StitchingPositionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoIDPStitching::SetStitchingPosition( EnumStitchingPosition value){
	SetEnumAttribute(atr_StitchingPosition,value,StitchingPositionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoIDPStitching::EnumStitchingPosition JDFAutoIDPStitching:: GetStitchingPosition() const {
	return (EnumStitchingPosition) GetEnumAttribute(atr_StitchingPosition,StitchingPositionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPStitching::ValidStitchingPosition(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_StitchingPosition,StitchingPositionString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoIDPStitching::StitchingReferenceEdgeString(){
		static const WString enums=WString(L"Unknown,Bottom,Top,Left,Right");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoIDPStitching::StitchingReferenceEdgeString(EnumStitchingReferenceEdge value){
		return StitchingReferenceEdgeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoIDPStitching::SetStitchingReferenceEdge( EnumStitchingReferenceEdge value){
	SetEnumAttribute(atr_StitchingReferenceEdge,value,StitchingReferenceEdgeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoIDPStitching::EnumStitchingReferenceEdge JDFAutoIDPStitching:: GetStitchingReferenceEdge() const {
	return (EnumStitchingReferenceEdge) GetEnumAttribute(atr_StitchingReferenceEdge,StitchingReferenceEdgeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPStitching::ValidStitchingReferenceEdge(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_StitchingReferenceEdge,StitchingReferenceEdgeString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFStitchingParams JDFAutoIDPStitching::GetStitchingParams(int iSkip)const{
	JDFStitchingParams e=GetElement(elm_StitchingParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStitchingParams JDFAutoIDPStitching::GetCreateStitchingParams(int iSkip){
	JDFStitchingParams e=GetCreateElement(elm_StitchingParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStitchingParams JDFAutoIDPStitching::AppendStitchingParams(){
	JDFStitchingParams e=AppendElement(elm_StitchingParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoIDPStitching::RefStitchingParams(JDFStitchingParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoIDPStitching::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_StitchingParams);

		for(i=0;i<nElem;i++){
			if (!GetStitchingParams(i).IsValid(level)) {
				vElem.AppendUnique(elm_StitchingParams);
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
	WString JDFAutoIDPStitching::OptionalElements()const{
		return JDFElement::OptionalElements()+L",StitchingParams";
	};
}; // end namespace JDF
