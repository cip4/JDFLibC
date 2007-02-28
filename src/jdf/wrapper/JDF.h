/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2004 The International Cooperation for the Integration of 
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
// created before 19.Jan.2000
// 06/07/00 | RP | renamed JDFProcessInfo to JDFNodeInfo
// 040900 RP renamed JDFProcess to JDFNode
// 250601 RP zapped using namespace
// 180602 RP rordered and made compatible with JDF 1.1
//
#include "jdf/lang/KString.h"
#include "jdf/util/JDFLibVersion.h"

#include <algorithm> // explicit include to min/max

#include "jdf/wrappercore/JDFParser.h"
#include "jdf/wrapper/JDFDoc.h"
#include "jdf/wrapper/JDFComment.h"
#include "jdf/wrapper/JDFSpan.h"


#include "jdf/wrapper/JDFAcknowledge.h"
#include "jdf/wrapper/JDFAction.h"
#include "jdf/wrapper/JDFAdhesiveBinding.h"
#include "jdf/wrapper/JDFAddress.h"
#include "jdf/wrapper/JDFApprovalPerson.h"
#include "jdf/wrapper/JDFApprovalSuccess.h"
#include "jdf/wrapper/JDFArgumentValue.h"
#include "jdf/wrapper/JDFArtDelivery.h"
#include "jdf/wrapper/JDFAdded.h"
#include "jdf/wrapper/JDFAncestor.h"
#include "jdf/wrapper/JDFand.h"
#include "jdf/wrapper/JDFAssembly.h"
#include "jdf/wrapper/JDFAssemblySection.h"
#include "jdf/wrapper/JDFAudit.h"

#include "jdf/wrapper/JDFBand.h"
#include "jdf/wrapper/JDFBasicPreflightTest.h"
#include "jdf/wrapper/JDFBusinessInfo.h"
#include "jdf/wrapper/JDFByteMap.h"
#include "jdf/wrapper/JDFBarcode.h"
#include "jdf/wrapper/JDFBookCase.h"
#include "jdf/wrapper/JDFBoxArgument.h"
#include "jdf/wrapper/JDFBoxToBoxDifference.h"
#include "jdf/wrapper/JDFBindItem.h"
#include "jdf/wrapper/JDFBindList.h"
#include "jdf/wrapper/JDFBinderySignature.h"
#include "jdf/wrapper/JDFBooleanEvaluation.h"
#include "jdf/wrapper/JDFBooleanState.h"

#include "jdf/wrapper/JDFcall.h"
#include "jdf/wrapper/JDFChannelBinding.h"
#include "jdf/wrapper/JDFChangedAttribute.h"
#include "jdf/wrapper/JDFchoice.h"
#include "jdf/wrapper/JDFCoilBinding.h"
#include "jdf/wrapper/JDFCollatingItem.h"
#include "jdf/wrapper/JDFColorantAlias.h"
#include "jdf/wrapper/JDFColorantControl.h"
#include "jdf/wrapper/JDFColorantZoneDetails.h"
#include "jdf/wrapper/JDFColor.h"
#include "jdf/wrapper/JDFColorControlStrip.h"
#include "jdf/wrapper/JDFColorCorrectionOp.h"
#include "jdf/wrapper/JDFColorSpaceConversionOp.h"
#include "jdf/wrapper/JDFColorMeasurementConditions.h"
#include "jdf/wrapper/JDFColorSpaceSubstitute.h"
#include "jdf/wrapper/JDFColorsUsed.h"
#include "jdf/wrapper/JDFCommand.h"
#include "jdf/wrapper/JDFComment.h"
#include "jdf/wrapper/JDFContainer.h"
#include "jdf/wrapper/JDFCounterReset.h"
#include "jdf/wrapper/JDFCrease.h"
#include "jdf/wrapper/JDFCreditCard.h"
#include "jdf/wrapper/JDFCut.h"
#include "jdf/wrapper/JDFCutBlock.h"
#include "jdf/wrapper/JDFCutMark.h"
#include "jdf/wrapper/JDFCIELABMeasuringField.h"
#include "jdf/wrapper/JDFComChannel.h"
#include "jdf/wrapper/JDFCompany.h"
#include "jdf/wrapper/JDFComponent.h"
#include "jdf/wrapper/JDFContact.h"
#include "jdf/wrapper/JDFContentObject.h"
#include "jdf/wrapper/JDFCostCenter.h"
#include "jdf/wrapper/JDFCreated.h"
#include "jdf/wrapper/JDFCustomerInfo.h"


