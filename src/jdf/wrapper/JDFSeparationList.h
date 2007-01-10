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
/*
*
*
* COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
*      ALL RIGHTS RESERVED 
*
*  Author: Dr. Rainer Prosi using JDFSchema code generator 
* 
* Warning! preliminary version. Interface subject to change without prior notice!
* Revision history:
* created 2002-05-31
* based on JDF Schema version JDFc_1_4_R.xsd
*
*/
#if !defined _JDFSeparationList_H_
#define _JDFSeparationList_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFElement.h"
namespace JDF{
	class JDFSeparationSpec;
	/*
	*********************************************************************
	class JDFSeparationList : public JDFElement

	*********************************************************************
	*/
	/**
	* 
	*/
	class JDF_WRAPPERCORE_EXPORT JDFSeparationList : public JDFElement{
	public:


		// Constructors / Destructors  


		/**
		* null ctor
		*/
		inline JDFSeparationList():JDFElement(){};
		/**
		* copy ctor
		*/
		inline JDFSeparationList(const KElement & other):JDFElement(){
			*this=other;
		};
		/**
		* copy equivalance operator
		*/
		JDFSeparationList &operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFSeparationList(){};

		/**
		* Checks if the node is abstract, i.e. is not completely described
		* utility used by GetUnknownElements, GetUnknownAttributes
		* @return boolean: true, if the node is abstract
		*/
		virtual bool IsAbstract()const;


		/**
		* typesafe validator utility
		* @param EnumValidationLevel level validation level
		* @param bool bIgnorePrivate ignore objects in foreign namespaces
		* @param int nMax size of the returned vector
		* @return vWString vector of invalid element names
		*/
		virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;

	protected:
		/**
		* typesafe validator utility - list of valid node names for this class 
		* @return WString& comma separated list of valid node names
		*/

		virtual WString ValidNodeNames()const;
	public:

		/* ******************************************************
		// Attribute Getter / Setter
		****************************************************** */


		/* ******************************************************
		// Element Getter / Setter
		**************************************************************** */


		/** Get Element SeparationSpec
		* @param int iSkip number of elements to skip
		* @return JDFSeparationSpec The element
		*/
		JDFSeparationSpec GetCreateSeparationSpec( int iSkip=0);

		/**
		* Append element SeparationSpec
		*/
		JDFSeparationSpec AppendSeparationSpec();
		/**
		* const get  element SeparationSpec
		* @param int iSkip number of elements to skip
		*@return  JDFSeparationSpec The element
		*/
		JDFSeparationSpec GetSeparationSpec(int iSkip=0)const;

		/**
		definition of optional elements in the JDF namespace
		*/
		virtual WString OptionalElements()const;

		/**
		* Get a list of all separation names in the SeparationSpec elements
		* @return vWString the vector of separation names
		*/
		vWString GetSeparations() const;


		void JDFSeparationList::setSeparations(const vWString& vSeps);

		//////////////////////////////////////////////////////////////////////////////////
		/**
		* append a separationspec with a given name to this
		* @param sep the separation name
		*/
		void appendSeparation(const WString& sep);

		//////////////////////////////////////////////////////////////////////////////////
		/**
		* remove a separationspec with a given name from this
		* 
		* @param sep the separation name
		* @return int the index of the removed separation; -1 if none found
		*/
		int removeSeparation(const WString& sep);
		//////////////////////////////////////////////////////////////////////////////////
		/**
		* Get the n'th separation name in the SeparationSpec elements
		* @param iSkip the index of the SeparationSpec
		* @return separation names, null if iSkip > nSeparations
		*/
		vWString getSeparation(int iSkip)const; 

		//////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////


	}; // endJDFSeparationList

	// ******************************************************
}; // end namespace JDF
#endif //_JDFSeparationList_H_
