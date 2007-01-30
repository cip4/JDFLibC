/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2005 The International Cooperation for the Integration of 
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

//EndCopyRight#include "JDFElement.h"
#include "JDFFactory.h"
#include "JDFSpan.h"
#include "JDFJMF.h"

#include "JDFArtDeliveryIntent.h"
#include "JDFBindingIntent.h"
#include "JDFColorIntent.h"
#include "JDFDeliveryIntent.h"
#include "JDFDropIntent.h"
#include "JDFEmbossingIntent.h"
#include "JDFDropItemIntent.h"
#include "JDFFoldingIntent.h"
#include "JDFHoleMakingIntent.h"
#include "JDFInsertingIntent.h"
#include "JDFLaminatingIntent.h"
#include "JDFLayoutIntent.h"
#include "JDFMediaIntent.h"
#include "JDFNumberingIntent.h"
#include "JDFPackingIntent.h"
#include "JDFProductionIntent.h"
#include "JDFProofingIntent.h"
#include "JDFShapeCuttingIntent.h"
#include "JDFScreeningIntent.h"
#include "JDFSizeIntent.h"

#include "JDFPool.h"
#include "JDFActionPool.h"
#include "JDFAmountPool.h"
#include "JDFAncestorPool.h"
#include "JDFAuditPool.h"
#include "JDFColorPool.h"
#include "JDFCreateLink.h"
#include "JDFDisplayGroupPool.h"
#include "JDFFeaturePool.h"
#include "JDFMacroPool.h"
#include "JDFResourcePool.h"
#include "JDFRemoveLink.h"
#include "JDFResourceLinkPool.h"
#include "JDFResourcePool.h"
#include "JDFStatusPool.h"
#include "JDFTestPool.h"
#include "JDFTransferCurvePool.h"




