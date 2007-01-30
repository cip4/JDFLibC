/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2004 The International Cooperation for the Integration of 
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

 
#if !defined _JDFArtDelivery_H_
#define _JDFArtDelivery_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFArtDeliveryIntent.h"
#include "AutoJDF/JDFAutoArtDelivery.h"
#include "AutoJDF/JDFAutoEnumerationSpan.h"
namespace JDF{
class JDFCompany;
class JDFContact;
/*
*********************************************************************
class JDFArtDelivery : public JDFAutoArtDelivery

*********************************************************************
*/
/**
* Typesafe resource wrapper class JDFArtDelivery 
*
* This file is hand edited and will not be regenerated
*/
class JDF_WRAPPERCORE_EXPORT JDFArtDelivery : public JDFAutoArtDelivery{
public:


// Constructors / Destructors  


/**
* null ctor
*/
	inline JDFArtDelivery():JDFAutoArtDelivery(){};
/**
* copy ctor
*/
	inline JDFArtDelivery(const KElement & other):JDFAutoArtDelivery(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFArtDelivery &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFArtDelivery(){};

/**
* Enumeration for attribute ArtDeliveryType
*/

	enum EnumArtDeliveryType{ArtDeliveryType_Unknown,ArtDeliveryType_DigitalMedia,ArtDeliveryType_DigitalNetwork,ArtDeliveryType_ExposedPlate,ArtDeliveryType_ImposedFilm,ArtDeliveryType_LooseFilm,ArtDeliveryType_OriginalPhysicalArt,ArtDeliveryType_Proof,ArtDeliveryType_Tool,ArtDeliveryType_None};
/**
* Enumeration strings for ArtDeliveryType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ArtDeliveryTypeString();
/**
* Enumeration string for enum value
* @param EnumArtDeliveryType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ArtDeliveryTypeString(EnumArtDeliveryType value);
/**
* Set attribute ArtDeliveryType
* @param EnumArtDeliveryType value the value to set the attribute to
*/
	virtual void SetEnumArtDeliveryType( EnumArtDeliveryType value);

/**
* Typesafe enumerated attribute ArtDeliveryType
* @return EnumArtDeliveryTypethe enumeration value of the attribute
*/
	virtual EnumArtDeliveryType GetEnumArtDeliveryType() const;

/**
* Get parent node of 'this' - node ArtDeliveryIntent
* @return JDFArtDeliveryIntent: ArtDeliveryIntent node
*/
	JDFArtDeliveryIntent GetParentArtDeliveryIntent() const;

/**
* Get of 'this' the value of element ArtHandling.
* If not specified, get the default value of element ArtHandling,
* that is specified in it's parent element (node ArtDeliveryIntent)
* @return JDFSpanArtHandling: element value
*/	
	JDFSpanArtHandling GetArtHandling()const;

/**
* Get of 'this' the value of element DeliveryCharge.
* If not specified, get the default value of element DeliveryCharge,
* that is specified in it's parent element (node ArtDeliveryIntent)
* @return JDFSpanDeliveryCharge: element value 
*/	
	JDFSpanDeliveryCharge GetDeliveryCharge()const;

/**
* Get of 'this' the value of element Method.
* If not specified, get the default value of element Method,
* that is specified in it's parent element (node ArtDeliveryIntent)
* @return JDFNameSpan: element value
*/
	JDFNameSpan GetMethod()const;

/**
* Get of 'this' the value of attribute PreflightStatus.
* If not specified, get the default value of attribute PreflightStatus,
* that is specified in it's parent element (node ArtDeliveryIntent)
* @return EnumPreflightStatus: attribute value
*/	
	JDFArtDelivery::EnumPreflightStatus GetPreflightStatus()const;

/**
* Get of 'this' the value of element ReturnMethod.
* If not specified, get the default value of element ReturnMethod,
* that is specified in it's parent element (node ArtDeliveryIntent)
* @return JDFNameSpan: element value
*/	
	JDFNameSpan GetReturnMethod()const;

/**
* Get of 'this' the value of element ServiceLevel.
* If not specified, get the default value of element ServiceLevel,
* that is specified in it's parent element (node ArtDeliveryIntent)
* @return JDFStringSpan: element value
*/	
	JDFStringSpan GetServiceLevel()const;

/**
* Get of 'this' the value of element Transfer.
* If not specified, get the default value of element Transfer,
* that is specified in it's parent element (node ArtDeliveryIntent)
* @return JDFSpanTransfer: element value
*/	
	JDFSpanTransfer GetTransfer()const;


/**
* Get of 'this' the iSkip-th child element Contact. If not specified,
* get the child element Contact of it's parent element (node ArtDeliveryIntent)
* @return JDFContact: the found element
*/	
	JDFContact GetContact(int iSkip=0)const;

}; // endJDFArtDelivery

// ******************************************************
}; // end namespace JDF
#endif //_JDFArtDelivery_H_
