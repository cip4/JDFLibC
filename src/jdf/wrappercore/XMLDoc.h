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
/************************************************************************
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
// 180700 RP MyString -> WString : all strings now 16 bit
// 230800 RP add comments to header
// 010601 NV migrated to JDF::iostream
// 011001 MM added ErrorHandler and Namespace handling to Parse
// 150101 RP added StringParse and Write2String methods
// 180101 RP made namespace supported parsing to the only option
// 201201 RP added a default error handler to the Parser
// 070502 RP added support for XMLDocUserData
// 020702 RP XXXParse() added support for schema validation
// 041202 RP added xercesdomparser to all callse of Parse()
// 290403 RP added DeleteAdopted
// 150503 RP Write2String now uses setUTF8Bytes()
// 150503 RP StringParse now uses getUTF8Bytes()
// 140703 RP added refcounts to the domDocument allowing destruction of the parser
// 010903 FB added Write2URL()
// 090903 RP reintroduced the parse routines
// 090903 RP mem leak of userData fixed
// 150904 RP Write2String now uses setUTF8Bytes()
// 150904 RP StringParse now uses getUTF8Bytes()
//
// XMLDoc.h: interface for the XMLDoc class.
// 
// The Document class 
//
//
**********************************************************************/
#ifndef _XMLDoc_H__
#define _XMLDoc_H__

#include <jdf/lang/WString.h>


XERCES_CPP_NAMESPACE_BEGIN
class ErrorHandler;
class DOMDocument;
class DOMNode;
class XMLFormatTarget;
XERCES_CPP_NAMESPACE_END


namespace JDF {

	class XMLDocUserData;
	class vWString;	
	class File;
	class OutputStream;
	class InputStream;
	class ByteArrayInputStream;
	class JDFParser;

	/**
	JDF independent wrapper class around a Dom document
	*/
	class JDF_WRAPPERCORE_EXPORT XMLDoc{
		friend class KElement;

	public:
		/**
		* copy ctor
		*/
		XMLDoc(XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument* D);

		/**
		* copy ctor
		*/
		XMLDoc(const XMLDoc& D);

		/**
		* dtor
		*/
		virtual ~XMLDoc();

		/**
		* copy ctor
		*/
		XMLDoc& operator =(XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument* other);

		/**
		* copy ctor
		*/
		XMLDoc& operator =(const XMLDoc& other);


		/**
		* @param WString& docRootString tag name of the doc root 
		* @param WString& docRootNS namespace uri of the doc root 
		*/
		XMLDoc(const WString& docRootString=WString::emptyStr, const WString& docRootNS=WString::emptyStr);

		/**
		* This method sends the contents of this XMLDoc to the URL <code>strURL</code> and
		* receives the response in the returned XMLDoc.
		*
		* @param  strURL					the URL to write to
		* @param  strContentType			the content type to write to
		* @param  WString schemaLocation	the location of the schema if validation is required. A non-empty string implies validation
		* @return docResponse				the response received from URL. A Null document if no response was received
		*/
		XMLDoc Write2URL(const WString& strURL, const WString& strContentType=L"text/xml", const WString& schemaLocation=WString::emptyStr) const;


		/**
		* write to a OutputStream
		* always assume utf-8 encoding
		* @param OutputStream& out stream to write to
		* @return bool true if successful
		* 
		*/
		bool Write2Stream(OutputStream& out)const;

		/**
		* write to a String in the system encoding
		* In order to retrieve utf-8 call GetUTF8Bytes() on the returned string
		*
		* @param JDF::WString& out string to write to
		* @return bool true if successful
		* 
		*/
		bool Write2String(WString& out)const;

		/**
		* write to a string
		* always assume utf-8 encoding
		* @return WString the string
		* 
		*/
		WString ToString()const;

		/**
		* write to a JDF::OutputStream
		* always assume utf-8 encoding
		* @param JDF::File outFile  file to write to
		* @return bool true if successful
		* 
		*/
		bool Write2File(JDF::File outFile)const;
		/**
		* write to a JDF::OutputStream
		* always assume utf-8 encoding
		* @param WString& ouFile output file name, stdout if empty
		* @return bool true if successful
		* 
		*/
		bool Write2File(const WString& outFile=WString::emptyStr)const;

		/**
		* create a new JDF::ByteArrayInputStream and fill it with the current contents of this
		* Ownership of the stream is passed on to the calling application
		* this stream may then be passed on to functions that require JDF input streams
		* always assume utf-8 encoding, no changes to XMLDoc are passed on to the stream after the initial creation
		* 
		* @return ByteArrayInputStream* the stream. Don't forget to delete it
		* 
		*/
		JDF::ByteArrayInputStream* CreateNewByteArrayInputStream()const;

