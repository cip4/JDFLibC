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

 
#if !defined _JDFAutoDeviceCap_H_
#define _JDFAutoDeviceCap_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
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
class JDFDisplayGroupPool;
class JDFFeaturePool;
class JDFMacroPool;
class JDFModulePool;
class JDFPerformance;
class JDFTestPool;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoDeviceCap : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoDeviceCap class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFDeviceCap should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoDeviceCap : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoDeviceCap():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoDeviceCap(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoDeviceCap &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoDeviceCap(){};
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
* Enumeration for attribute CombinedMethod
*/

	enum EnumCombinedMethod{CombinedMethod_Unknown,CombinedMethod_Combined,CombinedMethod_CombinedProcessGroup,CombinedMethod_GrayBox,CombinedMethod_ProcessGroup,CombinedMethod_None};
/**
* Enumeration for attribute ExecutionPolicy
*/

	enum EnumExecutionPolicy{ExecutionPolicy_Unknown,ExecutionPolicy_RootNode,ExecutionPolicy_FirstFound,ExecutionPolicy_AllFound};
/**
* Enumeration for attribute TypeOrder
*/

	enum EnumTypeOrder{TypeOrder_Unknown,TypeOrder_Fixed,TypeOrder_Unordered,TypeOrder_Unrestricted};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for CombinedMethod
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& CombinedMethodString();
/**
* Enumeration string for enum value
* @param EnumCombinedMethod value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString CombinedMethodString(EnumCombinedMethod value);
/**
* Set attribute CombinedMethod
* @param EnumCombinedMethod value the value to set the attribute to
*/
	virtual void SetCombinedMethod( EnumCombinedMethod value);

/**
* Typesafe enumerated attribute CombinedMethod; defaults to None
* @return EnumCombinedMethodthe enumeration value of the attribute
*/
	virtual EnumCombinedMethod GetCombinedMethod() const;

/**
* Typesafe attribute validation of CombinedMethod
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidCombinedMethod(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ExecutionPolicy
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ExecutionPolicyString();
/**
* Enumeration string for enum value
* @param EnumExecutionPolicy value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ExecutionPolicyString(EnumExecutionPolicy value);
/**
* Set attribute ExecutionPolicy
* @param EnumExecutionPolicy value the value to set the attribute to
*/
	virtual void SetExecutionPolicy( EnumExecutionPolicy value);

/**
* Typesafe enumerated attribute ExecutionPolicy; defaults to AllFound
* @return EnumExecutionPolicythe enumeration value of the attribute
*/
	virtual EnumExecutionPolicy GetExecutionPolicy() const;

/**
* Typesafe attribute validation of ExecutionPolicy
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidExecutionPolicy(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute Lang
*@param vWString value: the value to set the attribute to
*/
	virtual void SetLang(const vWString& value);
/**
* Get string attribute Lang
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetLang() const;
/**
* Typesafe attribute validation of Lang
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLang(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OptionalCombinedTypes
*@param vWString value: the value to set the attribute to
*/
	virtual void SetOptionalCombinedTypes(const vWString& value);
/**
* Get string attribute OptionalCombinedTypes
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetOptionalCombinedTypes() const;
/**
* Typesafe attribute validation of OptionalCombinedTypes
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOptionalCombinedTypes(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute TypeExpression
*@param WString value: the value to set the attribute to
*/
	virtual void SetTypeExpression(const WString& value);
/**
* Get string attribute TypeExpression
* @return WString the vaue of the attribute 
*/
	virtual WString GetTypeExpression() const;
/**
* Typesafe attribute validation of TypeExpression
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTypeExpression(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for TypeOrder
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& TypeOrderString();
/**
* Enumeration string for enum value
* @param EnumTypeOrder value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString TypeOrderString(EnumTypeOrder value);
/**
* Set attribute TypeOrder
* @param EnumTypeOrder value the value to set the attribute to
*/
	virtual void SetTypeOrder( EnumTypeOrder value);

/**
* Typesafe enumerated attribute TypeOrder
* @return EnumTypeOrderthe enumeration value of the attribute
*/
	virtual EnumTypeOrder GetTypeOrder() const;

/**
* Typesafe attribute validation of TypeOrder
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidTypeOrder(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Types
*@param vWString value: the value to set the attribute to
*/
	virtual void SetTypes(const vWString& value);
/**
* Get string attribute Types
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetTypes() const;
/**
* Typesafe attribute validation of Types
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTypes(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element ActionPool
* 
* @param int iSkip number of elements to skip
* @return JDFActionPool The element
*/
	JDFActionPool GetCreateActionPool(int iSkip=0);

/**
* const get element ActionPool
* @param int iSkip number of elements to skip
* @return JDFActionPool The element
*/
	JDFActionPool GetActionPool(int iSkip=0)const;
/**
* Append element ActionPool
 */
	JDFActionPool AppendActionPool();

/** Get Element DevCapPool
* 
* @param int iSkip number of elements to skip
* @return JDFDevCapPool The element
*/
	JDFDevCapPool GetCreateDevCapPool(int iSkip=0);

/**
* const get element DevCapPool
* @param int iSkip number of elements to skip
* @return JDFDevCapPool The element
*/
	JDFDevCapPool GetDevCapPool(int iSkip=0)const;
/**
* Append element DevCapPool
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

/** Get Element DisplayGroupPool
* 
* @param int iSkip number of elements to skip
* @return JDFDisplayGroupPool The element
*/
	JDFDisplayGroupPool GetCreateDisplayGroupPool(int iSkip=0);

/**
* const get element DisplayGroupPool
* @param int iSkip number of elements to skip
* @return JDFDisplayGroupPool The element
*/
	JDFDisplayGroupPool GetDisplayGroupPool(int iSkip=0)const;
/**
* Append element DisplayGroupPool
 */
	JDFDisplayGroupPool AppendDisplayGroupPool();

/** Get Element FeaturePool
* 
* @param int iSkip number of elements to skip
* @return JDFFeaturePool The element
*/
	JDFFeaturePool GetCreateFeaturePool(int iSkip=0);

/**
* const get element FeaturePool
* @param int iSkip number of elements to skip
* @return JDFFeaturePool The element
*/
	JDFFeaturePool GetFeaturePool(int iSkip=0)const;
/**
* Append element FeaturePool
 */
	JDFFeaturePool AppendFeaturePool();

/** Get Element MacroPool
* 
* @param int iSkip number of elements to skip
* @return JDFMacroPool The element
*/
	JDFMacroPool GetCreateMacroPool(int iSkip=0);

/**
* const get element MacroPool
* @param int iSkip number of elements to skip
* @return JDFMacroPool The element
*/
	JDFMacroPool GetMacroPool(int iSkip=0)const;
/**
* Append element MacroPool
 */
	JDFMacroPool AppendMacroPool();

/** Get Element ModulePool
* 
* @param int iSkip number of elements to skip
* @return JDFModulePool The element
*/
	JDFModulePool GetCreateModulePool(int iSkip=0);

/**
* const get element ModulePool
* @param int iSkip number of elements to skip
* @return JDFModulePool The element
*/
	JDFModulePool GetModulePool(int iSkip=0)const;
/**
* Append element ModulePool
 */
	JDFModulePool AppendModulePool();

/** Get Element Performance
* 
* @param int iSkip number of elements to skip
* @return JDFPerformance The element
*/
	JDFPerformance GetCreatePerformance(int iSkip=0);

/**
* const get element Performance
* @param int iSkip number of elements to skip
* @return JDFPerformance The element
*/
	JDFPerformance GetPerformance(int iSkip=0)const;
/**
* Append element Performance
 */
	JDFPerformance AppendPerformance();

/** Get Element TestPool
* 
* @param int iSkip number of elements to skip
* @return JDFTestPool The element
*/
	JDFTestPool GetCreateTestPool(int iSkip=0);

/**
* const get element TestPool
* @param int iSkip number of elements to skip
* @return JDFTestPool The element
*/
	JDFTestPool GetTestPool(int iSkip=0)const;
/**
* Append element TestPool
 */
	JDFTestPool AppendTestPool();

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

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoDeviceCap

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoDeviceCap_H_
