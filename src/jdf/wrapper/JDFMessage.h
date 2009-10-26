#if !defined(_JDFMESSAGE_H__)
#define _JDFMESSAGE_H__

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
// ////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
// 180700 RP MyString -> WString : all strings now 16 bit
// 160602 RP added IsValidMessageElement() and all detailed mesaage element manipulation
// 230802 RP GetValidTypeVector() added Status to valid types of "Queue"
// 300802 RP IsValidMessageElement() now returns true if not in JDF namespace
//        RP added DeviceList Support
//        RP added QueueEntryDefList Support
// 281102 RP GetValidTypeVector bug fix for StopPersChParams
// 230703 RP removed HasXXX NumXXX RemoveXXX
// 281106 NB updated EnumCmdTypeObj, EnumQueryTypeObj, EnumResponseTypeObj,
//           CmdTypeObjString(), QueryTypeObjString(), ResponseTypeObjString()
// 281106 NB updated GetValidTypeVector()
//
// JDFMessage.h: interface for the JDFMessage class.
//
// ////////////////////////////////////////////////////////////////////

#include "AutoJDF/JDFAutoMessage.h"

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

namespace JDF{
	
	class JDFDevice;
	class JDFDeviceFilter;
	class JDFDeviceInfo;
	class JDFDeviceList;
	class JDFFlushedResources;
	class JDFEmployeeDef;
	class JDFFlushQueueParams;
	class JDFFlushResourceParams;
	class JDFIDInfo;
	class JDFJDFController;
	class JDFJDFService;
	class JDFJobPhase;
	class JDFKnownMsgQuParams;
	class JDFMessageService;
	class JDFMsgFilter;
	class JDFNewJDFCmdParams;
	class JDFNewJDFQuParams;
	class JDFNodeInfoCmdParams;
	class JDFNodeInfoQuParams;
	class JDFNodeInfoResp;
	class JDFNotificationDef;
	class JDFNotificationFilter;
	class JDFOccupation;
	class JDFPipeParams;
	class JDFQueue;
	class JDFQueueFilter;
	class JDFQueueEntry;
	class JDFQueueEntryDef;
	class JDFQueueEntryDefList;
	class JDFQueueEntryPriParams;
	class JDFQueueEntryPosParams;
	class JDFQueueFilter;
	class JDFQueueSubmissionParams;
	class JDFRequestQueueEntryParams;
	class JDFResourceCmdParams;
	class JDFResourcePullParams;
	class JDFResourceQuParams;
	class JDFResourceInfo;
	class JDFResubmissionParams;
	class JDFReturnQueueEntryParams;
	class JDFShutDownCmdParams;
	class JDFStatusQuParams;
	class JDFStopPersChParams;
	class JDFSubmissionMethods;
	class JDFTrackFilter;
	class JDFTrackResult;
	class JDFWakeUpCmdParams;
	class JDFJMF;
	
	/**
	* wrapper for individual JMF message families - Acknowledge, Command, Query, Response, Signal
	* note that the JMF element itself is wrapped by JDFJMF
	* since the JMF message is a pool for individual messages
	*/
	
	class JDF_WRAPPERCORE_EXPORT JDFMessage  : public JDFAutoMessage{
		
		friend class JDFJMF;
		
	public:
		
	/**
	* default emty constructor
		*/
		JDFMessage():JDFAutoMessage(){};
		/**
		* copy constructor
		*/
		inline JDFMessage(const KElement & other):JDFAutoMessage()  { *this=other; };
		
		/**
		* Copy equivalance operator
		*/
		JDFMessage &operator =(const KElement& other);
		
		/**
		* Destructor
		*/
		virtual ~JDFMessage(){};
		
		/**
		* Is a message with this name a message element?
		*
		* @return bool: true if 'this' is a message
		*/
		bool IsMessageElement()const;
		
		/**
		* Validator
		*
		* @return bool: true if 'this' is a valid message
		*/
		virtual bool IsValid(EnumValidationLevel level=ValidationLevel_Complete)const;
		
		/**
		* Standard initialization
		*
		* @return bool: true if valid
		*/
		virtual bool init();
		
		/**
		* Typesafe validator utility
		*
		* @param EnumValidationLevel level: validation level
		* @param bool bIgnorePrivate: ignore objects in foreign namespaces
		* @param int nMax: size of the returned vector
		* @return vWString: vector of invalid element names
		*/
		virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;
		
		/**
		* Definition of optional elements in the JDF namespace
		*
		* @return WString: list of optional elements
		*/
		virtual WString OptionalElements()const;
		
		
		/**
		* Sets the initiating query/command to q
		*
		* @param JDFQuery& q: the query to respond to
		* @return bool: true if successful
		*/
		bool SetQuery(const JDFMessage& q);
		
