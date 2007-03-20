#if !defined _JDFSheet_H_
#define _JDFSheet_H_

/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001 The International Cooperation for the Integration of 
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
* created 2001-07-08
*
* 120207 NB added "Layout" to ValidNodeNames()
* 130207 NB AppendBackSurface() now throws JDFException, if you try to add a second back surface
* 130207 NB added GetSheetName()
*/

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFSignature.h"
#include "JDFSheet.h"

namespace JDF{
	class JDFSurface;
	/*
	*********************************************************************
	class JDFSheet : public JDFSignature

	*********************************************************************
	*/
	/**
	* Typesafe resource wrapper calls JDFSheet 
	*
	* This file is hand edited and will not be regenerated
	*/
	class JDF_WRAPPERCORE_EXPORT JDFSheet : public JDFSignature{
	public:


		// Constructors / Destructors  


		/**
		* null ctor
		*/
		inline JDFSheet():JDFSignature(){};
		/**
		* copy ctor
		*/
		inline JDFSheet(const KElement & other):JDFSignature(){*this=other;};
		/**
		* copy equivalance operator
		*/
		JDFSheet &operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFSheet(){};
		/**
		* typesafe validator utility
		* also checks for correct surface numbers front + back
		* @param EnumValidationLevel level validation level
		* @param bool bIgnorePrivate ignore objects in foreign namespaces
		* @param int nMax size of the returned vector
		* @return vWString vector of invalid attribute names
		*/
		virtual vWString GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const;

		/** Get Element Surface
		* @param int iSkip number of elements to skip
		* @return JDFSurface The element
		*/
		JDFSurface GetCreateFrontSurface();
		/**
		* Remove element Surface
		* @param int iSkip number of elements to skip
		*/
		void RemoveFrontSurface();
		/**
		* Append element Surface
		*/
		JDFSurface AppendFrontSurface();
		/**
		* const get first element Surface
		*@return  JDFSurface The element
		*/
		JDFSurface GetFrontSurface()const;
		/**
		* test element Surface existance
		* @return bool true if a matching element exists 
		*/
		bool HasFrontSurface() const;

		/** Get Element Surface
		* @param int iSkip number of elements to skip
		* @return JDFSurface The element
		*/
		JDFSurface GetCreateBackSurface();
		/**
		* Remove element Surface
		* @param int iSkip number of elements to skip
		*/
		void RemoveBackSurface();
		/**
		* Append element Surface
		*/
		JDFSurface AppendBackSurface();
		/**
		* const get first element Surface
		*@return  JDFSurface The element
		*/
		JDFSurface GetBackSurface()const;
		/**
		* test element Surface existance
		* @return bool true if a matching element exists 
		*/
		bool HasBackSurface() const;

		/**
		* appends a Surface in both old and new Layouts
		* if old: a <Surface> element
		* if new: a Side partition leaf
		*/
		JDFSurface appendSurface();

		/**
		* counts the number of Surfaces in both old and new Layouts
		* if old: the number of <Surface> elements
		* if new: the number of Side partition leaves
		* @return the number of Surfaces
		*/
		int numSurfaces();

		/**
		* const get element Surface
		* @param int iSkip number of elements to skip
		* @return JDFSurface The element
		*/
		JDFSurface GetSurface(int iSkip=0)const;

		/**
		* const get surface with the correct partition key
		*/
		JDFSurface GetSurfaceBySide(JDFPart::EnumSide side) const;

		/**
		* if this is a new layout, return the partition key signaturename
		* else return Signature/@Name of this or its appropriate parent
		* @return the name of the signature
		*/

		WString GetSheetName() const;
		/**
		* get the vector of surfaces in this sheet
		* @return {@link VElement} the vector of surfaces in this
		*/
		VElement getSurfaceVector()const;

	protected:
		/**
		* typesafe validator utility - list of valid node names for this class 
		* @return WString& comma separated list of valid node names
		*/
		WString ValidNodeNames()const;


	}; // endJDFSheet

	// ******************************************************
}; // end namespace JDF
#endif //_JDFSheet_H_
