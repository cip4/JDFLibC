/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2014 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoQueueFilter.h"
#include "jdf/wrapper/JDFQueueEntryDef.h"
#include "jdf/wrapper/JDFDevice.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoQueueFilter : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoQueueFilter& JDFAutoQueueFilter::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoQueueFilter: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoQueueFilter::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoQueueFilter::ValidNodeNames()const{
	return L"*:,QueueFilter";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoQueueFilter::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",GangNames,JobID,JobPartID,MaxEntries,OlderThan,PreviewUsages,NewerThan,QueueEntryDetails,StatusList,UpdateGranularity");
};

/**
 typesafe validator
*/
	vWString JDFAutoQueueFilter::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidGangNames(level)) {
			vAtts.push_back(atr_GangNames);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJobID(level)) {
			vAtts.push_back(atr_JobID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJobPartID(level)) {
			vAtts.push_back(atr_JobPartID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxEntries(level)) {
			vAtts.push_back(atr_MaxEntries);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOlderThan(level)) {
			vAtts.push_back(atr_OlderThan);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPreviewUsages(level)) {
			vAtts.push_back(atr_PreviewUsages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNewerThan(level)) {
			vAtts.push_back(atr_NewerThan);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidQueueEntryDetails(level)) {
			vAtts.push_back(atr_QueueEntryDetails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStatusList(level)) {
			vAtts.push_back(atr_StatusList);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUpdateGranularity(level)) {
			vAtts.push_back(atr_UpdateGranularity);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute GangNames
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoQueueFilter::SetGangNames(const vWString& value){
	SetAttribute(atr_GangNames,value);
};
/**
* Get string attribute GangNames
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoQueueFilter::GetGangNames() const {
	return GetAttribute(atr_GangNames,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueFilter::ValidGangNames(EnumValidationLevel level) const {
		return ValidAttribute(atr_GangNames,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueFilter::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueFilter::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueFilter::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_string,false);
	};
/**
* Set attribute JobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueFilter::SetJobPartID(const WString& value){
	SetAttribute(atr_JobPartID,value);
};
/**
* Get string attribute JobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueFilter::GetJobPartID() const {
	return GetAttribute(atr_JobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueFilter::ValidJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobPartID,AttributeType_string,false);
	};
/**
* Set attribute MaxEntries
*@param int value: the value to set the attribute to
*/
	 void JDFAutoQueueFilter::SetMaxEntries(int value){
	SetAttribute(atr_MaxEntries,WString::valueOf(value));
};
/**
* Get integer attribute MaxEntries
* @return int the vaue of the attribute 
*/
	 int JDFAutoQueueFilter::GetMaxEntries() const {
	return GetIntAttribute(atr_MaxEntries,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueFilter::ValidMaxEntries(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxEntries,AttributeType_integer,false);
	};
/**
* Set attribute OlderThan
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoQueueFilter::SetOlderThan(JDFDate value){
	SetAttribute(atr_OlderThan,value.DateTimeISO());
};
/**
* Get string attribute OlderThan
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoQueueFilter::GetOlderThan() const {
	return GetAttribute(atr_OlderThan,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueFilter::ValidOlderThan(EnumValidationLevel level) const {
		return ValidAttribute(atr_OlderThan,AttributeType_dateTime,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoQueueFilter::PreviewUsagesString(){
		static const WString enums=WString(L"Unknown,3D,Animation,Separation,SeparationRaw,SeparatedThumbNail,ThumbNail,Viewable");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoQueueFilter::PreviewUsagesString(EnumPreviewUsages value){
		return PreviewUsagesString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoQueueFilter::AddPreviewUsages( EnumPreviewUsages value){
	return AddEnumerationsAttribute(atr_PreviewUsages,value,PreviewUsagesString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoQueueFilter::RemovePreviewUsages( EnumPreviewUsages value){
	return RemoveEnumerationsAttribute(atr_PreviewUsages,value,PreviewUsagesString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoQueueFilter::GetPreviewUsages() const {
	return GetEnumerationsAttribute(atr_PreviewUsages,PreviewUsagesString(),WString::emptyStr,(unsigned int)PreviewUsages_Separation);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoQueueFilter::SetPreviewUsages( EnumPreviewUsages value){
	SetEnumAttribute(atr_PreviewUsages,value,PreviewUsagesString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoQueueFilter::SetPreviewUsages( const vint& value){
	SetEnumerationsAttribute(atr_PreviewUsages,value,PreviewUsagesString());
};
/**
* Typesafe attribute validation of PreviewUsages
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueFilter::ValidPreviewUsages(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_PreviewUsages,PreviewUsagesString(),false);
	};
/**
* Set attribute NewerThan
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoQueueFilter::SetNewerThan(JDFDate value){
	SetAttribute(atr_NewerThan,value.DateTimeISO());
};
/**
* Get string attribute NewerThan
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoQueueFilter::GetNewerThan() const {
	return GetAttribute(atr_NewerThan,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueFilter::ValidNewerThan(EnumValidationLevel level) const {
		return ValidAttribute(atr_NewerThan,AttributeType_dateTime,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoQueueFilter::QueueEntryDetailsString(){
		static const WString enums=WString(L"Unknown,None,Brief,JobPhase,JDF");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoQueueFilter::QueueEntryDetailsString(EnumQueueEntryDetails value){
		return QueueEntryDetailsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoQueueFilter::SetQueueEntryDetails( EnumQueueEntryDetails value){
	SetEnumAttribute(atr_QueueEntryDetails,value,QueueEntryDetailsString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoQueueFilter::EnumQueueEntryDetails JDFAutoQueueFilter:: GetQueueEntryDetails() const {
	return (EnumQueueEntryDetails) GetEnumAttribute(atr_QueueEntryDetails,QueueEntryDetailsString(),WString::emptyStr,QueueEntryDetails_Brief);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueFilter::ValidQueueEntryDetails(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_QueueEntryDetails,QueueEntryDetailsString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoQueueFilter::StatusListString(){
		static const WString enums=WString(L"Unknown,Running,Waiting,Held,Removed,Suspended,PendingReturn,Completed,Aborted");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoQueueFilter::StatusListString(EnumStatusList value){
		return StatusListString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoQueueFilter::AddStatusList( EnumStatusList value){
	return AddEnumerationsAttribute(atr_StatusList,value,StatusListString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoQueueFilter::RemoveStatusList( EnumStatusList value){
	return RemoveEnumerationsAttribute(atr_StatusList,value,StatusListString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoQueueFilter::GetStatusList() const {
	return GetEnumerationsAttribute(atr_StatusList,StatusListString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoQueueFilter::SetStatusList( EnumStatusList value){
	SetEnumAttribute(atr_StatusList,value,StatusListString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoQueueFilter::SetStatusList( const vint& value){
	SetEnumerationsAttribute(atr_StatusList,value,StatusListString());
};
/**
* Typesafe attribute validation of StatusList
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueFilter::ValidStatusList(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_StatusList,StatusListString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoQueueFilter::UpdateGranularityString(){
		static const WString enums=WString(L"Unknown,All,ChangesOnly");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoQueueFilter::UpdateGranularityString(EnumUpdateGranularity value){
		return UpdateGranularityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoQueueFilter::SetUpdateGranularity( EnumUpdateGranularity value){
	SetEnumAttribute(atr_UpdateGranularity,value,UpdateGranularityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoQueueFilter::EnumUpdateGranularity JDFAutoQueueFilter:: GetUpdateGranularity() const {
	return (EnumUpdateGranularity) GetEnumAttribute(atr_UpdateGranularity,UpdateGranularityString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueFilter::ValidUpdateGranularity(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_UpdateGranularity,UpdateGranularityString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFQueueEntryDef JDFAutoQueueFilter::GetQueueEntryDef(int iSkip)const{
	JDFQueueEntryDef e=GetElement(elm_QueueEntryDef,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQueueEntryDef JDFAutoQueueFilter::GetCreateQueueEntryDef(int iSkip){
	JDFQueueEntryDef e=GetCreateElement(elm_QueueEntryDef,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQueueEntryDef JDFAutoQueueFilter::AppendQueueEntryDef(){
	JDFQueueEntryDef e=AppendElement(elm_QueueEntryDef);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoQueueFilter::GetDevice(int iSkip)const{
	JDFDevice e=GetElement(elm_Device,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoQueueFilter::GetCreateDevice(int iSkip){
	JDFDevice e=GetCreateElement(elm_Device,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoQueueFilter::AppendDevice(){
	JDFDevice e=AppendElement(elm_Device);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoQueueFilter::RefDevice(JDFDevice& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoQueueFilter::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoQueueFilter::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoQueueFilter::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoQueueFilter::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoQueueFilter::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoQueueFilter::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoQueueFilter::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoQueueFilter::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

/**
 typesafe validator
*/
	vWString JDFAutoQueueFilter::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_QueueEntryDef);

		for(i=0;i<nElem;i++){
			if (!GetQueueEntryDef(i).IsValid(level)) {
				vElem.AppendUnique(elm_QueueEntryDef);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Device);

		for(i=0;i<nElem;i++){
			if (!GetDevice(i).IsValid(level)) {
				vElem.AppendUnique(elm_Device);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoQueueFilter::OptionalElements()const{
		return JDFElement::OptionalElements()+L",QueueEntryDef,Device,Part";
	};
}; // end namespace JDF
