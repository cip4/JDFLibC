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
//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
// KElement.cpp: implementation of the KElement class.
// 151101 RP added GetInheritedAttribute, GetInheritedElement, AddNameSpace
//
//////////////////////////////////////////////////////////////////////

#include "KElement.h"

#include "JDFException.h"

#include "vElement.h"
#include "XMLDoc.h"
#include "XMLDocUserData.h"
#include "jdf/lang/Mutex.h"
#include "jdf/lang/SetWString.h"

#include <xercesc/framework/MemBufFormatTarget.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMNamedNodeMap.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMComment.hpp>
#include <xercesc/dom/DOMAttr.hpp>
#include <xercesc/dom/DOMEntityReference.hpp>
#include <xercesc/dom/DOMCDATASection.hpp>
#include <xercesc/dom/DOMXPathNSResolver.hpp>
#include <xercesc/dom/DOMXPathResult.hpp>
#include <xercesc/dom/DOMXPathExpression.hpp>
#include <xercesc/dom/DOMException.hpp>


#include<iostream>


XERCES_CPP_NAMESPACE_USE

namespace JDF{

	const int KElement::ANY_NODE						=0; // any node
	const int KElement::ELEMENT_NODE					=DOMNode::ELEMENT_NODE;
	const int KElement::ATTRIBUTE_NODE					=DOMNode::ATTRIBUTE_NODE;
	const int KElement::TEXT_NODE						=DOMNode::TEXT_NODE;
	const int KElement::CDATA_SECTION_NODE				=DOMNode::CDATA_SECTION_NODE;
	const int KElement::ENTITY_REFERENCE_NODE			=DOMNode::ENTITY_REFERENCE_NODE;
	const int KElement::ENTITY_NODE						=DOMNode::ENTITY_NODE;
	const int KElement::PROCESSING_INSTRUCTION_NODE		=DOMNode::PROCESSING_INSTRUCTION_NODE;
	const int KElement::COMMENT_NODE					=DOMNode::COMMENT_NODE;
	const int KElement::DOCUMENT_NODE					=DOMNode::DOCUMENT_NODE;
	const int KElement::DOCUMENT_TYPE_NODE				=DOMNode::DOCUMENT_TYPE_NODE;
	const int KElement::DOCUMENT_FRAGMENT_NODE			=DOMNode::DOCUMENT_FRAGMENT_NODE;
	const int KElement::NOTATION_NODE					=DOMNode::NOTATION_NODE;
	//	const int XML_DECL_NODE								=DOMNode::XML_DECL_NODE;

	const KElement KElement::DefKElement=KElement();

	//////////////////////////////////////////////////////////////////////
	// Construction/Destruction
	//////////////////////////////////////////////////////////////////////

	/**
	* Assignment of KElement object 'other' to the current KElement object
	*
	* @param KElement& other: KElement object to assign
	*/

	KElement& KElement::operator =(const KElement& other){
		domElement=other.domElement;
		return *this;
	};

	//////////////////////////////////////////////////////////////////////
	/**
	* Assignment of DOMElement* object 'other' to the current KElement object
	*
	* @param DOMElement* other: DOMElement object to assign
	*/

	KElement& KElement::operator =(DOMElement* other){
		domElement=other;
		return *this;
	};

	//////////////////////////////////////////////////////////////////////
	/** 
	* Overloaded compare operator == <br>
	* Compares 'this' reference with reference of other
	*
	* @param KElement & other: the reference to compare with 
	* @return bool: true, if 'this' reference and reference of other are equivalent 
	*/

	bool KElement::operator ==(const KElement& other)const{
		return domElement==other.domElement;
	}

	//////////////////////////////////////////////////////////////////////
	/** 
	* Overloaded compare operator != <br>
	* Compares 'this' reference with reference of other 
	*
	* @param KElement & other: the reference to compare with 
	* @return bool: true, if 'this' reference and reference of other are not equivalent
	*/

