/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2007 The International Cooperation for the Integration of 
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
// created 04 Oct 2000
// JDFElement.cpp: wrapper around KElement
//
//////////////////////////////////////////////////////////////////////

#include "jdf/wrapper/JDFElement.h"
#include "jdf/wrapper/JDFAudit.h"
#include "jdf/wrapper/JDFAuditPool.h"
#include "jdf/wrapper/JDFProductionIntent.h"
#include "jdf/wrapper/JDFResourcePool.h"
#include "jdf/wrapper/JDFNode.h"
#include "jdf/wrapper/JDFJMF.h"
#include "jdf/wrapper/JDFComment.h"
#include "jdf/wrapper/JDFRefElement.h"
#include "jdf/wrapper/JDFFactory.h"
#include "jdf/wrappercore/XMLDoc.h"
#include "jdf/lang/VoidSet.h"
#include "jdf/lang/SetWString.h"
#include "jdf/util/PlatformUtils.h"
#include <xercesc/dom/DOMAttr.hpp>
#include <iostream>
XERCES_CPP_NAMESPACE_USE


using namespace std;
namespace JDF{



	// the static default version for any new elements
	static JDFElement::EnumVersion defaultVersion=JDFElement::Version_1_3;

	//////////////////////////////////////////////////////////////////////
	// Construction/Destruction
	//////////////////////////////////////////////////////////////////////
	JDFElement & JDFElement::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFElement: "+other.GetNodeName()); 
		return *this;
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	vWString JDFElement::GetChildIds(const WString & attrib,const WString & element,const WString & nameSpaceURI)const{
		vWString setID;
		if(throwNull()) 
			return setID;

		vElement nl=GetChildrenByTagName(element,nameSpaceURI,mAttribute::emptyMap,false);

		int l=nl.size();
		for (int i=0;i<l;i++){
			WString s=nl[i].GetAttribute(attrib,nameSpaceURI);
			if (s.empty())
				continue;
			setID.push_back(s);
		}
		return setID;
	}

	//////////////////////////////////////////////////////////////////////

	WString JDFElement::GetRefString()const {
		return GetNodeName()+atr_Ref;
	}

	//////////////////////////////////////////////////////////////////////

	JDFElement JDFElement::GetTarget()const{
		return KElement::GetTarget(GetHRef(),atr_ID);
	}; 

	//////////////////////////////////////////////////////////////////////
	JDFElement JDFElement::GetTarget(const WString & id, const WString & attrib) const{
		return KElement::GetTarget(id,attrib);
	};
	//////////////////////////////////////////////////////////////////////


	vElement JDFElement::GetLinks(const WString & elementName, const WString & nameSpaceURI)const{
		mAttribute m;
		m.AddPair(atr_rRef,GetID());
		// 290502 RP added line
		m.AddPair(atr_rSubRef,GetID());
		return GetDocRoot().GetChildrenByTagName(elementName,nameSpaceURI,m,false,false);
	}


	//////////////////////////////////////////////////////////////////////

	void JDFElement::SetTimeStamp(const WString & label){
		JDFDate dt;
		SetAttribute(label,dt.DateTimeISO());
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Typesafe attribute validation of ID
	*/
	bool JDFElement::ValidID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ID,AttributeType_string,false);
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFElement::RequiredLevel(EnumValidationLevel level)const{
		return (level==ValidationLevel_Complete)||(level==ValidationLevel_RecursiveComplete);
	};	

	//////////////////////////////////////////////////////////////////////

	bool JDFElement::RequiredOneOfAttribute(EnumValidationLevel level, const WString& att1, const WString& att2, const WString& att3, const WString& att4)const{
		if(RequiredLevel(level)){
			// either att1 xor att2
			return HasAttribute(att1) || HasAttribute(att2)|| ( (!att3.empty()) && HasAttribute(att3)) || ( (!att4.empty()) && HasAttribute(att4));
		}else{ 
			// anything goes
			return true;
		}
	};	
	//////////////////////////////////////////////////////////////////////

	bool JDFElement::ExclusiveOneOfAttribute(EnumValidationLevel level, const WString& att1, const WString& att2, const WString& att3, const WString& att4)const{
		int n=0;
		bool hasAtt1=HasAttribute(att1);
		n+=hasAtt1 ? 1 : 0;
		n+=HasAttribute(att2) ? 1 : 0;
		if(!att3.empty())
			n+=HasAttribute(att3) ? 1 : 0;
		if(!att4.empty())
			n+=HasAttribute(att4) ? 1 : 0;

		if(RequiredLevel(level)){
			// exactly one or more than one, but not this one
			return n==1 || ((!hasAtt1)&&(n>=1));
		}else{ 
			// at most one is good or more than one, but not this one
			return n<=1 || !hasAtt1;
		}
	};	

	bool JDFElement::RequiredOneOfElement(EnumValidationLevel level, const WString& elm1, const WString& ns1, const WString& elm2, const WString& ns2)const{
		if(RequiredLevel(level)){
			// either att1 xor att2
			return HasChildElement(elm1,ns1) || HasChildElement(elm2,ns2);
		}else{ 
			// anything goes
			return true;
		}
	};	
	//////////////////////////////////////////////////////////////////////

	bool JDFElement::ExclusiveOneOfElement(EnumValidationLevel level, const WString& elm1, const WString& ns1, const WString& elm2, const WString& ns2)const{
		int n=0;
		n+=HasChildElement(elm1,ns1) ? 1 : 0;
		n+=HasChildElement(elm2,ns2) ? 1 : 0;
		if(RequiredLevel(level)){
			// exactly one
			return n==1;
		}else{ 
			// at most one is good
			return n<=1;
		}
	};	

	//////////////////////////////////////////////////////////////////////

	JDFElement::EnumVersion JDFElement::GetEnumVersion(bool bInherit) const 
	{
		WString s=GetVersion(bInherit);
		if(s.empty()) 
			return (EnumVersion)0;

		int enumIndex=VersionString().PosOfToken(s,WString::comma);
		// unknown or illegal
		if(enumIndex<0)
			return (EnumVersion)0;

		return (EnumVersion) enumIndex; 
	};

	//////////////////////////////////////////////////////////////////////

	WString JDFElement::GetVersion(bool bInherit) const 
	{
		if(bInherit){
			JDFNode n=IsJDFNode() ? *this : GetParentJDF();
			return n.GetAncestorAttribute(atr_Version);
		}else{
			return GetAttribute(atr_Version);
		}
	};	

	//////////////////////////////////////////////////////////////////////

