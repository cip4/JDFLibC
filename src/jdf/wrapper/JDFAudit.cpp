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
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
//
// JDFAudit.cpp: implementation of the JDFAudit class.
//
//////////////////////////////////////////////////////////////////////

#include "JDFAudit.h"
#include "JDFAuditPool.h"
#include "JDFDoc.h"
#include "JDFNode.h"
#include "JDFResourceLink.h"

#include "jdf/util/JDFLibVersion.h"

using namespace std;

namespace JDF{
	static WString agentName=L"CIP4 JDF Writer C++";
	static WString agentVersion=JDFLibVersion;

	//////////////////////////////////////////////////////////////////////
	// Construction/Destruction
	//////////////////////////////////////////////////////////////////////

	/**
	* copy ctor
	*/


	//////////////////////////////////////////////////////////////////////

	JDFAudit &JDFAudit::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFAudit: "+other.GetNodeName()); 
		return *this;
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFAudit::init(){
		EnumVersion v=GetEnumVersion(true);
		SetTimeStamp(JDFDate());
		if(v>=Version_1_2)
		{
			SetAgentName(agentName);
			SetAgentVersion(agentVersion);
		}
		if(v>=Version_1_3)
		{
			AppendAnchor();
		}
		return true;
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFAudit::GetIDPrefix() const {
		const static WString n=L"a";
		return n;
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFAudit::FixVersion(EnumVersion version){
		if(version>=Version_1_3){
			AppendAnchor();
		}else{
			RemoveAttribute(atr_ID);
		}
		WString author=GetAuthor();
		if(version<=Version_1_1){
			WString tmp=GetAgentName();
			bool b=false;
			if(tmp.length()!=0){
				author+=L"_|_"+tmp;
				b=true;
			}
			tmp=GetAgentVersion();
			if(tmp.length()!=0){
				if(!b)
					author+=L"_|_ ";

				author+=L"_|_"+tmp;
				b=true;
			}
			RemoveAttribute(atr_AgentName);
			RemoveAttribute(atr_AgentVersion);
			if(b)
				SetAuthor(author);
		}
		else if(author.length()>0) // version>=1.2 and has author
		{
			vWString tokens=author.Tokenize(L"_|_");
			if(tokens.size()==3){ // it was previously fixed
				WString tmp=tokens.stringAt(0);
				if(!tmp.equals(WString::emptyStr)&&!tmp.equals(WString::blank))
					SetAuthor(tmp);
				tmp=tokens.stringAt(1);
				if(!tmp.equals(WString::emptyStr)&&!tmp.equals(WString::blank))
					SetAgentName(tmp);
				tmp=tokens.stringAt(2);
				if(!tmp.equals(WString::emptyStr)&&!tmp.equals(WString::blank))
					SetAgentVersion(tmp);
			}
		}
		return JDFElement::FixVersion(version);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFAudit::EnumAuditType JDFAudit::GetAuditType(){
		vWString vType=AuditTypeString().Tokenize(WString::comma);
		WString nam=GetNodeName();
		for(int i=1;i<vType.size();i++){
			if (nam==vType[i]) 
				return (EnumAuditType) i;
		}
		return (EnumAuditType)0; // unknown
	}

	//////////////////////////////////////////////////////////////////////

	WString JDFAudit::Software(){
		return agentName+WString::blank+agentVersion;
	};
	//////////////////////////////////////////////////////////////////////

	JDFAuditPool JDFAudit::GetAuditPool()const{
		return GetDeepParent(elm_AuditPool);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	typesafe validator
	*/
	vWString JDFAudit::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level, bIgnorePrivate, nMax);
		int n=0;
		if(!ValidAuthor(level)) {
			vAtts.push_back(atr_Author);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidAgentName(level)) {
			vAtts.push_back(atr_AgentName);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidAgentVersion(level)) {
			vAtts.push_back(atr_AgentVersion);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidTimeStamp(level)) {
			vAtts.push_back(atr_TimeStamp);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidSpawnID(level)) {
			vAtts.push_back(atr_SpawnID);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidID(level)) {
			vAtts.push_back(atr_ID);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidrefID(level)) {
			vAtts.push_back(atr_refID);
			if(++n>=nMax) 
				return vAtts;
		};
		return vAtts;
	};


	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */


	//////////////////////////////////////////////////////////////////////

	/**
	Set attribute Author
	*/
	void JDFAudit::SetAuthor(const WString& value){
		SetAttribute(atr_Author,value);
	};
	/**
	Get string attribute Author
	*/
	WString JDFAudit::GetAuthor() const {
		return GetAttribute(atr_Author);
	};
	/**
	Typesafe attribute validation of Author
	*/
	bool JDFAudit::ValidAuthor(EnumValidationLevel level) const {
		return ValidAttribute(atr_Author,AttributeType_string,false);
	};
	/**
	Set attribute AgentName
	*/
	void JDFAudit::SetAgentName(const WString& value){
		if (value.empty())
		{
			if (HasAttribute(atr_AgentName))
				RemoveAttribute(atr_AgentName);
		}
		else
			SetAttribute(atr_AgentName,value);
	};
	/**
	Get string attribute AgentName
	*/
	WString JDFAudit::GetAgentName() const {
		return GetAttribute(atr_AgentName);
	};
	/**
	Typesafe attribute validation of AgentName
	*/
	bool JDFAudit::ValidAgentName(EnumValidationLevel level) const {
		return ValidAttribute(atr_AgentName,AttributeType_string,false);
	};
	/**
	Set attribute AgentVersion
	*/
	void JDFAudit::SetAgentVersion(const WString& value){
		if (value.empty())
		{
			if (HasAttribute(atr_AgentVersion))
				RemoveAttribute(atr_AgentVersion);
		}
		else
			SetAttribute(atr_AgentVersion,value);
	};
	/**
	Get string attribute AgentVersion
	*/
	WString JDFAudit::GetAgentVersion() const {
		return GetAttribute(atr_AgentVersion);
	};
	/**
	Typesafe attribute validation of AgentVersion
	*/
	bool JDFAudit::ValidAgentVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_AgentVersion,AttributeType_string,false);
	};

