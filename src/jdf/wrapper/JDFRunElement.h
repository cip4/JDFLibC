/* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2007 The International Cooperation for the Integration of 
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
// created  31.May.2000
// 180700 RP MyString -> WString : all strings now 16 bit
//
// JDFRunElement.h: interface for the JDFRunElement class.
// one JDFRunElement corresponds to one run entry in a runlist
//
// ////////////////////////////////////////////////////////////////////

#if !defined(_JDFRunElement_H___)
#define _JDFRunElement_H___

#pragma warning( disable : 4786 ) // long debug names from stl
#pragma warning( disable : 4251 ) // stl dll linking

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include <vector>

#include "JDFFileSpec.h"
namespace JDF{
	class JDFRunList;
	/**
	* JDFRunElement corresponds to one virtual entry, i.e. one element in the runlist that is independent of the representation as run elements
	* For one XML sub element in the run list that may specify multiple pages see JDFRunElement
	* Note that this class does NOT inherit from any XML DOM element classes
	*
	* @deprecated 
	*/ 
	class JDF_WRAPPERCORE_EXPORT JDFRunElement{
		
	public:
	/**
	* null ctor
		*/
		JDFRunElement();
		/**
		* copy ctor
		*/
		JDFRunElement(const JDFRunElement&other);
		/**
		* ctor
		*/
		virtual ~JDFRunElement(){};
		/**
		* Set this element to a certain  RunList leaf
		*
		*/
		void SetRunSeparation(JDFRunList& fs);
		/**
		* Get the RunList element for a given separation
		* @param WString& separation the separation to get
		* @return JDFRunList the Runlist Partition for the specified separation
		*/
		JDFRunList GetRunSeparation(const WString& separation);
		
		/**
		* equality operator
		*/
		bool operator<(const JDFRunElement& r) const;

		/**
		* equality operator
		*/
		bool operator==(const JDFRunElement& r) const;
		
	protected:
		
	/**
	* generic initialization
		*/
		void init();
		/**
		* internal list of RunList elements for each separation
		*/
		vElement vRunSep;
	};
	
	
	
	/**
	* simple vector of JDFRunElement
	*/
	typedef std::vector<JDFRunElement> vRunElement;


	/**
	* JDFRunElementList defines a vector of RunElements
	* RunList manipulation is accomplished by reordering a JDFRunElementList and serializing to a RunList
	*/ 
	class JDF_WRAPPERCORE_EXPORT JDFRunElementList:public vRunElement{
		
	public:

		/**
		* null ctor
		*/
		JDFRunElementList();
		/**
		* copy ctor
		*/
		JDFRunElementList(const vRunElement &other);
		/**
		* dtor
		*/
		virtual ~JDFRunElementList();
		
		
	private:

		void * pBase;
	};
};


#endif // !defined(_JDFRunElement_H___)