		/**
		* parse an input string<br>
		* returns an empty document if unsuccessful
		* StringParse assumes system default encoding 
		* thus the string is first encoded to a UTF8 byte stream which is the parsed. 
		*
		* @param WString& in input string to parse
		* @param bool bValidate validating parse if true
		* @param bool bEraseEmpty erase empty or whitespace only nodes if true
		* @param bool bDoNamespaces analyze namespaces during parsing if true (recommended: true) - now a dummy - namespace support is always switched on
		* @param ErrorHandler * pErrorHandler pointer to a customized error handler, must be derived from class ErrorHandler. <br>
		*	If zero the XMLErrorHandler defined in JDFParser.cpp is used
		* @param WString& schemaLocation location of a schema if any
		*
		* @return bool true if successful
		*/
		bool StringParse(const WString& in,bool bValidate=true, bool bEraseEmpty=true,
			bool bDoNamespaces=true, XERCES_CPP_NAMESPACE_QUALIFIER ErrorHandler* pErrorHandler=0,
			const WString& schemaLocation=WString::emptyStr);

		/**
		* parse any input stream<br>
		* returns an empty document if unsuccessful
		* @param InputStream& in input stream to parse
		* @param bool bValidate validating parse if true
		* @param bool bEraseEmpty erase empty or whitespace only nodes if true
		* @param bool bDoNamespaces analyze namespaces during parsing if true (recommended: true) - now a dummy - namespace support is always switched on
		* @param ErrorHandler * pErrorHandler pointer to a customized error handler, must be derived from class ErrorHandler. <br>
		*	If zero the XMLErrorHandler defined in JDFParser.cpp is used
		* @return bool true if successful
		*/
		bool StreamParse( InputStream& in,bool bValidate=true, bool bEraseEmpty=true,
			bool bDoNamespaces=true, XERCES_CPP_NAMESPACE_QUALIFIER ErrorHandler* pErrorHandler=0,
			const WString& schemaLocation=WString::emptyStr);


		/**
		* parse a file specified by inFile into memory<br>
		* returns an empty document if unsuccessful
		* @param WString& inFile input file name
		* @param bool bValidate validating parse if true
		* @param bool bEraseEmpty erase empty or whitespace only nodes if true
		* @param bool bDoNamespaces analyze namespaces during parsing if true (recommended: true) - now a dummy - namespace support is always switched on
		* @param ErrorHandler * pErrorHandler pointer to a customized error handler, must be derived from class ErrorHandler. <br>
		*	If zero the XMLErrorHandler defined in JDFParser.cpp is used
		* @param WString& schemaLocation location of a schema if any
		* @int nRetry number of times the parser should attempt to parse in case of an IO-Exception
		* @int waitMilliSecs milliseconds between retries
		* @return bool true if successful
		*/
		bool Parse(const WString& inFile,bool bValidate=true, bool bEraseEmpty=true,
			bool bDoNamespaces=true, XERCES_CPP_NAMESPACE_QUALIFIER ErrorHandler* pErrorHandler=0,
			const WString& schemaLocation=WString::emptyStr, int nRetry=0, int waitMilliSecs=42);

		/**
		* parse a file specified by inFile into memory<br>
		* returns an empty document if unsuccessful
		* @param File inFile file to parse
		* @param bool bValidate validating parse if true
		* @param bool bEraseEmpty erase empty or whitespace only nodes if true (recommended: true)
		* @param bool bDoNamespaces analyze namespaces during parsing if true (recommended: true) - now a dummy - namespace support is always switched on
		* @param ErrorHandler * pErrorHandler pointer to a customized error handler, must be derived from class ErrorHandler. <br>
		*	If zero the XMLErrorHandler defined in JDFParser.cpp is used
		* @param WString& schemaLocation location of a schema if any
		* @int nRetry number of times the parser should attempt to parse in case of an IO-Exception
		* @int waitMilliSecs milliseconds between retries
		* @return bool true if successful
		*/
		bool Parse(File inFile, bool bValidate=true, bool bEraseEmpty=true,
			bool bDoNamespaces=true, XERCES_CPP_NAMESPACE_QUALIFIER ErrorHandler* pErrorHandler=0,
			const WString& schemaLocation=WString::emptyStr, int nRetry=0, int waitMilliSecs=42);


		/**
		* get the document root element
		* @param WString& docRootString local tag name of the doc root to create if still empty
		* @param WString& docRootNS namespace uri of the doc root 
		* @return KElement the root element
		*/
		KElement GetRoot(const WString& docRootString=WString::emptyStr, const WString& docRootNS=WString::emptyStr)const;

		/**
		* append the document root element
		* @param WString& docRootString qualified tag name of the doc root to create if still empty
		* @param WString& docRootNS namespace uri of the doc root 
		* @return KElement the root element
		*/
		KElement SetRoot(const WString& docRootString, const WString& docRootNS=WString::emptyStr);

