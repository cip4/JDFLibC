#ifndef _KELEMENT_H_
#define _KELEMENT_H_

/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2014 The International Cooperation for the Integration of 
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
//
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 04 oct 2000
// 041000 RP JDFElement -> KElement : 
// 270301 RP Added RenameAttribute
// 080102 RP added GetChildrenFromList
// 090102 RP added RemoveFromAttribute
// 230102 RP removed JDF specific check from MergeNode and renamed it to MergeElement. 
//			The original MergeNode routine is now in JDFNode
// 230102 RP added text node manipulation routines GetText, RemoveText, RemoveChildText, NumChildText
// 020202 RP renamed AppendComment to AppendXMLComment
// 060202 RP Getattribute now returns def when used on a null object
// 060202 RP GetXPathAttribute default / namespaceURI swap bug fixed
// 120202 RP added IsAbstract protected function
// 210302 RP added FitsName
// 300402 RP added bInherit to HasAttribute,
// 300402 RP added def to GetInheritedAttribute()
// 060502 RP made HasAttribute() virtual and call KElement::GetAttribute
// 080502 RP added bInherit to HasAttribute() 
// 220502 RP renamed protected fuction GetDeepElement() to GetDeepElementByID()
// 270502 RP renamed GetElement (not const) to GetCreateElement
// 270502 RP added GetCreateXPathElement()
// 140802 RP DeleteNode(), HasChildNodes(), HasAttributes(): added throwNull check
// 200802 RP clean up DeleteNode
// 300802 RP NumChildElements: inlined FitsName()
// 060902 RP DeleteNode() also gracefully handle previosly deleted nodes (parent=Null)
// 060902 RP AppendElementN() added
// 060902 RP added getters / setters for XML Comments and CData sections
// 060902 RP AppendCDATA, AppendXMLComment etc. now are void (used to return DOM_CDATA...)
// 221002 RP NumAttributes() added
// 051102 RP GetFirstChildElement() added throwNull check
// 061102 RP GetDeepElementByID() added excludeChild
// 291102 RP XMLNSPrefix, XMLNSLocalName added
// 291102 RP GetPrefix, GetLocalName optimized to use XMLNSPrefix, XMLNSLocalName
// 041202 RP major overhaul to use Xerces 2.x -> no more inheritence of DOM_Element
// 130103 RP ReplaceElement now also works for root element
// 130103 RP RenameElement now uses DomDocument::RenameNode
// 180203 RP added GetTree
// 180203 RP CopyElement, RenameElement added optional beforeChild parameter
// 030303 RP added insert element support
// 190503 RP added GetTreeElement
// 070703 RP added xmlns static strings
// 070703 RP SetAttribute ccheck for Namespace setting attributes and set them as DOM level 2
// 010903 RP removed NMAX from GetInsertvector - it was never used
// 250903 RP all element and attribute modifying routines now throw exceptions when the element is null
// 040813 RP XPath routines Added support for element index, e.g elem[3] is the third child element
// 260804 RP GetDOMAttr new private routine
// 260804 RP GetAttribute, RemoveAttribute, HasAttribute now also retrieve attributes using the local namespace prefix when called in DOM level 1 mode
// 140205 RP AppendElement, SetAttribute now heuristically determine the namespace URI and attempt to call the appropriate dom lvl 2 routine when called in lvl 1 mode
// 040806 NB fixed ReplaceElement, return values were mixed up
// 040680 NB added GetPreviousSiblingElement, eraseEmptyAttributes, matchesPath
// 070806 NB fixed GetDeepChild()
// 080806 NB added getNumChildNodes()
// 240806 NB fixed GetDomAttr()
// 280806 NB fixed SetAttribute()
// 301006 NB changed GetElement(...) to handle negative iSkip's
// 301006 NB fixed maxSize being ignored in GetChildrenByTagName()
// 271106 NB added parameter bInherit to GetDOMAttr()
// 281106 NB fixed GetChildWithAttribute(), GetDOMElement(), GetDOMAttr()
// 011206 NB added SetXSIType(), GetXSIType()
// 211206 NB moved EnumAttributeType from JDFElement to KElement (allows StringUtil to move to WrapperCore)
// 250107 NB removed unreferenced variables
//
// KElement.h: interface for the KElement class.
// KElement wraps DOMElement and has some stl WString conversion utilities
// Every access to a DOMElement should be wrapped using KElement
//
//
*/

#include <jdf/lang/vWString.h>
#include <jdf/lang/mapWString.h>
#include <jdf/lang/vMapWString.h> /* for wrapper only */
#include <jdf/wrappercore/KElementStrings.h>

XERCES_CPP_NAMESPACE_BEGIN
class DOMElement;
class DOMNode;
class DOMAttr;
XERCES_CPP_NAMESPACE_END


namespace JDF {

	/**
	* string - string stl map that defines key-value pairs for attributes
	*/
	typedef vMapWString vmAttribute; /* for wrapper only */

	/**
	* xml document
	*/
	class XMLDoc;
	class XMLDocUserData;
	class SetWString;
	class JDFResource;
	class JDFElement;

	/**
	* stl vector of KElements.
	* This class is overwritten by vElement, which contains some additional utility functions for vectors of elements
	*/
	class vElement;

	/**
	* KElement wraps DOMElement objects and additionally wraps
	* DOM_String objects with STL wstrings or WStrings
	* It is the first layer around the 3rd party XML DOM-parser, in this case Xerces
	* depending on the value of the @see THROWNULL compiler switch the routines will either
	* gracefully continue on Null objects (the default) or
	* throw a @see JDFException
	*/
	class JDF_WRAPPERCORE_EXPORT KElement: public KElementStrings{
	public:
		static const KElement DefKElement;

	public:
		/**
		* Construction / Destruction
		*/
		//@{

		/**
		* Empty constructor <br>
		* : domElement(0) this.domElement = 0
		*/
		KElement() : domElement(0) { }

		/** 
		* Copy constructor <br>
		* Creates a new KElement object by copying the KElement object 'other'
		*
		* @param KElement & other: KElement object to copy <br>
		* : domElement(other.domElement)  this.domElement = other.domElement
		*/
		KElement(const KElement & other) : domElement(other.domElement) { }

		/** 
		* Conversion copy constructor <br>
		* Converts the DOMElement object 'other' into a KElement object
		*
		* @param DOMElement* other : is the DOMElement object to convert <br>
		* : domElement(other)  this.domElement = other
		*/
		KElement(XERCES_CPP_NAMESPACE_QUALIFIER DOMElement* other) : domElement(other) { }

		/**
		* Assignment of KElement object 'other' to the current KElement object
		*
		* @param KElement& other: KElement object to assign
		*/
		KElement& operator=(const KElement& other);

		/**
		* Assignment of DOMElement* object 'other' to the current KElement object
		*
		* @param DOMElement* other: DOMElement object to assign
		*/
		KElement& operator=(XERCES_CPP_NAMESPACE_QUALIFIER DOMElement* other);

		/** 
		* Destructor
		*/
		virtual ~KElement() { }
		//@}

		/**
		* Tests whether an argument is a wildcard i.e empty or *  
		*
		* @param JDFCh* nodeName: the argument to test
		* @return bool: true if the name is wildcard
		*/
		inline static bool IsWildcard(const JDFCh* nodeName){
			return (nodeName==0) || ((*nodeName)==0) || ((*nodeName)==L'*'&&!*(nodeName+1));
		}

		static const int ANY_NODE;
		static const int ELEMENT_NODE;
		static const int ATTRIBUTE_NODE;
		static const int TEXT_NODE;
		static const int CDATA_SECTION_NODE;
		static const int ENTITY_REFERENCE_NODE;
		static const int ENTITY_NODE;
		static const int PROCESSING_INSTRUCTION_NODE;
		static const int COMMENT_NODE;
		static const int DOCUMENT_NODE;
		static const int DOCUMENT_TYPE_NODE;
		static const int DOCUMENT_FRAGMENT_NODE;
		static const int NOTATION_NODE;
		//		static const int XML_DECL_NODE;

		/**
		* Returns the internal DOMElement pointer <br>
		* ATTENTION, use with care. No guarantee for internal consistency is given when modifying the DOMDocument
		*
		* @return DOMElement* : the internal DOMElement pointer
		*/
		XERCES_CPP_NAMESPACE_QUALIFIER DOMElement* GetDOMElement()const;

		/**
		* Gets the qualified name of 'this'
		*
		* @return WString: the qualified name of the node; #null if it is null
		*/
		WString GetNodeName()const;