	//////////////////////////////////////////////////////////////////////
	/**
	* Set attribute TimeStamp
	* @since 11.11.2004 takes the parameters of type JDFDate instead of MyDate
	*/
	void JDFAudit::SetTimeStamp(JDFDate value){
		SetAttribute(atr_TimeStamp,value.DateTimeISO());
	};
	/**
	* Get string attribute TimeStamp
	* @since 11.11.2004 returns value of type JDFDate instead of MyDate
	*/
	JDFDate JDFAudit::GetTimeStamp() const {
		return GetAttribute(atr_TimeStamp);
	};

	/**
	Typesafe attribute validation of SpawnID
	*/
	bool JDFAudit::ValidSpawnID(EnumValidationLevel level) const {
		return ValidAttribute(atr_SpawnID,AttributeType_NMTOKEN,false);
	};

	/**
	Set attribute SpawnID
	*/
	void JDFAudit::SetSpawnID(const WString& value){
		SetAttribute(atr_SpawnID,value);
	};
	/**
	Get string attribute SpawnID
	*/
	WString JDFAudit::GetSpawnID() const {
		return GetAttribute(atr_SpawnID);
	};

	/**
	Typesafe attribute validation of ID
	*/
	bool JDFAudit::ValidID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ID,AttributeType_ID,false);
	};

	/**
	Set attribute refID
	*/
	void JDFAudit::SetrefID(const WString& value){
		SetAttribute(atr_refID,value);
	};

	/**
	Get string attribute refID
	*/
	WString JDFAudit::GetrefID() const {
		return GetAttribute(atr_refID);
	};

	/**
	Typesafe attribute validation of refID
	*/
	bool JDFAudit::ValidrefID(EnumValidationLevel level) const {
		return ValidAttribute(atr_refID,AttributeType_IDREF,false);
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFAudit::ValidTimeStamp(EnumValidationLevel level) const {
		return ValidAttribute(atr_TimeStamp,AttributeType_dateTime,RequiredLevel(level));
	};

	//////////////////////////////////////////////////////////////////////
	/**
	* definition of required attributes in the JDF namespace
	*/
	WString JDFAudit::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",TimeStamp";
	};

	/**
	* definition of optional attributes in the JDF namespace
	*/
	WString JDFAudit::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+L",Author,SpawnID,AgentName,AgentVersion,ID,refID";
	};
	//////////////////////////////////////////////////////////////////////
	const WString& JDFAudit::AuditTypeString(){
		static const WString k="Unknown,Created,Modified,Spawned,Merged,Notification,PhaseTime,ResourceAudit,ProcessRun"; 
		return k;
	};
	//////////////////////////////////////////////////////////////////////
	WString JDFAudit::AuditTypeString(EnumAuditType i){
		return AuditTypeString().Token(i,WString::comma);
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* @return Returns the m_strAgentName.
	*/
	WString JDFAudit::getStaticAgentName()
	{
		return agentName;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* @param agentName The m_strAgentName to set.
	*/
	void JDFAudit::setStaticAgentName(const WString& _agentName)
	{
		agentName = _agentName;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* @return Returns the m_strAgentVersion.
	*/
	WString JDFAudit::getStaticAgentVersion()
	{
		return agentVersion;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* @param agentVersion The m_strAgentVersion to set.
	*/
	void JDFAudit::setStaticAgentVersion(const WString& _agentVersion)
	{
		agentVersion = _agentVersion;
	}	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

}