/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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
// XMLDoc.cpp: implementation of the XMLDoc class.
//
//////////////////////////////////////////////////////////////////////

#include "XMLDoc.h"

#include "XMLDocUserData.h"
#include "KElement.h"
#include "vElement.h"
#include "JDFException.h"
#include "JDFParser.h"

#include <jdf/io/OutputStream.h>
#include <jdf/io/File.h>
#include <jdf/io/PushbackInputStream.h>
#include <jdf/lang/Janitor.h>
#include <jdf/net/URLConnection.h>
#include <jdf/util/PlatformUtils.h>

#include <xercesc/DOM/DOMDocument.hpp>
#include <xercesc/DOM/DOMImplementation.hpp>
#include <xercesc/DOM/DOMElement.hpp>
#include <xercesc/DOM/DOMImplementationRegistry.hpp>
#include <xercesc/DOM/DOMWriter.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/framework/MemBufFormatTarget.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/util/PlatformUtils.hpp>

#include <iostream>

XERCES_CPP_NAMESPACE_USE

namespace JDF{
	const JDFCh* xmlDocRef=L"XMLDocRef";
	static bool setIgnoreNSDefault=false;
	static bool generateUID=false;
	static bool compressPrint=false;
	static int writeRetry=10;

	//////////////////////////////////////////////////////////////////////
	// Construction/Destruction
	//////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////
	XMLDoc::XMLDoc(DOMDocument* D){
		domDocument=D;
		IncRef();
	}
	//////////////////////////////////////////////////////////////////////
	XMLDoc::XMLDoc(const XMLDoc& D){
		domDocument=D.domDocument;
		IncRef();
	}
	//////////////////////////////////////////////////////////////////////
	XMLDoc::~XMLDoc(){
		DecRef();
	}
	//////////////////////////////////////////////////////////////////////
	XMLDoc& XMLDoc::operator =(DOMDocument* other){
		if(domDocument!=other){
			DecRef();
			domDocument=other;
			IncRef();
		}
		return *this;
	};
	//////////////////////////////////////////////////////////////////////
	XMLDoc& XMLDoc::operator =(const XMLDoc& other){
		if(domDocument!=other.domDocument){
			DecRef();
			domDocument=other.domDocument;
			IncRef();
		}
		return *this;
	};
	//////////////////////////////////////////////////////////////////////
	XMLDoc::XMLDoc(const WString& docRootString,const WString& docRootNS){
		domDocument=0;
		if(docRootString.empty()) 
			return;
		SetRoot(docRootString,docRootNS);
		GetCreateXMLDocUserData();

	}

	//////////////////////////////////////////////////////////////////////
	DOMDocument* XMLDoc::GetDOMDocument()const{
		return domDocument;
	}

	//////////////////////////////////////////////////////////////////////

	// cleanup
	bool XMLDoc::Flush(){
		return GetRoot().Flush();
	}

	//////////////////////////////////////////////////////////////////////

	bool XMLDoc::StringParse(const WString& in,bool bValidate, bool bEraseEmpty,
		bool bDoNamespaces, XERCES_CPP_NAMESPACE_QUALIFIER ErrorHandler* pErrorHandler,
		const WString& schemaLocation){
			JDFParser p;
			bool b=p.StringParse( in, bValidate,  bEraseEmpty, bDoNamespaces, pErrorHandler,schemaLocation);
			*this=p.GetDocument();
			GetCreateXMLDocUserData();

			return b;
	}

	//////////////////////////////////////////////////////////////////////
	bool XMLDoc::StreamParse( InputStream& in,bool bValidate, bool bEraseEmpty,
		bool bDoNamespaces, XERCES_CPP_NAMESPACE_QUALIFIER ErrorHandler* pErrorHandler,
		const WString& schemaLocation){
			JDFParser p;
			bool b=p.StreamParse( in, bValidate,  bEraseEmpty, bDoNamespaces, pErrorHandler,schemaLocation);
			*this=p.GetDocument();
			GetCreateXMLDocUserData();

			return b;
	}


	//////////////////////////////////////////////////////////////////////
	bool XMLDoc::Parse(const WString& inFile,bool bValidate, bool bEraseEmpty,
		bool bDoNamespaces, XERCES_CPP_NAMESPACE_QUALIFIER ErrorHandler* pErrorHandler,
		const WString& schemaLocation, int nRetry, int waitMilliSecs){
			JDFParser p;
			bool b=p.Parse( inFile, bValidate,  bEraseEmpty, bDoNamespaces, pErrorHandler,schemaLocation, nRetry, waitMilliSecs);
			*this=p.GetDocument();
			GetCreateXMLDocUserData();

			return b;
	}


