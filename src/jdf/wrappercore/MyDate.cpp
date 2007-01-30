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
// MyDate.cpp: implementation of the MyDate class.
//
//////////////////////////////////////////////////////////////////////

#include "MyDate.h"

#include <jdf/lang/WString.h>
#include <jdf/lang/vWString.h>
#include <jdf/wrappercore/JDFException.h>
#include <jdf/lang/Exception.h>

#include <ctime>
#include <algorithm>
#include <xercesc/util/regx/RegularExpression.hpp>

XERCES_CPP_NAMESPACE_USE
using namespace std;

namespace JDF{
	

	MyDate::MyDate(int iOffset){
		offset=iOffset;
		duration=0.0;
		Refresh();
	};
	
	///////////////////////////////////////////////////////////////////
	
	MyDate& MyDate::operator =(const MyDate& other){
		duration=other.duration;
		offset=other.offset;
		sTim=other.sTim;
		t=other.t;
		return *this;
	};
	
	///////////////////////////////////////////////////////////////////
	
	MyDate::MyDate(const JDFDate& other)
	{
		duration=0.0;
		offset=other.offset;
		sTim=other.sTim;
		t=other.t;
	}

	///////////////////////////////////////////////////////////////////
	
	MyDate::MyDate(const JDFDuration& other)
	{
		duration=other.duration;
		offset=0;
	}

	///////////////////////////////////////////////////////////////////
	
	MyDate::MyDate(const time_t tsec)
	{
		struct tm *tmFromTimet;
		offset=0;
		duration=0.0;
		t = tsec;
		
		tmFromTimet = localtime(&t);
		if(tmFromTimet != NULL)
		{
			memcpy(&sTim,tmFromTimet,sizeof(tm));
		}
	}
	
	///////////////////////////////////////////////////////////////////

	MyDate& MyDate::operator=(const WString & a_aTimeFormat){
		offset=0;
		duration=0.0;
		
		if (a_aTimeFormat.length() <= 0)
		{
			Refresh();
			return *this;
		}

		// is the string a duration format ('P' - Period) or a date time format?
		int iPPos = a_aTimeFormat.find_first_of(L"P");
		
		 
		if (iPPos == 0) //string is duration format
		{
			RegularExpression re(WString::regExp_duration.c_str());
			if (re.matches(a_aTimeFormat.c_str())) {
				SetDurationString(a_aTimeFormat);
			} else {
				throw IllegalArgumentException("MyDate illegal MyDate duration string: "+ a_aTimeFormat);
			}
		}
		
		else //string is date time format
		{
			RegularExpression re(WString::regExp_datetime.c_str());
			if (re.matches(a_aTimeFormat.c_str())) {
				Refresh();
				SetDateTimeString(a_aTimeFormat);
			} else {
				throw IllegalArgumentException("MyDate illegal MyDate string: "+ a_aTimeFormat);
			}
		}
		return *this;
	}

	///////////////////////////////////////////////////////////////////

	MyDate::MyDate(const WString & a_aTimeFormat){
		*this=a_aTimeFormat;
	}

	///////////////////////////////////////////////////////////////////

