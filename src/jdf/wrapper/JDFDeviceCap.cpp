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
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
//      ALL RIGHTS RESERVED 
//
//  Authors: Dr. Rainer Prosi, Elena Skobchenko
// 
// Revision history:
// created  08.07.2002
//
// JDFDeviceCap.cpp: implementation of the JDFDeviceCap 
//
//////////////////////////////////////////////////////////////////////

 
#include "JDFDeviceCap.h"
#include "JDFDevCapPool.h"
#include "JDFModulePool.h"
#include "JDFActionPool.h"
#include "JDFTestPool.h"
#include "JDFDevCaps.h"
#include "JDFAction.h"
#include "JDFTest.h"
#include "JDFCustomerInfo.h"
#include "xercesc/util/regx/RegularExpression.hpp"

XERCES_CPP_NAMESPACE_USE
namespace JDF{
/**
* copy equivalance operator
*/
	JDFDeviceCap& JDFDeviceCap::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFDeviceCap: "+other.GetNodeName());
	return *this;
};

	/////////////////////////////////////////////////////////////////////

	WString JDFDeviceCap::OptionalElements()const{
		return JDFAutoDeviceCap::OptionalElements()+L",DevCapPool,ModulePool";
	};

	/////////////////////////////////////////////////////////////////////

	vWString JDFDeviceCap::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFAutoDeviceCap::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;

		nElem=NumChildElements(elm_DevCapPool);

		if (nElem>1) {
			vElem.push_back(elm_DevCapPool);
			if (++n>=nMax) return vElem;
		}
		for(i=0;i<nElem;i++){
			if (!GetDevCapPool().IsValid(level)) {
				vElem.AppendUnique(elm_DevCapPool);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ModulePool);

		if (nElem>1) {
			vElem.push_back(elm_ModulePool);
			if (++n>=nMax) return vElem;
		}
		for(i=0;i<nElem;i++){
			if (!GetModulePool().IsValid(level)) {
				vElem.AppendUnique(elm_ModulePool);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};

	/////////////////////////////////////////////////////////////////////////
	
	WString JDFDeviceCap::GetTypeExpression() const{
		if (HasAttribute(atr_TypeExpression)) {
			return JDFAutoDeviceCap::GetTypeExpression();
		}
		return GetAttribute(atr_Types);
	}
	
	/////////////////////////////////////////////////////////////////////
	JDFDevCapPool JDFDeviceCap::GetCreateDevCapPool(){
		JDFDevCapPool e=GetCreateElement(elm_DevCapPool,WString::emptyStr);
		e.init();	
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFDevCapPool JDFDeviceCap::GetDevCapPool()const{
		return GetElement(elm_DevCapPool,WString::emptyStr);
	};

	/////////////////////////////////////////////////////////////////////
	
	JDFDevCapPool JDFDeviceCap::AppendDevCapPool(){
		JDFDevCapPool e=AppendElementN(elm_DevCapPool,1);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFModulePool JDFDeviceCap::GetCreateModulePool(){
		JDFModulePool e=GetCreateElement(elm_ModulePool,WString::emptyStr);
		e.init();	
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFModulePool JDFDeviceCap::GetModulePool()const{
		return GetElement(elm_ModulePool,WString::emptyStr);
	};

	/////////////////////////////////////////////////////////////////////
	
	JDFModulePool JDFDeviceCap::AppendModulePool(){
		JDFModulePool e=AppendElementN(elm_ModulePool,1);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////////
	
	vElement JDFDeviceCap::GetExecutableJDF(const JDFNode& jdfRoot, EnumFitsValue testlists, EnumValidationLevel level) const {
		
		vElement execNodes;
		WString typeNode = jdfRoot.GetType();
		EnumExecutionPolicy execPolicy = GetExecutionPolicy();
		bool bExit = false;
		if (execPolicy==ExecutionPolicy_RootNode)	
		{
			if (typeNode!=(L"Product")) 
			{
				XMLDoc doc;
				bool bException = false;
				try {
					doc = Report(jdfRoot,testlists, level);
				}
				catch (JDFException&) {
					bException = true; // if Report throws exception - 'jdfRoot' is non-executable Node 
				}
				if (doc.isNull() && !bException)
                {
					if (typeNode==(L"ProcessGroup")) 
					{
						vJDFNode vNodes =jdfRoot.GetvJDFNode(WString::emptyStr);
						for (int i=0; i<vNodes.size()-1 && !bExit; i++) 
						{ // test if all children of ProcessGroup fit DevCaps. Type was already tested for a whole Node
							if (!DevCapsReport(vNodes[i], testlists, level).isNull())
							{
								bExit = true;
							}
						}
					}
					if (!bExit)
						execNodes.push_back(jdfRoot);
				}
			}
		}
		else
		{
			// here vNodes is jdfRoot + all children
			vJDFNode vNodes=jdfRoot.GetvJDFNode(WString::emptyStr);
			for (int i=0; i<vNodes.size(); i++) {
				JDFNode n=vNodes[i];
				typeNode = n.GetType();
				XMLDoc nOutput;
				bool bException = false;
				try {
					nOutput = Report(n,testlists,level);
				}
				catch (JDFException&) {
					bException = true; // if Report throws exception - 'n' is non-executable Node 
				}
				if (nOutput.isNull() && !bException)
                { // to the executable add only the "highest" executable product/processGroup node
					if (typeNode==(L"Product") || typeNode==(L"ProcessGroup")) {
						JDFNode parent = n.GetParentJDF();
						if (parent.isNull() || parent.GetType()!=typeNode) {
							execNodes.push_back(n); // 'n' is already the highest product/processGroup node
						}
						else
						{
							XMLDoc parentOutput;
							bool bCaughtException = false;
							try {
								parentOutput = Report(parent, testlists, level);
							}
							catch (JDFException&) {
								bCaughtException = true; // 'n' is executable, 'parent' is not - append 'n' to execNodes 
							}
							if (parentOutput.isNull() && !bCaughtException){
								execNodes.push_back(n); 
							}
						}
					}
					else 
					{
						execNodes.push_back(n);
					}
				}
			}
		}
		return execNodes;
	}

	/////////////////////////////////////////////////////////////////////////
	XMLDoc JDFDeviceCap::GetBadJDFInfo(const JDFNode& jdfRoot, EnumFitsValue testlists, EnumValidationLevel level) const {
		
		XMLDoc bugReport = XMLDoc("BugReport");
		KElement outputRoot = bugReport.GetRoot();
		
		vJDFNode vNodes = jdfRoot.GetvJDFNode(""); // in GetvJDFNode("") 3-d attr is false -> I take root as well
		for (int i=0; i<vNodes.size(); i++) {
			JDFNode n = vNodes[i];
			XMLDoc rejectedNodeReport;
			try
			{
				rejectedNodeReport = Report(n, testlists, level);
			}
			catch (JDFException& jdfe)
			{
				KElement e = outputRoot.AppendElement("RejectedNode");
				e.SetAttribute("CaughtException", jdfe.getMessage());
                e.SetAttribute("XPath", n.GetXPath());
			}
			if (!outputRoot.isNull())
			{
				outputRoot.CopyElement(rejectedNodeReport.GetRoot());
			}
		}
		if (!outputRoot.HasChildElements())
			bugReport = XMLDoc();
		return bugReport;
	}

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	XMLDoc JDFDeviceCap::Report(const JDFNode& jdfRoot, EnumFitsValue testlists, EnumValidationLevel level) const {

		XMLDoc testResult = XMLDoc("RejectedNode");
		KElement root = testResult.GetRoot();
		root.SetAttribute("XPath",jdfRoot.GetXPath());

		if (!jdfRoot.IsValid(level)) {
			root.SetAttribute("IsValid", false);
			return testResult;
		}
		
		WString typeNode = jdfRoot.GetType();
		vint vcombMethod = GetCombinedMethod();
		for(int i=0;i<vcombMethod.size();i++)
		{
			EnumCombinedMethod combMethod = (EnumCombinedMethod)vcombMethod[i];

		switch (combMethod) {

			case CombinedMethod_None: { // node is an individual process

				WString typeExpStr = GetTypeExpression();
				if(typeExpStr.Tokenize().size()!=1)
					throw JDFException (L"JDFDeviceCap::Report: Invalid DeviceCap - illegal value of Types(TypeExpression) attribute");

				RegularExpression typeExp(typeExpStr.c_str());
				if (!typeExp.matches(typeNode.c_str())) {
					root.SetAttribute("FitsType", false);
					return testResult;
				}
				
				if (typeNode==L"Product") {
					testResult = ProductReport(jdfRoot,testlists,level);
				}
				else {
					XMLDoc devCapsTestResult = DevCapsReport(jdfRoot,testlists,level);
					if (!devCapsTestResult.isNull()) 
					{
						root.SetAttribute("FitsType",true);
						MoveChildElementVector(root,devCapsTestResult.GetRoot());
					}
				}
				break;
			}
			case CombinedMethod_Combined: {
				if (typeNode == L"Combined") {
					testResult = CombinedNodeReport(jdfRoot,testlists,level);
				} else {
					root.SetAttribute("FitsType",false);
				}
				break;
			}
			case CombinedMethod_ProcessGroup: {
				if (typeNode == L"ProcessGroup") {
					testResult = ProcessGroupReport(jdfRoot,testlists,level);
				}else {
					root.SetAttribute("FitsType",false);
				}
				break;
			} 
			case CombinedMethod_CombinedProcessGroup: {
				if ((typeNode == L"ProcessGroup")||(typeNode == L"Combined")) {
					if (typeNode == L"ProcessGroup") {
						testResult = ProcessGroupReport(jdfRoot,testlists,level);
					}
					else {
						testResult = CombinedNodeReport(jdfRoot,testlists,level);
					}
				}else {
					root.SetAttribute("FitsType",false);
				}
				break;
			}
			// __Lena__ case CombinedMethod_GrayBox: {return true;}
			default: {
				throw JDFException (L"JDFDeviceCap::Report: Invalid DeviceCap - illegal value of CombinedMethod attribute"); 
			}
		}
		}
		if (!testResult.isNull()){
			root = testResult.GetRoot();

			if (!root.HasChildElements() && !root.HasAttribute("FitsType"))
				testResult = XMLDoc();
		}

		return testResult;

	}
	
	/////////////////////////////////////////////////////////////////////////
	XMLDoc JDFDeviceCap::ProductReport(const JDFNode& jdfRoot, EnumFitsValue testlists, EnumValidationLevel level) const{
		
		XMLDoc testResult = XMLDoc("RejectedNode");
		KElement root = testResult.GetRoot();
		root.SetAttribute("XPath",jdfRoot.GetXPath());
		root.SetAttribute("FitsType",true);

		XMLDoc devCapsTestResult;
		
		// check the status of all child jdf intent product nodes
		vJDFNode vNodes= jdfRoot.GetvJDFNode(L"Product");
		for (int i=0; i<vNodes.size()-1; i++) {
			JDFNode n=vNodes[i];
			devCapsTestResult=DevCapsReport(n,testlists,level);
			if (!devCapsTestResult.isNull()) {
				KElement childRoot = root.AppendElement("RejectedChildNode");
                childRoot.SetAttribute("XPath", n.GetXPath());
				MoveChildElementVector(childRoot,devCapsTestResult.GetRoot());
			}
		}

		devCapsTestResult = DevCapsReport(jdfRoot,testlists,level);
		if (!devCapsTestResult.isNull()) 
		{
			MoveChildElementVector(root,devCapsTestResult.GetRoot());
		}
		if(!root.HasChildElements())
			testResult = XMLDoc();

		return testResult;
	}

	/////////////////////////////////////////////////////////////////////////
	bool JDFDeviceCap::FitsTypes(const vWString& typesNode) const{
		
		if (typesNode.empty())
			return false; // __Lena__ false ?

		WString typesNodeStr = typesNode.GetString();
		vWString types = typesNode;
		WString typeExpStr = GetTypeExpression();
		if (typeExpStr.empty()) {
			throw JDFException (L"JDFDeviceCap::FitsTypes: Invalid DeviceCap - missing attributes Types and TypeExpression");
		}
		RegularExpression typeExp(typeExpStr.c_str());
		
		if (HasAttribute(atr_TypeExpression)) {
			if (!typeExp.matches(typesNodeStr.c_str()))
				return false;
		}
		else {
			for (int i=0; i<types.size(); i++) {
				WString type = types[i];
				if (!GetTypes().hasString(type)) 
					return false;
			}
		}
		return true;
	}

	/////////////////////////////////////////////////////////////////////////
	XMLDoc JDFDeviceCap::CombinedNodeReport(const JDFNode& jdfRoot, EnumFitsValue testlists, EnumValidationLevel level) const{
		
		XMLDoc testResult = XMLDoc("RejectedNode");
		KElement root = testResult.GetRoot();
		root.SetAttribute("XPath",jdfRoot.GetXPath());

		vWString typesNode = jdfRoot.GetTypes();
		bool bWrongType = !FitsTypes(typesNode);
		if (bWrongType) {
			root.SetAttribute("FitsType", false);
		} else {
			root.SetAttribute("FitsType", true);
			XMLDoc devCapsTestResult = DevCapsReport(jdfRoot,testlists,level);
			if (!devCapsTestResult.isNull()) 
			{
				MoveChildElementVector(root,devCapsTestResult.GetRoot());
			}
		}
		if(!root.HasChildElements() && root.GetBoolAttribute("FitsType",WString::emptyStr,true))
			testResult = XMLDoc();

		return testResult;
	}

	/////////////////////////////////////////////////////////////////////////
	XMLDoc JDFDeviceCap::ProcessGroupReport(const JDFNode& jdfRoot,  EnumFitsValue testlists, EnumValidationLevel level) const{

		XMLDoc testResult = XMLDoc("RejectedNode");
		KElement root = testResult.GetRoot();
		root.SetAttribute("XPath",jdfRoot.GetXPath());

		vWString typesNode;
		try {
			typesNode = GetProcessGroupTypeVector(jdfRoot);
		}
		catch (JDFException& jdfe){
            root.SetAttribute("FitsType", false);
            root.SetAttribute("Message", jdfe.getMessage());
            return testResult;
        }

		XMLDoc devCapsTestResult;
		bool bWrongType = !FitsTypes(typesNode);
		if (bWrongType) {
			root.SetAttribute("FitsType", false);
		}else {
			root.SetAttribute("FitsType", true);

			// check the status of all child nodes
			vJDFNode vNodes= jdfRoot.GetvJDFNode();
			for (int i=0; i<vNodes.size()-1; i++) {
				JDFNode n = vNodes[i];
				devCapsTestResult=DevCapsReport(n,testlists,level);
				if (!devCapsTestResult.isNull()) {
					KElement childRoot = root.AppendElement("RejectedChildNode");
					childRoot.SetAttribute("XPath", n.GetXPath());
					MoveChildElementVector(childRoot,devCapsTestResult.GetRoot());
				}
			}
		}
		devCapsTestResult = DevCapsReport(jdfRoot,testlists,level);
		if (!devCapsTestResult.isNull()) 
		{
			MoveChildElementVector(root,devCapsTestResult.GetRoot());
		}
		if(!root.HasChildElements() && root.GetBoolAttribute("FitsType",WString::emptyStr,true))
			testResult = XMLDoc();

		return testResult;
	}

	/////////////////////////////////////////////////////////////////////////

	vWString JDFDeviceCap::GetProcessGroupTypeVector(const JDFNode& jdfRoot) const{
	
		vJDFNode vNodes = jdfRoot.GetvJDFNode(WString::emptyStr,JDFNode::Activation_Unknown,true);
		vWString types;
		vWString vs = jdfRoot.GetTypes();
		if (!vs.empty()) {
			if (!vNodes.empty()) {
				throw JDFException (L"JDFDeviceCap::GetProcessGroupTypeVector illegal combination of the attribute 'Types' and child JDF Nodes");
			}
			types.AppendUnique(vs);// __Lena__  May contain GrayBoxes
		}
		else {
			for (int i=0; i<vNodes.size(); i++) {
				JDFNode node = vNodes[i];
				WString type = node.GetType();
				if (type == L"ProcessGroup") {
					types.AppendUnique(GetProcessGroupTypeVector(node));
				}
				else if (type == L"Combined") {
					types.AppendUnique(node.GetTypes());
				}
				else {
					types.AppendUnique(type);
				}
			}
		}
		return types;
	}
	/////////////////////////////////////////////////////////////////////////

	XMLDoc JDFDeviceCap::DevCapsReport(const JDFNode& jdfRoot, EnumFitsValue testlists, EnumValidationLevel level)const {
		
		XMLDoc testResult = XMLDoc("Temp");
		KElement root = testResult.GetRoot();
		
		// first test if there are in the JDFNode any ResourceLink or NodeInfo/CustomerInfo elements
		// that are not described by DevCaps
		XMLDoc temp = MissingDevCaps(jdfRoot);
		if (!temp.isNull()) {
			root.CopyElement(temp.GetRoot());
		}
		
		
		// if we are here, all resourceLinks of JDFNode and its NodeInfo/CustomerInfo elements (if exist)
		// are specified as DevCaps and we may test them. 
		temp = InvalidDevCaps(jdfRoot,testlists,level);
		if (!temp.isNull()) {
			MoveChildElementVector(root,temp.GetRoot());
		}

		if (RequiredLevel(level)) {
			// test of ActionPool/TestPool
			temp = ActionPoolReport(jdfRoot);
			if (!temp.isNull()) {
				root.CopyElement(temp.GetRoot());
			}
		}
		
		if(!root.HasChildElements())
			testResult = XMLDoc();

		return testResult;
	}


	/////////////////////////////////////////////////////////////////////////

	XMLDoc JDFDeviceCap::InvalidDevCaps(const JDFNode& jdfRoot, EnumFitsValue testlists, EnumValidationLevel level)const {
		
		XMLDoc testResult = XMLDoc("Temp");
		KElement root = testResult.GetRoot();
		KElement mrp = root.AppendElement("MissingResources");
        KElement irp = root.AppendElement("InvalidResources");
		
		JDFResourceLinkPool resLinkPool = jdfRoot.GetResourceLinkPool();

		vElement vDevCaps = GetChildElementVector(elm_DevCaps);
		for (int i=0; i< vDevCaps.size(); i++) {
					
			JDFDevCaps devCaps = vDevCaps[i];
			vElement vElem;
			bool bLink;
			bool bInOut;
			
			WString name = devCaps.GetName();
			JDFDevCaps::EnumContext context = devCaps.GetContext();
			JDFDevCaps::EnumLinkUsage linkUsage = devCaps.GetLinkUsage();

			if ((name=="NodeInfo") || (name=="CustomerInfo") || (name=="Comment")) {
				 vElem = jdfRoot.GetChildElementVector(name); // vElem - for a common return type in all cases
			}
			else {
				if ((context==JDFDevCaps::Context_Resource)||(context==JDFDevCaps::Context_Link)) {
					bLink=(context==JDFDevCaps::Context_Resource)?false:true;

					if (linkUsage!=JDFDevCaps::LinkUsage_Unknown) {
						bInOut=(linkUsage==JDFDevCaps::LinkUsage_Input)?true:false;
						vElem = resLinkPool.GetInOutLinks(bInOut,bLink,name); 
					}
					else {
						// If LinkUsage is not specified, we need both Input + Output
						vElem = resLinkPool.GetInOutLinks(true,bLink,name);
						vElem.AppendUnique(resLinkPool.GetInOutLinks(false,bLink,name));
					}      
				}
				else {
					if (context==JDFDevCaps::Context_JMF) {
					// __Lena__ ...
					}
					else // Context_Unknown
						throw JDFException(L"JDFDeviceCap::FitsDevCaps wrong attribute Context value");
				}
			}
			if (vElem.empty()) {
				if (devCaps.GetRequired() && RequiredLevel(level)) {
					KElement r = mrp.AppendElement("MissingResource");
                    r.SetAttribute("XPath", resLinkPool.GetXPath()+ "/" + devCaps.GetName());
                    if (linkUsage!=JDFDevCaps::LinkUsage_Unknown)
                    {
                        r.SetAttribute("Usage", JDFDevCaps::LinkUsageString(linkUsage));
                    }
                    r.SetAttribute("Message", "Missing Resource/NodeInfo/CustomerInfo");
				}
			}
			else {
				XMLDoc devCapTestResult = devCaps.DevCapReport(vElem,testlists,level);  // InvalidResources
				if (!devCapTestResult.isNull()) {
					MoveChildElementVector(irp,devCapTestResult.GetRoot());
				}
			}
		}

		if (!mrp.HasChildElements() && !irp.HasChildElements()) {// XML output stuff
            testResult = XMLDoc();
		}
		else {
			if (!mrp.HasChildElements())
				root.RemoveChild(mrp.GetNodeName());
	        
			if (!irp.HasChildElements())
				root.RemoveChild(irp.GetNodeName());
		}

		return testResult;
	}

	/////////////////////////////////////////////////////////////////////////

	XMLDoc JDFDeviceCap::MissingDevCaps(const JDFNode& jdfRoot)const {
		
		XMLDoc testResult = XMLDoc("UnknownResources");
		KElement root = testResult.GetRoot();

		JDFResourceLinkPool resLinkPool = jdfRoot.GetResourceLinkPool();
		vElement vLinks = resLinkPool.GetChildElementVector();

		for (int j=0; j<vLinks.size(); j++) {
			JDFResourceLink link=vLinks[j];
			WString resName = link.GetNodeName().leftStr(-4);
			mAttribute m;
			m.AddPair(atr_Name,resName);
			vElement vDevCaps=GetChildElementVector(elm_DevCaps,WString::emptyStr,m);
			bool bFound=false;
			for (int k=0; k<vDevCaps.size(); k++) {
				JDFDevCaps dc = vDevCaps[k];
				if ((!dc.HasAttribute(atr_LinkUsage))||(dc.GetLinkUsage()==link.GetUsage())) {
					bFound=true;
					break;
				}
			}
			if (!bFound) { // no DevCaps with Name=resName and the corresponding LinkUsage were found
				KElement r = root.AppendElement("UnknownResource");
                r.SetAttribute("XPath", link.GetXPath());
                if (link.HasAttribute(atr_Usage) && link.GetUsage()!=JDFResourceLink::Usage_Unknown)
                {
                    r.SetAttribute("Usage", link.UsageString(link.GetUsage()));
                }
                r.SetAttribute("Message", "Found no DevCaps description for this resource");
			}
		}

		if ((!jdfRoot.GetNodeInfo().isNull()) && (GetChildWithMatchingAttribute(elm_DevCaps, atr_Name, WString::emptyStr, elm_NodeInfo).isNull())) {
            KElement ue = root.AppendElement("UnknownElement");
            ue.SetAttribute("XPath", jdfRoot.GetNodeInfo().GetXPath());
            ue.SetAttribute("Message", "Found no DevCaps description for this element");
        }
        
		if ((!jdfRoot.GetCustomerInfo().isNull()) && (GetChildWithMatchingAttribute(elm_DevCaps, atr_Name, WString::emptyStr, elm_CustomerInfo).isNull())) {
            KElement ue = root.AppendElement("UnknownElement");
            ue.SetAttribute("XPath", jdfRoot.GetCustomerInfo().GetXPath());
            ue.SetAttribute("Message", "Found no DevCaps description for this element");
        }
                
        if (!root.HasChildElements())
            testResult = XMLDoc();

		return testResult;
	}

	/////////////////////////////////////////////////////////////////////////

	XMLDoc JDFDeviceCap::ActionPoolReport(const JDFNode& jdfRoot)const {
		
		XMLDoc testResult = XMLDoc("ActionPoolReport");
		KElement root = testResult.GetRoot();

		JDFActionPool actionPool = GetElement(elm_ActionPool);
		if (!actionPool.isNull()) {
			
			JDFTestPool testPool = GetElement(elm_TestPool);
			if (testPool.isNull()) {
				throw JDFException(L"JDFDeviceCap::ActionPoolReport TestPool is required but was not found. Attempt to operate on a null element");
			}
			vElement vActions = actionPool.GetChildElementVector(elm_Action);

			for (int j=0; j<vActions.size(); j++) {
			
				JDFAction action = vActions[j]; 
				
				WString testRef = action.GetTestRef();
				JDFTest test=testPool.GetChildWithAttribute(elm_Test,atr_ID,WString::emptyStr,testRef);
				if (test.isNull()) 
					throw JDFException(L"JDFDeviceCap::ActionPoolReport Test with ID=" + testRef + L" was not found. Attempt to operate on a null element");
				if (test.FitsJDF(jdfRoot)) // If the Test referenced by TestRef evaluates to “true” the combination 
				{							// of processes and attribute values described is not allowed
					
					KElement ar = root.AppendElement("ActionReport");
                    ar.SetAttribute("ActionID", action.GetID());
                    ar.SetAttribute("Severity", action.SeverityString(action.GetSeverity()));
                    
                    // __Lena__ TBD choose Loc element according to the language settings
                    JDFLoc loc = action.GetLoc();
                    ar.SetAttribute("ErrorDescription", loc.GetValue());

                    WString helpText = loc.GetHelpText();
                    if (!helpText.empty()) 
                    {
                        ar.SetAttribute("Help", helpText);
                    }
                    
                    vWString vAttr = test.GetTestedAttributesInfo(jdfRoot);
                    for (int i=0; i < vAttr.size(); i++)
                    {
                        KElement attr = ar.AppendElement("TestedAttribute");
                        WString s = vAttr.at(i);
                        attr.SetAttribute("XPath", s.substring(0, s.find(",")));
                        attr.SetAttribute("Value", s.substring((s.find("="))+1));
                    }
				}
			}
		}

		if (!root.HasChildElements())
            testResult = XMLDoc();

		return testResult;
	}
	/////////////////////////////////////////////////////////////////////////

	void JDFDeviceCap::MoveChildElementVector(KElement moveToElement, KElement moveFromElement) 
    {
		if (!moveToElement.isNull() && !moveFromElement.isNull())
        {
            vElement v = moveFromElement.GetChildElementVector();
            for (int i = 0; i < v.size(); i++) 
            {
                moveToElement.MoveElement(v.at(i));
            }
        }
        return;
    }

	///////////////////////////////////////////////////////////////////////////////////
   /**
     * set the defaults of node to the values defined in the child DevCap and State elements
     * @param node the JDFNode in which to set defults
     * @param bLocal if true, set only in the local node, else recurse children
     */
	bool JDFDeviceCap::setDefaultsFromCaps(JDFNode node, bool bLocal)const
    {
        bool success=false;
        if(bLocal==false)
        {
			VElement vNode=node.GetvJDFNode(WString::emptyStr,JDFNode::Activation_Unknown,false);
            for(int i=0;i<vNode.size();i++)
            {
                JDFNode nod=(JDFNode)vNode.elementAt(i);
                success = setDefaultsFromCaps(nod,true) || success;
            }
            return success;
        }
        if(!matchesType(node,true))
            return false;
        addResourcesFromDevCaps(node);
        int i;
		VElement vDevCaps=GetChildElementVector(elm_DevCaps);
//      step 1, create all missing resources etc
        const int size = vDevCaps.size();
        for(i=0;i<size;i++)
        {
            JDFDevCaps dcs=(JDFDevCaps)vDevCaps.elementAt(i);
            success =  dcs.setDefaultsFromCaps(node) || success;
        }

        return success;
   }

	    /**
     * add any missing resources, links or elements that are described by devcaps elements
     * @param node
     */
	void JDFDeviceCap::addResourcesFromDevCaps(JDFNode node) const
    {
        VElement vDevCaps=GetChildElementVector(elm_DevCaps);
// step 1, create all missing resources etc
        const int size = vDevCaps.size();
        for(int i=0;i<size;i++)
        {
            JDFDevCaps dcs=(JDFDevCaps)vDevCaps.elementAt(i);
            dcs.appendMatchingElementsToNode(node);
        }
    }


    /**
     * test whether agiven node has the coreect Types and Type Attribute
     * 
     * @param testRoot the JDF or JMF to test
     * @param bLocal if true, only check the root of this, else also check children
     * 
     * @return boolean true if this DeviceCaps TypeExpression fits the testRoot/@Type and testRoot/@Types
     * 
     */
	bool JDFDeviceCap::matchesType(JDFNode testRoot, bool bLocal) const
    {
        WString typeNode = testRoot.GetType();
        
        vint vCombMethod = GetCombinedMethod();
        for(int j=0;j<vCombMethod.size();j++)
        {
			EnumCombinedMethod combMethod = (EnumCombinedMethod)vCombMethod[j];
            
            WString typeExp = GetTypeExpression();
            if (combMethod==CombinedMethod_None)  // node is an individual process
            {            
                return typeNode.matches(typeExp);
            }
            else if (combMethod==CombinedMethod_Combined)
            {
                return FitsTypes(testRoot.GetTypes());
            }
            else if (combMethod==CombinedMethod_ProcessGroup)
            {
                if(bLocal){
                    return typeNode.equals(L"ProcessGroup")
                    && FitsTypes(testRoot.getAllTypes());
                }
                
                VElement vNodes=testRoot.GetvJDFNode();
                for(int i=0;i<vNodes.size();i++)
                {
                    JDFNode node=(JDFNode) vNodes.elementAt(i);
                    if(matchesType(node,true))
                        return true;
                }
                return false;
            } 
            else if (combMethod==CombinedMethod_CombinedProcessGroup)
            {
                if (typeNode.equals("ProcessGroup")) 
                {
                    return FitsTypes(testRoot.getAllTypes());
                }
                else if (typeNode.equals("Combined"))
                {
                    return FitsTypes(testRoot.GetTypes());
                }            
                else
                {
                    return false;
                }
            }
            // TODO __Lena__ if CombinedMethod_GrayBox: {return true;}
            else 
            {
                throw new JDFException ("JDFDeviceCap.report: Invalid DeviceCap: illegal value of CombinedMethod attribute"); 
            }
        }
        return false;
    }


	/**
     * get a DevCaps element by name and further restrictions.
     * if an Enumerative restriction is "unknown" (e.g. Context_Unknown), the restriction is not checked
     * 
     * @param devCapsName the Name attribute of the DevCaps
     * @param context the Context attribute of the DevCaps
     * @param linkUsage the LinkUsage attribute of the DevCaps
     * @param processUsage the ProcessUsage attribute of the DevCaps
     * @param iSkip the iSkipth matching DevCaps
     * @return JDFDevCaps the matching DevCaps, null if not there
     */
	JDFDevCaps JDFDeviceCap::getDevCapsByName(const WString& devCapsName, JDFAutoDevCaps::EnumContext context, 
		JDFAutoDevCaps::EnumLinkUsage linkUsage, const WString& processUsage, int iSkip)
	{
		JDFAttributeMap map(atr_Name, devCapsName);
		if (context != JDFAutoDevCaps::Context_Unknown)
			map.put(atr_Context, JDFAutoDevCaps::ContextString(context));
		if (linkUsage != JDFAutoDevCaps::LinkUsage_Unknown)
			map.put(atr_LinkUsage, JDFAutoDevCaps::LinkUsageString(linkUsage));
		if ( !processUsage.empty() )
			map.put(atr_ProcessUsage, processUsage);
		return (JDFDevCaps)GetChildByTagName(elm_DevCaps, WString::emptyStr, iSkip, map, true, true);
	}
}; // namespace JDF
