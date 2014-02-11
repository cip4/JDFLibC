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
// MyArgs.h: interface for the MyArgs class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYARGS_H__1B1905B2_A6FE_11D2_8DB5_0060086D41A4__INCLUDED_)
#define AFX_MYARGS_H__1B1905B2_A6FE_11D2_8DB5_0060086D41A4__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
  
#include <jdf/lang/JDFToolsDefs.h>
#include "jdf/util/myuti.h"
#include "jdf/lang/KString.h"
 
/**
command line argument processor
*/

class MyArgs{
public:
	int IntParameter(char c,int idef=0,int radix=10);
	double FloatParameter(char c, double def=0.);
	bool BoolParameter(char c, bool def=false);
	const char* Parameter(char c);
	const char* Argument(int m=0);
	inline JDF::WString ParameterString(char c){const char*pc=Parameter(c); return pc?pc:"";};
	inline JDF::WString ArgumentString(int m=0){const char*pc=Argument(m); return pc?pc:"";};
	JDF::WString Usage(JDF::WString pc="");
	int NArgs();
	MyArgs(int argc, char** argv, const char*param0string,const char*param1string,const char*paramreqstring=0);
	virtual ~MyArgs();

protected:
	JDF::WString sBuf;
	int nArgs;
	char ** onlyArgs;
	char** argV;
	char*param0String;
	char*param1String;
	char*paramReqString;
	int argC;
};

#endif // !defined(AFX_MYARGS_H__1B1905B2_A6FE_11D2_8DB5_0060086D41A4__INCLUDED_)
