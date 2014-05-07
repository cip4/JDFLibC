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

 
#if !defined _JDFAutoBindItem_H_
#define _JDFAutoBindItem_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
#include "jdf/wrapper/AutoJDF/JDFAutoEnumerationSpan.h"
namespace JDF{
class JDFChannelBinding;
class JDFCoilBinding;
class JDFEdgeGluing;
class JDFHardCoverBinding;
class JDFPlasticCombBinding;
class JDFRingBinding;
class JDFSaddleStitching;
class JDFSideSewing;
class JDFSideStitching;
class JDFSoftCoverBinding;
class JDFTape;
class JDFTabs;
class JDFThreadSealing;
class JDFThreadSewing;
class JDFStripBinding;
class JDFWireCombBinding;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoBindItem : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoBindItem class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFBindItem should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoBindItem : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoBindItem():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoBindItem(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoBindItem &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoBindItem(){};
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
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute ChildFolio
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetChildFolio(const JDFXYPair& value);
/**
* Get string attribute ChildFolio
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetChildFolio() const;
/**
* Typesafe attribute validation of ChildFolio
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidChildFolio(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ParentFolio
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetParentFolio(const JDFXYPair& value);
/**
* Get string attribute ParentFolio
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetParentFolio() const;
/**
* Typesafe attribute validation of ParentFolio
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidParentFolio(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Transformation
*@param JDFMatrix value: the value to set the attribute to
*/
	virtual void SetTransformation(const JDFMatrix& value);
/**
* Get string attribute Transformation
* @return JDFMatrix the vaue of the attribute 
*/
	virtual JDFMatrix GetTransformation() const;
/**
* Typesafe attribute validation of Transformation
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTransformation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute WrapPages
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetWrapPages(const JDFIntegerRangeList& value);
/**
* Get range attribute WrapPages
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetWrapPages() const;
/**
* Typesafe attribute validation of WrapPages
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWrapPages(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element BindingType
* 
* @param int iSkip number of elements to skip
* @return JDFSpanBindingType The element
*/
	JDFSpanBindingType GetCreateBindingType(int iSkip=0);

/**
* const get element BindingType
* @param int iSkip number of elements to skip
* @return JDFSpanBindingType The element
*/
	JDFSpanBindingType GetBindingType(int iSkip=0)const;
/**
* Append element BindingType
 */
	JDFSpanBindingType AppendBindingType();

/** Get Element ChannelBinding
* 
* @param int iSkip number of elements to skip
* @return JDFChannelBinding The element
*/
	JDFChannelBinding GetCreateChannelBinding(int iSkip=0);

/**
* const get element ChannelBinding
* @param int iSkip number of elements to skip
* @return JDFChannelBinding The element
*/
	JDFChannelBinding GetChannelBinding(int iSkip=0)const;
/**
* Append element ChannelBinding
 */
	JDFChannelBinding AppendChannelBinding();

/** Get Element CoilBinding
* 
* @param int iSkip number of elements to skip
* @return JDFCoilBinding The element
*/
	JDFCoilBinding GetCreateCoilBinding(int iSkip=0);

/**
* const get element CoilBinding
* @param int iSkip number of elements to skip
* @return JDFCoilBinding The element
*/
	JDFCoilBinding GetCoilBinding(int iSkip=0)const;
/**
* Append element CoilBinding
 */
	JDFCoilBinding AppendCoilBinding();

/** Get Element EdgeGluing
* 
* @param int iSkip number of elements to skip
* @return JDFEdgeGluing The element
*/
	JDFEdgeGluing GetCreateEdgeGluing(int iSkip=0);

/**
* const get element EdgeGluing
* @param int iSkip number of elements to skip
* @return JDFEdgeGluing The element
*/
	JDFEdgeGluing GetEdgeGluing(int iSkip=0)const;
/**
* Append element EdgeGluing
 */
	JDFEdgeGluing AppendEdgeGluing();

/** Get Element HardCoverBinding
* 
* @param int iSkip number of elements to skip
* @return JDFHardCoverBinding The element
*/
	JDFHardCoverBinding GetCreateHardCoverBinding(int iSkip=0);

/**
* const get element HardCoverBinding
* @param int iSkip number of elements to skip
* @return JDFHardCoverBinding The element
*/
	JDFHardCoverBinding GetHardCoverBinding(int iSkip=0)const;
/**
* Append element HardCoverBinding
 */
	JDFHardCoverBinding AppendHardCoverBinding();

/** Get Element PlasticCombBinding
* 
* @param int iSkip number of elements to skip
* @return JDFPlasticCombBinding The element
*/
	JDFPlasticCombBinding GetCreatePlasticCombBinding(int iSkip=0);

/**
* const get element PlasticCombBinding
* @param int iSkip number of elements to skip
* @return JDFPlasticCombBinding The element
*/
	JDFPlasticCombBinding GetPlasticCombBinding(int iSkip=0)const;
/**
* Append element PlasticCombBinding
 */
	JDFPlasticCombBinding AppendPlasticCombBinding();

/** Get Element RingBinding
* 
* @param int iSkip number of elements to skip
* @return JDFRingBinding The element
*/
	JDFRingBinding GetCreateRingBinding(int iSkip=0);

/**
* const get element RingBinding
* @param int iSkip number of elements to skip
* @return JDFRingBinding The element
*/
	JDFRingBinding GetRingBinding(int iSkip=0)const;
/**
* Append element RingBinding
 */
	JDFRingBinding AppendRingBinding();

/** Get Element SaddleStitching
* 
* @param int iSkip number of elements to skip
* @return JDFSaddleStitching The element
*/
	JDFSaddleStitching GetCreateSaddleStitching(int iSkip=0);

/**
* const get element SaddleStitching
* @param int iSkip number of elements to skip
* @return JDFSaddleStitching The element
*/
	JDFSaddleStitching GetSaddleStitching(int iSkip=0)const;
/**
* Append element SaddleStitching
 */
	JDFSaddleStitching AppendSaddleStitching();

/** Get Element SideSewing
* 
* @param int iSkip number of elements to skip
* @return JDFSideSewing The element
*/
	JDFSideSewing GetCreateSideSewing(int iSkip=0);

/**
* const get element SideSewing
* @param int iSkip number of elements to skip
* @return JDFSideSewing The element
*/
	JDFSideSewing GetSideSewing(int iSkip=0)const;
/**
* Append element SideSewing
 */
	JDFSideSewing AppendSideSewing();

/** Get Element SideStitching
* 
* @param int iSkip number of elements to skip
* @return JDFSideStitching The element
*/
	JDFSideStitching GetCreateSideStitching(int iSkip=0);

/**
* const get element SideStitching
* @param int iSkip number of elements to skip
* @return JDFSideStitching The element
*/
	JDFSideStitching GetSideStitching(int iSkip=0)const;
/**
* Append element SideStitching
 */
	JDFSideStitching AppendSideStitching();

/** Get Element SoftCoverBinding
* 
* @param int iSkip number of elements to skip
* @return JDFSoftCoverBinding The element
*/
	JDFSoftCoverBinding GetCreateSoftCoverBinding(int iSkip=0);

/**
* const get element SoftCoverBinding
* @param int iSkip number of elements to skip
* @return JDFSoftCoverBinding The element
*/
	JDFSoftCoverBinding GetSoftCoverBinding(int iSkip=0)const;
/**
* Append element SoftCoverBinding
 */
	JDFSoftCoverBinding AppendSoftCoverBinding();

/** Get Element Tape
* 
* @param int iSkip number of elements to skip
* @return JDFTape The element
*/
	JDFTape GetCreateTape(int iSkip=0);

/**
* const get element Tape
* @param int iSkip number of elements to skip
* @return JDFTape The element
*/
	JDFTape GetTape(int iSkip=0)const;
/**
* Append element Tape
 */
	JDFTape AppendTape();

/** Get Element Tabs
* 
* @param int iSkip number of elements to skip
* @return JDFTabs The element
*/
	JDFTabs GetCreateTabs(int iSkip=0);

/**
* const get element Tabs
* @param int iSkip number of elements to skip
* @return JDFTabs The element
*/
	JDFTabs GetTabs(int iSkip=0)const;
/**
* Append element Tabs
 */
	JDFTabs AppendTabs();

/** Get Element ThreadSealing
* 
* @param int iSkip number of elements to skip
* @return JDFThreadSealing The element
*/
	JDFThreadSealing GetCreateThreadSealing(int iSkip=0);

/**
* const get element ThreadSealing
* @param int iSkip number of elements to skip
* @return JDFThreadSealing The element
*/
	JDFThreadSealing GetThreadSealing(int iSkip=0)const;
/**
* Append element ThreadSealing
 */
	JDFThreadSealing AppendThreadSealing();

/** Get Element ThreadSewing
* 
* @param int iSkip number of elements to skip
* @return JDFThreadSewing The element
*/
	JDFThreadSewing GetCreateThreadSewing(int iSkip=0);

/**
* const get element ThreadSewing
* @param int iSkip number of elements to skip
* @return JDFThreadSewing The element
*/
	JDFThreadSewing GetThreadSewing(int iSkip=0)const;
/**
* Append element ThreadSewing
 */
	JDFThreadSewing AppendThreadSewing();

/** Get Element StripBinding
* 
* @param int iSkip number of elements to skip
* @return JDFStripBinding The element
*/
	JDFStripBinding GetCreateStripBinding(int iSkip=0);

/**
* const get element StripBinding
* @param int iSkip number of elements to skip
* @return JDFStripBinding The element
*/
	JDFStripBinding GetStripBinding(int iSkip=0)const;
/**
* Append element StripBinding
 */
	JDFStripBinding AppendStripBinding();

/** Get Element WireCombBinding
* 
* @param int iSkip number of elements to skip
* @return JDFWireCombBinding The element
*/
	JDFWireCombBinding GetCreateWireCombBinding(int iSkip=0);

/**
* const get element WireCombBinding
* @param int iSkip number of elements to skip
* @return JDFWireCombBinding The element
*/
	JDFWireCombBinding GetWireCombBinding(int iSkip=0)const;
/**
* Append element WireCombBinding
 */
	JDFWireCombBinding AppendWireCombBinding();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoBindItem

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoBindItem_H_
