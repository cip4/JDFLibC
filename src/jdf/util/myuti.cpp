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

/******************************************************************************
*                     Copyright 1998 Agfa-Gevaert N.V.                       *
*                           All rights reserved                              *
*                                                                            *
* The material contained herein may not be reproduced in whole or in part,   *
*        without the prior written consent of Agfa-Gevaert N.V.              *
*                                                                            *
******************************************************************************/

/******************************************************************************
*	Includes
******************************************************************************/ 
//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
//
// 161000 RP GetTmpFile added default to $TEMP env variable
//
///////////////////////////////////////////////////////////////////////////


#if defined(_WIN32)
#   include <io.h>
#   include <direct.h>
#elif defined(__MWERKS__)
#   include <stdio.h>
#   include <cctype>
#else
#  include <unistd.h>
#  include <sys/types.h>
#  include <sys/stat.h>
#endif

#include <stdlib.h>
#include <string>

#include <jdf/util/myuti.h>

#ifndef _WIN32
// we will need another flag, strupr,lwr exist on linux.
#   include <ctype.h>

#if !defined(towlower) && !defined(__MWERKS__)
int towlower(int c)
{
	return (((c&0xFFFFFF00) == 0) ? tolower((char)c) : c);
}
#endif
#if !defined(towupper) && !defined(__MWERKS__)
int towupper(int c)
{
	return (((c&0xFFFFFF00) == 0) ? toupper((char)c) : c);
}
#endif


//#include <wchar.h>

//#define _wcsicmp wcscasecmp
//template<class _TS_p>
//inline int swprintf(wchar_t* s,const wchar_t* format,_TS_p p){
//	char pc[1000];
//	int i=sprintf(pc,WString(format).a_str(),p);
//	WString ws(pc);
//	wcscpy(s,ws.c_str());
//	return i;
//}

#ifndef __APPLE_CC__
#if !defined(isspace) && !defined(__MWERKS__)
int isspace(int c)
{
	if ((c==0x09)||(c==0x0A)||(c==0x0B)||(c==0x0C)||(c==0x0D)||(c==0x20))
		return 1;
	return 0;
}
#endif
#endif

#if !(defined (__GNUC__) && (__GNUC__ >= 3))
#if !defined(wcscpy) && !defined(__MWERKS__)
wchar_t* wcscpy(wchar_t* dst, const wchar_t* src)
{
	const	wchar_t * p = src;
	wchar_t * q = dst;

	while (*q++ = *p++);

	return(dst);
}
#endif
#endif

#if !defined(wcschr) && !defined(__MWERKS__)
wchar_t* wcschr(const wchar_t *string, wchar_t check)
{
	while(*string)
	{        
		if(*string==check)
		{
			return (wchar_t*)string;
		}
		string++;
	}
	return NULL;
}
#endif

#if !(defined (__GNUC__) && (__GNUC__ >= 3))
#if !defined(wcsncpy) && !defined(__MWERKS__)
wchar_t* wcsncpy(wchar_t *dst, const wchar_t *src, size_t maxLen)
{
	int l=wcslen(src)+1;
	if(l>maxLen)
	{
		l=maxLen;
	}
	for (int i=0; i<l; i++)
	{
		*(dst+i)=*(src+i);
	}
	if(maxLen>0)
	{
		dst[maxLen-1]=0;
	}
	return dst;
}
#endif
#endif


