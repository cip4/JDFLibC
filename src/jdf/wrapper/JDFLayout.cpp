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


///////////////////////////////////////////////////////////////////


#include "JDFLayout.h"
#include "JDFSheet.h"
#include "JDFSurface.h"
#include "JDFRefElement.h"

namespace JDF{
	/**
	* copy equivalance operator
	*/
	JDFLayout& JDFLayout::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFLayout: "+other.GetNodeName());
		return *this;
	};

	///////////////////////////////////////////////////////////////////
	bool JDFLayout::FixVersion(EnumVersion version){
		bool bRet=true;

		if(IsResourceRoot()){
			bool newLayout = isNewLayout(*this);
			if(version>=Version_1_3 && !newLayout)
			{
				bRet=ToNewLayout();
			}
			else if(version<Version_1_3 && newLayout)
			{
				bRet=FromNewLayout();
			}
		}
		return JDFSignature::FixVersion(version) && bRet;
	}


	///////////////////////////////////////////////////////////////////

	bool JDFLayout::ToNewLayout(){
		vElement vSig=GetChildElementVector(elm_Signature);
		for(int iSig=0;iSig<vSig.size();iSig++){
			JDFResource rSig=vSig[iSig];
			if(rSig.IsRefElement()){
				rSig=JDFRefElement(rSig).InlineRef();
			}
			rSig.RenameElement(elm_Layout);
			rSig.SetPartIDKey(rSig.PartIDKey_SignatureName,rSig.GetAttribute(atr_Name,WString::emptyStr,L"Sig"+WString(iSig)));
			rSig.RemoveAttribute(atr_Name);
			vElement vSheet=rSig.GetChildElementVector(elm_Sheet);
			for(int iSheet=0;iSheet<vSheet.size();iSheet++){
				JDFResource rSheet=vSheet[iSheet];
				if(rSheet.IsRefElement()){
					rSheet=JDFRefElement(rSheet).InlineRef();
				}
				rSheet.RenameElement(elm_Layout);
				rSheet.SetPartIDKey(rSheet.PartIDKey_SheetName,rSheet.GetAttribute(atr_Name,WString::emptyStr,L"Sheet"+WString(iSheet)));
				rSheet.RemoveAttribute(atr_Name);
				vElement vSurf=rSheet.GetChildElementVector(elm_Surface);
				for(int iSurf=0;iSurf<vSurf.size();iSurf++){
					JDFResource rSurf=vSurf[iSurf];
					if(rSurf.IsRefElement()){
						rSurf=JDFRefElement(rSurf).InlineRef();
					}
					rSurf.RenameElement(elm_Layout);
					rSurf.SetPartIDKey(rSurf.PartIDKey_Side,rSurf.GetAttribute(atr_Side,WString::emptyStr,L"Surf"+WString(iSurf)));
					rSurf.RemoveAttribute(atr_Name);
				}
			}
		}
		return true;
	}	

	///////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////

	bool JDFLayout::FromNewLayout(){
		vElement vLO=JDFElement::GetChildElementVector(elm_Layout,WString::emptyStr,mAttribute(atr_SignatureName,WString::emptyStr),false);
		vElement vSig;
		if(vLO.empty()){
			JDFSignature signature = AppendElement(elm_Signature);
			signature.SetName("Sig_00");
			vSig.push_back(signature);
			moveElementsTo((JDFLayout)signature);
		}else{
			JDFSignature sig;
			for(int i=0;i<vLO.size();i++){
				JDFElement lo=vLO[i];
				if(lo.HasAttribute(atr_SignatureName)){
					lo.RenameAttribute(atr_SignatureName,atr_Name);
					sig = lo.RenameElement(elm_Signature);
					sig.cleanResourceAttributes();
					vSig.push_back(sig);
				}else{
					if(vSig.empty()){
						JDFSignature signature = AppendElement(elm_Signature);
						signature.SetName("Sig_00");
						vSig.push_back(sig);
					}
				}
				if(!sig.isNull())
					MoveElement(sig);
			}
		}

		int nSheet = 0;
		for(int iSig=0;iSig<vSig.size();iSig++){
			JDFSignature sig=vSig[iSig];
			vLO=JDFElement(sig).GetChildElementVector(elm_Layout,WString::emptyStr,mAttribute(atr_SheetName,WString::emptyStr),false);
			vElement vSheet;
			if(vLO.empty()){
				nSheet++;
				JDFSheet sheet = sig.AppendElement(elm_Sheet);
				sheet.SetName("Sheet_" + WString::valueOf(nSheet));
				vSheet.push_back(sheet);
				((JDFLayout)sig).moveElementsTo((JDFLayout)sheet);
			}else{
				JDFSheet sheet;
				for(int i=0;i<vLO.size();i++){
					sheet = JDFSheet();
					JDFElement lo=vLO[i];
					if(lo.HasAttribute(atr_SheetName)){
						lo.RenameAttribute(atr_SheetName,atr_Name);
						sheet=lo.RenameElement(elm_Sheet);
						sheet.cleanResourceAttributes();
						vSheet.push_back(sheet);
						nSheet++;
					}else{
						if(vSheet.empty()){
							nSheet++;
							sheet=sig.AppendElement(elm_Sheet);
							sheet.SetName("Sheet_"+WString::valueOf(nSheet));
							vSheet.push_back(sheet);
						}
						if (!sheet.isNull())
							sheet.MoveElement(lo);
					}
				}
			}	


			for(int iSheet=0;iSheet<vSheet.size();iSheet++){
				JDFSheet sheet=vSheet[iSheet];
				vLO=JDFElement(sheet).GetChildElementVector(elm_Layout,WString::emptyStr,mAttribute(atr_Side,WString::emptyStr),false);
				if(vLO.empty()){
					JDFSurface surf=sheet.AppendElement(elm_Surface);
					surf.SetSide(JDFPart::Side_Front);
					((JDFLayout)sheet).moveElementsTo((JDFLayout)surf);
				}else{
					for(int i=0;i<vLO.size();i++){
						JDFSurface surface=(JDFSurface)vLO[i];
						surface.RenameElement(elm_Surface);
						JDFPart::EnumSide sid = surface.GetSide();
						surface.cleanResourceAttributes();
						surface.SetSide(sid);
					}
				}							
			}
		}
		RemoveFromAttribute(atr_PartIDKeys,atr_SignatureName);
		RemoveFromAttribute(atr_PartIDKeys,atr_SheetName);
		RemoveFromAttribute(atr_PartIDKeys,atr_Side);
		return true;
	}

	/**
	* heuristics to check which version an element of a Layout is in: 1.3 or 1.2
	* 
	* Note that this routine is static since it must be used on all sheets, surfaces etc.
	* 
	* @param sheet the Sheet, Surface, Signature or Layout to check
	* @return true if this is a new, i.e. partitioned Layout
	* 
	*/
	bool JDFLayout::isNewLayout(const JDFResource& sheet)
	{

		// either Signature, Sheet or Surface --> old
		if(sheet.GetLocalName() != elm_Layout)
			return false;

		// it's a layout the only allowed (old) element is a signature , if it exists --> old
		if(sheet.HasChildElement(elm_Signature))
			return false;
		// it is a layout and it has no subelements and it is partitioned --> new
		JDFResource resourceRoot = sheet.GetResourceRoot();
		if(resourceRoot.HasAttribute(atr_PartIDKeys))
			return true;
        
		// it is a non partitioned layout and it has palacedobjects --> new
        if(resourceRoot.HasChildElement(elm_ContentObject)  ||
                resourceRoot.HasChildElement(elm_MarkObject))
            return true;

		// now I'm ready to punt - no partition and no subelements --> assume that version tags are correct
		WString v=sheet.GetVersion(true);

		// no version, we are 1.3 --> assume 1.3
		if(v.empty())
			return true;

		return v>=L"1.3";
	}

	   /**
     * gets the vector of all placed objects that reside directly in this partition
     * retains the order of marks and content
     * 
     * @return the vector of placedobjects, null if none were found
     */
    vElement JDFLayout::getPlacedObjectVector()
    {
        vElement v;
        KElement n=GetFirstChildElement();
        while(!n.isNull())
        {
			WString s=n.GetLocalName();
            if((s==elm_ContentObject)||(s==elm_MarkObject))
            {
                v.add(n);
            }
            n=n.GetNextSiblingElement();
        }
        return v;
     }

	///////////////////////////////////////////////////////////////////////////////

	WString JDFLayout::ValidNodeNames() const
	{
		return L"*:,Layout,Sheet,Signature,Surface";
	}

	///////////////////////////////////////////////////////////////////////////////

	void JDFLayout::moveElementsTo(JDFLayout &target)
	{
		vElement vPO=getPlacedObjectVector();
		if(!vPO.empty())
        {
            for(int i=0;i<vPO.size();i++)
				target.MoveElement(vPO[i]);
        }
		vPO=JDFElement::GetChildElementVector(elm_Layout,WString::emptyStr,mAttribute::emptyMap,false);
		if(!vPO.empty())
        {
            for(int i=0;i<vPO.size();i++)
                target.MoveElement(vPO[i]);
        }
	}

	///////////////////////////////////////////////////////////////////////////////

	int JDFLayout::numSignatures()
	{
		return JDFSignature::numLayoutElements(*this, elm_Signature, atr_SignatureName);
	}

	///////////////////////////////////////////////////////////////////////////////
	
	JDFSignature JDFLayout::AppendSignature()
	{
		return appendLayoutElement(*this,elm_Signature,atr_SignatureName);
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////

	JDFSignature JDFLayout::GetCreateSignature(int iSkip)
	{
		JDFSignature s = GetSignature(iSkip);
		if (s.isNull())
			s=AppendSignature();
		return s;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////

	JDFSignature JDFLayout::GetSignature(int iSkip) const
	{
		return getLayoutElement(*this,elm_Signature,atr_SignatureName,iSkip);
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////

	WString JDFLayout::RequiredAttributes() const
	{
		return JDFResource::RequiredAttributes();
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////

}; // namespace JDF
