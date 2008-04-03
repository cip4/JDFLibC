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

#include "JDFPart.h"
#include "JDFResource.h"
#include "jdf/wrappercore/StringUtil.h"

namespace JDF{
	
	///////////////////////////////////////////////////////////////////////////
	
	JDFPart& JDFPart::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFPart: "+other.GetNodeName()); 
		return *this;
	};
	
	///////////////////////////////////////////////////////////////////////////
	
	mAttribute JDFPart::GetPartMap()const{
		return GetAttributeMap();
	};
	
	///////////////////////////////////////////////////////////////////////////

	bool JDFPart::matchesPart(const WString& key, const WString& resourceValue, const WString& linkValue)
	{
		JDFResource::EnumPartIDKey eKey=JDFResource::GetPartIDKeyEnum(key);
		if(eKey==JDFResource::PartIDKey_Unknown)
			return resourceValue.equals(linkValue);
        bool b;
		// 080403 RP removed JDFResource::PartIDKey_PartVersion==eKey 
        if(JDFResource::PartIDKey_DocTags==eKey
                || JDFResource::PartIDKey_ItemNames==eKey
                || JDFResource::PartIDKey_PageTags==eKey
                || JDFResource::PartIDKey_RunTags==eKey
                || JDFResource::PartIDKey_SetTags==eKey)
        
        {
			b=StringUtil::matchesAttribute(linkValue,resourceValue,KElement::AttributeType_NMTOKENS);
        }
        
        else if(JDFResource::PartIDKey_DocCopies==eKey
                || JDFResource::PartIDKey_DocIndex==eKey
                || JDFResource::PartIDKey_DocRunIndex==eKey
                || JDFResource::PartIDKey_DocSheetIndex==eKey
                || JDFResource::PartIDKey_LayerIDs==eKey
                || JDFResource::PartIDKey_PageNumber==eKey
                || JDFResource::PartIDKey_RunIndex==eKey
                || JDFResource::PartIDKey_SectionIndex==eKey
                || JDFResource::PartIDKey_SetIndex==eKey
                || JDFResource::PartIDKey_SetRunIndex==eKey
                || JDFResource::PartIDKey_SetSheetIndex==eKey
                || JDFResource::PartIDKey_SheetIndex==eKey
        )
        {
			b=StringUtil::matchesAttribute(linkValue,resourceValue,KElement::AttributeType_IntegerRangeList);
        }
        else
        {
            b=resourceValue.equals(linkValue);
        }
        return b;
	}

	///////////////////////////////////////////////////////////////////////////

	bool JDFPart::overlapPartMap(const mAttribute& resourceMap, const mAttribute& linkMap)
	{
		if(resourceMap.empty()||linkMap.empty())
			return true; // null always overlaps with anything

		vWString subMapEnum = linkMap.GetKeys();
		// iterate subMapEnum
		for (int i = 0; i < subMapEnum.size(); i++)
		{
			WString key    = subMapEnum[i];
			WString resVal = resourceMap.GetValue(key);

			if (!resVal.empty())
			{
				WString linkVal = linkMap.GetValue(key);
				if (!matchesPart(key,resVal,linkVal))
				{
					return false;
				}
			}
		}
		return true;
	}

	///////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
}; // namespace JDF
