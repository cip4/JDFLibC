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
/************************************************************************
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created RP 060502
//
// XMLDocUserData.h: interface for the XMLDocUserData class.
// 
// The Document class 
//
//
**********************************************************************/

#ifndef _XMLDocUserData_H__
#define _XMLDocUserData_H__

#include <jdf/lang/vWString.h>


namespace JDF{
	//fowards
	class KElement;
	
	class JDF_WRAPPERCORE_EXPORT XMLDocUserData{
	public:
	/**
	* ctor
		*/
		XMLDocUserData();
		/**
		* dtor
		*/
		virtual ~XMLDocUserData();
		
		/**
		* enumeration for policy to set dirty elements
		*/
		enum EnumDirtyPolicy{DirtyPolicy_None,DirtyPolicy_ID,DirtyPolicy_XPath};

		/**
		* Set the dirty policy to dirtPol
		*/
		void SetDirtyPolicy(EnumDirtyPolicy dirtPol);

		/**
		* get a vector of all XPaths of elements that are dirty
		* @return vWString the vector of element XPaths
		*/
		const vWString& GetDirtyXPaths()const;

		/**
		* get a vector of all IDs of elements that are dirty
		* @return vWString the vector of element IDs
		*/
		const vWString& GetDirtyIDs()const;
		
		/**
		* clear the vector of all IDs of elements that are dirty
		* @return void
		*/
		void ClearDirtyIDs();
		
		/**
		* add string id uniquely to the vector of dirty ids
		* @param WString id the id to be added to the dirty list
		* @return vWString the vector of element IDs after appending id
		*/
		const vWString&  SetDirty(const WString &id);
		/**
		* add string id uniquely to the vector of dirty ids
		* @param KElement * pE the element to be added to the dirty list
		* @param bool bAttribute if true, only attributes are dirty, else also sub-elements
		* @return vWString the vector of element IDs after appending id
		*/
		const vWString&  SetDirty(const KElement * pE, bool bAttribute);
		
		/**
		* is the node with ID dirty?
		* @param WString id the id to be checked
		* @return bool true if the node with ID=id is dirty
		*/
		bool IsDirty(const WString &id)const;
		
		/**
		* Set the target  to target
		* @param KElement target the target element
		*/
		void SetTarget(const KElement& target, const WString& id);
		
		/**
		* Remove the target from the target list
		* @param KElement target the target element
		*/
		void RemoveTarget(const KElement& target);
		
		/**
		* Get the target with ID=id
		* @param WString id the id of the target to search 
		* @return KElement target the target element
		*/
		KElement GetTarget(const WString& id)const;
		
		/**
		* clear the map of all targets
		* @return void
		*/
		void ClearTargets();

		/**
		* switch on or off the caching method for ids
		* @param bCache if true, the ids will be cached
		*/
		void setIDCache(bool bCache);

		/**
	    * get the status of the caching method for ids
		* @return if true, the ids will be cached
		*/
		bool getIDCache();
		
	protected:
		
		/** 
		* vWString vDirtyID the vector of dirty IDs or dirty XPaths
		*/
		vWString vDirtyID;

		/**
		*
		*/
		EnumDirtyPolicy dirtyPolicy;
		/** 
		* map of ID KElement pairs is casted internally
		*/
		void* mapTarget;
	};
}

#endif // !defined(_XMLDocUserData_H__)