		/**
		* Gets the value of 'this'
		*
		* @return WString: the value of the node; #null if it is null
		*/
		WString GetNodeValue()const;

		/**
		* Gets the parent node of 'this'
		*
		* @return KElement:the parent node of this
		*/	
		KElement GetParentNode()const;

		/**
		* Mother of all Attribute setters <br>
		* Adds a new attribute or modifies an existing attribute. 
		* If an attribute with that name is already present in
		* the element, its value is changed to be that of the value parameter. This
		* value is a simple string; it is not parsed as it is being set. So any
		* markup (such as syntax to be recognized as an entity reference) is treated
		* as literal text, and needs to be appropriately escaped by the
		* implementation when it is written out. 
		*
		* @param WString & key: the qualified name of the attribute to create or alter.
		* @param WString & value: the value to set in string form.
		* @param WString & nameSpaceURI: the namespace the element is in
		* 
		* @throws JDFException if 'this' is a null element and the settings of its attributes are impossible
		* @throws JDFException if different namespace uri are used for the same namespace prefix within one element 
		*/
		void SetAttribute(const WString & key, const WString & value, const WString & nameSpaceURI=WString::emptyStr);

		/**
		* Sets an element attribute of type unsigned int
		*
		* @param WString & key: the qualified name of the attribute to set
		* @param unsigned int value: the value for the attribute of type unsigned int 
		* @param WString & nameSpaceURI: the namespace the element is in
		* 
		* @throws JDFException if 'this' is a null element and the settings of its attributes are impossible
		*/
		inline void SetAttribute(const WString & key, const unsigned int value, const WString & nameSpaceURI=WString::emptyStr){
			SetAttribute(key,WString::valueOf(value),nameSpaceURI);
		}

		/**
		* Sets an element attribute of type int
		*
		* @param WString & key: the qualified name of the attribute to set
		* @param int value: the value for the attribute of type int
		* @param WString & nameSpaceURI: the namespace the element is in
		* 
		* @throws JDFException if 'this' is a null element and the settings of its attributes are impossible
		*/
		inline void SetAttribute(const WString & key, const int value, const WString & nameSpaceURI=WString::emptyStr){
			SetAttribute(key,WString::valueOf(value),nameSpaceURI);
		}


		/**
		* Sets an element attribute of type double
		*
		* @param WString & key: the qualified name of the attribute to set
		* @param double value: the value for the attribute of type double 
		* @param WString & nameSpaceURI: the namespace the element is in
		* 
		* @throws JDFException if 'this' is a null element and the settings of its attributes are impossible
		*/
		inline void SetAttribute(const WString & key, const double value, const WString & nameSpaceURI=WString::emptyStr){
			SetAttribute(key,WString::valueOf(value),nameSpaceURI);
		}

		/**
		* Sets an element attribute of type bool
		*
		* @param WString & key: the qualified name of the attribute to set
		* @param boolean b: the value for the boolean attribute (true or false)
		* @param WString & nameSpaceURI: the namespace the element is in
		* 
		* @throws JDFException if 'this' is a null element and the settings of its attributes are impossible
		*/
		inline void SetAttribute(const WString & key, const bool b, const WString & nameSpaceURI=WString::emptyStr){
			SetAttribute(key,b?WString(L"true"):WString(L"false"),nameSpaceURI);
		}

		/**
		* Sets an element attribute of type char* 
		*
		* @param WString & key: the qualified name of the attribute to set
		* @param char* value: the value for the attribute of type char* 
		* @param WString & nameSpaceURI: the namespace the element is in
		* 
		* @throws JDFException if 'this' is a null element and the settings of its attributes are impossible
		*/
		inline void SetAttribute(const WString & key, const char* value, const WString & nameSpaceURI=WString::emptyStr){
			SetAttribute(key,WString(value),nameSpaceURI);
		}

		/**
		* Sets an element attribute of type wchar_t* 
		*
		* @param WString &  key: the qualified name of the attribute to set
		* @param wchar_t* value: the value for the attribute of type wchar_t* 
		* @param WString & nameSpaceURI: the namespace the element is in
		* 
		* @throws JDFException if 'this' is a null element and the settings of its attributes are impossible
		*/		
		inline void SetAttribute(const WString & key, const wchar_t* value, const WString & nameSpaceURI=WString::emptyStr){
			SetAttribute(key,WString(value),nameSpaceURI);
		}


		/**
		* Sets the attributes of 'this'. <br> 
		* If the Attributes map is empty, zero is returned.
		* Otherwise the size of the map is returned
		*
		* @param mAttribute & aMap: map of attributes to set
		* @return int: size of the map or zero if it is empty
		*/		
		int SetAttributes(const mAttribute& aMap);

		/**
		* Sets the attributes of 'this'. <br> 
		* If the Attributes map of the element e is empty, zero is returned.
		* Otherwise the size of the map is returned 
		*
		* @param KElement e : element, that contains attributes to set
		* @return int: size of the map or zero if it is empty
		*/
		int SetAttributes(KElement e);


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
		void AppendAttribute(const WString & key, const WString& value, const WString & nameSpaceURI=WString::emptyStr, const WString & sep=WString::blank, bool bUnique=false);

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
		virtual int RemoveFromAttribute(const WString & key, const WString& value, const WString & nameSpaceURI=WString::emptyStr, const WString & sep=WString::blank, int nMax=-1);

		/**
		* Sets an attribute as defined by XPath to value <br>
		*
		* @tbd enhance the subsets of allowed XPaths, now only .,..,/,@,[n] are supported
		* note that the index in brackets (elem[index]) is 1-based in order to conform with XPath!
		* @param WString & path: XPath abbreviated syntax representation of the attribute, e.g parentElement/thisElement@thisAtt
		* @param WString & value: string to be appended
		*
		* @since 040813 Added support for element index, e.g elem[3] is the third child element
		* @throws JDFException if the defined path is a bad attribute path
		*/
		void SetXPathAttribute(const WString & path, const WString & value);

		/**
		* Gets the XPath full tree representation of 'this'
		*
		* @return WString: the XPath representation of 'this' e.g. /root/parent[2]/element
		* note that the index in brackets (elem[index]) is 1-based in order to conform with XPath!
		* @since 040813 Added support for element index, e.g elem[3] is the third child element
		*/
		WString GetXPath() const;

		/**
		* Adds a NameSpace and maps the prefix to a URI. <br>
		* Checks all parents, whether such namespace is already defined in an ancestor
		*
		* @param WString & prefix: the namespace prefix to set
		* @param WString nameSpaceURI: the namespace URI to set
		* @return bool: true if newly set, false if already there and matching
		*/
		bool AddNameSpace(const WString & prefix, const WString nameSpaceURI);

		/**
		* Mother of all attribute getters <br>
		* Gets an attribute value out of an element
		*
		* @param WString & attrib: the name of the attribute you wanna have
		* @param WString & nameSpaceURI: namespace of attribute key
		* @param WString & def: the value that is returned if attrib does not exist in 'this' or 'this' is null
		* @return WString: the attribute value as a string, or def if that attribute does not have a specified or default value
		*/
		virtual WString GetAttribute(const WString & attrib, const WString & nameSpaceURI=WString::emptyStr,const WString & def=WString::emptyStr ) const ;

		/**
		* Gets of 'this' an attribute map - key-value pairs of all attributes
		*
		* @return mAttribute: a map of all key-value pairs in 'this'
		*/
		mAttribute GetAttributeMap()const;

		/**
		* Gets of 'this' all attribute keys as a vector of strings 
		*
		* @return vWString: a vector of all attribute keys in 'this'
		*/
		virtual vWString GetAttributeVector()const;

		/**
		* Gets of 'this' the number of all attributes 
		*
		* @return int: number of all attributes in 'this'
		*/
		virtual int NumAttributes()const;

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
		int GetIntAttribute(const WString & attrib, const WString & nameSpaceURI=WString::emptyStr, int def=0) const;

		/**
		* Gets a boolean attribute value out of an element
		* or default value if the attribute does not exist. <br>
		* Note, that GetBoolAttribute calls the virtual function @see GetAttribute
		*
		* @param WString & attrib: attribute to parse for a boolean value
		* @param WString & nameSpaceURI: nameSpaceURI to search in
		* @param bool def: the default to be returned if attrib does not exist
		* @return bool: the parsed boolean attribute value. If the attribute was not found bool def is returned
		*/
		bool GetBoolAttribute(const WString & attrib, const WString & nameSpaceURI=WString::emptyStr, bool def=false) const;

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
		double GetRealAttribute(const WString & attrib, const WString & nameSpaceURI=WString::emptyStr,double def=0.0)const;

