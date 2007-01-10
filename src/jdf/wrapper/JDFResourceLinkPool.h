#if !defined(_JDFResourceLinkPool_H__INCLUDED_)
#define _JDFResourceLinkPool_H__INCLUDED_

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
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
// 180700 RP MyString -> WString : all strings now 16 bit
// 270401 RP added IsValid()
// 030501 RP now inherits from JDFPool
// 120202 RP added IsAbstract
// 020502 RP added GetPoolChild, GetPoolChildren
// 080502 RP GetPartValues() first parameter is now JDFRessource::EnumPartIDKey
// 210602 RP changed calls to protected _XXX() to XXXGeneric()
// 260602 RP AppendResource() modified calls to rl.IsInput() -> rl.GetUsage()
// 130902 RP GetLinkedResources now returns vResource
// 210203 RP AppendResource() now moves the resource to a valid resourcepool, if it is not yet there
// 120803 RP ResourceVector now correctly follows <Part> elements
// 291106 NB GetLinkedResources() now processes "...Link" resTypes correctly
//
// JDFResourceLinkPool.h: interface for the JDFResourceLinkPool class.
//
// ////////////////////////////////////////////////////////////////////

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFPool.h"
#include "JDFResource.h"
#include "JDFResourceLink.h"
#include "JDFNode.h"

namespace JDF{
	
	class JDFResource;
	class JDFNode;
	class VoidSet;
	/**
	* Class wrapper for the ResourceLinkPool
	* also Factory for ResourceLink and related objects
	*/
	class JDF_WRAPPERCORE_EXPORT JDFResourceLinkPool : public JDFPool{
		
	public:
		/**
		* null ctor
		*/
		inline JDFResourceLinkPool():JDFPool(){};

		/**
		* copy ctor
		*/
		inline JDFResourceLinkPool(const KElement& other):JDFPool(){
			*this=other;
		};

		/**
		* yacctor
		*/
		
		JDFResourceLinkPool& operator =(const KElement& other);
		/**
		*  dtor
		*/
		virtual ~JDFResourceLinkPool(){};
		
		/**
		* Append resource r to this link pool
		* @param JDFResource r: the resource to append
		* @param boolean input: usage of the link
		* @param boolean bForce: if true create the link, even though it already exists
		* @return JDFResourceLink: link to appended resource
		*/
		JDFResourceLink AppendResource(const JDFResource& r, bool input, bool bForce=false);
		
		/**
		* Convert a link vector to a resource vector
		* @param vElement linkVector: vector to convert
		* @param String resType: kind of resType to add ( * for all)
		* @return vElement: the converted vector
		*/
		static vElement ResourceVector(const vElement& linkVector,const WString& resType=WString::star);
		
		/**
		* Get the links matching mLinkAtt
		* @param mAttribute mLinkAtt: the attribute to search for
		* @return vElement: vector all all elements matching the condition mLinkAtt
		* @deprecated use GetPoolChilderen instead
		*/
		vElement GetLinks(const mAttribute&mLinkAtt=mAttribute::emptyMap)const;
		
		/**
		* Gets all children with the attribute name,mAttrib, nameSpaceURI out of the pool
		* @param WString name: name of the Child
		* @param mAttribute mAttrib: a attribute to search for
		* @return vElement: a vector with all elements in the pool matching the conditions
		*/
		vElement GetPoolChildren(const WString & name=WString::emptyStr, const mAttribute&mAttrib=mAttribute::emptyMap,const WString & nameSpaceURI=WString::emptyStr)const;

		/**
		* get a child resource from the pool matching the parameters
		*
		* @param int i: the index of the child or -1 to make a new one.
		* @param WString name: the name of the element
		* @param mAttribute mAttrib: the attribute of the element
		* @param WString nameSpaceURI: the namespace to search in
		* @return JDFElement: the pool child matching the above conditions
		*/		

		JDFResourceLink GetPoolChild(int i, const WString &resType=WString::emptyStr, const mAttribute&mAttrib=mAttribute::emptyMap, const WString & nameSpaceURI=WString::emptyStr)const;
		/**
		* Get the linked resources matching some conditions
		* the root is always returned, even if the resources are partitioned,
		*
		* @param String resType: type of the resource to get
		* @param mAttribute mLinkAtt: map of ResourceLink attributes to search for
		* @param mAttribute mResAtt: map of Resource attributes to search for
		* @return vResource: vector with all elements matching the conditions
		*/
		vElement GetLinkedResources(const WString& resType=WString::emptyStr,const mAttribute &mLinkAtt=mAttribute::emptyMap,const mAttribute &mResAtt=mAttribute::emptyMap,bool bFollowRefs=false)const;
		
