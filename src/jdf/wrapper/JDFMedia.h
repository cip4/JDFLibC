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
* created 2001-05-18
*
* 050602 RP added ValidMediaType() to correctly handle explicit Unknown enumeration
* 050602 RP de-inlined copy constructor
*
*/

#if !defined _JDFMedia_H_
#define _JDFMedia_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "AutoJDF/JDFAutoMedia.h"
namespace JDF{
/*
*********************************************************************
class JDFMedia : public JDFAutoMedia

  *********************************************************************
	*/
	/**
	*Typesafe resource wrapper calss JDFMedia 
	*
	*This file is hand edited and will not be regenerated
	*/
	class JDF_WRAPPERCORE_EXPORT JDFMedia : public JDFAutoMedia{
	public:
		
		
	/**
	* Constructors / Destructors  
		*/
		//@{
		
		/**
		null ctor
		*/
		inline JDFMedia():JDFAutoMedia(){};
		
		/**
		copy ctor
		*/
		inline JDFMedia(const KElement & other):JDFAutoMedia(){
			*this=other;
		};
		
		/**
		* copy equivalance operator
		*/
		JDFMedia &operator =(const KElement& other);

		/**
		dtor
		*/
		virtual ~JDFMedia(){};
		//@}
		
		/**
		* Typesafe attribute validation of MediaType
		* This version explicitly handles instances of Mediatype="Unknown"
		*
 		* @param EnumValidationLevel level element validation level 
		* @return bool true if valid
		*/
		virtual bool ValidMediaType(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		* Access to dimensions in various metrics
		*/
		//@{
		/**
		* Set attribute Dimension in centimeters
		*@param JDFXYPair value: the value to set the attribute to
		*/
		void SetDimensionCM(JDFXYPair value);
		/**
		* Get string attribute Dimension in centimeters
		* @return JDFXYPair the vaue of the attribute 
		*/
		JDFXYPair GetDimensionCM() const;
		
		/**
		* Set attribute Dimension in inch
		*@param JDFXYPair value: the value to set the attribute to
		*/
		void SetDimensionInch(JDFXYPair value);
		/**
		* Get string attribute Dimension in inch
		* @return JDFXYPair the vaue of the attribute 
		*/
		JDFXYPair GetDimensionInch() const;
		//@}
		
	}; // endJDFMedia
	
	// ******************************************************
}; // end namespace JDF
#endif //_JDFMedia_H_
