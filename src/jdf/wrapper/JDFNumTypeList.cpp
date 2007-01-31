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
/*
// ////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
//
// JDFRange.cpp: interface for the JDFRange class.
// used to describe ranges in resources
// RangeType may be int, double or string
//
*/

#include "jdf/wrapper/JDFNumTypeList.h"
#include "jdf/lang/vWString.h"
#include "jdf/wrappercore/JDFException.h"


namespace JDF{

	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFNumList::JDFNumList(const WString& s, int siz):vdouble(){
		vWString vs=s.Tokenize(WString::blank);
		if(siz<=0) 
			siz=vs.size();
		if(s.empty()){
			for(int i=0;i<siz;i++){
				push_back(0);
			}
		}else if(vs.size()==siz){
			for(int i=0;i<siz;i++){
				push_back(vs[i]);
			}
		}else{
			throw JDFException(L"JDFNumList illegal string: "+s);
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	* empty list initialization
	*/
	JDFNumList::JDFNumList(int siz):vdouble(){
		for(int i=0;i<siz;i++){
			push_back(0);
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFNumList::JDFNumList(const vdouble&m):vdouble(m){
		if (!IsValid())	
			throw JDFException(WString(L"JDFNumList illegal size: ")+WString::valueOf(size()));
	}	

	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFNumList::JDFNumList(const JDFNumList&m):vdouble(m){
		if (!IsValid())	
			throw JDFException(WString(L"JDFNumList illegal size: ")+WString::valueOf(size()));
	}	

	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFNumList& JDFNumList::operator =(const vdouble&m){
		vdouble::operator=(m);
		return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFNumList& JDFNumList::operator =(const JDFNumList&m){
		vdouble::operator=(m);
		return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFNumList& JDFNumList::operator =(const WString&s){
		vWString vs=s.Tokenize(WString::blank);
		int	siz=vs.size();

		clear();
		for(int i=0;i<siz;i++){
			push_back(vs[i]);
		}
		return *this;

	}

	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFNumList::~JDFNumList(){};

	///////////////////////////////////////////////////////////////////////////////////////////////////

	void JDFNumList::Scale(double factor) {
		for(int i=0;i<size();i++) {
			at(i)*=factor;
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////

	void JDFNumList::Offset(double offset) {
		for(int i=0;i<size();i++) {
			at(i)+=offset;
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////

	WString JDFNumList::GetString() const {
		WString s;
		if(!size()) 
			return s;

		for (int i=0;i<size();i++){
			if (i!=0)
				s+=WString::blank;
			WString value;
			WString actValue = WString::valueOf(at(i));
			if (actValue == WString(WString::pINF))
				value = WString::pINFstr;
			else if (actValue == WString(WString::nINF))
				value = WString::nINFstr;
			else if (actValue == WString(WString::pDINF))
				value = WString::pDINFstr;
			else if (actValue == WString(WString::nDINF))
				value = WString::nDINFstr;
			else
				value = WString::valueOf(at(i));
			s+=value;
		}
		return s;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFNumList::operator WString() const{
		return GetString();
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	* default validator
	*/
	bool JDFNumList::IsValid(){
		return true;
	};


	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFIntList::JDFIntList(const WString& s, int siz):vint(){
		vWString vs=s.Tokenize(WString::blank);
		if(siz<=0) 
			siz=vs.size();

		if(vs.size()==siz){
			for(int i=0;i<siz;i++){
				push_back(vs[i]);
			}
		}else{
			throw JDFException(L"JDFIntList illegal string: "+s);
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	* empty list initialization
	*/
	JDFIntList::JDFIntList(int siz):vint(){
		for(int i=0;i<siz;i++){
			push_back(0);
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFIntList::JDFIntList(const vint&m):vint(m){
		if (!IsValid())	
			throw JDFException(WString(L"JDFIntList illegal size: ")+WString::valueOf(size()));
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFIntList::JDFIntList(const JDFIntList&m):vint(m){
		if (!IsValid())	
			throw JDFException(WString(L"JDFIntList illegal size: ")+WString::valueOf(size()));
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFIntList& JDFIntList::operator =(const vint&m){
		vint::operator=(m);
		return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFIntList& JDFIntList::operator =(const JDFIntList&m){
		vint::operator=(m);
		return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFIntList& JDFIntList::operator =(const WString&s){
		vWString vs=s.Tokenize(WString::blank);
		int	siz=vs.size();

		clear();
		for(int i=0;i<siz;i++){
			push_back(vs[i]);
		}
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFIntList::~JDFIntList(){};

	///////////////////////////////////////////////////////////////////////////////////////////////////

	void JDFIntList::Scale(int factor) {
		for(int i=0;i<size();i++) {
			at(i)*=factor;
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////

	void JDFIntList::Offset(int offset) {
		for(int i=0;i<size();i++) {
			at(i)+=offset;
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////

	WString JDFIntList::GetString() const {
		WString s;
		if(!size()) 
			return s;

		for (int i=0;i<size();i++){
			if (i!=0)
				s+=WString::blank;
			WString value;
			WString actValue = WString::valueOf(at(i));
			if (actValue == WString(WString::pINF))
				value = WString::pINFstr;
			else if (actValue == WString(WString::nINF))
				value = WString::nINFstr;
			else
				value = WString::valueOf(at(i));
			s+=value;
		}
		return s;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFIntList::operator WString() const{
		return GetString();
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	* default validator
	*/
	bool JDFIntList::IsValid(){
		return true;
	};
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFIntegerList& JDFIntegerList::operator =(const JDFIntegerList&m){
		vint::operator=(m);
		return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFIntegerList& JDFIntegerList::operator =(const vint&m){
		vint::operator=(m);
		return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFIntegerList& JDFIntegerList::operator =(const WString&s){
		vWString vs=s.Tokenize(WString::blank);
		int	siz=vs.size();

		clear();
		for(int i=0;i<siz;i++){
			push_back(vs[i]);
		}
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	bool JDFIntegerList::IsValid(){
		return true;
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFIntegerList::JDFIntegerList(int i):JDFIntList(0){
		push_back(i);
	};
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFNumberList& JDFNumberList::operator =(const vdouble&m){
		vdouble::operator=(m);
		return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFNumberList& JDFNumberList::operator =(const JDFNumberList&m){
		vdouble::operator=(m);
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFNumberList& JDFNumberList::operator =(const WString&s){
		vWString vs=s.Tokenize(WString::blank);
		int	siz=vs.size();

		clear();
		for(int i=0;i<siz;i++){
			push_back(vs[i]);
		}
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////

	bool JDFNumberList::IsValid(){
		return true;
	};
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFMatrix& JDFMatrix::operator =(const vdouble&m){
		vdouble::operator=(m);
		if(!IsValid()) 
			throw JDFException("JDFMatrix bad copy");
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFMatrix& JDFMatrix::operator =(const JDFMatrix&m){
		vdouble::operator=(m);
		if(!IsValid()) 
			throw JDFException("JDFMatrix bad copy");
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFMatrix& JDFMatrix::operator =(const WString&m){
		JDFNumList::operator=(m.empty()?L"0 0 0 0 0 0":m);
		if(!IsValid()) 
			throw JDFException("JDFMatrix bad copy");
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	* default validator
	*/
	bool JDFMatrix::IsValid(){
		return size()==6;
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFMatrix::JDFMatrix(double a, double b, double c, double d, double Tx, double Ty ):JDFNumList(6){
		at(0)=a; at(1)=b; at(2)=c; at(3)=d; at(4)=Tx; at(5)=Ty;
	};

	/**
	* get a 
	* @return double a 
	*/
	double JDFMatrix::GetA()const{
		return at(0);
	}
	/**
	* get b
	* @return double b 
	*/
	double JDFMatrix::GetB()const{
		return at(1);
	}
	/**
	* get c
	* @return double c 
	*/
	double JDFMatrix::GetC()const{
		return at(2);
	}
	/**
	* get d
	* @return double d
	*/
	double JDFMatrix::GetD()const{
		return at(3);
	}
	/**
	* get Tx
	* @return double Tx 
	*/
	double JDFMatrix::GetTx()const{
		return at(4);
	}
	/**
	* get Ty
	* @return double Ty
	*/
	double JDFMatrix::GetTy()const{
		return at(5);
	}

	/**
	* set a
	* @return double a 
	*/
	void JDFMatrix::SetA(double a){
		at(0)=a;
	}
	/**
	* set b
	* @return double b 
	*/
	void JDFMatrix::SetB(double b){
		at(1)=b;
	}
	/**
	* set c
	* @return double c 
	*/
	void JDFMatrix::SetC(double c){
		at(2)=c;
	}
	/**
	* set d
	* @return double d 
	*/
	void JDFMatrix::SetD(double d){
		at(3)=d;
	}
	/**
	* set Tx
	* @return double Tx 
	*/
	void JDFMatrix::SetTx(double Tx){
		at(4)=Tx;
	}
	/**
	* set Ty
	* @return double Ty 
	*/
	void JDFMatrix::SetTy(double Ty){
		at(5)=Ty;
	}

	/**
	* equality operator
	* @param JDFMatrix & m: the JDFMatrix object to compare to
	* @return bool true if 'this' and 'm' are equal
	*/
	bool JDFMatrix::operator ==(const JDFMatrix & m)const{
		return at(0)==m.GetA()&&at(1)==m.GetB()&&at(2)==m.GetC()&&at(3)==m.GetD()&&at(4)==m.GetTx()&&at(5)==m.GetTy();
	}

	/**
	* equality operator
	* @param JDFMatrix & m: the JDFMatrix object to compare to
	* @return bool true if 'this' and 'm' are not equal
	*/
	bool JDFMatrix::operator !=(const JDFMatrix & m)const{
		return at(0)!=m.GetA()||at(1)!=m.GetB()||at(2)!=m.GetC()||at(3)!=m.GetD()||at(4)!=m.GetTx()||at(5)!=m.GetTy();
	}


	/**
	* Tests, if the defined 'test' matrix equal 'this' matrix +/- Tolerance
	*
	* @param JDFMatrix test: the matrix to test
	* @param double nT: negative tolerance
	* @param double pT: positive tolerance
	* @return bool: true if 'this' and 'test' +/- Tolerance are equal
	*/
	bool JDFMatrix::FitsTolerance(const JDFMatrix& test, double nT, double pT) const{

		for (int i=0; i<6; i++)
		{	
			double dx = at(i)-test.at(i);

			if ( (dx<-nT)||(dx>pT) )
				return false;
		}
		return true;

	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFRectangle& JDFRectangle::operator =(const vdouble&m){
		vdouble::operator=(m);
		if(!IsValid()) 
			throw JDFException("JDFRectangle bad copy");
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFRectangle& JDFRectangle::operator =(const JDFRectangle&m){
		vdouble::operator=(m);
		if(!IsValid()) 
			throw JDFException("JDFRectangle bad copy");
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFRectangle& JDFRectangle::operator =(const WString&m){
		JDFNumList::operator=(m.empty()?L"0 0 0 0":m);
		if(!IsValid()) 
			throw JDFException("JDFRectangle bad copy");
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////

	bool JDFRectangle::IsValid(){
		return size()==4;
	};
	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFRectangle::JDFRectangle(double llx, double lly, double urx, double ury):JDFNumList(4){
		at(0)=llx; at(1)=lly; at(2)=urx; at(3)=ury;
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	* get Llx 
	* @return double llx 
	*/
	double JDFRectangle::GetLlx()const{
		return at(0);
	}
	/**
	* get Lly
	* @return double lly 
	*/
	double JDFRectangle::GetLly()const{
		return at(1);
	}
	/**
	* get Urx
	* @return double urx 
	*/
	double JDFRectangle::GetUrx()const{
		return at(2);
	}
	/**
	* get Ury
	* @return double ury 
	*/
	double JDFRectangle::GetUry()const{
		return at(3);
	}
	/**
	* set Llx 
	* @return double llx 
	*/
	void JDFRectangle::SetLlx(double llx){
		at(0)=llx;
	}
	/**
	* set Lly
	* @return double lly 
	*/
	void JDFRectangle::SetLly(double lly){
		at(1)=lly;
	}
	/**
	* set Urx
	* @return double urx 
	*/
	void JDFRectangle::SetUrx(double urx){
		at(2)=urx;
	}
	/**
	* set Ury
	* @return double urx 
	*/
	void JDFRectangle::SetUry(double urx){
		at(3)=urx;
	}


	/**
	* equality operator
	* @param JDFRectangle & r: the JDFRectangle object to compare to
	* @return bool true if 'this' and 'r' are equal
	*/
	bool JDFRectangle::operator ==(const JDFRectangle & r)const{
		return at(0)==r.GetLlx()&&at(1)==r.GetLly()&&at(2)==r.GetUrx()&&at(3)==r.GetUry();
	}

	/**
	* equality operator
	* @param JDFRectangle & r: the JDFRectangle object to compare to
	* @return bool true if 'this' and 'r' are not equal
	*/
	bool JDFRectangle::operator !=(const JDFRectangle & r)const{
		return at(0)!=r.GetLlx()||at(1)!=r.GetLly()||at(2)!=r.GetUrx()||at(3)!=r.GetUry();
	}

	/**
	* equality operator
	* @param JDFRectangle & r: the JDFRectangle object to compare to
	* @return bool true if 'this' >= 'r'
	*/
	bool JDFRectangle::operator >=(const JDFRectangle & r)const{
		return at(0)<=r.GetLlx()&&at(1)<=r.GetLly()&&at(2)>=r.GetUrx()&&at(3)>=r.GetUry();
	}		

	/**
	* equality operator
	* @param JDFRectangle & r: the JDFRectangle object to compare to
	* @return bool true if 'this' <= 'r'
	*/
	bool JDFRectangle::operator <=(const JDFRectangle & r)const{
		return at(0)>=r.GetLlx()&&at(1)>=r.GetLly()&&at(2)<=r.GetUrx()&&at(3)<=r.GetUry();
	}

	/**
	* equality operator
	* @param JDFRectangle & r: the JDFRectangle object to compare to
	* @return bool true if 'this' > 'r'
	*/
	bool JDFRectangle::operator >(const JDFRectangle & r)const{
		return !(*this==r)&&at(0)<=r.GetLlx()&&at(1)<=r.GetLly()&&at(2)>=r.GetUrx()&&at(3)>=r.GetUry();
	}
	/**
	* equality operator
	* @param JDFRectangle & r: the JDFRectangle object to compare to
	* @return bool true if 'this' < 'r'
	*/
	bool JDFRectangle::operator <(const JDFRectangle & r)const{
		return !(*this==r)&&at(0)>=r.GetLlx()&&at(1)>=r.GetLly()&&at(2)<=r.GetUrx()&&at(3)<=r.GetUry();
	}	
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////


	JDFCMYKColor& JDFCMYKColor::operator =(const vdouble&m){
		vdouble::operator=(m);
		if(!IsValid()) 
			throw JDFException("JDFCMYKColor bad copy");
		return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFCMYKColor& JDFCMYKColor::operator =(const JDFCMYKColor&m){
		vdouble::operator=(m);
		if(!IsValid()) 
			throw JDFException("JDFCMYKColor bad copy");
		return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFCMYKColor& JDFCMYKColor::operator =(const WString&m){
		JDFNumList::operator=(m.empty()?L"0 0 0":m);
		if(!IsValid()) 
			throw JDFException("JDFCMYKColor bad copy");
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	bool JDFCMYKColor::IsValid(){
		return size()==4;
	};
	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFCMYKColor::JDFCMYKColor(double c, double m, double y, double k):JDFNumList(4){
		at(0)=c; at(1)=m; at(2)=y; at(3)=k;
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFShape& JDFShape::operator =(const vdouble&m){
		vdouble::operator=(m);
		if(!IsValid()) 
			throw JDFException("JDFShape bad copy");
		return *this;
	}

	JDFShape& JDFShape::operator =(const JDFShape&m){
		vdouble::operator=(m);
		if(!IsValid()) 
			throw JDFException("JDFShape bad copy");
		return *this;
	}


	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFShape& JDFShape::operator =(const WString&m){
		JDFNumList::operator=(m.empty()?L"0 0 0":m);
		if(!IsValid()) 
			throw JDFException("JDFShape bad copy");
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	bool JDFShape::IsValid(){
		return size()==3;
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFShape::JDFShape(double a, double b, double c):JDFNumList(3){
		at(0)=a; at(1)=b; at(2)=c; 
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	* get A 
	* @return double a 
	*/
	double JDFShape::GetA()const{
		return at(0);
	}
	/**
	* get B
	* @return double b 
	*/
	double JDFShape::GetB()const{
		return at(1);
	}
	/**
	* get C
	* @return double c 
	*/
	double JDFShape::GetC()const{
		return at(2);
	}
	/**
	* set A 
	* @return double a 
	*/
	void JDFShape::SetA(double a){
		at(0)=a;
	}
	/**
	* set B
	* @return double b 
	*/
	void JDFShape::SetB(double b){
		at(1)=b;
	}
	/**
	* set C
	* @return double c 
	*/
	void JDFShape::SetC(double c){
		at(2)=c;
	}


	/**
	* equality operator
	* @param JDFShape & abc: the JDFShape object to compare to
	* @return bool true if this and abc are equal
	*/
	bool JDFShape::operator ==(const JDFShape & abc)const{
		return at(0)==abc.GetA()&&at(1)==abc.GetB()&&at(2)==abc.GetC();
	}

	/**
	* equality operator
	* @param JDFShape & abc: the JDFShape object to compare to
	* @return bool true if this and abc are not equal
	*/
	bool JDFShape::operator !=(const JDFShape & abc)const{
		return at(0)!=abc.GetA()||at(1)!=abc.GetB()||at(2)!=abc.GetC();
	}

	/**
	* equality operator
	* @param JDFShape & abc: the JDFShape object to compare to
	* @return bool true if this >= abc
	*/
	bool JDFShape::operator >=(const JDFShape & abc)const{
		return at(0)>=abc.GetA()&&at(1)>=abc.GetB()&&at(2)>=abc.GetC();
	}		

	/**
	* equality operator
	* @param JDFShape & abc: the JDFShape object to compare to
	* @return bool true if this <= abc
	*/
	bool JDFShape::operator <=(const JDFShape & abc)const{
		return at(0)<=abc.GetA()&&at(1)<=abc.GetB()&&at(2)<=abc.GetC();
	}

	/**
	* equality operator
	* @param JDFShape & abc: the JDFShape object to compare to
	* @return bool true if this > abc
	*/
	bool JDFShape::operator >(const JDFShape & abc)const{
		return (!(*this==abc))&&at(0)>=abc.GetA()&&at(1)>=abc.GetB()&&at(2)>=abc.GetC();
	}
	/**
	* equality operator
	* @param JDFShape & abc: the JDFShape object to compare to
	* @return bool true if this < abc
	*/
	bool JDFShape::operator <(const JDFShape & abc)const{
		return (!(*this==abc))&&at(0)<=abc.GetA()&&at(1)<=abc.GetB()&&at(2)<=abc.GetC();
	}	
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFRGBColor& JDFRGBColor::operator =(const vdouble&m){
		vdouble::operator=(m);
		if(!IsValid()) 
			throw JDFException("JDFRGBColor bad copy");
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFRGBColor& JDFRGBColor::operator =(const JDFRGBColor&m){
		vdouble::operator=(m);
		if(!IsValid()) 
			throw JDFException("JDFRGBColor bad copy");
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFRGBColor& JDFRGBColor::operator =(const WString&m){
		JDFNumList::operator=(m.empty()?L"0 0 0":m);
		if(!IsValid()) 
			throw JDFException("JDFRGBColor bad copy");
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	bool JDFRGBColor::IsValid(){
		return size()==3;
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFRGBColor::JDFRGBColor(double r, double g, double b):JDFNumList(3){
		at(0)=r; at(1)=g; at(2)=b; 
	};
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFLabColor& JDFLabColor::operator =(const vdouble&m){
		vdouble::operator=(m);
		if(!IsValid()) 
			throw JDFException("JDFLabColor bad copy");
		return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFLabColor& JDFLabColor::operator =(const JDFLabColor&m){
		vdouble::operator=(m);
		if(!IsValid()) 
			throw JDFException("JDFLabColor bad copy");
		return *this;
	}


	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFLabColor& JDFLabColor::operator =(const WString&m){
		JDFNumList::operator=(m.empty()?L"0 0 0":m);
		if(!IsValid()) 
			throw JDFException("JDFLabColor bad copy");
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	bool JDFLabColor::IsValid(){
		return size()==3;
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFLabColor::JDFLabColor(double L, double a, double b):JDFNumList(3){
		at(0)=L; at(1)=a; at(2)=b; 
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFXYPair& JDFXYPair::operator =(const vdouble&m){
		vdouble::operator=(m);
		if(!IsValid()) 
			throw JDFException("JDFXYPair bad copy");
		return *this;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFXYPair& JDFXYPair::operator =(const JDFXYPair&m){
		vdouble::operator=(m);
		if(!IsValid()) 
			throw JDFException("JDFXYPair bad copy");
		return *this;
	}


	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFXYPair& JDFXYPair::operator =(const WString&m){
		JDFNumList::operator=(m.empty()?L"0 0":m);
		if(!IsValid()) 
			throw JDFException("JDFXYPair bad copy");
		return *this;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	bool JDFXYPair::IsValid(){
		return size()==2;
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	JDFXYPair::JDFXYPair(double x, double y):JDFNumList(2){
		at(0)=x; at(1)=y;
	};
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	* get X 
	* @return double x 
	*/
	double JDFXYPair::GetX()const{
		return at(0);
	}
	/**
	* get y
	* @return double y 
	*/
	double JDFXYPair::GetY()const{
		return at(1);
	}
	/**
	* set X 
	* @return double x 
	*/
	void JDFXYPair::SetX(double x){
		at(0)=x;
	}
	/**
	* set y
	* @return double y 
	*/
	void JDFXYPair::SetY(double y){
		at(1)=y;
	}

	/**
	* equality operator
	* @param JDFXYPair xy the pair to compare to
	* @return bool true if both are equal
	*/
	bool JDFXYPair::operator ==(const JDFXYPair&xy)const{
		return at(0)==xy.GetX()&&at(1)==xy.GetY();
	}
	/**
	* equality operator
	* @param JDFXYPair xy the pair to compare to
	* @return bool true if both are not equal
	*/
	bool JDFXYPair::operator !=(const JDFXYPair&xy)const{
		return at(0)!=xy.GetX()||at(1)!=xy.GetY();
	}
	/**
	* equality operator
	* @param JDFXYPair xy the pair to compare to
	* @return bool true if this >= xy
	*/
	bool JDFXYPair::operator >=(const JDFXYPair&xy)const{
		return at(0)>=xy.GetX()&&at(1)>=xy.GetY();
	}		
	/**
	* equality operator
	* @param JDFXYPair xy the pair to compare to
	* @return bool true if this <= xy
	*/
	bool JDFXYPair::operator <=(const JDFXYPair&xy)const{
		return at(0)<=xy.GetX()&&at(1)<=xy.GetY();
	}		
	/**
	* equality operator
	* @param JDFXYPair xy the pair to compare to
	* @return bool true if this > xy
	*/
	bool JDFXYPair::operator >(const JDFXYPair&xy)const{
		return !(*this==xy)&&at(0)>=xy.GetX()&&at(1)>=xy.GetY();
	}
	/**
	* equality operator
	* @param JDFXYPair xy the pair to compare to
	* @return bool true if this < xy
	*/
	bool JDFXYPair::operator <(const JDFXYPair&xy)const{
		return !(*this==xy)&&at(0)<=xy.GetX()&&at(1)<=xy.GetY();
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
};// namespace JDF

