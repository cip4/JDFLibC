#if !defined _JDFResourceAudit_H_
#define _JDFResourceAudit_H_

/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2005 The International Cooperation for the Integration of 
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
* created 2001-07-02
// 211102 RP UpdateLink() added
// 250107 NB removed unreferenced variables
*
*/

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "AutoJDF/JDFAutoResourceAudit.h"
#include "JDFResourceLink.h"

namespace JDF{
	/*
	*********************************************************************
	class JDFResourceAudit : public JDFAutoResourceAudit

	*********************************************************************
	*/
	/**
	* Typesafe resource wrapper calss JDFResourceAudit 
	*
	* This file is hand edited and will not be regenerated
	*/
	class JDF_WRAPPERCORE_EXPORT JDFResourceAudit : public JDFAutoResourceAudit{
	public:


		// Constructors / Destructors  


		/**
		* null ctor
		*/
		inline JDFResourceAudit():JDFAutoResourceAudit(){};
		/**
		* copy ctor
		*/
		inline JDFResourceAudit(const KElement & other):JDFAutoResourceAudit(){
			*this=other;
		};
		/**
		* copy equivalance operator
		*/
		JDFResourceAudit &operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFResourceAudit(){};
		/**
		* check for valid elements
		* also check the valididty of ResourceLinks in the ResourceAudit
		*/
		virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=999999) const;
		/**
		* return a vector of unknown element nodenames
		*/
		virtual vWString GetUnknownElements(bool bIgnorePrivate=true,int nMax=99999999)const;

		/**
		* add  a link to the new resource
		* @param JDFResource r the resource that is valid after modification
		* @param bInput usage of the resource
		* @return the ResourceLink object in the ResourceAudit that points to r
		*/
		JDFResourceLink AddNewLink(const JDFResource & r, bool bInput);
		/**
		* add  a link to the original resource
		* @param JDFResource r the resource that was valid before modification
		* @param bInput usage of the resource
		* @return the ResourceLink object in the ResourceAudit that points to r
		*/
		JDFResourceLink AddOldLink(const JDFResource & r, bool bInput);

		/**
		* add  a link to the new resource
		* @return the ResourceLink object in the ResourceAudit 
		*/
		JDFResourceLink GetNewLink()const;

		/**
		* add  a link to the new resource
		* @return the ResourceLink object in the ResourceAudit 
		*/
		JDFResourceLink GetOldLink()const;

		/**
		* Get the vector of ResourceLinks
		* @return vElement the resource links in this
		*/
		vElement GetResourceLinkVector()const;

		/**
		* replace the original updated link with newlink if 2 ResourceLinks are in this
		* if only one is set, it is the original ResourceLink and newLink inserted before the original
		* @param JDFResourceLink newLink the link to the updated resource in the ResourceLinkPool
		* @return the newly created copy in the ResourceAudit
		*/
		JDFResourceLink UpdateLink(const JDFResourceLink & newLink);

		/**
		* add  a link to one of the resources 
		* @param bool bNew - new or original?
		* @param JDFResource r the resource that was valid before modification
		* @param bInput usage of the resource
		* @return the ResourceLink object in the ResourceAudit that points to r
		*/
		JDFResourceLink addNewOldLink(bool bNew, const JDFResource & r, JDFResourceLink::EnumUsage usage);
	private:
		/**
		* add  a link to one of the resources 
		* @param bool bNew - new or original?
		* @param JDFResource r the resource that was valid before modification
		* @param bInput usage of the resource
		* @return the ResourceLink object in the ResourceAudit that points to r
		*/
		JDFResourceLink AddNewOldLink(bool bNew, const JDFResource & r, bool bInput);


		/**
		* add  a link to one of the resources 
		* @param bool bNew - new or original?
		* @param JDFResource r the resource that was valid before modification
		* if r is not specified, return the link that already exists
		* @return the ResourceLink object in the ResourceAudit that points to r
		*/
		JDFResourceLink GetNewOldLink(bool bNew)const;

	}; // endJDFResourceAudit

	// ******************************************************
}; // end namespace JDF
#endif //_JDFResourceAudit_H_
