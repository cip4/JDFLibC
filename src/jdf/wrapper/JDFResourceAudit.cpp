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

  //
  // COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
  //      ALL RIGHTS RESERVED 
  //
  //  Author: Dr. Rainer Prosi using JDFSchema code generator 
  // 
  // Warning! very preliminary test version. Interface subject to change without prior notice!
  // Revision history:
  // created 2001-02-26
  //
*/

#include "JDFResourceAudit.h"
#include "JDFResourceLink.h"

namespace JDF{

	
	/////////////////////////////////////////////////////////////////////////////////////////

	JDFResourceAudit &JDFResourceAudit::operator =(const KElement& other){
		JDFAutoResourceAudit::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFResourceAudit: "+other.GetNodeName()); 
		return *this;
	};

	/////////////////////////////////////////////////////////////////////////////////////////

	/**
	typesafe validator
	*/
	vWString JDFResourceAudit::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int i=0;
		vWString vElem=JDFAutoResourceAudit::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax) 
			return vElem;

		vWString vUnknownElems=GetUnknownElements(bIgnorePrivate,nMax);
		// check for resource links and allow them
		int nLink=0;
		//max 2 links;
		for(i=0;i<vUnknownElems.size();i++){
			JDFElement el=GetElement(vUnknownElems[i]);
			if(el.IsComment())
				continue;
			if(!el.IsResourceLink()){
				vElem.AppendUnique(vUnknownElems[i]);
			}
			for(int j=0;j<2;j++){
				JDFResourceLink l=GetElement(vUnknownElems[i],WString::emptyStr,j);
				nLink++;
				if(l.IsValid()&&(nLink<3)) {
					continue;
				}else{
					vElem.AppendUnique(vUnknownElems[i]);
				}
			}
		}
		return vElem;
	};
	
	/////////////////////////////////////////////////////////////////////////////////////////
	
	JDFResourceLink JDFResourceAudit::GetNewLink()const{
		return GetNewOldLink(true);
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////
	
	JDFResourceLink JDFResourceAudit::GetOldLink()const{
		return GetNewOldLink(false);
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////
	
	vElement JDFResourceAudit::GetResourceLinkVector()const {
		vElement v=GetChildElementVector();
		for(int i=v.size()-1;i>=0;i--){
			JDFElement e=v[i];
			if(!e.IsResourceLink()){
				v.erase(v.begin()+i);
			}
		}
		return v;
	}
	/////////////////////////////////////////////////////////////////////////////////////////
	
	JDFResourceLink JDFResourceAudit::GetNewOldLink(bool bNew)const {
		vElement v=GetResourceLinkVector();
		int iNew=bNew?0:1;
		if (v.size()<iNew) 
			return JDFResourceLink();
		JDFResourceLink rl=v[iNew];
		return rl;
		
	}
	/////////////////////////////////////////////////////////////////////////////////////////
	
	
	JDFResourceLink JDFResourceAudit::AddNewLink(const JDFResource & r, bool bInput){
		return AddNewOldLink(true,r,bInput);
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////
	
	JDFResourceLink JDFResourceAudit::AddOldLink(const JDFResource & r, bool bInput){
		return AddNewOldLink(false,r,bInput);
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////
	
	JDFResourceLink JDFResourceAudit::AddNewOldLink(bool bNew, const JDFResource & r, bool bInput){
		return addNewOldLink(bNew,r,bInput ? JDFResourceLink::Usage_Input :  JDFResourceLink::Usage_Output);
	}
	/////////////////////////////////////////////////////////////////////////////////////////
	
	JDFResourceLink JDFResourceAudit::addNewOldLink(bool bNew, const JDFResource & r, JDFResourceLink::EnumUsage usage){
		vElement v=GetResourceLinkVector();
		int iNew=bNew?0:1;
		if (v.size()!=iNew) 
			throw JDFException(L"JDFResourceLink::AddNewOldLink invalid  ResourceAudit");

		JDFResourceLink l=AppendElement(r.GetLinkString());
		l.SetTarget(r);
		if(usage!=JDFResourceLink::Usage_Unknown)
			l.SetUsage(usage);	
		return l;
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////	
	
	vWString JDFResourceAudit::GetUnknownElements(bool bIgnorePrivate,int nMax)const{
		vElement v=GetChildElementVector();
		vWString vElem;
		int n=0;
		for(int i=0;i<v.size();i++){
			JDFElement e=v[i];
			if(e.IsComment()) 
				continue;
			if(e.IsResourceLink()) 
				continue;
			vElem.push_back(e.GetNodeName());
			if(++n>nMax) 
				return vElem;
		}
		return vElem;
	};

	/////////////////////////////////////////////////////////////////////////////////////////

	JDFResourceLink JDFResourceAudit::UpdateLink(const JDFResourceLink & newLink){
		vElement v=GetResourceLinkVector();
		if (v.size()>2)
			throw JDFException(L"JDFResourceLink::UpdateLink invalid  ResourceAudit");
		
		// update of an update, delete the first element and assume the second is the real original
		if(v.size()>1){
			v[0].DeleteNode();
			v.erase(v.begin());
		}

		// the updated link is the first
		JDFResourceLink resLink=CopyElement(newLink);
		if(v.size()>0){
			InsertBefore(resLink,v[0]);
		}
		return resLink;
	}
		
	/////////////////////////////////////////////////////////////////////////////////////////

}