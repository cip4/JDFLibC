/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2009 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoAssembly_H_
#define _JDFAutoAssembly_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFAssemblySection;
class JDFPageList;
class JDFPageAssignedList;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoAssembly : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoAssembly class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFAssembly should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoAssembly : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoAssembly():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoAssembly(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoAssembly &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoAssembly(){};
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
* Enumeration for attribute JogSide
*/

	enum EnumJogSide{JogSide_Unknown,JogSide_Left,JogSide_Right,JogSide_Top,JogSide_Bottom,JogSide_None};
/**
* Enumeration for attribute Order
*/

	enum EnumOrder{Order_Unknown,Order_Collecting,Order_Gathering,Order_None,Order_List};
/**
* Enumeration for attribute BindingSide
*/

	enum EnumBindingSide{BindingSide_Unknown,BindingSide_Left,BindingSide_Right,BindingSide_Top,BindingSide_Bottom};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for JogSide
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& JogSideString();
/**
* Enumeration string for enum value
* @param EnumJogSide value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString JogSideString(EnumJogSide value);
/**
* Set attribute JogSide
* @param EnumJogSide value the value to set the attribute to
*/
	virtual void SetJogSide( EnumJogSide value);

/**
* Typesafe enumerated attribute JogSide; defaults to Top
* @return EnumJogSidethe enumeration value of the attribute
*/
	virtual EnumJogSide GetJogSide() const;

/**
* Typesafe attribute validation of JogSide
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidJogSide(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Order
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& OrderString();
/**
* Enumeration string for enum value
* @param EnumOrder value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString OrderString(EnumOrder value);
/**
* Set attribute Order
* @param EnumOrder value the value to set the attribute to
*/
	virtual void SetOrder( EnumOrder value);

/**
* Typesafe enumerated attribute Order; defaults to Gathering
* @return EnumOrderthe enumeration value of the attribute
*/
	virtual EnumOrder GetOrder() const;

/**
* Typesafe attribute validation of Order
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidOrder(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for BindingSide
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& BindingSideString();
/**
* Enumeration string for enum value
* @param EnumBindingSide value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString BindingSideString(EnumBindingSide value);
/**
* Set attribute BindingSide
* @param EnumBindingSide value the value to set the attribute to
*/
	virtual void SetBindingSide( EnumBindingSide value);

/**
* Typesafe enumerated attribute BindingSide; defaults to Left
* @return EnumBindingSidethe enumeration value of the attribute
*/
	virtual EnumBindingSide GetBindingSide() const;

/**
* Typesafe attribute validation of BindingSide
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBindingSide(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AssemblyID
*@param WString value: the value to set the attribute to
*/
	virtual void SetAssemblyID(const WString& value);
/**
* Get string attribute AssemblyID
* @return WString the vaue of the attribute 
*/
	virtual WString GetAssemblyID() const;
/**
* Typesafe attribute validation of AssemblyID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAssemblyID(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	virtual void SetJobID(const WString& value);
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	virtual WString GetJobID() const;
/**
* Typesafe attribute validation of JobID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidJobID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PhysicalSection
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetPhysicalSection(const JDFIntegerList& value);
/**
* Get string attribute PhysicalSection
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetPhysicalSection() const;
/**
* Typesafe attribute validation of PhysicalSection
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPhysicalSection(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element AssemblySection
* 
* @param int iSkip number of elements to skip
* @return JDFAssemblySection The element
*/
	JDFAssemblySection GetCreateAssemblySection(int iSkip=0);

/**
* const get element AssemblySection
* @param int iSkip number of elements to skip
* @return JDFAssemblySection The element
*/
	JDFAssemblySection GetAssemblySection(int iSkip=0)const;
/**
* Append element AssemblySection
 */
	JDFAssemblySection AppendAssemblySection();

/** Get Element PageList
* 
* @return JDFPageList The element
*/
	JDFPageList GetCreatePageList();

/**
* const get element PageList
*@return  JDFPageList The element
*/
	JDFPageList GetPageList()const;
/**
* Append element PageList
 * 
*/
	JDFPageList AppendPageList();
/**
* create inter-resource link to refTarget
* @param JDFPageList& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefPageList(JDFPageList& refTarget);

/** Get Element PageAssignedList
* 
* @param int iSkip number of elements to skip
* @return JDFPageAssignedList The element
*/
	JDFPageAssignedList GetCreatePageAssignedList(int iSkip=0);

/**
* const get element PageAssignedList
* @param int iSkip number of elements to skip
* @return JDFPageAssignedList The element
*/
	JDFPageAssignedList GetPageAssignedList(int iSkip=0)const;
/**
* Append element PageAssignedList
 */
	JDFPageAssignedList AppendPageAssignedList();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoAssembly

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoAssembly_H_
