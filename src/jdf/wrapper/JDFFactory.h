/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2006 The International Cooperation for the Integration of 
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
#if !defined(_JDFFactory_H_)
#define _JDFFactory_H_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFElement.h"

namespace JDF{
	/**
	* Factory class that creates a typed instance of an object from a generic instance
	*/
	class JDF_WRAPPERCORE_EXPORT JDFFactory{
				
	public:
		/**
		* default ctor
		*/
		JDFFactory();
		/**
		* dtor
		*/
		virtual ~JDFFactory();
		/**
		* copy ctor
		*/
		JDFFactory(const JDFElement & other);
		/**
		* copy ctor
		*/
		JDFFactory& operator =(const JDFElement& other);
		/**
		* copy ctor
		*/
		JDFFactory(const JDFFactory & other);
		/**
		* copy ctor
		*/
		JDFFactory& operator =(const JDFFactory& other);
		/**
		* copy ctor
		*/
		JDFFactory(const WString &elementName, const WString &typ,const JDFElement& part=JDFElement());
		/**
		* get a reference to the factory's Element
		* @return JDFElement& the specialized JDFElement
		*/
		inline JDFElement& GetRef(){return *pE;};
		
	protected:
		/**
		* initialize pE according to elm
		* @param elm the generic element that will generate a new specialized element
		* @return a pointer to the newly created specialized class
		*/
		JDFElement* init(const JDFElement &elm);
		/**
		* initialize pE according to a set of nodename and type
		* @param elementName the name of the element that will generate a new specialized element
		* @param typ the name of the type or DataType attribute that will generate a new specialized element
		* @return a pointer to the newly created specialized class
		*/
		JDFElement* init(const WString &elementName, const WString &typ, const JDFElement& other);

		JDFElement* initIntent(const WString &resName, const WString &typ, const JDFElement &part);
		JDFElement* initNode(const WString &resName, const WString &typ, const JDFElement &part);
		JDFElement* initPool(const WString &resName, const WString &typ, const JDFElement &part);
		JDFElement* initSpan(const WString &resName, const WString &typ, const JDFElement &part);

		JDFElement* initRest(const WString &resName, const WString &typ, const JDFElement &part);
		JDFElement* initRestA(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestB(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestC(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestD(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestE(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestF(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestG(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestH(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestI(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestJ(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestL(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestM(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestN(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestO(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestP(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestQ(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestR(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestS(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestT(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestV(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestW(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initRestX(const JDFCh* pcResName, const WString &typ, const JDFElement &part);

		JDFElement* initParams(const WString &resName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsA(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsB(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsC(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsD(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsE(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsF(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsG(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsH(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsI(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsJ(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsK(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsL(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsM(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsN(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsO(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsP(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsQ(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsR(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsS(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsT(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsV(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		JDFElement* initParamsW(const JDFCh* pcResName, const WString &typ, const JDFElement &part);
		

		/**
		* the specialized element
		*/
		JDFElement*pE;
	};
};

#endif // _JDFFactory_H_