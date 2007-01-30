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


///////////////////////////////////////////////////////////////////

 
#if !defined _JDFPageData_H_
#define _JDFPageData_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/AutoJDF/JDFAutoPageData.h"
namespace JDF{
class JDFPageList;
class JDFSeparationSpec;
class JDFImageCompressionParams;
class ElementColorParams;
class JDFScreeningParams;
/*
*********************************************************************
class JDFPageData : public JDFAutoPageData

*********************************************************************
*/
/**
* Typesafe resource wrapper class JDFPageData 
*
* This file is hand edited and will not be regenerated
*/
class JDF_WRAPPERCORE_EXPORT JDFPageData : public JDFAutoPageData{
public:


// Constructors / Destructors  


/**
* null ctor
*/
	inline JDFPageData():JDFAutoPageData(){};
/**
* copy ctor
*/
	inline JDFPageData(const KElement & other):JDFAutoPageData(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFPageData &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFPageData(){};

/**
* Get parent node of 'this' - node PageList
* @return JDFPageList: PageList node
*/
	JDFPageList GetParentPageList() const;

/**
* Get of 'this' the value of attribute AssemblyID.
* If not specified, get the default value of attribute AssemblyID,
* that is specified in it's parent element (node PageList)
* @return WString: attribute value 
*/
	WString GetAssemblyID()const;

	/**
* Get of 'this' the value of attribute CatalogID.
* If not specified, get the default value of attribute CatalogID,
* that is specified in it's parent element (node PageList)
* @return WString: attribute value 
*/
	WString GetCatalogID()const;

/**
* Get of 'this' the value of attribute CatalogDetails.
* If not specified, get the default value of attribute CatalogDetails,
* that is specified in it's parent element (node PageList)
* @return WString: attribute value 
*/
	WString GetCatalogDetails()const;

/**
* Get of 'this' the value of attribute HasBleeds.
* If not specified, get the default value of attribute HasBleeds,
* that is specified in it's parent element (node PageList)
* @return bool: attribute value 
*/	
	bool GetHasBleeds()const;

/**
* Get of 'this' the value of attribute IsBlank.
* If not specified, get the default value of attribute IsBlank,
* that is specified in it's parent element (node PageList)
* @return bool: attribute value 
*/	
	bool GetIsBlank()const;

/**
* Get of 'this' the value of attribute IsPrintable.
* If not specified, get the default value of attribute IsPrintable,
* that is specified in it's parent element (node PageList)
* @return bool: attribute value 
*/
	bool GetIsPrintable()const;

/**
* Get of 'this' the value of attribute IsTrapped.
* If not specified, get the default value of attribute IsTrapped,
* that is specified in it's parent element (node PageList)
* @return bool: attribute value 
*/
	bool GetIsTrapped()const;

/**
* Get of 'this' the value of attribute JobID.
* If not specified, get the default value of attribute JobID,
* that is specified in it's parent element (node PageList)
* @return WString: attribute value 
*/
	WString GetJobID()const;


/**
* Get of 'this' the value of attribute PageLabelPrefix.
* If not specified, get the default value of attribute PageLabelPrefix,
* that is specified in it's parent element (node PageList)
* @return WString: attribute value 
*/
	WString GetPageLabelPrefix()const;

/**
* Get of 'this' the value of attribute PageLabelSuffix.
* If not specified, get the default value of attribute PageLabelSuffix,
* that is specified in it's parent element (node PageList)
* @return WString: attribute value 
*/
	WString GetPageLabelSuffix()const;

/**
* Get of 'this' the value of attribute ProductID.
* If not specified, get the default value of attribute ProductID,
* that is specified in it's parent element (node PageList)
* @return WString: attribute value 
*/
	WString GetProductID()const;

/**
* Get of 'this' the value of attribute SourceBleedBox.
* If not specified, get the default value of attribute SourceBleedBox,
* that is specified in it's parent element (node PageList)
* @return JDFRectangle: attribute value 
*/
	JDFRectangle GetSourceBleedBox()const;

/**
* Get of 'this' the value of attribute SourceClipBox.
* If not specified, get the default value of attribute SourceClipBox,
* that is specified in it's parent element (node PageList)
* @return JDFRectangle: attribute value 
*/
	JDFRectangle GetSourceClipBox()const;

/**
* Get of 'this' the value of attribute SourceTrimBox.
* If not specified, get the default value of attribute SourceTrimBox,
* that is specified in it's parent element (node PageList)
* @return JDFRectangle: attribute value 
*/
	JDFRectangle GetSourceTrimBox()const;

/**
* Get of 'this' the value of attribute Template.
* If not specified, get the default value of attribute Template,
* that is specified in it's parent element (node PageList)
* @return bool: attribute value 
*/
	bool GetTemplate()const;

/**
* Get of 'this' child element ImageCompressionParams. If not specified,
* get the child element ImageCompressionParams of it's parent element (node PageList)
* @return JDFImageCompressionParams: element ImageCompressionParams
*/
	JDFImageCompressionParams GetImageCompressionParams()const;

/**
* Get of 'this' child element ScreeningParams. If not specified,
* get the child element ScreeningParams of it's parent element (node PageList)
* @return JDFScreeningParams: element ScreeningParams
*/
	JDFScreeningParams GetScreeningParams()const;

/**
* Get of 'this' the iSkip-th child element SeparationSpec. If not specified,
* get the child element SeparationSpec of it's parent element (node PageList)
* @param int iSkip: number of elements to skip, default=0
* @return JDFSeparationSpec: element SeparationSpec
*/
	JDFSeparationSpec GetSeparationSpec(int iSkip=0)const;

/**
* Get of 'this' child element ElementColorParams. If not specified,
* get the child element ElementColorParams of it's parent element (node PageList)
* @return JDFElementColorParams: element ElementColorParams
*/
	JDFElementColorParams GetElementColorParams()const;


}; // endJDFPageData

// ******************************************************
}; // end namespace JDF
#endif //_JDFPageData_H_