	void MyDate::SetDateTimeString(const WString & a_aTime){
		offset=0;
		duration=0.0;
		
		int h,mi,y,mo,d, h_bias, mi_bias, s;
		
		y=sTim.tm_year+1900;
		mo=sTim.tm_mon+1;
		d=sTim.tm_mday;
		h=sTim.tm_hour;
		mi=sTim.tm_min;
		s=sTim.tm_sec;
		
		// set daylight time insert by MG 08.07.2002 
		sTim.tm_isdst = GetDaylight();
		
		WString  theDate, theTime, thePureTime, theBiasTime;
		
		// devide timeInstant into date and time part, which are separated by 'T'
		int iTPos = a_aTime.find_first_of(L"T");
		
		if (iTPos >= 0) 
		{
			theDate = a_aTime.substr (0, iTPos);
			theTime = a_aTime.substr (++iTPos, a_aTime.length()-iTPos);
			// devide time part into pure time part and bias offset time, 
			// may be which are separated by '+' or '-'
			int iTPosP = theTime.find_first_of(L"+");
			int iTPosN = theTime.find_first_of(L"-");
			
			// *!* -af- added std:: scope to prevent overloading ambiguity
			iTPos = std::max (iTPosN, iTPosP); 
			if (iTPos > 0)
			{
				thePureTime = theTime.substr (0, iTPos);
				theBiasTime = theTime.substr (iTPos, theTime.length()-iTPos);
			}
			else
			{
				// time zone may also be in A-Z format
				JDFCh lastChar=theTime.at(theTime.length()-1);
				if((lastChar>=L'a')&&(lastChar<=L'z'))
					lastChar+=L'P'-L'p';

				if((lastChar>=L'A')&&(lastChar<=L'Z')){ // we have a zulu style time zone
					theBiasTime=L"+00:00";
					if((lastChar>=L'A')&&(lastChar<=L'I')){
						theBiasTime[2]=L'1'+lastChar-L'A';
					}else if((lastChar>=L'K')&&(lastChar<=L'M')){
						theBiasTime[1]=L'1';
						theBiasTime[2]=L'0'+lastChar-L'K';
					}else if((lastChar>=L'N')&&(lastChar<=L'V')){
						theBiasTime[0]=L'-';
						theBiasTime[2]=L'1'+lastChar-L'N';
					}else if((lastChar>=L'W')&&(lastChar<=L'Y')){
						theBiasTime[0]=L'-';
						theBiasTime[1]=L'1';
						theBiasTime[2]=L'0'+lastChar-L'W';
					}
					thePureTime = theTime.leftStr(-1);
				}else{
				thePureTime = theTime;
			}
			}
			
		}
		else
		{
			theDate = a_aTime;
		}
		
		if (theDate.length() > 0)
		{
			vWString vDate=theDate.Tokenize(L"-");
			int siz=vDate.size();
			if(siz>0)
			y = vDate[0];
			if(siz>1)
			mo = vDate[1];
			if(siz>2)
			d = vDate[2];
		}
		
		if (thePureTime.length() > 0)
		{
			vWString vTime=thePureTime.Tokenize(WString::colon);
			int siz=vTime.size();
			// iRes is not used
			if(siz>0)		
			h = vTime[0];
			if(siz>1)		
			mi = vTime[1];
			if(siz>2)		
			s = vTime[2];
		}
		
		if (theBiasTime.length() > 0)
		{
			vWString vTime=theBiasTime.Tokenize(WString::colon);
			h_bias = vTime[0];
			mi_bias = vTime[1];
			// TBD-MMOE handle bias
			int dZone = DeltaTimeZone();
			if (h_bias==dZone)
			{
				SetTime(h, mi, s);
				SetDate(y, mo, d);
			}
			else
			{
				// TBD-MMOE, check this
				// Changed by MG 08.07.2002
				int iCarry = SetTimeOverflow(h+dZone-h_bias, mi, s);
				if(iCarry == 0)
				{
					SetDate(y, mo, d);
				}
				else
				{
					SetDate(y, mo, d,iCarry);
				}
			}
		}
		else
		{
			SetTime(h, mi, s);
			SetDate(y, mo, d);
		}
	}

	///////////////////////////////////////////////////////////////////
	
	void MyDate::SetDurationString(const WString & a_aDuration){
		offset=0;
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
				s = (double) Seconds;
				duration += s;
			}
		}

}

//////////////////////////////////////////////////////////////////////

void MyDate::Refresh(){
	time(&t);
	t+=offset;
	struct tm * pTm=localtime(&t);
	memcpy(&sTim,pTm,sizeof(sTim));
}

//////////////////////////////////////////////////////////////////////

WString  MyDate::DateYYYYMMDD() const {
	int year=sTim.tm_year+1900;
	int month=sTim.tm_mon+1;
	int day=sTim.tm_mday;
	char buf[256];
	sprintf(buf,"%.4i%.2i%.2i",year,month,day);
	return buf;
}

///////////////////////////////////////////////////////////////////

WString  MyDate::DateISO() const {
	int year=sTim.tm_year+1900;
	int month=sTim.tm_mon+1;
	int day=sTim.tm_mday;
	char buf[256];
	sprintf(buf,"%.4i-%.2i-%.2i",year,month,day);
	return buf;
}

///////////////////////////////////////////////////////////////////

WString  MyDate::TimeHHMMSS() const {
	int hour=sTim.tm_hour;
	int minute=sTim.tm_min;
	int sec=sTim.tm_sec;
	char buf[256];
	sprintf(buf,"%.2i%.2i%.2i",hour,minute,sec);
	return buf;
}

///////////////////////////////////////////////////////////////////
WString  MyDate::TimeISO() const {
	int hour=sTim.tm_hour;
	int minute=sTim.tm_min;
	int sec=sTim.tm_sec;
	char buf[256];
	sprintf(buf,"%.2i:%.2i:%.2i",hour,minute,sec);
	return buf;
}

///////////////////////////////////////////////////////////////////

WString  MyDate::DateTime() const {
	return DateYYYYMMDD()+TimeHHMMSS();
}

///////////////////////////////////////////////////////////////////

WString  MyDate::DateTimeISO() const {
	return DateISO()+WString(L"T")+TimeISO()+ISOTimeZone();
}

///////////////////////////////////////////////////////////////////

