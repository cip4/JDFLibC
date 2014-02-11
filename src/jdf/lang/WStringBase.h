/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2013 The International Cooperation for the Integration of 
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
*   
* 300802 RP WStringBase: added a virtual destructor and inlined trivial constructors
* 211003 RP removed some of WStringBase and moved it WString
*                                                                         
******************************************************************************/


/*******************************************************************************
* 
* Description:
*
*
******************************************************************************/

#ifndef I_JDF_WSTRINGBASE_H
#define I_JDF_WSTRINGBASE_H

/******************************************************************************
*	Includes
******************************************************************************/ 

#include "JDFToolsDefs.h"

#include <string>

#ifdef __MWERKS__
	#include <ctype.h>
#endif

namespace JDF
{
	
/******************************************************************************
*	Forward declarations
	******************************************************************************/ 
	
	
	/******************************************************************************
	*	Defines and constants
	******************************************************************************/ 
	template <class _TS_E, class _TS_Tr, class _TS_A>
		inline void _trim(std::basic_string<_TS_E, _TS_Tr, _TS_A>& _TS_S)
    {
        typename std::basic_string<_TS_E, _TS_Tr, _TS_A>::size_type posBeg = 0;
        typename std::basic_string<_TS_E, _TS_Tr, _TS_A>::size_type posEnd = _TS_S.length();
		
        while ((posBeg < posEnd) && iswspace(_TS_S.at(posBeg)))
			posBeg++;
		
        while ((posEnd > posBeg) && iswspace(_TS_S.at(posEnd - 1)))
            posEnd--;
		
        if (posBeg < posEnd)
            _TS_S.assign(_TS_S.substr(posBeg, posEnd - posBeg));
        else
            _TS_S.erase();
    }
	
	
	// _trimLeft
	template <class _TS_E, class _TS_Tr, class _TS_A>
		inline void _trimLeft(std::basic_string<_TS_E, _TS_Tr, _TS_A>& _TS_S)
    {
        typename std::basic_string<_TS_E, _TS_Tr, _TS_A>::size_type posBeg = 0;
        typename std::basic_string<_TS_E, _TS_Tr, _TS_A>::size_type posEnd = _TS_S.length();
        while ((posBeg < posEnd) && iswspace(_TS_S.at(posBeg)))
			posBeg++;
        _TS_S.assign(_TS_S.substr(posBeg));
    }
	
	// _trimRight
	template <class _TS_E, class _TS_Tr, class _TS_A>
		inline void _trimRight(std::basic_string<_TS_E, _TS_Tr, _TS_A>& _TS_S)
    {
        typename std::basic_string<_TS_E, _TS_Tr, _TS_A>::size_type posEnd = _TS_S.length();
        while ((posEnd > 0) && iswspace(_TS_S.at(posEnd - 1)))
            posEnd--;
        _TS_S.resize(posEnd);
    }
	
	/******************************************************************************
	*	Typedefs
	******************************************************************************/ 
	
	
	/******************************************************************************
	*	Classes
	******************************************************************************/ 
	
	template <class T>
		class JDFTOOLS_EXPORT WStringBase : public std::basic_string<T>
	{
		typedef std::basic_string<T> _BT;


public:
		typedef  typename std::basic_string<T>::size_type size_type;

		
		/** 
* @name Constructors
	*/
	/*@{*/
	
	/** 
	* Initializes a newly created WStringBase object so that it represents
	* an empty character sequence.
	*/
	inline WStringBase(){}
	
	/** 
	* standard virtual dtor
	*/
	virtual ~WStringBase(){}

	/**
	* Allocates a new WStringBase object so that it represents the single wide character.
	* @param c the wide character to represent
	*/
	inline WStringBase(const T c)  : _BT (1,c)		  		 {}
	