		/**
		* create a KElement that floats in nirvana <p>
		* this must be appended to a node with appendChild
		* @param WString tagName name of the element that is created
		* @param nameSpaceURI the namespace uri of the created element
		* @return KElement unconnected elememt that is created
		*/
		KElement CreateElement(const WString& tagName,const WString& nameSpaceURI=WString::emptyStr);

		/**
		* checks whether this is a reference to a DOM document
		* @return false if this points to an element in the dom tree
		*/
		inline bool isNull()const{
			return domDocument==0;
		}

		/**
		* return the internal DOMDocument pointer<br>
		* attention, use with care. No guarantee for internal consistency is given when modifying the DOMDocument
		* @return DOMDocument* the internal DOMDocument
		*/
		XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument* GetDOMDocument()const;

		/**
		* Switch between limp-along and picky mode; 
		* <p> if the MACRO THROWNULL is defined, throws an exception for NULL objects, else returns DOM_ELEMENT::isNull()
		* @return true if this is a null element
		*/
		inline bool throwNull()const{
#ifdef THROWNULL
			if(isNull()) 
				throw JDFException("Attempting operation on NULL XMLDoc");
			return true;
#else
			return isNull();
#endif
		}

		/**
		* get an XMLDoc that contains a representation of all dirty nodes
		* note that it does NOT reset the dirty flags
		* @return vWString the vector of element IDs
		*/
		XMLDoc GetDirtyDiff()const;

		/**
		* apply an XMLDoc that contains a representation of all dirty nodes
		*/
		void SetDirtyDiff(const XMLDoc &diffDoc);

		/**
		* get a vector of all IDs of elements that are dirty
		* @return vWString the vector of element IDs
		*/
		const vWString& GetDirtyIDs()const;

		/**
		* get a vector of all XPaths of elements that are dirty
		* @return vWString the vector of element IDs
		*/
		const vWString& GetDirtyXPaths()const;

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
		const vWString& SetDirty(const WString &id);

		/**
		* is the node with ID dirty?
		* @param WString id the id to be checked
		* @return bool true if the node with ID=id is dirty
		*/
		bool IsDirty(const WString &id)const;

		/**
		* Set the target with to target
		* @param KElement target the target element
		*/
		void SetTarget(const KElement& target);

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
		* delete the XMLDocUserData structure
		* @return void
		*/
		void DeleteUserData();

		/**
		* Remove the target from the target list
		* @param KElement target the target element
		*/
		void RemoveTarget(const KElement& target);


		/**
		* clean the doc and restart from scratch
		* The root element remains
		* @return bool true if successful
		*/
		bool Flush();

		/**
		* get the associated XMLDocUserData
		* @throw JDFException if no XMLDocUserData is set or this is NULL
		* @return the XMLDocUserData of this
		*/
		XMLDocUserData* GetXMLDocUserData()const;

		/**
		* get the XMLDocUserData
		* @throw JDFException if no XMLDocUserData is set or this is NULL
		* @param DOMDocument* pDomDocument the domDocument to get the user data for
		* @return the XMLDocUserData of this
		*/
		static XMLDocUserData* GetXMLDocUserData(XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument* pDomDocument);
		/**
		* does the owner document of this have an associated XMLDocUserData
		* @throw JDFException if no XMLDocUserData is set or this is NULL
		* @return true if XMLDocUserData of this exists
		*/
		bool HasXMLDocUserData()const;

		/**
		* get/create the associated XMLDocUserData
		* @throw JDFException if is NULL
		* @return the XMLDocUserData of this
		*/
		XMLDocUserData* GetCreateXMLDocUserData();


	private:
		static bool Write2FormatTarget(XERCES_CPP_NAMESPACE_QUALIFIER XMLFormatTarget* formTarget, const XERCES_CPP_NAMESPACE_QUALIFIER DOMNode*);
		XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument* domDocument;

		int DecRef();
		int IncRef();
		/**
		* Delete a previously adopted document 
		* the document must have been adopted manually with a call to AdoptSelf()<p>
		* any documents that were generated with an explicit call to 
		* SetRoot(WString) or  XMLDoc(JDFParser) are also deleted
		*/
		void DeleteAdopted();
	};
	/**
	* stream a DOM_Node to a stream
	* @param ostream target stream to dump the chatacter
	* @param DOM_Node &toWrite  the character string to write
	* @return  ostream& the stream after the operation
	*/
	JDF_WRAPPERCORE_EXPORT std::ostream& operator<<(std::ostream& target, const JDF::XMLDoc& toWrite);
}


#endif // !defined(_XMLDoc_H__)
