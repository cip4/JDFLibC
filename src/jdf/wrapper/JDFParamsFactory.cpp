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
#include "JDFFactory.h"
#include "JDFElement.h"

#include "JDFAdhesiveBindingParams.h"
#include "JDFAdvancedParams.h"
#include "JDFApprovalParams.h"
#include "JDFAssetListCreationParams.h"
#include "JDFAuthenticationCmdParams.h"
#include "JDFAuthenticationQuParams.h"
#include "JDFAutomatedOverPrintParams.h"

#include "JDFBarcodeCompParams.h"
#include "JDFBarcodeProductionParams.h"
#include "JDFBarcodeReproParams.h"
#include "JDFBindingQualityParams.h"
#include "JDFBlockPreparationParams.h"
#include "JDFBoxPackingParams.h"
#include "JDFBufferParams.h"
#include "JDFBundlingParams.h"

#include "JDFCaseMakingParams.h"
#include "JDFCasingInParams.h"
#include "JDFCCITTFaxParams.h"
#include "JDFChannelBindingParams.h"
#include "JDFCoilBindingParams.h"
#include "JDFCollectingParams.h"
#include "JDFColorCorrectionParams.h"
#include "JDFColorSpaceConversionParams.h"
#include "JDFContactCopyParams.h"
#include "JDFConventionalPrintingParams.h"
#include "JDFCoverApplicationParams.h"
#include "JDFCreasingParams.h"
#include "JDFCuttingParams.h"

#include "JDFDBMergeParams.h"
#include "JDFDCTParams.h"
#include "JDFDeliveryParams.h"
#include "JDFDevelopingParams.h"
#include "JDFDieLayoutProductionParams.h"
#include "JDFDigitalDeliveryParams.h"
#include "JDFDigitalPrintingParams.h"
#include "JDFDividingParams.h"

#include "JDFElementColorParams.h"
#include "JDFEmbossingParams.h"
#include "JDFEndSheetGluingParams.h"

#include "JDFFeederQualityParams.h"
#include "JDFFeedingParams.h"
#include "JDFFlateParams.h"
#include "JDFFlushResourceParams.h"
#include "JDFFlushQueueParams.h"
#include "JDFFoldingParams.h"
#include "JDFFontParams.h"
#include "JDFFormatConversionParams.h"

#include "JDFGatheringParams.h"
#include "JDFGluingParams.h"

#include "JDFHeadBandApplicationParams.h"
#include "JDFHoleMakingParams.h"

#include "JDFIDPrintingParams.h"
#include "JDFImageCompressionParams.h"
#include "JDFImageReplacementParams.h"
#include "JDFImageSetterParams.h"
#include "JDFInkZoneCalculationParams.h"
#include "JDFInsertingParams.h"
#include "JDFInterpretingParams.h"

#include "JDFJacketingParams.h"
#include "JDFJBIG2Params.h"
#include "JDFJPEG2000Params.h"

#include "JDFKnownMsgQuParams.h"

#include "JDFLabelingParams.h"
#include "JDFLaminatingParams.h"
#include "JDFLayoutPreparationParams.h"
#include "JDFLongitudinalRibbonOperationParams.h"
#include "JDFLZWParams.h"

#include "JDFManualLaborParams.h"

#include "JDFNewJDFCmdParams.h"
#include "JDFNewJDFQuParams.h"
#include "JDFNodeInfoCmdParams.h"
#include "JDFNodeInfoQuParams.h"
#include "JDFNumberingParams.h"

#include "JDFOrderingParams.h"

#include "JDFPackingParams.h"
#include "JDFPageAssignParams.h"
#include "JDFPalletizingParams.h"
#include "JDFPDFInterpretingParams.h"
#include "JDFPDFToPSConversionParams.h"
#include "JDFPDFXParams.h"
#include "JDFPerforatingParams.h"
#include "JDFPlasticCombBindingParams.h"
#include "JDFPlateCopyParams.h"
#include "JDFPreviewGenerationParams.h"
#include "JDFPrintRollingParams.h"
#include "JDFProofingParams.h"
#include "JDFPSToPDFConversionParams.h"
#include "JDFPipeParams.h"

#include "JDFQualityControlParams.h"
#include "JDFQueueEntryPosParams.h"
#include "JDFQueueEntryPriParams.h"
#include "JDFQueueSubmissionParams.h"

