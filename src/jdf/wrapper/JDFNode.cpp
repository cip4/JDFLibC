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

//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
// 040900 RP renamed JDFProcess to JDFNode
// 050201 TG spawning partitions: set spawn status of local resources,
//           append selector resource (if necessary)
// 070201 TG Spawn: only setting default status of status pool with
//           node status when node status is not Pool
// 083101 MM implemented: GetInheritedElement | GetInheritedNodeInfo | GetInheritedCustomerInfo
//			 modified GetActivation (now also takes into account the activations state of the anchestors)
// 050603 TG MergeJDF: uses GetTarget instead of GetTargetResource to find resources in overwriteNode,
//           and to find local nodes in toMergeNode
// 140504 RP removed UniqueTypeString
// 270906 NB fixed TypeLinkInfo()/TypeLinkName() [21x]
//
// JDFNode.cpp: implementation of the JDFNode class.
//
//////////////////////////////////////////////////////////////////////
#include <algorithm>

#include "JDFNode.h"
#include "JDFComment.h"
#include "JDFAncestor.h"
#include "JDFNodeInfo.h"
#include "JDFRefElement.h"
#include "JDFResourcePool.h"
#include "JDFResourceLink.h"
#include "JDFResourceLinkPool.h"
#include "JDFDoc.h"
#include "JDFCustomerInfo.h"
#include "JDFAuditPool.h"
#include "JDFAncestorPool.h"
#include "JDFModified.h"
#include "JDFComponent.h"
#include "JDFSpawned.h"
#include "JDFStatusPool.h"
#include "JDFPartStatus.h"
#include "JDFFactory.h"
#include "JDFApprovalSuccess.h"
#include "JDFDevice.h"
#include "JDFEmployee.h"
#include "JDFPreview.h"
#include "JDFTool.h"
#include "JDFPartAmount.h"
#include "JDFAmountPool.h"
#include "JDFBusinessInfo.h"
#include "JDFMISDetails.h"
#include "JDFNotificationFilter.h"
#include "JDFCompany.h"
#include "JDFCustomerMessage.h"
#include "JDFJMF.h"
#include "JDFContact.h"
#include "JDFSignal.h"
#include "JDFJobPhase.h"
#include "JDFSpawn.h"
#include "JDFMerge.h"
#include "jdf/wrappercore/XMLDocUserData.h"

using namespace std;
namespace JDF{

	const JDFNode JDFNode::DefJDFNode=JDFNode();
	static const WString sProduct=L"Product";
	const static WString sInternal=L"Internal";

	//////////////////////////////////////////////////////////////////////
	// Construction/Destruction
	//////////////////////////////////////////////////////////////////////
	const WString& JDFNode::TypeString(){
		static const WString s=WString(L"Type_Unknown,Product,ProcessGroup,Combined,Approval,Buffer,Combine,Delivery,ManualLabor,Ordering")
			+WString(L",Packing,QualityControl,ResourceDefinition,Split,Verification,AssetListCreation,Bending,ColorCorrection,ColorSpaceConversion,ContactCopying")
			+WString(L",ContoneCalibration,CylinderLayoutPreparation,DBDocTemplateLayout,DBTemplateMerging,DigitalDelivery,FilmToPlateCopying,FormatConversion,ImageReplacement,ImageSetting,Imposition")
			+WString(L",InkZoneCalculation,Interpreting,LayoutElementProduction,LayoutPreparation,PDFToPSConversion,PDLCreation,Preflight,PreviewGeneration,Proofing,PSToPDFConversion")
			+WString(L",RasterReading,Rendering,Scanning,Screening,Separation,SoftProofing,Stripping,Tiling,Trapping,ConventionalPrinting")
			+WString(L",DigitalPrinting,IDPrinting,AdhesiveBinding,BlockPreparation,BoxFolding,BoxPacking,Bundling,CaseMaking,CasingIn,ChannelBinding")
			+WString(L",CoilBinding,Collecting,CoverApplication,Creasing,Cutting,Dividing,Embossing,EndSheetGluing,Feeding,Folding")
			+WString(L",Gathering,Gluing,HeadBandApplication,HoleMaking,Inserting,Jacketing,Labeling,Laminating,LongitudinalRibbonOperations,Numbering")
			+WString(L",Palletizing,Perforating,PlasticCombBinding,PrintRolling,RingBinding,SaddleStitching,ShapeCutting,Shrinking,SideSewing,SpinePreparation")
			+WString(L",SpineTaping,Stacking,Stitching,Strapping,StripBinding,ThreadSealing,ThreadSewing,Trimming,WebInlineFinishing,WireCombBinding")
			+WString(L",Wrapping");
		return s;
	}

	//////////////////////////////////////////////////////////////////////
	WString JDFNode::TypeString(EnumType typ){
		return TypeString().Token((int)typ,WString::comma);
	}
	//////////////////////////////////////////////////////////////////////

	// length of GenericLinkNames() and GenericLinkInfo()
	int JDFNode::genericLinksLength=10;		

	//////////////////////////////////////////////////////////////////////
	const vWString& JDFNode::TypeVector(){
		static const vWString v=TypeString().Tokenize(WString::comma); 
		return v;
	}

	//////////////////////////////////////////////////////////////////////

	const WString& JDFNode::ProcessUsageString(){
		static const WString ProcessUsageString=L"Unknown,AnyInput,AnyOutput,Any,Jacket,Parent,Cover,Rejected,Accepted,Marks,Document,Surface,Waste,Proof,Input,Plate,Good,BookBlock,Box,CoverMaterial,SpineBoard,CoverBoard,Case,FrontEndSheet,BackEndSheet,Child,Mother,Book,Label,RingBinder";
		return ProcessUsageString;
	}

	/////////////////////////////////////////////////////////////////////////
	const WString JDFNode::ProcessUsageString(EnumProcessUsage processUsage){
		return ProcessUsageString().Token(processUsage,WString::comma);
	}

	/////////////////////////////////////////////////////////////////////////

	JDFNode::EnumProcessUsage JDFNode::EnumProcessUsageFromString(const WString& pu){
		int n;
		if(pu.empty()){
			n=0;
		}else{
			n=ProcessUsageString().PosOfToken(pu,WString::comma);
			if(n<0)
				n=0;
		}
		return (EnumProcessUsage) n;
	}

	/////////////////////////////////////////////////////////////////////////

