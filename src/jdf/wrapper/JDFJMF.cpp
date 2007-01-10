/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2006 The International Cooperation for the Integration of 
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
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created  17.Feb.2000
//
//
// JDFJMF.cpp: implementation of the JDFJMF class.
//
//////////////////////////////////////////////////////////////////////

#include "JDFJMF.h"
#include "JDFNode.h"
#include "JDFMessage.h"
#include "JDFQuery.h"
#include "JDFCommand.h"
#include "JDFResponse.h"
#include "JDFSignal.h"
#include "JDFAcknowledge.h"
#include "JDFRegistration.h"

using namespace std;
namespace JDF{

	//////////////////////////////////////////////////////////////////////
	// Construction/Destruction
	//////////////////////////////////////////////////////////////////////
	JDFJMF::JDFJMF():JDFAutoJMF(){};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFJMF &JDFJMF::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFJMF: "+other.GetNodeName()); 
		return *this;
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	bool JDFJMF::ValidVersion(EnumValidationLevel level) const {
		WString version=GetVersion();
		if(version.empty())
			return !RequiredLevel(level);
		return VersionString().HasToken(version,WString::comma);

	};
	///////////////////////////////////////////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////////////////////////////////////////

	vElement JDFJMF::GetMessageVector(JDFMessage::EnumFamily family,JDFMessage::EnumType typ)const{
		vElement vM;
		WString sFamily=(family!=JDFMessage::Family_Unknown)?JDFMessage::FamilyString(family):WString::star;
		if(typ!=JDFMessage::Type_Unknown){
			vM=GetChildrenWithAttribute(sFamily,atr_Type,WString::emptyStr,JDFMessage::TypeString(typ));
		}else{
			vM=GetChildElementVector(sFamily);
		}
		if(family==JDFMessage::Family_Unknown){
			// do reverse iteration because erase invalidates
			for(int i=vM.size()-1;i>=0;i--){
				JDFMessage& m=(JDFMessage&)vM[i];
				if(!m.IsMessageElement()){
					vM.erase(vM.begin()+i);
				}
			}
		}
		return vM;

	}
	//////////////////////////////////////////////////////////////////////

	int JDFJMF::NumMessages(JDFMessage::EnumFamily family, JDFMessage::EnumType typ)const{
		return GetMessageVector(family,typ).size();
	}

	//////////////////////////////////////////////////////////////////////

	JDFMessage JDFJMF::GetCreateMessageElement(JDFMessage::EnumFamily family, int i){
		JDFMessage m=GetMessageElement(family, i);
		if(!m.isNull())
			return m;
		return AppendMessageElement(family);
	}
	//////////////////////////////////////////////////////////////////////

	JDFMessage JDFJMF::AppendMessageElement(JDFMessage::EnumFamily family){
		if((family==JDFMessage::Family_Unknown)){
			throw JDFException("GetMessageElement: creating undefined message family");
		}

		JDFMessage m;
		WString sFamily=JDFMessage::FamilyString(family);
		if(family==JDFMessage::Family_Response){
			JDFResponse r=AppendElement(sFamily);
			r.init();
			m=r;
		}else if(family==JDFMessage::Family_Query){
			JDFQuery q=AppendElement(sFamily);
			q.init();
			m=q;
		}else if(family==JDFMessage::Family_Signal){
			JDFSignal q=AppendElement(sFamily);
			q.init();
			m=q;
		}else if(family==JDFMessage::Family_Command){
			JDFCommand q=AppendElement(sFamily);
			q.init();
			m=q;
		}else if(family==JDFMessage::Family_Acknowledge){
			JDFAcknowledge q=AppendElement(sFamily);
			q.init();
			m=q;
		}else if(family==JDFMessage::Family_Registration){
			JDFRegistration q=AppendElement(sFamily);
			q.init();
			m=q;
		}
		return m;
	}

	//////////////////////////////////////////////////////////////////////

