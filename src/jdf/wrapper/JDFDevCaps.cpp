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
// JDFDevCaps.cpp: implementation of the JDFDevCaps 
//
//////////////////////////////////////////////////////////////////////


#include "JDFDevCaps.h"
#include "JDFDevCap.h"
#include "JDFDevCapPool.h"

namespace JDF{
	/**
	* copy equivalance operator
	*/
	JDFDevCaps& JDFDevCaps::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFDevCaps: "+other.GetNodeName());
		return *this;
	};

	/////////////////////////////////////////////////////////////////////////
	WString JDFDevCaps::OptionalAttributes()const{
		return JDFAutoDevCaps::OptionalAttributes()+WString(L",DevCapRef,ModuleRefs");
	};

	/////////////////////////////////////////////////////////////////////////

	vWString JDFDevCaps::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFAutoDevCaps::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDevCapRef(level)) {
			vAtts.push_back(atr_DevCapRef);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModuleRefs(level)) {
			vAtts.push_back(atr_ModuleRefs);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

	/////////////////////////////////////////////////////////////////////////
	WString JDFDevCaps::GetNamePath(bool onlyNames)const{

		WString name = GetName();
		WString xPath = name;
		if (!onlyNames) {
			WString context = ContextString(GetContext());
			WString linkUsage = LinkUsageString(GetLinkUsage());
			xPath.append(L"[Context="+context+L", LinkUsage=" +linkUsage+L"]");
		}
		return xPath;
	}
	//////////////////////////////////////////////////////////////////////

	/**
     * Gets the NamePath of this DevCap in form 
     * "DevCapsName/SubelemName1/SubelemName2/..."
     * If this DevCap is located in DevCapPool and not in a DevCaps - it describes the reusable resource 
     * and DevCap root will have the attribute "Name" = value of DevCaps/@Name 
     * but will have no info about DevCaps/@Context or DevCaps/@LinkUsage 
     *
     * @param bRecurse - if true, returns "DevCapsName/SubelemName1/SubelemName2/..."
     * @return String - NamePath of this DevCap
     * 
     * default: getNamePath(false)  
     */
	VString JDFDevCaps::getNamePathVector()
    {
        WString result = getDevCapsName();    
        VString vResult;
        vResult.add(result);
        return vResult;
    } 

	//////////////////////////////////////////////////////////////////////

	WString JDFDevCaps::getDevCapsName()
	{
		WString nam = GetName();
		EnumContext cont = GetContext();
		if (cont == Context_Link)
		{
			nam+=atr_Link;
		}
		else if (cont == Context_Element && nam != elm_JDF)
		{
			nam = elm_JDF + (WString)"/" + nam;
		}
		else if (cont == Context_JMF)
		{
			nam = elm_JMF + (WString)"/" + nam;
		}
		return nam;
	}

	//////////////////////////////////////////////////////////////////////

	VElement JDFDevCaps::getDevCapVector()
	{
		VElement vDevCap = GetChildElementVector(elm_DevCap, WString::emptyStr, mAttribute::emptyMap, true, 0, false);
		WString dcr=GetAttribute(atr_DevCapRef, WString::emptyStr, WString::emptyStr);
		if ( !dcr.empty() )
		{
			JDFDevCapPool dcp=((JDFDeviceCap)GetParentNode()).GetDevCapPool();
			if ( !dcp.isNull() )
			{
				KElement dcre=GetChildWithAttribute(elm_DevCap, atr_ID, WString::emptyStr, dcr, 0, true);
				vDevCap.AppendUnique(dcre);
			}
		}
		return vDevCap;
	}

	//////////////////////////////////////////////////////////////////////

	/**
	* get the one and only devCap - note that the spec allows * but recommends only one + additional actions
	* also search devCapPool for a matching element to DevCapRef
	* @return the devCap
	*/
	JDFDevCap JDFDevCaps::getDevCap()const
	{
		WString dcr=GetDevCapRef();
		if(!dcr.empty()){
			JDFDeviceCap deviceCap=GetParentNode();
			JDFDevCapPool dcp=deviceCap.GetDevCapPool();
			if(dcp.isNull())
				return JDFDevCap();
			return dcp.GetChildWithAttribute(elm_DevCap,atr_ID,WString::emptyStr,dcr,0,true);
		}
		return GetDevCap(0);
	}

	//////////////////////////////////////////////////////////////////////

	XMLDoc JDFDevCaps::DevCapReport(vElement vElem, EnumFitsValue testlists, EnumValidationLevel level)const {

		XMLDoc testResult = XMLDoc("Temp");
		KElement tempRoot = testResult.GetRoot();

		vElement vDevCap = GetChildElementVector(elm_DevCap);
		XMLDoc stateTestResult;
		bool bExit = false;

		if (HasAttribute(atr_DevCapRef))
		{
			JDFDeviceCap deviceCap = GetDeepParent(elm_DeviceCap);
			JDFDevCapPool devCapPool = deviceCap.GetDevCapPool();
			if (!devCapPool.isNull())
			{
				// get devCap element from DevCapPool with the attributes Name = this.getName() and ID = this.getDevCapRef()
				mAttribute map;
				map.AddPair("Name", GetName());
				map.AddPair("ID", GetDevCapRef());
				JDFDevCap devCapP = devCapPool.GetChildByTagName(elm_DevCap,WString::emptyStr,0,map);                            
				if ( !devCapP.isNull() ) 
				{
					stateTestResult = devCapP.StateReport(vElem,testlists,level);
					if(stateTestResult.isNull()) 
					{ 
						testResult = XMLDoc();
						bExit = true; // First DevCap that fits -> go back to DeviceCap
					}
					else 
					{
						KElement r = tempRoot.AppendElement("InvalidResource");
						r.SetAttribute("XPath", devCapP.GetName());
						MoveChildElementVector(r,stateTestResult.GetRoot());
					}
				}
				else 
				{
					throw JDFException("JDFDevCaps::DevCapReport: Invalid DeviceCap: DevCaps/@DevCapRef refers to the non-existent DevCap");
				}
			}
			else 
			{
				throw JDFException("JDFDevCaps::DevCapReport: Invalid DeviceCap: DevCaps/@DevCapRef refers to the non-existent DevCapPool");
			}
		}

		if (!bExit && !vDevCap.empty()) // DevCap can have both - atr_DevCapRef and elm_DevCap
		{
			for (int i=0; i<vDevCap.size(); i++) { // elm_DevCap is required in DevCaps. 

				JDFDevCap dc = vDevCap[i];

				stateTestResult = dc.StateReport(vElem,testlists,level);
				if(stateTestResult.isNull()) 
				{ 
					testResult = XMLDoc();
					bExit = true; // First DevCap that fits -> go back to DeviceCap
				}
				else 
				{
					KElement r = tempRoot.AppendElement("InvalidResource");
					r.SetAttribute("XPath", dc.GetName());
					MoveChildElementVector(r,stateTestResult.GetRoot());
				}
			}
		}

		if (!testResult.isNull()) 
		{
			Correction(testResult.GetRoot());
		}
		return testResult;
	}

	//////////////////////////////////////////////////////////////////////
	void JDFDevCaps::SetDevCapRef(const WString& value){
		SetAttribute(atr_DevCapRef,value);
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFDevCaps::GetDevCapRef() const {
		return GetAttribute(atr_DevCapRef,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFDevCaps::ValidDevCapRef(EnumValidationLevel level) const {
		return ValidAttribute(atr_DevCapRef,AttributeType_IDREF,false);
	};

	//////////////////////////////////////////////////////////////////////
	void JDFDevCaps::SetModuleRefs(const vWString& value){
		SetAttribute(atr_ModuleRefs,value);
	};
	//////////////////////////////////////////////////////////////////////

	vWString JDFDevCaps::GetModuleRefs() const {
		return GetAttribute(atr_ModuleRefs,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFDevCaps::ValidModuleRefs(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleRefs,AttributeType_IDREFS,false);
	};

	//////////////////////////////////////////////////////////////////////

	void JDFDevCaps::Correction(KElement root) const
	{
		vElement v = root.GetChildElementVector("InvalidResource");
		for (int i = 0; i < v.size(); i++) 
		{
			KElement invRes = v.at(i);
			vElement vv = invRes.GetChildElementVector();

			for (int j = vv.size()-1; j >= 0; j--) 
			{
				XPathCorrection(vv.at(j),invRes.GetAttribute("XPath"));
			}
			RemovePoolElements(invRes);
		}
		return;
	}

	void JDFDevCaps::RemovePoolElements(KElement root)const
	{
		vElement v = root.GetChildElementVector();
		for (int j = v.size()-1; j >= 0; j--) 
		{
			KElement el = v.at(j);
			WString nam = el.GetNodeName();
			if (nam==L"InvalidAttributes" || nam==L"InvalidSubelements" ||
				nam==L"UnknownAttributes" || nam==L"UnknownSubelements" || 
				nam==L"MissingAttributes")
			{
				MoveChildElementVector(root,el);
				if (!el.HasChildElements()&&!el.HasAttributes())
					root.RemoveChild(el.GetNodeName());
			}

		}
		vElement vv = root.GetChildElementVector();
		for (int i = vv.size()-1; i >= 0; i--) 
		{
			RemovePoolElements(vv.at(i));
		}
		return;
	}


	void JDFDevCaps::XPathCorrection(KElement elem, const WString& originalPath) const
	{
		WString parentPath = elem.GetParentNode().GetAttribute("XPath");

		vElement vEl = elem.GetChildElementVector();

		for (int i = 0; i < vEl.size(); i++) 
		{
			KElement child = vEl.at(i);
			WString childPath = child.GetAttribute("XPath");

			if (parentPath!=WString::emptyStr && childPath!=WString::emptyStr)
			{
				WString childPathPart = childPath;
				if (childPath.startsWith(originalPath))
				{
					childPathPart = childPath.substring(originalPath.length()+1); // +1 removes "/"
				}
				child.SetAttribute("XPath", parentPath + "/" + childPathPart);

				// recursion to set everywhere the right XPath
				vElement vSubEl = child.GetChildElementVector();
				for (int j = 0; j < vSubEl.size(); j++) 
				{
					XPathCorrection(vSubEl.at(j),childPath);
				}
			}
		}
		return;
	}

	void JDFDevCaps::MoveChildElementVector(KElement moveToElement, KElement moveFromElement) 
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

	/**
	* sets default elements and adds them if therw are less than minorrurs
	*/
	bool JDFDevCaps::setDefaultsFromCaps(JDFNode node) const
	{
		bool modified = false;
		JDFDevCap dc = getDevCap();
		if (!dc.isNull())
		{
			VElement v = getMatchingElementsFromNode(node);
			const int size =  v.size();
			for (int i = 0; i < size; i++)
			{
				modified = dc.setDefaultsFromCaps(v.elementAt(i)) || modified;
			}
		}

		return modified;    
	}

	/**
	* gets the matching elements in node that match this devcap
	* 
	* @param node the node to search in
	* @return VElement the element vector of matching elements, 
	* null if none were found
	*/
	vElement JDFDevCaps::getMatchingElementsFromNode(JDFNode node)const
	{
		VElement vElem;
		WString nam = GetName();
		EnumContext context = GetContext();
		JDFResourceLinkPool resLinkPool=node.GetResourceLinkPool();

		if (context==Context_Element) 
		{ // vElem - for a common return type in all cases
			if(nam.equals(elm_JDF))
			{
				vElem.add(node);
			}
			else
			{
				vElem = node.GetChildElementVector(nam);
			}
		}
		else if (context==Context_Link || context==Context_Resource)
		{
			if (!resLinkPool.isNull())
			{
				VElement vElemLinks;
				JDFResourceLink::EnumUsage linkUsage = (JDFResourceLink::EnumUsage)GetLinkUsage();
				WString procUsage=GetProcessUsage();
				bool bLink = context==Context_Link;
				vElemLinks = resLinkPool.getInOutLinks(linkUsage, true, nam); 


				for(int j=vElemLinks.size()-1;j>=0;j--)
				{
					JDFResourceLink rl=(JDFResourceLink) vElemLinks.elementAt(j);
					if(!rl.GetProcessUsage().equals(procUsage)){
						vElemLinks.remove(j);
					}
				}

				if (!bLink)
				{
					vElem = JDFResourceLinkPool::ResourceVector(vElemLinks);
				}
			}
		}
		else if (context==Context_JMF)
		{
			// TODO __Lena__ ...
		}
		else 
		{// Context_Unknown
			throw new JDFException("JDFDevCaps wrong attribute Context value");
		}

		return vElem;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFDevCaps::FixVersion(EnumVersion version){
		if(HasAttribute(L"Occurences"))
			RenameAttribute(L"TypeOccurenceNum",atr_TypeOccurrenceNum);

		return JDFAutoDevCaps::FixVersion(version);
	}
	/**
	* append elements that match this devCap to node, if they do not yet exist
	* 
	* @param node the node to append the elements to
	* 
	* @return KElement the last element that was appended
	*/
	KElement JDFDevCaps::appendMatchingElementsToNode(JDFNode node)const
	{
		WString nam = GetName();
		EnumContext context = GetContext();
		JDFDevCap devCap = getDevCap();
		if(devCap.isNull())
			return devCap;
		int minOcc=devCap.GetMinOccurs();

		KElement e;
		for(int i=0;i<minOcc;i++)
		{
			if (context==Context_Element) 
			{ // vElem - for a common return type in all cases
				if(nam.equals(elm_JDF))
				{
					// nop - should actually never get here
				}
				else
				{
					e=node.GetCreateElement(nam,GetDevNS(),i);
				}
			}
			else if (context==Context_Resource || context==Context_Link)
			{
				JDFResourceLink::EnumUsage linkUsage = (JDFResourceLink::EnumUsage)GetLinkUsage();
				WString procUsage=GetProcessUsage();
				JDFAttributeMap map;
				if(procUsage.length()>0)
				{
					map.put(atr_ProcessUsage,procUsage);
				}
				if(linkUsage!=JDFResourceLink::Usage_Unknown)
				{
					map.put(atr_Usage,JDFResourceLink::UsageString(linkUsage));
				}
				VElement links=node.getLinks(nam,map);
				if(links.size()<=i)
				{
					JDFResource r=node.addResource(nam,JDFResource::Class_Unknown,linkUsage,procUsage,JDFNode::DefJDFNode,GetDevNS());
					e=node.getLink(r);
				}
			}
			else if (context==Context_JMF) 
			{
				// TODO __Lena__ ...
			}
		}
		return e;
	}

	int JDFDevCaps::getMaxOccurs()
	{
		int m=0;
		VElement vDC=getDevCapVector();
		int svDC;
		svDC = vDC.empty() ? 0 : vDC.size();
		for (int i=0; i<svDC; i++)
		{
			JDFDevCap dc=(JDFDevCap)vDC.elementAt(i);
			if ( m<dc.GetMaxOccurs() )
				m=dc.GetMaxOccurs();
		}
		return m;
	}

	int JDFDevCaps::getMinOccurs()
	{
		int m=INT_MAX;
		VElement vDC=getDevCapVector();
		int svDC;
		svDC = vDC.empty() ? 0 : vDC.size();
		for (int i=0; i<svDC; i++)
		{
			JDFDevCap dc=(JDFDevCap)vDC.elementAt(i);
			if (m>dc.GetMinOccurs())
				m=dc.GetMinOccurs();
		}
		if (m<0 && GetRequired())
			m=1;
		return m;
	}

}; // namespace JDF