	/**
	* Allocate a new WStringBase object so that it contains characters from a
	* subarray of the character array argument. The <code>count</code> argument
	* specifies the length of the subarray.
	* The contents of the character array are copied.
	* @param str array that is the source of characters.
	* @param count the the length of the subarray
	*/
	inline WStringBase(const T* str, size_type count) : _BT() {
		if((str!=0L)&&(count>0)){
			assign(str,count);
		}
	}
	
	/**
	* Allocate a new WStringBase object so that it represents the sequence of
	* characters currently contained in the character array argument.
	* The contents of the character array are copied.
	* @param str the initial value of the WStringBase
	*/
	inline WStringBase(const T* str) : _BT(str)                {}
	
	/** 
	* Initializes a newly created WStringBase object so that it
	* represents the same sequence of characters as the argument; in other
	* words the newly created string is a copy of the argument string.
	* @param str a WStringBase
	*/
	inline WStringBase(const WStringBase<T>& str) : _BT(str)           {}
	
	/**
	* Constructs a new WStringBase so that it contains characters from a
	* subarray of the character array argument. The <code>count</code> argument
	* specifies the length of the subarray starting at the specified offset.
	* The contents of the character array are copied.
	* @param str array that is the source of characters.
	* @param offset Index of the first character to copy.
	* @param count the length of the subarray
	*/
	inline WStringBase(const WStringBase<T>& str, int offset, int count) : _BT(str,offset,count) {}
	
	/**
	* Allocate a new WStringBase object that copies a given character
	* a number of times.
	* @param n the number of times to copy the given character
	* @param c the character to copy
	*/	
	inline WStringBase(size_type n, T c) : _BT(n, c) {}
	
	
	/**
	* Allocates a new WString object so that it represents the 
	* single character. The character is converted using the system default
	* character encoding.
	* @param c the wide character to represent
	*/
	explicit WStringBase(const char c) { 
		*this = c; 
	}
	
	
	/**
	* Constructs a new WStringBase by converting the specified stl string
	* using the platform's default character encoding.
	* The length of the new WStringBase is a function of the encoding,
	* and hence may not be equal to the length of the byte array.
	* @param str the stl string to convert
	*/
	inline WStringBase(const std::string& str) { 
		*this = str; 
	}
	
	inline WStringBase(const std::basic_string<T>& str) : _BT(str) {}
	/**
	* Constructs a new WStringBase by converting the specified subarray
	* of bytes using the platform's default character encoding.
	* The <code>count</code> argument specifies the length of the subarray.
	* The length of the new WStringBase is a function of the encoding,
	* and hence may not be equal to the length of the byte array.
	* @param str array that is the source of characters.
	* @param count the length of the subarray
	*/
	inline WStringBase(const char* str, size_type count) { 
		*this = std::string(str,count); 
	}
	
	/*@}*/ 
	
	/**
	* Assign a single character to this WStringBase.
	* The single character is converted using the platform's default character
	* encoding.
	* @param c the byte character 
	*/
	WStringBase<T>& operator=(const char c);
	
	
	/**
	* Assign a single wide character to this WString.
	* @param c the wide character 
	*/
	WStringBase<T>& operator=(const T c) { 
		_BT::assign(1,c); 
		return *this; 
	}
	
	/**
	* Assign the sequence of character currently contained in the character
	* array argument to this WStringBase
	* The contents of the character array are copied.
	* @param str the new value of the WString
	*/
	WStringBase<T>& operator=(const T* str) { 
		_BT::assign((str) ? str : L""); 
		return *this; 
	}
	
	/**
	* Assign the specified array of bytes specified by the stl string
	* to this WStringBase. 
	* The array is converted using the platform's default character encoding.
	* The length of the new WStringBase is a function of the encoding,
	* and hence may not be equal to the length of the byte array.
	* @param str array that is the source of characters.
	*/
	WStringBase<T>& operator=(const std::string& str);
	
	/**
	* Assign the sequence of character currently contained in the STL wide string
	* argument to this WStringBase
	* The contents of WStringBase are copied.
	* @param str the new value of the WStringBase
	*/
	WStringBase<T>& operator=(const WStringBase<T>& str) { 
		_BT::assign(str); 
		return *this; 
	}
	