	JDFMessage JDFJMF::GetMessageElement(JDFMessage::EnumFamily family, int i)const{


		vElement vM;
		// not necessary for append
		vM=GetMessageVector(family);
		if(i<vM.size()) {
			return vM[i];
		}
		// none there
		return JDFMessage();
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFJMF::init(){
		JDFAutoJMF::init();
		SetTimeStamp();
		AddNameSpace(WString::emptyStr,GetSchemaURL(1,1));
		SetEnumVersion(getDefaultJDFVersion());

		return true;
	}
	//////////////////////////////////////////////////////////////////////

	void JDFJMF::SetEnumVersion(EnumVersion value)
	{
		SetEnumAttribute(atr_Version,value,JDFNode::VersionString());
	};

	//////////////////////////////////////////////////////////////////////
	JDFMessage JDFJMF::GetAnyMessage(int i)const{
		vElement vM=GetMessageVector(JDFMessage::Family_Unknown);
		if(i<0)
			i+=vM.size();
		if((i<0)||(i>=vM.size()))
			return JDFMessage();
		return vM[i];
	};
	//////////////////////////////////////////////////////////////////////
	JDFQuery JDFJMF::GetQuery(int i)const{
		return GetMessageElement(JDFMessage::Family_Query,i);
	};
	//////////////////////////////////////////////////////////////////////
	JDFResponse JDFJMF::GetResponse(int i)const{
		return GetMessageElement(JDFMessage::Family_Response,i);
	};
	//////////////////////////////////////////////////////////////////////
	JDFSignal JDFJMF::GetSignal(int i)const{
		return GetMessageElement(JDFMessage::Family_Signal,i);
	};
	//////////////////////////////////////////////////////////////////////
	JDFCommand JDFJMF::GetCommand(int i)const{
		return GetMessageElement(JDFMessage::Family_Command,i);
	};
	//////////////////////////////////////////////////////////////////////
	JDFAcknowledge JDFJMF::GetAcknowledge(int i)const{
		return GetMessageElement(JDFMessage::Family_Acknowledge,i);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	JDFRegistration JDFJMF::GetRegistration(int i)const{
		return GetMessageElement(JDFMessage::Family_Registration,i);
	};
	//////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////
	JDFQuery JDFJMF::GetCreateQuery(int i){
		return GetCreateMessageElement(JDFMessage::Family_Query,i);
	};
	//////////////////////////////////////////////////////////////////////
	JDFResponse JDFJMF::GetCreateResponse(int i){
		return GetCreateMessageElement(JDFMessage::Family_Response,i);
	};
	//////////////////////////////////////////////////////////////////////
	JDFSignal JDFJMF::GetCreateSignal(int i){
		return GetCreateMessageElement(JDFMessage::Family_Signal,i);
	};
	//////////////////////////////////////////////////////////////////////
	JDFCommand JDFJMF::GetCreateCommand(int i){
		return GetCreateMessageElement(JDFMessage::Family_Command,i);
	};
	//////////////////////////////////////////////////////////////////////
	JDFAcknowledge JDFJMF::GetCreateAcknowledge(int i){
		return GetCreateMessageElement(JDFMessage::Family_Acknowledge,i);
	};
	//////////////////////////////////////////////////////////////////////
	JDFRegistration JDFJMF::GetCreateRegistration(int i){
		return GetCreateMessageElement(JDFMessage::Family_Registration,i);
	};
	//////////////////////////////////////////////////////////////////////
	JDFQuery JDFJMF::AppendQuery(JDFMessage::EnumType typ){
		JDFQuery m=AppendMessageElement(JDFMessage::Family_Query);
		if(typ!=JDFMessage::Type_Unknown)
			m.SetEnumType(typ);
		m.init();
		return m;
	};
	//////////////////////////////////////////////////////////////////////
	JDFResponse JDFJMF::AppendResponse(JDFMessage::EnumType typ){
		JDFResponse m= AppendMessageElement(JDFMessage::Family_Response);
		if(typ!=JDFMessage::Type_Unknown)
			m.SetEnumType(typ);
		m.init();
		return m;
	};
	//////////////////////////////////////////////////////////////////////
	JDFSignal JDFJMF::AppendSignal(JDFMessage::EnumType typ){
		JDFSignal m=AppendMessageElement(JDFMessage::Family_Signal);
		if(typ!=JDFMessage::Type_Unknown)
			m.SetEnumType(typ);
		m.init();
		return m;
	};
	//////////////////////////////////////////////////////////////////////
	JDFCommand JDFJMF::AppendCommand(JDFMessage::EnumType typ){
		JDFCommand m=AppendMessageElement(JDFMessage::Family_Command);
		if(typ!=JDFMessage::Type_Unknown)
			m.SetEnumType(typ);
		m.init();
		return m;
	};
	//////////////////////////////////////////////////////////////////////
	JDFAcknowledge JDFJMF::AppendAcknowledge(JDFMessage::EnumType typ){
		JDFAcknowledge m=AppendMessageElement(JDFMessage::Family_Acknowledge);
		if(typ!=JDFMessage::Type_Unknown)
			m.SetEnumType(typ);
		m.init();
		return m;
	};
	//////////////////////////////////////////////////////////////////////
	JDFRegistration JDFJMF::AppendRegistration(JDFMessage::EnumType typ){
		JDFAcknowledge m=AppendMessageElement(JDFMessage::Family_Registration);
		if(typ!=JDFMessage::Type_Unknown)
			m.SetEnumType(typ);
		m.init();
		return m;
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFJMF::IsQueryImplemented(const JDFQuery& q){
		WString s=q.GetType();
		if(!s.compare(L"KnownMessages")) 
			return true;
		return false;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFJMF::IsAbstract()const{
		return false;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	definition of required attributes in the JDF namespace
	*/
	WString JDFJMF::RequiredAttributes()const{
		if(GetParentJDF().isNull())
			return JDFAutoJMF::RequiredAttributes()+L",xmlns";

		return JDFAutoJMF::RequiredAttributes();
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
}
