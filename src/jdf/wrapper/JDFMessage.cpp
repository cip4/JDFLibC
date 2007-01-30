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
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
//
// JDFMessage.cpp: implementation of the JDFMessage class.
//
//////////////////////////////////////////////////////////////////////

#include "JDFDoc.h"
#include "JDFMessage.h"

#include "JDFDevice.h" 
#include "JDFDeviceList.h" 
#include "JDFDeviceFilter.h"
#include "JDFDeviceInfo.h"
#include "JDFEmployeeDef.h"
#include "JDFFlushedResources.h"
#include "JDFFlushQueueParams.h"
#include "JDFFlushResourceParams.h"
#include "JDFIDInfo.h"
#include "JDFJDFController.h"
#include "JDFJDFService.h"
#include "JDFJobPhase.h"
#include "JDFKnownMsgQuParams.h"
#include "JDFMessageService.h"
#include "JDFMsgFilter.h"
#include "JDFNewJDFCmdParams.h"
#include "JDFNewJDFQuParams.h"
#include "JDFNodeInfoCmdParams.h"
#include "JDFNodeInfoQuParams.h"
#include "JDFNodeInfoResp.h"
#include "JDFNotificationDef.h"
#include "JDFNotificationFilter.h"
#include "JDFOccupation.h"
#include "JDFPipeParams.h"
#include "JDFQueue.h"
#include "JDFQueueEntry.h"
#include "JDFQueueEntryDef.h"
#include "JDFQueueEntryDefList.h"
#include "JDFQueueEntryPriParams.h"
#include "JDFQueueEntryPosParams.h"
#include "JDFQueueFilter.h"
#include "JDFQueueSubmissionParams.h"
#include "JDFRequestQueueEntryParams.h"
#include "JDFResourceCmdParams.h"
#include "JDFResourcePullParams.h"
#include "JDFResourceQuParams.h"
#include "JDFResourceInfo.h"
#include "JDFResubmissionParams.h"
#include "JDFReturnQueueEntryParams.h"
#include "JDFShutDownCmdParams.h"
#include "JDFStatusQuParams.h"
#include "JDFStopPersChParams.h"
#include "JDFSubmissionMethods.h"
#include "JDFTrackFilter.h"
#include "JDFTrackResult.h"
#include "JDFWakeUpCmdParams.h"


namespace JDF{
	
	//////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////////
	
	JDFMessage &JDFMessage::operator =(const KElement& other){
		JDFElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFMessage: "+other.GetNodeName()); 
		return *this;
	};
	
