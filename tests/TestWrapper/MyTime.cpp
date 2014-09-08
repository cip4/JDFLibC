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
// MyTime.cpp: implementation of the MyTime class.
//
//////////////////////////////////////////////////////////////////////

#include "time.h"
#include "string.h"
#include <iostream>
#include "stdio.h"
#include "MyTime.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MyTime::MyTime(const char* Name, bool start)
{
//	startTime=time(&startTime);
	startClock=clock();
	name=new char[1+strlen(Name)];
	strcpy(name,Name);
	dTime=dClock=nStarts=0;
	bTiming=false;
	if(start) {
		Start();
	}
}

MyTime::~MyTime()
{
	Stop();
//	cout << "Time in "<<name<<" : "<<difftime(time(0),startTime)<<" Process Time: "<<(double)(clock()-startClock)/CLOCKS_PER_SEC<<" Calls: "<<nStarts<<" Timed Time: "<<dTime<<" Timed Clocks: "<<(float)dClock/CLOCKS_PER_SEC<<endl;
//	cout << "Time in "<<name<<" :  Calls: "<<nStarts<<" Total Time: "<<dTime<<" Clocked Time: "<<(float)dClock/CLOCKS_PER_SEC<<endl;
	if (nStarts){
		printf("%20s : Calls: %6i Time: %5.1f",name,nStarts,(float)dClock/CLOCKS_PER_SEC);
		if(nStarts>1) printf(" T/call (mS): %8.1f",(float)dClock/(nStarts));
		printf("\n");
	}
  // *!* added brackets since name was allocated as an array -af-
	delete[] (name);

}

void MyTime::Stop()
{
	if(!bTiming) return;
	bTiming=false;
//	dTime+=difftime(time(0),pauseTime);
	dClock+=(clock()-pauseClock);
}

void MyTime::Start()
{
	if(bTiming) return;
	bTiming=true;
	nStarts++;
//	pauseTime=time(0);
	pauseClock=clock();
}
