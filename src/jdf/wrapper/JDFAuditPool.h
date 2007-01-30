/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2003 The International Cooperation for the Integration of 
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
// 080102 RP SetPhase modified first parameter to be JDFPhaseTime::EnumStatus
// 130202 RP added IsAbstract, removed IsValid 
// 210302 RP GetAudits added const mAttribute &mAttributes=mAttribute::emptyMap also fixed inversion logic bug
//			 GetAudit modified 3rd parameter to const mAttribute &mAttributes=mAttribute::emptyMap
// 220302 RP remove GetPoolChildName
// 210602 RP changed calls to protected _XXX() to XXXGeneric()
// 260602 RP SetPhase() EnumStatus modified to be JDFElement::EnumStatus
// 230802 RP Bug Fix of misalligned brackets in GetAudits()
// 130902 RP GetLinkedResources now returns vElement
// 211102 RP added optional JDFElements to AddCreated, AddModified
// 010903 | RP | CleanUpMerge() added
//
// GatAuditPool.h: interface for the JDFAuditPool class.
//
// ////////////////////////////////////////////////////////////////////

#if !defined(AFX_JDFAuditPool_H__)
#define AFX_JDFAuditPool_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#include "JDFPool.h"
#include "JDFNotification.h"
#include "JDFProcessRun.h"
#include "JDFPhaseTime.h"
#include "JDFSpawned.h"
#include "JDFMerged.h"
#include "JDFResourceAudit.h"
#include "JDFCreated.h"
#include "JDFModified.h"
#include "JDFNode.h"

namespace JDF{
	
/**
* defines the audit pool and a factory for audit objects
	*/
	class JDF_WRAPPERCORE_EXPORT JDFAuditPool : public JDFPool{
	public:
		
	/**
	* empty ctor	
		*/
		inline JDFAuditPool():JDFPool(){};
		
		/**
		* copy ctor
		*/
		inline JDFAuditPool(const KElement& other):JDFPool(){
			*this=other;
		};
		
		/**
		* yacctor
		*/
		JDFAuditPool& operator =(const KElement& other);
		
		/**
		* dtor
		*/
		virtual ~JDFAuditPool(){};
		
		/**
		* Checks if the node is abstract, i.e. is not completely described
		* utility used by GetUnknownElements, GetUnknownAttributes
		* @return boolean: true, if the node is abstract
		*/
		virtual bool IsAbstract()const;
		
		/**
		* Create a PhaseTime Audit and fill it
		* @param EnumStatus status the node status at this time
		* @param WString& statusDetails details of this status
		* @param vmAttribute &vmParts defines a vector of map of parts for which the PhaseTime is valid
		* @return JDFPhaseTime the newly created PhaseTime audit
		*/		
		JDFPhaseTime SetPhase(EnumStatus status, const WString & statusDetails=WString::emptyStr,const vmAttribute &vmParts=vmAttribute());
		
		/**
		* Get the most recent PhaseTime audit in this pool
		* @return JDFPhaseTime the last  PhaseTime audit
		*/
		JDFPhaseTime GetLastPhase();
		
		/**
		* default initialization
		* @return true if successful
		*/
		bool init();		
		
		/**
		* Append a Created audit element
		* @param WString& by the author keyword
		* @param JDFElement createdElem the created audit
		* @return JDFCreated the newly created Created audit
		*/
		JDFCreated AddCreated(const WString & by=WString::emptyStr,const JDFElement createdElem=JDFElement());
		
		/**
		* Append a Modified audit element
		* @param WString& by the author keyword
		* @param JDFElement modifiedElem the modified element
		* @return JDFModified  the newly created Modified audit
		*/
		JDFModified AddModified(const WString & by=WString::emptyStr,const JDFElement modifiedElem=JDFElement());
		
		/**
		* Append a ResourceAudit audit element
		* @param WString& by the author keyword
		* @return JDFResourceAudit the newly created ResourceAudit audit
		*/
		JDFResourceAudit AddResourceAudit(const WString & by=WString::emptyStr);
		
		/**
		* Append a Spawned audit element
		* @param JDFNode spawned the spawned node
		* @param  vWString & rRefsRO a vector of rRefs that are spawned read-only
		* @param  vWString & rRefsRW a vector of rRefs that are spawned read-write
		* @param WString& by the author keyword
		* @param vmAttribute &vmParts defines a vector of map of parts for which the Spawned is valid
		* @return JDFSpawned the newly created Spawned audit
		*/
		JDFSpawned AddSpawned(JDFNode spawned, const vWString & rRefsRO=vWString::emptyvStr, const vWString & rRefsRW=vWString::emptyvStr, const WString & by=WString::emptyStr, const vmAttribute &vmParts=vmAttribute());
		
		/**
		* Append a Merged audit element
		* @param JDFNode merged the merged node
		* @param  vWString & rRefsOverwritten a vector of rRefs that are overwritten
		* @param WString& by the author keyword
		* @param vmAttribute &vmParts defines a vector of map of parts for which the Spawned is valid
		* @return JDFMerged the newly created Merged audit
		*/		
		JDFMerged AddMerged(JDFNode merged, const vWString & rRefsOverwritten, const WString & by=WString::emptyStr,const vmAttribute &vmParts=vmAttribute());
		
