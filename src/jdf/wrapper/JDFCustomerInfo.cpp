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
//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
//
// JDFCustomerInfo.cpp: implementation of the JDFCustomer class.
//
//////////////////////////////////////////////////////////////////////

#include "JDFCustomerInfo.h"
#include "JDFCompany.h"
#include "JDFContact.h"
#include "JDFRefElement.h"

using namespace std;
namespace JDF{

	//////////////////////////////////////////////////////////////////////
	// Construction/Destruction
	//////////////////////////////////////////////////////////////////////

	JDFCustomerInfo & JDFCustomerInfo::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFCustomerInfo: "+other.GetNodeName()); 
		return *this;
	};


	//////////////////////////////////////////////////////////////////////

	vElement JDFCustomerInfo::GetLinkedResources(const mAttribute &mResAtt, bool bFollowRefs)const{
		vElement v=GetChildElementVector();
		vElement vL;
		for(int i=0;i<v.size();i++){
			if(!JDFElement(v[i]).IsRefElement())
				continue;
			JDFRefElement l=v[i];
			JDFResource r=l.GetTarget();
			r=r.GetResourceRoot();
			if(r.IncludesAttributes(mResAtt)) {
				vL.push_back(r);
				if(bFollowRefs){
					vL.AppendUnique(r.GetvHRefRes(bFollowRefs));
				}
			}
		}
		return vL;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFCustomerInfo::init(){
		bool bRet=true;
		if(GetParentNode().GetLocalName()==elm_ResourcePool){
			bRet=JDFResource::init();
			SetPartUsage(JDFResource::PartUsage_Implicit);
			SetStatus(JDFResource::EnumStatus::Status_Available);
			SetClass(Class_Parameter);
		}
		return bRet;
	};
	//////////////////////////////////////////////////////////////////////
    /**
     * get a Contact with at least one contacttype set
     * @param contactType the contatcttype string
     * @param iSkip, number of occurrences to skip - if 0 take the first
     * @return a matching JDFContact, null if none are found
     */
	JDFContact JDFCustomerInfo::GetContactWithContactType(const WString& contactType,int iSkip) const
    {
        vElement v=GetChildElementVector(elm_Contact);
        int siz=v.size();
        int n=0;
        for(int i=0;i<siz;i++)
        {
            JDFContact contact=v[i];
            vWString contactTypes=contact.GetContactTypes();
            if(contactTypes.hasString(contactType)){
                if(iSkip==n++){
                    return contact;
                }
            }
        }
        return JDFContact();
    }

	vElement JDFCustomerInfo::getContactVectorWithContactType(const WString& contactType)const
    {
		vElement v=GetChildElementVector(elm_Contact);
        vElement v2;
        int siz=v.size();
        for(int i=0;i<siz;i++)
        {
            JDFContact contact=(JDFContact)v.elementAt(i);
            vWString contactTypes=contact.GetContactTypes();
            if(contactTypes.contains(contactType)){
               v2.add(contact);
            }
        }
        return v2;
	}
 
}