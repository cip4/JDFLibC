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


///////////////////////////////////////////////////////////////////

 
#if !defined _JDFAutoCutBlock_H_
#define _JDFAutoCutBlock_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCutBlock : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoCutBlock class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFCutBlock should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoCutBlock : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoCutBlock():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoCutBlock(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoCutBlock &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoCutBlock(){};
public:

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid attribute names
*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

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

/** 
 * Typesafe attribute validation of Class
* @return true if class is valid
*/
virtual bool ValidClass(EnumValidationLevel level) const;

/** 
 * Typesafe initialization
 * @return true if succcessful
*/
virtual bool init();

/**
* Enumeration for attribute BlockType
*/

	enum EnumBlockType{BlockType_Unknown,BlockType_CutBlock,BlockType_SaveBlock,BlockType_TempBlock,BlockType_MarkBlock};
/**
* Enumeration for attribute BlockElementType
*/

	enum EnumBlockElementType{BlockElementType_Unknown,BlockElementType_CutElement,BlockElementType_PunchElement};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute BlockName
*@param WString value: the value to set the attribute to
*/
	virtual void SetBlockName(const WString& value);
/**
* Get string attribute BlockName
* @return WString the vaue of the attribute 
*/
	virtual WString GetBlockName() const;
/**
* Typesafe attribute validation of BlockName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBlockName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BlockSize
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetBlockSize(const JDFXYPair& value);
/**
* Get string attribute BlockSize
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetBlockSize() const;
/**
* Typesafe attribute validation of BlockSize
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBlockSize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BlockSubdivision
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetBlockSubdivision(const JDFXYPair& value);
/**
* Get string attribute BlockSubdivision
* @return JDFXYPair the vaue of the attribute ; defaults to 1 1
*/
	virtual JDFXYPair GetBlockSubdivision() const;
/**
* Typesafe attribute validation of BlockSubdivision
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBlockSubdivision(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BlockTrf
*@param JDFMatrix value: the value to set the attribute to
*/
	virtual void SetBlockTrf(const JDFMatrix& value);
/**
* Get string attribute BlockTrf
* @return JDFMatrix the vaue of the attribute ; defaults to 1 0 0 1 0 0
*/
	virtual JDFMatrix GetBlockTrf() const;
/**
* Typesafe attribute validation of BlockTrf
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBlockTrf(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for BlockType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& BlockTypeString();
/**
* Enumeration string for enum value
* @param EnumBlockType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString BlockTypeString(EnumBlockType value);
/**
* Set attribute BlockType
* @param EnumBlockType value the value to set the attribute to
*/
	virtual void SetBlockType( EnumBlockType value);

/**
* Typesafe enumerated attribute BlockType
* @return EnumBlockTypethe enumeration value of the attribute
*/
	virtual EnumBlockType GetBlockType() const;

/**
* Typesafe attribute validation of BlockType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBlockType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AssemblyIDs
*@param vWString value: the value to set the attribute to
*/
	virtual void SetAssemblyIDs(const vWString& value);
/**
* Get string attribute AssemblyIDs
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetAssemblyIDs() const;
/**
* Typesafe attribute validation of AssemblyIDs
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAssemblyIDs(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BlockElementSize
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetBlockElementSize(const JDFXYPair& value);
/**
* Get string attribute BlockElementSize
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetBlockElementSize() const;
/**
* Typesafe attribute validation of BlockElementSize
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBlockElementSize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for BlockElementType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& BlockElementTypeString();
/**
* Enumeration string for enum value
* @param EnumBlockElementType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString BlockElementTypeString(EnumBlockElementType value);
/**
* Set attribute BlockElementType
* @param EnumBlockElementType value the value to set the attribute to
*/
	virtual void SetBlockElementType( EnumBlockElementType value);

/**
* Typesafe enumerated attribute BlockElementType
* @return EnumBlockElementTypethe enumeration value of the attribute
*/
	virtual EnumBlockElementType GetBlockElementType() const;

/**
* Typesafe attribute validation of BlockElementType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBlockElementType(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoCutBlock

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoCutBlock_H_