	/**
	* Append the sequence of bytes specified by the stl string to this
	* WStringBase.
	* The sequence of bytes are converted using the platform's default 
	* character encoding.
	* @param str array that is the source of characters.
	*/
	
	WStringBase<T>& operator+=(const std::string& str) { 
		WStringBase<T> s(str); append(s); 
		return *this;
	}
	
	/**
	* Append the sequence of character currently contained in the WStringBase
	* argument to this WStringBase
	* The contents of WStringBase are copied.
	* @param str the new value of the WString
	*/
	WStringBase<T>& operator+=(const WStringBase<T>& str) { 
		append(str); 
		return *this;
	}

	/**
	* Append a single byte to this WStringBase.
	* The byte is converted using the platform's defaultcharacter encoding.
	* @param c the single byte to append.
	*/
	WStringBase<T>& operator+=(const char c) { 
		WStringBase<T> s(c); 
		append(s); 
		return *this;
	}
	
	/**
	* Append the sequence of bytes to this WStringBase.
	* The sequence of bytes are converted using the platform's default 
	* character encoding.
	* @param str array that is the source of characters.
	*/
	WStringBase<T>& operator+=(const char* str) { 
		WStringBase<T> s(str); 
		append(s); 
		return *this;}
	
	/**
	* Append a single character to this WStringBase.
	* @param c the single character to append.
	*/
	WStringBase<T>& operator+=(const T c) { 
		append(1,c); 
		return *this;
	}
	
	/**
	* Return a modifiable reference to the character at the specified index.
	* @param nIdx index position of the character
	* @return a reference to the character at the specified index.
	*/
	T& operator[](int nIdx) { 
		return _BT::operator[](nIdx);
	}
	
	/**
	* Return a non-modifiable reference to the character at the specified index.
	* @param nIdx index position of the character
	* @return a const reference to the character at the specified index.
	*/
	const T& operator[](int nIdx) const { 
		return _BT::operator[](nIdx); 
	}
	
	/**
	* Return a modifiable reference to the character at the specified index.
	* This method has been added to resolve compiler warning with signed/unsigned
	* indices.
	* @param nIdx index position of the character
	* @return a reference to the character at the specified index.
	*/
	T& operator[](unsigned int nIdx) { 
		return _BT::operator[](nIdx); 
	}
	
	/**
	* Return a non-modifiable reference to the character at the specified index.
	* This method has been added to resolve compiler warning with signed/unsigned
	* indices.
	* @param nIdx index position of the character
	* @return a const reference to the character at the specified index.
	*/
	const T& operator[](unsigned int nIdx) const { 
		return _BT::operator[](nIdx); 
	}
	
	/**
	* Test operator to test if a string is invalid (empty)
	*/
	bool operator!() const { 
		return this->empty(); 
	}
	
	/**
	* Compares two string lexicographically with the sequence of bytes specified
	* by the str argument.
	* The comparison is based on the Unicode value of each character in the strings.
	* The character sequence represented by this WStringBase object is compared 
	* lexicographically to the byte sequence represented by the argument string.
	* The byte sequence is first converted using the platform's default character encoding. 
	* The result is a positive integer if this WStringBase object lexicographically follows
	* the argument string. The result is zero if the strings are equal; <code>compareTo</code>
	* returns <code>0</code> exactly when the equality operator would return <code>true</code>.
	* <p>
	* This is the definition for lexicographic ordering. If two strings are different,
	* then either the have different characters at some index that is a valid index for both
	* strings, or their lengths are different, or both. 
	* @param str string to compare to
	* @return 0 if the argument string is equal to this string, a value less than 0 if this string
	* is lexicographically less than the string argument; and a value greater than 0 if this
	* string is lexicographically greater than the string argument.
	*/ 
	int compareTo(const char* str) const { 
		return _BT::compare(WStringBase<T>(str));
	}
	
