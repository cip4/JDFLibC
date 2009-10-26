#ifndef I_JDF_WSTRING_H
#define I_JDF_WSTRING_H

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
* 290502 RP removed inline from peekBytes(), ostream operator <<, vMapWString::index
* 051102 RP Token() gracefully handle index above limit of number of tokens
* 160103 RP getBytes() calculate the size of the returned string using the transcoder
* 160103 RP added IsTranscodable()
* 240103 RP added SetUTF8Bytes, GetUTF8Bytes()
* 100203 RP added SetUTF8String, GetUTF8String()
* 100203 RP peekBytes now returns a const char* instead of non-const char*
* 070403 RP added putBytes(...)
* 041202 RP remove STL from the interface and hide it in pBase
* 160103 RP getBytes() calculate the size of the returned string using the transcoder
* 160103 RP added IsTranscodable()
* 050503 TG find_first_(not_)of uses default 0 instead of npos
* 200503 RP added wostream << operator
* 211003 RP fixed toUpperCase and toLowerCase not to overwrite reference counted strings
* 211003 RP removed some of WStringBase and moved it here
* 301006 NB fixed Wstring::ZappTokenWS(), WString::regExp_datetime
* 020207 NB added regExp_hexbinary
* 020207 NB fixed WString::matches()
*
*
******************************************************************************/

/******************************************************************************
*	Includes
******************************************************************************/ 

#include "JDFToolsDefs.h"
#include <ostream>


namespace JDF
{
	/******************************************************************************
	*	Forward declarations
	******************************************************************************/ 
	//class ostream;
	class WStringBaseJDF;
	class vWString;
	class WStringIterator;                                            // RN20060320
	class PlatformUtils;

	/******************************************************************************
	*	Defines and constants
	******************************************************************************/ 

	/******************************************************************************
	*	Typedefs
	******************************************************************************/ 

	/******************************************************************************
	*	Classes
	******************************************************************************/ 

	/**
	* The WString class represents unicode character strings.
	* <p>
	* This class implements the STL string class with additional methods for comparing
	* string, searching strings, for extracting substrings and for creating a 
	* copy of a string with all characters translated to uppercase or to lowercase.<br>
	*
	* no STL strings are passes through the interface the STL is defined only in the implementation
	* @ingroup lang
	* @nosubgrouping
	*/

	class JDFTOOLS_EXPORT WString 
	{
	public:
		//@{
		/**
		* the empty string L""
		*/
		static const WString emptyStr;

		/**
		* the blank string L" "
		*/
		static const WString blank;

		/**
		* the star string L"*"
		*/
		static const WString star;

		/**
		* the tilde string L"~"
		*/
		static const WString tilde;

		/**
		* the comma string L","
		*/
		static const WString comma;

		/**
		* the dot string L"."
		*/
		static const WString dot;

		/**
		* the colon string L":"
		*/
		static const WString colon;

		/**
		* the question mark string L"?"
		*/
		static const WString question;

		/**
		* the whitespace string L" \n\t"
		*/
		static const WString whiteSpace;
		/**
		* the backSlash string L"\\"
		*/
		static const WString backSlash;
		/**
		* the quote string L"\""
		*/
		static const WString quote;
		/**
		* the quote string L"/"
		*/
		static const WString slash;
		/**
		* the utf-8 string L"UTF-8"
		*/
		static const WString utf8;
		/**
		* regular expression for ISO formatted JDFDuration strings
		*/
		static const WString regExp_duration;
		/**
		* regular expression for ISO formatted JDFDateTime strings
		*/
		static const WString regExp_datetime;

		/**
		* regular expression for hex strings
		*/
		static const WString regExp_hexbinary;
		//@}

	public:
		typedef  unsigned int size_type;
		static const int npos;
		typedef WStringIterator iterator;                              // RN20060320
		typedef const WStringIterator const_iterator;                  // RN20060320
		typedef JDFCh& reference;
		typedef const JDFCh& const_reference;
		/** 
		* @name Constructors
		*/
		/*@{*/

		/** 
		* Initializes a newly created WString object so that it represents
		* an empty character sequence.
		*/
		WString();

		/**
		* Allocates a new WString object so that it represents the single wide character.
		* @param c the wide character to represent
		*/
		WString(const JDFCh c);

		/**
		* Allocate a new WString object so that it contains characters from a
		* subarray of the character array argument. The <code>count</code> argument
		* specifies the length of the subarray.
		* The contents of the character array are copied.
		* @param str array that is the source of characters.
		* @param count the the length of the subarray
		*/
		WString(const JDFCh* str, size_type count);

		/**
		* Allocate a new WString object so that it represents the sequence of
		* characters currently contained in the character array argument.
		* The contents of the character array are copied.
		* @param str the initial value of the WString
		*/
		WString(const JDFCh* str);

		/** 
		* Initializes a newly created WString object so that it
		* represents the same sequence of characters as the argument; in other
		* words the newly created string is a copy of the argument string.
		* @param str a WString
		*/
		WString(const WString& str);