		/**
		* Gets an attribute as defined by XPath to value namespace prefixes are resolved <br>
		*
		* @tbd enhance the subsets of allowed XPaths, now only .,..,/,@,[n] are supported
		* note that the index in brackets (elem[index]) is 1-based in order to conform with XPath!
		* @param WString & path: XPath abbreviated syntax representation of the attribute, e.g parentElement/thisElement@thisAtt
		* @param WString & def: default value if it doesn't exist
		* @return WString: the String value of the attribute
		*
		* @throws JDFException if the defined path is a bad attribute path
		* @since 040813 Added support for element index, e.g elem[3] is the third child element
		*/
		WString GetXPathAttribute(const WString & path, const WString & def=WString::emptyStr)const;

		/**
		* removes an attribute as defined by XPath to value namespace prefixes are resolved <br>
		*
		* @tbd enhance the subsets of allowed XPaths, now only .,..,/,@,[n] are supported
		* note that the index in brackets (elem[index]) is 1-based in order to conform with XPath!
		* @param WString & path: XPath abbreviated syntax representation of the attribute, e.g parentElement/thisElement@thisAtt
		*
		* @throws JDFException if the defined path is a bad attribute path
		* @since 040813 Added support for element index, e.g elem[3] is the third child element
		*/
		void RemoveXPathAttribute(const WString & path);

		/**
		* Removes an attribute from 'this'
		*
		* @param WString & attrib: the name of attribute to remove
		* @param WString & nameSpaceURI: the namespace 'this' is in
		*
		* @throws JDFException if 'this' is a null element and its modifying is thus impossible
		*/
		virtual void RemoveAttribute(const WString & attrib, const WString & nameSpaceURI=WString::emptyStr);

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
		virtual void RenameAttribute(const WString & oldName, const WString &newName,  const WString & nameSpaceURI=WString::emptyStr,const WString & newNameSpaceURI=WString::emptyStr);

		/**
		* Removes all attributes in all namespaces of 'this'
		*
		* @attrib vWString list of attributes to remove, if empty, remove all
		* @throws JDFException if 'this' is a null element and its modifying is thus impossible
		*/
		void RemoveAttributes(const vWString& attribs=vWString::emptyvStr);

		/**
		* Checks, if 'this' has a specific attribute <br>
		* This version checks within the exact xml element
		*
		* @param WString & attrib: the name of the attribute to look for
		* @param WString & nameSpaceURI: the nameSpace to look in
		* @param bool bInherit: if true also checks recursively in parent elements
		* @return bool: true, if the attribute is present
		*/
		virtual bool HasAttribute(const WString & attrib, const WString & nameSpaceURI=WString::emptyStr, bool bInherit=false) const;

		/**
		* Tests whether the attributes described by aMap exist
		*
		* @param mAttribute & aMap: map of key-value pairs. any values of "*" are treated as true when the atrribute exists, regardless of value <br>
		* @tbd allow for regular expressions in values
		* @param bool bAnd: if true, all conditions described in aMap must be true (boolean and), if false any condition must match (boolean or).
		* @return bool: true, if bAnd=true and all the attributes described by aMap are present,
		* or if bAnd=false and one or more of the attributes described by aMap are present
		*/
		bool IncludesAttributes(const mAttribute& aMap,bool bAnd=true)const;

		/**
		* Tests whether an attribute with the proper key-value pair exists
		*
		* @param WString & attName: the name of the attribute to look for
		* @param WString & attVal: the value of the attribute to look for;
		* a value of "*" is treated as true when the atrribute exists, regardless of its value <br>
		* @tbd allow for regular expressions in attVal
		* @return bool: true, if the attribute with the proper key-value pair exists
		*/
		bool IncludesAttribute(const WString & attName, const WString & attVal=WString::star)const;

		/**
		* Checks if 'this' has attributes or not
		*
		* @return bool: true, if 'this' has any attributes
		*/
		bool HasAttributes()const;

		/**
		* Gets a list of all direct child element names of 'this'
		*
		* @param bool bLocal: if true, gets the local names, else the qualified names
		* @return vWString: vector of strings, that contains a list of all direct child element names
		* @tbd namespace handling
		*/
		virtual vWString GetElementNameVector(bool bLocal=false)const;

		/**
		* Checks, if in 'this' are any missing attributes
		*
		* @return bool: true, if one or more attributes are missing 
		*/
		bool HasMissingAttributes()const;

		/**
		* Gets a vector of attribute keys, that are missing in 'this'
		*
		* @param int nMax: maximum size of the returned vector
		* @return vWString: vector of strings, that contains missing attribute keys
		*/
		virtual vWString GetMissingAttributes(int nMax=99999999)const;

		/**
		* Checks, if in 'this' are any unknown attributes
		*
		* @param bool bIgnorePrivate: if true, looks only in default and JDF namespaces
		* @return bool: true, if one or more attributes are unknown
		*/
		bool HasUnknownAttributes(bool bIgnorePrivate)const;

		/**
		* Gets a vector of attribute keys that exist but are unknown by 'this'
		*
		* @param bool bIgnorePrivate: if true, looks only in default and JDF namespaces
		* @param int nMax: maximum size of the returned vector
		* @return vWString: vector of strings, that contains unknown attribute keys
		* @tbd clean up namespace handling
		*/

		virtual vWString GetUnknownAttributes(bool bIgnorePrivate,int nMax=99999999)const;

		/**
		* Tests, whether 'this' has any missing direct child elements
		*
		* @return bool: true, if one or more direct child elements are missing
		*/
		bool HasMissingElements()const;

		/**
		* Gets a vector of direct child element names, that are missing in 'this'
		*
		* @param int nMax: maximum size of the returned vector
		* @return vWString: vector of strings, that contains missing element names
		*/
		virtual vWString GetMissingElements(int nMax=99999999)const;

		/**
		* Tests, whether 'this' has any unknown direct child elements
		*
		* @param bool bIgnorePrivate: if true, only looks in default and JDF namespaces
		* @return bool: true, if direct child elements exist but are unknown in 'this'
		*/
		bool HasUnknownElements(bool bIgnorePrivate)const;

		/**
		* Gets a vector of direct child element names, that exist but are unknown in 'this'
		*
		* @param bool bIgnorePrivate: if true, only looks in default and JDF namespaces
		* @param int nMax: maximum size of the returned vector
		* @return vWString: vector of strings, that contains unknown element names
		*/
		virtual vWString GetUnknownElements(bool bIgnorePrivate,int nMax=99999999)const;

		/**
		* Tests, whether 'this' contains direct child element names, that may be legally inserted in it ones more 
		*
		* @return bool: true, if direct child element names may be inserted ones more
		*/
		bool HasInsertElements()const;

		/**
		* Gets a vector of direct child element names, that may be legally inserted into 'this'
		*
		* @return vWString: vector of strings, that contains insertable element names
		*/
		virtual vWString GetInsertElements()const;

		/**
		* Copies an attribute from src to 'this'
		*
		* @param WString & attrib: the name of the attribute
		* @param KElement & src: source element, where the attribute to be copied resides
		* @param WString & srcAttrib: name of the attribute in the source, defaults to the value of attrib
		* @param WString & nameSpaceURI: nameSpace of the attribute in the destination
		* @param WString & srcNameSpaceURI: nameSpace of the attribute in the source, defaults to the value of nameSpaceURI
		*/
		void CopyAttribute(const WString & attrib, const KElement & src, const WString & srcAttrib=WString::emptyStr,const WString & nameSpaceURI=WString::emptyStr, const WString & srcNameSpaceURI=WString::emptyStr);

		/**
		* Moves an attribute from src to 'this'
		*
		* @param WString & attrib: the name of the attribute
		* @param KElement & src: source element, where the attribute to be moved resides
		* @param WString & srcAttrib: name of the attribute in the source, defaults to the value of attrib
		* @param WString & nameSpaceURI: nameSpace of the attribute in the destination
		* @param WString & srcNameSpaceURI: nameSpace of the attribute in the source, defaults to the value of nameSpaceURI
		*/
		void MoveAttribute(const WString & attrib, KElement& src, const WString & srcAttrib=WString::emptyStr,const WString & nameSpaceURI=WString::emptyStr, const WString & srcNameSpaceURI=WString::emptyStr);

