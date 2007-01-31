/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2005 The International Cooperation for the Integration of 
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
* created 2002-11-08
* based on JDF Schema version JDF_1_1_RM.xsd
*
*/
#include "JDFPipeParams.h"
#include "JDFResourceLink.h"

namespace JDF{
/**
* copy equivalance operator
	*/
	JDFPipeParams& JDFPipeParams::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFPipeParams: "+other.GetNodeName());
		return *this;
	};
	
	//////////////////////////////////////////////////////////////////////////////////////////////
	
	vElement JDFPipeParams::GetResourceLinks(const WString & name, const mAttribute&mAttrib, const WString& nameSpaceURI)const{
		vElement v=GetChildElementVector(name,nameSpaceURI,mAttrib,true);
		for(int i=v.size()-1;i>=0;i--){
			JDFElement e=v[i];
			if(!e.IsResourceLink()){
				v.erase(v.begin()+i);
			}
		}
		return v;
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////
	
	vWString JDFPipeParams::GetUnknownElements(bool bIgnorePrivate,int nMax)const{
		return GetUnknownPoolElements(PoolType_PipeParams,bIgnorePrivate,nMax);
	};
	//////////////////////////////////////////////////////////////////////////////////////////////
	JDFResource JDFPipeParams::GetResource(const WString &resName)const{
		JDFResource e=GetElement(resName,WString::emptyStr);
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFResource JDFPipeParams::GetCreateResource(const WString &resName){
		JDFResource e=GetCreateElement(resName,WString::emptyStr);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFResource JDFPipeParams::AppendResource(const WString &resName){
		JDFResource e=AppendElement(resName);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
}; // namespace JDF