	const WString& JDFNode::GenericLinkInfo()const{
		static const WString s=L"i*,i*,i*,i*,i*,i*,i*,i*,i*,i*";
		return s;
	};
	//////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	const WString& JDFNode::GenericLinkNames()const{
		static const WString s=L"ApprovalSuccess,Device,Employee,Tool,PreflightReport,CustomerInfo,NodeInfo,Preview,MiscConsumable,UsageCounter";
		return s;
	}
	//////////////////////////////////////////////////////////////////////

	JDFNode::EnumType JDFNode::GetEnumType()const{
		return EnumTypeFromString(GetType());
	}

	//////////////////////////////////////////////////////////////////////
	void JDFNode::SetEnumType(JDFNode::EnumType typ){
		int it=(int)typ;
		WString s=TypeString().Token(it,WString::comma);
		if(s.empty())
			throw JDFException(L"JDFNode::SetEnumType invalid enum: "+WString(it));

		SetType(s);
	}

	//////////////////////////////////////////////////////////////////////

	vWString JDFNode::getEnumTypes()
	{
		vWString types=GetTypes();
		if(types.empty())
			return vWString::emptyvStr;
		vWString vs;
		bool bFirst=true;
		for(int i=0;i<(int)types.size();i++)
		{
			JDFNode::EnumType typ=JDFNode::EnumTypeFromString(types.stringAt(i));
			if(typ==JDFNode::Type_Unknown)
				return vWString::emptyvStr;
			if(bFirst)
			{
				bFirst=false;
				vs.clear();
			}
			vs.add(typ);
		}
		return vs;
	}

	//////////////////////////////////////////////////////////////////////

	JDFNode::EnumType JDFNode::EnumTypeFromString(const WString& typ){
		int n;
		if(typ.empty()){
			n=0;
		}else{
			n=TypeString().PosOfToken(typ,WString::comma);
			if(n<0)
				n=0;
		}
		return (EnumType) n;
	}

	//////////////////////////////////////////////////////////////////////


	/////////////////////////////////////////////////////////////////////////

	WString JDFNode::LinkNames()const{
		EnumType typ=GetEnumType();
		if(typ==Type_Combined || (typ==Type_ProcessGroup && HasAttribute(atr_Types))){
			vWString v=GenericLinkNames();
			vWString vTypes;
			int startPos=0; // Types contains some entries at the beginning that must be skipped
			vTypes=GetTypes();
			for(int i=startPos;i<vTypes.size();i++){
				EnumType t=EnumTypeFromString(vTypes[i]);
				vWString newNames=TypeLinkNames(t).Tokenize(WString::comma);
				for(int j=genericLinksLength;j<newNames.size();j++){
					v.push_back(newNames[j]);
				}
			}
			return v.GetString(WString::comma);
		}else if(typ!=Type_Unknown){
			return TypeLinkNames(typ);
		}
		return WString::emptyStr;
	}

	//////////////////////////////////////////////////////////////////////

	WString JDFNode::LinkInfo()const{
		EnumType typ=GetEnumType();		
		if(typ==Type_Combined || (typ==Type_ProcessGroup && HasAttribute(atr_Types))){
			vWString v=GenericLinkInfo().Tokenize(WString::comma);
			vWString vNames=GenericLinkNames().Tokenize(WString::comma);
			vWString vTypes;
			vTypes=GetTypes();
			int i;
			for(i=0;i<vTypes.size();i++){
				EnumType t=EnumTypeFromString(vTypes[i]);
				vWString newLinks=TypeLinkInfo(t).Tokenize(WString::comma);
				vWString newNames=TypeLinkNames(t).Tokenize(WString::comma);
				for(int j=genericLinksLength;j<newLinks.size();j++){
					v.push_back(newLinks[j]);
					vNames.push_back(newNames[j]);
				}
			}

			// make the intermediate links optional
			int s=v.size();
			// loop over all links
			for(i=0;i<s;i++){
				vWString typeList=v[i].Tokenize();
				for(int iTyp=0;iTyp<typeList.size();iTyp++){
					WString typString=typeList[iTyp];
					if(typString[0]==L'o'){
						WString linkName=vNames[i];
						// loop over all links behind this one in types
						for(int j=i+1;j<s;j++){
							if(vNames[j]==linkName){ // if the names match, they should fit 
								bool bGotOne=false;
								vWString typeList2=v[j].Tokenize();
								for(int iTyp2=0;iTyp2<typeList2.size();iTyp2++){
									WString typ2=typeList2[iTyp2];
									if(typ2[0]==L'i'){
										bGotOne=true;
										// make them optional
										if(typ2[1]==L'_'){
											typ2[1]=L'?';
										}else if(typ2[1]==L'+'){
											typ2[1]=L'*';
										}
										typeList2[iTyp2]=typ2;
									}
								}
								if(bGotOne){
									// replace input link entry
									v[j]=typeList2.GetString();
									if(typString[1]==L'_'){
										typString[1]=L'?';
									}else if(typString[1]==L'+'){
										typString[1]=L'*';
									}
									typeList[iTyp]=typString;
								}
							}
						}
					}
				}
				v[i]=typeList.GetString();
			}
			return v.GetString(WString::comma);
		}else if(typ!=Type_Unknown){		
			return TypeLinkInfo(typ);
		}else{			
			return WString::emptyStr;
		}
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::TypeLinkNames(JDFNode::EnumType typeNum)const{
		switch(typeNum)
		{
		case Type_Product:{
			return GenericLinkNames()+L",Component,ArtDeliveryIntent,BindingIntent,ColorIntent,DeliveryIntent,EmbossingIntent,FoldingIntent,HoleMakingIntent,InsertingIntent,LaminatingIntent,LayoutIntent,MediaIntent,NumberingIntent,PackingIntent,ProductionIntent,ProofingIntent,ScreeningIntent,ShapeCuttingIntent,SizeIntent,ApprovalSuccess,Device,Employee,Preview,PreflightReport";
			break;
						  };
		case Type_ProcessGroup:{
			return GenericLinkNames()+L",";
			break;
							   };
		case Type_Combined:{
			return GenericLinkNames()+L",";
			break;
						   };
		case Type_Approval:{
			return GenericLinkNames()+L",*,ApprovalSuccess,ApprovalParams";
			break;
						   };
		case Type_Buffer:{
			return GenericLinkNames()+L",*,BufferParams";
			break;
						 };
		case Type_Combine:{
			return GenericLinkNames()+L",*";
			break;
						  };
		case Type_Delivery:{
			return GenericLinkNames()+L",*,DeliveryParams";
			break;
						   };
		case Type_ManualLabor:{
			return GenericLinkNames()+L",*,ManualLaborParams";
			break;
							  };
		case Type_Ordering:{
			return GenericLinkNames()+L",*,OrderingParams";
			break;
						   };
		case Type_Packing:{
			return GenericLinkNames()+L",*,PackingParams";
			break;
						  };
		case Type_QualityControl:{
			return GenericLinkNames()+L",*,QualityControlResult,QualityControlParams";
			break;
								 };
		case Type_ResourceDefinition:{
			return GenericLinkNames()+L",*,ResourceDefinitionParams";
			break;
									 };
		case Type_Split:{
			return GenericLinkNames()+L",*";
			break;
						};
		case Type_Verification:{
			return GenericLinkNames()+L",*,DBSelection,ApprovalSuccess,VerificationParams,IdentificationField,DBSchema";
			break;
							   };
		case Type_AssetListCreation:{
			return GenericLinkNames()+L",AssetListCreationParams,RunList";
			break;
									};
		case Type_Bending:{
			return GenericLinkNames()+L",BendingParams,ExposedMedia,Media";
			break;
						  };
		case Type_ColorCorrection:{
			return GenericLinkNames()+L",ColorantControl,ColorCorrectionParams,RunList";
			break;
								  };
		case Type_ColorSpaceConversion:{
			return GenericLinkNames()+L",ColorantControl,ColorSpaceConversionParams,RunList";
			break;
									   };
		case Type_ContactCopying:{
			return GenericLinkNames()+L",ContactCopyParams,DevelopingParams,ExposedMedia,Media,TransferCurvePool";
			break;
								 };
		case Type_ContoneCalibration:{
			return GenericLinkNames()+L",RunList,ScreeningParams,TransferFunctionControl";
			break;
									 };
		case Type_CylinderLayoutPreparation:{
			return GenericLinkNames()+L",CylinderLayoutPreparationParams,Layout,RunList,CylinderLayout";
			break;
											};
		case Type_DBDocTemplateLayout:{
			return GenericLinkNames()+L",DBRules,DBSchema,LayoutElement";
			break;
									  };
		case Type_DBTemplateMerging:{
			return GenericLinkNames()+L",DBMergeParams,DBSelection,LayoutElement,RunList";
			break;
									};
		case Type_DigitalDelivery:{
			return GenericLinkNames()+L",DigitalDeliveryParams,RunList";
			break;
								  };
		case Type_FilmToPlateCopying:{
			return GenericLinkNames()+L",DevelopingParams,ExposedMedia,Media,PlateCopyParams";
			break;
									 };
		case Type_FormatConversion:{
			return GenericLinkNames()+L",FormatConversionParams,RunList";
			break;
								   };
		case Type_ImageReplacement:{
			return GenericLinkNames()+L",ImageCompressionParams,ImageReplacementParams,RunList";
			break;
								   };
		case Type_ImageSetting:{
			return GenericLinkNames()+L",ColorantControl,DevelopingParams,ExposedMedia,ImageSetterParams,Media,RunList,TransferCurvePool";
			break;
							   };
		case Type_Imposition:{
			return GenericLinkNames()+L",Layout,RunList";
			break;
							 };
		case Type_InkZoneCalculation:{
			return GenericLinkNames()+L",InkZoneCalculationParams,InkZoneProfile,Layout,TransferCurvePool,Sheet,Preview";
			break;
									 };
		case Type_Interpreting:{
			return GenericLinkNames()+L",ColorantControl,FontPolicy,InterpretedPDLData,InterpretingParams,PDLResourceAlias,RunList";
			break;
							   };
		case Type_LayoutElementProduction:{
			return GenericLinkNames()+L",LayoutElement,LayoutElementProductionParams,RunList";
			break;
										  };
		case Type_LayoutPreparation:{
			return GenericLinkNames()+L",LayoutPreparationParams,RunList,Layout,TransferCurvePool";
			break;
									};
		case Type_PDFToPSConversion:{
			return GenericLinkNames()+L",PDFToPSConversionParams,RunList";
			break;
									};
		case Type_PDLCreation:{
			return GenericLinkNames()+L",ImageCompressionParams,PDLCreationParams,RunList";
			break;
							  };
		case Type_Preflight:{
			return GenericLinkNames()+L",PreflightParams,PreflightReportRulePool,RunList,PreflightReport";
			break;
							};
		case Type_PreviewGeneration:{
			return GenericLinkNames()+L",ColorantControl,ExposedMedia,PreviewGenerationParams,RunList,TransferCurvePool,Preview";
			break;
									};
		case Type_Proofing:{
			return GenericLinkNames()+L",ColorantControl,ColorSpaceConversionParams,ExposedMedia,Layout,Media,ProofingParams,RunList";
			break;
						   };
		case Type_PSToPDFConversion:{
			return GenericLinkNames()+L",FontParams,ImageCompressionParams,PSToPDFConversionParams,RunList";
			break;
									};
		case Type_RasterReading:{
			return GenericLinkNames()+L",RasterReadingParams,RunList";
			break;
								};
		case Type_Rendering:{
			return GenericLinkNames()+L",InterpretedPDLData,Media,RenderingParams,RunList";
			break;
							};
		case Type_Scanning:{
			return GenericLinkNames()+L",ExposedMedia,ScanParams,RunList";
			break;
						   };
		case Type_Screening:{
			return GenericLinkNames()+L",RunList,ScreeningParams";
			break;
							};
		case Type_Separation:{
			return GenericLinkNames()+L",ColorantControl,RunList,SeparationControlParams";
			break;
							 };
		case Type_SoftProofing:{
			return GenericLinkNames()+L",ColorantControl,ColorSpaceConversionParams,Layout,ProofingParams,RunList";
			break;
							   };
		case Type_Stripping:{
			return GenericLinkNames()+L",Assembly,ColorantControl,RunList,StrippingParams,TransferCurvePool,Layout";
			break;
							};
		case Type_Tiling:{
			return GenericLinkNames()+L",RunList,Tile";
			break;
						 };
		case Type_Trapping:{
			return GenericLinkNames()+L",ColorantControl,RunList,TrappingDetails,FontPolicy";
			break;
						   };
		case Type_ConventionalPrinting:{
			return GenericLinkNames()+L",ColorantControl,Component,ConventionalPrintingParams,ExposedMedia,Ink,InkZoneProfile,Layout,Media,PrintCondition,Sheet,TransferCurvePool";
			break;
									   };
		case Type_DigitalPrinting:{
			return GenericLinkNames()+L",ColorantControl,Component,DigitalPrintingParams,ExposedMedia,Ink,PrintCondition,Media,RunList,Layout,Sheet,TransferCurvePool";
			break;
								  };
		case Type_IDPrinting:{
			return GenericLinkNames()+L",ColorantControl,Component,ExposedMedia,FontPolicy,Ink,InterpretingParams,IDPrintingParams,Media,RenderingParams,RunList,ScreeningParams,TransferFunctionControl";
			break;
							 };
		case Type_AdhesiveBinding:{
			return GenericLinkNames()+L",AdhesiveBindingParams,Component";
			break;
								  };
		case Type_BlockPreparation:{
			return GenericLinkNames()+L",Component,BlockPreparationParams";
			break;
								   };
		case Type_BoxFolding:{
			return GenericLinkNames()+L",Component,BoxFoldingParams";
			break;
							 };
		case Type_BoxPacking:{
			return GenericLinkNames()+L",BoxPackingParams,Component,Media";
			break;
							 };
		case Type_Bundling:{
			return GenericLinkNames()+L",Component,BundlingParams,Media";
			break;
						   };
		case Type_CaseMaking:{
			return GenericLinkNames()+L",Component,CaseMakingParams,Media";
			break;
							 };
		case Type_CasingIn:{
			return GenericLinkNames()+L",Component,CasingInParams";
			break;
						   };
		case Type_ChannelBinding:{
			return GenericLinkNames()+L",ChannelBindingParams,Component";
			break;
								 };
		case Type_CoilBinding:{
			return GenericLinkNames()+L",CoilBindingParams,Component";
			break;
							  };
		case Type_Collecting:{
			return GenericLinkNames()+L",Assembly,CollectingParams,Component,DBRules,DBSelection,IdentificationField";
			break;
							 };
		case Type_CoverApplication:{
			return GenericLinkNames()+L",Component,CoverApplicationParams";
			break;
								   };
		case Type_Creasing:{
			return GenericLinkNames()+L",CreasingParams,Component";
			break;
						   };
		case Type_Cutting:{
			return GenericLinkNames()+L",Component,CutBlock,CutMark,CuttingParams,Media";
			break;
						  };
		case Type_Dividing:{
			return GenericLinkNames()+L",Component,DividingParams";
			break;
						   };
		case Type_Embossing:{
			return GenericLinkNames()+L",Component,EmbossingParams,Media";
			break;
							};
		case Type_EndSheetGluing:{
			return GenericLinkNames()+L",Component,EndSheetGluingParams";
			break;
								 };
		case Type_Feeding:{
			return GenericLinkNames()+L",Component,FeedingParams,Media";
			break;
						  };
		case Type_Folding:{
			return GenericLinkNames()+L",Component,FoldingParams";
			break;
						  };
		case Type_Gathering:{
			return GenericLinkNames()+L",Assembly,Component,DBRules,DBSelection,GatheringParams,IdentificationField";
			break;
							};
		case Type_Gluing:{
			return GenericLinkNames()+L",Component,GluingParams";
			break;
						 };
		case Type_HeadBandApplication:{
			return GenericLinkNames()+L",Component,HeadBandApplicationParams";
			break;
									  };
		case Type_HoleMaking:{
			return GenericLinkNames()+L",Component,HoleMakingParams";
			break;
							 };
		case Type_Inserting:{
			return GenericLinkNames()+L",Component,DBRules,DBSelection,IdentificationField,InsertingParams";
			break;
							};
		case Type_Jacketing:{
			return GenericLinkNames()+L",Component,JacketingParams";
			break;
							};
		case Type_Labeling:{
			return GenericLinkNames()+L",Component,LabelingParams";
			break;
						   };
		case Type_Laminating:{
			return GenericLinkNames()+L",Component,LaminatingParams,Media";
			break;
							 };
		case Type_LongitudinalRibbonOperations:{
			return GenericLinkNames()+L",Component,LongitudinalRibbonOperationParams";
			break;
											   };
		case Type_Numbering:{
			return GenericLinkNames()+L",Component,NumberingParams";
			break;
							};
		case Type_Palletizing:{
			return GenericLinkNames()+L",Component,PalletizingParams,Pallet";
			break;
							  };
		case Type_Perforating:{
			return GenericLinkNames()+L",PerforatingParams,Component";
			break;
							  };
		case Type_PlasticCombBinding:{
			return GenericLinkNames()+L",Component,PlasticCombBindingParams";
			break;
									 };
		case Type_PrintRolling:{
			return GenericLinkNames()+L",Component,PrintRollingParams,RollStand";
			break;
							   };
		case Type_RingBinding:{
			return GenericLinkNames()+L",Component,RingBindingParams";
			break;
							  };
		case Type_SaddleStitching:{
			return GenericLinkNames()+L",Component,SaddleStitchingParams";
			break;
								  };
		case Type_ShapeCutting:{
			return GenericLinkNames()+L",Component,ShapeCuttingParams,Tool";
			break;
							   };
		case Type_Shrinking:{
			return GenericLinkNames()+L",Component,ShrinkingParams";
			break;
							};
		case Type_SideSewing:{
			return GenericLinkNames()+L",Component,SideSewingParams";
			break;
							 };
		case Type_SpinePreparation:{
			return GenericLinkNames()+L",Component,SpinePreparationParams";
			break;
								   };
		case Type_SpineTaping:{
			return GenericLinkNames()+L",Component,SpineTapingParams";
			break;
							  };
		case Type_Stacking:{
			return GenericLinkNames()+L",Component,StackingParams";
			break;
						   };
		case Type_Stitching:{
			return GenericLinkNames()+L",Component,StitchingParams";
			break;
							};
		case Type_Strapping:{
			return GenericLinkNames()+L",Component,StrappingParams,Strap";
			break;
							};
		case Type_StripBinding:{
			return GenericLinkNames()+L",Component,StripBindingParams";
			break;
							   };
		case Type_ThreadSealing:{
			return GenericLinkNames()+L",Component,ThreadSealingParams";
			break;
								};
		case Type_ThreadSewing:{
			return GenericLinkNames()+L",Component,ThreadSewingParams";
			break;
							   };
		case Type_Trimming:{
			return GenericLinkNames()+L",Component,TrimmingParams";
			break;
						   };
		case Type_WebInlineFinishing:{
			return GenericLinkNames()+L",Assembly,Component,ProductionPath,StrippingParams,WebInlineFinishingParams";
			break;
									 };
		case Type_WireCombBinding:{
			return GenericLinkNames()+L",Component,WireCombBindingParams";
			break;
								  };
		case Type_Wrapping:{
			return GenericLinkNames()+L",Component,WrappingParams,Media";
			break;
						   };
		}
		return GenericLinkNames();
	}


	//////////////////////////////////////////////////////////////////////

	WString JDFNode::TypeLinkInfo(EnumType typeNum)const{
		switch(typeNum)
		{
		case Type_Product:{
			return GenericLinkInfo()+L",o+ i?Jacket i?Parent i*Cover i*EndSheet i*,i?,i?,i?,i?,i?,i?,i?,i?,i?,i?,i?,i?,i?,i?,i?,i? o?,i?,i? o?,i*,i*,i*,i*,i*";
			break;
						  };
		case Type_ProcessGroup:{
			return GenericLinkInfo()+L",";
			break;
							   };
		case Type_Combined:{
			return GenericLinkInfo()+L",i? o?";
			break;
						   };
		case Type_Approval:{
			return GenericLinkInfo()+L",o*Rejected o*Accepted i*,o_,i_";
			break;
						   };
		case Type_Buffer:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
						 };
		case Type_Combine:{
			return GenericLinkInfo()+L",o_ i+";
			break;
						  };
		case Type_Delivery:{
			return GenericLinkInfo()+L",o+ i?,i_";
			break;
						   };
		case Type_ManualLabor:{
			return GenericLinkInfo()+L",o? i*,i_";
			break;
							  };
		case Type_Ordering:{
			return GenericLinkInfo()+L",o+,i_";
			break;
						   };
		case Type_Packing:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
						  };
		case Type_QualityControl:{
			return GenericLinkInfo()+L",o_ i_,o_,i_";
			break;
								 };
		case Type_ResourceDefinition:{
			return GenericLinkInfo()+L",o+ i*,i?";
			break;
									 };
		case Type_Split:{
			return GenericLinkInfo()+L",o+ i_";
			break;
						};
		case Type_Verification:{
			return GenericLinkInfo()+L",o? i?,o? i?,o?,i_,i*,i?";
			break;
							   };
		case Type_AssetListCreation:{
			return GenericLinkInfo()+L",i_,i_ o_";
			break;
									};
		case Type_Bending:{
			return GenericLinkInfo()+L",i_,i? o_,i?";
			break;
						  };
		case Type_ColorCorrection:{
			return GenericLinkInfo()+L",i?,i_,o_ i_";
			break;
								  };
		case Type_ColorSpaceConversion:{
			return GenericLinkInfo()+L",o? i?,i_,o_ i_";
			break;
									   };
		case Type_ContactCopying:{
			return GenericLinkInfo()+L",i_,i?,o_ i+,i_,i?";
			break;
								 };
		case Type_ContoneCalibration:{
			return GenericLinkInfo()+L",o_ i_,i?,i?";
			break;
									 };
		case Type_CylinderLayoutPreparation:{
			return GenericLinkInfo()+L",i?,i_,i_,o?";
			break;
											};
		case Type_DBDocTemplateLayout:{
			return GenericLinkInfo()+L",i_,i_,o* i*";
			break;
									  };
		case Type_DBTemplateMerging:{
			return GenericLinkInfo()+L",i_,i_,i*,o_";
			break;
									};
		case Type_DigitalDelivery:{
			return GenericLinkInfo()+L",i_,o+ i*";
			break;
								  };
		case Type_FilmToPlateCopying:{
			return GenericLinkInfo()+L",i?,o_ i_,i_,i_";
			break;
									 };
		case Type_FormatConversion:{
			return GenericLinkInfo()+L",i_,o_ i_";
			break;
								   };
		case Type_ImageReplacement:{
			return GenericLinkInfo()+L",i?,i_,o_ i_";
			break;
								   };
		case Type_ImageSetting:{
			return GenericLinkInfo()+L",i?,i?,o_ i?,i?,i_,i_,i?";
			break;
							   };
		case Type_Imposition:{
			return GenericLinkInfo()+L",i_,o_ i?Marks i_Document";
			break;
							 };
		case Type_InkZoneCalculation:{
			return GenericLinkInfo()+L",i?,o_,i?,i?,i?,i_";
			break;
									 };
		case Type_Interpreting:{
			return GenericLinkInfo()+L",i?,i?,o?,i_,i*,o? i_";
			break;
							   };
		case Type_LayoutElementProduction:{
			return GenericLinkInfo()+L",o? i*,i?,o?";
			break;
										  };
		case Type_LayoutPreparation:{
			return GenericLinkInfo()+L",i_,o?Marks i?Marks i?Document,o_,o?";
			break;
									};
		case Type_PDFToPSConversion:{
			return GenericLinkInfo()+L",i_,o_ i_";
			break;
									};
		case Type_PDLCreation:{
			return GenericLinkInfo()+L",i?,i?,o_ i_";
			break;
							  };
		case Type_Preflight:{
			return GenericLinkInfo()+L",i_,i_,i_,o_";
			break;
							};
		case Type_PreviewGeneration:{
			return GenericLinkInfo()+L",i?,i?,i_,i?,i?,o_";
			break;
									};
		case Type_Proofing:{
			return GenericLinkInfo()+L",i?,i?,o_,i?,i_,i_,i?Marks i_Document";
			break;
						   };
		case Type_PSToPDFConversion:{
			return GenericLinkInfo()+L",i?,i?,i?,o_ i_";
			break;
									};
		case Type_RasterReading:{
			return GenericLinkInfo()+L",i?,o_ i_";
			break;
								};
		case Type_Rendering:{
			return GenericLinkInfo()+L",i?,i?,i?,o_ i?";
			break;
							};
		case Type_Scanning:{
			return GenericLinkInfo()+L",i_,i_,o_";
			break;
						   };
		case Type_Screening:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
							};
		case Type_Separation:{
			return GenericLinkInfo()+L",i?,o_ i_,i_";
			break;
							 };
		case Type_SoftProofing:{
			return GenericLinkInfo()+L",i?,i?,i?,i_,i?Marks i_Document";
			break;
							   };
		case Type_Stripping:{
			return GenericLinkInfo()+L",i+,i?,o?Marks o?Document i?Document,i_,i?,o_";
			break;
							};
		case Type_Tiling:{
			return GenericLinkInfo()+L",o_ i?Marks i_Surface,i_";
			break;
						 };
		case Type_Trapping:{
			return GenericLinkInfo()+L",i?,o_ i_,i_,i?";
			break;
						   };
		case Type_ConventionalPrinting:{
			return GenericLinkInfo()+L",i?,o?Waste o_ i?Proof i?Input,i_,i?Plate i?Proof i?Cylinder,i?,i?,i?,i?,i?,i?,i?";
			break;
									   };
		case Type_DigitalPrinting:{
			return GenericLinkInfo()+L",i?,o?Waste o_ i?Proof i*Input,i_,i?,i?,i?,i*,i_,i?,i?,i?";
			break;
								  };
		case Type_IDPrinting:{
			return GenericLinkInfo()+L",i?,o?Waste o_Good i?Proof i?Input i?Cover,i?,i?,i?,i*,i?,i?,i?,i_,i?,i?";
			break;
							 };
		case Type_AdhesiveBinding:{
			return GenericLinkInfo()+L",i_,o_ i?Cover i_BookBlock";
			break;
								  };
		case Type_BlockPreparation:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
								   };
		case Type_BoxFolding:{
			return GenericLinkInfo()+L",o_ i*Application i_,i_";
			break;
							 };
		case Type_BoxPacking:{
			return GenericLinkInfo()+L",i_,o_ i?Box i_,i?Tie i?UnderLay";
			break;
							 };
		case Type_Bundling:{
			return GenericLinkInfo()+L",o_ i_,i_,i?";
			break;
						   };
		case Type_CaseMaking:{
			return GenericLinkInfo()+L",o_ i?CoverMaterial,i_,i?SpineBoard i_CoverBoard i?CoverMaterial";
			break;
							 };
		case Type_CasingIn:{
			return GenericLinkInfo()+L",o_ i_Case i_,i_";
			break;
						   };
		case Type_ChannelBinding:{
			return GenericLinkInfo()+L",i_,o_ i?Cover i_BookBlock";
			break;
								 };
		case Type_CoilBinding:{
			return GenericLinkInfo()+L",i_,o_ i_";
			break;
							  };
		case Type_Collecting:{
			return GenericLinkInfo()+L",i?,i?,o_ i+,i*,i?,i?";
			break;
							 };
		case Type_CoverApplication:{
			return GenericLinkInfo()+L",o_ i_Cover i_,i_";
			break;
								   };
		case Type_Creasing:{
			return GenericLinkInfo()+L",i_,o_ i_";
			break;
						   };
		case Type_Cutting:{
			return GenericLinkInfo()+L",o* i?,i*,i*,i_,o* i?";
			break;
						  };
		case Type_Dividing:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
						   };
		case Type_Embossing:{
			return GenericLinkInfo()+L",o_ i_,i_,i?";
			break;
							};
		case Type_EndSheetGluing:{
			return GenericLinkInfo()+L",o_ i_FrontEndSheet i_BookBlock i_BackEndSheet,i_";
			break;
								 };
		case Type_Feeding:{
			return GenericLinkInfo()+L",o* i*,i_,o* i*";
			break;
						  };
		case Type_Folding:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
						  };
		case Type_Gathering:{
			return GenericLinkInfo()+L",i?,o_ i+,i*,i?,i_,i?";
			break;
							};
		case Type_Gluing:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
						 };
		case Type_HeadBandApplication:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
									  };
		case Type_HoleMaking:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
							 };
		case Type_Inserting:{
			return GenericLinkInfo()+L",o_ i_Child i_Mother,i?,i?,i?,i_";
			break;
							};
		case Type_Jacketing:{
			return GenericLinkInfo()+L",o_ i_Jacket i_Book,i_";
			break;
							};
		case Type_Labeling:{
			return GenericLinkInfo()+L",o_ i?Label i_,i_";
			break;
						   };
		case Type_Laminating:{
			return GenericLinkInfo()+L",o_ i_,i_,i?";
			break;
							 };
		case Type_LongitudinalRibbonOperations:{
			return GenericLinkInfo()+L",o+ i_,i_";
			break;
											   };
		case Type_Numbering:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
							};
		case Type_Palletizing:{
			return GenericLinkInfo()+L",o_ i_,i_,i_";
			break;
							  };
		case Type_Perforating:{
			return GenericLinkInfo()+L",i_,o_ i_";
			break;
							  };
		case Type_PlasticCombBinding:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
									 };
		case Type_PrintRolling:{
			return GenericLinkInfo()+L",o_ i_,i?,i?";
			break;
							   };
		case Type_RingBinding:{
			return GenericLinkInfo()+L",o_ i?RingBinder i_BookBlock,i_";
			break;
							  };
		case Type_SaddleStitching:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
								  };
		case Type_ShapeCutting:{
			return GenericLinkInfo()+L",o+ i_,i?,i*";
			break;
							   };
		case Type_Shrinking:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
							};
		case Type_SideSewing:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
							 };
		case Type_SpinePreparation:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
								   };
		case Type_SpineTaping:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
							  };
		case Type_Stacking:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
						   };
		case Type_Stitching:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
							};
		case Type_Strapping:{
			return GenericLinkInfo()+L",o_ i_,i_,i?";
			break;
							};
		case Type_StripBinding:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
							   };
		case Type_ThreadSealing:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
								};
		case Type_ThreadSewing:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
							   };
		case Type_Trimming:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
						   };
		case Type_WebInlineFinishing:{
			return GenericLinkInfo()+L",i?,o_ i_,i?,i?,i?";
			break;
									 };
		case Type_WireCombBinding:{
			return GenericLinkInfo()+L",o_ i_,i_";
			break;
								  };
		case Type_Wrapping:{
			return GenericLinkInfo()+L",o_ i_,i_,i?";
			break;
						   };
		}
		return GenericLinkInfo();
	}



	//////////////////////////////////////////////////////////////////////

	JDFNode& JDFNode::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFNode: "+other.GetNodeName()); 
		return *this;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFNode::init(bool flush, const JDFNode& parent){
		if(GetLocalName()!=elm_JDF) 
			return false;

		if(IsJDFRoot()){
			if(flush) {
				Flush();
				UniqueID(GetMinID());
			}

			// update the version
			WString comment(L"Generated by the CIP4 C++ open source JDF Library version "); 
			comment += JDFAudit::Software();
			AppendXMLComment(comment); 

			AddNameSpace(WString::emptyStr,GetSchemaURL(1,1));
			SetEnumVersion(getDefaultJDFVersion());

			JDFAuditPool h=GetCreateAuditPool();
			h.AddCreated();
			WString id=AppendAnchor();
			SetJobPartID(id);
		}else{
			SetJobPartID(GenerateDotID(JDFStrings::atr_JobPartID));
			AppendAnchor();
		}
		SetStatus(JDFNode::Status_Waiting);

		return true;
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::IsAbstract()const{
		return false;
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::IsJDFRoot()const{
		KElement e=GetParentNode();
		if(e.isNull())
			return true;
		return e.GetLocalName()!=elm_JDF;
	}
	//////////////////////////////////////////////////////////////////////

	const WString& JDFNode::ActivationString(){
		static const WString enums=L"Unknown,Inactive,Informative,Held,TestRun,TestRunAndGo,Active"; 
		return enums;
	};

	//////////////////////////////////////////////////////////////////////
	const WString JDFNode::ActivationString(EnumActivation value){
		return ActivationString().Token(value,WString::comma);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	WString JDFNode::ValidNodeNames()const{
		return elm_JDF;
	};



	//////////////////////////////////////////////////////////////////////
	// Add a resource to resroot and link it to this process 

	JDFResource JDFNode::AddResource(const WString & name,JDFResource::EnumClass resClass, bool bInput, JDFNode resRoot, bool bLink, const WString & nameSpaceURI, const JDFResource & toReplace)
	{
		JDFResourceLink::EnumUsage usage=JDFResourceLink::Usage_Unknown;
		if(bLink)
			usage=bInput ? JDFResourceLink::Usage_Input : JDFResourceLink::Usage_Output; 
		return addResource(name,resClass,usage,WString::emptyStr,resRoot,nameSpaceURI, toReplace);
	}

	//////////////////////////////////////////////////////////////////////
	// Add a resource to resroot and link it to this process 

	JDFResource JDFNode::addResource(const WString & name,JDFResource::EnumClass resClass, JDFResourceLink::EnumUsage usage,const WString& procUsage, JDFNode resRoot, const WString & nameSpaceURI, const JDFResource & toReplace){
		if (resRoot.isNull()) 
			resRoot=*this;
		JDFResourcePool p=resRoot.GetCreateResourcePool();
		JDFResource r=p.AppendResource(name,resClass,nameSpaceURI);

		if(usage!=JDFResourceLink::Usage_Unknown) 
			linkResource(r,usage,JDFNode::EnumProcessUsageFromString(procUsage));
		JDFResource::EnumClass resClass2 = r.GetClass();
		if(resClass2!=JDFResource::Class_Unknown)
		{
			resClass=resClass2;
		}
		else
		{
			resClass=JDFResource::Class_Unknown;
		}
		if(resClass!=JDFResource::Class_Unknown)
			r.SetClass(resClass);


		// parameters and consumables are assumed to be available by default
		if (usage == JDFResourceLink::Usage_Input&& resClass!=JDFResource::Class_Unknown
			&& ((resClass==JDFResource::Class_Parameter)
			|| (resClass==JDFResource::Class_Consumable)))
		{
			r.SetStatus(JDFResource::Status_Available,false);
		}
		else
		{
			r.SetStatus(JDFResource::Status_Unavailable,false);
		}
		if(!toReplace.isNull()){
			JDFAuditPool auditPool=GetCreateAuditPool();
			JDFResourceAudit resourceAudit=auditPool.AddResourceAudit(WString::emptyStr);
			resourceAudit.addNewOldLink(true, r, usage);
			resourceAudit.addNewOldLink(false,toReplace,usage);
			VElement vRL=GetResourceLinkPool().getInOutLinks(usage,true,WString::star,WString::star);
			for(int i=0;i<vRL.size();i++){
				JDFResourceLink l=(JDFResourceLink) vRL.elementAt(i);
				if(l.GetTarget()==toReplace){
					l.DeleteNode();
				}
			}           
		}    
		return r;
	}

	//////////////////////////////////////////////////////////////////////////////////////

	/**
	* Is this a Combined node type ?
	* return boolean: true if this is a combined node
	*/
	bool JDFNode::IsCombined()const{
		static const WString s=L"Combined";
		return GetType().compare(s)==0;
	};
	//////////////////////////////////////////////////////////////////////////////////////

	/**
	* Is this a Product node type ?
	* return boolean: true if this is a Product node
	*/
	bool JDFNode::IsProduct()const{
		return GetType().compare(sProduct)==0;
	};
	//////////////////////////////////////////////////////////////////////////////////////

	/**
	* Is this a ProcessGroup node type ?
	* return boolean: true if this is a ProcessGroup node
	*/
	bool JDFNode::IsProcessGroup()const{
		static const WString s=L"ProcessGroup";
		return GetType().compare(s)==0;
	};
	/**
	* Is this a group node type (ProcessGroup or Product)?
	* return boolean: true if this is a combined node
	*/
	bool JDFNode::IsGroupNode()const{
		return IsProcessGroup()||IsProduct();
	};

	//////////////////////////////////////////////////////////////////////

	JDFResourceLink JDFNode::LinkResource(JDFResource r, bool input, bool bForce){
		if(bForce) // fool compiler
			bForce=true;
		return linkResource(r,input ? JDFResourceLink::Usage_Input : JDFResourceLink::Usage_Output,JDFNode::ProcessUsage_Unknown);
	}

	//////////////////////////////////////////////////////////////////////

	JDFResourceLink JDFNode::linkResource(JDFResource jdfResource, JDFResourceLink::EnumUsage usage, EnumProcessUsage processUsage)
	{
		if (jdfResource.isNull())
			return JDFNode::DefJDFNode;

		JDFResourceLinkPool resourceLinkPool = GetCreateResourceLinkPool();
		JDFResourceLink resourceLink = resourceLinkPool.linkResource(jdfResource, usage, processUsage);
		vWString types = GetTypes();
		// generate 
		if(!types.empty()) 
		{
			generateCombinedProcessIndex(jdfResource, usage, processUsage, resourceLink, types);
		}
		return resourceLink;
	}

	//////////////////////////////////////////////////////////////////////

	void JDFNode::generateCombinedProcessIndex(const JDFResource& jdfResource, JDFResourceLink::EnumUsage usage, JDFNode::EnumProcessUsage processUsage, JDFResourceLink resourceLink, const vWString& types)
	{
		JDFIntegerList cpi;
		WString resName=jdfResource.GetLocalName();
		int typSize = types.size();
		int lastGot=-2; // not -1!!!
		vWString typeLinkNamesLast;
		for(int i=0;i<typSize;i++)
		{

			bool bAddCPI=false;
			EnumType t = JDFNode::EnumTypeFromString(types.stringAt(i));
			vWString typeLinkNames = TypeLinkNames(t).Tokenize(WString::comma);
			if(!typeLinkNames.empty() && typeLinkNames.hasString(resName))
			{
				// if we already added a cpi, but this is an exchange resource, only set cpi for the last one
				int iPos = typeLinkNames.index(resName);
				vWString allTypeInfos = TypeLinkInfo(t).Tokenize(WString::comma);
				vWString typeInfo = allTypeInfos[iPos].Tokenize(WString::whiteSpace);
				bool bMatchUsage=false;
				WString inOut=usage==JDFResourceLink::Usage_Input ? "i" : "o";

				for(int ti=0;ti<typeInfo.size();ti++)
				{
					WString sti=typeInfo.stringAt(ti);
					if(inOut.empty() || sti.startsWith(inOut))
					{
						if(processUsage==JDFNode::ProcessUsage_Unknown || JDFNode::ProcessUsageString(processUsage).equals(sti.substring(2)))
						{
							bMatchUsage=true;
							bAddCPI=true;
							break; // one match is enough!
						}
					}
				}
				if(bMatchUsage && lastGot==i-1)
				{
					bAddCPI = cleanCombinedProcessIndex(usage, types, cpi, resName, lastGot, typeLinkNamesLast, bAddCPI, typeInfo);
				}
				if(bAddCPI)
					cpi.add(i);

				lastGot=i;
				typeLinkNamesLast=typeLinkNames;
			}                               
		}
		if(cpi.size()>0)
			resourceLink.SetCombinedProcessIndex(cpi);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFNode::cleanCombinedProcessIndex(JDFResourceLink::EnumUsage usage, const vWString& types, JDFIntegerList& cpi, const WString& resName, int lastGot, const vWString& typeLinkNamesLast, bool bAddCPI, const vWString& typeInfo)
	{    
		// attention: parameter cpi must not be const!
		int iPosLast = typeLinkNamesLast.index(resName);
		// the i* i?pu ... list of this
		// the o* i?pu ... list of the previous type
		JDFNode::EnumType t=JDFNode::EnumTypeFromString(types.stringAt(lastGot));
		vWString allTypeInfosLast = TypeLinkInfo(t).Tokenize(WString::comma);
		vWString typeInfoLast = allTypeInfosLast[iPosLast].Tokenize(WString::whiteSpace);
		bool bOut=false;

		for(int ii=0;ii<typeInfoLast.size();ii++)
		{
			if(typeInfoLast.stringAt(ii).startsWith("o"))
			{
				bOut=true; // we found a matching output
				break;
			}
		}
		if(bOut)
		{
			bool bIn=false;
			bOut=false;
			for(int ii=0;ii<typeInfo.size();ii++)
			{
				if(!bIn && typeInfo.stringAt(ii).startsWith("i"))
				{
					bIn=true; // after finding a matching output in last, we find an input here
				}
				if(!bOut && typeInfo.stringAt(ii).startsWith("o"))
				{
					bOut=true; // after finding a matching output in last, we find an input here
				}
			}
			if(bIn && bOut)
			{ // remove the last output if we found a pass through
				if(usage==JDFResourceLink::Usage_Input)
				{
					bAddCPI=false;
				}
				else
				{					
					cpi.pop_back();
					bAddCPI=true;
				}
			}
			else
			{
				//not continuous - reset
				bAddCPI=true;
			}
		}
		return bAddCPI;
	}

	//////////////////////////////////////////////////////////////////////

	vElement JDFNode::GetPredecessors(bool bPre, bool bRecurse)const{
		return GetPredecessors(bPre,bRecurse,vWString());
	}

	//////////////////////////////////////////////////////////////////////

	vElement JDFNode::GetPredecessors(bool bPre, bool bRecurse, const vWString &vID)const{
		vWString vIDs = vID;
		vElement vNodes;
		JDFResourceLinkPool rp=GetResourceLinkPool();
		// get either all input or output resources, depending on bPre
		vElement vLinkedResources=rp.GetInOutLinks(bPre,false);
		//
		for(int i=0;i<vLinkedResources.size();i++){
			JDFResource r=vLinkedResources[i];
			// get all creator or consumer processes
			vElement vCreators=r.GetCreator(bPre);
			// recurse for these
			for(int j=0;j<vCreators.size();j++){
				JDFNode creator=vCreators[j];
				// skip circular references
				if(vIDs.hasString(creator.GetID()))
					continue;
				vIDs.push_back(WString(creator.GetID()));
				vNodes.push_back(creator);
				// recurse through all linked JDF nodes
				if(bRecurse){
					vElement vRec=creator.GetPredecessors(bPre,bRecurse,vIDs);
					if(!vRec.empty()) 
						vNodes.insert(vNodes.end(),vRec.begin(),vRec.end());
				}
			}
		}
		return vNodes;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFNode::IsExecutable(const mAttribute & partMap, bool bCheckChildren){
		vElement v=GetResourceLinkPool().GetLinks();
		EnumStatus status = this->GetPartStatus(partMap);
		if ((status != Status_Waiting) && (status != Status_Ready))
			return false;

		for(int i=0;i<v.size();i++){
			JDFResourceLink rl=v[i];
			if(!rl.IsExecutable(partMap,bCheckChildren)) 
				return false;
		}
		return true;
	}

	//////////////////////////////////////////////////////////////////////

	JDFNode JDFNode::GetChildJDFNode(const WString& id, bool bDirect)const{
		if(GetID()==id)
			return *this;
		mAttribute m;
		m.AddPair(atr_ID,id);
		return GetTreeElement(elm_JDF,WString::emptyStr,m,bDirect);
	}

	//////////////////////////////////////////////////////////////////////

	JDFNode JDFNode::GetParentJDFNode()const{
		JDFElement n=GetParentNode();
		if(!n.IsJDFNode())
			n=DefJDFNode;
		return n;
	}

	//////////////////////////////////////////////////////////////////////

	vElement JDFNode::GetvJDFNode(const WString & task,EnumActivation active, bool bDirect)const{
		vElement v;
		if(throwNull()) 
			return v;

		bool bActive=active!=Activation_Unknown;
		vElement l=GetTree(elm_JDF,WString::emptyStr,mAttribute::emptyMap,bDirect);
		// only create a complete tree including this in the recursive case
		if(!bDirect)
			l.push_back(*this);

		bool wantTask=!IsWildcard(task.c_str());
		for(int i=0;i<l.size();i++){
			const JDFNode& p=l.at(i);
			if((bActive)&&(!p.FitsActivation(active))){
				continue;
			}
			if(wantTask&&(p.GetType()!=task)) 
				continue;
			v.push_back(p);
		}
		return v;
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::IsActive(bool bWalkThroughAnchestors)const{
		EnumActivation a=GetActivation(bWalkThroughAnchestors);
		return (a==Activation_Active)||(a==Activation_TestRunAndGo);
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFNode::FitsActivation(EnumActivation active,bool bWalkThroughAnchestors)const{
		EnumActivation a=GetActivation(bWalkThroughAnchestors);
		switch(active){
		case Activation_Unknown: 
			return true;
		case Activation_TestRun: 
			return (a==Activation_TestRun)||(a==Activation_TestRunAndGo);
		case Activation_Active: 
			return (a==Activation_Active)||(a==Activation_TestRunAndGo);
		default:
			return a==active;
		}
	}

	//////////////////////////////////////////////////////////////////////



	vElement JDFNode::GetResourceLinks(const mAttribute &mLinkAtt){
		return GetResourceLinkPool().GetLinks(mLinkAtt);
	};

	//////////////////////////////////////////////////////////////////////

	/**
	typesafe validator
	*/
	bool JDFNode::IsValid(EnumValidationLevel level)const{
		if(level<=ValidationLevel_Construct) {
			if(level<=ValidationLevel_None) 
				return true;
			if(isNull()) 
				return true;
		}
		level = IncompleteLevel(level);
		bool bValid=JDFElement::IsValid(level);
		if(!bValid) 
			return false;
		if(level<=ValidationLevel_Construct)
			return true;
		bValid=!HasInvalidLinks(level);
		if(bValid && (Type_Product == GetEnumType()))
		{
			JDFNode n=GetParentJDF();
			if(!n.isNull()){
				bValid=(Type_Product==n.GetEnumType());
			}
		}
		return bValid;
	}


	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	// Getters, Setters, Validators for JDFNode attributes ///////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetActivation( EnumActivation value){
		SetEnumAttribute(atr_Activation,value,ActivationString());
	};

	//////////////////////////////////////////////////////////////////////
	JDFNode::EnumActivation JDFNode::GetActivation(bool bWalkThroughAnchestors)const{

		if (bWalkThroughAnchestors){

			EnumActivation res = Activation_Active;
			JDFNode p = *this;
			while(!p.isNull()){
				// walk through through all anchestors, to parent to grandparent to grandgrandparent 
				// and so on until root and compare the Activation state
				EnumActivation a = (EnumActivation) p.GetEnumAttribute(atr_Activation, ActivationString(), WString::emptyStr, Activation_Active);

				if((a<=Activation_TestRun)||(res<Activation_Active)){
					res = min(a, res); // smaller enums are inherited to all descendants
				}else{ // special case for non-linear test run / test run and go
					if(res==Activation_TestRunAndGo){
						res=a; // either TRG or TR
					}else{
						// nop it remains TestRun
					}
				}

				p = p.GetParentNode();
			}
			return res;
		}
		else{
			return (EnumActivation) GetEnumAttribute(atr_Activation,ActivationString(), WString::emptyStr, Activation_Active);
		}
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidActivation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Activation,ActivationString(),false);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetCategory(const WString& value){
		SetAttribute(atr_Category,value);
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetCategory() const {
		return GetAttribute(atr_Category);
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidCategory(EnumValidationLevel level) const	{
		return ValidAttribute(atr_Category,AttributeType_NMTOKEN,false);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetICSVersions(const vWString& value){
		SetAttribute(atr_ICSVersions,value);
	};
	//////////////////////////////////////////////////////////////////////

	vWString JDFNode::GetICSVersions(bool bInherit) const {
		if(bInherit){
			return GetAncestorAttribute(atr_ICSVersions);
		}else{
			return GetAttribute(atr_ICSVersions);
		}
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidICSVersions(EnumValidationLevel level) const	{
		return ValidAttribute(atr_ICSVersions,AttributeType_NMTOKENS,false);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetID(WString value){
		SetAttribute(atr_ID,value);
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetID() const {
		return GetAttribute(atr_ID);
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ID,AttributeType_ID,RequiredLevel(level));
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetJobID(const WString& value){
		SetAttribute(atr_JobID,value);
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetJobID(bool bInherit) const {
		if(bInherit){
			return GetAncestorAttribute(atr_JobID);
		}else{
			return GetAttribute(atr_JobID);
		}
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_string,false);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetJobPartID(const WString& value){
		SetAttribute(atr_JobPartID,value);
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetJobPartID(bool bInherit) const {
		if(bInherit){
			return GetAncestorAttribute(atr_JobPartID);
		}else{
			return GetAttribute(atr_JobPartID);
		}
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobPartID,AttributeType_string,false);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetMaxVersion(const WString& value){
		SetAttribute(atr_MaxVersion,value);
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetMaxVersion(bool bInherit) const {
		if(bInherit){
			return GetAncestorAttribute(atr_MaxVersion);
		}else{
			return GetAttribute(atr_MaxVersion);
		}
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidMaxVersion(EnumValidationLevel level) const {
		WString version=GetMaxVersion(true);
		if(version.empty())
			return true;
		return VersionString().HasToken(version,WString::comma);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetNamedFeatures(const vWString& value){
		SetAttribute(atr_NamedFeatures,value);
	};
	//////////////////////////////////////////////////////////////////////

	vWString JDFNode::GetNamedFeatures() const {
		return GetAttribute(atr_NamedFeatures);
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidNamedFeatures(EnumValidationLevel level) const {
		return ValidAttribute(atr_NamedFeatures,AttributeType_NMTOKENS,false);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetProjectID(const WString& value){
		SetAttribute(atr_ProjectID,value);
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetProjectID(bool bInherit) const {
		if(bInherit){
			return GetAncestorAttribute(atr_ProjectID);
		}else{
			return GetAttribute(atr_ProjectID);
		}
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidProjectID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProjectID,AttributeType_string,false);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetRelatedJobID(const WString& value){
		SetAttribute(atr_RelatedJobID,value);
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetRelatedJobID(bool bInherit) const {
		if(bInherit){
			return GetAncestorAttribute(atr_RelatedJobID);
		}else{
			return GetAttribute(atr_RelatedJobID);
		}
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidRelatedJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_RelatedJobID,AttributeType_string,false);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetRelatedJobPartID(const WString& value){
		SetAttribute(atr_RelatedJobPartID,value);
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetRelatedJobPartID(bool bInherit) const {
		if(bInherit){
			return GetAncestorAttribute(atr_RelatedJobPartID);
		}else{
			return GetAttribute(atr_RelatedJobPartID);
		}
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidRelatedJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_RelatedJobPartID,AttributeType_string,false);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetSpawnID(const WString& value){
		SetAttribute(atr_SpawnID,value);
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetSpawnID(bool bInherit) const {
		if(bInherit){
			return GetAncestorAttribute(atr_SpawnID);
		}else{
			return GetAttribute(atr_SpawnID);
		}
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFNode::ValidSpawnID(EnumValidationLevel level) const	{
		return ValidAttribute(atr_SpawnID,AttributeType_NMTOKEN,false);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetStatusDetails(const WString& value){
		if(value.empty()){
			RemoveAttribute(atr_StatusDetails);
		}else{
			SetAttribute(atr_StatusDetails,value);
		}
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetStatusDetails() const {
		return GetAttribute(atr_StatusDetails);
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidStatusDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_StatusDetails,AttributeType_string,false);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetTemplate(bool value){
		SetAttribute(atr_Template,value);
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::GetTemplate() const {
		return GetBoolAttribute(atr_Template,WString::emptyStr,false);
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidTemplate(EnumValidationLevel level) const{
		return ValidAttribute(atr_Template,AttributeType_boolean,false);
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetTemplateID(const WString& value){
		SetAttribute(atr_TemplateID,value);
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetTemplateID(bool bInherit) const {
		if(bInherit){
			return GetAncestorAttribute(atr_TemplateID);
		}else{
			return GetAttribute(atr_TemplateID);
		}
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidTemplateID(EnumValidationLevel level) const {
		return ValidAttribute(atr_TemplateID,AttributeType_string,false);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetTemplateVersion(const WString& value){
		SetAttribute(atr_TemplateVersion,value);
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetTemplateVersion(bool bInherit) const {
		if(bInherit){
			return GetAncestorAttribute(atr_TemplateVersion);
		}else{
			return GetAttribute(atr_TemplateVersion);
		}
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidTemplateVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_TemplateVersion,AttributeType_string,false);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetType(const WString & typ){
		RemoveAttribute("type",atr_xsiURI);
		SetAttribute(atr_Type,typ);
		if(EnumTypeFromString(typ)>0){
			SetAttribute(L"xsi:type",typ,atr_xsiURI);
		}
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetType() const {
		return GetAttribute(atr_Type);
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidType(EnumValidationLevel level) const {
		if(!ValidAttribute(atr_Type,AttributeType_NMTOKEN,RequiredLevel(level)))
			return false;
		WString typ=GetType();
		if(XMLNameSpace(typ).empty()){
			if(!TypeString().HasToken(typ,WString::comma))
				return false;
		}
		return true;
	};
	//////////////////////////////////////////////////////////////////////
	/**
	* 
	* remove a resourceLink and potentially its linked resource
	* @param l
	* @param bRemoveResource
	*/
	void JDFNode::removeLink( JDFResourceLink l,  bool bRemoveResource)
	{
		if (l.isNull())
			return;

		if (bRemoveResource)
		{
			JDFResource r = l.GetLinkRoot();
			l.DeleteNode();

			if (r.GetLinks().size() == 0)
			{
				r.deleteUnLinked();
			}
		}
		else
		{
			l.DeleteNode();
		}
	}

	/**
	* remove a type from the types list - also cleaning up combinedprocessindex
	* @param type the type
	* @param iSkip the index of this type in the list of identical types - typically 0
	* @param bRemoveEmptyLink if true, remove any reslinks that have no remaining combinedprocessindex
	* 
	*/
	void JDFNode::removeFromTypes(const WString& type, int iSkip, bool bRemoveEmptyLink)
	{
		vWString v = GetTypes();
		if (v.empty())
		{
			return;
		}
		int n = 0;
		int posLast = -1;
		while (n <= iSkip)
		{
			int pos = v.index(type, posLast + 1);
			posLast = pos;
			if (pos < 0)
			{
				break;
			}
			n++;
		}
		if (posLast >= 0)
		{
			v.remove(posLast);
			SetTypes(v);
			JDFAttributeMap map(atr_CombinedProcessIndex, "*");
			VElement vResLinks = GetResourceLinks(map);
			for ( int li=0;li<vResLinks.size();li++)
			{
				JDFResourceLink rl =vResLinks[li];
				JDFIntegerList list = rl.GetCombinedProcessIndex();
				if (list.size()>0)
				{
					JDFIntegerList newList;
					for (int pi =0;pi<list.size();pi++)
					{
						int i=list[pi];
						if (i < posLast)
						{
							newList.add(i);
						}
						else if (i > posLast)
						{
							newList.add(i - 1);
						}
						// == is obviously omitted - the type is gone

					}
					if (newList.size() > 0)
					{
						rl.SetCombinedProcessIndex(newList);
					}
					else if (bRemoveEmptyLink)
					{
						removeLink(rl, true);
					}
				}
			}
		}
	}


	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetTypes(const vWString & vCombiNodes){
		SetAttribute(atr_Types,vCombiNodes);
	}

	vElement JDFNode::getLinksForCombinedProcessIndex(int combinedProcessIndex)
	{
		JDFNode::EnumType typ = GetEnumType();
		if(!(typ==JDFNode::Type_Combined)&&!(typ==JDFNode::Type_ProcessGroup))
			return vElement::emptyVector;


		VElement vLinks=getLinks(WString::emptyStr,mAttribute::emptyMap,WString::emptyStr);
		if(vLinks.empty())
			return vElement::emptyVector;

		WString indexString=WString::formatInteger(combinedProcessIndex);
		// loop over all links
		for(int i=vLinks.size()-1;i>=0;i--)
		{
			JDFResourceLink rl=(JDFResourceLink) vLinks.elementAt(i);
			if(rl.HasAttribute(JDFStrings::atr_CombinedProcessIndex) &&
				!rl.IncludesMatchingAttribute(JDFStrings::atr_CombinedProcessIndex,indexString,JDFElement::AttributeType_IntegerList)) 
			{
				vLinks.remove(i);
			}
		}
		return vLinks;
	}

	vElement JDFNode::getLinksForType(JDFNode::EnumType type, int nType)
	{
		JDFNode::EnumType typ = GetEnumType();
		if (typ==JDFNode::Type_Unknown)
			return vElement::emptyVector;

		// not combined, simpy get links from entire node 
		if (typ == type)
		{
			return getLinks(WString::emptyStr,mAttribute::emptyMap,WString::emptyStr);
		}

		// nasty - mismatching type attribute
		if(!(typ==JDFNode::Type_Combined)&&!(typ==JDFNode::Type_ProcessGroup))
			return vElement::emptyVector;

		// no types - this is a corrupt node
		vWString vTypes=getEnumTypes();
		if(vTypes.empty())
			return vElement::emptyVector;
		int typSize=vTypes.size();

		// no links here at all
		vElement vLinks=getLinks(WString::emptyStr,mAttribute::emptyMap,WString::emptyStr);
		if(vLinks.empty())
			return vElement::emptyVector;
		// 
		// loop over all links and remove non-matching entries
		for(int i=vLinks.size()-1;i>=0;i--)
		{
			JDFResourceLink rl=(JDFResourceLink) vLinks.elementAt(i);
			JDFIntegerList cpi=rl.GetCombinedProcessIndex();
			if(!cpi.empty()) // there is a cpi, check if it matches
			{
				int size = cpi.size();
				bool bFound=false;
				// loop over indeces of CombinedProcessIndex
				for(int j=0;j<size;j++)
				{
					int index=(int)cpi[j];
					if(index<typSize) // the index points to a vaild position in the list
					{
						JDFNode::EnumType cpiType=(JDFNode::EnumType)((int)vTypes.elementAt(index));
						if(cpiType==type)
						{
							if(nType<0) // flag not to check which ocurrence
							{
								bFound=true;
							}
							else
							{
								int nFound=-1;
								for(int k=0;k<=index;k++) // count occurences of this process type in front of and including this
								{
									JDFNode::EnumType cpiTypeCount=(JDFNode::EnumType)((int)vTypes.elementAt(k));
									if(cpiTypeCount==type)
										nFound++;                                  
								}
								bFound=nFound==nType;
								if(bFound) // we found a good cpi, break search
									break;
							}
						}
					}
				}
				// found non matching cpi - remove link
				if(!bFound) 
				{
					vLinks.remove(i);
				}
			}
		}

		return vLinks;
	}

	/**
	* getLinks - get the links matching mLinkAtt out of the resource link pool
	*
	* @param linkName - the name of the link including or excluding the "Link", 
	* If it is omitted, it will be added
	* @param mLinkAtt - the attributes to search for
	* @param linkNS - the namespace of the link
	*
	* @return VElement - all elements matching the condition mLinkAtt
	* default: getLinks(null,null,null)
	*/
	VElement JDFNode::getLinks(WString linkName, const JDFAttributeMap& mLinkAtt, const WString& linkNS)const
	{
		JDFResourceLinkPool rlp=GetResourceLinkPool();
		if(!linkName.empty() && !linkName.endsWith(atr_Link))
			linkName+=atr_Link;

		return rlp.GetPoolChildren(linkName, mLinkAtt, linkNS);
	}

	/**
	* insert a new Process into @Types at the position pos
	* @param type the process type
	* @param beforePos the position before which to add the in the list, 0 is first, ... -1 is before the last, very large is append
	*/
	void JDFNode::insertTypeInTypes(EnumType type, int beforePos)
	{
		vWString types=GetTypes();

		int typeSize = types.size();
		if(beforePos<0)
			beforePos=typeSize+beforePos;

		if(beforePos<0)
			beforePos=0;

		if(beforePos<=typeSize)
		{
			vElement vResLinks=getLinks(WString::emptyStr,JDFAttributeMap(atr_CombinedProcessIndex,""));
			for(int i=0;i<vResLinks.size();i++)
			{
				JDFResourceLink rl=(JDFResourceLink)vResLinks.elementAt(i);
				JDFIntegerList cpi=rl.GetCombinedProcessIndex();
				for(int j=0;j<cpi.size();j++)
				{
					if (cpi[j]>=beforePos)
						cpi[j]++;
				}
				if(cpi.size()>0)
					rl.SetCombinedProcessIndex(cpi);

			}

			types.insertElementAt(TypeString(type),beforePos);
		}
		else
		{
			types.add(TypeString(type));
		}

		SetTypes(types);
	}
	//////////////////////////////////////////////////////////////////////

	vWString JDFNode::GetTypes()const{
		EnumType typ=GetEnumType();
		if((typ!=Type_Combined)&&(typ!=Type_ProcessGroup)) 
			return vWString();
		WString s=GetAttribute(atr_Types);
		return s.Tokenize(WString::blank);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidTypes(EnumValidationLevel level) const {
		EnumType typ=GetEnumType();
		if(typ==Type_Combined){
			return ValidAttribute(atr_Types,AttributeType_NMTOKENS,RequiredLevel(level));
		}else if(typ==Type_ProcessGroup){
			if(HasChildElement(elm_JDF)){
				return (GetAttribute(atr_Types)==WString::emptyStr);
			}else{
				return ValidAttribute(atr_Types,AttributeType_NMTOKENS,false);
			}
		}else{
			return !HasAttribute(atr_Types);
		}
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetVersion(const WString& value){
		if(VersionString().HasToken(value,WString::comma)){
			SetAttribute(atr_Version,value);
		}else{
			throw JDFException(L"JDFNode::SetVersion: , Unknown version: "+value);
		}
	};
	//////////////////////////////////////////////////////////////////////

	void JDFNode::SetEnumVersion(EnumVersion value){
		SetEnumAttribute(atr_Version,value,VersionString());
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFNode::ValidVersion(EnumValidationLevel level) const {
		WString version=GetVersion(true);
		if(version.empty())
			return !RequiredLevel(level);
		return VersionString().HasToken(version,WString::comma);

	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::FixVersion(EnumVersion version){
		bool bRet=true;
		if (version != Version_Unknown)
		{
			SetEnumVersion(version);
			JDFResourceLinkPool rlp=GetResourceLinkPool();
			// fix NodeInfo and CustomerInfo
			for(int i=0;i<2;i++){
				WString nam=i?elm_NodeInfo:elm_CustomerInfo;
				WString linkNam=nam+atr_Link;
				if(version>=Version_1_3){
					if(HasChildElement(nam)||((i==1) && HasChildElement(elm_StatusPool))){
						JDFElement e=GetElement(nam);
						// move nodeinfo or CustomerInfo into the resource
						if(!rlp.HasChildElement(linkNam)){
							JDFResource r=AddParameter(nam);
							r.MergeElement(e,false);
							if((i==1) && HasChildElement(elm_StatusPool)){

								// get PartStatus vector
								JDFStatusPool statusPool=GetStatusPool();
								vElement vPartStatus=statusPool.GetPoolChildren();
								SetStatus(Status_Part);
								mAttribute mps;
								if(!vPartStatus.empty()){
									JDFPartStatus ps=vPartStatus[0];
									mps=ps.GetPartMap();
								}
								vWString partIDKeys=GetPartIDKeys(mps);

								JDFNodeInfo ni=r;
								ni.SetAttribute(atr_NodeStatus,statusPool.GetAttribute(atr_Status));
								ni.SetAttribute(atr_NodeStatusDetails,statusPool.GetStatusDetails());
								for(int ips=0;ips<vPartStatus.size();ips++){
									JDFPartStatus ps=vPartStatus[ips];
									try{ // see if the partstatus is consistent with what we have
										ni=r.GetCreatePartition(ps.GetPartMap(),partIDKeys);
									}catch (JDFException ex){
										// couldn't create a partiton - flag failure and move on
										bRet=false;
										continue;
									}
									ni.SetAttribute(atr_NodeStatus,ps.GetAttribute(atr_Status));
									ni.SetAttribute(atr_NodeStatusDetails,ps.GetStatusDetails());
								}
								RemoveChild(elm_StatusPool);
							}
						}
						// have both link and element - snafu simply remove element
						RemoveChild(nam);
					}
				}else{ // move to version <= 1.2
					if(rlp.HasChildElement(linkNam)){
						JDFResourceLink rl=rlp.GetPoolChild(0,linkNam);
						JDFResource root=rl.GetLinkRoot();
						JDFElement e=GetCreateElement(nam);

						// not partitioned, simply copy into nodeinfo element
						if(!root.HasAttribute(atr_PartIDKeys)){
							e.MergeElement(root,false);
							if(i==1){
								MoveAttribute(atr_Status,e,atr_NodeStatus);
								MoveAttribute(atr_StatusDetails,e,atr_NodeStatusDetails);
							}
						}else{ // partitioned nodeinfo or customerinfo handling
							if(i==1){ // copy nodeinfo stati into statuspool
								SetStatus(Status_Pool);
								vElement vLeaves=root.GetLeaves();
								JDFStatusPool sp=GetCreateStatusPool();
								sp.RemoveChildren();
								for(int j=0;j<vLeaves.size();j++){
									JDFNodeInfo ni=vLeaves[j];
									JDFPartStatus ps=sp.AppendPartStatus();
									ps.SetPartMap(ni.GetPartMap());
									ps.SetAttribute(atr_Status,ni.GetAttribute(atr_NodeStatus));
									ps.SetAttribute(atr_StatusDetails,ni.GetAttribute(atr_NodeStatusDetails));
								}
							}
							// merge the most fitting resource partition into the unpartitioned 
							// nodeinfo or customerinfo
							JDFResource target=rl.GetTarget();
							KElement targetElement=target;
							targetElement.RemoveChildren(targetElement.GetNodeName());
							target.Expand();
							e.MergeElement(target,false);
						}

						// clean up resource specific attributes
						e.RemoveAttribute(atr_ID);
						e.RemoveAttribute(atr_Class);
						e.RemoveAttribute(atr_Status);
						if(i==1){
							e.RemoveAttribute(atr_NodeStatus);
							e.RemoveAttribute(atr_NodeStatusDetails);
						}

						// ciao bello
						rl.DeleteNode();
						root.DeleteNode();
					}
				}
			}
		}
		return JDFElement::FixVersion(version) && bRet;
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* removes a Resource from this ResourceLinkPool and from the resourcePool if it is 
	* no longer linked to any other process
	* 
	* @param resName  the Nodename of the Resource "NodeInfo" for example
	* @param iSkip     number to skip before deleting
	* @return KElement the removed resource, null if nothing was found or deleated e.g. 4 found 
	*                 and the 5th is the one to deleate. The link is not returned. 
	*                 If the link is deleated and the resource is still linked to another 
	*                 process null is returned. 
	*/
	KElement JDFNode::RemoveResource(const WString& resName, int iSkip)
	{
		WString linkName        = resName + L"Link";
		KElement kRet           = DefKElement;
		JDFResourceLinkPool rlp = GetResourceLinkPool();

		vElement v = rlp.GetChildElementVector(linkName, WString::emptyStr, mAttribute::emptyMap, false, WString::nINF);
		if(v.size() <= iSkip)
		{
			return DefKElement;
		}

		JDFResourceLink rl = (JDFResourceLink)v[iSkip];
		JDFResource r      = rl.GetLinkRoot();
		rl.DeleteNode();
		if(r.isNull()){
			return DefKElement;
		}

		vElement vLinks = r.GetLinks();
		if(vLinks.size() == 0)
		{
			kRet = r.DeleteNode();    
		}

		return kRet;
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	void JDFNode::UpDateStatus(){
		vElement vOut=GetResourceLinkPool().GetInOutLinks(false,false);
		bool bReady=true;
		if(vOut.empty()) 
			return;
		for(int i=0;i<vOut.size();i++){
			JDFResource g=vOut[i];
			if(!g.IsAvailable()){
				bReady=false;
			}
		}
		if(bReady) {
			SetStatus(Status_Completed);
			JDFNode p=GetParentJDFNode();
			p.UpDateStatus();
		}
	}

	//////////////////////////////////////////////////////////////////////

	JDFNode JDFNode::GetJobPart(const WString & jobPartID_a, const WString & jobID_a)const
	{
		JDFNode node=*this;
		if (!jobID_a.empty())
		{
			// search for a matching JobID, 
			if (GetJobID(true)==jobID_a) 
			{
				node = *this;
			}
			else
			{
				// searchg for the JobID in the descendents
				node = GetChildWithAttribute(elm_JDF,atr_JobID,WString::emptyStr,jobID_a,0,false);
			}

			if (node.isNull())
				return node;  // search for a node having the specified JobID failed 
		}

		if (jobPartID_a.empty())
		{
			if (jobID_a.empty())
			{
				// both JobID and JobPartID should be empty
				if (GetJobID(true).empty() && GetJobPartID(true).empty())
					return *this;
			}
			else
			{
				// if a node has already been found for JobID then return the node
				return node;
			}
		}
		else // if (!node.isNull())
		{
			//  search only for the first matching JobPartID
			if (node.GetJobPartID(true)==jobPartID_a) 
			{
				node = *this;
			}
			else
			{
				// search for the JobPartID in the descendents
				node = node.GetChildWithAttribute(elm_JDF,atr_JobPartID,WString::emptyStr,jobPartID_a,0,false);
			}

			return node;
		}

		// didn't found a matching node
		return DefJDFNode;

	}

	///////////////////////////////////////////////////////////////

	//check for any resources that
	vElement JDFNode::CheckSpawnedResources(const vWString& vRWResources,const vmAttribute& vSpawnParts){
		JDFSpawn spawn(*this);
		return spawn.checkSpawnedResources(vRWResources,vSpawnParts);
	}


	///////////////////////////////////////////////////////////////

	JDFDoc JDFNode::SpawnInformative(const WString &  parentURL, const WString& spawnURL, const vmAttribute& vSpawnParts, bool bSpawnROPartsOnly,bool bCopyNodeInfo, bool bCopyCustomerInfo, bool bCopyComments) const{
		JDFDoc d(0);
		JDFNode n = d.GetRoot();
		JDFNode n2 = *this;
		n = JDFSpawn(n2).spawnInformative(parentURL, spawnURL, vSpawnParts, bSpawnROPartsOnly, bCopyNodeInfo, bCopyCustomerInfo, bCopyComments).GetJDFRoot();
		return d;
	}

	///////////////////////////////////////////////////////////////
	// interface changed: returns JDFDoc instead of JDFNode [RN 21.07.03]
	///////////////////////////////////////////////////////////////

	JDFDoc JDFNode::Spawn(const WString &  parentURL, const WString& spawnURL, const vWString& vRWResources_in, const vmAttribute& vSpawnParts, bool bSpawnROPartsOnly,bool bCopyNodeInfo, bool bCopyCustomerInfo, bool bCopyComments){
		JDFSpawn spawn(*this);
		JDFDoc d(0);
		//JDFNode n = d.GetJDFRoot();
		d = spawn.spawn(parentURL,spawnURL,vRWResources_in,vSpawnParts,bSpawnROPartsOnly,bCopyNodeInfo,bCopyCustomerInfo,bCopyComments);
		return d; 
	}

	///////////////////////////////////////////////////////////////

	bool JDFNode::UnSpawnNode(const WString & spawnID){
		if(throwNull()||spawnID.empty())
			return false;

		mAttribute mapSpawn;
		mapSpawn.AddPair(atr_NewSpawnID,spawnID);
		JDFSpawned spawnAudit=GetAuditPool().GetAudit(0,JDFAudit::AuditType_Spawned,mapSpawn);

		// loop over all 
		mAttribute mapMerge;
		mapMerge.AddPair(atr_MergeID,spawnID);

		JDFMerged mergedAudit=GetAuditPool().GetAudit(0,JDFAudit::AuditType_Merged,mapMerge);
		// cannot undo - it is already merged
		if(!mergedAudit.isNull())
			return false;


		// get parts from audit
		vmAttribute parts=spawnAudit.GetPartMapVector();
		if (parts.size() == 1){
			if (parts[0].empty()){
				parts.clear();
			}
		}

		// loop over all referenced ROCopied resources
		vWString vs=spawnAudit.GetrRefsROCopied();

		int i;
		for(i=0;i<vs.size();i++){
			JDFResource oldRes=GetTarget(vs[i]);
			oldRes.UnSpawnPart(spawnID,oldRes.SpawnStatus_SpawnedRO);
		}
		// merge rw resources
		vs=spawnAudit.GetrRefsRWCopied();
		for(i=0;i<vs.size();i++){
			JDFResource oldRes=GetTarget(vs[i]);
			oldRes.UnSpawnPart(spawnID,oldRes.SpawnStatus_SpawnedRW);
		}

		JDFNode localNode=GetTarget(spawnAudit.GetjRef());
		vElement vn=localNode.GetvJDFNode();

		// loop over all child nodes of the spawned node to be unspawned
		for(int nod=0;nod<vn.size();nod++){
			JDFNode deepNode=vn.at(nod);
			JDFResourcePool resPool = deepNode.GetResourcePool();

			if (resPool.isNull())
				continue;

			vElement vRes = resPool.GetPoolChildren();

			for (i = 0; i < vRes.size(); i++){
				JDFResource res1=vRes[i];
				res1.UnSpawnPart(spawnID,JDFResource::SpawnStatus_SpawnedRW);
			}			
		}

		EnumStatus status=spawnAudit.HasAttribute(atr_Status)?spawnAudit.GetStatus():Status_Waiting;

		if(!parts.empty()){
			if (GetStatus() == Status_Pool || GetStatus() == Status_Part){
				for(int i=0;i<parts.size();i++){
					if((GetPartStatus(parts[i])==Status_Spawned)||(spawnAudit.HasAttribute(atr_Status))){
						// 100602 RP fix
						SetPartStatus(parts[i],status);
					}
				}
			}else{
				if((GetStatus()==Status_Spawned)||(spawnAudit.HasAttribute(atr_Status)))
					SetStatus(status);
			}
		}else{
			// we either must overwrite because it is now definitely not spawned or had an explicit correct status in the spawned audit
			if((localNode.GetStatus()==Status_Spawned)||(spawnAudit.HasAttribute(atr_Status)))
				localNode.SetStatus(status);
		}			
		spawnAudit.DeleteNode();
		return true;		
	}

	///////////////////////////////////////////////////////////////

	JDFResourceLink JDFNode::GetLink(const JDFResource& r, bool bInput){
		return getLink(r,bInput ? JDFResourceLink::Usage_Input :  JDFResourceLink::Usage_Output);
	}
	///////////////////////////////////////////////////////////////

	JDFResourceLink JDFNode::getLink(const JDFResource& r, JDFResourceLink::EnumUsage usage){
		// get the reslink pool
		JDFResourceLinkPool p=GetResourceLinkPool();
		if(p.isNull()) 
			return JDFResourceLink();

		// get any possible links
		vElement v=p.getInOutLinks(usage,true);
		// is it the right one?
		for(int i=0;i<v.size();i++){
			if(JDFElement(v[i]).GetHRef()==r.GetID()) 
				return v[i]; // heureka!
		}
		// nothing found
		return JDFResourceLink();
	}


	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFNodeInfo JDFNode::GetInheritedNodeInfo()const
	{
		return (JDFNodeInfo)getNiCi(elm_NodeInfo,true);
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFDuration JDFNode::GetNodeInfoCleanupDuration() const {
		return GetInheritedNodeInfo().GetCleanupDuration();
	}

	//////////////////////////////////////////////////////////////////////

	JDFMISDetails::EnumCostType JDFNode::GetNodeInfoCostType() const {
		return GetInheritedNodeInfo().GetMISDetails().GetCostType();
	}

	//////////////////////////////////////////////////////////////////////

	JDFNodeInfo::EnumDueLevel JDFNode::GetNodeInfoDueLevel() const {
		return GetInheritedNodeInfo().GetDueLevel();
	}

	//////////////////////////////////////////////////////////////////////

	JDFDate JDFNode::GetNodeInfoEnd() const {
		return GetInheritedNodeInfo().GetEnd();
	}
	//////////////////////////////////////////////////////////////////////

	JDFDate JDFNode::GetNodeInfoFirstEnd() const {
		return GetInheritedNodeInfo().GetFirstEnd();
	}
	//////////////////////////////////////////////////////////////////////

	JDFDate JDFNode::GetNodeInfoFirstStart() const {
		return GetInheritedNodeInfo().GetFirstStart();
	}
	//////////////////////////////////////////////////////////////////////

	JDFXYPair JDFNode::GetNodeInfoIPPVersion() const {
		return GetInheritedNodeInfo().GetIPPVersion();
	}
	//////////////////////////////////////////////////////////////////////

	int JDFNode::GetNodeInfoJobPriority() const {
		return GetInheritedNodeInfo().GetJobPriority();
	}

	//////////////////////////////////////////////////////////////////////

	JDFDate JDFNode::GetNodeInfoLastEnd() const {
		return GetInheritedNodeInfo().GetLastEnd();
	}
	//////////////////////////////////////////////////////////////////////

	JDFDate JDFNode::GetNodeInfoLastStart() const {
		return GetInheritedNodeInfo().GetLastStart();
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetNodeInfoNaturalLang() const {
		return GetInheritedNodeInfo().GetNaturalLang();
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFNode::GetNodeInfoMergeTarget() const {
		return GetInheritedNodeInfo().GetMergeTarget();
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetNodeInfoRoute() const {
		return GetInheritedNodeInfo().GetRoute();
	}
	//////////////////////////////////////////////////////////////////////

	vWString JDFNode::GetNodeInforRefs() const {
		return GetInheritedNodeInfo().GetrRefs();
	}
	//////////////////////////////////////////////////////////////////////

	JDFDuration JDFNode::GetNodeInfoSetupDuration() const {
		return GetInheritedNodeInfo().GetSetupDuration();
	}
	//////////////////////////////////////////////////////////////////////

	JDFDate JDFNode::GetNodeInfoStart() const {
		return GetInheritedNodeInfo().GetStart();
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetNodeInfoTargetRoute() const {
		return GetInheritedNodeInfo().GetTargetRoute();
	}
	//////////////////////////////////////////////////////////////////////

	JDFDuration JDFNode::GetNodeInfoTotalDuration() const {
		return GetInheritedNodeInfo().GetTotalDuration();
	}
	//////////////////////////////////////////////////////////////////////

	JDFMISDetails::EnumWorkType JDFNode::GetNodeInfoWorkType() const {
		return GetInheritedNodeInfo().GetMISDetails().GetWorkType();
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetNodeInfoWorkTypeDetails() const {
		return GetInheritedNodeInfo().GetMISDetails().GetWorkTypeDetails();
	}
	//////////////////////////////////////////////////////////////////////

	JDFBusinessInfo JDFNode::GetNodeInfoBusinessInfo() const {
		return GetInheritedNodeInfo().GetBusinessInfo();
	}
	//////////////////////////////////////////////////////////////////////

	JDFEmployee JDFNode::GetNodeInfoEmployee() const {
		return GetInheritedNodeInfo().GetEmployee();
	}
	//////////////////////////////////////////////////////////////////////

	JDFJMF JDFNode::GetNodeInfoJMF(int iSkip) const {
		return GetInheritedNodeInfo().GetJMF(iSkip);
	}
	//////////////////////////////////////////////////////////////////////

	JDFMISDetails JDFNode::GetNodeInfoMISDetails() const {
		return GetInheritedNodeInfo().GetMISDetails();
	}

	//////////////////////////////////////////////////////////////////////

	JDFNotificationFilter JDFNode::GetNodeInfoNotificationFilter(int iSkip) const {
		return GetInheritedNodeInfo().GetNotificationFilter(iSkip);
	}


	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFCustomerInfo JDFNode::GetInheritedCustomerInfo()const{
		return (JDFCustomerInfo)getNiCi(elm_CustomerInfo, true);
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetCustomerInfoBillingCode() const{
		return GetInheritedCustomerInfo().GetBillingCode();
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetCustomerInfoCustomerID() const{
		return GetInheritedCustomerInfo().GetCustomerID();
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetCustomerInfoCustomerJobName() const{
		return GetInheritedCustomerInfo().GetCustomerJobName();
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetCustomerInfoCustomerOrderID() const{
		return GetInheritedCustomerInfo().GetCustomerOrderID();
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFNode::GetCustomerInfoCustomerProjectID() const{
		return GetInheritedCustomerInfo().GetCustomerProjectID();
	}
	//////////////////////////////////////////////////////////////////////

	vWString JDFNode::GetCustomerInforRefs() const{
		return GetInheritedCustomerInfo().GetrRefs();
	}
	//////////////////////////////////////////////////////////////////////

	JDFCompany JDFNode::GetCustomerInfoCompany() const{
		return GetInheritedCustomerInfo().GetCompany();
	}
	//////////////////////////////////////////////////////////////////////

	JDFContact JDFNode::GetCustomerInfoContact(int iSkip) const{
		return GetInheritedCustomerInfo().GetContact(iSkip);
	}
	//////////////////////////////////////////////////////////////////////

	JDFCustomerMessage JDFNode::GetCustomerInfoCustomerMessage(int iSkip) const{
		return GetInheritedCustomerInfo().GetCustomerMessage(iSkip);
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////



	vWString JDFNode::GetAncestorIDs()const{
		vWString vs;
		if(isNull()) 
			return vs;
		JDFNode me=*this;
		while(42){
			WString pid=me.GetID();
			JDFNode parent=me.GetParentNode();
			vs.push_back(pid);
			if(parent.isNull())	
				break;
			if(parent.GetNodeName()!=GetNodeName()) 
				break;
			me=parent;
		}
		// 010702 invert
		vWString vs2;
		for(int i=vs.size()-1;i>=0;i--){
			vs2.push_back(vs[i]);
		}
		return vs2;
	}

	//////////////////////////////////////////////////////////////////////

	/**
	typesafe validator
	*/
	vWString JDFNode::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		level=IncompleteLevel(level);
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();

		if(!ValidActivation(level)) {
			vAtts.push_back(atr_Activation);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidCategory(level)) {
			vAtts.push_back(atr_Category);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidICSVersions(level)) {
			vAtts.push_back(atr_ICSVersions);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidID(level)) {
			vAtts.push_back(atr_ID);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidJobID(level)) {
			vAtts.push_back(atr_JobID);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidJobPartID(level)) {
			vAtts.push_back(atr_JobPartID);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidMaxVersion(level)) {
			vAtts.push_back(atr_MaxVersion);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidNamedFeatures(level)) {
			vAtts.push_back(atr_NamedFeatures);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidProjectID(level)) {
			vAtts.push_back(atr_ProjectID);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidRelatedJobID(level)) {
			vAtts.push_back(atr_RelatedJobID);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidRelatedJobPartID(level)) {
			vAtts.push_back(atr_RelatedJobPartID);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidSpawnID(level)) {
			vAtts.push_back(atr_SpawnID);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidStatus(level)) {
			vAtts.push_back(atr_Status);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidStatusDetails(level)) {
			vAtts.push_back(atr_StatusDetails);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidTemplate(level)) {
			vAtts.push_back(atr_Template);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidTemplateID(level)) {
			vAtts.push_back(atr_TemplateID);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidTemplateVersion(level)) {
			vAtts.push_back(atr_TemplateVersion);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidType(level)) {
			vAtts.push_back(atr_Type);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidTypes(level)) {
			vAtts.push_back(atr_Types);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidVersion(level)) {
			vAtts.push_back(atr_Version);
			if(++n>=nMax) 
				return vAtts;
		};

		// 'xsi:type' is not yet in optional

		WString nsAtt=atr_xmlns;
		if(!GetPrefix().empty()){
			nsAtt+=WString::colon+GetPrefix();
		}
		WString nsURI=GetInheritedAttribute(nsAtt);
		if((RequiredLevel(level)&&nsURI.empty()) || (!IsInJDFNameSpace())){
			vAtts.push_back(atr_xmlns);
			if(++n>=nMax) 
				return vAtts;
		}


		return vAtts;
	};

	/**
	definition of required attributes in the JDF namespace
	*/
	WString JDFNode::RequiredAttributes()const{
		static const WString req=L",ID,Status,Type";
		WString s=JDFElement::RequiredAttributes()+req;
		if(IsCombined()){ 
			s+=L",Types";
		}
		if(GetParentNode().GetLocalName()!=GetLocalName()){
			s+=L",Version";
			if(GetPrefix().empty()){
				s+=L",xmlns";
			}else{
				s+=L",xmlns:"+GetPrefix();
			}
		}

		return s;
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	WString JDFNode::OptionalAttributes()const{
		static const WString opt=L",Activation,Category,ICSVersions,JobID,JobPartID,MaxVersion,NamedFeatures,ProjectID,RelatedJobID,RelatedJobPartID,SpawnID,StatusDetails,Template,TemplateID,TemplateVersion,Version";
		WString s= JDFElement::OptionalAttributes()+opt;
		if(IsProcessGroup()&&!HasChildElement(elm_JDF)){ 
			static const WString types=L",Types";
			s+=types;
		}
		return s;
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	WString JDFNode::UniqueElements()const{
		const static WString s=L",AncestorPool,AuditPool,CustomerInfo,NodeInfo,ResourceLinkPool,ResourcePool,StatusPool";
		return JDFElement::UniqueElements()+s;
	};
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	WString JDFNode::OptionalElements()const{
		WString typ=GetType();
		const static WString jdf=L",JDF";
		WString elms=JDFElement::OptionalElements()+L",AncestorPool,AuditPool,CustomerInfo,NodeInfo,ResourceLinkPool,ResourcePool,StatusPool";
		if( (typ==L"ProcessGroup") || (typ==L"Product") ){
			elms+=jdf;
		}
		return elms;
	};


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	sets node's partition status
	*/
	bool JDFNode::SetPartStatus (const vmAttribute& vmattr, EnumStatus status, const WString& statusDetails, const vWString partIDKeys)
	{
		bool bRet=true;
		int siz=vmattr.size();
		if(siz>0){
			for(int i=0;i<siz;i++){
				bRet=bRet && SetPartStatus(vmattr[i],status,statusDetails,partIDKeys);
			}
		}else{
			bRet=SetPartStatus(mAttribute::emptyMap,status,statusDetails,partIDKeys);
		}
		return bRet;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	sets node's partition status
	*/
	bool JDFNode::SetPartStatus (const mAttribute& mattr, EnumStatus status, const WString& statusDetails,  const vWString partIDKeys)
	{
		bool bRet=true;
		EnumStatus stat = GetStatus();

		// 100602 handle nasty combination
		if ( !mattr.empty() && (status == Status_Pool || status == Status_Part)){
			// throw an exception??? this is a snafu to set an individual part status to pool
			return false;
		}

		if (mattr.empty()) {
			SetStatus (status);
			SetStatusDetails(statusDetails);
			RemoveChild(elm_StatusPool);
			// tbd kai, also clean up nodeinfo status leaves
			return true;
		}
		if(GetEnumVersion(true)<Version_1_3){
			// we are setting an individual attribute
			JDFStatusPool statusPool = GetCreateStatusPool();

			if (stat != Status_Pool){
				statusPool.SetStatus (stat);
				statusPool.SetStatusDetails(statusDetails);

				SetStatus (JDFNode::Status_Pool);
			}

			statusPool.SetStatus (mattr, status, statusDetails);

			// this can happen if status = the previous status
			// just remove the pool and reset the status to the original status
			if(statusPool.NumChildElements(elm_PartStatus)==0){
				SetStatus(status);
				SetStatusDetails(statusDetails);
				statusPool.DeleteNode();
			}
		}else{
			JDFNodeInfo ni=GetCreateNodeInfo();
			if(GetStatus()!=JDFNode::Status_Part) { //  set a decent default status for implicit
				ni.SetAttribute(atr_NodeStatus,StatusString(GetStatus()));
				ni.SetAttribute(atr_NodeStatusDetails,GetStatusDetails());
				RemoveAttribute(atr_StatusDetails);
			}

			ni.GetResourceRoot().SetPartUsage(JDFResource::PartUsage_Implicit);
			try{
				ni=ni.GetCreatePartition(mattr,partIDKeys);
			}catch(JDFException ex){
				bRet=false;
			}
			ni.RemoveAttributeFromLeaves(atr_NodeStatusDetails);
			ni.RemoveAttributeFromLeaves(atr_NodeStatus);
			ni.SetNodeStatus(status);
			ni.SetAttribute(atr_NodeStatus,StatusString(status));
			if(!statusDetails.empty())
				ni.SetAttribute(atr_NodeStatusDetails,statusDetails);

			SetStatus (JDFNode::Status_Part);
		}

		return bRet;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	gets node's partition status
	*/
	JDFNode::EnumStatus JDFNode::GetPartStatus (const mAttribute& mattr)
	{
		EnumStatus stat = GetStatus();
		if ((stat != Status_Pool)&&(stat != Status_Part)){
			return stat;
		}else if (stat==Status_Part){
			JDFNodeInfo ni=GetNodeInfo();
			ni=ni.GetPartition(mattr);
			stat=(EnumStatus) ni.GetEnumAttribute(L"NodeStatus",StatusString());
			WString statString = ni.GetAttribute(L"NodeStatus");
			vElement vLeaves=ni.GetLeaves(true);
			for(int i=0;i<vLeaves.size();i++){
				JDFNodeInfo niCmp=(JDFNodeInfo) vLeaves[i];
				WString statStringCmp = niCmp.GetAttribute(L"NodeStatus");
				if(statString!=statStringCmp)
				{
					return Status_Unknown; //inconsistent
				}
			}

		}else if (stat==Status_Pool){
			JDFStatusPool statusPool = GetStatusPool();
			stat = statusPool.GetStatus(mattr);
		}
		return stat;
	}

	/**
	gets node's partition statusdetails
	*/
	WString JDFNode::GetPartStatusDetails (const mAttribute& mattr)
	{
		EnumStatus stat = GetStatus();
		WString statDet = GetStatusDetails();
		if ((stat != Status_Pool)&&(stat != Status_Part)){
			return statDet;
		}else if (stat==Status_Part){
			JDFNodeInfo ni=GetNodeInfo();
			ni=ni.GetPartition(mattr);
			statDet=ni.GetAttribute(atr_NodeStatusDetails);
		}else if (stat==Status_Pool){
			JDFStatusPool statusPool = GetStatusPool();
			statDet = statusPool.GetStatusDetails(mattr);
		}
		return statDet;
	}	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */


	JDFAncestorPool JDFNode::GetCreateAncestorPool(){
		return GetCreateElement(elm_AncestorPool);
	};

	//////////////////////////////////////////////////////////////////////

	JDFAncestorPool JDFNode::AppendAncestorPool(){
		return AppendElementN(elm_AncestorPool,1);
	};
	//////////////////////////////////////////////////////////////////////

	JDFAncestorPool JDFNode::GetAncestorPool()const{
		return GetElement(elm_AncestorPool);
	};

	//////////////////////////////////////////////////////////////////////
	JDFAuditPool JDFNode::GetCreateAuditPool(){
		return GetCreateElement(elm_AuditPool);
	};
	//////////////////////////////////////////////////////////////////////

	JDFAuditPool JDFNode::AppendAuditPool(){
		return AppendElementN(elm_AuditPool,1);
	};
	//////////////////////////////////////////////////////////////////////

	JDFAuditPool JDFNode::GetAuditPool()const{
		return GetElement(elm_AuditPool);
	};

	//////////////////////////////////////////////////////////////////////

	JDFCustomerInfo JDFNode::GetCreateCustomerInfo(){
		//check if this already has a customerinfo
		JDFCustomerInfo ci = GetCustomerInfo();
		if(ci.isNull()){
			EnumVersion eVer = GetEnumVersion(true);
			if (eVer >= Version_1_3)
			{
				ci= (JDFCustomerInfo)AddParameter(JDFElement::elm_CustomerInfo);
			}else{
				ci= AppendElement(elm_CustomerInfo);
			}
			ci.init();
		}
		return ci;
	}

	//////////////////////////////////////////////////////////////////////

	JDFCustomerInfo JDFNode::GetCustomerInfo()const
	{
		return (JDFCustomerInfo) getNiCi(elm_CustomerInfo, false);
	};

	//////////////////////////////////////////////////////////////////////

	JDFCustomerInfo JDFNode::AppendCustomerInfo()
	{
		JDFCustomerInfo ci=GetCustomerInfo();
		if(!ci.isNull())
			throw(L"JDFNode::AppendCustomerInfo: CustomerInfo already exists");
		return GetCreateCustomerInfo();
	};

	///////////////////////////////////////////////////////////////////////////////////

	JDFNodeInfo JDFNode::GetCreateNodeInfo()
	{
		//check if this already has a Nodeinfo
		JDFNodeInfo ni = GetNodeInfo();
		if(ni.isNull()){
			EnumVersion eVer = GetEnumVersion(true);
			if (eVer >= Version_1_3)
			{
				ni= (JDFNodeInfo)AddParameter(JDFElement::elm_NodeInfo);
			}else{
				ni= AppendElement(elm_NodeInfo);
			}
			ni.init();
		}
		return ni;

	};

	//////////////////////////////////////////////////////////////////////
	JDFNodeInfo JDFNode::AppendNodeInfo()
	{
		JDFNodeInfo ni=GetNodeInfo();
		if(!ni.isNull())
			throw JDFException(L"JDFNode::AppendNodeInfo: NodeInfo already exists");
		return GetCreateNodeInfo();
	};

	//////////////////////////////////////////////////////////////////////

	JDFNodeInfo JDFNode::GetNodeInfo()const
	{
		return (JDFNodeInfo) getNiCi(elm_NodeInfo,false);
	};


	//////////////////////////////////////////////////////////////////////

	/**
	* removes all NodeInfo elements 
	*/
	void JDFNode::RemoveNodeInfos()
	{
		while(HasNodeInfo())
		{
			KElement remRes = RemoveResource(elm_NodeInfo, 0);
			if (remRes.isNull())
			{
				//removed all in the resource pool
				break;
			}
		}

		//remove all direct childs
		vElement nodeInfoChilds = GetChildElementVector(elm_NodeInfo, WString::emptyStr, mAttribute::emptyMap, true, WString::pINF,false);
		for(int i = 0; i < nodeInfoChilds.size(); i++)
		{
			RemoveChild(nodeInfoChilds.elementAt(i).GetNodeName());
		}
	};

	//////////////////////////////////////////////////////////////////////

	/**
	* removes all CustomerInfo elements 
	*/
	void JDFNode::RemoveCustomerInfos()
	{
		KElement remRes = RemoveResource(elm_CustomerInfo, 0);
		while(HasCustomerInfo())
		{
			RemoveResource(elm_CustomerInfo, 0);
			if (remRes.isNull())
			{
				//removed all in the resource pool
				break;
			}
		}

		//remove all direct childs
		vElement nodeInfoChilds = GetChildElementVector(elm_CustomerInfo, WString::emptyStr, mAttribute::emptyMap, true, WString::pINF,false);
		for(int i = 0; i < nodeInfoChilds.size(); i++)
		{
			RemoveChild(nodeInfoChilds.elementAt(i).GetNodeName());
		}
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFNode::HasCustomerInfo()
	{
		return NumCustomerInfos() > 0;
	};

	//////////////////////////////////////////////////////////////////////

	int JDFNode::NumCustomerInfos()
	{
		int i = NumChildElements(JDFElement::elm_CustomerInfo, WString::emptyStr); 
		JDFResourceLinkPool rlp = GetResourceLinkPool();
		if(rlp != NULL)
		{
			i += rlp.GetPoolChildren(L"CustomerInfoLink", mAttribute::emptyMap).size();
		}
		return i;
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFNode::HasNodeInfo()
	{
		return NumNodeInfos() > 0;
	};

	//////////////////////////////////////////////////////////////////////

	int JDFNode::NumNodeInfos()
	{
		int i = NumChildElements(JDFElement::elm_NodeInfo, WString::emptyStr); 
		JDFResourceLinkPool rlp = GetResourceLinkPool();
		if(rlp != NULL)
		{
			i += rlp.GetPoolChildren(L"NodeInfoLink", mAttribute::emptyMap).size();
		}
		return i;
	};

	//////////////////////////////////////////////////////////////////////

	JDFResourceLinkPool JDFNode::GetCreateResourceLinkPool(){
		return GetCreateElement(elm_ResourceLinkPool);
	};
	//////////////////////////////////////////////////////////////////////

	JDFResourceLinkPool JDFNode::AppendResourceLinkPool(){
		return AppendElementN(elm_ResourceLinkPool,1);
	};
	//////////////////////////////////////////////////////////////////////
	JDFResourceLinkPool JDFNode::GetResourceLinkPool()const{
		return GetElement(elm_ResourceLinkPool);
	};

	//////////////////////////////////////////////////////////////////////

	JDFResourcePool JDFNode::GetCreateResourcePool(){
		return GetCreateElement(elm_ResourcePool);
	};
	//////////////////////////////////////////////////////////////////////

	JDFResourcePool JDFNode::AppendResourcePool(){
		return AppendElementN(elm_ResourcePool,1);
	};
	//////////////////////////////////////////////////////////////////////
	JDFResourcePool JDFNode::GetResourcePool()const{
		return GetElement(elm_ResourcePool);
	};

	//////////////////////////////////////////////////////////////////////

	JDFStatusPool JDFNode::GetCreateStatusPool(){
		SetStatus(JDFNode::Status_Pool);
		return GetCreateElement(elm_StatusPool);
	};

	//////////////////////////////////////////////////////////////////////

	JDFStatusPool JDFNode::AppendStatusPool(){
		SetStatus(JDFNode::Status_Pool);
		return AppendElementN(elm_StatusPool,1);
	};

	//////////////////////////////////////////////////////////////////////

	JDFStatusPool JDFNode::GetStatusPool()const{
		return GetElement(elm_StatusPool);
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	typesafe validator
	*/
	vWString JDFNode::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		level=IncompleteLevel(level);
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax) return vElem;
		nElem=NumChildElements(elm_AncestorPool);
		if (nElem>1) {
			vElem.push_back(elm_AncestorPool);
			if (++n>=nMax) return vElem;
		};
		for(i=0;i<nElem;i++){
			JDFAncestorPool child=GetElement(elm_AncestorPool,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_AncestorPool);
				if (++n>=nMax) return vElem;
			};
		}
		nElem=NumChildElements(elm_AuditPool);
		if (nElem>1) {
			vElem.push_back(elm_AuditPool);
			if (++n>=nMax) return vElem;
		};
		for(i=0;i<nElem;i++){
			JDFAuditPool child=GetElement(elm_AuditPool,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_AuditPool);
				if (++n>=nMax) return vElem;
			};
		}
		nElem=NumChildElements(elm_CustomerInfo);
		if (nElem>1) {
			vElem.push_back(elm_CustomerInfo);
			if (++n>=nMax) return vElem;
		};
		for(i=0;i<nElem;i++){
			JDFCustomerInfo child=GetElement(elm_CustomerInfo,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_CustomerInfo);
				if (++n>=nMax) return vElem;
			};
		}
		nElem=NumChildElements(elm_NodeInfo);
		if (nElem>1) {
			vElem.push_back(elm_NodeInfo);
			if (++n>=nMax) return vElem;
		};
		for(i=0;i<nElem;i++){
			JDFNodeInfo child=GetElement(elm_NodeInfo,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_NodeInfo);
				if (++n>=nMax) return vElem;
			};
		}
		nElem=NumChildElements(elm_ResourceLinkPool);
		if (nElem>1) {
			vElem.push_back(elm_ResourceLinkPool);
			if (++n>=nMax) return vElem;
		};
		for(i=0;i<nElem;i++){
			JDFResourceLinkPool child=GetElement(elm_ResourceLinkPool,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_ResourceLinkPool);
				if (++n>=nMax) return vElem;
			};
		}
		nElem=NumChildElements(elm_ResourcePool);
		if (nElem>1) {
			vElem.push_back(elm_ResourcePool);
			if (++n>=nMax) return vElem;
		};
		for(i=0;i<nElem;i++){
			JDFResourcePool child=GetElement(elm_ResourcePool,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_ResourcePool);
				if (++n>=nMax) return vElem;
			};
		}
		nElem=NumChildElements(elm_StatusPool);
		if (nElem>1) {
			vElem.push_back(elm_StatusPool);
			if (++n>=nMax) 
				return vElem;
		};
		for(i=0;i<nElem;i++){
			JDFStatusPool child=GetElement(elm_StatusPool,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_StatusPool);
				if (++n>=nMax) 
					return vElem;
			};
		}
		if(level>=ValidationLevel_RecursiveIncomplete){
			nElem=NumChildElements(elm_JDF);
			for(i=0;i<nElem;i++){
				JDFNode child=GetElement(elm_JDF,WString::emptyStr,i);
				if (!child.IsValid(level)) {
					vElem.push_back(elm_JDF);
					if (++n>=nMax)
						return vElem;
					break;
				};
			}
		}
		return vElem;
	};


	/////////////////////////////////////////////////////////////////////////

	vWString JDFNode::vLinkInfo(int namIndex)const{
		vWString vRet;
		vWString linkInfo = LinkInfo().Tokenize(WString::comma);
		if (namIndex < 0)
		{
			// tokenize retains order
			return vWString(linkInfo);
		}

		vWString linkNames = LinkNames().Tokenize(WString::comma);

		WString strName  = linkNames.stringAt(namIndex);

		while (namIndex >= 0)
		{
			WString kToken  = linkInfo.stringAt(namIndex);
			vWString  vToken = kToken.Tokenize(WString::blank);

			vRet.addAll(vToken);
			namIndex = linkNames.index(strName, ++namIndex);
		}

		return vRet.empty() ? vWString::emptyvStr : vRet;
	};

	/////////////////////////////////////////////////////////////////////////
	/**
	typesafe validator
	*/
	vWString JDFNode::GetUnknownLinkVector(vWString vInNameSpace, int nMax) const{
		vWString names=LinkNames().Tokenize(WString::comma);
		vElement ve=getLinks(WString::emptyStr, mAttribute::emptyMap, WString::emptyStr);
		vWString vUnknown;
		bool bAllNS=vInNameSpace.empty();
		for(int j=0;j<vInNameSpace.size();j++) {
			// tokenize needs a blank
			if(vInNameSpace[j]==WString::blank)
				vInNameSpace[j]=WString::emptyStr;
		}

		for(int i=0;i<ve.size();i++){
			JDFResourceLink rl=ve[i];
			WString name=rl.GetNodeName().leftStr(-4);
			if(bAllNS||(vInNameSpace.hasString(XMLNameSpace(name)))){
				if(!names.hasString(name)){
					vUnknown.AppendUnique(name);
					if(vUnknown.size()>=nMax) 
						break;
				}
			}
		}
		return vUnknown;
	}

	vElement JDFNode::getUnknownLinkVector(vWString vInNameSpace, int nMax) const{
		vWString names=LinkNames().Tokenize(WString::comma);
		vElement ve=getLinks(WString::emptyStr, mAttribute::emptyMap, WString::emptyStr);
		vElement vUnknown;
		bool bAllNS=vInNameSpace.empty();
		for(int j=0;j<vInNameSpace.size();j++) {
			// tokenize needs a blank
			if(vInNameSpace[j]==WString::blank)
				vInNameSpace[j]=WString::emptyStr;
		}

		for(int i=0;i<ve.size();i++){
			JDFResourceLink rl=ve[i];
			WString name=rl.GetNodeName().leftStr(-4);
			if(bAllNS||(vInNameSpace.hasString(XMLNameSpace(name)))){
				if(!names.hasString(name)){
					vUnknown.AppendUnique(rl);
					if(vUnknown.size()>=nMax) 
						break;
				}
			}
		}
		return vUnknown;
	}

	/////////////////////////////////////////////////////////////////////////

	bool JDFNode::HasMissingLinks()const{ 
		return GetMissingLinkVector(1).size()>0;
	};

	/////////////////////////////////////////////////////////////////////////

	/**
	typesafe validator
	*/
	vWString JDFNode::GetMissingLinkVector(int nMax) const{
		vWString names=LinkNames().Tokenize(WString::comma);
		vWString vMissing;
		if(GetEnumType()==Type_ProcessGroup){
			return vMissing;
		}
		for(int i=0;i<names.size();i++){
			vWString types=vLinkInfo(i);	
			int siz =types.size();
			for(int j=0;j<siz;j++){
				WString typesAt = types.elementAt(j);
				if (typesAt.at(1) == L'+' || typesAt.at(1) == L'_')
				{
					// 110602 added
					EnumProcessUsage pu=GetEnumProcessUsage(types[j]);
					if(GetMatchingLink(names[i],pu,0).isNull()){
						WString s=names[i]+atr_Link;
						if(pu!=ProcessUsage_Any){
							s+=WString::colon+ProcessUsageString(pu);
						}

						vMissing.push_back(s);
						if(vMissing.size()>=nMax) 
							break;
					}				
				}
			}
		}
		return vMissing;
	}/////////////////////////////////////////////////////////////////////////

	/**
	typesafe validator
	*/
	vWString JDFNode::GetInsertLinkVector(int nMax) const{
		vWString names=LinkNames().Tokenize(WString::comma);
		vWString vInsert;
		for(int i=0;i<names.size();i++){
			vWString types=vLinkInfo(i);
			for(int j=0;j<types.size();j++){
				EnumProcessUsage pu=GetEnumProcessUsage(types[j]);
				if((types[j][1]==L'?')||(types[j][1]==L'_')){
					// 110602 added
					if(!GetMatchingLink(names[i],pu,0).isNull()){
						continue; // skip existing links with maxOccurs=1
					}				
				}

				WString s=names[i]+atr_Link;
				if(pu!=ProcessUsage_Any){
					s+=WString::colon+ProcessUsageString(pu);
				}else{
				}

				vInsert.push_back(s);
				if(vInsert.size()>=nMax) 
					break;
			}
		}
		return vInsert;
	}
	/////////////////////////////////////////////////////////////////////////

	/**
	typesafe validator
	*/
	vWString JDFNode::GetInvalidLinks(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		vWString vElem;

		JDFResourceLinkPool linkPool=GetResourceLinkPool();
		vint foundSingleLinks;
		vint foundSingleLinks2;
		if(!linkPool.isNull()){ 
			vElement vLinks=linkPool.GetLinks();
			for(int i=vLinks.size()-1;i>=0;i--){
				JDFResourceLink rl=vLinks[i];
				if(!IsValidLink(level,rl,foundSingleLinks,foundSingleLinks2)){
					vElem.AppendUnique(rl.GetLinkedResourceName());
				}
			}
		}

		if(RequiredLevel(level)){
			vElem.AppendUnique(GetMissingLinks(nMax));
		}


		return vElem;

	}

	/////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	vWString JDFNode::GetInconsistentLinks(EnumValidationLevel level)const{
		EnumType typeNum=GetEnumType();
		vWString vs;
		JDFResourceLinkPool rlp=GetResourceLinkPool();
		vWString inLinks=rlp.GetInOutLinks(true,false).GetElementNameVector();
		vWString outLinks=rlp.GetInOutLinks(false,false).GetElementNameVector();

		switch(typeNum)	{
		case Type_Product:{
			if(RequiredLevel(level)){
				if(inLinks.hasString("ComponentLink")){
					if(!inLinks.hasString("BindingIntentLink")&&!inLinks.hasString("InsertingIntentLink")){
						vs.AppendUnique(elm_Component);
					}
				}				
			}
						  }

		case Type_ImageSetting:{
			if(RequiredLevel(level)){
				if(!(inLinks.hasString("ExposedMediaLink")^inLinks.hasString("MediaLink"))){
					vs.AppendUnique(elm_ExposedMedia);
					vs.AppendUnique(elm_Media);
				}				
			}else{
				if(inLinks.hasString("ExposedMediaLink")&&inLinks.hasString("MediaLink")){
					vs.AppendUnique(elm_ExposedMedia);
					vs.AppendUnique(elm_Media);
				}				
			}
							   }

		case Type_LayoutElementProduction:{
			if(RequiredLevel(level)){
				if(!(outLinks.hasString("RunListLink")^outLinks.hasString("LayoutElementLink"))){
					vs.AppendUnique(elm_RunList);
					vs.AppendUnique(elm_LayoutElement);
				}				
			}else{
				if(outLinks.hasString("RunListLink")&&outLinks.hasString("LayoutElementLink")){
					vs.AppendUnique(elm_RunList);
					vs.AppendUnique(elm_LayoutElement);
				}				
			}
										  }


		}
		return vs;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////

	bool JDFNode::IsValidLink(EnumValidationLevel level, const JDFResourceLink & rl, vint& doneNameList,vint& doneIndexList)const{
		if(rl.isNull()) 
			return false;

		if(!rl.IsResourceLink())
			return false;

		if(!rl.IsInJDFNameSpace())
			return true;

		if(GetEnumType()==Type_Unknown) // this must be a private extension node
			return true;

		int nOccur=0;
		int iIndex;
		int namIndex;

		// loop over all potential occurrences
		while(42){
			namIndex=GetMatchingIndex(rl,iIndex,nOccur);

			// not found -> check whether this node is known yet
			if(namIndex<0){
				if(!HasAttribute(atr_Type)) 
					return true;
				if(GetEnumType()==Type_ProcessGroup) 
					return true;

				return false;
			}

			// loop over all completed occurrences with maxOccurs=1
			// if they have already been found, search for next occurrence
			bool bTryNext=false;
			int dns=doneNameList.size();

			for(int i=0;i<dns;i++){
				if((doneNameList[i]==namIndex)&&(doneIndexList[i]==iIndex)){
					nOccur++; // this one is gone, try next
					bTryNext=true;
					break; // 
				}
			}

			if(!bTryNext) // we got here and the link is potentially valid
				break; 
		}

		bool isValid=rl.IsValid(level);

		wchar_t card=vLinkInfo(namIndex)[iIndex][1];
		if(isValid&&( (card==L'_')||(card==L'?') ) ){
			doneNameList.push_back(namIndex);
			doneIndexList.push_back(iIndex);
		}

		return isValid;
	}

	/////////////////////////////////////////////////////////////////////////

	JDFResourceLink JDFNode::GetMatchingLink(const WString& resName, EnumProcessUsage processUsage,int pos)const{
		vElement vE=GetMatchingLinks(resName,true,processUsage);
		if(vE.size()>pos)
			return vE[pos];
		return JDFResourceLink();
	}

	/////////////////////////////////////////////////////////////////////////

	int JDFNode::NumMatchingLinks(const WString& resName, bool bLink, EnumProcessUsage processUsage)const{
		return GetMatchingLinks(resName,bLink,processUsage).size();
	};

	/////////////////////////////////////////////////////////////////////////

	JDFResource JDFNode::GetMatchingResource(const WString& resName, EnumProcessUsage processUsage, const mAttribute & partMap, int pos)const{
		JDFResourceLink rl=GetMatchingLink(resName,processUsage,pos);
		if(rl.isNull()) 
			return JDFResource();
		if(!partMap.empty() && !rl.HasPartMap(partMap))
			return JDFResource();
		JDFResource r=rl.GetTarget();
		return r.GetPartition(partMap);

	}

	/////////////////////////////////////////////////////////////////////////

	vElement JDFNode::GetMatchingLinks(const WString& resName, bool bLink, EnumProcessUsage processUsage)const{
		vElement vE;

		JDFResourceLinkPool rlp=GetResourceLinkPool();
		if (rlp.isNull()) 
			return vE;

		WString linkNames=LinkNames();

		int namIndex=linkNames.PosOfToken(resName,WString::comma);

		if(namIndex<0){
			namIndex=linkNames.PosOfToken(WString::star,WString::comma);
			if(namIndex<0)
				return vE;
		}

		vWString vInfo=vLinkInfo(namIndex);
		if(processUsage>(int)ProcessUsage_Any){
			WString pu=ProcessUsageString(processUsage);
			for(int i=0;i<vInfo.size();i++){
				if(vInfo[i].endsWith(pu)){
					bool bInput=vInfo[i][0]==L'i';
					// 240502 RP bug fix by Komori
					vE=rlp.GetInOutLinks(bInput,bLink,resName,pu);
					break;
				}
			}
		}else{
			if(processUsage==ProcessUsage_AnyInput){
				vE=rlp.GetInOutLinks(true,bLink,resName);
				// 170205 RP remove internal pipes from all inputs
				// ideally we would check if they are connected, but this is a sufficient 98% solution
				if(bLink){
					for(int i=vE.size()-1;i>=0;i--){
						JDFResourceLink rl=vE[i];
						if(rl.GetPipeProtocol()==sInternal){
							vE.erase(vE.begin()+i);
						}
					}
				}
			}else if(processUsage==ProcessUsage_AnyOutput){
				vE=rlp.GetInOutLinks(false,bLink,resName);
				int vEsize = vE.empty() ? 0 : vE.size();
				// 170205 RP remove internal pipes from all outputs
				// ideally we would check if they are connected, but this is a sufficient 98% solution
				if(bLink){
					for(int i = vEsize-1; i >= 0; i--)
					{
						JDFResourceLink rl = (JDFResourceLink)vE.elementAt(i);
						if(rl.GetPipeProtocol().equals("Internal"))
						{
							vE.remove(i);
						}
					}
				}
				//}

				///////////////////////////// old version ///////////////////////////////////
				//}else if(processUsage==ProcessUsage_AnyOutput){
				//	vE=rlp.GetInOutLinks(false,bLink,resName);
				//	// 170205 RP remove internal pipes from all outputs
				//	// ideally we would check if they are connected, but this is a sufficient 98% solution
				//	if(bLink){
				//		for(int i=vE.size()-1;i>=0;i--){
				//			JDFResourceLink rl=vE[i];
				//			if(rl.GetPipeProtocol()==sInternal){
				//				vE.erase(vE.begin()+i);
				//			}
				//		}
				//	}
			}else{
				vE=rlp.GetInOutLinks(true,bLink,resName);
				vE.AppendUnique(rlp.GetInOutLinks(false,bLink,resName));
			}
		}

		return vE;
	}

	/////////////////////////////////////////////////////////////////////////

	JDFNode::EnumProcessUsage JDFNode::GetEnumProcessUsage(const WString&info, int i)const{
		WString iToken=info.Token(i,WString::blank);
		if(iToken.empty())
			return ProcessUsage_Any;

		if(iToken.size()>2){
			WString pu=iToken.substr(2);
			int index=ProcessUsageString().PosOfToken(pu,WString::comma);
			if(index>0){
				return EnumProcessUsage(index);
			}
		}
		if(iToken[0]==L'i'){
			return ProcessUsage_AnyInput;
		}else if(iToken[0]==L'o'){
			return ProcessUsage_AnyOutput;
		}else{
			throw JDFException(L"JDFNode:GetEnumProcessUsage:: bad input: "+info);
		}

		// make the compiler happy
		return ProcessUsage_Any;


	}

	/////////////////////////////////////////////////////////////////////////

	int JDFNode::GetMatchingIndex(const JDFResourceLink & rl, int &iIndex, int nOccur)const{
		iIndex=-1;
		if(rl.throwNull()) 
			return -1;

		// 311002 RP added nOccur for looping over combined nodes
		// TBD evaluate CombinedProcessIndex when generating nOccur
		WString linkNames=LinkNames();
		int	namIndex=linkNames.PosOfToken(rl.GetLocalName().leftStr(-4),WString::comma);

		// 120802 rp add check for *
		if(namIndex<0) {
			namIndex=linkNames.PosOfToken(WString::star,WString::comma);
		}

		if(namIndex<0) {
			return -1;
		}

		vWString vIndex=vLinkInfo(namIndex);
		int iLoop=0;
		for(int i=0;i<vIndex.size();i++){
			WString typ=vIndex[i];
			if(!rl.ValidUsage())
				continue;
			if(typ[0]==L'i'&&rl.GetUsage()!=JDFResourceLink::Usage_Input)
				continue;
			if(typ[0]==L'o'&&rl.GetUsage()!=JDFResourceLink::Usage_Output)
				continue;
			if(typ.size()>2) { // processusage is specified
				if (typ.rightStr(-2)!=rl.GetProcessUsage()){
					continue;
				}
			}else{  // no processusage is specified
				if(rl.HasAttribute(atr_ProcessUsage)){ 
					continue;
				}

			}
			if(iLoop++<nOccur)
				continue;
			// match!
			iIndex=i;
			return namIndex;
		}
		return -1;
	}

	/////////////////////////////////////////////////////////////////////////

	vWString JDFNode::GetMissingLinks(int nMax)const{
		return GetMissingLinkVector(nMax);
	};

	//////////////////////////////////////////////////////////////////////

	vWString JDFNode::GetUnknownLinks(bool bIgnorePrivate,int nMax)const{
		return GetUnknownLinkVector(bIgnorePrivate ?WString(L" :JDF").Tokenize(WString::colon):vWString(),nMax);
	};


	//////////////////////////////////////////////////////////////////////

	vElement JDFNode::GetLinkedResources(const mAttribute &mResAtt, bool bFollowRefs)const{
		vElement vLinkedResources=GetResourceLinkPool().GetLinkedResources(WString::emptyStr,mAttribute::emptyMap,mResAtt,bFollowRefs);

		vLinkedResources.AppendUnique(GetAuditPool().GetLinkedResources(mResAtt,bFollowRefs));

		vLinkedResources.AppendUnique(GetCustomerInfo().GetLinkedResources(mResAtt,bFollowRefs));

		vLinkedResources.AppendUnique(GetNodeInfo().GetLinkedResources(mResAtt,bFollowRefs));	
		vLinkedResources.AppendUnique(GetAncestorPool().GetLinkedResources(mResAtt,bFollowRefs));	
		return vLinkedResources;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFNode::RemoveMatchingLink(const WString& resName, EnumProcessUsage processUsage,  bool bRemoveResource, int pos){
		JDFResourceLink l=GetMatchingLink(resName,processUsage,pos);
		if(l.isNull()) 
			return false;

		if(bRemoveResource){
			JDFResource r=l.GetLinkRoot();
			if(r.GetLinks().size()<=1) // 1 is this
				r.DeleteNode();
		}
		l.DeleteNode();
		return true;
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFNode::RemoveMatchingLinks(const WString& resName, EnumProcessUsage processUsage, bool bRemoveResource){
		vElement v=GetMatchingLinks(resName,true,processUsage);
		for(int i=0;i<v.size();i++){
			if(bRemoveResource){
				JDFResource r=JDFResourceLink(v[i]).GetLinkRoot();
				// only remove if not linked from elsewhere
				if(r.GetLinks().size()<=1) // 1 is this
					r.DeleteNode();
			}
			v[i].DeleteNode();
		}
		return v.size()>0;
	}

	//////////////////////////////////////////////////////////////////////


	vWString JDFNode::GetMatchType(const WString& resName, EnumProcessUsage processUsage){
		vWString vRet;

		WString linkNames=LinkNames();
		int namIndex=linkNames.PosOfToken(resName,WString::comma);
		if(namIndex<0) 
			namIndex=linkNames.PosOfToken(WString::star,WString::comma);

		if(namIndex<0) { 
			throw JDFException(L"JDFNode::GetMatchType invalid resName: "+resName);
		}
		vWString vInfo=vLinkInfo(namIndex);

		WString pu=ProcessUsageString(processUsage);

		if(processUsage==ProcessUsage_Any)
			return vInfo;

		for(int i=0;i<vInfo.size();i++){
			if(processUsage>(int)ProcessUsage_Any){
				if(vInfo[i].endsWith(pu)){
					vRet.push_back(vInfo[i]);
				}
			}else{
				if((processUsage==ProcessUsage_AnyInput)&&(vInfo[i][0]==L'i')){
					vRet.push_back(vInfo[i]);
				}else if((processUsage==ProcessUsage_AnyOutput)&&(vInfo[i][0]==L'o')){
					vRet.push_back(vInfo[i]);
				}

			}
		}	
		return vRet;
	}
	//////////////////////////////////////////////////////////////////////

	JDFResource JDFNode::AppendMatchingResource(const WString& resName, EnumProcessUsage processUsage, JDFNode resourceRoot){
		vWString vtyp=GetMatchType(resName,processUsage);
		if(vtyp.empty())
		{
			//throw JDFException(L"JDFNode::AppendMatchingResource invalid type for"+resName);
			bool bInput=!(processUsage==ProcessUsage_AnyOutput);
			JDFResource r=AddResource(resName, JDFResource::Class_Unknown, bInput, resourceRoot, true, WString::emptyStr,JDFResource::DefJDFResource);
			JDFResourceLink rl=getLink(r,JDFResourceLink::Usage_Unknown);
			if(processUsage > ProcessUsage_Any)
			{
				rl.SetProcessUsage(JDFNode::ProcessUsageString(processUsage));
			}
			return r;
		}
		int nFound=0;
		WString foundTyp;
		bool foundMulti=false;
		int iInputFound=0; // 1 is in, 2 is out
		for(int i=0;i<vtyp.size();i++){
			WString typ=vtyp[i];
			bool bInput=typ[0]==L'i';

			if((typ[1]==L'?')||(typ[1]==L'_')){
				if (NumMatchingLinks(resName,false,processUsage)>nFound){
					nFound++;
					continue;
				}
			}
			if (foundTyp.empty())
			{
				foundTyp=typ;
				iInputFound=bInput ? 1 : 2; 
			}
			else if(typ!=foundTyp)
			{
				foundMulti=true;
				if((bInput ? 1 : 2) != iInputFound){
					iInputFound=0; // we could have either in or out - cannot link
					break;
				}
			}

		}
		if (foundTyp.empty()){
			// should only get here it the link alreay exists
			throw JDFException(L"JDFNode::AppendMatchingResource already exists");
		}
		JDFResource r=AddResource(resName,JDFResource::Class_Unknown,true,resourceRoot,false);
		JDFFactory f(r);
		f.GetRef().init();

		if(iInputFound>0){
			JDFResourceLink rl=LinkResource(r,iInputFound==1);
			if(!foundMulti &&  foundTyp.size()>2)
				rl.SetProcessUsage(foundTyp.rightStr(-2));
		}
		return r;
	}

	/////////////////////////////////////////////////////////////////////

	JDFResourceLink JDFNode::LinkMatchingResource(const JDFResource & resource,EnumProcessUsage processUsage, const mAttribute & partMap){
		JDFResourceLink rl;
		WString resName=resource.GetLocalName();

		vWString vtyp=GetMatchType(resName,processUsage);
		for(int i=0;i<vtyp.size();i++){
			WString typ=vtyp[i];
			if((typ[1]==L'?')||(typ[1]==L'_')){
				if (NumMatchingLinks(resName,false,processUsage)>0){ 
					continue; // not this one...
				}
			}
			rl=LinkResource(resource,typ[0]==L'i',false);
			if(typ.size()>2)
				rl.SetProcessUsage(typ.rightStr(-2));
			rl.SetPartMap(partMap);
			return rl;
		}
		// should only get here it the link alreay exists
		throw JDFException(L"JDFNode::LinkMatchingResource already exists");
		// make compiler happy
		return JDFResourceLink();
	}

	//////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////

	void JDFNode::RemoveNode( bool bLeaveSubmit){
		if(bLeaveSubmit){
			WString id=GetID();
			RemoveAttributes();
			SetAttribute(atr_ID,id);
			SetStatus(Status_Spawned);
			RemoveChildren();
		}else{
			DeleteNode();
		}
	}

	//////////////////////////////////////////////////////////////////////

	JDFNode JDFNode::MergeNode(JDFNode e, bool bDelete){

		// merge nodes in a way that no duplicate elements are created
		// attention - this kills pools....

		if(throwNull()) return KElement();
		vElement v=e.GetChildElementVector(); 
		for(int i=0;i<v.size();i++){ 
			KElement m=v[i];
			WString name=m.GetNodeName();
			KElement mHere;
			if((name==elm_NodeInfo)||(name==elm_CustomerInfo)||(name==elm_ResourcePool)||(name==elm_ResourceLinkPool)||(name==elm_AncestorPool)||(name==elm_AuditPool)){
				mHere=GetElement(m.GetNodeName());
			}
			if(mHere.isNull()){
				if(bDelete){
					MoveElement(m);
				}else{
					CopyElement(m);
				}
			}else{
				mHere.MergeElement(m,bDelete);
				if(bDelete){
					m.DeleteNode();
				}
			}
		}
		SetText(e.GetText());
		SetAttributes(e);
		return *this;	
	}



	//////////////////////////////////////////////////////////////////////




	//////////////////////////////////////////////////////////////////////
	WString JDFNode::GetIDPrefix() const {
		const static WString n=L"n";
		return n;
	}

	//////////////////////////////////////////////////////////////////////

	vWString JDFNode::GetHRefs(const vWString& vDoneRefs, bool bRecurse)const{
		vWString v1=vDoneRefs;
		v1=GetResourcePool().GetHRefs(v1,bRecurse);
		v1=GetResourceLinkPool().GetHRefs(v1,bRecurse);
		v1=GetCustomerInfo().GetHRefs(v1,bRecurse);
		v1=GetNodeInfo().GetHRefs(v1,bRecurse);
		v1=GetAncestorPool().GetHRefs(v1,bRecurse);
		if(!bRecurse) 
			return v1;
		vElement vNodes =GetvJDFNode(WString::emptyStr,Activation_Unknown,true);
		for(int i=0;i<vNodes.size();i++)
			v1=JDFNode(vNodes.at(i)).GetHRefs(v1,bRecurse);
		return v1;

	}
	//////////////////////////////////////////////////////////////////////

	VoidSet* JDFNode::GetAllRefs(VoidSet* vDoneRefs, bool bRecurse)const{
		if(bRecurse)
			GetResourcePool().GetAllRefs(vDoneRefs,bRecurse);
		GetResourceLinkPool().GetAllRefs(vDoneRefs,bRecurse);
		GetCustomerInfo().GetAllRefs(vDoneRefs,bRecurse);
		GetNodeInfo().GetAllRefs(vDoneRefs,bRecurse);
		GetAncestorPool().GetAllRefs(vDoneRefs,bRecurse);

		vElement vNodes =GetvJDFNode(WString::emptyStr,Activation_Unknown,true);
		for(int i=0;i<vNodes.size();i++)
			JDFNode(vNodes.at(i)).GetAllRefs(vDoneRefs,bRecurse);
		return vDoneRefs;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	/**
	* searches for the first attribute occurrence in the ancestor elements
	*
	* @param WString attrib: the attribute name
	* @param WString nameSpaceURI: the XML-namespace
	* @param WString def: the default if it does not exist
	* @since 180502 
	* @return WString: value of attribute found, empty string if not available
	*/
	WString JDFNode::GetAncestorAttribute(const WString & attrib,const WString& nameSpaceURI,const WString & def)const{
		// search the inherited nodes first
		WString att=GetInheritedAttribute(attrib,nameSpaceURI,WString::quote);
		if(att==WString::quote){	
			// not in the inherited nodes, check the root node's AncestorPool
			att= GetJDFRoot().GetAncestorPool().GetAncestorAttribute(attrib,nameSpaceURI,def);
		}
		return att;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////
	/**
	* searches for the first attribute occurrence in the ancestor elements
	*
	* @param WString attrib: the attribute name
	* @param WString nameSpaceURI: the XML-namespace
	* @since 180502 
	* @return WString: value of attribute found, empty string if not available
	*/
	JDFElement JDFNode::GetAncestorElement(const WString & element,const WString& nameSpaceURI)const{
		// search the inherited nodes first
		KElement e=GetInheritedElement(element,nameSpaceURI);
		if(e.isNull()){
			// not in the inherited nodes, check the root node's AncestorPool
			e=GetJDFRoot().GetAncestorPool().GetAncestorElement(element,nameSpaceURI);
		}
		return e;
	}


	//////////////////////////////////////////////////////////////////////////////////////////////
	/**
	* searches for the first attribute occurrence in the ancestor elements subelements
	*
	* @param WString attrib: the attribute name
	* @param WString nameSpaceURI: the XML-namespace
	* @param WString def: the default if it does not exist
	* @since 180502 
	* @return WString: value of attribute found, empty string if not available
	*/
	WString JDFNode::GetAncestorElementAttribute(const WString & element,const WString & attrib,const WString& nameSpaceURI,const WString & def)const{
		JDFNode n=*this;
		while(!n.isNull()){
			KElement e= n.GetElement(element, nameSpaceURI);
			if((!e.isNull())&&(e.HasAttribute(attrib,nameSpaceURI)))
				return e.GetAttribute(attrib,nameSpaceURI);
			n=n.GetParentJDFNode();
		}

		// not in the inherited nodes, check the root node's AncestorPool
		return GetJDFRoot().GetAncestorPool().GetAncestorElementAttribute(element,attrib,nameSpaceURI,def);
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	/**
	* true if a non default attribute occurrence in the parent nodes and then the ancestor elements subelements of the root ancestorpool exists
	*
	* @param WString attrib: the attribute name
	* @param WString nameSpaceURI: the XML-namespace
	* @param WString def: the default if it does not exist
	* @since 180502 
	* @return bool: true if the attribute exists
	*/
	bool JDFNode::HasAncestorElementAttribute(const WString & element,const WString & attrib,const WString& nameSpaceURI)const{
		return GetAncestorElementAttribute(element,attrib,nameSpaceURI,WString::quote).compare(WString::quote)!=0;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////
	/**
	* true id a non default occurrence in the ancestor elements exists
	*
	* @param WString attrib: the attribute name
	* @param WString nameSpaceURI: the XML-namespace
	* @param WString def: the default if it does not exist
	* @since 180502 
	* @return WString: value of attribute found, empty string if not available
	*/
	bool JDFNode::HasAncestorAttribute(const WString & attrib,const WString& nameSpaceURI)const{
		return GetAncestorAttribute(attrib,nameSpaceURI,WString::quote).compare(WString::quote)!=0;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////
	/**
	* true id a non default occurrence in the ancestor elements exists
	*
	* @param WString attrib: the attribute name
	* @param WString nameSpaceURI: the XML-namespace
	* @param int iSkip number of elements to skip
	* @since 180502 
	* @return WString: value of attribute found, empty string if not available
	*/
	bool JDFNode::HasAncestorElement(const WString & element,const WString& nameSpaceURI)const{
		return !GetAncestorElement(element,nameSpaceURI).isNull();
	}

	//////////////////////////////////////////////////////////////////////////////////////////////

	JDFResource JDFNode::AddParameter(const WString &  name, bool bInput, JDFNode resRoot,bool bLink, const WString & nameSpaceURI, const JDFResource & toReplace){
		return AddResource(name,JDFResource::Class_Parameter,bInput,resRoot,bLink, nameSpaceURI, toReplace);
	};

	//////////////////////////////////////////////////////////////////////////////////////////////
	JDFResource JDFNode::AddConsumable(const WString &  name, bool bInput, JDFNode resRoot,bool bLink, const WString & nameSpaceURI, const JDFResource & toReplace){
		return AddResource(name,JDFResource::Class_Consumable,bInput,resRoot,bLink, nameSpaceURI, toReplace);
	};

	//////////////////////////////////////////////////////////////////////////////////////////////
	JDFResource JDFNode::AddImplementation(const WString &  name, bool bInput, JDFNode resRoot,bool bLink, const WString & nameSpaceURI, const JDFResource & toReplace){
		return AddResource(name,JDFResource::Class_Implementation,bInput,resRoot,bLink, nameSpaceURI, toReplace);
	};

	//////////////////////////////////////////////////////////////////////////////////////////////
	JDFResource JDFNode::AddHandling(const WString &  name, bool bInput, JDFNode resRoot,bool bLink, const WString & nameSpaceURI, const JDFResource & toReplace){
		return AddResource(name,JDFResource::Class_Handling,bInput,resRoot,bLink, nameSpaceURI, toReplace);
	};


	//////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFResourceAudit JDFNode::CloneResourceToModify(const JDFResourceLink& resLink){

		JDFResourceAudit resourceAudit;

		JDFResource r       = resLink.GetLinkRoot();
		JDFResourcePool p   = r.GetParentJDF().GetResourcePool();
		JDFResource oldCopy = (JDFResource) p.CopyElement(r,KElement::DefKElement);

		if (!oldCopy.isNull())
		{
			oldCopy.SetLocked(true);
			WString newID = r.NewModifiedID();
			oldCopy.SetID(newID);
			resourceAudit = PrepareToModifyLink(resLink);
			JDFResourceLink resLinkAudit = (JDFResourceLink) resourceAudit.CopyElement(resLink,KElement::DefKElement);

			if (!resLinkAudit.isNull())
			{
				resLinkAudit.SetrRef(newID);
			}
		}

		return resourceAudit;
	}

	//////////////////////////////////////////////////////////////////////

	JDFResourceAudit JDFNode::PrepareToModifyLink(const JDFResourceLink& resLink){

		JDFAuditPool ap=GetCreateAuditPool();
		JDFResourceAudit resourceAudit=ap.AddResourceAudit();
		resourceAudit.SetContentsModified(false);
		JDFResourceLink resLinkAudit=resourceAudit.CopyElement(resLink);

		return resourceAudit;
	}

	///////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////
	void JDFNode::SetSpawnParent(const JDFNode& parent, const WString& url,const vmAttribute& vSpawnParts,bool bCopyNodeInfo, bool bCopyCustomerInfo, bool bCopyComments){
		vWString vs=parent.GetAncestorIDs();
		JDFAncestorPool ancestorPool=parent.GetJDFRoot().GetAncestorPool();
		WString lastAncestorID;

		if(!(parent==*this)){
			RemoveChild(elm_AncestorPool); // just in case
			if(parent.GetJDFRoot().HasChildElement(elm_AncestorPool))
			{
				ancestorPool=CopyElement(ancestorPool);
				int numAncestors=ancestorPool.NumChildElements(elm_Ancestor);
				if(numAncestors>0){
					lastAncestorID=ancestorPool.GetAncestor(numAncestors-1).GetNodeID();
				}
			}
		}
		ancestorPool=GetCreateAncestorPool();
		ancestorPool.SetPartMapVector(vSpawnParts);

		// avoid double counting of this node's root element in case of partitioned spawning
		int startAncestorLoop=0;
		if((vs.size()>0)&&(vs[0]==lastAncestorID)){
			startAncestorLoop=1;
		}

		// 010702 RP reversed in GetAncestorIDs: the last in the list is the actual 
		for(int i=startAncestorLoop;i<vs.size();i++){				
			JDFAncestor ancestor=ancestorPool.AppendAncestor();
			ancestor.SetNodeID(vs[i]);
			if(i==0){ // first in list is the parent
				if(!url.empty()) 
					ancestor.SetFileName(url);
			}
		}
		SetJobID(parent.GetJobID(true));

		// 180502 RP added line
		ancestorPool.CopyNodeData(parent, bCopyNodeInfo, bCopyCustomerInfo, bCopyComments);
	}

	//////////////////////////////////////////////////////////////////////

	vWString JDFNode::GetParentIds(){
		vWString vs;
		if ( !GetAncestorPool().isNull() )
		{
			vElement v=GetAncestorPool().GetPoolChildren();
			for(int i=0;i<v.size();i++) {
				vs.push_back(JDFAncestor(v[i]).GetNodeID());
			}
		}
		return vs;
	}



	//////////////////////////////////////////////////////////////////////

	bool JDFNode::MergeJDF(JDFNode toMerge, const WString& urlMerge, EnumCleanUpMerge cleanPolicy, JDFResource::EnumAmountMerge amountPolicy){
		JDFMerge merge = JDFMerge(*this);
		JDFDoc docOut = merge.mergeJDF(toMerge, urlMerge, cleanPolicy, amountPolicy);
		JDFNode n = docOut.GetJDFRoot();
		if (!n.isNull())
			return true;
		else 
			return false;
	}

	//////////////////////////////////////////////////////////////////////

	void JDFNode::CleanUpMerge(EnumCleanUpMerge cleanPolicy, const WString& spawnID, bool bRecurse){
		if(cleanPolicy!=CleanUpMerge_None){
			if(bRecurse){
				vElement v=GetvJDFNode();
				for(int i=v.size();i>=0;i--){
					JDFNode(v.at(i)).CleanUpMerge(cleanPolicy,spawnID,false);
				}

			}else{
				GetAuditPool().CleanUpMerge(cleanPolicy,spawnID);
			}
		}
	}
	//////////////////////////////////////////////////////////////////////

	void JDFNode::MergeComments(JDFNode toMerge){
		vElement v=GetChildElementVector(elm_Comment);
		vElement vToMerge=toMerge.GetChildElementVector(elm_Comment);
		unsigned int siz=vToMerge.size(); // size prior to appending
		vToMerge.AppendUnique(v);
		for(int i=siz;i<vToMerge.size();i++){
			toMerge.MoveElement(vToMerge[i]);
		}
	}

	////////////////////////////////////////////////////////////////////////////////

	void JDFNode::MergeAuditPool(JDFNode toMerge){
		// merge audit pool
		JDFAuditPool overWriteAuditPool = GetAuditPool();
		JDFAuditPool toMergeAuditPool = toMerge.GetAuditPool();

		// the node that is overwritten has an audit pool that must be merged
		if (!overWriteAuditPool.isNull()){
			// the overwriting node node is empty, just copy the previous pool
			if (toMergeAuditPool.isNull())	{
				toMerge.CopyElement (overWriteAuditPool);
			}else{
				// must merge the old node into the overwriting node
				overWriteAuditPool.AppendUnique (toMergeAuditPool);
				toMergeAuditPool.ReplaceElement (overWriteAuditPool);
			}
		}

	}
	//////////////////////////////////////////////////////////////////////

	void JDFNode::MergeMainPools(JDFNode toMerge, JDFNode overWriteParent, const vmAttribute& parts, const vWString& vsRW, const WString& spawnID, const WString& preSpawn, const WString& urlMerge, bool bSnafu){
		// add the merged audit
		JDFMerged mergeAudit=toMerge.GetCreateAuditPool().AddMerged(toMerge,vsRW,WString::emptyStr,parts);
		if(!urlMerge.empty()) {
			WString url=urlMerge;
			// 300802 RP added check for preexisting file prefix
			if(url.indexOf(L"://")==-1)
				url=L"File://"+url;
			mergeAudit.SetURL(url);
		}
		mergeAudit.SetMergeID(spawnID);

		// if something went wrong, also add a notification
		if(bSnafu){
			JDFNotification notification=toMerge.GetCreateAuditPool().AddNotification(JDFNotification::Class_Error,L"JDFNode::MergeJDF",parts);
			notification.SetType(L"Error");
			notification.AppendComment().AppendText("The Ancestor list was incorrectly ordered for merging in the spawned JDF");
		}


		// merge StatusPool and AncestorPool
		toMerge.RemoveChild(elm_AncestorPool);
		if (parts.size() >= 1){
			MergeStatusPool(toMerge,parts);
			// handle ancestor pools only in partitioned spawns
			JDFAncestorPool ancPool=overWriteParent.GetAncestorPool();
			if(!ancPool.isNull()){
				toMerge.CopyElement(ancPool);
			}
		}

		// cleanup
		WString jid=overWriteParent.GetJobID(true);
		if(toMerge.GetAttribute(atr_JobID)==jid)
			toMerge.RemoveAttribute(atr_JobID);

		if(preSpawn.empty()){
			toMerge.RemoveAttribute(atr_SpawnID);
		}else{
			toMerge.SetSpawnID(preSpawn);
		}
	}

	//////////////////////////////////////////////////////////////////////

	void JDFNode::MergeStatusPool(JDFNode toMerge, const vmAttribute &parts){
		if (toMerge.HasChildElement(elm_StatusPool) || HasChildElement(elm_StatusPool))
		{
			JDFStatusPool overWriteStatusPool = GetCreateStatusPool();
			if (GetStatus() != JDFNode::Status_Pool)
			{
				overWriteStatusPool.SetStatus(GetStatus());
				SetStatus(JDFNode::Status_Pool);
			}

			JDFStatusPool toMergeStatusPool = toMerge.GetStatusPool();
			if (toMerge.GetStatus() == JDFNode::Status_Pool)
			{
				for (int i = 0; i < parts.size(); i++){
					int j;
					// clean up the pool to overwrite
					vElement vpso=overWriteStatusPool.GetMatchingPartStatusVector(parts[i]);
					for(j=0;j<vpso.size();j++){
						vpso[j].DeleteNode(); // remove all matching partstatus elements in case they were expanded in the spawned node
					}

					// extract data from spawned node
					vElement vps=toMergeStatusPool.GetMatchingPartStatusVector(parts[i]);
					for(j=0;j<vps.size();j++){
						JDFPartStatus ps=vps[j];
						mAttribute m=ps.GetPartMap();
						overWriteStatusPool.SetStatus(m,ps.GetStatus(),ps.GetStatusDetails());
					}
					// 100305 RP the following lines cause problems with nested spawn and therefore are commented out
					//					JDFPartStatus ps=overWriteStatusPool.GetPartStatus(parts[i]);
					// just in case someone updated detailed partstatus elements
					//					if(ps.GetStatus()==ps.Status_Spawned)
					//						ps.DeleteNode();
				}
				toMergeStatusPool.ReplaceElement(overWriteStatusPool);
			}
			else
			{
				// this part of the program will probably never be executed, but...
				for (int i = 0; i < parts.size(); i++)
					overWriteStatusPool.SetStatus(parts[i],toMerge.GetStatus());
				if(!toMergeStatusPool.isNull())
					toMergeStatusPool.DeleteNode();
				toMerge.SetStatus(JDFNode::Status_Pool);
				toMerge.MoveElement(overWriteStatusPool);
			}
		}
	}
	//////////////////////////////////////////////////////////////////////


	void JDFNode::MergeResourceLinkPool(JDFNode toMerge, const vmAttribute &parts){
		vElement links=toMerge.GetResourceLinkPool().GetLinks();
		for(int i=0;i<links.size();i++){
			JDFResourceLink rl=links[i];
			rl.ExpandTarget();
		}

		if(!parts.empty()){
			JDFResourceLinkPool overWriteRLP=GetResourceLinkPool();
			JDFResourceLinkPool toMergeRLP=toMerge.GetResourceLinkPool();
			vElement overWriteLinks=overWriteRLP.GetPoolChildren();
			vElement toMergeLinks=toMergeRLP.GetPoolChildren();
			for(int rl=0;rl<toMergeLinks.size();rl++){
				JDFResourceLink overWriteLink;
				JDFResourceLink toMergeLink=toMergeLinks[rl];
				WString rRef=toMergeLink.GetAttribute(atr_rRef);
				for(int k=0;k<overWriteLinks.size();k++){
					if(overWriteLinks[k].GetAttribute(atr_rRef)==rRef){
						overWriteLink=overWriteLinks[k];
						overWriteLinks.erase(overWriteLinks.begin()+k);
						break;
					}

				}
				if(!overWriteLink.isNull()){
					if(toMergeLink.HasChildElement(elm_Part)){
						for(int i=0;i<parts.size();i++){
							bool hasAP=overWriteLink.HasChildElement(elm_AmountPool);

							vElement vPartAmounts=toMergeLink.GetAmountPool().GetMatchingPartAmountVector(parts[i]);
							if(vPartAmounts.empty()){
								mAttribute mpaMap=toMergeLink.GetAttributeMap();
								// remove generic link stuff
								mpaMap.erase(atr_CombinedProcessIndex);
								mpaMap.erase(atr_CombinedProcessType);
								//tbd						opa.RemoveAttribute(atr_PipePartIDKeys);
								mpaMap.erase(atr_PipeProtocol);
								mpaMap.erase(atr_ProcessUsage);
								mpaMap.erase(atr_rRef);
								mpaMap.erase(atr_rSubRef);
								mpaMap.erase(atr_Usage);
								// dont add ap if mpa link only has copies of the original link
								if(!hasAP){
									mAttribute opaMap=overWriteLink.GetAttributeMap();
									if(opaMap.SubMap(mpaMap)){
										mpaMap.clear();
									}
								}
								// only add something if partmap contains real information
								if(!mpaMap.empty()&&(mpaMap!=parts[i])){
									JDFPartAmount opa=overWriteLink.GetCreateAmountPool().GetCreatePartAmount(parts[i]);
									opa.SetAttributes(mpaMap);
									overWriteLink.RemoveAttributes(mpaMap.GetKeys());
								}							
							}else{
								// loop over all fitting part amounts and blast them in
								for(int j=0;j<vPartAmounts.size();j++){
									JDFPartAmount mpa=vPartAmounts[j];								
									mAttribute amountMap=mpa.GetAttributeMap();
									mAttribute partMap=mpa.GetPartMap();
									JDFPartAmount opa=overWriteLink.GetCreateAmountPool().GetCreatePartAmount(partMap);
									opa.SetAttributes(amountMap);
									overWriteLink.RemoveAttributes(amountMap.GetKeys());								
								}
							}
							// nothing has changed --> leave as is
						}
					}else{
						// blast the spawned link into the overWritePool completely
						overWriteLink.ReplaceElement(toMergeLink);
					}
				}
			}
			toMergeRLP.DeleteNode();
			toMerge.CopyElement(overWriteRLP);
		}
	}

	//////////////////////////////////////////////////////////////////////

	void JDFNode::MergeLocalLinks(JDFNode toMerge, const vmAttribute& parts){	
		vElement vn=GetvJDFNode();
		int siz = vn.size();
		// merge local (internal) partitioned resource links
		for(int nod=0;nod<siz;nod++){
			JDFNode overwriteLocalNode=vn.at(nod);
			JDFNode toMergeLocalNode=toMerge.GetChildJDFNode(overwriteLocalNode.GetID(),false);
			overwriteLocalNode.MergeResourceLinkPool(toMergeLocalNode,parts);
			if(toMergeLocalNode.GetEnumVersion(true)>=JDFNode::Version_1_3){
				JDFNode::EnumStatus stat=toMergeLocalNode.GetStatus();
				if(stat!=JDFNode::Status_Part&&stat!=JDFNode::Status_Pool&&(parts.size()>0)){
					toMergeLocalNode.SetPartStatus(parts,stat,toMergeLocalNode.GetStatusDetails());
				}
			}
		}
	}
	//////////////////////////////////////////////////////////////////////

	void JDFNode::MergeLocalNodes(JDFNode toMerge, const vmAttribute& parts, const vWString& previousMergeIDs,
		const WString& spawnID, JDFResource::EnumAmountMerge amountPolicy){	
			vElement vn=GetvJDFNode();
			// merge local (internal) partitioned resources
			for(int nod=0;nod<vn.size();nod++){
				JDFNode overwriteLocalNode=vn.at(nod);
				JDFNode toMergeLocalNode=toMerge.GetChildJDFNode(overwriteLocalNode.GetID(),false);

				JDFResourcePool poolOverWrite = overwriteLocalNode.GetResourcePool();
				JDFResourcePool poolToMerge = toMergeLocalNode.GetResourcePool();

				if (!poolOverWrite.isNull()) 
				{
					vElement resOverWrite = poolOverWrite.GetPoolChildren();

					for (int i = 0; i < resOverWrite.size(); i++)
					{
						JDFResource res1 = resOverWrite[i];
						WString resID=res1.GetID();
						JDFResource res2 =poolToMerge.GetResourceByID(resID);

						if (!res2.isNull())	{
							res2.MergeSpawnIDs(res1,previousMergeIDs);
							res1.MergePartition (res2, spawnID, amountPolicy,true);   // esp. deletes res2 from toMerge node
						}
						// copy resource from orig to spawned node
						poolToMerge.CopyElement(res1);
						res1 =poolToMerge.GetResourceByID(resID);
						vElement resLeafsSpawned=res1.GetNodesWithSpawnID(spawnID);
						for(int leaf=0;leaf<resLeafsSpawned.size();leaf++){
							JDFResource leafRes=resLeafsSpawned[leaf];
							leafRes.RemoveFromSpawnIDs(spawnID);
							vWString spawnIDs=leafRes.GetSpawnIDs(false);
							spawnIDs.RemoveStrings(previousMergeIDs);
							if(spawnIDs.empty()){
								leafRes.RemoveAttribute(atr_SpawnIDs);
								leafRes.RemoveAttribute(atr_SpawnStatus);
								leafRes.RemoveAttribute(atr_Locked);

							}else{
								leafRes.SetSpawnIDs(spawnIDs);
							}
						}	
					}
				}

				// retain all other elements of the original (non spawned) JDF Node if the spawn is partitioned
				if(toMerge.GetAncestorPool().IsPartitioned()){
					vElement localChildren=overwriteLocalNode.GetChildElementVector();
					int siz=localChildren.size();
					for(int i=0;i<siz;i++){
						JDFElement e=localChildren[i];
						if(e.isNull())
							continue;
						// skip all pools and retain the partitioned values they will be cleaned up later
						WString nodeName=e.GetLocalName();
						if(nodeName.endsWith(JDFElement::atr_Pool)){
							if(nodeName==JDFElement::elm_ResourceLinkPool)
								continue;
							if(nodeName==JDFElement::elm_ResourcePool)
								continue;
							if(nodeName==JDFElement::elm_AuditPool){
								overwriteLocalNode.MergeAuditPool(toMergeLocalNode);
								continue;
							}
							if(nodeName==JDFElement::elm_StatusPool){
								overwriteLocalNode.MergeStatusPool(toMergeLocalNode,parts);
								continue;
							}
							if(nodeName==JDFElement::elm_AncestorPool) // this should never happen
								continue;
						}
						// 041213 RP also skip all sub-JDF nodes!!!
						if(nodeName==JDFElement::elm_JDF)
							continue;
						//050708 RP special handling for comments
						if(nodeName==JDFElement::elm_Comment){
							overwriteLocalNode.MergeComments(toMergeLocalNode);
							continue;
						}
						toMergeLocalNode.RemoveChildren(nodeName);
						toMergeLocalNode.MoveElement(e);

						// repeat in case of multiple identical elements
						for(int j=i+1;j<siz;j++){
							if(localChildren.at(j).GetNodeName()==nodeName){
								toMergeLocalNode.MoveElement(localChildren.at(j));
								localChildren.at(j)=JDFElement();
							}
						}
					}
				}		
			}
	}
	////////////////////////////////////////////////////////////////////////////////////

	void JDFNode::CleanROResources(JDFNode toMerge, const vWString& previousMergeIDs, const vWString& vsRO, const WString& spawnID){

		for(int i=0;i<vsRO.size();i++){
			JDFResource newRes=toMerge.GetTargetResource(vsRO[i]);
			JDFResource oldRes=GetLinkRoot(vsRO[i]);
			if(oldRes.isNull()){ // also check in tree below
				oldRes=GetTargetResource(vsRO[i]);
				if(oldRes.isNull()) // also check in entire tree below root
					oldRes=GetJDFRoot().GetTargetResource(vsRO[i]);
			}
			if(oldRes.isNull())
				continue;

			// merge all potential new spawnIds from toMerge to this
			oldRes.MergeSpawnIDs(newRes,previousMergeIDs);
			vElement oldResLeafsSpawned=oldRes.GetNodesWithSpawnID(spawnID);
			for(int leaf=0;leaf<oldResLeafsSpawned.size();leaf++){
				JDFResource leafRes=oldResLeafsSpawned[leaf];
				//  handle multiple spawns (reference count of spawned audits!)
				leafRes.RemoveFromSpawnIDs(spawnID);

				if(!leafRes.HasAttribute(atr_SpawnIDs))
					leafRes.RemoveAttribute(atr_SpawnStatus);
			}

			if(newRes.GetParentJDF().GetID()!=oldRes.GetParentJDF().GetID()){
				// this has been copied from lower down up and MUST be deleted...
				newRes.DeleteNode();

			}else{

				// don't use a simple for because deleting a parent may invalidate later resources!
				vElement newResLeafsSpawned=newRes.GetNodesWithSpawnID(spawnID);
				// just in case: if no SpawnID exists assume the whole thing 
				if(newResLeafsSpawned.size()==0){
					newResLeafsSpawned.push_back(newRes);
				}
				while(newResLeafsSpawned.size()>0){
					// use the last because it is potentially the root...
					JDFResource leafRes=newResLeafsSpawned[newResLeafsSpawned.size()-1];
					bool bZappRoot=leafRes==newRes;
					leafRes.DeleteNode();
					// we killed the root, nothing can be left...
					if(bZappRoot)
						break;
					// regenerate the list
					newResLeafsSpawned=newRes.GetNodesWithSpawnID(spawnID);
				}
			}
		}
	}
	////////////////////////////////////////////////////////////////////////////////////

	void JDFNode::MergeRWResources(JDFNode toMerge, const vWString& previousMergeIDs, const vWString& vsRW, const WString& spawnID, JDFResource::EnumAmountMerge amountPolicy){
		for(int i=0;i<vsRW.size();i++){
			JDFResource oldRes=GetLinkRoot(vsRW[i]);
			if(oldRes.isNull()){ // also check in tree below
				oldRes=GetTargetResource(vsRW[i]);
				if(oldRes.isNull()) // also check in entire tree below the root
					oldRes=GetJDFRoot().GetTargetResource(vsRW[i]);
			}
			if(oldRes.isNull())
				continue;

			JDFResource newRes=toMerge.GetTargetResource(vsRW[i]);

			// merge all potential new spawnIds from this to toMerge before merging them
			oldRes.MergeSpawnIDs(newRes,previousMergeIDs);
			// do both, since some leaves may be RO
			newRes.MergeSpawnIDs(oldRes,previousMergeIDs);

			// merge the resource from the spawned node into the lower level resourcepool
			oldRes.MergePartition(newRes,spawnID,amountPolicy,false);

			vElement oldResLeafsSpawned=oldRes.GetNodesWithSpawnID(spawnID);
			for(int leaf=0;leaf<oldResLeafsSpawned.size();leaf++){
				JDFResource leafRes=oldResLeafsSpawned[leaf];
				leafRes.RemoveFromSpawnIDs(spawnID);
				KElement leafElem=leafRes;
				if(!leafElem.HasAttribute(atr_SpawnIDs)){
					leafRes.RemoveAttribute(atr_SpawnStatus);
					leafRes.RemoveAttribute(atr_Locked);
				}else{
					//					leafRes.SetSpawnStatus(JDFResource::SpawnStatus_SpawnedRO);
				}
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////////

	bool JDFNode::HasParent(JDFNode p){
		vWString vpa=p.GetAncestorIDs();
		vWString vParents=GetParentIds(); 
		vParents.push_back(GetID());
		if(vpa.size()==0) 
			return false;
		WString id=vpa[0];
		if(id.empty()) 
			throw JDFException(L"JDFNode::HasParent: no id???");
		for(int i=0;i<vParents.size();i++){
			if(id==vParents[i]) 
				return true;
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////

	int JDFNode::GetMinID()
	{
		// the previous algorithm did more harm than good!
		return 0;
	}

	//////////////////////////////////////////////////////////////////////
	int JDFNode::GetMaxJobPartId(const WString& idPrefix){
		vElement v=GetvJDFNode();
		int prefixSize=idPrefix.size();
		int iMax=-1;
		for(int i=0;i<v.size();i++){
			JDFNode e(v[i]);
			WString s=e.GetJobPartID();
			if(s.empty()||s.compare(0,prefixSize,idPrefix)) 
				continue;
			s=s.substr(prefixSize).trim();
			int pos=0;
			int len=s.size();

			while((pos<len)&&(s[pos]==L'0')){
				pos++;
			}
			// 300402 RP added
			if(pos)
				s=s.rightStr(-pos);
			if(s.empty()) 
				continue;
			iMax=max((int)s,iMax);
		}
		return iMax;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFNode::UnSpawn(const WString & spawnID){			
		JDFNode unspawned = JDFSpawn(*this).unSpawn(spawnID);
		if (!unspawned.isNull())
		{
			*this = unspawned;
			return true;
		}
		else
			return false;
	}	
	//////////////////////////////////////////////////////////////////////

	JDFNode JDFNode::AddJDFNode(const WString & typ){
		EnumType t=GetEnumType();
		if((t==Type_Unknown)||(t!=Type_Product)&&(t!=Type_ProcessGroup)){
			throw JDFException(L"JDFNode:AddProcessGroup adding ProcessGroup to invalid node type: Type="+GetType());
		}
		JDFNode p=AppendElement(elm_JDF);
		p.init(false,*this);
		if(!typ.empty())
			p.SetType(typ);

		return p;
	}

	//////////////////////////////////////////////////////////////////////

	JDFNode JDFNode::AddJDFNode(EnumType typ){
		JDFNode p=AddJDFNode(WString::emptyStr);
		p.SetEnumType(typ);
		return p;
	}

	//////////////////////////////////////////////////////////////////////

	JDFNode JDFNode::AddProcess(const WString & prodName){
		JDFNode p=AddJDFNode(prodName);	
		return p;
	}

	//////////////////////////////////////////////////////////////////////


	JDFNode JDFNode::AddProcessGroup(const vWString& tasks){
		JDFNode p=AddJDFNode(Type_ProcessGroup);
		p.SetEnumType(Type_ProcessGroup);
		if(!tasks.empty())
			p.SetTypes(tasks);
		return p;
	}
	///////////////////////////////////////////////////////////////
	JDFNode JDFNode::AddCombined(const vWString& tasks){
		JDFNode cNode=AddJDFNode(Type_Combined);
		if(!tasks.empty())
			cNode.SetTypes(tasks);
		return cNode;
	};

	///////////////////////////////////////////////////////////////
	JDFNode JDFNode::AddProduct(){
		if(GetEnumType()!=Type_Product){
			throw JDFException(L"JDFNode:AddProduct adding Product to invalid node type: Type="+GetType());
		}
		JDFNode p=AddJDFNode(Type_Product);
		p.SetEnumType(Type_Product);
		return p;
	}
	///////////////////////////////////////////////////////////////
	bool JDFNode::RemoveCompleted(){
		vElement v=GetCompleted();
		for(int i=0;i<v.size();i++){
			JDFNode pr=v.at(i);
			pr.RemoveNode(false);
		}
		return true;
	}

	//////////////////////////////////////////////////////////////////////
	vElement JDFNode::GetCompleted()const{
		vElement v=GetvJDFNode(WString::emptyStr);
		vElement v2;
		for(int i=0;i<v.size();i++){
			JDFNode pr=v.at(i);
			if(pr.isNull()) break;
			if (pr.GetStatus()==Status_Completed){
				v2.push_back(pr);			
			}
		}
		return v2;
	}


	//////////////////////////////////////////////////////////////////////////////////////////////

	JDFResource JDFNode::GetTargetResource(const WString& id)const{
		XMLDocUserData* ud=getXMLDocUserData();
		if(ud!=0)
		{
			JDFElement e=ud->GetTarget(id);
			if(e.IsResource())
				return e;
		}


		JDFResourcePool p=GetResourcePool();
		if(!p.isNull()){
			JDFResource r=p.GetResourceByID(id);
			if(!r.isNull())
				return r;
		}
		vElement v=GetvJDFNode(WString::emptyStr,Activation_Unknown,true);
		for(int i=0;i<v.size();i++){
			JDFResource r=JDFNode(v.at(i)).GetTargetResource(id);
			if(!r.isNull())
				return r;
		}
		return  JDFResource();
	}

	//////////////////////////////////////////////////////////////////////
	JDFResource JDFNode::AddInternalPipe(const WString& resourceName, unsigned int indexOutput, unsigned int indexInput){
		if(GetEnumType()!=Type_Combined){
			throw JDFException(L"JDFNode::AddInternalPipe: adding pipe to node that is not combined "+GetType());
		} 
		JDFResource r=AddResource(resourceName,JDFResource::Class_Unknown,true);
		JDFFactory f(r);
		f.GetRef().init();
		r.SetPipeProtocol(L"Internal");

		JDFResourceLink rl=GetLink(r,true);
		rl.SetPipeProtocol(L"Internal"); // redundant but not harmful
		rl.SetCombinedProcessIndex(JDFIntegerList(indexInput));
		rl=LinkResource(r,false);
		rl.SetPipeProtocol(L"Internal");// redundant but not harmful
		rl.SetCombinedProcessIndex(JDFIntegerList(indexOutput));
		return r;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFNode::RequiredLevel(EnumValidationLevel level)const{
		level=IncompleteLevel(level);
		return (level==ValidationLevel_Complete)||(level==ValidationLevel_RecursiveComplete);
	};

	//////////////////////////////////////////////////////////////////////////////////////////////

	KElement::EnumValidationLevel JDFNode::IncompleteLevel(KElement::EnumValidationLevel level)const{
		if(JDFElement::RequiredLevel(level)){
			EnumStatus es=GetStatus();
			if(es==Status_Setup){
				if(level==ValidationLevel_Complete){
					level=ValidationLevel_Incomplete;
				}else if(level==ValidationLevel_RecursiveComplete){
					level=ValidationLevel_RecursiveIncomplete;
				}
			}			
		}
		return level;
	}
	//////////////////////////////////////////////////////////////////////
	JDFNode JDFNode::GetRoot()const{
		return GetDeepParent(elm_JDF,9999999);
	};
	//////////////////////////////////////////////////////////////////////

	JDFNode JDFNode::GetProduct(const WString& productType, int iSkip)const{
		vJDFNode vN=GetvJDFNode(sProduct,Activation_Unknown,true);

		bool bWildCard=IsWildcard(productType.c_str());

		// loop over all direct product nodes
		for(int i=0;i<vN.size();i++){
			JDFNode n=vN[i];
			JDFComponent c=n.GetMatchingResource(JDFStrings::elm_Component,JDFNode::ProcessUsage_AnyOutput);
			// we have a matching component, return the corresponding node unless iSkip>0
			if( !c.isNull()
				&& (bWildCard || (c.GetAttribute(JDFStrings::atr_ProductType)==productType))
				&& (iSkip--<=0) ){
					return n;
			}
		}
		// ain't got nothing that matches
		return DefJDFNode;
	};

	//////////////////////////////////////////////////////////////////////
	/**
	* Checks whether this link references a resource that 
	*/
	bool JDFNode::LinkFitsRWRes(const JDFResourceLink& li, const vWString& vRWResources){
		bool bResRW=vRWResources.hasString(li.GetNamedProcessUsage());
		// 200602 RP added fix
		if(!bResRW)
			bResRW=vRWResources.hasString(li.GetLinkedResourceName());

		// 230802 RP added check for ID in vRWResources
		if(!bResRW)
			bResRW=vRWResources.hasString(li.GetHRef());

		// 040902 RP added check for Usage in vRWResources
		if(!bResRW)
			bResRW=vRWResources.hasString(li.GetAttribute(JDFStrings::atr_Usage));		
		return bResRW;
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFNode::ResFitsRWRes(const JDFResource& r, const vWString& vRWResources){

		bool bResRW=vRWResources.hasString(r.GetLocalName());
		// 200602 RP added fix
		if(!bResRW)
			bResRW=vRWResources.hasString(WString::star);

		// 230802 RP added check for ID in vRWResources
		if(!bResRW)
			bResRW=vRWResources.hasString(r.GetID());

		return bResRW;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////

	void JDFNode::CopySpawnedResource(JDFResourcePool p, JDFResource r, JDFResource::EnumSpawnStatus copyStatus, const vmAttribute& vParts, const WString &spawnID, const vWString& resInPool, const vWString& vRWResources, vWString& vRWIDs, vWString& vROIDs, bool bSpawnROPartsOnly){

		vWString ss=resInPool;
		if(ss.empty())
			ss=p.GetResIds();


		if (r.throwNull()) {
			return;
		}

		// r is not yet here copy r
		if(ss.find(r.GetID())==ss.end()) {

			JDFResource rNew=p.CopyElement(r);
			// if spawning, fix stati and locks

			if((copyStatus==r.SpawnStatus_SpawnedRW)||bSpawnROPartsOnly){
				rNew.ReducePartitions(vParts);
			}
			r.SpawnPart(spawnID,copyStatus,vParts,true);
			rNew.SpawnPart(spawnID,copyStatus,vParts,false);


			if(copyStatus==r.SpawnStatus_SpawnedRW){
				vRWIDs.push_back(rNew.GetID());
			}else{
				vROIDs.push_back(rNew.GetID());
			}
		}


		vWString vs=r.GetHRefs();		
		// add recursively copied resource references
		for(int i=0;i<vs.size();i++){
			const WString& id=vs[i];

			// the referenced resource is already in this pool - continue
			if(ss.hasString(id)) 
				continue;

			JDFResource next=p.GetParentJDF().GetTargetResource(id);
			if(next.isNull()){
				// 071101 RP added r is by definition in the original document which also contains the rrefs elements
				next=JDFNode(r.GetDocRoot()).GetTargetResource(id);

				// and now all those interlinked resources
				if (next.throwNull())
					continue;

				// only copy refelements rw if they are explicitly in the list
				if(copyStatus==r.SpawnStatus_SpawnedRW)
					copyStatus=ResFitsRWRes(next,vRWResources)?r.SpawnStatus_SpawnedRW:r.SpawnStatus_SpawnedRO;

				// recurse into refelements
				CopySpawnedResource(p,next,copyStatus,vParts,spawnID,ss,vRWResources,vRWIDs,vROIDs,bSpawnROPartsOnly);
				// these have been copied here
				ss.insert(ss.end(),vRWIDs.begin(),vRWIDs.end());
				ss.insert(ss.end(),vROIDs.begin(),vROIDs.end());
			}			
		}		
		return;
	}
	//////////////////////////////////////////////////////////////////////
	vWString JDFNode::GetPartIDKeys(const mAttribute& partMap)
	{
		vWString matchingPartIDKeys;
		if(partMap.size() > 1)
		{
			JDFResourceLinkPool resourceLinkPool = GetResourceLinkPool();
			vElement linkedResources = resourceLinkPool.GetLinkedResources();
			int linkedResourcesSize = linkedResources.size();
			for (int i = 0; i < linkedResourcesSize; i++)
			{
				JDFResource resource = linkedResources[i];
				vWString partIDKeys = resource.GetPartIDKeys();
				if(partIDKeys.size() >= partMap.size() && partIDKeys.containsAll(partMap.GetKeys()))
				{
					matchingPartIDKeys = partIDKeys;
					break;
				}
			}
		}
		else
		{
			matchingPartIDKeys = partMap.GetKeys();
		}
		if(matchingPartIDKeys.empty()){
			// grab output link and partition nodeinfo accordingly
			vElement vRes=GetResourceLinkPool().GetInOutLinks(false,true);
			for (int i = 0; i < vRes.size(); i++)
			{
				JDFResourceLink rl = (JDFResourceLink) vRes.at(i);
				vRes[i]=rl.GetLinkRoot();
			}

			// get heuristic list of partidkeys from the output
			vWString partIDKeys;
			if(vRes.size()>0){
				JDFResource r=vRes[0];
				matchingPartIDKeys=r.GetResourceRoot().GetPartIDKeys();
			}
		}
		return matchingPartIDKeys;
	}

	//////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////

	vElement JDFNode::PrepareNodeInfo(const vmAttribute& vSpawnParts){
		JDFNodeInfo ni=GetCreateNodeInfo(); // make sure we have a nodeinfo in case we have to merge stati 
		vElement vni;
		if(ni.HasAttribute(atr_Class)){ // it is a 1.3 style resource
			mAttribute spawnPart;

			// find the most granular part in the vector
			int i;
			for(i=0;i<vSpawnParts.size();i++){
				if(vSpawnParts[i].size()>spawnPart.size())
					spawnPart=vSpawnParts[i];
			}

			vWString partVector=GetPartIDKeys(spawnPart);
			if(vSpawnParts.size()>0){
				if(GetStatus()!=Status_Part){
					ni.SetAttribute(L"NodeStatus",GetAttribute(atr_Status));
					SetStatus(Status_Part);
				}

				for(i=0;i<vSpawnParts.size();i++){
					JDFNodeInfo niLeaf=ni.GetPartition(vSpawnParts[i],JDFResource::PartUsage_Explicit);
					if(niLeaf.isNull()){ // leaves that do not exist yet are assumed waiting
						niLeaf=ni.GetCreatePartition(vSpawnParts[i],partVector);
						niLeaf.SetAttribute(L"NodeStatus",L"Waiting");
					}
					vni.push_back(niLeaf); 
				}
			}else{
				vni.push_back(ni);
			}
		}else{
			vni.push_back(ni); // simply return the 1.2 element
		}
		return vni;
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Gets the vector of the string Type/Types attribute values of the given JDFNode by 
	* recursively traversing the tree
	* returns exactly one element="Product" if the tested node's type is product
	*
	* @param JDFNode jdfRoot - the ProcessGroup JDFNode
	* @return VString - vector of Type/Types attributes of the tested ProcessGroup JDFNode
	* @throws JDFException if the testen JDFNode has illegal combination of attribute 'Types' and child JDFNodes
	*/
	vWString JDFNode::getAllTypes() const
	{
		VString vs;
		if(GetType().equals(L"Product"))
		{
			vs=vWString(L"Product");
		}
		else if(GetType().equals(L"Combined"))
		{
			vs=GetTypes();
		}
		else if(GetType().equals(L"ProcessGroup"))
		{
			VElement vNodes = GetvJDFNode(WString::emptyStr,Activation_Unknown,true);
			vs = GetTypes();
			if (!vs.empty()) // grey box or simple type 
			{
				if (vNodes.size()!=0) 
				{
					throw new JDFException ("JDFNode.getAllTypes: illegal combination of the attribute 'Types' and child JDF Nodes");
				}
				return vs;// __Lena__  May contain GrayBoxes
			}
			for (int i=0; i<vNodes.size(); i++) 
			{
				JDFNode node = (JDFNode)vNodes.elementAt(i);
				VString allTypes = node.getAllTypes();
				if(!allTypes.empty())
				{
					if(vs.empty())
					{
						vs=allTypes;
					}
					else
					{
						vs.addAll(allTypes);
					}
				}
			}
		}
		else
		{
			WString type=GetType();
			vs=VString(type);
		}
		return vs;
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* setCombined - set the combined node types to the values in vCombiNodes
	*
	* @param Vector vCombiNodes
	*/
	void JDFNode::setCombined(const vWString& vCombiNodes)
	{
		SetType(JDFNode::TypeString(JDFNode::Type_Combined));
		SetTypes(vCombiNodes);
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Set the Status and StatusDetails of this node
	* update the PhaseTime audit or append a new phasetime as appropriate  
	* also generate a status JMF
	* 
	* @param nodeStatus the new status of the node
	* @param nodeStatusDetails the new statusDetails of the node
	* @param deviceStatus the new status of the device
	* @param deviceStatusDetails the new statusDetails of the device
	* @param vPartMap the vector of parts to that should be set
	* 
	* @return The root element representing the PhaseTime JMF
	*/
	JDFDoc JDFNode::setPhase(JDFNode::EnumStatus nodeStatus, const WString& nodeStatusDetails, const WString& deviceID, 
		JDFDeviceInfo::EnumDeviceStatus deviceStatus, const WString& deviceStatusDetails, const vmAttribute& vPartMap)
	{
		JDFDoc jmfDoc(1);
		JDFJMF jmf=jmfDoc.GetJMFRoot();

		JDFAuditPool ap=GetCreateAuditPool();
		JDFPhaseTime pt1=(JDFPhaseTime) ap.GetAudit(-1,JDFAudit::AuditType_PhaseTime,mAttribute::emptyMap);
		JDFPhaseTime pt2=ap.SetPhase(nodeStatus,nodeStatusDetails,vPartMap);
		if(!pt1.isNull() && pt2!=pt1) // we explicitly added a new phasetime audit, thus we need to add a closing JMF for the original jobPhase
		{
			JDFSignal s=(JDFSignal)jmf.appendMessageElement(JDFMessage::Family_Signal,JDFMessage::Type_Status);
			JDFDeviceInfo deviceInfo = s.AppendDeviceInfo();
			deviceInfo.createJobPhaseFromPhaseTime(pt1);
			if(!deviceID.empty())
				pt2.AppendDevice().SetDeviceID(deviceID);
		}
		JDFSignal s=(JDFSignal)jmf.appendMessageElement(JDFMessage::Family_Signal,JDFMessage::Type_Status);
		JDFDeviceInfo deviceInfo = s.AppendDeviceInfo();
		deviceInfo.createJobPhaseFromPhaseTime(pt2); 
		deviceInfo.SetDeviceStatus(deviceStatus);
		deviceInfo.SetStatusDetails(deviceStatusDetails);
		deviceInfo.SetDeviceID(deviceID);
		SetPartStatus(vPartMap,nodeStatus);
		// cleanup
		jmf.eraseEmptyAttributes(true);
		pt2.eraseEmptyAttributes(true);
		return jmfDoc;
	}
	//////////////////////////////////////////////////////////////////////
	KElement JDFNode::getNiCi(const WString& elementName, bool bInherit, const WString& xPath) const
	{
		// always get the element
		KElement nici=GetElement(elementName);
		EnumVersion eVer = GetEnumVersion(true);
		// if version>=1.0 or no direct element is there try the resource
		if (eVer >= Version_1_3 || (nici.isNull()) )
		{
			JDFResourceLinkPool rlp = GetResourceLinkPool();
			if( !rlp.isNull() )
			{
				JDFResourceLink rl=rlp.GetPoolChild(0,elementName+"Link",JDFAttributeMap(atr_Usage,"Input"),WString::emptyStr);
				if(! rl.isNull() )
					nici=rl.GetPart(1).isNull() ? rl.GetTarget() : rl.GetLinkRoot();
			}
		}

		// continue search if not found
		if(!nici.isNull() || !bInherit)
		{
			return nici;
		}

		JDFNode parent = GetParentJDF();
		if( !parent.isNull() )
		{
			return parent.getNiCi(elementName,bInherit, xPath);
		}
		JDFAncestorPool ap=GetAncestorPool();
		if( !ap.isNull() )
			return ap.GetAncestorElement(elementName,WString::emptyStr);
		return JDFElement::DefKElement;
	}
	//////////////////////////////////////////////////////////////////////
}
