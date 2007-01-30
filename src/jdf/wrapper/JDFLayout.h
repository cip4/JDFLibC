#if !defined _JDFLayout_H_
#define _JDFLayout_H_

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
//
// Revision history
//
// 051206 NB fixed isNewLayout() -> now GetVersion() goes into parents as well
// 141206 NB added moveElementsTo(), ValidNodeNames()
// 141206 NB fixed FromNewLayout()

///////////////////////////////////////////////////////////////////

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFSurface.h"

namespace JDF{
	/*
	*********************************************************************
	class JDFLayout : public JDFAutoLayout

	*********************************************************************
	*/
	/**
	* Typesafe resource wrapper class JDFLayout 
	*
	* This file is hand edited and will not be regenerated
	*/
	class JDF_WRAPPERCORE_EXPORT JDFLayout : public JDFSurface{
	public:


		// Constructors / Destructors  


		/**
		* null ctor
		*/
		inline JDFLayout():JDFSurface(){};
		/**
		* copy ctor
		*/
		inline JDFLayout(const KElement & other):JDFSurface(){
			*this=other;
		};
		/**
		* copy equivalance operator
		*/
		JDFLayout &operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFLayout(){};

		/**
		* Version fixing routine
		*
		* uses heuristics to modify this element and its children to be compatible with a given version
		* in general, it will be able to move from low to high versions but potentially fail 
		* when attempting to move from higher to lower versions
		*
		* @param EnumVersion version: version that the resulting element should correspond to
		* @param bool true if successful
		*/
		virtual bool FixVersion(EnumVersion version);

		/**
		* generate a JDF 1.3 compatible Layout from this (1.2)
		* @return bool true if successful
		*/
		bool ToNewLayout();

		/**
		* generate a JDF 1.2 compatible Layout from this (1.3)
		* @return bool true if successful
		*
		*/
		bool FromNewLayout();

		/**
		* heuristics to check which version an element of a Layout is in: 1.3 or 1.2
		* 
		* Note that this routine is static since it must be used on all sheets, surfaces etc.
		* 
		* @param sheet the Sheet, Surface, Signature or Layout to check
		* @return true if this is a new, i.e. partitioned Layout
		* 
		*/
		static bool isNewLayout(const JDFResource& sheet);

		/**
		* gets the vector of all placed objects that reside directly in this partition
		* retains the order of marks and content
		* 
		* @return the vector of placedobjects, null if none were found
		*/
		vElement getPlacedObjectVector();

		/**
		* counts the number of signatures in both old and new Layouts
		* if old: the number of <Signature> elements
		* if new: the number of SignatureName partition leaves
		* @return the number of signatures
		*/
		int numSignatures();

		
		/**
		* Append element Signature
		*/
		JDFSignature AppendSignature();

		/** 
		* Get element signature, create if it doesn't exist
		* @param int iSkip number of elements to skip
		* @return JDFSignature: the element
		*/
		JDFSignature GetCreateSignature(int iSkip=0);

		/**
		* const get element Signature
		* @param int iSkip number of elements to skip
		* @return JDFSignature: the element
		*/
		JDFSignature GetSignature(int iSkip=0)const;

		/**
		* definition of required attributes in the JDF namespace
		*
		* @return WString: list of required attributes
		*/
		WString RequiredAttributes()const;

	protected:
		/**
		* typesafe validator utility - list of valid node names for this class 
		* @return WString& comma separated list of valid node names
		*/
		WString ValidNodeNames()const;

	private:
		void moveElementsTo(JDFLayout& target);


	}; // endJDFLayout	
	// ******************************************************
}; // end namespace JDF
#endif //_JDFLayout_H_