int MyDate::DeltaTimeZone() const {
	time_t t;
	time(&t);
	struct tm * pTm=localtime(&t);
	int i0=pTm->tm_hour;
	pTm=gmtime(&t);
	int i1=pTm->tm_hour;
	return (i0+36-i1)%24-12;
}

///////////////////////////////////////////////////////////////////

WString  MyDate::ISOTimeZone() const {
	int i=DeltaTimeZone();
	// 301002 RP this does not work and is not necessary: _daylight is always true on Win2k, regardless of the time zone.
	int iDayLight = GetDaylight();
    if( iDayLight != sTim.tm_isdst)
    {
        if(sTim.tm_isdst == 0)
        {
            i -= 1;
        }else{
			i +=1;
		}
    }
	
	//-----------------------------------------------------
	char buf[10];
	if (i<0){
		sprintf(buf,"%.2i:00",i);
	}else{
		sprintf(buf,"+%.2i:00",i);
	}
	return buf;
}


//new by MG 08.07.2002
///////////////////////////////////////////////////////////////////

int MyDate::SetTimeOverflow(int h, int m, int s){
    int iOverflow = 0;
	sTim.tm_sec=s;
	sTim.tm_min=m;
	
    if(h<0)
    {
        h+=24;
        iOverflow = -1;
    }
    else if(h>23)
    {
        h-=24;
        iOverflow = 1;
    }
	
	sTim.tm_hour=h;
    return iOverflow;
}

//new by MG 08.07.2002
///////////////////////////////////////////////////////////////////

void MyDate::SetDate(int y, int m, int d,int carry){
	
    int iOverflow;
    iOverflow = SetDayOverflow(d+carry,m,y);
    iOverflow = SetMonthOverflow(m+iOverflow);
	
	sTim.tm_year = y + iOverflow - 1900;
}

//new by MG 08.07.2002
///////////////////////////////////////////////////////////////////
int MyDate::SetMonthOverflow(int m){
    int i = m-1;
    int iOverflow = 0;
	
    if(i<0)
    {
        i+=12;
        iOverflow = -1;
    }
    else if(i>11)
    {
        i-=12;
        iOverflow = 1;
    }
	
	sTim.tm_mon=i;
    return iOverflow;
}

///////////////////////////////////////////////////////////////////

//new by MG 08.07.2002
int MyDate::SetDayOverflow(int d,int m,int y){
	
    int iOverflow = 0;
	
	d-=1;
	
    if((d>=0) && (d<28))
    {
		sTim.tm_mday=d+1;
        return 0;
    }
    else if(d<0)
    {
        iOverflow = -1;
        switch(m)
        {
		case 3:
            {
                int k = y%4;
                if(k!=0)
                {
                    d+=28;
                }
                else
                {
                    d+=29;
                }
				
            }
            break;
		case 5:
		case 7:
		case 10:
		case 12:
            {
                d+=30;
            }
            break;
		default:
            {
                d+=31;
            }
			
        }
    }
    else
    {
        switch(m)
        {
		case 2:
            {
                int k = y%4;
                if(k!=0)
                {
                    d-=28;
                    iOverflow = 1;
                }
                else
                {
                    if(d>28)
                    {
                        d-=29;
                        iOverflow = 1;
                    }
                }
				
            }
            break;
		case 4:
		case 6:
		case 9:
		case 11:
            {
                if(d>29)
                {
                    d-=30;
                    iOverflow = 1;
                }
            }
            break;
		default:
            {
                if(d>30)
                {
                    d-=31;
                    iOverflow = 1;
                }
            }
			
        }
		
    }
	
	sTim.tm_mday=d+1;
    return iOverflow;
}


///////////////////////////////////////////////////////////////////

void MyDate::SetTime(int h, int m, int s){
	sTim.tm_hour=h;
	sTim.tm_min=m;
	sTim.tm_sec=s;
}

///////////////////////////////////////////////////////////////////

void MyDate::SetDate(int y, int m, int d){
	sTim.tm_year=y-1900;
	sTim.tm_mon=m-1;
	sTim.tm_mday=d;
}

///////////////////////////////////////////////////////////////////

void MyDate::AddDate(int y, int m, int d)
{
	const int secondesPerDay = 24*3600;
	t += secondesPerDay * d;
	struct tm * pTm=localtime(&t);
	memcpy(&sTim, pTm, sizeof(sTim));
	sTim.tm_mon += m;
	int dYears = (sTim.tm_mon)/12;
	sTim.tm_mon += -(dYears*12);
	sTim.tm_year += y + dYears;
}

///////////////////////////////////////////////////////////////////

void MyDate::AddTime(int h, int m, int s)
{
	t += ( s + 60*m + 3600*h);
	struct tm * pTm=localtime(&t);
	memcpy(&sTim, pTm, sizeof(sTim));
}

