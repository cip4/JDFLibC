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
// ////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// 110201 RP added OptionalAttributes,OptionalElements,ValidNodeNames
// 110202 RP removed OptionalAttributes,OptionalElements,ValidNodeNames
// 130802 RP added GetPoolChild, GetPoolChildren
// 190902 RP SetStatus(const mAttribute&mPart,JDFNode::EnumStatus s) cleanup for 1.1
//
// JDFStatusPool.h: interface for the JDFStatusPool class.
//
// ////////////////////////////////////////////////////////////////////

#if !defined(_JDFStatusPool_H___)
#define _JDFStatusPool_H___

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#include "AutoJDF/JDFAutoStatusPool.h"

namespace JDF{
	class JDFPartStatus;
	/**
	* defines the status pool and a factory for PartStatus objects
	*/
	class JDF_WRAPPERCORE_EXPORT JDFStatusPool : public JDFAutoStatusPool{
	public:

		/**
		* empty ctor	
		*/
		JDFStatusPool():JDFAutoStatusPool(){};

		/**
		* copy ctor
		*/
		JDFStatusPool(const KElement& other):JDFAutoStatusPool(){
			*this=other;
		};

		/**
		* yacctor
		*/
		JDFStatusPool& operator =(const KElement& other);

		/**
		* dtor
		*/
		virtual ~JDFStatusPool(){};


		/**
		* Get the status of a part defined in StatusPool
		* @return the status for the entire StatusPool
		*/
		EnumStatus GetStatus()const{
			return JDFPool::GetStatus();
		};

		/**
		* Get the status of a part defined in StatusPool
		* @param mAttribute&mPart filter for the part to get the status
		* @return the status for the filter defined in mPart
		*/
		EnumStatus GetStatus(const mAttribute&mPart)const;

		/**
		* Get the statusdetails of a part defined in StatusPool
		* @return the status for the entire StatusPool
		*/
		WString GetStatusDetails()const{
			return JDFAutoStatusPool::GetStatusDetails();
		};

		/**
		* Get the statusdetails of a part defined in StatusPool
		* @param mAttribute&mPart filter for the part to get the status
		* @return the status for the filter defined in mPart
		*/
		WString GetStatusDetails(const mAttribute&mPart)const;

		/**
		* Set the status of the entire StatusPool
		* @param EnumStatus s the status for the filter defined in mPart
		*/
		void SetStatus(EnumStatus s);

		/**
		* Set the status of a part defined in StatusPool
		* @param mAttribute&mPart filter for the part to set the status
		* @param EnumStatus s the status for the filter defined in mPart
		* @param WString statusDetails the statusdetails for this part
		*/
		void SetStatus(const mAttribute&mPart,EnumStatus s, const WString& statusDetails=WString::emptyStr);

		/**
		* Set the status of a vector of parts defined in StatusPool
		* @param vmAttribute&mPart filter for the part to set the status
		* @param EnumStatus s the status for the filter defined in mPart
		* @param WString statusDetails the statusdetails for this part
		*/
		void SetStatus(const vmAttribute&mPart,EnumStatus s, const WString& statusDetails=WString::emptyStr);

		/**
		* Get a PartStatus that fits to the filter defined by mPart
		* @param mAttribute&mPart filter for the part to set the status
		* @return the PartStatus that fits
		*/
		JDFPartStatus GetPartStatus(const mAttribute&mPart)const;

		/**
		* Get a vector of PartStatus that fits to the filter defined by mPart
		* @param vmAttribute&mPart filter vector for the part to set the status
		* @return the PartStatus that fits
		*/
		vElement GetPartStatusVector(const vmAttribute&mPart)const;

		/**
		* Get a vector of PartStatus that fits to the filter defined by mPart
		* @param vmAttribute&mPart filter vector for the part to set the status
		* @return the PartStatus that fits
		*/
		vElement GetMatchingPartStatusVector(const mAttribute&mPart)const;

		/**
		* Get a PartStatus that fits to the filter defined by mPart
		* @param mAttribute&mPart filter for the part to set the status
		* @return the PartStatus that fits
		*/
		JDFPartStatus GetCreatePartStatus(const mAttribute&mPart);

		/**
		* Get a vector of PartStatus that fits to the filter defined by mPart
		* @param vmAttribute&mPart filter vector for the part to set the status
		* @return the PartStatus that fits
		*/
		vElement GetCreatePartStatusVector(const vmAttribute&mPart);

		/**
		* Gets all children with the attribute name,mAttrib, nameSpaceURI out of the pool
		* @param mAttribute mAttrib: a attribute to search for
		* @return vElement: a vector with all elements in the pool matching the conditions
		*/
		vElement GetPoolChildren(const mAttribute&mAttrib=mAttribute::emptyMap)const;

		/**
		* get a child from the pool matching the parameters
		* @param int i: the index of the child or -1 to make a new one.
		* @param WString name: the name of the element
		* @param mAttribute mAttrib: a attribute to search for
		* @return JDFPartStatus: the pool child matching the above conditions
		*/		
		JDFPartStatus GetPoolChild(int i, const mAttribute&mAttrib=mAttribute::emptyMap)const;
		/**
		* Typesafe attribute validation of Status
		* @param EnumValidationLevel level element validation level 
		* @return bool true if valid
		*/
		virtual bool ValidStatus(EnumValidationLevel level=ValidationLevel_Complete) const;
	};
};

#endif // !defined(_JDFStatusPool_H___)