		/**
		* Constructs a new WString so that it contains characters from a
		* subarray of the character array argument. The <code>count</code> argument
		* specifies the length of the subarray starting at the specified offset.
		* The contents of the character array are copied.
		* @param str array that is the source of characters.
		* @param offset Index of the first character to copy.
		* @param count the length of the subarray
		*/
		WString(const WString& str, int offset, int count);

		/**
		* Allocate a new WString object that copies a given character
		* a number of times.
		* @param n the nubmer of times to copy the given character
		* @param c the character to copy
		*/	
		WString(size_type n, JDFCh c);

		/**
		* Allocates a new WString object so that it represents the 
		* single character. The character is converted using the system default
		* character encoding.
		* @param c the wide character to represent
		*/
		explicit WString(const char c);
		/**
		* Allocates a new WString object so that it represents the 
		* single character. The character is converted using the system default
		* character encoding.
		* @param c the wide character to represent
		*/
		explicit WString(const unsigned char c) ;

		/**
		* Constructs a new WString by converting the specified array
		* of bytes using the platform's default character encoding.
		* The length of the new WString is a function of the encoding,
		* and hence may not be equal to the length of the byte array.
		* @param str the array to convert
		*/
		WString(const char* str) ;

		/**
		* Constructs a new WString by converting the specified subarray
		* of bytes using the platform's default character encoding.
		* The <code>count</code> argument specifies the length of the subarray.
		* The length of the new WString is a function of the encoding,
		* and hence may not be equal to the length of the byte array.
		* @param str array that is the source of characters.
		* @param count the length of the subarray
		*/

		WString(const char* str, size_type count);
		/*@}*/ 
		/**
		* constructor from int
		*/
		WString(const int i);

		/**
		* constructor from unsigned int
		*/
		WString(const unsigned int i);

		/**
		* constructor from long int
		*/
		WString(const long int i);

		/**
		* constructor from int64
		*/
		WString(const JDFInt64 i);

		/**
		* constructor from unsigned int64
		*/
		WString(const JDFUInt64 i);

		/**
		* constructor from double
		*/
		WString(const double d);

		/**
		* string constructor from a vector of strings
		*/
		WString(const vWString &vS,const WString& sep=WString::blank,const WString& front=WString::emptyStr,const WString& back=WString::emptyStr);

		/**
		* destructor
		*/
		virtual ~WString();

		/**
		* Compares two strings lexicographically, ignoring case considerations.
		* The argument str is first converted converted using the platform's default character encoding. 
		* @param str the string to be compared
		*/ 
		int compareToIgnoreCase(const char* str) const;

		/**
		* Compares two strings lexicographically, ignoring case considerations.
		* @param str the string to be compared
		*/ 
		int compareToIgnoreCase(const JDFCh* str) const;

		/**
		* Compares two strings lexicographically, ignoring case considerations.
		* @param str the string to be compared
		*/ 
		int compareToIgnoreCase(const WString& str) const;

		/** 
		* Compares this string to another string, ignoring case considerations.
		* This WString is compared to a byte sequence. 
		* The byte sequence is first converted converted using the platform's default character encoding.
		* Two strings are considered equal ignoring case if they are of the same
		* length, and corresponding characters in the two string are equal ignoring
		* case.
		* @param str the byte sequence to compare this WString against.
		*/
		bool equalsIgnoreCase(const char* str) const;

		/** 
		* Compares this string to another string, ignoring case considerations.
		* Two strings are considered equal ignoring case if they are of the same
		* length, and corresponding characters in the two string are equal ignoring
		* case.
		* @param str the string to compare this WStringBase against.
		*/
		bool equalsIgnoreCase(const JDFCh* str) const ;		

		/** 
		* Compares this string to another string, ignoring case considerations.
		* Two strings are considered equal ignoring case if they are of the same
		* length, and corresponding characters in the two string are equal ignoring
		* case.
		* @param str the WStringBase to compare this WStringBase against.
		*/
		bool equalsIgnoreCase(const WString& str) const ;

		/** 
		* Compares this string to another string.
		* Two strings are considered equal if they are of the same
		* length, and corresponding characters in the two string are equal.
		* @param str the WStringBase to compare this WStringBase against.
		*/
		bool equals(const WString& str) const;

		/**
		* Converts this string into bytes according to the platform's 
		* default character encoding, storing the result into a new byte array.
		* The caller owns the (char *) string that is returned, and is responsible
		* for deleting it.
		* @return the resultant byte array
		*/
		char* getBytes() const;

		/**
		* returns true if the string can legally be transcoded without adding replacement chars ('?' on Windows)
		* @return bool true if this string may be completely transcoded
		* @since 050517 checks for added '?' rather than only the returned null string
		*/
		bool IsTranscodable() const;

