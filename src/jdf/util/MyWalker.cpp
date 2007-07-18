//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 2007
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created  29.Jun.2007
//
// simple wrapper arround stackwalker that hides the windows crap
// simply instantiate an instance on the stack in main.
//
//////////////////////////////////////////////////////////////////////

#include "MyWalker.h"
#ifdef WIN32
#ifdef _DEBUG
#include <windows.h>
#include "Platforms/Win32/StackWalker.h"
#endif
#endif
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MyWalker::MyWalker()
{
#ifdef WIN32
#ifdef _DEBUG
	InitAllocCheck (ACOutput_XML);
#endif
#endif
}

//////////////////////////////////////////////////////////////////////

MyWalker::~MyWalker()
{
#ifdef WIN32
#ifdef _DEBUG
	DeInitAllocCheck ();
#endif
#endif
}
//////////////////////////////////////////////////////////////////////