#if !defined(wcstok) && !defined(__MWERKS__)
wchar_t* wcstok(wchar_t *str, const wchar_t *set, wchar_t **last)
{
	wchar_t 	*seek;
	wchar_t 	*token;
	wchar_t		c;

	if (!last) // error
	{
		return(NULL);
	}

	if (str) // first call
	{
		seek = (wchar_t *) str; // find first
	}
	else // subsequent call
	{
		if (*last)
		{
			seek = (wchar_t *) *last; // find next
		}
		else
		{
			return(NULL); // stop tokenize
		}
	}

	// strip leading seperators
	seek--;
	while (c = *++seek)
	{
		if (wcschr(set, c)==NULL)
			break;
	}

	// check for end
	if (!c)
	{
		// stop now
		token = NULL;
		*last = NULL;
	}
	else
	{
		// token found
		token = seek; 

		// seek to end of current token
		while (c = *++seek)
		{
			if (wcschr(set, c))
				break;
		}

		// check for end
		if (!c)
		{
			*last = NULL; // stop next time
		}
		else
		{
			*seek = L'\0'; // overwrite delimiter
			*last = seek+1;
		}
	}

	return(( wchar_t *) token);
}
#endif

#if !defined(wcstod) && !defined(__MWERKS__)
double wcstod(const wchar_t *nptr, wchar_t **endptr)
{
	double value;
	int l=wcslen(nptr)+1;
	char* buffer= new char[l];
	for(int i=0;i<l;i++)
		*(buffer+i)=(char)*(nptr+i);
	char*endPC=0;

	value=strtod(buffer,&endPC);
	if(endptr){
		int bufLen=endPC-buffer;
		*endptr=(wchar_t*)nptr + bufLen;
	}
	delete[]buffer;

	return value;
}
#endif


#if !defined(wcstol) && !defined(__MWERKS__)
long wcstol(const wchar_t *nptr, wchar_t** endptr, int base)
{
	long value;
	int l=wcslen(nptr)+1;
	char* buffer= new char[l];
	for(int i=0;i<l;i++)
		*(buffer+i)=(char)*(nptr+i);
	char*endPC=0;

	value=strtol(buffer,&endPC,base);
	if(endptr){
		int bufLen=endPC-buffer;
		*endptr=(wchar_t*)nptr + bufLen;
	}
	delete[]buffer;

	return value;
}
#endif

#ifndef __MWERKS__

static char* strupr(char *s){
	size_t sl=strlen(s);
	for (size_t i=0; i<sl;i++)
		s[i]=toupper(s[i]);
	return s;
}
///////////////////////////////////////////////////////////////////
static char* strlwr(char *s){
	for (size_t i=0; i<strlen(s);i++)
		s[i]=tolower(s[i]);
	return s;
}
///////////////////////////////////////////////////////////////////
#endif

#ifndef itoa

char *itoa( int value, char *s, int radix ){
	sprintf(s,"%d",value);
	return s;
}
#endif

///////////////////////////////////////////////////////////////////
#ifndef _itow
wchar_t* _itow( int value, wchar_t* buffer, int radix){

	char buf[32];
	if(radix==8){
		sprintf(buf,"%o",value);
	}else if(radix==10){
		sprintf(buf,"%d",value);
	}else if(radix==16){
		sprintf(buf,"%x",value);
	}else{
		throw 1;
	}
	for(unsigned int z=0; z <= strlen(buf); z++) *(buffer+z) = (wchar_t)*(buf+z);
	return buffer;
}
#endif

///////////////////////////////////////////////////////////////////
#ifndef _ltow
wchar_t* _ltow( long value, wchar_t* buffer, int radix){

	char buf[32];
	if(radix==8){
		sprintf(buf,"%lo",value);
	}else if(radix==10){
		sprintf(buf,"%ld",value);
	}else if(radix==16){
		sprintf(buf,"%lx",value);
	}else{
		throw 1;
	}
	for(unsigned int z=0; z <= strlen(buf); z++) *(buffer+z) = (wchar_t)*(buf+z);
	return buffer;
}
#endif

///////////////////////////////////////////////////////////////////
#ifndef _ultow
wchar_t* _ultow( unsigned long value, wchar_t* buffer, int radix){
	char buf[32];
	if(radix==8){
		sprintf(buf,"%lo",value);
	}else if(radix==10){
		sprintf(buf,"%lu",value);
	}else if(radix==16){
		sprintf(buf,"%lx",value);
	}else{
		throw 1;
	}
	for(unsigned int z=0; z <= strlen(buf); z++) *(buffer+z) = (wchar_t)*(buf+z);
	return buffer;
}
#endif