using namespace std;
namespace JDF{
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	JDFElement* JDFFactory::init(const WString &resName, const WString &typ, const JDFElement &part)
	{
		JDFElement* pe=0;
		
		// it is a link
		if(resName==JDFElement::elm_JDF){
			return new JDFNode(part);
		} else if(resName.rightStr(4)==JDFElement::atr_Link) {
			JDFCh c=resName[0];
			const JDFCh* pc=resName.c_str();

			if((c=='C')&&!wcscmp(pc,JDFElement::elm_CreateLink.c_str())){
				return new JDFCreateLink(part);
			}else if((c=='R')&&!wcscmp(pc,JDFElement::elm_RemoveLink.c_str())){
				return new JDFRemoveLink(part);
			}else{
				return new JDFResourceLink(part);
			}
		}
		
		if(!pe&&!typ.empty()){
			const JDFCh*  pcTyp=typ.c_str();
			
			// span type objects
			if(!wcscmp(pcTyp,L"XYPairSpan")) 
				return new JDFXYPairSpan(part);
			if(!wcscmp(pcTyp,L"OptionSpan")) 
				return new JDFOptionSpan(part);
			if(!wcscmp(pcTyp,L"NameSpan")) 
				return new JDFNameSpan(part);
			if(!wcscmp(pcTyp,L"IntegerSpan")) 
				return new JDFIntegerSpan(part);
			if(!wcscmp(pcTyp,L"NumberSpan")) 
				return new JDFNumberSpan(part);
			if(!wcscmp(pcTyp,L"StringSpan")) 
				return new JDFStringSpan(part);
			if(!wcscmp(pcTyp,L"TimeSpan")) 
				return new JDFTimeSpan(part);
			if(!wcscmp(pcTyp,L"ShapeSpan")) 
				return new JDFShapeSpan(part);
			if(!wcscmp(pcTyp,L"DurationSpan")) 
				return new JDFDurationSpan(part);
		}
		
		// ResourceUpdate elements
		WString res6=resName.rightStr(6);
		if(res6==JDFElement::atr_Update){
			pe=init(resName.leftStr(-6),typ,part);
		}else if ( res6 == JDFElement::atr_Intent ){
			pe=initIntent(resName,typ,part);
		}else if (res6 == JDFElement::atr_Params ){
			pe= initParams(resName,typ,part);
		}else if (resName.rightStr(4) == JDFElement::atr_Pool ){
			pe= initPool(resName,typ,part);
		}else if(resName==JDFElement::elm_JMF){
			pe=new JDFJMF(part);
		};		
		
		if(!pe){
			pe=initRest(resName,typ,part);
		}
		if(!pe){
			if(!part.isNull()){
				if (part.IsResource(false))
					return new JDFResource(part);
			}				
			return new JDFElement(part);
		}
		return pe;
	}
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	JDFElement* JDFFactory::initIntent(const WString &resName, const WString &typ, const JDFElement &part){
		
		
		
		if(resName.empty())
			return 0;
		
		const JDFCh* pcResName=resName.c_str();
		JDFCh c=*pcResName;
		
		if(c==L'A'){
			if(!wcscmp(pcResName,JDFElement::elm_ArtDeliveryIntent.c_str())){
				return new JDFArtDeliveryIntent(part);
			};
		}else if (c==L'B'){
			if(!wcscmp(pcResName,JDFElement::elm_BindingIntent.c_str())){
				return new JDFBindingIntent(part);
			};
		}else if (c==L'C'){
			if(!wcscmp(pcResName,JDFElement::elm_ColorIntent.c_str())){
				return new JDFColorIntent(part);
			};
		}else if (c==L'D'){
			if(!wcscmp(pcResName,JDFElement::elm_DeliveryIntent.c_str())){
				return new JDFDeliveryIntent(part);
			};
			
			if(!wcscmp(pcResName,JDFElement::elm_DropIntent.c_str())){
				return new JDFDropIntent(part);
			};
			
			if(!wcscmp(pcResName,JDFElement::elm_DropItemIntent.c_str())){
				return new JDFDropItemIntent(part);
			};
			
		}else if (c==L'E'){
			if(!wcscmp(pcResName,JDFElement::elm_EmbossingIntent.c_str())){
				return new JDFEmbossingIntent(part);
			};
			
		}else if (c==L'F'){
			if(!wcscmp(pcResName,JDFElement::elm_FoldingIntent.c_str())){
				return new JDFFoldingIntent(part);
			};
			
		}else if (c==L'H'){
			if(!wcscmp(pcResName,JDFElement::elm_HoleMakingIntent.c_str())){
				return new JDFHoleMakingIntent(part);
			};
			
		}else if (c==L'I'){
			if(!wcscmp(pcResName,JDFElement::elm_InsertingIntent.c_str())){
				return new JDFInsertingIntent(part);
			};
			
		}else if (c==L'L'){
			if(!wcscmp(pcResName,JDFElement::elm_LaminatingIntent.c_str())){
				return new JDFLaminatingIntent(part);
			};
			
			if(!wcscmp(pcResName,JDFElement::elm_LayoutIntent.c_str())){
				return new JDFLayoutIntent(part);
			};
			
		}else if (c==L'M'){
			if(!wcscmp(pcResName,JDFElement::elm_MediaIntent.c_str())){
				return new JDFMediaIntent(part);
			};
			
		}else if (c==L'N'){
			if(!wcscmp(pcResName,JDFElement::elm_NumberingIntent.c_str())){
				return new JDFNumberingIntent(part);
			};
			
		}else if (c==L'P'){
			if(!wcscmp(pcResName,JDFElement::elm_PackingIntent.c_str())){
				return new JDFPackingIntent(part);
			};
			
			if(!wcscmp(pcResName,JDFElement::elm_ProductionIntent.c_str())){
				return new JDFProductionIntent(part);
			};
			
			if(!wcscmp(pcResName,JDFElement::elm_ProofingIntent.c_str())){
				return new JDFProofingIntent(part);
			};
			
		}else if (c==L'S'){
			if(!wcscmp(pcResName,JDFElement::elm_ShapeCuttingIntent.c_str())){
				return new JDFShapeCuttingIntent(part);
			};
			
			if(!wcscmp(pcResName,JDFElement::elm_ScreeningIntent.c_str())){
				return new JDFScreeningIntent(part);
			};

			if(!wcscmp(pcResName,JDFElement::elm_SizeIntent.c_str())){
				return new JDFSizeIntent(part);
			};
		}
		return 0;
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	JDFElement* JDFFactory::initPool(const WString &resName, const WString &typ, const JDFElement &part){
		
		const JDFCh* pcResName=resName.c_str();
		
		if(!wcscmp(pcResName,JDFElement::elm_ActionPool.c_str())){
			return new JDFActionPool(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_AmountPool.c_str())){
			return new JDFAmountPool(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_AncestorPool.c_str())){
			return new JDFAncestorPool(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_AuditPool.c_str())){
			return new JDFAuditPool(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ColorPool.c_str())){
			return new JDFColorPool(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_DisplayGroupPool.c_str())){
			return new JDFDisplayGroupPool(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_FeaturePool.c_str())){
			return new JDFFeaturePool(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_MacroPool.c_str())){
			return new JDFMacroPool(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_ResourceLinkPool.c_str())){
			return new JDFResourceLinkPool(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ResourcePool.c_str())){
			return new JDFResourcePool(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_StatusPool.c_str())){
			return new JDFStatusPool(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_TestPool.c_str())){
			return new JDFTestPool(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_TransferCurvePool.c_str())){
			return new JDFTransferCurvePool(part);
		};
			
		return 0;
	}
	
	
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	JDFElement* JDFFactory::initSpan(const WString &resName, const WString &typ, const JDFElement &part){
		
		// generic spans
		const JDFCh* pcResName=resName.c_str();
		
		static const WString sIntegerSpan=L"StitchNumber,Pages,PageVariance,Grade,HoleCount,BoxedQuantity,CartonQuantity,PalletQuantity,WrappedQuantity,Amount";
		if(sIntegerSpan.HasToken(resName,WString::comma)){
			return new JDFIntegerSpan(part);
		};
		
		static const WString sNameSpan=L"Method,ReturnMethod,PlasticCombType,BinderMaterial,RingShape,RingSystem,ViewBinder,ColorStandard,InkManufacturer,FoldingCatalog,StockType,Texture,PalletType,PalletWrapping,WrappingMaterial,Technology";
		if(sNameSpan.HasToken(resName,WString::comma)){
			return new JDFNameSpan(part);
		};
		
		static const WString sNumberSpan=L"RecycledPercentage,OpacityLevel,Thickness,RingDiameter,TabExtensionDistance,Coverage,Overage,Underage,EdgeAngle,Height,Brightness,USWeight,Weight,XPosition,YPosition,Orientation,CartonMaxWeight,CartonStrength,PalletMaxHeight,PalletMaxWeight,ShapeDepth,TeethPerDimension,DotSize,Frequency";
		if(sNumberSpan.HasToken(resName,WString::comma)){
			return new JDFNumberSpan(part);
		};
		
		static const WString sOptionSpan=L"TapeBinding,Headbands,Cover,BlockThreadSewing,EndSheets,HeadBands,JapanBind,SpineBrushing,SpineFiberRoughing,SpineLevelling,SpineMilling,SpineNotching,SpineSanding,SpineShredding,RingMechanic,RivetsExposed,SpineFibreRoughing,TabExtensionMylar,TabBindMylar,TabBodyCopy,Laminated,BuyerSupplied,Recycled,HalfTone";
		if(sOptionSpan.HasToken(resName,WString::comma)){
			return new JDFOptionSpan(part);
		};
		
		static const WString sXYPairSpan=L"ImageSize,Position,Dimensions,PalletSize";
		if(sXYPairSpan.HasToken(resName,WString::comma)){
			return new JDFXYPairSpan(part);
		};
		
		static const WString sStringSpan=L"MediaColorDetails,ServiceLevel,Coatings,EmbossingType,HoleType,StockBrand,BrandName,Material";
		if(sStringSpan.HasToken(resName,WString::comma)){
			return new JDFStringSpan(part);
		};
		
		static const WString sTimeSpan=L"ArtDeliveryDate,Earliest,Required";
		if(sTimeSpan.HasToken(resName,WString::comma)){
			return new JDFTimeSpan(part);
		};
		
		static const WString sShapeSpan=L"FinishedDimensions,BoxShape,CartonShape";
		if(sShapeSpan.HasToken(resName,WString::comma)){
			return new JDFShapeSpan(part);
		};
		
		static const WString sDurationSpan=L"ArtDeliveryDuration,EarliestDuration,RequiredDuration";
		if(sDurationSpan.HasToken(resName,WString::comma)){
			return new JDFDurationSpan(part);
		};
		
		JDFCh first=*pcResName;
		
		if(first==L'A'){
			// specific enumeration spans
			if(!wcscmp(pcResName,JDFElement::elm_ArtHandling.c_str())){
				return new JDFSpanArtHandling(part);
			};
		}else if (first==L'B'){
			if(!wcscmp(pcResName,JDFElement::elm_BackCoverColor.c_str())){
				return new JDFSpanNamedColor(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_BindingType.c_str())){
				return new JDFSpanBindingType(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_BindingColor.c_str())){
				return new JDFSpanNamedColor(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_BindingLength.c_str())){
				return new JDFSpanBindingLength(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_BindingSide.c_str())){
				return new JDFSpanBindingSide(part);
			};
			
			if(!wcscmp(pcResName,JDFElement::elm_BackCoatings.c_str())){
				return new JDFSpanCoatings(part);
			};
		}else if (first==L'C'){
			
			if(!wcscmp(pcResName,JDFElement::elm_CoilMaterial.c_str())){
				return new JDFSpanCoilMaterial(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_CoverColor.c_str())){
				return new JDFSpanNamedColor(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_ColorType.c_str())){
				return new JDFSpanColorType(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_ColorName.c_str())){
				return new JDFSpanNamedColor(part);
			};
			
			if(!wcscmp(pcResName,JDFElement::elm_CutType.c_str())){
				return new JDFSpanCutType(part);
			};
		}else if (first==L'D'){
			if(!wcscmp(pcResName,JDFElement::elm_DeliveryCharge.c_str())){
				return new JDFSpanDeliveryCharge(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_Direction.c_str())){
				return new JDFSpanDirection(part);
			};
		}else if (first==L'E'){
			if(!wcscmp(pcResName,JDFElement::elm_EdgeShape.c_str())){
				return new JDFSpanEdgeShape(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_EdgeGlue.c_str())){
				return new JDFSpanGlue(part);
			};
		}else if (first==L'F'){
			if(!wcscmp(pcResName,JDFElement::elm_FinishedGrainDirection.c_str())){
				return new JDFSpanFinishedGrainDirection(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_FoilColor.c_str())){
				return new JDFSpanNamedColor(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_FrontCoatings.c_str())){
				return new JDFSpanCoatings(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_FrequencySelection.c_str())){
				return new JDFSpanFrequencySelection(part);
			};
		}else if (first==L'G'){
			if(!wcscmp(pcResName,JDFElement::elm_GlueProcedure.c_str())){
				return new JDFSpanGlueProcedure(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_GlueType.c_str())){
				return new JDFSpanGlueType(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_GrainDirection.c_str())){
				return new JDFSpanGrainDirection(part);
			};
		}else if (first==L'H'){
			if(!wcscmp(pcResName,JDFElement::elm_HeadBandColor.c_str())){
				return new JDFSpanNamedColor(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_HoleType.c_str())){
				return new JDFSpanHoleType(part);
			};
		}else if (first==L'I'){
			if(!wcscmp(pcResName,JDFElement::elm_ImageStrategy.c_str())){
				return new JDFSpanImageStrategy(part);
			};
		}else if (first==L'J'){
			if(!wcscmp(pcResName,JDFElement::elm_Jacket.c_str())){
				return new JDFSpanJacket(part);
			};
		}else if (first==L'L'){
			if(!wcscmp(pcResName,JDFElement::elm_Level.c_str())){
				return new JDFSpanLevel(part);
			};
		}else if (first==L'M'){
			if(!wcscmp(pcResName,JDFElement::elm_Method.c_str())){
				return new JDFSpanMethod(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_MediaColor.c_str())){
				return new JDFSpanNamedColor(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_MediaType.c_str())){
				return new JDFSpanMediaType(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_MediaUnit.c_str())){
				return new JDFSpanMediaUnit(part);
			};
		}else if (first==L'O'){
			if(!wcscmp(pcResName,JDFElement::elm_Opacity.c_str())){
				return new JDFSpanOpacity(part);
			};
		}else if (first==L'P'){
			if(!wcscmp(pcResName,JDFElement::elm_PrintPreference.c_str())){
				return new JDFSpanPrintPreference(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_PrintProcess.c_str())){
				return new JDFSpanPrintProcess(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_ProofType.c_str())){
				return new JDFSpanProofType(part);
			};
		}else if (first==L'S'){
			if(!wcscmp(pcResName,JDFElement::elm_Scoring.c_str())){
				return new JDFSpanScoring(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_ScreeningType.c_str())){
				return new JDFSpanScreeningType(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_SizePolicy.c_str())){
				return new JDFSpanSizePolicy(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_SpineGlue.c_str())){
				return new JDFSpanGlue(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_StripMaterial.c_str())){
				return new JDFSpanStripMaterial(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_SurplusHandling.c_str())){
				return new JDFSpanSurplusHandling(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_ShapeType.c_str())){
				return new JDFSpanShapeType(part);
			};
		}else if (first==L'T'){
			if(!wcscmp(pcResName,JDFElement::elm_TightBacking.c_str())){
				return new JDFSpanTightBacking(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_TapeColor.c_str())){
				return new JDFSpanNamedColor(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_TabMylarColor.c_str())){
				return new JDFSpanNamedColor(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_Temperature.c_str())){
				return new JDFSpanTemperature(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_Transfer.c_str())){
				return new JDFSpanTransfer(part);
			};
		}else if (first==L'W'){
			if(!wcscmp(pcResName,JDFElement::elm_WireCombMaterial.c_str())){
				return new JDFSpanWireCombMaterial(part);
			};
			if(!wcscmp(pcResName,JDFElement::elm_WireCombShape.c_str())){
				return new JDFSpanWireCombShape(part);
			};
		}else if (first==L'Z'){
		}
		
		
		
		
	
		/////////////////////////////////////// end of enumerationspan part ///////////////////////////////////////
		
		
		
		return 0;
	}

	
}
