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
//
// JDFDoc.cpp: implementation of the JDFDoc class.
//
//////////////////////////////////////////////////////////////////////

#include "JDFDoc.h"
#include "JDFJMF.h"
#include "JDFNode.h"
#include "JDFResourcePool.h"
#include <jdf/io/File.h>

#include <jdf/mime/MIMEMessage.h>
#include <jdf/mime/MIMEMessagePart.h>
#include <jdf/mime/MIMEBasicPart.h>
#include <jdf/mime/MIMEMultiPart.h>

using namespace std;
XERCES_CPP_NAMESPACE_USE

namespace JDF{

	//////////////////////////////////////////////////////////////////////
	// Construction/Destruction
	//////////////////////////////////////////////////////////////////////

	JDFDoc::JDFDoc(int docType)
		:XMLDoc()
	{
		WString docRootString;
		WString docRootNS;
		if(docType==0){
			docRootString=JDFElement::elm_JDF;
		}else if(docType==1){
			docRootString=JDFElement::elm_JMF;
		}else{
			throw JDFException(L"JDFDoc::JDFDoc: unknown doc type");
		}
		docRootNS=JDFElement().GetSchemaURL(1,2);
		KElement r=SetRoot(docRootString,docRootNS);
		if(docType==0){
			JDFNode(r).init(true);
		}else if(docType==1){
			JDFJMF(r).init();
		}
		// a bug in xerces causes an unitialized doc to crash when setting the user data to 0
		//setUserData(0);
	}

	//////////////////////////////////////////////////////////////////////

	/**
	* copy ctor
	*/
	JDFDoc::JDFDoc(DOMDocument* D):XMLDoc(D){}
	//////////////////////////////////////////////////////////////////////

	/**
	* copy ctor
	*/
	JDFDoc::JDFDoc(const XMLDoc& D):XMLDoc(D){}

	//////////////////////////////////////////////////////////////////////
	/**
	* dtor
	*/
	JDFDoc::~JDFDoc(){}