		/**
		* Converts this string into bytes according to the platform's 
		* default character encoding, storing the result into a new byte array.
		* same as @see getBytes() but the WString owns the (char *) string
		* that is returned, and is responsible for deleting it.
		* @return the resultant byte array
		*/
		const char* peekBytes()const;

		/**
		* Converts this string into bytes according to the specified 
		* character encoding, st
		* default character encoding, storing the result into a new byte array.
		* same as @see getBytes(const WString& encoding) but the WString owns the (char *) string
		* that is returned, and is responsible for deleting it.
		* @return the resultant byte array
		*/
		const char* peekBytes(const WString& encoding)const;

		/**
		* Converts this string into bytes according to the specified 
		* character encoding, st
		* default character encoding, storing the result into a new byte array.
		* The caller owns the (char *) string that is returned, and is responsible
		* for deleting it.
		* @return the resultant byte array
		*/
		char* getBytes(const WString& encoding) const;

		/**
		* Converts all the characters in this String to lower case.
		* @return the string, converted to lowercase.
		*/
		WString toLowerCase() const;

		/**
		* Converts all the characters in this String to upper case.
		* @return the string, converted to uppercase.
		*/
		WString toUpperCase() const;

		/**
		* Removes white space from both ends of this string.
		* @return this string, with white space removed from the front and end.
		*/
		WString trim() const;

		/**
		* Removes white space from the front of this string.
		* @return this string, with white space removed from the front.
		*/
		WString trimLeft() const;

		/**
		* Removes white space from the end of this string.
		* @return this string, with white space removed from the end.
		*/
		WString trimRight() const;

		WString& operator=(const char* str);
		WString& operator=(const char str);
		WString& operator=(const unsigned char str);


		/**
		* std::string pass throughs
		*/
		//@{
		/**
		* replaces the sequence controlled by *this with the operand sequence, then returns *this.
		* @param
		* @return WString& *this: the newly assigned string
		*/
		WString& assign(const WString&str);
		WString& assign(const JDFCh* c);
		WString& assign(const JDFCh *s, size_type n);
		WString& assign(const WString& str,    size_type pos, size_type n);
		WString& assign(size_type n, JDFCh c);
		WString& assign(const_iterator first, const_iterator last);
		WString& assign(const char* pc ,size_type n);
		WString& assign(const char* pc);


		WString& append(const JDFCh *s);
		WString& append(const JDFCh *s, size_type n);
		WString& append(const WString& str,    size_type pos, size_type n);
		WString& append(const WString& str);
		WString& append(size_type n, JDFCh c);
		WString& append(size_type n, char c);
		WString& append(const char* pc ,size_type n);

		const JDFCh* c_str()const;
		const JDFCh* data()const;
		const size_type length()const;
		const_reference at(int i)const;
		const_reference charAt(int i)const;
		reference at(int i);
		reference charAt(int i);
		WString substr(size_type pos = 0, size_type n = npos) const;
		WString substring(int beginIndex, int endIndex) const;
		WString substring(int beginIndex) const;
		WString& erase(size_type p0 = 0, size_type n = npos);
		void resize(size_type n, JDFCh c = 0);
		size_type size() const;
		//@}

		/** 
		* Tests if this string starts with the specified byte sequence.
		* The byte sequence is first converted converted using the platform's default character encoding. 
		*
		* @param prefix the prefix
		*/
		bool startsWith(const WString &w) const;

		/** 
		* Tests if this string starts with the specified byte sequence.
		* The byte sequence is first converted converted using the platform's default character encoding. 
		*
		* @param prefix the prefix
		*/
		bool startsWith(const char* prefix)const;

		/** 
		* Tests if this string starts with thes pecified prefix beginning a specified index.
		*
		* @param prefix the prefix
		* @Param offset where to begin looking in the string
		*/
		bool startsWith(const WString& prefix, int offset)const;

		/**
		* Tests if this string starts with the byte sequence beginning a specified index.
		* The byte sequence is first converted converted using the platform's default character encoding. 
		*
		* @param prefix the prefix
		* @Param offset where to begin looking in the string
		*/
		bool startsWith(const char* prefix, int offset) const;

		/** 
		* Tests if this string starts with the specified prefix, ignoring case
		* @param prefix the prefix
		*/
		bool startsWithIgnoreCase(const WString& str)const;

		/** 
		* Tests if this string starts with the specified byte sequence, ignoring case
		* The byte sequence is first converted converted using the platform's default character encoding. 
		* @param prefix the prefix
		*/
		bool startsWithIgnoreCase(const char* str) const;




		bool endsWith(const WString &w) const;
		bool empty() const;
		WString leftStr (int n) const;
		WString leftstring (int n) const;
		WString rightStr (int n) const;
		WString rightstring (int n) const;
		int compare(const WString& str) const;
		int compare(size_type p0, size_type n0,   const WString& str);
		int compare(size_type p0, size_type n0,    const WString& str, size_type pos, size_type n);
		int compare(const JDFCh *s) const;
		int compare(size_type p0, size_type n0,    const JDFCh *s) const;
		int compare(size_type p0, size_type n0,    const JDFCh *s, size_type pos) const;

