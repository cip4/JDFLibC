/*
* The CIP4 Software License, Version 1.0
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
// ////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created  17.Feb.2000
// 180700 RP MyString -> WString : all strings now 16 bit
// 121101 RP remove type argument to get / set
//		     added AppendXXX methods
// 031201 RP renamed GetMessage to GetAnyMessage to avoid windows GetMessage macro redefinition
// 130602 RP modifications in GetMessageElement()
// 150602 RP added GetInvalidElements(), RequiredElements()
// 160602 RP added EnumTyp to calls of AppendCommand/Response/...
// 180602 RP init() added call to GetSchemaURL()
// 040702 RP added ValidVersion()
// 040702 RP init() added call to SetVersion()
// 120802 RP removed GetInvalidElements(), OptionalElements() - these are handled by JDFAutoJMF
// 270902 RP added RequiredAttributes for xmlns handling
//
// JDFJMF.h: interface for the JDFJMF class.
//
// ////////////////////////////////////////////////////////////////////

#if !defined(_JDFJMF_H__INCLUDED_)
#define _JDFJMF_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AutoJDF/JDFAutoJMF.h"
#include "JDFMessage.h"

namespace JDF{
/**
The wrapper for JMF messages, i.e. the root of a JMF document
this is still a big construction site
	*/
	class JDFResponse;
	class JDFQuery;
	class JDFSignal;
	class JDFCommand;
	class JDFAcknowledge;
	
	
	class JDF_WRAPPERCORE_EXPORT JDFJMF : public JDFAutoJMF{
		
		
	public:
	/**
	* default ctor
		*/
		JDFJMF();
		
		/**
		* dtor
		*/
		virtual ~JDFJMF(){};
		
		/**
		* copy ctor
		*/
		JDFJMF(const KElement & other):JDFAutoJMF(){
			*this=other;
		};
		
		/**
		* yacctor
		*/
		JDFJMF &operator =(const KElement& other);
		
		/**
		* definition of required attributes in the JDF namespace
		*/
		virtual WString RequiredAttributes()const;
		
		/**
		* Get the ith message, regardless of type
		* @param int i index of the message
		* @return JDFMessage the message element
		*/
		JDFMessage GetAnyMessage(int i)const;
		
		/**
		* Get the ith query,
		* @param int i index of the message
		* @return JDFQuery the message element
		*/
		JDFQuery GetQuery(int i=0)const;
		
		/**
		* Get the ith response,
		* @param int i index of the message
		* @return JDFResponse the message element
		*/
		JDFResponse GetResponse(int i=0)const;
		
		/**
		* Get the ith signal,
		* @param int i index of the message
		* @return JDFSignal the message element
		*/
		JDFSignal GetSignal(int i=0)const;
		
		/**
		* Get the ith command,
		* @param int i index of the message
		* @return JDFCommand the message element
		*/
		JDFCommand GetCommand(int i=0)const;
		
		/**
		* Get the ith acknowledge,
		* @param int i index of the message
		* @return JDFAcknowledge the message element
		*/
		JDFAcknowledge GetAcknowledge(int i=0)const;
		
		/**
		* Get the ith Registration,
		* @param int i index of the message
		* @return JDFAcknowledge the message element
		*/
		JDFRegistration GetRegistration(int i=0)const;
		
		/**
		* Get the ith query,
		* @param int i index of the message
		* @return JDFQuery the message element
		*/
		JDFQuery GetCreateQuery(int i=0);
		
		/**
		* Get the ith response,
		* @param int i index of the message
		* @return JDFResponse the message element
		*/
		JDFResponse GetCreateResponse(int i=0);
		
		/**
		* Get the ith signal,
		* @param int i index of the message
		* @return JDFSignal the message element
		*/
		JDFSignal GetCreateSignal(int i=0);
		
		/**
		* Get the ith command,
		* @param int i index of the message
		* @return JDFCommand the message element
		*/
		JDFCommand GetCreateCommand(int i=0);
		
		/**
		* Get the ith acknowledge,
		* @param int i index of the message
		* @return JDFAcknowledge the message element
		*/
		JDFAcknowledge GetCreateAcknowledge(int i=0);
		
		/**
		* Get the ith Registration,
		* @param int i index of the message
		* @return JDFAcknowledge the message element
		*/
		JDFRegistration GetCreateRegistration(int i=0);
		
		/**
		* default initializaion of a JMF
		* @return true if successful
		*/
		bool init();
		
		/**
		* Append a query,
		* @param JDFMessage::EnumTyp typ the type attribute of the appended message
		* @return JDFQuery the newly created message element
		*/
		JDFQuery AppendQuery(JDFMessage::EnumType typ);
		
		/**
		* Append a Signal,
		* @param JDFMessage::EnumTyp typ the type attribute of the appended message
		* @return JDFQuery the newly created message element
		*/
		JDFSignal AppendSignal(JDFMessage::EnumType typ);
		
		/**
		* Append a Command,
		* @param JDFMessage::EnumTyp typ the type attribute of the appended message
		* @return JDFQuery the newly created message element
		*/
		JDFCommand AppendCommand(JDFMessage::EnumType typ);
		
		/**
		* Append a Response,
		* @param JDFMessage::EnumTyp typ the type attribute of the appended message
		* @return JDFQuery the newly created message element
		*/
		JDFResponse AppendResponse(JDFMessage::EnumType typ);
		
		/**
		* Append an Acknowledge,
		* @param JDFMessage::EnumTyp typ the type attribute of the appended message
		* @return JDFQuery the newly created message element
		*/
		JDFAcknowledge AppendAcknowledge(JDFMessage::EnumType typ);
		
		/**
		* Append an Acknowledge,
		* @param JDFMessage::EnumTyp typ the type attribute of the appended message
		* @return JDFQuery the newly created message element
		*/
		JDFRegistration AppendRegistration(JDFMessage::EnumType typ);
		
		/**
		* get a vector of all messages in this JMF 
		* @param JDFMessage::EnumFamily family requested message family
		* @param JDFMessage::EnumType typ requested message type
		* @return vElement all message elements
		*/
		vElement GetMessageVector(JDFMessage::EnumFamily family=JDFMessage::Family_Unknown, JDFMessage::EnumType typ=JDFMessage::Type_Unknown)const;
		
		/**
		* get the number of messages in this JMF 
		* @param JDFMessage::EnumFamily family requested message family
		* @param JDFMessage::EnumType typ requested message type
		* @return int number of message elements
		*/
		int NumMessages(JDFMessage::EnumFamily family=JDFMessage::Family_Unknown, JDFMessage::EnumType typ=JDFMessage::Type_Unknown)const;
		
		/** 
		* checks whether q is a valid query that is implemented
		* this routine should be overwritten
		* @return bool true if the query is implemented
		*/
		virtual bool IsQueryImplemented(const JDFQuery& q);
		
		/**
		* Append a Message,
		* @param JDFMessage::EnumTyp typ the type attribute of the appended message
		* @return JDFMessage the newly created message element
		* @deprecated use appendMessageElement (family, EnumType::Type_Unknown);
		*/
		JDFMessage AppendMessageElement(JDFMessage::EnumFamily family);

		/**
		 * append a message element to this
		 * @param family the Message family - Query, Acknowledge, Command, Response, Registration or Signal
		 * @param typ the messages @Type value, EnumType::Type_Unknown if unknown
		 * @return the newly created message
		 */
		JDFMessage appendMessageElement(JDFMessage::EnumFamily family, JDFMessage::EnumType typ);
		
		/**
		* Get an existing Message,
		* @param JDFMessage::EnumTyp typ the type attribute of the appended message
		* @param i which message to get
		* @return JDFMessage the newly created message element
		*/
		JDFMessage GetMessageElement(JDFMessage::EnumFamily family,int i=0)const;
		
		/**
		* Get a Message, Create it if it does not exist
		* @param JDFMessage::EnumTyp typ the type attribute of the appended message
		* @param i which message to get
		* @return JDFMessage the newly created message element
		*/
		JDFMessage GetCreateMessageElement(JDFMessage::EnumFamily family,int i=0);
		
		/**
		* Typesafe attribute validation of Version
		* @param EnumValidationLevel level validation level
		* @return bool true if valid
		*/
		virtual bool ValidVersion(EnumValidationLevel level) const;

		/**
		* Checks if the node is abstract, i.e. is not completely described
		* utility used by GetUnknownElements, GetUnknownAttributes
		* @return boolean: true, if the node is abstract
		*/
		virtual bool IsAbstract()const;

		/**
		* Set attribute Version
		* @param EnumVersion value: the value to set the attribute to
		*/
		void SetEnumVersion(EnumVersion value);

	};
};
#endif // !defined(_JDFJMF_H__INCLUDED_)
