/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2002 The International Cooperation for the Integration of 
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
#ifndef _JDFAutoEnumerationSpan_H_
#define _JDFAutoEnumerationSpan_H_
#include "jdf/wrapper/JDFSpan.h"

namespace JDF{
class JDF_WRAPPERCORE_EXPORT JDFSpanArtHandling : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanArtHandling():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanArtHandling(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanArtHandling &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanArtHandling: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanArtHandling(){};
/**
* enumeration type for ArtHandling
*/
enum EnumSpanArtHandling{SpanArtHandling_Unknown,SpanArtHandling_ReturnWithProof,SpanArtHandling_ReturnWithProduct,SpanArtHandling_Return,SpanArtHandling_Pickup,SpanArtHandling_Destroy,SpanArtHandling_PrinterOwns,SpanArtHandling_Store};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanDeliveryCharge : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanDeliveryCharge():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanDeliveryCharge(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanDeliveryCharge &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanDeliveryCharge: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanDeliveryCharge(){};
/**
* enumeration type for DeliveryCharge
*/
enum EnumSpanDeliveryCharge{SpanDeliveryCharge_Unknown,SpanDeliveryCharge_Printer,SpanDeliveryCharge_Buyer,SpanDeliveryCharge_Other};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanTransfer : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanTransfer():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanTransfer(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanTransfer &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanTransfer: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanTransfer(){};
/**
* enumeration type for Transfer
*/
enum EnumSpanTransfer{SpanTransfer_Unknown,SpanTransfer_BuyerToPrinterDeliver,SpanTransfer_BuyerToPrinterPickup,SpanTransfer_PrinterToBuyerDeliver,SpanTransfer_PrinterToBuyerPickup};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanScoring : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanScoring():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanScoring(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanScoring &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanScoring: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanScoring(){};
/**
* enumeration type for Scoring
*/
enum EnumSpanScoring{SpanScoring_Unknown,SpanScoring_TwiceScored,SpanScoring_QuadScored,SpanScoring_None};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanGlue : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanGlue():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanGlue(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanGlue &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanGlue: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanGlue(){};
/**
* enumeration type for Glue
*/
enum EnumSpanGlue{SpanGlue_Unknown,SpanGlue_ColdGlue,SpanGlue_Hotmelt,SpanGlue_PUR};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanShape : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanShape():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanShape(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanShape &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanShape: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanShape(){};
/**
* enumeration type for Shape
*/
enum EnumSpanShape{SpanShape_Unknown,SpanShape_RoundedBack,SpanShape_SquareBack};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanCoilMaterial : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanCoilMaterial():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanCoilMaterial(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanCoilMaterial &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanCoilMaterial: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanCoilMaterial(){};
/**
* enumeration type for CoilMaterial
*/
enum EnumSpanCoilMaterial{SpanCoilMaterial_Unknown,SpanCoilMaterial_Plastic,SpanCoilMaterial_Steel,SpanCoilMaterial_ColorCoatedSteel};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanStripMaterial : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanStripMaterial():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanStripMaterial(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanStripMaterial &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanStripMaterial: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanStripMaterial(){};
/**
* enumeration type for StripMaterial
*/
enum EnumSpanStripMaterial{SpanStripMaterial_Unknown,SpanStripMaterial_Calico,SpanStripMaterial_Cardboard,SpanStripMaterial_CrepePaper,SpanStripMaterial_Gauze,SpanStripMaterial_Paper,SpanStripMaterial_PaperlinedMules,SpanStripMaterial_Tape};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanWireCombMaterial : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanWireCombMaterial():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanWireCombMaterial(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanWireCombMaterial &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanWireCombMaterial: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanWireCombMaterial(){};
/**
* enumeration type for WireCombMaterial
*/
enum EnumSpanWireCombMaterial{SpanWireCombMaterial_Unknown,SpanWireCombMaterial_Steel_Silver,SpanWireCombMaterial_ColorCoatedSteel};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////
class JDF_WRAPPERCORE_EXPORT JDFSpanImageStrategy : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanImageStrategy():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanImageStrategy(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanImageStrategy &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanImageStrategy: "+other.GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanImageStrategy(){};
/**
* enumeration type for ImageStrategy
*/
enum EnumSpanImageStrategy{SpanImageStrategy_Unknown,SpanImageStrategy_NoImages,SpanImageStrategy_LowResolution,SpanImageStrategy_HighResolution};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////
class JDF_WRAPPERCORE_EXPORT JDFSpanScreeningType : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanScreeningType():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanScreeningType(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanScreeningType &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanScreeningType: "+other.GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanScreeningType(){};
/**
* enumeration type for ScreeningType
*/
enum EnumSpanScreeningType{SpanScreeningType_Unknown,SpanScreeningType_AM,SpanScreeningType_FM};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////
class JDF_WRAPPERCORE_EXPORT JDFSpanFrequencySelection : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanFrequencySelection():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanFrequencySelection(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanFrequencySelection &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanFrequencySelection: "+other.GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanFrequencySelection(){};
/**
* enumeration type for FrequencySelection
*/
enum EnumSpanFrequencySelection{SpanFrequencySelection_Unknown,SpanFrequencySelection_LowestFrequency,SpanFrequencySelection_MiddleFrequency,SpanFrequencySelection_HighestFrequency};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};


///////////////////////////////////////////////////////////////
class JDF_WRAPPERCORE_EXPORT JDFSpanFinishedGrainDirection : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanFinishedGrainDirection():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanFinishedGrainDirection(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanFinishedGrainDirection &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanFinishedGrainDirection: "+other.GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanFinishedGrainDirection(){};
/**
* enumeration type for FinishedGrainDirection
*/
enum EnumSpanFinishedGrainDirection{SpanFinishedGrainDirection_Unknown,SpanFinishedGrainDirection_ParallelToBind,SpanFinishedGrainDirection_PerpendicularToBind};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};


///////////////////////////////////////////////////////////////
class JDF_WRAPPERCORE_EXPORT JDFSpanSizePolicy : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanSizePolicy():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanSizePolicy(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanSizePolicy &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanSizePolicy: "+other.GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanSizePolicy(){};
/**
* enumeration type for SizePolicy
*/
enum EnumSpanSizePolicy{SpanSizePolicy_Unknown,SpanSizePolicy_ClipToMaxPage,SpanSizePolicy_FitToPage,SpanSizePolicy_ReduceToFit,SpanSizePolicy_Tile};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanGrainDirection : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanGrainDirection():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanGrainDirection(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanGrainDirection &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanGrainDirection: "+other.GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanGrainDirection(){};
/**
* enumeration type for GrainDirection
*/
enum EnumSpanGrainDirection{SpanGrainDirection_Unknown,SpanGrainDirection_ShortEdge,SpanGrainDirection_LongEdge};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};


///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanNamedColor : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanNamedColor():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanNamedColor(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanNamedColor &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanNamedColor: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanNamedColor(){};
public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanJacket : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanJacket():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanJacket(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanJacket &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanJacket: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanJacket(){};
/**
* enumeration type for Jacket
*/
enum EnumSpanJacket{SpanJacket_Unknown,SpanJacket_None,SpanJacket_Loose,SpanJacket_Glue};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanTightBacking : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanTightBacking():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanTightBacking(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanTightBacking &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanTightBacking: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanTightBacking(){};
/**
* enumeration type for TightBacking
*/
enum EnumSpanTightBacking{SpanTightBacking_Unknown,SpanTightBacking_Flat,SpanTightBacking_Round,SpanTightBacking_FlatBacked,SpanTightBacking_RoundBacked};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanHoleType : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanHoleType():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanHoleType(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanHoleType &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanHoleType: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanHoleType(){};
public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanGlueProcedure : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanGlueProcedure():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanGlueProcedure(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanGlueProcedure &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanGlueProcedure: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanGlueProcedure(){};
/**
* enumeration type for GlueProcedure
*/
enum EnumSpanGlueProcedure{SpanGlueProcedure_Unknown,SpanGlueProcedure_Spine,SpanGlueProcedure_SideOnly,SpanGlueProcedure_SingleSide,SpanGlueProcedure_SideSpine};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanWireCombShape : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanWireCombShape():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanWireCombShape(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanWireCombShape &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanWireCombShape: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanWireCombShape(){};
/**
* enumeration type for WireCombShape
*/
enum EnumSpanWireCombShape{SpanWireCombShape_Unknown,SpanWireCombShape_Single,SpanWireCombShape_Twin};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanBindingType : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanBindingType():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanBindingType(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanBindingType &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanBindingType: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanBindingType(){};
/**
* enumeration type for BindingType
*/
	enum EnumSpanBindingType{SpanBindingType_Unknown,SpanBindingType_Adhesive,SpanBindingType_ChannelBinding,SpanBindingType_CoilBinding,SpanBindingType_CornerStitch,SpanBindingType_EdgeGluing,SpanBindingType_HardCover,SpanBindingType_LooseBinding,SpanBindingType_PlasticComb,SpanBindingType_Ring,SpanBindingType_SaddleStitch,SpanBindingType_Sewn,SpanBindingType_SideSewn,SpanBindingType_SideStitch,SpanBindingType_SoftCover,SpanBindingType_StripBind,SpanBindingType_Tape,SpanBindingType_ThreadSealing,SpanBindingType_WireComb};
		

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanBindingLength : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanBindingLength():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanBindingLength(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanBindingLength &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanBindingLength: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanBindingLength(){};
/**
* enumeration type for BindingLength
*/
enum EnumSpanBindingLength{SpanBindingLength_Unknown,SpanBindingLength_Long,SpanBindingLength_Short};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanBindingSide : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanBindingSide():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanBindingSide(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanBindingSide &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanBindingSide: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanBindingSide(){};
/**
* enumeration type for BindingSide
*/
enum EnumSpanBindingSide{SpanBindingSide_Unknown,SpanBindingSide_Top,SpanBindingSide_Bottom,SpanBindingSide_Right,SpanBindingSide_Left};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanSurplusHandling : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanSurplusHandling():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanSurplusHandling(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanSurplusHandling &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanSurplusHandling: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanSurplusHandling(){};
/**
* enumeration type for SurplusHandling
*/
enum EnumSpanSurplusHandling{SpanSurplusHandling_Unknown,SpanSurplusHandling_ReturnWithProduct,SpanSurplusHandling_Return,SpanSurplusHandling_Pickup,SpanSurplusHandling_Destroy,SpanSurplusHandling_PrinterOwns,SpanSurplusHandling_Store};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanDirection : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanDirection():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanDirection(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanDirection &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanDirection: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanDirection(){};
/**
* enumeration type for Direction
*/
enum EnumSpanDirection{SpanDirection_Unknown,SpanDirection_Both,SpanDirection_Depressed,SpanDirection_Raised};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanEdgeShape : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanEdgeShape():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanEdgeShape(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanEdgeShape &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanEdgeShape: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanEdgeShape(){};
/**
* enumeration type for EdgeShape
*/
enum EnumSpanEdgeShape{SpanEdgeShape_Unknown,SpanEdgeShape_Rounded,SpanEdgeShape_Beveled};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanLevel : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanLevel():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanLevel(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanLevel &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanLevel: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanLevel(){};
/**
* enumeration type for Level
*/
enum EnumSpanLevel{SpanLevel_Unknown,SpanLevel_SingleLevel,SpanLevel_MultiLevel,SpanLevel_Sculpted};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanGlueType : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanGlueType():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanGlueType(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanGlueType &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanGlueType: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanGlueType(){};
/**
* enumeration type for GlueType
*/
enum EnumSpanGlueType{SpanGlueType_Unknown,SpanGlueType_Removable,SpanGlueType_Permanent};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanMethod : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanMethod():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanMethod(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanMethod &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanMethod: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanMethod(){};
/**
* enumeration type for Method
*/
enum EnumSpanMethod{SpanMethod_Unknown,SpanMethod_BindIn,SpanMethod_BlowIn};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanTemperature : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanTemperature():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanTemperature(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanTemperature &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanTemperature: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanTemperature(){};
/**
* enumeration type for Temperature
*/
enum EnumSpanTemperature{SpanTemperature_Unknown,SpanTemperature_Hot,SpanTemperature_Cold};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanSurface : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanSurface():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanSurface(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanSurface &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanSurface: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanSurface(){};
/**
* enumeration type for Surface
*/
enum EnumSpanSurface{SpanSurface_Unknown,SpanSurface_Front,SpanSurface_Back,SpanSurface_Both};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanCoatings : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanCoatings():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanCoatings(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanCoatings &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanCoatings: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanCoatings(){};
/**
* enumeration type for Coatings
*/
enum EnumSpanCoatings{SpanCoatings_Unknown,SpanCoatings_None,SpanCoatings_Coated,SpanCoatings_Glossy,SpanCoatings_HighGloss,SpanCoatings_InkJet,SpanCoatings_Matte,SpanCoatings_Satin,SpanCoatings_Semigloss};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanMediaType : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanMediaType():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanMediaType(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanMediaType &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanMediaType: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanMediaType(){};
/**
* enumeration type for MediaType
*/
enum EnumSpanMediaType{SpanMediaType_Unknown,SpanMediaType_CorrugatedBoard,SpanMediaType_Disc,SpanMediaType_Other,SpanMediaType_Paper,SpanMediaType_SelfAdhesive,SpanMediaType_Transparency};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanMediaUnit : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanMediaUnit():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanMediaUnit(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanMediaUnit &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanMediaUnit: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanMediaUnit(){};
/**
* enumeration type for MediaUnit
*/
enum EnumSpanMediaUnit{SpanMediaUnit_Unknown,SpanMediaUnit_Roll,SpanMediaUnit_Sheet};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanOpacity : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanOpacity():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanOpacity(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanOpacity &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanOpacity: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanOpacity(){};
/**
* enumeration type for Opacity
*/
enum EnumSpanOpacity{SpanOpacity_Unknown,SpanOpacity_Opaque,SpanOpacity_Translucent,SpanOpacity_Transparent};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanPrintPreference : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanPrintPreference():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanPrintPreference(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanPrintPreference &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanPrintPreference: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanPrintPreference(){};
/**
* enumeration type for PrintPreference
*/
enum EnumSpanPrintPreference{SpanPrintPreference_Unknown,SpanPrintPreference_Fastest,SpanPrintPreference_Balanced,SpanPrintPreference_CostEffective,SpanPrintPreference_HighestQuality};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanPrintProcess : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanPrintProcess():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanPrintProcess(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanPrintProcess &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanPrintProcess: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanPrintProcess(){};
/**
* enumeration type for PrintProcess
*/
enum EnumSpanPrintProcess{SpanPrintProcess_Unknown,SpanPrintProcess_Electrophotography,SpanPrintProcess_Flexography,SpanPrintProcess_Gravure,SpanPrintProcess_Lithography,SpanPrintProcess_Letterpress,SpanPrintProcess_Screen,SpanPrintProcess_Inkjet,SpanPrintProcess_Thermography};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanColorType : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanColorType():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanColorType(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanColorType &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanColorType: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanColorType(){};
/**
* enumeration type for ColorType
*/
enum EnumSpanColorType{SpanColorType_Unknown,SpanColorType_Monochrome,SpanColorType_BasicColor,SpanColorType_MatchedColor};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanProofType : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanProofType():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanProofType(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanProofType &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanProofType: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanProofType(){};
/**
* enumeration type for ProofType
*/
enum EnumSpanProofType{SpanProofType_Unknown,SpanProofType_Page,SpanProofType_Imposition,SpanProofType_None};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanCutType : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanCutType():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanCutType(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanCutType &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanCutType: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanCutType(){};
/**
* enumeration type for CutType
*/
enum EnumSpanCutType{SpanCutType_Unknown,SpanCutType_Cut,SpanCutType_Perforate};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

class JDF_WRAPPERCORE_EXPORT JDFSpanShapeType : public JDFEnumerationSpan{
public:
/**
* null ctor
*/
	inline JDFSpanShapeType():JDFEnumerationSpan(){};
/**
* copy ctor
*/
	inline JDFSpanShapeType(const KElement & other):JDFEnumerationSpan(){
	*this=other;
};
/**
* copy equivalance operator
*/
	inline JDFSpanShapeType &operator =(const KElement& other){KElement::operator=(other);if(!IsValid(ValidationLevel_Construct)) throw JDFException(L"Invalid constructor for JDFSpanShapeType: "+GetNodeName()); return *this;};
/**
* dtor
*/
	virtual ~JDFSpanShapeType(){};
/**
* enumeration type for ShapeType
*/
enum EnumSpanShapeType{SpanShapeType_Unknown,SpanShapeType_Rectangular,SpanShapeType_Round,SpanShapeType_RoundedRectangle,SpanShapeType_Path};

public:
/**
* Returns the list of valid strings
*/
	 virtual WString AllowedValues()const;
};

///////////////////////////////////////////////////////////////

}
#endif //_JDFAutoEnumerationSpan_H_
