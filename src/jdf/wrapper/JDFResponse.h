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
// ////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
// 180700 RP MyString -> WString : all strings now 16 bit
// 160602 RP init() Also call super::init()
//
// JDFResponse.h: interface for the JDFResponse class.
//
// ////////////////////////////////////////////////////////////////////

#if !defined(_JDFResponse_H__)
#define _JDFResponse_H__

#include "AutoJDF/JDFAutoResponse.h"


#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
namespace JDF{
	
	class JDFNotification;
	class JDFQuery;
	/**
	* JMF Response wrapper class
	*/
	class JDF_WRAPPERCORE_EXPORT JDFResponse  : public JDFAutoResponse{
	public:
	/**
	* null ctor
		*/
		inline JDFResponse():JDFAutoResponse(){};
		/**
		* copy ctor
		*/
		inline JDFResponse(const KElement & other):JDFAutoResponse(){
			*this=other;
		};
		/**
		* yactor
		*/
		JDFResponse& operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFResponse(){};

		/**
		* Creates a Notification of Type="Error" that Contains a comment with the appropriate text.
		*@param WString et the error text contents of the appended comment
		*@return JDFNotification the newly created Notification element
		*/
		JDFNotification SetErrorText(const WString& et);
		
	protected:
	/**
	* @tbd still very limited
		*/
		WString ErrorToString(Error s);
		/**
		* @tbd still very limited
		*/
		Error StringToError(WString s);
		/**
		* @tbd still very limited
		*/
		WString GetErrorString();
		/**
		* @tbd still very limited
		*/
		void SetErrorString(WString s);
	};
};

#endif // !defined(_JDFResponse_H__)