		/**
		* Child manipulation routines
		*/
		//@{
		/**
		* Gets a list of all values of the attribute attName in the children of this node
		*
		* @param WString & nodeName: element name you are searching for
		* @param WString & attName: attributes you are looking for
		* @param WString & nameSpaceURI: nameSpace you are searching for
		* @param WString & attVal: value of the attribute you are searching for
		* @param bool bDirect: if true, looks only in direct children, else searches through all children, grandchildren etc.
		* @param bool bUnique: if you want to make sure, the attribute is unique, set
		* this boolean to true. Otherwise attribute attName is added to the returned
		* @return vWString: vector of strings, that contains values of the attribute attName
		*/
		vWString GetChildAttributeList(const WString & nodeName, const WString & attName, const WString & nameSpaceURI=WString::emptyStr,const WString & attVal=WString::star,bool bDirect=true, bool bUnique=true)const;

		/**
		* Gets a list of all values of the attribute attName in the children of this node
		*
		* @param WString & nodeName: element name you are searching for
		* @param WString & attName: attributes you are looking for
		* @param WString & nameSpaceURI: nameSpace you are searching for
		* @param WString & attVal: value of the attribute you are searching for
		* @param bool bDirect: if true, looks only in direct children, else searches through all children, grandchildren etc.
		* @param SetWString* the set to fill
		*/
		void getChildAttributeSet(SetWString*sSet,const WString & nodeName, const WString & attName,  const WString & nameSpaceURI=WString::emptyStr,const WString & attVal=WString::star,bool bDirect=true)const;

		/**
		* Gets a vector of all children with a matching attribute
		*
		* @param WString & nodeName: elementname you are searching for
		* @param WString & attName: attributes you are looking for
		* @param WString & nameSpaceURI: nameSpace you are searching for
		* @param WString & attVal: value of the attribute you are searching for
		* @param bool bDirect: if true, looks only in direct children, else searches through all children, grandchildren etc.
		* @return vElement: vector with all found elements
		*/	
		vElement GetChildrenWithAttribute(const WString & nodeName, const WString & attName, const WString & nameSpaceURI=WString::emptyStr, const WString & attVal=WString::star, bool bDirect=true)const;

		/**
		* Gets of 'this' a child with a matching attribute
		*
		* @param WString & nodeName: name of the child node to search for
		* @param WString & attName: attribute name to search for
		* @param WString & nameSpaceURI: namespace to search for
		* @param WString & attVal: a special value to search for
		* @param int index: if more then one child meets the condition, you can specify the one to return via an index
		* @param bool bDirect: if true, looks only in direct children, else searches through all children, grandchildren etc.
		* @return KElement: the child element, which matches the above conditions
		*/
		KElement GetChildWithAttribute(const WString & nodeName,const WString & attName, const WString & nameSpaceURI=WString::emptyStr, const WString &attVal=WString::star, int index=0, bool bDirect=true)const;

		/**
		* Gets an existing iSkip-th child node with matching nodeName and nameSpaceURI
		*
		* @param WString & nodeName: name of the child node to get
		* @param WString & nameSpaceURI: namespace to search for
		* @param int iSkip: number of matching child nodes to skip
		* @return KElement: the matching child element
		*/
		virtual KElement GetElement(const WString& nodeName, const WString & nameSpaceURI=WString::emptyStr,int iSkip=0)const;


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
		virtual KElement GetCreateElement(const WString& nodeName, const WString & nameSpaceURI=WString::emptyStr, int iSkip=0);

		/**
		* Gets an element as defined by XPath to value <br>
		*
		* @tbd enhance the subsets of allowed XPaths, now only .,..,/,@,,[n] are supported
		* note that the index in brackets (elem[index]) is 1-based in order to conform with XPath!
		* @param WString & path: XPath abbreviated syntax representation of the attribute, e.g parentElement/thisElement@thisAtt
		* @return KElement: the specified element
		* @since 040813 Added support for element index, e.g elem[3] is the third child element
		*/
		KElement GetXPathElement(const WString & path)const;

		vElement GetXPathElementVector(const WString & pathIn, int maxSize)const;
		/**
		* Gets an element as defined by XPath to value and creates it if it does not exist <br>
		*
		* @tbd enhance the subsets of allowed XPaths, now only .,..,/,@,,[n] are supported
		* note that the index in brackets (elem[index]) is 1-based in order to conform with XPath!
		* @param WString & path: XPath abbreviated syntax representation of the attribute, e.g parentElement/thisElement@thisAtt
		* @return KElement: the specified element
		* @throws JDFException if the root node name is not identical to the root node name of the XPath
		* @since 040813 Added support for element index, e.g elem[3] is the third child element
		* @since 040813 modified behavior of absolute xpaths (starting with a "/e..." to throw an exception if the root node name is not identical 
		* to the root node name of the XPath
		*/
		KElement GetCreateXPathElement(const WString & path);

		/**
		* Removes children, that match nodeName and nameSpaceURI
		*
		* @param WString & nodeName: name of the child node to remove, if empty or "*" removes all
		* @param WString & nameSpaceURI: namespace to search for
		*
		* @throws JDFException if 'this' is a null element and its modifying is thus impossible
		*/
		virtual void RemoveChildren(const WString& nodeName=WString::emptyStr,const WString & nameSpaceURI=WString::emptyStr);

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
		virtual KElement RemoveChild(const WString & nodeName,const WString & nameSpaceURI=WString::emptyStr,unsigned int n=0);

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
		vElement GetChildrenByTagName(const WString & s, const WString & nameSpaceURI=WString::emptyStr, const mAttribute & mAttrib=mAttribute::emptyMap,bool bDirect=true, bool bAnd=true, unsigned int maxSize=0)const;

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
		KElement GetChildByTagName(const WString & s, const WString & nameSpaceURI=WString::emptyStr, int index=0, const mAttribute&mAttrib=mAttribute::emptyMap,bool bDirect=true, bool bAnd=true)const;

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
		KElement GetTreeElement(const WString & nodeName, const WString & nameSpaceURI=WString::emptyStr, const mAttribute & mAttrib=mAttribute::emptyMap,bool bDirect=false, bool bAnd=true)const;

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
		vElement GetTree(const WString & nodeName, const WString & nameSpaceURI=WString::emptyStr, const mAttribute & mAttrib=mAttribute::emptyMap,bool bDirect=false, bool bAnd=true)const;

		/**
		* Gets the iSkip-th child, whose localname matches a string defined in nodeNames 
		*
		* @param vWString & nodeNames: list of node names that fit
		* @param int iSkip: number of matching child nodes to skip
		* @return KElement: the found child element
		*/
		KElement GetChildFromList(const vWString& nodeNames, int iSkip=0)const;

		/**
		* Gets a vector of all children, whose localnames match the string defined in nodeNames
		*
		* @param vWString & nodeNames: list of node names that fit
		* @return vElement: the found child elements
		*/
	vElement GetChildrenFromList(const vWString& nodeNames,const JDFAttributeMap& map=JDFAttributeMap::emptyMap, bool bDirect=true)const;
		//@}

		/*
		//
		// Functions for validating JDF documents
		//
		*/
		//@{
		/**
		* Comma separated list of all required attributes. KElement is generic, therefore the list is empty
		*
		* @return WString: the comma separated list of required attribute keys
		*/
		virtual WString RequiredAttributes()const;

		/**
		* Comma separated list of all optional attributes. 
		* KElement is generic, therefore only the XML generic attributes are listed <br>
		* xmlns: the namespace declaration
		*
		* @return WString: the comma separated list of optional attribute keys
		*/
		virtual WString OptionalAttributes()const;

		/**
		* Comma separated list of all required + optional attributes.
		* KElement is generic, therefore the list is empty 
		*
		* @return WString: the comma separated list of known attribute keys
		*/
		WString KnownAttributes()const;

		/**
		* Comma separated list of all unique element names that may occur at most once; 
		* KElement is generic, therefore the list is empty
		*
		* @return WString: the comma separated list of unique element names
		*/
		virtual WString UniqueElements()const;

		/**
		* Comma separated list of all required element names; KElement is generic, therefore the list is empty
		*
		* @return WString: the comma separated list of required element names
		*/
		virtual WString RequiredElements()const;

		/**
		* Comma separated list of all optional element names; KElement is generic, therefore the list is empty
		*
		* @return WString: the comma separated list of optional element names
		*/
		virtual WString OptionalElements()const;

