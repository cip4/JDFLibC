/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2002 The International Cooperation for the Integration of 
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


///////////////////////////////////////////////////////////////////

#include "jdf/wrapper/JDFEvaluation.h" 
#include "jdf/wrapper/JDFDeviceCap.h" 
#include "jdf/wrapper/JDFBasicPreflightTest.h"
#include "jdf/wrapper/JDFRefElement.h"
#include "jdf/wrapper/JDFFactory.h"

namespace JDF{
/*
*********************************************************************
class JDFEvaluation : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFEvaluation& JDFEvaluation::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFEvaluation: "+other.GetNodeName());
		return *this;
	};

	/////////////////////////////////////////////////////////////////////////
	
	bool JDFEvaluation::IsAbstract()const{
		return true;
	}

	/////////////////////////////////////////////////////////////////////////
	
	WString JDFEvaluation::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+L",rRef";
	};

	/////////////////////////////////////////////////////////////////////////
	vWString JDFEvaluation::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidrRef(level)) {
			vAtts.push_back(atr_rRef);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

	/////////////////////////////////////////////////////////////////////////

	WString JDFEvaluation::OptionalElements()const{
		return JDFElement::OptionalElements()+L",BasicPreflightTest";
	};

	/////////////////////////////////////////////////////////////////////

	vWString JDFEvaluation::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_BasicPreflightTest);
		if (nElem>1) {
			vElem.push_back(elm_BasicPreflightTest);
			if (++n>=nMax) 
				return vElem;
		}
		for(i=0;i<nElem;i++){
			JDFBasicPreflightTest child=GetElement(elm_BasicPreflightTest,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_BasicPreflightTest);
				if (++n>=nMax) 
					return vElem;
			}
		}
		return vElem;
	};

	/////////////////////////////////////////////////////////////////////////
	
	bool JDFEvaluation::FitsMap(const mAttribute & m) const {
		
		WString name = GetBasicPreflightTest().GetName();

		if (m.HasKey(name)) {
			WString val= m[name];
			return FitsValue(val);
		}
		return false; 
	}
	
	//////////////////////////////////////////////////////////////////////
	JDFBasicPreflightTest::EnumListType JDFEvaluation::GetListType() const{
		
		if (HasAttribute(atr_rRef)) 
		{
			JDFDeviceCap deviceCap = GetDeepParent(elm_DeviceCap);
			vElement vDevCaps = deviceCap.GetChildElementVector(elm_DevCaps);
			JDFStateBase::EnumListType listtype;
			for (int i=0; i<vDevCaps.size(); i++) 
			{
				JDFDevCaps devCaps = vDevCaps[i];
				// elm is a State, that we are looking for
				JDFElement elm = devCaps.GetChildWithAttribute(WString::emptyStr,atr_ID,WString::emptyStr,GetrRef(),0,false);
				if (elm.isNull())
					continue;
				else {

					JDFFactory f(elm);
					JDFStateBase& state=(JDFStateBase&)f.GetRef();
					listtype = state.GetListType();
					break;
				}
			}
			return (JDFBasicPreflightTest::EnumListType) listtype;
		}
		return GetBasicPreflightTest().GetListType();
	}
	
	/////////////////////////////////////////////////////////////////////////
	
	vWString JDFEvaluation::GetAttributeXPathVector(const JDFNode& jdf) const {
		
		JDFDeviceCap deviceCap = GetDeepParent(elm_DeviceCap);
		vElement vDevCaps = deviceCap.GetChildElementVector(elm_DevCaps);
		for (int i=0; i<vDevCaps.size(); i++) {
			JDFDevCaps devCaps = vDevCaps[i];
			// elm is a State, that we are looking for
			JDFElement elm = devCaps.GetChildWithAttribute(WString::emptyStr,atr_ID,WString::emptyStr,GetrRef(),0,false);
			if (elm.isNull())
				continue;
			else {
				// we have found our state -> take its xPath and look for corresponding elem in JDFNode, we test
				JDFFactory f(elm);
				JDFStateBase& state=(JDFStateBase&)f.GetRef();
				WString xPath = state.GetNamePath();
				vWString v = xPath.Tokenize(WString::slash);
				
				// resName = DevCaps/@Name
				int beginPos=0;
				int endPos=v[0].find_first_of("[");
				WString resName = v[0].substr(beginPos,endPos);

				// context = DevCaps/@Context
				beginPos=(v[0].find_first_of("=")+1);
				endPos=v[0].find_first_of(",")-beginPos;
				WString context = v[0].substr(beginPos,endPos);
				
				// linkUsage = DevCaps/@LinkUsage
				beginPos=(v[0].find_last_of("=")+1); 
				endPos=v[0].find_first_of("]")-beginPos;
				WString linkUsage = v[0].substr(beginPos,endPos);

				// subElem = DevCap/@Name
				int siz = (v.size()-1); // the last one is attrName
				vWString vSubElmNames;
				for (int j=1; j<siz; j++) {
					vSubElmNames.push_back(v[j]);
				}
				
				// attrName = State/@Name
				beginPos=(v[siz].find_first_of("@")+1);
				endPos=v[siz].length()-beginPos;
				WString attrName = v[siz].substr(beginPos,endPos);

				
				// now we have all var from xPath: types, resName, context, linkUsage, all vSubElmNames, attrName
				// we need attrVal

				JDFResourceLinkPool resLinkPool = jdf.GetResourceLinkPool();
				vElement vElem;
				bool bLink; // for context
				bool bInOut; // for linkUsage
				if ((context==L"Resource")||(context==L"Link")) {
					bLink=(context==L"Resource")?false:true;

					if (linkUsage!=L"Unknown") {
						bInOut=(linkUsage==L"Input")?true:false;
						vElem = resLinkPool.GetInOutLinks(bInOut,bLink,resName); 
					}
					else {
						// If LinkUsage is not specified, we need both Input + Output
						vElem = resLinkPool.GetInOutLinks(true,bLink,resName);
						vElem.AppendUnique(resLinkPool.GetInOutLinks(false,bLink,resName));
					}
				}
				else {
					if (context==L"JMF") {
					// __Lena__ ...
					}
					else // Context_Unknown 
						throw JDFException(L"JDFEvaluation::GetAttributeXPathVector invalid Context attribute"); 
				}
				
				vWString elemXPath;
				for (int k=0; k<vElem.size(); k++) {
					JDFElement elem = vElem[k];
					if (!vSubElmNames.empty()) {
						for (int ii=0; ii<vSubElmNames.size(); ii++) {
							JDFElement subElm = elem.GetElement(vSubElmNames[ii]);
							if (subElm.isNull())
								throw JDFException(L"JDFEvaluation::GetAttributeXPathVector attempt to operate on a null element");
							elem=subElm; 
						}
					}
					WString path = elem.GetXPath();
					elemXPath.AppendUnique(path +"/@"+ attrName);
				}
				return elemXPath;
			}
		}
		return WString();	
	}

	/////////////////////////////////////////////////////////////////////////

	bool JDFEvaluation::FitsJDF(const JDFNode& jdf) const {

		vWString vXPath = GetAttributeXPathVector(jdf);
		WString attrVal;
		for (int i=0; i<vXPath.size(); i++) {
			attrVal = jdf.GetXPathAttribute(vXPath[i]); 
			if (!FitsValue(attrVal))
				return false;
		}
		return true;
	}

	/////////////////////////////////////////////////////////////////////////
	vWString JDFEvaluation::GetTestedAttributesInfo(const JDFNode& jdf) const {

		vWString vStr;
		vWString vXPath = GetAttributeXPathVector(jdf);
		for (int i=0; i<vXPath.size(); i++) {
			WString attrVal = jdf.GetXPathAttribute(vXPath[i]); 
			vStr.AppendUnique(vXPath[i]+L", Value="+attrVal);
		}
		return vStr;
	}
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Attribute Getter / Setter
	****************************************************** */

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	void JDFEvaluation::SetrRef(const WString& value){
		SetAttribute(atr_rRef,value);
	};
	/////////////////////////////////////////////////////////////////////////

