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
*/

///////////////////////////////////////////////////////////////////

 
//EndCopyRight


///////////////////////////////////////////////////////////////////


#include "jdf/wrapper/JDFColorPool.h"
#include "jdf/wrapper/JDFColor.h"
#include <iostream>

namespace JDF{

/**
* copy equivalance operator
*/
	JDFColorPool& JDFColorPool::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFColorPool: "+other.GetNodeName());
	return *this;
};
	
	///////////////////////////////////////////////////////////////////
	/**
	typesafe validator
	*/
	bool JDFColorPool::IsValid(EnumValidationLevel level)const{
		if(level<=ValidationLevel_Construct) {
			if(level<=ValidationLevel_None) 
				return true;
			if(isNull()) 
				return true;
		}
		bool bValid=JDFAutoColorPool::IsValid(level);
		if(!bValid) 
			return false;
		if(level>ValidationLevel_Construct) {
			bValid=!HasDuplicateColors();
		}
		return bValid;
	}
	
	///////////////////////////////////////////////////////////////////
	
	bool JDFColorPool::HasDuplicateColors()const{
		vElement v=GetChildElementVector(elm_Color);
		vWString vName;
		vWString vRawName;
		int nCols=v.size();
		for(int i=0;i<nCols;i++){
			JDFColor color=v[i];
			WString name=color.GetName();
			if(vName.hasString(name))
				return true;
			vName.push_back(name);
			WString rawName=color.Get8BitName();
			if(vRawName.hasString(rawName))
				return true;
			vRawName.push_back(name);
		}
		return false;
	}
	///////////////////////////////////////////////////////////////////

	JDFColor JDFColorPool::GetColorWithName(const WString&name)const{
		mAttribute m;
		m.AddPair(atr_Name,name);
		vElement v=GetChildElementVector(elm_Color,WString::emptyStr,m);
		if(v.size()==0){
			return JDFColor();
		}else if (v.size()>1){
			std::cout<<"JDFColorPool::GetColorWithName: too many colors\n";
		}
		return v[0];
	}
	///////////////////////////////////////////////////////////////////

	JDFColor JDFColorPool::GetColorWith8BitName(const char* rawName)const{
		vElement v=GetChildElementVector(elm_Color);

		for(int i=0;i<v.size();i++){
			JDFColor c=v[i];
			const char*pRawName=c.Get8BitName().GetRawBytes();
			if(!strcmp(pRawName,rawName)){
				return c;
			}
		}
		return JDFColor();
	}
	///////////////////////////////////////////////////////////////////

	JDFColor JDFColorPool::GetColorWithRawName(const char* rawName)const{
		WString hexRawName;
		hexRawName.SetHexBinaryBytes(rawName);
		mAttribute m(atr_RawName,hexRawName);
		vElement v=GetChildElementVector(elm_Color,WString::emptyStr,m);
		if(v.size()==0){
			return JDFColor();
		}else if (v.size()>1){ // not really an exception...
			std::cout<<"JDFColorPool::GetColorWithRawName: too many colors\n";
		}
		return v[0];
	}

	///////////////////////////////////////////////////////////////////

	JDFColor JDFColorPool::AppendColorWithName(const WString&name,const char* rawName){
		JDFColor col=GetColorWithName(name);
		if(col.isNull()){
			col=GetColorWith8BitName(rawName);
		}
		if(col.isNull()){
			col=AppendColor();
			col.Set8BitNames(rawName);
			col.SetName(name);
		}else{
			throw JDFException(L"JDFColorPool::AppendColorWithName color exists: "+name);
		}
		return col;
	}
	///////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////

	JDFColor JDFColorPool::GetCreateColorWithName(const WString&name,const char* rawName){
		JDFColor col=GetColorWithRawName(rawName);
		if(!col.isNull())
			return col;

// it only defaulted throught the transcoder, therefor redo
		col=GetColorWithName(name);

		if(col.isNull()){
			col=AppendColor();
			col.Set8BitNames(rawName);
			col.SetName(name);
		}else{
			if(col.HasAttribute(atr_RawName)){
				// snafu - the rawname is different
				throw JDFException(L"JDFColorPool::GetCreateColorWithName color is inconsistent: "+name);
				// tbd fix up
				col=AppendColor();
				col.Set8BitNames(rawName);
				
			}
		}
		return col;
	}
	///////////////////////////////////////////////////////////////////
	

	}; // namespace JDF
