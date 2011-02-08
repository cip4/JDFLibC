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

 
#if !defined _JDFAutoLayout_H_
#define _JDFAutoLayout_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFContentObject;
class JDFInsertSheet;
class JDFLayerList;
class JDFLogicalStackParams;
class JDFMarkObject;
class JDFMedia;
class JDFMediaSource;
class JDFPageCondition;
class JDFSignature;
class JDFTransferCurvePool;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoLayout : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoLayout class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFLayout should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoLayout : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoLayout():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoLayout(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoLayout &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoLayout(){};
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
* Enumeration for attribute OrdReset
*/

	enum EnumOrdReset{OrdReset_Unknown,OrdReset_Continue,OrdReset_PagePool,OrdReset_PagePoolList};
/**
* Enumeration for attribute SheetCountReset
*/

	enum EnumSheetCountReset{SheetCountReset_Unknown,SheetCountReset_Continue,SheetCountReset_PagePool,SheetCountReset_PagePoolList};
/**
* Enumeration for attribute BaseOrdReset
*/

	enum EnumBaseOrdReset{BaseOrdReset_Unknown,BaseOrdReset_PagePool,BaseOrdReset_PagePoolList};
/**
* Enumeration for attribute SourceWorkStyle
*/

	enum EnumSourceWorkStyle{SourceWorkStyle_Unknown,SourceWorkStyle_Simplex,SourceWorkStyle_Perfecting,SourceWorkStyle_WorkAndBack,SourceWorkStyle_WorkAndTurn,SourceWorkStyle_WorkAndTumble,SourceWorkStyle_WorkAndTwist};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute Automated
*@param bool value: the value to set the attribute to
*/
	virtual void SetAutomated(bool value);
/**
* Get bool attribute Automated
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetAutomated() const;
/**
* Typesafe attribute validation of Automated
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAutomated(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LockOrigins
*@param bool value: the value to set the attribute to
*/
	virtual void SetLockOrigins(bool value);
/**
* Get bool attribute LockOrigins
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetLockOrigins() const;
/**
* Typesafe attribute validation of LockOrigins
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLockOrigins(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxDocOrd
*@param int value: the value to set the attribute to
*/
	virtual void SetMaxDocOrd(int value);
/**
* Get integer attribute MaxDocOrd
* @return int the vaue of the attribute 
*/
	virtual int GetMaxDocOrd() const;
/**
* Typesafe attribute validation of MaxDocOrd
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxDocOrd(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxSetOrd
*@param int value: the value to set the attribute to
*/
	virtual void SetMaxSetOrd(int value);
/**
* Get integer attribute MaxSetOrd
* @return int the vaue of the attribute 
*/
	virtual int GetMaxSetOrd() const;
/**
* Typesafe attribute validation of MaxSetOrd
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxSetOrd(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for OrdReset
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& OrdResetString();
/**
* Enumeration string for enum value
* @param EnumOrdReset value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString OrdResetString(EnumOrdReset value);
/**
* Set attribute OrdReset
* @param EnumOrdReset value the value to set the attribute to
*/
	virtual void SetOrdReset( EnumOrdReset value);

/**
* Typesafe enumerated attribute OrdReset; defaults to Continue
* @return EnumOrdResetthe enumeration value of the attribute
*/
	virtual EnumOrdReset GetOrdReset() const;

/**
* Typesafe attribute validation of OrdReset
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidOrdReset(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for SheetCountReset
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SheetCountResetString();
/**
* Enumeration string for enum value
* @param EnumSheetCountReset value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SheetCountResetString(EnumSheetCountReset value);
/**
* Set attribute SheetCountReset
* @param EnumSheetCountReset value the value to set the attribute to
*/
	virtual void SetSheetCountReset( EnumSheetCountReset value);

/**
* Typesafe enumerated attribute SheetCountReset; defaults to Continue
* @return EnumSheetCountResetthe enumeration value of the attribute
*/
	virtual EnumSheetCountReset GetSheetCountReset() const;

/**
* Typesafe attribute validation of SheetCountReset
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSheetCountReset(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Name
*@param WString value: the value to set the attribute to
*/
	virtual void SetName(const WString& value);
/**
* Get string attribute Name
* @return WString the vaue of the attribute 
*/
	virtual WString GetName() const;
/**
* Typesafe attribute validation of Name
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for BaseOrdReset
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& BaseOrdResetString();
/**
* Enumeration string for enum value
* @param EnumBaseOrdReset value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString BaseOrdResetString(EnumBaseOrdReset value);
/**
* Set attribute BaseOrdReset
* @param EnumBaseOrdReset value the value to set the attribute to
*/
	virtual void SetBaseOrdReset( EnumBaseOrdReset value);

/**
* Typesafe enumerated attribute BaseOrdReset
* @return EnumBaseOrdResetthe enumeration value of the attribute
*/
	virtual EnumBaseOrdReset GetBaseOrdReset() const;

/**
* Typesafe attribute validation of BaseOrdReset
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBaseOrdReset(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxCollect
*@param int value: the value to set the attribute to
*/
	virtual void SetMaxCollect(int value);
/**
* Get integer attribute MaxCollect
* @return int the vaue of the attribute 
*/
	virtual int GetMaxCollect() const;
/**
* Typesafe attribute validation of MaxCollect
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxCollect(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxOrd
*@param int value: the value to set the attribute to
*/
	virtual void SetMaxOrd(int value);
/**
* Get integer attribute MaxOrd
* @return int the vaue of the attribute 
*/
	virtual int GetMaxOrd() const;
/**
* Typesafe attribute validation of MaxOrd
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxOrd(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MinCollect
*@param int value: the value to set the attribute to
*/
	virtual void SetMinCollect(int value);
/**
* Get integer attribute MinCollect
* @return int the vaue of the attribute 
*/
	virtual int GetMinCollect() const;
/**
* Typesafe attribute validation of MinCollect
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMinCollect(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OrdsConsumed
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetOrdsConsumed(const JDFIntegerRangeList& value);
/**
* Get range attribute OrdsConsumed
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetOrdsConsumed() const;
/**
* Typesafe attribute validation of OrdsConsumed
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOrdsConsumed(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SheetNameFormat
*@param WString value: the value to set the attribute to
*/
	virtual void SetSheetNameFormat(const WString& value);
/**
* Get string attribute SheetNameFormat
* @return WString the vaue of the attribute 
*/
	virtual WString GetSheetNameFormat() const;
/**
* Typesafe attribute validation of SheetNameFormat
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSheetNameFormat(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SheetNameTemplate
*@param WString value: the value to set the attribute to
*/
	virtual void SetSheetNameTemplate(const WString& value);
/**
* Get string attribute SheetNameTemplate
* @return WString the vaue of the attribute 
*/
	virtual WString GetSheetNameTemplate() const;
/**
* Typesafe attribute validation of SheetNameTemplate
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSheetNameTemplate(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for SourceWorkStyle
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SourceWorkStyleString();
/**
* Enumeration string for enum value
* @param EnumSourceWorkStyle value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SourceWorkStyleString(EnumSourceWorkStyle value);
/**
* Set attribute SourceWorkStyle
* @param EnumSourceWorkStyle value the value to set the attribute to
*/
	virtual void SetSourceWorkStyle( EnumSourceWorkStyle value);

/**
* Typesafe enumerated attribute SourceWorkStyle
* @return EnumSourceWorkStylethe enumeration value of the attribute
*/
	virtual EnumSourceWorkStyle GetSourceWorkStyle() const;

/**
* Typesafe attribute validation of SourceWorkStyle
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSourceWorkStyle(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StackDepth
*@param int value: the value to set the attribute to
*/
	virtual void SetStackDepth(int value);
/**
* Get integer attribute StackDepth
* @return int the vaue of the attribute 
*/
	virtual int GetStackDepth() const;
/**
* Typesafe attribute validation of StackDepth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStackDepth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SurfaceContentsBox
*@param JDFRectangle value: the value to set the attribute to
*/
	virtual void SetSurfaceContentsBox(const JDFRectangle& value);
/**
* Get string attribute SurfaceContentsBox
* @return JDFRectangle the vaue of the attribute 
*/
	virtual JDFRectangle GetSurfaceContentsBox() const;
/**
* Typesafe attribute validation of SurfaceContentsBox
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSurfaceContentsBox(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element ContentObject
* 
* @param int iSkip number of elements to skip
* @return JDFContentObject The element
*/
	JDFContentObject GetCreateContentObject(int iSkip=0);

/**
* const get element ContentObject
* @param int iSkip number of elements to skip
* @return JDFContentObject The element
*/
	JDFContentObject GetContentObject(int iSkip=0)const;
/**
* Append element ContentObject
 */
	JDFContentObject AppendContentObject();

/** Get Element InsertSheet
* 
* @param int iSkip number of elements to skip
* @return JDFInsertSheet The element
*/
	JDFInsertSheet GetCreateInsertSheet(int iSkip=0);

/**
* const get element InsertSheet
* @param int iSkip number of elements to skip
* @return JDFInsertSheet The element
*/
	JDFInsertSheet GetInsertSheet(int iSkip=0)const;
/**
* Append element InsertSheet
 */
	JDFInsertSheet AppendInsertSheet();
/**
* create inter-resource link to refTarget
* @param JDFInsertSheet& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefInsertSheet(JDFInsertSheet& refTarget);

/** Get Element LayerList
* 
* @return JDFLayerList The element
*/
	JDFLayerList GetCreateLayerList();

/**
* const get element LayerList
*@return  JDFLayerList The element
*/
	JDFLayerList GetLayerList()const;
/**
* Append element LayerList
 * 
*/
	JDFLayerList AppendLayerList();

/** Get Element LogicalStackParams
* 
* @return JDFLogicalStackParams The element
*/
	JDFLogicalStackParams GetCreateLogicalStackParams();

/**
* const get element LogicalStackParams
*@return  JDFLogicalStackParams The element
*/
	JDFLogicalStackParams GetLogicalStackParams()const;
/**
* Append element LogicalStackParams
 * 
*/
	JDFLogicalStackParams AppendLogicalStackParams();

/** Get Element MarkObject
* 
* @param int iSkip number of elements to skip
* @return JDFMarkObject The element
*/
	JDFMarkObject GetCreateMarkObject(int iSkip=0);

/**
* const get element MarkObject
* @param int iSkip number of elements to skip
* @return JDFMarkObject The element
*/
	JDFMarkObject GetMarkObject(int iSkip=0)const;
/**
* Append element MarkObject
 */
	JDFMarkObject AppendMarkObject();

/** Get Element Media
* 
* @param int iSkip number of elements to skip
* @return JDFMedia The element
*/
	JDFMedia GetCreateMedia(int iSkip=0);

/**
* const get element Media
* @param int iSkip number of elements to skip
* @return JDFMedia The element
*/
	JDFMedia GetMedia(int iSkip=0)const;
/**
* Append element Media
 */
	JDFMedia AppendMedia();
/**
* create inter-resource link to refTarget
* @param JDFMedia& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefMedia(JDFMedia& refTarget);

/** Get Element MediaSource
* 
* @return JDFMediaSource The element
*/
	JDFMediaSource GetCreateMediaSource();

/**
* const get element MediaSource
*@return  JDFMediaSource The element
*/
	JDFMediaSource GetMediaSource()const;
/**
* Append element MediaSource
 * 
*/
	JDFMediaSource AppendMediaSource();
/**
* create inter-resource link to refTarget
* @param JDFMediaSource& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefMediaSource(JDFMediaSource& refTarget);

/** Get Element PageCondition
* 
* @param int iSkip number of elements to skip
* @return JDFPageCondition The element
*/
	JDFPageCondition GetCreatePageCondition(int iSkip=0);

/**
* const get element PageCondition
* @param int iSkip number of elements to skip
* @return JDFPageCondition The element
*/
	JDFPageCondition GetPageCondition(int iSkip=0)const;
/**
* Append element PageCondition
 */
	JDFPageCondition AppendPageCondition();

/** Get Element Signature
* 
* @param int iSkip number of elements to skip
* @return JDFSignature The element
*/
	JDFSignature GetCreateSignature(int iSkip=0);

/**
* const get element Signature
* @param int iSkip number of elements to skip
* @return JDFSignature The element
*/
	JDFSignature GetSignature(int iSkip=0)const;
/**
* Append element Signature
 */
	JDFSignature AppendSignature();

/** Get Element TransferCurvePool
* 
* @return JDFTransferCurvePool The element
*/
	JDFTransferCurvePool GetCreateTransferCurvePool();

/**
* const get element TransferCurvePool
*@return  JDFTransferCurvePool The element
*/
	JDFTransferCurvePool GetTransferCurvePool()const;
/**
* Append element TransferCurvePool
 * 
*/
	JDFTransferCurvePool AppendTransferCurvePool();
/**
* create inter-resource link to refTarget
* @param JDFTransferCurvePool& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefTransferCurvePool(JDFTransferCurvePool& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoLayout

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoLayout_H_