		/**
		* Comma separated list of all known element names; KElement is generic, therefore the list is empty
		*
		* @return WString: the comma separated list of known element names
		*/
		WString KnownElements()const;
		//@}

		/**
		* Gets the number of child elements with matching nodeName and nameSpace. <br>
		* If nodeName is an empty string or *, all element nodes are counted.
		*
		* @param WString & nodeName: NodeName of nodes to count 
		* @param WString & nameSpaceURI: the nameSpace to look in
		* @return int: the number of matching child elements
		*/
		virtual int NumChildElements(const WString & nodeName=WString::emptyStr,const WString & nameSpaceURI=WString::emptyStr)const;

		/**
		* Gets the first child element of 'this'
		*
		* @return KElement: the first chid element of 'this'
		*/
		KElement GetFirstChildElement()const;

		/**
		* Gets the next sibling element of 'this'
		*
		* @return KElement: the next sibling element of 'this'
		*/
		KElement GetNextSiblingElement()const;

		/**
		* Gets the next sibling element of 'this'
		*
		* @param nodeName the nodename of the desired element
		* @return KElement: the next sibling element of 'this'
		*/
		KElement GetNextSiblingElement(const WString& nodeName, const WString& nameSpaceURI)const;

		/**
		* Gets the previous sibling element of 'this'
		*
		* @return KElement: the previous sibling element of 'this'
		*/
		KElement GetPreviousSiblingElement()const;

		/**
		* Checks, if 'this' has child element nodes
		*
		* @return bool: true, if 'this' has one or more child element nodes 
		*/
		bool HasChildElements()const;

		/**
		* Checks, if 'this' has a child with matching NodeName and nameSpace
		*
		* @param WString & NodeName: child NodeName to search for
		* @param WString & nameSpaceURI: the nameSpace to look for
		* @param bool bInherit: if true also checks recursively in parent elements 
		* @return bool: true, if the child with matching NodeName and nameSpace was found in 'this' 
		*/
		bool HasChildElement(const WString & NodeName,const WString & nameSpaceURI=WString::emptyStr, bool bInherit=false)const;

		/**
		* Gets of 'this' all child elements, matching the given conditions
		*
		* @param WString & element: node name you are searching for
		* @param WString & nameSpaceURI: nameSpace you are searching in
		* @param Attributes & mAttrib: map of attributes you are looking for.
		* @param bool bAnd: if true, a child is only added if it includes all attributes, specified in mAttrib
		* @param unsigned int maxSize: maximum size of the element vector
		* @param bool bResolveTarget: if true, IDRef elements are followed, dummy at this level but needed in JDFElement
		* @return vElement: vector with all found elements
		*/
		virtual vElement GetChildElementVector(const WString & element=WString::star, const WString & nameSpaceURI=WString::emptyStr, const mAttribute& mAttrib=mAttribute::emptyMap, bool bAnd=true, unsigned int maxSize=0, bool bResolveTarget=false)const;

		/**
		* Checks, if 'this' is an ancestor of child or not. <br>
		* Recursively checks child parents, parent's parents, etc. 
		*
		* @param KElement child: child to check 
		* @return bool: true, if 'this' is an ancestor
		*/
		bool IsAncestor(KElement child)const;

		/*
		//
		// text element manipulation
		///
		*/
		//@{
		/**
		* Tests, whether 'this' contains any text child nodes
		*
		* @return bool: true, if there are one or more text child nodes in 'this'
		*/
		bool HasChildText()const;

		/**
		* Gets the i-th text child node of 'this'
		*
		* @param int i: index of the child text node, you are searching for. First node has index 0, second - 1, etc.
		* @return WString: text - the value of the text node
		*/
		WString GetChildText(int i=0)const;

		/**
		* Gets of 'this' the concatenated string representing all direct text child nodes
		*
		* @return WString: the concatenated string of values of all direct text child nodes
		*/
		WString GetText()const;

		/**
		* Removes all direct text child nodes of 'this' 
		*/
		void RemoveText();

		/** 
		* Appends an XML Text <br>
		* Appends a new text child node to the end of 'this' 
		*
		* @param WString & text: XML Text to append 
		*
		* @throws JDFException if 'this' is a null element and thus nothing can be inserted in it 
		*/
		void AppendText(const WString & text);

		/** 
		* Sets an XML Text <br>
		* the text contents of this to the value of text 
		*
		* @param WString & text: XML Text to set 
		*
		* @throws JDFException if 'this' is a null element and thus nothing can be inserted in it 
		*/
		void SetText(const WString & text);

		/**
		* Removes the i-th text node of 'this'
		*
		* @param int i: index of the text node to remove. First node has index 0, second - 1, etc.
		*/
		void RemoveChildText(int i=0);

		/**
		* Gets the number of direct text child nodes in 'this' 
		*
		* @return int: the number of direct text child nodes in 'this'
		*/
		int NumChildText()const;
		//@}

		/* 
		*
		* Insert new elements
		*/

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
		* For example, if beforePos=1, new element Element2 will be inserted before second occurrence of Element1<br><br>
		* <table cellSpacing=5 width="100%" border=1>
		* <TR bgColor=#708090>
		*    <TD vAlign=center align=middle><I><B>Position</I></B></TD>
		*    <TD vAlign=center align=middle><I><B>Initial consequence of nodes before InsertAt</I></B></TD>
		*    <TD vAlign=center align=middle><I><B>Position</I></B></TD>
		*    <TD vAlign=center align=middle><I><B>Consequence of nodes after InsertAt</I></B></TD>
		* </TR>
		* <TR bgColor=#d3d3d3>
		*    <TD vAlign=center align=middle>index=0<br> first occurrence</TD>
		*    <TD vAlign=center align=middle><B>1-st Node Element1</B><br> (Name=beforeNode, NameSpace=beforeNameSpaceURI)</TD>
		*    <TD vAlign=center align=middle>index=0<br> first occurrence</TD>
		*    <TD vAlign=center align=middle><B>1-st Node Element1</B><br> (Name=beforeNode, NameSpace=beforeNameSpaceURI)</TD>
		* </TR>
		* <TR >
		*    <TD vAlign=center align=middle bgColor=#f5f5f5 >index=1<br> second occurrence </TD>
		*   <TD vAlign=center align=middle bgColor=#d3d3d3><B>2-nd Node Element1</B><br> (Name=beforeNode, NameSpace=beforeNameSpaceURI)</TD>
		*    <TD vAlign=center align=middle bgColor=#f5f5f5 >beforePos=1</TD>
		*    <TD vAlign=center align=middle bgColor=#f5f5f5 ><B>New Element2</B><br> (Name=nodeName, NameSpace=NameSpaceURI)</TD>
		* </TR>
		* <TR bgColor=#d3d3d3>
		*    <TD vAlign=center align=middle>index=2<br>  third occurrence</TD>
		*    <TD vAlign=center align=middle><B>3-d Node Element1</B><br> (Name=beforeNode, NameSpace=beforeNameSpaceURI)</TD>
		*    <TD vAlign=center align=middle bgColor=#f5f5f5 >index=1<br>  second occurrence </TD>
		*    <TD vAlign=center align=middle><B>2-nd Node Element1</B><br> (Name=beforeNode, NameSpace=beforeNameSpaceURI)</TD>
		* </TR>
		* <TR bgColor=#d3d3d3>
		*    <TD vAlign=center align=middle>&nbsp;</TD>
		*    <TD vAlign=center align=middle>&nbsp;</TD>
		*    <TD vAlign=center align=middle>index=2<br> third occurrence</TD>
		*    <TD vAlign=center align=middle><B>3-d Node Element1</B><br> (Name=beforeNode, NameSpace=beforeNameSpaceURI)</TD>
		* </TR>
		*</table>
		*
		* @throws JDFException if 'this' is a null element and thus nothing can be inserted in it
		*/
		KElement InsertAt(const WString & nodeName, int beforePos, const WString& beforeNode=WString::emptyStr,const WString & nameSpaceURI=WString::emptyStr,const WString & beforeNameSpaceURI=WString::emptyStr);

		/**
		* Appends a new child element to the end of 'this' 
		*
		* @param KElement & element: a new child element to append
		* @return KElement: newly created child element 
		*
		* @throws JDFException if 'this' is a null element and thus appending of elements to it is impossible
		*/
		KElement AppendElement(const KElement & element);

