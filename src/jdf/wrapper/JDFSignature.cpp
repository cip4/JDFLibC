/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2012 The International Cooperation for the Integration of 
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


#include "JDFSignature.h"
#include "JDFLayout.h"
#include "JDFSheet.h"

namespace JDF{
	/**
	* copy equivalance operator
	*/
	JDFSignature& JDFSignature::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFSignature: "+other.GetNodeName());
		return *this;
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////////

	int JDFSignature::numLayoutElements(const JDFResource &layout, const WString &elementName, const JDF::WString &partitionKeyName)
	{
        return getLayoutElementVector(layout, elementName, partitionKeyName).size();
 	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////

	JDFLayout JDFSignature::appendLayoutElement(JDFResource &layout, const WString &elementName, const JDF::WString &partitionKeyName)
	{
		if(JDFLayout::isNewLayout(layout))
        {
            int n=1+numLayoutElements(layout,elementName,partitionKeyName);
			return layout.AddPartition(JDFResource::GetPartIDKeyEnum(partitionKeyName),partitionKeyName+WString::valueOf(n));
        }
        else
		{
            return layout.AppendElement(elementName);
        }
  	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////

	JDFSheet JDFSignature::GetSheet(int iSkip) const
	{
		return getLayoutElement(*this,elm_Sheet,atr_SheetName,iSkip);
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////

	JDFLayout JDFSignature::getLayoutElement(const JDF::JDFResource &layout, const JDF::WString &elementName, const JDF::WString &partitionKeyName, int iSkip)
	{
		JDFLayout s;
		if(JDFLayout::isNewLayout(layout))
		{
			vElement v=((KElement)layout).GetChildElementVector(elm_Layout,WString::emptyStr,mAttribute(partitionKeyName,WString::emptyStr),true,iSkip+1);
			if(v.size()>iSkip)
				s=(JDFLayout)v[iSkip];
		}
		else{
			s=layout.GetElement(elementName, WString::emptyStr, iSkip);

		}
		return s;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////

   /**
     * get a specific layout element
     * @param layout
     * @param elementName
     * @param partitionKeyName
     * @return JDFLayout: the element
     */
	VElement JDFSignature::getLayoutElementVector(const JDF::JDFResource & layout, const JDF::WString & elementName, const JDF::WString &partitionKeyName)
    {
		if(JDFLayout::isNewLayout(layout))
        {
			return ((KElement)layout).GetChildElementVector(elm_Layout,WString::emptyStr,JDFAttributeMap(partitionKeyName,WString::emptyStr),true,0,true);
        }
		return layout.GetChildElementVector(elementName,WString::emptyStr,JDFAttributeMap::emptyMap,true,0,true);            
    }    
	////////////////////////////////////////////////////////////////////////////////////////////////////////

    /**
     * get the vector of sheets in this signature
     * @return {@link VElement} the vector of signatures in this
     */
	VElement JDFSignature::getSheetVector()const
    {
        return getLayoutElementVector(*this,elm_Sheet,atr_SheetName);
    }

	////////////////////////////////////////////////////////////////////////////////////////////////////////


	JDFSheet JDFSignature::AppendSheet(){
		return appendLayoutElement(*this,elm_Sheet,atr_SheetName);
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////////

	int JDFSignature::numSheets()const
	{
		return JDFSignature::numLayoutElements(*this,elm_Sheet,atr_SheetName);
	}

	/////////////////////////////////////////////////////////////////////

	JDFSheet JDFSignature::GetCreateSheet(int iSkip){
		JDFSheet s = GetSheet(iSkip);
		if (s.isNull())
		{
			s=AppendSheet();
		}
		return s;
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	* typesafe validator utility - list of valid node names for this class 
	* @return WString& comma separated list of valid node names
	*/
	WString JDFSignature::ValidNodeNames()const{
		return L"*:,Signature,Layout";
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////////

	vElement JDFSignature::getLayoutLeaves(bool bAll)
    {
		if(JDFLayout::isNewLayout(*this))
			return GetLeaves(bAll);
		return GetChildrenByTagName(JDFElement::elm_Surface, WString::emptyStr, mAttribute::emptyMap, false, true, -1);
    }

	////////////////////////////////////////////////////////////////////////////////////////////////////////

	WString JDFSignature::GetSignatureName() const
	{
		if(GetLocalName() == JDFElement::elm_Signature)
            return GetName();
		if(GetLocalName() == JDFElement::elm_Sheet)
        {
			KElement parentNode = KElement::GetParentNode();
			if(parentNode.GetLocalName() == JDFElement::elm_Signature)
            {
                JDFSignature sig=(JDFSignature)parentNode;
                return sig.GetSignatureName();
            }
        }
		else if(GetLocalName() == JDFElement::elm_Surface)
        {
			KElement parentNode = KElement::GetParentNode().KElement::GetParentNode();
			if(parentNode.GetLocalName() == JDFElement::elm_Signature)
            {
                JDFSignature sig=(JDFSignature)parentNode;
                return sig.GetSignatureName();
            }
        }
		return   JDFResource::GetSignatureName();
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////

}; // namespace JDF
