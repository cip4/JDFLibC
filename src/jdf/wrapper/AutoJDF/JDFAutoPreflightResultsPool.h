/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2002 The International Cooperation for the Integration of 
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


///////////////////////////////////////////////////////////////////

 
#if !defined _JDFAutoPreflightResultsPool_H_
#define _JDFAutoPreflightResultsPool_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFPool.h"
namespace JDF{
class JDFPreflightCommonPool;
class JDFPreflightCommonPool;
class JDFPreflightCommonPool;
class JDFPreflightCommonPool;
class JDFPreflightCommonPool;
class JDFPreflightCommonPool;
class JDFRefElement;
class vResource;
/*
*********************************************************************
class JDFAutoPreflightResultsPool : public JDFPool

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPreflightResultsPool class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPreflightResultsPool should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPreflightResultsPool : public JDFPool{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPreflightResultsPool():JDFPool(){};
/**
* copy ctor
*/
	inline JDFAutoPreflightResultsPool(const KElement & other):JDFPool(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPreflightResultsPool &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPreflightResultsPool(){};
public:

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid attribute names
*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid element names
*/
	virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;

protected:
/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	virtual WString ValidNodeNames()const;
public:

/**
* Checks if the node is abstract, i.e. is not completely described
* utility used by GetUnknownElements, GetUnknownAttributes
* @return boolean: true, if the node is abstract
*/
	virtual bool IsAbstract()const;


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element ColorsResultsPool
* 
* @param int iSkip number of elements to skip
* @return JDFPreflightCommonPool The element
*/
	JDFPreflightCommonPool GetCreateColorsResultsPool(int iSkip=0);

/**
* const get element ColorsResultsPool
* @param int iSkip number of elements to skip
* @return JDFPreflightCommonPool The element
*/
	JDFPreflightCommonPool GetColorsResultsPool(int iSkip=0)const;
/**
* Append element ColorsResultsPool
 */
	JDFPreflightCommonPool AppendColorsResultsPool();

/** Get Element DocumentResultsPool
* 
* @param int iSkip number of elements to skip
* @return JDFPreflightCommonPool The element
*/
	JDFPreflightCommonPool GetCreateDocumentResultsPool(int iSkip=0);

/**
* const get element DocumentResultsPool
* @param int iSkip number of elements to skip
* @return JDFPreflightCommonPool The element
*/
	JDFPreflightCommonPool GetDocumentResultsPool(int iSkip=0)const;
/**
* Append element DocumentResultsPool
 */
	JDFPreflightCommonPool AppendDocumentResultsPool();

/** Get Element FontsResultsPool
* 
* @param int iSkip number of elements to skip
* @return JDFPreflightCommonPool The element
*/
	JDFPreflightCommonPool GetCreateFontsResultsPool(int iSkip=0);

/**
* const get element FontsResultsPool
* @param int iSkip number of elements to skip
* @return JDFPreflightCommonPool The element
*/
	JDFPreflightCommonPool GetFontsResultsPool(int iSkip=0)const;
/**
* Append element FontsResultsPool
 */
	JDFPreflightCommonPool AppendFontsResultsPool();

/** Get Element FileTypeResultsPool
* 
* @param int iSkip number of elements to skip
* @return JDFPreflightCommonPool The element
*/
	JDFPreflightCommonPool GetCreateFileTypeResultsPool(int iSkip=0);

/**
* const get element FileTypeResultsPool
* @param int iSkip number of elements to skip
* @return JDFPreflightCommonPool The element
*/
	JDFPreflightCommonPool GetFileTypeResultsPool(int iSkip=0)const;
/**
* Append element FileTypeResultsPool
 */
	JDFPreflightCommonPool AppendFileTypeResultsPool();

/** Get Element ImagesResultsPool
* 
* @param int iSkip number of elements to skip
* @return JDFPreflightCommonPool The element
*/
	JDFPreflightCommonPool GetCreateImagesResultsPool(int iSkip=0);

/**
* const get element ImagesResultsPool
* @param int iSkip number of elements to skip
* @return JDFPreflightCommonPool The element
*/
	JDFPreflightCommonPool GetImagesResultsPool(int iSkip=0)const;
/**
* Append element ImagesResultsPool
 */
	JDFPreflightCommonPool AppendImagesResultsPool();

/** Get Element PagesResultsPool
* 
* @param int iSkip number of elements to skip
* @return JDFPreflightCommonPool The element
*/
	JDFPreflightCommonPool GetCreatePagesResultsPool(int iSkip=0);

/**
* const get element PagesResultsPool
* @param int iSkip number of elements to skip
* @return JDFPreflightCommonPool The element
*/
	JDFPreflightCommonPool GetPagesResultsPool(int iSkip=0)const;
/**
* Append element PagesResultsPool
 */
	JDFPreflightCommonPool AppendPagesResultsPool();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoPreflightResultsPool

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPreflightResultsPool_H_