	/**
	* Compares two string lexicographically
	* The comparison is based on the Unicode value of each character in the strings.
	* The character sequence represented by this WStringBase object is compared 
	* lexicographically to the character sequence represented by the argument string.
	* The result is a positive integer if this WStringBase object lexicographically follows
	* the argument string. The result is zero if the strings are equal; <code>compareTo</code>
	* returns <code>0</code> exactly when the equality operator would return <code>true</code>.
	* <p>
	* This is the definition for lexicographic ordering. If two strings are different,
	* then either the have different characters at some index that is a valid index for both
	* strings, or their lengths are different, or both. 
	* @param str string to compare to
	* @return 0 if the argument string is equal to this string, a value less than 0 if this string
	* is lexicographically less than the string argument; and a value greater than 0 if this
	* string is lexicographically greater than the string argument.
	*/ 
	int compareTo(const T* str) const { 
		return _BT::compare(str); 
	}

	/**
	* Compares two string lexicographically with the sequence of characters specified
	* by the str argument.
	* The comparison is based on the Unicode value of each character in the strings.
	* The character sequence represented by this WStringBase object is compared 
	* lexicographically to the character sequence represented by the argument string.
	* The result is a positive integer if this WStringBase object lexicographically follows
	* the argument string. The result is zero if the strings are equal; <code>compareTo</code>
	* returns <code>0</code> exactly when the equality operator would return <code>true</code>.
	* <p>
	* This is the definition for lexicographic ordering. If two strings are different,
	* then either the have different characters at some index that is a valid index for both
	* strings, or their lengths are different, or both. 
	* @param str string to compare to
	* @return 0 if the argument string is equal to this string, a value less than 0 if this string
	* is lexicographically less than the string argument; and a value greater than 0 if this
	* string is lexicographically greater than the string argument.
	*/ 
	int compareTo(const WStringBase<T>& str) const { 
		return _BT::compare(str); 
	}
	
	/**
	* Compares two strings lexicographically.
	* The comparison is based on the Unicode value of each character in the strings.
	* A subset of the character sequence represented by this WStringBase object
	* is compared lexicographically to the byte sequence represented by the argument
	* string.The byte sequence is first converted using the platform's default character encoding. 
	* The subset starts at position index, The length of the subset is defined
	* by the count argument.
	* The result is a positive integer if this WStringBase object lexicographically follows
	* the argument string. The result is zero if the strings are equal; <code>compareTo</code>
	* returns <code>0</code> exactly when the equality operator would return <code>true</code>.
	* <p>
	* This is the definition for lexicographic ordering. If two strings are different,
	* then either the have different characters at some index that is a valid index for both
	* strings, or their lengths are different, or both. 
	* @param str string to compare to
	* @return 0 if the argument string is equal to this string, a value less than 0 if this string
	* is lexicographically less than the string argument; and a value greater than 0 if this
	* string is lexicographically greater than the string argument.
	*/ 
	int compareTo(size_type index, size_type count, const char* str) const { 
		return _BT::compare(index,count, WStringBase<T>(str)); 
	}
	
	/**
	* Compares two strings lexicographically.
	* The comparison is based on the Unicode value of each character in the strings.
	* A subset of the character sequence represented by this WString object
	* is compared lexicographically to the character sequence represented by the argument
	* string.
	* The subset starts at position index, The length of the subset is defined
	* by the count argument.
	* The result is a positive integer if this WString object lexicographically follows
	* the argument string. The result is zero if the strings are equal; <code>compareTo</code>
	* returns <code>0</code> exactly when the equality operator would return <code>true</code>.
	* <p>
	* This is the definition for lexicographic ordering. If two strings are different,
	* then either the have different characters at some index that is a valid index for both
	* strings, or their lengths are different, or both. 
	* @param str string to compare to
	* @return 0 if the argument string is equal to this string, a value less than 0 if this string
	* is lexicographically less than the string argument; and a value greater than 0 if this
	* string is lexicographically greater than the string argument.
	*/ 
	
