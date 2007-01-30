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
// 2000-12-20 MM added constructor MyDate(const WString  & a_aTime) 
// 2001-10-17 MM added AddTime and AddDate 
// 2002-01-30 MG added constructor MyDate(const time_t tsec) 
// 2002-01-30 MG added GetSecondsSince1970 
// 2002-07-08 MG changes in MyDate(const WString  & a_aTime) 
// 2002-07-08 MG changes in MyDate::ISOTimeZone() 
// 2002-07-08 MG added int SetTimeOverflow(int h, int m=0, int s=0)	
// 2002-07-08 MG added void SetDate(int y, int m, int d,int carry) 
// 2002-07-08 MG added int SetDayOverflow(int d,int m,int y)
// 2002-07-08 MG added int SetMonthOverflow(int m)
// 2002-07-12 SF remove mac exclusion
// 2004-02-02 ES changes in MyDate(const WString  & a_aTime)
// 2004-02-02 ES added SetDurationFromString, SetDateTimeFromString
// 2004-02-02 ES added operators ==, !=, <=, >=, >, <
// 2004-02-02 ES changed duration type from int into double 
//
// 2004-11-10 ES MyDate was split into JDFDate and JDFDuration
//
// JDFDuration.cpp: implementation of the JDFDuration class.
//
//////////////////////////////////////////////////////////////////////

#include "JDFDuration.h"

#include <jdf/lang/WString.h>
#include <jdf/lang/vWString.h>
#include <jdf/wrappercore/MyDate.h>
#include <jdf/wrappercore/JDFException.h>
#include <jdf/lang/Exception.h>

#include <ctime>
#include <algorithm>
#include <math.h>
#include "xercesc/util/regx/RegularExpression.hpp"

XERCES_CPP_NAMESPACE_USE
using namespace std;

namespace JDF{
	
	
	///////////////////////////////////////////////////////////////////
	
	JDFDuration::JDFDuration(){
		duration=0.0;
	};
	///////////////////////////////////////////////////////////////////
	
	JDFDuration::JDFDuration(const JDFDuration & other){
		*this=other;
	}
	///////////////////////////////////////////////////////////////////
	
	JDFDuration::JDFDuration(const MyDate& other){
		duration=other.duration;
	};
	///////////////////////////////////////////////////////////////////
	
	JDFDuration::JDFDuration(double s){
		duration=s;
	};
	/////////////////////////////////////////////////////////////
	
	JDFDuration& JDFDuration::operator =(const JDFDuration& other){
		duration=other.duration;
		return *this;
	};
	///////////////////////////////////////////////////////////////////

	JDFDuration& JDFDuration::operator=(const WString & a_aTimeFormat){
		duration = 0.0;
		if (a_aTimeFormat.length() > 0)
		{
			RegularExpression re(WString::regExp_duration.c_str());
			if (re.matches(a_aTimeFormat.c_str())) {
				SetDurationString(a_aTimeFormat);
			} else {
				throw IllegalArgumentException("JDFDuration illegal string "+ a_aTimeFormat);
			}
		}
		return *this;
	}

	///////////////////////////////////////////////////////////////////

	JDFDuration::JDFDuration(const WString & a_aTimeFormat){
		*this=a_aTimeFormat;
	}

	///////////////////////////////////////////////////////////////////
	
