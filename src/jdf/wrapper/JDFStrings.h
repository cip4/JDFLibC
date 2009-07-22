#if !defined(_JDFSTRINGS_H__)
#define _JDFSTRINGS_H__

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
/* *******************************************************************
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// 290404 created from JDGFElement
// 211106 NB changed value of atr_File to lower case
// 281106 NB added elm_ModifyNodeCmdParams, elm_UpdateJDFCmdParams
*/

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <jdf/lang/WString.h>


namespace JDF{
	
	
	
/**
* JDFStrings contains a list of static strings for use with the JDF Library
* it is never instantiated
*/

	class JDF_WRAPPERCORE_EXPORT JDFStrings{
	protected:
		JDFStrings(){};
		virtual~JDFStrings(){};
		JDFStrings(const JDFStrings&s){};

	public:
		static const WString elm_Acknowledge;
		static const WString elm_Action;
		static const WString elm_ActionPool;
		static const WString elm_Added;
		static const WString elm_Address;
		static const WString elm_AdhesiveBinding;
		static const WString elm_AdhesiveBindingParams;
		static const WString elm_AdvancedParams;
		static const WString elm_AllowedValue;
		static const WString elm_AllowedValueList;
		static const WString elm_Amount;
		static const WString elm_AmountPool;
		static const WString elm_Ancestor;
		static const WString elm_AncestorPool;
		static const WString elm_and;
		static const WString elm_ApprovalDetails;
		static const WString elm_ApprovalParams;
		static const WString elm_ApprovalPerson;
		static const WString elm_ApprovalSuccess;
		static const WString elm_ArgumentValue;
		static const WString elm_ArtDelivery;
		static const WString elm_ArtDeliveryDate;
		static const WString elm_ArtDeliveryDuration;
		static const WString elm_ArtDeliveryIntent;
		static const WString elm_ArtHandling;
		static const WString elm_Assembly;
		static const WString elm_AssemblySection;
		static const WString elm_AssetListCreationParams;
		static const WString elm_Audit;
		static const WString elm_AuditPool;
		static const WString elm_AutomatedOverPrintParams;
		static const WString elm_AutomatedOverprintParams; // legacy for typo

		// BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB //
		
		static const WString elm_BackCoatings;
		static const WString elm_BackCoverColor;
		static const WString elm_Band;
		static const WString elm_Barcode;
		static const WString elm_BarcodeCompParams;
		static const WString elm_BarcodeDetails;
		static const WString elm_BarcodeProductionParams;
		static const WString elm_BarcodeReproParams;
		static const WString elm_BasicPreflightTest;
		static const WString elm_BinderBrand;
		static const WString elm_BinderMaterial;
		static const WString elm_BinderySignature;
		static const WString elm_BindingColor;
		static const WString elm_BindingIntent;
		static const WString elm_BindingLength;
		static const WString elm_BindingSide;
		static const WString elm_BindingType;
		static const WString elm_BindingQualityMeasurement;
		static const WString elm_BindingQualityParams;
		static const WString elm_BindItem;
		static const WString elm_BindList;
		static const WString elm_BlockPreparationParams;
		static const WString elm_BlockThreadSewing;
		static const WString elm_BookCase;
		static const WString elm_BooleanEvaluation;
		static const WString elm_BooleanState;
		static const WString elm_BoxApplication;
		static const WString elm_BoxArgument;
		static const WString elm_BoxedQuantity;
		static const WString elm_BoxFoldAction;
		static const WString elm_BoxPackingParams;
		static const WString elm_BoxShape;
		static const WString elm_BoxToBoxDifference;
		static const WString elm_BrandName;
		static const WString elm_Brightness;
		static const WString elm_BufferParams;
		static const WString elm_BundlingParams;
		static const WString elm_Bundle;
		static const WString elm_BundleItem;
		static const WString elm_BusinessInfo;
		static const WString elm_BuyerSupplied;
		static const WString elm_ByteMap;

		// CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
		
		static const WString elm_call;
		static const WString elm_CartonMaxWeight;
		static const WString elm_CartonQuantity;
		static const WString elm_CartonShape;
		static const WString elm_CartonStrength;
		static const WString elm_CaseMakingParams;
		static const WString elm_CasingInParams;
		static const WString elm_CCITTFaxParams;
		static const WString elm_ChangedAttribute;
		static const WString elm_ChangedPath;
		static const WString elm_ChannelBinding;
		static const WString elm_ChannelBindingParams;
		static const WString elm_ChannelBrand;
		static const WString elm_choice;
		static const WString elm_CIELABMeasuringField;
		static const WString elm_Circulation;

		static const WString elm_Coatings;
		static const WString elm_CoilBinding;
		static const WString elm_CoilBindingParams;
		static const WString elm_CoilBrand;
		static const WString elm_CoilMaterial;
		static const WString elm_CollatingItem;
		static const WString elm_CollectingParams;
		static const WString elm_Color;
		static const WString elm_ColorantAlias;
		static const WString elm_ColorantControl;
		static const WString elm_ColorantOrder;
		static const WString elm_ColorantParams;
		static const WString elm_ColorantZoneDetails;
		static const WString elm_ColorControlStrip;
		static const WString elm_ColorCorrectionOp;
		static const WString elm_ColorCorrectionParams;
		static const WString elm_ColorICCStandard;
		static const WString elm_ColorIntent;
		static const WString elm_ColorMeasurementConditions;
		static const WString elm_ColorName;
		static const WString elm_ColorPool;
		static const WString elm_ColorsConstraintsPool;
		static const WString elm_ColorSpaceConversionOp;
		static const WString elm_ColorSpaceConversionParams;
		static const WString elm_ColorSpaceSubstitute;
		static const WString elm_ColorsResultsPool;
		static const WString elm_ColorStandard;
		static const WString elm_ColorsUsed;
		static const WString elm_ColorType;
		static const WString elm_CombBrand;
		static const WString elm_ComChannel;
		static const WString elm_Command;
		static const WString elm_CommandStopPersistentChannel;
		static const WString elm_Comment;
		static const WString elm_Company;
		static const WString elm_Component;
		static const WString elm_ConstraintValue;
		static const WString elm_Contact;
		static const WString elm_ContactCopyParams;
		static const WString elm_Container;
		static const WString elm_ContentData;
		static const WString elm_ContentList;
		static const WString elm_ContentObject;
		static const WString elm_ConventionalPrintingParams;
		static const WString elm_CostCenter;
		static const WString elm_CounterReset;
		static const WString elm_Cover;
		static const WString elm_Coverage;
		static const WString elm_CoverApplicationParams;
		static const WString elm_CoverColor;
		static const WString elm_CoverStyle;
		static const WString elm_Crease;
		static const WString elm_CreasingParams;
		static const WString elm_Created;
		static const WString elm_CreateLink;
		static const WString elm_CreateResource;
		static const WString elm_CreditCard;
		static const WString elm_CustomerInfo;
		static const WString elm_CustomerMessage;
		static const WString elm_Cut;
		static const WString elm_CutBlock;
		static const WString elm_CutMark;
		static const WString elm_CuttingParams;
		static const WString elm_CutType;
		static const WString elm_CylinderPosition;

		// DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD //
		
		static const WString elm_DateTimeEvaluation;
		static const WString elm_DateTimeState;
		static const WString elm_DBMergeParams;
		static const WString elm_DBRules;
		static const WString elm_DBSchema;
		static const WString elm_DBSelection;
		static const WString elm_DCTParams;
		static const WString elm_Deleted;
		static const WString elm_DeliveryCharge;
		static const WString elm_DeliveryIntent;
		static const WString elm_DeliveryMode;
		static const WString elm_DeliveryParams;
		static const WString elm_DensityMeasuringField;
		static const WString elm_Dependencies;
		static const WString elm_DevCap;
		static const WString elm_DevCapPool;
		static const WString elm_DevCaps;
		static const WString elm_DevelopingParams;
		static const WString elm_Device;
		static const WString elm_DeviceCap;
		static const WString elm_DeviceColorantOrder;
		static const WString elm_DeviceFilter;
		static const WString elm_DeviceInfo;
		static const WString elm_DeviceList;
		static const WString elm_DeviceMark;
		static const WString elm_DeviceNColor;
		static const WString elm_DeviceNSpace;
		static const WString elm_DieLayout;
		static const WString elm_DigitalDeliveryParams;
		static const WString elm_DigitalMedia;
		static const WString elm_DigitalPrintingParams;
		static const WString elm_Dimensions;
		static const WString elm_Direction;
		static const WString elm_Disjointing;
		static const WString elm_DisplayGroup;
		static const WString elm_DisplayGroupPool;
		static const WString elm_Disposition;
		static const WString elm_DividingParams;
		static const WString elm_DocumentConstraintsPool;
		static const WString elm_DocumentResultsPool;
		static const WString elm_DotSize;
		static const WString elm_Drop;
		static const WString elm_DropIntent;
		static const WString elm_DropItem;
		static const WString elm_DropItemIntent;
		static const WString elm_DurationEvaluation;
		static const WString elm_DurationState;
		static const WString elm_DynamicField;
		static const WString elm_DynamicInput;
		
		static const WString elm_Earliest;
		static const WString elm_EarliestDuration;
		static const WString elm_EdgeAngle;
		static const WString elm_EdgeGlue;
		static const WString elm_EdgeGluing;
		static const WString elm_EdgeShape;
		static const WString elm_ElementColorParams;
		static const WString elm_Emboss;
		static const WString elm_EmbossingIntent;
		static const WString elm_EmbossingItem;
		static const WString elm_EmbossingParams;
		static const WString elm_EmbossingType;
		static const WString elm_Employee;
		static const WString elm_EmployeeDef;
		static const WString elm_EndSheet;
		static const WString elm_EndSheetGluingParams;
		static const WString elm_EndSheets;
		static const WString elm_EnumerationEvaluation;
		static const WString elm_EnumerationState;
		static const WString elm_Error;
		static const WString elm_ErrorData;
		static const WString elm_Event;
		static const WString elm_ExposedMedia;
		static const WString elm_ExtendedAddress;
		static const WString elm_ExternalImpositionTemplate;

//FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
		
		static const WString elm_FCNKey;
		static const WString elm_FeatureAttribute;
		static const WString elm_FeaturePool;
		static const WString elm_Feeder;
		static const WString elm_FeederQualityParams;
		static const WString elm_FeedingParams;
		static const WString elm_FileAlias;
		static const WString elm_FileSpec;
		static const WString elm_FileSpecOut;
		static const WString elm_FileTypeConstraintsPool;
		static const WString elm_FileTypeResultsPool;
		static const WString elm_FinishedDimensions;
		static const WString elm_FinishedGrainDirection;
		static const WString elm_FitPolicy;
		static const WString elm_FlateParams;
		static const WString elm_FlushedResources;
		static const WString elm_FlushQueueParams;
		static const WString elm_FlushResourceParams;
		static const WString elm_FoilColor;
		static const WString elm_Fold;
		static const WString elm_FolderSuperstructureWebPath;
		static const WString elm_FolderProduction;
		static const WString elm_FoldingCatalog;
		static const WString elm_FoldingIntent;
		static const WString elm_FoldingParams;
		static const WString elm_FoldingWidth;
		static const WString elm_FoldingWidthBack;
		static const WString elm_FontParams;
		static const WString elm_FontPolicy;
		static const WString elm_FontsConstraintsPool;
		static const WString elm_FontsResultsPool;
		static const WString elm_FormatConversionParams;
		static const WString elm_Frequency;
		static const WString elm_FrequencySelection;
		static const WString elm_FrontCoatings;

		// GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG //
		
		static const WString elm_GangCmdFilter;
		static const WString elm_GangInfo;
		static const WString elm_GangQuFilter;
		static const WString elm_GatheringParams;
		static const WString elm_GeneralID;
		static const WString elm_Glue;
		static const WString elm_GlueApplication;
		static const WString elm_GlueLine;
		static const WString elm_GlueProcedure;
		static const WString elm_GlueType;
		static const WString elm_GluingParams;
		static const WString elm_Grade;
		static const WString elm_GrainDirection;

		// HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
		
		static const WString elm_HalfTone;
		static const WString elm_HardCoverBinding;
		static const WString elm_HeadBandApplicationParams;
		static const WString elm_HeadBandColor;
		static const WString elm_Headbands;
		static const WString elm_HeadBands;
		static const WString elm_Height;
		static const WString elm_Hole;
		static const WString elm_HoleCount;
		static const WString elm_HoleLine;
		static const WString elm_HoleList;
		static const WString elm_HoleMakingIntent;
		static const WString elm_HoleMakingParams;
		static const WString elm_HoleType;

		// IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
		
		static const WString elm_Icon;
		static const WString elm_IconList;
		static const WString elm_Identical;
		static const WString elm_IdentificationField;
		static const WString elm_IDInfo;
		static const WString elm_IDPCover;
		static const WString elm_IDPFinishing;
		static const WString elm_IDPFolding;
		static const WString elm_IDPHoleMaking;
		static const WString elm_IDPImageShift;
		static const WString elm_IDPJobSheet;
		static const WString elm_IDPLayout;
		static const WString elm_IDPrintingParams;
		static const WString elm_IDPStitching;
		static const WString elm_IDPTrimming;
		static const WString elm_ImageCompression;
		static const WString elm_ImageCompressionParams;
		static const WString elm_ImageReplacementParams;
		static const WString elm_ImagesConstraintsPool;
		static const WString elm_ImageSetterParams;
		static const WString elm_ImageShift;
		static const WString elm_ImageSize;
		static const WString elm_ImageStrategy;
		static const WString elm_ImagesResultsPool;
		static const WString elm_Ink;
		static const WString elm_InkManufacturer;
		static const WString elm_InkZoneCalculationParams;
		static const WString elm_InkZoneProfile;
		static const WString elm_Insert;
		static const WString elm_InsertingIntent;
		static const WString elm_InsertingParams;
		static const WString elm_InsertList;
		static const WString elm_InsertSheet;
		static const WString elm_IntegerEvaluation;
		static const WString elm_IntegerState;
		static const WString elm_InterpretedPDLData;
		static const WString elm_InterpretingParams;
		static const WString elm_IsPresentEvaluation;
		static const WString elm_IssueDate;
		static const WString elm_IssueName;
		static const WString elm_IssueType;

		// JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
		
		static const WString elm_Jacket;
		static const WString elm_JacketFoldingWidth;
		static const WString elm_JacketingParams;
		static const WString elm_JapanBind;
		static const WString elm_JBIG2Params;
		static const WString elm_JDF;
		static const WString elm_JDFController;
		static const WString elm_JDFService;
		static const WString elm_JDFSystemTimeSet;
		static const WString elm_JMF;
		static const WString elm_JobField;
		static const WString elm_JobPhase;
		static const WString elm_JobSheet;
		static const WString elm_JPEG2000Params;
		
		// KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK

		static const WString elm_KnownMsgQuParams;
		
		// LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL

		static const WString elm_LabelingParams;
		static const WString elm_Laminated;
		static const WString elm_LaminatingIntent;
		static const WString elm_LaminatingParams;
		static const WString elm_LayerDetails;
		static const WString elm_LayerList;
		static const WString elm_Layout;
		static const WString elm_LayoutElement;
		static const WString elm_LayoutElementPart;
		static const WString elm_LayoutElementProductionParams;
		static const WString elm_LayoutIntent;
		static const WString elm_LayoutPreparationParams;
		static const WString elm_Level;
		static const WString elm_Loc;
		static const WString elm_Location;
		static const WString elm_LongFold;
		static const WString elm_LongGlue;
		static const WString elm_LongitudinalRibbonOperationParams;
		static const WString elm_LongPerforate;
		static const WString elm_LongSlit;
		static const WString elm_Lot;
		static const WString elm_LZWParams;

		// MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
		
		static const WString elm_macro;
		static const WString elm_macros;
		static const WString elm_MacroPool;
		static const WString elm_ManualLaborParams;
		static const WString elm_MarkObject;
		static const WString elm_Material;
		static const WString elm_MatrixEvaluation;
		static const WString elm_MatrixState;

		static const WString elm_Media;
		static const WString elm_MediaColor;
		static const WString elm_MediaColorDetails;
		static const WString elm_MediaIntent;
		static const WString elm_MediaLayers;
		static const WString elm_MediaSource;
		static const WString elm_MediaType;
		static const WString elm_MediaTypeDetails;
		static const WString elm_MediaUnit;
		static const WString elm_Merged;
		static const WString elm_Message;
		static const WString elm_MessageService;
		static const WString elm_Method;

		static const WString elm_MISDetails;
		static const WString elm_Milestone;

		static const WString elm_Modified;
		static const WString elm_ModifyNodeCmdParams;
		static const WString elm_Module;
		static const WString elm_ModuleCap;
		static const WString elm_ModulePhase;
		static const WString elm_ModulePool;
		static const WString elm_ModuleStatus;
		static const WString elm_MoveLink;
		static const WString elm_MoveResource;
		static const WString elm_MsgFilter;

		// NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN //
		
		static const WString elm_NameEvaluation;
		static const WString elm_NameState;
		static const WString elm_NewComment;
		static const WString elm_NewJDFCmdParams;
		static const WString elm_NewJDFQuParams;
		static const WString elm_NodeInfo;
		static const WString elm_NodeInfoCmdParams;
		static const WString elm_NodeInfoQuParams;
		static const WString elm_NodeInfoResp;
		static const WString elm_not;
		static const WString elm_Notification;
		static const WString elm_NotificationDef;
		static const WString elm_NotificationFilter;
		static const WString elm_NumberEvaluation;
		static const WString elm_NumberingIntent;
		static const WString elm_NumberingParam;
		static const WString elm_NumberingParams;
		static const WString elm_NumberItem;
		static const WString elm_NumberState;

		// OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO //
		
		static const WString elm_ObjectResolution;
		static const WString elm_ObservationTarget;
		static const WString elm_Occupation;
		static const WString elm_OCGControl;
		static const WString elm_Opacity;
		static const WString elm_OpacityLevel;
		static const WString elm_or;
		static const WString elm_OrderingParams;
		static const WString elm_OrganizationalUnit;
		static const WString elm_Orientation;
		static const WString elm_otherwise;
		static const WString elm_Overage;

		// PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP //
		
		static const WString elm_PackingIntent;
		static const WString elm_PackingParams;
		static const WString elm_PageCell;
		static const WString elm_PageData;
		static const WString elm_PageElement;
		static const WString elm_PageList;
		static const WString elm_PageAssignedList;
		static const WString elm_Pages;
		static const WString elm_PagesConstraintsPool;
		static const WString elm_PagesResultsPool;
		static const WString elm_PageVariance;
		static const WString elm_Pallet;
		static const WString elm_PalletCornerBoards;
		static const WString elm_PalletizingParams;
		static const WString elm_PalletMaxHeight;
		static const WString elm_PalletMaxWeight;
		static const WString elm_PalletQuantity;
		static const WString elm_PalletSize;
		static const WString elm_PalletType;
		static const WString elm_PalletWrapping;
		static const WString elm_Part;
		static const WString elm_PartAmount;
		static const WString elm_PartStatus;
		static const WString elm_Path;
		static const WString elm_Payment;
		static const WString elm_PayTerm;
		static const WString elm_PDFInterpretingParams;
		static const WString elm_PDFPathEvaluation;
		static const WString elm_PDFPathState;
		static const WString elm_PDFToPSConversionParams;
		static const WString elm_PDLResourceAlias;
		static const WString elm_PDFXParams;
		static const WString elm_Perforate;
		static const WString elm_PerforatingParams;
		static const WString elm_Performance;
		static const WString elm_Person;
		static const WString elm_PhaseTime;
		static const WString elm_PipeParams;
		static const WString elm_PixelColorant;
		static const WString elm_PlaceHolderResource;
		static const WString elm_PlasticCombBinding;
		static const WString elm_PlasticCombBindingParams;
		static const WString elm_PlasticCombType;
		static const WString elm_PlateCopyParams;
		static const WString elm_Position;
		static const WString elm_PostPressComponentPath;

		static const WString elm_PreflightAction;
		static const WString elm_PreflightAnalysis;
		static const WString elm_PreflightArgument;
		static const WString elm_PreflightConstraint;
		static const WString elm_PreflightConstraintsPool;
		static const WString elm_PreflightDetail;
		static const WString elm_PreflightInformation;
		static const WString elm_PreflightInstance;
		static const WString elm_PreflightInstanceDetail;
		static const WString elm_PreflightInventory;
		static const WString elm_PreflightParams;
		static const WString elm_PreflightProfile;
		static const WString elm_PreflightProfileConstraintsPool;
		static const WString elm_PreflightReport;
		static const WString elm_PreflightReportRulePool;
		static const WString elm_PreflightResultsPool;
		static const WString elm_PreflightValue;
		static const WString elm_PRError;
		static const WString elm_Preview;
		static const WString elm_PreviewGenerationParams;
		static const WString elm_Pricing;
		static const WString elm_PrintCondition;
		static const WString elm_PrintConditionColor;
		static const WString elm_PrintingUnitWebPath;
		static const WString elm_PrintPreference;
		static const WString elm_PrintProcess;
		static const WString elm_PrintRollingParams;
		static const WString elm_PRItem;
		static const WString elm_PRGroup;
		static const WString elm_PRGroupOccurrence;
		static const WString elm_PROccurrence;
		static const WString elm_ProcessRun;
		static const WString elm_ProductionIntent;
		static const WString elm_ProductionPath;
		static const WString elm_ProofingIntent;
		static const WString elm_ProofingParams;
		static const WString elm_ProofItem;
		static const WString elm_ProofType;
		static const WString elm_Properties;
		static const WString elm_PRRule;
		static const WString elm_PRRuleAttr;
		static const WString elm_PSToPDFConversionParams;

		// QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ //
		
		static const WString elm_QualityControlParams;
		static const WString elm_QualityControlResult;
		static const WString elm_QualityMeasurement;
		static const WString elm_Query;
		static const WString elm_Queue;
		static const WString elm_QueueEntry;
		static const WString elm_QueueEntryDef;
		static const WString elm_QueueEntryDefList;
		static const WString elm_QueueEntryPosParams;
		static const WString elm_QueueEntryPriParams;
		static const WString elm_QueueFilter;
		static const WString elm_QueueSubmissionParams;

		// RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR //
		
		static const WString elm_RectangleEvaluation;
		static const WString elm_RectangleState;
		static const WString elm_Recycled;
		static const WString elm_RecycledPercentage;
		static const WString elm_RegisterMark;
		static const WString elm_RegisterRibbon;
		static const WString elm_Registration;
		static const WString elm_Removed;
		static const WString elm_RemoveLink;
		static const WString elm_RemoveResource;
		static const WString elm_RenderingParams;
		static const WString elm_RequestQueueEntryParams;
		static const WString elm_Required;
		static const WString elm_RequiredDuration;
		static const WString elm_Resource;
		static const WString elm_ResourceAudit;
		static const WString elm_ResourceCmdParams;
		static const WString elm_ResourceDefinitionParams;
		static const WString elm_ResourceInfo;
		static const WString elm_ResourceLink;
		static const WString elm_ResourceLinkPool;
		static const WString elm_ResourceParam;
		static const WString elm_ResourcePool;
		static const WString elm_ResourcePull;
		static const WString elm_ResourcePullParams;
		static const WString elm_ResourceQuParams;
		static const WString elm_Response;
		static const WString elm_ResubmissionParams;
		static const WString elm_ReturnQueueEntryParams;
		static const WString elm_ReturnMethod;
		static const WString elm_RingBinding;
		static const WString elm_RingBindingParams;
		static const WString elm_RingDiameter;
		static const WString elm_RingMechanic;
		static const WString elm_RingShape;
		static const WString elm_RingSystem;
		static const WString elm_RivetsExposed;
		static const WString elm_RollStand;
		static const WString elm_RunList;
		
