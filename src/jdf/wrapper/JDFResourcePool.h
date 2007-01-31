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
// 030501 RP now inherits from JDFAutoResourcePool
// xxyy01 RP back to inheriting from JDFPool
// 050401 TG CopyResource: setting the SpawnStatus after copying the node
// 060601 TG CopyResource: don't add partitions in unpartitioned resources
//                         to set the spawn status
// 071101 RP CopyResource  fixed HRefs handling
// 101201 RP CopyResource added spawnID parameter
// 060202 RP CopyResource does not add new partitions any more
// 070202 RP removed AddDevice, AddOperator, AddScan and AddPDF
// 020502 RP added GetPoolChild, GetPoolChildren
// 180602 RP GetInvalidElements - added factory
// 210602 RP changed calls to protected _XXX() to XXXGeneric()
// 050902 RP CopyResource() also track rrefs of resources that are here
// 160902 RP CopyResource() added null check to pLeaf
// 160902 RP removed GetInvalidAttributes() - only called super anyhow...
// 221204 RP CopyResource() removed. Replaced by JDFNode::CopySpawnedResource
//
//
// JDFResourcePool.h: interface for the JDFResourcePool class.
//
// ////////////////////////////////////////////////////////////////////

#if !defined(__JDFRESOURCEPOOL_H__)
#define __JDFRESOURCEPOOL_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFPool.h"
#include "JDFResource.h"
namespace JDF{
/**
* Wrapper class for the ResourcePool
* also used as a class factory for resources
	*/
		class VoidSet;

	class JDF_WRAPPERCORE_EXPORT JDFResourcePool : public JDFPool{
		friend class JDFNode;

	public:
		/**
		* null ctor
		*/
		inline JDFResourcePool():JDFPool(){};

		/**
		* copy ctor
		*/
		inline JDFResourcePool(const KElement & other):JDFPool(){
			*this=other;
		};

		/**
		* yacctor
		*/
		JDFResourcePool& operator =(const KElement& other);

		/**
		* dtor
		*/
		virtual ~JDFResourcePool(){};
		
		/**
		* Checks if the node is abstract, i.e. is not completely described
		* utility used by GetUnknownElements, GetUnknownAttributes
		* @return boolean: true, if the node is abstract
		*/
		virtual bool IsAbstract()const;
		
		/**
		* return a vector of unknown element nodenames
		*/
		virtual vWString GetUnknownElements(bool bIgnorePrivate=true,int nMax=99999999)const;
				
		/**
		* returns a set of all ids of the resources that are in this pool
		* @return setWString: set of all ids of the pool childs
		*/
		vWString GetResIds();
		
		/**
		* returns a the resource with id=id if it is in this pool
		* @param WString id the id of the requested resource;
		* @return JDFResource: the resource, empty element if it does not exist
		*/
		JDFResource GetResourceByID(const WString& id)const;

		/**
		* move the resource into this pool<br>
		* note that the resource is moved, not copied
		*
		* @param JDFResource res the resource to append
		* @return the resource after it has been moved into this
		*/
		JDFResource AppendResource(const JDFResource& res);
		
		/**
		* Appends a new resource to the resource pool
		* @param String name: name of the resource to add
		* @param JDFResource.Class resClass: the class of the resource
		* @param String nameSpaceURI: The namespace URI of the new resource
		* @return JDFResource: The newly created resource
		*/
		JDFResource AppendResource(const WString & name,JDFResource::EnumClass resClass, const WString & nameSpaceURI=WString::emptyStr);

		/**
		* Get a resource out of the resource pool. This function takes the name
		* and generates a vector of all Resource childs which matches the name.
		* Then take the one out of it specified by the int i value
		* 0 means first appearance
		* if int i is out of bounds or negativ, a new resource element is created
		* @param WString name: the kind of Resource you are searching for
		* @param int i: the number you want
		* @param WString nameSpaceURI: in which namespace the resource is
		* @return JDFResource: the JDFResource
		* @deprecated use GetPoolChild instead
		*/
		JDFResource GetResource(const WString & name,int i=0, const WString & nameSpaceURI=WString::emptyStr) const;
				
		/**
		* default initialization
		* @return boolean: TBD: return's true always 
		*/
		bool init();
		
		/**
		* get inter-resource linked resource ids
		* @param vWString vDoneRefs:
		* @param bool bRecurse if true, also return recursively linked IDS
		* @return vWString: the vector of referenced resource ids
		*/
		vWString GetHRefs(const vWString& vDoneRefs=vWString::emptyvStr, bool bRecurse=false)const;

		/**
		* get refElements
		* @param vElement vDoneRefs:
		* @param bool bRecurse if true, also return recursively linked IDS
		* @return vWString: the vector of referenced resource ids
		*/
		VoidSet* GetAllRefs(VoidSet* vDoneRefs, bool bRecurse=false)const;
		
		/**
		* Gets all children with the attribute name,mAttrib, nameSpaceURI out of the pool
		* @param WString name: name of the Child
		* @param mAttribute mAttrib: a attribute to search for
		* @return vResource: a vector with all elements in the pool matching the conditions
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
		JDFResource GetPoolChild(int i, const WString & name=WString::emptyStr, const mAttribute&mAttrib=mAttribute::emptyMap, const WString & nameSpaceURI=WString::emptyStr)const;

		/**
		* Mother of all version fixing routines
	    *
		* uses heuristics to modify this element and its children to be compatible with a given version
        * in general, it will be able to move from low to high versions but potentially fail 
		* when attempting to move from higher to lower versions
		*
		* @param version: version that the resulting element should correspond to
		* @return true if successful
		*/
		bool FixVersion(EnumVersion version);

	protected:
		/**
		* definition of the allowed node names for elements of this type
		* @return comma separated list of valid node names, * if any
		*/
		virtual WString ValidNodeNames()const;

	};	
};

#endif // !defined(__JDFRESOURCEPOOL_H__)