#include "jdf/wrapper/JDFDate.h"
#include "jdf/wrapper/JDFDateTimeEvaluation.h"
#include "jdf/wrapper/JDFDateTimeState.h"
#include "jdf/wrapper/JDFDBRules.h"
#include "jdf/wrapper/JDFDBSchema.h"
#include "jdf/wrapper/JDFDBSelection.h"
#include "jdf/wrapper/JDFDeleted.h"
#include "jdf/wrapper/JDFDensityMeasuringField.h"
#include "jdf/wrapper/JDFDependencies.h"
#include "jdf/wrapper/JDFDevCap.h"
#include "jdf/wrapper/JDFDevCaps.h"
#include "jdf/wrapper/JDFDevice.h"
#include "jdf/wrapper/JDFDeviceCap.h"
#include "jdf/wrapper/JDFDeviceMark.h"
#include "jdf/wrapper/JDFDeviceList.h"
#include "jdf/wrapper/JDFDeviceNSpace.h"
#include "jdf/wrapper/JDFDeviceNColor.h"
#include "jdf/wrapper/JDFDeviceFilter.h"
#include "jdf/wrapper/JDFDeviceInfo.h"
#include "jdf/wrapper/JDFDigitalMedia.h"
#include "jdf/wrapper/JDFDisjointing.h"
#include "jdf/wrapper/JDFDisplayGroup.h"
#include "jdf/wrapper/JDFDisposition.h"
#include "jdf/wrapper/JDFDrop.h"
#include "jdf/wrapper/JDFDropItem.h"
#include "jdf/wrapper/JDFDuration.h"
#include "jdf/wrapper/JDFDurationEvaluation.h"
#include "jdf/wrapper/JDFDurationState.h"
#include "jdf/wrapper/JDFDynamicField.h"
#include "jdf/wrapper/JDFDynamicInput.h"

#include "jdf/wrapper/JDFElement.h"
#include "jdf/wrapper/JDFEmboss.h"
#include "jdf/wrapper/JDFEmbossingItem.h"
#include "jdf/wrapper/JDFEmployee.h"
#include "jdf/wrapper/JDFEdgeGluing.h"
#include "jdf/wrapper/JDFEmployeeDef.h"
#include "jdf/wrapper/JDFEndSheet.h"
#include "jdf/wrapper/JDFEnumerationEvaluation.h"
#include "jdf/wrapper/JDFEnumerationState.h"
#include "jdf/wrapper/JDFError.h"
#include "jdf/wrapper/JDFExposedMedia.h"

#include "jdf/wrapper/JDFFCNKey.h"
#include "jdf/wrapper/JDFFeatureAttribute.h"
#include "jdf/wrapper/JDFFeeder.h"
#include "jdf/wrapper/JDFFlushedResources.h"
#include "jdf/wrapper/JDFFlushResourceParams.h"
#include "jdf/wrapper/JDFFlushQueueParams.h"
#include "jdf/wrapper/JDFFold.h"
#include "jdf/wrapper/JDFFitPolicy.h"
#include "jdf/wrapper/JDFFontPolicy.h"
#include "jdf/wrapper/JDFFileAlias.h"
#include "jdf/wrapper/JDFFileSpec.h"

#include "jdf/wrapper/JDFGlue.h"
#include "jdf/wrapper/JDFGlueApplication.h"
#include "jdf/wrapper/JDFGlueLine.h"

#include "jdf/wrapper/JDFHardCoverBinding.h"
#include "jdf/wrapper/JDFHole.h"
#include "jdf/wrapper/JDFHoleList.h"
#include "jdf/wrapper/JDFHoleLine.h"

