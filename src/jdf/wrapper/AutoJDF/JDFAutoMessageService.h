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

 
#if !defined _JDFAutoMessageService_H_
#define _JDFAutoMessageService_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
#include "jdf/wrapper/JDFState.h"
#include "jdf/wrapper/JDFBooleanState.h"
#include "jdf/wrapper/JDFDateTimeState.h"
#include "jdf/wrapper/JDFDurationState.h"
#include "jdf/wrapper/JDFEnumerationState.h"
#include "jdf/wrapper/JDFIntegerState.h"
#include "jdf/wrapper/JDFMatrixState.h"
#include "jdf/wrapper/JDFNameState.h"
#include "jdf/wrapper/JDFNumberState.h"
#include "jdf/wrapper/JDFPDFPathState.h"
#include "jdf/wrapper/JDFRectangleState.h"
#include "jdf/wrapper/JDFShapeState.h"
#include "jdf/wrapper/JDFStringState.h"
#include "jdf/wrapper/JDFXYPairState.h"
namespace JDF{
class JDFActionPool;
class JDFDevCapPool;
class JDFDevCaps;
class JDFModulePool;
class JDFTestPool;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoMessageService : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoMessageService class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFMessageService should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoMessageService : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoMessageService():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoMessageService(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoMessageService &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoMessageService(){};
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
* Enumeration for attribute ChannelMode
*/

	enum EnumChannelMode{ChannelMode_Unknown,ChannelMode_FireAndForget,ChannelMode_Reliable};
/**
* Enumeration for attribute JMFRole
*/

	enum EnumJMFRole{JMFRole_Unknown,JMFRole_Receiver,JMFRole_Sender};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute Acknowledge
*@param bool value: the value to set the attribute to
*/
	virtual void SetAcknowledge(bool value);
/**
* Get bool attribute Acknowledge
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetAcknowledge() const;
/**
* Typesafe attribute validation of Acknowledge
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAcknowledge(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ChannelMode
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ChannelModeString();
/**
* Enumeration string for enum value
* @param EnumChannelMode value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ChannelModeString(EnumChannelMode value);
/**
* Set attribute ChannelMode
* @param EnumChannelMode value the value to set the attribute to
*/
	virtual void SetChannelMode( EnumChannelMode value);

/**
* Typesafe enumerated attribute ChannelMode
* @return EnumChannelModethe enumeration value of the attribute
*/
	virtual EnumChannelMode GetChannelMode() const;

/**
* Typesafe attribute validation of ChannelMode
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidChannelMode(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Command
*@param bool value: the value to set the attribute to
*/
	virtual void SetCommand(bool value);
/**
* Get bool attribute Command
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetCommand() const;
/**
* Typesafe attribute validation of Command
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCommand(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute GenericAttributes
*@param vWString value: the value to set the attribute to
*/
	virtual void SetGenericAttributes(const vWString& value);
/**
* Get string attribute GenericAttributes
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetGenericAttributes() const;
/**
* Typesafe attribute validation of GenericAttributes
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGenericAttributes(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for JMFRole
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& JMFRoleString();
/**
* Enumeration string for enum value
* @param EnumJMFRole value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString JMFRoleString(EnumJMFRole value);
/**
* Set attribute JMFRole
* @param EnumJMFRole value the value to set the attribute to
*/
	virtual void SetJMFRole( EnumJMFRole value);

/**
* Typesafe enumerated attribute JMFRole
* @return EnumJMFRolethe enumeration value of the attribute
*/
	virtual EnumJMFRole GetJMFRole() const;

/**
* Typesafe attribute validation of JMFRole
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidJMFRole(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Persistent
*@param bool value: the value to set the attribute to
*/
	virtual void SetPersistent(bool value);
/**
* Get bool attribute Persistent
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetPersistent() const;
/**
* Typesafe attribute validation of Persistent
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPersistent(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Query
*@param bool value: the value to set the attribute to
*/
	virtual void SetQuery(bool value);
/**
* Get bool attribute Query
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetQuery() const;
/**
* Typesafe attribute validation of Query
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidQuery(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Registration
*@param bool value: the value to set the attribute to
*/
	virtual void SetRegistration(bool value);
/**
* Get bool attribute Registration
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetRegistration() const;
/**
* Typesafe attribute validation of Registration
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRegistration(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Signal
*@param bool value: the value to set the attribute to
*/
	virtual void SetSignal(bool value);
/**
* Get bool attribute Signal
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetSignal() const;
/**
* Typesafe attribute validation of Signal
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSignal(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Type
*@param WString value: the value to set the attribute to
*/
	virtual void SetType(const WString& value);
/**
* Get string attribute Type
* @return WString the vaue of the attribute 
*/
	virtual WString GetType() const;
/**
* Typesafe attribute validation of Type
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute URLSchemes
*@param vWString value: the value to set the attribute to
*/
	virtual void SetURLSchemes(const vWString& value);
/**
* Get string attribute URLSchemes
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetURLSchemes() const;
/**
* Typesafe attribute validation of URLSchemes
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidURLSchemes(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element ActionPool
* 
* @return JDFActionPool The element
*/
	JDFActionPool GetCreateActionPool();

/**
* const get element ActionPool
*@return  JDFActionPool The element
*/
	JDFActionPool GetActionPool()const;
/**
* Append element ActionPool
 * 
*/
	JDFActionPool AppendActionPool();

/** Get Element DevCapPool
* 
* @return JDFDevCapPool The element
*/
	JDFDevCapPool GetCreateDevCapPool();

/**
* const get element DevCapPool
*@return  JDFDevCapPool The element
*/
	JDFDevCapPool GetDevCapPool()const;
/**
* Append element DevCapPool
 * 
*/
	JDFDevCapPool AppendDevCapPool();

/** Get Element DevCaps
* 
* @param int iSkip number of elements to skip
* @return JDFDevCaps The element
*/
	JDFDevCaps GetCreateDevCaps(int iSkip=0);

/**
* const get element DevCaps
* @param int iSkip number of elements to skip
* @return JDFDevCaps The element
*/
	JDFDevCaps GetDevCaps(int iSkip=0)const;
/**
* Append element DevCaps
 */
	JDFDevCaps AppendDevCaps();

/** Get Element ModulePool
* 
* @return JDFModulePool The element
*/
	JDFModulePool GetCreateModulePool();

/**
* const get element ModulePool
*@return  JDFModulePool The element
*/
	JDFModulePool GetModulePool()const;
/**
* Append element ModulePool
 * 
*/
	JDFModulePool AppendModulePool();

/** Get Element BooleanState
* 
* @param int iSkip number of elements to skip
* @return JDFBooleanState The element
*/
	JDFBooleanState GetCreateBooleanState(int iSkip=0);

/**
* const get element BooleanState
* @param int iSkip number of elements to skip
* @return JDFBooleanState The element
*/
	JDFBooleanState GetBooleanState(int iSkip=0)const;
/**
* Append element BooleanState
 */
	JDFBooleanState AppendBooleanState();

/** Get Element DateTimeState
* 
* @param int iSkip number of elements to skip
* @return JDFDateTimeState The element
*/
	JDFDateTimeState GetCreateDateTimeState(int iSkip=0);

/**
* const get element DateTimeState
* @param int iSkip number of elements to skip
* @return JDFDateTimeState The element
*/
	JDFDateTimeState GetDateTimeState(int iSkip=0)const;
/**
* Append element DateTimeState
 */
	JDFDateTimeState AppendDateTimeState();

/** Get Element DurationState
* 
* @param int iSkip number of elements to skip
* @return JDFDurationState The element
*/
	JDFDurationState GetCreateDurationState(int iSkip=0);

/**
* const get element DurationState
* @param int iSkip number of elements to skip
* @return JDFDurationState The element
*/
	JDFDurationState GetDurationState(int iSkip=0)const;
/**
* Append element DurationState
 */
	JDFDurationState AppendDurationState();

/** Get Element EnumerationState
* 
* @param int iSkip number of elements to skip
* @return JDFEnumerationState The element
*/
	JDFEnumerationState GetCreateEnumerationState(int iSkip=0);

/**
* const get element EnumerationState
* @param int iSkip number of elements to skip
* @return JDFEnumerationState The element
*/
	JDFEnumerationState GetEnumerationState(int iSkip=0)const;
/**
* Append element EnumerationState
 */
	JDFEnumerationState AppendEnumerationState();

/** Get Element IntegerState
* 
* @param int iSkip number of elements to skip
* @return JDFIntegerState The element
*/
	JDFIntegerState GetCreateIntegerState(int iSkip=0);

/**
* const get element IntegerState
* @param int iSkip number of elements to skip
* @return JDFIntegerState The element
*/
	JDFIntegerState GetIntegerState(int iSkip=0)const;
/**
* Append element IntegerState
 */
	JDFIntegerState AppendIntegerState();

/** Get Element MatrixState
* 
* @param int iSkip number of elements to skip
* @return JDFMatrixState The element
*/
	JDFMatrixState GetCreateMatrixState(int iSkip=0);

/**
* const get element MatrixState
* @param int iSkip number of elements to skip
* @return JDFMatrixState The element
*/
	JDFMatrixState GetMatrixState(int iSkip=0)const;
/**
* Append element MatrixState
 */
	JDFMatrixState AppendMatrixState();

/** Get Element NameState
* 
* @param int iSkip number of elements to skip
* @return JDFNameState The element
*/
	JDFNameState GetCreateNameState(int iSkip=0);

/**
* const get element NameState
* @param int iSkip number of elements to skip
* @return JDFNameState The element
*/
	JDFNameState GetNameState(int iSkip=0)const;
/**
* Append element NameState
 */
	JDFNameState AppendNameState();

/** Get Element NumberState
* 
* @param int iSkip number of elements to skip
* @return JDFNumberState The element
*/
	JDFNumberState GetCreateNumberState(int iSkip=0);

/**
* const get element NumberState
* @param int iSkip number of elements to skip
* @return JDFNumberState The element
*/
	JDFNumberState GetNumberState(int iSkip=0)const;
/**
* Append element NumberState
 */
	JDFNumberState AppendNumberState();

/** Get Element PDFPathState
* 
* @param int iSkip number of elements to skip
* @return JDFPDFPathState The element
*/
	JDFPDFPathState GetCreatePDFPathState(int iSkip=0);

/**
* const get element PDFPathState
* @param int iSkip number of elements to skip
* @return JDFPDFPathState The element
*/
	JDFPDFPathState GetPDFPathState(int iSkip=0)const;
/**
* Append element PDFPathState
 */
	JDFPDFPathState AppendPDFPathState();

/** Get Element RectangleState
* 
* @param int iSkip number of elements to skip
* @return JDFRectangleState The element
*/
	JDFRectangleState GetCreateRectangleState(int iSkip=0);

/**
* const get element RectangleState
* @param int iSkip number of elements to skip
* @return JDFRectangleState The element
*/
	JDFRectangleState GetRectangleState(int iSkip=0)const;
/**
* Append element RectangleState
 */
	JDFRectangleState AppendRectangleState();

/** Get Element ShapeState
* 
* @param int iSkip number of elements to skip
* @return JDFShapeState The element
*/
	JDFShapeState GetCreateShapeState(int iSkip=0);

/**
* const get element ShapeState
* @param int iSkip number of elements to skip
* @return JDFShapeState The element
*/
	JDFShapeState GetShapeState(int iSkip=0)const;
/**
* Append element ShapeState
 */
	JDFShapeState AppendShapeState();

/** Get Element StringState
* 
* @param int iSkip number of elements to skip
* @return JDFStringState The element
*/
	JDFStringState GetCreateStringState(int iSkip=0);

/**
* const get element StringState
* @param int iSkip number of elements to skip
* @return JDFStringState The element
*/
	JDFStringState GetStringState(int iSkip=0)const;
/**
* Append element StringState
 */
	JDFStringState AppendStringState();

/** Get Element XYPairState
* 
* @param int iSkip number of elements to skip
* @return JDFXYPairState The element
*/
	JDFXYPairState GetCreateXYPairState(int iSkip=0);

/**
* const get element XYPairState
* @param int iSkip number of elements to skip
* @return JDFXYPairState The element
*/
	JDFXYPairState GetXYPairState(int iSkip=0)const;
/**
* Append element XYPairState
 */
	JDFXYPairState AppendXYPairState();

/** Get Element TestPool
* 
* @return JDFTestPool The element
*/
	JDFTestPool GetCreateTestPool();

/**
* const get element TestPool
*@return  JDFTestPool The element
*/
	JDFTestPool GetTestPool()const;
/**
* Append element TestPool
 * 
*/
	JDFTestPool AppendTestPool();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoMessageService

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoMessageService_H_