		/**
		* Inserts a new child element in front of child element BeforeChild
		*
		* @param KElement & newChild: a new child element to insert
		* @param KElement & BeforeChild: child node to put it before
		* @return KElement: newly inserted child element 
		*
		* @throws JDFException if 'this' is a null element and thus nothing can be inserted in it
		*/
		KElement InsertBefore(const KElement & newChild, const KElement & BeforeChild);

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
		KElement InsertBefore(const WString & elementName, const KElement & beforeChild, const WString & nameSpaceURI=WString::emptyStr);

		/**
		* Appends a new child element to the end of 'this' 
		*
		* @param WString & elementName: name of the new child element
		* @param WString & nameSpaceURI: nameSpace of the new child element
		* @return KElement: newly created child element 
		*/
		KElement AppendElement(const WString & elementName,const WString & nameSpaceURI=WString::emptyStr);

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
		KElement AppendElementN(const WString & elementName, int maxAllowed, const WString & nameSpaceURI=WString::emptyStr);

		/** 
		* Appends an XML Comment (NOT a JDF comment) <br>
		* Appends a new comment child node to the end of 'this' 
		*
		* @param WString & commentText: the text of the XML Comment to append 
		*
		* @throws JDFException if 'this' is a null element and thus nothing can be appended to it
		*/
		void AppendXMLComment(const WString & commentText=WString::emptyStr);

		/** 
		* Gets of 'this' the text of the i-th XMLComment  
		*
		* @param int i: index of the XMLComment child node, you are searching for. First node has index 0, second - 1, etc.
		* @return WString: text of the i-th XMLComment
		*/
		WString GetXMLComment(int i=0)const;

		/**
		* Removes the i-th XMLComment of 'this' 
		*
		* @param int i: index of the XML comment child node to remove
		*/
		void RemoveXMLComment(int i=0);

		/**
		* Gets the number of direct child XMLComment nodes in 'this' 
		*
		* @return int: the number of direct child XMLComment nodes
		*/
		int NumXMLComments()const;

		/** 
		* Appends XML CData section - some character data <br>
		* Appends a new CData section child node to the end of 'this '
		*
		* @param WString & cDataText: the text of the XML CData section to append
		*
		* @throws JDFException if 'this' is a null element and thus nothing can be appended to it
		*/
		void AppendCData(const WString & cDataText);

		/** 
		* Gets of 'this' the text of the i-th XML CData section 
		*
		* @param int i: index of the CData section child node, you are searching for. First node has index 0, second - 1, etc.
		* @return WString: text of the i-th XML CData section
		*/
		WString GetCData(int i=0)const;

		/**
		* Removes the i-th XML CData section of 'this'  
		*
		* @param int i: index of the CData section child node to remove
		*/
		void RemoveCData(int i=0);

		/**
		* Gets the number of direct child CData sections in 'this'
		*
		* @return int: the number of direct child CData sections
		*/
		int NumCDatas()const;

		/** 
		* Appends an XML EntityReference <br>
		* Appends a new EntityReference child node named refName to the end of 'this'
		*
		* @param WString & refName: name of the XML EntityReference 
		*
		* @throws JDFException if 'this' is a null element and thus nothing can be appended to it
		*/
		void AppendEntityReference(const WString & refName);

		/** 
		* Creates and appends to 'this' a new child element named nodeName and appends an XML Text to it
		*
		* @param WString & nodeName: the name of the new child element
		* @param WString & text: text to append
		* @return KElement: newly created child element, that contains the XML Text
		*/
		KElement AppendTextElement(const WString & nodeName, const WString & text);


		/**
		//
		// modify element
		//
		*/

		/**
		* Deletes itself from its parent
		* @return KElement: the deleted element
		*
		* @throws JDFException if 'this' is a null element and thus can't be deleted or modified 
		*/
		KElement DeleteNode();

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
		KElement MergeElement(KElement e,bool bDelete);

		/**
		* Removes all attributes, elements and text, leaving only a stub tag
		*
		* @return bool: true, if successful
		*/
		bool Flush();	

		/**
		* Compares element contents recursively. <br>
		* Note, that this is <em>NOT</em> the same as operator ==, which compares 'this' reference with reference of e
		*
		* @param KElement & e: the node element to compare with 'this' 
		* @return bool: true, if the contents are equivalent
		*/
		bool IsEqual(const KElement &e) const;

		/** 
		* Overloaded compare operator == <br>
		* Compares 'this' reference with reference of other
		*
		* @param KElement & other: the reference to compare with 
		* @return bool: true, if 'this' reference and reference of other are equivalent 
		*/
		bool operator ==(const KElement& other)const;

		/** 
		* Overloaded compare operator != <br>
		* Compares 'this' reference with reference of other 
		*
		* @param KElement & other: the reference to compare with 
		* @return bool: true, if 'this' reference and reference of other are not equivalent
		*/
		bool operator !=(const KElement& other)const;

		/**
		* Gets the n'th Ancestor node with name parentNode 
		*
		* @param WString & parentNode: tag name of the parent to find
		* @param int depth: the number of recursions to go through. Only counted for nodes that match parentNode
		* @return KElement: the matching parent element
		*/
		KElement GetDeepParent(const WString &parentNode, int depth=0)const;

		/**
		* Gets the first Ancestor node whose name is different from thisNode
		*
		* @param WString & thisNode: tag name of the parent that is skipped in the search
		* @return KElement: the matching parent element
		*/
		KElement GetDeepParentNotName(const WString &thisNode)const;

		/**
		* Gets the first Ancestor of 'this' with name parentNode;
		* e.g. The resource in a resourcepool
		*
		* @param WString & parentNode: tag name of the parent to find
		* @return KElement: the matching parent element
		*/
		KElement GetDeepParentChild(const WString &parentNode)const;

		/**
		* Gets the n'th Ancestor node with name, that is defined in vParentNode
		*
		* @param vWString & vParentNode: list of tag names of the parent to find
		* @param int depth: the number of recursions to go through. Only counted for nodes that match vParentNode
		* @return KElement: the matching parent element
		*/
		KElement GetDeepParent(const vWString& vParentNode, int depth=0)const;

		/**
		* Moves 'this' up by one level (moves from parent to grandparent) or to the closest ancestor with name newParentName
		*
		* @param WString & newParentName: name of the parent to recursively search, defaults to any name
		* @return KElement&: 'this' after moving
		*
		* @throws JDFException if 'this' is a null element and thus can't be moved or modified 
		*/
		KElement& PushUp(const WString & newParentName=WString::emptyStr);

		/**
		* Erases all empty text nodes in 'this' and its subelements 
		* If there any empty text nodes removes them.
		* If bTrimWhite is true, then trims white spaces from both ends of a text node
		* and only then, if it is empty, removes it
		*
		* @param bool bTrimWhite: trims whitespace of text, default=true
		* @return int: the number of removed nodes 
		*/
		int EraseEmptyNodes(bool bTrimWhite=true);

		/**
		* Searches for the first occurrence of the attribute with name attrib in 'this' or any its ancestors
		*
		* @param WString & attrib: the attribute key
		* @param WString & nameSpaceURI: the XML-namespace to look in
		* @param WString & def: the default value to return if attrib does not exist
		* @return WString: value of attribute found, value of def if not available
		* @since 300402 
		*/
		WString GetInheritedAttribute(const WString & attrib,const WString& nameSpaceURI=WString::emptyStr,const WString & def=WString::emptyStr)const;

		// MM added 2001-08-31: 
		/**
		* Searches for the first occurrence of the child element with name elementName in 'this' or any its ancestors
		*
		* @param WString & elementName: name of the child element, you are looking for
		* @param WString & nameSpaceURI: XML-namespace to look in
		* @param int iSkip: number of matching child nodes to skip
		* @return KElement: the found child element 
		*/
		KElement GetInheritedElement(const WString& elementName, const WString & nameSpaceURI=WString::emptyStr,int iSkip=0)const;

		/**
		* Shorthand to get a deep child, that matches defined name and nameSpace
		* 
		* @param WString & nodeName: the name of the child to search
		* @param WString & nameSpaceURI: nameSpace to look in
		* @param int iSkip: number of matching child nodes to skip 
		* @return KElement: the found child element
		*
		* @deprecated uses GetChildByTagName(...) instead
		*/
		KElement GetDeepElement(const WString &nodeName,const WString& nameSpaceURI=WString::emptyStr, int iSkip=0) const;

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
		KElement RenameElement(const WString & newName,const WString & newNameSpaceURI=WString::emptyStr);

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
		KElement ReplaceElement(const KElement & src);

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
		KElement MoveElement(const KElement & src, const KElement& beforeChild=DefKElement);

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
		KElement CopyElement(const KElement & src, const KElement& beforeChild = DefKElement);
		/*
		* document access
		*/
		//@{
		/**
		* Gets the root element of the current document
		*
		* @return KElement: the root element of the current document
		*/
		KElement GetDocRoot()const;