#include "jdf/wrapper/JDFIcon.h"
#include "jdf/wrapper/JDFIconList.h"
#include "jdf/wrapper/JDFIDInfo.h"
#include "jdf/wrapper/JDFIDPCover.h"
#include "jdf/wrapper/JDFIDPFolding.h"
#include "jdf/wrapper/JDFIDPFinishing.h"
#include "jdf/wrapper/JDFIDPHoleMaking.h"
#include "jdf/wrapper/JDFIDPLayout.h"
#include "jdf/wrapper/JDFIDPStitching.h"
#include "jdf/wrapper/JDFIDPTrimming.h"
#include "jdf/wrapper/JDFIDPJobSheet.h"
#include "jdf/wrapper/JDFImageCompression.h"
#include "jdf/wrapper/JDFImageShift.h"
#include "jdf/wrapper/JDFInk.h"
#include "jdf/wrapper/JDFInkZoneProfile.h"
#include "jdf/wrapper/JDFInsert.h"
#include "jdf/wrapper/JDFInsertList.h"
#include "jdf/wrapper/JDFInterpretedPDLData.h"
#include "jdf/wrapper/JDFIdentificationField.h"
#include "jdf/wrapper/JDFInsertSheet.h"
#include "jdf/wrapper/JDFIntegerEvaluation.h"
#include "jdf/wrapper/JDFIntegerState.h"
#include "jdf/wrapper/JDFIntentResource.h" 
#include "jdf/wrapper/JDFIsPresentEvaluation.h"

#include "jdf/wrapper/JDFJDFController.h"
#include "jdf/wrapper/JDFJDFService.h"
#include "jdf/wrapper/JDFJMF.h"
#include "jdf/wrapper/JDFJobField.h"
#include "jdf/wrapper/JDFJobPhase.h"

#include "jdf/wrapper/JDFLayout.h"
#include "jdf/wrapper/JDFLayoutElement.h"
#include "jdf/wrapper/JDFLayoutPreparationParams.h"
#include "jdf/wrapper/JDFLayerDetails.h"
#include "jdf/wrapper/JDFLayerList.h"
#include "jdf/wrapper/JDFLoc.h"
#include "jdf/wrapper/JDFLocation.h"
#include "jdf/wrapper/JDFLongFold.h"
#include "jdf/wrapper/JDFLongGlue.h"
#include "jdf/wrapper/JDFLongPerforate.h"
#include "jdf/wrapper/JDFLongSlit.h"

#include "jdf/wrapper/JDFObjectResolution.h"
#include "jdf/wrapper/JDFor.h"
#include "jdf/wrapper/JDFotherwise.h"


#include "jdf/wrapper/JDFmacro.h"
#include "jdf/wrapper/JDFMarkObject.h"
#include "jdf/wrapper/JDFMatrixEvaluation.h"
#include "jdf/wrapper/JDFMatrixState.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFMediaSource.h"
#include "jdf/wrapper/JDFMerged.h"
#include "jdf/wrapper/JDFModified.h"
#include "jdf/wrapper/JDFModulePhase.h"
#include "jdf/wrapper/JDFModuleStatus.h"
#include "jdf/wrapper/JDFMessageService.h"
#include "jdf/wrapper/JDFMessage.h"
#include "jdf/wrapper/JDFMessageElement.h"
#include "jdf/wrapper/JDFMISDetails.h"
#include "jdf/wrapper/JDFMsgFilter.h"

#include "jdf/wrapper/JDFNameEvaluation.h"
#include "jdf/wrapper/JDFNameState.h"
#include "jdf/wrapper/JDFNewJDFCmdParams.h"
#include "jdf/wrapper/JDFNewJDFQuParams.h"
#include "jdf/wrapper/JDFNode.h"
#include "jdf/wrapper/JDFNodeInfo.h"
#include "jdf/wrapper/JDFNodeInfoCmdParams.h"
#include "jdf/wrapper/JDFNodeInfoQuParams.h"
#include "jdf/wrapper/JDFNodeInfoResp.h"
#include "jdf/wrapper/JDFnot.h"
#include "jdf/wrapper/JDFNotification.h"
#include "jdf/wrapper/JDFNotificationDef.h"
#include "jdf/wrapper/JDFNotificationFilter.h"
#include "jdf/wrapper/JDFNumberEvaluation.h"
#include "jdf/wrapper/JDFNumberState.h"
#include "jdf/wrapper/JDFNumberingParam.h"
#include "jdf/wrapper/JDFNumberItem.h"

#include "jdf/wrapper/JDFOccupation.h"
#include "jdf/wrapper/JDFObservationTarget.h"

