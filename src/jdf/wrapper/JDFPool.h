/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2002 The International Cooperation for the Integration of 
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
// 300401 RP added some refelement support for nodeinfo and customerinfo
// 170501 RP added AppendUnique with JDFPool as parameter
// 220302 RP remove GetPoolChildName, AddPoolElement
// 020502 RP remove 		AddResID, GetHRefs GetvHRefRes
// 210602 RP renamed protected _XXX() to XXXGeneric()
//
// JDFPool.h: interface for the JDFPool class.
//
// provides functionality for "network" containers
// and is the base class for JDFResourcePool
//                       and GarStepNetwork
// ///////////////////////////////////////////////////////////////////

#if !defined(_JDFPool_H___)
#define _JDFPool_H___

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFElement.h"

namespace JDF{
	/**
	superclass for all JDF and JMF pools
	also misused as a base class for NodeInfo and CustomerInfo in order to have a good location for reference handling
	*/
	class JDF_WRAPPERCORE_EXPORT JDFPool : public JDFElement {
	public:
		/**
		* default ctor
		*/
		inline JDFPool():JDFElement(){};
		/**
		* copy ctor
		*/
		inline JDFPool(const KElement & other):JDFElement(){
			*this=other;
		};
		/**
		* yactor
		*/
		JDFPool& operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFPool(){};
		
	protected:		
		/**
		* Gets all children with the attribute name,mAttrib, nameSpaceURI out of the pool<p>
		* this is not simply a version of GetPoolChildren() that is overwritten because the specialized routines have 
		* @param WString name: name of the Child
		* @param mAttribute mAttrib: a attribute to search for
		* @param WString nameSpaceURI: in which nameSpaceURI you want to search
		* @return vElement: a vector with all elements in the pool matching the conditions
		*/
		vElement GetPoolChildrenGeneric(const WString & name=WString::emptyStr, const mAttribute&mAttrib=mAttribute::emptyMap,const WString & nameSpaceURI=WString::emptyStr)const;
		
		/**
		* get a child from the pool matching the parameters
		*
		* @param int i: the index of the child or -1 to make a new one.
		* @param WString name: the name of the element
		* @param mAttribute mAttrib: the attribute of the element
		* @param WString nameSpaceURI: the namespace to search in
		* @return JDFElement: the pool child matching the above conditions
		*/		
		JDFElement GetPoolChildGeneric(int i, const WString & name=WString::emptyStr, const mAttribute&mAttrib=mAttribute::emptyMap, const WString & nameSpaceURI=WString::emptyStr)const;
		
		/**
		* Append a new child if no identical child exists
		* @param JDFElement p: the Child to add to the element
		*/
		void AppendUniqueGeneric(const JDFElement & p);
		/**
		* Append all children of p for which no identical child exists
		* @param JDFPool p: the Child to add to the element
		* @since 170501
		*/
		void AppendUniqueGeneric(const JDFPool & p);
		
		
	};
};

#endif // !defined(_JDFPool_H___)