		/**
		* Message Type  enumeration
		*/
		enum EnumType {Type_Unknown,Type_AbortQueueEntry,Type_CloseQueue,Type_Events,Type_FlushQueue,
			Type_FlushResources,Type_ForceGang,Type_GangStatus,Type_HoldQueue,Type_HoldQueueEntry,Type_KnownControllers,Type_KnownDevices,Type_KnownJDFServices,
			Type_KnownMessages,Type_ModifyNode,Type_NewJDF,Type_NodeInfo,
			Type_Notification,Type_Occupation,Type_OpenQueue,Type_PipeClose,Type_PipePull,
			Type_PipePush,Type_PipePause,Type_QueueEntryStatus,Type_QueueStatus,Type_RequestQueueEntry,Type_RemoveQueueEntry,Type_RepeatMessages,
			Type_Resource,Type_ResourcePull,Type_ResumeQueue,Type_ResumeQueueEntry,Type_ResubmitQueueEntry,Type_ReturnQueueEntry,
			Type_SetQueueEntryPosition,Type_SetQueueEntryPriority,Type_ShutDown,Type_Status,Type_StopPersistentChannel,Type_SubmissionMethods,Type_SubmitQueueEntry,
			Type_SuspendQueueEntry,Type_Track,Type_UpdateJDF,Type_WakeUp};
		 
		/** 
		* Standard vector typedef
		*/
		typedef vint vEnumType;
		
		/**
		* Message Family enumeration
		*/
		enum EnumFamily{Family_Unknown,Family_Query,Family_Signal,Family_Command,Family_Response,Family_Acknowledge,Family_Registration};
		
		/**
		* Message CommandTypeObj enumeration
		*/
		enum EnumCommandTypeObj{CommandTypeObj_Unknown,CommandTypeObj_FlushQueueParams,CommandTypeObj_FlushResourceParams,CommandTypeObj_NewJDFCmdParams,CommandTypeObj_NodeInfoCmdParams,CommandTypeObj_PipeParams,CommandTypeObj_QueueEntryDef,CommandTypeObj_QueueEntryPriParams,CommandTypeObj_QueueEntryPosParams,CommandTypeObj_QueueFilter,CommandTypeObj_QueueSubmissionParams,CommandTypeObj_RequestQueueEntryParams,CommandTypeObj_ResourceCmdParams,CommandTypeObj_ResourcePullParams,CommandTypeObj_ResubmissionParams,CommandTypeObj_ReturnQueueEntryParams,CommandTypeObj_ShutDownCmdParams,CommandTypeObj_StopPersChParams,CommandTypeObj_UpdateJDFCmdParams,CommandTypeObj_WakeUpCmdParams};
		
		/**
		* Message QueryTypeObj enumeration
		*/
		enum EnumQueryTypeObj{QueryTypeObj_Unknown,QueryTypeObj_DeviceFilter,QueryTypeObj_EmployeeDef,QueryTypeObj_KnownMsgQuParams,QueryTypeObj_MsgFilter,QueryTypeObj_ModifyNodeCmdParams,QueryTypeObj_NewJDFQuParams,QueryTypeObj_NodeInfoQuParams,QueryTypeObj_NotificationFilter,QueryTypeObj_QueueEntryDefList,QueryTypeObj_QueueFilter,QueryTypeObj_ResourceQuParams,QueryTypeObj_StatusQuParams,QueryTypeObj_TrackFilter,QueryTypeObj_UpdateJDFCmdParams};
		
		/**
		* Message ResponseTypeObj enumeration
		*/
		enum EnumResponseTypeObj{ResponseTypeObj_Unknown,ResponseTypeObj_Acknowledge,ResponseTypeObj_Command,ResponseTypeObj_DeviceList,ResponseTypeObj_DeviceInfo,ResponseTypeObj_FlushedResources,ResponseTypeObj_IDInfo,ResponseTypeObj_JDFController,ResponseTypeObj_JDFService,ResponseTypeObj_JobPhase,ResponseTypeObj_MessageService,ResponseTypeObj_NodeInfoResp,ResponseTypeObj_NotificationDef,ResponseTypeObj_Occupation,ResponseTypeObj_Queue,ResponseTypeObj_QueueEntry,ResponseTypeObj_Query,ResponseTypeObj_Registration,ResponseTypeObj_ResourceInfo,ResponseTypeObj_Response,ResponseTypeObj_Signal,ResponseTypeObj_SubmissionMethods,ResponseTypeObj_TrackResult};
		
		/**
		* Gets message family
		*
		* @return EnumFamily: the family of the message
		*/
		EnumFamily GetFamily()const;
		
		/**
		* Family string representation
		*
		* @return WString&: comma separated list of message families
		*/
		static const WString& FamilyString();
		
		/**
		* Family string representation
		*/
		static WString FamilyString(EnumFamily i);
		
		/**
		* Returns a vector of valid object names for this family type 
		*
		* @return WString: comma separated valid object types for this family type
		*/
		WString FamilyTypeObj()const;
		
		/**
		* Enumeration strings for Type
		*
		* @return const WString&: comma separated list of enumerated string values 
		*/
		static const WString& TypeString();
		
		/**
		* Enumeration string for enum value
		*
		* @param EnumType value: the enumeration to translate
		* @return WString: the string representation of the enumeration
		*/
		static WString TypeString(EnumType value);
		
		/**
		* Sets attribute Type
		*
		* @param EnumType value: the value to set the attribute to
		*/
		void SetEnumType( EnumType value);
		
		/**
		* Gets typesafe enumerated attribute Type
		*
		* @return EnumType: the enumeration value of the attribute
		*/
		EnumType GetEnumType() const;