#include "jdf/wrapper/JDFPageCell.h"
#include "jdf/wrapper/JDFPageData.h"
#include "jdf/wrapper/JDFPageList.h"
#include "jdf/wrapper/JDFPallet.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFPartStatus.h"
#include "jdf/wrapper/JDFPerson.h"
#include "jdf/wrapper/JDFPhaseTime.h"
#include "jdf/wrapper/JDFPixelColorant.h"
#include "jdf/wrapper/JDFProcessRun.h"
#include "jdf/wrapper/JDFPartAmount.h"
#include "jdf/wrapper/JDFPayment.h"
#include "jdf/wrapper/JDFPDFPathEvaluation.h"
#include "jdf/wrapper/JDFPDFPathState.h"
#include "jdf/wrapper/JDFPDLResourceAlias.h"
#include "jdf/wrapper/JDFPerforate.h"
#include "jdf/wrapper/JDFPlaceHolderResource.h"
#include "jdf/wrapper/JDFPlasticCombBinding.h"
#include "jdf/wrapper/JDFPosition.h"
#include "jdf/wrapper/JDFPreflightAction.h"
#include "jdf/wrapper/JDFPreflightAnalysis.h"
#include "jdf/wrapper/JDFPreflightArgument.h"
#include "jdf/wrapper/JDFPreflightConstraint.h"
#include "jdf/wrapper/JDFPreflightConstraintsPool.h"
#include "jdf/wrapper/JDFPreflightDetail.h"
#include "jdf/wrapper/JDFPreflightInstance.h"
#include "jdf/wrapper/JDFPreflightInstanceDetail.h"
#include "jdf/wrapper/JDFPreflightInventory.h"
#include "jdf/wrapper/JDFPreflightProfile.h"
#include "jdf/wrapper/JDFPreflightReport.h"
#include "jdf/wrapper/JDFPreflightReportRulePool.h"
#include "jdf/wrapper/JDFPreflightResultsPool.h"
#include "jdf/wrapper/JDFPreflightValue.h"
#include "jdf/wrapper/JDFPRError.h"
#include "jdf/wrapper/JDFPreview.h"
#include "jdf/wrapper/JDFPRGroupOccurrence.h"
#include "jdf/wrapper/JDFPricing.h"
#include "jdf/wrapper/JDFPRItem.h"
#include "jdf/wrapper/JDFPROccurrence.h"
#include "jdf/wrapper/JDFProofItem.h"
#include "jdf/wrapper/JDFPRRule.h"
#include "jdf/wrapper/JDFPRRuleAttr.h"



#include "jdf/wrapper/JDFQualityControlResult.h"
#include "jdf/wrapper/JDFQualityMeasurement.h"
#include "jdf/wrapper/JDFQueue.h"
#include "jdf/wrapper/JDFQueueEntry.h"
#include "jdf/wrapper/JDFQueueEntryDef.h"
#include "jdf/wrapper/JDFQueueEntryDefList.h"
#include "jdf/wrapper/JDFQueueFilter.h"
#include "jdf/wrapper/JDFQuery.h"

#include "jdf/wrapper/JDFRange.h"
#include "jdf/wrapper/JDFRectangleEvaluation.h"
#include "jdf/wrapper/JDFRectangleState.h"
#include "jdf/wrapper/JDFRegisterMark.h"
#include "jdf/wrapper/JDFRemoved.h"
#include "jdf/wrapper/JDFResourceAudit.h"
#include "jdf/wrapper/JDFRefElement.h"
#include "jdf/wrapper/JDFRegisterRibbon.h"
#include "jdf/wrapper/JDFRequestQueueEntryParams.h"
#include "jdf/wrapper/JDFResourceInfo.h"
#include "jdf/wrapper/JDFResourceLink.h"
#include "jdf/wrapper/JDFResourceParam.h"
#include "jdf/wrapper/JDFResourcePullParams.h"
#include "jdf/wrapper/JDFResponse.h"
#include "jdf/wrapper/JDFResubmissionParams.h"
#include "jdf/wrapper/JDFReturnQueueEntryParams.h"
#include "jdf/wrapper/JDFRollStand.h"
#include "jdf/wrapper/JDFRingBinding.h"
#include "jdf/wrapper/JDFRunList.h"