		size_type find(JDFCh c, size_type pos = 0) const;
		size_type find(const JDFCh *s, size_type pos = 0) const;
		size_type find(const JDFCh *s, size_type pos, size_type n) const;
		size_type find(const WString& str, size_type pos = 0) const;

		size_type rfind(JDFCh c, size_type pos = npos) const;
		size_type rfind(const JDFCh *s, size_type pos = npos) const;
		size_type rfind(const JDFCh *s, size_type pos, size_type n) const;
		size_type rfind(const WString& str, size_type pos = npos) const;

		WString& insert(size_type p0, const JDFCh *s);
		WString& insert(size_type p0, const JDFCh *s, size_type n);
		WString& insert(size_type p0,    const WString& str);
		WString& insert(size_type p0,    const WString& str, size_type pos, size_type n);
		WString& insert(size_type p0, size_type n, JDFCh c);
		iterator insert(iterator it, JDFCh c);
		void insert(iterator it, const_iterator first, const_iterator last);
		void insert(iterator it, size_type n, JDFCh c);

		WString& replace(size_type p0, size_type n0,    const JDFCh *s);
		WString& replace(size_type p0, size_type n0,    const JDFCh *s, size_type n);
		WString& replace(size_type p0, size_type n0,    const WString& str);
		WString& replace(size_type p0, size_type n0,    const WString& str, size_type pos, size_type n);
		WString& replace(size_type p0, size_type n0,    size_type n, JDFCh c);
		WString& replace(iterator first0, iterator last0,    const JDFCh *s);
		WString& replace(iterator first0, iterator last0,    const JDFCh *s, size_type n);
		WString& replace(iterator first0, iterator last0,    const WString& str);
		WString& replace(iterator first0, iterator last0,    size_type n, JDFCh c);
		WString& replace(iterator first0, iterator last0,    const_iterator first, const_iterator last);

		WString replaceChar(JDFCh oldChar, JDFCh newChar) const;
		bool regionMatches(int toffset, const WString& other, int ooffset, int len) const;
		bool regionMatches(bool ignoreCase, int toffset, const WString& other, int ooffset, int len) const;
		int indexOf(const WString&str,int fromIndex=0) const;
		/**
		* counts the number of ocurrences of str in this
		* Note that overlapping strings are counted multiple times, 
		* thus "ss" will occur 5 times in "ssssasss" 
		*
		* @param WString str the string st osearch
		* @returns int the number of occurrences of ste
		*/
		int numOccurrenceOf(const WString&str) const;
		/**
		* returns true if this matches the reugular expression defined in regeXp
		* @param String regExp the string that defines the regExp to match against
		*/
		bool matches(const WString& regExp)const;

		size_type find_last_of(JDFCh c, size_type pos = npos) const;
		size_type find_last_of(const JDFCh *s, size_type pos = npos) const;
		size_type find_last_of(const JDFCh *s, size_type pos, size_type n = npos) const;
		size_type find_last_of(const WString& str,    size_type pos = npos) const;

		size_type find_last_not_of(JDFCh c, size_type pos = npos) const;
		size_type find_last_not_of(const JDFCh *s, size_type pos = npos) const;
		size_type find_last_not_of(const JDFCh *s, size_type pos,  size_type n) const;
		size_type find_last_not_of(const WString& str,    size_type pos = npos) const;

		size_type find_first_of(JDFCh c, size_type pos = 0) const;
		size_type find_first_of(const JDFCh *s, size_type pos = 0) const;
		size_type find_first_of(const JDFCh *s, size_type pos, size_type n) const;
		size_type find_first_of(const WString& str,    size_type pos = 0) const;

		size_type find_first_not_of(JDFCh c, size_type pos = 0) const;
		size_type find_first_not_of(const JDFCh *s, size_type pos = 0) const;
		size_type find_first_not_of(const JDFCh *s, size_type pos,  size_type n) const;
		size_type find_first_not_of(const WString& str,    size_type pos = 0) const;

		inline WString& operator=(JDFCh c){assign(valueOf(c)); return *this;};
		inline WString& operator=(const JDFCh* data){assign(valueOf(data)); return *this;};
		inline WString& operator=(double d){assign(valueOf(d)); return *this;};
		inline WString& operator=(float f){assign(valueOf(f)); return *this;};
		inline WString& operator=(int i){assign(valueOf(i)); return *this;};
		inline WString& operator=(long l){assign(valueOf(l)); return *this;};
		inline WString& operator=(short s){assign(valueOf(s)); return *this;};
		inline WString& operator=(unsigned int i){assign(valueOf(i)); return *this;};
		inline WString& operator=(unsigned long l){assign(valueOf(l)); return *this;};
		inline WString& operator=(JDFUInt64 n){assign(valueOf(n)); return *this;};
		inline WString& operator=(JDFInt64 n){assign(valueOf(n)); return *this;};