		static const WString elm_SaddleStitching;
		static const WString elm_SaddleStitchingParams;
		static const WString elm_ScanParams;
		static const WString elm_ScavengerArea;
		static const WString elm_Score;
		static const WString elm_Scoring;
		static const WString elm_ScreeningIntent;
		static const WString elm_ScreeningParams;
		static const WString elm_ScreeningSpec;
		static const WString elm_ScreeningType;
		static const WString elm_ScreenSelector;
		static const WString elm_Sealing;
		static const WString elm_SearchPath;
		static const WString elm_SeparationControlParams;
		static const WString elm_SeparationList;
		static const WString elm_SeparationSpec;
		static const WString elm_ServiceLevel;
		static const WString elm_set;
		static const WString elm_Shape;
		static const WString elm_ShapeCut;
		static const WString elm_ShapeCuttingIntent;
		static const WString elm_ShapeCuttingParams;
		static const WString elm_ShapeDepth;
		static const WString elm_ShapeElement;
		static const WString elm_ShapeEvaluation;
		static const WString elm_ShapeState;
		static const WString elm_ShapeType;
		static const WString elm_Sheet;
		static const WString elm_ShrinkingParams;
		static const WString elm_ShutDown;
		static const WString elm_ShutDownCmdParams;
		static const WString elm_SideSewing;
		static const WString elm_SideSewingParams;
		static const WString elm_SideStitching;
		static const WString elm_Signal;
		static const WString elm_Signature;
		static const WString elm_SignatureCell;
		static const WString elm_SizeIntent;
		static const WString elm_SizePolicy;
		static const WString elm_SoftCoverBinding;
		static const WString elm_SourceResource;
		static const WString elm_Spawned;
		static const WString elm_SpineBrushing;
		static const WString elm_SpineFiberRoughing;
		static const WString elm_SpineFibreRoughing;
		static const WString elm_SpineGlue;
		static const WString elm_SpineLevelling;
		static const WString elm_SpineMilling;
		static const WString elm_SpineNotching;
		static const WString elm_SpinePreparationParams;
		static const WString elm_SpineSanding;
		static const WString elm_SpineShredding;
		static const WString elm_SpineTapingParams;
		static const WString elm_StackingParams;
		static const WString elm_State;
		static const WString elm_Station;
		static const WString elm_StatusPool;
		static const WString elm_StatusQuParams;
		static const WString elm_StitchingParams;
		static const WString elm_StitchNumber;
		static const WString elm_StockBrand;
		static const WString elm_StockType;
		static const WString elm_StopPersChParams;
		static const WString elm_Strap;
		static const WString elm_StrappingParams;
		static const WString elm_StringEvaluation;
		static const WString elm_StringListValue;
		static const WString elm_StringState;
		static const WString elm_StripBinding;
		static const WString elm_StripBindingParams;
		static const WString elm_StripMark;
		static const WString elm_StripMaterial;
		static const WString elm_StripCellParams;
		static const WString elm_StrippingParams;
		static const WString elm_SubmissionMethods;
		static const WString elm_Subscription;
		static const WString elm_Surface;
		static const WString elm_SurplusHandling;
		static const WString elm_SystemTimeSet;
		
		static const WString elm_TabBindMylar;
		static const WString elm_TabBrand;
		static const WString elm_TabBodyCopy;
		static const WString elm_TabExtensionDistance;
		static const WString elm_TabExtensionMylar;
		static const WString elm_TabMylarColor;
		static const WString elm_Tabs;
		static const WString elm_Tape;
		static const WString elm_TapeBinding;
		static const WString elm_TapeColor;
		static const WString elm_Technology;
		static const WString elm_TeethPerDimension;
		static const WString elm_Temperature;
		static const WString elm_Term;
		static const WString elm_Test;
		static const WString elm_TestPool;
		static const WString elm_TestRef;
		static const WString elm_Texture;
		static const WString elm_Thickness;
		static const WString elm_ThinPDFParams;
		static const WString elm_ThreadSealing;
		static const WString elm_ThreadSealingParams;
		static const WString elm_ThreadSewing;
		static const WString elm_ThreadSewingParams;
		static const WString elm_TIFFEmbeddedFile;
		static const WString elm_TIFFFormatParams;
		static const WString elm_TIFFtag;
		static const WString elm_TightBacking;
		static const WString elm_Tile;
		static const WString elm_Tool;
		static const WString elm_TrackFilter;
		static const WString elm_TrackResult;
		static const WString elm_Transfer;
		static const WString elm_TransferCurve;
		static const WString elm_TransferCurvePool;
		static const WString elm_TransferCurveSet;
		static const WString elm_TransferFunctionControl;
		static const WString elm_TrappingDetails;
		static const WString elm_TrappingOrder;
		static const WString elm_TrappingParams;
		static const WString elm_TrapRegion;
		static const WString elm_Trigger;
		static const WString elm_TrimmingParams;
		
		static const WString elm_Underage;
		static const WString elm_UpdateJDFCmdParams;
		static const WString elm_USWeight;
		
		static const WString elm_Value;
		static const WString elm_ValueLoc;
		static const WString elm_VeloBindingParams;
		static const WString elm_VerificationParams;
		static const WString elm_ViewBinder;
		
		static const WString elm_WakeUp;
		static const WString elm_WakeUpCmdParams;
		static const WString elm_Weight;
		static const WString elm_when;
		static const WString elm_WireCombBinding;
		static const WString elm_WireCombBindingParams;
		static const WString elm_WireCombBrand;
		static const WString elm_WireCombMaterial;
		static const WString elm_WireCombShape;
		static const WString elm_WrappedQuantity;
		static const WString elm_WrappingMaterial;
		static const WString elm_WrappingParams;
		
		static const WString elm_xor;
		static const WString elm_XPosition;
		static const WString elm_XYPairEvaluation;
		static const WString elm_XYPairState;
		
		static const WString elm_YPosition;
		






static const WString elm_ColorantConvertProcess;
static const WString elm_ContentMetaData;

static const WString elm_RuleLength;

static const WString elm_ShapeDef;
static const WString elm_ConvertingConfig;
static const WString elm_RepeatDesc;
static const WString elm_DieLayoutProductionParams;



static const WString elm_PageCondition;

static const WString elm_MarkActivation;
static const WString elm_RefAnchor;


static const WString elm_PositionObj;

static const WString elm_ShiftPoint;
static const WString elm_LayoutShift;


static const WString elm_TabDimensions;

static const WString elm_PageAssignParams;




static const WString elm_MetadataMap;


static const WString elm_ObjectModel;
static const WString elm_ShapeTemplate;
static const WString elm_ShapeDefProductionParams;

static const WString elm_StaticBlockingParams;



static const WString elm_VarnishingParams;


static const WString elm_ControllerFilter;

static const WString elm_SubscriptionFilter;
static const WString elm_SubscriptionInfo;

static const WString elm_Certificate;
static const WString elm_AuthenticationResp;
static const WString elm_AuthenticationQuParams;
static const WString elm_AuthenticationCmdParams;


static const WString elm_Flute;
static const WString elm_FluteDirection;
static const WString elm_MediaQuality;


static const WString elm_TabMylarColorDetails;
static const WString elm_ColorNameDetails;
static const WString elm_HeadBandColorDetails;
static const WString elm_FoilColorDetails;
static const WString elm_BindingColorDetails;
static const WString elm_CoverColorDetails;
static const WString elm_BackCoverColorDetails;

static const WString atr_ChannelMode;
static const WString atr_RetryPolicy;
static const WString atr_LotDetails;
static const WString atr_ResourceDetails;
static const WString atr_CommandResult;
static const WString atr_LotControlled;

static const WString atr_PreviewUsages;
static const WString atr_UpdateGranularity;
static const WString atr_TransactionID;

static const WString atr_IdleStartTime;
static const WString atr_RelatedCommands;
static const WString atr_MilestoneTypes;
static const WString atr_ReturnTime;
static const WString atr_WorkStepID;

static const WString atr_MarkContext;
static const WString atr_RelativeHeight;
static const WString atr_RelativeWidth;

static const WString atr_DieSide;
static const WString atr_Rotated;
static const WString atr_ContentRefs;


		//////////////////////////////////////////////////////////
		
		
		static const WString atr_Aborted;
		static const WString atr_AbortJobWhenScreenMatchingFails;
		static const WString atr_AbsoluteBox;
		static const WString atr_Accepted;
		static const WString atr_Acknowledge;
		static const WString atr_Acknowledged;
		static const WString atr_AcknowledgeFormat;
		static const WString atr_AcknowledgeTemplate;
		static const WString atr_AcknowledgeType;
		static const WString atr_AcknowledgeURL;
		static const WString atr_Action;
		static const WString atr_ActionPools;
		static const WString atr_ActionRef;
		static const WString atr_ActionRefs;
		static const WString atr_Activation;
		static const WString atr_Actual;	
		static const WString atr_ActualAmount;
		static const WString atr_ActualTotalAmount;
		static const WString atr_AdditionalAmount;
		static const WString atr_AdditionalNames;
		static const WString atr_AdditionalPrice;
		static const WString atr_AdhesiveType;
		static const WString atr_AdjustContrast;
		static const WString atr_AdjustCyanRed;
		static const WString atr_AdjustHue;
		static const WString atr_AdjustLightness;
		static const WString atr_AdjustMagentaGreen;
		static const WString atr_AdjustSaturation;
		static const WString atr_AdjustYellowBlue;
		static const WString atr_AdvanceDistance;
		static const WString atr_After;
		static const WString atr_AgentName;
		static const WString atr_AgentVersion;
		static const WString atr_AimCurve;
		static const WString atr_Alias;
		static const WString atr_AliasSeparations;
		static const WString atr_AllowedHWRelation;
		static const WString atr_AllowedLength;
		static const WString atr_AllowedRegExp;
		static const WString atr_AllowedRotateMod;
		static const WString atr_AllowedShift;
		static const WString atr_AllowedTransforms;
		static const WString atr_AllowedValue;
		static const WString atr_AllowedValueDurationList;
		static const WString atr_AllowedValueList;
		static const WString atr_AllowedValueMax;
		static const WString atr_AllowedValueMin;
		static const WString atr_AllowedValueMod;
		static const WString atr_AllowedX;
		static const WString atr_AllowedXYRelation;
		static const WString atr_AllowedY;
		static const WString atr_AllowedZ;
		static const WString atr_AllowPSXObjects;
		static const WString atr_AllowTransparency;
		static const WString atr_AlphaIsShape;
		static const WString atr_AlternateBrand;
		static const WString atr_AlternateColorSpace;
		static const WString atr_AlternateImages;
		static const WString atr_AlternatePositions;
		static const WString atr_AlwaysEmbed;
		static const WString atr_AmbiguousSeparations;
		static const WString atr_Amount;
		static const WString atr_AmountProduced;	
		static const WString atr_AmountRequired;	
		static const WString atr_Angle;
		static const WString atr_AngleMap;
		static const WString atr_AnnotationPrintFlag;
		static const WString atr_AnnotationType;
		static const WString atr_AntiAliasing;
		static const WString atr_AntiAliasImages;
		static const WString atr_Application;
		static const WString atr_ApplicationArea;
		static const WString atr_AppOS;
		static const WString atr_ApprovalRole;
		static const WString atr_ApprovalRoleDetails;
		static const WString atr_ApprovalState;
		static const WString atr_ApprovalStateDetails;
		static const WString atr_AppVersion;
		static const WString atr_AreaGlue;
		static const WString atr_ArtDeliveryType;
		static const WString atr_ASCII85EncodePages;
		static const WString atr_AspectRatio;
		static const WString atr_AssemblyID;
		static const WString atr_AssemblyIDs;
		static const WString atr_AssetTypes;
		static const WString atr_AttemptFixupErrors;
		static const WString atr_AttemptFixupWarnings;
		static const WString atr_Attribute;
		static const WString atr_AttributeName;
		static const WString atr_Attributes;
		static const WString atr_AttributesNaturalLang;
		static const WString atr_Author;
		static const WString atr_Authorization;
		static const WString atr_AuthorizationExpires;
		static const WString atr_AutoFilterImages;
		static const WString atr_Automated;
		static const WString atr_AutoPositionEPSInfo;
		static const WString atr_AutoRotatePages;
		static const WString atr_AvailableAmount;
		static const WString atr_Availability;
		static const WString atr_AverageAmount;
		static const WString atr_AverageCleanup;
		static const WString atr_AverageSetup;

		// BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB //
		
		static const WString atr_BackCoatings;
		static const WString atr_BackFacePages;
		static const WString atr_BackGlossValue;
		static const WString atr_Backing;
		static const WString atr_BackMarkList;
		static const WString atr_BackOverfold;
		static const WString atr_BackPages;
		static const WString atr_BackSide;
		static const WString atr_BadFeedQuality;
		static const WString atr_BadFeeds;
		static const WString atr_BandHeight;
		static const WString atr_BandOrdering;
		static const WString atr_BandWidth;
		static const WString atr_BarcodeVersion;
		static const WString atr_BaseOrdReset;		
		static const WString atr_BatchID;	
		static const WString atr_Before;
		static const WString atr_BearerBars;
		static const WString atr_BelongsToAnnotation;
		static const WString atr_Bend;
		static const WString atr_BestEffortExceptions;