	int compareTo(size_type index, size_type count, const WStringBase<T>& str) const 
	{
		return _BT::compare(index,count,str);
	}
	
	
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
	bool equalsIgnoreCase(const T* str) const ;
	
	
	/** 
	* Compares this string to another string, ignoring case considerations.
	* Two strings are considered equal ignoring case if they are of the same
	* length, and corresponding characters in the two string are equal ignoring
	* case.
	* @param str the WStringBase to compare this WStringBase against.
	*/
	bool equalsIgnoreCase(const WStringBase<T>& str) const ;
	
	/**
	* Returns a copy of this WStringBase
	*/
	inline WStringBase<T> w_str() const { 
		return *this;
	}
	
	/**
	* Returns the internal character data
	*/
	inline const T* c_str() const { 
		return _BT::c_str();
	}
	
	/**
	* Converts this string into bytes according to the platform's 
	* default character encoding, storing the result into a new byte array.
	* @return the resultant byte array
	*/
//	virtual char* getBytes() const;
	
	/**
	* Returns the substring starting at the index specified by
	* <code>beginIndex</code>. The substring starts with the character at the
	* specified index and extends to the end of this string.
	* @param beginIndex the beginning index, inclusive
	* @param length the number of characters to copy starting at the beginIndex.
	* @return the specified substring
	*/
	inline WStringBase<T> substring(int beginIndex) const { 
		return substring(beginIndex,this->length()); 
	}
	
	/**
	* Returns the substring starting at the index specified by
	* <code>beginIndex</code>. The substring starts with the character at the
	* specified index and extends to the character at index <code>endIndex</code>-1.
	* Thus the length of the substring is endIndex-beginIndex.
	*<p>
	* Example
	* <p><pre>
	*  WStringBase("hamburger").substring(4,8) returns "urge
	*  WStringBase("smiles").substring(1,5) returns "mile"
	* </pre><p>
	* @param beginIndex the beginning index, inclusive
	* @param endIndex the ending index, exclusive
	* @return the specified substring
	*/
	inline WStringBase<T> substring(int beginIndex, int endIndex) const { 
		return _BT::substr(beginIndex,endIndex-beginIndex); 
	}
	
	/**
	* Returns the substring starting at the index specified by
	* <code>beginIndex</code>. The substring starts with the character at the
	* specified index and extends with a number of characters specified by length.
	* @param beginIndex the beginning index, inclusive
	* @param length the number of characters to copy starting at the beginIndex.
	* @return the specified substring
	*/
	inline WStringBase<T> substr(int beginIndex=0, int length=WString::npos) const { 
		return _BT::substr(beginIndex,length); 
	}
	
	/**
	* Returns the substring consisting of the first n characters.
	*/
	inline WStringBase<T> leftstring(int n) const { 
		if (n <0) 
			return *this; 
		else if (n==0) 
			return L""; 
		else 
			return substr(0,n); 
	}
	
	/**
	* Returns the substring consisting of the last n characters.
	*/
	inline WStringBase<T> rightstring(int n) const{ 
		if (n <0) 
			return *this; 
		else if (n==0) 
			return L""; 
		else return substr(this->length()-n); 
	}
	
	
	/**
	* note the python like usage of negative n
	* e.g. leftStr (-4) results in leftStr(length-4)
	*/
	inline WStringBase<T> leftStr (int n) const {
		if (n<0) 
			n=this->length()+n; 
		if(n<=0) 
			return L""; 
		return substr(0, n); 
	}
	/**
	* note the python like usage of negative n
	* e.g. rightStr (-4) results in leftStr(length-4)
	*/
	inline WStringBase<T> rightStr(int n) const {
		if (n<0) 
			n=this->length()+n; 
		if(n<=0) 
			return L""; 
		if (static_cast<unsigned int>(n) > this->length()) 
			return *this; 
		return substr(this->length() - n); 
	}
	
	/**
	* Removes white space from both ends of this string.
	* @return this string, with white space removed from the front and end.
	*/
	virtual WStringBase<T> trim() const { 
		WStringBase<T> s(*this); 
		_trim(s); 
		return s; 
	}
	
