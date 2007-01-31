/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001 The International Cooperation for the Integration of 
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
/*
*
*
* COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
*      ALL RIGHTS RESERVED 
*
*  Author: Dr. Rainer Prosi using JDFSchema code generator 
* 
* Warning! preliminary version. Interface subject to change without prior notice!
* Revision history:
* created 2001-12-17
* based on JDF Schema version JDFCore_1_0_0.xsd
*
*/
#include "JDFPreflightResultsPool.h"
#include "JDFPreflightInstance.h"
#include "JDFPreflightDetail.h"
namespace JDF{
/*
*********************************************************************
class JDFPreflightResultsPool : public JDFPool

  *********************************************************************
	*/
	JDFPreflightResultsPool & JDFPreflightResultsPool::operator =(const KElement& other){
		KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFPreflightResultsPool: "+other.GetNodeName()); 
		return *this;
	};
	
	/**
	* typesafe validator utility - list of valid node names for this class 
	* @return WString& comma separated list of valid node names
	*/
	
	WString JDFPreflightResultsPool::ValidNodeNames()const{
		return L"*:,ColorsResultsPool,DocumentResultsPool,FontsResultsPool,FileTypeResultsPool,ImagesResultsPool,PagesResultsPool";
	};
	
	
	/* ******************************************************
	// Attribute Getter / Setter
	****************************************************** */
	
	
	/**
	typesafe validator
	*/
	
	
	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */
	
	
	JDFPreflightDetail JDFPreflightResultsPool::GetCreatePreflightDetail(int iSkip){
		JDFPreflightDetail e=GetCreateElement(L"PreflightDetail",L"",iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFPreflightDetail JDFPreflightResultsPool::AppendPreflightDetail(){
		JDFPreflightDetail e=AppendElement(L"PreflightDetail");
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	/*
	const get first element 
	*/
	JDFPreflightDetail JDFPreflightResultsPool::GetPreflightDetail(int iSkip)const{
		return GetElement(L"PreflightDetail",L"",iSkip);
	};

	/////////////////////////////////////////////////////////////////////
	/*
	const get first element 
	*/
	JDFPreflightInstance JDFPreflightResultsPool::GetPreflightInstance(int iSkip)const{
		return GetElement(L"PreflightInstance",L"",iSkip);
	};
	
	/////////////////////////////////////////////////////////////////////
	JDFPreflightInstance JDFPreflightResultsPool::GetCreatePreflightInstance(int iSkip){
		JDFPreflightInstance e=GetCreateElement(L"PreflightInstance",L"",iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFPreflightInstance JDFPreflightResultsPool::AppendPreflightInstance(){
		JDFPreflightInstance e=AppendElement(L"PreflightInstance");
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	/**
	typesafe validator
	*/
	vWString JDFPreflightResultsPool::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFPool::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax) 
			return vElem;

		nElem=NumChildElements(L"PreflightDetail");
		for(i=0;i<nElem;i++){
			JDFPreflightDetail child=GetElement(L"PreflightDetail",L"",i);
			if (child.IsRefElement()) 
				continue;
			if (!child.IsValid(level)) {
				vElem.AppendUnique(L"PreflightDetail");
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(L"PreflightInstance");
		for(i=0;i<nElem;i++){
			JDFPreflightInstance child=GetElement(L"PreflightInstance",L"",i);
			if (child.IsRefElement()) 
				continue;
			if (!child.IsValid(level)) {
				vElem.AppendUnique(L"PreflightInstance");
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
	WString JDFPreflightResultsPool::OptionalElements()const{
		return JDFPool::OptionalElements()+L",PreflightDetail,PreflightInstance";
	};
}; // end namespace JDF
