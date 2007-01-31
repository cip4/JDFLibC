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
// ////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
// 180700 RP MyString -> WString : all strings now 16 bit
// 040900 RP renamed JDFProcess to JDFNode
// 201100 RP cleanup + comment
// 170501 RP added GetPartMap, GetPartMapVector
// 050601 RP merge AutoAudit stuff into JDFAudit
// 240102 RP add SpawnID support
// 200802 RP ValidTimeStamp() changed datatype 
//           GetInvalidAttributes() added call to ValidTimeStamp()
// 120902 RP GetAuditPool() added
// 221204 RP ValidNodeNames() removed since it is an abstract class
//        RP init() now also appends an ID
//
// JDFAudit.h: interface for the JDFAudit class.
// Handles individual Audit elements
//
// ////////////////////////////////////////////////////////////////////

#if !defined(_JDFAudit_H___INCLUDED_)
#define _JDFAudit_H___INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFElement.h"

namespace JDF{
	/**
	parent class for individual audit types
	*/
	class JDF_WRAPPERCORE_EXPORT JDFAudit : public JDFElement{
		friend class JDFAuditPool;

	public:
		/** 
		* construction / destruction
		*/
		inline JDFAudit():JDFElement(){};
		/**
		* copy ctor
		*/

		inline JDFAudit(const KElement & other):JDFElement(){
			*this=other;
		};
		/**
		* copy equivalance operator
		*/
		JDFAudit &operator =(const KElement& other);

		/**
		* dtor
		*/
		virtual ~JDFAudit(){};

		/**
		* default initialization
		*/
		bool init();

		/**
		* get a prefix for ID creation for the element
		* @return the prefix for the appropriate node 
		* returns "a" for an audit
		*
		*/
		virtual WString GetIDPrefix() const;

		/**
		* Version fixing routine
		*
		* uses heuristics to modify this element and its children to be compatible with a given version
		* in general, it will be able to move from low to high versions but potentially fail 
		* when attempting to move from higher to lower versions
		*
		* @param EnumVersion version: version that the resulting element should correspond to
		* @param bool true if successful
		*/
		virtual bool FixVersion(EnumVersion version);

		/**
		* Typesafe enumerated Audit type
		*/
		enum EnumAuditType{AuditType_Unknown,AuditType_Created,AuditType_Modified,AuditType_Spawned,AuditType_Merged,AuditType_Notification,AuditType_PhaseTime,AuditType_ResourceAudit,AuditType_ProcessRun};

		/**
		* @return the subclass of audit
		*/
		EnumAuditType GetAuditType();

		/**
		* returns the library name
		* @return a string defining this library
		*/
		static WString Software();

		/**
		* Get the parent AuditPool
		* @return JDFAuditPool the parent JDFAuditPool 
		*/
		JDFAuditPool GetAuditPool() const;

		/**
		* typesafe validator
		* @param EnumValidationLevel level validation level
		* @param boolean bIgnorePrivate do not validate elements in private name spaces, if true
		* @param int nMax stop validation after nMax invalid attributes
		*/
		virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

		/** ******************************************************
		// Attribute Getter / Setter
		****************************************************** */

		/**
		* definition of required attributes in the JDF namespace
		*/
		virtual WString RequiredAttributes()const;

		/**
		* definition of optional attributes in the JDF namespace
		*/
		virtual WString OptionalAttributes()const;

		/**
		* Set attribute Author
		* @param WString the author to set
		*/
		virtual void SetAuthor(const WString& value);

		/**
		* Get string attribute Author
		* @return WString the author 
		*/
		virtual WString GetAuthor() const;

		/**
		* Typesafe attribute validation of Author
		*/
		virtual bool ValidAuthor(EnumValidationLevel level=ValidationLevel_Complete) const;

		/**
		* Set attribute AgentVersion
		* @param WString the AgentVersion to set
		*/
		virtual void SetAgentVersion(const WString& value);

		/**
		* Get string attribute AgentVersion
		* @return WString the AgentVersion 
		*/
		virtual WString GetAgentVersion() const;

		/**
		* Typesafe attribute validation of AgentVersion
		*/
		virtual bool ValidAgentVersion(EnumValidationLevel level=ValidationLevel_Complete) const;

		/**
		* Set attribute AgentName
		* @param WString the AgentName to set
		*/
		virtual void SetAgentName(const WString& value);

		/**
		* Get string attribute AgentName
		* @return WString the AgentName 
		*/
		virtual WString GetAgentName() const;

		/**
		* Typesafe attribute validation of AgentName
		*/
		virtual bool ValidAgentName(EnumValidationLevel level=ValidationLevel_Complete) const;

		/**
		Set attribute refID
		*/
		void SetrefID(const WString& value);

		/**
		Get string attribute refID
		*/
		WString GetrefID() const;

		/**
		Typesafe attribute validation of refID
		*/
		bool ValidrefID(EnumValidationLevel level) const;

		/**
		Typesafe attribute validation of ID
		*/
		bool ValidID(EnumValidationLevel level) const;

		/**
		Set attribute SpawnID
		*/
		virtual void SetSpawnID(const WString& value);
		/**
		Get string attribute SpawnID
		*/
		virtual WString GetSpawnID() const;
		/**
		Typesafe attribute validation of SpawnID
		*/
		virtual bool ValidSpawnID(EnumValidationLevel level=ValidationLevel_Complete) const;
		/**
		* Set attribute TimeStamp
		* @since 11.11.2004 takes the parameters of type JDFDate instead of MyDate
		*/
		virtual void SetTimeStamp(JDFDate value=JDFDate());
		/**
		* Get string attribute TimeStamp
		* @since 11.11.2004 returns value of type JDFDate instead of MyDate
		*/
		virtual JDFDate GetTimeStamp() const;

		/**
		Typesafe attribute validation of TimeStamp
		*/
		virtual bool ValidTimeStamp(EnumValidationLevel level) const;

		/**
		* Typesafe enumerated Audit type
		*/
		static const WString& AuditTypeString();
		/**
		Typesafe enumerated Audit type
		*/
		static WString AuditTypeString(EnumAuditType i);
		//////////////////////////////////////////////////////////////////////
		/**
		* @return Returns the static agentName.
		*/
		static WString getStaticAgentName();

		//////////////////////////////////////////////////////////////////////
		/**
		* @param agentName The aAgentName to set.
		*/
		static void setStaticAgentName(const WString& _agentName);

		//////////////////////////////////////////////////////////////////////
		/**
		* @return Returns the static agentVersion.
		*/
		static WString getStaticAgentVersion();

		//////////////////////////////////////////////////////////////////////
		/**
		* @param agentVersion The agentVersion to set.
		*/
		static void setStaticAgentVersion(const WString& _agentVersion);
	};
};

#endif // !defined(_JDFAudit_H___INCLUDED_