	WString JDFEvaluation::GetrRef() const {
		return GetAttribute(atr_rRef,WString::emptyStr);
	};

	/////////////////////////////////////////////////////////////////////////

	bool JDFEvaluation::ValidrRef(EnumValidationLevel level) const {
		return ValidAttribute(atr_rRef,AttributeType_IDREF,false);
	};
	
	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */
	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	
	JDFBasicPreflightTest JDFEvaluation::GetCreateBasicPreflightTest(){
		JDFBasicPreflightTest e=GetCreateElement(elm_BasicPreflightTest,WString::emptyStr);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	JDFBasicPreflightTest JDFEvaluation::GetBasicPreflightTest()const{
		return GetElement(elm_BasicPreflightTest,WString::emptyStr);
	};
	/////////////////////////////////////////////////////////////////////

	JDFBasicPreflightTest JDFEvaluation::AppendBasicPreflightTest(){
		JDFBasicPreflightTest e=AppendElementN(elm_BasicPreflightTest,1);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFBasicPreflightTest JDFEvaluation::appendBasicPreflightTest(const WString& testName)
	{
		JDFBasicPreflightTest pft=(JDFBasicPreflightTest)AppendElementN(JDFStrings::elm_BasicPreflightTest, 1, WString::emptyStr);
		if (pft.isNull())
			return JDFBasicPreflightTest();
		if (!testName.empty())
			pft.SetName(testName);
		return pft;
	}
	
	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

}; // end namespace JDF