		/**
		* Get the links from the pool (input or output)
		* @param boolean bInOut: what kind of links you want to have (true for input)
		* @param boolean bLink: if false, returns the linked resources, else if true, returns the ResourceLink elements
		* @param String resName: name of the resource to get ( * for all)
		* @param String resProcUsage: process usage of the resource to get (* for all)
		* resName and resProcUsage perform a logical "and"-operation on the links
		* @return vElement: Vector with the found resource links
		* @deprecated
		*/
		vElement GetInOutLinks(bool bInOut,bool bLink=true, const WString& resName=WString::star, const WString& resProcUsage=WString::star)const;
		/**
		* Get the links from the pool (input or output)
		* @param usage  - what kind of links you want to have (input, output) if null all are selected
		* @param boolean bLink: if false, returns the linked resources, else if true, returns the ResourceLink elements
		* @param String resName: name of the resource to get ( * for all)
		* @param String resProcUsage: process usage of the resource to get (* for all)
		* resName and resProcUsage perform a logical "and"-operation on the links
		* @return vElement: Vector with the found resource links
		*/
		vElement getInOutLinks(JDFResourceLink::EnumUsage usage,bool bLink=true, const WString& resName=WString::star, const WString& resProcUsage=WString::star)const;
		/**
		* default initialization
		* @return bool true if successful
		*/
		bool init();
		
		/**
		* Checks if the node is abstract, i.e. is not completely described
		* utility used by GetUnknownElements, GetUnknownAttributes
		* @return boolean: true, if the node is abstract
		*/
		virtual bool IsAbstract()const;

		/**
		* Get the part map vector from all resourcelinks in this pool
		* @param boolean bComplete: if true, expand all parts defined in PartIDKeys
		* @return vmAttribute: map of all parts linked by this resourcelinkpool
		*/
		vmAttribute GetPartMapVector(bool bComplete)const;
		
		
		/**
		* get a vector of all part id keys linked
		* @param void
		* @return Vector
		*/
		vWString GetPartIDKeys()const;
		
		/**
		* Get a list of the values for attribute partType within the leaves of all linked resources
		* @param EnumPartIDKey key: the attribute name you which to get the values
		* @return Vector: vector with all values of the attribute partType
		*/
		vWString GetPartValues(JDFResource::EnumPartIDKey key)const;
		
		/**
		* typesafe validator that does NOT check the pool elements
		* @param EnumValidationLevel level validation level
		* @return bool true if valid
		*/
		virtual bool IsValid(EnumValidationLevel level=ValidationLevel_Complete)const;

		/**
		* typesafe validator
		*/
		virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;
		
		/**
		* return a vector of unknown element nodenames
		*/
		virtual vWString GetUnknownElements(bool bIgnorePrivate,int nMax=99999999)const;
		/**
		* definition of the allowed node names for elements of this type
		* @return comma separated list of valid node names, * if any
		*/
		virtual WString ValidNodeNames()const;
		
		/**
		* get inter-resource linked resource ids
		* @param vWString vDoneRefs:
		* @param bool bRecurse if true, also return recursively linked IDS
		* @return vWString: the vector of referenced resource ids
		*/
		vWString GetHRefs(const vWString& vDoneRefs=vWString::emptyvStr, bool bRecurse=false)const;
		
		/**
		* get inter-resource linked resource ids
		* @param vElement vDoneRefs:
		* @param bool bRecurse if true, also return recursively linked IDS
		* @return vElement: the vector of referenced resource ids
		*/
		VoidSet* GetAllRefs(VoidSet* vDoneRefs, bool bRecurse=false)const;

		/**
		* linkResource - link resource r to this link pool 
		*
		* @param r      - the resource to link
		* @param usage  - usage of the link 
		* @param processUsage  - processUsage of the link null, if none
		*
		* @return JDFResourceLink - new link  resource
		* 
		* @throws JDFException if r is not in the same document as this
		* default: linkResource(r, usage, null)
		* 
		*/
		JDFResourceLink linkResource(JDFResource r, JDFResourceLink::EnumUsage usage, JDFNode::EnumProcessUsage processUsage);

	}; // class JDFResourceLinkPool
}; // namespace JDF

#endif // !defined(_JDFResourceLinkPool_H__INCLUDED_)
