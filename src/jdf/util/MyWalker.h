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
// KPoint.h: interface for the KPoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYWALKER__INCLUDED_)
#define AFX_MYWALKER__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
/**
simple wrapper around stackwalker that is switched off in release mode
*/
class JDFTOOLS_EXPORT MyWalker
{
public:
	MyWalker();
	virtual ~MyWalker();
};

#endif // !defined(AFX_MYWALKER__INCLUDED_)
