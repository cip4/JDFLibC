/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2003 The International Cooperation for the Integration of 
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
#include "jdf/wrapper/AutoJDF/JDFAutoEnumerationSpan.h"
#include "jdf/wrapper/JDFHoleMakingParams.h"

namespace JDF{


///////////////////////////////////////////////////////////////
	WString JDFSpanArtHandling::AllowedValues()const{
		return WString(L"Unknown,ReturnWithProof,ReturnWithProduct,Return,Pickup,Destroy,PrinterOwns,Store");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanDeliveryCharge::AllowedValues()const{
		return WString(L"Unknown,Printer,Buyer,Other");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanTransfer::AllowedValues()const{
		return WString(L"Unknown,BuyerToPrinterDeliver,BuyerToPrinterPickup,PrinterToBuyerDeliver,PrinterToBuyerPickup");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanScoring::AllowedValues()const{
		return WString(L"Unknown,TwiceScored,QuadScored,None");
	}


/////////////////////////////////////////////////////////////////////
	 WString JDFSpanFinishedGrainDirection::AllowedValues()const{
		return WString(L"Unknown,ParallelToBind,PerpendicularToBind");
	}

/////////////////////////////////////////////////////////////////////
	 WString JDFSpanFrequencySelection::AllowedValues()const{
		return WString(L"Unknown,LowestFrequency,MiddleFrequency,HighestFrequency");
	}

/////////////////////////////////////////////////////////////////////
	 WString JDFSpanScreeningType::AllowedValues()const{
		return WString(L"Unknown,AM,FM");
	}

///////////////////////////////////////////////////////////////
	 WString JDFSpanSizePolicy::AllowedValues()const{
		return WString(L"Unknown,ClipToMaxPage,FitToPage,ReduceToFit,Tile");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanGrainDirection::AllowedValues()const{
		return WString(L"Unknown,LongEdge,ShortEdge,XDirection,YDirection");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanShape::AllowedValues()const{
		return WString(L"Unknown,RoundedBack,SquareBack");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanCoilMaterial::AllowedValues()const{
		return WString(L"Unknown,Plastic,Steel,ColorCoatedSteel");
	}

///////////////////////////////////////////////////////////////
	 WString JDFSpanStripMaterial::AllowedValues()const{
		return WString(L"Unknown,Calico,Cardboard,CrepePaper,Gauze,Paper,PaperlinedMules,Tape");
	}

///////////////////////////////////////////////////////////////
	 WString JDFSpanWireCombMaterial::AllowedValues()const{
		return WString(L"Unknown,Steel_Silver,ColorCoatedSteel");
	}

///////////////////////////////////////////////////////////////
 	 WString JDFSpanImageStrategy::AllowedValues()const{
		return WString(L"Unknown,NoImages,LowResolution,HighResolution");
	}

///////////////////////////////////////////////////////////////
	 WString JDFSpanGlue::AllowedValues()const{
		return WString(L"Unknown,ColdGlue,Hotmelt,PUR");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanNamedColor::AllowedValues()const{
		return JDFElement::NamedColorString();
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanJacket::AllowedValues()const{
		return WString(L"Unknown,None,Loose,Glue");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanTightBacking::AllowedValues()const{
		return WString(L"Unknown,Flat,Round,FlatBacked,RoundBacked");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanHoleType::AllowedValues()const{
		return JDFHoleMakingParams::HoleTypeString();
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanGlueProcedure::AllowedValues()const{
		return WString(L"Unknown,Spine,SideOnly,SingleSide,SideSpine");
	}



///////////////////////////////////////////////////////////////
	 WString JDFSpanWireCombShape::AllowedValues()const{
		return WString(L"Unknown,Single,Twin");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanBindingType::AllowedValues()const{
		return WString(L"Unknown,Adhesive,ChannelBinding,CoilBinding,CornerStitch,EdgeGluing,HardCover,LooseBinding,PlasticComb,Ring,SaddleStitch,Sewn,SideSewn,SideStitch,SoftCover,StripBind,Tape,ThreadSealing,WireComb");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanBindingLength::AllowedValues()const{
		return WString(L"Unknown,Long,Short");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanBindingSide::AllowedValues()const{
		return WString(L"Unknown,Top,Bottom,Right,Left");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanSurplusHandling::AllowedValues()const{
		return WString(L"Unknown,ReturnWithProduct,Return,Pickup,Destroy,PrinterOwns,Store");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanDirection::AllowedValues()const{
		return WString(L"Unknown,Both,Depressed,Raised");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanEdgeShape::AllowedValues()const{
		return WString(L"Unknown,Rounded,Beveled");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanLevel::AllowedValues()const{
		return WString(L"Unknown,SingleLevel,MultiLevel,Sculpted");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanGlueType::AllowedValues()const{
		return WString(L"Unknown,Removable,Permanent");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanMethod::AllowedValues()const{
		return WString(L"Unknown,BindIn,BlowIn");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanTemperature::AllowedValues()const{
		return WString(L"Unknown,Hot,Cold");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanSurface::AllowedValues()const{
		return WString(L"Unknown,Front,Back,Both");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanCoatings::AllowedValues()const{
		return WString(L"Unknown,None,Coated,Glossy,HighGloss,InkJet,Matte,Satin,Semigloss");
	}

///////////////////////////////////////////////////////////////
	 WString JDFSpanMediaType::AllowedValues()const{
		return WString(L"Unknown,CorrugatedBoard,Disc,Other,Paper,SelfAdhesive,Transparency");
	}
///////////////////////////////////////////////////////////////
	 WString JDFSpanMediaUnit::AllowedValues()const{
		return WString(L"Unknown,Roll,Sheet");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanOpacity::AllowedValues()const{
		return WString(L"Unknown,Opaque,Translucent,Transparent");
	}



///////////////////////////////////////////////////////////////
	 WString JDFSpanPrintPreference::AllowedValues()const{
		return WString(L"Unknown,Fastest,Balanced,CostEffective,HighestQuality");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanPrintProcess::AllowedValues()const{
		return WString(L"Unknown,Electrophotography,Flexography,Gravure,Lithography,Letterpress,Screen,Inkjet,Thermography");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanColorType::AllowedValues()const{
		return WString(L"Unknown,Monochrome,BasicColor,MatchedColor");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanProofType::AllowedValues()const{
		return WString(L"Unknown,Page,Imposition,None");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanCutType::AllowedValues()const{
		return WString(L"Unknown,Cut,Perforate");
	}


///////////////////////////////////////////////////////////////
	 WString JDFSpanShapeType::AllowedValues()const{
		return WString(L"Unknown,Rectangular,Round,RoundedRectangle,Path");
	}
}
