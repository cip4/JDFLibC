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
/*
*
*
* COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
*      ALL RIGHTS RESERVED 
*
*  Author: Dr. Rainer Prosi using JDFSchema code generator 
* 
* Warning! very preliminary test version. Interface subject to change without prior notice!
* Revision history:
* created 2001-07-11
*
*/

#include "JDFResourceInfo.h"
#include "JDFResource.h"

namespace JDF{
	
	/////////////////////////////////////////////////////////////////////////////
	JDFResourceInfo & JDFResourceInfo::operator =(const KElement& other){
		KElement::operator=(other); 
		return *this;
	};
		
	/////////////////////////////////////////////////////////////////////////////
	
	vWString JDFResourceInfo::GetUnknownElements(bool bIgnorePrivate,int nMax)const{
		return GetUnknownPoolElements(PoolType_ResourcePool,bIgnorePrivate,nMax,KnownElements().Tokenize(WString::comma));
	};

	   /**
     * Method GetInvalidElements.
     * @param level
     * @param bIgnorePrivate
     * @param nMax
     * @return Vector
     * 
     * default: GetInvalidElements(level, true, 999999)
     */
    vWString JDFResourceInfo::getInvalidElements(EnumValidationLevel level,
            bool bIgnorePrivate, int nMax)const
    {
		vWString s=JDFAutoResourceInfo::GetInvalidElements(level, bIgnorePrivate, nMax);
        if(s.size()>nMax)
            return s;
        
        vElement v=GetChildElementVector();
        if(v.size()>1)
        {
            // remove anything but resources
            for(int i=v.size()-1;i>=0;i--)
            {
				JDFElement e=v.elementAt(i);
                if(!(e.IsResource()))
                {
                    v.remove(i);
                }                   
            }
            
            // more tahn one resource --> evil!
            if(v.size()>1)
            {                
                for(int j=0;j<v.size();j++)
                {
                    s.AppendUnique(v.at(j).GetLocalName());
                }
            }
        }
        return s;
    }
	//////////////////////////////////////////////////////////////////////
	JDFResource JDFResourceInfo::GetResource(const WString &resName)const{
		JDFResource e=GetElement(resName,WString::emptyStr);
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFResource JDFResourceInfo::GetCreateResource(const WString &resName){
		JDFResource e=GetCreateElement(resName,WString::emptyStr);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFResource JDFResourceInfo::AppendResource(const WString &resName){
		JDFResource e=AppendElement(resName);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	vmAttribute JDFResourceInfo::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}
	
	//////////////////////////////////////////////////////////////////////
	
	void JDFResourceInfo::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
	
	//////////////////////////////////////////////////////////////////////
	
	void JDFResourceInfo::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
	
	//////////////////////////////////////////////////////////////////////
	void JDFResourceInfo::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFResourceInfo::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
}; // namespace JDF
