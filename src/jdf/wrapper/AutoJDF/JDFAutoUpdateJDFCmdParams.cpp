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

 
#include "jdf/wrapper/AutoJDF/JDFAutoUpdateJDFCmdParams.h"
#include "jdf/wrapper/JDFCreateLink.h"
#include "jdf/wrapper/JDFCreateResource.h"
#include "jdf/wrapper/JDFMoveResource.h"
#include "jdf/wrapper/JDFRemoveLink.h"
#include "jdf/wrapper/JDFNode.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoUpdateJDFCmdParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoUpdateJDFCmdParams& JDFAutoUpdateJDFCmdParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoUpdateJDFCmdParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoUpdateJDFCmdParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoUpdateJDFCmdParams::ValidNodeNames()const{
	return L"*:,UpdateJDFCmdParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoUpdateJDFCmdParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFCreateLink JDFAutoUpdateJDFCmdParams::GetCreateLink(int iSkip)const{
	JDFCreateLink e=GetElement(elm_CreateLink,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCreateLink JDFAutoUpdateJDFCmdParams::GetCreateCreateLink(int iSkip){
	JDFCreateLink e=GetCreateElement(elm_CreateLink,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCreateLink JDFAutoUpdateJDFCmdParams::AppendCreateLink(){
	JDFCreateLink e=AppendElement(elm_CreateLink);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCreateResource JDFAutoUpdateJDFCmdParams::GetCreateResource(int iSkip)const{
	JDFCreateResource e=GetElement(elm_CreateResource,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCreateResource JDFAutoUpdateJDFCmdParams::GetCreateCreateResource(int iSkip){
	JDFCreateResource e=GetCreateElement(elm_CreateResource,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCreateResource JDFAutoUpdateJDFCmdParams::AppendCreateResource(){
	JDFCreateResource e=AppendElement(elm_CreateResource);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMoveResource JDFAutoUpdateJDFCmdParams::GetMoveResource(int iSkip)const{
	JDFMoveResource e=GetElement(elm_MoveResource,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMoveResource JDFAutoUpdateJDFCmdParams::GetCreateMoveResource(int iSkip){
	JDFMoveResource e=GetCreateElement(elm_MoveResource,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMoveResource JDFAutoUpdateJDFCmdParams::AppendMoveResource(){
	JDFMoveResource e=AppendElement(elm_MoveResource);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRemoveLink JDFAutoUpdateJDFCmdParams::GetRemoveLink(int iSkip)const{
	JDFRemoveLink e=GetElement(elm_RemoveLink,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRemoveLink JDFAutoUpdateJDFCmdParams::GetCreateRemoveLink(int iSkip){
	JDFRemoveLink e=GetCreateElement(elm_RemoveLink,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRemoveLink JDFAutoUpdateJDFCmdParams::AppendRemoveLink(){
	JDFRemoveLink e=AppendElement(elm_RemoveLink);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNode JDFAutoUpdateJDFCmdParams::GetNode(int iSkip)const{
	JDFNode e=GetElement(elm_JDF,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNode JDFAutoUpdateJDFCmdParams::GetCreateNode(int iSkip){
	JDFNode e=GetCreateElement(elm_JDF,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNode JDFAutoUpdateJDFCmdParams::AppendNode(){
	JDFNode e=AppendElement(elm_JDF);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoUpdateJDFCmdParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_CreateLink);

		for(i=0;i<nElem;i++){
			if (!GetCreateLink(i).IsValid(level)) {
				vElem.AppendUnique(elm_CreateLink);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_RemoveLink);

		for(i=0;i<nElem;i++){
			if (!GetRemoveLink(i).IsValid(level)) {
				vElem.AppendUnique(elm_RemoveLink);
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
	WString JDFAutoUpdateJDFCmdParams::OptionalElements()const{
		return JDFElement::OptionalElements()+L",CreateLink,CreateResource,MoveResource,RemoveLink,JDF";
	};
}; // end namespace JDF
