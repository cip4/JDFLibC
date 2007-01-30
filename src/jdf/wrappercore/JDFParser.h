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
// 010601 NV migrated to iostream
// 011001 MM added ErrorHandler and Namespace handling to Parse
// 150101 RP added StringParse and Write2String methods
// 180101 RP made namespace supported parsing to the only option
// 201201 RP added a default error handler to the Parser
// 070502 RP added support for JDFParserUserData
// 020702 RP XXXParse() added support for schema validation
// 041202 RP added XercesDOMParser to all callse of Parse()
// 290403 RP added AdoptDocument
// 240806 NB fixed ParseXXX)(), corrected external schema location
// 240806 NB added setExternalSchemaLocation()
//
// JDFParser.h: interface for the JDFParser class.
// 
// The Document class 
//
//
**********************************************************************/
#ifndef _JDFParser_H__
#define _JDFParser_H__

#include <jdf/lang/WString.h>


XERCES_CPP_NAMESPACE_BEGIN
class ErrorHandler;
class XercesDOMParser;
class DOMDocument;
XERCES_CPP_NAMESPACE_END


namespace JDF {

	class XMLDoc;
	class File;
	class InputStream;

	/**
	JDF independent wrapper class around a Dom document
	*/
	class JDF_WRAPPERCORE_EXPORT JDFParser{
		friend class KElement;

	public:
		/**
		*  ctor
		*/
		JDFParser();

		/**
		* dtor
		*/
		virtual ~JDFParser();

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
		* StringParse assumes system default encoding 
		* thus the string is first encoded to a UTF8 byte stream which is the parsed. 
		*
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
		* @param WString& inFile input file name or URL. 
		* Parse attempts to interpret inFile as a URL, i.e. it unescapes '%xx' and removes the File: prefix.
		* if this fails, inFile is interpreted literally as a local file name
		*
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
		* get the document root 
		* @return XMLDoc the root element
		* @deprecated use GetDocument instead
		*/
		XMLDoc GetRoot()const;

		/**
		* get the document root 
		* @return XMLDoc the root element
		*/
		XMLDoc GetDocument()const;


	private:
		XERCES_CPP_NAMESPACE_QUALIFIER XercesDOMParser* xercesDOMParser;
		/**
		* hide copy ctor
		*/
		JDFParser(const JDFParser& D);

		/**
		* copy ctor
		*/
		JDFParser& operator =(const JDFParser& other);
		XMLDoc* LastParsed;
		XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument* AdoptDocument()const;

		void initParser(const WString& schemaLocation, bool bValidate);

	};
	/**
	* stream a DOM_Node to a stream
	* @param ostream target stream to dump the chatacter
	* @param DOM_Node &toWrite  the character string to write
	* @return  ostream& the stream after the operation
	*/
	JDF_WRAPPERCORE_EXPORT std::ostream& operator<<(std::ostream& target, const JDFParser& toWrite);

} // namespace JDF


#endif // !defined(_JDFParser_H__)
