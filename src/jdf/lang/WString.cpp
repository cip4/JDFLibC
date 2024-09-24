/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2014 The International Cooperation for the Integration of 
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
*
* 050603 TG replaceChar corrected
* 070806 NB using constants from  LIMITS.H and FLOAT.H for Win32 builds
* 070806 NB added double constants
*
*
******************************************************************************/

/******************************************************************************
*	Includes
******************************************************************************/ 

#include <ctime>

#include <xercesc/util/TransService.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/regx/RegularExpression.hpp>
#include <xercesc/util/XMLUniDefs.hpp>
#include <xercesc/util/UTFDataFormatException.hpp>

#include <jdf/lang/WString.h>
#include <jdf/lang/WStringBase.h>
#include <jdf/lang/Janitor.h>
#include <jdf/lang/ByteBuffer.h>
#include <jdf/lang/Mutex.h>
#include <jdf/lang/vWString.h>
#include <jdf/lang/Exception.h>
#include <jdf/util/myuti.h>
#include <jdf/util/dtoa.h>
#include <jdf/util/PlatformUtils.h>

#include <cfloat>


/**********************************************************************/
// nasty macros
#define PBASE ((WStringBaseJDF*)pBase)
#define PBASES(s) ((WStringBaseJDF*)s.pBase)
#define BASES(s) (*((WStringBaseJDF*)s.pBase))

// RN20060320
#define IteratorIPos(iter) (PBASE->begin()+iter.iPos)
#define IteratorIPosS(iter) (((WStringBaseJDF*)iter.pWString)->begin()+iter.iPos)

/*
* In debug mode, we always set a unicode string to the current value for visibility purposes
* this step is left out in release mode for performance reasons
* 051216 - we also allow explicit selection through the _PCDATA macro
*/
#if defined(_DEBUG) || defined(_TDEBUG) || defined(_PCDATA)
#define DATAPOINT pc_data=PBASE->c_str();
#else
#define DATAPOINT 
#endif

#ifdef __MWERKS__
	#include <time.h>
#endif

/******************************************************************************
*	Forward declarations
******************************************************************************/ 
XERCES_CPP_NAMESPACE_USE

namespace JDF
{
	/******************************************************************************
	*	Defines and constants
	******************************************************************************/ 
	const ssize_t WString::npos=-1;
	//@{

	/**
	* the positive INF value INT_MAX
	*/
	const long int WString::pINF = INT_MAX;
	
	/**
	* the negative INF value INT_MIN
	*/
	const long int WString::nINF = INT_MIN;

	/**
	* the positive double INF value DBL_MAX
	*/
	const double WString::pDINF = DBL_MAX;

	/**
	* the positive double INF value DBL_MAX
	*/
	const double WString::nDINF = -DBL_MAX;
	



	/**
	* the positive INF string "INF"
	*/
	const WString WString::pINFstr=L"INF";

	/**
	* the negative INF string "-INF"
	*/
	const WString WString::nINFstr=L"-INF";

	/**
	* the positive DINF string "DINF"
	*/
	const WString WString::pDINFstr=L"DINF";

	/**
	* the negative DINF string "-DINF"
	*/
	const WString WString::nDINFstr=L"-DINF";

	/**
	* the empty string WString::emptyStr
	*/
	const WString WString::emptyStr=L"";

	/**
	* the blank string L" "
	*/
	const WString WString::blank=L" ";

	/**
	* the star string L"*"
	*/
	const WString WString::star=L"*";

	/**
	* the tilde string L","
	*/
	const WString WString::tilde=L"~";

	/**
	* the comma string L","
	*/
	const WString WString::comma=L",";

	/**
	* the dot string dot
	*/
	const WString WString::dot=L".";

	/**
	* the colon string L":"
	*/
	const WString WString::colon=L":";

	/**
	* the question string L"?"
	*/
	const WString WString::question=L"?";

	/**
	* the UTF-8 transcoder string L"UTF-8"
	*/
	const WString WString::utf8=L"UTF-8";

	/**
	* the whitespace string L"\\"
	*/
	const WString WString::whiteSpace=L" \n\t";
	const WString WString::backSlash=L"\\";
	const WString WString::quote=L"\"";
	const WString WString::slash=L"/";
	const WString WString::regExp_duration = L"(-)?[P](((\\d)*)[Y])?((\\d)*[M])?((\\d)*[D])?([T]((\\d)*[H])?((\\d)*[M])?((\\d)*([.](\\d)*)?[S])?)?";
	const WString WString::regExp_datetime =L"(19|20)\\d\\d(-)(0[1-9]|1[012])(-)(0[1-9]|[12][0-9]|3[01])[T](0[0-9]|1[0-9]|2[0123])(:)([0-5][0-9])(:)([0-5][0-9])([.](\\d)*)?(([+-](0[0-9]|1[0-9]|2[0123])(:)([03]0))|[a-zA-Z])?";
	const WString WString::regExp_hexbinary = L"([0-9a-fA-F]{2})+";

	/******************************************************************************
	*	class WStringBaseJDF
	******************************************************************************/ 

    class  WStringBaseJDF : public WStringBase<JDFCh>
    {
    public:
        WStringBaseJDF()
            : WStringBase<JDFCh>()
        {
        }

        WStringBaseJDF(const wchar_t* str)
            : WStringBase<JDFCh>(str)
        {
        }
    };

	///////////////////////////////////////////////////////////////////////////////////////////////

	static Mutex* tokenMutex=0;
	static Mutex* idMutex=0;
	static const WStringBaseJDF emptyBase=L"";

// 	static bool baseDumpInUse=false;
	///////////////////////////////////////////////////////////////////////////////////////////////
	/******************************************************************************
	*	Classes
	******************************************************************************/ 

	/******************************************************************************
	*	Prototypes
	******************************************************************************/ 


	/******************************************************************************
	*	Implementation
	******************************************************************************/ 

	static XMLLCPTranscoder*    gTranscoder = 0;

	//  UTF-8 static reused transcoder
	static XMLTranscoder*    gUTF8Transcoder = 0;

	///////////////////////////////////////////////////////////////////////////////////////////////

