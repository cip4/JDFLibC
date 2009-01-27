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

 
#include "jdf/wrapper/AutoJDF/JDFAutoBoxFoldAction.h"
#include "jdf/wrapper/JDFGlueLine.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoBoxFoldAction : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoBoxFoldAction& JDFAutoBoxFoldAction::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoBoxFoldAction: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoBoxFoldAction::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoBoxFoldAction::ValidNodeNames()const{
	return L"*:,BoxFoldAction";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoBoxFoldAction::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",FoldIndex";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoBoxFoldAction::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Action");
};

/**
 typesafe validator
*/
	vWString JDFAutoBoxFoldAction::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidFoldIndex(level)) {
			vAtts.push_back(atr_FoldIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAction(level)) {
			vAtts.push_back(atr_Action);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute FoldIndex
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoBoxFoldAction::SetFoldIndex(const JDFXYPair& value){
	SetAttribute(atr_FoldIndex,value);
};
/**
* Get string attribute FoldIndex
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoBoxFoldAction::GetFoldIndex() const {
	return GetAttribute(atr_FoldIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxFoldAction::ValidFoldIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_FoldIndex,AttributeType_XYPair,RequiredLevel(level));
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoBoxFoldAction::ActionString(){
		static const WString enums=WString(L"Unknown,LongFoldLeftToRight,LongFoldRightToLeft,LongPreFoldLeftToRight,LongPreFoldRightToLeft,FrontFoldComplete,FrontFoldDiagonal,FrontFoldCompleteDiagonal,BackFoldComplete,BackFoldDiagonal")
	+WString(L",BackFoldCompleteDiagonal,ReverseFold,Milling,Rotate90,Rotate180,Rotate270");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoBoxFoldAction::ActionString(EnumAction value){
		return ActionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoBoxFoldAction::SetAction( EnumAction value){
	SetEnumAttribute(atr_Action,value,ActionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoBoxFoldAction::EnumAction JDFAutoBoxFoldAction:: GetAction() const {
	return (EnumAction) GetEnumAttribute(atr_Action,ActionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxFoldAction::ValidAction(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Action,ActionString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFGlueLine JDFAutoBoxFoldAction::GetGlueLine(int iSkip)const{
	JDFGlueLine e=GetElement(elm_GlueLine,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoBoxFoldAction::GetCreateGlueLine(int iSkip){
	JDFGlueLine e=GetCreateElement(elm_GlueLine,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoBoxFoldAction::AppendGlueLine(){
	JDFGlueLine e=AppendElement(elm_GlueLine);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoBoxFoldAction::RefGlueLine(JDFGlueLine& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoBoxFoldAction::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_GlueLine);

		for(i=0;i<nElem;i++){
			if (!GetGlueLine(i).IsValid(level)) {
				vElem.AppendUnique(elm_GlueLine);
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
	WString JDFAutoBoxFoldAction::OptionalElements()const{
		return JDFElement::OptionalElements()+L",GlueLine";
	};
}; // end namespace JDF