		WString& operator=(const WString& w);
		bool operator==(const WString& w)const;
		bool operator!=(const WString& w)const;
		bool operator<(const WString& w)const;
		bool operator<=(const WString& w)const;
		bool operator>(const WString& w)const;
		bool operator>=(const WString& w)const;

		bool operator==(const JDFCh* pc)const;
		bool operator!=(const JDFCh* pc)const;
		bool operator<(const JDFCh* pc)const;
		bool operator<=(const JDFCh* pc)const;
		bool operator>(const JDFCh* pc)const;
		bool operator>=(const JDFCh* pc)const;

		const_reference operator[](size_type pos) const;
		reference operator[](size_type pos);

		static WString valueOf(JDFCh c);
		static WString valueOf(const char data);
		static WString valueOf(const char* data);
		static WString valueOf(const JDFCh* data);
		static WString valueOf(double d);
		static WString valueOf(float f);
		static WString valueOf(int i);
		static WString valueOf(long l);
		static WString valueOf(bool b);
		static WString valueOf(short s);
		static WString valueOf(unsigned int i);
		static WString valueOf(unsigned long l);
		static WString valueOf(JDFUInt64 n);
		static WString valueOf(JDFInt64 n);

		JDFTOOLS_EXPORT friend WString operator+(const WString& str1, const WString& str2);
		JDFTOOLS_EXPORT friend WString operator+(const WString& str1, const JDFCh* str2);
		JDFTOOLS_EXPORT friend WString operator+(const JDFCh* str1, const WString& str2);
		JDFTOOLS_EXPORT friend WString operator+(const WString& str1, const char* str2); 
		JDFTOOLS_EXPORT friend WString operator+(const WString& str1, char* str2); 
		JDFTOOLS_EXPORT friend WString operator+(const char* str1, const WString& str2);
		JDFTOOLS_EXPORT friend WString operator+(const WString& str1, const char str2); 
		JDFTOOLS_EXPORT friend WString operator+(const char str1, const WString& str2);
		JDFTOOLS_EXPORT friend WString operator+(const WString& str1, const JDFCh str2); 
		JDFTOOLS_EXPORT friend WString operator+(const JDFCh str1, const WString& str2); 
		JDFTOOLS_EXPORT friend WString operator+(const int i, const WString& str2); 
		JDFTOOLS_EXPORT friend WString operator+(const WString& str1, const int i); 
		JDFTOOLS_EXPORT friend WString operator+(const double d, const WString& str2); 
		JDFTOOLS_EXPORT friend WString operator+(const WString& str1, const double d); 

		/**
		* Append the sequence of character currently contained in the WStringBase
		* argument to this WStringBase
		* The contents of WStringBase are copied.
		* @param str the new value of the WString
		*/
		WString& operator+=(const WString& str);

		/**
		* Append a single byte to this WStringBase.
		* The byte is converted using the platform's defaultcharacter encoding.
		* @param c the single byte to append.
		*/
		WString& operator+=(const char c) ;

		/**
		* Append the sequence of bytes to this WStringBase.
		* The sequence of bytes are converted using the platform's default 
		* character encoding.
		* @param str array that is the source of characters.
		*/
		WString& operator+=(const char* str);

		/**
		* Append the sequence of bytes to this WStringBase.
		* The sequence of bytes are converted using the platform's default 
		* character encoding.
		* @param str array that is the source of characters.
		*/
		WString& operator+=(char* str);

		/**
		* Append a single character to this WStringBase.
		* @param c the single character to append.
		*/
		WString& operator+=(const JDFCh c) ;
		/**
		* Append a double to this WStringBase.
		* The byte is converted using the platform's defaultcharacter encoding.
		* @param d the double to append.
		*/
		WString& operator+=(const double d) { append(valueOf(d)); return *this;}
		/**
		* Append a float to this WStringBase.
		* The byte is converted using the platform's defaultcharacter encoding.
		* @param f the float to append.
		*/
		WString& operator+=(const float f) { append(valueOf(f)); return *this;}
		/**
		* Append an int to this WStringBase.
		* The byte is converted using the platform's defaultcharacter encoding.
		* @param i the int to append.
		*/
		WString& operator+=(const int i) { append(valueOf(i)); return *this;}
		/**
		* Append an unsigned int to this WStringBase.
		* The byte is converted using the platform's defaultcharacter encoding.
		* @param i the unsigned int to append.
		*/
		WString& operator+=(const unsigned int i) { append(valueOf(i)); return *this;}
		/**
		* Append a long to this WStringBase.
		* The byte is converted using the platform's defaultcharacter encoding.
		* @param l the long to append.
		*/
		WString& operator+=(const unsigned long l) { append(valueOf(l)); return *this;}
		/**
		* Append an unsigned long to this WStringBase.
		* The byte is converted using the platform's defaultcharacter encoding.
		* @param l the unsigned long to append.
		*/
		WString& operator+=(const long l) { append(valueOf(l)); return *this;}
		/**
		* Append an JDFInt64 to this WStringBase.
		* The byte is converted using the platform's defaultcharacter encoding.
		* @param n the JDFInt64 to append.
		*/
		WString& operator+=(const JDFInt64 n) { append(valueOf(n)); return *this;}
		/**
		* Append an JDFUInt64 to this WStringBase.
		* The byte is converted using the platform's defaultcharacter encoding.
		* @param l the JDFUInt64 to append.
		*/
		WString& operator+=(const JDFUInt64 n) { append(valueOf(n)); return *this;}