#include "jdf/wrapper/JDFScore.h"
#include "jdf/wrapper/JDFSheet.h"
#include "jdf/wrapper/JDFSpawned.h"
#include "jdf/wrapper/JDFSurface.h"
#include "jdf/wrapper/JDFScavengerArea.h"
#include "jdf/wrapper/JDFScreenSelector.h"
#include "jdf/wrapper/JDFset.h"
#include "jdf/wrapper/JDFShapeCut.h"
#include "jdf/wrapper/JDFShapeElement.h"
#include "jdf/wrapper/JDFShapeEvaluation.h"
#include "jdf/wrapper/JDFShapeState.h"
#include "jdf/wrapper/JDFShutDownCmdParams.h"
#include "jdf/wrapper/JDFSignal.h"
#include "jdf/wrapper/JDFSignature.h"
#include "jdf/wrapper/JDFSignatureCell.h"
#include "jdf/wrapper/JDFState.h"
#include "jdf/wrapper/JDFStringEvaluation.h"
#include "jdf/wrapper/JDFStringListValue.h"
#include "jdf/wrapper/JDFStringState.h"
#include "jdf/wrapper/JDFSystemTimeSet.h"
#include "jdf/wrapper/JDFSeparationList.h"
#include "jdf/wrapper/JDFSeparationSpec.h"
#include "jdf/wrapper/JDFSaddleStitching.h"
#include "jdf/wrapper/JDFSideStitching.h"
#include "jdf/wrapper/JDFSideSewing.h"
#include "jdf/wrapper/JDFStripBinding.h"
#include "jdf/wrapper/JDFSoftCoverBinding.h"
#include "jdf/wrapper/JDFStrap.h"
#include "jdf/wrapper/JDFSubmissionMethods.h"
#include "jdf/wrapper/JDFSubscription.h"

#include "jdf/wrapper/JDFTabs.h"
#include "jdf/wrapper/JDFTape.h"
#include "jdf/wrapper/JDFTest.h"
#include "jdf/wrapper/JDFTestRef.h"
#include "jdf/wrapper/JDFThreadSealing.h"
#include "jdf/wrapper/JDFThreadSewing.h"
#include "jdf/wrapper/JDFTIFFEmbeddedFile.h"
#include "jdf/wrapper/JDFTIFFtag.h"
#include "jdf/wrapper/JDFTile.h"
#include "jdf/wrapper/JDFTool.h"
#include "jdf/wrapper/JDFTrackFilter.h"
#include "jdf/wrapper/JDFTrackResult.h"
#include "jdf/wrapper/JDFTransferCurve.h"
#include "jdf/wrapper/JDFTransferCurveSet.h"
#include "jdf/wrapper/JDFTransferFunctionControl.h"
#include "jdf/wrapper/JDFTrappingDetails.h"
#include "jdf/wrapper/JDFTrappingOrder.h"
#include "jdf/wrapper/JDFTrapRegion.h"
#include "jdf/wrapper/JDFTrigger.h"

#include "jdf/wrapper/JDFValue.h"
#include "jdf/wrapper/JDFValueLoc.h"

#include "jdf/wrapper/JDFWakeUpCmdParams.h"
#include "jdf/wrapper/JDFwhen.h"
#include "jdf/wrapper/JDFWireCombBinding.h"

#include "jdf/wrapper/JDFxor.h"
#include "jdf/wrapper/JDFXYPairEvaluation.h"
#include "jdf/wrapper/JDFXYPairState.h"
//

#include "jdf/wrapper/JDFArtDeliveryIntent.h"
#include "jdf/wrapper/JDFBindingIntent.h"
#include "jdf/wrapper/JDFColorIntent.h"
#include "jdf/wrapper/JDFDeliveryIntent.h"
#include "jdf/wrapper/JDFDropIntent.h"
#include "jdf/wrapper/JDFEmbossingIntent.h"
#include "jdf/wrapper/JDFDropItemIntent.h"
#include "jdf/wrapper/JDFFoldingIntent.h"
#include "jdf/wrapper/JDFHoleMakingIntent.h"
#include "jdf/wrapper/JDFInsertingIntent.h"
#include "jdf/wrapper/JDFLaminatingIntent.h"
#include "jdf/wrapper/JDFLayoutIntent.h"
#include "jdf/wrapper/JDFMediaIntent.h"
#include "jdf/wrapper/JDFNumberingIntent.h"
#include "jdf/wrapper/JDFProductionIntent.h"
#include "jdf/wrapper/JDFProofingIntent.h"
#include "jdf/wrapper/JDFShapeCuttingIntent.h"
#include "jdf/wrapper/JDFScreeningIntent.h"
#include "jdf/wrapper/JDFPackingIntent.h"
#include "jdf/wrapper/JDFSizeIntent.h"

