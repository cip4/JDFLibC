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
// ////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created 110202
// 260602 RP changed inheritance to JDFAutoAmountPool and removed excess routines
//           added GetPartAmount() pass throughs to JDFAutoAmountPool
//           added AppendPartAmount(mAttribute), Removemount(mAttribute)
//
// JDFAmountPool.h: interface for the JDFAmountPool class.
//
// ////////////////////////////////////////////////////////////////////

#if !defined(_JDFAmountPool_H___)
#define _JDFAmountPool_H___

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#include "AutoJDF/JDFAutoAmountPool.h"

namespace JDF{
	class JDFPartAmount;
	/**
	defines the status pool and a factory for PartAmount objects
	*/
	class JDF_WRAPPERCORE_EXPORT JDFAmountPool : public JDFAutoAmountPool{
	public:
		
	/**
	* empty ctor	
		*/
		JDFAmountPool():JDFAutoAmountPool(){};
		
		/**
		* copy ctor
		*/
		JDFAmountPool(const KElement& other):JDFAutoAmountPool(){
			*this=other;
		};
		
		/**
		* yacctor
		*/
		JDFAmountPool& operator =(const KElement& other);
		
		/**
		* dtor
		*/
		virtual ~JDFAmountPool(){};
		
		
		/**
		* Get a PartAmount that fits to the filter defined by mPart
		* @param mAttribute& mPart filter for the part to set the status
		* @return the PartAmount that fits
		*/		
		JDFPartAmount GetPartAmount(const mAttribute&mPart)const;

		/**
		* Get a vector of PartAmount that exactly fits to the filter defined by mPart
		* @param vmAttribute& mPart filter vector for the part to set the status
		* @return vElement the vector of PartAmount elements that fit
		*/
		vElement GetPartAmountVector(const vmAttribute&mPart)const;
		
		/**
		* Get a vector of PartAmount that are supersets of the filter defined by mPart
		* i.e. mPart is a submap of all returned elements
		* @param mAttribute& mPart filter vector for the part to set the status
		* @return vElement the vector of PartAmount elements that fit
		*/
		vElement GetMatchingPartAmountVector(const mAttribute&mPart)const;

		/**
		* Get a PartAmount that fits to the filter defined by mPart
		* @param mAttribute&mPart filter for the part to set the status
		* @return the PartAmount that fits
		*/
		JDFPartAmount GetCreatePartAmount(const mAttribute&mPart);
		
		/** Get Element PartAmount
		* @param int iSkip number of elements to skip
		* @return JDFPartAmount The element
		*/
		JDFPartAmount GetCreatePartAmount( int iSkip=0);
		
		/**
		* const get first element PartAmount
		*@return  JDFPartAmount The element
		*/
		JDFPartAmount GetPartAmount(int iSkip=0)const;
		
		/**
		* Get a vector of PartAmount that fits to the filter defined by mPart<br>
		* create the PartAmounts if they do not exist
		* @param vmAttribute&mPart filter vector for the part to set the status
		* @return the PartAmount that fits
		*/
		vElement GetCreatePartAmountVector(const vmAttribute&mPart);
		
		/**
		* Append element PartAmount
		*/
		JDFPartAmount AppendPartAmount(const mAttribute&mPart);

		/**
		* Append JDFPartAmount elements
		* @param vPArt vector of partAmounts to append
		*/
		JDFPartAmount AppendPartAmount(const vmAttribute &vPart);
		
		/**
		* Remove element PartAmount
		* @param mAttribute&mPart filter for the part to set the status
		*/
		void RemovePartAmount(const mAttribute&mPart);
		
		/**
		* gets part map vector
		*
		* @return vector of mAttribute, one for each partamount
		*/
		vmAttribute GetPartMapVector()const;
};
		
};

#endif // !defined(_JDFAmountPool_H___)
