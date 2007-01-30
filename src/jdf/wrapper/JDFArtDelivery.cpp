/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2004 The International Cooperation for the Integration of 
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


#include "JDFArtDelivery.h"
#include "JDFArtDeliveryIntent.h"
#include "JDFCompany.h"
#include "JDFContact.h"

namespace JDF{
	
	//////////////////////////////////////////////////////////////////////
	/**
	* copy equivalance operator
	*/
	JDFArtDelivery& JDFArtDelivery::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFArtDelivery: "+other.GetNodeName());
		return *this;
	};
	///////////////////////////////////////////////////////////////////////
	const WString& JDFArtDelivery::ArtDeliveryTypeString(){
		static const WString enums=WString(L"Unknown,DigitalMedia,DigitalNetwork,ExposedPlate,ImposedFilm,LooseFilm,OriginalPhysicalArt,Proof,Tool,None");
		return enums;
	};
	
	///////////////////////////////////////////////////////////////////////
	
	WString JDFArtDelivery::ArtDeliveryTypeString(EnumArtDeliveryType value){
		return ArtDeliveryTypeString().Token(value,WString::comma);
	};
	
	/////////////////////////////////////////////////////////////////////////
	void JDFArtDelivery::SetEnumArtDeliveryType( EnumArtDeliveryType value){
		SetEnumAttribute(atr_ArtDeliveryType,value,ArtDeliveryTypeString());
	};
	/////////////////////////////////////////////////////////////////////////
	JDFArtDelivery::EnumArtDeliveryType JDFArtDelivery:: GetEnumArtDeliveryType() const {
		return (EnumArtDeliveryType) GetEnumAttribute(atr_ArtDeliveryType,ArtDeliveryTypeString(),WString::emptyStr);
		
	};//////////////////////////////////////////////////////////////////////
	JDFArtDeliveryIntent JDFArtDelivery::GetParentArtDeliveryIntent() const {
		return GetParentNode();
	};
	//////////////////////////////////////////////////////////////////////
	JDFSpanArtHandling JDFArtDelivery::GetArtHandling()const{
		if(HasChildElement(elm_ArtHandling))
			return JDFAutoArtDelivery::GetArtHandling();
		return GetParentArtDeliveryIntent().GetArtHandling();
	};
	//////////////////////////////////////////////////////////////////////
	JDFSpanDeliveryCharge JDFArtDelivery::GetDeliveryCharge()const{
		if(HasChildElement(elm_DeliveryCharge))
			return JDFAutoArtDelivery::GetDeliveryCharge();
		return GetParentArtDeliveryIntent().GetDeliveryCharge();
	};
	//////////////////////////////////////////////////////////////////////
	JDFNameSpan JDFArtDelivery::GetMethod()const{
		if(HasChildElement(elm_Method))
			return JDFAutoArtDelivery::GetMethod();
		return GetParentArtDeliveryIntent().GetMethod();
	};
	//////////////////////////////////////////////////////////////////////
	JDFArtDelivery::EnumPreflightStatus JDFArtDelivery::GetPreflightStatus()const{
		if(HasAttribute(atr_PreflightStatus))
			return JDFAutoArtDelivery::GetPreflightStatus();
		return (JDFArtDelivery::EnumPreflightStatus)GetParentArtDeliveryIntent().GetPreflightStatus();
	};
	//////////////////////////////////////////////////////////////////////
	JDFNameSpan JDFArtDelivery::GetReturnMethod()const{
		if(HasChildElement(elm_ReturnMethod))
			return JDFAutoArtDelivery::GetReturnMethod();
		return GetParentArtDeliveryIntent().GetReturnMethod();
	};
	//////////////////////////////////////////////////////////////////////
	JDFStringSpan JDFArtDelivery::GetServiceLevel()const{
		if(HasChildElement(elm_ServiceLevel))
			return JDFAutoArtDelivery::GetServiceLevel();
		return GetParentArtDeliveryIntent().GetServiceLevel();
	};
	//////////////////////////////////////////////////////////////////////
	JDFSpanTransfer JDFArtDelivery::GetTransfer()const{
		if(HasChildElement(elm_Transfer))
			return JDFAutoArtDelivery::GetTransfer();
		return GetParentArtDeliveryIntent().GetTransfer();
	};
	//////////////////////////////////////////////////////////////////////
	JDFContact JDFArtDelivery::GetContact(int iSkip)const{
		if(HasChildElement(elm_Contact,WString::emptyStr)) 
			return JDFAutoArtDelivery::GetContact(iSkip);
		return GetParentArtDeliveryIntent().GetContact();
	};
	//////////////////////////////////////////////////////////////////////
	
}; // namespace JDF
