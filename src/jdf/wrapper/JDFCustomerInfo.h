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
/*
*
*
* COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
*      ALL RIGHTS RESERVED 
*
*  Author: Dr. Rainer Prosi using JDFSchema code generator 
* 
* Warning! very preliminary test version. Interface subject to change without prior notice!
* Revision history:
* created 2001-07-02
* 260302 RP added GetHRefs()
* 130902 RP GetLinkedResources now returns vElement
* 290803 RP Removed GetRRefs - now handled by JDFElement
*
*/

#if !defined _JDFCustomerInfo_H_
#define _JDFCustomerInfo_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "AutoJDF/JDFAutoCustomerInfo.h"
namespace JDF{
	/*
	*********************************************************************
	class JDFCustomerInfo : public JDFAutoCustomerInfo

	*********************************************************************
	*/
	/**
	* Typesafe resource wrapper calss JDFCustomerInfo 
	*
	* This file is hand edited and will not be regenerated
	*/
	class JDFCompany;

	class JDF_WRAPPERCORE_EXPORT JDFCustomerInfo : public JDFAutoCustomerInfo{
	public:


		// Constructors / Destructors  


		/**
		* null ctor
		*/
		inline JDFCustomerInfo():JDFAutoCustomerInfo(){};
		/**
		* copy ctor
		*/
		inline JDFCustomerInfo(const KElement & other):JDFAutoCustomerInfo( ){
			*this=other;
		};
		/**
		* copy equivalance operator
		*/
		JDFCustomerInfo &operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFCustomerInfo(){};

		/**
		* Get the linked resources matching some conditions
		* @param mAttribute mResAtt: map of Resource attributes to search for
		* @param boolean bFollowRefs true if internal references shall be followed
		* @return vElement: vector with all elements matching the conditions
		*/
		vElement GetLinkedResources(const mAttribute &mResAtt=mAttribute::emptyMap, bool bFollowRefs=false)const;
		/** 
		* Typesafe initialization
		* @return true if succcessful
		*/
		virtual bool init();

		/**
		* get a Contact with at least one contacttype set
		* @param contactType the contatcttype string
		* @param iSkip, number of occurrences to skip - if 0 take the first
		* @return a matching JDFContact, null if none are found
		*/
		JDFContact GetContactWithContactType(const WString& contactType,int iSkip) const;

		/**
		* get a list of Contacts with at least one contacttype set
		* @param contactType the contatcttype string
		* @return VElement the vector of matching JDFContacts, null if none are found
		*/
		vElement JDFCustomerInfo::getContactVectorWithContactType(const WString& contactType)const;

	}; // endJDFCustomerInfo

	// ******************************************************
}; // end namespace JDF
#endif //_JDFCustomerInfo_H_