#include "JDFReferenceXObjParams.h"
#include "JDFRequestQueueEntryParams.h"
#include "JDFRenderingParams.h"
#include "JDFResourceCmdParams.h"
#include "JDFResourceQuParams.h"
#include "JDFResourceDefinitionParams.h"
#include "JDFResourcePullParams.h"
#include "JDFResubmissionParams.h"
#include "JDFReturnQueueEntryParams.h"
#include "JDFRingBindingParams.h"

#include "JDFSaddleStitchingParams.h"
#include "JDFScanParams.h"
#include "JDFScreeningParams.h"
#include "JDFSeparationControlParams.h"
#include "JDFSeparationList.h"
#include "JDFShapeCuttingParams.h"
#include "JDFShapeDefProductionParams.h"
#include "JDFShrinkingParams.h"
#include "JDFShutDownCmdParams.h"
#include "JDFSideSewingParams.h"
#include "JDFSpinePreparationParams.h"
#include "JDFSpineTapingParams.h"
#include "JDFStackingParams.h"
#include "JDFStopPersChParams.h"
#include "JDFStatusQuParams.h"
#include "JDFStrappingParams.h"
#include "JDFStitchingParams.h"
#include "JDFStripBindingParams.h"
#include "JDFStripCellParams.h"
#include "JDFStrippingParams.h"

#include "JDFTIFFFormatParams.h"
#include "JDFThinPDFParams.h"
#include "JDFThreadSealingParams.h"
#include "JDFThreadSewingParams.h"
#include "JDFTrappingParams.h"
#include "JDFTrimmingParams.h"

#include "JDFVerificationParams.h"
#include "JDFVarnishingParams.h"

#include "JDFWakeUpCmdParams.h"
#include "JDFWireCombBindingParams.h"
#include "JDFWrappingParams.h"

namespace JDF{

	JDFElement* JDFFactory::initParams(const WString &resName, const WString &typ, const JDFElement &part){

		if(resName.empty())
			return 0;

		const JDFCh*pcResName=resName.c_str();
		JDFCh c=*pcResName;

		JDFElement*pE=0;

		if(c==L'A'){

			pE=initParamsA(pcResName,typ,part);

		}else if (c==L'B'){

			pE=initParamsB(pcResName,typ,part);

		}else if (c==L'C'){

			pE=initParamsC(pcResName,typ,part);

		}else if (c==L'D'){

			pE=initParamsD(pcResName,typ,part);

		}else if (c==L'E'){

			pE=initParamsE(pcResName,typ,part);

		}else if (c==L'F'){

			pE=initParamsF(pcResName,typ,part);

		}else if (c==L'G'){

			pE=initParamsG(pcResName,typ,part);

		}else if (c==L'H'){

			pE=initParamsH(pcResName,typ,part);

		}else if (c==L'I'){

			pE=initParamsI(pcResName,typ,part);

		}else if (c==L'J'){

			pE=initParamsJ(pcResName,typ,part);

		}else if (c==L'K'){

			pE=initParamsK(pcResName,typ,part);

		}else if (c==L'L'){

			pE=initParamsL(pcResName,typ,part);

		}else if (c==L'M'){

			pE=initParamsM(pcResName,typ,part);

		}else if (c==L'N'){

			pE=initParamsN(pcResName,typ,part);

		}else if (c==L'O'){

			pE=initParamsO(pcResName,typ,part);

		}else if (c==L'P'){

			pE=initParamsP(pcResName,typ,part);

		}else if (c==L'Q'){

			pE=initParamsQ(pcResName,typ,part);

		}else if (c==L'R'){

			pE=initParamsR(pcResName,typ,part);

		}else if (c==L'S'){

			pE=initParamsS(pcResName,typ,part);

		}else if (c==L'T'){

			pE=initParamsT(pcResName,typ,part);

		}else if (c==L'V'){

			pE=initParamsV(pcResName,typ,part);

		}else if (c==L'W'){

			pE=initParamsW(pcResName,typ,part);
		}

		return pE;
	}