	/**
	* Removes white space from the front of this string.
	* @return this string, with white space removed from the front.
	*/
	virtual WStringBase<T> trimLeft() const { WStringBase<T> s(*this); _trimLeft(s); return s; }
	
	/**
	* Removes white space from the end of this string.
	* @return this string, with white space removed from the end.
	*/
	virtual WStringBase<T> trimRight() const { WStringBase<T> s(*this); _trimRight(s); return s; }
	
	/**
	* Tests if this string starts with the specified prefix.
	* @param prefix the prefix
	*/
	inline bool startsWith(const WStringBase<T>& prefix) const{ return (compareTo(0,prefix.length(),prefix) == 0); }
	
	/** 
	* Tests if this string starts with the specified byte sequence.
	* The byte sequence is first converted converted using the platform's default character encoding. 
	*
	* @param prefix the prefix
	*/
	inline bool startsWith(const char* prefix)const { return (compareTo(0,strlen(prefix),prefix) == 0); }
	
	/** 
	* Tests if this string starts with thes pecified prefix beginning a specified index.
	*
	* @param prefix the prefix
	* @Param offset where to begin looking in the string
	*/
    inline bool startsWith(const WStringBase<T>& prefix, int offset)const { return (compareTo(offset,prefix.length(),prefix) == 0); }
	
	/**
	* Tests if this string starts with the byte sequence beginning a specified index.
	* The byte sequence is first converted converted using the platform's default character encoding. 
	*
	* @param prefix the prefix
	* @Param offset where to begin looking in the string
	*/
	inline bool startsWith(const char* prefix, int offset) const{ return (compareTo(offset,strlen(prefix),prefix) == 0); }
	
	
	
	/**
	* Tests if this string starts with the specified prefix.
	* @param prefix the prefix
	*/
    inline bool endsWith(const WStringBase<T>& suffix) const{ 
		int pos = this->length() - suffix.length();
		if (pos < 0)
			return false;
		return startsWith(suffix,pos); 
	}
	
	/** 
	* Returns the index within this string of the first occurrence of the specified substring.
	* The integer returned is the smallest value <code>k</code> such that :
	* <p><pre>
	* this->startWith(str,k)
	* </pre><p>
	* is <code>true</code>
	* @param str any string
	* @return if the string argument occurs as a substring within this object, then the index
	* of the first character of the first such substring is returned; if it does not occur as a 
	* substring, -1 is returned.
	*/
	int indexOf(const WStringBase<T>& str) const;
	
	/**
	* Returns the index within this string of the first occurrence of the specified substring.
	* The integer returned is the smallest value <code>k</code> such that :
	* <p><pre>
	* this->startWith(str,k) && (k>= fromIndex)
	* </pre><p>
	* is <code>true</code>
	* There is no restriction on the value of <code>fromIndex</code>. If it is
	* negative, it has the same effect as if it were zero; this enture string may be searched.
	* If it is greater then the length of this string, it has the same effect as if were equal
	* to the length of this string: -1 is returned.
	* @param str the substring to search for.
	* @param fromIndex the index to start the search from
	* @return If the string argument occurs as a substring within this object at a starting index
	* no smaller than <code>fromIndex</code>, then the index of the first character of the first
	* such substring is returned. If it does not occur as a substring starting at <code>fromIndex</code>
	* or beyond <code>-1</code> is returned
	*/
	int indexOf(const WStringBase<T>& str, int fromIndex) const;

	/**
	* Returns a new WString resulting from replacing all occurrences of <code>oldChar</code> in this
	* WString with <code>newChar</code>.
	* @param oldChar the old character
	* @param newChar the new character
	* @return a string derived from this string replacing every occurrence of <code>oldChar</code> with <code>newChar</code>
	*/

	inline WStringBase<T> replaceChar(T oldChar, T newChar) const;

