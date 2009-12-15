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

 
#if !defined _JDFAutoIDPJobSheet_H_
#define _JDFAutoIDPJobSheet_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFIDPFinishing;
class JDFIDPLayout;
class JDFMediaIntent;
class JDFMediaSource;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoIDPJobSheet : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoIDPJobSheet class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFIDPJobSheet should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoIDPJobSheet : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoIDPJobSheet():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoIDPJobSheet(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoIDPJobSheet &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoIDPJobSheet(){};
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
* Enumeration for attribute SheetOccurrence
*/

	enum EnumSheetOccurrence{SheetOccurrence_Unknown,SheetOccurrence_Always,SheetOccurrence_End,SheetOccurrence_OnError,SheetOccurrence_Slip,SheetOccurrence_Start,SheetOccurrence_Both,SheetOccurrence_None};
/**
* Enumeration for attribute SheetType
*/

	enum EnumSheetType{SheetType_Unknown,SheetType_AccountingSheet,SheetType_ErrorSheet,SheetType_JobSheet,SheetType_SeparatorSheet};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute SheetFormat
*@param WString value: the value to set the attribute to
*/
	virtual void SetSheetFormat(const WString& value);
/**
* Get string attribute SheetFormat
* @return WString the vaue of the attribute ; defaults to Standard
*/
	virtual WString GetSheetFormat() const;
/**
* Typesafe attribute validation of SheetFormat
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSheetFormat(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for SheetOccurrence
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SheetOccurrenceString();
/**
* Enumeration string for enum value
* @param EnumSheetOccurrence value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SheetOccurrenceString(EnumSheetOccurrence value);
/**
* Set attribute SheetOccurrence
* @param EnumSheetOccurrence value the value to set the attribute to
*/
	virtual void SetSheetOccurrence( EnumSheetOccurrence value);

/**
* Typesafe enumerated attribute SheetOccurrence
* @return EnumSheetOccurrencethe enumeration value of the attribute
*/
	virtual EnumSheetOccurrence GetSheetOccurrence() const;

/**
* Typesafe attribute validation of SheetOccurrence
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSheetOccurrence(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for SheetType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SheetTypeString();
/**
* Enumeration string for enum value
* @param EnumSheetType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SheetTypeString(EnumSheetType value);
/**
* Set attribute SheetType
* @param EnumSheetType value the value to set the attribute to
*/
	virtual void SetSheetType( EnumSheetType value);

/**
* Typesafe enumerated attribute SheetType
* @return EnumSheetTypethe enumeration value of the attribute
*/
	virtual EnumSheetType GetSheetType() const;

/**
* Typesafe attribute validation of SheetType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSheetType(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element IDPFinishing
* 
* @param int iSkip number of elements to skip
* @return JDFIDPFinishing The element
*/
	JDFIDPFinishing GetCreateIDPFinishing(int iSkip=0);

/**
* const get element IDPFinishing
* @param int iSkip number of elements to skip
* @return JDFIDPFinishing The element
*/
	JDFIDPFinishing GetIDPFinishing(int iSkip=0)const;
/**
* Append element IDPFinishing
 */
	JDFIDPFinishing AppendIDPFinishing();

/** Get Element IDPLayout
* 
* @param int iSkip number of elements to skip
* @return JDFIDPLayout The element
*/
	JDFIDPLayout GetCreateIDPLayout(int iSkip=0);

/**
* const get element IDPLayout
* @param int iSkip number of elements to skip
* @return JDFIDPLayout The element
*/
	JDFIDPLayout GetIDPLayout(int iSkip=0)const;
/**
* Append element IDPLayout
 */
	JDFIDPLayout AppendIDPLayout();

/** Get Element MediaIntent
* 
* @param int iSkip number of elements to skip
* @return JDFMediaIntent The element
*/
	JDFMediaIntent GetCreateMediaIntent(int iSkip=0);

/**
* const get element MediaIntent
* @param int iSkip number of elements to skip
* @return JDFMediaIntent The element
*/
	JDFMediaIntent GetMediaIntent(int iSkip=0)const;
/**
* Append element MediaIntent
 */
	JDFMediaIntent AppendMediaIntent();
/**
* create inter-resource link to refTarget
* @param JDFMediaIntent& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefMediaIntent(JDFMediaIntent& refTarget);

/** Get Element MediaSource
* 
* @param int iSkip number of elements to skip
* @return JDFMediaSource The element
*/
	JDFMediaSource GetCreateMediaSource(int iSkip=0);

/**
* const get element MediaSource
* @param int iSkip number of elements to skip
* @return JDFMediaSource The element
*/
	JDFMediaSource GetMediaSource(int iSkip=0)const;
/**
* Append element MediaSource
 */
	JDFMediaSource AppendMediaSource();
/**
* create inter-resource link to refTarget
* @param JDFMediaSource& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefMediaSource(JDFMediaSource& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoIDPJobSheet

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoIDPJobSheet_H_
