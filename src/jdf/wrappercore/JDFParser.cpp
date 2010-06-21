/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2010 The International Cooperation for the Integration of 
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
//
// JDFParser.cpp: implementation of the JDFParser class.
//
//////////////////////////////////////////////////////////////////////

#include "JDFParser.h"

#include "XMLDoc.h"
#include "KElement.h"
#include "JDFException.h"

#include <jdf/io/ByteArrayInputStream.h>
#include <jdf/io/InputStream.h>
#include <jdf/io/File.h>
#include <jdf/lang/Exception.h>
#include <jdf/net/URL.h>

#include <jdf/util/PlatformUtils.h>

#include <xercesc/sax/ErrorHandler.hpp>
#include <xercesc/util/BinInputStream.hpp>
#include <xercesc/framework/StdInInputSource.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/SAXParseException.hpp>

#include <iostream>

XERCES_CPP_NAMESPACE_USE


namespace JDF{
	//////////////////////////////////////////////////////////////////////////////////////////
	// internal error handler class
	class XMLErrorHandler : public ErrorHandler {
	public:
		XMLErrorHandler():ErrorHandler(){};
		virtual void warning(const SAXParseException& exception){
			std::cout << "warning " << exception.getMessage() << std::endl;
		}
		virtual void error(const SAXParseException& exception){
			// print out all parser errors except undefined variables for non-JDF stuff
			WString er(exception.getMessage());
			// this works with xerces 1.7, must check for higher versions
			if (er.toLowerCase().find(L"unknown") == er.npos) 
				std::cout <<"error " << er <<std::endl;
		}
		virtual void fatalError(const SAXParseException& exception){
			std::cout << "fatalError " << exception.getMessage() <<std::endl;
			throw JDFException("Fatal error in the Parser:" + WString(exception.getMessage()));
		}
		virtual void resetErrors(){
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////////////
	class BinInputStreamAdapter : public BinInputStream
	{
	public :

		BinInputStreamAdapter(JDF::InputStream* in) :
		   mStream(in)
		   {
			   fCurIndex = 0;		
		   }
		   virtual ~BinInputStreamAdapter() {}

		   virtual unsigned int curPos() const;
		   virtual unsigned int readBytes
			   (
			   XMLByte* const  toFill
			   , const unsigned int    maxToRead
			   );

	private :

		JDF::InputStream* mStream;
		unsigned int    fCurIndex;
	};


	inline unsigned int BinInputStreamAdapter::curPos() const
	{
		return fCurIndex;
	}

	class InputSourceAdapter : public InputSource
	{
	public:

		InputSourceAdapter(JDF::InputStream* in, bool takeOwnerShip=false) :
		  mStream(in),
			  mOwnerShip(takeOwnerShip)
		  {
		  }

		  ~InputSourceAdapter() 
		  {
			  if (mOwnerShip)
				  delete mStream;
		  }

		  BinInputStream* makeStream() const;

	private:
		JDF::InputStream* mStream;
		bool			  mOwnerShip;

	};

	BinInputStream* InputSourceAdapter::makeStream() const
	{
		return new BinInputStreamAdapter(mStream);
	}


	// ---------------------------------------------------------------------------
	//  MemBinInputStream: Implementation of the input stream interface
	// ---------------------------------------------------------------------------
	unsigned int BinInputStreamAdapter::readBytes(          XMLByte* const  toFill
		, const unsigned int    maxToRead)
	{
		try
		{
			/*
			if((fCurIndex%maxToRead)==0){
			const unsigned int bytesRead = mStream->read((char*)toFill,maxToRead);
			if (bytesRead == -1)
			return 0;
			fCurIndex += bytesRead;
			return bytesRead;
			}else{
			return 0;
			}
			*/

			const int bytesRead = mStream->read((char*)toFill,maxToRead);
			if (bytesRead == -1)
				return 0;
			fCurIndex += bytesRead;
			return bytesRead;


		}
		catch (JDF::IOException&)
		{
			return 0;
		}
	}


	//////////////////////////////////////////////////////////////////////
	// Construction/Destruction
	//////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////
	JDFParser::JDFParser(){
		xercesDOMParser = new XercesDOMParser();
		LastParsed=new XMLDoc();
	}
	//////////////////////////////////////////////////////////////////////
	JDFParser::~JDFParser(){
		delete xercesDOMParser;
		delete LastParsed;
	}
	//////////////////////////////////////////////////////////////////////
	JDFParser::JDFParser(const JDFParser& D){
	}
	//////////////////////////////////////////////////////////////////////
	JDFParser& JDFParser::operator =(const JDFParser& other){
		return *this;
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////

	XMLDoc JDFParser::GetRoot()const{
		return GetDocument();
	}
	//////////////////////////////////////////////////////////////////////
	XMLDoc JDFParser::GetDocument()const{
		return *LastParsed;
	}
	//////////////////////////////////////////////////////////////////////

	DOMDocument* JDFParser::AdoptDocument()const{
		DOMDocument* pUserDomDocument=xercesDOMParser->adoptDocument();
		return pUserDomDocument;
	}

	//////////////////////////////////////////////////////////////////////


	bool JDFParser::Parse(const WString& inFile, bool bValidate,bool bEraseEmpty,
		bool bDoNamespaces, ErrorHandler * pErrorHandler, const WString& schemaLocation,
		int nRetry, int waitMilliSecs)
	{
		*LastParsed=(DOMDocument*)0;
		if(schemaLocation.empty()) // 080207 - don't validate w/o schema
			bValidate=false;

		// special case
		if(inFile==L"_STDIN_") 
		{
			XMLErrorHandler err;
			StdInInputSource stdinSource;
			initParser(schemaLocation,bValidate);
			// 181201 RP always use namespace handling!
			xercesDOMParser->setDoNamespaces(bDoNamespaces);
			if (pErrorHandler != NULL){
				xercesDOMParser->setErrorHandler(pErrorHandler);  
			}else{
				xercesDOMParser->setErrorHandler(&err);  
			}
			bool bTry=bDoNamespaces;
			while(42){
				try{
					// parse the memory
					xercesDOMParser->parse(stdinSource);
					// cleanup the XML
					if(bEraseEmpty) 
						GetRoot().GetRoot().EraseEmptyNodes();
					*LastParsed=AdoptDocument();
					return true;
				}
				catch (const XMLException& e)
				{
					std::cout << "An error occured during parsing\n   Message: "
						<< e.getMessage() << std::endl;
				}catch (const JDFException& e){
					std::cout << "An error occured during parsing\n   Message: "
						<< e.getMessage() << std::endl;
				}
				// error case
				if(bTry) // already tried or absolutely require ns handling
					return false;
				// only try to fix once...
				bTry=true;
				// try again, ignoring name spaces
				xercesDOMParser->setDoNamespaces(false);
			}
			return false;
		}else{
			URL url;
			WString protocol;
			bool bGoodURL=true;
			try{
				url.setURL(inFile);
				protocol=url.getProtocol();
			}catch(...){
				// not a valid URL, assume straight file
				bGoodURL=false;
			}

			bool bRet=false;
			// assume that string is a URL, try parsing the file url interpretation of the string
			if(bGoodURL && protocol.compareToIgnoreCase(L"File")==0){
				bRet= Parse(JDF::File(url), bValidate, bEraseEmpty, bDoNamespaces, pErrorHandler, schemaLocation, nRetry, waitMilliSecs);
			}

			if(!bRet){ // the last parse failed or was not performed - try a straight 1-1 file name parse
				bRet = Parse(JDF::File(inFile), bValidate, bEraseEmpty, bDoNamespaces, pErrorHandler,schemaLocation, nRetry, waitMilliSecs);
			}
			return bRet;
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////

	bool JDFParser::Parse(JDF::File inFile, bool bValidate, bool bEraseEmpty,
		bool bDoNamespaces, ErrorHandler * pErrorHandler, const WString& schemaLocation, 
		int nRetry, int waitMilliSecs)
	{
		*LastParsed=(DOMDocument*)0;
		if(schemaLocation.empty()) // 080207 - don't validate w/o schema
			bValidate=false;

		// the actual parsing
		if (JDF::File(inFile).exists() == false)
		{
			throw JDFException("Error opening "+inFile.toString());
			return false;
		}
		XMLErrorHandler err;
		initParser(schemaLocation,bValidate);
		xercesDOMParser->setDoNamespaces(bDoNamespaces);

		if (pErrorHandler != NULL){
			xercesDOMParser->setErrorHandler(pErrorHandler);  
		}else{
			xercesDOMParser->setErrorHandler(&err);  
		}

		bool bTry=bDoNamespaces;
		bool bXMLError=false;
		while(42){
			try {
				// parse a file
				xercesDOMParser->parse(inFile.getAbsolutePath().data());
				// cleanup the XML
				if(bEraseEmpty) 
					GetDocument().GetRoot().EraseEmptyNodes();
				*LastParsed=AdoptDocument();

				return true;
			}
			catch (const XMLException& e)
			{
				std::cout << "An error occured during parsing\n   Message: "
					<< e.getMessage() << std::endl;
				bXMLError=true;
			}catch (const JDFException& e){
				WString er=e.getMessage();
				if(er.find(L"The primary document entity could not be opened") != er.npos){
					// some general read exception, retry and wait
					if(--nRetry<=0)
						return false;
					if (JDF::File(inFile).exists() == false) // someone pulled it out from under our feet
						return false;
					PlatformUtils::sleep(waitMilliSecs);
				}else{
					std::cout << "An error occured during parsing\n   Message: "
						<< er << std::endl;
					bXMLError=true;
				}
			}
			if(bXMLError){
				// XML Parse error case
				if(bTry) // already tried or absolutely require ns handling
					return false;
				// only try to fix once...
				bTry=true;
				// try again, ignoring name spaces
				xercesDOMParser->setDoNamespaces(false);
			}
		}

		return false;
	}

	//////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////


	bool JDFParser::StreamParse(JDF::InputStream& in, bool bValidate,bool bEraseEmpty,
		bool bDoNamespaces, ErrorHandler * pErrorHandler, const WString& schemaLocation)
	{
		if(schemaLocation.empty()) // 080207 - don't validate w/o schema
			bValidate=false;
		*LastParsed=(DOMDocument*)0;

		InputSourceAdapter adapter(&in,false);
		XMLErrorHandler err;
		initParser(schemaLocation,bValidate);
		xercesDOMParser->setDoNamespaces(bDoNamespaces);

		if (pErrorHandler != NULL){
			xercesDOMParser->setErrorHandler(pErrorHandler);  
		}else{
			xercesDOMParser->setErrorHandler(&err);  
		}

		bool bTry=bDoNamespaces;
		while(42){
			try{
				// parse the memory
				xercesDOMParser->parse(adapter);
				// cleanup the XML
				if(bEraseEmpty) 
					GetRoot().GetRoot().EraseEmptyNodes();

				*LastParsed=AdoptDocument();

				return true;
			}
			catch (const XMLException& e)
			{
				std::cout << "An error occured during parsing\n   Message: "
					<< e.getMessage() << std::endl;
			}catch (const JDFException& e){
				std::cout << "An error occured during parsing\n   Message: "
					<< e.getMessage() << std::endl;
			}

			// error case
			if(bTry) // already tried or absolutely require ns handling
				return false;
			// only try to fix once...
			bTry=true;
			// try again, ignoring name spaces
			xercesDOMParser->setDoNamespaces(false);
		}
		return false;
	}
	/////////////////////////////////////////////////////////////////
	bool JDFParser::StringParse(const JDF::WString& in, bool bValidate,bool bEraseEmpty,
		bool bDoNamespaces, ErrorHandler * pErrorHandler,const WString& schemaLocation)
	{
		const char * buf=((WString&)in).GetUTF8Bytes(); // this const_cast is safe although messy, but saves a lot of copying
		int siz=strlen(buf);
		ByteArrayInputStream inStream((char*)buf,siz,false);
		bool bRet=StreamParse(inStream, bValidate,bEraseEmpty, bDoNamespaces, pErrorHandler,schemaLocation);
		return bRet;
	}
	/////////////////////////////////////////////////////////////////

	void JDFParser::initParser(const WString& schemaLocation, bool bValidate)
	{
		xercesDOMParser->setDoValidation(bValidate);
		//		xercesDOMParser->setDoNamespaces(true);
		xercesDOMParser->setDoSchema(bValidate);
	}

	//////////////////////////////////////////////////////////////////////
} // namespace JDF


