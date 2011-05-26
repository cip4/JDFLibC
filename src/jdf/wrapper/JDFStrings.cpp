/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2011 The International Cooperation for the Integration of 
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
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created 04 Oct 2000
// JDFStrings.cpp: wrapper around KElement
//
//////////////////////////////////////////////////////////////////////

#include "jdf/wrapper/JDFStrings.h"


namespace JDF{
	//////////////////////////////////////////////////////////////////////


	// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA //

	const WString JDFStrings::elm_Acknowledge=L"Acknowledge";
	const WString JDFStrings::elm_Action=L"Action";
	const WString JDFStrings::elm_ActionPool=L"ActionPool";
	const WString JDFStrings::elm_Added=L"Added";
	const WString JDFStrings::elm_Address=L"Address";
	const WString JDFStrings::elm_AdhesiveBinding=L"AdhesiveBinding";
	const WString JDFStrings::elm_AdhesiveBindingParams=L"AdhesiveBindingParams";
	const WString JDFStrings::elm_AdvancedParams=L"AdvancedParams";
	const WString JDFStrings::elm_AllowedValue=L"AllowedValue";
	const WString JDFStrings::elm_AllowedValueList=L"AllowedValueList";
	const WString JDFStrings::elm_Amount=L"Amount";
	const WString JDFStrings::elm_AmountPool=L"AmountPool";
	const WString JDFStrings::elm_Ancestor=L"Ancestor";
	const WString JDFStrings::elm_AncestorPool=L"AncestorPool";
	const WString JDFStrings::elm_and=L"and";
	const WString JDFStrings::elm_ApprovalDetails=L"ApprovalDetails";
	const WString JDFStrings::elm_ApprovalParams=L"ApprovalParams";
	const WString JDFStrings::elm_ApprovalPerson=L"ApprovalPerson";
	const WString JDFStrings::elm_ApprovalSuccess=L"ApprovalSuccess";
	const WString JDFStrings::elm_ArgumentValue=L"ArgumentValue";
	const WString JDFStrings::elm_ArtDelivery=L"ArtDelivery";
	const WString JDFStrings::elm_ArtDeliveryDate=L"ArtDeliveryDate";
	const WString JDFStrings::elm_ArtDeliveryDuration=L"ArtDeliveryDuration";
	const WString JDFStrings::elm_ArtDeliveryIntent=L"ArtDeliveryIntent";
	const WString JDFStrings::elm_ArtHandling=L"ArtHandling";
	const WString JDFStrings::elm_Assembly=L"Assembly";
	const WString JDFStrings::elm_AssemblySection=L"AssemblySection";
	const WString JDFStrings::elm_AssetListCreationParams=L"AssetListCreationParams";
	const WString JDFStrings::elm_Audit=L"Audit";
	const WString JDFStrings::elm_AuditPool=L"AuditPool";
	const WString JDFStrings::elm_AutomatedOverPrintParams=L"AutomatedOverPrintParams";
	const WString JDFStrings::elm_AutomatedOverprintParams=L"AutomatedOverPrintParams"; // legacy for typo

	// BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB//

	const WString JDFStrings::elm_BackCoatings=L"BackCoatings";
	const WString JDFStrings::elm_BackCoverColor=L"BackCoverColor";
	const WString JDFStrings::elm_Band=L"Band";
	const WString JDFStrings::elm_Barcode=L"Barcode";
	const WString JDFStrings::elm_BarcodeCompParams=L"BarcodeCompParams";
	const WString JDFStrings::elm_BarcodeDetails=L"BarcodeDetails";
	const WString JDFStrings::elm_BarcodeReproParams=L"BarcodeReproParams";
	const WString JDFStrings::elm_BarcodeProductionParams=L"BarcodeProductionParams";
	const WString JDFStrings::elm_BasicPreflightTest=L"BasicPreflightTest";
	const WString JDFStrings::elm_BinderBrand=L"BinderBrand";
	const WString JDFStrings::elm_BinderMaterial=L"BinderMaterial";
	const WString JDFStrings::elm_BinderySignature=L"BinderySignature";
	const WString JDFStrings::elm_BindingColor=L"BindingColor";
	const WString JDFStrings::elm_BindingIntent=L"BindingIntent";
	const WString JDFStrings::elm_BindingLength=L"BindingLength";
	const WString JDFStrings::elm_BindingSide=L"BindingSide";
	const WString JDFStrings::elm_BindingType=L"BindingType";
	const WString JDFStrings::elm_BindingQualityMeasurement=L"BindingQualityMeasurement";
	const WString JDFStrings::elm_BindingQualityParams=L"BindingQualityParams";
	const WString JDFStrings::elm_BindItem=L"BindItem";
	const WString JDFStrings::elm_BindList=L"BindList";
	const WString JDFStrings::elm_BlockPreparationParams=L"BlockPreparationParams";
	const WString JDFStrings::elm_BlockThreadSewing=L"BlockThreadSewing";
	const WString JDFStrings::elm_BookCase=L"BookCase";
	const WString JDFStrings::elm_BooleanEvaluation=L"BooleanEvaluation";
	const WString JDFStrings::elm_BooleanState=L"BooleanState";
	const WString JDFStrings::elm_BoxApplication=L"BoxApplication";
	const WString JDFStrings::elm_BoxArgument=L"BoxArgument";
	const WString JDFStrings::elm_BoxedQuantity=L"BoxedQuantity";
	const WString JDFStrings::elm_BoxFoldAction=L"BoxFoldAction";
	const WString JDFStrings::elm_BoxPackingParams=L"BoxPackingParams";
	const WString JDFStrings::elm_BoxShape=L"BoxShape";
	const WString JDFStrings::elm_BoxToBoxDifference=L"BoxToBoxDifference";
	const WString JDFStrings::elm_BrandName=L"BrandName";
	const WString JDFStrings::elm_Brightness=L"Brightness";
	const WString JDFStrings::elm_BufferParams=L"BufferParams";
	const WString JDFStrings::elm_BundlingParams=L"BundlingParams";
	const WString JDFStrings::elm_Bundle=L"Bundle";
	const WString JDFStrings::elm_BundleItem=L"BundleItem";
	const WString JDFStrings::elm_BusinessInfo=L"BusinessInfo";
	const WString JDFStrings::elm_BuyerSupplied=L"BuyerSupplied";
	const WString JDFStrings::elm_ByteMap=L"ByteMap";

	// CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC //

	const WString JDFStrings::elm_call=L"call";
	const WString JDFStrings::elm_CartonMaxWeight=L"CartonMaxWeight";
	const WString JDFStrings::elm_CartonQuantity=L"CartonQuantity";
	const WString JDFStrings::elm_CartonShape=L"CartonShape";
	const WString JDFStrings::elm_CartonStrength=L"CartonStrength";
	const WString JDFStrings::elm_CaseMakingParams=L"CaseMakingParams";
	const WString JDFStrings::elm_CasingInParams=L"CasingInParams";
	const WString JDFStrings::elm_CCITTFaxParams=L"CCITTFaxParams";
	const WString JDFStrings::elm_ChangedAttribute=L"ChangedAttribute";
	const WString JDFStrings::elm_ChangedPath=L"ChangedPath";
	const WString JDFStrings::elm_ChannelBinding=L"ChannelBinding";
	const WString JDFStrings::elm_ChannelBindingParams=L"ChannelBindingParams";
	const WString JDFStrings::elm_ChannelBrand=L"ChannelBrand";
	const WString JDFStrings::elm_choice=L"choice";
	const WString JDFStrings::elm_CIELABMeasuringField=L"CIELABMeasuringField";
	const WString JDFStrings::elm_Circulation=L"Circulation";

	const WString JDFStrings::elm_Coatings=L"Coatings";
	const WString JDFStrings::elm_CoilBinding=L"CoilBinding";
	const WString JDFStrings::elm_CoilBindingParams=L"CoilBindingParams";
	const WString JDFStrings::elm_CoilBrand=L"CoilBrand";
	const WString JDFStrings::elm_CoilMaterial=L"CoilMaterial";
	const WString JDFStrings::elm_CollatingItem=L"CollatingItem";
	const WString JDFStrings::elm_CollectingParams=L"CollectingParams";
	const WString JDFStrings::elm_Color=L"Color";
	const WString JDFStrings::elm_ColorantAlias=L"ColorantAlias";
	const WString JDFStrings::elm_ColorantControl=L"ColorantControl";
	const WString JDFStrings::elm_ColorantOrder=L"ColorantOrder";
	const WString JDFStrings::elm_ColorantParams=L"ColorantParams";
	const WString JDFStrings::elm_ColorantZoneDetails=L"ColorantZoneDetails";
	const WString JDFStrings::elm_ColorControlStrip=L"ColorControlStrip";
	const WString JDFStrings::elm_ColorCorrectionOp=L"ColorCorrectionOp";
	const WString JDFStrings::elm_ColorCorrectionParams=L"ColorCorrectionParams";
	const WString JDFStrings::elm_ColorICCStandard=L"ColorICCStandard";	
	const WString JDFStrings::elm_ColorIntent=L"ColorIntent";
	const WString JDFStrings::elm_ColorMeasurementConditions=L"ColorMeasurementConditions";
	const WString JDFStrings::elm_ColorName=L"ColorName";
	const WString JDFStrings::elm_ColorPool=L"ColorPool";
	const WString JDFStrings::elm_ColorsConstraintsPool=L"ColorsConstraintsPool";
	const WString JDFStrings::elm_ColorSpaceConversionOp=L"ColorSpaceConversionOp";
	const WString JDFStrings::elm_ColorSpaceConversionParams=L"ColorSpaceConversionParams";
	const WString JDFStrings::elm_ColorSpaceSubstitute=L"ColorSpaceSubstitute";
	const WString JDFStrings::elm_ColorsResultsPool=L"ColorsResultsPool";
	const WString JDFStrings::elm_ColorStandard=L"ColorStandard";
	const WString JDFStrings::elm_ColorsUsed=L"ColorsUsed";
	const WString JDFStrings::elm_ColorType=L"ColorType";
	const WString JDFStrings::elm_CombBrand=L"CombBrand";
	const WString JDFStrings::elm_ComChannel=L"ComChannel";
	const WString JDFStrings::elm_Command=L"Command";
	const WString JDFStrings::elm_CommandStopPersistentChannel=L"CommandStopPersistentChannel";
	const WString JDFStrings::elm_Comment=L"Comment";
	const WString JDFStrings::elm_Company=L"Company";
	const WString JDFStrings::elm_Component=L"Component";
	const WString JDFStrings::elm_ConstraintValue=L"ConstraintValue";
	const WString JDFStrings::elm_Contact=L"Contact";
	const WString JDFStrings::elm_ContactCopyParams=L"ContactCopyParams";
	const WString JDFStrings::elm_Container=L"Container";
	const WString JDFStrings::elm_ContentData=L"ContentData";
	const WString JDFStrings::elm_ContentList=L"ContentList";
	const WString JDFStrings::elm_ContentObject=L"ContentObject";
	const WString JDFStrings::elm_ConventionalPrintingParams=L"ConventionalPrintingParams";
	const WString JDFStrings::elm_CostCenter=L"CostCenter";
	const WString JDFStrings::elm_CounterReset=L"CounterReset";
	const WString JDFStrings::elm_Cover=L"Cover";
	const WString JDFStrings::elm_Coverage=L"Coverage";
	const WString JDFStrings::elm_CoverApplicationParams=L"CoverApplicationParams";
	const WString JDFStrings::elm_CoverColor=L"CoverColor";
	const WString JDFStrings::elm_CoverStyle=L"CoverStyle";
	const WString JDFStrings::elm_Crease=L"Crease";
	const WString JDFStrings::elm_CreasingParams=L"CreasingParams";
	const WString JDFStrings::elm_Created=L"Created";
	const WString JDFStrings::elm_CreateLink=L"CreateLink";
	const WString JDFStrings::elm_CreateResource=L"CreateResource";
	const WString JDFStrings::elm_CreditCard=L"CreditCard";
	const WString JDFStrings::elm_CustomerInfo=L"CustomerInfo";
	const WString JDFStrings::elm_CustomerMessage=L"CustomerMessage";
	const WString JDFStrings::elm_Cut=L"Cut";
	const WString JDFStrings::elm_CutBlock=L"CutBlock";
	const WString JDFStrings::elm_CutMark=L"CutMark";
	const WString JDFStrings::elm_CuttingParams=L"CuttingParams";
	const WString JDFStrings::elm_CutType=L"CutType";
	const WString JDFStrings::elm_CylinderPosition=L"CylinderPosition";

	// DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD //

	const WString JDFStrings::elm_DateTimeEvaluation=L"DateTimeEvaluation";
	const WString JDFStrings::elm_DateTimeState=L"DateTimeState";
	const WString JDFStrings::elm_DBMergeParams=L"DBMergeParams";
	const WString JDFStrings::elm_DBRules=L"DBRules";
	const WString JDFStrings::elm_DBSchema=L"DBSchema";
	const WString JDFStrings::elm_DBSelection=L"DBSelection";
	const WString JDFStrings::elm_DCTParams=L"DCTParams";
	const WString JDFStrings::elm_Deleted=L"Deleted";
	const WString JDFStrings::elm_DeliveryCharge=L"DeliveryCharge";
	const WString JDFStrings::elm_DeliveryIntent=L"DeliveryIntent";
	const WString JDFStrings::elm_DeliveryMode=L"DeliveryMode";
	const WString JDFStrings::elm_DeliveryParams=L"DeliveryParams";
	const WString JDFStrings::elm_DensityMeasuringField=L"DensityMeasuringField";
	const WString JDFStrings::elm_Dependencies=L"Dependencies";
	const WString JDFStrings::elm_DevCap=L"DevCap";
	const WString JDFStrings::elm_DevCapPool=L"DevCapPool";
	const WString JDFStrings::elm_DevCaps=L"DevCaps";
	const WString JDFStrings::elm_DevelopingParams=L"DevelopingParams";
	const WString JDFStrings::elm_Device=L"Device";
	const WString JDFStrings::elm_DeviceCap=L"DeviceCap";
	const WString JDFStrings::elm_DeviceColorantOrder=L"DeviceColorantOrder";
	const WString JDFStrings::elm_DeviceFilter=L"DeviceFilter";
	const WString JDFStrings::elm_DeviceInfo=L"DeviceInfo";
	const WString JDFStrings::elm_DeviceList=L"DeviceList";
	const WString JDFStrings::elm_DeviceMark=L"DeviceMark";
	const WString JDFStrings::elm_DeviceNColor=L"DeviceNColor";
	const WString JDFStrings::elm_DeviceNSpace=L"DeviceNSpace";
	const WString JDFStrings::elm_DieLayout=L"DieLayout";
	const WString JDFStrings::elm_DigitalDeliveryParams=L"DigitalDeliveryParams";
	const WString JDFStrings::elm_DigitalMedia=L"DigitalMedia";
	const WString JDFStrings::elm_DigitalPrintingParams=L"DigitalPrintingParams";
	const WString JDFStrings::elm_Dimensions=L"Dimensions";
	const WString JDFStrings::elm_Direction=L"Direction";
	const WString JDFStrings::elm_Disjointing=L"Disjointing";
	const WString JDFStrings::elm_DisplayGroup=L"DisplayGroup";
	const WString JDFStrings::elm_DisplayGroupPool=L"DisplayGroupPool";
	const WString JDFStrings::elm_Disposition=L"Disposition";
	const WString JDFStrings::elm_DividingParams=L"DividingParams";
	const WString JDFStrings::elm_DocumentConstraintsPool=L"DocumentConstraintsPool";
	const WString JDFStrings::elm_DocumentResultsPool=L"DocumentResultsPool";
	const WString JDFStrings::elm_DotSize=L"DotSize";
	const WString JDFStrings::elm_Drop=L"Drop";
	const WString JDFStrings::elm_DropIntent=L"DropIntent";
	const WString JDFStrings::elm_DropItem=L"DropItem";
	const WString JDFStrings::elm_DropItemIntent=L"DropItemIntent";
	const WString JDFStrings::elm_DurationEvaluation=L"DurationEvaluation";
	const WString JDFStrings::elm_DurationState=L"DurationState";
	const WString JDFStrings::elm_DynamicField=L"DynamicField";
	const WString JDFStrings::elm_DynamicInput=L"DynamicInput";

	// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

	const WString JDFStrings::elm_Earliest=L"Earliest";
	const WString JDFStrings::elm_EarliestDuration=L"EarliestDuration";
	const WString JDFStrings::elm_EdgeAngle=L"EdgeAngle";
	const WString JDFStrings::elm_EdgeGlue=L"EdgeGlue";
	const WString JDFStrings::elm_EdgeGluing=L"EdgeGluing";
	const WString JDFStrings::elm_EdgeShape=L"EdgeShape";
	const WString JDFStrings::elm_ElementColorParams=L"ElementColorParams";
	const WString JDFStrings::elm_Emboss=L"Emboss";
	const WString JDFStrings::elm_EmbossingIntent=L"EmbossingIntent";
	const WString JDFStrings::elm_EmbossingItem=L"EmbossingItem";
	const WString JDFStrings::elm_EmbossingParams=L"EmbossingParams";
	const WString JDFStrings::elm_EmbossingType=L"EmbossingType";
	const WString JDFStrings::elm_Employee=L"Employee";
	const WString JDFStrings::elm_EmployeeDef=L"EmployeeDef";
	const WString JDFStrings::elm_EndSheet=L"EndSheet";
	const WString JDFStrings::elm_EndSheetGluingParams=L"EndSheetGluingParams";
	const WString JDFStrings::elm_EndSheets=L"EndSheets";
	const WString JDFStrings::elm_EnumerationEvaluation=L"EnumerationEvaluation";
	const WString JDFStrings::elm_EnumerationState=L"EnumerationState";
	const WString JDFStrings::elm_Error=L"Error";
	const WString JDFStrings::elm_ErrorData=L"ErrorData";
	const WString JDFStrings::elm_Event=L"Event";
	const WString JDFStrings::elm_ExposedMedia=L"ExposedMedia";
	const WString JDFStrings::elm_ExtendedAddress=L"ExtendedAddress";
	const WString JDFStrings::elm_ExternalImpositionTemplate=L"ExternalImpositionTemplate";
	const WString JDFStrings::elm_ExtraValues=L"ExtraValues";

	// FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF

	const WString JDFStrings::elm_FCNKey=L"FCNKey";
	const WString JDFStrings::elm_FeatureAttribute=L"FeatureAttribute";
	const WString JDFStrings::elm_FeaturePool=L"FeaturePool";
	const WString JDFStrings::elm_Feeder=L"Feeder";
	const WString JDFStrings::elm_FeederQualityParams=L"FeederQualityParams";
	const WString JDFStrings::elm_FeedingParams=L"FeedingParams";
	const WString JDFStrings::elm_FileAlias=L"FileAlias";
	const WString JDFStrings::elm_FileSpec=L"FileSpec";
	const WString JDFStrings::elm_FileSpecOut=L"FileSpecOut";
	const WString JDFStrings::elm_FileTypeConstraintsPool=L"FileTypeConstraintsPool";
	const WString JDFStrings::elm_FileTypeResultsPool=L"FileTypeResultsPool";
	const WString JDFStrings::elm_FinishedDimensions=L"FinishedDimensions";
	const WString JDFStrings::elm_FinishedGrainDirection=L"FinishedGrainDirection";
	const WString JDFStrings::elm_FitPolicy=L"FitPolicy";
	const WString JDFStrings::elm_FlateParams=L"FlateParams";
	const WString JDFStrings::elm_FlushedResources=L"FlushedResources";
	const WString JDFStrings::elm_FlushQueueParams=L"FlushQueueParams";
	const WString JDFStrings::elm_FlushResourceParams=L"FlushResourceParams";
	const WString JDFStrings::elm_FoilColor=L"FoilColor";
	const WString JDFStrings::elm_Fold=L"Fold";
	const WString JDFStrings::elm_FolderSuperstructureWebPath=L"FolderSuperstructureWebPath";
	const WString JDFStrings::elm_FolderProduction=L"FolderProduction";
	const WString JDFStrings::elm_FoldingCatalog=L"FoldingCatalog";
	const WString JDFStrings::elm_FoldingIntent=L"FoldingIntent";
	const WString JDFStrings::elm_FoldingParams=L"FoldingParams";
	const WString JDFStrings::elm_FoldingWidth=L"FoldingWidth";
	const WString JDFStrings::elm_FoldingWidthBack=L"FoldingWidthBack";
	const WString JDFStrings::elm_FontParams=L"FontParams";
	const WString JDFStrings::elm_FontPolicy=L"FontPolicy";
	const WString JDFStrings::elm_FontsConstraintsPool=L"FontsConstraintsPool";
	const WString JDFStrings::elm_FontsResultsPool=L"FontsResultsPool";
	const WString JDFStrings::elm_FormatConversionParams=L"FormatConversionParams";
	const WString JDFStrings::elm_Frequency=L"Frequency";
	const WString JDFStrings::elm_FrequencySelection=L"FrequencySelection";
	const WString JDFStrings::elm_FrontCoatings=L"FrontCoatings";

	// GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG

	const WString JDFStrings::elm_GangCmdFilter=L"GangCmdFilter";
	const WString JDFStrings::elm_GangInfo=L"GangInfo";
	const WString JDFStrings::elm_GangQuFilter=L"GangQuFilter";
	const WString JDFStrings::elm_GatheringParams=L"GatheringParams";
	const WString JDFStrings::elm_GeneralID=L"GeneralID";
	const WString JDFStrings::elm_Glue=L"Glue";
	const WString JDFStrings::elm_GlueApplication=L"GlueApplication";
	const WString JDFStrings::elm_GlueLine=L"GlueLine";
	const WString JDFStrings::elm_GlueProcedure=L"GlueProcedure";
	const WString JDFStrings::elm_GlueType=L"GlueType";
	const WString JDFStrings::elm_GluingParams=L"GluingParams";
	const WString JDFStrings::elm_Grade=L"Grade";
	const WString JDFStrings::elm_GrainDirection=L"GrainDirection";

	// HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

	const WString JDFStrings::elm_HalfTone=L"HalfTone";
	const WString JDFStrings::elm_HardCoverBinding=L"HardCoverBinding";
	const WString JDFStrings::elm_HeadBandApplicationParams=L"HeadBandApplicationParams";
	const WString JDFStrings::elm_HeadBandColor=L"HeadBandColor";
	const WString JDFStrings::elm_Headbands=L"Headbands";
	const WString JDFStrings::elm_HeadBands=L"HeadBands";
	const WString JDFStrings::elm_Height=L"Height";
	const WString JDFStrings::elm_Hole=L"Hole";
	const WString JDFStrings::elm_HoleCount=L"HoleCount";
	const WString JDFStrings::elm_HoleLine=L"HoleLine";
	const WString JDFStrings::elm_HoleList=L"HoleList";
	const WString JDFStrings::elm_HoleMakingIntent=L"HoleMakingIntent";
	const WString JDFStrings::elm_HoleMakingParams=L"HoleMakingParams";
	const WString JDFStrings::elm_HoleType=L"HoleType";

	// IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII

	const WString JDFStrings::elm_Icon=L"Icon";
	const WString JDFStrings::elm_IconList=L"IconList";
	const WString JDFStrings::elm_Identical=L"Identical";
	const WString JDFStrings::elm_IdentificationField=L"IdentificationField";
	const WString JDFStrings::elm_IDInfo=L"IDInfo";
	const WString JDFStrings::elm_IDPCover=L"IDPCover";
	const WString JDFStrings::elm_IDPFinishing=L"IDPFinishing";
	const WString JDFStrings::elm_IDPFolding=L"IDPFolding";
	const WString JDFStrings::elm_IDPHoleMaking=L"IDPHoleMaking";
	const WString JDFStrings::elm_IDPImageShift=L"IDPImageShift";
	const WString JDFStrings::elm_IDPJobSheet=L"IDPJobSheet";
	const WString JDFStrings::elm_IDPLayout=L"IDPLayout";
	const WString JDFStrings::elm_IDPrintingParams=L"IDPrintingParams";
	const WString JDFStrings::elm_IDPStitching=L"IDPStitching";
	const WString JDFStrings::elm_IDPTrimming=L"IDPTrimming";
	const WString JDFStrings::elm_ImageCompression=L"ImageCompression";
	const WString JDFStrings::elm_ImageCompressionParams=L"ImageCompressionParams";
	const WString JDFStrings::elm_ImageReplacementParams=L"ImageReplacementParams";
	const WString JDFStrings::elm_ImagesConstraintsPool=L"ImagesConstraintsPool";
	const WString JDFStrings::elm_ImageSetterParams=L"ImageSetterParams";
	const WString JDFStrings::elm_ImageShift=L"ImageShift";
	const WString JDFStrings::elm_ImageSize=L"ImageSize";
	const WString JDFStrings::elm_ImageStrategy=L"ImageStrategy";
	const WString JDFStrings::elm_ImagesResultsPool=L"ImagesResultsPool";
	const WString JDFStrings::elm_Ink=L"Ink";
	const WString JDFStrings::elm_InkManufacturer=L"InkManufacturer";
	const WString JDFStrings::elm_InkZoneCalculationParams=L"InkZoneCalculationParams";
	const WString JDFStrings::elm_InkZoneProfile=L"InkZoneProfile";
	const WString JDFStrings::elm_Insert=L"Insert";
	const WString JDFStrings::elm_InsertingIntent=L"InsertingIntent";
	const WString JDFStrings::elm_InsertingParams=L"InsertingParams";
	const WString JDFStrings::elm_InsertList=L"InsertList";
	const WString JDFStrings::elm_InsertSheet=L"InsertSheet";
	const WString JDFStrings::elm_IntegerEvaluation=L"IntegerEvaluation";
	const WString JDFStrings::elm_IntegerState=L"IntegerState";
	const WString JDFStrings::elm_InterpretedPDLData=L"InterpretedPDLData";
	const WString JDFStrings::elm_InterpretingParams=L"InterpretingParams";
	const WString JDFStrings::elm_IsPresentEvaluation=L"IsPresentEvaluation";
	const WString JDFStrings::elm_IssueDate=L"IssueDate";
	const WString JDFStrings::elm_IssueName=L"IssueName";
	const WString JDFStrings::elm_IssueType=L"IssueType";

	// JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ

	const WString JDFStrings::elm_Jacket=L"Jacket";
	const WString JDFStrings::elm_JacketFoldingWidth=L"JacketFoldingWidth";
	const WString JDFStrings::elm_JacketingParams=L"JacketingParams";
	const WString JDFStrings::elm_JapanBind=L"JapanBind";
	const WString JDFStrings::elm_JBIG2Params=L"JBIG2Params";
	const WString JDFStrings::elm_JDF=L"JDF";
	const WString JDFStrings::elm_JDFController=L"JDFController";
	const WString JDFStrings::elm_JDFService=L"JDFService";
	const WString JDFStrings::elm_JDFSystemTimeSet=L"JDFSystemTimeSet";
	const WString JDFStrings::elm_JMF=L"JMF";
	const WString JDFStrings::elm_JobField=L"JobField";
	const WString JDFStrings::elm_JobPhase=L"JobPhase";
	const WString JDFStrings::elm_JobSheet=L"JobSheet";
	const WString JDFStrings::elm_JPEG2000Params=L"JPEG2000Params";

	// KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK

	const WString JDFStrings::elm_KnownMsgQuParams=L"KnownMsgQuParams";

	// LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL

	const WString JDFStrings::elm_LabelingParams=L"LabelingParams";
	const WString JDFStrings::elm_Laminated=L"Laminated";
	const WString JDFStrings::elm_LaminatingIntent=L"LaminatingIntent";
	const WString JDFStrings::elm_LaminatingParams=L"LaminatingParams";
	const WString JDFStrings::elm_LayerDetails=L"LayerDetails";
	const WString JDFStrings::elm_LayerList=L"LayerList";
	const WString JDFStrings::elm_Layout=L"Layout";
	const WString JDFStrings::elm_LayoutElement=L"LayoutElement";
	const WString JDFStrings::elm_LayoutElementPart=L"LayoutElementPart";
	const WString JDFStrings::elm_LayoutElementProductionParams=L"LayoutElementProductionParams";
	const WString JDFStrings::elm_LayoutIntent=L"LayoutIntent";
	const WString JDFStrings::elm_LayoutPreparationParams=L"LayoutPreparationParams";
	const WString JDFStrings::elm_Level=L"Level";
	const WString JDFStrings::elm_Loc=L"Loc";
	const WString JDFStrings::elm_Location=L"Location";
	const WString JDFStrings::elm_LogicalStackParams=L"LogicalStackParams";
	const WString JDFStrings::elm_LongFold=L"LongFold";
	const WString JDFStrings::elm_LongGlue=L"LongGlue";
	const WString JDFStrings::elm_LongitudinalRibbonOperationParams=L"LongitudinalRibbonOperationParams";
	const WString JDFStrings::elm_LongPerforate=L"LongPerforate";
	const WString JDFStrings::elm_LongSlit=L"LongSlit";
	const WString JDFStrings::elm_Lot=L"Lot";
	const WString JDFStrings::elm_LZWParams=L"LZWParams";

	// MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM

	const WString JDFStrings::elm_macro=L"macro";
	const WString JDFStrings::elm_macros=L"macros";
	const WString JDFStrings::elm_MacroPool=L"MacroPool";
	const WString JDFStrings::elm_ManualLaborParams=L"ManualLaborParams";
	const WString JDFStrings::elm_MarkObject=L"MarkObject";
	const WString JDFStrings::elm_Material=L"Material";
	const WString JDFStrings::elm_MatrixEvaluation=L"MatrixEvaluation";
	const WString JDFStrings::elm_MatrixState=L"MatrixState";
	const WString JDFStrings::elm_Media=L"Media";
	const WString JDFStrings::elm_MediaColor=L"MediaColor";
	const WString JDFStrings::elm_MediaColorDetails=L"MediaColorDetails";
	const WString JDFStrings::elm_MediaIntent=L"MediaIntent";
	const WString JDFStrings::elm_MediaLayers=L"MediaLayers";
	const WString JDFStrings::elm_MediaSource=L"MediaSource";
	const WString JDFStrings::elm_MediaType=L"MediaType";
	const WString JDFStrings::elm_MediaTypeDetails=L"MediaTypeDetails";
	const WString JDFStrings::elm_MediaUnit=L"MediaUnit";
	const WString JDFStrings::elm_Merged=L"Merged";
	const WString JDFStrings::elm_Message=L"Message";
	const WString JDFStrings::elm_MessageService=L"MessageService";
	const WString JDFStrings::elm_Method=L"Method";
	const WString JDFStrings::elm_Milestone=L"Milestone";
	const WString JDFStrings::elm_MISDetails=L"MISDetails";
	const WString JDFStrings::elm_Modified=L"Modified";
	const WString JDFStrings::elm_ModifyNodeCmdParams=L"ModifyNodeCmdParams";
	const WString JDFStrings::elm_Module=L"Module";
	const WString JDFStrings::elm_ModuleCap=L"ModuleCap";
	const WString JDFStrings::elm_ModulePhase=L"ModulePhase";
	const WString JDFStrings::elm_ModulePool=L"ModulePool";
	const WString JDFStrings::elm_ModuleStatus=L"ModuleStatus";
	const WString JDFStrings::elm_MoveLink=L"MoveLink";
	const WString JDFStrings::elm_MoveResource=L"MoveResource";
	const WString JDFStrings::elm_MsgFilter=L"MsgFilter";

	// NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN //

	const WString JDFStrings::elm_NameEvaluation=L"NameEvaluation";
	const WString JDFStrings::elm_NameState=L"NameState";
	const WString JDFStrings::elm_NewComment=L"NewComment";
	const WString JDFStrings::elm_NewJDFCmdParams=L"NewJDFCmdParams";
	const WString JDFStrings::elm_NewJDFQuParams=L"NewJDFQuParams";
	const WString JDFStrings::elm_NodeInfo=L"NodeInfo";
	const WString JDFStrings::elm_NodeInfoCmdParams=L"NodeInfoCmdParams";
	const WString JDFStrings::elm_NodeInfoQuParams=L"NodeInfoQuParams";
	const WString JDFStrings::elm_NodeInfoResp=L"NodeInfoResp";
	const WString JDFStrings::elm_not=L"not";
	const WString JDFStrings::elm_Notification=L"Notification";
	const WString JDFStrings::elm_NotificationDef=L"NotificationDef";
	const WString JDFStrings::elm_NotificationFilter=L"NotificationFilter";
	const WString JDFStrings::elm_NumberEvaluation=L"NumberEvaluation";
	const WString JDFStrings::elm_NumberingIntent=L"NumberingIntent";
	const WString JDFStrings::elm_NumberingParam=L"NumberingParam";
	const WString JDFStrings::elm_NumberingParams=L"NumberingParams";
	const WString JDFStrings::elm_NumberItem=L"NumberItem";
	const WString JDFStrings::elm_NumberState=L"NumberState";

	// OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO //

	const WString JDFStrings::elm_ObjectResolution=L"ObjectResolution";
	const WString JDFStrings::elm_ObservationTarget=L"ObservationTarget";
	const WString JDFStrings::elm_Occupation=L"Occupation";
	const WString JDFStrings::elm_OCGControl=L"OCGControl";
	const WString JDFStrings::elm_Opacity=L"Opacity";
	const WString JDFStrings::elm_OpacityLevel=L"OpacityLevel";
	const WString JDFStrings::elm_or=L"or";
	const WString JDFStrings::elm_OrderingParams=L"OrderingParams";
	const WString JDFStrings::elm_OrganizationalUnit=L"OrganizationalUnit";
	const WString JDFStrings::elm_Orientation=L"Orientation";
	const WString JDFStrings::elm_otherwise=L"otherwise";
	const WString JDFStrings::elm_Overage=L"Overage";

	// PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP

	const WString JDFStrings::elm_PackingIntent=L"PackingIntent";
	const WString JDFStrings::elm_PackingParams=L"PackingParams";
	const WString JDFStrings::elm_PageCell=L"PageCell";
	const WString JDFStrings::elm_PageData=L"PageData";
	const WString JDFStrings::elm_PageAssignedList=L"PageAssignedList";
	const WString JDFStrings::elm_PageElement=L"PageElement";
	const WString JDFStrings::elm_PageList=L"PageList";
	const WString JDFStrings::elm_Pages=L"Pages";
	const WString JDFStrings::elm_PagesConstraintsPool=L"PagesConstraintsPool";
	const WString JDFStrings::elm_PagesResultsPool=L"PagesResultsPool";
	const WString JDFStrings::elm_PageVariance=L"PageVariance";
	const WString JDFStrings::elm_Pallet=L"Pallet";
	const WString JDFStrings::elm_PalletCornerBoards=L"PalletCornerBoards";
	const WString JDFStrings::elm_PalletizingParams=L"PalletizingParams";
	const WString JDFStrings::elm_PalletMaxHeight=L"PalletMaxHeight";
	const WString JDFStrings::elm_PalletMaxWeight=L"PalletMaxWeight";
	const WString JDFStrings::elm_PalletQuantity=L"PalletQuantity";
	const WString JDFStrings::elm_PalletSize=L"PalletSize";
	const WString JDFStrings::elm_PalletType=L"PalletType";
	const WString JDFStrings::elm_PalletWrapping=L"PalletWrapping";
	const WString JDFStrings::elm_Part=L"Part";
	const WString JDFStrings::elm_PartAmount=L"PartAmount";
	const WString JDFStrings::elm_PartStatus=L"PartStatus";
	const WString JDFStrings::elm_Path=L"Path";
	const WString JDFStrings::elm_Payment=L"Payment";
	const WString JDFStrings::elm_PayTerm=L"PayTerm";
	const WString JDFStrings::elm_PDFInterpretingParams=L"PDFInterpretingParams";
	const WString JDFStrings::elm_PDFPathEvaluation=L"PDFPathEvaluation";
	const WString JDFStrings::elm_PDFPathState=L"PDFPathState";
	const WString JDFStrings::elm_PDFToPSConversionParams=L"PDFToPSConversionParams";
	const WString JDFStrings::elm_PDLResourceAlias=L"PDLResourceAlias";
	const WString JDFStrings::elm_PDFXParams=L"PDFXParams";
	const WString JDFStrings::elm_Perforate=L"Perforate";
	const WString JDFStrings::elm_PerforatingParams=L"PerforatingParams";
	const WString JDFStrings::elm_Performance=L"Performance";
	const WString JDFStrings::elm_Person=L"Person";
	const WString JDFStrings::elm_PhaseTime=L"PhaseTime";
	const WString JDFStrings::elm_PipeParams=L"PipeParams";
	const WString JDFStrings::elm_PixelColorant=L"PixelColorant";
	const WString JDFStrings::elm_PlaceHolderResource=L"PlaceHolderResource";
	const WString JDFStrings::elm_PlasticCombBinding=L"PlasticCombBinding";
	const WString JDFStrings::elm_PlasticCombBindingParams=L"PlasticCombBindingParams";
	const WString JDFStrings::elm_PlasticCombType=L"PlasticCombType";
	const WString JDFStrings::elm_PlateCopyParams=L"PlateCopyParams";
	const WString JDFStrings::elm_Position=L"Position";
	const WString JDFStrings::elm_PostPressComponentPath=L"PostPressComponentPath";
	 
	const WString JDFStrings::elm_PreflightAction=L"PreflightAction";
	const WString JDFStrings::elm_PreflightAnalysis=L"PreflightAnalysis";
	const WString JDFStrings::elm_PreflightArgument=L"PreflightArgument";
	const WString JDFStrings::elm_PreflightConstraint=L"PreflightConstraint";
	const WString JDFStrings::elm_PreflightConstraintsPool=L"PreflightConstraintsPool";
	const WString JDFStrings::elm_PreflightDetail=L"PreflightDetail";
	const WString JDFStrings::elm_PreflightInformation=L"PreflightInformation";
	const WString JDFStrings::elm_PreflightInstance=L"PreflightInstance";
	const WString JDFStrings::elm_PreflightInstanceDetail=L"PreflightInstanceDetail";
	const WString JDFStrings::elm_PreflightInventory=L"PreflightInventory";
	const WString JDFStrings::elm_PreflightParams=L"PreflightParams";
	const WString JDFStrings::elm_PreflightProfile=L"PreflightProfile";
	const WString JDFStrings::elm_PreflightProfileConstraintsPool=L"PreflightProfileConstraintsPool";
	const WString JDFStrings::elm_PreflightReport=L"PreflightReport";
	const WString JDFStrings::elm_PreflightReportRulePool=L"PreflightReportRulePool";
	const WString JDFStrings::elm_PreflightResultsPool=L"PreflightResultsPool";
	const WString JDFStrings::elm_PreflightValue=L"PreflightValue";
	const WString JDFStrings::elm_PRError=L"PRError";
	const WString JDFStrings::elm_Preview=L"Preview";
	const WString JDFStrings::elm_PreviewGenerationParams=L"PreviewGenerationParams";
	const WString JDFStrings::elm_Pricing=L"Pricing";
	const WString JDFStrings::elm_PrintCondition=L"PrintCondition";
	const WString JDFStrings::elm_PrintConditionColor=L"PrintConditionColor";
	const WString JDFStrings::elm_PrintingUnitWebPath=L"PrintingUnitWebPath";
	const WString JDFStrings::elm_PrintPreference=L"PrintPreference";
	const WString JDFStrings::elm_PrintProcess=L"PrintProcess";
	const WString JDFStrings::elm_PrintRollingParams=L"PrintRollingParams";
	const WString JDFStrings::elm_PRItem=L"PRItem";
	const WString JDFStrings::elm_PRGroup=L"PRGroup";
	const WString JDFStrings::elm_PRGroupOccurrence=L"PRGroupOccurrence";
	const WString JDFStrings::elm_PROccurrence=L"PROccurrence";
	const WString JDFStrings::elm_ProcessRun=L"ProcessRun";
	const WString JDFStrings::elm_ProductionIntent=L"ProductionIntent";
	const WString JDFStrings::elm_ProductionPath=L"ProductionPath";
	const WString JDFStrings::elm_ProofingIntent=L"ProofingIntent";
	const WString JDFStrings::elm_ProofingParams=L"ProofingParams";
	const WString JDFStrings::elm_ProofItem=L"ProofItem";
	const WString JDFStrings::elm_ProofType=L"ProofType";
	const WString JDFStrings::elm_Properties=L"Properties";
	const WString JDFStrings::elm_PRRule=L"PRRule";
	const WString JDFStrings::elm_PRRuleAttr=L"PRRuleAttr";
	const WString JDFStrings::elm_PSToPDFConversionParams=L"PSToPDFConversionParams";

	// QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ//

	const WString JDFStrings::elm_QualityControlParams=L"QualityControlParams";
	const WString JDFStrings::elm_QualityControlResult=L"QualityControlResult";
	const WString JDFStrings::elm_QualityMeasurement=L"QualityMeasurement";
	const WString JDFStrings::elm_Query=L"Query";
	const WString JDFStrings::elm_Queue=L"Queue";
	const WString JDFStrings::elm_QueueEntry=L"QueueEntry";
	const WString JDFStrings::elm_QueueEntryDef=L"QueueEntryDef";
	const WString JDFStrings::elm_QueueEntryDefList=L"QueueEntryDefList";
	const WString JDFStrings::elm_QueueEntryPosParams=L"QueueEntryPosParams";
	const WString JDFStrings::elm_QueueEntryPriParams=L"QueueEntryPriParams";
	const WString JDFStrings::elm_QueueFilter=L"QueueFilter";
	const WString JDFStrings::elm_QueueSubmissionParams=L"QueueSubmissionParams";

	// RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR //

	const WString JDFStrings::elm_RectangleEvaluation=L"RectangleEvaluation";
	const WString JDFStrings::elm_RectangleState=L"RectangleState";
	const WString JDFStrings::elm_Recycled=L"Recycled";
	const WString JDFStrings::elm_RecycledPercentage=L"RecycledPercentage";
	const WString JDFStrings::elm_ReferenceXObjParams=L"ReferenceXObjParams";
	const WString JDFStrings::elm_RegisterMark=L"RegisterMark";
	const WString JDFStrings::elm_RegisterRibbon=L"RegisterRibbon";
	const WString JDFStrings::elm_Registration=L"Registration";
	const WString JDFStrings::elm_Removed=L"Removed";
	const WString JDFStrings::elm_RemoveLink=L"RemoveLink";
	const WString JDFStrings::elm_RemoveResource=L"RemoveResource";
	const WString JDFStrings::elm_RenderingParams=L"RenderingParams";
	const WString JDFStrings::elm_RequestQueueEntryParams=L"RequestQueueEntryParams";
	const WString JDFStrings::elm_Required=L"Required";
	const WString JDFStrings::elm_RequiredDuration=L"RequiredDuration";
	const WString JDFStrings::elm_Resource=L"Resource";
	const WString JDFStrings::elm_ResourceAudit=L"ResourceAudit";
	const WString JDFStrings::elm_ResourceCmdParams=L"ResourceCmdParams";
	const WString JDFStrings::elm_ResourceDefinitionParams=L"ResourceDefinitionParams";
	const WString JDFStrings::elm_ResourceInfo=L"ResourceInfo";
	const WString JDFStrings::elm_ResourceLink=L"ResourceLink";
	const WString JDFStrings::elm_ResourceLinkPool=L"ResourceLinkPool";
	const WString JDFStrings::elm_ResourceParam=L"ResourceParam";
	const WString JDFStrings::elm_ResourcePool=L"ResourcePool";
	const WString JDFStrings::elm_ResourcePull=L"ResourcePull";
	const WString JDFStrings::elm_ResourcePullParams=L"ResourcePullParams";
	const WString JDFStrings::elm_ResourceQuParams=L"ResourceQuParams";
	const WString JDFStrings::elm_Response=L"Response";
	const WString JDFStrings::elm_ResubmissionParams=L"ResubmissionParams";
	const WString JDFStrings::elm_ReturnMethod=L"ReturnMethod";
	const WString JDFStrings::elm_ReturnQueueEntryParams=L"ReturnQueueEntryParams";
	const WString JDFStrings::elm_RingBinding=L"RingBinding";
	const WString JDFStrings::elm_RingBindingParams=L"RingBindingParams";
	const WString JDFStrings::elm_RingDiameter=L"RingDiameter";
	const WString JDFStrings::elm_RingMechanic=L"RingMechanic";
	const WString JDFStrings::elm_RingShape=L"RingShape";
	const WString JDFStrings::elm_RingSystem=L"RingSystem";
	const WString JDFStrings::elm_RivetsExposed=L"RivetsExposed";
	const WString JDFStrings::elm_RollStand=L"RollStand";
	const WString JDFStrings::elm_RunList=L"RunList";

	// SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS //

	const WString JDFStrings::elm_SaddleStitching=L"SaddleStitching";
	const WString JDFStrings::elm_SaddleStitchingParams=L"SaddleStitchingParams";
	const WString JDFStrings::elm_ScanParams=L"ScanParams";
	const WString JDFStrings::elm_ScavengerArea=L"ScavengerArea";
	const WString JDFStrings::elm_Score=L"Score";
	const WString JDFStrings::elm_Scoring=L"Scoring";
	const WString JDFStrings::elm_ScreeningIntent=L"ScreeningIntent";
	const WString JDFStrings::elm_ScreeningParams=L"ScreeningParams";
	const WString JDFStrings::elm_ScreeningSpec=L"ScreeningSpec";
	const WString JDFStrings::elm_ScreeningType=L"ScreeningType";
	const WString JDFStrings::elm_ScreenSelector=L"ScreenSelector";
	const WString JDFStrings::elm_Sealing=L"Sealing";
	const WString JDFStrings::elm_SearchPath=L"SearchPath";
	const WString JDFStrings::elm_SeparationControlParams=L"SeparationControlParams";
	const WString JDFStrings::elm_SeparationList=L"SeparationList";
	const WString JDFStrings::elm_SeparationSpec=L"SeparationSpec";
	const WString JDFStrings::elm_ServiceLevel=L"ServiceLevel";
	const WString JDFStrings::elm_set=L"set";
	const WString JDFStrings::elm_Shape=L"Shape";
	const WString JDFStrings::elm_ShapeCut=L"ShapeCut";
	const WString JDFStrings::elm_ShapeCuttingIntent=L"ShapeCuttingIntent";
	const WString JDFStrings::elm_ShapeCuttingParams=L"ShapeCuttingParams";
	const WString JDFStrings::elm_ShapeDepth=L"ShapeDepth";
	const WString JDFStrings::elm_ShapeElement=L"ShapeElement";
	const WString JDFStrings::elm_ShapeEvaluation=L"ShapeEvaluation";
	const WString JDFStrings::elm_ShapeState=L"ShapeState";
	const WString JDFStrings::elm_ShapeType=L"ShapeType";
	const WString JDFStrings::elm_Sheet=L"Sheet";
	const WString JDFStrings::elm_ShrinkingParams=L"ShrinkingParams";
	const WString JDFStrings::elm_ShutDown=L"ShutDown";
	const WString JDFStrings::elm_ShutDownCmdParams=L"ShutDownCmdParams";
	const WString JDFStrings::elm_SideSewing=L"SideSewing";
	const WString JDFStrings::elm_SideSewingParams=L"SideSewingParams";
	const WString JDFStrings::elm_SideStitching=L"SideStitching";
	const WString JDFStrings::elm_Signal=L"Signal";
	const WString JDFStrings::elm_Signature=L"Signature";
	const WString JDFStrings::elm_SignatureCell=L"SignatureCell";
	const WString JDFStrings::elm_SizeIntent=L"SizeIntent";
	const WString JDFStrings::elm_SizePolicy=L"SizePolicy";
	const WString JDFStrings::elm_SoftCoverBinding=L"SoftCoverBinding";
	const WString JDFStrings::elm_SourceResource=L"SourceResource";
	const WString JDFStrings::elm_Spawned=L"Spawned";
	const WString JDFStrings::elm_SpineBrushing=L"SpineBrushing";
	const WString JDFStrings::elm_SpineFiberRoughing=L"SpineFiberRoughing";
	const WString JDFStrings::elm_SpineFibreRoughing=L"SpineFibreRoughing";
	const WString JDFStrings::elm_SpineGlue=L"SpineGlue";
	const WString JDFStrings::elm_SpineLevelling=L"SpineLevelling";
	const WString JDFStrings::elm_SpineMilling=L"SpineMilling";
	const WString JDFStrings::elm_SpineNotching=L"SpineNotching";
	const WString JDFStrings::elm_SpinePreparationParams=L"SpinePreparationParams";
	const WString JDFStrings::elm_SpineSanding=L"SpineSanding";
	const WString JDFStrings::elm_SpineShredding=L"SpineShredding";
	const WString JDFStrings::elm_SpineTapingParams=L"SpineTapingParams";
	const WString JDFStrings::elm_Stack=L"Stack";
	const WString JDFStrings::elm_StackingParams=L"StackingParams";
	const WString JDFStrings::elm_State=L"State";
	const WString JDFStrings::elm_Station=L"Station";
	const WString JDFStrings::elm_StatusPool=L"StatusPool";
	const WString JDFStrings::elm_StatusQuParams=L"StatusQuParams";
	const WString JDFStrings::elm_StitchingParams=L"StitchingParams";
	const WString JDFStrings::elm_StitchNumber=L"StitchNumber";
	const WString JDFStrings::elm_StockBrand=L"StockBrand";
	const WString JDFStrings::elm_StockType=L"StockType";
	const WString JDFStrings::elm_StopPersChParams=L"StopPersChParams";
	const WString JDFStrings::elm_Strap=L"Strap";
	const WString JDFStrings::elm_StrappingParams=L"StrappingParams";
	const WString JDFStrings::elm_StringEvaluation=L"StringEvaluation";
	const WString JDFStrings::elm_StringListValue=L"StringListValue";
	const WString JDFStrings::elm_StringState=L"StringState";
	const WString JDFStrings::elm_StripBinding=L"StripBinding";
	const WString JDFStrings::elm_StripBindingParams=L"StripBindingParams";
	const WString JDFStrings::elm_StripMark=L"StripMark";
	const WString JDFStrings::elm_StripMaterial=L"StripMaterial";
	const WString JDFStrings::elm_StripCellParams=L"StripCellParams";
	const WString JDFStrings::elm_StrippingParams=L"StrippingParams";
	const WString JDFStrings::elm_SubmissionMethods=L"SubmissionMethods";
	const WString JDFStrings::elm_Subscription=L"Subscription";
	const WString JDFStrings::elm_Surface=L"Surface";
	const WString JDFStrings::elm_SurplusHandling=L"SurplusHandling";
	const WString JDFStrings::elm_SystemTimeSet=L"SystemTimeSet";

