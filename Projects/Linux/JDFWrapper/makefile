########################################
#
# Makefile for JDFWrapperLib
#
# TBD: (1) static lib in release version
#
########################################

LIBNAME = JDFWrapperLib

DLIB_MAJ_NR = 0
DLIB_MIN_NR = 0
DLIB_REL_NR = 0

INSTPATH = ../../../Build/Linux/$(LIBNAME)
SRCPATH = ../../../src/jdf
OBJPATH = ../../../Build/Linux/obj


INCLUDES = -I../../../external/stlport/stlport -I../../../src -I../../../src/jdf -I../../../src/jdf/wrappercore -I../../../external/xerces/src/xercesc -I../../../external/xerces/src -I../../../src/jdf/wrapper -I../../../src/jdf/wrapper/AutoJDF -DPROJ_JDFTOOLSLIB

##########################################
OPTIONS = -O -Wno-non-template-friend -w -DTYPESAFE

STATLIB := lib$(LIBNAME).a

OPTS = $(OPTIONS)
LIBOUT = $(STATLIB)

CPP = g++

##########################################

OBJS =  $(OBJPATH)/JDFAutoAcknowledge.o \
	$(OBJPATH)/JDFAutoAdded.o \
	$(OBJPATH)/JDFAutoAddress.o \
	$(OBJPATH)/JDFAutoAdhesiveBinding.o \
	$(OBJPATH)/JDFAutoAdhesiveBindingParams.o \
	$(OBJPATH)/JDFAutoAdvancedParams.o \
	$(OBJPATH)/JDFAutoAmountPool.o \
	$(OBJPATH)/JDFAutoAncestor.o \
	$(OBJPATH)/JDFAutoAncestorPool.o \
	$(OBJPATH)/JDFAutoApprovalParams.o \
	$(OBJPATH)/JDFAutoApprovalPerson.o \
	$(OBJPATH)/JDFAutoApprovalSuccess.o \
	$(OBJPATH)/JDFAutoArtDelivery.o \
	$(OBJPATH)/JDFAutoArtDeliveryIntent.o \
	$(OBJPATH)/JDFAutoAutomatedOverprintParams.o \
	$(OBJPATH)/JDFAutoBackPreparation.o \
	$(OBJPATH)/JDFAutoBand.o \
	$(OBJPATH)/JDFAutoBarcode.o \
	$(OBJPATH)/JDFAutoBindItem.o \
	$(OBJPATH)/JDFAutoBindList.o \
	$(OBJPATH)/JDFAutoBindingIntent.o \
	$(OBJPATH)/JDFAutoBlockPreparationParams.o \
	$(OBJPATH)/JDFAutoBookCase.o \
	$(OBJPATH)/JDFAutoBoxPackingParams.o \
	$(OBJPATH)/JDFAutoBufferParams.o \
	$(OBJPATH)/JDFAutoBundle.o \
	$(OBJPATH)/JDFAutoBundleItem.o \
	$(OBJPATH)/JDFAutoBusinessInfo.o \
	$(OBJPATH)/JDFAutoByteMap.o \
	$(OBJPATH)/JDFAutoCIELABMeasuringField.o \
	$(OBJPATH)/JDFAutoCaseMakingParams.o \
	$(OBJPATH)/JDFAutoCasingInParams.o \
	$(OBJPATH)/JDFAutoChangedAttribute.o \
	$(OBJPATH)/JDFAutoChannelBinding.o \
	$(OBJPATH)/JDFAutoChannelBindingParams.o \
	$(OBJPATH)/JDFAutoCoilBinding.o \
	$(OBJPATH)/JDFAutoCoilBindingParams.o \
	$(OBJPATH)/JDFAutoCollectingParams.o \
	$(OBJPATH)/JDFAutoColor.o \
	$(OBJPATH)/JDFAutoColorControlStrip.o \
	$(OBJPATH)/JDFAutoColorCorrectionOp.o \
	$(OBJPATH)/JDFAutoColorCorrectionParams.o \
	$(OBJPATH)/JDFAutoColorIntent.o \
	$(OBJPATH)/JDFAutoColorMeasurementConditions.o \
	$(OBJPATH)/JDFAutoColorPool.o \
	$(OBJPATH)/JDFAutoColorSpaceConversionOp.o \
	$(OBJPATH)/JDFAutoColorSpaceConversionParams.o \
	$(OBJPATH)/JDFAutoColorSpaceSubstitute.o \
	$(OBJPATH)/JDFAutoColorantAlias.o \
	$(OBJPATH)/JDFAutoColorantControl.o \
	$(OBJPATH)/JDFAutoColorantZoneDetails.o \
	$(OBJPATH)/JDFAutoComChannel.o \
	$(OBJPATH)/JDFAutoCommand.o \
	$(OBJPATH)/JDFAutoComment.o \
	$(OBJPATH)/JDFAutoCompany.o \
	$(OBJPATH)/JDFAutoComponent.o \
	$(OBJPATH)/JDFAutoContact.o \
	$(OBJPATH)/JDFAutoContactCopyParams.o \
	$(OBJPATH)/JDFAutoContentObject.o \
	$(OBJPATH)/JDFAutoConventionalPrintingParams.o \
	$(OBJPATH)/JDFAutoCostCenter.o \
	$(OBJPATH)/JDFAutoCounterReset.o \
	$(OBJPATH)/JDFAutoCoverApplicationParams.o \
	$(OBJPATH)/JDFAutoCrease.o \
	$(OBJPATH)/JDFAutoCreasingParams.o \
	$(OBJPATH)/JDFAutoCreated.o \
	$(OBJPATH)/JDFAutoCreditCard.o \
	$(OBJPATH)/JDFAutoCustomerInfo.o \
	$(OBJPATH)/JDFAutoCut.o \
	$(OBJPATH)/JDFAutoCutBlock.o \
	$(OBJPATH)/JDFAutoCutMark.o \
	$(OBJPATH)/JDFAutoCuttingParams.o \
	$(OBJPATH)/JDFAutoDBMergeParams.o \
	$(OBJPATH)/JDFAutoDBRules.o \
	$(OBJPATH)/JDFAutoDBSchema.o \
	$(OBJPATH)/JDFAutoDBSelection.o \
	$(OBJPATH)/JDFAutoDeliveryIntent.o \
	$(OBJPATH)/JDFAutoDeliveryParams.o \
	$(OBJPATH)/JDFAutoDensityMeasuringField.o \
	$(OBJPATH)/JDFAutoDevCaps.o \
	$(OBJPATH)/JDFAutoDevelopingParams.o \
	$(OBJPATH)/JDFAutoDevice.o \
	$(OBJPATH)/JDFAutoDeviceFilter.o \
	$(OBJPATH)/JDFAutoDeviceInfo.o \
	$(OBJPATH)/JDFAutoDeviceList.o \
	$(OBJPATH)/JDFAutoDeviceMark.o \
	$(OBJPATH)/JDFAutoDeviceNColor.o \
	$(OBJPATH)/JDFAutoDeviceNSpace.o \
	$(OBJPATH)/JDFAutoDigitalPrintingParams.o \
	$(OBJPATH)/JDFAutoDisjointing.o \
	$(OBJPATH)/JDFAutoDividingParams.o \
	$(OBJPATH)/JDFAutoDrop.o \
	$(OBJPATH)/JDFAutoDropIntent.o \
	$(OBJPATH)/JDFAutoDropItem.o \
	$(OBJPATH)/JDFAutoDropItemIntent.o \
	$(OBJPATH)/JDFAutoDynamicField.o \
	$(OBJPATH)/JDFAutoDynamicInput.o \
	$(OBJPATH)/JDFAutoEdgeGluing.o \
	$(OBJPATH)/JDFAutoEmboss.o \
	$(OBJPATH)/JDFAutoEmbossingIntent.o \
	$(OBJPATH)/JDFAutoEmbossingItem.o \
	$(OBJPATH)/JDFAutoEmbossingParams.o \
	$(OBJPATH)/JDFAutoEmployee.o \
	$(OBJPATH)/JDFAutoEmployeeDef.o \
	$(OBJPATH)/JDFAutoEndSheet.o \
	$(OBJPATH)/JDFAutoEndSheetGluingParams.o \
	$(OBJPATH)/JDFAutoEnumerationSpan.o \
	$(OBJPATH)/JDFAutoError.o \
	$(OBJPATH)/JDFAutoExposedMedia.o \
	$(OBJPATH)/JDFAutoFCNKey.o \
	$(OBJPATH)/JDFAutoFileAlias.o \
	$(OBJPATH)/JDFAutoFileSpec.o \
	$(OBJPATH)/JDFAutoFitPolicy.o \
	$(OBJPATH)/JDFAutoFold.o \
	$(OBJPATH)/JDFAutoFoldingIntent.o \
	$(OBJPATH)/JDFAutoFoldingParams.o \
	$(OBJPATH)/JDFAutoFontParams.o \
	$(OBJPATH)/JDFAutoFontPolicy.o \
	$(OBJPATH)/JDFAutoFormatConversionParams.o \
	$(OBJPATH)/JDFAutoGatheringParams.o \
	$(OBJPATH)/JDFAutoGlue.o \
	$(OBJPATH)/JDFAutoGlueApplication.o \
	$(OBJPATH)/JDFAutoGlueLine.o \
	$(OBJPATH)/JDFAutoGluingParams.o \
	$(OBJPATH)/JDFAutoHardCoverBinding.o \
	$(OBJPATH)/JDFAutoHeadBandApplicationParams.o \
	$(OBJPATH)/JDFAutoHole.o \
	$(OBJPATH)/JDFAutoHoleLine.o \
	$(OBJPATH)/JDFAutoHoleList.o \
	$(OBJPATH)/JDFAutoHoleMakingIntent.o \
	$(OBJPATH)/JDFAutoHoleMakingParams.o \
	$(OBJPATH)/JDFAutoIDPCover.o \
	$(OBJPATH)/JDFAutoIDPFinishing.o \
	$(OBJPATH)/JDFAutoIDPFolding.o \
	$(OBJPATH)/JDFAutoIDPHoleMaking.o \
	$(OBJPATH)/JDFAutoIDPImageShift.o \
	$(OBJPATH)/JDFAutoIDPJobSheet.o \
	$(OBJPATH)/JDFAutoIDPLayout.o \
	$(OBJPATH)/JDFAutoIDPStitching.o \
	$(OBJPATH)/JDFAutoIDPTrimming.o \
	$(OBJPATH)/JDFAutoIDPrintingParams.o \
	$(OBJPATH)/JDFAutoIcon.o \
	$(OBJPATH)/JDFAutoIconList.o \
	$(OBJPATH)/JDFAutoIdentificationField.o \
	$(OBJPATH)/JDFAutoImageCompression.o \
	$(OBJPATH)/JDFAutoImageCompressionParams.o \
	$(OBJPATH)/JDFAutoImageReplacementParams.o \
	$(OBJPATH)/JDFAutoImageSetterParams.o \
	$(OBJPATH)/JDFAutoImageShift.o \
	$(OBJPATH)/JDFAutoInk.o \
	$(OBJPATH)/JDFAutoInkZoneCalculationParams.o \
	$(OBJPATH)/JDFAutoInkZoneProfile.o \
	$(OBJPATH)/JDFAutoInsert.o \
	$(OBJPATH)/JDFAutoInsertList.o \
	$(OBJPATH)/JDFAutoInsertSheet.o \
	$(OBJPATH)/JDFAutoInsertingIntent.o \
	$(OBJPATH)/JDFAutoInsertingParams.o \
	$(OBJPATH)/JDFAutoInterpretedPDLData.o \
	$(OBJPATH)/JDFAutoInterpretingParams.o \
	$(OBJPATH)/JDFAutoJDFController.o \
	$(OBJPATH)/JDFAutoJDFService.o \
	$(OBJPATH)/JDFAutoJMF.o \
	$(OBJPATH)/JDFAutoJacketingParams.o \
	$(OBJPATH)/JDFAutoJobField.o \
	$(OBJPATH)/JDFAutoJobPhase.o \
	$(OBJPATH)/JDFAutoKnownMsgQuParams.o \
	$(OBJPATH)/JDFAutoLabelingParams.o \
	$(OBJPATH)/JDFAutoLaminatingIntent.o \
	$(OBJPATH)/JDFAutoLaminatingParams.o \
	$(OBJPATH)/JDFAutoLayerDetails.o \
	$(OBJPATH)/JDFAutoLayerList.o \
	$(OBJPATH)/JDFAutoLayout.o \
	$(OBJPATH)/JDFAutoLayoutElement.o \
	$(OBJPATH)/JDFAutoLayoutIntent.o \
	$(OBJPATH)/JDFAutoLayoutPreparationParams.o \
	$(OBJPATH)/JDFAutoLocation.o \
	$(OBJPATH)/JDFAutoLongFold.o \
	$(OBJPATH)/JDFAutoLongGlue.o \
	$(OBJPATH)/JDFAutoLongPerforate.o \
	$(OBJPATH)/JDFAutoLongSlit.o \
	$(OBJPATH)/JDFAutoLongitudinalRibbonOperationParams.o \
	$(OBJPATH)/JDFAutoManualLaborParams.o \
	$(OBJPATH)/JDFAutoMarkObject.o \
	$(OBJPATH)/JDFAutoMedia.o \
	$(OBJPATH)/JDFAutoMediaIntent.o \
	$(OBJPATH)/JDFAutoMediaSource.o \
	$(OBJPATH)/JDFAutoMerged.o \
	$(OBJPATH)/JDFAutoMessage.o \
	$(OBJPATH)/JDFAutoMessageService.o \
	$(OBJPATH)/JDFAutoModified.o \
	$(OBJPATH)/JDFAutoModulePhase.o \
	$(OBJPATH)/JDFAutoModuleStatus.o \
	$(OBJPATH)/JDFAutoMsgFilter.o \
	$(OBJPATH)/JDFAutoNodeAdhesiveBinding.o \
	$(OBJPATH)/JDFAutoNodeBlockPreparation.o \
	$(OBJPATH)/JDFAutoNodeBoxPacking.o \
	$(OBJPATH)/JDFAutoNodeCaseMaking.o \
	$(OBJPATH)/JDFAutoNodeCasingIn.o \
	$(OBJPATH)/JDFAutoNodeChannelBinding.o \
	$(OBJPATH)/JDFAutoNodeCoilBinding.o \
	$(OBJPATH)/JDFAutoNodeCollecting.o \
	$(OBJPATH)/JDFAutoNodeColorCorrection.o \
	$(OBJPATH)/JDFAutoNodeColorSpaceConversion.o \
	$(OBJPATH)/JDFAutoNodeContactCopying.o \
	$(OBJPATH)/JDFAutoNodeContoneCalibration.o \
	$(OBJPATH)/JDFAutoNodeConventionalPrinting.o \
	$(OBJPATH)/JDFAutoNodeCoverApplication.o \
	$(OBJPATH)/JDFAutoNodeCutting.o \
	$(OBJPATH)/JDFAutoNodeDBDocTemplateLayout.o \
	$(OBJPATH)/JDFAutoNodeDBTemplateMerging.o \
	$(OBJPATH)/JDFAutoNodeDigitalPrinting.o \
	$(OBJPATH)/JDFAutoNodeDividing.o \
	$(OBJPATH)/JDFAutoNodeEmbossing.o \
	$(OBJPATH)/JDFAutoNodeEndSheetGluing.o \
	$(OBJPATH)/JDFAutoNodeFilmToPlateCopying.o \
	$(OBJPATH)/JDFAutoNodeFolding.o \
	$(OBJPATH)/JDFAutoNodeFormatConversion.o \
	$(OBJPATH)/JDFAutoNodeGathering.o \
	$(OBJPATH)/JDFAutoNodeGluing.o \
	$(OBJPATH)/JDFAutoNodeHeadBandApplication.o \
	$(OBJPATH)/JDFAutoNodeHoleMaking.o \
	$(OBJPATH)/JDFAutoNodeIDPrinting.o \
	$(OBJPATH)/JDFAutoNodeImageReplacement.o \
	$(OBJPATH)/JDFAutoNodeImageSetting.o \
	$(OBJPATH)/JDFAutoNodeImposition.o \
	$(OBJPATH)/JDFAutoNodeInfo.o \
	$(OBJPATH)/JDFAutoNodeInkZoneCalculation.o \
	$(OBJPATH)/JDFAutoNodeInserting.o \
	$(OBJPATH)/JDFAutoNodeInterpreting.o \
	$(OBJPATH)/JDFAutoNodeJacketing.o \
	$(OBJPATH)/JDFAutoNodeLabeling.o \
	$(OBJPATH)/JDFAutoNodeLaminating.o \
	$(OBJPATH)/JDFAutoNodeLayoutElementProduction.o \
	$(OBJPATH)/JDFAutoNodeLayoutPreparation.o \
	$(OBJPATH)/JDFAutoNodeLongitudinalRibbonOperations.o \
	$(OBJPATH)/JDFAutoNodeNumbering.o \
	$(OBJPATH)/JDFAutoNodePDFToPSConversion.o \
	$(OBJPATH)/JDFAutoNodePSToPDFConversion.o \
	$(OBJPATH)/JDFAutoNodePalletizing.o \
	$(OBJPATH)/JDFAutoNodePlasticCombBinding.o \
	$(OBJPATH)/JDFAutoNodePreflight.o \
	$(OBJPATH)/JDFAutoNodePreviewGeneration.o \
	$(OBJPATH)/JDFAutoNodeProduct.o \
	$(OBJPATH)/JDFAutoNodeProofing.o \
	$(OBJPATH)/JDFAutoNodeRendering.o \
	$(OBJPATH)/JDFAutoNodeRingBinding.o \
	$(OBJPATH)/JDFAutoNodeSaddleStitching.o \
	$(OBJPATH)/JDFAutoNodeScanning.o \
	$(OBJPATH)/JDFAutoNodeScreening.o \
	$(OBJPATH)/JDFAutoNodeSeparation.o \
	$(OBJPATH)/JDFAutoNodeShapeCutting.o \
	$(OBJPATH)/JDFAutoNodeShrinking.o \
	$(OBJPATH)/JDFAutoNodeSideSewing.o \
	$(OBJPATH)/JDFAutoNodeSoftProofing.o \
	$(OBJPATH)/JDFAutoNodeSpinePreparation.o \
	$(OBJPATH)/JDFAutoNodeSpineTaping.o \
	$(OBJPATH)/JDFAutoNodeStacking.o \
	$(OBJPATH)/JDFAutoNodeStitching.o \
	$(OBJPATH)/JDFAutoNodeStrapping.o \
	$(OBJPATH)/JDFAutoNodeThreadSealing.o \
	$(OBJPATH)/JDFAutoNodeThreadSewing.o \
	$(OBJPATH)/JDFAutoNodeTiling.o \
	$(OBJPATH)/JDFAutoNodeTrapping.o \
	$(OBJPATH)/JDFAutoNodeTrimming.o \
	$(OBJPATH)/JDFAutoNodeWireCombBinding.o \
	$(OBJPATH)/JDFAutoNodeWrapping.o \
	$(OBJPATH)/JDFAutoNotification.o \
	$(OBJPATH)/JDFAutoNotificationDef.o \
	$(OBJPATH)/JDFAutoNotificationFilter.o \
	$(OBJPATH)/JDFAutoNumberItem.o \
	$(OBJPATH)/JDFAutoNumberingIntent.o \
	$(OBJPATH)/JDFAutoNumberingParam.o \
	$(OBJPATH)/JDFAutoNumberingParams.o \
	$(OBJPATH)/JDFAutoObjectResolution.o \
	$(OBJPATH)/JDFAutoObservationTarget.o \
	$(OBJPATH)/JDFAutoOccupation.o \
	$(OBJPATH)/JDFAutoOrderingParams.o \
	$(OBJPATH)/JDFAutoPDFInterpretingParams.o \
	$(OBJPATH)/JDFAutoPDFToPSConversionParams.o \
	$(OBJPATH)/JDFAutoPDLResourceAlias.o \
	$(OBJPATH)/JDFAutoPSToPDFConversionParams.o \
	$(OBJPATH)/JDFAutoPackingIntent.o \
	$(OBJPATH)/JDFAutoPackingParams.o \
	$(OBJPATH)/JDFAutoPageCell.o \
	$(OBJPATH)/JDFAutoPallet.o \
	$(OBJPATH)/JDFAutoPalletizingParams.o \
	$(OBJPATH)/JDFAutoPart.o \
	$(OBJPATH)/JDFAutoPartAmount.o \
	$(OBJPATH)/JDFAutoPartStatus.o \
	$(OBJPATH)/JDFAutoPayment.o \
	$(OBJPATH)/JDFAutoPerforate.o \
	$(OBJPATH)/JDFAutoPerforatingParams.o \
	$(OBJPATH)/JDFAutoPerson.o \
	$(OBJPATH)/JDFAutoPhaseTime.o \
	$(OBJPATH)/JDFAutoPipeParams.o \
	$(OBJPATH)/JDFAutoPixelColorant.o \
	$(OBJPATH)/JDFAutoPlaceHolder.o \
	$(OBJPATH)/JDFAutoPlasticCombBinding.o \
	$(OBJPATH)/JDFAutoPlasticCombBindingParams.o \
	$(OBJPATH)/JDFAutoPlateCopyParams.o \
	$(OBJPATH)/JDFAutoPreflightAnalysis.o \
	$(OBJPATH)/JDFAutoPreflightConstraint.o \
	$(OBJPATH)/JDFAutoPreflightDetail.o \
	$(OBJPATH)/JDFAutoPreflightInstance.o \
	$(OBJPATH)/JDFAutoPreflightInstanceDetail.o \
	$(OBJPATH)/JDFAutoPreflightInventory.o \
	$(OBJPATH)/JDFAutoPreflightProfile.o \
	$(OBJPATH)/JDFAutoPreview.o \
	$(OBJPATH)/JDFAutoPreviewGenerationParams.o \
	$(OBJPATH)/JDFAutoPricing.o \
	$(OBJPATH)/JDFAutoProcessRun.o \
	$(OBJPATH)/JDFAutoProductionIntent.o \
	$(OBJPATH)/JDFAutoProofItem.o \
	$(OBJPATH)/JDFAutoProofingIntent.o \
	$(OBJPATH)/JDFAutoProofingParams.o \
	$(OBJPATH)/JDFAutoProperties.o \
	$(OBJPATH)/JDFAutoQuery.o \
	$(OBJPATH)/JDFAutoQueue.o \
	$(OBJPATH)/JDFAutoQueueEntry.o \
	$(OBJPATH)/JDFAutoQueueEntryDef.o \
	$(OBJPATH)/JDFAutoQueueEntryPosParams.o \
	$(OBJPATH)/JDFAutoQueueEntryPriParams.o \
	$(OBJPATH)/JDFAutoQueueSubmissionParams.o \
	$(OBJPATH)/JDFAutoRegisterMark.o \
	$(OBJPATH)/JDFAutoRegisterRibbon.o \
	$(OBJPATH)/JDFAutoRemoved.o \
	$(OBJPATH)/JDFAutoRenderingParams.o \
	$(OBJPATH)/JDFAutoResourceAudit.o \
	$(OBJPATH)/JDFAutoResourceCmdParams.o \
	$(OBJPATH)/JDFAutoResourceDefinitionParams.o \
	$(OBJPATH)/JDFAutoResourceInfo.o \
	$(OBJPATH)/JDFAutoResourceParam.o \
	$(OBJPATH)/JDFAutoResourceQuParams.o \
	$(OBJPATH)/JDFAutoResponse.o \
	$(OBJPATH)/JDFAutoResubmissionParams.o \
	$(OBJPATH)/JDFAutoRingBinding.o \
	$(OBJPATH)/JDFAutoRingBindingParams.o \
	$(OBJPATH)/JDFAutoRunList.o \
	$(OBJPATH)/JDFAutoSaddleStitching.o \
	$(OBJPATH)/JDFAutoSaddleStitchingParams.o \
	$(OBJPATH)/JDFAutoScanParams.o \
	$(OBJPATH)/JDFAutoScavengerArea.o \
	$(OBJPATH)/JDFAutoScore.o \
	$(OBJPATH)/JDFAutoScreenSelector.o \
	$(OBJPATH)/JDFAutoScreeningParams.o \
	$(OBJPATH)/JDFAutoSeparationControlParams.o \
	$(OBJPATH)/JDFAutoSeparationSpec.o \
	$(OBJPATH)/JDFAutoShapeCut.o \
	$(OBJPATH)/JDFAutoShapeCuttingIntent.o \
	$(OBJPATH)/JDFAutoShapeCuttingParams.o \
	$(OBJPATH)/JDFAutoShapeElement.o \
	$(OBJPATH)/JDFAutoSheet.o \
	$(OBJPATH)/JDFAutoShrinkingParams.o \
	$(OBJPATH)/JDFAutoSideSewing.o \
	$(OBJPATH)/JDFAutoSideSewingParams.o \
	$(OBJPATH)/JDFAutoSideStitching.o \
	$(OBJPATH)/JDFAutoSignal.o \
	$(OBJPATH)/JDFAutoSignature.o \
	$(OBJPATH)/JDFAutoSizeIntent.o \
	$(OBJPATH)/JDFAutoSoftCoverBinding.o \
	$(OBJPATH)/JDFAutoSpawned.o \
	$(OBJPATH)/JDFAutoSpinePreparationParams.o \
	$(OBJPATH)/JDFAutoSpineTaping.o \
	$(OBJPATH)/JDFAutoSpineTapingParams.o \
	$(OBJPATH)/JDFAutoStackingParams.o \
	$(OBJPATH)/JDFAutoStatusPool.o \
	$(OBJPATH)/JDFAutoStatusQuParams.o \
	$(OBJPATH)/JDFAutoStitchingParams.o \
	$(OBJPATH)/JDFAutoStopPersChParams.o \
	$(OBJPATH)/JDFAutoStrap.o \
	$(OBJPATH)/JDFAutoStrappingParams.o \
	$(OBJPATH)/JDFAutoStripBinding.o \
	$(OBJPATH)/JDFAutoStripBindingParams.o \
	$(OBJPATH)/JDFAutoSubmissionMethods.o \
	$(OBJPATH)/JDFAutoSubscription.o \
	$(OBJPATH)/JDFAutoSurface.o \
	$(OBJPATH)/JDFAutoSystemTimeSet.o \
	$(OBJPATH)/JDFAutoTabs.o \
	$(OBJPATH)/JDFAutoTape.o \
	$(OBJPATH)/JDFAutoThinPDFParams.o \
	$(OBJPATH)/JDFAutoThreadSealing.o \
	$(OBJPATH)/JDFAutoThreadSealingParams.o \
	$(OBJPATH)/JDFAutoThreadSewing.o \
	$(OBJPATH)/JDFAutoThreadSewingParams.o \
	$(OBJPATH)/JDFAutoTile.o \
	$(OBJPATH)/JDFAutoTool.o \
	$(OBJPATH)/JDFAutoTrackFilter.o \
	$(OBJPATH)/JDFAutoTrackResult.o \
	$(OBJPATH)/JDFAutoTransferCurve.o \
	$(OBJPATH)/JDFAutoTransferCurvePool.o \
	$(OBJPATH)/JDFAutoTransferCurveSet.o \
	$(OBJPATH)/JDFAutoTransferFunctionControl.o \
	$(OBJPATH)/JDFAutoTrapRegion.o \
	$(OBJPATH)/JDFAutoTrappingDetails.o \
	$(OBJPATH)/JDFAutoTrappingOrder.o \
	$(OBJPATH)/JDFAutoTrappingParams.o \
	$(OBJPATH)/JDFAutoTrigger.o \
	$(OBJPATH)/JDFAutoTrimmingParams.o \
	$(OBJPATH)/JDFAutoVerificationParams.o \
	$(OBJPATH)/JDFAutoWireCombBinding.o \
	$(OBJPATH)/JDFAutoWireCombBindingParams.o \
	$(OBJPATH)/JDFAutoWrappingParams.o \
	$(OBJPATH)/JDFAcknowledge.o \
	$(OBJPATH)/JDFAdded.o \
	$(OBJPATH)/JDFAddress.o \
	$(OBJPATH)/JDFAdhesiveBinding.o \
	$(OBJPATH)/JDFAdhesiveBindingParams.o \
	$(OBJPATH)/JDFAdvancedParams.o \
	$(OBJPATH)/JDFAmountPool.o \
	$(OBJPATH)/JDFAncestor.o \
	$(OBJPATH)/JDFAncestorPool.o \
	$(OBJPATH)/JDFApprovalParams.o \
	$(OBJPATH)/JDFApprovalPerson.o \
	$(OBJPATH)/JDFApprovalSuccess.o \
	$(OBJPATH)/JDFArtDelivery.o \
	$(OBJPATH)/JDFArtDeliveryIntent.o \
	$(OBJPATH)/JDFAudit.o \
	$(OBJPATH)/JDFAuditPool.o \
	$(OBJPATH)/JDFAutomatedOverprintParams.o \
	$(OBJPATH)/JDFBackPreparation.o \
	$(OBJPATH)/JDFBand.o \
	$(OBJPATH)/JDFBarcode.o \
	$(OBJPATH)/JDFBindItem.o \
	$(OBJPATH)/JDFBindList.o \
	$(OBJPATH)/JDFBindingIntent.o \
	$(OBJPATH)/JDFBlockPreparationParams.o \
	$(OBJPATH)/JDFBookCase.o \
	$(OBJPATH)/JDFBoxPackingParams.o \
	$(OBJPATH)/JDFBufferParams.o \
	$(OBJPATH)/JDFBundle.o \
	$(OBJPATH)/JDFBundleItem.o \
	$(OBJPATH)/JDFBusinessInfo.o \
	$(OBJPATH)/JDFByteMap.o \
	$(OBJPATH)/JDFCIELABMeasuringField.o \
	$(OBJPATH)/JDFCaseMakingParams.o \
	$(OBJPATH)/JDFCasingInParams.o \
	$(OBJPATH)/JDFChangedAttribute.o \
	$(OBJPATH)/JDFChannelBinding.o \
	$(OBJPATH)/JDFChannelBindingParams.o \
	$(OBJPATH)/JDFCoilBinding.o \
	$(OBJPATH)/JDFCoilBindingParams.o \
	$(OBJPATH)/JDFCollectingParams.o \
	$(OBJPATH)/JDFColor.o \
	$(OBJPATH)/JDFColorControlStrip.o \
	$(OBJPATH)/JDFColorCorrectionOp.o \
	$(OBJPATH)/JDFColorCorrectionParams.o \
	$(OBJPATH)/JDFColorIntent.o \
	$(OBJPATH)/JDFColorMeasurementConditions.o \
	$(OBJPATH)/JDFColorPool.o \
	$(OBJPATH)/JDFColorSpaceConversionOp.o \
	$(OBJPATH)/JDFColorSpaceConversionParams.o \
	$(OBJPATH)/JDFColorSpaceSubstitute.o \
	$(OBJPATH)/JDFColorantAlias.o \
	$(OBJPATH)/JDFColorantControl.o \
	$(OBJPATH)/JDFColorantZoneDetails.o \
	$(OBJPATH)/JDFComChannel.o \
	$(OBJPATH)/JDFCommand.o \
	$(OBJPATH)/JDFComment.o \
	$(OBJPATH)/JDFCompany.o \
	$(OBJPATH)/JDFComponent.o \
	$(OBJPATH)/JDFContact.o \
	$(OBJPATH)/JDFContactCopyParams.o \
	$(OBJPATH)/JDFContentObject.o \
	$(OBJPATH)/JDFConventionalPrintingParams.o \
	$(OBJPATH)/JDFCostCenter.o \
	$(OBJPATH)/JDFCounterReset.o \
	$(OBJPATH)/JDFCoverApplicationParams.o \
	$(OBJPATH)/JDFCrease.o \
	$(OBJPATH)/JDFCreasingParams.o \
	$(OBJPATH)/JDFCreated.o \
	$(OBJPATH)/JDFCreditCard.o \
	$(OBJPATH)/JDFCustomerInfo.o \
	$(OBJPATH)/JDFCut.o \
	$(OBJPATH)/JDFCutBlock.o \
	$(OBJPATH)/JDFCutMark.o \
	$(OBJPATH)/JDFCuttingParams.o \
	$(OBJPATH)/JDFDBMergeParams.o \
	$(OBJPATH)/JDFDBRules.o \
	$(OBJPATH)/JDFDBSchema.o \
	$(OBJPATH)/JDFDBSelection.o \
	$(OBJPATH)/JDFDeliveryIntent.o \
	$(OBJPATH)/JDFDeliveryParams.o \
	$(OBJPATH)/JDFDensityMeasuringField.o \
	$(OBJPATH)/JDFDevCaps.o \
	$(OBJPATH)/JDFDevelopingParams.o \
	$(OBJPATH)/JDFDevice.o \
	$(OBJPATH)/JDFDeviceCap.o \
	$(OBJPATH)/JDFDeviceFilter.o \
	$(OBJPATH)/JDFDeviceInfo.o \
	$(OBJPATH)/JDFDeviceList.o \
	$(OBJPATH)/JDFDeviceMark.o \
	$(OBJPATH)/JDFDeviceNColor.o \
	$(OBJPATH)/JDFDeviceNSpace.o \
	$(OBJPATH)/JDFDigitalPrintingParams.o \
	$(OBJPATH)/JDFDisjointing.o \
	$(OBJPATH)/JDFDividingParams.o \
	$(OBJPATH)/JDFDoc.o \
	$(OBJPATH)/JDFDrop.o \
	$(OBJPATH)/JDFDropIntent.o \
	$(OBJPATH)/JDFDropItem.o \
	$(OBJPATH)/JDFDropItemIntent.o \
	$(OBJPATH)/JDFDynamicField.o \
	$(OBJPATH)/JDFDynamicInput.o \
	$(OBJPATH)/JDFEdgeGluing.o \
	$(OBJPATH)/JDFElement.o \
	$(OBJPATH)/JDFEmboss.o \
	$(OBJPATH)/JDFEmbossingIntent.o \
	$(OBJPATH)/JDFEmbossingItem.o \
	$(OBJPATH)/JDFEmbossingParams.o \
	$(OBJPATH)/JDFEmployee.o \
	$(OBJPATH)/JDFEmployeeDef.o \
	$(OBJPATH)/JDFEndSheet.o \
	$(OBJPATH)/JDFEndSheetGluingParams.o \
	$(OBJPATH)/JDFError.o \
	$(OBJPATH)/JDFExposedMedia.o \
	$(OBJPATH)/JDFFCNKey.o \
	$(OBJPATH)/JDFFactory.o \
	$(OBJPATH)/JDFFileAlias.o \
	$(OBJPATH)/JDFFileSpec.o \
	$(OBJPATH)/JDFFitPolicy.o \
	$(OBJPATH)/JDFFold.o \
	$(OBJPATH)/JDFFoldingIntent.o \
	$(OBJPATH)/JDFFoldingParams.o \
	$(OBJPATH)/JDFFontParams.o \
	$(OBJPATH)/JDFFontPolicy.o \
	$(OBJPATH)/JDFFormatConversionParams.o \
	$(OBJPATH)/JDFGatheringParams.o \
	$(OBJPATH)/JDFGlue.o \
	$(OBJPATH)/JDFGlueApplication.o \
	$(OBJPATH)/JDFGlueLine.o \
	$(OBJPATH)/JDFGluingParams.o \
	$(OBJPATH)/JDFHardCoverBinding.o \
	$(OBJPATH)/JDFHeadBandApplicationParams.o \
	$(OBJPATH)/JDFHole.o \
	$(OBJPATH)/JDFHoleLine.o \
	$(OBJPATH)/JDFHoleList.o \
	$(OBJPATH)/JDFHoleMakingIntent.o \
	$(OBJPATH)/JDFHoleMakingParams.o \
	$(OBJPATH)/JDFIDPCover.o \
	$(OBJPATH)/JDFIDPFinishing.o \
	$(OBJPATH)/JDFIDPFolding.o \
	$(OBJPATH)/JDFIDPHoleMaking.o \
	$(OBJPATH)/JDFIDPImageShift.o \
	$(OBJPATH)/JDFIDPJobSheet.o \
	$(OBJPATH)/JDFIDPLayout.o \
	$(OBJPATH)/JDFIDPStitching.o \
	$(OBJPATH)/JDFIDPTrimming.o \
	$(OBJPATH)/JDFIDPrintingParams.o \
	$(OBJPATH)/JDFIcon.o \
	$(OBJPATH)/JDFIconList.o \
	$(OBJPATH)/JDFIdentificationField.o \
	$(OBJPATH)/JDFImageCompression.o \
	$(OBJPATH)/JDFImageCompressionParams.o \
	$(OBJPATH)/JDFImageReplacementParams.o \
	$(OBJPATH)/JDFImageSetterParams.o \
	$(OBJPATH)/JDFImageShift.o \
	$(OBJPATH)/JDFInk.o \
	$(OBJPATH)/JDFInkZoneCalculationParams.o \
	$(OBJPATH)/JDFInkZoneProfile.o \
	$(OBJPATH)/JDFInsert.o \
	$(OBJPATH)/JDFInsertList.o \
	$(OBJPATH)/JDFInsertSheet.o \
	$(OBJPATH)/JDFInsertingIntent.o \
	$(OBJPATH)/JDFInsertingParams.o \
	$(OBJPATH)/JDFIntegerRange.o \
	$(OBJPATH)/JDFIntegerRangeList.o \
	$(OBJPATH)/JDFIntentResource.o \
	$(OBJPATH)/JDFInterpretedPDLData.o \
	$(OBJPATH)/JDFInterpretingParams.o \
	$(OBJPATH)/JDFJDFController.o \
	$(OBJPATH)/JDFJDFService.o \
	$(OBJPATH)/JDFJMF.o \
	$(OBJPATH)/JDFJacketingParams.o \
	$(OBJPATH)/JDFJobField.o \
	$(OBJPATH)/JDFJobPhase.o \
	$(OBJPATH)/JDFKnownMsgQuParams.o \
	$(OBJPATH)/JDFLabelingParams.o \
	$(OBJPATH)/JDFLaminatingIntent.o \
	$(OBJPATH)/JDFLaminatingParams.o \
	$(OBJPATH)/JDFLayerDetails.o \
	$(OBJPATH)/JDFLayerList.o \
	$(OBJPATH)/JDFLayout.o \
	$(OBJPATH)/JDFLayoutElement.o \
	$(OBJPATH)/JDFLayoutIntent.o \
	$(OBJPATH)/JDFLayoutPreparationParams.o \
	$(OBJPATH)/JDFLocation.o \
	$(OBJPATH)/JDFLongFold.o \
	$(OBJPATH)/JDFLongGlue.o \
	$(OBJPATH)/JDFLongPerforate.o \
	$(OBJPATH)/JDFLongSlit.o \
	$(OBJPATH)/JDFLongitudinalRibbonOperationParams.o \
	$(OBJPATH)/JDFManualLaborParams.o \
	$(OBJPATH)/JDFMarkObject.o \
	$(OBJPATH)/JDFMedia.o \
	$(OBJPATH)/JDFMediaIntent.o \
	$(OBJPATH)/JDFMediaSource.o \
	$(OBJPATH)/JDFMerged.o \
	$(OBJPATH)/JDFMessage.o \
	$(OBJPATH)/JDFMessageElement.o \
	$(OBJPATH)/JDFMessageService.o \
	$(OBJPATH)/JDFModified.o \
	$(OBJPATH)/JDFModulePhase.o \
	$(OBJPATH)/JDFModuleStatus.o \
	$(OBJPATH)/JDFMsgFilter.o \
	$(OBJPATH)/JDFNode.o \
	$(OBJPATH)/JDFNodeAdhesiveBinding.o \
	$(OBJPATH)/JDFNodeBlockPreparation.o \
	$(OBJPATH)/JDFNodeBoxPacking.o \
	$(OBJPATH)/JDFNodeCaseMaking.o \
	$(OBJPATH)/JDFNodeCasingIn.o \
	$(OBJPATH)/JDFNodeChannelBinding.o \
	$(OBJPATH)/JDFNodeCoilBinding.o \
	$(OBJPATH)/JDFNodeCollecting.o \
	$(OBJPATH)/JDFNodeColorCorrection.o \
	$(OBJPATH)/JDFNodeColorSpaceConversion.o \
	$(OBJPATH)/JDFNodeCombined.o \
	$(OBJPATH)/JDFNodeContactCopying.o \
	$(OBJPATH)/JDFNodeContoneCalibration.o \
	$(OBJPATH)/JDFNodeConventionalPrinting.o \
	$(OBJPATH)/JDFNodeCoverApplication.o \
	$(OBJPATH)/JDFNodeCutting.o \
	$(OBJPATH)/JDFNodeDBDocTemplateLayout.o \
	$(OBJPATH)/JDFNodeDBTemplateMerging.o \
	$(OBJPATH)/JDFNodeDigitalPrinting.o \
	$(OBJPATH)/JDFNodeDividing.o \
	$(OBJPATH)/JDFNodeEmbossing.o \
	$(OBJPATH)/JDFNodeEndSheetGluing.o \
	$(OBJPATH)/JDFNodeFactory.o \
	$(OBJPATH)/JDFNodeFilmToPlateCopying.o \
	$(OBJPATH)/JDFNodeFolding.o \
	$(OBJPATH)/JDFNodeFormatConversion.o \
	$(OBJPATH)/JDFNodeGathering.o \
	$(OBJPATH)/JDFNodeGluing.o \
	$(OBJPATH)/JDFNodeHeadBandApplication.o \
	$(OBJPATH)/JDFNodeHoleMaking.o \
	$(OBJPATH)/JDFNodeIDPrinting.o \
	$(OBJPATH)/JDFNodeImageReplacement.o \
	$(OBJPATH)/JDFNodeImageSetting.o \
	$(OBJPATH)/JDFNodeImposition.o \
	$(OBJPATH)/JDFNodeInfo.o \
	$(OBJPATH)/JDFNodeInkZoneCalculation.o \
	$(OBJPATH)/JDFNodeInserting.o \
	$(OBJPATH)/JDFNodeInterpreting.o \
	$(OBJPATH)/JDFNodeJacketing.o \
	$(OBJPATH)/JDFNodeLabeling.o \
	$(OBJPATH)/JDFNodeLaminating.o \
	$(OBJPATH)/JDFNodeLayoutElementProduction.o \
	$(OBJPATH)/JDFNodeLayoutPreparation.o \
	$(OBJPATH)/JDFNodeLongitudinalRibbonOperations.o \
	$(OBJPATH)/JDFNodeNumbering.o \
	$(OBJPATH)/JDFNodePDFToPSConversion.o \
	$(OBJPATH)/JDFNodePSToPDFConversion.o \
	$(OBJPATH)/JDFNodePalletizing.o \
	$(OBJPATH)/JDFNodePlasticCombBinding.o \
	$(OBJPATH)/JDFNodePreflight.o \
	$(OBJPATH)/JDFNodePreviewGeneration.o \
	$(OBJPATH)/JDFNodeProcessGroup.o \
	$(OBJPATH)/JDFNodeProduct.o \
	$(OBJPATH)/JDFNodeProofing.o \
	$(OBJPATH)/JDFNodeRendering.o \
	$(OBJPATH)/JDFNodeRingBinding.o \
	$(OBJPATH)/JDFNodeSaddleStitching.o \
	$(OBJPATH)/JDFNodeScanning.o \
	$(OBJPATH)/JDFNodeScreening.o \
	$(OBJPATH)/JDFNodeSeparation.o \
	$(OBJPATH)/JDFNodeShapeCutting.o \
	$(OBJPATH)/JDFNodeShrinking.o \
	$(OBJPATH)/JDFNodeSideSewing.o \
	$(OBJPATH)/JDFNodeSoftProofing.o \
	$(OBJPATH)/JDFNodeSpinePreparation.o \
	$(OBJPATH)/JDFNodeSpineTaping.o \
	$(OBJPATH)/JDFNodeStacking.o \
	$(OBJPATH)/JDFNodeStitching.o \
	$(OBJPATH)/JDFNodeStrapping.o \
	$(OBJPATH)/JDFNodeThreadSealing.o \
	$(OBJPATH)/JDFNodeThreadSewing.o \
	$(OBJPATH)/JDFNodeTiling.o \
	$(OBJPATH)/JDFNodeTrapping.o \
	$(OBJPATH)/JDFNodeTrimming.o \
	$(OBJPATH)/JDFNodeWireCombBinding.o \
	$(OBJPATH)/JDFNodeWrapping.o \
	$(OBJPATH)/JDFNotification.o \
	$(OBJPATH)/JDFNotificationDef.o \
	$(OBJPATH)/JDFNotificationFilter.o \
	$(OBJPATH)/JDFNumberItem.o \
	$(OBJPATH)/JDFNumberingIntent.o \
	$(OBJPATH)/JDFNumberingParam.o \
	$(OBJPATH)/JDFNumberingParams.o \
	$(OBJPATH)/JDFObjectResolution.o \
	$(OBJPATH)/JDFObservationTarget.o \
	$(OBJPATH)/JDFOccupation.o \
	$(OBJPATH)/JDFOrderingParams.o \
	$(OBJPATH)/JDFPDFInterpretingParams.o \
	$(OBJPATH)/JDFPDFToPSConversionParams.o \
	$(OBJPATH)/JDFPDLResourceAlias.o \
	$(OBJPATH)/JDFPSToPDFConversionParams.o \
	$(OBJPATH)/JDFPackingIntent.o \
	$(OBJPATH)/JDFPackingParams.o \
	$(OBJPATH)/JDFPageCell.o \
	$(OBJPATH)/JDFPallet.o \
	$(OBJPATH)/JDFPalletizingParams.o \
	$(OBJPATH)/JDFParamsFactory.o \
	$(OBJPATH)/JDFPart.o \
	$(OBJPATH)/JDFPartAmount.o \
	$(OBJPATH)/JDFPartStatus.o \
	$(OBJPATH)/JDFPayment.o \
	$(OBJPATH)/JDFPerforate.o \
	$(OBJPATH)/JDFPerforatingParams.o \
	$(OBJPATH)/JDFPerson.o \
	$(OBJPATH)/JDFPhaseTime.o \
	$(OBJPATH)/JDFPipeParams.o \
	$(OBJPATH)/JDFPixelColorant.o \
	$(OBJPATH)/JDFPlaceHolder.o \
	$(OBJPATH)/JDFPlasticCombBinding.o \
	$(OBJPATH)/JDFPlasticCombBindingParams.o \
	$(OBJPATH)/JDFPlateCopyParams.o \
	$(OBJPATH)/JDFPool.o \
	$(OBJPATH)/JDFPreflightAnalysis.o \
	$(OBJPATH)/JDFPreflightConstraint.o \
	$(OBJPATH)/JDFPreflightConstraintsPool.o \
	$(OBJPATH)/JDFPreflightDetail.o \
	$(OBJPATH)/JDFPreflightInstance.o \
	$(OBJPATH)/JDFPreflightInstanceDetail.o \
	$(OBJPATH)/JDFPreflightInventory.o \
	$(OBJPATH)/JDFPreflightProfile.o \
	$(OBJPATH)/JDFPreflightResultsPool.o \
	$(OBJPATH)/JDFPreview.o \
	$(OBJPATH)/JDFPreviewGenerationParams.o \
	$(OBJPATH)/JDFPricing.o \
	$(OBJPATH)/JDFProcessRun.o \
	$(OBJPATH)/JDFProductionIntent.o \
	$(OBJPATH)/JDFProofItem.o \
	$(OBJPATH)/JDFProofingIntent.o \
	$(OBJPATH)/JDFProofingParams.o \
	$(OBJPATH)/JDFProperties.o \
	$(OBJPATH)/JDFQuery.o \
	$(OBJPATH)/JDFQueue.o \
	$(OBJPATH)/JDFQueueEntry.o \
	$(OBJPATH)/JDFQueueEntryDef.o \
	$(OBJPATH)/JDFQueueEntryPosParams.o \
	$(OBJPATH)/JDFQueueEntryPriParams.o \
	$(OBJPATH)/JDFQueueSubmissionParams.o \
	$(OBJPATH)/JDFRange.o \
	$(OBJPATH)/JDFRefElement.o \
	$(OBJPATH)/JDFRegisterMark.o \
	$(OBJPATH)/JDFRegisterRibbon.o \
	$(OBJPATH)/JDFRemoved.o \
	$(OBJPATH)/JDFRenderingParams.o \
	$(OBJPATH)/JDFResource.o \
	$(OBJPATH)/JDFResourceAudit.o \
	$(OBJPATH)/JDFResourceCmdParams.o \
	$(OBJPATH)/JDFResourceDefinitionParams.o \
	$(OBJPATH)/JDFResourceInfo.o \
	$(OBJPATH)/JDFResourceLink.o \
	$(OBJPATH)/JDFResourceLinkPool.o \
	$(OBJPATH)/JDFResourceParam.o \
	$(OBJPATH)/JDFResourcePool.o \
	$(OBJPATH)/JDFResourceQuParams.o \
	$(OBJPATH)/JDFResponse.o \
	$(OBJPATH)/JDFResubmissionParams.o \
	$(OBJPATH)/JDFRingBinding.o \
	$(OBJPATH)/JDFRingBindingParams.o \
	$(OBJPATH)/JDFRoot.o \
	$(OBJPATH)/JDFRunElement.o \
	$(OBJPATH)/JDFRunList.o \
	$(OBJPATH)/JDFSaddleStitching.o \
	$(OBJPATH)/JDFSaddleStitchingParams.o \
	$(OBJPATH)/JDFScanParams.o \
	$(OBJPATH)/JDFScavengerArea.o \
	$(OBJPATH)/JDFScore.o \
	$(OBJPATH)/JDFScreenSelector.o \
	$(OBJPATH)/JDFScreeningParams.o \
	$(OBJPATH)/JDFSeparationControlParams.o \
	$(OBJPATH)/JDFSeparationList.o \
	$(OBJPATH)/JDFSeparationSpec.o \
	$(OBJPATH)/JDFShapeCut.o \
	$(OBJPATH)/JDFShapeCuttingIntent.o \
	$(OBJPATH)/JDFShapeCuttingParams.o \
	$(OBJPATH)/JDFShapeElement.o \
	$(OBJPATH)/JDFSheet.o \
	$(OBJPATH)/JDFShrinkingParams.o \
	$(OBJPATH)/JDFSideSewing.o \
	$(OBJPATH)/JDFSideSewingParams.o \
	$(OBJPATH)/JDFSideStitching.o \
	$(OBJPATH)/JDFSignal.o \
	$(OBJPATH)/JDFSignature.o \
	$(OBJPATH)/JDFSizeIntent.o \
	$(OBJPATH)/JDFSoftCoverBinding.o \
	$(OBJPATH)/JDFSpan.o \
	$(OBJPATH)/JDFSpawned.o \
	$(OBJPATH)/JDFSpinePreparationParams.o \
	$(OBJPATH)/JDFSpineTaping.o \
	$(OBJPATH)/JDFSpineTapingParams.o \
	$(OBJPATH)/JDFStackingParams.o \
	$(OBJPATH)/JDFState.o \
	$(OBJPATH)/JDFStatusPool.o \
	$(OBJPATH)/JDFStatusQuParams.o \
	$(OBJPATH)/JDFStitchingParams.o \
	$(OBJPATH)/JDFStopPersChParams.o \
	$(OBJPATH)/JDFStrap.o \
	$(OBJPATH)/JDFStrappingParams.o \
	$(OBJPATH)/JDFStripBinding.o \
	$(OBJPATH)/JDFStripBindingParams.o \
	$(OBJPATH)/JDFSubmissionMethods.o \
	$(OBJPATH)/JDFSubscription.o \
	$(OBJPATH)/JDFSurface.o \
	$(OBJPATH)/JDFSystemTimeSet.o \
	$(OBJPATH)/JDFTabs.o \
	$(OBJPATH)/JDFTape.o \
	$(OBJPATH)/JDFThinPDFParams.o \
	$(OBJPATH)/JDFThreadSealing.o \
	$(OBJPATH)/JDFThreadSealingParams.o \
	$(OBJPATH)/JDFThreadSewing.o \
	$(OBJPATH)/JDFThreadSewingParams.o \
	$(OBJPATH)/JDFTile.o \
	$(OBJPATH)/JDFTool.o \
	$(OBJPATH)/JDFTrackFilter.o \
	$(OBJPATH)/JDFTrackResult.o \
	$(OBJPATH)/JDFTransferCurve.o \
	$(OBJPATH)/JDFTransferCurvePool.o \
	$(OBJPATH)/JDFTransferCurveSet.o \
	$(OBJPATH)/JDFTransferFunctionControl.o \
	$(OBJPATH)/JDFTrapRegion.o \
	$(OBJPATH)/JDFTrappingDetails.o \
	$(OBJPATH)/JDFTrappingOrder.o \
	$(OBJPATH)/JDFTrappingParams.o \
	$(OBJPATH)/JDFTrigger.o \
	$(OBJPATH)/JDFTrimmingParams.o \
	$(OBJPATH)/JDFVeloBindingParams.o \
	$(OBJPATH)/JDFVerificationParams.o \
	$(OBJPATH)/JDFWireCombBinding.o \
	$(OBJPATH)/JDFWireCombBindingParams.o \
	$(OBJPATH)/JDFWrappingParams.o 
	