		/**
		* Typesafe attribute validation of Type
		*
		* @param EnumValidationLevel level: element validation level 
		* @return bool: true if valid
		*/
		virtual bool ValidType(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		* Enumeration strings for list of CommandTypeObj
		*
		* @return const WString&: comma separated list of enumerated string values 
		*/
		static const WString& CommandTypeObjString();
		
		/**
		* Enumeration strings for list of QueryTypeObj
		*
		* @return const WString&: comma separated list of enumerated string values 
		*/
		static const WString& QueryTypeObjString();
		
		/**
		* Enumeration strings for list of ResponseTypeObj
		*
		* @return const WString&: comma separated list of enumerated string values 
		*/
		static const WString& ResponseTypeObjString();
		
		/**
		* Appends a new KElement to the end of 'this' and validate that it is legal in this context
		*
		* @param WString& elementName: name of the new Element
		* @param String nameSpaceURI: nameSpace of the new element
		* @throws JDFException: if the element to be appended is illegal or
		* there is an attempt to append the element if that doesn't match its cardinality
		* @return KElement: the newly created valid element 
		*/
		KElement AppendValidElement(const WString & elementName,const WString & nameSpaceURI=WString::emptyStr);
		
		/**
		* Gets a child node that is valid in this context <br>
		*
		* @param String nodeName: name of the child node to get
		* @param String nameSpaceURI: namespace to search in
		* @param int iSkip: number of elements with such name and namespace to skip, defaults to 0
		* @throws JDFException: if the element, you are searching for is illegal or
		* there is an attempt to get the element if that doesn't match its cardinality
		* @return KElement: the matching valid element
		*/
		KElement GetValidElement(const WString& nodeName, const WString & nameSpaceURI=WString::emptyStr, int iSkip=0)const;
		
		/**
		* Gets a child node that is valid in this context and optionally creates it if it doesn't exist, <br>
		* if iSkip is more than one larger that the number of elements only one is appended
		*
		* @param String nodeName: name of the child node to get
		* @param String nameSpaceURI: namespace to search in
		* @param int iSkip: number of elements with such name and namespace to skip, defaults to 0
		* @throws JDFException: if the element, you are searching for is illegal or
		* there is an attempt to get the element if that doesn't match its cardinality
		* @return KElement: the matching valid element
		*/
		KElement GetCreateValidElement(const WString& nodeName, const WString & nameSpaceURI=WString::emptyStr, int iSkip=0);

		/**
		* set the attributes type and xsi:type
		* @param typ the type
		*/
		void SetType(const WString& typ);
		/**
		* sets the senderID of this message
		* @param senderID
		*/
		void setSenderID(const WString& senderID);

		////////////////////////////////////////////////////////////////////////////////

		/**
		* sets the senderID of this message
		* @return String the senderID of this message or the SenderID of the parent JMF.
		*/
		WString getSenderID() const;



	protected:

		/**
		* Gets a prefix for ID creation for the element
		*/
		virtual WString GetIDPrefix() const;
		
		/**
		* Checks whether the type of messageElement is valid for this message <br>
		* Always returns true for messages in foreign namespaces, i.e. type="XXX:MyType"
		*
		* @param WString& elementName: the name of the element to be tested
		* @param int iSkip: number of elements with such name to skip, defaults=0 <br>
		* Tests the cardinality of the element for different message element types
		* @return bool: true if valid
		*/
		bool IsValidMessageElement(const WString& elementName, int iSkip=0)const; 
		
		/**
		* Gets a vector of valid messageElement types for this element
		*
		* @param WString elementName: the name of the element to be tested
		* @param int iSkip: number of elements with such name to skip, defaults=0 <br>
		* Tests the cardinality of the element for different message element types
		* @return vEnumType: vector of valid EnumTypes; empty if all are invalid
		*/
		vEnumType GetValidTypeVector(const WString& elementName, int iSkip=0) const;
		
	public:
	//@{	
	/** 
	* Gets of 'this' the iSkip-th Device element.
	* Optionally creates it, if it doesn't exist
	*
	* @param int iSkip: number of elements to skip, defaults to 0
	* @return JDFDevice: the matching Device element
		*/
		JDFDevice GetCreateDevice(int iSkip=0);
		
		/**
		* Appends new Device element to the end of 'this'
		*
		* @return JDFDevice: newly created Device element
		*/
		JDFDevice AppendDevice();
		
		/**
		* Gets of 'this' the iSkip-th Device element 
		* 
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFDevice: the matching Device element
		*/
		JDFDevice GetDevice(int iSkip=0)const;		
		//@}
		

		//@{
		/** 
		* Gets of 'this' the iSkip-th DeviceFilter element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFDeviceFilter: the matching DeviceFilter element
		*/
		JDFDeviceFilter GetCreateDeviceFilter(int iSkip=0);
		
		/**
		* Appends new DeviceFilter element to the end of 'this'
		*
		* @return JDFDeviceFilter: newly created DeviceFilter element
		*/
		JDFDeviceFilter AppendDeviceFilter();

		/**
		* Gets of 'this' the iSkip-th DeviceFilter element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFDeviceFilter: the matching DeviceFilter element
		*/
		JDFDeviceFilter GetDeviceFilter(int iSkip=0)const;
		//@}
		
		
		//@{
		/** 
		* Gets of 'this' the iSkip-th DeviceInfo element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFDeviceInfo: the matching DeviceInfo element
		*/
		JDFDeviceInfo GetCreateDeviceInfo(int iSkip=0);
		
		/**
		* Appends new DeviceInfo element to the end of 'this'
		*
		* @return JDFDeviceInfo: newly created DeviceInfo element
		*/
		JDFDeviceInfo AppendDeviceInfo();

		/**
		* Gets of 'this' the iSkip-th DeviceInfo element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFDeviceInfo: the matching DeviceInfo element
		*/
		JDFDeviceInfo GetDeviceInfo(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th DeviceList element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFDeviceList: the matching DeviceList element
		*/
		JDFDeviceList GetCreateDeviceList(int iSkip=0);
		
		/**
		* Appends new DeviceList element to the end of 'this'
		*
		* @return JDFDeviceList: newly created DeviceList element
		*/
		JDFDeviceList AppendDeviceList();

		/**
		* Gets of 'this' the iSkip-th DeviceList element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFDeviceList: the matching DeviceList element
		*/
		JDFDeviceList GetDeviceList(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th EmployeeDef element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFEmployeeDef: the matching EmployeeDef element
		*/
		JDFEmployeeDef GetCreateEmployeeDef(int iSkip=0);
		
		/**
		* Appends new EmployeeDef element to the end of 'this'
		*
		* @return JDFEmployeeDef: newly created EmployeeDef element
		*/
		JDFEmployeeDef AppendEmployeeDef();

		/**
		* Gets of 'this' the iSkip-th EmployeeDef element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFEmployeeDef: the matching EmployeeDef element
		*/
		JDFEmployeeDef GetEmployeeDef(int iSkip=0)const;
		//@}

		
		//@{
		/** 
		* Gets of 'this' the iSkip-th IDInfo element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFIDInfo: the matching IDInfo element
		*/
		JDFIDInfo GetCreateIDInfo(int iSkip=0);
		
		/**
		* Appends new IDInfo element to the end of 'this'
		*
		* @return JDFIDInfo: newly created IDInfo element
		*/
		JDFIDInfo AppendIDInfo();

		/**
		* Gets of 'this' the iSkip-th IDInfo element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFIDInfo: the matching IDInfo element
		*/
		JDFIDInfo GetIDInfo(int iSkip=0)const;
		//@}
			

		//@{
		/** 
		* Gets of 'this' the iSkip-th FlushedResources element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFFlushedResources: the matching FlushedResources element
		*/
		JDFFlushedResources GetCreateFlushedResources(int iSkip=0);
		
		/**
		* Appends new FlushedResources element to the end of 'this'
		*
		* @return JDFFlushedResources: newly created FlushedResources element
		*/
		JDFFlushedResources AppendFlushedResources();

		/**
		* Gets of 'this' the iSkip-th FlushedResources element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFFlushedResources: the matching FlushedResources element
		*/
		JDFFlushedResources GetFlushedResources(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th FlushQueueParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFFlushQueueParams: the matching FlushQueueParams element
		*/
		JDFFlushQueueParams GetCreateFlushQueueParams(int iSkip=0);
		
		/**
		* Appends new FlushQueueParams element to the end of 'this'
		*
		* @return JDFFlushQueueParams: newly created FlushQueueParams element
		*/
		JDFFlushQueueParams AppendFlushQueueParams();

		/**
		* Gets of 'this' the iSkip-th FlushQueueParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFFlushQueueParams: the matching FlushQueueParams element
		*/
		JDFFlushQueueParams GetFlushQueueParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th FlushResourceParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFFlushResourceParams: the matching FlushResourceParams element
		*/
		JDFFlushResourceParams GetCreateFlushResourceParams(int iSkip=0);
		
		/**
		* Appends new FlushResourceParams element to the end of 'this'
		*
		* @return JDFFlushResourceParams: newly created FlushResourceParams element
		*/
		JDFFlushResourceParams AppendFlushResourceParams();

		/**
		* Gets of 'this' the iSkip-th FlushResourceParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFFlushResourceParams: the matching FlushResourceParams element
		*/
		JDFFlushResourceParams GetFlushResourceParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th JDFController element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFJDFController: the matching JDFController element
		*/
		JDFJDFController GetCreateJDFController(int iSkip=0);
		
		/**
		* Appends new JDFController element to the end of 'this'
		*
		* @return JDFJDFController: newly created JDFController element
		*/
		JDFJDFController AppendJDFController();

		/**
		* Gets of 'this' the iSkip-th JDFController element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFJDFController: the matching JDFController element
		*/
		JDFJDFController GetJDFController(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th JDFService element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFJDFService: the matching JDFService element
		*/
		JDFJDFService GetCreateJDFService(int iSkip=0);
		
		/**
		* Appends new JDFService element to the end of 'this'
		*
		* @return JDFJDFService: newly created JDFService element
		*/
		JDFJDFService AppendJDFService();

		/**
		* Gets of 'this' the iSkip-th JDFService element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFJDFService: the matching JDFService element
		*/
		JDFJDFService GetJDFService(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th JobPhase element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFJobPhase: the matching JobPhase element
		*/
		JDFJobPhase GetCreateJobPhase(int iSkip=0);
		
		/**
		* Appends new JobPhase element to the end of 'this'
		*
		* @return JDFJobPhase: newly created JobPhase element
		*/
		JDFJobPhase AppendJobPhase();

		/**
		* Gets of 'this' the iSkip-th JobPhase element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFJobPhase: the matching JobPhase element
		*/
		JDFJobPhase GetJobPhase(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th KnownMsgQuParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFKnownMsgQuParams: the matching KnownMsgQuParams element
		*/
		JDFKnownMsgQuParams GetCreateKnownMsgQuParams(int iSkip=0);
		
		/**
		* Appends new KnownMsgQuParams element to the end of 'this'
		*
		* @return JDFKnownMsgQuParams: newly created KnownMsgQuParams element
		*/
		JDFKnownMsgQuParams AppendKnownMsgQuParams();

		/**
		* Gets of 'this' the iSkip-th KnownMsgQuParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFKnownMsgQuParams: the matching KnownMsgQuParams element
		*/
		JDFKnownMsgQuParams GetKnownMsgQuParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th MessageService element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFMessageService: the matching MessageService element
		*/
		JDFMessageService GetCreateMessageService(int iSkip=0);
		
		/**
		* Appends new MessageService element to the end of 'this'
		*
		* @return JDFMessageService: newly created MessageService element
		*/
		JDFMessageService AppendMessageService();

		/**
		* Gets of 'this' the iSkip-th MessageService element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFMessageService: the matching MessageService element
		*/
		JDFMessageService GetMessageService(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th MsgFilter element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFMsgFilter: the matching MsgFilter element
		*/
		JDFMsgFilter GetCreateMsgFilter(int iSkip=0);
		
		/**
		* Appends new MsgFilter element to the end of 'this'
		*
		* @return JDFMsgFilter: newly created MsgFilter element
		*/
		JDFMsgFilter AppendMsgFilter();

		/**
		* Gets of 'this' the iSkip-th MsgFilter element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFMsgFilter: the matching MsgFilter element
		*/
		JDFMsgFilter GetMsgFilter(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th NewJDFCmdParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFNewJDFCmdParams: the matching NewJDFCmdParams element
		*/
		JDFNewJDFCmdParams GetCreateNewJDFCmdParams(int iSkip=0);
		
		/**
		* Appends new NewJDFCmdParams element to the end of 'this'
		*
		* @return JDFNewJDFCmdParams: newly created NewJDFCmdParams element
		*/
		JDFNewJDFCmdParams AppendNewJDFCmdParams();

		/**
		* Gets of 'this' the iSkip-th NewJDFCmdParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFNewJDFCmdParams: the matching NewJDFCmdParams element
		*/
		JDFNewJDFCmdParams GetNewJDFCmdParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th NewJDFQuParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFNewJDFQuParams: the matching NewJDFQuParams element
		*/
		JDFNewJDFQuParams GetCreateNewJDFQuParams(int iSkip=0);
		
		/**
		* Appends new NewJDFQuParams element to the end of 'this'
		*
		* @return JDFNewJDFQuParams: newly created NewJDFQuParams element
		*/
		JDFNewJDFQuParams AppendNewJDFQuParams();

		/**
		* Gets of 'this' the iSkip-th NewJDFQuParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFNewJDFQuParams: the matching NewJDFQuParams element
		*/
		JDFNewJDFQuParams GetNewJDFQuParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th NodeInfoCmdParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFNodeInfoCmdParams: the matching NodeInfoCmdParams element
		*/
		JDFNodeInfoCmdParams GetCreateNodeInfoCmdParams(int iSkip=0);
		
		/**
		* Appends new NodeInfoCmdParams element to the end of 'this'
		*
		* @return JDFNodeInfoCmdParams: newly created NodeInfoCmdParams element
		*/
		JDFNodeInfoCmdParams AppendNodeInfoCmdParams();

		/**
		* Gets of 'this' the iSkip-th NodeInfoCmdParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFNodeInfoCmdParams: the matching NodeInfoCmdParams element
		*/
		JDFNodeInfoCmdParams GetNodeInfoCmdParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th NodeInfoQuParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFNodeInfoQuParams: the matching NodeInfoQuParams element
		*/
		JDFNodeInfoQuParams GetCreateNodeInfoQuParams(int iSkip=0);
		
		/**
		* Appends new NodeInfoQuParams element to the end of 'this'
		*
		* @return JDFNodeInfoQuParams: newly created NodeInfoQuParams element
		*/
		JDFNodeInfoQuParams AppendNodeInfoQuParams();

		/**
		* Gets of 'this' the iSkip-th NodeInfoQuParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFNodeInfoQuParams: the matching NodeInfoQuParams element
		*/
		JDFNodeInfoQuParams GetNodeInfoQuParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th NodeInfoResp element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFNodeInfoResp: the matching NodeInfoResp element
		*/
		JDFNodeInfoResp GetCreateNodeInfoResp(int iSkip=0);
		
		/**
		* Appends new NodeInfoResp element to the end of 'this'
		*
		* @return JDFNodeInfoResp: newly created NodeInfoResp element
		*/
		JDFNodeInfoResp AppendNodeInfoResp();

		/**
		* Gets of 'this' the iSkip-th NodeInfoResp element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFNodeInfoResp: the matching NodeInfoResp element
		*/
		JDFNodeInfoResp GetNodeInfoResp(int iSkip=0)const;
		//@}

		//@{
		/** 
		* Gets of 'this' the iSkip-th NotificationDef element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFNotificationDef: the matching NotificationDef element
		*/
		JDFNotificationDef GetCreateNotificationDef(int iSkip=0);
		
		/**
		* Appends new NotificationDef element to the end of 'this'
		*
		* @return JDFNotificationDef: newly created NotificationDef element
		*/
		JDFNotificationDef AppendNotificationDef();

		/**
		* Gets of 'this' the iSkip-th NotificationDef element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFNotificationDef: the matching NotificationDef element
		*/
		JDFNotificationDef GetNotificationDef(int iSkip=0)const;
		//@}

		//@{
		/** 
		* Gets of 'this' the iSkip-th NotificationFilter element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFNotificationFilter: the matching NotificationFilter element
		*/
		JDFNotificationFilter GetCreateNotificationFilter(int iSkip=0);
		
		/**
		* Appends new NotificationFilter element to the end of 'this'
		*
		* @return JDFNotificationFilter: newly created NotificationFilter element
		*/
		JDFNotificationFilter AppendNotificationFilter();

		/**
		* Gets of 'this' the iSkip-th NotificationFilter element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFNotificationFilter: the matching NotificationFilter element
		*/
		JDFNotificationFilter GetNotificationFilter(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th Occupation element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFOccupation: the matching Occupation element
		*/
		JDFOccupation GetCreateOccupation(int iSkip=0);
		
		/**
		* Appends new Occupation element to the end of 'this'
		*
		* @return JDFOccupation: newly created Occupation element
		*/
		JDFOccupation AppendOccupation();

		/**
		* Gets of 'this' the iSkip-th Occupation element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFOccupation: the matching Occupation element
		*/
		JDFOccupation GetOccupation(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th PipeParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFPipeParams: the matching PipeParams element
		*/
		JDFPipeParams GetCreatePipeParams(int iSkip=0);
		
		/**
		* Appends new PipeParams element to the end of 'this'
		*
		* @return JDFPipeParams: newly created PipeParams element
		*/
		JDFPipeParams AppendPipeParams();

		/**
		* Gets of 'this' the iSkip-th PipeParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFPipeParams: the matching PipeParams element
		*/
		JDFPipeParams GetPipeParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th Queue element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFQueue: the matching Queue element
		*/
		JDFQueue GetCreateQueue(int iSkip=0);
		
		/**
		* Appends new Queue element to the end of 'this'
		*
		* @return JDFQueue: newly created Queue element
		*/
		JDFQueue AppendQueue();

		/**
		* Gets of 'this' the iSkip-th Queue element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFQueue: the matching Queue element
		*/
		JDFQueue GetQueue(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th QueueEntry element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFQueueEntry: the matching QueueEntry element
		*/
		JDFQueueEntry GetCreateQueueEntry(int iSkip=0);
		
		/**
		* Appends new QueueEntry element to the end of 'this'
		*
		* @return JDFQueueEntry: newly created QueueEntry element
		*/
		JDFQueueEntry AppendQueueEntry();

		/**
		* Gets of 'this' the iSkip-th QueueEntry element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFQueueEntry: the matching QueueEntry element
		*/
		JDFQueueEntry GetQueueEntry(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th QueueEntryDef element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFQueueEntryDef: the matching QueueEntryDef element
		*/
		JDFQueueEntryDef GetCreateQueueEntryDef(int iSkip=0);
		
		/**
		* Appends new QueueEntryDef element to the end of 'this'
		*
		* @return JDFQueueEntryDef: newly created QueueEntryDef element
		*/
		JDFQueueEntryDef AppendQueueEntryDef();

		/**
		* Gets of 'this' the iSkip-th QueueEntryDef element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFQueueEntryDef: the matching QueueEntryDef element
		*/
		JDFQueueEntryDef GetQueueEntryDef(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th QueueEntryDefList element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFQueueEntryDefList: the matching QueueEntryDefList element
		*/
		JDFQueueEntryDefList GetCreateQueueEntryDefList(int iSkip=0);
		
		/**
		* Appends new QueueEntryDefList element to the end of 'this'
		*
		* @return JDFQueueEntryDefList: newly created QueueEntryDefList element
		*/
		JDFQueueEntryDefList AppendQueueEntryDefList();

		/**
		* Gets of 'this' the iSkip-th QueueEntryDefList element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFQueueEntryDefList: the matching QueueEntryDefList element
		*/
		JDFQueueEntryDefList GetQueueEntryDefList(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th QueueEntryPriParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFQueueEntryPriParams: the matching QueueEntryPriParams element
		*/
		JDFQueueEntryPriParams GetCreateQueueEntryPriParams(int iSkip=0);
		
		/**
		* Appends new QueueEntryPriParams element to the end of 'this'
		*
		* @return JDFQueueEntryPriParams: newly created QueueEntryPriParams element
		*/
		JDFQueueEntryPriParams AppendQueueEntryPriParams();

		/**
		* Gets of 'this' the iSkip-th QueueEntryPriParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFQueueEntryPriParams: the matching QueueEntryPriParams element
		*/
		JDFQueueEntryPriParams GetQueueEntryPriParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th QueueEntryPosParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFQueueEntryPosParams: the matching QueueEntryPosParams element
		*/
		JDFQueueEntryPosParams GetCreateQueueEntryPosParams(int iSkip=0);
		
		/**
		* Appends new QueueEntryPosParams element to the end of 'this'
		*
		* @return JDFQueueEntryPosParams: newly created QueueEntryPosParams element
		*/
		JDFQueueEntryPosParams AppendQueueEntryPosParams();

		/**
		* Gets of 'this' the iSkip-th QueueEntryPosParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFQueueEntryPosParams: the matching QueueEntryPosParams element
		*/
		JDFQueueEntryPosParams GetQueueEntryPosParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th QueueFilter element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFQueueFilter: the matching QueueFilter element
		*/
		JDFQueueFilter GetCreateQueueFilter(int iSkip=0);
		
		/**
		* Appends new QueueFilter element to the end of 'this'
		*
		* @return JDFQueueFilter: newly created QueueFilter element
		*/
		JDFQueueFilter AppendQueueFilter();

		/**
		* Gets of 'this' the iSkip-th QueueFilter element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFQueueFilter: the matching QueueFilter element
		*/
		JDFQueueFilter GetQueueFilter(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th QueueSubmissionParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFQueueSubmissionParams: the matching QueueSubmissionParams element
		*/
		JDFQueueSubmissionParams GetCreateQueueSubmissionParams(int iSkip=0);
		
		/**
		* Appends new QueueSubmissionParams element to the end of 'this'
		*
		* @return JDFQueueSubmissionParams: newly created QueueSubmissionParams element
		*/
		JDFQueueSubmissionParams AppendQueueSubmissionParams();

		/**
		* Gets of 'this' the iSkip-th QueueSubmissionParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFQueueSubmissionParams: the matching QueueSubmissionParams element
		*/
		JDFQueueSubmissionParams GetQueueSubmissionParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th RequestQueueEntryParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFRequestQueueEntryParams: the matching RequestQueueEntryParams element
		*/
		JDFRequestQueueEntryParams GetCreateRequestQueueEntryParams(int iSkip=0);
		
		/**
		* Appends new RequestQueueEntryParams element to the end of 'this'
		*
		* @return JDFRequestQueueEntryParams: newly created RequestQueueEntryParams element
		*/
		JDFRequestQueueEntryParams AppendRequestQueueEntryParams();

		/**
		* Gets of 'this' the iSkip-th RequestQueueEntryParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFRequestQueueEntryParams: the matching RequestQueueEntryParams element
		*/
		JDFRequestQueueEntryParams GetRequestQueueEntryParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th ResourceCmdParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFResourceCmdParams: the matching ResourceCmdParams element
		*/
		JDFResourceCmdParams GetCreateResourceCmdParams(int iSkip=0);
		
		/**
		* Appends new ResourceCmdParams element to the end of 'this'
		*
		* @return JDFResourceCmdParams: newly created ResourceCmdParams element
		*/
		JDFResourceCmdParams AppendResourceCmdParams();

		/**
		* Gets of 'this' the iSkip-th ResourceCmdParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFResourceCmdParams: the matching ResourceCmdParams element
		*/
		JDFResourceCmdParams GetResourceCmdParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th ResourceInfo element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFResourceInfo: the matching ResourceInfo element
		*/
		JDFResourceInfo GetCreateResourceInfo(int iSkip=0);
		
		/**
		* Appends new ResourceInfo element to the end of 'this'
		*
		* @return JDFResourceInfo: newly created ResourceInfo element
		*/
		JDFResourceInfo AppendResourceInfo();

		/**
		* Gets of 'this' the iSkip-th ResourceInfo element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFResourceInfo: the matching ResourceInfo element
		*/
		JDFResourceInfo GetResourceInfo(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th ResourcePullParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFResourcePullParams: the matching ResourcePullParams element
		*/
		JDFResourcePullParams GetCreateResourcePullParams(int iSkip=0);
		
		/**
		* Appends new ResourcePullParams element to the end of 'this'
		*
		* @return JDFResourcePullParams: newly created ResourcePullParams element
		*/
		JDFResourcePullParams AppendResourcePullParams();

		/**
		* Gets of 'this' the iSkip-th ResourcePullParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFResourcePullParams: the matching ResourcePullParams element
		*/
		JDFResourcePullParams GetResourcePullParams(int iSkip=0)const;
		//@}
		

		//@{
		/** 
		* Gets of 'this' the iSkip-th ResourceQuParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFResourceQuParams: the matching ResourceQuParams element
		*/
		JDFResourceQuParams GetCreateResourceQuParams(int iSkip=0);
		
		/**
		* Appends new ResourceQuParams element to the end of 'this'
		*
		* @return JDFResourceQuParams: newly created ResourceQuParams element
		*/
		JDFResourceQuParams AppendResourceQuParams();

		/**
		* Gets of 'this' the iSkip-th ResourceQuParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFResourceQuParams: the matching ResourceQuParams element
		*/
		JDFResourceQuParams GetResourceQuParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th ResubmissionParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFResubmissionParams: the matching ResubmissionParams element
		*/
		JDFResubmissionParams GetCreateResubmissionParams(int iSkip=0);
		
		/**
		* Appends new ResubmissionParams element to the end of 'this'
		*
		* @return JDFResubmissionParams: newly created ResubmissionParams element
		*/
		JDFResubmissionParams AppendResubmissionParams();

		/**
		* Gets of 'this' the iSkip-th ResubmissionParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFResubmissionParams: the matching ResubmissionParams element
		*/
		JDFResubmissionParams GetResubmissionParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th ReturnQueueEntryParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFReturnQueueEntryParams: the matching ReturnQueueEntryParams element
		*/
		JDFReturnQueueEntryParams GetCreateReturnQueueEntryParams(int iSkip=0);
		
		/**
		* Appends new ReturnQueueEntryParams element to the end of 'this'
		*
		* @return JDFReturnQueueEntryParams: newly created ReturnQueueEntryParams element
		*/
		JDFReturnQueueEntryParams AppendReturnQueueEntryParams();

		/**
		* Gets of 'this' the iSkip-th ReturnQueueEntryParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFReturnQueueEntryParams: the matching ReturnQueueEntryParams element
		*/
		JDFReturnQueueEntryParams GetReturnQueueEntryParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th ShutDownCmdParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFShutDownCmdParams: the matching ShutDownCmdParams element
		*/
		JDFShutDownCmdParams GetCreateShutDownCmdParams(int iSkip=0);
		
		/**
		* Appends new ShutDownCmdParams element to the end of 'this'
		*
		* @return JDFShutDownCmdParams: newly created ShutDownCmdParams element
		*/
		JDFShutDownCmdParams AppendShutDownCmdParams();

		/**
		* Gets of 'this' the iSkip-th ShutDownCmdParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFShutDownCmdParams: the matching ShutDownCmdParams element
		*/
		JDFShutDownCmdParams GetShutDownCmdParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th StatusQuParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFStatusQuParams: the matching StatusQuParams element
		*/
		JDFStatusQuParams GetCreateStatusQuParams(int iSkip=0);
		
		/**
		* Appends new StatusQuParams element to the end of 'this'
		*
		* @return JDFStatusQuParams: newly created StatusQuParams element
		*/
		JDFStatusQuParams AppendStatusQuParams();

		/**
		* Gets of 'this' the iSkip-th StatusQuParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFStatusQuParams: the matching StatusQuParams element
		*/
		JDFStatusQuParams GetStatusQuParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th StopPersChParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFStopPersChParams: the matching StopPersChParams element
		*/
		JDFStopPersChParams GetCreateStopPersChParams(int iSkip=0);
		
		/**
		* Appends new StopPersChParams element to the end of 'this'
		*
		* @return JDFStopPersChParams: newly created StopPersChParams element
		*/
		JDFStopPersChParams AppendStopPersChParams();

		/**
		* Gets of 'this' the iSkip-th StopPersChParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFStopPersChParams: the matching StopPersChParams element
		*/
		JDFStopPersChParams GetStopPersChParams(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th SubmissionMethods element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFSubmissionMethods: the matching SubmissionMethods element
		*/
		JDFSubmissionMethods GetCreateSubmissionMethods(int iSkip=0);
		
		/**
		* Appends new SubmissionMethods element to the end of 'this'
		*
		* @return JDFSubmissionMethods: newly created SubmissionMethods element
		*/
		JDFSubmissionMethods AppendSubmissionMethods();

		/**
		* Gets of 'this' the iSkip-th SubmissionMethods element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFSubmissionMethods: the matching SubmissionMethods element
		*/
		JDFSubmissionMethods GetSubmissionMethods(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th TrackFilter element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFTrackFilter: the matching TrackFilter element
		*/
		JDFTrackFilter GetCreateTrackFilter(int iSkip=0);
		
		/**
		* Appends new TrackFilter element to the end of 'this'
		*
		* @return JDFTrackFilter: newly created TrackFilter element
		*/
		JDFTrackFilter AppendTrackFilter();

		/**
		* Gets of 'this' the iSkip-th TrackFilter element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFTrackFilter: the matching TrackFilter element
		*/
		JDFTrackFilter GetTrackFilter(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th TrackResult element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFTrackResult: the matching TrackResult element
		*/
		JDFTrackResult GetCreateTrackResult(int iSkip=0);
		
		/**
		* Appends new TrackResult element to the end of 'this'
		*
		* @return JDFTrackResult: newly created TrackResult element
		*/
		JDFTrackResult AppendTrackResult();

		/**
		* Gets of 'this' the iSkip-th TrackResult element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFTrackResult: the matching TrackResult element
		*/
		JDFTrackResult GetTrackResult(int iSkip=0)const;
		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th WakeUpCmdParams element.
		* Optionally creates it, if it doesn't exist
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFWakeUpCmdParams: the matching WakeUpCmdParams element
		*/
		JDFWakeUpCmdParams GetCreateWakeUpCmdParams(int iSkip=0);
		
		/**
		* Appends new WakeUpCmdParams element to the end of 'this'
		*
		* @return JDFWakeUpCmdParams: newly created WakeUpCmdParams element
		*/
		JDFWakeUpCmdParams AppendWakeUpCmdParams();

		/**
		* Gets of 'this' the iSkip-th WakeUpCmdParams element
		*
		* @param int iSkip: number of elements to skip, defaults to 0
		* @return JDFWakeUpCmdParams: the matching WakeUpCmdParams element
		*/
		JDFWakeUpCmdParams GetWakeUpCmdParams(int iSkip=0)const;
		//@}


	};

};

#endif // !defined(_JDFMESSAGE_H__)
