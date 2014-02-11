/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2007 The International Cooperation for the Integration of 
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
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created  26.May.2000
//
// JDFIntegerRange.cpp: implementation of the JDFIntegerRange class.
//
//////////////////////////////////////////////////////////////////////

#pragma warning( disable : 4786 ) // long debug names from stl
#pragma warning( disable : 4804 ) // bool checking
#include "JDFIntegerRange.h"
#include "jdf/wrappercore/StringUtil.h"

#include <stdlib.h>

using namespace std;
static int m_defaultXDef=0;

namespace JDF{
	
	
	JDFIntegerRange::JDFIntegerRange(const IntegerRange&r){
		init (r.GetLeft(),r.GetRight());
	};
	
	//////////////////////////////////////////////////////////////////////

	JDFIntegerRange::JDFIntegerRange(const JDFIntegerRange&r){
		init (r.GetLeft(),r.GetRight(), r.xDef);
	};

	//////////////////////////////////////////////////////////////////////

	JDFIntegerRange& JDFIntegerRange::operator =(int r){
		init(r,r);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////

	JDFIntegerRange& JDFIntegerRange::operator =(const IntegerRange&r){
		init(r.GetLeft(),r.GetRight());
		return *this;
	}

	//////////////////////////////////////////////////////////////////////
	
	JDFIntegerRange& JDFIntegerRange::operator =(const JDFIntegerRange&r){
		init(r.GetLeft(),r.GetRight(),r.xDef);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////

	JDFIntegerRange& JDFIntegerRange::operator =(const WString& s){
		*this= IntegerRange::operator=(s);
		return *this;
	}
	
	//////////////////////////////////////////////////////////////////////

	bool JDFIntegerRange::InRange(const int& x) const
	{ 
		int _left = GetLeft();
		int _right = GetRight();
		int _realLeft = min(_left,_right);
		int _realRight = max(_left,_right);
		return (x>=_realLeft)&&(x<=_realRight);
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFIntegerRange::IsPartOfRange(JDFIntegerRange x){ 
		return (x.GetLeft()>=GetLeft())&&(x.GetRight()<=GetRight());
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFIntegerRange::JDFIntegerRange(const int GetLeft, const int GetRight, const int xdef):JDFRange<int>(GetLeft,GetRight){
		SetDef(xdef);
	}

	//////////////////////////////////////////////////////////////////////
	
	int JDFIntegerRange::Element(const int i)const{
		int n=NElements();
		if((i>=n)||(i<-n)) throw(JDFException("JDFIntegerRange::Element out of range error"));
		// element(-2) is the second to last element
		if(i<0) return Element(n+i);
		// ascending range
		if (GetRight()>=GetLeft()) return GetLeft()+i;
		// decending range
		return GetLeft()-i;
	}
	
	//////////////////////////////////////////////////////////////////////

	bool JDFIntegerRange::Append(const int x){
		int a=GetRight();
		int i=GetLeft();
		if((a>=i)&&(a+1)==x){
			xMax=x;
			return true;
		}else if((a<=i)&&((a-1)==x)){
			xMax=x;
			return true;
		}
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////
	vint JDFIntegerRange::ToVInt(int maxelem) const {
		vint vi;
		int n = (NElements()<maxelem) ? NElements() : maxelem; // maxelem limits NElements in case of INF 
		
		for (int i=0; i<n; i++) 
		{
			vi.push_back(Element(i));
		}
		return vi;
	}
	

	/**
	* set the default value which is used for negative numbers
	* if xDef==0 (the default) the neg numbers themselves are used
	* @param int xdef the value that -1 will represent in this range
	*/
	void JDFIntegerRange::SetDef(const int xdef) {
		xDef=xdef;
	};
	
	/**
	* Get the default value which is used for negative numbers
	* @return int: the value that -1 will represent in this range
	*/
	int JDFIntegerRange::GetDef(){ 
		return xDef;
	}
	
	/**
	* number of elements that this range represents
	* @return int the number of elements represented by this
	*/
	int JDFIntegerRange::NElements()const {
		// note: defaultXDef == 0
		if(GetRight()<0 || GetLeft()<0)
            return 0;
		return 1 + abs(GetLeft()-GetRight());
	}
	

	/**
	* the value of the left range element
	* this is always the left value, i.e. no check for min or max is done
	* @return int the left value
	*/
	int JDFIntegerRange::GetLeft() const {
		return (xMin<0 && xDef>0) ? xDef+xMin : xMin;
	}
	
	/** 
	* the value of the right range element
	* this is always the right value, i.e. no check for min or max is done
	* @return int the right value
	*/
	int JDFIntegerRange::GetRight() const {
		return (xMax<0 && xDef>0) ? xDef+xMax : xMax;
	}
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	void JDFIntegerRange::init(int x, int y, int xdef){
		IntegerRange::init(x,y);
		SetDef(xdef);
	}

	WString JDFIntegerRange::GetString() const
	{
		return toString();
	}

	WString JDFIntegerRange::toString() const
	{
		if (GetLeft()==GetRight())
        {
			return StringUtil::formatInteger(GetRight());
        }
		return StringUtil::formatInteger(GetLeft()) + " ~ " + StringUtil::formatInteger(GetRight());
	}
	   /**
     * setDefaultDef - sets the preset for xDef, which will be used when constructing an IntegerRange<br>
     * the value represents the index that is one past the end of the list<br>
     * if xdef==0 (the default), the neg numbers themselves are used
     *
     * @param xdef - (int)1 above the value that -1 will represent in this range
     * i.e. the value that -0, were it possible to specify, would represent
     */
	void JDFIntegerRange::setDefaultDef(int xdef)
    {
        m_defaultXDef = xdef;
    }
    
    /**
     * getDefaultDef - gets the preset for xDef, which will be used when constructing an IntegerRange<br>
     * the value represents the index that is one past the end of the list<br>
     * if xdef==0 (the default), the neg numbers themselves are used
     *
     * @return int - (int)1 above the value that -1 will represent in this range
     * i.e. the value that -0, were it possible to specify, would represent
     */
	int JDFIntegerRange::getDefaultDef()
	{
        return m_defaultXDef;
    }

}