		/**
		* Append a Notification audit element with a Class attribute of Severity
		* @param JDFNotification::EnumClass severity the severity of the notification
		* @param WString& by the author keyword
		* @param vmAttribute &vmParts defines a vector of map of parts for which the Spawned is valid
		* @return JDFNotification the newly created Notification audit
		*/
		JDFNotification AddNotification(JDFNotification::EnumClass severity,const WString & by=WString::emptyStr, const vmAttribute &vmParts=vmAttribute());
		
		/**
		* Append a PhaseTime audit element
		* @param EnumStatus phase The  node status at this time
		* @param WString& by the author keyword
		* @param vmAttribute &vmParts defines a vector of map of parts for which the Spawned is valid
		* @return JDFPhaseTime the newly created PhaseTime audit
		*/
		JDFPhaseTime AddPhaseTime(JDFPhaseTime::EnumStatus phase,const WString & by=WString::emptyStr,const vmAttribute &vmParts=vmAttribute());
		
		/**
		* Add a ProcessRun Audit
		* @param EnumStatus s The  node status at this time
		* @param WString& by the author keyword
		* @param vmAttribute &vmParts defines a vector of map of parts for which the Spawned is valid
		* @return JDFProcessRun the newly created ProcessRun audit
		*/
		JDFProcessRun AddProcessRun(EnumStatus s,const WString & by=WString::emptyStr,const vmAttribute &vmParts=vmAttribute());
		
		/**
		* Get the index'th audit
		* @param int index index of the audit
		* @param EnumAuditType typ type of the audit to take
		* @param mAttribute &mAttributes attribute map to filter the audits
		* @return an Audit that matches the filers
		*/
		JDFAudit GetAudit(int index, JDFAudit::EnumAuditType typ,const mAttribute &mAttributes=mAttribute::emptyMap)const;
		
		/**
		* typesafe validator utility
		* @param EnumValidationLevel level validation level
		* @param bool bIgnorePrivate ignore objects in foreign namespaces
		* @param int nMax size of the returned vector
		* @return vWString vector of invalid attribute names
		*/
		virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;
		
		/**
		* typesafe validator utility
		* @param EnumValidationLevel level validation level
		* @param bool bIgnorePrivate ignore objects in foreign namespaces
		* @param int nMax size of the returned vector
		* @return vWString vector of invalid element names
		*/
		virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;
		
		/**
		* definition of optional elements in the JDF namespace
		*/
		virtual WString OptionalElements()const;		
		
		/**
		* definition of optional attributes in the JDF namespace
		*/
		virtual WString OptionalAttributes()const;
		
				
		/**
		* Set attribute rRefs
		*@param vWString value: the value to set the attribute to
		*/
		void SetrRefs(vWString value);
		
		/**
		* Get string attribute rRefs
		* @return vWString the vaue of the attribute 
		*/
		vWString GetrRefs() const;
		
		/**
		* Typesafe attribute validation of rRefs
		* @param EnumValidationLevel level validation level
		* @return bool true if valid
		*/
		virtual bool ValidrRefs(EnumValidationLevel level) const;
		
		/**
		* get a vector of the audit elements
		* @param EnumAuditType typ  type of audits to get
		* @param mAttribute &mAttributes attribute map to filter the audits
		* @ return vector of Audit elements
		*/
		vElement GetAudits(JDFAudit::EnumAuditType typ=JDFAudit::AuditType_Unknown,const mAttribute &mAttributes=mAttribute::emptyMap)const;
		
		/**
		* Get the linked resources matching some conditions
		* @param mAttribute mResAtt: map of Resource attributes to search for
		* @param boolean bFollowRefs true if internal references shall be followed
		* @return vElement: vector with all elements matching the conditions
		*/
		vElement GetLinkedResources(const mAttribute &mResAtt=mAttribute::emptyMap, bool bFollowRefs=false)const;
		
		/**
		* Gets all children with the attribute name,mAttrib, nameSpaceURI out of the pool
		* @param WString name: name of the Child
		* @param mAttribute mAttrib: a attribute to search for
		* @return vElement: a vector with all elements in the pool matching the conditions
		*/
		vElement GetPoolChildren(const WString & name=WString::emptyStr, const mAttribute&mAttrib=mAttribute::emptyMap)const;
		
		/**
		* Append a new child if no identical child exists
		* @param JDFAudit p: the Child to add to the element
		*/
		void AppendUnique(const JDFAudit & p);
		
		/**
		* Append all children of p for which no identical child exists
		* @param JDFAuditPool p: the Child to add to the element
		*/
		void AppendUnique(const JDFAuditPool & p);
		
		/**
		* clean up the spawn and merge audits in this Node
		* @param EnumCleanUpMerge policy how to clean up the spawn and merge audits after merging
		* @param WString spawnID the SpawnID of the spawn and MergeID of the merge to clean up
		*	if not specified all spawns will be cleaned up
		*/
		void CleanUpMerge(JDFNode::EnumCleanUpMerge cleanPolicy, const WString& spawnID=WString::emptyStr);
		
	protected:
	/**
	* add an audit, called internally by the specialized functions
		*/
		JDFAudit AddAudit(JDFAudit::EnumAuditType typ,const WString &software=WString::emptyStr);

		/**
		* definition of the allowed node names for elements of this type
		* @return comma separated list of valid node names, * if any
		*/
		virtual WString ValidNodeNames()const;
		
	};
};

#endif // !defined(AFX_JDFAuditPool_H__)