	JDFTOOLS_EXPORT std::ostream& operator<<(std::ostream&s,const WString&t){ 
		char* ppc=t.getBytes(); 
		s<<ppc; 
		delete[]ppc; 
		return s; 
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	JDFTOOLS_EXPORT std::wostream& operator<<(std::wostream&s,const WString&t){ 
		return s<<t.c_str(); 
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////

	WString::WString(){
		pc=0;
		pBase=new WStringBaseJDF();
		PBASE->assign(emptyBase);
		DATAPOINT
	}
	///////////////////////////////////////////////////////////////////////////////////////////////

	WString::WString(const JDFCh c) {
		pc=0;
		pBase=new WStringBaseJDF();
		PBASE->assign(1,c);
		DATAPOINT
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	WString::WString(const JDFCh* str,  size_type count) {
		pc=0;
		pBase=new WStringBaseJDF();
		PBASE->assign(str,count);
		DATAPOINT
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	WString::WString(const JDFCh* str){
		pc=0;
		pBase=new WStringBaseJDF();
		PBASE->assign(str);
		DATAPOINT
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	WString::WString(const WString& str){
		pc=0;
		pBase=new WStringBaseJDF();
		PBASE->assign(BASES(str));
		DATAPOINT
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	WString::WString(const WString& str, int offset, int count){
		pc=0;
		pBase=new WStringBaseJDF();
		PBASE->assign(BASES(str),offset,count);
		DATAPOINT
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	WString::WString(size_type n, JDFCh c){
		pc=0;
		pBase=new WStringBaseJDF();
		PBASE->assign(n, c);
		DATAPOINT
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	WString::WString(const char c) { 
		pc=0;
		pBase=new WStringBaseJDF();
		*this=c;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	WString::WString(const unsigned char c) { 
		pc=0;
		pBase=new WStringBaseJDF();
		*this=c;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	WString::WString(const char* c) { 
		pc=0;
		pBase=new WStringBaseJDF();
		*this=c;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	WString::WString(const char* str, size_type count){
		pc=0;
		if(count<=0){
			pBase=new WStringBaseJDF();
		}else{
			JDFCh *pBuf    = NULL;
			char  *pInBuf  = NULL;

			try
			{
				pInBuf   = new char[count+2];
				memcpy(pInBuf, str, count);
				*(pInBuf+count)   = 0;
				*(pInBuf+count+1) = 0;

				// Calculate the buffer size required
				unsigned int neededLen = gTranscoder->calcRequiredSize(pInBuf);
				pBuf  = new JDFCh[neededLen+2];
				// pBuf= new JDFCh[count+1];
				// memset in case the transcoded amount is less than count, e.g. gr,n
				memset(pBuf,0,(neededLen+2)*sizeof(JDFCh));

				if (!gTranscoder->transcode(pInBuf, pBuf, count))
				{
					*pBuf=0;
				}
				else
				{
					*(pBuf+count)=0;
				}
				// clean up
				delete [] pInBuf;

				// use the default JDFCh constructor
				pBase=new WStringBaseJDF(pBuf);
			}
			catch(...)
			{
				// clean up
				delete [] pInBuf;
				delete [] pBuf;
				throw IllegalArgumentException(L"WString::WString, TRANSCODER error");
			}
			delete[]pBuf;
		}
		DATAPOINT
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	WString::WString(const int i){
		pBase=new WStringBaseJDF();
		PBASE->assign(valueOf(i).c_str());
		pc=0;
		DATAPOINT
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	WString::WString(const unsigned int i){
		pBase=new WStringBaseJDF();
		PBASE->assign(valueOf(i).c_str());
		pc=0;
		DATAPOINT
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	WString::WString(const long int i){
		pBase=new WStringBaseJDF();
		PBASE->assign(valueOf(i).c_str());
		pc=0;
		DATAPOINT
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	WString::WString(const JDFInt64 i){
		pBase=new WStringBaseJDF();
		PBASE->assign(valueOf(i).c_str());
		pc=0;
		DATAPOINT
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	WString::WString(const JDFUInt64 i){
		pBase=new WStringBaseJDF();
		PBASE->assign(valueOf(i).c_str());
		pc=0;
		DATAPOINT
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::WString(const double d){
		pBase=new WStringBaseJDF();
		PBASE->assign(valueOf(d).c_str());
		pc=0;
		DATAPOINT
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::WString(const vWString &vS,const WString& sep,const WString& front,const WString& back){
		pBase=new WStringBaseJDF();
		SetvString(vS, sep, front,back); 
		pc=0;
		DATAPOINT
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::~WString(){
		delete PBASE;
		pBase=0;
		if(pc){
			delete[]pc;
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////

	WString& WString::assign(const WString&str){
		PBASE->assign(BASES(str));
		DATAPOINT
			return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::assign(const JDFCh* c){
		PBASE->assign(c);
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::assign(const JDFCh *s, size_type n){
		PBASE->assign(s,n);
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::assign(const WString& str,  size_type pos, size_type n){
		PBASE->assign(BASES(str),pos,n);
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::assign(size_type n, JDFCh c){
		PBASE->assign(n,c);
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::assign(const_iterator first, const_iterator last){
		// RN20060320
		PBASE->assign(IteratorIPosS(first), IteratorIPosS(last));
		DATAPOINT
			return *this;
	}


	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::assign(const char* pc ,size_type n){
		PBASE->assign(BASES(WString(pc,n)));
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::assign(const char* pc ){
		PBASE->assign(BASES(WString(pc)));
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::append(const WString&str){
		PBASE->append(BASES(str));
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::append(size_type n, JDFCh c){
		PBASE->append(n,c);
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::append(size_type n, char c){
		PBASE->append(n,(JDFCh)c);
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::append(const char* pc ,size_type n){
		PBASE->append(BASES(WString(pc,n)));
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::append(const JDFCh *s){
		PBASE->append(s);
		DATAPOINT
			return *this;
	};
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::append(const JDFCh *s, size_type n){
		PBASE->append(s,n);
		DATAPOINT
			return *this;
	};

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::append(const WString& str,  size_type pos, size_type n){
		PBASE->append(BASES(str),pos,n);
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	const JDFCh* WString::c_str()const{
		return PBASE->c_str();
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	const JDFCh* WString::data()const{
		return PBASE->data();
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::const_reference WString::at(int i)const{
		return PBASE->at(i);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::reference WString::at(int i){
		return PBASE->at(i);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::const_reference WString::charAt(int i)const{
		return PBASE->at(i);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::reference WString::charAt(int i){
		return PBASE->at(i);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	const WString::size_type WString::length()const{
		return PBASE->length();
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString WString::substring(int beginIndex) const { 
		WString s(PBASE->substring(beginIndex,length()).c_str());
		return s;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString WString::substring(int beginIndex, int endIndex) const { 
		WString s(PBASE->substr(beginIndex,endIndex-beginIndex).c_str());
		return s;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString WString::substr(size_type pos , size_type n) const{
		WString s(PBASE->substr(pos,n).c_str());
		return s;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////

	WString& WString::erase(size_type p0 , size_type n ){
		PBASE->erase(p0,n);
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	void WString::resize(size_type n, JDFCh c ){
		PBASE->resize(n,c);
		DATAPOINT
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::size() const{
		return PBASE->size();
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool WString::startsWith(const WString &w) const{
		return PBASE->startsWith(BASES(w));
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	bool WString::startsWith(const char* prefix)const{
		return PBASE->startsWith(BASES(WString(prefix)));
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool WString::startsWith(const WString& prefix, int offset)const{
		return PBASE->startsWith(BASES(prefix),offset);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool WString::startsWith(const char* prefix, int offset) const{
		return PBASE->startsWith(BASES(WString(prefix)),offset);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool WString::startsWithIgnoreCase(const WString& str)const{
		return str.compareToIgnoreCase(leftstring(str.length())) == 0;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool WString::startsWithIgnoreCase(const char* str) const{
		return startsWithIgnoreCase(WString(str));
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	bool WString::endsWith(const WString &w) const{
		return PBASE->endsWith(BASES(w));
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool WString::empty() const{
		return PBASE->empty();
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString WString::leftStr (int n) const{
		WString s(PBASE->leftStr(n).c_str());
		return s;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString WString::leftstring (int n) const{
		WString s(PBASE->leftstring(n).c_str());		
		return s;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString WString::rightStr (int n) const{
		WString s(PBASE->rightStr(n).c_str());
		return s;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString WString::rightstring (int n) const{
		WString s(PBASE->rightstring(n).c_str());
		return s;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	int WString::compare(const WString& str) const{
		return PBASE->compare(BASES(str));
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	int WString::compare(size_type p0, size_type n0,   const WString& str){
		return PBASE->compare(p0,n0,BASES(str));
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	int WString::compare(size_type p0, size_type n0,    const WString& str, size_type pos, size_type n){
		return PBASE->compare(p0,n0,BASES(str),pos,n);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	int WString::compare(const JDFCh *s) const{
		return wcscmp(PBASE->c_str(),s);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	int WString::compare(size_type p0, size_type n0,    const JDFCh *s) const{
		return PBASE->compare(p0,n0,s);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	int WString::compare(size_type p0, size_type n0,    const JDFCh *s, size_type pos) const{
		return PBASE->compare(p0,n0,s,pos);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find(JDFCh c, size_type pos ) const{
		return PBASE->find(c,pos);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find(const JDFCh *s, size_type pos ) const{
		return PBASE->find(s,pos);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find(const JDFCh *s, size_type pos, size_type n) const{
		return PBASE->find(s,pos,n);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find(const WString& str, size_type pos) const{
		return PBASE->find(BASES(str),pos);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::rfind(JDFCh c, size_type pos ) const{
		return PBASE->rfind(c,pos);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::rfind(const JDFCh *s, size_type pos ) const{
		return PBASE->rfind(s,pos);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::rfind(const JDFCh *s, size_type pos, size_type n) const{
		return PBASE->rfind(s,pos,n);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::rfind(const WString& str, size_type pos) const{
		return PBASE->rfind(BASES(str),pos);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::insert(size_type p0, const JDFCh *s){
		PBASE->insert(p0,s);
		DATAPOINT
			return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::insert(size_type p0, const JDFCh *s, size_type n){
		PBASE->insert(p0,s,n);
		DATAPOINT
			return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::insert(size_type p0,    const WString& str){
		PBASE->insert(p0,BASES(str));
		DATAPOINT
			return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::insert(size_type p0,    const WString& str, size_type pos, size_type n){
		PBASE->insert(p0,BASES(str),pos,n);
		DATAPOINT
			return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::insert(size_type p0, size_type n, JDFCh c){
		PBASE->insert(p0,n,c);
		DATAPOINT
			return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::iterator WString::insert(iterator it, JDFCh c){
		// RN20060320
		PBASE->insert(IteratorIPos(it), c);
		DATAPOINT
			return WStringIterator(pBase,it.iPos);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	void WString::insert(iterator it, const_iterator first, const_iterator last){
		// RN20060320
		PBASE->insert(IteratorIPos(it), IteratorIPosS(first), IteratorIPosS(last));
		DATAPOINT
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	void WString::insert(iterator it, size_type n, JDFCh c){
		// RN20060320
		PBASE->insert(IteratorIPos(it), n, c);
		DATAPOINT
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::replace(size_type p0, size_type n0,    const JDFCh *s){
		PBASE->replace(p0,n0,s);
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::replace(size_type p0, size_type n0,    const JDFCh *s, size_type n){
		PBASE->replace(p0,n0,s,n);
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::replace(size_type p0, size_type n0,    const WString& str){
		PBASE->replace(p0,n0,BASES(str));
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::replace(size_type p0, size_type n0,    const WString& str, size_type pos, size_type n){
		PBASE->replace(p0,n0,BASES(str),pos,n);
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::replace(size_type p0, size_type n0,    size_type n, JDFCh c){
		PBASE->replace(p0,n0,n,c);
		DATAPOINT
			return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////

	WString& WString::replace(iterator first0, iterator last0, const JDFCh* s){
		// RN20060320
		PBASE->replace(IteratorIPos(first0), IteratorIPos(last0), s);
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::replace(iterator first0, iterator last0,    const JDFCh *s, size_type n){
		// RN20060320
		PBASE->replace(IteratorIPos(first0), IteratorIPos(last0), s, n);
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::replace(iterator first0, iterator last0,    const WString& str){
		// RN20060320
		PBASE->replace(IteratorIPos(first0), IteratorIPos(last0), BASES(str));
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::replace(iterator first0, iterator last0,    size_type n, JDFCh c){
		// RN20060320
		PBASE->replace(IteratorIPos(first0), IteratorIPos(last0) ,n, c);
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString& WString::replace(iterator first0, iterator last0, const_iterator first, const_iterator last){
		// RN20060320
		PBASE->replace(IteratorIPos(first0), IteratorIPos(last0),
			IteratorIPosS(first), IteratorIPosS(last));
		DATAPOINT
			return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find_first_of(JDFCh c, size_type pos ) const{
		return PBASE->find_first_of(c,pos);
	};
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find_first_of(const JDFCh *s, size_type pos ) const{
		return PBASE->find_first_of(s,pos);
	};
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find_first_of(const JDFCh *s, size_type pos, size_type n ) const{
		return PBASE->find_first_of(s,pos,n);
	};
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find_first_of(const WString& str,    size_type pos) const{
		return PBASE->find_first_of(BASES(str),pos);
	};


	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find_first_not_of(JDFCh c, size_type pos ) const{
		return PBASE->find_first_not_of(c,pos);
	};
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find_first_not_of(const JDFCh *s, size_type pos ) const{
		return PBASE->find_first_not_of(s,pos);
	};
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find_first_not_of(const JDFCh *s, size_type pos, size_type n ) const{
		return PBASE->find_first_not_of(s,pos,n);
	};
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find_first_not_of(const WString& str,    size_type pos) const{
		return PBASE->find_first_not_of(BASES(str),pos);
	};

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find_last_of(JDFCh c, size_type pos ) const{
		return PBASE->find_last_of(c,pos);
	};
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find_last_of(const JDFCh *s, size_type pos ) const{
		return PBASE->find_last_of(s,pos);
	};
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find_last_of(const JDFCh *s, size_type pos, size_type n ) const{
		return PBASE->find_last_of(s,pos,n);
	};
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find_last_of(const WString& str,    size_type pos) const{
		return PBASE->find_last_of(BASES(str),pos);
	};


	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find_last_not_of(JDFCh c, size_type pos ) const{
		return PBASE->find_last_not_of(c,pos);
	};
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find_last_not_of(const JDFCh *s, size_type pos ) const{
		return PBASE->find_last_not_of(s,pos);
	};
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find_last_not_of(const JDFCh *s, size_type pos, size_type n ) const{
		return PBASE->find_last_not_of(s,pos,n);
	};
	///////////////////////////////////////////////////////////////////////////////////////////////
	WString::size_type WString::find_last_not_of(const WString& str,    size_type pos) const{
		return PBASE->find_last_not_of(BASES(str),pos);
	};

	///////////////////////////////////////////////////////////////////////////////////////////////
	WString WString::replaceChar(JDFCh oldChar, JDFCh newChar) const{
		return WString((PBASE->replaceChar(oldChar,newChar)).c_str());
		/*WString s(*this);
		PBASES(s)->replaceChar(oldChar,newChar);
		return s;*/
	}




	///////////////////////////////////////////////////////////////////////////////////////////////
	bool WString::regionMatches(int toffset, const WString& other, int ooffset, int len) const{
		return PBASE->regionMatches( toffset, BASES(other),  ooffset,  len);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool WString::regionMatches(bool ignoreCase, int toffset, const WString& other, int ooffset, int len) const{
		return PBASE->regionMatches( ignoreCase, toffset, BASES(other),  ooffset, len);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	int WString::indexOf(const WString&str,int fromIndex) const{
		return PBASE->indexOf(  BASES(str), fromIndex);
	}

	////////////////////////////////////////////////////////////////////////

	int WString::numOccurrenceOf(const WString&str) const{
		int n=0;
		int pos=0;
		while (42){
			pos=indexOf(str,pos);
			if(pos==WString::npos)
				break;
			n++;
			pos++;
		}
		return n;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////






	///////////////////////////////////////////////////////////////////////////////////////////////

	void WString::initString(void* defToUse)
	{
		gTranscoder = (XMLLCPTranscoder*) defToUse;

		// needed for wcstok critical section
		tokenMutex=new Mutex();
		idMutex=new Mutex();

		XMLTransService::Codes resCode;
		const int kTmpBufSize = 1024;
		gUTF8Transcoder = XMLPlatformUtils::fgTransService->makeNewTranscoderFor
			(
			L"UTF-8"
			, resCode
			, kTmpBufSize
#if !((XERCES_VERSION_MAJOR==2)&&(XERCES_VERSION_MINOR<3))
			, XMLPlatformUtils::fgMemoryManager
#endif
			);


	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	void WString::terminate(){
		ClearBaseDump();
		delete gTranscoder;
		gTranscoder=0;
		delete gUTF8Transcoder;
		gUTF8Transcoder=0;
		gTranscoder=0;
		delete idMutex;
		delete tokenMutex;
		tokenMutex=0;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	void WString::ClearBaseDump(){
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	bool WString::equalsIgnoreCase(const char* str) const{
		return compareToIgnoreCase(WString(str))==0;
	}

	bool WString::equalsIgnoreCase(const JDFCh* str) const{
		return compareToIgnoreCase(str)==0;
	}

	bool WString::equalsIgnoreCase(const WString& str) const{
		return compareToIgnoreCase(str)==0;
	}

	bool WString::equals(const WString& str) const{
		return compare(str)==0;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	int WString::compareToIgnoreCase(const char* str) const 
	{
		WString s(str);

		// Refer this one to the transcoding service
		return XMLPlatformUtils::fgTransService->compareIString(this->c_str(),s.c_str());
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////7
	int WString::compareToIgnoreCase(const JDFCh* str) const 
	{
		return XMLPlatformUtils::fgTransService->compareIString(this->c_str(),str);
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////7
	int WString::compareToIgnoreCase(const WString& str) const 
	{
		return XMLPlatformUtils::fgTransService->compareIString(this->c_str(),str.c_str());
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////7
	WString WString::trim() const
	{
		WString s(*this);
		WStringBaseJDF* ps=(WStringBaseJDF*)(s.pBase);

		size_type posBeg = 0;
		size_type posEnd = ps->length();

		while ((posBeg < posEnd) && iswspace(ps->at(posBeg)) )
			posBeg++;

		while ((posEnd > posBeg) && iswspace(ps->at(posEnd-1)) )
			posEnd--;

		if (posBeg < posEnd)
			ps->assign(ps->substr(posBeg, posEnd - posBeg));
		else
			ps->erase();

		return s; 
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////7
	WString WString::trimRight() const
	{
		WString s(*this);
		WStringBaseJDF* ps=(WStringBaseJDF*)(s.pBase);
		size_type posEnd = ps->length();
		while ((posEnd > 0) &&  iswspace(ps->at(posEnd-1)) )
			posEnd--;
		ps->resize(posEnd);
		return s; 
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////7

	WString WString::trimLeft() const
	{
		WString s(*this);
		WStringBaseJDF* ps=(WStringBaseJDF*)(s.pBase);

		size_type posBeg = 0;
		size_type posEnd = ps->length();
		while ((posBeg < posEnd) && iswspace(ps->at(posBeg)) )
			posBeg++;
		ps->assign(ps->substr(posBeg));
		return s; 
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////7

	WString WString::toLowerCase() const
	{
		int l=length();
		JDFCh* buf=new JDFCh[l+1];
		buf[l]=0;
		memcpy(buf,c_str(),l*sizeof(JDFCh));
		XMLPlatformUtils::fgTransService->lowerCase(buf);
		WString s=buf;
		delete[]buf;
		return s;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////7


	WString WString::toUpperCase() const
	{
		int l=length();
		JDFCh* buf=new JDFCh[l+1];
		buf[l]=0;
		memcpy(buf,c_str(),l*sizeof(JDFCh));
		XMLPlatformUtils::fgTransService->upperCase(buf);
		WString s=buf;
		delete[]buf;
		return s;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////7
	WString& WString::operator=(const char str){
		char buf[2];
		buf[0]=str;
		buf[1]=0;
		return operator=(buf);
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////7
	WString& WString::operator=(const unsigned char str){
		char buf[2];
		buf[0]=str;
		buf[1]=0;
		return operator=(buf);
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////7
	bool WString::operator==(const WString& str)const{
		return PBASE->compare(BASES(str))==0;
	};
	////////////////////////////////////////////////////////////////////////////////////////////////////7
	bool WString::operator==(const JDFCh* pc)const{
		return wcscmp(PBASE->c_str(),pc)==0;
	};

	////////////////////////////////////////////////////////////////////////
	bool WString::operator!=(const WString& str)const{
		return PBASE->compare(BASES(str))!=0;
	};
	////////////////////////////////////////////////////////////////////////////////////////////////////7
	bool WString::operator!=(const JDFCh* pc)const{
		return wcscmp(PBASE->c_str(),pc)!=0;
	};

	////////////////////////////////////////////////////////////////////////

	bool WString::operator<(const WString& str)const{
		return PBASE->compare(BASES(str))<0;
	};
	////////////////////////////////////////////////////////////////////////////////////////////////////7
	bool WString::operator<(const JDFCh* pc)const{
		return wcscmp(PBASE->c_str(),pc)<0;
	};
	////////////////////////////////////////////////////////////////////////

	bool WString::operator>(const WString& str)const{
		return PBASE->compare(BASES(str))>0;
	};
	////////////////////////////////////////////////////////////////////////
	bool WString::operator>(const JDFCh* pc)const{
		return wcscmp(PBASE->c_str(),pc)>0;
	};
	////////////////////////////////////////////////////////////////////////

	bool WString::operator<=(const WString& str)const{
		return PBASE->compare(BASES(str))<=0;
	};
	////////////////////////////////////////////////////////////////////////
	bool WString::operator<=(const JDFCh* pc)const{
		return wcscmp(PBASE->c_str(),pc)<=0;
	};
	////////////////////////////////////////////////////////////////////////

	bool WString::operator>=(const WString& str)const{
		return PBASE->compare(BASES(str))>=0;
	};

	////////////////////////////////////////////////////////////////////////
	bool WString::operator>=(const JDFCh* pc)const{
		return wcscmp(PBASE->c_str(),pc)>=0;
	};
	////////////////////////////////////////////////////////////////////////
	WString::const_reference WString::operator[](size_type pos) const{
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	WString::reference WString::operator[](size_type pos){
		return PBASE->at(pos);
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////7
	WString& WString::operator=(const WString& w)
	{
		if (pBase == w.pBase) 
			return *this;

		*PBASE=*((WStringBaseJDF*)w.pBase);
		DATAPOINT
			return *this;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////7

	WString& WString::operator=(const char* str)
	{
		if ((str != NULL) && strlen(str) != 0)
		{

			//			unsigned int minLength = gTranscoder->calcRequiredSize(str);
			// assume a maximum of the char string length but prefill it with 0, 
			// so that it is null terminated, even if the transcoded string is shorter
			// 
			unsigned int minLength = strlen(str);		

			JDFCh *pBuf=  new JDFCh[minLength+1];
			memset(pBuf,0,minLength*sizeof(JDFCh));

			if (!gTranscoder->transcode(str, pBuf, minLength)){
				PBASE->erase();
			}else{
				*(pBuf+minLength)=0;
				PBASE->assign(pBuf);
			}

			delete[]pBuf;

		}else{
			PBASE->erase();
		}
		DATAPOINT
			return *this;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////7
	WString& WString::operator+=(const WString& str) { 
		append(str); 
		return *this;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////7
	WString& WString::operator+=(const char c) { 
		WString s(c); 
		append(s); 
		return *this;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////7
	WString& WString::operator+=(const char* c) { 
		WString s(c); 
		append(s); 
		return *this;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////7
	WString& WString::operator+=(char* c) { 
		return operator+=((const char*) c);
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////7
	WString& WString::operator+=(const JDFCh c) { 
		append(1,c); 
		return *this;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////7
	////////////////////////////////////////////////////////////////////////////////////////////////////7

	bool WString::IsTranscodable() const{
		// old version - still maintained
		if(gTranscoder->calcRequiredSize(c_str())==0)
			return false;

		// xerces 2.6 switched transcoding calls from mbstowcs() to WideCharToMultiByte() which now replaces non-encodeable 
		// chars with a literal '?'. thus if more '?' are ther after encoding, something is fishy
		// this should be transparent to the mac and linux versions (except for the obvious performance hit...)
		char* pbc=getBytes();
		bool bRet= numOccurrenceOf(question)==WString(pbc).numOccurrenceOf(question);
		delete[] pbc;
		return bRet;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////7

	char* WString::getBytes() const
	{

		int siz=gTranscoder->calcRequiredSize(c_str()); // the returned string is a mbstring 

		char*d=new char[siz+1];
		*d=0;
		if(!siz)
			return d;
		// create the new buffer
		bool b=gTranscoder->transcode(c_str(),d,siz);

		// all's well
		if(b)
			return d;

		// snafu
		delete[] d;
		d=new char[1];
		*d=0;
		return d;
	}


	////////////////////////////////////////////////////////////////////////////////////////////////////7

	char* WString::getBytes(const WString& encoding) const
	{
		ByteBuffer buffer;

		// Try to create a transcoder for this encoding
		XMLTransService::Codes resCode;
		const int kTmpBufSize = 1024;
		XMLTranscoder* fXCoder = XMLPlatformUtils::fgTransService->makeNewTranscoderFor
			(
			encoding.c_str()
			, resCode
			, kTmpBufSize
#if !((XERCES_VERSION_MAJOR==2)&&(XERCES_VERSION_MINOR<3))
			, XMLPlatformUtils::fgMemoryManager
#endif
			);

		if (fXCoder == NULL)
			throw IllegalArgumentException(WString(L"WString::getBytes illegal encoder: ")+encoding);

		unsigned char* tmpBuf = new unsigned char[kTmpBufSize];
		ArrayJanitor<unsigned char> tmpBufJanitor(tmpBuf);

		//  If we don't have any escape flags set, then we can do the most
		//  efficient loop, else we have to do it the hard way.
		//
		const JDFCh*    srcPtr = PBASE->data();
		const JDFCh*    endPtr = PBASE->data() + PBASE->length();
		XMLSize_t    charsEaten;
		//
		//  Just do a whole buffer at a time into the temp buffer, cap it
		//  off, and send it to the target.
		//
		while (srcPtr < endPtr)
		{
			const unsigned int srcCount = endPtr - srcPtr;
			const unsigned srcChars = srcCount > kTmpBufSize ? kTmpBufSize : srcCount;

			const unsigned int outBytes = fXCoder->transcodeTo
				(
				srcPtr
				, srcChars
				, tmpBuf
				, kTmpBufSize
				, charsEaten
				, XMLTranscoder::UnRep_RepChar
				);

			// If we get any bytes out, then write them
			if (outBytes)
			{
				//fTmpBuf[outBytes] = 0;
				//fTarget->writeChars(fTmpBuf);
				buffer.append((char*)tmpBuf,outBytes);
			}

			// throw an exception for illegal input streams
			if(!charsEaten)
				throw IllegalArgumentException(WString(L"WString::getBytes illegal input chars: ")+data());

			// And bump up our pointer
			srcPtr += charsEaten;
		}
		buffer.append('\0');

		//TODO cache latest transcoder
		delete fXCoder;
		char* ret = buffer.bytes();
		buffer.orphan();
		return ret;
	}


	////////////////////////////////////////////////////////////////////////////////////////////////////


	void WString::putBytes(const char* chars, int len, const WString& encoding){

		if(encoding.empty()){
			*this=WString(chars,len);
		}else{
			if(len<0)
				len=strlen(chars);
			JDFCh* buf=new JDFCh[len+1];
			memset(buf,0,len+1*sizeof(JDFCh));

			XMLByte* charSizes=new XMLByte[len+1];

			// Try to create a transcoder for this encoding
			XMLTransService::Codes resCode;
			const int kTmpBufSize = 1024;
			XMLTranscoder* fXCoder = XMLPlatformUtils::fgTransService->makeNewTranscoderFor
				(
				encoding.c_str()
				, resCode
				, kTmpBufSize
#if !((XERCES_VERSION_MAJOR==2)&&(XERCES_VERSION_MINOR<3))
				, XMLPlatformUtils::fgMemoryManager
#endif
				);

			if (fXCoder == NULL){
				delete[] buf;
				delete[] charSizes;
				throw IllegalArgumentException(WString(L"WString::putBytes illegal transcoder: ")+encoding);
			}
			//  If we don't have any escape flags set, then we can do the most
			//  efficient loop, else we have to do it the hard way.
			//
			XMLSize_t    charsEaten;
			//

			const unsigned int outBytes = fXCoder->transcodeFrom(
				(const unsigned char *const)chars
				, len
				, buf
				, len
				, charsEaten
				, charSizes
				);


			//TODO cache latest transcoder
			delete fXCoder;
			delete[] charSizes;
			PBASE->assign(buf,outBytes);
			delete[] buf;

			// throw an exception for illegal input streams
			if(charsEaten<len)
				throw IllegalArgumentException(WString(L"WString::putBytes illegal input chars: ")+data());

			// And bump up our pointer

		}
	}


	////////////////////////////////////////////////////////////////////////////////////////////////////
	const char* WString::peekBytes(const WString& encoding)const
	{
		// hack to make const, this is actually safe since multiple calls do not modify this
		char** ppc=(char**) &pc; // unconstify pc and access by reference ;-)
		if(pc)
			delete[]*ppc; 
		*ppc=getBytes(encoding); 
		return pc;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////
	const char* WString::peekBytes()const
	{
		// hack to make const, this is actually safe since multiple calls do not modify this
		char** ppc=(char**) &pc;  // unconstify pc and access by reference ;-)
		if(pc)
			delete[]*ppc; 
		*ppc=getBytes(); 
		return pc;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////

	WString WString::valueOf(JDFCh c)
	{
		return WString(c);
	}

	WString WString::valueOf(const JDFCh* data)
	{
		return WString(data);
	}

	WString WString::valueOf(const char* data)
	{
		return WString(data);
	}

	WString WString::valueOf(const char data)
	{
		return WString(data);
	}

	WString WString::valueOf(double d)
	{
		char temp[515];
		size_t templen = dtoa(temp, d, 'f', 50, 8);
		return WString(temp,templen);
	}

	WString WString::valueOf(float f)
	{
		char temp[515];
		size_t templen = dtoa(temp, (double)f, 'f', 50, 8);
		return WString(temp,templen);
	}

	WString WString::valueOf(int i)
	{
		WString w;

		w.resize((size_type)33);
		_itow(i,(JDFCh*)w.data(),10);
		w.resize(wcslen(w.c_str()));
		return w;
	}

	WString WString::valueOf(long l)
	{
		WString w;
		w.resize((size_type)33);
		_ltow(l,(JDFCh*)w.data(),10);
		w.resize(wcslen(w.c_str()));
		return w;
	}
	WString WString::valueOf(bool b)
	{
		return b? L"true" : L"false";
	}

	WString WString::valueOf(short s)
	{
		WString w;
		w.resize((size_type)33);
		_itow(s,(JDFCh*)w.data(),10);
		w.resize(wcslen(w.c_str()));
		return w;
	}

	WString WString::valueOf(unsigned int i)
	{
		WString w;
		w.resize((size_type)33);
		_ultow(i,(JDFCh*)w.data(),10);
		w.resize(wcslen(w.c_str()));
		return w;
	}

	WString WString::valueOf(unsigned long l)
	{
		WString w;
		w.resize((size_type)33);
		_ultow(l,(JDFCh*)w.data(),10);
		w.resize(wcslen(w.c_str()));
		return w;

	}

	WString WString::valueOf(JDFUInt64 n)
	{
		WString w;
		w.resize((size_type)33);
		_ui64tow(n,(JDFCh*)w.data(),10);
		w.resize(wcslen(w.c_str()));
		return w;
	}

	WString WString::valueOf(JDFInt64 n)
	{
		WString w;
		w.resize((size_type)33);
		_i64tow(n,(JDFCh*)w.data(),10);
		w.resize(wcslen(w.c_str()));
		return w;
	}

	//@vigo: fixed trim usage
	bool WString::isNumber() const
	{
		WString str(this->trim());
		if (str.empty())
			return false;

		if(!str.compare(pINFstr))
			return true;

		if(!str.compare(nINFstr))
			return true;

		if(!str.compare(pDINFstr))
			return true;

		if(!str.compare(nDINFstr))
			return true;

		wchar_t* pEnd = NULL;
		wcstol(str.c_str(), &pEnd, 10);
		if (!*pEnd)
			return true;

		wcstod(str.c_str(), &pEnd);

		if (!*pEnd)
			return true;

		return false;
	}

	WString WString::formatInteger(int i)
	{
		WString s;
		if (i == WString::pINF)
		{
			s = WString::pINFstr;
		}
		else if (i == WString::nINF)
		{
			s = WString::nINFstr;
		}
		else
		{
			s = WString::valueOf(i);
		}
		return s;
	}


	//@vigo: fixed trim usage
	bool WString::isInteger() const
	{
		WString str(this->trim());
		if (str.empty())
			return false;

		if(!str.compare(pINFstr))
			return true;

		if(!str.compare(nINFstr))
			return true;

		{
			wchar_t* pEnd = NULL;
			wcstol(str.c_str(), &pEnd, 10);
			if (!*pEnd)
				return true;
		}

		return false;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	bool WString::isBoolean() const{
		return !PBASE->compare(L"true")||!PBASE->compare(L"false");
	}
	//////////////////////////////////////////////////////////////////////////////////////
	// tbd add more exceptions
	bool WString::isNMTOKEN() const{
		if(empty())
			return false;
		bool bNMToken=PBASE->find_first_of(BASES(whiteSpace))==npos;
		return bNMToken;
	}
	//////////////////////////////////////////////////////////////////////////////////////
	bool WString::isNMTOKENS() const{
		vWString vs=Tokenize(whiteSpace);
		int s=vs.size();
		if(vs.size()==0) 
			return true; // empty lists are valid
		for(int i=0;i<s;i++){
			if(!vs[i].isNMTOKEN()) 
				return false;
		}
		return true;
	}
	//////////////////////////////////////////////////////////////////////////////////////

	bool WString::isAlpha(JDFCh const ch)
	{
		if ((( ch >= chLatin_a ) && ( ch <= chLatin_z )) ||
			(( ch >= chLatin_A ) && ( ch <= chLatin_Z )) )
			return true;

		return false;
	}

	bool WString::isAlphaNum(JDFCh const ch)
	{
		return (isAlpha(ch) || isDigit(ch));
	}

	bool WString::isDigit(JDFCh const ch)
	{
		if (( ch >= chDigit_0 ) && ( ch <= chDigit_9 ))
			return true;
		return false;
	}

	bool WString::isHex(JDFCh const ch)
	{
		return (isDigit(ch) ||
			(ch >= chLatin_a && ch <= chLatin_f) ||
			(ch >= chLatin_A && ch <= chLatin_F));
	}

	/**
	* @return conversion to double
	*/
	WString::operator JDFUInt64() const {
		if(!isNumber()) 
			throw IllegalArgumentException(); 
		char * pc=getBytes();
		JDFUInt64 i=_atoi64(pc);  
		delete pc;
		return i;
	}

	///////////////////////////////////////////////////////////////////////////////

	WString::operator JDFInt64() const {
		if(!isNumber()) 
			throw IllegalArgumentException(); 
		char * pc=getBytes();
		JDFInt64 i=_atoi64(pc);  
		delete pc;
		return i;
	}

	/**
	* @return conversion to double
	*/
	WString::operator double() const {

		if(!isNumber()) 
			throw IllegalArgumentException();

		WString str(this->trim());

		if(!str.compare(pINFstr))
			return pINF;
		if(!str.compare(nINFstr))
			return nINF;
		if(!str.compare(pDINFstr))
			return pDINF;
		if(!str.compare(nDINFstr))
			return nDINF;
		return  wcstod(c_str(), 0);   
	}
	/**
	* @return conversion to integer
	* using isNumber for int is NOT a copy paste bug. (int) on doubles will return a truncated integer
	*/
	WString::operator int()  const  {
		if(!isNumber()) 
			throw IllegalArgumentException("WString::operator int(): " + *this + " is not a number"); 

		WString str(this->trim());

		if(!str.compare(pINFstr))
			return pINF;
		if(!str.compare(nINFstr))
			return nINF;
		return wcstol(c_str(), 0, 10);
	}

	/**
	* @return conversion to boolean
	*/
	WString::operator bool()  const  {
		if(!isBoolean()) 
			throw IllegalArgumentException("WString::operator bool(): " + *this + " is not a boolean"); 
		return (compareToIgnoreCase(L"true") == 0);
	}


	///////////////////////////////////////////////////////////////////////////

	WString WString::ZappTokenWS(const WString& token){
		vWString vs=Tokenize(token);
		int vss=vs.size();
		for(int i=0;i<vss;i++){
		    vs[i]=vs[i].trim();
		}
		return SetvString(vs,token);
	}

	//////////////////////////////////////////////////////////////////////

	WString WString::SetvString(const vWString& v, const WString& sep, const WString& front , const WString& end){
		WString s=front;
		int siz=v.size();
		for(int i=0;i<siz;i++){
			if(i) s+=sep;
			s+=v[i];
		}
		s+=end;
		assign(s);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////

	WString WString::Token(int i,const WString& separator) const{
		if(empty())
			return emptyStr;

		wchar_t* buf=new wchar_t[size()+1];
		const wchar_t* pSeparator=separator.c_str();
		wcscpy (buf,c_str());

		// all wcstok calls must be in a critical section to avoid overwriting the global buffer
		tokenMutex->lock();

		// *!* Solaris also has the two-parameter version -af-
#if defined(_WIN32) || defined(__SUNPRO_CC)
		wchar_t* tok=wcstok(buf,pSeparator);
#else
		wchar_t *tok, *tok2;
		tok = wcstok(buf,pSeparator,&tok2);
#endif
		for(int ii=0;ii<i;ii++){		
			// *!* Solaris also has the two-parameter version -af-
#if defined(_WIN32) || defined(__SUNPRO_CC)
			tok=wcstok(0,pSeparator); // While there are tokens in buf,get next token
#else
			tok=wcstok(0,pSeparator,&tok2); // While there are tokens in buf,get next token
#endif
			// 051102 RP check for end of token list and gracefully return null string
			if(!tok)
				break;
		}
		WString s=tok ? WString(tok) : emptyStr; /// better do this since I'm deleting buf and thus tok!
		delete[](buf);
		tokenMutex->unlock();

		return s;
	}

	//////////////////////////////////////////////////////////////////////

	vWString WString::Tokenize(const WString & separator) const {
		if(empty())
			return vWString::emptyvStr;
		wchar_t* buf=new wchar_t[size()+1];
		wcscpy (buf,c_str());
		const wchar_t* pSeparator=separator.c_str();
		*(buf+size())=0x0000; //needed by linux-wcstok
		vWString tokens;

		// all wcstok calls must be in a critical section to avoid overwriting the global buffer
		tokenMutex->lock();

		// *!* Solaris also has the two-parameter version -af-
#if defined(_WIN32) || defined(__SUNPRO_CC)
		wchar_t* tok=wcstok(buf,pSeparator);
#else
		wchar_t *tok, *tok2;
		tok = wcstok(buf,pSeparator,&tok2);
#endif
		while(tok){
			tokens.push_back(WString(tok));  // store token in the container
			// *!* Solaris also has the two-parameter version -af-
#if defined(_WIN32) || defined(__SUNPRO_CC)
			tok=wcstok(0,pSeparator); // While there are tokens in buf,get next token
#else
			tok=wcstok(0,pSeparator,&tok2); // While there are tokens in buf,get next token
#endif
		}
		delete[](buf);
		tokenMutex->unlock();
		return tokens;
	}


	//////////////////////////////////////////////////////////////////////


	int WString::PosOfToken(const WString & token, const WString & separator, int iSkip) const {
		const JDFCh* pSep=separator.c_str();
		int l=token.length();

		if(!l)
			throw IllegalArgumentException(L"WString::PosOfToken null length token");

		int nPos=find(token);
		int nSkip=0; 

		while(nPos!=npos){
			if(!nPos||wcschr(pSep,at(nPos-1))){ // beginning of sequence or token separator is before the token
				if((nPos+l>=length())||wcschr(pSep,at(nPos+l))){
					// end of sequence or token separator is after the token
					if(nSkip++>=iSkip)
						break;
				}
			}
			// not found, continue searching
			nPos=find(token,nPos+l);
		}
		if(nPos==npos)
			return -1;

		// now search the index
		nSkip=0;
		int iPos=0;
		const JDFCh* pTok=token.c_str();

		wchar_t* buf=new wchar_t[size()+1];
		wcscpy (buf,c_str());

		// all wcstok calls must be in a critical section to avoid overwriting the global buffer
		tokenMutex->lock();
		// *!* Solaris also has the two-parameter version -af-
#if defined(_WIN32) || defined(__SUNPRO_CC)
		wchar_t* tok=wcstok(buf,pSep);
#else
		wchar_t *tok, *tok2;
		tok = wcstok(buf,pSep,&tok2);
#endif
		bool bFoundFirst=!wcscmp(tok,pTok);
		if(iSkip||!bFoundFirst){ // first token is not the one
			if(bFoundFirst)
				nSkip++;

			while(tok){
				iPos++;
				// *!* Solaris also has the two-parameter version -af-
#if defined(_WIN32) || defined(__SUNPRO_CC)
				tok=wcstok(0,pSep); // While there are tokens in buf,get next token
#else
				tok=wcstok(0,pSep,&tok2); // While there are tokens in buf,get next token
#endif
				if(!wcscmp(tok,pTok)) {// break on equal
					if(nSkip++>=iSkip)
						break;
				}
			}
		}
		tokenMutex->unlock();
		delete[](buf);
		return iPos;

	}

	///////////////////////////////////////////////////////////////////

	bool WString::HasToken(const WString & token, const WString & separator, int iSkip) const {
		int l=token.length();
		if(!l)
			throw IllegalArgumentException(L"WString::HasToken null length token");

		const JDFCh* pSep=separator.c_str();
		int nPos=find(token);
		int nSkip=0;

		while(nPos!=npos){
			if(!nPos||wcschr(pSep,at(nPos-1))){ // beginning of sequence or token separator is before the token
				if((nPos+l>=length())||wcschr(pSep,at(nPos+l))){// end of sequence or token separator is after the token
					if(nSkip++>=iSkip)
						break;
				}
			}
			// not found, continue searching
			nPos=find(token,nPos+l);
		}
		return (nPos!=npos);
	}

	///////////////////////////////////////////////////////////////////


	WString WString::Escape(const WString& toEscape,const WString& escapeChar, int radix, int escapeLen, int escapeBelow, int escapeAbove)const{
		WString escapedString;
		int l=size();
		const wchar_t* pc=c_str();
		for(int i=0;i<l;i++){
			JDFCh cToEscape = this->operator [](i);
			if ((cToEscape>escapeAbove)||(cToEscape<escapeBelow)||(toEscape.find(cToEscape)!=toEscape.npos)){ //||((*pc==escapeCh)&&(radix>0))){ // the character must be escaped
				escapedString+=escapeChar;
				if(radix>0){ // radix is a flag to convert to octal, hex etc.
					wchar_t buf[16];
#if defined(_WIN32)
					if(radix==8){
						swprintf(buf,L"%o",*pc);
					}else if(radix==10){
						swprintf(buf,L"%u",*pc);
					}else if(radix==16){
						swprintf(buf,L"%x",*pc);
					}else{
						throw IllegalArgumentException("WString::Escape radix out of range");
					}

#else
					char ansibuf[16];
					if(radix==8){
						sprintf(ansibuf,"%o",*pc);
					}else if(radix==10){
						sprintf(ansibuf,"%u",*pc);
					}else if(radix==16){
						sprintf(ansibuf,"%x",*pc);
					}else{
						throw IllegalArgumentException("WString::Escape radix out of range");
					}
					for ( int o = 0; o < 16; o++) *(buf+o) = (wchar_t)*(ansibuf+o);
#endif

					wcsupr(buf);  //capitalize hex stuff
					if(escapeLen){ // prepad zeroes to a total of escapeLen
						int lenBuf=wcslen(buf);
						if(lenBuf<escapeLen){ 
							escapedString.insert(escapedString.size(),escapeLen-lenBuf,L'0');
						}
					}
					escapedString+=buf;
				}else if(radix<0){
					// nop
				}else{ // radix=0; just insert the escape character in front of the actual char
					escapedString+=*pc;
				}
			}else{ // no escape necessary --> just copy it
				escapedString+=*pc;
			}
			pc++;
		}
		return escapedString;
	}
	///////////////////////////////////////////////////////////////////

	WString WString::UnEscape(wchar_t escapeChar, int radix, int escapeLen)const{
		int pos=find(escapeChar);
		WString escapedString;
		if(pos!=npos){
			int lastPos=0;

			while(pos!=npos){
				// copy the chars between the escaped characters
				escapedString.append(*this,lastPos,pos-lastPos);

				if(at(pos+1)==escapeChar){
					escapedString.append(escapeChar);
					lastPos=pos+2;
				}else{
					// convert the escaped char
					WString subst=substr(pos+1,escapeLen);
					int l=wcstol(subst.c_str(),0,radix);
					// 111202 RP fix corrupt escapes
					if(l==0){
						escapedString+=escapeChar;
						lastPos=pos+1;
					}else{
						escapedString+=((wchar_t)l);
						// find the next char to escape
						lastPos=pos+escapeLen+1;
					}
				}
				pos=find(escapeChar,lastPos);
			}
			if(lastPos<size()) 
				escapedString.append(substr(lastPos));

		}else{
			escapedString.assign(*this);
		}
		return escapedString;
	}

	///////////////////////////////////////////////////////////////////////////

	WString WString::UnEscape(const char escapeChar, int radix, int escapeLen)const{
		return UnEscape((wchar_t) escapeChar, radix, escapeLen);
	};

	///////////////////////////////////////////////////////////////////
	void WString::SetRawBytes(const char* buffer, int len){
		if(buffer){
			if(len<0)
				len=strlen(buffer);
			if(len>0){
				JDFCh* buf=new JDFCh[len+1];
				for(int i=0;i<len;i++){
					buf[i]=(const unsigned char)buffer[i];
				}
				buf[len]=0;
				assign(buf,len);
				delete[]buf;
			}else{
				assign(0,(JDFCh)0);
			}
		}else{
			assign(0,(JDFCh)0);
		}
	}

	///////////////////////////////////////////////////////////////////////

	void WString::SetHexBinaryBytes(const char* buffer, int len){
		if(buffer){
			if(len<0)
				len=strlen(buffer);
			if(len>0){
				JDFCh* buf=new JDFCh[len*2+1];
				for(int i=0;i<len;i++){
					JDFCh c=(buffer[i]&0xf0)>>4;
					// 260804 RP mea culpa. It must be >=10, not > 10...
					buf[2*i]   = (c>=10) ? 'A'-10+c : '0'+c;
					c=(buffer[i]&0xf);  
					// 260804 RP mea culpa. It must be >=10, not > 10...
					buf[2*i+1] = (c>=10) ? 'A'-10+c : '0'+c;
				}
				buf[len*2]=0;
				assign(buf,len*2);
				delete[]buf;
			}else{
				assign(0,(JDFCh)0);
			}
		}else{
			assign(0,(JDFCh)0);
		}
	}

	///////////////////////////////////////////////////////////////////////

	const char* WString::GetRawBytes(){
		if(pc)
			delete[]pc;
		int len=size();
		pc=new char[len+1];
		const JDFCh* pBuf=c_str();
		for(int i=0;i<len;i++){
			pc[i]=pBuf[i]&0xff;
		}
		pc[len]=0;
		return pc;
	}
	////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////

	const char* WString::GetHexBinaryBytes(){
		if(pc)
			delete[]pc;
		pc=0;
		int len=size();
		if(len%2)
			return 0;
		int len2=len/2;
		pc=new char[len2+1];
		const JDFCh* pBuf=c_str();
		for(int i=0;i<len2;i++){
			char c;
			int p=pBuf[i*2]&0xff;
			if(p>='0'&&p<='9'){
				c=p-'0';
			}else if (p>='A'&&p<='F'){
				c=10+p-'A';
			}else if (p>='a'&&p<='f'){
				c=10+p-'a';
			}else{
				return 0;
			}
			pc[i]=c<<4;
			p=pBuf[i*2+1]&0xff;
			if(p>='0'&&p<='9'){
				c=p-'0';
			}else if (p>='A'&&p<='F'){
				c=10+p-'A';
			}else if (p>='a'&&p<='f'){
				c=10+p-'a';
			}else{
				return 0;
			}
			pc[i]+=c;
		}
		pc[len2]=0;
		return pc;
	}
	///////////////////////////////////////////////////////////////////////
	WString WString::UniqueID(int ID){
		idMutex->lock();
		static int id=ID;
		if(ID) 
			id=ID; // reset dynamically!
		char buf[7];
		sprintf(buf,"%.6i",(id++)%100000);
		idMutex->unlock();
		return buf;
	}

	///////////////////////////////////////////////////////////////////////
	WString WString::GetUID(int len){
		char sFileID[256];
		if(len>255) 
			len=255;
		sFileID[len]=0;
		static bool first=true;
		if(first){
			first=false;
			srand((unsigned) time(NULL));
		}
		for (int i=0; i<len; i++) 
			sFileID[i] = rand() & 0xff;

		WString s(sFileID,len);
		return s;
	}

	void WString::SetUTF8String(const WString& buffer){
		WString b=buffer;
		SetUTF8Bytes(b.peekBytes());
	}
	////////////////////////////////////////////////////////////////////////
	/**
	* set this to the  bytes specified in buffer,and transcode itfrom UTF8
	* @param char* buffer the UTF-8 encoded buffer to assign to this
	* @param int len the length of the buffer. if<0, call strlen
	*/
	void WString::SetUTF8Bytes(const char* buffer, int len){
		if(len<0)
			len=strlen(buffer);


		JDFCh* wData=new JDFCh[len+1];
		JDFCh* tmpBuf=wData;

		XMLByte* charSizes=new XMLByte[len+1];

		const XMLByte*    srcPtr = (XMLByte*)buffer;
		const XMLByte*    endPtr = srcPtr + len;
		unsigned int    allOut=0;

		while (srcPtr < endPtr)
		{
			XMLSize_t   charsEaten;
			const unsigned int srcCount = endPtr - srcPtr;

			unsigned int outBytes;
			try
			{
			 outBytes = gUTF8Transcoder->transcodeFrom(srcPtr	, srcCount, tmpBuf, srcCount, charsEaten, charSizes );
			}
			catch (UTFDataFormatException x)
			{
				WString s(buffer,len);
				if(s.size()<len)
					throw IllegalArgumentException(WString(L"WString::SetUTF8Bytes illegal input chars: ")+buffer);
				assign(s);
				return;

			};

			// If we get any bytes out, then write them
			if (outBytes){
				tmpBuf+=outBytes;
			}

			// try default encoding, else throw an exception for illegal input streams
			if(!charsEaten)
			{
				WString s(buffer,len);
				if(s.size()<len)
					throw IllegalArgumentException(WString(L"WString::SetUTF8Bytes illegal input chars: ")+buffer);
				assign(s);
				return;
			}

			// And bump up our pointer
			srcPtr += charsEaten;
			allOut+=outBytes;
		}

		delete[]charSizes;
		*tmpBuf=0;
		assign(wData);
		delete[]wData;
		return;
	}

	////////////////////////////////////////////////////////////////////////
	/**
	* get the raw bytes specified in buffer, bypassing all except hex binary transcoders
	* any character values above 255 are truncated (c=c&0xff)
	* note that the char* is owned by the string and must not be deleted.
	* @return char* buffer the raw bytes assigned to this, 0 if an error occurrred
	*/
	const char* WString::GetUTF8Bytes()	{	
		int maxLenUTF8=1+length()*6;
		if(pc){
			delete[]pc;
		}
		pc=new char[maxLenUTF8];

		XMLByte* tmpBuf =(XMLByte*) pc;


		const JDFCh*    srcPtr = this->data();
		const JDFCh*    endPtr = srcPtr + length();
		unsigned int    allOut=0;

		while (srcPtr < endPtr)
		{
			XMLSize_t   charsEaten;
			const unsigned int srcCount = endPtr - srcPtr;			
			const unsigned int outBytes = gUTF8Transcoder->transcodeTo(srcPtr	, srcCount, tmpBuf, maxLenUTF8-allOut, charsEaten, XMLTranscoder::UnRep_RepChar);

			// If we get any bytes out, then write them
			if (outBytes){
				tmpBuf+=outBytes;
			}

			// throw an exception for illegal input streams
			if(!charsEaten)
				throw IllegalArgumentException(WString(L"WString::GetUTF8Bytes illegal input chars: ")+data());

			// And bump up our pointer
			srcPtr += charsEaten;
			allOut+=outBytes;
		}

		*tmpBuf=0;
		if(maxLenUTF8>333){
			// we made a very pessimistic assumption on size: clean up here 
			tmpBuf=(XMLByte*)pc;
			pc=new char[allOut+1];
			memcpy(pc,tmpBuf,allOut+1);
			delete[]tmpBuf;
		}
		return pc;
	}

	////////////////////////////////////////////////////////////////////////

	WString WString::GetUTF8String(){	
		const char* pUtf8=GetUTF8Bytes();
		WString s=pUtf8;
		return s;
	}
	////////////////////////////////////////////////////////////////////////


	bool WString::matches(const WString& regExp)const
	{
		WString _regExp = WString(regExp);
		// the null expression is assumed to match everything
		if (_regExp.empty())
			return true;
		// this is a really common mistake
		if (_regExp == WString::star)
			_regExp = WString::dot;
		bool b;
		try
		{
			RegularExpression exp(_regExp.c_str());
			b = exp.matches(c_str());
		}
		catch (...)
		{
			b = false;
		}
		return b;
	}



	////////////////////////////////////////////////////////////////////////

	JDFTOOLS_EXPORT WString operator+(const WString& str1, const WString& str2)
	{
		if(str1.empty()){
			return str2;
		}else if(str2.empty()){
			return str1;
		}else{
			WString str(str1); 
			str.append(str2); 
			return str;
		}
	}

	JDFTOOLS_EXPORT WString operator+(const WString& str1, const JDFCh* str2) 
	{
		if(str1.empty()){
			return WString(str2);
		}else if((str2==0)||(*str2==0)){
			return str1;
		}else{
			WString str(str1); 
			str.append(str2); 
			return str;
		}
	}

	JDFTOOLS_EXPORT WString operator+(const JDFCh* str1, const WString& str2) 
	{
		if((str1==0)||(*str1==0)){
			return str2;
		}else if(str2.empty()){
			return WString(str1);
		}else{
			WString str(str1); 
			str.append(str2); 
			return str;       
		}
	}

	JDFTOOLS_EXPORT WString operator+(const WString& str1, const char* str2) 
	{
		if(str1.empty()){
			return WString(str2);
		}else if((str2==0)||(*str2==0)){
			return str1;
		}else{
			WString str(str1); 
			str.append(str2); 
			return str;
		}
	}

	JDFTOOLS_EXPORT WString operator+(const WString& str1, char* str2) 
	{
		return operator+(str1, (const char*) str2);
	}

	JDFTOOLS_EXPORT WString operator+(const char* str1, const WString& str2) 
	{
		if((str1==0)||(*str1==0)){
			return str2;
		}else if(str2.empty()){
			return WString(str1);
		}else{
			WString str(str1); 
			str.append(str2); 
			return str;       
		}
	}

	JDFTOOLS_EXPORT WString operator+(const WString& str1, const char str2) 
	{
		WString str(str1); str.append(WString(str2)); return str;       
	}

	JDFTOOLS_EXPORT WString operator+(const char str1, const WString& str2) 
	{
		WString str(str1); str.append(str2); return str;       
	}

	JDFTOOLS_EXPORT WString operator+(const WString& str1, const JDFCh str2)
	{
		WString str(str1);str.append(1,str2);return str;       
	}

	JDFTOOLS_EXPORT WString operator+(const JDFCh str1, const WString& str2)
	{
		WString str(str1); str.append(str2); return str;       
	}

	JDFTOOLS_EXPORT WString operator+(const int i, const WString& str2) 
	{
		WString str=WString::valueOf(i); str.append(str2); return str;
	}
	JDFTOOLS_EXPORT WString operator+(const WString& str1, const int i)
	{
		WString str(str1); str.append(WString::valueOf(i)); return str;       
	}
	JDFTOOLS_EXPORT WString operator+(const double d, const WString& str2)
	{
		WString str=WString::valueOf(d); str.append(str2); return str;
	}
	JDFTOOLS_EXPORT WString operator+(const WString& str1, const double d) 
	{
		WString str(str1); str.append(WString::valueOf(d)); return str;       
	}
	// RN20060320
	////////////////////////////////////////////////////////////////////////
	// Implementation of WStringIterator
	////////////////////////////////////////////////////////////////////////

	WStringIterator::WStringIterator(){
		pWString=0;
		iPos=0;
	}

	////////////////////////////////////////////////////////////////////////
	WStringIterator::WStringIterator(const WStringIterator&other){
		iPos=other.iPos;
		pWString=other.pWString;
	}

	////////////////////////////////////////////////////////////////////////
	WStringIterator& WStringIterator::operator =(const WStringIterator&other){
		iPos=other.iPos;
		pWString=other.pWString;
		return *this;
	}

	////////////////////////////////////////////////////////////////////////
	WStringIterator::WStringIterator(void*p, int ipos){
		if(p){
			WStringBaseJDF* v=(WStringBaseJDF*)p;
			if(ipos<0)
				ipos=v->size(); // return end
			iPos=ipos;
			pWString=p;

		}else{
			pWString=0;
			iPos=0;
		}
	};
	////////////////////////////////////////////////////////////////////////

	WStringIterator::~WStringIterator(){
	};

	////////////////////////////////////////////////////////////////////////
	WStringIterator WStringIterator::operator +(int i)const{
		if(pWString==0) 
			throw (L"JDFException null WStringIterator");
		WStringIterator it=*this;
		it.iPos+=i;
		return it;
	}
	////////////////////////////////////////////////////////////////////////
	WStringIterator WStringIterator::operator ++(){
		if(pWString==0) 
			throw (L"JDFException null WStringIterator");
		iPos++;
		return *this;
	}
	////////////////////////////////////////////////////////////////////////
	WStringIterator WStringIterator::operator ++(int){
		if(pWString==0) 
			throw (L"JDFException null WStringIterator");
		iPos++;
		return *this;
	}
	////////////////////////////////////////////////////////////////////////

	const WStringIterator* WStringIterator::operator->() const{
		return (&*this); 
	}
	////////////////////////////////////////////////////////////////////////

	bool WStringIterator::operator!=(const WStringIterator & other) const{
		return (pWString!=other.pWString)||(iPos!=other.iPos);
	}
	////////////////////////////////////////////////////////////////////////

	bool WStringIterator::operator==(const WStringIterator & other) const{
		return (pWString==other.pWString)&&(iPos==other.iPos);
	}
	////////////////////////////////////////////////////////////////////////

	bool WStringIterator::operator>(const WStringIterator & other) const{
		bool result = (pWString==other.pWString);
		if (result)
			result = (iPos > other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////	

	bool WStringIterator::operator<(const WStringIterator & other) const{
		bool result = (pWString==other.pWString);
		if (result)
			result = (iPos<other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////

	bool WStringIterator::operator>=(const WStringIterator & other) const{
		bool result = (pWString==other.pWString);
		if (result)
			result = (iPos >= other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////	

	bool WStringIterator::operator<=(const WStringIterator & other) const{
		bool result = (pWString==other.pWString);
		if (result)
			result = (iPos<=other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////

	WString::reference WStringIterator::operator *(){
		return ((WStringBaseJDF*)pWString)->at(iPos);
	}
	///////////////////////////////////////////////////////////////////////

	WString::const_reference WStringIterator::operator *() const{
		return ((WStringBaseJDF*)pWString)->at(iPos);
	}
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////


} // namespace JDF


