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
// created  31.May.2000
// 180700 RP MyString -> WString : all strings now 16 bit
// 180602 RP added ConsistentPartIDKeys()
// 130902 RP GetCommonURLFileSpecMap() added
//
// JDFRunList.h: interface for the JDFRunList class.
//
// ////////////////////////////////////////////////////////////////////

#if !defined(_JDFRunList_H_INCLUDED_)
#define _JDFRunList_H_INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFRunElement.h"
#include "AutoJDF/JDFAutoRunList.h"
namespace JDF{

	class fileSpecMap;
	class JDFLayoutElement;
	/**
	Wrapper around a JDF RunList
	*/
	class JDF_WRAPPERCORE_EXPORT JDFRunList : public JDFAutoRunList{
	public:
		/**
		* null ctor
		*/
		inline JDFRunList():JDFAutoRunList(){};
		/**
		* copy ctor
		*/
		inline JDFRunList(const KElement & other):JDFAutoRunList(){
			*this=other;
		};
		/**
		* copy equivalance operator
		*/
		JDFRunList &operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFRunList(){};

		/**
		* fills the run list with a consolidates set of runs that are defined by vNew
		*/
		JDFRunList SetRunElements(JDFRunElementList vNew);
		/**
		* add a RunList element that is partitioned by Run
		* @param WString fileName the file name of the file to add
		* @param int first the first page in the file to be included in this run
		* @param int last the last page in the file to be included in this run
		* @return JDFRunList the newly created runlist partition
		*/
		JDFRunList AddRun(WString fileName, int first=0, int last=-1);

		/**
		* add a RunList element that is partitioned by Run and has type pdf
		* @param WString fileName the file name of the file to add
		* @param int first the first page in the file to be included in this run
		* @param int last the last page in the file to be included in this run
		* @return JDFRunList the newly created runlist partition
		*/
		JDFRunList AddPDF(WString fileName, int first=0, int last=-1);

		/**
		* set the URL of the LayoutElement/FileSpec of this runlist partition
		* @param WString& url the url to set
		* @return bool true if successful
		*/
		bool SetFileURL (const WString& url);

		/**
		* get the URL of the LayoutElement/FileSpec of this runlist partition
		* @return Ktring the url 
		*/
		WString GetFileURL() const;

		/** getMimeType 
		*
		* Returns the MimeType attribute of the current RunList (partition). If the attribute does not exist, the 
		* empty string is returned.
		*
		* @param const JDF::JDFRunList& runList (in): The RunList partition to obtain the MimeType from.
		*
		* @return JDF::WString: The MimeType string, if the attribute is present, the empty string otherwise.
		* 
		*/
		WString getMimeType()const;

		/// deserialize the runlist into a vector of runelements
		JDFRunElementList GetvRunElement();

		/**
		* add a run separation
		* @param vWString fileNames vector of file names for the URL attribute of the FileSpec in the LayoutElement
		* @param vWString sepNames parallel vector of separation names.
		* @param int firstPage index of the first page in the file - Sets the RunList FirstPage attribute
		* @param nPage the number of logical pages in this run
		* @param bool pageMajor if true separations are order page Major, i.e CMYKCMYK else if false the ordering is CCMMYYKK
		* @return JDFRunList the appended runList
		*/
		JDFRunList AddSepRun(const vWString& fileNames, const vWString& sepNames, int firstPage=0, int nPage=1, bool pageMajor=true);

		/**
		* add a run separation
		* @deprecated use AddSepRun with vectors
		* @param WString fileNames string of sep separated file names for the URL attribute of the FileSpec in the LayoutElement
		* @param WString sepNames parallel string of sep separated of separation names.
		* @param int firstPage index of the first page in the file - Sets the RunList FirstPage attribute
		* @param nPage the number of logical pages in this run
		* @param bool pageMajor if true separations are order page Major, i.e CMYKCMYK else if false the ordering is CCMMYYKK
		* @param WString sep separator for fileNames and sepNames
		* @return JDFRunList the appended runList
		*/
		JDFRunList AddSepRun(const WString& fileNames, const WString& sepNames, int firstPage=0, int nPage=1, bool pageMajor=true, const WString& sep=L",");

		/**
		* add a run separation
		* @deprecated use AddSepRun with vWString
		* @param vElement& vLayoutElement list of layout elements to append for the URL attribute of the FileSpec in the LayoutElement
		* @param vWString sepNames parallel vector of separation names.
		* @param int firstPage index of the first page in the file - Sets the RunList FirstPage attribute
		* @param nPage the number of logical pages in this run
		* @param bool pageMajor if true separations are order page Major, i.e CMYKCMYK else if false the ordering is CCMMYYKK
		* @param WString sep separator for fileNames and sepNames
		* @return JDFRunList the appended runList
		*/
		JDFRunList AddSepRun(const vElement& vLayoutElement,const vWString& sepNames, int firstPage=0, int nPage=1, bool pageMajor=true);

		/**
		* add a run separation
		* @deprecated use AddSepRun with vWString
		* @param vElement& vLayoutElement list of layout elements to append for the URL attribute of the FileSpec in the LayoutElement
		* @param vWString sepNames parallel vector of separation names.
		* @param int firstPage index of the first page in the file - Sets the RunList FirstPage attribute
		* @param nPage the number of logical pages in this run
		* @param bool pageMajor if true separations are order page Major, i.e CMYKCMYK else if false the ordering is CCMMYYKK
		* @param WString sep separator for fileNames and sepNames
		* @return JDFRunList the appended runList
		*/
		JDFRunList AddSepRun(JDFLayoutElement layoutElement, const WString& sepNames, int firstPage=0, int nPage=1, bool pageMajor=true, const WString& sep=L",");

		/**
		* does this leaf have a consistent PartIDKey as specified by key
		* the JDFSurface version requires noe PartIDKey of Side
		* @param EnumPartIDKey key the PartIDKey attribute name
		* @return bool true if key exists in this leaf is in PartIDKeys
		*/
		virtual bool ConsistentPartIDKeys(EnumPartIDKey key) const;

		/**
		* get a list of all partition keys that this resource may be implicitly partitioned by
		* e.g. RunIndex for RunList...
		*
		* @return vint vector of integers that must be casted to EnumPartIDKey
		*/
		virtual vint GetImplicitPartitions() const;

		/**
		* definition of optional attributes in the JDF namespace
		* in this case, we add DocCopies
		*
		* @return WString: list of optional attributes
		*/
		virtual WString OptionalAttributes()const;

		/**
		* Typesafe attribute validation of EndOfBundleItem
		* @param EnumValidationLevel level of attribute validation 
		* @return bool true if valid
		*/
		virtual bool ValidEndOfBundleItem(EnumValidationLevel level=ValidationLevel_Complete) const;

		/**
		* typesafe validator utility
		* @param EnumValidationLevel level validation level
		* @param bool bIgnorePrivate ignore objects in foreign namespaces
		* @param int nMax size of the returned vector
		* @return vWString vector of invalid element names
		*/
		virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;

		/**
		* set attribute Pages
		* @param value: the value to set the attribute to
		*/
		void SetPages(const JDFIntegerRangeList& value);

	protected:

	};
};

#endif // !defined(_JDFRunList_H_INCLUDED_)