	inline bool regionMatches(int toffset, const WStringBase<T>& other, int ooffset, int len)const;
	inline bool regionMatches(bool ignoreCase, int toffset, const WStringBase<T>& other, int ooffset, int len)const;

    // rational operators used to compare two WStrings : equality or inequality
    inline bool operator==(const char*    rhs) const { return (compareTo(rhs) == 0); }
    inline bool operator==(const T* rhs) const { return (compareTo(rhs) == 0); }
    inline bool operator==(const WStringBase<T>& rhs) const { return (compareTo(rhs) == 0); }

    inline bool operator!=(const char*    rhs) const { return (compareTo(rhs) != 0); }
    inline bool operator!=(const T* rhs) const { return (compareTo(rhs) != 0); }
    inline bool operator!=(const WStringBase<T>& rhs) const { return (compareTo(rhs) != 0); }

    inline bool operator> (const T* rhs) const { return (compareTo(rhs) >  0); }
    inline bool operator< (const T* rhs) const { return (compareTo(rhs) <  0); }
    inline bool operator>=(const T* rhs) const { return (compareTo(rhs) >= 0); }
    inline bool operator<=(const T* rhs) const { return (compareTo(rhs) <= 0); }

    inline bool operator> (const WStringBase<T>& rhs) const { return (compareTo(rhs) >  0); }
    inline bool operator< (const WStringBase<T>& rhs) const { return (compareTo(rhs) <  0); }
    inline bool operator>=(const WStringBase<T>& rhs) const { return (compareTo(rhs) >= 0); }
    inline bool operator<=(const WStringBase<T>& rhs) const { return (compareTo(rhs) <= 0); }

    friend inline WStringBase<T> operator+(const WStringBase<T>& str1, const T* str2);
    friend inline WStringBase<T> operator+(const T* str1, const WStringBase<T>& str2);
    friend inline WStringBase<T> operator+(const WStringBase<T>& str1, const char* str2);
	friend inline WStringBase<T> operator+(const char* str1, const WStringBase<T>& str2);
    friend inline WStringBase<T> operator+(const WStringBase<T>& str1, const T str2);
	friend inline WStringBase<T> operator+(const T str1, const WStringBase<T>& str2);
	//friend inline WStringBase<T> operator+(const WStringBase<T> str1, const WStringBase<T> str2);

