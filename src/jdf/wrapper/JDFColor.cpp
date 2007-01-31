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


///////////////////////////////////////////////////////////////////


#include "JDFColor.h"
#include "JDFFileSpec.h"

namespace JDF{
/**
* copy equivalance operator
	*/
	JDFColor& JDFColor::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFColor: "+other.GetNodeName());
		return *this;
	};
	
	///////////////////////////////////////////////////////////////////
	
	/** 
	* Set the Name and RawName attributes to the value given in pName
	* The value in Name uses the default encoding
	* @param pName the 8 bit string to set the name to
	*/
	void JDFColor::Set8BitNames(const char* pName){
		WString rawName;
		rawName.SetHexBinaryBytes(pName);
		SetAttribute(atr_RawName,rawName);
		SetName(WString(pName));
	}
	
	///////////////////////////////////////////////////////////////////
	
	
	/**
	* Gets the 16 bit representation of the 8 bit color name
	* Use WString::GetRawBytes() to extract the 8 bit representation
	* @return WString the 8 bit Name of the color extracted from RawName, or if this is missing from Name, using the default transcoder
	*/
	WString JDFColor::Get8BitName()const{
		WString name;
		if(HasAttribute(atr_RawName)){
			name=GetAttribute(atr_RawName);
			name.SetRawBytes(name.GetHexBinaryBytes());
		}else{
			name=GetName();
			name.SetRawBytes(name.peekBytes());
		}
		return name;
	}
	
	///////////////////////////////////////////////////////////////////

	JDFFileSpec JDFColor::GetColorProfile() const{
		
		vElement v=GetChildElementVector(elm_FileSpec);
		
		int siz=v.size();
		for(int i=0;i<siz;i++)
		{
			JDFFileSpec res=v[i];
			if (res.HasAttribute(atr_ResourceUsage)) {
				if (res.GetResourceUsage()==L"ColorProfile")
				{
					return res;
				}	
			}
		}
		return JDFFileSpec();
	};

	///////////////////////////////////////////////////////////////////
	
	JDFFileSpec JDFColor::GetCreateColorProfile() {
		
		JDFFileSpec res=GetColorProfile();
		if (res.isNull()) 
		{
			res=AppendColorProfile();
		}
		return res;
	}

	///////////////////////////////////////////////////////////////////
	
	JDFFileSpec JDFColor::AppendColorProfile() {

		JDFFileSpec res=AppendFileSpec();
		res.SetResourceUsage(L"ColorProfile");

		return res;
	}
	
	///////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////

	JDFFileSpec JDFColor::GetTargetProfile() const{
		
		vElement v=GetChildElementVector(elm_FileSpec);
		
		int siz=v.size();
		for(int i=0;i<siz;i++)
		{
			JDFFileSpec res=v[i];
			if (res.HasAttribute(atr_ResourceUsage)) {
				if (res.GetResourceUsage()==L"TargetProfile")
				{
					return res;
				}	
			}
		}
		return JDFFileSpec();
	};

	///////////////////////////////////////////////////////////////////
	
	JDFFileSpec JDFColor::GetCreateTargetProfile() {
		
		JDFFileSpec res=GetTargetProfile();
		if (res.isNull()) 
		{
			res=AppendTargetProfile();
		}
		return res;
	}

	///////////////////////////////////////////////////////////////////
	
	JDFFileSpec JDFColor::AppendTargetProfile() {

		JDFFileSpec res=AppendFileSpec();
		res.SetResourceUsage(L"TargetProfile");

		return res;
	}

	///////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////

	vWString JDFColor::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
	
		vWString vElem;
		int n=0;
		int nElem=NumChildElements(elm_FileSpec);

		if(nElem>2){ //bound error
			vElem.AppendUnique(elm_FileSpec);
			if (++n>=nMax)
				return vElem;
		}
		for(int i=0;i<nElem;i++){

			WString ru=GetFileSpec(i).GetResourceUsage();
			if ((ru!=L"ColorProfile")&&(ru!=L"TargetProfile")) 
			{
				vElem.AppendUnique(elm_FileSpec);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		vElem.AppendUnique(JDFAutoColor::GetInvalidElements(level, bIgnorePrivate, (nMax-n)));

		return vElem;
	}

	///////////////////////////////////////////////////////////////////

}; // namespace JDF