#include "jdf/wrapper/JDFPool.h"
#include "jdf/wrapper/JDFAncestorPool.h"
#include "jdf/wrapper/JDFAuditPool.h"
#include "jdf/wrapper/JDFAmountPool.h"
#include "jdf/wrapper/JDFColorPool.h"
#include "jdf/wrapper/JDFTransferCurvePool.h"
#include "jdf/wrapper/JDFResourcePool.h"
#include "jdf/wrapper/JDFResourceLinkPool.h"
#include "jdf/wrapper/JDFStatusPool.h"



#include "jdf/wrapper/JDFFactory.h"
#include "jdf/wrapper/JDFElement.h"
#include "jdf/wrapper/JDFAdhesiveBindingParams.h"
#include "jdf/wrapper/JDFAdvancedParams.h"
#include "jdf/wrapper/JDFApprovalParams.h"
#include "jdf/wrapper/JDFAssetListCreationParams.h"
#include "jdf/wrapper/JDFAutomatedOverPrintParams.h"

#include "jdf/wrapper/JDFBindingQualityParams.h"
#include "jdf/wrapper/JDFBlockPreparationParams.h"
#include "jdf/wrapper/JDFBoxPackingParams.h"
#include "jdf/wrapper/JDFBufferParams.h"
#include "jdf/wrapper/JDFBundlingParams.h"

#include "jdf/wrapper/JDFCaseMakingParams.h"
#include "jdf/wrapper/JDFCasingInParams.h"
#include "jdf/wrapper/JDFCCITTFaxParams.h"
#include "jdf/wrapper/JDFChannelBindingParams.h"
#include "jdf/wrapper/JDFCoilBindingParams.h"
#include "jdf/wrapper/JDFCollectingParams.h"
#include "jdf/wrapper/JDFColorCorrectionParams.h"
#include "jdf/wrapper/JDFColorSpaceConversionParams.h"
#include "jdf/wrapper/JDFContactCopyParams.h"
#include "jdf/wrapper/JDFConventionalPrintingParams.h"
#include "jdf/wrapper/JDFCoverApplicationParams.h"
#include "jdf/wrapper/JDFCreasingParams.h"
#include "jdf/wrapper/JDFCuttingParams.h"

#include "jdf/wrapper/JDFDBMergeParams.h"
#include "jdf/wrapper/JDFDCTParams.h"
#include "jdf/wrapper/JDFDeliveryParams.h"
#include "jdf/wrapper/JDFDevelopingParams.h"
#include "jdf/wrapper/JDFDigitalDeliveryParams.h"
#include "jdf/wrapper/JDFDigitalPrintingParams.h"
#include "jdf/wrapper/JDFDividingParams.h"

#include "jdf/wrapper/JDFElementColorParams.h"
#include "jdf/wrapper/JDFEmbossingParams.h"
#include "jdf/wrapper/JDFEndSheetGluingParams.h"

#include "jdf/wrapper/JDFFeederQualityParams.h"
#include "jdf/wrapper/JDFFeedingParams.h"
#include "jdf/wrapper/JDFFlateParams.h"
#include "jdf/wrapper/JDFFoldingParams.h"
#include "jdf/wrapper/JDFFontParams.h"
#include "jdf/wrapper/JDFFormatConversionParams.h"

#include "jdf/wrapper/JDFGatheringParams.h"
#include "jdf/wrapper/JDFGluingParams.h"

#include "jdf/wrapper/JDFHeadBandApplicationParams.h"
#include "jdf/wrapper/JDFHoleMakingParams.h"