	const WString JDFStrings::elm_TabBindMylar=L"TabBindMylar";
	const WString JDFStrings::elm_TabBrand=L"TabBrand";
	const WString JDFStrings::elm_TabBodyCopy=L"TabBodyCopy";
	const WString JDFStrings::elm_TabExtensionDistance=L"TabExtensionDistance";
	const WString JDFStrings::elm_TabExtensionMylar=L"TabExtensionMylar";
	const WString JDFStrings::elm_TabMylarColor=L"TabMylarColor";
	const WString JDFStrings::elm_Tabs=L"Tabs";
	const WString JDFStrings::elm_Tape=L"Tape";
	const WString JDFStrings::elm_TapeBinding=L"TapeBinding";
	const WString JDFStrings::elm_TapeColor=L"TapeColor";
	const WString JDFStrings::elm_Technology=L"Technology";
	const WString JDFStrings::elm_TeethPerDimension=L"TeethPerDimension";
	const WString JDFStrings::elm_Temperature=L"Temperature";
	const WString JDFStrings::elm_Term=L"Term";
	const WString JDFStrings::elm_Test=L"Test";
	const WString JDFStrings::elm_TestPool=L"TestPool";
	const WString JDFStrings::elm_TestRef=L"TestRef";
	const WString JDFStrings::elm_Texture=L"Texture";
	const WString JDFStrings::elm_Thickness=L"Thickness";
	const WString JDFStrings::elm_ThinPDFParams=L"ThinPDFParams";
	const WString JDFStrings::elm_ThreadSealing=L"ThreadSealing";
	const WString JDFStrings::elm_ThreadSealingParams=L"ThreadSealingParams";
	const WString JDFStrings::elm_ThreadSewing=L"ThreadSewing";
	const WString JDFStrings::elm_ThreadSewingParams=L"ThreadSewingParams";
	const WString JDFStrings::elm_TIFFEmbeddedFile=L"TIFFEmbeddedFile";
	const WString JDFStrings::elm_TIFFFormatParams=L"TIFFFormatParams";
	const WString JDFStrings::elm_TIFFtag=L"TIFFtag";
	const WString JDFStrings::elm_TightBacking=L"TightBacking";
	const WString JDFStrings::elm_Tile=L"Tile";
	const WString JDFStrings::elm_Tool=L"Tool";
	const WString JDFStrings::elm_TrackFilter=L"TrackFilter";
	const WString JDFStrings::elm_TrackResult=L"TrackResult";
	const WString JDFStrings::elm_Transfer=L"Transfer";
	const WString JDFStrings::elm_TransferCurve=L"TransferCurve";
	const WString JDFStrings::elm_TransferCurvePool=L"TransferCurvePool";
	const WString JDFStrings::elm_TransferCurveSet=L"TransferCurveSet";
	const WString JDFStrings::elm_TransferFunctionControl=L"TransferFunctionControl";
	const WString JDFStrings::elm_TrappingDetails=L"TrappingDetails";
	const WString JDFStrings::elm_TrappingOrder=L"TrappingOrder";
	const WString JDFStrings::elm_TrappingParams=L"TrappingParams";
	const WString JDFStrings::elm_TrapRegion=L"TrapRegion";
	const WString JDFStrings::elm_Trigger=L"Trigger";
	const WString JDFStrings::elm_TrimmingParams=L"TrimmingParams";

	const WString JDFStrings::elm_Underage=L"Underage";
	const WString JDFStrings::elm_UpdateJDFCmdParams=L"UpdateJDFCmdParams";
	const WString JDFStrings::elm_USWeight=L"USWeight";

	const WString JDFStrings::elm_Value=L"Value";
	const WString JDFStrings::elm_VarnishingParams=L"VarnishingParams";
	const WString JDFStrings::elm_ValueLoc=L"ValueLoc";
	const WString JDFStrings::elm_VeloBindingParams=L"VeloBindingParams";
	const WString JDFStrings::elm_VerificationParams=L"VerificationParams";
	const WString JDFStrings::elm_ViewBinder=L"ViewBinder";

	const WString JDFStrings::elm_WakeUp=L"WakeUp";
	const WString JDFStrings::elm_WakeUpCmdParams=L"WakeUpCmdParams";
	const WString JDFStrings::elm_Weight=L"Weight";
	const WString JDFStrings::elm_when=L"when";
	const WString JDFStrings::elm_WireCombBinding=L"WireCombBinding";
	const WString JDFStrings::elm_WireCombBindingParams=L"WireCombBindingParams";
	const WString JDFStrings::elm_WireCombBrand=L"WireCombBrand";
	const WString JDFStrings::elm_WireCombMaterial=L"WireCombMaterial";
	const WString JDFStrings::elm_WireCombShape=L"WireCombShape";
	const WString JDFStrings::elm_WrappedQuantity=L"WrappedQuantity";
	const WString JDFStrings::elm_WrappingMaterial=L"WrappingMaterial";
	const WString JDFStrings::elm_WrappingParams=L"WrappingParams";

	const WString JDFStrings::elm_xor=L"xor";
	const WString JDFStrings::elm_XPosition=L"XPosition";
	const WString JDFStrings::elm_XYPairEvaluation=L"XYPairEvaluation";
	const WString JDFStrings::elm_XYPairState=L"XYPairState";

	const WString JDFStrings::elm_YPosition=L"YPosition";





const WString JDFStrings::elm_TabDimensions=L"TabDimensions";
const WString JDFStrings::elm_ColorantConvertProcess=L"ColorantConvertProcess";
const WString JDFStrings::elm_ContentMetaData=L"ContentMetaData";

const WString JDFStrings::elm_RuleLength=L"RuleLength";
const WString JDFStrings::elm_ShapeDef=L"ShapeDef";
const WString JDFStrings::elm_ConvertingConfig=L"ConvertingConfig";
const WString JDFStrings::elm_RepeatDesc=L"RepeatDesc";
const WString JDFStrings::elm_DieLayoutProductionParams=L"DieLayoutProductionParams";
const WString JDFStrings::elm_PageCondition=L"PageCondition";
const WString JDFStrings::elm_MarkActivation=L"MarkActivation";
const WString JDFStrings::elm_RefAnchor=L"RefAnchor";


const WString JDFStrings::elm_PositionObj=L"PositionObj";

const WString JDFStrings::elm_ShiftPoint=L"ShiftPoint";
const WString JDFStrings::elm_LayoutShift=L"LayoutShift";

const WString JDFStrings::elm_PageAssignParams=L"PageAssignParams";

const WString JDFStrings::elm_MetadataMap=L"MetadataMap";

const WString JDFStrings::elm_ObjectModel=L"ObjectModel";
const WString JDFStrings::elm_ShapeTemplate=L"ShapeTemplate";
const WString JDFStrings::elm_ShapeDefProductionParams=L"ShapeDefProductionParams";

const WString JDFStrings::elm_StaticBlockingParams=L"StaticBlockingParams";


const WString JDFStrings::elm_ControllerFilter=L"ControllerFilter";

const WString JDFStrings::elm_SubscriptionFilter=L"SubscriptionFilter";
const WString JDFStrings::elm_SubscriptionInfo=L"SubscriptionInfo";

const WString JDFStrings::elm_Certificate=L"Certificate";
const WString JDFStrings::elm_AuthenticationResp=L"AuthenticationResp";
const WString JDFStrings::elm_AuthenticationQuParams=L"AuthenticationQuParams";
const WString JDFStrings::elm_AuthenticationCmdParams=L"AuthenticationCmdParams";

const WString JDFStrings::elm_Flute=L"Flute";
const WString JDFStrings::elm_FluteDirection=L"FluteDirection";
const WString JDFStrings::elm_MediaQuality=L"MediaQuality";

const WString JDFStrings::elm_TabMylarColorDetails=L"TabMylarColorDetails";
const WString JDFStrings::elm_ColorNameDetails=L"ColorNameDetails";
const WString JDFStrings::elm_HeadBandColorDetails=L"HeadBandColorDetails";
const WString JDFStrings::elm_FoilColorDetails=L"FoilColorDetails";
const WString JDFStrings::elm_BindingColorDetails=L"BindingColorDetails";
const WString JDFStrings::elm_CoverColorDetails=L"CoverColorDetails";
const WString JDFStrings::elm_BackCoverColorDetails=L"BackCoverColorDetails";

	
	//////////////////////////////////////////////////////////

	const WString JDFStrings::atr_Aborted=L"Aborted";
	const WString JDFStrings::atr_AbortJobWhenScreenMatchingFails=L"AbortJobWhenScreenMatchingFails";
	const WString JDFStrings::atr_AbsoluteBox=L"AbsoluteBox";
	const WString JDFStrings::atr_Accepted=L"Accepted";
	const WString JDFStrings::atr_Acknowledge=L"Acknowledge";
	const WString JDFStrings::atr_Acknowledged=L"Acknowledged";
	const WString JDFStrings::atr_AcknowledgeFormat=L"AcknowledgeFormat";
	const WString JDFStrings::atr_AcknowledgeTemplate=L"AcknowledgeTemplate";
	const WString JDFStrings::atr_AcknowledgeType=L"AcknowledgeType";
	const WString JDFStrings::atr_AcknowledgeURL=L"AcknowledgeURL";
	const WString JDFStrings::atr_Action=L"Action";
	const WString JDFStrings::atr_ActionPools=L"ActionPools";
	const WString JDFStrings::atr_ActionRef=L"ActionRef";
	const WString JDFStrings::atr_ActionRefs=L"ActionRefs";
	const WString JDFStrings::atr_Activation=L"Activation";
	const WString JDFStrings::atr_Actual=L"Actual";
	const WString JDFStrings::atr_ActualAmount=L"ActualAmount";
	const WString JDFStrings::atr_ActualTotalAmount=L"ActualTotalAmount";
	const WString JDFStrings::atr_AdditionalAmount=L"AdditionalAmount";
	const WString JDFStrings::atr_AdditionalNames=L"AdditionalNames";
	const WString JDFStrings::atr_AdditionalPrice=L"AdditionalPrice";
	const WString JDFStrings::atr_AdhesiveType=L"AdhesiveType";
	const WString JDFStrings::atr_AdjustContrast=L"AdjustContrast";
	const WString JDFStrings::atr_AdjustCyanRed=L"AdjustCyanRed";
	const WString JDFStrings::atr_AdjustHue=L"AdjustHue";
	const WString JDFStrings::atr_AdjustLightness=L"AdjustLightness";
	const WString JDFStrings::atr_AdjustMagentaGreen=L"AdjustMagentaGreen";
	const WString JDFStrings::atr_AdjustSaturation=L"AdjustSaturation";
	const WString JDFStrings::atr_AdjustYellowBlue=L"AdjustYellowBlue";
	const WString JDFStrings::atr_AdvanceDistance=L"AdvanceDistance";
	const WString JDFStrings::atr_After=L"After";
	const WString JDFStrings::atr_AgentName=L"AgentName";
	const WString JDFStrings::atr_AgentVersion=L"AgentVersion";
	const WString JDFStrings::atr_AimCurve=L"AimCurve";
	const WString JDFStrings::atr_Alias=L"Alias";
	const WString JDFStrings::atr_AliasSeparations=L"AliasSeparations";
	const WString JDFStrings::atr_AllowedHWRelation=L"AllowedHWRelation";
	const WString JDFStrings::atr_AllowedLength=L"AllowedLength";
	const WString JDFStrings::atr_AllowedRegExp=L"AllowedRegExp";
	const WString JDFStrings::atr_AllowedRotateMod=L"AllowedRotateMod";
	const WString JDFStrings::atr_AllowedShift=L"AllowedShift";
	const WString JDFStrings::atr_AllowedTransforms=L"AllowedTransforms";
	const WString JDFStrings::atr_AllowedValue=L"AllowedValue";
	const WString JDFStrings::atr_AllowedValueDurationList=L"AllowedValueDurationList";
	const WString JDFStrings::atr_AllowedValueList=L"AllowedValueList";
	const WString JDFStrings::atr_AllowedValueMax=L"AllowedValueMax";
	const WString JDFStrings::atr_AllowedValueMin=L"AllowedValueMin";
	const WString JDFStrings::atr_AllowedValueMod=L"AllowedValueMod";
	const WString JDFStrings::atr_AllowedX=L"AllowedX";
	const WString JDFStrings::atr_AllowedXYRelation=L"AllowedXYRelation";
	const WString JDFStrings::atr_AllowedY=L"AllowedY";
	const WString JDFStrings::atr_AllowedZ=L"AllowedZ";
	const WString JDFStrings::atr_AllowPSXObjects=L"AllowPSXObjects";
	const WString JDFStrings::atr_AllowTransparency=L"AllowTransparency";
	const WString JDFStrings::atr_AlphaIsShape=L"AlphaIsShape";
	const WString JDFStrings::atr_AlternateBrand=L"AlternateBrand";
	const WString JDFStrings::atr_AlternateColorSpace=L"AlternateColorSpace";
	const WString JDFStrings::atr_AlternateImages=L"AlternateImages";
	const WString JDFStrings::atr_AlternatePositions=L"AlternatePositions";
	const WString JDFStrings::atr_AlwaysEmbed=L"AlwaysEmbed";
	const WString JDFStrings::atr_AmbiguousSeparations=L"AmbiguousSeparations";
	const WString JDFStrings::atr_Amount=L"Amount";
	const WString JDFStrings::atr_AmountProduced=L"AmountProduced";	
	const WString JDFStrings::atr_AmountRequired=L"AmountRequired";	
	const WString JDFStrings::atr_Angle=L"Angle";
	const WString JDFStrings::atr_AngleMap=L"AngleMap";
	const WString JDFStrings::atr_AnnotationPrintFlag=L"AnnotationPrintFlag";
	const WString JDFStrings::atr_AnnotationType=L"AnnotationType";
	const WString JDFStrings::atr_AntiAliasing=L"AntiAliasing";
	const WString JDFStrings::atr_AntiAliasImages=L"AntiAliasImages";
	const WString JDFStrings::atr_Application=L"Application";
	const WString JDFStrings::atr_ApplicationArea=L"ApplicationArea";
	const WString JDFStrings::atr_AppOS=L"AppOS";
	const WString JDFStrings::atr_ApprovalRole=L"ApprovalRole";
	const WString JDFStrings::atr_ApprovalRoleDetails=L"ApprovalRoleDetails";
	const WString JDFStrings::atr_ApprovalState=L"ApprovalState";
	const WString JDFStrings::atr_ApprovalStateDetails=L"ApprovalStateDetails";
	const WString JDFStrings::atr_AppVersion=L"AppVersion";
	const WString JDFStrings::atr_AreaGlue=L"AreaGlue";
	const WString JDFStrings::atr_ArtDeliveryType=L"ArtDeliveryType";
	const WString JDFStrings::atr_ASCII85EncodePages=L"ASCII85EncodePages";
	const WString JDFStrings::atr_AspectRatio=L"AspectRatio";
	const WString JDFStrings::atr_AssemblyID=L"AssemblyID";
	const WString JDFStrings::atr_AssemblyIDs=L"AssemblyIDs";
	const WString JDFStrings::atr_AssetTypes=L"AssetTypes";
	const WString JDFStrings::atr_AttemptFixupErrors=L"AttemptFixupErrors";
	const WString JDFStrings::atr_AttemptFixupWarnings=L"AttemptFixupWarnings";
	const WString JDFStrings::atr_Attribute=L"Attribute";
	const WString JDFStrings::atr_AttributeName=L"AttributeName";
	const WString JDFStrings::atr_Attributes=L"Attributes";
	const WString JDFStrings::atr_AttributesNaturalLang=L"AttributesNaturalLang";
	const WString JDFStrings::atr_Author=L"Author";
	const WString JDFStrings::atr_Authorization=L"Authorization";
	const WString JDFStrings::atr_AuthorizationExpires=L"AuthorizationExpires";
	const WString JDFStrings::atr_AutoFilterImages=L"AutoFilterImages";
	const WString JDFStrings::atr_Automated=L"Automated";
	const WString JDFStrings::atr_AutoPositionEPSInfo=L"AutoPositionEPSInfo";
	const WString JDFStrings::atr_AutoRotatePages=L"AutoRotatePages";
	const WString JDFStrings::atr_AvailableAmount=L"AvailableAmount";
	const WString JDFStrings::atr_Availability=L"Availability";
	const WString JDFStrings::atr_AverageAmount=L"AverageAmount";
	const WString JDFStrings::atr_AverageCleanup=L"AverageCleanup";
	const WString JDFStrings::atr_AverageSetup=L"AverageSetup";

	// BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB //

	const WString JDFStrings::atr_BackCoatings=L"BackCoatings";
	const WString JDFStrings::atr_BackFacePages=L"BackFacePages";
	const WString JDFStrings::atr_BackGlossValue=L"BackGlossValue";
	const WString JDFStrings::atr_Backing=L"Backing";
	const WString JDFStrings::atr_BackMarkList=L"BackMarkList";
	const WString JDFStrings::atr_BackOverfold=L"BackOverfold";
	const WString JDFStrings::atr_BackPages=L"BackPages";
	const WString JDFStrings::atr_BackSide=L"BackSide";
	const WString JDFStrings::atr_BadFeedQuality=L"BadFeedQuality";
	const WString JDFStrings::atr_BadFeeds=L"BadFeeds";
	const WString JDFStrings::atr_BandHeight=L"BandHeight";
	const WString JDFStrings::atr_BandOrdering=L"BandOrdering";
	const WString JDFStrings::atr_BandWidth=L"BandWidth";
	const WString JDFStrings::atr_BarcodeVersion=L"BarcodeVersion";
	const WString JDFStrings::atr_BaseOrdReset=L"BaseOrdReset";
	const WString JDFStrings::atr_BatchID=L"BatchID";	

	const WString JDFStrings::atr_BearerBars=L"BearerBars";
	const WString JDFStrings::atr_Before=L"Before";
	const WString JDFStrings::atr_BelongsToAnnotation=L"BelongsToAnnotation";
	const WString JDFStrings::atr_Bend=L"Bend";
	const WString JDFStrings::atr_BestEffortExceptions=L"BestEffortExceptions";
	const WString JDFStrings::atr_BillingCode=L"BillingCode";
	const WString JDFStrings::atr_BillingType=L"BillingType";
	const WString JDFStrings::atr_BillingTypeDetails=L"BillingTypeDetails";
	const WString JDFStrings::atr_BinaryOK=L"BinaryOK";
	const WString JDFStrings::atr_BinaryValue=L"BinaryValue";
	const WString JDFStrings::atr_BinderColor=L"BinderColor";
	const WString JDFStrings::atr_BinderMaterial=L"BinderMaterial";
	const WString JDFStrings::atr_BinderySignatureName=L"BinderySignatureName";
	const WString JDFStrings::atr_BinderySignaturePaginationIndex=L"BinderySignaturePaginationIndex";
	const WString JDFStrings::atr_BinderySignatureType=L"BinderySignatureType";
	const WString JDFStrings::atr_BinderName=L"BinderName";
	const WString JDFStrings::atr_Binding=L"Binding";
	const WString JDFStrings::atr_BindingEdge=L"BindingEdge";
	const WString JDFStrings::atr_BindingOrder=L"BindingOrder";
	const WString JDFStrings::atr_BindingOrientation=L"BindingOrientation";
	const WString JDFStrings::atr_BindingSide=L"BindingSide";
	const WString JDFStrings::atr_BitDepth=L"BitDepth";
	const WString JDFStrings::atr_BitsPerSample=L"BitsPerSample";
	const WString JDFStrings::atr_BlackColorLimit=L"BlackColorLimit";
	const WString JDFStrings::atr_BlackDensityLimit=L"BlackDensityLimit";
	const WString JDFStrings::atr_BlackGeneration=L"BlackGeneration";
	const WString JDFStrings::atr_BlackWidth=L"BlackWidth";
	const WString JDFStrings::atr_BlankDimensionsX=L"BlankDimensionsX";
	const WString JDFStrings::atr_BlankDimensionsY=L"BlankDimensionsY";
	const WString JDFStrings::atr_BlankPage=L"BlankPage";
	const WString JDFStrings::atr_BleedFace=L"BleedFace";
	const WString JDFStrings::atr_BleedFoot=L"BleedFoot";
	const WString JDFStrings::atr_BleedHead=L"BleedHead";
	const WString JDFStrings::atr_BleedSpine=L"BleedSpine";
	const WString JDFStrings::atr_BlendColorSpace=L"BlendColorSpace";
	const WString JDFStrings::atr_BlendMode=L"BlendMode";
	const WString JDFStrings::atr_BlindStitch=L"BlindStitch";
	const WString JDFStrings::atr_BlockElementSize=L"BlockElementSize";
	const WString JDFStrings::atr_BlockElementType=L"BlockElementType";
	const WString JDFStrings::atr_BlockName=L"BlockName";
	const WString JDFStrings::atr_Blocks=L"Blocks";
	const WString JDFStrings::atr_BlockSize=L"BlockSize";
	const WString JDFStrings::atr_BlockSubdivision=L"BlockSubdivision";
	const WString JDFStrings::atr_BlockTrf=L"BlockTrf";
	const WString JDFStrings::atr_BlockType=L"BlockType";
	const WString JDFStrings::atr_Border=L"Border";
	const WString JDFStrings::atr_BottleAngle=L"BottleAngle";
	const WString JDFStrings::atr_BottleAxis=L"BottleAxis";
	const WString JDFStrings::atr_BottomBrand=L"BottomBrand";
	const WString JDFStrings::atr_BottomColor=L"BottomColor";
	const WString JDFStrings::atr_BottomFoldIn=L"BottomFoldIn";
	const WString JDFStrings::atr_BottomLength=L"BottomLength";
	const WString JDFStrings::atr_BoundingBox=L"BoundingBox";
	const WString JDFStrings::atr_Box=L"Box";
	const WString JDFStrings::atr_BoxFoldingType=L"BoxFoldingType";
	const WString JDFStrings::atr_BoxedQuantity=L"BoxedQuantity";
	const WString JDFStrings::atr_BoxShape=L"BoxShape";
	const WString JDFStrings::atr_Brand=L"Brand";
	const WString JDFStrings::atr_Brightness=L"Brightness";
	const WString JDFStrings::atr_BroadsheetNumber=L"BroadsheetNumber";

