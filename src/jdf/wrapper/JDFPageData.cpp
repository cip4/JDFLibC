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

 
#include "jdf/wrapper/JDFPageData.h"
#include "jdf/wrapper/JDFPageList.h"
#include "jdf/wrapper/JDFSeparationSpec.h"
#include "jdf/wrapper/JDFImageCompressionParams.h"
#include "jdf/wrapper/JDFElementColorParams.h"
#include "jdf/wrapper/JDFScreeningParams.h"

namespace JDF{
/**
* copy equivalance operator
*/
	JDFPageData& JDFPageData::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFPageData: "+other.GetNodeName());
	return *this;
};

//////////////////////////////////////////////////////////////////////
	JDFPageList JDFPageData::GetParentPageList() const {
		return GetParentNode();
	};
//////////////////////////////////////////////////////////////////////
	WString JDFPageData::GetAssemblyID()const{
		if(HasAttribute(atr_AssemblyID))
			return JDFAutoPageData::GetAssemblyID();
		return GetParentPageList().GetAssemblyID();
	};
//////////////////////////////////////////////////////////////////////
	WString JDFPageData::GetCatalogID()const{
		if(HasAttribute(atr_CatalogID))
			return JDFAutoPageData::GetCatalogID();
		return GetParentPageList().GetCatalogID();
	};
//////////////////////////////////////////////////////////////////////
	WString JDFPageData::GetCatalogDetails()const{
		if(HasAttribute(atr_CatalogDetails))
			return JDFAutoPageData::GetCatalogDetails();
		return GetParentPageList().GetCatalogDetails();
	};
//////////////////////////////////////////////////////////////////////
	bool JDFPageData::GetHasBleeds()const{
		if(HasAttribute(atr_HasBleeds))
			return JDFAutoPageData::GetHasBleeds();
		return GetParentPageList().GetHasBleeds();
	};
//////////////////////////////////////////////////////////////////////
	bool JDFPageData::GetIsBlank()const{
		if(HasAttribute(atr_IsBlank))
			return JDFAutoPageData::GetIsBlank();
		return GetParentPageList().GetIsBlank();
	};
//////////////////////////////////////////////////////////////////////
	bool JDFPageData::GetIsPrintable()const{
		if(HasAttribute(atr_IsPrintable))
			return JDFAutoPageData::GetIsPrintable();
		return GetParentPageList().GetIsPrintable();
	};
//////////////////////////////////////////////////////////////////////
	bool JDFPageData::GetIsTrapped()const{
		if(HasAttribute(atr_IsTrapped))
			return JDFAutoPageData::GetIsTrapped();
		return GetParentPageList().GetIsTrapped();
	};
//////////////////////////////////////////////////////////////////////
	WString JDFPageData::GetJobID()const{
		if(HasAttribute(atr_JobID))
			return JDFAutoPageData::GetJobID();
		return GetParentPageList().GetJobID();
	}
//////////////////////////////////////////////////////////////////////
	WString JDFPageData::GetPageLabelPrefix()const{
		if(HasAttribute(atr_PageLabelPrefix))
			return JDFAutoPageData::GetPageLabelPrefix();
		return GetParentPageList().GetPageLabelPrefix();
	};
//////////////////////////////////////////////////////////////////////
	WString JDFPageData::GetPageLabelSuffix()const{
		if(HasAttribute(atr_PageLabelSuffix))
			return JDFAutoPageData::GetPageLabelSuffix();
		return GetParentPageList().GetPageLabelSuffix();
	};
//////////////////////////////////////////////////////////////////////
	WString JDFPageData::GetProductID()const{
		if(HasAttribute(atr_ProductID))
			return JDFAutoPageData::GetProductID();
		return GetParentPageList().GetProductID();
	};
//////////////////////////////////////////////////////////////////////
	JDFRectangle JDFPageData::GetSourceBleedBox()const{
		if(HasAttribute(atr_SourceBleedBox))
			return JDFAutoPageData::GetSourceBleedBox();
		return GetParentPageList().GetSourceBleedBox();
	};
//////////////////////////////////////////////////////////////////////
	JDFRectangle JDFPageData::GetSourceClipBox()const{
		if(HasAttribute(atr_SourceClipBox))
			return JDFAutoPageData::GetSourceClipBox();
		return GetParentPageList().GetSourceClipBox();
	};
//////////////////////////////////////////////////////////////////////
	JDFRectangle JDFPageData::GetSourceTrimBox()const{
		if(HasAttribute(atr_SourceTrimBox))
			return JDFAutoPageData::GetSourceTrimBox();
		return GetParentPageList().GetSourceTrimBox();
	};
//////////////////////////////////////////////////////////////////////
	bool JDFPageData::GetTemplate()const{
		if(HasAttribute(atr_Template))
			return JDFAutoPageData::GetTemplate();
		return GetParentPageList().GetTemplate();
	};
/////////////////////////////////////////////////////////////////////
	JDFImageCompressionParams JDFPageData::GetImageCompressionParams()const{
		if(HasChildElement(elm_ImageCompressionParams,WString::emptyStr)) 
			return JDFAutoPageData::GetImageCompressionParams();
		return GetParentPageList().GetImageCompressionParams();
	};
/////////////////////////////////////////////////////////////////////
	JDFScreeningParams JDFPageData::GetScreeningParams()const{
		if(HasChildElement(elm_ScreeningParams,WString::emptyStr)) 
			return JDFAutoPageData::GetScreeningParams();
		return GetParentPageList().GetScreeningParams();
	};
/////////////////////////////////////////////////////////////////////
	JDFSeparationSpec JDFPageData::GetSeparationSpec(int iSkip)const{
		if(HasChildElement(elm_SeparationSpec,WString::emptyStr)) 
			return GetElement(elm_SeparationSpec,WString::emptyStr,iSkip);
		return GetParentPageList().GetElement(elm_SeparationSpec);
	};
/////////////////////////////////////////////////////////////////////
	JDFElementColorParams JDFPageData::GetElementColorParams()const{
		if(HasChildElement(elm_ElementColorParams,WString::emptyStr)) 
			return JDFAutoPageData::GetElementColorParams();
		return GetParentPageList().GetElementColorParams();
	};
/////////////////////////////////////////////////////////////////////

}; // namespace JDF