	bool KElement::operator !=(const KElement& other)const{
		return domElement!=other.domElement;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Returns the internal DOMElement pointer <br>
	* ATTENTION, use with care. No guarantee for internal consistency is given when modifying the DOMDocument
	*
	* @return DOMElement* : the internal DOMElement pointer
	*/

	DOMElement* KElement::GetDOMElement()const{
		return domElement;
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the qualified name of 'this'
	*
	* @return WString: the qualified name of the node; #null if it is null
	*/

	WString KElement::GetNodeName()const{
		if(throwNull())
			return L"#null";
		return domElement->getNodeName();
	};

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the value of 'this'
	*
	* @return WString: the value of the node; #null if it is null
	*/	

	WString KElement::GetNodeValue()const{
		if(throwNull())
			return L"#null";
		return domElement->getNodeValue();
	};

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the NameSpaceURI corresponding to a given prefix
	* @param WString prefix the prefix to check for
	* @return WString: The nameSpaceURI that maps to prfix
	*/

	WString KElement::GetNamespaceURIFromPrefix(const WString& prefix)const{
		if(throwNull())
			return WString::emptyStr;		
		WString elementPrefix=GetPrefix();
		// we are checking an element or attribute with the same prefix as this. 
		// therefore we assume that the same NamespaceURI also applies, if it is set
		if(elementPrefix==prefix){
			const JDFCh* pc=domElement->getNamespaceURI();
			if(pc!=0)
			{
				return pc;
			}
		}

		// note that elementPrefix is being reused for convinience and performance. 
		// It now actually represents the URI
		if(prefix.empty()){
			elementPrefix = GetAttribute(atr_xmlns);
		}else{
			elementPrefix = GetAttribute(atr_xmlns+WString::colon+prefix);
		}

		// found a decent URI
		if(!elementPrefix.empty())
			return elementPrefix;

		KElement e=GetParentNode();
		// we reached the document root and didn't find anything --> punt and return a null string
		if(e.isNull())
			return WString::emptyStr;

		// nothing found, recurse into parent element and try again
		return e.GetNamespaceURIFromPrefix(prefix);
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the NameSpaceURI of 'this'
	*
	* @return WString: The nameSpaceURI of 'this'
	*/

	WString KElement::GetNamespaceURI()const{
		if(throwNull())
			return WString::emptyStr;
		const JDFCh* pc=domElement->getNamespaceURI();
		if(pc!=0)
			return pc;
		else if(XMLDoc::getDefaultIgnoreNS())
			return WString::emptyStr;

		WString s=GetPrefix();
		if(s.empty()){
			return GetInheritedAttribute(atr_xmlns);
		}else{
			return GetInheritedAttribute(atr_xmlns+WString::colon+s);
		}
	};
	///
	//////////////////////////////////////////////////////////////////////
	/**
	* Parses pc for it's namespace prefix
	*
	* @param JDFCh* pc: pointer to string to parse
	* @return WString: namespace prefix of element - empty if no ":" is in pc 
	*/

	WString KElement::XMLNSPrefix(const JDFCh* pc){
		if(!pc)
			return WString::emptyStr;
		const JDFCh* posColon=wcschr(pc,L':');
		if(posColon==0)
			return WString::emptyStr;
		return WString(pc,posColon-pc);		
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Parses pc for it's local name
	*
	* @param JDFCh* pc: pointer to string to parse 
	* @return WString: local name  
	*/

	WString KElement::XMLNSLocalName(const JDFCh* pc){
		if(!pc)
			return WString::emptyStr;
		const JDFCh* posColon=wcschr(pc,L':');
		if(posColon==0)
			return pc;
		return ++posColon;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Parses s for it's namespace prefix
	*
	* @param WString & s: string to parse
	* @return WString: namespace prefix - empty if no ":" is in s
	*
	* @deprecated  use XMLNSPrefix
	*/

	WString KElement::XMLNameSpace(const WString & s){
		const JDFCh* pc=s.c_str();
		const JDFCh* posColon=wcschr(pc,L':');
		if(posColon==0)
			return WString::emptyStr;
		return WString(pc,posColon-pc);		
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the namespace prefix of 'this'
	*
	* @return WString: the namespace prefix of 'this'
	*/

	WString KElement::GetPrefix()const{
		if(throwNull())
			return WString::emptyStr;
		const JDFCh* pc=domElement->getPrefix();
		if(pc!=0)
			return pc;
		pc=domElement->getNodeName();
		return XMLNSPrefix(pc);
	}
	//////////////////////////////////////////////////////////////////////
	int KElement::getPrefixLength()const{
		if(throwNull())
			return -1;
		const JDFCh* pc=domElement->getPrefix();
		if(pc!=0)
			return wcslen(pc);
		pc=domElement->getNodeName();
		const JDFCh* posColon=wcschr(pc,L':');
		if(posColon==0)
			return -1;

		return posColon-pc;
	}
	//////////////////////////////////////////////////////////////////////
	///
	/**
	* Gets the local name of 'this'
	*
	* @return WString: the local name of 'this'
	*/

	WString KElement::GetLocalName()const{
		if(throwNull())
			return WString::emptyStr;
		const JDFCh* pc=domElement->getLocalName();
		if(pc!=0)
			return pc;
		pc=domElement->getNodeName();
		return XMLNSLocalName(pc);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Sets the namespace prefix of 'this'
	*
	* @param WString prefix: namespace prefix to set
	*
	* @throws JDFException if 'this' is a null element and thus no settings can be made
	*/
	void KElement::SetPrefix(const WString& prefix){
		if(isNull())
			throw JDFException(L"KElement::SetPrefix setting prefix on null element");
		domElement->setPrefix(prefix.c_str());
		SetDirty(false);
	};

	//////////////////////////////////////////////////////////////////////
	/**
	* Copies an attribute from src to 'this'
	*
	* @param WString & attrib: the name of the attribute
	* @param KElement & src: source element, where the attribute to be copied resides
	* @param WString & srcAttrib: name of the attribute in the source, defaults to the value of attrib
	* @param WString & nameSpaceURI: nameSpace of the attribute in the destination
	* @param WString & srcNameSpaceURI: nameSpace of the attribute in the source, defaults to the value of nameSpaceURI
	*/
	void KElement::CopyAttribute(const WString & attrib, const KElement & src, const WString & srcAttrib,const WString & nameSpaceURI, const WString & srcNameSpaceURI){	
		const WString& pSrcAttrib=(srcAttrib.empty())?attrib:srcAttrib;
		const WString& pSrcNameSpaceURI=(srcNameSpaceURI.empty())?nameSpaceURI:srcNameSpaceURI;
		SetAttribute(attrib,src.GetAttribute(pSrcAttrib,pSrcNameSpaceURI),nameSpaceURI);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Moves an attribute from src to 'this'
	*
	* @param WString & attrib: the name of the attribute
	* @param KElement & src: source element, where the attribute to be moved resides
	* @param WString & srcAttrib: name of the attribute in the source, defaults to the value of attrib
	* @param WString & nameSpaceURI: nameSpace of the attribute in the destination
	* @param WString & srcNameSpaceURI: nameSpace of the attribute in the source, defaults to the value of nameSpaceURI
	*/

	void KElement::MoveAttribute(const WString & attrib, KElement& src, const WString & srcAttrib,const WString & nameSpaceURI, const WString & srcNameSpaceURI){		
		const WString& pSrcAttrib=(srcAttrib.empty())?attrib:srcAttrib;
		const WString& pSrcNameSpaceURI=(srcNameSpaceURI.empty())?nameSpaceURI:srcNameSpaceURI;
		SetAttribute(attrib,src.GetAttribute(pSrcAttrib,pSrcNameSpaceURI));
		src.RemoveAttribute(pSrcAttrib,pSrcNameSpaceURI);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Mother of all Attribute setters <br>
	* Adds a new attribute. If an attribute with that name is already present in
	* the element, its value is changed to be that of the value parameter. This
	* value is a simple string; it is not parsed as it is being set. So any
	* markup (such as syntax to be recognized as an entity reference) is treated
	* as literal text, and needs to be appropriately escaped by the
	* implementation when it is written out. 
	*
	* @param WString & key: the qualified name of the attribute to create or alter.
	* @param WString & value: the value to set in string form.
	* @param WString & nameSpaceURI: the namespace the element is in
	* @throws JDFException: if 'this' is a null element and no settings of its attributes are possible
	*/	

	void KElement::SetAttribute(const WString & key, const WString & value, const WString & nameSpaceURI){
		if(isNull())
			throw JDFException(L"KElement::SetAttribute setting attribute on null element");

		bool bDirty=false;
		const JDFCh*pc=key.c_str();

		if(nameSpaceURI.empty()){

			// must explicitly set xmlns as DOM level 2 because the xerces serializer checks for DOM level 2 
			// xmlns attributes and avoids duplicate serialization of the attribute and namespace nodes
			if(!wcsncmp(pc,atr_xmlns.c_str(),5)&&((pc[5]==0)||(pc[5]==L':')))
			{
				if(value.empty())
				{
					DOMNode *a=domElement->getAttributeNode(pc);
					// never ever set "xmlns:foo="" !           
					if(a!=0)
					{
						bDirty=true;
						domElement->removeAttribute(pc);
					}
				}
				else if(GetInheritedAttribute(key)!=value)
				{
					bDirty=true;
					domElement->setAttributeNS(atr_xmlnsURI.c_str(),pc,value.c_str());
				}
			}
			else
			{

				WString namespaceURI2=GetNamespaceURIFromPrefix(XMLNSPrefix(key.c_str()));
				if(!namespaceURI2.empty()){
					SetAttribute(key,value,namespaceURI2);
					return;
				}

				DOMNode *a=GetDOMAttr(pc,L"");
				if(!a||value!=a->getNodeValue()){
					bDirty=true;
					if(a)
					{ // don't search the attribute node if it is already there
						if(wcscmp(a->getNodeName(),pc)){ // overwrite default namespace with qualified namespace or vice versa
							domElement->removeAttribute(a->getNodeName());
							domElement->setAttribute(pc,value.c_str());
						}else{ // same qualified name, simply overwrite the value
							a->setNodeValue(value.c_str());
						}
					}
					else
					{
						domElement->setAttribute(pc,value.c_str());
					}
				}
			}
		}
		else
		{
			if(nameSpaceURI==atr_xmlnsURI)
			{
				// never ever set "xmlns:foo="" !
				if(value.empty()){
					domElement->removeAttributeNS(nameSpaceURI.c_str(),pc);
					bDirty=true;
				}else if(GetInheritedAttribute(XMLNSLocalName(pc),nameSpaceURI)!=value){
					bDirty=true;
					domElement->setAttributeNS(atr_xmlnsURI.c_str(),pc,value.c_str());
				}
			}
			else
			{
				DOMNode*a=domElement->getAttributeNodeNS(nameSpaceURI.c_str(),XMLNSLocalName(pc).c_str());
				if(!a||value!=a->getNodeValue())
				{
					bDirty=true;
					if(a)
					{ // don't search the attribute node if it is already there
						if(wcscmp(a->getNodeName(),pc)){ // overwrite default namespace with qualified namespace or vice versa
							domElement->setAttributeNS(nameSpaceURI.c_str(),pc,value.c_str());
						}else{ // same qualified name, simply overwrite the value
							a->setNodeValue(value.c_str());
						}
					}
					else
					{
						WString namespaceURI2=GetNamespaceURIFromPrefix(XMLNSPrefix(key.c_str()));
						// in case multiple namespace uris are defined for the same prefix, all we can do is to bail out loudly
						if(!namespaceURI2.empty()&&(namespaceURI2!=nameSpaceURI)){
							WString s(L"KElement::SetAttribute: inconsistent namespace URI for prefix: "+XMLNSPrefix(pc)+L"; existing URI: "+namespaceURI2+L"; attempting to set URI: "+nameSpaceURI);
							throw JDFException(s);
						}
						// remove any twin dom lvl 1 attributes - just in case
						domElement->removeAttribute(pc);    
						domElement->setAttributeNS(nameSpaceURI.c_str(),pc,value.c_str());
					}
				}
			}
		}
		if(bDirty)
			SetDirty(true);
	}


	//////////////////////////////////////////////////////////////////////
	/**
	* Appends a new child element to the end of 'this' 
	*
	* @param KElement & element: a new child element to append
	* @return KElement: newly created child element 
	*
	* @throws JDFException if 'this' is a null element and thus appending of elements to it is impossible
	*/

	KElement KElement::AppendElement(const KElement & element){
		if(element.throwNull()) 
			return DefKElement;

		if(isNull())
			throw JDFException(L"KElement::AppendElement appending to null element");


		DOMElement* e=(DOMElement*) domElement->appendChild(element.domElement);
		SetDirty(false);
		return e;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Appends a new child element to the end of 'this' 
	*
	* @param WString & elementName: name of the new child element
	* @param WString & nameSpaceURI: nameSpace of the new child element
	* @return KElement: newly created child element 
	*/

	KElement KElement::AppendElement(const WString & elementName,const WString & nameSpaceURI){
		if(throwNull()) 
			return DefKElement;

		DOMElement* newChild;
		if(nameSpaceURI.empty()){
			WString namespaceURI2=GetNamespaceURIFromPrefix(XMLNSPrefix(elementName.c_str()));
			if(!namespaceURI2.empty()){
				newChild=domElement->getOwnerDocument()->createElementNS(namespaceURI2.c_str(),elementName.c_str());
			}else{
				newChild=domElement->getOwnerDocument()->createElement(elementName.c_str());
			}
		}else{
			newChild=domElement->getOwnerDocument()->createElementNS(nameSpaceURI.c_str(),elementName.c_str());
		}
		domElement->appendChild(newChild);
		SetDirty(false);
		return newChild;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Appends a new child element to the end of 'this', 
	* if it's maximum number of the children with defined name and nameSpace doesn't exceed maxAllowed 
	*
	* @param WString & elementName: name of the new child element
	* @param int maxAllowed: the maximum number of children with defined name and nameSpace, that are allowed for 'this'
	* @param WString & nameSpaceURI: nameSpace of the new child element
	* @return KElement: newly created child element
	*
	* @throws JDFException if 'this' is a null element and thus appending of elements to it is impossible
	* @throws JDFException if maxAllowed or more elements with defined name and namespace already exist
	*/

	KElement KElement::AppendElementN(const WString & elementName, int maxAllowed, const WString & nameSpaceURI){
		if(isNull())
			throw JDFException(L"KElement::AppendElementN appending to null element");

		if(KElement::NumChildElements(elementName,nameSpaceURI)>=maxAllowed)
			throw JDFException(L"KElement:AppendElementN: too many elements of type"+nameSpaceURI+WString::colon+elementName);
		return AppendElement(elementName,nameSpaceURI);		
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Inserts a new child element in front of child element BeforeChild
	*
	* @param KElement & newChild: a new child element to insert
	* @param KElement & BeforeChild: child node to put it before
	* @return KElement: newly inserted child element 
	*
	* @throws JDFException if 'this' is a null element and thus nothing can be inserted in it
	*/

	KElement KElement::InsertBefore(const KElement & newChild, const KElement & BeforeChild){
		if(isNull())
			throw JDFException(L"KElement::InsertBefore inserting in null element");

		if(newChild==BeforeChild||newChild.isNull())
			return newChild;

		domElement->insertBefore(newChild.domElement,BeforeChild.domElement);
		SetDirty(false);
		return newChild;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Creates a new child element with defined name and nameSpace and
	* inserts it into 'this' in front of child element named beforeChild
	*
	* @param WString & elementName: name of the new child element
	* @param KElement & beforeChild: child node to put it before
	* @param WString & nameSpaceURI: nameSpace of the new child element
	* @return KElement: newly inserted child element 
	*
	* @throws JDFException if 'this' is a null element and thus nothing can be inserted in it
	* @throws JDFException if beforeChild is not a child of 'this' 
	*/
	KElement KElement::InsertBefore(const WString & elementName, const KElement& beforeChild,const  WString & nameSpaceURI){
		if(isNull())
			throw JDFException(L"KElement::InsertBefore inserting in null element");

		if(beforeChild.GetParentNode()!=*this)
			throw JDFException(L"KElement::InsertBefore beforeChild is not child of this");

		DOMElement* newChild;
		if(nameSpaceURI.empty()){
			WString namespaceURI2=GetNamespaceURIFromPrefix(XMLNSPrefix(elementName.c_str()));
			if(!namespaceURI2.empty()){
				newChild=domElement->getOwnerDocument()->createElementNS(namespaceURI2.c_str(),elementName.c_str());
			}else{
				newChild=domElement->getOwnerDocument()->createElement(elementName.c_str());
			}
		}else{
			newChild=domElement->getOwnerDocument()->createElementNS(nameSpaceURI.c_str(),elementName.c_str());
		}
		domElement->insertBefore(newChild,beforeChild.domElement);
		SetDirty(false);
		return newChild;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Creates new child element with defined Name and NameSpace and inserts it 
	* in front of the node with a name bForeNode and namespace beforeNameSpaceURI, with index beforePos  
	*
	* @param WString & nodeName: name of the new Element
	* @param int beforePos: index of beforeNode, i.e if beforePos=0, put it before the first occurrence
	* @param WString & beforeNode: name of the node to put it before, default - any name
	* @param WString & nameSpaceURI: nameSpace of the new node
	* @param WString & beforeNameSpaceURI: nameSpace of the node to put it before, default - value of nameSpaceURI
	* @return KElement: the newly created element
	* 
	* @throws JDFException if 'this' is a null element and thus nothing can be inserted in it
	*/

	KElement KElement::InsertAt(const WString & nodeName, int beforePos, const WString& beforeNode,const  WString & nameSpaceURI,const WString & beforeNameSpaceURI){
		if(isNull())
			throw JDFException(L"KElement::InsertAt inserting in null element");

		KElement e=GetElement(beforeNode,beforeNameSpaceURI.empty()?nameSpaceURI:beforeNameSpaceURI,beforePos);
		if(e.isNull())
			beforePos=-1;

		if(beforePos==-1)
			return AppendElement(nodeName,nameSpaceURI);

		return InsertBefore(nodeName,e,nameSpaceURI);
	}

	//////////////////////////////////////////////////////////////////////

	/** 
	* Appends an XML Comment (NOT a JDF comment) <br>
	* Appends a new comment child node to the end of 'this' 
	*
	* @param WString & commentText: the text of the XML Comment to append 
	*
	* @throws JDFException if 'this' is a null element and thus nothing can be appended to it
	*/

	void KElement::AppendXMLComment(const WString & commentText){
		if(isNull())
			throw JDFException(L"KElement::AppendXMLComment inserting in null element");

		DOMComment* newChild=domElement->getOwnerDocument()->createComment(commentText.c_str());
		domElement->appendChild(newChild);
		SetDirty(false);
		return;
	}

	//////////////////////////////////////////////////////////////////////
	/** 
	* Appends XML CData section - some character data <br>
	* Appends a new CData section child node to the end of 'this '
	*
	* @param WString & cDataText: the text of the XML CData section to append 
	*
	* @throws JDFException if 'this' is a null element and thus nothing can be appended to it
	*/

	void KElement::AppendCData(const WString & cDataText){
		if(isNull())
			throw JDFException(L"KElement::AppendCData inserting in null element");

		DOMCDATASection* newChild=domElement->getOwnerDocument()->createCDATASection(cDataText.c_str());
		domElement->appendChild(newChild);
		SetDirty(false);
		return;
	}

	//////////////////////////////////////////////////////////////////////

	/** 
	* Sets an XML Text <br>
	* the text contents of this to the value of text 
	*
	* @param WString & text: XML Text to set 
	*
	* @throws JDFException if 'this' is a null element and thus nothing can be inserted in it 
	*/
	void KElement::SetText(const WString & text){
		RemoveText();
		AppendText(text);
	}

	//////////////////////////////////////////////////////////////////////


	/** 
	* Appends an XML Text <br>
	* Appends a new text child node to the end of 'this' 
	*
	* @param WString & text: XML Text to append
	*
	* @throws JDFException if 'this' is a null element and thus nothing can be inserted in it 
	*/

	void KElement::AppendText(const WString & text){
		if(isNull())
			throw JDFException(L"KElement::AppendText inserting in null element");
		DOMText* newChild=domElement->getOwnerDocument()->createTextNode(text.c_str());
		domElement->appendChild(newChild);
		SetDirty(false);
		return;
	}
	//////////////////////////////////////////////////////////////////////

	/** 
	* Creates and appends to 'this' a new child element named nodeName and appends an XML Text to it
	*
	* @param WString & nodeName: the name of the new child element
	* @param WString & text: text to append
	* @return KElement: newly created child element, that contains the XML Text
	*/

	KElement KElement::AppendTextElement(const WString & nodeName, const WString & text){
		KElement e=AppendElement(nodeName);
		e.AppendText(text);
		return e;
	}

	//////////////////////////////////////////////////////////////////////
	/** 
	* Appends an XML EntityReference <br>
	* Appends a new EntityReference child node named refName to the end of 'this'
	*
	* @param WString & refName: name of the XML EntityReference 
	*
	* @throws JDFException if 'this' is a null element and thus nothing can be appended to it
	*/
	void KElement::AppendEntityReference(const WString & refName){
		if(isNull())
			throw JDFException(L"KElement::AppendEntityReference inserting in null element");
		DOMEntityReference* newChild=domElement->getOwnerDocument()->createEntityReference(refName.c_str());
		domElement->appendChild(newChild);
		SetDirty(false);
		return;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Checks, if the node is abstract, i.e. is not completely described.
	* Utility used by GetUnknownElements, GetUnknownAttributes
	*
	* @return bool: true, if the node is abstract
	*/

	bool KElement::IsAbstract()const{
		return true;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Mother of all validators
	*
	* @param EnumValidationLevel level: validation level
	* level ValidationLevel_None: always return true <br>
	* level ValidationLevel_Construct: incomplete and null elements are valid <br>
	* level ValidationLevel_Incomplete: incomplete elements are valid <br>
	* level ValidationLevel_Complete: full validation of an individual resource <br>
	* level ValidationLevel_RecursiveIncomplete: incomplete validation of an individual resource and all of its child elements - e.g. for pools <br>
	* level ValidationLevel_RecursiveComplete: full validation of an individual resource and all of its child elements - e.g. for pools <br>
	* @return bool: true, if the node is valid.
	*/

	bool KElement::IsValid(EnumValidationLevel level)const{
		// I can construct from a null object
		if(level<=ValidationLevel_Construct) 
			return true;
		if(isNull()) 
			return false;
		if(domElement->getOwnerDocument()==0) 
			return false;
		// must be an element node
		if(domElement->getNodeType()!=ELEMENT_NODE) 
			return false;

		return true;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the document object that owns 'this' 
	*
	* @return XMLDoc: the document owner of 'this'
	*/

	XMLDoc KElement::GetOwnerDocument()const{
		XMLDoc d;

		if(! throwNull())
			d=domElement->getOwnerDocument();
		return d;
	};

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets an existing iSkip-th child node with matching nodeName and nameSpaceURI
	*
	* @param WString & nodeName: name of the child node to get
	* @param WString & nameSpaceURI: namespace to search for
	* @param int iSkip: number of matching child nodes to skip, if negative count backwards (-1 is the last)
	* @return KElement: the matching child element
	*/

	KElement KElement::GetElement(const WString& nodeName,const WString & nameSpaceURI, int iSkip)const{
		if(throwNull())
			return DefKElement; 
		if (iSkip < 0)
			iSkip = NumChildElements(nodeName,nameSpaceURI) + iSkip;

		KElement e=GetFirstChildElement();
		int i=0;
		const JDFCh* pcNodeName=nodeName.c_str();
		const JDFCh* pcNameSpaceURI=nameSpaceURI.c_str();
		while(!e.isNull()){
			if(e.FitsName(pcNodeName,pcNameSpaceURI)){
				// this guy is the one
				if(i++==iSkip) 
					return e;
			}
			e=e.GetNextSiblingElement();
		}

		return DefKElement;
	}

	//////////////////////////////////////////////////////////////////////	
	/**
	* Gets the iSkip-th child node with matching nodeName and nameSpaceURI, 
	* optionally creates it if it doesn't exist. <br>
	* If iSkip is more than one larger that the number of elements only one is appended
	*
	* @param WString & nodeName: name of the child node to get
	* @param WString & nameSpaceURI: namespace to search for
	* @param int iSkip: number of matching child nodes to skip
	* @return KElement: the matching child element
	*/

	KElement KElement::GetCreateElement(const WString & nodeName, const WString & nameSpaceURI,int iSkip){
		if(throwNull()) 
			return DefKElement;

		KElement e=GetElement(nodeName, nameSpaceURI, iSkip);

		if(e.isNull()){
			return AppendElement(nodeName,nameSpaceURI);
		}
		return e;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the iSkip-th child, whose localname matches a string defined in nodeNames 
	*
	* @param vWString & nodeNames: list of node names that fit
	* @param int iSkip: number of matching child nodes to skip
	* @return KElement: the found child element
	*/

	KElement KElement::GetChildFromList(const vWString& nodeNames, int iSkip)const{
		if(throwNull()) 
			return DefKElement;
		int i=0;
		KElement e=GetFirstChildElement();
		while(!e.isNull()){			
			if(nodeNames.hasString(e.GetLocalName())){
				if(i++==iSkip) 
					return e; // this guy is the one
			}
			e=e.GetNextSiblingElement();
		}	
		return DefKElement;
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Gets a vector of all children, whose localnames match the string defined in nodeNames
	*
	* @param vWString & nodeNames: list of node names that fit
	* @return vElement: the found child elements
	*/

	vElement KElement::GetChildrenFromList(const vWString& nodeNames)const{
		vElement v;
		if(throwNull()) 
			return v;

		KElement e=GetFirstChildElement();
		while(!e.isNull()){			
			if(nodeNames.hasString(e.GetLocalName())){
				v.push_back(e);
			}
			e=e.GetNextSiblingElement();
		}	
		return v;
	}


	/////////////////////////////////////////////////////////////////////////////////////////////

	DOMAttr* KElement::GetDOMAttr(const JDFCh* attrib, const JDFCh* nameSpaceURI, bool bInherit) const 
	{
		if(throwNull()) 
			return 0;
		DOMAttr* a=0;
		WString strNSURI; // has to bei defined here, since nameSpaceURI could point to it
		if(nameSpaceURI==0 || *nameSpaceURI==0)
		{
			a=domElement->getAttributeNode(attrib);
			if(!a)
			{
				const JDFCh* pColon=wcschr(attrib,L':');
				int prefixLen=getPrefixLength();
				if(pColon)
				{ // has attribute prefix
					if(prefixLen==pColon-attrib)
					{
						WString prefix=GetPrefix();
						if(!wcsncmp(prefix.c_str(),attrib,pColon-attrib)&&(*(pColon+1))){
							a=domElement->getAttributeNode(pColon+1);
						}
					}
				}
				else
				{
					if(prefixLen>0)
					{
						WString prefix=GetPrefix();
						a=domElement->getAttributeNode((prefix+WString::colon+attrib).c_str());
					}
				}
				if((a==0) && wcsncmp(attrib,L"xmlns",5))
				{
					strNSURI = GetNamespaceURIFromPrefix( XMLNSPrefix(attrib) );
					nameSpaceURI = strNSURI.c_str();
				}
			}
		}
		if(a==0 && nameSpaceURI!=0)
		{
			const JDFCh* pColon=wcschr(attrib,L':');
			// 071106 RP use attrib if the pointer to ":" is NULL
			a=domElement->getAttributeNodeNS(nameSpaceURI,pColon==NULL ? attrib : pColon+1);
		}

		if (a == NULL && bInherit)
		{
			KElement parent = GetParentNode();
			if (parent != NULL)
				return parent.GetDOMAttr(attrib,nameSpaceURI,bInherit);
		}

		return a;
	};

	//////////////////////////////////////////////////////////////////////
	/**
	* Mother of all attribute getters <br>
	* Gets an attribute value out of an element
	*
	* @param WString & attrib: the name of the attribute you wanna have
	* @param WString & nameSpaceURI: namespace of attribute key
	* @param WString & def: the value that is returned if attrib does not exist in 'this' or 'this' is null
	* @return WString: the attribute value as a string, or def if that attribute does not have a specified or default value
	*/
	WString KElement::GetAttribute(const WString & attrib, const WString & nameSpaceURI, const WString & def) const {
		if(throwNull()) 
			return def;
		DOMAttr* a=GetDOMAttr(attrib.c_str(),nameSpaceURI.c_str());

		if (a==0) 
			return def;
		return a->getValue();
	};


	//////////////////////////////////////////////////////////////////////
	/**
	* Internal function for searching through the trees.
	* Gets 'this' or the child node of arbitrary depth,
	* that matches defined id, name and is not a childToExclude
	*
	* @param JDFCh* name: name of the attribute node to find
	* @param JDFCh* id: the ID of the node to find
	* @param KElement & childToExclude: child to exclude during the search 
	* @return KElement: the matching element node
	*/	

	KElement KElement::GetDeepElementByID(const JDFCh* name, const JDFCh * id, const KElement& childToExclude, XMLDocUserData*ud)const{

		// found it - heureka
		// RP 260104 inlined wcscmp for performance
		const JDFCh* attVal=domElement->getAttribute(name);
		if(attVal!=0)
		{
			if (ud!=0)
			{
				ud->SetTarget(*this,attVal);
			}
		}

		if (wcscmp(attVal,id)==0){
			return *this;
		}

		// tree walk children
		KElement g=GetFirstChildElement();
		KElement elemNull;
		while(!g.isNull()){
			if(g==childToExclude){
				g=g.GetNextSiblingElement();
				continue;
			}
			KElement g2=g.GetDeepElementByID(name,id,elemNull,ud);
			if(g2.isNull()) {
				// not found; try next sibling
				g=g.GetNextSiblingElement();
			}else{
				// gotcha!
				return g2;
			}
		}

		// found nothing; return null
		return DefKElement;
	}


	//////////////////////////////////////////////////////////////////////
	/**
	* Moves src node (including all attributes and subelements)
	* from its parent node into 'this' and 
	* inserts it in front of beforeChild, if it exists.
	* Otherwise appends src to 'this'.<br>
	* If src is null, an empty KElement is returned.<br>
	*
	* src is removed from its parent node.
	* if the actual document owner is the same as the document owner of src,
	* src is appended to 'this'
	* If the documents are different, then src is appended to 'this' in the actual document.
	*
	* @param KElement & src: node to move.
	* @param KElement & beforeChild: child of 'this' to insert src before.
	* If beforeChild is null, src is appended to 'this' 
	* @return KElement: src element after moving
	*
	* @throws JDFException if 'this' is a null element and thus nothing can't be moved into it 
	* @throws JDFException if beforeChild is not a child of 'this'
	*/

	KElement KElement::MoveElement(const KElement & src, const KElement& beforeChild){

		if(src.throwNull()) 
			return DefKElement;
		if(isNull())
			throw JDFException(L"KElement::MoveElement moving into null element");

		src.GetParentNode().SetDirty(false);
		SetDirty(false);
		DOMElement* srcElement = (DOMElement*) src.domElement->getParentNode()->removeChild(src.domElement);

		if((!beforeChild.isNull())&&(beforeChild.GetParentNode()!=*this))
			throw JDFException(L"KElement::InsertBefore beforeChild is not child of this");
		if(src.domElement->getOwnerDocument()!=domElement->getOwnerDocument()){
			src.GetOwnerDocument().ClearTargets();			
			srcElement=(DOMElement*) domElement->getOwnerDocument()->importNode(srcElement,true);
		}

		KElement e;
		if(beforeChild.isNull()){
			e=(DOMElement*) (domElement->appendChild(srcElement));	
		}else{
			e=(DOMElement*) (domElement->insertBefore(srcElement,beforeChild.domElement));
		}

		return e;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Replaces 'this' with src.  <br>
	* If the actual document owner is the same as the src document owner,'this' is replaced by src. <br>
	* If the actual document owner and the src document owner are different, 
	* src is positioned at the position of 'this' in the current document
	* and not removed from the old parent document. <br>
	* 
	* @since 130103 ReplaceElement works on all elements including the document root
	* @param KElement & src: node, that 'this' will be replaced with
	* @return KElement: the replaced element. If src is null or equal 'this', src is returned.
	*
	* @throws JDFException if 'this' is a null element and thus can't be replaced
	*/

	KElement KElement::ReplaceElement(const KElement & src){
		if(src.throwNull()||(src==*this)) 
			return src;

		if(isNull())
			throw JDFException(L"KElement::ReplaceElement replacing  null element");

		// workaround for the document element - TBD: there must be a better way
		if(GetParentNode().isNull()){
			RenameElement(src.GetNodeName(),src.GetNamespaceURI());
			Flush();
			SetAttributes(src.GetAttributeMap());
			vElement children=src.GetChildElementVector();
			for(unsigned int iv=0;iv<children.size();iv++){
				CopyElement(children[iv]);
			}
			return *this; // return the original
		}else{

			src.GetParentNode().SetDirty(false);
			if(src.GetNodeName()==GetNodeName()){
				SetDirty(false);
			}else{ // I am modifying XPaths, must set the lower level dirty
				GetParentNode().SetDirty(false);
			}
			GetOwnerDocument().RemoveTarget(*this);

			DOMElement* srcElement = (DOMElement*) src.domElement->getParentNode()->removeChild(src.domElement);

			KElement n;
			// this and src are in the same document
			if(src.domElement->getOwnerDocument()==domElement->getOwnerDocument()){
				*this=(DOMElement*) domElement->getParentNode()->replaceChild(srcElement,domElement);
				n=src;
			}else{ // import from other document
				DOMElement* dn;
				dn=(DOMElement*) domElement->getOwnerDocument()->importNode(srcElement,true);
				*this=(DOMElement*) domElement->getParentNode()->replaceChild(dn,domElement);
				n=dn;
			}
			return n;
		}
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Copies src node (including all attributes and subelements) 
	* and inserts the copy into 'this' in front of beforeChild, if it exists.
	* Otherwise appends src node to 'this'.<br>
	*
	* @param KElement & src: node to copy.
	* @param KElement & beforeChild: child of 'this' to insert src before. If null, src is appended
	* @return KElement: the copied element. If src is null, an empty KElement is returned.
	*
	* @throws JDFException if 'this' is a null element and thus nothing can't be inserted into it 
	* @throws JDFException if beforeChild is not a child of 'this'
	*/

	KElement KElement::CopyElement(const KElement & src,const KElement& beforeChild){
		if(src.throwNull()) 
			return DefKElement;
		if(isNull())
			throw JDFException(L"KElement::CopyElement copying into null element");

		SetDirty(false);

		DOMElement* srcElement;

		if(src.domElement->getOwnerDocument()==domElement->getOwnerDocument()){
			srcElement=(DOMElement*) src.domElement->cloneNode(true);
		}else{
			srcElement=(DOMElement*) domElement->getOwnerDocument()->importNode(src.domElement,true);
		}
		KElement e;
		if(beforeChild.isNull())
		{
			e=(DOMElement*) (domElement->appendChild(srcElement));	
		}
		else
		{
			if(beforeChild.GetParentNode()!=*this)
				throw JDFException(L"KElement::CopyElement beforeChild is not child of this");

			e=(DOMElement*) (domElement->insertBefore(srcElement,beforeChild.domElement));
		}
		return e;
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Renames 'this' with the String newName.
	*
	* @param WString & newName: the new qualified name of 'this'
	* @param WString & newNameSpaceURI: the new nameSpace URI of 'this'
	* @return KElement: the renamed element
	*
	* @throws JDFException if 'this' is a null element and thus can't be renamed 
	* @throws JDFException if 'this' has no documnent owner and thus can't be renamed
	*/

	KElement KElement::RenameElement(const WString & newName,const WString & nNameSpaceURI){

		if(isNull())
			throw JDFException(L"KElement::RenameElement renaming null element");

		if(newName==GetNodeName() && nNameSpaceURI==GetNamespaceURI()) 
			return *this;

		WString newNameSpaceURI=nNameSpaceURI;

		// retain namespace if it is not reset
		if (newNameSpaceURI==WString::emptyStr){
			newNameSpaceURI=GetNamespaceURI();
		}
		DOMDocument* domDocument=domElement->getOwnerDocument();
		if(!domDocument){
			throw JDFException(L"KElement:RenameElement: no owner documnent"); 
		}
		*this=(DOMElement*) domDocument->renameNode(domElement,newNameSpaceURI.c_str(),newName.c_str());
		return *this;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Erases all empty text nodes in 'this' and its subelements 
	* If there any empty text nodes removes them.
	* If bTrimWhite is true, then trims white spaces from both ends of a text node
	* and only then, if it is empty, removes it
	*
	* @param bool bTrimWhite: trims whitespace of text, default=true
	* @return int: the number of removed nodes 
	*/

	int KElement::EraseEmptyNodes(bool bTrimWhite){
		const static WString comment=L"Comment";
		int nRemove=0;

		if(throwNull()) 
			return 0;
		DOMNode* n=domElement->getFirstChild();
		DOMNode* nNext=0; 
		while(n!=0){
			short nodeType=n->getNodeType();
			nNext=n->getNextSibling(); // get it here since n may be deleted below

			if (nodeType==TEXT_NODE){
				WString s=n->getNodeValue();
				if(bTrimWhite) 
					s=s.trim();
				if(s.empty()){
					domElement->removeChild(n);
					nRemove++;
				}else if(bTrimWhite){ // replace value with cleaned string
					n->setNodeValue(s.c_str());
				}
			}else if(nodeType==ELEMENT_NODE){
				KElement e((DOMElement*)n);
				// also remove spurious xmlns attributes
				vWString vNS=e.GetAttributeVector();
				int siz=vNS.size();
				for(int i=0;i<siz;i++){
					const WString& key=vNS[i];
					const JDFCh*pc=key.c_str();
					if(!wcsncmp(pc,atr_xmlns.c_str(),5)&&((pc[5]==0)||(pc[5]==L':'))){
						if(e.GetAttribute(key)==e.GetParentNode().GetInheritedAttribute(key)){
							e.RemoveAttribute(key);
							nRemove++;
						}
					}
				}
				if(e.GetLocalName()!=comment)
				{
					nRemove+=e.EraseEmptyNodes(); // retain ws in comment elements
				}
				// 040302 RP do not erase empty elements - they may have a sementic meaning
			}else{
			}
			n=nNext;
		}		
		return nRemove;
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Checks, if 'this' has child nodes, that match NodeType, or not.
	*
	* @param int nodeType: the DOM NodeType, if 0 count all nodes
	* @return bool: true, if there are child nodes of defined NodeType in 'this'
	*/

	bool KElement::HasChildNodes(int nodeType)const{
		if(throwNull())
			return false;

		DOMNode* e=domElement->getFirstChild();
		while(e){
			if((!nodeType)||(e->getNodeType()==nodeType))
				return true;
			e=e->getNextSibling();
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the number of child elements with matching nodeName and nameSpace. <br>
	* If nodeName is an empty string or *, all element nodes are counted.
	*
	* @param WString & nodeName: NodeName of nodes to count 
	* @param WString & nameSpaceURI: the nameSpace to look in
	* @return int: the number of matching child elements
	*/

	int KElement::NumChildElements(const WString & nodeName, const WString & nameSpaceURI)const{
		KElement e=GetFirstChildElement();
		int n=0;
		const JDFCh* pcNodeName=nodeName.c_str();
		const JDFCh* pcNameSpaceURI=nameSpaceURI.c_str();
		while(!e.isNull()){
			if(e.FitsName(pcNodeName,pcNameSpaceURI)){
				n++;
			}
			e=e.GetNextSiblingElement();
		}
		return n;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Checks if 'this' has attributes or not
	*
	* @return bool: true, if 'this' has any attributes
	*/

	bool KElement::HasAttributes()const{
		if(throwNull())
			return false;

		DOMNamedNodeMap* nm=domElement->getAttributes();
		int l=(nm==0)?0:nm->getLength(); 
		return l!=0;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Removes all attributes, elements and text, leaving only a stub tag
	*
	* @return bool: true, if successful
	*/

	bool KElement::Flush(){
		if(throwNull()) 
			return false;
		DOMNode* n=domElement->getFirstChild();
		while(n!=0){
			domElement->removeChild(n);
			n=domElement->getFirstChild();
		}
		GetOwnerDocument().ClearTargets();
		RemoveAttributes();
		return true;
	}

	///////////////////////////////////////////////////////////////////////
	/**
	* Gets children of 'this' by tag name, nameSpaceURI 
	* and attribute map, if the attribute map is not empty.<br> 
	* Searches the entire tree including hidden nodes that are children of non-matching nodes
	*
	* @param WString & s: elementname you are searching for
	* @param WString & nameSpaceURI: nameSpace you are searching for
	* @param mAttribute & mAttrib: map of attributes you are looking for <br> Wildcards in the attribute map are supported  
	* @param bool bDirect: if true, return value is a vector only of all direct child elements. <br>
	* Otherwise the returned vector contains nodes of arbitrary depth
	* @param bool bAnd: if true, a child is only added, if it includes all attributes, specified in mAttrib
	* @param unsigned int maxSize: maximum size of the element vector
	* @return vElement: vector with all found elements
	*/

	vElement KElement::GetChildrenByTagName(const WString& s, const WString & nameSpaceURI, const mAttribute & mAttrib, bool bDirect, bool bAnd, unsigned int maxSize)const{
		if (bDirect)
		{
			// if JDFResource::GetChildElementVector() is called, partitions will not be returned
			return GetChildElementVector(s,nameSpaceURI,mAttrib,bAnd,maxSize);
		}

		// maxSize is ignored in the tree walk!
		bool bHasNoMap=mAttrib.empty();
		if(throwNull()) 
			return vElement();

		vElement v;
		KElement e=GetFirstChildElement();
		const JDFCh* pcNodeName=s.c_str();
		const JDFCh* pcNameSpaceURI=nameSpaceURI.c_str();
		bool bAlwaysFit=IsWildcard(pcNodeName)&&IsWildcard(pcNameSpaceURI);

		while(!e.isNull()){
			if ((bAlwaysFit || e.FitsName(pcNodeName,pcNameSpaceURI))
				&& (bHasNoMap || e.IncludesAttributes(mAttrib, bAnd)))
			{
				// this guy is the one
				v.push_back(e);
				if (maxSize>0 && v.size() == maxSize)
				{
					return v;
				}
			}
			int maxSizeRecurse = maxSize>0 ? maxSize - v.size() : maxSize;
			VElement v2 = e.GetChildrenByTagName(s, nameSpaceURI, mAttrib, bDirect, bAnd, maxSizeRecurse);
			v.insert(v.end(),v2.begin(),v2.end());

			if ( maxSize > 0 && v.size() >= maxSize)
			{
				return v;
			}
			e = e.GetNextSiblingElement();
		} 
		return v;
	};

	///////////////////////////////////////////////////////////////////////
	/**
	* Gets a child of 'this' by tag name, nameSpaceURI
	* index and attribute map, if attribute map is not empty <br>
	* Searches the entire tree including hidden nodes, that are children of non-matching nodes <br>
	*
	* @param WString & s: elementname you are searching for
	* @param WString & nameSpaceURI: nameSpace you are searching for
	* @param int index: if more then one child matches the condition, you can
	* specify which one you want to have via the index. 
	* If the index is less than 0 the children are taken from the end, -1 returns the last, -2 the second to last element
	* @param mAttribute & mAttrib: map of attributes you are looking for <br> Wildcards in the attribute map are supported
	* @param bool bDirect: if true, return value is a vector only of all direct child elements.<br>
	* Otherwise the returned vector contains nodes of arbitrary depth
	* @param bool bAnd: if true, a child is only returned, if it includes all attributes, specified in mAttrib
	* @return KElement: the found child (element or node)
	*/

	KElement KElement::GetChildByTagName(const WString & s, const WString & nameSpaceURI, int index, const mAttribute & mAttrib, bool bDirect, bool bAnd)const{
		vElement v=GetChildrenByTagName(s,nameSpaceURI,mAttrib,bDirect,bAnd,index+1);
		if(index<0){
			index=v.size()+index;
			if(index<0)
				return DefKElement;
		}
		if(v.size()>index) 
			return v[index];
		return DefKElement;
	};

	///////////////////////////////////////////////////////////////////////
	/**
	* Sets the attributes of 'this'. <br> 
	* If the Attributes map is empty, zero is returned.
	* Otherwise the size of the map is returned
	*
	* @param mAttribute & aMap: map of attributes to set
	* @return int: size of the map or zero if it is empty
	*/

	int KElement::SetAttributes(const mAttribute &aMap){
		if(aMap.empty()) 
			return 0;
		for(mAttribute::const_iterator i=aMap.begin();i!=aMap.end();i++){
			WString key=i->first();
			if(key.length()>6&&key.startsWith(atr_xmlns)&&key[5]==L':'){
				AddNameSpace(XMLNSLocalName(key.c_str()),i->second());
			}else{
				SetAttribute(key,i->second());
			}
		}
		return aMap.size();
	}

	///////////////////////////////////////////////////////////////////////
	/**
	* Sets the attributes of 'this'. <br> 
	* If the Attributes map of the element e is empty, zero is returned.
	* Otherwise the size of the map is returned 
	*
	* @param KElement e : element, that contains attributes to set
	* @return int: size of the map or zero if it is empty
	*/

	int KElement::SetAttributes(KElement e){
		if(throwNull()||e.throwNull()) 
			return 0;
		DOMNamedNodeMap* nm= e.domElement->getAttributes();
		int l=(nm==0)?0:nm->getLength(); 
		for(int i=0;i<l;i++){
			DOMAttr* a=(DOMAttr*)nm->item(i);
			const JDFCh* uri=a->getNamespaceURI();
			SetAttribute(a->getNodeName(),a->getValue(),uri?uri:L"");
		}
		return l;
	}

	///////////////////////////////////////////////////////////////////////
	/**
	* Appends new attribute value to its list of values <br>
	* Appends the contents of value to the existing attribute key 
	* and, if it does not exist, creates the attribute key
	*
	* @param WString & key: attribute key
	* @param WString & value: string to append
	* @param WString & nameSpaceURI: namespace of attribute key
	* @param WString & sep: separator between the original attribute value and the new value
	* @param bool bUnique: if true, the attribute will only be appended if it is not yet within the list of known attributes<br>
	* AppendAttribute("key","next","",",") applied to <xml key="first"/> results in <xml key="first,next"/>
	* 
	* @throws JDFException if 'this' is a null element and appending of attributes to it is impossible
	*/

	void KElement::AppendAttribute(const WString & key, const WString& value, const WString & nameSpaceURI, const WString & sep, bool bUnique){
		if(isNull())
			throw JDFException(L"KElement::AppendAttribute appending to null element");
		WString oldVal=KElement::GetAttribute(key,nameSpaceURI);
		if(oldVal.empty()){
			SetAttribute(key,value,nameSpaceURI);
		}else{
			if(!bUnique||!oldVal.HasToken(value,sep)){ // add it if it is either not unique or it is not yet there
				SetAttribute(key,oldVal+sep+value,nameSpaceURI);
			}
		}
	}

	///////////////////////////////////////////////////////////////////////
	/**
	* Removes the attribute value from its value list <br>
	* Removes the contents of value from the existing attribute key. Deletes the attribute Key, if it has no value
	*
	* @param WString & key: attribute key
	* @param WString & value: string to remove
	* @param WString & nameSpaceURI: namespace of attribute key
	* @param WString & sep: separator between the values
	* @param int nMax: maximum number of value instances to remove (-1=all)
	* @return int: number of removed instances <br>
	* RemoveFromAttribute("key","next","",",") applied to <xml key="first,next"/> results in <xml key="first"/>
	*
	* @throws JDFException if 'this' is a null element and its modifying is thus impossible
	*/

	int KElement::RemoveFromAttribute(const WString & key, const WString& value, const WString & nameSpaceURI, const WString & sep, int nMax){
		if(isNull())
			throw JDFException(L"KElement::RemoveFromAttribute modifying  null element");

		vWString v=KElement::GetAttribute(key,nameSpaceURI).Tokenize(sep);
		int siz=v.size();
		v.RemoveStrings(value,nMax);
		if(v.empty()){
			KElement::RemoveAttribute(key,nameSpaceURI);
			return siz;
		}else{
			SetAttribute(key,v.GetString(sep),nameSpaceURI);
			return siz-v.size();
		}
	}

	///////////////////////////////////////////////////////////////////////
	/**
	* Tests whether the attributes described by aMap exist
	*
	* @param mAttribute & aMap: map of key-value pairs. any values of "*" are treated as true when the atrribute exists, regardless of value <br>
	* @tbd allow for regular expressions in values
	* @param bool bAnd: if true, all conditions described in aMap must be true (boolean and), if false any condition must match (boolean or).
	* @return bool: true, if bAnd=true and all the attributes described by aMap are present,
	* or if bAnd=false and one or more of the attributes described by aMap are present
	*/

	bool KElement::IncludesAttributes(const mAttribute & aMap, bool bAnd)const{

		int siz=aMap.size();

		if(siz==0) {
			return true;

		}else if(siz==1){
			mAttribute::const_iterator i=aMap.begin();
			return IncludesAttribute(i->first(),i->second());

		}else{			
			mAttribute::const_iterator end=aMap.end();			
			if(bAnd){
				for(mAttribute::const_iterator i=aMap.begin();i!=end;i++){
					//			cout <<i->first<<" |"<<GetAttribute(i->first)<<"| |"<<i->second<<"|"<<endl;
					if(!IncludesAttribute(i->first(),i->second()))
						return false;
				}
				return true;
			}else{
				for(mAttribute::const_iterator i=aMap.begin();i!=end;i++){
					if(IncludesAttribute(i->first(),i->second()))
						return true;
				}
				return false;
			}
		}
	}
	///////////////////////////////////////////////////////////////////////
	/**
	* Tests whether an attribute with the proper key-value pair exists
	*
	* @param WString & attName: the name of the attribute to look for
	* @param WString & attVal: the value of the attribute to look for;
	* a value of "*" is treated as true when the atrribute exists, regardless of its value <br>
	* @tbd allow for regular expressions in attVal
	* @return bool: true, if the attribute with the proper key-value pair exists
	*/

	bool KElement::IncludesAttribute(const WString & attName, const WString & attVal)const
	{
		if(throwNull()) 
			return false;
		DOMAttr* a=GetDOMAttr(attName.c_str(),0);
		if (a==0) 
			return false;

		const JDFCh* pc=attVal.c_str();
		if(IsWildcard(pc))
		{
			return true;
		}
		else
		{
			return wcscmp(pc,a->getValue())==0;
		}
	}

	///////////////////////////////////////////////////////////////////////
	/**
	* Gets a vector of attribute keys that are missing in 'this' 
	*
	* @param vWString& vReqKeys: list of required attribute keys
	* @param int nMax: maximum size of the returned vector
	* @return vWString: vector of strings that contains missing attribute keys
	*/

	vWString KElement::GetMissingAttributeVector(const vWString& vReqKeys, int nMax)const{
		vWString vAtts=GetAttributeVector();
		vWString vMissing;

		WString prefix=GetPrefix();
		bool prefixEmpty=prefix.empty();
		if(!prefixEmpty)
			prefix+=WString::colon;

		for(int i=0;i<vReqKeys.size();i++){
			const WString& req=vReqKeys[i];
			if(vAtts.hasString(req)) 
				continue;

			if((!prefixEmpty)&&(vAtts.hasString(prefix+req)))
				continue;

			vMissing.push_back(req);
			if(vMissing.size()>=nMax) 
				break;
		}
		return vMissing;
	}

	///////////////////////////////////////////////////////////////////////
	/**
	* Gets a vector of attribute keys that exist but are unknown by 'this'
	*
	* @param vWString & vKnownKeys: list of known attribute keys
	* @param vWString & vInNameSpace: list of namespaces where unknown attributes are searched for. if empty, all namespaces are searched
	* @param int nMax: maximum size of the returned vector
	* @return vWString: vector of strings that contains unknown attribute keys
	*/

	vWString KElement::GetUnknownAttributeVector(const vWString& vKnownKeys, const vWString& vInNameSpace, int nMax)const{
		vWString vAtts=KElement::GetAttributeVector();
		vWString vUnknown;
		vWString vNS=vInNameSpace;
		bool bAllNS=vInNameSpace.empty();
		for(int j=0;j<vNS.size();j++) {
			// tokenize needs a blank
			if(vNS[j]==WString::blank)
				vNS[j]=WString::emptyStr;
		}
		int siz=vAtts.size();
		WString prefix=GetPrefix();
		bool prefixEmpty=prefix.empty();
		for(int i=0;i<siz;i++){
			const WString& att=vAtts[i];
			if(bAllNS||(vNS.hasString(XMLNameSpace(att)))){
				if(vKnownKeys.hasString(att)) 
					continue;
				// check for <foo:elm foo:att="a"/>
				if( (!prefixEmpty) &&
					(prefix==XMLNSPrefix(att.c_str()))&&
					(vKnownKeys.hasString(XMLNSLocalName(att.c_str()))))
					continue;

				vUnknown.push_back(att);
				if(vUnknown.size()>=nMax) 
					break;
			}
		}
		return vUnknown;
	}
	///////////////////////////////////////////////////////////////////////
	/**
	* Gets a vector of direct child element names that are missing in 'this'
	*
	* @param vWString & vReqKeys: list of required element tag names
	* @param int nMax: maximum size of the returned vector
	* @return vWString: vector of strings that contains missing element names
	*/

	vWString KElement::GetMissingElementVector(const vWString& vReqKeys, int nMax)const{
		vWString vAtts=GetElementNameVector(true);
		vWString vMissing;

		int siz=vReqKeys.size();
		for(int i=0;i<siz;i++){
			const WString& req=vReqKeys[i];
			if(vAtts.hasString(req)) 
				continue;
			vMissing.push_back(req);
			if(vMissing.size()>=nMax) 
				break;
		}
		return vMissing;
	}

	///////////////////////////////////////////////////////////////////////
	/**
	* Gets a vector of direct child element names that may be legally inserted in 'this'
	*
	* @param vWString & vKnownKeys: list of insertable element tag names
	* @param vWString & vUnique: list of elements that may occur only once
	* @return vWString: vector of strings that contains insertable element names
	*/

	vWString KElement::GetInsertElementVector(const vWString& vKnownKeys, const vWString& vUnique)const{
		vWString vAtts=GetElementNameVector(true);
		vWString vInsert=vKnownKeys;
		for(int i=0;i<vAtts.size();i++){
			if(vUnique.hasString(vAtts[i])){
				vInsert.RemoveStrings(vAtts[i]);
			}
		}
		return vInsert;
	}

	///////////////////////////////////////////////////////////////////////
	/**
	* Gets a vector of direct child element names that exist but are unknown in 'this'
	*
	* @param vWString & vKnownKeys: list of unknown element tag names
	* @param vWString & vInNameSpace: list of namespaces where unknown element are searched for. if empty, all namespaces are searched
	* @param int nMax: maximum size of the returned vector
	* @return vWString: vector of strings that contains unknown element names
	*/

	vWString KElement::GetUnknownElementVector(const vWString& vKnownKeys, vWString vInNameSpace, int nMax)const{
		vWString vAtts=GetElementNameVector();
		vWString vUnknown;
		bool bAllNS=vInNameSpace.empty();
		for(int j=0;j<vInNameSpace.size();j++) {
			// tokenize needs a blank
			if(vInNameSpace[j]==WString::blank)
				vInNameSpace[j]=WString::emptyStr;
		}
		for(int i=0;i<vAtts.size();i++){
			const WString& att=vAtts[i];
			bool bExplicitNS=vInNameSpace.hasString(XMLNameSpace(att));
			if(bAllNS||bExplicitNS){
				if(vKnownKeys.hasString(att)) 
					continue;
				if(vKnownKeys.hasString(XMLNSLocalName(att.c_str()))) 
					continue;
				vUnknown.push_back(att);
				if(vUnknown.size()>=nMax) 
					break;
			}
		}
		return vUnknown;
	}
	///////////////////////////////////////////////////////////////////////
	/**
	* Gets a list of all direct child element names
	*
	* @param bool bLocal: if true, gets the local names, else the qualified names
	* @return vWString: vector of strings, that contains a list of all direct child element names
	* @tbd namespace handling
	*/

	vWString KElement::GetElementNameVector(bool bLocal)const{
		vElement e=GetChildElementVector();
		vWString v;
		int s=e.size();
		for(int i=0;i<s;i++) {
			if(bLocal){
				v.AppendUnique(e[i].GetLocalName());				
			}else{
				v.AppendUnique(e[i].GetNodeName());
			}
		}
		return v;
	}
	///////////////////////////////////////////////////////////////////////
	/**
	* Moves 'this' up by one level (moves from parent to grandparent) or to the closest ancestor with name newParentName
	*
	* @param WString & newParentName: name of the parent to recursively search, defaults to any name
	* @return KElement&: 'this' after moving
	*
	* @throws JDFException if 'this' is a null element and thus can't be moved or modified 
	*/

	KElement & KElement::PushUp(const WString & newParentName){
		if(isNull())
			throw JDFException(L"KElement::PushUp modifying null element");

		DOMNode* parent=domElement->getParentNode();
		if(parent==0) 
			//return *this;
			// TODO warning C4172: returning address of local variable or temporary
			return *this=KElement();

		while(42){
			parent=parent->getParentNode();
			if(parent==0) 
				//return *this;
				// TODO warning C4172: returning address of local variable or temporary
				return *this=KElement();
			if (newParentName.empty()) 
				break;
			if (newParentName==parent->getNodeName()) 
				break;
		}
		return *this=KElement((DOMElement*)parent).MoveElement(*this);
	}
	///////////////////////////////////////////////////////////////////////
	/**
	* Gets the n'th Ancestor node with name parentNode 
	*
	* @param WString & parentNode: tag name of the parent to find
	* @param int depth: the number of recursions to go through. Only counted for nodes that match parentNode
	* @return KElement: the matching parent element
	*/

	KElement KElement::GetDeepParent(const WString& parentNode,int depth)const{
		if(throwNull()) 
			return DefKElement;
		if((GetLocalName()!=parentNode)) 
			return  GetParentNode().GetDeepParent(parentNode,depth);
		if(depth<=0) 
			return *this;
		// found one, now look for deeper elements
		KElement par=GetParentNode();
		// last in chain
		if(par.isNull())
			return *this;
		// leaving structure
		if(par.GetLocalName()!=parentNode)
			return *this;
		return par.GetDeepParent(parentNode,depth-1);
	}
	///////////////////////////////////////////////////////////////////////
	/**
	* Gets the Ancestor node with name other than thisNode
	*
	* @param WString & thisNode: tag name of the parent that is skipped in the search
	* @return KElement: the matching parent element
	*/

	KElement KElement::GetDeepParentNotName(const WString& thisNode)const{
		if(throwNull()) 
			return DefKElement;
		if((GetLocalName()==thisNode)) 
			return  GetParentNode().GetDeepParentNotName(thisNode);
		return *this;
	}

	///////////////////////////////////////////////////////////////////////
	/**
	* Gets the first Ancestor of 'this' with name parentNode;
	* e.g. The resource in a resourcepool
	*
	* @param WString & parentNode: tag name of the parent to find
	* @return KElement: the matching parent element
	*/
	KElement KElement::GetDeepParentChild(const WString &parentNode)const{
		if(throwNull()) 
			return DefKElement;
		KElement par=GetParentNode();
		if(par.isNull()) 
			return DefKElement;

		if((par.GetNodeName()!=parentNode)) 
			return par.GetDeepParentChild(parentNode);
		return *this;
	}

	///////////////////////////////////////////////////////////////////////
	/**
	* Gets the n'th Ancestor node with name, that is defined in vParentNode
	*
	* @param vWString & vParentNode: list of tag names of the parent to find
	* @param int depth: the number of recursions to go through. Only counted for nodes that match vParentNode
	* @return KElement: the matching parent element
	*/

	KElement KElement::GetDeepParent(const vWString& vParentNode, int depth)const{
		if(!(vParentNode.hasString(GetLocalName()))) 
			return  GetParentNode().GetDeepParent(vParentNode,depth);
		if(depth<=0) 
			return *this;
		KElement par=GetParentNode();
		if((par==0)||!(vParentNode.hasString(par.GetLocalName()))) 
			return *this;
		return par.GetDeepParent(vParentNode,depth-1);
	}

	///////////////////////////////////////////////////////////////////////
	/**
	* Removes the child node, that matches nodeName, nameSpaceURI and number of nodes to skip
	*
	* @param WString & nodeName: name of the child node to remove, if empty or "*" removes element, that matches n 
	* @param WString & nameSpaceURI: namespace to search for
	* @param unsigned int n: number of nodes to skip before deleting
	* @return KElement: the removed element
	* @tbd clean up
	*
	* @throws JDFException if 'this' is a null element and its modifying is thus impossible
	*/

	KElement KElement::RemoveChild(const WString & nodeName, const WString & nameSpaceURI, unsigned int n){
		if(isNull())
			throw JDFException(L"KElement::RemoveChild modifying null element");

		KElement e=GetChildByTagName(nodeName,nameSpaceURI,n);
		if(e.throwNull()) 
			return e;

		SetDirty(false);
		// tbd clean up
		GetOwnerDocument().ClearTargets();

		return (DOMElement*) domElement->removeChild(e.domElement);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Removes children, that match nodeName and nameSpaceURI
	*
	* @param WString & nodeName: name of the child node to remove, if empty or "*" removes all
	* @param WString & nameSpaceURI: namespace to search for
	*
	* @throws JDFException if 'this' is a null element and its modifying is thus impossible
	*/

	void KElement::RemoveChildren(const WString&  nodeName,const WString & nameSpaceURI){
		if(isNull())
			throw JDFException(L"KElement::RemoveChildren modifying null element");
		vElement v=GetChildElementVector(nodeName,nameSpaceURI);
		if(v.size()){
			for(int i=0;i<v.size();i++){
				domElement->removeChild(v[i].domElement);
			}
			GetOwnerDocument().ClearTargets();
			SetDirty(false);
		}
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Compares element contents recursively. <br>
	* Note, that this is <em>NOT</em> the same as operator ==, which compares 'this' reference with reference of e
	*
	* @param KElement & e: the node element to compare with 'this' 
	* @return bool: true, if the contents are equivalent
	*/

	bool KElement::IsEqual(const KElement &e)const{
		if(isNull()) 
			return e.isNull();

		if(domElement==e.domElement)
			return true;

		if(e.isNull()) 
			return false;

		if(wcscmp(domElement->getNodeName(),e.domElement->getNodeName()))
			return false;


		// this raw mode is necessary for performance - the attribute maps are much too slow
		DOMNamedNodeMap* nm= domElement->getAttributes();
		int l=(nm==0)?0:nm->getLength(); 
		DOMNamedNodeMap* enm= e.domElement->getAttributes();
		int el=(enm==0)?0:enm->getLength(); 
		if(l!=el){ // different number of attributes
			return false;
		}

		// the attribute maps are luckily always ordered alphabetically! 
		// therefore we do not need to do a double loop here and can compare in synch
		for(int i=0;i<l;i++){
			// first the attribute names
			DOMNode* a=nm->item(i);
			const JDFCh* nn=a->getNodeName();
			DOMNode* ea=enm->item(i);
			const JDFCh* enn=ea->getNodeName();
			if(wcscmp(nn,enn))
				return false;

			// now compare the attribute values
			nn=a->getNodeValue();
			enn=ea->getNodeValue();
			if(wcscmp(nn,enn))
				return false;
		}


		// don't do this ... performance is miserable
		//		if(GetAttributeMap()!=e.GetAttributeMap())
		//			return false;

		// we ignore whitespace from formatting
		if(GetText().trim()!=e.GetText().trim())
			return false;

		// now recurse the kiddies (only elements, we don't care about xml comments)
		int ne=NumChildNodes(ELEMENT_NODE);
		int ene=e.NumChildNodes(ELEMENT_NODE);
		if(ne!=ene)
			return false;

		if(ne>0){
			int i=0;
			KElement subEl1=GetFirstChildElement(); 
			KElement subEl2=e.GetFirstChildElement(); 
			while(42){
				if(!subEl1.IsEqual(subEl2))
					return false;

				if(++i>=ne)
					break;

				subEl1=subEl1.GetNextSiblingElement();
				subEl2=subEl2.GetNextSiblingElement();
			}
		}

		ne=NumChildNodes(CDATA_SECTION_NODE);
		ene=e.NumChildNodes(CDATA_SECTION_NODE);
		if(ne!=ene)
			return false;

		if(ne>0){
			int cd=0;
			while(42){
				WString w1=GetCData(cd);
				WString w2=e.GetCData(cd);
				if(w1.empty()||w1.empty())
					return w1==w2;
				cd++;
			}
		}
		return true;

		// for reasons unknown to me, this doesn't work for elements in separate documents - snafu
		//		return domElement->isEqualNode(e.domElement);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets of 'this' all attribute keys as a vector of strings 
	*
	* @return vWString: a vector of all attribute keys in 'this'
	*/

	vWString KElement::GetAttributeVector()const{
		vWString v;
		if(throwNull()) 
			return v;

		DOMNamedNodeMap* nm=domElement->getAttributes();
		int l=(nm==0)?0:nm->getLength(); 
		if(l)
			v.reserve(l);

		for(int i=0;i<l;i++){
			v.push_back(nm->item(i)->getNodeName());	
		}
		return v;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets of 'this' the number of all attributes 
	*
	* @return int: number of all attributes in 'this'
	*/

	int KElement::NumAttributes()const{
		if(throwNull()) 
			return 0;
		DOMNamedNodeMap* nm= domElement->getAttributes();
		int l=(nm==0)?0:nm->getLength(); 
		return l;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets of 'this' an attribute map - key-value pairs of all attributes
	*
	* @return mAttribute: a map of key-value pairs 
	*/

	mAttribute KElement::GetAttributeMap()const{
		mAttribute m;
		if(throwNull()) 
			return m;
		DOMNamedNodeMap* nm= domElement->getAttributes();
		int l=(nm==0)?0:nm->getLength(); 

		if(l)
			m.reserve(l);

		for(int i=0;i<l;i++){
			DOMNode* a=nm->item(i);
			const JDFCh* nn=a->getNodeName();
			m.AppendPair(nn,a->getNodeValue());
			// work around to transport dom level to xmlns information
			if(wcschr(nn,L':')){
				WString prefix=XMLNSPrefix(nn);
				if(atr_xmlns!=prefix){
					WString xmlns=atr_xmlns;
					xmlns+=WString::colon+prefix;
					const JDFCh* uri=a->getNamespaceURI();
					if(!uri){
						uri=domElement->getAttribute(xmlns.c_str());
					}
					if(uri&&*uri){
						m.AppendPair(xmlns,uri);
					}
				}				
			}
		}
		return m;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Removes all attributes in all namespaces of 'this'
	*
	* @throws JDFException if 'this' is a null element and its modifying is thus impossible
	*/

	void KElement::RemoveAttributes(const vWString& attribs){
		if(isNull())
			throw JDFException(L"KElement::RemoveAttributes modifying null element");
		if(attribs.empty()){
			DOMNamedNodeMap* nm= domElement->getAttributes();
			int l=(nm==0)?0:nm->getLength(); 
			for(int i=l-1;i>=0;i--){
				domElement->removeAttribute(nm->item(i)->getNodeName());
			}
		}else{
			for(int i=0;i<attribs.size();i++)
				RemoveAttribute(attribs[i]);
		}
		SetDirty(true);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the i-th text child node of 'this'
	*
	* @param int i: index of the child text node, you are searching for. First node has index 0, second - 1, etc.
	* @return WString: text - the value of the text node
	*/

	WString KElement::GetChildText(int i)const{
		DOMNode* n=GetChildNode(TEXT_NODE,i);
		if(n==0) 
			return WString::emptyStr;
		return n->getNodeValue();
	}
	//////////////////////////////////////////////////////////////////////
	/** 
	* Gets of 'this' the text of the i-th XML CData section 
	*
	* @param int i: index of the CData section child node, you are searching for. First node has index 0, second - 1, etc.
	* @return WString: text of the i-th XML CData section
	*/

	WString KElement::GetCData(int i)const{
		DOMNode* n=GetChildNode(CDATA_SECTION_NODE,i);
		if(n==0) 
			return WString::emptyStr;
		return n->getNodeValue();
	}
	//////////////////////////////////////////////////////////////////////

	/** 
	* Gets of 'this' the text of the i-th XMLComment  
	*
	* @param int i: index of the XMLComment child node, you are searching for. First node has index 0, second - 1, etc.
	* @return WString: text of the i-th XMLComment
	*/

	WString KElement::GetXMLComment(int i)const{
		DOMNode* n=GetChildNode(COMMENT_NODE,i);
		if(!n) 
			return WString::emptyStr;
		return n->getNodeValue();
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets of 'this' the concatenated string representing all direct text child nodes
	*
	* @return WString: the concatenated string of values of all direct text child nodes
	*/

	WString KElement::GetText()const{
		if(throwNull())
			return WString::emptyStr;
		WString s;
		DOMNode* e=domElement->getFirstChild();
		while(e){
			if(e->getNodeType()==TEXT_NODE){
				s+=e->getNodeValue();
			}
			e=e->getNextSibling();
		}	
		return s;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Removes all direct text child nodes of 'this' 
	*/

	void KElement::RemoveText(){
		if(isNull())
			throw JDFException(L"KElement::RemoveText on null element");
		DOMNode* e=domElement->getFirstChild();
		while(e){
			if(e->getNodeType()==TEXT_NODE){
				domElement->removeChild(e);
			}
			e=e->getNextSibling();
		}	
		SetDirty(false);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Removes from 'this' iSkip-th child node, that match NodeType
	*
	* @param int nodeType: the DOM NodeType,if 0 count all nodes
	* @param iSkip number: number of matching child nodes to skip
	*/

	void KElement::RemoveChildNode(int nodeType,int i){
		if(isNull())
			throw JDFException(L"KElement::RemoveChildNode on null element");
		DOMNode* n=GetChildNode(nodeType,i);
		if(n!=0) {			
			domElement->removeChild(n);
			SetDirty(false);
		}
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Removes the i-th text node of 'this'
	*
	* @param int i: index of the text node to remove. First node has index 0, second - 1, etc.
	*/

	void KElement::RemoveChildText(int i){
		RemoveChildNode(TEXT_NODE,i);
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Removes the i-th XML CData section of 'this'  
	*
	* @param int i: index of the CData section child node to remove
	*/

	void KElement::RemoveCData(int i){
		RemoveChildNode(CDATA_SECTION_NODE,i);
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Removes the i-th XMLComment of 'this' 
	*
	* @param int i: index of the XML comment child node to remove
	*/

	void KElement::RemoveXMLComment(int i){
		RemoveChildNode(COMMENT_NODE,i);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the number of direct child nodes of 'this', that match NodeType
	*
	* @param int nodeType: the DOM NodeType, if 0 count all nodes
	* @return int: the counted number of direct child nodes, that match NodeType
	*/

	int KElement::NumChildNodes(int nodeType)const{
		int n=0;
		DOMNode* e=domElement->getFirstChild();
		while(e){
			if((!nodeType)||(e->getNodeType()==nodeType)){
				n++;
			}
			e=e->getNextSibling();
		}	
		return n;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the number of direct text child nodes in 'this' 
	*
	* @return int: the number of direct text child nodes in 'this'
	*/

	int KElement::NumChildText()const{
		return NumChildNodes(TEXT_NODE);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the number of direct child CData sections in 'this'
	*
	* @return int: the number of direct child CData sections
	*/
	int KElement::NumCDatas()const{
		return NumChildNodes(CDATA_SECTION_NODE);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the number of direct child XMLComment nodes in 'this'
	*
	* @return int: the number of direct child XMLComment nodes
	*/

	int KElement::NumXMLComments()const{
		return NumChildNodes(COMMENT_NODE);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets a child node of nodetype nodeType with index=iPos
	* @param int nodeType: the DOM node type to get
	*
	*    ELEMENT_NODE                = 1,
	*    ATTRIBUTE_NODE              = 2,
	*    TEXT_NODE                   = 3,
	*    CDATA_SECTION_NODE          = 4,
	*    ENTITY_REFERENCE_NODE       = 5,
	*    ENTITY_NODE                 = 6,
	*    PROCESSING_INSTRUCTION_NODE = 7,
	*    COMMENT_NODE                = 8,
	*    DOCUMENT_NODE               = 9,
	*    DOCUMENT_TYPE_NODE          = 10,
	*    DOCUMENT_FRAGMENT_NODE      = 11,
	*    NOTATION_NODE               = 12,
	*    XML_DECL_NODE               = 13
	*
	* @param int iPos: the index of the node
	* @return KElement: a node that matches the filter
	*/

	DOMNode* KElement::GetChildNode(int nodeType, int iPos)const{
		if(throwNull()) 
			return 0;

		int i=0;
		DOMNode* e=domElement->getFirstChild();
		while(e){
			if((!nodeType)||(e->getNodeType()==nodeType)){
				if(i++==iPos) 
					return e; // gotcha
			}
			e=e->getNextSibling();
		}	
		return 0;
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the name of the iSkip-th child node, that fits NodeType
	*
	* @param int nodeType: the DOM NodeType, if 0 count all nodes
	* @param int iSkip:  number of matching child nodes to skip
	* @return WString: the node name of the matching child
	*/

	WString KElement::GetChildNodeName(int nodeType,int iSkip)const{
		DOMNode* n=GetChildNode(nodeType,iSkip);
		if(n==0)
			return WString::emptyStr;
		return n->getNodeName();
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the value of the iSkip-th child node, that fits NodeType
	*
	* @param int nodeType: the DOM NodeType, if 0 count all nodes
	* @param int iSkip: number of matching child nodes to skip
	* @return WString: the node value of the matching child
	*/

	WString KElement::GetChildNodeValue(int nodeType,int iSkip)const{
		DOMNode* n=GetChildNode(nodeType,iSkip);
		if(n==0)
			return WString::emptyStr;
		return n->getNodeValue();
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the NodeType of the iSkip-th child node
	*
	* @param int iSkip: number of child nodes to skip
	* @return int: number, that determines the DOM NodeType of the child
	*/

	int KElement::GetChildNodeType(int iSkip)const{
		DOMNode* n=GetChildNode(0,iSkip);
		if(n==0)
			return WString::emptyStr;
		return n->getNodeType();

	}
	//////////////////////////////////////////////////////////////////////

	/**
	* Gets the iSkip-th child node, if it fits nodeType ELEMENT_NODE 
	* (child node is a element node, not text node, comment node ect).
	* Otherwise empty KElement is returned. <br>
	* Note, that this differs from the pure element accessors, in that intermediate text nodes etc are NOT skipped
	*
	* @param int iSkip: number of child nodes to skip, regardless of its type
	* @return KElement: the iSkip-th child node, if it is element node or otherwise an empty KElement
	*/

	KElement KElement::GetChildNodeElement(int iSkip)const{
		DOMNode* n=GetChildNode(0,iSkip);
		if(n->getNodeType()==ELEMENT_NODE){ 
			return (DOMElement*)n;
		}
		return DefKElement;

	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the first child element of 'this'
	* @return KElement: the first chid element of 'this'
	*/

	KElement KElement::GetFirstChildElement()const{
		if(throwNull()) 
			return DefKElement;
		DOMNode* e=domElement->getFirstChild();
		while(e){
			if(e->getNodeType()==ELEMENT_NODE){ 
				return (DOMElement*)e;
			}
			e=e->getNextSibling();
		}
		return DefKElement;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the next sibling element of 'this'
	* @return KElement: the next sibling element of 'this'
	*/

	KElement KElement::GetNextSiblingElement()const{
		DOMNode* e=domElement->getNextSibling();
		while(e){
			if(e->getNodeType()==ELEMENT_NODE) {
				return (DOMElement*)e;
			}
			e=e->getNextSibling();
		}
		return DefKElement;
	}

	/**
	* Gets the next sibling element of 'this'
	* @return KElement: the next sibling element of 'this'
	*/

	//////////////////////////////////////////////////////////////////////
	KElement KElement::GetNextSiblingElement(const WString & nodeName, const WString& nameSpaceURI)const{
		const JDFCh* pcNodeName=nodeName.c_str();
		const JDFCh* pcNameSpaceURI=nameSpaceURI.c_str();
		KElement e=GetNextSiblingElement();
		while(!e.isNull()){
			if(e.FitsName(pcNodeName,pcNameSpaceURI)){
				// this guy is the one
				return e;
			}
			e=e.GetNextSiblingElement();
		}
		return DefKElement;
	}
	//////////////////////////////////////////////////////////////////////

	KElement KElement::GetPreviousSiblingElement()const
	{
		DOMNode* e=domElement->getPreviousSibling();
		while(e){
			if(e->getNodeType()==ELEMENT_NODE) {
				return (DOMElement*)e;
			}
			e=e->getPreviousSibling();
		}
		return DefKElement;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Merges nodes in a way that no duplicate elements are created<br>
	* ATTENTION !! this kills pools !! since elements in e overwrites those in *this
	*
	* @param KElement e: the node element to merge with the current node
	* @param bool bDelete: if true KElement e will be deleted
	* @return KElement: the merged node element
	*
	* @throws JDFException if 'this' is a null element and thus can't be modified 
	*/

	KElement KElement::MergeElement(KElement e, bool bDelete){

		if(isNull())
			throw JDFException(L"KElement::MergeElement modifying null element");

		vElement vE=e.GetChildElementVector(); 
		for(int i=0;i<vE.size();i++){ 
			KElement m=vE[i];
			int nThis=NumChildElements(m.GetNodeName());
			if(nThis==1){
				int nE=e.NumChildElements(m.GetNodeName());
				if(nE==1){
					GetElement(m.GetNodeName()).MergeElement(m,bDelete);
					continue; // we've merged the only element and can continue with the next
				}
			}
			// it was impossible to merge, therefore simply copy over
			if(bDelete){
				MoveElement(m);
			}else{
				CopyElement(m);
			}
		}

		SetText(e.GetText());
		SetAttributes(e);
		return *this;	
	}

	//////////////////////////////////////////////////////////////////////	
	XMLDocUserData* KElement::getXMLDocUserData() const
	{
		return GetOwnerDocument().GetXMLDocUserData();
	}
	//////////////////////////////////////////////////////////////////////	
	/**
	* Gets of 'this' a child with a matching attribute
	*
	* @param WString & nodeName: name of the child node to search for
	* @param WString & attName: attribute name to search for
	* @param WString & nameSpaceURI: namespace to search for
	* @param WString & attVal: a special value to search for
	* @param int index: if more then one child meets the condition, you can specify the one to return via an index
	* @param bool bDirect: if true, looks only in direct children, else search through all children, grandchildren etc.
	* @return KElement: the child element, which matches the above conditions
	*/

	KElement KElement::GetChildWithAttribute(const WString & nodeName, const WString &  attName, const WString & nameSpaceURI, const WString & attVal, int index, bool bDirect)const{
		if(throwNull()) 
			return DefKElement;

		XMLDocUserData* ud=0;
		const JDFCh* pcAttVal=attVal.c_str();
		if(attName.equals(atr_ID)&&!IsWildcard(pcAttVal))
		{
			ud = getXMLDocUserData();
			if(ud!=0)
			{
				KElement kRet=ud->GetTarget(attVal);
				if(!kRet.isNull()) // a matching element is somewhere around here
				{
					if(bDirect)
					{
						if(kRet.GetParentNode()!=*this)
						{
							kRet=KElement::DefKElement; // it is somewhere else, not a child of this!
						}
					}
				}
				if (!kRet.isNull())
					return kRet;
			}
		}


		if(bDirect){ // inlined for performance			
			KElement e=GetFirstChildElement();
			if(e.isNull())
				return e;

			const JDFCh* pcNodeName=nodeName.c_str();
			const JDFCh* pcNameSpaceURI=nameSpaceURI.c_str();

			bool bAlwaysFit=IsWildcard(pcNodeName)&&IsWildcard(pcNameSpaceURI);

			while(!e.isNull()){
				if(ud!=0)
				{
					DOMAttr* at=GetDOMAttr(L"ID",0);
					if(at!=0)
						ud->SetTarget(e,at->getValue());
				}

				if(bAlwaysFit||e.FitsName(pcNodeName,pcNameSpaceURI)){
					if(e.IncludesAttribute(attName,attVal)){
						return e;
					}
				}
				e=e.GetNextSiblingElement();
			}
			return e;
		}else{
			mAttribute m;
			m.AddPair(attName,attVal);
			return GetChildByTagName(nodeName,nameSpaceURI,index,m,bDirect);
		}
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets a vector of all children with a matching attribute
	*
	* @param WString & nodeName: elementname you are searching for
	* @param WString & attName: attributes you are looking for
	* @param WString & nameSpaceURI: nameSpace you are searching for
	* @param WString & attVal: value of the attribute you are searching for
	* @param bool bDirect: if true, looks only in direct children, else search through all children, grandchildren etc.
	* @return vElement: vector with all found elements
	*/

	vElement KElement::GetChildrenWithAttribute(const WString & nodeName, const WString & attName, const WString & nameSpaceURI, const WString & attVal, bool bDirect)const{
		mAttribute m;
		m.AppendPair(attName,attVal);
		return GetChildrenByTagName(nodeName,nameSpaceURI,m,bDirect);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets a list of all values of the attribute attName in the children of this node
	*
	* @param WString & nodeName: element name you are searching for
	* @param WString & attName: attributes you are looking for
	* @param WString & nameSpaceURI: nameSpace you are searching for
	* @param WString & attVal: value of the attribute you are searching for
	* @param bool bDirect: if true, looks only in direct children, else searchs through all children, grandchildren etc.
	* @param bool bUnique: if you want to make sure, the attribute is unique, set
	* this boolean to true. Otherwise attribute attName is added to the returned
	* @return vWString: vector of strings, that contains values of the attribute attName
	*/

	vWString KElement::GetChildAttributeList(const WString & nodeName, const WString & attName, const WString & nameSpaceURI, const WString & attVal,bool bDirect, bool bUnique)const{
		vElement e=GetChildrenWithAttribute(nodeName,attName,nameSpaceURI,WString::star,bDirect);
		vWString v;
		bool bAttWildCard=IsWildcard(attVal.c_str());
		for(int i=0;i<e.size();i++){
			WString s=e[i].GetAttribute(attName,nameSpaceURI);
			if(!bAttWildCard){ // fill only matching attributes
				if(s!=attVal)
					continue;
			}
			if(bUnique){
				v.AppendUnique(s);
			}else{
				v.push_back(s);
			}
		}
		return v;
	}

	void KElement::getChildAttributeSet(SetWString*sSet,const WString & nodeName, const WString & attName, const WString & nameSpaceURI, const WString & attVal,bool bDirect)const
	{
		vElement e=GetChildrenWithAttribute(nodeName,attName,nameSpaceURI,WString::star,bDirect);
		bool bAttWildCard=IsWildcard(attVal.c_str());
		for(int i=0;i<e.size();i++){
			WString s=e[i].GetAttribute(attName,nameSpaceURI);
			if(!bAttWildCard){ // fill only matching attributes
				if(s!=attVal)
					continue;
			}
			sSet->add(s);
		}
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Gets of 'this' all child elements, matching the given conditions <br>
	* bypass nodelist --> performance!
	*
	* @param WString & nodeName: elementname you are searching for
	* @param WString & nameSpaceURI: nameSpace you are searching for
	* @param Attributes & mAttrib: map of attributes you are looking for.
	* @param bool bAnd: if true, a child is only added if it includes all attributes, specified in mAttrib
	* @param unsigned int maxSize: maximum size of the element vector
	* @return vElement: vector with all found elements
	*/

	vElement KElement::GetChildElementVector(const WString & nodeName, const WString & nameSpaceURI, const mAttribute &mAttrib, bool bAnd, unsigned int maxSize, bool bFollowRefs)const{
		vElement v;
		if(throwNull()) 
			return v;

		KElement e=GetFirstChildElement();
		if(e.isNull())
			return v;

		int i=0;
		const JDFCh* pcNodeName=nodeName.c_str();
		const JDFCh* pcNameSpaceURI=nameSpaceURI.c_str();

		bool bAlwaysFit=IsWildcard(pcNodeName)&&IsWildcard(pcNameSpaceURI);
		bool bHasNoMap=mAttrib.empty();

		while(!e.isNull()){
			if(bAlwaysFit||e.FitsName(pcNodeName,pcNameSpaceURI)){
				if(bHasNoMap||e.IncludesAttributes(mAttrib,bAnd)){
					// this guy is the one
					v.push_back(e);
					if(++i==maxSize) 
						break;
				}
			}
			e=e.GetNextSiblingElement();
		}
		return v;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the child of 'this' by tag name, nameSpaceURI 
	* and attribute map, if attribute map is not empty <br>
	* Follows only direct links, e.g. as in a JDF tree. Hidden nodes that are children of non-matching nodes are ignored. <br>
	* Gets the first matching element.
	*
	* @param WString & nodeName: elementname you are searching for
	* @param WString & nameSpaceURI: nameSpace you are searching for
	* @param mAttribute & mAttrib: map of attributes you are looking for <br> Wildcards in the attribute map are supported
	* @param bool bDirect: if true, return value is a vector only of all direct child elements. <br>
	* Otherwise the returned vector contains nodes of arbitrary depth
	* @param bool bAnd: if true, a child is only added if it includes all attributes, specified in mAttrib
	* @return KElement: the first found element
	*/

	KElement KElement::GetTreeElement(const WString & nodeName, const WString & nameSpaceURI, const mAttribute &mAttrib, bool bDirect, bool bAnd)const{
		if(throwNull()) 
			return DefKElement;

		KElement e=GetFirstChildElement();
		const JDFCh* pcNodeName=nodeName.c_str();
		const JDFCh* pcNameSpaceURI=nameSpaceURI.c_str();

		bool bAlwaysFit=IsWildcard(pcNodeName)&&IsWildcard(pcNameSpaceURI);
		bool bHasNoMap=mAttrib.empty();

		while(!e.isNull()){
			if(bAlwaysFit||e.FitsName(pcNodeName,pcNameSpaceURI)){
				if(bHasNoMap||e.IncludesAttributes(mAttrib,bAnd)){
					// this guy is the one
					return e;
				}
				if(!bDirect){ // if not direct, recurse
					KElement ee=e.GetTreeElement(nodeName,nameSpaceURI,mAttrib,bDirect,bAnd);
					if(!ee.isNull())
						return ee;
				}
			}
			e=e.GetNextSiblingElement();
		}
		return DefKElement;
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Gets children of 'this' by tag name, nameSpaceURI
	* and attribute map, if attribute map is not empty <br>
	* Follows only direct links, e.g. as in a JDF tree. Hidden nodes that are children of non-matching nodes are ignored
	*
	* @param WString & nodeName: elementname you are searching for
	* @param WString & nameSpaceURI: nameSpace you are searching for
	* @param mAttribute & mAttrib: map of attributes you are looking for <br> Wildcards in the attribute map are supported
	* @param bool bDirect: if true, return value is a vector only of all direct elements. <br>
	* Otherwise the returned vector contains nodes of arbitrary depth
	* @param bool bAnd: if true, a child is only added, if it includes all attributes, specified in mAttrib
	* @return vElement: vector with all found elements
	*/

	vElement KElement::GetTree(const WString & nodeName, const WString & nameSpaceURI, const mAttribute &mAttrib, bool bDirect, bool bAnd)const{
		vElement v;
		if(throwNull()) 
			return v;

		KElement e=GetFirstChildElement();
		const JDFCh* pcNodeName=nodeName.c_str();
		const JDFCh* pcNameSpaceURI=nameSpaceURI.c_str();

		bool bAlwaysFit=IsWildcard(pcNodeName)&&IsWildcard(pcNameSpaceURI);
		bool bHasNoMap=mAttrib.empty();

		while(!e.isNull()){
			if(bAlwaysFit||e.FitsName(pcNodeName,pcNameSpaceURI)){
				if(bHasNoMap||e.IncludesAttributes(mAttrib,bAnd)){
					// this guy is the one
					v.push_back(e);
				}
				if(!bDirect){ // if not direct, recurse
					vElement vv=e.GetTree(nodeName,nameSpaceURI,mAttrib,bDirect,bAnd);
					v.insert(v.end(),vv.begin(),vv.end());
				}

			}
			e=e.GetNextSiblingElement();
		}
		return v;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Checks, if 'this' is an ancestor of child or not. <br>
	* Recursively checks child parents, parent's parents, etc. 
	*
	* @param KElement child: child to check 
	* @return bool: true, if 'this' is an ancestor
	*/	

	bool KElement::IsAncestor(KElement child)const{
		if(child.throwNull()) 
			return false;
		if(child==*this) 
			return true;
		return IsAncestor(child.GetParentNode());
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the target of link
	* Follows an ID-IDREF pair by recursively searching for an attrib with the value id
	*
	* @param WString id: value of the ID tag to search
	* @param WString attrib: name of the ID tag, defaults to "ID"
	*
	* @tbd add namespace search String nameSpaceURI: nameSpace of the ID attribute, defaults to empty
	* @return KElement: the target of link - the element node.
	*/

	KElement KElement::GetTarget(const WString & id, const WString & attrib)const{
		if(throwNull()) 
			return *this;
		// not a link --> return null
		if (id.empty()) 
			return DefKElement;

		XMLDoc ownerDoc=GetOwnerDocument();
		XMLDocUserData* ud=0;

		if(attrib==atr_ID){
			ud=ownerDoc.GetXMLDocUserData();
			if(ud!=0){
				KElement t=ownerDoc.GetTarget(id);
				if(!t.isNull()){
					return t;
				}

			}
		}
		// loop upwards from here
		// links are most likely quite local
		// tbd: don't re-search known dead branches
		KElement root=*this;
		KElement docRoot=GetDocRoot();
		KElement excludeElement;
		while (!root.isNull()){
			KElement t=root.GetDeepElementByID(attrib.c_str(),id.c_str(),excludeElement,ud);
			// search tree one level higher
			if(t.isNull()){
				if(root==docRoot) 
					return DefKElement;
				excludeElement=root;
				root=root.GetParentNode();
				continue;
			}
			// fill the user data of the document with the target map
			if(ud!=0){
				ud->SetTarget(t,id);
			}
			// found it; return it
			return t;
		}
		// tried starting at the root; found nothing
		return DefKElement;
	}


	//////////////////////////////////////////////////////////////////////
	/**
	* Gets an element as defined by XPath to value <br>
	*
	* @tbd enhance the subsets of allowed XPaths, now only .,..,/,@ are supported
	* @param WString & path: XPath abbreviated syntax representation of the attribute, e.g parentElement/thisElement@thisAtt
	* @return KElement: the specified element
	*/
	/*
	KElement KElement::GetXPathElement(const WString & path)const{
	DOMDocument* dd=GetOwnerDocument().GetDOMDocument();
	try
	{
	const DOMXPathNSResolver* resolver=dd->createNSResolver(domElement);
	//	DOMXPathExpression xpe*=dd->createExpression(path.c_str(),dd->createNSResolver(domElement));
	DOMXPathResult* result=(DOMXPathResult*) dd->evaluate(path.c_str(),domElement,resolver,DOMXPathResult::FIRST_ORDERED_NODE_TYPE,0);
	return KElement((DOMElement*)result->getSingleNodeValue());
	}
	catch (DOMException x)
	{
	std::cout<<WString(x.getMessage())<<std::endl;
	}
	return DefKElement;
	}
	*/
	KElement KElement::GetXPathElement(const WString & path)const{
		if(throwNull()) 
			return DefKElement;
		if(path.empty()) 
			return *this;
		if(path[0]==L'/'){ 
			KElement r=GetDocRoot();
			int nextPos=path.find(L"/",2);
			if(path.substring(1,nextPos)!=r.GetNodeName())
				return DefKElement;
			if(nextPos==WString::npos)
				return *this;

			return r.GetXPathElement(path.substring(nextPos+1));
		}
		if(path.leftStr(2)==L"./") 
			return GetXPathElement(path.substring(2));
		if(path.leftStr(3)==L"../") 
			return GetParentNode().GetXPathElement(path.substring(3));
		int posB0=path.find(L"[");
		int pos=path.find(L"/");
		int iSkip=0;
		WString newPath=path;
		if(posB0!=path.npos && (posB0<pos || pos==WString::npos)){
			int posB1=path.find(L"]");
			iSkip=path.substring(posB0+1,posB1);
			iSkip--;
			newPath=path.leftStr(posB0)+path.substring(posB1+1,path.npos);
			pos=newPath.find(L"/");
		}
		if(pos!=newPath.npos){ 
			KElement e=GetElement(newPath.leftStr(pos),WString::emptyStr,iSkip);
			return e.GetXPathElement(newPath.substring(pos+1));
		}
		int posA=newPath.find(L"@");
		if(posA!=newPath.npos) 
			return GetElement(newPath.leftstring(posA),WString::emptyStr,iSkip);
		return GetElement(newPath,WString::emptyStr,iSkip);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the XPath full tree representation of 'this'
	*
	* @return WString: the XPath representation of 'this' e.g. /root/parent/element
	*/

	WString KElement::GetXPath()const{
		if(throwNull()) 
			return WString::emptyStr;

		JDFCh pathBuf[1024],buf[16]; // we probably wont need more than 13 digits for the number of sibling nodes -> this is really safe!

		KElement parent=*this;
		WString path; // tbd handle namespaces
		while(!parent.isNull()){
			WString LastNodeName=parent.GetNodeName();
			const JDFCh* pcLastNodeName=LastNodeName.c_str();
			KElement e=parent.GetParentNode().GetElement(LastNodeName);
			int i=1;
			*buf=0;
			while(!e.isNull()){
				if(e==parent){
					buf[0]=L'[';
					JDFCh* pI=_itow(i,buf+1,10);
					while(*pI)
						pI++;
					*pI++=L']';
					*pI++=0;

					//					LastNodeName.append(buf);
					break;
				}
				do{ // inline it here for speed
					e=e.GetNextSiblingElement();
				}while((!e.isNull())&&(!e.FitsName(pcLastNodeName)));
				i++;
			}
			// speed is the thing!
			pathBuf[0]=L'/';
			wcscpy(pathBuf+1,pcLastNodeName);
			if(*buf)
				wcscat(pathBuf+1,buf);
			wcscat(pathBuf+1,path.c_str());
			path=pathBuf;
			parent=parent.GetParentNode();
		}
		return path;
	}


	//////////////////////////////////////////////////////////////////////
	/**
	* Gets an element as defined by XPath to value and creates it if it does not exist <br>
	*
	* @tbd enhance the subsets of allowed XPaths, now only .,..,/,@ are supported
	* @param WString & path: XPath abbreviated syntax representation of the attribute, e.g parentElement/thisElement@thisAtt
	* @return KElement: the specified element
	*/

	KElement KElement::GetCreateXPathElement(const WString & path){
		if(throwNull()) 
			return DefKElement;
		if(path.empty()) 
			return *this;
		JDFCh path0=path[0];
		if(path0==L'/') {
			KElement r=GetDocRoot();
			int nextPos=path.find(WString::slash,2);
			if(path.substring(1,nextPos)!=r.GetNodeName())
				throw JDFException(L"GetCreateXPathElement:: invalid path: "+path);
			if(nextPos==WString::npos)
				return *this;

			return r.GetCreateXPathElement(path.substring(nextPos+1));
		}
		if(path0==L'.'){
			if(path.leftStr(2)==L"./") 
				return GetCreateXPathElement(path.substring(2));
			if(path.leftStr(3)==L"../") 
				return GetParentNode().GetCreateXPathElement(path.substring(3));
		}
		int posB0=path.find(L"[");
		int iSkip=0;
		WString newPath=path;
		int pos=newPath.find(WString::slash);
		if(posB0!=path.npos && (posB0<pos || pos==WString::npos)){
			int posB1=path.find(L"]");
			iSkip=path.substring(posB0+1,posB1);
			iSkip--;
			newPath=path.leftStr(posB0)+path.substring(posB1+1,path.npos);
			pos=newPath.find(L"/");
		}
		if(pos!=newPath.npos){ 
			int n=NumChildElements(newPath.leftStr(pos));
			for(int i=n;i<iSkip;i++)
				AppendElement(newPath.leftStr(pos),WString::emptyStr);
			KElement e=GetCreateElement(newPath.leftStr(pos),WString::emptyStr,iSkip);
			return e.GetCreateXPathElement(newPath.substring(pos+1));
		}
		int posA=newPath.find(L"@");
		if(posA!=newPath.npos){ 
			int n=NumChildElements(newPath.leftStr(posA));
			for(int i=n;i<iSkip;i++)
				AppendElement(newPath.leftstring(posA),WString::emptyStr);
			return GetCreateElement(newPath.leftstring(posA),WString::emptyStr,iSkip);
		}
		int n=NumChildElements(newPath);
		for(int i=n;i<iSkip;i++)
			AppendElement(newPath,WString::emptyStr);
		return GetCreateElement(newPath,WString::emptyStr,iSkip);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Sets an attribute as defined by XPath to value <br>
	*
	* @tbd enhance the subsets of allowed XPaths, now only .,..,/,@ are supported
	* @param WString & path: XPath abbreviated syntax representation of the attribute, e.g parentElement/thisElement@thisAtt
	* @param WString & value: string to be appended
	*
	* @throws JDFException if the defined path is a bad attribute path
	*/

	void KElement::SetXPathAttribute(const WString & path, const WString & value){
		int pos=path.find(L"@");
		if(pos==path.npos) 
			throw JDFException(L"SetXPathAttribute - bad attribute path: "+path);
		WString att=path.substr(pos+1);
		GetCreateXPathElement(path.leftStr(pos)).SetAttribute(att,value);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets an attribute as defined by XPath to value namespace prefixes are resolved <br>
	*
	* @tbd enhance the subsets of allowed XPaths, now only .,..,/,@ are supported
	* @param WString & path: XPath abbreviated syntax representation of the attribute, e.g parentElement/thisElement@thisAtt
	* @param WString & def: default value if it doesn't exist
	* @return WString: the String value of the attribute
	*
	* @throws JDFException if the defined path is a bad attribute path
	*/

	WString KElement::GetXPathAttribute(const WString & path, const WString & def)const{
		int pos=path.find(L"@");
		if(pos==path.npos) 
			throw JDFException(L"GetXPathAttribute - bad attribute path: "+path);
		WString att=path.substr(pos+1);
		return GetXPathElement(path.leftStr(pos)).GetAttribute(att,WString::emptyStr,def);
	}

	//////////////////////////////////////////////////////////////////////
	void KElement::RemoveXPathAttribute(const WString & path){
		int pos=path.find(L"@");
		if(pos==path.npos) 
			throw JDFException(L"GetXPathAttribute - bad attribute path: "+path);
		WString att=path.substr(pos+1);
		return GetXPathElement(path.leftStr(pos)).RemoveAttribute(att,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Comma separated list of all required attributes. KElement is generic, therefore the list is empty
	* @return WString: the comma separated list of required attribute keys
	*/

	WString KElement::RequiredAttributes()const{
		return WString::emptyStr;
	};

	//////////////////////////////////////////////////////////////////////

	/**
	* Comma separated list of all optional attributes. 
	* KElement is generic, therefore only the XML generic attributes are listed <br>
	* xmlns: the namespace declaration
	* @return WString: the comma separated list of optional attribute keys
	*/

	WString KElement::OptionalAttributes()const{
		static const WString optionalAttributes=atr_xmlns+L",xsi:type,xmlns:xsi,xsi:schemaLocation";
		return optionalAttributes;
	};

	//////////////////////////////////////////////////////////////////////	
	/**
	* Comma separated list of all unique element names that may occur at most once; 
	* KElement is generic, therefore the list is empty
	* @return WString: the comma separated list of unique element names
	*/

	WString KElement::UniqueElements()const{
		return WString::emptyStr;
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* Comma separated list of all required element names; KElement is generic, therefore the list is empty
	* @return WString: the comma separated list of required element names
	*/

	WString KElement::RequiredElements()const{
		return WString::emptyStr;
	};
	//////////////////////////////////////////////////////////////////////	
	/**
	* Comma separated list of all optional element names; KElement is generic, therefore the list is empty
	* @return WString: the comma separated list of optional element names
	*/

	WString KElement::OptionalElements()const{
		return WString::emptyStr;
	};

	//////////////////////////////////////////////////////////////////////

	KElement KElement::GetParentNode()const{
		if(throwNull()) 
			return DefKElement; 
		DOMNode* par = domElement->getParentNode();
		if (par==0)
			return DefKElement;
		if (par->getNodeType()!=ELEMENT_NODE)
			return DefKElement;
		return (DOMElement*)par;
	};

	//////////////////////////////////////////////////////////////////////
	/**
	* Checks, if 'this' has a specific attribute <br>
	* This version checks within the exact xml element
	*
	* @param WString & attrib: the name of the attribute to look for
	* @param WString & nameSpaceURI: the nameSpace to look in
	* @param bool bInherit: if true also checks recursively in parent elements
	* @return bool: true, if the attribute is present
	*/
	bool KElement::HasAttribute(const WString & attrib, const WString & nameSpaceURI,bool bInherit)const{ 
		if(throwNull()) 
			return false;

		if(bInherit){
			return KElement::GetInheritedAttribute(attrib,nameSpaceURI,WString::quote).compare(WString::quote)!=0;
		}else{
			return GetDOMAttr(attrib.c_str(),nameSpaceURI.c_str())!=0;
		}
	};

	//////////////////////////////////////////////////////////////////////
	/**
	* Removes an attribute from 'this'
	*
	* @param WString & attrib: the name of attribute to remove
	* @param WString & nameSpaceURI: the namespace 'this' is in
	*
	* @throws JDFException if 'this' is a null element and its modifying is thus impossible
	*/

	void KElement::RemoveAttribute(const WString & attrib, const WString & nameSpaceURI){
		if(isNull())
			throw JDFException(L"KElement::RemoveAttribute modifying null element");

		DOMAttr* a=GetDOMAttr(attrib.c_str(),nameSpaceURI.c_str());
		if (a){
			domElement->removeAttributeNode(a);
			// only set 
			SetDirty(true);
		}	
	};

	//////////////////////////////////////////////////////////////////////
	/**
	* Renames an attribute and its namespace
	*
	* @param WString & oldName: old attribute name (local name) to move from
	* @param WString & newName: new attribute name (qualified name) to move to
	* @param WString & nameSpaceURI: attribute nameSpaceURI to move from
	* @param WString & newNameSpaceURI: attribute nameSpaceURI to move to
	*
	* @throws JDFException if 'this' is a null element and its modifying is thus impossible
	*/

	void KElement::RenameAttribute(const WString & oldName, const WString &newName,  const WString & nameSpaceURI,const WString & newNameSpaceURI){
		if(isNull())
			throw JDFException(L"KElement::RenameAttribute modifying null element");

		if (!HasAttribute(oldName,nameSpaceURI)) 
			return;
		SetAttribute(newName,GetAttribute(oldName,nameSpaceURI),newNameSpaceURI);
		RemoveAttribute(oldName,nameSpaceURI);
	};

	//////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////
	/**
	* Checks, if in 'this' are any missing attributes
	*
	* @return bool: true, if one or more attributes are missing 
	*/

	bool KElement::HasMissingAttributes()const{ 
		return GetMissingAttributes(1).size()>0;
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* Checks, if in 'this' are any unknown attributes
	*
	* @param bool bIgnorePrivate: if true, looks only in default and JDF namespaces
	* @return bool: true, if one or more attributes are unknown
	*/

	bool KElement::HasUnknownAttributes(bool bIgnorePrivate)const{ 
		return GetUnknownAttributes(bIgnorePrivate,1).size()>0;
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* Tests, whether 'this' has any missing direct child elements
	*
	* @return bool: true, if one or more direct child elements are missing
	*/

	bool KElement::HasMissingElements()const{ 
		return GetMissingElements(1).size()>0;
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* Tests, whether 'this' contains direct child element names, that may be legally inserted in it ones more 
	*
	* @return bool: true, if direct child element names may be inserted ones more
	*/

	bool KElement::HasInsertElements()const{ 
		return GetInsertElements().size()>0;
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* Tests, whether 'this' has any unknown direct child elements
	*
	* @param bool bIgnorePrivate: if true, only looks in default and JDF namespaces
	* @return bool: true, if direct child elements exist but are unknown in 'this'
	*/

	bool KElement::HasUnknownElements(bool bIgnorePrivate)const{ 
		return GetUnknownElements(bIgnorePrivate,1).size()>0;
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* Gets a vector of attribute keys, that are missing in 'this'
	*
	* @param int nMax: maximum size of the returned vector
	* @return vWString: vector of strings, that contains missing attribute keys
	*/

	vWString KElement::GetMissingAttributes(int nMax)const{
		return GetMissingAttributeVector(RequiredAttributes().Tokenize(WString::comma),nMax);
	};

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets a vector of attribute keys that exist but are unknown by 'this'
	*
	* @param bool bIgnorePrivate: if true, looks only in default and JDF namespaces
	* @param int nMax: maximum size of the returned vector
	* @return vWString: vector of strings, that contains unknown attribute keys
	* @tbd clean up namespace handling
	*/

	vWString KElement::GetUnknownAttributes(bool bIgnorePrivate,int nMax)const{
		if(IsAbstract())
			return vWString::emptyvStr;
		return GetUnknownAttributeVector(KnownAttributes().Tokenize(WString::comma),bIgnorePrivate ?WString(L" :JDF").Tokenize(WString::colon):vWString::emptyvStr,nMax);
	};

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets a vector of direct child element names, that are missing in 'this'
	*
	* @param int nMax: maximum size of the returned vector
	* @return vWString: vector of strings, that contains missing element names
	*/

	vWString KElement::GetMissingElements(int nMax)const{
		return GetMissingElementVector(RequiredElements().Tokenize(WString::comma),nMax);
	};

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets a vector of direct child element names, that exist but are unknown in 'this'
	*
	* @param bool bIgnorePrivate: if true, only looks in default and JDF namespaces
	* @param int nMax: maximum size of the returned vector
	* @return vWString: vector of strings, that contains unknown element names
	*/

	vWString KElement::GetUnknownElements(bool bIgnorePrivate,int nMax)const{
		if(IsAbstract())
			return vWString();
		return GetUnknownElementVector(KnownElements().Tokenize(WString::comma),bIgnorePrivate ?WString(L" :JDF").Tokenize(WString::colon):vWString::emptyvStr,nMax);
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* Gets a vector of direct child element names, that may be legally inserted into 'this'
	*
	* @return vWString: vector of strings, that contains insertable element names
	*/

	vWString KElement::GetInsertElements()const{
		if(IsAbstract())
			return WString::star;
		return GetInsertElementVector(KnownElements().Tokenize(WString::comma), UniqueElements().Tokenize(WString::comma));
	};

	//////////////////////////////////////////////////////////////////////
	/**
	* Adds a NameSpace and maps the prefix to a URI. <br>
	* Checks all parents, whether such namespace is already defined in an ancestor
	*
	* @param WString & prefix: the namespace prefix to set
	* @param WString nameSpaceURI: the namespace URI to set
	* @return bool: true if newly set, false if already there and matching
	*/

	bool KElement::AddNameSpace(const WString & prefix, const WString nameSpaceURI){
		if(prefix==atr_xmlns) // never ever write xmlns::xmlns=...
			return false;

		WString ns=atr_xmlns;
		if(!prefix.empty()){
			ns+=WString::colon+prefix;
		}

		WString oldNS=GetInheritedAttribute(ns);
		if(oldNS==nameSpaceURI) 
			return false;

		SetAttribute(ns,nameSpaceURI,atr_xmlnsURI);
		return true;
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* Searches for the first occurrence of the attribute with name attrib in 'this' or any its ancestors 
	*
	* @param WString & attrib: the attribute key
	* @param WString & nameSpaceURI: the XML-namespace to look in
	* @param WString & def: the default value to return if attrib does not exist
	* @return WString: value of attribute found, value of def if not available
	* @since 300402 
	*/

	WString KElement::GetInheritedAttribute(const WString & attrib, const WString & nameSpaceURI, const WString& def)const{
		static const WString dummyDef=L"\"\'"; // this should be sufficiently improbable
		WString s=GetAttribute(attrib,nameSpaceURI,dummyDef);
		if(s!=dummyDef) 
			return s;

		KElement n=GetParentNode();
		if(n.isNull()) 
			return def;

		return n.GetInheritedAttribute(attrib,nameSpaceURI,def);
	}

	//////////////////////////////////////////////////////////////////////
	// MM added 2001-08-31: 
	/**
	* Searches for the first occurrence of the child element with name elementName in 'this' or any its ancestors
	*
	* @param WString & elementName: name of the child element, you are looking for
	* @param WString & nameSpaceURI: XML-namespace to look in
	* @param int iSkip: number of matching child nodes to skip
	* @return KElement: the found child element 
	*/

	KElement KElement::GetInheritedElement(const WString& elementName,const WString & nameSpaceURI, int iSkip)const{
		KElement e= GetElement(elementName, nameSpaceURI, iSkip);
		if(!e.isNull())
			return e;

		KElement n=GetParentNode();
		if(n.isNull()) 
			return DefKElement;

		return n.GetInheritedElement(elementName, nameSpaceURI, iSkip);
	}

	//////////////////////////////////////////////////////////////////////

	/**
	* Deletes itself from its parent
	* @return KElement: the deleted element
	*
	* @throws JDFException if 'this' is a null element and thus can't be deleted or modified 
	*/

	KElement KElement::DeleteNode(){
		if(isNull())
			throw JDFException(L"KElement::DeleteNode modifying null element");

		KElement parent=GetParentNode();

		// this has already been removed and is therefore in nirvana; it has no parent.
		if(parent.throwNull())
			return DefKElement;

		parent.SetDirty(false);
		GetOwnerDocument().RemoveTarget(*this);

		// 210802 RP inlined call to KNode::DeleteNode
		DOMElement* oldNode=(DOMElement*)parent.domElement->removeChild(domElement);
		*this=(DOMElement*) 0;
		return (DOMElement*)oldNode;			
	}


	//////////////////////////////////////////////////////////////////////
	/**
	* Tests whether the specified nodename and namespace fits the nodename and namespace of 'this'
	*
	* @param JDFCh* nodeName: the name of the node to test. may be either local or qualified
	* @param JDFCh* nameSpaceURI: the namespace of the node to test.
	* @return bool: true if fits 
	*/

	bool KElement::FitsName(const JDFCh* nodeName, const JDFCh* nameSpaceURI)const{
		if(throwNull())
			return false;

		bool bNameOK=IsWildcard(nodeName);		

		// first check name, since it is faster
		if(!bNameOK){
			const JDFCh* nn=domElement->getNodeName();
			if(!wcscmp(nn,nodeName)){
				bNameOK=true;
			}else{
				const JDFCh* posColon=wcschr(nn,L':');
				if (posColon&&!wcscmp(++posColon,nodeName)){
					bNameOK=true;
				}
			}
		}

		// only check ns, if the name is ok
		if(bNameOK&&!IsWildcard(nameSpaceURI)){
			if(GetNamespaceURI().compare(nameSpaceURI)){
				bNameOK=false;
			}
		}
		return bNameOK;		
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Tests whether the specified nodename and namespace fits the nodename and namespace of 'this'
	*
	* @param JDFCh* nodeName: the name of the node to test. may be either local or qualified
	* @param JDFCh* nameSpaceURI: the namespace of the node to test.
	* @return bool: true if fits 
	*/

	bool KElement::FitsName(const JDFCh* nodeName)const{
		if(throwNull())
			return false;

		if(IsWildcard(nodeName))
			return true;		

		if(!wcscmp(domElement->getNodeName(),nodeName))
			return true;

		return false;

	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Sets 'this' or its closest parent element with an id as dirty 
	*/

	void KElement::SetDirty(bool bAttribute)const{
		if(!domElement)
			return;

		// use the static methods to avoid ref counting
		XMLDocUserData* pUserData=XMLDoc::GetXMLDocUserData(domElement->getOwnerDocument());
		if(pUserData){
			pUserData->SetDirty(this, bAttribute);
		}
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Comma separated list of all required + optional attributes.
	* KElement is generic, therefore the list is empty 
	* @return WString: the comma separated list of known attribute keys
	*/

	WString KElement::KnownAttributes()const{
		return RequiredAttributes()+WString::comma+OptionalAttributes();
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* Comma separated list of all known element names; KElement is generic, therefore the list is empty
	* @return WString: the comma separated list of known element names
	*/

	WString KElement::KnownElements()const{
		return RequiredElements()+WString::comma+OptionalElements();
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* Checks, if 'this' has child element nodes
	*
	* @return bool: true, if 'this' has one or more child element nodes 
	*/

	bool KElement::HasChildElements()const{
		return HasChildNodes(ELEMENT_NODE);
	};	
	//////////////////////////////////////////////////////////////////////
	/**
	* Checks, if 'this' has a child with matching NodeName and nameSpace
	*
	* @param WString & NodeName: child NodeName to search for
	* @param WString & nameSpaceURI: the nameSpace to look for
	* @param bool bInherit: if true also checks recursively in parent elements 
	* @return bool: true, if the child with matching NodeName and nameSpace was found in 'this'
	*/

	bool KElement::HasChildElement(const WString & NodeName,const WString & nameSpaceURI,bool bInherit)const{
		if(bInherit){
			return !GetInheritedElement(NodeName,nameSpaceURI).isNull();
		}else{
			return !GetElement(NodeName,nameSpaceURI).isNull();
		}
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* Tests, whether 'this' contains any text child nodes
	*
	* @return bool: true, if there are one or more text child nodes in 'this'
	*/

	bool KElement::HasChildText()const{
		return HasChildNodes(TEXT_NODE);
	};
	//////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////
	/**
	* Shorthand to get a deep child, that matches defined name and nameSpace
	* 
	* @param WString & nodeName: the name of the child to search
	* @param WString & nameSpaceURI: nameSpace to look in
	* @param int iSkip: number of matching child nodes to skip 
	* @return KElement: the found child element
	* @deprecated uses GetChildByTagName(...) instead
	*/

	KElement KElement::GetDeepElement(const WString &nodeName,const WString& nameSpaceURI, int iSkip) const{
		return  GetChildByTagName(nodeName, nameSpaceURI, iSkip,MapWString::emptyMap,false);
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the root element of the document
	*
	* @return KElement: the root element of the document
	*/

	KElement KElement::GetDocRoot()const
	{
		if (throwNull())
		{
			return DefKElement;
		}
		else
		{
			return domElement->getOwnerDocument()->getDocumentElement();
		}
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the root element name of the current document
	*
	* @return WString: the root element name of the current document
	*/

	WString KElement::GetDocRootName()const{
		return GetDocRoot().GetNodeName();
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* Shorthand for lazy people. Uses isNull
	* Checks, whether 'this' is null or not. 
	*
	* @return bool: true, if 'this' is a null element
	*/

	bool KElement::operator !()const{
		return isNull();
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* Gets an integer attribute value out of an element
	* or default value if the attribute does not exist. <br>
	* Note, that GetIntAttribute calls the virtual function @see GetAttribute
	*
	* @param WString & attrib: attribute to parse for an integer attribute value 
	* @param WString & nameSpaceURI: nameSpaceURI to search in
	* @param int def: the default to be returned if attrib does not exist
	* @return int: the parsed int attribute value. If the attribute was not found int def is returned
	*/

	int KElement::GetIntAttribute(const WString & attrib, const WString & nameSpaceURI, int def) const {
		WString s=GetAttribute(attrib,nameSpaceURI);
		if(s.empty()) 
			return def;
		return (int) s;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Gets a boolean attribute value out of an element
	* or default value if the attribute does not exist. <br>
	* Note that GetBoolAttribute calls the virtual function @see GetAttribute
	*
	* @param WString & attrib: attribute to parse for a boolean value
	* @param WString & nameSpaceURI: nameSpaceURI to search in
	* @param bool def: the default to be returned if attrib does not exist
	* @return bool: the parsed boolean attribute value. If the attribute was not found bool def is returned
	*/

	bool KElement::GetBoolAttribute(const WString & attrib, const WString & nameSpaceURI, bool def) const {
		WString s=GetAttribute(attrib,nameSpaceURI);
		if(s.empty()) 
			return def;
		return s.compareToIgnoreCase(L"true")==0;
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Gets a double attribute value out of an element
	* or default value if the attribute does not exist. <br>
	* Note that GetRealAttribute calls the virtual function @see GetAttribute
	*
	* @param WString & attrib: attribute to parse for a double value
	* @param WString & nameSpaceURI: nameSpaceURI to search in
	* @param double def: the default to be returned if attrib does not exist
	* @return double: the parsed double attribute value. If the attribute was not found double def is returned
	*/

	double KElement::GetRealAttribute(const WString & attrib, const WString & nameSpaceURI,double def)const{
		WString s=GetAttribute(attrib,nameSpaceURI);
		if(s.empty()) 
			return def;
		return (double) s;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Writes a character representation of 'this' to a string <br> 
	* Always assumes utf-8 encoding
	*
	* @param WString& out : string to write to
	* @return bool: true if successful
	* 
	*/

	bool KElement::Write2String(WString& out)const{
		MemBufFormatTarget *formTarget = new MemBufFormatTarget();
		bool bRet=XMLDoc::Write2FormatTarget(formTarget,domElement);
		out.SetUTF8Bytes((const char*)formTarget->getRawBuffer());
		delete formTarget;
		return bRet;
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Returns a  character representation of 'this' <br> Writes to a string <br>
	* Always assumes utf-8 encoding
	*
	* @return WString: the string
	*/

	WString KElement::ToString()const{
		if(throwNull())
			return L"##null Element##\n";
		WString s;
		Write2String(s);
		return s;
	}

	/**
	* remove all empty attributes from this (e.g. att="")
	* @param bRecurse if true, alse recurse subelements, else only local
	*/
	void KElement::eraseEmptyAttributes(bool bRecurse)
	{
		DOMNamedNodeMap* nm=domElement->getAttributes();
		int siz=(nm==0)?0:nm->getLength(); 

		for (int i = siz - 1; i >= 0; i--)
		{
			DOMNode* item=nm->item(i);
			if ( WString::emptyStr.equals(item->getNodeValue()) )
			{
				RemoveAttribute(item->getNodeName());
			}
		}
		if (bRecurse)
		{
			KElement e=GetFirstChildElement();
			while ( !e.isNull() )
			{
				e.eraseEmptyAttributes(true);
				e=e.GetNextSiblingElement();
			}
		}
	}

	/**
	* check whether this matches a simple xpath
	* @param path
	* @return
	*/
	bool KElement::matchesPath(const WString& path, bool bFollowRefs)
	{
		// bFollowRefs only needed in the JDFElement version
		if ( path.empty() )
		{
			return true;
		}
		//if(bFollowRefs)
		//	this.getClass(); //	dummy to fool compiler

		vWString v = path.Tokenize("/");
		KElement e = *this;

		for (int i = v.size() - 1; i >= 0; i--)
		{
			if(e.isNull())
				return false;

			if (!e.GetLocalName().equals(v.stringAt(i)))
				return false;

			e = e.GetParentNode();
		}

		if (path.startsWith("/"))
			return e.isNull(); // must be root

		return true; // any location
	}

	int KElement::getNumChildNodes(int nodeType)
	{
		int n = 0;

		DOMNodeList* nodeList = domElement->getChildNodes();
		for (int i = 0; i < nodeList->getLength(); i++)
		{
			if ((nodeList->item(i))->getNodeType() == nodeType)
			{
				n++;
			}
		}

		return n;
	}

	//////////////////////////////////////////////////////////////////////

	/**
	* fills a HashSet with all values of the attribute in all child elements
	* @param attName attribute name
	* @param attNS attrib ute namespaceuri
	* @param preFill the HashSet to fill
	*/
	void KElement::fillHashSet(const WString& attName,const WString& attNS, SetWString* preFill)const
	{
		WString attVal=GetAttribute(attName,attNS);
		if(!attVal.empty()) 
		{
			if (preFill->contains(attVal))
				return; // been here already: break
			preFill->add(attVal);
		}

		// get all subnodes, INCLUDING partition leaves
		vElement v=KElement::GetChildElementVector();
		int siz=v.size();
		for(int i=0;i<siz;i++)
		{
			v.at(i).fillHashSet(attName,attNS,preFill);
		}

		// also get all lower level parent partition refs
		v=GetChildElementVector();
		siz=v.size();
		for(int i=0;i<siz;i++)
		{
			v.at(i).fillHashSet(attName,attNS,preFill);
		}
	}

	//////////////////////////////////////////////////////////////////////

	void KElement::setXSIType(const JDF::WString &typ)
	{
		SetAttribute(atr_xsiType, typ, atr_xsiURI);
	}

	//////////////////////////////////////////////////////////////////////

	WString KElement::getXSIType()
	{
		return GetAttribute(atr_xsiType,atr_xsiURI);
	}

	//////////////////////////////////////////////////////////////////////

	/** overload << for KElement
	*/
	std::ostream& operator<<(std::ostream& target, const KElement& toWrite) {
		return target<<toWrite.ToString();
	}	

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

} // namespace JDF

