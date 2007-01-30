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
// 300802 RP GetJDFNodeByID(const WString & ID)const added
// 130902 RP CollectGarbageResources() added
// 010903 FB added Write2URL()
// 291003 RP added schemalocation to Write2URL
//
// JDFDoc.h: interface for the JDFDoc class.
// 
// The Document class 
//
//
**********************************************************************/

#if !defined(_JDFDOC_H__)
#define _JDFDOC_H__
#include <jdf/wrappercore/XMLDoc.h>
#include <jdf/lang/vWString.h>

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


namespace JDF{
	
	class JDFNode;
	class JDFJMF;
	class File;
	class MIMEMessage;
	class MIMEBasicPart;
	class JDFElement;
	
	/**
	* Wrapper class around a Dom document
	* defines both the document of a JDF or JMF 
	*/
	//@{
	class JDF_WRAPPERCORE_EXPORT JDFDoc :public XMLDoc{
	public:
	/**
	* copy ctor
		*/
		JDFDoc(XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument* D);
		
		/**
		* copy ctor
		*/
		JDFDoc(const XMLDoc& D);
		
		/**
		* dtor
		*/
		virtual ~JDFDoc();
		
		/**
		*	Create the kind of JDF you need - new ctor - create a new document;
		*	type=0: JDF
		*	type=1: JMF
		*/
		JDFDoc(int docType=0);
		
		/**
		* copy ctor
		*/
		JDFDoc& operator =(XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument* other);
		
		/**
		* copy ctor
		*/
		JDFDoc& operator =(const XMLDoc& other);
		
		/**
		* Get the jdf root, e.g. in a printtalk document
		*
		* @ param void
		* @ return JDFNode: The root of the JDF File
		*/
		JDFNode GetJDFRoot();
		
		/**
		* Get the jmf root, e.g. in a printtalk document
		*
		* @ param void
		* @ return JMFRoot: The root of the JDF File
		*/
		JDFJMF GetJMFRoot();
		
		/**
		* returns a JDFNode by its id attribute
		*
		* @param WString the ID parameter of the JDF node
		* @return JDFNode the corresponding JDF Node, null if no such node exists
		*
		*/
		JDFNode GetJDFNodeByID(const WString & ID)const;
		
		/**
		* removes all dangling resources and cleans up the rrefs attributes
		*
		* @param vWString nodeNames the list of nodenames to remove, remove all if nodenames is empty
		* @return int the number of resources that were removed
		*
		*/
		int CollectGarbageResources(const vWString & nodeNames=vWString::emptyvStr);
		
		/**
        * This method sends the contents of this JDFDoc to the URL <code>strURL</code> and
        * receives the response in the returned JDFDoc.
		*
        * @param  strURL      the URL to write to
		* @param  WString schemaLocation	the location of the schema if validation is required. A non-empty string implies validation
        * @return docResponse the response received from URL. A Null document if no response was received
		*/
		JDFDoc Write2URL(const WString& strURL, const WString& schemaLocation=WString::emptyStr) const;
		
		
		/**
		* parse an input string<br>
		* returns an empty document if unsuccessful
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
			* @return bool true if successful
		*/
		bool Parse(const WString& inFile,bool bValidate=true, bool bEraseEmpty=true,
			bool bDoNamespaces=true, XERCES_CPP_NAMESPACE_QUALIFIER ErrorHandler* pErrorHandler=0,
			const WString& schemaLocation=WString::emptyStr);
		
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
			* @return bool true if successful
		*/
		bool Parse(File inFile, bool bValidate=true, bool bEraseEmpty=true,
			bool bDoNamespaces=true, XERCES_CPP_NAMESPACE_QUALIFIER ErrorHandler* pErrorHandler=0,
			const WString& schemaLocation=WString::emptyStr);

			/**
			* return the MIME content type of this document
			* @return WString the mime conten type
			* @throws JDFException if neithe JDF nor JMF root
		*/
		WString GetContentType() const;

		/**
		* Creates a pointer to a MIMEMessage that contains the document as the first mimePart
		* @return the MIMEMessage with this as its first part
		*/
		MIMEMessage *CreateMIMEMessage() const;
		
		/**
		* Creates a pointer to a MIMEBasicPart that contains the document
		* @return the MIMEBasicPart with this 
		*/
		MIMEBasicPart* CreateMIMEBasicPart() const;


	protected:
		
	/**
	*	clean the doc and restart from scratch
	*	The root element remains
	*	@return boolean: true if success
		*/
		bool Flush();
	};
	//@}
};

#endif // !defined(_JDFDOC_H__)