	void JDFDuration::SetDurationString(const WString & a_aDuration){
		duration=0.0;
		
		int y, mo, d, h, mi;
		double s;
		
		y = mo = d = h = mi = 0;
		s =0.0;
				
		WString  thePeriod, theDate, theTime, Years, Months, Days, Hours, Minutes, Seconds;
		
		int iPPos = a_aDuration.find_first_of(L"P");
		
		thePeriod = a_aDuration.substr (++iPPos, a_aDuration.length()-iPPos);
			
		// devide periodInstant into date and time part, which are separated by 'T'
		int iTPos = thePeriod.find_first_of(L"T");

		if (iTPos >= 0) 
		{
			if (iTPos == 0) { // e.g. if durationInstant looks like "PT10H30M" - without date part
				theTime = thePeriod.substr (++iTPos, thePeriod.length()-iTPos);;
			} 
			else { // e.g. if durationInstant looks like "P1Y2M3DT10H30M"
				theDate = thePeriod.substr (0, iTPos);
				theTime = thePeriod.substr (++iTPos, thePeriod.length()-iTPos);
				
			}
		}
		else { // e.g. if durationInstant looks like "P1Y2M3D" - without time part
			theDate = thePeriod;
		}
		
		if (theDate.length() > 0)
		{
			int iYPos = theDate.find_first_of(L"Y");
			if (iYPos > 0)
			{
				Years = theDate.substr (0, iYPos);
				y = (int) Years * 365*24*60*60; 
				duration += y;
			}

			int iMPos = theDate.find_first_of(L"M");
			if (iMPos > 0)
			{
				int nextYPos = ++iYPos;
				Months = theDate.substr (nextYPos, (iMPos-nextYPos));
				mo = (int) Months * 30*24*60*60;
				duration += mo;
			}

			int iDPos = theDate.find_first_of(L"D");
			if (iDPos > 0)
			{
				int nextMPos = ++iMPos;
				Days = theDate.substr (nextMPos, (iDPos-nextMPos));
				d = (int) Days * 24*60*60;
				duration += d;
			}
		}

		if (theTime.length() > 0)
		{
			int iHPos = theTime.find_first_of(L"H");
			if (iHPos > 0)
			{
				Hours = theTime.substr (0, iHPos);
				h = (int) Hours * 60*60; 
				duration += h;
			}

			int iMPos = theTime.find_first_of(L"M");
			if (iMPos > 0)
			{
				int nextHPos = ++iHPos;
				Minutes = theTime.substr (nextHPos, (iMPos-nextHPos));
				mi = (int) Minutes * 60;
				duration += mi;
			}

			int iSPos = theTime.find_first_of(L"S");
			if (iSPos > 0)
			{
				int nextMPos = ++iMPos;
				Seconds = theTime.substr (nextMPos, (iSPos-nextMPos));
				s = Seconds.isNumber() ? (double) Seconds : 0;
				duration += s;
			}
		}

}

///////////////////////////////////////////////////////////////////

WString  JDFDuration::DurationISO() const {
	if(duration==0) 
		return "PT00M";
	WString  s="P";
	int i;
	double sec;
	double temp=duration;
	if(i=(int)duration/(60*60*24*365)) {
		s=s+i+L"Y"; // string with years
		temp = duration - (i*60*60*24*365);
	}
	i=(int)temp;
	if(i=i/(60*60*24*30)) {
		s=s+i+L"M"; // string with months
		temp = temp - (i*60*60*24*30);
	}
	i=(int)temp%(60*60*24*30);
	if(i=i/(60*60*24)) {
		s=s+i+L"D"; // string with days
	}
	s+="T";
	
	i=(int)duration%(60*60*24);
	if(i=i/(60*60)) {
		s=s+i+L"H"; // string with hours
	}
	i=(int)duration%(60*60);
	if(i=i/(60)) {
		s=s+i+L"M"; // string with minutes
	}
	i=(int)duration%(60); 
	sec=i+(duration-(int)duration);
	if(sec) {
		char buf[8];
		sprintf(buf,"%.1f",sec); // seconds in format 00.0
	
		s=s+buf+L"S"; // string with seconds
	}
	
	int lastIndex=s.size()-1;
    if (s.find("T")==lastIndex)
        return s.leftStr(-1);
	return s;
	
}

///////////////////////////////////////////////////////////////////

void JDFDuration::SetDuration(double iSec)
{
	duration=iSec;
}

///////////////////////////////////////////////////////////////////

double JDFDuration::getDuration()
{
	return duration;
}

///////////////////////////////////////////////////////////////////

bool JDFDuration::operator ==(const JDFDuration & md)const{
	return fabs(duration-md.duration)<0.000000001;
}
///////////////////////////////////////////////////////////////////
bool JDFDuration::operator !=(const JDFDuration & md)const{
	return fabs(duration-md.duration)>0.000000001;
}
///////////////////////////////////////////////////////////////////
bool JDFDuration::operator >=(const JDFDuration & md)const{
	return (duration-md.duration) > -0.000000001;
}
///////////////////////////////////////////////////////////////////
bool JDFDuration::operator <=(const JDFDuration & md)const{
	return (duration-md.duration) < 0.000000001;
}
///////////////////////////////////////////////////////////////////
bool JDFDuration::operator >(const JDFDuration & md)const{
	return duration > md.duration;
}
///////////////////////////////////////////////////////////////////
bool JDFDuration::operator <(const JDFDuration & md)const{
	return duration < md.duration;
}
///////////////////////////////////////////////////////////////////

} // namespace JDF