	//////////////////////////////////////////////////////////////////////
	bool XMLDoc::Parse(JDF::File inFile, bool bValidate, bool bEraseEmpty,
		bool bDoNamespaces, XERCES_CPP_NAMESPACE_QUALIFIER ErrorHandler* pErrorHandler,
		const WString& schemaLocation, int nRetry, int waitMilliSecs){
			JDFParser p;
			bool b=p.Parse(inFile, bValidate,  bEraseEmpty, bDoNamespaces, pErrorHandler,schemaLocation, nRetry, waitMilliSecs);
			*this=p.GetDocument();
			GetCreateXMLDocUserData();

			return b;
	}

	//////////////////////////////////////////////////////////////////////

	KElement XMLDoc::GetRoot(const WString& docRootString, const WString& docRootNS)const{
		if(throwNull())
			return KElement();
		KElement root=domDocument->getDocumentElement();
		if(docRootString.empty()&&docRootNS.empty()) 
			return root;
		if((!docRootString.empty())&&(root.GetLocalName()!=docRootString))
			throw JDFException(L"GetRoot: illegal root tag name: "+docRootString);
		if((!docRootNS.empty())&&(root.GetNamespaceURI()!=docRootNS))
			throw JDFException(L"GetRoot: illegal root namespace uri: "+docRootString);
		return root;

	}
	//////////////////////////////////////////////////////////////////////
	int XMLDoc::DecRef(){
		if(!domDocument)
			return 0;
		int* pRefCount=(int*)domDocument->getUserData(xmlDocRef);
		if(pRefCount==0 || *pRefCount<=1){ // one is left that is zero after decrement --> zapp
			DeleteAdopted();
			return 0;
		}else{
			(*pRefCount)--;
		}

		return *pRefCount;
	}
	//////////////////////////////////////////////////////////////////////
	int XMLDoc::IncRef(){
		if(!domDocument)
			return 0;
		int* pRefCount=(int*)domDocument->getUserData(xmlDocRef);
		if(pRefCount==0){
			pRefCount=new int;
			*pRefCount=1;
			domDocument->setUserData(xmlDocRef,(void*)pRefCount,0);
		}else{
			(*pRefCount)++;
		}
		return *pRefCount;
	}

	//////////////////////////////////////////////////////////////////////
	// mak esure taht it is set in a reasonable range
	void XMLDoc::setWriteRetry(int i)
	{
		writeRetry=i>0 ? i : 1;
		writeRetry=i<100 ? i : 100;
	}
	//////////////////////////////////////////////////////////////////////
	void XMLDoc::DeleteAdopted(){
		if(!isNull()){
			XMLDocUserData* ud=GetXMLDocUserData();
			if(ud)
				delete ud;

			int* pRefCount=(int*)domDocument->getUserData(xmlDocRef);
			delete pRefCount;
			domDocument->setUserData(xmlDocRef,0,0);
			delete domDocument;
			domDocument=0;
		}
	}

	//////////////////////////////////////////////////////////////////////

	KElement XMLDoc::SetRoot(const WString& docRootString, const WString& docRootNS){
		if(isNull()) {
			DOMImplementation* impl = DOMImplementation::getImplementation();
			domDocument= impl->createDocument();
			IncRef();
		}

		KElement root=domDocument->getDocumentElement();
		// create a new document root element
		if(root.isNull()){
			root=CreateElement(docRootString,docRootNS);
			domDocument->appendChild(root.domElement);
		}else{
			throw JDFException(L"SetRoot:  root already exists: ");
		}
		GetCreateXMLDocUserData();
		return root;
	}

	//////////////////////////////////////////////////////////////////////

	XMLDoc XMLDoc::clone(){
		if(isNull()) {
			return XMLDoc();
		}
		KElement root=GetRoot();

		XMLDoc clon(root.GetNodeName(),root.GetNamespaceURI());
		clon.GetRoot().ReplaceElement(root);
		return clon;
	}

	//////////////////////////////////////////////////////////////////////

