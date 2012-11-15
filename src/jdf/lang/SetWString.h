#ifndef I_JDF_SetWString_H
#define I_JDF_SetWString_H
/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2012 The International Cooperation for the Integration of 
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
/******************************************************************************
*                     Copyright 1998 Agfa-Gevaert N.V.                       *
*                           All rights reserved                              *
*                                                                            *
* The material contained herein may not be reproduced in whole or in part,   *
*        without the prior written consent of Agfa-Gevaert N.V.              *
*                                                                            *
******************************************************************************/



/*******************************************************************************
* 
* Description:
*
* Revision history
******************************************************************************/


/******************************************************************************
*	Includes
******************************************************************************/ 
#include "JDFToolsDefs.h"
#include "JDF/lang/WString.h"
#include "JDF/lang/vWString.h"
#include <set>

namespace JDF
{


	/******************************************************************************
	*	Forward declarations
	******************************************************************************/ 
	/**
	* utility class to provide a simple but fast set for any void pointers
	*/
	typedef  std::set<WString> setstring;
	class JDFTOOLS_EXPORT SetWString : private setstring
	{
	public:

		/*
		* the empty vector
		*/		
	private:
		iterator nextIterator;

	public:
		/**
		* Empty constructor
		*/
		SetWString();
		/**
		* Copy constructor
		* @param vint&m: object of type vint to copy
		*/
		SetWString(const SetWString&m);

		/**
		* Destructor
		*/
		virtual ~SetWString();

		bool contains(const WString&p);

		void add(const WString&p);
			
		size_t size();

		WString next();

		bool hasNext();

		void resetIterator();

		void addTo(vWString &v);

		void addAll(const vWString&v);

	};

} // namespace JDF

#endif /* I_JDF_SetWString_H */

