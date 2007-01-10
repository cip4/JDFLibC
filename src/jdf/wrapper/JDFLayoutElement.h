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
* created 2001-07-02
* 020702 RP Added ValidElementType
*
*/

#if !defined _JDFLayoutElement_H_
#define _JDFLayoutElement_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "AutoJDF/JDFAutoLayoutElement.h"
namespace JDF{
	class JDFImageCompressionParams;
	class JDFScreeningParams;
	class JDFSeparationSpec;
	class JDFPageList;
	class JDFPageData;
	class JDFResourcePool;

/*
*********************************************************************
class JDFLayoutElement : public JDFAutoLayoutElement

  *********************************************************************
	*/
	/**
	* Typesafe resource wrapper calss JDFLayoutElement 
	*
	* This file is hand edited and will not be regenerated
	*/
	class JDF_WRAPPERCORE_EXPORT JDFLayoutElement : public JDFAutoLayoutElement{
	public:
		
		
		// Constructors / Destructors  
		
		
		/**
		* null ctor
		*/
		inline JDFLayoutElement():JDFAutoLayoutElement(){};
		
		/**
		* copy ctor
		*/
		inline JDFLayoutElement(const KElement & other):JDFAutoLayoutElement(){
			*this=other;
		};
		
		/**
		* copy equivalance operator
		*/
		JDFLayoutElement &operator =(const KElement& other);
		
		/**
		* dtor
		*/
		virtual ~JDFLayoutElement(){};
		
		/**
		* Set the URL of the child FileSpec 
		* @param WString& fileName the filename in the filespec
		*/
		void SetURL(const WString& fileName);
		
		/**
		* Typesafe validation of attribute ElementType
		* This version explicitly handles instances of ElementType="Unknown"
		*
		* @param EnumValidationLevel level element validation level 
		* @return bool true if valid
		*/
		virtual bool ValidElementType(EnumValidationLevel level=ValidationLevel_Complete) const;

		
		/**
		* Gets the first resource PageList element of the resource pool 
		* and returns its child PageData
		* @return JDFPageData: found PageData element
		*/
		JDFPageData GetPageListPageData() const;


		/**
		* Get of 'this' the value of attribute HasBleeds.
		* If it is not specified, get the default value of attribute HasBleeds,
		* that is specified in PageList/PageData element
		* @return bool: the attribute value 
		*/
		bool GetHasBleeds() const;
		
		/**
		* Get of 'this' the value of attribute IsBlank.
		* If it is not specified, get the default value of attribute IsBlank,
		* that is specified in PageList/PageData element
		* @return bool: the attribute value 
		*/
		bool GetIsBlank() const;
				
		/**
		* Get of 'this' the value of attribute IsPrintable.
		* If it is not specified, get the default value of attribute IsPrintable,
		* that is specified in PageList/PageData element
		* @return bool: the attribute value 
		*/
		bool GetIsPrintable() const;

		
		/**
		* Get of 'this' the value of attribute IsTrapped.
		* If it is not specified, get the default value of attribute IsTrapped,
		* that is specified in PageList/PageData element
		* @return bool: the attribute value 
		*/
		bool GetIsTrapped() const;

		
		/**
		* Get of 'this' the value of attribute SourceBleedBox.
		* If it is not specified, get the default value of attribute SourceBleedBox,
		* that is specified in PageList/PageData element
		* @return JDFRectangle: the attribute value 
		*/
		JDFRectangle GetSourceBleedBox() const;

		
		/**
		* Get of 'this' the value of attribute SourceClipBox.
		* If it is not specified, get the default value of attribute SourceClipBox,
		* that is specified in PageList/PageData element
		* @return JDFRectangle: the attribute value 
		*/
		JDFRectangle GetSourceClipBox() const;

		
		/**
		* Get of 'this' the value of attribute SourceTrimBox.
		* If it is not specified, get the default value of attribute SourceTrimBox,
		* that is specified in PageList/PageData element
		* @return JDFRectangle: the attribute value 
		*/
		JDFRectangle GetSourceTrimBox() const;

		
		/**
		* Get of 'this' the value of attribute Template.
		* If it is not specified, get the default value of attribute Template,
		* that is specified in PageList/PageData element
		* @return bool: the attribute value 
		*/
		bool GetTemplate() const;

		
		/**
		* Get of 'this' child element ImageCompressionParams. If it is not specified,
		* get the child element ImageCompressionParams of PageList/PageData element
		* @return JDFImageCompressionParams: element ImageCompressionParams
		*/
		JDFImageCompressionParams GetImageCompressionParams()const;
		

		/**
		* Get of 'this' child element ScreeningParams. If it is not specified,
		* get the child element ScreeningParams of PageList/PageData element
		* @return JDFScreeningParams: element ScreeningParams
		*/
		JDFScreeningParams GetScreeningParams()const;
		

		/**
		* Get of 'this' the iSkip-th child element SeparationSpec. If it is not specified,
		* get the child element SeparationSpec of PageList/PageData element
		* @param int iSkip: number of SeparationSpec elements to skip
		* @return JDFSeparationSpec: element SeparationSpec
		*/
		JDFSeparationSpec GetSeparationSpec(int iSkip) const;

		
	}; // endJDFLayoutElement
	
	// ******************************************************
}; // end namespace JDF
#endif //_JDFLayoutElement_H_