	XMLDoc XMLDoc::Write2URL(const WString& strURL, const WString& strContentType, const WString& schemaLocation) const
	{
		XMLDoc docResponse;
		bool bValidate=!schemaLocation.empty();	
		try
		{
			JDF::URL url;

			url.setURL(strURL);
			WString protocol=url.getProtocol();
			if((protocol.compareToIgnoreCase(L"File")==0)||(protocol.empty())){ // either a file or relative

				// workaround for buggy url file handler
				WString path=url.getPath().UnEscape(L'%',16,2);
				if(path.empty()){
					throw JDFException(L"Write2URL: empty path variable in"+strURL);
				}
				if((path[0]==L'/')&&(path[2]==L':'))
					path=path.substr(1,path.npos);

				Write2File(path);
				// a file returns an empty response
				return docResponse;
			}

			JDF::Janitor<JDF::URLConnection> pURLConnection(url.openConnection());

			pURLConnection->setDoOutput(true);
			pURLConnection->setRequestProperty(L"Connection",   L"close");
			pURLConnection->setRequestProperty(L"Content-Type", strContentType);

			if (!Write2Stream(pURLConnection->getOutputStream()))
				return docResponse;

			JDF::JDFParser parser;

			JDF::PushbackInputStream pbin(pURLConnection->getInputStream(),6);
			char xmlHeader[6];
			memset(xmlHeader,0,6);
			int bytesRead = pbin.read(xmlHeader,5);
			// empty response?
			if (bytesRead == -1)
				return docResponse;

			// check if response is a valid xml response before parsing
			if (!::strcmp(xmlHeader,"<?xml"))
			{
				pbin.unread(xmlHeader,bytesRead);
				if (!parser.StreamParse(pbin, bValidate,true,true,0,schemaLocation))
					return docResponse;

				docResponse = parser.GetDocument();
			}
			else
				// not a valid xml response return empty doc
				return docResponse;
		}
		catch (const XMLException&)
		{
			throw JDFException(L"XMLDoc::Write2URL: error writing URL "+strURL);
		}
		catch (const JDF::Exception&)
		{
			throw JDFException(L"XMLDoc::Write2URL: error writing URL "+strURL);
		}

		return docResponse;
	}


	//////////////////////////////////////////////////////////////////////

	bool XMLDoc::Write2File(JDF::File outFile)const{
		WString outFileName = outFile.getAbsolutePath();
		return Write2File(outFileName);
	}

	//////////////////////////////////////////////////////////////////////

