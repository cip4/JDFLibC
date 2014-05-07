/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2014 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoPackingIntent_H_
#define _JDFAutoPackingIntent_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFIntentResource.h"
#include "jdf/wrapper/AutoJDF/JDFAutoEnumerationSpan.h"
namespace JDF{
class JDFRefElement;
/*
*********************************************************************
class JDFAutoPackingIntent : public JDFIntentResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPackingIntent class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPackingIntent should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPackingIntent : public JDFIntentResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPackingIntent():JDFIntentResource(){};
/**
* copy ctor
*/
	inline JDFAutoPackingIntent(const KElement & other):JDFIntentResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPackingIntent &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPackingIntent(){};
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


/** Get Element BoxedQuantity
* 
* @return JDFIntegerSpan The element
*/
	JDFIntegerSpan GetCreateBoxedQuantity();

/**
* const get element BoxedQuantity
*@return  JDFIntegerSpan The element
*/
	JDFIntegerSpan GetBoxedQuantity()const;
/**
* Append element BoxedQuantity
 * 
*/
	JDFIntegerSpan AppendBoxedQuantity();

/** Get Element BoxShape
* 
* @return JDFShapeSpan The element
*/
	JDFShapeSpan GetCreateBoxShape();

/**
* const get element BoxShape
*@return  JDFShapeSpan The element
*/
	JDFShapeSpan GetBoxShape()const;
/**
* Append element BoxShape
 * 
*/
	JDFShapeSpan AppendBoxShape();

/** Get Element CartonQuantity
* 
* @return JDFIntegerSpan The element
*/
	JDFIntegerSpan GetCreateCartonQuantity();

/**
* const get element CartonQuantity
*@return  JDFIntegerSpan The element
*/
	JDFIntegerSpan GetCartonQuantity()const;
/**
* Append element CartonQuantity
 * 
*/
	JDFIntegerSpan AppendCartonQuantity();

/** Get Element CartonShape
* 
* @return JDFShapeSpan The element
*/
	JDFShapeSpan GetCreateCartonShape();

/**
* const get element CartonShape
*@return  JDFShapeSpan The element
*/
	JDFShapeSpan GetCartonShape()const;
/**
* Append element CartonShape
 * 
*/
	JDFShapeSpan AppendCartonShape();

/** Get Element CartonMaxWeight
* 
* @return JDFNumberSpan The element
*/
	JDFNumberSpan GetCreateCartonMaxWeight();

/**
* const get element CartonMaxWeight
*@return  JDFNumberSpan The element
*/
	JDFNumberSpan GetCartonMaxWeight()const;
/**
* Append element CartonMaxWeight
 * 
*/
	JDFNumberSpan AppendCartonMaxWeight();

/** Get Element CartonStrength
* 
* @return JDFNumberSpan The element
*/
	JDFNumberSpan GetCreateCartonStrength();

/**
* const get element CartonStrength
*@return  JDFNumberSpan The element
*/
	JDFNumberSpan GetCartonStrength()const;
/**
* Append element CartonStrength
 * 
*/
	JDFNumberSpan AppendCartonStrength();

/** Get Element FoldingCatalog
* 
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCreateFoldingCatalog();

/**
* const get element FoldingCatalog
*@return  JDFNameSpan The element
*/
	JDFNameSpan GetFoldingCatalog()const;
/**
* Append element FoldingCatalog
 * 
*/
	JDFNameSpan AppendFoldingCatalog();

/** Get Element PalletCornerBoards
* 
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCreatePalletCornerBoards();

/**
* const get element PalletCornerBoards
*@return  JDFNameSpan The element
*/
	JDFNameSpan GetPalletCornerBoards()const;
/**
* Append element PalletCornerBoards
 * 
*/
	JDFNameSpan AppendPalletCornerBoards();

/** Get Element PalletQuantity
* 
* @return JDFIntegerSpan The element
*/
	JDFIntegerSpan GetCreatePalletQuantity();

/**
* const get element PalletQuantity
*@return  JDFIntegerSpan The element
*/
	JDFIntegerSpan GetPalletQuantity()const;
/**
* Append element PalletQuantity
 * 
*/
	JDFIntegerSpan AppendPalletQuantity();

/** Get Element PalletSize
* 
* @return JDFXYPairSpan The element
*/
	JDFXYPairSpan GetCreatePalletSize();

/**
* const get element PalletSize
*@return  JDFXYPairSpan The element
*/
	JDFXYPairSpan GetPalletSize()const;
/**
* Append element PalletSize
 * 
*/
	JDFXYPairSpan AppendPalletSize();

/** Get Element PalletMaxHeight
* 
* @return JDFNumberSpan The element
*/
	JDFNumberSpan GetCreatePalletMaxHeight();

/**
* const get element PalletMaxHeight
*@return  JDFNumberSpan The element
*/
	JDFNumberSpan GetPalletMaxHeight()const;
/**
* Append element PalletMaxHeight
 * 
*/
	JDFNumberSpan AppendPalletMaxHeight();

/** Get Element PalletMaxWeight
* 
* @return JDFNumberSpan The element
*/
	JDFNumberSpan GetCreatePalletMaxWeight();

/**
* const get element PalletMaxWeight
*@return  JDFNumberSpan The element
*/
	JDFNumberSpan GetPalletMaxWeight()const;
/**
* Append element PalletMaxWeight
 * 
*/
	JDFNumberSpan AppendPalletMaxWeight();

/** Get Element PalletType
* 
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCreatePalletType();

/**
* const get element PalletType
*@return  JDFNameSpan The element
*/
	JDFNameSpan GetPalletType()const;
/**
* Append element PalletType
 * 
*/
	JDFNameSpan AppendPalletType();

/** Get Element PalletWrapping
* 
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCreatePalletWrapping();

/**
* const get element PalletWrapping
*@return  JDFNameSpan The element
*/
	JDFNameSpan GetPalletWrapping()const;
/**
* Append element PalletWrapping
 * 
*/
	JDFNameSpan AppendPalletWrapping();

/** Get Element WrappedQuantity
* 
* @return JDFIntegerSpan The element
*/
	JDFIntegerSpan GetCreateWrappedQuantity();

/**
* const get element WrappedQuantity
*@return  JDFIntegerSpan The element
*/
	JDFIntegerSpan GetWrappedQuantity()const;
/**
* Append element WrappedQuantity
 * 
*/
	JDFIntegerSpan AppendWrappedQuantity();

/** Get Element WrappingMaterial
* 
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCreateWrappingMaterial();

/**
* const get element WrappingMaterial
*@return  JDFNameSpan The element
*/
	JDFNameSpan GetWrappingMaterial()const;
/**
* Append element WrappingMaterial
 * 
*/
	JDFNameSpan AppendWrappingMaterial();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoPackingIntent

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPackingIntent_H_
