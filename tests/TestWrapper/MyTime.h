//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
//
// MyTime.h: interface for the MyTime class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYTIME_H__CAB83E02_A543_11D2_8DB0_0060086D41A4__INCLUDED_)
#define AFX_MYTIME_H__CAB83E02_A543_11D2_8DB0_0060086D41A4__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "time.h"
#include "string.h"

/*
Execution Time processor for profiling
*/

class MyTime{
public:
	void Stop();
	void Start();
	MyTime(char* Name, bool start=true);
	virtual ~MyTime();

private:
	int nStarts;
	bool bTiming;
	char* name;
	time_t startTime, pauseTime;
	clock_t startClock, pauseClock; 
	double dTime;
	long dClock;
};

#endif // !defined(AFX_MYTIME_H__CAB83E02_A543_11D2_8DB0_0060086D41A4__INCLUDED_)
