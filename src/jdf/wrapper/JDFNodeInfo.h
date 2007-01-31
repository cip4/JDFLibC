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
* 260302 RP added GetHRefs()
* 130902 RP GetLinkedResources now returns vElement
* 270902 added ValidDueLevel for explicit "Unknown"
* 290803 RP Removed GetRRefs - now handled by JDFElement
*
*/

#if !defined _JDFNodeInfo_H_
#define _JDFNodeInfo_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "AutoJDF/JDFAutoNodeInfo.h"
namespace JDF{
	/*
	*********************************************************************
	class JDFNodeInfo : public JDFAutoNodeInfo

	*********************************************************************
	*/
	/**
	* Typesafe resource wrapper calss JDFNodeInfo 
	*
	* This file is hand edited and will not be regenerated
	*/
	class JDF_WRAPPERCORE_EXPORT JDFNodeInfo : public JDFAutoNodeInfo{
	public:


		// Constructors / Destructors  


		/**
		* null ctor
		*/
		inline JDFNodeInfo():JDFAutoNodeInfo(){};
		/**
		* copy ctor
		*/
		inline JDFNodeInfo(const KElement & other):JDFAutoNodeInfo( ){
			*this=other;
		};
		/**
		* copy equivalance operator
		*/
		JDFNodeInfo &operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFNodeInfo(){};
		/**
		* default initialization
		* @return bool true if successful
		*/
		virtual bool init();
		/**
		* printtalk based business objects
		*/
		enum EnumBusinessObject{BusinessObject_Unknown,BusinessObject_RFQ,BusinessObject_Quote,BusinessObject_RFRequote,BusinessObject_Requote,BusinessObject_PO,BusinessObject_Confirmation,BusinessObject_CO_RFQ,BusinessObject_CO_Quote,BusinessObject_CO_PO,BusinessObject_CO_Confirmation,BusinessObject_Invoice,BusinessObject_None};
		/*
		EnumBusinessObject GetBusinessObject(){return (EnumBusinessObject) GetEnumAttribute("BusinessObject",BusinessObjectString());};
		void SetBusinessObject(EnumBusinessObject s){SetEnumAttribute("BusinessObject",s,BusinessObjectString());};
		*/
		/**
		* update the businessobject ..
		* very preliminary!!!
		*/
		bool UpdateBusiness(EnumBusinessObject businessObject, const WString& newID=WString::emptyStr);

		/**
		* strings for business objects
		*/
		static const WString& BusinessObjectString();
		/**
		* individual token string for business objects
		*/
		static WString BusinessObjectString(EnumBusinessObject value);
		/**
		* Get the linked resources matching some conditions
		* @param mAttribute mResAtt: map of Resource attributes to search for
		* @param boolean bFollowRefs true if internal references shall be followed
		* @return vElement: vector with all elements matching the conditions
		*/
		vElement GetLinkedResources(const mAttribute &mResAtt=mAttribute::emptyMap, bool bFollowRefs=false)const;

		/**
		* Typesafe attribute validation of DueLevel<br<
		* also treats explicit value of "Unknown" correctly
		* @param EnumValidationLevel level element validation level 
		* @return bool true if valid
		*/
		virtual bool ValidDueLevel(EnumValidationLevel level=ValidationLevel_Complete) const;
		/**
		* Sets attribute Status
		*
		* @param EnumStatus value: value to set the attribute to
		*/
		void SetNodeStatus( JDFElement::EnumStatus value);

		/**
		* Gets typesafe enumerated value of attribute Status
		*
		* @return EnumStatus: the attribute value
		*/
		JDFElement::EnumStatus GetNodeStatus() const;

		/** 
		* Typesafe attribute validation of Status
		* note that this is JDF/@Status and derived stati. 
		* Resource/@Status is defined in JDFResource
		*
		* @param EnumValidationLevel level: attribute validation level
		* @return bool: true, if valid
		*/
		virtual bool ValidNodeStatus(EnumValidationLevel level=ValidationLevel_Complete) const;

	}; // endJDFNodeInfo

	// ******************************************************
}; // end namespace JDF
#endif //_JDFNodeInfo_H_