all: ObjDir $(LIBOUT) install

ObjDir:
	mkdir -p $(OBJPATH)

$(STATLIB): $(OBJPATH)/$(STATLIB)

$(OBJPATH)/$(STATLIB): $(OBJS)
	ar rcs $(OBJPATH)/$(STATLIB) $(OBJS)

install: $(LIBOUT)
	mkdir -p $(INSTPATH)
	cp $(OBJPATH)/$(LIBOUT) $(INSTPATH)

clean:
	rm -f $(OBJPATH)/$(STATLIB)
	rm -f $(OBJPATH)/*.o

$(OBJPATH)/JDFAcknowledge.o: $(SRCPATH)/wrapper/JDFAcknowledge.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAcknowledge.o $(SRCPATH)/wrapper/JDFAcknowledge.cpp

$(OBJPATH)/JDFAdded.o: $(SRCPATH)/wrapper/JDFAdded.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAdded.o $(SRCPATH)/wrapper/JDFAdded.cpp

$(OBJPATH)/JDFAddress.o: $(SRCPATH)/wrapper/JDFAddress.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAddress.o $(SRCPATH)/wrapper/JDFAddress.cpp

$(OBJPATH)/JDFAdhesiveBinding.o: $(SRCPATH)/wrapper/JDFAdhesiveBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAdhesiveBinding.o $(SRCPATH)/wrapper/JDFAdhesiveBinding.cpp

$(OBJPATH)/JDFAdhesiveBindingParams.o: $(SRCPATH)/wrapper/JDFAdhesiveBindingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAdhesiveBindingParams.o $(SRCPATH)/wrapper/JDFAdhesiveBindingParams.cpp

$(OBJPATH)/JDFAdvancedParams.o: $(SRCPATH)/wrapper/JDFAdvancedParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAdvancedParams.o $(SRCPATH)/wrapper/JDFAdvancedParams.cpp

$(OBJPATH)/JDFAmountPool.o: $(SRCPATH)/wrapper/JDFAmountPool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAmountPool.o $(SRCPATH)/wrapper/JDFAmountPool.cpp

$(OBJPATH)/JDFAncestor.o: $(SRCPATH)/wrapper/JDFAncestor.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAncestor.o $(SRCPATH)/wrapper/JDFAncestor.cpp

$(OBJPATH)/JDFAncestorPool.o: $(SRCPATH)/wrapper/JDFAncestorPool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAncestorPool.o $(SRCPATH)/wrapper/JDFAncestorPool.cpp

$(OBJPATH)/JDFApprovalParams.o: $(SRCPATH)/wrapper/JDFApprovalParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFApprovalParams.o $(SRCPATH)/wrapper/JDFApprovalParams.cpp

$(OBJPATH)/JDFApprovalPerson.o: $(SRCPATH)/wrapper/JDFApprovalPerson.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFApprovalPerson.o $(SRCPATH)/wrapper/JDFApprovalPerson.cpp

$(OBJPATH)/JDFApprovalSuccess.o: $(SRCPATH)/wrapper/JDFApprovalSuccess.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFApprovalSuccess.o $(SRCPATH)/wrapper/JDFApprovalSuccess.cpp

$(OBJPATH)/JDFArtDelivery.o: $(SRCPATH)/wrapper/JDFArtDelivery.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFArtDelivery.o $(SRCPATH)/wrapper/JDFArtDelivery.cpp

$(OBJPATH)/JDFArtDeliveryIntent.o: $(SRCPATH)/wrapper/JDFArtDeliveryIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFArtDeliveryIntent.o $(SRCPATH)/wrapper/JDFArtDeliveryIntent.cpp

$(OBJPATH)/JDFAudit.o: $(SRCPATH)/wrapper/JDFAudit.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAudit.o $(SRCPATH)/wrapper/JDFAudit.cpp

$(OBJPATH)/JDFAuditPool.o: $(SRCPATH)/wrapper/JDFAuditPool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAuditPool.o $(SRCPATH)/wrapper/JDFAuditPool.cpp

$(OBJPATH)/JDFAutomatedOverprintParams.o: $(SRCPATH)/wrapper/JDFAutomatedOverprintParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutomatedOverprintParams.o $(SRCPATH)/wrapper/JDFAutomatedOverprintParams.cpp

$(OBJPATH)/JDFBackPreparation.o: $(SRCPATH)/wrapper/JDFBackPreparation.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFBackPreparation.o $(SRCPATH)/wrapper/JDFBackPreparation.cpp

$(OBJPATH)/JDFBand.o: $(SRCPATH)/wrapper/JDFBand.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFBand.o $(SRCPATH)/wrapper/JDFBand.cpp

$(OBJPATH)/JDFBarcode.o: $(SRCPATH)/wrapper/JDFBarcode.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFBarcode.o $(SRCPATH)/wrapper/JDFBarcode.cpp

$(OBJPATH)/JDFBindItem.o: $(SRCPATH)/wrapper/JDFBindItem.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFBindItem.o $(SRCPATH)/wrapper/JDFBindItem.cpp

$(OBJPATH)/JDFBindList.o: $(SRCPATH)/wrapper/JDFBindList.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFBindList.o $(SRCPATH)/wrapper/JDFBindList.cpp

$(OBJPATH)/JDFBindingIntent.o: $(SRCPATH)/wrapper/JDFBindingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFBindingIntent.o $(SRCPATH)/wrapper/JDFBindingIntent.cpp

$(OBJPATH)/JDFBlockPreparationParams.o: $(SRCPATH)/wrapper/JDFBlockPreparationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFBlockPreparationParams.o $(SRCPATH)/wrapper/JDFBlockPreparationParams.cpp

$(OBJPATH)/JDFBookCase.o: $(SRCPATH)/wrapper/JDFBookCase.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFBookCase.o $(SRCPATH)/wrapper/JDFBookCase.cpp

$(OBJPATH)/JDFBoxPackingParams.o: $(SRCPATH)/wrapper/JDFBoxPackingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFBoxPackingParams.o $(SRCPATH)/wrapper/JDFBoxPackingParams.cpp

$(OBJPATH)/JDFBufferParams.o: $(SRCPATH)/wrapper/JDFBufferParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFBufferParams.o $(SRCPATH)/wrapper/JDFBufferParams.cpp

$(OBJPATH)/JDFBundle.o: $(SRCPATH)/wrapper/JDFBundle.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFBundle.o $(SRCPATH)/wrapper/JDFBundle.cpp

$(OBJPATH)/JDFBundleItem.o: $(SRCPATH)/wrapper/JDFBundleItem.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFBundleItem.o $(SRCPATH)/wrapper/JDFBundleItem.cpp

$(OBJPATH)/JDFBusinessInfo.o: $(SRCPATH)/wrapper/JDFBusinessInfo.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFBusinessInfo.o $(SRCPATH)/wrapper/JDFBusinessInfo.cpp

$(OBJPATH)/JDFByteMap.o: $(SRCPATH)/wrapper/JDFByteMap.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFByteMap.o $(SRCPATH)/wrapper/JDFByteMap.cpp

$(OBJPATH)/JDFCIELABMeasuringField.o: $(SRCPATH)/wrapper/JDFCIELABMeasuringField.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCIELABMeasuringField.o $(SRCPATH)/wrapper/JDFCIELABMeasuringField.cpp

$(OBJPATH)/JDFCaseMakingParams.o: $(SRCPATH)/wrapper/JDFCaseMakingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCaseMakingParams.o $(SRCPATH)/wrapper/JDFCaseMakingParams.cpp

$(OBJPATH)/JDFCasingInParams.o: $(SRCPATH)/wrapper/JDFCasingInParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCasingInParams.o $(SRCPATH)/wrapper/JDFCasingInParams.cpp

$(OBJPATH)/JDFChangedAttribute.o: $(SRCPATH)/wrapper/JDFChangedAttribute.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFChangedAttribute.o $(SRCPATH)/wrapper/JDFChangedAttribute.cpp

$(OBJPATH)/JDFChannelBinding.o: $(SRCPATH)/wrapper/JDFChannelBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFChannelBinding.o $(SRCPATH)/wrapper/JDFChannelBinding.cpp

$(OBJPATH)/JDFChannelBindingParams.o: $(SRCPATH)/wrapper/JDFChannelBindingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFChannelBindingParams.o $(SRCPATH)/wrapper/JDFChannelBindingParams.cpp

$(OBJPATH)/JDFCoilBinding.o: $(SRCPATH)/wrapper/JDFCoilBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCoilBinding.o $(SRCPATH)/wrapper/JDFCoilBinding.cpp

$(OBJPATH)/JDFCoilBindingParams.o: $(SRCPATH)/wrapper/JDFCoilBindingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCoilBindingParams.o $(SRCPATH)/wrapper/JDFCoilBindingParams.cpp

$(OBJPATH)/JDFCollectingParams.o: $(SRCPATH)/wrapper/JDFCollectingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCollectingParams.o $(SRCPATH)/wrapper/JDFCollectingParams.cpp

$(OBJPATH)/JDFColor.o: $(SRCPATH)/wrapper/JDFColor.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFColor.o $(SRCPATH)/wrapper/JDFColor.cpp

$(OBJPATH)/JDFColorControlStrip.o: $(SRCPATH)/wrapper/JDFColorControlStrip.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFColorControlStrip.o $(SRCPATH)/wrapper/JDFColorControlStrip.cpp

$(OBJPATH)/JDFColorCorrectionOp.o: $(SRCPATH)/wrapper/JDFColorCorrectionOp.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFColorCorrectionOp.o $(SRCPATH)/wrapper/JDFColorCorrectionOp.cpp

$(OBJPATH)/JDFColorCorrectionParams.o: $(SRCPATH)/wrapper/JDFColorCorrectionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFColorCorrectionParams.o $(SRCPATH)/wrapper/JDFColorCorrectionParams.cpp

$(OBJPATH)/JDFColorIntent.o: $(SRCPATH)/wrapper/JDFColorIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFColorIntent.o $(SRCPATH)/wrapper/JDFColorIntent.cpp

$(OBJPATH)/JDFColorMeasurementConditions.o: $(SRCPATH)/wrapper/JDFColorMeasurementConditions.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFColorMeasurementConditions.o $(SRCPATH)/wrapper/JDFColorMeasurementConditions.cpp

$(OBJPATH)/JDFColorPool.o: $(SRCPATH)/wrapper/JDFColorPool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFColorPool.o $(SRCPATH)/wrapper/JDFColorPool.cpp

$(OBJPATH)/JDFColorSpaceConversionOp.o: $(SRCPATH)/wrapper/JDFColorSpaceConversionOp.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFColorSpaceConversionOp.o $(SRCPATH)/wrapper/JDFColorSpaceConversionOp.cpp

$(OBJPATH)/JDFColorSpaceConversionParams.o: $(SRCPATH)/wrapper/JDFColorSpaceConversionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFColorSpaceConversionParams.o $(SRCPATH)/wrapper/JDFColorSpaceConversionParams.cpp

$(OBJPATH)/JDFColorSpaceSubstitute.o: $(SRCPATH)/wrapper/JDFColorSpaceSubstitute.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFColorSpaceSubstitute.o $(SRCPATH)/wrapper/JDFColorSpaceSubstitute.cpp

$(OBJPATH)/JDFColorantAlias.o: $(SRCPATH)/wrapper/JDFColorantAlias.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFColorantAlias.o $(SRCPATH)/wrapper/JDFColorantAlias.cpp

$(OBJPATH)/JDFColorantControl.o: $(SRCPATH)/wrapper/JDFColorantControl.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFColorantControl.o $(SRCPATH)/wrapper/JDFColorantControl.cpp

$(OBJPATH)/JDFColorantZoneDetails.o: $(SRCPATH)/wrapper/JDFColorantZoneDetails.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFColorantZoneDetails.o $(SRCPATH)/wrapper/JDFColorantZoneDetails.cpp

$(OBJPATH)/JDFComChannel.o: $(SRCPATH)/wrapper/JDFComChannel.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFComChannel.o $(SRCPATH)/wrapper/JDFComChannel.cpp

$(OBJPATH)/JDFCommand.o: $(SRCPATH)/wrapper/JDFCommand.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCommand.o $(SRCPATH)/wrapper/JDFCommand.cpp

$(OBJPATH)/JDFComment.o: $(SRCPATH)/wrapper/JDFComment.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFComment.o $(SRCPATH)/wrapper/JDFComment.cpp

$(OBJPATH)/JDFCompany.o: $(SRCPATH)/wrapper/JDFCompany.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCompany.o $(SRCPATH)/wrapper/JDFCompany.cpp

$(OBJPATH)/JDFComponent.o: $(SRCPATH)/wrapper/JDFComponent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFComponent.o $(SRCPATH)/wrapper/JDFComponent.cpp

$(OBJPATH)/JDFContact.o: $(SRCPATH)/wrapper/JDFContact.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFContact.o $(SRCPATH)/wrapper/JDFContact.cpp

$(OBJPATH)/JDFContactCopyParams.o: $(SRCPATH)/wrapper/JDFContactCopyParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFContactCopyParams.o $(SRCPATH)/wrapper/JDFContactCopyParams.cpp

$(OBJPATH)/JDFContentObject.o: $(SRCPATH)/wrapper/JDFContentObject.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFContentObject.o $(SRCPATH)/wrapper/JDFContentObject.cpp

$(OBJPATH)/JDFConventionalPrintingParams.o: $(SRCPATH)/wrapper/JDFConventionalPrintingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFConventionalPrintingParams.o $(SRCPATH)/wrapper/JDFConventionalPrintingParams.cpp

$(OBJPATH)/JDFCostCenter.o: $(SRCPATH)/wrapper/JDFCostCenter.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCostCenter.o $(SRCPATH)/wrapper/JDFCostCenter.cpp

$(OBJPATH)/JDFCounterReset.o: $(SRCPATH)/wrapper/JDFCounterReset.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCounterReset.o $(SRCPATH)/wrapper/JDFCounterReset.cpp

$(OBJPATH)/JDFCoverApplicationParams.o: $(SRCPATH)/wrapper/JDFCoverApplicationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCoverApplicationParams.o $(SRCPATH)/wrapper/JDFCoverApplicationParams.cpp

$(OBJPATH)/JDFCrease.o: $(SRCPATH)/wrapper/JDFCrease.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCrease.o $(SRCPATH)/wrapper/JDFCrease.cpp

$(OBJPATH)/JDFCreasingParams.o: $(SRCPATH)/wrapper/JDFCreasingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCreasingParams.o $(SRCPATH)/wrapper/JDFCreasingParams.cpp

$(OBJPATH)/JDFCreated.o: $(SRCPATH)/wrapper/JDFCreated.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCreated.o $(SRCPATH)/wrapper/JDFCreated.cpp

$(OBJPATH)/JDFCreditCard.o: $(SRCPATH)/wrapper/JDFCreditCard.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCreditCard.o $(SRCPATH)/wrapper/JDFCreditCard.cpp

$(OBJPATH)/JDFCustomerInfo.o: $(SRCPATH)/wrapper/JDFCustomerInfo.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCustomerInfo.o $(SRCPATH)/wrapper/JDFCustomerInfo.cpp

$(OBJPATH)/JDFCut.o: $(SRCPATH)/wrapper/JDFCut.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCut.o $(SRCPATH)/wrapper/JDFCut.cpp

$(OBJPATH)/JDFCutBlock.o: $(SRCPATH)/wrapper/JDFCutBlock.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCutBlock.o $(SRCPATH)/wrapper/JDFCutBlock.cpp

$(OBJPATH)/JDFCutMark.o: $(SRCPATH)/wrapper/JDFCutMark.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCutMark.o $(SRCPATH)/wrapper/JDFCutMark.cpp

$(OBJPATH)/JDFCuttingParams.o: $(SRCPATH)/wrapper/JDFCuttingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFCuttingParams.o $(SRCPATH)/wrapper/JDFCuttingParams.cpp

$(OBJPATH)/JDFDBMergeParams.o: $(SRCPATH)/wrapper/JDFDBMergeParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDBMergeParams.o $(SRCPATH)/wrapper/JDFDBMergeParams.cpp

$(OBJPATH)/JDFDBRules.o: $(SRCPATH)/wrapper/JDFDBRules.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDBRules.o $(SRCPATH)/wrapper/JDFDBRules.cpp

$(OBJPATH)/JDFDBSchema.o: $(SRCPATH)/wrapper/JDFDBSchema.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDBSchema.o $(SRCPATH)/wrapper/JDFDBSchema.cpp

$(OBJPATH)/JDFDBSelection.o: $(SRCPATH)/wrapper/JDFDBSelection.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDBSelection.o $(SRCPATH)/wrapper/JDFDBSelection.cpp

$(OBJPATH)/JDFDeliveryIntent.o: $(SRCPATH)/wrapper/JDFDeliveryIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDeliveryIntent.o $(SRCPATH)/wrapper/JDFDeliveryIntent.cpp

$(OBJPATH)/JDFDeliveryParams.o: $(SRCPATH)/wrapper/JDFDeliveryParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDeliveryParams.o $(SRCPATH)/wrapper/JDFDeliveryParams.cpp

$(OBJPATH)/JDFDensityMeasuringField.o: $(SRCPATH)/wrapper/JDFDensityMeasuringField.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDensityMeasuringField.o $(SRCPATH)/wrapper/JDFDensityMeasuringField.cpp

$(OBJPATH)/JDFDevCaps.o: $(SRCPATH)/wrapper/JDFDevCaps.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDevCaps.o $(SRCPATH)/wrapper/JDFDevCaps.cpp

$(OBJPATH)/JDFDevelopingParams.o: $(SRCPATH)/wrapper/JDFDevelopingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDevelopingParams.o $(SRCPATH)/wrapper/JDFDevelopingParams.cpp

$(OBJPATH)/JDFDevice.o: $(SRCPATH)/wrapper/JDFDevice.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDevice.o $(SRCPATH)/wrapper/JDFDevice.cpp

$(OBJPATH)/JDFDeviceCap.o: $(SRCPATH)/wrapper/JDFDeviceCap.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDeviceCap.o $(SRCPATH)/wrapper/JDFDeviceCap.cpp

$(OBJPATH)/JDFDeviceFilter.o: $(SRCPATH)/wrapper/JDFDeviceFilter.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDeviceFilter.o $(SRCPATH)/wrapper/JDFDeviceFilter.cpp

$(OBJPATH)/JDFDeviceInfo.o: $(SRCPATH)/wrapper/JDFDeviceInfo.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDeviceInfo.o $(SRCPATH)/wrapper/JDFDeviceInfo.cpp

$(OBJPATH)/JDFDeviceList.o: $(SRCPATH)/wrapper/JDFDeviceList.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDeviceList.o $(SRCPATH)/wrapper/JDFDeviceList.cpp

$(OBJPATH)/JDFDeviceMark.o: $(SRCPATH)/wrapper/JDFDeviceMark.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDeviceMark.o $(SRCPATH)/wrapper/JDFDeviceMark.cpp

$(OBJPATH)/JDFDeviceNColor.o: $(SRCPATH)/wrapper/JDFDeviceNColor.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDeviceNColor.o $(SRCPATH)/wrapper/JDFDeviceNColor.cpp

$(OBJPATH)/JDFDeviceNSpace.o: $(SRCPATH)/wrapper/JDFDeviceNSpace.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDeviceNSpace.o $(SRCPATH)/wrapper/JDFDeviceNSpace.cpp

$(OBJPATH)/JDFDigitalPrintingParams.o: $(SRCPATH)/wrapper/JDFDigitalPrintingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDigitalPrintingParams.o $(SRCPATH)/wrapper/JDFDigitalPrintingParams.cpp

$(OBJPATH)/JDFDisjointing.o: $(SRCPATH)/wrapper/JDFDisjointing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDisjointing.o $(SRCPATH)/wrapper/JDFDisjointing.cpp

$(OBJPATH)/JDFDividingParams.o: $(SRCPATH)/wrapper/JDFDividingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDividingParams.o $(SRCPATH)/wrapper/JDFDividingParams.cpp

$(OBJPATH)/JDFDoc.o: $(SRCPATH)/wrapper/JDFDoc.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDoc.o $(SRCPATH)/wrapper/JDFDoc.cpp

$(OBJPATH)/JDFDrop.o: $(SRCPATH)/wrapper/JDFDrop.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDrop.o $(SRCPATH)/wrapper/JDFDrop.cpp

$(OBJPATH)/JDFDropIntent.o: $(SRCPATH)/wrapper/JDFDropIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDropIntent.o $(SRCPATH)/wrapper/JDFDropIntent.cpp

$(OBJPATH)/JDFDropItem.o: $(SRCPATH)/wrapper/JDFDropItem.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDropItem.o $(SRCPATH)/wrapper/JDFDropItem.cpp

$(OBJPATH)/JDFDropItemIntent.o: $(SRCPATH)/wrapper/JDFDropItemIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDropItemIntent.o $(SRCPATH)/wrapper/JDFDropItemIntent.cpp

$(OBJPATH)/JDFDynamicField.o: $(SRCPATH)/wrapper/JDFDynamicField.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDynamicField.o $(SRCPATH)/wrapper/JDFDynamicField.cpp

$(OBJPATH)/JDFDynamicInput.o: $(SRCPATH)/wrapper/JDFDynamicInput.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFDynamicInput.o $(SRCPATH)/wrapper/JDFDynamicInput.cpp

$(OBJPATH)/JDFEdgeGluing.o: $(SRCPATH)/wrapper/JDFEdgeGluing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFEdgeGluing.o $(SRCPATH)/wrapper/JDFEdgeGluing.cpp

$(OBJPATH)/JDFElement.o: $(SRCPATH)/wrapper/JDFElement.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFElement.o $(SRCPATH)/wrapper/JDFElement.cpp

$(OBJPATH)/JDFEmboss.o: $(SRCPATH)/wrapper/JDFEmboss.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFEmboss.o $(SRCPATH)/wrapper/JDFEmboss.cpp

$(OBJPATH)/JDFEmbossingIntent.o: $(SRCPATH)/wrapper/JDFEmbossingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFEmbossingIntent.o $(SRCPATH)/wrapper/JDFEmbossingIntent.cpp

$(OBJPATH)/JDFEmbossingItem.o: $(SRCPATH)/wrapper/JDFEmbossingItem.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFEmbossingItem.o $(SRCPATH)/wrapper/JDFEmbossingItem.cpp

$(OBJPATH)/JDFEmbossingParams.o: $(SRCPATH)/wrapper/JDFEmbossingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFEmbossingParams.o $(SRCPATH)/wrapper/JDFEmbossingParams.cpp

$(OBJPATH)/JDFEmployee.o: $(SRCPATH)/wrapper/JDFEmployee.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFEmployee.o $(SRCPATH)/wrapper/JDFEmployee.cpp

$(OBJPATH)/JDFEmployeeDef.o: $(SRCPATH)/wrapper/JDFEmployeeDef.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFEmployeeDef.o $(SRCPATH)/wrapper/JDFEmployeeDef.cpp

$(OBJPATH)/JDFEndSheet.o: $(SRCPATH)/wrapper/JDFEndSheet.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFEndSheet.o $(SRCPATH)/wrapper/JDFEndSheet.cpp

$(OBJPATH)/JDFEndSheetGluingParams.o: $(SRCPATH)/wrapper/JDFEndSheetGluingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFEndSheetGluingParams.o $(SRCPATH)/wrapper/JDFEndSheetGluingParams.cpp

$(OBJPATH)/JDFError.o: $(SRCPATH)/wrapper/JDFError.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFError.o $(SRCPATH)/wrapper/JDFError.cpp

$(OBJPATH)/JDFExposedMedia.o: $(SRCPATH)/wrapper/JDFExposedMedia.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFExposedMedia.o $(SRCPATH)/wrapper/JDFExposedMedia.cpp

$(OBJPATH)/JDFFCNKey.o: $(SRCPATH)/wrapper/JDFFCNKey.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFFCNKey.o $(SRCPATH)/wrapper/JDFFCNKey.cpp

$(OBJPATH)/JDFFactory.o: $(SRCPATH)/wrapper/JDFFactory.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFFactory.o $(SRCPATH)/wrapper/JDFFactory.cpp

$(OBJPATH)/JDFFileAlias.o: $(SRCPATH)/wrapper/JDFFileAlias.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFFileAlias.o $(SRCPATH)/wrapper/JDFFileAlias.cpp

$(OBJPATH)/JDFFileSpec.o: $(SRCPATH)/wrapper/JDFFileSpec.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFFileSpec.o $(SRCPATH)/wrapper/JDFFileSpec.cpp

$(OBJPATH)/JDFFitPolicy.o: $(SRCPATH)/wrapper/JDFFitPolicy.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFFitPolicy.o $(SRCPATH)/wrapper/JDFFitPolicy.cpp

$(OBJPATH)/JDFFold.o: $(SRCPATH)/wrapper/JDFFold.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFFold.o $(SRCPATH)/wrapper/JDFFold.cpp

$(OBJPATH)/JDFFoldingIntent.o: $(SRCPATH)/wrapper/JDFFoldingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFFoldingIntent.o $(SRCPATH)/wrapper/JDFFoldingIntent.cpp

$(OBJPATH)/JDFFoldingParams.o: $(SRCPATH)/wrapper/JDFFoldingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFFoldingParams.o $(SRCPATH)/wrapper/JDFFoldingParams.cpp

$(OBJPATH)/JDFFontParams.o: $(SRCPATH)/wrapper/JDFFontParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFFontParams.o $(SRCPATH)/wrapper/JDFFontParams.cpp

$(OBJPATH)/JDFFontPolicy.o: $(SRCPATH)/wrapper/JDFFontPolicy.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFFontPolicy.o $(SRCPATH)/wrapper/JDFFontPolicy.cpp

$(OBJPATH)/JDFFormatConversionParams.o: $(SRCPATH)/wrapper/JDFFormatConversionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFFormatConversionParams.o $(SRCPATH)/wrapper/JDFFormatConversionParams.cpp

$(OBJPATH)/JDFGatheringParams.o: $(SRCPATH)/wrapper/JDFGatheringParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFGatheringParams.o $(SRCPATH)/wrapper/JDFGatheringParams.cpp

$(OBJPATH)/JDFGlue.o: $(SRCPATH)/wrapper/JDFGlue.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFGlue.o $(SRCPATH)/wrapper/JDFGlue.cpp

$(OBJPATH)/JDFGlueApplication.o: $(SRCPATH)/wrapper/JDFGlueApplication.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFGlueApplication.o $(SRCPATH)/wrapper/JDFGlueApplication.cpp

$(OBJPATH)/JDFGlueLine.o: $(SRCPATH)/wrapper/JDFGlueLine.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFGlueLine.o $(SRCPATH)/wrapper/JDFGlueLine.cpp

$(OBJPATH)/JDFGluingParams.o: $(SRCPATH)/wrapper/JDFGluingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFGluingParams.o $(SRCPATH)/wrapper/JDFGluingParams.cpp

$(OBJPATH)/JDFHardCoverBinding.o: $(SRCPATH)/wrapper/JDFHardCoverBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFHardCoverBinding.o $(SRCPATH)/wrapper/JDFHardCoverBinding.cpp

$(OBJPATH)/JDFHeadBandApplicationParams.o: $(SRCPATH)/wrapper/JDFHeadBandApplicationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFHeadBandApplicationParams.o $(SRCPATH)/wrapper/JDFHeadBandApplicationParams.cpp

$(OBJPATH)/JDFHole.o: $(SRCPATH)/wrapper/JDFHole.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFHole.o $(SRCPATH)/wrapper/JDFHole.cpp

$(OBJPATH)/JDFHoleLine.o: $(SRCPATH)/wrapper/JDFHoleLine.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFHoleLine.o $(SRCPATH)/wrapper/JDFHoleLine.cpp

$(OBJPATH)/JDFHoleList.o: $(SRCPATH)/wrapper/JDFHoleList.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFHoleList.o $(SRCPATH)/wrapper/JDFHoleList.cpp

$(OBJPATH)/JDFHoleMakingIntent.o: $(SRCPATH)/wrapper/JDFHoleMakingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFHoleMakingIntent.o $(SRCPATH)/wrapper/JDFHoleMakingIntent.cpp

$(OBJPATH)/JDFHoleMakingParams.o: $(SRCPATH)/wrapper/JDFHoleMakingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFHoleMakingParams.o $(SRCPATH)/wrapper/JDFHoleMakingParams.cpp

$(OBJPATH)/JDFIDPCover.o: $(SRCPATH)/wrapper/JDFIDPCover.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFIDPCover.o $(SRCPATH)/wrapper/JDFIDPCover.cpp

$(OBJPATH)/JDFIDPFinishing.o: $(SRCPATH)/wrapper/JDFIDPFinishing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFIDPFinishing.o $(SRCPATH)/wrapper/JDFIDPFinishing.cpp

$(OBJPATH)/JDFIDPFolding.o: $(SRCPATH)/wrapper/JDFIDPFolding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFIDPFolding.o $(SRCPATH)/wrapper/JDFIDPFolding.cpp

$(OBJPATH)/JDFIDPHoleMaking.o: $(SRCPATH)/wrapper/JDFIDPHoleMaking.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFIDPHoleMaking.o $(SRCPATH)/wrapper/JDFIDPHoleMaking.cpp

$(OBJPATH)/JDFIDPImageShift.o: $(SRCPATH)/wrapper/JDFIDPImageShift.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFIDPImageShift.o $(SRCPATH)/wrapper/JDFIDPImageShift.cpp

$(OBJPATH)/JDFIDPJobSheet.o: $(SRCPATH)/wrapper/JDFIDPJobSheet.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFIDPJobSheet.o $(SRCPATH)/wrapper/JDFIDPJobSheet.cpp

$(OBJPATH)/JDFIDPLayout.o: $(SRCPATH)/wrapper/JDFIDPLayout.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFIDPLayout.o $(SRCPATH)/wrapper/JDFIDPLayout.cpp

$(OBJPATH)/JDFIDPStitching.o: $(SRCPATH)/wrapper/JDFIDPStitching.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFIDPStitching.o $(SRCPATH)/wrapper/JDFIDPStitching.cpp

$(OBJPATH)/JDFIDPTrimming.o: $(SRCPATH)/wrapper/JDFIDPTrimming.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFIDPTrimming.o $(SRCPATH)/wrapper/JDFIDPTrimming.cpp

$(OBJPATH)/JDFIDPrintingParams.o: $(SRCPATH)/wrapper/JDFIDPrintingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFIDPrintingParams.o $(SRCPATH)/wrapper/JDFIDPrintingParams.cpp

$(OBJPATH)/JDFIcon.o: $(SRCPATH)/wrapper/JDFIcon.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFIcon.o $(SRCPATH)/wrapper/JDFIcon.cpp

$(OBJPATH)/JDFIconList.o: $(SRCPATH)/wrapper/JDFIconList.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFIconList.o $(SRCPATH)/wrapper/JDFIconList.cpp

$(OBJPATH)/JDFIdentificationField.o: $(SRCPATH)/wrapper/JDFIdentificationField.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFIdentificationField.o $(SRCPATH)/wrapper/JDFIdentificationField.cpp

$(OBJPATH)/JDFImageCompression.o: $(SRCPATH)/wrapper/JDFImageCompression.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFImageCompression.o $(SRCPATH)/wrapper/JDFImageCompression.cpp

$(OBJPATH)/JDFImageCompressionParams.o: $(SRCPATH)/wrapper/JDFImageCompressionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFImageCompressionParams.o $(SRCPATH)/wrapper/JDFImageCompressionParams.cpp

$(OBJPATH)/JDFImageReplacementParams.o: $(SRCPATH)/wrapper/JDFImageReplacementParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFImageReplacementParams.o $(SRCPATH)/wrapper/JDFImageReplacementParams.cpp

$(OBJPATH)/JDFImageSetterParams.o: $(SRCPATH)/wrapper/JDFImageSetterParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFImageSetterParams.o $(SRCPATH)/wrapper/JDFImageSetterParams.cpp

$(OBJPATH)/JDFImageShift.o: $(SRCPATH)/wrapper/JDFImageShift.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFImageShift.o $(SRCPATH)/wrapper/JDFImageShift.cpp

$(OBJPATH)/JDFInk.o: $(SRCPATH)/wrapper/JDFInk.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFInk.o $(SRCPATH)/wrapper/JDFInk.cpp

$(OBJPATH)/JDFInkZoneCalculationParams.o: $(SRCPATH)/wrapper/JDFInkZoneCalculationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFInkZoneCalculationParams.o $(SRCPATH)/wrapper/JDFInkZoneCalculationParams.cpp

$(OBJPATH)/JDFInkZoneProfile.o: $(SRCPATH)/wrapper/JDFInkZoneProfile.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFInkZoneProfile.o $(SRCPATH)/wrapper/JDFInkZoneProfile.cpp

$(OBJPATH)/JDFInsert.o: $(SRCPATH)/wrapper/JDFInsert.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFInsert.o $(SRCPATH)/wrapper/JDFInsert.cpp

$(OBJPATH)/JDFInsertList.o: $(SRCPATH)/wrapper/JDFInsertList.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFInsertList.o $(SRCPATH)/wrapper/JDFInsertList.cpp

$(OBJPATH)/JDFInsertSheet.o: $(SRCPATH)/wrapper/JDFInsertSheet.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFInsertSheet.o $(SRCPATH)/wrapper/JDFInsertSheet.cpp

$(OBJPATH)/JDFInsertingIntent.o: $(SRCPATH)/wrapper/JDFInsertingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFInsertingIntent.o $(SRCPATH)/wrapper/JDFInsertingIntent.cpp

$(OBJPATH)/JDFInsertingParams.o: $(SRCPATH)/wrapper/JDFInsertingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFInsertingParams.o $(SRCPATH)/wrapper/JDFInsertingParams.cpp

$(OBJPATH)/JDFIntegerRange.o: $(SRCPATH)/wrapper/JDFIntegerRange.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFIntegerRange.o $(SRCPATH)/wrapper/JDFIntegerRange.cpp

$(OBJPATH)/JDFIntegerRangeList.o: $(SRCPATH)/wrapper/JDFIntegerRangeList.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFIntegerRangeList.o $(SRCPATH)/wrapper/JDFIntegerRangeList.cpp

$(OBJPATH)/JDFIntentResource.o: $(SRCPATH)/wrapper/JDFIntentResource.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFIntentResource.o $(SRCPATH)/wrapper/JDFIntentResource.cpp

$(OBJPATH)/JDFInterpretedPDLData.o: $(SRCPATH)/wrapper/JDFInterpretedPDLData.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFInterpretedPDLData.o $(SRCPATH)/wrapper/JDFInterpretedPDLData.cpp

$(OBJPATH)/JDFInterpretingParams.o: $(SRCPATH)/wrapper/JDFInterpretingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFInterpretingParams.o $(SRCPATH)/wrapper/JDFInterpretingParams.cpp

$(OBJPATH)/JDFJDFController.o: $(SRCPATH)/wrapper/JDFJDFController.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFJDFController.o $(SRCPATH)/wrapper/JDFJDFController.cpp

$(OBJPATH)/JDFJDFService.o: $(SRCPATH)/wrapper/JDFJDFService.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFJDFService.o $(SRCPATH)/wrapper/JDFJDFService.cpp

$(OBJPATH)/JDFJMF.o: $(SRCPATH)/wrapper/JDFJMF.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFJMF.o $(SRCPATH)/wrapper/JDFJMF.cpp

$(OBJPATH)/JDFJacketingParams.o: $(SRCPATH)/wrapper/JDFJacketingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFJacketingParams.o $(SRCPATH)/wrapper/JDFJacketingParams.cpp

$(OBJPATH)/JDFJobField.o: $(SRCPATH)/wrapper/JDFJobField.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFJobField.o $(SRCPATH)/wrapper/JDFJobField.cpp

$(OBJPATH)/JDFJobPhase.o: $(SRCPATH)/wrapper/JDFJobPhase.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFJobPhase.o $(SRCPATH)/wrapper/JDFJobPhase.cpp

$(OBJPATH)/JDFKnownMsgQuParams.o: $(SRCPATH)/wrapper/JDFKnownMsgQuParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFKnownMsgQuParams.o $(SRCPATH)/wrapper/JDFKnownMsgQuParams.cpp

$(OBJPATH)/JDFLabelingParams.o: $(SRCPATH)/wrapper/JDFLabelingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFLabelingParams.o $(SRCPATH)/wrapper/JDFLabelingParams.cpp

$(OBJPATH)/JDFLaminatingIntent.o: $(SRCPATH)/wrapper/JDFLaminatingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFLaminatingIntent.o $(SRCPATH)/wrapper/JDFLaminatingIntent.cpp

$(OBJPATH)/JDFLaminatingParams.o: $(SRCPATH)/wrapper/JDFLaminatingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFLaminatingParams.o $(SRCPATH)/wrapper/JDFLaminatingParams.cpp

$(OBJPATH)/JDFLayerDetails.o: $(SRCPATH)/wrapper/JDFLayerDetails.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFLayerDetails.o $(SRCPATH)/wrapper/JDFLayerDetails.cpp

$(OBJPATH)/JDFLayerList.o: $(SRCPATH)/wrapper/JDFLayerList.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFLayerList.o $(SRCPATH)/wrapper/JDFLayerList.cpp

$(OBJPATH)/JDFLayout.o: $(SRCPATH)/wrapper/JDFLayout.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFLayout.o $(SRCPATH)/wrapper/JDFLayout.cpp

$(OBJPATH)/JDFLayoutElement.o: $(SRCPATH)/wrapper/JDFLayoutElement.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFLayoutElement.o $(SRCPATH)/wrapper/JDFLayoutElement.cpp

$(OBJPATH)/JDFLayoutIntent.o: $(SRCPATH)/wrapper/JDFLayoutIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFLayoutIntent.o $(SRCPATH)/wrapper/JDFLayoutIntent.cpp

$(OBJPATH)/JDFLayoutPreparationParams.o: $(SRCPATH)/wrapper/JDFLayoutPreparationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFLayoutPreparationParams.o $(SRCPATH)/wrapper/JDFLayoutPreparationParams.cpp

$(OBJPATH)/JDFLocation.o: $(SRCPATH)/wrapper/JDFLocation.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFLocation.o $(SRCPATH)/wrapper/JDFLocation.cpp

$(OBJPATH)/JDFLongFold.o: $(SRCPATH)/wrapper/JDFLongFold.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFLongFold.o $(SRCPATH)/wrapper/JDFLongFold.cpp

$(OBJPATH)/JDFLongGlue.o: $(SRCPATH)/wrapper/JDFLongGlue.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFLongGlue.o $(SRCPATH)/wrapper/JDFLongGlue.cpp

$(OBJPATH)/JDFLongPerforate.o: $(SRCPATH)/wrapper/JDFLongPerforate.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFLongPerforate.o $(SRCPATH)/wrapper/JDFLongPerforate.cpp

$(OBJPATH)/JDFLongSlit.o: $(SRCPATH)/wrapper/JDFLongSlit.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFLongSlit.o $(SRCPATH)/wrapper/JDFLongSlit.cpp

$(OBJPATH)/JDFLongitudinalRibbonOperationParams.o: $(SRCPATH)/wrapper/JDFLongitudinalRibbonOperationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFLongitudinalRibbonOperationParams.o $(SRCPATH)/wrapper/JDFLongitudinalRibbonOperationParams.cpp

$(OBJPATH)/JDFManualLaborParams.o: $(SRCPATH)/wrapper/JDFManualLaborParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFManualLaborParams.o $(SRCPATH)/wrapper/JDFManualLaborParams.cpp

$(OBJPATH)/JDFMarkObject.o: $(SRCPATH)/wrapper/JDFMarkObject.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFMarkObject.o $(SRCPATH)/wrapper/JDFMarkObject.cpp

$(OBJPATH)/JDFMedia.o: $(SRCPATH)/wrapper/JDFMedia.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFMedia.o $(SRCPATH)/wrapper/JDFMedia.cpp

$(OBJPATH)/JDFMediaIntent.o: $(SRCPATH)/wrapper/JDFMediaIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFMediaIntent.o $(SRCPATH)/wrapper/JDFMediaIntent.cpp

$(OBJPATH)/JDFMediaSource.o: $(SRCPATH)/wrapper/JDFMediaSource.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFMediaSource.o $(SRCPATH)/wrapper/JDFMediaSource.cpp

$(OBJPATH)/JDFMerged.o: $(SRCPATH)/wrapper/JDFMerged.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFMerged.o $(SRCPATH)/wrapper/JDFMerged.cpp

$(OBJPATH)/JDFMessage.o: $(SRCPATH)/wrapper/JDFMessage.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFMessage.o $(SRCPATH)/wrapper/JDFMessage.cpp

$(OBJPATH)/JDFMessageElement.o: $(SRCPATH)/wrapper/JDFMessageElement.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFMessageElement.o $(SRCPATH)/wrapper/JDFMessageElement.cpp

$(OBJPATH)/JDFMessageService.o: $(SRCPATH)/wrapper/JDFMessageService.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFMessageService.o $(SRCPATH)/wrapper/JDFMessageService.cpp

$(OBJPATH)/JDFModified.o: $(SRCPATH)/wrapper/JDFModified.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFModified.o $(SRCPATH)/wrapper/JDFModified.cpp

$(OBJPATH)/JDFModulePhase.o: $(SRCPATH)/wrapper/JDFModulePhase.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFModulePhase.o $(SRCPATH)/wrapper/JDFModulePhase.cpp

$(OBJPATH)/JDFModuleStatus.o: $(SRCPATH)/wrapper/JDFModuleStatus.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFModuleStatus.o $(SRCPATH)/wrapper/JDFModuleStatus.cpp

$(OBJPATH)/JDFMsgFilter.o: $(SRCPATH)/wrapper/JDFMsgFilter.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFMsgFilter.o $(SRCPATH)/wrapper/JDFMsgFilter.cpp

$(OBJPATH)/JDFNode.o: $(SRCPATH)/wrapper/JDFNode.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNode.o $(SRCPATH)/wrapper/JDFNode.cpp

$(OBJPATH)/JDFNodeAdhesiveBinding.o: $(SRCPATH)/wrapper/JDFNodeAdhesiveBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeAdhesiveBinding.o $(SRCPATH)/wrapper/JDFNodeAdhesiveBinding.cpp

$(OBJPATH)/JDFNodeBlockPreparation.o: $(SRCPATH)/wrapper/JDFNodeBlockPreparation.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeBlockPreparation.o $(SRCPATH)/wrapper/JDFNodeBlockPreparation.cpp

$(OBJPATH)/JDFNodeBoxPacking.o: $(SRCPATH)/wrapper/JDFNodeBoxPacking.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeBoxPacking.o $(SRCPATH)/wrapper/JDFNodeBoxPacking.cpp

$(OBJPATH)/JDFNodeCaseMaking.o: $(SRCPATH)/wrapper/JDFNodeCaseMaking.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeCaseMaking.o $(SRCPATH)/wrapper/JDFNodeCaseMaking.cpp

$(OBJPATH)/JDFNodeCasingIn.o: $(SRCPATH)/wrapper/JDFNodeCasingIn.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeCasingIn.o $(SRCPATH)/wrapper/JDFNodeCasingIn.cpp

$(OBJPATH)/JDFNodeChannelBinding.o: $(SRCPATH)/wrapper/JDFNodeChannelBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeChannelBinding.o $(SRCPATH)/wrapper/JDFNodeChannelBinding.cpp

$(OBJPATH)/JDFNodeCoilBinding.o: $(SRCPATH)/wrapper/JDFNodeCoilBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeCoilBinding.o $(SRCPATH)/wrapper/JDFNodeCoilBinding.cpp

$(OBJPATH)/JDFNodeCollecting.o: $(SRCPATH)/wrapper/JDFNodeCollecting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeCollecting.o $(SRCPATH)/wrapper/JDFNodeCollecting.cpp

$(OBJPATH)/JDFNodeColorCorrection.o: $(SRCPATH)/wrapper/JDFNodeColorCorrection.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeColorCorrection.o $(SRCPATH)/wrapper/JDFNodeColorCorrection.cpp

$(OBJPATH)/JDFNodeColorSpaceConversion.o: $(SRCPATH)/wrapper/JDFNodeColorSpaceConversion.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeColorSpaceConversion.o $(SRCPATH)/wrapper/JDFNodeColorSpaceConversion.cpp

$(OBJPATH)/JDFNodeCombined.o: $(SRCPATH)/wrapper/JDFNodeCombined.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeCombined.o $(SRCPATH)/wrapper/JDFNodeCombined.cpp

$(OBJPATH)/JDFNodeContactCopying.o: $(SRCPATH)/wrapper/JDFNodeContactCopying.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeContactCopying.o $(SRCPATH)/wrapper/JDFNodeContactCopying.cpp

$(OBJPATH)/JDFNodeContoneCalibration.o: $(SRCPATH)/wrapper/JDFNodeContoneCalibration.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeContoneCalibration.o $(SRCPATH)/wrapper/JDFNodeContoneCalibration.cpp

$(OBJPATH)/JDFNodeConventionalPrinting.o: $(SRCPATH)/wrapper/JDFNodeConventionalPrinting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeConventionalPrinting.o $(SRCPATH)/wrapper/JDFNodeConventionalPrinting.cpp

$(OBJPATH)/JDFNodeCoverApplication.o: $(SRCPATH)/wrapper/JDFNodeCoverApplication.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeCoverApplication.o $(SRCPATH)/wrapper/JDFNodeCoverApplication.cpp

$(OBJPATH)/JDFNodeCutting.o: $(SRCPATH)/wrapper/JDFNodeCutting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeCutting.o $(SRCPATH)/wrapper/JDFNodeCutting.cpp

$(OBJPATH)/JDFNodeDBDocTemplateLayout.o: $(SRCPATH)/wrapper/JDFNodeDBDocTemplateLayout.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeDBDocTemplateLayout.o $(SRCPATH)/wrapper/JDFNodeDBDocTemplateLayout.cpp

$(OBJPATH)/JDFNodeDBTemplateMerging.o: $(SRCPATH)/wrapper/JDFNodeDBTemplateMerging.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeDBTemplateMerging.o $(SRCPATH)/wrapper/JDFNodeDBTemplateMerging.cpp

$(OBJPATH)/JDFNodeDigitalPrinting.o: $(SRCPATH)/wrapper/JDFNodeDigitalPrinting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeDigitalPrinting.o $(SRCPATH)/wrapper/JDFNodeDigitalPrinting.cpp

$(OBJPATH)/JDFNodeDividing.o: $(SRCPATH)/wrapper/JDFNodeDividing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeDividing.o $(SRCPATH)/wrapper/JDFNodeDividing.cpp

$(OBJPATH)/JDFNodeEmbossing.o: $(SRCPATH)/wrapper/JDFNodeEmbossing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeEmbossing.o $(SRCPATH)/wrapper/JDFNodeEmbossing.cpp

$(OBJPATH)/JDFNodeEndSheetGluing.o: $(SRCPATH)/wrapper/JDFNodeEndSheetGluing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeEndSheetGluing.o $(SRCPATH)/wrapper/JDFNodeEndSheetGluing.cpp

$(OBJPATH)/JDFNodeFactory.o: $(SRCPATH)/wrapper/JDFNodeFactory.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeFactory.o $(SRCPATH)/wrapper/JDFNodeFactory.cpp

$(OBJPATH)/JDFNodeFilmToPlateCopying.o: $(SRCPATH)/wrapper/JDFNodeFilmToPlateCopying.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeFilmToPlateCopying.o $(SRCPATH)/wrapper/JDFNodeFilmToPlateCopying.cpp

$(OBJPATH)/JDFNodeFolding.o: $(SRCPATH)/wrapper/JDFNodeFolding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeFolding.o $(SRCPATH)/wrapper/JDFNodeFolding.cpp

$(OBJPATH)/JDFNodeFormatConversion.o: $(SRCPATH)/wrapper/JDFNodeFormatConversion.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeFormatConversion.o $(SRCPATH)/wrapper/JDFNodeFormatConversion.cpp

$(OBJPATH)/JDFNodeGathering.o: $(SRCPATH)/wrapper/JDFNodeGathering.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeGathering.o $(SRCPATH)/wrapper/JDFNodeGathering.cpp

$(OBJPATH)/JDFNodeGluing.o: $(SRCPATH)/wrapper/JDFNodeGluing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeGluing.o $(SRCPATH)/wrapper/JDFNodeGluing.cpp

$(OBJPATH)/JDFNodeHeadBandApplication.o: $(SRCPATH)/wrapper/JDFNodeHeadBandApplication.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeHeadBandApplication.o $(SRCPATH)/wrapper/JDFNodeHeadBandApplication.cpp

$(OBJPATH)/JDFNodeHoleMaking.o: $(SRCPATH)/wrapper/JDFNodeHoleMaking.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeHoleMaking.o $(SRCPATH)/wrapper/JDFNodeHoleMaking.cpp

$(OBJPATH)/JDFNodeIDPrinting.o: $(SRCPATH)/wrapper/JDFNodeIDPrinting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeIDPrinting.o $(SRCPATH)/wrapper/JDFNodeIDPrinting.cpp

$(OBJPATH)/JDFNodeImageReplacement.o: $(SRCPATH)/wrapper/JDFNodeImageReplacement.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeImageReplacement.o $(SRCPATH)/wrapper/JDFNodeImageReplacement.cpp

$(OBJPATH)/JDFNodeImageSetting.o: $(SRCPATH)/wrapper/JDFNodeImageSetting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeImageSetting.o $(SRCPATH)/wrapper/JDFNodeImageSetting.cpp

$(OBJPATH)/JDFNodeImposition.o: $(SRCPATH)/wrapper/JDFNodeImposition.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeImposition.o $(SRCPATH)/wrapper/JDFNodeImposition.cpp

$(OBJPATH)/JDFNodeInfo.o: $(SRCPATH)/wrapper/JDFNodeInfo.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeInfo.o $(SRCPATH)/wrapper/JDFNodeInfo.cpp

$(OBJPATH)/JDFNodeInkZoneCalculation.o: $(SRCPATH)/wrapper/JDFNodeInkZoneCalculation.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeInkZoneCalculation.o $(SRCPATH)/wrapper/JDFNodeInkZoneCalculation.cpp

$(OBJPATH)/JDFNodeInserting.o: $(SRCPATH)/wrapper/JDFNodeInserting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeInserting.o $(SRCPATH)/wrapper/JDFNodeInserting.cpp

$(OBJPATH)/JDFNodeInterpreting.o: $(SRCPATH)/wrapper/JDFNodeInterpreting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeInterpreting.o $(SRCPATH)/wrapper/JDFNodeInterpreting.cpp

$(OBJPATH)/JDFNodeJacketing.o: $(SRCPATH)/wrapper/JDFNodeJacketing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeJacketing.o $(SRCPATH)/wrapper/JDFNodeJacketing.cpp

$(OBJPATH)/JDFNodeLabeling.o: $(SRCPATH)/wrapper/JDFNodeLabeling.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeLabeling.o $(SRCPATH)/wrapper/JDFNodeLabeling.cpp

$(OBJPATH)/JDFNodeLaminating.o: $(SRCPATH)/wrapper/JDFNodeLaminating.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeLaminating.o $(SRCPATH)/wrapper/JDFNodeLaminating.cpp

$(OBJPATH)/JDFNodeLayoutElementProduction.o: $(SRCPATH)/wrapper/JDFNodeLayoutElementProduction.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeLayoutElementProduction.o $(SRCPATH)/wrapper/JDFNodeLayoutElementProduction.cpp

$(OBJPATH)/JDFNodeLayoutPreparation.o: $(SRCPATH)/wrapper/JDFNodeLayoutPreparation.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeLayoutPreparation.o $(SRCPATH)/wrapper/JDFNodeLayoutPreparation.cpp

$(OBJPATH)/JDFNodeLongitudinalRibbonOperations.o: $(SRCPATH)/wrapper/JDFNodeLongitudinalRibbonOperations.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeLongitudinalRibbonOperations.o $(SRCPATH)/wrapper/JDFNodeLongitudinalRibbonOperations.cpp

$(OBJPATH)/JDFNodeNumbering.o: $(SRCPATH)/wrapper/JDFNodeNumbering.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeNumbering.o $(SRCPATH)/wrapper/JDFNodeNumbering.cpp

$(OBJPATH)/JDFNodePDFToPSConversion.o: $(SRCPATH)/wrapper/JDFNodePDFToPSConversion.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodePDFToPSConversion.o $(SRCPATH)/wrapper/JDFNodePDFToPSConversion.cpp

$(OBJPATH)/JDFNodePSToPDFConversion.o: $(SRCPATH)/wrapper/JDFNodePSToPDFConversion.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodePSToPDFConversion.o $(SRCPATH)/wrapper/JDFNodePSToPDFConversion.cpp

$(OBJPATH)/JDFNodePalletizing.o: $(SRCPATH)/wrapper/JDFNodePalletizing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodePalletizing.o $(SRCPATH)/wrapper/JDFNodePalletizing.cpp

$(OBJPATH)/JDFNodePlasticCombBinding.o: $(SRCPATH)/wrapper/JDFNodePlasticCombBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodePlasticCombBinding.o $(SRCPATH)/wrapper/JDFNodePlasticCombBinding.cpp

$(OBJPATH)/JDFNodePreflight.o: $(SRCPATH)/wrapper/JDFNodePreflight.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodePreflight.o $(SRCPATH)/wrapper/JDFNodePreflight.cpp

$(OBJPATH)/JDFNodePreviewGeneration.o: $(SRCPATH)/wrapper/JDFNodePreviewGeneration.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodePreviewGeneration.o $(SRCPATH)/wrapper/JDFNodePreviewGeneration.cpp

$(OBJPATH)/JDFNodeProcessGroup.o: $(SRCPATH)/wrapper/JDFNodeProcessGroup.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeProcessGroup.o $(SRCPATH)/wrapper/JDFNodeProcessGroup.cpp

$(OBJPATH)/JDFNodeProduct.o: $(SRCPATH)/wrapper/JDFNodeProduct.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeProduct.o $(SRCPATH)/wrapper/JDFNodeProduct.cpp

$(OBJPATH)/JDFNodeProofing.o: $(SRCPATH)/wrapper/JDFNodeProofing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeProofing.o $(SRCPATH)/wrapper/JDFNodeProofing.cpp

$(OBJPATH)/JDFNodeRendering.o: $(SRCPATH)/wrapper/JDFNodeRendering.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeRendering.o $(SRCPATH)/wrapper/JDFNodeRendering.cpp

$(OBJPATH)/JDFNodeRingBinding.o: $(SRCPATH)/wrapper/JDFNodeRingBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeRingBinding.o $(SRCPATH)/wrapper/JDFNodeRingBinding.cpp

$(OBJPATH)/JDFNodeSaddleStitching.o: $(SRCPATH)/wrapper/JDFNodeSaddleStitching.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeSaddleStitching.o $(SRCPATH)/wrapper/JDFNodeSaddleStitching.cpp

$(OBJPATH)/JDFNodeScanning.o: $(SRCPATH)/wrapper/JDFNodeScanning.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeScanning.o $(SRCPATH)/wrapper/JDFNodeScanning.cpp

$(OBJPATH)/JDFNodeScreening.o: $(SRCPATH)/wrapper/JDFNodeScreening.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeScreening.o $(SRCPATH)/wrapper/JDFNodeScreening.cpp

$(OBJPATH)/JDFNodeSeparation.o: $(SRCPATH)/wrapper/JDFNodeSeparation.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeSeparation.o $(SRCPATH)/wrapper/JDFNodeSeparation.cpp

$(OBJPATH)/JDFNodeShapeCutting.o: $(SRCPATH)/wrapper/JDFNodeShapeCutting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeShapeCutting.o $(SRCPATH)/wrapper/JDFNodeShapeCutting.cpp

$(OBJPATH)/JDFNodeShrinking.o: $(SRCPATH)/wrapper/JDFNodeShrinking.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeShrinking.o $(SRCPATH)/wrapper/JDFNodeShrinking.cpp

$(OBJPATH)/JDFNodeSideSewing.o: $(SRCPATH)/wrapper/JDFNodeSideSewing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeSideSewing.o $(SRCPATH)/wrapper/JDFNodeSideSewing.cpp

$(OBJPATH)/JDFNodeSoftProofing.o: $(SRCPATH)/wrapper/JDFNodeSoftProofing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeSoftProofing.o $(SRCPATH)/wrapper/JDFNodeSoftProofing.cpp

$(OBJPATH)/JDFNodeSpinePreparation.o: $(SRCPATH)/wrapper/JDFNodeSpinePreparation.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeSpinePreparation.o $(SRCPATH)/wrapper/JDFNodeSpinePreparation.cpp

$(OBJPATH)/JDFNodeSpineTaping.o: $(SRCPATH)/wrapper/JDFNodeSpineTaping.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeSpineTaping.o $(SRCPATH)/wrapper/JDFNodeSpineTaping.cpp

$(OBJPATH)/JDFNodeStacking.o: $(SRCPATH)/wrapper/JDFNodeStacking.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeStacking.o $(SRCPATH)/wrapper/JDFNodeStacking.cpp

$(OBJPATH)/JDFNodeStitching.o: $(SRCPATH)/wrapper/JDFNodeStitching.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeStitching.o $(SRCPATH)/wrapper/JDFNodeStitching.cpp

$(OBJPATH)/JDFNodeStrapping.o: $(SRCPATH)/wrapper/JDFNodeStrapping.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeStrapping.o $(SRCPATH)/wrapper/JDFNodeStrapping.cpp

$(OBJPATH)/JDFNodeThreadSealing.o: $(SRCPATH)/wrapper/JDFNodeThreadSealing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeThreadSealing.o $(SRCPATH)/wrapper/JDFNodeThreadSealing.cpp

$(OBJPATH)/JDFNodeThreadSewing.o: $(SRCPATH)/wrapper/JDFNodeThreadSewing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeThreadSewing.o $(SRCPATH)/wrapper/JDFNodeThreadSewing.cpp

$(OBJPATH)/JDFNodeTiling.o: $(SRCPATH)/wrapper/JDFNodeTiling.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeTiling.o $(SRCPATH)/wrapper/JDFNodeTiling.cpp

$(OBJPATH)/JDFNodeTrapping.o: $(SRCPATH)/wrapper/JDFNodeTrapping.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeTrapping.o $(SRCPATH)/wrapper/JDFNodeTrapping.cpp

$(OBJPATH)/JDFNodeTrimming.o: $(SRCPATH)/wrapper/JDFNodeTrimming.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeTrimming.o $(SRCPATH)/wrapper/JDFNodeTrimming.cpp

$(OBJPATH)/JDFNodeVeloBinding.o: $(SRCPATH)/wrapper/JDFNodeVeloBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeVeloBinding.o $(SRCPATH)/wrapper/JDFNodeVeloBinding.cpp

$(OBJPATH)/JDFNodeWireCombBinding.o: $(SRCPATH)/wrapper/JDFNodeWireCombBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeWireCombBinding.o $(SRCPATH)/wrapper/JDFNodeWireCombBinding.cpp

$(OBJPATH)/JDFNodeWrapping.o: $(SRCPATH)/wrapper/JDFNodeWrapping.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNodeWrapping.o $(SRCPATH)/wrapper/JDFNodeWrapping.cpp

$(OBJPATH)/JDFNotification.o: $(SRCPATH)/wrapper/JDFNotification.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNotification.o $(SRCPATH)/wrapper/JDFNotification.cpp

$(OBJPATH)/JDFNotificationDef.o: $(SRCPATH)/wrapper/JDFNotificationDef.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNotificationDef.o $(SRCPATH)/wrapper/JDFNotificationDef.cpp

$(OBJPATH)/JDFNotificationFilter.o: $(SRCPATH)/wrapper/JDFNotificationFilter.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNotificationFilter.o $(SRCPATH)/wrapper/JDFNotificationFilter.cpp

$(OBJPATH)/JDFNumberItem.o: $(SRCPATH)/wrapper/JDFNumberItem.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNumberItem.o $(SRCPATH)/wrapper/JDFNumberItem.cpp

$(OBJPATH)/JDFNumberingIntent.o: $(SRCPATH)/wrapper/JDFNumberingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNumberingIntent.o $(SRCPATH)/wrapper/JDFNumberingIntent.cpp

$(OBJPATH)/JDFNumberingParam.o: $(SRCPATH)/wrapper/JDFNumberingParam.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNumberingParam.o $(SRCPATH)/wrapper/JDFNumberingParam.cpp

$(OBJPATH)/JDFNumberingParams.o: $(SRCPATH)/wrapper/JDFNumberingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFNumberingParams.o $(SRCPATH)/wrapper/JDFNumberingParams.cpp

$(OBJPATH)/JDFObjectResolution.o: $(SRCPATH)/wrapper/JDFObjectResolution.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFObjectResolution.o $(SRCPATH)/wrapper/JDFObjectResolution.cpp

$(OBJPATH)/JDFObservationTarget.o: $(SRCPATH)/wrapper/JDFObservationTarget.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFObservationTarget.o $(SRCPATH)/wrapper/JDFObservationTarget.cpp

$(OBJPATH)/JDFOccupation.o: $(SRCPATH)/wrapper/JDFOccupation.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFOccupation.o $(SRCPATH)/wrapper/JDFOccupation.cpp

$(OBJPATH)/JDFOrderingParams.o: $(SRCPATH)/wrapper/JDFOrderingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFOrderingParams.o $(SRCPATH)/wrapper/JDFOrderingParams.cpp

$(OBJPATH)/JDFPDFInterpretingParams.o: $(SRCPATH)/wrapper/JDFPDFInterpretingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPDFInterpretingParams.o $(SRCPATH)/wrapper/JDFPDFInterpretingParams.cpp

$(OBJPATH)/JDFPDFToPSConversionParams.o: $(SRCPATH)/wrapper/JDFPDFToPSConversionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPDFToPSConversionParams.o $(SRCPATH)/wrapper/JDFPDFToPSConversionParams.cpp

$(OBJPATH)/JDFPDLResourceAlias.o: $(SRCPATH)/wrapper/JDFPDLResourceAlias.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPDLResourceAlias.o $(SRCPATH)/wrapper/JDFPDLResourceAlias.cpp

$(OBJPATH)/JDFPSToPDFConversionParams.o: $(SRCPATH)/wrapper/JDFPSToPDFConversionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPSToPDFConversionParams.o $(SRCPATH)/wrapper/JDFPSToPDFConversionParams.cpp

$(OBJPATH)/JDFPackingIntent.o: $(SRCPATH)/wrapper/JDFPackingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPackingIntent.o $(SRCPATH)/wrapper/JDFPackingIntent.cpp

$(OBJPATH)/JDFPackingParams.o: $(SRCPATH)/wrapper/JDFPackingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPackingParams.o $(SRCPATH)/wrapper/JDFPackingParams.cpp

$(OBJPATH)/JDFPageCell.o: $(SRCPATH)/wrapper/JDFPageCell.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPageCell.o $(SRCPATH)/wrapper/JDFPageCell.cpp

$(OBJPATH)/JDFPallet.o: $(SRCPATH)/wrapper/JDFPallet.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPallet.o $(SRCPATH)/wrapper/JDFPallet.cpp

$(OBJPATH)/JDFPalletizingParams.o: $(SRCPATH)/wrapper/JDFPalletizingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPalletizingParams.o $(SRCPATH)/wrapper/JDFPalletizingParams.cpp

$(OBJPATH)/JDFParamsFactory.o: $(SRCPATH)/wrapper/JDFParamsFactory.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFParamsFactory.o $(SRCPATH)/wrapper/JDFParamsFactory.cpp

$(OBJPATH)/JDFPart.o: $(SRCPATH)/wrapper/JDFPart.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPart.o $(SRCPATH)/wrapper/JDFPart.cpp

$(OBJPATH)/JDFPartAmount.o: $(SRCPATH)/wrapper/JDFPartAmount.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPartAmount.o $(SRCPATH)/wrapper/JDFPartAmount.cpp

$(OBJPATH)/JDFPartStatus.o: $(SRCPATH)/wrapper/JDFPartStatus.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPartStatus.o $(SRCPATH)/wrapper/JDFPartStatus.cpp

$(OBJPATH)/JDFPayment.o: $(SRCPATH)/wrapper/JDFPayment.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPayment.o $(SRCPATH)/wrapper/JDFPayment.cpp

$(OBJPATH)/JDFPerforate.o: $(SRCPATH)/wrapper/JDFPerforate.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPerforate.o $(SRCPATH)/wrapper/JDFPerforate.cpp

$(OBJPATH)/JDFPerforatingParams.o: $(SRCPATH)/wrapper/JDFPerforatingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPerforatingParams.o $(SRCPATH)/wrapper/JDFPerforatingParams.cpp

$(OBJPATH)/JDFPerson.o: $(SRCPATH)/wrapper/JDFPerson.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPerson.o $(SRCPATH)/wrapper/JDFPerson.cpp

$(OBJPATH)/JDFPhaseTime.o: $(SRCPATH)/wrapper/JDFPhaseTime.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPhaseTime.o $(SRCPATH)/wrapper/JDFPhaseTime.cpp

$(OBJPATH)/JDFPipeParams.o: $(SRCPATH)/wrapper/JDFPipeParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPipeParams.o $(SRCPATH)/wrapper/JDFPipeParams.cpp

$(OBJPATH)/JDFPixelColorant.o: $(SRCPATH)/wrapper/JDFPixelColorant.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPixelColorant.o $(SRCPATH)/wrapper/JDFPixelColorant.cpp

$(OBJPATH)/JDFPlaceHolder.o: $(SRCPATH)/wrapper/JDFPlaceHolder.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPlaceHolder.o $(SRCPATH)/wrapper/JDFPlaceHolder.cpp

$(OBJPATH)/JDFPlasticCombBinding.o: $(SRCPATH)/wrapper/JDFPlasticCombBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPlasticCombBinding.o $(SRCPATH)/wrapper/JDFPlasticCombBinding.cpp

$(OBJPATH)/JDFPlasticCombBindingParams.o: $(SRCPATH)/wrapper/JDFPlasticCombBindingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPlasticCombBindingParams.o $(SRCPATH)/wrapper/JDFPlasticCombBindingParams.cpp

$(OBJPATH)/JDFPlateCopyParams.o: $(SRCPATH)/wrapper/JDFPlateCopyParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPlateCopyParams.o $(SRCPATH)/wrapper/JDFPlateCopyParams.cpp

$(OBJPATH)/JDFPool.o: $(SRCPATH)/wrapper/JDFPool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPool.o $(SRCPATH)/wrapper/JDFPool.cpp

$(OBJPATH)/JDFPreflightAnalysis.o: $(SRCPATH)/wrapper/JDFPreflightAnalysis.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPreflightAnalysis.o $(SRCPATH)/wrapper/JDFPreflightAnalysis.cpp

$(OBJPATH)/JDFPreflightConstraint.o: $(SRCPATH)/wrapper/JDFPreflightConstraint.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPreflightConstraint.o $(SRCPATH)/wrapper/JDFPreflightConstraint.cpp

$(OBJPATH)/JDFPreflightConstraintsPool.o: $(SRCPATH)/wrapper/JDFPreflightConstraintsPool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPreflightConstraintsPool.o $(SRCPATH)/wrapper/JDFPreflightConstraintsPool.cpp

$(OBJPATH)/JDFPreflightDetail.o: $(SRCPATH)/wrapper/JDFPreflightDetail.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPreflightDetail.o $(SRCPATH)/wrapper/JDFPreflightDetail.cpp

$(OBJPATH)/JDFPreflightInstance.o: $(SRCPATH)/wrapper/JDFPreflightInstance.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPreflightInstance.o $(SRCPATH)/wrapper/JDFPreflightInstance.cpp

$(OBJPATH)/JDFPreflightInstanceDetail.o: $(SRCPATH)/wrapper/JDFPreflightInstanceDetail.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPreflightInstanceDetail.o $(SRCPATH)/wrapper/JDFPreflightInstanceDetail.cpp

$(OBJPATH)/JDFPreflightInventory.o: $(SRCPATH)/wrapper/JDFPreflightInventory.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPreflightInventory.o $(SRCPATH)/wrapper/JDFPreflightInventory.cpp

$(OBJPATH)/JDFPreflightProfile.o: $(SRCPATH)/wrapper/JDFPreflightProfile.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPreflightProfile.o $(SRCPATH)/wrapper/JDFPreflightProfile.cpp

$(OBJPATH)/JDFPreflightResultsPool.o: $(SRCPATH)/wrapper/JDFPreflightResultsPool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPreflightResultsPool.o $(SRCPATH)/wrapper/JDFPreflightResultsPool.cpp

$(OBJPATH)/JDFPreview.o: $(SRCPATH)/wrapper/JDFPreview.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPreview.o $(SRCPATH)/wrapper/JDFPreview.cpp

$(OBJPATH)/JDFPreviewGenerationParams.o: $(SRCPATH)/wrapper/JDFPreviewGenerationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPreviewGenerationParams.o $(SRCPATH)/wrapper/JDFPreviewGenerationParams.cpp

$(OBJPATH)/JDFPricing.o: $(SRCPATH)/wrapper/JDFPricing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFPricing.o $(SRCPATH)/wrapper/JDFPricing.cpp

$(OBJPATH)/JDFProcessRun.o: $(SRCPATH)/wrapper/JDFProcessRun.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFProcessRun.o $(SRCPATH)/wrapper/JDFProcessRun.cpp

$(OBJPATH)/JDFProductionIntent.o: $(SRCPATH)/wrapper/JDFProductionIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFProductionIntent.o $(SRCPATH)/wrapper/JDFProductionIntent.cpp

$(OBJPATH)/JDFProofItem.o: $(SRCPATH)/wrapper/JDFProofItem.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFProofItem.o $(SRCPATH)/wrapper/JDFProofItem.cpp

$(OBJPATH)/JDFProofingIntent.o: $(SRCPATH)/wrapper/JDFProofingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFProofingIntent.o $(SRCPATH)/wrapper/JDFProofingIntent.cpp

$(OBJPATH)/JDFProofingParams.o: $(SRCPATH)/wrapper/JDFProofingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFProofingParams.o $(SRCPATH)/wrapper/JDFProofingParams.cpp

$(OBJPATH)/JDFProperties.o: $(SRCPATH)/wrapper/JDFProperties.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFProperties.o $(SRCPATH)/wrapper/JDFProperties.cpp

$(OBJPATH)/JDFQuery.o: $(SRCPATH)/wrapper/JDFQuery.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFQuery.o $(SRCPATH)/wrapper/JDFQuery.cpp

$(OBJPATH)/JDFQueue.o: $(SRCPATH)/wrapper/JDFQueue.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFQueue.o $(SRCPATH)/wrapper/JDFQueue.cpp

$(OBJPATH)/JDFQueueEntry.o: $(SRCPATH)/wrapper/JDFQueueEntry.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFQueueEntry.o $(SRCPATH)/wrapper/JDFQueueEntry.cpp

$(OBJPATH)/JDFQueueEntryDef.o: $(SRCPATH)/wrapper/JDFQueueEntryDef.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFQueueEntryDef.o $(SRCPATH)/wrapper/JDFQueueEntryDef.cpp

$(OBJPATH)/JDFQueueEntryPosParams.o: $(SRCPATH)/wrapper/JDFQueueEntryPosParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFQueueEntryPosParams.o $(SRCPATH)/wrapper/JDFQueueEntryPosParams.cpp

$(OBJPATH)/JDFQueueEntryPriParams.o: $(SRCPATH)/wrapper/JDFQueueEntryPriParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFQueueEntryPriParams.o $(SRCPATH)/wrapper/JDFQueueEntryPriParams.cpp

$(OBJPATH)/JDFQueueSubmissionParams.o: $(SRCPATH)/wrapper/JDFQueueSubmissionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFQueueSubmissionParams.o $(SRCPATH)/wrapper/JDFQueueSubmissionParams.cpp

$(OBJPATH)/JDFRange.o: $(SRCPATH)/wrapper/JDFRange.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFRange.o $(SRCPATH)/wrapper/JDFRange.cpp

$(OBJPATH)/JDFRefElement.o: $(SRCPATH)/wrapper/JDFRefElement.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFRefElement.o $(SRCPATH)/wrapper/JDFRefElement.cpp

$(OBJPATH)/JDFRegisterMark.o: $(SRCPATH)/wrapper/JDFRegisterMark.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFRegisterMark.o $(SRCPATH)/wrapper/JDFRegisterMark.cpp

$(OBJPATH)/JDFRegisterRibbon.o: $(SRCPATH)/wrapper/JDFRegisterRibbon.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFRegisterRibbon.o $(SRCPATH)/wrapper/JDFRegisterRibbon.cpp

$(OBJPATH)/JDFRemoved.o: $(SRCPATH)/wrapper/JDFRemoved.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFRemoved.o $(SRCPATH)/wrapper/JDFRemoved.cpp

$(OBJPATH)/JDFRenderingParams.o: $(SRCPATH)/wrapper/JDFRenderingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFRenderingParams.o $(SRCPATH)/wrapper/JDFRenderingParams.cpp

$(OBJPATH)/JDFResource.o: $(SRCPATH)/wrapper/JDFResource.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFResource.o $(SRCPATH)/wrapper/JDFResource.cpp

$(OBJPATH)/JDFResourceAudit.o: $(SRCPATH)/wrapper/JDFResourceAudit.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFResourceAudit.o $(SRCPATH)/wrapper/JDFResourceAudit.cpp

$(OBJPATH)/JDFResourceCmdParams.o: $(SRCPATH)/wrapper/JDFResourceCmdParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFResourceCmdParams.o $(SRCPATH)/wrapper/JDFResourceCmdParams.cpp

$(OBJPATH)/JDFResourceDefinitionParams.o: $(SRCPATH)/wrapper/JDFResourceDefinitionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFResourceDefinitionParams.o $(SRCPATH)/wrapper/JDFResourceDefinitionParams.cpp

$(OBJPATH)/JDFResourceInfo.o: $(SRCPATH)/wrapper/JDFResourceInfo.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFResourceInfo.o $(SRCPATH)/wrapper/JDFResourceInfo.cpp

$(OBJPATH)/JDFResourceLink.o: $(SRCPATH)/wrapper/JDFResourceLink.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFResourceLink.o $(SRCPATH)/wrapper/JDFResourceLink.cpp

$(OBJPATH)/JDFResourceLinkPool.o: $(SRCPATH)/wrapper/JDFResourceLinkPool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFResourceLinkPool.o $(SRCPATH)/wrapper/JDFResourceLinkPool.cpp

$(OBJPATH)/JDFResourceParam.o: $(SRCPATH)/wrapper/JDFResourceParam.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFResourceParam.o $(SRCPATH)/wrapper/JDFResourceParam.cpp

$(OBJPATH)/JDFResourcePool.o: $(SRCPATH)/wrapper/JDFResourcePool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFResourcePool.o $(SRCPATH)/wrapper/JDFResourcePool.cpp

$(OBJPATH)/JDFResourceQuParams.o: $(SRCPATH)/wrapper/JDFResourceQuParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFResourceQuParams.o $(SRCPATH)/wrapper/JDFResourceQuParams.cpp

$(OBJPATH)/JDFResponse.o: $(SRCPATH)/wrapper/JDFResponse.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFResponse.o $(SRCPATH)/wrapper/JDFResponse.cpp

$(OBJPATH)/JDFResubmissionParams.o: $(SRCPATH)/wrapper/JDFResubmissionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFResubmissionParams.o $(SRCPATH)/wrapper/JDFResubmissionParams.cpp

$(OBJPATH)/JDFRingBinding.o: $(SRCPATH)/wrapper/JDFRingBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFRingBinding.o $(SRCPATH)/wrapper/JDFRingBinding.cpp

$(OBJPATH)/JDFRingBindingParams.o: $(SRCPATH)/wrapper/JDFRingBindingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFRingBindingParams.o $(SRCPATH)/wrapper/JDFRingBindingParams.cpp

$(OBJPATH)/JDFRoot.o: $(SRCPATH)/wrapper/JDFRoot.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFRoot.o $(SRCPATH)/wrapper/JDFRoot.cpp

$(OBJPATH)/JDFRunElement.o: $(SRCPATH)/wrapper/JDFRunElement.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFRunElement.o $(SRCPATH)/wrapper/JDFRunElement.cpp

$(OBJPATH)/JDFRunList.o: $(SRCPATH)/wrapper/JDFRunList.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFRunList.o $(SRCPATH)/wrapper/JDFRunList.cpp

$(OBJPATH)/JDFSaddleStitching.o: $(SRCPATH)/wrapper/JDFSaddleStitching.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSaddleStitching.o $(SRCPATH)/wrapper/JDFSaddleStitching.cpp

$(OBJPATH)/JDFSaddleStitchingParams.o: $(SRCPATH)/wrapper/JDFSaddleStitchingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSaddleStitchingParams.o $(SRCPATH)/wrapper/JDFSaddleStitchingParams.cpp

$(OBJPATH)/JDFScanParams.o: $(SRCPATH)/wrapper/JDFScanParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFScanParams.o $(SRCPATH)/wrapper/JDFScanParams.cpp

$(OBJPATH)/JDFScavengerArea.o: $(SRCPATH)/wrapper/JDFScavengerArea.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFScavengerArea.o $(SRCPATH)/wrapper/JDFScavengerArea.cpp

$(OBJPATH)/JDFScore.o: $(SRCPATH)/wrapper/JDFScore.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFScore.o $(SRCPATH)/wrapper/JDFScore.cpp

$(OBJPATH)/JDFScreenSelector.o: $(SRCPATH)/wrapper/JDFScreenSelector.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFScreenSelector.o $(SRCPATH)/wrapper/JDFScreenSelector.cpp

$(OBJPATH)/JDFScreeningParams.o: $(SRCPATH)/wrapper/JDFScreeningParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFScreeningParams.o $(SRCPATH)/wrapper/JDFScreeningParams.cpp

$(OBJPATH)/JDFSeparationControlParams.o: $(SRCPATH)/wrapper/JDFSeparationControlParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSeparationControlParams.o $(SRCPATH)/wrapper/JDFSeparationControlParams.cpp

$(OBJPATH)/JDFSeparationList.o: $(SRCPATH)/wrapper/JDFSeparationList.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSeparationList.o $(SRCPATH)/wrapper/JDFSeparationList.cpp

$(OBJPATH)/JDFSeparationSpec.o: $(SRCPATH)/wrapper/JDFSeparationSpec.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSeparationSpec.o $(SRCPATH)/wrapper/JDFSeparationSpec.cpp

$(OBJPATH)/JDFShapeCut.o: $(SRCPATH)/wrapper/JDFShapeCut.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFShapeCut.o $(SRCPATH)/wrapper/JDFShapeCut.cpp

$(OBJPATH)/JDFShapeCuttingIntent.o: $(SRCPATH)/wrapper/JDFShapeCuttingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFShapeCuttingIntent.o $(SRCPATH)/wrapper/JDFShapeCuttingIntent.cpp

$(OBJPATH)/JDFShapeCuttingParams.o: $(SRCPATH)/wrapper/JDFShapeCuttingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFShapeCuttingParams.o $(SRCPATH)/wrapper/JDFShapeCuttingParams.cpp

$(OBJPATH)/JDFShapeElement.o: $(SRCPATH)/wrapper/JDFShapeElement.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFShapeElement.o $(SRCPATH)/wrapper/JDFShapeElement.cpp

$(OBJPATH)/JDFSheet.o: $(SRCPATH)/wrapper/JDFSheet.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSheet.o $(SRCPATH)/wrapper/JDFSheet.cpp

$(OBJPATH)/JDFShrinkingParams.o: $(SRCPATH)/wrapper/JDFShrinkingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFShrinkingParams.o $(SRCPATH)/wrapper/JDFShrinkingParams.cpp

$(OBJPATH)/JDFSideSewing.o: $(SRCPATH)/wrapper/JDFSideSewing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSideSewing.o $(SRCPATH)/wrapper/JDFSideSewing.cpp

$(OBJPATH)/JDFSideSewingParams.o: $(SRCPATH)/wrapper/JDFSideSewingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSideSewingParams.o $(SRCPATH)/wrapper/JDFSideSewingParams.cpp

$(OBJPATH)/JDFSideStitching.o: $(SRCPATH)/wrapper/JDFSideStitching.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSideStitching.o $(SRCPATH)/wrapper/JDFSideStitching.cpp

$(OBJPATH)/JDFSignal.o: $(SRCPATH)/wrapper/JDFSignal.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSignal.o $(SRCPATH)/wrapper/JDFSignal.cpp

$(OBJPATH)/JDFSignature.o: $(SRCPATH)/wrapper/JDFSignature.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSignature.o $(SRCPATH)/wrapper/JDFSignature.cpp

$(OBJPATH)/JDFSizeIntent.o: $(SRCPATH)/wrapper/JDFSizeIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSizeIntent.o $(SRCPATH)/wrapper/JDFSizeIntent.cpp

$(OBJPATH)/JDFSoftCoverBinding.o: $(SRCPATH)/wrapper/JDFSoftCoverBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSoftCoverBinding.o $(SRCPATH)/wrapper/JDFSoftCoverBinding.cpp

$(OBJPATH)/JDFSpan.o: $(SRCPATH)/wrapper/JDFSpan.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSpan.o $(SRCPATH)/wrapper/JDFSpan.cpp

$(OBJPATH)/JDFSpawned.o: $(SRCPATH)/wrapper/JDFSpawned.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSpawned.o $(SRCPATH)/wrapper/JDFSpawned.cpp

$(OBJPATH)/JDFSpinePreparationParams.o: $(SRCPATH)/wrapper/JDFSpinePreparationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSpinePreparationParams.o $(SRCPATH)/wrapper/JDFSpinePreparationParams.cpp

$(OBJPATH)/JDFSpineTaping.o: $(SRCPATH)/wrapper/JDFSpineTaping.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSpineTaping.o $(SRCPATH)/wrapper/JDFSpineTaping.cpp

$(OBJPATH)/JDFSpineTapingParams.o: $(SRCPATH)/wrapper/JDFSpineTapingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSpineTapingParams.o $(SRCPATH)/wrapper/JDFSpineTapingParams.cpp

$(OBJPATH)/JDFStackingParams.o: $(SRCPATH)/wrapper/JDFStackingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFStackingParams.o $(SRCPATH)/wrapper/JDFStackingParams.cpp

$(OBJPATH)/JDFState.o: $(SRCPATH)/wrapper/JDFState.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFState.o $(SRCPATH)/wrapper/JDFState.cpp

$(OBJPATH)/JDFStatusPool.o: $(SRCPATH)/wrapper/JDFStatusPool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFStatusPool.o $(SRCPATH)/wrapper/JDFStatusPool.cpp

$(OBJPATH)/JDFStatusQuParams.o: $(SRCPATH)/wrapper/JDFStatusQuParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFStatusQuParams.o $(SRCPATH)/wrapper/JDFStatusQuParams.cpp

$(OBJPATH)/JDFStitchingParams.o: $(SRCPATH)/wrapper/JDFStitchingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFStitchingParams.o $(SRCPATH)/wrapper/JDFStitchingParams.cpp

$(OBJPATH)/JDFStopPersChParams.o: $(SRCPATH)/wrapper/JDFStopPersChParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFStopPersChParams.o $(SRCPATH)/wrapper/JDFStopPersChParams.cpp

$(OBJPATH)/JDFStrap.o: $(SRCPATH)/wrapper/JDFStrap.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFStrap.o $(SRCPATH)/wrapper/JDFStrap.cpp

$(OBJPATH)/JDFStrappingParams.o: $(SRCPATH)/wrapper/JDFStrappingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFStrappingParams.o $(SRCPATH)/wrapper/JDFStrappingParams.cpp

$(OBJPATH)/JDFStripBinding.o: $(SRCPATH)/wrapper/JDFStripBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFStripBinding.o $(SRCPATH)/wrapper/JDFStripBinding.cpp

$(OBJPATH)/JDFStripBindingParams.o: $(SRCPATH)/wrapper/JDFStripBindingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFStripBindingParams.o $(SRCPATH)/wrapper/JDFStripBindingParams.cpp

$(OBJPATH)/JDFSubmissionMethods.o: $(SRCPATH)/wrapper/JDFSubmissionMethods.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSubmissionMethods.o $(SRCPATH)/wrapper/JDFSubmissionMethods.cpp

$(OBJPATH)/JDFSubscription.o: $(SRCPATH)/wrapper/JDFSubscription.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSubscription.o $(SRCPATH)/wrapper/JDFSubscription.cpp

$(OBJPATH)/JDFSurface.o: $(SRCPATH)/wrapper/JDFSurface.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSurface.o $(SRCPATH)/wrapper/JDFSurface.cpp

$(OBJPATH)/JDFSystemTimeSet.o: $(SRCPATH)/wrapper/JDFSystemTimeSet.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFSystemTimeSet.o $(SRCPATH)/wrapper/JDFSystemTimeSet.cpp

$(OBJPATH)/JDFTabs.o: $(SRCPATH)/wrapper/JDFTabs.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFTabs.o $(SRCPATH)/wrapper/JDFTabs.cpp

$(OBJPATH)/JDFTape.o: $(SRCPATH)/wrapper/JDFTape.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFTape.o $(SRCPATH)/wrapper/JDFTape.cpp

$(OBJPATH)/JDFThinPDFParams.o: $(SRCPATH)/wrapper/JDFThinPDFParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFThinPDFParams.o $(SRCPATH)/wrapper/JDFThinPDFParams.cpp

$(OBJPATH)/JDFThreadSeal.o: $(SRCPATH)/wrapper/JDFThreadSeal.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFThreadSeal.o $(SRCPATH)/wrapper/JDFThreadSeal.cpp

$(OBJPATH)/JDFThreadSealing.o: $(SRCPATH)/wrapper/JDFThreadSealing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFThreadSealing.o $(SRCPATH)/wrapper/JDFThreadSealing.cpp

$(OBJPATH)/JDFThreadSealingParams.o: $(SRCPATH)/wrapper/JDFThreadSealingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFThreadSealingParams.o $(SRCPATH)/wrapper/JDFThreadSealingParams.cpp

$(OBJPATH)/JDFThreadSewing.o: $(SRCPATH)/wrapper/JDFThreadSewing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFThreadSewing.o $(SRCPATH)/wrapper/JDFThreadSewing.cpp

$(OBJPATH)/JDFThreadSewingParams.o: $(SRCPATH)/wrapper/JDFThreadSewingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFThreadSewingParams.o $(SRCPATH)/wrapper/JDFThreadSewingParams.cpp

$(OBJPATH)/JDFTile.o: $(SRCPATH)/wrapper/JDFTile.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFTile.o $(SRCPATH)/wrapper/JDFTile.cpp

$(OBJPATH)/JDFTool.o: $(SRCPATH)/wrapper/JDFTool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFTool.o $(SRCPATH)/wrapper/JDFTool.cpp

$(OBJPATH)/JDFTrackFilter.o: $(SRCPATH)/wrapper/JDFTrackFilter.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFTrackFilter.o $(SRCPATH)/wrapper/JDFTrackFilter.cpp

$(OBJPATH)/JDFTrackResult.o: $(SRCPATH)/wrapper/JDFTrackResult.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFTrackResult.o $(SRCPATH)/wrapper/JDFTrackResult.cpp

$(OBJPATH)/JDFTransferCurve.o: $(SRCPATH)/wrapper/JDFTransferCurve.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFTransferCurve.o $(SRCPATH)/wrapper/JDFTransferCurve.cpp

$(OBJPATH)/JDFTransferCurvePool.o: $(SRCPATH)/wrapper/JDFTransferCurvePool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFTransferCurvePool.o $(SRCPATH)/wrapper/JDFTransferCurvePool.cpp

$(OBJPATH)/JDFTransferCurveSet.o: $(SRCPATH)/wrapper/JDFTransferCurveSet.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFTransferCurveSet.o $(SRCPATH)/wrapper/JDFTransferCurveSet.cpp

$(OBJPATH)/JDFTransferFunctionControl.o: $(SRCPATH)/wrapper/JDFTransferFunctionControl.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFTransferFunctionControl.o $(SRCPATH)/wrapper/JDFTransferFunctionControl.cpp

$(OBJPATH)/JDFTrapRegion.o: $(SRCPATH)/wrapper/JDFTrapRegion.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFTrapRegion.o $(SRCPATH)/wrapper/JDFTrapRegion.cpp

$(OBJPATH)/JDFTrappingDetails.o: $(SRCPATH)/wrapper/JDFTrappingDetails.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFTrappingDetails.o $(SRCPATH)/wrapper/JDFTrappingDetails.cpp

$(OBJPATH)/JDFTrappingOrder.o: $(SRCPATH)/wrapper/JDFTrappingOrder.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFTrappingOrder.o $(SRCPATH)/wrapper/JDFTrappingOrder.cpp

$(OBJPATH)/JDFTrappingParams.o: $(SRCPATH)/wrapper/JDFTrappingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFTrappingParams.o $(SRCPATH)/wrapper/JDFTrappingParams.cpp

$(OBJPATH)/JDFTrigger.o: $(SRCPATH)/wrapper/JDFTrigger.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFTrigger.o $(SRCPATH)/wrapper/JDFTrigger.cpp

$(OBJPATH)/JDFTrimmingParams.o: $(SRCPATH)/wrapper/JDFTrimmingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFTrimmingParams.o $(SRCPATH)/wrapper/JDFTrimmingParams.cpp

$(OBJPATH)/JDFVeloBindingParams.o: $(SRCPATH)/wrapper/JDFVeloBindingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFVeloBindingParams.o $(SRCPATH)/wrapper/JDFVeloBindingParams.cpp

$(OBJPATH)/JDFVerificationParams.o: $(SRCPATH)/wrapper/JDFVerificationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFVerificationParams.o $(SRCPATH)/wrapper/JDFVerificationParams.cpp

$(OBJPATH)/JDFWireCombBinding.o: $(SRCPATH)/wrapper/JDFWireCombBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFWireCombBinding.o $(SRCPATH)/wrapper/JDFWireCombBinding.cpp

$(OBJPATH)/JDFWireCombBindingParams.o: $(SRCPATH)/wrapper/JDFWireCombBindingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFWireCombBindingParams.o $(SRCPATH)/wrapper/JDFWireCombBindingParams.cpp

$(OBJPATH)/JDFWrappingParams.o: $(SRCPATH)/wrapper/JDFWrappingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFWrappingParams.o $(SRCPATH)/wrapper/JDFWrappingParams.cpp

$(OBJPATH)/JDFAutoAcknowledge.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoAcknowledge.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoAcknowledge.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoAcknowledge.cpp

$(OBJPATH)/JDFAutoAdded.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoAdded.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoAdded.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoAdded.cpp

$(OBJPATH)/JDFAutoAddress.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoAddress.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoAddress.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoAddress.cpp

$(OBJPATH)/JDFAutoAdhesiveBinding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoAdhesiveBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoAdhesiveBinding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoAdhesiveBinding.cpp

$(OBJPATH)/JDFAutoAdhesiveBindingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoAdhesiveBindingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoAdhesiveBindingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoAdhesiveBindingParams.cpp

$(OBJPATH)/JDFAutoAdvancedParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoAdvancedParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoAdvancedParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoAdvancedParams.cpp

$(OBJPATH)/JDFAutoAmountPool.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoAmountPool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoAmountPool.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoAmountPool.cpp

$(OBJPATH)/JDFAutoAncestor.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoAncestor.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoAncestor.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoAncestor.cpp

$(OBJPATH)/JDFAutoAncestorPool.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoAncestorPool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoAncestorPool.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoAncestorPool.cpp

$(OBJPATH)/JDFAutoApprovalParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoApprovalParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoApprovalParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoApprovalParams.cpp

$(OBJPATH)/JDFAutoApprovalPerson.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoApprovalPerson.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoApprovalPerson.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoApprovalPerson.cpp

$(OBJPATH)/JDFAutoApprovalSuccess.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoApprovalSuccess.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoApprovalSuccess.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoApprovalSuccess.cpp

$(OBJPATH)/JDFAutoArtDelivery.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoArtDelivery.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoArtDelivery.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoArtDelivery.cpp

$(OBJPATH)/JDFAutoArtDeliveryIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoArtDeliveryIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoArtDeliveryIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoArtDeliveryIntent.cpp

$(OBJPATH)/JDFAutoAutomatedOverprintParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoAutomatedOverprintParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoAutomatedOverprintParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoAutomatedOverprintParams.cpp

$(OBJPATH)/JDFAutoBackPreparation.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoBackPreparation.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoBackPreparation.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoBackPreparation.cpp

$(OBJPATH)/JDFAutoBand.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoBand.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoBand.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoBand.cpp

$(OBJPATH)/JDFAutoBarcode.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoBarcode.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoBarcode.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoBarcode.cpp

$(OBJPATH)/JDFAutoBindItem.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoBindItem.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoBindItem.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoBindItem.cpp

$(OBJPATH)/JDFAutoBindList.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoBindList.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoBindList.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoBindList.cpp

$(OBJPATH)/JDFAutoBindingIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoBindingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoBindingIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoBindingIntent.cpp

$(OBJPATH)/JDFAutoBlockPreparationParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoBlockPreparationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoBlockPreparationParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoBlockPreparationParams.cpp

$(OBJPATH)/JDFAutoBookCase.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoBookCase.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoBookCase.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoBookCase.cpp

$(OBJPATH)/JDFAutoBoxPackingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoBoxPackingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoBoxPackingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoBoxPackingParams.cpp

$(OBJPATH)/JDFAutoBufferParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoBufferParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoBufferParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoBufferParams.cpp

$(OBJPATH)/JDFAutoBundle.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoBundle.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoBundle.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoBundle.cpp

$(OBJPATH)/JDFAutoBundleItem.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoBundleItem.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoBundleItem.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoBundleItem.cpp

$(OBJPATH)/JDFAutoBusinessInfo.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoBusinessInfo.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoBusinessInfo.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoBusinessInfo.cpp

$(OBJPATH)/JDFAutoByteMap.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoByteMap.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoByteMap.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoByteMap.cpp

$(OBJPATH)/JDFAutoCIELABMeasuringField.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCIELABMeasuringField.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCIELABMeasuringField.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCIELABMeasuringField.cpp

$(OBJPATH)/JDFAutoCaseMakingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCaseMakingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCaseMakingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCaseMakingParams.cpp

$(OBJPATH)/JDFAutoCasingInParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCasingInParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCasingInParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCasingInParams.cpp

$(OBJPATH)/JDFAutoChangedAttribute.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoChangedAttribute.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoChangedAttribute.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoChangedAttribute.cpp

$(OBJPATH)/JDFAutoChannelBinding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoChannelBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoChannelBinding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoChannelBinding.cpp

$(OBJPATH)/JDFAutoChannelBindingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoChannelBindingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoChannelBindingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoChannelBindingParams.cpp

$(OBJPATH)/JDFAutoCoilBinding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCoilBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCoilBinding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCoilBinding.cpp

$(OBJPATH)/JDFAutoCoilBindingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCoilBindingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCoilBindingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCoilBindingParams.cpp

$(OBJPATH)/JDFAutoCollectingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCollectingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCollectingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCollectingParams.cpp

$(OBJPATH)/JDFAutoColor.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoColor.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoColor.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoColor.cpp

$(OBJPATH)/JDFAutoColorControlStrip.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorControlStrip.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoColorControlStrip.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorControlStrip.cpp

$(OBJPATH)/JDFAutoColorCorrectionOp.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorCorrectionOp.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoColorCorrectionOp.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorCorrectionOp.cpp

$(OBJPATH)/JDFAutoColorCorrectionParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorCorrectionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoColorCorrectionParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorCorrectionParams.cpp

$(OBJPATH)/JDFAutoColorIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoColorIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorIntent.cpp

$(OBJPATH)/JDFAutoColorMeasurementConditions.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorMeasurementConditions.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoColorMeasurementConditions.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorMeasurementConditions.cpp

$(OBJPATH)/JDFAutoColorPool.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorPool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoColorPool.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorPool.cpp

$(OBJPATH)/JDFAutoColorSpaceConversionOp.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorSpaceConversionOp.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoColorSpaceConversionOp.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorSpaceConversionOp.cpp

$(OBJPATH)/JDFAutoColorSpaceConversionParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorSpaceConversionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoColorSpaceConversionParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorSpaceConversionParams.cpp

$(OBJPATH)/JDFAutoColorSpaceSubstitute.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorSpaceSubstitute.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoColorSpaceSubstitute.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorSpaceSubstitute.cpp

$(OBJPATH)/JDFAutoColorantAlias.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorantAlias.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoColorantAlias.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorantAlias.cpp

$(OBJPATH)/JDFAutoColorantControl.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorantControl.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoColorantControl.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorantControl.cpp

$(OBJPATH)/JDFAutoColorantZoneDetails.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorantZoneDetails.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoColorantZoneDetails.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoColorantZoneDetails.cpp

$(OBJPATH)/JDFAutoComChannel.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoComChannel.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoComChannel.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoComChannel.cpp

$(OBJPATH)/JDFAutoCommand.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCommand.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCommand.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCommand.cpp

$(OBJPATH)/JDFAutoComment.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoComment.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoComment.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoComment.cpp

$(OBJPATH)/JDFAutoCompany.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCompany.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCompany.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCompany.cpp

$(OBJPATH)/JDFAutoComponent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoComponent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoComponent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoComponent.cpp

$(OBJPATH)/JDFAutoContact.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoContact.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoContact.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoContact.cpp

$(OBJPATH)/JDFAutoContactCopyParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoContactCopyParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoContactCopyParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoContactCopyParams.cpp

$(OBJPATH)/JDFAutoContentObject.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoContentObject.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoContentObject.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoContentObject.cpp

$(OBJPATH)/JDFAutoConventionalPrintingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoConventionalPrintingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoConventionalPrintingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoConventionalPrintingParams.cpp

$(OBJPATH)/JDFAutoCostCenter.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCostCenter.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCostCenter.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCostCenter.cpp

$(OBJPATH)/JDFAutoCounterReset.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCounterReset.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCounterReset.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCounterReset.cpp

$(OBJPATH)/JDFAutoCoverApplicationParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCoverApplicationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCoverApplicationParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCoverApplicationParams.cpp

$(OBJPATH)/JDFAutoCrease.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCrease.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCrease.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCrease.cpp

$(OBJPATH)/JDFAutoCreasingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCreasingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCreasingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCreasingParams.cpp

$(OBJPATH)/JDFAutoCreated.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCreated.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCreated.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCreated.cpp

$(OBJPATH)/JDFAutoCreditCard.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCreditCard.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCreditCard.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCreditCard.cpp

$(OBJPATH)/JDFAutoCustomerInfo.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCustomerInfo.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCustomerInfo.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCustomerInfo.cpp

$(OBJPATH)/JDFAutoCut.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCut.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCut.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCut.cpp

$(OBJPATH)/JDFAutoCutBlock.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCutBlock.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCutBlock.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCutBlock.cpp

$(OBJPATH)/JDFAutoCutMark.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCutMark.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCutMark.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCutMark.cpp

$(OBJPATH)/JDFAutoCuttingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoCuttingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoCuttingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoCuttingParams.cpp

$(OBJPATH)/JDFAutoDBMergeParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDBMergeParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDBMergeParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDBMergeParams.cpp

$(OBJPATH)/JDFAutoDBRules.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDBRules.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDBRules.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDBRules.cpp

$(OBJPATH)/JDFAutoDBSchema.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDBSchema.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDBSchema.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDBSchema.cpp

$(OBJPATH)/JDFAutoDBSelection.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDBSelection.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDBSelection.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDBSelection.cpp

$(OBJPATH)/JDFAutoDeliveryIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDeliveryIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDeliveryIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDeliveryIntent.cpp

$(OBJPATH)/JDFAutoDeliveryParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDeliveryParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDeliveryParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDeliveryParams.cpp

$(OBJPATH)/JDFAutoDensityMeasuringField.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDensityMeasuringField.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDensityMeasuringField.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDensityMeasuringField.cpp

$(OBJPATH)/JDFAutoDevCaps.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDevCaps.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDevCaps.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDevCaps.cpp

$(OBJPATH)/JDFAutoDevelopingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDevelopingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDevelopingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDevelopingParams.cpp

$(OBJPATH)/JDFAutoDevice.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDevice.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDevice.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDevice.cpp

$(OBJPATH)/JDFAutoDeviceFilter.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDeviceFilter.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDeviceFilter.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDeviceFilter.cpp

$(OBJPATH)/JDFAutoDeviceInfo.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDeviceInfo.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDeviceInfo.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDeviceInfo.cpp

$(OBJPATH)/JDFAutoDeviceList.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDeviceList.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDeviceList.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDeviceList.cpp

$(OBJPATH)/JDFAutoDeviceMark.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDeviceMark.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDeviceMark.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDeviceMark.cpp

$(OBJPATH)/JDFAutoDeviceNColor.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDeviceNColor.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDeviceNColor.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDeviceNColor.cpp

$(OBJPATH)/JDFAutoDeviceNSpace.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDeviceNSpace.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDeviceNSpace.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDeviceNSpace.cpp

$(OBJPATH)/JDFAutoDigitalPrintingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDigitalPrintingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDigitalPrintingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDigitalPrintingParams.cpp

$(OBJPATH)/JDFAutoDisjointing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDisjointing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDisjointing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDisjointing.cpp

$(OBJPATH)/JDFAutoDividingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDividingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDividingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDividingParams.cpp

$(OBJPATH)/JDFAutoDrop.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDrop.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDrop.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDrop.cpp

$(OBJPATH)/JDFAutoDropIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDropIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDropIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDropIntent.cpp

$(OBJPATH)/JDFAutoDropItem.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDropItem.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDropItem.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDropItem.cpp

$(OBJPATH)/JDFAutoDropItemIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDropItemIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDropItemIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDropItemIntent.cpp

$(OBJPATH)/JDFAutoDynamicField.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDynamicField.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDynamicField.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDynamicField.cpp

$(OBJPATH)/JDFAutoDynamicInput.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoDynamicInput.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoDynamicInput.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoDynamicInput.cpp

$(OBJPATH)/JDFAutoEdgeGluing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoEdgeGluing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoEdgeGluing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoEdgeGluing.cpp

$(OBJPATH)/JDFAutoEmboss.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoEmboss.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoEmboss.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoEmboss.cpp

$(OBJPATH)/JDFAutoEmbossingIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoEmbossingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoEmbossingIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoEmbossingIntent.cpp

$(OBJPATH)/JDFAutoEmbossingItem.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoEmbossingItem.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoEmbossingItem.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoEmbossingItem.cpp

$(OBJPATH)/JDFAutoEmbossingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoEmbossingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoEmbossingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoEmbossingParams.cpp

$(OBJPATH)/JDFAutoEmployee.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoEmployee.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoEmployee.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoEmployee.cpp

$(OBJPATH)/JDFAutoEmployeeDef.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoEmployeeDef.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoEmployeeDef.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoEmployeeDef.cpp

$(OBJPATH)/JDFAutoEndSheet.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoEndSheet.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoEndSheet.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoEndSheet.cpp

$(OBJPATH)/JDFAutoEndSheetGluingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoEndSheetGluingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoEndSheetGluingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoEndSheetGluingParams.cpp

$(OBJPATH)/JDFAutoEnumerationSpan.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoEnumerationSpan.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoEnumerationSpan.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoEnumerationSpan.cpp

$(OBJPATH)/JDFAutoError.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoError.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoError.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoError.cpp

$(OBJPATH)/JDFAutoExposedMedia.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoExposedMedia.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoExposedMedia.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoExposedMedia.cpp

$(OBJPATH)/JDFAutoFCNKey.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoFCNKey.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoFCNKey.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoFCNKey.cpp

$(OBJPATH)/JDFAutoFileAlias.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoFileAlias.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoFileAlias.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoFileAlias.cpp

$(OBJPATH)/JDFAutoFileSpec.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoFileSpec.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoFileSpec.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoFileSpec.cpp

$(OBJPATH)/JDFAutoFitPolicy.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoFitPolicy.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoFitPolicy.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoFitPolicy.cpp

$(OBJPATH)/JDFAutoFold.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoFold.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoFold.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoFold.cpp

$(OBJPATH)/JDFAutoFoldingIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoFoldingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoFoldingIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoFoldingIntent.cpp

$(OBJPATH)/JDFAutoFoldingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoFoldingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoFoldingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoFoldingParams.cpp

$(OBJPATH)/JDFAutoFontParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoFontParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoFontParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoFontParams.cpp

$(OBJPATH)/JDFAutoFontPolicy.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoFontPolicy.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoFontPolicy.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoFontPolicy.cpp

$(OBJPATH)/JDFAutoFormatConversionParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoFormatConversionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoFormatConversionParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoFormatConversionParams.cpp

$(OBJPATH)/JDFAutoGatheringParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoGatheringParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoGatheringParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoGatheringParams.cpp

$(OBJPATH)/JDFAutoGlue.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoGlue.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoGlue.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoGlue.cpp

$(OBJPATH)/JDFAutoGlueApplication.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoGlueApplication.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoGlueApplication.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoGlueApplication.cpp

$(OBJPATH)/JDFAutoGlueLine.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoGlueLine.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoGlueLine.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoGlueLine.cpp

$(OBJPATH)/JDFAutoGluingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoGluingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoGluingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoGluingParams.cpp

$(OBJPATH)/JDFAutoHardCoverBinding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoHardCoverBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoHardCoverBinding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoHardCoverBinding.cpp

$(OBJPATH)/JDFAutoHeadBandApplicationParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoHeadBandApplicationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoHeadBandApplicationParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoHeadBandApplicationParams.cpp

$(OBJPATH)/JDFAutoHole.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoHole.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoHole.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoHole.cpp

$(OBJPATH)/JDFAutoHoleLine.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoHoleLine.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoHoleLine.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoHoleLine.cpp

$(OBJPATH)/JDFAutoHoleList.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoHoleList.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoHoleList.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoHoleList.cpp

$(OBJPATH)/JDFAutoHoleMakingIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoHoleMakingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoHoleMakingIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoHoleMakingIntent.cpp

$(OBJPATH)/JDFAutoHoleMakingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoHoleMakingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoHoleMakingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoHoleMakingParams.cpp

$(OBJPATH)/JDFAutoIDPCover.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPCover.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoIDPCover.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPCover.cpp

$(OBJPATH)/JDFAutoIDPFinishing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPFinishing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoIDPFinishing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPFinishing.cpp

$(OBJPATH)/JDFAutoIDPFolding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPFolding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoIDPFolding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPFolding.cpp

$(OBJPATH)/JDFAutoIDPHoleMaking.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPHoleMaking.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoIDPHoleMaking.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPHoleMaking.cpp

$(OBJPATH)/JDFAutoIDPImageShift.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPImageShift.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoIDPImageShift.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPImageShift.cpp

$(OBJPATH)/JDFAutoIDPJobSheet.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPJobSheet.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoIDPJobSheet.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPJobSheet.cpp

$(OBJPATH)/JDFAutoIDPLayout.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPLayout.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoIDPLayout.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPLayout.cpp

$(OBJPATH)/JDFAutoIDPStitching.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPStitching.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoIDPStitching.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPStitching.cpp

$(OBJPATH)/JDFAutoIDPTrimming.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPTrimming.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoIDPTrimming.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPTrimming.cpp

$(OBJPATH)/JDFAutoIDPrintingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPrintingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoIDPrintingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoIDPrintingParams.cpp

$(OBJPATH)/JDFAutoIcon.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoIcon.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoIcon.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoIcon.cpp

$(OBJPATH)/JDFAutoIconList.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoIconList.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoIconList.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoIconList.cpp

$(OBJPATH)/JDFAutoIdentificationField.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoIdentificationField.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoIdentificationField.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoIdentificationField.cpp

$(OBJPATH)/JDFAutoImageCompression.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoImageCompression.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoImageCompression.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoImageCompression.cpp

$(OBJPATH)/JDFAutoImageCompressionParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoImageCompressionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoImageCompressionParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoImageCompressionParams.cpp

$(OBJPATH)/JDFAutoImageReplacementParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoImageReplacementParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoImageReplacementParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoImageReplacementParams.cpp

$(OBJPATH)/JDFAutoImageSetterParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoImageSetterParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoImageSetterParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoImageSetterParams.cpp

$(OBJPATH)/JDFAutoImageShift.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoImageShift.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoImageShift.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoImageShift.cpp

$(OBJPATH)/JDFAutoInk.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoInk.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoInk.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoInk.cpp

$(OBJPATH)/JDFAutoInkZoneCalculationParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoInkZoneCalculationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoInkZoneCalculationParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoInkZoneCalculationParams.cpp

$(OBJPATH)/JDFAutoInkZoneProfile.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoInkZoneProfile.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoInkZoneProfile.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoInkZoneProfile.cpp

$(OBJPATH)/JDFAutoInsert.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoInsert.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoInsert.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoInsert.cpp

$(OBJPATH)/JDFAutoInsertList.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoInsertList.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoInsertList.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoInsertList.cpp

$(OBJPATH)/JDFAutoInsertSheet.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoInsertSheet.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoInsertSheet.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoInsertSheet.cpp

$(OBJPATH)/JDFAutoInsertingIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoInsertingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoInsertingIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoInsertingIntent.cpp

$(OBJPATH)/JDFAutoInsertingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoInsertingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoInsertingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoInsertingParams.cpp

$(OBJPATH)/JDFAutoInterpretedPDLData.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoInterpretedPDLData.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoInterpretedPDLData.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoInterpretedPDLData.cpp

$(OBJPATH)/JDFAutoInterpretingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoInterpretingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoInterpretingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoInterpretingParams.cpp

$(OBJPATH)/JDFAutoJDFController.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoJDFController.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoJDFController.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoJDFController.cpp

$(OBJPATH)/JDFAutoJDFService.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoJDFService.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoJDFService.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoJDFService.cpp

$(OBJPATH)/JDFAutoJMF.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoJMF.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoJMF.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoJMF.cpp

$(OBJPATH)/JDFAutoJacketingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoJacketingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoJacketingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoJacketingParams.cpp

$(OBJPATH)/JDFAutoJobField.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoJobField.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoJobField.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoJobField.cpp

$(OBJPATH)/JDFAutoJobPhase.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoJobPhase.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoJobPhase.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoJobPhase.cpp

$(OBJPATH)/JDFAutoKnownMsgQuParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoKnownMsgQuParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoKnownMsgQuParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoKnownMsgQuParams.cpp

$(OBJPATH)/JDFAutoLabelingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoLabelingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoLabelingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoLabelingParams.cpp

$(OBJPATH)/JDFAutoLaminatingIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoLaminatingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoLaminatingIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoLaminatingIntent.cpp

$(OBJPATH)/JDFAutoLaminatingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoLaminatingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoLaminatingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoLaminatingParams.cpp

$(OBJPATH)/JDFAutoLayerDetails.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoLayerDetails.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoLayerDetails.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoLayerDetails.cpp

$(OBJPATH)/JDFAutoLayerList.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoLayerList.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoLayerList.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoLayerList.cpp

$(OBJPATH)/JDFAutoLayout.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoLayout.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoLayout.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoLayout.cpp

$(OBJPATH)/JDFAutoLayoutElement.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoLayoutElement.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoLayoutElement.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoLayoutElement.cpp

$(OBJPATH)/JDFAutoLayoutIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoLayoutIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoLayoutIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoLayoutIntent.cpp

$(OBJPATH)/JDFAutoLayoutPreparationParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoLayoutPreparationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoLayoutPreparationParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoLayoutPreparationParams.cpp

$(OBJPATH)/JDFAutoLocation.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoLocation.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoLocation.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoLocation.cpp

$(OBJPATH)/JDFAutoLongFold.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoLongFold.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoLongFold.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoLongFold.cpp

$(OBJPATH)/JDFAutoLongGlue.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoLongGlue.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoLongGlue.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoLongGlue.cpp

$(OBJPATH)/JDFAutoLongPerforate.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoLongPerforate.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoLongPerforate.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoLongPerforate.cpp

$(OBJPATH)/JDFAutoLongSlit.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoLongSlit.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoLongSlit.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoLongSlit.cpp

$(OBJPATH)/JDFAutoLongitudinalRibbonOperationParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoLongitudinalRibbonOperationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoLongitudinalRibbonOperationParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoLongitudinalRibbonOperationParams.cpp

$(OBJPATH)/JDFAutoManualLaborParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoManualLaborParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoManualLaborParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoManualLaborParams.cpp

$(OBJPATH)/JDFAutoMarkObject.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoMarkObject.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoMarkObject.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoMarkObject.cpp

$(OBJPATH)/JDFAutoMedia.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoMedia.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoMedia.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoMedia.cpp

$(OBJPATH)/JDFAutoMediaIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoMediaIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoMediaIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoMediaIntent.cpp

$(OBJPATH)/JDFAutoMediaSource.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoMediaSource.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoMediaSource.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoMediaSource.cpp

$(OBJPATH)/JDFAutoMerged.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoMerged.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoMerged.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoMerged.cpp

$(OBJPATH)/JDFAutoMessage.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoMessage.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoMessage.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoMessage.cpp

$(OBJPATH)/JDFAutoMessageService.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoMessageService.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoMessageService.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoMessageService.cpp

$(OBJPATH)/JDFAutoModified.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoModified.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoModified.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoModified.cpp

$(OBJPATH)/JDFAutoModulePhase.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoModulePhase.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoModulePhase.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoModulePhase.cpp

$(OBJPATH)/JDFAutoModuleStatus.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoModuleStatus.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoModuleStatus.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoModuleStatus.cpp

$(OBJPATH)/JDFAutoMsgFilter.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoMsgFilter.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoMsgFilter.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoMsgFilter.cpp

$(OBJPATH)/JDFAutoNodeAdhesiveBinding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeAdhesiveBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeAdhesiveBinding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeAdhesiveBinding.cpp

$(OBJPATH)/JDFAutoNodeBlockPreparation.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeBlockPreparation.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeBlockPreparation.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeBlockPreparation.cpp

$(OBJPATH)/JDFAutoNodeBoxPacking.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeBoxPacking.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeBoxPacking.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeBoxPacking.cpp

$(OBJPATH)/JDFAutoNodeCaseMaking.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeCaseMaking.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeCaseMaking.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeCaseMaking.cpp

$(OBJPATH)/JDFAutoNodeCasingIn.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeCasingIn.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeCasingIn.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeCasingIn.cpp

$(OBJPATH)/JDFAutoNodeChannelBinding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeChannelBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeChannelBinding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeChannelBinding.cpp

$(OBJPATH)/JDFAutoNodeCoilBinding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeCoilBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeCoilBinding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeCoilBinding.cpp

$(OBJPATH)/JDFAutoNodeCollecting.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeCollecting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeCollecting.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeCollecting.cpp

$(OBJPATH)/JDFAutoNodeColorCorrection.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeColorCorrection.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeColorCorrection.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeColorCorrection.cpp

$(OBJPATH)/JDFAutoNodeColorSpaceConversion.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeColorSpaceConversion.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeColorSpaceConversion.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeColorSpaceConversion.cpp

$(OBJPATH)/JDFAutoNodeContactCopying.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeContactCopying.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeContactCopying.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeContactCopying.cpp

$(OBJPATH)/JDFAutoNodeContoneCalibration.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeContoneCalibration.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeContoneCalibration.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeContoneCalibration.cpp

$(OBJPATH)/JDFAutoNodeConventionalPrinting.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeConventionalPrinting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeConventionalPrinting.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeConventionalPrinting.cpp

$(OBJPATH)/JDFAutoNodeCoverApplication.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeCoverApplication.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeCoverApplication.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeCoverApplication.cpp

$(OBJPATH)/JDFAutoNodeCutting.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeCutting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeCutting.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeCutting.cpp

$(OBJPATH)/JDFAutoNodeDBDocTemplateLayout.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeDBDocTemplateLayout.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeDBDocTemplateLayout.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeDBDocTemplateLayout.cpp

$(OBJPATH)/JDFAutoNodeDBTemplateMerging.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeDBTemplateMerging.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeDBTemplateMerging.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeDBTemplateMerging.cpp

$(OBJPATH)/JDFAutoNodeDigitalPrinting.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeDigitalPrinting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeDigitalPrinting.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeDigitalPrinting.cpp

$(OBJPATH)/JDFAutoNodeDividing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeDividing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeDividing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeDividing.cpp

$(OBJPATH)/JDFAutoNodeEmbossing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeEmbossing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeEmbossing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeEmbossing.cpp

$(OBJPATH)/JDFAutoNodeEndSheetGluing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeEndSheetGluing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeEndSheetGluing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeEndSheetGluing.cpp

$(OBJPATH)/JDFAutoNodeFilmToPlateCopying.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeFilmToPlateCopying.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeFilmToPlateCopying.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeFilmToPlateCopying.cpp

$(OBJPATH)/JDFAutoNodeFolding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeFolding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeFolding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeFolding.cpp

$(OBJPATH)/JDFAutoNodeFormatConversion.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeFormatConversion.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeFormatConversion.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeFormatConversion.cpp

$(OBJPATH)/JDFAutoNodeGathering.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeGathering.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeGathering.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeGathering.cpp

$(OBJPATH)/JDFAutoNodeGluing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeGluing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeGluing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeGluing.cpp

$(OBJPATH)/JDFAutoNodeHeadBandApplication.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeHeadBandApplication.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeHeadBandApplication.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeHeadBandApplication.cpp

$(OBJPATH)/JDFAutoNodeHoleMaking.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeHoleMaking.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeHoleMaking.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeHoleMaking.cpp

$(OBJPATH)/JDFAutoNodeIDPrinting.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeIDPrinting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeIDPrinting.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeIDPrinting.cpp

$(OBJPATH)/JDFAutoNodeImageReplacement.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeImageReplacement.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeImageReplacement.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeImageReplacement.cpp

$(OBJPATH)/JDFAutoNodeImageSetting.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeImageSetting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeImageSetting.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeImageSetting.cpp

$(OBJPATH)/JDFAutoNodeImposition.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeImposition.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeImposition.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeImposition.cpp

$(OBJPATH)/JDFAutoNodeInfo.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeInfo.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeInfo.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeInfo.cpp

$(OBJPATH)/JDFAutoNodeInkZoneCalculation.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeInkZoneCalculation.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeInkZoneCalculation.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeInkZoneCalculation.cpp

$(OBJPATH)/JDFAutoNodeInserting.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeInserting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeInserting.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeInserting.cpp

$(OBJPATH)/JDFAutoNodeInterpreting.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeInterpreting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeInterpreting.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeInterpreting.cpp

$(OBJPATH)/JDFAutoNodeJacketing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeJacketing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeJacketing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeJacketing.cpp

$(OBJPATH)/JDFAutoNodeLabeling.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeLabeling.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeLabeling.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeLabeling.cpp

$(OBJPATH)/JDFAutoNodeLaminating.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeLaminating.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeLaminating.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeLaminating.cpp

$(OBJPATH)/JDFAutoNodeLayoutElementProduction.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeLayoutElementProduction.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeLayoutElementProduction.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeLayoutElementProduction.cpp

$(OBJPATH)/JDFAutoNodeLayoutPreparation.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeLayoutPreparation.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeLayoutPreparation.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeLayoutPreparation.cpp

$(OBJPATH)/JDFAutoNodeLongitudinalRibbonOperations.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeLongitudinalRibbonOperations.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeLongitudinalRibbonOperations.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeLongitudinalRibbonOperations.cpp

$(OBJPATH)/JDFAutoNodeNumbering.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeNumbering.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeNumbering.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeNumbering.cpp

$(OBJPATH)/JDFAutoNodePDFToPSConversion.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodePDFToPSConversion.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodePDFToPSConversion.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodePDFToPSConversion.cpp

$(OBJPATH)/JDFAutoNodePSToPDFConversion.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodePSToPDFConversion.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodePSToPDFConversion.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodePSToPDFConversion.cpp

$(OBJPATH)/JDFAutoNodePalletizing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodePalletizing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodePalletizing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodePalletizing.cpp

$(OBJPATH)/JDFAutoNodePlasticCombBinding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodePlasticCombBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodePlasticCombBinding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodePlasticCombBinding.cpp

$(OBJPATH)/JDFAutoNodePreflight.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodePreflight.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodePreflight.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodePreflight.cpp

$(OBJPATH)/JDFAutoNodePreviewGeneration.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodePreviewGeneration.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodePreviewGeneration.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodePreviewGeneration.cpp

$(OBJPATH)/JDFAutoNodeProduct.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeProduct.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeProduct.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeProduct.cpp

$(OBJPATH)/JDFAutoNodeProofing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeProofing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeProofing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeProofing.cpp

$(OBJPATH)/JDFAutoNodeRendering.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeRendering.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeRendering.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeRendering.cpp

$(OBJPATH)/JDFAutoNodeRingBinding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeRingBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeRingBinding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeRingBinding.cpp

$(OBJPATH)/JDFAutoNodeSaddleStitching.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeSaddleStitching.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeSaddleStitching.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeSaddleStitching.cpp

$(OBJPATH)/JDFAutoNodeScanning.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeScanning.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeScanning.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeScanning.cpp

$(OBJPATH)/JDFAutoNodeScreening.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeScreening.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeScreening.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeScreening.cpp

$(OBJPATH)/JDFAutoNodeSeparation.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeSeparation.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeSeparation.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeSeparation.cpp

$(OBJPATH)/JDFAutoNodeShapeCutting.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeShapeCutting.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeShapeCutting.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeShapeCutting.cpp

$(OBJPATH)/JDFAutoNodeShrinking.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeShrinking.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeShrinking.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeShrinking.cpp

$(OBJPATH)/JDFAutoNodeSideSewing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeSideSewing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeSideSewing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeSideSewing.cpp

$(OBJPATH)/JDFAutoNodeSoftProofing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeSoftProofing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeSoftProofing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeSoftProofing.cpp

$(OBJPATH)/JDFAutoNodeSpinePreparation.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeSpinePreparation.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeSpinePreparation.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeSpinePreparation.cpp

$(OBJPATH)/JDFAutoNodeSpineTaping.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeSpineTaping.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeSpineTaping.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeSpineTaping.cpp

$(OBJPATH)/JDFAutoNodeStacking.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeStacking.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeStacking.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeStacking.cpp

$(OBJPATH)/JDFAutoNodeStitching.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeStitching.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeStitching.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeStitching.cpp

$(OBJPATH)/JDFAutoNodeStrapping.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeStrapping.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeStrapping.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeStrapping.cpp

$(OBJPATH)/JDFAutoNodeThreadSealing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeThreadSealing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeThreadSealing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeThreadSealing.cpp

$(OBJPATH)/JDFAutoNodeThreadSewing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeThreadSewing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeThreadSewing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeThreadSewing.cpp

$(OBJPATH)/JDFAutoNodeTiling.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeTiling.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeTiling.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeTiling.cpp

$(OBJPATH)/JDFAutoNodeTrapping.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeTrapping.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeTrapping.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeTrapping.cpp

$(OBJPATH)/JDFAutoNodeTrimming.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeTrimming.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeTrimming.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeTrimming.cpp

$(OBJPATH)/JDFAutoNodeVeloBinding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeVeloBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeVeloBinding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeVeloBinding.cpp

$(OBJPATH)/JDFAutoNodeWireCombBinding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeWireCombBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeWireCombBinding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeWireCombBinding.cpp

$(OBJPATH)/JDFAutoNodeWrapping.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeWrapping.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNodeWrapping.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNodeWrapping.cpp

$(OBJPATH)/JDFAutoNotification.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNotification.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNotification.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNotification.cpp

$(OBJPATH)/JDFAutoNotificationDef.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNotificationDef.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNotificationDef.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNotificationDef.cpp

$(OBJPATH)/JDFAutoNotificationFilter.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNotificationFilter.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNotificationFilter.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNotificationFilter.cpp

$(OBJPATH)/JDFAutoNumberItem.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNumberItem.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNumberItem.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNumberItem.cpp

$(OBJPATH)/JDFAutoNumberingIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNumberingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNumberingIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNumberingIntent.cpp

$(OBJPATH)/JDFAutoNumberingParam.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNumberingParam.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNumberingParam.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNumberingParam.cpp

$(OBJPATH)/JDFAutoNumberingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoNumberingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoNumberingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoNumberingParams.cpp

$(OBJPATH)/JDFAutoObjectResolution.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoObjectResolution.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoObjectResolution.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoObjectResolution.cpp

$(OBJPATH)/JDFAutoObservationTarget.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoObservationTarget.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoObservationTarget.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoObservationTarget.cpp

$(OBJPATH)/JDFAutoOccupation.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoOccupation.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoOccupation.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoOccupation.cpp

$(OBJPATH)/JDFAutoOrderingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoOrderingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoOrderingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoOrderingParams.cpp

$(OBJPATH)/JDFAutoPDFInterpretingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPDFInterpretingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPDFInterpretingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPDFInterpretingParams.cpp

$(OBJPATH)/JDFAutoPDFToPSConversionParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPDFToPSConversionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPDFToPSConversionParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPDFToPSConversionParams.cpp

$(OBJPATH)/JDFAutoPDLResourceAlias.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPDLResourceAlias.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPDLResourceAlias.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPDLResourceAlias.cpp

$(OBJPATH)/JDFAutoPSToPDFConversionParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPSToPDFConversionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPSToPDFConversionParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPSToPDFConversionParams.cpp

$(OBJPATH)/JDFAutoPackingIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPackingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPackingIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPackingIntent.cpp

$(OBJPATH)/JDFAutoPackingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPackingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPackingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPackingParams.cpp

$(OBJPATH)/JDFAutoPageCell.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPageCell.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPageCell.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPageCell.cpp

$(OBJPATH)/JDFAutoPallet.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPallet.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPallet.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPallet.cpp

$(OBJPATH)/JDFAutoPalletizingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPalletizingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPalletizingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPalletizingParams.cpp

$(OBJPATH)/JDFAutoPart.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPart.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPart.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPart.cpp

$(OBJPATH)/JDFAutoPartAmount.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPartAmount.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPartAmount.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPartAmount.cpp

$(OBJPATH)/JDFAutoPartStatus.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPartStatus.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPartStatus.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPartStatus.cpp

$(OBJPATH)/JDFAutoPayment.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPayment.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPayment.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPayment.cpp

$(OBJPATH)/JDFAutoPerforate.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPerforate.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPerforate.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPerforate.cpp

$(OBJPATH)/JDFAutoPerforatingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPerforatingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPerforatingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPerforatingParams.cpp

$(OBJPATH)/JDFAutoPerson.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPerson.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPerson.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPerson.cpp

$(OBJPATH)/JDFAutoPhaseTime.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPhaseTime.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPhaseTime.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPhaseTime.cpp

$(OBJPATH)/JDFAutoPipeParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPipeParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPipeParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPipeParams.cpp

$(OBJPATH)/JDFAutoPixelColorant.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPixelColorant.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPixelColorant.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPixelColorant.cpp

$(OBJPATH)/JDFAutoPlaceHolder.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPlaceHolder.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPlaceHolder.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPlaceHolder.cpp

$(OBJPATH)/JDFAutoPlasticCombBinding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPlasticCombBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPlasticCombBinding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPlasticCombBinding.cpp

$(OBJPATH)/JDFAutoPlasticCombBindingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPlasticCombBindingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPlasticCombBindingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPlasticCombBindingParams.cpp

$(OBJPATH)/JDFAutoPlateCopyParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPlateCopyParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPlateCopyParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPlateCopyParams.cpp

$(OBJPATH)/JDFAutoPreflightAnalysis.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreflightAnalysis.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPreflightAnalysis.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreflightAnalysis.cpp

$(OBJPATH)/JDFAutoPreflightConstraint.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreflightConstraint.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPreflightConstraint.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreflightConstraint.cpp

$(OBJPATH)/JDFAutoPreflightDetail.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreflightDetail.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPreflightDetail.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreflightDetail.cpp

$(OBJPATH)/JDFAutoPreflightInstance.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreflightInstance.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPreflightInstance.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreflightInstance.cpp

$(OBJPATH)/JDFAutoPreflightInstanceDetail.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreflightInstanceDetail.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPreflightInstanceDetail.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreflightInstanceDetail.cpp

$(OBJPATH)/JDFAutoPreflightInventory.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreflightInventory.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPreflightInventory.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreflightInventory.cpp

$(OBJPATH)/JDFAutoPreflightProfile.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreflightProfile.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPreflightProfile.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreflightProfile.cpp

$(OBJPATH)/JDFAutoPreview.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreview.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPreview.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreview.cpp

$(OBJPATH)/JDFAutoPreviewGenerationParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreviewGenerationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPreviewGenerationParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPreviewGenerationParams.cpp

$(OBJPATH)/JDFAutoPricing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoPricing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoPricing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoPricing.cpp

$(OBJPATH)/JDFAutoProcessRun.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoProcessRun.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoProcessRun.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoProcessRun.cpp

$(OBJPATH)/JDFAutoProductionIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoProductionIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoProductionIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoProductionIntent.cpp

$(OBJPATH)/JDFAutoProofItem.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoProofItem.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoProofItem.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoProofItem.cpp

$(OBJPATH)/JDFAutoProofingIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoProofingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoProofingIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoProofingIntent.cpp

$(OBJPATH)/JDFAutoProofingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoProofingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoProofingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoProofingParams.cpp

$(OBJPATH)/JDFAutoProperties.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoProperties.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoProperties.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoProperties.cpp

$(OBJPATH)/JDFAutoQuery.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoQuery.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoQuery.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoQuery.cpp

$(OBJPATH)/JDFAutoQueue.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoQueue.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoQueue.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoQueue.cpp

$(OBJPATH)/JDFAutoQueueEntry.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoQueueEntry.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoQueueEntry.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoQueueEntry.cpp

$(OBJPATH)/JDFAutoQueueEntryDef.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoQueueEntryDef.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoQueueEntryDef.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoQueueEntryDef.cpp

$(OBJPATH)/JDFAutoQueueEntryPosParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoQueueEntryPosParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoQueueEntryPosParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoQueueEntryPosParams.cpp

$(OBJPATH)/JDFAutoQueueEntryPriParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoQueueEntryPriParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoQueueEntryPriParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoQueueEntryPriParams.cpp

$(OBJPATH)/JDFAutoQueueSubmissionParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoQueueSubmissionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoQueueSubmissionParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoQueueSubmissionParams.cpp

$(OBJPATH)/JDFAutoRegisterMark.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoRegisterMark.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoRegisterMark.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoRegisterMark.cpp

$(OBJPATH)/JDFAutoRegisterRibbon.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoRegisterRibbon.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoRegisterRibbon.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoRegisterRibbon.cpp

$(OBJPATH)/JDFAutoRemoved.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoRemoved.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoRemoved.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoRemoved.cpp

$(OBJPATH)/JDFAutoRenderingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoRenderingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoRenderingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoRenderingParams.cpp

$(OBJPATH)/JDFAutoResourceAudit.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoResourceAudit.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoResourceAudit.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoResourceAudit.cpp

$(OBJPATH)/JDFAutoResourceCmdParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoResourceCmdParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoResourceCmdParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoResourceCmdParams.cpp

$(OBJPATH)/JDFAutoResourceDefinitionParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoResourceDefinitionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoResourceDefinitionParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoResourceDefinitionParams.cpp

$(OBJPATH)/JDFAutoResourceInfo.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoResourceInfo.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoResourceInfo.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoResourceInfo.cpp

$(OBJPATH)/JDFAutoResourceParam.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoResourceParam.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoResourceParam.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoResourceParam.cpp

$(OBJPATH)/JDFAutoResourceQuParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoResourceQuParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoResourceQuParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoResourceQuParams.cpp

$(OBJPATH)/JDFAutoResponse.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoResponse.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoResponse.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoResponse.cpp

$(OBJPATH)/JDFAutoResubmissionParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoResubmissionParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoResubmissionParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoResubmissionParams.cpp

$(OBJPATH)/JDFAutoRingBinding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoRingBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoRingBinding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoRingBinding.cpp

$(OBJPATH)/JDFAutoRingBindingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoRingBindingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoRingBindingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoRingBindingParams.cpp

$(OBJPATH)/JDFAutoRunList.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoRunList.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoRunList.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoRunList.cpp

$(OBJPATH)/JDFAutoSaddleStitching.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSaddleStitching.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSaddleStitching.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSaddleStitching.cpp

$(OBJPATH)/JDFAutoSaddleStitchingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSaddleStitchingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSaddleStitchingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSaddleStitchingParams.cpp

$(OBJPATH)/JDFAutoScanParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoScanParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoScanParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoScanParams.cpp

$(OBJPATH)/JDFAutoScavengerArea.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoScavengerArea.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoScavengerArea.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoScavengerArea.cpp

$(OBJPATH)/JDFAutoScore.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoScore.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoScore.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoScore.cpp

$(OBJPATH)/JDFAutoScreenSelector.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoScreenSelector.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoScreenSelector.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoScreenSelector.cpp

$(OBJPATH)/JDFAutoScreeningParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoScreeningParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoScreeningParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoScreeningParams.cpp

$(OBJPATH)/JDFAutoSeparationControlParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSeparationControlParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSeparationControlParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSeparationControlParams.cpp

$(OBJPATH)/JDFAutoSeparationSpec.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSeparationSpec.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSeparationSpec.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSeparationSpec.cpp

$(OBJPATH)/JDFAutoShapeCut.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoShapeCut.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoShapeCut.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoShapeCut.cpp

$(OBJPATH)/JDFAutoShapeCuttingIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoShapeCuttingIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoShapeCuttingIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoShapeCuttingIntent.cpp

$(OBJPATH)/JDFAutoShapeCuttingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoShapeCuttingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoShapeCuttingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoShapeCuttingParams.cpp

$(OBJPATH)/JDFAutoShapeElement.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoShapeElement.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoShapeElement.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoShapeElement.cpp

$(OBJPATH)/JDFAutoSheet.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSheet.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSheet.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSheet.cpp

$(OBJPATH)/JDFAutoShrinkingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoShrinkingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoShrinkingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoShrinkingParams.cpp

$(OBJPATH)/JDFAutoSideSewing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSideSewing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSideSewing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSideSewing.cpp

$(OBJPATH)/JDFAutoSideSewingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSideSewingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSideSewingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSideSewingParams.cpp

$(OBJPATH)/JDFAutoSideStitching.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSideStitching.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSideStitching.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSideStitching.cpp

$(OBJPATH)/JDFAutoSignal.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSignal.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSignal.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSignal.cpp

$(OBJPATH)/JDFAutoSignature.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSignature.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSignature.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSignature.cpp

$(OBJPATH)/JDFAutoSizeIntent.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSizeIntent.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSizeIntent.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSizeIntent.cpp

$(OBJPATH)/JDFAutoSoftCoverBinding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSoftCoverBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSoftCoverBinding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSoftCoverBinding.cpp

$(OBJPATH)/JDFAutoSpawned.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSpawned.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSpawned.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSpawned.cpp

$(OBJPATH)/JDFAutoSpinePreparationParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSpinePreparationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSpinePreparationParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSpinePreparationParams.cpp

$(OBJPATH)/JDFAutoSpineTaping.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSpineTaping.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSpineTaping.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSpineTaping.cpp

$(OBJPATH)/JDFAutoSpineTapingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSpineTapingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSpineTapingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSpineTapingParams.cpp

$(OBJPATH)/JDFAutoStackingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoStackingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoStackingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoStackingParams.cpp

$(OBJPATH)/JDFAutoStatusPool.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoStatusPool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoStatusPool.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoStatusPool.cpp

$(OBJPATH)/JDFAutoStatusQuParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoStatusQuParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoStatusQuParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoStatusQuParams.cpp

$(OBJPATH)/JDFAutoStitchingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoStitchingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoStitchingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoStitchingParams.cpp

$(OBJPATH)/JDFAutoStopPersChParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoStopPersChParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoStopPersChParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoStopPersChParams.cpp

$(OBJPATH)/JDFAutoStrap.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoStrap.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoStrap.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoStrap.cpp

$(OBJPATH)/JDFAutoStrappingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoStrappingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoStrappingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoStrappingParams.cpp

$(OBJPATH)/JDFAutoStripBinding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoStripBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoStripBinding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoStripBinding.cpp

$(OBJPATH)/JDFAutoStripBindingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoStripBindingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoStripBindingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoStripBindingParams.cpp

$(OBJPATH)/JDFAutoSubmissionMethods.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSubmissionMethods.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSubmissionMethods.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSubmissionMethods.cpp

$(OBJPATH)/JDFAutoSubscription.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSubscription.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSubscription.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSubscription.cpp

$(OBJPATH)/JDFAutoSurface.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSurface.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSurface.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSurface.cpp

$(OBJPATH)/JDFAutoSystemTimeSet.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoSystemTimeSet.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoSystemTimeSet.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoSystemTimeSet.cpp

$(OBJPATH)/JDFAutoTabs.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoTabs.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoTabs.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoTabs.cpp

$(OBJPATH)/JDFAutoTape.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoTape.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoTape.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoTape.cpp

$(OBJPATH)/JDFAutoThinPDFParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoThinPDFParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoThinPDFParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoThinPDFParams.cpp

$(OBJPATH)/JDFAutoThreadSeal.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoThreadSeal.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoThreadSeal.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoThreadSeal.cpp

$(OBJPATH)/JDFAutoThreadSealing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoThreadSealing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoThreadSealing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoThreadSealing.cpp

$(OBJPATH)/JDFAutoThreadSealingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoThreadSealingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoThreadSealingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoThreadSealingParams.cpp

$(OBJPATH)/JDFAutoThreadSewing.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoThreadSewing.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoThreadSewing.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoThreadSewing.cpp

$(OBJPATH)/JDFAutoThreadSewingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoThreadSewingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoThreadSewingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoThreadSewingParams.cpp

$(OBJPATH)/JDFAutoTile.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoTile.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoTile.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoTile.cpp

$(OBJPATH)/JDFAutoTool.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoTool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoTool.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoTool.cpp

$(OBJPATH)/JDFAutoTrackFilter.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoTrackFilter.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoTrackFilter.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoTrackFilter.cpp

$(OBJPATH)/JDFAutoTrackResult.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoTrackResult.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoTrackResult.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoTrackResult.cpp

$(OBJPATH)/JDFAutoTransferCurve.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoTransferCurve.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoTransferCurve.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoTransferCurve.cpp

$(OBJPATH)/JDFAutoTransferCurvePool.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoTransferCurvePool.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoTransferCurvePool.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoTransferCurvePool.cpp

$(OBJPATH)/JDFAutoTransferCurveSet.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoTransferCurveSet.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoTransferCurveSet.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoTransferCurveSet.cpp

$(OBJPATH)/JDFAutoTransferFunctionControl.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoTransferFunctionControl.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoTransferFunctionControl.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoTransferFunctionControl.cpp

$(OBJPATH)/JDFAutoTrapRegion.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoTrapRegion.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoTrapRegion.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoTrapRegion.cpp

$(OBJPATH)/JDFAutoTrappingDetails.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoTrappingDetails.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoTrappingDetails.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoTrappingDetails.cpp

$(OBJPATH)/JDFAutoTrappingOrder.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoTrappingOrder.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoTrappingOrder.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoTrappingOrder.cpp

$(OBJPATH)/JDFAutoTrappingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoTrappingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoTrappingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoTrappingParams.cpp

$(OBJPATH)/JDFAutoTrigger.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoTrigger.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoTrigger.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoTrigger.cpp

$(OBJPATH)/JDFAutoTrimmingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoTrimmingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoTrimmingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoTrimmingParams.cpp

$(OBJPATH)/JDFAutoVeloBindingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoVeloBindingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoVeloBindingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoVeloBindingParams.cpp

$(OBJPATH)/JDFAutoVerificationParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoVerificationParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoVerificationParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoVerificationParams.cpp

$(OBJPATH)/JDFAutoWireCombBinding.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoWireCombBinding.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoWireCombBinding.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoWireCombBinding.cpp

$(OBJPATH)/JDFAutoWireCombBindingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoWireCombBindingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoWireCombBindingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoWireCombBindingParams.cpp

$(OBJPATH)/JDFAutoWrappingParams.o: $(SRCPATH)/wrapper/AutoJDF/JDFAutoWrappingParams.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/JDFAutoWrappingParams.o $(SRCPATH)/wrapper/AutoJDF/JDFAutoWrappingParams.cpp