	bool JDFElement::FixVersion(EnumVersion version){
		bool bRet=true;
		vElement v=KElement::GetChildElementVector(); // do not follow refelements
		for(int i=0;i<v.size();i++){
			JDFElement e=v[i];
			JDFFactory f(e);
			JDFElement& r=f.GetRef();
			bool bRet2=r.FixVersion(version);
			bRet=bRet&&bRet2; // always fix
		}

		// replace all "~" with " ~ "
		mAttribute m=GetAttributeMap();
		int siz=m.size();
		for(int j=0;j<siz;j++){
			WString s=m.GetValueByPos(j);
			if(s.find(WString::tilde)!=WString::npos){
				try{
					JDFNumberRangeList nrl(s);
					SetAttribute(m.GetKeyByPos(j),nrl);
				}catch(JDFException &e){
					e.getType();
				}catch(IllegalArgumentException &ie){
					ie.getType();
				}
			}
		}

		return bRet;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFElement::IsValid(EnumValidationLevel level)const{
		// I can construct from a null object
		try{
			if(level<=ValidationLevel_Construct) {
				if(level<=ValidationLevel_None) 
					return true;
				if(isNull()) 
					return true;
			}else{
				if(GetInvalidAttributes(level,true,1).size()>0) 
					return false;
				if(GetInvalidElements(level,true,1).size()>0) 
					return false;
			}
			WString s=ValidNodeNames();
			if(s.compare(WString::star)){
				vWString vValidNames=GetValidNodeNames();
				WString nn=GetLocalName();
				bool checkNodeName=IsInJDFNameSpace();
				if(!checkNodeName){ // it is not in the jdf namespace
					// first check whether the namespace was simply incorrectly specified
					WString qualNodeName=GetNodeName();
					if((!vValidNames.hasString(nn))&&(!vValidNames.hasString(qualNodeName))&&(!vValidNames.hasString(L"*:"))){
						return false;
					}
				}else{ // it is in the jdf namespace
					if(!vValidNames.hasString(nn)){
						return false; // name not found
					}
				}
			}
			if(level>=ValidationLevel_RecursiveIncomplete){
				EnumValidationLevel valDown=(level==ValidationLevel_RecursiveIncomplete) ? ValidationLevel_Incomplete : ValidationLevel_Complete;
				vElement v=KElement::GetChildElementVector();
				for(int i=0;i<v.size();i++){
					if(((JDFElement&)v[i]).IsRefElement()){
						JDFRefElement re=v[i];
						if(!re.IsValid(valDown)) 
							return false;
					}
				}
			}
			return true;
		}catch(JDFException& e){
			e.getType();
			return false;
		}
	}

	//////////////////////////////////////////////////////////////////////

	// define a link ID
	WString JDFElement::IDString(int id)const{
		char buf[20];
		sprintf(buf,"L%i",id);
		return buf;
	}


	//////////////////////////////////////////////////////////////////////

	WString JDFElement::NewID(const WString& lastID)
	{
		if(lastID.empty())
			return GetIDPrefix()+UniqueID();
		JDFElement p=GetParentNode();
		if(p.isNull())
			return GetIDPrefix()+UniqueID();
		return GenerateDotID(KElementStrings::atr_ID);
	}

	//////////////////////////////////////////////////////////////////////

	WString JDFElement::GenerateDotID(const WString& key,const WString& nameSpaceURI){
		WString nodeName=GetLocalName();
		JDFElement p=GetParentNode();
		if(p.isNull())
			return GetIDPrefix()+UniqueID();
		WString parentID=p.GetAttribute(key,nameSpaceURI);
		if(parentID.empty())
			return GetIDPrefix()+UniqueID();

		vElement vn=p.GetChildElementVector(nodeName,nameSpaceURI);
		int siz=vn.size();
		parentID+=WString::dot;

		for(int i=siz;i<10000;i++){
			WString nn=parentID+WString::valueOf(i);
			bool bFound=false;
			for(int j=0;j<siz;j++){
				if(!nn.compare(vn[j].GetAttribute(key,nameSpaceURI))){
					bFound=true;
					break;
				}
			}
			if(!bFound){
				return nn;
			}
		}
		// panic exit!
		return GetIDPrefix()+UniqueID();
	}
	//////////////////////////////////////////////////////////////////////

	unsigned int JDFElement::GetEnumAttribute(const WString & key, const WString& allowedValues, const WString & nameSpaceURI, unsigned int def, bool bInherit)const{
		WString s;
		if(bInherit){
			s=GetInheritedAttribute(key,nameSpaceURI);
		}else{
			s=GetAttribute(key,nameSpaceURI);
		}
		if(s.empty()) 
			return def;

		int enumIndex=allowedValues.PosOfToken(s,WString::comma);

		// unknown or illegal
		if(enumIndex<0)
			return 0;

		return enumIndex; 
	}

	//////////////////////////////////////////////////////////////////////

	vint JDFElement::GetEnumerationsAttribute(const WString &  key, const WString & allowedValues, const WString & nameSpaceURI,unsigned int def, bool bInherit)const{
		vWString vs;
		if(bInherit){
			vs=GetInheritedAttribute(key,nameSpaceURI);
		}else{
			vs=GetAttribute(key,nameSpaceURI);
		}
		vint ret;

		if(vs.empty()) {
			if(def<0x80000000) // RP051201 used to be >0 but note unsigned 
				ret.push_back(def);
			return ret;
		}

		vWString vAllowed=allowedValues.Tokenize(WString::comma);
		// 080502 RP was vAllowed,size - oops
		for(int i=0;i<vs.size();i++){
			int enumIndex=vAllowed.index(vs[i]);
			if(enumIndex>=0){
				ret.push_back(enumIndex);
			}else{
				// illegal value
				ret.push_back(0);
			}
		}

		return ret; 
	}

	//////////////////////////////////////////////////////////////////////

	unsigned int JDFElement::GetEnumNodeName(const WString& allowedValues)const{
		int i=allowedValues.PosOfToken(GetLocalName(),WString::comma);
		return i<0 ? 0 : i;
	}

	//////////////////////////////////////////////////////////////////////

	void JDFElement::SetEnumAttribute(const WString & key, unsigned int value,const WString& allowedValues,const WString & nameSpaceURI, bool bAllowUnknown){
		if((value>0)||(bAllowUnknown&&(value==0))){
			WString token=allowedValues.Token(value,WString::comma);
			if(token.empty()){				
				throw JDFException(L"JDFElement::SetEnumAttribute illegal value for attribute"+key+L" int value: "+WString::valueOf(value));
			}
			SetAttribute(key,token,nameSpaceURI);
		}else{ // don't set explicit value of "Unknown"
			throw JDFException(L"JDFElement::SetEnumAttribute illegal value for attribute"+key+L" int value: "+WString::valueOf(value));
		}
	}

	//////////////////////////////////////////////////////////////////////

	void JDFElement::SetEnumerationsAttribute(const WString & key, const vint& value,const WString& allowedValues,const WString & nameSpaceURI){
		vWString vAllowed=allowedValues.Tokenize(WString::comma);
		WString s;
		int n=0;
		for(int i=0;i<value.size();i++){
			int vi=value[i];
			if(vi>0){ // don't set explicit value of "Unknown"				
				if(vi>=vAllowed.size()) // NB removed (vi==0)
					throw JDFException("JDFElement::SetEnumerationsAttribute illegal value");
				if(n++) 
					s+=WString::blank;
				s+=vAllowed[vi];
			}
		}
		if(n){
			SetAttribute(key,s,nameSpaceURI);
		}else{ // don't set empty lists
			RemoveAttribute(key,nameSpaceURI);
		}
	}

	//////////////////////////////////////////////////////////////////////

	vint JDFElement::AddEnumerationsAttribute(const WString & key, int value,const WString& allowedValues,const WString & nameSpaceURI){
		vint vi=GetEnumerationsAttribute(key,allowedValues,nameSpaceURI);
		if(value<0)
			return vi;
		int i;
		for(i=0;i<vi.size();i++){
			if(vi[i]==value)
				return vi; // already there
		}
		vi.push_back(value);
		SetEnumerationsAttribute(key,vi,allowedValues,nameSpaceURI);
		return vi;
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFElement::HasEnumerationsAttribute(const WString & key, int value,const WString& allowedValues,const WString & nameSpaceURI)const{
		vint vi=GetEnumerationsAttribute(key,allowedValues,nameSpaceURI);
		if(value<0)
			return false;
		int i;
		for(i=0;i<vi.size();i++){
			if(vi[i]==value) 
				return true; // already there
		}
		return false;
	}
	//////////////////////////////////////////////////////////////////////

	vint JDFElement::RemoveEnumerationsAttribute(const WString & key, int value,const WString& allowedValues,const WString & nameSpaceURI){
		vint vi=GetEnumerationsAttribute(key,allowedValues,nameSpaceURI);
		if(value<0)
			return vi;
		int i;
		for(i=vi.size()-1;i>=0;i--){
			if(vi[i]==value) {
				vi.erase(vi.begin()+i); // already there zapp it - continue in case it's corrupt and has double entries
			}
		}
		SetEnumerationsAttribute(key,vi,allowedValues,nameSpaceURI);
		return vi;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFElement::ValidAttribute(const WString & key,EnumAttributeType iType,bool bRequired,const WString & nameSpaceURI)const{

		if(!HasAttribute(key,nameSpaceURI))
			return !bRequired;

		WString val=GetAttribute(key,nameSpaceURI);

		switch(iType){
		case AttributeType_Unknown: 
			return true;
		case AttributeType_Any: 
			return true;
		case AttributeType_string: 
			return true;
		case AttributeType_longString: 
			return true;
		case AttributeType_shortString: 
			return val.size()<64;
		case AttributeType_ID: {
			return val.isNMTOKEN();
							   }
		case AttributeType_NMTOKEN: 
			return val.isNMTOKEN();
		case AttributeType_NMTOKENS: 
			return val.isNMTOKENS();
		case AttributeType_IDREF: 
			return val.isNMTOKEN();
		case AttributeType_IDREFS: 
			return val.isNMTOKENS();
		case AttributeType_enumeration: 
			return val.isNMTOKEN();
		case AttributeType_enumerations: 
			return val.isNMTOKENS();
		case AttributeType_boolean: 
			return val.isBoolean();
		case AttributeType_double: 
			return val.isNumber();
		case AttributeType_integer:
			return val.isInteger();

		case AttributeType_IntegerRange:{
			try{
				JDFIntegerRange ir(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
										}

		case AttributeType_IntegerList:{
			try{
				JDFIntegerList il(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
									   }

		case AttributeType_IntegerRangeList:{
			try{
				JDFIntegerRangeList irl(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
											}

		case AttributeType_NumberRange:{
			try{
				NumberRange nr(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
									   }

		case AttributeType_NumberRangeList:{
			try{
				JDFNumberRangeList nrl(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
										   }

		case AttributeType_NameRangeList:{
			try{
				JDFNameRangeList nrl(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
										 }

		case AttributeType_NumberList:{
			try{
				JDFNumberList nl(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
									  }

		case AttributeType_matrix:{
			try{
				JDFMatrix m(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
								  }

		case AttributeType_rectangle:{
			try{
				JDFRectangle r(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
									 }

		case AttributeType_shape:{
			try{
				JDFShape s(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
								 }

		case AttributeType_XYPair:{
			try{
				JDFXYPair p(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
								  }

		case AttributeType_XYPairRange:{
			try{
				JDFXYPairRange pr(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
									   }

		case AttributeType_XYPairRangeList:{
			try{
				JDFXYPairRangeList prl(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
										   }


		case AttributeType_dateTime:{
			try{
				JDFDate dt(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
									}

		case AttributeType_duration:{
			try{
				JDFDuration d(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
									}

		case AttributeType_DurationRange:{
			try{
				JDFDurationRange dr(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
										 }

		case AttributeType_DurationRangeList:{
			try{
				JDFDurationRangeList drl(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
											 }

		case AttributeType_DateTimeRange:{
			try{
				JDFDateTimeRange dtr(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
										 }

		case AttributeType_DateTimeRangeList:{
			try{
				JDFDateTimeRangeList dtrl(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
											 }

		case AttributeType_RectangleRangeList:{
			try{
				JDFRectangleRangeList rrl(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
											  }

		case AttributeType_ShapeRangeList:{
			try{
				JDFShapeRangeList srl(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
										  }

		case AttributeType_URL:{
			return true;
							   }

		case AttributeType_URI:{
			return true;
							   }

		case AttributeType_PDFPath:{
			return true;
								   }
		case AttributeType_XPath:{
			return true;
								 }
		case AttributeType_language:{
			int l=val.length();
			// languages are of format de, us, en-gb
			return (l>=2)&&(l<=6)&&val.isNMTOKEN();
									}
		case AttributeType_languages:{
			// languages are of format de, us, en-gb
			return val.isNMTOKENS();
							   }

		case AttributeType_regExp: {
			return true;
								   }
		case AttributeType_hexBinary: {
			return true;
									  }

		case AttributeType_LabColor:{
			try{
				JDFLabColor p(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
									}

		case AttributeType_RGBColor:{
			try{
				JDFRGBColor p(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
									}

		case AttributeType_CMYKColor:{
			try{
				JDFCMYKColor p(val);
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
									 }
		case AttributeType_TransferFunction:{
			try{
				JDFNumberList p(val);
				if(p.size()%2) 
					return false; // must have even # entries
			}catch (JDFException& e){
				e.getType(); // fool compiler
				return false;
			}catch (IllegalArgumentException& ie){
				ie.getType(); // fool compiler
				return false;
			}
			return true;
											}

		} // end switch
		return false;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFElement::ValidEnumAttribute(const WString & key,const WString& allowedValues,bool bRequired,const WString & nameSpaceURI, bool bAllowUnknown)const{
		static const WString pSystemSpecified=L"SystemSpecified";
		if(!HasAttribute(key,nameSpaceURI)) 
			return !bRequired;
		int i= GetEnumAttribute(key,allowedValues,nameSpaceURI,-1);
		if((i>0)||(bAllowUnknown&&(i==0)))
			return true;
		if(GetAttribute(key,nameSpaceURI)==pSystemSpecified)
			return true;
		return false;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFElement::ValidEnumerationsAttribute(const WString & key,const WString& allowedValues,bool bRequired,const WString & nameSpaceURI)const{
		if(!HasAttribute(key,nameSpaceURI)) 
			return !bRequired;
		vint v=GetEnumerationsAttribute(key,allowedValues,nameSpaceURI,-1);
		for(int i=0;i<v.size();i++) {
			if(v[i]==-1) 
				return false;
		}
		return true;
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFElement::GetEnumString(unsigned int value,const WString& allowedValues)const{
		return allowedValues.Token(value,WString::comma);
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFElement::UniqueID(int ID){
		WString s;
		static int id=ID;
		if(ID<0){ // increment by a large chunk e.g. in case of spawning
			id=id-ID;
		}

		if(ID>0){ 
			id=ID; // reset dynamically!
		}

		id=id%1000000;
		char buf[8];
		sprintf(buf,"_%.6i",id++);
		
		if(XMLDoc::getGenerateUID())
		{
			s=PlatformUtils::createUID();
		}

		if(s.empty())
		{
			JDFDate md;
			s= md.DateYYYYMMDD()+md.TimeHHMMSSsss();
			// for the beginning, use a readable but not so unique id
			// RP 280604 made longer but more unique by retaining the date
			s=s.substr(2);
		}
		s+=(char*)buf;
		return s;
	}

	//////////////////////////////////////////////////////////////////////

	void JDFElement::AppendHRef(JDFElement target, const WString & refAttribute, const WString & preSet){
		if(target.throwNull()) 
			return;
		WString idRef=target.GetID();
		if(idRef.empty()){
			target.AppendAnchor(preSet);
			idRef=target.GetID();
		}
		AppendHRef(idRef,refAttribute);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFElement::AppendHRef(const WString & idRef, WString refAttribute,const WString & nameSpaceURI){
		if((throwNull())||(idRef.size()<1)) 
			return;
		SetAttribute(refAttribute,idRef,nameSpaceURI);
	}

	//////////////////////////////////////////////////////////////////////

	WString JDFElement::AppendAnchor(const WString & name){
		if(throwNull()) 
			return WString::emptyStr;

		if(!GetID().empty()) 
			return GetID();

		WString n=name;
		if(name.empty())
		{
			JDFNode nod=GetJDFRoot();
			WString w=nod.GetSpawnID().rightStr(6);
			if(!w.empty())
				w=WString::dot+w+WString::dot;
			
			n = GetIDPrefix() + w +UniqueID();
		}

		SetAttribute(atr_ID,n);
		return n;
	}

	//////////////////////////////////////////////////////////////////////


	JDFNode JDFElement::GetParentJDF()const
	{
		if(IsJDFNode()){
			JDFElement par=GetParentNode();
			if(par.IsJDFNode()){
				return JDFNode(par).GetDeepParent(elm_JDF);
			}else{
				// JDF was embedded in something else and has no JDF parent!
				return JDFNode();
			}
		}
		return GetDeepParent(elm_JDF);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFElement::IsRefElement()const{
		if(throwNull())
			return false;
		bool bRef=!(GetNodeName().rightStr(3).compare(atr_Ref));
		if(!bRef) 
			return false;
		return true;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFElement::IsResource(bool createFactory)const{
		if(throwNull())
			return false;
		if(IsComment())
			return false;
		if (ValidEnumAttribute(atr_Class,JDFResource::ClassString(),true))
			return true;
		if(createFactory){
			JDFFactory f(*this);
			return f.GetRef().IsResource(false);
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFElement::IsSpan()const{
		if(throwNull())
			return false;
		if(IsComment())
			return false;
		if(HasAttribute(atr_DataType))
			return GetAttribute(atr_DataType).endsWith(L"Span");
		return false;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFElement::IsAudit()const{
		if(throwNull())
			return false;
		if(IsComment())
			return false;
		if(GetLocalName()==elm_AuditPool)
			return false;
		return !GetDeepParent(elm_AuditPool).isNull();
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFElement::IsJDFNode()const{
		if(throwNull())
			return false;
		return GetLocalName()==elm_JDF;
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFElement::IsResourceLink()const{
		if(throwNull())
			return false;
		if(GetLocalName().rightStr(4).compare(atr_Link)) 
			return false;

		return true;
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFElement::IsResourceUpdate()const{
		if(throwNull())
			return false;
		if(GetLocalName().rightStr(6).compare(atr_Update)) 
			return false;

		return true;
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFElement::IsComment()const{
		if(throwNull())
			return false;
		if(GetLocalName().compare(elm_Comment)) 
			return false;
		return true;
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFElement::isJDFJMF()const
	{
		if(throwNull())
			return false;
		if(GetLocalName()==elm_JMF) 
			return true;
		return false;
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFElement::isJDFNodeInfo()const
	{
		if(throwNull())
			return false;
		if(GetLocalName()==elm_NodeInfo) 
			return true;
		return false;
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFElement::isJDFCustomerInfo()const
	{
		if(throwNull())
			return false;
		if(GetLocalName()==elm_CustomerInfo) 
			return true;
		return false;
	}

	//////////////////////////////////////////////////////////////////////

	JDFResource JDFElement::GetLinkRoot(const WString& id)const {

		JDFResource ret;

		if(throwNull())
			return ret;

		WString id_=id.empty()?GetAttribute(atr_rRef):id;
		const JDFCh* pc_ID=id_.c_str();
		bool bSearching=true;

		bool hasUserData=GetOwnerDocument().HasXMLDocUserData();
		if(hasUserData){
			ret=GetOwnerDocument().GetTarget(id_);
			if(!ret.isNull()){
				if(!ret.IsResourceRootRoot()){
					ret = JDFResource();
				}
				if(!ret.isNull()){
					bSearching=false;

					JDFNode nodeResource=ret.GetParentJDF();
					JDFNode nodeLink=GetParentJDF();
					if(!(nodeResource==nodeLink)&&!(nodeResource.IsAncestor(nodeLink)))
						ret = JDFResource();
					bSearching=true;
				}
			}
		}

		if(ret.isNull()){
			// start with the first parent jdf node, which may be this so that nod is initialized 
			JDFElement nod=GetDeepParent(elm_JDF,0);

			bool hasJDF=!nod.isNull();

			if(hasJDF){
				while(bSearching){
					// if this is a JDF, also search here

					// low level for speed sake
					JDFElement rp=nod.GetElement(elm_ResourcePool);

					if(!rp.isNull()){				
						JDFElement r=rp.GetFirstChildElement();

						while(!r.isNull())
						{
							DOMAttr* da=r.GetDOMAttr(L"ID",0,false);
							if(da!=0 && !wcscmp(pc_ID,da->getNodeValue())&& !r.IsComment() )
							{
								bSearching=false;
								ret=r;
								break;
							}
							r=r.GetNextSiblingElement();
						}
					}

					// GetParentJDF always goes down by one
					if(bSearching){
						nod=nod.GetParentNode();
						if(nod.GetLocalName()!=elm_JDF){
							nod=DefKElement;
						}
						bSearching=!nod.isNull();
					}
				}
			}else{ // we may be in a in a JMF
				JDFElement jmf=GetDeepParent(elm_JMF,0);
				if(!jmf.isNull()){
					return jmf.GetChildWithAttribute(WString::star,atr_ID,WString::star,id_,0,false);
				}
			}
		}
		if(!ret.isNull() && hasUserData){
			GetOwnerDocument().SetTarget(ret,id_);
		}

		return ret;
	};	//////////////////////////////////////////////////////////////////////

	vWString JDFElement::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts;
		int n=0;
		if(!ValidSettingsPolicy(level)) {
			vAtts.push_back(atr_SettingsPolicy);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidDescriptiveName(level)) {
			vAtts.push_back(atr_DescriptiveName);
			if(++n>=nMax) 
				return vAtts;
		};

		// 300402 RP added for JDF 1.1
		if(!ValidBestEffortExceptions(level)) {
			vAtts.push_back(atr_BestEffortExceptions);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidMustHonorExceptions(level)) {
			vAtts.push_back(atr_MustHonorExceptions);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidOperatorInterventionExceptions(level)) {
			vAtts.push_back(atr_OperatorInterventionExceptions);
			if(++n>=nMax) 
				return vAtts;
		};

		// empty ns uri definitions.. 
		if(GetAttribute(atr_xmlns,WString::emptyStr,WString::quote)==WString::emptyStr){
			vAtts.push_back(atr_xmlns);
			if(++n>=nMax) 
				return vAtts;
		};

		if(RequiredLevel(level))
			vAtts.AppendUnique(GetMissingAttributes(nMax));

		if(vAtts.size()>=nMax)
			return vAtts;

		vAtts.AppendUnique(GetUnknownAttributes(bIgnorePrivate,nMax));
		return vAtts;
	};


	//////////////////////////////////////////////////////////////////////


	vWString JDFElement::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		vWString vBad;
		int i;
		int n=0;
		int nElem=NumChildElements(elm_Comment);
		for(i=0;i<nElem;i++){
			if (!GetComment(i).IsValid(level)) {
				vBad.push_back(elm_Comment);
				if (++n>=nMax) 
					return vBad;
			};
		}

		// now get all invalid ref elements
		vElement v=GetRefElements();
		for(i=0;i<v.size();i++){
			JDFRefElement rE=v[i];
			if(!rE.IsValid()){
				vBad.push_back(rE.GetNodeName());
				if (++n>=nMax) 
					return vBad;

			}
		}


		if(RequiredLevel(level))
			vBad.AppendUnique(GetMissingElements(nMax));

		if(vBad.size()>=nMax)
			return vBad;

		vBad.AppendUnique(GetUnknownElements(bIgnorePrivate,nMax));
		return vBad;
	}

	///////////////////////////////////////////////////////////////////////

	KElement JDFElement::GetElement(const WString& nodeName,const WString & nameSpaceURI, int iSkip)const{
		if(throwNull()) 
			return KElement();
		if (iSkip < 0)
			iSkip = NumChildElements(nodeName,nameSpaceURI) + iSkip;

		const JDFCh* pcNodeName=nodeName.c_str();
		const JDFCh* pcNameSpaceURI=nameSpaceURI.c_str();

		// loop over the list
		int i=0;
		JDFElement e=GetFirstChildElement();

		bool bExplicitRefElement=nodeName.rightStr(3)==atr_Ref;

		while(!e.isNull()){
			if(e.FitsName(pcNodeName,pcNameSpaceURI)){
				// this guy is the one
				if(i++==iSkip) {
					// follow valid (!) refElements, invalid refelements are ignored
					// 300502 RP added check for explicit refelements
					if(e.IsRefElement()&&!bExplicitRefElement){	
						try{
							JDFRefElement re(e);
							KElement target=re.GetTarget();
							if(!target.isNull()) {
								return target;
							}
						}catch (JDFException ex){
							// simply ignore invalid refelements¬
						}
						i--; // this one was screwed up -> don't count it
					}else{ // not a refElement or explicitly want the refElement
						return e;
					}
				} 
			}
			e=e.GetNextSiblingElement();
		}

		// found no match
		return KElement();
	}

	///////////////////////////////////////////////////////////////////////	

	KElement JDFElement::RemoveChild(const WString & node, const WString & nameSpaceURI, unsigned int n){
		vElement v=GetChildElementVector(node,nameSpaceURI,mAttribute::emptyMap,true,0,false);

		if(n>=v.size())
			return KElement();

		// tbd clean up
		GetOwnerDocument().ClearTargets();
		// may NOT call removeChild since JDFResource calls to this routine may actually change the parent
		return v[n].DeleteNode();
	}

	//////////////////////////////////////////////////////////////////////


	void JDFElement::RemoveChildren(const WString&  nodeName,const WString & nameSpaceURI){
		// the loop allows jdf resources to recursively remove all children
		while(42){
			vElement v=GetChildElementVector(nodeName,nameSpaceURI,mAttribute::emptyMap,true,0,false);
			if(v.size()){
				for(int i=0;i<v.size();i++){
					// may NOT call removeChild since JDFResource calls to this routine may actually change the parent
					v[i].DeleteNode();
				}
				GetOwnerDocument().ClearTargets();
			}else{
				return;
			}
		}
	}

	///////////////////////////////////////////////////////////////////////


	// creates an inter resource link  to target.
	////////////////////////////////////////////////////////////////////////////

	JDFRefElement JDFElement::RefElement(const JDFResource& target){
		JDFRefElement newRef=AppendElement(target.GetNodeName()+atr_Ref,target.GetNamespaceURI());

		if(!target.IsResource()){
			throw JDFException(L"JDFElement::RefElement: may only reference to a resource or resource element");
		}
		// add the subref
		JDFResource r=target;
		JDFResource root=r.GetResourceRoot();
		// check whether it is a resource element
		if(r.IsResourceElement()){
			newRef.AppendHRef(target,atr_rSubRef);
			WString resourceName=root.GetNodeName();
		}
		// check whether it is a resource leaf or root
		if(!r.IsResourceRoot()){
			mAttribute partMap=r.GetPartMap();
			newRef.SetPartMap(partMap);
		}
		// ID is appended to the resource root of target
		newRef.AppendHRef(root,atr_rRef);


		// move the resource to the closest common ancestor if it is not already an ancestor of this
		while(!root.GetParentJDF().IsAncestor(newRef)){
			KElement parent=root.GetParentJDF();
            if(parent.isNull())
                break;

			root=root.GetParentJDF().GetParentJDF().GetCreateResourcePool().MoveElement(root);
		}

		return newRef;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* GetHRefs - get inter-resource linked resource IDs
	*
	* @param vDoneRefs (use null by default)
	* @param bRecurse if true recurse followed refs
	* @param bExpand if true expand partitioned resources
	*
	* @return VString - the vector of referenced resource IDs
	* 
	* @default GetHRefs(null, false);
	*/
	vWString JDFElement::GetHRefs(const vWString& vDoneRefs, bool bRecurse, bool bExpand)const{


		if(throwNull())
			return vDoneRefs;

		vWString vrRefs=vDoneRefs;
		SetWString h;

		if(bExpand&&IsResource())
		{
			JDFResource r=*this;
			vElement vLeaves=r.GetLeaves(true);
			int siz=vLeaves.size();
			for(int i=0;i<siz;i++)
				vLeaves.elementAt(i).fillHashSet(atr_rRef.c_str(),&h);
		}
		else
		{
			fillHashSet(atr_rRef.c_str(),&h);
		}
		int iFirstPos = vrRefs.size(); // get the previous size
		vWString v2;
		h.addTo(v2);

		vrRefs.AppendUnique(v2); // get the new size
		if(bRecurse)
		{
			int iLastPos  = vrRefs.size();

			// recurse only the new rrefs
			for (int i = iFirstPos; i < iLastPos; i++)
			{
				WString& s     = vrRefs.elementAt(i);
				JDFElement e = GetTarget(s, atr_ID);
				if (!e.isNull())
				{
					vrRefs = e.GetHRefs(vrRefs, true, bExpand);
				}
			}
		}

		return vrRefs;
	}

	////////////////////////////////////////////////////////////////////////////

	//@{
	/**
	Set attribute rRefs
	*/
	void JDFElement::SetrRefs(vWString value){
		SetAttribute(atr_rRefs,value);
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFElement::ValidrRefs(EnumValidationLevel level) const {
		return ValidAttribute(atr_rRefs,AttributeType_Any,false);
	};

	///////////////////////////////////////////////////////////////////////

	vWString JDFElement::AddResID(const WString & resID){
		vWString v;
		return v;
	}

	//////////////////////////////////////////////////////////////////////

	vElement JDFElement::GetvHRefRes(bool bRecurse)const{
		vWString sRefs=GetHRefs(vWString(),bRecurse);
		vElement v;
		for(int i=0;i<sRefs.size();i++){
			v.AppendUnique(GetTarget(sRefs[i]));
		}
		return v;
	}
	//////////////////////////////////////////////////////////////////////
	// removes an inter resource link  to target.
	////////////////////////////////////////////////////////////////////////////

	void JDFElement::RemoveRefElement(const JDFElement& target){
		WString id=target.GetID();
		if(id.empty())
			throw JDFException(L"RemoveRefElement: target has no id"); 
		vElement v=GetChildElementVector(target.GetRefString());
		for(int i=0;i<v.size();i++){
			JDFRefElement re=v[i];
			if(re.GetrRef()==id){
				re.DeleteNode();
				break;
			}
			if(re.GetrSubRef()==id){
				re.DeleteNode();
				// need to delete rref, nor rsubref from refs
				id=re.GetrRef();
				break;
			}
		}
	}


	////////////////////////////////////////////////////////////////////////////

	vWString JDFElement::UpDaterRefs()const{
		vWString vrRefs;
		if(throwNull())
			return vrRefs;

		vElement v=GetChildrenWithAttribute(WString::star,atr_rRef,WString::emptyStr,WString::emptyStr,false); // grabemall
		for(int i=0;i<v.size();i++){
			vrRefs.AppendUnique(v[i].GetAttribute(atr_rRef));
		}
		return vrRefs;
	}
	////////////////////////////////////////////////////////////////////////////

	VoidSet* JDFElement::GetAllRefs(VoidSet* vDoneRefs, bool bRecurse)const
	{		
		if(vDoneRefs->contains(GetDOMElement()))
			return vDoneRefs;

		vElement v=GetChildElementVector(); // grabemall
		for(int i=0;i<v.size();i++){
			JDFElement e=v[i];
			if(e.IsRefElement()){
				JDFRefElement ref=e;
				if(!vDoneRefs->contains(e.GetDOMElement()))
				{
					vDoneRefs->add(e.GetDOMElement());
					if(bRecurse){
						JDFResource r=ref.GetTarget();
						r.GetAllRefs(vDoneRefs,bRecurse);
					}
				}
			}else{ // recurse tree
				e.GetAllRefs(vDoneRefs,bRecurse);
			}
		}
		return vDoneRefs;
	}

	//////////////////////////////////////////////////////////////////////

	void JDFElement::InlineRefElements(const WString& nodeName,const WString & nameSpaceURI, bool bDirect){
		vElement v=GetRefElements();
		const JDFCh* pcNodeName=nodeName.c_str();
		const JDFCh* pcNameSpaceURI=nameSpaceURI.c_str();
		int i;
		int vSize=v.size();
		for(i=0;i<vSize;i++){
			JDFRefElement re=v[i];
			// it fits - inline it
			if(re.FitsName(pcNodeName,pcNameSpaceURI)){
				JDFElement e=re.InlineRef();
				// also recurse into followed refs...
			}
		}
		// now loop over all (!) children, to see if any descendants match
		if(!bDirect){
			v = GetChildElementVector();
			vSize=v.size();
			vSize = v.size();
			for (i = 0; i < vSize; i++)
			{           
				JDFElement e=v[i];
				e.InlineRefElements(nodeName,nameSpaceURI,bDirect);
			}
		}
	}

	//////////////////////////////////////////////////////////////////////

	vElement JDFElement::GetRefElements()const{
		vElement v=GetChildElementVector();
		// loop backwords so that I don't invalidate the vector by deleting
		for(int i=v.size()-1;i>=0;i--){
			JDFElement e=v[i];
			if(!e.IsRefElement()){
				v.erase(v.begin()+i);
			}
		}
		return v;
	};

	//////////////////////////////////////////////////////////////////////

	vmAttribute JDFElement::GetPartMapVector()const{
		vmAttribute v;
		vElement vE=KElement::GetChildElementVector(elm_Part);
		for(int i=0;i<vE.size();i++){
			v.push_back(vE[i].GetAttributeMap());
		}
		// fix explicit single empty part element
		if (v.size() == 1){ 
			if (v[0].empty()){
				v.clear();
			}
		}
		return v;
	}

	//////////////////////////////////////////////////////////////////////

	void JDFElement::SetPartMapVector(const vmAttribute & vParts){
		RemoveChildren(elm_Part);
		for(int i=0;i<vParts.size();i++){
			if(!vParts[i].empty()){
				JDFElement p=AppendElement(elm_Part);
				p.SetAttributes(vParts[i]);
			}
		}
	}

	//////////////////////////////////////////////////////////////////////

	void JDFElement::SetPartMap(const mAttribute & mPart){
		RemoveChildren(elm_Part);
		if(!mPart.empty()){
			JDFElement p=AppendElement(elm_Part);
			p.SetAttributes(mPart);
		}
	}
	//////////////////////////////////////////////////////////////////////
	///
	void JDFElement::RemovePartMap(const mAttribute & mPart){
		vElement vE=KElement::GetChildElementVector(elm_Part);
		for(int i=vE.size()-1;i>=0;i--){
			if(GetAttributeMap().SubMap(mPart)) 
				vE.erase(vE.begin()+i);
		}
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFElement::HasPartMap(const mAttribute & mPart){
		vElement vE=KElement::GetChildElementVector(elm_Part);
		for(int i=0;i<vE.size();i++){
			if(vE[i].GetAttributeMap().SubMap(mPart)) 
				return true;
		}
		return false;
	}
	//////////////////////////////////////////////////////////////////////

	/**
	* definition of optional elements in the JDF namespace
	* @return comma separated list of optional element names
	*/
	WString JDFElement::OptionalElements()const{
		static const WString optionalElements=L",Comment";
		return KElement::OptionalElements()+optionalElements;
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* definition of optional attributes in the JDF namespace
	* @return comma separated list of optional attribute names
	*/
	WString JDFElement::OptionalAttributes()const{
		static const WString optionalAttributes=L",SettingsPolicy,CommentURL,DescriptiveName,BestEffortExceptions,MustHonorExceptions,OperatorInterventionExceptions";
		return KElement::OptionalAttributes() + optionalAttributes;

	};
	//////////////////////////////////////////////////////////////////////
	/**
	* definition of the allowed node names for elements of this type
	* @return comma separated list of valid node names, * if any
	*/
	//////////////////////////////////////////////////////////////////////
	WString JDFElement::ValidNodeNames()const{
		return WString::star;
	};
	//////////////////////////////////////////////////////////////////////
	vWString JDFElement::GetValidNodeNames()const{
		return ValidNodeNames().Tokenize(WString::comma);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFElement::IsInJDFNameSpace()const{
		if(throwNull()) 
			return true;
		WString ns=GetNamespaceURI();
		return  ns.empty()  ||
			(ns.compareToIgnoreCase(GetSchemaURL(1,0))==0) ||
			(ns.compareToIgnoreCase(GetSchemaURL(1,1))==0);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFElement::init(){
		return true;
	}

	//////////////////////////////////////////////////////////////////////
	void JDFElement::SetAttribute(const WString & key, const WString & value, const WString & nameSpaceURI){
		KElement::SetAttribute(key,value,nameSpaceURI);
	}

	//////////////////////////////////////////////////////////////////////
	void JDFElement::SetAttribute(const WString & key, const JDFNumList& value, const WString & nameSpaceURI){
		KElement::SetAttribute(key,value.GetString(),nameSpaceURI);
	}
	//////////////////////////////////////////////////////////////////////
	void JDFElement::SetAttribute(const WString & key, const NumberRange& value, const WString & nameSpaceURI){
		KElement::SetAttribute(key,value.GetString(),nameSpaceURI);
	}
	//////////////////////////////////////////////////////////////////////
	void JDFElement::SetAttribute(const WString & key, const IntegerRange& value, const WString & nameSpaceURI){
		KElement::SetAttribute(key,value.GetString(),nameSpaceURI);
	}
	//////////////////////////////////////////////////////////////////////
	void JDFElement::SetAttribute(const WString & key, const NameRange& value, const WString & nameSpaceURI){
		KElement::SetAttribute(key,value.GetString(),nameSpaceURI);
	}
	//////////////////////////////////////////////////////////////////////
	void JDFElement::SetAttribute(const WString & key, const JDFDate& value, const WString & nameSpaceURI){
		KElement::SetAttribute(key,value.DateTimeISO(),nameSpaceURI);
	}
	//////////////////////////////////////////////////////////////////////
	void JDFElement::SetAttribute(const WString & key, const JDFDuration& value, const WString & nameSpaceURI){
		KElement::SetAttribute(key,value.DurationISO(),nameSpaceURI);
	}
	//////////////////////////////////////////////////////////////////////
	void JDFElement::SetAttribute(const WString & key, const JDFNumberRangeList& value, const WString & nameSpaceURI){
		KElement::SetAttribute(key,value.GetString(),nameSpaceURI);
	}
	//////////////////////////////////////////////////////////////////////
	void JDFElement::SetAttribute(const WString & key, const JDFIntegerRangeList& value, const WString & nameSpaceURI){
		KElement::SetAttribute(key,value.GetString(),nameSpaceURI);
	}
	//////////////////////////////////////////////////////////////////////
	void JDFElement::SetAttribute(const WString & key, const JDFXYPairRange& value, const WString & nameSpaceURI){
		KElement::SetAttribute(key,value.GetString(),nameSpaceURI);
	}
	//////////////////////////////////////////////////////////////////////
	void JDFElement::SetAttribute(const WString & key, const JDFXYPairRangeList& value, const WString & nameSpaceURI){
		KElement::SetAttribute(key,value.GetString(),nameSpaceURI);
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* returns the official JDF version string
	*/
	WString JDFElement::Version()const{
		static const WString v=L"1.3";
		return v;
	}

	/**
	* returns the JDFElement::EnumVersion that new elements will be generated in by default
	* @return JDFElement::EnumVersion
	*/
	JDFElement::EnumVersion JDFElement::getDefaultJDFVersion()
	{
		return defaultVersion;
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* sets the JDFElement::EnumVersion that new elements will be generated in by default
	* @param JDFElement::EnumVersion vers the new default version
	*/
	void JDFElement::setDefaultJDFVersion(JDFElement::EnumVersion vers)
	{
		defaultVersion=vers;
	}
	//////////////////////////////////////////////////////////////////////

	const WString& JDFElement::GetSchemaURL(int majorVersion, int minorVersion){
		static const WString s10=L"http://www.CIP4.org/JDFSchema_1";
		static const WString s11=L"http://www.CIP4.org/JDFSchema_1_1";
		if (majorVersion==1){
			if (minorVersion==0){
				return s10;
			}else if (minorVersion>=1){
				return s11;
			}
		}
		// not supported
		return WString::emptyStr;
	};

	//////////////////////////////////////////////////////////////////////

	JDFElement::EnumSettingsPolicy JDFElement::GetAttributeSettingsPolicy(const WString& key) const{
		EnumSettingsPolicy settingsPolicy=GetSettingsPolicy(true);
		if(settingsPolicy!=SettingsPolicy_BestEffort){
			if(GetBestEffortExceptions().hasString(key))
				return SettingsPolicy_BestEffort;
		}
		if(settingsPolicy!=SettingsPolicy_MustHonor){
			if(GetMustHonorExceptions().hasString(key))
				return SettingsPolicy_MustHonor;
		}
		if(settingsPolicy!=SettingsPolicy_OperatorIntervention){
			if(GetOperatorInterventionExceptions().hasString(key))
				return SettingsPolicy_OperatorIntervention;
		}
		return settingsPolicy;
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFElement::ValidCommentURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_CommentURL,AttributeType_URL,false);
	};
	//////////////////////////////////////////////////////////////////////
	/** 
	* Typesafe attribute validation of SettingsPolicy
	*/
	bool JDFElement::ValidSettingsPolicy(EnumValidationLevel level) const{
		return ValidEnumAttribute(atr_SettingsPolicy,SettingsPolicyString(),false);
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFElement::ValidStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Status,StatusString(),false);
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFElement::ValidDescriptiveName(EnumValidationLevel level) const {
		return ValidAttribute(atr_DescriptiveName,AttributeType_string,false);
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFElement::ValidBestEffortExceptions(EnumValidationLevel level) const{
		return ValidAttribute(atr_BestEffortExceptions,AttributeType_NMTOKENS,false);
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFElement::ValidMustHonorExceptions(EnumValidationLevel level) const{
		return ValidAttribute(atr_MustHonorExceptions,AttributeType_NMTOKENS,false);
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFElement::ValidOperatorInterventionExceptions(EnumValidationLevel level) const{
		return ValidAttribute(atr_OperatorInterventionExceptions,AttributeType_NMTOKENS,false);
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFElement::FitsName(const JDFCh* nodeName, const JDFCh* nameSpaceURI)const{
		if(KElement::FitsName(nodeName,nameSpaceURI))
			return true;

		// if this is a valid ResourceRef, it also fits
		int l=wcslen(nodeName);

		// performance enhanced for small strings
		if(l<125){
			JDFCh buf[128];
			memcpy(buf,nodeName,l*sizeof(JDFCh));
			wcscpy(buf+l,L"Ref");
			if(KElement::FitsName(buf,nameSpaceURI)){
				return true;
			}
		}else{
			WString refString=WString(nodeName)+atr_Ref;
			if(KElement::FitsName(refString.c_str(),nameSpaceURI)){
				return true;
			}
		}
		return false;

	}

	////////////////////////////////////////////////////////////////////////////////

	bool JDFElement::FitsName(const JDFCh* nodeName)const{
		if(KElement::FitsName(nodeName))
			return true;

		// if this is a valid ResourceRef, it also fits
		int l=wcslen(nodeName);

		// performance enhanced for small strings
		if(l<125){
			JDFCh buf[128];
			memcpy(buf,nodeName,l*sizeof(JDFCh));
			wcscpy(buf+l,L"Ref");
			if(KElement::FitsName(buf)){
				return true;
			}
		}else{
			WString refString=WString(nodeName)+atr_Ref;
			if(KElement::FitsName(refString.c_str())){
				return true;
			}
		}
		return false;

	}
	//////////////////////////////////////////////////////////////////////
	WString JDFElement::GetIDPrefix() const {
		static const WString l=L"l";
		return l;
	}

	//////////////////////////////////////////////////////////////////////
	JDFNode JDFElement::GetJDFRoot()const{
		return GetDeepParent(elm_JDF,99999999);
	}

	//////////////////////////////////////////////////////////////////////
	JDFJMF JDFElement::GetJMFRoot()const{
		return GetDeepParent(elm_JMF,99999999);
	}

	///////////////////////////////////////////////////////////////////////

	JDFElement JDFElement::GetChildWithMatchingAttribute(const WString & nodeName, const WString &  attName, const WString & nameSpaceURI, const WString & attVal, int index, bool bDirect,EnumAttributeType dataType)const{
		vElement v=GetChildrenByTagName(nodeName,nameSpaceURI,mAttribute(),bDirect);
		int siz=v.size();
		int n=0;
		for(int i=0;i<siz;i++){
			JDFElement e=v[i];
			e = e.GetTarget(); // NB fixed to use elements instead of refs
			if(e.IncludesMatchingAttribute(attName,attVal,dataType)){
				if(n++==index)
					return e;
			}
		}
		return JDFElement();

	}
	///////////////////////////////////////////////////////////////////////

	bool JDFElement::IncludesMatchingAttribute(const WString & attName, const WString & attVal,EnumAttributeType dataType)const{
		if (IncludesAttribute(attName,attVal)){
			return true;
		}
		bool bAny=dataType==AttributeType_Any;

		WString thisVal=GetAttribute(attName);

		if(bAny||(dataType==AttributeType_NMTOKENS)||(dataType==AttributeType_enumerations)||(dataType==AttributeType_IDREFS)){			
			// check for matching individual NMTOKEN
			vWString vs=thisVal.Tokenize();
			if(vs.hasString(attVal))
				return true;
		}

		if(dataType==AttributeType_IntegerList)
		{
			try{
				vWString vs=thisVal.Tokenize();
				for (int i=0; i<= vs.size()-1; i++)
				{					
					if ((int)vs[i] == (int)attVal)
						return true;
				}
			}catch (JDFException&){
			}catch (IllegalArgumentException& ){
			}
		}

		if(dataType==AttributeType_NumberList)
		{
			try{
				vWString vs=thisVal.Tokenize();
				for (int i=0; i<= vs.size()-1; i++)
				{					
					if ((double)vs[i] == (double)attVal)
						return true;
				}
			}catch (JDFException&){
			}catch (IllegalArgumentException&){
			}
		}

		if(dataType==AttributeType_NumberRange){
			try{
				JDFRange<double> r(thisVal);
				if(r.InRange(attVal)) 
					return true;
			}catch (JDFException&){
			}catch (IllegalArgumentException&){
			}
		}

		if(bAny||(dataType==AttributeType_NumberRangeList)){
			try{
				JDFNumberRangeList r(thisVal);
				if(r.InRange(attVal)) 
					return true;
			}catch (JDFException&){
			}catch (IllegalArgumentException&){
			}
		}

		if(dataType==AttributeType_IntegerRange){		
			try{
				JDFIntegerRange r(thisVal,999999);
				if(r.InRange(attVal)) 
					return true;
			}catch (JDFException&){
			}catch (IllegalArgumentException&){
			}
		}

		if(bAny||(dataType==AttributeType_IntegerRangeList)){		
			try{
				JDFIntegerRangeList r(thisVal,999999);
				if(r.InRange(attVal)) 
					return true;
			}catch (JDFException&){
			}catch (IllegalArgumentException&){
			}
		}

		if(dataType==AttributeType_XYPairRange){		
			try{
				JDFRange<JDFXYPair> r(thisVal);
				if(r.InRange(attVal)) 
					return true;
			}catch (JDFException&){
			}catch (IllegalArgumentException&){
			}
		}

		if(bAny||(dataType==AttributeType_XYPairRangeList)){		
			try{
				JDFXYPairRangeList r(thisVal);
				if(r.InRange(attVal)) 
					return true;
			}catch (JDFException&){
			}catch (IllegalArgumentException&){
			}
		}

		return false;
	}

	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////

	int JDFElement::NumChildElements(const WString& nodeName,const WString & nameSpaceURI)const{
		return JDFElement::GetChildElementVector(nodeName,nameSpaceURI,mAttribute::emptyMap,true,9999999,true).size();
	}

	//////////////////////////////////////////////////////////////////////

	vElement JDFElement::GetChildElementVector(const WString & nodeName, const WString & nameSpaceURI, const mAttribute &mAttrib, bool bAnd, unsigned int maxSize,bool bResolveTarget)const{
		vElement v;
		if(throwNull()) 
			return v;

		JDFElement e=GetFirstChildElement();
		int i=0;

		//		bool bExplicitRefElement=nodeName.rightStr(3)==atr_Ref;

		const JDFCh* pcNodeName=nodeName.c_str();
		const JDFCh* pcNameSpaceURI=nameSpaceURI.c_str();

		bool bAlwaysFit=IsWildcard(pcNodeName)&&IsWildcard(pcNameSpaceURI);
		bool bMapEmpty=mAttrib.empty();

		// don't need to get target if I don't care about the attributes, since I return the refElement anyhow
		//		bExplicitRefElement=bExplicitRefElement || bMapEmpty; 

		while(!e.isNull()){
			KElement target;
			if(bAlwaysFit || e.FitsName(pcNodeName,pcNameSpaceURI)){
				// follow valid (!) refElements, invalid refelements are ignored
				if(bResolveTarget&&(e.IsRefElement())){	
					try{
						JDFRefElement re=e;
						target=re.GetTarget();
						if(target.isNull()){
							target=e;
						}
					}catch (JDFException ex){
						// simply skip invalid refelements 
						target=e;						
					}
				}else{
					target=e;
				}
				if(!target.isNull()){
					if(bMapEmpty||target.IncludesAttributes(mAttrib,bAnd)){
						v.push_back(target);
						if(++i==maxSize) 
							break;
					}
				}
			}
			e=e.GetNextSiblingElement();
		}
		return v;
	}

	///////////////////////////////////////////////////////////////////////

	vWString JDFElement::GetElementNameVector(bool bLocal)const{
		vElement e=GetChildElementVector();
		vWString v;
		for(int i=0;i<e.size();i++) {
			JDFElement el=e[i];
			WString s;
			if(bLocal){
				s=el.GetLocalName();				
			}else{
				s=el.GetNodeName();				
			}
			if(el.IsRefElement()){
				s=s.leftStr(-3);
			}
			v.AppendUnique(s);
		}
		return v;
	}


	//////////////////////////////////////////////////////////////////////

	const WString& JDFElement::NamedColorString(){
		static const WString enums=WString(L"Unknown,White,Black,Gray,Red,Yellow,Green,Blue,Turquoise,Violet")
			+WString(L",Orange,Brown,Gold,Silver,Pink,Buff,Ivory,Goldenrod,Mustard,MultiColor,Cyan,Magenta,DarkWhite,DarkBlack")
			+WString(L",DarkGray,DarkRed,DarkYellow,DarkGreen,DarkBlue,DarkTurquoise,DarkViolet,DarkOrange,DarkBrown,DarkGold")
			+WString(L",DarkSilver,DarkPink,DarkBuff,DarkIvory,DarkGoldenrod,DarkMustard,DarkMultiColor,DarkCyan,DarkMagenta,LightWhite,LightBlack,LightGray,LightRed,LightYellow")
			+WString(L",LightGreen,LightBlue,LightTurquoise,LightViolet,LightOrange,LightBrown,LightGold,LightSilver,LightPink,LightBuff")
			+WString(L",LightIvory,LightGoldenrod,LightMustard,LightMultiColor,LightCyan,LightMagenta,ClearWhite,ClearBlack,ClearGray,ClearRed,ClearYellow,ClearGreen,ClearBlue,ClearTurquoise")
			+WString(L",ClearViolet,ClearOrange,ClearBrown,ClearGold,ClearSilver,ClearPink,ClearBuff,ClearIvory,ClearGoldenrod,ClearMustard,ClearDarkWhite")
			+WString(L",ClearDarkBlack,ClearDarkGray,ClearDarkRed,ClearDarkYellow,ClearDarkGreen,ClearDarkBlue,ClearDarkTurquoise,ClearDarkViolet,ClearDarkOrange,ClearDarkBrown")
			+WString(L",ClearDarkGold,ClearDarkSilver,ClearDarkPink,ClearDarkBuff,ClearDarkIvory,ClearDarkGoldenrod,ClearDarkMustard,ClearDarkMultiColor,ClearDarkCyan,ClearDarkMagenta,ClearLightWhite,ClearLightBlack,ClearLightGray,ClearLightRed")
			+WString(L",ClearLightYellow,ClearLightGreen,ClearLightBlue,ClearLightTurquoise,ClearLightViolet,ClearLightOrange,ClearLightBrown,ClearLightGold,ClearLightSilver,ClearLightPink")
			+WString(L",ClearLightBuff,ClearLightIvory,ClearLightGoldenrod,ClearLightMustard,ClearLightMultiColor,ClearLightCyan,ClearLightMagenta,NoColor"); 
		return enums;
	};

	//////////////////////////////////////////////////////////////////////

	WString JDFElement::NamedColorString(EnumNamedColor value){
		return NamedColorString().Token(value,WString::comma);
	};

	//////////////////////////////////////////////////////////////////////

	const WString& JDFElement::OrientationString(){
		static const WString enums=L"Unknown,Flip0,Flip90,Flip180,Flip270,Rotate0,Rotate90,Rotate180,Rotate270"; 
		return enums;
	};

	//////////////////////////////////////////////////////////////////////

	WString JDFElement::OrientationString(EnumOrientation value){
		return OrientationString().Token(value,WString::comma);
	};

	//////////////////////////////////////////////////////////////////////

	const WString& JDFElement::VersionString()
	{
		static const WString enums=L"Unknown,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9";
		return enums;
	}

	//////////////////////////////////////////////////////////////////////

	WString JDFElement::VersionString(EnumVersion value)
	{
		return VersionString().Token(value,WString::comma);
	}

	//////////////////////////////////////////////////////////////////////
	const WString& JDFElement::XYRelationString(){
		static const WString enums=L"Unknown,gt,ge,eq,le,lt,ne"; 
		return enums;
	};

	//////////////////////////////////////////////////////////////////////

	WString JDFElement::XYRelationString(EnumXYRelation value){
		return XYRelationString().Token(value,WString::comma);
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFElement::XYRelation(EnumXYRelation value, double x, double y, double nt, double pt ) const {

		switch (value) {

			case XYRelation_gt: 
				{					
					return (x+pt>y-nt); 
				}
			case XYRelation_ge:
				{					
					return (x+pt>=y-nt); 
				}
			case XYRelation_eq:
				{					
					return (x>=(y-nt)&&x<=(y+pt)); 
				}
			case XYRelation_le:
				{					
					return (x-nt<=y+pt);
				}
			case XYRelation_lt:
				{					
					return (x-nt<y+pt);
				}
			case XYRelation_ne:
				{					
					return (x<(y-nt)||x>(y+pt));
				}
			default:
				{
					return true;
				}
		}
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	const WString& JDFElement::StatusString(){
		static const WString enums=L"Unknown,Waiting,TestRunInProgress,Ready,FailedTestRun,Setup,InProgress,Cleanup,Spawned,Suspended,Stopped,Completed,Aborted,Pool,Part"; 
		return enums;
	};

	//////////////////////////////////////////////////////////////////////

	WString JDFElement::StatusString(EnumStatus value){
		return StatusString().Token(value,WString::comma);
	};

	//////////////////////////////////////////////////////////////////////

	void JDFElement::SetStatus( EnumStatus value){
		SetEnumAttribute(atr_Status,value,StatusString());
	};

	//////////////////////////////////////////////////////////////////////

	JDFElement::EnumStatus JDFElement::GetStatus() const {
		return (EnumStatus) GetEnumAttribute(atr_Status,StatusString());
	};

	//////////////////////////////////////////////////////////////////////

	const WString& JDFElement::SeparationString(){
		static const WString enums=L"Unknown,Cyan,Magenta,Yellow,Black,Red,Green,Blue,Orange,Spot,Varnish"; 
		return enums;
	};

	//////////////////////////////////////////////////////////////////////

	WString JDFElement::SeparationString(EnumSeparation value){
		return SeparationString().Token(value,WString::comma);
	};

	/////////////////////////////////////////////////////////////////////////

	const WString& JDFElement::FitsValueString(){
		static const WString enums=L"Unknown,Allowed,Present";
		return enums;
	};

	/////////////////////////////////////////////////////////////////////////

	const WString JDFElement::FitsValueString(EnumFitsValue value){
		return FitsValueString().Token(value,WString::comma);
	};

	//////////////////////////////////////////////////////////////////////

	const WString& JDFElement::SettingsPolicyString(){
		static const WString enums=L"Unknown,BestEffort,MustHonor,OperatorIntervention"; 
		return enums;
	};

	//////////////////////////////////////////////////////////////////////

	WString JDFElement::SettingsPolicyString(EnumSettingsPolicy value){
		return SettingsPolicyString().Token(value,WString::comma);
	};

	//////////////////////////////////////////////////////////////////////

	vWString JDFElement::GetUnknownPoolElements(EnumPoolType poolType, bool bIgnorePrivate,int nMax, const vWString& exceptStrings)const{
		vElement v=GetChildElementVector();
		vWString vElem;
		int n=0;
		int siz=v.size();
		for(int i=0;i<siz;i++){
			JDFElement e=v[i];

			if(e.IsComment()) 
				continue;

			if(((poolType==PoolType_ResourcePool)||(poolType==PoolType_ProductionIntent)||(poolType==PoolType_PipeParams))&&e.IsResource()) 
				continue;

			if(((poolType==PoolType_ResourceLinkPool) || (poolType==PoolType_PipeParams)) && e.IsResourceLink()) 
				continue;

			if(poolType==PoolType_AuditPool&&e.IsAudit()) 
				continue;

			if(exceptStrings.hasString(e.GetLocalName()))
				continue;

			// this one is bad
			vElem.push_back(e.GetNodeName());	
			if(++n>nMax) 
				return vElem;
		}
		return vElem;
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Attribute Getter/ Setter
	**************************************************************** */	

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFElement::SetSettingsPolicy( EnumSettingsPolicy value) {
		SetEnumAttribute(atr_SettingsPolicy,value,SettingsPolicyString());
	}
	//////////////////////////////////////////////////////////////////////

	JDFElement::EnumSettingsPolicy JDFElement::GetSettingsPolicy(bool bInherit) const {
		return (EnumSettingsPolicy) GetEnumAttribute(atr_SettingsPolicy,SettingsPolicyString(),WString::emptyStr,SettingsPolicy_BestEffort,bInherit);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFElement::SetBestEffortExceptions (const vWString& value){
		SetAttribute(atr_BestEffortExceptions,value);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFElement::AppendBestEffortExceptions(const WString& value){
		AppendAttribute(atr_BestEffortExceptions,value,WString::emptyStr,WString::blank,true);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFElement::RemoveFromBestEffortExceptions( const WString& value){
		RemoveFromAttribute(atr_BestEffortExceptions,value);
	}
	//////////////////////////////////////////////////////////////////////

	vWString JDFElement::GetBestEffortExceptions() const {
		return GetAttribute(atr_BestEffortExceptions);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFElement::SetMustHonorExceptions( const vWString& value){
		SetAttribute(atr_MustHonorExceptions,value);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFElement::AppendMustHonorExceptions( const WString& value){
		AppendAttribute(atr_MustHonorExceptions,value,WString::emptyStr,WString::blank,true);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFElement::RemoveFromMustHonorExceptions( const WString& value){
		RemoveFromAttribute(atr_MustHonorExceptions,value);
	}
	//////////////////////////////////////////////////////////////////////

	vWString JDFElement::GetMustHonorExceptions() const {
		return GetAttribute(atr_MustHonorExceptions);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFElement::SetOperatorInterventionExceptions( const vWString& value){
		SetAttribute(atr_OperatorInterventionExceptions,value);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFElement::AppendOperatorInterventionExceptions( const WString& value){
		AppendAttribute(atr_OperatorInterventionExceptions,value,WString::emptyStr,WString::blank,true);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFElement::RemoveFromOperatorInterventionExceptions( const WString& value){
		RemoveFromAttribute(atr_OperatorInterventionExceptions,value);
	}
	//////////////////////////////////////////////////////////////////////

	vWString JDFElement::GetOperatorInterventionExceptions() const {
		return GetAttribute(atr_OperatorInterventionExceptions);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFElement::SetID(WString value){
		SetAttribute(atr_ID,value);
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFElement::GetID() const {
		return GetAttribute(atr_ID);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFElement::SetDescriptiveName(WString value){
		SetAttribute(atr_DescriptiveName,value);
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFElement::GetDescriptiveName() const {
		return GetAttribute(atr_DescriptiveName);
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFComment JDFElement::AppendComment(){
		JDFComment c = AppendElement(elm_Comment);
		c.init();
		return c;//AppendElement(elm_Comment);
	};

	///////////////////////////////////////////////////////////////////////
	JDFComment JDFElement::GetCreateComment(int iSkip){
		return GetCreateElement(elm_Comment,WString::emptyStr,iSkip);
	};

	///////////////////////////////////////////////////////////////////////
	JDFComment JDFElement::GetComment(int iSkip)const{
		return GetElement(elm_Comment,WString::emptyStr,iSkip);
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	bool JDFElement::ValidResourcePosition(const JDFResource & r)const{
		JDFNode nodeResource=r.GetParentJDF();
		JDFNode nodeLink=GetParentJDF();
		if(!nodeResource.isNull() && !nodeLink.isNull())
		{
			if(nodeResource==nodeLink)
				return true;
			if(nodeResource.IsAncestor(nodeLink))
				return true;
		}
		else if(!GetDeepParent(elm_JMF).isNull())
		{
			// they are in the same signal, command etc..
			return GetDeepParentChild(elm_JMF)==r.GetDeepParentChild(elm_JMF);
		}
		return false;
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFElement::matchesPath(WString path, bool bFollowRefs)
	{ 
		if(path.empty())
			return true;

		vWString v = path.Tokenize("/");
		JDFElement e=*this;
		JDFElement eLast;
		for(int i=v.size()-1;i>=0;i--)
		{ 
			if(e.isNull())
				return false;
			WString locName = e.GetLocalName();
			if(!locName.equals(v.stringAt(i)))
			{
				if(bFollowRefs && !eLast.isNull() && locName.equals(JDFStrings::elm_ResourcePool))
				{ // now look for a refelement that points at this
					if (eLast.IsResource())
					{
						JDFResource r=(JDFResource)eLast;
						VElement vRefs=r.GetLinks(r.GetRefString(),WString::emptyStr);
						if(!vRefs.empty())
						{
							WString subPath=v.stringAt(0);
							for(int k=1;k<=i+1;k++)
								subPath+="/"+v.stringAt(k);
							subPath+="Ref";
							for(int j=0;j<vRefs.size();j++)
							{
								JDFElement eRef=vRefs.elementAt(j);
								bool b=eRef.matchesPath(subPath, bFollowRefs);
								if(b)
									return true;
							}
						}
					}
				}
				if(eLast.isNull())
				{
					if(eLast.IsResource())
					{
						if(locName.equals(eLast.GetLocalName())){
							e=e.GetParentNode();
							i++; // undo i--
							continue;
						}
					}
				}
				return false;                
			}
			eLast=e;
			e=e.GetParentNode();
		}  
		if(path.startsWith("/"))
			return e.isNull(); // must be root
		return true; // any location
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* JDF 1.2 new additions
	*/
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	vWString JDFElement::GetEnumerationsvString(const vint& value,const WString& allowedValues)const{
		vWString s;
		for (int i=0; i < value.size(); i++)
		{
			s.push_back(allowedValues.Token(value[i]));
		}
		return s;
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
}