#include "jdf/wrapper/JDFIDPrintingParams.h"
#include "jdf/wrapper/JDFImageCompressionParams.h"
#include "jdf/wrapper/JDFImageReplacementParams.h"
#include "jdf/wrapper/JDFImageSetterParams.h"
#include "jdf/wrapper/JDFInkZoneCalculationParams.h"
#include "jdf/wrapper/JDFInsertingParams.h"
#include "jdf/wrapper/JDFInterpretingParams.h"

#include "jdf/wrapper/JDFJacketingParams.h"

#include "jdf/wrapper/JDFKnownMsgQuParams.h"

#include "jdf/wrapper/JDFLabelingParams.h"
#include "jdf/wrapper/JDFLaminatingParams.h"
#include "jdf/wrapper/JDFLongitudinalRibbonOperationParams.h"
#include "jdf/wrapper/JDFLZWParams.h"

#include "jdf/wrapper/JDFManualLaborParams.h"

#include "jdf/wrapper/JDFNumberingParams.h"

#include "jdf/wrapper/JDFOrderingParams.h"

#include "jdf/wrapper/JDFPackingParams.h"
#include "jdf/wrapper/JDFPalletizingParams.h"
#include "jdf/wrapper/JDFPDFInterpretingParams.h"
#include "jdf/wrapper/JDFPDFToPSConversionParams.h"
#include "jdf/wrapper/JDFPDFXParams.h"
#include "jdf/wrapper/JDFPerforatingParams.h"
#include "jdf/wrapper/JDFPlasticCombBindingParams.h"
#include "jdf/wrapper/JDFPlateCopyParams.h"
#include "jdf/wrapper/JDFPreviewGenerationParams.h"
#include "jdf/wrapper/JDFPrintRollingParams.h"
#include "jdf/wrapper/JDFProofingParams.h"
#include "jdf/wrapper/JDFPSToPDFConversionParams.h"
#include "jdf/wrapper/JDFPipeParams.h"

#include "jdf/wrapper/JDFQualityControlParams.h"
#include "jdf/wrapper/JDFQueueEntryPosParams.h"
#include "jdf/wrapper/JDFQueueEntryPriParams.h"
#include "jdf/wrapper/JDFQueueSubmissionParams.h"


#include "jdf/wrapper/JDFRenderingParams.h"
#include "jdf/wrapper/JDFResourceCmdParams.h"
#include "jdf/wrapper/JDFResourceQuParams.h"
#include "jdf/wrapper/JDFResubmissionParams.h"

#include "jdf/wrapper/JDFResourceDefinitionParams.h"
#include "jdf/wrapper/JDFRingBindingParams.h"

#include "jdf/wrapper/JDFSaddleStitchingParams.h"
#include "jdf/wrapper/JDFScanParams.h"
#include "jdf/wrapper/JDFScreeningParams.h"
#include "jdf/wrapper/JDFSeparationControlParams.h"
#include "jdf/wrapper/JDFSeparationList.h"
#include "jdf/wrapper/JDFShapeCuttingParams.h"
#include "jdf/wrapper/JDFShrinkingParams.h"
#include "jdf/wrapper/JDFSideSewingParams.h"
#include "jdf/wrapper/JDFSpinePreparationParams.h"
#include "jdf/wrapper/JDFSpineTapingParams.h"
#include "jdf/wrapper/JDFStackingParams.h"
#include "jdf/wrapper/JDFStopPersChParams.h"
#include "jdf/wrapper/JDFStatusQuParams.h"
#include "jdf/wrapper/JDFStrappingParams.h"
#include "jdf/wrapper/JDFStitchingParams.h"
#include "jdf/wrapper/JDFStripBindingParams.h"
#include "jdf/wrapper/JDFStripCellParams.h"
#include "jdf/wrapper/JDFStrippingParams.h"

#include "jdf/wrapper/JDFTIFFFormatParams.h"
#include "jdf/wrapper/JDFThinPDFParams.h"
#include "jdf/wrapper/JDFThreadSealingParams.h"
#include "jdf/wrapper/JDFThreadSewingParams.h"
#include "jdf/wrapper/JDFTrappingParams.h"
#include "jdf/wrapper/JDFTrimmingParams.h"

#include "jdf/wrapper/JDFVerificationParams.h"

#include "jdf/wrapper/JDFWireCombBindingParams.h"
#include "jdf/wrapper/JDFWrappingParams.h"


#include "jdf/wrapper/JDFElement.h"