	const WString JDFStrings::atr_BundleDepth=L"BundleDepth";
	const WString JDFStrings::atr_BundleItemIndex=L"BundleItemIndex";
	const WString JDFStrings::atr_BundleType=L"BundleType";
	const WString JDFStrings::atr_BurnOutArea=L"BurnOutArea";
	const WString JDFStrings::atr_BusinessID=L"BusinessID";
	const WString JDFStrings::atr_BusinessRefID=L"BusinessRefID";
	const WString JDFStrings::atr_Busy=L"Busy";
	const WString JDFStrings::atr_BuyerAccount=L"BuyerAccount";
	const WString JDFStrings::atr_ByteOrder=L"ByteOrder";

	// CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC //

	const WString JDFStrings::atr_CannotEmbedFontPolicy=L"CannotEmbedFontPolicy";
	const WString JDFStrings::atr_Capacity=L"Capacity";
	const WString JDFStrings::atr_CartonMaxWeight=L"CartonMaxWeight";
	const WString JDFStrings::atr_CartonQuantity=L"CartonQuantity";
	const WString JDFStrings::atr_CartonShape=L"CartonShape";
	const WString JDFStrings::atr_CartonStrength=L"CartonStrength";
	const WString JDFStrings::atr_CartonTopFlaps=L"CartonTopFlaps";
	const WString JDFStrings::atr_CaseRadius=L"CaseRadius";
	const WString JDFStrings::atr_CastingMaterial=L"CastingMaterial";
	const WString JDFStrings::atr_CatalogID=L"CatalogID";
	const WString JDFStrings::atr_CatalogDetails=L"CatalogDetails";
	const WString JDFStrings::atr_Category=L"Category";
	const WString JDFStrings::atr_CellIndex=L"CellIndex";
	const WString JDFStrings::atr_Center=L"Center";
	const WString JDFStrings::atr_CenterAcross=L"CenterAcross";
	const WString JDFStrings::atr_CenterCropBox=L"CenterCropBox";
	const WString JDFStrings::atr_CenterReference=L"CenterReference";
	const WString JDFStrings::atr_ChannelID=L"ChannelID";
	const WString JDFStrings::atr_ChannelType=L"ChannelType";
	const WString JDFStrings::atr_ChannelTypeDetails=L"ChannelTypeDetails";
	const WString JDFStrings::atr_ChannelUsage=L"ChannelUsage";
	const WString JDFStrings::atr_CharacterProblem=L"CharacterProblem";
	const WString JDFStrings::atr_CheckSum=L"CheckSum";
	const WString JDFStrings::atr_ChildFolio=L"ChildFolio";
	const WString JDFStrings::atr_CIELab=L"CIELab";
	const WString JDFStrings::atr_CIETint=L"CIETint";
	const WString JDFStrings::atr_CIEWhiteness=L"CIEWhiteness";
	const WString JDFStrings::atr_City=L"City";
	const WString JDFStrings::atr_ClampColor=L"ClampColor";
	const WString JDFStrings::atr_ClampD=L"ClampD";
	const WString JDFStrings::atr_ClampSize=L"ClampSize";
	const WString JDFStrings::atr_ClampSystem=L"ClampSystem";
	const WString JDFStrings::atr_Class=L"Class";
	const WString JDFStrings::atr_Classes=L"Classes";
	const WString JDFStrings::atr_ClassName=L"ClassName";
	const WString JDFStrings::atr_CleanupDuration=L"CleanupDuration";
	const WString JDFStrings::atr_ClipBox=L"ClipBox";
	const WString JDFStrings::atr_ClipBoxFormat=L"ClipBoxFormat";
	const WString JDFStrings::atr_ClipBoxTemplate=L"ClipBoxTemplate";
	const WString JDFStrings::atr_ClipOffset=L"ClipOffset";
	const WString JDFStrings::atr_ClipPath=L"ClipPath";
	const WString JDFStrings::atr_CMYK=L"CMYK";

	const WString JDFStrings::atr_Code=L"Code";
	const WString JDFStrings::atr_CodeBlockSize=L"CodeBlockSize";
	const WString JDFStrings::atr_Collate=L"Collate";
	const WString JDFStrings::atr_Color=L"Color";
	const WString JDFStrings::atr_Colorant=L"Colorant";
	const WString JDFStrings::atr_ColorantDepth=L"ColorantDepth";
	const WString JDFStrings::atr_ColorantName=L"ColorantName";
	const WString JDFStrings::atr_ColorantSetName=L"ColorantSetName";
	const WString JDFStrings::atr_ColorBook=L"ColorBook";
	const WString JDFStrings::atr_ColorBookEntry=L"ColorBookEntry";
	const WString JDFStrings::atr_ColorBookPrefix=L"ColorBookPrefix";
	const WString JDFStrings::atr_ColorBookSuffix=L"ColorBookSuffix";
	const WString JDFStrings::atr_ColorList=L"ColorList";
	const WString JDFStrings::atr_ColorManagementSystem=L"ColorManagementSystem";
	const WString JDFStrings::atr_ColorName=L"ColorName";
	const WString JDFStrings::atr_ColorSpace=L"ColorSpace";
	const WString JDFStrings::atr_ColorTransform=L"ColorTransform";
	const WString JDFStrings::atr_ColorType=L"ColorType";
	const WString JDFStrings::atr_CombinedMethod=L"CombinedMethod";
	const WString JDFStrings::atr_CombinedProcessIndex=L"CombinedProcessIndex";
	const WString JDFStrings::atr_CombinedProcessType=L"CombinedProcessType";
	const WString JDFStrings::atr_CombinedProcessUsage=L"CombinedProcessUsage";
	const WString JDFStrings::atr_Command=L"Command";
	const WString JDFStrings::atr_CommentID=L"CommentID";
	const WString JDFStrings::atr_CommentURL=L"CommentURL";
	const WString JDFStrings::atr_Company=L"Company";
	const WString JDFStrings::atr_Compensate=L"Compensate";
	const WString JDFStrings::atr_Compensation=L"Compensation";		
	const WString JDFStrings::atr_CompensationCTMFormat=L"CompensationCTMFormat";		
	const WString JDFStrings::atr_CompensationCTMTemplate=L"CompensationCTMTemplate";		
	
	const WString JDFStrings::atr_CompensationProcess=L"CompensationProcess";
	const WString JDFStrings::atr_CompensationValue=L"CompensationValue";
	const WString JDFStrings::atr_Completed=L"Completed";
	const WString JDFStrings::atr_ComponentGranularity=L"ComponentGranularity";
	const WString JDFStrings::atr_ComponentsPerRow=L"ComponentsPerRow";
	const WString JDFStrings::atr_ComponentType=L"ComponentType";
	const WString JDFStrings::atr_Compression=L"Compression";
	const WString JDFStrings::atr_CompressionAlgorithm=L"CompressionAlgorithm";
	const WString JDFStrings::atr_CompressionFilter=L"CompressionFilter";
	const WString JDFStrings::atr_CompressionRatio=L"CompressionRatio";
	const WString JDFStrings::atr_CompressionTypes=L"CompressionTypes";
	const WString JDFStrings::atr_CompressPages=L"CompressPages";
	const WString JDFStrings::atr_Condition=L"Condition";
	const WString JDFStrings::atr_Constraint=L"Constraint";
	const WString JDFStrings::atr_Consumption=L"Consumption";
	const WString JDFStrings::atr_ConsumableType=L"ConsumableType";
	const WString JDFStrings::atr_Contact=L"Contact";
	const WString JDFStrings::atr_ContactScreen=L"ContactScreen";
	const WString JDFStrings::atr_ContactTypeDetails=L"ContactTypeDetails";
	const WString JDFStrings::atr_ContactTypes=L"ContactTypes";
	const WString JDFStrings::atr_ContentListIndex=L"ContentListIndex";
	const WString JDFStrings::atr_ContentsModified=L"ContentsModified";
	const WString JDFStrings::atr_ContentType=L"ContentType";
	const WString JDFStrings::atr_Context=L"Context";
	const WString JDFStrings::atr_Contract=L"Contract";
	const WString JDFStrings::atr_ControllerID=L"ControllerID";
	const WString JDFStrings::atr_ConvertDevIndepColors=L"ConvertDevIndepColors";
	const WString JDFStrings::atr_ConvertImagesToIndexed=L"ConvertImagesToIndexed";
	const WString JDFStrings::atr_Copies=L"Copies";
	const WString JDFStrings::atr_CoreMaterial=L"CoreMaterial";
	const WString JDFStrings::atr_CoreWeight=L"CoreWeight";
	const WString JDFStrings::atr_CornerType=L"CornerType";

	const WString JDFStrings::atr_CostCenterID=L"CostCenterID";
	const WString JDFStrings::atr_CostType=L"CostType";
	const WString JDFStrings::atr_CostTypeDetails=L"CostTypeDetails";
	const WString JDFStrings::atr_Count=L"Count";
	const WString JDFStrings::atr_CounterID=L"CounterID";
	const WString JDFStrings::atr_CounterTypes=L"CounterTypes";
	const WString JDFStrings::atr_CounterUnit=L"CounterUnit";
	const WString JDFStrings::atr_Country=L"Country";
	const WString JDFStrings::atr_CountryCode=L"CountryCode";
	const WString JDFStrings::atr_CoverOffset=L"CoverOffset";
	const WString JDFStrings::atr_CoverType=L"CoverType";
	const WString JDFStrings::atr_CoverWidth=L"CoverWidth";
	const WString JDFStrings::atr_CreationDate=L"CreationDate";
	const WString JDFStrings::atr_CreationDateInDocument=L"CreationDateInDocument";
	const WString JDFStrings::atr_CreationID=L"CreationID";
	const WString JDFStrings::atr_Creator=L"Creator";
	const WString JDFStrings::atr_Creep=L"Creep";
	const WString JDFStrings::atr_CreepValue=L"CreepValue";
	const WString JDFStrings::atr_CTM=L"CTM";

	const WString JDFStrings::atr_Currency=L"Currency";
	const WString JDFStrings::atr_CurrentValue=L"CurrentValue";
	const WString JDFStrings::atr_Curve=L"Curve";
	const WString JDFStrings::atr_CustomerID=L"CustomerID";
	const WString JDFStrings::atr_CustomerJobName=L"CustomerJobName";
	const WString JDFStrings::atr_CustomerOrderID=L"CustomerOrderID";
	const WString JDFStrings::atr_CustomerProjectID=L"CustomerProjectID";
	const WString JDFStrings::atr_CutBox=L"CutBox";
	const WString JDFStrings::atr_CutMedia=L"CutMedia";
	const WString JDFStrings::atr_CutOut=L"CutOut";
	const WString JDFStrings::atr_CutPath=L"CutPath";
	const WString JDFStrings::atr_CutType=L"CutType";
	const WString JDFStrings::atr_CutWidthFoot=L"CutWidthFoot";
	const WString JDFStrings::atr_CutWidthHead=L"CutWidthHead";
	const WString JDFStrings::atr_Cycle=L"Cycle";

	// DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD//

	const WString JDFStrings::atr_Data=L"Data";
	const WString JDFStrings::atr_DataBase=L"DataBase";
	const WString JDFStrings::atr_DataType=L"DataType";
	const WString JDFStrings::atr_DBSchemaType=L"DBSchemaType";
	const WString JDFStrings::atr_DCTQuality=L"DCTQuality";
	const WString JDFStrings::atr_DeadLine=L"DeadLine";
	const WString JDFStrings::atr_DefaultID=L"DefaultID";
	const WString JDFStrings::atr_DefaultJDF=L"DefaultJDF";
	const WString JDFStrings::atr_DefaultPriority=L"DefaultPriority";
	const WString JDFStrings::atr_DefaultRenderingIntent=L"DefaultRenderingIntent";
	const WString JDFStrings::atr_DefaultTrapping=L"DefaultTrapping";
	const WString JDFStrings::atr_DefaultValue=L"DefaultValue";
	const WString JDFStrings::atr_DeliveryMode=L"DeliveryMode";
	const WString JDFStrings::atr_DeliveryUnit=L"DeliveryUnit";
	const WString JDFStrings::atr_DeliveryUnit0=L"DeliveryUnit0";
	const WString JDFStrings::atr_DeliveryUnit1=L"DeliveryUnit1";
	const WString JDFStrings::atr_DeliveryUnit2=L"DeliveryUnit2";
	const WString JDFStrings::atr_DeliveryUnit3=L"DeliveryUnit3";
	const WString JDFStrings::atr_DeliveryUnit4=L"DeliveryUnit4";
	const WString JDFStrings::atr_DeliveryUnit5=L"DeliveryUnit5";
	const WString JDFStrings::atr_DeliveryUnit6=L"DeliveryUnit6";
	const WString JDFStrings::atr_DeliveryUnit7=L"DeliveryUnit7";
	const WString JDFStrings::atr_DeliveryUnit8=L"DeliveryUnit8";
	const WString JDFStrings::atr_DeliveryUnit9=L"DeliveryUnit9";
	const WString JDFStrings::atr_Density=L"Density";
	const WString JDFStrings::atr_DensityStandard=L"DensityStandard";
	const WString JDFStrings::atr_DependentMacroRef=L"DependentMacroRef";
	const WString JDFStrings::atr_Depth=L"Depth";
	const WString JDFStrings::atr_DescriptionType=L"DescriptionType";
	const WString JDFStrings::atr_DescriptiveName=L"DescriptiveName";
	const WString JDFStrings::atr_DetectBlend=L"DetectBlend";
	const WString JDFStrings::atr_DevCapRef=L"DevCapRef";
	const WString JDFStrings::atr_DevCapRefs=L"DevCapRefs";
	const WString JDFStrings::atr_DevCapsRef=L"DevCapsRef";
	const WString JDFStrings::atr_DeviceCondition=L"DeviceCondition";
	const WString JDFStrings::atr_DeviceDetails=L"DeviceDetails";
	const WString JDFStrings::atr_DeviceFamily=L"DeviceFamily";
	const WString JDFStrings::atr_DeviceID=L"DeviceID";
	const WString JDFStrings::atr_DeviceModuleIndex=L"DeviceModuleIndex";
	const WString JDFStrings::atr_DeviceOperationMode=L"DeviceOperationMode";
	const WString JDFStrings::atr_DeviceStatus=L"DeviceStatus";
	const WString JDFStrings::atr_DeviceType=L"DeviceType";
	const WString JDFStrings::atr_DevNS=L"DevNS";
	const WString JDFStrings::atr_Diameter=L"Diameter";
	const WString JDFStrings::atr_DifferentBoxSize=L"DifferentBoxSize";
	const WString JDFStrings::atr_Diffusion=L"Diffusion";
	const WString JDFStrings::atr_DigitalDeliveryDirection=L"DigitalDeliveryDirection";
	const WString JDFStrings::atr_DigitalDeliveryProtocol=L"DigitalDeliveryProtocol";
	const WString JDFStrings::atr_Dimension=L"Dimension";
	const WString JDFStrings::atr_Dimensions=L"Dimensions";
	const WString JDFStrings::atr_Direction=L"Direction";
	const WString JDFStrings::atr_Directory=L"Directory";
	const WString JDFStrings::atr_DirectProof=L"DirectProof";
	const WString JDFStrings::atr_DirectProofAmount=L"DirectProofAmount";
	const WString JDFStrings::atr_DisplayTraps=L"DisplayTraps";
	const WString JDFStrings::atr_Disposition=L"Disposition";
	const WString JDFStrings::atr_DispositionUsage=L"DispositionUsage";
	const WString JDFStrings::atr_DispositionAction=L"DispositionAction";
	const WString JDFStrings::atr_Distance=L"Distance";
	const WString JDFStrings::atr_DividePositions=L"DividePositions";
	const WString JDFStrings::atr_DocCopies=L"DocCopies";
	const WString JDFStrings::atr_DocIndex=L"DocIndex";
	const WString JDFStrings::atr_DocNames=L"DocNames";
	const WString JDFStrings::atr_DocOrd=L"DocOrd";
	const WString JDFStrings::atr_DocRunIndex=L"DocRunIndex";
	const WString JDFStrings::atr_Docs=L"Docs";
	const WString JDFStrings::atr_DocSheetIndex=L"DocSheetIndex";
	const WString JDFStrings::atr_DocTags=L"DocTags";
	const WString JDFStrings::atr_DocumentCompression=L"DocumentCompression";
	const WString JDFStrings::atr_DocumentCorruption=L"DocumentCorruption";
	const WString JDFStrings::atr_DocumentEncoding=L"DocumentEncoding";
	const WString JDFStrings::atr_DocumentIsGoodCompression=L"DocumentIsGoodCompression";
	const WString JDFStrings::atr_DocumentNaturalLang=L"DocumentNaturalLang";
	const WString JDFStrings::atr_DocumentPDLType=L"DocumentPDLType";
	const WString JDFStrings::atr_DotGain=L"DotGain";
	const WString JDFStrings::atr_DoThumbnails=L"DoThumbnails";
	const WString JDFStrings::atr_DotSize=L"DotSize";
	const WString JDFStrings::atr_DoubleFeedQuality=L"DoubleFeedQuality";
	const WString JDFStrings::atr_DoubleFeeds=L"DoubleFeeds";
	const WString JDFStrings::atr_DownsampleImages=L"DownsampleImages";
	const WString JDFStrings::atr_DraftOK=L"DraftOK";
	const WString JDFStrings::atr_Drying=L"Drying";
	const WString JDFStrings::atr_DueLevel=L"DueLevel";
	const WString JDFStrings::atr_Duration=L"Duration";

	// EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE //

	const WString JDFStrings::atr_Earliest=L"Earliest";
	const WString JDFStrings::atr_EarlyChange=L"EarlyChange";
	const WString JDFStrings::atr_EdgeAngle=L"EdgeAngle";
	const WString JDFStrings::atr_EdgeShape=L"EdgeShape";
	const WString JDFStrings::atr_Editable=L"Editable";
	const WString JDFStrings::atr_Edition=L"Edition";
	const WString JDFStrings::atr_EditionVersion=L"EditionVersion";
	const WString JDFStrings::atr_EffectiveResolution=L"EffectiveResolution";
	const WString JDFStrings::atr_Effort=L"Effort";
	const WString JDFStrings::atr_ElementID=L"ElementID";
	const WString JDFStrings::atr_ElementPages=L"ElementPages";
	const WString JDFStrings::atr_ElementIDs=L"ElementIDs";
	const WString JDFStrings::atr_ElementType=L"ElementType";
	const WString JDFStrings::atr_EmbedAllFonts=L"EmbedAllFonts";
	const WString JDFStrings::atr_EmbeddedPS=L"EmbeddedPS";
	const WString JDFStrings::atr_EmbeddingRestrictionFlag=L"EmbeddingRestrictionFlag";
	const WString JDFStrings::atr_EmbedJobOptions=L"EmbedJobOptions";
	const WString JDFStrings::atr_EmbossingType=L"EmbossingType";
	const WString JDFStrings::atr_EmitDSCWarnings=L"EmitDSCWarnings";
	const WString JDFStrings::atr_EmitPDFBG=L"EmitPDFBG";
	const WString JDFStrings::atr_EmitPDFHalftones=L"EmitPDFHalftones";
	const WString JDFStrings::atr_EmitPDFTransfers=L"EmitPDFTransfers";
	const WString JDFStrings::atr_EmitPDFUCR=L"EmitPDFUCR";
	const WString JDFStrings::atr_EmployeeInfo=L"EmployeeInfo";
	const WString JDFStrings::atr_Enabled=L"Enabled";
	const WString JDFStrings::atr_EncodeColorImages=L"EncodeColorImages";
	const WString JDFStrings::atr_EncodedByteAlign=L"EncodedByteAlign";
	const WString JDFStrings::atr_EncodeImages=L"EncodeImages";
	const WString JDFStrings::atr_Encoding=L"Encoding";
	const WString JDFStrings::atr_EncodingDetails=L"EncodingDetails";
	const WString JDFStrings::atr_EncryptedDocument=L"EncryptedDocument";
	const WString JDFStrings::atr_EncryptionFilter=L"EncryptionFilter";
	const WString JDFStrings::atr_EncryptionLength=L"EncryptionLength";
	const WString JDFStrings::atr_EncryptionRestrictions=L"EncryptionRestrictions";
	const WString JDFStrings::atr_EncryptionSubFilter=L"EncryptionSubFilter";
	const WString JDFStrings::atr_EncryptionV=L"EncryptionV";
	const WString JDFStrings::atr_End=L"End";
	const WString JDFStrings::atr_EndOfBlock=L"EndOfBlock";
	const WString JDFStrings::atr_EndOfBundleItem=L"EndOfBundleItem";
	const WString JDFStrings::atr_EndOfDocument=L"EndOfDocument";
	const WString JDFStrings::atr_EndOfLine=L"EndOfLine";
	const WString JDFStrings::atr_EndOfSet=L"EndOfSet";
	const WString JDFStrings::atr_EndPage=L"EndPage";
	const WString JDFStrings::atr_EndStatus=L"EndStatus";
	const WString JDFStrings::atr_EndTime=L"EndTime";
	const WString JDFStrings::atr_ErrorCount=L"ErrorCount";
	const WString JDFStrings::atr_ErrorCorrectionLevel=L"ErrorCorrectionLevel";
	const WString JDFStrings::atr_ErrorID=L"ErrorID";
	const WString JDFStrings::atr_ErrorState=L"ErrorState";
	const WString JDFStrings::atr_ErrorType=L"ErrorType";
	const WString JDFStrings::atr_ErrorURL=L"ErrorURL";
	const WString JDFStrings::atr_EstimatedJPEGQuality=L"EstimatedJPEGQuality";
	const WString JDFStrings::atr_EventID=L"EventID";
	const WString JDFStrings::atr_EventValue=L"EventValue";
	const WString JDFStrings::atr_Exact=L"Exact";
	const WString JDFStrings::atr_ExecutionPolicy=L"ExecutionPolicy";
	const WString JDFStrings::atr_Expires=L"Expires";
	const WString JDFStrings::atr_Extent=L"Extent";
	const WString JDFStrings::atr_ExternalReferenceMissing=L"ExternalReferenceMissing";
	const WString JDFStrings::atr_ExtraDuration=L"ExtraDuration";

	// FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF//

