#if !defined _JDFSignature_H_
#define _JDFSignature_H_

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

// Revision history:
//
// 120207 NB added getLayoutLeaves()
// 120207 NB added "Layout" to ValidNodeNames()


///////////////////////////////////////////////////////////////////

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "AutoJDF/JDFAutoLayout.h"
namespace JDF{

	class JDFLayout;
	class JDFSheet;

	/*
	*********************************************************************
	class JDFSignature : public JDFAutoLayout

	*********************************************************************
	*/
	/**
	* Typesafe resource wrapper class JDFSignature 
	*
	* This file is hand edited and will not be regenerated
	*/
	class JDF_WRAPPERCORE_EXPORT JDFSignature : public JDFAutoLayout{
	public:


		// Constructors / Destructors  


		/**
		* null ctor
		*/
		inline JDFSignature():JDFAutoLayout(){};
		/**
		* copy ctor
		*/
		inline JDFSignature(const KElement & other):JDFAutoLayout(){
			*this=other;
		};
		/**
		* copy equivalance operator
		*/
		JDFSignature &operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFSignature(){};

		/**
		* gets a Sheet in both old and new Layouts
		* <li>if old: a <code>Sheet</code> element
		* <li>if new: a <code>SheetName</code> partition leaf
		* @param iSkip the number of Sheets to skip
		* @return JDFSheet
		*/
		JDFSheet GetSheet(int iSkip=0)const;

		/**
		* Append element Sheet
		*/
		JDFSheet AppendSheet();

		/**
		* counts the number of Sheets in both old and new Layouts
		* <li>if old: a <code>Sheet</code> element
		* <li>if new: a <code>SheetName</code> partition leaf
		* @return the number of Sheets
		*/
		int numSheets();

		/** 
		* Get element Sheet, create if it doesn't exist
		* 
		* @param int iSkip number of elements to skip
		* @return JDFSheet The element
		*/
		JDFSheet GetCreateSheet(int iSkip=0);

		/**
		* get the leaves of a layout, either pre 1.2 or post 1.3
		* @return VElement the layout leaves, i.e. partition leaves(1.3+) or explicit surfaces(1.2-)
		*/
		vElement getLayoutLeaves(bool bAll);

	protected:
		/**
		* get the number of layout elements
		* @param layout
		* @param elementName
		* @param partitionKeyName
		* @return int: number of layout elements
		*/
		static int numLayoutElements(const JDFResource& layout, const WString& elementName, const WString& partitionKeyName);

		/**
		* appends a signature in both old and new Layouts
		* if old: a <code>< Signature></code> element
		* if new: a SignatureName partition leaf
		* @return JDFLayout
		*/
		static JDFLayout appendLayoutElement(JDFResource& layout, const WString& elementName, const WString& partitionKeyName);

		/**
		* get a specific layout element
		* @param layout
		* @param elementName
		* @param partitionKeyName
		* @return JDFLayout: the element
		*/
		static JDFLayout getLayoutElement(const JDFResource&  layout, const WString& elementName, const WString& partitionKeyName, int iSkip);

		/**
		* typesafe validator utility - list of valid node names for this class 
		* @return WString& comma separated list of valid node names
		*/
		WString ValidNodeNames()const;

	}; // endJDFSignature
	// ******************************************************
}; // end namespace JDF
#endif //_JDFSignature_H_
