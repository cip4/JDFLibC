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
// MyDate.h: interface for the MyDate class.
// Date and time routines
//
//////////////////////////////////////////////////////////////////////

#ifndef _MyDate_H_
#define _MyDate_H_

#if !defined(__MACH__)
#include "wchar.h"
#endif


#include <jdf/lang/JDFToolsDefs.h>
#include <jdf/lang/WString.h>
#include <jdf/wrapper/JDFDate.h>
#include <jdf/wrapper/JDFDuration.h>

#include <ctime>
#define TIME_T_PREFIX 


namespace JDF {

	class JDFDate;
	class JDFDuration;
	class WString;
/**
* date / time utility class
* converts system times to various formats
*/
class JDF_WRAPPERCORE_EXPORT MyDate {
	friend class JDFDate;
	friend class JDFDuration;

public:
	/**
	* ctor
	* @param int iOffset offset to the current time in milliseconds
	*/
	MyDate(int iOffset=0);
	/**
	* ctor
	* @param WString & a_aTimeFormat: formatted date and time or duration
	*/
	MyDate(const WString & aTimeFormat);
	/**
	* ctor
	* @param time_t tsec time in second from 1st Jan 1970
	*/
	MyDate(const TIME_T_PREFIX::time_t tsec);
	/**
	* ctor
	* @param MyDate & other the date to copy
	*/
	inline MyDate(const MyDate & other){
		*this=other;
	}

	/**
	* ctor
	* @param JDFDate & other the date to copy
	*/
	MyDate(const JDFDate & other);

	/**
	* ctor
	* @param JDFDuration & other the date to copy
	*/
	MyDate(const JDFDuration & other);

	/**
	* ctor
	* @param MyDate & other the date to copy
	*/
	MyDate& operator=(const MyDate& other);

	/**
	* ctor 
	* if either date or time are missing in the string, they are filled with the actual date and time
	* @param WString  a_aTimeFormat the string to set this date to
	*/
	MyDate& operator=(const WString & a_aTimeFormat);
	
	/**
	* dtor 
	*/
	virtual ~MyDate(){};

	/**
	* Sets date and time from a String
	* @param WString & a_aTime: formatted date and time
	*/
	void SetDateTimeString(const WString & a_aTime);
	/**
	* Sets duration from a String
	* @param WString & a_aDuration: formatted duration
	*/
	void SetDurationString(const WString & a_aDuration);
	/**
	* add time to the internal saved time
	* @param int h hours to be added
	* @param int m minutes to be added 
	* @param int s seconds to be added 
	*/
	void AddTime(int h,int m=0, int s=0);
	/**
	* add time to the internal saved time
	* @param int y years to be added
	* @param int m months to be added 
	* @param int d days to be added 
	*/
	void AddDate(int y,int m=0, int d=0);
	/**
	* set local time, the date remains constant
	* @param int hour 0-23
	* @param int minute 0-59 
	* @param int second 0-59 
	*/
	void SetTime(int h,int m=0, int s=0);
	/**
	* set local time, the date and get an overflow for the date
	* @param int hour 0-47
	* @param int minute 0-59 
	* @param int second 0-59 
	* @return int overflow for the date
	*/
	int SetTimeOverflow(int h, int m=0, int s=0);	
	/**
	* set date year, month, day
	* @param int year
	* @param int month 1-12 
	* @param int day 1-31 
	*/
	void SetDate(int y,int m=1, int d=1);