		///////////////////////////////////////////////////////////////////////////////////////////////////////
		// 300501 rp added from WString
		
		/**
		* returns a formatted integer, 
		* replaces string consts with according int const
		* @param i the integer to format
		* @return the formatted string that represents i
		* TBD handle exp format
        */
		static WString formatInteger(int i);

		/**
		* @return bool true if the string represents an integer number
		*/
		bool isInteger() const;
		/**
		* @return bool true if the string represents a number
		*/
		bool isNumber()  const;
		/**
		* @return bool true if the string represents a boolean
		*/
		bool isBoolean()  const;
		/**
		* @return bool true if the string represents an NMTOKEN
		* @since 011001
		*/
		bool isNMTOKEN() const;
		/**
		* @return bool true if the string represents an NMTOKENS
		* @since 011001
		*/
		bool isNMTOKENS() const;
		/**
		* @return conversion to double
		*/
		operator double() const;
		/**
		* @return conversion to JDFInt64
		*/
		operator JDFInt64() const;
		/**
		* @return conversion to JDFUInt64
		*/
		operator JDFUInt64() const;
		/**
		* @return conversion to integer
		*/
		operator int()  const ;
		/**
		* @return conversion to boolean
		* using isNumber for int is NOT a copy paste bug. (int) on doubles will return a truncated integer
		*/
		operator bool()  const ;

		/**
		* replace all whitespace as defined by token in a string by a single instance of whiteSpace as defined by whiteSpace
		* @param WString 
		*/
		WString ZappTokenWS(const WString& token);	

		/**
		* sets this string to the bytes defined in chars in the encoding defined in encoding
		* @param char* chars the byte array to set this to. 
		* @param int len the length of the input array in bytes. if not specified (-1) chars must be null terminated
		* @param WString encoding the encoding code page. If not specified, the default encoding is assumed
		*/
		void putBytes(const char* chars, int len=-1, const WString& encoding=emptyStr);

		/**
		* return a vector of individual tokens. The separator is excluded from the tokens. 
		* multiple consequtive separators are treeted as one (similar to whitespace handling)
		* @param WString separator set of token separators
		* @return vWString vector of individual tokens. 
		*/
		vWString Tokenize(const WString & separator=whiteSpace)const;

		/**
		* return an individual token
		* The separator is excluded from the tokens. 
		* multiple consequtive separators are treeted as one (similar to whitespace handling)
		* @param int i index of the token in the vector
		* @param WString separator set of token separators
		* @return WString an individual token. 
		*/
		WString Token(int i,const WString& separator=whiteSpace)const;

		/**
		* return true if the token is in this string
		* The separator is excluded from the tokens. 
		* multiple consequtive separators are treeted as one (similar to whitespace handling)
		* @param WString token the token to search
		* @param WString separator set of token separators
		* @param number of tokens to skip before accepting, if 0 take the first etc.
		* @return bool true if the token exists
		*/
		bool HasToken(const WString & token, const WString & separator=whiteSpace,int iSkip=0) const;

		/**
		* returns the position of the token if it is in this string
		* The separator is excluded from the tokens. 
		* multiple consequtive separators are treeted as one (similar to whitespace handling)
		* @param WString token the token to search
		* @param WString separator set of token separators
		* @param number of tokens to skip before accepting, if 0 take the first etc.
		* @return int 0 based position if the token exists, else -1
		*/
		int PosOfToken(const WString & token, const WString & separator=whiteSpace, int iSkip=0) const;

		/**
		* create a string from a vector of tokens
		* @param vWString v vector of tokens
		* @param WString sep separator between tokens
		* @param WString front prefix to string (before the first token)
		* @param WString end suffix to string (after the last token)
		* @return condensed string of tokens separated by sep
		*/
		WString SetvString(const vWString& v, const WString& sep=WString::blank, const WString & front=WString::emptyStr , const WString &end=WString::emptyStr);

		/**
		* unescape a string radix the radix of the numerical representation; escapelen the number of digits / escaped char
		* does not assign itself
		* @param wchar_t escapeChar the character that marks an escape sequence
		* @param int radix the numerical representation base of the escaped chars, e.g. 8 for octal, 16 for hex
		* if radix==0 the escape chare is merely removed
		* valid radix: 0,8,10,16
		* @param escapeLen the number of digits per escaped char, not including escapeChar
		* @return the string where all escaped sequences have been replaced by their original representation
		*
		* @since 010704 Duplicated escape chars will be reduced to a single escape char
		*/
		WString UnEscape(const wchar_t escapeChar, int radix, int escapeLen)const;