	inline void append(T ch)  { _BT::append(1,ch); }
	inline void append(int i,T ch)  { _BT::append(i,ch); }
	inline void append(const WStringBase<T>& str)  { _BT::append(str.c_str()); }
	inline void append(const T* const str)  { _BT::append(str); }
	inline void append(const T* const str,int len)  { _BT::append(str,len); }
	inline void append(const char* const str)  { append(WStringBase<T>(str)); }
	inline void append(const char* const str,int len)  { append(WStringBase<T>(str,len)); }
	/// rp added 170501
	inline void append(const WStringBase<T> str, size_type pos, size_type n){_BT::append(str,pos,n);}

/*
	T* buffer       (int nMinBufLen = -1) { return _buffer       (*this, nMinBufLen); }
    T* bufferSet    (int nNewLen)         { return _bufferSet    (*this, nNewLen);    }
    void     bufferRelease(int nNewLen = -1 )   {    _bufferRelease(*this, nNewLen);    }
*/
};


/******************************************************************************
*	Prototypes
******************************************************************************/


/******************************************************************************
*	Implementation
******************************************************************************/

template <class T>
WStringBase<T> WStringBase<T>::replaceChar(T oldChar, T newChar) const
{
	WStringBase<T> s(*this);
	typename _BT::iterator it;
    for (it = s.begin(); it != s.end(); it++)
    {
        if (*it == oldChar)
            *it = newChar;
    }
	return s;
}

template <class T>
bool WStringBase<T>::regionMatches(int toffset, const WStringBase<T>& other, int ooffset, int len) const
{
	if ((ooffset < 0) || (toffset < 0) || (toffset > (long)this->length() - len)
		|| (ooffset > (long)other.length() - len)) 
	{
		return false;
	}
	while (len-- > 0) {
		if ( _BT::operator[](toffset++) != other[ooffset++]) 
			return false;
	}
	return true;
}

template <class T>
bool WStringBase<T>::regionMatches(bool ignoreCase, int toffset, const WStringBase<T>& other, int ooffset, int len) const
{
	if ((ooffset < 0) || (toffset < 0) || (toffset > (long)this->length() - len)
		|| (ooffset > (long)other.length() - len)) 
	{
		return false;
	}
	while (len-- > 0) 
	{
		if (ignoreCase)
		{
			if (towlower( _BT::operator[](toffset++)) != towlower(other[ooffset++]))
				return false;
		}
		else
		{
			if ( _BT::operator[](toffset++) != other[ooffset++]) 
				return false;
		}
	}
	return true;
}  

template <class T>
WStringBase<T>& WStringBase<T>::operator=(const char c)
{
	char buf[2] = { c, '\0' };
	return (*this = buf);
}

template <class T>
WStringBase<T>& WStringBase<T>::operator=(const std::string& str)
{
	return (*this = str.c_str()); 
}
template <class T>
WStringBase<T> operator+(const WStringBase<T>& str1, const T* str2) 
{
    WStringBase<T> str(str1); str.append(str2); return str;       
}

template <class T>
WStringBase<T> operator+(const T* str1, const WStringBase<T>& str2) 
{
    WStringBase<T> str(str1); str.append(str2); return str;
}

template <class T>
WStringBase<T> operator+(const WStringBase<T>& str1, const char* str2)
{
    WStringBase<T> str(str1); str.append(WStringBase<T>(str2)); return str;       
}

template <class T>
WStringBase<T> operator+(const char* str1, const WStringBase<T>& str2) 
{
    WStringBase<T> str(str1); str.append(str2); return str;       
}

template <class T>
WStringBase<T> operator+(const WStringBase<T>& str1, const T str2)
{
    WStringBase<T> str(str1);str.append(1,str2);return str;
}

//template <class T>
//WStringBase<T> operator+(const WStringBase<T> str1, const WStringBase<T> str2){
//	WStringBase<T> str(str1);
//	str.append(str2.c_str());
//	return str;
//}

template <class T>
WStringBase<T> operator+(const T str1, const WStringBase<T>& str2)
{
    WStringBase<T> str(str1); str.append(str2); return str;
}


template <class T>
int WStringBase<T>::indexOf(const WStringBase<T>& str) const
{
	return indexOf(str,0);
}

template <class T>
int WStringBase<T>::indexOf(const WStringBase<T>& str, int fromIndex) const
{
	const T* v1 = c_str();
	const T* v2 = str.c_str();
	
	int max =this->length() - str.length();
	if (static_cast<unsigned int>(fromIndex) >= this->length())
	{
		// there is an empty string at index 0 in an empty string
		if (this->length() == 0 && fromIndex == 0 && str.length() == 0)
			return 0;
		return -1;
	}
	if (fromIndex < 0)
		fromIndex = 0;
	
	if (str.length() == 0)
		return fromIndex;
	
	JDFCh first = v2[0];
	int i = fromIndex;
	bool continueSearch=false;
	while (true)
	{
		/* Look for first character. */
		while (i <= max && v1[i] != first) 
			i++;
		
		if (i > max) 
			return (int)WStringBase::npos;
		
		/* Found first character, now look at the rest of v2 */
		int j = i + 1;
		int end = j + str.length() - 1;
		int k = 1;
		continueSearch = false;
		while (j < end) 
		{
			if (v1[j++] != v2[k++]) 
			{
				i++;
				/* Look for str's first char again. */
				continueSearch = true;
				break;
			}
		}
		if (continueSearch)
			continue;
		
		return i;	/* Found whole string. */
    }
}



/******************************************************************************
*	Prototypes
******************************************************************************/ 


/******************************************************************************
*	Implementation
******************************************************************************/ 

} 

#endif /* I_JDF_WSTRINGBASE_H */

