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
/*
*
*
* COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
*      ALL RIGHTS RESERVED 
*
*  Author: Dr. Rainer Prosi using JDFSchema code generator 
* 
* Warning! preliminary version. Interface subject to change without prior notice!
* Revision history:
* created 2002-11-08
* 131102 RP GetResourceLinks() added
*
* based on JDF Schema version JDF_1_1_RM.xsd
*
*/
#if !defined _JDFPipeParams_H_
#define _JDFPipeParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "AutoJDF/JDFAutoPipeParams.h"
namespace JDF{
	/*
	*********************************************************************
	class JDFPipeParams : public JDFAutoPipeParams

	*********************************************************************
	*/
	/**
	* Typesafe resource wrapper class JDFPipeParams 
	*
	* This file is hand edited and will not be regenerated
	*/
	class JDF_WRAPPERCORE_EXPORT JDFPipeParams : public JDFAutoPipeParams{
	public:


		// Constructors / Destructors  


		/**
		* null ctor
		*/
		inline JDFPipeParams():JDFAutoPipeParams(){};
		/**
		* copy ctor
		*/
		inline JDFPipeParams(const KElement & other):JDFAutoPipeParams(){
			*this=other;
		};
		/**
		* copy equivalance operator
		*/
		JDFPipeParams &operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFPipeParams(){};

		/**
		* Gets all children with the attribute name,mAttrib, nameSpaceURI out of the pool
		* @param WString name: name of the Child
		* @param mAttribute mAttrib: a attribute to search for
		* @return vElement: a vector with all elements in the pool matching the conditions
		*/
		vElement GetResourceLinks(const WString & name=WString::emptyStr, const mAttribute&mAttrib=mAttribute::emptyMap,const WString & nameSpaceURI=L"")const;

		/**
		* Gets the ResourceLink from the PipeParams element
		* @return ResorceLink: the resource link
		*/
		JDFResourceLink getResourceLink()const;

		/** 
		* 
		* @param WString resName, name of the resource to get/create
		* @return JDFCostCenter The element
		*/
		JDFResource GetCreateResource(const WString &resName);

		/**
		* const get Resource
		* @param WString resName, name of the resource to get/create
		* @return JDFResource The element
		*/
		JDFResource GetResource(const WString &resName=WString::emptyStr)const;

		/**
		* Append  Resource
		* @param WString resName, name of the resource to get/create
		*/

		JDFResource AppendResource(const WString &resName);
		/**
		* append  ResourceLink
		* @param linkName name of the ResourceLink to append a link for
		* @param bInput if true, the link is an input link
		* @return JDFResourceLink: the appended element 
		*/
		JDFResource AppendResourceLink(const WString &resName, bool bInput);

		/**
		* return a vector of unknown element nodenames
		*/

		virtual vWString GetUnknownElements(bool bIgnorePrivate,int nMax=99999999)const;
	}; // endJDFPipeParams

	// ******************************************************
}; // end namespace JDF
#endif //_JDFPipeParams_H_