		/**
		* Gets the root element name of the current document
		*
		* @return WString: the root element name of the current document
		*/
		WString GetDocRootName()const;

		/**
		* Gets the document object that owns 'this' 
		*
		* @return XMLDoc: the document owner of 'this'
		*/
		XMLDoc GetOwnerDocument()const;

		/* namespace support
		*/
		//@}

		/**
		* Gets the NameSpaceURI of 'this'
		*
		* @return WString: The nameSpaceURI of 'this'
		*/
		WString GetNamespaceURI()const;

		/**
		* Gets the NameSpaceURI corresponding to a given prefix
		* @param WString prefix the prefix to check for
		* @return WString: The nameSpaceURI that maps to prfix
		*/

		WString GetNamespaceURIFromPrefix(const WString& prefix)const;

		/**
		* Gets the namespace prefix of 'this'
		*
		* @return WString: the namespace prefix of 'this'
		*/
		WString GetPrefix()const;

		/**
		* Gets the length of the namespace prefix of 'this', -1 if no prefix is set
		*
		* @return WString: the namespace prefix of 'this'
		*/
		int getPrefixLength()const;

		/**
		* Gets the local name of 'this'
		*
		* @return WString: the local name of 'this'
		*/
		WString GetLocalName()const;

		/**
		* Parses s for it's namespace prefix
		*
		* @param WString & s: string to parse
		* @return WString: namespace prefix - empty if no ":" is in s
		*
		* @deprecated  use XMLNSPrefix
		*/
		static WString XMLNameSpace(const WString& s);

		/**
		* Parses pc for it's namespace prefix
		*
		* @param JDFCh* pc: pointer to string to parse
		* @return WString: namespace prefix of element - empty if no ":" is in pc 
		*/
		static WString XMLNSPrefix(const JDFCh* pc);

		/**
		* Parses pc for it's local name
		*
		* @param JDFCh* pc: pointer to string to parse 
		* @return WString: local name  
		*/
		static WString XMLNSLocalName(const JDFCh* pc);

		/**
		* Sets the namespace prefix of 'this'
		*
		* @param WString prefix: namespace prefix to set
		*
		* @throws JDFException if 'this' is a null element and thus no settings can be made
		*/
		void SetPrefix(const WString& prefix);

		/*
		* 
		* misceleneous
		*
		*/
		/**
		* Enumeration for validation level <br>
		* level ValidationLevel_None: always return true <br>
		* level ValidationLevel_Construct: incomplete and null elements are valid <br>
		* level ValidationLevel_Incomplete: incomplete elements are valid <br>
		* level ValidationLevel_Complete: full validation of an individual resource <br>
		* level ValidationLevel_RecursiveIncomplete: incomplete validation of an individual resource and all of its child elements - e.g. for pools <br>
		* level ValidationLevel_RecursiveComplete: full validation of an individual resource and all of its child elements - e.g. for pools <br>
		*/
		enum EnumValidationLevel{ValidationLevel_None,ValidationLevel_Construct,ValidationLevel_Incomplete,ValidationLevel_Complete,ValidationLevel_RecursiveIncomplete,ValidationLevel_RecursiveComplete};

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
		virtual bool IsValid(EnumValidationLevel level=ValidationLevel_Complete)const;

		/**
		* Shorthand for lazy people. Uses isNull
		* Checks, whether 'this' is null or not. 
		*
		* @return bool: true, if 'this' is a null element
		*/
		bool operator !()const;

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
		KElement GetTarget(const WString & id,const WString & attrib=L"ID") const;

		/**
		* Checks, whether 'this' is null or not
		* 
		* @return bool: true, if 'this' does not point at an element in the DOM tree
		*/
		inline bool isNull()const{
			return this==0 || domElement==0;
		}

		/**
		* Switches between limp-along and picky mode; if the MACRO THROWNULL is defined,
		* throws an exception for NULL objects, else returns DOMElement::isNull()    <p> 
		* Checkes if 'this' is null and if so, throws a warning message
		*
		* @return bool: true, if 'this' is null
		*
		* @throws JDFException if there was attempt to operate with a null element
		*/
		inline bool throwNull()const{
		#ifdef THROWNULL
			if(isNull()) 
				throw JDFException(L"Attempting operation on a NULL KElement");
			return true;
		#else
			return isNull();
		#endif
		};



		/**
		* Sets 'this' or its closest parent element with an id as dirty 
		* @param bool bAttribute if true, only attributes are dirty, else child elements
		*/
		void SetDirty(bool bAttribute)const;

		/**
		* Writes a character representation of 'this' to a string <br> 
		* Always assumes utf-8 encoding
		*
		* @param WString& out : string to write to
		* @return bool: true if successful
		* 
		*/
		bool Write2String(WString& out)const;

		/**
		* Returns a  character representation of 'this' <br> Writes to a string <br>
		* Always assumes utf-8 encoding
		*
		* @return WString: the string
		*/
		WString ToString()const;

		/**
		* Gets the number of direct child nodes of 'this', that match NodeType
		*
		* @param int nodeType: the DOM NodeType, if 0 count all nodes
		* @return int: the counted number of direct child nodes, that match NodeType
		*/
		int NumChildNodes(int nodeType)const;

		/**
		* Removes from 'this' iSkip-th child node, that match NodeType
		*
		* @param int nodeType: the DOM NodeType,if 0 count all nodes
		* @param iSkip number: number of matching child nodes to skip
		*/
		void RemoveChildNode(int nodeType, int iSkip);

		/**
		* Checks, if 'this' has child nodes, that match NodeType, or not.
		*
		* @param int nodeType: the DOM NodeType, if 0 count all nodes
		* @return bool: true, if there are child nodes of defined NodeType in 'this'
		*/
		bool HasChildNodes(int nodeType)const;

		/**
		* Checks, if the node is abstract, i.e. is not completely described.
		* Utility used by GetUnknownElements, GetUnknownAttributes
		*
		* @return bool: true, if the node is abstract
		*/
		virtual bool IsAbstract()const;

		/**
		* Gets the name of the iSkip-th child node, that fits NodeType
		*
		* @param int nodeType: the DOM NodeType, if 0 count all nodes
		* @param int iSkip:  number of matching child nodes to skip
		* @return WString: the node name of the matching child
		*/
		WString GetChildNodeName(int nodeType,int iSkip)const;

		/**
		* Gets the value of the iSkip-th child node, that fits NodeType
		*
		* @param int nodeType: the DOM NodeType, if 0 count all nodes
		* @param int iSkip: number of matching child nodes to skip
		* @return WString: the node value of the matching child
		*/
		WString GetChildNodeValue(int nodeType,int iSkip)const;

		/**
		* Gets the NodeType of the iSkip-th child node
		*
		* @param int iSkip: number of child nodes to skip
		* @return int: number, that determines the DOM NodeType of the child
		*/
		int GetChildNodeType(int iSkip=0)const;

		/**
		* Gets the iSkip-th child node, if it fits nodeType ELEMENT_NODE 
		* (child node is a element node, not text node, comment node ect).
		* Otherwise empty KElement is returned. <br>
		* Note, that this differs from the pure element accessors, in that intermediate text nodes etc are NOT skipped
		*
		* @param int iSkip: number of child nodes to skip, regardless of its type
		* @return KElement: the iSkip-th child node, if it is element node or otherwise an empty KElement
		*/
		KElement GetChildNodeElement(int iSkip=0)const;

		/**
		* remove all empty attributes from this (e.g. att="")
		* @param bRecurse if true, alse recurse subelements, else only local
		*/
		void eraseEmptyAttributes(bool bRecurse);

		/**
		* check whether this matches a simple xpath
		* @param path
		* @return
		*/
		bool matchesPath(const WString& path, bool bFollowRefs);