	JDFElement* JDFFactory::initParamsA(const JDFCh* pcResName, const WString &typ, const JDFElement &part){

		if(!wcscmp(pcResName,JDFElement::elm_AdhesiveBindingParams.c_str())){
			return new JDFAdhesiveBindingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_AdvancedParams.c_str())){
			return new JDFAdvancedParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ApprovalParams.c_str())){
			return new JDFApprovalParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_AssetListCreationParams.c_str())){
			return new JDFAssetListCreationParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_AutomatedOverPrintParams.c_str())){
			return new JDFAutomatedOverPrintParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_AuthenticationCmdParams.c_str())){
			return new JDFAuthenticationCmdParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_AuthenticationQuParams.c_str())){
			return new JDFAuthenticationQuParams(part);
		};
		return 0;
	}

	// BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB

	JDFElement* JDFFactory::initParamsB(const JDFCh* pcResName, const WString &typ, const JDFElement &part){

		if(!wcscmp(pcResName,JDFElement::elm_BarcodeCompParams.c_str())){
			return new JDFBarcodeCompParams(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_BarcodeReproParams.c_str())){
			return new JDFBarcodeReproParams(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_BarcodeProductionParams.c_str())){
			return new JDFBarcodeProductionParams(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_BindingQualityParams.c_str())){
			return new JDFBindingQualityParams(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_BlockPreparationParams.c_str())){
			return new JDFBlockPreparationParams(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_BoxPackingParams.c_str())){
			return new JDFBoxPackingParams(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_BufferParams.c_str())){
			return new JDFBufferParams(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_BundlingParams.c_str())){
			return new JDFBundlingParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsC(const JDFCh* pcResName, const WString &typ, const JDFElement &part){

		if(!wcscmp(pcResName,JDFElement::elm_CaseMakingParams.c_str())){
			return new JDFCaseMakingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_CasingInParams.c_str())){
			return new JDFCasingInParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_CCITTFaxParams.c_str())){
			return new JDFCCITTFaxParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ChannelBindingParams.c_str())){
			return new JDFChannelBindingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_CoilBindingParams.c_str())){
			return new JDFCoilBindingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_CollectingParams.c_str())){
			return new JDFCollectingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ColorantParams.c_str())){
			return new JDFSeparationList(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ColorCorrectionParams.c_str())){
			return new JDFColorCorrectionParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ColorSpaceConversionParams.c_str())){
			return new JDFColorSpaceConversionParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ContactCopyParams.c_str())){
			return new JDFContactCopyParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ConventionalPrintingParams.c_str())){
			return new JDFConventionalPrintingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_CoverApplicationParams.c_str())){
			return new JDFCoverApplicationParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_CreasingParams.c_str())){
			return new JDFCreasingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_CuttingParams.c_str())){
			return new JDFCuttingParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsD(const JDFCh* pcResName, const WString &typ, const JDFElement &part){

		if(!wcscmp(pcResName,JDFElement::elm_DBMergeParams.c_str())){
			return new JDFDBMergeParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_DCTParams.c_str())){
			return new JDFDCTParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_DeliveryParams.c_str())){
			return new JDFDeliveryParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_DevelopingParams.c_str())){
			return new JDFDevelopingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_DieLayoutProductionParams.c_str())){
			return new JDFDieLayoutProductionParams(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_DigitalDeliveryParams.c_str())){
			return new JDFDigitalDeliveryParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_DigitalPrintingParams.c_str())){
			return new JDFDigitalPrintingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_DividingParams.c_str())){
			return new JDFDividingParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsE(const JDFCh* pcResName, const WString &typ, const JDFElement &part){

		if(!wcscmp(pcResName,JDFElement::elm_ElementColorParams.c_str())){
			return new JDFElementColorParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_EmbossingParams.c_str())){
			return new JDFEmbossingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_EndSheetGluingParams.c_str())){
			return new JDFEndSheetGluingParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsF(const JDFCh* pcResName, const WString &typ, const JDFElement &part){

		if(!wcscmp(pcResName,JDFElement::elm_FeederQualityParams.c_str())){
			return new JDFFeederQualityParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_FeedingParams.c_str())){
			return new JDFFeedingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_FlateParams.c_str())){
			return new JDFFlateParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_FlushResourceParams.c_str())){
			return new JDFFlushResourceParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_FlushQueueParams.c_str())){
			return new JDFFlushQueueParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_FoldingParams.c_str())){
			return new JDFFoldingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_FontParams.c_str())){
			return new JDFFontParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_FormatConversionParams.c_str())){
			return new JDFFormatConversionParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsG(const JDFCh* pcResName, const WString &typ, const JDFElement &part){

		if(!wcscmp(pcResName,JDFElement::elm_GatheringParams.c_str())){
			return new JDFGatheringParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_GluingParams.c_str())){
			return new JDFGluingParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsH(const JDFCh* pcResName, const WString &typ, const JDFElement &part){

		if(!wcscmp(pcResName,JDFElement::elm_HeadBandApplicationParams.c_str())){
			return new JDFHeadBandApplicationParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_HoleMakingParams.c_str())){
			return new JDFHoleMakingParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsI(const JDFCh* pcResName, const WString &typ, const JDFElement &part){		

		if(!wcscmp(pcResName,JDFElement::elm_IDPrintingParams.c_str())){
			return new JDFIDPrintingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ImageCompressionParams.c_str())){
			return new JDFImageCompressionParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ImageReplacementParams.c_str())){
			return new JDFImageReplacementParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ImageSetterParams.c_str())){
			return new JDFImageSetterParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_InkZoneCalculationParams.c_str())){
			return new JDFInkZoneCalculationParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_InsertingParams.c_str())){
			return new JDFInsertingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_InterpretingParams.c_str())){
			return new JDFInterpretingParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsJ(const JDFCh* pcResName, const WString &typ, const JDFElement &part){		

		if(!wcscmp(pcResName,JDFElement::elm_JacketingParams.c_str())){
			return new JDFJacketingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_JBIG2Params.c_str())){
			return new JDFJBIG2Params(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_JPEG2000Params.c_str())){
			return new JDFJPEG2000Params(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsK(const JDFCh* pcResName, const WString &typ, const JDFElement &part){		

		if(!wcscmp(pcResName,JDFElement::elm_KnownMsgQuParams.c_str())){
			return new JDFKnownMsgQuParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsL(const JDFCh* pcResName, const WString &typ, const JDFElement &part){		

		if(!wcscmp(pcResName,JDFElement::elm_LabelingParams.c_str())){
			return new JDFLabelingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_LaminatingParams.c_str())){
			return new JDFLaminatingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_LayoutPreparationParams.c_str())){
			return new JDFLayoutPreparationParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_LongitudinalRibbonOperationParams.c_str())){
			return new JDFLongitudinalRibbonOperationParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_LZWParams.c_str())){
			return new JDFLZWParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsM(const JDFCh* pcResName, const WString &typ, const JDFElement &part){		

		if(!wcscmp(pcResName,JDFElement::elm_ManualLaborParams.c_str())){
			return new JDFManualLaborParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsN(const JDFCh* pcResName, const WString &typ, const JDFElement &part){		

		if(!wcscmp(pcResName,JDFElement::elm_NewJDFCmdParams.c_str())){
			return new JDFNewJDFCmdParams(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_NewJDFQuParams.c_str())){
			return new JDFNewJDFQuParams(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_NodeInfoCmdParams.c_str())){
			return new JDFNodeInfoCmdParams(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_NodeInfoQuParams.c_str())){
			return new JDFNodeInfoQuParams(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_NumberingParams.c_str())){
			return new JDFNumberingParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsO(const JDFCh* pcResName, const WString &typ, const JDFElement &part){		

		if(!wcscmp(pcResName,JDFElement::elm_OrderingParams.c_str())){
			return new JDFOrderingParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsP(const JDFCh* pcResName, const WString &typ, const JDFElement &part){		

		if(!wcscmp(pcResName,JDFElement::elm_PackingParams.c_str())){
			return new JDFPackingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_PageAssignParams.c_str())){
			return new JDFPageAssignParams(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PalletizingParams.c_str())){
			return new JDFPalletizingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_PDFInterpretingParams.c_str())){
			return new JDFPDFInterpretingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_PDFToPSConversionParams.c_str())){
			return new JDFPDFToPSConversionParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_PDFXParams.c_str())){
			return new JDFPDFXParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_PerforatingParams.c_str())){
			return new JDFPerforatingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_PipeParams.c_str())){
			return new JDFPipeParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_PlasticCombBindingParams.c_str())){
			return new JDFPlasticCombBindingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_PlateCopyParams.c_str())){
			return new JDFPlateCopyParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_PreviewGenerationParams.c_str())){
			return new JDFPreviewGenerationParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_PrintRollingParams.c_str())){
			return new JDFPrintRollingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ProofingParams.c_str())){
			return new JDFProofingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_PSToPDFConversionParams.c_str())){
			return new JDFPSToPDFConversionParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsQ(const JDFCh* pcResName, const WString &typ, const JDFElement &part){		

		if(!wcscmp(pcResName,JDFElement::elm_QualityControlParams.c_str())){
			return new JDFQualityControlParams(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_QueueEntryPosParams.c_str())){
			return new JDFQueueEntryPosParams(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_QueueEntryPriParams.c_str())){
			return new JDFQueueEntryPriParams(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_QueueSubmissionParams.c_str())){
			return new JDFQueueSubmissionParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsR(const JDFCh* pcResName, const WString &typ, const JDFElement &part){		

		if(!wcscmp(pcResName,JDFElement::elm_ReferenceXObjParams.c_str())){
			return new JDFReferenceXObjParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_RequestQueueEntryParams.c_str())){
			return new JDFRequestQueueEntryParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_RenderingParams.c_str())){
			return new JDFRenderingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ResourceCmdParams.c_str())){
			return new JDFResourceCmdParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ResourceQuParams.c_str())){
			return new JDFResourceQuParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ResourceDefinitionParams.c_str())){
			return new JDFResourceDefinitionParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ResourcePullParams.c_str())){
			return new JDFResourcePullParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ResubmissionParams.c_str())){
			return new JDFResubmissionParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ReturnQueueEntryParams.c_str())){
			return new JDFReturnQueueEntryParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_RingBindingParams.c_str())){
			return new JDFRingBindingParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsS(const JDFCh* pcResName, const WString &typ, const JDFElement &part){		

		if(!wcscmp(pcResName,JDFElement::elm_SaddleStitchingParams.c_str())){
			return new JDFSaddleStitchingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ScanParams.c_str())){
			return new JDFScanParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ScreeningParams.c_str())){
			return new JDFScreeningParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_SeparationControlParams.c_str())){
			return new JDFSeparationControlParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ShapeCuttingParams.c_str())){
			return new JDFShapeCuttingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ShapeDefProductionParams.c_str())){
			return new JDFShapeDefProductionParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ShrinkingParams.c_str())){
			return new JDFShrinkingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ShutDownCmdParams.c_str())){
			return new JDFShutDownCmdParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_SideSewingParams.c_str())){
			return new JDFSideSewingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_SpinePreparationParams.c_str())){
			return new JDFSpinePreparationParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_SpineTapingParams.c_str())){
			return new JDFSpineTapingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_StackingParams.c_str())){
			return new JDFStackingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_StopPersChParams.c_str())){
			return new JDFStopPersChParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_StatusQuParams.c_str())){
			return new JDFStatusQuParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_StrappingParams.c_str())){
			return new JDFStrappingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_StitchingParams.c_str())){
			return new JDFStitchingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_StripBindingParams.c_str())){
			return new JDFStripBindingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_StripCellParams.c_str())){
			return new JDFStripCellParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_StrippingParams.c_str())){
			return new JDFStrippingParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsT(const JDFCh* pcResName, const WString &typ, const JDFElement &part){		

		if(!wcscmp(pcResName,JDFElement::elm_TIFFFormatParams.c_str())){
			return new JDFTIFFFormatParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ThinPDFParams.c_str())){
			return new JDFThinPDFParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ThreadSealingParams.c_str())){
			return new JDFThreadSealingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ThreadSewingParams.c_str())){
			return new JDFThreadSewingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_TrappingParams.c_str())){
			return new JDFTrappingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_TrimmingParams.c_str())){
			return new JDFTrimmingParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsV(const JDFCh* pcResName, const WString &typ, const JDFElement &part){		

		// deprecated velobinding was renamed to StripBinding
		if(!wcscmp(pcResName,JDFElement::elm_VeloBindingParams.c_str())){
			return new JDFStripBindingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_VarnishingParams.c_str())){
			return new JDFVarnishingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_VerificationParams.c_str())){
			return new JDFVerificationParams(part);
		};
		return 0;
	}


	JDFElement* JDFFactory::initParamsW(const JDFCh* pcResName, const WString &typ, const JDFElement &part){		

		if(!wcscmp(pcResName,JDFElement::elm_WakeUpCmdParams.c_str())){
			return new JDFWakeUpCmdParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_WireCombBindingParams.c_str())){
			return new JDFWireCombBindingParams(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_WrappingParams.c_str())){
			return new JDFWrappingParams(part);
		};
		return 0;
	}			
}