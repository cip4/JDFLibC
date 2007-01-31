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
* created 2001-07-08
//
* 150102 RP added Part element support
* 020502 RP added GetPoolChild, GetPoolChildren
* 020502 RP added CopyNodeData
* 180502 RP added GetAncestorAttribute(), HasAncestorAttribute()
* 290502 | RP | added GetAncestorElement(), HasAncestorElement()
* 210602 RP changed calls to protected _XXX() to XXXGeneric()
* 170902 RP CopyNodeData() cleanup for differing spawns
* 201102 RP CopyNodeData() added bool bCopyNodeInfo, bool bCopyCustomerInfo
* 200503 RP added GetAncestorElementAttribute(), HasAncestorElementAttribute()
*
*/

#if !defined _JDFAncestorPool_H_
#define _JDFAncestorPool_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "AutoJDF/JDFAutoAncestorPool.h"
namespace JDF{
	class JDFPart;
	/*
	*********************************************************************
	class JDFAncestorPool : public JDFAutoAncestorPool

	*********************************************************************
	*/
	/**
	* Typesafe resource wrapper calss JDFAncestorPool 
	*
	* This file is hand edited and will not be regenerated
	*/
	class JDF_WRAPPERCORE_EXPORT JDFAncestorPool : public JDFAutoAncestorPool{
	public:


		// Constructors / Destructors  


		/**
		* null ctor
		*/
		inline JDFAncestorPool():JDFAutoAncestorPool(){};

		/**
		* copy ctor
		*/
		inline JDFAncestorPool(const KElement & other):JDFAutoAncestorPool(){
			*this=other;
		};

		/**
		* copy equivalance operator
		*/
		JDFAncestorPool &operator =(const KElement& other);

		/**
		* dtor
		*/
		virtual ~JDFAncestorPool(){};

		/**
		* check whether the Ancestor pool contains any part elements
		* @return bool true if the pool comtains part elements 
		*/
		bool IsPartitioned()const;				

		/**
		* Copy all data from root Node into the Ancestor elements of this
		*
		* @param JDFNode rootNode the closest parent Node that contains the information to be copied
		* @param bool bCopyNodeInfo if true, also copy the NodeInfo into the ancestor
		* @param bool bCopyCustomerInfo if true, also copy the CustomerInfo into the ancestor
		* @param bool bCopyComments if true, also copy the Comment elements into the ancestor
		*/
		void CopyNodeData(const JDFNode& parentNode,bool bCopyNodeInfo=false, bool bCopyCustomerInfo=false, bool bCopyComments=false);

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
		* @return JDFAncestor: the pool child matching the above conditions
		*/		
		JDFAncestor GetPoolChild(int i, const mAttribute&mAttrib=mAttribute::emptyMap)const;

		/**
		* searches for the first attribute occurrence in the ancestor elements
		*
		* @param WString attrib: the attribute name
		* @param WString nameSpaceURI: the XML-namespace
		* @param WString def: the default if it does not exist
		* @since 180502 
		* @return WString: value of attribute found, value of def if not available
		*/
		WString GetAncestorAttribute(const WString & attrib,const WString& nameSpaceURI=WString::emptyStr,const WString & def=WString::emptyStr)const;

		/**
		* true if a non default occurrence in the ancestor elements exists
		*
		* @param WString attrib: the attribute name
		* @param WString nameSpaceURI: the XML-namespace
		* @param WString def: the default if it does not exist
		* @since 180502 
		* @return WString: value of attribute found, empty string if not available
		*/
		bool HasAncestorAttribute(const WString & attrib,const WString& nameSpaceURI=WString::emptyStr)const;

		/**
		* searches for the first element occurrence in the ancestor elements
		*
		* @param WString attrib: the element name
		* @param WString nameSpaceURI: the XML-namespace of the element
		* @since 290502 
		* @return WString: value of attribute found, empty string if not available
		*/
		JDFElement GetAncestorElement(const WString & element,const WString& nameSpaceURI=WString::emptyStr)const;

		/**
		* true if a non default element occurrence in the parent nodes and then the ancestor elements of the root ancestorpool exists
		*
		* @param WString attrib: the element name
		* @param WString nameSpaceURI: the XML-namespace of the element
		* @since 290502 
		* @return bool: true if the element exists
		*/
		bool HasAncestorElement(const WString & attrib,const WString& nameSpaceURI=WString::emptyStr)const;

		/**
		* searches for the first attribute occurrence in the ancestor elements subelements<br>
		* e.g. the JobPriority in NodeInfo
		*
		* @param WString attrib: the attribute name
		* @param WString nameSpaceURI: the XML-namespace
		* @param WString def: the default if it does not exist
		* @since 200503 
		* @return WString: value of attribute found, empty string if not available
		*/
		WString GetAncestorElementAttribute(const WString & element,const WString & attrib,const WString& nameSpaceURI=WString::emptyStr,const WString & def=WString::emptyStr)const;

		/**
		* true if a non default attribute occurrence in the parent nodes and then the ancestor elements subelements of the root ancestorpool exists
		* e.g. the JobPriority in NodeInfo
		*
		* @param WString attrib: the attribute name
		* @param WString nameSpaceURI: the XML-namespace
		* @param WString def: the default if it does not exist
		* @since 200503 
		* @return bool: true if the attribute exists
		*/
		bool HasAncestorElementAttribute(const WString & element,const WString & attrib,const WString& nameSpaceURI=WString::emptyStr)const;


		//@{
		/**
		* gets part map vector
		*
		* @return vector of mAttribute, one for each part
		*/
		vmAttribute GetPartMapVector()const;

		/**
		* sets all parts to those define in vParts
		*
		* @param vmAttribute& vParts: vector of attribute maps for the parts
		*/
		void SetPartMapVector(const vmAttribute & vParts);

		/**
		* sets part to mPart
		*
		* @param mAttribute& mPart: attribute map for the part to set
		*/
		void SetPartMap(const mAttribute & mPart);

		/**
		* removes the part defined in mPart
		*
		* @param mAttribute& mPart: attribute map for the part to remove
		*/
		void RemovePartMap(const mAttribute & mPart);

		/**
		* checks whether the part defined in mPart is included
		*
		* @param mAttribute& mPart: attribute map for the part to remove
		* @return bool: if the part exists
		*/
		bool HasPartMap(const mAttribute & mPart);
		//@}

		/**
		* Get the linked resources matching some conditions<br>
		* combines all linked resources from the ancestors
		*
		* @param mAttribute mResAtt: map of Resource attributes to search for
		* @param boolean bFollowRefs true if internal references shall be followed
		* @return vResource: vector with all elements matching the conditions
		*/
		vElement GetLinkedResources(const mAttribute &mResAtt=mAttribute::emptyMap, bool bFollowRefs=false)const;

	}; // endJDFAncestorPool

	// ******************************************************
}; // end namespace JDF
#endif //_JDFAncestorPool_H_