///////////////////////////////////////////////////////////////////

WString  MyDate::DurationISO() const {
	if(duration==0) 
		return "PT00M";
	WString  s="P";
	int i;
	double sec;
	double temp=duration;

	i=(int)duration/(60*60*24*365);
	if ( i ) {
		s=s+i+L"Y"; // string with years
		temp = duration - (i*60*60*24*365);
	}

	i=(int)temp;
	i=i/(60*60*24*30);
	if ( i ) {
		s=s+i+L"M"; // string with months
		temp = temp - (i*60*60*24*30);
	}
	i=(int)temp%(60*60*24*30);
	i=i/(60*60*24);
	if ( i ) {
		s=s+i+L"D"; // string with days
	}
	s+="T";
	
	i=(int)duration%(60*60*24);
	i=i/(60*60);
	if ( i ) {
		s=s+i+L"H"; // string with hours
	}
	i=(int)duration%(60*60);
	i=i/(60);
	if ( i ) {
		s=s+i+L"M"; // string with minutes
	}
	i=(int)duration%(60); 
	sec=i+(duration-(int)duration);
	if(sec) {
		char buf[4];
		sprintf(buf,"%.1f",sec); // seconds in format 00.0
	
		s=s+buf+L"S"; // string with seconds
	}
	
	return s;
	
}

///////////////////////////////////////////////////////////////////

time_t MyDate::GetSecondsSince1970() const
{
	struct tm sMyTm;
	memcpy(&sMyTm,&sTim,sizeof(tm));
    return (mktime(&sMyTm));
}

///////////////////////////////////////////////////////////////////

int MyDate::GetDaylight() const
{
	time_t tMyt;
	time(&tMyt);
	struct tm *psMyTm = localtime(&tMyt);
	return psMyTm->tm_isdst;
}

///////////////////////////////////////////////////////////////////

bool MyDate::operator ==(const MyDate & md)const{
	if (duration>0 || md.duration>0) { // Compare two Duration objects 
		if (duration<=0 || md.duration<=0) // trying to compare DateTime with Duration -> exception
			throw JDFException("MyDate illegal compare pair");
		return (duration==md.duration);
	} // Compare two DateTime objects
	return GetSecondsSince1970()==md.GetSecondsSince1970();
}
///////////////////////////////////////////////////////////////////
bool MyDate::operator !=(const MyDate & md)const{
	if (duration>0 || md.duration>0) { // Compare two Duration objects
		if (duration<=0 || md.duration<=0) // trying to compare DateTime with Duration -> exception
			throw JDFException("MyDate illegal compare pair");
		return duration!=md.duration;
	}// Compare two DateTime objects
	return GetSecondsSince1970()!=md.GetSecondsSince1970();
}
///////////////////////////////////////////////////////////////////
bool MyDate::operator >=(const MyDate & md)const{
	if (duration>0 || md.duration>0) { // Compare two Duration objects
		if (duration<=0 || md.duration<=0) // trying to compare DateTime with Duration -> exception
			throw JDFException("MyDate illegal compare pair");
		return duration>=md.duration;
	}// Compare two DateTime objects
	return GetSecondsSince1970()>=md.GetSecondsSince1970();
}
///////////////////////////////////////////////////////////////////
bool MyDate::operator <=(const MyDate & md)const{
	if (duration>0 || md.duration>0) { // Compare two Duration objects
		if (duration<=0 || md.duration<=0) // trying to compare DateTime with Duration -> exception
			throw JDFException("MyDate illegal compare pair");
		return duration<=md.duration;
	}// Compare two DateTime objects
	return GetSecondsSince1970()<=md.GetSecondsSince1970();
}
///////////////////////////////////////////////////////////////////
bool MyDate::operator >(const MyDate & md)const{
	if (duration>0 || md.duration>0) { // Compare two Duration objects
		if (duration<=0 || md.duration<=0) // trying to compare DateTime with Duration -> exception
			throw JDFException("MyDate illegal compare pair");
		return duration>md.duration;
	}// Compare two DateTime objects
	return GetSecondsSince1970()>md.GetSecondsSince1970();
}
///////////////////////////////////////////////////////////////////
bool MyDate::operator <(const MyDate & md)const{
	if (duration>0 || md.duration>0) { // Compare two Duration objects
		if (duration<=0 || md.duration<=0) // trying to compare DateTime with Duration -> exception
			throw JDFException("MyDate illegal compare pair");
		return duration<md.duration;
	}// Compare two DateTime objects
	return GetSecondsSince1970()<md.GetSecondsSince1970();
}
///////////////////////////////////////////////////////////////////
} // namespace JDF