///////////////////////////////////////////////////////////////////
#ifndef _ui64tow
wchar_t* _ui64tow( unsigned long long value, wchar_t* buffer, int radix){
	char buf[32];
	if(radix==8){
		sprintf(buf,"%I64o",value);
	}else if(radix==10){
		sprintf(buf,"%I64u",value);
	}else if(radix==16){
		sprintf(buf,"%I64x",value);
	}else{
		throw 1;
	}
	for(unsigned int z=0; z <= strlen(buf); z++) *(buffer+z) = (wchar_t)*(buf+z);
	return buffer;
}
#endif

///////////////////////////////////////////////////////////////////
#ifndef _wcslwr
wchar_t* _wcslwr( wchar_t* buffer){
	size_t size = wcslen(buffer);
	wchar_t* t;
	for ( size_t i = 0; i < size; i++){
		t = (buffer+i);
		towlower(*t);
	}
	return buffer;
}
#endif


///////////////////////////////////////////////////////////////////
#ifndef _wcsupr
wchar_t* _wcsupr( wchar_t* buffer){
	size_t size = wcslen(buffer);
	wchar_t* t;
	for ( size_t i = 0; i < size; i++){
		t = (buffer+i);
		towupper(*t);
	}
	return buffer;
}
#endif

///////////////////////////////////////////////////////////////////
#ifndef _wcsicmp
int _wcsicmp(const wchar_t* str1, const wchar_t* str2){
	wchar_t c1, c2;
	while (1)
	{
		c1 = towlower(*str1++);
		c2 = towlower(*str2++);
		if (c1 < c2) return -1;
		if (c1 > c2) return 1;
		if (c1 == 0) return 0;
	}
}
#endif

///////////////////////////////////////////////////////////////////
#if !defined(wcslen) && !defined(__MWERKS__) && !(defined (__GNUC__) && (__GNUC__ >= 3))
size_t wcslen( const wchar_t* str){
	size_t i;
	for ( i = 0; *(str+i) != 0x00; i++ );
	return i;
}
#endif
#ifndef _i64tow
wchar_t* _i64tow( unsigned long long value, wchar_t* buffer, int radix){
	char buf[32];
	if(radix==8){
		sprintf(buf,"%I64o",value);
	}else if(radix==10){
		sprintf(buf,"%I64d",value);
	}else if(radix==16){
		sprintf(buf,"%I64x",value);
	}else{
		throw 1;
	}
	for(unsigned int z=0; z <= strlen(buf); z++) *(buffer+z) = (wchar_t)*(buf+z);
	return buffer;
}
#endif

///////////////////////////////////////////////////////////////////
//#ifndef _wotoi64
#ifndef _wtoi64
long long _wtoi64(const wchar_t* str){
	long long retVal;
	size_t s = wcslen(str);
	char* t = new char[s+1];
	for ( size_t z = 0; z <=s; z++) *(t+z)=(char)*(str+z);
	sscanf(t,"%I64d",&retVal);
	delete (t);
	return retVal;
}
#endif

#if !defined(_wtoi) && !defined(__MWERKS__)
int _wtoi(const wchar_t* str){
	int retVal;
	size_t s = wcslen(str);
	char* t = new char[s+1];
	for ( size_t z = 0; z <=s; z++) *(t+z)=(char)*(str+z);
	sscanf(t,"%d",&retVal);
	delete (t);
	return retVal;
}
#endif

///////////////////////////////////////////////////////////////////
#ifndef _atoi64
long long _atoi64(const char* str){
	long long retVal;
	sscanf(str,"%I64d",&retVal);
	return retVal;
}
#endif


///////////////////////////////////////////////////////////////////

#endif // for solaris

namespace JDF{

	///////////////////////////////////////////////////////////////////


}
///////////////////////////////////////////////////////////////////
