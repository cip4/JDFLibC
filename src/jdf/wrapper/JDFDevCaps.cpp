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
	//////////////////////////////////////////////////////////////////////

	bool JDFDevCaps::FixVersion(EnumVersion version){
		if(HasAttribute(L"Occurences"))
			RenameAttribute(L"TypeOccurenceNum",atr_TypeOccurrenceNum);

		return JDFAutoDevCaps::FixVersion(version);
	}

}; // namespace JDF