		/**
		* unescape a string radix the radix of the numerical representation; escapelen the number of digits / escaped char
		* does not assign itself
		* @param char escapeChar the character that marks an escape sequence
		* @param int radix the numerical representation base of the escaped chars, e.g. 8 for octal, 16 for hex
		* if radix==0 the escape chare is merely removed
		* valid radix: 0,8,10,16
		* @param escapeLen the number of digits per escaped char, not including escapeChar
		* @return the string where all escaped sequences have been replaced by their original representation
		*
		* @since 010704 Duplicated escape chars will be reduced to a single escape char
		*/
		WString UnEscape(const char escapeChar, int radix, int escapeLen)const;

		/**
		* escape a string by prepending escapeChar and a numerical representation of the string
		* characters to be escaped are defined by toEscape, escapeBelow and escapeAbove
		* @param WString& toEscape the set of characters that should be escaped
		* @param WString& escapeChar the character sequence that marks an escape sequence
		* @param int radix the numerical representation base of the escaped chars, e.g. 8 for octal, 16 for hex
		* if radix==0 the escape chare is merely inserted
		* valid radix: 0,8,10,16
		* @param escapeLen the number of digits per escaped char, not including escapeChar
		* @param int escapeBelow all characters with an encoding below escapeBelow should also be escaped
		* @param int escapeAbove all characters with an encoding above escapeAbove should also be escaped
		* @return the string where all illegal sequences have been replaced by their escaped representation
		*
		* @since 010704 If the escape char itself is not in the escape range, it will be duplicated
		*/
		WString Escape(const WString& toEscape, const WString& escapeChar=backSlash, int radix=0, int escapeLen=0, int escapeBelow=0, int escapeAbove=256)const;

		/**
		* set this to the raw bytes specified in buffer, bypassing all transcoders
		* @param char* buffer the buffer to assign to this
		* @param int len the length of the buffer. if<0, call strlen
		*/
		void SetRawBytes(const char* buffer, int len=-1);

		/**
		* get the raw bytes specified in buffer, bypassing all transcoders
		* any character values above 255 are truncated (c=c&0xff)
		* note that the char* is owned by the string and must not be deleted.
		* @return char* buffer the raw bytes assigned to this
		*/
		const char* GetRawBytes();

		/**
		* set this to the  bytes specified in buffer,and transcode it to hexBinary
		* @param char* buffer the hex binary encoded buffer to assign to this
		* @param int len the length of the buffer. if<0, call strlen
		*/
		void SetHexBinaryBytes(const char* buffer, int len=-1);

		/**
		* get the raw bytes specified as hex binary in buffer, bypassing all except hex binary transcoders
		* any character values above 255 are truncated (c=c&0xff)
		* note that the char* is owned by the string and must not be deleted.
		* @return char* buffer the raw bytes assigned to this, 0 if an error occurrred
		*/
		const char* GetHexBinaryBytes();

		/**
		* return a unique ID - note this is not really threadsafe since an internal static member gets incremented
		* @param int ID the minimum value for an ID
		* @return a string representing an ID
		*/
		static WString UniqueID(int ID=0);

		/**
		* return a unique ID - note this is not really threadsafe since an internal static member gets incremented
		* @param int len the length of the returned UID
		* @return a string representing an ID
		*/
		static WString GetUID(int len=16);

		/**
		* Checks whether a character is within [a-zA-Z].
		* @param theChar the character to check
		* @return Returns true if within the range, otherwise false
		*/

		static bool isAlpha(JDFCh const ch);

		/**
		* Checks whether a character is within [0-9a-zA-Z].
		* @param theChar the character to check
		* @return Returns true if within the range, otherwise false
		*/
		static bool isAlphaNum(JDFCh const ch);

		/**
		* Checks whether a character is within [0-9].
		* @param theChar the character to check
		* @return Returns true if within the range, otherwise false
		*/
		static bool isDigit(JDFCh const ch);

		/**
		* Checks whether a character is within [0-9a-fA-F].
		* @param theChar the character to check
		* @return Returns true if within the range, otherwise false
		*/
		static bool isHex(JDFCh const theChar);

		//@{
		/**
		* the positive INF string "INF"
		*/
		static const WString pINFstr;

		/**
		* the negative INF string "-INF"
		*/
		static const WString nINFstr;

		/**
		* the positive INF value 0x7FEDCBAA / INT_MAX in Win32 builds
		*/
		static const long int pINF;

		/**
		* the negative INF value 0x80123456 / INT_MIN in Win32 builds
		*/
		static const long int nINF;

		/**
		* the positive double INF string "DINF"
		*/
		static const WString pDINFstr;

