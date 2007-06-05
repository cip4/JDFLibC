/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2007 The International Cooperation for the Integration of 
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
* Warning! very preliminary test version. Interface subject to change without prior notice!
* Revision history:
* created 2001-07-11
*
*/

#include "JDFSheet.h"
#include "JDFSurface.h"
#include "JDFLayout.h"

namespace JDF{
	////////////////////////////////////////////////////////////////////////////////////////////////////////

	JDFSheet &JDFSheet::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFSheet: "+other.GetNodeName()); 
		return *this;
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////////

	vWString JDFSheet::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFSignature::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if (n>=nMax) return vElem;

		// only for JDF version < 1.3
		EnumVersion ver = GetEnumVersion();
		if (ver != Version_Unknown && ver < Version_1_3)
		{
			nElem=NumChildElements(elm_Surface);
			if(nElem>2){
				vElem.AppendUnique(elm_Surface);
				if (++n>=nMax) return vElem;
			}
			if(nElem==0){
				if(RequiredLevel(level))
					vElem.AppendUnique(elm_Surface);
				if (++n>=nMax) return vElem;
			}
		}

		int nFront=0;
		int nBack=0;
		for(i=0;i<nElem;i++){
			JDFSurface child=GetElement(elm_Surface,WString::emptyStr,i);
			if (child.IsRefElement()) continue;
			if(child.GetSide()==JDFPart::Side_Front)
				nFront++;
			if(child.GetSide()==JDFPart::Side_Back)
				nBack++;
		}
		if((nFront>1)||(nBack>1)){
			vElem.AppendUnique(elm_Surface);
			if (++n>=nMax) return vElem;
		}
		return vElem;
	};
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	JDFSurface JDFSheet::GetCreateFrontSurface(){
		JDFSurface e=GetFrontSurface();
		if(e.isNull()){
			e=AppendFrontSurface();
		}
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFSurface JDFSheet::AppendFrontSurface(){
		JDFSurface e=GetFrontSurface();
		if(e.isNull()){
			e=appendSurface();
			e.SetSide(JDFPart::Side_Front);
		}

		return e;
	};
	/////////////////////////////////////////////////////////////////////
	/*
	const get first element 
	*/
	JDFSurface JDFSheet::GetFrontSurface()const{
		return GetSurfaceBySide(JDFPart::Side_Front);
	};
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	void JDFSheet::RemoveFrontSurface(){
		GetFrontSurface().DeleteNode();
	};
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool JDFSheet::HasFrontSurface() const {
		return !GetSurfaceBySide(JDFPart::Side_Front).isNull();
	};
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	JDFSurface JDFSheet::GetCreateBackSurface(){
		JDFSurface e=GetBackSurface();
		if(e.isNull()){
			e=AppendBackSurface();
		}
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFSurface JDFSheet::AppendBackSurface(){
		JDFSurface e=GetBackSurface();
		if(e.isNull()){
			e=appendSurface();
			e.SetSide(JDFPart::Side_Back);
		}
		else
		{
			throw JDFException("AppendBackSurface: BackSurface already exists");
		}

		return e;
	};
	/////////////////////////////////////////////////////////////////////
	/*
	const get first element 
	*/
	JDFSurface JDFSheet::GetBackSurface()const{
		return GetSurfaceBySide(JDFPart::Side_Back);
	};
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	void JDFSheet::RemoveBackSurface(){
		GetBackSurface().DeleteNode();
	};
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool JDFSheet::HasBackSurface() const {
		return !GetSurfaceBySide(JDFPart::Side_Back).isNull();
	};
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	JDFSurface JDFSheet::appendSurface()
	{
		if (numSurfaces() > 1)
			throw JDFException("appendSurfaces: sheet already has two surfaces");

		return appendLayoutElement(*this,elm_Surface,atr_Side);;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	int JDFSheet::numSurfaces()const
	{
		return numLayoutElements(*this,elm_Surface,atr_Side);
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	JDFSurface JDFSheet::GetSurface(int iSkip)const{
		return getLayoutElement(*this,elm_Surface,atr_Side,iSkip);
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	WString JDFSheet::ValidNodeNames()const{
		return L"*:,Sheet,Layout";
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	JDFSurface JDFSheet::GetSurfaceBySide(JDFPart::EnumSide side) const
	{
		JDFSurface s = GetSurface(0);
		if (s.isNull())
			return JDFSurface();
		if (s.GetSide()==side)
			return s;
		s=GetSurface(1);
		if (s.GetSide()==side)
			return s;
		return JDFSurface();
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	WString JDFSheet::GetSheetName() const
	{
		if(GetLocalName() == JDFElement::elm_Sheet)
		{
			return GetName();
		}
		if(GetLocalName() == JDFElement::elm_Surface)
		{
			JDFSheet sh=(JDFSheet)KElement::GetParentNode();
			return sh.GetSheetName();
		}
		return JDFResource::GetSheetName();
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	* get the vector of sheets in this signature
	* @return {@link VElement} the vector of signatures in this
	*/
	VElement JDFSheet::getSurfaceVector()const
	{
		return getLayoutElementVector(*this,elm_Surface,atr_Side);
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////

}; // namespace JDF