		static const WString atr_BillingCode;
		static const WString atr_BillingType;
		static const WString atr_BillingTypeDetails;
		static const WString atr_BinaryOK;
		static const WString atr_BinaryValue;
		static const WString atr_BinderColor;
		static const WString atr_BinderMaterial;
		static const WString atr_BinderName;
		static const WString atr_BinderySignatureName;
		static const WString atr_BinderySignatureType;
		static const WString atr_Binding;
		static const WString atr_BindingEdge;
		static const WString atr_BindingOrder;
		static const WString atr_BindingOrientation;
		static const WString atr_BindingSide;
		static const WString atr_BitDepth;
		static const WString atr_BitsPerSample;
		static const WString atr_BlackColorLimit;
		static const WString atr_BlackDensityLimit;
		static const WString atr_BlackGeneration;
		static const WString atr_BlackWidth;
		static const WString atr_BlankDimensionsX;
		static const WString atr_BlankDimensionsY;
		static const WString atr_BlankPage;
		static const WString atr_BleedFace;
		static const WString atr_BleedFoot;
		static const WString atr_BleedHead;
		static const WString atr_BleedSpine;
		static const WString atr_BlendColorSpace;
		static const WString atr_BlendMode;
		static const WString atr_BlindStitch;
		static const WString atr_BlockElementSize;
		static const WString atr_BlockElementType;
		static const WString atr_BlockName;
		static const WString atr_Blocks;
		static const WString atr_BlockSize;
		static const WString atr_BlockSubdivision;
		static const WString atr_BlockTrf;
		static const WString atr_BlockType;

		static const WString atr_Border;
		static const WString atr_BottleAngle;
		static const WString atr_BottleAxis;
		static const WString atr_BottomBrand;
		static const WString atr_BottomColor;
		static const WString atr_BottomFoldIn;
		static const WString atr_BottomLength;
		static const WString atr_BoundingBox;
		static const WString atr_Box;
		static const WString atr_BoxedQuantity;
		static const WString atr_BoxFoldingType;
		static const WString atr_BoxShape;
		static const WString atr_Brand;
		static const WString atr_Brightness;
		static const WString atr_BroadsheetNumber;
		static const WString atr_BundleDepth;
		static const WString atr_BundleItemIndex;
		static const WString atr_BundleType;
		static const WString atr_BurnOutArea;
		static const WString atr_BusinessID;
		static const WString atr_BusinessRefID;
		static const WString atr_Busy;
		static const WString atr_BuyerAccount;
		static const WString atr_ByteOrder;

		// CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC//
		
		static const WString atr_CannotEmbedFontPolicy;
		static const WString atr_Capacity;
		static const WString atr_CartonMaxWeight;
		static const WString atr_CartonQuantity;
		static const WString atr_CartonShape;
		static const WString atr_CartonStrength;
		static const WString atr_CartonTopFlaps;
		static const WString atr_CaseRadius;
		static const WString atr_CastingMaterial;
		static const WString atr_CatalogDetails;
		static const WString atr_CatalogID;
		static const WString atr_Category;
		static const WString atr_CellIndex;
		static const WString atr_Center;
		static const WString atr_CenterAcross;
		static const WString atr_CenterCropBox;
		static const WString atr_CenterReference;
		static const WString atr_ChannelID;
		static const WString atr_ChannelType;
		static const WString atr_ChannelTypeDetails;
		static const WString atr_ChannelUsage;
		static const WString atr_CharacterProblem;
		static const WString atr_CheckSum;
		static const WString atr_ChildFolio;
		static const WString atr_CIELab;
		static const WString atr_CIETint;
		static const WString atr_CIEWhiteness;
		static const WString atr_City;
		static const WString atr_ClampColor;
		static const WString atr_ClampD;
		static const WString atr_ClampSize;
		static const WString atr_ClampSystem;
		static const WString atr_Class;
		static const WString atr_Classes;
		static const WString atr_ClassName;
		static const WString atr_CleanupDuration;
		static const WString atr_ClipBox;
		static const WString atr_ClipBoxFormat;
		static const WString atr_ClipBoxTemplate;
		static const WString atr_ClipOffset;
		static const WString atr_ClipPath;
		static const WString atr_CMYK;

		static const WString atr_Code;
		static const WString atr_CodeBlockSize;
		static const WString atr_Collate;
		static const WString atr_Color;
		static const WString atr_Colorant;
		static const WString atr_ColorantDepth;
		static const WString atr_ColorantName;
		static const WString atr_ColorantSetName;
		static const WString atr_ColorBook;
		static const WString atr_ColorBookEntry;
		static const WString atr_ColorBookPrefix;
		static const WString atr_ColorBookSuffix;
		static const WString atr_ColorList;
		static const WString atr_ColorManagementSystem;
		static const WString atr_ColorName;
		static const WString atr_ColorSpace;
		static const WString atr_ColorTransform;
		static const WString atr_ColorType;
		static const WString atr_CombinedMethod;
		static const WString atr_CombinedProcessIndex;	
		static const WString atr_CombinedProcessType;	
		static const WString atr_CombinedProcessUsage;	
		static const WString atr_Command;
		static const WString atr_CommentID;
		static const WString atr_CommentURL;
		static const WString atr_Company;
		static const WString atr_Compensate;
		static const WString atr_Compensation;
		static const WString atr_CompensationCTMFormat;
		static const WString atr_CompensationCTMTemplate;
		static const WString atr_CompensationProcess;
		static const WString atr_CompensationValue;
		static const WString atr_Completed;
		static const WString atr_ComponentGranularity;
		static const WString atr_ComponentsPerRow;
		static const WString atr_ComponentType;
		static const WString atr_Compression;
		static const WString atr_CompressionAlgorithm;
		static const WString atr_CompressionFilter;
		static const WString atr_CompressionRatio;
		static const WString atr_CompressionTypes;
		static const WString atr_CompressPages;
		static const WString atr_Condition;
		static const WString atr_Constraint;
		static const WString atr_ConsumableType;
		static const WString atr_Consumption;
		static const WString atr_Contact;
		static const WString atr_ContactScreen;
		static const WString atr_ContactTypeDetails;
		static const WString atr_ContactTypes;
		static const WString atr_ContentListIndex;
		static const WString atr_ContentsModified;
		static const WString atr_ContentType;
		static const WString atr_Context;
		static const WString atr_Contract;
		static const WString atr_ControllerID;
		static const WString atr_ConvertDevIndepColors;
		static const WString atr_ConvertImagesToIndexed;
		static const WString atr_Copies;
		static const WString atr_CoreMaterial;
		static const WString atr_CoreWeight;
		static const WString atr_CornerType;
		static const WString atr_CostCenterID;
		static const WString atr_Count;
		static const WString atr_CounterID;
		static const WString atr_CounterTypes;
		static const WString atr_CounterUnit;
		static const WString atr_Country;
		static const WString atr_CountryCode;
		static const WString atr_CoverOffset;
		static const WString atr_CoverType;
		static const WString atr_CoverWidth;
		static const WString atr_CreationDate;
		static const WString atr_CreationDateInDocument;
		static const WString atr_CreationID;
		static const WString atr_Creator;
		static const WString atr_Creep;
		static const WString atr_CreepValue;
		static const WString atr_CTM;

		static const WString atr_Currency;
		static const WString atr_CurrentValue;
		static const WString atr_Curve;
		static const WString atr_CustomerID;
		static const WString atr_CustomerJobName;
		static const WString atr_CustomerOrderID;
		static const WString atr_CustomerProjectID;
		static const WString atr_CostType;
		static const WString atr_CostTypeDetails;
		static const WString atr_CutBox;
		static const WString atr_CutMedia;
		static const WString atr_CutOut;
		static const WString atr_CutPath;
		static const WString atr_CutType;
		static const WString atr_CutWidthFoot;
		static const WString atr_CutWidthHead;
		static const WString atr_Cycle;
		
		// DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD //

		static const WString atr_Data;
		static const WString atr_DataBase;
		static const WString atr_DataType;	
		static const WString atr_DBSchemaType;
		static const WString atr_DCTQuality;
		static const WString atr_DeadLine;
		static const WString atr_DefaultID;
		static const WString atr_DefaultJDF;
		static const WString atr_DefaultPriority;
		static const WString atr_DefaultRenderingIntent;
		static const WString atr_DefaultTrapping;
		static const WString atr_DefaultValue;
		static const WString atr_DeliveryMode;
		static const WString atr_DeliveryUnit;
		static const WString atr_DeliveryUnit0;
		static const WString atr_DeliveryUnit1;
		static const WString atr_DeliveryUnit2;
		static const WString atr_DeliveryUnit3;
		static const WString atr_DeliveryUnit4;
		static const WString atr_DeliveryUnit5;
		static const WString atr_DeliveryUnit6;
		static const WString atr_DeliveryUnit7;
		static const WString atr_DeliveryUnit8;
		static const WString atr_DeliveryUnit9;
		static const WString atr_Density;
		static const WString atr_DensityStandard;
		static const WString atr_DependentMacroRef;
		static const WString atr_Depth;
		static const WString atr_DescriptionType;
		static const WString atr_DescriptiveName;
		static const WString atr_DetectBlend;
		static const WString atr_DevCapRef;
		static const WString atr_DevCapRefs;
		static const WString atr_DevCapsRef;
		static const WString atr_DeviceCondition;
		static const WString atr_DeviceDetails;
		static const WString atr_DeviceFamily;
		static const WString atr_DeviceID;
		static const WString atr_DeviceModuleIndex;
		static const WString atr_DeviceOperationMode;
		static const WString atr_DeviceStatus;
		static const WString atr_DeviceType;
		static const WString atr_DevNS;
		static const WString atr_Diameter;
		static const WString atr_DifferentBoxSize;
		static const WString atr_Diffusion;
		static const WString atr_DigitalDeliveryDirection;
		static const WString atr_DigitalDeliveryProtocol;
		static const WString atr_Dimension;
		static const WString atr_Dimensions;
		static const WString atr_Direction;
		static const WString atr_Directory;
		static const WString atr_DirectProof;
		static const WString atr_DirectProofAmount;
		static const WString atr_DisplayTraps;
		static const WString atr_Disposition;
		static const WString atr_DispositionAction;
		static const WString atr_DispositionUsage;
		static const WString atr_Distance;
		static const WString atr_DividePositions;
		static const WString atr_DocCopies;
		static const WString atr_DocIndex;
		static const WString atr_DocNames;
		static const WString atr_DocOrd;
		static const WString atr_DocRunIndex;
		static const WString atr_Docs;
		static const WString atr_DocSheetIndex;
		static const WString atr_DocTags;
		static const WString atr_DocumentCompression;
		static const WString atr_DocumentCorruption;
		static const WString atr_DocumentEncoding;
		static const WString atr_DocumentIsGoodCompression;
		static const WString atr_DocumentNaturalLang;
		static const WString atr_DocumentPDLType;
		static const WString atr_DotGain;
		static const WString atr_DoThumbnails;
		static const WString atr_DotSize;
		static const WString atr_DoubleFeedQuality;
		static const WString atr_DoubleFeeds;
		static const WString atr_DownsampleImages;
		static const WString atr_DraftOK;
		static const WString atr_Drying;
		static const WString atr_DueLevel;
		static const WString atr_Duration;

		// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //
		
		static const WString atr_Earliest;
		static const WString atr_EarlyChange;
		static const WString atr_EdgeAngle;
		static const WString atr_EdgeShape;
		static const WString atr_Editable;
		static const WString atr_Edition;
		static const WString atr_EditionVersion;
		static const WString atr_EffectiveResolution;
		static const WString atr_Effort;
		static const WString atr_ElementID;
		static const WString atr_ElementIDs;
		static const WString atr_ElementPages;
		static const WString atr_ElementType;
		static const WString atr_EmbedAllFonts;
		static const WString atr_EmbeddedPS;
		static const WString atr_EmbeddingRestrictionFlag;
		static const WString atr_EmbedJobOptions;
		static const WString atr_EmbossingType;
		static const WString atr_EmitDSCWarnings;
		static const WString atr_EmitPDFBG;
		static const WString atr_EmitPDFHalftones;
		static const WString atr_EmitPDFTransfers;
		static const WString atr_EmitPDFUCR;
		static const WString atr_EmployeeInfo;
		static const WString atr_Enabled;
		static const WString atr_EncodeColorImages;
		static const WString atr_EncodedByteAlign;
		static const WString atr_EncodeImages;
		static const WString atr_Encoding;
		static const WString atr_EncodingDetails;
		static const WString atr_EncryptedDocument;
		static const WString atr_EncryptionFilter;
		static const WString atr_EncryptionLength;
		static const WString atr_EncryptionRestrictions;
		static const WString atr_EncryptionSubFilter;
		static const WString atr_EncryptionV;
		static const WString atr_End;
		static const WString atr_EndOfBlock;
		static const WString atr_EndOfBundleItem;
		static const WString atr_EndOfDocument;
		static const WString atr_EndOfLine;
		static const WString atr_EndOfSet;
		static const WString atr_EndPage;
		static const WString atr_EndStatus;
		static const WString atr_EndTime;
		static const WString atr_ErrorCount;
		static const WString atr_ErrorCorrectionLevel;
		static const WString atr_ErrorID;
		static const WString atr_ErrorState;
		static const WString atr_ErrorType;
		static const WString atr_ErrorURL;
		static const WString atr_EstimatedJPEGQuality;
		static const WString atr_EventID;
		static const WString atr_EventValue;
		static const WString atr_Exact;
		static const WString atr_ExecutionPolicy;
		static const WString atr_Expires;
		static const WString atr_Extent;
		static const WString atr_ExternalReferenceMissing;
		static const WString atr_ExtraDuration;
		
		// FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF//

		static const WString atr_Failed;
		static const WString atr_Family;
		static const WString atr_FamilyName;
		static const WString atr_FeederSynchronization;
		static const WString atr_FeederType;
		static const WString atr_FieldRange;
		static const WString atr_File;
		static const WString atr_FileFormat;
		static const WString atr_FileName;
		static const WString atr_FilePath;
		static const WString atr_FilePerPage;
		static const WString atr_FileSize;
		static const WString atr_FileTargetDeviceModel;
		static const WString atr_FileTemplate;
		static const WString atr_FileVersion;
		static const WString atr_FillColorName;
		static const WString atr_FillColorType;
		static const WString atr_FillMaterial;
		static const WString atr_FinishedPage;
		static const WString atr_FinishedPageOrientation;
		static const WString atr_FinishingOrder;
		static const WString atr_Finishings;
		static const WString atr_FirstEnd;
		static const WString atr_FirstName;
		static const WString atr_FirstPage;
		static const WString atr_FirstStart;
		static const WString atr_FirstSurface;
		static const WString atr_FitToPage;
		static const WString atr_FixExpression;

		static const WString atr_Flatness;
		static const WString atr_FlexValue;
		static const WString atr_FlipBackCover;
		static const WString atr_FlushPolicy;
		static const WString atr_Flute;
		static const WString atr_FluteDirection;

		static const WString atr_FoldCatalog;
		static const WString atr_FoldCatalogOrientation;
		static const WString atr_FolderModuleIndex;
		static const WString atr_FoldingWidth;
		static const WString atr_FoldIndex;
		static const WString atr_FoldOutPages;
		static const WString atr_Folds;
		static const WString atr_FoldSheetIn;
		static const WString atr_Folio;
		static const WString atr_FolioCount;
		static const WString atr_Font;
		static const WString atr_FontCorrupted;
		static const WString atr_FontCreator;
		static const WString atr_FontEmbedded;
		static const WString atr_FontIsStandardLatin;
		static const WString atr_FontName;
		static const WString atr_FontNotUsed;
		static const WString atr_FontSize;
		static const WString atr_FontSubset;
		static const WString atr_FontType;
		static const WString atr_FontVendor;
		static const WString atr_ForceFrontSide;
		static const WString atr_ForceSeparations;
		static const WString atr_Format;
		static const WString atr_FountainNumber;
		static const WString atr_FountainPositions;
		static const WString atr_FountainSolution;
		static const WString atr_FrameHeight;
		static const WString atr_FrameWidth;
		static const WString atr_Frequency;
		static const WString atr_FriendlyName;
		static const WString atr_From;
		static const WString atr_FromBox;
		static const WString atr_FrontCoatings;
		static const WString atr_FrontFacePages;
		static const WString atr_FrontFoldIn;
		static const WString atr_FrontGlossValue;
		static const WString atr_FrontMarkList;
		static const WString atr_FrontOverfold;
		static const WString atr_FrontPages;
		static const WString atr_FrontSide;
		
		static const WString atr_GangName;
		static const WString atr_GangNames;
		static const WString atr_GangPolicy;
		static const WString atr_GapList;
		static const WString atr_GeneratePageStreams;
		static const WString atr_GenericAttributes;
		static const WString atr_GlueBrand;
		static const WString atr_GlueLineRefSheets;
		static const WString atr_GlueLineWidth;
		static const WString atr_GlueType;
		static const WString atr_GluingPattern;
		static const WString atr_GluingProductionID;
		static const WString atr_GluingTechnique;
		static const WString atr_Grade;
		static const WString atr_GrainDirection;
		static const WString atr_GrossWeight;		
		static const WString atr_GroupBy;		
		static const WString atr_Gutter;
		static const WString atr_GutterMinimumLimit;
		static const WString atr_GutterPolicy;

		static const WString atr_HalfTone;
		static const WString atr_Halftone;
		static const WString atr_Halftoned;
		static const WString atr_HalftoneName;
		static const WString atr_HalftonePhase;
		static const WString atr_HalfTonePhase; // bug fix in JDF 1.3
		static const WString atr_HalfTonePhaseOrigin;
		static const WString atr_HardenerType;
		static const WString atr_HasBleeds;
		static const WString atr_HasColorLUT;
		static const WString atr_HasDefault;
		static const WString atr_HasExternalReference;
		static const WString atr_HasFillColor;
		static const WString atr_HasOPI;
		static const WString atr_HasPrice;
		static const WString atr_HasSoftMask;
		static const WString atr_HasStrokeColor;
		static const WString atr_Height;
		static const WString atr_HelpText;
		static const WString atr_Hold;
		static const WString atr_HoleCount;
		static const WString atr_HoleReferenceEdge;
		static const WString atr_HoleType;
		static const WString atr_HonorPDFOverprint;
		static const WString atr_HorizontalCreep;
		static const WString atr_HorizontalExcess;
		static const WString atr_HotFolder;
		static const WString atr_HourCounter;
		static const WString atr_HSamples;
		static const WString atr_HttpGet;
		static const WString atr_HuffTable;
		static const WString atr_HWRelation;

		// IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII //
		
		static const WString atr_ICCColorAsDeviceColor;
		static const WString atr_ICCProfileSubFolder;
		static const WString atr_ICCProfileUsage;
		static const WString atr_ICCOutputProfileUsage;
		static const WString atr_IconUsage;
		static const WString atr_ICSVersions;
		static const WString atr_Identifier;
		static const WString atr_IDPAttributeFidelity;
		static const WString atr_IDUsage;
		static const WString atr_IDValue;
		static const WString atr_IgnoreAnnotForms;
		static const WString atr_IgnoreBG;
		static const WString atr_IgnoreColorSeps;
		static const WString atr_IgnoreDeviceExtGState;
		static const WString atr_IgnoreDSC;
		static const WString atr_IgnoreEmbeddedICC;
		static const WString atr_IgnoreExtensions;
		static const WString atr_IgnoreExternStreamRef;
		static const WString atr_IgnoreFileParams;
		static const WString atr_IgnoreHalftones;
		static const WString atr_IgnoreOverprint;
		static const WString atr_IgnorePageRotation;
		static const WString atr_IgnorePDLCopies;
		static const WString atr_IgnorePDLImposition;
		static const WString atr_IgnoreRawData;
		static const WString atr_IgnoreSeparableImagesOnly;
		static const WString atr_IgnoreShowPage;
		static const WString atr_IgnoreSourceFile;
		static const WString atr_IgnoreTransfers;
		static const WString atr_IgnoreTTFontsFirst;
		static const WString atr_IgnoreUCR;
		static const WString atr_Illumination;
		static const WString atr_ImageAutoFilterStrategy;
		static const WString atr_ImagableSide;
		static const WString atr_ImageDepth;
		static const WString atr_ImageDownsampleThreshold;
		static const WString atr_ImageDownsampleType;
		static const WString atr_ImageFilter;
		static const WString atr_ImageFlipped;
		static const WString atr_ImageInternalTrapping;
		static const WString atr_ImageMaskTrapping;
		static const WString atr_ImageMaskType;
		static const WString atr_ImageMemory;
		static const WString atr_ImagePreScanStrategy;
		static const WString atr_ImageReplacementStrategy;
		static const WString atr_ImageResolution;
		static const WString atr_ImageRotation;
		static const WString atr_ImageScalingRatio;
		static const WString atr_ImageSize;
		static const WString atr_ImageSkew;
		static const WString atr_ImagesSubFolder;
		static const WString atr_ImageToImageTrapping;
		static const WString atr_ImageToObjectTrapping;
		static const WString atr_ImageTrapPlacement;
		static const WString atr_ImageTrapWidth;
		static const WString atr_ImageTrapWidthY;
		static const WString atr_ImageType;
		static const WString atr_ImageViewingStrategy;
		static const WString atr_ImplicitGutter;
		static const WString atr_ImplicitGutterMinimumLimit;
		static const WString atr_IncludeBaseFonts;
		static const WString atr_IncludeCIDFonts;
		static const WString atr_IncludeEmbeddedFonts;
		static const WString atr_IncludeInBundleItem;
		static const WString atr_IncludeItemInBundle;
		static const WString atr_IncludeOCG;
		static const WString atr_IncludeOtherResources;
		static const WString atr_IncludeProcSets;
		static const WString atr_IncludeTrueTypeFonts;
		static const WString atr_IncludeType1Fonts;
		static const WString atr_IncludeType3Fonts;
		static const WString atr_IncorrectComponentQuality;
		static const WString atr_IncorrectComponents;
		static const WString atr_Independent;
		static const WString atr_InitialPageSize;
		static const WString atr_InitialResolution;
		static const WString atr_InkCoverage;
		static const WString atr_InkName;
		static const WString atr_InkState;
		static const WString atr_InputBox;
		static const WString atr_InputField;
		static const WString atr_InsertError;
		static const WString atr_InsertLocation;
		static const WString atr_InsertOK;
		static const WString atr_InsideBox;
		static const WString atr_InsideLoss;
		static const WString atr_Instrumentation;
		static const WString atr_IntegerValue;
		static const WString atr_Interleaved;
		static const WString atr_Interleaving;
		static const WString atr_IPPJobPriority;
		static const WString atr_IPPVersion;
		static const WString atr_IsBlank;
		static const WString atr_IsDevice;
		static const WString atr_IsFontScreenOnly;
		static const WString atr_IsPage;
		static const WString atr_IsPrintable;
		static const WString atr_IsTrapped;
		static const WString atr_IsWaste;
		static const WString atr_Item;
		static const WString atr_ItemName;
		static const WString atr_ItemNames;

		// JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ//
		
		static const WString atr_JBIG2Lossless;
		static const WString atr_JDFDetails;
		static const WString atr_JDFErrorURL;
		static const WString atr_JDFInputURL;
		static const WString atr_JDFOutputURL;
		static const WString atr_JMFRole;
		static const WString atr_JMFSenderID;
		static const WString atr_JMFURL;
		static const WString atr_JDFVersions;
		static const WString atr_JobDetails;
		static const WString atr_JobID;
		static const WString atr_JobPartID;
		static const WString atr_JobPriority;
		static const WString atr_JobTitle;
		static const WString atr_JogEdge;
		static const WString atr_JogSide;
		static const WString atr_JointWidth;
		static const WString atr_JPXQuality;
		static const WString atr_jRef;
		static const WString atr_jRefDestination;
		static const WString atr_jRefSource;

		// KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK //
		
		static const WString atr_K;
		static const WString atr_Key;
		static const WString atr_Keywords;
		static const WString atr_KnownLocalizations;
		static const WString atr_KnockOutCMYKWhite;
		
		// LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL//
		
		static const WString atr_Lab;
		static const WString atr_LabColorValue;
		static const WString atr_LaborType;
		static const WString atr_LaminatingBox;
		static const WString atr_LaminatingMethod;
		static const WString atr_Lang;
		static const WString atr_Language;
		static const WString atr_LastCount;
		static const WString atr_LastEnd;
		static const WString atr_LastRepeat;
		static const WString atr_LastStart;
		static const WString atr_LayerAmount;
		static const WString atr_LayerID;
		static const WString atr_LayerIDs;
		static const WString atr_LayerRates;
		static const WString atr_Layers;
		static const WString atr_LayersPerTile;
		static const WString atr_LayoutElementPageNum;
		static const WString atr_LeadingEdge;
		static const WString atr_Length;
		static const WString atr_LengthOverall;
		static const WString atr_Level;
		static const WString atr_Light;
		static const WString atr_Linearized;
		static const WString atr_LineArtBlackLevel;
		static const WString atr_LineWidth;
		static const WString atr_LinkUsage;
		static const WString atr_ListCommands;
		static const WString atr_ListPolicy;
		static const WString atr_ListQueries;
		static const WString atr_ListRegistrations;
		static const WString atr_ListSignals;
		static const WString atr_ListType;
		static const WString atr_Loading;
		static const WString atr_Localization;
		static const WString atr_Location;
		static const WString atr_LocationName;
		static const WString atr_Locator;
		static const WString atr_LocID;
		static const WString atr_LockDistillerParams;
		static const WString atr_Locked;
		static const WString atr_LockOrigins;
		static const WString atr_LogicalPage;
		static const WString atr_LogicalPrinterSection;
	static const WString atr_LogicalStackOrd;
		static const WString atr_LogErrors;
		static const WString atr_LotControl;
		static const WString atr_LotID;

		// MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM //
		
		static const WString atr_MacroRefs;
		static const WString atr_Magnification;
		static const WString atr_ManualFeed;
		static const WString atr_Manufacturer;
		static const WString atr_ManufacturerURL;
		static const WString atr_MappingSelection;
		static const WString atr_MarginBottom;
		static const WString atr_MarginLeft;
		static const WString atr_MarginRight;
		static const WString atr_MarginTop;
		static const WString atr_MarkJustification;
		static const WString atr_MarkList;
		static const WString atr_MarkName;
		static const WString atr_MarkOffset;
		static const WString atr_MarkOrientation;
		static const WString atr_MarkPosition;
		static const WString atr_MarkSide;
		static const WString atr_MarkType;
		static const WString atr_MarkUsage;
		static const WString atr_Mask;
		static const WString atr_MaskBleed;
		static const WString atr_Masking;
		static const WString atr_MaskSeparation;
		static const WString atr_Material;
		static const WString atr_MaxAmount;
		static const WString atr_MaxCleanup;
		static const WString atr_MaxDiameter;
		static const WString atr_MaxDocOrd;
		static const WString atr_MaxEntries;
		static const WString atr_MaxGroups;
		static const WString atr_MaxHeat;
		static const WString atr_MaxHeight;
		static const WString atr_MaxOccurrences;
		static const WString atr_MaxOccurs;
		static const WString atr_MaxOrd;
		static const WString atr_MaxPerGroup;
		static const WString atr_MaxResolution;
		static const WString atr_MaxSearchRecursion;
		static const WString atr_MaxSetOrd;
		static const WString atr_MaxSetup;
		static const WString atr_MaxSubsetPct;
		static const WString atr_MaxVersion;
		static const WString atr_MaxWeight;
		static const WString atr_MaxWidth;

		static const WString atr_MeasurementFilter;
		static const WString atr_MediaColorName;
		static const WString atr_MediaColorNameDetails;
		static const WString atr_MediaLabel;
		static const WString atr_MediaLocation;
		static const WString atr_MediaSetCount;
		static const WString atr_MediaSide;
		static const WString atr_MediaType;
		static const WString atr_MediaTypeDetails;
		static const WString atr_MediaUnit;
		static const WString atr_MeltingTemperature;
		static const WString atr_MergeID;
		static const WString atr_MergeTarget;
		static const WString atr_MessageEvents;
		static const WString atr_MessageID;
		static const WString atr_MessageRefID;
		static const WString atr_MessageType;
		static const WString atr_Method;

		static const WString atr_MillingDepth;
		static const WString atr_MilestoneType;
		static const WString atr_MIME;
		static const WString atr_MIMEType; // retained for backward compatibility with buggy schema. Implementation maps to MimeType
		static const WString atr_MimeType;
		static const WString atr_MimeTypeVersion;
		static const WString atr_MinAmount;
		static const WString atr_MinApprovals;
		static const WString atr_MinCleanup;
		static const WString atr_MinDelayTime;
		static const WString atr_MinDuration;
		static const WString atr_MinGutter;
		static const WString atr_MinimumBlackWidth;
		static const WString atr_MinimumWait;
		static const WString atr_MinLateStatus;
		static const WString atr_MinOccurs;
		static const WString atr_MinResolution;
		static const WString atr_MinSetup;
		static const WString atr_MinStatus;
		static const WString atr_MirrorAround;
		static const WString atr_MirrorMargins;
		static const WString atr_MissingPrinterFont;
		static const WString atr_MissingScreenFont;
		static const WString atr_ModelDescription;
		static const WString atr_ModelName;
		static const WString atr_ModelNumber;
		static const WString atr_ModelURL;
		static const WString atr_Modification;
		static const WString atr_ModificationDate;
		static const WString atr_ModificationDateInDocument;
		static const WString atr_ModificationID;
		static const WString atr_ModuleAvailableIndex;
		static const WString atr_ModuleDrying;
		static const WString atr_ModuleHeight;
		static const WString atr_ModuleID;
		static const WString atr_ModuleIndex;
		static const WString atr_ModuleRefs;
		static const WString atr_ModuleType;
		static const WString atr_ModuleWidth;
		static const WString atr_MountID;
		static const WString atr_Mounting;
		static const WString atr_MustHonorExceptions;
		
		static const WString atr_N;
		static const WString atr_Name;
		static const WString atr_NamedFeatures;
		static const WString atr_NamePrefix;
		static const WString atr_NameSpace;
		static const WString atr_NameSuffix;
		static const WString atr_NaturalLang;
		static const WString atr_NDoc;
		static const WString atr_NeedlePositions;
		static const WString atr_NeutralDensity;
		static const WString atr_NeverEmbed;
		static const WString atr_NewerThan;
		static const WString atr_NewSpawnID;
		static const WString atr_NewTime;
		static const WString atr_NewValue;
		static const WString atr_NextQueueEntryID;
		static const WString atr_NodeID;
		static const WString atr_NipWidth;
		static const WString atr_NodeStatus;
		static const WString atr_NodeStatusDetails;
		static const WString atr_NonPrintableMarginBottom;
		static const WString atr_NonPrintableMarginLeft;
		static const WString atr_NonPrintableMarginRight;
		static const WString atr_NonPrintableMarginTop;
		static const WString atr_NoOp;
		static const WString atr_NotchingDepth;
		static const WString atr_NotchingDistance;
		static const WString atr_NPage;
		static const WString atr_NSet;
		static const WString atr_Number;
		static const WString atr_NumberOfColorsInLUT;
		static const WString atr_NumberOfNeedles;
		static const WString atr_NumberOfPages;
		static const WString atr_NumberOfPathPoints;
		static const WString atr_NumberOfStitches;
		static const WString atr_NumberUp;
		static const WString atr_NumberValue;
		static const WString atr_NumResolutions;

		// OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO //
		
		static const WString atr_Obligated;
		static const WString atr_Observer;
		static const WString atr_ObservationPath;
		static const WString atr_Occurrences;
		static const WString atr_OCGDefault;
		static const WString atr_OCGIntent;
		static const WString atr_OCGName;
		static const WString atr_OCGProcess;
		static const WString atr_OCGZoom;
		static const WString atr_OfferRange;
		static const WString atr_Offset;
		static const WString atr_OffsetAmount;
		static const WString atr_OffsetDirection;
		static const WString atr_OlderThan;
		static const WString atr_OldTime;
		static const WString atr_OldValue;
		static const WString atr_Opacity;
		static const WString atr_OpacityLevel;
		static const WString atr_Opening;
		static const WString atr_Operation;
		static const WString atr_Operations;
		static const WString atr_OperatorInterventionExceptions;
		static const WString atr_OperatorText;
		static const WString atr_OPIMissing;
		static const WString atr_OPIType;
		static const WString atr_OPIVersion;
		static const WString atr_Optimize;
		static const WString atr_Option;
		static const WString atr_OptionalCombinedTypes;
		static const WString atr_Ord;
		static const WString atr_Order;
		static const WString atr_OrderedAmount;
		static const WString atr_OrdExpression;
		static const WString atr_OrdID;
		static const WString atr_OrganizationName;
		static const WString atr_Orientation;
		static const WString atr_OriginalResolution;
		static const WString atr_OSVersion;
		static const WString atr_OuterCoreDiameter;
		static const WString atr_OutputBin;
		static const WString atr_OutputColorSpace;
		static const WString atr_OutputIntentColorSpace;
		static const WString atr_OutputIntentStandard;
		static const WString atr_OutputPreferencesSubFolder;
		static const WString atr_OutputResolution;
		static const WString atr_OutputSize;
		static const WString atr_OutputType;
		static const WString atr_OutsideBox;
		static const WString atr_OutsideGain;
		static const WString atr_OutsideGutter;
		static const WString atr_Overfold;
		static const WString atr_OverfoldSide;
		static const WString atr_Overlap;
		static const WString atr_OverPrintBlackLineArt;
		static const WString atr_OverPrintBlackText;
		static const WString atr_OverPrintFlag; // bug fix
		static const WString atr_OverprintFlag;
		static const WString atr_OverprintMode;
		static const WString atr_OverPrintMode;
		static const WString atr_OverwritePolicy;
		static const WString atr_Ownership;

		// PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP //
		
		static const WString atr_Packaging;
		static const WString atr_Page;
		static const WString atr_PageBoxType;
		static const WString atr_PageCopies;
		static const WString atr_PageDelivery;
		static const WString atr_PageDistributionScheme;
		static const WString atr_PageFormat;
		static const WString atr_PageHasUnknownObjects;
		static const WString atr_PageIndex;
		static const WString atr_PageLabel;
		static const WString atr_PageLabelPrefix;
		static const WString atr_PageLabelSuffix;
		static const WString atr_PageList;
		static const WString atr_PageListIndex;
		static const WString atr_PageNames;
		static const WString atr_PageNumber;
		static const WString atr_PageOrder;
		static const WString atr_PageRefs;
		static const WString atr_PagePlacementName;
		static const WString atr_Pages;
		static const WString atr_PageSet;
		static const WString atr_PagesHaveSameOrientation;
		static const WString atr_PagesPageNumber;
		static const WString atr_PageStatus;
		static const WString atr_PageTags;
		static const WString atr_PalletMaxHeight;
		static const WString atr_PalletMaxWeight;
		static const WString atr_PalletQuantity;
		static const WString atr_PalletSize;
		static const WString atr_PalletType;
		static const WString atr_PalletWrapping;
		static const WString atr_ParentFolio;
		static const WString atr_ParentJobID;
		static const WString atr_ParentJobPartID;
		static const WString atr_ParseDSCComments;
		static const WString atr_ParseDSCCommentsForDocInfo;
		static const WString atr_PartIDKeys;
		static const WString atr_PartUsage;	
		static const WString atr_PartVersion;
		static const WString atr_Passed;
		static const WString atr_PassThroughJPEGImages;
		static const WString atr_Password;
		static const WString atr_Path;
		static const WString atr_Pattern;
		static const WString atr_PDFVersion;
		static const WString atr_PDFX1aCheck;
		static const WString atr_PDFX3Check;
		static const WString atr_PDFXCompliantPDFOnly;
		static const WString atr_PDFXNoTrimBoxError;
		static const WString atr_PDFXTrimBoxToMediaBoxOffset;
		static const WString atr_PDFXSetBleedBoxToMediaBox;
		static const WString atr_PDFXBleedBoxToTrimBoxOffset;
		static const WString atr_PDFXOutputIntentProfile;
		static const WString atr_PDFXOutputCondition;
		static const WString atr_PDFXRegistryName;
		static const WString atr_PDFXTrapped;
		static const WString atr_PDFXVersion;
		static const WString atr_PDLType;
		static const WString atr_PDLVersion;
		static const WString atr_Percentage;
		static const WString atr_Percentages;
		static const WString atr_PercentCompleted;
		static const WString atr_PerfectingModule;
		static const WString atr_Persistent;
		static const WString atr_PersonalID;
		static const WString atr_PhaseAmount;
		static const WString atr_PhaseStartTime;
		static const WString atr_PhaseWaste;
		static const WString atr_PhysicalSection;
		static const WString atr_Pickup;
		static const WString atr_PipeID;
		static const WString atr_PipePartIDKeys;
		static const WString atr_PipePause;
		static const WString atr_PipeProtocol;
		static const WString atr_PipeResume;
		static const WString atr_PipeURL;
		static const WString atr_Pitch;
		static const WString atr_PixelDepth;
		static const WString atr_PixelHeight;
		static const WString atr_PixelSkip;
		static const WString atr_PixelWidth;
		static const WString atr_PlateLayout;
		static const WString atr_PlatePosition;
		static const WString atr_PlateTechnology;
		static const WString atr_PlateType;
		static const WString atr_PlateUsage;
		static const WString atr_Polarity;
		static const WString atr_PolarityChange;
		static const WString atr_Position;
		static const WString atr_PositionX;
		static const WString atr_PositionY;
		static const WString atr_PostalCode;
		static const WString atr_PostBakeTemp;
		static const WString atr_PostBakeTime;
		static const WString atr_PostBox;
		static const WString atr_PostCompressionEncoding;
		static const WString atr_Poster;
		static const WString atr_PosterOverlap;
		static const WString atr_PostExposeTime;
		static const WString atr_Powder;
		static const WString atr_PowerOnTime;
		static const WString atr_PreCompressionIndividualEncoding;
		static const WString atr_Predictor;
		static const WString atr_Preferred;	
		static const WString atr_PreferredFont;
		static const WString atr_PreflightActionList;
		static const WString atr_PreflightOutput;
		static const WString atr_PreflightProfile;
		static const WString atr_PreflightRule;
		static const WString atr_PreflightStatus;
		static const WString atr_PreflightTool;
		static const WString atr_PreflightToolVersion;
		static const WString atr_PreHeatTemp;
		static const WString atr_PreHeatTime;
		static const WString atr_PrePrinted;
		static const WString atr_PresentationDirection;
		static const WString atr_PresentationURL;
		static const WString atr_PresentHWRelation;
		static const WString atr_PresentLength;
		static const WString atr_PresentRegExp;
		static const WString atr_PresentRotateMod;
		static const WString atr_PresentShift;
		static const WString atr_PresentTransforms;
		static const WString atr_PresentValue;
		static const WString atr_PresentValueDurationList;
		static const WString atr_PresentValueList;
		static const WString atr_PresentValueMax;
		static const WString atr_PresentValueMin;
		static const WString atr_PresentValueMod;
		static const WString atr_PresentX;
		static const WString atr_PresentXYRelation;
		static const WString atr_PresentY;
		static const WString atr_PresentZ;
		static const WString atr_PreserveBlack;
		static const WString atr_PreserveCopyPage;
		static const WString atr_PreserveEPSInfo;
		static const WString atr_PreserveHalftoneInfo;
		static const WString atr_PreserveOPIComments;
		static const WString atr_PreserveOverprintSettings;
		static const WString atr_PreviewFileType;
		static const WString atr_PreviewType;
		static const WString atr_PreviewUsage;
		static const WString atr_PrevQueueEntryID;
		static const WString atr_Price;
		static const WString atr_PrintableArea;
		static const WString atr_PrintTrapAnnotations;
		static const WString atr_PrintConditionName;
		static const WString atr_PrinterFontsSubFolder;
		static const WString atr_PrintingType;
		static const WString atr_PrintPDFAnnotations;
		static const WString atr_PrintQuality;
		static const WString atr_Priority;
		static const WString atr_ProcessColorModel;
		static const WString atr_ProcessUsage;
		static const WString atr_Producer;
		static const WString atr_ProductID;	
		static const WString atr_ProductionAmount;
		static const WString atr_ProductionCounter;
		static const WString atr_ProductionPathID;
		static const WString atr_ProductionType;
		static const WString atr_ProductType;
		static const WString atr_ProductTypeDetails;
		static const WString atr_ProgressionOrder;
		static const WString atr_ProjectID;
		static const WString atr_Proof;
		static const WString atr_ProofName;
		static const WString atr_ProofQuality;
		static const WString atr_ProofRenderingIntent;
		static const WString atr_ProofTarget;
		static const WString atr_ProofType;
		static const WString atr_Property;
		static const WString atr_PropertyList;
		static const WString atr_PSFontName;
		static const WString atr_PSLevel;
		static const WString atr_PullOutValue;
		static const WString atr_Punch;
		static const WString atr_PunchType;
		static const WString atr_Purpose;
		static const WString atr_PurposeDetails;

		// QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ //
		
		static const WString atr_QFactor;
		static const WString atr_QuantTable;
		static const WString atr_Query;
		static const WString atr_QueueEntryID;
		static const WString atr_QueueEntryDetails;
		static const WString atr_QueueInfo;
		static const WString atr_QueueSize;
		static const WString atr_QueueURL;

		// RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR //
		
		static const WString atr_Range;
		static const WString atr_Ratio;
		static const WString atr_RawAlias;
		static const WString atr_RawName;	
		static const WString atr_ReaderPageCount;
		static const WString atr_Reason;
		static const WString atr_ReceiverURL;
		static const WString atr_Recommendation;
		static const WString atr_Records;
		static const WString atr_Recycled;
		static const WString atr_RecycledPercentage;
		static const WString atr_ref;
		static const WString atr_ReferenceEdge;
		static const WString atr_refID;
		static const WString atr_RegExp;
		static const WString atr_Region;
		static const WString atr_Registration;
		static const WString atr_RelativeBox;
		static const WString atr_RelatedJobID;
		static const WString atr_RelatedJobPartID;
		static const WString atr_RelativeStartPosition;
		static const WString atr_RelativeTravel;
		static const WString atr_RelativeWorkingPath;
		static const WString atr_RelativeWorkingPattern;
		static const WString atr_RemotePipeEndPause;
		static const WString atr_RemotePipeEndResume;
		static const WString atr_RenderingIntent;
		static const WString atr_RepeatPolicy;
		static const WString atr_RepeatStep;
		static const WString atr_RepeatTime;
		static const WString atr_ReplaceField;
		static const WString atr_ReplacementColorantName;
		static const WString atr_ReportAttr;
		static const WString atr_Required;
		static const WString atr_RequestQuality;
		static const WString atr_Resend;
		static const WString atr_ResponseURL;
		static const WString atr_Resolution;
		static const WString atr_ResolutionReductionStrategy;
		static const WString atr_ResourceID;
		static const WString atr_ResourceName;
		static const WString atr_ResourceType;
		static const WString atr_ResourceUpdate;
		static const WString atr_ResourceUsage;
		static const WString atr_ResourceWeight;
		static const WString atr_RestoreTime;
		static const WString atr_RestTime;

		static const WString atr_Retention;
		static const WString atr_ReturnCode;
		static const WString atr_ReturnJMF;
		static const WString atr_ReturnList;
		static const WString atr_ReturnURL;
		static const WString atr_ReversePageNumber;
		static const WString atr_RGB2GrayBlack;
		static const WString atr_RGBGray2Black;
		static const WString atr_RGBGray2BlackThreshold;
		static const WString atr_RibbonColor;
		static const WString atr_RibbonEnd;
		static const WString atr_RibbonName;
		static const WString atr_RingDiameter;
		static const WString atr_RingMechanic;
		static const WString atr_RingShape;
		static const WString atr_RingSystem;
		static const WString atr_RivetsExposed;
		static const WString atr_Roles;
		static const WString atr_RollCut;
		static const WString atr_RollDiameter;
		static const WString atr_Rotate;
		static const WString atr_RotateMod;
		static const WString atr_RotatePolicy;
		static const WString atr_Rotation;
		static const WString atr_Rounding;
		static const WString atr_Route;
		static const WString atr_Rows;
		static const WString atr_RowsPerStrip;
		static const WString atr_rRef;
		static const WString atr_rRefs;
		static const WString atr_rRefsOverwritten;
		static const WString atr_rRefsROCopied;
		static const WString atr_rRefsRWCopied;
		static const WString atr_rSubRef;
		static const WString atr_Run;
		static const WString atr_RunIndex;
		static const WString atr_RunPage;
		static const WString atr_RunSet;
		static const WString atr_RunTag;
		static const WString atr_RunTags;

		// SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS//
		
		static const WString atr_SampleBacking;
		static const WString atr_SampleInterval;
		static const WString atr_Scale;
		static const WString atr_Scaling;
		static const WString atr_ScalingOrigin;
		static const WString atr_Scope;
		static const WString atr_Screen;
		static const WString atr_ScreeningFamily;
		static const WString atr_ScreeningType;
		static const WString atr_ScreenFontsSubFolder;
		static const WString atr_ScreenRuling;
		static const WString atr_ScreenShape;
		static const WString atr_Sealing;
		static const WString atr_SealingTemperature;
		static const WString atr_SearchDepth;
		static const WString atr_SectionIndex;
		static const WString atr_SectionList;
		static const WString atr_SecureJMFURL;
		static const WString atr_Segmentation;
		static const WString atr_Select;
		static const WString atr_SenderID;
		static const WString atr_Separation;
		static const WString atr_SeparationFlag;
		static const WString atr_SeparationList;
		static const WString atr_SeparationNameTag;
		static const WString atr_SerialNumber;
		static const WString atr_ServiceLevel;
		static const WString atr_SetCopies;
		static const WString atr_SetDocIndex;
		static const WString atr_SetIndex;
		static const WString atr_SetNames;
		static const WString atr_SetOrd;
		static const WString atr_SetPageSize;
		static const WString atr_SetRef;
		static const WString atr_SetRunIndex;
		static const WString atr_Sets;
		static const WString atr_SetSheetIndex;
		static const WString atr_SetSplitBy;
		static const WString atr_SetTags;
		static const WString atr_SettingsPolicy;
		static const WString atr_Setup;
		static const WString atr_SetupDuration;
		static const WString atr_SetupProcsets;
		static const WString atr_Severity;
		static const WString atr_SewingPattern;
		static const WString atr_ShadingType;
		static const WString atr_Shape;
		static const WString atr_ShapeDepth;
		static const WString atr_ShapeType;
		static const WString atr_SheetCollate;
		static const WString atr_SheetFormat;
		static const WString atr_SheetIndex;
		static const WString atr_SheetLay;
		static const WString atr_SheetName;
		static const WString atr_SheetOccurence;
		static const WString atr_SheetOffset;
		static const WString atr_SheetPart;
		static const WString atr_SheetType;
		static const WString atr_SheetUsage;
		static const WString atr_Shift;
		static const WString atr_ShiftBack;
		static const WString atr_ShiftFront;
		static const WString atr_ShiftX;
		static const WString atr_ShiftXSide1;
		static const WString atr_ShiftXSide2;
		static const WString atr_ShiftY;
		static const WString atr_ShiftYSide1;
		static const WString atr_ShiftYSide2;
		static const WString atr_ShortValue;
		static const WString atr_ShowList;
		static const WString atr_ShrinkIndex;
		static const WString atr_ShrinkingMethod;
		static const WString atr_ShrinkToFit;
		static const WString atr_ShutDownType;
		static const WString atr_Side;
		static const WString atr_SidelineEPS;
		static const WString atr_SidelineFonts;
		static const WString atr_SidelineImages;
		static const WString atr_Sides;
		static const WString atr_Signal;
		static const WString atr_SignalType;
		static const WString atr_SignalTypes;
		static const WString atr_SignatureName;
		static const WString atr_Size;
		static const WString atr_SizePolicy;
		static const WString atr_SkipPage;
		static const WString atr_SlidingTrapLimit;
		static const WString atr_Smoothness;

		static const WString atr_SortAmount;
		static const WString atr_Sorted;
		static const WString atr_Sorting;
		static const WString atr_SourceBleedBox;
		static const WString atr_SourceClipBox;
		static const WString atr_SourceClipPath;
		static const WString atr_SourceCS;
		static const WString atr_SourceCSs;
		static const WString atr_SourceFrequency;
		static const WString atr_SourceName;
		static const WString atr_SourceObjects;
		static const WString atr_SourceRenderingIntent;
		static const WString atr_SourceRibbon;
		static const WString atr_SourceSheet;
		static const WString atr_SourceTrimBox;
		static const WString atr_SourceWeb;
		static const WString atr_SourceWorkStyle;
		static const WString atr_SpawnID;
		static const WString atr_SpawnIDs;
		static const WString atr_SpawnStatus;
		static const WString atr_SpecialInk;
		static const WString atr_SpecificYield;
		static const WString atr_Speed;
		static const WString atr_Spine;
		static const WString atr_SpineColor;
		static const WString atr_SpineWidth;
		static const WString atr_SplitDocuments;
		static const WString atr_SpotFunction;
		static const WString atr_sRGB;