		/**
		* the negative double INF string "-DINF"
		*/
		static const WString nDINFstr;

		/**
		* the positive double INF value 0x7fefffffffffffffL / DBL_MAX in Win32 builds
		*/
		static const double pDINF;

		/**
		* the negative double INF value 0x8010000000000002L / -DBL_MAX in Win32 builds
		*/
		static const double nDINF;



		//@{
		/**
		* set this to the  bytes specified in buffer,and transcode the buffer from UTF8
		* @param char* buffer the UTF-8 encoded buffer to assign to this
		* @param int len the length of the buffer. if<0, call strlen
		* @throws IllegalArgumentException
		*/
		void SetUTF8Bytes(const char* buffer, int len=-1);

		/**
		* set this to the string specified in buffer,and transcode the buffer from UTF8
		* @param WString buffer the unicode representation of the UTF-8 encoded buffer to assign to this
		* @throws IllegalArgumentException
		*/
		void SetUTF8String(const WString& buffer);

		/**
		* get the UTF8 representation of the internal buffer
		* note that the returned char* is owned by the string and must not be deleted.
		*
		* @return char* buffer the raw bytes assigned to this, 0 if an error occurrred
		* @throws IllegalArgumentException
		*/
		const char* GetUTF8Bytes();

		/**
		* get the unicode string representing the UTF8 representation of the internal buffer
		*
		* @return WString buffer the string representation of the raw bytes assigned to this, 0 if an error occurrred
		* @throws IllegalArgumentException
		*/
		WString GetUTF8String();
		//@}


	private:

		static void initString(void* transcoder);
		/**
		* remove the private handler of reused WStringBase pointers
		* must be called by PlatformUtils::Terminate
		*/
		static void ClearBaseDump();
		static void terminate();
		// pointer to the char* returned by peekBytes()
		char*           pc;
		WStringBaseJDF* pBase;

		/**
		*   the following is used by the ms ide - in order to view wstring, please add the following line to
		*   C:\MSTools\Program Files\Visual Studio\Common\MSDev98\Bin ( or wherever your IDE is installed )
		*	JDF::WString=<pc_data,su>
		*/
		const wchar_t*pc_data;

		friend class PlatformUtils;
	};

	/**
	* stream to char ostream operator
	* @param std::ostream&s the ostream
	* @param WString&t the string to stream
	* @return ostream& the char stream
	*/
	JDFTOOLS_EXPORT std::ostream& operator<<(std::ostream&s,const WString&t); 

	/**
	* stream to wide char wostream operator
	* @param std::wostream&s the wostream
	* @param WString&t the string to stream
	* @return wostream& the wide char stream
	*/
	JDFTOOLS_EXPORT std::wostream& operator<<(std::wostream&s,const WString&t); 


	/******************************************************************************
	*	Prototypes
	******************************************************************************/ 


	/******************************************************************************
	*	Implementation
	******************************************************************************/
	// RN20060320
	/**
	* the iterator implements a subset of STL::string::iterator with the notable differences:
	*/
	class JDFTOOLS_EXPORT WStringIterator{
		friend class WString;
	public:
		/**
		* constructor
		*/
		WStringIterator();

		/**
		* do not use, this constructo is actually private but must be declared public due to name mangling problems

		*/
		WStringIterator(void*p, int ipos);

		/**
		* copy constructor
		*/
		WStringIterator(const WStringIterator & other);

		/**
		* dtor
		*/
		virtual ~WStringIterator();

		/**
		* copy constructor

		*/
		WStringIterator& operator =(const WStringIterator & other);

		/**
		* reference operator to simplify translation of ->first, ->second to  ->first(), ->second()
		*/
		const WStringIterator* operator->()const;

		/**
		* operator +
		* @param int i - int value to add
		* @return vintIterator - the sum of 'this' + 'i'
		*/
		WStringIterator operator +(int i)const;

		/**
		* iteration for loops
		*/
		WStringIterator operator++();

		/**
		* iteration for loops
		*/
		WStringIterator operator++(int);

		/**
		* inequivalence for loops
		* @return bool
		*/
		bool operator!=(const WStringIterator & other) const;

		/**
		* equivalence for loops
		* @return bool
		*/
		bool operator==(const WStringIterator & other) const;

		/**
		* inequivalence for loops
		* @return bool
		*/
		bool operator>=(const WStringIterator & other) const;

		/**
		* equivalence for loops
		* @return bool
		*/
		bool operator<=(const WStringIterator & other) const;

		/**
		* inequivalence for loops
		* @return bool
		*/
		bool operator>(const WStringIterator & other) const;

		/**
		* equivalence for loops
		* @return bool
		*/
		bool operator<(const WStringIterator & other) const;


		WString::reference operator *();

		WString::const_reference operator *() const;

	private:
		void *pWString;
		int iPos;
	};
} // namespace JDF

#endif /* I_JDF_WSTRING_H */

