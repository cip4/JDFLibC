/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001 The International Cooperation for the Integration of 
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
/*
// ////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Authors: Dr. Rainer Prosi, Elena Skobchenko
// 
// Revision history:
// created  4.February.2004
//
// JDFDateTimeRange.cpp: interface for the JDFDateTimeRange class.
// used to describe ranges of points in time in resources
//
*/
#include "JDFDateTimeRange.h"


namespace JDF{
	
		//////////////////////////////////////////////////////////////////////
		JDFDateTimeRange::JDFDateTimeRange(){
			init(0,0);
		}

		//////////////////////////////////////////////////////////////////////
		JDFDateTimeRange::JDFDateTimeRange(const JDFDateTimeRange&r){
			init(r.GetLeft(),r.GetRight());
		}

		//////////////////////////////////////////////////////////////////////
		JDFDateTimeRange& JDFDateTimeRange::operator =(const JDFDateTimeRange&r){
			init(r.GetLeft(),r.GetRight());
			return *this;
		}

		//////////////////////////////////////////////////////////////////////
		JDFDateTimeRange::JDFDateTimeRange(const WString& s){
			*this=s;
		}

		//////////////////////////////////////////////////////////////////////
		JDFDateTimeRange& JDFDateTimeRange::operator =(const WString& s){
			vWString vs=s.Tokenize(WString::tilde);
			if(vs.size()==1){
				JDFDate x=(JDFDate)s;
				init(x,x);
			}else if(vs.size()==2){
				WString ms=vs[0];
				JDFDate xmin=(JDFDate)ms.trim();
				ms=vs[1];
				JDFDate xmax=(JDFDate)ms.trim();
				init(xmin,xmax);
			}else{
				throw IllegalArgumentException("JDFDateTimeRange illegal string: "+s);
			}
			return *this;
		}

		//////////////////////////////////////////////////////////////////////
		JDFDateTimeRange::JDFDateTimeRange(const JDFDate & xmin, const JDFDate & xmax){
			init(xmin,xmax);
		}

		//////////////////////////////////////////////////////////////////////
		JDFDateTimeRange::JDFDateTimeRange(const JDFDate& x){
			init(x,x);
		}

		//////////////////////////////////////////////////////////////////////
		JDFDateTimeRange& JDFDateTimeRange::operator =(const JDFDate& x){
			init(x,x);
			return *this;
		}

		//////////////////////////////////////////////////////////////////////
		JDFDateTimeRange::~JDFDateTimeRange(){};
		
		//////////////////////////////////////////////////////////////////////
		bool JDFDateTimeRange::InRange(const JDFDate & x)const{
			return (x>=xMin)&&(x<=xMax);
		}
		
		//////////////////////////////////////////////////////////////////////
		bool JDFDateTimeRange::IsPartOfRange(const JDFDateTimeRange& x)const{
			return (x.xMin>=xMin)&&(x.xMax<=xMax);
		}

		//////////////////////////////////////////////////////////////////////
		WString JDFDateTimeRange::GetString() const {
			if(xMin==xMax){
				return xMin.DateTimeISO();
			}else{
				return xMin.DateTimeISO()+WString(" ~ ")+xMax.DateTimeISO();
			}
		}

		//////////////////////////////////////////////////////////////////////
		JDFDateTimeRange::operator WString(){
			return GetString();
		};

		//////////////////////////////////////////////////////////////////////
		bool JDFDateTimeRange::operator ==(const JDFDateTimeRange& g)const {
			return (xMin==g.xMin)&&(xMax==g.xMax);
		}

		//////////////////////////////////////////////////////////////////////
		bool JDFDateTimeRange::operator !=(const JDFDateTimeRange& g)const {
			return (xMin!=g.xMin)||(xMax!=g.xMax);
		}

		//////////////////////////////////////////////////////////////////////
		JDFDate JDFDateTimeRange::GetLeft() const {
			return xMin;
		};

		//////////////////////////////////////////////////////////////////////
		JDFDate JDFDateTimeRange::GetRight() const {
			return xMax;
		};
		
		//////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////

};// namespace JDF