		static const WString atr_StackDepth;
		static const WString atr_StaggerColumns;
		static const WString atr_StaggerContinuous;
		static const WString atr_StaggerRows;
		static const WString atr_StandardAmount;
		static const WString atr_StapleShape;
		static const WString atr_Start;
		static const WString atr_StartOffset;
		static const WString atr_StartPage;
		static const WString atr_StartPosition;
		static const WString atr_StartTime;
		static const WString atr_StartValue;
		static const WString atr_StationAmount;
		static const WString atr_StationName;
		static const WString atr_Status;
		static const WString atr_StatusList;
		static const WString atr_StatusDetails;
		static const WString atr_Step;
		static const WString atr_StepDocs;
		static const WString atr_StepLimit;
		static const WString atr_StepRepeat;
		static const WString atr_StitchFromFront;
		static const WString atr_StitchingPosition;
		static const WString atr_StitchingReferenceEdge;
		static const WString atr_StitchPositions;
		static const WString atr_StitchType;
		static const WString atr_StitchWidth;
		static const WString atr_StockType;
		static const WString atr_StorageEvent;
		static const WString atr_StoragePeriod;
		static const WString atr_StrapColor;
		static const WString atr_StrappingType;
		static const WString atr_StrapPositions;
		static const WString atr_Street;
		static const WString atr_StringValue;
		static const WString atr_StripBrand;
		static const WString atr_StripColor;
		static const WString atr_StripLength;
		static const WString atr_StripMarkDetails;
		static const WString atr_StripMaterial;
		static const WString atr_StripType;
		static const WString atr_StrokeAlternateColorSpace;
		static const WString atr_StrokeColorName;
		static const WString atr_StrokeColorSpace;
		static const WString atr_StrokeColorType;
		static const WString atr_StrokeOverprintFlag;
		static const WString atr_StrokeShadingType;
		static const WString atr_StrokeThickness;
		static const WString atr_Subject;
		static const WString atr_SubmissionTime;
		static const WString atr_SubmitPolicy;
		static const WString atr_SubModuleIndex;
		static const WString atr_SubRun;
		static const WString atr_Subscribed;
		static const WString atr_SubsetFonts;
		static const WString atr_SuppressCenter;
		static const WString atr_SuppressRotate;
		static const WString atr_SurfaceContentsBox;
		static const WString atr_SurfaceCount;

		// TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT //
		
		static const WString atr_TabBanks;
		static const WString atr_TabsPerBank;
		static const WString atr_TagNumber;
		static const WString atr_TagType;
		static const WString atr_TargetRoute;
		static const WString atr_TeethPerDimension;
		static const WString atr_Temperature;
		static const WString atr_Template;
		static const WString atr_TemplateID;
		static const WString atr_TemplateVersion;
		static const WString atr_TestRef;
		static const WString atr_TextBlackLevel;
		static const WString atr_TextSize;
		static const WString atr_TextSizeThreshold;
		static const WString atr_Texture;
		static const WString atr_Thickness;
		static const WString atr_ThreadBrand;
		static const WString atr_ThreadLength;
		static const WString atr_ThreadMaterial;
		static const WString atr_ThreadPositions;
		static const WString atr_ThreadStitchWidth;
		static const WString atr_ThreadThickness;
		static const WString atr_Ties;
		static const WString atr_TightBacking;
		static const WString atr_TileID;
		static const WString atr_TileSize;
		static const WString atr_Time;
		static const WString atr_TimeInterval;
		static const WString atr_TimeStamp;
		static const WString atr_Title;

		static const WString atr_To;
		static const WString atr_ToBox;
		static const WString atr_Tolerance;
		static const WString atr_ToleranceBlack;
		static const WString atr_ToleranceCyan;
		static const WString atr_ToleranceDotGain;
		static const WString atr_ToleranceMagenta;
		static const WString atr_ToleranceYellow;
		static const WString atr_ToolAmount;
		static const WString atr_ToolID;
		static const WString atr_ToolType;
		static const WString atr_TopBrand;
		static const WString atr_TopColor;
		static const WString atr_TopExcess;
		static const WString atr_TopFoldIn;
		static const WString atr_TopLength;
		static const WString atr_TotalAmount;
		static const WString atr_TotalDimensions;
		static const WString atr_TotalDuration;
		static const WString atr_TotalVolume;
		static const WString atr_TotalWeight;
		static const WString atr_TotalProductionCounter;
		static const WString atr_TrackingID;
		static const WString atr_Transfer;
		static const WString atr_TransferCurve;
		static const WString atr_TransferFunction;
		static const WString atr_TransferFunctionInfo;
		static const WString atr_TransferFunctionSource;
		static const WString atr_Transformation;
		static const WString atr_TransformationContext;
		static const WString atr_Transforms;
		static const WString atr_TransparencyFlag;
		static const WString atr_TransparencyRenderingQuality;
		static const WString atr_TrapColorScaling;
		static const WString atr_TrapEndStyle;
		static const WString atr_TrapJoinStyle;
		static const WString atr_TrapnetAnnotationPDFX;
		static const WString atr_TrappedKey;
		static const WString atr_Trapping;
		static const WString atr_TrappingType;
		static const WString atr_TrapPlacement;
		static const WString atr_TrapWidth;
		static const WString atr_TrapWidthY;
		static const WString atr_TrapZone;
		static const WString atr_Travel;
		static const WString atr_TravelInterval;
		static const WString atr_TrimCover;
		static const WString atr_TrimCTM;
		static const WString atr_TrimFace;
		static const WString atr_TrimFoot;
		static const WString atr_TrimHead;
		static const WString atr_TrimmingOffset;
		static const WString atr_TrimmingType;
		static const WString atr_TrimSize;
		static const WString atr_TTasT42;
		static const WString atr_Tucked;
		static const WString atr_Type;
		static const WString atr_TypeAmount;
		static const WString atr_TypeExpression;
		static const WString atr_TypeOrder;
		static const WString atr_TypeOccurrenceNum;
		static const WString atr_Types;
		
		// UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU//

		static const WString atr_UCRandBGInfo;
		static const WString atr_UID;
		static const WString atr_Uncompressed;
		static const WString atr_UnderColorRemoval;
		static const WString atr_UnderLays;
		static const WString atr_Unit;
		static const WString atr_UnitType;
		static const WString atr_Until;
		static const WString atr_UPC;
		static const WString atr_UpdatedStatus;
		static const WString atr_UpdateID;
		static const WString atr_UpdateIDs;
		static const WString atr_UpdateMethod;
		static const WString atr_URL;
		static const WString atr_URLSchemes;
		static const WString atr_Usage;
		static const WString atr_UseArtificialTextEffect;
		static const WString atr_UseDefaultFont;
		static const WString atr_UseFontAliasNames;
		static const WString atr_UseFontEmulation;
		static const WString atr_UsePDLAlternateCS;
		static const WString atr_UsePrologue;
		static const WString atr_UserDisplay;
		static const WString atr_UserFileName;
		static const WString atr_UserMediaType;
		static const WString atr_UserText;

		// VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV//
		
		static const WString atr_Vacuum;
		static const WString atr_Value;
		static const WString atr_ValueDurationList;
		static const WString atr_ValueFormat;
		static const WString atr_ValueList;
		static const WString atr_ValueMod;
		static const WString atr_ValueRange;
		static const WString atr_ValueTemplate;
		static const WString atr_ValueUsage;
		static const WString atr_Version;
		static const WString atr_VerticalCreep;
		static const WString atr_ViewBinder;
		static const WString atr_VisibleLength;
		static const WString atr_VSamples;

		// WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW//
		
		static const WString atr_WarningCount;
		static const WString atr_WasMarked;
		static const WString atr_Waste;
		static const WString atr_WatchURL;
		static const WString atr_WebName;
		static const WString atr_WebProduct;
		static const WString atr_WebSetup;
		static const WString atr_Weight;
		static const WString atr_WhiteBase;
		static const WString atr_WhiteIsZero;
		static const WString atr_Width;
		static const WString atr_WireBrand;
		static const WString atr_WireGauge;
		static const WString atr_WorkingDirection;
		static const WString atr_WorkingLength;
		static const WString atr_WorkingList;
		static const WString atr_WorkingPath;
		static const WString atr_WorkStyle;
		static const WString atr_WorkType;
		static const WString atr_WorkTypeDetails;
		static const WString atr_WrapPages;
		static const WString atr_WrappedQuantity;
		static const WString atr_WrapperWeight;
		static const WString atr_WrappingKind;
		static const WString atr_WrappingMaterial;

		// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//
		
		static const WString atr_X;
		static const WString atr_XCells;
		static const WString atr_XOffset;
		static const WString atr_XPath;
		static const WString atr_XPosition;
		static const WString atr_XYRelation;
		
		// YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY//
		
		static const WString atr_Y;
		static const WString atr_YCells;
		static const WString atr_YPosition;
		
		// ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ//

		static const WString atr_Z;
		static const WString atr_ZoneHeight;
		static const WString atr_Zones;
		static const WString atr_ZoneSettingsX;
		static const WString atr_ZoneSettingsY;
		static const WString atr_ZonesY;
		static const WString atr_ZoneWidth;
		
		


		static const WString atr_Intent;
		static const WString atr_Params;
		static const WString atr_Link;
		static const WString atr_Pool;
		static const WString atr_Ref;
		static const WString atr_Update;
		
		static const WString atr_true;
		static const WString atr_false;
		
		static const WString atr_Unknown;
			



		static const WString atr_AbsoluteHeight;
static const WString atr_AbsoluteWidth;
static const WString atr_Anchor;

		static const WString atr_Metadata0;
static const WString atr_Metadata1;
static const WString atr_Metadata2;
static const WString atr_Metadata3;
static const WString atr_Metadata4;
static const WString atr_Metadata5;
static const WString atr_Metadata6;
static const WString atr_Metadata7;
static const WString atr_Metadata8;
static const WString atr_Metadata9;

static const WString atr_VarnishMethod;
static const WString atr_TabEdge;
static const WString atr_TabExtensionDistance;
static const WString atr_TabOffset;
static const WString atr_TabSetCollationOrder;
static const WString atr_TabWidth;
static const WString atr_Families;
static const WString atr_MessageTypes;
static const WString atr_InnerDimensions;
static const WString atr_Standard;
static const WString atr_Area;
static const WString atr_DDESCutType;

static const WString atr_AllowedRotate;
static const WString atr_GutterX;
static const WString atr_GutterX2;
static const WString atr_GutterY;
static const WString atr_GutterY2;
static const WString atr_LayoutStyle;
static const WString atr_OrderQuantity;
static const WString atr_UseBleeds;

static const WString atr_AnchorType;
static const WString atr_RestrictedContentObjects;

static const WString atr_PageRange;
static const WString atr_PositionPolicy;
static const WString atr_RelativeSize;
static const WString atr_RotationPolicy;

static const WString atr_Index;


static const WString atr_RunPageRange;

static const WString atr_Estimate;

static const WString atr_SheetHeight;
static const WString atr_SheetWidth;


static const WString atr_URLTypes;
static const WString atr_URLType;
static const WString atr_OrdReset;
static const WString atr_SheetCountReset;
static const WString atr_MaxCollect;
static const WString atr_MinCollect;
static const WString atr_OrdsConsumed;
static const WString atr_SheetNameFormat;
static const WString atr_SheetNameTemplate;

static const WString atr_JobFormat;
static const WString atr_JobTemplate;

static const WString atr_ISBN10;
static const WString atr_ISBN13;

static const WString atr_AuthenticationType;
static const WString atr_ReasonDetails;

static const WString atr_FaceCells;
static const WString atr_ObjectTags;

static const WString atr_IsDoubleByteFont;

static const WString atr_PageHasOptionalContent;
static const WString atr_PageScalingFactor;

static const WString atr_CompensationCTM;
static const WString atr_ContentRef;
static const WString atr_StackOrd;
static const WString atr_TrimClipPath;

static const WString atr_CutWidth;

static const WString atr_ColorDetails;

static const WString atr_InnermostShingling;
static const WString atr_OutermostShingling;


static const WString atr_StripColorDetails;
static const WString atr_StitchOrigin;
static const WString atr_LayerLift;

static const WString atr_LayerCompression;
static const WString atr_PreStackAmount;
static const WString atr_PreStackMethod;
static const WString atr_StackCompression;

static const WString atr_HorizontalExcessBack;

static const WString atr_IgnoreContext;
static const WString atr_SheetSides;

static const WString atr_BinderColorDetails;
static const WString atr_SpineColorDetails;
static const WString atr_RibbonColorDetails;
static const WString atr_MimeTypeDetails;


static const WString atr_Languages;

static const WString atr_Overhang;
static const WString atr_OverhangOffset;

static const WString atr_BackCoatingDetail;
static const WString atr_FrontCoatingDetail;
static const WString atr_MediaQuality;
static const WString atr_PrintingTechnology;
static const WString atr_ReliefThickness;
static const WString atr_SleeveInterlock;

static const WString atr_ContentDataRefs;
static const WString atr_SourceMediaBox;

static const WString atr_TopColorDetails;
static const WString atr_BottomColorDetails;
static const WString atr_ClampColorDetails;

static const WString atr_HorizontalFitPolicy;
static const WString atr_VerticalFitPolicy;

static const WString atr_NUpSeparation;

static const WString atr_SpineThickness;
static const WString atr_RawNames;

static const WString atr_ActualColorName;
static const WString atr_Gray;

static const WString atr_Columns;
static const WString atr_ComponentOrientation;

static const WString atr_AlignmentReferenceWeb;
static const WString atr_FoldLay;
static const WString atr_WebCellAlignment;

static const WString atr_TabCount;


	};
};

#endif // !defined(_JDFSTRINGS_H__)
