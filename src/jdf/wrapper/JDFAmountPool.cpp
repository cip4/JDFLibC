/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2002 The International Cooperation for the Integration of 
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
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created 110202
//
// JDFAmountPool.cpp: implementation of the JDFAmountPool class.
//
//////////////////////////////////////////////////////////////////////
#include "JDFAmountPool.h"
#include "JDFPartAmount.h"
using namespace std;
namespace JDF{
	
	//////////////////////////////////////////////////////////////////////
	
	JDFAmountPool& JDFAmountPool::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFAmountPool: "+other.GetNodeName()); 
		return *this;
	};
	
	
	
	//////////////////////////////////////////////////////////////////////
	
	JDFPartAmount JDFAmountPool::GetPartAmount(const mAttribute&mPart)const{
		vElement vPartAmount=GetChildElementVector(elm_PartAmount);
		for(int i=vPartAmount.size()-1;i>=0;i--){
			JDFPartAmount ps=vPartAmount[i];
			mAttribute mapPart=ps.GetPartMap();
			
			if(mapPart==mPart) 
				return ps; // exact match
		}
		return JDFPartAmount();
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFPartAmount JDFAmountPool::GetPartAmount(int iSkip)const{
		return JDFAutoAmountPool::GetPartAmount(iSkip);
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFPartAmount JDFAmountPool::GetCreatePartAmount(int iSkip){
		return JDFAutoAmountPool::GetCreatePartAmount(iSkip);
	}
	
	//////////////////////////////////////////////////////////////////////
		
	JDFPartAmount JDFAmountPool::GetCreatePartAmount(const mAttribute&mPart){
		JDFPartAmount p=GetPartAmount(mPart);
		if(p.isNull()) {
			p=AppendElement(elm_PartAmount);
			p.SetPartMap(mPart);
		}
		return p;
	}
	
	/////////////////////////////////////////////////////////////////////

	JDFPartAmount JDFAmountPool::AppendPartAmount(const mAttribute&mPart){
		JDFPartAmount p=JDFAutoAmountPool::AppendPartAmount();
		p.SetPartMap(mPart);
		return p;
	};

	//////////////////////////////////////////////////////////////////////

	JDFPartAmount JDFAmountPool::AppendPartAmount(const vmAttribute &vPart){
		JDFPartAmount p=JDFAutoAmountPool::AppendPartAmount();
		p.SetPartMapVector(vPart);
		return p;
	};

	//////////////////////////////////////////////////////////////////////
	
	void JDFAmountPool::RemovePartAmount(const mAttribute&mPart){
		GetPartAmount(mPart).DeleteNode();
	};
	//////////////////////////////////////////////////////////////////////

	vElement JDFAmountPool::GetMatchingPartAmountVector(const mAttribute&mPart)const{
		vElement vPA;
		vElement vPartAmount=GetChildElementVector(elm_PartAmount);
		for(unsigned int i=0;i<vPartAmount.size();i++){
			JDFPartAmount ps=vPartAmount[i];
			mAttribute m=ps.GetPartMap();
			if(m.SubMap(mPart)){
				vPA.push_back(ps);
			}
		}
		return vPA;
	}

	//////////////////////////////////////////////////////////////////////
	
	vElement JDFAmountPool::GetPartAmountVector(const vmAttribute&vmPart)const{
		vElement vPartAmount;
		for(unsigned int i=0;i<vmPart.size();i++){
			JDFPartAmount ps=GetPartAmount(vmPart[i]);
			if(!ps.isNull()) 
				vPartAmount.push_back(ps);
		}
		return vPartAmount;
	}
	//////////////////////////////////////////////////////////////////////
	vElement JDFAmountPool::GetCreatePartAmountVector(const vmAttribute&vmPart){
		vElement vPartAmount;
		for(unsigned int i=0;i<vmPart.size();i++){
			JDFPartAmount ps=GetCreatePartAmount(vmPart[i]);
			vPartAmount.push_back(ps);
		}
		return vPartAmount;
	}
	//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAmountPool::GetPartMapVector()const{
		vmAttribute v;
		vElement vE=KElement::GetChildElementVector(elm_PartAmount);
		for(unsigned int i=0;i<vE.size();i++){
			JDFPartAmount pa=vE[i];
			mAttribute ma=pa.GetPartMap();
			if(!ma.empty())
				v.push_back(ma);
		}
		return v;
	}
	
}