	const WString JDFStrings::atr_Failed=L"Failed";
	const WString JDFStrings::atr_Family=L"Family";
	const WString JDFStrings::atr_FamilyName=L"FamilyName";
	const WString JDFStrings::atr_FeederSynchronization=L"FeederSynchronization";
	const WString JDFStrings::atr_FeederType=L"FeederType";
	const WString JDFStrings::atr_FieldRange=L"FieldRange";
	const WString JDFStrings::atr_File=L"file";
	const WString JDFStrings::atr_FileFormat=L"FileFormat";
	const WString JDFStrings::atr_FileName=L"FileName";
	const WString JDFStrings::atr_FilePath=L"FilePath";
	const WString JDFStrings::atr_FilePerPage=L"FilePerPage";
	const WString JDFStrings::atr_FileSize=L"FileSize";
	const WString JDFStrings::atr_FileTargetDeviceModel=L"FileTargetDeviceModel";
	const WString JDFStrings::atr_FileTemplate=L"FileTemplate";
	const WString JDFStrings::atr_FileVersion=L"FileVersion";
	const WString JDFStrings::atr_FillColorName=L"FillColorName";
	const WString JDFStrings::atr_FillColorType=L"FillColorType";
	const WString JDFStrings::atr_FillMaterial=L"FillMaterial";
	const WString JDFStrings::atr_FinishedPage=L"FinishedPage";
	const WString JDFStrings::atr_FinishedPageOrientation=L"FinishedPageOrientation";
	const WString JDFStrings::atr_FinishingOrder=L"FinishingOrder";
	const WString JDFStrings::atr_Finishings=L"Finishings";
	const WString JDFStrings::atr_FirstEnd=L"FirstEnd";
	const WString JDFStrings::atr_FirstName=L"FirstName";
	const WString JDFStrings::atr_FirstPage=L"FirstPage";
	const WString JDFStrings::atr_FirstStart=L"FirstStart";
	const WString JDFStrings::atr_FirstSurface=L"FirstSurface";
	const WString JDFStrings::atr_FitToPage=L"FitToPage";
	const WString JDFStrings::atr_FixExpression=L"FixExpression";

	const WString JDFStrings::atr_Flatness=L"Flatness";
	const WString JDFStrings::atr_FlexValue=L"FlexValue";
	const WString JDFStrings::atr_FlipBackCover=L"FlipBackCover";
	const WString JDFStrings::atr_FlushPolicy=L"FlushPolicy";
	const WString JDFStrings::atr_Flute=L"Flute";
	const WString JDFStrings::atr_FluteDirection=L"FluteDirection";

	const WString JDFStrings::atr_FoldCatalog=L"FoldCatalog";
	const WString JDFStrings::atr_FoldCatalogOrientation=L"FoldCatalogOrientation";
	const WString JDFStrings::atr_FolderModuleIndex=L"FolderModuleIndex";
	const WString JDFStrings::atr_FoldIndex=L"FoldIndex";
	const WString JDFStrings::atr_FoldingWidth=L"FoldingWidth";
	const WString JDFStrings::atr_FoldOutPages=L"FoldOutPages";
	const WString JDFStrings::atr_Folds=L"Folds";
	const WString JDFStrings::atr_FoldSheetIn=L"FoldSheetIn";
	const WString JDFStrings::atr_Folio=L"Folio";
	const WString JDFStrings::atr_FolioCount=L"FolioCount";
	const WString JDFStrings::atr_Font=L"Font";
	const WString JDFStrings::atr_FontCorrupted=L"FontCorrupted";
	const WString JDFStrings::atr_FontCreator=L"FontCreator";
	const WString JDFStrings::atr_FontEmbedded=L"FontEmbedded";
	const WString JDFStrings::atr_FontIsStandardLatin=L"FontIsStandardLatin";
	const WString JDFStrings::atr_FontName=L"FontName";
	const WString JDFStrings::atr_FontNotUsed=L"FontNotUsed";
	const WString JDFStrings::atr_FontSize=L"FontSize";
	const WString JDFStrings::atr_FontSubset=L"FontSubset";
	const WString JDFStrings::atr_FontType=L"FontType";
	const WString JDFStrings::atr_FontVendor=L"FontVendor";
	const WString JDFStrings::atr_ForceFrontSide=L"ForceFrontSide";
	const WString JDFStrings::atr_ForceSeparations=L"ForceSeparations";
	const WString JDFStrings::atr_Format=L"Format";
	const WString JDFStrings::atr_FountainNumber=L"FountainNumber";
	const WString JDFStrings::atr_FountainPositions=L"FountainPositions";
	const WString JDFStrings::atr_FountainSolution=L"FountainSolution";
	const WString JDFStrings::atr_FrameHeight=L"FrameHeight";
	const WString JDFStrings::atr_FrameWidth=L"FrameWidth";
	const WString JDFStrings::atr_Frequency=L"Frequency";
	const WString JDFStrings::atr_FriendlyName=L"FriendlyName";
	const WString JDFStrings::atr_From=L"From";
	const WString JDFStrings::atr_FromBox=L"FromBox";
	const WString JDFStrings::atr_FrontCoatings=L"FrontCoatings";
	const WString JDFStrings::atr_FrontFacePages=L"FrontFacePages";
	const WString JDFStrings::atr_FrontFoldIn=L"FrontFoldIn";
	const WString JDFStrings::atr_FrontGlossValue=L"FrontGlossValue";
	const WString JDFStrings::atr_FrontMarkList=L"FrontMarkList";
	const WString JDFStrings::atr_FrontOverfold=L"FrontOverfold";
	const WString JDFStrings::atr_FrontPages=L"FrontPages";
	const WString JDFStrings::atr_FrontSide=L"FrontSide";

	const WString JDFStrings::atr_GangName=L"GangName";
	const WString JDFStrings::atr_GangNames=L"GangNames";
	const WString JDFStrings::atr_GangPolicy=L"GangPolicy";
	const WString JDFStrings::atr_GapList=L"GapList";
	const WString JDFStrings::atr_GeneratePageStreams=L"GeneratePageStreams";
	const WString JDFStrings::atr_GenericAttributes=L"GenericAttributes";
	const WString JDFStrings::atr_GlueBrand=L"GlueBrand";
	const WString JDFStrings::atr_GlueLineRefSheets=L"GlueLineRefSheets";
	const WString JDFStrings::atr_GlueLineWidth=L"GlueLineWidth";
	const WString JDFStrings::atr_GlueType=L"GlueType";
	const WString JDFStrings::atr_GluingPattern=L"GluingPattern";
	const WString JDFStrings::atr_GluingProductionID=L"GluingProductionID";
	const WString JDFStrings::atr_GluingTechnique=L"GluingTechnique";
	const WString JDFStrings::atr_Grade=L"Grade";
	const WString JDFStrings::atr_GrainDirection=L"GrainDirection";
	const WString JDFStrings::atr_GrossWeight=L"GrossWeight";
	const WString JDFStrings::atr_GroupBy=L"GroupBy";
	const WString JDFStrings::atr_Gutter=L"Gutter";
	const WString JDFStrings::atr_GutterMinimumLimit=L"GutterMinimumLimit";
	const WString JDFStrings::atr_GutterPolicy=L"GutterPolicy";

	// HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH//

	const WString JDFStrings::atr_HalfTone=L"HalfTone";
	const WString JDFStrings::atr_Halftone=L"Halftone";
	const WString JDFStrings::atr_Halftoned=L"Halftoned";
	const WString JDFStrings::atr_HalftoneName=L"HalftoneName";
	const WString JDFStrings::atr_HalftonePhase=L"HalfTonePhase"; // bug fix in JDF 1.3
	const WString JDFStrings::atr_HalfTonePhase=L"HalfTonePhase";
	const WString JDFStrings::atr_HalfTonePhaseOrigin=L"HalfTonePhaseOrigin";
	const WString JDFStrings::atr_HardenerType=L"HardenerType";
	const WString JDFStrings::atr_HasBleeds=L"HasBleeds";
	const WString JDFStrings::atr_HasColorLUT=L"HasColorLUT";
	const WString JDFStrings::atr_HasDefault=L"HasDefault";
	const WString JDFStrings::atr_HasExternalReference=L"HasExternalReference";
	const WString JDFStrings::atr_HasFillColor=L"HasFillColor";
	const WString JDFStrings::atr_HasOPI=L"HasOPI";
	const WString JDFStrings::atr_HasPrice=L"HasPrice";
	const WString JDFStrings::atr_HasSoftMask=L"HasSoftMask";
	const WString JDFStrings::atr_HasStrokeColor=L"HasStrokeColor";
	const WString JDFStrings::atr_Height=L"Height";
	const WString JDFStrings::atr_HelpText=L"HelpText";
	const WString JDFStrings::atr_Hold=L"Hold";
	const WString JDFStrings::atr_HoleCount=L"HoleCount";
	const WString JDFStrings::atr_HoleReferenceEdge=L"HoleReferenceEdge";
	const WString JDFStrings::atr_HoleType=L"HoleType";
	const WString JDFStrings::atr_HonorPDFOverprint=L"HonorPDFOverprint";
	const WString JDFStrings::atr_HorizontalCreep=L"HorizontalCreep";
	const WString JDFStrings::atr_HorizontalExcess=L"HorizontalExcess";
	const WString JDFStrings::atr_HotFolder=L"HotFolder";
	const WString JDFStrings::atr_HourCounter=L"HourCounter";
	const WString JDFStrings::atr_HSamples=L"HSamples";
	const WString JDFStrings::atr_HttpGet=L"HttpGet";
	const WString JDFStrings::atr_HuffTable=L"HuffTable";
	const WString JDFStrings::atr_HWRelation=L"HWRelation";

	// IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII//

	const WString JDFStrings::atr_ICCColorAsDeviceColor=L"ICCColorAsDeviceColor";
	const WString JDFStrings::atr_ICCProfileSubFolder=L"ICCProfileSubFolder";
	const WString JDFStrings::atr_ICCProfileUsage=L"ICCProfileUsage";
	const WString JDFStrings::atr_ICCOutputProfileUsage=L"ICCOutputProfileUsage";
	const WString JDFStrings::atr_IconUsage=L"IconUsage";
	const WString JDFStrings::atr_ICSVersions=L"ICSVersions";
	const WString JDFStrings::atr_Identifier=L"Identifier";
	const WString JDFStrings::atr_IDPAttributeFidelity=L"IDPAttributeFidelity";
	const WString JDFStrings::atr_IDUsage=L"IDUsage";
	const WString JDFStrings::atr_IDValue=L"IDValue";
	const WString JDFStrings::atr_IgnoreAnnotForms=L"IgnoreAnnotForms";
	const WString JDFStrings::atr_IgnoreBG=L"IgnoreBG";
	const WString JDFStrings::atr_IgnoreColorSeps=L"IgnoreColorSeps";
	const WString JDFStrings::atr_IgnoreDeviceExtGState=L"IgnoreDeviceExtGState";
	const WString JDFStrings::atr_IgnoreDSC=L"IgnoreDSC";
	const WString JDFStrings::atr_IgnoreEmbeddedICC=L"IgnoreEmbeddedICC";
	const WString JDFStrings::atr_IgnoreExtensions=L"IgnoreExtensions";
	const WString JDFStrings::atr_IgnoreExternStreamRef=L"IgnoreExternStreamRef";
	const WString JDFStrings::atr_IgnoreFileParams=L"IgnoreFileParams";
	const WString JDFStrings::atr_IgnoreHalftones=L"IgnoreHalftones";
	const WString JDFStrings::atr_IgnoreOverprint=L"IgnoreOverprint";
	const WString JDFStrings::atr_IgnorePageRotation=L"IgnorePageRotation";
	const WString JDFStrings::atr_IgnorePDLCopies=L"IgnorePDLCopies";
	const WString JDFStrings::atr_IgnorePDLImposition=L"IgnorePDLImposition";
	const WString JDFStrings::atr_IgnoreRawData=L"IgnoreRawData";
	const WString JDFStrings::atr_IgnoreSeparableImagesOnly=L"IgnoreSeparableImagesOnly";
	const WString JDFStrings::atr_IgnoreShowPage=L"IgnoreShowPage";
	const WString JDFStrings::atr_IgnoreSourceFile=L"IgnoreSourceFile";
	const WString JDFStrings::atr_IgnoreTransfers=L"IgnoreTransfers";
	const WString JDFStrings::atr_IgnoreTTFontsFirst=L"IgnoreTTFontsFirst";
	const WString JDFStrings::atr_IgnoreUCR=L"IgnoreUCR";
	const WString JDFStrings::atr_Illumination=L"Illumination";
	const WString JDFStrings::atr_ImageAutoFilterStrategy=L"ImageAutoFilterStrategy";
	const WString JDFStrings::atr_ImagableSide=L"ImagableSide";
	const WString JDFStrings::atr_ImageDepth=L"ImageDepth";
	const WString JDFStrings::atr_ImageDownsampleThreshold=L"ImageDownsampleThreshold";
	const WString JDFStrings::atr_ImageDownsampleType=L"ImageDownsampleType";
	const WString JDFStrings::atr_ImageFilter=L"ImageFilter";
	const WString JDFStrings::atr_ImageFlipped=L"ImageFlipped";
	const WString JDFStrings::atr_ImageInternalTrapping=L"ImageInternalTrapping";
	const WString JDFStrings::atr_ImageMaskTrapping=L"ImageMaskTrapping";
	const WString JDFStrings::atr_ImageMaskType=L"ImageMaskType";
	const WString JDFStrings::atr_ImageMemory=L"ImageMemory";
	const WString JDFStrings::atr_ImagePreScanStrategy=L"ImagePreScanStrategy";
	const WString JDFStrings::atr_ImageReplacementStrategy=L"ImageReplacementStrategy";
	const WString JDFStrings::atr_ImageResolution=L"ImageResolution";
	const WString JDFStrings::atr_ImageRotation=L"ImageRotation";
	const WString JDFStrings::atr_ImageScalingRatio=L"ImageScalingRatio";
	const WString JDFStrings::atr_ImageSize=L"ImageSize";
	const WString JDFStrings::atr_ImageSkew=L"ImageSkew";
	const WString JDFStrings::atr_ImagesSubFolder=L"ImagesSubFolder";
	const WString JDFStrings::atr_ImageToImageTrapping=L"ImageToImageTrapping";
	const WString JDFStrings::atr_ImageToObjectTrapping=L"ImageToObjectTrapping";
	const WString JDFStrings::atr_ImageTrapPlacement=L"ImageTrapPlacement";
	const WString JDFStrings::atr_ImageTrapWidth=L"ImageTrapWidth";
	const WString JDFStrings::atr_ImageTrapWidthY=L"ImageTrapWidthY";
	const WString JDFStrings::atr_ImageType=L"ImageType";
	const WString JDFStrings::atr_ImageViewingStrategy=L"ImageViewingStrategy";
	const WString JDFStrings::atr_ImplicitGutter=L"ImplicitGutter";
	const WString JDFStrings::atr_ImplicitGutterMinimumLimit=L"ImplicitGutterMinimumLimit";
	
	const WString JDFStrings::atr_IncludeBaseFonts=L"IncludeBaseFonts";
	const WString JDFStrings::atr_IncludeCIDFonts=L"IncludeCIDFonts";
	const WString JDFStrings::atr_IncludeEmbeddedFonts=L"IncludeEmbeddedFonts";
	const WString JDFStrings::atr_IncludeInBundleItem=L"IncludeInBundleItem";
	const WString JDFStrings::atr_IncludeItemInBundle=L"IncludeItemInBundle";
	const WString JDFStrings::atr_IncludeOCG=L"IncludeOCG";
	const WString JDFStrings::atr_IncludeOtherResources=L"IncludeOtherResources";
	const WString JDFStrings::atr_IncludeProcSets=L"IncludeProcSets";
	const WString JDFStrings::atr_IncludeTrueTypeFonts=L"IncludeTrueTypeFonts";
	const WString JDFStrings::atr_IncludeType1Fonts=L"IncludeType1Fonts";
	const WString JDFStrings::atr_IncludeType3Fonts=L"IncludeType3Fonts";
	const WString JDFStrings::atr_IncorrectComponentQuality=L"IncorrectComponentQuality";
	const WString JDFStrings::atr_IncorrectComponents=L"IncorrectComponents";
	const WString JDFStrings::atr_Independent=L"Independent";
	const WString JDFStrings::atr_InitialPageSize=L"InitialPageSize";
	const WString JDFStrings::atr_InitialResolution=L"InitialResolution";
	const WString JDFStrings::atr_InkCoverage=L"InkCoverage";
	const WString JDFStrings::atr_InkName=L"InkName";
	const WString JDFStrings::atr_InkState=L"InkState";
	const WString JDFStrings::atr_InputBox=L"InputBox";
	const WString JDFStrings::atr_InputField=L"InputField";
	const WString JDFStrings::atr_InsertError=L"InsertError";
	const WString JDFStrings::atr_InsertLocation=L"InsertLocation";
	const WString JDFStrings::atr_InsertOK=L"InsertOK";
	const WString JDFStrings::atr_InsideBox=L"InsideBox";
	const WString JDFStrings::atr_InsideLoss=L"InsideLoss";
	const WString JDFStrings::atr_Instrumentation=L"Instrumentation";
	const WString JDFStrings::atr_IntegerValue=L"IntegerValue";
	const WString JDFStrings::atr_Interleaved=L"Interleaved";
	const WString JDFStrings::atr_Interleaving=L"Interleaving";
	const WString JDFStrings::atr_IPPJobPriority=L"IPPJobPriority";
	const WString JDFStrings::atr_IPPVersion=L"IPPVersion";
	const WString JDFStrings::atr_IsBlank=L"IsBlank";
	const WString JDFStrings::atr_IsDevice=L"IsDevice";
	const WString JDFStrings::atr_IsFontScreenOnly=L"IsFontScreenOnly";
	const WString JDFStrings::atr_IsPage=L"IsPage";
	const WString JDFStrings::atr_IsPrintable=L"IsPrintable";
	const WString JDFStrings::atr_IsTrapped=L"IsTrapped";
	const WString JDFStrings::atr_IsWaste=L"IsWaste";
	const WString JDFStrings::atr_Item=L"Item";
	const WString JDFStrings::atr_ItemName=L"ItemName";
	const WString JDFStrings::atr_ItemNames=L"ItemNames";

	// JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ //

	const WString JDFStrings::atr_JBIG2Lossless=L"JBIG2Lossless";
	const WString JDFStrings::atr_JDFDetails=L"JDFDetails";
	const WString JDFStrings::atr_JDFErrorURL=L"JDFErrorURL";
	const WString JDFStrings::atr_JDFInputURL=L"JDFInputURL";
	const WString JDFStrings::atr_JDFOutputURL=L"JDFOutputURL";
	const WString JDFStrings::atr_JMFRole=L"JMFRole";
	const WString JDFStrings::atr_JMFSenderID=L"JMFSenderID";
	const WString JDFStrings::atr_JMFURL=L"JMFURL";
	const WString JDFStrings::atr_JDFVersions=L"JDFVersions";
	const WString JDFStrings::atr_JobDetails=L"JobDetails";
	const WString JDFStrings::atr_JobID=L"JobID";
	const WString JDFStrings::atr_JobPartID=L"JobPartID";
	const WString JDFStrings::atr_JobPriority=L"JobPriority";
	const WString JDFStrings::atr_JobTitle=L"JobTitle";
	const WString JDFStrings::atr_JogEdge=L"JogEdge";
	const WString JDFStrings::atr_JogSide=L"JogSide";
	const WString JDFStrings::atr_JointWidth=L"JointWidth";
	const WString JDFStrings::atr_JPXQuality=L"JPXQuality";
	const WString JDFStrings::atr_jRef=L"jRef";
	const WString JDFStrings::atr_jRefDestination=L"jRefDestination";
	const WString JDFStrings::atr_jRefSource=L"jRefSource";

	const WString JDFStrings::atr_K=L"K";
	const WString JDFStrings::atr_Key=L"Key";
	const WString JDFStrings::atr_Keywords=L"Keywords";
	const WString JDFStrings::atr_KnockOutCMYKWhite=L"KnockOutCMYKWhite";
	const WString JDFStrings::atr_KnownLocalizations=L"KnownLocalizations";

	const WString JDFStrings::atr_Lab=L"Lab";
	const WString JDFStrings::atr_LabColorValue=L"LabColorValue";
	const WString JDFStrings::atr_LaborType=L"LaborType";
	const WString JDFStrings::atr_LaminatingBox=L"LaminatingBox";
	const WString JDFStrings::atr_LaminatingMethod=L"LaminatingMethod";
	const WString JDFStrings::atr_Lang=L"Lang";
	const WString JDFStrings::atr_Language=L"Language";
	const WString JDFStrings::atr_LastCount=L"LastCount";
	const WString JDFStrings::atr_LastEnd=L"LastEnd";
	const WString JDFStrings::atr_LastRepeat=L"LastRepeat";
	const WString JDFStrings::atr_LastStart=L"LastStart";
	const WString JDFStrings::atr_LayerAmount=L"LayerAmount";
	const WString JDFStrings::atr_LayerID=L"LayerID";
	const WString JDFStrings::atr_LayerIDs=L"LayerIDs";
	const WString JDFStrings::atr_LayerRates=L"LayerRates";
	const WString JDFStrings::atr_Layers=L"Layers";
	const WString JDFStrings::atr_LayersPerTile=L"LayersPerTile";
	const WString JDFStrings::atr_LayoutElementPageNum=L"LayoutElementPageNum";
	const WString JDFStrings::atr_LeadingEdge=L"LeadingEdge";
	const WString JDFStrings::atr_Length=L"Length";
	const WString JDFStrings::atr_LengthOverall=L"LengthOverall";
	const WString JDFStrings::atr_Level=L"Level";
	const WString JDFStrings::atr_Light=L"Light";
	const WString JDFStrings::atr_Linearized=L"Linearized";
	const WString JDFStrings::atr_LineArtBlackLevel=L"LineArtBlackLevel";
	const WString JDFStrings::atr_LineWidth=L"LineWidth";
	const WString JDFStrings::atr_LinkUsage=L"LinkUsage";
	const WString JDFStrings::atr_ListCommands=L"ListCommands";
	const WString JDFStrings::atr_ListPolicy=L"ListPolicy";
	const WString JDFStrings::atr_ListQueries=L"ListQueries";
	const WString JDFStrings::atr_ListRegistrations=L"ListRegistrations";
	const WString JDFStrings::atr_ListSignals=L"ListSignals";
	const WString JDFStrings::atr_ListType=L"ListType";
	const WString JDFStrings::atr_Loading=L"Loading";
	const WString JDFStrings::atr_Localization=L"Localization";
	const WString JDFStrings::atr_Location=L"Location";
	const WString JDFStrings::atr_LocationName=L"LocationName";
	const WString JDFStrings::atr_Locator=L"Locator";
	const WString JDFStrings::atr_LocID=L"LocID";
	const WString JDFStrings::atr_LockDistillerParams=L"LockDistillerParams";
	const WString JDFStrings::atr_Locked=L"Locked";
	const WString JDFStrings::atr_LockOrigins=L"LockOrigins";
	const WString JDFStrings::atr_LogicalPage=L"LogicalPage";
	const WString JDFStrings::atr_LogicalPrinterSection=L"LogicalPrinterSection";
	const WString JDFStrings::atr_LogicalStackOrd=L"LogicalStackOrd";
	const WString JDFStrings::atr_LogicalStackSequence=L"LogicalStackSequence";
	const WString JDFStrings::atr_LogErrors=L"LogErrors";
	const WString JDFStrings::atr_LotControl=L"LotControl";
	const WString JDFStrings::atr_LotID=L"LotID";

	// MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM//

