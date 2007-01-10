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
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created  31.May.2000
//
// JDFRunList.cpp: implementation of the JDFRunList class.
//
//////////////////////////////////////////////////////////////////////
#include "JDFRunElement.h"
#include "JDFRunList.h"
#include "JDFLayoutElement.h"
#include "JDFFileSpec.h"
#include "JDFRefElement.h"

using namespace std;

namespace JDF{

	//////////////////////////////////////////////////////////////////////
	
	JDFRunList & JDFRunList::operator =(const KElement& other){
			JDFAutoRunList::operator=(other);
			if(!IsValid(ValidationLevel_Construct)) 
				throw JDFException(L"Invalid constructor for JDFRunList: "+other.GetNodeName()); 
			return *this;
	};
	
		//////////////////////////////////////////////////////////////////////

		JDFRunElementList JDFRunList::GetvRunElement(){
		vRunElement v;
		vElement vE=GetChildrenByTagName("Run");
		for(int i=0;i<vE.size();i++){
			JDFRunList r=vE[i];
			vRunElement vv=r.GetvRunElement();
			v.insert(v.end(),vv.begin(),vv.end());
		}
		
		return v;
	}
	//////////////////////////////////////////////////////////////////////
	
	JDFRunList JDFRunList::AddRun(WString fileName, int first, int last){
		JDFRunList r=AddPartition(PartIDKey_Run,L"Run"+UniqueID());
		r.init();
		IntegerRangeList irl;
		irl.Append(first,last);
		r.SetPages(irl);
		JDFLayoutElement loe=r.AppendLayoutElement();
		JDFFileSpec fs=loe.AppendFileSpec();
		fs.SetURL(fileName);
		return r;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFRunList::SetFileURL (const WString& url)
	{
		JDFLayoutElement lay = GetCreateLayoutElement();

		if (lay.isNull())
			return false;

		JDFFileSpec fspec = lay.GetCreateFileSpec();

		if (fspec.isNull())
			return false;

		fspec.SetURL (url);

		return true;
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFRunList::GetFileURL() const
	{
		if (!HasChildElement(elm_LayoutElement))
			return WString();

		JDFLayoutElement lay = GetLayoutElement();

		if (!lay.HasChildElement(elm_FileSpec))
			return WString();

		JDFFileSpec fspec = lay.GetFileSpec();

		if (!fspec.HasAttribute(atr_URL))
			return WString();

		return fspec.GetURL();
	}
	//////////////////////////////////////////////////////////////////////

	JDFRunList JDFRunList::AddSepRun(const WString& fileNames,const WString& sepNames, int first, int n, bool pageMajor, const WString& sep){
		return AddSepRun(fileNames.Tokenize(sep), sepNames.Tokenize(sep),  first,  n, pageMajor);
	}
	//////////////////////////////////////////////////////////////////////
	
	JDFRunList JDFRunList::AddSepRun(JDFLayoutElement layoutElement, const WString& sepNames, int firstPage, int nPage, bool pageMajor, const WString& sep){
		vElement v;
		v.push_back(layoutElement);
		return AddSepRun(v, sepNames.Tokenize(sep),  firstPage,  nPage, pageMajor);
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFRunList JDFRunList::AddSepRun(const vElement& vlayoutElement,const vWString& sepNames, int firstPage, int nPage, bool pageMajor){
		JDFRunList runList=AddPartition(PartIDKey_Run,L"Run"+UniqueID());
		int siz=vlayoutElement.size();
		runList.init();
		runList.SetNPage(nPage);
		runList.SetIsPage(true);

		for(int i=0;i<sepNames.size();i++){
			JDFRunList rs=runList.AddPartition(PartIDKey_Separation,sepNames[i]);
			rs.SetIsPage(false);
			JDFLayoutElement layoutElement=vlayoutElement[min(i,siz-1)];

			rs.RefElement(layoutElement);
			if(vlayoutElement.size()==sepNames.size()){
				rs.SetAttribute("FirstPage",firstPage);
			}else{
				if(pageMajor){
					rs.SetSkipPage((int)sepNames.size()-1);
					rs.SetFirstPage(i+firstPage);
				}else{
					rs.SetFirstPage(i*nPage+firstPage);
				}
			}
		}
		return runList;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFRunList JDFRunList::AddSepRun(const vWString& fileNames, const vWString& sepNames, int firstPage, int nPage, bool pageMajor){
		JDFRunList r=AddPartition(PartIDKey_Run,L"Run"+UniqueID());
		int siz=fileNames.size();
		r.init();
		r.SetNPage(nPage);
		r.SetIsPage(true);
		for(int i=0;i<sepNames.size();i++){
			JDFRunList rs=r.AddPartition(PartIDKey_Separation,sepNames[i]);
			rs.SetIsPage(false);
			JDFLayoutElement lo=rs.AppendLayoutElement();
			lo.init();
			lo.SetURL(fileNames[min(i,siz-1)]);
			if(fileNames.size()==sepNames.size()){
				rs.SetFirstPage(firstPage);
			}else{
				if(pageMajor){
					rs.SetSkipPage((int)sepNames.size()-1);
					rs.SetFirstPage(i+firstPage);
				}else{
					rs.SetFirstPage(i*nPage+firstPage);
				}
			}
		}
		return r;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFRunList JDFRunList::AddPDF(WString fileName, int first, int last){
		JDFRunList r=AddRun(fileName,first,last);
        JDFFileSpec fs=r.GetLayoutElement().GetFileSpec();
        fs.SetMimeType("application/PDF");
		return r;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFRunList JDFRunList::SetRunElements(JDFRunElementList vNew){
	/* TBD
	vElement vOld=GetChildVector("Run");
	if(!vNew.empty()){
	JDFIntegerRangeList rl;
	int pages=vNew[0].GetPage();
	vElement vRS=vNew[0].GetRunSeparation();
	rl.Append(pages);
	int vNS=vNew.size();
	for(int i=1;i<vNS;i++){
	if (pages+1==vNew[i].GetPage()){
				if(vRS==vNew[i].GetRunSeparation()){
				rl.Append(pages);
				pages++;
				if(i+1<vNS) continue;
				}
				};
				JDFResource run=AppendElement("Run");
				for(int k=0;k<vRL.size();k++){
				run.CopyNode(vRL[i]);
				}
				pages=vNew[i].GetPage();
				vRS=vNew[i].GetRunSeparation();
				}
				}
				for(int i=0;i<vOld.size();i++){
				vOld[i].DeleteNode();
				}
		*/
		return *this;
		
	}
	
	//////////////////////////////////////////////////////////////////////
	
	
	bool JDFRunList::ConsistentPartIDKeys(EnumPartIDKey key)const{
		if(GetImplicitPartitions().index((int)key)<0)
			return JDFAutoRunList::ConsistentPartIDKeys(key);

	
		return false;
	};
	
	////////////////////////////////////////////////////////////////////////////////////////////////
	vint JDFRunList::GetImplicitPartitions() const{
		vint v=JDFResource::GetImplicitPartitions();
		v.push_back((int) PartIDKey_RunIndex);
		v.push_back((int) PartIDKey_DocIndex);
		v.push_back((int) PartIDKey_DocRunIndex);
		v.push_back((int) PartIDKey_DocSheetIndex);
		v.push_back((int) PartIDKey_SetIndex);
		v.push_back((int) PartIDKey_PageNumber);
		
		return v;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////	

	WString JDFRunList::OptionalAttributes()const{
		return JDFAutoRunList::OptionalAttributes()+L",DocCopies";
	};

	//////////////////////////////////////////////////////////////////////////////////

	vWString JDFRunList::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		vWString v=JDFAutoRunList::GetInvalidElements(level, bIgnorePrivate, nMax);
		if(HasChildElement(elm_ByteMap)&&(HasChildElement(elm_LayoutElement)||HasChildElement(elm_InterpretedPDLData))){
			v.AppendUnique(elm_ByteMap);
		}
		if(HasChildElement(elm_LayoutElement)&&(HasChildElement(elm_ByteMap)||HasChildElement(elm_InterpretedPDLData))){
			v.AppendUnique(elm_LayoutElement);
		}
		if(HasChildElement(elm_InterpretedPDLData)&&(HasChildElement(elm_LayoutElement)||HasChildElement(elm_ByteMap))){
			v.AppendUnique(elm_InterpretedPDLData);
		}

		return v;
	}
	/////////////////////////////////////////////////////////////////////////

	bool JDFRunList::ValidEndOfBundleItem(EnumValidationLevel level) const {
		bool b=JDFAutoRunList::ValidEndOfBundleItem(level);
		b=b && !(HasAttribute(atr_EndOfBundleItem) && GetComponentGranularity()!=ComponentGranularity_BundleItem);
		return b;	
	};

	///////////////////////////////////////////////////////////////////
	/** getMimeType 
	*
	* Returns the MimeType attribute of the current RunList (partition). If the attribute does not exist, the 
	* empty string is returned.
	*
	* @param const JDF::JDFRunList& runList (in): The RunList partition to obtain the MimeType from.
	*
	* @return JDF::WString: The MimeType string, if the attribute is present, the empty string otherwise.
	* 
	*/
	WString JDFRunList::getMimeType()const
	{
		return GetLayoutElement().GetFileSpec().GetMimeType();
	}

	void JDFRunList::SetPages(const JDFIntegerRangeList& value)
	{
		JDFAutoRunList::SetPages(value);
		int count = value.NElements();
		if (count != 0)
			SetNPage(count);
	}
}