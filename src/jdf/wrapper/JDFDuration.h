/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2004 The International Cooperation for the Integration of 
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
//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT CIP 4, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Authors: 
//  RP: Dr. Rainer Prosi, Heidelberger Druckmaschinen AG
//  MM: Dr. Markus Möller, MAN Roland Druckmaschinen AG
// 
// Revision history:
// created before 19.Jan.2000
//
// 2000-04-14 RP added settime, setdate
// 2000-07-11 RP SetOffset: added call to Refresh()
// 2000-09-14 RP added duration and DurationISO
// 2002-01-11 RP added constructor MyDate(const MyDate& other) and operator = MyDate
// 2000-12-20 MM added constructor MyDate(const WString  & aTime) 
// 2002-01-30 MG added constructor MyDate(const time_t tsec) 
// 2002-01-30 MG added GetSecondsSince1970 
// 2002-07-08 MG added int SetTimeOverflow(int h, int m=0, int s=0)	
// 2002-07-08 MG added void SetDate(int y, int m, int d,int carry) 
// 2002-07-08 MG added int SetDayOverflow(int d,int m,int y)
// 2002-07-08 MG added int SetMonthOverflow(int m)
// 2002-07-12 SF remove mac exclusion
// 2002-08-27 RP replace std:string with WString
// 2002-09-24 RP ISOTimeZone() bug fix for negative time zones, used to print --
// 2002-10-30 RP added GetDaylight; use instead of _Daylight
// 2004-02-02 ES changes in MyDate(const WString  & a_aTime)
// 2004-02-02 ES added SetDurationFromString, SetDateTimeFromString
//
// 2004-11-10 ES MyDate was split into JDFDate and JDFDuration
// 2006-10-30 NB fixed SetDurationString()
// 2007-01-17 NB moved implementation of SetDuration() to JDFDuration.cpp
// 2007-01-17 NB added getDuration()
//
// JDFDuration.h: interface for the JDFDuration class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _JDFDuration_H_
#define _JDFDuration_H_

#if !defined(__MACH__)
#include "wchar.h"
#endif


#include <jdf/lang/JDFToolsDefs.h>
#include <jdf/lang/WString.h>

#include <ctime>
#define TIME_T_PREFIX 

namespace JDF {

	class WString;
/**
* date / time utility class
* converts system times to various formats
*/
class JDF_WRAPPERCORE_EXPORT JDFDuration {
	friend class MyDate;
public:
	
	/**
	* empty ctor
	*/
	JDFDuration();

	/**
	* ctor
	* @param double s: seconds of duration
	*/
	JDFDuration(double s);

	/**
	* constructs JDFDuration from a string
	* if empty duration = 0.0
	* @param WString & a_aTimeFormat: formatted duration
	*/
	JDFDuration(const WString & aTimeFormat);

	/**
	* copy constructor
	* constructs JDFDuration from a string
	* if empty duration = 0.0
	* @param WString& a_aTimeFormat: the string to set 'this' duration to
	*/
	JDFDuration& operator=(const WString & a_aTimeFormat);
	
	/**
	* copy constructor
	* @param JDFDuration & other: JDFDuration to copy
	*/
	JDFDuration(const JDFDuration & other);

	/**
	* copy constructor
	* @param MyDate & other: MyDate to copy as a duration
	*/
	JDFDuration(const MyDate & other);

	/**
	* ctor
	* @param JDFDuration & other: JDFDuration to copy
	*/
	JDFDuration& operator=(const JDFDuration& other);
	
	/**
	* dtor 
	*/
	virtual ~JDFDuration(){};


	/**
	* Sets duration from a String
	* @param WString & a_aDuration: formatted duration
	*/
	void SetDurationString(const WString & a_aDuration);

	/** 
	* duration in ISO 8601 format: PyYmMdDThHmMsS
	* @return WString: duration in ISO 8601 format
	*/
	WString DurationISO()  const;

	/**
	* set duration 
	* @param double iSec - seconds of duration
	*/
	void SetDuration(double iSec);


	/**
	* get duration 
	* @return double - duration in seconds
	*/
	double getDuration();
	
	/**
	* equality operator
	* @param JDFDuration & md: the JDFDuration object to compare to
	* @return bool: true if 'this' and 'md' are equal
	*/
	bool operator ==(const JDFDuration & md)const;

	/**
	* equality operator
	* @param JDFDuration & md: the JDFDuration object to compare to
	* @return bool: true if 'this' and 'md' are not equal
	*/
	bool operator !=(const JDFDuration & md)const;
	
	/**
	* equality operator
	* @param JDFDuration & md: the JDFDuration object to compare to
	* @return bool: true if 'this' >= 'md'
	*/
	bool operator >=(const JDFDuration & md)const;
	
	/**
	* equality operator
	* @param JDFDuration & md: the JDFDuration object to compare to
	* @return bool: true if 'this' <= 'md'
	*/
	bool operator <=(const JDFDuration & md)const;
	
	/**
	* equality operator
	* @param JDFDuration & md: the JDFDuration object to compare to
	* @return bool: true if 'this' > 'md'
	*/
	bool operator >(const JDFDuration & md)const;

	/**
	* equality operator
	* @param JDFDuration & md: the JDFDuration object to compare to
	* @return bool: true if 'this' < 'md'
	*/
	bool operator <(const JDFDuration & md)const;

	
protected:

	/**
	* duration in seconds in format 0.0
	*/
	double duration;


};

}
#endif // !defined(_JDFDuration_H_)