	const WString JDFStrings::atr_MacroRefs=L"MacroRefs";
	const WString JDFStrings::atr_Magnification=L"Magnification";
	const WString JDFStrings::atr_ManualFeed=L"ManualFeed";
	const WString JDFStrings::atr_Manufacturer=L"Manufacturer";
	const WString JDFStrings::atr_ManufacturerURL=L"ManufacturerURL";
	const WString JDFStrings::atr_MappingSelection=L"MappingSelection";
	const WString JDFStrings::atr_MarginBottom=L"MarginBottom";
	const WString JDFStrings::atr_MarginLeft=L"MarginLeft";
	const WString JDFStrings::atr_MarginRight=L"MarginRight";
	const WString JDFStrings::atr_MarginTop=L"MarginTop";
	const WString JDFStrings::atr_MarkJustification=L"MarkJustification";
	const WString JDFStrings::atr_MarkList=L"MarkList";
	const WString JDFStrings::atr_MarkName=L"MarkName";
	const WString JDFStrings::atr_MarkOffset=L"MarkOffset";
	const WString JDFStrings::atr_MarkOrientation=L"MarkOrientation";
	const WString JDFStrings::atr_MarkPosition=L"MarkPosition";
	const WString JDFStrings::atr_MarkSide=L"MarkSide";
	const WString JDFStrings::atr_MarkType=L"MarkType";
	const WString JDFStrings::atr_MarkUsage=L"MarkUsage";
	const WString JDFStrings::atr_Mask=L"Mask";
	const WString JDFStrings::atr_MaskBleed=L"MaskBleed";
	const WString JDFStrings::atr_Masking=L"Masking";
	const WString JDFStrings::atr_MaskSeparation=L"MaskSeparation";
	const WString JDFStrings::atr_Material=L"Material";
	const WString JDFStrings::atr_MaxAmount=L"MaxAmount";
	const WString JDFStrings::atr_MaxCleanup=L"MaxCleanup";
	const WString JDFStrings::atr_MaxDiameter=L"MaxDiameter";
	const WString JDFStrings::atr_MaxDocOrd=L"MaxDocOrd";
	const WString JDFStrings::atr_MaxEntries=L"MaxEntries";
	const WString JDFStrings::atr_MaxGroups=L"MaxGroups";
	const WString JDFStrings::atr_MaxHeat=L"MaxHeat";
	const WString JDFStrings::atr_MaxHeight=L"MaxHeight";
	const WString JDFStrings::atr_MaxOccurrences=L"MaxOccurrences";
	const WString JDFStrings::atr_MaxOccurs=L"MaxOccurs";
	const WString JDFStrings::atr_MaxOrd=L"MaxOrd";
	const WString JDFStrings::atr_MaxPerGroup=L"MaxPerGroup";
	const WString JDFStrings::atr_MaxResolution=L"MaxResolution";
	const WString JDFStrings::atr_MaxSearchRecursion=L"MaxSearchRecursion";
	const WString JDFStrings::atr_MaxSetOrd=L"MaxSetOrd";
	const WString JDFStrings::atr_MaxSetup=L"MaxSetup";
	const WString JDFStrings::atr_MaxStackDepth=L"MaxStackDepth";
	const WString JDFStrings::atr_MaxSubsetPct=L"MaxSubsetPct";
	const WString JDFStrings::atr_MaxVersion=L"MaxVersion";
	const WString JDFStrings::atr_MaxWeight=L"MaxWeight";
	const WString JDFStrings::atr_MaxWidth=L"MaxWidth";

	const WString JDFStrings::atr_MeasurementFilter=L"MeasurementFilter";
	const WString JDFStrings::atr_MediaColorName=L"MediaColorName";
	const WString JDFStrings::atr_MediaColorNameDetails=L"MediaColorNameDetails";
	const WString JDFStrings::atr_MediaLabel=L"MediaLabel";
	const WString JDFStrings::atr_MediaLocation=L"MediaLocation";
	const WString JDFStrings::atr_MediaSetCount=L"MediaSetCount";
	const WString JDFStrings::atr_MediaSide=L"MediaSide";
	const WString JDFStrings::atr_MediaType=L"MediaType";
	const WString JDFStrings::atr_MediaTypeDetails=L"MediaTypeDetails";
	const WString JDFStrings::atr_MediaUnit=L"MediaUnit";
	const WString JDFStrings::atr_MeltingTemperature=L"MeltingTemperature";
	const WString JDFStrings::atr_MergeID=L"MergeID";
	const WString JDFStrings::atr_MergeTarget=L"MergeTarget";
	const WString JDFStrings::atr_MessageEvents=L"MessageEvents";
	const WString JDFStrings::atr_MessageID=L"MessageID";
	const WString JDFStrings::atr_MessageRefID=L"MessageRefID";
	const WString JDFStrings::atr_MessageType=L"MessageType";
	const WString JDFStrings::atr_Method=L"Method";

	const WString JDFStrings::atr_MilestoneType=L"MilestoneType";
	const WString JDFStrings::atr_MillingDepth=L"MillingDepth";

	const WString JDFStrings::atr_MIME=L"MIME";
	const WString JDFStrings::atr_MimeType=L"MimeType";
	const WString JDFStrings::atr_MIMEType=JDFStrings::atr_MimeType; // retained for backward compatibility with buggy schema.
	const WString JDFStrings::atr_MimeTypeVersion=L"MimeTypeVersion";
	const WString JDFStrings::atr_MinAmount=L"MinAmount";
	const WString JDFStrings::atr_MinApprovals=L"MinApprovals";
	const WString JDFStrings::atr_MinCleanup=L"MinCleanup";
	const WString JDFStrings::atr_MinDelayTime=L"MinDelayTime";
	const WString JDFStrings::atr_MinDuration=L"MinDuration";
	const WString JDFStrings::atr_MinGutter=L"MinGutter";
	const WString JDFStrings::atr_MinimumBlackWidth=L"MinimumBlackWidth";
	const WString JDFStrings::atr_MinimumWait=L"MinimumWait";
	const WString JDFStrings::atr_MinLateStatus=L"MinLateStatus";
	const WString JDFStrings::atr_MinOccurs=L"MinOccurs";
	const WString JDFStrings::atr_MinResolution=L"MinResolution";
	const WString JDFStrings::atr_MinSetup=L"MinSetup";
	const WString JDFStrings::atr_MinStatus=L"MinStatus";
	const WString JDFStrings::atr_MirrorAround=L"MirrorAround";
	const WString JDFStrings::atr_MirrorMargins=L"MirrorMargins";
	const WString JDFStrings::atr_MissingPrinterFont=L"MissingPrinterFont";
	const WString JDFStrings::atr_MissingScreenFont=L"MissingScreenFont";
	const WString JDFStrings::atr_ModelDescription=L"ModelDescription";
	const WString JDFStrings::atr_Mode=L"Mode";
	const WString JDFStrings::atr_ModelName=L"ModelName";
	const WString JDFStrings::atr_ModelNumber=L"ModelNumber";
	const WString JDFStrings::atr_ModelURL=L"ModelURL";
	const WString JDFStrings::atr_Modification=L"Modification";
	const WString JDFStrings::atr_ModificationDate=L"ModificationDate";
	const WString JDFStrings::atr_ModificationDateInDocument=L"ModificationDateInDocument";
	const WString JDFStrings::atr_ModificationID=L"ModificationID";
	const WString JDFStrings::atr_ModuleAvailableIndex=L"ModuleAvailableIndex";
	const WString JDFStrings::atr_ModuleDrying=L"ModuleDrying";
	const WString JDFStrings::atr_ModuleHeight=L"ModuleHeight";
	const WString JDFStrings::atr_ModuleID=L"ModuleID";
	const WString JDFStrings::atr_ModuleIndex=L"ModuleIndex";
	const WString JDFStrings::atr_ModuleRefs=L"ModuleRefs";
	const WString JDFStrings::atr_ModuleType=L"ModuleType";
	const WString JDFStrings::atr_ModuleWidth=L"ModuleWidth";
	const WString JDFStrings::atr_MountID=L"MountID";
	const WString JDFStrings::atr_Mounting=L"Mounting";
	const WString JDFStrings::atr_MustHonorExceptions=L"MustHonorExceptions";

	// NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

	const WString JDFStrings::atr_N=L"N";
	const WString JDFStrings::atr_Name=L"Name";
	const WString JDFStrings::atr_NamedFeatures=L"NamedFeatures";
	const WString JDFStrings::atr_NamePrefix=L"NamePrefix";
	const WString JDFStrings::atr_NameSpace=L"NameSpace";
	const WString JDFStrings::atr_NameSuffix=L"NameSuffix";
	const WString JDFStrings::atr_NaturalLang=L"NaturalLang";
	const WString JDFStrings::atr_NDoc=L"NDoc";
	const WString JDFStrings::atr_NeedlePositions=L"NeedlePositions";
	const WString JDFStrings::atr_NeutralDensity=L"NeutralDensity";
	const WString JDFStrings::atr_NeverEmbed=L"NeverEmbed";
	const WString JDFStrings::atr_NewerThan=L"NewerThan";
	const WString JDFStrings::atr_NewSpawnID=L"NewSpawnID";
	const WString JDFStrings::atr_NewTime=L"NewTime";
	const WString JDFStrings::atr_NewValue=L"NewValue";
	const WString JDFStrings::atr_NextQueueEntryID=L"NextQueueEntryID";
	const WString JDFStrings::atr_NipWidth=L"NipWidth";
	const WString JDFStrings::atr_NodeID=L"NodeID";
	const WString JDFStrings::atr_NodeStatus=L"NodeStatus";
	const WString JDFStrings::atr_NodeStatusDetails=L"NodeStatusDetails";
	const WString JDFStrings::atr_NonPrintableMarginBottom=L"NonPrintableMarginBottom";
	const WString JDFStrings::atr_NonPrintableMarginLeft=L"NonPrintableMarginLeft";
	const WString JDFStrings::atr_NonPrintableMarginRight=L"NonPrintableMarginRight";
	const WString JDFStrings::atr_NonPrintableMarginTop=L"NonPrintableMarginTop";
	const WString JDFStrings::atr_NoOp=L"NoOp";
	const WString JDFStrings::atr_NotchingDepth=L"NotchingDepth";
	const WString JDFStrings::atr_NotchingDistance=L"NotchingDistance";
	const WString JDFStrings::atr_NPage=L"NPage";
	const WString JDFStrings::atr_NSet=L"NSet";
	const WString JDFStrings::atr_Number=L"Number";
	const WString JDFStrings::atr_NumberOfColorsInLUT=L"NumberOfColorsInLUT";
	const WString JDFStrings::atr_NumberOfNeedles=L"NumberOfNeedles";
	const WString JDFStrings::atr_NumberOfPages=L"NumberOfPages";
	const WString JDFStrings::atr_NumberOfPathPoints=L"NumberOfPathPoints";
	const WString JDFStrings::atr_NumberOfStitches=L"NumberOfStitches";
	const WString JDFStrings::atr_NumberUp=L"NumberUp";
	const WString JDFStrings::atr_NumberValue=L"NumberValue";
	const WString JDFStrings::atr_NumResolutions=L"NumResolutions";

	// OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO //

	const WString JDFStrings::atr_Obligated=L"Obligated";
	const WString JDFStrings::atr_Observer=L"Observer";
	const WString JDFStrings::atr_ObservationPath=L"ObservationPath";
	const WString JDFStrings::atr_Occurrences=L"Occurrences";
	const WString JDFStrings::atr_OCGDefault=L"OCGDefault";
	const WString JDFStrings::atr_OCGIntent=L"OCGIntent";
	const WString JDFStrings::atr_OCGName=L"OCGName";
	const WString JDFStrings::atr_OCGProcess=L"OCGProcess";
	const WString JDFStrings::atr_OCGZoom=L"OCGZoom";
	const WString JDFStrings::atr_OfferRange=L"OfferRange";
	const WString JDFStrings::atr_Offset=L"Offset";
	const WString JDFStrings::atr_OffsetAmount=L"OffsetAmount";
	const WString JDFStrings::atr_OffsetDirection=L"OffsetDirection";
	const WString JDFStrings::atr_OlderThan=L"OlderThan";
	const WString JDFStrings::atr_OldTime=L"OldTime";
	const WString JDFStrings::atr_OldValue=L"OldValue";
	const WString JDFStrings::atr_Opacity=L"Opacity";
	const WString JDFStrings::atr_OpacityLevel=L"OpacityLevel";
	const WString JDFStrings::atr_Opening=L"Opening";
	const WString JDFStrings::atr_Operation=L"Operation";
	const WString JDFStrings::atr_Operations=L"Operations";
	const WString JDFStrings::atr_OperatorInterventionExceptions=L"OperatorInterventionExceptions";
	const WString JDFStrings::atr_OperatorText=L"OperatorText";
	const WString JDFStrings::atr_OPIMissing=L"OPIMissing";
	const WString JDFStrings::atr_OPIType=L"OPIType";
	const WString JDFStrings::atr_OPIVersion=L"OPIVersion";
	const WString JDFStrings::atr_Optimize=L"Optimize";
	const WString JDFStrings::atr_Option=L"Option";
	const WString JDFStrings::atr_OptionalCombinedTypes=L"OptionalCombinedTypes";
	const WString JDFStrings::atr_Ord=L"Ord";
	const WString JDFStrings::atr_Order=L"Order";
	const WString JDFStrings::atr_OrderedAmount=L"OrderedAmount";
	const WString JDFStrings::atr_OrdExpression=L"OrdExpression";
	const WString JDFStrings::atr_OrdID=L"OrdID";
	const WString JDFStrings::atr_OrganizationName=L"OrganizationName";
	const WString JDFStrings::atr_Orientation=L"Orientation";
	const WString JDFStrings::atr_OriginalResolution=L"OriginalResolution";
	const WString JDFStrings::atr_OSVersion=L"OSVersion";
	const WString JDFStrings::atr_OuterCoreDiameter=L"OuterCoreDiameter";
	const WString JDFStrings::atr_OutputBin=L"OutputBin";
	const WString JDFStrings::atr_OutputColorSpace=L"OutputColorSpace";
	const WString JDFStrings::atr_OutputIntentColorSpace=L"OutputIntentColorSpace";
	const WString JDFStrings::atr_OutputIntentStandard=L"OutputIntentStandard";
	const WString JDFStrings::atr_OutputPreferencesSubFolder=L"OutputPreferencesSubFolder";
	const WString JDFStrings::atr_OutputResolution=L"OutputResolution";
	const WString JDFStrings::atr_OutputSize=L"OutputSize";
	const WString JDFStrings::atr_OutputType=L"OutputType";
	const WString JDFStrings::atr_OutsideBox=L"OutsideBox";
	const WString JDFStrings::atr_OutsideGain=L"OutsideGain";
	const WString JDFStrings::atr_OutsideGutter=L"OutsideGutter";
	const WString JDFStrings::atr_Overfold=L"Overfold";
	const WString JDFStrings::atr_OverfoldSide=L"OverfoldSide";
	const WString JDFStrings::atr_Overlap=L"Overlap";
	const WString JDFStrings::atr_OverPrintBlackLineArt=L"OverPrintBlackLineArt";
	const WString JDFStrings::atr_OverPrintBlackText=L"OverPrintBlackText";
	const WString JDFStrings::atr_OverprintFlag=L"OverPrintFlag";
	const WString JDFStrings::atr_OverPrintFlag=L"OverPrintFlag";
	const WString JDFStrings::atr_OverprintMode=L"OverprintMode";
	const WString JDFStrings::atr_OverPrintMode=L"OverPrintMode";
	const WString JDFStrings::atr_OverwritePolicy=L"OverwritePolicy";
	const WString JDFStrings::atr_Ownership=L"Ownership";

	// PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP//

	const WString JDFStrings::atr_Packaging=L"Packaging";
	const WString JDFStrings::atr_Page=L"Page";
	const WString JDFStrings::atr_PageCopies=L"PageCopies";
	const WString JDFStrings::atr_PageBoxType=L"PageBoxType";
	const WString JDFStrings::atr_PageDelivery=L"PageDelivery";
	const WString JDFStrings::atr_PageDistributionScheme=L"PageDistributionScheme";
	const WString JDFStrings::atr_PageFormat=L"PageFormat";
	const WString JDFStrings::atr_PageHasUnknownObjects=L"PageHasUnknownObjects";
	const WString JDFStrings::atr_PageIndex=L"PageIndex";
	const WString JDFStrings::atr_PageLabel=L"PageLabel";
	const WString JDFStrings::atr_PageLabelPrefix=L"PageLabelPrefix";
	const WString JDFStrings::atr_PageLabelSuffix=L"PageLabelSuffix";
	const WString JDFStrings::atr_PageList=L"PageList";
	const WString JDFStrings::atr_PageListIndex=L"PageListIndex";
	const WString JDFStrings::atr_PageNames=L"PageNames";
	const WString JDFStrings::atr_PageNumber=L"PageNumber";
	const WString JDFStrings::atr_PageOrder=L"PageOrder";
	const WString JDFStrings::atr_PagePlacementName=L"PagePlacementName";
	const WString JDFStrings::atr_PageRefs=L"PageRefs";
	const WString JDFStrings::atr_Pages=L"Pages";
	const WString JDFStrings::atr_PageSet=L"PageSet";
	const WString JDFStrings::atr_PagesHaveSameOrientation=L"PagesHaveSameOrientation";
	const WString JDFStrings::atr_PagesPageNumber=L"PagesPageNumber";
	const WString JDFStrings::atr_PageStatus=L"PageStatus";
	const WString JDFStrings::atr_PageTags=L"PageTags";
	const WString JDFStrings::atr_PalletMaxHeight=L"PalletMaxHeight";
	const WString JDFStrings::atr_PalletMaxWeight=L"PalletMaxWeight";
	const WString JDFStrings::atr_PalletQuantity=L"PalletQuantity";
	const WString JDFStrings::atr_PalletSize=L"PalletSize";
	const WString JDFStrings::atr_PalletType=L"PalletType";
	const WString JDFStrings::atr_PalletWrapping=L"PalletWrapping";
	const WString JDFStrings::atr_ParentFolio=L"ParentFolio";
	const WString JDFStrings::atr_ParentJobID=L"ParentJobID";
	const WString JDFStrings::atr_ParentJobPartID=L"ParentJobPartID";
	const WString JDFStrings::atr_ParseDSCComments=L"ParseDSCComments";
	const WString JDFStrings::atr_ParseDSCCommentsForDocInfo=L"ParseDSCCommentsForDocInfo";
	const WString JDFStrings::atr_PartIDKeys=L"PartIDKeys";
	const WString JDFStrings::atr_PartUsage=L"PartUsage";	
	const WString JDFStrings::atr_PartVersion=L"PartVersion";
	const WString JDFStrings::atr_Passed=L"Passed";
	const WString JDFStrings::atr_PassThroughJPEGImages=L"PassThroughJPEGImages";
	const WString JDFStrings::atr_Password=L"Password";
	const WString JDFStrings::atr_Path=L"Path";
	const WString JDFStrings::atr_Pattern=L"Pattern";
	const WString JDFStrings::atr_PDFVersion=L"PDFVersion";
	const WString JDFStrings::atr_PDFX1aCheck=L"PDFX1aCheck";
	const WString JDFStrings::atr_PDFX3Check=L"PDFX3Check";
	const WString JDFStrings::atr_PDFXCompliantPDFOnly=L"PDFXCompliantPDFOnly";
	const WString JDFStrings::atr_PDFXNoTrimBoxError=L"PDFXNoTrimBoxError";
	const WString JDFStrings::atr_PDFXTrimBoxToMediaBoxOffset=L"PDFXTrimBoxToMediaBoxOffset";
	const WString JDFStrings::atr_PDFXSetBleedBoxToMediaBox=L"PDFXSetBleedBoxToMediaBox";
	const WString JDFStrings::atr_PDFXBleedBoxToTrimBoxOffset=L"PDFXBleedBoxToTrimBoxOffset";
	const WString JDFStrings::atr_PDFXOutputIntentProfile=L"PDFXOutputIntentProfile";
	const WString JDFStrings::atr_PDFXOutputCondition=L"PDFXOutputCondition";
	const WString JDFStrings::atr_PDFXRegistryName=L"PDFXRegistryName";
	const WString JDFStrings::atr_PDFXTrapped=L"PDFXTrapped";
	const WString JDFStrings::atr_PDFXVersion=L"PDFXVersion";
	const WString JDFStrings::atr_PDLObjectType=L"PDLObjectType";
	const WString JDFStrings::atr_PDLType=L"PDLType";
	const WString JDFStrings::atr_PDLVersion=L"PDLVersion";
	const WString JDFStrings::atr_Percentage=L"Percentage";
	const WString JDFStrings::atr_Percentages=L"Percentages";
	const WString JDFStrings::atr_PercentCompleted=L"PercentCompleted";
	const WString JDFStrings::atr_PerfectingModule=L"PerfectingModule";
	const WString JDFStrings::atr_Persistent=L"Persistent";
	const WString JDFStrings::atr_PersonalID=L"PersonalID";
	const WString JDFStrings::atr_PhaseAmount=L"PhaseAmount";
	const WString JDFStrings::atr_PhaseStartTime=L"PhaseStartTime";
	const WString JDFStrings::atr_PhaseWaste=L"PhaseWaste";
	const WString JDFStrings::atr_PhysicalSection=L"PhysicalSection";
	const WString JDFStrings::atr_Pickup=L"Pickup";
	const WString JDFStrings::atr_PipeID=L"PipeID";
	const WString JDFStrings::atr_PipePartIDKeys=L"PipePartIDKeys";
	const WString JDFStrings::atr_PipePause=L"PipePause";
	const WString JDFStrings::atr_PipeProtocol=L"PipeProtocol";
	const WString JDFStrings::atr_PipeResume=L"PipeResume";
	const WString JDFStrings::atr_PipeURL=L"PipeURL";
	const WString JDFStrings::atr_Pitch=L"Pitch";
	const WString JDFStrings::atr_PixelDepth=L"PixelDepth";
	const WString JDFStrings::atr_PixelHeight=L"PixelHeight";
	const WString JDFStrings::atr_PixelSkip=L"PixelSkip";
	const WString JDFStrings::atr_PixelWidth=L"PixelWidth";
	const WString JDFStrings::atr_PlateTechnology=L"PlateTechnology";
	const WString JDFStrings::atr_PlateLayout=L"PlateLayout";
	const WString JDFStrings::atr_PlatePosition=L"PlatePosition";
	const WString JDFStrings::atr_PlateType=L"PlateType";
	const WString JDFStrings::atr_PlateUsage=L"PlateUsage";
	const WString JDFStrings::atr_Polarity=L"Polarity";
	const WString JDFStrings::atr_PolarityChange=L"PolarityChange";
	const WString JDFStrings::atr_Position=L"Position";
	const WString JDFStrings::atr_PositionX=L"PositionX";
	const WString JDFStrings::atr_PositionY=L"PositionY";
	const WString JDFStrings::atr_PostalCode=L"PostalCode";
	const WString JDFStrings::atr_PostBakeTemp=L"PostBakeTemp";
	const WString JDFStrings::atr_PostBakeTime=L"PostBakeTime";
	const WString JDFStrings::atr_PostBox=L"PostBox";
	const WString JDFStrings::atr_PostCompressionEncoding=L"PostCompressionEncoding";
	const WString JDFStrings::atr_Poster=L"Poster";
	const WString JDFStrings::atr_PosterOverlap=L"PosterOverlap";
	const WString JDFStrings::atr_PostExposeTime=L"PostExposeTime";
	const WString JDFStrings::atr_Powder=L"Powder";
	const WString JDFStrings::atr_PowerOnTime=L"PowerOnTime";
	const WString JDFStrings::atr_PreCompressionIndividualEncoding=L"PreCompressionIndividualEncoding";
	const WString JDFStrings::atr_Predictor=L"Predictor";
	const WString JDFStrings::atr_Preferred=L"Preferred";
	const WString JDFStrings::atr_PreferredFont=L"PreferredFont";
	const WString JDFStrings::atr_PreflightActionList=L"PreflightActionList";
	const WString JDFStrings::atr_PreflightOutput=L"PreflightOutput";
	const WString JDFStrings::atr_PreflightProfile=L"PreflightProfile";
	const WString JDFStrings::atr_PreflightRule=L"PreflightRule";
	const WString JDFStrings::atr_PreflightStatus=L"PreflightStatus";
	const WString JDFStrings::atr_PreflightTool=L"PreflightTool";
	const WString JDFStrings::atr_PreflightToolVersion=L"PreflightToolVersion";
	const WString JDFStrings::atr_PreHeatTemp=L"PreHeatTemp";
	const WString JDFStrings::atr_PreHeatTime=L"PreHeatTime";
	const WString JDFStrings::atr_PrePrinted=L"PrePrinted";
	const WString JDFStrings::atr_PresentationDirection=L"PresentationDirection";
	const WString JDFStrings::atr_PresentationURL=L"PresentationURL";
	const WString JDFStrings::atr_PresentHWRelation=L"PresentHWRelation";
	const WString JDFStrings::atr_PresentLength=L"PresentLength";
	const WString JDFStrings::atr_PresentRegExp=L"PresentRegExp";
	const WString JDFStrings::atr_PresentRotateMod=L"PresentRotateMod";
	const WString JDFStrings::atr_PresentShift=L"PresentShift";
	const WString JDFStrings::atr_PresentTransforms=L"PresentTransforms";
	const WString JDFStrings::atr_PresentValue=L"PresentValue";
	const WString JDFStrings::atr_PresentValueDurationList=L"PresentValueDurationList";
	const WString JDFStrings::atr_PresentValueList=L"PresentValueList";
	const WString JDFStrings::atr_PresentValueMax=L"PresentValueMax";
	const WString JDFStrings::atr_PresentValueMin=L"PresentValueMin";
	const WString JDFStrings::atr_PresentValueMod=L"PresentValueMod";
	const WString JDFStrings::atr_PresentX=L"PresentX";
	const WString JDFStrings::atr_PresentXYRelation=L"PresentXYRelation";
	const WString JDFStrings::atr_PresentY=L"PresentY";
	const WString JDFStrings::atr_PresentZ=L"PresentZ";
	const WString JDFStrings::atr_PreserveBlack=L"PreserveBlack";
	const WString JDFStrings::atr_PreserveCopyPage=L"PreserveCopyPage";
	const WString JDFStrings::atr_PreserveEPSInfo=L"PreserveEPSInfo";
	const WString JDFStrings::atr_PreserveHalftoneInfo=L"PreserveHalftoneInfo";
	const WString JDFStrings::atr_PreserveOPIComments=L"PreserveOPIComments";
	const WString JDFStrings::atr_PreserveOverprintSettings=L"PreserveOverprintSettings";
	const WString JDFStrings::atr_PreviewFileType=L"PreviewFileType";
	const WString JDFStrings::atr_PreviewType=L"PreviewType";
	const WString JDFStrings::atr_PreviewUsage=L"PreviewUsage";
	const WString JDFStrings::atr_PrevQueueEntryID=L"PrevQueueEntryID";
	const WString JDFStrings::atr_Price=L"Price";
	const WString JDFStrings::atr_PrintableArea=L"PrintableArea";
	const WString JDFStrings::atr_PrintTrapAnnotations=L"PrintTrapAnnotations";
	const WString JDFStrings::atr_PrintConditionName=L"PrintConditionName";
	const WString JDFStrings::atr_PrinterFontsSubFolder=L"PrinterFontsSubFolder";
	const WString JDFStrings::atr_PrintingType=L"PrintingType";
	const WString JDFStrings::atr_PrintPDFAnnotations=L"PrintPDFAnnotations";
	const WString JDFStrings::atr_PrintQuality=L"PrintQuality";
	const WString JDFStrings::atr_Priority=L"Priority";
	const WString JDFStrings::atr_ProcessColorModel=L"ProcessColorModel";
	const WString JDFStrings::atr_ProcessUsage=L"ProcessUsage";
	const WString JDFStrings::atr_Producer=L"Producer";
	const WString JDFStrings::atr_ProductID=L"ProductID";
	const WString JDFStrings::atr_ProductionAmount=L"ProductionAmount";
	const WString JDFStrings::atr_ProductionCounter=L"ProductionCounter";
	const WString JDFStrings::atr_ProductionPathID=L"ProductionPathID";
	const WString JDFStrings::atr_ProductionType=L"ProductionType";
	const WString JDFStrings::atr_ProductType=L"ProductType";
	const WString JDFStrings::atr_ProductTypeDetails=L"ProductTypeDetails";
	const WString JDFStrings::atr_ProgressionOrder=L"ProgressionOrder";
	const WString JDFStrings::atr_ProjectID=L"ProjectID";
	const WString JDFStrings::atr_Proof=L"Proof";
	const WString JDFStrings::atr_ProofName=L"ProofName";
	const WString JDFStrings::atr_ProofQuality=L"ProofQuality";
	const WString JDFStrings::atr_ProofRenderingIntent=L"ProofRenderingIntent";
	const WString JDFStrings::atr_ProofTarget=L"ProofTarget";
	const WString JDFStrings::atr_ProofType=L"ProofType";
	const WString JDFStrings::atr_Property=L"Property";
	const WString JDFStrings::atr_PropertyList=L"PropertyList";
	const WString JDFStrings::atr_PSFontName=L"PSFontName";
	const WString JDFStrings::atr_PSLevel=L"PSLevel";
	const WString JDFStrings::atr_PullOutValue=L"PullOutValue";
	const WString JDFStrings::atr_Punch=L"Punch";
	const WString JDFStrings::atr_PunchType=L"PunchType";
	const WString JDFStrings::atr_Purpose=L"Purpose";
	const WString JDFStrings::atr_PurposeDetails=L"PurposeDetails";

	// QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ //

	const WString JDFStrings::atr_QFactor=L"QFactor";
	const WString JDFStrings::atr_QuantTable=L"QuantTable";
	const WString JDFStrings::atr_Query=L"Query";
	const WString JDFStrings::atr_QueueEntryID=L"QueueEntryID";
	const WString JDFStrings::atr_QueueEntryDetails=L"QueueEntryDetails";
	const WString JDFStrings::atr_QueueInfo=L"QueueInfo";
	const WString JDFStrings::atr_QueueSize=L"QueueSize";
	const WString JDFStrings::atr_QueueURL=L"QueueURL";

	// RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR //

	const WString JDFStrings::atr_Range=L"Range";
	const WString JDFStrings::atr_Ratio=L"Ratio";
	const WString JDFStrings::atr_RawAlias=L"RawAlias";
	const WString JDFStrings::atr_RawName=L"RawName";
	const WString JDFStrings::atr_ReaderPageCount=L"ReaderPageCount";
	const WString JDFStrings::atr_Reason=L"Reason";
	const WString JDFStrings::atr_ReceiverURL=L"ReceiverURL";
	const WString JDFStrings::atr_Recommendation=L"Recommendation";
	const WString JDFStrings::atr_Records=L"Records";
	const WString JDFStrings::atr_Recycled=L"Recycled";
	const WString JDFStrings::atr_RecycledPercentage=L"RecycledPercentage";
	const WString JDFStrings::atr_ref=L"ref";
	const WString JDFStrings::atr_ReferenceEdge=L"ReferenceEdge";
	const WString JDFStrings::atr_refID=L"refID";
	const WString JDFStrings::atr_RegExp=L"RegExp";
	const WString JDFStrings::atr_Region=L"Region";
	const WString JDFStrings::atr_Registration=L"Registration";
	const WString JDFStrings::atr_RelativeBox=L"RelativeBox";
	const WString JDFStrings::atr_RelatedJobID=L"RelatedJobID";
	const WString JDFStrings::atr_RelatedJobPartID=L"RelatedJobPartID";
	const WString JDFStrings::atr_RelativeStartPosition=L"RelativeStartPosition";
	const WString JDFStrings::atr_RelativeTravel=L"RelativeTravel";
	const WString JDFStrings::atr_RelativeWorkingPath=L"RelativeWorkingPath";
	const WString JDFStrings::atr_RelativeWorkingPattern=L"RelativeWorkingPattern";
	const WString JDFStrings::atr_RemotePipeEndPause=L"RemotePipeEndPause";
	const WString JDFStrings::atr_RemotePipeEndResume=L"RemotePipeEndResume";
	const WString JDFStrings::atr_RenderingIntent=L"RenderingIntent";
	const WString JDFStrings::atr_RepeatPolicy=L"RepeatPolicy";
	const WString JDFStrings::atr_RepeatStep=L"RepeatStep";
	const WString JDFStrings::atr_RepeatTime=L"RepeatTime";
	const WString JDFStrings::atr_ReplaceField=L"ReplaceField";
	const WString JDFStrings::atr_ReplacementColorantName=L"ReplacementColorantName";
	const WString JDFStrings::atr_ReportAttr=L"ReportAttr";
	const WString JDFStrings::atr_RequestQuality=L"RequestQuality";
	const WString JDFStrings::atr_Required=L"Required";

	const WString JDFStrings::atr_Resend=L"Resend";
	const WString JDFStrings::atr_ResponseURL=L"ResponseURL";
	const WString JDFStrings::atr_Resolution=L"Resolution";
	const WString JDFStrings::atr_ResolutionReductionStrategy=L"ResolutionReductionStrategy";
	const WString JDFStrings::atr_ResourceID=L"ResourceID";
	const WString JDFStrings::atr_ResourceName=L"ResourceName";
	const WString JDFStrings::atr_ResourceType=L"ResourceType";
	const WString JDFStrings::atr_ResourceUpdate=L"ResourceUpdate";
	const WString JDFStrings::atr_ResourceUsage=L"ResourceUsage";
	const WString JDFStrings::atr_ResourceWeight=L"ResourceWeight";
	const WString JDFStrings::atr_RestoreTime=L"RestoreTime";
	const WString JDFStrings::atr_RestTime=L"RestTime";
	const WString JDFStrings::atr_Restrictions=L"Restrictions";
	const WString JDFStrings::atr_ReturnCode=L"ReturnCode";
	const WString JDFStrings::atr_ReturnJMF=L"ReturnJMF";
	const WString JDFStrings::atr_ReturnList=L"ReturnList";
	const WString JDFStrings::atr_ReturnURL=L"ReturnURL";
	const WString JDFStrings::atr_ReversePageNumber=L"ReversePageNumber";
	const WString JDFStrings::atr_RGB2GrayBlack=L"RGB2GrayBlack";
	const WString JDFStrings::atr_RGBGray2Black=L"RGBGray2Black";
	const WString JDFStrings::atr_RGBGray2BlackThreshold=L"RGBGray2BlackThreshold"; 
	const WString JDFStrings::atr_RibbonColor=L"RibbonColor";
	const WString JDFStrings::atr_RibbonEnd=L"RibbonEnd";
	const WString JDFStrings::atr_RibbonName=L"RibbonName";
	const WString JDFStrings::atr_RingDiameter=L"RingDiameter";
	const WString JDFStrings::atr_RingMechanic=L"RingMechanic";
	const WString JDFStrings::atr_RingShape=L"RingShape";
	const WString JDFStrings::atr_RingSystem=L"RingSystem";
	const WString JDFStrings::atr_RivetsExposed=L"RivetsExposed";
	const WString JDFStrings::atr_Roles=L"Roles";
	const WString JDFStrings::atr_RollCut=L"RollCut";
	const WString JDFStrings::atr_RollDiameter=L"RollDiameter";
	const WString JDFStrings::atr_Rotate=L"Rotate";
	const WString JDFStrings::atr_RotateMod=L"RotateMod";
	const WString JDFStrings::atr_RotatePolicy=L"RotatePolicy";
	const WString JDFStrings::atr_Rotation=L"Rotation";
	const WString JDFStrings::atr_Rounding=L"Rounding";
	const WString JDFStrings::atr_Route=L"Route";
	const WString JDFStrings::atr_RowsPerStrip=L"RowsPerStrip";
	const WString JDFStrings::atr_Rows=L"Rows";
	const WString JDFStrings::atr_rRef=L"rRef";
	const WString JDFStrings::atr_rRefs=L"rRefs";
	const WString JDFStrings::atr_rRefsOverwritten=L"rRefsOverwritten";
	const WString JDFStrings::atr_rRefsROCopied=L"rRefsROCopied";
	const WString JDFStrings::atr_rRefsRWCopied=L"rRefsRWCopied";
	const WString JDFStrings::atr_rSubRef=L"rSubRef";
	const WString JDFStrings::atr_Run=L"Run";
	const WString JDFStrings::atr_RunIndex=L"RunIndex";
	const WString JDFStrings::atr_RunPage=L"RunPage";
	const WString JDFStrings::atr_RunSet=L"RunSet";
	const WString JDFStrings::atr_RunTag=L"RunTag";
	const WString JDFStrings::atr_RunTags=L"RunTags";

	// SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS //

	const WString JDFStrings::atr_SampleBacking=L"SampleBacking";
	const WString JDFStrings::atr_SampleInterval=L"SampleInterval";
	const WString JDFStrings::atr_Scale=L"Scale";
	const WString JDFStrings::atr_Scaling=L"Scaling";
	const WString JDFStrings::atr_ScalingOrigin=L"ScalingOrigin";
	const WString JDFStrings::atr_Scope=L"Scope";
	const WString JDFStrings::atr_Screen=L"Screen";
	const WString JDFStrings::atr_ScreeningFamily=L"ScreeningFamily";
	const WString JDFStrings::atr_ScreeningType=L"ScreeningType";
	const WString JDFStrings::atr_ScreenFontsSubFolder=L"ScreenFontsSubFolder";
	const WString JDFStrings::atr_ScreenRuling=L"ScreenRuling";
	const WString JDFStrings::atr_ScreenShape=L"ScreenShape";
	const WString JDFStrings::atr_Sealing=L"Sealing";
	const WString JDFStrings::atr_SealingTemperature=L"SealingTemperature";
	const WString JDFStrings::atr_SearchDepth=L"SearchDepth";
	const WString JDFStrings::atr_SectionIndex=L"SectionIndex";
	const WString JDFStrings::atr_SectionList=L"SectionList";
	const WString JDFStrings::atr_SecureJMFURL=L"SecureJMFURL";
	const WString JDFStrings::atr_Segmentation=L"Segmentation";
	const WString JDFStrings::atr_Select=L"Select";
	const WString JDFStrings::atr_SenderID=L"SenderID";
	const WString JDFStrings::atr_Separation=L"Separation";
	const WString JDFStrings::atr_SeparationFlag=L"SeparationFlag";
	const WString JDFStrings::atr_SeparationList=L"SeparationList";
	const WString JDFStrings::atr_SeparationNameTag=L"SeparationNameTag";
	const WString JDFStrings::atr_SerialNumber=L"SerialNumber";
	const WString JDFStrings::atr_ServiceLevel=L"ServiceLevel";
	const WString JDFStrings::atr_SetCopies=L"SetCopies";
	const WString JDFStrings::atr_SetDocIndex=L"SetDocIndex";
	const WString JDFStrings::atr_SetIndex=L"SetIndex";
	const WString JDFStrings::atr_SetLevel=L"SetLevel";
	const WString JDFStrings::atr_SetNames=L"SetNames";
	const WString JDFStrings::atr_SetOrd=L"SetOrd";
	const WString JDFStrings::atr_SetPageSize=L"SetPageSize";
	const WString JDFStrings::atr_SetRef=L"SetRef";
	const WString JDFStrings::atr_SetRunIndex=L"SetRunIndex";
	const WString JDFStrings::atr_Sets=L"Sets";
	const WString JDFStrings::atr_SetSheetIndex=L"SetSheetIndex";
	const WString JDFStrings::atr_SetSplitBy=L"SetSplitBy";
	const WString JDFStrings::atr_SetTags=L"SetTags";
	const WString JDFStrings::atr_SettingsPolicy=L"SettingsPolicy";
	const WString JDFStrings::atr_Setup=L"Setup";
	const WString JDFStrings::atr_SetupDuration=L"SetupDuration";
	const WString JDFStrings::atr_SetupProcsets=L"SetupProcsets";
	const WString JDFStrings::atr_Severity=L"Severity";
	const WString JDFStrings::atr_SewingPattern=L"SewingPattern";
	const WString JDFStrings::atr_ShadingType=L"ShadingType";
	const WString JDFStrings::atr_Shape=L"Shape";
	const WString JDFStrings::atr_ShapeDepth=L"ShapeDepth";
	const WString JDFStrings::atr_ShapeType=L"ShapeType";
	const WString JDFStrings::atr_SheetCollate=L"SheetCollate";
	const WString JDFStrings::atr_SheetFormat=L"SheetFormat";
	const WString JDFStrings::atr_SheetIndex=L"SheetIndex";
	const WString JDFStrings::atr_SheetLay=L"SheetLay";
	const WString JDFStrings::atr_SheetName=L"SheetName";
	const WString JDFStrings::atr_SheetOccurrence=L"SheetOccurrence";
	const WString JDFStrings::atr_SheetOffset=L"SheetOffset";
	const WString JDFStrings::atr_SheetPart=L"SheetPart";
	const WString JDFStrings::atr_SheetType=L"SheetType";
	const WString JDFStrings::atr_SheetUsage=L"SheetUsage";
	const WString JDFStrings::atr_Shift=L"Shift";
	const WString JDFStrings::atr_ShiftBack=L"ShiftBack";
	const WString JDFStrings::atr_ShiftFront=L"ShiftFront";
	const WString JDFStrings::atr_ShiftX=L"ShiftX";
	const WString JDFStrings::atr_ShiftXSide1=L"ShiftXSide1";
	const WString JDFStrings::atr_ShiftXSide2=L"ShiftXSide2";
	const WString JDFStrings::atr_ShiftY=L"ShiftY";
	const WString JDFStrings::atr_ShiftYSide1=L"ShiftYSide1";
	const WString JDFStrings::atr_ShiftYSide2=L"ShiftYSide2";
	const WString JDFStrings::atr_ShortValue=L"ShortValue";
	const WString JDFStrings::atr_ShowList=L"ShowList";
	const WString JDFStrings::atr_ShrinkIndex=L"ShrinkIndex";
	const WString JDFStrings::atr_ShrinkingMethod=L"ShrinkingMethod";
	const WString JDFStrings::atr_ShrinkToFit=L"ShrinkToFit";
	const WString JDFStrings::atr_ShutDownType=L"ShutDownType";
	const WString JDFStrings::atr_Side=L"Side";
	const WString JDFStrings::atr_SidelineEPS=L"SidelineEPS";
	const WString JDFStrings::atr_SidelineFonts=L"SidelineFonts";
	const WString JDFStrings::atr_SidelineImages=L"SidelineImages";
	const WString JDFStrings::atr_Sides=L"Sides";
	const WString JDFStrings::atr_Signal=L"Signal";
	const WString JDFStrings::atr_SignalType=L"SignalType";
	const WString JDFStrings::atr_SignalTypes=L"SignalTypes";
	const WString JDFStrings::atr_SignatureName=L"SignatureName";
	const WString JDFStrings::atr_Size=L"Size";
	const WString JDFStrings::atr_SizePolicy=L"SizePolicy";
	const WString JDFStrings::atr_SkipPage=L"SkipPage";
	const WString JDFStrings::atr_SlidingTrapLimit=L"SlidingTrapLimit";
	const WString JDFStrings::atr_Smoothness=L"Smoothness";
	const WString JDFStrings::atr_SortAmount=L"SortAmount";
	const WString JDFStrings::atr_Sorted=L"Sorted";
	const WString JDFStrings::atr_Sorting=L"Sorting";
	const WString JDFStrings::atr_SourceBleedBox=L"SourceBleedBox";
	const WString JDFStrings::atr_SourceClipBox=L"SourceClipBox";
	const WString JDFStrings::atr_SourceClipPath=L"SourceClipPath";
	const WString JDFStrings::atr_SourceCS=L"SourceCS";
	const WString JDFStrings::atr_SourceCSs=L"SourceCSs";
	const WString JDFStrings::atr_SourceFrequency=L"SourceFrequency";
	const WString JDFStrings::atr_SourceName=L"SourceName";
	const WString JDFStrings::atr_SourceObjects=L"SourceObjects";
	const WString JDFStrings::atr_SourceRenderingIntent=L"SourceRenderingIntent";
	const WString JDFStrings::atr_SourceRibbon=L"SourceRibbon";
	const WString JDFStrings::atr_SourceSheet=L"SourceSheet";
	const WString JDFStrings::atr_SourceTrimBox=L"SourceTrimBox";
	const WString JDFStrings::atr_SourceWeb=L"SourceWeb";
	const WString JDFStrings::atr_SourceWorkStyle=L"SourceWorkStyle";
	const WString JDFStrings::atr_SpawnID=L"SpawnID";
	const WString JDFStrings::atr_SpawnIDs=L"SpawnIDs";
	const WString JDFStrings::atr_SpawnStatus=L"SpawnStatus";
	const WString JDFStrings::atr_SpecialInk=L"SpecialInk";
	const WString JDFStrings::atr_SpecificYield=L"SpecificYield";
	const WString JDFStrings::atr_Speed=L"Speed";
	const WString JDFStrings::atr_Spine=L"Spine";
	const WString JDFStrings::atr_SpineColor=L"SpineColor";
	const WString JDFStrings::atr_SpineWidth=L"SpineWidth";
	const WString JDFStrings::atr_SplitDocuments=L"SplitDocuments";
	const WString JDFStrings::atr_SpotFunction=L"SpotFunction";
	const WString JDFStrings::atr_sRGB=L"sRGB";

	const WString JDFStrings::atr_StackDepth=L"StackDepth";
	const WString JDFStrings::atr_StaggerColumns=L"StaggerColumns";
	const WString JDFStrings::atr_StaggerContinuous=L"StaggerContinuous";
	const WString JDFStrings::atr_StaggerRows=L"StaggerRows";
	const WString JDFStrings::atr_StandardAmount=L"StandardAmount";
	const WString JDFStrings::atr_StapleShape=L"StapleShape";
	const WString JDFStrings::atr_Start=L"Start";
	const WString JDFStrings::atr_StartOffset=L"StartOffset";
	const WString JDFStrings::atr_StartPage=L"StartPage";
	const WString JDFStrings::atr_StartPosition=L"StartPosition";
	const WString JDFStrings::atr_StartTime=L"StartTime";
	const WString JDFStrings::atr_StartValue=L"StartValue";
	const WString JDFStrings::atr_StationAmount=L"StationAmount";
	const WString JDFStrings::atr_StationName=L"StationName";
	const WString JDFStrings::atr_Status=L"Status";
	const WString JDFStrings::atr_StatusList=L"StatusList";
	const WString JDFStrings::atr_StatusDetails=L"StatusDetails";
	const WString JDFStrings::atr_Step=L"Step";
	const WString JDFStrings::atr_StepDocs=L"StepDocs";
	const WString JDFStrings::atr_StepLimit=L"StepLimit";
	const WString JDFStrings::atr_StepRepeat=L"StepRepeat";
	const WString JDFStrings::atr_StitchFromFront=L"StitchFromFront";
	const WString JDFStrings::atr_StitchingPosition=L"StitchingPosition";
	const WString JDFStrings::atr_StitchingReferenceEdge=L"StitchingReferenceEdge";
	const WString JDFStrings::atr_StitchPositions=L"StitchPositions";
	const WString JDFStrings::atr_StitchType=L"StitchType";
	const WString JDFStrings::atr_StitchWidth=L"StitchWidth";
	const WString JDFStrings::atr_StockType=L"StockType";
	const WString JDFStrings::atr_StorageEvent=L"StorageEvent";
	const WString JDFStrings::atr_StoragePeriod=L"StoragePeriod";
	const WString JDFStrings::atr_StrapColor=L"StrapColor";
	const WString JDFStrings::atr_StrappingType=L"StrappingType";
	const WString JDFStrings::atr_StrapPositions=L"StrapPositions";
	const WString JDFStrings::atr_Street=L"Street";
	const WString JDFStrings::atr_StringValue=L"StringValue";
	const WString JDFStrings::atr_StripBrand=L"StripBrand";
	const WString JDFStrings::atr_StripColor=L"StripColor";
	const WString JDFStrings::atr_StripLength=L"StripLength";
	const WString JDFStrings::atr_StripMaterial=L"StripMaterial";
	const WString JDFStrings::atr_StripMarkDetails=L"StripMarkDetails";
	const WString JDFStrings::atr_StripType=L"StripType";
	const WString JDFStrings::atr_StrokeAlternateColorSpace=L"StrokeAlternateColorSpace";
	const WString JDFStrings::atr_StrokeColorName=L"StrokeColorName";
	const WString JDFStrings::atr_StrokeColorSpace=L"StrokeColorSpace";
	const WString JDFStrings::atr_StrokeColorType=L"StrokeColorType";
	const WString JDFStrings::atr_StrokeOverprintFlag=L"StrokeOverprintFlag";
	const WString JDFStrings::atr_StrokeShadingType=L"StrokeShadingType";
	const WString JDFStrings::atr_StrokeThickness=L"StrokeThickness";
	const WString JDFStrings::atr_Subject=L"Subject";
	const WString JDFStrings::atr_SubmissionTime=L"SubmissionTime";
	const WString JDFStrings::atr_SubmitPolicy=L"SubmitPolicy";
	const WString JDFStrings::atr_SubModuleIndex=L"SuModuleIndex";
	const WString JDFStrings::atr_Subscribed=L"Subscribed";
	const WString JDFStrings::atr_SubRun=L"SubRun";
	const WString JDFStrings::atr_SubsetFonts=L"SubsetFonts";
	const WString JDFStrings::atr_SuppressCenter=L"SuppressCenter";
	const WString JDFStrings::atr_SuppressRotate=L"SuppressRotate";
	const WString JDFStrings::atr_SurfaceContentsBox=L"SurfaceContentsBox";
	const WString JDFStrings::atr_SurfaceCount=L"SurfaceCount";

	// TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT //

	const WString JDFStrings::atr_TabBanks=L"TabBanks";
	const WString JDFStrings::atr_TabsPerBank=L"TabsPerBank";
	const WString JDFStrings::atr_TagNumber=L"TagNumber";
	const WString JDFStrings::atr_TagType=L"TagType";
	const WString JDFStrings::atr_TargetRoute=L"TargetRoute";
	const WString JDFStrings::atr_TeethPerDimension=L"TeethPerDimension";
	const WString JDFStrings::atr_Temperature=L"Temperature";
	const WString JDFStrings::atr_Template=L"Template";
	const WString JDFStrings::atr_TemplateID=L"TemplateID";
	const WString JDFStrings::atr_TemplateType=L"TemplateType";
	const WString JDFStrings::atr_TemplateVersion=L"TemplateVersion";
	const WString JDFStrings::atr_TestRef=L"TestRef";
	const WString JDFStrings::atr_TextBlackLevel=L"TextBlackLevel";
	const WString JDFStrings::atr_TextSize=L"TextSize";
	const WString JDFStrings::atr_TextSizeThreshold=L"TextSizeThreshold";
	const WString JDFStrings::atr_Texture=L"Texture";
	const WString JDFStrings::atr_Thickness=L"Thickness";
	const WString JDFStrings::atr_ThreadBrand=L"ThreadBrand";
	const WString JDFStrings::atr_ThreadLength=L"ThreadLength";
	const WString JDFStrings::atr_ThreadMaterial=L"ThreadMaterial";
	const WString JDFStrings::atr_ThreadPositions=L"ThreadPositions";
	const WString JDFStrings::atr_ThreadStitchWidth=L"ThreadStitchWidth";
	const WString JDFStrings::atr_ThreadThickness=L"ThreadThickness";
	const WString JDFStrings::atr_Ties=L"Ties";
	const WString JDFStrings::atr_TightBacking=L"TightBacking";
	const WString JDFStrings::atr_TileID=L"TileID";
	const WString JDFStrings::atr_TileSize=L"TileSize";
	const WString JDFStrings::atr_Time=L"Time";
	const WString JDFStrings::atr_TimeInterval=L"TimeInterval";
	const WString JDFStrings::atr_TimeStamp=L"TimeStamp";
	const WString JDFStrings::atr_Title=L"Title";
	const WString JDFStrings::atr_To=L"To";
	const WString JDFStrings::atr_ToBox=L"ToBox";
	const WString JDFStrings::atr_Tolerance=L"Tolerance";
	const WString JDFStrings::atr_ToleranceBlack=L"ToleranceBlack";
	const WString JDFStrings::atr_ToleranceCyan=L"ToleranceCyan";
	const WString JDFStrings::atr_ToleranceDotGain=L"ToleranceDotGain";
	const WString JDFStrings::atr_ToleranceMagenta=L"ToleranceMagenta";
	const WString JDFStrings::atr_ToleranceYellow=L"ToleranceYellow";
	const WString JDFStrings::atr_ToolAmount=L"ToolAmount";
	const WString JDFStrings::atr_ToolID=L"ToolID";
	const WString JDFStrings::atr_ToolType=L"ToolType";
	const WString JDFStrings::atr_TopBrand=L"TopBrand";
	const WString JDFStrings::atr_TopColor=L"TopColor";
	const WString JDFStrings::atr_TopExcess=L"TopExcess";
	const WString JDFStrings::atr_TopFoldIn=L"TopFoldIn";
	const WString JDFStrings::atr_TopLength=L"TopLength";
	const WString JDFStrings::atr_TotalAmount=L"TotalAmount";
	const WString JDFStrings::atr_TotalDimensions=L"TotalDimensions";
	const WString JDFStrings::atr_TotalDuration=L"TotalDuration";
	const WString JDFStrings::atr_TotalVolume=L"TotalVolume";
	const WString JDFStrings::atr_TotalWeight=L"TotalWeight";
	const WString JDFStrings::atr_TotalProductionCounter=L"TotalProductionCounter";
	const WString JDFStrings::atr_TrackingID=L"TrackingID";
	const WString JDFStrings::atr_Transfer=L"Transfer";
	const WString JDFStrings::atr_TransferCurve=L"TransferCurve";
	const WString JDFStrings::atr_TransferFunction=L"TransferFunction";
	const WString JDFStrings::atr_TransferFunctionInfo=L"TransferFunctionInfo";
	const WString JDFStrings::atr_TransferFunctionSource=L"TransferFunctionSource";
	const WString JDFStrings::atr_Transformation=L"Transformation";
	const WString JDFStrings::atr_TransformationContext=L"TransformationContext";
	const WString JDFStrings::atr_Transforms=L"Transforms";
	const WString JDFStrings::atr_TransparencyFlag=L"TransparencyFlag";
	const WString JDFStrings::atr_TransparencyRenderingQuality=L"TransparencyRenderingQuality";
	const WString JDFStrings::atr_TrapColorScaling=L"TrapColorScaling";
	const WString JDFStrings::atr_TrapEndStyle=L"TrapEndStyle";
	const WString JDFStrings::atr_TrapJoinStyle=L"TrapJoinStyle";
	const WString JDFStrings::atr_TrapnetAnnotationPDFX=L"TrapnetAnnotationPDFX";
	const WString JDFStrings::atr_TrappedKey=L"TrappedKey";
	const WString JDFStrings::atr_Trapping=L"Trapping";
	const WString JDFStrings::atr_TrappingType=L"TrappingType";
	const WString JDFStrings::atr_TrapPlacement=L"TrapPlacement";
	const WString JDFStrings::atr_TrapWidth=L"TrapWidth";
	const WString JDFStrings::atr_TrapWidthY=L"TrapWidthY";
	const WString JDFStrings::atr_TrapZone=L"TrapZone";
	const WString JDFStrings::atr_Travel=L"Travel";
	const WString JDFStrings::atr_TravelInterval=L"TravelInterval";
	const WString JDFStrings::atr_TrimCover=L"TrimCover";
	const WString JDFStrings::atr_TrimCTM=L"TrimCTM";
	const WString JDFStrings::atr_TrimFace=L"TrimFace";
	const WString JDFStrings::atr_TrimFoot=L"TrimFoot";
	const WString JDFStrings::atr_TrimHead=L"TrimHead";
	const WString JDFStrings::atr_TrimmingOffset=L"TrimmingOffset";
	const WString JDFStrings::atr_TrimmingType=L"TrimmingType";
	const WString JDFStrings::atr_TrimSize=L"TrimSize";
	const WString JDFStrings::atr_TTasT42=L"TTasT42";
	const WString JDFStrings::atr_Tucked=L"Tucked";
	const WString JDFStrings::atr_Type=L"Type";
	const WString JDFStrings::atr_TypeAmount=L"TypeAmount";
	const WString JDFStrings::atr_TypeExpression=L"TypeExpression";
	const WString JDFStrings::atr_TypeOrder=L"TypeOrder";
	const WString JDFStrings::atr_TypeOccurrenceNum=L"TypeOccurrenceNum";
	const WString JDFStrings::atr_Types=L"Types";

	// UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU //

	const WString JDFStrings::atr_UCRandBGInfo=L"UCRandBGInfo";
	const WString JDFStrings::atr_UID=L"UID";
	const WString JDFStrings::atr_Uncompressed=L"Uncompressed";
	const WString JDFStrings::atr_UnderColorRemoval=L"UnderColorRemoval";
	const WString JDFStrings::atr_UnderLays=L"UnderLays";
	const WString JDFStrings::atr_Unit=L"Unit";
	const WString JDFStrings::atr_UnitType=L"UnitType";
	const WString JDFStrings::atr_Until=L"Until";
	const WString JDFStrings::atr_UPC=L"UPC";
	const WString JDFStrings::atr_UpdatedStatus=L"UpdatedStatus";
	const WString JDFStrings::atr_UpdateID=L"UpdateID";
	const WString JDFStrings::atr_UpdateIDs=L"UpdateIDs";
	const WString JDFStrings::atr_UpdateMethod=L"UpdateMethod";
	const WString JDFStrings::atr_URL=L"URL";
	const WString JDFStrings::atr_URLSchemes=L"URLSchemes";
	const WString JDFStrings::atr_Usage=L"Usage";
	const WString JDFStrings::atr_UseArtificialTextEffect=L"UseArtificialTextEffect";
	const WString JDFStrings::atr_UseDefaultFont=L"UseDefaultFont";
	const WString JDFStrings::atr_UseFontAliasNames=L"UseFontAliasNames";
	const WString JDFStrings::atr_UseFontEmulation=L"UseFontEmulation";
	const WString JDFStrings::atr_UsePDLAlternateCS=L"UsePDLAlternateCS";
	const WString JDFStrings::atr_UsePrologue=L"UsePrologue";
	const WString JDFStrings::atr_UserDisplay=L"UserDisplay";
	const WString JDFStrings::atr_UserFileName=L"UserFileName";
	const WString JDFStrings::atr_UserMediaType=L"UserMediaType";
	const WString JDFStrings::atr_UserText=L"UserText";

	// VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV//

	const WString JDFStrings::atr_Vacuum=L"Vacuum";
	const WString JDFStrings::atr_Value=L"Value";
	const WString JDFStrings::atr_ValueDurationList=L"ValueDurationList";
	const WString JDFStrings::atr_ValueFormat=L"ValueFormat";
	const WString JDFStrings::atr_ValueList=L"ValueList";
	const WString JDFStrings::atr_ValueMod=L"ValueMod";
	const WString JDFStrings::atr_ValueRange=L"ValueRange";
	const WString JDFStrings::atr_ValueTemplate=L"ValueTemplate";
	const WString JDFStrings::atr_ValueUsage=L"ValueUsage";
	const WString JDFStrings::atr_VarnishArea=L"VarnishArea";
	const WString JDFStrings::atr_Version=L"Version";
	const WString JDFStrings::atr_VerticalCreep=L"VerticalCreep";
	const WString JDFStrings::atr_ViewBinder=L"ViewBinder";
	const WString JDFStrings::atr_VisibleLength=L"VisibleLength";
	const WString JDFStrings::atr_VSamples=L"VSamples";

	// WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW//

	const WString JDFStrings::atr_WarningCount=L"WarningCount";
	const WString JDFStrings::atr_WasMarked=L"WasMarked";
	const WString JDFStrings::atr_Waste=L"Waste";
	const WString JDFStrings::atr_WatchURL=L"WatchURL";
	const WString JDFStrings::atr_WebName=L"WebName";
	const WString JDFStrings::atr_WebProduct=L"WebProduct";
	const WString JDFStrings::atr_WebSetup=L"WebSetup";
	const WString JDFStrings::atr_Weight=L"Weight";
	const WString JDFStrings::atr_WhiteBase=L"WhiteBase";
	const WString JDFStrings::atr_WhiteIsZero=L"WhiteIsZero";
	const WString JDFStrings::atr_Width=L"Width";
	const WString JDFStrings::atr_WireBrand=L"WireBrand";
	const WString JDFStrings::atr_WireGauge=L"WireGauge";
	const WString JDFStrings::atr_WorkingDirection=L"WorkingDirection";
	const WString JDFStrings::atr_WorkingLength=L"WorkingLength";
	const WString JDFStrings::atr_WorkingList=L"WorkingList";
	const WString JDFStrings::atr_WorkingPath=L"WorkingPath";
	const WString JDFStrings::atr_WorkStyle=L"WorkStyle";
	const WString JDFStrings::atr_WorkType=L"WorkType";
	const WString JDFStrings::atr_WorkTypeDetails=L"WorkTypeDetails";
	const WString JDFStrings::atr_WrapPages=L"WrapPages";
	const WString JDFStrings::atr_WrappedQuantity=L"WrappedQuantity";
	const WString JDFStrings::atr_WrapperWeight=L"WrapperWeight";
	const WString JDFStrings::atr_WrappingKind=L"WrappingKind";
	const WString JDFStrings::atr_WrappingMaterial=L"WrappingMaterial";

	// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//

	const WString JDFStrings::atr_X=L"X";
	const WString JDFStrings::atr_XCells=L"XCells";
	const WString JDFStrings::atr_XOffset=L"XOffset";
	const WString JDFStrings::atr_XPath=L"XPath";
	const WString JDFStrings::atr_XPosition=L"XPosition";
	const WString JDFStrings::atr_XYRelation=L"XYRelation";

	// YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY//
	const WString JDFStrings::atr_Y=L"Y";
	const WString JDFStrings::atr_YCells=L"YCells";
	const WString JDFStrings::atr_YPosition=L"YPosition";

	// ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ//

	const WString JDFStrings::atr_Z=L"Z";
	const WString JDFStrings::atr_ZoneHeight=L"ZoneHeight";
	const WString JDFStrings::atr_Zones=L"Zones";
	const WString JDFStrings::atr_ZoneSettingsX=L"ZoneSettingsX";
	const WString JDFStrings::atr_ZoneSettingsY=L"ZoneSettingsY";
	const WString JDFStrings::atr_ZonesY=L"ZonesY";
	const WString JDFStrings::atr_ZoneWidth=L"ZoneWidth";



	// for type checks	
	const WString JDFStrings::atr_Params=L"Params";
	const WString JDFStrings::atr_Intent=L"Intent";
	const WString JDFStrings::atr_Link=L"Link";
	const WString JDFStrings::atr_Pool=L"Pool";
	const WString JDFStrings::atr_Ref=L"Ref";
	const WString JDFStrings::atr_Update=L"Update";
	const WString JDFStrings::atr_true=L"true";
	const WString JDFStrings::atr_false=L"false";
	const WString JDFStrings::atr_Unknown=L"Unknown";

	//////////////////////////////////////////////////////////////////////
	/**
	* JDF 1.2 new additions
	*/
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

const WString JDFStrings::atr_AbsoluteHeight=L"AbsoluteHeight";
const WString JDFStrings::atr_AbsoluteWidth=L"AbsoluteWidth";
const WString JDFStrings::atr_Anchor=L"Anchor";
const WString JDFStrings::atr_Metadata0=L"Metadata0";
const WString JDFStrings::atr_Metadata1=L"Metadata1";
const WString JDFStrings::atr_Metadata2=L"Metadata2";
const WString JDFStrings::atr_Metadata3=L"Metadata3";
const WString JDFStrings::atr_Metadata4=L"Metadata4";
const WString JDFStrings::atr_Metadata5=L"Metadata5";
const WString JDFStrings::atr_Metadata6=L"Metadata6";
const WString JDFStrings::atr_Metadata7=L"Metadata7";
const WString JDFStrings::atr_Metadata8=L"Metadata8";
const WString JDFStrings::atr_Metadata9=L"Metadata9";

const WString JDFStrings::atr_VarnishMethod=L"VarnishMethod";
const WString JDFStrings::atr_TabEdge=L"TabEdge";
const WString JDFStrings::atr_TabExtensionDistance=L"TabExtensionDistance";
const WString JDFStrings::atr_TabOffset=L"TabOffset";
const WString JDFStrings::atr_TabSetCollationOrder=L"TabSetCollationOrder";
const WString JDFStrings::atr_TabWidth=L"TabWidth";
const WString JDFStrings::atr_Families=L"Families";
const WString JDFStrings::atr_MessageTypes=L"MessageTypes";
const WString JDFStrings::atr_InnerDimensions=L"InnerDimensions";
const WString JDFStrings::atr_Standard=L"Standard";

const WString JDFStrings::atr_Area=L"Area";
const WString JDFStrings::atr_DDESCutType=L"DDESCutType";
const WString JDFStrings::atr_AllowedRotate=L"AllowedRotate";
const WString JDFStrings::atr_GutterX=L"GutterX";
const WString JDFStrings::atr_GutterX2=L"GutterX2";
const WString JDFStrings::atr_GutterY=L"GutterY";
const WString JDFStrings::atr_GutterY2=L"GutterY2";
const WString JDFStrings::atr_LayoutStyle=L"LayoutStyle";
const WString JDFStrings::atr_OrderQuantity=L"OrderQuantity";
const WString JDFStrings::atr_UseBleeds=L"UseBleeds";



const WString JDFStrings::atr_AnchorType=L"AnchorType";

const WString JDFStrings::atr_PageRange=L"PageRange";
const WString JDFStrings::atr_RunPageRange=L"RunPageRange";
const WString JDFStrings::atr_PositionPolicy=L"PositionPolicy";
const WString JDFStrings::atr_RelativeSize=L"RelativeSize";
const WString JDFStrings::atr_RotationPolicy=L"RotationPolicy";

const WString JDFStrings::atr_RestrictedContentObjects=L"RestrictedContentObjects";
const WString JDFStrings::atr_Index=L"Index";

const WString JDFStrings::atr_Estimate=L"Estimate";
const WString JDFStrings::atr_SheetHeight=L"SheetHeight";
const WString JDFStrings::atr_SheetWidth=L"SheetWidth";

const WString JDFStrings::atr_URLTypes=L"URLTypes";
const WString JDFStrings::atr_URLType=L"URLType";

const WString JDFStrings::atr_OrdReset=L"OrdReset";
const WString JDFStrings::atr_SheetCountReset=L"SheetCountReset";
const WString JDFStrings::atr_MaxCollect=L"MaxCollect";
const WString JDFStrings::atr_MinCollect=L"MinCollect";
const WString JDFStrings::atr_OrdsConsumed=L"OrdsConsumed";
const WString JDFStrings::atr_SheetNameFormat=L"SheetNameFormat";
const WString JDFStrings::atr_SheetNameTemplate=L"SheetNameTemplate";


const WString JDFStrings::atr_JobFormat=L"JobFormat";
const WString JDFStrings::atr_JobTemplate=L"JobTemplate";

const WString JDFStrings::atr_ISBN10=L"ISBN10";
const WString JDFStrings::atr_ISBN13=L"ISBN13";

const WString JDFStrings::atr_AuthenticationType=L"AuthenticationType";
const WString JDFStrings::atr_ReasonDetails=L"ReasonDetails";

const WString JDFStrings::atr_FaceCells=L"FaceCells";
const WString JDFStrings::atr_ObjectTags=L"ObjectTags";

const WString JDFStrings::atr_IsDoubleByteFont=L"IsDoubleByteFont";
const WString JDFStrings::atr_PageHasOptionalContent=L"PageHasOptionalContent";

const WString JDFStrings::atr_PageScalingFactor=L"PageScalingFactor";

const WString JDFStrings::atr_ContentRef=L"ContentRef";
const WString JDFStrings::atr_StackOrd=L"StackOrd";
const WString JDFStrings::atr_TrimClipPath=L"TrimClipPath";
const WString JDFStrings::atr_CompensationCTM=L"CompensationCTM";

const WString JDFStrings::atr_CutWidth=L"CutWidth";
const WString JDFStrings::atr_ColorDetails=L"ColorDetails";

const WString JDFStrings::atr_InnermostShingling=L"InnermostShingling";
const WString JDFStrings::atr_OutermostShingling=L"OutermostShingling";

const WString JDFStrings::atr_StripColorDetails=L"StripColorDetails";
const WString JDFStrings::atr_StitchOrigin=L"StitchOrigin";
const WString JDFStrings::atr_LayerLift=L"LayerLift";

const WString JDFStrings::atr_LayerCompression=L"LayerCompression";
const WString JDFStrings::atr_PreStackAmount=L"PreStackAmount";
const WString JDFStrings::atr_PreStackMethod=L"PreStackMethod";
const WString JDFStrings::atr_StackCompression=L"StackCompression";


const WString JDFStrings::atr_HorizontalExcessBack=L"HorizontalExcessBack";
const WString JDFStrings::atr_BinderColorDetails=L"BinderColorDetails";
const WString JDFStrings::atr_SpineColorDetails=L"SpineColorDetails";
const WString JDFStrings::atr_RibbonColorDetails=L"RibbonColorDetails";
const WString JDFStrings::atr_MimeTypeDetails=L"MimeTypeDetails";

const WString JDFStrings::atr_IgnoreContext=L"IgnoreContext";
const WString JDFStrings::atr_SheetSides=L"SheetSides";
const WString JDFStrings::atr_Languages=L"Languages";

const WString JDFStrings::atr_Overhang=L"Overhang";
const WString JDFStrings::atr_OverhangOffset=L"OverhangOffset";

const WString JDFStrings::atr_BackCoatingDetail=L"BackCoatingDetail";
const WString JDFStrings::atr_FrontCoatingDetail=L"FrontCoatingDetail";
const WString JDFStrings::atr_MediaQuality=L"MediaQuality";
const WString JDFStrings::atr_PrintingTechnology=L"PrintingTechnology";
const WString JDFStrings::atr_ReliefThickness=L"ReliefThickness";
const WString JDFStrings::atr_SleeveInterlock=L"SleeveInterlock";

const WString JDFStrings::atr_ContentDataRefs=L"ContentDataRefs";
const WString JDFStrings::atr_SourceMediaBox=L"SourceMediaBox";

const WString JDFStrings::atr_TopColorDetails=L"TopColorDetails";
const WString JDFStrings::atr_BottomColorDetails=L"BottomColorDetails";
const WString JDFStrings::atr_ClampColorDetails=L"ClampColorDetails";

const WString JDFStrings::atr_HorizontalFitPolicy=L"HorizontalFitPolicy";
const WString JDFStrings::atr_VerticalFitPolicy=L"VerticalFitPolicy";

const WString JDFStrings::atr_NUpSeparation=L"NUpSeparation";
const WString JDFStrings::atr_SpineThickness=L"SpineThickness";
const WString JDFStrings::atr_RawNames=L"RawNames";

const WString JDFStrings::atr_ActualColorName=L"ActualColorName";
const WString JDFStrings::atr_Gray=L"Gray";

const WString JDFStrings::atr_Columns=L"Columns";
const WString JDFStrings::atr_ComponentOrientation=L"ComponentOrientation";

const WString JDFStrings::atr_AlignmentReferenceWeb=L"AlignmentReferenceWeb";
const WString JDFStrings::atr_FoldLay=L"FoldLay";
const WString JDFStrings::atr_WebCellAlignment=L"WebCellAlignment";

const WString JDFStrings::atr_TabCount=L"TabCount";

const WString JDFStrings::atr_ChannelMode=L"ChannelMode";
const WString JDFStrings::atr_RetryPolicy=L"RetryPolicy";
const WString JDFStrings::atr_LotDetails=L"LotDetails";
const WString JDFStrings::atr_ResourceDetails=L"ResourceDetails";
const WString JDFStrings::atr_CommandResult=L"CommandResult";
const WString JDFStrings::atr_LotControlled=L"LotControlled";

const WString JDFStrings::atr_PreviewUsages=L"PreviewUsages";
const WString JDFStrings::atr_UpdateGranularity=L"UpdateGranularity";
const WString JDFStrings::atr_MilestoneTypes=L"MilestoneTypes";

const WString JDFStrings::atr_TransactionID=L"TransactionID";
const WString JDFStrings::atr_IdleStartTime=L"IdleStartTime";
const WString JDFStrings::atr_RelatedCommands=L"RelatedCommands";
const WString JDFStrings::atr_ReturnTime=L"ReturnTime";
const WString JDFStrings::atr_WorkStepID=L"WorkStepID";

const WString JDFStrings::atr_MarkContext=L"MarkContext";
const WString JDFStrings::atr_RelativeHeight=L"RelativeHeight";
const WString JDFStrings::atr_RelativeWidth=L"RelativeWidth";

const WString JDFStrings::atr_DieSide=L"DieSide";
const WString JDFStrings::atr_Rotated=L"Rotated";
const WString JDFStrings::atr_ContentRefs=L"ContentRefs";


}
