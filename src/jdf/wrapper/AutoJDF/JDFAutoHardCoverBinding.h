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

 
#if !defined _JDFAutoHardCoverBinding_H_
#define _JDFAutoHardCoverBinding_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
#include "jdf/wrapper/AutoJDF/JDFAutoEnumerationSpan.h"
namespace JDF{
class JDFRegisterRibbon;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoHardCoverBinding : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoHardCoverBinding class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFHardCoverBinding should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoHardCoverBinding : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoHardCoverBinding():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoHardCoverBinding(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoHardCoverBinding &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoHardCoverBinding(){};
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


/** Get Element BlockThreadSewing
* 
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetCreateBlockThreadSewing(int iSkip=0);

/**
* const get element BlockThreadSewing
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetBlockThreadSewing(int iSkip=0)const;
/**
* Append element BlockThreadSewing
 */
	JDFOptionSpan AppendBlockThreadSewing();

/** Get Element CoverStyle
* 
* @param int iSkip number of elements to skip
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCreateCoverStyle(int iSkip=0);

/**
* const get element CoverStyle
* @param int iSkip number of elements to skip
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCoverStyle(int iSkip=0)const;
/**
* Append element CoverStyle
 */
	JDFNameSpan AppendCoverStyle();

/** Get Element EndSheets
* 
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetCreateEndSheets(int iSkip=0);

/**
* const get element EndSheets
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetEndSheets(int iSkip=0)const;
/**
* Append element EndSheets
 */
	JDFOptionSpan AppendEndSheets();

/** Get Element HeadBands
* 
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetCreateHeadBands(int iSkip=0);

/**
* const get element HeadBands
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetHeadBands(int iSkip=0)const;
/**
* Append element HeadBands
 */
	JDFOptionSpan AppendHeadBands();

/** Get Element HeadBandColor
* 
* @param int iSkip number of elements to skip
* @return JDFSpanNamedColor The element
*/
	JDFSpanNamedColor GetCreateHeadBandColor(int iSkip=0);

/**
* const get element HeadBandColor
* @param int iSkip number of elements to skip
* @return JDFSpanNamedColor The element
*/
	JDFSpanNamedColor GetHeadBandColor(int iSkip=0)const;
/**
* Append element HeadBandColor
 */
	JDFSpanNamedColor AppendHeadBandColor();

/** Get Element HeadBandColorDetails
* 
* @param int iSkip number of elements to skip
* @return JDFStringSpan The element
*/
	JDFStringSpan GetCreateHeadBandColorDetails(int iSkip=0);

/**
* const get element HeadBandColorDetails
* @param int iSkip number of elements to skip
* @return JDFStringSpan The element
*/
	JDFStringSpan GetHeadBandColorDetails(int iSkip=0)const;
/**
* Append element HeadBandColorDetails
 */
	JDFStringSpan AppendHeadBandColorDetails();

/** Get Element Jacket
* 
* @param int iSkip number of elements to skip
* @return JDFSpanJacket The element
*/
	JDFSpanJacket GetCreateJacket(int iSkip=0);

/**
* const get element Jacket
* @param int iSkip number of elements to skip
* @return JDFSpanJacket The element
*/
	JDFSpanJacket GetJacket(int iSkip=0)const;
/**
* Append element Jacket
 */
	JDFSpanJacket AppendJacket();

/** Get Element JacketFoldingWidth
* 
* @param int iSkip number of elements to skip
* @return JDFNumberSpan The element
*/
	JDFNumberSpan GetCreateJacketFoldingWidth(int iSkip=0);

/**
* const get element JacketFoldingWidth
* @param int iSkip number of elements to skip
* @return JDFNumberSpan The element
*/
	JDFNumberSpan GetJacketFoldingWidth(int iSkip=0)const;
/**
* Append element JacketFoldingWidth
 */
	JDFNumberSpan AppendJacketFoldingWidth();

/** Get Element JapanBind
* 
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetCreateJapanBind(int iSkip=0);

/**
* const get element JapanBind
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetJapanBind(int iSkip=0)const;
/**
* Append element JapanBind
 */
	JDFOptionSpan AppendJapanBind();

/** Get Element SpineBrushing
* 
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetCreateSpineBrushing(int iSkip=0);

/**
* const get element SpineBrushing
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetSpineBrushing(int iSkip=0)const;
/**
* Append element SpineBrushing
 */
	JDFOptionSpan AppendSpineBrushing();

/** Get Element SpineFiberRoughing
* 
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetCreateSpineFiberRoughing(int iSkip=0);

/**
* const get element SpineFiberRoughing
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetSpineFiberRoughing(int iSkip=0)const;
/**
* Append element SpineFiberRoughing
 */
	JDFOptionSpan AppendSpineFiberRoughing();

/** Get Element SpineGlue
* 
* @param int iSkip number of elements to skip
* @return JDFSpanGlue The element
*/
	JDFSpanGlue GetCreateSpineGlue(int iSkip=0);

/**
* const get element SpineGlue
* @param int iSkip number of elements to skip
* @return JDFSpanGlue The element
*/
	JDFSpanGlue GetSpineGlue(int iSkip=0)const;
/**
* Append element SpineGlue
 */
	JDFSpanGlue AppendSpineGlue();

/** Get Element SpineLevelling
* 
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetCreateSpineLevelling(int iSkip=0);

/**
* const get element SpineLevelling
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetSpineLevelling(int iSkip=0)const;
/**
* Append element SpineLevelling
 */
	JDFOptionSpan AppendSpineLevelling();

/** Get Element SpineMilling
* 
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetCreateSpineMilling(int iSkip=0);

/**
* const get element SpineMilling
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetSpineMilling(int iSkip=0)const;
/**
* Append element SpineMilling
 */
	JDFOptionSpan AppendSpineMilling();

/** Get Element SpineNotching
* 
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetCreateSpineNotching(int iSkip=0);

/**
* const get element SpineNotching
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetSpineNotching(int iSkip=0)const;
/**
* Append element SpineNotching
 */
	JDFOptionSpan AppendSpineNotching();

/** Get Element SpineSanding
* 
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetCreateSpineSanding(int iSkip=0);

/**
* const get element SpineSanding
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetSpineSanding(int iSkip=0)const;
/**
* Append element SpineSanding
 */
	JDFOptionSpan AppendSpineSanding();

/** Get Element SpineShredding
* 
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetCreateSpineShredding(int iSkip=0);

/**
* const get element SpineShredding
* @param int iSkip number of elements to skip
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetSpineShredding(int iSkip=0)const;
/**
* Append element SpineShredding
 */
	JDFOptionSpan AppendSpineShredding();

/** Get Element StripMaterial
* 
* @param int iSkip number of elements to skip
* @return JDFSpanStripMaterial The element
*/
	JDFSpanStripMaterial GetCreateStripMaterial(int iSkip=0);

/**
* const get element StripMaterial
* @param int iSkip number of elements to skip
* @return JDFSpanStripMaterial The element
*/
	JDFSpanStripMaterial GetStripMaterial(int iSkip=0)const;
/**
* Append element StripMaterial
 */
	JDFSpanStripMaterial AppendStripMaterial();

/** Get Element TightBacking
* 
* @param int iSkip number of elements to skip
* @return JDFSpanTightBacking The element
*/
	JDFSpanTightBacking GetCreateTightBacking(int iSkip=0);

/**
* const get element TightBacking
* @param int iSkip number of elements to skip
* @return JDFSpanTightBacking The element
*/
	JDFSpanTightBacking GetTightBacking(int iSkip=0)const;
/**
* Append element TightBacking
 */
	JDFSpanTightBacking AppendTightBacking();

/** Get Element Thickness
* 
* @param int iSkip number of elements to skip
* @return JDFNumberSpan The element
*/
	JDFNumberSpan GetCreateThickness(int iSkip=0);

/**
* const get element Thickness
* @param int iSkip number of elements to skip
* @return JDFNumberSpan The element
*/
	JDFNumberSpan GetThickness(int iSkip=0)const;
/**
* Append element Thickness
 */
	JDFNumberSpan AppendThickness();

/** Get Element RegisterRibbon
* 
* @param int iSkip number of elements to skip
* @return JDFRegisterRibbon The element
*/
	JDFRegisterRibbon GetCreateRegisterRibbon(int iSkip=0);

/**
* const get element RegisterRibbon
* @param int iSkip number of elements to skip
* @return JDFRegisterRibbon The element
*/
	JDFRegisterRibbon GetRegisterRibbon(int iSkip=0)const;
/**
* Append element RegisterRibbon
 */
	JDFRegisterRibbon AppendRegisterRibbon();
/**
* create inter-resource link to refTarget
* @param JDFRegisterRibbon& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefRegisterRibbon(JDFRegisterRibbon& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoHardCoverBinding

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoHardCoverBinding_H_