	bool XMLDoc::Write2File(const WString& outFile)const{
		writeRetry=writeRetry<1?1:writeRetry;
		writeRetry=writeRetry>100?100:writeRetry;

		for(int tryWrite=0;tryWrite<writeRetry;tryWrite++)
		{
			LocalFileFormatTarget *formTarget=0;
			try
			{
				formTarget = new LocalFileFormatTarget(outFile.c_str());
				bool bRet=Write2FormatTarget(formTarget,domDocument);
				delete formTarget;
				formTarget=0;
				if(bRet)
					return true;

			}
			catch (XMLException& e) 
			{
				if(tryWrite==writeRetry-1)
				{
					std::cerr << "An error occurred during creation or deletion of format target. Msg is:"
						<< std::endl<< WString(e.getMessage()) << std::endl;
				}
				else
				{
					std::cerr << "An error occurred during creation or deletion of format target. Msg is:"
						<< std::endl<< WString(e.getMessage()) << tryWrite<<std::endl;
					PlatformUtils::sleep(1000*(tryWrite+1));
				}
			}
			catch (...) 
			{
				if(tryWrite==writeRetry-1)
				{
					std::cerr << "An error occurred during creation or deletion of format target." << std::endl;
				}
				else
				{
					std::cerr << "An error occurred during creation or deletion of format target." << tryWrite<<std::endl;
					PlatformUtils::sleep(1000*(tryWrite+1));
				}
			}
			delete formTarget;
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////

	bool XMLDoc::Write2FormatTarget(XMLFormatTarget* formTarget,const DOMNode* node){
		writeRetry=writeRetry<1?1:writeRetry;
		writeRetry=writeRetry>100?100:writeRetry;

		for(int tryWrite=0;tryWrite<writeRetry;tryWrite++)
		{
			DOMWriter *theSerializer = 0;
			try 
			{
				// get a serializer, an instance of DOMWriter
				XMLCh tempStr[100];
				XMLString::transcode("LS", tempStr, 99);
				DOMImplementation *impl          = DOMImplementationRegistry::getDOMImplementation(tempStr);
				theSerializer = ((DOMImplementationLS*)impl)->createDOMWriter();


				if (theSerializer->canSetFeature(XMLUni::fgDOMWRTFormatPrettyPrint, true))
					theSerializer->setFeature(XMLUni::fgDOMWRTFormatPrettyPrint, !compressPrint);

				XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument* document=node->getOwnerDocument();
				if(document==0 && node->getNodeType()==KElement::DOCUMENT_NODE)
				{
					document=(DOMDocument*) node;
				}
				if(document)
				{
					const XMLCh* encoding = document->getEncoding();
					WString wStrEncoding = L"UTF-16";
					if (encoding != NULL && (wStrEncoding.compareToIgnoreCase(encoding) == 0) &&
						theSerializer->canSetFeature(XERCES_CPP_NAMESPACE::XMLUni::fgDOMWRTBOM, true))
					{
						theSerializer->setFeature(XERCES_CPP_NAMESPACE::XMLUni::fgDOMWRTBOM, true);
						theSerializer->setEncoding(encoding);
					}
				}

				//
				// do the serialization through DOMWriter::writeNode();
				//

				theSerializer->writeNode(formTarget, *node);
				delete theSerializer;
				return true;

			} 
			catch (XMLException& e) 
			{
				if(tryWrite==writeRetry-1)
				{
					std::cerr << "An error occurred during creation of output transcoder. Msg is:"
						<< std::endl<< WString(e.getMessage()) << std::endl;
				}
				else
				{
					std::cerr << "An error occurred during creation of output transcoder. Msg is:"
						<< std::endl<< WString(e.getMessage()) << " "<<tryWrite<< std::endl;
					PlatformUtils::sleep(1000*(tryWrite+1));
				}
			}
			catch (...) 
			{
				if(tryWrite==writeRetry-1)
				{
					std::cerr << "An unknown error occurred during creation of output transcoder. " << std::endl;
				}
				else
				{
					std::cerr << "An unknown error occurred during creation of output transcoder. " << tryWrite<<std::endl;
					PlatformUtils::sleep(1000*(tryWrite+1));
				}
			}
			delete theSerializer; // always zapp also in case of snafu
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////

	bool XMLDoc::Write2Stream(JDF::OutputStream& out)const{

		MemBufFormatTarget *formTarget = new MemBufFormatTarget();
		bool bRet=Write2FormatTarget(formTarget,domDocument);
		out.write((const char*) formTarget->getRawBuffer(),formTarget->getLen());
		delete formTarget;
		return bRet;

	}
	//////////////////////////////////////////////////////////////////////

	bool XMLDoc::Write2String(JDF::WString& out)const{
		if(!domDocument){ // return an empty string if this is a null object
			out.erase();
			return false;
		}
		MemBufFormatTarget *formTarget = new MemBufFormatTarget();
		bool bRet=Write2FormatTarget(formTarget,domDocument);
		out.SetUTF8Bytes((const char*)formTarget->getRawBuffer());
		delete formTarget;
		return bRet;
	}
	//////////////////////////////////////////////////////////////////////

	JDF::WString XMLDoc::ToString()const{
		WString s;
		Write2String(s);
		return s;
	}

	//////////////////////////////////////////////////////////////////////


	/////////////////////////////////////////////////////////////////

	KElement XMLDoc::CreateElement(const WString& tagName,const WString& nameSpaceURI){
		if(nameSpaceURI.empty()){
			return domDocument->createElement(tagName.c_str());
		}else{
			return domDocument->createElementNS(nameSpaceURI.c_str(),tagName.c_str());
		}
	};
	/////////////////////////////////////////////////////////////////


	/**
	* get the associated XMLDocUserData
	* @throw JDFException if no XMLDocUserData is set or this is NULL
	* @return the XMLDocUserData of this
	*/
	XMLDocUserData* XMLDoc::GetXMLDocUserData()const{
		if(isNull()){
			return 0;
			// the exception causes problems for people who build nodes in thin air before attaching them to a document
			// throw JDFException(L"XMLDoc::GetXMLDocUserData: used on Null document");
		}
		XMLDocUserData* pUserData=(XMLDocUserData*)domDocument->getUserData(L"JDFTargetDirty");
		return pUserData;
	}

	/**
	* get the associated XMLDocUserData
	* @throw JDFException if no XMLDocUserData is set or this is NULL
	* @return the XMLDocUserData of this
	*/
	XMLDocUserData* XMLDoc::GetXMLDocUserData(XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument* pDomDocument){
		if(pDomDocument==0){
			return 0;
			// the exception causes problems for people who build nodes in thin air before attaching them to a document
			// throw JDFException(L"XMLDoc::GetXMLDocUserData: used on Null document");
		}
		XMLDocUserData* pUserData=(XMLDocUserData*)pDomDocument->getUserData(L"JDFTargetDirty");
		return pUserData;
	}

	/**
	* does the owner document of this have an associated XMLDocUserData
	* @throw JDFException if no XMLDocUserData is set or this is NULL
	* @return true if XMLDocUserData of this exists
	*/
	bool XMLDoc::HasXMLDocUserData()const{
		if(isNull()){
			throw JDFException(L"XMLDoc::GetXMLDocUserData: used on Null document");
		}
		XMLDocUserData* pUserData=(XMLDocUserData*)domDocument->getUserData(L"JDFTargetDirty");
		return pUserData!=0;
	}

	/**
	* get/create the associated XMLDocUserData
	* @throw JDFException if is NULL
	* @return the XMLDocUserData of this
	*/
	XMLDocUserData* XMLDoc::GetCreateXMLDocUserData(){
		if(isNull()){
			throw JDFException(L"XMLDoc::GetXMLDocUserData: used on Null document");
		}
		XMLDocUserData* pUserData=(XMLDocUserData*)domDocument->getUserData(L"JDFTargetDirty");
		if(pUserData==0){
			pUserData=new XMLDocUserData();
			domDocument->setUserData(L"JDFTargetDirty",pUserData,0);
		}
		return pUserData;
	}

	/**
	* delete the XMLDocUserData structure
	* @return void
	*/
	void XMLDoc::DeleteUserData(){
		if(throwNull())
			return;
		XMLDocUserData* pUserData=(XMLDocUserData*)domDocument->getUserData(L"JDFTargetDirty");
		if(pUserData==0)
			return;
		delete(pUserData);
		domDocument->setUserData(L"JDFTargetDirty",0,0);
	};

	/**
	* get a vector of all IDs of elements that are dirty
	* @return vWString the vector of element IDs
	*/
	const vWString& XMLDoc::GetDirtyIDs()const{
		return GetXMLDocUserData()->GetDirtyIDs();
	};
	/**
	* get a vector of all IDs of elements that are dirty
	* @return vWString the vector of element IDs
	*/
	const vWString& XMLDoc::GetDirtyXPaths()const{
		return GetXMLDocUserData()->GetDirtyXPaths();
	};

	///////////////////////////////////////////////////////////////////
	XMLDoc XMLDoc::GetDirtyDiff()const{
		vWString vs=GetXMLDocUserData()->GetDirtyXPaths();
		XMLDoc diffDoc(L"Diffs");
		vWString DummyNS;
		KElement root=diffDoc.GetRoot();
		KElement docRoot=GetRoot();
		for(int i=0;i<vs.size();i++){
			KElement eDif=root.AppendElement(L"Dif");
			WString path=vs[i];
			if(path.endsWith(L"/@")){
				path=path.leftStr(-2);
				KElement e=docRoot.GetXPathElement(path);
				vWString atts=e.GetAttributeVector();
				for(int ii=0;ii<atts.size();ii++){
					WString prefix=KElement::XMLNSPrefix(atts[ii].c_str());
					if(!prefix.empty()){
						DummyNS.AppendUnique(prefix);
					}
				}
				eDif.AppendElement(L"Attributes").SetAttributes(e);
				eDif.SetAttribute(L"XPath",e.GetXPath());
				eDif.SetAttribute(L"elem",false);
			}else{
				KElement e=docRoot.GetXPathElement(path);
				KElement eNew=eDif.CopyElement(e);
				eDif.SetAttribute(L"XPath",e.GetXPath());
				eDif.SetAttribute(L"elem",true);
			}
		}
		for(int j=0;j<DummyNS.size();j++)
			root.AddNameSpace(DummyNS[j],L"NS"+WString(j));
		return diffDoc;
	};

	///////////////////////////////////////////////////////////////////
	void XMLDoc::SetDirtyDiff(const XMLDoc &diffDoc){
		KElement diffRoot=diffDoc.GetRoot();
		KElement root=GetRoot();
		if(diffRoot.GetNodeName()!="Diffs"){
			throw JDFException(L"SetDirtyDiff: illegal root tag name: "+root.GetNodeName());
		}

		vElement vDifs=diffRoot.GetChildElementVector(L"Dif");
		if(root.isNull()&&!vDifs.empty()){
			WString rootString=vDifs[0].GetAttribute(L"XPath");
			rootString=rootString.substring(rootString.find(L"/")+1,rootString.find(L"/",2));
			SetRoot(rootString);
			root=GetRoot();

		}
		for(int i=0;i<vDifs.size();i++){
			KElement newDif=vDifs[i];
			WString path=newDif.GetAttribute(L"XPath");
			KElement oldElm=root.GetCreateXPathElement(path);
			if(newDif.GetAttribute(L"elem")==L"false"){
				KElement e=root.GetXPathElement(path);
				oldElm.RemoveAttributes();
				oldElm.SetAttributes(newDif.GetElement(L"Attributes"));
			}else{
				oldElm.ReplaceElement(newDif.GetElement(WString::star));
				oldElm=root.GetXPathElement(path);
				oldElm.EraseEmptyNodes();
			}
		}
	}
	///////////////////////////////////////////////////////////////////
	/**
	* clear the vector of all IDs of elements that are dirty
	* @return void
	*/
	void XMLDoc::ClearDirtyIDs(){
		XMLDocUserData* pUserData=GetXMLDocUserData();
		if(pUserData)
			pUserData->ClearDirtyIDs();
	};

	/**
	* clear the vector of all IDs of elements that are dirty
	* @param WString id the id to be added to the dirty list
	* @return vWString the vector of element IDs
	*/
	const vWString& XMLDoc::SetDirty(const WString &id){
		return GetCreateXMLDocUserData()->SetDirty(id);
	}

	/**
	* is the node with ID dirty?
	* @param WString id the id to be checked
	* @return bool true if the node with ID=id is dirty
	*/
	bool XMLDoc::IsDirty(const WString &id)const{
		return GetXMLDocUserData()->IsDirty(id);
	}

	/**
	* Remove the target from the target list
	* @param KElement target the target element
	*/
	void XMLDoc::RemoveTarget(const KElement& target){
		GetCreateXMLDocUserData()->RemoveTarget(target);
	}

	/**
	* Set the target with to target
	* @param KElement target the target element
	*/
	void XMLDoc::SetTarget(const KElement& target, const WString &id){
		GetCreateXMLDocUserData()->SetTarget(target, id);
	}

	/**
	* Get the target with ID=id
	* @param WString id the id of the target to search 
	* @return KElement target the target element
	*/
	KElement XMLDoc::GetTarget(const WString& id)const{
		return GetXMLDocUserData()->GetTarget(id);
	}


	/**
	* clear the map of all targets
	* @return void
	*/
	void XMLDoc::ClearTargets(){
		XMLDocUserData* pUserData=GetXMLDocUserData();
		if(pUserData)
			pUserData->ClearTargets();
	}

	/////////////////////////////////////////////////
	void XMLDoc::setDefaultIgnoreNS(bool bIgnore)
	{
		setIgnoreNSDefault=bIgnore;
	}

	/////////////////////////////////////////////////
	bool XMLDoc::getDefaultIgnoreNS()
	{
		return setIgnoreNSDefault;
	}
	/////////////////////////////////////////////////
	void XMLDoc::setGenerateUID(bool bGenerateUID)
	{
		generateUID=bGenerateUID;
	}

	/////////////////////////////////////////////////
	bool XMLDoc::getGenerateUID()
	{
		return generateUID;
	}

	/////////////////////////////////////////////////
	void XMLDoc::setCompressOutput(bool bCompressPrint)
	{
		compressPrint=bCompressPrint;
	}

	/////////////////////////////////////////////////
	bool XMLDoc::getCompressOutput()
	{
		return compressPrint;
	}

	//////////////////////////////////////////////////////////////////////
	JDF_WRAPPERCORE_EXPORT std::ostream& operator<<(std::ostream& target, const JDF::XMLDoc& toWrite){
		return target<<toWrite.ToString();
	}
	//////////////////////////////////////////////////////////////////////
} // namespace JDF