		/**
		* Gets the number of direct child nodes of 'this', that match NodeType
		*
		* @param int nodeType: the DOM NodeType, if 0 count all nodes
		* <blockquote><ul>
		*    <li>ELEMENT_NODE                = 1
		*    <li>ATTRIBUTE_NODE              = 2
		*    <li>TEXT_NODE                   = 3
		*    <li>CDATA_SECTION_NODE          = 4
		*    <li>ENTITY_REFERENCE_NODE       = 5
		*    <li>ENTITY_NODE                 = 6
		*    <li>PROCESSING_INSTRUCTION_NODE = 7
		*    <li>COMMENT_NODE                = 8
		*    <li>DOCUMENT_NODE               = 9
		*    <li>DOCUMENT_TYPE_NODE          = 10
		*    <li>DOCUMENT_FRAGMENT_NODE      = 11
		*    <li>NOTATION_NODE               = 12
		*    <li>XML_DECL_NODE               = 13
		* </blockquote></ul>
		* @return int: the counted number of direct child nodes, that match NodeType
		*/
		int getNumChildNodes(int nodeType);

		/**
		* fills a HashSet with all values of the attribute in all child elements
		* @param attName attribute name
		* @param preFill the HashSet to fill
		*/
		void fillHashSet(const XMLCh* attName,SetWString* preFill)const;

		/*
		* set attribute "xsi:type"
		* @param typ the value to set the attribute to
		*/
		void setXSIType(const WString& typ);

		/**
		* returns the xsi:type of this element, null if not present
		* @return String the xsi:type of this element, null if not present
		*/
		WString getXSIType();

		/**
		* Attribute data types used by the autogenerator
		* @since 011001 added NMTOKENS, enumeration, enumerations
		* @since 160104 added URI, IDREFS, IDREF, XYPairRangeList, XYRelation, RectangleRangeList, regExp, 
		* NumberList, ShapeRangeList, DateTimeRangeList, DurationRangeList, DateTimeRange, DurationRange
		* @since 110205 added Unknown 
		* @since 211206 moved to KElement
		*/
		enum EnumAttributeType{AttributeType_Unknown,AttributeType_Any,AttributeType_boolean,AttributeType_double,AttributeType_integer,
			AttributeType_NMTOKEN,AttributeType_NMTOKENS,AttributeType_string,AttributeType_IntegerRange,
			AttributeType_IntegerList,AttributeType_IntegerRangeList,AttributeType_matrix,AttributeType_rectangle,AttributeType_XYPair,
			AttributeType_URL,AttributeType_URI,AttributeType_enumeration,AttributeType_enumerations,AttributeType_NumberRangeList,AttributeType_NameRangeList,
			AttributeType_NumberRange,AttributeType_ID,AttributeType_dateTime,AttributeType_duration,AttributeType_shape,
			AttributeType_IDREFS,AttributeType_IDREF,AttributeType_XYPairRange,AttributeType_XYPairRangeList,AttributeType_XYRelation,
			AttributeType_RectangleRangeList,AttributeType_regExp,AttributeType_NumberList,AttributeType_ShapeRangeList,
			AttributeType_DateTimeRangeList,AttributeType_DurationRangeList,AttributeType_DateTimeRange,AttributeType_DurationRange,
			AttributeType_language,AttributeType_languages,AttributeType_PDFPath,AttributeType_XPath,
			AttributeType_LabColor,AttributeType_RGBColor,AttributeType_CMYKColor,AttributeType_hexBinary,AttributeType_TransferFunction,
			AttributeType_NameRange,AttributeType_RectangleRange,AttributeType_ShapeRange,AttributeType_JDFJMFVersion,AttributeType_shortString,AttributeType_longString
		};


	protected:

		/**
		* gets the XMLDocUserData of this
		*/
		XMLDocUserData* getXMLDocUserData() const;

		/**
		* Gets a vector of attribute keys that are missing in 'this' 
		*
		* @param vWString& vReqKeys: list of required attribute keys
		* @param int nMax: maximum size of the returned vector
		* @return vWString: vector of strings that contains missing attribute keys
		*/
		vWString GetMissingAttributeVector(const vWString& vReqKeys, int nMax=9999999)const;

		/**
		* Gets a vector of attribute keys that exist but are unknown by 'this'
		*
		* @param vWString & vKnownKeys: list of known attribute keys
		* @param vWString & vInNameSpace: list of namespaces where unknown attributes are searched for. if empty, all namespaces are searched
		* @param int nMax: maximum size of the returned vector
		* @return vWString: vector of strings that contains unknown attribute keys
		*/
		vWString GetUnknownAttributeVector(const vWString& vKnownKeys, const vWString& vInNameSpace=vWString(), int nMax=9999999)const;

		/**
		* Gets a vector of direct child element names that are missing in 'this'
		*
		* @param vWString & vReqKeys: list of required element tag names
		* @param int nMax: maximum size of the returned vector
		* @return vWString: vector of strings that contains missing element names
		*/
		vWString GetMissingElementVector(const vWString& vReqKeys, int nMax=9999999)const;

		/**
		* Gets a vector of direct child element names that exist but are unknown in 'this'
		*
		* @param vWString & vKnownKeys: list of unknown element tag names
		* @param vWString & vInNameSpace: list of namespaces where unknown element are searched for. if empty, all namespaces are searched
		* @param int nMax: maximum size of the returned vector
		* @return vWString: vector of strings that contains unknown element names
		*/
		vWString GetUnknownElementVector(const vWString& vKnownKeys,vWString vInNameSpace=vWString(), int nMax=9999999)const;

		/**
		* Gets a vector of direct child element names that may be legally inserted in 'this'
		*
		* @param vWString & vKnownKeys: list of insertable element tag names
		* @param vWString & vUnique: list of elements that may occur only once
		* @return vWString: vector of strings that contains insertable element names
		*/
		vWString GetInsertElementVector(const vWString& vKnownKeys, const vWString& vUnique)const;

		/**
		* Tests whether the specified nodename and namespace fits the nodename and namespace of 'this'
		*
		* @param JDFCh* nodeName: the name of the node to test. may be either local or qualified
		* @param JDFCh* nameSpaceURI: the namespace of the node to test.
		* @return bool: true if fits 
		*/
		virtual bool FitsName(const JDFCh* nodeName, const JDFCh* nameSpaceURI)const;

		/**
		* Tests whether the specified nodename and namespace fits the nodename and namespace of 'this'
		*
		* @param JDFCh* nodeName: the name of the node to test. may be either local or qualified
		* @return bool: true if fits 
		*/
		virtual bool FitsName(const JDFCh* nodeName)const;

		/**
		* Internal function for searching through the trees.
		* Gets 'this' or the child node of arbitrary depth,
		* that matches defined id, name and is not a childToExclude
		* @since 260104 swapped name and id, note that this is NOT and interface change but simply reflects
		* the way it is implemented, i.e. the implementation has always been first paramater=name, second parameter = value
		*
		* @param JDFCh* name: name of the attribute node to find
		* @param JDFCh* id: the ID of the node to find
		* @param KElement & childToExclude: child to exclude during the search 
		* @return KElement: the matching element node
		*/	
		KElement GetDeepElementByID(const JDFCh* name, const JDFCh* id,const KElement& childToExclude, XMLDocUserData* ud)const;


	private:
		friend class XMLDoc;
		friend class JDFResource;
		friend class JDFElement;
		XERCES_CPP_NAMESPACE_QUALIFIER DOMElement* domElement;	
		vElement getXPathElementVectorInternal(WString path, int maxSize, bool bLocal)const;
		JDFAttributeMap getXPathAtMap(const WString& path, int posBAt, int posB1)const;


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
		XERCES_CPP_NAMESPACE_QUALIFIER DOMNode* GetChildNode(int nodeType, int iPos=0)const;

		/**
		* Get The DOM Attribute node of a given attribute
		* It if attrib has no namespace prefix and nameSpaceURI is a wildcard
		* the attribute with the element prefix will be returned if no empty attribute exists
		* e.g. GetDOMAttr("a") will return the node x:a in <x:e x:a="b"/>
		* <br>
		* default: GetDomAttr(attrib,nameSpaceURI,false)
		*
		* @param JDFCh* attrib the attribute Name
		* @param JDFCh* nameSpaceURI then manespaceURI, defaults to the local namespace
		* @param bInherit search in parent elements as well
		* @return DOMAttr*  the DOMAttr node of the matching attribute
		* 
		*/
		XERCES_CPP_NAMESPACE_QUALIFIER DOMAttr* GetDOMAttr(const JDFCh* attrib, const JDFCh* nameSpaceURI, bool bInherit=false) const;
	}; // class KElement

	/** overload << for KElement
	*/
	JDF_WRAPPERCORE_EXPORT std::ostream& operator<<(std::ostream& target, const JDF::KElement& toWrite);

} // namespace JDF


#endif // !defined(_KELEMENT_H_)