	//////////////////////////////////////////////////////////////////////
	bool JDFMessage::init(){
		AppendAnchor();
		return JDFAutoMessage::init();
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* is a message with this name a message element?
	* @return bool true if this is a message
	*/
	bool JDFMessage::IsMessageElement()const{	
		return GetFamily()>0;
	};
	
	//////////////////////////////////////////////////////////////////////

	const WString& JDFMessage::FamilyString(){
		static const WString enums= WString(L"Unknown,Query,Signal,Command,Response,Acknowledge,Registration");
		return enums;
	}
	
	//////////////////////////////////////////////////////////////////////

	WString JDFMessage::FamilyString(EnumFamily i){
		return FamilyString().Token(i,WString::comma);
	}
	

	//////////////////////////////////////////////////////////////////////
	const WString& JDFMessage::TypeString(){
		static const WString enums=WString(L"Unknown,AbortQueueEntry,CloseQueue,Events,FlushQueue,FlushResources,ForceGang,GangStatus,HoldQueue,HoldQueueEntry,KnownControllers")
			+WString(L",KnownDevices,KnownJDFServices,KnownMessages,ModifyNode,NewJDF,NodeInfo,Notification,Occupation,OpenQueue,PipeClose,PipePull,PipePush,PipePause,QueueEntryStatus,QueueStatus")
			+WString(L",RequestQueueEntry,RemoveQueueEntry,RepeatMessages,Resource,ResourcePull,ResumeQueue,ResumeQueueEntry,ResubmitQueueEntry,ReturnQueueEntry")
			+WString(L",SetQueueEntryPosition,SetQueueEntryPriority,ShutDown,Status,StopPersistentChannel,SubmissionMethods,SubmitQueueEntry,SuspendQueueEntry,Track,UpdateJDF,WakeUp"); 
		return enums;
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFMessage::TypeString(EnumType value){
			return TypeString().Token(value,WString::comma);
		};

	//////////////////////////////////////////////////////////////////////
	const WString& JDFMessage::CommandTypeObjString(){
		static const WString enums=WString(L"Unknown,FlushQueueParams,FlushResourceParams,NewJDFCmdParams,NodeInfoCmdParams,PipeParams,QueueEntryDef,QueueEntryPriParams,QueueEntryPosParams,QueueFilter,QueueSubmissionParams,RequestQueueEntryParams,ResourceCmdParams,ResourcePullParams,ResubmissionParams,ReturnQueueEntryParams,ShutDownCmdParams,StopPersChParams,UpdateJDFCmdParams,WakeUpCmdParams"); 
		return enums;
	};
	//////////////////////////////////////////////////////////////////////
	const WString& JDFMessage::QueryTypeObjString(){
		static const WString enums=WString(L"Unknown,DeviceFilter,EmployeeDef,KnownMsgQuParams,MsgFilter,ModifyNodeCmdParams,NewJDFQuParams,NodeInfoQuParams,NotificationFilter,QueueEntryDefList,QueueFilter,ResourceQuParams,StatusQuParams,TrackFilter,UpdateJDFCmdParams"); 
		return enums;
	};
	
	
	//////////////////////////////////////////////////////////////////////
	const WString& JDFMessage::ResponseTypeObjString(){
		static const WString enums=WString(L"Unknown,Acknowledge,Command,DeviceList,DeviceInfo,FlushedResources,IDInfo,JDFController,JDFService,JobPhase,MessageService,NodeInfoResp,NotificationDef,Occupation,Queue,QueueEntry,Query,Registration,ResourceInfo,Response,Signal,SubmissionMethods,TrackResult"); 
		return enums;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFMessage::IsValid(EnumValidationLevel level)const{
		if(level<=ValidationLevel_Construct) {
			if(level<=ValidationLevel_None) 
				return true;
			if(isNull()) 
				return true;
		}
		
		if (!JDFAutoMessage::IsValid(level)) 
			return false;
		
		return IsMessageElement();
	}
	
	//////////////////////////////////////////////////////////////////////
	
	WString JDFMessage::FamilyTypeObj()const{
		EnumFamily family=GetFamily();
		switch(family){
		case Family_Command:
		case Family_Registration:
			return CommandTypeObjString();
		case Family_Query:
			return QueryTypeObjString();
		case Family_Response:
		case Family_Acknowledge:
			return ResponseTypeObjString();
		case Family_Signal:
			return QueryTypeObjString()+WString::comma+ResponseTypeObjString();
		}
		return WString();
	}
	
	//////////////////////////////////////////////////////////////////////
	JDFMessage::EnumFamily JDFMessage::GetFamily()const{
		return (EnumFamily) GetEnumNodeName(FamilyString());
	};
	
	//////////////////////////////////////////////////////////////////////
	
	JDFMessage::EnumType JDFMessage::GetEnumType() const {
		return (EnumType) GetEnumAttribute(atr_Type,TypeString(),WString::emptyStr);
	};
	
	//////////////////////////////////////////////////////////////////////
	void JDFMessage::SetEnumType( EnumType value){
		if(value>0){
			WString t=TypeString(value);
			SetAttribute(atr_Type,t);
			SetAttribute(L"xsi:type",GetLocalName()+t,atr_xsiURI);
		}
	};
	
	//////////////////////////////////////////////////////////////////////
	bool JDFMessage::IsValidMessageElement(const WString& elementName, int iSkip)const{

		// this is not a standard jdf element, but rather an extension
		// we assume that anyone calling the typesafe methods knows what he is doing
		if(!IsInJDFNameSpace())
			return true;

		// this is not a standard jdf type, but rather an extension type
		// we assume that anyone calling the typesafe methods knows what he is doing
		WString sTyp=GetType();
		if(!KElement::XMLNSPrefix(sTyp.c_str()).empty())
			return true;

		// it aint even valid for any family
		if (!FamilyTypeObj().HasToken(elementName,WString::comma))
			return false;
		
		EnumType typ=GetEnumType();
		// the type seams to be unknown, we certainly don't know what to dump in
		if(typ==Type_Unknown)
			return false;
		
		vEnumType validList=GetValidTypeVector(elementName,iSkip);
		
		// search list of valid types for this type
		for(int i=0;i<validList.size();i++){
			if(validList[i]==typ)
				return true;
		}
		
		// nothing found, too bad
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFMessage::vEnumType JDFMessage::GetValidTypeVector(const WString& elementName, int iSkip)const{
		vEnumType validList; 
		
		// Commands
		if(elementName==elm_FlushQueueParams){
			if (iSkip==0) { // validation for cardinality '?' or '-', when no more than 1 element are allowed
				validList.push_back(Type_FlushQueue);
			}

		}else if(elementName==elm_FlushResourceParams){
			if (iSkip==0) {
				validList.push_back(Type_FlushResources);
			}

		}else if(elementName==elm_NewJDFCmdParams){
			if (iSkip==0) {
				validList.push_back(Type_NewJDF);
			}

		}else if(elementName==elm_NodeInfoCmdParams){
			if (iSkip==0) {
				validList.push_back(Type_NodeInfo);
			}

		}else if(elementName==elm_PipeParams){
			if (iSkip==0) {
				validList.push_back(Type_PipeClose);
				validList.push_back(Type_PipePush);
				validList.push_back(Type_PipePull);
				validList.push_back(Type_PipePause);
			}

		}else if(elementName==elm_QueueEntryDef){
			if (iSkip==0) {
				validList.push_back(Type_AbortQueueEntry);
				validList.push_back(Type_HoldQueueEntry);
				validList.push_back(Type_RemoveQueueEntry);
				validList.push_back(Type_ResumeQueueEntry);
				validList.push_back(Type_SuspendQueueEntry);
			}

		}else if(elementName==elm_QueueEntryPriParams){
			if (iSkip==0) {
				validList.push_back(Type_SetQueueEntryPriority);
			}

		}else if(elementName==elm_QueueEntryPosParams){
			if (iSkip==0) {
				validList.push_back(Type_SetQueueEntryPosition);
			}

		}else if(elementName==elm_QueueFilter){
			if (iSkip==0) {
				validList.push_back(Type_AbortQueueEntry);
				validList.push_back(Type_CloseQueue);
				validList.push_back(Type_FlushQueue);
				validList.push_back(Type_FlushResources);
				validList.push_back(Type_HoldQueue);
				validList.push_back(Type_HoldQueueEntry);
				validList.push_back(Type_OpenQueue);
				validList.push_back(Type_RemoveQueueEntry);
				validList.push_back(Type_ResourcePull);
				validList.push_back(Type_ResubmitQueueEntry);
				validList.push_back(Type_ResumeQueue);
				validList.push_back(Type_ResumeQueueEntry);
				validList.push_back(Type_SetQueueEntryPosition);
				validList.push_back(Type_SetQueueEntryPriority);
				validList.push_back(Type_ShutDown);
				validList.push_back(Type_SubmitQueueEntry);
				validList.push_back(Type_SuspendQueueEntry);
				// Queries for QueueFilter 
				validList.push_back(Type_QueueStatus);
			}
			
		}else if(elementName==elm_QueueSubmissionParams){
			if (iSkip==0) {
				validList.push_back(Type_SubmitQueueEntry);
			}

		}else if(elementName==elm_RequestQueueEntryParams){
			if (iSkip==0) {
				validList.push_back(Type_RequestQueueEntry);
			}

		}else if(elementName==elm_ResourceCmdParams){
			if (iSkip==0) {
				validList.push_back(Type_Resource);
			}

		}else if(elementName==elm_ResourcePullParams){
			if (iSkip==0) {
				validList.push_back(Type_ResourcePull);
			}

		}else if(elementName==elm_ResubmissionParams){
			if (iSkip==0) {
				validList.push_back(Type_ResubmitQueueEntry);
			}

		}else if(elementName==elm_ReturnQueueEntryParams){
			if (iSkip==0) {
				validList.push_back(Type_ReturnQueueEntry);
			}

		}else if(elementName==elm_ShutDownCmdParams){
			if (iSkip==0) {
				validList.push_back(Type_ShutDown);
			}

		}else if(elementName==elm_StopPersChParams){
			if (iSkip==0) {
				validList.push_back(Type_StopPersistentChannel);
			}

		}else if(elementName==elm_WakeUpCmdParams){
			if (iSkip==0) {
				validList.push_back(Type_WakeUp);
			}
		
			
			// Queries
		}else if(elementName==elm_DeviceFilter){
			if (iSkip==0) {
				validList.push_back(Type_KnownDevices);
			}

		}else if(elementName==elm_EmployeeDef){
			validList.push_back(Type_Occupation);
			
		}else if(elementName==elm_KnownMsgQuParams){
			if (iSkip==0) {
				validList.push_back(Type_KnownMessages);
			}

		}else if(elementName==elm_MsgFilter){
			if (iSkip==0) {
				validList.push_back(Type_RepeatMessages);
			}

		}else if(elementName==elm_NewJDFQuParams){
			if (iSkip==0) {
				validList.push_back(Type_NewJDF);
			}

		}else if(elementName==elm_NodeInfoQuParams){
			if (iSkip==0) {
				validList.push_back(Type_NodeInfo);
			}

		}else if(elementName==elm_NotificationFilter){
			if (iSkip==0) {
				validList.push_back(Type_Events);
			}

		}else if(elementName==elm_QueueEntryDefList){
			if (iSkip==0) {
				validList.push_back(Type_QueueEntryStatus);
			}

		}else if(elementName==elm_ResourceQuParams){
			if (iSkip==0) {
				validList.push_back(Type_Resource);
			}

		}else if(elementName==elm_StatusQuParams){
			if (iSkip==0) {
				validList.push_back(Type_Status);
			}

		}else if(elementName==elm_TrackFilter){
			if (iSkip==0) {
				validList.push_back(Type_Track);
			}

			
			// Responses	
		}else if(elementName==elm_Acknowledge){ 
			validList.push_back(Type_RepeatMessages);

		}else if(elementName==elm_Command){ 
			validList.push_back(Type_RepeatMessages);

		}else if(elementName==elm_DeviceList){ 
			if (iSkip==0) {
				validList.push_back(Type_KnownDevices);
			}

		}else if(elementName==elm_DeviceInfo){
			if (iSkip==0) {
				validList.push_back(Type_ShutDown);
				validList.push_back(Type_WakeUp);
			}
			validList.push_back(Type_Status);
			
		}else if(elementName==elm_FlushedResources){
			if (iSkip==0) {
				validList.push_back(Type_FlushResources);
			}

		}else if(elementName==elm_IDInfo){
			validList.push_back(Type_NewJDF);

		}else if(elementName==elm_JDFController){
			validList.push_back(Type_KnownControllers);

		}else if(elementName==elm_JDFService){
			validList.push_back(Type_KnownJDFServices);

		}else if(elementName==elm_JobPhase){
			if (iSkip==0) {
				validList.push_back(Type_PipeClose);
				validList.push_back(Type_PipePush);
				validList.push_back(Type_PipePull);
				validList.push_back(Type_PipePause);
			}

		}else if(elementName==elm_MessageService){
			validList.push_back(Type_KnownMessages);

		}else if(elementName==elm_NodeInfoResp){
			validList.push_back(Type_NodeInfo);

		}else if(elementName==elm_NotificationDef){
			validList.push_back(Type_Events);

		}else if(elementName==elm_Occupation){
			validList.push_back(Type_Occupation);

		}else if(elementName==elm_Queue){
			if (iSkip==0) {
				validList.push_back(Type_AbortQueueEntry);
				validList.push_back(Type_CloseQueue);
				validList.push_back(Type_FlushQueue);
				validList.push_back(Type_HoldQueue);
				validList.push_back(Type_HoldQueueEntry);
				validList.push_back(Type_OpenQueue);
				validList.push_back(Type_QueueStatus);
				validList.push_back(Type_RemoveQueueEntry);
				validList.push_back(Type_ResourcePull);
				validList.push_back(Type_ResumeQueue);
				validList.push_back(Type_ResubmitQueueEntry);
				validList.push_back(Type_ResumeQueueEntry);
				validList.push_back(Type_SetQueueEntryPosition);
				validList.push_back(Type_SetQueueEntryPriority);
				validList.push_back(Type_ShutDown);
				validList.push_back(Type_Status);
				validList.push_back(Type_SubmitQueueEntry);
				validList.push_back(Type_SuspendQueueEntry);
			}

		}else if(elementName==elm_QueueEntry){
			if (iSkip==0) {
				validList.push_back(Type_ResourcePull);
				validList.push_back(Type_SubmitQueueEntry);
			}
			validList.push_back(Type_QueueEntryStatus);

		}else if(elementName==elm_Query){ 
			validList.push_back(Type_RepeatMessages);

		}else if(elementName==elm_ResourceInfo){
			validList.push_back(Type_Resource);

		}else if(elementName==elm_Response){ 
			validList.push_back(Type_RepeatMessages);

		}else if(elementName==elm_Signal){ 
			validList.push_back(Type_RepeatMessages);

		}else if(elementName==elm_SubmissionMethods){
			if (iSkip==0) {
				validList.push_back(Type_SubmissionMethods);
			}

		}else if(elementName==elm_TrackResult){
			validList.push_back(Type_Track);

		}else if(elementName==elm_UpdateJDFCmdParams){
			validList.push_back(Type_UpdateJDF);

		}else if(elementName==elm_ModifyNodeCmdParams){
			validList.push_back(Type_ModifyNode);
			
		}else if(FamilyString().HasToken(elementName,WString::comma)){
			validList.push_back(Type_RepeatMessages);
		}
		
		return validList;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFMessage::SetQuery(const JDFMessage& q){
		SetAttribute(atr_refID,q.GetID());
		SetEnumType(q.GetEnumType());
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	WString JDFMessage::GetIDPrefix() const {
		static const WString l=L"m";
		return l;
	}
	
	//////////////////////////////////////////////////////////////////////
	KElement JDFMessage::AppendValidElement(const WString & elementName,const WString & nameSpaceURI){
		
		int iSkip=NumChildElements(elementName,nameSpaceURI);

		if(!IsValidMessageElement(elementName,iSkip))
			throw JDFException(L"AppendValidElement: illegal element :"+elementName);
		return AppendElement(elementName,nameSpaceURI);
	}
	
	//////////////////////////////////////////////////////////////////////
	KElement JDFMessage::GetValidElement(const WString& nodeName, const WString & nameSpaceURI, int iSkip)const{
		if(!IsValidMessageElement(nodeName,iSkip))
			throw JDFException(L"GetValidElement: illegal element :"+nodeName);
		return GetElement(nodeName, nameSpaceURI, iSkip);
	};

	//////////////////////////////////////////////////////////////////////
	KElement JDFMessage::GetCreateValidElement(const WString& nodeName, const WString & nameSpaceURI, int iSkip){
		if(!IsValidMessageElement(nodeName,iSkip))
			throw JDFException(L"GetCreateValidElement: illegal element :"+nodeName);
		return GetCreateElement(nodeName, nameSpaceURI, iSkip);
	};
	
	//////////////////////////////////////////////////////////////////////	

	void JDFMessage::SetType(const WString& typ)
	{
		RemoveAttribute("type",atr_xsiURI); // removing "xsi:uri"
		SetAttribute(atr_Type,typ);
		if(XMLNSPrefix(typ.c_str()).empty())
			setXSIType(GetLocalName()+typ);
	}

	//////////////////////////////////////////////////////////////////////	
	
	bool JDFMessage::ValidType(EnumValidationLevel level) const {
		const WString typ=GetType();
		if (XMLNameSpace(typ).empty()){
			return ValidEnumAttribute(atr_Type,TypeString(),RequiredLevel(level));
		}else{
			return ValidAttribute(atr_Type,AttributeType_NMTOKEN,RequiredLevel(level));
		}
	};
	
	
	//////////////////////////////////////////////////////////////////////
	/**
	definition of optional elements in the JDF namespace
	*/
	WString JDFMessage::OptionalElements()const{
		WString s=JDFAutoMessage::OptionalElements();
		EnumType t=GetEnumType();
		// loop over all valid potential elements for this family
		vWString vObjs=FamilyTypeObj().Tokenize(WString::comma);
		// for each object, check whether it is compatible with the type of this
		for(int i=0;i<vObjs.size();i++){
			vEnumType vt=GetValidTypeVector(vObjs[i]);
			// is it there ?
			for(int j=0;j<vt.size();j++){
				if(vt[j]==t){
					// obj x is compatible with this -> add it to the list of elements
					s+=WString::comma+vObjs[i];
					break;
				}
			}
		}
		
		return s;
		
	};
	/**
	typesafe validator
	*/
	//////////////////////////////////////////////////////////////////////
	
	vWString JDFMessage::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		bool bCatch=false;
		vWString vElem=JDFAutoMessage::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax) 
			return vElem;
		
		nElem=NumChildElements (elm_Device);
		for(i=0;i<nElem;i++){
			JDFDevice child;
			try {
				child=GetValidElement(elm_Device,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_Device);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_DeviceFilter);
		for(i=0;i<nElem;i++){
			JDFDeviceFilter child;
			try {
				child=GetValidElement(elm_DeviceFilter,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_DeviceFilter);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_DeviceInfo);
		for(i=0;i<nElem;i++){
			JDFDeviceInfo child;
			try {
				child=GetValidElement(elm_DeviceInfo,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_DeviceInfo);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_DeviceList);
		for(i=0;i<nElem;i++){
			JDFDeviceList child;
			try {
				child=GetValidElement(elm_DeviceList,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_DeviceList);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}

		nElem=NumChildElements(elm_EmployeeDef);
		for(i=0;i<nElem;i++){
			JDFEmployeeDef child;
			try {
				child=GetValidElement(elm_EmployeeDef,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_EmployeeDef);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_FlushedResources);
		for(i=0;i<nElem;i++){
			JDFFlushedResources child;
			try {
				child=GetValidElement(elm_FlushedResources,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_FlushedResources);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}

		nElem=NumChildElements(elm_FlushQueueParams);
		for(i=0;i<nElem;i++){
			JDFFlushQueueParams child;
			try {
				child=GetValidElement(elm_FlushQueueParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_FlushQueueParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}

		nElem=NumChildElements(elm_FlushResourceParams);
		for(i=0;i<nElem;i++){
			JDFFlushResourceParams child;
			try {
				child=GetValidElement(elm_FlushResourceParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_FlushResourceParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}

		
		nElem=NumChildElements(elm_IDInfo);
		for(i=0;i<nElem;i++){
			JDFIDInfo child;
			try {
				child=GetValidElement(elm_IDInfo,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_IDInfo);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_JDFController);
		for(i=0;i<nElem;i++){
			JDFJDFController child;
			try {
				child=GetValidElement(elm_JDFController,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_JDFController);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_JDFService);
		for(i=0;i<nElem;i++){
			JDFJDFService child;
			try {
				child=GetValidElement(elm_JDFService,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_JDFService);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_JobPhase);
		for(i=0;i<nElem;i++){
			JDFJobPhase child;
			try {
				child=GetValidElement(elm_JobPhase,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_JobPhase);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_KnownMsgQuParams);
		for(i=0;i<nElem;i++){
			JDFKnownMsgQuParams child;
			try {
				child=GetValidElement(elm_KnownMsgQuParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_KnownMsgQuParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_MessageService);
		for(i=0;i<nElem;i++){
			JDFMessageService child;
			try {
				child=GetValidElement(elm_MessageService,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_MessageService);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_MsgFilter);
		for(i=0;i<nElem;i++){
			JDFMsgFilter child;
			try {
				child=GetValidElement(elm_MsgFilter,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_MsgFilter);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_NewJDFCmdParams);
		for(i=0;i<nElem;i++){
			JDFNewJDFCmdParams child;
			try {
				child=GetValidElement(elm_NewJDFCmdParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_NewJDFCmdParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_NewJDFQuParams);
		for(i=0;i<nElem;i++){
			JDFNewJDFQuParams child;
			try {
				child=GetValidElement(elm_NewJDFQuParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_NewJDFQuParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_NodeInfoCmdParams);
		for(i=0;i<nElem;i++){
			JDFNodeInfoCmdParams child;
			try {
				child=GetValidElement(elm_NodeInfoCmdParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_NodeInfoCmdParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_NodeInfoQuParams);
		for(i=0;i<nElem;i++){
			JDFNodeInfoQuParams child;
			try {
				child=GetValidElement(elm_NodeInfoQuParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_NodeInfoQuParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_NodeInfoResp);
		for(i=0;i<nElem;i++){
			JDFNodeInfoResp child;
			try {
				child=GetValidElement(elm_NodeInfoResp,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_NodeInfoResp);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_NotificationDef);
		for(i=0;i<nElem;i++){
			JDFNotificationDef child;
			try {
				child=GetValidElement(elm_NotificationDef,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_NotificationDef);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_NotificationFilter);
		for(i=0;i<nElem;i++){
			JDFNotificationFilter child;
			try {
				child=GetValidElement(elm_NotificationFilter,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_NotificationFilter);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_Occupation);
		for(i=0;i<nElem;i++){
			JDFOccupation child;
			try {
				child=GetValidElement(elm_Occupation,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_Occupation);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_PipeParams);
		for(i=0;i<nElem;i++){
			JDFPipeParams child;
			try {
				child=GetValidElement(elm_PipeParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_PipeParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_Queue);
		for(i=0;i<nElem;i++){
			JDFQueue child;
			try {
				child=GetValidElement(elm_Queue,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_Queue);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_QueueEntry);
		for(i=0;i<nElem;i++){
			JDFQueueEntry child;
			try {
				child=GetValidElement(elm_QueueEntry,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_QueueEntry);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_QueueEntryDef);
		for(i=0;i<nElem;i++){
			JDFQueueEntryDef child;
			try {
				child=GetValidElement(elm_QueueEntryDef,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_QueueEntryDef);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_QueueEntryDefList);
		for(i=0;i<nElem;i++){
			JDFQueueEntryDefList child;
			try {
				child=GetValidElement(elm_QueueEntryDefList,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_QueueEntryDefList);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}

		nElem=NumChildElements(elm_QueueEntryPriParams);
		for(i=0;i<nElem;i++){
			JDFQueueEntryPriParams child;
			try {
				child=GetValidElement(elm_QueueEntryPriParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_QueueEntryPriParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_QueueEntryPosParams);
		for(i=0;i<nElem;i++){
			JDFQueueEntryPosParams child;
			try {
				child=GetValidElement(elm_QueueEntryPosParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_QueueEntryPosParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_QueueFilter);
		for(i=0;i<nElem;i++){
			JDFQueueFilter child;
			try {
				child=GetValidElement(elm_QueueFilter,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_QueueFilter);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}

		nElem=NumChildElements(elm_QueueSubmissionParams);
		for(i=0;i<nElem;i++){
			JDFQueueSubmissionParams child;
			try {
				child=GetValidElement(elm_QueueSubmissionParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_QueueSubmissionParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_RequestQueueEntryParams);
		for(i=0;i<nElem;i++){
			JDFRequestQueueEntryParams child;
			try {
				child=GetValidElement(elm_RequestQueueEntryParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_RequestQueueEntryParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}

		nElem=NumChildElements(elm_ResourceCmdParams);
		for(i=0;i<nElem;i++){
			JDFResourceCmdParams child;
			try {
				child=GetValidElement(elm_ResourceCmdParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_ResourceCmdParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_ResourceInfo);
		for(i=0;i<nElem;i++){
			JDFResourceInfo child;
			try {
				child=GetValidElement(elm_ResourceInfo,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_ResourceInfo);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}

		nElem=NumChildElements(elm_ResourcePullParams);
		for(i=0;i<nElem;i++){
			JDFResourcePullParams child;
			try {
				child=GetValidElement(elm_ResourcePullParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_ResourcePullParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}

		nElem=NumChildElements(elm_ResourceQuParams);
		for(i=0;i<nElem;i++){
			JDFResourceQuParams child;
			try {
				child=GetValidElement(elm_ResourceQuParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_ResourceQuParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}

		nElem=NumChildElements(elm_ResubmissionParams);
		for(i=0;i<nElem;i++){
			JDFResubmissionParams child;
			try {
				child=GetValidElement(elm_ResubmissionParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_ResubmissionParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_ReturnQueueEntryParams);
		for(i=0;i<nElem;i++){
			JDFReturnQueueEntryParams child;
			try {
				child=GetValidElement(elm_ReturnQueueEntryParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_ReturnQueueEntryParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
				
		nElem=NumChildElements(elm_ShutDownCmdParams);
		for(i=0;i<nElem;i++){
			JDFShutDownCmdParams child;
			try {
				child=GetValidElement(elm_ShutDownCmdParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_ShutDownCmdParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}

		nElem=NumChildElements(elm_StatusQuParams);
		for(i=0;i<nElem;i++){
			JDFStatusQuParams child;
			try {
				child=GetValidElement(elm_StatusQuParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_StatusQuParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_StopPersChParams);
		for(i=0;i<nElem;i++){
			JDFStopPersChParams child;
			try {
				child=GetValidElement(elm_StopPersChParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_StopPersChParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_SubmissionMethods);
		for(i=0;i<nElem;i++){
			JDFSubmissionMethods child;
			try {
				child=GetValidElement(elm_SubmissionMethods,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_SubmissionMethods);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_TrackFilter);
		for(i=0;i<nElem;i++){
			JDFTrackFilter child;
			try {
				child=GetValidElement(elm_TrackFilter,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_TrackFilter);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_TrackResult);
		for(i=0;i<nElem;i++){
			JDFTrackResult child;
			try {
				child=GetValidElement(elm_TrackResult,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_TrackResult);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		nElem=NumChildElements(elm_WakeUpCmdParams);
		for(i=0;i<nElem;i++){
			JDFWakeUpCmdParams child;
			try {
				child=GetValidElement(elm_WakeUpCmdParams,WString::emptyStr,i);
			}
			catch (JDFException x)
			{
				bCatch=true;
			}
			if (bCatch||!child.IsValid(level)) {
				vElem.AppendUnique(elm_WakeUpCmdParams);
				bCatch=false;
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}
		
		return vElem;
	};
	
	
	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFDevice JDFMessage::GetCreateDevice(int iSkip){
		JDFDevice e=GetCreateValidElement(elm_Device,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFDevice JDFMessage::AppendDevice(){
		JDFDevice e=AppendValidElement(elm_Device);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFDevice JDFMessage::GetDevice(int iSkip)const{
		return GetValidElement(elm_Device,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFDeviceFilter JDFMessage::GetCreateDeviceFilter(int iSkip){
		JDFDeviceFilter e=GetCreateValidElement(elm_DeviceFilter,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFDeviceFilter JDFMessage::AppendDeviceFilter(){
		JDFDeviceFilter e=AppendValidElement(elm_DeviceFilter);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFDeviceFilter JDFMessage::GetDeviceFilter(int iSkip) const{
		return GetValidElement(elm_DeviceFilter,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFDeviceInfo JDFMessage::GetCreateDeviceInfo(int iSkip){
		JDFDeviceInfo e=GetCreateValidElement(elm_DeviceInfo,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFDeviceInfo JDFMessage::AppendDeviceInfo(){
		JDFDeviceInfo e=AppendValidElement(elm_DeviceInfo);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFDeviceInfo JDFMessage::GetDeviceInfo(int iSkip) const{
		return GetValidElement(elm_DeviceInfo,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFDeviceList JDFMessage::GetCreateDeviceList(int iSkip){
		JDFDeviceList e=GetCreateValidElement(elm_DeviceList,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFDeviceList JDFMessage::AppendDeviceList(){
		JDFDeviceList e=AppendValidElement(elm_DeviceList);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFDeviceList JDFMessage::GetDeviceList(int iSkip) const{
		return GetValidElement(elm_DeviceList,WString::emptyStr,iSkip);
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFEmployeeDef JDFMessage::GetCreateEmployeeDef(int iSkip){
		JDFEmployeeDef e=GetCreateValidElement(elm_EmployeeDef,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFEmployeeDef JDFMessage::AppendEmployeeDef(){
		JDFEmployeeDef e=AppendValidElement(elm_EmployeeDef);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFEmployeeDef JDFMessage::GetEmployeeDef(int iSkip) const{
		return GetValidElement(elm_EmployeeDef,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFIDInfo JDFMessage::GetCreateIDInfo(int iSkip){
		JDFIDInfo e=GetCreateValidElement(elm_IDInfo,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFIDInfo JDFMessage::AppendIDInfo(){
		JDFIDInfo e=AppendValidElement(elm_IDInfo);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFIDInfo JDFMessage::GetIDInfo(int iSkip) const{
		return GetValidElement(elm_IDInfo,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFFlushedResources JDFMessage::GetCreateFlushedResources(int iSkip){
		JDFFlushedResources e=GetCreateValidElement(elm_FlushedResources,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFFlushedResources JDFMessage::AppendFlushedResources(){
		JDFFlushedResources e=AppendValidElement(elm_FlushedResources);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFFlushedResources JDFMessage::GetFlushedResources(int iSkip) const{
		return GetValidElement(elm_FlushedResources,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFFlushQueueParams JDFMessage::GetCreateFlushQueueParams(int iSkip){
		JDFFlushQueueParams e=GetCreateValidElement(elm_FlushQueueParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFFlushQueueParams JDFMessage::AppendFlushQueueParams(){
		JDFFlushQueueParams e=AppendValidElement(elm_FlushQueueParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFFlushQueueParams JDFMessage::GetFlushQueueParams(int iSkip) const{
		return GetValidElement(elm_FlushQueueParams,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFFlushResourceParams JDFMessage::GetCreateFlushResourceParams(int iSkip){
		JDFFlushResourceParams e=GetCreateValidElement(elm_FlushResourceParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFFlushResourceParams JDFMessage::AppendFlushResourceParams(){
		JDFFlushResourceParams e=AppendValidElement(elm_FlushResourceParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFFlushResourceParams JDFMessage::GetFlushResourceParams(int iSkip) const{
		return GetValidElement(elm_FlushResourceParams,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFJDFController JDFMessage::GetCreateJDFController(int iSkip){
		JDFJDFController e=GetCreateValidElement(elm_JDFController,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFJDFController JDFMessage::AppendJDFController(){
		JDFJDFController e=AppendValidElement(elm_JDFController);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFJDFController JDFMessage::GetJDFController(int iSkip) const{
		return GetValidElement(elm_JDFController,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFJDFService JDFMessage::GetCreateJDFService(int iSkip){
		JDFJDFService e=GetCreateValidElement(elm_JDFService,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFJDFService JDFMessage::AppendJDFService(){
		JDFJDFService e=AppendValidElement(elm_JDFService);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFJDFService JDFMessage::GetJDFService(int iSkip) const{
		return GetValidElement(elm_JDFService,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFJobPhase JDFMessage::GetCreateJobPhase(int iSkip){
		JDFJobPhase e=GetValidElement(elm_JobPhase,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFJobPhase JDFMessage::AppendJobPhase(){
		JDFJobPhase e=AppendValidElement(elm_JobPhase);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFJobPhase JDFMessage::GetJobPhase(int iSkip) const{
		return GetValidElement(elm_JobPhase,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFKnownMsgQuParams JDFMessage::GetCreateKnownMsgQuParams(int iSkip){
		JDFKnownMsgQuParams e=GetCreateValidElement(elm_KnownMsgQuParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFKnownMsgQuParams JDFMessage::AppendKnownMsgQuParams(){
		JDFKnownMsgQuParams e=AppendValidElement(elm_KnownMsgQuParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFKnownMsgQuParams JDFMessage::GetKnownMsgQuParams(int iSkip) const{
		return GetValidElement(elm_KnownMsgQuParams,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFMessageService JDFMessage::GetCreateMessageService(int iSkip){
		JDFMessageService e=GetCreateValidElement(elm_MessageService,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFMessageService JDFMessage::AppendMessageService(){
		JDFMessageService e=AppendValidElement(elm_MessageService);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFMessageService JDFMessage::GetMessageService(int iSkip) const{
		return GetValidElement(elm_MessageService,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFMsgFilter JDFMessage::GetCreateMsgFilter(int iSkip){
		JDFMsgFilter e=GetCreateValidElement(elm_MsgFilter,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFMsgFilter JDFMessage::AppendMsgFilter(){
		JDFMsgFilter e=AppendValidElement(elm_MsgFilter);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFMsgFilter JDFMessage::GetMsgFilter(int iSkip) const{
		return GetValidElement(elm_MsgFilter,WString::emptyStr,iSkip);
	};
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFNewJDFCmdParams JDFMessage::GetCreateNewJDFCmdParams(int iSkip){
		JDFNewJDFCmdParams e=GetCreateValidElement(elm_NewJDFCmdParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFNewJDFCmdParams JDFMessage::AppendNewJDFCmdParams(){
		JDFNewJDFCmdParams e=AppendValidElement(elm_NewJDFCmdParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFNewJDFCmdParams JDFMessage::GetNewJDFCmdParams(int iSkip) const{
		return GetValidElement(elm_NewJDFCmdParams,WString::emptyStr,iSkip);
	};
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFNewJDFQuParams JDFMessage::GetCreateNewJDFQuParams(int iSkip){
		JDFNewJDFQuParams e=GetCreateValidElement(elm_NewJDFQuParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFNewJDFQuParams JDFMessage::AppendNewJDFQuParams(){
		JDFNewJDFQuParams e=AppendValidElement(elm_NewJDFQuParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFNewJDFQuParams JDFMessage::GetNewJDFQuParams(int iSkip) const{
		return GetValidElement(elm_NewJDFQuParams,WString::emptyStr,iSkip);
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFNodeInfoCmdParams JDFMessage::GetCreateNodeInfoCmdParams(int iSkip){
		JDFNodeInfoCmdParams e=GetCreateValidElement(elm_NodeInfoCmdParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFNodeInfoCmdParams JDFMessage::AppendNodeInfoCmdParams(){
		JDFNodeInfoCmdParams e=AppendValidElement(elm_NodeInfoCmdParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFNodeInfoCmdParams JDFMessage::GetNodeInfoCmdParams(int iSkip) const{
		return GetValidElement(elm_NodeInfoCmdParams,WString::emptyStr,iSkip);
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFNodeInfoQuParams JDFMessage::GetCreateNodeInfoQuParams(int iSkip){
		JDFNodeInfoQuParams e=GetCreateValidElement(elm_NodeInfoQuParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFNodeInfoQuParams JDFMessage::AppendNodeInfoQuParams(){
		JDFNodeInfoQuParams e=AppendValidElement(elm_NodeInfoQuParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFNodeInfoQuParams JDFMessage::GetNodeInfoQuParams(int iSkip) const{
		return GetValidElement(elm_NodeInfoQuParams,WString::emptyStr,iSkip);
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFNodeInfoResp JDFMessage::GetCreateNodeInfoResp(int iSkip){
		JDFNodeInfoResp e=GetCreateValidElement(elm_NodeInfoResp,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFNodeInfoResp JDFMessage::AppendNodeInfoResp(){
		JDFNodeInfoResp e=AppendValidElement(elm_NodeInfoResp);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFNodeInfoResp JDFMessage::GetNodeInfoResp(int iSkip) const{
		return GetValidElement(elm_NodeInfoResp,WString::emptyStr,iSkip);
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFNotificationDef JDFMessage::GetCreateNotificationDef(int iSkip){
		JDFNotificationDef e=GetCreateValidElement(elm_NotificationDef,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFNotificationDef JDFMessage::AppendNotificationDef(){
		JDFNotificationDef e=AppendValidElement(elm_NotificationDef);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFNotificationDef JDFMessage::GetNotificationDef(int iSkip) const{
		return GetValidElement(elm_NotificationDef,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFNotificationFilter JDFMessage::GetCreateNotificationFilter(int iSkip){
		JDFNotificationFilter e=GetCreateValidElement(elm_NotificationFilter,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFNotificationFilter JDFMessage::AppendNotificationFilter(){
		JDFNotificationFilter e=AppendValidElement(elm_NotificationFilter);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFNotificationFilter JDFMessage::GetNotificationFilter(int iSkip) const{
		return GetValidElement(elm_NotificationFilter,WString::emptyStr,iSkip);
	};
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFOccupation JDFMessage::GetCreateOccupation(int iSkip){
		JDFOccupation e=GetCreateValidElement(elm_Occupation,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFOccupation JDFMessage::AppendOccupation(){
		JDFOccupation e=AppendValidElement(elm_Occupation);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFOccupation JDFMessage::GetOccupation(int iSkip) const{
		return GetValidElement(elm_Occupation,WString::emptyStr,iSkip);
	};
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFPipeParams JDFMessage::GetCreatePipeParams(int iSkip){
		JDFPipeParams e=GetCreateValidElement(elm_PipeParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFPipeParams JDFMessage::AppendPipeParams(){
		JDFPipeParams e=AppendValidElement(elm_PipeParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFPipeParams JDFMessage::GetPipeParams(int iSkip) const{
		return GetValidElement(elm_PipeParams,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFQueue JDFMessage::GetCreateQueue(int iSkip){
		JDFQueue e=GetCreateValidElement(elm_Queue,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFQueue JDFMessage::AppendQueue(){
		JDFQueue e=AppendValidElement(elm_Queue);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFQueue JDFMessage::GetQueue(int iSkip) const{
		return GetValidElement(elm_Queue,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFQueueEntry JDFMessage::GetCreateQueueEntry(int iSkip){
		JDFQueueEntry e=GetCreateValidElement(elm_QueueEntry,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFQueueEntry JDFMessage::AppendQueueEntry(){
		JDFQueueEntry e=AppendValidElement(elm_QueueEntry);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFQueueEntry JDFMessage::GetQueueEntry(int iSkip) const{
		return GetValidElement(elm_QueueEntry,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFQueueEntryDef JDFMessage::GetCreateQueueEntryDef(int iSkip){
		JDFQueueEntryDef e=GetCreateValidElement(elm_QueueEntryDef,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFQueueEntryDef JDFMessage::AppendQueueEntryDef(){
		JDFQueueEntryDef e=AppendValidElement(elm_QueueEntryDef);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFQueueEntryDef JDFMessage::GetQueueEntryDef(int iSkip) const{
		return GetValidElement(elm_QueueEntryDef,WString::emptyStr,iSkip);
	};
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFQueueEntryDefList JDFMessage::GetCreateQueueEntryDefList(int iSkip){
		JDFQueueEntryDefList e=GetCreateValidElement(elm_QueueEntryDefList,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFQueueEntryDefList JDFMessage::AppendQueueEntryDefList(){
		JDFQueueEntryDefList e=AppendValidElement(elm_QueueEntryDefList);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFQueueEntryDefList JDFMessage::GetQueueEntryDefList(int iSkip) const{
		return GetValidElement(elm_QueueEntryDefList,WString::emptyStr,iSkip);
	};
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFQueueEntryPriParams JDFMessage::GetCreateQueueEntryPriParams(int iSkip){
		JDFQueueEntryPriParams e=GetCreateValidElement(elm_QueueEntryPriParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	}

	//////////////////////////////////////////////////////////////////////

	JDFQueueEntryPriParams JDFMessage::AppendQueueEntryPriParams(){
		JDFQueueEntryPriParams e=AppendValidElement(elm_QueueEntryPriParams);
		e.init();
		return e;
	}
	
	//////////////////////////////////////////////////////////////////////

	JDFQueueEntryPriParams JDFMessage::GetQueueEntryPriParams(int iSkip)const{
		return GetValidElement(elm_QueueEntryPriParams,WString::emptyStr,iSkip);
	}
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFQueueEntryPosParams JDFMessage::GetCreateQueueEntryPosParams(int iSkip){
		JDFQueueEntryPosParams e=GetCreateValidElement(elm_QueueEntryPosParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFQueueEntryPosParams JDFMessage::AppendQueueEntryPosParams(){
		JDFQueueEntryPosParams e=AppendValidElement(elm_QueueEntryPosParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFQueueEntryPosParams JDFMessage::GetQueueEntryPosParams(int iSkip) const{
		return GetValidElement(elm_QueueEntryPosParams,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFQueueFilter JDFMessage::GetCreateQueueFilter(int iSkip){
		JDFQueueFilter e=GetCreateValidElement(elm_QueueFilter,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFQueueFilter JDFMessage::AppendQueueFilter(){
		JDFQueueFilter e=AppendValidElement(elm_QueueFilter);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFQueueFilter JDFMessage::GetQueueFilter(int iSkip) const{
		return GetValidElement(elm_QueueFilter,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFQueueSubmissionParams JDFMessage::GetCreateQueueSubmissionParams(int iSkip){
		JDFQueueSubmissionParams e=GetCreateValidElement(elm_QueueSubmissionParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFQueueSubmissionParams JDFMessage::AppendQueueSubmissionParams(){
		JDFQueueSubmissionParams e=AppendValidElement(elm_QueueSubmissionParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFQueueSubmissionParams JDFMessage::GetQueueSubmissionParams(int iSkip) const{
		return GetValidElement(elm_QueueSubmissionParams,WString::emptyStr,iSkip);
	};
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFRequestQueueEntryParams JDFMessage::GetCreateRequestQueueEntryParams(int iSkip){
		JDFRequestQueueEntryParams e=GetCreateValidElement(elm_RequestQueueEntryParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFRequestQueueEntryParams JDFMessage::AppendRequestQueueEntryParams(){
		JDFRequestQueueEntryParams e=AppendValidElement(elm_RequestQueueEntryParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFRequestQueueEntryParams JDFMessage::GetRequestQueueEntryParams(int iSkip) const{
		return GetValidElement(elm_RequestQueueEntryParams,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFResourceCmdParams JDFMessage::GetCreateResourceCmdParams(int iSkip){
		JDFResourceCmdParams e=GetCreateValidElement(elm_ResourceCmdParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFResourceCmdParams JDFMessage::AppendResourceCmdParams(){
		JDFResourceCmdParams e=AppendValidElement(elm_ResourceCmdParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFResourceCmdParams JDFMessage::GetResourceCmdParams(int iSkip) const{
		return GetValidElement(elm_ResourceCmdParams,WString::emptyStr,iSkip);
	};
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	JDFResourceInfo JDFMessage::GetCreateResourceInfo(int iSkip){
		JDFResourceInfo e=GetCreateValidElement(elm_ResourceInfo,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFResourceInfo JDFMessage::AppendResourceInfo(){
		JDFResourceInfo e=AppendValidElement(elm_ResourceInfo);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFResourceInfo JDFMessage::GetResourceInfo(int iSkip) const{
		return GetValidElement(elm_ResourceInfo,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFResourcePullParams JDFMessage::GetCreateResourcePullParams(int iSkip){
		JDFResourcePullParams e=GetCreateValidElement(elm_ResourcePullParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFResourcePullParams JDFMessage::AppendResourcePullParams(){
		JDFResourcePullParams e=AppendValidElement(elm_ResourcePullParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFResourcePullParams JDFMessage::GetResourcePullParams(int iSkip) const{
		return GetValidElement(elm_ResourcePullParams,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFResourceQuParams JDFMessage::GetCreateResourceQuParams(int iSkip){
		JDFResourceQuParams e=GetCreateValidElement(elm_ResourceQuParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFResourceQuParams JDFMessage::AppendResourceQuParams(){
		JDFResourceQuParams e=AppendValidElement(elm_ResourceQuParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFResourceQuParams JDFMessage::GetResourceQuParams(int iSkip) const{
		return GetValidElement(elm_ResourceQuParams,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFResubmissionParams JDFMessage::GetCreateResubmissionParams(int iSkip){
		JDFResubmissionParams e=GetCreateValidElement(elm_ResubmissionParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFResubmissionParams JDFMessage::AppendResubmissionParams(){
		JDFResubmissionParams e=AppendValidElement(elm_ResubmissionParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFResubmissionParams JDFMessage::GetResubmissionParams(int iSkip) const{
		return GetValidElement(elm_ResubmissionParams,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFReturnQueueEntryParams JDFMessage::GetCreateReturnQueueEntryParams(int iSkip){
		JDFReturnQueueEntryParams e=GetCreateValidElement(elm_ReturnQueueEntryParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFReturnQueueEntryParams JDFMessage::AppendReturnQueueEntryParams(){
		JDFReturnQueueEntryParams e=AppendValidElement(elm_ReturnQueueEntryParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFReturnQueueEntryParams JDFMessage::GetReturnQueueEntryParams(int iSkip) const{
		return GetValidElement(elm_ReturnQueueEntryParams,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFShutDownCmdParams JDFMessage::GetCreateShutDownCmdParams(int iSkip){
		JDFShutDownCmdParams e=GetCreateValidElement(elm_ShutDownCmdParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFShutDownCmdParams JDFMessage::AppendShutDownCmdParams(){
		JDFShutDownCmdParams e=AppendValidElement(elm_ShutDownCmdParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFShutDownCmdParams JDFMessage::GetShutDownCmdParams(int iSkip) const{
		return GetValidElement(elm_ShutDownCmdParams,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	JDFStatusQuParams JDFMessage::GetCreateStatusQuParams(int iSkip){
		JDFStatusQuParams e=GetCreateValidElement(elm_StatusQuParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFStatusQuParams JDFMessage::AppendStatusQuParams(){
		JDFStatusQuParams e=AppendValidElement(elm_StatusQuParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFStatusQuParams JDFMessage::GetStatusQuParams(int iSkip) const{
		return GetValidElement(elm_StatusQuParams,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	JDFStopPersChParams JDFMessage::GetCreateStopPersChParams(int iSkip){
		JDFStopPersChParams e=GetCreateValidElement(elm_StopPersChParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFStopPersChParams JDFMessage::AppendStopPersChParams(){
		JDFStopPersChParams e=AppendValidElement(elm_StopPersChParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFStopPersChParams JDFMessage::GetStopPersChParams(int iSkip) const{
		return GetValidElement(elm_StopPersChParams,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	JDFSubmissionMethods JDFMessage::GetCreateSubmissionMethods(int iSkip){
		JDFSubmissionMethods e=GetCreateValidElement(elm_SubmissionMethods,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFSubmissionMethods JDFMessage::AppendSubmissionMethods(){
		JDFSubmissionMethods e=AppendValidElement(elm_SubmissionMethods);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFSubmissionMethods JDFMessage::GetSubmissionMethods(int iSkip) const{
		return GetValidElement(elm_SubmissionMethods,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	JDFTrackFilter JDFMessage::GetCreateTrackFilter(int iSkip){
		JDFTrackFilter e=GetCreateValidElement(elm_TrackFilter,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFTrackFilter JDFMessage::AppendTrackFilter(){
		JDFTrackFilter e=AppendValidElement(elm_TrackFilter);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFTrackFilter JDFMessage::GetTrackFilter(int iSkip) const{
		return GetValidElement(elm_TrackFilter,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	JDFTrackResult JDFMessage::GetCreateTrackResult(int iSkip){
		JDFTrackResult e=GetCreateValidElement(elm_TrackResult,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFTrackResult JDFMessage::AppendTrackResult(){
		JDFTrackResult e=AppendValidElement(elm_TrackResult);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFTrackResult JDFMessage::GetTrackResult(int iSkip)const{
		return GetValidElement(elm_TrackResult,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFWakeUpCmdParams JDFMessage::GetCreateWakeUpCmdParams(int iSkip){
		JDFWakeUpCmdParams e=GetCreateValidElement(elm_WakeUpCmdParams,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFWakeUpCmdParams JDFMessage::AppendWakeUpCmdParams(){
		JDFWakeUpCmdParams e=AppendValidElement(elm_WakeUpCmdParams);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFWakeUpCmdParams JDFMessage::GetWakeUpCmdParams(int iSkip)const{
		return GetValidElement(elm_WakeUpCmdParams,WString::emptyStr,iSkip);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	
	
}