	//////////////////////////////////////////////////////////////////////
	JDFDoc& JDFDoc::operator =(const XMLDoc& other){
		return (JDFDoc&) XMLDoc::operator=(other);
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* copy ctor
	*/
	JDFDoc& JDFDoc::operator =(DOMDocument* other){
		return (JDFDoc&) XMLDoc::operator=(other);
	};

	//////////////////////////////////////////////////////////////////////

	JDFNode JDFDoc::GetJDFRoot(){
		KElement r=GetRoot();
		if(r.GetLocalName()==JDFElement::elm_JDF) 
			return r;

		return r.GetChildByTagName(JDFElement::elm_JDF,JDFElement::GetSchemaURL(1,1),0,MapWString::emptyMap,false);
	}

	//////////////////////////////////////////////////////////////////////

	JDFJMF JDFDoc::GetJMFRoot(){
		KElement r=GetRoot();
		if(r.GetLocalName()==JDFElement::elm_JMF) 
			return r;

		return r.GetChildByTagName(JDFElement::elm_JMF,JDFElement::GetSchemaURL(1,1),0,MapWString::emptyMap,false);
	}

	//////////////////////////////////////////////////////////////////////

	JDFNode JDFDoc::GetJDFNodeByID(const WString & ID)const{
		return GetRoot().GetTarget(ID);
	}
	//////////////////////////////////////////////////////////////////////////////////////////////

	int JDFDoc::CollectGarbageResources(const vWString & nodeNames){
		bool bCollectAll=nodeNames.empty();

		vElement vProcs=GetJDFRoot().GetvJDFNode();
		vElement vResources;
		vElement vLinkedResources;
		// loop over all jdf nodes
		int i;
		for(i=0;i<vProcs.size();i++){
			int j;
			JDFNode n=vProcs[i];
			vLinkedResources.AppendUnique(n.GetLinkedResources(mAttribute(),true));

			JDFResourcePool rp=n.GetResourcePool();
			vElement resources=rp.GetPoolChildren();
			vResources.AppendUnique(resources);
			for(j=0;j<resources.size();j++){
				vResources.AppendUnique(JDFResource(resources[j]).GetvHRefRes(true));
			}			
		}
		vElement vr;
		for(i=0;i<vResources.size();i++){
			vr.AppendUnique(JDFResource(vResources.at(i)).GetResourceRoot());
		}
		vResources=vr;
		vr.clear();
		for(i=0;i<vLinkedResources.size();i++){
			vr.AppendUnique(JDFResource(vLinkedResources.at(i)).GetResourceRoot());
		}
		vLinkedResources=vr;

		int nDeleted=0;
		for(i=0;i<vResources.size();i++){
			JDFResource r=vResources[i];
			if(!vLinkedResources.hasElement(r)){
				if(bCollectAll||nodeNames.hasString(r.GetLocalName())){
					r.DeleteNode();
					nDeleted++;
				}
			}
		}
		return nDeleted;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////

	WString JDFDoc::GetContentType() const{
		JDFElement e=GetRoot();
		WString strNodeName=e.GetLocalName();
		WString strContentType;

		if (strNodeName == JDFElement::elm_JDF){
			strContentType = L"application/vnd.cip4-jdf+xml";
		}else if (strNodeName ==JDFElement::elm_JMF){
			strContentType = L"application/vnd.cip4-jmf+xml";
		}else{
			throw JDFException(L"JDFDoc::GetContentType - illegal root element "+strNodeName);
		}
		return strContentType;
	}

	//////////////////////////////////////////////////////////////////////

	JDFDoc JDFDoc::Write2URL(const WString& strURL, const WString& schemaLocation) const{

		return XMLDoc::Write2URL(strURL,GetContentType(),schemaLocation);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFDoc::StringParse(const WString& in,bool bValidate, bool bEraseEmpty,
		bool bDoNamespaces, XERCES_CPP_NAMESPACE_QUALIFIER ErrorHandler* pErrorHandler,
		const WString& schemaLocation){
			bool b=XMLDoc::StringParse( in, bValidate,  bEraseEmpty, bDoNamespaces, pErrorHandler,schemaLocation);
			GetJDFRoot().GetMinID();
			return b;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFDoc::StreamParse( InputStream& in,bool bValidate, bool bEraseEmpty,
		bool bDoNamespaces, XERCES_CPP_NAMESPACE_QUALIFIER ErrorHandler* pErrorHandler,
		const WString& schemaLocation){
			bool b=XMLDoc::StreamParse( in, bValidate,  bEraseEmpty, bDoNamespaces, pErrorHandler,schemaLocation);
			GetJDFRoot().GetMinID();
			return b;
	}


	//////////////////////////////////////////////////////////////////////

	bool JDFDoc::Parse(const WString& inFile,bool bValidate, bool bEraseEmpty,
		bool bDoNamespaces, XERCES_CPP_NAMESPACE_QUALIFIER ErrorHandler* pErrorHandler,
		const WString& schemaLocation){
			bool b=XMLDoc::Parse( inFile, bValidate,  bEraseEmpty, bDoNamespaces, pErrorHandler,schemaLocation);
			GetJDFRoot().GetMinID();
			return b;
	}


	//////////////////////////////////////////////////////////////////////

	bool JDFDoc::Parse(JDF::File inFile, bool bValidate, bool bEraseEmpty,
		bool bDoNamespaces, XERCES_CPP_NAMESPACE_QUALIFIER ErrorHandler* pErrorHandler,
		const WString& schemaLocation){
			bool b=XMLDoc::Parse(inFile, bValidate,  bEraseEmpty, bDoNamespaces, pErrorHandler,schemaLocation);
			GetJDFRoot().GetMinID();
			return b;
	}

	//////////////////////////////////////////////////////////////////////

	MIMEMessage* JDFDoc::CreateMIMEMessage() const{

		JDF::MIMEBasicPart* mbp = CreateMIMEBasicPart();
		MIMEMultiPart *mmp = new JDF::MIMEMultiPart();
		mmp->addBodyPart(mbp, false); // false->don't clone it
		mmp->setContentSubType(L"related");


		// make a MIMEMessage out of it
		MIMEMessage* mmsg = new JDF::MIMEMessage();
		mmsg->setBody(mmp,false);

		return mmsg;
	}
	//////////////////////////////////////////////////////////////////////

	MIMEBasicPart* JDFDoc::CreateMIMEBasicPart() const{
		JDF::MIMEBasicPart* mbp = new JDF::MIMEBasicPart (MIMEBasicPart::APPLICATION);
		WString docString;
		Write2String(docString);
		mbp->setBodyData (docString);
		mbp->setContentSubType(GetContentType().substr(12));

		return mbp;
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

}
