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

 
#if !defined _JDFAutoBindingIntent_H_
#define _JDFAutoBindingIntent_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFIntentResource.h"
#include "jdf/wrapper/AutoJDF/JDFAutoEnumerationSpan.h"
namespace JDF{
class JDFAdhesiveBinding;
class JDFBindList;
class JDFBookCase;
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
class JDFAutoBindingIntent : public JDFIntentResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoBindingIntent class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFBindingIntent should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoBindingIntent : public JDFIntentResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoBindingIntent():JDFIntentResource(){};
/**
* copy ctor
*/
	inline JDFAutoBindingIntent(const KElement & other):JDFIntentResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoBindingIntent &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoBindingIntent(){};
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
* Enumeration for attribute BindingOrder
*/

	enum EnumBindingOrder{BindingOrder_Unknown,BindingOrder_Collecting,BindingOrder_Gathering,BindingOrder_List};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for BindingOrder
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& BindingOrderString();
/**
* Enumeration string for enum value
* @param EnumBindingOrder value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString BindingOrderString(EnumBindingOrder value);
/**
* Set attribute BindingOrder
* @param EnumBindingOrder value the value to set the attribute to
*/
	virtual void SetBindingOrder( EnumBindingOrder value);

/**
* Typesafe enumerated attribute BindingOrder; defaults to Gathering
* @return EnumBindingOrderthe enumeration value of the attribute
*/
	virtual EnumBindingOrder GetBindingOrder() const;

/**
* Typesafe attribute validation of BindingOrder
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBindingOrder(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element BackCoverColor
* 
* @param int iSkip number of elements to skip
* @return JDFSpanNamedColor The element
*/
	JDFSpanNamedColor GetCreateBackCoverColor(int iSkip=0);

/**
* const get element BackCoverColor
* @param int iSkip number of elements to skip
* @return JDFSpanNamedColor The element
*/
	JDFSpanNamedColor GetBackCoverColor(int iSkip=0)const;
/**
* Append element BackCoverColor
 */
	JDFSpanNamedColor AppendBackCoverColor();

/** Get Element BackCoverColorDetails
* 
* @param int iSkip number of elements to skip
* @return JDFStringSpan The element
*/
	JDFStringSpan GetCreateBackCoverColorDetails(int iSkip=0);

/**
* const get element BackCoverColorDetails
* @param int iSkip number of elements to skip
* @return JDFStringSpan The element
*/
	JDFStringSpan GetBackCoverColorDetails(int iSkip=0)const;
/**
* Append element BackCoverColorDetails
 */
	JDFStringSpan AppendBackCoverColorDetails();

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

/** Get Element BindingColor
* 
* @param int iSkip number of elements to skip
* @return JDFSpanNamedColor The element
*/
	JDFSpanNamedColor GetCreateBindingColor(int iSkip=0);

/**
* const get element BindingColor
* @param int iSkip number of elements to skip
* @return JDFSpanNamedColor The element
*/
	JDFSpanNamedColor GetBindingColor(int iSkip=0)const;
/**
* Append element BindingColor
 */
	JDFSpanNamedColor AppendBindingColor();

/** Get Element BindingColorDetails
* 
* @param int iSkip number of elements to skip
* @return JDFStringSpan The element
*/
	JDFStringSpan GetCreateBindingColorDetails(int iSkip=0);

/**
* const get element BindingColorDetails
* @param int iSkip number of elements to skip
* @return JDFStringSpan The element
*/
	JDFStringSpan GetBindingColorDetails(int iSkip=0)const;
/**
* Append element BindingColorDetails
 */
	JDFStringSpan AppendBindingColorDetails();

/** Get Element BindingLength
* 
* @param int iSkip number of elements to skip
* @return JDFSpanBindingLength The element
*/
	JDFSpanBindingLength GetCreateBindingLength(int iSkip=0);

/**
* const get element BindingLength
* @param int iSkip number of elements to skip
* @return JDFSpanBindingLength The element
*/
	JDFSpanBindingLength GetBindingLength(int iSkip=0)const;
/**
* Append element BindingLength
 */
	JDFSpanBindingLength AppendBindingLength();

/** Get Element BindingSide
* 
* @param int iSkip number of elements to skip
* @return JDFSpanBindingSide The element
*/
	JDFSpanBindingSide GetCreateBindingSide(int iSkip=0);

/**
* const get element BindingSide
* @param int iSkip number of elements to skip
* @return JDFSpanBindingSide The element
*/
	JDFSpanBindingSide GetBindingSide(int iSkip=0)const;
/**
* Append element BindingSide
 */
	JDFSpanBindingSide AppendBindingSide();

/** Get Element CoverColor
* 
* @param int iSkip number of elements to skip
* @return JDFSpanNamedColor The element
*/
	JDFSpanNamedColor GetCreateCoverColor(int iSkip=0);

/**
* const get element CoverColor
* @param int iSkip number of elements to skip
* @return JDFSpanNamedColor The element
*/
	JDFSpanNamedColor GetCoverColor(int iSkip=0)const;
/**
* Append element CoverColor
 */
	JDFSpanNamedColor AppendCoverColor();

/** Get Element CoverColorDetails
* 
* @param int iSkip number of elements to skip
* @return JDFStringSpan The element
*/
	JDFStringSpan GetCreateCoverColorDetails(int iSkip=0);

/**
* const get element CoverColorDetails
* @param int iSkip number of elements to skip
* @return JDFStringSpan The element
*/
	JDFStringSpan GetCoverColorDetails(int iSkip=0)const;
/**
* Append element CoverColorDetails
 */
	JDFStringSpan AppendCoverColorDetails();

/** Get Element AdhesiveBinding
* 
* @param int iSkip number of elements to skip
* @return JDFAdhesiveBinding The element
*/
	JDFAdhesiveBinding GetCreateAdhesiveBinding(int iSkip=0);

/**
* const get element AdhesiveBinding
* @param int iSkip number of elements to skip
* @return JDFAdhesiveBinding The element
*/
	JDFAdhesiveBinding GetAdhesiveBinding(int iSkip=0)const;
/**
* Append element AdhesiveBinding
 */
	JDFAdhesiveBinding AppendAdhesiveBinding();

/** Get Element BindList
* 
* @param int iSkip number of elements to skip
* @return JDFBindList The element
*/
	JDFBindList GetCreateBindList(int iSkip=0);

/**
* const get element BindList
* @param int iSkip number of elements to skip
* @return JDFBindList The element
*/
	JDFBindList GetBindList(int iSkip=0)const;
/**
* Append element BindList
 */
	JDFBindList AppendBindList();

/** Get Element BookCase
* 
* @param int iSkip number of elements to skip
* @return JDFBookCase The element
*/
	JDFBookCase GetCreateBookCase(int iSkip=0);

/**
* const get element BookCase
* @param int iSkip number of elements to skip
* @return JDFBookCase The element
*/
	JDFBookCase GetBookCase(int iSkip=0)const;
/**
* Append element BookCase
 */
	JDFBookCase AppendBookCase();

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
}; // endJDFAutoBindingIntent

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoBindingIntent_H_
