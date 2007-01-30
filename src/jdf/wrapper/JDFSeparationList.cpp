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
* Warning! preliminary version. Interface subject to change without prior notice!
* Revision history:
* created 2002-05-31
* based on JDF Schema version JDFc_1_4_R.xsd
*
*/
#include "JDFSeparationList.h"
#include "JDFSeparationSpec.h"
namespace JDF{
	/*
	*********************************************************************
	class JDFSeparationList : public JDFElement

	*********************************************************************
	*/
	JDFSeparationList & JDFSeparationList::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFSeparationList: "+other.GetNodeName()); 
		return *this;
	};

	/**
	* typesafe validator utility - list of valid node names for this class 
	* @return WString& comma separated list of valid node names
	*/

	/////////////////////////////////////////////////////
	bool JDFSeparationList::IsAbstract()const{
		return false;
	}

	/////////////////////////////////////////////////////


	WString JDFSeparationList::ValidNodeNames()const{
		return L"*:,ColorantOrder,ColorantParams,DeviceColorantOrder,ColorsUsed";
	};


	/* ******************************************************
	// Attribute Getter / Setter
	****************************************************** */



	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */


	JDFSeparationSpec JDFSeparationList::GetCreateSeparationSpec( int iSkip){
		JDFSeparationSpec e=GetCreateElement(elm_SeparationSpec,WString::emptyStr,iSkip);;
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFSeparationSpec JDFSeparationList::AppendSeparationSpec(){
		JDFSeparationSpec e=AppendElement(elm_SeparationSpec,WString::emptyStr);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	/*
	const get first element 
	*/
	JDFSeparationSpec JDFSeparationList::GetSeparationSpec(int iSkip)const{
		return GetElement(elm_SeparationSpec,WString::emptyStr,iSkip);
	};

	/**
	typesafe validator
	*/
	vWString JDFSeparationList::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			return vElem;
		nElem=NumChildElements(elm_SeparationSpec);
		for(i=0;i<nElem;i++){
			JDFSeparationSpec child=GetElement(elm_SeparationSpec,WString::emptyStr,i);
			if (child.IsRefElement()) continue;
			if (!child.IsValid(level)) {
				vElem.AppendUnique(elm_SeparationSpec);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		if(level>=ValidationLevel_Complete)vElem.AppendUnique(GetMissingElements(nMax));
		vElem.AppendUnique(GetUnknownElements(bIgnorePrivate,nMax));
		return vElem;
	};


	/**
	definition of optional elements in the JDF namespace
	*/
	WString JDFSeparationList::OptionalElements()const{
		return JDFElement::OptionalElements()+L",SeparationSpec";
	};

	//////////////////////////////////////////////////////////////////////////////////

	vWString JDFSeparationList::GetSeparations() const{
		vWString vName;
		vElement v=GetChildElementVector(elm_SeparationSpec);
		int nSep=v.size();
		for(int i=0;i<nSep;i++)
		{
			JDFSeparationSpec sep=v[i];
			WString name=sep.GetName();
			vName.AppendUnique(name);
		}
		return vName;
	}
	//////////////////////////////////////////////////////////////////////////////////
	/**
	* set all separation names in the SeparationSpec elements
	* remove any prior elements
	* 
	* @param the vector of separation names to set
	*/
	void JDFSeparationList::setSeparations(const vWString& vSeps) 
	{
		RemoveChildren(elm_SeparationSpec);
		for(int i=0;i<vSeps.size();i++)
		{
			appendSeparation(vSeps.stringAt(i));
		}
	}

	//////////////////////////////////////////////////////////////////////////////////
	/**
	* append a separationspec with a given name to this
	* @param sep the separation name
	*/
	void JDFSeparationList::appendSeparation(const WString& sep)
	{
		AppendSeparationSpec().SetName(sep);
	}   

	//////////////////////////////////////////////////////////////////////////////////
	/**
	* remove a separationspec with a given name from this
	* 
	* @param sep the separation name
	* @return int the index of the removed separation; -1 if none found
	*/
	int JDFSeparationList::removeSeparation(const WString& sep)
	{
		vWString vs=GetSeparations();
		int index=vs.index(sep);
		if (index>=0)
			GetSeparationSpec(index).DeleteNode();
		return index;
	}   
	//////////////////////////////////////////////////////////////////////////////////
	/**
	* Get the n'th separation name in the SeparationSpec elements
	* @param iSkip the index of the SeparationSpec
	* @return separation names, null if iSkip > nSeparations
	*/
	vWString JDFSeparationList::getSeparation(int iSkip) const
	{
		return GetSeparationSpec(iSkip).GetName();        
	}  
	//////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////

}; // end namespace JDF