	/**
	* set date year, month, day,carry (overflow from SetTimeOverflow)
	* @param int year
	* @param int month 1-12 
	* @param int day 1-31
	* @param int carry -1 - +1
	*/
	void SetDate(int y, int m, int d,int carry);
	// various formatting routines
	/** 
	* the date in YYYYMMDD format
	* @return string the date in YYYYMMDD format
	*/
	WString  DateYYYYMMDD()  const;
	/** 
	* the time in HHMMSS format
	* @return string the time in HHMMSS format
	*/
	WString  TimeHHMMSS()  const;
	/** 
	* the date + time in YYYYMMDDHHMMSS format
	* @return string the date + time in YYYYMMDDHHMMSS format
	*/
	WString  DateTime()  const;
	/** 
	* the date in ISO 8601 format: YYYY-MM-DD
	* @return string the date in ISO 8601 format
	*/
	WString  DateISO()  const;
	/** 
	* the time in ISO 8601 format: HH:MM:SS-TZ:TZ
	* @return string the time in ISO 8601 format
	*/
	WString  TimeISO()  const;
	/** 
	* the time duration in ISO 8601 format: PyYmMdDThHmMsS
	* @return string the time in ISO 8601 format
	*/
	WString  DurationISO()  const;
	/** 
	* the date+time in ISO 8601 format: YYYY-MM-DDTHH:MM:SS-TZ:TZ
	* @return string the time in ISO 8601 format
	*/
	WString  DateTimeISO()  const;
	/**
	* set the offset compared to machine time
	* @param int iSec seconds of offset vs. machine time
	*/
	void SetOffset(int iSec){offset=iSec;Refresh();};
	/**
	* set the duration 
	* @param int iSec seconds of duration
	*/
	void SetDuration(unsigned int i){duration=i;Refresh();};
	/**
	* apply the value of setdate, settime etc.
	*/
	void Refresh();
	/**
	* time zone off gmt
	@return int hours off GMT
	*/
	int DeltaTimeZone() const;
	/**
	* print out current timezone
	*/
	WString  ISOTimeZone()  const;
	/**
	* a pointer to the tm structure used internally
	* @return const tm* the internal tm structure
	*/
	const struct tm * pTime() const {
		return &sTim;
	}
	/** 
	* the time in seconds since 1.1.1970 from internal tm structure sTim
	* @return time_t in sec
	*/
    time_t GetSecondsSince1970() const;

	
	/**
	* equality operator
	* @param MyDate & md: the MyDate object to compare to
	* @return bool: true if 'this' and 'md' are equal
	*/
	bool operator ==(const MyDate & md)const;

	/**
	* equality operator
	* @param MyDate & md: the MyDate object to compare to
	* @return bool: true if 'this' and 'md' are not equal
	*/
	bool operator !=(const MyDate & md)const;
	
	/**
	* equality operator
	* @param MyDate & md: the MyDate object to compare to
	* @return bool: true if 'this' >= 'md'
	*/
	bool operator >=(const MyDate & md)const;
	
	/**
	* equality operator
	* @param MyDate & md: the MyDate object to compare to
	* @return bool: true if 'this' <= 'md'
	*/
	bool operator <=(const MyDate & md)const;
	
	/**
	* equality operator
	* @param MyDate & md: the MyDate object to compare to
	* @return bool: true if 'this' > 'md'
	*/
	bool operator >(const MyDate & md)const;

	/**
	* equality operator
	* @param MyDate & md: the MyDate object to compare to
	* @return bool: true if 'this' < 'md'
	*/
	bool operator <(const MyDate & md)const;

	
protected:
	/**
	* time_t for internal use
	*/
	time_t t;
	/**
	* offset to machine time in seconds
	*/
	int offset;
	/**
	* duration in seconds in format 0.0
	*/
	double duration;
	/**
	* tm for internal use
	*/
	struct tm sTim;

private:

	/**
	* set date and get overflow for the month
	* @param int day -1 - 32 
	* @param int month 0 - 11 
	* @param int year 
	* @return int overflow to the month
	*/
	int SetDayOverflow(int d,int m,int y);

	/**
	* set date and get overflow for the month
	* @param int month 1-12 
	* @return int overflow to the year
	*/
	int SetMonthOverflow(int m);
	
	/**
	* get daylight value
	* @return int daylight value; 0 if not DST
	*/
	int GetDaylight() const;

};

}
#endif // !defined(_MyDate_H_)


