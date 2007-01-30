# Microsoft Developer Studio Generated NMAKE File, Based on JDFWrapperLib.dsp
!IF "$(CFG)" == ""
CFG=JDFWrapperLib - Win32 Debug LineOnly
!MESSAGE No configuration specified. Defaulting to JDFWrapperLib - Win32 Debug LineOnly.
!ENDIF 

!IF "$(CFG)" != "JDFWrapperLib - Win32 Release DLL" && "$(CFG)" != "JDFWrapperLib - Win32 Debug DLL" && "$(CFG)" != "JDFWrapperLib - Win32 Debug" && "$(CFG)" != "JDFWrapperLib - Win32 Release" && "$(CFG)" != "JDFWrapperLib - Win32 Debug LineOnly"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "JDFWrapperLib.mak" CFG="JDFWrapperLib - Win32 Debug LineOnly"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "JDFWrapperLib - Win32 Release DLL" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "JDFWrapperLib - Win32 Debug DLL" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "JDFWrapperLib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "JDFWrapperLib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "JDFWrapperLib - Win32 Debug LineOnly" (based on "Win32 (x86) Static Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "JDFWrapperLib - Win32 Release DLL"

OUTDIR=.\..\..\..\Build\Win32\VC6\ReleaseDLL
INTDIR=.\..\..\..\Build\Win32\VC6\ReleaseDLL\obj\JDFWrapperDLL
# Begin Custom Macros
OutDir=.\..\..\..\Build\Win32\VC6\ReleaseDLL
# End Custom Macros

ALL : "$(OUTDIR)\JDFWrapperDLL.dll" "$(OUTDIR)\JDFWrapperLib.bsc"


CLEAN :
	-@erase "$(INTDIR)\JDFAcknowledge.obj"
	-@erase "$(INTDIR)\JDFAcknowledge.sbr"
	-@erase "$(INTDIR)\JDFAction.obj"
	-@erase "$(INTDIR)\JDFAction.sbr"
	-@erase "$(INTDIR)\JDFActionPool.obj"
	-@erase "$(INTDIR)\JDFActionPool.sbr"
	-@erase "$(INTDIR)\JDFAdded.obj"
	-@erase "$(INTDIR)\JDFAdded.sbr"
	-@erase "$(INTDIR)\JDFAddress.obj"
	-@erase "$(INTDIR)\JDFAddress.sbr"
	-@erase "$(INTDIR)\JDFAdhesiveBinding.obj"
	-@erase "$(INTDIR)\JDFAdhesiveBinding.sbr"
	-@erase "$(INTDIR)\JDFAdhesiveBindingParams.obj"
	-@erase "$(INTDIR)\JDFAdhesiveBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAdvancedParams.obj"
	-@erase "$(INTDIR)\JDFAdvancedParams.sbr"
	-@erase "$(INTDIR)\JDFAmountPool.obj"
	-@erase "$(INTDIR)\JDFAmountPool.sbr"
	-@erase "$(INTDIR)\JDFAncestor.obj"
	-@erase "$(INTDIR)\JDFAncestor.sbr"
	-@erase "$(INTDIR)\JDFAncestorPool.obj"
	-@erase "$(INTDIR)\JDFAncestorPool.sbr"
	-@erase "$(INTDIR)\JDFand.obj"
	-@erase "$(INTDIR)\JDFand.sbr"
	-@erase "$(INTDIR)\JDFApprovalParams.obj"
	-@erase "$(INTDIR)\JDFApprovalParams.sbr"
	-@erase "$(INTDIR)\JDFApprovalPerson.obj"
	-@erase "$(INTDIR)\JDFApprovalPerson.sbr"
	-@erase "$(INTDIR)\JDFApprovalSuccess.obj"
	-@erase "$(INTDIR)\JDFApprovalSuccess.sbr"
	-@erase "$(INTDIR)\JDFArgumentValue.obj"
	-@erase "$(INTDIR)\JDFArgumentValue.sbr"
	-@erase "$(INTDIR)\JDFArtDelivery.obj"
	-@erase "$(INTDIR)\JDFArtDelivery.sbr"
	-@erase "$(INTDIR)\JDFArtDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFArtDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFAssembly.obj"
	-@erase "$(INTDIR)\JDFAssembly.sbr"
	-@erase "$(INTDIR)\JDFAssemblySection.obj"
	-@erase "$(INTDIR)\JDFAssemblySection.sbr"
	-@erase "$(INTDIR)\JDFAssetListCreationParams.obj"
	-@erase "$(INTDIR)\JDFAssetListCreationParams.sbr"
	-@erase "$(INTDIR)\JDFAudit.obj"
	-@erase "$(INTDIR)\JDFAudit.sbr"
	-@erase "$(INTDIR)\JDFAuditPool.obj"
	-@erase "$(INTDIR)\JDFAuditPool.sbr"
	-@erase "$(INTDIR)\JDFAutoAcknowledge.obj"
	-@erase "$(INTDIR)\JDFAutoAcknowledge.sbr"
	-@erase "$(INTDIR)\JDFAutoAction.obj"
	-@erase "$(INTDIR)\JDFAutoAction.sbr"
	-@erase "$(INTDIR)\JDFAutoActionPool.obj"
	-@erase "$(INTDIR)\JDFAutoActionPool.sbr"
	-@erase "$(INTDIR)\JDFAutoAdded.obj"
	-@erase "$(INTDIR)\JDFAutoAdded.sbr"
	-@erase "$(INTDIR)\JDFAutoAddress.obj"
	-@erase "$(INTDIR)\JDFAutoAddress.sbr"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBinding.obj"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoAdvancedParams.obj"
	-@erase "$(INTDIR)\JDFAutoAdvancedParams.sbr"
	-@erase "$(INTDIR)\JDFAutoAmountPool.obj"
	-@erase "$(INTDIR)\JDFAutoAmountPool.sbr"
	-@erase "$(INTDIR)\JDFAutoAncestor.obj"
	-@erase "$(INTDIR)\JDFAutoAncestor.sbr"
	-@erase "$(INTDIR)\JDFAutoAncestorPool.obj"
	-@erase "$(INTDIR)\JDFAutoAncestorPool.sbr"
	-@erase "$(INTDIR)\JDFAutoand.obj"
	-@erase "$(INTDIR)\JDFAutoand.sbr"
	-@erase "$(INTDIR)\JDFAutoApprovalParams.obj"
	-@erase "$(INTDIR)\JDFAutoApprovalParams.sbr"
	-@erase "$(INTDIR)\JDFAutoApprovalPerson.obj"
	-@erase "$(INTDIR)\JDFAutoApprovalPerson.sbr"
	-@erase "$(INTDIR)\JDFAutoApprovalSuccess.obj"
	-@erase "$(INTDIR)\JDFAutoApprovalSuccess.sbr"
	-@erase "$(INTDIR)\JDFAutoArgumentValue.obj"
	-@erase "$(INTDIR)\JDFAutoArgumentValue.sbr"
	-@erase "$(INTDIR)\JDFAutoArtDelivery.obj"
	-@erase "$(INTDIR)\JDFAutoArtDelivery.sbr"
	-@erase "$(INTDIR)\JDFAutoArtDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFAutoArtDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoAssembly.obj"
	-@erase "$(INTDIR)\JDFAutoAssembly.sbr"
	-@erase "$(INTDIR)\JDFAutoAssemblySection.obj"
	-@erase "$(INTDIR)\JDFAutoAssemblySection.sbr"
	-@erase "$(INTDIR)\JDFAutoAssetListCreationParams.obj"
	-@erase "$(INTDIR)\JDFAutoAssetListCreationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoAutomatedOverprintParams.obj"
	-@erase "$(INTDIR)\JDFAutoAutomatedOverprintParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBand.obj"
	-@erase "$(INTDIR)\JDFAutoBand.sbr"
	-@erase "$(INTDIR)\JDFAutoBarcode.obj"
	-@erase "$(INTDIR)\JDFAutoBarcode.sbr"
	-@erase "$(INTDIR)\JDFAutoBasicPreflightTest.obj"
	-@erase "$(INTDIR)\JDFAutoBasicPreflightTest.sbr"
	-@erase "$(INTDIR)\JDFAutoBinderySignature.obj"
	-@erase "$(INTDIR)\JDFAutoBinderySignature.sbr"
	-@erase "$(INTDIR)\JDFAutoBindingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoBindingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoBindingQualityParams.obj"
	-@erase "$(INTDIR)\JDFAutoBindingQualityParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBindItem.obj"
	-@erase "$(INTDIR)\JDFAutoBindItem.sbr"
	-@erase "$(INTDIR)\JDFAutoBindList.obj"
	-@erase "$(INTDIR)\JDFAutoBindList.sbr"
	-@erase "$(INTDIR)\JDFAutoBlockPreparationParams.obj"
	-@erase "$(INTDIR)\JDFAutoBlockPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBookCase.obj"
	-@erase "$(INTDIR)\JDFAutoBookCase.sbr"
	-@erase "$(INTDIR)\JDFAutoBoxArgument.obj"
	-@erase "$(INTDIR)\JDFAutoBoxArgument.sbr"
	-@erase "$(INTDIR)\JDFAutoBoxPackingParams.obj"
	-@erase "$(INTDIR)\JDFAutoBoxPackingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBoxToBoxDifference.obj"
	-@erase "$(INTDIR)\JDFAutoBoxToBoxDifference.sbr"
	-@erase "$(INTDIR)\JDFAutoBufferParams.obj"
	-@erase "$(INTDIR)\JDFAutoBufferParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBundle.obj"
	-@erase "$(INTDIR)\JDFAutoBundle.sbr"
	-@erase "$(INTDIR)\JDFAutoBundleItem.obj"
	-@erase "$(INTDIR)\JDFAutoBundleItem.sbr"
	-@erase "$(INTDIR)\JDFAutoBundlingParams.obj"
	-@erase "$(INTDIR)\JDFAutoBundlingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBusinessInfo.obj"
	-@erase "$(INTDIR)\JDFAutoBusinessInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoByteMap.obj"
	-@erase "$(INTDIR)\JDFAutoByteMap.sbr"
	-@erase "$(INTDIR)\JDFAutocall.obj"
	-@erase "$(INTDIR)\JDFAutocall.sbr"
	-@erase "$(INTDIR)\JDFAutoCaseMakingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCaseMakingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCasingInParams.obj"
	-@erase "$(INTDIR)\JDFAutoCasingInParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCCITTFaxParams.obj"
	-@erase "$(INTDIR)\JDFAutoCCITTFaxParams.sbr"
	-@erase "$(INTDIR)\JDFAutoChangedAttribute.obj"
	-@erase "$(INTDIR)\JDFAutoChangedAttribute.sbr"
	-@erase "$(INTDIR)\JDFAutoChangedPath.obj"
	-@erase "$(INTDIR)\JDFAutoChangedPath.sbr"
	-@erase "$(INTDIR)\JDFAutoChannelBinding.obj"
	-@erase "$(INTDIR)\JDFAutoChannelBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoChannelBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoChannelBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutochoice.obj"
	-@erase "$(INTDIR)\JDFAutochoice.sbr"
	-@erase "$(INTDIR)\JDFAutoCIELABMeasuringField.obj"
	-@erase "$(INTDIR)\JDFAutoCIELABMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFAutoCoilBinding.obj"
	-@erase "$(INTDIR)\JDFAutoCoilBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoCoilBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCoilBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCollatingItem.obj"
	-@erase "$(INTDIR)\JDFAutoCollatingItem.sbr"
	-@erase "$(INTDIR)\JDFAutoCollectingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCollectingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoColor.obj"
	-@erase "$(INTDIR)\JDFAutoColor.sbr"
	-@erase "$(INTDIR)\JDFAutoColorantAlias.obj"
	-@erase "$(INTDIR)\JDFAutoColorantAlias.sbr"
	-@erase "$(INTDIR)\JDFAutoColorantControl.obj"
	-@erase "$(INTDIR)\JDFAutoColorantControl.sbr"
	-@erase "$(INTDIR)\JDFAutoColorantZoneDetails.obj"
	-@erase "$(INTDIR)\JDFAutoColorantZoneDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoColorControlStrip.obj"
	-@erase "$(INTDIR)\JDFAutoColorControlStrip.sbr"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionOp.obj"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionOp.sbr"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionParams.obj"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoColorIntent.obj"
	-@erase "$(INTDIR)\JDFAutoColorIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoColorMeasurementConditions.obj"
	-@erase "$(INTDIR)\JDFAutoColorMeasurementConditions.sbr"
	-@erase "$(INTDIR)\JDFAutoColorPool.obj"
	-@erase "$(INTDIR)\JDFAutoColorPool.sbr"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionOp.obj"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionOp.sbr"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoColorSpaceSubstitute.obj"
	-@erase "$(INTDIR)\JDFAutoColorSpaceSubstitute.sbr"
	-@erase "$(INTDIR)\JDFAutoColorsUsed.obj"
	-@erase "$(INTDIR)\JDFAutoColorsUsed.sbr"
	-@erase "$(INTDIR)\JDFAutoComChannel.obj"
	-@erase "$(INTDIR)\JDFAutoComChannel.sbr"
	-@erase "$(INTDIR)\JDFAutoCommand.obj"
	-@erase "$(INTDIR)\JDFAutoCommand.sbr"
	-@erase "$(INTDIR)\JDFAutoComment.obj"
	-@erase "$(INTDIR)\JDFAutoComment.sbr"
	-@erase "$(INTDIR)\JDFAutoCompany.obj"
	-@erase "$(INTDIR)\JDFAutoCompany.sbr"
	-@erase "$(INTDIR)\JDFAutoComponent.obj"
	-@erase "$(INTDIR)\JDFAutoComponent.sbr"
	-@erase "$(INTDIR)\JDFAutoContact.obj"
	-@erase "$(INTDIR)\JDFAutoContact.sbr"
	-@erase "$(INTDIR)\JDFAutoContactCopyParams.obj"
	-@erase "$(INTDIR)\JDFAutoContactCopyParams.sbr"
	-@erase "$(INTDIR)\JDFAutoContainer.obj"
	-@erase "$(INTDIR)\JDFAutoContainer.sbr"
	-@erase "$(INTDIR)\JDFAutoContentObject.obj"
	-@erase "$(INTDIR)\JDFAutoContentObject.sbr"
	-@erase "$(INTDIR)\JDFAutoConventionalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFAutoConventionalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCostCenter.obj"
	-@erase "$(INTDIR)\JDFAutoCostCenter.sbr"
	-@erase "$(INTDIR)\JDFAutoCounterReset.obj"
	-@erase "$(INTDIR)\JDFAutoCounterReset.sbr"
	-@erase "$(INTDIR)\JDFAutoCoverApplicationParams.obj"
	-@erase "$(INTDIR)\JDFAutoCoverApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCrease.obj"
	-@erase "$(INTDIR)\JDFAutoCrease.sbr"
	-@erase "$(INTDIR)\JDFAutoCreasingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCreasingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCreated.obj"
	-@erase "$(INTDIR)\JDFAutoCreated.sbr"
	-@erase "$(INTDIR)\JDFAutoCreditCard.obj"
	-@erase "$(INTDIR)\JDFAutoCreditCard.sbr"
	-@erase "$(INTDIR)\JDFAutoCustomerInfo.obj"
	-@erase "$(INTDIR)\JDFAutoCustomerInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoCustomerMessage.obj"
	-@erase "$(INTDIR)\JDFAutoCustomerMessage.sbr"
	-@erase "$(INTDIR)\JDFAutoCut.obj"
	-@erase "$(INTDIR)\JDFAutoCut.sbr"
	-@erase "$(INTDIR)\JDFAutoCutBlock.obj"
	-@erase "$(INTDIR)\JDFAutoCutBlock.sbr"
	-@erase "$(INTDIR)\JDFAutoCutMark.obj"
	-@erase "$(INTDIR)\JDFAutoCutMark.sbr"
	-@erase "$(INTDIR)\JDFAutoCuttingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDBMergeParams.obj"
	-@erase "$(INTDIR)\JDFAutoDBMergeParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDBRules.obj"
	-@erase "$(INTDIR)\JDFAutoDBRules.sbr"
	-@erase "$(INTDIR)\JDFAutoDBSchema.obj"
	-@erase "$(INTDIR)\JDFAutoDBSchema.sbr"
	-@erase "$(INTDIR)\JDFAutoDBSelection.obj"
	-@erase "$(INTDIR)\JDFAutoDBSelection.sbr"
	-@erase "$(INTDIR)\JDFAutoDCTParams.obj"
	-@erase "$(INTDIR)\JDFAutoDCTParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDeleted.obj"
	-@erase "$(INTDIR)\JDFAutoDeleted.sbr"
	-@erase "$(INTDIR)\JDFAutoDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFAutoDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFAutoDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDensityMeasuringField.obj"
	-@erase "$(INTDIR)\JDFAutoDensityMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFAutoDependencies.obj"
	-@erase "$(INTDIR)\JDFAutoDependencies.sbr"
	-@erase "$(INTDIR)\JDFAutoDevCap.obj"
	-@erase "$(INTDIR)\JDFAutoDevCap.sbr"
	-@erase "$(INTDIR)\JDFAutoDevCaps.obj"
	-@erase "$(INTDIR)\JDFAutoDevCaps.sbr"
	-@erase "$(INTDIR)\JDFAutoDevelopingParams.obj"
	-@erase "$(INTDIR)\JDFAutoDevelopingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDevice.obj"
	-@erase "$(INTDIR)\JDFAutoDevice.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceCap.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceCap.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceFilter.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceInfo.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceList.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceList.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceMark.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceMark.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceNColor.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceNColor.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceNSpace.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceNSpace.sbr"
	-@erase "$(INTDIR)\JDFAutoDigitalDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFAutoDigitalDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDigitalMedia.obj"
	-@erase "$(INTDIR)\JDFAutoDigitalMedia.sbr"
	-@erase "$(INTDIR)\JDFAutoDigitalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFAutoDigitalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDisjointing.obj"
	-@erase "$(INTDIR)\JDFAutoDisjointing.sbr"
	-@erase "$(INTDIR)\JDFAutoDisplayGroup.obj"
	-@erase "$(INTDIR)\JDFAutoDisplayGroup.sbr"
	-@erase "$(INTDIR)\JDFAutoDisplayGroupPool.obj"
	-@erase "$(INTDIR)\JDFAutoDisplayGroupPool.sbr"
	-@erase "$(INTDIR)\JDFAutoDisposition.obj"
	-@erase "$(INTDIR)\JDFAutoDisposition.sbr"
	-@erase "$(INTDIR)\JDFAutoDividingParams.obj"
	-@erase "$(INTDIR)\JDFAutoDividingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDrop.obj"
	-@erase "$(INTDIR)\JDFAutoDrop.sbr"
	-@erase "$(INTDIR)\JDFAutoDropIntent.obj"
	-@erase "$(INTDIR)\JDFAutoDropIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoDropItem.obj"
	-@erase "$(INTDIR)\JDFAutoDropItem.sbr"
	-@erase "$(INTDIR)\JDFAutoDropItemIntent.obj"
	-@erase "$(INTDIR)\JDFAutoDropItemIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoDynamicField.obj"
	-@erase "$(INTDIR)\JDFAutoDynamicField.sbr"
	-@erase "$(INTDIR)\JDFAutoDynamicInput.obj"
	-@erase "$(INTDIR)\JDFAutoDynamicInput.sbr"
	-@erase "$(INTDIR)\JDFAutoEdgeGluing.obj"
	-@erase "$(INTDIR)\JDFAutoEdgeGluing.sbr"
	-@erase "$(INTDIR)\JDFAutoElementColorParams.obj"
	-@erase "$(INTDIR)\JDFAutoElementColorParams.sbr"
	-@erase "$(INTDIR)\JDFAutoEmboss.obj"
	-@erase "$(INTDIR)\JDFAutoEmboss.sbr"
	-@erase "$(INTDIR)\JDFAutoEmbossingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoEmbossingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoEmbossingItem.obj"
	-@erase "$(INTDIR)\JDFAutoEmbossingItem.sbr"
	-@erase "$(INTDIR)\JDFAutoEmbossingParams.obj"
	-@erase "$(INTDIR)\JDFAutoEmbossingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoEmployee.obj"
	-@erase "$(INTDIR)\JDFAutoEmployee.sbr"
	-@erase "$(INTDIR)\JDFAutoEmployeeDef.obj"
	-@erase "$(INTDIR)\JDFAutoEmployeeDef.sbr"
	-@erase "$(INTDIR)\JDFAutoEndSheet.obj"
	-@erase "$(INTDIR)\JDFAutoEndSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoEndSheetGluingParams.obj"
	-@erase "$(INTDIR)\JDFAutoEndSheetGluingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoEnumerationSpan.obj"
	-@erase "$(INTDIR)\JDFAutoEnumerationSpan.sbr"
	-@erase "$(INTDIR)\JDFAutoError.obj"
	-@erase "$(INTDIR)\JDFAutoError.sbr"
	-@erase "$(INTDIR)\JDFAutoEvent.obj"
	-@erase "$(INTDIR)\JDFAutoEvent.sbr"
	-@erase "$(INTDIR)\JDFAutoExposedMedia.obj"
	-@erase "$(INTDIR)\JDFAutoExposedMedia.sbr"
	-@erase "$(INTDIR)\JDFAutoFCNKey.obj"
	-@erase "$(INTDIR)\JDFAutoFCNKey.sbr"
	-@erase "$(INTDIR)\JDFAutoFeatureAttribute.obj"
	-@erase "$(INTDIR)\JDFAutoFeatureAttribute.sbr"
	-@erase "$(INTDIR)\JDFAutoFeaturePool.obj"
	-@erase "$(INTDIR)\JDFAutoFeaturePool.sbr"
	-@erase "$(INTDIR)\JDFAutoFeeder.obj"
	-@erase "$(INTDIR)\JDFAutoFeeder.sbr"
	-@erase "$(INTDIR)\JDFAutoFeederQualityParams.obj"
	-@erase "$(INTDIR)\JDFAutoFeederQualityParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFeedingParams.obj"
	-@erase "$(INTDIR)\JDFAutoFeedingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFileAlias.obj"
	-@erase "$(INTDIR)\JDFAutoFileAlias.sbr"
	-@erase "$(INTDIR)\JDFAutoFileSpec.obj"
	-@erase "$(INTDIR)\JDFAutoFileSpec.sbr"
	-@erase "$(INTDIR)\JDFAutoFitPolicy.obj"
	-@erase "$(INTDIR)\JDFAutoFitPolicy.sbr"
	-@erase "$(INTDIR)\JDFAutoFlateParams.obj"
	-@erase "$(INTDIR)\JDFAutoFlateParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFlushedResources.obj"
	-@erase "$(INTDIR)\JDFAutoFlushedResources.sbr"
	-@erase "$(INTDIR)\JDFAutoFlushQueueParams.obj"
	-@erase "$(INTDIR)\JDFAutoFlushQueueParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFlushResourceParams.obj"
	-@erase "$(INTDIR)\JDFAutoFlushResourceParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFold.obj"
	-@erase "$(INTDIR)\JDFAutoFold.sbr"
	-@erase "$(INTDIR)\JDFAutoFoldingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoFoldingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoFoldingParams.obj"
	-@erase "$(INTDIR)\JDFAutoFoldingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFontParams.obj"
	-@erase "$(INTDIR)\JDFAutoFontParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFontPolicy.obj"
	-@erase "$(INTDIR)\JDFAutoFontPolicy.sbr"
	-@erase "$(INTDIR)\JDFAutoFormatConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoFormatConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoGatheringParams.obj"
	-@erase "$(INTDIR)\JDFAutoGatheringParams.sbr"
	-@erase "$(INTDIR)\JDFAutoGlue.obj"
	-@erase "$(INTDIR)\JDFAutoGlue.sbr"
	-@erase "$(INTDIR)\JDFAutoGlueApplication.obj"
	-@erase "$(INTDIR)\JDFAutoGlueApplication.sbr"
	-@erase "$(INTDIR)\JDFAutoGlueLine.obj"
	-@erase "$(INTDIR)\JDFAutoGlueLine.sbr"
	-@erase "$(INTDIR)\JDFAutoGluingParams.obj"
	-@erase "$(INTDIR)\JDFAutoGluingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoHardCoverBinding.obj"
	-@erase "$(INTDIR)\JDFAutoHardCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoHeadBandApplicationParams.obj"
	-@erase "$(INTDIR)\JDFAutoHeadBandApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoHole.obj"
	-@erase "$(INTDIR)\JDFAutoHole.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleLine.obj"
	-@erase "$(INTDIR)\JDFAutoHoleLine.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleList.obj"
	-@erase "$(INTDIR)\JDFAutoHoleList.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleMakingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoHoleMakingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleMakingParams.obj"
	-@erase "$(INTDIR)\JDFAutoHoleMakingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoIcon.obj"
	-@erase "$(INTDIR)\JDFAutoIcon.sbr"
	-@erase "$(INTDIR)\JDFAutoIconList.obj"
	-@erase "$(INTDIR)\JDFAutoIconList.sbr"
	-@erase "$(INTDIR)\JDFAutoIdentificationField.obj"
	-@erase "$(INTDIR)\JDFAutoIdentificationField.sbr"
	-@erase "$(INTDIR)\JDFAutoIDInfo.obj"
	-@erase "$(INTDIR)\JDFAutoIDInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPCover.obj"
	-@erase "$(INTDIR)\JDFAutoIDPCover.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPFinishing.obj"
	-@erase "$(INTDIR)\JDFAutoIDPFinishing.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPFolding.obj"
	-@erase "$(INTDIR)\JDFAutoIDPFolding.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPHoleMaking.obj"
	-@erase "$(INTDIR)\JDFAutoIDPHoleMaking.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPImageShift.obj"
	-@erase "$(INTDIR)\JDFAutoIDPImageShift.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPJobSheet.obj"
	-@erase "$(INTDIR)\JDFAutoIDPJobSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPLayout.obj"
	-@erase "$(INTDIR)\JDFAutoIDPLayout.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPrintingParams.obj"
	-@erase "$(INTDIR)\JDFAutoIDPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPStitching.obj"
	-@erase "$(INTDIR)\JDFAutoIDPStitching.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPTrimming.obj"
	-@erase "$(INTDIR)\JDFAutoIDPTrimming.sbr"
	-@erase "$(INTDIR)\JDFAutoImageCompression.obj"
	-@erase "$(INTDIR)\JDFAutoImageCompression.sbr"
	-@erase "$(INTDIR)\JDFAutoImageCompressionParams.obj"
	-@erase "$(INTDIR)\JDFAutoImageCompressionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoImageReplacementParams.obj"
	-@erase "$(INTDIR)\JDFAutoImageReplacementParams.sbr"
	-@erase "$(INTDIR)\JDFAutoImageSetterParams.obj"
	-@erase "$(INTDIR)\JDFAutoImageSetterParams.sbr"
	-@erase "$(INTDIR)\JDFAutoImageShift.obj"
	-@erase "$(INTDIR)\JDFAutoImageShift.sbr"
	-@erase "$(INTDIR)\JDFAutoInk.obj"
	-@erase "$(INTDIR)\JDFAutoInk.sbr"
	-@erase "$(INTDIR)\JDFAutoInkZoneCalculationParams.obj"
	-@erase "$(INTDIR)\JDFAutoInkZoneCalculationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoInkZoneProfile.obj"
	-@erase "$(INTDIR)\JDFAutoInkZoneProfile.sbr"
	-@erase "$(INTDIR)\JDFAutoInsert.obj"
	-@erase "$(INTDIR)\JDFAutoInsert.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoInsertingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertingParams.obj"
	-@erase "$(INTDIR)\JDFAutoInsertingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertList.obj"
	-@erase "$(INTDIR)\JDFAutoInsertList.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertSheet.obj"
	-@erase "$(INTDIR)\JDFAutoInsertSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoInterpretedPDLData.obj"
	-@erase "$(INTDIR)\JDFAutoInterpretedPDLData.sbr"
	-@erase "$(INTDIR)\JDFAutoInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFAutoInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoJacketingParams.obj"
	-@erase "$(INTDIR)\JDFAutoJacketingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoJDFController.obj"
	-@erase "$(INTDIR)\JDFAutoJDFController.sbr"
	-@erase "$(INTDIR)\JDFAutoJDFService.obj"
	-@erase "$(INTDIR)\JDFAutoJDFService.sbr"
	-@erase "$(INTDIR)\JDFAutoJMF.obj"
	-@erase "$(INTDIR)\JDFAutoJMF.sbr"
	-@erase "$(INTDIR)\JDFAutoJobField.obj"
	-@erase "$(INTDIR)\JDFAutoJobField.sbr"
	-@erase "$(INTDIR)\JDFAutoJobPhase.obj"
	-@erase "$(INTDIR)\JDFAutoJobPhase.sbr"
	-@erase "$(INTDIR)\JDFAutoKnownMsgQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoKnownMsgQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLabelingParams.obj"
	-@erase "$(INTDIR)\JDFAutoLabelingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLaminatingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoLaminatingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoLaminatingParams.obj"
	-@erase "$(INTDIR)\JDFAutoLaminatingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLayerDetails.obj"
	-@erase "$(INTDIR)\JDFAutoLayerDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoLayerList.obj"
	-@erase "$(INTDIR)\JDFAutoLayerList.sbr"
	-@erase "$(INTDIR)\JDFAutoLayout.obj"
	-@erase "$(INTDIR)\JDFAutoLayout.sbr"
	-@erase "$(INTDIR)\JDFAutoLayoutElement.obj"
	-@erase "$(INTDIR)\JDFAutoLayoutElement.sbr"
	-@erase "$(INTDIR)\JDFAutoLayoutIntent.obj"
	-@erase "$(INTDIR)\JDFAutoLayoutIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoLayoutPreparationParams.obj"
	-@erase "$(INTDIR)\JDFAutoLayoutPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLoc.obj"
	-@erase "$(INTDIR)\JDFAutoLoc.sbr"
	-@erase "$(INTDIR)\JDFAutoLocation.obj"
	-@erase "$(INTDIR)\JDFAutoLocation.sbr"
	-@erase "$(INTDIR)\JDFAutoLongFold.obj"
	-@erase "$(INTDIR)\JDFAutoLongFold.sbr"
	-@erase "$(INTDIR)\JDFAutoLongGlue.obj"
	-@erase "$(INTDIR)\JDFAutoLongGlue.sbr"
	-@erase "$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.obj"
	-@erase "$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLongPerforate.obj"
	-@erase "$(INTDIR)\JDFAutoLongPerforate.sbr"
	-@erase "$(INTDIR)\JDFAutoLongSlit.obj"
	-@erase "$(INTDIR)\JDFAutoLongSlit.sbr"
	-@erase "$(INTDIR)\JDFAutoLZWParams.obj"
	-@erase "$(INTDIR)\JDFAutoLZWParams.sbr"
	-@erase "$(INTDIR)\JDFAutomacro.obj"
	-@erase "$(INTDIR)\JDFAutomacro.sbr"
	-@erase "$(INTDIR)\JDFAutoMacroPool.obj"
	-@erase "$(INTDIR)\JDFAutoMacroPool.sbr"
	-@erase "$(INTDIR)\JDFAutoManualLaborParams.obj"
	-@erase "$(INTDIR)\JDFAutoManualLaborParams.sbr"
	-@erase "$(INTDIR)\JDFAutoMarkObject.obj"
	-@erase "$(INTDIR)\JDFAutoMarkObject.sbr"
	-@erase "$(INTDIR)\JDFAutomatedOverprintParams.obj"
	-@erase "$(INTDIR)\JDFAutomatedOverprintParams.sbr"
	-@erase "$(INTDIR)\JDFAutoMedia.obj"
	-@erase "$(INTDIR)\JDFAutoMedia.sbr"
	-@erase "$(INTDIR)\JDFAutoMediaIntent.obj"
	-@erase "$(INTDIR)\JDFAutoMediaIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoMediaSource.obj"
	-@erase "$(INTDIR)\JDFAutoMediaSource.sbr"
	-@erase "$(INTDIR)\JDFAutoMerged.obj"
	-@erase "$(INTDIR)\JDFAutoMerged.sbr"
	-@erase "$(INTDIR)\JDFAutoMessage.obj"
	-@erase "$(INTDIR)\JDFAutoMessage.sbr"
	-@erase "$(INTDIR)\JDFAutoMessageService.obj"
	-@erase "$(INTDIR)\JDFAutoMessageService.sbr"
	-@erase "$(INTDIR)\JDFAutoMISDetails.obj"
	-@erase "$(INTDIR)\JDFAutoMISDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoModified.obj"
	-@erase "$(INTDIR)\JDFAutoModified.sbr"
	-@erase "$(INTDIR)\JDFAutoModulePhase.obj"
	-@erase "$(INTDIR)\JDFAutoModulePhase.sbr"
	-@erase "$(INTDIR)\JDFAutoModuleStatus.obj"
	-@erase "$(INTDIR)\JDFAutoModuleStatus.sbr"
	-@erase "$(INTDIR)\JDFAutoMsgFilter.obj"
	-@erase "$(INTDIR)\JDFAutoMsgFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoNewJDFCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoNewJDFCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNewJDFQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoNewJDFQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfo.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfoCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfoCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfoQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfoQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfoResp.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfoResp.sbr"
	-@erase "$(INTDIR)\JDFAutonot.obj"
	-@erase "$(INTDIR)\JDFAutonot.sbr"
	-@erase "$(INTDIR)\JDFAutoNotification.obj"
	-@erase "$(INTDIR)\JDFAutoNotification.sbr"
	-@erase "$(INTDIR)\JDFAutoNotificationDef.obj"
	-@erase "$(INTDIR)\JDFAutoNotificationDef.sbr"
	-@erase "$(INTDIR)\JDFAutoNotificationFilter.obj"
	-@erase "$(INTDIR)\JDFAutoNotificationFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoNumberingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberingParam.obj"
	-@erase "$(INTDIR)\JDFAutoNumberingParam.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberingParams.obj"
	-@erase "$(INTDIR)\JDFAutoNumberingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberItem.obj"
	-@erase "$(INTDIR)\JDFAutoNumberItem.sbr"
	-@erase "$(INTDIR)\JDFAutoObjectResolution.obj"
	-@erase "$(INTDIR)\JDFAutoObjectResolution.sbr"
	-@erase "$(INTDIR)\JDFAutoObservationTarget.obj"
	-@erase "$(INTDIR)\JDFAutoObservationTarget.sbr"
	-@erase "$(INTDIR)\JDFAutoOccupation.obj"
	-@erase "$(INTDIR)\JDFAutoOccupation.sbr"
	-@erase "$(INTDIR)\JDFAutoor.obj"
	-@erase "$(INTDIR)\JDFAutoor.sbr"
	-@erase "$(INTDIR)\JDFAutoOrderingParams.obj"
	-@erase "$(INTDIR)\JDFAutoOrderingParams.sbr"
	-@erase "$(INTDIR)\JDFAutootherwise.obj"
	-@erase "$(INTDIR)\JDFAutootherwise.sbr"
	-@erase "$(INTDIR)\JDFAutoPackingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoPackingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoPackingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPackingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPageCell.obj"
	-@erase "$(INTDIR)\JDFAutoPageCell.sbr"
	-@erase "$(INTDIR)\JDFAutoPageData.obj"
	-@erase "$(INTDIR)\JDFAutoPageData.sbr"
	-@erase "$(INTDIR)\JDFAutoPageList.obj"
	-@erase "$(INTDIR)\JDFAutoPageList.sbr"
	-@erase "$(INTDIR)\JDFAutoPallet.obj"
	-@erase "$(INTDIR)\JDFAutoPallet.sbr"
	-@erase "$(INTDIR)\JDFAutoPalletizingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPalletizingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPart.obj"
	-@erase "$(INTDIR)\JDFAutoPart.sbr"
	-@erase "$(INTDIR)\JDFAutoPartStatus.obj"
	-@erase "$(INTDIR)\JDFAutoPartStatus.sbr"
	-@erase "$(INTDIR)\JDFAutoPayment.obj"
	-@erase "$(INTDIR)\JDFAutoPayment.sbr"
	-@erase "$(INTDIR)\JDFAutoPDFInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPDFInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPDFToPSConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoPDFToPSConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPDFXParams.obj"
	-@erase "$(INTDIR)\JDFAutoPDFXParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPDLResourceAlias.obj"
	-@erase "$(INTDIR)\JDFAutoPDLResourceAlias.sbr"
	-@erase "$(INTDIR)\JDFAutoPerforate.obj"
	-@erase "$(INTDIR)\JDFAutoPerforate.sbr"
	-@erase "$(INTDIR)\JDFAutoPerforatingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPerforatingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPerformance.obj"
	-@erase "$(INTDIR)\JDFAutoPerformance.sbr"
	-@erase "$(INTDIR)\JDFAutoPerson.obj"
	-@erase "$(INTDIR)\JDFAutoPerson.sbr"
	-@erase "$(INTDIR)\JDFAutoPhaseTime.obj"
	-@erase "$(INTDIR)\JDFAutoPhaseTime.sbr"
	-@erase "$(INTDIR)\JDFAutoPipeParams.obj"
	-@erase "$(INTDIR)\JDFAutoPipeParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPixelColorant.obj"
	-@erase "$(INTDIR)\JDFAutoPixelColorant.sbr"
	-@erase "$(INTDIR)\JDFAutoPlaceHolderResource.obj"
	-@erase "$(INTDIR)\JDFAutoPlaceHolderResource.sbr"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBinding.obj"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPlateCopyParams.obj"
	-@erase "$(INTDIR)\JDFAutoPlateCopyParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPosition.obj"
	-@erase "$(INTDIR)\JDFAutoPosition.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightAction.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightAction.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightAnalysis.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightAnalysis.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightArgument.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightArgument.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightConstraint.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightConstraint.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightDetail.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightDetail.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightInstance.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightInstance.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightInstanceDetail.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightInstanceDetail.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightInventory.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightInventory.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightParams.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightProfile.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightProfile.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightReport.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightReport.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightReportRulePool.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightReportRulePool.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightValue.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightValue.sbr"
	-@erase "$(INTDIR)\JDFAutoPRError.obj"
	-@erase "$(INTDIR)\JDFAutoPRError.sbr"
	-@erase "$(INTDIR)\JDFAutoPreview.obj"
	-@erase "$(INTDIR)\JDFAutoPreview.sbr"
	-@erase "$(INTDIR)\JDFAutoPreviewGenerationParams.obj"
	-@erase "$(INTDIR)\JDFAutoPreviewGenerationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPRGroup.obj"
	-@erase "$(INTDIR)\JDFAutoPRGroup.sbr"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurence.obj"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurence.sbr"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurenceBase.obj"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurenceBase.sbr"
	-@erase "$(INTDIR)\JDFAutoPricing.obj"
	-@erase "$(INTDIR)\JDFAutoPricing.sbr"
	-@erase "$(INTDIR)\JDFAutoPrintCondition.obj"
	-@erase "$(INTDIR)\JDFAutoPrintCondition.sbr"
	-@erase "$(INTDIR)\JDFAutoPrintConditionColor.obj"
	-@erase "$(INTDIR)\JDFAutoPrintConditionColor.sbr"
	-@erase "$(INTDIR)\JDFAutoPrintRollingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPrintRollingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPRItem.obj"
	-@erase "$(INTDIR)\JDFAutoPRItem.sbr"
	-@erase "$(INTDIR)\JDFAutoPROccurence.obj"
	-@erase "$(INTDIR)\JDFAutoPROccurence.sbr"
	-@erase "$(INTDIR)\JDFAutoProcessRun.obj"
	-@erase "$(INTDIR)\JDFAutoProcessRun.sbr"
	-@erase "$(INTDIR)\JDFAutoProductionIntent.obj"
	-@erase "$(INTDIR)\JDFAutoProductionIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoProofingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoProofingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoProofingParams.obj"
	-@erase "$(INTDIR)\JDFAutoProofingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoProofItem.obj"
	-@erase "$(INTDIR)\JDFAutoProofItem.sbr"
	-@erase "$(INTDIR)\JDFAutoProperties.obj"
	-@erase "$(INTDIR)\JDFAutoProperties.sbr"
	-@erase "$(INTDIR)\JDFAutoPRRule.obj"
	-@erase "$(INTDIR)\JDFAutoPRRule.sbr"
	-@erase "$(INTDIR)\JDFAutoPRRuleAttr.obj"
	-@erase "$(INTDIR)\JDFAutoPRRuleAttr.sbr"
	-@erase "$(INTDIR)\JDFAutoPSToPDFConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoPSToPDFConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQualityControlParams.obj"
	-@erase "$(INTDIR)\JDFAutoQualityControlParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQualityControlResult.obj"
	-@erase "$(INTDIR)\JDFAutoQualityControlResult.sbr"
	-@erase "$(INTDIR)\JDFAutoQualityMeasurement.obj"
	-@erase "$(INTDIR)\JDFAutoQualityMeasurement.sbr"
	-@erase "$(INTDIR)\JDFAutoQuery.obj"
	-@erase "$(INTDIR)\JDFAutoQuery.sbr"
	-@erase "$(INTDIR)\JDFAutoQueue.obj"
	-@erase "$(INTDIR)\JDFAutoQueue.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntry.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntry.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDef.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDef.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDefList.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDefList.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPosParams.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPosParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPriParams.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPriParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueFilter.obj"
	-@erase "$(INTDIR)\JDFAutoQueueFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueSubmissionParams.obj"
	-@erase "$(INTDIR)\JDFAutoQueueSubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRegisterMark.obj"
	-@erase "$(INTDIR)\JDFAutoRegisterMark.sbr"
	-@erase "$(INTDIR)\JDFAutoRegisterRibbon.obj"
	-@erase "$(INTDIR)\JDFAutoRegisterRibbon.sbr"
	-@erase "$(INTDIR)\JDFAutoRemoved.obj"
	-@erase "$(INTDIR)\JDFAutoRemoved.sbr"
	-@erase "$(INTDIR)\JDFAutoRenderingParams.obj"
	-@erase "$(INTDIR)\JDFAutoRenderingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRequestQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFAutoRequestQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceAudit.obj"
	-@erase "$(INTDIR)\JDFAutoResourceAudit.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourceCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceDefinitionParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourceDefinitionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceInfo.obj"
	-@erase "$(INTDIR)\JDFAutoResourceInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceParam.obj"
	-@erase "$(INTDIR)\JDFAutoResourceParam.sbr"
	-@erase "$(INTDIR)\JDFAutoResourcePullParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourcePullParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourceQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResponse.obj"
	-@erase "$(INTDIR)\JDFAutoResponse.sbr"
	-@erase "$(INTDIR)\JDFAutoResubmissionParams.obj"
	-@erase "$(INTDIR)\JDFAutoResubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoReturnQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFAutoReturnQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRingBinding.obj"
	-@erase "$(INTDIR)\JDFAutoRingBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoRingBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoRingBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRollStand.obj"
	-@erase "$(INTDIR)\JDFAutoRollStand.sbr"
	-@erase "$(INTDIR)\JDFAutoRunList.obj"
	-@erase "$(INTDIR)\JDFAutoRunList.sbr"
	-@erase "$(INTDIR)\JDFAutoSaddleStitching.obj"
	-@erase "$(INTDIR)\JDFAutoSaddleStitching.sbr"
	-@erase "$(INTDIR)\JDFAutoSaddleStitchingParams.obj"
	-@erase "$(INTDIR)\JDFAutoSaddleStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoScanParams.obj"
	-@erase "$(INTDIR)\JDFAutoScanParams.sbr"
	-@erase "$(INTDIR)\JDFAutoScavengerArea.obj"
	-@erase "$(INTDIR)\JDFAutoScavengerArea.sbr"
	-@erase "$(INTDIR)\JDFAutoScore.obj"
	-@erase "$(INTDIR)\JDFAutoScore.sbr"
	-@erase "$(INTDIR)\JDFAutoScreeningIntent.obj"
	-@erase "$(INTDIR)\JDFAutoScreeningIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoScreeningParams.obj"
	-@erase "$(INTDIR)\JDFAutoScreeningParams.sbr"
	-@erase "$(INTDIR)\JDFAutoScreenSelector.obj"
	-@erase "$(INTDIR)\JDFAutoScreenSelector.sbr"
	-@erase "$(INTDIR)\JDFAutoSeparationControlParams.obj"
	-@erase "$(INTDIR)\JDFAutoSeparationControlParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSeparationSpec.obj"
	-@erase "$(INTDIR)\JDFAutoSeparationSpec.sbr"
	-@erase "$(INTDIR)\JDFAutoset.obj"
	-@erase "$(INTDIR)\JDFAutoset.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeCut.obj"
	-@erase "$(INTDIR)\JDFAutoShapeCut.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingParams.obj"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeElement.obj"
	-@erase "$(INTDIR)\JDFAutoShapeElement.sbr"
	-@erase "$(INTDIR)\JDFAutoSheet.obj"
	-@erase "$(INTDIR)\JDFAutoSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoShrinkingParams.obj"
	-@erase "$(INTDIR)\JDFAutoShrinkingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoShutDownCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoShutDownCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSideSewing.obj"
	-@erase "$(INTDIR)\JDFAutoSideSewing.sbr"
	-@erase "$(INTDIR)\JDFAutoSideSewingParams.obj"
	-@erase "$(INTDIR)\JDFAutoSideSewingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSideStitching.obj"
	-@erase "$(INTDIR)\JDFAutoSideStitching.sbr"
	-@erase "$(INTDIR)\JDFAutoSignal.obj"
	-@erase "$(INTDIR)\JDFAutoSignal.sbr"
	-@erase "$(INTDIR)\JDFAutoSignature.obj"
	-@erase "$(INTDIR)\JDFAutoSignature.sbr"
	-@erase "$(INTDIR)\JDFAutoSignatureCell.obj"
	-@erase "$(INTDIR)\JDFAutoSignatureCell.sbr"
	-@erase "$(INTDIR)\JDFAutoSizeIntent.obj"
	-@erase "$(INTDIR)\JDFAutoSizeIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoSoftCoverBinding.obj"
	-@erase "$(INTDIR)\JDFAutoSoftCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoSpawned.obj"
	-@erase "$(INTDIR)\JDFAutoSpawned.sbr"
	-@erase "$(INTDIR)\JDFAutoSpinePreparationParams.obj"
	-@erase "$(INTDIR)\JDFAutoSpinePreparationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSpineTapingParams.obj"
	-@erase "$(INTDIR)\JDFAutoSpineTapingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStackingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStackingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStatusPool.obj"
	-@erase "$(INTDIR)\JDFAutoStatusPool.sbr"
	-@erase "$(INTDIR)\JDFAutoStatusQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoStatusQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStitchingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStopPersChParams.obj"
	-@erase "$(INTDIR)\JDFAutoStopPersChParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStrap.obj"
	-@erase "$(INTDIR)\JDFAutoStrap.sbr"
	-@erase "$(INTDIR)\JDFAutoStrappingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStrappingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStringListValue.obj"
	-@erase "$(INTDIR)\JDFAutoStringListValue.sbr"
	-@erase "$(INTDIR)\JDFAutoStripBinding.obj"
	-@erase "$(INTDIR)\JDFAutoStripBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoStripBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStripBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStripCellParams.obj"
	-@erase "$(INTDIR)\JDFAutoStripCellParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStrippingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStrippingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSubmissionMethods.obj"
	-@erase "$(INTDIR)\JDFAutoSubmissionMethods.sbr"
	-@erase "$(INTDIR)\JDFAutoSubscription.obj"
	-@erase "$(INTDIR)\JDFAutoSubscription.sbr"
	-@erase "$(INTDIR)\JDFAutoSurface.obj"
	-@erase "$(INTDIR)\JDFAutoSurface.sbr"
	-@erase "$(INTDIR)\JDFAutoSystemTimeSet.obj"
	-@erase "$(INTDIR)\JDFAutoSystemTimeSet.sbr"
	-@erase "$(INTDIR)\JDFAutoTabs.obj"
	-@erase "$(INTDIR)\JDFAutoTabs.sbr"
	-@erase "$(INTDIR)\JDFAutoTape.obj"
	-@erase "$(INTDIR)\JDFAutoTape.sbr"
	-@erase "$(INTDIR)\JDFAutoTest.obj"
	-@erase "$(INTDIR)\JDFAutoTest.sbr"
	-@erase "$(INTDIR)\JDFAutoTestPool.obj"
	-@erase "$(INTDIR)\JDFAutoTestPool.sbr"
	-@erase "$(INTDIR)\JDFAutoTestRef.obj"
	-@erase "$(INTDIR)\JDFAutoTestRef.sbr"
	-@erase "$(INTDIR)\JDFAutoThinPDFParams.obj"
	-@erase "$(INTDIR)\JDFAutoThinPDFParams.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSealing.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSealing.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSealingParams.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSealingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSewing.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSewing.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSewingParams.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSewingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoTIFFEmbeddedFile.obj"
	-@erase "$(INTDIR)\JDFAutoTIFFEmbeddedFile.sbr"
	-@erase "$(INTDIR)\JDFAutoTIFFFormatParams.obj"
	-@erase "$(INTDIR)\JDFAutoTIFFFormatParams.sbr"
	-@erase "$(INTDIR)\JDFAutoTIFFtag.obj"
	-@erase "$(INTDIR)\JDFAutoTIFFtag.sbr"
	-@erase "$(INTDIR)\JDFAutoTile.obj"
	-@erase "$(INTDIR)\JDFAutoTile.sbr"
	-@erase "$(INTDIR)\JDFAutoTool.obj"
	-@erase "$(INTDIR)\JDFAutoTool.sbr"
	-@erase "$(INTDIR)\JDFAutoTrackFilter.obj"
	-@erase "$(INTDIR)\JDFAutoTrackFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoTrackResult.obj"
	-@erase "$(INTDIR)\JDFAutoTrackResult.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferCurve.obj"
	-@erase "$(INTDIR)\JDFAutoTransferCurve.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferCurvePool.obj"
	-@erase "$(INTDIR)\JDFAutoTransferCurvePool.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferCurveSet.obj"
	-@erase "$(INTDIR)\JDFAutoTransferCurveSet.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferFunctionControl.obj"
	-@erase "$(INTDIR)\JDFAutoTransferFunctionControl.sbr"
	-@erase "$(INTDIR)\JDFAutoTrappingDetails.obj"
	-@erase "$(INTDIR)\JDFAutoTrappingDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoTrappingOrder.obj"
	-@erase "$(INTDIR)\JDFAutoTrappingOrder.sbr"
	-@erase "$(INTDIR)\JDFAutoTrappingParams.obj"
	-@erase "$(INTDIR)\JDFAutoTrappingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoTrapRegion.obj"
	-@erase "$(INTDIR)\JDFAutoTrapRegion.sbr"
	-@erase "$(INTDIR)\JDFAutoTrigger.obj"
	-@erase "$(INTDIR)\JDFAutoTrigger.sbr"
	-@erase "$(INTDIR)\JDFAutoTrimmingParams.obj"
	-@erase "$(INTDIR)\JDFAutoTrimmingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoValue.obj"
	-@erase "$(INTDIR)\JDFAutoValue.sbr"
	-@erase "$(INTDIR)\JDFAutoValueLoc.obj"
	-@erase "$(INTDIR)\JDFAutoValueLoc.sbr"
	-@erase "$(INTDIR)\JDFAutoVerificationParams.obj"
	-@erase "$(INTDIR)\JDFAutoVerificationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoWakeUpCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoWakeUpCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutowhen.obj"
	-@erase "$(INTDIR)\JDFAutowhen.sbr"
	-@erase "$(INTDIR)\JDFAutoWireCombBinding.obj"
	-@erase "$(INTDIR)\JDFAutoWireCombBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoWireCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoWireCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoWrappingParams.obj"
	-@erase "$(INTDIR)\JDFAutoWrappingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoxor.obj"
	-@erase "$(INTDIR)\JDFAutoxor.sbr"
	-@erase "$(INTDIR)\JDFBand.obj"
	-@erase "$(INTDIR)\JDFBand.sbr"
	-@erase "$(INTDIR)\JDFBarcode.obj"
	-@erase "$(INTDIR)\JDFBarcode.sbr"
	-@erase "$(INTDIR)\JDFBasicPreflightTest.obj"
	-@erase "$(INTDIR)\JDFBasicPreflightTest.sbr"
	-@erase "$(INTDIR)\JDFBinderySignature.obj"
	-@erase "$(INTDIR)\JDFBinderySignature.sbr"
	-@erase "$(INTDIR)\JDFBindingIntent.obj"
	-@erase "$(INTDIR)\JDFBindingIntent.sbr"
	-@erase "$(INTDIR)\JDFBindingQualityParams.obj"
	-@erase "$(INTDIR)\JDFBindingQualityParams.sbr"
	-@erase "$(INTDIR)\JDFBindItem.obj"
	-@erase "$(INTDIR)\JDFBindItem.sbr"
	-@erase "$(INTDIR)\JDFBindList.obj"
	-@erase "$(INTDIR)\JDFBindList.sbr"
	-@erase "$(INTDIR)\JDFBlockPreparationParams.obj"
	-@erase "$(INTDIR)\JDFBlockPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFBookCase.obj"
	-@erase "$(INTDIR)\JDFBookCase.sbr"
	-@erase "$(INTDIR)\JDFBooleanEvaluation.obj"
	-@erase "$(INTDIR)\JDFBooleanEvaluation.sbr"
	-@erase "$(INTDIR)\JDFBooleanState.obj"
	-@erase "$(INTDIR)\JDFBooleanState.sbr"
	-@erase "$(INTDIR)\JDFBoxArgument.obj"
	-@erase "$(INTDIR)\JDFBoxArgument.sbr"
	-@erase "$(INTDIR)\JDFBoxPackingParams.obj"
	-@erase "$(INTDIR)\JDFBoxPackingParams.sbr"
	-@erase "$(INTDIR)\JDFBoxToBoxDifference.obj"
	-@erase "$(INTDIR)\JDFBoxToBoxDifference.sbr"
	-@erase "$(INTDIR)\JDFBufferParams.obj"
	-@erase "$(INTDIR)\JDFBufferParams.sbr"
	-@erase "$(INTDIR)\JDFBundle.obj"
	-@erase "$(INTDIR)\JDFBundle.sbr"
	-@erase "$(INTDIR)\JDFBundleItem.obj"
	-@erase "$(INTDIR)\JDFBundleItem.sbr"
	-@erase "$(INTDIR)\JDFBundlingParams.obj"
	-@erase "$(INTDIR)\JDFBundlingParams.sbr"
	-@erase "$(INTDIR)\JDFBusinessInfo.obj"
	-@erase "$(INTDIR)\JDFBusinessInfo.sbr"
	-@erase "$(INTDIR)\JDFByteMap.obj"
	-@erase "$(INTDIR)\JDFByteMap.sbr"
	-@erase "$(INTDIR)\JDFcall.obj"
	-@erase "$(INTDIR)\JDFcall.sbr"
	-@erase "$(INTDIR)\JDFCaseMakingParams.obj"
	-@erase "$(INTDIR)\JDFCaseMakingParams.sbr"
	-@erase "$(INTDIR)\JDFCasingInParams.obj"
	-@erase "$(INTDIR)\JDFCasingInParams.sbr"
	-@erase "$(INTDIR)\JDFCCITTFaxParams.obj"
	-@erase "$(INTDIR)\JDFCCITTFaxParams.sbr"
	-@erase "$(INTDIR)\JDFChangedAttribute.obj"
	-@erase "$(INTDIR)\JDFChangedAttribute.sbr"
	-@erase "$(INTDIR)\JDFChangedPath.obj"
	-@erase "$(INTDIR)\JDFChangedPath.sbr"
	-@erase "$(INTDIR)\JDFChannelBinding.obj"
	-@erase "$(INTDIR)\JDFChannelBinding.sbr"
	-@erase "$(INTDIR)\JDFChannelBindingParams.obj"
	-@erase "$(INTDIR)\JDFChannelBindingParams.sbr"
	-@erase "$(INTDIR)\JDFchoice.obj"
	-@erase "$(INTDIR)\JDFchoice.sbr"
	-@erase "$(INTDIR)\JDFCIELABMeasuringField.obj"
	-@erase "$(INTDIR)\JDFCIELABMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFCoilBinding.obj"
	-@erase "$(INTDIR)\JDFCoilBinding.sbr"
	-@erase "$(INTDIR)\JDFCoilBindingParams.obj"
	-@erase "$(INTDIR)\JDFCoilBindingParams.sbr"
	-@erase "$(INTDIR)\JDFCollatingItem.obj"
	-@erase "$(INTDIR)\JDFCollatingItem.sbr"
	-@erase "$(INTDIR)\JDFCollectingParams.obj"
	-@erase "$(INTDIR)\JDFCollectingParams.sbr"
	-@erase "$(INTDIR)\JDFColor.obj"
	-@erase "$(INTDIR)\JDFColor.sbr"
	-@erase "$(INTDIR)\JDFColorantAlias.obj"
	-@erase "$(INTDIR)\JDFColorantAlias.sbr"
	-@erase "$(INTDIR)\JDFColorantControl.obj"
	-@erase "$(INTDIR)\JDFColorantControl.sbr"
	-@erase "$(INTDIR)\JDFColorantZoneDetails.obj"
	-@erase "$(INTDIR)\JDFColorantZoneDetails.sbr"
	-@erase "$(INTDIR)\JDFColorControlStrip.obj"
	-@erase "$(INTDIR)\JDFColorControlStrip.sbr"
	-@erase "$(INTDIR)\JDFColorCorrectionOp.obj"
	-@erase "$(INTDIR)\JDFColorCorrectionOp.sbr"
	-@erase "$(INTDIR)\JDFColorCorrectionParams.obj"
	-@erase "$(INTDIR)\JDFColorCorrectionParams.sbr"
	-@erase "$(INTDIR)\JDFColorIntent.obj"
	-@erase "$(INTDIR)\JDFColorIntent.sbr"
	-@erase "$(INTDIR)\JDFColorMeasurementConditions.obj"
	-@erase "$(INTDIR)\JDFColorMeasurementConditions.sbr"
	-@erase "$(INTDIR)\JDFColorPool.obj"
	-@erase "$(INTDIR)\JDFColorPool.sbr"
	-@erase "$(INTDIR)\JDFColorSpaceConversionOp.obj"
	-@erase "$(INTDIR)\JDFColorSpaceConversionOp.sbr"
	-@erase "$(INTDIR)\JDFColorSpaceConversionParams.obj"
	-@erase "$(INTDIR)\JDFColorSpaceConversionParams.sbr"
	-@erase "$(INTDIR)\JDFColorSpaceSubstitute.obj"
	-@erase "$(INTDIR)\JDFColorSpaceSubstitute.sbr"
	-@erase "$(INTDIR)\JDFColorsUsed.obj"
	-@erase "$(INTDIR)\JDFColorsUsed.sbr"
	-@erase "$(INTDIR)\JDFComChannel.obj"
	-@erase "$(INTDIR)\JDFComChannel.sbr"
	-@erase "$(INTDIR)\JDFCommand.obj"
	-@erase "$(INTDIR)\JDFCommand.sbr"
	-@erase "$(INTDIR)\JDFComment.obj"
	-@erase "$(INTDIR)\JDFComment.sbr"
	-@erase "$(INTDIR)\JDFCompany.obj"
	-@erase "$(INTDIR)\JDFCompany.sbr"
	-@erase "$(INTDIR)\JDFComponent.obj"
	-@erase "$(INTDIR)\JDFComponent.sbr"
	-@erase "$(INTDIR)\JDFContact.obj"
	-@erase "$(INTDIR)\JDFContact.sbr"
	-@erase "$(INTDIR)\JDFContactCopyParams.obj"
	-@erase "$(INTDIR)\JDFContactCopyParams.sbr"
	-@erase "$(INTDIR)\JDFContainer.obj"
	-@erase "$(INTDIR)\JDFContainer.sbr"
	-@erase "$(INTDIR)\JDFContentObject.obj"
	-@erase "$(INTDIR)\JDFContentObject.sbr"
	-@erase "$(INTDIR)\JDFConventionalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFConventionalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFCostCenter.obj"
	-@erase "$(INTDIR)\JDFCostCenter.sbr"
	-@erase "$(INTDIR)\JDFCounterReset.obj"
	-@erase "$(INTDIR)\JDFCounterReset.sbr"
	-@erase "$(INTDIR)\JDFCoverApplicationParams.obj"
	-@erase "$(INTDIR)\JDFCoverApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFCrease.obj"
	-@erase "$(INTDIR)\JDFCrease.sbr"
	-@erase "$(INTDIR)\JDFCreasingParams.obj"
	-@erase "$(INTDIR)\JDFCreasingParams.sbr"
	-@erase "$(INTDIR)\JDFCreated.obj"
	-@erase "$(INTDIR)\JDFCreated.sbr"
	-@erase "$(INTDIR)\JDFCreditCard.obj"
	-@erase "$(INTDIR)\JDFCreditCard.sbr"
	-@erase "$(INTDIR)\JDFCustomerInfo.obj"
	-@erase "$(INTDIR)\JDFCustomerInfo.sbr"
	-@erase "$(INTDIR)\JDFCustomerMessage.obj"
	-@erase "$(INTDIR)\JDFCustomerMessage.sbr"
	-@erase "$(INTDIR)\JDFCut.obj"
	-@erase "$(INTDIR)\JDFCut.sbr"
	-@erase "$(INTDIR)\JDFCutBlock.obj"
	-@erase "$(INTDIR)\JDFCutBlock.sbr"
	-@erase "$(INTDIR)\JDFCutMark.obj"
	-@erase "$(INTDIR)\JDFCutMark.sbr"
	-@erase "$(INTDIR)\JDFCuttingParams.obj"
	-@erase "$(INTDIR)\JDFCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFDateTimeEvaluation.obj"
	-@erase "$(INTDIR)\JDFDateTimeEvaluation.sbr"
	-@erase "$(INTDIR)\JDFDateTimeRange.obj"
	-@erase "$(INTDIR)\JDFDateTimeRange.sbr"
	-@erase "$(INTDIR)\JDFDateTimeRangeList.obj"
	-@erase "$(INTDIR)\JDFDateTimeRangeList.sbr"
	-@erase "$(INTDIR)\JDFDateTimeState.obj"
	-@erase "$(INTDIR)\JDFDateTimeState.sbr"
	-@erase "$(INTDIR)\JDFDBMergeParams.obj"
	-@erase "$(INTDIR)\JDFDBMergeParams.sbr"
	-@erase "$(INTDIR)\JDFDBRules.obj"
	-@erase "$(INTDIR)\JDFDBRules.sbr"
	-@erase "$(INTDIR)\JDFDBSchema.obj"
	-@erase "$(INTDIR)\JDFDBSchema.sbr"
	-@erase "$(INTDIR)\JDFDBSelection.obj"
	-@erase "$(INTDIR)\JDFDBSelection.sbr"
	-@erase "$(INTDIR)\JDFDCTParams.obj"
	-@erase "$(INTDIR)\JDFDCTParams.sbr"
	-@erase "$(INTDIR)\JDFDeleted.obj"
	-@erase "$(INTDIR)\JDFDeleted.sbr"
	-@erase "$(INTDIR)\JDFDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFDensityMeasuringField.obj"
	-@erase "$(INTDIR)\JDFDensityMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFDependencies.obj"
	-@erase "$(INTDIR)\JDFDependencies.sbr"
	-@erase "$(INTDIR)\JDFDevCap.obj"
	-@erase "$(INTDIR)\JDFDevCap.sbr"
	-@erase "$(INTDIR)\JDFDevCaps.obj"
	-@erase "$(INTDIR)\JDFDevCaps.sbr"
	-@erase "$(INTDIR)\JDFDevelopingParams.obj"
	-@erase "$(INTDIR)\JDFDevelopingParams.sbr"
	-@erase "$(INTDIR)\JDFDevice.obj"
	-@erase "$(INTDIR)\JDFDevice.sbr"
	-@erase "$(INTDIR)\JDFDeviceCap.obj"
	-@erase "$(INTDIR)\JDFDeviceCap.sbr"
	-@erase "$(INTDIR)\JDFDeviceFilter.obj"
	-@erase "$(INTDIR)\JDFDeviceFilter.sbr"
	-@erase "$(INTDIR)\JDFDeviceInfo.obj"
	-@erase "$(INTDIR)\JDFDeviceInfo.sbr"
	-@erase "$(INTDIR)\JDFDeviceList.obj"
	-@erase "$(INTDIR)\JDFDeviceList.sbr"
	-@erase "$(INTDIR)\JDFDeviceMark.obj"
	-@erase "$(INTDIR)\JDFDeviceMark.sbr"
	-@erase "$(INTDIR)\JDFDeviceNColor.obj"
	-@erase "$(INTDIR)\JDFDeviceNColor.sbr"
	-@erase "$(INTDIR)\JDFDeviceNSpace.obj"
	-@erase "$(INTDIR)\JDFDeviceNSpace.sbr"
	-@erase "$(INTDIR)\JDFDigitalDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFDigitalDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFDigitalMedia.obj"
	-@erase "$(INTDIR)\JDFDigitalMedia.sbr"
	-@erase "$(INTDIR)\JDFDigitalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFDigitalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFDisjointing.obj"
	-@erase "$(INTDIR)\JDFDisjointing.sbr"
	-@erase "$(INTDIR)\JDFDisplayGroup.obj"
	-@erase "$(INTDIR)\JDFDisplayGroup.sbr"
	-@erase "$(INTDIR)\JDFDisplayGroupPool.obj"
	-@erase "$(INTDIR)\JDFDisplayGroupPool.sbr"
	-@erase "$(INTDIR)\JDFDisposition.obj"
	-@erase "$(INTDIR)\JDFDisposition.sbr"
	-@erase "$(INTDIR)\JDFDividingParams.obj"
	-@erase "$(INTDIR)\JDFDividingParams.sbr"
	-@erase "$(INTDIR)\JDFDoc.obj"
	-@erase "$(INTDIR)\JDFDoc.sbr"
	-@erase "$(INTDIR)\JDFDrop.obj"
	-@erase "$(INTDIR)\JDFDrop.sbr"
	-@erase "$(INTDIR)\JDFDropIntent.obj"
	-@erase "$(INTDIR)\JDFDropIntent.sbr"
	-@erase "$(INTDIR)\JDFDropItem.obj"
	-@erase "$(INTDIR)\JDFDropItem.sbr"
	-@erase "$(INTDIR)\JDFDropItemIntent.obj"
	-@erase "$(INTDIR)\JDFDropItemIntent.sbr"
	-@erase "$(INTDIR)\JDFDurationEvaluation.obj"
	-@erase "$(INTDIR)\JDFDurationEvaluation.sbr"
	-@erase "$(INTDIR)\JDFDurationRange.obj"
	-@erase "$(INTDIR)\JDFDurationRange.sbr"
	-@erase "$(INTDIR)\JDFDurationRangeList.obj"
	-@erase "$(INTDIR)\JDFDurationRangeList.sbr"
	-@erase "$(INTDIR)\JDFDurationState.obj"
	-@erase "$(INTDIR)\JDFDurationState.sbr"
	-@erase "$(INTDIR)\JDFDynamicField.obj"
	-@erase "$(INTDIR)\JDFDynamicField.sbr"
	-@erase "$(INTDIR)\JDFDynamicInput.obj"
	-@erase "$(INTDIR)\JDFDynamicInput.sbr"
	-@erase "$(INTDIR)\JDFEdgeGluing.obj"
	-@erase "$(INTDIR)\JDFEdgeGluing.sbr"
	-@erase "$(INTDIR)\JDFElement.obj"
	-@erase "$(INTDIR)\JDFElement.sbr"
	-@erase "$(INTDIR)\JDFElementColorParams.obj"
	-@erase "$(INTDIR)\JDFElementColorParams.sbr"
	-@erase "$(INTDIR)\JDFEmboss.obj"
	-@erase "$(INTDIR)\JDFEmboss.sbr"
	-@erase "$(INTDIR)\JDFEmbossingIntent.obj"
	-@erase "$(INTDIR)\JDFEmbossingIntent.sbr"
	-@erase "$(INTDIR)\JDFEmbossingItem.obj"
	-@erase "$(INTDIR)\JDFEmbossingItem.sbr"
	-@erase "$(INTDIR)\JDFEmbossingParams.obj"
	-@erase "$(INTDIR)\JDFEmbossingParams.sbr"
	-@erase "$(INTDIR)\JDFEmployee.obj"
	-@erase "$(INTDIR)\JDFEmployee.sbr"
	-@erase "$(INTDIR)\JDFEmployeeDef.obj"
	-@erase "$(INTDIR)\JDFEmployeeDef.sbr"
	-@erase "$(INTDIR)\JDFEndSheet.obj"
	-@erase "$(INTDIR)\JDFEndSheet.sbr"
	-@erase "$(INTDIR)\JDFEndSheetGluingParams.obj"
	-@erase "$(INTDIR)\JDFEndSheetGluingParams.sbr"
	-@erase "$(INTDIR)\JDFEnumerationEvaluation.obj"
	-@erase "$(INTDIR)\JDFEnumerationEvaluation.sbr"
	-@erase "$(INTDIR)\JDFEnumerationState.obj"
	-@erase "$(INTDIR)\JDFEnumerationState.sbr"
	-@erase "$(INTDIR)\JDFError.obj"
	-@erase "$(INTDIR)\JDFError.sbr"
	-@erase "$(INTDIR)\JDFEvaluation.obj"
	-@erase "$(INTDIR)\JDFEvaluation.sbr"
	-@erase "$(INTDIR)\JDFEvent.obj"
	-@erase "$(INTDIR)\JDFEvent.sbr"
	-@erase "$(INTDIR)\JDFExposedMedia.obj"
	-@erase "$(INTDIR)\JDFExposedMedia.sbr"
	-@erase "$(INTDIR)\JDFFactory.obj"
	-@erase "$(INTDIR)\JDFFactory.sbr"
	-@erase "$(INTDIR)\JDFFCNKey.obj"
	-@erase "$(INTDIR)\JDFFCNKey.sbr"
	-@erase "$(INTDIR)\JDFFeatureAttribute.obj"
	-@erase "$(INTDIR)\JDFFeatureAttribute.sbr"
	-@erase "$(INTDIR)\JDFFeaturePool.obj"
	-@erase "$(INTDIR)\JDFFeaturePool.sbr"
	-@erase "$(INTDIR)\JDFFeeder.obj"
	-@erase "$(INTDIR)\JDFFeeder.sbr"
	-@erase "$(INTDIR)\JDFFeederQualityParams.obj"
	-@erase "$(INTDIR)\JDFFeederQualityParams.sbr"
	-@erase "$(INTDIR)\JDFFeedingParams.obj"
	-@erase "$(INTDIR)\JDFFeedingParams.sbr"
	-@erase "$(INTDIR)\JDFFileAlias.obj"
	-@erase "$(INTDIR)\JDFFileAlias.sbr"
	-@erase "$(INTDIR)\JDFFileSpec.obj"
	-@erase "$(INTDIR)\JDFFileSpec.sbr"
	-@erase "$(INTDIR)\JDFFitPolicy.obj"
	-@erase "$(INTDIR)\JDFFitPolicy.sbr"
	-@erase "$(INTDIR)\JDFFlateParams.obj"
	-@erase "$(INTDIR)\JDFFlateParams.sbr"
	-@erase "$(INTDIR)\JDFFlushedResources.obj"
	-@erase "$(INTDIR)\JDFFlushedResources.sbr"
	-@erase "$(INTDIR)\JDFFlushQueueParams.obj"
	-@erase "$(INTDIR)\JDFFlushQueueParams.sbr"
	-@erase "$(INTDIR)\JDFFlushResourceParams.obj"
	-@erase "$(INTDIR)\JDFFlushResourceParams.sbr"
	-@erase "$(INTDIR)\JDFFold.obj"
	-@erase "$(INTDIR)\JDFFold.sbr"
	-@erase "$(INTDIR)\JDFFoldingIntent.obj"
	-@erase "$(INTDIR)\JDFFoldingIntent.sbr"
	-@erase "$(INTDIR)\JDFFoldingParams.obj"
	-@erase "$(INTDIR)\JDFFoldingParams.sbr"
	-@erase "$(INTDIR)\JDFFontParams.obj"
	-@erase "$(INTDIR)\JDFFontParams.sbr"
	-@erase "$(INTDIR)\JDFFontPolicy.obj"
	-@erase "$(INTDIR)\JDFFontPolicy.sbr"
	-@erase "$(INTDIR)\JDFFormatConversionParams.obj"
	-@erase "$(INTDIR)\JDFFormatConversionParams.sbr"
	-@erase "$(INTDIR)\JDFGatheringParams.obj"
	-@erase "$(INTDIR)\JDFGatheringParams.sbr"
	-@erase "$(INTDIR)\JDFGlue.obj"
	-@erase "$(INTDIR)\JDFGlue.sbr"
	-@erase "$(INTDIR)\JDFGlueApplication.obj"
	-@erase "$(INTDIR)\JDFGlueApplication.sbr"
	-@erase "$(INTDIR)\JDFGlueLine.obj"
	-@erase "$(INTDIR)\JDFGlueLine.sbr"
	-@erase "$(INTDIR)\JDFGluingParams.obj"
	-@erase "$(INTDIR)\JDFGluingParams.sbr"
	-@erase "$(INTDIR)\JDFHardCoverBinding.obj"
	-@erase "$(INTDIR)\JDFHardCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFHeadBandApplicationParams.obj"
	-@erase "$(INTDIR)\JDFHeadBandApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFHole.obj"
	-@erase "$(INTDIR)\JDFHole.sbr"
	-@erase "$(INTDIR)\JDFHoleLine.obj"
	-@erase "$(INTDIR)\JDFHoleLine.sbr"
	-@erase "$(INTDIR)\JDFHoleList.obj"
	-@erase "$(INTDIR)\JDFHoleList.sbr"
	-@erase "$(INTDIR)\JDFHoleMakingIntent.obj"
	-@erase "$(INTDIR)\JDFHoleMakingIntent.sbr"
	-@erase "$(INTDIR)\JDFHoleMakingParams.obj"
	-@erase "$(INTDIR)\JDFHoleMakingParams.sbr"
	-@erase "$(INTDIR)\JDFIcon.obj"
	-@erase "$(INTDIR)\JDFIcon.sbr"
	-@erase "$(INTDIR)\JDFIconList.obj"
	-@erase "$(INTDIR)\JDFIconList.sbr"
	-@erase "$(INTDIR)\JDFIdentificationField.obj"
	-@erase "$(INTDIR)\JDFIdentificationField.sbr"
	-@erase "$(INTDIR)\JDFIDInfo.obj"
	-@erase "$(INTDIR)\JDFIDInfo.sbr"
	-@erase "$(INTDIR)\JDFIDPCover.obj"
	-@erase "$(INTDIR)\JDFIDPCover.sbr"
	-@erase "$(INTDIR)\JDFIDPFinishing.obj"
	-@erase "$(INTDIR)\JDFIDPFinishing.sbr"
	-@erase "$(INTDIR)\JDFIDPFolding.obj"
	-@erase "$(INTDIR)\JDFIDPFolding.sbr"
	-@erase "$(INTDIR)\JDFIDPHoleMaking.obj"
	-@erase "$(INTDIR)\JDFIDPHoleMaking.sbr"
	-@erase "$(INTDIR)\JDFIDPImageShift.obj"
	-@erase "$(INTDIR)\JDFIDPImageShift.sbr"
	-@erase "$(INTDIR)\JDFIDPJobSheet.obj"
	-@erase "$(INTDIR)\JDFIDPJobSheet.sbr"
	-@erase "$(INTDIR)\JDFIDPLayout.obj"
	-@erase "$(INTDIR)\JDFIDPLayout.sbr"
	-@erase "$(INTDIR)\JDFIDPrintingParams.obj"
	-@erase "$(INTDIR)\JDFIDPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFIDPStitching.obj"
	-@erase "$(INTDIR)\JDFIDPStitching.sbr"
	-@erase "$(INTDIR)\JDFIDPTrimming.obj"
	-@erase "$(INTDIR)\JDFIDPTrimming.sbr"
	-@erase "$(INTDIR)\JDFImageCompression.obj"
	-@erase "$(INTDIR)\JDFImageCompression.sbr"
	-@erase "$(INTDIR)\JDFImageCompressionParams.obj"
	-@erase "$(INTDIR)\JDFImageCompressionParams.sbr"
	-@erase "$(INTDIR)\JDFImageReplacementParams.obj"
	-@erase "$(INTDIR)\JDFImageReplacementParams.sbr"
	-@erase "$(INTDIR)\JDFImageSetterParams.obj"
	-@erase "$(INTDIR)\JDFImageSetterParams.sbr"
	-@erase "$(INTDIR)\JDFImageShift.obj"
	-@erase "$(INTDIR)\JDFImageShift.sbr"
	-@erase "$(INTDIR)\JDFInk.obj"
	-@erase "$(INTDIR)\JDFInk.sbr"
	-@erase "$(INTDIR)\JDFInkZoneCalculationParams.obj"
	-@erase "$(INTDIR)\JDFInkZoneCalculationParams.sbr"
	-@erase "$(INTDIR)\JDFInkZoneProfile.obj"
	-@erase "$(INTDIR)\JDFInkZoneProfile.sbr"
	-@erase "$(INTDIR)\JDFInsert.obj"
	-@erase "$(INTDIR)\JDFInsert.sbr"
	-@erase "$(INTDIR)\JDFInsertingIntent.obj"
	-@erase "$(INTDIR)\JDFInsertingIntent.sbr"
	-@erase "$(INTDIR)\JDFInsertingParams.obj"
	-@erase "$(INTDIR)\JDFInsertingParams.sbr"
	-@erase "$(INTDIR)\JDFInsertList.obj"
	-@erase "$(INTDIR)\JDFInsertList.sbr"
	-@erase "$(INTDIR)\JDFInsertSheet.obj"
	-@erase "$(INTDIR)\JDFInsertSheet.sbr"
	-@erase "$(INTDIR)\JDFIntegerEvaluation.obj"
	-@erase "$(INTDIR)\JDFIntegerEvaluation.sbr"
	-@erase "$(INTDIR)\JDFIntegerRange.obj"
	-@erase "$(INTDIR)\JDFIntegerRange.sbr"
	-@erase "$(INTDIR)\JDFIntegerRangeList.obj"
	-@erase "$(INTDIR)\JDFIntegerRangeList.sbr"
	-@erase "$(INTDIR)\JDFIntegerState.obj"
	-@erase "$(INTDIR)\JDFIntegerState.sbr"
	-@erase "$(INTDIR)\JDFIntentResource.obj"
	-@erase "$(INTDIR)\JDFIntentResource.sbr"
	-@erase "$(INTDIR)\JDFInterpretedPDLData.obj"
	-@erase "$(INTDIR)\JDFInterpretedPDLData.sbr"
	-@erase "$(INTDIR)\JDFInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFIsPresentEvaluation.obj"
	-@erase "$(INTDIR)\JDFIsPresentEvaluation.sbr"
	-@erase "$(INTDIR)\JDFJacketingParams.obj"
	-@erase "$(INTDIR)\JDFJacketingParams.sbr"
	-@erase "$(INTDIR)\JDFJDFController.obj"
	-@erase "$(INTDIR)\JDFJDFController.sbr"
	-@erase "$(INTDIR)\JDFJDFService.obj"
	-@erase "$(INTDIR)\JDFJDFService.sbr"
	-@erase "$(INTDIR)\JDFJMF.obj"
	-@erase "$(INTDIR)\JDFJMF.sbr"
	-@erase "$(INTDIR)\JDFJobField.obj"
	-@erase "$(INTDIR)\JDFJobField.sbr"
	-@erase "$(INTDIR)\JDFJobPhase.obj"
	-@erase "$(INTDIR)\JDFJobPhase.sbr"
	-@erase "$(INTDIR)\JDFKnownMsgQuParams.obj"
	-@erase "$(INTDIR)\JDFKnownMsgQuParams.sbr"
	-@erase "$(INTDIR)\JDFLabelingParams.obj"
	-@erase "$(INTDIR)\JDFLabelingParams.sbr"
	-@erase "$(INTDIR)\JDFLaminatingIntent.obj"
	-@erase "$(INTDIR)\JDFLaminatingIntent.sbr"
	-@erase "$(INTDIR)\JDFLaminatingParams.obj"
	-@erase "$(INTDIR)\JDFLaminatingParams.sbr"
	-@erase "$(INTDIR)\JDFLayerDetails.obj"
	-@erase "$(INTDIR)\JDFLayerDetails.sbr"
	-@erase "$(INTDIR)\JDFLayerList.obj"
	-@erase "$(INTDIR)\JDFLayerList.sbr"
	-@erase "$(INTDIR)\JDFLayout.obj"
	-@erase "$(INTDIR)\JDFLayout.sbr"
	-@erase "$(INTDIR)\JDFLayoutElement.obj"
	-@erase "$(INTDIR)\JDFLayoutElement.sbr"
	-@erase "$(INTDIR)\JDFLayoutIntent.obj"
	-@erase "$(INTDIR)\JDFLayoutIntent.sbr"
	-@erase "$(INTDIR)\JDFLayoutPreparationParams.obj"
	-@erase "$(INTDIR)\JDFLayoutPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFLoc.obj"
	-@erase "$(INTDIR)\JDFLoc.sbr"
	-@erase "$(INTDIR)\JDFLocation.obj"
	-@erase "$(INTDIR)\JDFLocation.sbr"
	-@erase "$(INTDIR)\JDFLongFold.obj"
	-@erase "$(INTDIR)\JDFLongFold.sbr"
	-@erase "$(INTDIR)\JDFLongGlue.obj"
	-@erase "$(INTDIR)\JDFLongGlue.sbr"
	-@erase "$(INTDIR)\JDFLongitudinalRibbonOperationParams.obj"
	-@erase "$(INTDIR)\JDFLongitudinalRibbonOperationParams.sbr"
	-@erase "$(INTDIR)\JDFLongPerforate.obj"
	-@erase "$(INTDIR)\JDFLongPerforate.sbr"
	-@erase "$(INTDIR)\JDFLongSlit.obj"
	-@erase "$(INTDIR)\JDFLongSlit.sbr"
	-@erase "$(INTDIR)\JDFLZWParams.obj"
	-@erase "$(INTDIR)\JDFLZWParams.sbr"
	-@erase "$(INTDIR)\JDFmacro.obj"
	-@erase "$(INTDIR)\JDFmacro.sbr"
	-@erase "$(INTDIR)\JDFMacroPool.obj"
	-@erase "$(INTDIR)\JDFMacroPool.sbr"
	-@erase "$(INTDIR)\JDFManualLaborParams.obj"
	-@erase "$(INTDIR)\JDFManualLaborParams.sbr"
	-@erase "$(INTDIR)\JDFMarkObject.obj"
	-@erase "$(INTDIR)\JDFMarkObject.sbr"
	-@erase "$(INTDIR)\JDFMatrixEvaluation.obj"
	-@erase "$(INTDIR)\JDFMatrixEvaluation.sbr"
	-@erase "$(INTDIR)\JDFMatrixState.obj"
	-@erase "$(INTDIR)\JDFMatrixState.sbr"
	-@erase "$(INTDIR)\JDFMedia.obj"
	-@erase "$(INTDIR)\JDFMedia.sbr"
	-@erase "$(INTDIR)\JDFMediaIntent.obj"
	-@erase "$(INTDIR)\JDFMediaIntent.sbr"
	-@erase "$(INTDIR)\JDFMediaSource.obj"
	-@erase "$(INTDIR)\JDFMediaSource.sbr"
	-@erase "$(INTDIR)\JDFMerged.obj"
	-@erase "$(INTDIR)\JDFMerged.sbr"
	-@erase "$(INTDIR)\JDFMessage.obj"
	-@erase "$(INTDIR)\JDFMessage.sbr"
	-@erase "$(INTDIR)\JDFMessageElement.obj"
	-@erase "$(INTDIR)\JDFMessageElement.sbr"
	-@erase "$(INTDIR)\JDFMessageService.obj"
	-@erase "$(INTDIR)\JDFMessageService.sbr"
	-@erase "$(INTDIR)\JDFMISDetails.obj"
	-@erase "$(INTDIR)\JDFMISDetails.sbr"
	-@erase "$(INTDIR)\JDFModified.obj"
	-@erase "$(INTDIR)\JDFModified.sbr"
	-@erase "$(INTDIR)\JDFModulePhase.obj"
	-@erase "$(INTDIR)\JDFModulePhase.sbr"
	-@erase "$(INTDIR)\JDFModuleStatus.obj"
	-@erase "$(INTDIR)\JDFModuleStatus.sbr"
	-@erase "$(INTDIR)\JDFMsgFilter.obj"
	-@erase "$(INTDIR)\JDFMsgFilter.sbr"
	-@erase "$(INTDIR)\JDFNameEvaluation.obj"
	-@erase "$(INTDIR)\JDFNameEvaluation.sbr"
	-@erase "$(INTDIR)\JDFNameRangeList.obj"
	-@erase "$(INTDIR)\JDFNameRangeList.sbr"
	-@erase "$(INTDIR)\JDFNameState.obj"
	-@erase "$(INTDIR)\JDFNameState.sbr"
	-@erase "$(INTDIR)\JDFNewJDFCmdParams.obj"
	-@erase "$(INTDIR)\JDFNewJDFCmdParams.sbr"
	-@erase "$(INTDIR)\JDFNewJDFQuParams.obj"
	-@erase "$(INTDIR)\JDFNewJDFQuParams.sbr"
	-@erase "$(INTDIR)\JDFNode.obj"
	-@erase "$(INTDIR)\JDFNode.sbr"
	-@erase "$(INTDIR)\JDFNodeFactory.obj"
	-@erase "$(INTDIR)\JDFNodeFactory.sbr"
	-@erase "$(INTDIR)\JDFNodeInfo.obj"
	-@erase "$(INTDIR)\JDFNodeInfo.sbr"
	-@erase "$(INTDIR)\JDFNodeInfoCmdParams.obj"
	-@erase "$(INTDIR)\JDFNodeInfoCmdParams.sbr"
	-@erase "$(INTDIR)\JDFNodeInfoQuParams.obj"
	-@erase "$(INTDIR)\JDFNodeInfoQuParams.sbr"
	-@erase "$(INTDIR)\JDFNodeInfoResp.obj"
	-@erase "$(INTDIR)\JDFNodeInfoResp.sbr"
	-@erase "$(INTDIR)\JDFnot.obj"
	-@erase "$(INTDIR)\JDFnot.sbr"
	-@erase "$(INTDIR)\JDFNotification.obj"
	-@erase "$(INTDIR)\JDFNotification.sbr"
	-@erase "$(INTDIR)\JDFNotificationDef.obj"
	-@erase "$(INTDIR)\JDFNotificationDef.sbr"
	-@erase "$(INTDIR)\JDFNotificationFilter.obj"
	-@erase "$(INTDIR)\JDFNotificationFilter.sbr"
	-@erase "$(INTDIR)\JDFNumberEvaluation.obj"
	-@erase "$(INTDIR)\JDFNumberEvaluation.sbr"
	-@erase "$(INTDIR)\JDFNumberingIntent.obj"
	-@erase "$(INTDIR)\JDFNumberingIntent.sbr"
	-@erase "$(INTDIR)\JDFNumberingParam.obj"
	-@erase "$(INTDIR)\JDFNumberingParam.sbr"
	-@erase "$(INTDIR)\JDFNumberingParams.obj"
	-@erase "$(INTDIR)\JDFNumberingParams.sbr"
	-@erase "$(INTDIR)\JDFNumberItem.obj"
	-@erase "$(INTDIR)\JDFNumberItem.sbr"
	-@erase "$(INTDIR)\JDFNumberRangeList.obj"
	-@erase "$(INTDIR)\JDFNumberRangeList.sbr"
	-@erase "$(INTDIR)\JDFNumberState.obj"
	-@erase "$(INTDIR)\JDFNumberState.sbr"
	-@erase "$(INTDIR)\JDFNumTypeList.obj"
	-@erase "$(INTDIR)\JDFNumTypeList.sbr"
	-@erase "$(INTDIR)\JDFObjectResolution.obj"
	-@erase "$(INTDIR)\JDFObjectResolution.sbr"
	-@erase "$(INTDIR)\JDFObservationTarget.obj"
	-@erase "$(INTDIR)\JDFObservationTarget.sbr"
	-@erase "$(INTDIR)\JDFOccupation.obj"
	-@erase "$(INTDIR)\JDFOccupation.sbr"
	-@erase "$(INTDIR)\JDFor.obj"
	-@erase "$(INTDIR)\JDFor.sbr"
	-@erase "$(INTDIR)\JDFOrderingParams.obj"
	-@erase "$(INTDIR)\JDFOrderingParams.sbr"
	-@erase "$(INTDIR)\JDFotherwise.obj"
	-@erase "$(INTDIR)\JDFotherwise.sbr"
	-@erase "$(INTDIR)\JDFPackingIntent.obj"
	-@erase "$(INTDIR)\JDFPackingIntent.sbr"
	-@erase "$(INTDIR)\JDFPackingParams.obj"
	-@erase "$(INTDIR)\JDFPackingParams.sbr"
	-@erase "$(INTDIR)\JDFPageCell.obj"
	-@erase "$(INTDIR)\JDFPageCell.sbr"
	-@erase "$(INTDIR)\JDFPageData.obj"
	-@erase "$(INTDIR)\JDFPageData.sbr"
	-@erase "$(INTDIR)\JDFPageList.obj"
	-@erase "$(INTDIR)\JDFPageList.sbr"
	-@erase "$(INTDIR)\JDFPallet.obj"
	-@erase "$(INTDIR)\JDFPallet.sbr"
	-@erase "$(INTDIR)\JDFPalletizingParams.obj"
	-@erase "$(INTDIR)\JDFPalletizingParams.sbr"
	-@erase "$(INTDIR)\JDFParamsFactory.obj"
	-@erase "$(INTDIR)\JDFParamsFactory.sbr"
	-@erase "$(INTDIR)\JDFParser.obj"
	-@erase "$(INTDIR)\JDFParser.sbr"
	-@erase "$(INTDIR)\JDFPart.obj"
	-@erase "$(INTDIR)\JDFPart.sbr"
	-@erase "$(INTDIR)\JDFPartAmount.obj"
	-@erase "$(INTDIR)\JDFPartAmount.sbr"
	-@erase "$(INTDIR)\JDFPartStatus.obj"
	-@erase "$(INTDIR)\JDFPartStatus.sbr"
	-@erase "$(INTDIR)\JDFPayment.obj"
	-@erase "$(INTDIR)\JDFPayment.sbr"
	-@erase "$(INTDIR)\JDFPDFInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFPDFInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFPDFPathEvaluation.obj"
	-@erase "$(INTDIR)\JDFPDFPathEvaluation.sbr"
	-@erase "$(INTDIR)\JDFPDFPathState.obj"
	-@erase "$(INTDIR)\JDFPDFPathState.sbr"
	-@erase "$(INTDIR)\JDFPDFToPSConversionParams.obj"
	-@erase "$(INTDIR)\JDFPDFToPSConversionParams.sbr"
	-@erase "$(INTDIR)\JDFPDFXParams.obj"
	-@erase "$(INTDIR)\JDFPDFXParams.sbr"
	-@erase "$(INTDIR)\JDFPDLResourceAlias.obj"
	-@erase "$(INTDIR)\JDFPDLResourceAlias.sbr"
	-@erase "$(INTDIR)\JDFPerforate.obj"
	-@erase "$(INTDIR)\JDFPerforate.sbr"
	-@erase "$(INTDIR)\JDFPerforatingParams.obj"
	-@erase "$(INTDIR)\JDFPerforatingParams.sbr"
	-@erase "$(INTDIR)\JDFPerformance.obj"
	-@erase "$(INTDIR)\JDFPerformance.sbr"
	-@erase "$(INTDIR)\JDFPerson.obj"
	-@erase "$(INTDIR)\JDFPerson.sbr"
	-@erase "$(INTDIR)\JDFPhaseTime.obj"
	-@erase "$(INTDIR)\JDFPhaseTime.sbr"
	-@erase "$(INTDIR)\JDFPipeParams.obj"
	-@erase "$(INTDIR)\JDFPipeParams.sbr"
	-@erase "$(INTDIR)\JDFPixelColorant.obj"
	-@erase "$(INTDIR)\JDFPixelColorant.sbr"
	-@erase "$(INTDIR)\JDFPlaceHolderResource.obj"
	-@erase "$(INTDIR)\JDFPlaceHolderResource.sbr"
	-@erase "$(INTDIR)\JDFPlasticCombBinding.obj"
	-@erase "$(INTDIR)\JDFPlasticCombBinding.sbr"
	-@erase "$(INTDIR)\JDFPlasticCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFPlasticCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFPlateCopyParams.obj"
	-@erase "$(INTDIR)\JDFPlateCopyParams.sbr"
	-@erase "$(INTDIR)\JDFPool.obj"
	-@erase "$(INTDIR)\JDFPool.sbr"
	-@erase "$(INTDIR)\JDFPosition.obj"
	-@erase "$(INTDIR)\JDFPosition.sbr"
	-@erase "$(INTDIR)\JDFPreflightAction.obj"
	-@erase "$(INTDIR)\JDFPreflightAction.sbr"
	-@erase "$(INTDIR)\JDFPreflightAnalysis.obj"
	-@erase "$(INTDIR)\JDFPreflightAnalysis.sbr"
	-@erase "$(INTDIR)\JDFPreflightArgument.obj"
	-@erase "$(INTDIR)\JDFPreflightArgument.sbr"
	-@erase "$(INTDIR)\JDFPreflightConstraint.obj"
	-@erase "$(INTDIR)\JDFPreflightConstraint.sbr"
	-@erase "$(INTDIR)\JDFPreflightConstraintsPool.obj"
	-@erase "$(INTDIR)\JDFPreflightConstraintsPool.sbr"
	-@erase "$(INTDIR)\JDFPreflightDetail.obj"
	-@erase "$(INTDIR)\JDFPreflightDetail.sbr"
	-@erase "$(INTDIR)\JDFPreflightInstance.obj"
	-@erase "$(INTDIR)\JDFPreflightInstance.sbr"
	-@erase "$(INTDIR)\JDFPreflightInstanceDetail.obj"
	-@erase "$(INTDIR)\JDFPreflightInstanceDetail.sbr"
	-@erase "$(INTDIR)\JDFPreflightInventory.obj"
	-@erase "$(INTDIR)\JDFPreflightInventory.sbr"
	-@erase "$(INTDIR)\JDFPreflightParams.obj"
	-@erase "$(INTDIR)\JDFPreflightParams.sbr"
	-@erase "$(INTDIR)\JDFPreflightProfile.obj"
	-@erase "$(INTDIR)\JDFPreflightProfile.sbr"
	-@erase "$(INTDIR)\JDFPreflightReport.obj"
	-@erase "$(INTDIR)\JDFPreflightReport.sbr"
	-@erase "$(INTDIR)\JDFPreflightReportRulePool.obj"
	-@erase "$(INTDIR)\JDFPreflightReportRulePool.sbr"
	-@erase "$(INTDIR)\JDFPreflightResultsPool.obj"
	-@erase "$(INTDIR)\JDFPreflightResultsPool.sbr"
	-@erase "$(INTDIR)\JDFPreflightValue.obj"
	-@erase "$(INTDIR)\JDFPreflightValue.sbr"
	-@erase "$(INTDIR)\JDFPRError.obj"
	-@erase "$(INTDIR)\JDFPRError.sbr"
	-@erase "$(INTDIR)\JDFPreview.obj"
	-@erase "$(INTDIR)\JDFPreview.sbr"
	-@erase "$(INTDIR)\JDFPreviewGenerationParams.obj"
	-@erase "$(INTDIR)\JDFPreviewGenerationParams.sbr"
	-@erase "$(INTDIR)\JDFPRGroup.obj"
	-@erase "$(INTDIR)\JDFPRGroup.sbr"
	-@erase "$(INTDIR)\JDFPRGroupOccurence.obj"
	-@erase "$(INTDIR)\JDFPRGroupOccurence.sbr"
	-@erase "$(INTDIR)\JDFPRGroupOccurenceBase.obj"
	-@erase "$(INTDIR)\JDFPRGroupOccurenceBase.sbr"
	-@erase "$(INTDIR)\JDFPricing.obj"
	-@erase "$(INTDIR)\JDFPricing.sbr"
	-@erase "$(INTDIR)\JDFPrintCondition.obj"
	-@erase "$(INTDIR)\JDFPrintCondition.sbr"
	-@erase "$(INTDIR)\JDFPrintConditionColor.obj"
	-@erase "$(INTDIR)\JDFPrintConditionColor.sbr"
	-@erase "$(INTDIR)\JDFPrintRollingParams.obj"
	-@erase "$(INTDIR)\JDFPrintRollingParams.sbr"
	-@erase "$(INTDIR)\JDFPRItem.obj"
	-@erase "$(INTDIR)\JDFPRItem.sbr"
	-@erase "$(INTDIR)\JDFPROccurence.obj"
	-@erase "$(INTDIR)\JDFPROccurence.sbr"
	-@erase "$(INTDIR)\JDFProcessRun.obj"
	-@erase "$(INTDIR)\JDFProcessRun.sbr"
	-@erase "$(INTDIR)\JDFProductionIntent.obj"
	-@erase "$(INTDIR)\JDFProductionIntent.sbr"
	-@erase "$(INTDIR)\JDFProofingIntent.obj"
	-@erase "$(INTDIR)\JDFProofingIntent.sbr"
	-@erase "$(INTDIR)\JDFProofingParams.obj"
	-@erase "$(INTDIR)\JDFProofingParams.sbr"
	-@erase "$(INTDIR)\JDFProofItem.obj"
	-@erase "$(INTDIR)\JDFProofItem.sbr"
	-@erase "$(INTDIR)\JDFProperties.obj"
	-@erase "$(INTDIR)\JDFProperties.sbr"
	-@erase "$(INTDIR)\JDFPRRule.obj"
	-@erase "$(INTDIR)\JDFPRRule.sbr"
	-@erase "$(INTDIR)\JDFPRRuleAttr.obj"
	-@erase "$(INTDIR)\JDFPRRuleAttr.sbr"
	-@erase "$(INTDIR)\JDFPSToPDFConversionParams.obj"
	-@erase "$(INTDIR)\JDFPSToPDFConversionParams.sbr"
	-@erase "$(INTDIR)\JDFQualityControlParams.obj"
	-@erase "$(INTDIR)\JDFQualityControlParams.sbr"
	-@erase "$(INTDIR)\JDFQualityControlResult.obj"
	-@erase "$(INTDIR)\JDFQualityControlResult.sbr"
	-@erase "$(INTDIR)\JDFQualityMeasurement.obj"
	-@erase "$(INTDIR)\JDFQualityMeasurement.sbr"
	-@erase "$(INTDIR)\JDFQuery.obj"
	-@erase "$(INTDIR)\JDFQuery.sbr"
	-@erase "$(INTDIR)\JDFQueue.obj"
	-@erase "$(INTDIR)\JDFQueue.sbr"
	-@erase "$(INTDIR)\JDFQueueEntry.obj"
	-@erase "$(INTDIR)\JDFQueueEntry.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryDef.obj"
	-@erase "$(INTDIR)\JDFQueueEntryDef.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryDefList.obj"
	-@erase "$(INTDIR)\JDFQueueEntryDefList.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryPosParams.obj"
	-@erase "$(INTDIR)\JDFQueueEntryPosParams.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryPriParams.obj"
	-@erase "$(INTDIR)\JDFQueueEntryPriParams.sbr"
	-@erase "$(INTDIR)\JDFQueueFilter.obj"
	-@erase "$(INTDIR)\JDFQueueFilter.sbr"
	-@erase "$(INTDIR)\JDFQueueSubmissionParams.obj"
	-@erase "$(INTDIR)\JDFQueueSubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFRange.obj"
	-@erase "$(INTDIR)\JDFRange.sbr"
	-@erase "$(INTDIR)\JDFRangeList.obj"
	-@erase "$(INTDIR)\JDFRangeList.sbr"
	-@erase "$(INTDIR)\JDFRectangleEvaluation.obj"
	-@erase "$(INTDIR)\JDFRectangleEvaluation.sbr"
	-@erase "$(INTDIR)\JDFRectangleState.obj"
	-@erase "$(INTDIR)\JDFRectangleState.sbr"
	-@erase "$(INTDIR)\JDFRefElement.obj"
	-@erase "$(INTDIR)\JDFRefElement.sbr"
	-@erase "$(INTDIR)\JDFRegisterMark.obj"
	-@erase "$(INTDIR)\JDFRegisterMark.sbr"
	-@erase "$(INTDIR)\JDFRegisterRibbon.obj"
	-@erase "$(INTDIR)\JDFRegisterRibbon.sbr"
	-@erase "$(INTDIR)\JDFRemoved.obj"
	-@erase "$(INTDIR)\JDFRemoved.sbr"
	-@erase "$(INTDIR)\JDFRenderingParams.obj"
	-@erase "$(INTDIR)\JDFRenderingParams.sbr"
	-@erase "$(INTDIR)\JDFRequestQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFRequestQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFResource.obj"
	-@erase "$(INTDIR)\JDFResource.sbr"
	-@erase "$(INTDIR)\JDFResourceAudit.obj"
	-@erase "$(INTDIR)\JDFResourceAudit.sbr"
	-@erase "$(INTDIR)\JDFResourceCmdParams.obj"
	-@erase "$(INTDIR)\JDFResourceCmdParams.sbr"
	-@erase "$(INTDIR)\JDFResourceDefinitionParams.obj"
	-@erase "$(INTDIR)\JDFResourceDefinitionParams.sbr"
	-@erase "$(INTDIR)\JDFResourceInfo.obj"
	-@erase "$(INTDIR)\JDFResourceInfo.sbr"
	-@erase "$(INTDIR)\JDFResourceLink.obj"
	-@erase "$(INTDIR)\JDFResourceLink.sbr"
	-@erase "$(INTDIR)\JDFResourceLinkPool.obj"
	-@erase "$(INTDIR)\JDFResourceLinkPool.sbr"
	-@erase "$(INTDIR)\JDFResourceParam.obj"
	-@erase "$(INTDIR)\JDFResourceParam.sbr"
	-@erase "$(INTDIR)\JDFResourcePool.obj"
	-@erase "$(INTDIR)\JDFResourcePool.sbr"
	-@erase "$(INTDIR)\JDFResourcePullParams.obj"
	-@erase "$(INTDIR)\JDFResourcePullParams.sbr"
	-@erase "$(INTDIR)\JDFResourceQuParams.obj"
	-@erase "$(INTDIR)\JDFResourceQuParams.sbr"
	-@erase "$(INTDIR)\JDFResponse.obj"
	-@erase "$(INTDIR)\JDFResponse.sbr"
	-@erase "$(INTDIR)\JDFResubmissionParams.obj"
	-@erase "$(INTDIR)\JDFResubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFReturnQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFReturnQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFRingBinding.obj"
	-@erase "$(INTDIR)\JDFRingBinding.sbr"
	-@erase "$(INTDIR)\JDFRingBindingParams.obj"
	-@erase "$(INTDIR)\JDFRingBindingParams.sbr"
	-@erase "$(INTDIR)\JDFRollStand.obj"
	-@erase "$(INTDIR)\JDFRollStand.sbr"
	-@erase "$(INTDIR)\JDFRunElement.obj"
	-@erase "$(INTDIR)\JDFRunElement.sbr"
	-@erase "$(INTDIR)\JDFRunList.obj"
	-@erase "$(INTDIR)\JDFRunList.sbr"
	-@erase "$(INTDIR)\JDFSaddleStitching.obj"
	-@erase "$(INTDIR)\JDFSaddleStitching.sbr"
	-@erase "$(INTDIR)\JDFSaddleStitchingParams.obj"
	-@erase "$(INTDIR)\JDFSaddleStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFScanParams.obj"
	-@erase "$(INTDIR)\JDFScanParams.sbr"
	-@erase "$(INTDIR)\JDFScavengerArea.obj"
	-@erase "$(INTDIR)\JDFScavengerArea.sbr"
	-@erase "$(INTDIR)\JDFScore.obj"
	-@erase "$(INTDIR)\JDFScore.sbr"
	-@erase "$(INTDIR)\JDFScreeningIntent.obj"
	-@erase "$(INTDIR)\JDFScreeningIntent.sbr"
	-@erase "$(INTDIR)\JDFScreeningParams.obj"
	-@erase "$(INTDIR)\JDFScreeningParams.sbr"
	-@erase "$(INTDIR)\JDFScreenSelector.obj"
	-@erase "$(INTDIR)\JDFScreenSelector.sbr"
	-@erase "$(INTDIR)\JDFSeparationControlParams.obj"
	-@erase "$(INTDIR)\JDFSeparationControlParams.sbr"
	-@erase "$(INTDIR)\JDFSeparationList.obj"
	-@erase "$(INTDIR)\JDFSeparationList.sbr"
	-@erase "$(INTDIR)\JDFSeparationSpec.obj"
	-@erase "$(INTDIR)\JDFSeparationSpec.sbr"
	-@erase "$(INTDIR)\JDFset.obj"
	-@erase "$(INTDIR)\JDFset.sbr"
	-@erase "$(INTDIR)\JDFShapeCut.obj"
	-@erase "$(INTDIR)\JDFShapeCut.sbr"
	-@erase "$(INTDIR)\JDFShapeCuttingIntent.obj"
	-@erase "$(INTDIR)\JDFShapeCuttingIntent.sbr"
	-@erase "$(INTDIR)\JDFShapeCuttingParams.obj"
	-@erase "$(INTDIR)\JDFShapeCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFShapeElement.obj"
	-@erase "$(INTDIR)\JDFShapeElement.sbr"
	-@erase "$(INTDIR)\JDFShapeEvaluation.obj"
	-@erase "$(INTDIR)\JDFShapeEvaluation.sbr"
	-@erase "$(INTDIR)\JDFShapeState.obj"
	-@erase "$(INTDIR)\JDFShapeState.sbr"
	-@erase "$(INTDIR)\JDFSheet.obj"
	-@erase "$(INTDIR)\JDFSheet.sbr"
	-@erase "$(INTDIR)\JDFShrinkingParams.obj"
	-@erase "$(INTDIR)\JDFShrinkingParams.sbr"
	-@erase "$(INTDIR)\JDFShutDownCmdParams.obj"
	-@erase "$(INTDIR)\JDFShutDownCmdParams.sbr"
	-@erase "$(INTDIR)\JDFSideSewing.obj"
	-@erase "$(INTDIR)\JDFSideSewing.sbr"
	-@erase "$(INTDIR)\JDFSideSewingParams.obj"
	-@erase "$(INTDIR)\JDFSideSewingParams.sbr"
	-@erase "$(INTDIR)\JDFSideStitching.obj"
	-@erase "$(INTDIR)\JDFSideStitching.sbr"
	-@erase "$(INTDIR)\JDFSignal.obj"
	-@erase "$(INTDIR)\JDFSignal.sbr"
	-@erase "$(INTDIR)\JDFSignature.obj"
	-@erase "$(INTDIR)\JDFSignature.sbr"
	-@erase "$(INTDIR)\JDFSignatureCell.obj"
	-@erase "$(INTDIR)\JDFSignatureCell.sbr"
	-@erase "$(INTDIR)\JDFSizeIntent.obj"
	-@erase "$(INTDIR)\JDFSizeIntent.sbr"
	-@erase "$(INTDIR)\JDFSoftCoverBinding.obj"
	-@erase "$(INTDIR)\JDFSoftCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFSpan.obj"
	-@erase "$(INTDIR)\JDFSpan.sbr"
	-@erase "$(INTDIR)\JDFSpawned.obj"
	-@erase "$(INTDIR)\JDFSpawned.sbr"
	-@erase "$(INTDIR)\JDFSpinePreparationParams.obj"
	-@erase "$(INTDIR)\JDFSpinePreparationParams.sbr"
	-@erase "$(INTDIR)\JDFSpineTapingParams.obj"
	-@erase "$(INTDIR)\JDFSpineTapingParams.sbr"
	-@erase "$(INTDIR)\JDFStackingParams.obj"
	-@erase "$(INTDIR)\JDFStackingParams.sbr"
	-@erase "$(INTDIR)\JDFState.obj"
	-@erase "$(INTDIR)\JDFState.sbr"
	-@erase "$(INTDIR)\JDFStatusPool.obj"
	-@erase "$(INTDIR)\JDFStatusPool.sbr"
	-@erase "$(INTDIR)\JDFStatusQuParams.obj"
	-@erase "$(INTDIR)\JDFStatusQuParams.sbr"
	-@erase "$(INTDIR)\JDFStitchingParams.obj"
	-@erase "$(INTDIR)\JDFStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFStopPersChParams.obj"
	-@erase "$(INTDIR)\JDFStopPersChParams.sbr"
	-@erase "$(INTDIR)\JDFStrap.obj"
	-@erase "$(INTDIR)\JDFStrap.sbr"
	-@erase "$(INTDIR)\JDFStrappingParams.obj"
	-@erase "$(INTDIR)\JDFStrappingParams.sbr"
	-@erase "$(INTDIR)\JDFStringEvaluation.obj"
	-@erase "$(INTDIR)\JDFStringEvaluation.sbr"
	-@erase "$(INTDIR)\JDFStringListValue.obj"
	-@erase "$(INTDIR)\JDFStringListValue.sbr"
	-@erase "$(INTDIR)\JDFStrings.obj"
	-@erase "$(INTDIR)\JDFStrings.sbr"
	-@erase "$(INTDIR)\JDFStringState.obj"
	-@erase "$(INTDIR)\JDFStringState.sbr"
	-@erase "$(INTDIR)\JDFStripBinding.obj"
	-@erase "$(INTDIR)\JDFStripBinding.sbr"
	-@erase "$(INTDIR)\JDFStripBindingParams.obj"
	-@erase "$(INTDIR)\JDFStripBindingParams.sbr"
	-@erase "$(INTDIR)\JDFStripCellParams.obj"
	-@erase "$(INTDIR)\JDFStripCellParams.sbr"
	-@erase "$(INTDIR)\JDFStrippingParams.obj"
	-@erase "$(INTDIR)\JDFStrippingParams.sbr"
	-@erase "$(INTDIR)\JDFSubmissionMethods.obj"
	-@erase "$(INTDIR)\JDFSubmissionMethods.sbr"
	-@erase "$(INTDIR)\JDFSubscription.obj"
	-@erase "$(INTDIR)\JDFSubscription.sbr"
	-@erase "$(INTDIR)\JDFSurface.obj"
	-@erase "$(INTDIR)\JDFSurface.sbr"
	-@erase "$(INTDIR)\JDFSystemTimeSet.obj"
	-@erase "$(INTDIR)\JDFSystemTimeSet.sbr"
	-@erase "$(INTDIR)\JDFTabs.obj"
	-@erase "$(INTDIR)\JDFTabs.sbr"
	-@erase "$(INTDIR)\JDFTape.obj"
	-@erase "$(INTDIR)\JDFTape.sbr"
	-@erase "$(INTDIR)\JDFTest.obj"
	-@erase "$(INTDIR)\JDFTest.sbr"
	-@erase "$(INTDIR)\JDFTestPool.obj"
	-@erase "$(INTDIR)\JDFTestPool.sbr"
	-@erase "$(INTDIR)\JDFTestRef.obj"
	-@erase "$(INTDIR)\JDFTestRef.sbr"
	-@erase "$(INTDIR)\JDFThinPDFParams.obj"
	-@erase "$(INTDIR)\JDFThinPDFParams.sbr"
	-@erase "$(INTDIR)\JDFThreadSealing.obj"
	-@erase "$(INTDIR)\JDFThreadSealing.sbr"
	-@erase "$(INTDIR)\JDFThreadSealingParams.obj"
	-@erase "$(INTDIR)\JDFThreadSealingParams.sbr"
	-@erase "$(INTDIR)\JDFThreadSewing.obj"
	-@erase "$(INTDIR)\JDFThreadSewing.sbr"
	-@erase "$(INTDIR)\JDFThreadSewingParams.obj"
	-@erase "$(INTDIR)\JDFThreadSewingParams.sbr"
	-@erase "$(INTDIR)\JDFTIFFEmbeddedFile.obj"
	-@erase "$(INTDIR)\JDFTIFFEmbeddedFile.sbr"
	-@erase "$(INTDIR)\JDFTIFFFormatParams.obj"
	-@erase "$(INTDIR)\JDFTIFFFormatParams.sbr"
	-@erase "$(INTDIR)\JDFTIFFtag.obj"
	-@erase "$(INTDIR)\JDFTIFFtag.sbr"
	-@erase "$(INTDIR)\JDFTile.obj"
	-@erase "$(INTDIR)\JDFTile.sbr"
	-@erase "$(INTDIR)\JDFTool.obj"
	-@erase "$(INTDIR)\JDFTool.sbr"
	-@erase "$(INTDIR)\JDFTrackFilter.obj"
	-@erase "$(INTDIR)\JDFTrackFilter.sbr"
	-@erase "$(INTDIR)\JDFTrackResult.obj"
	-@erase "$(INTDIR)\JDFTrackResult.sbr"
	-@erase "$(INTDIR)\JDFTransferCurve.obj"
	-@erase "$(INTDIR)\JDFTransferCurve.sbr"
	-@erase "$(INTDIR)\JDFTransferCurvePool.obj"
	-@erase "$(INTDIR)\JDFTransferCurvePool.sbr"
	-@erase "$(INTDIR)\JDFTransferCurveSet.obj"
	-@erase "$(INTDIR)\JDFTransferCurveSet.sbr"
	-@erase "$(INTDIR)\JDFTransferFunctionControl.obj"
	-@erase "$(INTDIR)\JDFTransferFunctionControl.sbr"
	-@erase "$(INTDIR)\JDFTrappingDetails.obj"
	-@erase "$(INTDIR)\JDFTrappingDetails.sbr"
	-@erase "$(INTDIR)\JDFTrappingOrder.obj"
	-@erase "$(INTDIR)\JDFTrappingOrder.sbr"
	-@erase "$(INTDIR)\JDFTrappingParams.obj"
	-@erase "$(INTDIR)\JDFTrappingParams.sbr"
	-@erase "$(INTDIR)\JDFTrapRegion.obj"
	-@erase "$(INTDIR)\JDFTrapRegion.sbr"
	-@erase "$(INTDIR)\JDFTrigger.obj"
	-@erase "$(INTDIR)\JDFTrigger.sbr"
	-@erase "$(INTDIR)\JDFTrimmingParams.obj"
	-@erase "$(INTDIR)\JDFTrimmingParams.sbr"
	-@erase "$(INTDIR)\JDFValue.obj"
	-@erase "$(INTDIR)\JDFValue.sbr"
	-@erase "$(INTDIR)\JDFValueLoc.obj"
	-@erase "$(INTDIR)\JDFValueLoc.sbr"
	-@erase "$(INTDIR)\JDFVerificationParams.obj"
	-@erase "$(INTDIR)\JDFVerificationParams.sbr"
	-@erase "$(INTDIR)\JDFWakeUpCmdParams.obj"
	-@erase "$(INTDIR)\JDFWakeUpCmdParams.sbr"
	-@erase "$(INTDIR)\JDFwhen.obj"
	-@erase "$(INTDIR)\JDFwhen.sbr"
	-@erase "$(INTDIR)\JDFWireCombBinding.obj"
	-@erase "$(INTDIR)\JDFWireCombBinding.sbr"
	-@erase "$(INTDIR)\JDFWireCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFWireCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFWrappingParams.obj"
	-@erase "$(INTDIR)\JDFWrappingParams.sbr"
	-@erase "$(INTDIR)\JDFxor.obj"
	-@erase "$(INTDIR)\JDFxor.sbr"
	-@erase "$(INTDIR)\JDFXYPairEvaluation.obj"
	-@erase "$(INTDIR)\JDFXYPairEvaluation.sbr"
	-@erase "$(INTDIR)\JDFXYPairRangeList.obj"
	-@erase "$(INTDIR)\JDFXYPairRangeList.sbr"
	-@erase "$(INTDIR)\JDFXYPairState.obj"
	-@erase "$(INTDIR)\JDFXYPairState.sbr"
	-@erase "$(INTDIR)\KElement.obj"
	-@erase "$(INTDIR)\KElement.sbr"
	-@erase "$(INTDIR)\KElementStrings.obj"
	-@erase "$(INTDIR)\KElementStrings.sbr"
	-@erase "$(INTDIR)\MyDate.obj"
	-@erase "$(INTDIR)\MyDate.sbr"
	-@erase "$(INTDIR)\vElement.obj"
	-@erase "$(INTDIR)\vElement.sbr"
	-@erase "$(INTDIR)\XMLDoc.obj"
	-@erase "$(INTDIR)\XMLDoc.sbr"
	-@erase "$(INTDIR)\XMLDocUserData.obj"
	-@erase "$(INTDIR)\XMLDocUserData.sbr"
	-@erase "$(OUTDIR)\JDFWrapperDLL.dll"
	-@erase "$(OUTDIR)\JDFWrapperDLL.exp"
	-@erase "$(OUTDIR)\JDFWrapperDLL.lib"
	-@erase "$(OUTDIR)\JDFWrapperLib.bsc"
	-@erase "$(OUTDIR)\obj\JDFWrapperDLL\JDFWrapperDLL.map"
	-@erase "..\..\..\Build\Win32\VC6\ReleaseDLL\JDFWrapperDLL.idb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=xicl6.exe
CPP_PROJ=/nologo /MD /w /W0 /GX /O2 /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /D "JDF_WRAPPERCORE" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\JDFWrapperLib.pch" /YX /Fo"$(INTDIR)\\" /Fd"..\..\..\Build\Win32\VC6\ReleaseDLL\JDFWrapperDLL" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\JDFWrapperLib.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\JDFAmountPool.sbr" \
	"$(INTDIR)\JDFAncestor.sbr" \
	"$(INTDIR)\JDFAncestorPool.sbr" \
	"$(INTDIR)\JDFAudit.sbr" \
	"$(INTDIR)\JDFAuditPool.sbr" \
	"$(INTDIR)\JDFBarcode.sbr" \
	"$(INTDIR)\JDFBusinessInfo.sbr" \
	"$(INTDIR)\JDFComment.sbr" \
	"$(INTDIR)\JDFCounterReset.sbr" \
	"$(INTDIR)\JDFCreated.sbr" \
	"$(INTDIR)\JDFCustomerInfo.sbr" \
	"$(INTDIR)\JDFCustomerMessage.sbr" \
	"$(INTDIR)\JDFDeleted.sbr" \
	"$(INTDIR)\JDFError.sbr" \
	"$(INTDIR)\JDFEvent.sbr" \
	"$(INTDIR)\JDFFCNKey.sbr" \
	"$(INTDIR)\JDFLocation.sbr" \
	"$(INTDIR)\JDFMerged.sbr" \
	"$(INTDIR)\JDFModified.sbr" \
	"$(INTDIR)\JDFModulePhase.sbr" \
	"$(INTDIR)\JDFNode.sbr" \
	"$(INTDIR)\JDFNodeInfo.sbr" \
	"$(INTDIR)\JDFNotification.sbr" \
	"$(INTDIR)\JDFPart.sbr" \
	"$(INTDIR)\JDFPartAmount.sbr" \
	"$(INTDIR)\JDFPartStatus.sbr" \
	"$(INTDIR)\JDFPhaseTime.sbr" \
	"$(INTDIR)\JDFProcessRun.sbr" \
	"$(INTDIR)\JDFResourceAudit.sbr" \
	"$(INTDIR)\JDFResourceLinkPool.sbr" \
	"$(INTDIR)\JDFResourcePool.sbr" \
	"$(INTDIR)\JDFSpawned.sbr" \
	"$(INTDIR)\JDFStatusPool.sbr" \
	"$(INTDIR)\JDFSystemTimeSet.sbr" \
	"$(INTDIR)\JDFAcknowledge.sbr" \
	"$(INTDIR)\JDFAdded.sbr" \
	"$(INTDIR)\JDFChangedAttribute.sbr" \
	"$(INTDIR)\JDFChangedPath.sbr" \
	"$(INTDIR)\JDFCommand.sbr" \
	"$(INTDIR)\JDFDeviceFilter.sbr" \
	"$(INTDIR)\JDFDeviceInfo.sbr" \
	"$(INTDIR)\JDFDeviceList.sbr" \
	"$(INTDIR)\JDFEmployeeDef.sbr" \
	"$(INTDIR)\JDFFlushedResources.sbr" \
	"$(INTDIR)\JDFFlushQueueParams.sbr" \
	"$(INTDIR)\JDFFlushResourceParams.sbr" \
	"$(INTDIR)\JDFIDInfo.sbr" \
	"$(INTDIR)\JDFJDFController.sbr" \
	"$(INTDIR)\JDFJDFService.sbr" \
	"$(INTDIR)\JDFJMF.sbr" \
	"$(INTDIR)\JDFJobPhase.sbr" \
	"$(INTDIR)\JDFKnownMsgQuParams.sbr" \
	"$(INTDIR)\JDFMessage.sbr" \
	"$(INTDIR)\JDFMessageElement.sbr" \
	"$(INTDIR)\JDFMessageService.sbr" \
	"$(INTDIR)\JDFModuleStatus.sbr" \
	"$(INTDIR)\JDFMsgFilter.sbr" \
	"$(INTDIR)\JDFNewJDFCmdParams.sbr" \
	"$(INTDIR)\JDFNewJDFQuParams.sbr" \
	"$(INTDIR)\JDFNodeInfoCmdParams.sbr" \
	"$(INTDIR)\JDFNodeInfoQuParams.sbr" \
	"$(INTDIR)\JDFNodeInfoResp.sbr" \
	"$(INTDIR)\JDFNotificationDef.sbr" \
	"$(INTDIR)\JDFNotificationFilter.sbr" \
	"$(INTDIR)\JDFObservationTarget.sbr" \
	"$(INTDIR)\JDFOccupation.sbr" \
	"$(INTDIR)\JDFPipeParams.sbr" \
	"$(INTDIR)\JDFQuery.sbr" \
	"$(INTDIR)\JDFQueue.sbr" \
	"$(INTDIR)\JDFQueueEntry.sbr" \
	"$(INTDIR)\JDFQueueEntryDef.sbr" \
	"$(INTDIR)\JDFQueueEntryDefList.sbr" \
	"$(INTDIR)\JDFQueueEntryPosParams.sbr" \
	"$(INTDIR)\JDFQueueEntryPriParams.sbr" \
	"$(INTDIR)\JDFQueueFilter.sbr" \
	"$(INTDIR)\JDFQueueSubmissionParams.sbr" \
	"$(INTDIR)\JDFRemoved.sbr" \
	"$(INTDIR)\JDFRequestQueueEntryParams.sbr" \
	"$(INTDIR)\JDFResourceCmdParams.sbr" \
	"$(INTDIR)\JDFResourceInfo.sbr" \
	"$(INTDIR)\JDFResourcePullParams.sbr" \
	"$(INTDIR)\JDFResourceQuParams.sbr" \
	"$(INTDIR)\JDFResponse.sbr" \
	"$(INTDIR)\JDFResubmissionParams.sbr" \
	"$(INTDIR)\JDFReturnQueueEntryParams.sbr" \
	"$(INTDIR)\JDFShutDownCmdParams.sbr" \
	"$(INTDIR)\JDFSignal.sbr" \
	"$(INTDIR)\JDFStatusQuParams.sbr" \
	"$(INTDIR)\JDFStopPersChParams.sbr" \
	"$(INTDIR)\JDFSubmissionMethods.sbr" \
	"$(INTDIR)\JDFSubscription.sbr" \
	"$(INTDIR)\JDFTrackFilter.sbr" \
	"$(INTDIR)\JDFTrackResult.sbr" \
	"$(INTDIR)\JDFTrigger.sbr" \
	"$(INTDIR)\JDFWakeUpCmdParams.sbr" \
	"$(INTDIR)\JDFArtDeliveryIntent.sbr" \
	"$(INTDIR)\JDFBindingIntent.sbr" \
	"$(INTDIR)\JDFColorIntent.sbr" \
	"$(INTDIR)\JDFDeliveryIntent.sbr" \
	"$(INTDIR)\JDFEmbossingIntent.sbr" \
	"$(INTDIR)\JDFFoldingIntent.sbr" \
	"$(INTDIR)\JDFHoleMakingIntent.sbr" \
	"$(INTDIR)\JDFInsertingIntent.sbr" \
	"$(INTDIR)\JDFIntentResource.sbr" \
	"$(INTDIR)\JDFLaminatingIntent.sbr" \
	"$(INTDIR)\JDFLayoutIntent.sbr" \
	"$(INTDIR)\JDFMediaIntent.sbr" \
	"$(INTDIR)\JDFNumberingIntent.sbr" \
	"$(INTDIR)\JDFPackingIntent.sbr" \
	"$(INTDIR)\JDFProductionIntent.sbr" \
	"$(INTDIR)\JDFProofingIntent.sbr" \
	"$(INTDIR)\JDFScreeningIntent.sbr" \
	"$(INTDIR)\JDFShapeCuttingIntent.sbr" \
	"$(INTDIR)\JDFSizeIntent.sbr" \
	"$(INTDIR)\JDFSpan.sbr" \
	"$(INTDIR)\JDFAdhesiveBinding.sbr" \
	"$(INTDIR)\JDFArtDelivery.sbr" \
	"$(INTDIR)\JDFBindItem.sbr" \
	"$(INTDIR)\JDFBindList.sbr" \
	"$(INTDIR)\JDFBookCase.sbr" \
	"$(INTDIR)\JDFChannelBinding.sbr" \
	"$(INTDIR)\JDFCoilBinding.sbr" \
	"$(INTDIR)\JDFColorsUsed.sbr" \
	"$(INTDIR)\JDFCreditCard.sbr" \
	"$(INTDIR)\JDFDropIntent.sbr" \
	"$(INTDIR)\JDFDropItemIntent.sbr" \
	"$(INTDIR)\JDFEdgeGluing.sbr" \
	"$(INTDIR)\JDFEmbossingItem.sbr" \
	"$(INTDIR)\JDFHardCoverBinding.sbr" \
	"$(INTDIR)\JDFHoleList.sbr" \
	"$(INTDIR)\JDFInsert.sbr" \
	"$(INTDIR)\JDFInsertList.sbr" \
	"$(INTDIR)\JDFNumberItem.sbr" \
	"$(INTDIR)\JDFPayment.sbr" \
	"$(INTDIR)\JDFPlasticCombBinding.sbr" \
	"$(INTDIR)\JDFPricing.sbr" \
	"$(INTDIR)\JDFProofItem.sbr" \
	"$(INTDIR)\JDFRingBinding.sbr" \
	"$(INTDIR)\JDFSaddleStitching.sbr" \
	"$(INTDIR)\JDFShapeCut.sbr" \
	"$(INTDIR)\JDFSideSewing.sbr" \
	"$(INTDIR)\JDFSideStitching.sbr" \
	"$(INTDIR)\JDFSoftCoverBinding.sbr" \
	"$(INTDIR)\JDFStripBinding.sbr" \
	"$(INTDIR)\JDFTabs.sbr" \
	"$(INTDIR)\JDFTape.sbr" \
	"$(INTDIR)\JDFThreadSealing.sbr" \
	"$(INTDIR)\JDFThreadSewing.sbr" \
	"$(INTDIR)\JDFWireCombBinding.sbr" \
	"$(INTDIR)\JDFAddress.sbr" \
	"$(INTDIR)\JDFAdhesiveBindingParams.sbr" \
	"$(INTDIR)\JDFApprovalParams.sbr" \
	"$(INTDIR)\JDFApprovalSuccess.sbr" \
	"$(INTDIR)\JDFAssembly.sbr" \
	"$(INTDIR)\JDFAssetListCreationParams.sbr" \
	"$(INTDIR)\JDFAutomatedOverprintParams.sbr" \
	"$(INTDIR)\JDFBinderySignature.sbr" \
	"$(INTDIR)\JDFBlockPreparationParams.sbr" \
	"$(INTDIR)\JDFBoxPackingParams.sbr" \
	"$(INTDIR)\JDFBufferParams.sbr" \
	"$(INTDIR)\JDFBundle.sbr" \
	"$(INTDIR)\JDFBundlingParams.sbr" \
	"$(INTDIR)\JDFByteMap.sbr" \
	"$(INTDIR)\JDFCaseMakingParams.sbr" \
	"$(INTDIR)\JDFCasingInParams.sbr" \
	"$(INTDIR)\JDFChannelBindingParams.sbr" \
	"$(INTDIR)\JDFCIELABMeasuringField.sbr" \
	"$(INTDIR)\JDFCoilBindingParams.sbr" \
	"$(INTDIR)\JDFCollectingParams.sbr" \
	"$(INTDIR)\JDFColor.sbr" \
	"$(INTDIR)\JDFColorantAlias.sbr" \
	"$(INTDIR)\JDFColorantControl.sbr" \
	"$(INTDIR)\JDFColorControlStrip.sbr" \
	"$(INTDIR)\JDFColorCorrectionParams.sbr" \
	"$(INTDIR)\JDFColorMeasurementConditions.sbr" \
	"$(INTDIR)\JDFColorPool.sbr" \
	"$(INTDIR)\JDFColorSpaceConversionOp.sbr" \
	"$(INTDIR)\JDFColorSpaceConversionParams.sbr" \
	"$(INTDIR)\JDFComChannel.sbr" \
	"$(INTDIR)\JDFCompany.sbr" \
	"$(INTDIR)\JDFComponent.sbr" \
	"$(INTDIR)\JDFContact.sbr" \
	"$(INTDIR)\JDFContactCopyParams.sbr" \
	"$(INTDIR)\JDFConventionalPrintingParams.sbr" \
	"$(INTDIR)\JDFCostCenter.sbr" \
	"$(INTDIR)\JDFCoverApplicationParams.sbr" \
	"$(INTDIR)\JDFCreasingParams.sbr" \
	"$(INTDIR)\JDFCutBlock.sbr" \
	"$(INTDIR)\JDFCutMark.sbr" \
	"$(INTDIR)\JDFCuttingParams.sbr" \
	"$(INTDIR)\JDFDBMergeParams.sbr" \
	"$(INTDIR)\JDFDBRules.sbr" \
	"$(INTDIR)\JDFDBSchema.sbr" \
	"$(INTDIR)\JDFDBSelection.sbr" \
	"$(INTDIR)\JDFDeliveryParams.sbr" \
	"$(INTDIR)\JDFDensityMeasuringField.sbr" \
	"$(INTDIR)\JDFDevelopingParams.sbr" \
	"$(INTDIR)\JDFDevice.sbr" \
	"$(INTDIR)\JDFDeviceMark.sbr" \
	"$(INTDIR)\JDFDeviceNSpace.sbr" \
	"$(INTDIR)\JDFDigitalDeliveryParams.sbr" \
	"$(INTDIR)\JDFDigitalMedia.sbr" \
	"$(INTDIR)\JDFDigitalPrintingParams.sbr" \
	"$(INTDIR)\JDFDisjointing.sbr" \
	"$(INTDIR)\JDFDisposition.sbr" \
	"$(INTDIR)\JDFDividingParams.sbr" \
	"$(INTDIR)\JDFElementColorParams.sbr" \
	"$(INTDIR)\JDFEmbossingParams.sbr" \
	"$(INTDIR)\JDFEmployee.sbr" \
	"$(INTDIR)\JDFEndSheetGluingParams.sbr" \
	"$(INTDIR)\JDFExposedMedia.sbr" \
	"$(INTDIR)\JDFFeedingParams.sbr" \
	"$(INTDIR)\JDFFileSpec.sbr" \
	"$(INTDIR)\JDFFitPolicy.sbr" \
	"$(INTDIR)\JDFFold.sbr" \
	"$(INTDIR)\JDFFoldingParams.sbr" \
	"$(INTDIR)\JDFFontParams.sbr" \
	"$(INTDIR)\JDFFontPolicy.sbr" \
	"$(INTDIR)\JDFFormatConversionParams.sbr" \
	"$(INTDIR)\JDFGatheringParams.sbr" \
	"$(INTDIR)\JDFGlueApplication.sbr" \
	"$(INTDIR)\JDFGlueLine.sbr" \
	"$(INTDIR)\JDFGluingParams.sbr" \
	"$(INTDIR)\JDFHeadBandApplicationParams.sbr" \
	"$(INTDIR)\JDFHole.sbr" \
	"$(INTDIR)\JDFHoleLine.sbr" \
	"$(INTDIR)\JDFHoleMakingParams.sbr" \
	"$(INTDIR)\JDFIdentificationField.sbr" \
	"$(INTDIR)\JDFIDPrintingParams.sbr" \
	"$(INTDIR)\JDFImageCompressionParams.sbr" \
	"$(INTDIR)\JDFImageReplacementParams.sbr" \
	"$(INTDIR)\JDFImageSetterParams.sbr" \
	"$(INTDIR)\JDFInk.sbr" \
	"$(INTDIR)\JDFInkZoneCalculationParams.sbr" \
	"$(INTDIR)\JDFInkZoneProfile.sbr" \
	"$(INTDIR)\JDFInsertingParams.sbr" \
	"$(INTDIR)\JDFInsertSheet.sbr" \
	"$(INTDIR)\JDFInterpretedPDLData.sbr" \
	"$(INTDIR)\JDFInterpretingParams.sbr" \
	"$(INTDIR)\JDFJacketingParams.sbr" \
	"$(INTDIR)\JDFJobField.sbr" \
	"$(INTDIR)\JDFLabelingParams.sbr" \
	"$(INTDIR)\JDFLaminatingParams.sbr" \
	"$(INTDIR)\JDFLayout.sbr" \
	"$(INTDIR)\JDFLayoutElement.sbr" \
	"$(INTDIR)\JDFLayoutPreparationParams.sbr" \
	"$(INTDIR)\JDFLongitudinalRibbonOperationParams.sbr" \
	"$(INTDIR)\JDFManualLaborParams.sbr" \
	"$(INTDIR)\JDFMedia.sbr" \
	"$(INTDIR)\JDFMediaSource.sbr" \
	"$(INTDIR)\JDFMISDetails.sbr" \
	"$(INTDIR)\JDFNumberingParams.sbr" \
	"$(INTDIR)\JDFObjectResolution.sbr" \
	"$(INTDIR)\JDFOrderingParams.sbr" \
	"$(INTDIR)\JDFPackingParams.sbr" \
	"$(INTDIR)\JDFPageList.sbr" \
	"$(INTDIR)\JDFPallet.sbr" \
	"$(INTDIR)\JDFPalletizingParams.sbr" \
	"$(INTDIR)\JDFPDFToPSConversionParams.sbr" \
	"$(INTDIR)\JDFPDLResourceAlias.sbr" \
	"$(INTDIR)\JDFPerforatingParams.sbr" \
	"$(INTDIR)\JDFPerson.sbr" \
	"$(INTDIR)\JDFPlaceHolderResource.sbr" \
	"$(INTDIR)\JDFPlasticCombBindingParams.sbr" \
	"$(INTDIR)\JDFPlateCopyParams.sbr" \
	"$(INTDIR)\JDFPreflightAnalysis.sbr" \
	"$(INTDIR)\JDFPreflightInventory.sbr" \
	"$(INTDIR)\JDFPreflightParams.sbr" \
	"$(INTDIR)\JDFPreflightProfile.sbr" \
	"$(INTDIR)\JDFPreflightReport.sbr" \
	"$(INTDIR)\JDFPreflightReportRulePool.sbr" \
	"$(INTDIR)\JDFPreview.sbr" \
	"$(INTDIR)\JDFPreviewGenerationParams.sbr" \
	"$(INTDIR)\JDFPrintCondition.sbr" \
	"$(INTDIR)\JDFPrintRollingParams.sbr" \
	"$(INTDIR)\JDFProofingParams.sbr" \
	"$(INTDIR)\JDFPSToPDFConversionParams.sbr" \
	"$(INTDIR)\JDFQualityControlParams.sbr" \
	"$(INTDIR)\JDFQualityControlResult.sbr" \
	"$(INTDIR)\JDFRegisterMark.sbr" \
	"$(INTDIR)\JDFRegisterRibbon.sbr" \
	"$(INTDIR)\JDFRenderingParams.sbr" \
	"$(INTDIR)\JDFResourceDefinitionParams.sbr" \
	"$(INTDIR)\JDFRingBindingParams.sbr" \
	"$(INTDIR)\JDFRollStand.sbr" \
	"$(INTDIR)\JDFRunList.sbr" \
	"$(INTDIR)\JDFSaddleStitchingParams.sbr" \
	"$(INTDIR)\JDFScanParams.sbr" \
	"$(INTDIR)\JDFScavengerArea.sbr" \
	"$(INTDIR)\JDFScreeningParams.sbr" \
	"$(INTDIR)\JDFSeparationControlParams.sbr" \
	"$(INTDIR)\JDFSeparationSpec.sbr" \
	"$(INTDIR)\JDFShapeCuttingParams.sbr" \
	"$(INTDIR)\JDFSheet.sbr" \
	"$(INTDIR)\JDFShrinkingParams.sbr" \
	"$(INTDIR)\JDFSideSewingParams.sbr" \
	"$(INTDIR)\JDFSpinePreparationParams.sbr" \
	"$(INTDIR)\JDFSpineTapingParams.sbr" \
	"$(INTDIR)\JDFStackingParams.sbr" \
	"$(INTDIR)\JDFStitchingParams.sbr" \
	"$(INTDIR)\JDFStrap.sbr" \
	"$(INTDIR)\JDFStrappingParams.sbr" \
	"$(INTDIR)\JDFStripBindingParams.sbr" \
	"$(INTDIR)\JDFStrippingParams.sbr" \
	"$(INTDIR)\JDFSurface.sbr" \
	"$(INTDIR)\JDFThreadSealingParams.sbr" \
	"$(INTDIR)\JDFThreadSewingParams.sbr" \
	"$(INTDIR)\JDFTile.sbr" \
	"$(INTDIR)\JDFTool.sbr" \
	"$(INTDIR)\JDFTransferCurve.sbr" \
	"$(INTDIR)\JDFTransferCurvePool.sbr" \
	"$(INTDIR)\JDFTransferFunctionControl.sbr" \
	"$(INTDIR)\JDFTrappingDetails.sbr" \
	"$(INTDIR)\JDFTrappingParams.sbr" \
	"$(INTDIR)\JDFTrapRegion.sbr" \
	"$(INTDIR)\JDFTrimmingParams.sbr" \
	"$(INTDIR)\JDFVerificationParams.sbr" \
	"$(INTDIR)\JDFWireCombBindingParams.sbr" \
	"$(INTDIR)\JDFWrappingParams.sbr" \
	"$(INTDIR)\JDFAdvancedParams.sbr" \
	"$(INTDIR)\JDFApprovalPerson.sbr" \
	"$(INTDIR)\JDFAssemblySection.sbr" \
	"$(INTDIR)\JDFBand.sbr" \
	"$(INTDIR)\JDFBasicPreflightTest.sbr" \
	"$(INTDIR)\JDFBindingQualityParams.sbr" \
	"$(INTDIR)\JDFBoxArgument.sbr" \
	"$(INTDIR)\JDFBoxToBoxDifference.sbr" \
	"$(INTDIR)\JDFBundleItem.sbr" \
	"$(INTDIR)\JDFCCITTFaxParams.sbr" \
	"$(INTDIR)\JDFCollatingItem.sbr" \
	"$(INTDIR)\JDFColorantZoneDetails.sbr" \
	"$(INTDIR)\JDFColorCorrectionOp.sbr" \
	"$(INTDIR)\JDFColorSpaceSubstitute.sbr" \
	"$(INTDIR)\JDFContainer.sbr" \
	"$(INTDIR)\JDFContentObject.sbr" \
	"$(INTDIR)\JDFCrease.sbr" \
	"$(INTDIR)\JDFCut.sbr" \
	"$(INTDIR)\JDFDCTParams.sbr" \
	"$(INTDIR)\JDFDependencies.sbr" \
	"$(INTDIR)\JDFDeviceNColor.sbr" \
	"$(INTDIR)\JDFDrop.sbr" \
	"$(INTDIR)\JDFDropItem.sbr" \
	"$(INTDIR)\JDFDynamicField.sbr" \
	"$(INTDIR)\JDFDynamicInput.sbr" \
	"$(INTDIR)\JDFEmboss.sbr" \
	"$(INTDIR)\JDFEndSheet.sbr" \
	"$(INTDIR)\JDFFeeder.sbr" \
	"$(INTDIR)\JDFFeederQualityParams.sbr" \
	"$(INTDIR)\JDFFileAlias.sbr" \
	"$(INTDIR)\JDFFlateParams.sbr" \
	"$(INTDIR)\JDFGlue.sbr" \
	"$(INTDIR)\JDFIcon.sbr" \
	"$(INTDIR)\JDFIconList.sbr" \
	"$(INTDIR)\JDFIDPCover.sbr" \
	"$(INTDIR)\JDFIDPFinishing.sbr" \
	"$(INTDIR)\JDFIDPFolding.sbr" \
	"$(INTDIR)\JDFIDPHoleMaking.sbr" \
	"$(INTDIR)\JDFIDPImageShift.sbr" \
	"$(INTDIR)\JDFIDPJobSheet.sbr" \
	"$(INTDIR)\JDFIDPLayout.sbr" \
	"$(INTDIR)\JDFIDPStitching.sbr" \
	"$(INTDIR)\JDFIDPTrimming.sbr" \
	"$(INTDIR)\JDFImageCompression.sbr" \
	"$(INTDIR)\JDFImageShift.sbr" \
	"$(INTDIR)\JDFLayerDetails.sbr" \
	"$(INTDIR)\JDFLayerList.sbr" \
	"$(INTDIR)\JDFLongFold.sbr" \
	"$(INTDIR)\JDFLongGlue.sbr" \
	"$(INTDIR)\JDFLongPerforate.sbr" \
	"$(INTDIR)\JDFLongSlit.sbr" \
	"$(INTDIR)\JDFLZWParams.sbr" \
	"$(INTDIR)\JDFMarkObject.sbr" \
	"$(INTDIR)\JDFNumberingParam.sbr" \
	"$(INTDIR)\JDFPageCell.sbr" \
	"$(INTDIR)\JDFPageData.sbr" \
	"$(INTDIR)\JDFPDFInterpretingParams.sbr" \
	"$(INTDIR)\JDFPDFXParams.sbr" \
	"$(INTDIR)\JDFPerforate.sbr" \
	"$(INTDIR)\JDFPixelColorant.sbr" \
	"$(INTDIR)\JDFPosition.sbr" \
	"$(INTDIR)\JDFPreflightAction.sbr" \
	"$(INTDIR)\JDFPreflightArgument.sbr" \
	"$(INTDIR)\JDFPreflightConstraint.sbr" \
	"$(INTDIR)\JDFPreflightDetail.sbr" \
	"$(INTDIR)\JDFPreflightInstance.sbr" \
	"$(INTDIR)\JDFPreflightInstanceDetail.sbr" \
	"$(INTDIR)\JDFPreflightValue.sbr" \
	"$(INTDIR)\JDFPRError.sbr" \
	"$(INTDIR)\JDFPRGroup.sbr" \
	"$(INTDIR)\JDFPrintConditionColor.sbr" \
	"$(INTDIR)\JDFPRItem.sbr" \
	"$(INTDIR)\JDFPROccurence.sbr" \
	"$(INTDIR)\JDFProperties.sbr" \
	"$(INTDIR)\JDFPRRule.sbr" \
	"$(INTDIR)\JDFPRRuleAttr.sbr" \
	"$(INTDIR)\JDFQualityMeasurement.sbr" \
	"$(INTDIR)\JDFResourceParam.sbr" \
	"$(INTDIR)\JDFScore.sbr" \
	"$(INTDIR)\JDFScreenSelector.sbr" \
	"$(INTDIR)\JDFShapeElement.sbr" \
	"$(INTDIR)\JDFSignature.sbr" \
	"$(INTDIR)\JDFSignatureCell.sbr" \
	"$(INTDIR)\JDFStringListValue.sbr" \
	"$(INTDIR)\JDFStripCellParams.sbr" \
	"$(INTDIR)\JDFThinPDFParams.sbr" \
	"$(INTDIR)\JDFTIFFEmbeddedFile.sbr" \
	"$(INTDIR)\JDFTIFFFormatParams.sbr" \
	"$(INTDIR)\JDFTIFFtag.sbr" \
	"$(INTDIR)\JDFTransferCurveSet.sbr" \
	"$(INTDIR)\JDFTrappingOrder.sbr" \
	"$(INTDIR)\JDFAction.sbr" \
	"$(INTDIR)\JDFActionPool.sbr" \
	"$(INTDIR)\JDFand.sbr" \
	"$(INTDIR)\JDFBooleanEvaluation.sbr" \
	"$(INTDIR)\JDFBooleanState.sbr" \
	"$(INTDIR)\JDFcall.sbr" \
	"$(INTDIR)\JDFchoice.sbr" \
	"$(INTDIR)\JDFDateTimeEvaluation.sbr" \
	"$(INTDIR)\JDFDateTimeState.sbr" \
	"$(INTDIR)\JDFDevCap.sbr" \
	"$(INTDIR)\JDFDevCaps.sbr" \
	"$(INTDIR)\JDFDeviceCap.sbr" \
	"$(INTDIR)\JDFDisplayGroup.sbr" \
	"$(INTDIR)\JDFDisplayGroupPool.sbr" \
	"$(INTDIR)\JDFDurationEvaluation.sbr" \
	"$(INTDIR)\JDFDurationState.sbr" \
	"$(INTDIR)\JDFEnumerationEvaluation.sbr" \
	"$(INTDIR)\JDFEnumerationState.sbr" \
	"$(INTDIR)\JDFEvaluation.sbr" \
	"$(INTDIR)\JDFFeatureAttribute.sbr" \
	"$(INTDIR)\JDFFeaturePool.sbr" \
	"$(INTDIR)\JDFIntegerEvaluation.sbr" \
	"$(INTDIR)\JDFIntegerState.sbr" \
	"$(INTDIR)\JDFIsPresentEvaluation.sbr" \
	"$(INTDIR)\JDFLoc.sbr" \
	"$(INTDIR)\JDFmacro.sbr" \
	"$(INTDIR)\JDFMacroPool.sbr" \
	"$(INTDIR)\JDFMatrixEvaluation.sbr" \
	"$(INTDIR)\JDFMatrixState.sbr" \
	"$(INTDIR)\JDFNameEvaluation.sbr" \
	"$(INTDIR)\JDFNameState.sbr" \
	"$(INTDIR)\JDFnot.sbr" \
	"$(INTDIR)\JDFNumberEvaluation.sbr" \
	"$(INTDIR)\JDFNumberState.sbr" \
	"$(INTDIR)\JDFor.sbr" \
	"$(INTDIR)\JDFotherwise.sbr" \
	"$(INTDIR)\JDFPDFPathEvaluation.sbr" \
	"$(INTDIR)\JDFPDFPathState.sbr" \
	"$(INTDIR)\JDFPerformance.sbr" \
	"$(INTDIR)\JDFRectangleEvaluation.sbr" \
	"$(INTDIR)\JDFRectangleState.sbr" \
	"$(INTDIR)\JDFset.sbr" \
	"$(INTDIR)\JDFShapeEvaluation.sbr" \
	"$(INTDIR)\JDFShapeState.sbr" \
	"$(INTDIR)\JDFState.sbr" \
	"$(INTDIR)\JDFStringEvaluation.sbr" \
	"$(INTDIR)\JDFStringState.sbr" \
	"$(INTDIR)\JDFTest.sbr" \
	"$(INTDIR)\JDFTestPool.sbr" \
	"$(INTDIR)\JDFTestRef.sbr" \
	"$(INTDIR)\JDFValue.sbr" \
	"$(INTDIR)\JDFValueLoc.sbr" \
	"$(INTDIR)\JDFwhen.sbr" \
	"$(INTDIR)\JDFxor.sbr" \
	"$(INTDIR)\JDFXYPairEvaluation.sbr" \
	"$(INTDIR)\JDFXYPairState.sbr" \
	"$(INTDIR)\JDFDoc.sbr" \
	"$(INTDIR)\JDFElement.sbr" \
	"$(INTDIR)\JDFFactory.sbr" \
	"$(INTDIR)\JDFNodeFactory.sbr" \
	"$(INTDIR)\JDFParamsFactory.sbr" \
	"$(INTDIR)\JDFPool.sbr" \
	"$(INTDIR)\JDFRefElement.sbr" \
	"$(INTDIR)\JDFResource.sbr" \
	"$(INTDIR)\JDFResourceLink.sbr" \
	"$(INTDIR)\JDFRunElement.sbr" \
	"$(INTDIR)\JDFSeparationList.sbr" \
	"$(INTDIR)\JDFStrings.sbr" \
	"$(INTDIR)\JDFAutoAmountPool.sbr" \
	"$(INTDIR)\JDFAutoAncestor.sbr" \
	"$(INTDIR)\JDFAutoAncestorPool.sbr" \
	"$(INTDIR)\JDFAutoBarcode.sbr" \
	"$(INTDIR)\JDFAutoBusinessInfo.sbr" \
	"$(INTDIR)\JDFAutoComment.sbr" \
	"$(INTDIR)\JDFAutoCounterReset.sbr" \
	"$(INTDIR)\JDFAutoCreated.sbr" \
	"$(INTDIR)\JDFAutoCustomerInfo.sbr" \
	"$(INTDIR)\JDFAutoCustomerMessage.sbr" \
	"$(INTDIR)\JDFAutoDeleted.sbr" \
	"$(INTDIR)\JDFAutoError.sbr" \
	"$(INTDIR)\JDFAutoEvent.sbr" \
	"$(INTDIR)\JDFAutoFCNKey.sbr" \
	"$(INTDIR)\JDFAutoLocation.sbr" \
	"$(INTDIR)\JDFAutoMerged.sbr" \
	"$(INTDIR)\JDFAutoModified.sbr" \
	"$(INTDIR)\JDFAutoModulePhase.sbr" \
	"$(INTDIR)\JDFAutoNodeInfo.sbr" \
	"$(INTDIR)\JDFAutoNotification.sbr" \
	"$(INTDIR)\JDFAutoPart.sbr" \
	"$(INTDIR)\JDFAutoPartStatus.sbr" \
	"$(INTDIR)\JDFAutoPhaseTime.sbr" \
	"$(INTDIR)\JDFAutoProcessRun.sbr" \
	"$(INTDIR)\JDFAutoResourceAudit.sbr" \
	"$(INTDIR)\JDFAutoSpawned.sbr" \
	"$(INTDIR)\JDFAutoStatusPool.sbr" \
	"$(INTDIR)\JDFAutoSystemTimeSet.sbr" \
	"$(INTDIR)\JDFAutoAcknowledge.sbr" \
	"$(INTDIR)\JDFAutoAdded.sbr" \
	"$(INTDIR)\JDFAutoChangedAttribute.sbr" \
	"$(INTDIR)\JDFAutoChangedPath.sbr" \
	"$(INTDIR)\JDFAutoCommand.sbr" \
	"$(INTDIR)\JDFAutoDeviceFilter.sbr" \
	"$(INTDIR)\JDFAutoDeviceInfo.sbr" \
	"$(INTDIR)\JDFAutoDeviceList.sbr" \
	"$(INTDIR)\JDFAutoEmployeeDef.sbr" \
	"$(INTDIR)\JDFAutoFlushedResources.sbr" \
	"$(INTDIR)\JDFAutoFlushQueueParams.sbr" \
	"$(INTDIR)\JDFAutoFlushResourceParams.sbr" \
	"$(INTDIR)\JDFAutoIDInfo.sbr" \
	"$(INTDIR)\JDFAutoJDFController.sbr" \
	"$(INTDIR)\JDFAutoJDFService.sbr" \
	"$(INTDIR)\JDFAutoJMF.sbr" \
	"$(INTDIR)\JDFAutoJobPhase.sbr" \
	"$(INTDIR)\JDFAutoKnownMsgQuParams.sbr" \
	"$(INTDIR)\JDFAutoMessage.sbr" \
	"$(INTDIR)\JDFAutoMessageService.sbr" \
	"$(INTDIR)\JDFAutoModuleStatus.sbr" \
	"$(INTDIR)\JDFAutoMsgFilter.sbr" \
	"$(INTDIR)\JDFAutoNewJDFCmdParams.sbr" \
	"$(INTDIR)\JDFAutoNewJDFQuParams.sbr" \
	"$(INTDIR)\JDFAutoNodeInfoCmdParams.sbr" \
	"$(INTDIR)\JDFAutoNodeInfoQuParams.sbr" \
	"$(INTDIR)\JDFAutoNodeInfoResp.sbr" \
	"$(INTDIR)\JDFAutoNotificationDef.sbr" \
	"$(INTDIR)\JDFAutoNotificationFilter.sbr" \
	"$(INTDIR)\JDFAutoObservationTarget.sbr" \
	"$(INTDIR)\JDFAutoOccupation.sbr" \
	"$(INTDIR)\JDFAutoPipeParams.sbr" \
	"$(INTDIR)\JDFAutoQuery.sbr" \
	"$(INTDIR)\JDFAutoQueue.sbr" \
	"$(INTDIR)\JDFAutoQueueEntry.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryDef.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryDefList.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryPosParams.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryPriParams.sbr" \
	"$(INTDIR)\JDFAutoQueueFilter.sbr" \
	"$(INTDIR)\JDFAutoQueueSubmissionParams.sbr" \
	"$(INTDIR)\JDFAutoRemoved.sbr" \
	"$(INTDIR)\JDFAutoRequestQueueEntryParams.sbr" \
	"$(INTDIR)\JDFAutoResourceCmdParams.sbr" \
	"$(INTDIR)\JDFAutoResourceInfo.sbr" \
	"$(INTDIR)\JDFAutoResourcePullParams.sbr" \
	"$(INTDIR)\JDFAutoResourceQuParams.sbr" \
	"$(INTDIR)\JDFAutoResponse.sbr" \
	"$(INTDIR)\JDFAutoResubmissionParams.sbr" \
	"$(INTDIR)\JDFAutoReturnQueueEntryParams.sbr" \
	"$(INTDIR)\JDFAutoShutDownCmdParams.sbr" \
	"$(INTDIR)\JDFAutoSignal.sbr" \
	"$(INTDIR)\JDFAutoStatusQuParams.sbr" \
	"$(INTDIR)\JDFAutoStopPersChParams.sbr" \
	"$(INTDIR)\JDFAutoSubmissionMethods.sbr" \
	"$(INTDIR)\JDFAutoSubscription.sbr" \
	"$(INTDIR)\JDFAutoTrackFilter.sbr" \
	"$(INTDIR)\JDFAutoTrackResult.sbr" \
	"$(INTDIR)\JDFAutoTrigger.sbr" \
	"$(INTDIR)\JDFAutoWakeUpCmdParams.sbr" \
	"$(INTDIR)\JDFAutoArtDeliveryIntent.sbr" \
	"$(INTDIR)\JDFAutoBindingIntent.sbr" \
	"$(INTDIR)\JDFAutoColorIntent.sbr" \
	"$(INTDIR)\JDFAutoDeliveryIntent.sbr" \
	"$(INTDIR)\JDFAutoEmbossingIntent.sbr" \
	"$(INTDIR)\JDFAutoFoldingIntent.sbr" \
	"$(INTDIR)\JDFAutoHoleMakingIntent.sbr" \
	"$(INTDIR)\JDFAutoInsertingIntent.sbr" \
	"$(INTDIR)\JDFAutoLaminatingIntent.sbr" \
	"$(INTDIR)\JDFAutoLayoutIntent.sbr" \
	"$(INTDIR)\JDFAutoMediaIntent.sbr" \
	"$(INTDIR)\JDFAutoNumberingIntent.sbr" \
	"$(INTDIR)\JDFAutoPackingIntent.sbr" \
	"$(INTDIR)\JDFAutoProductionIntent.sbr" \
	"$(INTDIR)\JDFAutoProofingIntent.sbr" \
	"$(INTDIR)\JDFAutoScreeningIntent.sbr" \
	"$(INTDIR)\JDFAutoShapeCuttingIntent.sbr" \
	"$(INTDIR)\JDFAutoSizeIntent.sbr" \
	"$(INTDIR)\JDFAutoAdhesiveBinding.sbr" \
	"$(INTDIR)\JDFAutoArtDelivery.sbr" \
	"$(INTDIR)\JDFAutoBindItem.sbr" \
	"$(INTDIR)\JDFAutoBindList.sbr" \
	"$(INTDIR)\JDFAutoBookCase.sbr" \
	"$(INTDIR)\JDFAutoChannelBinding.sbr" \
	"$(INTDIR)\JDFAutoCoilBinding.sbr" \
	"$(INTDIR)\JDFAutoColorsUsed.sbr" \
	"$(INTDIR)\JDFAutoCreditCard.sbr" \
	"$(INTDIR)\JDFAutoDropIntent.sbr" \
	"$(INTDIR)\JDFAutoDropItemIntent.sbr" \
	"$(INTDIR)\JDFAutoEdgeGluing.sbr" \
	"$(INTDIR)\JDFAutoEmbossingItem.sbr" \
	"$(INTDIR)\JDFAutoHardCoverBinding.sbr" \
	"$(INTDIR)\JDFAutoHoleList.sbr" \
	"$(INTDIR)\JDFAutoInsert.sbr" \
	"$(INTDIR)\JDFAutoInsertList.sbr" \
	"$(INTDIR)\JDFAutoNumberItem.sbr" \
	"$(INTDIR)\JDFAutoPayment.sbr" \
	"$(INTDIR)\JDFAutoPlasticCombBinding.sbr" \
	"$(INTDIR)\JDFAutoPricing.sbr" \
	"$(INTDIR)\JDFAutoProofItem.sbr" \
	"$(INTDIR)\JDFAutoRingBinding.sbr" \
	"$(INTDIR)\JDFAutoSaddleStitching.sbr" \
	"$(INTDIR)\JDFAutoShapeCut.sbr" \
	"$(INTDIR)\JDFAutoSideSewing.sbr" \
	"$(INTDIR)\JDFAutoSideStitching.sbr" \
	"$(INTDIR)\JDFAutoSoftCoverBinding.sbr" \
	"$(INTDIR)\JDFAutoStripBinding.sbr" \
	"$(INTDIR)\JDFAutoTabs.sbr" \
	"$(INTDIR)\JDFAutoTape.sbr" \
	"$(INTDIR)\JDFAutoThreadSealing.sbr" \
	"$(INTDIR)\JDFAutoThreadSewing.sbr" \
	"$(INTDIR)\JDFAutoWireCombBinding.sbr" \
	"$(INTDIR)\JDFAutoAddress.sbr" \
	"$(INTDIR)\JDFAutoAdhesiveBindingParams.sbr" \
	"$(INTDIR)\JDFAutoApprovalParams.sbr" \
	"$(INTDIR)\JDFAutoApprovalSuccess.sbr" \
	"$(INTDIR)\JDFAutoAssembly.sbr" \
	"$(INTDIR)\JDFAutoAssetListCreationParams.sbr" \
	"$(INTDIR)\JDFAutoAutomatedOverprintParams.sbr" \
	"$(INTDIR)\JDFAutoBinderySignature.sbr" \
	"$(INTDIR)\JDFAutoBlockPreparationParams.sbr" \
	"$(INTDIR)\JDFAutoBoxPackingParams.sbr" \
	"$(INTDIR)\JDFAutoBufferParams.sbr" \
	"$(INTDIR)\JDFAutoBundle.sbr" \
	"$(INTDIR)\JDFAutoBundlingParams.sbr" \
	"$(INTDIR)\JDFAutoByteMap.sbr" \
	"$(INTDIR)\JDFAutoCaseMakingParams.sbr" \
	"$(INTDIR)\JDFAutoCasingInParams.sbr" \
	"$(INTDIR)\JDFAutoChannelBindingParams.sbr" \
	"$(INTDIR)\JDFAutoCIELABMeasuringField.sbr" \
	"$(INTDIR)\JDFAutoCoilBindingParams.sbr" \
	"$(INTDIR)\JDFAutoCollectingParams.sbr" \
	"$(INTDIR)\JDFAutoColor.sbr" \
	"$(INTDIR)\JDFAutoColorantAlias.sbr" \
	"$(INTDIR)\JDFAutoColorantControl.sbr" \
	"$(INTDIR)\JDFAutoColorControlStrip.sbr" \
	"$(INTDIR)\JDFAutoColorCorrectionParams.sbr" \
	"$(INTDIR)\JDFAutoColorMeasurementConditions.sbr" \
	"$(INTDIR)\JDFAutoColorPool.sbr" \
	"$(INTDIR)\JDFAutoColorSpaceConversionOp.sbr" \
	"$(INTDIR)\JDFAutoColorSpaceConversionParams.sbr" \
	"$(INTDIR)\JDFAutoComChannel.sbr" \
	"$(INTDIR)\JDFAutoCompany.sbr" \
	"$(INTDIR)\JDFAutoComponent.sbr" \
	"$(INTDIR)\JDFAutoContact.sbr" \
	"$(INTDIR)\JDFAutoContactCopyParams.sbr" \
	"$(INTDIR)\JDFAutoConventionalPrintingParams.sbr" \
	"$(INTDIR)\JDFAutoCostCenter.sbr" \
	"$(INTDIR)\JDFAutoCoverApplicationParams.sbr" \
	"$(INTDIR)\JDFAutoCreasingParams.sbr" \
	"$(INTDIR)\JDFAutoCutBlock.sbr" \
	"$(INTDIR)\JDFAutoCutMark.sbr" \
	"$(INTDIR)\JDFAutoCuttingParams.sbr" \
	"$(INTDIR)\JDFAutoDBMergeParams.sbr" \
	"$(INTDIR)\JDFAutoDBRules.sbr" \
	"$(INTDIR)\JDFAutoDBSchema.sbr" \
	"$(INTDIR)\JDFAutoDBSelection.sbr" \
	"$(INTDIR)\JDFAutoDeliveryParams.sbr" \
	"$(INTDIR)\JDFAutoDensityMeasuringField.sbr" \
	"$(INTDIR)\JDFAutoDevelopingParams.sbr" \
	"$(INTDIR)\JDFAutoDevice.sbr" \
	"$(INTDIR)\JDFAutoDeviceMark.sbr" \
	"$(INTDIR)\JDFAutoDeviceNSpace.sbr" \
	"$(INTDIR)\JDFAutoDigitalDeliveryParams.sbr" \
	"$(INTDIR)\JDFAutoDigitalMedia.sbr" \
	"$(INTDIR)\JDFAutoDigitalPrintingParams.sbr" \
	"$(INTDIR)\JDFAutoDisjointing.sbr" \
	"$(INTDIR)\JDFAutoDisposition.sbr" \
	"$(INTDIR)\JDFAutoDividingParams.sbr" \
	"$(INTDIR)\JDFAutoElementColorParams.sbr" \
	"$(INTDIR)\JDFAutoEmbossingParams.sbr" \
	"$(INTDIR)\JDFAutoEmployee.sbr" \
	"$(INTDIR)\JDFAutoEndSheetGluingParams.sbr" \
	"$(INTDIR)\JDFAutoExposedMedia.sbr" \
	"$(INTDIR)\JDFAutoFeedingParams.sbr" \
	"$(INTDIR)\JDFAutoFileSpec.sbr" \
	"$(INTDIR)\JDFAutoFitPolicy.sbr" \
	"$(INTDIR)\JDFAutoFold.sbr" \
	"$(INTDIR)\JDFAutoFoldingParams.sbr" \
	"$(INTDIR)\JDFAutoFontParams.sbr" \
	"$(INTDIR)\JDFAutoFontPolicy.sbr" \
	"$(INTDIR)\JDFAutoFormatConversionParams.sbr" \
	"$(INTDIR)\JDFAutoGatheringParams.sbr" \
	"$(INTDIR)\JDFAutoGlueApplication.sbr" \
	"$(INTDIR)\JDFAutoGlueLine.sbr" \
	"$(INTDIR)\JDFAutoGluingParams.sbr" \
	"$(INTDIR)\JDFAutoHeadBandApplicationParams.sbr" \
	"$(INTDIR)\JDFAutoHole.sbr" \
	"$(INTDIR)\JDFAutoHoleLine.sbr" \
	"$(INTDIR)\JDFAutoHoleMakingParams.sbr" \
	"$(INTDIR)\JDFAutoIdentificationField.sbr" \
	"$(INTDIR)\JDFAutoIDPrintingParams.sbr" \
	"$(INTDIR)\JDFAutoImageCompressionParams.sbr" \
	"$(INTDIR)\JDFAutoImageReplacementParams.sbr" \
	"$(INTDIR)\JDFAutoImageSetterParams.sbr" \
	"$(INTDIR)\JDFAutoInk.sbr" \
	"$(INTDIR)\JDFAutoInkZoneCalculationParams.sbr" \
	"$(INTDIR)\JDFAutoInkZoneProfile.sbr" \
	"$(INTDIR)\JDFAutoInsertingParams.sbr" \
	"$(INTDIR)\JDFAutoInsertSheet.sbr" \
	"$(INTDIR)\JDFAutoInterpretedPDLData.sbr" \
	"$(INTDIR)\JDFAutoInterpretingParams.sbr" \
	"$(INTDIR)\JDFAutoJacketingParams.sbr" \
	"$(INTDIR)\JDFAutoJobField.sbr" \
	"$(INTDIR)\JDFAutoLabelingParams.sbr" \
	"$(INTDIR)\JDFAutoLaminatingParams.sbr" \
	"$(INTDIR)\JDFAutoLayout.sbr" \
	"$(INTDIR)\JDFAutoLayoutElement.sbr" \
	"$(INTDIR)\JDFAutoLayoutPreparationParams.sbr" \
	"$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.sbr" \
	"$(INTDIR)\JDFAutoManualLaborParams.sbr" \
	"$(INTDIR)\JDFAutoMedia.sbr" \
	"$(INTDIR)\JDFAutoMediaSource.sbr" \
	"$(INTDIR)\JDFAutoMISDetails.sbr" \
	"$(INTDIR)\JDFAutoNumberingParams.sbr" \
	"$(INTDIR)\JDFAutoObjectResolution.sbr" \
	"$(INTDIR)\JDFAutoOrderingParams.sbr" \
	"$(INTDIR)\JDFAutoPackingParams.sbr" \
	"$(INTDIR)\JDFAutoPageList.sbr" \
	"$(INTDIR)\JDFAutoPallet.sbr" \
	"$(INTDIR)\JDFAutoPalletizingParams.sbr" \
	"$(INTDIR)\JDFAutoPDFToPSConversionParams.sbr" \
	"$(INTDIR)\JDFAutoPDLResourceAlias.sbr" \
	"$(INTDIR)\JDFAutoPerforatingParams.sbr" \
	"$(INTDIR)\JDFAutoPerson.sbr" \
	"$(INTDIR)\JDFAutoPlaceHolderResource.sbr" \
	"$(INTDIR)\JDFAutoPlasticCombBindingParams.sbr" \
	"$(INTDIR)\JDFAutoPlateCopyParams.sbr" \
	"$(INTDIR)\JDFAutoPreflightAnalysis.sbr" \
	"$(INTDIR)\JDFAutoPreflightInventory.sbr" \
	"$(INTDIR)\JDFAutoPreflightParams.sbr" \
	"$(INTDIR)\JDFAutoPreflightProfile.sbr" \
	"$(INTDIR)\JDFAutoPreflightReport.sbr" \
	"$(INTDIR)\JDFAutoPreflightReportRulePool.sbr" \
	"$(INTDIR)\JDFAutoPreview.sbr" \
	"$(INTDIR)\JDFAutoPreviewGenerationParams.sbr" \
	"$(INTDIR)\JDFAutoPrintCondition.sbr" \
	"$(INTDIR)\JDFAutoPrintRollingParams.sbr" \
	"$(INTDIR)\JDFAutoProofingParams.sbr" \
	"$(INTDIR)\JDFAutoPSToPDFConversionParams.sbr" \
	"$(INTDIR)\JDFAutoQualityControlParams.sbr" \
	"$(INTDIR)\JDFAutoQualityControlResult.sbr" \
	"$(INTDIR)\JDFAutoRegisterMark.sbr" \
	"$(INTDIR)\JDFAutoRegisterRibbon.sbr" \
	"$(INTDIR)\JDFAutoRenderingParams.sbr" \
	"$(INTDIR)\JDFAutoResourceDefinitionParams.sbr" \
	"$(INTDIR)\JDFAutoRingBindingParams.sbr" \
	"$(INTDIR)\JDFAutoRollStand.sbr" \
	"$(INTDIR)\JDFAutoRunList.sbr" \
	"$(INTDIR)\JDFAutoSaddleStitchingParams.sbr" \
	"$(INTDIR)\JDFAutoScanParams.sbr" \
	"$(INTDIR)\JDFAutoScavengerArea.sbr" \
	"$(INTDIR)\JDFAutoScreeningParams.sbr" \
	"$(INTDIR)\JDFAutoSeparationControlParams.sbr" \
	"$(INTDIR)\JDFAutoSeparationSpec.sbr" \
	"$(INTDIR)\JDFAutoShapeCuttingParams.sbr" \
	"$(INTDIR)\JDFAutoSheet.sbr" \
	"$(INTDIR)\JDFAutoShrinkingParams.sbr" \
	"$(INTDIR)\JDFAutoSideSewingParams.sbr" \
	"$(INTDIR)\JDFAutoSpinePreparationParams.sbr" \
	"$(INTDIR)\JDFAutoSpineTapingParams.sbr" \
	"$(INTDIR)\JDFAutoStackingParams.sbr" \
	"$(INTDIR)\JDFAutoStitchingParams.sbr" \
	"$(INTDIR)\JDFAutoStrap.sbr" \
	"$(INTDIR)\JDFAutoStrappingParams.sbr" \
	"$(INTDIR)\JDFAutoStripBindingParams.sbr" \
	"$(INTDIR)\JDFAutoStrippingParams.sbr" \
	"$(INTDIR)\JDFAutoSurface.sbr" \
	"$(INTDIR)\JDFAutoThreadSealingParams.sbr" \
	"$(INTDIR)\JDFAutoThreadSewingParams.sbr" \
	"$(INTDIR)\JDFAutoTile.sbr" \
	"$(INTDIR)\JDFAutoTool.sbr" \
	"$(INTDIR)\JDFAutoTransferCurve.sbr" \
	"$(INTDIR)\JDFAutoTransferCurvePool.sbr" \
	"$(INTDIR)\JDFAutoTransferFunctionControl.sbr" \
	"$(INTDIR)\JDFAutoTrappingDetails.sbr" \
	"$(INTDIR)\JDFAutoTrappingParams.sbr" \
	"$(INTDIR)\JDFAutoTrapRegion.sbr" \
	"$(INTDIR)\JDFAutoTrimmingParams.sbr" \
	"$(INTDIR)\JDFAutoVerificationParams.sbr" \
	"$(INTDIR)\JDFAutoWireCombBindingParams.sbr" \
	"$(INTDIR)\JDFAutoWrappingParams.sbr" \
	"$(INTDIR)\JDFArgumentValue.sbr" \
	"$(INTDIR)\JDFAutoAdvancedParams.sbr" \
	"$(INTDIR)\JDFAutoApprovalPerson.sbr" \
	"$(INTDIR)\JDFAutoArgumentValue.sbr" \
	"$(INTDIR)\JDFAutoAssemblySection.sbr" \
	"$(INTDIR)\JDFAutoBand.sbr" \
	"$(INTDIR)\JDFAutoBasicPreflightTest.sbr" \
	"$(INTDIR)\JDFAutoBindingQualityParams.sbr" \
	"$(INTDIR)\JDFAutoBoxArgument.sbr" \
	"$(INTDIR)\JDFAutoBoxToBoxDifference.sbr" \
	"$(INTDIR)\JDFAutoBundleItem.sbr" \
	"$(INTDIR)\JDFAutoCCITTFaxParams.sbr" \
	"$(INTDIR)\JDFAutoCollatingItem.sbr" \
	"$(INTDIR)\JDFAutoColorantZoneDetails.sbr" \
	"$(INTDIR)\JDFAutoColorCorrectionOp.sbr" \
	"$(INTDIR)\JDFAutoColorSpaceSubstitute.sbr" \
	"$(INTDIR)\JDFAutoContainer.sbr" \
	"$(INTDIR)\JDFAutoContentObject.sbr" \
	"$(INTDIR)\JDFAutoCrease.sbr" \
	"$(INTDIR)\JDFAutoCut.sbr" \
	"$(INTDIR)\JDFAutoDCTParams.sbr" \
	"$(INTDIR)\JDFAutoDependencies.sbr" \
	"$(INTDIR)\JDFAutoDeviceNColor.sbr" \
	"$(INTDIR)\JDFAutoDrop.sbr" \
	"$(INTDIR)\JDFAutoDropItem.sbr" \
	"$(INTDIR)\JDFAutoDynamicField.sbr" \
	"$(INTDIR)\JDFAutoDynamicInput.sbr" \
	"$(INTDIR)\JDFAutoEmboss.sbr" \
	"$(INTDIR)\JDFAutoEndSheet.sbr" \
	"$(INTDIR)\JDFAutoFeeder.sbr" \
	"$(INTDIR)\JDFAutoFeederQualityParams.sbr" \
	"$(INTDIR)\JDFAutoFileAlias.sbr" \
	"$(INTDIR)\JDFAutoFlateParams.sbr" \
	"$(INTDIR)\JDFAutoGlue.sbr" \
	"$(INTDIR)\JDFAutoIcon.sbr" \
	"$(INTDIR)\JDFAutoIconList.sbr" \
	"$(INTDIR)\JDFAutoIDPCover.sbr" \
	"$(INTDIR)\JDFAutoIDPFinishing.sbr" \
	"$(INTDIR)\JDFAutoIDPFolding.sbr" \
	"$(INTDIR)\JDFAutoIDPHoleMaking.sbr" \
	"$(INTDIR)\JDFAutoIDPImageShift.sbr" \
	"$(INTDIR)\JDFAutoIDPJobSheet.sbr" \
	"$(INTDIR)\JDFAutoIDPLayout.sbr" \
	"$(INTDIR)\JDFAutoIDPStitching.sbr" \
	"$(INTDIR)\JDFAutoIDPTrimming.sbr" \
	"$(INTDIR)\JDFAutoImageCompression.sbr" \
	"$(INTDIR)\JDFAutoImageShift.sbr" \
	"$(INTDIR)\JDFAutoLayerDetails.sbr" \
	"$(INTDIR)\JDFAutoLayerList.sbr" \
	"$(INTDIR)\JDFAutoLongFold.sbr" \
	"$(INTDIR)\JDFAutoLongGlue.sbr" \
	"$(INTDIR)\JDFAutoLongPerforate.sbr" \
	"$(INTDIR)\JDFAutoLongSlit.sbr" \
	"$(INTDIR)\JDFAutoLZWParams.sbr" \
	"$(INTDIR)\JDFAutoMarkObject.sbr" \
	"$(INTDIR)\JDFAutoNumberingParam.sbr" \
	"$(INTDIR)\JDFAutoPageCell.sbr" \
	"$(INTDIR)\JDFAutoPageData.sbr" \
	"$(INTDIR)\JDFAutoPDFInterpretingParams.sbr" \
	"$(INTDIR)\JDFAutoPDFXParams.sbr" \
	"$(INTDIR)\JDFAutoPerforate.sbr" \
	"$(INTDIR)\JDFAutoPixelColorant.sbr" \
	"$(INTDIR)\JDFAutoPosition.sbr" \
	"$(INTDIR)\JDFAutoPreflightAction.sbr" \
	"$(INTDIR)\JDFAutoPreflightArgument.sbr" \
	"$(INTDIR)\JDFAutoPreflightConstraint.sbr" \
	"$(INTDIR)\JDFAutoPreflightDetail.sbr" \
	"$(INTDIR)\JDFAutoPreflightInstance.sbr" \
	"$(INTDIR)\JDFAutoPreflightInstanceDetail.sbr" \
	"$(INTDIR)\JDFAutoPreflightValue.sbr" \
	"$(INTDIR)\JDFAutoPRError.sbr" \
	"$(INTDIR)\JDFAutoPRGroup.sbr" \
	"$(INTDIR)\JDFAutoPrintConditionColor.sbr" \
	"$(INTDIR)\JDFAutoPRItem.sbr" \
	"$(INTDIR)\JDFAutoPROccurence.sbr" \
	"$(INTDIR)\JDFAutoProperties.sbr" \
	"$(INTDIR)\JDFAutoPRRule.sbr" \
	"$(INTDIR)\JDFAutoPRRuleAttr.sbr" \
	"$(INTDIR)\JDFAutoQualityMeasurement.sbr" \
	"$(INTDIR)\JDFAutoResourceParam.sbr" \
	"$(INTDIR)\JDFAutoScore.sbr" \
	"$(INTDIR)\JDFAutoScreenSelector.sbr" \
	"$(INTDIR)\JDFAutoShapeElement.sbr" \
	"$(INTDIR)\JDFAutoSignature.sbr" \
	"$(INTDIR)\JDFAutoSignatureCell.sbr" \
	"$(INTDIR)\JDFAutoStringListValue.sbr" \
	"$(INTDIR)\JDFAutoStripCellParams.sbr" \
	"$(INTDIR)\JDFAutoThinPDFParams.sbr" \
	"$(INTDIR)\JDFAutoTIFFEmbeddedFile.sbr" \
	"$(INTDIR)\JDFAutoTIFFFormatParams.sbr" \
	"$(INTDIR)\JDFAutoTIFFtag.sbr" \
	"$(INTDIR)\JDFAutoTransferCurveSet.sbr" \
	"$(INTDIR)\JDFAutoTrappingOrder.sbr" \
	"$(INTDIR)\JDFAutoAction.sbr" \
	"$(INTDIR)\JDFAutoActionPool.sbr" \
	"$(INTDIR)\JDFAutoand.sbr" \
	"$(INTDIR)\JDFAutocall.sbr" \
	"$(INTDIR)\JDFAutochoice.sbr" \
	"$(INTDIR)\JDFAutoDevCap.sbr" \
	"$(INTDIR)\JDFAutoDevCaps.sbr" \
	"$(INTDIR)\JDFAutoDeviceCap.sbr" \
	"$(INTDIR)\JDFAutoDisplayGroup.sbr" \
	"$(INTDIR)\JDFAutoDisplayGroupPool.sbr" \
	"$(INTDIR)\JDFAutoFeatureAttribute.sbr" \
	"$(INTDIR)\JDFAutoFeaturePool.sbr" \
	"$(INTDIR)\JDFAutoLoc.sbr" \
	"$(INTDIR)\JDFAutomacro.sbr" \
	"$(INTDIR)\JDFAutoMacroPool.sbr" \
	"$(INTDIR)\JDFAutonot.sbr" \
	"$(INTDIR)\JDFAutoor.sbr" \
	"$(INTDIR)\JDFAutootherwise.sbr" \
	"$(INTDIR)\JDFAutoPerformance.sbr" \
	"$(INTDIR)\JDFAutoset.sbr" \
	"$(INTDIR)\JDFAutoTest.sbr" \
	"$(INTDIR)\JDFAutoTestPool.sbr" \
	"$(INTDIR)\JDFAutoTestRef.sbr" \
	"$(INTDIR)\JDFAutoValue.sbr" \
	"$(INTDIR)\JDFAutoValueLoc.sbr" \
	"$(INTDIR)\JDFAutowhen.sbr" \
	"$(INTDIR)\JDFAutoxor.sbr" \
	"$(INTDIR)\JDFAutoEnumerationSpan.sbr" \
	"$(INTDIR)\JDFAutoPRGroupOccurence.sbr" \
	"$(INTDIR)\JDFAutoPRGroupOccurenceBase.sbr" \
	"$(INTDIR)\JDFPreflightConstraintsPool.sbr" \
	"$(INTDIR)\JDFPreflightResultsPool.sbr" \
	"$(INTDIR)\JDFPRGroupOccurence.sbr" \
	"$(INTDIR)\JDFPRGroupOccurenceBase.sbr" \
	"$(INTDIR)\JDFDateTimeRange.sbr" \
	"$(INTDIR)\JDFDateTimeRangeList.sbr" \
	"$(INTDIR)\JDFDurationRange.sbr" \
	"$(INTDIR)\JDFDurationRangeList.sbr" \
	"$(INTDIR)\JDFIntegerRange.sbr" \
	"$(INTDIR)\JDFIntegerRangeList.sbr" \
	"$(INTDIR)\JDFNameRangeList.sbr" \
	"$(INTDIR)\JDFNumberRangeList.sbr" \
	"$(INTDIR)\JDFNumTypeList.sbr" \
	"$(INTDIR)\JDFParser.sbr" \
	"$(INTDIR)\JDFRange.sbr" \
	"$(INTDIR)\JDFRangeList.sbr" \
	"$(INTDIR)\JDFXYPairRangeList.sbr" \
	"$(INTDIR)\KElement.sbr" \
	"$(INTDIR)\KElementStrings.sbr" \
	"$(INTDIR)\MyDate.sbr" \
	"$(INTDIR)\vElement.sbr" \
	"$(INTDIR)\XMLDoc.sbr" \
	"$(INTDIR)\XMLDocUserData.sbr"

"$(OUTDIR)\JDFWrapperLib.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=xilink6.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\JDFWrapperDLL.pdb" /map:"$(INTDIR)\JDFWrapperDLL.map" /machine:I386 /nodefaultlib:"libcmt.lib" /nodefaultlib:"libcpmt.lib" /nodefaultlib:"libc.lib" /out:"$(OUTDIR)\JDFWrapperDLL.dll" /implib:"$(OUTDIR)\JDFWrapperDLL.lib" /libpath:"..\..\..\external\stlport\lib" 
LINK32_OBJS= \
	"$(INTDIR)\JDFAmountPool.obj" \
	"$(INTDIR)\JDFAncestor.obj" \
	"$(INTDIR)\JDFAncestorPool.obj" \
	"$(INTDIR)\JDFAudit.obj" \
	"$(INTDIR)\JDFAuditPool.obj" \
	"$(INTDIR)\JDFBarcode.obj" \
	"$(INTDIR)\JDFBusinessInfo.obj" \
	"$(INTDIR)\JDFComment.obj" \
	"$(INTDIR)\JDFCounterReset.obj" \
	"$(INTDIR)\JDFCreated.obj" \
	"$(INTDIR)\JDFCustomerInfo.obj" \
	"$(INTDIR)\JDFCustomerMessage.obj" \
	"$(INTDIR)\JDFDeleted.obj" \
	"$(INTDIR)\JDFError.obj" \
	"$(INTDIR)\JDFEvent.obj" \
	"$(INTDIR)\JDFFCNKey.obj" \
	"$(INTDIR)\JDFLocation.obj" \
	"$(INTDIR)\JDFMerged.obj" \
	"$(INTDIR)\JDFModified.obj" \
	"$(INTDIR)\JDFModulePhase.obj" \
	"$(INTDIR)\JDFNode.obj" \
	"$(INTDIR)\JDFNodeInfo.obj" \
	"$(INTDIR)\JDFNotification.obj" \
	"$(INTDIR)\JDFPart.obj" \
	"$(INTDIR)\JDFPartAmount.obj" \
	"$(INTDIR)\JDFPartStatus.obj" \
	"$(INTDIR)\JDFPhaseTime.obj" \
	"$(INTDIR)\JDFProcessRun.obj" \
	"$(INTDIR)\JDFResourceAudit.obj" \
	"$(INTDIR)\JDFResourceLinkPool.obj" \
	"$(INTDIR)\JDFResourcePool.obj" \
	"$(INTDIR)\JDFSpawned.obj" \
	"$(INTDIR)\JDFStatusPool.obj" \
	"$(INTDIR)\JDFSystemTimeSet.obj" \
	"$(INTDIR)\JDFAcknowledge.obj" \
	"$(INTDIR)\JDFAdded.obj" \
	"$(INTDIR)\JDFChangedAttribute.obj" \
	"$(INTDIR)\JDFChangedPath.obj" \
	"$(INTDIR)\JDFCommand.obj" \
	"$(INTDIR)\JDFDeviceFilter.obj" \
	"$(INTDIR)\JDFDeviceInfo.obj" \
	"$(INTDIR)\JDFDeviceList.obj" \
	"$(INTDIR)\JDFEmployeeDef.obj" \
	"$(INTDIR)\JDFFlushedResources.obj" \
	"$(INTDIR)\JDFFlushQueueParams.obj" \
	"$(INTDIR)\JDFFlushResourceParams.obj" \
	"$(INTDIR)\JDFIDInfo.obj" \
	"$(INTDIR)\JDFJDFController.obj" \
	"$(INTDIR)\JDFJDFService.obj" \
	"$(INTDIR)\JDFJMF.obj" \
	"$(INTDIR)\JDFJobPhase.obj" \
	"$(INTDIR)\JDFKnownMsgQuParams.obj" \
	"$(INTDIR)\JDFMessage.obj" \
	"$(INTDIR)\JDFMessageElement.obj" \
	"$(INTDIR)\JDFMessageService.obj" \
	"$(INTDIR)\JDFModuleStatus.obj" \
	"$(INTDIR)\JDFMsgFilter.obj" \
	"$(INTDIR)\JDFNewJDFCmdParams.obj" \
	"$(INTDIR)\JDFNewJDFQuParams.obj" \
	"$(INTDIR)\JDFNodeInfoCmdParams.obj" \
	"$(INTDIR)\JDFNodeInfoQuParams.obj" \
	"$(INTDIR)\JDFNodeInfoResp.obj" \
	"$(INTDIR)\JDFNotificationDef.obj" \
	"$(INTDIR)\JDFNotificationFilter.obj" \
	"$(INTDIR)\JDFObservationTarget.obj" \
	"$(INTDIR)\JDFOccupation.obj" \
	"$(INTDIR)\JDFPipeParams.obj" \
	"$(INTDIR)\JDFQuery.obj" \
	"$(INTDIR)\JDFQueue.obj" \
	"$(INTDIR)\JDFQueueEntry.obj" \
	"$(INTDIR)\JDFQueueEntryDef.obj" \
	"$(INTDIR)\JDFQueueEntryDefList.obj" \
	"$(INTDIR)\JDFQueueEntryPosParams.obj" \
	"$(INTDIR)\JDFQueueEntryPriParams.obj" \
	"$(INTDIR)\JDFQueueFilter.obj" \
	"$(INTDIR)\JDFQueueSubmissionParams.obj" \
	"$(INTDIR)\JDFRemoved.obj" \
	"$(INTDIR)\JDFRequestQueueEntryParams.obj" \
	"$(INTDIR)\JDFResourceCmdParams.obj" \
	"$(INTDIR)\JDFResourceInfo.obj" \
	"$(INTDIR)\JDFResourcePullParams.obj" \
	"$(INTDIR)\JDFResourceQuParams.obj" \
	"$(INTDIR)\JDFResponse.obj" \
	"$(INTDIR)\JDFResubmissionParams.obj" \
	"$(INTDIR)\JDFReturnQueueEntryParams.obj" \
	"$(INTDIR)\JDFShutDownCmdParams.obj" \
	"$(INTDIR)\JDFSignal.obj" \
	"$(INTDIR)\JDFStatusQuParams.obj" \
	"$(INTDIR)\JDFStopPersChParams.obj" \
	"$(INTDIR)\JDFSubmissionMethods.obj" \
	"$(INTDIR)\JDFSubscription.obj" \
	"$(INTDIR)\JDFTrackFilter.obj" \
	"$(INTDIR)\JDFTrackResult.obj" \
	"$(INTDIR)\JDFTrigger.obj" \
	"$(INTDIR)\JDFWakeUpCmdParams.obj" \
	"$(INTDIR)\JDFArtDeliveryIntent.obj" \
	"$(INTDIR)\JDFBindingIntent.obj" \
	"$(INTDIR)\JDFColorIntent.obj" \
	"$(INTDIR)\JDFDeliveryIntent.obj" \
	"$(INTDIR)\JDFEmbossingIntent.obj" \
	"$(INTDIR)\JDFFoldingIntent.obj" \
	"$(INTDIR)\JDFHoleMakingIntent.obj" \
	"$(INTDIR)\JDFInsertingIntent.obj" \
	"$(INTDIR)\JDFIntentResource.obj" \
	"$(INTDIR)\JDFLaminatingIntent.obj" \
	"$(INTDIR)\JDFLayoutIntent.obj" \
	"$(INTDIR)\JDFMediaIntent.obj" \
	"$(INTDIR)\JDFNumberingIntent.obj" \
	"$(INTDIR)\JDFPackingIntent.obj" \
	"$(INTDIR)\JDFProductionIntent.obj" \
	"$(INTDIR)\JDFProofingIntent.obj" \
	"$(INTDIR)\JDFScreeningIntent.obj" \
	"$(INTDIR)\JDFShapeCuttingIntent.obj" \
	"$(INTDIR)\JDFSizeIntent.obj" \
	"$(INTDIR)\JDFSpan.obj" \
	"$(INTDIR)\JDFAdhesiveBinding.obj" \
	"$(INTDIR)\JDFArtDelivery.obj" \
	"$(INTDIR)\JDFBindItem.obj" \
	"$(INTDIR)\JDFBindList.obj" \
	"$(INTDIR)\JDFBookCase.obj" \
	"$(INTDIR)\JDFChannelBinding.obj" \
	"$(INTDIR)\JDFCoilBinding.obj" \
	"$(INTDIR)\JDFColorsUsed.obj" \
	"$(INTDIR)\JDFCreditCard.obj" \
	"$(INTDIR)\JDFDropIntent.obj" \
	"$(INTDIR)\JDFDropItemIntent.obj" \
	"$(INTDIR)\JDFEdgeGluing.obj" \
	"$(INTDIR)\JDFEmbossingItem.obj" \
	"$(INTDIR)\JDFHardCoverBinding.obj" \
	"$(INTDIR)\JDFHoleList.obj" \
	"$(INTDIR)\JDFInsert.obj" \
	"$(INTDIR)\JDFInsertList.obj" \
	"$(INTDIR)\JDFNumberItem.obj" \
	"$(INTDIR)\JDFPayment.obj" \
	"$(INTDIR)\JDFPlasticCombBinding.obj" \
	"$(INTDIR)\JDFPricing.obj" \
	"$(INTDIR)\JDFProofItem.obj" \
	"$(INTDIR)\JDFRingBinding.obj" \
	"$(INTDIR)\JDFSaddleStitching.obj" \
	"$(INTDIR)\JDFShapeCut.obj" \
	"$(INTDIR)\JDFSideSewing.obj" \
	"$(INTDIR)\JDFSideStitching.obj" \
	"$(INTDIR)\JDFSoftCoverBinding.obj" \
	"$(INTDIR)\JDFStripBinding.obj" \
	"$(INTDIR)\JDFTabs.obj" \
	"$(INTDIR)\JDFTape.obj" \
	"$(INTDIR)\JDFThreadSealing.obj" \
	"$(INTDIR)\JDFThreadSewing.obj" \
	"$(INTDIR)\JDFWireCombBinding.obj" \
	"$(INTDIR)\JDFAddress.obj" \
	"$(INTDIR)\JDFAdhesiveBindingParams.obj" \
	"$(INTDIR)\JDFApprovalParams.obj" \
	"$(INTDIR)\JDFApprovalSuccess.obj" \
	"$(INTDIR)\JDFAssembly.obj" \
	"$(INTDIR)\JDFAssetListCreationParams.obj" \
	"$(INTDIR)\JDFAutomatedOverprintParams.obj" \
	"$(INTDIR)\JDFBinderySignature.obj" \
	"$(INTDIR)\JDFBlockPreparationParams.obj" \
	"$(INTDIR)\JDFBoxPackingParams.obj" \
	"$(INTDIR)\JDFBufferParams.obj" \
	"$(INTDIR)\JDFBundle.obj" \
	"$(INTDIR)\JDFBundlingParams.obj" \
	"$(INTDIR)\JDFByteMap.obj" \
	"$(INTDIR)\JDFCaseMakingParams.obj" \
	"$(INTDIR)\JDFCasingInParams.obj" \
	"$(INTDIR)\JDFChannelBindingParams.obj" \
	"$(INTDIR)\JDFCIELABMeasuringField.obj" \
	"$(INTDIR)\JDFCoilBindingParams.obj" \
	"$(INTDIR)\JDFCollectingParams.obj" \
	"$(INTDIR)\JDFColor.obj" \
	"$(INTDIR)\JDFColorantAlias.obj" \
	"$(INTDIR)\JDFColorantControl.obj" \
	"$(INTDIR)\JDFColorControlStrip.obj" \
	"$(INTDIR)\JDFColorCorrectionParams.obj" \
	"$(INTDIR)\JDFColorMeasurementConditions.obj" \
	"$(INTDIR)\JDFColorPool.obj" \
	"$(INTDIR)\JDFColorSpaceConversionOp.obj" \
	"$(INTDIR)\JDFColorSpaceConversionParams.obj" \
	"$(INTDIR)\JDFComChannel.obj" \
	"$(INTDIR)\JDFCompany.obj" \
	"$(INTDIR)\JDFComponent.obj" \
	"$(INTDIR)\JDFContact.obj" \
	"$(INTDIR)\JDFContactCopyParams.obj" \
	"$(INTDIR)\JDFConventionalPrintingParams.obj" \
	"$(INTDIR)\JDFCostCenter.obj" \
	"$(INTDIR)\JDFCoverApplicationParams.obj" \
	"$(INTDIR)\JDFCreasingParams.obj" \
	"$(INTDIR)\JDFCutBlock.obj" \
	"$(INTDIR)\JDFCutMark.obj" \
	"$(INTDIR)\JDFCuttingParams.obj" \
	"$(INTDIR)\JDFDBMergeParams.obj" \
	"$(INTDIR)\JDFDBRules.obj" \
	"$(INTDIR)\JDFDBSchema.obj" \
	"$(INTDIR)\JDFDBSelection.obj" \
	"$(INTDIR)\JDFDeliveryParams.obj" \
	"$(INTDIR)\JDFDensityMeasuringField.obj" \
	"$(INTDIR)\JDFDevelopingParams.obj" \
	"$(INTDIR)\JDFDevice.obj" \
	"$(INTDIR)\JDFDeviceMark.obj" \
	"$(INTDIR)\JDFDeviceNSpace.obj" \
	"$(INTDIR)\JDFDigitalDeliveryParams.obj" \
	"$(INTDIR)\JDFDigitalMedia.obj" \
	"$(INTDIR)\JDFDigitalPrintingParams.obj" \
	"$(INTDIR)\JDFDisjointing.obj" \
	"$(INTDIR)\JDFDisposition.obj" \
	"$(INTDIR)\JDFDividingParams.obj" \
	"$(INTDIR)\JDFElementColorParams.obj" \
	"$(INTDIR)\JDFEmbossingParams.obj" \
	"$(INTDIR)\JDFEmployee.obj" \
	"$(INTDIR)\JDFEndSheetGluingParams.obj" \
	"$(INTDIR)\JDFExposedMedia.obj" \
	"$(INTDIR)\JDFFeedingParams.obj" \
	"$(INTDIR)\JDFFileSpec.obj" \
	"$(INTDIR)\JDFFitPolicy.obj" \
	"$(INTDIR)\JDFFold.obj" \
	"$(INTDIR)\JDFFoldingParams.obj" \
	"$(INTDIR)\JDFFontParams.obj" \
	"$(INTDIR)\JDFFontPolicy.obj" \
	"$(INTDIR)\JDFFormatConversionParams.obj" \
	"$(INTDIR)\JDFGatheringParams.obj" \
	"$(INTDIR)\JDFGlueApplication.obj" \
	"$(INTDIR)\JDFGlueLine.obj" \
	"$(INTDIR)\JDFGluingParams.obj" \
	"$(INTDIR)\JDFHeadBandApplicationParams.obj" \
	"$(INTDIR)\JDFHole.obj" \
	"$(INTDIR)\JDFHoleLine.obj" \
	"$(INTDIR)\JDFHoleMakingParams.obj" \
	"$(INTDIR)\JDFIdentificationField.obj" \
	"$(INTDIR)\JDFIDPrintingParams.obj" \
	"$(INTDIR)\JDFImageCompressionParams.obj" \
	"$(INTDIR)\JDFImageReplacementParams.obj" \
	"$(INTDIR)\JDFImageSetterParams.obj" \
	"$(INTDIR)\JDFInk.obj" \
	"$(INTDIR)\JDFInkZoneCalculationParams.obj" \
	"$(INTDIR)\JDFInkZoneProfile.obj" \
	"$(INTDIR)\JDFInsertingParams.obj" \
	"$(INTDIR)\JDFInsertSheet.obj" \
	"$(INTDIR)\JDFInterpretedPDLData.obj" \
	"$(INTDIR)\JDFInterpretingParams.obj" \
	"$(INTDIR)\JDFJacketingParams.obj" \
	"$(INTDIR)\JDFJobField.obj" \
	"$(INTDIR)\JDFLabelingParams.obj" \
	"$(INTDIR)\JDFLaminatingParams.obj" \
	"$(INTDIR)\JDFLayout.obj" \
	"$(INTDIR)\JDFLayoutElement.obj" \
	"$(INTDIR)\JDFLayoutPreparationParams.obj" \
	"$(INTDIR)\JDFLongitudinalRibbonOperationParams.obj" \
	"$(INTDIR)\JDFManualLaborParams.obj" \
	"$(INTDIR)\JDFMedia.obj" \
	"$(INTDIR)\JDFMediaSource.obj" \
	"$(INTDIR)\JDFMISDetails.obj" \
	"$(INTDIR)\JDFNumberingParams.obj" \
	"$(INTDIR)\JDFObjectResolution.obj" \
	"$(INTDIR)\JDFOrderingParams.obj" \
	"$(INTDIR)\JDFPackingParams.obj" \
	"$(INTDIR)\JDFPageList.obj" \
	"$(INTDIR)\JDFPallet.obj" \
	"$(INTDIR)\JDFPalletizingParams.obj" \
	"$(INTDIR)\JDFPDFToPSConversionParams.obj" \
	"$(INTDIR)\JDFPDLResourceAlias.obj" \
	"$(INTDIR)\JDFPerforatingParams.obj" \
	"$(INTDIR)\JDFPerson.obj" \
	"$(INTDIR)\JDFPlaceHolderResource.obj" \
	"$(INTDIR)\JDFPlasticCombBindingParams.obj" \
	"$(INTDIR)\JDFPlateCopyParams.obj" \
	"$(INTDIR)\JDFPreflightAnalysis.obj" \
	"$(INTDIR)\JDFPreflightInventory.obj" \
	"$(INTDIR)\JDFPreflightParams.obj" \
	"$(INTDIR)\JDFPreflightProfile.obj" \
	"$(INTDIR)\JDFPreflightReport.obj" \
	"$(INTDIR)\JDFPreflightReportRulePool.obj" \
	"$(INTDIR)\JDFPreview.obj" \
	"$(INTDIR)\JDFPreviewGenerationParams.obj" \
	"$(INTDIR)\JDFPrintCondition.obj" \
	"$(INTDIR)\JDFPrintRollingParams.obj" \
	"$(INTDIR)\JDFProofingParams.obj" \
	"$(INTDIR)\JDFPSToPDFConversionParams.obj" \
	"$(INTDIR)\JDFQualityControlParams.obj" \
	"$(INTDIR)\JDFQualityControlResult.obj" \
	"$(INTDIR)\JDFRegisterMark.obj" \
	"$(INTDIR)\JDFRegisterRibbon.obj" \
	"$(INTDIR)\JDFRenderingParams.obj" \
	"$(INTDIR)\JDFResourceDefinitionParams.obj" \
	"$(INTDIR)\JDFRingBindingParams.obj" \
	"$(INTDIR)\JDFRollStand.obj" \
	"$(INTDIR)\JDFRunList.obj" \
	"$(INTDIR)\JDFSaddleStitchingParams.obj" \
	"$(INTDIR)\JDFScanParams.obj" \
	"$(INTDIR)\JDFScavengerArea.obj" \
	"$(INTDIR)\JDFScreeningParams.obj" \
	"$(INTDIR)\JDFSeparationControlParams.obj" \
	"$(INTDIR)\JDFSeparationSpec.obj" \
	"$(INTDIR)\JDFShapeCuttingParams.obj" \
	"$(INTDIR)\JDFSheet.obj" \
	"$(INTDIR)\JDFShrinkingParams.obj" \
	"$(INTDIR)\JDFSideSewingParams.obj" \
	"$(INTDIR)\JDFSpinePreparationParams.obj" \
	"$(INTDIR)\JDFSpineTapingParams.obj" \
	"$(INTDIR)\JDFStackingParams.obj" \
	"$(INTDIR)\JDFStitchingParams.obj" \
	"$(INTDIR)\JDFStrap.obj" \
	"$(INTDIR)\JDFStrappingParams.obj" \
	"$(INTDIR)\JDFStripBindingParams.obj" \
	"$(INTDIR)\JDFStrippingParams.obj" \
	"$(INTDIR)\JDFSurface.obj" \
	"$(INTDIR)\JDFThreadSealingParams.obj" \
	"$(INTDIR)\JDFThreadSewingParams.obj" \
	"$(INTDIR)\JDFTile.obj" \
	"$(INTDIR)\JDFTool.obj" \
	"$(INTDIR)\JDFTransferCurve.obj" \
	"$(INTDIR)\JDFTransferCurvePool.obj" \
	"$(INTDIR)\JDFTransferFunctionControl.obj" \
	"$(INTDIR)\JDFTrappingDetails.obj" \
	"$(INTDIR)\JDFTrappingParams.obj" \
	"$(INTDIR)\JDFTrapRegion.obj" \
	"$(INTDIR)\JDFTrimmingParams.obj" \
	"$(INTDIR)\JDFVerificationParams.obj" \
	"$(INTDIR)\JDFWireCombBindingParams.obj" \
	"$(INTDIR)\JDFWrappingParams.obj" \
	"$(INTDIR)\JDFAdvancedParams.obj" \
	"$(INTDIR)\JDFApprovalPerson.obj" \
	"$(INTDIR)\JDFAssemblySection.obj" \
	"$(INTDIR)\JDFBand.obj" \
	"$(INTDIR)\JDFBasicPreflightTest.obj" \
	"$(INTDIR)\JDFBindingQualityParams.obj" \
	"$(INTDIR)\JDFBoxArgument.obj" \
	"$(INTDIR)\JDFBoxToBoxDifference.obj" \
	"$(INTDIR)\JDFBundleItem.obj" \
	"$(INTDIR)\JDFCCITTFaxParams.obj" \
	"$(INTDIR)\JDFCollatingItem.obj" \
	"$(INTDIR)\JDFColorantZoneDetails.obj" \
	"$(INTDIR)\JDFColorCorrectionOp.obj" \
	"$(INTDIR)\JDFColorSpaceSubstitute.obj" \
	"$(INTDIR)\JDFContainer.obj" \
	"$(INTDIR)\JDFContentObject.obj" \
	"$(INTDIR)\JDFCrease.obj" \
	"$(INTDIR)\JDFCut.obj" \
	"$(INTDIR)\JDFDCTParams.obj" \
	"$(INTDIR)\JDFDependencies.obj" \
	"$(INTDIR)\JDFDeviceNColor.obj" \
	"$(INTDIR)\JDFDrop.obj" \
	"$(INTDIR)\JDFDropItem.obj" \
	"$(INTDIR)\JDFDynamicField.obj" \
	"$(INTDIR)\JDFDynamicInput.obj" \
	"$(INTDIR)\JDFEmboss.obj" \
	"$(INTDIR)\JDFEndSheet.obj" \
	"$(INTDIR)\JDFFeeder.obj" \
	"$(INTDIR)\JDFFeederQualityParams.obj" \
	"$(INTDIR)\JDFFileAlias.obj" \
	"$(INTDIR)\JDFFlateParams.obj" \
	"$(INTDIR)\JDFGlue.obj" \
	"$(INTDIR)\JDFIcon.obj" \
	"$(INTDIR)\JDFIconList.obj" \
	"$(INTDIR)\JDFIDPCover.obj" \
	"$(INTDIR)\JDFIDPFinishing.obj" \
	"$(INTDIR)\JDFIDPFolding.obj" \
	"$(INTDIR)\JDFIDPHoleMaking.obj" \
	"$(INTDIR)\JDFIDPImageShift.obj" \
	"$(INTDIR)\JDFIDPJobSheet.obj" \
	"$(INTDIR)\JDFIDPLayout.obj" \
	"$(INTDIR)\JDFIDPStitching.obj" \
	"$(INTDIR)\JDFIDPTrimming.obj" \
	"$(INTDIR)\JDFImageCompression.obj" \
	"$(INTDIR)\JDFImageShift.obj" \
	"$(INTDIR)\JDFLayerDetails.obj" \
	"$(INTDIR)\JDFLayerList.obj" \
	"$(INTDIR)\JDFLongFold.obj" \
	"$(INTDIR)\JDFLongGlue.obj" \
	"$(INTDIR)\JDFLongPerforate.obj" \
	"$(INTDIR)\JDFLongSlit.obj" \
	"$(INTDIR)\JDFLZWParams.obj" \
	"$(INTDIR)\JDFMarkObject.obj" \
	"$(INTDIR)\JDFNumberingParam.obj" \
	"$(INTDIR)\JDFPageCell.obj" \
	"$(INTDIR)\JDFPageData.obj" \
	"$(INTDIR)\JDFPDFInterpretingParams.obj" \
	"$(INTDIR)\JDFPDFXParams.obj" \
	"$(INTDIR)\JDFPerforate.obj" \
	"$(INTDIR)\JDFPixelColorant.obj" \
	"$(INTDIR)\JDFPosition.obj" \
	"$(INTDIR)\JDFPreflightAction.obj" \
	"$(INTDIR)\JDFPreflightArgument.obj" \
	"$(INTDIR)\JDFPreflightConstraint.obj" \
	"$(INTDIR)\JDFPreflightDetail.obj" \
	"$(INTDIR)\JDFPreflightInstance.obj" \
	"$(INTDIR)\JDFPreflightInstanceDetail.obj" \
	"$(INTDIR)\JDFPreflightValue.obj" \
	"$(INTDIR)\JDFPRError.obj" \
	"$(INTDIR)\JDFPRGroup.obj" \
	"$(INTDIR)\JDFPrintConditionColor.obj" \
	"$(INTDIR)\JDFPRItem.obj" \
	"$(INTDIR)\JDFPROccurence.obj" \
	"$(INTDIR)\JDFProperties.obj" \
	"$(INTDIR)\JDFPRRule.obj" \
	"$(INTDIR)\JDFPRRuleAttr.obj" \
	"$(INTDIR)\JDFQualityMeasurement.obj" \
	"$(INTDIR)\JDFResourceParam.obj" \
	"$(INTDIR)\JDFScore.obj" \
	"$(INTDIR)\JDFScreenSelector.obj" \
	"$(INTDIR)\JDFShapeElement.obj" \
	"$(INTDIR)\JDFSignature.obj" \
	"$(INTDIR)\JDFSignatureCell.obj" \
	"$(INTDIR)\JDFStringListValue.obj" \
	"$(INTDIR)\JDFStripCellParams.obj" \
	"$(INTDIR)\JDFThinPDFParams.obj" \
	"$(INTDIR)\JDFTIFFEmbeddedFile.obj" \
	"$(INTDIR)\JDFTIFFFormatParams.obj" \
	"$(INTDIR)\JDFTIFFtag.obj" \
	"$(INTDIR)\JDFTransferCurveSet.obj" \
	"$(INTDIR)\JDFTrappingOrder.obj" \
	"$(INTDIR)\JDFAction.obj" \
	"$(INTDIR)\JDFActionPool.obj" \
	"$(INTDIR)\JDFand.obj" \
	"$(INTDIR)\JDFBooleanEvaluation.obj" \
	"$(INTDIR)\JDFBooleanState.obj" \
	"$(INTDIR)\JDFcall.obj" \
	"$(INTDIR)\JDFchoice.obj" \
	"$(INTDIR)\JDFDateTimeEvaluation.obj" \
	"$(INTDIR)\JDFDateTimeState.obj" \
	"$(INTDIR)\JDFDevCap.obj" \
	"$(INTDIR)\JDFDevCaps.obj" \
	"$(INTDIR)\JDFDeviceCap.obj" \
	"$(INTDIR)\JDFDisplayGroup.obj" \
	"$(INTDIR)\JDFDisplayGroupPool.obj" \
	"$(INTDIR)\JDFDurationEvaluation.obj" \
	"$(INTDIR)\JDFDurationState.obj" \
	"$(INTDIR)\JDFEnumerationEvaluation.obj" \
	"$(INTDIR)\JDFEnumerationState.obj" \
	"$(INTDIR)\JDFEvaluation.obj" \
	"$(INTDIR)\JDFFeatureAttribute.obj" \
	"$(INTDIR)\JDFFeaturePool.obj" \
	"$(INTDIR)\JDFIntegerEvaluation.obj" \
	"$(INTDIR)\JDFIntegerState.obj" \
	"$(INTDIR)\JDFIsPresentEvaluation.obj" \
	"$(INTDIR)\JDFLoc.obj" \
	"$(INTDIR)\JDFmacro.obj" \
	"$(INTDIR)\JDFMacroPool.obj" \
	"$(INTDIR)\JDFMatrixEvaluation.obj" \
	"$(INTDIR)\JDFMatrixState.obj" \
	"$(INTDIR)\JDFNameEvaluation.obj" \
	"$(INTDIR)\JDFNameState.obj" \
	"$(INTDIR)\JDFnot.obj" \
	"$(INTDIR)\JDFNumberEvaluation.obj" \
	"$(INTDIR)\JDFNumberState.obj" \
	"$(INTDIR)\JDFor.obj" \
	"$(INTDIR)\JDFotherwise.obj" \
	"$(INTDIR)\JDFPDFPathEvaluation.obj" \
	"$(INTDIR)\JDFPDFPathState.obj" \
	"$(INTDIR)\JDFPerformance.obj" \
	"$(INTDIR)\JDFRectangleEvaluation.obj" \
	"$(INTDIR)\JDFRectangleState.obj" \
	"$(INTDIR)\JDFset.obj" \
	"$(INTDIR)\JDFShapeEvaluation.obj" \
	"$(INTDIR)\JDFShapeState.obj" \
	"$(INTDIR)\JDFState.obj" \
	"$(INTDIR)\JDFStringEvaluation.obj" \
	"$(INTDIR)\JDFStringState.obj" \
	"$(INTDIR)\JDFTest.obj" \
	"$(INTDIR)\JDFTestPool.obj" \
	"$(INTDIR)\JDFTestRef.obj" \
	"$(INTDIR)\JDFValue.obj" \
	"$(INTDIR)\JDFValueLoc.obj" \
	"$(INTDIR)\JDFwhen.obj" \
	"$(INTDIR)\JDFxor.obj" \
	"$(INTDIR)\JDFXYPairEvaluation.obj" \
	"$(INTDIR)\JDFXYPairState.obj" \
	"$(INTDIR)\JDFDoc.obj" \
	"$(INTDIR)\JDFElement.obj" \
	"$(INTDIR)\JDFFactory.obj" \
	"$(INTDIR)\JDFNodeFactory.obj" \
	"$(INTDIR)\JDFParamsFactory.obj" \
	"$(INTDIR)\JDFPool.obj" \
	"$(INTDIR)\JDFRefElement.obj" \
	"$(INTDIR)\JDFResource.obj" \
	"$(INTDIR)\JDFResourceLink.obj" \
	"$(INTDIR)\JDFRunElement.obj" \
	"$(INTDIR)\JDFSeparationList.obj" \
	"$(INTDIR)\JDFStrings.obj" \
	"$(INTDIR)\JDFAutoAmountPool.obj" \
	"$(INTDIR)\JDFAutoAncestor.obj" \
	"$(INTDIR)\JDFAutoAncestorPool.obj" \
	"$(INTDIR)\JDFAutoBarcode.obj" \
	"$(INTDIR)\JDFAutoBusinessInfo.obj" \
	"$(INTDIR)\JDFAutoComment.obj" \
	"$(INTDIR)\JDFAutoCounterReset.obj" \
	"$(INTDIR)\JDFAutoCreated.obj" \
	"$(INTDIR)\JDFAutoCustomerInfo.obj" \
	"$(INTDIR)\JDFAutoCustomerMessage.obj" \
	"$(INTDIR)\JDFAutoDeleted.obj" \
	"$(INTDIR)\JDFAutoError.obj" \
	"$(INTDIR)\JDFAutoEvent.obj" \
	"$(INTDIR)\JDFAutoFCNKey.obj" \
	"$(INTDIR)\JDFAutoLocation.obj" \
	"$(INTDIR)\JDFAutoMerged.obj" \
	"$(INTDIR)\JDFAutoModified.obj" \
	"$(INTDIR)\JDFAutoModulePhase.obj" \
	"$(INTDIR)\JDFAutoNodeInfo.obj" \
	"$(INTDIR)\JDFAutoNotification.obj" \
	"$(INTDIR)\JDFAutoPart.obj" \
	"$(INTDIR)\JDFAutoPartStatus.obj" \
	"$(INTDIR)\JDFAutoPhaseTime.obj" \
	"$(INTDIR)\JDFAutoProcessRun.obj" \
	"$(INTDIR)\JDFAutoResourceAudit.obj" \
	"$(INTDIR)\JDFAutoSpawned.obj" \
	"$(INTDIR)\JDFAutoStatusPool.obj" \
	"$(INTDIR)\JDFAutoSystemTimeSet.obj" \
	"$(INTDIR)\JDFAutoAcknowledge.obj" \
	"$(INTDIR)\JDFAutoAdded.obj" \
	"$(INTDIR)\JDFAutoChangedAttribute.obj" \
	"$(INTDIR)\JDFAutoChangedPath.obj" \
	"$(INTDIR)\JDFAutoCommand.obj" \
	"$(INTDIR)\JDFAutoDeviceFilter.obj" \
	"$(INTDIR)\JDFAutoDeviceInfo.obj" \
	"$(INTDIR)\JDFAutoDeviceList.obj" \
	"$(INTDIR)\JDFAutoEmployeeDef.obj" \
	"$(INTDIR)\JDFAutoFlushedResources.obj" \
	"$(INTDIR)\JDFAutoFlushQueueParams.obj" \
	"$(INTDIR)\JDFAutoFlushResourceParams.obj" \
	"$(INTDIR)\JDFAutoIDInfo.obj" \
	"$(INTDIR)\JDFAutoJDFController.obj" \
	"$(INTDIR)\JDFAutoJDFService.obj" \
	"$(INTDIR)\JDFAutoJMF.obj" \
	"$(INTDIR)\JDFAutoJobPhase.obj" \
	"$(INTDIR)\JDFAutoKnownMsgQuParams.obj" \
	"$(INTDIR)\JDFAutoMessage.obj" \
	"$(INTDIR)\JDFAutoMessageService.obj" \
	"$(INTDIR)\JDFAutoModuleStatus.obj" \
	"$(INTDIR)\JDFAutoMsgFilter.obj" \
	"$(INTDIR)\JDFAutoNewJDFCmdParams.obj" \
	"$(INTDIR)\JDFAutoNewJDFQuParams.obj" \
	"$(INTDIR)\JDFAutoNodeInfoCmdParams.obj" \
	"$(INTDIR)\JDFAutoNodeInfoQuParams.obj" \
	"$(INTDIR)\JDFAutoNodeInfoResp.obj" \
	"$(INTDIR)\JDFAutoNotificationDef.obj" \
	"$(INTDIR)\JDFAutoNotificationFilter.obj" \
	"$(INTDIR)\JDFAutoObservationTarget.obj" \
	"$(INTDIR)\JDFAutoOccupation.obj" \
	"$(INTDIR)\JDFAutoPipeParams.obj" \
	"$(INTDIR)\JDFAutoQuery.obj" \
	"$(INTDIR)\JDFAutoQueue.obj" \
	"$(INTDIR)\JDFAutoQueueEntry.obj" \
	"$(INTDIR)\JDFAutoQueueEntryDef.obj" \
	"$(INTDIR)\JDFAutoQueueEntryDefList.obj" \
	"$(INTDIR)\JDFAutoQueueEntryPosParams.obj" \
	"$(INTDIR)\JDFAutoQueueEntryPriParams.obj" \
	"$(INTDIR)\JDFAutoQueueFilter.obj" \
	"$(INTDIR)\JDFAutoQueueSubmissionParams.obj" \
	"$(INTDIR)\JDFAutoRemoved.obj" \
	"$(INTDIR)\JDFAutoRequestQueueEntryParams.obj" \
	"$(INTDIR)\JDFAutoResourceCmdParams.obj" \
	"$(INTDIR)\JDFAutoResourceInfo.obj" \
	"$(INTDIR)\JDFAutoResourcePullParams.obj" \
	"$(INTDIR)\JDFAutoResourceQuParams.obj" \
	"$(INTDIR)\JDFAutoResponse.obj" \
	"$(INTDIR)\JDFAutoResubmissionParams.obj" \
	"$(INTDIR)\JDFAutoReturnQueueEntryParams.obj" \
	"$(INTDIR)\JDFAutoShutDownCmdParams.obj" \
	"$(INTDIR)\JDFAutoSignal.obj" \
	"$(INTDIR)\JDFAutoStatusQuParams.obj" \
	"$(INTDIR)\JDFAutoStopPersChParams.obj" \
	"$(INTDIR)\JDFAutoSubmissionMethods.obj" \
	"$(INTDIR)\JDFAutoSubscription.obj" \
	"$(INTDIR)\JDFAutoTrackFilter.obj" \
	"$(INTDIR)\JDFAutoTrackResult.obj" \
	"$(INTDIR)\JDFAutoTrigger.obj" \
	"$(INTDIR)\JDFAutoWakeUpCmdParams.obj" \
	"$(INTDIR)\JDFAutoArtDeliveryIntent.obj" \
	"$(INTDIR)\JDFAutoBindingIntent.obj" \
	"$(INTDIR)\JDFAutoColorIntent.obj" \
	"$(INTDIR)\JDFAutoDeliveryIntent.obj" \
	"$(INTDIR)\JDFAutoEmbossingIntent.obj" \
	"$(INTDIR)\JDFAutoFoldingIntent.obj" \
	"$(INTDIR)\JDFAutoHoleMakingIntent.obj" \
	"$(INTDIR)\JDFAutoInsertingIntent.obj" \
	"$(INTDIR)\JDFAutoLaminatingIntent.obj" \
	"$(INTDIR)\JDFAutoLayoutIntent.obj" \
	"$(INTDIR)\JDFAutoMediaIntent.obj" \
	"$(INTDIR)\JDFAutoNumberingIntent.obj" \
	"$(INTDIR)\JDFAutoPackingIntent.obj" \
	"$(INTDIR)\JDFAutoProductionIntent.obj" \
	"$(INTDIR)\JDFAutoProofingIntent.obj" \
	"$(INTDIR)\JDFAutoScreeningIntent.obj" \
	"$(INTDIR)\JDFAutoShapeCuttingIntent.obj" \
	"$(INTDIR)\JDFAutoSizeIntent.obj" \
	"$(INTDIR)\JDFAutoAdhesiveBinding.obj" \
	"$(INTDIR)\JDFAutoArtDelivery.obj" \
	"$(INTDIR)\JDFAutoBindItem.obj" \
	"$(INTDIR)\JDFAutoBindList.obj" \
	"$(INTDIR)\JDFAutoBookCase.obj" \
	"$(INTDIR)\JDFAutoChannelBinding.obj" \
	"$(INTDIR)\JDFAutoCoilBinding.obj" \
	"$(INTDIR)\JDFAutoColorsUsed.obj" \
	"$(INTDIR)\JDFAutoCreditCard.obj" \
	"$(INTDIR)\JDFAutoDropIntent.obj" \
	"$(INTDIR)\JDFAutoDropItemIntent.obj" \
	"$(INTDIR)\JDFAutoEdgeGluing.obj" \
	"$(INTDIR)\JDFAutoEmbossingItem.obj" \
	"$(INTDIR)\JDFAutoHardCoverBinding.obj" \
	"$(INTDIR)\JDFAutoHoleList.obj" \
	"$(INTDIR)\JDFAutoInsert.obj" \
	"$(INTDIR)\JDFAutoInsertList.obj" \
	"$(INTDIR)\JDFAutoNumberItem.obj" \
	"$(INTDIR)\JDFAutoPayment.obj" \
	"$(INTDIR)\JDFAutoPlasticCombBinding.obj" \
	"$(INTDIR)\JDFAutoPricing.obj" \
	"$(INTDIR)\JDFAutoProofItem.obj" \
	"$(INTDIR)\JDFAutoRingBinding.obj" \
	"$(INTDIR)\JDFAutoSaddleStitching.obj" \
	"$(INTDIR)\JDFAutoShapeCut.obj" \
	"$(INTDIR)\JDFAutoSideSewing.obj" \
	"$(INTDIR)\JDFAutoSideStitching.obj" \
	"$(INTDIR)\JDFAutoSoftCoverBinding.obj" \
	"$(INTDIR)\JDFAutoStripBinding.obj" \
	"$(INTDIR)\JDFAutoTabs.obj" \
	"$(INTDIR)\JDFAutoTape.obj" \
	"$(INTDIR)\JDFAutoThreadSealing.obj" \
	"$(INTDIR)\JDFAutoThreadSewing.obj" \
	"$(INTDIR)\JDFAutoWireCombBinding.obj" \
	"$(INTDIR)\JDFAutoAddress.obj" \
	"$(INTDIR)\JDFAutoAdhesiveBindingParams.obj" \
	"$(INTDIR)\JDFAutoApprovalParams.obj" \
	"$(INTDIR)\JDFAutoApprovalSuccess.obj" \
	"$(INTDIR)\JDFAutoAssembly.obj" \
	"$(INTDIR)\JDFAutoAssetListCreationParams.obj" \
	"$(INTDIR)\JDFAutoAutomatedOverprintParams.obj" \
	"$(INTDIR)\JDFAutoBinderySignature.obj" \
	"$(INTDIR)\JDFAutoBlockPreparationParams.obj" \
	"$(INTDIR)\JDFAutoBoxPackingParams.obj" \
	"$(INTDIR)\JDFAutoBufferParams.obj" \
	"$(INTDIR)\JDFAutoBundle.obj" \
	"$(INTDIR)\JDFAutoBundlingParams.obj" \
	"$(INTDIR)\JDFAutoByteMap.obj" \
	"$(INTDIR)\JDFAutoCaseMakingParams.obj" \
	"$(INTDIR)\JDFAutoCasingInParams.obj" \
	"$(INTDIR)\JDFAutoChannelBindingParams.obj" \
	"$(INTDIR)\JDFAutoCIELABMeasuringField.obj" \
	"$(INTDIR)\JDFAutoCoilBindingParams.obj" \
	"$(INTDIR)\JDFAutoCollectingParams.obj" \
	"$(INTDIR)\JDFAutoColor.obj" \
	"$(INTDIR)\JDFAutoColorantAlias.obj" \
	"$(INTDIR)\JDFAutoColorantControl.obj" \
	"$(INTDIR)\JDFAutoColorControlStrip.obj" \
	"$(INTDIR)\JDFAutoColorCorrectionParams.obj" \
	"$(INTDIR)\JDFAutoColorMeasurementConditions.obj" \
	"$(INTDIR)\JDFAutoColorPool.obj" \
	"$(INTDIR)\JDFAutoColorSpaceConversionOp.obj" \
	"$(INTDIR)\JDFAutoColorSpaceConversionParams.obj" \
	"$(INTDIR)\JDFAutoComChannel.obj" \
	"$(INTDIR)\JDFAutoCompany.obj" \
	"$(INTDIR)\JDFAutoComponent.obj" \
	"$(INTDIR)\JDFAutoContact.obj" \
	"$(INTDIR)\JDFAutoContactCopyParams.obj" \
	"$(INTDIR)\JDFAutoConventionalPrintingParams.obj" \
	"$(INTDIR)\JDFAutoCostCenter.obj" \
	"$(INTDIR)\JDFAutoCoverApplicationParams.obj" \
	"$(INTDIR)\JDFAutoCreasingParams.obj" \
	"$(INTDIR)\JDFAutoCutBlock.obj" \
	"$(INTDIR)\JDFAutoCutMark.obj" \
	"$(INTDIR)\JDFAutoCuttingParams.obj" \
	"$(INTDIR)\JDFAutoDBMergeParams.obj" \
	"$(INTDIR)\JDFAutoDBRules.obj" \
	"$(INTDIR)\JDFAutoDBSchema.obj" \
	"$(INTDIR)\JDFAutoDBSelection.obj" \
	"$(INTDIR)\JDFAutoDeliveryParams.obj" \
	"$(INTDIR)\JDFAutoDensityMeasuringField.obj" \
	"$(INTDIR)\JDFAutoDevelopingParams.obj" \
	"$(INTDIR)\JDFAutoDevice.obj" \
	"$(INTDIR)\JDFAutoDeviceMark.obj" \
	"$(INTDIR)\JDFAutoDeviceNSpace.obj" \
	"$(INTDIR)\JDFAutoDigitalDeliveryParams.obj" \
	"$(INTDIR)\JDFAutoDigitalMedia.obj" \
	"$(INTDIR)\JDFAutoDigitalPrintingParams.obj" \
	"$(INTDIR)\JDFAutoDisjointing.obj" \
	"$(INTDIR)\JDFAutoDisposition.obj" \
	"$(INTDIR)\JDFAutoDividingParams.obj" \
	"$(INTDIR)\JDFAutoElementColorParams.obj" \
	"$(INTDIR)\JDFAutoEmbossingParams.obj" \
	"$(INTDIR)\JDFAutoEmployee.obj" \
	"$(INTDIR)\JDFAutoEndSheetGluingParams.obj" \
	"$(INTDIR)\JDFAutoExposedMedia.obj" \
	"$(INTDIR)\JDFAutoFeedingParams.obj" \
	"$(INTDIR)\JDFAutoFileSpec.obj" \
	"$(INTDIR)\JDFAutoFitPolicy.obj" \
	"$(INTDIR)\JDFAutoFold.obj" \
	"$(INTDIR)\JDFAutoFoldingParams.obj" \
	"$(INTDIR)\JDFAutoFontParams.obj" \
	"$(INTDIR)\JDFAutoFontPolicy.obj" \
	"$(INTDIR)\JDFAutoFormatConversionParams.obj" \
	"$(INTDIR)\JDFAutoGatheringParams.obj" \
	"$(INTDIR)\JDFAutoGlueApplication.obj" \
	"$(INTDIR)\JDFAutoGlueLine.obj" \
	"$(INTDIR)\JDFAutoGluingParams.obj" \
	"$(INTDIR)\JDFAutoHeadBandApplicationParams.obj" \
	"$(INTDIR)\JDFAutoHole.obj" \
	"$(INTDIR)\JDFAutoHoleLine.obj" \
	"$(INTDIR)\JDFAutoHoleMakingParams.obj" \
	"$(INTDIR)\JDFAutoIdentificationField.obj" \
	"$(INTDIR)\JDFAutoIDPrintingParams.obj" \
	"$(INTDIR)\JDFAutoImageCompressionParams.obj" \
	"$(INTDIR)\JDFAutoImageReplacementParams.obj" \
	"$(INTDIR)\JDFAutoImageSetterParams.obj" \
	"$(INTDIR)\JDFAutoInk.obj" \
	"$(INTDIR)\JDFAutoInkZoneCalculationParams.obj" \
	"$(INTDIR)\JDFAutoInkZoneProfile.obj" \
	"$(INTDIR)\JDFAutoInsertingParams.obj" \
	"$(INTDIR)\JDFAutoInsertSheet.obj" \
	"$(INTDIR)\JDFAutoInterpretedPDLData.obj" \
	"$(INTDIR)\JDFAutoInterpretingParams.obj" \
	"$(INTDIR)\JDFAutoJacketingParams.obj" \
	"$(INTDIR)\JDFAutoJobField.obj" \
	"$(INTDIR)\JDFAutoLabelingParams.obj" \
	"$(INTDIR)\JDFAutoLaminatingParams.obj" \
	"$(INTDIR)\JDFAutoLayout.obj" \
	"$(INTDIR)\JDFAutoLayoutElement.obj" \
	"$(INTDIR)\JDFAutoLayoutPreparationParams.obj" \
	"$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.obj" \
	"$(INTDIR)\JDFAutoManualLaborParams.obj" \
	"$(INTDIR)\JDFAutoMedia.obj" \
	"$(INTDIR)\JDFAutoMediaSource.obj" \
	"$(INTDIR)\JDFAutoMISDetails.obj" \
	"$(INTDIR)\JDFAutoNumberingParams.obj" \
	"$(INTDIR)\JDFAutoObjectResolution.obj" \
	"$(INTDIR)\JDFAutoOrderingParams.obj" \
	"$(INTDIR)\JDFAutoPackingParams.obj" \
	"$(INTDIR)\JDFAutoPageList.obj" \
	"$(INTDIR)\JDFAutoPallet.obj" \
	"$(INTDIR)\JDFAutoPalletizingParams.obj" \
	"$(INTDIR)\JDFAutoPDFToPSConversionParams.obj" \
	"$(INTDIR)\JDFAutoPDLResourceAlias.obj" \
	"$(INTDIR)\JDFAutoPerforatingParams.obj" \
	"$(INTDIR)\JDFAutoPerson.obj" \
	"$(INTDIR)\JDFAutoPlaceHolderResource.obj" \
	"$(INTDIR)\JDFAutoPlasticCombBindingParams.obj" \
	"$(INTDIR)\JDFAutoPlateCopyParams.obj" \
	"$(INTDIR)\JDFAutoPreflightAnalysis.obj" \
	"$(INTDIR)\JDFAutoPreflightInventory.obj" \
	"$(INTDIR)\JDFAutoPreflightParams.obj" \
	"$(INTDIR)\JDFAutoPreflightProfile.obj" \
	"$(INTDIR)\JDFAutoPreflightReport.obj" \
	"$(INTDIR)\JDFAutoPreflightReportRulePool.obj" \
	"$(INTDIR)\JDFAutoPreview.obj" \
	"$(INTDIR)\JDFAutoPreviewGenerationParams.obj" \
	"$(INTDIR)\JDFAutoPrintCondition.obj" \
	"$(INTDIR)\JDFAutoPrintRollingParams.obj" \
	"$(INTDIR)\JDFAutoProofingParams.obj" \
	"$(INTDIR)\JDFAutoPSToPDFConversionParams.obj" \
	"$(INTDIR)\JDFAutoQualityControlParams.obj" \
	"$(INTDIR)\JDFAutoQualityControlResult.obj" \
	"$(INTDIR)\JDFAutoRegisterMark.obj" \
	"$(INTDIR)\JDFAutoRegisterRibbon.obj" \
	"$(INTDIR)\JDFAutoRenderingParams.obj" \
	"$(INTDIR)\JDFAutoResourceDefinitionParams.obj" \
	"$(INTDIR)\JDFAutoRingBindingParams.obj" \
	"$(INTDIR)\JDFAutoRollStand.obj" \
	"$(INTDIR)\JDFAutoRunList.obj" \
	"$(INTDIR)\JDFAutoSaddleStitchingParams.obj" \
	"$(INTDIR)\JDFAutoScanParams.obj" \
	"$(INTDIR)\JDFAutoScavengerArea.obj" \
	"$(INTDIR)\JDFAutoScreeningParams.obj" \
	"$(INTDIR)\JDFAutoSeparationControlParams.obj" \
	"$(INTDIR)\JDFAutoSeparationSpec.obj" \
	"$(INTDIR)\JDFAutoShapeCuttingParams.obj" \
	"$(INTDIR)\JDFAutoSheet.obj" \
	"$(INTDIR)\JDFAutoShrinkingParams.obj" \
	"$(INTDIR)\JDFAutoSideSewingParams.obj" \
	"$(INTDIR)\JDFAutoSpinePreparationParams.obj" \
	"$(INTDIR)\JDFAutoSpineTapingParams.obj" \
	"$(INTDIR)\JDFAutoStackingParams.obj" \
	"$(INTDIR)\JDFAutoStitchingParams.obj" \
	"$(INTDIR)\JDFAutoStrap.obj" \
	"$(INTDIR)\JDFAutoStrappingParams.obj" \
	"$(INTDIR)\JDFAutoStripBindingParams.obj" \
	"$(INTDIR)\JDFAutoStrippingParams.obj" \
	"$(INTDIR)\JDFAutoSurface.obj" \
	"$(INTDIR)\JDFAutoThreadSealingParams.obj" \
	"$(INTDIR)\JDFAutoThreadSewingParams.obj" \
	"$(INTDIR)\JDFAutoTile.obj" \
	"$(INTDIR)\JDFAutoTool.obj" \
	"$(INTDIR)\JDFAutoTransferCurve.obj" \
	"$(INTDIR)\JDFAutoTransferCurvePool.obj" \
	"$(INTDIR)\JDFAutoTransferFunctionControl.obj" \
	"$(INTDIR)\JDFAutoTrappingDetails.obj" \
	"$(INTDIR)\JDFAutoTrappingParams.obj" \
	"$(INTDIR)\JDFAutoTrapRegion.obj" \
	"$(INTDIR)\JDFAutoTrimmingParams.obj" \
	"$(INTDIR)\JDFAutoVerificationParams.obj" \
	"$(INTDIR)\JDFAutoWireCombBindingParams.obj" \
	"$(INTDIR)\JDFAutoWrappingParams.obj" \
	"$(INTDIR)\JDFArgumentValue.obj" \
	"$(INTDIR)\JDFAutoAdvancedParams.obj" \
	"$(INTDIR)\JDFAutoApprovalPerson.obj" \
	"$(INTDIR)\JDFAutoArgumentValue.obj" \
	"$(INTDIR)\JDFAutoAssemblySection.obj" \
	"$(INTDIR)\JDFAutoBand.obj" \
	"$(INTDIR)\JDFAutoBasicPreflightTest.obj" \
	"$(INTDIR)\JDFAutoBindingQualityParams.obj" \
	"$(INTDIR)\JDFAutoBoxArgument.obj" \
	"$(INTDIR)\JDFAutoBoxToBoxDifference.obj" \
	"$(INTDIR)\JDFAutoBundleItem.obj" \
	"$(INTDIR)\JDFAutoCCITTFaxParams.obj" \
	"$(INTDIR)\JDFAutoCollatingItem.obj" \
	"$(INTDIR)\JDFAutoColorantZoneDetails.obj" \
	"$(INTDIR)\JDFAutoColorCorrectionOp.obj" \
	"$(INTDIR)\JDFAutoColorSpaceSubstitute.obj" \
	"$(INTDIR)\JDFAutoContainer.obj" \
	"$(INTDIR)\JDFAutoContentObject.obj" \
	"$(INTDIR)\JDFAutoCrease.obj" \
	"$(INTDIR)\JDFAutoCut.obj" \
	"$(INTDIR)\JDFAutoDCTParams.obj" \
	"$(INTDIR)\JDFAutoDependencies.obj" \
	"$(INTDIR)\JDFAutoDeviceNColor.obj" \
	"$(INTDIR)\JDFAutoDrop.obj" \
	"$(INTDIR)\JDFAutoDropItem.obj" \
	"$(INTDIR)\JDFAutoDynamicField.obj" \
	"$(INTDIR)\JDFAutoDynamicInput.obj" \
	"$(INTDIR)\JDFAutoEmboss.obj" \
	"$(INTDIR)\JDFAutoEndSheet.obj" \
	"$(INTDIR)\JDFAutoFeeder.obj" \
	"$(INTDIR)\JDFAutoFeederQualityParams.obj" \
	"$(INTDIR)\JDFAutoFileAlias.obj" \
	"$(INTDIR)\JDFAutoFlateParams.obj" \
	"$(INTDIR)\JDFAutoGlue.obj" \
	"$(INTDIR)\JDFAutoIcon.obj" \
	"$(INTDIR)\JDFAutoIconList.obj" \
	"$(INTDIR)\JDFAutoIDPCover.obj" \
	"$(INTDIR)\JDFAutoIDPFinishing.obj" \
	"$(INTDIR)\JDFAutoIDPFolding.obj" \
	"$(INTDIR)\JDFAutoIDPHoleMaking.obj" \
	"$(INTDIR)\JDFAutoIDPImageShift.obj" \
	"$(INTDIR)\JDFAutoIDPJobSheet.obj" \
	"$(INTDIR)\JDFAutoIDPLayout.obj" \
	"$(INTDIR)\JDFAutoIDPStitching.obj" \
	"$(INTDIR)\JDFAutoIDPTrimming.obj" \
	"$(INTDIR)\JDFAutoImageCompression.obj" \
	"$(INTDIR)\JDFAutoImageShift.obj" \
	"$(INTDIR)\JDFAutoLayerDetails.obj" \
	"$(INTDIR)\JDFAutoLayerList.obj" \
	"$(INTDIR)\JDFAutoLongFold.obj" \
	"$(INTDIR)\JDFAutoLongGlue.obj" \
	"$(INTDIR)\JDFAutoLongPerforate.obj" \
	"$(INTDIR)\JDFAutoLongSlit.obj" \
	"$(INTDIR)\JDFAutoLZWParams.obj" \
	"$(INTDIR)\JDFAutoMarkObject.obj" \
	"$(INTDIR)\JDFAutoNumberingParam.obj" \
	"$(INTDIR)\JDFAutoPageCell.obj" \
	"$(INTDIR)\JDFAutoPageData.obj" \
	"$(INTDIR)\JDFAutoPDFInterpretingParams.obj" \
	"$(INTDIR)\JDFAutoPDFXParams.obj" \
	"$(INTDIR)\JDFAutoPerforate.obj" \
	"$(INTDIR)\JDFAutoPixelColorant.obj" \
	"$(INTDIR)\JDFAutoPosition.obj" \
	"$(INTDIR)\JDFAutoPreflightAction.obj" \
	"$(INTDIR)\JDFAutoPreflightArgument.obj" \
	"$(INTDIR)\JDFAutoPreflightConstraint.obj" \
	"$(INTDIR)\JDFAutoPreflightDetail.obj" \
	"$(INTDIR)\JDFAutoPreflightInstance.obj" \
	"$(INTDIR)\JDFAutoPreflightInstanceDetail.obj" \
	"$(INTDIR)\JDFAutoPreflightValue.obj" \
	"$(INTDIR)\JDFAutoPRError.obj" \
	"$(INTDIR)\JDFAutoPRGroup.obj" \
	"$(INTDIR)\JDFAutoPrintConditionColor.obj" \
	"$(INTDIR)\JDFAutoPRItem.obj" \
	"$(INTDIR)\JDFAutoPROccurence.obj" \
	"$(INTDIR)\JDFAutoProperties.obj" \
	"$(INTDIR)\JDFAutoPRRule.obj" \
	"$(INTDIR)\JDFAutoPRRuleAttr.obj" \
	"$(INTDIR)\JDFAutoQualityMeasurement.obj" \
	"$(INTDIR)\JDFAutoResourceParam.obj" \
	"$(INTDIR)\JDFAutoScore.obj" \
	"$(INTDIR)\JDFAutoScreenSelector.obj" \
	"$(INTDIR)\JDFAutoShapeElement.obj" \
	"$(INTDIR)\JDFAutoSignature.obj" \
	"$(INTDIR)\JDFAutoSignatureCell.obj" \
	"$(INTDIR)\JDFAutoStringListValue.obj" \
	"$(INTDIR)\JDFAutoStripCellParams.obj" \
	"$(INTDIR)\JDFAutoThinPDFParams.obj" \
	"$(INTDIR)\JDFAutoTIFFEmbeddedFile.obj" \
	"$(INTDIR)\JDFAutoTIFFFormatParams.obj" \
	"$(INTDIR)\JDFAutoTIFFtag.obj" \
	"$(INTDIR)\JDFAutoTransferCurveSet.obj" \
	"$(INTDIR)\JDFAutoTrappingOrder.obj" \
	"$(INTDIR)\JDFAutoAction.obj" \
	"$(INTDIR)\JDFAutoActionPool.obj" \
	"$(INTDIR)\JDFAutoand.obj" \
	"$(INTDIR)\JDFAutocall.obj" \
	"$(INTDIR)\JDFAutochoice.obj" \
	"$(INTDIR)\JDFAutoDevCap.obj" \
	"$(INTDIR)\JDFAutoDevCaps.obj" \
	"$(INTDIR)\JDFAutoDeviceCap.obj" \
	"$(INTDIR)\JDFAutoDisplayGroup.obj" \
	"$(INTDIR)\JDFAutoDisplayGroupPool.obj" \
	"$(INTDIR)\JDFAutoFeatureAttribute.obj" \
	"$(INTDIR)\JDFAutoFeaturePool.obj" \
	"$(INTDIR)\JDFAutoLoc.obj" \
	"$(INTDIR)\JDFAutomacro.obj" \
	"$(INTDIR)\JDFAutoMacroPool.obj" \
	"$(INTDIR)\JDFAutonot.obj" \
	"$(INTDIR)\JDFAutoor.obj" \
	"$(INTDIR)\JDFAutootherwise.obj" \
	"$(INTDIR)\JDFAutoPerformance.obj" \
	"$(INTDIR)\JDFAutoset.obj" \
	"$(INTDIR)\JDFAutoTest.obj" \
	"$(INTDIR)\JDFAutoTestPool.obj" \
	"$(INTDIR)\JDFAutoTestRef.obj" \
	"$(INTDIR)\JDFAutoValue.obj" \
	"$(INTDIR)\JDFAutoValueLoc.obj" \
	"$(INTDIR)\JDFAutowhen.obj" \
	"$(INTDIR)\JDFAutoxor.obj" \
	"$(INTDIR)\JDFAutoEnumerationSpan.obj" \
	"$(INTDIR)\JDFAutoPRGroupOccurence.obj" \
	"$(INTDIR)\JDFAutoPRGroupOccurenceBase.obj" \
	"$(INTDIR)\JDFPreflightConstraintsPool.obj" \
	"$(INTDIR)\JDFPreflightResultsPool.obj" \
	"$(INTDIR)\JDFPRGroupOccurence.obj" \
	"$(INTDIR)\JDFPRGroupOccurenceBase.obj" \
	"$(INTDIR)\JDFDateTimeRange.obj" \
	"$(INTDIR)\JDFDateTimeRangeList.obj" \
	"$(INTDIR)\JDFDurationRange.obj" \
	"$(INTDIR)\JDFDurationRangeList.obj" \
	"$(INTDIR)\JDFIntegerRange.obj" \
	"$(INTDIR)\JDFIntegerRangeList.obj" \
	"$(INTDIR)\JDFNameRangeList.obj" \
	"$(INTDIR)\JDFNumberRangeList.obj" \
	"$(INTDIR)\JDFNumTypeList.obj" \
	"$(INTDIR)\JDFParser.obj" \
	"$(INTDIR)\JDFRange.obj" \
	"$(INTDIR)\JDFRangeList.obj" \
	"$(INTDIR)\JDFXYPairRangeList.obj" \
	"$(INTDIR)\KElement.obj" \
	"$(INTDIR)\KElementStrings.obj" \
	"$(INTDIR)\MyDate.obj" \
	"$(INTDIR)\vElement.obj" \
	"$(INTDIR)\XMLDoc.obj" \
	"$(INTDIR)\XMLDocUserData.obj" \
	"..\..\..\external\xerces\Build\Win32\VC6\Release\xerces-c_2.lib" \
	"$(OUTDIR)\JDFToolsDLL.lib"

"$(OUTDIR)\JDFWrapperDLL.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug DLL"

OUTDIR=.\..\..\..\Build\Win32\VC6\DebugDLL
INTDIR=.\..\..\..\Build\Win32\VC6\DebugDLL\obj\JDFWrapperDLL
# Begin Custom Macros
OutDir=.\..\..\..\Build\Win32\VC6\DebugDLL
# End Custom Macros

ALL : "$(OUTDIR)\JDFWrapperDLLd.dll" "$(OUTDIR)\JDFWrapperLib.bsc"


CLEAN :
	-@erase "$(INTDIR)\JDFAcknowledge.obj"
	-@erase "$(INTDIR)\JDFAcknowledge.sbr"
	-@erase "$(INTDIR)\JDFAction.obj"
	-@erase "$(INTDIR)\JDFAction.sbr"
	-@erase "$(INTDIR)\JDFActionPool.obj"
	-@erase "$(INTDIR)\JDFActionPool.sbr"
	-@erase "$(INTDIR)\JDFAdded.obj"
	-@erase "$(INTDIR)\JDFAdded.sbr"
	-@erase "$(INTDIR)\JDFAddress.obj"
	-@erase "$(INTDIR)\JDFAddress.sbr"
	-@erase "$(INTDIR)\JDFAdhesiveBinding.obj"
	-@erase "$(INTDIR)\JDFAdhesiveBinding.sbr"
	-@erase "$(INTDIR)\JDFAdhesiveBindingParams.obj"
	-@erase "$(INTDIR)\JDFAdhesiveBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAdvancedParams.obj"
	-@erase "$(INTDIR)\JDFAdvancedParams.sbr"
	-@erase "$(INTDIR)\JDFAmountPool.obj"
	-@erase "$(INTDIR)\JDFAmountPool.sbr"
	-@erase "$(INTDIR)\JDFAncestor.obj"
	-@erase "$(INTDIR)\JDFAncestor.sbr"
	-@erase "$(INTDIR)\JDFAncestorPool.obj"
	-@erase "$(INTDIR)\JDFAncestorPool.sbr"
	-@erase "$(INTDIR)\JDFand.obj"
	-@erase "$(INTDIR)\JDFand.sbr"
	-@erase "$(INTDIR)\JDFApprovalParams.obj"
	-@erase "$(INTDIR)\JDFApprovalParams.sbr"
	-@erase "$(INTDIR)\JDFApprovalPerson.obj"
	-@erase "$(INTDIR)\JDFApprovalPerson.sbr"
	-@erase "$(INTDIR)\JDFApprovalSuccess.obj"
	-@erase "$(INTDIR)\JDFApprovalSuccess.sbr"
	-@erase "$(INTDIR)\JDFArgumentValue.obj"
	-@erase "$(INTDIR)\JDFArgumentValue.sbr"
	-@erase "$(INTDIR)\JDFArtDelivery.obj"
	-@erase "$(INTDIR)\JDFArtDelivery.sbr"
	-@erase "$(INTDIR)\JDFArtDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFArtDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFAssembly.obj"
	-@erase "$(INTDIR)\JDFAssembly.sbr"
	-@erase "$(INTDIR)\JDFAssemblySection.obj"
	-@erase "$(INTDIR)\JDFAssemblySection.sbr"
	-@erase "$(INTDIR)\JDFAssetListCreationParams.obj"
	-@erase "$(INTDIR)\JDFAssetListCreationParams.sbr"
	-@erase "$(INTDIR)\JDFAudit.obj"
	-@erase "$(INTDIR)\JDFAudit.sbr"
	-@erase "$(INTDIR)\JDFAuditPool.obj"
	-@erase "$(INTDIR)\JDFAuditPool.sbr"
	-@erase "$(INTDIR)\JDFAutoAcknowledge.obj"
	-@erase "$(INTDIR)\JDFAutoAcknowledge.sbr"
	-@erase "$(INTDIR)\JDFAutoAction.obj"
	-@erase "$(INTDIR)\JDFAutoAction.sbr"
	-@erase "$(INTDIR)\JDFAutoActionPool.obj"
	-@erase "$(INTDIR)\JDFAutoActionPool.sbr"
	-@erase "$(INTDIR)\JDFAutoAdded.obj"
	-@erase "$(INTDIR)\JDFAutoAdded.sbr"
	-@erase "$(INTDIR)\JDFAutoAddress.obj"
	-@erase "$(INTDIR)\JDFAutoAddress.sbr"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBinding.obj"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoAdvancedParams.obj"
	-@erase "$(INTDIR)\JDFAutoAdvancedParams.sbr"
	-@erase "$(INTDIR)\JDFAutoAmountPool.obj"
	-@erase "$(INTDIR)\JDFAutoAmountPool.sbr"
	-@erase "$(INTDIR)\JDFAutoAncestor.obj"
	-@erase "$(INTDIR)\JDFAutoAncestor.sbr"
	-@erase "$(INTDIR)\JDFAutoAncestorPool.obj"
	-@erase "$(INTDIR)\JDFAutoAncestorPool.sbr"
	-@erase "$(INTDIR)\JDFAutoand.obj"
	-@erase "$(INTDIR)\JDFAutoand.sbr"
	-@erase "$(INTDIR)\JDFAutoApprovalParams.obj"
	-@erase "$(INTDIR)\JDFAutoApprovalParams.sbr"
	-@erase "$(INTDIR)\JDFAutoApprovalPerson.obj"
	-@erase "$(INTDIR)\JDFAutoApprovalPerson.sbr"
	-@erase "$(INTDIR)\JDFAutoApprovalSuccess.obj"
	-@erase "$(INTDIR)\JDFAutoApprovalSuccess.sbr"
	-@erase "$(INTDIR)\JDFAutoArgumentValue.obj"
	-@erase "$(INTDIR)\JDFAutoArgumentValue.sbr"
	-@erase "$(INTDIR)\JDFAutoArtDelivery.obj"
	-@erase "$(INTDIR)\JDFAutoArtDelivery.sbr"
	-@erase "$(INTDIR)\JDFAutoArtDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFAutoArtDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoAssembly.obj"
	-@erase "$(INTDIR)\JDFAutoAssembly.sbr"
	-@erase "$(INTDIR)\JDFAutoAssemblySection.obj"
	-@erase "$(INTDIR)\JDFAutoAssemblySection.sbr"
	-@erase "$(INTDIR)\JDFAutoAssetListCreationParams.obj"
	-@erase "$(INTDIR)\JDFAutoAssetListCreationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoAutomatedOverprintParams.obj"
	-@erase "$(INTDIR)\JDFAutoAutomatedOverprintParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBand.obj"
	-@erase "$(INTDIR)\JDFAutoBand.sbr"
	-@erase "$(INTDIR)\JDFAutoBarcode.obj"
	-@erase "$(INTDIR)\JDFAutoBarcode.sbr"
	-@erase "$(INTDIR)\JDFAutoBasicPreflightTest.obj"
	-@erase "$(INTDIR)\JDFAutoBasicPreflightTest.sbr"
	-@erase "$(INTDIR)\JDFAutoBinderySignature.obj"
	-@erase "$(INTDIR)\JDFAutoBinderySignature.sbr"
	-@erase "$(INTDIR)\JDFAutoBindingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoBindingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoBindingQualityParams.obj"
	-@erase "$(INTDIR)\JDFAutoBindingQualityParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBindItem.obj"
	-@erase "$(INTDIR)\JDFAutoBindItem.sbr"
	-@erase "$(INTDIR)\JDFAutoBindList.obj"
	-@erase "$(INTDIR)\JDFAutoBindList.sbr"
	-@erase "$(INTDIR)\JDFAutoBlockPreparationParams.obj"
	-@erase "$(INTDIR)\JDFAutoBlockPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBookCase.obj"
	-@erase "$(INTDIR)\JDFAutoBookCase.sbr"
	-@erase "$(INTDIR)\JDFAutoBoxArgument.obj"
	-@erase "$(INTDIR)\JDFAutoBoxArgument.sbr"
	-@erase "$(INTDIR)\JDFAutoBoxPackingParams.obj"
	-@erase "$(INTDIR)\JDFAutoBoxPackingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBoxToBoxDifference.obj"
	-@erase "$(INTDIR)\JDFAutoBoxToBoxDifference.sbr"
	-@erase "$(INTDIR)\JDFAutoBufferParams.obj"
	-@erase "$(INTDIR)\JDFAutoBufferParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBundle.obj"
	-@erase "$(INTDIR)\JDFAutoBundle.sbr"
	-@erase "$(INTDIR)\JDFAutoBundleItem.obj"
	-@erase "$(INTDIR)\JDFAutoBundleItem.sbr"
	-@erase "$(INTDIR)\JDFAutoBundlingParams.obj"
	-@erase "$(INTDIR)\JDFAutoBundlingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBusinessInfo.obj"
	-@erase "$(INTDIR)\JDFAutoBusinessInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoByteMap.obj"
	-@erase "$(INTDIR)\JDFAutoByteMap.sbr"
	-@erase "$(INTDIR)\JDFAutocall.obj"
	-@erase "$(INTDIR)\JDFAutocall.sbr"
	-@erase "$(INTDIR)\JDFAutoCaseMakingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCaseMakingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCasingInParams.obj"
	-@erase "$(INTDIR)\JDFAutoCasingInParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCCITTFaxParams.obj"
	-@erase "$(INTDIR)\JDFAutoCCITTFaxParams.sbr"
	-@erase "$(INTDIR)\JDFAutoChangedAttribute.obj"
	-@erase "$(INTDIR)\JDFAutoChangedAttribute.sbr"
	-@erase "$(INTDIR)\JDFAutoChangedPath.obj"
	-@erase "$(INTDIR)\JDFAutoChangedPath.sbr"
	-@erase "$(INTDIR)\JDFAutoChannelBinding.obj"
	-@erase "$(INTDIR)\JDFAutoChannelBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoChannelBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoChannelBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutochoice.obj"
	-@erase "$(INTDIR)\JDFAutochoice.sbr"
	-@erase "$(INTDIR)\JDFAutoCIELABMeasuringField.obj"
	-@erase "$(INTDIR)\JDFAutoCIELABMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFAutoCoilBinding.obj"
	-@erase "$(INTDIR)\JDFAutoCoilBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoCoilBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCoilBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCollatingItem.obj"
	-@erase "$(INTDIR)\JDFAutoCollatingItem.sbr"
	-@erase "$(INTDIR)\JDFAutoCollectingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCollectingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoColor.obj"
	-@erase "$(INTDIR)\JDFAutoColor.sbr"
	-@erase "$(INTDIR)\JDFAutoColorantAlias.obj"
	-@erase "$(INTDIR)\JDFAutoColorantAlias.sbr"
	-@erase "$(INTDIR)\JDFAutoColorantControl.obj"
	-@erase "$(INTDIR)\JDFAutoColorantControl.sbr"
	-@erase "$(INTDIR)\JDFAutoColorantZoneDetails.obj"
	-@erase "$(INTDIR)\JDFAutoColorantZoneDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoColorControlStrip.obj"
	-@erase "$(INTDIR)\JDFAutoColorControlStrip.sbr"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionOp.obj"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionOp.sbr"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionParams.obj"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoColorIntent.obj"
	-@erase "$(INTDIR)\JDFAutoColorIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoColorMeasurementConditions.obj"
	-@erase "$(INTDIR)\JDFAutoColorMeasurementConditions.sbr"
	-@erase "$(INTDIR)\JDFAutoColorPool.obj"
	-@erase "$(INTDIR)\JDFAutoColorPool.sbr"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionOp.obj"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionOp.sbr"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoColorSpaceSubstitute.obj"
	-@erase "$(INTDIR)\JDFAutoColorSpaceSubstitute.sbr"
	-@erase "$(INTDIR)\JDFAutoColorsUsed.obj"
	-@erase "$(INTDIR)\JDFAutoColorsUsed.sbr"
	-@erase "$(INTDIR)\JDFAutoComChannel.obj"
	-@erase "$(INTDIR)\JDFAutoComChannel.sbr"
	-@erase "$(INTDIR)\JDFAutoCommand.obj"
	-@erase "$(INTDIR)\JDFAutoCommand.sbr"
	-@erase "$(INTDIR)\JDFAutoComment.obj"
	-@erase "$(INTDIR)\JDFAutoComment.sbr"
	-@erase "$(INTDIR)\JDFAutoCompany.obj"
	-@erase "$(INTDIR)\JDFAutoCompany.sbr"
	-@erase "$(INTDIR)\JDFAutoComponent.obj"
	-@erase "$(INTDIR)\JDFAutoComponent.sbr"
	-@erase "$(INTDIR)\JDFAutoContact.obj"
	-@erase "$(INTDIR)\JDFAutoContact.sbr"
	-@erase "$(INTDIR)\JDFAutoContactCopyParams.obj"
	-@erase "$(INTDIR)\JDFAutoContactCopyParams.sbr"
	-@erase "$(INTDIR)\JDFAutoContainer.obj"
	-@erase "$(INTDIR)\JDFAutoContainer.sbr"
	-@erase "$(INTDIR)\JDFAutoContentObject.obj"
	-@erase "$(INTDIR)\JDFAutoContentObject.sbr"
	-@erase "$(INTDIR)\JDFAutoConventionalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFAutoConventionalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCostCenter.obj"
	-@erase "$(INTDIR)\JDFAutoCostCenter.sbr"
	-@erase "$(INTDIR)\JDFAutoCounterReset.obj"
	-@erase "$(INTDIR)\JDFAutoCounterReset.sbr"
	-@erase "$(INTDIR)\JDFAutoCoverApplicationParams.obj"
	-@erase "$(INTDIR)\JDFAutoCoverApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCrease.obj"
	-@erase "$(INTDIR)\JDFAutoCrease.sbr"
	-@erase "$(INTDIR)\JDFAutoCreasingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCreasingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCreated.obj"
	-@erase "$(INTDIR)\JDFAutoCreated.sbr"
	-@erase "$(INTDIR)\JDFAutoCreditCard.obj"
	-@erase "$(INTDIR)\JDFAutoCreditCard.sbr"
	-@erase "$(INTDIR)\JDFAutoCustomerInfo.obj"
	-@erase "$(INTDIR)\JDFAutoCustomerInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoCustomerMessage.obj"
	-@erase "$(INTDIR)\JDFAutoCustomerMessage.sbr"
	-@erase "$(INTDIR)\JDFAutoCut.obj"
	-@erase "$(INTDIR)\JDFAutoCut.sbr"
	-@erase "$(INTDIR)\JDFAutoCutBlock.obj"
	-@erase "$(INTDIR)\JDFAutoCutBlock.sbr"
	-@erase "$(INTDIR)\JDFAutoCutMark.obj"
	-@erase "$(INTDIR)\JDFAutoCutMark.sbr"
	-@erase "$(INTDIR)\JDFAutoCuttingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDBMergeParams.obj"
	-@erase "$(INTDIR)\JDFAutoDBMergeParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDBRules.obj"
	-@erase "$(INTDIR)\JDFAutoDBRules.sbr"
	-@erase "$(INTDIR)\JDFAutoDBSchema.obj"
	-@erase "$(INTDIR)\JDFAutoDBSchema.sbr"
	-@erase "$(INTDIR)\JDFAutoDBSelection.obj"
	-@erase "$(INTDIR)\JDFAutoDBSelection.sbr"
	-@erase "$(INTDIR)\JDFAutoDCTParams.obj"
	-@erase "$(INTDIR)\JDFAutoDCTParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDeleted.obj"
	-@erase "$(INTDIR)\JDFAutoDeleted.sbr"
	-@erase "$(INTDIR)\JDFAutoDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFAutoDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFAutoDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDensityMeasuringField.obj"
	-@erase "$(INTDIR)\JDFAutoDensityMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFAutoDependencies.obj"
	-@erase "$(INTDIR)\JDFAutoDependencies.sbr"
	-@erase "$(INTDIR)\JDFAutoDevCap.obj"
	-@erase "$(INTDIR)\JDFAutoDevCap.sbr"
	-@erase "$(INTDIR)\JDFAutoDevCaps.obj"
	-@erase "$(INTDIR)\JDFAutoDevCaps.sbr"
	-@erase "$(INTDIR)\JDFAutoDevelopingParams.obj"
	-@erase "$(INTDIR)\JDFAutoDevelopingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDevice.obj"
	-@erase "$(INTDIR)\JDFAutoDevice.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceCap.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceCap.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceFilter.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceInfo.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceList.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceList.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceMark.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceMark.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceNColor.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceNColor.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceNSpace.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceNSpace.sbr"
	-@erase "$(INTDIR)\JDFAutoDigitalDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFAutoDigitalDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDigitalMedia.obj"
	-@erase "$(INTDIR)\JDFAutoDigitalMedia.sbr"
	-@erase "$(INTDIR)\JDFAutoDigitalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFAutoDigitalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDisjointing.obj"
	-@erase "$(INTDIR)\JDFAutoDisjointing.sbr"
	-@erase "$(INTDIR)\JDFAutoDisplayGroup.obj"
	-@erase "$(INTDIR)\JDFAutoDisplayGroup.sbr"
	-@erase "$(INTDIR)\JDFAutoDisplayGroupPool.obj"
	-@erase "$(INTDIR)\JDFAutoDisplayGroupPool.sbr"
	-@erase "$(INTDIR)\JDFAutoDisposition.obj"
	-@erase "$(INTDIR)\JDFAutoDisposition.sbr"
	-@erase "$(INTDIR)\JDFAutoDividingParams.obj"
	-@erase "$(INTDIR)\JDFAutoDividingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDrop.obj"
	-@erase "$(INTDIR)\JDFAutoDrop.sbr"
	-@erase "$(INTDIR)\JDFAutoDropIntent.obj"
	-@erase "$(INTDIR)\JDFAutoDropIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoDropItem.obj"
	-@erase "$(INTDIR)\JDFAutoDropItem.sbr"
	-@erase "$(INTDIR)\JDFAutoDropItemIntent.obj"
	-@erase "$(INTDIR)\JDFAutoDropItemIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoDynamicField.obj"
	-@erase "$(INTDIR)\JDFAutoDynamicField.sbr"
	-@erase "$(INTDIR)\JDFAutoDynamicInput.obj"
	-@erase "$(INTDIR)\JDFAutoDynamicInput.sbr"
	-@erase "$(INTDIR)\JDFAutoEdgeGluing.obj"
	-@erase "$(INTDIR)\JDFAutoEdgeGluing.sbr"
	-@erase "$(INTDIR)\JDFAutoElementColorParams.obj"
	-@erase "$(INTDIR)\JDFAutoElementColorParams.sbr"
	-@erase "$(INTDIR)\JDFAutoEmboss.obj"
	-@erase "$(INTDIR)\JDFAutoEmboss.sbr"
	-@erase "$(INTDIR)\JDFAutoEmbossingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoEmbossingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoEmbossingItem.obj"
	-@erase "$(INTDIR)\JDFAutoEmbossingItem.sbr"
	-@erase "$(INTDIR)\JDFAutoEmbossingParams.obj"
	-@erase "$(INTDIR)\JDFAutoEmbossingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoEmployee.obj"
	-@erase "$(INTDIR)\JDFAutoEmployee.sbr"
	-@erase "$(INTDIR)\JDFAutoEmployeeDef.obj"
	-@erase "$(INTDIR)\JDFAutoEmployeeDef.sbr"
	-@erase "$(INTDIR)\JDFAutoEndSheet.obj"
	-@erase "$(INTDIR)\JDFAutoEndSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoEndSheetGluingParams.obj"
	-@erase "$(INTDIR)\JDFAutoEndSheetGluingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoEnumerationSpan.obj"
	-@erase "$(INTDIR)\JDFAutoEnumerationSpan.sbr"
	-@erase "$(INTDIR)\JDFAutoError.obj"
	-@erase "$(INTDIR)\JDFAutoError.sbr"
	-@erase "$(INTDIR)\JDFAutoEvent.obj"
	-@erase "$(INTDIR)\JDFAutoEvent.sbr"
	-@erase "$(INTDIR)\JDFAutoExposedMedia.obj"
	-@erase "$(INTDIR)\JDFAutoExposedMedia.sbr"
	-@erase "$(INTDIR)\JDFAutoFCNKey.obj"
	-@erase "$(INTDIR)\JDFAutoFCNKey.sbr"
	-@erase "$(INTDIR)\JDFAutoFeatureAttribute.obj"
	-@erase "$(INTDIR)\JDFAutoFeatureAttribute.sbr"
	-@erase "$(INTDIR)\JDFAutoFeaturePool.obj"
	-@erase "$(INTDIR)\JDFAutoFeaturePool.sbr"
	-@erase "$(INTDIR)\JDFAutoFeeder.obj"
	-@erase "$(INTDIR)\JDFAutoFeeder.sbr"
	-@erase "$(INTDIR)\JDFAutoFeederQualityParams.obj"
	-@erase "$(INTDIR)\JDFAutoFeederQualityParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFeedingParams.obj"
	-@erase "$(INTDIR)\JDFAutoFeedingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFileAlias.obj"
	-@erase "$(INTDIR)\JDFAutoFileAlias.sbr"
	-@erase "$(INTDIR)\JDFAutoFileSpec.obj"
	-@erase "$(INTDIR)\JDFAutoFileSpec.sbr"
	-@erase "$(INTDIR)\JDFAutoFitPolicy.obj"
	-@erase "$(INTDIR)\JDFAutoFitPolicy.sbr"
	-@erase "$(INTDIR)\JDFAutoFlateParams.obj"
	-@erase "$(INTDIR)\JDFAutoFlateParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFlushedResources.obj"
	-@erase "$(INTDIR)\JDFAutoFlushedResources.sbr"
	-@erase "$(INTDIR)\JDFAutoFlushQueueParams.obj"
	-@erase "$(INTDIR)\JDFAutoFlushQueueParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFlushResourceParams.obj"
	-@erase "$(INTDIR)\JDFAutoFlushResourceParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFold.obj"
	-@erase "$(INTDIR)\JDFAutoFold.sbr"
	-@erase "$(INTDIR)\JDFAutoFoldingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoFoldingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoFoldingParams.obj"
	-@erase "$(INTDIR)\JDFAutoFoldingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFontParams.obj"
	-@erase "$(INTDIR)\JDFAutoFontParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFontPolicy.obj"
	-@erase "$(INTDIR)\JDFAutoFontPolicy.sbr"
	-@erase "$(INTDIR)\JDFAutoFormatConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoFormatConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoGatheringParams.obj"
	-@erase "$(INTDIR)\JDFAutoGatheringParams.sbr"
	-@erase "$(INTDIR)\JDFAutoGlue.obj"
	-@erase "$(INTDIR)\JDFAutoGlue.sbr"
	-@erase "$(INTDIR)\JDFAutoGlueApplication.obj"
	-@erase "$(INTDIR)\JDFAutoGlueApplication.sbr"
	-@erase "$(INTDIR)\JDFAutoGlueLine.obj"
	-@erase "$(INTDIR)\JDFAutoGlueLine.sbr"
	-@erase "$(INTDIR)\JDFAutoGluingParams.obj"
	-@erase "$(INTDIR)\JDFAutoGluingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoHardCoverBinding.obj"
	-@erase "$(INTDIR)\JDFAutoHardCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoHeadBandApplicationParams.obj"
	-@erase "$(INTDIR)\JDFAutoHeadBandApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoHole.obj"
	-@erase "$(INTDIR)\JDFAutoHole.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleLine.obj"
	-@erase "$(INTDIR)\JDFAutoHoleLine.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleList.obj"
	-@erase "$(INTDIR)\JDFAutoHoleList.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleMakingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoHoleMakingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleMakingParams.obj"
	-@erase "$(INTDIR)\JDFAutoHoleMakingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoIcon.obj"
	-@erase "$(INTDIR)\JDFAutoIcon.sbr"
	-@erase "$(INTDIR)\JDFAutoIconList.obj"
	-@erase "$(INTDIR)\JDFAutoIconList.sbr"
	-@erase "$(INTDIR)\JDFAutoIdentificationField.obj"
	-@erase "$(INTDIR)\JDFAutoIdentificationField.sbr"
	-@erase "$(INTDIR)\JDFAutoIDInfo.obj"
	-@erase "$(INTDIR)\JDFAutoIDInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPCover.obj"
	-@erase "$(INTDIR)\JDFAutoIDPCover.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPFinishing.obj"
	-@erase "$(INTDIR)\JDFAutoIDPFinishing.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPFolding.obj"
	-@erase "$(INTDIR)\JDFAutoIDPFolding.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPHoleMaking.obj"
	-@erase "$(INTDIR)\JDFAutoIDPHoleMaking.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPImageShift.obj"
	-@erase "$(INTDIR)\JDFAutoIDPImageShift.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPJobSheet.obj"
	-@erase "$(INTDIR)\JDFAutoIDPJobSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPLayout.obj"
	-@erase "$(INTDIR)\JDFAutoIDPLayout.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPrintingParams.obj"
	-@erase "$(INTDIR)\JDFAutoIDPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPStitching.obj"
	-@erase "$(INTDIR)\JDFAutoIDPStitching.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPTrimming.obj"
	-@erase "$(INTDIR)\JDFAutoIDPTrimming.sbr"
	-@erase "$(INTDIR)\JDFAutoImageCompression.obj"
	-@erase "$(INTDIR)\JDFAutoImageCompression.sbr"
	-@erase "$(INTDIR)\JDFAutoImageCompressionParams.obj"
	-@erase "$(INTDIR)\JDFAutoImageCompressionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoImageReplacementParams.obj"
	-@erase "$(INTDIR)\JDFAutoImageReplacementParams.sbr"
	-@erase "$(INTDIR)\JDFAutoImageSetterParams.obj"
	-@erase "$(INTDIR)\JDFAutoImageSetterParams.sbr"
	-@erase "$(INTDIR)\JDFAutoImageShift.obj"
	-@erase "$(INTDIR)\JDFAutoImageShift.sbr"
	-@erase "$(INTDIR)\JDFAutoInk.obj"
	-@erase "$(INTDIR)\JDFAutoInk.sbr"
	-@erase "$(INTDIR)\JDFAutoInkZoneCalculationParams.obj"
	-@erase "$(INTDIR)\JDFAutoInkZoneCalculationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoInkZoneProfile.obj"
	-@erase "$(INTDIR)\JDFAutoInkZoneProfile.sbr"
	-@erase "$(INTDIR)\JDFAutoInsert.obj"
	-@erase "$(INTDIR)\JDFAutoInsert.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoInsertingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertingParams.obj"
	-@erase "$(INTDIR)\JDFAutoInsertingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertList.obj"
	-@erase "$(INTDIR)\JDFAutoInsertList.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertSheet.obj"
	-@erase "$(INTDIR)\JDFAutoInsertSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoInterpretedPDLData.obj"
	-@erase "$(INTDIR)\JDFAutoInterpretedPDLData.sbr"
	-@erase "$(INTDIR)\JDFAutoInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFAutoInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoJacketingParams.obj"
	-@erase "$(INTDIR)\JDFAutoJacketingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoJDFController.obj"
	-@erase "$(INTDIR)\JDFAutoJDFController.sbr"
	-@erase "$(INTDIR)\JDFAutoJDFService.obj"
	-@erase "$(INTDIR)\JDFAutoJDFService.sbr"
	-@erase "$(INTDIR)\JDFAutoJMF.obj"
	-@erase "$(INTDIR)\JDFAutoJMF.sbr"
	-@erase "$(INTDIR)\JDFAutoJobField.obj"
	-@erase "$(INTDIR)\JDFAutoJobField.sbr"
	-@erase "$(INTDIR)\JDFAutoJobPhase.obj"
	-@erase "$(INTDIR)\JDFAutoJobPhase.sbr"
	-@erase "$(INTDIR)\JDFAutoKnownMsgQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoKnownMsgQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLabelingParams.obj"
	-@erase "$(INTDIR)\JDFAutoLabelingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLaminatingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoLaminatingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoLaminatingParams.obj"
	-@erase "$(INTDIR)\JDFAutoLaminatingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLayerDetails.obj"
	-@erase "$(INTDIR)\JDFAutoLayerDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoLayerList.obj"
	-@erase "$(INTDIR)\JDFAutoLayerList.sbr"
	-@erase "$(INTDIR)\JDFAutoLayout.obj"
	-@erase "$(INTDIR)\JDFAutoLayout.sbr"
	-@erase "$(INTDIR)\JDFAutoLayoutElement.obj"
	-@erase "$(INTDIR)\JDFAutoLayoutElement.sbr"
	-@erase "$(INTDIR)\JDFAutoLayoutIntent.obj"
	-@erase "$(INTDIR)\JDFAutoLayoutIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoLayoutPreparationParams.obj"
	-@erase "$(INTDIR)\JDFAutoLayoutPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLoc.obj"
	-@erase "$(INTDIR)\JDFAutoLoc.sbr"
	-@erase "$(INTDIR)\JDFAutoLocation.obj"
	-@erase "$(INTDIR)\JDFAutoLocation.sbr"
	-@erase "$(INTDIR)\JDFAutoLongFold.obj"
	-@erase "$(INTDIR)\JDFAutoLongFold.sbr"
	-@erase "$(INTDIR)\JDFAutoLongGlue.obj"
	-@erase "$(INTDIR)\JDFAutoLongGlue.sbr"
	-@erase "$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.obj"
	-@erase "$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLongPerforate.obj"
	-@erase "$(INTDIR)\JDFAutoLongPerforate.sbr"
	-@erase "$(INTDIR)\JDFAutoLongSlit.obj"
	-@erase "$(INTDIR)\JDFAutoLongSlit.sbr"
	-@erase "$(INTDIR)\JDFAutoLZWParams.obj"
	-@erase "$(INTDIR)\JDFAutoLZWParams.sbr"
	-@erase "$(INTDIR)\JDFAutomacro.obj"
	-@erase "$(INTDIR)\JDFAutomacro.sbr"
	-@erase "$(INTDIR)\JDFAutoMacroPool.obj"
	-@erase "$(INTDIR)\JDFAutoMacroPool.sbr"
	-@erase "$(INTDIR)\JDFAutoManualLaborParams.obj"
	-@erase "$(INTDIR)\JDFAutoManualLaborParams.sbr"
	-@erase "$(INTDIR)\JDFAutoMarkObject.obj"
	-@erase "$(INTDIR)\JDFAutoMarkObject.sbr"
	-@erase "$(INTDIR)\JDFAutomatedOverprintParams.obj"
	-@erase "$(INTDIR)\JDFAutomatedOverprintParams.sbr"
	-@erase "$(INTDIR)\JDFAutoMedia.obj"
	-@erase "$(INTDIR)\JDFAutoMedia.sbr"
	-@erase "$(INTDIR)\JDFAutoMediaIntent.obj"
	-@erase "$(INTDIR)\JDFAutoMediaIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoMediaSource.obj"
	-@erase "$(INTDIR)\JDFAutoMediaSource.sbr"
	-@erase "$(INTDIR)\JDFAutoMerged.obj"
	-@erase "$(INTDIR)\JDFAutoMerged.sbr"
	-@erase "$(INTDIR)\JDFAutoMessage.obj"
	-@erase "$(INTDIR)\JDFAutoMessage.sbr"
	-@erase "$(INTDIR)\JDFAutoMessageService.obj"
	-@erase "$(INTDIR)\JDFAutoMessageService.sbr"
	-@erase "$(INTDIR)\JDFAutoMISDetails.obj"
	-@erase "$(INTDIR)\JDFAutoMISDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoModified.obj"
	-@erase "$(INTDIR)\JDFAutoModified.sbr"
	-@erase "$(INTDIR)\JDFAutoModulePhase.obj"
	-@erase "$(INTDIR)\JDFAutoModulePhase.sbr"
	-@erase "$(INTDIR)\JDFAutoModuleStatus.obj"
	-@erase "$(INTDIR)\JDFAutoModuleStatus.sbr"
	-@erase "$(INTDIR)\JDFAutoMsgFilter.obj"
	-@erase "$(INTDIR)\JDFAutoMsgFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoNewJDFCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoNewJDFCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNewJDFQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoNewJDFQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfo.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfoCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfoCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfoQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfoQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfoResp.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfoResp.sbr"
	-@erase "$(INTDIR)\JDFAutonot.obj"
	-@erase "$(INTDIR)\JDFAutonot.sbr"
	-@erase "$(INTDIR)\JDFAutoNotification.obj"
	-@erase "$(INTDIR)\JDFAutoNotification.sbr"
	-@erase "$(INTDIR)\JDFAutoNotificationDef.obj"
	-@erase "$(INTDIR)\JDFAutoNotificationDef.sbr"
	-@erase "$(INTDIR)\JDFAutoNotificationFilter.obj"
	-@erase "$(INTDIR)\JDFAutoNotificationFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoNumberingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberingParam.obj"
	-@erase "$(INTDIR)\JDFAutoNumberingParam.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberingParams.obj"
	-@erase "$(INTDIR)\JDFAutoNumberingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberItem.obj"
	-@erase "$(INTDIR)\JDFAutoNumberItem.sbr"
	-@erase "$(INTDIR)\JDFAutoObjectResolution.obj"
	-@erase "$(INTDIR)\JDFAutoObjectResolution.sbr"
	-@erase "$(INTDIR)\JDFAutoObservationTarget.obj"
	-@erase "$(INTDIR)\JDFAutoObservationTarget.sbr"
	-@erase "$(INTDIR)\JDFAutoOccupation.obj"
	-@erase "$(INTDIR)\JDFAutoOccupation.sbr"
	-@erase "$(INTDIR)\JDFAutoor.obj"
	-@erase "$(INTDIR)\JDFAutoor.sbr"
	-@erase "$(INTDIR)\JDFAutoOrderingParams.obj"
	-@erase "$(INTDIR)\JDFAutoOrderingParams.sbr"
	-@erase "$(INTDIR)\JDFAutootherwise.obj"
	-@erase "$(INTDIR)\JDFAutootherwise.sbr"
	-@erase "$(INTDIR)\JDFAutoPackingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoPackingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoPackingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPackingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPageCell.obj"
	-@erase "$(INTDIR)\JDFAutoPageCell.sbr"
	-@erase "$(INTDIR)\JDFAutoPageData.obj"
	-@erase "$(INTDIR)\JDFAutoPageData.sbr"
	-@erase "$(INTDIR)\JDFAutoPageList.obj"
	-@erase "$(INTDIR)\JDFAutoPageList.sbr"
	-@erase "$(INTDIR)\JDFAutoPallet.obj"
	-@erase "$(INTDIR)\JDFAutoPallet.sbr"
	-@erase "$(INTDIR)\JDFAutoPalletizingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPalletizingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPart.obj"
	-@erase "$(INTDIR)\JDFAutoPart.sbr"
	-@erase "$(INTDIR)\JDFAutoPartStatus.obj"
	-@erase "$(INTDIR)\JDFAutoPartStatus.sbr"
	-@erase "$(INTDIR)\JDFAutoPayment.obj"
	-@erase "$(INTDIR)\JDFAutoPayment.sbr"
	-@erase "$(INTDIR)\JDFAutoPDFInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPDFInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPDFToPSConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoPDFToPSConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPDFXParams.obj"
	-@erase "$(INTDIR)\JDFAutoPDFXParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPDLResourceAlias.obj"
	-@erase "$(INTDIR)\JDFAutoPDLResourceAlias.sbr"
	-@erase "$(INTDIR)\JDFAutoPerforate.obj"
	-@erase "$(INTDIR)\JDFAutoPerforate.sbr"
	-@erase "$(INTDIR)\JDFAutoPerforatingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPerforatingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPerformance.obj"
	-@erase "$(INTDIR)\JDFAutoPerformance.sbr"
	-@erase "$(INTDIR)\JDFAutoPerson.obj"
	-@erase "$(INTDIR)\JDFAutoPerson.sbr"
	-@erase "$(INTDIR)\JDFAutoPhaseTime.obj"
	-@erase "$(INTDIR)\JDFAutoPhaseTime.sbr"
	-@erase "$(INTDIR)\JDFAutoPipeParams.obj"
	-@erase "$(INTDIR)\JDFAutoPipeParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPixelColorant.obj"
	-@erase "$(INTDIR)\JDFAutoPixelColorant.sbr"
	-@erase "$(INTDIR)\JDFAutoPlaceHolderResource.obj"
	-@erase "$(INTDIR)\JDFAutoPlaceHolderResource.sbr"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBinding.obj"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPlateCopyParams.obj"
	-@erase "$(INTDIR)\JDFAutoPlateCopyParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPosition.obj"
	-@erase "$(INTDIR)\JDFAutoPosition.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightAction.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightAction.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightAnalysis.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightAnalysis.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightArgument.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightArgument.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightConstraint.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightConstraint.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightDetail.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightDetail.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightInstance.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightInstance.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightInstanceDetail.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightInstanceDetail.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightInventory.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightInventory.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightParams.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightProfile.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightProfile.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightReport.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightReport.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightReportRulePool.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightReportRulePool.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightValue.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightValue.sbr"
	-@erase "$(INTDIR)\JDFAutoPRError.obj"
	-@erase "$(INTDIR)\JDFAutoPRError.sbr"
	-@erase "$(INTDIR)\JDFAutoPreview.obj"
	-@erase "$(INTDIR)\JDFAutoPreview.sbr"
	-@erase "$(INTDIR)\JDFAutoPreviewGenerationParams.obj"
	-@erase "$(INTDIR)\JDFAutoPreviewGenerationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPRGroup.obj"
	-@erase "$(INTDIR)\JDFAutoPRGroup.sbr"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurence.obj"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurence.sbr"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurenceBase.obj"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurenceBase.sbr"
	-@erase "$(INTDIR)\JDFAutoPricing.obj"
	-@erase "$(INTDIR)\JDFAutoPricing.sbr"
	-@erase "$(INTDIR)\JDFAutoPrintCondition.obj"
	-@erase "$(INTDIR)\JDFAutoPrintCondition.sbr"
	-@erase "$(INTDIR)\JDFAutoPrintConditionColor.obj"
	-@erase "$(INTDIR)\JDFAutoPrintConditionColor.sbr"
	-@erase "$(INTDIR)\JDFAutoPrintRollingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPrintRollingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPRItem.obj"
	-@erase "$(INTDIR)\JDFAutoPRItem.sbr"
	-@erase "$(INTDIR)\JDFAutoPROccurence.obj"
	-@erase "$(INTDIR)\JDFAutoPROccurence.sbr"
	-@erase "$(INTDIR)\JDFAutoProcessRun.obj"
	-@erase "$(INTDIR)\JDFAutoProcessRun.sbr"
	-@erase "$(INTDIR)\JDFAutoProductionIntent.obj"
	-@erase "$(INTDIR)\JDFAutoProductionIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoProofingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoProofingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoProofingParams.obj"
	-@erase "$(INTDIR)\JDFAutoProofingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoProofItem.obj"
	-@erase "$(INTDIR)\JDFAutoProofItem.sbr"
	-@erase "$(INTDIR)\JDFAutoProperties.obj"
	-@erase "$(INTDIR)\JDFAutoProperties.sbr"
	-@erase "$(INTDIR)\JDFAutoPRRule.obj"
	-@erase "$(INTDIR)\JDFAutoPRRule.sbr"
	-@erase "$(INTDIR)\JDFAutoPRRuleAttr.obj"
	-@erase "$(INTDIR)\JDFAutoPRRuleAttr.sbr"
	-@erase "$(INTDIR)\JDFAutoPSToPDFConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoPSToPDFConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQualityControlParams.obj"
	-@erase "$(INTDIR)\JDFAutoQualityControlParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQualityControlResult.obj"
	-@erase "$(INTDIR)\JDFAutoQualityControlResult.sbr"
	-@erase "$(INTDIR)\JDFAutoQualityMeasurement.obj"
	-@erase "$(INTDIR)\JDFAutoQualityMeasurement.sbr"
	-@erase "$(INTDIR)\JDFAutoQuery.obj"
	-@erase "$(INTDIR)\JDFAutoQuery.sbr"
	-@erase "$(INTDIR)\JDFAutoQueue.obj"
	-@erase "$(INTDIR)\JDFAutoQueue.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntry.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntry.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDef.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDef.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDefList.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDefList.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPosParams.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPosParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPriParams.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPriParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueFilter.obj"
	-@erase "$(INTDIR)\JDFAutoQueueFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueSubmissionParams.obj"
	-@erase "$(INTDIR)\JDFAutoQueueSubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRegisterMark.obj"
	-@erase "$(INTDIR)\JDFAutoRegisterMark.sbr"
	-@erase "$(INTDIR)\JDFAutoRegisterRibbon.obj"
	-@erase "$(INTDIR)\JDFAutoRegisterRibbon.sbr"
	-@erase "$(INTDIR)\JDFAutoRemoved.obj"
	-@erase "$(INTDIR)\JDFAutoRemoved.sbr"
	-@erase "$(INTDIR)\JDFAutoRenderingParams.obj"
	-@erase "$(INTDIR)\JDFAutoRenderingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRequestQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFAutoRequestQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceAudit.obj"
	-@erase "$(INTDIR)\JDFAutoResourceAudit.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourceCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceDefinitionParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourceDefinitionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceInfo.obj"
	-@erase "$(INTDIR)\JDFAutoResourceInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceParam.obj"
	-@erase "$(INTDIR)\JDFAutoResourceParam.sbr"
	-@erase "$(INTDIR)\JDFAutoResourcePullParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourcePullParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourceQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResponse.obj"
	-@erase "$(INTDIR)\JDFAutoResponse.sbr"
	-@erase "$(INTDIR)\JDFAutoResubmissionParams.obj"
	-@erase "$(INTDIR)\JDFAutoResubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoReturnQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFAutoReturnQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRingBinding.obj"
	-@erase "$(INTDIR)\JDFAutoRingBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoRingBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoRingBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRollStand.obj"
	-@erase "$(INTDIR)\JDFAutoRollStand.sbr"
	-@erase "$(INTDIR)\JDFAutoRunList.obj"
	-@erase "$(INTDIR)\JDFAutoRunList.sbr"
	-@erase "$(INTDIR)\JDFAutoSaddleStitching.obj"
	-@erase "$(INTDIR)\JDFAutoSaddleStitching.sbr"
	-@erase "$(INTDIR)\JDFAutoSaddleStitchingParams.obj"
	-@erase "$(INTDIR)\JDFAutoSaddleStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoScanParams.obj"
	-@erase "$(INTDIR)\JDFAutoScanParams.sbr"
	-@erase "$(INTDIR)\JDFAutoScavengerArea.obj"
	-@erase "$(INTDIR)\JDFAutoScavengerArea.sbr"
	-@erase "$(INTDIR)\JDFAutoScore.obj"
	-@erase "$(INTDIR)\JDFAutoScore.sbr"
	-@erase "$(INTDIR)\JDFAutoScreeningIntent.obj"
	-@erase "$(INTDIR)\JDFAutoScreeningIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoScreeningParams.obj"
	-@erase "$(INTDIR)\JDFAutoScreeningParams.sbr"
	-@erase "$(INTDIR)\JDFAutoScreenSelector.obj"
	-@erase "$(INTDIR)\JDFAutoScreenSelector.sbr"
	-@erase "$(INTDIR)\JDFAutoSeparationControlParams.obj"
	-@erase "$(INTDIR)\JDFAutoSeparationControlParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSeparationSpec.obj"
	-@erase "$(INTDIR)\JDFAutoSeparationSpec.sbr"
	-@erase "$(INTDIR)\JDFAutoset.obj"
	-@erase "$(INTDIR)\JDFAutoset.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeCut.obj"
	-@erase "$(INTDIR)\JDFAutoShapeCut.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingParams.obj"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeElement.obj"
	-@erase "$(INTDIR)\JDFAutoShapeElement.sbr"
	-@erase "$(INTDIR)\JDFAutoSheet.obj"
	-@erase "$(INTDIR)\JDFAutoSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoShrinkingParams.obj"
	-@erase "$(INTDIR)\JDFAutoShrinkingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoShutDownCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoShutDownCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSideSewing.obj"
	-@erase "$(INTDIR)\JDFAutoSideSewing.sbr"
	-@erase "$(INTDIR)\JDFAutoSideSewingParams.obj"
	-@erase "$(INTDIR)\JDFAutoSideSewingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSideStitching.obj"
	-@erase "$(INTDIR)\JDFAutoSideStitching.sbr"
	-@erase "$(INTDIR)\JDFAutoSignal.obj"
	-@erase "$(INTDIR)\JDFAutoSignal.sbr"
	-@erase "$(INTDIR)\JDFAutoSignature.obj"
	-@erase "$(INTDIR)\JDFAutoSignature.sbr"
	-@erase "$(INTDIR)\JDFAutoSignatureCell.obj"
	-@erase "$(INTDIR)\JDFAutoSignatureCell.sbr"
	-@erase "$(INTDIR)\JDFAutoSizeIntent.obj"
	-@erase "$(INTDIR)\JDFAutoSizeIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoSoftCoverBinding.obj"
	-@erase "$(INTDIR)\JDFAutoSoftCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoSpawned.obj"
	-@erase "$(INTDIR)\JDFAutoSpawned.sbr"
	-@erase "$(INTDIR)\JDFAutoSpinePreparationParams.obj"
	-@erase "$(INTDIR)\JDFAutoSpinePreparationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSpineTapingParams.obj"
	-@erase "$(INTDIR)\JDFAutoSpineTapingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStackingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStackingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStatusPool.obj"
	-@erase "$(INTDIR)\JDFAutoStatusPool.sbr"
	-@erase "$(INTDIR)\JDFAutoStatusQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoStatusQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStitchingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStopPersChParams.obj"
	-@erase "$(INTDIR)\JDFAutoStopPersChParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStrap.obj"
	-@erase "$(INTDIR)\JDFAutoStrap.sbr"
	-@erase "$(INTDIR)\JDFAutoStrappingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStrappingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStringListValue.obj"
	-@erase "$(INTDIR)\JDFAutoStringListValue.sbr"
	-@erase "$(INTDIR)\JDFAutoStripBinding.obj"
	-@erase "$(INTDIR)\JDFAutoStripBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoStripBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStripBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStripCellParams.obj"
	-@erase "$(INTDIR)\JDFAutoStripCellParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStrippingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStrippingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSubmissionMethods.obj"
	-@erase "$(INTDIR)\JDFAutoSubmissionMethods.sbr"
	-@erase "$(INTDIR)\JDFAutoSubscription.obj"
	-@erase "$(INTDIR)\JDFAutoSubscription.sbr"
	-@erase "$(INTDIR)\JDFAutoSurface.obj"
	-@erase "$(INTDIR)\JDFAutoSurface.sbr"
	-@erase "$(INTDIR)\JDFAutoSystemTimeSet.obj"
	-@erase "$(INTDIR)\JDFAutoSystemTimeSet.sbr"
	-@erase "$(INTDIR)\JDFAutoTabs.obj"
	-@erase "$(INTDIR)\JDFAutoTabs.sbr"
	-@erase "$(INTDIR)\JDFAutoTape.obj"
	-@erase "$(INTDIR)\JDFAutoTape.sbr"
	-@erase "$(INTDIR)\JDFAutoTest.obj"
	-@erase "$(INTDIR)\JDFAutoTest.sbr"
	-@erase "$(INTDIR)\JDFAutoTestPool.obj"
	-@erase "$(INTDIR)\JDFAutoTestPool.sbr"
	-@erase "$(INTDIR)\JDFAutoTestRef.obj"
	-@erase "$(INTDIR)\JDFAutoTestRef.sbr"
	-@erase "$(INTDIR)\JDFAutoThinPDFParams.obj"
	-@erase "$(INTDIR)\JDFAutoThinPDFParams.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSealing.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSealing.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSealingParams.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSealingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSewing.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSewing.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSewingParams.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSewingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoTIFFEmbeddedFile.obj"
	-@erase "$(INTDIR)\JDFAutoTIFFEmbeddedFile.sbr"
	-@erase "$(INTDIR)\JDFAutoTIFFFormatParams.obj"
	-@erase "$(INTDIR)\JDFAutoTIFFFormatParams.sbr"
	-@erase "$(INTDIR)\JDFAutoTIFFtag.obj"
	-@erase "$(INTDIR)\JDFAutoTIFFtag.sbr"
	-@erase "$(INTDIR)\JDFAutoTile.obj"
	-@erase "$(INTDIR)\JDFAutoTile.sbr"
	-@erase "$(INTDIR)\JDFAutoTool.obj"
	-@erase "$(INTDIR)\JDFAutoTool.sbr"
	-@erase "$(INTDIR)\JDFAutoTrackFilter.obj"
	-@erase "$(INTDIR)\JDFAutoTrackFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoTrackResult.obj"
	-@erase "$(INTDIR)\JDFAutoTrackResult.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferCurve.obj"
	-@erase "$(INTDIR)\JDFAutoTransferCurve.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferCurvePool.obj"
	-@erase "$(INTDIR)\JDFAutoTransferCurvePool.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferCurveSet.obj"
	-@erase "$(INTDIR)\JDFAutoTransferCurveSet.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferFunctionControl.obj"
	-@erase "$(INTDIR)\JDFAutoTransferFunctionControl.sbr"
	-@erase "$(INTDIR)\JDFAutoTrappingDetails.obj"
	-@erase "$(INTDIR)\JDFAutoTrappingDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoTrappingOrder.obj"
	-@erase "$(INTDIR)\JDFAutoTrappingOrder.sbr"
	-@erase "$(INTDIR)\JDFAutoTrappingParams.obj"
	-@erase "$(INTDIR)\JDFAutoTrappingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoTrapRegion.obj"
	-@erase "$(INTDIR)\JDFAutoTrapRegion.sbr"
	-@erase "$(INTDIR)\JDFAutoTrigger.obj"
	-@erase "$(INTDIR)\JDFAutoTrigger.sbr"
	-@erase "$(INTDIR)\JDFAutoTrimmingParams.obj"
	-@erase "$(INTDIR)\JDFAutoTrimmingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoValue.obj"
	-@erase "$(INTDIR)\JDFAutoValue.sbr"
	-@erase "$(INTDIR)\JDFAutoValueLoc.obj"
	-@erase "$(INTDIR)\JDFAutoValueLoc.sbr"
	-@erase "$(INTDIR)\JDFAutoVerificationParams.obj"
	-@erase "$(INTDIR)\JDFAutoVerificationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoWakeUpCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoWakeUpCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutowhen.obj"
	-@erase "$(INTDIR)\JDFAutowhen.sbr"
	-@erase "$(INTDIR)\JDFAutoWireCombBinding.obj"
	-@erase "$(INTDIR)\JDFAutoWireCombBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoWireCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoWireCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoWrappingParams.obj"
	-@erase "$(INTDIR)\JDFAutoWrappingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoxor.obj"
	-@erase "$(INTDIR)\JDFAutoxor.sbr"
	-@erase "$(INTDIR)\JDFBand.obj"
	-@erase "$(INTDIR)\JDFBand.sbr"
	-@erase "$(INTDIR)\JDFBarcode.obj"
	-@erase "$(INTDIR)\JDFBarcode.sbr"
	-@erase "$(INTDIR)\JDFBasicPreflightTest.obj"
	-@erase "$(INTDIR)\JDFBasicPreflightTest.sbr"
	-@erase "$(INTDIR)\JDFBinderySignature.obj"
	-@erase "$(INTDIR)\JDFBinderySignature.sbr"
	-@erase "$(INTDIR)\JDFBindingIntent.obj"
	-@erase "$(INTDIR)\JDFBindingIntent.sbr"
	-@erase "$(INTDIR)\JDFBindingQualityParams.obj"
	-@erase "$(INTDIR)\JDFBindingQualityParams.sbr"
	-@erase "$(INTDIR)\JDFBindItem.obj"
	-@erase "$(INTDIR)\JDFBindItem.sbr"
	-@erase "$(INTDIR)\JDFBindList.obj"
	-@erase "$(INTDIR)\JDFBindList.sbr"
	-@erase "$(INTDIR)\JDFBlockPreparationParams.obj"
	-@erase "$(INTDIR)\JDFBlockPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFBookCase.obj"
	-@erase "$(INTDIR)\JDFBookCase.sbr"
	-@erase "$(INTDIR)\JDFBooleanEvaluation.obj"
	-@erase "$(INTDIR)\JDFBooleanEvaluation.sbr"
	-@erase "$(INTDIR)\JDFBooleanState.obj"
	-@erase "$(INTDIR)\JDFBooleanState.sbr"
	-@erase "$(INTDIR)\JDFBoxArgument.obj"
	-@erase "$(INTDIR)\JDFBoxArgument.sbr"
	-@erase "$(INTDIR)\JDFBoxPackingParams.obj"
	-@erase "$(INTDIR)\JDFBoxPackingParams.sbr"
	-@erase "$(INTDIR)\JDFBoxToBoxDifference.obj"
	-@erase "$(INTDIR)\JDFBoxToBoxDifference.sbr"
	-@erase "$(INTDIR)\JDFBufferParams.obj"
	-@erase "$(INTDIR)\JDFBufferParams.sbr"
	-@erase "$(INTDIR)\JDFBundle.obj"
	-@erase "$(INTDIR)\JDFBundle.sbr"
	-@erase "$(INTDIR)\JDFBundleItem.obj"
	-@erase "$(INTDIR)\JDFBundleItem.sbr"
	-@erase "$(INTDIR)\JDFBundlingParams.obj"
	-@erase "$(INTDIR)\JDFBundlingParams.sbr"
	-@erase "$(INTDIR)\JDFBusinessInfo.obj"
	-@erase "$(INTDIR)\JDFBusinessInfo.sbr"
	-@erase "$(INTDIR)\JDFByteMap.obj"
	-@erase "$(INTDIR)\JDFByteMap.sbr"
	-@erase "$(INTDIR)\JDFcall.obj"
	-@erase "$(INTDIR)\JDFcall.sbr"
	-@erase "$(INTDIR)\JDFCaseMakingParams.obj"
	-@erase "$(INTDIR)\JDFCaseMakingParams.sbr"
	-@erase "$(INTDIR)\JDFCasingInParams.obj"
	-@erase "$(INTDIR)\JDFCasingInParams.sbr"
	-@erase "$(INTDIR)\JDFCCITTFaxParams.obj"
	-@erase "$(INTDIR)\JDFCCITTFaxParams.sbr"
	-@erase "$(INTDIR)\JDFChangedAttribute.obj"
	-@erase "$(INTDIR)\JDFChangedAttribute.sbr"
	-@erase "$(INTDIR)\JDFChangedPath.obj"
	-@erase "$(INTDIR)\JDFChangedPath.sbr"
	-@erase "$(INTDIR)\JDFChannelBinding.obj"
	-@erase "$(INTDIR)\JDFChannelBinding.sbr"
	-@erase "$(INTDIR)\JDFChannelBindingParams.obj"
	-@erase "$(INTDIR)\JDFChannelBindingParams.sbr"
	-@erase "$(INTDIR)\JDFchoice.obj"
	-@erase "$(INTDIR)\JDFchoice.sbr"
	-@erase "$(INTDIR)\JDFCIELABMeasuringField.obj"
	-@erase "$(INTDIR)\JDFCIELABMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFCoilBinding.obj"
	-@erase "$(INTDIR)\JDFCoilBinding.sbr"
	-@erase "$(INTDIR)\JDFCoilBindingParams.obj"
	-@erase "$(INTDIR)\JDFCoilBindingParams.sbr"
	-@erase "$(INTDIR)\JDFCollatingItem.obj"
	-@erase "$(INTDIR)\JDFCollatingItem.sbr"
	-@erase "$(INTDIR)\JDFCollectingParams.obj"
	-@erase "$(INTDIR)\JDFCollectingParams.sbr"
	-@erase "$(INTDIR)\JDFColor.obj"
	-@erase "$(INTDIR)\JDFColor.sbr"
	-@erase "$(INTDIR)\JDFColorantAlias.obj"
	-@erase "$(INTDIR)\JDFColorantAlias.sbr"
	-@erase "$(INTDIR)\JDFColorantControl.obj"
	-@erase "$(INTDIR)\JDFColorantControl.sbr"
	-@erase "$(INTDIR)\JDFColorantZoneDetails.obj"
	-@erase "$(INTDIR)\JDFColorantZoneDetails.sbr"
	-@erase "$(INTDIR)\JDFColorControlStrip.obj"
	-@erase "$(INTDIR)\JDFColorControlStrip.sbr"
	-@erase "$(INTDIR)\JDFColorCorrectionOp.obj"
	-@erase "$(INTDIR)\JDFColorCorrectionOp.sbr"
	-@erase "$(INTDIR)\JDFColorCorrectionParams.obj"
	-@erase "$(INTDIR)\JDFColorCorrectionParams.sbr"
	-@erase "$(INTDIR)\JDFColorIntent.obj"
	-@erase "$(INTDIR)\JDFColorIntent.sbr"
	-@erase "$(INTDIR)\JDFColorMeasurementConditions.obj"
	-@erase "$(INTDIR)\JDFColorMeasurementConditions.sbr"
	-@erase "$(INTDIR)\JDFColorPool.obj"
	-@erase "$(INTDIR)\JDFColorPool.sbr"
	-@erase "$(INTDIR)\JDFColorSpaceConversionOp.obj"
	-@erase "$(INTDIR)\JDFColorSpaceConversionOp.sbr"
	-@erase "$(INTDIR)\JDFColorSpaceConversionParams.obj"
	-@erase "$(INTDIR)\JDFColorSpaceConversionParams.sbr"
	-@erase "$(INTDIR)\JDFColorSpaceSubstitute.obj"
	-@erase "$(INTDIR)\JDFColorSpaceSubstitute.sbr"
	-@erase "$(INTDIR)\JDFColorsUsed.obj"
	-@erase "$(INTDIR)\JDFColorsUsed.sbr"
	-@erase "$(INTDIR)\JDFComChannel.obj"
	-@erase "$(INTDIR)\JDFComChannel.sbr"
	-@erase "$(INTDIR)\JDFCommand.obj"
	-@erase "$(INTDIR)\JDFCommand.sbr"
	-@erase "$(INTDIR)\JDFComment.obj"
	-@erase "$(INTDIR)\JDFComment.sbr"
	-@erase "$(INTDIR)\JDFCompany.obj"
	-@erase "$(INTDIR)\JDFCompany.sbr"
	-@erase "$(INTDIR)\JDFComponent.obj"
	-@erase "$(INTDIR)\JDFComponent.sbr"
	-@erase "$(INTDIR)\JDFContact.obj"
	-@erase "$(INTDIR)\JDFContact.sbr"
	-@erase "$(INTDIR)\JDFContactCopyParams.obj"
	-@erase "$(INTDIR)\JDFContactCopyParams.sbr"
	-@erase "$(INTDIR)\JDFContainer.obj"
	-@erase "$(INTDIR)\JDFContainer.sbr"
	-@erase "$(INTDIR)\JDFContentObject.obj"
	-@erase "$(INTDIR)\JDFContentObject.sbr"
	-@erase "$(INTDIR)\JDFConventionalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFConventionalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFCostCenter.obj"
	-@erase "$(INTDIR)\JDFCostCenter.sbr"
	-@erase "$(INTDIR)\JDFCounterReset.obj"
	-@erase "$(INTDIR)\JDFCounterReset.sbr"
	-@erase "$(INTDIR)\JDFCoverApplicationParams.obj"
	-@erase "$(INTDIR)\JDFCoverApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFCrease.obj"
	-@erase "$(INTDIR)\JDFCrease.sbr"
	-@erase "$(INTDIR)\JDFCreasingParams.obj"
	-@erase "$(INTDIR)\JDFCreasingParams.sbr"
	-@erase "$(INTDIR)\JDFCreated.obj"
	-@erase "$(INTDIR)\JDFCreated.sbr"
	-@erase "$(INTDIR)\JDFCreditCard.obj"
	-@erase "$(INTDIR)\JDFCreditCard.sbr"
	-@erase "$(INTDIR)\JDFCustomerInfo.obj"
	-@erase "$(INTDIR)\JDFCustomerInfo.sbr"
	-@erase "$(INTDIR)\JDFCustomerMessage.obj"
	-@erase "$(INTDIR)\JDFCustomerMessage.sbr"
	-@erase "$(INTDIR)\JDFCut.obj"
	-@erase "$(INTDIR)\JDFCut.sbr"
	-@erase "$(INTDIR)\JDFCutBlock.obj"
	-@erase "$(INTDIR)\JDFCutBlock.sbr"
	-@erase "$(INTDIR)\JDFCutMark.obj"
	-@erase "$(INTDIR)\JDFCutMark.sbr"
	-@erase "$(INTDIR)\JDFCuttingParams.obj"
	-@erase "$(INTDIR)\JDFCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFDateTimeEvaluation.obj"
	-@erase "$(INTDIR)\JDFDateTimeEvaluation.sbr"
	-@erase "$(INTDIR)\JDFDateTimeRange.obj"
	-@erase "$(INTDIR)\JDFDateTimeRange.sbr"
	-@erase "$(INTDIR)\JDFDateTimeRangeList.obj"
	-@erase "$(INTDIR)\JDFDateTimeRangeList.sbr"
	-@erase "$(INTDIR)\JDFDateTimeState.obj"
	-@erase "$(INTDIR)\JDFDateTimeState.sbr"
	-@erase "$(INTDIR)\JDFDBMergeParams.obj"
	-@erase "$(INTDIR)\JDFDBMergeParams.sbr"
	-@erase "$(INTDIR)\JDFDBRules.obj"
	-@erase "$(INTDIR)\JDFDBRules.sbr"
	-@erase "$(INTDIR)\JDFDBSchema.obj"
	-@erase "$(INTDIR)\JDFDBSchema.sbr"
	-@erase "$(INTDIR)\JDFDBSelection.obj"
	-@erase "$(INTDIR)\JDFDBSelection.sbr"
	-@erase "$(INTDIR)\JDFDCTParams.obj"
	-@erase "$(INTDIR)\JDFDCTParams.sbr"
	-@erase "$(INTDIR)\JDFDeleted.obj"
	-@erase "$(INTDIR)\JDFDeleted.sbr"
	-@erase "$(INTDIR)\JDFDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFDensityMeasuringField.obj"
	-@erase "$(INTDIR)\JDFDensityMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFDependencies.obj"
	-@erase "$(INTDIR)\JDFDependencies.sbr"
	-@erase "$(INTDIR)\JDFDevCap.obj"
	-@erase "$(INTDIR)\JDFDevCap.sbr"
	-@erase "$(INTDIR)\JDFDevCaps.obj"
	-@erase "$(INTDIR)\JDFDevCaps.sbr"
	-@erase "$(INTDIR)\JDFDevelopingParams.obj"
	-@erase "$(INTDIR)\JDFDevelopingParams.sbr"
	-@erase "$(INTDIR)\JDFDevice.obj"
	-@erase "$(INTDIR)\JDFDevice.sbr"
	-@erase "$(INTDIR)\JDFDeviceCap.obj"
	-@erase "$(INTDIR)\JDFDeviceCap.sbr"
	-@erase "$(INTDIR)\JDFDeviceFilter.obj"
	-@erase "$(INTDIR)\JDFDeviceFilter.sbr"
	-@erase "$(INTDIR)\JDFDeviceInfo.obj"
	-@erase "$(INTDIR)\JDFDeviceInfo.sbr"
	-@erase "$(INTDIR)\JDFDeviceList.obj"
	-@erase "$(INTDIR)\JDFDeviceList.sbr"
	-@erase "$(INTDIR)\JDFDeviceMark.obj"
	-@erase "$(INTDIR)\JDFDeviceMark.sbr"
	-@erase "$(INTDIR)\JDFDeviceNColor.obj"
	-@erase "$(INTDIR)\JDFDeviceNColor.sbr"
	-@erase "$(INTDIR)\JDFDeviceNSpace.obj"
	-@erase "$(INTDIR)\JDFDeviceNSpace.sbr"
	-@erase "$(INTDIR)\JDFDigitalDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFDigitalDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFDigitalMedia.obj"
	-@erase "$(INTDIR)\JDFDigitalMedia.sbr"
	-@erase "$(INTDIR)\JDFDigitalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFDigitalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFDisjointing.obj"
	-@erase "$(INTDIR)\JDFDisjointing.sbr"
	-@erase "$(INTDIR)\JDFDisplayGroup.obj"
	-@erase "$(INTDIR)\JDFDisplayGroup.sbr"
	-@erase "$(INTDIR)\JDFDisplayGroupPool.obj"
	-@erase "$(INTDIR)\JDFDisplayGroupPool.sbr"
	-@erase "$(INTDIR)\JDFDisposition.obj"
	-@erase "$(INTDIR)\JDFDisposition.sbr"
	-@erase "$(INTDIR)\JDFDividingParams.obj"
	-@erase "$(INTDIR)\JDFDividingParams.sbr"
	-@erase "$(INTDIR)\JDFDoc.obj"
	-@erase "$(INTDIR)\JDFDoc.sbr"
	-@erase "$(INTDIR)\JDFDrop.obj"
	-@erase "$(INTDIR)\JDFDrop.sbr"
	-@erase "$(INTDIR)\JDFDropIntent.obj"
	-@erase "$(INTDIR)\JDFDropIntent.sbr"
	-@erase "$(INTDIR)\JDFDropItem.obj"
	-@erase "$(INTDIR)\JDFDropItem.sbr"
	-@erase "$(INTDIR)\JDFDropItemIntent.obj"
	-@erase "$(INTDIR)\JDFDropItemIntent.sbr"
	-@erase "$(INTDIR)\JDFDurationEvaluation.obj"
	-@erase "$(INTDIR)\JDFDurationEvaluation.sbr"
	-@erase "$(INTDIR)\JDFDurationRange.obj"
	-@erase "$(INTDIR)\JDFDurationRange.sbr"
	-@erase "$(INTDIR)\JDFDurationRangeList.obj"
	-@erase "$(INTDIR)\JDFDurationRangeList.sbr"
	-@erase "$(INTDIR)\JDFDurationState.obj"
	-@erase "$(INTDIR)\JDFDurationState.sbr"
	-@erase "$(INTDIR)\JDFDynamicField.obj"
	-@erase "$(INTDIR)\JDFDynamicField.sbr"
	-@erase "$(INTDIR)\JDFDynamicInput.obj"
	-@erase "$(INTDIR)\JDFDynamicInput.sbr"
	-@erase "$(INTDIR)\JDFEdgeGluing.obj"
	-@erase "$(INTDIR)\JDFEdgeGluing.sbr"
	-@erase "$(INTDIR)\JDFElement.obj"
	-@erase "$(INTDIR)\JDFElement.sbr"
	-@erase "$(INTDIR)\JDFElementColorParams.obj"
	-@erase "$(INTDIR)\JDFElementColorParams.sbr"
	-@erase "$(INTDIR)\JDFEmboss.obj"
	-@erase "$(INTDIR)\JDFEmboss.sbr"
	-@erase "$(INTDIR)\JDFEmbossingIntent.obj"
	-@erase "$(INTDIR)\JDFEmbossingIntent.sbr"
	-@erase "$(INTDIR)\JDFEmbossingItem.obj"
	-@erase "$(INTDIR)\JDFEmbossingItem.sbr"
	-@erase "$(INTDIR)\JDFEmbossingParams.obj"
	-@erase "$(INTDIR)\JDFEmbossingParams.sbr"
	-@erase "$(INTDIR)\JDFEmployee.obj"
	-@erase "$(INTDIR)\JDFEmployee.sbr"
	-@erase "$(INTDIR)\JDFEmployeeDef.obj"
	-@erase "$(INTDIR)\JDFEmployeeDef.sbr"
	-@erase "$(INTDIR)\JDFEndSheet.obj"
	-@erase "$(INTDIR)\JDFEndSheet.sbr"
	-@erase "$(INTDIR)\JDFEndSheetGluingParams.obj"
	-@erase "$(INTDIR)\JDFEndSheetGluingParams.sbr"
	-@erase "$(INTDIR)\JDFEnumerationEvaluation.obj"
	-@erase "$(INTDIR)\JDFEnumerationEvaluation.sbr"
	-@erase "$(INTDIR)\JDFEnumerationState.obj"
	-@erase "$(INTDIR)\JDFEnumerationState.sbr"
	-@erase "$(INTDIR)\JDFError.obj"
	-@erase "$(INTDIR)\JDFError.sbr"
	-@erase "$(INTDIR)\JDFEvaluation.obj"
	-@erase "$(INTDIR)\JDFEvaluation.sbr"
	-@erase "$(INTDIR)\JDFEvent.obj"
	-@erase "$(INTDIR)\JDFEvent.sbr"
	-@erase "$(INTDIR)\JDFExposedMedia.obj"
	-@erase "$(INTDIR)\JDFExposedMedia.sbr"
	-@erase "$(INTDIR)\JDFFactory.obj"
	-@erase "$(INTDIR)\JDFFactory.sbr"
	-@erase "$(INTDIR)\JDFFCNKey.obj"
	-@erase "$(INTDIR)\JDFFCNKey.sbr"
	-@erase "$(INTDIR)\JDFFeatureAttribute.obj"
	-@erase "$(INTDIR)\JDFFeatureAttribute.sbr"
	-@erase "$(INTDIR)\JDFFeaturePool.obj"
	-@erase "$(INTDIR)\JDFFeaturePool.sbr"
	-@erase "$(INTDIR)\JDFFeeder.obj"
	-@erase "$(INTDIR)\JDFFeeder.sbr"
	-@erase "$(INTDIR)\JDFFeederQualityParams.obj"
	-@erase "$(INTDIR)\JDFFeederQualityParams.sbr"
	-@erase "$(INTDIR)\JDFFeedingParams.obj"
	-@erase "$(INTDIR)\JDFFeedingParams.sbr"
	-@erase "$(INTDIR)\JDFFileAlias.obj"
	-@erase "$(INTDIR)\JDFFileAlias.sbr"
	-@erase "$(INTDIR)\JDFFileSpec.obj"
	-@erase "$(INTDIR)\JDFFileSpec.sbr"
	-@erase "$(INTDIR)\JDFFitPolicy.obj"
	-@erase "$(INTDIR)\JDFFitPolicy.sbr"
	-@erase "$(INTDIR)\JDFFlateParams.obj"
	-@erase "$(INTDIR)\JDFFlateParams.sbr"
	-@erase "$(INTDIR)\JDFFlushedResources.obj"
	-@erase "$(INTDIR)\JDFFlushedResources.sbr"
	-@erase "$(INTDIR)\JDFFlushQueueParams.obj"
	-@erase "$(INTDIR)\JDFFlushQueueParams.sbr"
	-@erase "$(INTDIR)\JDFFlushResourceParams.obj"
	-@erase "$(INTDIR)\JDFFlushResourceParams.sbr"
	-@erase "$(INTDIR)\JDFFold.obj"
	-@erase "$(INTDIR)\JDFFold.sbr"
	-@erase "$(INTDIR)\JDFFoldingIntent.obj"
	-@erase "$(INTDIR)\JDFFoldingIntent.sbr"
	-@erase "$(INTDIR)\JDFFoldingParams.obj"
	-@erase "$(INTDIR)\JDFFoldingParams.sbr"
	-@erase "$(INTDIR)\JDFFontParams.obj"
	-@erase "$(INTDIR)\JDFFontParams.sbr"
	-@erase "$(INTDIR)\JDFFontPolicy.obj"
	-@erase "$(INTDIR)\JDFFontPolicy.sbr"
	-@erase "$(INTDIR)\JDFFormatConversionParams.obj"
	-@erase "$(INTDIR)\JDFFormatConversionParams.sbr"
	-@erase "$(INTDIR)\JDFGatheringParams.obj"
	-@erase "$(INTDIR)\JDFGatheringParams.sbr"
	-@erase "$(INTDIR)\JDFGlue.obj"
	-@erase "$(INTDIR)\JDFGlue.sbr"
	-@erase "$(INTDIR)\JDFGlueApplication.obj"
	-@erase "$(INTDIR)\JDFGlueApplication.sbr"
	-@erase "$(INTDIR)\JDFGlueLine.obj"
	-@erase "$(INTDIR)\JDFGlueLine.sbr"
	-@erase "$(INTDIR)\JDFGluingParams.obj"
	-@erase "$(INTDIR)\JDFGluingParams.sbr"
	-@erase "$(INTDIR)\JDFHardCoverBinding.obj"
	-@erase "$(INTDIR)\JDFHardCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFHeadBandApplicationParams.obj"
	-@erase "$(INTDIR)\JDFHeadBandApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFHole.obj"
	-@erase "$(INTDIR)\JDFHole.sbr"
	-@erase "$(INTDIR)\JDFHoleLine.obj"
	-@erase "$(INTDIR)\JDFHoleLine.sbr"
	-@erase "$(INTDIR)\JDFHoleList.obj"
	-@erase "$(INTDIR)\JDFHoleList.sbr"
	-@erase "$(INTDIR)\JDFHoleMakingIntent.obj"
	-@erase "$(INTDIR)\JDFHoleMakingIntent.sbr"
	-@erase "$(INTDIR)\JDFHoleMakingParams.obj"
	-@erase "$(INTDIR)\JDFHoleMakingParams.sbr"
	-@erase "$(INTDIR)\JDFIcon.obj"
	-@erase "$(INTDIR)\JDFIcon.sbr"
	-@erase "$(INTDIR)\JDFIconList.obj"
	-@erase "$(INTDIR)\JDFIconList.sbr"
	-@erase "$(INTDIR)\JDFIdentificationField.obj"
	-@erase "$(INTDIR)\JDFIdentificationField.sbr"
	-@erase "$(INTDIR)\JDFIDInfo.obj"
	-@erase "$(INTDIR)\JDFIDInfo.sbr"
	-@erase "$(INTDIR)\JDFIDPCover.obj"
	-@erase "$(INTDIR)\JDFIDPCover.sbr"
	-@erase "$(INTDIR)\JDFIDPFinishing.obj"
	-@erase "$(INTDIR)\JDFIDPFinishing.sbr"
	-@erase "$(INTDIR)\JDFIDPFolding.obj"
	-@erase "$(INTDIR)\JDFIDPFolding.sbr"
	-@erase "$(INTDIR)\JDFIDPHoleMaking.obj"
	-@erase "$(INTDIR)\JDFIDPHoleMaking.sbr"
	-@erase "$(INTDIR)\JDFIDPImageShift.obj"
	-@erase "$(INTDIR)\JDFIDPImageShift.sbr"
	-@erase "$(INTDIR)\JDFIDPJobSheet.obj"
	-@erase "$(INTDIR)\JDFIDPJobSheet.sbr"
	-@erase "$(INTDIR)\JDFIDPLayout.obj"
	-@erase "$(INTDIR)\JDFIDPLayout.sbr"
	-@erase "$(INTDIR)\JDFIDPrintingParams.obj"
	-@erase "$(INTDIR)\JDFIDPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFIDPStitching.obj"
	-@erase "$(INTDIR)\JDFIDPStitching.sbr"
	-@erase "$(INTDIR)\JDFIDPTrimming.obj"
	-@erase "$(INTDIR)\JDFIDPTrimming.sbr"
	-@erase "$(INTDIR)\JDFImageCompression.obj"
	-@erase "$(INTDIR)\JDFImageCompression.sbr"
	-@erase "$(INTDIR)\JDFImageCompressionParams.obj"
	-@erase "$(INTDIR)\JDFImageCompressionParams.sbr"
	-@erase "$(INTDIR)\JDFImageReplacementParams.obj"
	-@erase "$(INTDIR)\JDFImageReplacementParams.sbr"
	-@erase "$(INTDIR)\JDFImageSetterParams.obj"
	-@erase "$(INTDIR)\JDFImageSetterParams.sbr"
	-@erase "$(INTDIR)\JDFImageShift.obj"
	-@erase "$(INTDIR)\JDFImageShift.sbr"
	-@erase "$(INTDIR)\JDFInk.obj"
	-@erase "$(INTDIR)\JDFInk.sbr"
	-@erase "$(INTDIR)\JDFInkZoneCalculationParams.obj"
	-@erase "$(INTDIR)\JDFInkZoneCalculationParams.sbr"
	-@erase "$(INTDIR)\JDFInkZoneProfile.obj"
	-@erase "$(INTDIR)\JDFInkZoneProfile.sbr"
	-@erase "$(INTDIR)\JDFInsert.obj"
	-@erase "$(INTDIR)\JDFInsert.sbr"
	-@erase "$(INTDIR)\JDFInsertingIntent.obj"
	-@erase "$(INTDIR)\JDFInsertingIntent.sbr"
	-@erase "$(INTDIR)\JDFInsertingParams.obj"
	-@erase "$(INTDIR)\JDFInsertingParams.sbr"
	-@erase "$(INTDIR)\JDFInsertList.obj"
	-@erase "$(INTDIR)\JDFInsertList.sbr"
	-@erase "$(INTDIR)\JDFInsertSheet.obj"
	-@erase "$(INTDIR)\JDFInsertSheet.sbr"
	-@erase "$(INTDIR)\JDFIntegerEvaluation.obj"
	-@erase "$(INTDIR)\JDFIntegerEvaluation.sbr"
	-@erase "$(INTDIR)\JDFIntegerRange.obj"
	-@erase "$(INTDIR)\JDFIntegerRange.sbr"
	-@erase "$(INTDIR)\JDFIntegerRangeList.obj"
	-@erase "$(INTDIR)\JDFIntegerRangeList.sbr"
	-@erase "$(INTDIR)\JDFIntegerState.obj"
	-@erase "$(INTDIR)\JDFIntegerState.sbr"
	-@erase "$(INTDIR)\JDFIntentResource.obj"
	-@erase "$(INTDIR)\JDFIntentResource.sbr"
	-@erase "$(INTDIR)\JDFInterpretedPDLData.obj"
	-@erase "$(INTDIR)\JDFInterpretedPDLData.sbr"
	-@erase "$(INTDIR)\JDFInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFIsPresentEvaluation.obj"
	-@erase "$(INTDIR)\JDFIsPresentEvaluation.sbr"
	-@erase "$(INTDIR)\JDFJacketingParams.obj"
	-@erase "$(INTDIR)\JDFJacketingParams.sbr"
	-@erase "$(INTDIR)\JDFJDFController.obj"
	-@erase "$(INTDIR)\JDFJDFController.sbr"
	-@erase "$(INTDIR)\JDFJDFService.obj"
	-@erase "$(INTDIR)\JDFJDFService.sbr"
	-@erase "$(INTDIR)\JDFJMF.obj"
	-@erase "$(INTDIR)\JDFJMF.sbr"
	-@erase "$(INTDIR)\JDFJobField.obj"
	-@erase "$(INTDIR)\JDFJobField.sbr"
	-@erase "$(INTDIR)\JDFJobPhase.obj"
	-@erase "$(INTDIR)\JDFJobPhase.sbr"
	-@erase "$(INTDIR)\JDFKnownMsgQuParams.obj"
	-@erase "$(INTDIR)\JDFKnownMsgQuParams.sbr"
	-@erase "$(INTDIR)\JDFLabelingParams.obj"
	-@erase "$(INTDIR)\JDFLabelingParams.sbr"
	-@erase "$(INTDIR)\JDFLaminatingIntent.obj"
	-@erase "$(INTDIR)\JDFLaminatingIntent.sbr"
	-@erase "$(INTDIR)\JDFLaminatingParams.obj"
	-@erase "$(INTDIR)\JDFLaminatingParams.sbr"
	-@erase "$(INTDIR)\JDFLayerDetails.obj"
	-@erase "$(INTDIR)\JDFLayerDetails.sbr"
	-@erase "$(INTDIR)\JDFLayerList.obj"
	-@erase "$(INTDIR)\JDFLayerList.sbr"
	-@erase "$(INTDIR)\JDFLayout.obj"
	-@erase "$(INTDIR)\JDFLayout.sbr"
	-@erase "$(INTDIR)\JDFLayoutElement.obj"
	-@erase "$(INTDIR)\JDFLayoutElement.sbr"
	-@erase "$(INTDIR)\JDFLayoutIntent.obj"
	-@erase "$(INTDIR)\JDFLayoutIntent.sbr"
	-@erase "$(INTDIR)\JDFLayoutPreparationParams.obj"
	-@erase "$(INTDIR)\JDFLayoutPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFLoc.obj"
	-@erase "$(INTDIR)\JDFLoc.sbr"
	-@erase "$(INTDIR)\JDFLocation.obj"
	-@erase "$(INTDIR)\JDFLocation.sbr"
	-@erase "$(INTDIR)\JDFLongFold.obj"
	-@erase "$(INTDIR)\JDFLongFold.sbr"
	-@erase "$(INTDIR)\JDFLongGlue.obj"
	-@erase "$(INTDIR)\JDFLongGlue.sbr"
	-@erase "$(INTDIR)\JDFLongitudinalRibbonOperationParams.obj"
	-@erase "$(INTDIR)\JDFLongitudinalRibbonOperationParams.sbr"
	-@erase "$(INTDIR)\JDFLongPerforate.obj"
	-@erase "$(INTDIR)\JDFLongPerforate.sbr"
	-@erase "$(INTDIR)\JDFLongSlit.obj"
	-@erase "$(INTDIR)\JDFLongSlit.sbr"
	-@erase "$(INTDIR)\JDFLZWParams.obj"
	-@erase "$(INTDIR)\JDFLZWParams.sbr"
	-@erase "$(INTDIR)\JDFmacro.obj"
	-@erase "$(INTDIR)\JDFmacro.sbr"
	-@erase "$(INTDIR)\JDFMacroPool.obj"
	-@erase "$(INTDIR)\JDFMacroPool.sbr"
	-@erase "$(INTDIR)\JDFManualLaborParams.obj"
	-@erase "$(INTDIR)\JDFManualLaborParams.sbr"
	-@erase "$(INTDIR)\JDFMarkObject.obj"
	-@erase "$(INTDIR)\JDFMarkObject.sbr"
	-@erase "$(INTDIR)\JDFMatrixEvaluation.obj"
	-@erase "$(INTDIR)\JDFMatrixEvaluation.sbr"
	-@erase "$(INTDIR)\JDFMatrixState.obj"
	-@erase "$(INTDIR)\JDFMatrixState.sbr"
	-@erase "$(INTDIR)\JDFMedia.obj"
	-@erase "$(INTDIR)\JDFMedia.sbr"
	-@erase "$(INTDIR)\JDFMediaIntent.obj"
	-@erase "$(INTDIR)\JDFMediaIntent.sbr"
	-@erase "$(INTDIR)\JDFMediaSource.obj"
	-@erase "$(INTDIR)\JDFMediaSource.sbr"
	-@erase "$(INTDIR)\JDFMerged.obj"
	-@erase "$(INTDIR)\JDFMerged.sbr"
	-@erase "$(INTDIR)\JDFMessage.obj"
	-@erase "$(INTDIR)\JDFMessage.sbr"
	-@erase "$(INTDIR)\JDFMessageElement.obj"
	-@erase "$(INTDIR)\JDFMessageElement.sbr"
	-@erase "$(INTDIR)\JDFMessageService.obj"
	-@erase "$(INTDIR)\JDFMessageService.sbr"
	-@erase "$(INTDIR)\JDFMISDetails.obj"
	-@erase "$(INTDIR)\JDFMISDetails.sbr"
	-@erase "$(INTDIR)\JDFModified.obj"
	-@erase "$(INTDIR)\JDFModified.sbr"
	-@erase "$(INTDIR)\JDFModulePhase.obj"
	-@erase "$(INTDIR)\JDFModulePhase.sbr"
	-@erase "$(INTDIR)\JDFModuleStatus.obj"
	-@erase "$(INTDIR)\JDFModuleStatus.sbr"
	-@erase "$(INTDIR)\JDFMsgFilter.obj"
	-@erase "$(INTDIR)\JDFMsgFilter.sbr"
	-@erase "$(INTDIR)\JDFNameEvaluation.obj"
	-@erase "$(INTDIR)\JDFNameEvaluation.sbr"
	-@erase "$(INTDIR)\JDFNameRangeList.obj"
	-@erase "$(INTDIR)\JDFNameRangeList.sbr"
	-@erase "$(INTDIR)\JDFNameState.obj"
	-@erase "$(INTDIR)\JDFNameState.sbr"
	-@erase "$(INTDIR)\JDFNewJDFCmdParams.obj"
	-@erase "$(INTDIR)\JDFNewJDFCmdParams.sbr"
	-@erase "$(INTDIR)\JDFNewJDFQuParams.obj"
	-@erase "$(INTDIR)\JDFNewJDFQuParams.sbr"
	-@erase "$(INTDIR)\JDFNode.obj"
	-@erase "$(INTDIR)\JDFNode.sbr"
	-@erase "$(INTDIR)\JDFNodeFactory.obj"
	-@erase "$(INTDIR)\JDFNodeFactory.sbr"
	-@erase "$(INTDIR)\JDFNodeInfo.obj"
	-@erase "$(INTDIR)\JDFNodeInfo.sbr"
	-@erase "$(INTDIR)\JDFNodeInfoCmdParams.obj"
	-@erase "$(INTDIR)\JDFNodeInfoCmdParams.sbr"
	-@erase "$(INTDIR)\JDFNodeInfoQuParams.obj"
	-@erase "$(INTDIR)\JDFNodeInfoQuParams.sbr"
	-@erase "$(INTDIR)\JDFNodeInfoResp.obj"
	-@erase "$(INTDIR)\JDFNodeInfoResp.sbr"
	-@erase "$(INTDIR)\JDFnot.obj"
	-@erase "$(INTDIR)\JDFnot.sbr"
	-@erase "$(INTDIR)\JDFNotification.obj"
	-@erase "$(INTDIR)\JDFNotification.sbr"
	-@erase "$(INTDIR)\JDFNotificationDef.obj"
	-@erase "$(INTDIR)\JDFNotificationDef.sbr"
	-@erase "$(INTDIR)\JDFNotificationFilter.obj"
	-@erase "$(INTDIR)\JDFNotificationFilter.sbr"
	-@erase "$(INTDIR)\JDFNumberEvaluation.obj"
	-@erase "$(INTDIR)\JDFNumberEvaluation.sbr"
	-@erase "$(INTDIR)\JDFNumberingIntent.obj"
	-@erase "$(INTDIR)\JDFNumberingIntent.sbr"
	-@erase "$(INTDIR)\JDFNumberingParam.obj"
	-@erase "$(INTDIR)\JDFNumberingParam.sbr"
	-@erase "$(INTDIR)\JDFNumberingParams.obj"
	-@erase "$(INTDIR)\JDFNumberingParams.sbr"
	-@erase "$(INTDIR)\JDFNumberItem.obj"
	-@erase "$(INTDIR)\JDFNumberItem.sbr"
	-@erase "$(INTDIR)\JDFNumberRangeList.obj"
	-@erase "$(INTDIR)\JDFNumberRangeList.sbr"
	-@erase "$(INTDIR)\JDFNumberState.obj"
	-@erase "$(INTDIR)\JDFNumberState.sbr"
	-@erase "$(INTDIR)\JDFNumTypeList.obj"
	-@erase "$(INTDIR)\JDFNumTypeList.sbr"
	-@erase "$(INTDIR)\JDFObjectResolution.obj"
	-@erase "$(INTDIR)\JDFObjectResolution.sbr"
	-@erase "$(INTDIR)\JDFObservationTarget.obj"
	-@erase "$(INTDIR)\JDFObservationTarget.sbr"
	-@erase "$(INTDIR)\JDFOccupation.obj"
	-@erase "$(INTDIR)\JDFOccupation.sbr"
	-@erase "$(INTDIR)\JDFor.obj"
	-@erase "$(INTDIR)\JDFor.sbr"
	-@erase "$(INTDIR)\JDFOrderingParams.obj"
	-@erase "$(INTDIR)\JDFOrderingParams.sbr"
	-@erase "$(INTDIR)\JDFotherwise.obj"
	-@erase "$(INTDIR)\JDFotherwise.sbr"
	-@erase "$(INTDIR)\JDFPackingIntent.obj"
	-@erase "$(INTDIR)\JDFPackingIntent.sbr"
	-@erase "$(INTDIR)\JDFPackingParams.obj"
	-@erase "$(INTDIR)\JDFPackingParams.sbr"
	-@erase "$(INTDIR)\JDFPageCell.obj"
	-@erase "$(INTDIR)\JDFPageCell.sbr"
	-@erase "$(INTDIR)\JDFPageData.obj"
	-@erase "$(INTDIR)\JDFPageData.sbr"
	-@erase "$(INTDIR)\JDFPageList.obj"
	-@erase "$(INTDIR)\JDFPageList.sbr"
	-@erase "$(INTDIR)\JDFPallet.obj"
	-@erase "$(INTDIR)\JDFPallet.sbr"
	-@erase "$(INTDIR)\JDFPalletizingParams.obj"
	-@erase "$(INTDIR)\JDFPalletizingParams.sbr"
	-@erase "$(INTDIR)\JDFParamsFactory.obj"
	-@erase "$(INTDIR)\JDFParamsFactory.sbr"
	-@erase "$(INTDIR)\JDFParser.obj"
	-@erase "$(INTDIR)\JDFParser.sbr"
	-@erase "$(INTDIR)\JDFPart.obj"
	-@erase "$(INTDIR)\JDFPart.sbr"
	-@erase "$(INTDIR)\JDFPartAmount.obj"
	-@erase "$(INTDIR)\JDFPartAmount.sbr"
	-@erase "$(INTDIR)\JDFPartStatus.obj"
	-@erase "$(INTDIR)\JDFPartStatus.sbr"
	-@erase "$(INTDIR)\JDFPayment.obj"
	-@erase "$(INTDIR)\JDFPayment.sbr"
	-@erase "$(INTDIR)\JDFPDFInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFPDFInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFPDFPathEvaluation.obj"
	-@erase "$(INTDIR)\JDFPDFPathEvaluation.sbr"
	-@erase "$(INTDIR)\JDFPDFPathState.obj"
	-@erase "$(INTDIR)\JDFPDFPathState.sbr"
	-@erase "$(INTDIR)\JDFPDFToPSConversionParams.obj"
	-@erase "$(INTDIR)\JDFPDFToPSConversionParams.sbr"
	-@erase "$(INTDIR)\JDFPDFXParams.obj"
	-@erase "$(INTDIR)\JDFPDFXParams.sbr"
	-@erase "$(INTDIR)\JDFPDLResourceAlias.obj"
	-@erase "$(INTDIR)\JDFPDLResourceAlias.sbr"
	-@erase "$(INTDIR)\JDFPerforate.obj"
	-@erase "$(INTDIR)\JDFPerforate.sbr"
	-@erase "$(INTDIR)\JDFPerforatingParams.obj"
	-@erase "$(INTDIR)\JDFPerforatingParams.sbr"
	-@erase "$(INTDIR)\JDFPerformance.obj"
	-@erase "$(INTDIR)\JDFPerformance.sbr"
	-@erase "$(INTDIR)\JDFPerson.obj"
	-@erase "$(INTDIR)\JDFPerson.sbr"
	-@erase "$(INTDIR)\JDFPhaseTime.obj"
	-@erase "$(INTDIR)\JDFPhaseTime.sbr"
	-@erase "$(INTDIR)\JDFPipeParams.obj"
	-@erase "$(INTDIR)\JDFPipeParams.sbr"
	-@erase "$(INTDIR)\JDFPixelColorant.obj"
	-@erase "$(INTDIR)\JDFPixelColorant.sbr"
	-@erase "$(INTDIR)\JDFPlaceHolderResource.obj"
	-@erase "$(INTDIR)\JDFPlaceHolderResource.sbr"
	-@erase "$(INTDIR)\JDFPlasticCombBinding.obj"
	-@erase "$(INTDIR)\JDFPlasticCombBinding.sbr"
	-@erase "$(INTDIR)\JDFPlasticCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFPlasticCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFPlateCopyParams.obj"
	-@erase "$(INTDIR)\JDFPlateCopyParams.sbr"
	-@erase "$(INTDIR)\JDFPool.obj"
	-@erase "$(INTDIR)\JDFPool.sbr"
	-@erase "$(INTDIR)\JDFPosition.obj"
	-@erase "$(INTDIR)\JDFPosition.sbr"
	-@erase "$(INTDIR)\JDFPreflightAction.obj"
	-@erase "$(INTDIR)\JDFPreflightAction.sbr"
	-@erase "$(INTDIR)\JDFPreflightAnalysis.obj"
	-@erase "$(INTDIR)\JDFPreflightAnalysis.sbr"
	-@erase "$(INTDIR)\JDFPreflightArgument.obj"
	-@erase "$(INTDIR)\JDFPreflightArgument.sbr"
	-@erase "$(INTDIR)\JDFPreflightConstraint.obj"
	-@erase "$(INTDIR)\JDFPreflightConstraint.sbr"
	-@erase "$(INTDIR)\JDFPreflightConstraintsPool.obj"
	-@erase "$(INTDIR)\JDFPreflightConstraintsPool.sbr"
	-@erase "$(INTDIR)\JDFPreflightDetail.obj"
	-@erase "$(INTDIR)\JDFPreflightDetail.sbr"
	-@erase "$(INTDIR)\JDFPreflightInstance.obj"
	-@erase "$(INTDIR)\JDFPreflightInstance.sbr"
	-@erase "$(INTDIR)\JDFPreflightInstanceDetail.obj"
	-@erase "$(INTDIR)\JDFPreflightInstanceDetail.sbr"
	-@erase "$(INTDIR)\JDFPreflightInventory.obj"
	-@erase "$(INTDIR)\JDFPreflightInventory.sbr"
	-@erase "$(INTDIR)\JDFPreflightParams.obj"
	-@erase "$(INTDIR)\JDFPreflightParams.sbr"
	-@erase "$(INTDIR)\JDFPreflightProfile.obj"
	-@erase "$(INTDIR)\JDFPreflightProfile.sbr"
	-@erase "$(INTDIR)\JDFPreflightReport.obj"
	-@erase "$(INTDIR)\JDFPreflightReport.sbr"
	-@erase "$(INTDIR)\JDFPreflightReportRulePool.obj"
	-@erase "$(INTDIR)\JDFPreflightReportRulePool.sbr"
	-@erase "$(INTDIR)\JDFPreflightResultsPool.obj"
	-@erase "$(INTDIR)\JDFPreflightResultsPool.sbr"
	-@erase "$(INTDIR)\JDFPreflightValue.obj"
	-@erase "$(INTDIR)\JDFPreflightValue.sbr"
	-@erase "$(INTDIR)\JDFPRError.obj"
	-@erase "$(INTDIR)\JDFPRError.sbr"
	-@erase "$(INTDIR)\JDFPreview.obj"
	-@erase "$(INTDIR)\JDFPreview.sbr"
	-@erase "$(INTDIR)\JDFPreviewGenerationParams.obj"
	-@erase "$(INTDIR)\JDFPreviewGenerationParams.sbr"
	-@erase "$(INTDIR)\JDFPRGroup.obj"
	-@erase "$(INTDIR)\JDFPRGroup.sbr"
	-@erase "$(INTDIR)\JDFPRGroupOccurence.obj"
	-@erase "$(INTDIR)\JDFPRGroupOccurence.sbr"
	-@erase "$(INTDIR)\JDFPRGroupOccurenceBase.obj"
	-@erase "$(INTDIR)\JDFPRGroupOccurenceBase.sbr"
	-@erase "$(INTDIR)\JDFPricing.obj"
	-@erase "$(INTDIR)\JDFPricing.sbr"
	-@erase "$(INTDIR)\JDFPrintCondition.obj"
	-@erase "$(INTDIR)\JDFPrintCondition.sbr"
	-@erase "$(INTDIR)\JDFPrintConditionColor.obj"
	-@erase "$(INTDIR)\JDFPrintConditionColor.sbr"
	-@erase "$(INTDIR)\JDFPrintRollingParams.obj"
	-@erase "$(INTDIR)\JDFPrintRollingParams.sbr"
	-@erase "$(INTDIR)\JDFPRItem.obj"
	-@erase "$(INTDIR)\JDFPRItem.sbr"
	-@erase "$(INTDIR)\JDFPROccurence.obj"
	-@erase "$(INTDIR)\JDFPROccurence.sbr"
	-@erase "$(INTDIR)\JDFProcessRun.obj"
	-@erase "$(INTDIR)\JDFProcessRun.sbr"
	-@erase "$(INTDIR)\JDFProductionIntent.obj"
	-@erase "$(INTDIR)\JDFProductionIntent.sbr"
	-@erase "$(INTDIR)\JDFProofingIntent.obj"
	-@erase "$(INTDIR)\JDFProofingIntent.sbr"
	-@erase "$(INTDIR)\JDFProofingParams.obj"
	-@erase "$(INTDIR)\JDFProofingParams.sbr"
	-@erase "$(INTDIR)\JDFProofItem.obj"
	-@erase "$(INTDIR)\JDFProofItem.sbr"
	-@erase "$(INTDIR)\JDFProperties.obj"
	-@erase "$(INTDIR)\JDFProperties.sbr"
	-@erase "$(INTDIR)\JDFPRRule.obj"
	-@erase "$(INTDIR)\JDFPRRule.sbr"
	-@erase "$(INTDIR)\JDFPRRuleAttr.obj"
	-@erase "$(INTDIR)\JDFPRRuleAttr.sbr"
	-@erase "$(INTDIR)\JDFPSToPDFConversionParams.obj"
	-@erase "$(INTDIR)\JDFPSToPDFConversionParams.sbr"
	-@erase "$(INTDIR)\JDFQualityControlParams.obj"
	-@erase "$(INTDIR)\JDFQualityControlParams.sbr"
	-@erase "$(INTDIR)\JDFQualityControlResult.obj"
	-@erase "$(INTDIR)\JDFQualityControlResult.sbr"
	-@erase "$(INTDIR)\JDFQualityMeasurement.obj"
	-@erase "$(INTDIR)\JDFQualityMeasurement.sbr"
	-@erase "$(INTDIR)\JDFQuery.obj"
	-@erase "$(INTDIR)\JDFQuery.sbr"
	-@erase "$(INTDIR)\JDFQueue.obj"
	-@erase "$(INTDIR)\JDFQueue.sbr"
	-@erase "$(INTDIR)\JDFQueueEntry.obj"
	-@erase "$(INTDIR)\JDFQueueEntry.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryDef.obj"
	-@erase "$(INTDIR)\JDFQueueEntryDef.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryDefList.obj"
	-@erase "$(INTDIR)\JDFQueueEntryDefList.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryPosParams.obj"
	-@erase "$(INTDIR)\JDFQueueEntryPosParams.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryPriParams.obj"
	-@erase "$(INTDIR)\JDFQueueEntryPriParams.sbr"
	-@erase "$(INTDIR)\JDFQueueFilter.obj"
	-@erase "$(INTDIR)\JDFQueueFilter.sbr"
	-@erase "$(INTDIR)\JDFQueueSubmissionParams.obj"
	-@erase "$(INTDIR)\JDFQueueSubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFRange.obj"
	-@erase "$(INTDIR)\JDFRange.sbr"
	-@erase "$(INTDIR)\JDFRangeList.obj"
	-@erase "$(INTDIR)\JDFRangeList.sbr"
	-@erase "$(INTDIR)\JDFRectangleEvaluation.obj"
	-@erase "$(INTDIR)\JDFRectangleEvaluation.sbr"
	-@erase "$(INTDIR)\JDFRectangleState.obj"
	-@erase "$(INTDIR)\JDFRectangleState.sbr"
	-@erase "$(INTDIR)\JDFRefElement.obj"
	-@erase "$(INTDIR)\JDFRefElement.sbr"
	-@erase "$(INTDIR)\JDFRegisterMark.obj"
	-@erase "$(INTDIR)\JDFRegisterMark.sbr"
	-@erase "$(INTDIR)\JDFRegisterRibbon.obj"
	-@erase "$(INTDIR)\JDFRegisterRibbon.sbr"
	-@erase "$(INTDIR)\JDFRemoved.obj"
	-@erase "$(INTDIR)\JDFRemoved.sbr"
	-@erase "$(INTDIR)\JDFRenderingParams.obj"
	-@erase "$(INTDIR)\JDFRenderingParams.sbr"
	-@erase "$(INTDIR)\JDFRequestQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFRequestQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFResource.obj"
	-@erase "$(INTDIR)\JDFResource.sbr"
	-@erase "$(INTDIR)\JDFResourceAudit.obj"
	-@erase "$(INTDIR)\JDFResourceAudit.sbr"
	-@erase "$(INTDIR)\JDFResourceCmdParams.obj"
	-@erase "$(INTDIR)\JDFResourceCmdParams.sbr"
	-@erase "$(INTDIR)\JDFResourceDefinitionParams.obj"
	-@erase "$(INTDIR)\JDFResourceDefinitionParams.sbr"
	-@erase "$(INTDIR)\JDFResourceInfo.obj"
	-@erase "$(INTDIR)\JDFResourceInfo.sbr"
	-@erase "$(INTDIR)\JDFResourceLink.obj"
	-@erase "$(INTDIR)\JDFResourceLink.sbr"
	-@erase "$(INTDIR)\JDFResourceLinkPool.obj"
	-@erase "$(INTDIR)\JDFResourceLinkPool.sbr"
	-@erase "$(INTDIR)\JDFResourceParam.obj"
	-@erase "$(INTDIR)\JDFResourceParam.sbr"
	-@erase "$(INTDIR)\JDFResourcePool.obj"
	-@erase "$(INTDIR)\JDFResourcePool.sbr"
	-@erase "$(INTDIR)\JDFResourcePullParams.obj"
	-@erase "$(INTDIR)\JDFResourcePullParams.sbr"
	-@erase "$(INTDIR)\JDFResourceQuParams.obj"
	-@erase "$(INTDIR)\JDFResourceQuParams.sbr"
	-@erase "$(INTDIR)\JDFResponse.obj"
	-@erase "$(INTDIR)\JDFResponse.sbr"
	-@erase "$(INTDIR)\JDFResubmissionParams.obj"
	-@erase "$(INTDIR)\JDFResubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFReturnQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFReturnQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFRingBinding.obj"
	-@erase "$(INTDIR)\JDFRingBinding.sbr"
	-@erase "$(INTDIR)\JDFRingBindingParams.obj"
	-@erase "$(INTDIR)\JDFRingBindingParams.sbr"
	-@erase "$(INTDIR)\JDFRollStand.obj"
	-@erase "$(INTDIR)\JDFRollStand.sbr"
	-@erase "$(INTDIR)\JDFRunElement.obj"
	-@erase "$(INTDIR)\JDFRunElement.sbr"
	-@erase "$(INTDIR)\JDFRunList.obj"
	-@erase "$(INTDIR)\JDFRunList.sbr"
	-@erase "$(INTDIR)\JDFSaddleStitching.obj"
	-@erase "$(INTDIR)\JDFSaddleStitching.sbr"
	-@erase "$(INTDIR)\JDFSaddleStitchingParams.obj"
	-@erase "$(INTDIR)\JDFSaddleStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFScanParams.obj"
	-@erase "$(INTDIR)\JDFScanParams.sbr"
	-@erase "$(INTDIR)\JDFScavengerArea.obj"
	-@erase "$(INTDIR)\JDFScavengerArea.sbr"
	-@erase "$(INTDIR)\JDFScore.obj"
	-@erase "$(INTDIR)\JDFScore.sbr"
	-@erase "$(INTDIR)\JDFScreeningIntent.obj"
	-@erase "$(INTDIR)\JDFScreeningIntent.sbr"
	-@erase "$(INTDIR)\JDFScreeningParams.obj"
	-@erase "$(INTDIR)\JDFScreeningParams.sbr"
	-@erase "$(INTDIR)\JDFScreenSelector.obj"
	-@erase "$(INTDIR)\JDFScreenSelector.sbr"
	-@erase "$(INTDIR)\JDFSeparationControlParams.obj"
	-@erase "$(INTDIR)\JDFSeparationControlParams.sbr"
	-@erase "$(INTDIR)\JDFSeparationList.obj"
	-@erase "$(INTDIR)\JDFSeparationList.sbr"
	-@erase "$(INTDIR)\JDFSeparationSpec.obj"
	-@erase "$(INTDIR)\JDFSeparationSpec.sbr"
	-@erase "$(INTDIR)\JDFset.obj"
	-@erase "$(INTDIR)\JDFset.sbr"
	-@erase "$(INTDIR)\JDFShapeCut.obj"
	-@erase "$(INTDIR)\JDFShapeCut.sbr"
	-@erase "$(INTDIR)\JDFShapeCuttingIntent.obj"
	-@erase "$(INTDIR)\JDFShapeCuttingIntent.sbr"
	-@erase "$(INTDIR)\JDFShapeCuttingParams.obj"
	-@erase "$(INTDIR)\JDFShapeCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFShapeElement.obj"
	-@erase "$(INTDIR)\JDFShapeElement.sbr"
	-@erase "$(INTDIR)\JDFShapeEvaluation.obj"
	-@erase "$(INTDIR)\JDFShapeEvaluation.sbr"
	-@erase "$(INTDIR)\JDFShapeState.obj"
	-@erase "$(INTDIR)\JDFShapeState.sbr"
	-@erase "$(INTDIR)\JDFSheet.obj"
	-@erase "$(INTDIR)\JDFSheet.sbr"
	-@erase "$(INTDIR)\JDFShrinkingParams.obj"
	-@erase "$(INTDIR)\JDFShrinkingParams.sbr"
	-@erase "$(INTDIR)\JDFShutDownCmdParams.obj"
	-@erase "$(INTDIR)\JDFShutDownCmdParams.sbr"
	-@erase "$(INTDIR)\JDFSideSewing.obj"
	-@erase "$(INTDIR)\JDFSideSewing.sbr"
	-@erase "$(INTDIR)\JDFSideSewingParams.obj"
	-@erase "$(INTDIR)\JDFSideSewingParams.sbr"
	-@erase "$(INTDIR)\JDFSideStitching.obj"
	-@erase "$(INTDIR)\JDFSideStitching.sbr"
	-@erase "$(INTDIR)\JDFSignal.obj"
	-@erase "$(INTDIR)\JDFSignal.sbr"
	-@erase "$(INTDIR)\JDFSignature.obj"
	-@erase "$(INTDIR)\JDFSignature.sbr"
	-@erase "$(INTDIR)\JDFSignatureCell.obj"
	-@erase "$(INTDIR)\JDFSignatureCell.sbr"
	-@erase "$(INTDIR)\JDFSizeIntent.obj"
	-@erase "$(INTDIR)\JDFSizeIntent.sbr"
	-@erase "$(INTDIR)\JDFSoftCoverBinding.obj"
	-@erase "$(INTDIR)\JDFSoftCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFSpan.obj"
	-@erase "$(INTDIR)\JDFSpan.sbr"
	-@erase "$(INTDIR)\JDFSpawned.obj"
	-@erase "$(INTDIR)\JDFSpawned.sbr"
	-@erase "$(INTDIR)\JDFSpinePreparationParams.obj"
	-@erase "$(INTDIR)\JDFSpinePreparationParams.sbr"
	-@erase "$(INTDIR)\JDFSpineTapingParams.obj"
	-@erase "$(INTDIR)\JDFSpineTapingParams.sbr"
	-@erase "$(INTDIR)\JDFStackingParams.obj"
	-@erase "$(INTDIR)\JDFStackingParams.sbr"
	-@erase "$(INTDIR)\JDFState.obj"
	-@erase "$(INTDIR)\JDFState.sbr"
	-@erase "$(INTDIR)\JDFStatusPool.obj"
	-@erase "$(INTDIR)\JDFStatusPool.sbr"
	-@erase "$(INTDIR)\JDFStatusQuParams.obj"
	-@erase "$(INTDIR)\JDFStatusQuParams.sbr"
	-@erase "$(INTDIR)\JDFStitchingParams.obj"
	-@erase "$(INTDIR)\JDFStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFStopPersChParams.obj"
	-@erase "$(INTDIR)\JDFStopPersChParams.sbr"
	-@erase "$(INTDIR)\JDFStrap.obj"
	-@erase "$(INTDIR)\JDFStrap.sbr"
	-@erase "$(INTDIR)\JDFStrappingParams.obj"
	-@erase "$(INTDIR)\JDFStrappingParams.sbr"
	-@erase "$(INTDIR)\JDFStringEvaluation.obj"
	-@erase "$(INTDIR)\JDFStringEvaluation.sbr"
	-@erase "$(INTDIR)\JDFStringListValue.obj"
	-@erase "$(INTDIR)\JDFStringListValue.sbr"
	-@erase "$(INTDIR)\JDFStrings.obj"
	-@erase "$(INTDIR)\JDFStrings.sbr"
	-@erase "$(INTDIR)\JDFStringState.obj"
	-@erase "$(INTDIR)\JDFStringState.sbr"
	-@erase "$(INTDIR)\JDFStripBinding.obj"
	-@erase "$(INTDIR)\JDFStripBinding.sbr"
	-@erase "$(INTDIR)\JDFStripBindingParams.obj"
	-@erase "$(INTDIR)\JDFStripBindingParams.sbr"
	-@erase "$(INTDIR)\JDFStripCellParams.obj"
	-@erase "$(INTDIR)\JDFStripCellParams.sbr"
	-@erase "$(INTDIR)\JDFStrippingParams.obj"
	-@erase "$(INTDIR)\JDFStrippingParams.sbr"
	-@erase "$(INTDIR)\JDFSubmissionMethods.obj"
	-@erase "$(INTDIR)\JDFSubmissionMethods.sbr"
	-@erase "$(INTDIR)\JDFSubscription.obj"
	-@erase "$(INTDIR)\JDFSubscription.sbr"
	-@erase "$(INTDIR)\JDFSurface.obj"
	-@erase "$(INTDIR)\JDFSurface.sbr"
	-@erase "$(INTDIR)\JDFSystemTimeSet.obj"
	-@erase "$(INTDIR)\JDFSystemTimeSet.sbr"
	-@erase "$(INTDIR)\JDFTabs.obj"
	-@erase "$(INTDIR)\JDFTabs.sbr"
	-@erase "$(INTDIR)\JDFTape.obj"
	-@erase "$(INTDIR)\JDFTape.sbr"
	-@erase "$(INTDIR)\JDFTest.obj"
	-@erase "$(INTDIR)\JDFTest.sbr"
	-@erase "$(INTDIR)\JDFTestPool.obj"
	-@erase "$(INTDIR)\JDFTestPool.sbr"
	-@erase "$(INTDIR)\JDFTestRef.obj"
	-@erase "$(INTDIR)\JDFTestRef.sbr"
	-@erase "$(INTDIR)\JDFThinPDFParams.obj"
	-@erase "$(INTDIR)\JDFThinPDFParams.sbr"
	-@erase "$(INTDIR)\JDFThreadSealing.obj"
	-@erase "$(INTDIR)\JDFThreadSealing.sbr"
	-@erase "$(INTDIR)\JDFThreadSealingParams.obj"
	-@erase "$(INTDIR)\JDFThreadSealingParams.sbr"
	-@erase "$(INTDIR)\JDFThreadSewing.obj"
	-@erase "$(INTDIR)\JDFThreadSewing.sbr"
	-@erase "$(INTDIR)\JDFThreadSewingParams.obj"
	-@erase "$(INTDIR)\JDFThreadSewingParams.sbr"
	-@erase "$(INTDIR)\JDFTIFFEmbeddedFile.obj"
	-@erase "$(INTDIR)\JDFTIFFEmbeddedFile.sbr"
	-@erase "$(INTDIR)\JDFTIFFFormatParams.obj"
	-@erase "$(INTDIR)\JDFTIFFFormatParams.sbr"
	-@erase "$(INTDIR)\JDFTIFFtag.obj"
	-@erase "$(INTDIR)\JDFTIFFtag.sbr"
	-@erase "$(INTDIR)\JDFTile.obj"
	-@erase "$(INTDIR)\JDFTile.sbr"
	-@erase "$(INTDIR)\JDFTool.obj"
	-@erase "$(INTDIR)\JDFTool.sbr"
	-@erase "$(INTDIR)\JDFTrackFilter.obj"
	-@erase "$(INTDIR)\JDFTrackFilter.sbr"
	-@erase "$(INTDIR)\JDFTrackResult.obj"
	-@erase "$(INTDIR)\JDFTrackResult.sbr"
	-@erase "$(INTDIR)\JDFTransferCurve.obj"
	-@erase "$(INTDIR)\JDFTransferCurve.sbr"
	-@erase "$(INTDIR)\JDFTransferCurvePool.obj"
	-@erase "$(INTDIR)\JDFTransferCurvePool.sbr"
	-@erase "$(INTDIR)\JDFTransferCurveSet.obj"
	-@erase "$(INTDIR)\JDFTransferCurveSet.sbr"
	-@erase "$(INTDIR)\JDFTransferFunctionControl.obj"
	-@erase "$(INTDIR)\JDFTransferFunctionControl.sbr"
	-@erase "$(INTDIR)\JDFTrappingDetails.obj"
	-@erase "$(INTDIR)\JDFTrappingDetails.sbr"
	-@erase "$(INTDIR)\JDFTrappingOrder.obj"
	-@erase "$(INTDIR)\JDFTrappingOrder.sbr"
	-@erase "$(INTDIR)\JDFTrappingParams.obj"
	-@erase "$(INTDIR)\JDFTrappingParams.sbr"
	-@erase "$(INTDIR)\JDFTrapRegion.obj"
	-@erase "$(INTDIR)\JDFTrapRegion.sbr"
	-@erase "$(INTDIR)\JDFTrigger.obj"
	-@erase "$(INTDIR)\JDFTrigger.sbr"
	-@erase "$(INTDIR)\JDFTrimmingParams.obj"
	-@erase "$(INTDIR)\JDFTrimmingParams.sbr"
	-@erase "$(INTDIR)\JDFValue.obj"
	-@erase "$(INTDIR)\JDFValue.sbr"
	-@erase "$(INTDIR)\JDFValueLoc.obj"
	-@erase "$(INTDIR)\JDFValueLoc.sbr"
	-@erase "$(INTDIR)\JDFVerificationParams.obj"
	-@erase "$(INTDIR)\JDFVerificationParams.sbr"
	-@erase "$(INTDIR)\JDFWakeUpCmdParams.obj"
	-@erase "$(INTDIR)\JDFWakeUpCmdParams.sbr"
	-@erase "$(INTDIR)\JDFwhen.obj"
	-@erase "$(INTDIR)\JDFwhen.sbr"
	-@erase "$(INTDIR)\JDFWireCombBinding.obj"
	-@erase "$(INTDIR)\JDFWireCombBinding.sbr"
	-@erase "$(INTDIR)\JDFWireCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFWireCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFWrappingParams.obj"
	-@erase "$(INTDIR)\JDFWrappingParams.sbr"
	-@erase "$(INTDIR)\JDFxor.obj"
	-@erase "$(INTDIR)\JDFxor.sbr"
	-@erase "$(INTDIR)\JDFXYPairEvaluation.obj"
	-@erase "$(INTDIR)\JDFXYPairEvaluation.sbr"
	-@erase "$(INTDIR)\JDFXYPairRangeList.obj"
	-@erase "$(INTDIR)\JDFXYPairRangeList.sbr"
	-@erase "$(INTDIR)\JDFXYPairState.obj"
	-@erase "$(INTDIR)\JDFXYPairState.sbr"
	-@erase "$(INTDIR)\KElement.obj"
	-@erase "$(INTDIR)\KElement.sbr"
	-@erase "$(INTDIR)\KElementStrings.obj"
	-@erase "$(INTDIR)\KElementStrings.sbr"
	-@erase "$(INTDIR)\MyDate.obj"
	-@erase "$(INTDIR)\MyDate.sbr"
	-@erase "$(INTDIR)\vElement.obj"
	-@erase "$(INTDIR)\vElement.sbr"
	-@erase "$(INTDIR)\XMLDoc.obj"
	-@erase "$(INTDIR)\XMLDoc.sbr"
	-@erase "$(INTDIR)\XMLDocUserData.obj"
	-@erase "$(INTDIR)\XMLDocUserData.sbr"
	-@erase "$(OUTDIR)\JDFWrapperDLLd.dll"
	-@erase "$(OUTDIR)\JDFWrapperDLLd.exp"
	-@erase "$(OUTDIR)\JDFWrapperDLLd.lib"
	-@erase "$(OUTDIR)\JDFWrapperDLLd.pdb"
	-@erase "$(OUTDIR)\JDFWrapperLib.bsc"
	-@erase "$(OUTDIR)\obj\JDFWrapperDLL\JDFWrapperDLLd.map"
	-@erase "..\..\..\Build\Win32\VC6\DebugDLL\JDFWrapperDLL.idb"
	-@erase "..\..\..\Build\Win32\VC6\DebugDLL\JDFWrapperDLL.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=xicl6.exe
CPP_PROJ=/nologo /MDd /w /W0 /Gm /GX /Zi /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /D "JDF_WRAPPERCORE" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"..\..\..\Build\Win32\VC6\DebugDLL\JDFWrapperDLL" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\JDFWrapperLib.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\JDFAmountPool.sbr" \
	"$(INTDIR)\JDFAncestor.sbr" \
	"$(INTDIR)\JDFAncestorPool.sbr" \
	"$(INTDIR)\JDFAudit.sbr" \
	"$(INTDIR)\JDFAuditPool.sbr" \
	"$(INTDIR)\JDFBarcode.sbr" \
	"$(INTDIR)\JDFBusinessInfo.sbr" \
	"$(INTDIR)\JDFComment.sbr" \
	"$(INTDIR)\JDFCounterReset.sbr" \
	"$(INTDIR)\JDFCreated.sbr" \
	"$(INTDIR)\JDFCustomerInfo.sbr" \
	"$(INTDIR)\JDFCustomerMessage.sbr" \
	"$(INTDIR)\JDFDeleted.sbr" \
	"$(INTDIR)\JDFError.sbr" \
	"$(INTDIR)\JDFEvent.sbr" \
	"$(INTDIR)\JDFFCNKey.sbr" \
	"$(INTDIR)\JDFLocation.sbr" \
	"$(INTDIR)\JDFMerged.sbr" \
	"$(INTDIR)\JDFModified.sbr" \
	"$(INTDIR)\JDFModulePhase.sbr" \
	"$(INTDIR)\JDFNode.sbr" \
	"$(INTDIR)\JDFNodeInfo.sbr" \
	"$(INTDIR)\JDFNotification.sbr" \
	"$(INTDIR)\JDFPart.sbr" \
	"$(INTDIR)\JDFPartAmount.sbr" \
	"$(INTDIR)\JDFPartStatus.sbr" \
	"$(INTDIR)\JDFPhaseTime.sbr" \
	"$(INTDIR)\JDFProcessRun.sbr" \
	"$(INTDIR)\JDFResourceAudit.sbr" \
	"$(INTDIR)\JDFResourceLinkPool.sbr" \
	"$(INTDIR)\JDFResourcePool.sbr" \
	"$(INTDIR)\JDFSpawned.sbr" \
	"$(INTDIR)\JDFStatusPool.sbr" \
	"$(INTDIR)\JDFSystemTimeSet.sbr" \
	"$(INTDIR)\JDFAcknowledge.sbr" \
	"$(INTDIR)\JDFAdded.sbr" \
	"$(INTDIR)\JDFChangedAttribute.sbr" \
	"$(INTDIR)\JDFChangedPath.sbr" \
	"$(INTDIR)\JDFCommand.sbr" \
	"$(INTDIR)\JDFDeviceFilter.sbr" \
	"$(INTDIR)\JDFDeviceInfo.sbr" \
	"$(INTDIR)\JDFDeviceList.sbr" \
	"$(INTDIR)\JDFEmployeeDef.sbr" \
	"$(INTDIR)\JDFFlushedResources.sbr" \
	"$(INTDIR)\JDFFlushQueueParams.sbr" \
	"$(INTDIR)\JDFFlushResourceParams.sbr" \
	"$(INTDIR)\JDFIDInfo.sbr" \
	"$(INTDIR)\JDFJDFController.sbr" \
	"$(INTDIR)\JDFJDFService.sbr" \
	"$(INTDIR)\JDFJMF.sbr" \
	"$(INTDIR)\JDFJobPhase.sbr" \
	"$(INTDIR)\JDFKnownMsgQuParams.sbr" \
	"$(INTDIR)\JDFMessage.sbr" \
	"$(INTDIR)\JDFMessageElement.sbr" \
	"$(INTDIR)\JDFMessageService.sbr" \
	"$(INTDIR)\JDFModuleStatus.sbr" \
	"$(INTDIR)\JDFMsgFilter.sbr" \
	"$(INTDIR)\JDFNewJDFCmdParams.sbr" \
	"$(INTDIR)\JDFNewJDFQuParams.sbr" \
	"$(INTDIR)\JDFNodeInfoCmdParams.sbr" \
	"$(INTDIR)\JDFNodeInfoQuParams.sbr" \
	"$(INTDIR)\JDFNodeInfoResp.sbr" \
	"$(INTDIR)\JDFNotificationDef.sbr" \
	"$(INTDIR)\JDFNotificationFilter.sbr" \
	"$(INTDIR)\JDFObservationTarget.sbr" \
	"$(INTDIR)\JDFOccupation.sbr" \
	"$(INTDIR)\JDFPipeParams.sbr" \
	"$(INTDIR)\JDFQuery.sbr" \
	"$(INTDIR)\JDFQueue.sbr" \
	"$(INTDIR)\JDFQueueEntry.sbr" \
	"$(INTDIR)\JDFQueueEntryDef.sbr" \
	"$(INTDIR)\JDFQueueEntryDefList.sbr" \
	"$(INTDIR)\JDFQueueEntryPosParams.sbr" \
	"$(INTDIR)\JDFQueueEntryPriParams.sbr" \
	"$(INTDIR)\JDFQueueFilter.sbr" \
	"$(INTDIR)\JDFQueueSubmissionParams.sbr" \
	"$(INTDIR)\JDFRemoved.sbr" \
	"$(INTDIR)\JDFRequestQueueEntryParams.sbr" \
	"$(INTDIR)\JDFResourceCmdParams.sbr" \
	"$(INTDIR)\JDFResourceInfo.sbr" \
	"$(INTDIR)\JDFResourcePullParams.sbr" \
	"$(INTDIR)\JDFResourceQuParams.sbr" \
	"$(INTDIR)\JDFResponse.sbr" \
	"$(INTDIR)\JDFResubmissionParams.sbr" \
	"$(INTDIR)\JDFReturnQueueEntryParams.sbr" \
	"$(INTDIR)\JDFShutDownCmdParams.sbr" \
	"$(INTDIR)\JDFSignal.sbr" \
	"$(INTDIR)\JDFStatusQuParams.sbr" \
	"$(INTDIR)\JDFStopPersChParams.sbr" \
	"$(INTDIR)\JDFSubmissionMethods.sbr" \
	"$(INTDIR)\JDFSubscription.sbr" \
	"$(INTDIR)\JDFTrackFilter.sbr" \
	"$(INTDIR)\JDFTrackResult.sbr" \
	"$(INTDIR)\JDFTrigger.sbr" \
	"$(INTDIR)\JDFWakeUpCmdParams.sbr" \
	"$(INTDIR)\JDFArtDeliveryIntent.sbr" \
	"$(INTDIR)\JDFBindingIntent.sbr" \
	"$(INTDIR)\JDFColorIntent.sbr" \
	"$(INTDIR)\JDFDeliveryIntent.sbr" \
	"$(INTDIR)\JDFEmbossingIntent.sbr" \
	"$(INTDIR)\JDFFoldingIntent.sbr" \
	"$(INTDIR)\JDFHoleMakingIntent.sbr" \
	"$(INTDIR)\JDFInsertingIntent.sbr" \
	"$(INTDIR)\JDFIntentResource.sbr" \
	"$(INTDIR)\JDFLaminatingIntent.sbr" \
	"$(INTDIR)\JDFLayoutIntent.sbr" \
	"$(INTDIR)\JDFMediaIntent.sbr" \
	"$(INTDIR)\JDFNumberingIntent.sbr" \
	"$(INTDIR)\JDFPackingIntent.sbr" \
	"$(INTDIR)\JDFProductionIntent.sbr" \
	"$(INTDIR)\JDFProofingIntent.sbr" \
	"$(INTDIR)\JDFScreeningIntent.sbr" \
	"$(INTDIR)\JDFShapeCuttingIntent.sbr" \
	"$(INTDIR)\JDFSizeIntent.sbr" \
	"$(INTDIR)\JDFSpan.sbr" \
	"$(INTDIR)\JDFAdhesiveBinding.sbr" \
	"$(INTDIR)\JDFArtDelivery.sbr" \
	"$(INTDIR)\JDFBindItem.sbr" \
	"$(INTDIR)\JDFBindList.sbr" \
	"$(INTDIR)\JDFBookCase.sbr" \
	"$(INTDIR)\JDFChannelBinding.sbr" \
	"$(INTDIR)\JDFCoilBinding.sbr" \
	"$(INTDIR)\JDFColorsUsed.sbr" \
	"$(INTDIR)\JDFCreditCard.sbr" \
	"$(INTDIR)\JDFDropIntent.sbr" \
	"$(INTDIR)\JDFDropItemIntent.sbr" \
	"$(INTDIR)\JDFEdgeGluing.sbr" \
	"$(INTDIR)\JDFEmbossingItem.sbr" \
	"$(INTDIR)\JDFHardCoverBinding.sbr" \
	"$(INTDIR)\JDFHoleList.sbr" \
	"$(INTDIR)\JDFInsert.sbr" \
	"$(INTDIR)\JDFInsertList.sbr" \
	"$(INTDIR)\JDFNumberItem.sbr" \
	"$(INTDIR)\JDFPayment.sbr" \
	"$(INTDIR)\JDFPlasticCombBinding.sbr" \
	"$(INTDIR)\JDFPricing.sbr" \
	"$(INTDIR)\JDFProofItem.sbr" \
	"$(INTDIR)\JDFRingBinding.sbr" \
	"$(INTDIR)\JDFSaddleStitching.sbr" \
	"$(INTDIR)\JDFShapeCut.sbr" \
	"$(INTDIR)\JDFSideSewing.sbr" \
	"$(INTDIR)\JDFSideStitching.sbr" \
	"$(INTDIR)\JDFSoftCoverBinding.sbr" \
	"$(INTDIR)\JDFStripBinding.sbr" \
	"$(INTDIR)\JDFTabs.sbr" \
	"$(INTDIR)\JDFTape.sbr" \
	"$(INTDIR)\JDFThreadSealing.sbr" \
	"$(INTDIR)\JDFThreadSewing.sbr" \
	"$(INTDIR)\JDFWireCombBinding.sbr" \
	"$(INTDIR)\JDFAddress.sbr" \
	"$(INTDIR)\JDFAdhesiveBindingParams.sbr" \
	"$(INTDIR)\JDFApprovalParams.sbr" \
	"$(INTDIR)\JDFApprovalSuccess.sbr" \
	"$(INTDIR)\JDFAssembly.sbr" \
	"$(INTDIR)\JDFAssetListCreationParams.sbr" \
	"$(INTDIR)\JDFAutomatedOverprintParams.sbr" \
	"$(INTDIR)\JDFBinderySignature.sbr" \
	"$(INTDIR)\JDFBlockPreparationParams.sbr" \
	"$(INTDIR)\JDFBoxPackingParams.sbr" \
	"$(INTDIR)\JDFBufferParams.sbr" \
	"$(INTDIR)\JDFBundle.sbr" \
	"$(INTDIR)\JDFBundlingParams.sbr" \
	"$(INTDIR)\JDFByteMap.sbr" \
	"$(INTDIR)\JDFCaseMakingParams.sbr" \
	"$(INTDIR)\JDFCasingInParams.sbr" \
	"$(INTDIR)\JDFChannelBindingParams.sbr" \
	"$(INTDIR)\JDFCIELABMeasuringField.sbr" \
	"$(INTDIR)\JDFCoilBindingParams.sbr" \
	"$(INTDIR)\JDFCollectingParams.sbr" \
	"$(INTDIR)\JDFColor.sbr" \
	"$(INTDIR)\JDFColorantAlias.sbr" \
	"$(INTDIR)\JDFColorantControl.sbr" \
	"$(INTDIR)\JDFColorControlStrip.sbr" \
	"$(INTDIR)\JDFColorCorrectionParams.sbr" \
	"$(INTDIR)\JDFColorMeasurementConditions.sbr" \
	"$(INTDIR)\JDFColorPool.sbr" \
	"$(INTDIR)\JDFColorSpaceConversionOp.sbr" \
	"$(INTDIR)\JDFColorSpaceConversionParams.sbr" \
	"$(INTDIR)\JDFComChannel.sbr" \
	"$(INTDIR)\JDFCompany.sbr" \
	"$(INTDIR)\JDFComponent.sbr" \
	"$(INTDIR)\JDFContact.sbr" \
	"$(INTDIR)\JDFContactCopyParams.sbr" \
	"$(INTDIR)\JDFConventionalPrintingParams.sbr" \
	"$(INTDIR)\JDFCostCenter.sbr" \
	"$(INTDIR)\JDFCoverApplicationParams.sbr" \
	"$(INTDIR)\JDFCreasingParams.sbr" \
	"$(INTDIR)\JDFCutBlock.sbr" \
	"$(INTDIR)\JDFCutMark.sbr" \
	"$(INTDIR)\JDFCuttingParams.sbr" \
	"$(INTDIR)\JDFDBMergeParams.sbr" \
	"$(INTDIR)\JDFDBRules.sbr" \
	"$(INTDIR)\JDFDBSchema.sbr" \
	"$(INTDIR)\JDFDBSelection.sbr" \
	"$(INTDIR)\JDFDeliveryParams.sbr" \
	"$(INTDIR)\JDFDensityMeasuringField.sbr" \
	"$(INTDIR)\JDFDevelopingParams.sbr" \
	"$(INTDIR)\JDFDevice.sbr" \
	"$(INTDIR)\JDFDeviceMark.sbr" \
	"$(INTDIR)\JDFDeviceNSpace.sbr" \
	"$(INTDIR)\JDFDigitalDeliveryParams.sbr" \
	"$(INTDIR)\JDFDigitalMedia.sbr" \
	"$(INTDIR)\JDFDigitalPrintingParams.sbr" \
	"$(INTDIR)\JDFDisjointing.sbr" \
	"$(INTDIR)\JDFDisposition.sbr" \
	"$(INTDIR)\JDFDividingParams.sbr" \
	"$(INTDIR)\JDFElementColorParams.sbr" \
	"$(INTDIR)\JDFEmbossingParams.sbr" \
	"$(INTDIR)\JDFEmployee.sbr" \
	"$(INTDIR)\JDFEndSheetGluingParams.sbr" \
	"$(INTDIR)\JDFExposedMedia.sbr" \
	"$(INTDIR)\JDFFeedingParams.sbr" \
	"$(INTDIR)\JDFFileSpec.sbr" \
	"$(INTDIR)\JDFFitPolicy.sbr" \
	"$(INTDIR)\JDFFold.sbr" \
	"$(INTDIR)\JDFFoldingParams.sbr" \
	"$(INTDIR)\JDFFontParams.sbr" \
	"$(INTDIR)\JDFFontPolicy.sbr" \
	"$(INTDIR)\JDFFormatConversionParams.sbr" \
	"$(INTDIR)\JDFGatheringParams.sbr" \
	"$(INTDIR)\JDFGlueApplication.sbr" \
	"$(INTDIR)\JDFGlueLine.sbr" \
	"$(INTDIR)\JDFGluingParams.sbr" \
	"$(INTDIR)\JDFHeadBandApplicationParams.sbr" \
	"$(INTDIR)\JDFHole.sbr" \
	"$(INTDIR)\JDFHoleLine.sbr" \
	"$(INTDIR)\JDFHoleMakingParams.sbr" \
	"$(INTDIR)\JDFIdentificationField.sbr" \
	"$(INTDIR)\JDFIDPrintingParams.sbr" \
	"$(INTDIR)\JDFImageCompressionParams.sbr" \
	"$(INTDIR)\JDFImageReplacementParams.sbr" \
	"$(INTDIR)\JDFImageSetterParams.sbr" \
	"$(INTDIR)\JDFInk.sbr" \
	"$(INTDIR)\JDFInkZoneCalculationParams.sbr" \
	"$(INTDIR)\JDFInkZoneProfile.sbr" \
	"$(INTDIR)\JDFInsertingParams.sbr" \
	"$(INTDIR)\JDFInsertSheet.sbr" \
	"$(INTDIR)\JDFInterpretedPDLData.sbr" \
	"$(INTDIR)\JDFInterpretingParams.sbr" \
	"$(INTDIR)\JDFJacketingParams.sbr" \
	"$(INTDIR)\JDFJobField.sbr" \
	"$(INTDIR)\JDFLabelingParams.sbr" \
	"$(INTDIR)\JDFLaminatingParams.sbr" \
	"$(INTDIR)\JDFLayout.sbr" \
	"$(INTDIR)\JDFLayoutElement.sbr" \
	"$(INTDIR)\JDFLayoutPreparationParams.sbr" \
	"$(INTDIR)\JDFLongitudinalRibbonOperationParams.sbr" \
	"$(INTDIR)\JDFManualLaborParams.sbr" \
	"$(INTDIR)\JDFMedia.sbr" \
	"$(INTDIR)\JDFMediaSource.sbr" \
	"$(INTDIR)\JDFMISDetails.sbr" \
	"$(INTDIR)\JDFNumberingParams.sbr" \
	"$(INTDIR)\JDFObjectResolution.sbr" \
	"$(INTDIR)\JDFOrderingParams.sbr" \
	"$(INTDIR)\JDFPackingParams.sbr" \
	"$(INTDIR)\JDFPageList.sbr" \
	"$(INTDIR)\JDFPallet.sbr" \
	"$(INTDIR)\JDFPalletizingParams.sbr" \
	"$(INTDIR)\JDFPDFToPSConversionParams.sbr" \
	"$(INTDIR)\JDFPDLResourceAlias.sbr" \
	"$(INTDIR)\JDFPerforatingParams.sbr" \
	"$(INTDIR)\JDFPerson.sbr" \
	"$(INTDIR)\JDFPlaceHolderResource.sbr" \
	"$(INTDIR)\JDFPlasticCombBindingParams.sbr" \
	"$(INTDIR)\JDFPlateCopyParams.sbr" \
	"$(INTDIR)\JDFPreflightAnalysis.sbr" \
	"$(INTDIR)\JDFPreflightInventory.sbr" \
	"$(INTDIR)\JDFPreflightParams.sbr" \
	"$(INTDIR)\JDFPreflightProfile.sbr" \
	"$(INTDIR)\JDFPreflightReport.sbr" \
	"$(INTDIR)\JDFPreflightReportRulePool.sbr" \
	"$(INTDIR)\JDFPreview.sbr" \
	"$(INTDIR)\JDFPreviewGenerationParams.sbr" \
	"$(INTDIR)\JDFPrintCondition.sbr" \
	"$(INTDIR)\JDFPrintRollingParams.sbr" \
	"$(INTDIR)\JDFProofingParams.sbr" \
	"$(INTDIR)\JDFPSToPDFConversionParams.sbr" \
	"$(INTDIR)\JDFQualityControlParams.sbr" \
	"$(INTDIR)\JDFQualityControlResult.sbr" \
	"$(INTDIR)\JDFRegisterMark.sbr" \
	"$(INTDIR)\JDFRegisterRibbon.sbr" \
	"$(INTDIR)\JDFRenderingParams.sbr" \
	"$(INTDIR)\JDFResourceDefinitionParams.sbr" \
	"$(INTDIR)\JDFRingBindingParams.sbr" \
	"$(INTDIR)\JDFRollStand.sbr" \
	"$(INTDIR)\JDFRunList.sbr" \
	"$(INTDIR)\JDFSaddleStitchingParams.sbr" \
	"$(INTDIR)\JDFScanParams.sbr" \
	"$(INTDIR)\JDFScavengerArea.sbr" \
	"$(INTDIR)\JDFScreeningParams.sbr" \
	"$(INTDIR)\JDFSeparationControlParams.sbr" \
	"$(INTDIR)\JDFSeparationSpec.sbr" \
	"$(INTDIR)\JDFShapeCuttingParams.sbr" \
	"$(INTDIR)\JDFSheet.sbr" \
	"$(INTDIR)\JDFShrinkingParams.sbr" \
	"$(INTDIR)\JDFSideSewingParams.sbr" \
	"$(INTDIR)\JDFSpinePreparationParams.sbr" \
	"$(INTDIR)\JDFSpineTapingParams.sbr" \
	"$(INTDIR)\JDFStackingParams.sbr" \
	"$(INTDIR)\JDFStitchingParams.sbr" \
	"$(INTDIR)\JDFStrap.sbr" \
	"$(INTDIR)\JDFStrappingParams.sbr" \
	"$(INTDIR)\JDFStripBindingParams.sbr" \
	"$(INTDIR)\JDFStrippingParams.sbr" \
	"$(INTDIR)\JDFSurface.sbr" \
	"$(INTDIR)\JDFThreadSealingParams.sbr" \
	"$(INTDIR)\JDFThreadSewingParams.sbr" \
	"$(INTDIR)\JDFTile.sbr" \
	"$(INTDIR)\JDFTool.sbr" \
	"$(INTDIR)\JDFTransferCurve.sbr" \
	"$(INTDIR)\JDFTransferCurvePool.sbr" \
	"$(INTDIR)\JDFTransferFunctionControl.sbr" \
	"$(INTDIR)\JDFTrappingDetails.sbr" \
	"$(INTDIR)\JDFTrappingParams.sbr" \
	"$(INTDIR)\JDFTrapRegion.sbr" \
	"$(INTDIR)\JDFTrimmingParams.sbr" \
	"$(INTDIR)\JDFVerificationParams.sbr" \
	"$(INTDIR)\JDFWireCombBindingParams.sbr" \
	"$(INTDIR)\JDFWrappingParams.sbr" \
	"$(INTDIR)\JDFAdvancedParams.sbr" \
	"$(INTDIR)\JDFApprovalPerson.sbr" \
	"$(INTDIR)\JDFAssemblySection.sbr" \
	"$(INTDIR)\JDFBand.sbr" \
	"$(INTDIR)\JDFBasicPreflightTest.sbr" \
	"$(INTDIR)\JDFBindingQualityParams.sbr" \
	"$(INTDIR)\JDFBoxArgument.sbr" \
	"$(INTDIR)\JDFBoxToBoxDifference.sbr" \
	"$(INTDIR)\JDFBundleItem.sbr" \
	"$(INTDIR)\JDFCCITTFaxParams.sbr" \
	"$(INTDIR)\JDFCollatingItem.sbr" \
	"$(INTDIR)\JDFColorantZoneDetails.sbr" \
	"$(INTDIR)\JDFColorCorrectionOp.sbr" \
	"$(INTDIR)\JDFColorSpaceSubstitute.sbr" \
	"$(INTDIR)\JDFContainer.sbr" \
	"$(INTDIR)\JDFContentObject.sbr" \
	"$(INTDIR)\JDFCrease.sbr" \
	"$(INTDIR)\JDFCut.sbr" \
	"$(INTDIR)\JDFDCTParams.sbr" \
	"$(INTDIR)\JDFDependencies.sbr" \
	"$(INTDIR)\JDFDeviceNColor.sbr" \
	"$(INTDIR)\JDFDrop.sbr" \
	"$(INTDIR)\JDFDropItem.sbr" \
	"$(INTDIR)\JDFDynamicField.sbr" \
	"$(INTDIR)\JDFDynamicInput.sbr" \
	"$(INTDIR)\JDFEmboss.sbr" \
	"$(INTDIR)\JDFEndSheet.sbr" \
	"$(INTDIR)\JDFFeeder.sbr" \
	"$(INTDIR)\JDFFeederQualityParams.sbr" \
	"$(INTDIR)\JDFFileAlias.sbr" \
	"$(INTDIR)\JDFFlateParams.sbr" \
	"$(INTDIR)\JDFGlue.sbr" \
	"$(INTDIR)\JDFIcon.sbr" \
	"$(INTDIR)\JDFIconList.sbr" \
	"$(INTDIR)\JDFIDPCover.sbr" \
	"$(INTDIR)\JDFIDPFinishing.sbr" \
	"$(INTDIR)\JDFIDPFolding.sbr" \
	"$(INTDIR)\JDFIDPHoleMaking.sbr" \
	"$(INTDIR)\JDFIDPImageShift.sbr" \
	"$(INTDIR)\JDFIDPJobSheet.sbr" \
	"$(INTDIR)\JDFIDPLayout.sbr" \
	"$(INTDIR)\JDFIDPStitching.sbr" \
	"$(INTDIR)\JDFIDPTrimming.sbr" \
	"$(INTDIR)\JDFImageCompression.sbr" \
	"$(INTDIR)\JDFImageShift.sbr" \
	"$(INTDIR)\JDFLayerDetails.sbr" \
	"$(INTDIR)\JDFLayerList.sbr" \
	"$(INTDIR)\JDFLongFold.sbr" \
	"$(INTDIR)\JDFLongGlue.sbr" \
	"$(INTDIR)\JDFLongPerforate.sbr" \
	"$(INTDIR)\JDFLongSlit.sbr" \
	"$(INTDIR)\JDFLZWParams.sbr" \
	"$(INTDIR)\JDFMarkObject.sbr" \
	"$(INTDIR)\JDFNumberingParam.sbr" \
	"$(INTDIR)\JDFPageCell.sbr" \
	"$(INTDIR)\JDFPageData.sbr" \
	"$(INTDIR)\JDFPDFInterpretingParams.sbr" \
	"$(INTDIR)\JDFPDFXParams.sbr" \
	"$(INTDIR)\JDFPerforate.sbr" \
	"$(INTDIR)\JDFPixelColorant.sbr" \
	"$(INTDIR)\JDFPosition.sbr" \
	"$(INTDIR)\JDFPreflightAction.sbr" \
	"$(INTDIR)\JDFPreflightArgument.sbr" \
	"$(INTDIR)\JDFPreflightConstraint.sbr" \
	"$(INTDIR)\JDFPreflightDetail.sbr" \
	"$(INTDIR)\JDFPreflightInstance.sbr" \
	"$(INTDIR)\JDFPreflightInstanceDetail.sbr" \
	"$(INTDIR)\JDFPreflightValue.sbr" \
	"$(INTDIR)\JDFPRError.sbr" \
	"$(INTDIR)\JDFPRGroup.sbr" \
	"$(INTDIR)\JDFPrintConditionColor.sbr" \
	"$(INTDIR)\JDFPRItem.sbr" \
	"$(INTDIR)\JDFPROccurence.sbr" \
	"$(INTDIR)\JDFProperties.sbr" \
	"$(INTDIR)\JDFPRRule.sbr" \
	"$(INTDIR)\JDFPRRuleAttr.sbr" \
	"$(INTDIR)\JDFQualityMeasurement.sbr" \
	"$(INTDIR)\JDFResourceParam.sbr" \
	"$(INTDIR)\JDFScore.sbr" \
	"$(INTDIR)\JDFScreenSelector.sbr" \
	"$(INTDIR)\JDFShapeElement.sbr" \
	"$(INTDIR)\JDFSignature.sbr" \
	"$(INTDIR)\JDFSignatureCell.sbr" \
	"$(INTDIR)\JDFStringListValue.sbr" \
	"$(INTDIR)\JDFStripCellParams.sbr" \
	"$(INTDIR)\JDFThinPDFParams.sbr" \
	"$(INTDIR)\JDFTIFFEmbeddedFile.sbr" \
	"$(INTDIR)\JDFTIFFFormatParams.sbr" \
	"$(INTDIR)\JDFTIFFtag.sbr" \
	"$(INTDIR)\JDFTransferCurveSet.sbr" \
	"$(INTDIR)\JDFTrappingOrder.sbr" \
	"$(INTDIR)\JDFAction.sbr" \
	"$(INTDIR)\JDFActionPool.sbr" \
	"$(INTDIR)\JDFand.sbr" \
	"$(INTDIR)\JDFBooleanEvaluation.sbr" \
	"$(INTDIR)\JDFBooleanState.sbr" \
	"$(INTDIR)\JDFcall.sbr" \
	"$(INTDIR)\JDFchoice.sbr" \
	"$(INTDIR)\JDFDateTimeEvaluation.sbr" \
	"$(INTDIR)\JDFDateTimeState.sbr" \
	"$(INTDIR)\JDFDevCap.sbr" \
	"$(INTDIR)\JDFDevCaps.sbr" \
	"$(INTDIR)\JDFDeviceCap.sbr" \
	"$(INTDIR)\JDFDisplayGroup.sbr" \
	"$(INTDIR)\JDFDisplayGroupPool.sbr" \
	"$(INTDIR)\JDFDurationEvaluation.sbr" \
	"$(INTDIR)\JDFDurationState.sbr" \
	"$(INTDIR)\JDFEnumerationEvaluation.sbr" \
	"$(INTDIR)\JDFEnumerationState.sbr" \
	"$(INTDIR)\JDFEvaluation.sbr" \
	"$(INTDIR)\JDFFeatureAttribute.sbr" \
	"$(INTDIR)\JDFFeaturePool.sbr" \
	"$(INTDIR)\JDFIntegerEvaluation.sbr" \
	"$(INTDIR)\JDFIntegerState.sbr" \
	"$(INTDIR)\JDFIsPresentEvaluation.sbr" \
	"$(INTDIR)\JDFLoc.sbr" \
	"$(INTDIR)\JDFmacro.sbr" \
	"$(INTDIR)\JDFMacroPool.sbr" \
	"$(INTDIR)\JDFMatrixEvaluation.sbr" \
	"$(INTDIR)\JDFMatrixState.sbr" \
	"$(INTDIR)\JDFNameEvaluation.sbr" \
	"$(INTDIR)\JDFNameState.sbr" \
	"$(INTDIR)\JDFnot.sbr" \
	"$(INTDIR)\JDFNumberEvaluation.sbr" \
	"$(INTDIR)\JDFNumberState.sbr" \
	"$(INTDIR)\JDFor.sbr" \
	"$(INTDIR)\JDFotherwise.sbr" \
	"$(INTDIR)\JDFPDFPathEvaluation.sbr" \
	"$(INTDIR)\JDFPDFPathState.sbr" \
	"$(INTDIR)\JDFPerformance.sbr" \
	"$(INTDIR)\JDFRectangleEvaluation.sbr" \
	"$(INTDIR)\JDFRectangleState.sbr" \
	"$(INTDIR)\JDFset.sbr" \
	"$(INTDIR)\JDFShapeEvaluation.sbr" \
	"$(INTDIR)\JDFShapeState.sbr" \
	"$(INTDIR)\JDFState.sbr" \
	"$(INTDIR)\JDFStringEvaluation.sbr" \
	"$(INTDIR)\JDFStringState.sbr" \
	"$(INTDIR)\JDFTest.sbr" \
	"$(INTDIR)\JDFTestPool.sbr" \
	"$(INTDIR)\JDFTestRef.sbr" \
	"$(INTDIR)\JDFValue.sbr" \
	"$(INTDIR)\JDFValueLoc.sbr" \
	"$(INTDIR)\JDFwhen.sbr" \
	"$(INTDIR)\JDFxor.sbr" \
	"$(INTDIR)\JDFXYPairEvaluation.sbr" \
	"$(INTDIR)\JDFXYPairState.sbr" \
	"$(INTDIR)\JDFDoc.sbr" \
	"$(INTDIR)\JDFElement.sbr" \
	"$(INTDIR)\JDFFactory.sbr" \
	"$(INTDIR)\JDFNodeFactory.sbr" \
	"$(INTDIR)\JDFParamsFactory.sbr" \
	"$(INTDIR)\JDFPool.sbr" \
	"$(INTDIR)\JDFRefElement.sbr" \
	"$(INTDIR)\JDFResource.sbr" \
	"$(INTDIR)\JDFResourceLink.sbr" \
	"$(INTDIR)\JDFRunElement.sbr" \
	"$(INTDIR)\JDFSeparationList.sbr" \
	"$(INTDIR)\JDFStrings.sbr" \
	"$(INTDIR)\JDFAutoAmountPool.sbr" \
	"$(INTDIR)\JDFAutoAncestor.sbr" \
	"$(INTDIR)\JDFAutoAncestorPool.sbr" \
	"$(INTDIR)\JDFAutoBarcode.sbr" \
	"$(INTDIR)\JDFAutoBusinessInfo.sbr" \
	"$(INTDIR)\JDFAutoComment.sbr" \
	"$(INTDIR)\JDFAutoCounterReset.sbr" \
	"$(INTDIR)\JDFAutoCreated.sbr" \
	"$(INTDIR)\JDFAutoCustomerInfo.sbr" \
	"$(INTDIR)\JDFAutoCustomerMessage.sbr" \
	"$(INTDIR)\JDFAutoDeleted.sbr" \
	"$(INTDIR)\JDFAutoError.sbr" \
	"$(INTDIR)\JDFAutoEvent.sbr" \
	"$(INTDIR)\JDFAutoFCNKey.sbr" \
	"$(INTDIR)\JDFAutoLocation.sbr" \
	"$(INTDIR)\JDFAutoMerged.sbr" \
	"$(INTDIR)\JDFAutoModified.sbr" \
	"$(INTDIR)\JDFAutoModulePhase.sbr" \
	"$(INTDIR)\JDFAutoNodeInfo.sbr" \
	"$(INTDIR)\JDFAutoNotification.sbr" \
	"$(INTDIR)\JDFAutoPart.sbr" \
	"$(INTDIR)\JDFAutoPartStatus.sbr" \
	"$(INTDIR)\JDFAutoPhaseTime.sbr" \
	"$(INTDIR)\JDFAutoProcessRun.sbr" \
	"$(INTDIR)\JDFAutoResourceAudit.sbr" \
	"$(INTDIR)\JDFAutoSpawned.sbr" \
	"$(INTDIR)\JDFAutoStatusPool.sbr" \
	"$(INTDIR)\JDFAutoSystemTimeSet.sbr" \
	"$(INTDIR)\JDFAutoAcknowledge.sbr" \
	"$(INTDIR)\JDFAutoAdded.sbr" \
	"$(INTDIR)\JDFAutoChangedAttribute.sbr" \
	"$(INTDIR)\JDFAutoChangedPath.sbr" \
	"$(INTDIR)\JDFAutoCommand.sbr" \
	"$(INTDIR)\JDFAutoDeviceFilter.sbr" \
	"$(INTDIR)\JDFAutoDeviceInfo.sbr" \
	"$(INTDIR)\JDFAutoDeviceList.sbr" \
	"$(INTDIR)\JDFAutoEmployeeDef.sbr" \
	"$(INTDIR)\JDFAutoFlushedResources.sbr" \
	"$(INTDIR)\JDFAutoFlushQueueParams.sbr" \
	"$(INTDIR)\JDFAutoFlushResourceParams.sbr" \
	"$(INTDIR)\JDFAutoIDInfo.sbr" \
	"$(INTDIR)\JDFAutoJDFController.sbr" \
	"$(INTDIR)\JDFAutoJDFService.sbr" \
	"$(INTDIR)\JDFAutoJMF.sbr" \
	"$(INTDIR)\JDFAutoJobPhase.sbr" \
	"$(INTDIR)\JDFAutoKnownMsgQuParams.sbr" \
	"$(INTDIR)\JDFAutoMessage.sbr" \
	"$(INTDIR)\JDFAutoMessageService.sbr" \
	"$(INTDIR)\JDFAutoModuleStatus.sbr" \
	"$(INTDIR)\JDFAutoMsgFilter.sbr" \
	"$(INTDIR)\JDFAutoNewJDFCmdParams.sbr" \
	"$(INTDIR)\JDFAutoNewJDFQuParams.sbr" \
	"$(INTDIR)\JDFAutoNodeInfoCmdParams.sbr" \
	"$(INTDIR)\JDFAutoNodeInfoQuParams.sbr" \
	"$(INTDIR)\JDFAutoNodeInfoResp.sbr" \
	"$(INTDIR)\JDFAutoNotificationDef.sbr" \
	"$(INTDIR)\JDFAutoNotificationFilter.sbr" \
	"$(INTDIR)\JDFAutoObservationTarget.sbr" \
	"$(INTDIR)\JDFAutoOccupation.sbr" \
	"$(INTDIR)\JDFAutoPipeParams.sbr" \
	"$(INTDIR)\JDFAutoQuery.sbr" \
	"$(INTDIR)\JDFAutoQueue.sbr" \
	"$(INTDIR)\JDFAutoQueueEntry.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryDef.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryDefList.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryPosParams.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryPriParams.sbr" \
	"$(INTDIR)\JDFAutoQueueFilter.sbr" \
	"$(INTDIR)\JDFAutoQueueSubmissionParams.sbr" \
	"$(INTDIR)\JDFAutoRemoved.sbr" \
	"$(INTDIR)\JDFAutoRequestQueueEntryParams.sbr" \
	"$(INTDIR)\JDFAutoResourceCmdParams.sbr" \
	"$(INTDIR)\JDFAutoResourceInfo.sbr" \
	"$(INTDIR)\JDFAutoResourcePullParams.sbr" \
	"$(INTDIR)\JDFAutoResourceQuParams.sbr" \
	"$(INTDIR)\JDFAutoResponse.sbr" \
	"$(INTDIR)\JDFAutoResubmissionParams.sbr" \
	"$(INTDIR)\JDFAutoReturnQueueEntryParams.sbr" \
	"$(INTDIR)\JDFAutoShutDownCmdParams.sbr" \
	"$(INTDIR)\JDFAutoSignal.sbr" \
	"$(INTDIR)\JDFAutoStatusQuParams.sbr" \
	"$(INTDIR)\JDFAutoStopPersChParams.sbr" \
	"$(INTDIR)\JDFAutoSubmissionMethods.sbr" \
	"$(INTDIR)\JDFAutoSubscription.sbr" \
	"$(INTDIR)\JDFAutoTrackFilter.sbr" \
	"$(INTDIR)\JDFAutoTrackResult.sbr" \
	"$(INTDIR)\JDFAutoTrigger.sbr" \
	"$(INTDIR)\JDFAutoWakeUpCmdParams.sbr" \
	"$(INTDIR)\JDFAutoArtDeliveryIntent.sbr" \
	"$(INTDIR)\JDFAutoBindingIntent.sbr" \
	"$(INTDIR)\JDFAutoColorIntent.sbr" \
	"$(INTDIR)\JDFAutoDeliveryIntent.sbr" \
	"$(INTDIR)\JDFAutoEmbossingIntent.sbr" \
	"$(INTDIR)\JDFAutoFoldingIntent.sbr" \
	"$(INTDIR)\JDFAutoHoleMakingIntent.sbr" \
	"$(INTDIR)\JDFAutoInsertingIntent.sbr" \
	"$(INTDIR)\JDFAutoLaminatingIntent.sbr" \
	"$(INTDIR)\JDFAutoLayoutIntent.sbr" \
	"$(INTDIR)\JDFAutoMediaIntent.sbr" \
	"$(INTDIR)\JDFAutoNumberingIntent.sbr" \
	"$(INTDIR)\JDFAutoPackingIntent.sbr" \
	"$(INTDIR)\JDFAutoProductionIntent.sbr" \
	"$(INTDIR)\JDFAutoProofingIntent.sbr" \
	"$(INTDIR)\JDFAutoScreeningIntent.sbr" \
	"$(INTDIR)\JDFAutoShapeCuttingIntent.sbr" \
	"$(INTDIR)\JDFAutoSizeIntent.sbr" \
	"$(INTDIR)\JDFAutoAdhesiveBinding.sbr" \
	"$(INTDIR)\JDFAutoArtDelivery.sbr" \
	"$(INTDIR)\JDFAutoBindItem.sbr" \
	"$(INTDIR)\JDFAutoBindList.sbr" \
	"$(INTDIR)\JDFAutoBookCase.sbr" \
	"$(INTDIR)\JDFAutoChannelBinding.sbr" \
	"$(INTDIR)\JDFAutoCoilBinding.sbr" \
	"$(INTDIR)\JDFAutoColorsUsed.sbr" \
	"$(INTDIR)\JDFAutoCreditCard.sbr" \
	"$(INTDIR)\JDFAutoDropIntent.sbr" \
	"$(INTDIR)\JDFAutoDropItemIntent.sbr" \
	"$(INTDIR)\JDFAutoEdgeGluing.sbr" \
	"$(INTDIR)\JDFAutoEmbossingItem.sbr" \
	"$(INTDIR)\JDFAutoHardCoverBinding.sbr" \
	"$(INTDIR)\JDFAutoHoleList.sbr" \
	"$(INTDIR)\JDFAutoInsert.sbr" \
	"$(INTDIR)\JDFAutoInsertList.sbr" \
	"$(INTDIR)\JDFAutoNumberItem.sbr" \
	"$(INTDIR)\JDFAutoPayment.sbr" \
	"$(INTDIR)\JDFAutoPlasticCombBinding.sbr" \
	"$(INTDIR)\JDFAutoPricing.sbr" \
	"$(INTDIR)\JDFAutoProofItem.sbr" \
	"$(INTDIR)\JDFAutoRingBinding.sbr" \
	"$(INTDIR)\JDFAutoSaddleStitching.sbr" \
	"$(INTDIR)\JDFAutoShapeCut.sbr" \
	"$(INTDIR)\JDFAutoSideSewing.sbr" \
	"$(INTDIR)\JDFAutoSideStitching.sbr" \
	"$(INTDIR)\JDFAutoSoftCoverBinding.sbr" \
	"$(INTDIR)\JDFAutoStripBinding.sbr" \
	"$(INTDIR)\JDFAutoTabs.sbr" \
	"$(INTDIR)\JDFAutoTape.sbr" \
	"$(INTDIR)\JDFAutoThreadSealing.sbr" \
	"$(INTDIR)\JDFAutoThreadSewing.sbr" \
	"$(INTDIR)\JDFAutoWireCombBinding.sbr" \
	"$(INTDIR)\JDFAutoAddress.sbr" \
	"$(INTDIR)\JDFAutoAdhesiveBindingParams.sbr" \
	"$(INTDIR)\JDFAutoApprovalParams.sbr" \
	"$(INTDIR)\JDFAutoApprovalSuccess.sbr" \
	"$(INTDIR)\JDFAutoAssembly.sbr" \
	"$(INTDIR)\JDFAutoAssetListCreationParams.sbr" \
	"$(INTDIR)\JDFAutoAutomatedOverprintParams.sbr" \
	"$(INTDIR)\JDFAutoBinderySignature.sbr" \
	"$(INTDIR)\JDFAutoBlockPreparationParams.sbr" \
	"$(INTDIR)\JDFAutoBoxPackingParams.sbr" \
	"$(INTDIR)\JDFAutoBufferParams.sbr" \
	"$(INTDIR)\JDFAutoBundle.sbr" \
	"$(INTDIR)\JDFAutoBundlingParams.sbr" \
	"$(INTDIR)\JDFAutoByteMap.sbr" \
	"$(INTDIR)\JDFAutoCaseMakingParams.sbr" \
	"$(INTDIR)\JDFAutoCasingInParams.sbr" \
	"$(INTDIR)\JDFAutoChannelBindingParams.sbr" \
	"$(INTDIR)\JDFAutoCIELABMeasuringField.sbr" \
	"$(INTDIR)\JDFAutoCoilBindingParams.sbr" \
	"$(INTDIR)\JDFAutoCollectingParams.sbr" \
	"$(INTDIR)\JDFAutoColor.sbr" \
	"$(INTDIR)\JDFAutoColorantAlias.sbr" \
	"$(INTDIR)\JDFAutoColorantControl.sbr" \
	"$(INTDIR)\JDFAutoColorControlStrip.sbr" \
	"$(INTDIR)\JDFAutoColorCorrectionParams.sbr" \
	"$(INTDIR)\JDFAutoColorMeasurementConditions.sbr" \
	"$(INTDIR)\JDFAutoColorPool.sbr" \
	"$(INTDIR)\JDFAutoColorSpaceConversionOp.sbr" \
	"$(INTDIR)\JDFAutoColorSpaceConversionParams.sbr" \
	"$(INTDIR)\JDFAutoComChannel.sbr" \
	"$(INTDIR)\JDFAutoCompany.sbr" \
	"$(INTDIR)\JDFAutoComponent.sbr" \
	"$(INTDIR)\JDFAutoContact.sbr" \
	"$(INTDIR)\JDFAutoContactCopyParams.sbr" \
	"$(INTDIR)\JDFAutoConventionalPrintingParams.sbr" \
	"$(INTDIR)\JDFAutoCostCenter.sbr" \
	"$(INTDIR)\JDFAutoCoverApplicationParams.sbr" \
	"$(INTDIR)\JDFAutoCreasingParams.sbr" \
	"$(INTDIR)\JDFAutoCutBlock.sbr" \
	"$(INTDIR)\JDFAutoCutMark.sbr" \
	"$(INTDIR)\JDFAutoCuttingParams.sbr" \
	"$(INTDIR)\JDFAutoDBMergeParams.sbr" \
	"$(INTDIR)\JDFAutoDBRules.sbr" \
	"$(INTDIR)\JDFAutoDBSchema.sbr" \
	"$(INTDIR)\JDFAutoDBSelection.sbr" \
	"$(INTDIR)\JDFAutoDeliveryParams.sbr" \
	"$(INTDIR)\JDFAutoDensityMeasuringField.sbr" \
	"$(INTDIR)\JDFAutoDevelopingParams.sbr" \
	"$(INTDIR)\JDFAutoDevice.sbr" \
	"$(INTDIR)\JDFAutoDeviceMark.sbr" \
	"$(INTDIR)\JDFAutoDeviceNSpace.sbr" \
	"$(INTDIR)\JDFAutoDigitalDeliveryParams.sbr" \
	"$(INTDIR)\JDFAutoDigitalMedia.sbr" \
	"$(INTDIR)\JDFAutoDigitalPrintingParams.sbr" \
	"$(INTDIR)\JDFAutoDisjointing.sbr" \
	"$(INTDIR)\JDFAutoDisposition.sbr" \
	"$(INTDIR)\JDFAutoDividingParams.sbr" \
	"$(INTDIR)\JDFAutoElementColorParams.sbr" \
	"$(INTDIR)\JDFAutoEmbossingParams.sbr" \
	"$(INTDIR)\JDFAutoEmployee.sbr" \
	"$(INTDIR)\JDFAutoEndSheetGluingParams.sbr" \
	"$(INTDIR)\JDFAutoExposedMedia.sbr" \
	"$(INTDIR)\JDFAutoFeedingParams.sbr" \
	"$(INTDIR)\JDFAutoFileSpec.sbr" \
	"$(INTDIR)\JDFAutoFitPolicy.sbr" \
	"$(INTDIR)\JDFAutoFold.sbr" \
	"$(INTDIR)\JDFAutoFoldingParams.sbr" \
	"$(INTDIR)\JDFAutoFontParams.sbr" \
	"$(INTDIR)\JDFAutoFontPolicy.sbr" \
	"$(INTDIR)\JDFAutoFormatConversionParams.sbr" \
	"$(INTDIR)\JDFAutoGatheringParams.sbr" \
	"$(INTDIR)\JDFAutoGlueApplication.sbr" \
	"$(INTDIR)\JDFAutoGlueLine.sbr" \
	"$(INTDIR)\JDFAutoGluingParams.sbr" \
	"$(INTDIR)\JDFAutoHeadBandApplicationParams.sbr" \
	"$(INTDIR)\JDFAutoHole.sbr" \
	"$(INTDIR)\JDFAutoHoleLine.sbr" \
	"$(INTDIR)\JDFAutoHoleMakingParams.sbr" \
	"$(INTDIR)\JDFAutoIdentificationField.sbr" \
	"$(INTDIR)\JDFAutoIDPrintingParams.sbr" \
	"$(INTDIR)\JDFAutoImageCompressionParams.sbr" \
	"$(INTDIR)\JDFAutoImageReplacementParams.sbr" \
	"$(INTDIR)\JDFAutoImageSetterParams.sbr" \
	"$(INTDIR)\JDFAutoInk.sbr" \
	"$(INTDIR)\JDFAutoInkZoneCalculationParams.sbr" \
	"$(INTDIR)\JDFAutoInkZoneProfile.sbr" \
	"$(INTDIR)\JDFAutoInsertingParams.sbr" \
	"$(INTDIR)\JDFAutoInsertSheet.sbr" \
	"$(INTDIR)\JDFAutoInterpretedPDLData.sbr" \
	"$(INTDIR)\JDFAutoInterpretingParams.sbr" \
	"$(INTDIR)\JDFAutoJacketingParams.sbr" \
	"$(INTDIR)\JDFAutoJobField.sbr" \
	"$(INTDIR)\JDFAutoLabelingParams.sbr" \
	"$(INTDIR)\JDFAutoLaminatingParams.sbr" \
	"$(INTDIR)\JDFAutoLayout.sbr" \
	"$(INTDIR)\JDFAutoLayoutElement.sbr" \
	"$(INTDIR)\JDFAutoLayoutPreparationParams.sbr" \
	"$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.sbr" \
	"$(INTDIR)\JDFAutoManualLaborParams.sbr" \
	"$(INTDIR)\JDFAutoMedia.sbr" \
	"$(INTDIR)\JDFAutoMediaSource.sbr" \
	"$(INTDIR)\JDFAutoMISDetails.sbr" \
	"$(INTDIR)\JDFAutoNumberingParams.sbr" \
	"$(INTDIR)\JDFAutoObjectResolution.sbr" \
	"$(INTDIR)\JDFAutoOrderingParams.sbr" \
	"$(INTDIR)\JDFAutoPackingParams.sbr" \
	"$(INTDIR)\JDFAutoPageList.sbr" \
	"$(INTDIR)\JDFAutoPallet.sbr" \
	"$(INTDIR)\JDFAutoPalletizingParams.sbr" \
	"$(INTDIR)\JDFAutoPDFToPSConversionParams.sbr" \
	"$(INTDIR)\JDFAutoPDLResourceAlias.sbr" \
	"$(INTDIR)\JDFAutoPerforatingParams.sbr" \
	"$(INTDIR)\JDFAutoPerson.sbr" \
	"$(INTDIR)\JDFAutoPlaceHolderResource.sbr" \
	"$(INTDIR)\JDFAutoPlasticCombBindingParams.sbr" \
	"$(INTDIR)\JDFAutoPlateCopyParams.sbr" \
	"$(INTDIR)\JDFAutoPreflightAnalysis.sbr" \
	"$(INTDIR)\JDFAutoPreflightInventory.sbr" \
	"$(INTDIR)\JDFAutoPreflightParams.sbr" \
	"$(INTDIR)\JDFAutoPreflightProfile.sbr" \
	"$(INTDIR)\JDFAutoPreflightReport.sbr" \
	"$(INTDIR)\JDFAutoPreflightReportRulePool.sbr" \
	"$(INTDIR)\JDFAutoPreview.sbr" \
	"$(INTDIR)\JDFAutoPreviewGenerationParams.sbr" \
	"$(INTDIR)\JDFAutoPrintCondition.sbr" \
	"$(INTDIR)\JDFAutoPrintRollingParams.sbr" \
	"$(INTDIR)\JDFAutoProofingParams.sbr" \
	"$(INTDIR)\JDFAutoPSToPDFConversionParams.sbr" \
	"$(INTDIR)\JDFAutoQualityControlParams.sbr" \
	"$(INTDIR)\JDFAutoQualityControlResult.sbr" \
	"$(INTDIR)\JDFAutoRegisterMark.sbr" \
	"$(INTDIR)\JDFAutoRegisterRibbon.sbr" \
	"$(INTDIR)\JDFAutoRenderingParams.sbr" \
	"$(INTDIR)\JDFAutoResourceDefinitionParams.sbr" \
	"$(INTDIR)\JDFAutoRingBindingParams.sbr" \
	"$(INTDIR)\JDFAutoRollStand.sbr" \
	"$(INTDIR)\JDFAutoRunList.sbr" \
	"$(INTDIR)\JDFAutoSaddleStitchingParams.sbr" \
	"$(INTDIR)\JDFAutoScanParams.sbr" \
	"$(INTDIR)\JDFAutoScavengerArea.sbr" \
	"$(INTDIR)\JDFAutoScreeningParams.sbr" \
	"$(INTDIR)\JDFAutoSeparationControlParams.sbr" \
	"$(INTDIR)\JDFAutoSeparationSpec.sbr" \
	"$(INTDIR)\JDFAutoShapeCuttingParams.sbr" \
	"$(INTDIR)\JDFAutoSheet.sbr" \
	"$(INTDIR)\JDFAutoShrinkingParams.sbr" \
	"$(INTDIR)\JDFAutoSideSewingParams.sbr" \
	"$(INTDIR)\JDFAutoSpinePreparationParams.sbr" \
	"$(INTDIR)\JDFAutoSpineTapingParams.sbr" \
	"$(INTDIR)\JDFAutoStackingParams.sbr" \
	"$(INTDIR)\JDFAutoStitchingParams.sbr" \
	"$(INTDIR)\JDFAutoStrap.sbr" \
	"$(INTDIR)\JDFAutoStrappingParams.sbr" \
	"$(INTDIR)\JDFAutoStripBindingParams.sbr" \
	"$(INTDIR)\JDFAutoStrippingParams.sbr" \
	"$(INTDIR)\JDFAutoSurface.sbr" \
	"$(INTDIR)\JDFAutoThreadSealingParams.sbr" \
	"$(INTDIR)\JDFAutoThreadSewingParams.sbr" \
	"$(INTDIR)\JDFAutoTile.sbr" \
	"$(INTDIR)\JDFAutoTool.sbr" \
	"$(INTDIR)\JDFAutoTransferCurve.sbr" \
	"$(INTDIR)\JDFAutoTransferCurvePool.sbr" \
	"$(INTDIR)\JDFAutoTransferFunctionControl.sbr" \
	"$(INTDIR)\JDFAutoTrappingDetails.sbr" \
	"$(INTDIR)\JDFAutoTrappingParams.sbr" \
	"$(INTDIR)\JDFAutoTrapRegion.sbr" \
	"$(INTDIR)\JDFAutoTrimmingParams.sbr" \
	"$(INTDIR)\JDFAutoVerificationParams.sbr" \
	"$(INTDIR)\JDFAutoWireCombBindingParams.sbr" \
	"$(INTDIR)\JDFAutoWrappingParams.sbr" \
	"$(INTDIR)\JDFArgumentValue.sbr" \
	"$(INTDIR)\JDFAutoAdvancedParams.sbr" \
	"$(INTDIR)\JDFAutoApprovalPerson.sbr" \
	"$(INTDIR)\JDFAutoArgumentValue.sbr" \
	"$(INTDIR)\JDFAutoAssemblySection.sbr" \
	"$(INTDIR)\JDFAutoBand.sbr" \
	"$(INTDIR)\JDFAutoBasicPreflightTest.sbr" \
	"$(INTDIR)\JDFAutoBindingQualityParams.sbr" \
	"$(INTDIR)\JDFAutoBoxArgument.sbr" \
	"$(INTDIR)\JDFAutoBoxToBoxDifference.sbr" \
	"$(INTDIR)\JDFAutoBundleItem.sbr" \
	"$(INTDIR)\JDFAutoCCITTFaxParams.sbr" \
	"$(INTDIR)\JDFAutoCollatingItem.sbr" \
	"$(INTDIR)\JDFAutoColorantZoneDetails.sbr" \
	"$(INTDIR)\JDFAutoColorCorrectionOp.sbr" \
	"$(INTDIR)\JDFAutoColorSpaceSubstitute.sbr" \
	"$(INTDIR)\JDFAutoContainer.sbr" \
	"$(INTDIR)\JDFAutoContentObject.sbr" \
	"$(INTDIR)\JDFAutoCrease.sbr" \
	"$(INTDIR)\JDFAutoCut.sbr" \
	"$(INTDIR)\JDFAutoDCTParams.sbr" \
	"$(INTDIR)\JDFAutoDependencies.sbr" \
	"$(INTDIR)\JDFAutoDeviceNColor.sbr" \
	"$(INTDIR)\JDFAutoDrop.sbr" \
	"$(INTDIR)\JDFAutoDropItem.sbr" \
	"$(INTDIR)\JDFAutoDynamicField.sbr" \
	"$(INTDIR)\JDFAutoDynamicInput.sbr" \
	"$(INTDIR)\JDFAutoEmboss.sbr" \
	"$(INTDIR)\JDFAutoEndSheet.sbr" \
	"$(INTDIR)\JDFAutoFeeder.sbr" \
	"$(INTDIR)\JDFAutoFeederQualityParams.sbr" \
	"$(INTDIR)\JDFAutoFileAlias.sbr" \
	"$(INTDIR)\JDFAutoFlateParams.sbr" \
	"$(INTDIR)\JDFAutoGlue.sbr" \
	"$(INTDIR)\JDFAutoIcon.sbr" \
	"$(INTDIR)\JDFAutoIconList.sbr" \
	"$(INTDIR)\JDFAutoIDPCover.sbr" \
	"$(INTDIR)\JDFAutoIDPFinishing.sbr" \
	"$(INTDIR)\JDFAutoIDPFolding.sbr" \
	"$(INTDIR)\JDFAutoIDPHoleMaking.sbr" \
	"$(INTDIR)\JDFAutoIDPImageShift.sbr" \
	"$(INTDIR)\JDFAutoIDPJobSheet.sbr" \
	"$(INTDIR)\JDFAutoIDPLayout.sbr" \
	"$(INTDIR)\JDFAutoIDPStitching.sbr" \
	"$(INTDIR)\JDFAutoIDPTrimming.sbr" \
	"$(INTDIR)\JDFAutoImageCompression.sbr" \
	"$(INTDIR)\JDFAutoImageShift.sbr" \
	"$(INTDIR)\JDFAutoLayerDetails.sbr" \
	"$(INTDIR)\JDFAutoLayerList.sbr" \
	"$(INTDIR)\JDFAutoLongFold.sbr" \
	"$(INTDIR)\JDFAutoLongGlue.sbr" \
	"$(INTDIR)\JDFAutoLongPerforate.sbr" \
	"$(INTDIR)\JDFAutoLongSlit.sbr" \
	"$(INTDIR)\JDFAutoLZWParams.sbr" \
	"$(INTDIR)\JDFAutoMarkObject.sbr" \
	"$(INTDIR)\JDFAutoNumberingParam.sbr" \
	"$(INTDIR)\JDFAutoPageCell.sbr" \
	"$(INTDIR)\JDFAutoPageData.sbr" \
	"$(INTDIR)\JDFAutoPDFInterpretingParams.sbr" \
	"$(INTDIR)\JDFAutoPDFXParams.sbr" \
	"$(INTDIR)\JDFAutoPerforate.sbr" \
	"$(INTDIR)\JDFAutoPixelColorant.sbr" \
	"$(INTDIR)\JDFAutoPosition.sbr" \
	"$(INTDIR)\JDFAutoPreflightAction.sbr" \
	"$(INTDIR)\JDFAutoPreflightArgument.sbr" \
	"$(INTDIR)\JDFAutoPreflightConstraint.sbr" \
	"$(INTDIR)\JDFAutoPreflightDetail.sbr" \
	"$(INTDIR)\JDFAutoPreflightInstance.sbr" \
	"$(INTDIR)\JDFAutoPreflightInstanceDetail.sbr" \
	"$(INTDIR)\JDFAutoPreflightValue.sbr" \
	"$(INTDIR)\JDFAutoPRError.sbr" \
	"$(INTDIR)\JDFAutoPRGroup.sbr" \
	"$(INTDIR)\JDFAutoPrintConditionColor.sbr" \
	"$(INTDIR)\JDFAutoPRItem.sbr" \
	"$(INTDIR)\JDFAutoPROccurence.sbr" \
	"$(INTDIR)\JDFAutoProperties.sbr" \
	"$(INTDIR)\JDFAutoPRRule.sbr" \
	"$(INTDIR)\JDFAutoPRRuleAttr.sbr" \
	"$(INTDIR)\JDFAutoQualityMeasurement.sbr" \
	"$(INTDIR)\JDFAutoResourceParam.sbr" \
	"$(INTDIR)\JDFAutoScore.sbr" \
	"$(INTDIR)\JDFAutoScreenSelector.sbr" \
	"$(INTDIR)\JDFAutoShapeElement.sbr" \
	"$(INTDIR)\JDFAutoSignature.sbr" \
	"$(INTDIR)\JDFAutoSignatureCell.sbr" \
	"$(INTDIR)\JDFAutoStringListValue.sbr" \
	"$(INTDIR)\JDFAutoStripCellParams.sbr" \
	"$(INTDIR)\JDFAutoThinPDFParams.sbr" \
	"$(INTDIR)\JDFAutoTIFFEmbeddedFile.sbr" \
	"$(INTDIR)\JDFAutoTIFFFormatParams.sbr" \
	"$(INTDIR)\JDFAutoTIFFtag.sbr" \
	"$(INTDIR)\JDFAutoTransferCurveSet.sbr" \
	"$(INTDIR)\JDFAutoTrappingOrder.sbr" \
	"$(INTDIR)\JDFAutoAction.sbr" \
	"$(INTDIR)\JDFAutoActionPool.sbr" \
	"$(INTDIR)\JDFAutoand.sbr" \
	"$(INTDIR)\JDFAutocall.sbr" \
	"$(INTDIR)\JDFAutochoice.sbr" \
	"$(INTDIR)\JDFAutoDevCap.sbr" \
	"$(INTDIR)\JDFAutoDevCaps.sbr" \
	"$(INTDIR)\JDFAutoDeviceCap.sbr" \
	"$(INTDIR)\JDFAutoDisplayGroup.sbr" \
	"$(INTDIR)\JDFAutoDisplayGroupPool.sbr" \
	"$(INTDIR)\JDFAutoFeatureAttribute.sbr" \
	"$(INTDIR)\JDFAutoFeaturePool.sbr" \
	"$(INTDIR)\JDFAutoLoc.sbr" \
	"$(INTDIR)\JDFAutomacro.sbr" \
	"$(INTDIR)\JDFAutoMacroPool.sbr" \
	"$(INTDIR)\JDFAutonot.sbr" \
	"$(INTDIR)\JDFAutoor.sbr" \
	"$(INTDIR)\JDFAutootherwise.sbr" \
	"$(INTDIR)\JDFAutoPerformance.sbr" \
	"$(INTDIR)\JDFAutoset.sbr" \
	"$(INTDIR)\JDFAutoTest.sbr" \
	"$(INTDIR)\JDFAutoTestPool.sbr" \
	"$(INTDIR)\JDFAutoTestRef.sbr" \
	"$(INTDIR)\JDFAutoValue.sbr" \
	"$(INTDIR)\JDFAutoValueLoc.sbr" \
	"$(INTDIR)\JDFAutowhen.sbr" \
	"$(INTDIR)\JDFAutoxor.sbr" \
	"$(INTDIR)\JDFAutoEnumerationSpan.sbr" \
	"$(INTDIR)\JDFAutoPRGroupOccurence.sbr" \
	"$(INTDIR)\JDFAutoPRGroupOccurenceBase.sbr" \
	"$(INTDIR)\JDFPreflightConstraintsPool.sbr" \
	"$(INTDIR)\JDFPreflightResultsPool.sbr" \
	"$(INTDIR)\JDFPRGroupOccurence.sbr" \
	"$(INTDIR)\JDFPRGroupOccurenceBase.sbr" \
	"$(INTDIR)\JDFDateTimeRange.sbr" \
	"$(INTDIR)\JDFDateTimeRangeList.sbr" \
	"$(INTDIR)\JDFDurationRange.sbr" \
	"$(INTDIR)\JDFDurationRangeList.sbr" \
	"$(INTDIR)\JDFIntegerRange.sbr" \
	"$(INTDIR)\JDFIntegerRangeList.sbr" \
	"$(INTDIR)\JDFNameRangeList.sbr" \
	"$(INTDIR)\JDFNumberRangeList.sbr" \
	"$(INTDIR)\JDFNumTypeList.sbr" \
	"$(INTDIR)\JDFParser.sbr" \
	"$(INTDIR)\JDFRange.sbr" \
	"$(INTDIR)\JDFRangeList.sbr" \
	"$(INTDIR)\JDFXYPairRangeList.sbr" \
	"$(INTDIR)\KElement.sbr" \
	"$(INTDIR)\KElementStrings.sbr" \
	"$(INTDIR)\MyDate.sbr" \
	"$(INTDIR)\vElement.sbr" \
	"$(INTDIR)\XMLDoc.sbr" \
	"$(INTDIR)\XMLDocUserData.sbr"

"$(OUTDIR)\JDFWrapperLib.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=xilink6.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\JDFWrapperDLLd.pdb" /map:"$(INTDIR)\JDFWrapperDLLd.map" /debug /machine:I386 /nodefaultlib:"libcmtd.lib" /nodefaultlib:"libcpmtd.lib" /nodefaultlib:"libcd.lib" /nodefaultlib:"libc.lib" /out:"$(OUTDIR)\JDFWrapperDLLd.dll" /implib:"$(OUTDIR)\JDFWrapperDLLd.lib" /pdbtype:sept /libpath:"..\..\..\external\stlport\lib" 
LINK32_OBJS= \
	"$(INTDIR)\JDFAmountPool.obj" \
	"$(INTDIR)\JDFAncestor.obj" \
	"$(INTDIR)\JDFAncestorPool.obj" \
	"$(INTDIR)\JDFAudit.obj" \
	"$(INTDIR)\JDFAuditPool.obj" \
	"$(INTDIR)\JDFBarcode.obj" \
	"$(INTDIR)\JDFBusinessInfo.obj" \
	"$(INTDIR)\JDFComment.obj" \
	"$(INTDIR)\JDFCounterReset.obj" \
	"$(INTDIR)\JDFCreated.obj" \
	"$(INTDIR)\JDFCustomerInfo.obj" \
	"$(INTDIR)\JDFCustomerMessage.obj" \
	"$(INTDIR)\JDFDeleted.obj" \
	"$(INTDIR)\JDFError.obj" \
	"$(INTDIR)\JDFEvent.obj" \
	"$(INTDIR)\JDFFCNKey.obj" \
	"$(INTDIR)\JDFLocation.obj" \
	"$(INTDIR)\JDFMerged.obj" \
	"$(INTDIR)\JDFModified.obj" \
	"$(INTDIR)\JDFModulePhase.obj" \
	"$(INTDIR)\JDFNode.obj" \
	"$(INTDIR)\JDFNodeInfo.obj" \
	"$(INTDIR)\JDFNotification.obj" \
	"$(INTDIR)\JDFPart.obj" \
	"$(INTDIR)\JDFPartAmount.obj" \
	"$(INTDIR)\JDFPartStatus.obj" \
	"$(INTDIR)\JDFPhaseTime.obj" \
	"$(INTDIR)\JDFProcessRun.obj" \
	"$(INTDIR)\JDFResourceAudit.obj" \
	"$(INTDIR)\JDFResourceLinkPool.obj" \
	"$(INTDIR)\JDFResourcePool.obj" \
	"$(INTDIR)\JDFSpawned.obj" \
	"$(INTDIR)\JDFStatusPool.obj" \
	"$(INTDIR)\JDFSystemTimeSet.obj" \
	"$(INTDIR)\JDFAcknowledge.obj" \
	"$(INTDIR)\JDFAdded.obj" \
	"$(INTDIR)\JDFChangedAttribute.obj" \
	"$(INTDIR)\JDFChangedPath.obj" \
	"$(INTDIR)\JDFCommand.obj" \
	"$(INTDIR)\JDFDeviceFilter.obj" \
	"$(INTDIR)\JDFDeviceInfo.obj" \
	"$(INTDIR)\JDFDeviceList.obj" \
	"$(INTDIR)\JDFEmployeeDef.obj" \
	"$(INTDIR)\JDFFlushedResources.obj" \
	"$(INTDIR)\JDFFlushQueueParams.obj" \
	"$(INTDIR)\JDFFlushResourceParams.obj" \
	"$(INTDIR)\JDFIDInfo.obj" \
	"$(INTDIR)\JDFJDFController.obj" \
	"$(INTDIR)\JDFJDFService.obj" \
	"$(INTDIR)\JDFJMF.obj" \
	"$(INTDIR)\JDFJobPhase.obj" \
	"$(INTDIR)\JDFKnownMsgQuParams.obj" \
	"$(INTDIR)\JDFMessage.obj" \
	"$(INTDIR)\JDFMessageElement.obj" \
	"$(INTDIR)\JDFMessageService.obj" \
	"$(INTDIR)\JDFModuleStatus.obj" \
	"$(INTDIR)\JDFMsgFilter.obj" \
	"$(INTDIR)\JDFNewJDFCmdParams.obj" \
	"$(INTDIR)\JDFNewJDFQuParams.obj" \
	"$(INTDIR)\JDFNodeInfoCmdParams.obj" \
	"$(INTDIR)\JDFNodeInfoQuParams.obj" \
	"$(INTDIR)\JDFNodeInfoResp.obj" \
	"$(INTDIR)\JDFNotificationDef.obj" \
	"$(INTDIR)\JDFNotificationFilter.obj" \
	"$(INTDIR)\JDFObservationTarget.obj" \
	"$(INTDIR)\JDFOccupation.obj" \
	"$(INTDIR)\JDFPipeParams.obj" \
	"$(INTDIR)\JDFQuery.obj" \
	"$(INTDIR)\JDFQueue.obj" \
	"$(INTDIR)\JDFQueueEntry.obj" \
	"$(INTDIR)\JDFQueueEntryDef.obj" \
	"$(INTDIR)\JDFQueueEntryDefList.obj" \
	"$(INTDIR)\JDFQueueEntryPosParams.obj" \
	"$(INTDIR)\JDFQueueEntryPriParams.obj" \
	"$(INTDIR)\JDFQueueFilter.obj" \
	"$(INTDIR)\JDFQueueSubmissionParams.obj" \
	"$(INTDIR)\JDFRemoved.obj" \
	"$(INTDIR)\JDFRequestQueueEntryParams.obj" \
	"$(INTDIR)\JDFResourceCmdParams.obj" \
	"$(INTDIR)\JDFResourceInfo.obj" \
	"$(INTDIR)\JDFResourcePullParams.obj" \
	"$(INTDIR)\JDFResourceQuParams.obj" \
	"$(INTDIR)\JDFResponse.obj" \
	"$(INTDIR)\JDFResubmissionParams.obj" \
	"$(INTDIR)\JDFReturnQueueEntryParams.obj" \
	"$(INTDIR)\JDFShutDownCmdParams.obj" \
	"$(INTDIR)\JDFSignal.obj" \
	"$(INTDIR)\JDFStatusQuParams.obj" \
	"$(INTDIR)\JDFStopPersChParams.obj" \
	"$(INTDIR)\JDFSubmissionMethods.obj" \
	"$(INTDIR)\JDFSubscription.obj" \
	"$(INTDIR)\JDFTrackFilter.obj" \
	"$(INTDIR)\JDFTrackResult.obj" \
	"$(INTDIR)\JDFTrigger.obj" \
	"$(INTDIR)\JDFWakeUpCmdParams.obj" \
	"$(INTDIR)\JDFArtDeliveryIntent.obj" \
	"$(INTDIR)\JDFBindingIntent.obj" \
	"$(INTDIR)\JDFColorIntent.obj" \
	"$(INTDIR)\JDFDeliveryIntent.obj" \
	"$(INTDIR)\JDFEmbossingIntent.obj" \
	"$(INTDIR)\JDFFoldingIntent.obj" \
	"$(INTDIR)\JDFHoleMakingIntent.obj" \
	"$(INTDIR)\JDFInsertingIntent.obj" \
	"$(INTDIR)\JDFIntentResource.obj" \
	"$(INTDIR)\JDFLaminatingIntent.obj" \
	"$(INTDIR)\JDFLayoutIntent.obj" \
	"$(INTDIR)\JDFMediaIntent.obj" \
	"$(INTDIR)\JDFNumberingIntent.obj" \
	"$(INTDIR)\JDFPackingIntent.obj" \
	"$(INTDIR)\JDFProductionIntent.obj" \
	"$(INTDIR)\JDFProofingIntent.obj" \
	"$(INTDIR)\JDFScreeningIntent.obj" \
	"$(INTDIR)\JDFShapeCuttingIntent.obj" \
	"$(INTDIR)\JDFSizeIntent.obj" \
	"$(INTDIR)\JDFSpan.obj" \
	"$(INTDIR)\JDFAdhesiveBinding.obj" \
	"$(INTDIR)\JDFArtDelivery.obj" \
	"$(INTDIR)\JDFBindItem.obj" \
	"$(INTDIR)\JDFBindList.obj" \
	"$(INTDIR)\JDFBookCase.obj" \
	"$(INTDIR)\JDFChannelBinding.obj" \
	"$(INTDIR)\JDFCoilBinding.obj" \
	"$(INTDIR)\JDFColorsUsed.obj" \
	"$(INTDIR)\JDFCreditCard.obj" \
	"$(INTDIR)\JDFDropIntent.obj" \
	"$(INTDIR)\JDFDropItemIntent.obj" \
	"$(INTDIR)\JDFEdgeGluing.obj" \
	"$(INTDIR)\JDFEmbossingItem.obj" \
	"$(INTDIR)\JDFHardCoverBinding.obj" \
	"$(INTDIR)\JDFHoleList.obj" \
	"$(INTDIR)\JDFInsert.obj" \
	"$(INTDIR)\JDFInsertList.obj" \
	"$(INTDIR)\JDFNumberItem.obj" \
	"$(INTDIR)\JDFPayment.obj" \
	"$(INTDIR)\JDFPlasticCombBinding.obj" \
	"$(INTDIR)\JDFPricing.obj" \
	"$(INTDIR)\JDFProofItem.obj" \
	"$(INTDIR)\JDFRingBinding.obj" \
	"$(INTDIR)\JDFSaddleStitching.obj" \
	"$(INTDIR)\JDFShapeCut.obj" \
	"$(INTDIR)\JDFSideSewing.obj" \
	"$(INTDIR)\JDFSideStitching.obj" \
	"$(INTDIR)\JDFSoftCoverBinding.obj" \
	"$(INTDIR)\JDFStripBinding.obj" \
	"$(INTDIR)\JDFTabs.obj" \
	"$(INTDIR)\JDFTape.obj" \
	"$(INTDIR)\JDFThreadSealing.obj" \
	"$(INTDIR)\JDFThreadSewing.obj" \
	"$(INTDIR)\JDFWireCombBinding.obj" \
	"$(INTDIR)\JDFAddress.obj" \
	"$(INTDIR)\JDFAdhesiveBindingParams.obj" \
	"$(INTDIR)\JDFApprovalParams.obj" \
	"$(INTDIR)\JDFApprovalSuccess.obj" \
	"$(INTDIR)\JDFAssembly.obj" \
	"$(INTDIR)\JDFAssetListCreationParams.obj" \
	"$(INTDIR)\JDFAutomatedOverprintParams.obj" \
	"$(INTDIR)\JDFBinderySignature.obj" \
	"$(INTDIR)\JDFBlockPreparationParams.obj" \
	"$(INTDIR)\JDFBoxPackingParams.obj" \
	"$(INTDIR)\JDFBufferParams.obj" \
	"$(INTDIR)\JDFBundle.obj" \
	"$(INTDIR)\JDFBundlingParams.obj" \
	"$(INTDIR)\JDFByteMap.obj" \
	"$(INTDIR)\JDFCaseMakingParams.obj" \
	"$(INTDIR)\JDFCasingInParams.obj" \
	"$(INTDIR)\JDFChannelBindingParams.obj" \
	"$(INTDIR)\JDFCIELABMeasuringField.obj" \
	"$(INTDIR)\JDFCoilBindingParams.obj" \
	"$(INTDIR)\JDFCollectingParams.obj" \
	"$(INTDIR)\JDFColor.obj" \
	"$(INTDIR)\JDFColorantAlias.obj" \
	"$(INTDIR)\JDFColorantControl.obj" \
	"$(INTDIR)\JDFColorControlStrip.obj" \
	"$(INTDIR)\JDFColorCorrectionParams.obj" \
	"$(INTDIR)\JDFColorMeasurementConditions.obj" \
	"$(INTDIR)\JDFColorPool.obj" \
	"$(INTDIR)\JDFColorSpaceConversionOp.obj" \
	"$(INTDIR)\JDFColorSpaceConversionParams.obj" \
	"$(INTDIR)\JDFComChannel.obj" \
	"$(INTDIR)\JDFCompany.obj" \
	"$(INTDIR)\JDFComponent.obj" \
	"$(INTDIR)\JDFContact.obj" \
	"$(INTDIR)\JDFContactCopyParams.obj" \
	"$(INTDIR)\JDFConventionalPrintingParams.obj" \
	"$(INTDIR)\JDFCostCenter.obj" \
	"$(INTDIR)\JDFCoverApplicationParams.obj" \
	"$(INTDIR)\JDFCreasingParams.obj" \
	"$(INTDIR)\JDFCutBlock.obj" \
	"$(INTDIR)\JDFCutMark.obj" \
	"$(INTDIR)\JDFCuttingParams.obj" \
	"$(INTDIR)\JDFDBMergeParams.obj" \
	"$(INTDIR)\JDFDBRules.obj" \
	"$(INTDIR)\JDFDBSchema.obj" \
	"$(INTDIR)\JDFDBSelection.obj" \
	"$(INTDIR)\JDFDeliveryParams.obj" \
	"$(INTDIR)\JDFDensityMeasuringField.obj" \
	"$(INTDIR)\JDFDevelopingParams.obj" \
	"$(INTDIR)\JDFDevice.obj" \
	"$(INTDIR)\JDFDeviceMark.obj" \
	"$(INTDIR)\JDFDeviceNSpace.obj" \
	"$(INTDIR)\JDFDigitalDeliveryParams.obj" \
	"$(INTDIR)\JDFDigitalMedia.obj" \
	"$(INTDIR)\JDFDigitalPrintingParams.obj" \
	"$(INTDIR)\JDFDisjointing.obj" \
	"$(INTDIR)\JDFDisposition.obj" \
	"$(INTDIR)\JDFDividingParams.obj" \
	"$(INTDIR)\JDFElementColorParams.obj" \
	"$(INTDIR)\JDFEmbossingParams.obj" \
	"$(INTDIR)\JDFEmployee.obj" \
	"$(INTDIR)\JDFEndSheetGluingParams.obj" \
	"$(INTDIR)\JDFExposedMedia.obj" \
	"$(INTDIR)\JDFFeedingParams.obj" \
	"$(INTDIR)\JDFFileSpec.obj" \
	"$(INTDIR)\JDFFitPolicy.obj" \
	"$(INTDIR)\JDFFold.obj" \
	"$(INTDIR)\JDFFoldingParams.obj" \
	"$(INTDIR)\JDFFontParams.obj" \
	"$(INTDIR)\JDFFontPolicy.obj" \
	"$(INTDIR)\JDFFormatConversionParams.obj" \
	"$(INTDIR)\JDFGatheringParams.obj" \
	"$(INTDIR)\JDFGlueApplication.obj" \
	"$(INTDIR)\JDFGlueLine.obj" \
	"$(INTDIR)\JDFGluingParams.obj" \
	"$(INTDIR)\JDFHeadBandApplicationParams.obj" \
	"$(INTDIR)\JDFHole.obj" \
	"$(INTDIR)\JDFHoleLine.obj" \
	"$(INTDIR)\JDFHoleMakingParams.obj" \
	"$(INTDIR)\JDFIdentificationField.obj" \
	"$(INTDIR)\JDFIDPrintingParams.obj" \
	"$(INTDIR)\JDFImageCompressionParams.obj" \
	"$(INTDIR)\JDFImageReplacementParams.obj" \
	"$(INTDIR)\JDFImageSetterParams.obj" \
	"$(INTDIR)\JDFInk.obj" \
	"$(INTDIR)\JDFInkZoneCalculationParams.obj" \
	"$(INTDIR)\JDFInkZoneProfile.obj" \
	"$(INTDIR)\JDFInsertingParams.obj" \
	"$(INTDIR)\JDFInsertSheet.obj" \
	"$(INTDIR)\JDFInterpretedPDLData.obj" \
	"$(INTDIR)\JDFInterpretingParams.obj" \
	"$(INTDIR)\JDFJacketingParams.obj" \
	"$(INTDIR)\JDFJobField.obj" \
	"$(INTDIR)\JDFLabelingParams.obj" \
	"$(INTDIR)\JDFLaminatingParams.obj" \
	"$(INTDIR)\JDFLayout.obj" \
	"$(INTDIR)\JDFLayoutElement.obj" \
	"$(INTDIR)\JDFLayoutPreparationParams.obj" \
	"$(INTDIR)\JDFLongitudinalRibbonOperationParams.obj" \
	"$(INTDIR)\JDFManualLaborParams.obj" \
	"$(INTDIR)\JDFMedia.obj" \
	"$(INTDIR)\JDFMediaSource.obj" \
	"$(INTDIR)\JDFMISDetails.obj" \
	"$(INTDIR)\JDFNumberingParams.obj" \
	"$(INTDIR)\JDFObjectResolution.obj" \
	"$(INTDIR)\JDFOrderingParams.obj" \
	"$(INTDIR)\JDFPackingParams.obj" \
	"$(INTDIR)\JDFPageList.obj" \
	"$(INTDIR)\JDFPallet.obj" \
	"$(INTDIR)\JDFPalletizingParams.obj" \
	"$(INTDIR)\JDFPDFToPSConversionParams.obj" \
	"$(INTDIR)\JDFPDLResourceAlias.obj" \
	"$(INTDIR)\JDFPerforatingParams.obj" \
	"$(INTDIR)\JDFPerson.obj" \
	"$(INTDIR)\JDFPlaceHolderResource.obj" \
	"$(INTDIR)\JDFPlasticCombBindingParams.obj" \
	"$(INTDIR)\JDFPlateCopyParams.obj" \
	"$(INTDIR)\JDFPreflightAnalysis.obj" \
	"$(INTDIR)\JDFPreflightInventory.obj" \
	"$(INTDIR)\JDFPreflightParams.obj" \
	"$(INTDIR)\JDFPreflightProfile.obj" \
	"$(INTDIR)\JDFPreflightReport.obj" \
	"$(INTDIR)\JDFPreflightReportRulePool.obj" \
	"$(INTDIR)\JDFPreview.obj" \
	"$(INTDIR)\JDFPreviewGenerationParams.obj" \
	"$(INTDIR)\JDFPrintCondition.obj" \
	"$(INTDIR)\JDFPrintRollingParams.obj" \
	"$(INTDIR)\JDFProofingParams.obj" \
	"$(INTDIR)\JDFPSToPDFConversionParams.obj" \
	"$(INTDIR)\JDFQualityControlParams.obj" \
	"$(INTDIR)\JDFQualityControlResult.obj" \
	"$(INTDIR)\JDFRegisterMark.obj" \
	"$(INTDIR)\JDFRegisterRibbon.obj" \
	"$(INTDIR)\JDFRenderingParams.obj" \
	"$(INTDIR)\JDFResourceDefinitionParams.obj" \
	"$(INTDIR)\JDFRingBindingParams.obj" \
	"$(INTDIR)\JDFRollStand.obj" \
	"$(INTDIR)\JDFRunList.obj" \
	"$(INTDIR)\JDFSaddleStitchingParams.obj" \
	"$(INTDIR)\JDFScanParams.obj" \
	"$(INTDIR)\JDFScavengerArea.obj" \
	"$(INTDIR)\JDFScreeningParams.obj" \
	"$(INTDIR)\JDFSeparationControlParams.obj" \
	"$(INTDIR)\JDFSeparationSpec.obj" \
	"$(INTDIR)\JDFShapeCuttingParams.obj" \
	"$(INTDIR)\JDFSheet.obj" \
	"$(INTDIR)\JDFShrinkingParams.obj" \
	"$(INTDIR)\JDFSideSewingParams.obj" \
	"$(INTDIR)\JDFSpinePreparationParams.obj" \
	"$(INTDIR)\JDFSpineTapingParams.obj" \
	"$(INTDIR)\JDFStackingParams.obj" \
	"$(INTDIR)\JDFStitchingParams.obj" \
	"$(INTDIR)\JDFStrap.obj" \
	"$(INTDIR)\JDFStrappingParams.obj" \
	"$(INTDIR)\JDFStripBindingParams.obj" \
	"$(INTDIR)\JDFStrippingParams.obj" \
	"$(INTDIR)\JDFSurface.obj" \
	"$(INTDIR)\JDFThreadSealingParams.obj" \
	"$(INTDIR)\JDFThreadSewingParams.obj" \
	"$(INTDIR)\JDFTile.obj" \
	"$(INTDIR)\JDFTool.obj" \
	"$(INTDIR)\JDFTransferCurve.obj" \
	"$(INTDIR)\JDFTransferCurvePool.obj" \
	"$(INTDIR)\JDFTransferFunctionControl.obj" \
	"$(INTDIR)\JDFTrappingDetails.obj" \
	"$(INTDIR)\JDFTrappingParams.obj" \
	"$(INTDIR)\JDFTrapRegion.obj" \
	"$(INTDIR)\JDFTrimmingParams.obj" \
	"$(INTDIR)\JDFVerificationParams.obj" \
	"$(INTDIR)\JDFWireCombBindingParams.obj" \
	"$(INTDIR)\JDFWrappingParams.obj" \
	"$(INTDIR)\JDFAdvancedParams.obj" \
	"$(INTDIR)\JDFApprovalPerson.obj" \
	"$(INTDIR)\JDFAssemblySection.obj" \
	"$(INTDIR)\JDFBand.obj" \
	"$(INTDIR)\JDFBasicPreflightTest.obj" \
	"$(INTDIR)\JDFBindingQualityParams.obj" \
	"$(INTDIR)\JDFBoxArgument.obj" \
	"$(INTDIR)\JDFBoxToBoxDifference.obj" \
	"$(INTDIR)\JDFBundleItem.obj" \
	"$(INTDIR)\JDFCCITTFaxParams.obj" \
	"$(INTDIR)\JDFCollatingItem.obj" \
	"$(INTDIR)\JDFColorantZoneDetails.obj" \
	"$(INTDIR)\JDFColorCorrectionOp.obj" \
	"$(INTDIR)\JDFColorSpaceSubstitute.obj" \
	"$(INTDIR)\JDFContainer.obj" \
	"$(INTDIR)\JDFContentObject.obj" \
	"$(INTDIR)\JDFCrease.obj" \
	"$(INTDIR)\JDFCut.obj" \
	"$(INTDIR)\JDFDCTParams.obj" \
	"$(INTDIR)\JDFDependencies.obj" \
	"$(INTDIR)\JDFDeviceNColor.obj" \
	"$(INTDIR)\JDFDrop.obj" \
	"$(INTDIR)\JDFDropItem.obj" \
	"$(INTDIR)\JDFDynamicField.obj" \
	"$(INTDIR)\JDFDynamicInput.obj" \
	"$(INTDIR)\JDFEmboss.obj" \
	"$(INTDIR)\JDFEndSheet.obj" \
	"$(INTDIR)\JDFFeeder.obj" \
	"$(INTDIR)\JDFFeederQualityParams.obj" \
	"$(INTDIR)\JDFFileAlias.obj" \
	"$(INTDIR)\JDFFlateParams.obj" \
	"$(INTDIR)\JDFGlue.obj" \
	"$(INTDIR)\JDFIcon.obj" \
	"$(INTDIR)\JDFIconList.obj" \
	"$(INTDIR)\JDFIDPCover.obj" \
	"$(INTDIR)\JDFIDPFinishing.obj" \
	"$(INTDIR)\JDFIDPFolding.obj" \
	"$(INTDIR)\JDFIDPHoleMaking.obj" \
	"$(INTDIR)\JDFIDPImageShift.obj" \
	"$(INTDIR)\JDFIDPJobSheet.obj" \
	"$(INTDIR)\JDFIDPLayout.obj" \
	"$(INTDIR)\JDFIDPStitching.obj" \
	"$(INTDIR)\JDFIDPTrimming.obj" \
	"$(INTDIR)\JDFImageCompression.obj" \
	"$(INTDIR)\JDFImageShift.obj" \
	"$(INTDIR)\JDFLayerDetails.obj" \
	"$(INTDIR)\JDFLayerList.obj" \
	"$(INTDIR)\JDFLongFold.obj" \
	"$(INTDIR)\JDFLongGlue.obj" \
	"$(INTDIR)\JDFLongPerforate.obj" \
	"$(INTDIR)\JDFLongSlit.obj" \
	"$(INTDIR)\JDFLZWParams.obj" \
	"$(INTDIR)\JDFMarkObject.obj" \
	"$(INTDIR)\JDFNumberingParam.obj" \
	"$(INTDIR)\JDFPageCell.obj" \
	"$(INTDIR)\JDFPageData.obj" \
	"$(INTDIR)\JDFPDFInterpretingParams.obj" \
	"$(INTDIR)\JDFPDFXParams.obj" \
	"$(INTDIR)\JDFPerforate.obj" \
	"$(INTDIR)\JDFPixelColorant.obj" \
	"$(INTDIR)\JDFPosition.obj" \
	"$(INTDIR)\JDFPreflightAction.obj" \
	"$(INTDIR)\JDFPreflightArgument.obj" \
	"$(INTDIR)\JDFPreflightConstraint.obj" \
	"$(INTDIR)\JDFPreflightDetail.obj" \
	"$(INTDIR)\JDFPreflightInstance.obj" \
	"$(INTDIR)\JDFPreflightInstanceDetail.obj" \
	"$(INTDIR)\JDFPreflightValue.obj" \
	"$(INTDIR)\JDFPRError.obj" \
	"$(INTDIR)\JDFPRGroup.obj" \
	"$(INTDIR)\JDFPrintConditionColor.obj" \
	"$(INTDIR)\JDFPRItem.obj" \
	"$(INTDIR)\JDFPROccurence.obj" \
	"$(INTDIR)\JDFProperties.obj" \
	"$(INTDIR)\JDFPRRule.obj" \
	"$(INTDIR)\JDFPRRuleAttr.obj" \
	"$(INTDIR)\JDFQualityMeasurement.obj" \
	"$(INTDIR)\JDFResourceParam.obj" \
	"$(INTDIR)\JDFScore.obj" \
	"$(INTDIR)\JDFScreenSelector.obj" \
	"$(INTDIR)\JDFShapeElement.obj" \
	"$(INTDIR)\JDFSignature.obj" \
	"$(INTDIR)\JDFSignatureCell.obj" \
	"$(INTDIR)\JDFStringListValue.obj" \
	"$(INTDIR)\JDFStripCellParams.obj" \
	"$(INTDIR)\JDFThinPDFParams.obj" \
	"$(INTDIR)\JDFTIFFEmbeddedFile.obj" \
	"$(INTDIR)\JDFTIFFFormatParams.obj" \
	"$(INTDIR)\JDFTIFFtag.obj" \
	"$(INTDIR)\JDFTransferCurveSet.obj" \
	"$(INTDIR)\JDFTrappingOrder.obj" \
	"$(INTDIR)\JDFAction.obj" \
	"$(INTDIR)\JDFActionPool.obj" \
	"$(INTDIR)\JDFand.obj" \
	"$(INTDIR)\JDFBooleanEvaluation.obj" \
	"$(INTDIR)\JDFBooleanState.obj" \
	"$(INTDIR)\JDFcall.obj" \
	"$(INTDIR)\JDFchoice.obj" \
	"$(INTDIR)\JDFDateTimeEvaluation.obj" \
	"$(INTDIR)\JDFDateTimeState.obj" \
	"$(INTDIR)\JDFDevCap.obj" \
	"$(INTDIR)\JDFDevCaps.obj" \
	"$(INTDIR)\JDFDeviceCap.obj" \
	"$(INTDIR)\JDFDisplayGroup.obj" \
	"$(INTDIR)\JDFDisplayGroupPool.obj" \
	"$(INTDIR)\JDFDurationEvaluation.obj" \
	"$(INTDIR)\JDFDurationState.obj" \
	"$(INTDIR)\JDFEnumerationEvaluation.obj" \
	"$(INTDIR)\JDFEnumerationState.obj" \
	"$(INTDIR)\JDFEvaluation.obj" \
	"$(INTDIR)\JDFFeatureAttribute.obj" \
	"$(INTDIR)\JDFFeaturePool.obj" \
	"$(INTDIR)\JDFIntegerEvaluation.obj" \
	"$(INTDIR)\JDFIntegerState.obj" \
	"$(INTDIR)\JDFIsPresentEvaluation.obj" \
	"$(INTDIR)\JDFLoc.obj" \
	"$(INTDIR)\JDFmacro.obj" \
	"$(INTDIR)\JDFMacroPool.obj" \
	"$(INTDIR)\JDFMatrixEvaluation.obj" \
	"$(INTDIR)\JDFMatrixState.obj" \
	"$(INTDIR)\JDFNameEvaluation.obj" \
	"$(INTDIR)\JDFNameState.obj" \
	"$(INTDIR)\JDFnot.obj" \
	"$(INTDIR)\JDFNumberEvaluation.obj" \
	"$(INTDIR)\JDFNumberState.obj" \
	"$(INTDIR)\JDFor.obj" \
	"$(INTDIR)\JDFotherwise.obj" \
	"$(INTDIR)\JDFPDFPathEvaluation.obj" \
	"$(INTDIR)\JDFPDFPathState.obj" \
	"$(INTDIR)\JDFPerformance.obj" \
	"$(INTDIR)\JDFRectangleEvaluation.obj" \
	"$(INTDIR)\JDFRectangleState.obj" \
	"$(INTDIR)\JDFset.obj" \
	"$(INTDIR)\JDFShapeEvaluation.obj" \
	"$(INTDIR)\JDFShapeState.obj" \
	"$(INTDIR)\JDFState.obj" \
	"$(INTDIR)\JDFStringEvaluation.obj" \
	"$(INTDIR)\JDFStringState.obj" \
	"$(INTDIR)\JDFTest.obj" \
	"$(INTDIR)\JDFTestPool.obj" \
	"$(INTDIR)\JDFTestRef.obj" \
	"$(INTDIR)\JDFValue.obj" \
	"$(INTDIR)\JDFValueLoc.obj" \
	"$(INTDIR)\JDFwhen.obj" \
	"$(INTDIR)\JDFxor.obj" \
	"$(INTDIR)\JDFXYPairEvaluation.obj" \
	"$(INTDIR)\JDFXYPairState.obj" \
	"$(INTDIR)\JDFDoc.obj" \
	"$(INTDIR)\JDFElement.obj" \
	"$(INTDIR)\JDFFactory.obj" \
	"$(INTDIR)\JDFNodeFactory.obj" \
	"$(INTDIR)\JDFParamsFactory.obj" \
	"$(INTDIR)\JDFPool.obj" \
	"$(INTDIR)\JDFRefElement.obj" \
	"$(INTDIR)\JDFResource.obj" \
	"$(INTDIR)\JDFResourceLink.obj" \
	"$(INTDIR)\JDFRunElement.obj" \
	"$(INTDIR)\JDFSeparationList.obj" \
	"$(INTDIR)\JDFStrings.obj" \
	"$(INTDIR)\JDFAutoAmountPool.obj" \
	"$(INTDIR)\JDFAutoAncestor.obj" \
	"$(INTDIR)\JDFAutoAncestorPool.obj" \
	"$(INTDIR)\JDFAutoBarcode.obj" \
	"$(INTDIR)\JDFAutoBusinessInfo.obj" \
	"$(INTDIR)\JDFAutoComment.obj" \
	"$(INTDIR)\JDFAutoCounterReset.obj" \
	"$(INTDIR)\JDFAutoCreated.obj" \
	"$(INTDIR)\JDFAutoCustomerInfo.obj" \
	"$(INTDIR)\JDFAutoCustomerMessage.obj" \
	"$(INTDIR)\JDFAutoDeleted.obj" \
	"$(INTDIR)\JDFAutoError.obj" \
	"$(INTDIR)\JDFAutoEvent.obj" \
	"$(INTDIR)\JDFAutoFCNKey.obj" \
	"$(INTDIR)\JDFAutoLocation.obj" \
	"$(INTDIR)\JDFAutoMerged.obj" \
	"$(INTDIR)\JDFAutoModified.obj" \
	"$(INTDIR)\JDFAutoModulePhase.obj" \
	"$(INTDIR)\JDFAutoNodeInfo.obj" \
	"$(INTDIR)\JDFAutoNotification.obj" \
	"$(INTDIR)\JDFAutoPart.obj" \
	"$(INTDIR)\JDFAutoPartStatus.obj" \
	"$(INTDIR)\JDFAutoPhaseTime.obj" \
	"$(INTDIR)\JDFAutoProcessRun.obj" \
	"$(INTDIR)\JDFAutoResourceAudit.obj" \
	"$(INTDIR)\JDFAutoSpawned.obj" \
	"$(INTDIR)\JDFAutoStatusPool.obj" \
	"$(INTDIR)\JDFAutoSystemTimeSet.obj" \
	"$(INTDIR)\JDFAutoAcknowledge.obj" \
	"$(INTDIR)\JDFAutoAdded.obj" \
	"$(INTDIR)\JDFAutoChangedAttribute.obj" \
	"$(INTDIR)\JDFAutoChangedPath.obj" \
	"$(INTDIR)\JDFAutoCommand.obj" \
	"$(INTDIR)\JDFAutoDeviceFilter.obj" \
	"$(INTDIR)\JDFAutoDeviceInfo.obj" \
	"$(INTDIR)\JDFAutoDeviceList.obj" \
	"$(INTDIR)\JDFAutoEmployeeDef.obj" \
	"$(INTDIR)\JDFAutoFlushedResources.obj" \
	"$(INTDIR)\JDFAutoFlushQueueParams.obj" \
	"$(INTDIR)\JDFAutoFlushResourceParams.obj" \
	"$(INTDIR)\JDFAutoIDInfo.obj" \
	"$(INTDIR)\JDFAutoJDFController.obj" \
	"$(INTDIR)\JDFAutoJDFService.obj" \
	"$(INTDIR)\JDFAutoJMF.obj" \
	"$(INTDIR)\JDFAutoJobPhase.obj" \
	"$(INTDIR)\JDFAutoKnownMsgQuParams.obj" \
	"$(INTDIR)\JDFAutoMessage.obj" \
	"$(INTDIR)\JDFAutoMessageService.obj" \
	"$(INTDIR)\JDFAutoModuleStatus.obj" \
	"$(INTDIR)\JDFAutoMsgFilter.obj" \
	"$(INTDIR)\JDFAutoNewJDFCmdParams.obj" \
	"$(INTDIR)\JDFAutoNewJDFQuParams.obj" \
	"$(INTDIR)\JDFAutoNodeInfoCmdParams.obj" \
	"$(INTDIR)\JDFAutoNodeInfoQuParams.obj" \
	"$(INTDIR)\JDFAutoNodeInfoResp.obj" \
	"$(INTDIR)\JDFAutoNotificationDef.obj" \
	"$(INTDIR)\JDFAutoNotificationFilter.obj" \
	"$(INTDIR)\JDFAutoObservationTarget.obj" \
	"$(INTDIR)\JDFAutoOccupation.obj" \
	"$(INTDIR)\JDFAutoPipeParams.obj" \
	"$(INTDIR)\JDFAutoQuery.obj" \
	"$(INTDIR)\JDFAutoQueue.obj" \
	"$(INTDIR)\JDFAutoQueueEntry.obj" \
	"$(INTDIR)\JDFAutoQueueEntryDef.obj" \
	"$(INTDIR)\JDFAutoQueueEntryDefList.obj" \
	"$(INTDIR)\JDFAutoQueueEntryPosParams.obj" \
	"$(INTDIR)\JDFAutoQueueEntryPriParams.obj" \
	"$(INTDIR)\JDFAutoQueueFilter.obj" \
	"$(INTDIR)\JDFAutoQueueSubmissionParams.obj" \
	"$(INTDIR)\JDFAutoRemoved.obj" \
	"$(INTDIR)\JDFAutoRequestQueueEntryParams.obj" \
	"$(INTDIR)\JDFAutoResourceCmdParams.obj" \
	"$(INTDIR)\JDFAutoResourceInfo.obj" \
	"$(INTDIR)\JDFAutoResourcePullParams.obj" \
	"$(INTDIR)\JDFAutoResourceQuParams.obj" \
	"$(INTDIR)\JDFAutoResponse.obj" \
	"$(INTDIR)\JDFAutoResubmissionParams.obj" \
	"$(INTDIR)\JDFAutoReturnQueueEntryParams.obj" \
	"$(INTDIR)\JDFAutoShutDownCmdParams.obj" \
	"$(INTDIR)\JDFAutoSignal.obj" \
	"$(INTDIR)\JDFAutoStatusQuParams.obj" \
	"$(INTDIR)\JDFAutoStopPersChParams.obj" \
	"$(INTDIR)\JDFAutoSubmissionMethods.obj" \
	"$(INTDIR)\JDFAutoSubscription.obj" \
	"$(INTDIR)\JDFAutoTrackFilter.obj" \
	"$(INTDIR)\JDFAutoTrackResult.obj" \
	"$(INTDIR)\JDFAutoTrigger.obj" \
	"$(INTDIR)\JDFAutoWakeUpCmdParams.obj" \
	"$(INTDIR)\JDFAutoArtDeliveryIntent.obj" \
	"$(INTDIR)\JDFAutoBindingIntent.obj" \
	"$(INTDIR)\JDFAutoColorIntent.obj" \
	"$(INTDIR)\JDFAutoDeliveryIntent.obj" \
	"$(INTDIR)\JDFAutoEmbossingIntent.obj" \
	"$(INTDIR)\JDFAutoFoldingIntent.obj" \
	"$(INTDIR)\JDFAutoHoleMakingIntent.obj" \
	"$(INTDIR)\JDFAutoInsertingIntent.obj" \
	"$(INTDIR)\JDFAutoLaminatingIntent.obj" \
	"$(INTDIR)\JDFAutoLayoutIntent.obj" \
	"$(INTDIR)\JDFAutoMediaIntent.obj" \
	"$(INTDIR)\JDFAutoNumberingIntent.obj" \
	"$(INTDIR)\JDFAutoPackingIntent.obj" \
	"$(INTDIR)\JDFAutoProductionIntent.obj" \
	"$(INTDIR)\JDFAutoProofingIntent.obj" \
	"$(INTDIR)\JDFAutoScreeningIntent.obj" \
	"$(INTDIR)\JDFAutoShapeCuttingIntent.obj" \
	"$(INTDIR)\JDFAutoSizeIntent.obj" \
	"$(INTDIR)\JDFAutoAdhesiveBinding.obj" \
	"$(INTDIR)\JDFAutoArtDelivery.obj" \
	"$(INTDIR)\JDFAutoBindItem.obj" \
	"$(INTDIR)\JDFAutoBindList.obj" \
	"$(INTDIR)\JDFAutoBookCase.obj" \
	"$(INTDIR)\JDFAutoChannelBinding.obj" \
	"$(INTDIR)\JDFAutoCoilBinding.obj" \
	"$(INTDIR)\JDFAutoColorsUsed.obj" \
	"$(INTDIR)\JDFAutoCreditCard.obj" \
	"$(INTDIR)\JDFAutoDropIntent.obj" \
	"$(INTDIR)\JDFAutoDropItemIntent.obj" \
	"$(INTDIR)\JDFAutoEdgeGluing.obj" \
	"$(INTDIR)\JDFAutoEmbossingItem.obj" \
	"$(INTDIR)\JDFAutoHardCoverBinding.obj" \
	"$(INTDIR)\JDFAutoHoleList.obj" \
	"$(INTDIR)\JDFAutoInsert.obj" \
	"$(INTDIR)\JDFAutoInsertList.obj" \
	"$(INTDIR)\JDFAutoNumberItem.obj" \
	"$(INTDIR)\JDFAutoPayment.obj" \
	"$(INTDIR)\JDFAutoPlasticCombBinding.obj" \
	"$(INTDIR)\JDFAutoPricing.obj" \
	"$(INTDIR)\JDFAutoProofItem.obj" \
	"$(INTDIR)\JDFAutoRingBinding.obj" \
	"$(INTDIR)\JDFAutoSaddleStitching.obj" \
	"$(INTDIR)\JDFAutoShapeCut.obj" \
	"$(INTDIR)\JDFAutoSideSewing.obj" \
	"$(INTDIR)\JDFAutoSideStitching.obj" \
	"$(INTDIR)\JDFAutoSoftCoverBinding.obj" \
	"$(INTDIR)\JDFAutoStripBinding.obj" \
	"$(INTDIR)\JDFAutoTabs.obj" \
	"$(INTDIR)\JDFAutoTape.obj" \
	"$(INTDIR)\JDFAutoThreadSealing.obj" \
	"$(INTDIR)\JDFAutoThreadSewing.obj" \
	"$(INTDIR)\JDFAutoWireCombBinding.obj" \
	"$(INTDIR)\JDFAutoAddress.obj" \
	"$(INTDIR)\JDFAutoAdhesiveBindingParams.obj" \
	"$(INTDIR)\JDFAutoApprovalParams.obj" \
	"$(INTDIR)\JDFAutoApprovalSuccess.obj" \
	"$(INTDIR)\JDFAutoAssembly.obj" \
	"$(INTDIR)\JDFAutoAssetListCreationParams.obj" \
	"$(INTDIR)\JDFAutoAutomatedOverprintParams.obj" \
	"$(INTDIR)\JDFAutoBinderySignature.obj" \
	"$(INTDIR)\JDFAutoBlockPreparationParams.obj" \
	"$(INTDIR)\JDFAutoBoxPackingParams.obj" \
	"$(INTDIR)\JDFAutoBufferParams.obj" \
	"$(INTDIR)\JDFAutoBundle.obj" \
	"$(INTDIR)\JDFAutoBundlingParams.obj" \
	"$(INTDIR)\JDFAutoByteMap.obj" \
	"$(INTDIR)\JDFAutoCaseMakingParams.obj" \
	"$(INTDIR)\JDFAutoCasingInParams.obj" \
	"$(INTDIR)\JDFAutoChannelBindingParams.obj" \
	"$(INTDIR)\JDFAutoCIELABMeasuringField.obj" \
	"$(INTDIR)\JDFAutoCoilBindingParams.obj" \
	"$(INTDIR)\JDFAutoCollectingParams.obj" \
	"$(INTDIR)\JDFAutoColor.obj" \
	"$(INTDIR)\JDFAutoColorantAlias.obj" \
	"$(INTDIR)\JDFAutoColorantControl.obj" \
	"$(INTDIR)\JDFAutoColorControlStrip.obj" \
	"$(INTDIR)\JDFAutoColorCorrectionParams.obj" \
	"$(INTDIR)\JDFAutoColorMeasurementConditions.obj" \
	"$(INTDIR)\JDFAutoColorPool.obj" \
	"$(INTDIR)\JDFAutoColorSpaceConversionOp.obj" \
	"$(INTDIR)\JDFAutoColorSpaceConversionParams.obj" \
	"$(INTDIR)\JDFAutoComChannel.obj" \
	"$(INTDIR)\JDFAutoCompany.obj" \
	"$(INTDIR)\JDFAutoComponent.obj" \
	"$(INTDIR)\JDFAutoContact.obj" \
	"$(INTDIR)\JDFAutoContactCopyParams.obj" \
	"$(INTDIR)\JDFAutoConventionalPrintingParams.obj" \
	"$(INTDIR)\JDFAutoCostCenter.obj" \
	"$(INTDIR)\JDFAutoCoverApplicationParams.obj" \
	"$(INTDIR)\JDFAutoCreasingParams.obj" \
	"$(INTDIR)\JDFAutoCutBlock.obj" \
	"$(INTDIR)\JDFAutoCutMark.obj" \
	"$(INTDIR)\JDFAutoCuttingParams.obj" \
	"$(INTDIR)\JDFAutoDBMergeParams.obj" \
	"$(INTDIR)\JDFAutoDBRules.obj" \
	"$(INTDIR)\JDFAutoDBSchema.obj" \
	"$(INTDIR)\JDFAutoDBSelection.obj" \
	"$(INTDIR)\JDFAutoDeliveryParams.obj" \
	"$(INTDIR)\JDFAutoDensityMeasuringField.obj" \
	"$(INTDIR)\JDFAutoDevelopingParams.obj" \
	"$(INTDIR)\JDFAutoDevice.obj" \
	"$(INTDIR)\JDFAutoDeviceMark.obj" \
	"$(INTDIR)\JDFAutoDeviceNSpace.obj" \
	"$(INTDIR)\JDFAutoDigitalDeliveryParams.obj" \
	"$(INTDIR)\JDFAutoDigitalMedia.obj" \
	"$(INTDIR)\JDFAutoDigitalPrintingParams.obj" \
	"$(INTDIR)\JDFAutoDisjointing.obj" \
	"$(INTDIR)\JDFAutoDisposition.obj" \
	"$(INTDIR)\JDFAutoDividingParams.obj" \
	"$(INTDIR)\JDFAutoElementColorParams.obj" \
	"$(INTDIR)\JDFAutoEmbossingParams.obj" \
	"$(INTDIR)\JDFAutoEmployee.obj" \
	"$(INTDIR)\JDFAutoEndSheetGluingParams.obj" \
	"$(INTDIR)\JDFAutoExposedMedia.obj" \
	"$(INTDIR)\JDFAutoFeedingParams.obj" \
	"$(INTDIR)\JDFAutoFileSpec.obj" \
	"$(INTDIR)\JDFAutoFitPolicy.obj" \
	"$(INTDIR)\JDFAutoFold.obj" \
	"$(INTDIR)\JDFAutoFoldingParams.obj" \
	"$(INTDIR)\JDFAutoFontParams.obj" \
	"$(INTDIR)\JDFAutoFontPolicy.obj" \
	"$(INTDIR)\JDFAutoFormatConversionParams.obj" \
	"$(INTDIR)\JDFAutoGatheringParams.obj" \
	"$(INTDIR)\JDFAutoGlueApplication.obj" \
	"$(INTDIR)\JDFAutoGlueLine.obj" \
	"$(INTDIR)\JDFAutoGluingParams.obj" \
	"$(INTDIR)\JDFAutoHeadBandApplicationParams.obj" \
	"$(INTDIR)\JDFAutoHole.obj" \
	"$(INTDIR)\JDFAutoHoleLine.obj" \
	"$(INTDIR)\JDFAutoHoleMakingParams.obj" \
	"$(INTDIR)\JDFAutoIdentificationField.obj" \
	"$(INTDIR)\JDFAutoIDPrintingParams.obj" \
	"$(INTDIR)\JDFAutoImageCompressionParams.obj" \
	"$(INTDIR)\JDFAutoImageReplacementParams.obj" \
	"$(INTDIR)\JDFAutoImageSetterParams.obj" \
	"$(INTDIR)\JDFAutoInk.obj" \
	"$(INTDIR)\JDFAutoInkZoneCalculationParams.obj" \
	"$(INTDIR)\JDFAutoInkZoneProfile.obj" \
	"$(INTDIR)\JDFAutoInsertingParams.obj" \
	"$(INTDIR)\JDFAutoInsertSheet.obj" \
	"$(INTDIR)\JDFAutoInterpretedPDLData.obj" \
	"$(INTDIR)\JDFAutoInterpretingParams.obj" \
	"$(INTDIR)\JDFAutoJacketingParams.obj" \
	"$(INTDIR)\JDFAutoJobField.obj" \
	"$(INTDIR)\JDFAutoLabelingParams.obj" \
	"$(INTDIR)\JDFAutoLaminatingParams.obj" \
	"$(INTDIR)\JDFAutoLayout.obj" \
	"$(INTDIR)\JDFAutoLayoutElement.obj" \
	"$(INTDIR)\JDFAutoLayoutPreparationParams.obj" \
	"$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.obj" \
	"$(INTDIR)\JDFAutoManualLaborParams.obj" \
	"$(INTDIR)\JDFAutoMedia.obj" \
	"$(INTDIR)\JDFAutoMediaSource.obj" \
	"$(INTDIR)\JDFAutoMISDetails.obj" \
	"$(INTDIR)\JDFAutoNumberingParams.obj" \
	"$(INTDIR)\JDFAutoObjectResolution.obj" \
	"$(INTDIR)\JDFAutoOrderingParams.obj" \
	"$(INTDIR)\JDFAutoPackingParams.obj" \
	"$(INTDIR)\JDFAutoPageList.obj" \
	"$(INTDIR)\JDFAutoPallet.obj" \
	"$(INTDIR)\JDFAutoPalletizingParams.obj" \
	"$(INTDIR)\JDFAutoPDFToPSConversionParams.obj" \
	"$(INTDIR)\JDFAutoPDLResourceAlias.obj" \
	"$(INTDIR)\JDFAutoPerforatingParams.obj" \
	"$(INTDIR)\JDFAutoPerson.obj" \
	"$(INTDIR)\JDFAutoPlaceHolderResource.obj" \
	"$(INTDIR)\JDFAutoPlasticCombBindingParams.obj" \
	"$(INTDIR)\JDFAutoPlateCopyParams.obj" \
	"$(INTDIR)\JDFAutoPreflightAnalysis.obj" \
	"$(INTDIR)\JDFAutoPreflightInventory.obj" \
	"$(INTDIR)\JDFAutoPreflightParams.obj" \
	"$(INTDIR)\JDFAutoPreflightProfile.obj" \
	"$(INTDIR)\JDFAutoPreflightReport.obj" \
	"$(INTDIR)\JDFAutoPreflightReportRulePool.obj" \
	"$(INTDIR)\JDFAutoPreview.obj" \
	"$(INTDIR)\JDFAutoPreviewGenerationParams.obj" \
	"$(INTDIR)\JDFAutoPrintCondition.obj" \
	"$(INTDIR)\JDFAutoPrintRollingParams.obj" \
	"$(INTDIR)\JDFAutoProofingParams.obj" \
	"$(INTDIR)\JDFAutoPSToPDFConversionParams.obj" \
	"$(INTDIR)\JDFAutoQualityControlParams.obj" \
	"$(INTDIR)\JDFAutoQualityControlResult.obj" \
	"$(INTDIR)\JDFAutoRegisterMark.obj" \
	"$(INTDIR)\JDFAutoRegisterRibbon.obj" \
	"$(INTDIR)\JDFAutoRenderingParams.obj" \
	"$(INTDIR)\JDFAutoResourceDefinitionParams.obj" \
	"$(INTDIR)\JDFAutoRingBindingParams.obj" \
	"$(INTDIR)\JDFAutoRollStand.obj" \
	"$(INTDIR)\JDFAutoRunList.obj" \
	"$(INTDIR)\JDFAutoSaddleStitchingParams.obj" \
	"$(INTDIR)\JDFAutoScanParams.obj" \
	"$(INTDIR)\JDFAutoScavengerArea.obj" \
	"$(INTDIR)\JDFAutoScreeningParams.obj" \
	"$(INTDIR)\JDFAutoSeparationControlParams.obj" \
	"$(INTDIR)\JDFAutoSeparationSpec.obj" \
	"$(INTDIR)\JDFAutoShapeCuttingParams.obj" \
	"$(INTDIR)\JDFAutoSheet.obj" \
	"$(INTDIR)\JDFAutoShrinkingParams.obj" \
	"$(INTDIR)\JDFAutoSideSewingParams.obj" \
	"$(INTDIR)\JDFAutoSpinePreparationParams.obj" \
	"$(INTDIR)\JDFAutoSpineTapingParams.obj" \
	"$(INTDIR)\JDFAutoStackingParams.obj" \
	"$(INTDIR)\JDFAutoStitchingParams.obj" \
	"$(INTDIR)\JDFAutoStrap.obj" \
	"$(INTDIR)\JDFAutoStrappingParams.obj" \
	"$(INTDIR)\JDFAutoStripBindingParams.obj" \
	"$(INTDIR)\JDFAutoStrippingParams.obj" \
	"$(INTDIR)\JDFAutoSurface.obj" \
	"$(INTDIR)\JDFAutoThreadSealingParams.obj" \
	"$(INTDIR)\JDFAutoThreadSewingParams.obj" \
	"$(INTDIR)\JDFAutoTile.obj" \
	"$(INTDIR)\JDFAutoTool.obj" \
	"$(INTDIR)\JDFAutoTransferCurve.obj" \
	"$(INTDIR)\JDFAutoTransferCurvePool.obj" \
	"$(INTDIR)\JDFAutoTransferFunctionControl.obj" \
	"$(INTDIR)\JDFAutoTrappingDetails.obj" \
	"$(INTDIR)\JDFAutoTrappingParams.obj" \
	"$(INTDIR)\JDFAutoTrapRegion.obj" \
	"$(INTDIR)\JDFAutoTrimmingParams.obj" \
	"$(INTDIR)\JDFAutoVerificationParams.obj" \
	"$(INTDIR)\JDFAutoWireCombBindingParams.obj" \
	"$(INTDIR)\JDFAutoWrappingParams.obj" \
	"$(INTDIR)\JDFArgumentValue.obj" \
	"$(INTDIR)\JDFAutoAdvancedParams.obj" \
	"$(INTDIR)\JDFAutoApprovalPerson.obj" \
	"$(INTDIR)\JDFAutoArgumentValue.obj" \
	"$(INTDIR)\JDFAutoAssemblySection.obj" \
	"$(INTDIR)\JDFAutoBand.obj" \
	"$(INTDIR)\JDFAutoBasicPreflightTest.obj" \
	"$(INTDIR)\JDFAutoBindingQualityParams.obj" \
	"$(INTDIR)\JDFAutoBoxArgument.obj" \
	"$(INTDIR)\JDFAutoBoxToBoxDifference.obj" \
	"$(INTDIR)\JDFAutoBundleItem.obj" \
	"$(INTDIR)\JDFAutoCCITTFaxParams.obj" \
	"$(INTDIR)\JDFAutoCollatingItem.obj" \
	"$(INTDIR)\JDFAutoColorantZoneDetails.obj" \
	"$(INTDIR)\JDFAutoColorCorrectionOp.obj" \
	"$(INTDIR)\JDFAutoColorSpaceSubstitute.obj" \
	"$(INTDIR)\JDFAutoContainer.obj" \
	"$(INTDIR)\JDFAutoContentObject.obj" \
	"$(INTDIR)\JDFAutoCrease.obj" \
	"$(INTDIR)\JDFAutoCut.obj" \
	"$(INTDIR)\JDFAutoDCTParams.obj" \
	"$(INTDIR)\JDFAutoDependencies.obj" \
	"$(INTDIR)\JDFAutoDeviceNColor.obj" \
	"$(INTDIR)\JDFAutoDrop.obj" \
	"$(INTDIR)\JDFAutoDropItem.obj" \
	"$(INTDIR)\JDFAutoDynamicField.obj" \
	"$(INTDIR)\JDFAutoDynamicInput.obj" \
	"$(INTDIR)\JDFAutoEmboss.obj" \
	"$(INTDIR)\JDFAutoEndSheet.obj" \
	"$(INTDIR)\JDFAutoFeeder.obj" \
	"$(INTDIR)\JDFAutoFeederQualityParams.obj" \
	"$(INTDIR)\JDFAutoFileAlias.obj" \
	"$(INTDIR)\JDFAutoFlateParams.obj" \
	"$(INTDIR)\JDFAutoGlue.obj" \
	"$(INTDIR)\JDFAutoIcon.obj" \
	"$(INTDIR)\JDFAutoIconList.obj" \
	"$(INTDIR)\JDFAutoIDPCover.obj" \
	"$(INTDIR)\JDFAutoIDPFinishing.obj" \
	"$(INTDIR)\JDFAutoIDPFolding.obj" \
	"$(INTDIR)\JDFAutoIDPHoleMaking.obj" \
	"$(INTDIR)\JDFAutoIDPImageShift.obj" \
	"$(INTDIR)\JDFAutoIDPJobSheet.obj" \
	"$(INTDIR)\JDFAutoIDPLayout.obj" \
	"$(INTDIR)\JDFAutoIDPStitching.obj" \
	"$(INTDIR)\JDFAutoIDPTrimming.obj" \
	"$(INTDIR)\JDFAutoImageCompression.obj" \
	"$(INTDIR)\JDFAutoImageShift.obj" \
	"$(INTDIR)\JDFAutoLayerDetails.obj" \
	"$(INTDIR)\JDFAutoLayerList.obj" \
	"$(INTDIR)\JDFAutoLongFold.obj" \
	"$(INTDIR)\JDFAutoLongGlue.obj" \
	"$(INTDIR)\JDFAutoLongPerforate.obj" \
	"$(INTDIR)\JDFAutoLongSlit.obj" \
	"$(INTDIR)\JDFAutoLZWParams.obj" \
	"$(INTDIR)\JDFAutoMarkObject.obj" \
	"$(INTDIR)\JDFAutoNumberingParam.obj" \
	"$(INTDIR)\JDFAutoPageCell.obj" \
	"$(INTDIR)\JDFAutoPageData.obj" \
	"$(INTDIR)\JDFAutoPDFInterpretingParams.obj" \
	"$(INTDIR)\JDFAutoPDFXParams.obj" \
	"$(INTDIR)\JDFAutoPerforate.obj" \
	"$(INTDIR)\JDFAutoPixelColorant.obj" \
	"$(INTDIR)\JDFAutoPosition.obj" \
	"$(INTDIR)\JDFAutoPreflightAction.obj" \
	"$(INTDIR)\JDFAutoPreflightArgument.obj" \
	"$(INTDIR)\JDFAutoPreflightConstraint.obj" \
	"$(INTDIR)\JDFAutoPreflightDetail.obj" \
	"$(INTDIR)\JDFAutoPreflightInstance.obj" \
	"$(INTDIR)\JDFAutoPreflightInstanceDetail.obj" \
	"$(INTDIR)\JDFAutoPreflightValue.obj" \
	"$(INTDIR)\JDFAutoPRError.obj" \
	"$(INTDIR)\JDFAutoPRGroup.obj" \
	"$(INTDIR)\JDFAutoPrintConditionColor.obj" \
	"$(INTDIR)\JDFAutoPRItem.obj" \
	"$(INTDIR)\JDFAutoPROccurence.obj" \
	"$(INTDIR)\JDFAutoProperties.obj" \
	"$(INTDIR)\JDFAutoPRRule.obj" \
	"$(INTDIR)\JDFAutoPRRuleAttr.obj" \
	"$(INTDIR)\JDFAutoQualityMeasurement.obj" \
	"$(INTDIR)\JDFAutoResourceParam.obj" \
	"$(INTDIR)\JDFAutoScore.obj" \
	"$(INTDIR)\JDFAutoScreenSelector.obj" \
	"$(INTDIR)\JDFAutoShapeElement.obj" \
	"$(INTDIR)\JDFAutoSignature.obj" \
	"$(INTDIR)\JDFAutoSignatureCell.obj" \
	"$(INTDIR)\JDFAutoStringListValue.obj" \
	"$(INTDIR)\JDFAutoStripCellParams.obj" \
	"$(INTDIR)\JDFAutoThinPDFParams.obj" \
	"$(INTDIR)\JDFAutoTIFFEmbeddedFile.obj" \
	"$(INTDIR)\JDFAutoTIFFFormatParams.obj" \
	"$(INTDIR)\JDFAutoTIFFtag.obj" \
	"$(INTDIR)\JDFAutoTransferCurveSet.obj" \
	"$(INTDIR)\JDFAutoTrappingOrder.obj" \
	"$(INTDIR)\JDFAutoAction.obj" \
	"$(INTDIR)\JDFAutoActionPool.obj" \
	"$(INTDIR)\JDFAutoand.obj" \
	"$(INTDIR)\JDFAutocall.obj" \
	"$(INTDIR)\JDFAutochoice.obj" \
	"$(INTDIR)\JDFAutoDevCap.obj" \
	"$(INTDIR)\JDFAutoDevCaps.obj" \
	"$(INTDIR)\JDFAutoDeviceCap.obj" \
	"$(INTDIR)\JDFAutoDisplayGroup.obj" \
	"$(INTDIR)\JDFAutoDisplayGroupPool.obj" \
	"$(INTDIR)\JDFAutoFeatureAttribute.obj" \
	"$(INTDIR)\JDFAutoFeaturePool.obj" \
	"$(INTDIR)\JDFAutoLoc.obj" \
	"$(INTDIR)\JDFAutomacro.obj" \
	"$(INTDIR)\JDFAutoMacroPool.obj" \
	"$(INTDIR)\JDFAutonot.obj" \
	"$(INTDIR)\JDFAutoor.obj" \
	"$(INTDIR)\JDFAutootherwise.obj" \
	"$(INTDIR)\JDFAutoPerformance.obj" \
	"$(INTDIR)\JDFAutoset.obj" \
	"$(INTDIR)\JDFAutoTest.obj" \
	"$(INTDIR)\JDFAutoTestPool.obj" \
	"$(INTDIR)\JDFAutoTestRef.obj" \
	"$(INTDIR)\JDFAutoValue.obj" \
	"$(INTDIR)\JDFAutoValueLoc.obj" \
	"$(INTDIR)\JDFAutowhen.obj" \
	"$(INTDIR)\JDFAutoxor.obj" \
	"$(INTDIR)\JDFAutoEnumerationSpan.obj" \
	"$(INTDIR)\JDFAutoPRGroupOccurence.obj" \
	"$(INTDIR)\JDFAutoPRGroupOccurenceBase.obj" \
	"$(INTDIR)\JDFPreflightConstraintsPool.obj" \
	"$(INTDIR)\JDFPreflightResultsPool.obj" \
	"$(INTDIR)\JDFPRGroupOccurence.obj" \
	"$(INTDIR)\JDFPRGroupOccurenceBase.obj" \
	"$(INTDIR)\JDFDateTimeRange.obj" \
	"$(INTDIR)\JDFDateTimeRangeList.obj" \
	"$(INTDIR)\JDFDurationRange.obj" \
	"$(INTDIR)\JDFDurationRangeList.obj" \
	"$(INTDIR)\JDFIntegerRange.obj" \
	"$(INTDIR)\JDFIntegerRangeList.obj" \
	"$(INTDIR)\JDFNameRangeList.obj" \
	"$(INTDIR)\JDFNumberRangeList.obj" \
	"$(INTDIR)\JDFNumTypeList.obj" \
	"$(INTDIR)\JDFParser.obj" \
	"$(INTDIR)\JDFRange.obj" \
	"$(INTDIR)\JDFRangeList.obj" \
	"$(INTDIR)\JDFXYPairRangeList.obj" \
	"$(INTDIR)\KElement.obj" \
	"$(INTDIR)\KElementStrings.obj" \
	"$(INTDIR)\MyDate.obj" \
	"$(INTDIR)\vElement.obj" \
	"$(INTDIR)\XMLDoc.obj" \
	"$(INTDIR)\XMLDocUserData.obj" \
	"..\..\..\external\xerces\lib\xerces-c_2D.lib" \
	"$(OUTDIR)\JDFToolsDLLd.lib"

"$(OUTDIR)\JDFWrapperDLLd.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug"

OUTDIR=.\..\..\..\Build\Win32\VC6\Debug
INTDIR=.\..\..\..\Build\Win32\VC6\Debug\obj\JDFWrapperLib
# Begin Custom Macros
OutDir=.\..\..\..\Build\Win32\VC6\Debug
# End Custom Macros

ALL : "$(OUTDIR)\JDFWrapperLib_D.lib" "$(OUTDIR)\JDFWrapperLib.bsc"


CLEAN :
	-@erase "$(INTDIR)\JDFAcknowledge.obj"
	-@erase "$(INTDIR)\JDFAcknowledge.sbr"
	-@erase "$(INTDIR)\JDFAction.obj"
	-@erase "$(INTDIR)\JDFAction.sbr"
	-@erase "$(INTDIR)\JDFActionPool.obj"
	-@erase "$(INTDIR)\JDFActionPool.sbr"
	-@erase "$(INTDIR)\JDFAdded.obj"
	-@erase "$(INTDIR)\JDFAdded.sbr"
	-@erase "$(INTDIR)\JDFAddress.obj"
	-@erase "$(INTDIR)\JDFAddress.sbr"
	-@erase "$(INTDIR)\JDFAdhesiveBinding.obj"
	-@erase "$(INTDIR)\JDFAdhesiveBinding.sbr"
	-@erase "$(INTDIR)\JDFAdhesiveBindingParams.obj"
	-@erase "$(INTDIR)\JDFAdhesiveBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAdvancedParams.obj"
	-@erase "$(INTDIR)\JDFAdvancedParams.sbr"
	-@erase "$(INTDIR)\JDFAmountPool.obj"
	-@erase "$(INTDIR)\JDFAmountPool.sbr"
	-@erase "$(INTDIR)\JDFAncestor.obj"
	-@erase "$(INTDIR)\JDFAncestor.sbr"
	-@erase "$(INTDIR)\JDFAncestorPool.obj"
	-@erase "$(INTDIR)\JDFAncestorPool.sbr"
	-@erase "$(INTDIR)\JDFand.obj"
	-@erase "$(INTDIR)\JDFand.sbr"
	-@erase "$(INTDIR)\JDFApprovalParams.obj"
	-@erase "$(INTDIR)\JDFApprovalParams.sbr"
	-@erase "$(INTDIR)\JDFApprovalPerson.obj"
	-@erase "$(INTDIR)\JDFApprovalPerson.sbr"
	-@erase "$(INTDIR)\JDFApprovalSuccess.obj"
	-@erase "$(INTDIR)\JDFApprovalSuccess.sbr"
	-@erase "$(INTDIR)\JDFArgumentValue.obj"
	-@erase "$(INTDIR)\JDFArgumentValue.sbr"
	-@erase "$(INTDIR)\JDFArtDelivery.obj"
	-@erase "$(INTDIR)\JDFArtDelivery.sbr"
	-@erase "$(INTDIR)\JDFArtDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFArtDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFAssembly.obj"
	-@erase "$(INTDIR)\JDFAssembly.sbr"
	-@erase "$(INTDIR)\JDFAssemblySection.obj"
	-@erase "$(INTDIR)\JDFAssemblySection.sbr"
	-@erase "$(INTDIR)\JDFAssetListCreationParams.obj"
	-@erase "$(INTDIR)\JDFAssetListCreationParams.sbr"
	-@erase "$(INTDIR)\JDFAudit.obj"
	-@erase "$(INTDIR)\JDFAudit.sbr"
	-@erase "$(INTDIR)\JDFAuditPool.obj"
	-@erase "$(INTDIR)\JDFAuditPool.sbr"
	-@erase "$(INTDIR)\JDFAutoAcknowledge.obj"
	-@erase "$(INTDIR)\JDFAutoAcknowledge.sbr"
	-@erase "$(INTDIR)\JDFAutoAction.obj"
	-@erase "$(INTDIR)\JDFAutoAction.sbr"
	-@erase "$(INTDIR)\JDFAutoActionPool.obj"
	-@erase "$(INTDIR)\JDFAutoActionPool.sbr"
	-@erase "$(INTDIR)\JDFAutoAdded.obj"
	-@erase "$(INTDIR)\JDFAutoAdded.sbr"
	-@erase "$(INTDIR)\JDFAutoAddress.obj"
	-@erase "$(INTDIR)\JDFAutoAddress.sbr"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBinding.obj"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoAdvancedParams.obj"
	-@erase "$(INTDIR)\JDFAutoAdvancedParams.sbr"
	-@erase "$(INTDIR)\JDFAutoAmountPool.obj"
	-@erase "$(INTDIR)\JDFAutoAmountPool.sbr"
	-@erase "$(INTDIR)\JDFAutoAncestor.obj"
	-@erase "$(INTDIR)\JDFAutoAncestor.sbr"
	-@erase "$(INTDIR)\JDFAutoAncestorPool.obj"
	-@erase "$(INTDIR)\JDFAutoAncestorPool.sbr"
	-@erase "$(INTDIR)\JDFAutoand.obj"
	-@erase "$(INTDIR)\JDFAutoand.sbr"
	-@erase "$(INTDIR)\JDFAutoApprovalParams.obj"
	-@erase "$(INTDIR)\JDFAutoApprovalParams.sbr"
	-@erase "$(INTDIR)\JDFAutoApprovalPerson.obj"
	-@erase "$(INTDIR)\JDFAutoApprovalPerson.sbr"
	-@erase "$(INTDIR)\JDFAutoApprovalSuccess.obj"
	-@erase "$(INTDIR)\JDFAutoApprovalSuccess.sbr"
	-@erase "$(INTDIR)\JDFAutoArgumentValue.obj"
	-@erase "$(INTDIR)\JDFAutoArgumentValue.sbr"
	-@erase "$(INTDIR)\JDFAutoArtDelivery.obj"
	-@erase "$(INTDIR)\JDFAutoArtDelivery.sbr"
	-@erase "$(INTDIR)\JDFAutoArtDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFAutoArtDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoAssembly.obj"
	-@erase "$(INTDIR)\JDFAutoAssembly.sbr"
	-@erase "$(INTDIR)\JDFAutoAssemblySection.obj"
	-@erase "$(INTDIR)\JDFAutoAssemblySection.sbr"
	-@erase "$(INTDIR)\JDFAutoAssetListCreationParams.obj"
	-@erase "$(INTDIR)\JDFAutoAssetListCreationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoAutomatedOverprintParams.obj"
	-@erase "$(INTDIR)\JDFAutoAutomatedOverprintParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBand.obj"
	-@erase "$(INTDIR)\JDFAutoBand.sbr"
	-@erase "$(INTDIR)\JDFAutoBarcode.obj"
	-@erase "$(INTDIR)\JDFAutoBarcode.sbr"
	-@erase "$(INTDIR)\JDFAutoBasicPreflightTest.obj"
	-@erase "$(INTDIR)\JDFAutoBasicPreflightTest.sbr"
	-@erase "$(INTDIR)\JDFAutoBinderySignature.obj"
	-@erase "$(INTDIR)\JDFAutoBinderySignature.sbr"
	-@erase "$(INTDIR)\JDFAutoBindingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoBindingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoBindingQualityParams.obj"
	-@erase "$(INTDIR)\JDFAutoBindingQualityParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBindItem.obj"
	-@erase "$(INTDIR)\JDFAutoBindItem.sbr"
	-@erase "$(INTDIR)\JDFAutoBindList.obj"
	-@erase "$(INTDIR)\JDFAutoBindList.sbr"
	-@erase "$(INTDIR)\JDFAutoBlockPreparationParams.obj"
	-@erase "$(INTDIR)\JDFAutoBlockPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBookCase.obj"
	-@erase "$(INTDIR)\JDFAutoBookCase.sbr"
	-@erase "$(INTDIR)\JDFAutoBoxArgument.obj"
	-@erase "$(INTDIR)\JDFAutoBoxArgument.sbr"
	-@erase "$(INTDIR)\JDFAutoBoxPackingParams.obj"
	-@erase "$(INTDIR)\JDFAutoBoxPackingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBoxToBoxDifference.obj"
	-@erase "$(INTDIR)\JDFAutoBoxToBoxDifference.sbr"
	-@erase "$(INTDIR)\JDFAutoBufferParams.obj"
	-@erase "$(INTDIR)\JDFAutoBufferParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBundle.obj"
	-@erase "$(INTDIR)\JDFAutoBundle.sbr"
	-@erase "$(INTDIR)\JDFAutoBundleItem.obj"
	-@erase "$(INTDIR)\JDFAutoBundleItem.sbr"
	-@erase "$(INTDIR)\JDFAutoBundlingParams.obj"
	-@erase "$(INTDIR)\JDFAutoBundlingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBusinessInfo.obj"
	-@erase "$(INTDIR)\JDFAutoBusinessInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoByteMap.obj"
	-@erase "$(INTDIR)\JDFAutoByteMap.sbr"
	-@erase "$(INTDIR)\JDFAutocall.obj"
	-@erase "$(INTDIR)\JDFAutocall.sbr"
	-@erase "$(INTDIR)\JDFAutoCaseMakingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCaseMakingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCasingInParams.obj"
	-@erase "$(INTDIR)\JDFAutoCasingInParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCCITTFaxParams.obj"
	-@erase "$(INTDIR)\JDFAutoCCITTFaxParams.sbr"
	-@erase "$(INTDIR)\JDFAutoChangedAttribute.obj"
	-@erase "$(INTDIR)\JDFAutoChangedAttribute.sbr"
	-@erase "$(INTDIR)\JDFAutoChangedPath.obj"
	-@erase "$(INTDIR)\JDFAutoChangedPath.sbr"
	-@erase "$(INTDIR)\JDFAutoChannelBinding.obj"
	-@erase "$(INTDIR)\JDFAutoChannelBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoChannelBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoChannelBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutochoice.obj"
	-@erase "$(INTDIR)\JDFAutochoice.sbr"
	-@erase "$(INTDIR)\JDFAutoCIELABMeasuringField.obj"
	-@erase "$(INTDIR)\JDFAutoCIELABMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFAutoCoilBinding.obj"
	-@erase "$(INTDIR)\JDFAutoCoilBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoCoilBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCoilBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCollatingItem.obj"
	-@erase "$(INTDIR)\JDFAutoCollatingItem.sbr"
	-@erase "$(INTDIR)\JDFAutoCollectingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCollectingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoColor.obj"
	-@erase "$(INTDIR)\JDFAutoColor.sbr"
	-@erase "$(INTDIR)\JDFAutoColorantAlias.obj"
	-@erase "$(INTDIR)\JDFAutoColorantAlias.sbr"
	-@erase "$(INTDIR)\JDFAutoColorantControl.obj"
	-@erase "$(INTDIR)\JDFAutoColorantControl.sbr"
	-@erase "$(INTDIR)\JDFAutoColorantZoneDetails.obj"
	-@erase "$(INTDIR)\JDFAutoColorantZoneDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoColorControlStrip.obj"
	-@erase "$(INTDIR)\JDFAutoColorControlStrip.sbr"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionOp.obj"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionOp.sbr"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionParams.obj"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoColorIntent.obj"
	-@erase "$(INTDIR)\JDFAutoColorIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoColorMeasurementConditions.obj"
	-@erase "$(INTDIR)\JDFAutoColorMeasurementConditions.sbr"
	-@erase "$(INTDIR)\JDFAutoColorPool.obj"
	-@erase "$(INTDIR)\JDFAutoColorPool.sbr"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionOp.obj"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionOp.sbr"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoColorSpaceSubstitute.obj"
	-@erase "$(INTDIR)\JDFAutoColorSpaceSubstitute.sbr"
	-@erase "$(INTDIR)\JDFAutoColorsUsed.obj"
	-@erase "$(INTDIR)\JDFAutoColorsUsed.sbr"
	-@erase "$(INTDIR)\JDFAutoComChannel.obj"
	-@erase "$(INTDIR)\JDFAutoComChannel.sbr"
	-@erase "$(INTDIR)\JDFAutoCommand.obj"
	-@erase "$(INTDIR)\JDFAutoCommand.sbr"
	-@erase "$(INTDIR)\JDFAutoComment.obj"
	-@erase "$(INTDIR)\JDFAutoComment.sbr"
	-@erase "$(INTDIR)\JDFAutoCompany.obj"
	-@erase "$(INTDIR)\JDFAutoCompany.sbr"
	-@erase "$(INTDIR)\JDFAutoComponent.obj"
	-@erase "$(INTDIR)\JDFAutoComponent.sbr"
	-@erase "$(INTDIR)\JDFAutoContact.obj"
	-@erase "$(INTDIR)\JDFAutoContact.sbr"
	-@erase "$(INTDIR)\JDFAutoContactCopyParams.obj"
	-@erase "$(INTDIR)\JDFAutoContactCopyParams.sbr"
	-@erase "$(INTDIR)\JDFAutoContainer.obj"
	-@erase "$(INTDIR)\JDFAutoContainer.sbr"
	-@erase "$(INTDIR)\JDFAutoContentObject.obj"
	-@erase "$(INTDIR)\JDFAutoContentObject.sbr"
	-@erase "$(INTDIR)\JDFAutoConventionalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFAutoConventionalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCostCenter.obj"
	-@erase "$(INTDIR)\JDFAutoCostCenter.sbr"
	-@erase "$(INTDIR)\JDFAutoCounterReset.obj"
	-@erase "$(INTDIR)\JDFAutoCounterReset.sbr"
	-@erase "$(INTDIR)\JDFAutoCoverApplicationParams.obj"
	-@erase "$(INTDIR)\JDFAutoCoverApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCrease.obj"
	-@erase "$(INTDIR)\JDFAutoCrease.sbr"
	-@erase "$(INTDIR)\JDFAutoCreasingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCreasingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCreated.obj"
	-@erase "$(INTDIR)\JDFAutoCreated.sbr"
	-@erase "$(INTDIR)\JDFAutoCreditCard.obj"
	-@erase "$(INTDIR)\JDFAutoCreditCard.sbr"
	-@erase "$(INTDIR)\JDFAutoCustomerInfo.obj"
	-@erase "$(INTDIR)\JDFAutoCustomerInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoCustomerMessage.obj"
	-@erase "$(INTDIR)\JDFAutoCustomerMessage.sbr"
	-@erase "$(INTDIR)\JDFAutoCut.obj"
	-@erase "$(INTDIR)\JDFAutoCut.sbr"
	-@erase "$(INTDIR)\JDFAutoCutBlock.obj"
	-@erase "$(INTDIR)\JDFAutoCutBlock.sbr"
	-@erase "$(INTDIR)\JDFAutoCutMark.obj"
	-@erase "$(INTDIR)\JDFAutoCutMark.sbr"
	-@erase "$(INTDIR)\JDFAutoCuttingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDBMergeParams.obj"
	-@erase "$(INTDIR)\JDFAutoDBMergeParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDBRules.obj"
	-@erase "$(INTDIR)\JDFAutoDBRules.sbr"
	-@erase "$(INTDIR)\JDFAutoDBSchema.obj"
	-@erase "$(INTDIR)\JDFAutoDBSchema.sbr"
	-@erase "$(INTDIR)\JDFAutoDBSelection.obj"
	-@erase "$(INTDIR)\JDFAutoDBSelection.sbr"
	-@erase "$(INTDIR)\JDFAutoDCTParams.obj"
	-@erase "$(INTDIR)\JDFAutoDCTParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDeleted.obj"
	-@erase "$(INTDIR)\JDFAutoDeleted.sbr"
	-@erase "$(INTDIR)\JDFAutoDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFAutoDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFAutoDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDensityMeasuringField.obj"
	-@erase "$(INTDIR)\JDFAutoDensityMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFAutoDependencies.obj"
	-@erase "$(INTDIR)\JDFAutoDependencies.sbr"
	-@erase "$(INTDIR)\JDFAutoDevCap.obj"
	-@erase "$(INTDIR)\JDFAutoDevCap.sbr"
	-@erase "$(INTDIR)\JDFAutoDevCaps.obj"
	-@erase "$(INTDIR)\JDFAutoDevCaps.sbr"
	-@erase "$(INTDIR)\JDFAutoDevelopingParams.obj"
	-@erase "$(INTDIR)\JDFAutoDevelopingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDevice.obj"
	-@erase "$(INTDIR)\JDFAutoDevice.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceCap.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceCap.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceFilter.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceInfo.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceList.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceList.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceMark.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceMark.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceNColor.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceNColor.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceNSpace.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceNSpace.sbr"
	-@erase "$(INTDIR)\JDFAutoDigitalDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFAutoDigitalDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDigitalMedia.obj"
	-@erase "$(INTDIR)\JDFAutoDigitalMedia.sbr"
	-@erase "$(INTDIR)\JDFAutoDigitalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFAutoDigitalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDisjointing.obj"
	-@erase "$(INTDIR)\JDFAutoDisjointing.sbr"
	-@erase "$(INTDIR)\JDFAutoDisplayGroup.obj"
	-@erase "$(INTDIR)\JDFAutoDisplayGroup.sbr"
	-@erase "$(INTDIR)\JDFAutoDisplayGroupPool.obj"
	-@erase "$(INTDIR)\JDFAutoDisplayGroupPool.sbr"
	-@erase "$(INTDIR)\JDFAutoDisposition.obj"
	-@erase "$(INTDIR)\JDFAutoDisposition.sbr"
	-@erase "$(INTDIR)\JDFAutoDividingParams.obj"
	-@erase "$(INTDIR)\JDFAutoDividingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDrop.obj"
	-@erase "$(INTDIR)\JDFAutoDrop.sbr"
	-@erase "$(INTDIR)\JDFAutoDropIntent.obj"
	-@erase "$(INTDIR)\JDFAutoDropIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoDropItem.obj"
	-@erase "$(INTDIR)\JDFAutoDropItem.sbr"
	-@erase "$(INTDIR)\JDFAutoDropItemIntent.obj"
	-@erase "$(INTDIR)\JDFAutoDropItemIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoDynamicField.obj"
	-@erase "$(INTDIR)\JDFAutoDynamicField.sbr"
	-@erase "$(INTDIR)\JDFAutoDynamicInput.obj"
	-@erase "$(INTDIR)\JDFAutoDynamicInput.sbr"
	-@erase "$(INTDIR)\JDFAutoEdgeGluing.obj"
	-@erase "$(INTDIR)\JDFAutoEdgeGluing.sbr"
	-@erase "$(INTDIR)\JDFAutoElementColorParams.obj"
	-@erase "$(INTDIR)\JDFAutoElementColorParams.sbr"
	-@erase "$(INTDIR)\JDFAutoEmboss.obj"
	-@erase "$(INTDIR)\JDFAutoEmboss.sbr"
	-@erase "$(INTDIR)\JDFAutoEmbossingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoEmbossingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoEmbossingItem.obj"
	-@erase "$(INTDIR)\JDFAutoEmbossingItem.sbr"
	-@erase "$(INTDIR)\JDFAutoEmbossingParams.obj"
	-@erase "$(INTDIR)\JDFAutoEmbossingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoEmployee.obj"
	-@erase "$(INTDIR)\JDFAutoEmployee.sbr"
	-@erase "$(INTDIR)\JDFAutoEmployeeDef.obj"
	-@erase "$(INTDIR)\JDFAutoEmployeeDef.sbr"
	-@erase "$(INTDIR)\JDFAutoEndSheet.obj"
	-@erase "$(INTDIR)\JDFAutoEndSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoEndSheetGluingParams.obj"
	-@erase "$(INTDIR)\JDFAutoEndSheetGluingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoEnumerationSpan.obj"
	-@erase "$(INTDIR)\JDFAutoEnumerationSpan.sbr"
	-@erase "$(INTDIR)\JDFAutoError.obj"
	-@erase "$(INTDIR)\JDFAutoError.sbr"
	-@erase "$(INTDIR)\JDFAutoEvent.obj"
	-@erase "$(INTDIR)\JDFAutoEvent.sbr"
	-@erase "$(INTDIR)\JDFAutoExposedMedia.obj"
	-@erase "$(INTDIR)\JDFAutoExposedMedia.sbr"
	-@erase "$(INTDIR)\JDFAutoFCNKey.obj"
	-@erase "$(INTDIR)\JDFAutoFCNKey.sbr"
	-@erase "$(INTDIR)\JDFAutoFeatureAttribute.obj"
	-@erase "$(INTDIR)\JDFAutoFeatureAttribute.sbr"
	-@erase "$(INTDIR)\JDFAutoFeaturePool.obj"
	-@erase "$(INTDIR)\JDFAutoFeaturePool.sbr"
	-@erase "$(INTDIR)\JDFAutoFeeder.obj"
	-@erase "$(INTDIR)\JDFAutoFeeder.sbr"
	-@erase "$(INTDIR)\JDFAutoFeederQualityParams.obj"
	-@erase "$(INTDIR)\JDFAutoFeederQualityParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFeedingParams.obj"
	-@erase "$(INTDIR)\JDFAutoFeedingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFileAlias.obj"
	-@erase "$(INTDIR)\JDFAutoFileAlias.sbr"
	-@erase "$(INTDIR)\JDFAutoFileSpec.obj"
	-@erase "$(INTDIR)\JDFAutoFileSpec.sbr"
	-@erase "$(INTDIR)\JDFAutoFitPolicy.obj"
	-@erase "$(INTDIR)\JDFAutoFitPolicy.sbr"
	-@erase "$(INTDIR)\JDFAutoFlateParams.obj"
	-@erase "$(INTDIR)\JDFAutoFlateParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFlushedResources.obj"
	-@erase "$(INTDIR)\JDFAutoFlushedResources.sbr"
	-@erase "$(INTDIR)\JDFAutoFlushQueueParams.obj"
	-@erase "$(INTDIR)\JDFAutoFlushQueueParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFlushResourceParams.obj"
	-@erase "$(INTDIR)\JDFAutoFlushResourceParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFold.obj"
	-@erase "$(INTDIR)\JDFAutoFold.sbr"
	-@erase "$(INTDIR)\JDFAutoFoldingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoFoldingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoFoldingParams.obj"
	-@erase "$(INTDIR)\JDFAutoFoldingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFontParams.obj"
	-@erase "$(INTDIR)\JDFAutoFontParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFontPolicy.obj"
	-@erase "$(INTDIR)\JDFAutoFontPolicy.sbr"
	-@erase "$(INTDIR)\JDFAutoFormatConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoFormatConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoGatheringParams.obj"
	-@erase "$(INTDIR)\JDFAutoGatheringParams.sbr"
	-@erase "$(INTDIR)\JDFAutoGlue.obj"
	-@erase "$(INTDIR)\JDFAutoGlue.sbr"
	-@erase "$(INTDIR)\JDFAutoGlueApplication.obj"
	-@erase "$(INTDIR)\JDFAutoGlueApplication.sbr"
	-@erase "$(INTDIR)\JDFAutoGlueLine.obj"
	-@erase "$(INTDIR)\JDFAutoGlueLine.sbr"
	-@erase "$(INTDIR)\JDFAutoGluingParams.obj"
	-@erase "$(INTDIR)\JDFAutoGluingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoHardCoverBinding.obj"
	-@erase "$(INTDIR)\JDFAutoHardCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoHeadBandApplicationParams.obj"
	-@erase "$(INTDIR)\JDFAutoHeadBandApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoHole.obj"
	-@erase "$(INTDIR)\JDFAutoHole.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleLine.obj"
	-@erase "$(INTDIR)\JDFAutoHoleLine.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleList.obj"
	-@erase "$(INTDIR)\JDFAutoHoleList.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleMakingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoHoleMakingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleMakingParams.obj"
	-@erase "$(INTDIR)\JDFAutoHoleMakingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoIcon.obj"
	-@erase "$(INTDIR)\JDFAutoIcon.sbr"
	-@erase "$(INTDIR)\JDFAutoIconList.obj"
	-@erase "$(INTDIR)\JDFAutoIconList.sbr"
	-@erase "$(INTDIR)\JDFAutoIdentificationField.obj"
	-@erase "$(INTDIR)\JDFAutoIdentificationField.sbr"
	-@erase "$(INTDIR)\JDFAutoIDInfo.obj"
	-@erase "$(INTDIR)\JDFAutoIDInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPCover.obj"
	-@erase "$(INTDIR)\JDFAutoIDPCover.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPFinishing.obj"
	-@erase "$(INTDIR)\JDFAutoIDPFinishing.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPFolding.obj"
	-@erase "$(INTDIR)\JDFAutoIDPFolding.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPHoleMaking.obj"
	-@erase "$(INTDIR)\JDFAutoIDPHoleMaking.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPImageShift.obj"
	-@erase "$(INTDIR)\JDFAutoIDPImageShift.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPJobSheet.obj"
	-@erase "$(INTDIR)\JDFAutoIDPJobSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPLayout.obj"
	-@erase "$(INTDIR)\JDFAutoIDPLayout.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPrintingParams.obj"
	-@erase "$(INTDIR)\JDFAutoIDPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPStitching.obj"
	-@erase "$(INTDIR)\JDFAutoIDPStitching.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPTrimming.obj"
	-@erase "$(INTDIR)\JDFAutoIDPTrimming.sbr"
	-@erase "$(INTDIR)\JDFAutoImageCompression.obj"
	-@erase "$(INTDIR)\JDFAutoImageCompression.sbr"
	-@erase "$(INTDIR)\JDFAutoImageCompressionParams.obj"
	-@erase "$(INTDIR)\JDFAutoImageCompressionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoImageReplacementParams.obj"
	-@erase "$(INTDIR)\JDFAutoImageReplacementParams.sbr"
	-@erase "$(INTDIR)\JDFAutoImageSetterParams.obj"
	-@erase "$(INTDIR)\JDFAutoImageSetterParams.sbr"
	-@erase "$(INTDIR)\JDFAutoImageShift.obj"
	-@erase "$(INTDIR)\JDFAutoImageShift.sbr"
	-@erase "$(INTDIR)\JDFAutoInk.obj"
	-@erase "$(INTDIR)\JDFAutoInk.sbr"
	-@erase "$(INTDIR)\JDFAutoInkZoneCalculationParams.obj"
	-@erase "$(INTDIR)\JDFAutoInkZoneCalculationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoInkZoneProfile.obj"
	-@erase "$(INTDIR)\JDFAutoInkZoneProfile.sbr"
	-@erase "$(INTDIR)\JDFAutoInsert.obj"
	-@erase "$(INTDIR)\JDFAutoInsert.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoInsertingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertingParams.obj"
	-@erase "$(INTDIR)\JDFAutoInsertingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertList.obj"
	-@erase "$(INTDIR)\JDFAutoInsertList.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertSheet.obj"
	-@erase "$(INTDIR)\JDFAutoInsertSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoInterpretedPDLData.obj"
	-@erase "$(INTDIR)\JDFAutoInterpretedPDLData.sbr"
	-@erase "$(INTDIR)\JDFAutoInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFAutoInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoJacketingParams.obj"
	-@erase "$(INTDIR)\JDFAutoJacketingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoJDFController.obj"
	-@erase "$(INTDIR)\JDFAutoJDFController.sbr"
	-@erase "$(INTDIR)\JDFAutoJDFService.obj"
	-@erase "$(INTDIR)\JDFAutoJDFService.sbr"
	-@erase "$(INTDIR)\JDFAutoJMF.obj"
	-@erase "$(INTDIR)\JDFAutoJMF.sbr"
	-@erase "$(INTDIR)\JDFAutoJobField.obj"
	-@erase "$(INTDIR)\JDFAutoJobField.sbr"
	-@erase "$(INTDIR)\JDFAutoJobPhase.obj"
	-@erase "$(INTDIR)\JDFAutoJobPhase.sbr"
	-@erase "$(INTDIR)\JDFAutoKnownMsgQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoKnownMsgQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLabelingParams.obj"
	-@erase "$(INTDIR)\JDFAutoLabelingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLaminatingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoLaminatingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoLaminatingParams.obj"
	-@erase "$(INTDIR)\JDFAutoLaminatingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLayerDetails.obj"
	-@erase "$(INTDIR)\JDFAutoLayerDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoLayerList.obj"
	-@erase "$(INTDIR)\JDFAutoLayerList.sbr"
	-@erase "$(INTDIR)\JDFAutoLayout.obj"
	-@erase "$(INTDIR)\JDFAutoLayout.sbr"
	-@erase "$(INTDIR)\JDFAutoLayoutElement.obj"
	-@erase "$(INTDIR)\JDFAutoLayoutElement.sbr"
	-@erase "$(INTDIR)\JDFAutoLayoutIntent.obj"
	-@erase "$(INTDIR)\JDFAutoLayoutIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoLayoutPreparationParams.obj"
	-@erase "$(INTDIR)\JDFAutoLayoutPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLoc.obj"
	-@erase "$(INTDIR)\JDFAutoLoc.sbr"
	-@erase "$(INTDIR)\JDFAutoLocation.obj"
	-@erase "$(INTDIR)\JDFAutoLocation.sbr"
	-@erase "$(INTDIR)\JDFAutoLongFold.obj"
	-@erase "$(INTDIR)\JDFAutoLongFold.sbr"
	-@erase "$(INTDIR)\JDFAutoLongGlue.obj"
	-@erase "$(INTDIR)\JDFAutoLongGlue.sbr"
	-@erase "$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.obj"
	-@erase "$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLongPerforate.obj"
	-@erase "$(INTDIR)\JDFAutoLongPerforate.sbr"
	-@erase "$(INTDIR)\JDFAutoLongSlit.obj"
	-@erase "$(INTDIR)\JDFAutoLongSlit.sbr"
	-@erase "$(INTDIR)\JDFAutoLZWParams.obj"
	-@erase "$(INTDIR)\JDFAutoLZWParams.sbr"
	-@erase "$(INTDIR)\JDFAutomacro.obj"
	-@erase "$(INTDIR)\JDFAutomacro.sbr"
	-@erase "$(INTDIR)\JDFAutoMacroPool.obj"
	-@erase "$(INTDIR)\JDFAutoMacroPool.sbr"
	-@erase "$(INTDIR)\JDFAutoManualLaborParams.obj"
	-@erase "$(INTDIR)\JDFAutoManualLaborParams.sbr"
	-@erase "$(INTDIR)\JDFAutoMarkObject.obj"
	-@erase "$(INTDIR)\JDFAutoMarkObject.sbr"
	-@erase "$(INTDIR)\JDFAutomatedOverprintParams.obj"
	-@erase "$(INTDIR)\JDFAutomatedOverprintParams.sbr"
	-@erase "$(INTDIR)\JDFAutoMedia.obj"
	-@erase "$(INTDIR)\JDFAutoMedia.sbr"
	-@erase "$(INTDIR)\JDFAutoMediaIntent.obj"
	-@erase "$(INTDIR)\JDFAutoMediaIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoMediaSource.obj"
	-@erase "$(INTDIR)\JDFAutoMediaSource.sbr"
	-@erase "$(INTDIR)\JDFAutoMerged.obj"
	-@erase "$(INTDIR)\JDFAutoMerged.sbr"
	-@erase "$(INTDIR)\JDFAutoMessage.obj"
	-@erase "$(INTDIR)\JDFAutoMessage.sbr"
	-@erase "$(INTDIR)\JDFAutoMessageService.obj"
	-@erase "$(INTDIR)\JDFAutoMessageService.sbr"
	-@erase "$(INTDIR)\JDFAutoMISDetails.obj"
	-@erase "$(INTDIR)\JDFAutoMISDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoModified.obj"
	-@erase "$(INTDIR)\JDFAutoModified.sbr"
	-@erase "$(INTDIR)\JDFAutoModulePhase.obj"
	-@erase "$(INTDIR)\JDFAutoModulePhase.sbr"
	-@erase "$(INTDIR)\JDFAutoModuleStatus.obj"
	-@erase "$(INTDIR)\JDFAutoModuleStatus.sbr"
	-@erase "$(INTDIR)\JDFAutoMsgFilter.obj"
	-@erase "$(INTDIR)\JDFAutoMsgFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoNewJDFCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoNewJDFCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNewJDFQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoNewJDFQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfo.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfoCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfoCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfoQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfoQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfoResp.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfoResp.sbr"
	-@erase "$(INTDIR)\JDFAutonot.obj"
	-@erase "$(INTDIR)\JDFAutonot.sbr"
	-@erase "$(INTDIR)\JDFAutoNotification.obj"
	-@erase "$(INTDIR)\JDFAutoNotification.sbr"
	-@erase "$(INTDIR)\JDFAutoNotificationDef.obj"
	-@erase "$(INTDIR)\JDFAutoNotificationDef.sbr"
	-@erase "$(INTDIR)\JDFAutoNotificationFilter.obj"
	-@erase "$(INTDIR)\JDFAutoNotificationFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoNumberingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberingParam.obj"
	-@erase "$(INTDIR)\JDFAutoNumberingParam.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberingParams.obj"
	-@erase "$(INTDIR)\JDFAutoNumberingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberItem.obj"
	-@erase "$(INTDIR)\JDFAutoNumberItem.sbr"
	-@erase "$(INTDIR)\JDFAutoObjectResolution.obj"
	-@erase "$(INTDIR)\JDFAutoObjectResolution.sbr"
	-@erase "$(INTDIR)\JDFAutoObservationTarget.obj"
	-@erase "$(INTDIR)\JDFAutoObservationTarget.sbr"
	-@erase "$(INTDIR)\JDFAutoOccupation.obj"
	-@erase "$(INTDIR)\JDFAutoOccupation.sbr"
	-@erase "$(INTDIR)\JDFAutoor.obj"
	-@erase "$(INTDIR)\JDFAutoor.sbr"
	-@erase "$(INTDIR)\JDFAutoOrderingParams.obj"
	-@erase "$(INTDIR)\JDFAutoOrderingParams.sbr"
	-@erase "$(INTDIR)\JDFAutootherwise.obj"
	-@erase "$(INTDIR)\JDFAutootherwise.sbr"
	-@erase "$(INTDIR)\JDFAutoPackingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoPackingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoPackingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPackingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPageCell.obj"
	-@erase "$(INTDIR)\JDFAutoPageCell.sbr"
	-@erase "$(INTDIR)\JDFAutoPageData.obj"
	-@erase "$(INTDIR)\JDFAutoPageData.sbr"
	-@erase "$(INTDIR)\JDFAutoPageList.obj"
	-@erase "$(INTDIR)\JDFAutoPageList.sbr"
	-@erase "$(INTDIR)\JDFAutoPallet.obj"
	-@erase "$(INTDIR)\JDFAutoPallet.sbr"
	-@erase "$(INTDIR)\JDFAutoPalletizingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPalletizingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPart.obj"
	-@erase "$(INTDIR)\JDFAutoPart.sbr"
	-@erase "$(INTDIR)\JDFAutoPartStatus.obj"
	-@erase "$(INTDIR)\JDFAutoPartStatus.sbr"
	-@erase "$(INTDIR)\JDFAutoPayment.obj"
	-@erase "$(INTDIR)\JDFAutoPayment.sbr"
	-@erase "$(INTDIR)\JDFAutoPDFInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPDFInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPDFToPSConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoPDFToPSConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPDFXParams.obj"
	-@erase "$(INTDIR)\JDFAutoPDFXParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPDLResourceAlias.obj"
	-@erase "$(INTDIR)\JDFAutoPDLResourceAlias.sbr"
	-@erase "$(INTDIR)\JDFAutoPerforate.obj"
	-@erase "$(INTDIR)\JDFAutoPerforate.sbr"
	-@erase "$(INTDIR)\JDFAutoPerforatingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPerforatingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPerformance.obj"
	-@erase "$(INTDIR)\JDFAutoPerformance.sbr"
	-@erase "$(INTDIR)\JDFAutoPerson.obj"
	-@erase "$(INTDIR)\JDFAutoPerson.sbr"
	-@erase "$(INTDIR)\JDFAutoPhaseTime.obj"
	-@erase "$(INTDIR)\JDFAutoPhaseTime.sbr"
	-@erase "$(INTDIR)\JDFAutoPipeParams.obj"
	-@erase "$(INTDIR)\JDFAutoPipeParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPixelColorant.obj"
	-@erase "$(INTDIR)\JDFAutoPixelColorant.sbr"
	-@erase "$(INTDIR)\JDFAutoPlaceHolderResource.obj"
	-@erase "$(INTDIR)\JDFAutoPlaceHolderResource.sbr"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBinding.obj"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPlateCopyParams.obj"
	-@erase "$(INTDIR)\JDFAutoPlateCopyParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPosition.obj"
	-@erase "$(INTDIR)\JDFAutoPosition.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightAction.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightAction.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightAnalysis.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightAnalysis.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightArgument.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightArgument.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightConstraint.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightConstraint.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightDetail.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightDetail.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightInstance.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightInstance.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightInstanceDetail.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightInstanceDetail.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightInventory.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightInventory.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightParams.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightProfile.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightProfile.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightReport.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightReport.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightReportRulePool.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightReportRulePool.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightValue.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightValue.sbr"
	-@erase "$(INTDIR)\JDFAutoPRError.obj"
	-@erase "$(INTDIR)\JDFAutoPRError.sbr"
	-@erase "$(INTDIR)\JDFAutoPreview.obj"
	-@erase "$(INTDIR)\JDFAutoPreview.sbr"
	-@erase "$(INTDIR)\JDFAutoPreviewGenerationParams.obj"
	-@erase "$(INTDIR)\JDFAutoPreviewGenerationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPRGroup.obj"
	-@erase "$(INTDIR)\JDFAutoPRGroup.sbr"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurence.obj"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurence.sbr"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurenceBase.obj"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurenceBase.sbr"
	-@erase "$(INTDIR)\JDFAutoPricing.obj"
	-@erase "$(INTDIR)\JDFAutoPricing.sbr"
	-@erase "$(INTDIR)\JDFAutoPrintCondition.obj"
	-@erase "$(INTDIR)\JDFAutoPrintCondition.sbr"
	-@erase "$(INTDIR)\JDFAutoPrintConditionColor.obj"
	-@erase "$(INTDIR)\JDFAutoPrintConditionColor.sbr"
	-@erase "$(INTDIR)\JDFAutoPrintRollingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPrintRollingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPRItem.obj"
	-@erase "$(INTDIR)\JDFAutoPRItem.sbr"
	-@erase "$(INTDIR)\JDFAutoPROccurence.obj"
	-@erase "$(INTDIR)\JDFAutoPROccurence.sbr"
	-@erase "$(INTDIR)\JDFAutoProcessRun.obj"
	-@erase "$(INTDIR)\JDFAutoProcessRun.sbr"
	-@erase "$(INTDIR)\JDFAutoProductionIntent.obj"
	-@erase "$(INTDIR)\JDFAutoProductionIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoProofingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoProofingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoProofingParams.obj"
	-@erase "$(INTDIR)\JDFAutoProofingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoProofItem.obj"
	-@erase "$(INTDIR)\JDFAutoProofItem.sbr"
	-@erase "$(INTDIR)\JDFAutoProperties.obj"
	-@erase "$(INTDIR)\JDFAutoProperties.sbr"
	-@erase "$(INTDIR)\JDFAutoPRRule.obj"
	-@erase "$(INTDIR)\JDFAutoPRRule.sbr"
	-@erase "$(INTDIR)\JDFAutoPRRuleAttr.obj"
	-@erase "$(INTDIR)\JDFAutoPRRuleAttr.sbr"
	-@erase "$(INTDIR)\JDFAutoPSToPDFConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoPSToPDFConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQualityControlParams.obj"
	-@erase "$(INTDIR)\JDFAutoQualityControlParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQualityControlResult.obj"
	-@erase "$(INTDIR)\JDFAutoQualityControlResult.sbr"
	-@erase "$(INTDIR)\JDFAutoQualityMeasurement.obj"
	-@erase "$(INTDIR)\JDFAutoQualityMeasurement.sbr"
	-@erase "$(INTDIR)\JDFAutoQuery.obj"
	-@erase "$(INTDIR)\JDFAutoQuery.sbr"
	-@erase "$(INTDIR)\JDFAutoQueue.obj"
	-@erase "$(INTDIR)\JDFAutoQueue.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntry.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntry.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDef.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDef.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDefList.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDefList.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPosParams.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPosParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPriParams.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPriParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueFilter.obj"
	-@erase "$(INTDIR)\JDFAutoQueueFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueSubmissionParams.obj"
	-@erase "$(INTDIR)\JDFAutoQueueSubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRegisterMark.obj"
	-@erase "$(INTDIR)\JDFAutoRegisterMark.sbr"
	-@erase "$(INTDIR)\JDFAutoRegisterRibbon.obj"
	-@erase "$(INTDIR)\JDFAutoRegisterRibbon.sbr"
	-@erase "$(INTDIR)\JDFAutoRemoved.obj"
	-@erase "$(INTDIR)\JDFAutoRemoved.sbr"
	-@erase "$(INTDIR)\JDFAutoRenderingParams.obj"
	-@erase "$(INTDIR)\JDFAutoRenderingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRequestQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFAutoRequestQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceAudit.obj"
	-@erase "$(INTDIR)\JDFAutoResourceAudit.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourceCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceDefinitionParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourceDefinitionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceInfo.obj"
	-@erase "$(INTDIR)\JDFAutoResourceInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceParam.obj"
	-@erase "$(INTDIR)\JDFAutoResourceParam.sbr"
	-@erase "$(INTDIR)\JDFAutoResourcePullParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourcePullParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourceQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResponse.obj"
	-@erase "$(INTDIR)\JDFAutoResponse.sbr"
	-@erase "$(INTDIR)\JDFAutoResubmissionParams.obj"
	-@erase "$(INTDIR)\JDFAutoResubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoReturnQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFAutoReturnQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRingBinding.obj"
	-@erase "$(INTDIR)\JDFAutoRingBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoRingBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoRingBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRollStand.obj"
	-@erase "$(INTDIR)\JDFAutoRollStand.sbr"
	-@erase "$(INTDIR)\JDFAutoRunList.obj"
	-@erase "$(INTDIR)\JDFAutoRunList.sbr"
	-@erase "$(INTDIR)\JDFAutoSaddleStitching.obj"
	-@erase "$(INTDIR)\JDFAutoSaddleStitching.sbr"
	-@erase "$(INTDIR)\JDFAutoSaddleStitchingParams.obj"
	-@erase "$(INTDIR)\JDFAutoSaddleStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoScanParams.obj"
	-@erase "$(INTDIR)\JDFAutoScanParams.sbr"
	-@erase "$(INTDIR)\JDFAutoScavengerArea.obj"
	-@erase "$(INTDIR)\JDFAutoScavengerArea.sbr"
	-@erase "$(INTDIR)\JDFAutoScore.obj"
	-@erase "$(INTDIR)\JDFAutoScore.sbr"
	-@erase "$(INTDIR)\JDFAutoScreeningIntent.obj"
	-@erase "$(INTDIR)\JDFAutoScreeningIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoScreeningParams.obj"
	-@erase "$(INTDIR)\JDFAutoScreeningParams.sbr"
	-@erase "$(INTDIR)\JDFAutoScreenSelector.obj"
	-@erase "$(INTDIR)\JDFAutoScreenSelector.sbr"
	-@erase "$(INTDIR)\JDFAutoSeparationControlParams.obj"
	-@erase "$(INTDIR)\JDFAutoSeparationControlParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSeparationSpec.obj"
	-@erase "$(INTDIR)\JDFAutoSeparationSpec.sbr"
	-@erase "$(INTDIR)\JDFAutoset.obj"
	-@erase "$(INTDIR)\JDFAutoset.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeCut.obj"
	-@erase "$(INTDIR)\JDFAutoShapeCut.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingParams.obj"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeElement.obj"
	-@erase "$(INTDIR)\JDFAutoShapeElement.sbr"
	-@erase "$(INTDIR)\JDFAutoSheet.obj"
	-@erase "$(INTDIR)\JDFAutoSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoShrinkingParams.obj"
	-@erase "$(INTDIR)\JDFAutoShrinkingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoShutDownCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoShutDownCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSideSewing.obj"
	-@erase "$(INTDIR)\JDFAutoSideSewing.sbr"
	-@erase "$(INTDIR)\JDFAutoSideSewingParams.obj"
	-@erase "$(INTDIR)\JDFAutoSideSewingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSideStitching.obj"
	-@erase "$(INTDIR)\JDFAutoSideStitching.sbr"
	-@erase "$(INTDIR)\JDFAutoSignal.obj"
	-@erase "$(INTDIR)\JDFAutoSignal.sbr"
	-@erase "$(INTDIR)\JDFAutoSignature.obj"
	-@erase "$(INTDIR)\JDFAutoSignature.sbr"
	-@erase "$(INTDIR)\JDFAutoSignatureCell.obj"
	-@erase "$(INTDIR)\JDFAutoSignatureCell.sbr"
	-@erase "$(INTDIR)\JDFAutoSizeIntent.obj"
	-@erase "$(INTDIR)\JDFAutoSizeIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoSoftCoverBinding.obj"
	-@erase "$(INTDIR)\JDFAutoSoftCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoSpawned.obj"
	-@erase "$(INTDIR)\JDFAutoSpawned.sbr"
	-@erase "$(INTDIR)\JDFAutoSpinePreparationParams.obj"
	-@erase "$(INTDIR)\JDFAutoSpinePreparationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSpineTapingParams.obj"
	-@erase "$(INTDIR)\JDFAutoSpineTapingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStackingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStackingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStatusPool.obj"
	-@erase "$(INTDIR)\JDFAutoStatusPool.sbr"
	-@erase "$(INTDIR)\JDFAutoStatusQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoStatusQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStitchingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStopPersChParams.obj"
	-@erase "$(INTDIR)\JDFAutoStopPersChParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStrap.obj"
	-@erase "$(INTDIR)\JDFAutoStrap.sbr"
	-@erase "$(INTDIR)\JDFAutoStrappingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStrappingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStringListValue.obj"
	-@erase "$(INTDIR)\JDFAutoStringListValue.sbr"
	-@erase "$(INTDIR)\JDFAutoStripBinding.obj"
	-@erase "$(INTDIR)\JDFAutoStripBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoStripBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStripBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStripCellParams.obj"
	-@erase "$(INTDIR)\JDFAutoStripCellParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStrippingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStrippingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSubmissionMethods.obj"
	-@erase "$(INTDIR)\JDFAutoSubmissionMethods.sbr"
	-@erase "$(INTDIR)\JDFAutoSubscription.obj"
	-@erase "$(INTDIR)\JDFAutoSubscription.sbr"
	-@erase "$(INTDIR)\JDFAutoSurface.obj"
	-@erase "$(INTDIR)\JDFAutoSurface.sbr"
	-@erase "$(INTDIR)\JDFAutoSystemTimeSet.obj"
	-@erase "$(INTDIR)\JDFAutoSystemTimeSet.sbr"
	-@erase "$(INTDIR)\JDFAutoTabs.obj"
	-@erase "$(INTDIR)\JDFAutoTabs.sbr"
	-@erase "$(INTDIR)\JDFAutoTape.obj"
	-@erase "$(INTDIR)\JDFAutoTape.sbr"
	-@erase "$(INTDIR)\JDFAutoTest.obj"
	-@erase "$(INTDIR)\JDFAutoTest.sbr"
	-@erase "$(INTDIR)\JDFAutoTestPool.obj"
	-@erase "$(INTDIR)\JDFAutoTestPool.sbr"
	-@erase "$(INTDIR)\JDFAutoTestRef.obj"
	-@erase "$(INTDIR)\JDFAutoTestRef.sbr"
	-@erase "$(INTDIR)\JDFAutoThinPDFParams.obj"
	-@erase "$(INTDIR)\JDFAutoThinPDFParams.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSealing.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSealing.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSealingParams.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSealingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSewing.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSewing.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSewingParams.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSewingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoTIFFEmbeddedFile.obj"
	-@erase "$(INTDIR)\JDFAutoTIFFEmbeddedFile.sbr"
	-@erase "$(INTDIR)\JDFAutoTIFFFormatParams.obj"
	-@erase "$(INTDIR)\JDFAutoTIFFFormatParams.sbr"
	-@erase "$(INTDIR)\JDFAutoTIFFtag.obj"
	-@erase "$(INTDIR)\JDFAutoTIFFtag.sbr"
	-@erase "$(INTDIR)\JDFAutoTile.obj"
	-@erase "$(INTDIR)\JDFAutoTile.sbr"
	-@erase "$(INTDIR)\JDFAutoTool.obj"
	-@erase "$(INTDIR)\JDFAutoTool.sbr"
	-@erase "$(INTDIR)\JDFAutoTrackFilter.obj"
	-@erase "$(INTDIR)\JDFAutoTrackFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoTrackResult.obj"
	-@erase "$(INTDIR)\JDFAutoTrackResult.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferCurve.obj"
	-@erase "$(INTDIR)\JDFAutoTransferCurve.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferCurvePool.obj"
	-@erase "$(INTDIR)\JDFAutoTransferCurvePool.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferCurveSet.obj"
	-@erase "$(INTDIR)\JDFAutoTransferCurveSet.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferFunctionControl.obj"
	-@erase "$(INTDIR)\JDFAutoTransferFunctionControl.sbr"
	-@erase "$(INTDIR)\JDFAutoTrappingDetails.obj"
	-@erase "$(INTDIR)\JDFAutoTrappingDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoTrappingOrder.obj"
	-@erase "$(INTDIR)\JDFAutoTrappingOrder.sbr"
	-@erase "$(INTDIR)\JDFAutoTrappingParams.obj"
	-@erase "$(INTDIR)\JDFAutoTrappingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoTrapRegion.obj"
	-@erase "$(INTDIR)\JDFAutoTrapRegion.sbr"
	-@erase "$(INTDIR)\JDFAutoTrigger.obj"
	-@erase "$(INTDIR)\JDFAutoTrigger.sbr"
	-@erase "$(INTDIR)\JDFAutoTrimmingParams.obj"
	-@erase "$(INTDIR)\JDFAutoTrimmingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoValue.obj"
	-@erase "$(INTDIR)\JDFAutoValue.sbr"
	-@erase "$(INTDIR)\JDFAutoValueLoc.obj"
	-@erase "$(INTDIR)\JDFAutoValueLoc.sbr"
	-@erase "$(INTDIR)\JDFAutoVerificationParams.obj"
	-@erase "$(INTDIR)\JDFAutoVerificationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoWakeUpCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoWakeUpCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutowhen.obj"
	-@erase "$(INTDIR)\JDFAutowhen.sbr"
	-@erase "$(INTDIR)\JDFAutoWireCombBinding.obj"
	-@erase "$(INTDIR)\JDFAutoWireCombBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoWireCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoWireCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoWrappingParams.obj"
	-@erase "$(INTDIR)\JDFAutoWrappingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoxor.obj"
	-@erase "$(INTDIR)\JDFAutoxor.sbr"
	-@erase "$(INTDIR)\JDFBand.obj"
	-@erase "$(INTDIR)\JDFBand.sbr"
	-@erase "$(INTDIR)\JDFBarcode.obj"
	-@erase "$(INTDIR)\JDFBarcode.sbr"
	-@erase "$(INTDIR)\JDFBasicPreflightTest.obj"
	-@erase "$(INTDIR)\JDFBasicPreflightTest.sbr"
	-@erase "$(INTDIR)\JDFBinderySignature.obj"
	-@erase "$(INTDIR)\JDFBinderySignature.sbr"
	-@erase "$(INTDIR)\JDFBindingIntent.obj"
	-@erase "$(INTDIR)\JDFBindingIntent.sbr"
	-@erase "$(INTDIR)\JDFBindingQualityParams.obj"
	-@erase "$(INTDIR)\JDFBindingQualityParams.sbr"
	-@erase "$(INTDIR)\JDFBindItem.obj"
	-@erase "$(INTDIR)\JDFBindItem.sbr"
	-@erase "$(INTDIR)\JDFBindList.obj"
	-@erase "$(INTDIR)\JDFBindList.sbr"
	-@erase "$(INTDIR)\JDFBlockPreparationParams.obj"
	-@erase "$(INTDIR)\JDFBlockPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFBookCase.obj"
	-@erase "$(INTDIR)\JDFBookCase.sbr"
	-@erase "$(INTDIR)\JDFBooleanEvaluation.obj"
	-@erase "$(INTDIR)\JDFBooleanEvaluation.sbr"
	-@erase "$(INTDIR)\JDFBooleanState.obj"
	-@erase "$(INTDIR)\JDFBooleanState.sbr"
	-@erase "$(INTDIR)\JDFBoxArgument.obj"
	-@erase "$(INTDIR)\JDFBoxArgument.sbr"
	-@erase "$(INTDIR)\JDFBoxPackingParams.obj"
	-@erase "$(INTDIR)\JDFBoxPackingParams.sbr"
	-@erase "$(INTDIR)\JDFBoxToBoxDifference.obj"
	-@erase "$(INTDIR)\JDFBoxToBoxDifference.sbr"
	-@erase "$(INTDIR)\JDFBufferParams.obj"
	-@erase "$(INTDIR)\JDFBufferParams.sbr"
	-@erase "$(INTDIR)\JDFBundle.obj"
	-@erase "$(INTDIR)\JDFBundle.sbr"
	-@erase "$(INTDIR)\JDFBundleItem.obj"
	-@erase "$(INTDIR)\JDFBundleItem.sbr"
	-@erase "$(INTDIR)\JDFBundlingParams.obj"
	-@erase "$(INTDIR)\JDFBundlingParams.sbr"
	-@erase "$(INTDIR)\JDFBusinessInfo.obj"
	-@erase "$(INTDIR)\JDFBusinessInfo.sbr"
	-@erase "$(INTDIR)\JDFByteMap.obj"
	-@erase "$(INTDIR)\JDFByteMap.sbr"
	-@erase "$(INTDIR)\JDFcall.obj"
	-@erase "$(INTDIR)\JDFcall.sbr"
	-@erase "$(INTDIR)\JDFCaseMakingParams.obj"
	-@erase "$(INTDIR)\JDFCaseMakingParams.sbr"
	-@erase "$(INTDIR)\JDFCasingInParams.obj"
	-@erase "$(INTDIR)\JDFCasingInParams.sbr"
	-@erase "$(INTDIR)\JDFCCITTFaxParams.obj"
	-@erase "$(INTDIR)\JDFCCITTFaxParams.sbr"
	-@erase "$(INTDIR)\JDFChangedAttribute.obj"
	-@erase "$(INTDIR)\JDFChangedAttribute.sbr"
	-@erase "$(INTDIR)\JDFChangedPath.obj"
	-@erase "$(INTDIR)\JDFChangedPath.sbr"
	-@erase "$(INTDIR)\JDFChannelBinding.obj"
	-@erase "$(INTDIR)\JDFChannelBinding.sbr"
	-@erase "$(INTDIR)\JDFChannelBindingParams.obj"
	-@erase "$(INTDIR)\JDFChannelBindingParams.sbr"
	-@erase "$(INTDIR)\JDFchoice.obj"
	-@erase "$(INTDIR)\JDFchoice.sbr"
	-@erase "$(INTDIR)\JDFCIELABMeasuringField.obj"
	-@erase "$(INTDIR)\JDFCIELABMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFCoilBinding.obj"
	-@erase "$(INTDIR)\JDFCoilBinding.sbr"
	-@erase "$(INTDIR)\JDFCoilBindingParams.obj"
	-@erase "$(INTDIR)\JDFCoilBindingParams.sbr"
	-@erase "$(INTDIR)\JDFCollatingItem.obj"
	-@erase "$(INTDIR)\JDFCollatingItem.sbr"
	-@erase "$(INTDIR)\JDFCollectingParams.obj"
	-@erase "$(INTDIR)\JDFCollectingParams.sbr"
	-@erase "$(INTDIR)\JDFColor.obj"
	-@erase "$(INTDIR)\JDFColor.sbr"
	-@erase "$(INTDIR)\JDFColorantAlias.obj"
	-@erase "$(INTDIR)\JDFColorantAlias.sbr"
	-@erase "$(INTDIR)\JDFColorantControl.obj"
	-@erase "$(INTDIR)\JDFColorantControl.sbr"
	-@erase "$(INTDIR)\JDFColorantZoneDetails.obj"
	-@erase "$(INTDIR)\JDFColorantZoneDetails.sbr"
	-@erase "$(INTDIR)\JDFColorControlStrip.obj"
	-@erase "$(INTDIR)\JDFColorControlStrip.sbr"
	-@erase "$(INTDIR)\JDFColorCorrectionOp.obj"
	-@erase "$(INTDIR)\JDFColorCorrectionOp.sbr"
	-@erase "$(INTDIR)\JDFColorCorrectionParams.obj"
	-@erase "$(INTDIR)\JDFColorCorrectionParams.sbr"
	-@erase "$(INTDIR)\JDFColorIntent.obj"
	-@erase "$(INTDIR)\JDFColorIntent.sbr"
	-@erase "$(INTDIR)\JDFColorMeasurementConditions.obj"
	-@erase "$(INTDIR)\JDFColorMeasurementConditions.sbr"
	-@erase "$(INTDIR)\JDFColorPool.obj"
	-@erase "$(INTDIR)\JDFColorPool.sbr"
	-@erase "$(INTDIR)\JDFColorSpaceConversionOp.obj"
	-@erase "$(INTDIR)\JDFColorSpaceConversionOp.sbr"
	-@erase "$(INTDIR)\JDFColorSpaceConversionParams.obj"
	-@erase "$(INTDIR)\JDFColorSpaceConversionParams.sbr"
	-@erase "$(INTDIR)\JDFColorSpaceSubstitute.obj"
	-@erase "$(INTDIR)\JDFColorSpaceSubstitute.sbr"
	-@erase "$(INTDIR)\JDFColorsUsed.obj"
	-@erase "$(INTDIR)\JDFColorsUsed.sbr"
	-@erase "$(INTDIR)\JDFComChannel.obj"
	-@erase "$(INTDIR)\JDFComChannel.sbr"
	-@erase "$(INTDIR)\JDFCommand.obj"
	-@erase "$(INTDIR)\JDFCommand.sbr"
	-@erase "$(INTDIR)\JDFComment.obj"
	-@erase "$(INTDIR)\JDFComment.sbr"
	-@erase "$(INTDIR)\JDFCompany.obj"
	-@erase "$(INTDIR)\JDFCompany.sbr"
	-@erase "$(INTDIR)\JDFComponent.obj"
	-@erase "$(INTDIR)\JDFComponent.sbr"
	-@erase "$(INTDIR)\JDFContact.obj"
	-@erase "$(INTDIR)\JDFContact.sbr"
	-@erase "$(INTDIR)\JDFContactCopyParams.obj"
	-@erase "$(INTDIR)\JDFContactCopyParams.sbr"
	-@erase "$(INTDIR)\JDFContainer.obj"
	-@erase "$(INTDIR)\JDFContainer.sbr"
	-@erase "$(INTDIR)\JDFContentObject.obj"
	-@erase "$(INTDIR)\JDFContentObject.sbr"
	-@erase "$(INTDIR)\JDFConventionalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFConventionalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFCostCenter.obj"
	-@erase "$(INTDIR)\JDFCostCenter.sbr"
	-@erase "$(INTDIR)\JDFCounterReset.obj"
	-@erase "$(INTDIR)\JDFCounterReset.sbr"
	-@erase "$(INTDIR)\JDFCoverApplicationParams.obj"
	-@erase "$(INTDIR)\JDFCoverApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFCrease.obj"
	-@erase "$(INTDIR)\JDFCrease.sbr"
	-@erase "$(INTDIR)\JDFCreasingParams.obj"
	-@erase "$(INTDIR)\JDFCreasingParams.sbr"
	-@erase "$(INTDIR)\JDFCreated.obj"
	-@erase "$(INTDIR)\JDFCreated.sbr"
	-@erase "$(INTDIR)\JDFCreditCard.obj"
	-@erase "$(INTDIR)\JDFCreditCard.sbr"
	-@erase "$(INTDIR)\JDFCustomerInfo.obj"
	-@erase "$(INTDIR)\JDFCustomerInfo.sbr"
	-@erase "$(INTDIR)\JDFCustomerMessage.obj"
	-@erase "$(INTDIR)\JDFCustomerMessage.sbr"
	-@erase "$(INTDIR)\JDFCut.obj"
	-@erase "$(INTDIR)\JDFCut.sbr"
	-@erase "$(INTDIR)\JDFCutBlock.obj"
	-@erase "$(INTDIR)\JDFCutBlock.sbr"
	-@erase "$(INTDIR)\JDFCutMark.obj"
	-@erase "$(INTDIR)\JDFCutMark.sbr"
	-@erase "$(INTDIR)\JDFCuttingParams.obj"
	-@erase "$(INTDIR)\JDFCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFDateTimeEvaluation.obj"
	-@erase "$(INTDIR)\JDFDateTimeEvaluation.sbr"
	-@erase "$(INTDIR)\JDFDateTimeRange.obj"
	-@erase "$(INTDIR)\JDFDateTimeRange.sbr"
	-@erase "$(INTDIR)\JDFDateTimeRangeList.obj"
	-@erase "$(INTDIR)\JDFDateTimeRangeList.sbr"
	-@erase "$(INTDIR)\JDFDateTimeState.obj"
	-@erase "$(INTDIR)\JDFDateTimeState.sbr"
	-@erase "$(INTDIR)\JDFDBMergeParams.obj"
	-@erase "$(INTDIR)\JDFDBMergeParams.sbr"
	-@erase "$(INTDIR)\JDFDBRules.obj"
	-@erase "$(INTDIR)\JDFDBRules.sbr"
	-@erase "$(INTDIR)\JDFDBSchema.obj"
	-@erase "$(INTDIR)\JDFDBSchema.sbr"
	-@erase "$(INTDIR)\JDFDBSelection.obj"
	-@erase "$(INTDIR)\JDFDBSelection.sbr"
	-@erase "$(INTDIR)\JDFDCTParams.obj"
	-@erase "$(INTDIR)\JDFDCTParams.sbr"
	-@erase "$(INTDIR)\JDFDeleted.obj"
	-@erase "$(INTDIR)\JDFDeleted.sbr"
	-@erase "$(INTDIR)\JDFDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFDensityMeasuringField.obj"
	-@erase "$(INTDIR)\JDFDensityMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFDependencies.obj"
	-@erase "$(INTDIR)\JDFDependencies.sbr"
	-@erase "$(INTDIR)\JDFDevCap.obj"
	-@erase "$(INTDIR)\JDFDevCap.sbr"
	-@erase "$(INTDIR)\JDFDevCaps.obj"
	-@erase "$(INTDIR)\JDFDevCaps.sbr"
	-@erase "$(INTDIR)\JDFDevelopingParams.obj"
	-@erase "$(INTDIR)\JDFDevelopingParams.sbr"
	-@erase "$(INTDIR)\JDFDevice.obj"
	-@erase "$(INTDIR)\JDFDevice.sbr"
	-@erase "$(INTDIR)\JDFDeviceCap.obj"
	-@erase "$(INTDIR)\JDFDeviceCap.sbr"
	-@erase "$(INTDIR)\JDFDeviceFilter.obj"
	-@erase "$(INTDIR)\JDFDeviceFilter.sbr"
	-@erase "$(INTDIR)\JDFDeviceInfo.obj"
	-@erase "$(INTDIR)\JDFDeviceInfo.sbr"
	-@erase "$(INTDIR)\JDFDeviceList.obj"
	-@erase "$(INTDIR)\JDFDeviceList.sbr"
	-@erase "$(INTDIR)\JDFDeviceMark.obj"
	-@erase "$(INTDIR)\JDFDeviceMark.sbr"
	-@erase "$(INTDIR)\JDFDeviceNColor.obj"
	-@erase "$(INTDIR)\JDFDeviceNColor.sbr"
	-@erase "$(INTDIR)\JDFDeviceNSpace.obj"
	-@erase "$(INTDIR)\JDFDeviceNSpace.sbr"
	-@erase "$(INTDIR)\JDFDigitalDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFDigitalDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFDigitalMedia.obj"
	-@erase "$(INTDIR)\JDFDigitalMedia.sbr"
	-@erase "$(INTDIR)\JDFDigitalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFDigitalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFDisjointing.obj"
	-@erase "$(INTDIR)\JDFDisjointing.sbr"
	-@erase "$(INTDIR)\JDFDisplayGroup.obj"
	-@erase "$(INTDIR)\JDFDisplayGroup.sbr"
	-@erase "$(INTDIR)\JDFDisplayGroupPool.obj"
	-@erase "$(INTDIR)\JDFDisplayGroupPool.sbr"
	-@erase "$(INTDIR)\JDFDisposition.obj"
	-@erase "$(INTDIR)\JDFDisposition.sbr"
	-@erase "$(INTDIR)\JDFDividingParams.obj"
	-@erase "$(INTDIR)\JDFDividingParams.sbr"
	-@erase "$(INTDIR)\JDFDoc.obj"
	-@erase "$(INTDIR)\JDFDoc.sbr"
	-@erase "$(INTDIR)\JDFDrop.obj"
	-@erase "$(INTDIR)\JDFDrop.sbr"
	-@erase "$(INTDIR)\JDFDropIntent.obj"
	-@erase "$(INTDIR)\JDFDropIntent.sbr"
	-@erase "$(INTDIR)\JDFDropItem.obj"
	-@erase "$(INTDIR)\JDFDropItem.sbr"
	-@erase "$(INTDIR)\JDFDropItemIntent.obj"
	-@erase "$(INTDIR)\JDFDropItemIntent.sbr"
	-@erase "$(INTDIR)\JDFDurationEvaluation.obj"
	-@erase "$(INTDIR)\JDFDurationEvaluation.sbr"
	-@erase "$(INTDIR)\JDFDurationRange.obj"
	-@erase "$(INTDIR)\JDFDurationRange.sbr"
	-@erase "$(INTDIR)\JDFDurationRangeList.obj"
	-@erase "$(INTDIR)\JDFDurationRangeList.sbr"
	-@erase "$(INTDIR)\JDFDurationState.obj"
	-@erase "$(INTDIR)\JDFDurationState.sbr"
	-@erase "$(INTDIR)\JDFDynamicField.obj"
	-@erase "$(INTDIR)\JDFDynamicField.sbr"
	-@erase "$(INTDIR)\JDFDynamicInput.obj"
	-@erase "$(INTDIR)\JDFDynamicInput.sbr"
	-@erase "$(INTDIR)\JDFEdgeGluing.obj"
	-@erase "$(INTDIR)\JDFEdgeGluing.sbr"
	-@erase "$(INTDIR)\JDFElement.obj"
	-@erase "$(INTDIR)\JDFElement.sbr"
	-@erase "$(INTDIR)\JDFElementColorParams.obj"
	-@erase "$(INTDIR)\JDFElementColorParams.sbr"
	-@erase "$(INTDIR)\JDFEmboss.obj"
	-@erase "$(INTDIR)\JDFEmboss.sbr"
	-@erase "$(INTDIR)\JDFEmbossingIntent.obj"
	-@erase "$(INTDIR)\JDFEmbossingIntent.sbr"
	-@erase "$(INTDIR)\JDFEmbossingItem.obj"
	-@erase "$(INTDIR)\JDFEmbossingItem.sbr"
	-@erase "$(INTDIR)\JDFEmbossingParams.obj"
	-@erase "$(INTDIR)\JDFEmbossingParams.sbr"
	-@erase "$(INTDIR)\JDFEmployee.obj"
	-@erase "$(INTDIR)\JDFEmployee.sbr"
	-@erase "$(INTDIR)\JDFEmployeeDef.obj"
	-@erase "$(INTDIR)\JDFEmployeeDef.sbr"
	-@erase "$(INTDIR)\JDFEndSheet.obj"
	-@erase "$(INTDIR)\JDFEndSheet.sbr"
	-@erase "$(INTDIR)\JDFEndSheetGluingParams.obj"
	-@erase "$(INTDIR)\JDFEndSheetGluingParams.sbr"
	-@erase "$(INTDIR)\JDFEnumerationEvaluation.obj"
	-@erase "$(INTDIR)\JDFEnumerationEvaluation.sbr"
	-@erase "$(INTDIR)\JDFEnumerationState.obj"
	-@erase "$(INTDIR)\JDFEnumerationState.sbr"
	-@erase "$(INTDIR)\JDFError.obj"
	-@erase "$(INTDIR)\JDFError.sbr"
	-@erase "$(INTDIR)\JDFEvaluation.obj"
	-@erase "$(INTDIR)\JDFEvaluation.sbr"
	-@erase "$(INTDIR)\JDFEvent.obj"
	-@erase "$(INTDIR)\JDFEvent.sbr"
	-@erase "$(INTDIR)\JDFExposedMedia.obj"
	-@erase "$(INTDIR)\JDFExposedMedia.sbr"
	-@erase "$(INTDIR)\JDFFactory.obj"
	-@erase "$(INTDIR)\JDFFactory.sbr"
	-@erase "$(INTDIR)\JDFFCNKey.obj"
	-@erase "$(INTDIR)\JDFFCNKey.sbr"
	-@erase "$(INTDIR)\JDFFeatureAttribute.obj"
	-@erase "$(INTDIR)\JDFFeatureAttribute.sbr"
	-@erase "$(INTDIR)\JDFFeaturePool.obj"
	-@erase "$(INTDIR)\JDFFeaturePool.sbr"
	-@erase "$(INTDIR)\JDFFeeder.obj"
	-@erase "$(INTDIR)\JDFFeeder.sbr"
	-@erase "$(INTDIR)\JDFFeederQualityParams.obj"
	-@erase "$(INTDIR)\JDFFeederQualityParams.sbr"
	-@erase "$(INTDIR)\JDFFeedingParams.obj"
	-@erase "$(INTDIR)\JDFFeedingParams.sbr"
	-@erase "$(INTDIR)\JDFFileAlias.obj"
	-@erase "$(INTDIR)\JDFFileAlias.sbr"
	-@erase "$(INTDIR)\JDFFileSpec.obj"
	-@erase "$(INTDIR)\JDFFileSpec.sbr"
	-@erase "$(INTDIR)\JDFFitPolicy.obj"
	-@erase "$(INTDIR)\JDFFitPolicy.sbr"
	-@erase "$(INTDIR)\JDFFlateParams.obj"
	-@erase "$(INTDIR)\JDFFlateParams.sbr"
	-@erase "$(INTDIR)\JDFFlushedResources.obj"
	-@erase "$(INTDIR)\JDFFlushedResources.sbr"
	-@erase "$(INTDIR)\JDFFlushQueueParams.obj"
	-@erase "$(INTDIR)\JDFFlushQueueParams.sbr"
	-@erase "$(INTDIR)\JDFFlushResourceParams.obj"
	-@erase "$(INTDIR)\JDFFlushResourceParams.sbr"
	-@erase "$(INTDIR)\JDFFold.obj"
	-@erase "$(INTDIR)\JDFFold.sbr"
	-@erase "$(INTDIR)\JDFFoldingIntent.obj"
	-@erase "$(INTDIR)\JDFFoldingIntent.sbr"
	-@erase "$(INTDIR)\JDFFoldingParams.obj"
	-@erase "$(INTDIR)\JDFFoldingParams.sbr"
	-@erase "$(INTDIR)\JDFFontParams.obj"
	-@erase "$(INTDIR)\JDFFontParams.sbr"
	-@erase "$(INTDIR)\JDFFontPolicy.obj"
	-@erase "$(INTDIR)\JDFFontPolicy.sbr"
	-@erase "$(INTDIR)\JDFFormatConversionParams.obj"
	-@erase "$(INTDIR)\JDFFormatConversionParams.sbr"
	-@erase "$(INTDIR)\JDFGatheringParams.obj"
	-@erase "$(INTDIR)\JDFGatheringParams.sbr"
	-@erase "$(INTDIR)\JDFGlue.obj"
	-@erase "$(INTDIR)\JDFGlue.sbr"
	-@erase "$(INTDIR)\JDFGlueApplication.obj"
	-@erase "$(INTDIR)\JDFGlueApplication.sbr"
	-@erase "$(INTDIR)\JDFGlueLine.obj"
	-@erase "$(INTDIR)\JDFGlueLine.sbr"
	-@erase "$(INTDIR)\JDFGluingParams.obj"
	-@erase "$(INTDIR)\JDFGluingParams.sbr"
	-@erase "$(INTDIR)\JDFHardCoverBinding.obj"
	-@erase "$(INTDIR)\JDFHardCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFHeadBandApplicationParams.obj"
	-@erase "$(INTDIR)\JDFHeadBandApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFHole.obj"
	-@erase "$(INTDIR)\JDFHole.sbr"
	-@erase "$(INTDIR)\JDFHoleLine.obj"
	-@erase "$(INTDIR)\JDFHoleLine.sbr"
	-@erase "$(INTDIR)\JDFHoleList.obj"
	-@erase "$(INTDIR)\JDFHoleList.sbr"
	-@erase "$(INTDIR)\JDFHoleMakingIntent.obj"
	-@erase "$(INTDIR)\JDFHoleMakingIntent.sbr"
	-@erase "$(INTDIR)\JDFHoleMakingParams.obj"
	-@erase "$(INTDIR)\JDFHoleMakingParams.sbr"
	-@erase "$(INTDIR)\JDFIcon.obj"
	-@erase "$(INTDIR)\JDFIcon.sbr"
	-@erase "$(INTDIR)\JDFIconList.obj"
	-@erase "$(INTDIR)\JDFIconList.sbr"
	-@erase "$(INTDIR)\JDFIdentificationField.obj"
	-@erase "$(INTDIR)\JDFIdentificationField.sbr"
	-@erase "$(INTDIR)\JDFIDInfo.obj"
	-@erase "$(INTDIR)\JDFIDInfo.sbr"
	-@erase "$(INTDIR)\JDFIDPCover.obj"
	-@erase "$(INTDIR)\JDFIDPCover.sbr"
	-@erase "$(INTDIR)\JDFIDPFinishing.obj"
	-@erase "$(INTDIR)\JDFIDPFinishing.sbr"
	-@erase "$(INTDIR)\JDFIDPFolding.obj"
	-@erase "$(INTDIR)\JDFIDPFolding.sbr"
	-@erase "$(INTDIR)\JDFIDPHoleMaking.obj"
	-@erase "$(INTDIR)\JDFIDPHoleMaking.sbr"
	-@erase "$(INTDIR)\JDFIDPImageShift.obj"
	-@erase "$(INTDIR)\JDFIDPImageShift.sbr"
	-@erase "$(INTDIR)\JDFIDPJobSheet.obj"
	-@erase "$(INTDIR)\JDFIDPJobSheet.sbr"
	-@erase "$(INTDIR)\JDFIDPLayout.obj"
	-@erase "$(INTDIR)\JDFIDPLayout.sbr"
	-@erase "$(INTDIR)\JDFIDPrintingParams.obj"
	-@erase "$(INTDIR)\JDFIDPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFIDPStitching.obj"
	-@erase "$(INTDIR)\JDFIDPStitching.sbr"
	-@erase "$(INTDIR)\JDFIDPTrimming.obj"
	-@erase "$(INTDIR)\JDFIDPTrimming.sbr"
	-@erase "$(INTDIR)\JDFImageCompression.obj"
	-@erase "$(INTDIR)\JDFImageCompression.sbr"
	-@erase "$(INTDIR)\JDFImageCompressionParams.obj"
	-@erase "$(INTDIR)\JDFImageCompressionParams.sbr"
	-@erase "$(INTDIR)\JDFImageReplacementParams.obj"
	-@erase "$(INTDIR)\JDFImageReplacementParams.sbr"
	-@erase "$(INTDIR)\JDFImageSetterParams.obj"
	-@erase "$(INTDIR)\JDFImageSetterParams.sbr"
	-@erase "$(INTDIR)\JDFImageShift.obj"
	-@erase "$(INTDIR)\JDFImageShift.sbr"
	-@erase "$(INTDIR)\JDFInk.obj"
	-@erase "$(INTDIR)\JDFInk.sbr"
	-@erase "$(INTDIR)\JDFInkZoneCalculationParams.obj"
	-@erase "$(INTDIR)\JDFInkZoneCalculationParams.sbr"
	-@erase "$(INTDIR)\JDFInkZoneProfile.obj"
	-@erase "$(INTDIR)\JDFInkZoneProfile.sbr"
	-@erase "$(INTDIR)\JDFInsert.obj"
	-@erase "$(INTDIR)\JDFInsert.sbr"
	-@erase "$(INTDIR)\JDFInsertingIntent.obj"
	-@erase "$(INTDIR)\JDFInsertingIntent.sbr"
	-@erase "$(INTDIR)\JDFInsertingParams.obj"
	-@erase "$(INTDIR)\JDFInsertingParams.sbr"
	-@erase "$(INTDIR)\JDFInsertList.obj"
	-@erase "$(INTDIR)\JDFInsertList.sbr"
	-@erase "$(INTDIR)\JDFInsertSheet.obj"
	-@erase "$(INTDIR)\JDFInsertSheet.sbr"
	-@erase "$(INTDIR)\JDFIntegerEvaluation.obj"
	-@erase "$(INTDIR)\JDFIntegerEvaluation.sbr"
	-@erase "$(INTDIR)\JDFIntegerRange.obj"
	-@erase "$(INTDIR)\JDFIntegerRange.sbr"
	-@erase "$(INTDIR)\JDFIntegerRangeList.obj"
	-@erase "$(INTDIR)\JDFIntegerRangeList.sbr"
	-@erase "$(INTDIR)\JDFIntegerState.obj"
	-@erase "$(INTDIR)\JDFIntegerState.sbr"
	-@erase "$(INTDIR)\JDFIntentResource.obj"
	-@erase "$(INTDIR)\JDFIntentResource.sbr"
	-@erase "$(INTDIR)\JDFInterpretedPDLData.obj"
	-@erase "$(INTDIR)\JDFInterpretedPDLData.sbr"
	-@erase "$(INTDIR)\JDFInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFIsPresentEvaluation.obj"
	-@erase "$(INTDIR)\JDFIsPresentEvaluation.sbr"
	-@erase "$(INTDIR)\JDFJacketingParams.obj"
	-@erase "$(INTDIR)\JDFJacketingParams.sbr"
	-@erase "$(INTDIR)\JDFJDFController.obj"
	-@erase "$(INTDIR)\JDFJDFController.sbr"
	-@erase "$(INTDIR)\JDFJDFService.obj"
	-@erase "$(INTDIR)\JDFJDFService.sbr"
	-@erase "$(INTDIR)\JDFJMF.obj"
	-@erase "$(INTDIR)\JDFJMF.sbr"
	-@erase "$(INTDIR)\JDFJobField.obj"
	-@erase "$(INTDIR)\JDFJobField.sbr"
	-@erase "$(INTDIR)\JDFJobPhase.obj"
	-@erase "$(INTDIR)\JDFJobPhase.sbr"
	-@erase "$(INTDIR)\JDFKnownMsgQuParams.obj"
	-@erase "$(INTDIR)\JDFKnownMsgQuParams.sbr"
	-@erase "$(INTDIR)\JDFLabelingParams.obj"
	-@erase "$(INTDIR)\JDFLabelingParams.sbr"
	-@erase "$(INTDIR)\JDFLaminatingIntent.obj"
	-@erase "$(INTDIR)\JDFLaminatingIntent.sbr"
	-@erase "$(INTDIR)\JDFLaminatingParams.obj"
	-@erase "$(INTDIR)\JDFLaminatingParams.sbr"
	-@erase "$(INTDIR)\JDFLayerDetails.obj"
	-@erase "$(INTDIR)\JDFLayerDetails.sbr"
	-@erase "$(INTDIR)\JDFLayerList.obj"
	-@erase "$(INTDIR)\JDFLayerList.sbr"
	-@erase "$(INTDIR)\JDFLayout.obj"
	-@erase "$(INTDIR)\JDFLayout.sbr"
	-@erase "$(INTDIR)\JDFLayoutElement.obj"
	-@erase "$(INTDIR)\JDFLayoutElement.sbr"
	-@erase "$(INTDIR)\JDFLayoutIntent.obj"
	-@erase "$(INTDIR)\JDFLayoutIntent.sbr"
	-@erase "$(INTDIR)\JDFLayoutPreparationParams.obj"
	-@erase "$(INTDIR)\JDFLayoutPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFLoc.obj"
	-@erase "$(INTDIR)\JDFLoc.sbr"
	-@erase "$(INTDIR)\JDFLocation.obj"
	-@erase "$(INTDIR)\JDFLocation.sbr"
	-@erase "$(INTDIR)\JDFLongFold.obj"
	-@erase "$(INTDIR)\JDFLongFold.sbr"
	-@erase "$(INTDIR)\JDFLongGlue.obj"
	-@erase "$(INTDIR)\JDFLongGlue.sbr"
	-@erase "$(INTDIR)\JDFLongitudinalRibbonOperationParams.obj"
	-@erase "$(INTDIR)\JDFLongitudinalRibbonOperationParams.sbr"
	-@erase "$(INTDIR)\JDFLongPerforate.obj"
	-@erase "$(INTDIR)\JDFLongPerforate.sbr"
	-@erase "$(INTDIR)\JDFLongSlit.obj"
	-@erase "$(INTDIR)\JDFLongSlit.sbr"
	-@erase "$(INTDIR)\JDFLZWParams.obj"
	-@erase "$(INTDIR)\JDFLZWParams.sbr"
	-@erase "$(INTDIR)\JDFmacro.obj"
	-@erase "$(INTDIR)\JDFmacro.sbr"
	-@erase "$(INTDIR)\JDFMacroPool.obj"
	-@erase "$(INTDIR)\JDFMacroPool.sbr"
	-@erase "$(INTDIR)\JDFManualLaborParams.obj"
	-@erase "$(INTDIR)\JDFManualLaborParams.sbr"
	-@erase "$(INTDIR)\JDFMarkObject.obj"
	-@erase "$(INTDIR)\JDFMarkObject.sbr"
	-@erase "$(INTDIR)\JDFMatrixEvaluation.obj"
	-@erase "$(INTDIR)\JDFMatrixEvaluation.sbr"
	-@erase "$(INTDIR)\JDFMatrixState.obj"
	-@erase "$(INTDIR)\JDFMatrixState.sbr"
	-@erase "$(INTDIR)\JDFMedia.obj"
	-@erase "$(INTDIR)\JDFMedia.sbr"
	-@erase "$(INTDIR)\JDFMediaIntent.obj"
	-@erase "$(INTDIR)\JDFMediaIntent.sbr"
	-@erase "$(INTDIR)\JDFMediaSource.obj"
	-@erase "$(INTDIR)\JDFMediaSource.sbr"
	-@erase "$(INTDIR)\JDFMerged.obj"
	-@erase "$(INTDIR)\JDFMerged.sbr"
	-@erase "$(INTDIR)\JDFMessage.obj"
	-@erase "$(INTDIR)\JDFMessage.sbr"
	-@erase "$(INTDIR)\JDFMessageElement.obj"
	-@erase "$(INTDIR)\JDFMessageElement.sbr"
	-@erase "$(INTDIR)\JDFMessageService.obj"
	-@erase "$(INTDIR)\JDFMessageService.sbr"
	-@erase "$(INTDIR)\JDFMISDetails.obj"
	-@erase "$(INTDIR)\JDFMISDetails.sbr"
	-@erase "$(INTDIR)\JDFModified.obj"
	-@erase "$(INTDIR)\JDFModified.sbr"
	-@erase "$(INTDIR)\JDFModulePhase.obj"
	-@erase "$(INTDIR)\JDFModulePhase.sbr"
	-@erase "$(INTDIR)\JDFModuleStatus.obj"
	-@erase "$(INTDIR)\JDFModuleStatus.sbr"
	-@erase "$(INTDIR)\JDFMsgFilter.obj"
	-@erase "$(INTDIR)\JDFMsgFilter.sbr"
	-@erase "$(INTDIR)\JDFNameEvaluation.obj"
	-@erase "$(INTDIR)\JDFNameEvaluation.sbr"
	-@erase "$(INTDIR)\JDFNameRangeList.obj"
	-@erase "$(INTDIR)\JDFNameRangeList.sbr"
	-@erase "$(INTDIR)\JDFNameState.obj"
	-@erase "$(INTDIR)\JDFNameState.sbr"
	-@erase "$(INTDIR)\JDFNewJDFCmdParams.obj"
	-@erase "$(INTDIR)\JDFNewJDFCmdParams.sbr"
	-@erase "$(INTDIR)\JDFNewJDFQuParams.obj"
	-@erase "$(INTDIR)\JDFNewJDFQuParams.sbr"
	-@erase "$(INTDIR)\JDFNode.obj"
	-@erase "$(INTDIR)\JDFNode.sbr"
	-@erase "$(INTDIR)\JDFNodeFactory.obj"
	-@erase "$(INTDIR)\JDFNodeFactory.sbr"
	-@erase "$(INTDIR)\JDFNodeInfo.obj"
	-@erase "$(INTDIR)\JDFNodeInfo.sbr"
	-@erase "$(INTDIR)\JDFNodeInfoCmdParams.obj"
	-@erase "$(INTDIR)\JDFNodeInfoCmdParams.sbr"
	-@erase "$(INTDIR)\JDFNodeInfoQuParams.obj"
	-@erase "$(INTDIR)\JDFNodeInfoQuParams.sbr"
	-@erase "$(INTDIR)\JDFNodeInfoResp.obj"
	-@erase "$(INTDIR)\JDFNodeInfoResp.sbr"
	-@erase "$(INTDIR)\JDFnot.obj"
	-@erase "$(INTDIR)\JDFnot.sbr"
	-@erase "$(INTDIR)\JDFNotification.obj"
	-@erase "$(INTDIR)\JDFNotification.sbr"
	-@erase "$(INTDIR)\JDFNotificationDef.obj"
	-@erase "$(INTDIR)\JDFNotificationDef.sbr"
	-@erase "$(INTDIR)\JDFNotificationFilter.obj"
	-@erase "$(INTDIR)\JDFNotificationFilter.sbr"
	-@erase "$(INTDIR)\JDFNumberEvaluation.obj"
	-@erase "$(INTDIR)\JDFNumberEvaluation.sbr"
	-@erase "$(INTDIR)\JDFNumberingIntent.obj"
	-@erase "$(INTDIR)\JDFNumberingIntent.sbr"
	-@erase "$(INTDIR)\JDFNumberingParam.obj"
	-@erase "$(INTDIR)\JDFNumberingParam.sbr"
	-@erase "$(INTDIR)\JDFNumberingParams.obj"
	-@erase "$(INTDIR)\JDFNumberingParams.sbr"
	-@erase "$(INTDIR)\JDFNumberItem.obj"
	-@erase "$(INTDIR)\JDFNumberItem.sbr"
	-@erase "$(INTDIR)\JDFNumberRangeList.obj"
	-@erase "$(INTDIR)\JDFNumberRangeList.sbr"
	-@erase "$(INTDIR)\JDFNumberState.obj"
	-@erase "$(INTDIR)\JDFNumberState.sbr"
	-@erase "$(INTDIR)\JDFNumTypeList.obj"
	-@erase "$(INTDIR)\JDFNumTypeList.sbr"
	-@erase "$(INTDIR)\JDFObjectResolution.obj"
	-@erase "$(INTDIR)\JDFObjectResolution.sbr"
	-@erase "$(INTDIR)\JDFObservationTarget.obj"
	-@erase "$(INTDIR)\JDFObservationTarget.sbr"
	-@erase "$(INTDIR)\JDFOccupation.obj"
	-@erase "$(INTDIR)\JDFOccupation.sbr"
	-@erase "$(INTDIR)\JDFor.obj"
	-@erase "$(INTDIR)\JDFor.sbr"
	-@erase "$(INTDIR)\JDFOrderingParams.obj"
	-@erase "$(INTDIR)\JDFOrderingParams.sbr"
	-@erase "$(INTDIR)\JDFotherwise.obj"
	-@erase "$(INTDIR)\JDFotherwise.sbr"
	-@erase "$(INTDIR)\JDFPackingIntent.obj"
	-@erase "$(INTDIR)\JDFPackingIntent.sbr"
	-@erase "$(INTDIR)\JDFPackingParams.obj"
	-@erase "$(INTDIR)\JDFPackingParams.sbr"
	-@erase "$(INTDIR)\JDFPageCell.obj"
	-@erase "$(INTDIR)\JDFPageCell.sbr"
	-@erase "$(INTDIR)\JDFPageData.obj"
	-@erase "$(INTDIR)\JDFPageData.sbr"
	-@erase "$(INTDIR)\JDFPageList.obj"
	-@erase "$(INTDIR)\JDFPageList.sbr"
	-@erase "$(INTDIR)\JDFPallet.obj"
	-@erase "$(INTDIR)\JDFPallet.sbr"
	-@erase "$(INTDIR)\JDFPalletizingParams.obj"
	-@erase "$(INTDIR)\JDFPalletizingParams.sbr"
	-@erase "$(INTDIR)\JDFParamsFactory.obj"
	-@erase "$(INTDIR)\JDFParamsFactory.sbr"
	-@erase "$(INTDIR)\JDFParser.obj"
	-@erase "$(INTDIR)\JDFParser.sbr"
	-@erase "$(INTDIR)\JDFPart.obj"
	-@erase "$(INTDIR)\JDFPart.sbr"
	-@erase "$(INTDIR)\JDFPartAmount.obj"
	-@erase "$(INTDIR)\JDFPartAmount.sbr"
	-@erase "$(INTDIR)\JDFPartStatus.obj"
	-@erase "$(INTDIR)\JDFPartStatus.sbr"
	-@erase "$(INTDIR)\JDFPayment.obj"
	-@erase "$(INTDIR)\JDFPayment.sbr"
	-@erase "$(INTDIR)\JDFPDFInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFPDFInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFPDFPathEvaluation.obj"
	-@erase "$(INTDIR)\JDFPDFPathEvaluation.sbr"
	-@erase "$(INTDIR)\JDFPDFPathState.obj"
	-@erase "$(INTDIR)\JDFPDFPathState.sbr"
	-@erase "$(INTDIR)\JDFPDFToPSConversionParams.obj"
	-@erase "$(INTDIR)\JDFPDFToPSConversionParams.sbr"
	-@erase "$(INTDIR)\JDFPDFXParams.obj"
	-@erase "$(INTDIR)\JDFPDFXParams.sbr"
	-@erase "$(INTDIR)\JDFPDLResourceAlias.obj"
	-@erase "$(INTDIR)\JDFPDLResourceAlias.sbr"
	-@erase "$(INTDIR)\JDFPerforate.obj"
	-@erase "$(INTDIR)\JDFPerforate.sbr"
	-@erase "$(INTDIR)\JDFPerforatingParams.obj"
	-@erase "$(INTDIR)\JDFPerforatingParams.sbr"
	-@erase "$(INTDIR)\JDFPerformance.obj"
	-@erase "$(INTDIR)\JDFPerformance.sbr"
	-@erase "$(INTDIR)\JDFPerson.obj"
	-@erase "$(INTDIR)\JDFPerson.sbr"
	-@erase "$(INTDIR)\JDFPhaseTime.obj"
	-@erase "$(INTDIR)\JDFPhaseTime.sbr"
	-@erase "$(INTDIR)\JDFPipeParams.obj"
	-@erase "$(INTDIR)\JDFPipeParams.sbr"
	-@erase "$(INTDIR)\JDFPixelColorant.obj"
	-@erase "$(INTDIR)\JDFPixelColorant.sbr"
	-@erase "$(INTDIR)\JDFPlaceHolderResource.obj"
	-@erase "$(INTDIR)\JDFPlaceHolderResource.sbr"
	-@erase "$(INTDIR)\JDFPlasticCombBinding.obj"
	-@erase "$(INTDIR)\JDFPlasticCombBinding.sbr"
	-@erase "$(INTDIR)\JDFPlasticCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFPlasticCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFPlateCopyParams.obj"
	-@erase "$(INTDIR)\JDFPlateCopyParams.sbr"
	-@erase "$(INTDIR)\JDFPool.obj"
	-@erase "$(INTDIR)\JDFPool.sbr"
	-@erase "$(INTDIR)\JDFPosition.obj"
	-@erase "$(INTDIR)\JDFPosition.sbr"
	-@erase "$(INTDIR)\JDFPreflightAction.obj"
	-@erase "$(INTDIR)\JDFPreflightAction.sbr"
	-@erase "$(INTDIR)\JDFPreflightAnalysis.obj"
	-@erase "$(INTDIR)\JDFPreflightAnalysis.sbr"
	-@erase "$(INTDIR)\JDFPreflightArgument.obj"
	-@erase "$(INTDIR)\JDFPreflightArgument.sbr"
	-@erase "$(INTDIR)\JDFPreflightConstraint.obj"
	-@erase "$(INTDIR)\JDFPreflightConstraint.sbr"
	-@erase "$(INTDIR)\JDFPreflightConstraintsPool.obj"
	-@erase "$(INTDIR)\JDFPreflightConstraintsPool.sbr"
	-@erase "$(INTDIR)\JDFPreflightDetail.obj"
	-@erase "$(INTDIR)\JDFPreflightDetail.sbr"
	-@erase "$(INTDIR)\JDFPreflightInstance.obj"
	-@erase "$(INTDIR)\JDFPreflightInstance.sbr"
	-@erase "$(INTDIR)\JDFPreflightInstanceDetail.obj"
	-@erase "$(INTDIR)\JDFPreflightInstanceDetail.sbr"
	-@erase "$(INTDIR)\JDFPreflightInventory.obj"
	-@erase "$(INTDIR)\JDFPreflightInventory.sbr"
	-@erase "$(INTDIR)\JDFPreflightParams.obj"
	-@erase "$(INTDIR)\JDFPreflightParams.sbr"
	-@erase "$(INTDIR)\JDFPreflightProfile.obj"
	-@erase "$(INTDIR)\JDFPreflightProfile.sbr"
	-@erase "$(INTDIR)\JDFPreflightReport.obj"
	-@erase "$(INTDIR)\JDFPreflightReport.sbr"
	-@erase "$(INTDIR)\JDFPreflightReportRulePool.obj"
	-@erase "$(INTDIR)\JDFPreflightReportRulePool.sbr"
	-@erase "$(INTDIR)\JDFPreflightResultsPool.obj"
	-@erase "$(INTDIR)\JDFPreflightResultsPool.sbr"
	-@erase "$(INTDIR)\JDFPreflightValue.obj"
	-@erase "$(INTDIR)\JDFPreflightValue.sbr"
	-@erase "$(INTDIR)\JDFPRError.obj"
	-@erase "$(INTDIR)\JDFPRError.sbr"
	-@erase "$(INTDIR)\JDFPreview.obj"
	-@erase "$(INTDIR)\JDFPreview.sbr"
	-@erase "$(INTDIR)\JDFPreviewGenerationParams.obj"
	-@erase "$(INTDIR)\JDFPreviewGenerationParams.sbr"
	-@erase "$(INTDIR)\JDFPRGroup.obj"
	-@erase "$(INTDIR)\JDFPRGroup.sbr"
	-@erase "$(INTDIR)\JDFPRGroupOccurence.obj"
	-@erase "$(INTDIR)\JDFPRGroupOccurence.sbr"
	-@erase "$(INTDIR)\JDFPRGroupOccurenceBase.obj"
	-@erase "$(INTDIR)\JDFPRGroupOccurenceBase.sbr"
	-@erase "$(INTDIR)\JDFPricing.obj"
	-@erase "$(INTDIR)\JDFPricing.sbr"
	-@erase "$(INTDIR)\JDFPrintCondition.obj"
	-@erase "$(INTDIR)\JDFPrintCondition.sbr"
	-@erase "$(INTDIR)\JDFPrintConditionColor.obj"
	-@erase "$(INTDIR)\JDFPrintConditionColor.sbr"
	-@erase "$(INTDIR)\JDFPrintRollingParams.obj"
	-@erase "$(INTDIR)\JDFPrintRollingParams.sbr"
	-@erase "$(INTDIR)\JDFPRItem.obj"
	-@erase "$(INTDIR)\JDFPRItem.sbr"
	-@erase "$(INTDIR)\JDFPROccurence.obj"
	-@erase "$(INTDIR)\JDFPROccurence.sbr"
	-@erase "$(INTDIR)\JDFProcessRun.obj"
	-@erase "$(INTDIR)\JDFProcessRun.sbr"
	-@erase "$(INTDIR)\JDFProductionIntent.obj"
	-@erase "$(INTDIR)\JDFProductionIntent.sbr"
	-@erase "$(INTDIR)\JDFProofingIntent.obj"
	-@erase "$(INTDIR)\JDFProofingIntent.sbr"
	-@erase "$(INTDIR)\JDFProofingParams.obj"
	-@erase "$(INTDIR)\JDFProofingParams.sbr"
	-@erase "$(INTDIR)\JDFProofItem.obj"
	-@erase "$(INTDIR)\JDFProofItem.sbr"
	-@erase "$(INTDIR)\JDFProperties.obj"
	-@erase "$(INTDIR)\JDFProperties.sbr"
	-@erase "$(INTDIR)\JDFPRRule.obj"
	-@erase "$(INTDIR)\JDFPRRule.sbr"
	-@erase "$(INTDIR)\JDFPRRuleAttr.obj"
	-@erase "$(INTDIR)\JDFPRRuleAttr.sbr"
	-@erase "$(INTDIR)\JDFPSToPDFConversionParams.obj"
	-@erase "$(INTDIR)\JDFPSToPDFConversionParams.sbr"
	-@erase "$(INTDIR)\JDFQualityControlParams.obj"
	-@erase "$(INTDIR)\JDFQualityControlParams.sbr"
	-@erase "$(INTDIR)\JDFQualityControlResult.obj"
	-@erase "$(INTDIR)\JDFQualityControlResult.sbr"
	-@erase "$(INTDIR)\JDFQualityMeasurement.obj"
	-@erase "$(INTDIR)\JDFQualityMeasurement.sbr"
	-@erase "$(INTDIR)\JDFQuery.obj"
	-@erase "$(INTDIR)\JDFQuery.sbr"
	-@erase "$(INTDIR)\JDFQueue.obj"
	-@erase "$(INTDIR)\JDFQueue.sbr"
	-@erase "$(INTDIR)\JDFQueueEntry.obj"
	-@erase "$(INTDIR)\JDFQueueEntry.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryDef.obj"
	-@erase "$(INTDIR)\JDFQueueEntryDef.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryDefList.obj"
	-@erase "$(INTDIR)\JDFQueueEntryDefList.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryPosParams.obj"
	-@erase "$(INTDIR)\JDFQueueEntryPosParams.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryPriParams.obj"
	-@erase "$(INTDIR)\JDFQueueEntryPriParams.sbr"
	-@erase "$(INTDIR)\JDFQueueFilter.obj"
	-@erase "$(INTDIR)\JDFQueueFilter.sbr"
	-@erase "$(INTDIR)\JDFQueueSubmissionParams.obj"
	-@erase "$(INTDIR)\JDFQueueSubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFRange.obj"
	-@erase "$(INTDIR)\JDFRange.sbr"
	-@erase "$(INTDIR)\JDFRangeList.obj"
	-@erase "$(INTDIR)\JDFRangeList.sbr"
	-@erase "$(INTDIR)\JDFRectangleEvaluation.obj"
	-@erase "$(INTDIR)\JDFRectangleEvaluation.sbr"
	-@erase "$(INTDIR)\JDFRectangleState.obj"
	-@erase "$(INTDIR)\JDFRectangleState.sbr"
	-@erase "$(INTDIR)\JDFRefElement.obj"
	-@erase "$(INTDIR)\JDFRefElement.sbr"
	-@erase "$(INTDIR)\JDFRegisterMark.obj"
	-@erase "$(INTDIR)\JDFRegisterMark.sbr"
	-@erase "$(INTDIR)\JDFRegisterRibbon.obj"
	-@erase "$(INTDIR)\JDFRegisterRibbon.sbr"
	-@erase "$(INTDIR)\JDFRemoved.obj"
	-@erase "$(INTDIR)\JDFRemoved.sbr"
	-@erase "$(INTDIR)\JDFRenderingParams.obj"
	-@erase "$(INTDIR)\JDFRenderingParams.sbr"
	-@erase "$(INTDIR)\JDFRequestQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFRequestQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFResource.obj"
	-@erase "$(INTDIR)\JDFResource.sbr"
	-@erase "$(INTDIR)\JDFResourceAudit.obj"
	-@erase "$(INTDIR)\JDFResourceAudit.sbr"
	-@erase "$(INTDIR)\JDFResourceCmdParams.obj"
	-@erase "$(INTDIR)\JDFResourceCmdParams.sbr"
	-@erase "$(INTDIR)\JDFResourceDefinitionParams.obj"
	-@erase "$(INTDIR)\JDFResourceDefinitionParams.sbr"
	-@erase "$(INTDIR)\JDFResourceInfo.obj"
	-@erase "$(INTDIR)\JDFResourceInfo.sbr"
	-@erase "$(INTDIR)\JDFResourceLink.obj"
	-@erase "$(INTDIR)\JDFResourceLink.sbr"
	-@erase "$(INTDIR)\JDFResourceLinkPool.obj"
	-@erase "$(INTDIR)\JDFResourceLinkPool.sbr"
	-@erase "$(INTDIR)\JDFResourceParam.obj"
	-@erase "$(INTDIR)\JDFResourceParam.sbr"
	-@erase "$(INTDIR)\JDFResourcePool.obj"
	-@erase "$(INTDIR)\JDFResourcePool.sbr"
	-@erase "$(INTDIR)\JDFResourcePullParams.obj"
	-@erase "$(INTDIR)\JDFResourcePullParams.sbr"
	-@erase "$(INTDIR)\JDFResourceQuParams.obj"
	-@erase "$(INTDIR)\JDFResourceQuParams.sbr"
	-@erase "$(INTDIR)\JDFResponse.obj"
	-@erase "$(INTDIR)\JDFResponse.sbr"
	-@erase "$(INTDIR)\JDFResubmissionParams.obj"
	-@erase "$(INTDIR)\JDFResubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFReturnQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFReturnQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFRingBinding.obj"
	-@erase "$(INTDIR)\JDFRingBinding.sbr"
	-@erase "$(INTDIR)\JDFRingBindingParams.obj"
	-@erase "$(INTDIR)\JDFRingBindingParams.sbr"
	-@erase "$(INTDIR)\JDFRollStand.obj"
	-@erase "$(INTDIR)\JDFRollStand.sbr"
	-@erase "$(INTDIR)\JDFRunElement.obj"
	-@erase "$(INTDIR)\JDFRunElement.sbr"
	-@erase "$(INTDIR)\JDFRunList.obj"
	-@erase "$(INTDIR)\JDFRunList.sbr"
	-@erase "$(INTDIR)\JDFSaddleStitching.obj"
	-@erase "$(INTDIR)\JDFSaddleStitching.sbr"
	-@erase "$(INTDIR)\JDFSaddleStitchingParams.obj"
	-@erase "$(INTDIR)\JDFSaddleStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFScanParams.obj"
	-@erase "$(INTDIR)\JDFScanParams.sbr"
	-@erase "$(INTDIR)\JDFScavengerArea.obj"
	-@erase "$(INTDIR)\JDFScavengerArea.sbr"
	-@erase "$(INTDIR)\JDFScore.obj"
	-@erase "$(INTDIR)\JDFScore.sbr"
	-@erase "$(INTDIR)\JDFScreeningIntent.obj"
	-@erase "$(INTDIR)\JDFScreeningIntent.sbr"
	-@erase "$(INTDIR)\JDFScreeningParams.obj"
	-@erase "$(INTDIR)\JDFScreeningParams.sbr"
	-@erase "$(INTDIR)\JDFScreenSelector.obj"
	-@erase "$(INTDIR)\JDFScreenSelector.sbr"
	-@erase "$(INTDIR)\JDFSeparationControlParams.obj"
	-@erase "$(INTDIR)\JDFSeparationControlParams.sbr"
	-@erase "$(INTDIR)\JDFSeparationList.obj"
	-@erase "$(INTDIR)\JDFSeparationList.sbr"
	-@erase "$(INTDIR)\JDFSeparationSpec.obj"
	-@erase "$(INTDIR)\JDFSeparationSpec.sbr"
	-@erase "$(INTDIR)\JDFset.obj"
	-@erase "$(INTDIR)\JDFset.sbr"
	-@erase "$(INTDIR)\JDFShapeCut.obj"
	-@erase "$(INTDIR)\JDFShapeCut.sbr"
	-@erase "$(INTDIR)\JDFShapeCuttingIntent.obj"
	-@erase "$(INTDIR)\JDFShapeCuttingIntent.sbr"
	-@erase "$(INTDIR)\JDFShapeCuttingParams.obj"
	-@erase "$(INTDIR)\JDFShapeCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFShapeElement.obj"
	-@erase "$(INTDIR)\JDFShapeElement.sbr"
	-@erase "$(INTDIR)\JDFShapeEvaluation.obj"
	-@erase "$(INTDIR)\JDFShapeEvaluation.sbr"
	-@erase "$(INTDIR)\JDFShapeState.obj"
	-@erase "$(INTDIR)\JDFShapeState.sbr"
	-@erase "$(INTDIR)\JDFSheet.obj"
	-@erase "$(INTDIR)\JDFSheet.sbr"
	-@erase "$(INTDIR)\JDFShrinkingParams.obj"
	-@erase "$(INTDIR)\JDFShrinkingParams.sbr"
	-@erase "$(INTDIR)\JDFShutDownCmdParams.obj"
	-@erase "$(INTDIR)\JDFShutDownCmdParams.sbr"
	-@erase "$(INTDIR)\JDFSideSewing.obj"
	-@erase "$(INTDIR)\JDFSideSewing.sbr"
	-@erase "$(INTDIR)\JDFSideSewingParams.obj"
	-@erase "$(INTDIR)\JDFSideSewingParams.sbr"
	-@erase "$(INTDIR)\JDFSideStitching.obj"
	-@erase "$(INTDIR)\JDFSideStitching.sbr"
	-@erase "$(INTDIR)\JDFSignal.obj"
	-@erase "$(INTDIR)\JDFSignal.sbr"
	-@erase "$(INTDIR)\JDFSignature.obj"
	-@erase "$(INTDIR)\JDFSignature.sbr"
	-@erase "$(INTDIR)\JDFSignatureCell.obj"
	-@erase "$(INTDIR)\JDFSignatureCell.sbr"
	-@erase "$(INTDIR)\JDFSizeIntent.obj"
	-@erase "$(INTDIR)\JDFSizeIntent.sbr"
	-@erase "$(INTDIR)\JDFSoftCoverBinding.obj"
	-@erase "$(INTDIR)\JDFSoftCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFSpan.obj"
	-@erase "$(INTDIR)\JDFSpan.sbr"
	-@erase "$(INTDIR)\JDFSpawned.obj"
	-@erase "$(INTDIR)\JDFSpawned.sbr"
	-@erase "$(INTDIR)\JDFSpinePreparationParams.obj"
	-@erase "$(INTDIR)\JDFSpinePreparationParams.sbr"
	-@erase "$(INTDIR)\JDFSpineTapingParams.obj"
	-@erase "$(INTDIR)\JDFSpineTapingParams.sbr"
	-@erase "$(INTDIR)\JDFStackingParams.obj"
	-@erase "$(INTDIR)\JDFStackingParams.sbr"
	-@erase "$(INTDIR)\JDFState.obj"
	-@erase "$(INTDIR)\JDFState.sbr"
	-@erase "$(INTDIR)\JDFStatusPool.obj"
	-@erase "$(INTDIR)\JDFStatusPool.sbr"
	-@erase "$(INTDIR)\JDFStatusQuParams.obj"
	-@erase "$(INTDIR)\JDFStatusQuParams.sbr"
	-@erase "$(INTDIR)\JDFStitchingParams.obj"
	-@erase "$(INTDIR)\JDFStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFStopPersChParams.obj"
	-@erase "$(INTDIR)\JDFStopPersChParams.sbr"
	-@erase "$(INTDIR)\JDFStrap.obj"
	-@erase "$(INTDIR)\JDFStrap.sbr"
	-@erase "$(INTDIR)\JDFStrappingParams.obj"
	-@erase "$(INTDIR)\JDFStrappingParams.sbr"
	-@erase "$(INTDIR)\JDFStringEvaluation.obj"
	-@erase "$(INTDIR)\JDFStringEvaluation.sbr"
	-@erase "$(INTDIR)\JDFStringListValue.obj"
	-@erase "$(INTDIR)\JDFStringListValue.sbr"
	-@erase "$(INTDIR)\JDFStrings.obj"
	-@erase "$(INTDIR)\JDFStrings.sbr"
	-@erase "$(INTDIR)\JDFStringState.obj"
	-@erase "$(INTDIR)\JDFStringState.sbr"
	-@erase "$(INTDIR)\JDFStripBinding.obj"
	-@erase "$(INTDIR)\JDFStripBinding.sbr"
	-@erase "$(INTDIR)\JDFStripBindingParams.obj"
	-@erase "$(INTDIR)\JDFStripBindingParams.sbr"
	-@erase "$(INTDIR)\JDFStripCellParams.obj"
	-@erase "$(INTDIR)\JDFStripCellParams.sbr"
	-@erase "$(INTDIR)\JDFStrippingParams.obj"
	-@erase "$(INTDIR)\JDFStrippingParams.sbr"
	-@erase "$(INTDIR)\JDFSubmissionMethods.obj"
	-@erase "$(INTDIR)\JDFSubmissionMethods.sbr"
	-@erase "$(INTDIR)\JDFSubscription.obj"
	-@erase "$(INTDIR)\JDFSubscription.sbr"
	-@erase "$(INTDIR)\JDFSurface.obj"
	-@erase "$(INTDIR)\JDFSurface.sbr"
	-@erase "$(INTDIR)\JDFSystemTimeSet.obj"
	-@erase "$(INTDIR)\JDFSystemTimeSet.sbr"
	-@erase "$(INTDIR)\JDFTabs.obj"
	-@erase "$(INTDIR)\JDFTabs.sbr"
	-@erase "$(INTDIR)\JDFTape.obj"
	-@erase "$(INTDIR)\JDFTape.sbr"
	-@erase "$(INTDIR)\JDFTest.obj"
	-@erase "$(INTDIR)\JDFTest.sbr"
	-@erase "$(INTDIR)\JDFTestPool.obj"
	-@erase "$(INTDIR)\JDFTestPool.sbr"
	-@erase "$(INTDIR)\JDFTestRef.obj"
	-@erase "$(INTDIR)\JDFTestRef.sbr"
	-@erase "$(INTDIR)\JDFThinPDFParams.obj"
	-@erase "$(INTDIR)\JDFThinPDFParams.sbr"
	-@erase "$(INTDIR)\JDFThreadSealing.obj"
	-@erase "$(INTDIR)\JDFThreadSealing.sbr"
	-@erase "$(INTDIR)\JDFThreadSealingParams.obj"
	-@erase "$(INTDIR)\JDFThreadSealingParams.sbr"
	-@erase "$(INTDIR)\JDFThreadSewing.obj"
	-@erase "$(INTDIR)\JDFThreadSewing.sbr"
	-@erase "$(INTDIR)\JDFThreadSewingParams.obj"
	-@erase "$(INTDIR)\JDFThreadSewingParams.sbr"
	-@erase "$(INTDIR)\JDFTIFFEmbeddedFile.obj"
	-@erase "$(INTDIR)\JDFTIFFEmbeddedFile.sbr"
	-@erase "$(INTDIR)\JDFTIFFFormatParams.obj"
	-@erase "$(INTDIR)\JDFTIFFFormatParams.sbr"
	-@erase "$(INTDIR)\JDFTIFFtag.obj"
	-@erase "$(INTDIR)\JDFTIFFtag.sbr"
	-@erase "$(INTDIR)\JDFTile.obj"
	-@erase "$(INTDIR)\JDFTile.sbr"
	-@erase "$(INTDIR)\JDFTool.obj"
	-@erase "$(INTDIR)\JDFTool.sbr"
	-@erase "$(INTDIR)\JDFTrackFilter.obj"
	-@erase "$(INTDIR)\JDFTrackFilter.sbr"
	-@erase "$(INTDIR)\JDFTrackResult.obj"
	-@erase "$(INTDIR)\JDFTrackResult.sbr"
	-@erase "$(INTDIR)\JDFTransferCurve.obj"
	-@erase "$(INTDIR)\JDFTransferCurve.sbr"
	-@erase "$(INTDIR)\JDFTransferCurvePool.obj"
	-@erase "$(INTDIR)\JDFTransferCurvePool.sbr"
	-@erase "$(INTDIR)\JDFTransferCurveSet.obj"
	-@erase "$(INTDIR)\JDFTransferCurveSet.sbr"
	-@erase "$(INTDIR)\JDFTransferFunctionControl.obj"
	-@erase "$(INTDIR)\JDFTransferFunctionControl.sbr"
	-@erase "$(INTDIR)\JDFTrappingDetails.obj"
	-@erase "$(INTDIR)\JDFTrappingDetails.sbr"
	-@erase "$(INTDIR)\JDFTrappingOrder.obj"
	-@erase "$(INTDIR)\JDFTrappingOrder.sbr"
	-@erase "$(INTDIR)\JDFTrappingParams.obj"
	-@erase "$(INTDIR)\JDFTrappingParams.sbr"
	-@erase "$(INTDIR)\JDFTrapRegion.obj"
	-@erase "$(INTDIR)\JDFTrapRegion.sbr"
	-@erase "$(INTDIR)\JDFTrigger.obj"
	-@erase "$(INTDIR)\JDFTrigger.sbr"
	-@erase "$(INTDIR)\JDFTrimmingParams.obj"
	-@erase "$(INTDIR)\JDFTrimmingParams.sbr"
	-@erase "$(INTDIR)\JDFValue.obj"
	-@erase "$(INTDIR)\JDFValue.sbr"
	-@erase "$(INTDIR)\JDFValueLoc.obj"
	-@erase "$(INTDIR)\JDFValueLoc.sbr"
	-@erase "$(INTDIR)\JDFVerificationParams.obj"
	-@erase "$(INTDIR)\JDFVerificationParams.sbr"
	-@erase "$(INTDIR)\JDFWakeUpCmdParams.obj"
	-@erase "$(INTDIR)\JDFWakeUpCmdParams.sbr"
	-@erase "$(INTDIR)\JDFwhen.obj"
	-@erase "$(INTDIR)\JDFwhen.sbr"
	-@erase "$(INTDIR)\JDFWireCombBinding.obj"
	-@erase "$(INTDIR)\JDFWireCombBinding.sbr"
	-@erase "$(INTDIR)\JDFWireCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFWireCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFWrappingParams.obj"
	-@erase "$(INTDIR)\JDFWrappingParams.sbr"
	-@erase "$(INTDIR)\JDFxor.obj"
	-@erase "$(INTDIR)\JDFxor.sbr"
	-@erase "$(INTDIR)\JDFXYPairEvaluation.obj"
	-@erase "$(INTDIR)\JDFXYPairEvaluation.sbr"
	-@erase "$(INTDIR)\JDFXYPairRangeList.obj"
	-@erase "$(INTDIR)\JDFXYPairRangeList.sbr"
	-@erase "$(INTDIR)\JDFXYPairState.obj"
	-@erase "$(INTDIR)\JDFXYPairState.sbr"
	-@erase "$(INTDIR)\KElement.obj"
	-@erase "$(INTDIR)\KElement.sbr"
	-@erase "$(INTDIR)\KElementStrings.obj"
	-@erase "$(INTDIR)\KElementStrings.sbr"
	-@erase "$(INTDIR)\MyDate.obj"
	-@erase "$(INTDIR)\MyDate.sbr"
	-@erase "$(INTDIR)\vElement.obj"
	-@erase "$(INTDIR)\vElement.sbr"
	-@erase "$(INTDIR)\XMLDoc.obj"
	-@erase "$(INTDIR)\XMLDoc.sbr"
	-@erase "$(INTDIR)\XMLDocUserData.obj"
	-@erase "$(INTDIR)\XMLDocUserData.sbr"
	-@erase "$(OUTDIR)\JDFWrapperLib.bsc"
	-@erase "$(OUTDIR)\JDFWrapperLib_D.lib"
	-@erase "..\..\..\Build\Win32\VC6\Debug\JDFWrapperLib.idb"
	-@erase "..\..\..\Build\Win32\VC6\Debug\JDFWrapperLib.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

MTL=midl.exe
LINK32=link.exe
CPP=xicl6.exe
CPP_PROJ=/nologo /MDd /w /W0 /GX /Zi /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "_DEBUG" /D "_WINDOWS" /D "WIN32" /D "JDF_TOOLS_LIB" /D "JDF_WRAPPERCORE_LIB" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"..\..\..\Build\Win32\VC6\Debug\JDFWrapperLib" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\JDFWrapperLib.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\JDFAmountPool.sbr" \
	"$(INTDIR)\JDFAncestor.sbr" \
	"$(INTDIR)\JDFAncestorPool.sbr" \
	"$(INTDIR)\JDFAudit.sbr" \
	"$(INTDIR)\JDFAuditPool.sbr" \
	"$(INTDIR)\JDFBarcode.sbr" \
	"$(INTDIR)\JDFBusinessInfo.sbr" \
	"$(INTDIR)\JDFComment.sbr" \
	"$(INTDIR)\JDFCounterReset.sbr" \
	"$(INTDIR)\JDFCreated.sbr" \
	"$(INTDIR)\JDFCustomerInfo.sbr" \
	"$(INTDIR)\JDFCustomerMessage.sbr" \
	"$(INTDIR)\JDFDeleted.sbr" \
	"$(INTDIR)\JDFError.sbr" \
	"$(INTDIR)\JDFEvent.sbr" \
	"$(INTDIR)\JDFFCNKey.sbr" \
	"$(INTDIR)\JDFLocation.sbr" \
	"$(INTDIR)\JDFMerged.sbr" \
	"$(INTDIR)\JDFModified.sbr" \
	"$(INTDIR)\JDFModulePhase.sbr" \
	"$(INTDIR)\JDFNode.sbr" \
	"$(INTDIR)\JDFNodeInfo.sbr" \
	"$(INTDIR)\JDFNotification.sbr" \
	"$(INTDIR)\JDFPart.sbr" \
	"$(INTDIR)\JDFPartAmount.sbr" \
	"$(INTDIR)\JDFPartStatus.sbr" \
	"$(INTDIR)\JDFPhaseTime.sbr" \
	"$(INTDIR)\JDFProcessRun.sbr" \
	"$(INTDIR)\JDFResourceAudit.sbr" \
	"$(INTDIR)\JDFResourceLinkPool.sbr" \
	"$(INTDIR)\JDFResourcePool.sbr" \
	"$(INTDIR)\JDFSpawned.sbr" \
	"$(INTDIR)\JDFStatusPool.sbr" \
	"$(INTDIR)\JDFSystemTimeSet.sbr" \
	"$(INTDIR)\JDFAcknowledge.sbr" \
	"$(INTDIR)\JDFAdded.sbr" \
	"$(INTDIR)\JDFChangedAttribute.sbr" \
	"$(INTDIR)\JDFChangedPath.sbr" \
	"$(INTDIR)\JDFCommand.sbr" \
	"$(INTDIR)\JDFDeviceFilter.sbr" \
	"$(INTDIR)\JDFDeviceInfo.sbr" \
	"$(INTDIR)\JDFDeviceList.sbr" \
	"$(INTDIR)\JDFEmployeeDef.sbr" \
	"$(INTDIR)\JDFFlushedResources.sbr" \
	"$(INTDIR)\JDFFlushQueueParams.sbr" \
	"$(INTDIR)\JDFFlushResourceParams.sbr" \
	"$(INTDIR)\JDFIDInfo.sbr" \
	"$(INTDIR)\JDFJDFController.sbr" \
	"$(INTDIR)\JDFJDFService.sbr" \
	"$(INTDIR)\JDFJMF.sbr" \
	"$(INTDIR)\JDFJobPhase.sbr" \
	"$(INTDIR)\JDFKnownMsgQuParams.sbr" \
	"$(INTDIR)\JDFMessage.sbr" \
	"$(INTDIR)\JDFMessageElement.sbr" \
	"$(INTDIR)\JDFMessageService.sbr" \
	"$(INTDIR)\JDFModuleStatus.sbr" \
	"$(INTDIR)\JDFMsgFilter.sbr" \
	"$(INTDIR)\JDFNewJDFCmdParams.sbr" \
	"$(INTDIR)\JDFNewJDFQuParams.sbr" \
	"$(INTDIR)\JDFNodeInfoCmdParams.sbr" \
	"$(INTDIR)\JDFNodeInfoQuParams.sbr" \
	"$(INTDIR)\JDFNodeInfoResp.sbr" \
	"$(INTDIR)\JDFNotificationDef.sbr" \
	"$(INTDIR)\JDFNotificationFilter.sbr" \
	"$(INTDIR)\JDFObservationTarget.sbr" \
	"$(INTDIR)\JDFOccupation.sbr" \
	"$(INTDIR)\JDFPipeParams.sbr" \
	"$(INTDIR)\JDFQuery.sbr" \
	"$(INTDIR)\JDFQueue.sbr" \
	"$(INTDIR)\JDFQueueEntry.sbr" \
	"$(INTDIR)\JDFQueueEntryDef.sbr" \
	"$(INTDIR)\JDFQueueEntryDefList.sbr" \
	"$(INTDIR)\JDFQueueEntryPosParams.sbr" \
	"$(INTDIR)\JDFQueueEntryPriParams.sbr" \
	"$(INTDIR)\JDFQueueFilter.sbr" \
	"$(INTDIR)\JDFQueueSubmissionParams.sbr" \
	"$(INTDIR)\JDFRemoved.sbr" \
	"$(INTDIR)\JDFRequestQueueEntryParams.sbr" \
	"$(INTDIR)\JDFResourceCmdParams.sbr" \
	"$(INTDIR)\JDFResourceInfo.sbr" \
	"$(INTDIR)\JDFResourcePullParams.sbr" \
	"$(INTDIR)\JDFResourceQuParams.sbr" \
	"$(INTDIR)\JDFResponse.sbr" \
	"$(INTDIR)\JDFResubmissionParams.sbr" \
	"$(INTDIR)\JDFReturnQueueEntryParams.sbr" \
	"$(INTDIR)\JDFShutDownCmdParams.sbr" \
	"$(INTDIR)\JDFSignal.sbr" \
	"$(INTDIR)\JDFStatusQuParams.sbr" \
	"$(INTDIR)\JDFStopPersChParams.sbr" \
	"$(INTDIR)\JDFSubmissionMethods.sbr" \
	"$(INTDIR)\JDFSubscription.sbr" \
	"$(INTDIR)\JDFTrackFilter.sbr" \
	"$(INTDIR)\JDFTrackResult.sbr" \
	"$(INTDIR)\JDFTrigger.sbr" \
	"$(INTDIR)\JDFWakeUpCmdParams.sbr" \
	"$(INTDIR)\JDFArtDeliveryIntent.sbr" \
	"$(INTDIR)\JDFBindingIntent.sbr" \
	"$(INTDIR)\JDFColorIntent.sbr" \
	"$(INTDIR)\JDFDeliveryIntent.sbr" \
	"$(INTDIR)\JDFEmbossingIntent.sbr" \
	"$(INTDIR)\JDFFoldingIntent.sbr" \
	"$(INTDIR)\JDFHoleMakingIntent.sbr" \
	"$(INTDIR)\JDFInsertingIntent.sbr" \
	"$(INTDIR)\JDFIntentResource.sbr" \
	"$(INTDIR)\JDFLaminatingIntent.sbr" \
	"$(INTDIR)\JDFLayoutIntent.sbr" \
	"$(INTDIR)\JDFMediaIntent.sbr" \
	"$(INTDIR)\JDFNumberingIntent.sbr" \
	"$(INTDIR)\JDFPackingIntent.sbr" \
	"$(INTDIR)\JDFProductionIntent.sbr" \
	"$(INTDIR)\JDFProofingIntent.sbr" \
	"$(INTDIR)\JDFScreeningIntent.sbr" \
	"$(INTDIR)\JDFShapeCuttingIntent.sbr" \
	"$(INTDIR)\JDFSizeIntent.sbr" \
	"$(INTDIR)\JDFSpan.sbr" \
	"$(INTDIR)\JDFAdhesiveBinding.sbr" \
	"$(INTDIR)\JDFArtDelivery.sbr" \
	"$(INTDIR)\JDFBindItem.sbr" \
	"$(INTDIR)\JDFBindList.sbr" \
	"$(INTDIR)\JDFBookCase.sbr" \
	"$(INTDIR)\JDFChannelBinding.sbr" \
	"$(INTDIR)\JDFCoilBinding.sbr" \
	"$(INTDIR)\JDFColorsUsed.sbr" \
	"$(INTDIR)\JDFCreditCard.sbr" \
	"$(INTDIR)\JDFDropIntent.sbr" \
	"$(INTDIR)\JDFDropItemIntent.sbr" \
	"$(INTDIR)\JDFEdgeGluing.sbr" \
	"$(INTDIR)\JDFEmbossingItem.sbr" \
	"$(INTDIR)\JDFHardCoverBinding.sbr" \
	"$(INTDIR)\JDFHoleList.sbr" \
	"$(INTDIR)\JDFInsert.sbr" \
	"$(INTDIR)\JDFInsertList.sbr" \
	"$(INTDIR)\JDFNumberItem.sbr" \
	"$(INTDIR)\JDFPayment.sbr" \
	"$(INTDIR)\JDFPlasticCombBinding.sbr" \
	"$(INTDIR)\JDFPricing.sbr" \
	"$(INTDIR)\JDFProofItem.sbr" \
	"$(INTDIR)\JDFRingBinding.sbr" \
	"$(INTDIR)\JDFSaddleStitching.sbr" \
	"$(INTDIR)\JDFShapeCut.sbr" \
	"$(INTDIR)\JDFSideSewing.sbr" \
	"$(INTDIR)\JDFSideStitching.sbr" \
	"$(INTDIR)\JDFSoftCoverBinding.sbr" \
	"$(INTDIR)\JDFStripBinding.sbr" \
	"$(INTDIR)\JDFTabs.sbr" \
	"$(INTDIR)\JDFTape.sbr" \
	"$(INTDIR)\JDFThreadSealing.sbr" \
	"$(INTDIR)\JDFThreadSewing.sbr" \
	"$(INTDIR)\JDFWireCombBinding.sbr" \
	"$(INTDIR)\JDFAddress.sbr" \
	"$(INTDIR)\JDFAdhesiveBindingParams.sbr" \
	"$(INTDIR)\JDFApprovalParams.sbr" \
	"$(INTDIR)\JDFApprovalSuccess.sbr" \
	"$(INTDIR)\JDFAssembly.sbr" \
	"$(INTDIR)\JDFAssetListCreationParams.sbr" \
	"$(INTDIR)\JDFAutomatedOverprintParams.sbr" \
	"$(INTDIR)\JDFBinderySignature.sbr" \
	"$(INTDIR)\JDFBlockPreparationParams.sbr" \
	"$(INTDIR)\JDFBoxPackingParams.sbr" \
	"$(INTDIR)\JDFBufferParams.sbr" \
	"$(INTDIR)\JDFBundle.sbr" \
	"$(INTDIR)\JDFBundlingParams.sbr" \
	"$(INTDIR)\JDFByteMap.sbr" \
	"$(INTDIR)\JDFCaseMakingParams.sbr" \
	"$(INTDIR)\JDFCasingInParams.sbr" \
	"$(INTDIR)\JDFChannelBindingParams.sbr" \
	"$(INTDIR)\JDFCIELABMeasuringField.sbr" \
	"$(INTDIR)\JDFCoilBindingParams.sbr" \
	"$(INTDIR)\JDFCollectingParams.sbr" \
	"$(INTDIR)\JDFColor.sbr" \
	"$(INTDIR)\JDFColorantAlias.sbr" \
	"$(INTDIR)\JDFColorantControl.sbr" \
	"$(INTDIR)\JDFColorControlStrip.sbr" \
	"$(INTDIR)\JDFColorCorrectionParams.sbr" \
	"$(INTDIR)\JDFColorMeasurementConditions.sbr" \
	"$(INTDIR)\JDFColorPool.sbr" \
	"$(INTDIR)\JDFColorSpaceConversionOp.sbr" \
	"$(INTDIR)\JDFColorSpaceConversionParams.sbr" \
	"$(INTDIR)\JDFComChannel.sbr" \
	"$(INTDIR)\JDFCompany.sbr" \
	"$(INTDIR)\JDFComponent.sbr" \
	"$(INTDIR)\JDFContact.sbr" \
	"$(INTDIR)\JDFContactCopyParams.sbr" \
	"$(INTDIR)\JDFConventionalPrintingParams.sbr" \
	"$(INTDIR)\JDFCostCenter.sbr" \
	"$(INTDIR)\JDFCoverApplicationParams.sbr" \
	"$(INTDIR)\JDFCreasingParams.sbr" \
	"$(INTDIR)\JDFCutBlock.sbr" \
	"$(INTDIR)\JDFCutMark.sbr" \
	"$(INTDIR)\JDFCuttingParams.sbr" \
	"$(INTDIR)\JDFDBMergeParams.sbr" \
	"$(INTDIR)\JDFDBRules.sbr" \
	"$(INTDIR)\JDFDBSchema.sbr" \
	"$(INTDIR)\JDFDBSelection.sbr" \
	"$(INTDIR)\JDFDeliveryParams.sbr" \
	"$(INTDIR)\JDFDensityMeasuringField.sbr" \
	"$(INTDIR)\JDFDevelopingParams.sbr" \
	"$(INTDIR)\JDFDevice.sbr" \
	"$(INTDIR)\JDFDeviceMark.sbr" \
	"$(INTDIR)\JDFDeviceNSpace.sbr" \
	"$(INTDIR)\JDFDigitalDeliveryParams.sbr" \
	"$(INTDIR)\JDFDigitalMedia.sbr" \
	"$(INTDIR)\JDFDigitalPrintingParams.sbr" \
	"$(INTDIR)\JDFDisjointing.sbr" \
	"$(INTDIR)\JDFDisposition.sbr" \
	"$(INTDIR)\JDFDividingParams.sbr" \
	"$(INTDIR)\JDFElementColorParams.sbr" \
	"$(INTDIR)\JDFEmbossingParams.sbr" \
	"$(INTDIR)\JDFEmployee.sbr" \
	"$(INTDIR)\JDFEndSheetGluingParams.sbr" \
	"$(INTDIR)\JDFExposedMedia.sbr" \
	"$(INTDIR)\JDFFeedingParams.sbr" \
	"$(INTDIR)\JDFFileSpec.sbr" \
	"$(INTDIR)\JDFFitPolicy.sbr" \
	"$(INTDIR)\JDFFold.sbr" \
	"$(INTDIR)\JDFFoldingParams.sbr" \
	"$(INTDIR)\JDFFontParams.sbr" \
	"$(INTDIR)\JDFFontPolicy.sbr" \
	"$(INTDIR)\JDFFormatConversionParams.sbr" \
	"$(INTDIR)\JDFGatheringParams.sbr" \
	"$(INTDIR)\JDFGlueApplication.sbr" \
	"$(INTDIR)\JDFGlueLine.sbr" \
	"$(INTDIR)\JDFGluingParams.sbr" \
	"$(INTDIR)\JDFHeadBandApplicationParams.sbr" \
	"$(INTDIR)\JDFHole.sbr" \
	"$(INTDIR)\JDFHoleLine.sbr" \
	"$(INTDIR)\JDFHoleMakingParams.sbr" \
	"$(INTDIR)\JDFIdentificationField.sbr" \
	"$(INTDIR)\JDFIDPrintingParams.sbr" \
	"$(INTDIR)\JDFImageCompressionParams.sbr" \
	"$(INTDIR)\JDFImageReplacementParams.sbr" \
	"$(INTDIR)\JDFImageSetterParams.sbr" \
	"$(INTDIR)\JDFInk.sbr" \
	"$(INTDIR)\JDFInkZoneCalculationParams.sbr" \
	"$(INTDIR)\JDFInkZoneProfile.sbr" \
	"$(INTDIR)\JDFInsertingParams.sbr" \
	"$(INTDIR)\JDFInsertSheet.sbr" \
	"$(INTDIR)\JDFInterpretedPDLData.sbr" \
	"$(INTDIR)\JDFInterpretingParams.sbr" \
	"$(INTDIR)\JDFJacketingParams.sbr" \
	"$(INTDIR)\JDFJobField.sbr" \
	"$(INTDIR)\JDFLabelingParams.sbr" \
	"$(INTDIR)\JDFLaminatingParams.sbr" \
	"$(INTDIR)\JDFLayout.sbr" \
	"$(INTDIR)\JDFLayoutElement.sbr" \
	"$(INTDIR)\JDFLayoutPreparationParams.sbr" \
	"$(INTDIR)\JDFLongitudinalRibbonOperationParams.sbr" \
	"$(INTDIR)\JDFManualLaborParams.sbr" \
	"$(INTDIR)\JDFMedia.sbr" \
	"$(INTDIR)\JDFMediaSource.sbr" \
	"$(INTDIR)\JDFMISDetails.sbr" \
	"$(INTDIR)\JDFNumberingParams.sbr" \
	"$(INTDIR)\JDFObjectResolution.sbr" \
	"$(INTDIR)\JDFOrderingParams.sbr" \
	"$(INTDIR)\JDFPackingParams.sbr" \
	"$(INTDIR)\JDFPageList.sbr" \
	"$(INTDIR)\JDFPallet.sbr" \
	"$(INTDIR)\JDFPalletizingParams.sbr" \
	"$(INTDIR)\JDFPDFToPSConversionParams.sbr" \
	"$(INTDIR)\JDFPDLResourceAlias.sbr" \
	"$(INTDIR)\JDFPerforatingParams.sbr" \
	"$(INTDIR)\JDFPerson.sbr" \
	"$(INTDIR)\JDFPlaceHolderResource.sbr" \
	"$(INTDIR)\JDFPlasticCombBindingParams.sbr" \
	"$(INTDIR)\JDFPlateCopyParams.sbr" \
	"$(INTDIR)\JDFPreflightAnalysis.sbr" \
	"$(INTDIR)\JDFPreflightInventory.sbr" \
	"$(INTDIR)\JDFPreflightParams.sbr" \
	"$(INTDIR)\JDFPreflightProfile.sbr" \
	"$(INTDIR)\JDFPreflightReport.sbr" \
	"$(INTDIR)\JDFPreflightReportRulePool.sbr" \
	"$(INTDIR)\JDFPreview.sbr" \
	"$(INTDIR)\JDFPreviewGenerationParams.sbr" \
	"$(INTDIR)\JDFPrintCondition.sbr" \
	"$(INTDIR)\JDFPrintRollingParams.sbr" \
	"$(INTDIR)\JDFProofingParams.sbr" \
	"$(INTDIR)\JDFPSToPDFConversionParams.sbr" \
	"$(INTDIR)\JDFQualityControlParams.sbr" \
	"$(INTDIR)\JDFQualityControlResult.sbr" \
	"$(INTDIR)\JDFRegisterMark.sbr" \
	"$(INTDIR)\JDFRegisterRibbon.sbr" \
	"$(INTDIR)\JDFRenderingParams.sbr" \
	"$(INTDIR)\JDFResourceDefinitionParams.sbr" \
	"$(INTDIR)\JDFRingBindingParams.sbr" \
	"$(INTDIR)\JDFRollStand.sbr" \
	"$(INTDIR)\JDFRunList.sbr" \
	"$(INTDIR)\JDFSaddleStitchingParams.sbr" \
	"$(INTDIR)\JDFScanParams.sbr" \
	"$(INTDIR)\JDFScavengerArea.sbr" \
	"$(INTDIR)\JDFScreeningParams.sbr" \
	"$(INTDIR)\JDFSeparationControlParams.sbr" \
	"$(INTDIR)\JDFSeparationSpec.sbr" \
	"$(INTDIR)\JDFShapeCuttingParams.sbr" \
	"$(INTDIR)\JDFSheet.sbr" \
	"$(INTDIR)\JDFShrinkingParams.sbr" \
	"$(INTDIR)\JDFSideSewingParams.sbr" \
	"$(INTDIR)\JDFSpinePreparationParams.sbr" \
	"$(INTDIR)\JDFSpineTapingParams.sbr" \
	"$(INTDIR)\JDFStackingParams.sbr" \
	"$(INTDIR)\JDFStitchingParams.sbr" \
	"$(INTDIR)\JDFStrap.sbr" \
	"$(INTDIR)\JDFStrappingParams.sbr" \
	"$(INTDIR)\JDFStripBindingParams.sbr" \
	"$(INTDIR)\JDFStrippingParams.sbr" \
	"$(INTDIR)\JDFSurface.sbr" \
	"$(INTDIR)\JDFThreadSealingParams.sbr" \
	"$(INTDIR)\JDFThreadSewingParams.sbr" \
	"$(INTDIR)\JDFTile.sbr" \
	"$(INTDIR)\JDFTool.sbr" \
	"$(INTDIR)\JDFTransferCurve.sbr" \
	"$(INTDIR)\JDFTransferCurvePool.sbr" \
	"$(INTDIR)\JDFTransferFunctionControl.sbr" \
	"$(INTDIR)\JDFTrappingDetails.sbr" \
	"$(INTDIR)\JDFTrappingParams.sbr" \
	"$(INTDIR)\JDFTrapRegion.sbr" \
	"$(INTDIR)\JDFTrimmingParams.sbr" \
	"$(INTDIR)\JDFVerificationParams.sbr" \
	"$(INTDIR)\JDFWireCombBindingParams.sbr" \
	"$(INTDIR)\JDFWrappingParams.sbr" \
	"$(INTDIR)\JDFAdvancedParams.sbr" \
	"$(INTDIR)\JDFApprovalPerson.sbr" \
	"$(INTDIR)\JDFAssemblySection.sbr" \
	"$(INTDIR)\JDFBand.sbr" \
	"$(INTDIR)\JDFBasicPreflightTest.sbr" \
	"$(INTDIR)\JDFBindingQualityParams.sbr" \
	"$(INTDIR)\JDFBoxArgument.sbr" \
	"$(INTDIR)\JDFBoxToBoxDifference.sbr" \
	"$(INTDIR)\JDFBundleItem.sbr" \
	"$(INTDIR)\JDFCCITTFaxParams.sbr" \
	"$(INTDIR)\JDFCollatingItem.sbr" \
	"$(INTDIR)\JDFColorantZoneDetails.sbr" \
	"$(INTDIR)\JDFColorCorrectionOp.sbr" \
	"$(INTDIR)\JDFColorSpaceSubstitute.sbr" \
	"$(INTDIR)\JDFContainer.sbr" \
	"$(INTDIR)\JDFContentObject.sbr" \
	"$(INTDIR)\JDFCrease.sbr" \
	"$(INTDIR)\JDFCut.sbr" \
	"$(INTDIR)\JDFDCTParams.sbr" \
	"$(INTDIR)\JDFDependencies.sbr" \
	"$(INTDIR)\JDFDeviceNColor.sbr" \
	"$(INTDIR)\JDFDrop.sbr" \
	"$(INTDIR)\JDFDropItem.sbr" \
	"$(INTDIR)\JDFDynamicField.sbr" \
	"$(INTDIR)\JDFDynamicInput.sbr" \
	"$(INTDIR)\JDFEmboss.sbr" \
	"$(INTDIR)\JDFEndSheet.sbr" \
	"$(INTDIR)\JDFFeeder.sbr" \
	"$(INTDIR)\JDFFeederQualityParams.sbr" \
	"$(INTDIR)\JDFFileAlias.sbr" \
	"$(INTDIR)\JDFFlateParams.sbr" \
	"$(INTDIR)\JDFGlue.sbr" \
	"$(INTDIR)\JDFIcon.sbr" \
	"$(INTDIR)\JDFIconList.sbr" \
	"$(INTDIR)\JDFIDPCover.sbr" \
	"$(INTDIR)\JDFIDPFinishing.sbr" \
	"$(INTDIR)\JDFIDPFolding.sbr" \
	"$(INTDIR)\JDFIDPHoleMaking.sbr" \
	"$(INTDIR)\JDFIDPImageShift.sbr" \
	"$(INTDIR)\JDFIDPJobSheet.sbr" \
	"$(INTDIR)\JDFIDPLayout.sbr" \
	"$(INTDIR)\JDFIDPStitching.sbr" \
	"$(INTDIR)\JDFIDPTrimming.sbr" \
	"$(INTDIR)\JDFImageCompression.sbr" \
	"$(INTDIR)\JDFImageShift.sbr" \
	"$(INTDIR)\JDFLayerDetails.sbr" \
	"$(INTDIR)\JDFLayerList.sbr" \
	"$(INTDIR)\JDFLongFold.sbr" \
	"$(INTDIR)\JDFLongGlue.sbr" \
	"$(INTDIR)\JDFLongPerforate.sbr" \
	"$(INTDIR)\JDFLongSlit.sbr" \
	"$(INTDIR)\JDFLZWParams.sbr" \
	"$(INTDIR)\JDFMarkObject.sbr" \
	"$(INTDIR)\JDFNumberingParam.sbr" \
	"$(INTDIR)\JDFPageCell.sbr" \
	"$(INTDIR)\JDFPageData.sbr" \
	"$(INTDIR)\JDFPDFInterpretingParams.sbr" \
	"$(INTDIR)\JDFPDFXParams.sbr" \
	"$(INTDIR)\JDFPerforate.sbr" \
	"$(INTDIR)\JDFPixelColorant.sbr" \
	"$(INTDIR)\JDFPosition.sbr" \
	"$(INTDIR)\JDFPreflightAction.sbr" \
	"$(INTDIR)\JDFPreflightArgument.sbr" \
	"$(INTDIR)\JDFPreflightConstraint.sbr" \
	"$(INTDIR)\JDFPreflightDetail.sbr" \
	"$(INTDIR)\JDFPreflightInstance.sbr" \
	"$(INTDIR)\JDFPreflightInstanceDetail.sbr" \
	"$(INTDIR)\JDFPreflightValue.sbr" \
	"$(INTDIR)\JDFPRError.sbr" \
	"$(INTDIR)\JDFPRGroup.sbr" \
	"$(INTDIR)\JDFPrintConditionColor.sbr" \
	"$(INTDIR)\JDFPRItem.sbr" \
	"$(INTDIR)\JDFPROccurence.sbr" \
	"$(INTDIR)\JDFProperties.sbr" \
	"$(INTDIR)\JDFPRRule.sbr" \
	"$(INTDIR)\JDFPRRuleAttr.sbr" \
	"$(INTDIR)\JDFQualityMeasurement.sbr" \
	"$(INTDIR)\JDFResourceParam.sbr" \
	"$(INTDIR)\JDFScore.sbr" \
	"$(INTDIR)\JDFScreenSelector.sbr" \
	"$(INTDIR)\JDFShapeElement.sbr" \
	"$(INTDIR)\JDFSignature.sbr" \
	"$(INTDIR)\JDFSignatureCell.sbr" \
	"$(INTDIR)\JDFStringListValue.sbr" \
	"$(INTDIR)\JDFStripCellParams.sbr" \
	"$(INTDIR)\JDFThinPDFParams.sbr" \
	"$(INTDIR)\JDFTIFFEmbeddedFile.sbr" \
	"$(INTDIR)\JDFTIFFFormatParams.sbr" \
	"$(INTDIR)\JDFTIFFtag.sbr" \
	"$(INTDIR)\JDFTransferCurveSet.sbr" \
	"$(INTDIR)\JDFTrappingOrder.sbr" \
	"$(INTDIR)\JDFAction.sbr" \
	"$(INTDIR)\JDFActionPool.sbr" \
	"$(INTDIR)\JDFand.sbr" \
	"$(INTDIR)\JDFBooleanEvaluation.sbr" \
	"$(INTDIR)\JDFBooleanState.sbr" \
	"$(INTDIR)\JDFcall.sbr" \
	"$(INTDIR)\JDFchoice.sbr" \
	"$(INTDIR)\JDFDateTimeEvaluation.sbr" \
	"$(INTDIR)\JDFDateTimeState.sbr" \
	"$(INTDIR)\JDFDevCap.sbr" \
	"$(INTDIR)\JDFDevCaps.sbr" \
	"$(INTDIR)\JDFDeviceCap.sbr" \
	"$(INTDIR)\JDFDisplayGroup.sbr" \
	"$(INTDIR)\JDFDisplayGroupPool.sbr" \
	"$(INTDIR)\JDFDurationEvaluation.sbr" \
	"$(INTDIR)\JDFDurationState.sbr" \
	"$(INTDIR)\JDFEnumerationEvaluation.sbr" \
	"$(INTDIR)\JDFEnumerationState.sbr" \
	"$(INTDIR)\JDFEvaluation.sbr" \
	"$(INTDIR)\JDFFeatureAttribute.sbr" \
	"$(INTDIR)\JDFFeaturePool.sbr" \
	"$(INTDIR)\JDFIntegerEvaluation.sbr" \
	"$(INTDIR)\JDFIntegerState.sbr" \
	"$(INTDIR)\JDFIsPresentEvaluation.sbr" \
	"$(INTDIR)\JDFLoc.sbr" \
	"$(INTDIR)\JDFmacro.sbr" \
	"$(INTDIR)\JDFMacroPool.sbr" \
	"$(INTDIR)\JDFMatrixEvaluation.sbr" \
	"$(INTDIR)\JDFMatrixState.sbr" \
	"$(INTDIR)\JDFNameEvaluation.sbr" \
	"$(INTDIR)\JDFNameState.sbr" \
	"$(INTDIR)\JDFnot.sbr" \
	"$(INTDIR)\JDFNumberEvaluation.sbr" \
	"$(INTDIR)\JDFNumberState.sbr" \
	"$(INTDIR)\JDFor.sbr" \
	"$(INTDIR)\JDFotherwise.sbr" \
	"$(INTDIR)\JDFPDFPathEvaluation.sbr" \
	"$(INTDIR)\JDFPDFPathState.sbr" \
	"$(INTDIR)\JDFPerformance.sbr" \
	"$(INTDIR)\JDFRectangleEvaluation.sbr" \
	"$(INTDIR)\JDFRectangleState.sbr" \
	"$(INTDIR)\JDFset.sbr" \
	"$(INTDIR)\JDFShapeEvaluation.sbr" \
	"$(INTDIR)\JDFShapeState.sbr" \
	"$(INTDIR)\JDFState.sbr" \
	"$(INTDIR)\JDFStringEvaluation.sbr" \
	"$(INTDIR)\JDFStringState.sbr" \
	"$(INTDIR)\JDFTest.sbr" \
	"$(INTDIR)\JDFTestPool.sbr" \
	"$(INTDIR)\JDFTestRef.sbr" \
	"$(INTDIR)\JDFValue.sbr" \
	"$(INTDIR)\JDFValueLoc.sbr" \
	"$(INTDIR)\JDFwhen.sbr" \
	"$(INTDIR)\JDFxor.sbr" \
	"$(INTDIR)\JDFXYPairEvaluation.sbr" \
	"$(INTDIR)\JDFXYPairState.sbr" \
	"$(INTDIR)\JDFDoc.sbr" \
	"$(INTDIR)\JDFElement.sbr" \
	"$(INTDIR)\JDFFactory.sbr" \
	"$(INTDIR)\JDFNodeFactory.sbr" \
	"$(INTDIR)\JDFParamsFactory.sbr" \
	"$(INTDIR)\JDFPool.sbr" \
	"$(INTDIR)\JDFRefElement.sbr" \
	"$(INTDIR)\JDFResource.sbr" \
	"$(INTDIR)\JDFResourceLink.sbr" \
	"$(INTDIR)\JDFRunElement.sbr" \
	"$(INTDIR)\JDFSeparationList.sbr" \
	"$(INTDIR)\JDFStrings.sbr" \
	"$(INTDIR)\JDFAutoAmountPool.sbr" \
	"$(INTDIR)\JDFAutoAncestor.sbr" \
	"$(INTDIR)\JDFAutoAncestorPool.sbr" \
	"$(INTDIR)\JDFAutoBarcode.sbr" \
	"$(INTDIR)\JDFAutoBusinessInfo.sbr" \
	"$(INTDIR)\JDFAutoComment.sbr" \
	"$(INTDIR)\JDFAutoCounterReset.sbr" \
	"$(INTDIR)\JDFAutoCreated.sbr" \
	"$(INTDIR)\JDFAutoCustomerInfo.sbr" \
	"$(INTDIR)\JDFAutoCustomerMessage.sbr" \
	"$(INTDIR)\JDFAutoDeleted.sbr" \
	"$(INTDIR)\JDFAutoError.sbr" \
	"$(INTDIR)\JDFAutoEvent.sbr" \
	"$(INTDIR)\JDFAutoFCNKey.sbr" \
	"$(INTDIR)\JDFAutoLocation.sbr" \
	"$(INTDIR)\JDFAutoMerged.sbr" \
	"$(INTDIR)\JDFAutoModified.sbr" \
	"$(INTDIR)\JDFAutoModulePhase.sbr" \
	"$(INTDIR)\JDFAutoNodeInfo.sbr" \
	"$(INTDIR)\JDFAutoNotification.sbr" \
	"$(INTDIR)\JDFAutoPart.sbr" \
	"$(INTDIR)\JDFAutoPartStatus.sbr" \
	"$(INTDIR)\JDFAutoPhaseTime.sbr" \
	"$(INTDIR)\JDFAutoProcessRun.sbr" \
	"$(INTDIR)\JDFAutoResourceAudit.sbr" \
	"$(INTDIR)\JDFAutoSpawned.sbr" \
	"$(INTDIR)\JDFAutoStatusPool.sbr" \
	"$(INTDIR)\JDFAutoSystemTimeSet.sbr" \
	"$(INTDIR)\JDFAutoAcknowledge.sbr" \
	"$(INTDIR)\JDFAutoAdded.sbr" \
	"$(INTDIR)\JDFAutoChangedAttribute.sbr" \
	"$(INTDIR)\JDFAutoChangedPath.sbr" \
	"$(INTDIR)\JDFAutoCommand.sbr" \
	"$(INTDIR)\JDFAutoDeviceFilter.sbr" \
	"$(INTDIR)\JDFAutoDeviceInfo.sbr" \
	"$(INTDIR)\JDFAutoDeviceList.sbr" \
	"$(INTDIR)\JDFAutoEmployeeDef.sbr" \
	"$(INTDIR)\JDFAutoFlushedResources.sbr" \
	"$(INTDIR)\JDFAutoFlushQueueParams.sbr" \
	"$(INTDIR)\JDFAutoFlushResourceParams.sbr" \
	"$(INTDIR)\JDFAutoIDInfo.sbr" \
	"$(INTDIR)\JDFAutoJDFController.sbr" \
	"$(INTDIR)\JDFAutoJDFService.sbr" \
	"$(INTDIR)\JDFAutoJMF.sbr" \
	"$(INTDIR)\JDFAutoJobPhase.sbr" \
	"$(INTDIR)\JDFAutoKnownMsgQuParams.sbr" \
	"$(INTDIR)\JDFAutoMessage.sbr" \
	"$(INTDIR)\JDFAutoMessageService.sbr" \
	"$(INTDIR)\JDFAutoModuleStatus.sbr" \
	"$(INTDIR)\JDFAutoMsgFilter.sbr" \
	"$(INTDIR)\JDFAutoNewJDFCmdParams.sbr" \
	"$(INTDIR)\JDFAutoNewJDFQuParams.sbr" \
	"$(INTDIR)\JDFAutoNodeInfoCmdParams.sbr" \
	"$(INTDIR)\JDFAutoNodeInfoQuParams.sbr" \
	"$(INTDIR)\JDFAutoNodeInfoResp.sbr" \
	"$(INTDIR)\JDFAutoNotificationDef.sbr" \
	"$(INTDIR)\JDFAutoNotificationFilter.sbr" \
	"$(INTDIR)\JDFAutoObservationTarget.sbr" \
	"$(INTDIR)\JDFAutoOccupation.sbr" \
	"$(INTDIR)\JDFAutoPipeParams.sbr" \
	"$(INTDIR)\JDFAutoQuery.sbr" \
	"$(INTDIR)\JDFAutoQueue.sbr" \
	"$(INTDIR)\JDFAutoQueueEntry.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryDef.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryDefList.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryPosParams.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryPriParams.sbr" \
	"$(INTDIR)\JDFAutoQueueFilter.sbr" \
	"$(INTDIR)\JDFAutoQueueSubmissionParams.sbr" \
	"$(INTDIR)\JDFAutoRemoved.sbr" \
	"$(INTDIR)\JDFAutoRequestQueueEntryParams.sbr" \
	"$(INTDIR)\JDFAutoResourceCmdParams.sbr" \
	"$(INTDIR)\JDFAutoResourceInfo.sbr" \
	"$(INTDIR)\JDFAutoResourcePullParams.sbr" \
	"$(INTDIR)\JDFAutoResourceQuParams.sbr" \
	"$(INTDIR)\JDFAutoResponse.sbr" \
	"$(INTDIR)\JDFAutoResubmissionParams.sbr" \
	"$(INTDIR)\JDFAutoReturnQueueEntryParams.sbr" \
	"$(INTDIR)\JDFAutoShutDownCmdParams.sbr" \
	"$(INTDIR)\JDFAutoSignal.sbr" \
	"$(INTDIR)\JDFAutoStatusQuParams.sbr" \
	"$(INTDIR)\JDFAutoStopPersChParams.sbr" \
	"$(INTDIR)\JDFAutoSubmissionMethods.sbr" \
	"$(INTDIR)\JDFAutoSubscription.sbr" \
	"$(INTDIR)\JDFAutoTrackFilter.sbr" \
	"$(INTDIR)\JDFAutoTrackResult.sbr" \
	"$(INTDIR)\JDFAutoTrigger.sbr" \
	"$(INTDIR)\JDFAutoWakeUpCmdParams.sbr" \
	"$(INTDIR)\JDFAutoArtDeliveryIntent.sbr" \
	"$(INTDIR)\JDFAutoBindingIntent.sbr" \
	"$(INTDIR)\JDFAutoColorIntent.sbr" \
	"$(INTDIR)\JDFAutoDeliveryIntent.sbr" \
	"$(INTDIR)\JDFAutoEmbossingIntent.sbr" \
	"$(INTDIR)\JDFAutoFoldingIntent.sbr" \
	"$(INTDIR)\JDFAutoHoleMakingIntent.sbr" \
	"$(INTDIR)\JDFAutoInsertingIntent.sbr" \
	"$(INTDIR)\JDFAutoLaminatingIntent.sbr" \
	"$(INTDIR)\JDFAutoLayoutIntent.sbr" \
	"$(INTDIR)\JDFAutoMediaIntent.sbr" \
	"$(INTDIR)\JDFAutoNumberingIntent.sbr" \
	"$(INTDIR)\JDFAutoPackingIntent.sbr" \
	"$(INTDIR)\JDFAutoProductionIntent.sbr" \
	"$(INTDIR)\JDFAutoProofingIntent.sbr" \
	"$(INTDIR)\JDFAutoScreeningIntent.sbr" \
	"$(INTDIR)\JDFAutoShapeCuttingIntent.sbr" \
	"$(INTDIR)\JDFAutoSizeIntent.sbr" \
	"$(INTDIR)\JDFAutoAdhesiveBinding.sbr" \
	"$(INTDIR)\JDFAutoArtDelivery.sbr" \
	"$(INTDIR)\JDFAutoBindItem.sbr" \
	"$(INTDIR)\JDFAutoBindList.sbr" \
	"$(INTDIR)\JDFAutoBookCase.sbr" \
	"$(INTDIR)\JDFAutoChannelBinding.sbr" \
	"$(INTDIR)\JDFAutoCoilBinding.sbr" \
	"$(INTDIR)\JDFAutoColorsUsed.sbr" \
	"$(INTDIR)\JDFAutoCreditCard.sbr" \
	"$(INTDIR)\JDFAutoDropIntent.sbr" \
	"$(INTDIR)\JDFAutoDropItemIntent.sbr" \
	"$(INTDIR)\JDFAutoEdgeGluing.sbr" \
	"$(INTDIR)\JDFAutoEmbossingItem.sbr" \
	"$(INTDIR)\JDFAutoHardCoverBinding.sbr" \
	"$(INTDIR)\JDFAutoHoleList.sbr" \
	"$(INTDIR)\JDFAutoInsert.sbr" \
	"$(INTDIR)\JDFAutoInsertList.sbr" \
	"$(INTDIR)\JDFAutoNumberItem.sbr" \
	"$(INTDIR)\JDFAutoPayment.sbr" \
	"$(INTDIR)\JDFAutoPlasticCombBinding.sbr" \
	"$(INTDIR)\JDFAutoPricing.sbr" \
	"$(INTDIR)\JDFAutoProofItem.sbr" \
	"$(INTDIR)\JDFAutoRingBinding.sbr" \
	"$(INTDIR)\JDFAutoSaddleStitching.sbr" \
	"$(INTDIR)\JDFAutoShapeCut.sbr" \
	"$(INTDIR)\JDFAutoSideSewing.sbr" \
	"$(INTDIR)\JDFAutoSideStitching.sbr" \
	"$(INTDIR)\JDFAutoSoftCoverBinding.sbr" \
	"$(INTDIR)\JDFAutoStripBinding.sbr" \
	"$(INTDIR)\JDFAutoTabs.sbr" \
	"$(INTDIR)\JDFAutoTape.sbr" \
	"$(INTDIR)\JDFAutoThreadSealing.sbr" \
	"$(INTDIR)\JDFAutoThreadSewing.sbr" \
	"$(INTDIR)\JDFAutoWireCombBinding.sbr" \
	"$(INTDIR)\JDFAutoAddress.sbr" \
	"$(INTDIR)\JDFAutoAdhesiveBindingParams.sbr" \
	"$(INTDIR)\JDFAutoApprovalParams.sbr" \
	"$(INTDIR)\JDFAutoApprovalSuccess.sbr" \
	"$(INTDIR)\JDFAutoAssembly.sbr" \
	"$(INTDIR)\JDFAutoAssetListCreationParams.sbr" \
	"$(INTDIR)\JDFAutoAutomatedOverprintParams.sbr" \
	"$(INTDIR)\JDFAutoBinderySignature.sbr" \
	"$(INTDIR)\JDFAutoBlockPreparationParams.sbr" \
	"$(INTDIR)\JDFAutoBoxPackingParams.sbr" \
	"$(INTDIR)\JDFAutoBufferParams.sbr" \
	"$(INTDIR)\JDFAutoBundle.sbr" \
	"$(INTDIR)\JDFAutoBundlingParams.sbr" \
	"$(INTDIR)\JDFAutoByteMap.sbr" \
	"$(INTDIR)\JDFAutoCaseMakingParams.sbr" \
	"$(INTDIR)\JDFAutoCasingInParams.sbr" \
	"$(INTDIR)\JDFAutoChannelBindingParams.sbr" \
	"$(INTDIR)\JDFAutoCIELABMeasuringField.sbr" \
	"$(INTDIR)\JDFAutoCoilBindingParams.sbr" \
	"$(INTDIR)\JDFAutoCollectingParams.sbr" \
	"$(INTDIR)\JDFAutoColor.sbr" \
	"$(INTDIR)\JDFAutoColorantAlias.sbr" \
	"$(INTDIR)\JDFAutoColorantControl.sbr" \
	"$(INTDIR)\JDFAutoColorControlStrip.sbr" \
	"$(INTDIR)\JDFAutoColorCorrectionParams.sbr" \
	"$(INTDIR)\JDFAutoColorMeasurementConditions.sbr" \
	"$(INTDIR)\JDFAutoColorPool.sbr" \
	"$(INTDIR)\JDFAutoColorSpaceConversionOp.sbr" \
	"$(INTDIR)\JDFAutoColorSpaceConversionParams.sbr" \
	"$(INTDIR)\JDFAutoComChannel.sbr" \
	"$(INTDIR)\JDFAutoCompany.sbr" \
	"$(INTDIR)\JDFAutoComponent.sbr" \
	"$(INTDIR)\JDFAutoContact.sbr" \
	"$(INTDIR)\JDFAutoContactCopyParams.sbr" \
	"$(INTDIR)\JDFAutoConventionalPrintingParams.sbr" \
	"$(INTDIR)\JDFAutoCostCenter.sbr" \
	"$(INTDIR)\JDFAutoCoverApplicationParams.sbr" \
	"$(INTDIR)\JDFAutoCreasingParams.sbr" \
	"$(INTDIR)\JDFAutoCutBlock.sbr" \
	"$(INTDIR)\JDFAutoCutMark.sbr" \
	"$(INTDIR)\JDFAutoCuttingParams.sbr" \
	"$(INTDIR)\JDFAutoDBMergeParams.sbr" \
	"$(INTDIR)\JDFAutoDBRules.sbr" \
	"$(INTDIR)\JDFAutoDBSchema.sbr" \
	"$(INTDIR)\JDFAutoDBSelection.sbr" \
	"$(INTDIR)\JDFAutoDeliveryParams.sbr" \
	"$(INTDIR)\JDFAutoDensityMeasuringField.sbr" \
	"$(INTDIR)\JDFAutoDevelopingParams.sbr" \
	"$(INTDIR)\JDFAutoDevice.sbr" \
	"$(INTDIR)\JDFAutoDeviceMark.sbr" \
	"$(INTDIR)\JDFAutoDeviceNSpace.sbr" \
	"$(INTDIR)\JDFAutoDigitalDeliveryParams.sbr" \
	"$(INTDIR)\JDFAutoDigitalMedia.sbr" \
	"$(INTDIR)\JDFAutoDigitalPrintingParams.sbr" \
	"$(INTDIR)\JDFAutoDisjointing.sbr" \
	"$(INTDIR)\JDFAutoDisposition.sbr" \
	"$(INTDIR)\JDFAutoDividingParams.sbr" \
	"$(INTDIR)\JDFAutoElementColorParams.sbr" \
	"$(INTDIR)\JDFAutoEmbossingParams.sbr" \
	"$(INTDIR)\JDFAutoEmployee.sbr" \
	"$(INTDIR)\JDFAutoEndSheetGluingParams.sbr" \
	"$(INTDIR)\JDFAutoExposedMedia.sbr" \
	"$(INTDIR)\JDFAutoFeedingParams.sbr" \
	"$(INTDIR)\JDFAutoFileSpec.sbr" \
	"$(INTDIR)\JDFAutoFitPolicy.sbr" \
	"$(INTDIR)\JDFAutoFold.sbr" \
	"$(INTDIR)\JDFAutoFoldingParams.sbr" \
	"$(INTDIR)\JDFAutoFontParams.sbr" \
	"$(INTDIR)\JDFAutoFontPolicy.sbr" \
	"$(INTDIR)\JDFAutoFormatConversionParams.sbr" \
	"$(INTDIR)\JDFAutoGatheringParams.sbr" \
	"$(INTDIR)\JDFAutoGlueApplication.sbr" \
	"$(INTDIR)\JDFAutoGlueLine.sbr" \
	"$(INTDIR)\JDFAutoGluingParams.sbr" \
	"$(INTDIR)\JDFAutoHeadBandApplicationParams.sbr" \
	"$(INTDIR)\JDFAutoHole.sbr" \
	"$(INTDIR)\JDFAutoHoleLine.sbr" \
	"$(INTDIR)\JDFAutoHoleMakingParams.sbr" \
	"$(INTDIR)\JDFAutoIdentificationField.sbr" \
	"$(INTDIR)\JDFAutoIDPrintingParams.sbr" \
	"$(INTDIR)\JDFAutoImageCompressionParams.sbr" \
	"$(INTDIR)\JDFAutoImageReplacementParams.sbr" \
	"$(INTDIR)\JDFAutoImageSetterParams.sbr" \
	"$(INTDIR)\JDFAutoInk.sbr" \
	"$(INTDIR)\JDFAutoInkZoneCalculationParams.sbr" \
	"$(INTDIR)\JDFAutoInkZoneProfile.sbr" \
	"$(INTDIR)\JDFAutoInsertingParams.sbr" \
	"$(INTDIR)\JDFAutoInsertSheet.sbr" \
	"$(INTDIR)\JDFAutoInterpretedPDLData.sbr" \
	"$(INTDIR)\JDFAutoInterpretingParams.sbr" \
	"$(INTDIR)\JDFAutoJacketingParams.sbr" \
	"$(INTDIR)\JDFAutoJobField.sbr" \
	"$(INTDIR)\JDFAutoLabelingParams.sbr" \
	"$(INTDIR)\JDFAutoLaminatingParams.sbr" \
	"$(INTDIR)\JDFAutoLayout.sbr" \
	"$(INTDIR)\JDFAutoLayoutElement.sbr" \
	"$(INTDIR)\JDFAutoLayoutPreparationParams.sbr" \
	"$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.sbr" \
	"$(INTDIR)\JDFAutoManualLaborParams.sbr" \
	"$(INTDIR)\JDFAutoMedia.sbr" \
	"$(INTDIR)\JDFAutoMediaSource.sbr" \
	"$(INTDIR)\JDFAutoMISDetails.sbr" \
	"$(INTDIR)\JDFAutoNumberingParams.sbr" \
	"$(INTDIR)\JDFAutoObjectResolution.sbr" \
	"$(INTDIR)\JDFAutoOrderingParams.sbr" \
	"$(INTDIR)\JDFAutoPackingParams.sbr" \
	"$(INTDIR)\JDFAutoPageList.sbr" \
	"$(INTDIR)\JDFAutoPallet.sbr" \
	"$(INTDIR)\JDFAutoPalletizingParams.sbr" \
	"$(INTDIR)\JDFAutoPDFToPSConversionParams.sbr" \
	"$(INTDIR)\JDFAutoPDLResourceAlias.sbr" \
	"$(INTDIR)\JDFAutoPerforatingParams.sbr" \
	"$(INTDIR)\JDFAutoPerson.sbr" \
	"$(INTDIR)\JDFAutoPlaceHolderResource.sbr" \
	"$(INTDIR)\JDFAutoPlasticCombBindingParams.sbr" \
	"$(INTDIR)\JDFAutoPlateCopyParams.sbr" \
	"$(INTDIR)\JDFAutoPreflightAnalysis.sbr" \
	"$(INTDIR)\JDFAutoPreflightInventory.sbr" \
	"$(INTDIR)\JDFAutoPreflightParams.sbr" \
	"$(INTDIR)\JDFAutoPreflightProfile.sbr" \
	"$(INTDIR)\JDFAutoPreflightReport.sbr" \
	"$(INTDIR)\JDFAutoPreflightReportRulePool.sbr" \
	"$(INTDIR)\JDFAutoPreview.sbr" \
	"$(INTDIR)\JDFAutoPreviewGenerationParams.sbr" \
	"$(INTDIR)\JDFAutoPrintCondition.sbr" \
	"$(INTDIR)\JDFAutoPrintRollingParams.sbr" \
	"$(INTDIR)\JDFAutoProofingParams.sbr" \
	"$(INTDIR)\JDFAutoPSToPDFConversionParams.sbr" \
	"$(INTDIR)\JDFAutoQualityControlParams.sbr" \
	"$(INTDIR)\JDFAutoQualityControlResult.sbr" \
	"$(INTDIR)\JDFAutoRegisterMark.sbr" \
	"$(INTDIR)\JDFAutoRegisterRibbon.sbr" \
	"$(INTDIR)\JDFAutoRenderingParams.sbr" \
	"$(INTDIR)\JDFAutoResourceDefinitionParams.sbr" \
	"$(INTDIR)\JDFAutoRingBindingParams.sbr" \
	"$(INTDIR)\JDFAutoRollStand.sbr" \
	"$(INTDIR)\JDFAutoRunList.sbr" \
	"$(INTDIR)\JDFAutoSaddleStitchingParams.sbr" \
	"$(INTDIR)\JDFAutoScanParams.sbr" \
	"$(INTDIR)\JDFAutoScavengerArea.sbr" \
	"$(INTDIR)\JDFAutoScreeningParams.sbr" \
	"$(INTDIR)\JDFAutoSeparationControlParams.sbr" \
	"$(INTDIR)\JDFAutoSeparationSpec.sbr" \
	"$(INTDIR)\JDFAutoShapeCuttingParams.sbr" \
	"$(INTDIR)\JDFAutoSheet.sbr" \
	"$(INTDIR)\JDFAutoShrinkingParams.sbr" \
	"$(INTDIR)\JDFAutoSideSewingParams.sbr" \
	"$(INTDIR)\JDFAutoSpinePreparationParams.sbr" \
	"$(INTDIR)\JDFAutoSpineTapingParams.sbr" \
	"$(INTDIR)\JDFAutoStackingParams.sbr" \
	"$(INTDIR)\JDFAutoStitchingParams.sbr" \
	"$(INTDIR)\JDFAutoStrap.sbr" \
	"$(INTDIR)\JDFAutoStrappingParams.sbr" \
	"$(INTDIR)\JDFAutoStripBindingParams.sbr" \
	"$(INTDIR)\JDFAutoStrippingParams.sbr" \
	"$(INTDIR)\JDFAutoSurface.sbr" \
	"$(INTDIR)\JDFAutoThreadSealingParams.sbr" \
	"$(INTDIR)\JDFAutoThreadSewingParams.sbr" \
	"$(INTDIR)\JDFAutoTile.sbr" \
	"$(INTDIR)\JDFAutoTool.sbr" \
	"$(INTDIR)\JDFAutoTransferCurve.sbr" \
	"$(INTDIR)\JDFAutoTransferCurvePool.sbr" \
	"$(INTDIR)\JDFAutoTransferFunctionControl.sbr" \
	"$(INTDIR)\JDFAutoTrappingDetails.sbr" \
	"$(INTDIR)\JDFAutoTrappingParams.sbr" \
	"$(INTDIR)\JDFAutoTrapRegion.sbr" \
	"$(INTDIR)\JDFAutoTrimmingParams.sbr" \
	"$(INTDIR)\JDFAutoVerificationParams.sbr" \
	"$(INTDIR)\JDFAutoWireCombBindingParams.sbr" \
	"$(INTDIR)\JDFAutoWrappingParams.sbr" \
	"$(INTDIR)\JDFArgumentValue.sbr" \
	"$(INTDIR)\JDFAutoAdvancedParams.sbr" \
	"$(INTDIR)\JDFAutoApprovalPerson.sbr" \
	"$(INTDIR)\JDFAutoArgumentValue.sbr" \
	"$(INTDIR)\JDFAutoAssemblySection.sbr" \
	"$(INTDIR)\JDFAutoBand.sbr" \
	"$(INTDIR)\JDFAutoBasicPreflightTest.sbr" \
	"$(INTDIR)\JDFAutoBindingQualityParams.sbr" \
	"$(INTDIR)\JDFAutoBoxArgument.sbr" \
	"$(INTDIR)\JDFAutoBoxToBoxDifference.sbr" \
	"$(INTDIR)\JDFAutoBundleItem.sbr" \
	"$(INTDIR)\JDFAutoCCITTFaxParams.sbr" \
	"$(INTDIR)\JDFAutoCollatingItem.sbr" \
	"$(INTDIR)\JDFAutoColorantZoneDetails.sbr" \
	"$(INTDIR)\JDFAutoColorCorrectionOp.sbr" \
	"$(INTDIR)\JDFAutoColorSpaceSubstitute.sbr" \
	"$(INTDIR)\JDFAutoContainer.sbr" \
	"$(INTDIR)\JDFAutoContentObject.sbr" \
	"$(INTDIR)\JDFAutoCrease.sbr" \
	"$(INTDIR)\JDFAutoCut.sbr" \
	"$(INTDIR)\JDFAutoDCTParams.sbr" \
	"$(INTDIR)\JDFAutoDependencies.sbr" \
	"$(INTDIR)\JDFAutoDeviceNColor.sbr" \
	"$(INTDIR)\JDFAutoDrop.sbr" \
	"$(INTDIR)\JDFAutoDropItem.sbr" \
	"$(INTDIR)\JDFAutoDynamicField.sbr" \
	"$(INTDIR)\JDFAutoDynamicInput.sbr" \
	"$(INTDIR)\JDFAutoEmboss.sbr" \
	"$(INTDIR)\JDFAutoEndSheet.sbr" \
	"$(INTDIR)\JDFAutoFeeder.sbr" \
	"$(INTDIR)\JDFAutoFeederQualityParams.sbr" \
	"$(INTDIR)\JDFAutoFileAlias.sbr" \
	"$(INTDIR)\JDFAutoFlateParams.sbr" \
	"$(INTDIR)\JDFAutoGlue.sbr" \
	"$(INTDIR)\JDFAutoIcon.sbr" \
	"$(INTDIR)\JDFAutoIconList.sbr" \
	"$(INTDIR)\JDFAutoIDPCover.sbr" \
	"$(INTDIR)\JDFAutoIDPFinishing.sbr" \
	"$(INTDIR)\JDFAutoIDPFolding.sbr" \
	"$(INTDIR)\JDFAutoIDPHoleMaking.sbr" \
	"$(INTDIR)\JDFAutoIDPImageShift.sbr" \
	"$(INTDIR)\JDFAutoIDPJobSheet.sbr" \
	"$(INTDIR)\JDFAutoIDPLayout.sbr" \
	"$(INTDIR)\JDFAutoIDPStitching.sbr" \
	"$(INTDIR)\JDFAutoIDPTrimming.sbr" \
	"$(INTDIR)\JDFAutoImageCompression.sbr" \
	"$(INTDIR)\JDFAutoImageShift.sbr" \
	"$(INTDIR)\JDFAutoLayerDetails.sbr" \
	"$(INTDIR)\JDFAutoLayerList.sbr" \
	"$(INTDIR)\JDFAutoLongFold.sbr" \
	"$(INTDIR)\JDFAutoLongGlue.sbr" \
	"$(INTDIR)\JDFAutoLongPerforate.sbr" \
	"$(INTDIR)\JDFAutoLongSlit.sbr" \
	"$(INTDIR)\JDFAutoLZWParams.sbr" \
	"$(INTDIR)\JDFAutoMarkObject.sbr" \
	"$(INTDIR)\JDFAutoNumberingParam.sbr" \
	"$(INTDIR)\JDFAutoPageCell.sbr" \
	"$(INTDIR)\JDFAutoPageData.sbr" \
	"$(INTDIR)\JDFAutoPDFInterpretingParams.sbr" \
	"$(INTDIR)\JDFAutoPDFXParams.sbr" \
	"$(INTDIR)\JDFAutoPerforate.sbr" \
	"$(INTDIR)\JDFAutoPixelColorant.sbr" \
	"$(INTDIR)\JDFAutoPosition.sbr" \
	"$(INTDIR)\JDFAutoPreflightAction.sbr" \
	"$(INTDIR)\JDFAutoPreflightArgument.sbr" \
	"$(INTDIR)\JDFAutoPreflightConstraint.sbr" \
	"$(INTDIR)\JDFAutoPreflightDetail.sbr" \
	"$(INTDIR)\JDFAutoPreflightInstance.sbr" \
	"$(INTDIR)\JDFAutoPreflightInstanceDetail.sbr" \
	"$(INTDIR)\JDFAutoPreflightValue.sbr" \
	"$(INTDIR)\JDFAutoPRError.sbr" \
	"$(INTDIR)\JDFAutoPRGroup.sbr" \
	"$(INTDIR)\JDFAutoPrintConditionColor.sbr" \
	"$(INTDIR)\JDFAutoPRItem.sbr" \
	"$(INTDIR)\JDFAutoPROccurence.sbr" \
	"$(INTDIR)\JDFAutoProperties.sbr" \
	"$(INTDIR)\JDFAutoPRRule.sbr" \
	"$(INTDIR)\JDFAutoPRRuleAttr.sbr" \
	"$(INTDIR)\JDFAutoQualityMeasurement.sbr" \
	"$(INTDIR)\JDFAutoResourceParam.sbr" \
	"$(INTDIR)\JDFAutoScore.sbr" \
	"$(INTDIR)\JDFAutoScreenSelector.sbr" \
	"$(INTDIR)\JDFAutoShapeElement.sbr" \
	"$(INTDIR)\JDFAutoSignature.sbr" \
	"$(INTDIR)\JDFAutoSignatureCell.sbr" \
	"$(INTDIR)\JDFAutoStringListValue.sbr" \
	"$(INTDIR)\JDFAutoStripCellParams.sbr" \
	"$(INTDIR)\JDFAutoThinPDFParams.sbr" \
	"$(INTDIR)\JDFAutoTIFFEmbeddedFile.sbr" \
	"$(INTDIR)\JDFAutoTIFFFormatParams.sbr" \
	"$(INTDIR)\JDFAutoTIFFtag.sbr" \
	"$(INTDIR)\JDFAutoTransferCurveSet.sbr" \
	"$(INTDIR)\JDFAutoTrappingOrder.sbr" \
	"$(INTDIR)\JDFAutoAction.sbr" \
	"$(INTDIR)\JDFAutoActionPool.sbr" \
	"$(INTDIR)\JDFAutoand.sbr" \
	"$(INTDIR)\JDFAutocall.sbr" \
	"$(INTDIR)\JDFAutochoice.sbr" \
	"$(INTDIR)\JDFAutoDevCap.sbr" \
	"$(INTDIR)\JDFAutoDevCaps.sbr" \
	"$(INTDIR)\JDFAutoDeviceCap.sbr" \
	"$(INTDIR)\JDFAutoDisplayGroup.sbr" \
	"$(INTDIR)\JDFAutoDisplayGroupPool.sbr" \
	"$(INTDIR)\JDFAutoFeatureAttribute.sbr" \
	"$(INTDIR)\JDFAutoFeaturePool.sbr" \
	"$(INTDIR)\JDFAutoLoc.sbr" \
	"$(INTDIR)\JDFAutomacro.sbr" \
	"$(INTDIR)\JDFAutoMacroPool.sbr" \
	"$(INTDIR)\JDFAutonot.sbr" \
	"$(INTDIR)\JDFAutoor.sbr" \
	"$(INTDIR)\JDFAutootherwise.sbr" \
	"$(INTDIR)\JDFAutoPerformance.sbr" \
	"$(INTDIR)\JDFAutoset.sbr" \
	"$(INTDIR)\JDFAutoTest.sbr" \
	"$(INTDIR)\JDFAutoTestPool.sbr" \
	"$(INTDIR)\JDFAutoTestRef.sbr" \
	"$(INTDIR)\JDFAutoValue.sbr" \
	"$(INTDIR)\JDFAutoValueLoc.sbr" \
	"$(INTDIR)\JDFAutowhen.sbr" \
	"$(INTDIR)\JDFAutoxor.sbr" \
	"$(INTDIR)\JDFAutoEnumerationSpan.sbr" \
	"$(INTDIR)\JDFAutoPRGroupOccurence.sbr" \
	"$(INTDIR)\JDFAutoPRGroupOccurenceBase.sbr" \
	"$(INTDIR)\JDFPreflightConstraintsPool.sbr" \
	"$(INTDIR)\JDFPreflightResultsPool.sbr" \
	"$(INTDIR)\JDFPRGroupOccurence.sbr" \
	"$(INTDIR)\JDFPRGroupOccurenceBase.sbr" \
	"$(INTDIR)\JDFDateTimeRange.sbr" \
	"$(INTDIR)\JDFDateTimeRangeList.sbr" \
	"$(INTDIR)\JDFDurationRange.sbr" \
	"$(INTDIR)\JDFDurationRangeList.sbr" \
	"$(INTDIR)\JDFIntegerRange.sbr" \
	"$(INTDIR)\JDFIntegerRangeList.sbr" \
	"$(INTDIR)\JDFNameRangeList.sbr" \
	"$(INTDIR)\JDFNumberRangeList.sbr" \
	"$(INTDIR)\JDFNumTypeList.sbr" \
	"$(INTDIR)\JDFParser.sbr" \
	"$(INTDIR)\JDFRange.sbr" \
	"$(INTDIR)\JDFRangeList.sbr" \
	"$(INTDIR)\JDFXYPairRangeList.sbr" \
	"$(INTDIR)\KElement.sbr" \
	"$(INTDIR)\KElementStrings.sbr" \
	"$(INTDIR)\MyDate.sbr" \
	"$(INTDIR)\vElement.sbr" \
	"$(INTDIR)\XMLDoc.sbr" \
	"$(INTDIR)\XMLDocUserData.sbr"

"$(OUTDIR)\JDFWrapperLib.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=xilink6.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\JDFWrapperLib_D.lib" 
LIB32_OBJS= \
	"$(INTDIR)\JDFAmountPool.obj" \
	"$(INTDIR)\JDFAncestor.obj" \
	"$(INTDIR)\JDFAncestorPool.obj" \
	"$(INTDIR)\JDFAudit.obj" \
	"$(INTDIR)\JDFAuditPool.obj" \
	"$(INTDIR)\JDFBarcode.obj" \
	"$(INTDIR)\JDFBusinessInfo.obj" \
	"$(INTDIR)\JDFComment.obj" \
	"$(INTDIR)\JDFCounterReset.obj" \
	"$(INTDIR)\JDFCreated.obj" \
	"$(INTDIR)\JDFCustomerInfo.obj" \
	"$(INTDIR)\JDFCustomerMessage.obj" \
	"$(INTDIR)\JDFDeleted.obj" \
	"$(INTDIR)\JDFError.obj" \
	"$(INTDIR)\JDFEvent.obj" \
	"$(INTDIR)\JDFFCNKey.obj" \
	"$(INTDIR)\JDFLocation.obj" \
	"$(INTDIR)\JDFMerged.obj" \
	"$(INTDIR)\JDFModified.obj" \
	"$(INTDIR)\JDFModulePhase.obj" \
	"$(INTDIR)\JDFNode.obj" \
	"$(INTDIR)\JDFNodeInfo.obj" \
	"$(INTDIR)\JDFNotification.obj" \
	"$(INTDIR)\JDFPart.obj" \
	"$(INTDIR)\JDFPartAmount.obj" \
	"$(INTDIR)\JDFPartStatus.obj" \
	"$(INTDIR)\JDFPhaseTime.obj" \
	"$(INTDIR)\JDFProcessRun.obj" \
	"$(INTDIR)\JDFResourceAudit.obj" \
	"$(INTDIR)\JDFResourceLinkPool.obj" \
	"$(INTDIR)\JDFResourcePool.obj" \
	"$(INTDIR)\JDFSpawned.obj" \
	"$(INTDIR)\JDFStatusPool.obj" \
	"$(INTDIR)\JDFSystemTimeSet.obj" \
	"$(INTDIR)\JDFAcknowledge.obj" \
	"$(INTDIR)\JDFAdded.obj" \
	"$(INTDIR)\JDFChangedAttribute.obj" \
	"$(INTDIR)\JDFChangedPath.obj" \
	"$(INTDIR)\JDFCommand.obj" \
	"$(INTDIR)\JDFDeviceFilter.obj" \
	"$(INTDIR)\JDFDeviceInfo.obj" \
	"$(INTDIR)\JDFDeviceList.obj" \
	"$(INTDIR)\JDFEmployeeDef.obj" \
	"$(INTDIR)\JDFFlushedResources.obj" \
	"$(INTDIR)\JDFFlushQueueParams.obj" \
	"$(INTDIR)\JDFFlushResourceParams.obj" \
	"$(INTDIR)\JDFIDInfo.obj" \
	"$(INTDIR)\JDFJDFController.obj" \
	"$(INTDIR)\JDFJDFService.obj" \
	"$(INTDIR)\JDFJMF.obj" \
	"$(INTDIR)\JDFJobPhase.obj" \
	"$(INTDIR)\JDFKnownMsgQuParams.obj" \
	"$(INTDIR)\JDFMessage.obj" \
	"$(INTDIR)\JDFMessageElement.obj" \
	"$(INTDIR)\JDFMessageService.obj" \
	"$(INTDIR)\JDFModuleStatus.obj" \
	"$(INTDIR)\JDFMsgFilter.obj" \
	"$(INTDIR)\JDFNewJDFCmdParams.obj" \
	"$(INTDIR)\JDFNewJDFQuParams.obj" \
	"$(INTDIR)\JDFNodeInfoCmdParams.obj" \
	"$(INTDIR)\JDFNodeInfoQuParams.obj" \
	"$(INTDIR)\JDFNodeInfoResp.obj" \
	"$(INTDIR)\JDFNotificationDef.obj" \
	"$(INTDIR)\JDFNotificationFilter.obj" \
	"$(INTDIR)\JDFObservationTarget.obj" \
	"$(INTDIR)\JDFOccupation.obj" \
	"$(INTDIR)\JDFPipeParams.obj" \
	"$(INTDIR)\JDFQuery.obj" \
	"$(INTDIR)\JDFQueue.obj" \
	"$(INTDIR)\JDFQueueEntry.obj" \
	"$(INTDIR)\JDFQueueEntryDef.obj" \
	"$(INTDIR)\JDFQueueEntryDefList.obj" \
	"$(INTDIR)\JDFQueueEntryPosParams.obj" \
	"$(INTDIR)\JDFQueueEntryPriParams.obj" \
	"$(INTDIR)\JDFQueueFilter.obj" \
	"$(INTDIR)\JDFQueueSubmissionParams.obj" \
	"$(INTDIR)\JDFRemoved.obj" \
	"$(INTDIR)\JDFRequestQueueEntryParams.obj" \
	"$(INTDIR)\JDFResourceCmdParams.obj" \
	"$(INTDIR)\JDFResourceInfo.obj" \
	"$(INTDIR)\JDFResourcePullParams.obj" \
	"$(INTDIR)\JDFResourceQuParams.obj" \
	"$(INTDIR)\JDFResponse.obj" \
	"$(INTDIR)\JDFResubmissionParams.obj" \
	"$(INTDIR)\JDFReturnQueueEntryParams.obj" \
	"$(INTDIR)\JDFShutDownCmdParams.obj" \
	"$(INTDIR)\JDFSignal.obj" \
	"$(INTDIR)\JDFStatusQuParams.obj" \
	"$(INTDIR)\JDFStopPersChParams.obj" \
	"$(INTDIR)\JDFSubmissionMethods.obj" \
	"$(INTDIR)\JDFSubscription.obj" \
	"$(INTDIR)\JDFTrackFilter.obj" \
	"$(INTDIR)\JDFTrackResult.obj" \
	"$(INTDIR)\JDFTrigger.obj" \
	"$(INTDIR)\JDFWakeUpCmdParams.obj" \
	"$(INTDIR)\JDFArtDeliveryIntent.obj" \
	"$(INTDIR)\JDFBindingIntent.obj" \
	"$(INTDIR)\JDFColorIntent.obj" \
	"$(INTDIR)\JDFDeliveryIntent.obj" \
	"$(INTDIR)\JDFEmbossingIntent.obj" \
	"$(INTDIR)\JDFFoldingIntent.obj" \
	"$(INTDIR)\JDFHoleMakingIntent.obj" \
	"$(INTDIR)\JDFInsertingIntent.obj" \
	"$(INTDIR)\JDFIntentResource.obj" \
	"$(INTDIR)\JDFLaminatingIntent.obj" \
	"$(INTDIR)\JDFLayoutIntent.obj" \
	"$(INTDIR)\JDFMediaIntent.obj" \
	"$(INTDIR)\JDFNumberingIntent.obj" \
	"$(INTDIR)\JDFPackingIntent.obj" \
	"$(INTDIR)\JDFProductionIntent.obj" \
	"$(INTDIR)\JDFProofingIntent.obj" \
	"$(INTDIR)\JDFScreeningIntent.obj" \
	"$(INTDIR)\JDFShapeCuttingIntent.obj" \
	"$(INTDIR)\JDFSizeIntent.obj" \
	"$(INTDIR)\JDFSpan.obj" \
	"$(INTDIR)\JDFAdhesiveBinding.obj" \
	"$(INTDIR)\JDFArtDelivery.obj" \
	"$(INTDIR)\JDFBindItem.obj" \
	"$(INTDIR)\JDFBindList.obj" \
	"$(INTDIR)\JDFBookCase.obj" \
	"$(INTDIR)\JDFChannelBinding.obj" \
	"$(INTDIR)\JDFCoilBinding.obj" \
	"$(INTDIR)\JDFColorsUsed.obj" \
	"$(INTDIR)\JDFCreditCard.obj" \
	"$(INTDIR)\JDFDropIntent.obj" \
	"$(INTDIR)\JDFDropItemIntent.obj" \
	"$(INTDIR)\JDFEdgeGluing.obj" \
	"$(INTDIR)\JDFEmbossingItem.obj" \
	"$(INTDIR)\JDFHardCoverBinding.obj" \
	"$(INTDIR)\JDFHoleList.obj" \
	"$(INTDIR)\JDFInsert.obj" \
	"$(INTDIR)\JDFInsertList.obj" \
	"$(INTDIR)\JDFNumberItem.obj" \
	"$(INTDIR)\JDFPayment.obj" \
	"$(INTDIR)\JDFPlasticCombBinding.obj" \
	"$(INTDIR)\JDFPricing.obj" \
	"$(INTDIR)\JDFProofItem.obj" \
	"$(INTDIR)\JDFRingBinding.obj" \
	"$(INTDIR)\JDFSaddleStitching.obj" \
	"$(INTDIR)\JDFShapeCut.obj" \
	"$(INTDIR)\JDFSideSewing.obj" \
	"$(INTDIR)\JDFSideStitching.obj" \
	"$(INTDIR)\JDFSoftCoverBinding.obj" \
	"$(INTDIR)\JDFStripBinding.obj" \
	"$(INTDIR)\JDFTabs.obj" \
	"$(INTDIR)\JDFTape.obj" \
	"$(INTDIR)\JDFThreadSealing.obj" \
	"$(INTDIR)\JDFThreadSewing.obj" \
	"$(INTDIR)\JDFWireCombBinding.obj" \
	"$(INTDIR)\JDFAddress.obj" \
	"$(INTDIR)\JDFAdhesiveBindingParams.obj" \
	"$(INTDIR)\JDFApprovalParams.obj" \
	"$(INTDIR)\JDFApprovalSuccess.obj" \
	"$(INTDIR)\JDFAssembly.obj" \
	"$(INTDIR)\JDFAssetListCreationParams.obj" \
	"$(INTDIR)\JDFAutomatedOverprintParams.obj" \
	"$(INTDIR)\JDFBinderySignature.obj" \
	"$(INTDIR)\JDFBlockPreparationParams.obj" \
	"$(INTDIR)\JDFBoxPackingParams.obj" \
	"$(INTDIR)\JDFBufferParams.obj" \
	"$(INTDIR)\JDFBundle.obj" \
	"$(INTDIR)\JDFBundlingParams.obj" \
	"$(INTDIR)\JDFByteMap.obj" \
	"$(INTDIR)\JDFCaseMakingParams.obj" \
	"$(INTDIR)\JDFCasingInParams.obj" \
	"$(INTDIR)\JDFChannelBindingParams.obj" \
	"$(INTDIR)\JDFCIELABMeasuringField.obj" \
	"$(INTDIR)\JDFCoilBindingParams.obj" \
	"$(INTDIR)\JDFCollectingParams.obj" \
	"$(INTDIR)\JDFColor.obj" \
	"$(INTDIR)\JDFColorantAlias.obj" \
	"$(INTDIR)\JDFColorantControl.obj" \
	"$(INTDIR)\JDFColorControlStrip.obj" \
	"$(INTDIR)\JDFColorCorrectionParams.obj" \
	"$(INTDIR)\JDFColorMeasurementConditions.obj" \
	"$(INTDIR)\JDFColorPool.obj" \
	"$(INTDIR)\JDFColorSpaceConversionOp.obj" \
	"$(INTDIR)\JDFColorSpaceConversionParams.obj" \
	"$(INTDIR)\JDFComChannel.obj" \
	"$(INTDIR)\JDFCompany.obj" \
	"$(INTDIR)\JDFComponent.obj" \
	"$(INTDIR)\JDFContact.obj" \
	"$(INTDIR)\JDFContactCopyParams.obj" \
	"$(INTDIR)\JDFConventionalPrintingParams.obj" \
	"$(INTDIR)\JDFCostCenter.obj" \
	"$(INTDIR)\JDFCoverApplicationParams.obj" \
	"$(INTDIR)\JDFCreasingParams.obj" \
	"$(INTDIR)\JDFCutBlock.obj" \
	"$(INTDIR)\JDFCutMark.obj" \
	"$(INTDIR)\JDFCuttingParams.obj" \
	"$(INTDIR)\JDFDBMergeParams.obj" \
	"$(INTDIR)\JDFDBRules.obj" \
	"$(INTDIR)\JDFDBSchema.obj" \
	"$(INTDIR)\JDFDBSelection.obj" \
	"$(INTDIR)\JDFDeliveryParams.obj" \
	"$(INTDIR)\JDFDensityMeasuringField.obj" \
	"$(INTDIR)\JDFDevelopingParams.obj" \
	"$(INTDIR)\JDFDevice.obj" \
	"$(INTDIR)\JDFDeviceMark.obj" \
	"$(INTDIR)\JDFDeviceNSpace.obj" \
	"$(INTDIR)\JDFDigitalDeliveryParams.obj" \
	"$(INTDIR)\JDFDigitalMedia.obj" \
	"$(INTDIR)\JDFDigitalPrintingParams.obj" \
	"$(INTDIR)\JDFDisjointing.obj" \
	"$(INTDIR)\JDFDisposition.obj" \
	"$(INTDIR)\JDFDividingParams.obj" \
	"$(INTDIR)\JDFElementColorParams.obj" \
	"$(INTDIR)\JDFEmbossingParams.obj" \
	"$(INTDIR)\JDFEmployee.obj" \
	"$(INTDIR)\JDFEndSheetGluingParams.obj" \
	"$(INTDIR)\JDFExposedMedia.obj" \
	"$(INTDIR)\JDFFeedingParams.obj" \
	"$(INTDIR)\JDFFileSpec.obj" \
	"$(INTDIR)\JDFFitPolicy.obj" \
	"$(INTDIR)\JDFFold.obj" \
	"$(INTDIR)\JDFFoldingParams.obj" \
	"$(INTDIR)\JDFFontParams.obj" \
	"$(INTDIR)\JDFFontPolicy.obj" \
	"$(INTDIR)\JDFFormatConversionParams.obj" \
	"$(INTDIR)\JDFGatheringParams.obj" \
	"$(INTDIR)\JDFGlueApplication.obj" \
	"$(INTDIR)\JDFGlueLine.obj" \
	"$(INTDIR)\JDFGluingParams.obj" \
	"$(INTDIR)\JDFHeadBandApplicationParams.obj" \
	"$(INTDIR)\JDFHole.obj" \
	"$(INTDIR)\JDFHoleLine.obj" \
	"$(INTDIR)\JDFHoleMakingParams.obj" \
	"$(INTDIR)\JDFIdentificationField.obj" \
	"$(INTDIR)\JDFIDPrintingParams.obj" \
	"$(INTDIR)\JDFImageCompressionParams.obj" \
	"$(INTDIR)\JDFImageReplacementParams.obj" \
	"$(INTDIR)\JDFImageSetterParams.obj" \
	"$(INTDIR)\JDFInk.obj" \
	"$(INTDIR)\JDFInkZoneCalculationParams.obj" \
	"$(INTDIR)\JDFInkZoneProfile.obj" \
	"$(INTDIR)\JDFInsertingParams.obj" \
	"$(INTDIR)\JDFInsertSheet.obj" \
	"$(INTDIR)\JDFInterpretedPDLData.obj" \
	"$(INTDIR)\JDFInterpretingParams.obj" \
	"$(INTDIR)\JDFJacketingParams.obj" \
	"$(INTDIR)\JDFJobField.obj" \
	"$(INTDIR)\JDFLabelingParams.obj" \
	"$(INTDIR)\JDFLaminatingParams.obj" \
	"$(INTDIR)\JDFLayout.obj" \
	"$(INTDIR)\JDFLayoutElement.obj" \
	"$(INTDIR)\JDFLayoutPreparationParams.obj" \
	"$(INTDIR)\JDFLongitudinalRibbonOperationParams.obj" \
	"$(INTDIR)\JDFManualLaborParams.obj" \
	"$(INTDIR)\JDFMedia.obj" \
	"$(INTDIR)\JDFMediaSource.obj" \
	"$(INTDIR)\JDFMISDetails.obj" \
	"$(INTDIR)\JDFNumberingParams.obj" \
	"$(INTDIR)\JDFObjectResolution.obj" \
	"$(INTDIR)\JDFOrderingParams.obj" \
	"$(INTDIR)\JDFPackingParams.obj" \
	"$(INTDIR)\JDFPageList.obj" \
	"$(INTDIR)\JDFPallet.obj" \
	"$(INTDIR)\JDFPalletizingParams.obj" \
	"$(INTDIR)\JDFPDFToPSConversionParams.obj" \
	"$(INTDIR)\JDFPDLResourceAlias.obj" \
	"$(INTDIR)\JDFPerforatingParams.obj" \
	"$(INTDIR)\JDFPerson.obj" \
	"$(INTDIR)\JDFPlaceHolderResource.obj" \
	"$(INTDIR)\JDFPlasticCombBindingParams.obj" \
	"$(INTDIR)\JDFPlateCopyParams.obj" \
	"$(INTDIR)\JDFPreflightAnalysis.obj" \
	"$(INTDIR)\JDFPreflightInventory.obj" \
	"$(INTDIR)\JDFPreflightParams.obj" \
	"$(INTDIR)\JDFPreflightProfile.obj" \
	"$(INTDIR)\JDFPreflightReport.obj" \
	"$(INTDIR)\JDFPreflightReportRulePool.obj" \
	"$(INTDIR)\JDFPreview.obj" \
	"$(INTDIR)\JDFPreviewGenerationParams.obj" \
	"$(INTDIR)\JDFPrintCondition.obj" \
	"$(INTDIR)\JDFPrintRollingParams.obj" \
	"$(INTDIR)\JDFProofingParams.obj" \
	"$(INTDIR)\JDFPSToPDFConversionParams.obj" \
	"$(INTDIR)\JDFQualityControlParams.obj" \
	"$(INTDIR)\JDFQualityControlResult.obj" \
	"$(INTDIR)\JDFRegisterMark.obj" \
	"$(INTDIR)\JDFRegisterRibbon.obj" \
	"$(INTDIR)\JDFRenderingParams.obj" \
	"$(INTDIR)\JDFResourceDefinitionParams.obj" \
	"$(INTDIR)\JDFRingBindingParams.obj" \
	"$(INTDIR)\JDFRollStand.obj" \
	"$(INTDIR)\JDFRunList.obj" \
	"$(INTDIR)\JDFSaddleStitchingParams.obj" \
	"$(INTDIR)\JDFScanParams.obj" \
	"$(INTDIR)\JDFScavengerArea.obj" \
	"$(INTDIR)\JDFScreeningParams.obj" \
	"$(INTDIR)\JDFSeparationControlParams.obj" \
	"$(INTDIR)\JDFSeparationSpec.obj" \
	"$(INTDIR)\JDFShapeCuttingParams.obj" \
	"$(INTDIR)\JDFSheet.obj" \
	"$(INTDIR)\JDFShrinkingParams.obj" \
	"$(INTDIR)\JDFSideSewingParams.obj" \
	"$(INTDIR)\JDFSpinePreparationParams.obj" \
	"$(INTDIR)\JDFSpineTapingParams.obj" \
	"$(INTDIR)\JDFStackingParams.obj" \
	"$(INTDIR)\JDFStitchingParams.obj" \
	"$(INTDIR)\JDFStrap.obj" \
	"$(INTDIR)\JDFStrappingParams.obj" \
	"$(INTDIR)\JDFStripBindingParams.obj" \
	"$(INTDIR)\JDFStrippingParams.obj" \
	"$(INTDIR)\JDFSurface.obj" \
	"$(INTDIR)\JDFThreadSealingParams.obj" \
	"$(INTDIR)\JDFThreadSewingParams.obj" \
	"$(INTDIR)\JDFTile.obj" \
	"$(INTDIR)\JDFTool.obj" \
	"$(INTDIR)\JDFTransferCurve.obj" \
	"$(INTDIR)\JDFTransferCurvePool.obj" \
	"$(INTDIR)\JDFTransferFunctionControl.obj" \
	"$(INTDIR)\JDFTrappingDetails.obj" \
	"$(INTDIR)\JDFTrappingParams.obj" \
	"$(INTDIR)\JDFTrapRegion.obj" \
	"$(INTDIR)\JDFTrimmingParams.obj" \
	"$(INTDIR)\JDFVerificationParams.obj" \
	"$(INTDIR)\JDFWireCombBindingParams.obj" \
	"$(INTDIR)\JDFWrappingParams.obj" \
	"$(INTDIR)\JDFAdvancedParams.obj" \
	"$(INTDIR)\JDFApprovalPerson.obj" \
	"$(INTDIR)\JDFAssemblySection.obj" \
	"$(INTDIR)\JDFBand.obj" \
	"$(INTDIR)\JDFBasicPreflightTest.obj" \
	"$(INTDIR)\JDFBindingQualityParams.obj" \
	"$(INTDIR)\JDFBoxArgument.obj" \
	"$(INTDIR)\JDFBoxToBoxDifference.obj" \
	"$(INTDIR)\JDFBundleItem.obj" \
	"$(INTDIR)\JDFCCITTFaxParams.obj" \
	"$(INTDIR)\JDFCollatingItem.obj" \
	"$(INTDIR)\JDFColorantZoneDetails.obj" \
	"$(INTDIR)\JDFColorCorrectionOp.obj" \
	"$(INTDIR)\JDFColorSpaceSubstitute.obj" \
	"$(INTDIR)\JDFContainer.obj" \
	"$(INTDIR)\JDFContentObject.obj" \
	"$(INTDIR)\JDFCrease.obj" \
	"$(INTDIR)\JDFCut.obj" \
	"$(INTDIR)\JDFDCTParams.obj" \
	"$(INTDIR)\JDFDependencies.obj" \
	"$(INTDIR)\JDFDeviceNColor.obj" \
	"$(INTDIR)\JDFDrop.obj" \
	"$(INTDIR)\JDFDropItem.obj" \
	"$(INTDIR)\JDFDynamicField.obj" \
	"$(INTDIR)\JDFDynamicInput.obj" \
	"$(INTDIR)\JDFEmboss.obj" \
	"$(INTDIR)\JDFEndSheet.obj" \
	"$(INTDIR)\JDFFeeder.obj" \
	"$(INTDIR)\JDFFeederQualityParams.obj" \
	"$(INTDIR)\JDFFileAlias.obj" \
	"$(INTDIR)\JDFFlateParams.obj" \
	"$(INTDIR)\JDFGlue.obj" \
	"$(INTDIR)\JDFIcon.obj" \
	"$(INTDIR)\JDFIconList.obj" \
	"$(INTDIR)\JDFIDPCover.obj" \
	"$(INTDIR)\JDFIDPFinishing.obj" \
	"$(INTDIR)\JDFIDPFolding.obj" \
	"$(INTDIR)\JDFIDPHoleMaking.obj" \
	"$(INTDIR)\JDFIDPImageShift.obj" \
	"$(INTDIR)\JDFIDPJobSheet.obj" \
	"$(INTDIR)\JDFIDPLayout.obj" \
	"$(INTDIR)\JDFIDPStitching.obj" \
	"$(INTDIR)\JDFIDPTrimming.obj" \
	"$(INTDIR)\JDFImageCompression.obj" \
	"$(INTDIR)\JDFImageShift.obj" \
	"$(INTDIR)\JDFLayerDetails.obj" \
	"$(INTDIR)\JDFLayerList.obj" \
	"$(INTDIR)\JDFLongFold.obj" \
	"$(INTDIR)\JDFLongGlue.obj" \
	"$(INTDIR)\JDFLongPerforate.obj" \
	"$(INTDIR)\JDFLongSlit.obj" \
	"$(INTDIR)\JDFLZWParams.obj" \
	"$(INTDIR)\JDFMarkObject.obj" \
	"$(INTDIR)\JDFNumberingParam.obj" \
	"$(INTDIR)\JDFPageCell.obj" \
	"$(INTDIR)\JDFPageData.obj" \
	"$(INTDIR)\JDFPDFInterpretingParams.obj" \
	"$(INTDIR)\JDFPDFXParams.obj" \
	"$(INTDIR)\JDFPerforate.obj" \
	"$(INTDIR)\JDFPixelColorant.obj" \
	"$(INTDIR)\JDFPosition.obj" \
	"$(INTDIR)\JDFPreflightAction.obj" \
	"$(INTDIR)\JDFPreflightArgument.obj" \
	"$(INTDIR)\JDFPreflightConstraint.obj" \
	"$(INTDIR)\JDFPreflightDetail.obj" \
	"$(INTDIR)\JDFPreflightInstance.obj" \
	"$(INTDIR)\JDFPreflightInstanceDetail.obj" \
	"$(INTDIR)\JDFPreflightValue.obj" \
	"$(INTDIR)\JDFPRError.obj" \
	"$(INTDIR)\JDFPRGroup.obj" \
	"$(INTDIR)\JDFPrintConditionColor.obj" \
	"$(INTDIR)\JDFPRItem.obj" \
	"$(INTDIR)\JDFPROccurence.obj" \
	"$(INTDIR)\JDFProperties.obj" \
	"$(INTDIR)\JDFPRRule.obj" \
	"$(INTDIR)\JDFPRRuleAttr.obj" \
	"$(INTDIR)\JDFQualityMeasurement.obj" \
	"$(INTDIR)\JDFResourceParam.obj" \
	"$(INTDIR)\JDFScore.obj" \
	"$(INTDIR)\JDFScreenSelector.obj" \
	"$(INTDIR)\JDFShapeElement.obj" \
	"$(INTDIR)\JDFSignature.obj" \
	"$(INTDIR)\JDFSignatureCell.obj" \
	"$(INTDIR)\JDFStringListValue.obj" \
	"$(INTDIR)\JDFStripCellParams.obj" \
	"$(INTDIR)\JDFThinPDFParams.obj" \
	"$(INTDIR)\JDFTIFFEmbeddedFile.obj" \
	"$(INTDIR)\JDFTIFFFormatParams.obj" \
	"$(INTDIR)\JDFTIFFtag.obj" \
	"$(INTDIR)\JDFTransferCurveSet.obj" \
	"$(INTDIR)\JDFTrappingOrder.obj" \
	"$(INTDIR)\JDFAction.obj" \
	"$(INTDIR)\JDFActionPool.obj" \
	"$(INTDIR)\JDFand.obj" \
	"$(INTDIR)\JDFBooleanEvaluation.obj" \
	"$(INTDIR)\JDFBooleanState.obj" \
	"$(INTDIR)\JDFcall.obj" \
	"$(INTDIR)\JDFchoice.obj" \
	"$(INTDIR)\JDFDateTimeEvaluation.obj" \
	"$(INTDIR)\JDFDateTimeState.obj" \
	"$(INTDIR)\JDFDevCap.obj" \
	"$(INTDIR)\JDFDevCaps.obj" \
	"$(INTDIR)\JDFDeviceCap.obj" \
	"$(INTDIR)\JDFDisplayGroup.obj" \
	"$(INTDIR)\JDFDisplayGroupPool.obj" \
	"$(INTDIR)\JDFDurationEvaluation.obj" \
	"$(INTDIR)\JDFDurationState.obj" \
	"$(INTDIR)\JDFEnumerationEvaluation.obj" \
	"$(INTDIR)\JDFEnumerationState.obj" \
	"$(INTDIR)\JDFEvaluation.obj" \
	"$(INTDIR)\JDFFeatureAttribute.obj" \
	"$(INTDIR)\JDFFeaturePool.obj" \
	"$(INTDIR)\JDFIntegerEvaluation.obj" \
	"$(INTDIR)\JDFIntegerState.obj" \
	"$(INTDIR)\JDFIsPresentEvaluation.obj" \
	"$(INTDIR)\JDFLoc.obj" \
	"$(INTDIR)\JDFmacro.obj" \
	"$(INTDIR)\JDFMacroPool.obj" \
	"$(INTDIR)\JDFMatrixEvaluation.obj" \
	"$(INTDIR)\JDFMatrixState.obj" \
	"$(INTDIR)\JDFNameEvaluation.obj" \
	"$(INTDIR)\JDFNameState.obj" \
	"$(INTDIR)\JDFnot.obj" \
	"$(INTDIR)\JDFNumberEvaluation.obj" \
	"$(INTDIR)\JDFNumberState.obj" \
	"$(INTDIR)\JDFor.obj" \
	"$(INTDIR)\JDFotherwise.obj" \
	"$(INTDIR)\JDFPDFPathEvaluation.obj" \
	"$(INTDIR)\JDFPDFPathState.obj" \
	"$(INTDIR)\JDFPerformance.obj" \
	"$(INTDIR)\JDFRectangleEvaluation.obj" \
	"$(INTDIR)\JDFRectangleState.obj" \
	"$(INTDIR)\JDFset.obj" \
	"$(INTDIR)\JDFShapeEvaluation.obj" \
	"$(INTDIR)\JDFShapeState.obj" \
	"$(INTDIR)\JDFState.obj" \
	"$(INTDIR)\JDFStringEvaluation.obj" \
	"$(INTDIR)\JDFStringState.obj" \
	"$(INTDIR)\JDFTest.obj" \
	"$(INTDIR)\JDFTestPool.obj" \
	"$(INTDIR)\JDFTestRef.obj" \
	"$(INTDIR)\JDFValue.obj" \
	"$(INTDIR)\JDFValueLoc.obj" \
	"$(INTDIR)\JDFwhen.obj" \
	"$(INTDIR)\JDFxor.obj" \
	"$(INTDIR)\JDFXYPairEvaluation.obj" \
	"$(INTDIR)\JDFXYPairState.obj" \
	"$(INTDIR)\JDFDoc.obj" \
	"$(INTDIR)\JDFElement.obj" \
	"$(INTDIR)\JDFFactory.obj" \
	"$(INTDIR)\JDFNodeFactory.obj" \
	"$(INTDIR)\JDFParamsFactory.obj" \
	"$(INTDIR)\JDFPool.obj" \
	"$(INTDIR)\JDFRefElement.obj" \
	"$(INTDIR)\JDFResource.obj" \
	"$(INTDIR)\JDFResourceLink.obj" \
	"$(INTDIR)\JDFRunElement.obj" \
	"$(INTDIR)\JDFSeparationList.obj" \
	"$(INTDIR)\JDFStrings.obj" \
	"$(INTDIR)\JDFAutoAmountPool.obj" \
	"$(INTDIR)\JDFAutoAncestor.obj" \
	"$(INTDIR)\JDFAutoAncestorPool.obj" \
	"$(INTDIR)\JDFAutoBarcode.obj" \
	"$(INTDIR)\JDFAutoBusinessInfo.obj" \
	"$(INTDIR)\JDFAutoComment.obj" \
	"$(INTDIR)\JDFAutoCounterReset.obj" \
	"$(INTDIR)\JDFAutoCreated.obj" \
	"$(INTDIR)\JDFAutoCustomerInfo.obj" \
	"$(INTDIR)\JDFAutoCustomerMessage.obj" \
	"$(INTDIR)\JDFAutoDeleted.obj" \
	"$(INTDIR)\JDFAutoError.obj" \
	"$(INTDIR)\JDFAutoEvent.obj" \
	"$(INTDIR)\JDFAutoFCNKey.obj" \
	"$(INTDIR)\JDFAutoLocation.obj" \
	"$(INTDIR)\JDFAutoMerged.obj" \
	"$(INTDIR)\JDFAutoModified.obj" \
	"$(INTDIR)\JDFAutoModulePhase.obj" \
	"$(INTDIR)\JDFAutoNodeInfo.obj" \
	"$(INTDIR)\JDFAutoNotification.obj" \
	"$(INTDIR)\JDFAutoPart.obj" \
	"$(INTDIR)\JDFAutoPartStatus.obj" \
	"$(INTDIR)\JDFAutoPhaseTime.obj" \
	"$(INTDIR)\JDFAutoProcessRun.obj" \
	"$(INTDIR)\JDFAutoResourceAudit.obj" \
	"$(INTDIR)\JDFAutoSpawned.obj" \
	"$(INTDIR)\JDFAutoStatusPool.obj" \
	"$(INTDIR)\JDFAutoSystemTimeSet.obj" \
	"$(INTDIR)\JDFAutoAcknowledge.obj" \
	"$(INTDIR)\JDFAutoAdded.obj" \
	"$(INTDIR)\JDFAutoChangedAttribute.obj" \
	"$(INTDIR)\JDFAutoChangedPath.obj" \
	"$(INTDIR)\JDFAutoCommand.obj" \
	"$(INTDIR)\JDFAutoDeviceFilter.obj" \
	"$(INTDIR)\JDFAutoDeviceInfo.obj" \
	"$(INTDIR)\JDFAutoDeviceList.obj" \
	"$(INTDIR)\JDFAutoEmployeeDef.obj" \
	"$(INTDIR)\JDFAutoFlushedResources.obj" \
	"$(INTDIR)\JDFAutoFlushQueueParams.obj" \
	"$(INTDIR)\JDFAutoFlushResourceParams.obj" \
	"$(INTDIR)\JDFAutoIDInfo.obj" \
	"$(INTDIR)\JDFAutoJDFController.obj" \
	"$(INTDIR)\JDFAutoJDFService.obj" \
	"$(INTDIR)\JDFAutoJMF.obj" \
	"$(INTDIR)\JDFAutoJobPhase.obj" \
	"$(INTDIR)\JDFAutoKnownMsgQuParams.obj" \
	"$(INTDIR)\JDFAutoMessage.obj" \
	"$(INTDIR)\JDFAutoMessageService.obj" \
	"$(INTDIR)\JDFAutoModuleStatus.obj" \
	"$(INTDIR)\JDFAutoMsgFilter.obj" \
	"$(INTDIR)\JDFAutoNewJDFCmdParams.obj" \
	"$(INTDIR)\JDFAutoNewJDFQuParams.obj" \
	"$(INTDIR)\JDFAutoNodeInfoCmdParams.obj" \
	"$(INTDIR)\JDFAutoNodeInfoQuParams.obj" \
	"$(INTDIR)\JDFAutoNodeInfoResp.obj" \
	"$(INTDIR)\JDFAutoNotificationDef.obj" \
	"$(INTDIR)\JDFAutoNotificationFilter.obj" \
	"$(INTDIR)\JDFAutoObservationTarget.obj" \
	"$(INTDIR)\JDFAutoOccupation.obj" \
	"$(INTDIR)\JDFAutoPipeParams.obj" \
	"$(INTDIR)\JDFAutoQuery.obj" \
	"$(INTDIR)\JDFAutoQueue.obj" \
	"$(INTDIR)\JDFAutoQueueEntry.obj" \
	"$(INTDIR)\JDFAutoQueueEntryDef.obj" \
	"$(INTDIR)\JDFAutoQueueEntryDefList.obj" \
	"$(INTDIR)\JDFAutoQueueEntryPosParams.obj" \
	"$(INTDIR)\JDFAutoQueueEntryPriParams.obj" \
	"$(INTDIR)\JDFAutoQueueFilter.obj" \
	"$(INTDIR)\JDFAutoQueueSubmissionParams.obj" \
	"$(INTDIR)\JDFAutoRemoved.obj" \
	"$(INTDIR)\JDFAutoRequestQueueEntryParams.obj" \
	"$(INTDIR)\JDFAutoResourceCmdParams.obj" \
	"$(INTDIR)\JDFAutoResourceInfo.obj" \
	"$(INTDIR)\JDFAutoResourcePullParams.obj" \
	"$(INTDIR)\JDFAutoResourceQuParams.obj" \
	"$(INTDIR)\JDFAutoResponse.obj" \
	"$(INTDIR)\JDFAutoResubmissionParams.obj" \
	"$(INTDIR)\JDFAutoReturnQueueEntryParams.obj" \
	"$(INTDIR)\JDFAutoShutDownCmdParams.obj" \
	"$(INTDIR)\JDFAutoSignal.obj" \
	"$(INTDIR)\JDFAutoStatusQuParams.obj" \
	"$(INTDIR)\JDFAutoStopPersChParams.obj" \
	"$(INTDIR)\JDFAutoSubmissionMethods.obj" \
	"$(INTDIR)\JDFAutoSubscription.obj" \
	"$(INTDIR)\JDFAutoTrackFilter.obj" \
	"$(INTDIR)\JDFAutoTrackResult.obj" \
	"$(INTDIR)\JDFAutoTrigger.obj" \
	"$(INTDIR)\JDFAutoWakeUpCmdParams.obj" \
	"$(INTDIR)\JDFAutoArtDeliveryIntent.obj" \
	"$(INTDIR)\JDFAutoBindingIntent.obj" \
	"$(INTDIR)\JDFAutoColorIntent.obj" \
	"$(INTDIR)\JDFAutoDeliveryIntent.obj" \
	"$(INTDIR)\JDFAutoEmbossingIntent.obj" \
	"$(INTDIR)\JDFAutoFoldingIntent.obj" \
	"$(INTDIR)\JDFAutoHoleMakingIntent.obj" \
	"$(INTDIR)\JDFAutoInsertingIntent.obj" \
	"$(INTDIR)\JDFAutoLaminatingIntent.obj" \
	"$(INTDIR)\JDFAutoLayoutIntent.obj" \
	"$(INTDIR)\JDFAutoMediaIntent.obj" \
	"$(INTDIR)\JDFAutoNumberingIntent.obj" \
	"$(INTDIR)\JDFAutoPackingIntent.obj" \
	"$(INTDIR)\JDFAutoProductionIntent.obj" \
	"$(INTDIR)\JDFAutoProofingIntent.obj" \
	"$(INTDIR)\JDFAutoScreeningIntent.obj" \
	"$(INTDIR)\JDFAutoShapeCuttingIntent.obj" \
	"$(INTDIR)\JDFAutoSizeIntent.obj" \
	"$(INTDIR)\JDFAutoAdhesiveBinding.obj" \
	"$(INTDIR)\JDFAutoArtDelivery.obj" \
	"$(INTDIR)\JDFAutoBindItem.obj" \
	"$(INTDIR)\JDFAutoBindList.obj" \
	"$(INTDIR)\JDFAutoBookCase.obj" \
	"$(INTDIR)\JDFAutoChannelBinding.obj" \
	"$(INTDIR)\JDFAutoCoilBinding.obj" \
	"$(INTDIR)\JDFAutoColorsUsed.obj" \
	"$(INTDIR)\JDFAutoCreditCard.obj" \
	"$(INTDIR)\JDFAutoDropIntent.obj" \
	"$(INTDIR)\JDFAutoDropItemIntent.obj" \
	"$(INTDIR)\JDFAutoEdgeGluing.obj" \
	"$(INTDIR)\JDFAutoEmbossingItem.obj" \
	"$(INTDIR)\JDFAutoHardCoverBinding.obj" \
	"$(INTDIR)\JDFAutoHoleList.obj" \
	"$(INTDIR)\JDFAutoInsert.obj" \
	"$(INTDIR)\JDFAutoInsertList.obj" \
	"$(INTDIR)\JDFAutoNumberItem.obj" \
	"$(INTDIR)\JDFAutoPayment.obj" \
	"$(INTDIR)\JDFAutoPlasticCombBinding.obj" \
	"$(INTDIR)\JDFAutoPricing.obj" \
	"$(INTDIR)\JDFAutoProofItem.obj" \
	"$(INTDIR)\JDFAutoRingBinding.obj" \
	"$(INTDIR)\JDFAutoSaddleStitching.obj" \
	"$(INTDIR)\JDFAutoShapeCut.obj" \
	"$(INTDIR)\JDFAutoSideSewing.obj" \
	"$(INTDIR)\JDFAutoSideStitching.obj" \
	"$(INTDIR)\JDFAutoSoftCoverBinding.obj" \
	"$(INTDIR)\JDFAutoStripBinding.obj" \
	"$(INTDIR)\JDFAutoTabs.obj" \
	"$(INTDIR)\JDFAutoTape.obj" \
	"$(INTDIR)\JDFAutoThreadSealing.obj" \
	"$(INTDIR)\JDFAutoThreadSewing.obj" \
	"$(INTDIR)\JDFAutoWireCombBinding.obj" \
	"$(INTDIR)\JDFAutoAddress.obj" \
	"$(INTDIR)\JDFAutoAdhesiveBindingParams.obj" \
	"$(INTDIR)\JDFAutoApprovalParams.obj" \
	"$(INTDIR)\JDFAutoApprovalSuccess.obj" \
	"$(INTDIR)\JDFAutoAssembly.obj" \
	"$(INTDIR)\JDFAutoAssetListCreationParams.obj" \
	"$(INTDIR)\JDFAutoAutomatedOverprintParams.obj" \
	"$(INTDIR)\JDFAutoBinderySignature.obj" \
	"$(INTDIR)\JDFAutoBlockPreparationParams.obj" \
	"$(INTDIR)\JDFAutoBoxPackingParams.obj" \
	"$(INTDIR)\JDFAutoBufferParams.obj" \
	"$(INTDIR)\JDFAutoBundle.obj" \
	"$(INTDIR)\JDFAutoBundlingParams.obj" \
	"$(INTDIR)\JDFAutoByteMap.obj" \
	"$(INTDIR)\JDFAutoCaseMakingParams.obj" \
	"$(INTDIR)\JDFAutoCasingInParams.obj" \
	"$(INTDIR)\JDFAutoChannelBindingParams.obj" \
	"$(INTDIR)\JDFAutoCIELABMeasuringField.obj" \
	"$(INTDIR)\JDFAutoCoilBindingParams.obj" \
	"$(INTDIR)\JDFAutoCollectingParams.obj" \
	"$(INTDIR)\JDFAutoColor.obj" \
	"$(INTDIR)\JDFAutoColorantAlias.obj" \
	"$(INTDIR)\JDFAutoColorantControl.obj" \
	"$(INTDIR)\JDFAutoColorControlStrip.obj" \
	"$(INTDIR)\JDFAutoColorCorrectionParams.obj" \
	"$(INTDIR)\JDFAutoColorMeasurementConditions.obj" \
	"$(INTDIR)\JDFAutoColorPool.obj" \
	"$(INTDIR)\JDFAutoColorSpaceConversionOp.obj" \
	"$(INTDIR)\JDFAutoColorSpaceConversionParams.obj" \
	"$(INTDIR)\JDFAutoComChannel.obj" \
	"$(INTDIR)\JDFAutoCompany.obj" \
	"$(INTDIR)\JDFAutoComponent.obj" \
	"$(INTDIR)\JDFAutoContact.obj" \
	"$(INTDIR)\JDFAutoContactCopyParams.obj" \
	"$(INTDIR)\JDFAutoConventionalPrintingParams.obj" \
	"$(INTDIR)\JDFAutoCostCenter.obj" \
	"$(INTDIR)\JDFAutoCoverApplicationParams.obj" \
	"$(INTDIR)\JDFAutoCreasingParams.obj" \
	"$(INTDIR)\JDFAutoCutBlock.obj" \
	"$(INTDIR)\JDFAutoCutMark.obj" \
	"$(INTDIR)\JDFAutoCuttingParams.obj" \
	"$(INTDIR)\JDFAutoDBMergeParams.obj" \
	"$(INTDIR)\JDFAutoDBRules.obj" \
	"$(INTDIR)\JDFAutoDBSchema.obj" \
	"$(INTDIR)\JDFAutoDBSelection.obj" \
	"$(INTDIR)\JDFAutoDeliveryParams.obj" \
	"$(INTDIR)\JDFAutoDensityMeasuringField.obj" \
	"$(INTDIR)\JDFAutoDevelopingParams.obj" \
	"$(INTDIR)\JDFAutoDevice.obj" \
	"$(INTDIR)\JDFAutoDeviceMark.obj" \
	"$(INTDIR)\JDFAutoDeviceNSpace.obj" \
	"$(INTDIR)\JDFAutoDigitalDeliveryParams.obj" \
	"$(INTDIR)\JDFAutoDigitalMedia.obj" \
	"$(INTDIR)\JDFAutoDigitalPrintingParams.obj" \
	"$(INTDIR)\JDFAutoDisjointing.obj" \
	"$(INTDIR)\JDFAutoDisposition.obj" \
	"$(INTDIR)\JDFAutoDividingParams.obj" \
	"$(INTDIR)\JDFAutoElementColorParams.obj" \
	"$(INTDIR)\JDFAutoEmbossingParams.obj" \
	"$(INTDIR)\JDFAutoEmployee.obj" \
	"$(INTDIR)\JDFAutoEndSheetGluingParams.obj" \
	"$(INTDIR)\JDFAutoExposedMedia.obj" \
	"$(INTDIR)\JDFAutoFeedingParams.obj" \
	"$(INTDIR)\JDFAutoFileSpec.obj" \
	"$(INTDIR)\JDFAutoFitPolicy.obj" \
	"$(INTDIR)\JDFAutoFold.obj" \
	"$(INTDIR)\JDFAutoFoldingParams.obj" \
	"$(INTDIR)\JDFAutoFontParams.obj" \
	"$(INTDIR)\JDFAutoFontPolicy.obj" \
	"$(INTDIR)\JDFAutoFormatConversionParams.obj" \
	"$(INTDIR)\JDFAutoGatheringParams.obj" \
	"$(INTDIR)\JDFAutoGlueApplication.obj" \
	"$(INTDIR)\JDFAutoGlueLine.obj" \
	"$(INTDIR)\JDFAutoGluingParams.obj" \
	"$(INTDIR)\JDFAutoHeadBandApplicationParams.obj" \
	"$(INTDIR)\JDFAutoHole.obj" \
	"$(INTDIR)\JDFAutoHoleLine.obj" \
	"$(INTDIR)\JDFAutoHoleMakingParams.obj" \
	"$(INTDIR)\JDFAutoIdentificationField.obj" \
	"$(INTDIR)\JDFAutoIDPrintingParams.obj" \
	"$(INTDIR)\JDFAutoImageCompressionParams.obj" \
	"$(INTDIR)\JDFAutoImageReplacementParams.obj" \
	"$(INTDIR)\JDFAutoImageSetterParams.obj" \
	"$(INTDIR)\JDFAutoInk.obj" \
	"$(INTDIR)\JDFAutoInkZoneCalculationParams.obj" \
	"$(INTDIR)\JDFAutoInkZoneProfile.obj" \
	"$(INTDIR)\JDFAutoInsertingParams.obj" \
	"$(INTDIR)\JDFAutoInsertSheet.obj" \
	"$(INTDIR)\JDFAutoInterpretedPDLData.obj" \
	"$(INTDIR)\JDFAutoInterpretingParams.obj" \
	"$(INTDIR)\JDFAutoJacketingParams.obj" \
	"$(INTDIR)\JDFAutoJobField.obj" \
	"$(INTDIR)\JDFAutoLabelingParams.obj" \
	"$(INTDIR)\JDFAutoLaminatingParams.obj" \
	"$(INTDIR)\JDFAutoLayout.obj" \
	"$(INTDIR)\JDFAutoLayoutElement.obj" \
	"$(INTDIR)\JDFAutoLayoutPreparationParams.obj" \
	"$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.obj" \
	"$(INTDIR)\JDFAutoManualLaborParams.obj" \
	"$(INTDIR)\JDFAutoMedia.obj" \
	"$(INTDIR)\JDFAutoMediaSource.obj" \
	"$(INTDIR)\JDFAutoMISDetails.obj" \
	"$(INTDIR)\JDFAutoNumberingParams.obj" \
	"$(INTDIR)\JDFAutoObjectResolution.obj" \
	"$(INTDIR)\JDFAutoOrderingParams.obj" \
	"$(INTDIR)\JDFAutoPackingParams.obj" \
	"$(INTDIR)\JDFAutoPageList.obj" \
	"$(INTDIR)\JDFAutoPallet.obj" \
	"$(INTDIR)\JDFAutoPalletizingParams.obj" \
	"$(INTDIR)\JDFAutoPDFToPSConversionParams.obj" \
	"$(INTDIR)\JDFAutoPDLResourceAlias.obj" \
	"$(INTDIR)\JDFAutoPerforatingParams.obj" \
	"$(INTDIR)\JDFAutoPerson.obj" \
	"$(INTDIR)\JDFAutoPlaceHolderResource.obj" \
	"$(INTDIR)\JDFAutoPlasticCombBindingParams.obj" \
	"$(INTDIR)\JDFAutoPlateCopyParams.obj" \
	"$(INTDIR)\JDFAutoPreflightAnalysis.obj" \
	"$(INTDIR)\JDFAutoPreflightInventory.obj" \
	"$(INTDIR)\JDFAutoPreflightParams.obj" \
	"$(INTDIR)\JDFAutoPreflightProfile.obj" \
	"$(INTDIR)\JDFAutoPreflightReport.obj" \
	"$(INTDIR)\JDFAutoPreflightReportRulePool.obj" \
	"$(INTDIR)\JDFAutoPreview.obj" \
	"$(INTDIR)\JDFAutoPreviewGenerationParams.obj" \
	"$(INTDIR)\JDFAutoPrintCondition.obj" \
	"$(INTDIR)\JDFAutoPrintRollingParams.obj" \
	"$(INTDIR)\JDFAutoProofingParams.obj" \
	"$(INTDIR)\JDFAutoPSToPDFConversionParams.obj" \
	"$(INTDIR)\JDFAutoQualityControlParams.obj" \
	"$(INTDIR)\JDFAutoQualityControlResult.obj" \
	"$(INTDIR)\JDFAutoRegisterMark.obj" \
	"$(INTDIR)\JDFAutoRegisterRibbon.obj" \
	"$(INTDIR)\JDFAutoRenderingParams.obj" \
	"$(INTDIR)\JDFAutoResourceDefinitionParams.obj" \
	"$(INTDIR)\JDFAutoRingBindingParams.obj" \
	"$(INTDIR)\JDFAutoRollStand.obj" \
	"$(INTDIR)\JDFAutoRunList.obj" \
	"$(INTDIR)\JDFAutoSaddleStitchingParams.obj" \
	"$(INTDIR)\JDFAutoScanParams.obj" \
	"$(INTDIR)\JDFAutoScavengerArea.obj" \
	"$(INTDIR)\JDFAutoScreeningParams.obj" \
	"$(INTDIR)\JDFAutoSeparationControlParams.obj" \
	"$(INTDIR)\JDFAutoSeparationSpec.obj" \
	"$(INTDIR)\JDFAutoShapeCuttingParams.obj" \
	"$(INTDIR)\JDFAutoSheet.obj" \
	"$(INTDIR)\JDFAutoShrinkingParams.obj" \
	"$(INTDIR)\JDFAutoSideSewingParams.obj" \
	"$(INTDIR)\JDFAutoSpinePreparationParams.obj" \
	"$(INTDIR)\JDFAutoSpineTapingParams.obj" \
	"$(INTDIR)\JDFAutoStackingParams.obj" \
	"$(INTDIR)\JDFAutoStitchingParams.obj" \
	"$(INTDIR)\JDFAutoStrap.obj" \
	"$(INTDIR)\JDFAutoStrappingParams.obj" \
	"$(INTDIR)\JDFAutoStripBindingParams.obj" \
	"$(INTDIR)\JDFAutoStrippingParams.obj" \
	"$(INTDIR)\JDFAutoSurface.obj" \
	"$(INTDIR)\JDFAutoThreadSealingParams.obj" \
	"$(INTDIR)\JDFAutoThreadSewingParams.obj" \
	"$(INTDIR)\JDFAutoTile.obj" \
	"$(INTDIR)\JDFAutoTool.obj" \
	"$(INTDIR)\JDFAutoTransferCurve.obj" \
	"$(INTDIR)\JDFAutoTransferCurvePool.obj" \
	"$(INTDIR)\JDFAutoTransferFunctionControl.obj" \
	"$(INTDIR)\JDFAutoTrappingDetails.obj" \
	"$(INTDIR)\JDFAutoTrappingParams.obj" \
	"$(INTDIR)\JDFAutoTrapRegion.obj" \
	"$(INTDIR)\JDFAutoTrimmingParams.obj" \
	"$(INTDIR)\JDFAutoVerificationParams.obj" \
	"$(INTDIR)\JDFAutoWireCombBindingParams.obj" \
	"$(INTDIR)\JDFAutoWrappingParams.obj" \
	"$(INTDIR)\JDFArgumentValue.obj" \
	"$(INTDIR)\JDFAutoAdvancedParams.obj" \
	"$(INTDIR)\JDFAutoApprovalPerson.obj" \
	"$(INTDIR)\JDFAutoArgumentValue.obj" \
	"$(INTDIR)\JDFAutoAssemblySection.obj" \
	"$(INTDIR)\JDFAutoBand.obj" \
	"$(INTDIR)\JDFAutoBasicPreflightTest.obj" \
	"$(INTDIR)\JDFAutoBindingQualityParams.obj" \
	"$(INTDIR)\JDFAutoBoxArgument.obj" \
	"$(INTDIR)\JDFAutoBoxToBoxDifference.obj" \
	"$(INTDIR)\JDFAutoBundleItem.obj" \
	"$(INTDIR)\JDFAutoCCITTFaxParams.obj" \
	"$(INTDIR)\JDFAutoCollatingItem.obj" \
	"$(INTDIR)\JDFAutoColorantZoneDetails.obj" \
	"$(INTDIR)\JDFAutoColorCorrectionOp.obj" \
	"$(INTDIR)\JDFAutoColorSpaceSubstitute.obj" \
	"$(INTDIR)\JDFAutoContainer.obj" \
	"$(INTDIR)\JDFAutoContentObject.obj" \
	"$(INTDIR)\JDFAutoCrease.obj" \
	"$(INTDIR)\JDFAutoCut.obj" \
	"$(INTDIR)\JDFAutoDCTParams.obj" \
	"$(INTDIR)\JDFAutoDependencies.obj" \
	"$(INTDIR)\JDFAutoDeviceNColor.obj" \
	"$(INTDIR)\JDFAutoDrop.obj" \
	"$(INTDIR)\JDFAutoDropItem.obj" \
	"$(INTDIR)\JDFAutoDynamicField.obj" \
	"$(INTDIR)\JDFAutoDynamicInput.obj" \
	"$(INTDIR)\JDFAutoEmboss.obj" \
	"$(INTDIR)\JDFAutoEndSheet.obj" \
	"$(INTDIR)\JDFAutoFeeder.obj" \
	"$(INTDIR)\JDFAutoFeederQualityParams.obj" \
	"$(INTDIR)\JDFAutoFileAlias.obj" \
	"$(INTDIR)\JDFAutoFlateParams.obj" \
	"$(INTDIR)\JDFAutoGlue.obj" \
	"$(INTDIR)\JDFAutoIcon.obj" \
	"$(INTDIR)\JDFAutoIconList.obj" \
	"$(INTDIR)\JDFAutoIDPCover.obj" \
	"$(INTDIR)\JDFAutoIDPFinishing.obj" \
	"$(INTDIR)\JDFAutoIDPFolding.obj" \
	"$(INTDIR)\JDFAutoIDPHoleMaking.obj" \
	"$(INTDIR)\JDFAutoIDPImageShift.obj" \
	"$(INTDIR)\JDFAutoIDPJobSheet.obj" \
	"$(INTDIR)\JDFAutoIDPLayout.obj" \
	"$(INTDIR)\JDFAutoIDPStitching.obj" \
	"$(INTDIR)\JDFAutoIDPTrimming.obj" \
	"$(INTDIR)\JDFAutoImageCompression.obj" \
	"$(INTDIR)\JDFAutoImageShift.obj" \
	"$(INTDIR)\JDFAutoLayerDetails.obj" \
	"$(INTDIR)\JDFAutoLayerList.obj" \
	"$(INTDIR)\JDFAutoLongFold.obj" \
	"$(INTDIR)\JDFAutoLongGlue.obj" \
	"$(INTDIR)\JDFAutoLongPerforate.obj" \
	"$(INTDIR)\JDFAutoLongSlit.obj" \
	"$(INTDIR)\JDFAutoLZWParams.obj" \
	"$(INTDIR)\JDFAutoMarkObject.obj" \
	"$(INTDIR)\JDFAutoNumberingParam.obj" \
	"$(INTDIR)\JDFAutoPageCell.obj" \
	"$(INTDIR)\JDFAutoPageData.obj" \
	"$(INTDIR)\JDFAutoPDFInterpretingParams.obj" \
	"$(INTDIR)\JDFAutoPDFXParams.obj" \
	"$(INTDIR)\JDFAutoPerforate.obj" \
	"$(INTDIR)\JDFAutoPixelColorant.obj" \
	"$(INTDIR)\JDFAutoPosition.obj" \
	"$(INTDIR)\JDFAutoPreflightAction.obj" \
	"$(INTDIR)\JDFAutoPreflightArgument.obj" \
	"$(INTDIR)\JDFAutoPreflightConstraint.obj" \
	"$(INTDIR)\JDFAutoPreflightDetail.obj" \
	"$(INTDIR)\JDFAutoPreflightInstance.obj" \
	"$(INTDIR)\JDFAutoPreflightInstanceDetail.obj" \
	"$(INTDIR)\JDFAutoPreflightValue.obj" \
	"$(INTDIR)\JDFAutoPRError.obj" \
	"$(INTDIR)\JDFAutoPRGroup.obj" \
	"$(INTDIR)\JDFAutoPrintConditionColor.obj" \
	"$(INTDIR)\JDFAutoPRItem.obj" \
	"$(INTDIR)\JDFAutoPROccurence.obj" \
	"$(INTDIR)\JDFAutoProperties.obj" \
	"$(INTDIR)\JDFAutoPRRule.obj" \
	"$(INTDIR)\JDFAutoPRRuleAttr.obj" \
	"$(INTDIR)\JDFAutoQualityMeasurement.obj" \
	"$(INTDIR)\JDFAutoResourceParam.obj" \
	"$(INTDIR)\JDFAutoScore.obj" \
	"$(INTDIR)\JDFAutoScreenSelector.obj" \
	"$(INTDIR)\JDFAutoShapeElement.obj" \
	"$(INTDIR)\JDFAutoSignature.obj" \
	"$(INTDIR)\JDFAutoSignatureCell.obj" \
	"$(INTDIR)\JDFAutoStringListValue.obj" \
	"$(INTDIR)\JDFAutoStripCellParams.obj" \
	"$(INTDIR)\JDFAutoThinPDFParams.obj" \
	"$(INTDIR)\JDFAutoTIFFEmbeddedFile.obj" \
	"$(INTDIR)\JDFAutoTIFFFormatParams.obj" \
	"$(INTDIR)\JDFAutoTIFFtag.obj" \
	"$(INTDIR)\JDFAutoTransferCurveSet.obj" \
	"$(INTDIR)\JDFAutoTrappingOrder.obj" \
	"$(INTDIR)\JDFAutoAction.obj" \
	"$(INTDIR)\JDFAutoActionPool.obj" \
	"$(INTDIR)\JDFAutoand.obj" \
	"$(INTDIR)\JDFAutocall.obj" \
	"$(INTDIR)\JDFAutochoice.obj" \
	"$(INTDIR)\JDFAutoDevCap.obj" \
	"$(INTDIR)\JDFAutoDevCaps.obj" \
	"$(INTDIR)\JDFAutoDeviceCap.obj" \
	"$(INTDIR)\JDFAutoDisplayGroup.obj" \
	"$(INTDIR)\JDFAutoDisplayGroupPool.obj" \
	"$(INTDIR)\JDFAutoFeatureAttribute.obj" \
	"$(INTDIR)\JDFAutoFeaturePool.obj" \
	"$(INTDIR)\JDFAutoLoc.obj" \
	"$(INTDIR)\JDFAutomacro.obj" \
	"$(INTDIR)\JDFAutoMacroPool.obj" \
	"$(INTDIR)\JDFAutonot.obj" \
	"$(INTDIR)\JDFAutoor.obj" \
	"$(INTDIR)\JDFAutootherwise.obj" \
	"$(INTDIR)\JDFAutoPerformance.obj" \
	"$(INTDIR)\JDFAutoset.obj" \
	"$(INTDIR)\JDFAutoTest.obj" \
	"$(INTDIR)\JDFAutoTestPool.obj" \
	"$(INTDIR)\JDFAutoTestRef.obj" \
	"$(INTDIR)\JDFAutoValue.obj" \
	"$(INTDIR)\JDFAutoValueLoc.obj" \
	"$(INTDIR)\JDFAutowhen.obj" \
	"$(INTDIR)\JDFAutoxor.obj" \
	"$(INTDIR)\JDFAutoEnumerationSpan.obj" \
	"$(INTDIR)\JDFAutoPRGroupOccurence.obj" \
	"$(INTDIR)\JDFAutoPRGroupOccurenceBase.obj" \
	"$(INTDIR)\JDFPreflightConstraintsPool.obj" \
	"$(INTDIR)\JDFPreflightResultsPool.obj" \
	"$(INTDIR)\JDFPRGroupOccurence.obj" \
	"$(INTDIR)\JDFPRGroupOccurenceBase.obj" \
	"$(INTDIR)\JDFDateTimeRange.obj" \
	"$(INTDIR)\JDFDateTimeRangeList.obj" \
	"$(INTDIR)\JDFDurationRange.obj" \
	"$(INTDIR)\JDFDurationRangeList.obj" \
	"$(INTDIR)\JDFIntegerRange.obj" \
	"$(INTDIR)\JDFIntegerRangeList.obj" \
	"$(INTDIR)\JDFNameRangeList.obj" \
	"$(INTDIR)\JDFNumberRangeList.obj" \
	"$(INTDIR)\JDFNumTypeList.obj" \
	"$(INTDIR)\JDFParser.obj" \
	"$(INTDIR)\JDFRange.obj" \
	"$(INTDIR)\JDFRangeList.obj" \
	"$(INTDIR)\JDFXYPairRangeList.obj" \
	"$(INTDIR)\KElement.obj" \
	"$(INTDIR)\KElementStrings.obj" \
	"$(INTDIR)\MyDate.obj" \
	"$(INTDIR)\vElement.obj" \
	"$(INTDIR)\XMLDoc.obj" \
	"$(INTDIR)\XMLDocUserData.obj"

"$(OUTDIR)\JDFWrapperLib_D.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Release"

OUTDIR=.\..\..\..\Build\Win32\VC6\Release
INTDIR=.\..\..\..\Build\Win32\VC6\Release\obj\JDFWrapperLib
# Begin Custom Macros
OutDir=.\..\..\..\Build\Win32\VC6\Release
# End Custom Macros

ALL : "$(OUTDIR)\JDFWrapperLib.lib" "$(OUTDIR)\JDFWrapperLib.bsc"


CLEAN :
	-@erase "$(INTDIR)\JDFAcknowledge.obj"
	-@erase "$(INTDIR)\JDFAcknowledge.sbr"
	-@erase "$(INTDIR)\JDFAction.obj"
	-@erase "$(INTDIR)\JDFAction.sbr"
	-@erase "$(INTDIR)\JDFActionPool.obj"
	-@erase "$(INTDIR)\JDFActionPool.sbr"
	-@erase "$(INTDIR)\JDFAdded.obj"
	-@erase "$(INTDIR)\JDFAdded.sbr"
	-@erase "$(INTDIR)\JDFAddress.obj"
	-@erase "$(INTDIR)\JDFAddress.sbr"
	-@erase "$(INTDIR)\JDFAdhesiveBinding.obj"
	-@erase "$(INTDIR)\JDFAdhesiveBinding.sbr"
	-@erase "$(INTDIR)\JDFAdhesiveBindingParams.obj"
	-@erase "$(INTDIR)\JDFAdhesiveBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAdvancedParams.obj"
	-@erase "$(INTDIR)\JDFAdvancedParams.sbr"
	-@erase "$(INTDIR)\JDFAmountPool.obj"
	-@erase "$(INTDIR)\JDFAmountPool.sbr"
	-@erase "$(INTDIR)\JDFAncestor.obj"
	-@erase "$(INTDIR)\JDFAncestor.sbr"
	-@erase "$(INTDIR)\JDFAncestorPool.obj"
	-@erase "$(INTDIR)\JDFAncestorPool.sbr"
	-@erase "$(INTDIR)\JDFand.obj"
	-@erase "$(INTDIR)\JDFand.sbr"
	-@erase "$(INTDIR)\JDFApprovalParams.obj"
	-@erase "$(INTDIR)\JDFApprovalParams.sbr"
	-@erase "$(INTDIR)\JDFApprovalPerson.obj"
	-@erase "$(INTDIR)\JDFApprovalPerson.sbr"
	-@erase "$(INTDIR)\JDFApprovalSuccess.obj"
	-@erase "$(INTDIR)\JDFApprovalSuccess.sbr"
	-@erase "$(INTDIR)\JDFArgumentValue.obj"
	-@erase "$(INTDIR)\JDFArgumentValue.sbr"
	-@erase "$(INTDIR)\JDFArtDelivery.obj"
	-@erase "$(INTDIR)\JDFArtDelivery.sbr"
	-@erase "$(INTDIR)\JDFArtDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFArtDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFAssembly.obj"
	-@erase "$(INTDIR)\JDFAssembly.sbr"
	-@erase "$(INTDIR)\JDFAssemblySection.obj"
	-@erase "$(INTDIR)\JDFAssemblySection.sbr"
	-@erase "$(INTDIR)\JDFAssetListCreationParams.obj"
	-@erase "$(INTDIR)\JDFAssetListCreationParams.sbr"
	-@erase "$(INTDIR)\JDFAudit.obj"
	-@erase "$(INTDIR)\JDFAudit.sbr"
	-@erase "$(INTDIR)\JDFAuditPool.obj"
	-@erase "$(INTDIR)\JDFAuditPool.sbr"
	-@erase "$(INTDIR)\JDFAutoAcknowledge.obj"
	-@erase "$(INTDIR)\JDFAutoAcknowledge.sbr"
	-@erase "$(INTDIR)\JDFAutoAction.obj"
	-@erase "$(INTDIR)\JDFAutoAction.sbr"
	-@erase "$(INTDIR)\JDFAutoActionPool.obj"
	-@erase "$(INTDIR)\JDFAutoActionPool.sbr"
	-@erase "$(INTDIR)\JDFAutoAdded.obj"
	-@erase "$(INTDIR)\JDFAutoAdded.sbr"
	-@erase "$(INTDIR)\JDFAutoAddress.obj"
	-@erase "$(INTDIR)\JDFAutoAddress.sbr"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBinding.obj"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoAdvancedParams.obj"
	-@erase "$(INTDIR)\JDFAutoAdvancedParams.sbr"
	-@erase "$(INTDIR)\JDFAutoAmountPool.obj"
	-@erase "$(INTDIR)\JDFAutoAmountPool.sbr"
	-@erase "$(INTDIR)\JDFAutoAncestor.obj"
	-@erase "$(INTDIR)\JDFAutoAncestor.sbr"
	-@erase "$(INTDIR)\JDFAutoAncestorPool.obj"
	-@erase "$(INTDIR)\JDFAutoAncestorPool.sbr"
	-@erase "$(INTDIR)\JDFAutoand.obj"
	-@erase "$(INTDIR)\JDFAutoand.sbr"
	-@erase "$(INTDIR)\JDFAutoApprovalParams.obj"
	-@erase "$(INTDIR)\JDFAutoApprovalParams.sbr"
	-@erase "$(INTDIR)\JDFAutoApprovalPerson.obj"
	-@erase "$(INTDIR)\JDFAutoApprovalPerson.sbr"
	-@erase "$(INTDIR)\JDFAutoApprovalSuccess.obj"
	-@erase "$(INTDIR)\JDFAutoApprovalSuccess.sbr"
	-@erase "$(INTDIR)\JDFAutoArgumentValue.obj"
	-@erase "$(INTDIR)\JDFAutoArgumentValue.sbr"
	-@erase "$(INTDIR)\JDFAutoArtDelivery.obj"
	-@erase "$(INTDIR)\JDFAutoArtDelivery.sbr"
	-@erase "$(INTDIR)\JDFAutoArtDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFAutoArtDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoAssembly.obj"
	-@erase "$(INTDIR)\JDFAutoAssembly.sbr"
	-@erase "$(INTDIR)\JDFAutoAssemblySection.obj"
	-@erase "$(INTDIR)\JDFAutoAssemblySection.sbr"
	-@erase "$(INTDIR)\JDFAutoAssetListCreationParams.obj"
	-@erase "$(INTDIR)\JDFAutoAssetListCreationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoAutomatedOverprintParams.obj"
	-@erase "$(INTDIR)\JDFAutoAutomatedOverprintParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBand.obj"
	-@erase "$(INTDIR)\JDFAutoBand.sbr"
	-@erase "$(INTDIR)\JDFAutoBarcode.obj"
	-@erase "$(INTDIR)\JDFAutoBarcode.sbr"
	-@erase "$(INTDIR)\JDFAutoBasicPreflightTest.obj"
	-@erase "$(INTDIR)\JDFAutoBasicPreflightTest.sbr"
	-@erase "$(INTDIR)\JDFAutoBinderySignature.obj"
	-@erase "$(INTDIR)\JDFAutoBinderySignature.sbr"
	-@erase "$(INTDIR)\JDFAutoBindingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoBindingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoBindingQualityParams.obj"
	-@erase "$(INTDIR)\JDFAutoBindingQualityParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBindItem.obj"
	-@erase "$(INTDIR)\JDFAutoBindItem.sbr"
	-@erase "$(INTDIR)\JDFAutoBindList.obj"
	-@erase "$(INTDIR)\JDFAutoBindList.sbr"
	-@erase "$(INTDIR)\JDFAutoBlockPreparationParams.obj"
	-@erase "$(INTDIR)\JDFAutoBlockPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBookCase.obj"
	-@erase "$(INTDIR)\JDFAutoBookCase.sbr"
	-@erase "$(INTDIR)\JDFAutoBoxArgument.obj"
	-@erase "$(INTDIR)\JDFAutoBoxArgument.sbr"
	-@erase "$(INTDIR)\JDFAutoBoxPackingParams.obj"
	-@erase "$(INTDIR)\JDFAutoBoxPackingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBoxToBoxDifference.obj"
	-@erase "$(INTDIR)\JDFAutoBoxToBoxDifference.sbr"
	-@erase "$(INTDIR)\JDFAutoBufferParams.obj"
	-@erase "$(INTDIR)\JDFAutoBufferParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBundle.obj"
	-@erase "$(INTDIR)\JDFAutoBundle.sbr"
	-@erase "$(INTDIR)\JDFAutoBundleItem.obj"
	-@erase "$(INTDIR)\JDFAutoBundleItem.sbr"
	-@erase "$(INTDIR)\JDFAutoBundlingParams.obj"
	-@erase "$(INTDIR)\JDFAutoBundlingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBusinessInfo.obj"
	-@erase "$(INTDIR)\JDFAutoBusinessInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoByteMap.obj"
	-@erase "$(INTDIR)\JDFAutoByteMap.sbr"
	-@erase "$(INTDIR)\JDFAutocall.obj"
	-@erase "$(INTDIR)\JDFAutocall.sbr"
	-@erase "$(INTDIR)\JDFAutoCaseMakingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCaseMakingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCasingInParams.obj"
	-@erase "$(INTDIR)\JDFAutoCasingInParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCCITTFaxParams.obj"
	-@erase "$(INTDIR)\JDFAutoCCITTFaxParams.sbr"
	-@erase "$(INTDIR)\JDFAutoChangedAttribute.obj"
	-@erase "$(INTDIR)\JDFAutoChangedAttribute.sbr"
	-@erase "$(INTDIR)\JDFAutoChangedPath.obj"
	-@erase "$(INTDIR)\JDFAutoChangedPath.sbr"
	-@erase "$(INTDIR)\JDFAutoChannelBinding.obj"
	-@erase "$(INTDIR)\JDFAutoChannelBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoChannelBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoChannelBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutochoice.obj"
	-@erase "$(INTDIR)\JDFAutochoice.sbr"
	-@erase "$(INTDIR)\JDFAutoCIELABMeasuringField.obj"
	-@erase "$(INTDIR)\JDFAutoCIELABMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFAutoCoilBinding.obj"
	-@erase "$(INTDIR)\JDFAutoCoilBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoCoilBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCoilBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCollatingItem.obj"
	-@erase "$(INTDIR)\JDFAutoCollatingItem.sbr"
	-@erase "$(INTDIR)\JDFAutoCollectingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCollectingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoColor.obj"
	-@erase "$(INTDIR)\JDFAutoColor.sbr"
	-@erase "$(INTDIR)\JDFAutoColorantAlias.obj"
	-@erase "$(INTDIR)\JDFAutoColorantAlias.sbr"
	-@erase "$(INTDIR)\JDFAutoColorantControl.obj"
	-@erase "$(INTDIR)\JDFAutoColorantControl.sbr"
	-@erase "$(INTDIR)\JDFAutoColorantZoneDetails.obj"
	-@erase "$(INTDIR)\JDFAutoColorantZoneDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoColorControlStrip.obj"
	-@erase "$(INTDIR)\JDFAutoColorControlStrip.sbr"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionOp.obj"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionOp.sbr"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionParams.obj"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoColorIntent.obj"
	-@erase "$(INTDIR)\JDFAutoColorIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoColorMeasurementConditions.obj"
	-@erase "$(INTDIR)\JDFAutoColorMeasurementConditions.sbr"
	-@erase "$(INTDIR)\JDFAutoColorPool.obj"
	-@erase "$(INTDIR)\JDFAutoColorPool.sbr"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionOp.obj"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionOp.sbr"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoColorSpaceSubstitute.obj"
	-@erase "$(INTDIR)\JDFAutoColorSpaceSubstitute.sbr"
	-@erase "$(INTDIR)\JDFAutoColorsUsed.obj"
	-@erase "$(INTDIR)\JDFAutoColorsUsed.sbr"
	-@erase "$(INTDIR)\JDFAutoComChannel.obj"
	-@erase "$(INTDIR)\JDFAutoComChannel.sbr"
	-@erase "$(INTDIR)\JDFAutoCommand.obj"
	-@erase "$(INTDIR)\JDFAutoCommand.sbr"
	-@erase "$(INTDIR)\JDFAutoComment.obj"
	-@erase "$(INTDIR)\JDFAutoComment.sbr"
	-@erase "$(INTDIR)\JDFAutoCompany.obj"
	-@erase "$(INTDIR)\JDFAutoCompany.sbr"
	-@erase "$(INTDIR)\JDFAutoComponent.obj"
	-@erase "$(INTDIR)\JDFAutoComponent.sbr"
	-@erase "$(INTDIR)\JDFAutoContact.obj"
	-@erase "$(INTDIR)\JDFAutoContact.sbr"
	-@erase "$(INTDIR)\JDFAutoContactCopyParams.obj"
	-@erase "$(INTDIR)\JDFAutoContactCopyParams.sbr"
	-@erase "$(INTDIR)\JDFAutoContainer.obj"
	-@erase "$(INTDIR)\JDFAutoContainer.sbr"
	-@erase "$(INTDIR)\JDFAutoContentObject.obj"
	-@erase "$(INTDIR)\JDFAutoContentObject.sbr"
	-@erase "$(INTDIR)\JDFAutoConventionalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFAutoConventionalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCostCenter.obj"
	-@erase "$(INTDIR)\JDFAutoCostCenter.sbr"
	-@erase "$(INTDIR)\JDFAutoCounterReset.obj"
	-@erase "$(INTDIR)\JDFAutoCounterReset.sbr"
	-@erase "$(INTDIR)\JDFAutoCoverApplicationParams.obj"
	-@erase "$(INTDIR)\JDFAutoCoverApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCrease.obj"
	-@erase "$(INTDIR)\JDFAutoCrease.sbr"
	-@erase "$(INTDIR)\JDFAutoCreasingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCreasingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCreated.obj"
	-@erase "$(INTDIR)\JDFAutoCreated.sbr"
	-@erase "$(INTDIR)\JDFAutoCreditCard.obj"
	-@erase "$(INTDIR)\JDFAutoCreditCard.sbr"
	-@erase "$(INTDIR)\JDFAutoCustomerInfo.obj"
	-@erase "$(INTDIR)\JDFAutoCustomerInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoCustomerMessage.obj"
	-@erase "$(INTDIR)\JDFAutoCustomerMessage.sbr"
	-@erase "$(INTDIR)\JDFAutoCut.obj"
	-@erase "$(INTDIR)\JDFAutoCut.sbr"
	-@erase "$(INTDIR)\JDFAutoCutBlock.obj"
	-@erase "$(INTDIR)\JDFAutoCutBlock.sbr"
	-@erase "$(INTDIR)\JDFAutoCutMark.obj"
	-@erase "$(INTDIR)\JDFAutoCutMark.sbr"
	-@erase "$(INTDIR)\JDFAutoCuttingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDBMergeParams.obj"
	-@erase "$(INTDIR)\JDFAutoDBMergeParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDBRules.obj"
	-@erase "$(INTDIR)\JDFAutoDBRules.sbr"
	-@erase "$(INTDIR)\JDFAutoDBSchema.obj"
	-@erase "$(INTDIR)\JDFAutoDBSchema.sbr"
	-@erase "$(INTDIR)\JDFAutoDBSelection.obj"
	-@erase "$(INTDIR)\JDFAutoDBSelection.sbr"
	-@erase "$(INTDIR)\JDFAutoDCTParams.obj"
	-@erase "$(INTDIR)\JDFAutoDCTParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDeleted.obj"
	-@erase "$(INTDIR)\JDFAutoDeleted.sbr"
	-@erase "$(INTDIR)\JDFAutoDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFAutoDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFAutoDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDensityMeasuringField.obj"
	-@erase "$(INTDIR)\JDFAutoDensityMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFAutoDependencies.obj"
	-@erase "$(INTDIR)\JDFAutoDependencies.sbr"
	-@erase "$(INTDIR)\JDFAutoDevCap.obj"
	-@erase "$(INTDIR)\JDFAutoDevCap.sbr"
	-@erase "$(INTDIR)\JDFAutoDevCaps.obj"
	-@erase "$(INTDIR)\JDFAutoDevCaps.sbr"
	-@erase "$(INTDIR)\JDFAutoDevelopingParams.obj"
	-@erase "$(INTDIR)\JDFAutoDevelopingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDevice.obj"
	-@erase "$(INTDIR)\JDFAutoDevice.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceCap.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceCap.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceFilter.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceInfo.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceList.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceList.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceMark.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceMark.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceNColor.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceNColor.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceNSpace.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceNSpace.sbr"
	-@erase "$(INTDIR)\JDFAutoDigitalDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFAutoDigitalDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDigitalMedia.obj"
	-@erase "$(INTDIR)\JDFAutoDigitalMedia.sbr"
	-@erase "$(INTDIR)\JDFAutoDigitalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFAutoDigitalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDisjointing.obj"
	-@erase "$(INTDIR)\JDFAutoDisjointing.sbr"
	-@erase "$(INTDIR)\JDFAutoDisplayGroup.obj"
	-@erase "$(INTDIR)\JDFAutoDisplayGroup.sbr"
	-@erase "$(INTDIR)\JDFAutoDisplayGroupPool.obj"
	-@erase "$(INTDIR)\JDFAutoDisplayGroupPool.sbr"
	-@erase "$(INTDIR)\JDFAutoDisposition.obj"
	-@erase "$(INTDIR)\JDFAutoDisposition.sbr"
	-@erase "$(INTDIR)\JDFAutoDividingParams.obj"
	-@erase "$(INTDIR)\JDFAutoDividingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDrop.obj"
	-@erase "$(INTDIR)\JDFAutoDrop.sbr"
	-@erase "$(INTDIR)\JDFAutoDropIntent.obj"
	-@erase "$(INTDIR)\JDFAutoDropIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoDropItem.obj"
	-@erase "$(INTDIR)\JDFAutoDropItem.sbr"
	-@erase "$(INTDIR)\JDFAutoDropItemIntent.obj"
	-@erase "$(INTDIR)\JDFAutoDropItemIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoDynamicField.obj"
	-@erase "$(INTDIR)\JDFAutoDynamicField.sbr"
	-@erase "$(INTDIR)\JDFAutoDynamicInput.obj"
	-@erase "$(INTDIR)\JDFAutoDynamicInput.sbr"
	-@erase "$(INTDIR)\JDFAutoEdgeGluing.obj"
	-@erase "$(INTDIR)\JDFAutoEdgeGluing.sbr"
	-@erase "$(INTDIR)\JDFAutoElementColorParams.obj"
	-@erase "$(INTDIR)\JDFAutoElementColorParams.sbr"
	-@erase "$(INTDIR)\JDFAutoEmboss.obj"
	-@erase "$(INTDIR)\JDFAutoEmboss.sbr"
	-@erase "$(INTDIR)\JDFAutoEmbossingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoEmbossingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoEmbossingItem.obj"
	-@erase "$(INTDIR)\JDFAutoEmbossingItem.sbr"
	-@erase "$(INTDIR)\JDFAutoEmbossingParams.obj"
	-@erase "$(INTDIR)\JDFAutoEmbossingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoEmployee.obj"
	-@erase "$(INTDIR)\JDFAutoEmployee.sbr"
	-@erase "$(INTDIR)\JDFAutoEmployeeDef.obj"
	-@erase "$(INTDIR)\JDFAutoEmployeeDef.sbr"
	-@erase "$(INTDIR)\JDFAutoEndSheet.obj"
	-@erase "$(INTDIR)\JDFAutoEndSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoEndSheetGluingParams.obj"
	-@erase "$(INTDIR)\JDFAutoEndSheetGluingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoEnumerationSpan.obj"
	-@erase "$(INTDIR)\JDFAutoEnumerationSpan.sbr"
	-@erase "$(INTDIR)\JDFAutoError.obj"
	-@erase "$(INTDIR)\JDFAutoError.sbr"
	-@erase "$(INTDIR)\JDFAutoEvent.obj"
	-@erase "$(INTDIR)\JDFAutoEvent.sbr"
	-@erase "$(INTDIR)\JDFAutoExposedMedia.obj"
	-@erase "$(INTDIR)\JDFAutoExposedMedia.sbr"
	-@erase "$(INTDIR)\JDFAutoFCNKey.obj"
	-@erase "$(INTDIR)\JDFAutoFCNKey.sbr"
	-@erase "$(INTDIR)\JDFAutoFeatureAttribute.obj"
	-@erase "$(INTDIR)\JDFAutoFeatureAttribute.sbr"
	-@erase "$(INTDIR)\JDFAutoFeaturePool.obj"
	-@erase "$(INTDIR)\JDFAutoFeaturePool.sbr"
	-@erase "$(INTDIR)\JDFAutoFeeder.obj"
	-@erase "$(INTDIR)\JDFAutoFeeder.sbr"
	-@erase "$(INTDIR)\JDFAutoFeederQualityParams.obj"
	-@erase "$(INTDIR)\JDFAutoFeederQualityParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFeedingParams.obj"
	-@erase "$(INTDIR)\JDFAutoFeedingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFileAlias.obj"
	-@erase "$(INTDIR)\JDFAutoFileAlias.sbr"
	-@erase "$(INTDIR)\JDFAutoFileSpec.obj"
	-@erase "$(INTDIR)\JDFAutoFileSpec.sbr"
	-@erase "$(INTDIR)\JDFAutoFitPolicy.obj"
	-@erase "$(INTDIR)\JDFAutoFitPolicy.sbr"
	-@erase "$(INTDIR)\JDFAutoFlateParams.obj"
	-@erase "$(INTDIR)\JDFAutoFlateParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFlushedResources.obj"
	-@erase "$(INTDIR)\JDFAutoFlushedResources.sbr"
	-@erase "$(INTDIR)\JDFAutoFlushQueueParams.obj"
	-@erase "$(INTDIR)\JDFAutoFlushQueueParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFlushResourceParams.obj"
	-@erase "$(INTDIR)\JDFAutoFlushResourceParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFold.obj"
	-@erase "$(INTDIR)\JDFAutoFold.sbr"
	-@erase "$(INTDIR)\JDFAutoFoldingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoFoldingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoFoldingParams.obj"
	-@erase "$(INTDIR)\JDFAutoFoldingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFontParams.obj"
	-@erase "$(INTDIR)\JDFAutoFontParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFontPolicy.obj"
	-@erase "$(INTDIR)\JDFAutoFontPolicy.sbr"
	-@erase "$(INTDIR)\JDFAutoFormatConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoFormatConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoGatheringParams.obj"
	-@erase "$(INTDIR)\JDFAutoGatheringParams.sbr"
	-@erase "$(INTDIR)\JDFAutoGlue.obj"
	-@erase "$(INTDIR)\JDFAutoGlue.sbr"
	-@erase "$(INTDIR)\JDFAutoGlueApplication.obj"
	-@erase "$(INTDIR)\JDFAutoGlueApplication.sbr"
	-@erase "$(INTDIR)\JDFAutoGlueLine.obj"
	-@erase "$(INTDIR)\JDFAutoGlueLine.sbr"
	-@erase "$(INTDIR)\JDFAutoGluingParams.obj"
	-@erase "$(INTDIR)\JDFAutoGluingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoHardCoverBinding.obj"
	-@erase "$(INTDIR)\JDFAutoHardCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoHeadBandApplicationParams.obj"
	-@erase "$(INTDIR)\JDFAutoHeadBandApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoHole.obj"
	-@erase "$(INTDIR)\JDFAutoHole.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleLine.obj"
	-@erase "$(INTDIR)\JDFAutoHoleLine.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleList.obj"
	-@erase "$(INTDIR)\JDFAutoHoleList.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleMakingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoHoleMakingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleMakingParams.obj"
	-@erase "$(INTDIR)\JDFAutoHoleMakingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoIcon.obj"
	-@erase "$(INTDIR)\JDFAutoIcon.sbr"
	-@erase "$(INTDIR)\JDFAutoIconList.obj"
	-@erase "$(INTDIR)\JDFAutoIconList.sbr"
	-@erase "$(INTDIR)\JDFAutoIdentificationField.obj"
	-@erase "$(INTDIR)\JDFAutoIdentificationField.sbr"
	-@erase "$(INTDIR)\JDFAutoIDInfo.obj"
	-@erase "$(INTDIR)\JDFAutoIDInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPCover.obj"
	-@erase "$(INTDIR)\JDFAutoIDPCover.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPFinishing.obj"
	-@erase "$(INTDIR)\JDFAutoIDPFinishing.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPFolding.obj"
	-@erase "$(INTDIR)\JDFAutoIDPFolding.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPHoleMaking.obj"
	-@erase "$(INTDIR)\JDFAutoIDPHoleMaking.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPImageShift.obj"
	-@erase "$(INTDIR)\JDFAutoIDPImageShift.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPJobSheet.obj"
	-@erase "$(INTDIR)\JDFAutoIDPJobSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPLayout.obj"
	-@erase "$(INTDIR)\JDFAutoIDPLayout.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPrintingParams.obj"
	-@erase "$(INTDIR)\JDFAutoIDPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPStitching.obj"
	-@erase "$(INTDIR)\JDFAutoIDPStitching.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPTrimming.obj"
	-@erase "$(INTDIR)\JDFAutoIDPTrimming.sbr"
	-@erase "$(INTDIR)\JDFAutoImageCompression.obj"
	-@erase "$(INTDIR)\JDFAutoImageCompression.sbr"
	-@erase "$(INTDIR)\JDFAutoImageCompressionParams.obj"
	-@erase "$(INTDIR)\JDFAutoImageCompressionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoImageReplacementParams.obj"
	-@erase "$(INTDIR)\JDFAutoImageReplacementParams.sbr"
	-@erase "$(INTDIR)\JDFAutoImageSetterParams.obj"
	-@erase "$(INTDIR)\JDFAutoImageSetterParams.sbr"
	-@erase "$(INTDIR)\JDFAutoImageShift.obj"
	-@erase "$(INTDIR)\JDFAutoImageShift.sbr"
	-@erase "$(INTDIR)\JDFAutoInk.obj"
	-@erase "$(INTDIR)\JDFAutoInk.sbr"
	-@erase "$(INTDIR)\JDFAutoInkZoneCalculationParams.obj"
	-@erase "$(INTDIR)\JDFAutoInkZoneCalculationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoInkZoneProfile.obj"
	-@erase "$(INTDIR)\JDFAutoInkZoneProfile.sbr"
	-@erase "$(INTDIR)\JDFAutoInsert.obj"
	-@erase "$(INTDIR)\JDFAutoInsert.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoInsertingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertingParams.obj"
	-@erase "$(INTDIR)\JDFAutoInsertingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertList.obj"
	-@erase "$(INTDIR)\JDFAutoInsertList.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertSheet.obj"
	-@erase "$(INTDIR)\JDFAutoInsertSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoInterpretedPDLData.obj"
	-@erase "$(INTDIR)\JDFAutoInterpretedPDLData.sbr"
	-@erase "$(INTDIR)\JDFAutoInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFAutoInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoJacketingParams.obj"
	-@erase "$(INTDIR)\JDFAutoJacketingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoJDFController.obj"
	-@erase "$(INTDIR)\JDFAutoJDFController.sbr"
	-@erase "$(INTDIR)\JDFAutoJDFService.obj"
	-@erase "$(INTDIR)\JDFAutoJDFService.sbr"
	-@erase "$(INTDIR)\JDFAutoJMF.obj"
	-@erase "$(INTDIR)\JDFAutoJMF.sbr"
	-@erase "$(INTDIR)\JDFAutoJobField.obj"
	-@erase "$(INTDIR)\JDFAutoJobField.sbr"
	-@erase "$(INTDIR)\JDFAutoJobPhase.obj"
	-@erase "$(INTDIR)\JDFAutoJobPhase.sbr"
	-@erase "$(INTDIR)\JDFAutoKnownMsgQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoKnownMsgQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLabelingParams.obj"
	-@erase "$(INTDIR)\JDFAutoLabelingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLaminatingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoLaminatingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoLaminatingParams.obj"
	-@erase "$(INTDIR)\JDFAutoLaminatingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLayerDetails.obj"
	-@erase "$(INTDIR)\JDFAutoLayerDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoLayerList.obj"
	-@erase "$(INTDIR)\JDFAutoLayerList.sbr"
	-@erase "$(INTDIR)\JDFAutoLayout.obj"
	-@erase "$(INTDIR)\JDFAutoLayout.sbr"
	-@erase "$(INTDIR)\JDFAutoLayoutElement.obj"
	-@erase "$(INTDIR)\JDFAutoLayoutElement.sbr"
	-@erase "$(INTDIR)\JDFAutoLayoutIntent.obj"
	-@erase "$(INTDIR)\JDFAutoLayoutIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoLayoutPreparationParams.obj"
	-@erase "$(INTDIR)\JDFAutoLayoutPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLoc.obj"
	-@erase "$(INTDIR)\JDFAutoLoc.sbr"
	-@erase "$(INTDIR)\JDFAutoLocation.obj"
	-@erase "$(INTDIR)\JDFAutoLocation.sbr"
	-@erase "$(INTDIR)\JDFAutoLongFold.obj"
	-@erase "$(INTDIR)\JDFAutoLongFold.sbr"
	-@erase "$(INTDIR)\JDFAutoLongGlue.obj"
	-@erase "$(INTDIR)\JDFAutoLongGlue.sbr"
	-@erase "$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.obj"
	-@erase "$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLongPerforate.obj"
	-@erase "$(INTDIR)\JDFAutoLongPerforate.sbr"
	-@erase "$(INTDIR)\JDFAutoLongSlit.obj"
	-@erase "$(INTDIR)\JDFAutoLongSlit.sbr"
	-@erase "$(INTDIR)\JDFAutoLZWParams.obj"
	-@erase "$(INTDIR)\JDFAutoLZWParams.sbr"
	-@erase "$(INTDIR)\JDFAutomacro.obj"
	-@erase "$(INTDIR)\JDFAutomacro.sbr"
	-@erase "$(INTDIR)\JDFAutoMacroPool.obj"
	-@erase "$(INTDIR)\JDFAutoMacroPool.sbr"
	-@erase "$(INTDIR)\JDFAutoManualLaborParams.obj"
	-@erase "$(INTDIR)\JDFAutoManualLaborParams.sbr"
	-@erase "$(INTDIR)\JDFAutoMarkObject.obj"
	-@erase "$(INTDIR)\JDFAutoMarkObject.sbr"
	-@erase "$(INTDIR)\JDFAutomatedOverprintParams.obj"
	-@erase "$(INTDIR)\JDFAutomatedOverprintParams.sbr"
	-@erase "$(INTDIR)\JDFAutoMedia.obj"
	-@erase "$(INTDIR)\JDFAutoMedia.sbr"
	-@erase "$(INTDIR)\JDFAutoMediaIntent.obj"
	-@erase "$(INTDIR)\JDFAutoMediaIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoMediaSource.obj"
	-@erase "$(INTDIR)\JDFAutoMediaSource.sbr"
	-@erase "$(INTDIR)\JDFAutoMerged.obj"
	-@erase "$(INTDIR)\JDFAutoMerged.sbr"
	-@erase "$(INTDIR)\JDFAutoMessage.obj"
	-@erase "$(INTDIR)\JDFAutoMessage.sbr"
	-@erase "$(INTDIR)\JDFAutoMessageService.obj"
	-@erase "$(INTDIR)\JDFAutoMessageService.sbr"
	-@erase "$(INTDIR)\JDFAutoMISDetails.obj"
	-@erase "$(INTDIR)\JDFAutoMISDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoModified.obj"
	-@erase "$(INTDIR)\JDFAutoModified.sbr"
	-@erase "$(INTDIR)\JDFAutoModulePhase.obj"
	-@erase "$(INTDIR)\JDFAutoModulePhase.sbr"
	-@erase "$(INTDIR)\JDFAutoModuleStatus.obj"
	-@erase "$(INTDIR)\JDFAutoModuleStatus.sbr"
	-@erase "$(INTDIR)\JDFAutoMsgFilter.obj"
	-@erase "$(INTDIR)\JDFAutoMsgFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoNewJDFCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoNewJDFCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNewJDFQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoNewJDFQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfo.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfoCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfoCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfoQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfoQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfoResp.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfoResp.sbr"
	-@erase "$(INTDIR)\JDFAutonot.obj"
	-@erase "$(INTDIR)\JDFAutonot.sbr"
	-@erase "$(INTDIR)\JDFAutoNotification.obj"
	-@erase "$(INTDIR)\JDFAutoNotification.sbr"
	-@erase "$(INTDIR)\JDFAutoNotificationDef.obj"
	-@erase "$(INTDIR)\JDFAutoNotificationDef.sbr"
	-@erase "$(INTDIR)\JDFAutoNotificationFilter.obj"
	-@erase "$(INTDIR)\JDFAutoNotificationFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoNumberingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberingParam.obj"
	-@erase "$(INTDIR)\JDFAutoNumberingParam.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberingParams.obj"
	-@erase "$(INTDIR)\JDFAutoNumberingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberItem.obj"
	-@erase "$(INTDIR)\JDFAutoNumberItem.sbr"
	-@erase "$(INTDIR)\JDFAutoObjectResolution.obj"
	-@erase "$(INTDIR)\JDFAutoObjectResolution.sbr"
	-@erase "$(INTDIR)\JDFAutoObservationTarget.obj"
	-@erase "$(INTDIR)\JDFAutoObservationTarget.sbr"
	-@erase "$(INTDIR)\JDFAutoOccupation.obj"
	-@erase "$(INTDIR)\JDFAutoOccupation.sbr"
	-@erase "$(INTDIR)\JDFAutoor.obj"
	-@erase "$(INTDIR)\JDFAutoor.sbr"
	-@erase "$(INTDIR)\JDFAutoOrderingParams.obj"
	-@erase "$(INTDIR)\JDFAutoOrderingParams.sbr"
	-@erase "$(INTDIR)\JDFAutootherwise.obj"
	-@erase "$(INTDIR)\JDFAutootherwise.sbr"
	-@erase "$(INTDIR)\JDFAutoPackingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoPackingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoPackingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPackingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPageCell.obj"
	-@erase "$(INTDIR)\JDFAutoPageCell.sbr"
	-@erase "$(INTDIR)\JDFAutoPageData.obj"
	-@erase "$(INTDIR)\JDFAutoPageData.sbr"
	-@erase "$(INTDIR)\JDFAutoPageList.obj"
	-@erase "$(INTDIR)\JDFAutoPageList.sbr"
	-@erase "$(INTDIR)\JDFAutoPallet.obj"
	-@erase "$(INTDIR)\JDFAutoPallet.sbr"
	-@erase "$(INTDIR)\JDFAutoPalletizingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPalletizingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPart.obj"
	-@erase "$(INTDIR)\JDFAutoPart.sbr"
	-@erase "$(INTDIR)\JDFAutoPartStatus.obj"
	-@erase "$(INTDIR)\JDFAutoPartStatus.sbr"
	-@erase "$(INTDIR)\JDFAutoPayment.obj"
	-@erase "$(INTDIR)\JDFAutoPayment.sbr"
	-@erase "$(INTDIR)\JDFAutoPDFInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPDFInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPDFToPSConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoPDFToPSConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPDFXParams.obj"
	-@erase "$(INTDIR)\JDFAutoPDFXParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPDLResourceAlias.obj"
	-@erase "$(INTDIR)\JDFAutoPDLResourceAlias.sbr"
	-@erase "$(INTDIR)\JDFAutoPerforate.obj"
	-@erase "$(INTDIR)\JDFAutoPerforate.sbr"
	-@erase "$(INTDIR)\JDFAutoPerforatingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPerforatingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPerformance.obj"
	-@erase "$(INTDIR)\JDFAutoPerformance.sbr"
	-@erase "$(INTDIR)\JDFAutoPerson.obj"
	-@erase "$(INTDIR)\JDFAutoPerson.sbr"
	-@erase "$(INTDIR)\JDFAutoPhaseTime.obj"
	-@erase "$(INTDIR)\JDFAutoPhaseTime.sbr"
	-@erase "$(INTDIR)\JDFAutoPipeParams.obj"
	-@erase "$(INTDIR)\JDFAutoPipeParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPixelColorant.obj"
	-@erase "$(INTDIR)\JDFAutoPixelColorant.sbr"
	-@erase "$(INTDIR)\JDFAutoPlaceHolderResource.obj"
	-@erase "$(INTDIR)\JDFAutoPlaceHolderResource.sbr"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBinding.obj"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPlateCopyParams.obj"
	-@erase "$(INTDIR)\JDFAutoPlateCopyParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPosition.obj"
	-@erase "$(INTDIR)\JDFAutoPosition.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightAction.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightAction.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightAnalysis.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightAnalysis.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightArgument.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightArgument.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightConstraint.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightConstraint.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightDetail.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightDetail.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightInstance.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightInstance.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightInstanceDetail.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightInstanceDetail.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightInventory.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightInventory.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightParams.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightProfile.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightProfile.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightReport.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightReport.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightReportRulePool.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightReportRulePool.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightValue.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightValue.sbr"
	-@erase "$(INTDIR)\JDFAutoPRError.obj"
	-@erase "$(INTDIR)\JDFAutoPRError.sbr"
	-@erase "$(INTDIR)\JDFAutoPreview.obj"
	-@erase "$(INTDIR)\JDFAutoPreview.sbr"
	-@erase "$(INTDIR)\JDFAutoPreviewGenerationParams.obj"
	-@erase "$(INTDIR)\JDFAutoPreviewGenerationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPRGroup.obj"
	-@erase "$(INTDIR)\JDFAutoPRGroup.sbr"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurence.obj"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurence.sbr"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurenceBase.obj"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurenceBase.sbr"
	-@erase "$(INTDIR)\JDFAutoPricing.obj"
	-@erase "$(INTDIR)\JDFAutoPricing.sbr"
	-@erase "$(INTDIR)\JDFAutoPrintCondition.obj"
	-@erase "$(INTDIR)\JDFAutoPrintCondition.sbr"
	-@erase "$(INTDIR)\JDFAutoPrintConditionColor.obj"
	-@erase "$(INTDIR)\JDFAutoPrintConditionColor.sbr"
	-@erase "$(INTDIR)\JDFAutoPrintRollingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPrintRollingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPRItem.obj"
	-@erase "$(INTDIR)\JDFAutoPRItem.sbr"
	-@erase "$(INTDIR)\JDFAutoPROccurence.obj"
	-@erase "$(INTDIR)\JDFAutoPROccurence.sbr"
	-@erase "$(INTDIR)\JDFAutoProcessRun.obj"
	-@erase "$(INTDIR)\JDFAutoProcessRun.sbr"
	-@erase "$(INTDIR)\JDFAutoProductionIntent.obj"
	-@erase "$(INTDIR)\JDFAutoProductionIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoProofingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoProofingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoProofingParams.obj"
	-@erase "$(INTDIR)\JDFAutoProofingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoProofItem.obj"
	-@erase "$(INTDIR)\JDFAutoProofItem.sbr"
	-@erase "$(INTDIR)\JDFAutoProperties.obj"
	-@erase "$(INTDIR)\JDFAutoProperties.sbr"
	-@erase "$(INTDIR)\JDFAutoPRRule.obj"
	-@erase "$(INTDIR)\JDFAutoPRRule.sbr"
	-@erase "$(INTDIR)\JDFAutoPRRuleAttr.obj"
	-@erase "$(INTDIR)\JDFAutoPRRuleAttr.sbr"
	-@erase "$(INTDIR)\JDFAutoPSToPDFConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoPSToPDFConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQualityControlParams.obj"
	-@erase "$(INTDIR)\JDFAutoQualityControlParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQualityControlResult.obj"
	-@erase "$(INTDIR)\JDFAutoQualityControlResult.sbr"
	-@erase "$(INTDIR)\JDFAutoQualityMeasurement.obj"
	-@erase "$(INTDIR)\JDFAutoQualityMeasurement.sbr"
	-@erase "$(INTDIR)\JDFAutoQuery.obj"
	-@erase "$(INTDIR)\JDFAutoQuery.sbr"
	-@erase "$(INTDIR)\JDFAutoQueue.obj"
	-@erase "$(INTDIR)\JDFAutoQueue.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntry.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntry.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDef.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDef.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDefList.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDefList.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPosParams.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPosParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPriParams.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPriParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueFilter.obj"
	-@erase "$(INTDIR)\JDFAutoQueueFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueSubmissionParams.obj"
	-@erase "$(INTDIR)\JDFAutoQueueSubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRegisterMark.obj"
	-@erase "$(INTDIR)\JDFAutoRegisterMark.sbr"
	-@erase "$(INTDIR)\JDFAutoRegisterRibbon.obj"
	-@erase "$(INTDIR)\JDFAutoRegisterRibbon.sbr"
	-@erase "$(INTDIR)\JDFAutoRemoved.obj"
	-@erase "$(INTDIR)\JDFAutoRemoved.sbr"
	-@erase "$(INTDIR)\JDFAutoRenderingParams.obj"
	-@erase "$(INTDIR)\JDFAutoRenderingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRequestQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFAutoRequestQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceAudit.obj"
	-@erase "$(INTDIR)\JDFAutoResourceAudit.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourceCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceDefinitionParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourceDefinitionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceInfo.obj"
	-@erase "$(INTDIR)\JDFAutoResourceInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceParam.obj"
	-@erase "$(INTDIR)\JDFAutoResourceParam.sbr"
	-@erase "$(INTDIR)\JDFAutoResourcePullParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourcePullParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourceQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResponse.obj"
	-@erase "$(INTDIR)\JDFAutoResponse.sbr"
	-@erase "$(INTDIR)\JDFAutoResubmissionParams.obj"
	-@erase "$(INTDIR)\JDFAutoResubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoReturnQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFAutoReturnQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRingBinding.obj"
	-@erase "$(INTDIR)\JDFAutoRingBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoRingBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoRingBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRollStand.obj"
	-@erase "$(INTDIR)\JDFAutoRollStand.sbr"
	-@erase "$(INTDIR)\JDFAutoRunList.obj"
	-@erase "$(INTDIR)\JDFAutoRunList.sbr"
	-@erase "$(INTDIR)\JDFAutoSaddleStitching.obj"
	-@erase "$(INTDIR)\JDFAutoSaddleStitching.sbr"
	-@erase "$(INTDIR)\JDFAutoSaddleStitchingParams.obj"
	-@erase "$(INTDIR)\JDFAutoSaddleStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoScanParams.obj"
	-@erase "$(INTDIR)\JDFAutoScanParams.sbr"
	-@erase "$(INTDIR)\JDFAutoScavengerArea.obj"
	-@erase "$(INTDIR)\JDFAutoScavengerArea.sbr"
	-@erase "$(INTDIR)\JDFAutoScore.obj"
	-@erase "$(INTDIR)\JDFAutoScore.sbr"
	-@erase "$(INTDIR)\JDFAutoScreeningIntent.obj"
	-@erase "$(INTDIR)\JDFAutoScreeningIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoScreeningParams.obj"
	-@erase "$(INTDIR)\JDFAutoScreeningParams.sbr"
	-@erase "$(INTDIR)\JDFAutoScreenSelector.obj"
	-@erase "$(INTDIR)\JDFAutoScreenSelector.sbr"
	-@erase "$(INTDIR)\JDFAutoSeparationControlParams.obj"
	-@erase "$(INTDIR)\JDFAutoSeparationControlParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSeparationSpec.obj"
	-@erase "$(INTDIR)\JDFAutoSeparationSpec.sbr"
	-@erase "$(INTDIR)\JDFAutoset.obj"
	-@erase "$(INTDIR)\JDFAutoset.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeCut.obj"
	-@erase "$(INTDIR)\JDFAutoShapeCut.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingParams.obj"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeElement.obj"
	-@erase "$(INTDIR)\JDFAutoShapeElement.sbr"
	-@erase "$(INTDIR)\JDFAutoSheet.obj"
	-@erase "$(INTDIR)\JDFAutoSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoShrinkingParams.obj"
	-@erase "$(INTDIR)\JDFAutoShrinkingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoShutDownCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoShutDownCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSideSewing.obj"
	-@erase "$(INTDIR)\JDFAutoSideSewing.sbr"
	-@erase "$(INTDIR)\JDFAutoSideSewingParams.obj"
	-@erase "$(INTDIR)\JDFAutoSideSewingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSideStitching.obj"
	-@erase "$(INTDIR)\JDFAutoSideStitching.sbr"
	-@erase "$(INTDIR)\JDFAutoSignal.obj"
	-@erase "$(INTDIR)\JDFAutoSignal.sbr"
	-@erase "$(INTDIR)\JDFAutoSignature.obj"
	-@erase "$(INTDIR)\JDFAutoSignature.sbr"
	-@erase "$(INTDIR)\JDFAutoSignatureCell.obj"
	-@erase "$(INTDIR)\JDFAutoSignatureCell.sbr"
	-@erase "$(INTDIR)\JDFAutoSizeIntent.obj"
	-@erase "$(INTDIR)\JDFAutoSizeIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoSoftCoverBinding.obj"
	-@erase "$(INTDIR)\JDFAutoSoftCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoSpawned.obj"
	-@erase "$(INTDIR)\JDFAutoSpawned.sbr"
	-@erase "$(INTDIR)\JDFAutoSpinePreparationParams.obj"
	-@erase "$(INTDIR)\JDFAutoSpinePreparationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSpineTapingParams.obj"
	-@erase "$(INTDIR)\JDFAutoSpineTapingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStackingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStackingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStatusPool.obj"
	-@erase "$(INTDIR)\JDFAutoStatusPool.sbr"
	-@erase "$(INTDIR)\JDFAutoStatusQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoStatusQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStitchingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStopPersChParams.obj"
	-@erase "$(INTDIR)\JDFAutoStopPersChParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStrap.obj"
	-@erase "$(INTDIR)\JDFAutoStrap.sbr"
	-@erase "$(INTDIR)\JDFAutoStrappingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStrappingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStringListValue.obj"
	-@erase "$(INTDIR)\JDFAutoStringListValue.sbr"
	-@erase "$(INTDIR)\JDFAutoStripBinding.obj"
	-@erase "$(INTDIR)\JDFAutoStripBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoStripBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStripBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStripCellParams.obj"
	-@erase "$(INTDIR)\JDFAutoStripCellParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStrippingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStrippingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSubmissionMethods.obj"
	-@erase "$(INTDIR)\JDFAutoSubmissionMethods.sbr"
	-@erase "$(INTDIR)\JDFAutoSubscription.obj"
	-@erase "$(INTDIR)\JDFAutoSubscription.sbr"
	-@erase "$(INTDIR)\JDFAutoSurface.obj"
	-@erase "$(INTDIR)\JDFAutoSurface.sbr"
	-@erase "$(INTDIR)\JDFAutoSystemTimeSet.obj"
	-@erase "$(INTDIR)\JDFAutoSystemTimeSet.sbr"
	-@erase "$(INTDIR)\JDFAutoTabs.obj"
	-@erase "$(INTDIR)\JDFAutoTabs.sbr"
	-@erase "$(INTDIR)\JDFAutoTape.obj"
	-@erase "$(INTDIR)\JDFAutoTape.sbr"
	-@erase "$(INTDIR)\JDFAutoTest.obj"
	-@erase "$(INTDIR)\JDFAutoTest.sbr"
	-@erase "$(INTDIR)\JDFAutoTestPool.obj"
	-@erase "$(INTDIR)\JDFAutoTestPool.sbr"
	-@erase "$(INTDIR)\JDFAutoTestRef.obj"
	-@erase "$(INTDIR)\JDFAutoTestRef.sbr"
	-@erase "$(INTDIR)\JDFAutoThinPDFParams.obj"
	-@erase "$(INTDIR)\JDFAutoThinPDFParams.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSealing.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSealing.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSealingParams.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSealingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSewing.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSewing.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSewingParams.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSewingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoTIFFEmbeddedFile.obj"
	-@erase "$(INTDIR)\JDFAutoTIFFEmbeddedFile.sbr"
	-@erase "$(INTDIR)\JDFAutoTIFFFormatParams.obj"
	-@erase "$(INTDIR)\JDFAutoTIFFFormatParams.sbr"
	-@erase "$(INTDIR)\JDFAutoTIFFtag.obj"
	-@erase "$(INTDIR)\JDFAutoTIFFtag.sbr"
	-@erase "$(INTDIR)\JDFAutoTile.obj"
	-@erase "$(INTDIR)\JDFAutoTile.sbr"
	-@erase "$(INTDIR)\JDFAutoTool.obj"
	-@erase "$(INTDIR)\JDFAutoTool.sbr"
	-@erase "$(INTDIR)\JDFAutoTrackFilter.obj"
	-@erase "$(INTDIR)\JDFAutoTrackFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoTrackResult.obj"
	-@erase "$(INTDIR)\JDFAutoTrackResult.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferCurve.obj"
	-@erase "$(INTDIR)\JDFAutoTransferCurve.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferCurvePool.obj"
	-@erase "$(INTDIR)\JDFAutoTransferCurvePool.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferCurveSet.obj"
	-@erase "$(INTDIR)\JDFAutoTransferCurveSet.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferFunctionControl.obj"
	-@erase "$(INTDIR)\JDFAutoTransferFunctionControl.sbr"
	-@erase "$(INTDIR)\JDFAutoTrappingDetails.obj"
	-@erase "$(INTDIR)\JDFAutoTrappingDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoTrappingOrder.obj"
	-@erase "$(INTDIR)\JDFAutoTrappingOrder.sbr"
	-@erase "$(INTDIR)\JDFAutoTrappingParams.obj"
	-@erase "$(INTDIR)\JDFAutoTrappingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoTrapRegion.obj"
	-@erase "$(INTDIR)\JDFAutoTrapRegion.sbr"
	-@erase "$(INTDIR)\JDFAutoTrigger.obj"
	-@erase "$(INTDIR)\JDFAutoTrigger.sbr"
	-@erase "$(INTDIR)\JDFAutoTrimmingParams.obj"
	-@erase "$(INTDIR)\JDFAutoTrimmingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoValue.obj"
	-@erase "$(INTDIR)\JDFAutoValue.sbr"
	-@erase "$(INTDIR)\JDFAutoValueLoc.obj"
	-@erase "$(INTDIR)\JDFAutoValueLoc.sbr"
	-@erase "$(INTDIR)\JDFAutoVerificationParams.obj"
	-@erase "$(INTDIR)\JDFAutoVerificationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoWakeUpCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoWakeUpCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutowhen.obj"
	-@erase "$(INTDIR)\JDFAutowhen.sbr"
	-@erase "$(INTDIR)\JDFAutoWireCombBinding.obj"
	-@erase "$(INTDIR)\JDFAutoWireCombBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoWireCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoWireCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoWrappingParams.obj"
	-@erase "$(INTDIR)\JDFAutoWrappingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoxor.obj"
	-@erase "$(INTDIR)\JDFAutoxor.sbr"
	-@erase "$(INTDIR)\JDFBand.obj"
	-@erase "$(INTDIR)\JDFBand.sbr"
	-@erase "$(INTDIR)\JDFBarcode.obj"
	-@erase "$(INTDIR)\JDFBarcode.sbr"
	-@erase "$(INTDIR)\JDFBasicPreflightTest.obj"
	-@erase "$(INTDIR)\JDFBasicPreflightTest.sbr"
	-@erase "$(INTDIR)\JDFBinderySignature.obj"
	-@erase "$(INTDIR)\JDFBinderySignature.sbr"
	-@erase "$(INTDIR)\JDFBindingIntent.obj"
	-@erase "$(INTDIR)\JDFBindingIntent.sbr"
	-@erase "$(INTDIR)\JDFBindingQualityParams.obj"
	-@erase "$(INTDIR)\JDFBindingQualityParams.sbr"
	-@erase "$(INTDIR)\JDFBindItem.obj"
	-@erase "$(INTDIR)\JDFBindItem.sbr"
	-@erase "$(INTDIR)\JDFBindList.obj"
	-@erase "$(INTDIR)\JDFBindList.sbr"
	-@erase "$(INTDIR)\JDFBlockPreparationParams.obj"
	-@erase "$(INTDIR)\JDFBlockPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFBookCase.obj"
	-@erase "$(INTDIR)\JDFBookCase.sbr"
	-@erase "$(INTDIR)\JDFBooleanEvaluation.obj"
	-@erase "$(INTDIR)\JDFBooleanEvaluation.sbr"
	-@erase "$(INTDIR)\JDFBooleanState.obj"
	-@erase "$(INTDIR)\JDFBooleanState.sbr"
	-@erase "$(INTDIR)\JDFBoxArgument.obj"
	-@erase "$(INTDIR)\JDFBoxArgument.sbr"
	-@erase "$(INTDIR)\JDFBoxPackingParams.obj"
	-@erase "$(INTDIR)\JDFBoxPackingParams.sbr"
	-@erase "$(INTDIR)\JDFBoxToBoxDifference.obj"
	-@erase "$(INTDIR)\JDFBoxToBoxDifference.sbr"
	-@erase "$(INTDIR)\JDFBufferParams.obj"
	-@erase "$(INTDIR)\JDFBufferParams.sbr"
	-@erase "$(INTDIR)\JDFBundle.obj"
	-@erase "$(INTDIR)\JDFBundle.sbr"
	-@erase "$(INTDIR)\JDFBundleItem.obj"
	-@erase "$(INTDIR)\JDFBundleItem.sbr"
	-@erase "$(INTDIR)\JDFBundlingParams.obj"
	-@erase "$(INTDIR)\JDFBundlingParams.sbr"
	-@erase "$(INTDIR)\JDFBusinessInfo.obj"
	-@erase "$(INTDIR)\JDFBusinessInfo.sbr"
	-@erase "$(INTDIR)\JDFByteMap.obj"
	-@erase "$(INTDIR)\JDFByteMap.sbr"
	-@erase "$(INTDIR)\JDFcall.obj"
	-@erase "$(INTDIR)\JDFcall.sbr"
	-@erase "$(INTDIR)\JDFCaseMakingParams.obj"
	-@erase "$(INTDIR)\JDFCaseMakingParams.sbr"
	-@erase "$(INTDIR)\JDFCasingInParams.obj"
	-@erase "$(INTDIR)\JDFCasingInParams.sbr"
	-@erase "$(INTDIR)\JDFCCITTFaxParams.obj"
	-@erase "$(INTDIR)\JDFCCITTFaxParams.sbr"
	-@erase "$(INTDIR)\JDFChangedAttribute.obj"
	-@erase "$(INTDIR)\JDFChangedAttribute.sbr"
	-@erase "$(INTDIR)\JDFChangedPath.obj"
	-@erase "$(INTDIR)\JDFChangedPath.sbr"
	-@erase "$(INTDIR)\JDFChannelBinding.obj"
	-@erase "$(INTDIR)\JDFChannelBinding.sbr"
	-@erase "$(INTDIR)\JDFChannelBindingParams.obj"
	-@erase "$(INTDIR)\JDFChannelBindingParams.sbr"
	-@erase "$(INTDIR)\JDFchoice.obj"
	-@erase "$(INTDIR)\JDFchoice.sbr"
	-@erase "$(INTDIR)\JDFCIELABMeasuringField.obj"
	-@erase "$(INTDIR)\JDFCIELABMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFCoilBinding.obj"
	-@erase "$(INTDIR)\JDFCoilBinding.sbr"
	-@erase "$(INTDIR)\JDFCoilBindingParams.obj"
	-@erase "$(INTDIR)\JDFCoilBindingParams.sbr"
	-@erase "$(INTDIR)\JDFCollatingItem.obj"
	-@erase "$(INTDIR)\JDFCollatingItem.sbr"
	-@erase "$(INTDIR)\JDFCollectingParams.obj"
	-@erase "$(INTDIR)\JDFCollectingParams.sbr"
	-@erase "$(INTDIR)\JDFColor.obj"
	-@erase "$(INTDIR)\JDFColor.sbr"
	-@erase "$(INTDIR)\JDFColorantAlias.obj"
	-@erase "$(INTDIR)\JDFColorantAlias.sbr"
	-@erase "$(INTDIR)\JDFColorantControl.obj"
	-@erase "$(INTDIR)\JDFColorantControl.sbr"
	-@erase "$(INTDIR)\JDFColorantZoneDetails.obj"
	-@erase "$(INTDIR)\JDFColorantZoneDetails.sbr"
	-@erase "$(INTDIR)\JDFColorControlStrip.obj"
	-@erase "$(INTDIR)\JDFColorControlStrip.sbr"
	-@erase "$(INTDIR)\JDFColorCorrectionOp.obj"
	-@erase "$(INTDIR)\JDFColorCorrectionOp.sbr"
	-@erase "$(INTDIR)\JDFColorCorrectionParams.obj"
	-@erase "$(INTDIR)\JDFColorCorrectionParams.sbr"
	-@erase "$(INTDIR)\JDFColorIntent.obj"
	-@erase "$(INTDIR)\JDFColorIntent.sbr"
	-@erase "$(INTDIR)\JDFColorMeasurementConditions.obj"
	-@erase "$(INTDIR)\JDFColorMeasurementConditions.sbr"
	-@erase "$(INTDIR)\JDFColorPool.obj"
	-@erase "$(INTDIR)\JDFColorPool.sbr"
	-@erase "$(INTDIR)\JDFColorSpaceConversionOp.obj"
	-@erase "$(INTDIR)\JDFColorSpaceConversionOp.sbr"
	-@erase "$(INTDIR)\JDFColorSpaceConversionParams.obj"
	-@erase "$(INTDIR)\JDFColorSpaceConversionParams.sbr"
	-@erase "$(INTDIR)\JDFColorSpaceSubstitute.obj"
	-@erase "$(INTDIR)\JDFColorSpaceSubstitute.sbr"
	-@erase "$(INTDIR)\JDFColorsUsed.obj"
	-@erase "$(INTDIR)\JDFColorsUsed.sbr"
	-@erase "$(INTDIR)\JDFComChannel.obj"
	-@erase "$(INTDIR)\JDFComChannel.sbr"
	-@erase "$(INTDIR)\JDFCommand.obj"
	-@erase "$(INTDIR)\JDFCommand.sbr"
	-@erase "$(INTDIR)\JDFComment.obj"
	-@erase "$(INTDIR)\JDFComment.sbr"
	-@erase "$(INTDIR)\JDFCompany.obj"
	-@erase "$(INTDIR)\JDFCompany.sbr"
	-@erase "$(INTDIR)\JDFComponent.obj"
	-@erase "$(INTDIR)\JDFComponent.sbr"
	-@erase "$(INTDIR)\JDFContact.obj"
	-@erase "$(INTDIR)\JDFContact.sbr"
	-@erase "$(INTDIR)\JDFContactCopyParams.obj"
	-@erase "$(INTDIR)\JDFContactCopyParams.sbr"
	-@erase "$(INTDIR)\JDFContainer.obj"
	-@erase "$(INTDIR)\JDFContainer.sbr"
	-@erase "$(INTDIR)\JDFContentObject.obj"
	-@erase "$(INTDIR)\JDFContentObject.sbr"
	-@erase "$(INTDIR)\JDFConventionalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFConventionalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFCostCenter.obj"
	-@erase "$(INTDIR)\JDFCostCenter.sbr"
	-@erase "$(INTDIR)\JDFCounterReset.obj"
	-@erase "$(INTDIR)\JDFCounterReset.sbr"
	-@erase "$(INTDIR)\JDFCoverApplicationParams.obj"
	-@erase "$(INTDIR)\JDFCoverApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFCrease.obj"
	-@erase "$(INTDIR)\JDFCrease.sbr"
	-@erase "$(INTDIR)\JDFCreasingParams.obj"
	-@erase "$(INTDIR)\JDFCreasingParams.sbr"
	-@erase "$(INTDIR)\JDFCreated.obj"
	-@erase "$(INTDIR)\JDFCreated.sbr"
	-@erase "$(INTDIR)\JDFCreditCard.obj"
	-@erase "$(INTDIR)\JDFCreditCard.sbr"
	-@erase "$(INTDIR)\JDFCustomerInfo.obj"
	-@erase "$(INTDIR)\JDFCustomerInfo.sbr"
	-@erase "$(INTDIR)\JDFCustomerMessage.obj"
	-@erase "$(INTDIR)\JDFCustomerMessage.sbr"
	-@erase "$(INTDIR)\JDFCut.obj"
	-@erase "$(INTDIR)\JDFCut.sbr"
	-@erase "$(INTDIR)\JDFCutBlock.obj"
	-@erase "$(INTDIR)\JDFCutBlock.sbr"
	-@erase "$(INTDIR)\JDFCutMark.obj"
	-@erase "$(INTDIR)\JDFCutMark.sbr"
	-@erase "$(INTDIR)\JDFCuttingParams.obj"
	-@erase "$(INTDIR)\JDFCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFDateTimeEvaluation.obj"
	-@erase "$(INTDIR)\JDFDateTimeEvaluation.sbr"
	-@erase "$(INTDIR)\JDFDateTimeRange.obj"
	-@erase "$(INTDIR)\JDFDateTimeRange.sbr"
	-@erase "$(INTDIR)\JDFDateTimeRangeList.obj"
	-@erase "$(INTDIR)\JDFDateTimeRangeList.sbr"
	-@erase "$(INTDIR)\JDFDateTimeState.obj"
	-@erase "$(INTDIR)\JDFDateTimeState.sbr"
	-@erase "$(INTDIR)\JDFDBMergeParams.obj"
	-@erase "$(INTDIR)\JDFDBMergeParams.sbr"
	-@erase "$(INTDIR)\JDFDBRules.obj"
	-@erase "$(INTDIR)\JDFDBRules.sbr"
	-@erase "$(INTDIR)\JDFDBSchema.obj"
	-@erase "$(INTDIR)\JDFDBSchema.sbr"
	-@erase "$(INTDIR)\JDFDBSelection.obj"
	-@erase "$(INTDIR)\JDFDBSelection.sbr"
	-@erase "$(INTDIR)\JDFDCTParams.obj"
	-@erase "$(INTDIR)\JDFDCTParams.sbr"
	-@erase "$(INTDIR)\JDFDeleted.obj"
	-@erase "$(INTDIR)\JDFDeleted.sbr"
	-@erase "$(INTDIR)\JDFDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFDensityMeasuringField.obj"
	-@erase "$(INTDIR)\JDFDensityMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFDependencies.obj"
	-@erase "$(INTDIR)\JDFDependencies.sbr"
	-@erase "$(INTDIR)\JDFDevCap.obj"
	-@erase "$(INTDIR)\JDFDevCap.sbr"
	-@erase "$(INTDIR)\JDFDevCaps.obj"
	-@erase "$(INTDIR)\JDFDevCaps.sbr"
	-@erase "$(INTDIR)\JDFDevelopingParams.obj"
	-@erase "$(INTDIR)\JDFDevelopingParams.sbr"
	-@erase "$(INTDIR)\JDFDevice.obj"
	-@erase "$(INTDIR)\JDFDevice.sbr"
	-@erase "$(INTDIR)\JDFDeviceCap.obj"
	-@erase "$(INTDIR)\JDFDeviceCap.sbr"
	-@erase "$(INTDIR)\JDFDeviceFilter.obj"
	-@erase "$(INTDIR)\JDFDeviceFilter.sbr"
	-@erase "$(INTDIR)\JDFDeviceInfo.obj"
	-@erase "$(INTDIR)\JDFDeviceInfo.sbr"
	-@erase "$(INTDIR)\JDFDeviceList.obj"
	-@erase "$(INTDIR)\JDFDeviceList.sbr"
	-@erase "$(INTDIR)\JDFDeviceMark.obj"
	-@erase "$(INTDIR)\JDFDeviceMark.sbr"
	-@erase "$(INTDIR)\JDFDeviceNColor.obj"
	-@erase "$(INTDIR)\JDFDeviceNColor.sbr"
	-@erase "$(INTDIR)\JDFDeviceNSpace.obj"
	-@erase "$(INTDIR)\JDFDeviceNSpace.sbr"
	-@erase "$(INTDIR)\JDFDigitalDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFDigitalDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFDigitalMedia.obj"
	-@erase "$(INTDIR)\JDFDigitalMedia.sbr"
	-@erase "$(INTDIR)\JDFDigitalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFDigitalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFDisjointing.obj"
	-@erase "$(INTDIR)\JDFDisjointing.sbr"
	-@erase "$(INTDIR)\JDFDisplayGroup.obj"
	-@erase "$(INTDIR)\JDFDisplayGroup.sbr"
	-@erase "$(INTDIR)\JDFDisplayGroupPool.obj"
	-@erase "$(INTDIR)\JDFDisplayGroupPool.sbr"
	-@erase "$(INTDIR)\JDFDisposition.obj"
	-@erase "$(INTDIR)\JDFDisposition.sbr"
	-@erase "$(INTDIR)\JDFDividingParams.obj"
	-@erase "$(INTDIR)\JDFDividingParams.sbr"
	-@erase "$(INTDIR)\JDFDoc.obj"
	-@erase "$(INTDIR)\JDFDoc.sbr"
	-@erase "$(INTDIR)\JDFDrop.obj"
	-@erase "$(INTDIR)\JDFDrop.sbr"
	-@erase "$(INTDIR)\JDFDropIntent.obj"
	-@erase "$(INTDIR)\JDFDropIntent.sbr"
	-@erase "$(INTDIR)\JDFDropItem.obj"
	-@erase "$(INTDIR)\JDFDropItem.sbr"
	-@erase "$(INTDIR)\JDFDropItemIntent.obj"
	-@erase "$(INTDIR)\JDFDropItemIntent.sbr"
	-@erase "$(INTDIR)\JDFDurationEvaluation.obj"
	-@erase "$(INTDIR)\JDFDurationEvaluation.sbr"
	-@erase "$(INTDIR)\JDFDurationRange.obj"
	-@erase "$(INTDIR)\JDFDurationRange.sbr"
	-@erase "$(INTDIR)\JDFDurationRangeList.obj"
	-@erase "$(INTDIR)\JDFDurationRangeList.sbr"
	-@erase "$(INTDIR)\JDFDurationState.obj"
	-@erase "$(INTDIR)\JDFDurationState.sbr"
	-@erase "$(INTDIR)\JDFDynamicField.obj"
	-@erase "$(INTDIR)\JDFDynamicField.sbr"
	-@erase "$(INTDIR)\JDFDynamicInput.obj"
	-@erase "$(INTDIR)\JDFDynamicInput.sbr"
	-@erase "$(INTDIR)\JDFEdgeGluing.obj"
	-@erase "$(INTDIR)\JDFEdgeGluing.sbr"
	-@erase "$(INTDIR)\JDFElement.obj"
	-@erase "$(INTDIR)\JDFElement.sbr"
	-@erase "$(INTDIR)\JDFElementColorParams.obj"
	-@erase "$(INTDIR)\JDFElementColorParams.sbr"
	-@erase "$(INTDIR)\JDFEmboss.obj"
	-@erase "$(INTDIR)\JDFEmboss.sbr"
	-@erase "$(INTDIR)\JDFEmbossingIntent.obj"
	-@erase "$(INTDIR)\JDFEmbossingIntent.sbr"
	-@erase "$(INTDIR)\JDFEmbossingItem.obj"
	-@erase "$(INTDIR)\JDFEmbossingItem.sbr"
	-@erase "$(INTDIR)\JDFEmbossingParams.obj"
	-@erase "$(INTDIR)\JDFEmbossingParams.sbr"
	-@erase "$(INTDIR)\JDFEmployee.obj"
	-@erase "$(INTDIR)\JDFEmployee.sbr"
	-@erase "$(INTDIR)\JDFEmployeeDef.obj"
	-@erase "$(INTDIR)\JDFEmployeeDef.sbr"
	-@erase "$(INTDIR)\JDFEndSheet.obj"
	-@erase "$(INTDIR)\JDFEndSheet.sbr"
	-@erase "$(INTDIR)\JDFEndSheetGluingParams.obj"
	-@erase "$(INTDIR)\JDFEndSheetGluingParams.sbr"
	-@erase "$(INTDIR)\JDFEnumerationEvaluation.obj"
	-@erase "$(INTDIR)\JDFEnumerationEvaluation.sbr"
	-@erase "$(INTDIR)\JDFEnumerationState.obj"
	-@erase "$(INTDIR)\JDFEnumerationState.sbr"
	-@erase "$(INTDIR)\JDFError.obj"
	-@erase "$(INTDIR)\JDFError.sbr"
	-@erase "$(INTDIR)\JDFEvaluation.obj"
	-@erase "$(INTDIR)\JDFEvaluation.sbr"
	-@erase "$(INTDIR)\JDFEvent.obj"
	-@erase "$(INTDIR)\JDFEvent.sbr"
	-@erase "$(INTDIR)\JDFExposedMedia.obj"
	-@erase "$(INTDIR)\JDFExposedMedia.sbr"
	-@erase "$(INTDIR)\JDFFactory.obj"
	-@erase "$(INTDIR)\JDFFactory.sbr"
	-@erase "$(INTDIR)\JDFFCNKey.obj"
	-@erase "$(INTDIR)\JDFFCNKey.sbr"
	-@erase "$(INTDIR)\JDFFeatureAttribute.obj"
	-@erase "$(INTDIR)\JDFFeatureAttribute.sbr"
	-@erase "$(INTDIR)\JDFFeaturePool.obj"
	-@erase "$(INTDIR)\JDFFeaturePool.sbr"
	-@erase "$(INTDIR)\JDFFeeder.obj"
	-@erase "$(INTDIR)\JDFFeeder.sbr"
	-@erase "$(INTDIR)\JDFFeederQualityParams.obj"
	-@erase "$(INTDIR)\JDFFeederQualityParams.sbr"
	-@erase "$(INTDIR)\JDFFeedingParams.obj"
	-@erase "$(INTDIR)\JDFFeedingParams.sbr"
	-@erase "$(INTDIR)\JDFFileAlias.obj"
	-@erase "$(INTDIR)\JDFFileAlias.sbr"
	-@erase "$(INTDIR)\JDFFileSpec.obj"
	-@erase "$(INTDIR)\JDFFileSpec.sbr"
	-@erase "$(INTDIR)\JDFFitPolicy.obj"
	-@erase "$(INTDIR)\JDFFitPolicy.sbr"
	-@erase "$(INTDIR)\JDFFlateParams.obj"
	-@erase "$(INTDIR)\JDFFlateParams.sbr"
	-@erase "$(INTDIR)\JDFFlushedResources.obj"
	-@erase "$(INTDIR)\JDFFlushedResources.sbr"
	-@erase "$(INTDIR)\JDFFlushQueueParams.obj"
	-@erase "$(INTDIR)\JDFFlushQueueParams.sbr"
	-@erase "$(INTDIR)\JDFFlushResourceParams.obj"
	-@erase "$(INTDIR)\JDFFlushResourceParams.sbr"
	-@erase "$(INTDIR)\JDFFold.obj"
	-@erase "$(INTDIR)\JDFFold.sbr"
	-@erase "$(INTDIR)\JDFFoldingIntent.obj"
	-@erase "$(INTDIR)\JDFFoldingIntent.sbr"
	-@erase "$(INTDIR)\JDFFoldingParams.obj"
	-@erase "$(INTDIR)\JDFFoldingParams.sbr"
	-@erase "$(INTDIR)\JDFFontParams.obj"
	-@erase "$(INTDIR)\JDFFontParams.sbr"
	-@erase "$(INTDIR)\JDFFontPolicy.obj"
	-@erase "$(INTDIR)\JDFFontPolicy.sbr"
	-@erase "$(INTDIR)\JDFFormatConversionParams.obj"
	-@erase "$(INTDIR)\JDFFormatConversionParams.sbr"
	-@erase "$(INTDIR)\JDFGatheringParams.obj"
	-@erase "$(INTDIR)\JDFGatheringParams.sbr"
	-@erase "$(INTDIR)\JDFGlue.obj"
	-@erase "$(INTDIR)\JDFGlue.sbr"
	-@erase "$(INTDIR)\JDFGlueApplication.obj"
	-@erase "$(INTDIR)\JDFGlueApplication.sbr"
	-@erase "$(INTDIR)\JDFGlueLine.obj"
	-@erase "$(INTDIR)\JDFGlueLine.sbr"
	-@erase "$(INTDIR)\JDFGluingParams.obj"
	-@erase "$(INTDIR)\JDFGluingParams.sbr"
	-@erase "$(INTDIR)\JDFHardCoverBinding.obj"
	-@erase "$(INTDIR)\JDFHardCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFHeadBandApplicationParams.obj"
	-@erase "$(INTDIR)\JDFHeadBandApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFHole.obj"
	-@erase "$(INTDIR)\JDFHole.sbr"
	-@erase "$(INTDIR)\JDFHoleLine.obj"
	-@erase "$(INTDIR)\JDFHoleLine.sbr"
	-@erase "$(INTDIR)\JDFHoleList.obj"
	-@erase "$(INTDIR)\JDFHoleList.sbr"
	-@erase "$(INTDIR)\JDFHoleMakingIntent.obj"
	-@erase "$(INTDIR)\JDFHoleMakingIntent.sbr"
	-@erase "$(INTDIR)\JDFHoleMakingParams.obj"
	-@erase "$(INTDIR)\JDFHoleMakingParams.sbr"
	-@erase "$(INTDIR)\JDFIcon.obj"
	-@erase "$(INTDIR)\JDFIcon.sbr"
	-@erase "$(INTDIR)\JDFIconList.obj"
	-@erase "$(INTDIR)\JDFIconList.sbr"
	-@erase "$(INTDIR)\JDFIdentificationField.obj"
	-@erase "$(INTDIR)\JDFIdentificationField.sbr"
	-@erase "$(INTDIR)\JDFIDInfo.obj"
	-@erase "$(INTDIR)\JDFIDInfo.sbr"
	-@erase "$(INTDIR)\JDFIDPCover.obj"
	-@erase "$(INTDIR)\JDFIDPCover.sbr"
	-@erase "$(INTDIR)\JDFIDPFinishing.obj"
	-@erase "$(INTDIR)\JDFIDPFinishing.sbr"
	-@erase "$(INTDIR)\JDFIDPFolding.obj"
	-@erase "$(INTDIR)\JDFIDPFolding.sbr"
	-@erase "$(INTDIR)\JDFIDPHoleMaking.obj"
	-@erase "$(INTDIR)\JDFIDPHoleMaking.sbr"
	-@erase "$(INTDIR)\JDFIDPImageShift.obj"
	-@erase "$(INTDIR)\JDFIDPImageShift.sbr"
	-@erase "$(INTDIR)\JDFIDPJobSheet.obj"
	-@erase "$(INTDIR)\JDFIDPJobSheet.sbr"
	-@erase "$(INTDIR)\JDFIDPLayout.obj"
	-@erase "$(INTDIR)\JDFIDPLayout.sbr"
	-@erase "$(INTDIR)\JDFIDPrintingParams.obj"
	-@erase "$(INTDIR)\JDFIDPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFIDPStitching.obj"
	-@erase "$(INTDIR)\JDFIDPStitching.sbr"
	-@erase "$(INTDIR)\JDFIDPTrimming.obj"
	-@erase "$(INTDIR)\JDFIDPTrimming.sbr"
	-@erase "$(INTDIR)\JDFImageCompression.obj"
	-@erase "$(INTDIR)\JDFImageCompression.sbr"
	-@erase "$(INTDIR)\JDFImageCompressionParams.obj"
	-@erase "$(INTDIR)\JDFImageCompressionParams.sbr"
	-@erase "$(INTDIR)\JDFImageReplacementParams.obj"
	-@erase "$(INTDIR)\JDFImageReplacementParams.sbr"
	-@erase "$(INTDIR)\JDFImageSetterParams.obj"
	-@erase "$(INTDIR)\JDFImageSetterParams.sbr"
	-@erase "$(INTDIR)\JDFImageShift.obj"
	-@erase "$(INTDIR)\JDFImageShift.sbr"
	-@erase "$(INTDIR)\JDFInk.obj"
	-@erase "$(INTDIR)\JDFInk.sbr"
	-@erase "$(INTDIR)\JDFInkZoneCalculationParams.obj"
	-@erase "$(INTDIR)\JDFInkZoneCalculationParams.sbr"
	-@erase "$(INTDIR)\JDFInkZoneProfile.obj"
	-@erase "$(INTDIR)\JDFInkZoneProfile.sbr"
	-@erase "$(INTDIR)\JDFInsert.obj"
	-@erase "$(INTDIR)\JDFInsert.sbr"
	-@erase "$(INTDIR)\JDFInsertingIntent.obj"
	-@erase "$(INTDIR)\JDFInsertingIntent.sbr"
	-@erase "$(INTDIR)\JDFInsertingParams.obj"
	-@erase "$(INTDIR)\JDFInsertingParams.sbr"
	-@erase "$(INTDIR)\JDFInsertList.obj"
	-@erase "$(INTDIR)\JDFInsertList.sbr"
	-@erase "$(INTDIR)\JDFInsertSheet.obj"
	-@erase "$(INTDIR)\JDFInsertSheet.sbr"
	-@erase "$(INTDIR)\JDFIntegerEvaluation.obj"
	-@erase "$(INTDIR)\JDFIntegerEvaluation.sbr"
	-@erase "$(INTDIR)\JDFIntegerRange.obj"
	-@erase "$(INTDIR)\JDFIntegerRange.sbr"
	-@erase "$(INTDIR)\JDFIntegerRangeList.obj"
	-@erase "$(INTDIR)\JDFIntegerRangeList.sbr"
	-@erase "$(INTDIR)\JDFIntegerState.obj"
	-@erase "$(INTDIR)\JDFIntegerState.sbr"
	-@erase "$(INTDIR)\JDFIntentResource.obj"
	-@erase "$(INTDIR)\JDFIntentResource.sbr"
	-@erase "$(INTDIR)\JDFInterpretedPDLData.obj"
	-@erase "$(INTDIR)\JDFInterpretedPDLData.sbr"
	-@erase "$(INTDIR)\JDFInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFIsPresentEvaluation.obj"
	-@erase "$(INTDIR)\JDFIsPresentEvaluation.sbr"
	-@erase "$(INTDIR)\JDFJacketingParams.obj"
	-@erase "$(INTDIR)\JDFJacketingParams.sbr"
	-@erase "$(INTDIR)\JDFJDFController.obj"
	-@erase "$(INTDIR)\JDFJDFController.sbr"
	-@erase "$(INTDIR)\JDFJDFService.obj"
	-@erase "$(INTDIR)\JDFJDFService.sbr"
	-@erase "$(INTDIR)\JDFJMF.obj"
	-@erase "$(INTDIR)\JDFJMF.sbr"
	-@erase "$(INTDIR)\JDFJobField.obj"
	-@erase "$(INTDIR)\JDFJobField.sbr"
	-@erase "$(INTDIR)\JDFJobPhase.obj"
	-@erase "$(INTDIR)\JDFJobPhase.sbr"
	-@erase "$(INTDIR)\JDFKnownMsgQuParams.obj"
	-@erase "$(INTDIR)\JDFKnownMsgQuParams.sbr"
	-@erase "$(INTDIR)\JDFLabelingParams.obj"
	-@erase "$(INTDIR)\JDFLabelingParams.sbr"
	-@erase "$(INTDIR)\JDFLaminatingIntent.obj"
	-@erase "$(INTDIR)\JDFLaminatingIntent.sbr"
	-@erase "$(INTDIR)\JDFLaminatingParams.obj"
	-@erase "$(INTDIR)\JDFLaminatingParams.sbr"
	-@erase "$(INTDIR)\JDFLayerDetails.obj"
	-@erase "$(INTDIR)\JDFLayerDetails.sbr"
	-@erase "$(INTDIR)\JDFLayerList.obj"
	-@erase "$(INTDIR)\JDFLayerList.sbr"
	-@erase "$(INTDIR)\JDFLayout.obj"
	-@erase "$(INTDIR)\JDFLayout.sbr"
	-@erase "$(INTDIR)\JDFLayoutElement.obj"
	-@erase "$(INTDIR)\JDFLayoutElement.sbr"
	-@erase "$(INTDIR)\JDFLayoutIntent.obj"
	-@erase "$(INTDIR)\JDFLayoutIntent.sbr"
	-@erase "$(INTDIR)\JDFLayoutPreparationParams.obj"
	-@erase "$(INTDIR)\JDFLayoutPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFLoc.obj"
	-@erase "$(INTDIR)\JDFLoc.sbr"
	-@erase "$(INTDIR)\JDFLocation.obj"
	-@erase "$(INTDIR)\JDFLocation.sbr"
	-@erase "$(INTDIR)\JDFLongFold.obj"
	-@erase "$(INTDIR)\JDFLongFold.sbr"
	-@erase "$(INTDIR)\JDFLongGlue.obj"
	-@erase "$(INTDIR)\JDFLongGlue.sbr"
	-@erase "$(INTDIR)\JDFLongitudinalRibbonOperationParams.obj"
	-@erase "$(INTDIR)\JDFLongitudinalRibbonOperationParams.sbr"
	-@erase "$(INTDIR)\JDFLongPerforate.obj"
	-@erase "$(INTDIR)\JDFLongPerforate.sbr"
	-@erase "$(INTDIR)\JDFLongSlit.obj"
	-@erase "$(INTDIR)\JDFLongSlit.sbr"
	-@erase "$(INTDIR)\JDFLZWParams.obj"
	-@erase "$(INTDIR)\JDFLZWParams.sbr"
	-@erase "$(INTDIR)\JDFmacro.obj"
	-@erase "$(INTDIR)\JDFmacro.sbr"
	-@erase "$(INTDIR)\JDFMacroPool.obj"
	-@erase "$(INTDIR)\JDFMacroPool.sbr"
	-@erase "$(INTDIR)\JDFManualLaborParams.obj"
	-@erase "$(INTDIR)\JDFManualLaborParams.sbr"
	-@erase "$(INTDIR)\JDFMarkObject.obj"
	-@erase "$(INTDIR)\JDFMarkObject.sbr"
	-@erase "$(INTDIR)\JDFMatrixEvaluation.obj"
	-@erase "$(INTDIR)\JDFMatrixEvaluation.sbr"
	-@erase "$(INTDIR)\JDFMatrixState.obj"
	-@erase "$(INTDIR)\JDFMatrixState.sbr"
	-@erase "$(INTDIR)\JDFMedia.obj"
	-@erase "$(INTDIR)\JDFMedia.sbr"
	-@erase "$(INTDIR)\JDFMediaIntent.obj"
	-@erase "$(INTDIR)\JDFMediaIntent.sbr"
	-@erase "$(INTDIR)\JDFMediaSource.obj"
	-@erase "$(INTDIR)\JDFMediaSource.sbr"
	-@erase "$(INTDIR)\JDFMerged.obj"
	-@erase "$(INTDIR)\JDFMerged.sbr"
	-@erase "$(INTDIR)\JDFMessage.obj"
	-@erase "$(INTDIR)\JDFMessage.sbr"
	-@erase "$(INTDIR)\JDFMessageElement.obj"
	-@erase "$(INTDIR)\JDFMessageElement.sbr"
	-@erase "$(INTDIR)\JDFMessageService.obj"
	-@erase "$(INTDIR)\JDFMessageService.sbr"
	-@erase "$(INTDIR)\JDFMISDetails.obj"
	-@erase "$(INTDIR)\JDFMISDetails.sbr"
	-@erase "$(INTDIR)\JDFModified.obj"
	-@erase "$(INTDIR)\JDFModified.sbr"
	-@erase "$(INTDIR)\JDFModulePhase.obj"
	-@erase "$(INTDIR)\JDFModulePhase.sbr"
	-@erase "$(INTDIR)\JDFModuleStatus.obj"
	-@erase "$(INTDIR)\JDFModuleStatus.sbr"
	-@erase "$(INTDIR)\JDFMsgFilter.obj"
	-@erase "$(INTDIR)\JDFMsgFilter.sbr"
	-@erase "$(INTDIR)\JDFNameEvaluation.obj"
	-@erase "$(INTDIR)\JDFNameEvaluation.sbr"
	-@erase "$(INTDIR)\JDFNameRangeList.obj"
	-@erase "$(INTDIR)\JDFNameRangeList.sbr"
	-@erase "$(INTDIR)\JDFNameState.obj"
	-@erase "$(INTDIR)\JDFNameState.sbr"
	-@erase "$(INTDIR)\JDFNewJDFCmdParams.obj"
	-@erase "$(INTDIR)\JDFNewJDFCmdParams.sbr"
	-@erase "$(INTDIR)\JDFNewJDFQuParams.obj"
	-@erase "$(INTDIR)\JDFNewJDFQuParams.sbr"
	-@erase "$(INTDIR)\JDFNode.obj"
	-@erase "$(INTDIR)\JDFNode.sbr"
	-@erase "$(INTDIR)\JDFNodeFactory.obj"
	-@erase "$(INTDIR)\JDFNodeFactory.sbr"
	-@erase "$(INTDIR)\JDFNodeInfo.obj"
	-@erase "$(INTDIR)\JDFNodeInfo.sbr"
	-@erase "$(INTDIR)\JDFNodeInfoCmdParams.obj"
	-@erase "$(INTDIR)\JDFNodeInfoCmdParams.sbr"
	-@erase "$(INTDIR)\JDFNodeInfoQuParams.obj"
	-@erase "$(INTDIR)\JDFNodeInfoQuParams.sbr"
	-@erase "$(INTDIR)\JDFNodeInfoResp.obj"
	-@erase "$(INTDIR)\JDFNodeInfoResp.sbr"
	-@erase "$(INTDIR)\JDFnot.obj"
	-@erase "$(INTDIR)\JDFnot.sbr"
	-@erase "$(INTDIR)\JDFNotification.obj"
	-@erase "$(INTDIR)\JDFNotification.sbr"
	-@erase "$(INTDIR)\JDFNotificationDef.obj"
	-@erase "$(INTDIR)\JDFNotificationDef.sbr"
	-@erase "$(INTDIR)\JDFNotificationFilter.obj"
	-@erase "$(INTDIR)\JDFNotificationFilter.sbr"
	-@erase "$(INTDIR)\JDFNumberEvaluation.obj"
	-@erase "$(INTDIR)\JDFNumberEvaluation.sbr"
	-@erase "$(INTDIR)\JDFNumberingIntent.obj"
	-@erase "$(INTDIR)\JDFNumberingIntent.sbr"
	-@erase "$(INTDIR)\JDFNumberingParam.obj"
	-@erase "$(INTDIR)\JDFNumberingParam.sbr"
	-@erase "$(INTDIR)\JDFNumberingParams.obj"
	-@erase "$(INTDIR)\JDFNumberingParams.sbr"
	-@erase "$(INTDIR)\JDFNumberItem.obj"
	-@erase "$(INTDIR)\JDFNumberItem.sbr"
	-@erase "$(INTDIR)\JDFNumberRangeList.obj"
	-@erase "$(INTDIR)\JDFNumberRangeList.sbr"
	-@erase "$(INTDIR)\JDFNumberState.obj"
	-@erase "$(INTDIR)\JDFNumberState.sbr"
	-@erase "$(INTDIR)\JDFNumTypeList.obj"
	-@erase "$(INTDIR)\JDFNumTypeList.sbr"
	-@erase "$(INTDIR)\JDFObjectResolution.obj"
	-@erase "$(INTDIR)\JDFObjectResolution.sbr"
	-@erase "$(INTDIR)\JDFObservationTarget.obj"
	-@erase "$(INTDIR)\JDFObservationTarget.sbr"
	-@erase "$(INTDIR)\JDFOccupation.obj"
	-@erase "$(INTDIR)\JDFOccupation.sbr"
	-@erase "$(INTDIR)\JDFor.obj"
	-@erase "$(INTDIR)\JDFor.sbr"
	-@erase "$(INTDIR)\JDFOrderingParams.obj"
	-@erase "$(INTDIR)\JDFOrderingParams.sbr"
	-@erase "$(INTDIR)\JDFotherwise.obj"
	-@erase "$(INTDIR)\JDFotherwise.sbr"
	-@erase "$(INTDIR)\JDFPackingIntent.obj"
	-@erase "$(INTDIR)\JDFPackingIntent.sbr"
	-@erase "$(INTDIR)\JDFPackingParams.obj"
	-@erase "$(INTDIR)\JDFPackingParams.sbr"
	-@erase "$(INTDIR)\JDFPageCell.obj"
	-@erase "$(INTDIR)\JDFPageCell.sbr"
	-@erase "$(INTDIR)\JDFPageData.obj"
	-@erase "$(INTDIR)\JDFPageData.sbr"
	-@erase "$(INTDIR)\JDFPageList.obj"
	-@erase "$(INTDIR)\JDFPageList.sbr"
	-@erase "$(INTDIR)\JDFPallet.obj"
	-@erase "$(INTDIR)\JDFPallet.sbr"
	-@erase "$(INTDIR)\JDFPalletizingParams.obj"
	-@erase "$(INTDIR)\JDFPalletizingParams.sbr"
	-@erase "$(INTDIR)\JDFParamsFactory.obj"
	-@erase "$(INTDIR)\JDFParamsFactory.sbr"
	-@erase "$(INTDIR)\JDFParser.obj"
	-@erase "$(INTDIR)\JDFParser.sbr"
	-@erase "$(INTDIR)\JDFPart.obj"
	-@erase "$(INTDIR)\JDFPart.sbr"
	-@erase "$(INTDIR)\JDFPartAmount.obj"
	-@erase "$(INTDIR)\JDFPartAmount.sbr"
	-@erase "$(INTDIR)\JDFPartStatus.obj"
	-@erase "$(INTDIR)\JDFPartStatus.sbr"
	-@erase "$(INTDIR)\JDFPayment.obj"
	-@erase "$(INTDIR)\JDFPayment.sbr"
	-@erase "$(INTDIR)\JDFPDFInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFPDFInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFPDFPathEvaluation.obj"
	-@erase "$(INTDIR)\JDFPDFPathEvaluation.sbr"
	-@erase "$(INTDIR)\JDFPDFPathState.obj"
	-@erase "$(INTDIR)\JDFPDFPathState.sbr"
	-@erase "$(INTDIR)\JDFPDFToPSConversionParams.obj"
	-@erase "$(INTDIR)\JDFPDFToPSConversionParams.sbr"
	-@erase "$(INTDIR)\JDFPDFXParams.obj"
	-@erase "$(INTDIR)\JDFPDFXParams.sbr"
	-@erase "$(INTDIR)\JDFPDLResourceAlias.obj"
	-@erase "$(INTDIR)\JDFPDLResourceAlias.sbr"
	-@erase "$(INTDIR)\JDFPerforate.obj"
	-@erase "$(INTDIR)\JDFPerforate.sbr"
	-@erase "$(INTDIR)\JDFPerforatingParams.obj"
	-@erase "$(INTDIR)\JDFPerforatingParams.sbr"
	-@erase "$(INTDIR)\JDFPerformance.obj"
	-@erase "$(INTDIR)\JDFPerformance.sbr"
	-@erase "$(INTDIR)\JDFPerson.obj"
	-@erase "$(INTDIR)\JDFPerson.sbr"
	-@erase "$(INTDIR)\JDFPhaseTime.obj"
	-@erase "$(INTDIR)\JDFPhaseTime.sbr"
	-@erase "$(INTDIR)\JDFPipeParams.obj"
	-@erase "$(INTDIR)\JDFPipeParams.sbr"
	-@erase "$(INTDIR)\JDFPixelColorant.obj"
	-@erase "$(INTDIR)\JDFPixelColorant.sbr"
	-@erase "$(INTDIR)\JDFPlaceHolderResource.obj"
	-@erase "$(INTDIR)\JDFPlaceHolderResource.sbr"
	-@erase "$(INTDIR)\JDFPlasticCombBinding.obj"
	-@erase "$(INTDIR)\JDFPlasticCombBinding.sbr"
	-@erase "$(INTDIR)\JDFPlasticCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFPlasticCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFPlateCopyParams.obj"
	-@erase "$(INTDIR)\JDFPlateCopyParams.sbr"
	-@erase "$(INTDIR)\JDFPool.obj"
	-@erase "$(INTDIR)\JDFPool.sbr"
	-@erase "$(INTDIR)\JDFPosition.obj"
	-@erase "$(INTDIR)\JDFPosition.sbr"
	-@erase "$(INTDIR)\JDFPreflightAction.obj"
	-@erase "$(INTDIR)\JDFPreflightAction.sbr"
	-@erase "$(INTDIR)\JDFPreflightAnalysis.obj"
	-@erase "$(INTDIR)\JDFPreflightAnalysis.sbr"
	-@erase "$(INTDIR)\JDFPreflightArgument.obj"
	-@erase "$(INTDIR)\JDFPreflightArgument.sbr"
	-@erase "$(INTDIR)\JDFPreflightConstraint.obj"
	-@erase "$(INTDIR)\JDFPreflightConstraint.sbr"
	-@erase "$(INTDIR)\JDFPreflightConstraintsPool.obj"
	-@erase "$(INTDIR)\JDFPreflightConstraintsPool.sbr"
	-@erase "$(INTDIR)\JDFPreflightDetail.obj"
	-@erase "$(INTDIR)\JDFPreflightDetail.sbr"
	-@erase "$(INTDIR)\JDFPreflightInstance.obj"
	-@erase "$(INTDIR)\JDFPreflightInstance.sbr"
	-@erase "$(INTDIR)\JDFPreflightInstanceDetail.obj"
	-@erase "$(INTDIR)\JDFPreflightInstanceDetail.sbr"
	-@erase "$(INTDIR)\JDFPreflightInventory.obj"
	-@erase "$(INTDIR)\JDFPreflightInventory.sbr"
	-@erase "$(INTDIR)\JDFPreflightParams.obj"
	-@erase "$(INTDIR)\JDFPreflightParams.sbr"
	-@erase "$(INTDIR)\JDFPreflightProfile.obj"
	-@erase "$(INTDIR)\JDFPreflightProfile.sbr"
	-@erase "$(INTDIR)\JDFPreflightReport.obj"
	-@erase "$(INTDIR)\JDFPreflightReport.sbr"
	-@erase "$(INTDIR)\JDFPreflightReportRulePool.obj"
	-@erase "$(INTDIR)\JDFPreflightReportRulePool.sbr"
	-@erase "$(INTDIR)\JDFPreflightResultsPool.obj"
	-@erase "$(INTDIR)\JDFPreflightResultsPool.sbr"
	-@erase "$(INTDIR)\JDFPreflightValue.obj"
	-@erase "$(INTDIR)\JDFPreflightValue.sbr"
	-@erase "$(INTDIR)\JDFPRError.obj"
	-@erase "$(INTDIR)\JDFPRError.sbr"
	-@erase "$(INTDIR)\JDFPreview.obj"
	-@erase "$(INTDIR)\JDFPreview.sbr"
	-@erase "$(INTDIR)\JDFPreviewGenerationParams.obj"
	-@erase "$(INTDIR)\JDFPreviewGenerationParams.sbr"
	-@erase "$(INTDIR)\JDFPRGroup.obj"
	-@erase "$(INTDIR)\JDFPRGroup.sbr"
	-@erase "$(INTDIR)\JDFPRGroupOccurence.obj"
	-@erase "$(INTDIR)\JDFPRGroupOccurence.sbr"
	-@erase "$(INTDIR)\JDFPRGroupOccurenceBase.obj"
	-@erase "$(INTDIR)\JDFPRGroupOccurenceBase.sbr"
	-@erase "$(INTDIR)\JDFPricing.obj"
	-@erase "$(INTDIR)\JDFPricing.sbr"
	-@erase "$(INTDIR)\JDFPrintCondition.obj"
	-@erase "$(INTDIR)\JDFPrintCondition.sbr"
	-@erase "$(INTDIR)\JDFPrintConditionColor.obj"
	-@erase "$(INTDIR)\JDFPrintConditionColor.sbr"
	-@erase "$(INTDIR)\JDFPrintRollingParams.obj"
	-@erase "$(INTDIR)\JDFPrintRollingParams.sbr"
	-@erase "$(INTDIR)\JDFPRItem.obj"
	-@erase "$(INTDIR)\JDFPRItem.sbr"
	-@erase "$(INTDIR)\JDFPROccurence.obj"
	-@erase "$(INTDIR)\JDFPROccurence.sbr"
	-@erase "$(INTDIR)\JDFProcessRun.obj"
	-@erase "$(INTDIR)\JDFProcessRun.sbr"
	-@erase "$(INTDIR)\JDFProductionIntent.obj"
	-@erase "$(INTDIR)\JDFProductionIntent.sbr"
	-@erase "$(INTDIR)\JDFProofingIntent.obj"
	-@erase "$(INTDIR)\JDFProofingIntent.sbr"
	-@erase "$(INTDIR)\JDFProofingParams.obj"
	-@erase "$(INTDIR)\JDFProofingParams.sbr"
	-@erase "$(INTDIR)\JDFProofItem.obj"
	-@erase "$(INTDIR)\JDFProofItem.sbr"
	-@erase "$(INTDIR)\JDFProperties.obj"
	-@erase "$(INTDIR)\JDFProperties.sbr"
	-@erase "$(INTDIR)\JDFPRRule.obj"
	-@erase "$(INTDIR)\JDFPRRule.sbr"
	-@erase "$(INTDIR)\JDFPRRuleAttr.obj"
	-@erase "$(INTDIR)\JDFPRRuleAttr.sbr"
	-@erase "$(INTDIR)\JDFPSToPDFConversionParams.obj"
	-@erase "$(INTDIR)\JDFPSToPDFConversionParams.sbr"
	-@erase "$(INTDIR)\JDFQualityControlParams.obj"
	-@erase "$(INTDIR)\JDFQualityControlParams.sbr"
	-@erase "$(INTDIR)\JDFQualityControlResult.obj"
	-@erase "$(INTDIR)\JDFQualityControlResult.sbr"
	-@erase "$(INTDIR)\JDFQualityMeasurement.obj"
	-@erase "$(INTDIR)\JDFQualityMeasurement.sbr"
	-@erase "$(INTDIR)\JDFQuery.obj"
	-@erase "$(INTDIR)\JDFQuery.sbr"
	-@erase "$(INTDIR)\JDFQueue.obj"
	-@erase "$(INTDIR)\JDFQueue.sbr"
	-@erase "$(INTDIR)\JDFQueueEntry.obj"
	-@erase "$(INTDIR)\JDFQueueEntry.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryDef.obj"
	-@erase "$(INTDIR)\JDFQueueEntryDef.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryDefList.obj"
	-@erase "$(INTDIR)\JDFQueueEntryDefList.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryPosParams.obj"
	-@erase "$(INTDIR)\JDFQueueEntryPosParams.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryPriParams.obj"
	-@erase "$(INTDIR)\JDFQueueEntryPriParams.sbr"
	-@erase "$(INTDIR)\JDFQueueFilter.obj"
	-@erase "$(INTDIR)\JDFQueueFilter.sbr"
	-@erase "$(INTDIR)\JDFQueueSubmissionParams.obj"
	-@erase "$(INTDIR)\JDFQueueSubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFRange.obj"
	-@erase "$(INTDIR)\JDFRange.sbr"
	-@erase "$(INTDIR)\JDFRangeList.obj"
	-@erase "$(INTDIR)\JDFRangeList.sbr"
	-@erase "$(INTDIR)\JDFRectangleEvaluation.obj"
	-@erase "$(INTDIR)\JDFRectangleEvaluation.sbr"
	-@erase "$(INTDIR)\JDFRectangleState.obj"
	-@erase "$(INTDIR)\JDFRectangleState.sbr"
	-@erase "$(INTDIR)\JDFRefElement.obj"
	-@erase "$(INTDIR)\JDFRefElement.sbr"
	-@erase "$(INTDIR)\JDFRegisterMark.obj"
	-@erase "$(INTDIR)\JDFRegisterMark.sbr"
	-@erase "$(INTDIR)\JDFRegisterRibbon.obj"
	-@erase "$(INTDIR)\JDFRegisterRibbon.sbr"
	-@erase "$(INTDIR)\JDFRemoved.obj"
	-@erase "$(INTDIR)\JDFRemoved.sbr"
	-@erase "$(INTDIR)\JDFRenderingParams.obj"
	-@erase "$(INTDIR)\JDFRenderingParams.sbr"
	-@erase "$(INTDIR)\JDFRequestQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFRequestQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFResource.obj"
	-@erase "$(INTDIR)\JDFResource.sbr"
	-@erase "$(INTDIR)\JDFResourceAudit.obj"
	-@erase "$(INTDIR)\JDFResourceAudit.sbr"
	-@erase "$(INTDIR)\JDFResourceCmdParams.obj"
	-@erase "$(INTDIR)\JDFResourceCmdParams.sbr"
	-@erase "$(INTDIR)\JDFResourceDefinitionParams.obj"
	-@erase "$(INTDIR)\JDFResourceDefinitionParams.sbr"
	-@erase "$(INTDIR)\JDFResourceInfo.obj"
	-@erase "$(INTDIR)\JDFResourceInfo.sbr"
	-@erase "$(INTDIR)\JDFResourceLink.obj"
	-@erase "$(INTDIR)\JDFResourceLink.sbr"
	-@erase "$(INTDIR)\JDFResourceLinkPool.obj"
	-@erase "$(INTDIR)\JDFResourceLinkPool.sbr"
	-@erase "$(INTDIR)\JDFResourceParam.obj"
	-@erase "$(INTDIR)\JDFResourceParam.sbr"
	-@erase "$(INTDIR)\JDFResourcePool.obj"
	-@erase "$(INTDIR)\JDFResourcePool.sbr"
	-@erase "$(INTDIR)\JDFResourcePullParams.obj"
	-@erase "$(INTDIR)\JDFResourcePullParams.sbr"
	-@erase "$(INTDIR)\JDFResourceQuParams.obj"
	-@erase "$(INTDIR)\JDFResourceQuParams.sbr"
	-@erase "$(INTDIR)\JDFResponse.obj"
	-@erase "$(INTDIR)\JDFResponse.sbr"
	-@erase "$(INTDIR)\JDFResubmissionParams.obj"
	-@erase "$(INTDIR)\JDFResubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFReturnQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFReturnQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFRingBinding.obj"
	-@erase "$(INTDIR)\JDFRingBinding.sbr"
	-@erase "$(INTDIR)\JDFRingBindingParams.obj"
	-@erase "$(INTDIR)\JDFRingBindingParams.sbr"
	-@erase "$(INTDIR)\JDFRollStand.obj"
	-@erase "$(INTDIR)\JDFRollStand.sbr"
	-@erase "$(INTDIR)\JDFRunElement.obj"
	-@erase "$(INTDIR)\JDFRunElement.sbr"
	-@erase "$(INTDIR)\JDFRunList.obj"
	-@erase "$(INTDIR)\JDFRunList.sbr"
	-@erase "$(INTDIR)\JDFSaddleStitching.obj"
	-@erase "$(INTDIR)\JDFSaddleStitching.sbr"
	-@erase "$(INTDIR)\JDFSaddleStitchingParams.obj"
	-@erase "$(INTDIR)\JDFSaddleStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFScanParams.obj"
	-@erase "$(INTDIR)\JDFScanParams.sbr"
	-@erase "$(INTDIR)\JDFScavengerArea.obj"
	-@erase "$(INTDIR)\JDFScavengerArea.sbr"
	-@erase "$(INTDIR)\JDFScore.obj"
	-@erase "$(INTDIR)\JDFScore.sbr"
	-@erase "$(INTDIR)\JDFScreeningIntent.obj"
	-@erase "$(INTDIR)\JDFScreeningIntent.sbr"
	-@erase "$(INTDIR)\JDFScreeningParams.obj"
	-@erase "$(INTDIR)\JDFScreeningParams.sbr"
	-@erase "$(INTDIR)\JDFScreenSelector.obj"
	-@erase "$(INTDIR)\JDFScreenSelector.sbr"
	-@erase "$(INTDIR)\JDFSeparationControlParams.obj"
	-@erase "$(INTDIR)\JDFSeparationControlParams.sbr"
	-@erase "$(INTDIR)\JDFSeparationList.obj"
	-@erase "$(INTDIR)\JDFSeparationList.sbr"
	-@erase "$(INTDIR)\JDFSeparationSpec.obj"
	-@erase "$(INTDIR)\JDFSeparationSpec.sbr"
	-@erase "$(INTDIR)\JDFset.obj"
	-@erase "$(INTDIR)\JDFset.sbr"
	-@erase "$(INTDIR)\JDFShapeCut.obj"
	-@erase "$(INTDIR)\JDFShapeCut.sbr"
	-@erase "$(INTDIR)\JDFShapeCuttingIntent.obj"
	-@erase "$(INTDIR)\JDFShapeCuttingIntent.sbr"
	-@erase "$(INTDIR)\JDFShapeCuttingParams.obj"
	-@erase "$(INTDIR)\JDFShapeCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFShapeElement.obj"
	-@erase "$(INTDIR)\JDFShapeElement.sbr"
	-@erase "$(INTDIR)\JDFShapeEvaluation.obj"
	-@erase "$(INTDIR)\JDFShapeEvaluation.sbr"
	-@erase "$(INTDIR)\JDFShapeState.obj"
	-@erase "$(INTDIR)\JDFShapeState.sbr"
	-@erase "$(INTDIR)\JDFSheet.obj"
	-@erase "$(INTDIR)\JDFSheet.sbr"
	-@erase "$(INTDIR)\JDFShrinkingParams.obj"
	-@erase "$(INTDIR)\JDFShrinkingParams.sbr"
	-@erase "$(INTDIR)\JDFShutDownCmdParams.obj"
	-@erase "$(INTDIR)\JDFShutDownCmdParams.sbr"
	-@erase "$(INTDIR)\JDFSideSewing.obj"
	-@erase "$(INTDIR)\JDFSideSewing.sbr"
	-@erase "$(INTDIR)\JDFSideSewingParams.obj"
	-@erase "$(INTDIR)\JDFSideSewingParams.sbr"
	-@erase "$(INTDIR)\JDFSideStitching.obj"
	-@erase "$(INTDIR)\JDFSideStitching.sbr"
	-@erase "$(INTDIR)\JDFSignal.obj"
	-@erase "$(INTDIR)\JDFSignal.sbr"
	-@erase "$(INTDIR)\JDFSignature.obj"
	-@erase "$(INTDIR)\JDFSignature.sbr"
	-@erase "$(INTDIR)\JDFSignatureCell.obj"
	-@erase "$(INTDIR)\JDFSignatureCell.sbr"
	-@erase "$(INTDIR)\JDFSizeIntent.obj"
	-@erase "$(INTDIR)\JDFSizeIntent.sbr"
	-@erase "$(INTDIR)\JDFSoftCoverBinding.obj"
	-@erase "$(INTDIR)\JDFSoftCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFSpan.obj"
	-@erase "$(INTDIR)\JDFSpan.sbr"
	-@erase "$(INTDIR)\JDFSpawned.obj"
	-@erase "$(INTDIR)\JDFSpawned.sbr"
	-@erase "$(INTDIR)\JDFSpinePreparationParams.obj"
	-@erase "$(INTDIR)\JDFSpinePreparationParams.sbr"
	-@erase "$(INTDIR)\JDFSpineTapingParams.obj"
	-@erase "$(INTDIR)\JDFSpineTapingParams.sbr"
	-@erase "$(INTDIR)\JDFStackingParams.obj"
	-@erase "$(INTDIR)\JDFStackingParams.sbr"
	-@erase "$(INTDIR)\JDFState.obj"
	-@erase "$(INTDIR)\JDFState.sbr"
	-@erase "$(INTDIR)\JDFStatusPool.obj"
	-@erase "$(INTDIR)\JDFStatusPool.sbr"
	-@erase "$(INTDIR)\JDFStatusQuParams.obj"
	-@erase "$(INTDIR)\JDFStatusQuParams.sbr"
	-@erase "$(INTDIR)\JDFStitchingParams.obj"
	-@erase "$(INTDIR)\JDFStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFStopPersChParams.obj"
	-@erase "$(INTDIR)\JDFStopPersChParams.sbr"
	-@erase "$(INTDIR)\JDFStrap.obj"
	-@erase "$(INTDIR)\JDFStrap.sbr"
	-@erase "$(INTDIR)\JDFStrappingParams.obj"
	-@erase "$(INTDIR)\JDFStrappingParams.sbr"
	-@erase "$(INTDIR)\JDFStringEvaluation.obj"
	-@erase "$(INTDIR)\JDFStringEvaluation.sbr"
	-@erase "$(INTDIR)\JDFStringListValue.obj"
	-@erase "$(INTDIR)\JDFStringListValue.sbr"
	-@erase "$(INTDIR)\JDFStrings.obj"
	-@erase "$(INTDIR)\JDFStrings.sbr"
	-@erase "$(INTDIR)\JDFStringState.obj"
	-@erase "$(INTDIR)\JDFStringState.sbr"
	-@erase "$(INTDIR)\JDFStripBinding.obj"
	-@erase "$(INTDIR)\JDFStripBinding.sbr"
	-@erase "$(INTDIR)\JDFStripBindingParams.obj"
	-@erase "$(INTDIR)\JDFStripBindingParams.sbr"
	-@erase "$(INTDIR)\JDFStripCellParams.obj"
	-@erase "$(INTDIR)\JDFStripCellParams.sbr"
	-@erase "$(INTDIR)\JDFStrippingParams.obj"
	-@erase "$(INTDIR)\JDFStrippingParams.sbr"
	-@erase "$(INTDIR)\JDFSubmissionMethods.obj"
	-@erase "$(INTDIR)\JDFSubmissionMethods.sbr"
	-@erase "$(INTDIR)\JDFSubscription.obj"
	-@erase "$(INTDIR)\JDFSubscription.sbr"
	-@erase "$(INTDIR)\JDFSurface.obj"
	-@erase "$(INTDIR)\JDFSurface.sbr"
	-@erase "$(INTDIR)\JDFSystemTimeSet.obj"
	-@erase "$(INTDIR)\JDFSystemTimeSet.sbr"
	-@erase "$(INTDIR)\JDFTabs.obj"
	-@erase "$(INTDIR)\JDFTabs.sbr"
	-@erase "$(INTDIR)\JDFTape.obj"
	-@erase "$(INTDIR)\JDFTape.sbr"
	-@erase "$(INTDIR)\JDFTest.obj"
	-@erase "$(INTDIR)\JDFTest.sbr"
	-@erase "$(INTDIR)\JDFTestPool.obj"
	-@erase "$(INTDIR)\JDFTestPool.sbr"
	-@erase "$(INTDIR)\JDFTestRef.obj"
	-@erase "$(INTDIR)\JDFTestRef.sbr"
	-@erase "$(INTDIR)\JDFThinPDFParams.obj"
	-@erase "$(INTDIR)\JDFThinPDFParams.sbr"
	-@erase "$(INTDIR)\JDFThreadSealing.obj"
	-@erase "$(INTDIR)\JDFThreadSealing.sbr"
	-@erase "$(INTDIR)\JDFThreadSealingParams.obj"
	-@erase "$(INTDIR)\JDFThreadSealingParams.sbr"
	-@erase "$(INTDIR)\JDFThreadSewing.obj"
	-@erase "$(INTDIR)\JDFThreadSewing.sbr"
	-@erase "$(INTDIR)\JDFThreadSewingParams.obj"
	-@erase "$(INTDIR)\JDFThreadSewingParams.sbr"
	-@erase "$(INTDIR)\JDFTIFFEmbeddedFile.obj"
	-@erase "$(INTDIR)\JDFTIFFEmbeddedFile.sbr"
	-@erase "$(INTDIR)\JDFTIFFFormatParams.obj"
	-@erase "$(INTDIR)\JDFTIFFFormatParams.sbr"
	-@erase "$(INTDIR)\JDFTIFFtag.obj"
	-@erase "$(INTDIR)\JDFTIFFtag.sbr"
	-@erase "$(INTDIR)\JDFTile.obj"
	-@erase "$(INTDIR)\JDFTile.sbr"
	-@erase "$(INTDIR)\JDFTool.obj"
	-@erase "$(INTDIR)\JDFTool.sbr"
	-@erase "$(INTDIR)\JDFTrackFilter.obj"
	-@erase "$(INTDIR)\JDFTrackFilter.sbr"
	-@erase "$(INTDIR)\JDFTrackResult.obj"
	-@erase "$(INTDIR)\JDFTrackResult.sbr"
	-@erase "$(INTDIR)\JDFTransferCurve.obj"
	-@erase "$(INTDIR)\JDFTransferCurve.sbr"
	-@erase "$(INTDIR)\JDFTransferCurvePool.obj"
	-@erase "$(INTDIR)\JDFTransferCurvePool.sbr"
	-@erase "$(INTDIR)\JDFTransferCurveSet.obj"
	-@erase "$(INTDIR)\JDFTransferCurveSet.sbr"
	-@erase "$(INTDIR)\JDFTransferFunctionControl.obj"
	-@erase "$(INTDIR)\JDFTransferFunctionControl.sbr"
	-@erase "$(INTDIR)\JDFTrappingDetails.obj"
	-@erase "$(INTDIR)\JDFTrappingDetails.sbr"
	-@erase "$(INTDIR)\JDFTrappingOrder.obj"
	-@erase "$(INTDIR)\JDFTrappingOrder.sbr"
	-@erase "$(INTDIR)\JDFTrappingParams.obj"
	-@erase "$(INTDIR)\JDFTrappingParams.sbr"
	-@erase "$(INTDIR)\JDFTrapRegion.obj"
	-@erase "$(INTDIR)\JDFTrapRegion.sbr"
	-@erase "$(INTDIR)\JDFTrigger.obj"
	-@erase "$(INTDIR)\JDFTrigger.sbr"
	-@erase "$(INTDIR)\JDFTrimmingParams.obj"
	-@erase "$(INTDIR)\JDFTrimmingParams.sbr"
	-@erase "$(INTDIR)\JDFValue.obj"
	-@erase "$(INTDIR)\JDFValue.sbr"
	-@erase "$(INTDIR)\JDFValueLoc.obj"
	-@erase "$(INTDIR)\JDFValueLoc.sbr"
	-@erase "$(INTDIR)\JDFVerificationParams.obj"
	-@erase "$(INTDIR)\JDFVerificationParams.sbr"
	-@erase "$(INTDIR)\JDFWakeUpCmdParams.obj"
	-@erase "$(INTDIR)\JDFWakeUpCmdParams.sbr"
	-@erase "$(INTDIR)\JDFwhen.obj"
	-@erase "$(INTDIR)\JDFwhen.sbr"
	-@erase "$(INTDIR)\JDFWireCombBinding.obj"
	-@erase "$(INTDIR)\JDFWireCombBinding.sbr"
	-@erase "$(INTDIR)\JDFWireCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFWireCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFWrappingParams.obj"
	-@erase "$(INTDIR)\JDFWrappingParams.sbr"
	-@erase "$(INTDIR)\JDFxor.obj"
	-@erase "$(INTDIR)\JDFxor.sbr"
	-@erase "$(INTDIR)\JDFXYPairEvaluation.obj"
	-@erase "$(INTDIR)\JDFXYPairEvaluation.sbr"
	-@erase "$(INTDIR)\JDFXYPairRangeList.obj"
	-@erase "$(INTDIR)\JDFXYPairRangeList.sbr"
	-@erase "$(INTDIR)\JDFXYPairState.obj"
	-@erase "$(INTDIR)\JDFXYPairState.sbr"
	-@erase "$(INTDIR)\KElement.obj"
	-@erase "$(INTDIR)\KElement.sbr"
	-@erase "$(INTDIR)\KElementStrings.obj"
	-@erase "$(INTDIR)\KElementStrings.sbr"
	-@erase "$(INTDIR)\MyDate.obj"
	-@erase "$(INTDIR)\MyDate.sbr"
	-@erase "$(INTDIR)\vElement.obj"
	-@erase "$(INTDIR)\vElement.sbr"
	-@erase "$(INTDIR)\XMLDoc.obj"
	-@erase "$(INTDIR)\XMLDoc.sbr"
	-@erase "$(INTDIR)\XMLDocUserData.obj"
	-@erase "$(INTDIR)\XMLDocUserData.sbr"
	-@erase "$(OUTDIR)\JDFWrapperLib.bsc"
	-@erase "$(OUTDIR)\JDFWrapperLib.lib"
	-@erase "..\..\..\Build\Win32\VC6\Release\JDFWrapperLib.idb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

MTL=midl.exe
LINK32=link.exe
CPP=xicl6.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "NDEBUG" /D "UNICODE" /D "_UNICODE" /D "_LIB" /D "WIN32" /D "JDF_TOOLS_LIB" /D "JDF_WRAPPERCORE_LIB" /D "_REENTRANT" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"..\..\..\Build\Win32\VC6\Release\JDFWrapperLib" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\JDFWrapperLib.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\JDFAmountPool.sbr" \
	"$(INTDIR)\JDFAncestor.sbr" \
	"$(INTDIR)\JDFAncestorPool.sbr" \
	"$(INTDIR)\JDFAudit.sbr" \
	"$(INTDIR)\JDFAuditPool.sbr" \
	"$(INTDIR)\JDFBarcode.sbr" \
	"$(INTDIR)\JDFBusinessInfo.sbr" \
	"$(INTDIR)\JDFComment.sbr" \
	"$(INTDIR)\JDFCounterReset.sbr" \
	"$(INTDIR)\JDFCreated.sbr" \
	"$(INTDIR)\JDFCustomerInfo.sbr" \
	"$(INTDIR)\JDFCustomerMessage.sbr" \
	"$(INTDIR)\JDFDeleted.sbr" \
	"$(INTDIR)\JDFError.sbr" \
	"$(INTDIR)\JDFEvent.sbr" \
	"$(INTDIR)\JDFFCNKey.sbr" \
	"$(INTDIR)\JDFLocation.sbr" \
	"$(INTDIR)\JDFMerged.sbr" \
	"$(INTDIR)\JDFModified.sbr" \
	"$(INTDIR)\JDFModulePhase.sbr" \
	"$(INTDIR)\JDFNode.sbr" \
	"$(INTDIR)\JDFNodeInfo.sbr" \
	"$(INTDIR)\JDFNotification.sbr" \
	"$(INTDIR)\JDFPart.sbr" \
	"$(INTDIR)\JDFPartAmount.sbr" \
	"$(INTDIR)\JDFPartStatus.sbr" \
	"$(INTDIR)\JDFPhaseTime.sbr" \
	"$(INTDIR)\JDFProcessRun.sbr" \
	"$(INTDIR)\JDFResourceAudit.sbr" \
	"$(INTDIR)\JDFResourceLinkPool.sbr" \
	"$(INTDIR)\JDFResourcePool.sbr" \
	"$(INTDIR)\JDFSpawned.sbr" \
	"$(INTDIR)\JDFStatusPool.sbr" \
	"$(INTDIR)\JDFSystemTimeSet.sbr" \
	"$(INTDIR)\JDFAcknowledge.sbr" \
	"$(INTDIR)\JDFAdded.sbr" \
	"$(INTDIR)\JDFChangedAttribute.sbr" \
	"$(INTDIR)\JDFChangedPath.sbr" \
	"$(INTDIR)\JDFCommand.sbr" \
	"$(INTDIR)\JDFDeviceFilter.sbr" \
	"$(INTDIR)\JDFDeviceInfo.sbr" \
	"$(INTDIR)\JDFDeviceList.sbr" \
	"$(INTDIR)\JDFEmployeeDef.sbr" \
	"$(INTDIR)\JDFFlushedResources.sbr" \
	"$(INTDIR)\JDFFlushQueueParams.sbr" \
	"$(INTDIR)\JDFFlushResourceParams.sbr" \
	"$(INTDIR)\JDFIDInfo.sbr" \
	"$(INTDIR)\JDFJDFController.sbr" \
	"$(INTDIR)\JDFJDFService.sbr" \
	"$(INTDIR)\JDFJMF.sbr" \
	"$(INTDIR)\JDFJobPhase.sbr" \
	"$(INTDIR)\JDFKnownMsgQuParams.sbr" \
	"$(INTDIR)\JDFMessage.sbr" \
	"$(INTDIR)\JDFMessageElement.sbr" \
	"$(INTDIR)\JDFMessageService.sbr" \
	"$(INTDIR)\JDFModuleStatus.sbr" \
	"$(INTDIR)\JDFMsgFilter.sbr" \
	"$(INTDIR)\JDFNewJDFCmdParams.sbr" \
	"$(INTDIR)\JDFNewJDFQuParams.sbr" \
	"$(INTDIR)\JDFNodeInfoCmdParams.sbr" \
	"$(INTDIR)\JDFNodeInfoQuParams.sbr" \
	"$(INTDIR)\JDFNodeInfoResp.sbr" \
	"$(INTDIR)\JDFNotificationDef.sbr" \
	"$(INTDIR)\JDFNotificationFilter.sbr" \
	"$(INTDIR)\JDFObservationTarget.sbr" \
	"$(INTDIR)\JDFOccupation.sbr" \
	"$(INTDIR)\JDFPipeParams.sbr" \
	"$(INTDIR)\JDFQuery.sbr" \
	"$(INTDIR)\JDFQueue.sbr" \
	"$(INTDIR)\JDFQueueEntry.sbr" \
	"$(INTDIR)\JDFQueueEntryDef.sbr" \
	"$(INTDIR)\JDFQueueEntryDefList.sbr" \
	"$(INTDIR)\JDFQueueEntryPosParams.sbr" \
	"$(INTDIR)\JDFQueueEntryPriParams.sbr" \
	"$(INTDIR)\JDFQueueFilter.sbr" \
	"$(INTDIR)\JDFQueueSubmissionParams.sbr" \
	"$(INTDIR)\JDFRemoved.sbr" \
	"$(INTDIR)\JDFRequestQueueEntryParams.sbr" \
	"$(INTDIR)\JDFResourceCmdParams.sbr" \
	"$(INTDIR)\JDFResourceInfo.sbr" \
	"$(INTDIR)\JDFResourcePullParams.sbr" \
	"$(INTDIR)\JDFResourceQuParams.sbr" \
	"$(INTDIR)\JDFResponse.sbr" \
	"$(INTDIR)\JDFResubmissionParams.sbr" \
	"$(INTDIR)\JDFReturnQueueEntryParams.sbr" \
	"$(INTDIR)\JDFShutDownCmdParams.sbr" \
	"$(INTDIR)\JDFSignal.sbr" \
	"$(INTDIR)\JDFStatusQuParams.sbr" \
	"$(INTDIR)\JDFStopPersChParams.sbr" \
	"$(INTDIR)\JDFSubmissionMethods.sbr" \
	"$(INTDIR)\JDFSubscription.sbr" \
	"$(INTDIR)\JDFTrackFilter.sbr" \
	"$(INTDIR)\JDFTrackResult.sbr" \
	"$(INTDIR)\JDFTrigger.sbr" \
	"$(INTDIR)\JDFWakeUpCmdParams.sbr" \
	"$(INTDIR)\JDFArtDeliveryIntent.sbr" \
	"$(INTDIR)\JDFBindingIntent.sbr" \
	"$(INTDIR)\JDFColorIntent.sbr" \
	"$(INTDIR)\JDFDeliveryIntent.sbr" \
	"$(INTDIR)\JDFEmbossingIntent.sbr" \
	"$(INTDIR)\JDFFoldingIntent.sbr" \
	"$(INTDIR)\JDFHoleMakingIntent.sbr" \
	"$(INTDIR)\JDFInsertingIntent.sbr" \
	"$(INTDIR)\JDFIntentResource.sbr" \
	"$(INTDIR)\JDFLaminatingIntent.sbr" \
	"$(INTDIR)\JDFLayoutIntent.sbr" \
	"$(INTDIR)\JDFMediaIntent.sbr" \
	"$(INTDIR)\JDFNumberingIntent.sbr" \
	"$(INTDIR)\JDFPackingIntent.sbr" \
	"$(INTDIR)\JDFProductionIntent.sbr" \
	"$(INTDIR)\JDFProofingIntent.sbr" \
	"$(INTDIR)\JDFScreeningIntent.sbr" \
	"$(INTDIR)\JDFShapeCuttingIntent.sbr" \
	"$(INTDIR)\JDFSizeIntent.sbr" \
	"$(INTDIR)\JDFSpan.sbr" \
	"$(INTDIR)\JDFAdhesiveBinding.sbr" \
	"$(INTDIR)\JDFArtDelivery.sbr" \
	"$(INTDIR)\JDFBindItem.sbr" \
	"$(INTDIR)\JDFBindList.sbr" \
	"$(INTDIR)\JDFBookCase.sbr" \
	"$(INTDIR)\JDFChannelBinding.sbr" \
	"$(INTDIR)\JDFCoilBinding.sbr" \
	"$(INTDIR)\JDFColorsUsed.sbr" \
	"$(INTDIR)\JDFCreditCard.sbr" \
	"$(INTDIR)\JDFDropIntent.sbr" \
	"$(INTDIR)\JDFDropItemIntent.sbr" \
	"$(INTDIR)\JDFEdgeGluing.sbr" \
	"$(INTDIR)\JDFEmbossingItem.sbr" \
	"$(INTDIR)\JDFHardCoverBinding.sbr" \
	"$(INTDIR)\JDFHoleList.sbr" \
	"$(INTDIR)\JDFInsert.sbr" \
	"$(INTDIR)\JDFInsertList.sbr" \
	"$(INTDIR)\JDFNumberItem.sbr" \
	"$(INTDIR)\JDFPayment.sbr" \
	"$(INTDIR)\JDFPlasticCombBinding.sbr" \
	"$(INTDIR)\JDFPricing.sbr" \
	"$(INTDIR)\JDFProofItem.sbr" \
	"$(INTDIR)\JDFRingBinding.sbr" \
	"$(INTDIR)\JDFSaddleStitching.sbr" \
	"$(INTDIR)\JDFShapeCut.sbr" \
	"$(INTDIR)\JDFSideSewing.sbr" \
	"$(INTDIR)\JDFSideStitching.sbr" \
	"$(INTDIR)\JDFSoftCoverBinding.sbr" \
	"$(INTDIR)\JDFStripBinding.sbr" \
	"$(INTDIR)\JDFTabs.sbr" \
	"$(INTDIR)\JDFTape.sbr" \
	"$(INTDIR)\JDFThreadSealing.sbr" \
	"$(INTDIR)\JDFThreadSewing.sbr" \
	"$(INTDIR)\JDFWireCombBinding.sbr" \
	"$(INTDIR)\JDFAddress.sbr" \
	"$(INTDIR)\JDFAdhesiveBindingParams.sbr" \
	"$(INTDIR)\JDFApprovalParams.sbr" \
	"$(INTDIR)\JDFApprovalSuccess.sbr" \
	"$(INTDIR)\JDFAssembly.sbr" \
	"$(INTDIR)\JDFAssetListCreationParams.sbr" \
	"$(INTDIR)\JDFAutomatedOverprintParams.sbr" \
	"$(INTDIR)\JDFBinderySignature.sbr" \
	"$(INTDIR)\JDFBlockPreparationParams.sbr" \
	"$(INTDIR)\JDFBoxPackingParams.sbr" \
	"$(INTDIR)\JDFBufferParams.sbr" \
	"$(INTDIR)\JDFBundle.sbr" \
	"$(INTDIR)\JDFBundlingParams.sbr" \
	"$(INTDIR)\JDFByteMap.sbr" \
	"$(INTDIR)\JDFCaseMakingParams.sbr" \
	"$(INTDIR)\JDFCasingInParams.sbr" \
	"$(INTDIR)\JDFChannelBindingParams.sbr" \
	"$(INTDIR)\JDFCIELABMeasuringField.sbr" \
	"$(INTDIR)\JDFCoilBindingParams.sbr" \
	"$(INTDIR)\JDFCollectingParams.sbr" \
	"$(INTDIR)\JDFColor.sbr" \
	"$(INTDIR)\JDFColorantAlias.sbr" \
	"$(INTDIR)\JDFColorantControl.sbr" \
	"$(INTDIR)\JDFColorControlStrip.sbr" \
	"$(INTDIR)\JDFColorCorrectionParams.sbr" \
	"$(INTDIR)\JDFColorMeasurementConditions.sbr" \
	"$(INTDIR)\JDFColorPool.sbr" \
	"$(INTDIR)\JDFColorSpaceConversionOp.sbr" \
	"$(INTDIR)\JDFColorSpaceConversionParams.sbr" \
	"$(INTDIR)\JDFComChannel.sbr" \
	"$(INTDIR)\JDFCompany.sbr" \
	"$(INTDIR)\JDFComponent.sbr" \
	"$(INTDIR)\JDFContact.sbr" \
	"$(INTDIR)\JDFContactCopyParams.sbr" \
	"$(INTDIR)\JDFConventionalPrintingParams.sbr" \
	"$(INTDIR)\JDFCostCenter.sbr" \
	"$(INTDIR)\JDFCoverApplicationParams.sbr" \
	"$(INTDIR)\JDFCreasingParams.sbr" \
	"$(INTDIR)\JDFCutBlock.sbr" \
	"$(INTDIR)\JDFCutMark.sbr" \
	"$(INTDIR)\JDFCuttingParams.sbr" \
	"$(INTDIR)\JDFDBMergeParams.sbr" \
	"$(INTDIR)\JDFDBRules.sbr" \
	"$(INTDIR)\JDFDBSchema.sbr" \
	"$(INTDIR)\JDFDBSelection.sbr" \
	"$(INTDIR)\JDFDeliveryParams.sbr" \
	"$(INTDIR)\JDFDensityMeasuringField.sbr" \
	"$(INTDIR)\JDFDevelopingParams.sbr" \
	"$(INTDIR)\JDFDevice.sbr" \
	"$(INTDIR)\JDFDeviceMark.sbr" \
	"$(INTDIR)\JDFDeviceNSpace.sbr" \
	"$(INTDIR)\JDFDigitalDeliveryParams.sbr" \
	"$(INTDIR)\JDFDigitalMedia.sbr" \
	"$(INTDIR)\JDFDigitalPrintingParams.sbr" \
	"$(INTDIR)\JDFDisjointing.sbr" \
	"$(INTDIR)\JDFDisposition.sbr" \
	"$(INTDIR)\JDFDividingParams.sbr" \
	"$(INTDIR)\JDFElementColorParams.sbr" \
	"$(INTDIR)\JDFEmbossingParams.sbr" \
	"$(INTDIR)\JDFEmployee.sbr" \
	"$(INTDIR)\JDFEndSheetGluingParams.sbr" \
	"$(INTDIR)\JDFExposedMedia.sbr" \
	"$(INTDIR)\JDFFeedingParams.sbr" \
	"$(INTDIR)\JDFFileSpec.sbr" \
	"$(INTDIR)\JDFFitPolicy.sbr" \
	"$(INTDIR)\JDFFold.sbr" \
	"$(INTDIR)\JDFFoldingParams.sbr" \
	"$(INTDIR)\JDFFontParams.sbr" \
	"$(INTDIR)\JDFFontPolicy.sbr" \
	"$(INTDIR)\JDFFormatConversionParams.sbr" \
	"$(INTDIR)\JDFGatheringParams.sbr" \
	"$(INTDIR)\JDFGlueApplication.sbr" \
	"$(INTDIR)\JDFGlueLine.sbr" \
	"$(INTDIR)\JDFGluingParams.sbr" \
	"$(INTDIR)\JDFHeadBandApplicationParams.sbr" \
	"$(INTDIR)\JDFHole.sbr" \
	"$(INTDIR)\JDFHoleLine.sbr" \
	"$(INTDIR)\JDFHoleMakingParams.sbr" \
	"$(INTDIR)\JDFIdentificationField.sbr" \
	"$(INTDIR)\JDFIDPrintingParams.sbr" \
	"$(INTDIR)\JDFImageCompressionParams.sbr" \
	"$(INTDIR)\JDFImageReplacementParams.sbr" \
	"$(INTDIR)\JDFImageSetterParams.sbr" \
	"$(INTDIR)\JDFInk.sbr" \
	"$(INTDIR)\JDFInkZoneCalculationParams.sbr" \
	"$(INTDIR)\JDFInkZoneProfile.sbr" \
	"$(INTDIR)\JDFInsertingParams.sbr" \
	"$(INTDIR)\JDFInsertSheet.sbr" \
	"$(INTDIR)\JDFInterpretedPDLData.sbr" \
	"$(INTDIR)\JDFInterpretingParams.sbr" \
	"$(INTDIR)\JDFJacketingParams.sbr" \
	"$(INTDIR)\JDFJobField.sbr" \
	"$(INTDIR)\JDFLabelingParams.sbr" \
	"$(INTDIR)\JDFLaminatingParams.sbr" \
	"$(INTDIR)\JDFLayout.sbr" \
	"$(INTDIR)\JDFLayoutElement.sbr" \
	"$(INTDIR)\JDFLayoutPreparationParams.sbr" \
	"$(INTDIR)\JDFLongitudinalRibbonOperationParams.sbr" \
	"$(INTDIR)\JDFManualLaborParams.sbr" \
	"$(INTDIR)\JDFMedia.sbr" \
	"$(INTDIR)\JDFMediaSource.sbr" \
	"$(INTDIR)\JDFMISDetails.sbr" \
	"$(INTDIR)\JDFNumberingParams.sbr" \
	"$(INTDIR)\JDFObjectResolution.sbr" \
	"$(INTDIR)\JDFOrderingParams.sbr" \
	"$(INTDIR)\JDFPackingParams.sbr" \
	"$(INTDIR)\JDFPageList.sbr" \
	"$(INTDIR)\JDFPallet.sbr" \
	"$(INTDIR)\JDFPalletizingParams.sbr" \
	"$(INTDIR)\JDFPDFToPSConversionParams.sbr" \
	"$(INTDIR)\JDFPDLResourceAlias.sbr" \
	"$(INTDIR)\JDFPerforatingParams.sbr" \
	"$(INTDIR)\JDFPerson.sbr" \
	"$(INTDIR)\JDFPlaceHolderResource.sbr" \
	"$(INTDIR)\JDFPlasticCombBindingParams.sbr" \
	"$(INTDIR)\JDFPlateCopyParams.sbr" \
	"$(INTDIR)\JDFPreflightAnalysis.sbr" \
	"$(INTDIR)\JDFPreflightInventory.sbr" \
	"$(INTDIR)\JDFPreflightParams.sbr" \
	"$(INTDIR)\JDFPreflightProfile.sbr" \
	"$(INTDIR)\JDFPreflightReport.sbr" \
	"$(INTDIR)\JDFPreflightReportRulePool.sbr" \
	"$(INTDIR)\JDFPreview.sbr" \
	"$(INTDIR)\JDFPreviewGenerationParams.sbr" \
	"$(INTDIR)\JDFPrintCondition.sbr" \
	"$(INTDIR)\JDFPrintRollingParams.sbr" \
	"$(INTDIR)\JDFProofingParams.sbr" \
	"$(INTDIR)\JDFPSToPDFConversionParams.sbr" \
	"$(INTDIR)\JDFQualityControlParams.sbr" \
	"$(INTDIR)\JDFQualityControlResult.sbr" \
	"$(INTDIR)\JDFRegisterMark.sbr" \
	"$(INTDIR)\JDFRegisterRibbon.sbr" \
	"$(INTDIR)\JDFRenderingParams.sbr" \
	"$(INTDIR)\JDFResourceDefinitionParams.sbr" \
	"$(INTDIR)\JDFRingBindingParams.sbr" \
	"$(INTDIR)\JDFRollStand.sbr" \
	"$(INTDIR)\JDFRunList.sbr" \
	"$(INTDIR)\JDFSaddleStitchingParams.sbr" \
	"$(INTDIR)\JDFScanParams.sbr" \
	"$(INTDIR)\JDFScavengerArea.sbr" \
	"$(INTDIR)\JDFScreeningParams.sbr" \
	"$(INTDIR)\JDFSeparationControlParams.sbr" \
	"$(INTDIR)\JDFSeparationSpec.sbr" \
	"$(INTDIR)\JDFShapeCuttingParams.sbr" \
	"$(INTDIR)\JDFSheet.sbr" \
	"$(INTDIR)\JDFShrinkingParams.sbr" \
	"$(INTDIR)\JDFSideSewingParams.sbr" \
	"$(INTDIR)\JDFSpinePreparationParams.sbr" \
	"$(INTDIR)\JDFSpineTapingParams.sbr" \
	"$(INTDIR)\JDFStackingParams.sbr" \
	"$(INTDIR)\JDFStitchingParams.sbr" \
	"$(INTDIR)\JDFStrap.sbr" \
	"$(INTDIR)\JDFStrappingParams.sbr" \
	"$(INTDIR)\JDFStripBindingParams.sbr" \
	"$(INTDIR)\JDFStrippingParams.sbr" \
	"$(INTDIR)\JDFSurface.sbr" \
	"$(INTDIR)\JDFThreadSealingParams.sbr" \
	"$(INTDIR)\JDFThreadSewingParams.sbr" \
	"$(INTDIR)\JDFTile.sbr" \
	"$(INTDIR)\JDFTool.sbr" \
	"$(INTDIR)\JDFTransferCurve.sbr" \
	"$(INTDIR)\JDFTransferCurvePool.sbr" \
	"$(INTDIR)\JDFTransferFunctionControl.sbr" \
	"$(INTDIR)\JDFTrappingDetails.sbr" \
	"$(INTDIR)\JDFTrappingParams.sbr" \
	"$(INTDIR)\JDFTrapRegion.sbr" \
	"$(INTDIR)\JDFTrimmingParams.sbr" \
	"$(INTDIR)\JDFVerificationParams.sbr" \
	"$(INTDIR)\JDFWireCombBindingParams.sbr" \
	"$(INTDIR)\JDFWrappingParams.sbr" \
	"$(INTDIR)\JDFAdvancedParams.sbr" \
	"$(INTDIR)\JDFApprovalPerson.sbr" \
	"$(INTDIR)\JDFAssemblySection.sbr" \
	"$(INTDIR)\JDFBand.sbr" \
	"$(INTDIR)\JDFBasicPreflightTest.sbr" \
	"$(INTDIR)\JDFBindingQualityParams.sbr" \
	"$(INTDIR)\JDFBoxArgument.sbr" \
	"$(INTDIR)\JDFBoxToBoxDifference.sbr" \
	"$(INTDIR)\JDFBundleItem.sbr" \
	"$(INTDIR)\JDFCCITTFaxParams.sbr" \
	"$(INTDIR)\JDFCollatingItem.sbr" \
	"$(INTDIR)\JDFColorantZoneDetails.sbr" \
	"$(INTDIR)\JDFColorCorrectionOp.sbr" \
	"$(INTDIR)\JDFColorSpaceSubstitute.sbr" \
	"$(INTDIR)\JDFContainer.sbr" \
	"$(INTDIR)\JDFContentObject.sbr" \
	"$(INTDIR)\JDFCrease.sbr" \
	"$(INTDIR)\JDFCut.sbr" \
	"$(INTDIR)\JDFDCTParams.sbr" \
	"$(INTDIR)\JDFDependencies.sbr" \
	"$(INTDIR)\JDFDeviceNColor.sbr" \
	"$(INTDIR)\JDFDrop.sbr" \
	"$(INTDIR)\JDFDropItem.sbr" \
	"$(INTDIR)\JDFDynamicField.sbr" \
	"$(INTDIR)\JDFDynamicInput.sbr" \
	"$(INTDIR)\JDFEmboss.sbr" \
	"$(INTDIR)\JDFEndSheet.sbr" \
	"$(INTDIR)\JDFFeeder.sbr" \
	"$(INTDIR)\JDFFeederQualityParams.sbr" \
	"$(INTDIR)\JDFFileAlias.sbr" \
	"$(INTDIR)\JDFFlateParams.sbr" \
	"$(INTDIR)\JDFGlue.sbr" \
	"$(INTDIR)\JDFIcon.sbr" \
	"$(INTDIR)\JDFIconList.sbr" \
	"$(INTDIR)\JDFIDPCover.sbr" \
	"$(INTDIR)\JDFIDPFinishing.sbr" \
	"$(INTDIR)\JDFIDPFolding.sbr" \
	"$(INTDIR)\JDFIDPHoleMaking.sbr" \
	"$(INTDIR)\JDFIDPImageShift.sbr" \
	"$(INTDIR)\JDFIDPJobSheet.sbr" \
	"$(INTDIR)\JDFIDPLayout.sbr" \
	"$(INTDIR)\JDFIDPStitching.sbr" \
	"$(INTDIR)\JDFIDPTrimming.sbr" \
	"$(INTDIR)\JDFImageCompression.sbr" \
	"$(INTDIR)\JDFImageShift.sbr" \
	"$(INTDIR)\JDFLayerDetails.sbr" \
	"$(INTDIR)\JDFLayerList.sbr" \
	"$(INTDIR)\JDFLongFold.sbr" \
	"$(INTDIR)\JDFLongGlue.sbr" \
	"$(INTDIR)\JDFLongPerforate.sbr" \
	"$(INTDIR)\JDFLongSlit.sbr" \
	"$(INTDIR)\JDFLZWParams.sbr" \
	"$(INTDIR)\JDFMarkObject.sbr" \
	"$(INTDIR)\JDFNumberingParam.sbr" \
	"$(INTDIR)\JDFPageCell.sbr" \
	"$(INTDIR)\JDFPageData.sbr" \
	"$(INTDIR)\JDFPDFInterpretingParams.sbr" \
	"$(INTDIR)\JDFPDFXParams.sbr" \
	"$(INTDIR)\JDFPerforate.sbr" \
	"$(INTDIR)\JDFPixelColorant.sbr" \
	"$(INTDIR)\JDFPosition.sbr" \
	"$(INTDIR)\JDFPreflightAction.sbr" \
	"$(INTDIR)\JDFPreflightArgument.sbr" \
	"$(INTDIR)\JDFPreflightConstraint.sbr" \
	"$(INTDIR)\JDFPreflightDetail.sbr" \
	"$(INTDIR)\JDFPreflightInstance.sbr" \
	"$(INTDIR)\JDFPreflightInstanceDetail.sbr" \
	"$(INTDIR)\JDFPreflightValue.sbr" \
	"$(INTDIR)\JDFPRError.sbr" \
	"$(INTDIR)\JDFPRGroup.sbr" \
	"$(INTDIR)\JDFPrintConditionColor.sbr" \
	"$(INTDIR)\JDFPRItem.sbr" \
	"$(INTDIR)\JDFPROccurence.sbr" \
	"$(INTDIR)\JDFProperties.sbr" \
	"$(INTDIR)\JDFPRRule.sbr" \
	"$(INTDIR)\JDFPRRuleAttr.sbr" \
	"$(INTDIR)\JDFQualityMeasurement.sbr" \
	"$(INTDIR)\JDFResourceParam.sbr" \
	"$(INTDIR)\JDFScore.sbr" \
	"$(INTDIR)\JDFScreenSelector.sbr" \
	"$(INTDIR)\JDFShapeElement.sbr" \
	"$(INTDIR)\JDFSignature.sbr" \
	"$(INTDIR)\JDFSignatureCell.sbr" \
	"$(INTDIR)\JDFStringListValue.sbr" \
	"$(INTDIR)\JDFStripCellParams.sbr" \
	"$(INTDIR)\JDFThinPDFParams.sbr" \
	"$(INTDIR)\JDFTIFFEmbeddedFile.sbr" \
	"$(INTDIR)\JDFTIFFFormatParams.sbr" \
	"$(INTDIR)\JDFTIFFtag.sbr" \
	"$(INTDIR)\JDFTransferCurveSet.sbr" \
	"$(INTDIR)\JDFTrappingOrder.sbr" \
	"$(INTDIR)\JDFAction.sbr" \
	"$(INTDIR)\JDFActionPool.sbr" \
	"$(INTDIR)\JDFand.sbr" \
	"$(INTDIR)\JDFBooleanEvaluation.sbr" \
	"$(INTDIR)\JDFBooleanState.sbr" \
	"$(INTDIR)\JDFcall.sbr" \
	"$(INTDIR)\JDFchoice.sbr" \
	"$(INTDIR)\JDFDateTimeEvaluation.sbr" \
	"$(INTDIR)\JDFDateTimeState.sbr" \
	"$(INTDIR)\JDFDevCap.sbr" \
	"$(INTDIR)\JDFDevCaps.sbr" \
	"$(INTDIR)\JDFDeviceCap.sbr" \
	"$(INTDIR)\JDFDisplayGroup.sbr" \
	"$(INTDIR)\JDFDisplayGroupPool.sbr" \
	"$(INTDIR)\JDFDurationEvaluation.sbr" \
	"$(INTDIR)\JDFDurationState.sbr" \
	"$(INTDIR)\JDFEnumerationEvaluation.sbr" \
	"$(INTDIR)\JDFEnumerationState.sbr" \
	"$(INTDIR)\JDFEvaluation.sbr" \
	"$(INTDIR)\JDFFeatureAttribute.sbr" \
	"$(INTDIR)\JDFFeaturePool.sbr" \
	"$(INTDIR)\JDFIntegerEvaluation.sbr" \
	"$(INTDIR)\JDFIntegerState.sbr" \
	"$(INTDIR)\JDFIsPresentEvaluation.sbr" \
	"$(INTDIR)\JDFLoc.sbr" \
	"$(INTDIR)\JDFmacro.sbr" \
	"$(INTDIR)\JDFMacroPool.sbr" \
	"$(INTDIR)\JDFMatrixEvaluation.sbr" \
	"$(INTDIR)\JDFMatrixState.sbr" \
	"$(INTDIR)\JDFNameEvaluation.sbr" \
	"$(INTDIR)\JDFNameState.sbr" \
	"$(INTDIR)\JDFnot.sbr" \
	"$(INTDIR)\JDFNumberEvaluation.sbr" \
	"$(INTDIR)\JDFNumberState.sbr" \
	"$(INTDIR)\JDFor.sbr" \
	"$(INTDIR)\JDFotherwise.sbr" \
	"$(INTDIR)\JDFPDFPathEvaluation.sbr" \
	"$(INTDIR)\JDFPDFPathState.sbr" \
	"$(INTDIR)\JDFPerformance.sbr" \
	"$(INTDIR)\JDFRectangleEvaluation.sbr" \
	"$(INTDIR)\JDFRectangleState.sbr" \
	"$(INTDIR)\JDFset.sbr" \
	"$(INTDIR)\JDFShapeEvaluation.sbr" \
	"$(INTDIR)\JDFShapeState.sbr" \
	"$(INTDIR)\JDFState.sbr" \
	"$(INTDIR)\JDFStringEvaluation.sbr" \
	"$(INTDIR)\JDFStringState.sbr" \
	"$(INTDIR)\JDFTest.sbr" \
	"$(INTDIR)\JDFTestPool.sbr" \
	"$(INTDIR)\JDFTestRef.sbr" \
	"$(INTDIR)\JDFValue.sbr" \
	"$(INTDIR)\JDFValueLoc.sbr" \
	"$(INTDIR)\JDFwhen.sbr" \
	"$(INTDIR)\JDFxor.sbr" \
	"$(INTDIR)\JDFXYPairEvaluation.sbr" \
	"$(INTDIR)\JDFXYPairState.sbr" \
	"$(INTDIR)\JDFDoc.sbr" \
	"$(INTDIR)\JDFElement.sbr" \
	"$(INTDIR)\JDFFactory.sbr" \
	"$(INTDIR)\JDFNodeFactory.sbr" \
	"$(INTDIR)\JDFParamsFactory.sbr" \
	"$(INTDIR)\JDFPool.sbr" \
	"$(INTDIR)\JDFRefElement.sbr" \
	"$(INTDIR)\JDFResource.sbr" \
	"$(INTDIR)\JDFResourceLink.sbr" \
	"$(INTDIR)\JDFRunElement.sbr" \
	"$(INTDIR)\JDFSeparationList.sbr" \
	"$(INTDIR)\JDFStrings.sbr" \
	"$(INTDIR)\JDFAutoAmountPool.sbr" \
	"$(INTDIR)\JDFAutoAncestor.sbr" \
	"$(INTDIR)\JDFAutoAncestorPool.sbr" \
	"$(INTDIR)\JDFAutoBarcode.sbr" \
	"$(INTDIR)\JDFAutoBusinessInfo.sbr" \
	"$(INTDIR)\JDFAutoComment.sbr" \
	"$(INTDIR)\JDFAutoCounterReset.sbr" \
	"$(INTDIR)\JDFAutoCreated.sbr" \
	"$(INTDIR)\JDFAutoCustomerInfo.sbr" \
	"$(INTDIR)\JDFAutoCustomerMessage.sbr" \
	"$(INTDIR)\JDFAutoDeleted.sbr" \
	"$(INTDIR)\JDFAutoError.sbr" \
	"$(INTDIR)\JDFAutoEvent.sbr" \
	"$(INTDIR)\JDFAutoFCNKey.sbr" \
	"$(INTDIR)\JDFAutoLocation.sbr" \
	"$(INTDIR)\JDFAutoMerged.sbr" \
	"$(INTDIR)\JDFAutoModified.sbr" \
	"$(INTDIR)\JDFAutoModulePhase.sbr" \
	"$(INTDIR)\JDFAutoNodeInfo.sbr" \
	"$(INTDIR)\JDFAutoNotification.sbr" \
	"$(INTDIR)\JDFAutoPart.sbr" \
	"$(INTDIR)\JDFAutoPartStatus.sbr" \
	"$(INTDIR)\JDFAutoPhaseTime.sbr" \
	"$(INTDIR)\JDFAutoProcessRun.sbr" \
	"$(INTDIR)\JDFAutoResourceAudit.sbr" \
	"$(INTDIR)\JDFAutoSpawned.sbr" \
	"$(INTDIR)\JDFAutoStatusPool.sbr" \
	"$(INTDIR)\JDFAutoSystemTimeSet.sbr" \
	"$(INTDIR)\JDFAutoAcknowledge.sbr" \
	"$(INTDIR)\JDFAutoAdded.sbr" \
	"$(INTDIR)\JDFAutoChangedAttribute.sbr" \
	"$(INTDIR)\JDFAutoChangedPath.sbr" \
	"$(INTDIR)\JDFAutoCommand.sbr" \
	"$(INTDIR)\JDFAutoDeviceFilter.sbr" \
	"$(INTDIR)\JDFAutoDeviceInfo.sbr" \
	"$(INTDIR)\JDFAutoDeviceList.sbr" \
	"$(INTDIR)\JDFAutoEmployeeDef.sbr" \
	"$(INTDIR)\JDFAutoFlushedResources.sbr" \
	"$(INTDIR)\JDFAutoFlushQueueParams.sbr" \
	"$(INTDIR)\JDFAutoFlushResourceParams.sbr" \
	"$(INTDIR)\JDFAutoIDInfo.sbr" \
	"$(INTDIR)\JDFAutoJDFController.sbr" \
	"$(INTDIR)\JDFAutoJDFService.sbr" \
	"$(INTDIR)\JDFAutoJMF.sbr" \
	"$(INTDIR)\JDFAutoJobPhase.sbr" \
	"$(INTDIR)\JDFAutoKnownMsgQuParams.sbr" \
	"$(INTDIR)\JDFAutoMessage.sbr" \
	"$(INTDIR)\JDFAutoMessageService.sbr" \
	"$(INTDIR)\JDFAutoModuleStatus.sbr" \
	"$(INTDIR)\JDFAutoMsgFilter.sbr" \
	"$(INTDIR)\JDFAutoNewJDFCmdParams.sbr" \
	"$(INTDIR)\JDFAutoNewJDFQuParams.sbr" \
	"$(INTDIR)\JDFAutoNodeInfoCmdParams.sbr" \
	"$(INTDIR)\JDFAutoNodeInfoQuParams.sbr" \
	"$(INTDIR)\JDFAutoNodeInfoResp.sbr" \
	"$(INTDIR)\JDFAutoNotificationDef.sbr" \
	"$(INTDIR)\JDFAutoNotificationFilter.sbr" \
	"$(INTDIR)\JDFAutoObservationTarget.sbr" \
	"$(INTDIR)\JDFAutoOccupation.sbr" \
	"$(INTDIR)\JDFAutoPipeParams.sbr" \
	"$(INTDIR)\JDFAutoQuery.sbr" \
	"$(INTDIR)\JDFAutoQueue.sbr" \
	"$(INTDIR)\JDFAutoQueueEntry.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryDef.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryDefList.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryPosParams.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryPriParams.sbr" \
	"$(INTDIR)\JDFAutoQueueFilter.sbr" \
	"$(INTDIR)\JDFAutoQueueSubmissionParams.sbr" \
	"$(INTDIR)\JDFAutoRemoved.sbr" \
	"$(INTDIR)\JDFAutoRequestQueueEntryParams.sbr" \
	"$(INTDIR)\JDFAutoResourceCmdParams.sbr" \
	"$(INTDIR)\JDFAutoResourceInfo.sbr" \
	"$(INTDIR)\JDFAutoResourcePullParams.sbr" \
	"$(INTDIR)\JDFAutoResourceQuParams.sbr" \
	"$(INTDIR)\JDFAutoResponse.sbr" \
	"$(INTDIR)\JDFAutoResubmissionParams.sbr" \
	"$(INTDIR)\JDFAutoReturnQueueEntryParams.sbr" \
	"$(INTDIR)\JDFAutoShutDownCmdParams.sbr" \
	"$(INTDIR)\JDFAutoSignal.sbr" \
	"$(INTDIR)\JDFAutoStatusQuParams.sbr" \
	"$(INTDIR)\JDFAutoStopPersChParams.sbr" \
	"$(INTDIR)\JDFAutoSubmissionMethods.sbr" \
	"$(INTDIR)\JDFAutoSubscription.sbr" \
	"$(INTDIR)\JDFAutoTrackFilter.sbr" \
	"$(INTDIR)\JDFAutoTrackResult.sbr" \
	"$(INTDIR)\JDFAutoTrigger.sbr" \
	"$(INTDIR)\JDFAutoWakeUpCmdParams.sbr" \
	"$(INTDIR)\JDFAutoArtDeliveryIntent.sbr" \
	"$(INTDIR)\JDFAutoBindingIntent.sbr" \
	"$(INTDIR)\JDFAutoColorIntent.sbr" \
	"$(INTDIR)\JDFAutoDeliveryIntent.sbr" \
	"$(INTDIR)\JDFAutoEmbossingIntent.sbr" \
	"$(INTDIR)\JDFAutoFoldingIntent.sbr" \
	"$(INTDIR)\JDFAutoHoleMakingIntent.sbr" \
	"$(INTDIR)\JDFAutoInsertingIntent.sbr" \
	"$(INTDIR)\JDFAutoLaminatingIntent.sbr" \
	"$(INTDIR)\JDFAutoLayoutIntent.sbr" \
	"$(INTDIR)\JDFAutoMediaIntent.sbr" \
	"$(INTDIR)\JDFAutoNumberingIntent.sbr" \
	"$(INTDIR)\JDFAutoPackingIntent.sbr" \
	"$(INTDIR)\JDFAutoProductionIntent.sbr" \
	"$(INTDIR)\JDFAutoProofingIntent.sbr" \
	"$(INTDIR)\JDFAutoScreeningIntent.sbr" \
	"$(INTDIR)\JDFAutoShapeCuttingIntent.sbr" \
	"$(INTDIR)\JDFAutoSizeIntent.sbr" \
	"$(INTDIR)\JDFAutoAdhesiveBinding.sbr" \
	"$(INTDIR)\JDFAutoArtDelivery.sbr" \
	"$(INTDIR)\JDFAutoBindItem.sbr" \
	"$(INTDIR)\JDFAutoBindList.sbr" \
	"$(INTDIR)\JDFAutoBookCase.sbr" \
	"$(INTDIR)\JDFAutoChannelBinding.sbr" \
	"$(INTDIR)\JDFAutoCoilBinding.sbr" \
	"$(INTDIR)\JDFAutoColorsUsed.sbr" \
	"$(INTDIR)\JDFAutoCreditCard.sbr" \
	"$(INTDIR)\JDFAutoDropIntent.sbr" \
	"$(INTDIR)\JDFAutoDropItemIntent.sbr" \
	"$(INTDIR)\JDFAutoEdgeGluing.sbr" \
	"$(INTDIR)\JDFAutoEmbossingItem.sbr" \
	"$(INTDIR)\JDFAutoHardCoverBinding.sbr" \
	"$(INTDIR)\JDFAutoHoleList.sbr" \
	"$(INTDIR)\JDFAutoInsert.sbr" \
	"$(INTDIR)\JDFAutoInsertList.sbr" \
	"$(INTDIR)\JDFAutoNumberItem.sbr" \
	"$(INTDIR)\JDFAutoPayment.sbr" \
	"$(INTDIR)\JDFAutoPlasticCombBinding.sbr" \
	"$(INTDIR)\JDFAutoPricing.sbr" \
	"$(INTDIR)\JDFAutoProofItem.sbr" \
	"$(INTDIR)\JDFAutoRingBinding.sbr" \
	"$(INTDIR)\JDFAutoSaddleStitching.sbr" \
	"$(INTDIR)\JDFAutoShapeCut.sbr" \
	"$(INTDIR)\JDFAutoSideSewing.sbr" \
	"$(INTDIR)\JDFAutoSideStitching.sbr" \
	"$(INTDIR)\JDFAutoSoftCoverBinding.sbr" \
	"$(INTDIR)\JDFAutoStripBinding.sbr" \
	"$(INTDIR)\JDFAutoTabs.sbr" \
	"$(INTDIR)\JDFAutoTape.sbr" \
	"$(INTDIR)\JDFAutoThreadSealing.sbr" \
	"$(INTDIR)\JDFAutoThreadSewing.sbr" \
	"$(INTDIR)\JDFAutoWireCombBinding.sbr" \
	"$(INTDIR)\JDFAutoAddress.sbr" \
	"$(INTDIR)\JDFAutoAdhesiveBindingParams.sbr" \
	"$(INTDIR)\JDFAutoApprovalParams.sbr" \
	"$(INTDIR)\JDFAutoApprovalSuccess.sbr" \
	"$(INTDIR)\JDFAutoAssembly.sbr" \
	"$(INTDIR)\JDFAutoAssetListCreationParams.sbr" \
	"$(INTDIR)\JDFAutoAutomatedOverprintParams.sbr" \
	"$(INTDIR)\JDFAutoBinderySignature.sbr" \
	"$(INTDIR)\JDFAutoBlockPreparationParams.sbr" \
	"$(INTDIR)\JDFAutoBoxPackingParams.sbr" \
	"$(INTDIR)\JDFAutoBufferParams.sbr" \
	"$(INTDIR)\JDFAutoBundle.sbr" \
	"$(INTDIR)\JDFAutoBundlingParams.sbr" \
	"$(INTDIR)\JDFAutoByteMap.sbr" \
	"$(INTDIR)\JDFAutoCaseMakingParams.sbr" \
	"$(INTDIR)\JDFAutoCasingInParams.sbr" \
	"$(INTDIR)\JDFAutoChannelBindingParams.sbr" \
	"$(INTDIR)\JDFAutoCIELABMeasuringField.sbr" \
	"$(INTDIR)\JDFAutoCoilBindingParams.sbr" \
	"$(INTDIR)\JDFAutoCollectingParams.sbr" \
	"$(INTDIR)\JDFAutoColor.sbr" \
	"$(INTDIR)\JDFAutoColorantAlias.sbr" \
	"$(INTDIR)\JDFAutoColorantControl.sbr" \
	"$(INTDIR)\JDFAutoColorControlStrip.sbr" \
	"$(INTDIR)\JDFAutoColorCorrectionParams.sbr" \
	"$(INTDIR)\JDFAutoColorMeasurementConditions.sbr" \
	"$(INTDIR)\JDFAutoColorPool.sbr" \
	"$(INTDIR)\JDFAutoColorSpaceConversionOp.sbr" \
	"$(INTDIR)\JDFAutoColorSpaceConversionParams.sbr" \
	"$(INTDIR)\JDFAutoComChannel.sbr" \
	"$(INTDIR)\JDFAutoCompany.sbr" \
	"$(INTDIR)\JDFAutoComponent.sbr" \
	"$(INTDIR)\JDFAutoContact.sbr" \
	"$(INTDIR)\JDFAutoContactCopyParams.sbr" \
	"$(INTDIR)\JDFAutoConventionalPrintingParams.sbr" \
	"$(INTDIR)\JDFAutoCostCenter.sbr" \
	"$(INTDIR)\JDFAutoCoverApplicationParams.sbr" \
	"$(INTDIR)\JDFAutoCreasingParams.sbr" \
	"$(INTDIR)\JDFAutoCutBlock.sbr" \
	"$(INTDIR)\JDFAutoCutMark.sbr" \
	"$(INTDIR)\JDFAutoCuttingParams.sbr" \
	"$(INTDIR)\JDFAutoDBMergeParams.sbr" \
	"$(INTDIR)\JDFAutoDBRules.sbr" \
	"$(INTDIR)\JDFAutoDBSchema.sbr" \
	"$(INTDIR)\JDFAutoDBSelection.sbr" \
	"$(INTDIR)\JDFAutoDeliveryParams.sbr" \
	"$(INTDIR)\JDFAutoDensityMeasuringField.sbr" \
	"$(INTDIR)\JDFAutoDevelopingParams.sbr" \
	"$(INTDIR)\JDFAutoDevice.sbr" \
	"$(INTDIR)\JDFAutoDeviceMark.sbr" \
	"$(INTDIR)\JDFAutoDeviceNSpace.sbr" \
	"$(INTDIR)\JDFAutoDigitalDeliveryParams.sbr" \
	"$(INTDIR)\JDFAutoDigitalMedia.sbr" \
	"$(INTDIR)\JDFAutoDigitalPrintingParams.sbr" \
	"$(INTDIR)\JDFAutoDisjointing.sbr" \
	"$(INTDIR)\JDFAutoDisposition.sbr" \
	"$(INTDIR)\JDFAutoDividingParams.sbr" \
	"$(INTDIR)\JDFAutoElementColorParams.sbr" \
	"$(INTDIR)\JDFAutoEmbossingParams.sbr" \
	"$(INTDIR)\JDFAutoEmployee.sbr" \
	"$(INTDIR)\JDFAutoEndSheetGluingParams.sbr" \
	"$(INTDIR)\JDFAutoExposedMedia.sbr" \
	"$(INTDIR)\JDFAutoFeedingParams.sbr" \
	"$(INTDIR)\JDFAutoFileSpec.sbr" \
	"$(INTDIR)\JDFAutoFitPolicy.sbr" \
	"$(INTDIR)\JDFAutoFold.sbr" \
	"$(INTDIR)\JDFAutoFoldingParams.sbr" \
	"$(INTDIR)\JDFAutoFontParams.sbr" \
	"$(INTDIR)\JDFAutoFontPolicy.sbr" \
	"$(INTDIR)\JDFAutoFormatConversionParams.sbr" \
	"$(INTDIR)\JDFAutoGatheringParams.sbr" \
	"$(INTDIR)\JDFAutoGlueApplication.sbr" \
	"$(INTDIR)\JDFAutoGlueLine.sbr" \
	"$(INTDIR)\JDFAutoGluingParams.sbr" \
	"$(INTDIR)\JDFAutoHeadBandApplicationParams.sbr" \
	"$(INTDIR)\JDFAutoHole.sbr" \
	"$(INTDIR)\JDFAutoHoleLine.sbr" \
	"$(INTDIR)\JDFAutoHoleMakingParams.sbr" \
	"$(INTDIR)\JDFAutoIdentificationField.sbr" \
	"$(INTDIR)\JDFAutoIDPrintingParams.sbr" \
	"$(INTDIR)\JDFAutoImageCompressionParams.sbr" \
	"$(INTDIR)\JDFAutoImageReplacementParams.sbr" \
	"$(INTDIR)\JDFAutoImageSetterParams.sbr" \
	"$(INTDIR)\JDFAutoInk.sbr" \
	"$(INTDIR)\JDFAutoInkZoneCalculationParams.sbr" \
	"$(INTDIR)\JDFAutoInkZoneProfile.sbr" \
	"$(INTDIR)\JDFAutoInsertingParams.sbr" \
	"$(INTDIR)\JDFAutoInsertSheet.sbr" \
	"$(INTDIR)\JDFAutoInterpretedPDLData.sbr" \
	"$(INTDIR)\JDFAutoInterpretingParams.sbr" \
	"$(INTDIR)\JDFAutoJacketingParams.sbr" \
	"$(INTDIR)\JDFAutoJobField.sbr" \
	"$(INTDIR)\JDFAutoLabelingParams.sbr" \
	"$(INTDIR)\JDFAutoLaminatingParams.sbr" \
	"$(INTDIR)\JDFAutoLayout.sbr" \
	"$(INTDIR)\JDFAutoLayoutElement.sbr" \
	"$(INTDIR)\JDFAutoLayoutPreparationParams.sbr" \
	"$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.sbr" \
	"$(INTDIR)\JDFAutoManualLaborParams.sbr" \
	"$(INTDIR)\JDFAutoMedia.sbr" \
	"$(INTDIR)\JDFAutoMediaSource.sbr" \
	"$(INTDIR)\JDFAutoMISDetails.sbr" \
	"$(INTDIR)\JDFAutoNumberingParams.sbr" \
	"$(INTDIR)\JDFAutoObjectResolution.sbr" \
	"$(INTDIR)\JDFAutoOrderingParams.sbr" \
	"$(INTDIR)\JDFAutoPackingParams.sbr" \
	"$(INTDIR)\JDFAutoPageList.sbr" \
	"$(INTDIR)\JDFAutoPallet.sbr" \
	"$(INTDIR)\JDFAutoPalletizingParams.sbr" \
	"$(INTDIR)\JDFAutoPDFToPSConversionParams.sbr" \
	"$(INTDIR)\JDFAutoPDLResourceAlias.sbr" \
	"$(INTDIR)\JDFAutoPerforatingParams.sbr" \
	"$(INTDIR)\JDFAutoPerson.sbr" \
	"$(INTDIR)\JDFAutoPlaceHolderResource.sbr" \
	"$(INTDIR)\JDFAutoPlasticCombBindingParams.sbr" \
	"$(INTDIR)\JDFAutoPlateCopyParams.sbr" \
	"$(INTDIR)\JDFAutoPreflightAnalysis.sbr" \
	"$(INTDIR)\JDFAutoPreflightInventory.sbr" \
	"$(INTDIR)\JDFAutoPreflightParams.sbr" \
	"$(INTDIR)\JDFAutoPreflightProfile.sbr" \
	"$(INTDIR)\JDFAutoPreflightReport.sbr" \
	"$(INTDIR)\JDFAutoPreflightReportRulePool.sbr" \
	"$(INTDIR)\JDFAutoPreview.sbr" \
	"$(INTDIR)\JDFAutoPreviewGenerationParams.sbr" \
	"$(INTDIR)\JDFAutoPrintCondition.sbr" \
	"$(INTDIR)\JDFAutoPrintRollingParams.sbr" \
	"$(INTDIR)\JDFAutoProofingParams.sbr" \
	"$(INTDIR)\JDFAutoPSToPDFConversionParams.sbr" \
	"$(INTDIR)\JDFAutoQualityControlParams.sbr" \
	"$(INTDIR)\JDFAutoQualityControlResult.sbr" \
	"$(INTDIR)\JDFAutoRegisterMark.sbr" \
	"$(INTDIR)\JDFAutoRegisterRibbon.sbr" \
	"$(INTDIR)\JDFAutoRenderingParams.sbr" \
	"$(INTDIR)\JDFAutoResourceDefinitionParams.sbr" \
	"$(INTDIR)\JDFAutoRingBindingParams.sbr" \
	"$(INTDIR)\JDFAutoRollStand.sbr" \
	"$(INTDIR)\JDFAutoRunList.sbr" \
	"$(INTDIR)\JDFAutoSaddleStitchingParams.sbr" \
	"$(INTDIR)\JDFAutoScanParams.sbr" \
	"$(INTDIR)\JDFAutoScavengerArea.sbr" \
	"$(INTDIR)\JDFAutoScreeningParams.sbr" \
	"$(INTDIR)\JDFAutoSeparationControlParams.sbr" \
	"$(INTDIR)\JDFAutoSeparationSpec.sbr" \
	"$(INTDIR)\JDFAutoShapeCuttingParams.sbr" \
	"$(INTDIR)\JDFAutoSheet.sbr" \
	"$(INTDIR)\JDFAutoShrinkingParams.sbr" \
	"$(INTDIR)\JDFAutoSideSewingParams.sbr" \
	"$(INTDIR)\JDFAutoSpinePreparationParams.sbr" \
	"$(INTDIR)\JDFAutoSpineTapingParams.sbr" \
	"$(INTDIR)\JDFAutoStackingParams.sbr" \
	"$(INTDIR)\JDFAutoStitchingParams.sbr" \
	"$(INTDIR)\JDFAutoStrap.sbr" \
	"$(INTDIR)\JDFAutoStrappingParams.sbr" \
	"$(INTDIR)\JDFAutoStripBindingParams.sbr" \
	"$(INTDIR)\JDFAutoStrippingParams.sbr" \
	"$(INTDIR)\JDFAutoSurface.sbr" \
	"$(INTDIR)\JDFAutoThreadSealingParams.sbr" \
	"$(INTDIR)\JDFAutoThreadSewingParams.sbr" \
	"$(INTDIR)\JDFAutoTile.sbr" \
	"$(INTDIR)\JDFAutoTool.sbr" \
	"$(INTDIR)\JDFAutoTransferCurve.sbr" \
	"$(INTDIR)\JDFAutoTransferCurvePool.sbr" \
	"$(INTDIR)\JDFAutoTransferFunctionControl.sbr" \
	"$(INTDIR)\JDFAutoTrappingDetails.sbr" \
	"$(INTDIR)\JDFAutoTrappingParams.sbr" \
	"$(INTDIR)\JDFAutoTrapRegion.sbr" \
	"$(INTDIR)\JDFAutoTrimmingParams.sbr" \
	"$(INTDIR)\JDFAutoVerificationParams.sbr" \
	"$(INTDIR)\JDFAutoWireCombBindingParams.sbr" \
	"$(INTDIR)\JDFAutoWrappingParams.sbr" \
	"$(INTDIR)\JDFArgumentValue.sbr" \
	"$(INTDIR)\JDFAutoAdvancedParams.sbr" \
	"$(INTDIR)\JDFAutoApprovalPerson.sbr" \
	"$(INTDIR)\JDFAutoArgumentValue.sbr" \
	"$(INTDIR)\JDFAutoAssemblySection.sbr" \
	"$(INTDIR)\JDFAutoBand.sbr" \
	"$(INTDIR)\JDFAutoBasicPreflightTest.sbr" \
	"$(INTDIR)\JDFAutoBindingQualityParams.sbr" \
	"$(INTDIR)\JDFAutoBoxArgument.sbr" \
	"$(INTDIR)\JDFAutoBoxToBoxDifference.sbr" \
	"$(INTDIR)\JDFAutoBundleItem.sbr" \
	"$(INTDIR)\JDFAutoCCITTFaxParams.sbr" \
	"$(INTDIR)\JDFAutoCollatingItem.sbr" \
	"$(INTDIR)\JDFAutoColorantZoneDetails.sbr" \
	"$(INTDIR)\JDFAutoColorCorrectionOp.sbr" \
	"$(INTDIR)\JDFAutoColorSpaceSubstitute.sbr" \
	"$(INTDIR)\JDFAutoContainer.sbr" \
	"$(INTDIR)\JDFAutoContentObject.sbr" \
	"$(INTDIR)\JDFAutoCrease.sbr" \
	"$(INTDIR)\JDFAutoCut.sbr" \
	"$(INTDIR)\JDFAutoDCTParams.sbr" \
	"$(INTDIR)\JDFAutoDependencies.sbr" \
	"$(INTDIR)\JDFAutoDeviceNColor.sbr" \
	"$(INTDIR)\JDFAutoDrop.sbr" \
	"$(INTDIR)\JDFAutoDropItem.sbr" \
	"$(INTDIR)\JDFAutoDynamicField.sbr" \
	"$(INTDIR)\JDFAutoDynamicInput.sbr" \
	"$(INTDIR)\JDFAutoEmboss.sbr" \
	"$(INTDIR)\JDFAutoEndSheet.sbr" \
	"$(INTDIR)\JDFAutoFeeder.sbr" \
	"$(INTDIR)\JDFAutoFeederQualityParams.sbr" \
	"$(INTDIR)\JDFAutoFileAlias.sbr" \
	"$(INTDIR)\JDFAutoFlateParams.sbr" \
	"$(INTDIR)\JDFAutoGlue.sbr" \
	"$(INTDIR)\JDFAutoIcon.sbr" \
	"$(INTDIR)\JDFAutoIconList.sbr" \
	"$(INTDIR)\JDFAutoIDPCover.sbr" \
	"$(INTDIR)\JDFAutoIDPFinishing.sbr" \
	"$(INTDIR)\JDFAutoIDPFolding.sbr" \
	"$(INTDIR)\JDFAutoIDPHoleMaking.sbr" \
	"$(INTDIR)\JDFAutoIDPImageShift.sbr" \
	"$(INTDIR)\JDFAutoIDPJobSheet.sbr" \
	"$(INTDIR)\JDFAutoIDPLayout.sbr" \
	"$(INTDIR)\JDFAutoIDPStitching.sbr" \
	"$(INTDIR)\JDFAutoIDPTrimming.sbr" \
	"$(INTDIR)\JDFAutoImageCompression.sbr" \
	"$(INTDIR)\JDFAutoImageShift.sbr" \
	"$(INTDIR)\JDFAutoLayerDetails.sbr" \
	"$(INTDIR)\JDFAutoLayerList.sbr" \
	"$(INTDIR)\JDFAutoLongFold.sbr" \
	"$(INTDIR)\JDFAutoLongGlue.sbr" \
	"$(INTDIR)\JDFAutoLongPerforate.sbr" \
	"$(INTDIR)\JDFAutoLongSlit.sbr" \
	"$(INTDIR)\JDFAutoLZWParams.sbr" \
	"$(INTDIR)\JDFAutoMarkObject.sbr" \
	"$(INTDIR)\JDFAutoNumberingParam.sbr" \
	"$(INTDIR)\JDFAutoPageCell.sbr" \
	"$(INTDIR)\JDFAutoPageData.sbr" \
	"$(INTDIR)\JDFAutoPDFInterpretingParams.sbr" \
	"$(INTDIR)\JDFAutoPDFXParams.sbr" \
	"$(INTDIR)\JDFAutoPerforate.sbr" \
	"$(INTDIR)\JDFAutoPixelColorant.sbr" \
	"$(INTDIR)\JDFAutoPosition.sbr" \
	"$(INTDIR)\JDFAutoPreflightAction.sbr" \
	"$(INTDIR)\JDFAutoPreflightArgument.sbr" \
	"$(INTDIR)\JDFAutoPreflightConstraint.sbr" \
	"$(INTDIR)\JDFAutoPreflightDetail.sbr" \
	"$(INTDIR)\JDFAutoPreflightInstance.sbr" \
	"$(INTDIR)\JDFAutoPreflightInstanceDetail.sbr" \
	"$(INTDIR)\JDFAutoPreflightValue.sbr" \
	"$(INTDIR)\JDFAutoPRError.sbr" \
	"$(INTDIR)\JDFAutoPRGroup.sbr" \
	"$(INTDIR)\JDFAutoPrintConditionColor.sbr" \
	"$(INTDIR)\JDFAutoPRItem.sbr" \
	"$(INTDIR)\JDFAutoPROccurence.sbr" \
	"$(INTDIR)\JDFAutoProperties.sbr" \
	"$(INTDIR)\JDFAutoPRRule.sbr" \
	"$(INTDIR)\JDFAutoPRRuleAttr.sbr" \
	"$(INTDIR)\JDFAutoQualityMeasurement.sbr" \
	"$(INTDIR)\JDFAutoResourceParam.sbr" \
	"$(INTDIR)\JDFAutoScore.sbr" \
	"$(INTDIR)\JDFAutoScreenSelector.sbr" \
	"$(INTDIR)\JDFAutoShapeElement.sbr" \
	"$(INTDIR)\JDFAutoSignature.sbr" \
	"$(INTDIR)\JDFAutoSignatureCell.sbr" \
	"$(INTDIR)\JDFAutoStringListValue.sbr" \
	"$(INTDIR)\JDFAutoStripCellParams.sbr" \
	"$(INTDIR)\JDFAutoThinPDFParams.sbr" \
	"$(INTDIR)\JDFAutoTIFFEmbeddedFile.sbr" \
	"$(INTDIR)\JDFAutoTIFFFormatParams.sbr" \
	"$(INTDIR)\JDFAutoTIFFtag.sbr" \
	"$(INTDIR)\JDFAutoTransferCurveSet.sbr" \
	"$(INTDIR)\JDFAutoTrappingOrder.sbr" \
	"$(INTDIR)\JDFAutoAction.sbr" \
	"$(INTDIR)\JDFAutoActionPool.sbr" \
	"$(INTDIR)\JDFAutoand.sbr" \
	"$(INTDIR)\JDFAutocall.sbr" \
	"$(INTDIR)\JDFAutochoice.sbr" \
	"$(INTDIR)\JDFAutoDevCap.sbr" \
	"$(INTDIR)\JDFAutoDevCaps.sbr" \
	"$(INTDIR)\JDFAutoDeviceCap.sbr" \
	"$(INTDIR)\JDFAutoDisplayGroup.sbr" \
	"$(INTDIR)\JDFAutoDisplayGroupPool.sbr" \
	"$(INTDIR)\JDFAutoFeatureAttribute.sbr" \
	"$(INTDIR)\JDFAutoFeaturePool.sbr" \
	"$(INTDIR)\JDFAutoLoc.sbr" \
	"$(INTDIR)\JDFAutomacro.sbr" \
	"$(INTDIR)\JDFAutoMacroPool.sbr" \
	"$(INTDIR)\JDFAutonot.sbr" \
	"$(INTDIR)\JDFAutoor.sbr" \
	"$(INTDIR)\JDFAutootherwise.sbr" \
	"$(INTDIR)\JDFAutoPerformance.sbr" \
	"$(INTDIR)\JDFAutoset.sbr" \
	"$(INTDIR)\JDFAutoTest.sbr" \
	"$(INTDIR)\JDFAutoTestPool.sbr" \
	"$(INTDIR)\JDFAutoTestRef.sbr" \
	"$(INTDIR)\JDFAutoValue.sbr" \
	"$(INTDIR)\JDFAutoValueLoc.sbr" \
	"$(INTDIR)\JDFAutowhen.sbr" \
	"$(INTDIR)\JDFAutoxor.sbr" \
	"$(INTDIR)\JDFAutoEnumerationSpan.sbr" \
	"$(INTDIR)\JDFAutoPRGroupOccurence.sbr" \
	"$(INTDIR)\JDFAutoPRGroupOccurenceBase.sbr" \
	"$(INTDIR)\JDFPreflightConstraintsPool.sbr" \
	"$(INTDIR)\JDFPreflightResultsPool.sbr" \
	"$(INTDIR)\JDFPRGroupOccurence.sbr" \
	"$(INTDIR)\JDFPRGroupOccurenceBase.sbr" \
	"$(INTDIR)\JDFDateTimeRange.sbr" \
	"$(INTDIR)\JDFDateTimeRangeList.sbr" \
	"$(INTDIR)\JDFDurationRange.sbr" \
	"$(INTDIR)\JDFDurationRangeList.sbr" \
	"$(INTDIR)\JDFIntegerRange.sbr" \
	"$(INTDIR)\JDFIntegerRangeList.sbr" \
	"$(INTDIR)\JDFNameRangeList.sbr" \
	"$(INTDIR)\JDFNumberRangeList.sbr" \
	"$(INTDIR)\JDFNumTypeList.sbr" \
	"$(INTDIR)\JDFParser.sbr" \
	"$(INTDIR)\JDFRange.sbr" \
	"$(INTDIR)\JDFRangeList.sbr" \
	"$(INTDIR)\JDFXYPairRangeList.sbr" \
	"$(INTDIR)\KElement.sbr" \
	"$(INTDIR)\KElementStrings.sbr" \
	"$(INTDIR)\MyDate.sbr" \
	"$(INTDIR)\vElement.sbr" \
	"$(INTDIR)\XMLDoc.sbr" \
	"$(INTDIR)\XMLDocUserData.sbr"

"$(OUTDIR)\JDFWrapperLib.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=xilink6.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\JDFWrapperLib.lib" 
LIB32_OBJS= \
	"$(INTDIR)\JDFAmountPool.obj" \
	"$(INTDIR)\JDFAncestor.obj" \
	"$(INTDIR)\JDFAncestorPool.obj" \
	"$(INTDIR)\JDFAudit.obj" \
	"$(INTDIR)\JDFAuditPool.obj" \
	"$(INTDIR)\JDFBarcode.obj" \
	"$(INTDIR)\JDFBusinessInfo.obj" \
	"$(INTDIR)\JDFComment.obj" \
	"$(INTDIR)\JDFCounterReset.obj" \
	"$(INTDIR)\JDFCreated.obj" \
	"$(INTDIR)\JDFCustomerInfo.obj" \
	"$(INTDIR)\JDFCustomerMessage.obj" \
	"$(INTDIR)\JDFDeleted.obj" \
	"$(INTDIR)\JDFError.obj" \
	"$(INTDIR)\JDFEvent.obj" \
	"$(INTDIR)\JDFFCNKey.obj" \
	"$(INTDIR)\JDFLocation.obj" \
	"$(INTDIR)\JDFMerged.obj" \
	"$(INTDIR)\JDFModified.obj" \
	"$(INTDIR)\JDFModulePhase.obj" \
	"$(INTDIR)\JDFNode.obj" \
	"$(INTDIR)\JDFNodeInfo.obj" \
	"$(INTDIR)\JDFNotification.obj" \
	"$(INTDIR)\JDFPart.obj" \
	"$(INTDIR)\JDFPartAmount.obj" \
	"$(INTDIR)\JDFPartStatus.obj" \
	"$(INTDIR)\JDFPhaseTime.obj" \
	"$(INTDIR)\JDFProcessRun.obj" \
	"$(INTDIR)\JDFResourceAudit.obj" \
	"$(INTDIR)\JDFResourceLinkPool.obj" \
	"$(INTDIR)\JDFResourcePool.obj" \
	"$(INTDIR)\JDFSpawned.obj" \
	"$(INTDIR)\JDFStatusPool.obj" \
	"$(INTDIR)\JDFSystemTimeSet.obj" \
	"$(INTDIR)\JDFAcknowledge.obj" \
	"$(INTDIR)\JDFAdded.obj" \
	"$(INTDIR)\JDFChangedAttribute.obj" \
	"$(INTDIR)\JDFChangedPath.obj" \
	"$(INTDIR)\JDFCommand.obj" \
	"$(INTDIR)\JDFDeviceFilter.obj" \
	"$(INTDIR)\JDFDeviceInfo.obj" \
	"$(INTDIR)\JDFDeviceList.obj" \
	"$(INTDIR)\JDFEmployeeDef.obj" \
	"$(INTDIR)\JDFFlushedResources.obj" \
	"$(INTDIR)\JDFFlushQueueParams.obj" \
	"$(INTDIR)\JDFFlushResourceParams.obj" \
	"$(INTDIR)\JDFIDInfo.obj" \
	"$(INTDIR)\JDFJDFController.obj" \
	"$(INTDIR)\JDFJDFService.obj" \
	"$(INTDIR)\JDFJMF.obj" \
	"$(INTDIR)\JDFJobPhase.obj" \
	"$(INTDIR)\JDFKnownMsgQuParams.obj" \
	"$(INTDIR)\JDFMessage.obj" \
	"$(INTDIR)\JDFMessageElement.obj" \
	"$(INTDIR)\JDFMessageService.obj" \
	"$(INTDIR)\JDFModuleStatus.obj" \
	"$(INTDIR)\JDFMsgFilter.obj" \
	"$(INTDIR)\JDFNewJDFCmdParams.obj" \
	"$(INTDIR)\JDFNewJDFQuParams.obj" \
	"$(INTDIR)\JDFNodeInfoCmdParams.obj" \
	"$(INTDIR)\JDFNodeInfoQuParams.obj" \
	"$(INTDIR)\JDFNodeInfoResp.obj" \
	"$(INTDIR)\JDFNotificationDef.obj" \
	"$(INTDIR)\JDFNotificationFilter.obj" \
	"$(INTDIR)\JDFObservationTarget.obj" \
	"$(INTDIR)\JDFOccupation.obj" \
	"$(INTDIR)\JDFPipeParams.obj" \
	"$(INTDIR)\JDFQuery.obj" \
	"$(INTDIR)\JDFQueue.obj" \
	"$(INTDIR)\JDFQueueEntry.obj" \
	"$(INTDIR)\JDFQueueEntryDef.obj" \
	"$(INTDIR)\JDFQueueEntryDefList.obj" \
	"$(INTDIR)\JDFQueueEntryPosParams.obj" \
	"$(INTDIR)\JDFQueueEntryPriParams.obj" \
	"$(INTDIR)\JDFQueueFilter.obj" \
	"$(INTDIR)\JDFQueueSubmissionParams.obj" \
	"$(INTDIR)\JDFRemoved.obj" \
	"$(INTDIR)\JDFRequestQueueEntryParams.obj" \
	"$(INTDIR)\JDFResourceCmdParams.obj" \
	"$(INTDIR)\JDFResourceInfo.obj" \
	"$(INTDIR)\JDFResourcePullParams.obj" \
	"$(INTDIR)\JDFResourceQuParams.obj" \
	"$(INTDIR)\JDFResponse.obj" \
	"$(INTDIR)\JDFResubmissionParams.obj" \
	"$(INTDIR)\JDFReturnQueueEntryParams.obj" \
	"$(INTDIR)\JDFShutDownCmdParams.obj" \
	"$(INTDIR)\JDFSignal.obj" \
	"$(INTDIR)\JDFStatusQuParams.obj" \
	"$(INTDIR)\JDFStopPersChParams.obj" \
	"$(INTDIR)\JDFSubmissionMethods.obj" \
	"$(INTDIR)\JDFSubscription.obj" \
	"$(INTDIR)\JDFTrackFilter.obj" \
	"$(INTDIR)\JDFTrackResult.obj" \
	"$(INTDIR)\JDFTrigger.obj" \
	"$(INTDIR)\JDFWakeUpCmdParams.obj" \
	"$(INTDIR)\JDFArtDeliveryIntent.obj" \
	"$(INTDIR)\JDFBindingIntent.obj" \
	"$(INTDIR)\JDFColorIntent.obj" \
	"$(INTDIR)\JDFDeliveryIntent.obj" \
	"$(INTDIR)\JDFEmbossingIntent.obj" \
	"$(INTDIR)\JDFFoldingIntent.obj" \
	"$(INTDIR)\JDFHoleMakingIntent.obj" \
	"$(INTDIR)\JDFInsertingIntent.obj" \
	"$(INTDIR)\JDFIntentResource.obj" \
	"$(INTDIR)\JDFLaminatingIntent.obj" \
	"$(INTDIR)\JDFLayoutIntent.obj" \
	"$(INTDIR)\JDFMediaIntent.obj" \
	"$(INTDIR)\JDFNumberingIntent.obj" \
	"$(INTDIR)\JDFPackingIntent.obj" \
	"$(INTDIR)\JDFProductionIntent.obj" \
	"$(INTDIR)\JDFProofingIntent.obj" \
	"$(INTDIR)\JDFScreeningIntent.obj" \
	"$(INTDIR)\JDFShapeCuttingIntent.obj" \
	"$(INTDIR)\JDFSizeIntent.obj" \
	"$(INTDIR)\JDFSpan.obj" \
	"$(INTDIR)\JDFAdhesiveBinding.obj" \
	"$(INTDIR)\JDFArtDelivery.obj" \
	"$(INTDIR)\JDFBindItem.obj" \
	"$(INTDIR)\JDFBindList.obj" \
	"$(INTDIR)\JDFBookCase.obj" \
	"$(INTDIR)\JDFChannelBinding.obj" \
	"$(INTDIR)\JDFCoilBinding.obj" \
	"$(INTDIR)\JDFColorsUsed.obj" \
	"$(INTDIR)\JDFCreditCard.obj" \
	"$(INTDIR)\JDFDropIntent.obj" \
	"$(INTDIR)\JDFDropItemIntent.obj" \
	"$(INTDIR)\JDFEdgeGluing.obj" \
	"$(INTDIR)\JDFEmbossingItem.obj" \
	"$(INTDIR)\JDFHardCoverBinding.obj" \
	"$(INTDIR)\JDFHoleList.obj" \
	"$(INTDIR)\JDFInsert.obj" \
	"$(INTDIR)\JDFInsertList.obj" \
	"$(INTDIR)\JDFNumberItem.obj" \
	"$(INTDIR)\JDFPayment.obj" \
	"$(INTDIR)\JDFPlasticCombBinding.obj" \
	"$(INTDIR)\JDFPricing.obj" \
	"$(INTDIR)\JDFProofItem.obj" \
	"$(INTDIR)\JDFRingBinding.obj" \
	"$(INTDIR)\JDFSaddleStitching.obj" \
	"$(INTDIR)\JDFShapeCut.obj" \
	"$(INTDIR)\JDFSideSewing.obj" \
	"$(INTDIR)\JDFSideStitching.obj" \
	"$(INTDIR)\JDFSoftCoverBinding.obj" \
	"$(INTDIR)\JDFStripBinding.obj" \
	"$(INTDIR)\JDFTabs.obj" \
	"$(INTDIR)\JDFTape.obj" \
	"$(INTDIR)\JDFThreadSealing.obj" \
	"$(INTDIR)\JDFThreadSewing.obj" \
	"$(INTDIR)\JDFWireCombBinding.obj" \
	"$(INTDIR)\JDFAddress.obj" \
	"$(INTDIR)\JDFAdhesiveBindingParams.obj" \
	"$(INTDIR)\JDFApprovalParams.obj" \
	"$(INTDIR)\JDFApprovalSuccess.obj" \
	"$(INTDIR)\JDFAssembly.obj" \
	"$(INTDIR)\JDFAssetListCreationParams.obj" \
	"$(INTDIR)\JDFAutomatedOverprintParams.obj" \
	"$(INTDIR)\JDFBinderySignature.obj" \
	"$(INTDIR)\JDFBlockPreparationParams.obj" \
	"$(INTDIR)\JDFBoxPackingParams.obj" \
	"$(INTDIR)\JDFBufferParams.obj" \
	"$(INTDIR)\JDFBundle.obj" \
	"$(INTDIR)\JDFBundlingParams.obj" \
	"$(INTDIR)\JDFByteMap.obj" \
	"$(INTDIR)\JDFCaseMakingParams.obj" \
	"$(INTDIR)\JDFCasingInParams.obj" \
	"$(INTDIR)\JDFChannelBindingParams.obj" \
	"$(INTDIR)\JDFCIELABMeasuringField.obj" \
	"$(INTDIR)\JDFCoilBindingParams.obj" \
	"$(INTDIR)\JDFCollectingParams.obj" \
	"$(INTDIR)\JDFColor.obj" \
	"$(INTDIR)\JDFColorantAlias.obj" \
	"$(INTDIR)\JDFColorantControl.obj" \
	"$(INTDIR)\JDFColorControlStrip.obj" \
	"$(INTDIR)\JDFColorCorrectionParams.obj" \
	"$(INTDIR)\JDFColorMeasurementConditions.obj" \
	"$(INTDIR)\JDFColorPool.obj" \
	"$(INTDIR)\JDFColorSpaceConversionOp.obj" \
	"$(INTDIR)\JDFColorSpaceConversionParams.obj" \
	"$(INTDIR)\JDFComChannel.obj" \
	"$(INTDIR)\JDFCompany.obj" \
	"$(INTDIR)\JDFComponent.obj" \
	"$(INTDIR)\JDFContact.obj" \
	"$(INTDIR)\JDFContactCopyParams.obj" \
	"$(INTDIR)\JDFConventionalPrintingParams.obj" \
	"$(INTDIR)\JDFCostCenter.obj" \
	"$(INTDIR)\JDFCoverApplicationParams.obj" \
	"$(INTDIR)\JDFCreasingParams.obj" \
	"$(INTDIR)\JDFCutBlock.obj" \
	"$(INTDIR)\JDFCutMark.obj" \
	"$(INTDIR)\JDFCuttingParams.obj" \
	"$(INTDIR)\JDFDBMergeParams.obj" \
	"$(INTDIR)\JDFDBRules.obj" \
	"$(INTDIR)\JDFDBSchema.obj" \
	"$(INTDIR)\JDFDBSelection.obj" \
	"$(INTDIR)\JDFDeliveryParams.obj" \
	"$(INTDIR)\JDFDensityMeasuringField.obj" \
	"$(INTDIR)\JDFDevelopingParams.obj" \
	"$(INTDIR)\JDFDevice.obj" \
	"$(INTDIR)\JDFDeviceMark.obj" \
	"$(INTDIR)\JDFDeviceNSpace.obj" \
	"$(INTDIR)\JDFDigitalDeliveryParams.obj" \
	"$(INTDIR)\JDFDigitalMedia.obj" \
	"$(INTDIR)\JDFDigitalPrintingParams.obj" \
	"$(INTDIR)\JDFDisjointing.obj" \
	"$(INTDIR)\JDFDisposition.obj" \
	"$(INTDIR)\JDFDividingParams.obj" \
	"$(INTDIR)\JDFElementColorParams.obj" \
	"$(INTDIR)\JDFEmbossingParams.obj" \
	"$(INTDIR)\JDFEmployee.obj" \
	"$(INTDIR)\JDFEndSheetGluingParams.obj" \
	"$(INTDIR)\JDFExposedMedia.obj" \
	"$(INTDIR)\JDFFeedingParams.obj" \
	"$(INTDIR)\JDFFileSpec.obj" \
	"$(INTDIR)\JDFFitPolicy.obj" \
	"$(INTDIR)\JDFFold.obj" \
	"$(INTDIR)\JDFFoldingParams.obj" \
	"$(INTDIR)\JDFFontParams.obj" \
	"$(INTDIR)\JDFFontPolicy.obj" \
	"$(INTDIR)\JDFFormatConversionParams.obj" \
	"$(INTDIR)\JDFGatheringParams.obj" \
	"$(INTDIR)\JDFGlueApplication.obj" \
	"$(INTDIR)\JDFGlueLine.obj" \
	"$(INTDIR)\JDFGluingParams.obj" \
	"$(INTDIR)\JDFHeadBandApplicationParams.obj" \
	"$(INTDIR)\JDFHole.obj" \
	"$(INTDIR)\JDFHoleLine.obj" \
	"$(INTDIR)\JDFHoleMakingParams.obj" \
	"$(INTDIR)\JDFIdentificationField.obj" \
	"$(INTDIR)\JDFIDPrintingParams.obj" \
	"$(INTDIR)\JDFImageCompressionParams.obj" \
	"$(INTDIR)\JDFImageReplacementParams.obj" \
	"$(INTDIR)\JDFImageSetterParams.obj" \
	"$(INTDIR)\JDFInk.obj" \
	"$(INTDIR)\JDFInkZoneCalculationParams.obj" \
	"$(INTDIR)\JDFInkZoneProfile.obj" \
	"$(INTDIR)\JDFInsertingParams.obj" \
	"$(INTDIR)\JDFInsertSheet.obj" \
	"$(INTDIR)\JDFInterpretedPDLData.obj" \
	"$(INTDIR)\JDFInterpretingParams.obj" \
	"$(INTDIR)\JDFJacketingParams.obj" \
	"$(INTDIR)\JDFJobField.obj" \
	"$(INTDIR)\JDFLabelingParams.obj" \
	"$(INTDIR)\JDFLaminatingParams.obj" \
	"$(INTDIR)\JDFLayout.obj" \
	"$(INTDIR)\JDFLayoutElement.obj" \
	"$(INTDIR)\JDFLayoutPreparationParams.obj" \
	"$(INTDIR)\JDFLongitudinalRibbonOperationParams.obj" \
	"$(INTDIR)\JDFManualLaborParams.obj" \
	"$(INTDIR)\JDFMedia.obj" \
	"$(INTDIR)\JDFMediaSource.obj" \
	"$(INTDIR)\JDFMISDetails.obj" \
	"$(INTDIR)\JDFNumberingParams.obj" \
	"$(INTDIR)\JDFObjectResolution.obj" \
	"$(INTDIR)\JDFOrderingParams.obj" \
	"$(INTDIR)\JDFPackingParams.obj" \
	"$(INTDIR)\JDFPageList.obj" \
	"$(INTDIR)\JDFPallet.obj" \
	"$(INTDIR)\JDFPalletizingParams.obj" \
	"$(INTDIR)\JDFPDFToPSConversionParams.obj" \
	"$(INTDIR)\JDFPDLResourceAlias.obj" \
	"$(INTDIR)\JDFPerforatingParams.obj" \
	"$(INTDIR)\JDFPerson.obj" \
	"$(INTDIR)\JDFPlaceHolderResource.obj" \
	"$(INTDIR)\JDFPlasticCombBindingParams.obj" \
	"$(INTDIR)\JDFPlateCopyParams.obj" \
	"$(INTDIR)\JDFPreflightAnalysis.obj" \
	"$(INTDIR)\JDFPreflightInventory.obj" \
	"$(INTDIR)\JDFPreflightParams.obj" \
	"$(INTDIR)\JDFPreflightProfile.obj" \
	"$(INTDIR)\JDFPreflightReport.obj" \
	"$(INTDIR)\JDFPreflightReportRulePool.obj" \
	"$(INTDIR)\JDFPreview.obj" \
	"$(INTDIR)\JDFPreviewGenerationParams.obj" \
	"$(INTDIR)\JDFPrintCondition.obj" \
	"$(INTDIR)\JDFPrintRollingParams.obj" \
	"$(INTDIR)\JDFProofingParams.obj" \
	"$(INTDIR)\JDFPSToPDFConversionParams.obj" \
	"$(INTDIR)\JDFQualityControlParams.obj" \
	"$(INTDIR)\JDFQualityControlResult.obj" \
	"$(INTDIR)\JDFRegisterMark.obj" \
	"$(INTDIR)\JDFRegisterRibbon.obj" \
	"$(INTDIR)\JDFRenderingParams.obj" \
	"$(INTDIR)\JDFResourceDefinitionParams.obj" \
	"$(INTDIR)\JDFRingBindingParams.obj" \
	"$(INTDIR)\JDFRollStand.obj" \
	"$(INTDIR)\JDFRunList.obj" \
	"$(INTDIR)\JDFSaddleStitchingParams.obj" \
	"$(INTDIR)\JDFScanParams.obj" \
	"$(INTDIR)\JDFScavengerArea.obj" \
	"$(INTDIR)\JDFScreeningParams.obj" \
	"$(INTDIR)\JDFSeparationControlParams.obj" \
	"$(INTDIR)\JDFSeparationSpec.obj" \
	"$(INTDIR)\JDFShapeCuttingParams.obj" \
	"$(INTDIR)\JDFSheet.obj" \
	"$(INTDIR)\JDFShrinkingParams.obj" \
	"$(INTDIR)\JDFSideSewingParams.obj" \
	"$(INTDIR)\JDFSpinePreparationParams.obj" \
	"$(INTDIR)\JDFSpineTapingParams.obj" \
	"$(INTDIR)\JDFStackingParams.obj" \
	"$(INTDIR)\JDFStitchingParams.obj" \
	"$(INTDIR)\JDFStrap.obj" \
	"$(INTDIR)\JDFStrappingParams.obj" \
	"$(INTDIR)\JDFStripBindingParams.obj" \
	"$(INTDIR)\JDFStrippingParams.obj" \
	"$(INTDIR)\JDFSurface.obj" \
	"$(INTDIR)\JDFThreadSealingParams.obj" \
	"$(INTDIR)\JDFThreadSewingParams.obj" \
	"$(INTDIR)\JDFTile.obj" \
	"$(INTDIR)\JDFTool.obj" \
	"$(INTDIR)\JDFTransferCurve.obj" \
	"$(INTDIR)\JDFTransferCurvePool.obj" \
	"$(INTDIR)\JDFTransferFunctionControl.obj" \
	"$(INTDIR)\JDFTrappingDetails.obj" \
	"$(INTDIR)\JDFTrappingParams.obj" \
	"$(INTDIR)\JDFTrapRegion.obj" \
	"$(INTDIR)\JDFTrimmingParams.obj" \
	"$(INTDIR)\JDFVerificationParams.obj" \
	"$(INTDIR)\JDFWireCombBindingParams.obj" \
	"$(INTDIR)\JDFWrappingParams.obj" \
	"$(INTDIR)\JDFAdvancedParams.obj" \
	"$(INTDIR)\JDFApprovalPerson.obj" \
	"$(INTDIR)\JDFAssemblySection.obj" \
	"$(INTDIR)\JDFBand.obj" \
	"$(INTDIR)\JDFBasicPreflightTest.obj" \
	"$(INTDIR)\JDFBindingQualityParams.obj" \
	"$(INTDIR)\JDFBoxArgument.obj" \
	"$(INTDIR)\JDFBoxToBoxDifference.obj" \
	"$(INTDIR)\JDFBundleItem.obj" \
	"$(INTDIR)\JDFCCITTFaxParams.obj" \
	"$(INTDIR)\JDFCollatingItem.obj" \
	"$(INTDIR)\JDFColorantZoneDetails.obj" \
	"$(INTDIR)\JDFColorCorrectionOp.obj" \
	"$(INTDIR)\JDFColorSpaceSubstitute.obj" \
	"$(INTDIR)\JDFContainer.obj" \
	"$(INTDIR)\JDFContentObject.obj" \
	"$(INTDIR)\JDFCrease.obj" \
	"$(INTDIR)\JDFCut.obj" \
	"$(INTDIR)\JDFDCTParams.obj" \
	"$(INTDIR)\JDFDependencies.obj" \
	"$(INTDIR)\JDFDeviceNColor.obj" \
	"$(INTDIR)\JDFDrop.obj" \
	"$(INTDIR)\JDFDropItem.obj" \
	"$(INTDIR)\JDFDynamicField.obj" \
	"$(INTDIR)\JDFDynamicInput.obj" \
	"$(INTDIR)\JDFEmboss.obj" \
	"$(INTDIR)\JDFEndSheet.obj" \
	"$(INTDIR)\JDFFeeder.obj" \
	"$(INTDIR)\JDFFeederQualityParams.obj" \
	"$(INTDIR)\JDFFileAlias.obj" \
	"$(INTDIR)\JDFFlateParams.obj" \
	"$(INTDIR)\JDFGlue.obj" \
	"$(INTDIR)\JDFIcon.obj" \
	"$(INTDIR)\JDFIconList.obj" \
	"$(INTDIR)\JDFIDPCover.obj" \
	"$(INTDIR)\JDFIDPFinishing.obj" \
	"$(INTDIR)\JDFIDPFolding.obj" \
	"$(INTDIR)\JDFIDPHoleMaking.obj" \
	"$(INTDIR)\JDFIDPImageShift.obj" \
	"$(INTDIR)\JDFIDPJobSheet.obj" \
	"$(INTDIR)\JDFIDPLayout.obj" \
	"$(INTDIR)\JDFIDPStitching.obj" \
	"$(INTDIR)\JDFIDPTrimming.obj" \
	"$(INTDIR)\JDFImageCompression.obj" \
	"$(INTDIR)\JDFImageShift.obj" \
	"$(INTDIR)\JDFLayerDetails.obj" \
	"$(INTDIR)\JDFLayerList.obj" \
	"$(INTDIR)\JDFLongFold.obj" \
	"$(INTDIR)\JDFLongGlue.obj" \
	"$(INTDIR)\JDFLongPerforate.obj" \
	"$(INTDIR)\JDFLongSlit.obj" \
	"$(INTDIR)\JDFLZWParams.obj" \
	"$(INTDIR)\JDFMarkObject.obj" \
	"$(INTDIR)\JDFNumberingParam.obj" \
	"$(INTDIR)\JDFPageCell.obj" \
	"$(INTDIR)\JDFPageData.obj" \
	"$(INTDIR)\JDFPDFInterpretingParams.obj" \
	"$(INTDIR)\JDFPDFXParams.obj" \
	"$(INTDIR)\JDFPerforate.obj" \
	"$(INTDIR)\JDFPixelColorant.obj" \
	"$(INTDIR)\JDFPosition.obj" \
	"$(INTDIR)\JDFPreflightAction.obj" \
	"$(INTDIR)\JDFPreflightArgument.obj" \
	"$(INTDIR)\JDFPreflightConstraint.obj" \
	"$(INTDIR)\JDFPreflightDetail.obj" \
	"$(INTDIR)\JDFPreflightInstance.obj" \
	"$(INTDIR)\JDFPreflightInstanceDetail.obj" \
	"$(INTDIR)\JDFPreflightValue.obj" \
	"$(INTDIR)\JDFPRError.obj" \
	"$(INTDIR)\JDFPRGroup.obj" \
	"$(INTDIR)\JDFPrintConditionColor.obj" \
	"$(INTDIR)\JDFPRItem.obj" \
	"$(INTDIR)\JDFPROccurence.obj" \
	"$(INTDIR)\JDFProperties.obj" \
	"$(INTDIR)\JDFPRRule.obj" \
	"$(INTDIR)\JDFPRRuleAttr.obj" \
	"$(INTDIR)\JDFQualityMeasurement.obj" \
	"$(INTDIR)\JDFResourceParam.obj" \
	"$(INTDIR)\JDFScore.obj" \
	"$(INTDIR)\JDFScreenSelector.obj" \
	"$(INTDIR)\JDFShapeElement.obj" \
	"$(INTDIR)\JDFSignature.obj" \
	"$(INTDIR)\JDFSignatureCell.obj" \
	"$(INTDIR)\JDFStringListValue.obj" \
	"$(INTDIR)\JDFStripCellParams.obj" \
	"$(INTDIR)\JDFThinPDFParams.obj" \
	"$(INTDIR)\JDFTIFFEmbeddedFile.obj" \
	"$(INTDIR)\JDFTIFFFormatParams.obj" \
	"$(INTDIR)\JDFTIFFtag.obj" \
	"$(INTDIR)\JDFTransferCurveSet.obj" \
	"$(INTDIR)\JDFTrappingOrder.obj" \
	"$(INTDIR)\JDFAction.obj" \
	"$(INTDIR)\JDFActionPool.obj" \
	"$(INTDIR)\JDFand.obj" \
	"$(INTDIR)\JDFBooleanEvaluation.obj" \
	"$(INTDIR)\JDFBooleanState.obj" \
	"$(INTDIR)\JDFcall.obj" \
	"$(INTDIR)\JDFchoice.obj" \
	"$(INTDIR)\JDFDateTimeEvaluation.obj" \
	"$(INTDIR)\JDFDateTimeState.obj" \
	"$(INTDIR)\JDFDevCap.obj" \
	"$(INTDIR)\JDFDevCaps.obj" \
	"$(INTDIR)\JDFDeviceCap.obj" \
	"$(INTDIR)\JDFDisplayGroup.obj" \
	"$(INTDIR)\JDFDisplayGroupPool.obj" \
	"$(INTDIR)\JDFDurationEvaluation.obj" \
	"$(INTDIR)\JDFDurationState.obj" \
	"$(INTDIR)\JDFEnumerationEvaluation.obj" \
	"$(INTDIR)\JDFEnumerationState.obj" \
	"$(INTDIR)\JDFEvaluation.obj" \
	"$(INTDIR)\JDFFeatureAttribute.obj" \
	"$(INTDIR)\JDFFeaturePool.obj" \
	"$(INTDIR)\JDFIntegerEvaluation.obj" \
	"$(INTDIR)\JDFIntegerState.obj" \
	"$(INTDIR)\JDFIsPresentEvaluation.obj" \
	"$(INTDIR)\JDFLoc.obj" \
	"$(INTDIR)\JDFmacro.obj" \
	"$(INTDIR)\JDFMacroPool.obj" \
	"$(INTDIR)\JDFMatrixEvaluation.obj" \
	"$(INTDIR)\JDFMatrixState.obj" \
	"$(INTDIR)\JDFNameEvaluation.obj" \
	"$(INTDIR)\JDFNameState.obj" \
	"$(INTDIR)\JDFnot.obj" \
	"$(INTDIR)\JDFNumberEvaluation.obj" \
	"$(INTDIR)\JDFNumberState.obj" \
	"$(INTDIR)\JDFor.obj" \
	"$(INTDIR)\JDFotherwise.obj" \
	"$(INTDIR)\JDFPDFPathEvaluation.obj" \
	"$(INTDIR)\JDFPDFPathState.obj" \
	"$(INTDIR)\JDFPerformance.obj" \
	"$(INTDIR)\JDFRectangleEvaluation.obj" \
	"$(INTDIR)\JDFRectangleState.obj" \
	"$(INTDIR)\JDFset.obj" \
	"$(INTDIR)\JDFShapeEvaluation.obj" \
	"$(INTDIR)\JDFShapeState.obj" \
	"$(INTDIR)\JDFState.obj" \
	"$(INTDIR)\JDFStringEvaluation.obj" \
	"$(INTDIR)\JDFStringState.obj" \
	"$(INTDIR)\JDFTest.obj" \
	"$(INTDIR)\JDFTestPool.obj" \
	"$(INTDIR)\JDFTestRef.obj" \
	"$(INTDIR)\JDFValue.obj" \
	"$(INTDIR)\JDFValueLoc.obj" \
	"$(INTDIR)\JDFwhen.obj" \
	"$(INTDIR)\JDFxor.obj" \
	"$(INTDIR)\JDFXYPairEvaluation.obj" \
	"$(INTDIR)\JDFXYPairState.obj" \
	"$(INTDIR)\JDFDoc.obj" \
	"$(INTDIR)\JDFElement.obj" \
	"$(INTDIR)\JDFFactory.obj" \
	"$(INTDIR)\JDFNodeFactory.obj" \
	"$(INTDIR)\JDFParamsFactory.obj" \
	"$(INTDIR)\JDFPool.obj" \
	"$(INTDIR)\JDFRefElement.obj" \
	"$(INTDIR)\JDFResource.obj" \
	"$(INTDIR)\JDFResourceLink.obj" \
	"$(INTDIR)\JDFRunElement.obj" \
	"$(INTDIR)\JDFSeparationList.obj" \
	"$(INTDIR)\JDFStrings.obj" \
	"$(INTDIR)\JDFAutoAmountPool.obj" \
	"$(INTDIR)\JDFAutoAncestor.obj" \
	"$(INTDIR)\JDFAutoAncestorPool.obj" \
	"$(INTDIR)\JDFAutoBarcode.obj" \
	"$(INTDIR)\JDFAutoBusinessInfo.obj" \
	"$(INTDIR)\JDFAutoComment.obj" \
	"$(INTDIR)\JDFAutoCounterReset.obj" \
	"$(INTDIR)\JDFAutoCreated.obj" \
	"$(INTDIR)\JDFAutoCustomerInfo.obj" \
	"$(INTDIR)\JDFAutoCustomerMessage.obj" \
	"$(INTDIR)\JDFAutoDeleted.obj" \
	"$(INTDIR)\JDFAutoError.obj" \
	"$(INTDIR)\JDFAutoEvent.obj" \
	"$(INTDIR)\JDFAutoFCNKey.obj" \
	"$(INTDIR)\JDFAutoLocation.obj" \
	"$(INTDIR)\JDFAutoMerged.obj" \
	"$(INTDIR)\JDFAutoModified.obj" \
	"$(INTDIR)\JDFAutoModulePhase.obj" \
	"$(INTDIR)\JDFAutoNodeInfo.obj" \
	"$(INTDIR)\JDFAutoNotification.obj" \
	"$(INTDIR)\JDFAutoPart.obj" \
	"$(INTDIR)\JDFAutoPartStatus.obj" \
	"$(INTDIR)\JDFAutoPhaseTime.obj" \
	"$(INTDIR)\JDFAutoProcessRun.obj" \
	"$(INTDIR)\JDFAutoResourceAudit.obj" \
	"$(INTDIR)\JDFAutoSpawned.obj" \
	"$(INTDIR)\JDFAutoStatusPool.obj" \
	"$(INTDIR)\JDFAutoSystemTimeSet.obj" \
	"$(INTDIR)\JDFAutoAcknowledge.obj" \
	"$(INTDIR)\JDFAutoAdded.obj" \
	"$(INTDIR)\JDFAutoChangedAttribute.obj" \
	"$(INTDIR)\JDFAutoChangedPath.obj" \
	"$(INTDIR)\JDFAutoCommand.obj" \
	"$(INTDIR)\JDFAutoDeviceFilter.obj" \
	"$(INTDIR)\JDFAutoDeviceInfo.obj" \
	"$(INTDIR)\JDFAutoDeviceList.obj" \
	"$(INTDIR)\JDFAutoEmployeeDef.obj" \
	"$(INTDIR)\JDFAutoFlushedResources.obj" \
	"$(INTDIR)\JDFAutoFlushQueueParams.obj" \
	"$(INTDIR)\JDFAutoFlushResourceParams.obj" \
	"$(INTDIR)\JDFAutoIDInfo.obj" \
	"$(INTDIR)\JDFAutoJDFController.obj" \
	"$(INTDIR)\JDFAutoJDFService.obj" \
	"$(INTDIR)\JDFAutoJMF.obj" \
	"$(INTDIR)\JDFAutoJobPhase.obj" \
	"$(INTDIR)\JDFAutoKnownMsgQuParams.obj" \
	"$(INTDIR)\JDFAutoMessage.obj" \
	"$(INTDIR)\JDFAutoMessageService.obj" \
	"$(INTDIR)\JDFAutoModuleStatus.obj" \
	"$(INTDIR)\JDFAutoMsgFilter.obj" \
	"$(INTDIR)\JDFAutoNewJDFCmdParams.obj" \
	"$(INTDIR)\JDFAutoNewJDFQuParams.obj" \
	"$(INTDIR)\JDFAutoNodeInfoCmdParams.obj" \
	"$(INTDIR)\JDFAutoNodeInfoQuParams.obj" \
	"$(INTDIR)\JDFAutoNodeInfoResp.obj" \
	"$(INTDIR)\JDFAutoNotificationDef.obj" \
	"$(INTDIR)\JDFAutoNotificationFilter.obj" \
	"$(INTDIR)\JDFAutoObservationTarget.obj" \
	"$(INTDIR)\JDFAutoOccupation.obj" \
	"$(INTDIR)\JDFAutoPipeParams.obj" \
	"$(INTDIR)\JDFAutoQuery.obj" \
	"$(INTDIR)\JDFAutoQueue.obj" \
	"$(INTDIR)\JDFAutoQueueEntry.obj" \
	"$(INTDIR)\JDFAutoQueueEntryDef.obj" \
	"$(INTDIR)\JDFAutoQueueEntryDefList.obj" \
	"$(INTDIR)\JDFAutoQueueEntryPosParams.obj" \
	"$(INTDIR)\JDFAutoQueueEntryPriParams.obj" \
	"$(INTDIR)\JDFAutoQueueFilter.obj" \
	"$(INTDIR)\JDFAutoQueueSubmissionParams.obj" \
	"$(INTDIR)\JDFAutoRemoved.obj" \
	"$(INTDIR)\JDFAutoRequestQueueEntryParams.obj" \
	"$(INTDIR)\JDFAutoResourceCmdParams.obj" \
	"$(INTDIR)\JDFAutoResourceInfo.obj" \
	"$(INTDIR)\JDFAutoResourcePullParams.obj" \
	"$(INTDIR)\JDFAutoResourceQuParams.obj" \
	"$(INTDIR)\JDFAutoResponse.obj" \
	"$(INTDIR)\JDFAutoResubmissionParams.obj" \
	"$(INTDIR)\JDFAutoReturnQueueEntryParams.obj" \
	"$(INTDIR)\JDFAutoShutDownCmdParams.obj" \
	"$(INTDIR)\JDFAutoSignal.obj" \
	"$(INTDIR)\JDFAutoStatusQuParams.obj" \
	"$(INTDIR)\JDFAutoStopPersChParams.obj" \
	"$(INTDIR)\JDFAutoSubmissionMethods.obj" \
	"$(INTDIR)\JDFAutoSubscription.obj" \
	"$(INTDIR)\JDFAutoTrackFilter.obj" \
	"$(INTDIR)\JDFAutoTrackResult.obj" \
	"$(INTDIR)\JDFAutoTrigger.obj" \
	"$(INTDIR)\JDFAutoWakeUpCmdParams.obj" \
	"$(INTDIR)\JDFAutoArtDeliveryIntent.obj" \
	"$(INTDIR)\JDFAutoBindingIntent.obj" \
	"$(INTDIR)\JDFAutoColorIntent.obj" \
	"$(INTDIR)\JDFAutoDeliveryIntent.obj" \
	"$(INTDIR)\JDFAutoEmbossingIntent.obj" \
	"$(INTDIR)\JDFAutoFoldingIntent.obj" \
	"$(INTDIR)\JDFAutoHoleMakingIntent.obj" \
	"$(INTDIR)\JDFAutoInsertingIntent.obj" \
	"$(INTDIR)\JDFAutoLaminatingIntent.obj" \
	"$(INTDIR)\JDFAutoLayoutIntent.obj" \
	"$(INTDIR)\JDFAutoMediaIntent.obj" \
	"$(INTDIR)\JDFAutoNumberingIntent.obj" \
	"$(INTDIR)\JDFAutoPackingIntent.obj" \
	"$(INTDIR)\JDFAutoProductionIntent.obj" \
	"$(INTDIR)\JDFAutoProofingIntent.obj" \
	"$(INTDIR)\JDFAutoScreeningIntent.obj" \
	"$(INTDIR)\JDFAutoShapeCuttingIntent.obj" \
	"$(INTDIR)\JDFAutoSizeIntent.obj" \
	"$(INTDIR)\JDFAutoAdhesiveBinding.obj" \
	"$(INTDIR)\JDFAutoArtDelivery.obj" \
	"$(INTDIR)\JDFAutoBindItem.obj" \
	"$(INTDIR)\JDFAutoBindList.obj" \
	"$(INTDIR)\JDFAutoBookCase.obj" \
	"$(INTDIR)\JDFAutoChannelBinding.obj" \
	"$(INTDIR)\JDFAutoCoilBinding.obj" \
	"$(INTDIR)\JDFAutoColorsUsed.obj" \
	"$(INTDIR)\JDFAutoCreditCard.obj" \
	"$(INTDIR)\JDFAutoDropIntent.obj" \
	"$(INTDIR)\JDFAutoDropItemIntent.obj" \
	"$(INTDIR)\JDFAutoEdgeGluing.obj" \
	"$(INTDIR)\JDFAutoEmbossingItem.obj" \
	"$(INTDIR)\JDFAutoHardCoverBinding.obj" \
	"$(INTDIR)\JDFAutoHoleList.obj" \
	"$(INTDIR)\JDFAutoInsert.obj" \
	"$(INTDIR)\JDFAutoInsertList.obj" \
	"$(INTDIR)\JDFAutoNumberItem.obj" \
	"$(INTDIR)\JDFAutoPayment.obj" \
	"$(INTDIR)\JDFAutoPlasticCombBinding.obj" \
	"$(INTDIR)\JDFAutoPricing.obj" \
	"$(INTDIR)\JDFAutoProofItem.obj" \
	"$(INTDIR)\JDFAutoRingBinding.obj" \
	"$(INTDIR)\JDFAutoSaddleStitching.obj" \
	"$(INTDIR)\JDFAutoShapeCut.obj" \
	"$(INTDIR)\JDFAutoSideSewing.obj" \
	"$(INTDIR)\JDFAutoSideStitching.obj" \
	"$(INTDIR)\JDFAutoSoftCoverBinding.obj" \
	"$(INTDIR)\JDFAutoStripBinding.obj" \
	"$(INTDIR)\JDFAutoTabs.obj" \
	"$(INTDIR)\JDFAutoTape.obj" \
	"$(INTDIR)\JDFAutoThreadSealing.obj" \
	"$(INTDIR)\JDFAutoThreadSewing.obj" \
	"$(INTDIR)\JDFAutoWireCombBinding.obj" \
	"$(INTDIR)\JDFAutoAddress.obj" \
	"$(INTDIR)\JDFAutoAdhesiveBindingParams.obj" \
	"$(INTDIR)\JDFAutoApprovalParams.obj" \
	"$(INTDIR)\JDFAutoApprovalSuccess.obj" \
	"$(INTDIR)\JDFAutoAssembly.obj" \
	"$(INTDIR)\JDFAutoAssetListCreationParams.obj" \
	"$(INTDIR)\JDFAutoAutomatedOverprintParams.obj" \
	"$(INTDIR)\JDFAutoBinderySignature.obj" \
	"$(INTDIR)\JDFAutoBlockPreparationParams.obj" \
	"$(INTDIR)\JDFAutoBoxPackingParams.obj" \
	"$(INTDIR)\JDFAutoBufferParams.obj" \
	"$(INTDIR)\JDFAutoBundle.obj" \
	"$(INTDIR)\JDFAutoBundlingParams.obj" \
	"$(INTDIR)\JDFAutoByteMap.obj" \
	"$(INTDIR)\JDFAutoCaseMakingParams.obj" \
	"$(INTDIR)\JDFAutoCasingInParams.obj" \
	"$(INTDIR)\JDFAutoChannelBindingParams.obj" \
	"$(INTDIR)\JDFAutoCIELABMeasuringField.obj" \
	"$(INTDIR)\JDFAutoCoilBindingParams.obj" \
	"$(INTDIR)\JDFAutoCollectingParams.obj" \
	"$(INTDIR)\JDFAutoColor.obj" \
	"$(INTDIR)\JDFAutoColorantAlias.obj" \
	"$(INTDIR)\JDFAutoColorantControl.obj" \
	"$(INTDIR)\JDFAutoColorControlStrip.obj" \
	"$(INTDIR)\JDFAutoColorCorrectionParams.obj" \
	"$(INTDIR)\JDFAutoColorMeasurementConditions.obj" \
	"$(INTDIR)\JDFAutoColorPool.obj" \
	"$(INTDIR)\JDFAutoColorSpaceConversionOp.obj" \
	"$(INTDIR)\JDFAutoColorSpaceConversionParams.obj" \
	"$(INTDIR)\JDFAutoComChannel.obj" \
	"$(INTDIR)\JDFAutoCompany.obj" \
	"$(INTDIR)\JDFAutoComponent.obj" \
	"$(INTDIR)\JDFAutoContact.obj" \
	"$(INTDIR)\JDFAutoContactCopyParams.obj" \
	"$(INTDIR)\JDFAutoConventionalPrintingParams.obj" \
	"$(INTDIR)\JDFAutoCostCenter.obj" \
	"$(INTDIR)\JDFAutoCoverApplicationParams.obj" \
	"$(INTDIR)\JDFAutoCreasingParams.obj" \
	"$(INTDIR)\JDFAutoCutBlock.obj" \
	"$(INTDIR)\JDFAutoCutMark.obj" \
	"$(INTDIR)\JDFAutoCuttingParams.obj" \
	"$(INTDIR)\JDFAutoDBMergeParams.obj" \
	"$(INTDIR)\JDFAutoDBRules.obj" \
	"$(INTDIR)\JDFAutoDBSchema.obj" \
	"$(INTDIR)\JDFAutoDBSelection.obj" \
	"$(INTDIR)\JDFAutoDeliveryParams.obj" \
	"$(INTDIR)\JDFAutoDensityMeasuringField.obj" \
	"$(INTDIR)\JDFAutoDevelopingParams.obj" \
	"$(INTDIR)\JDFAutoDevice.obj" \
	"$(INTDIR)\JDFAutoDeviceMark.obj" \
	"$(INTDIR)\JDFAutoDeviceNSpace.obj" \
	"$(INTDIR)\JDFAutoDigitalDeliveryParams.obj" \
	"$(INTDIR)\JDFAutoDigitalMedia.obj" \
	"$(INTDIR)\JDFAutoDigitalPrintingParams.obj" \
	"$(INTDIR)\JDFAutoDisjointing.obj" \
	"$(INTDIR)\JDFAutoDisposition.obj" \
	"$(INTDIR)\JDFAutoDividingParams.obj" \
	"$(INTDIR)\JDFAutoElementColorParams.obj" \
	"$(INTDIR)\JDFAutoEmbossingParams.obj" \
	"$(INTDIR)\JDFAutoEmployee.obj" \
	"$(INTDIR)\JDFAutoEndSheetGluingParams.obj" \
	"$(INTDIR)\JDFAutoExposedMedia.obj" \
	"$(INTDIR)\JDFAutoFeedingParams.obj" \
	"$(INTDIR)\JDFAutoFileSpec.obj" \
	"$(INTDIR)\JDFAutoFitPolicy.obj" \
	"$(INTDIR)\JDFAutoFold.obj" \
	"$(INTDIR)\JDFAutoFoldingParams.obj" \
	"$(INTDIR)\JDFAutoFontParams.obj" \
	"$(INTDIR)\JDFAutoFontPolicy.obj" \
	"$(INTDIR)\JDFAutoFormatConversionParams.obj" \
	"$(INTDIR)\JDFAutoGatheringParams.obj" \
	"$(INTDIR)\JDFAutoGlueApplication.obj" \
	"$(INTDIR)\JDFAutoGlueLine.obj" \
	"$(INTDIR)\JDFAutoGluingParams.obj" \
	"$(INTDIR)\JDFAutoHeadBandApplicationParams.obj" \
	"$(INTDIR)\JDFAutoHole.obj" \
	"$(INTDIR)\JDFAutoHoleLine.obj" \
	"$(INTDIR)\JDFAutoHoleMakingParams.obj" \
	"$(INTDIR)\JDFAutoIdentificationField.obj" \
	"$(INTDIR)\JDFAutoIDPrintingParams.obj" \
	"$(INTDIR)\JDFAutoImageCompressionParams.obj" \
	"$(INTDIR)\JDFAutoImageReplacementParams.obj" \
	"$(INTDIR)\JDFAutoImageSetterParams.obj" \
	"$(INTDIR)\JDFAutoInk.obj" \
	"$(INTDIR)\JDFAutoInkZoneCalculationParams.obj" \
	"$(INTDIR)\JDFAutoInkZoneProfile.obj" \
	"$(INTDIR)\JDFAutoInsertingParams.obj" \
	"$(INTDIR)\JDFAutoInsertSheet.obj" \
	"$(INTDIR)\JDFAutoInterpretedPDLData.obj" \
	"$(INTDIR)\JDFAutoInterpretingParams.obj" \
	"$(INTDIR)\JDFAutoJacketingParams.obj" \
	"$(INTDIR)\JDFAutoJobField.obj" \
	"$(INTDIR)\JDFAutoLabelingParams.obj" \
	"$(INTDIR)\JDFAutoLaminatingParams.obj" \
	"$(INTDIR)\JDFAutoLayout.obj" \
	"$(INTDIR)\JDFAutoLayoutElement.obj" \
	"$(INTDIR)\JDFAutoLayoutPreparationParams.obj" \
	"$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.obj" \
	"$(INTDIR)\JDFAutoManualLaborParams.obj" \
	"$(INTDIR)\JDFAutoMedia.obj" \
	"$(INTDIR)\JDFAutoMediaSource.obj" \
	"$(INTDIR)\JDFAutoMISDetails.obj" \
	"$(INTDIR)\JDFAutoNumberingParams.obj" \
	"$(INTDIR)\JDFAutoObjectResolution.obj" \
	"$(INTDIR)\JDFAutoOrderingParams.obj" \
	"$(INTDIR)\JDFAutoPackingParams.obj" \
	"$(INTDIR)\JDFAutoPageList.obj" \
	"$(INTDIR)\JDFAutoPallet.obj" \
	"$(INTDIR)\JDFAutoPalletizingParams.obj" \
	"$(INTDIR)\JDFAutoPDFToPSConversionParams.obj" \
	"$(INTDIR)\JDFAutoPDLResourceAlias.obj" \
	"$(INTDIR)\JDFAutoPerforatingParams.obj" \
	"$(INTDIR)\JDFAutoPerson.obj" \
	"$(INTDIR)\JDFAutoPlaceHolderResource.obj" \
	"$(INTDIR)\JDFAutoPlasticCombBindingParams.obj" \
	"$(INTDIR)\JDFAutoPlateCopyParams.obj" \
	"$(INTDIR)\JDFAutoPreflightAnalysis.obj" \
	"$(INTDIR)\JDFAutoPreflightInventory.obj" \
	"$(INTDIR)\JDFAutoPreflightParams.obj" \
	"$(INTDIR)\JDFAutoPreflightProfile.obj" \
	"$(INTDIR)\JDFAutoPreflightReport.obj" \
	"$(INTDIR)\JDFAutoPreflightReportRulePool.obj" \
	"$(INTDIR)\JDFAutoPreview.obj" \
	"$(INTDIR)\JDFAutoPreviewGenerationParams.obj" \
	"$(INTDIR)\JDFAutoPrintCondition.obj" \
	"$(INTDIR)\JDFAutoPrintRollingParams.obj" \
	"$(INTDIR)\JDFAutoProofingParams.obj" \
	"$(INTDIR)\JDFAutoPSToPDFConversionParams.obj" \
	"$(INTDIR)\JDFAutoQualityControlParams.obj" \
	"$(INTDIR)\JDFAutoQualityControlResult.obj" \
	"$(INTDIR)\JDFAutoRegisterMark.obj" \
	"$(INTDIR)\JDFAutoRegisterRibbon.obj" \
	"$(INTDIR)\JDFAutoRenderingParams.obj" \
	"$(INTDIR)\JDFAutoResourceDefinitionParams.obj" \
	"$(INTDIR)\JDFAutoRingBindingParams.obj" \
	"$(INTDIR)\JDFAutoRollStand.obj" \
	"$(INTDIR)\JDFAutoRunList.obj" \
	"$(INTDIR)\JDFAutoSaddleStitchingParams.obj" \
	"$(INTDIR)\JDFAutoScanParams.obj" \
	"$(INTDIR)\JDFAutoScavengerArea.obj" \
	"$(INTDIR)\JDFAutoScreeningParams.obj" \
	"$(INTDIR)\JDFAutoSeparationControlParams.obj" \
	"$(INTDIR)\JDFAutoSeparationSpec.obj" \
	"$(INTDIR)\JDFAutoShapeCuttingParams.obj" \
	"$(INTDIR)\JDFAutoSheet.obj" \
	"$(INTDIR)\JDFAutoShrinkingParams.obj" \
	"$(INTDIR)\JDFAutoSideSewingParams.obj" \
	"$(INTDIR)\JDFAutoSpinePreparationParams.obj" \
	"$(INTDIR)\JDFAutoSpineTapingParams.obj" \
	"$(INTDIR)\JDFAutoStackingParams.obj" \
	"$(INTDIR)\JDFAutoStitchingParams.obj" \
	"$(INTDIR)\JDFAutoStrap.obj" \
	"$(INTDIR)\JDFAutoStrappingParams.obj" \
	"$(INTDIR)\JDFAutoStripBindingParams.obj" \
	"$(INTDIR)\JDFAutoStrippingParams.obj" \
	"$(INTDIR)\JDFAutoSurface.obj" \
	"$(INTDIR)\JDFAutoThreadSealingParams.obj" \
	"$(INTDIR)\JDFAutoThreadSewingParams.obj" \
	"$(INTDIR)\JDFAutoTile.obj" \
	"$(INTDIR)\JDFAutoTool.obj" \
	"$(INTDIR)\JDFAutoTransferCurve.obj" \
	"$(INTDIR)\JDFAutoTransferCurvePool.obj" \
	"$(INTDIR)\JDFAutoTransferFunctionControl.obj" \
	"$(INTDIR)\JDFAutoTrappingDetails.obj" \
	"$(INTDIR)\JDFAutoTrappingParams.obj" \
	"$(INTDIR)\JDFAutoTrapRegion.obj" \
	"$(INTDIR)\JDFAutoTrimmingParams.obj" \
	"$(INTDIR)\JDFAutoVerificationParams.obj" \
	"$(INTDIR)\JDFAutoWireCombBindingParams.obj" \
	"$(INTDIR)\JDFAutoWrappingParams.obj" \
	"$(INTDIR)\JDFArgumentValue.obj" \
	"$(INTDIR)\JDFAutoAdvancedParams.obj" \
	"$(INTDIR)\JDFAutoApprovalPerson.obj" \
	"$(INTDIR)\JDFAutoArgumentValue.obj" \
	"$(INTDIR)\JDFAutoAssemblySection.obj" \
	"$(INTDIR)\JDFAutoBand.obj" \
	"$(INTDIR)\JDFAutoBasicPreflightTest.obj" \
	"$(INTDIR)\JDFAutoBindingQualityParams.obj" \
	"$(INTDIR)\JDFAutoBoxArgument.obj" \
	"$(INTDIR)\JDFAutoBoxToBoxDifference.obj" \
	"$(INTDIR)\JDFAutoBundleItem.obj" \
	"$(INTDIR)\JDFAutoCCITTFaxParams.obj" \
	"$(INTDIR)\JDFAutoCollatingItem.obj" \
	"$(INTDIR)\JDFAutoColorantZoneDetails.obj" \
	"$(INTDIR)\JDFAutoColorCorrectionOp.obj" \
	"$(INTDIR)\JDFAutoColorSpaceSubstitute.obj" \
	"$(INTDIR)\JDFAutoContainer.obj" \
	"$(INTDIR)\JDFAutoContentObject.obj" \
	"$(INTDIR)\JDFAutoCrease.obj" \
	"$(INTDIR)\JDFAutoCut.obj" \
	"$(INTDIR)\JDFAutoDCTParams.obj" \
	"$(INTDIR)\JDFAutoDependencies.obj" \
	"$(INTDIR)\JDFAutoDeviceNColor.obj" \
	"$(INTDIR)\JDFAutoDrop.obj" \
	"$(INTDIR)\JDFAutoDropItem.obj" \
	"$(INTDIR)\JDFAutoDynamicField.obj" \
	"$(INTDIR)\JDFAutoDynamicInput.obj" \
	"$(INTDIR)\JDFAutoEmboss.obj" \
	"$(INTDIR)\JDFAutoEndSheet.obj" \
	"$(INTDIR)\JDFAutoFeeder.obj" \
	"$(INTDIR)\JDFAutoFeederQualityParams.obj" \
	"$(INTDIR)\JDFAutoFileAlias.obj" \
	"$(INTDIR)\JDFAutoFlateParams.obj" \
	"$(INTDIR)\JDFAutoGlue.obj" \
	"$(INTDIR)\JDFAutoIcon.obj" \
	"$(INTDIR)\JDFAutoIconList.obj" \
	"$(INTDIR)\JDFAutoIDPCover.obj" \
	"$(INTDIR)\JDFAutoIDPFinishing.obj" \
	"$(INTDIR)\JDFAutoIDPFolding.obj" \
	"$(INTDIR)\JDFAutoIDPHoleMaking.obj" \
	"$(INTDIR)\JDFAutoIDPImageShift.obj" \
	"$(INTDIR)\JDFAutoIDPJobSheet.obj" \
	"$(INTDIR)\JDFAutoIDPLayout.obj" \
	"$(INTDIR)\JDFAutoIDPStitching.obj" \
	"$(INTDIR)\JDFAutoIDPTrimming.obj" \
	"$(INTDIR)\JDFAutoImageCompression.obj" \
	"$(INTDIR)\JDFAutoImageShift.obj" \
	"$(INTDIR)\JDFAutoLayerDetails.obj" \
	"$(INTDIR)\JDFAutoLayerList.obj" \
	"$(INTDIR)\JDFAutoLongFold.obj" \
	"$(INTDIR)\JDFAutoLongGlue.obj" \
	"$(INTDIR)\JDFAutoLongPerforate.obj" \
	"$(INTDIR)\JDFAutoLongSlit.obj" \
	"$(INTDIR)\JDFAutoLZWParams.obj" \
	"$(INTDIR)\JDFAutoMarkObject.obj" \
	"$(INTDIR)\JDFAutoNumberingParam.obj" \
	"$(INTDIR)\JDFAutoPageCell.obj" \
	"$(INTDIR)\JDFAutoPageData.obj" \
	"$(INTDIR)\JDFAutoPDFInterpretingParams.obj" \
	"$(INTDIR)\JDFAutoPDFXParams.obj" \
	"$(INTDIR)\JDFAutoPerforate.obj" \
	"$(INTDIR)\JDFAutoPixelColorant.obj" \
	"$(INTDIR)\JDFAutoPosition.obj" \
	"$(INTDIR)\JDFAutoPreflightAction.obj" \
	"$(INTDIR)\JDFAutoPreflightArgument.obj" \
	"$(INTDIR)\JDFAutoPreflightConstraint.obj" \
	"$(INTDIR)\JDFAutoPreflightDetail.obj" \
	"$(INTDIR)\JDFAutoPreflightInstance.obj" \
	"$(INTDIR)\JDFAutoPreflightInstanceDetail.obj" \
	"$(INTDIR)\JDFAutoPreflightValue.obj" \
	"$(INTDIR)\JDFAutoPRError.obj" \
	"$(INTDIR)\JDFAutoPRGroup.obj" \
	"$(INTDIR)\JDFAutoPrintConditionColor.obj" \
	"$(INTDIR)\JDFAutoPRItem.obj" \
	"$(INTDIR)\JDFAutoPROccurence.obj" \
	"$(INTDIR)\JDFAutoProperties.obj" \
	"$(INTDIR)\JDFAutoPRRule.obj" \
	"$(INTDIR)\JDFAutoPRRuleAttr.obj" \
	"$(INTDIR)\JDFAutoQualityMeasurement.obj" \
	"$(INTDIR)\JDFAutoResourceParam.obj" \
	"$(INTDIR)\JDFAutoScore.obj" \
	"$(INTDIR)\JDFAutoScreenSelector.obj" \
	"$(INTDIR)\JDFAutoShapeElement.obj" \
	"$(INTDIR)\JDFAutoSignature.obj" \
	"$(INTDIR)\JDFAutoSignatureCell.obj" \
	"$(INTDIR)\JDFAutoStringListValue.obj" \
	"$(INTDIR)\JDFAutoStripCellParams.obj" \
	"$(INTDIR)\JDFAutoThinPDFParams.obj" \
	"$(INTDIR)\JDFAutoTIFFEmbeddedFile.obj" \
	"$(INTDIR)\JDFAutoTIFFFormatParams.obj" \
	"$(INTDIR)\JDFAutoTIFFtag.obj" \
	"$(INTDIR)\JDFAutoTransferCurveSet.obj" \
	"$(INTDIR)\JDFAutoTrappingOrder.obj" \
	"$(INTDIR)\JDFAutoAction.obj" \
	"$(INTDIR)\JDFAutoActionPool.obj" \
	"$(INTDIR)\JDFAutoand.obj" \
	"$(INTDIR)\JDFAutocall.obj" \
	"$(INTDIR)\JDFAutochoice.obj" \
	"$(INTDIR)\JDFAutoDevCap.obj" \
	"$(INTDIR)\JDFAutoDevCaps.obj" \
	"$(INTDIR)\JDFAutoDeviceCap.obj" \
	"$(INTDIR)\JDFAutoDisplayGroup.obj" \
	"$(INTDIR)\JDFAutoDisplayGroupPool.obj" \
	"$(INTDIR)\JDFAutoFeatureAttribute.obj" \
	"$(INTDIR)\JDFAutoFeaturePool.obj" \
	"$(INTDIR)\JDFAutoLoc.obj" \
	"$(INTDIR)\JDFAutomacro.obj" \
	"$(INTDIR)\JDFAutoMacroPool.obj" \
	"$(INTDIR)\JDFAutonot.obj" \
	"$(INTDIR)\JDFAutoor.obj" \
	"$(INTDIR)\JDFAutootherwise.obj" \
	"$(INTDIR)\JDFAutoPerformance.obj" \
	"$(INTDIR)\JDFAutoset.obj" \
	"$(INTDIR)\JDFAutoTest.obj" \
	"$(INTDIR)\JDFAutoTestPool.obj" \
	"$(INTDIR)\JDFAutoTestRef.obj" \
	"$(INTDIR)\JDFAutoValue.obj" \
	"$(INTDIR)\JDFAutoValueLoc.obj" \
	"$(INTDIR)\JDFAutowhen.obj" \
	"$(INTDIR)\JDFAutoxor.obj" \
	"$(INTDIR)\JDFAutoEnumerationSpan.obj" \
	"$(INTDIR)\JDFAutoPRGroupOccurence.obj" \
	"$(INTDIR)\JDFAutoPRGroupOccurenceBase.obj" \
	"$(INTDIR)\JDFPreflightConstraintsPool.obj" \
	"$(INTDIR)\JDFPreflightResultsPool.obj" \
	"$(INTDIR)\JDFPRGroupOccurence.obj" \
	"$(INTDIR)\JDFPRGroupOccurenceBase.obj" \
	"$(INTDIR)\JDFDateTimeRange.obj" \
	"$(INTDIR)\JDFDateTimeRangeList.obj" \
	"$(INTDIR)\JDFDurationRange.obj" \
	"$(INTDIR)\JDFDurationRangeList.obj" \
	"$(INTDIR)\JDFIntegerRange.obj" \
	"$(INTDIR)\JDFIntegerRangeList.obj" \
	"$(INTDIR)\JDFNameRangeList.obj" \
	"$(INTDIR)\JDFNumberRangeList.obj" \
	"$(INTDIR)\JDFNumTypeList.obj" \
	"$(INTDIR)\JDFParser.obj" \
	"$(INTDIR)\JDFRange.obj" \
	"$(INTDIR)\JDFRangeList.obj" \
	"$(INTDIR)\JDFXYPairRangeList.obj" \
	"$(INTDIR)\KElement.obj" \
	"$(INTDIR)\KElementStrings.obj" \
	"$(INTDIR)\MyDate.obj" \
	"$(INTDIR)\vElement.obj" \
	"$(INTDIR)\XMLDoc.obj" \
	"$(INTDIR)\XMLDocUserData.obj"

"$(OUTDIR)\JDFWrapperLib.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug LineOnly"

OUTDIR=.\..\..\..\Build\Win32\VC6\DebugLineOnly
INTDIR=.\..\..\..\Build\Win32\VC6\DebugLineOnly\obj\JDFWrapperLib
# Begin Custom Macros
OutDir=.\..\..\..\Build\Win32\VC6\DebugLineOnly
# End Custom Macros

ALL : "$(OUTDIR)\JDFWrapperLib_D.lib" "$(OUTDIR)\JDFWrapperLib.bsc"


CLEAN :
	-@erase "$(INTDIR)\JDFAcknowledge.obj"
	-@erase "$(INTDIR)\JDFAcknowledge.sbr"
	-@erase "$(INTDIR)\JDFAction.obj"
	-@erase "$(INTDIR)\JDFAction.sbr"
	-@erase "$(INTDIR)\JDFActionPool.obj"
	-@erase "$(INTDIR)\JDFActionPool.sbr"
	-@erase "$(INTDIR)\JDFAdded.obj"
	-@erase "$(INTDIR)\JDFAdded.sbr"
	-@erase "$(INTDIR)\JDFAddress.obj"
	-@erase "$(INTDIR)\JDFAddress.sbr"
	-@erase "$(INTDIR)\JDFAdhesiveBinding.obj"
	-@erase "$(INTDIR)\JDFAdhesiveBinding.sbr"
	-@erase "$(INTDIR)\JDFAdhesiveBindingParams.obj"
	-@erase "$(INTDIR)\JDFAdhesiveBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAdvancedParams.obj"
	-@erase "$(INTDIR)\JDFAdvancedParams.sbr"
	-@erase "$(INTDIR)\JDFAmountPool.obj"
	-@erase "$(INTDIR)\JDFAmountPool.sbr"
	-@erase "$(INTDIR)\JDFAncestor.obj"
	-@erase "$(INTDIR)\JDFAncestor.sbr"
	-@erase "$(INTDIR)\JDFAncestorPool.obj"
	-@erase "$(INTDIR)\JDFAncestorPool.sbr"
	-@erase "$(INTDIR)\JDFand.obj"
	-@erase "$(INTDIR)\JDFand.sbr"
	-@erase "$(INTDIR)\JDFApprovalParams.obj"
	-@erase "$(INTDIR)\JDFApprovalParams.sbr"
	-@erase "$(INTDIR)\JDFApprovalPerson.obj"
	-@erase "$(INTDIR)\JDFApprovalPerson.sbr"
	-@erase "$(INTDIR)\JDFApprovalSuccess.obj"
	-@erase "$(INTDIR)\JDFApprovalSuccess.sbr"
	-@erase "$(INTDIR)\JDFArgumentValue.obj"
	-@erase "$(INTDIR)\JDFArgumentValue.sbr"
	-@erase "$(INTDIR)\JDFArtDelivery.obj"
	-@erase "$(INTDIR)\JDFArtDelivery.sbr"
	-@erase "$(INTDIR)\JDFArtDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFArtDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFAssembly.obj"
	-@erase "$(INTDIR)\JDFAssembly.sbr"
	-@erase "$(INTDIR)\JDFAssemblySection.obj"
	-@erase "$(INTDIR)\JDFAssemblySection.sbr"
	-@erase "$(INTDIR)\JDFAssetListCreationParams.obj"
	-@erase "$(INTDIR)\JDFAssetListCreationParams.sbr"
	-@erase "$(INTDIR)\JDFAudit.obj"
	-@erase "$(INTDIR)\JDFAudit.sbr"
	-@erase "$(INTDIR)\JDFAuditPool.obj"
	-@erase "$(INTDIR)\JDFAuditPool.sbr"
	-@erase "$(INTDIR)\JDFAutoAcknowledge.obj"
	-@erase "$(INTDIR)\JDFAutoAcknowledge.sbr"
	-@erase "$(INTDIR)\JDFAutoAction.obj"
	-@erase "$(INTDIR)\JDFAutoAction.sbr"
	-@erase "$(INTDIR)\JDFAutoActionPool.obj"
	-@erase "$(INTDIR)\JDFAutoActionPool.sbr"
	-@erase "$(INTDIR)\JDFAutoAdded.obj"
	-@erase "$(INTDIR)\JDFAutoAdded.sbr"
	-@erase "$(INTDIR)\JDFAutoAddress.obj"
	-@erase "$(INTDIR)\JDFAutoAddress.sbr"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBinding.obj"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoAdhesiveBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoAdvancedParams.obj"
	-@erase "$(INTDIR)\JDFAutoAdvancedParams.sbr"
	-@erase "$(INTDIR)\JDFAutoAmountPool.obj"
	-@erase "$(INTDIR)\JDFAutoAmountPool.sbr"
	-@erase "$(INTDIR)\JDFAutoAncestor.obj"
	-@erase "$(INTDIR)\JDFAutoAncestor.sbr"
	-@erase "$(INTDIR)\JDFAutoAncestorPool.obj"
	-@erase "$(INTDIR)\JDFAutoAncestorPool.sbr"
	-@erase "$(INTDIR)\JDFAutoand.obj"
	-@erase "$(INTDIR)\JDFAutoand.sbr"
	-@erase "$(INTDIR)\JDFAutoApprovalParams.obj"
	-@erase "$(INTDIR)\JDFAutoApprovalParams.sbr"
	-@erase "$(INTDIR)\JDFAutoApprovalPerson.obj"
	-@erase "$(INTDIR)\JDFAutoApprovalPerson.sbr"
	-@erase "$(INTDIR)\JDFAutoApprovalSuccess.obj"
	-@erase "$(INTDIR)\JDFAutoApprovalSuccess.sbr"
	-@erase "$(INTDIR)\JDFAutoArgumentValue.obj"
	-@erase "$(INTDIR)\JDFAutoArgumentValue.sbr"
	-@erase "$(INTDIR)\JDFAutoArtDelivery.obj"
	-@erase "$(INTDIR)\JDFAutoArtDelivery.sbr"
	-@erase "$(INTDIR)\JDFAutoArtDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFAutoArtDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoAssembly.obj"
	-@erase "$(INTDIR)\JDFAutoAssembly.sbr"
	-@erase "$(INTDIR)\JDFAutoAssemblySection.obj"
	-@erase "$(INTDIR)\JDFAutoAssemblySection.sbr"
	-@erase "$(INTDIR)\JDFAutoAssetListCreationParams.obj"
	-@erase "$(INTDIR)\JDFAutoAssetListCreationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoAutomatedOverprintParams.obj"
	-@erase "$(INTDIR)\JDFAutoAutomatedOverprintParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBand.obj"
	-@erase "$(INTDIR)\JDFAutoBand.sbr"
	-@erase "$(INTDIR)\JDFAutoBarcode.obj"
	-@erase "$(INTDIR)\JDFAutoBarcode.sbr"
	-@erase "$(INTDIR)\JDFAutoBasicPreflightTest.obj"
	-@erase "$(INTDIR)\JDFAutoBasicPreflightTest.sbr"
	-@erase "$(INTDIR)\JDFAutoBinderySignature.obj"
	-@erase "$(INTDIR)\JDFAutoBinderySignature.sbr"
	-@erase "$(INTDIR)\JDFAutoBindingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoBindingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoBindingQualityParams.obj"
	-@erase "$(INTDIR)\JDFAutoBindingQualityParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBindItem.obj"
	-@erase "$(INTDIR)\JDFAutoBindItem.sbr"
	-@erase "$(INTDIR)\JDFAutoBindList.obj"
	-@erase "$(INTDIR)\JDFAutoBindList.sbr"
	-@erase "$(INTDIR)\JDFAutoBlockPreparationParams.obj"
	-@erase "$(INTDIR)\JDFAutoBlockPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBookCase.obj"
	-@erase "$(INTDIR)\JDFAutoBookCase.sbr"
	-@erase "$(INTDIR)\JDFAutoBoxArgument.obj"
	-@erase "$(INTDIR)\JDFAutoBoxArgument.sbr"
	-@erase "$(INTDIR)\JDFAutoBoxPackingParams.obj"
	-@erase "$(INTDIR)\JDFAutoBoxPackingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBoxToBoxDifference.obj"
	-@erase "$(INTDIR)\JDFAutoBoxToBoxDifference.sbr"
	-@erase "$(INTDIR)\JDFAutoBufferParams.obj"
	-@erase "$(INTDIR)\JDFAutoBufferParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBundle.obj"
	-@erase "$(INTDIR)\JDFAutoBundle.sbr"
	-@erase "$(INTDIR)\JDFAutoBundleItem.obj"
	-@erase "$(INTDIR)\JDFAutoBundleItem.sbr"
	-@erase "$(INTDIR)\JDFAutoBundlingParams.obj"
	-@erase "$(INTDIR)\JDFAutoBundlingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoBusinessInfo.obj"
	-@erase "$(INTDIR)\JDFAutoBusinessInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoByteMap.obj"
	-@erase "$(INTDIR)\JDFAutoByteMap.sbr"
	-@erase "$(INTDIR)\JDFAutocall.obj"
	-@erase "$(INTDIR)\JDFAutocall.sbr"
	-@erase "$(INTDIR)\JDFAutoCaseMakingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCaseMakingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCasingInParams.obj"
	-@erase "$(INTDIR)\JDFAutoCasingInParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCCITTFaxParams.obj"
	-@erase "$(INTDIR)\JDFAutoCCITTFaxParams.sbr"
	-@erase "$(INTDIR)\JDFAutoChangedAttribute.obj"
	-@erase "$(INTDIR)\JDFAutoChangedAttribute.sbr"
	-@erase "$(INTDIR)\JDFAutoChangedPath.obj"
	-@erase "$(INTDIR)\JDFAutoChangedPath.sbr"
	-@erase "$(INTDIR)\JDFAutoChannelBinding.obj"
	-@erase "$(INTDIR)\JDFAutoChannelBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoChannelBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoChannelBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutochoice.obj"
	-@erase "$(INTDIR)\JDFAutochoice.sbr"
	-@erase "$(INTDIR)\JDFAutoCIELABMeasuringField.obj"
	-@erase "$(INTDIR)\JDFAutoCIELABMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFAutoCoilBinding.obj"
	-@erase "$(INTDIR)\JDFAutoCoilBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoCoilBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCoilBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCollatingItem.obj"
	-@erase "$(INTDIR)\JDFAutoCollatingItem.sbr"
	-@erase "$(INTDIR)\JDFAutoCollectingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCollectingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoColor.obj"
	-@erase "$(INTDIR)\JDFAutoColor.sbr"
	-@erase "$(INTDIR)\JDFAutoColorantAlias.obj"
	-@erase "$(INTDIR)\JDFAutoColorantAlias.sbr"
	-@erase "$(INTDIR)\JDFAutoColorantControl.obj"
	-@erase "$(INTDIR)\JDFAutoColorantControl.sbr"
	-@erase "$(INTDIR)\JDFAutoColorantZoneDetails.obj"
	-@erase "$(INTDIR)\JDFAutoColorantZoneDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoColorControlStrip.obj"
	-@erase "$(INTDIR)\JDFAutoColorControlStrip.sbr"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionOp.obj"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionOp.sbr"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionParams.obj"
	-@erase "$(INTDIR)\JDFAutoColorCorrectionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoColorIntent.obj"
	-@erase "$(INTDIR)\JDFAutoColorIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoColorMeasurementConditions.obj"
	-@erase "$(INTDIR)\JDFAutoColorMeasurementConditions.sbr"
	-@erase "$(INTDIR)\JDFAutoColorPool.obj"
	-@erase "$(INTDIR)\JDFAutoColorPool.sbr"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionOp.obj"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionOp.sbr"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoColorSpaceConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoColorSpaceSubstitute.obj"
	-@erase "$(INTDIR)\JDFAutoColorSpaceSubstitute.sbr"
	-@erase "$(INTDIR)\JDFAutoColorsUsed.obj"
	-@erase "$(INTDIR)\JDFAutoColorsUsed.sbr"
	-@erase "$(INTDIR)\JDFAutoComChannel.obj"
	-@erase "$(INTDIR)\JDFAutoComChannel.sbr"
	-@erase "$(INTDIR)\JDFAutoCommand.obj"
	-@erase "$(INTDIR)\JDFAutoCommand.sbr"
	-@erase "$(INTDIR)\JDFAutoComment.obj"
	-@erase "$(INTDIR)\JDFAutoComment.sbr"
	-@erase "$(INTDIR)\JDFAutoCompany.obj"
	-@erase "$(INTDIR)\JDFAutoCompany.sbr"
	-@erase "$(INTDIR)\JDFAutoComponent.obj"
	-@erase "$(INTDIR)\JDFAutoComponent.sbr"
	-@erase "$(INTDIR)\JDFAutoContact.obj"
	-@erase "$(INTDIR)\JDFAutoContact.sbr"
	-@erase "$(INTDIR)\JDFAutoContactCopyParams.obj"
	-@erase "$(INTDIR)\JDFAutoContactCopyParams.sbr"
	-@erase "$(INTDIR)\JDFAutoContainer.obj"
	-@erase "$(INTDIR)\JDFAutoContainer.sbr"
	-@erase "$(INTDIR)\JDFAutoContentObject.obj"
	-@erase "$(INTDIR)\JDFAutoContentObject.sbr"
	-@erase "$(INTDIR)\JDFAutoConventionalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFAutoConventionalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCostCenter.obj"
	-@erase "$(INTDIR)\JDFAutoCostCenter.sbr"
	-@erase "$(INTDIR)\JDFAutoCounterReset.obj"
	-@erase "$(INTDIR)\JDFAutoCounterReset.sbr"
	-@erase "$(INTDIR)\JDFAutoCoverApplicationParams.obj"
	-@erase "$(INTDIR)\JDFAutoCoverApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCrease.obj"
	-@erase "$(INTDIR)\JDFAutoCrease.sbr"
	-@erase "$(INTDIR)\JDFAutoCreasingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCreasingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoCreated.obj"
	-@erase "$(INTDIR)\JDFAutoCreated.sbr"
	-@erase "$(INTDIR)\JDFAutoCreditCard.obj"
	-@erase "$(INTDIR)\JDFAutoCreditCard.sbr"
	-@erase "$(INTDIR)\JDFAutoCustomerInfo.obj"
	-@erase "$(INTDIR)\JDFAutoCustomerInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoCustomerMessage.obj"
	-@erase "$(INTDIR)\JDFAutoCustomerMessage.sbr"
	-@erase "$(INTDIR)\JDFAutoCut.obj"
	-@erase "$(INTDIR)\JDFAutoCut.sbr"
	-@erase "$(INTDIR)\JDFAutoCutBlock.obj"
	-@erase "$(INTDIR)\JDFAutoCutBlock.sbr"
	-@erase "$(INTDIR)\JDFAutoCutMark.obj"
	-@erase "$(INTDIR)\JDFAutoCutMark.sbr"
	-@erase "$(INTDIR)\JDFAutoCuttingParams.obj"
	-@erase "$(INTDIR)\JDFAutoCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDBMergeParams.obj"
	-@erase "$(INTDIR)\JDFAutoDBMergeParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDBRules.obj"
	-@erase "$(INTDIR)\JDFAutoDBRules.sbr"
	-@erase "$(INTDIR)\JDFAutoDBSchema.obj"
	-@erase "$(INTDIR)\JDFAutoDBSchema.sbr"
	-@erase "$(INTDIR)\JDFAutoDBSelection.obj"
	-@erase "$(INTDIR)\JDFAutoDBSelection.sbr"
	-@erase "$(INTDIR)\JDFAutoDCTParams.obj"
	-@erase "$(INTDIR)\JDFAutoDCTParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDeleted.obj"
	-@erase "$(INTDIR)\JDFAutoDeleted.sbr"
	-@erase "$(INTDIR)\JDFAutoDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFAutoDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFAutoDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDensityMeasuringField.obj"
	-@erase "$(INTDIR)\JDFAutoDensityMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFAutoDependencies.obj"
	-@erase "$(INTDIR)\JDFAutoDependencies.sbr"
	-@erase "$(INTDIR)\JDFAutoDevCap.obj"
	-@erase "$(INTDIR)\JDFAutoDevCap.sbr"
	-@erase "$(INTDIR)\JDFAutoDevCaps.obj"
	-@erase "$(INTDIR)\JDFAutoDevCaps.sbr"
	-@erase "$(INTDIR)\JDFAutoDevelopingParams.obj"
	-@erase "$(INTDIR)\JDFAutoDevelopingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDevice.obj"
	-@erase "$(INTDIR)\JDFAutoDevice.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceCap.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceCap.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceFilter.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceInfo.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceList.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceList.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceMark.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceMark.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceNColor.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceNColor.sbr"
	-@erase "$(INTDIR)\JDFAutoDeviceNSpace.obj"
	-@erase "$(INTDIR)\JDFAutoDeviceNSpace.sbr"
	-@erase "$(INTDIR)\JDFAutoDigitalDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFAutoDigitalDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDigitalMedia.obj"
	-@erase "$(INTDIR)\JDFAutoDigitalMedia.sbr"
	-@erase "$(INTDIR)\JDFAutoDigitalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFAutoDigitalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDisjointing.obj"
	-@erase "$(INTDIR)\JDFAutoDisjointing.sbr"
	-@erase "$(INTDIR)\JDFAutoDisplayGroup.obj"
	-@erase "$(INTDIR)\JDFAutoDisplayGroup.sbr"
	-@erase "$(INTDIR)\JDFAutoDisplayGroupPool.obj"
	-@erase "$(INTDIR)\JDFAutoDisplayGroupPool.sbr"
	-@erase "$(INTDIR)\JDFAutoDisposition.obj"
	-@erase "$(INTDIR)\JDFAutoDisposition.sbr"
	-@erase "$(INTDIR)\JDFAutoDividingParams.obj"
	-@erase "$(INTDIR)\JDFAutoDividingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoDrop.obj"
	-@erase "$(INTDIR)\JDFAutoDrop.sbr"
	-@erase "$(INTDIR)\JDFAutoDropIntent.obj"
	-@erase "$(INTDIR)\JDFAutoDropIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoDropItem.obj"
	-@erase "$(INTDIR)\JDFAutoDropItem.sbr"
	-@erase "$(INTDIR)\JDFAutoDropItemIntent.obj"
	-@erase "$(INTDIR)\JDFAutoDropItemIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoDynamicField.obj"
	-@erase "$(INTDIR)\JDFAutoDynamicField.sbr"
	-@erase "$(INTDIR)\JDFAutoDynamicInput.obj"
	-@erase "$(INTDIR)\JDFAutoDynamicInput.sbr"
	-@erase "$(INTDIR)\JDFAutoEdgeGluing.obj"
	-@erase "$(INTDIR)\JDFAutoEdgeGluing.sbr"
	-@erase "$(INTDIR)\JDFAutoElementColorParams.obj"
	-@erase "$(INTDIR)\JDFAutoElementColorParams.sbr"
	-@erase "$(INTDIR)\JDFAutoEmboss.obj"
	-@erase "$(INTDIR)\JDFAutoEmboss.sbr"
	-@erase "$(INTDIR)\JDFAutoEmbossingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoEmbossingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoEmbossingItem.obj"
	-@erase "$(INTDIR)\JDFAutoEmbossingItem.sbr"
	-@erase "$(INTDIR)\JDFAutoEmbossingParams.obj"
	-@erase "$(INTDIR)\JDFAutoEmbossingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoEmployee.obj"
	-@erase "$(INTDIR)\JDFAutoEmployee.sbr"
	-@erase "$(INTDIR)\JDFAutoEmployeeDef.obj"
	-@erase "$(INTDIR)\JDFAutoEmployeeDef.sbr"
	-@erase "$(INTDIR)\JDFAutoEndSheet.obj"
	-@erase "$(INTDIR)\JDFAutoEndSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoEndSheetGluingParams.obj"
	-@erase "$(INTDIR)\JDFAutoEndSheetGluingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoEnumerationSpan.obj"
	-@erase "$(INTDIR)\JDFAutoEnumerationSpan.sbr"
	-@erase "$(INTDIR)\JDFAutoError.obj"
	-@erase "$(INTDIR)\JDFAutoError.sbr"
	-@erase "$(INTDIR)\JDFAutoEvent.obj"
	-@erase "$(INTDIR)\JDFAutoEvent.sbr"
	-@erase "$(INTDIR)\JDFAutoExposedMedia.obj"
	-@erase "$(INTDIR)\JDFAutoExposedMedia.sbr"
	-@erase "$(INTDIR)\JDFAutoFCNKey.obj"
	-@erase "$(INTDIR)\JDFAutoFCNKey.sbr"
	-@erase "$(INTDIR)\JDFAutoFeatureAttribute.obj"
	-@erase "$(INTDIR)\JDFAutoFeatureAttribute.sbr"
	-@erase "$(INTDIR)\JDFAutoFeaturePool.obj"
	-@erase "$(INTDIR)\JDFAutoFeaturePool.sbr"
	-@erase "$(INTDIR)\JDFAutoFeeder.obj"
	-@erase "$(INTDIR)\JDFAutoFeeder.sbr"
	-@erase "$(INTDIR)\JDFAutoFeederQualityParams.obj"
	-@erase "$(INTDIR)\JDFAutoFeederQualityParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFeedingParams.obj"
	-@erase "$(INTDIR)\JDFAutoFeedingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFileAlias.obj"
	-@erase "$(INTDIR)\JDFAutoFileAlias.sbr"
	-@erase "$(INTDIR)\JDFAutoFileSpec.obj"
	-@erase "$(INTDIR)\JDFAutoFileSpec.sbr"
	-@erase "$(INTDIR)\JDFAutoFitPolicy.obj"
	-@erase "$(INTDIR)\JDFAutoFitPolicy.sbr"
	-@erase "$(INTDIR)\JDFAutoFlateParams.obj"
	-@erase "$(INTDIR)\JDFAutoFlateParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFlushedResources.obj"
	-@erase "$(INTDIR)\JDFAutoFlushedResources.sbr"
	-@erase "$(INTDIR)\JDFAutoFlushQueueParams.obj"
	-@erase "$(INTDIR)\JDFAutoFlushQueueParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFlushResourceParams.obj"
	-@erase "$(INTDIR)\JDFAutoFlushResourceParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFold.obj"
	-@erase "$(INTDIR)\JDFAutoFold.sbr"
	-@erase "$(INTDIR)\JDFAutoFoldingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoFoldingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoFoldingParams.obj"
	-@erase "$(INTDIR)\JDFAutoFoldingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFontParams.obj"
	-@erase "$(INTDIR)\JDFAutoFontParams.sbr"
	-@erase "$(INTDIR)\JDFAutoFontPolicy.obj"
	-@erase "$(INTDIR)\JDFAutoFontPolicy.sbr"
	-@erase "$(INTDIR)\JDFAutoFormatConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoFormatConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoGatheringParams.obj"
	-@erase "$(INTDIR)\JDFAutoGatheringParams.sbr"
	-@erase "$(INTDIR)\JDFAutoGlue.obj"
	-@erase "$(INTDIR)\JDFAutoGlue.sbr"
	-@erase "$(INTDIR)\JDFAutoGlueApplication.obj"
	-@erase "$(INTDIR)\JDFAutoGlueApplication.sbr"
	-@erase "$(INTDIR)\JDFAutoGlueLine.obj"
	-@erase "$(INTDIR)\JDFAutoGlueLine.sbr"
	-@erase "$(INTDIR)\JDFAutoGluingParams.obj"
	-@erase "$(INTDIR)\JDFAutoGluingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoHardCoverBinding.obj"
	-@erase "$(INTDIR)\JDFAutoHardCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoHeadBandApplicationParams.obj"
	-@erase "$(INTDIR)\JDFAutoHeadBandApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoHole.obj"
	-@erase "$(INTDIR)\JDFAutoHole.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleLine.obj"
	-@erase "$(INTDIR)\JDFAutoHoleLine.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleList.obj"
	-@erase "$(INTDIR)\JDFAutoHoleList.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleMakingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoHoleMakingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoHoleMakingParams.obj"
	-@erase "$(INTDIR)\JDFAutoHoleMakingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoIcon.obj"
	-@erase "$(INTDIR)\JDFAutoIcon.sbr"
	-@erase "$(INTDIR)\JDFAutoIconList.obj"
	-@erase "$(INTDIR)\JDFAutoIconList.sbr"
	-@erase "$(INTDIR)\JDFAutoIdentificationField.obj"
	-@erase "$(INTDIR)\JDFAutoIdentificationField.sbr"
	-@erase "$(INTDIR)\JDFAutoIDInfo.obj"
	-@erase "$(INTDIR)\JDFAutoIDInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPCover.obj"
	-@erase "$(INTDIR)\JDFAutoIDPCover.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPFinishing.obj"
	-@erase "$(INTDIR)\JDFAutoIDPFinishing.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPFolding.obj"
	-@erase "$(INTDIR)\JDFAutoIDPFolding.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPHoleMaking.obj"
	-@erase "$(INTDIR)\JDFAutoIDPHoleMaking.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPImageShift.obj"
	-@erase "$(INTDIR)\JDFAutoIDPImageShift.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPJobSheet.obj"
	-@erase "$(INTDIR)\JDFAutoIDPJobSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPLayout.obj"
	-@erase "$(INTDIR)\JDFAutoIDPLayout.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPrintingParams.obj"
	-@erase "$(INTDIR)\JDFAutoIDPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPStitching.obj"
	-@erase "$(INTDIR)\JDFAutoIDPStitching.sbr"
	-@erase "$(INTDIR)\JDFAutoIDPTrimming.obj"
	-@erase "$(INTDIR)\JDFAutoIDPTrimming.sbr"
	-@erase "$(INTDIR)\JDFAutoImageCompression.obj"
	-@erase "$(INTDIR)\JDFAutoImageCompression.sbr"
	-@erase "$(INTDIR)\JDFAutoImageCompressionParams.obj"
	-@erase "$(INTDIR)\JDFAutoImageCompressionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoImageReplacementParams.obj"
	-@erase "$(INTDIR)\JDFAutoImageReplacementParams.sbr"
	-@erase "$(INTDIR)\JDFAutoImageSetterParams.obj"
	-@erase "$(INTDIR)\JDFAutoImageSetterParams.sbr"
	-@erase "$(INTDIR)\JDFAutoImageShift.obj"
	-@erase "$(INTDIR)\JDFAutoImageShift.sbr"
	-@erase "$(INTDIR)\JDFAutoInk.obj"
	-@erase "$(INTDIR)\JDFAutoInk.sbr"
	-@erase "$(INTDIR)\JDFAutoInkZoneCalculationParams.obj"
	-@erase "$(INTDIR)\JDFAutoInkZoneCalculationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoInkZoneProfile.obj"
	-@erase "$(INTDIR)\JDFAutoInkZoneProfile.sbr"
	-@erase "$(INTDIR)\JDFAutoInsert.obj"
	-@erase "$(INTDIR)\JDFAutoInsert.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoInsertingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertingParams.obj"
	-@erase "$(INTDIR)\JDFAutoInsertingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertList.obj"
	-@erase "$(INTDIR)\JDFAutoInsertList.sbr"
	-@erase "$(INTDIR)\JDFAutoInsertSheet.obj"
	-@erase "$(INTDIR)\JDFAutoInsertSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoInterpretedPDLData.obj"
	-@erase "$(INTDIR)\JDFAutoInterpretedPDLData.sbr"
	-@erase "$(INTDIR)\JDFAutoInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFAutoInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoJacketingParams.obj"
	-@erase "$(INTDIR)\JDFAutoJacketingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoJDFController.obj"
	-@erase "$(INTDIR)\JDFAutoJDFController.sbr"
	-@erase "$(INTDIR)\JDFAutoJDFService.obj"
	-@erase "$(INTDIR)\JDFAutoJDFService.sbr"
	-@erase "$(INTDIR)\JDFAutoJMF.obj"
	-@erase "$(INTDIR)\JDFAutoJMF.sbr"
	-@erase "$(INTDIR)\JDFAutoJobField.obj"
	-@erase "$(INTDIR)\JDFAutoJobField.sbr"
	-@erase "$(INTDIR)\JDFAutoJobPhase.obj"
	-@erase "$(INTDIR)\JDFAutoJobPhase.sbr"
	-@erase "$(INTDIR)\JDFAutoKnownMsgQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoKnownMsgQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLabelingParams.obj"
	-@erase "$(INTDIR)\JDFAutoLabelingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLaminatingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoLaminatingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoLaminatingParams.obj"
	-@erase "$(INTDIR)\JDFAutoLaminatingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLayerDetails.obj"
	-@erase "$(INTDIR)\JDFAutoLayerDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoLayerList.obj"
	-@erase "$(INTDIR)\JDFAutoLayerList.sbr"
	-@erase "$(INTDIR)\JDFAutoLayout.obj"
	-@erase "$(INTDIR)\JDFAutoLayout.sbr"
	-@erase "$(INTDIR)\JDFAutoLayoutElement.obj"
	-@erase "$(INTDIR)\JDFAutoLayoutElement.sbr"
	-@erase "$(INTDIR)\JDFAutoLayoutIntent.obj"
	-@erase "$(INTDIR)\JDFAutoLayoutIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoLayoutPreparationParams.obj"
	-@erase "$(INTDIR)\JDFAutoLayoutPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLoc.obj"
	-@erase "$(INTDIR)\JDFAutoLoc.sbr"
	-@erase "$(INTDIR)\JDFAutoLocation.obj"
	-@erase "$(INTDIR)\JDFAutoLocation.sbr"
	-@erase "$(INTDIR)\JDFAutoLongFold.obj"
	-@erase "$(INTDIR)\JDFAutoLongFold.sbr"
	-@erase "$(INTDIR)\JDFAutoLongGlue.obj"
	-@erase "$(INTDIR)\JDFAutoLongGlue.sbr"
	-@erase "$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.obj"
	-@erase "$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoLongPerforate.obj"
	-@erase "$(INTDIR)\JDFAutoLongPerforate.sbr"
	-@erase "$(INTDIR)\JDFAutoLongSlit.obj"
	-@erase "$(INTDIR)\JDFAutoLongSlit.sbr"
	-@erase "$(INTDIR)\JDFAutoLZWParams.obj"
	-@erase "$(INTDIR)\JDFAutoLZWParams.sbr"
	-@erase "$(INTDIR)\JDFAutomacro.obj"
	-@erase "$(INTDIR)\JDFAutomacro.sbr"
	-@erase "$(INTDIR)\JDFAutoMacroPool.obj"
	-@erase "$(INTDIR)\JDFAutoMacroPool.sbr"
	-@erase "$(INTDIR)\JDFAutoManualLaborParams.obj"
	-@erase "$(INTDIR)\JDFAutoManualLaborParams.sbr"
	-@erase "$(INTDIR)\JDFAutoMarkObject.obj"
	-@erase "$(INTDIR)\JDFAutoMarkObject.sbr"
	-@erase "$(INTDIR)\JDFAutomatedOverprintParams.obj"
	-@erase "$(INTDIR)\JDFAutomatedOverprintParams.sbr"
	-@erase "$(INTDIR)\JDFAutoMedia.obj"
	-@erase "$(INTDIR)\JDFAutoMedia.sbr"
	-@erase "$(INTDIR)\JDFAutoMediaIntent.obj"
	-@erase "$(INTDIR)\JDFAutoMediaIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoMediaSource.obj"
	-@erase "$(INTDIR)\JDFAutoMediaSource.sbr"
	-@erase "$(INTDIR)\JDFAutoMerged.obj"
	-@erase "$(INTDIR)\JDFAutoMerged.sbr"
	-@erase "$(INTDIR)\JDFAutoMessage.obj"
	-@erase "$(INTDIR)\JDFAutoMessage.sbr"
	-@erase "$(INTDIR)\JDFAutoMessageService.obj"
	-@erase "$(INTDIR)\JDFAutoMessageService.sbr"
	-@erase "$(INTDIR)\JDFAutoMISDetails.obj"
	-@erase "$(INTDIR)\JDFAutoMISDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoModified.obj"
	-@erase "$(INTDIR)\JDFAutoModified.sbr"
	-@erase "$(INTDIR)\JDFAutoModulePhase.obj"
	-@erase "$(INTDIR)\JDFAutoModulePhase.sbr"
	-@erase "$(INTDIR)\JDFAutoModuleStatus.obj"
	-@erase "$(INTDIR)\JDFAutoModuleStatus.sbr"
	-@erase "$(INTDIR)\JDFAutoMsgFilter.obj"
	-@erase "$(INTDIR)\JDFAutoMsgFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoNewJDFCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoNewJDFCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNewJDFQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoNewJDFQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfo.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfoCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfoCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfoQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfoQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNodeInfoResp.obj"
	-@erase "$(INTDIR)\JDFAutoNodeInfoResp.sbr"
	-@erase "$(INTDIR)\JDFAutonot.obj"
	-@erase "$(INTDIR)\JDFAutonot.sbr"
	-@erase "$(INTDIR)\JDFAutoNotification.obj"
	-@erase "$(INTDIR)\JDFAutoNotification.sbr"
	-@erase "$(INTDIR)\JDFAutoNotificationDef.obj"
	-@erase "$(INTDIR)\JDFAutoNotificationDef.sbr"
	-@erase "$(INTDIR)\JDFAutoNotificationFilter.obj"
	-@erase "$(INTDIR)\JDFAutoNotificationFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoNumberingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberingParam.obj"
	-@erase "$(INTDIR)\JDFAutoNumberingParam.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberingParams.obj"
	-@erase "$(INTDIR)\JDFAutoNumberingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoNumberItem.obj"
	-@erase "$(INTDIR)\JDFAutoNumberItem.sbr"
	-@erase "$(INTDIR)\JDFAutoObjectResolution.obj"
	-@erase "$(INTDIR)\JDFAutoObjectResolution.sbr"
	-@erase "$(INTDIR)\JDFAutoObservationTarget.obj"
	-@erase "$(INTDIR)\JDFAutoObservationTarget.sbr"
	-@erase "$(INTDIR)\JDFAutoOccupation.obj"
	-@erase "$(INTDIR)\JDFAutoOccupation.sbr"
	-@erase "$(INTDIR)\JDFAutoor.obj"
	-@erase "$(INTDIR)\JDFAutoor.sbr"
	-@erase "$(INTDIR)\JDFAutoOrderingParams.obj"
	-@erase "$(INTDIR)\JDFAutoOrderingParams.sbr"
	-@erase "$(INTDIR)\JDFAutootherwise.obj"
	-@erase "$(INTDIR)\JDFAutootherwise.sbr"
	-@erase "$(INTDIR)\JDFAutoPackingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoPackingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoPackingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPackingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPageCell.obj"
	-@erase "$(INTDIR)\JDFAutoPageCell.sbr"
	-@erase "$(INTDIR)\JDFAutoPageData.obj"
	-@erase "$(INTDIR)\JDFAutoPageData.sbr"
	-@erase "$(INTDIR)\JDFAutoPageList.obj"
	-@erase "$(INTDIR)\JDFAutoPageList.sbr"
	-@erase "$(INTDIR)\JDFAutoPallet.obj"
	-@erase "$(INTDIR)\JDFAutoPallet.sbr"
	-@erase "$(INTDIR)\JDFAutoPalletizingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPalletizingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPart.obj"
	-@erase "$(INTDIR)\JDFAutoPart.sbr"
	-@erase "$(INTDIR)\JDFAutoPartStatus.obj"
	-@erase "$(INTDIR)\JDFAutoPartStatus.sbr"
	-@erase "$(INTDIR)\JDFAutoPayment.obj"
	-@erase "$(INTDIR)\JDFAutoPayment.sbr"
	-@erase "$(INTDIR)\JDFAutoPDFInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPDFInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPDFToPSConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoPDFToPSConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPDFXParams.obj"
	-@erase "$(INTDIR)\JDFAutoPDFXParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPDLResourceAlias.obj"
	-@erase "$(INTDIR)\JDFAutoPDLResourceAlias.sbr"
	-@erase "$(INTDIR)\JDFAutoPerforate.obj"
	-@erase "$(INTDIR)\JDFAutoPerforate.sbr"
	-@erase "$(INTDIR)\JDFAutoPerforatingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPerforatingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPerformance.obj"
	-@erase "$(INTDIR)\JDFAutoPerformance.sbr"
	-@erase "$(INTDIR)\JDFAutoPerson.obj"
	-@erase "$(INTDIR)\JDFAutoPerson.sbr"
	-@erase "$(INTDIR)\JDFAutoPhaseTime.obj"
	-@erase "$(INTDIR)\JDFAutoPhaseTime.sbr"
	-@erase "$(INTDIR)\JDFAutoPipeParams.obj"
	-@erase "$(INTDIR)\JDFAutoPipeParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPixelColorant.obj"
	-@erase "$(INTDIR)\JDFAutoPixelColorant.sbr"
	-@erase "$(INTDIR)\JDFAutoPlaceHolderResource.obj"
	-@erase "$(INTDIR)\JDFAutoPlaceHolderResource.sbr"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBinding.obj"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPlasticCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPlateCopyParams.obj"
	-@erase "$(INTDIR)\JDFAutoPlateCopyParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPosition.obj"
	-@erase "$(INTDIR)\JDFAutoPosition.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightAction.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightAction.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightAnalysis.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightAnalysis.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightArgument.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightArgument.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightConstraint.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightConstraint.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightDetail.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightDetail.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightInstance.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightInstance.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightInstanceDetail.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightInstanceDetail.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightInventory.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightInventory.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightParams.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightProfile.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightProfile.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightReport.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightReport.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightReportRulePool.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightReportRulePool.sbr"
	-@erase "$(INTDIR)\JDFAutoPreflightValue.obj"
	-@erase "$(INTDIR)\JDFAutoPreflightValue.sbr"
	-@erase "$(INTDIR)\JDFAutoPRError.obj"
	-@erase "$(INTDIR)\JDFAutoPRError.sbr"
	-@erase "$(INTDIR)\JDFAutoPreview.obj"
	-@erase "$(INTDIR)\JDFAutoPreview.sbr"
	-@erase "$(INTDIR)\JDFAutoPreviewGenerationParams.obj"
	-@erase "$(INTDIR)\JDFAutoPreviewGenerationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPRGroup.obj"
	-@erase "$(INTDIR)\JDFAutoPRGroup.sbr"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurence.obj"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurence.sbr"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurenceBase.obj"
	-@erase "$(INTDIR)\JDFAutoPRGroupOccurenceBase.sbr"
	-@erase "$(INTDIR)\JDFAutoPricing.obj"
	-@erase "$(INTDIR)\JDFAutoPricing.sbr"
	-@erase "$(INTDIR)\JDFAutoPrintCondition.obj"
	-@erase "$(INTDIR)\JDFAutoPrintCondition.sbr"
	-@erase "$(INTDIR)\JDFAutoPrintConditionColor.obj"
	-@erase "$(INTDIR)\JDFAutoPrintConditionColor.sbr"
	-@erase "$(INTDIR)\JDFAutoPrintRollingParams.obj"
	-@erase "$(INTDIR)\JDFAutoPrintRollingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoPRItem.obj"
	-@erase "$(INTDIR)\JDFAutoPRItem.sbr"
	-@erase "$(INTDIR)\JDFAutoPROccurence.obj"
	-@erase "$(INTDIR)\JDFAutoPROccurence.sbr"
	-@erase "$(INTDIR)\JDFAutoProcessRun.obj"
	-@erase "$(INTDIR)\JDFAutoProcessRun.sbr"
	-@erase "$(INTDIR)\JDFAutoProductionIntent.obj"
	-@erase "$(INTDIR)\JDFAutoProductionIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoProofingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoProofingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoProofingParams.obj"
	-@erase "$(INTDIR)\JDFAutoProofingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoProofItem.obj"
	-@erase "$(INTDIR)\JDFAutoProofItem.sbr"
	-@erase "$(INTDIR)\JDFAutoProperties.obj"
	-@erase "$(INTDIR)\JDFAutoProperties.sbr"
	-@erase "$(INTDIR)\JDFAutoPRRule.obj"
	-@erase "$(INTDIR)\JDFAutoPRRule.sbr"
	-@erase "$(INTDIR)\JDFAutoPRRuleAttr.obj"
	-@erase "$(INTDIR)\JDFAutoPRRuleAttr.sbr"
	-@erase "$(INTDIR)\JDFAutoPSToPDFConversionParams.obj"
	-@erase "$(INTDIR)\JDFAutoPSToPDFConversionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQualityControlParams.obj"
	-@erase "$(INTDIR)\JDFAutoQualityControlParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQualityControlResult.obj"
	-@erase "$(INTDIR)\JDFAutoQualityControlResult.sbr"
	-@erase "$(INTDIR)\JDFAutoQualityMeasurement.obj"
	-@erase "$(INTDIR)\JDFAutoQualityMeasurement.sbr"
	-@erase "$(INTDIR)\JDFAutoQuery.obj"
	-@erase "$(INTDIR)\JDFAutoQuery.sbr"
	-@erase "$(INTDIR)\JDFAutoQueue.obj"
	-@erase "$(INTDIR)\JDFAutoQueue.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntry.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntry.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDef.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDef.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDefList.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryDefList.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPosParams.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPosParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPriParams.obj"
	-@erase "$(INTDIR)\JDFAutoQueueEntryPriParams.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueFilter.obj"
	-@erase "$(INTDIR)\JDFAutoQueueFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoQueueSubmissionParams.obj"
	-@erase "$(INTDIR)\JDFAutoQueueSubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRegisterMark.obj"
	-@erase "$(INTDIR)\JDFAutoRegisterMark.sbr"
	-@erase "$(INTDIR)\JDFAutoRegisterRibbon.obj"
	-@erase "$(INTDIR)\JDFAutoRegisterRibbon.sbr"
	-@erase "$(INTDIR)\JDFAutoRemoved.obj"
	-@erase "$(INTDIR)\JDFAutoRemoved.sbr"
	-@erase "$(INTDIR)\JDFAutoRenderingParams.obj"
	-@erase "$(INTDIR)\JDFAutoRenderingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRequestQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFAutoRequestQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceAudit.obj"
	-@erase "$(INTDIR)\JDFAutoResourceAudit.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourceCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceDefinitionParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourceDefinitionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceInfo.obj"
	-@erase "$(INTDIR)\JDFAutoResourceInfo.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceParam.obj"
	-@erase "$(INTDIR)\JDFAutoResourceParam.sbr"
	-@erase "$(INTDIR)\JDFAutoResourcePullParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourcePullParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResourceQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoResourceQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoResponse.obj"
	-@erase "$(INTDIR)\JDFAutoResponse.sbr"
	-@erase "$(INTDIR)\JDFAutoResubmissionParams.obj"
	-@erase "$(INTDIR)\JDFAutoResubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFAutoReturnQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFAutoReturnQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRingBinding.obj"
	-@erase "$(INTDIR)\JDFAutoRingBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoRingBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoRingBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoRollStand.obj"
	-@erase "$(INTDIR)\JDFAutoRollStand.sbr"
	-@erase "$(INTDIR)\JDFAutoRunList.obj"
	-@erase "$(INTDIR)\JDFAutoRunList.sbr"
	-@erase "$(INTDIR)\JDFAutoSaddleStitching.obj"
	-@erase "$(INTDIR)\JDFAutoSaddleStitching.sbr"
	-@erase "$(INTDIR)\JDFAutoSaddleStitchingParams.obj"
	-@erase "$(INTDIR)\JDFAutoSaddleStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoScanParams.obj"
	-@erase "$(INTDIR)\JDFAutoScanParams.sbr"
	-@erase "$(INTDIR)\JDFAutoScavengerArea.obj"
	-@erase "$(INTDIR)\JDFAutoScavengerArea.sbr"
	-@erase "$(INTDIR)\JDFAutoScore.obj"
	-@erase "$(INTDIR)\JDFAutoScore.sbr"
	-@erase "$(INTDIR)\JDFAutoScreeningIntent.obj"
	-@erase "$(INTDIR)\JDFAutoScreeningIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoScreeningParams.obj"
	-@erase "$(INTDIR)\JDFAutoScreeningParams.sbr"
	-@erase "$(INTDIR)\JDFAutoScreenSelector.obj"
	-@erase "$(INTDIR)\JDFAutoScreenSelector.sbr"
	-@erase "$(INTDIR)\JDFAutoSeparationControlParams.obj"
	-@erase "$(INTDIR)\JDFAutoSeparationControlParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSeparationSpec.obj"
	-@erase "$(INTDIR)\JDFAutoSeparationSpec.sbr"
	-@erase "$(INTDIR)\JDFAutoset.obj"
	-@erase "$(INTDIR)\JDFAutoset.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeCut.obj"
	-@erase "$(INTDIR)\JDFAutoShapeCut.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingIntent.obj"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingParams.obj"
	-@erase "$(INTDIR)\JDFAutoShapeCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoShapeElement.obj"
	-@erase "$(INTDIR)\JDFAutoShapeElement.sbr"
	-@erase "$(INTDIR)\JDFAutoSheet.obj"
	-@erase "$(INTDIR)\JDFAutoSheet.sbr"
	-@erase "$(INTDIR)\JDFAutoShrinkingParams.obj"
	-@erase "$(INTDIR)\JDFAutoShrinkingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoShutDownCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoShutDownCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSideSewing.obj"
	-@erase "$(INTDIR)\JDFAutoSideSewing.sbr"
	-@erase "$(INTDIR)\JDFAutoSideSewingParams.obj"
	-@erase "$(INTDIR)\JDFAutoSideSewingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSideStitching.obj"
	-@erase "$(INTDIR)\JDFAutoSideStitching.sbr"
	-@erase "$(INTDIR)\JDFAutoSignal.obj"
	-@erase "$(INTDIR)\JDFAutoSignal.sbr"
	-@erase "$(INTDIR)\JDFAutoSignature.obj"
	-@erase "$(INTDIR)\JDFAutoSignature.sbr"
	-@erase "$(INTDIR)\JDFAutoSignatureCell.obj"
	-@erase "$(INTDIR)\JDFAutoSignatureCell.sbr"
	-@erase "$(INTDIR)\JDFAutoSizeIntent.obj"
	-@erase "$(INTDIR)\JDFAutoSizeIntent.sbr"
	-@erase "$(INTDIR)\JDFAutoSoftCoverBinding.obj"
	-@erase "$(INTDIR)\JDFAutoSoftCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoSpawned.obj"
	-@erase "$(INTDIR)\JDFAutoSpawned.sbr"
	-@erase "$(INTDIR)\JDFAutoSpinePreparationParams.obj"
	-@erase "$(INTDIR)\JDFAutoSpinePreparationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSpineTapingParams.obj"
	-@erase "$(INTDIR)\JDFAutoSpineTapingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStackingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStackingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStatusPool.obj"
	-@erase "$(INTDIR)\JDFAutoStatusPool.sbr"
	-@erase "$(INTDIR)\JDFAutoStatusQuParams.obj"
	-@erase "$(INTDIR)\JDFAutoStatusQuParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStitchingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStopPersChParams.obj"
	-@erase "$(INTDIR)\JDFAutoStopPersChParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStrap.obj"
	-@erase "$(INTDIR)\JDFAutoStrap.sbr"
	-@erase "$(INTDIR)\JDFAutoStrappingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStrappingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStringListValue.obj"
	-@erase "$(INTDIR)\JDFAutoStringListValue.sbr"
	-@erase "$(INTDIR)\JDFAutoStripBinding.obj"
	-@erase "$(INTDIR)\JDFAutoStripBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoStripBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStripBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStripCellParams.obj"
	-@erase "$(INTDIR)\JDFAutoStripCellParams.sbr"
	-@erase "$(INTDIR)\JDFAutoStrippingParams.obj"
	-@erase "$(INTDIR)\JDFAutoStrippingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoSubmissionMethods.obj"
	-@erase "$(INTDIR)\JDFAutoSubmissionMethods.sbr"
	-@erase "$(INTDIR)\JDFAutoSubscription.obj"
	-@erase "$(INTDIR)\JDFAutoSubscription.sbr"
	-@erase "$(INTDIR)\JDFAutoSurface.obj"
	-@erase "$(INTDIR)\JDFAutoSurface.sbr"
	-@erase "$(INTDIR)\JDFAutoSystemTimeSet.obj"
	-@erase "$(INTDIR)\JDFAutoSystemTimeSet.sbr"
	-@erase "$(INTDIR)\JDFAutoTabs.obj"
	-@erase "$(INTDIR)\JDFAutoTabs.sbr"
	-@erase "$(INTDIR)\JDFAutoTape.obj"
	-@erase "$(INTDIR)\JDFAutoTape.sbr"
	-@erase "$(INTDIR)\JDFAutoTest.obj"
	-@erase "$(INTDIR)\JDFAutoTest.sbr"
	-@erase "$(INTDIR)\JDFAutoTestPool.obj"
	-@erase "$(INTDIR)\JDFAutoTestPool.sbr"
	-@erase "$(INTDIR)\JDFAutoTestRef.obj"
	-@erase "$(INTDIR)\JDFAutoTestRef.sbr"
	-@erase "$(INTDIR)\JDFAutoThinPDFParams.obj"
	-@erase "$(INTDIR)\JDFAutoThinPDFParams.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSealing.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSealing.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSealingParams.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSealingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSewing.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSewing.sbr"
	-@erase "$(INTDIR)\JDFAutoThreadSewingParams.obj"
	-@erase "$(INTDIR)\JDFAutoThreadSewingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoTIFFEmbeddedFile.obj"
	-@erase "$(INTDIR)\JDFAutoTIFFEmbeddedFile.sbr"
	-@erase "$(INTDIR)\JDFAutoTIFFFormatParams.obj"
	-@erase "$(INTDIR)\JDFAutoTIFFFormatParams.sbr"
	-@erase "$(INTDIR)\JDFAutoTIFFtag.obj"
	-@erase "$(INTDIR)\JDFAutoTIFFtag.sbr"
	-@erase "$(INTDIR)\JDFAutoTile.obj"
	-@erase "$(INTDIR)\JDFAutoTile.sbr"
	-@erase "$(INTDIR)\JDFAutoTool.obj"
	-@erase "$(INTDIR)\JDFAutoTool.sbr"
	-@erase "$(INTDIR)\JDFAutoTrackFilter.obj"
	-@erase "$(INTDIR)\JDFAutoTrackFilter.sbr"
	-@erase "$(INTDIR)\JDFAutoTrackResult.obj"
	-@erase "$(INTDIR)\JDFAutoTrackResult.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferCurve.obj"
	-@erase "$(INTDIR)\JDFAutoTransferCurve.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferCurvePool.obj"
	-@erase "$(INTDIR)\JDFAutoTransferCurvePool.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferCurveSet.obj"
	-@erase "$(INTDIR)\JDFAutoTransferCurveSet.sbr"
	-@erase "$(INTDIR)\JDFAutoTransferFunctionControl.obj"
	-@erase "$(INTDIR)\JDFAutoTransferFunctionControl.sbr"
	-@erase "$(INTDIR)\JDFAutoTrappingDetails.obj"
	-@erase "$(INTDIR)\JDFAutoTrappingDetails.sbr"
	-@erase "$(INTDIR)\JDFAutoTrappingOrder.obj"
	-@erase "$(INTDIR)\JDFAutoTrappingOrder.sbr"
	-@erase "$(INTDIR)\JDFAutoTrappingParams.obj"
	-@erase "$(INTDIR)\JDFAutoTrappingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoTrapRegion.obj"
	-@erase "$(INTDIR)\JDFAutoTrapRegion.sbr"
	-@erase "$(INTDIR)\JDFAutoTrigger.obj"
	-@erase "$(INTDIR)\JDFAutoTrigger.sbr"
	-@erase "$(INTDIR)\JDFAutoTrimmingParams.obj"
	-@erase "$(INTDIR)\JDFAutoTrimmingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoValue.obj"
	-@erase "$(INTDIR)\JDFAutoValue.sbr"
	-@erase "$(INTDIR)\JDFAutoValueLoc.obj"
	-@erase "$(INTDIR)\JDFAutoValueLoc.sbr"
	-@erase "$(INTDIR)\JDFAutoVerificationParams.obj"
	-@erase "$(INTDIR)\JDFAutoVerificationParams.sbr"
	-@erase "$(INTDIR)\JDFAutoWakeUpCmdParams.obj"
	-@erase "$(INTDIR)\JDFAutoWakeUpCmdParams.sbr"
	-@erase "$(INTDIR)\JDFAutowhen.obj"
	-@erase "$(INTDIR)\JDFAutowhen.sbr"
	-@erase "$(INTDIR)\JDFAutoWireCombBinding.obj"
	-@erase "$(INTDIR)\JDFAutoWireCombBinding.sbr"
	-@erase "$(INTDIR)\JDFAutoWireCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFAutoWireCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoWrappingParams.obj"
	-@erase "$(INTDIR)\JDFAutoWrappingParams.sbr"
	-@erase "$(INTDIR)\JDFAutoxor.obj"
	-@erase "$(INTDIR)\JDFAutoxor.sbr"
	-@erase "$(INTDIR)\JDFBand.obj"
	-@erase "$(INTDIR)\JDFBand.sbr"
	-@erase "$(INTDIR)\JDFBarcode.obj"
	-@erase "$(INTDIR)\JDFBarcode.sbr"
	-@erase "$(INTDIR)\JDFBasicPreflightTest.obj"
	-@erase "$(INTDIR)\JDFBasicPreflightTest.sbr"
	-@erase "$(INTDIR)\JDFBinderySignature.obj"
	-@erase "$(INTDIR)\JDFBinderySignature.sbr"
	-@erase "$(INTDIR)\JDFBindingIntent.obj"
	-@erase "$(INTDIR)\JDFBindingIntent.sbr"
	-@erase "$(INTDIR)\JDFBindingQualityParams.obj"
	-@erase "$(INTDIR)\JDFBindingQualityParams.sbr"
	-@erase "$(INTDIR)\JDFBindItem.obj"
	-@erase "$(INTDIR)\JDFBindItem.sbr"
	-@erase "$(INTDIR)\JDFBindList.obj"
	-@erase "$(INTDIR)\JDFBindList.sbr"
	-@erase "$(INTDIR)\JDFBlockPreparationParams.obj"
	-@erase "$(INTDIR)\JDFBlockPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFBookCase.obj"
	-@erase "$(INTDIR)\JDFBookCase.sbr"
	-@erase "$(INTDIR)\JDFBooleanEvaluation.obj"
	-@erase "$(INTDIR)\JDFBooleanEvaluation.sbr"
	-@erase "$(INTDIR)\JDFBooleanState.obj"
	-@erase "$(INTDIR)\JDFBooleanState.sbr"
	-@erase "$(INTDIR)\JDFBoxArgument.obj"
	-@erase "$(INTDIR)\JDFBoxArgument.sbr"
	-@erase "$(INTDIR)\JDFBoxPackingParams.obj"
	-@erase "$(INTDIR)\JDFBoxPackingParams.sbr"
	-@erase "$(INTDIR)\JDFBoxToBoxDifference.obj"
	-@erase "$(INTDIR)\JDFBoxToBoxDifference.sbr"
	-@erase "$(INTDIR)\JDFBufferParams.obj"
	-@erase "$(INTDIR)\JDFBufferParams.sbr"
	-@erase "$(INTDIR)\JDFBundle.obj"
	-@erase "$(INTDIR)\JDFBundle.sbr"
	-@erase "$(INTDIR)\JDFBundleItem.obj"
	-@erase "$(INTDIR)\JDFBundleItem.sbr"
	-@erase "$(INTDIR)\JDFBundlingParams.obj"
	-@erase "$(INTDIR)\JDFBundlingParams.sbr"
	-@erase "$(INTDIR)\JDFBusinessInfo.obj"
	-@erase "$(INTDIR)\JDFBusinessInfo.sbr"
	-@erase "$(INTDIR)\JDFByteMap.obj"
	-@erase "$(INTDIR)\JDFByteMap.sbr"
	-@erase "$(INTDIR)\JDFcall.obj"
	-@erase "$(INTDIR)\JDFcall.sbr"
	-@erase "$(INTDIR)\JDFCaseMakingParams.obj"
	-@erase "$(INTDIR)\JDFCaseMakingParams.sbr"
	-@erase "$(INTDIR)\JDFCasingInParams.obj"
	-@erase "$(INTDIR)\JDFCasingInParams.sbr"
	-@erase "$(INTDIR)\JDFCCITTFaxParams.obj"
	-@erase "$(INTDIR)\JDFCCITTFaxParams.sbr"
	-@erase "$(INTDIR)\JDFChangedAttribute.obj"
	-@erase "$(INTDIR)\JDFChangedAttribute.sbr"
	-@erase "$(INTDIR)\JDFChangedPath.obj"
	-@erase "$(INTDIR)\JDFChangedPath.sbr"
	-@erase "$(INTDIR)\JDFChannelBinding.obj"
	-@erase "$(INTDIR)\JDFChannelBinding.sbr"
	-@erase "$(INTDIR)\JDFChannelBindingParams.obj"
	-@erase "$(INTDIR)\JDFChannelBindingParams.sbr"
	-@erase "$(INTDIR)\JDFchoice.obj"
	-@erase "$(INTDIR)\JDFchoice.sbr"
	-@erase "$(INTDIR)\JDFCIELABMeasuringField.obj"
	-@erase "$(INTDIR)\JDFCIELABMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFCoilBinding.obj"
	-@erase "$(INTDIR)\JDFCoilBinding.sbr"
	-@erase "$(INTDIR)\JDFCoilBindingParams.obj"
	-@erase "$(INTDIR)\JDFCoilBindingParams.sbr"
	-@erase "$(INTDIR)\JDFCollatingItem.obj"
	-@erase "$(INTDIR)\JDFCollatingItem.sbr"
	-@erase "$(INTDIR)\JDFCollectingParams.obj"
	-@erase "$(INTDIR)\JDFCollectingParams.sbr"
	-@erase "$(INTDIR)\JDFColor.obj"
	-@erase "$(INTDIR)\JDFColor.sbr"
	-@erase "$(INTDIR)\JDFColorantAlias.obj"
	-@erase "$(INTDIR)\JDFColorantAlias.sbr"
	-@erase "$(INTDIR)\JDFColorantControl.obj"
	-@erase "$(INTDIR)\JDFColorantControl.sbr"
	-@erase "$(INTDIR)\JDFColorantZoneDetails.obj"
	-@erase "$(INTDIR)\JDFColorantZoneDetails.sbr"
	-@erase "$(INTDIR)\JDFColorControlStrip.obj"
	-@erase "$(INTDIR)\JDFColorControlStrip.sbr"
	-@erase "$(INTDIR)\JDFColorCorrectionOp.obj"
	-@erase "$(INTDIR)\JDFColorCorrectionOp.sbr"
	-@erase "$(INTDIR)\JDFColorCorrectionParams.obj"
	-@erase "$(INTDIR)\JDFColorCorrectionParams.sbr"
	-@erase "$(INTDIR)\JDFColorIntent.obj"
	-@erase "$(INTDIR)\JDFColorIntent.sbr"
	-@erase "$(INTDIR)\JDFColorMeasurementConditions.obj"
	-@erase "$(INTDIR)\JDFColorMeasurementConditions.sbr"
	-@erase "$(INTDIR)\JDFColorPool.obj"
	-@erase "$(INTDIR)\JDFColorPool.sbr"
	-@erase "$(INTDIR)\JDFColorSpaceConversionOp.obj"
	-@erase "$(INTDIR)\JDFColorSpaceConversionOp.sbr"
	-@erase "$(INTDIR)\JDFColorSpaceConversionParams.obj"
	-@erase "$(INTDIR)\JDFColorSpaceConversionParams.sbr"
	-@erase "$(INTDIR)\JDFColorSpaceSubstitute.obj"
	-@erase "$(INTDIR)\JDFColorSpaceSubstitute.sbr"
	-@erase "$(INTDIR)\JDFColorsUsed.obj"
	-@erase "$(INTDIR)\JDFColorsUsed.sbr"
	-@erase "$(INTDIR)\JDFComChannel.obj"
	-@erase "$(INTDIR)\JDFComChannel.sbr"
	-@erase "$(INTDIR)\JDFCommand.obj"
	-@erase "$(INTDIR)\JDFCommand.sbr"
	-@erase "$(INTDIR)\JDFComment.obj"
	-@erase "$(INTDIR)\JDFComment.sbr"
	-@erase "$(INTDIR)\JDFCompany.obj"
	-@erase "$(INTDIR)\JDFCompany.sbr"
	-@erase "$(INTDIR)\JDFComponent.obj"
	-@erase "$(INTDIR)\JDFComponent.sbr"
	-@erase "$(INTDIR)\JDFContact.obj"
	-@erase "$(INTDIR)\JDFContact.sbr"
	-@erase "$(INTDIR)\JDFContactCopyParams.obj"
	-@erase "$(INTDIR)\JDFContactCopyParams.sbr"
	-@erase "$(INTDIR)\JDFContainer.obj"
	-@erase "$(INTDIR)\JDFContainer.sbr"
	-@erase "$(INTDIR)\JDFContentObject.obj"
	-@erase "$(INTDIR)\JDFContentObject.sbr"
	-@erase "$(INTDIR)\JDFConventionalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFConventionalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFCostCenter.obj"
	-@erase "$(INTDIR)\JDFCostCenter.sbr"
	-@erase "$(INTDIR)\JDFCounterReset.obj"
	-@erase "$(INTDIR)\JDFCounterReset.sbr"
	-@erase "$(INTDIR)\JDFCoverApplicationParams.obj"
	-@erase "$(INTDIR)\JDFCoverApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFCrease.obj"
	-@erase "$(INTDIR)\JDFCrease.sbr"
	-@erase "$(INTDIR)\JDFCreasingParams.obj"
	-@erase "$(INTDIR)\JDFCreasingParams.sbr"
	-@erase "$(INTDIR)\JDFCreated.obj"
	-@erase "$(INTDIR)\JDFCreated.sbr"
	-@erase "$(INTDIR)\JDFCreditCard.obj"
	-@erase "$(INTDIR)\JDFCreditCard.sbr"
	-@erase "$(INTDIR)\JDFCustomerInfo.obj"
	-@erase "$(INTDIR)\JDFCustomerInfo.sbr"
	-@erase "$(INTDIR)\JDFCustomerMessage.obj"
	-@erase "$(INTDIR)\JDFCustomerMessage.sbr"
	-@erase "$(INTDIR)\JDFCut.obj"
	-@erase "$(INTDIR)\JDFCut.sbr"
	-@erase "$(INTDIR)\JDFCutBlock.obj"
	-@erase "$(INTDIR)\JDFCutBlock.sbr"
	-@erase "$(INTDIR)\JDFCutMark.obj"
	-@erase "$(INTDIR)\JDFCutMark.sbr"
	-@erase "$(INTDIR)\JDFCuttingParams.obj"
	-@erase "$(INTDIR)\JDFCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFDateTimeEvaluation.obj"
	-@erase "$(INTDIR)\JDFDateTimeEvaluation.sbr"
	-@erase "$(INTDIR)\JDFDateTimeRange.obj"
	-@erase "$(INTDIR)\JDFDateTimeRange.sbr"
	-@erase "$(INTDIR)\JDFDateTimeRangeList.obj"
	-@erase "$(INTDIR)\JDFDateTimeRangeList.sbr"
	-@erase "$(INTDIR)\JDFDateTimeState.obj"
	-@erase "$(INTDIR)\JDFDateTimeState.sbr"
	-@erase "$(INTDIR)\JDFDBMergeParams.obj"
	-@erase "$(INTDIR)\JDFDBMergeParams.sbr"
	-@erase "$(INTDIR)\JDFDBRules.obj"
	-@erase "$(INTDIR)\JDFDBRules.sbr"
	-@erase "$(INTDIR)\JDFDBSchema.obj"
	-@erase "$(INTDIR)\JDFDBSchema.sbr"
	-@erase "$(INTDIR)\JDFDBSelection.obj"
	-@erase "$(INTDIR)\JDFDBSelection.sbr"
	-@erase "$(INTDIR)\JDFDCTParams.obj"
	-@erase "$(INTDIR)\JDFDCTParams.sbr"
	-@erase "$(INTDIR)\JDFDeleted.obj"
	-@erase "$(INTDIR)\JDFDeleted.sbr"
	-@erase "$(INTDIR)\JDFDeliveryIntent.obj"
	-@erase "$(INTDIR)\JDFDeliveryIntent.sbr"
	-@erase "$(INTDIR)\JDFDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFDensityMeasuringField.obj"
	-@erase "$(INTDIR)\JDFDensityMeasuringField.sbr"
	-@erase "$(INTDIR)\JDFDependencies.obj"
	-@erase "$(INTDIR)\JDFDependencies.sbr"
	-@erase "$(INTDIR)\JDFDevCap.obj"
	-@erase "$(INTDIR)\JDFDevCap.sbr"
	-@erase "$(INTDIR)\JDFDevCaps.obj"
	-@erase "$(INTDIR)\JDFDevCaps.sbr"
	-@erase "$(INTDIR)\JDFDevelopingParams.obj"
	-@erase "$(INTDIR)\JDFDevelopingParams.sbr"
	-@erase "$(INTDIR)\JDFDevice.obj"
	-@erase "$(INTDIR)\JDFDevice.sbr"
	-@erase "$(INTDIR)\JDFDeviceCap.obj"
	-@erase "$(INTDIR)\JDFDeviceCap.sbr"
	-@erase "$(INTDIR)\JDFDeviceFilter.obj"
	-@erase "$(INTDIR)\JDFDeviceFilter.sbr"
	-@erase "$(INTDIR)\JDFDeviceInfo.obj"
	-@erase "$(INTDIR)\JDFDeviceInfo.sbr"
	-@erase "$(INTDIR)\JDFDeviceList.obj"
	-@erase "$(INTDIR)\JDFDeviceList.sbr"
	-@erase "$(INTDIR)\JDFDeviceMark.obj"
	-@erase "$(INTDIR)\JDFDeviceMark.sbr"
	-@erase "$(INTDIR)\JDFDeviceNColor.obj"
	-@erase "$(INTDIR)\JDFDeviceNColor.sbr"
	-@erase "$(INTDIR)\JDFDeviceNSpace.obj"
	-@erase "$(INTDIR)\JDFDeviceNSpace.sbr"
	-@erase "$(INTDIR)\JDFDigitalDeliveryParams.obj"
	-@erase "$(INTDIR)\JDFDigitalDeliveryParams.sbr"
	-@erase "$(INTDIR)\JDFDigitalMedia.obj"
	-@erase "$(INTDIR)\JDFDigitalMedia.sbr"
	-@erase "$(INTDIR)\JDFDigitalPrintingParams.obj"
	-@erase "$(INTDIR)\JDFDigitalPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFDisjointing.obj"
	-@erase "$(INTDIR)\JDFDisjointing.sbr"
	-@erase "$(INTDIR)\JDFDisplayGroup.obj"
	-@erase "$(INTDIR)\JDFDisplayGroup.sbr"
	-@erase "$(INTDIR)\JDFDisplayGroupPool.obj"
	-@erase "$(INTDIR)\JDFDisplayGroupPool.sbr"
	-@erase "$(INTDIR)\JDFDisposition.obj"
	-@erase "$(INTDIR)\JDFDisposition.sbr"
	-@erase "$(INTDIR)\JDFDividingParams.obj"
	-@erase "$(INTDIR)\JDFDividingParams.sbr"
	-@erase "$(INTDIR)\JDFDoc.obj"
	-@erase "$(INTDIR)\JDFDoc.sbr"
	-@erase "$(INTDIR)\JDFDrop.obj"
	-@erase "$(INTDIR)\JDFDrop.sbr"
	-@erase "$(INTDIR)\JDFDropIntent.obj"
	-@erase "$(INTDIR)\JDFDropIntent.sbr"
	-@erase "$(INTDIR)\JDFDropItem.obj"
	-@erase "$(INTDIR)\JDFDropItem.sbr"
	-@erase "$(INTDIR)\JDFDropItemIntent.obj"
	-@erase "$(INTDIR)\JDFDropItemIntent.sbr"
	-@erase "$(INTDIR)\JDFDurationEvaluation.obj"
	-@erase "$(INTDIR)\JDFDurationEvaluation.sbr"
	-@erase "$(INTDIR)\JDFDurationRange.obj"
	-@erase "$(INTDIR)\JDFDurationRange.sbr"
	-@erase "$(INTDIR)\JDFDurationRangeList.obj"
	-@erase "$(INTDIR)\JDFDurationRangeList.sbr"
	-@erase "$(INTDIR)\JDFDurationState.obj"
	-@erase "$(INTDIR)\JDFDurationState.sbr"
	-@erase "$(INTDIR)\JDFDynamicField.obj"
	-@erase "$(INTDIR)\JDFDynamicField.sbr"
	-@erase "$(INTDIR)\JDFDynamicInput.obj"
	-@erase "$(INTDIR)\JDFDynamicInput.sbr"
	-@erase "$(INTDIR)\JDFEdgeGluing.obj"
	-@erase "$(INTDIR)\JDFEdgeGluing.sbr"
	-@erase "$(INTDIR)\JDFElement.obj"
	-@erase "$(INTDIR)\JDFElement.sbr"
	-@erase "$(INTDIR)\JDFElementColorParams.obj"
	-@erase "$(INTDIR)\JDFElementColorParams.sbr"
	-@erase "$(INTDIR)\JDFEmboss.obj"
	-@erase "$(INTDIR)\JDFEmboss.sbr"
	-@erase "$(INTDIR)\JDFEmbossingIntent.obj"
	-@erase "$(INTDIR)\JDFEmbossingIntent.sbr"
	-@erase "$(INTDIR)\JDFEmbossingItem.obj"
	-@erase "$(INTDIR)\JDFEmbossingItem.sbr"
	-@erase "$(INTDIR)\JDFEmbossingParams.obj"
	-@erase "$(INTDIR)\JDFEmbossingParams.sbr"
	-@erase "$(INTDIR)\JDFEmployee.obj"
	-@erase "$(INTDIR)\JDFEmployee.sbr"
	-@erase "$(INTDIR)\JDFEmployeeDef.obj"
	-@erase "$(INTDIR)\JDFEmployeeDef.sbr"
	-@erase "$(INTDIR)\JDFEndSheet.obj"
	-@erase "$(INTDIR)\JDFEndSheet.sbr"
	-@erase "$(INTDIR)\JDFEndSheetGluingParams.obj"
	-@erase "$(INTDIR)\JDFEndSheetGluingParams.sbr"
	-@erase "$(INTDIR)\JDFEnumerationEvaluation.obj"
	-@erase "$(INTDIR)\JDFEnumerationEvaluation.sbr"
	-@erase "$(INTDIR)\JDFEnumerationState.obj"
	-@erase "$(INTDIR)\JDFEnumerationState.sbr"
	-@erase "$(INTDIR)\JDFError.obj"
	-@erase "$(INTDIR)\JDFError.sbr"
	-@erase "$(INTDIR)\JDFEvaluation.obj"
	-@erase "$(INTDIR)\JDFEvaluation.sbr"
	-@erase "$(INTDIR)\JDFEvent.obj"
	-@erase "$(INTDIR)\JDFEvent.sbr"
	-@erase "$(INTDIR)\JDFExposedMedia.obj"
	-@erase "$(INTDIR)\JDFExposedMedia.sbr"
	-@erase "$(INTDIR)\JDFFactory.obj"
	-@erase "$(INTDIR)\JDFFactory.sbr"
	-@erase "$(INTDIR)\JDFFCNKey.obj"
	-@erase "$(INTDIR)\JDFFCNKey.sbr"
	-@erase "$(INTDIR)\JDFFeatureAttribute.obj"
	-@erase "$(INTDIR)\JDFFeatureAttribute.sbr"
	-@erase "$(INTDIR)\JDFFeaturePool.obj"
	-@erase "$(INTDIR)\JDFFeaturePool.sbr"
	-@erase "$(INTDIR)\JDFFeeder.obj"
	-@erase "$(INTDIR)\JDFFeeder.sbr"
	-@erase "$(INTDIR)\JDFFeederQualityParams.obj"
	-@erase "$(INTDIR)\JDFFeederQualityParams.sbr"
	-@erase "$(INTDIR)\JDFFeedingParams.obj"
	-@erase "$(INTDIR)\JDFFeedingParams.sbr"
	-@erase "$(INTDIR)\JDFFileAlias.obj"
	-@erase "$(INTDIR)\JDFFileAlias.sbr"
	-@erase "$(INTDIR)\JDFFileSpec.obj"
	-@erase "$(INTDIR)\JDFFileSpec.sbr"
	-@erase "$(INTDIR)\JDFFitPolicy.obj"
	-@erase "$(INTDIR)\JDFFitPolicy.sbr"
	-@erase "$(INTDIR)\JDFFlateParams.obj"
	-@erase "$(INTDIR)\JDFFlateParams.sbr"
	-@erase "$(INTDIR)\JDFFlushedResources.obj"
	-@erase "$(INTDIR)\JDFFlushedResources.sbr"
	-@erase "$(INTDIR)\JDFFlushQueueParams.obj"
	-@erase "$(INTDIR)\JDFFlushQueueParams.sbr"
	-@erase "$(INTDIR)\JDFFlushResourceParams.obj"
	-@erase "$(INTDIR)\JDFFlushResourceParams.sbr"
	-@erase "$(INTDIR)\JDFFold.obj"
	-@erase "$(INTDIR)\JDFFold.sbr"
	-@erase "$(INTDIR)\JDFFoldingIntent.obj"
	-@erase "$(INTDIR)\JDFFoldingIntent.sbr"
	-@erase "$(INTDIR)\JDFFoldingParams.obj"
	-@erase "$(INTDIR)\JDFFoldingParams.sbr"
	-@erase "$(INTDIR)\JDFFontParams.obj"
	-@erase "$(INTDIR)\JDFFontParams.sbr"
	-@erase "$(INTDIR)\JDFFontPolicy.obj"
	-@erase "$(INTDIR)\JDFFontPolicy.sbr"
	-@erase "$(INTDIR)\JDFFormatConversionParams.obj"
	-@erase "$(INTDIR)\JDFFormatConversionParams.sbr"
	-@erase "$(INTDIR)\JDFGatheringParams.obj"
	-@erase "$(INTDIR)\JDFGatheringParams.sbr"
	-@erase "$(INTDIR)\JDFGlue.obj"
	-@erase "$(INTDIR)\JDFGlue.sbr"
	-@erase "$(INTDIR)\JDFGlueApplication.obj"
	-@erase "$(INTDIR)\JDFGlueApplication.sbr"
	-@erase "$(INTDIR)\JDFGlueLine.obj"
	-@erase "$(INTDIR)\JDFGlueLine.sbr"
	-@erase "$(INTDIR)\JDFGluingParams.obj"
	-@erase "$(INTDIR)\JDFGluingParams.sbr"
	-@erase "$(INTDIR)\JDFHardCoverBinding.obj"
	-@erase "$(INTDIR)\JDFHardCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFHeadBandApplicationParams.obj"
	-@erase "$(INTDIR)\JDFHeadBandApplicationParams.sbr"
	-@erase "$(INTDIR)\JDFHole.obj"
	-@erase "$(INTDIR)\JDFHole.sbr"
	-@erase "$(INTDIR)\JDFHoleLine.obj"
	-@erase "$(INTDIR)\JDFHoleLine.sbr"
	-@erase "$(INTDIR)\JDFHoleList.obj"
	-@erase "$(INTDIR)\JDFHoleList.sbr"
	-@erase "$(INTDIR)\JDFHoleMakingIntent.obj"
	-@erase "$(INTDIR)\JDFHoleMakingIntent.sbr"
	-@erase "$(INTDIR)\JDFHoleMakingParams.obj"
	-@erase "$(INTDIR)\JDFHoleMakingParams.sbr"
	-@erase "$(INTDIR)\JDFIcon.obj"
	-@erase "$(INTDIR)\JDFIcon.sbr"
	-@erase "$(INTDIR)\JDFIconList.obj"
	-@erase "$(INTDIR)\JDFIconList.sbr"
	-@erase "$(INTDIR)\JDFIdentificationField.obj"
	-@erase "$(INTDIR)\JDFIdentificationField.sbr"
	-@erase "$(INTDIR)\JDFIDInfo.obj"
	-@erase "$(INTDIR)\JDFIDInfo.sbr"
	-@erase "$(INTDIR)\JDFIDPCover.obj"
	-@erase "$(INTDIR)\JDFIDPCover.sbr"
	-@erase "$(INTDIR)\JDFIDPFinishing.obj"
	-@erase "$(INTDIR)\JDFIDPFinishing.sbr"
	-@erase "$(INTDIR)\JDFIDPFolding.obj"
	-@erase "$(INTDIR)\JDFIDPFolding.sbr"
	-@erase "$(INTDIR)\JDFIDPHoleMaking.obj"
	-@erase "$(INTDIR)\JDFIDPHoleMaking.sbr"
	-@erase "$(INTDIR)\JDFIDPImageShift.obj"
	-@erase "$(INTDIR)\JDFIDPImageShift.sbr"
	-@erase "$(INTDIR)\JDFIDPJobSheet.obj"
	-@erase "$(INTDIR)\JDFIDPJobSheet.sbr"
	-@erase "$(INTDIR)\JDFIDPLayout.obj"
	-@erase "$(INTDIR)\JDFIDPLayout.sbr"
	-@erase "$(INTDIR)\JDFIDPrintingParams.obj"
	-@erase "$(INTDIR)\JDFIDPrintingParams.sbr"
	-@erase "$(INTDIR)\JDFIDPStitching.obj"
	-@erase "$(INTDIR)\JDFIDPStitching.sbr"
	-@erase "$(INTDIR)\JDFIDPTrimming.obj"
	-@erase "$(INTDIR)\JDFIDPTrimming.sbr"
	-@erase "$(INTDIR)\JDFImageCompression.obj"
	-@erase "$(INTDIR)\JDFImageCompression.sbr"
	-@erase "$(INTDIR)\JDFImageCompressionParams.obj"
	-@erase "$(INTDIR)\JDFImageCompressionParams.sbr"
	-@erase "$(INTDIR)\JDFImageReplacementParams.obj"
	-@erase "$(INTDIR)\JDFImageReplacementParams.sbr"
	-@erase "$(INTDIR)\JDFImageSetterParams.obj"
	-@erase "$(INTDIR)\JDFImageSetterParams.sbr"
	-@erase "$(INTDIR)\JDFImageShift.obj"
	-@erase "$(INTDIR)\JDFImageShift.sbr"
	-@erase "$(INTDIR)\JDFInk.obj"
	-@erase "$(INTDIR)\JDFInk.sbr"
	-@erase "$(INTDIR)\JDFInkZoneCalculationParams.obj"
	-@erase "$(INTDIR)\JDFInkZoneCalculationParams.sbr"
	-@erase "$(INTDIR)\JDFInkZoneProfile.obj"
	-@erase "$(INTDIR)\JDFInkZoneProfile.sbr"
	-@erase "$(INTDIR)\JDFInsert.obj"
	-@erase "$(INTDIR)\JDFInsert.sbr"
	-@erase "$(INTDIR)\JDFInsertingIntent.obj"
	-@erase "$(INTDIR)\JDFInsertingIntent.sbr"
	-@erase "$(INTDIR)\JDFInsertingParams.obj"
	-@erase "$(INTDIR)\JDFInsertingParams.sbr"
	-@erase "$(INTDIR)\JDFInsertList.obj"
	-@erase "$(INTDIR)\JDFInsertList.sbr"
	-@erase "$(INTDIR)\JDFInsertSheet.obj"
	-@erase "$(INTDIR)\JDFInsertSheet.sbr"
	-@erase "$(INTDIR)\JDFIntegerEvaluation.obj"
	-@erase "$(INTDIR)\JDFIntegerEvaluation.sbr"
	-@erase "$(INTDIR)\JDFIntegerRange.obj"
	-@erase "$(INTDIR)\JDFIntegerRange.sbr"
	-@erase "$(INTDIR)\JDFIntegerRangeList.obj"
	-@erase "$(INTDIR)\JDFIntegerRangeList.sbr"
	-@erase "$(INTDIR)\JDFIntegerState.obj"
	-@erase "$(INTDIR)\JDFIntegerState.sbr"
	-@erase "$(INTDIR)\JDFIntentResource.obj"
	-@erase "$(INTDIR)\JDFIntentResource.sbr"
	-@erase "$(INTDIR)\JDFInterpretedPDLData.obj"
	-@erase "$(INTDIR)\JDFInterpretedPDLData.sbr"
	-@erase "$(INTDIR)\JDFInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFIsPresentEvaluation.obj"
	-@erase "$(INTDIR)\JDFIsPresentEvaluation.sbr"
	-@erase "$(INTDIR)\JDFJacketingParams.obj"
	-@erase "$(INTDIR)\JDFJacketingParams.sbr"
	-@erase "$(INTDIR)\JDFJDFController.obj"
	-@erase "$(INTDIR)\JDFJDFController.sbr"
	-@erase "$(INTDIR)\JDFJDFService.obj"
	-@erase "$(INTDIR)\JDFJDFService.sbr"
	-@erase "$(INTDIR)\JDFJMF.obj"
	-@erase "$(INTDIR)\JDFJMF.sbr"
	-@erase "$(INTDIR)\JDFJobField.obj"
	-@erase "$(INTDIR)\JDFJobField.sbr"
	-@erase "$(INTDIR)\JDFJobPhase.obj"
	-@erase "$(INTDIR)\JDFJobPhase.sbr"
	-@erase "$(INTDIR)\JDFKnownMsgQuParams.obj"
	-@erase "$(INTDIR)\JDFKnownMsgQuParams.sbr"
	-@erase "$(INTDIR)\JDFLabelingParams.obj"
	-@erase "$(INTDIR)\JDFLabelingParams.sbr"
	-@erase "$(INTDIR)\JDFLaminatingIntent.obj"
	-@erase "$(INTDIR)\JDFLaminatingIntent.sbr"
	-@erase "$(INTDIR)\JDFLaminatingParams.obj"
	-@erase "$(INTDIR)\JDFLaminatingParams.sbr"
	-@erase "$(INTDIR)\JDFLayerDetails.obj"
	-@erase "$(INTDIR)\JDFLayerDetails.sbr"
	-@erase "$(INTDIR)\JDFLayerList.obj"
	-@erase "$(INTDIR)\JDFLayerList.sbr"
	-@erase "$(INTDIR)\JDFLayout.obj"
	-@erase "$(INTDIR)\JDFLayout.sbr"
	-@erase "$(INTDIR)\JDFLayoutElement.obj"
	-@erase "$(INTDIR)\JDFLayoutElement.sbr"
	-@erase "$(INTDIR)\JDFLayoutIntent.obj"
	-@erase "$(INTDIR)\JDFLayoutIntent.sbr"
	-@erase "$(INTDIR)\JDFLayoutPreparationParams.obj"
	-@erase "$(INTDIR)\JDFLayoutPreparationParams.sbr"
	-@erase "$(INTDIR)\JDFLoc.obj"
	-@erase "$(INTDIR)\JDFLoc.sbr"
	-@erase "$(INTDIR)\JDFLocation.obj"
	-@erase "$(INTDIR)\JDFLocation.sbr"
	-@erase "$(INTDIR)\JDFLongFold.obj"
	-@erase "$(INTDIR)\JDFLongFold.sbr"
	-@erase "$(INTDIR)\JDFLongGlue.obj"
	-@erase "$(INTDIR)\JDFLongGlue.sbr"
	-@erase "$(INTDIR)\JDFLongitudinalRibbonOperationParams.obj"
	-@erase "$(INTDIR)\JDFLongitudinalRibbonOperationParams.sbr"
	-@erase "$(INTDIR)\JDFLongPerforate.obj"
	-@erase "$(INTDIR)\JDFLongPerforate.sbr"
	-@erase "$(INTDIR)\JDFLongSlit.obj"
	-@erase "$(INTDIR)\JDFLongSlit.sbr"
	-@erase "$(INTDIR)\JDFLZWParams.obj"
	-@erase "$(INTDIR)\JDFLZWParams.sbr"
	-@erase "$(INTDIR)\JDFmacro.obj"
	-@erase "$(INTDIR)\JDFmacro.sbr"
	-@erase "$(INTDIR)\JDFMacroPool.obj"
	-@erase "$(INTDIR)\JDFMacroPool.sbr"
	-@erase "$(INTDIR)\JDFManualLaborParams.obj"
	-@erase "$(INTDIR)\JDFManualLaborParams.sbr"
	-@erase "$(INTDIR)\JDFMarkObject.obj"
	-@erase "$(INTDIR)\JDFMarkObject.sbr"
	-@erase "$(INTDIR)\JDFMatrixEvaluation.obj"
	-@erase "$(INTDIR)\JDFMatrixEvaluation.sbr"
	-@erase "$(INTDIR)\JDFMatrixState.obj"
	-@erase "$(INTDIR)\JDFMatrixState.sbr"
	-@erase "$(INTDIR)\JDFMedia.obj"
	-@erase "$(INTDIR)\JDFMedia.sbr"
	-@erase "$(INTDIR)\JDFMediaIntent.obj"
	-@erase "$(INTDIR)\JDFMediaIntent.sbr"
	-@erase "$(INTDIR)\JDFMediaSource.obj"
	-@erase "$(INTDIR)\JDFMediaSource.sbr"
	-@erase "$(INTDIR)\JDFMerged.obj"
	-@erase "$(INTDIR)\JDFMerged.sbr"
	-@erase "$(INTDIR)\JDFMessage.obj"
	-@erase "$(INTDIR)\JDFMessage.sbr"
	-@erase "$(INTDIR)\JDFMessageElement.obj"
	-@erase "$(INTDIR)\JDFMessageElement.sbr"
	-@erase "$(INTDIR)\JDFMessageService.obj"
	-@erase "$(INTDIR)\JDFMessageService.sbr"
	-@erase "$(INTDIR)\JDFMISDetails.obj"
	-@erase "$(INTDIR)\JDFMISDetails.sbr"
	-@erase "$(INTDIR)\JDFModified.obj"
	-@erase "$(INTDIR)\JDFModified.sbr"
	-@erase "$(INTDIR)\JDFModulePhase.obj"
	-@erase "$(INTDIR)\JDFModulePhase.sbr"
	-@erase "$(INTDIR)\JDFModuleStatus.obj"
	-@erase "$(INTDIR)\JDFModuleStatus.sbr"
	-@erase "$(INTDIR)\JDFMsgFilter.obj"
	-@erase "$(INTDIR)\JDFMsgFilter.sbr"
	-@erase "$(INTDIR)\JDFNameEvaluation.obj"
	-@erase "$(INTDIR)\JDFNameEvaluation.sbr"
	-@erase "$(INTDIR)\JDFNameRangeList.obj"
	-@erase "$(INTDIR)\JDFNameRangeList.sbr"
	-@erase "$(INTDIR)\JDFNameState.obj"
	-@erase "$(INTDIR)\JDFNameState.sbr"
	-@erase "$(INTDIR)\JDFNewJDFCmdParams.obj"
	-@erase "$(INTDIR)\JDFNewJDFCmdParams.sbr"
	-@erase "$(INTDIR)\JDFNewJDFQuParams.obj"
	-@erase "$(INTDIR)\JDFNewJDFQuParams.sbr"
	-@erase "$(INTDIR)\JDFNode.obj"
	-@erase "$(INTDIR)\JDFNode.sbr"
	-@erase "$(INTDIR)\JDFNodeFactory.obj"
	-@erase "$(INTDIR)\JDFNodeFactory.sbr"
	-@erase "$(INTDIR)\JDFNodeInfo.obj"
	-@erase "$(INTDIR)\JDFNodeInfo.sbr"
	-@erase "$(INTDIR)\JDFNodeInfoCmdParams.obj"
	-@erase "$(INTDIR)\JDFNodeInfoCmdParams.sbr"
	-@erase "$(INTDIR)\JDFNodeInfoQuParams.obj"
	-@erase "$(INTDIR)\JDFNodeInfoQuParams.sbr"
	-@erase "$(INTDIR)\JDFNodeInfoResp.obj"
	-@erase "$(INTDIR)\JDFNodeInfoResp.sbr"
	-@erase "$(INTDIR)\JDFnot.obj"
	-@erase "$(INTDIR)\JDFnot.sbr"
	-@erase "$(INTDIR)\JDFNotification.obj"
	-@erase "$(INTDIR)\JDFNotification.sbr"
	-@erase "$(INTDIR)\JDFNotificationDef.obj"
	-@erase "$(INTDIR)\JDFNotificationDef.sbr"
	-@erase "$(INTDIR)\JDFNotificationFilter.obj"
	-@erase "$(INTDIR)\JDFNotificationFilter.sbr"
	-@erase "$(INTDIR)\JDFNumberEvaluation.obj"
	-@erase "$(INTDIR)\JDFNumberEvaluation.sbr"
	-@erase "$(INTDIR)\JDFNumberingIntent.obj"
	-@erase "$(INTDIR)\JDFNumberingIntent.sbr"
	-@erase "$(INTDIR)\JDFNumberingParam.obj"
	-@erase "$(INTDIR)\JDFNumberingParam.sbr"
	-@erase "$(INTDIR)\JDFNumberingParams.obj"
	-@erase "$(INTDIR)\JDFNumberingParams.sbr"
	-@erase "$(INTDIR)\JDFNumberItem.obj"
	-@erase "$(INTDIR)\JDFNumberItem.sbr"
	-@erase "$(INTDIR)\JDFNumberRangeList.obj"
	-@erase "$(INTDIR)\JDFNumberRangeList.sbr"
	-@erase "$(INTDIR)\JDFNumberState.obj"
	-@erase "$(INTDIR)\JDFNumberState.sbr"
	-@erase "$(INTDIR)\JDFNumTypeList.obj"
	-@erase "$(INTDIR)\JDFNumTypeList.sbr"
	-@erase "$(INTDIR)\JDFObjectResolution.obj"
	-@erase "$(INTDIR)\JDFObjectResolution.sbr"
	-@erase "$(INTDIR)\JDFObservationTarget.obj"
	-@erase "$(INTDIR)\JDFObservationTarget.sbr"
	-@erase "$(INTDIR)\JDFOccupation.obj"
	-@erase "$(INTDIR)\JDFOccupation.sbr"
	-@erase "$(INTDIR)\JDFor.obj"
	-@erase "$(INTDIR)\JDFor.sbr"
	-@erase "$(INTDIR)\JDFOrderingParams.obj"
	-@erase "$(INTDIR)\JDFOrderingParams.sbr"
	-@erase "$(INTDIR)\JDFotherwise.obj"
	-@erase "$(INTDIR)\JDFotherwise.sbr"
	-@erase "$(INTDIR)\JDFPackingIntent.obj"
	-@erase "$(INTDIR)\JDFPackingIntent.sbr"
	-@erase "$(INTDIR)\JDFPackingParams.obj"
	-@erase "$(INTDIR)\JDFPackingParams.sbr"
	-@erase "$(INTDIR)\JDFPageCell.obj"
	-@erase "$(INTDIR)\JDFPageCell.sbr"
	-@erase "$(INTDIR)\JDFPageData.obj"
	-@erase "$(INTDIR)\JDFPageData.sbr"
	-@erase "$(INTDIR)\JDFPageList.obj"
	-@erase "$(INTDIR)\JDFPageList.sbr"
	-@erase "$(INTDIR)\JDFPallet.obj"
	-@erase "$(INTDIR)\JDFPallet.sbr"
	-@erase "$(INTDIR)\JDFPalletizingParams.obj"
	-@erase "$(INTDIR)\JDFPalletizingParams.sbr"
	-@erase "$(INTDIR)\JDFParamsFactory.obj"
	-@erase "$(INTDIR)\JDFParamsFactory.sbr"
	-@erase "$(INTDIR)\JDFParser.obj"
	-@erase "$(INTDIR)\JDFParser.sbr"
	-@erase "$(INTDIR)\JDFPart.obj"
	-@erase "$(INTDIR)\JDFPart.sbr"
	-@erase "$(INTDIR)\JDFPartAmount.obj"
	-@erase "$(INTDIR)\JDFPartAmount.sbr"
	-@erase "$(INTDIR)\JDFPartStatus.obj"
	-@erase "$(INTDIR)\JDFPartStatus.sbr"
	-@erase "$(INTDIR)\JDFPayment.obj"
	-@erase "$(INTDIR)\JDFPayment.sbr"
	-@erase "$(INTDIR)\JDFPDFInterpretingParams.obj"
	-@erase "$(INTDIR)\JDFPDFInterpretingParams.sbr"
	-@erase "$(INTDIR)\JDFPDFPathEvaluation.obj"
	-@erase "$(INTDIR)\JDFPDFPathEvaluation.sbr"
	-@erase "$(INTDIR)\JDFPDFPathState.obj"
	-@erase "$(INTDIR)\JDFPDFPathState.sbr"
	-@erase "$(INTDIR)\JDFPDFToPSConversionParams.obj"
	-@erase "$(INTDIR)\JDFPDFToPSConversionParams.sbr"
	-@erase "$(INTDIR)\JDFPDFXParams.obj"
	-@erase "$(INTDIR)\JDFPDFXParams.sbr"
	-@erase "$(INTDIR)\JDFPDLResourceAlias.obj"
	-@erase "$(INTDIR)\JDFPDLResourceAlias.sbr"
	-@erase "$(INTDIR)\JDFPerforate.obj"
	-@erase "$(INTDIR)\JDFPerforate.sbr"
	-@erase "$(INTDIR)\JDFPerforatingParams.obj"
	-@erase "$(INTDIR)\JDFPerforatingParams.sbr"
	-@erase "$(INTDIR)\JDFPerformance.obj"
	-@erase "$(INTDIR)\JDFPerformance.sbr"
	-@erase "$(INTDIR)\JDFPerson.obj"
	-@erase "$(INTDIR)\JDFPerson.sbr"
	-@erase "$(INTDIR)\JDFPhaseTime.obj"
	-@erase "$(INTDIR)\JDFPhaseTime.sbr"
	-@erase "$(INTDIR)\JDFPipeParams.obj"
	-@erase "$(INTDIR)\JDFPipeParams.sbr"
	-@erase "$(INTDIR)\JDFPixelColorant.obj"
	-@erase "$(INTDIR)\JDFPixelColorant.sbr"
	-@erase "$(INTDIR)\JDFPlaceHolderResource.obj"
	-@erase "$(INTDIR)\JDFPlaceHolderResource.sbr"
	-@erase "$(INTDIR)\JDFPlasticCombBinding.obj"
	-@erase "$(INTDIR)\JDFPlasticCombBinding.sbr"
	-@erase "$(INTDIR)\JDFPlasticCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFPlasticCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFPlateCopyParams.obj"
	-@erase "$(INTDIR)\JDFPlateCopyParams.sbr"
	-@erase "$(INTDIR)\JDFPool.obj"
	-@erase "$(INTDIR)\JDFPool.sbr"
	-@erase "$(INTDIR)\JDFPosition.obj"
	-@erase "$(INTDIR)\JDFPosition.sbr"
	-@erase "$(INTDIR)\JDFPreflightAction.obj"
	-@erase "$(INTDIR)\JDFPreflightAction.sbr"
	-@erase "$(INTDIR)\JDFPreflightAnalysis.obj"
	-@erase "$(INTDIR)\JDFPreflightAnalysis.sbr"
	-@erase "$(INTDIR)\JDFPreflightArgument.obj"
	-@erase "$(INTDIR)\JDFPreflightArgument.sbr"
	-@erase "$(INTDIR)\JDFPreflightConstraint.obj"
	-@erase "$(INTDIR)\JDFPreflightConstraint.sbr"
	-@erase "$(INTDIR)\JDFPreflightConstraintsPool.obj"
	-@erase "$(INTDIR)\JDFPreflightConstraintsPool.sbr"
	-@erase "$(INTDIR)\JDFPreflightDetail.obj"
	-@erase "$(INTDIR)\JDFPreflightDetail.sbr"
	-@erase "$(INTDIR)\JDFPreflightInstance.obj"
	-@erase "$(INTDIR)\JDFPreflightInstance.sbr"
	-@erase "$(INTDIR)\JDFPreflightInstanceDetail.obj"
	-@erase "$(INTDIR)\JDFPreflightInstanceDetail.sbr"
	-@erase "$(INTDIR)\JDFPreflightInventory.obj"
	-@erase "$(INTDIR)\JDFPreflightInventory.sbr"
	-@erase "$(INTDIR)\JDFPreflightParams.obj"
	-@erase "$(INTDIR)\JDFPreflightParams.sbr"
	-@erase "$(INTDIR)\JDFPreflightProfile.obj"
	-@erase "$(INTDIR)\JDFPreflightProfile.sbr"
	-@erase "$(INTDIR)\JDFPreflightReport.obj"
	-@erase "$(INTDIR)\JDFPreflightReport.sbr"
	-@erase "$(INTDIR)\JDFPreflightReportRulePool.obj"
	-@erase "$(INTDIR)\JDFPreflightReportRulePool.sbr"
	-@erase "$(INTDIR)\JDFPreflightResultsPool.obj"
	-@erase "$(INTDIR)\JDFPreflightResultsPool.sbr"
	-@erase "$(INTDIR)\JDFPreflightValue.obj"
	-@erase "$(INTDIR)\JDFPreflightValue.sbr"
	-@erase "$(INTDIR)\JDFPRError.obj"
	-@erase "$(INTDIR)\JDFPRError.sbr"
	-@erase "$(INTDIR)\JDFPreview.obj"
	-@erase "$(INTDIR)\JDFPreview.sbr"
	-@erase "$(INTDIR)\JDFPreviewGenerationParams.obj"
	-@erase "$(INTDIR)\JDFPreviewGenerationParams.sbr"
	-@erase "$(INTDIR)\JDFPRGroup.obj"
	-@erase "$(INTDIR)\JDFPRGroup.sbr"
	-@erase "$(INTDIR)\JDFPRGroupOccurence.obj"
	-@erase "$(INTDIR)\JDFPRGroupOccurence.sbr"
	-@erase "$(INTDIR)\JDFPRGroupOccurenceBase.obj"
	-@erase "$(INTDIR)\JDFPRGroupOccurenceBase.sbr"
	-@erase "$(INTDIR)\JDFPricing.obj"
	-@erase "$(INTDIR)\JDFPricing.sbr"
	-@erase "$(INTDIR)\JDFPrintCondition.obj"
	-@erase "$(INTDIR)\JDFPrintCondition.sbr"
	-@erase "$(INTDIR)\JDFPrintConditionColor.obj"
	-@erase "$(INTDIR)\JDFPrintConditionColor.sbr"
	-@erase "$(INTDIR)\JDFPrintRollingParams.obj"
	-@erase "$(INTDIR)\JDFPrintRollingParams.sbr"
	-@erase "$(INTDIR)\JDFPRItem.obj"
	-@erase "$(INTDIR)\JDFPRItem.sbr"
	-@erase "$(INTDIR)\JDFPROccurence.obj"
	-@erase "$(INTDIR)\JDFPROccurence.sbr"
	-@erase "$(INTDIR)\JDFProcessRun.obj"
	-@erase "$(INTDIR)\JDFProcessRun.sbr"
	-@erase "$(INTDIR)\JDFProductionIntent.obj"
	-@erase "$(INTDIR)\JDFProductionIntent.sbr"
	-@erase "$(INTDIR)\JDFProofingIntent.obj"
	-@erase "$(INTDIR)\JDFProofingIntent.sbr"
	-@erase "$(INTDIR)\JDFProofingParams.obj"
	-@erase "$(INTDIR)\JDFProofingParams.sbr"
	-@erase "$(INTDIR)\JDFProofItem.obj"
	-@erase "$(INTDIR)\JDFProofItem.sbr"
	-@erase "$(INTDIR)\JDFProperties.obj"
	-@erase "$(INTDIR)\JDFProperties.sbr"
	-@erase "$(INTDIR)\JDFPRRule.obj"
	-@erase "$(INTDIR)\JDFPRRule.sbr"
	-@erase "$(INTDIR)\JDFPRRuleAttr.obj"
	-@erase "$(INTDIR)\JDFPRRuleAttr.sbr"
	-@erase "$(INTDIR)\JDFPSToPDFConversionParams.obj"
	-@erase "$(INTDIR)\JDFPSToPDFConversionParams.sbr"
	-@erase "$(INTDIR)\JDFQualityControlParams.obj"
	-@erase "$(INTDIR)\JDFQualityControlParams.sbr"
	-@erase "$(INTDIR)\JDFQualityControlResult.obj"
	-@erase "$(INTDIR)\JDFQualityControlResult.sbr"
	-@erase "$(INTDIR)\JDFQualityMeasurement.obj"
	-@erase "$(INTDIR)\JDFQualityMeasurement.sbr"
	-@erase "$(INTDIR)\JDFQuery.obj"
	-@erase "$(INTDIR)\JDFQuery.sbr"
	-@erase "$(INTDIR)\JDFQueue.obj"
	-@erase "$(INTDIR)\JDFQueue.sbr"
	-@erase "$(INTDIR)\JDFQueueEntry.obj"
	-@erase "$(INTDIR)\JDFQueueEntry.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryDef.obj"
	-@erase "$(INTDIR)\JDFQueueEntryDef.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryDefList.obj"
	-@erase "$(INTDIR)\JDFQueueEntryDefList.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryPosParams.obj"
	-@erase "$(INTDIR)\JDFQueueEntryPosParams.sbr"
	-@erase "$(INTDIR)\JDFQueueEntryPriParams.obj"
	-@erase "$(INTDIR)\JDFQueueEntryPriParams.sbr"
	-@erase "$(INTDIR)\JDFQueueFilter.obj"
	-@erase "$(INTDIR)\JDFQueueFilter.sbr"
	-@erase "$(INTDIR)\JDFQueueSubmissionParams.obj"
	-@erase "$(INTDIR)\JDFQueueSubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFRange.obj"
	-@erase "$(INTDIR)\JDFRange.sbr"
	-@erase "$(INTDIR)\JDFRangeList.obj"
	-@erase "$(INTDIR)\JDFRangeList.sbr"
	-@erase "$(INTDIR)\JDFRectangleEvaluation.obj"
	-@erase "$(INTDIR)\JDFRectangleEvaluation.sbr"
	-@erase "$(INTDIR)\JDFRectangleState.obj"
	-@erase "$(INTDIR)\JDFRectangleState.sbr"
	-@erase "$(INTDIR)\JDFRefElement.obj"
	-@erase "$(INTDIR)\JDFRefElement.sbr"
	-@erase "$(INTDIR)\JDFRegisterMark.obj"
	-@erase "$(INTDIR)\JDFRegisterMark.sbr"
	-@erase "$(INTDIR)\JDFRegisterRibbon.obj"
	-@erase "$(INTDIR)\JDFRegisterRibbon.sbr"
	-@erase "$(INTDIR)\JDFRemoved.obj"
	-@erase "$(INTDIR)\JDFRemoved.sbr"
	-@erase "$(INTDIR)\JDFRenderingParams.obj"
	-@erase "$(INTDIR)\JDFRenderingParams.sbr"
	-@erase "$(INTDIR)\JDFRequestQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFRequestQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFResource.obj"
	-@erase "$(INTDIR)\JDFResource.sbr"
	-@erase "$(INTDIR)\JDFResourceAudit.obj"
	-@erase "$(INTDIR)\JDFResourceAudit.sbr"
	-@erase "$(INTDIR)\JDFResourceCmdParams.obj"
	-@erase "$(INTDIR)\JDFResourceCmdParams.sbr"
	-@erase "$(INTDIR)\JDFResourceDefinitionParams.obj"
	-@erase "$(INTDIR)\JDFResourceDefinitionParams.sbr"
	-@erase "$(INTDIR)\JDFResourceInfo.obj"
	-@erase "$(INTDIR)\JDFResourceInfo.sbr"
	-@erase "$(INTDIR)\JDFResourceLink.obj"
	-@erase "$(INTDIR)\JDFResourceLink.sbr"
	-@erase "$(INTDIR)\JDFResourceLinkPool.obj"
	-@erase "$(INTDIR)\JDFResourceLinkPool.sbr"
	-@erase "$(INTDIR)\JDFResourceParam.obj"
	-@erase "$(INTDIR)\JDFResourceParam.sbr"
	-@erase "$(INTDIR)\JDFResourcePool.obj"
	-@erase "$(INTDIR)\JDFResourcePool.sbr"
	-@erase "$(INTDIR)\JDFResourcePullParams.obj"
	-@erase "$(INTDIR)\JDFResourcePullParams.sbr"
	-@erase "$(INTDIR)\JDFResourceQuParams.obj"
	-@erase "$(INTDIR)\JDFResourceQuParams.sbr"
	-@erase "$(INTDIR)\JDFResponse.obj"
	-@erase "$(INTDIR)\JDFResponse.sbr"
	-@erase "$(INTDIR)\JDFResubmissionParams.obj"
	-@erase "$(INTDIR)\JDFResubmissionParams.sbr"
	-@erase "$(INTDIR)\JDFReturnQueueEntryParams.obj"
	-@erase "$(INTDIR)\JDFReturnQueueEntryParams.sbr"
	-@erase "$(INTDIR)\JDFRingBinding.obj"
	-@erase "$(INTDIR)\JDFRingBinding.sbr"
	-@erase "$(INTDIR)\JDFRingBindingParams.obj"
	-@erase "$(INTDIR)\JDFRingBindingParams.sbr"
	-@erase "$(INTDIR)\JDFRollStand.obj"
	-@erase "$(INTDIR)\JDFRollStand.sbr"
	-@erase "$(INTDIR)\JDFRunElement.obj"
	-@erase "$(INTDIR)\JDFRunElement.sbr"
	-@erase "$(INTDIR)\JDFRunList.obj"
	-@erase "$(INTDIR)\JDFRunList.sbr"
	-@erase "$(INTDIR)\JDFSaddleStitching.obj"
	-@erase "$(INTDIR)\JDFSaddleStitching.sbr"
	-@erase "$(INTDIR)\JDFSaddleStitchingParams.obj"
	-@erase "$(INTDIR)\JDFSaddleStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFScanParams.obj"
	-@erase "$(INTDIR)\JDFScanParams.sbr"
	-@erase "$(INTDIR)\JDFScavengerArea.obj"
	-@erase "$(INTDIR)\JDFScavengerArea.sbr"
	-@erase "$(INTDIR)\JDFScore.obj"
	-@erase "$(INTDIR)\JDFScore.sbr"
	-@erase "$(INTDIR)\JDFScreeningIntent.obj"
	-@erase "$(INTDIR)\JDFScreeningIntent.sbr"
	-@erase "$(INTDIR)\JDFScreeningParams.obj"
	-@erase "$(INTDIR)\JDFScreeningParams.sbr"
	-@erase "$(INTDIR)\JDFScreenSelector.obj"
	-@erase "$(INTDIR)\JDFScreenSelector.sbr"
	-@erase "$(INTDIR)\JDFSeparationControlParams.obj"
	-@erase "$(INTDIR)\JDFSeparationControlParams.sbr"
	-@erase "$(INTDIR)\JDFSeparationList.obj"
	-@erase "$(INTDIR)\JDFSeparationList.sbr"
	-@erase "$(INTDIR)\JDFSeparationSpec.obj"
	-@erase "$(INTDIR)\JDFSeparationSpec.sbr"
	-@erase "$(INTDIR)\JDFset.obj"
	-@erase "$(INTDIR)\JDFset.sbr"
	-@erase "$(INTDIR)\JDFShapeCut.obj"
	-@erase "$(INTDIR)\JDFShapeCut.sbr"
	-@erase "$(INTDIR)\JDFShapeCuttingIntent.obj"
	-@erase "$(INTDIR)\JDFShapeCuttingIntent.sbr"
	-@erase "$(INTDIR)\JDFShapeCuttingParams.obj"
	-@erase "$(INTDIR)\JDFShapeCuttingParams.sbr"
	-@erase "$(INTDIR)\JDFShapeElement.obj"
	-@erase "$(INTDIR)\JDFShapeElement.sbr"
	-@erase "$(INTDIR)\JDFShapeEvaluation.obj"
	-@erase "$(INTDIR)\JDFShapeEvaluation.sbr"
	-@erase "$(INTDIR)\JDFShapeState.obj"
	-@erase "$(INTDIR)\JDFShapeState.sbr"
	-@erase "$(INTDIR)\JDFSheet.obj"
	-@erase "$(INTDIR)\JDFSheet.sbr"
	-@erase "$(INTDIR)\JDFShrinkingParams.obj"
	-@erase "$(INTDIR)\JDFShrinkingParams.sbr"
	-@erase "$(INTDIR)\JDFShutDownCmdParams.obj"
	-@erase "$(INTDIR)\JDFShutDownCmdParams.sbr"
	-@erase "$(INTDIR)\JDFSideSewing.obj"
	-@erase "$(INTDIR)\JDFSideSewing.sbr"
	-@erase "$(INTDIR)\JDFSideSewingParams.obj"
	-@erase "$(INTDIR)\JDFSideSewingParams.sbr"
	-@erase "$(INTDIR)\JDFSideStitching.obj"
	-@erase "$(INTDIR)\JDFSideStitching.sbr"
	-@erase "$(INTDIR)\JDFSignal.obj"
	-@erase "$(INTDIR)\JDFSignal.sbr"
	-@erase "$(INTDIR)\JDFSignature.obj"
	-@erase "$(INTDIR)\JDFSignature.sbr"
	-@erase "$(INTDIR)\JDFSignatureCell.obj"
	-@erase "$(INTDIR)\JDFSignatureCell.sbr"
	-@erase "$(INTDIR)\JDFSizeIntent.obj"
	-@erase "$(INTDIR)\JDFSizeIntent.sbr"
	-@erase "$(INTDIR)\JDFSoftCoverBinding.obj"
	-@erase "$(INTDIR)\JDFSoftCoverBinding.sbr"
	-@erase "$(INTDIR)\JDFSpan.obj"
	-@erase "$(INTDIR)\JDFSpan.sbr"
	-@erase "$(INTDIR)\JDFSpawned.obj"
	-@erase "$(INTDIR)\JDFSpawned.sbr"
	-@erase "$(INTDIR)\JDFSpinePreparationParams.obj"
	-@erase "$(INTDIR)\JDFSpinePreparationParams.sbr"
	-@erase "$(INTDIR)\JDFSpineTapingParams.obj"
	-@erase "$(INTDIR)\JDFSpineTapingParams.sbr"
	-@erase "$(INTDIR)\JDFStackingParams.obj"
	-@erase "$(INTDIR)\JDFStackingParams.sbr"
	-@erase "$(INTDIR)\JDFState.obj"
	-@erase "$(INTDIR)\JDFState.sbr"
	-@erase "$(INTDIR)\JDFStatusPool.obj"
	-@erase "$(INTDIR)\JDFStatusPool.sbr"
	-@erase "$(INTDIR)\JDFStatusQuParams.obj"
	-@erase "$(INTDIR)\JDFStatusQuParams.sbr"
	-@erase "$(INTDIR)\JDFStitchingParams.obj"
	-@erase "$(INTDIR)\JDFStitchingParams.sbr"
	-@erase "$(INTDIR)\JDFStopPersChParams.obj"
	-@erase "$(INTDIR)\JDFStopPersChParams.sbr"
	-@erase "$(INTDIR)\JDFStrap.obj"
	-@erase "$(INTDIR)\JDFStrap.sbr"
	-@erase "$(INTDIR)\JDFStrappingParams.obj"
	-@erase "$(INTDIR)\JDFStrappingParams.sbr"
	-@erase "$(INTDIR)\JDFStringEvaluation.obj"
	-@erase "$(INTDIR)\JDFStringEvaluation.sbr"
	-@erase "$(INTDIR)\JDFStringListValue.obj"
	-@erase "$(INTDIR)\JDFStringListValue.sbr"
	-@erase "$(INTDIR)\JDFStrings.obj"
	-@erase "$(INTDIR)\JDFStrings.sbr"
	-@erase "$(INTDIR)\JDFStringState.obj"
	-@erase "$(INTDIR)\JDFStringState.sbr"
	-@erase "$(INTDIR)\JDFStripBinding.obj"
	-@erase "$(INTDIR)\JDFStripBinding.sbr"
	-@erase "$(INTDIR)\JDFStripBindingParams.obj"
	-@erase "$(INTDIR)\JDFStripBindingParams.sbr"
	-@erase "$(INTDIR)\JDFStripCellParams.obj"
	-@erase "$(INTDIR)\JDFStripCellParams.sbr"
	-@erase "$(INTDIR)\JDFStrippingParams.obj"
	-@erase "$(INTDIR)\JDFStrippingParams.sbr"
	-@erase "$(INTDIR)\JDFSubmissionMethods.obj"
	-@erase "$(INTDIR)\JDFSubmissionMethods.sbr"
	-@erase "$(INTDIR)\JDFSubscription.obj"
	-@erase "$(INTDIR)\JDFSubscription.sbr"
	-@erase "$(INTDIR)\JDFSurface.obj"
	-@erase "$(INTDIR)\JDFSurface.sbr"
	-@erase "$(INTDIR)\JDFSystemTimeSet.obj"
	-@erase "$(INTDIR)\JDFSystemTimeSet.sbr"
	-@erase "$(INTDIR)\JDFTabs.obj"
	-@erase "$(INTDIR)\JDFTabs.sbr"
	-@erase "$(INTDIR)\JDFTape.obj"
	-@erase "$(INTDIR)\JDFTape.sbr"
	-@erase "$(INTDIR)\JDFTest.obj"
	-@erase "$(INTDIR)\JDFTest.sbr"
	-@erase "$(INTDIR)\JDFTestPool.obj"
	-@erase "$(INTDIR)\JDFTestPool.sbr"
	-@erase "$(INTDIR)\JDFTestRef.obj"
	-@erase "$(INTDIR)\JDFTestRef.sbr"
	-@erase "$(INTDIR)\JDFThinPDFParams.obj"
	-@erase "$(INTDIR)\JDFThinPDFParams.sbr"
	-@erase "$(INTDIR)\JDFThreadSealing.obj"
	-@erase "$(INTDIR)\JDFThreadSealing.sbr"
	-@erase "$(INTDIR)\JDFThreadSealingParams.obj"
	-@erase "$(INTDIR)\JDFThreadSealingParams.sbr"
	-@erase "$(INTDIR)\JDFThreadSewing.obj"
	-@erase "$(INTDIR)\JDFThreadSewing.sbr"
	-@erase "$(INTDIR)\JDFThreadSewingParams.obj"
	-@erase "$(INTDIR)\JDFThreadSewingParams.sbr"
	-@erase "$(INTDIR)\JDFTIFFEmbeddedFile.obj"
	-@erase "$(INTDIR)\JDFTIFFEmbeddedFile.sbr"
	-@erase "$(INTDIR)\JDFTIFFFormatParams.obj"
	-@erase "$(INTDIR)\JDFTIFFFormatParams.sbr"
	-@erase "$(INTDIR)\JDFTIFFtag.obj"
	-@erase "$(INTDIR)\JDFTIFFtag.sbr"
	-@erase "$(INTDIR)\JDFTile.obj"
	-@erase "$(INTDIR)\JDFTile.sbr"
	-@erase "$(INTDIR)\JDFTool.obj"
	-@erase "$(INTDIR)\JDFTool.sbr"
	-@erase "$(INTDIR)\JDFTrackFilter.obj"
	-@erase "$(INTDIR)\JDFTrackFilter.sbr"
	-@erase "$(INTDIR)\JDFTrackResult.obj"
	-@erase "$(INTDIR)\JDFTrackResult.sbr"
	-@erase "$(INTDIR)\JDFTransferCurve.obj"
	-@erase "$(INTDIR)\JDFTransferCurve.sbr"
	-@erase "$(INTDIR)\JDFTransferCurvePool.obj"
	-@erase "$(INTDIR)\JDFTransferCurvePool.sbr"
	-@erase "$(INTDIR)\JDFTransferCurveSet.obj"
	-@erase "$(INTDIR)\JDFTransferCurveSet.sbr"
	-@erase "$(INTDIR)\JDFTransferFunctionControl.obj"
	-@erase "$(INTDIR)\JDFTransferFunctionControl.sbr"
	-@erase "$(INTDIR)\JDFTrappingDetails.obj"
	-@erase "$(INTDIR)\JDFTrappingDetails.sbr"
	-@erase "$(INTDIR)\JDFTrappingOrder.obj"
	-@erase "$(INTDIR)\JDFTrappingOrder.sbr"
	-@erase "$(INTDIR)\JDFTrappingParams.obj"
	-@erase "$(INTDIR)\JDFTrappingParams.sbr"
	-@erase "$(INTDIR)\JDFTrapRegion.obj"
	-@erase "$(INTDIR)\JDFTrapRegion.sbr"
	-@erase "$(INTDIR)\JDFTrigger.obj"
	-@erase "$(INTDIR)\JDFTrigger.sbr"
	-@erase "$(INTDIR)\JDFTrimmingParams.obj"
	-@erase "$(INTDIR)\JDFTrimmingParams.sbr"
	-@erase "$(INTDIR)\JDFValue.obj"
	-@erase "$(INTDIR)\JDFValue.sbr"
	-@erase "$(INTDIR)\JDFValueLoc.obj"
	-@erase "$(INTDIR)\JDFValueLoc.sbr"
	-@erase "$(INTDIR)\JDFVerificationParams.obj"
	-@erase "$(INTDIR)\JDFVerificationParams.sbr"
	-@erase "$(INTDIR)\JDFWakeUpCmdParams.obj"
	-@erase "$(INTDIR)\JDFWakeUpCmdParams.sbr"
	-@erase "$(INTDIR)\JDFwhen.obj"
	-@erase "$(INTDIR)\JDFwhen.sbr"
	-@erase "$(INTDIR)\JDFWireCombBinding.obj"
	-@erase "$(INTDIR)\JDFWireCombBinding.sbr"
	-@erase "$(INTDIR)\JDFWireCombBindingParams.obj"
	-@erase "$(INTDIR)\JDFWireCombBindingParams.sbr"
	-@erase "$(INTDIR)\JDFWrappingParams.obj"
	-@erase "$(INTDIR)\JDFWrappingParams.sbr"
	-@erase "$(INTDIR)\JDFxor.obj"
	-@erase "$(INTDIR)\JDFxor.sbr"
	-@erase "$(INTDIR)\JDFXYPairEvaluation.obj"
	-@erase "$(INTDIR)\JDFXYPairEvaluation.sbr"
	-@erase "$(INTDIR)\JDFXYPairRangeList.obj"
	-@erase "$(INTDIR)\JDFXYPairRangeList.sbr"
	-@erase "$(INTDIR)\JDFXYPairState.obj"
	-@erase "$(INTDIR)\JDFXYPairState.sbr"
	-@erase "$(INTDIR)\KElement.obj"
	-@erase "$(INTDIR)\KElement.sbr"
	-@erase "$(INTDIR)\KElementStrings.obj"
	-@erase "$(INTDIR)\KElementStrings.sbr"
	-@erase "$(INTDIR)\MyDate.obj"
	-@erase "$(INTDIR)\MyDate.sbr"
	-@erase "$(INTDIR)\vElement.obj"
	-@erase "$(INTDIR)\vElement.sbr"
	-@erase "$(INTDIR)\XMLDoc.obj"
	-@erase "$(INTDIR)\XMLDoc.sbr"
	-@erase "$(INTDIR)\XMLDocUserData.obj"
	-@erase "$(INTDIR)\XMLDocUserData.sbr"
	-@erase "$(OUTDIR)\JDFWrapperLib.bsc"
	-@erase "$(OUTDIR)\JDFWrapperLib_D.lib"
	-@erase "..\..\..\Build\Win32\VC6\DebugLineOnly\JDFWrapperLib.idb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

MTL=midl.exe
LINK32=link.exe
CPP=xicl6.exe
CPP_PROJ=/nologo /MDd /w /W0 /GX /Zd /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\src\jdf" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "_DEBUG" /D "_WINDOWS" /D "WIN32" /D "JDF_TOOLS_LIB" /D "JDF_WRAPPERCORE_LIB" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"..\..\..\Build\Win32\VC6\DebugLineOnly\JDFWrapperLib" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\JDFWrapperLib.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\JDFAmountPool.sbr" \
	"$(INTDIR)\JDFAncestor.sbr" \
	"$(INTDIR)\JDFAncestorPool.sbr" \
	"$(INTDIR)\JDFAudit.sbr" \
	"$(INTDIR)\JDFAuditPool.sbr" \
	"$(INTDIR)\JDFBarcode.sbr" \
	"$(INTDIR)\JDFBusinessInfo.sbr" \
	"$(INTDIR)\JDFComment.sbr" \
	"$(INTDIR)\JDFCounterReset.sbr" \
	"$(INTDIR)\JDFCreated.sbr" \
	"$(INTDIR)\JDFCustomerInfo.sbr" \
	"$(INTDIR)\JDFCustomerMessage.sbr" \
	"$(INTDIR)\JDFDeleted.sbr" \
	"$(INTDIR)\JDFError.sbr" \
	"$(INTDIR)\JDFEvent.sbr" \
	"$(INTDIR)\JDFFCNKey.sbr" \
	"$(INTDIR)\JDFLocation.sbr" \
	"$(INTDIR)\JDFMerged.sbr" \
	"$(INTDIR)\JDFModified.sbr" \
	"$(INTDIR)\JDFModulePhase.sbr" \
	"$(INTDIR)\JDFNode.sbr" \
	"$(INTDIR)\JDFNodeInfo.sbr" \
	"$(INTDIR)\JDFNotification.sbr" \
	"$(INTDIR)\JDFPart.sbr" \
	"$(INTDIR)\JDFPartAmount.sbr" \
	"$(INTDIR)\JDFPartStatus.sbr" \
	"$(INTDIR)\JDFPhaseTime.sbr" \
	"$(INTDIR)\JDFProcessRun.sbr" \
	"$(INTDIR)\JDFResourceAudit.sbr" \
	"$(INTDIR)\JDFResourceLinkPool.sbr" \
	"$(INTDIR)\JDFResourcePool.sbr" \
	"$(INTDIR)\JDFSpawned.sbr" \
	"$(INTDIR)\JDFStatusPool.sbr" \
	"$(INTDIR)\JDFSystemTimeSet.sbr" \
	"$(INTDIR)\JDFAcknowledge.sbr" \
	"$(INTDIR)\JDFAdded.sbr" \
	"$(INTDIR)\JDFChangedAttribute.sbr" \
	"$(INTDIR)\JDFChangedPath.sbr" \
	"$(INTDIR)\JDFCommand.sbr" \
	"$(INTDIR)\JDFDeviceFilter.sbr" \
	"$(INTDIR)\JDFDeviceInfo.sbr" \
	"$(INTDIR)\JDFDeviceList.sbr" \
	"$(INTDIR)\JDFEmployeeDef.sbr" \
	"$(INTDIR)\JDFFlushedResources.sbr" \
	"$(INTDIR)\JDFFlushQueueParams.sbr" \
	"$(INTDIR)\JDFFlushResourceParams.sbr" \
	"$(INTDIR)\JDFIDInfo.sbr" \
	"$(INTDIR)\JDFJDFController.sbr" \
	"$(INTDIR)\JDFJDFService.sbr" \
	"$(INTDIR)\JDFJMF.sbr" \
	"$(INTDIR)\JDFJobPhase.sbr" \
	"$(INTDIR)\JDFKnownMsgQuParams.sbr" \
	"$(INTDIR)\JDFMessage.sbr" \
	"$(INTDIR)\JDFMessageElement.sbr" \
	"$(INTDIR)\JDFMessageService.sbr" \
	"$(INTDIR)\JDFModuleStatus.sbr" \
	"$(INTDIR)\JDFMsgFilter.sbr" \
	"$(INTDIR)\JDFNewJDFCmdParams.sbr" \
	"$(INTDIR)\JDFNewJDFQuParams.sbr" \
	"$(INTDIR)\JDFNodeInfoCmdParams.sbr" \
	"$(INTDIR)\JDFNodeInfoQuParams.sbr" \
	"$(INTDIR)\JDFNodeInfoResp.sbr" \
	"$(INTDIR)\JDFNotificationDef.sbr" \
	"$(INTDIR)\JDFNotificationFilter.sbr" \
	"$(INTDIR)\JDFObservationTarget.sbr" \
	"$(INTDIR)\JDFOccupation.sbr" \
	"$(INTDIR)\JDFPipeParams.sbr" \
	"$(INTDIR)\JDFQuery.sbr" \
	"$(INTDIR)\JDFQueue.sbr" \
	"$(INTDIR)\JDFQueueEntry.sbr" \
	"$(INTDIR)\JDFQueueEntryDef.sbr" \
	"$(INTDIR)\JDFQueueEntryDefList.sbr" \
	"$(INTDIR)\JDFQueueEntryPosParams.sbr" \
	"$(INTDIR)\JDFQueueEntryPriParams.sbr" \
	"$(INTDIR)\JDFQueueFilter.sbr" \
	"$(INTDIR)\JDFQueueSubmissionParams.sbr" \
	"$(INTDIR)\JDFRemoved.sbr" \
	"$(INTDIR)\JDFRequestQueueEntryParams.sbr" \
	"$(INTDIR)\JDFResourceCmdParams.sbr" \
	"$(INTDIR)\JDFResourceInfo.sbr" \
	"$(INTDIR)\JDFResourcePullParams.sbr" \
	"$(INTDIR)\JDFResourceQuParams.sbr" \
	"$(INTDIR)\JDFResponse.sbr" \
	"$(INTDIR)\JDFResubmissionParams.sbr" \
	"$(INTDIR)\JDFReturnQueueEntryParams.sbr" \
	"$(INTDIR)\JDFShutDownCmdParams.sbr" \
	"$(INTDIR)\JDFSignal.sbr" \
	"$(INTDIR)\JDFStatusQuParams.sbr" \
	"$(INTDIR)\JDFStopPersChParams.sbr" \
	"$(INTDIR)\JDFSubmissionMethods.sbr" \
	"$(INTDIR)\JDFSubscription.sbr" \
	"$(INTDIR)\JDFTrackFilter.sbr" \
	"$(INTDIR)\JDFTrackResult.sbr" \
	"$(INTDIR)\JDFTrigger.sbr" \
	"$(INTDIR)\JDFWakeUpCmdParams.sbr" \
	"$(INTDIR)\JDFArtDeliveryIntent.sbr" \
	"$(INTDIR)\JDFBindingIntent.sbr" \
	"$(INTDIR)\JDFColorIntent.sbr" \
	"$(INTDIR)\JDFDeliveryIntent.sbr" \
	"$(INTDIR)\JDFEmbossingIntent.sbr" \
	"$(INTDIR)\JDFFoldingIntent.sbr" \
	"$(INTDIR)\JDFHoleMakingIntent.sbr" \
	"$(INTDIR)\JDFInsertingIntent.sbr" \
	"$(INTDIR)\JDFIntentResource.sbr" \
	"$(INTDIR)\JDFLaminatingIntent.sbr" \
	"$(INTDIR)\JDFLayoutIntent.sbr" \
	"$(INTDIR)\JDFMediaIntent.sbr" \
	"$(INTDIR)\JDFNumberingIntent.sbr" \
	"$(INTDIR)\JDFPackingIntent.sbr" \
	"$(INTDIR)\JDFProductionIntent.sbr" \
	"$(INTDIR)\JDFProofingIntent.sbr" \
	"$(INTDIR)\JDFScreeningIntent.sbr" \
	"$(INTDIR)\JDFShapeCuttingIntent.sbr" \
	"$(INTDIR)\JDFSizeIntent.sbr" \
	"$(INTDIR)\JDFSpan.sbr" \
	"$(INTDIR)\JDFAdhesiveBinding.sbr" \
	"$(INTDIR)\JDFArtDelivery.sbr" \
	"$(INTDIR)\JDFBindItem.sbr" \
	"$(INTDIR)\JDFBindList.sbr" \
	"$(INTDIR)\JDFBookCase.sbr" \
	"$(INTDIR)\JDFChannelBinding.sbr" \
	"$(INTDIR)\JDFCoilBinding.sbr" \
	"$(INTDIR)\JDFColorsUsed.sbr" \
	"$(INTDIR)\JDFCreditCard.sbr" \
	"$(INTDIR)\JDFDropIntent.sbr" \
	"$(INTDIR)\JDFDropItemIntent.sbr" \
	"$(INTDIR)\JDFEdgeGluing.sbr" \
	"$(INTDIR)\JDFEmbossingItem.sbr" \
	"$(INTDIR)\JDFHardCoverBinding.sbr" \
	"$(INTDIR)\JDFHoleList.sbr" \
	"$(INTDIR)\JDFInsert.sbr" \
	"$(INTDIR)\JDFInsertList.sbr" \
	"$(INTDIR)\JDFNumberItem.sbr" \
	"$(INTDIR)\JDFPayment.sbr" \
	"$(INTDIR)\JDFPlasticCombBinding.sbr" \
	"$(INTDIR)\JDFPricing.sbr" \
	"$(INTDIR)\JDFProofItem.sbr" \
	"$(INTDIR)\JDFRingBinding.sbr" \
	"$(INTDIR)\JDFSaddleStitching.sbr" \
	"$(INTDIR)\JDFShapeCut.sbr" \
	"$(INTDIR)\JDFSideSewing.sbr" \
	"$(INTDIR)\JDFSideStitching.sbr" \
	"$(INTDIR)\JDFSoftCoverBinding.sbr" \
	"$(INTDIR)\JDFStripBinding.sbr" \
	"$(INTDIR)\JDFTabs.sbr" \
	"$(INTDIR)\JDFTape.sbr" \
	"$(INTDIR)\JDFThreadSealing.sbr" \
	"$(INTDIR)\JDFThreadSewing.sbr" \
	"$(INTDIR)\JDFWireCombBinding.sbr" \
	"$(INTDIR)\JDFAddress.sbr" \
	"$(INTDIR)\JDFAdhesiveBindingParams.sbr" \
	"$(INTDIR)\JDFApprovalParams.sbr" \
	"$(INTDIR)\JDFApprovalSuccess.sbr" \
	"$(INTDIR)\JDFAssembly.sbr" \
	"$(INTDIR)\JDFAssetListCreationParams.sbr" \
	"$(INTDIR)\JDFAutomatedOverprintParams.sbr" \
	"$(INTDIR)\JDFBinderySignature.sbr" \
	"$(INTDIR)\JDFBlockPreparationParams.sbr" \
	"$(INTDIR)\JDFBoxPackingParams.sbr" \
	"$(INTDIR)\JDFBufferParams.sbr" \
	"$(INTDIR)\JDFBundle.sbr" \
	"$(INTDIR)\JDFBundlingParams.sbr" \
	"$(INTDIR)\JDFByteMap.sbr" \
	"$(INTDIR)\JDFCaseMakingParams.sbr" \
	"$(INTDIR)\JDFCasingInParams.sbr" \
	"$(INTDIR)\JDFChannelBindingParams.sbr" \
	"$(INTDIR)\JDFCIELABMeasuringField.sbr" \
	"$(INTDIR)\JDFCoilBindingParams.sbr" \
	"$(INTDIR)\JDFCollectingParams.sbr" \
	"$(INTDIR)\JDFColor.sbr" \
	"$(INTDIR)\JDFColorantAlias.sbr" \
	"$(INTDIR)\JDFColorantControl.sbr" \
	"$(INTDIR)\JDFColorControlStrip.sbr" \
	"$(INTDIR)\JDFColorCorrectionParams.sbr" \
	"$(INTDIR)\JDFColorMeasurementConditions.sbr" \
	"$(INTDIR)\JDFColorPool.sbr" \
	"$(INTDIR)\JDFColorSpaceConversionOp.sbr" \
	"$(INTDIR)\JDFColorSpaceConversionParams.sbr" \
	"$(INTDIR)\JDFComChannel.sbr" \
	"$(INTDIR)\JDFCompany.sbr" \
	"$(INTDIR)\JDFComponent.sbr" \
	"$(INTDIR)\JDFContact.sbr" \
	"$(INTDIR)\JDFContactCopyParams.sbr" \
	"$(INTDIR)\JDFConventionalPrintingParams.sbr" \
	"$(INTDIR)\JDFCostCenter.sbr" \
	"$(INTDIR)\JDFCoverApplicationParams.sbr" \
	"$(INTDIR)\JDFCreasingParams.sbr" \
	"$(INTDIR)\JDFCutBlock.sbr" \
	"$(INTDIR)\JDFCutMark.sbr" \
	"$(INTDIR)\JDFCuttingParams.sbr" \
	"$(INTDIR)\JDFDBMergeParams.sbr" \
	"$(INTDIR)\JDFDBRules.sbr" \
	"$(INTDIR)\JDFDBSchema.sbr" \
	"$(INTDIR)\JDFDBSelection.sbr" \
	"$(INTDIR)\JDFDeliveryParams.sbr" \
	"$(INTDIR)\JDFDensityMeasuringField.sbr" \
	"$(INTDIR)\JDFDevelopingParams.sbr" \
	"$(INTDIR)\JDFDevice.sbr" \
	"$(INTDIR)\JDFDeviceMark.sbr" \
	"$(INTDIR)\JDFDeviceNSpace.sbr" \
	"$(INTDIR)\JDFDigitalDeliveryParams.sbr" \
	"$(INTDIR)\JDFDigitalMedia.sbr" \
	"$(INTDIR)\JDFDigitalPrintingParams.sbr" \
	"$(INTDIR)\JDFDisjointing.sbr" \
	"$(INTDIR)\JDFDisposition.sbr" \
	"$(INTDIR)\JDFDividingParams.sbr" \
	"$(INTDIR)\JDFElementColorParams.sbr" \
	"$(INTDIR)\JDFEmbossingParams.sbr" \
	"$(INTDIR)\JDFEmployee.sbr" \
	"$(INTDIR)\JDFEndSheetGluingParams.sbr" \
	"$(INTDIR)\JDFExposedMedia.sbr" \
	"$(INTDIR)\JDFFeedingParams.sbr" \
	"$(INTDIR)\JDFFileSpec.sbr" \
	"$(INTDIR)\JDFFitPolicy.sbr" \
	"$(INTDIR)\JDFFold.sbr" \
	"$(INTDIR)\JDFFoldingParams.sbr" \
	"$(INTDIR)\JDFFontParams.sbr" \
	"$(INTDIR)\JDFFontPolicy.sbr" \
	"$(INTDIR)\JDFFormatConversionParams.sbr" \
	"$(INTDIR)\JDFGatheringParams.sbr" \
	"$(INTDIR)\JDFGlueApplication.sbr" \
	"$(INTDIR)\JDFGlueLine.sbr" \
	"$(INTDIR)\JDFGluingParams.sbr" \
	"$(INTDIR)\JDFHeadBandApplicationParams.sbr" \
	"$(INTDIR)\JDFHole.sbr" \
	"$(INTDIR)\JDFHoleLine.sbr" \
	"$(INTDIR)\JDFHoleMakingParams.sbr" \
	"$(INTDIR)\JDFIdentificationField.sbr" \
	"$(INTDIR)\JDFIDPrintingParams.sbr" \
	"$(INTDIR)\JDFImageCompressionParams.sbr" \
	"$(INTDIR)\JDFImageReplacementParams.sbr" \
	"$(INTDIR)\JDFImageSetterParams.sbr" \
	"$(INTDIR)\JDFInk.sbr" \
	"$(INTDIR)\JDFInkZoneCalculationParams.sbr" \
	"$(INTDIR)\JDFInkZoneProfile.sbr" \
	"$(INTDIR)\JDFInsertingParams.sbr" \
	"$(INTDIR)\JDFInsertSheet.sbr" \
	"$(INTDIR)\JDFInterpretedPDLData.sbr" \
	"$(INTDIR)\JDFInterpretingParams.sbr" \
	"$(INTDIR)\JDFJacketingParams.sbr" \
	"$(INTDIR)\JDFJobField.sbr" \
	"$(INTDIR)\JDFLabelingParams.sbr" \
	"$(INTDIR)\JDFLaminatingParams.sbr" \
	"$(INTDIR)\JDFLayout.sbr" \
	"$(INTDIR)\JDFLayoutElement.sbr" \
	"$(INTDIR)\JDFLayoutPreparationParams.sbr" \
	"$(INTDIR)\JDFLongitudinalRibbonOperationParams.sbr" \
	"$(INTDIR)\JDFManualLaborParams.sbr" \
	"$(INTDIR)\JDFMedia.sbr" \
	"$(INTDIR)\JDFMediaSource.sbr" \
	"$(INTDIR)\JDFMISDetails.sbr" \
	"$(INTDIR)\JDFNumberingParams.sbr" \
	"$(INTDIR)\JDFObjectResolution.sbr" \
	"$(INTDIR)\JDFOrderingParams.sbr" \
	"$(INTDIR)\JDFPackingParams.sbr" \
	"$(INTDIR)\JDFPageList.sbr" \
	"$(INTDIR)\JDFPallet.sbr" \
	"$(INTDIR)\JDFPalletizingParams.sbr" \
	"$(INTDIR)\JDFPDFToPSConversionParams.sbr" \
	"$(INTDIR)\JDFPDLResourceAlias.sbr" \
	"$(INTDIR)\JDFPerforatingParams.sbr" \
	"$(INTDIR)\JDFPerson.sbr" \
	"$(INTDIR)\JDFPlaceHolderResource.sbr" \
	"$(INTDIR)\JDFPlasticCombBindingParams.sbr" \
	"$(INTDIR)\JDFPlateCopyParams.sbr" \
	"$(INTDIR)\JDFPreflightAnalysis.sbr" \
	"$(INTDIR)\JDFPreflightInventory.sbr" \
	"$(INTDIR)\JDFPreflightParams.sbr" \
	"$(INTDIR)\JDFPreflightProfile.sbr" \
	"$(INTDIR)\JDFPreflightReport.sbr" \
	"$(INTDIR)\JDFPreflightReportRulePool.sbr" \
	"$(INTDIR)\JDFPreview.sbr" \
	"$(INTDIR)\JDFPreviewGenerationParams.sbr" \
	"$(INTDIR)\JDFPrintCondition.sbr" \
	"$(INTDIR)\JDFPrintRollingParams.sbr" \
	"$(INTDIR)\JDFProofingParams.sbr" \
	"$(INTDIR)\JDFPSToPDFConversionParams.sbr" \
	"$(INTDIR)\JDFQualityControlParams.sbr" \
	"$(INTDIR)\JDFQualityControlResult.sbr" \
	"$(INTDIR)\JDFRegisterMark.sbr" \
	"$(INTDIR)\JDFRegisterRibbon.sbr" \
	"$(INTDIR)\JDFRenderingParams.sbr" \
	"$(INTDIR)\JDFResourceDefinitionParams.sbr" \
	"$(INTDIR)\JDFRingBindingParams.sbr" \
	"$(INTDIR)\JDFRollStand.sbr" \
	"$(INTDIR)\JDFRunList.sbr" \
	"$(INTDIR)\JDFSaddleStitchingParams.sbr" \
	"$(INTDIR)\JDFScanParams.sbr" \
	"$(INTDIR)\JDFScavengerArea.sbr" \
	"$(INTDIR)\JDFScreeningParams.sbr" \
	"$(INTDIR)\JDFSeparationControlParams.sbr" \
	"$(INTDIR)\JDFSeparationSpec.sbr" \
	"$(INTDIR)\JDFShapeCuttingParams.sbr" \
	"$(INTDIR)\JDFSheet.sbr" \
	"$(INTDIR)\JDFShrinkingParams.sbr" \
	"$(INTDIR)\JDFSideSewingParams.sbr" \
	"$(INTDIR)\JDFSpinePreparationParams.sbr" \
	"$(INTDIR)\JDFSpineTapingParams.sbr" \
	"$(INTDIR)\JDFStackingParams.sbr" \
	"$(INTDIR)\JDFStitchingParams.sbr" \
	"$(INTDIR)\JDFStrap.sbr" \
	"$(INTDIR)\JDFStrappingParams.sbr" \
	"$(INTDIR)\JDFStripBindingParams.sbr" \
	"$(INTDIR)\JDFStrippingParams.sbr" \
	"$(INTDIR)\JDFSurface.sbr" \
	"$(INTDIR)\JDFThreadSealingParams.sbr" \
	"$(INTDIR)\JDFThreadSewingParams.sbr" \
	"$(INTDIR)\JDFTile.sbr" \
	"$(INTDIR)\JDFTool.sbr" \
	"$(INTDIR)\JDFTransferCurve.sbr" \
	"$(INTDIR)\JDFTransferCurvePool.sbr" \
	"$(INTDIR)\JDFTransferFunctionControl.sbr" \
	"$(INTDIR)\JDFTrappingDetails.sbr" \
	"$(INTDIR)\JDFTrappingParams.sbr" \
	"$(INTDIR)\JDFTrapRegion.sbr" \
	"$(INTDIR)\JDFTrimmingParams.sbr" \
	"$(INTDIR)\JDFVerificationParams.sbr" \
	"$(INTDIR)\JDFWireCombBindingParams.sbr" \
	"$(INTDIR)\JDFWrappingParams.sbr" \
	"$(INTDIR)\JDFAdvancedParams.sbr" \
	"$(INTDIR)\JDFApprovalPerson.sbr" \
	"$(INTDIR)\JDFAssemblySection.sbr" \
	"$(INTDIR)\JDFBand.sbr" \
	"$(INTDIR)\JDFBasicPreflightTest.sbr" \
	"$(INTDIR)\JDFBindingQualityParams.sbr" \
	"$(INTDIR)\JDFBoxArgument.sbr" \
	"$(INTDIR)\JDFBoxToBoxDifference.sbr" \
	"$(INTDIR)\JDFBundleItem.sbr" \
	"$(INTDIR)\JDFCCITTFaxParams.sbr" \
	"$(INTDIR)\JDFCollatingItem.sbr" \
	"$(INTDIR)\JDFColorantZoneDetails.sbr" \
	"$(INTDIR)\JDFColorCorrectionOp.sbr" \
	"$(INTDIR)\JDFColorSpaceSubstitute.sbr" \
	"$(INTDIR)\JDFContainer.sbr" \
	"$(INTDIR)\JDFContentObject.sbr" \
	"$(INTDIR)\JDFCrease.sbr" \
	"$(INTDIR)\JDFCut.sbr" \
	"$(INTDIR)\JDFDCTParams.sbr" \
	"$(INTDIR)\JDFDependencies.sbr" \
	"$(INTDIR)\JDFDeviceNColor.sbr" \
	"$(INTDIR)\JDFDrop.sbr" \
	"$(INTDIR)\JDFDropItem.sbr" \
	"$(INTDIR)\JDFDynamicField.sbr" \
	"$(INTDIR)\JDFDynamicInput.sbr" \
	"$(INTDIR)\JDFEmboss.sbr" \
	"$(INTDIR)\JDFEndSheet.sbr" \
	"$(INTDIR)\JDFFeeder.sbr" \
	"$(INTDIR)\JDFFeederQualityParams.sbr" \
	"$(INTDIR)\JDFFileAlias.sbr" \
	"$(INTDIR)\JDFFlateParams.sbr" \
	"$(INTDIR)\JDFGlue.sbr" \
	"$(INTDIR)\JDFIcon.sbr" \
	"$(INTDIR)\JDFIconList.sbr" \
	"$(INTDIR)\JDFIDPCover.sbr" \
	"$(INTDIR)\JDFIDPFinishing.sbr" \
	"$(INTDIR)\JDFIDPFolding.sbr" \
	"$(INTDIR)\JDFIDPHoleMaking.sbr" \
	"$(INTDIR)\JDFIDPImageShift.sbr" \
	"$(INTDIR)\JDFIDPJobSheet.sbr" \
	"$(INTDIR)\JDFIDPLayout.sbr" \
	"$(INTDIR)\JDFIDPStitching.sbr" \
	"$(INTDIR)\JDFIDPTrimming.sbr" \
	"$(INTDIR)\JDFImageCompression.sbr" \
	"$(INTDIR)\JDFImageShift.sbr" \
	"$(INTDIR)\JDFLayerDetails.sbr" \
	"$(INTDIR)\JDFLayerList.sbr" \
	"$(INTDIR)\JDFLongFold.sbr" \
	"$(INTDIR)\JDFLongGlue.sbr" \
	"$(INTDIR)\JDFLongPerforate.sbr" \
	"$(INTDIR)\JDFLongSlit.sbr" \
	"$(INTDIR)\JDFLZWParams.sbr" \
	"$(INTDIR)\JDFMarkObject.sbr" \
	"$(INTDIR)\JDFNumberingParam.sbr" \
	"$(INTDIR)\JDFPageCell.sbr" \
	"$(INTDIR)\JDFPageData.sbr" \
	"$(INTDIR)\JDFPDFInterpretingParams.sbr" \
	"$(INTDIR)\JDFPDFXParams.sbr" \
	"$(INTDIR)\JDFPerforate.sbr" \
	"$(INTDIR)\JDFPixelColorant.sbr" \
	"$(INTDIR)\JDFPosition.sbr" \
	"$(INTDIR)\JDFPreflightAction.sbr" \
	"$(INTDIR)\JDFPreflightArgument.sbr" \
	"$(INTDIR)\JDFPreflightConstraint.sbr" \
	"$(INTDIR)\JDFPreflightDetail.sbr" \
	"$(INTDIR)\JDFPreflightInstance.sbr" \
	"$(INTDIR)\JDFPreflightInstanceDetail.sbr" \
	"$(INTDIR)\JDFPreflightValue.sbr" \
	"$(INTDIR)\JDFPRError.sbr" \
	"$(INTDIR)\JDFPRGroup.sbr" \
	"$(INTDIR)\JDFPrintConditionColor.sbr" \
	"$(INTDIR)\JDFPRItem.sbr" \
	"$(INTDIR)\JDFPROccurence.sbr" \
	"$(INTDIR)\JDFProperties.sbr" \
	"$(INTDIR)\JDFPRRule.sbr" \
	"$(INTDIR)\JDFPRRuleAttr.sbr" \
	"$(INTDIR)\JDFQualityMeasurement.sbr" \
	"$(INTDIR)\JDFResourceParam.sbr" \
	"$(INTDIR)\JDFScore.sbr" \
	"$(INTDIR)\JDFScreenSelector.sbr" \
	"$(INTDIR)\JDFShapeElement.sbr" \
	"$(INTDIR)\JDFSignature.sbr" \
	"$(INTDIR)\JDFSignatureCell.sbr" \
	"$(INTDIR)\JDFStringListValue.sbr" \
	"$(INTDIR)\JDFStripCellParams.sbr" \
	"$(INTDIR)\JDFThinPDFParams.sbr" \
	"$(INTDIR)\JDFTIFFEmbeddedFile.sbr" \
	"$(INTDIR)\JDFTIFFFormatParams.sbr" \
	"$(INTDIR)\JDFTIFFtag.sbr" \
	"$(INTDIR)\JDFTransferCurveSet.sbr" \
	"$(INTDIR)\JDFTrappingOrder.sbr" \
	"$(INTDIR)\JDFAction.sbr" \
	"$(INTDIR)\JDFActionPool.sbr" \
	"$(INTDIR)\JDFand.sbr" \
	"$(INTDIR)\JDFBooleanEvaluation.sbr" \
	"$(INTDIR)\JDFBooleanState.sbr" \
	"$(INTDIR)\JDFcall.sbr" \
	"$(INTDIR)\JDFchoice.sbr" \
	"$(INTDIR)\JDFDateTimeEvaluation.sbr" \
	"$(INTDIR)\JDFDateTimeState.sbr" \
	"$(INTDIR)\JDFDevCap.sbr" \
	"$(INTDIR)\JDFDevCaps.sbr" \
	"$(INTDIR)\JDFDeviceCap.sbr" \
	"$(INTDIR)\JDFDisplayGroup.sbr" \
	"$(INTDIR)\JDFDisplayGroupPool.sbr" \
	"$(INTDIR)\JDFDurationEvaluation.sbr" \
	"$(INTDIR)\JDFDurationState.sbr" \
	"$(INTDIR)\JDFEnumerationEvaluation.sbr" \
	"$(INTDIR)\JDFEnumerationState.sbr" \
	"$(INTDIR)\JDFEvaluation.sbr" \
	"$(INTDIR)\JDFFeatureAttribute.sbr" \
	"$(INTDIR)\JDFFeaturePool.sbr" \
	"$(INTDIR)\JDFIntegerEvaluation.sbr" \
	"$(INTDIR)\JDFIntegerState.sbr" \
	"$(INTDIR)\JDFIsPresentEvaluation.sbr" \
	"$(INTDIR)\JDFLoc.sbr" \
	"$(INTDIR)\JDFmacro.sbr" \
	"$(INTDIR)\JDFMacroPool.sbr" \
	"$(INTDIR)\JDFMatrixEvaluation.sbr" \
	"$(INTDIR)\JDFMatrixState.sbr" \
	"$(INTDIR)\JDFNameEvaluation.sbr" \
	"$(INTDIR)\JDFNameState.sbr" \
	"$(INTDIR)\JDFnot.sbr" \
	"$(INTDIR)\JDFNumberEvaluation.sbr" \
	"$(INTDIR)\JDFNumberState.sbr" \
	"$(INTDIR)\JDFor.sbr" \
	"$(INTDIR)\JDFotherwise.sbr" \
	"$(INTDIR)\JDFPDFPathEvaluation.sbr" \
	"$(INTDIR)\JDFPDFPathState.sbr" \
	"$(INTDIR)\JDFPerformance.sbr" \
	"$(INTDIR)\JDFRectangleEvaluation.sbr" \
	"$(INTDIR)\JDFRectangleState.sbr" \
	"$(INTDIR)\JDFset.sbr" \
	"$(INTDIR)\JDFShapeEvaluation.sbr" \
	"$(INTDIR)\JDFShapeState.sbr" \
	"$(INTDIR)\JDFState.sbr" \
	"$(INTDIR)\JDFStringEvaluation.sbr" \
	"$(INTDIR)\JDFStringState.sbr" \
	"$(INTDIR)\JDFTest.sbr" \
	"$(INTDIR)\JDFTestPool.sbr" \
	"$(INTDIR)\JDFTestRef.sbr" \
	"$(INTDIR)\JDFValue.sbr" \
	"$(INTDIR)\JDFValueLoc.sbr" \
	"$(INTDIR)\JDFwhen.sbr" \
	"$(INTDIR)\JDFxor.sbr" \
	"$(INTDIR)\JDFXYPairEvaluation.sbr" \
	"$(INTDIR)\JDFXYPairState.sbr" \
	"$(INTDIR)\JDFDoc.sbr" \
	"$(INTDIR)\JDFElement.sbr" \
	"$(INTDIR)\JDFFactory.sbr" \
	"$(INTDIR)\JDFNodeFactory.sbr" \
	"$(INTDIR)\JDFParamsFactory.sbr" \
	"$(INTDIR)\JDFPool.sbr" \
	"$(INTDIR)\JDFRefElement.sbr" \
	"$(INTDIR)\JDFResource.sbr" \
	"$(INTDIR)\JDFResourceLink.sbr" \
	"$(INTDIR)\JDFRunElement.sbr" \
	"$(INTDIR)\JDFSeparationList.sbr" \
	"$(INTDIR)\JDFStrings.sbr" \
	"$(INTDIR)\JDFAutoAmountPool.sbr" \
	"$(INTDIR)\JDFAutoAncestor.sbr" \
	"$(INTDIR)\JDFAutoAncestorPool.sbr" \
	"$(INTDIR)\JDFAutoBarcode.sbr" \
	"$(INTDIR)\JDFAutoBusinessInfo.sbr" \
	"$(INTDIR)\JDFAutoComment.sbr" \
	"$(INTDIR)\JDFAutoCounterReset.sbr" \
	"$(INTDIR)\JDFAutoCreated.sbr" \
	"$(INTDIR)\JDFAutoCustomerInfo.sbr" \
	"$(INTDIR)\JDFAutoCustomerMessage.sbr" \
	"$(INTDIR)\JDFAutoDeleted.sbr" \
	"$(INTDIR)\JDFAutoError.sbr" \
	"$(INTDIR)\JDFAutoEvent.sbr" \
	"$(INTDIR)\JDFAutoFCNKey.sbr" \
	"$(INTDIR)\JDFAutoLocation.sbr" \
	"$(INTDIR)\JDFAutoMerged.sbr" \
	"$(INTDIR)\JDFAutoModified.sbr" \
	"$(INTDIR)\JDFAutoModulePhase.sbr" \
	"$(INTDIR)\JDFAutoNodeInfo.sbr" \
	"$(INTDIR)\JDFAutoNotification.sbr" \
	"$(INTDIR)\JDFAutoPart.sbr" \
	"$(INTDIR)\JDFAutoPartStatus.sbr" \
	"$(INTDIR)\JDFAutoPhaseTime.sbr" \
	"$(INTDIR)\JDFAutoProcessRun.sbr" \
	"$(INTDIR)\JDFAutoResourceAudit.sbr" \
	"$(INTDIR)\JDFAutoSpawned.sbr" \
	"$(INTDIR)\JDFAutoStatusPool.sbr" \
	"$(INTDIR)\JDFAutoSystemTimeSet.sbr" \
	"$(INTDIR)\JDFAutoAcknowledge.sbr" \
	"$(INTDIR)\JDFAutoAdded.sbr" \
	"$(INTDIR)\JDFAutoChangedAttribute.sbr" \
	"$(INTDIR)\JDFAutoChangedPath.sbr" \
	"$(INTDIR)\JDFAutoCommand.sbr" \
	"$(INTDIR)\JDFAutoDeviceFilter.sbr" \
	"$(INTDIR)\JDFAutoDeviceInfo.sbr" \
	"$(INTDIR)\JDFAutoDeviceList.sbr" \
	"$(INTDIR)\JDFAutoEmployeeDef.sbr" \
	"$(INTDIR)\JDFAutoFlushedResources.sbr" \
	"$(INTDIR)\JDFAutoFlushQueueParams.sbr" \
	"$(INTDIR)\JDFAutoFlushResourceParams.sbr" \
	"$(INTDIR)\JDFAutoIDInfo.sbr" \
	"$(INTDIR)\JDFAutoJDFController.sbr" \
	"$(INTDIR)\JDFAutoJDFService.sbr" \
	"$(INTDIR)\JDFAutoJMF.sbr" \
	"$(INTDIR)\JDFAutoJobPhase.sbr" \
	"$(INTDIR)\JDFAutoKnownMsgQuParams.sbr" \
	"$(INTDIR)\JDFAutoMessage.sbr" \
	"$(INTDIR)\JDFAutoMessageService.sbr" \
	"$(INTDIR)\JDFAutoModuleStatus.sbr" \
	"$(INTDIR)\JDFAutoMsgFilter.sbr" \
	"$(INTDIR)\JDFAutoNewJDFCmdParams.sbr" \
	"$(INTDIR)\JDFAutoNewJDFQuParams.sbr" \
	"$(INTDIR)\JDFAutoNodeInfoCmdParams.sbr" \
	"$(INTDIR)\JDFAutoNodeInfoQuParams.sbr" \
	"$(INTDIR)\JDFAutoNodeInfoResp.sbr" \
	"$(INTDIR)\JDFAutoNotificationDef.sbr" \
	"$(INTDIR)\JDFAutoNotificationFilter.sbr" \
	"$(INTDIR)\JDFAutoObservationTarget.sbr" \
	"$(INTDIR)\JDFAutoOccupation.sbr" \
	"$(INTDIR)\JDFAutoPipeParams.sbr" \
	"$(INTDIR)\JDFAutoQuery.sbr" \
	"$(INTDIR)\JDFAutoQueue.sbr" \
	"$(INTDIR)\JDFAutoQueueEntry.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryDef.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryDefList.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryPosParams.sbr" \
	"$(INTDIR)\JDFAutoQueueEntryPriParams.sbr" \
	"$(INTDIR)\JDFAutoQueueFilter.sbr" \
	"$(INTDIR)\JDFAutoQueueSubmissionParams.sbr" \
	"$(INTDIR)\JDFAutoRemoved.sbr" \
	"$(INTDIR)\JDFAutoRequestQueueEntryParams.sbr" \
	"$(INTDIR)\JDFAutoResourceCmdParams.sbr" \
	"$(INTDIR)\JDFAutoResourceInfo.sbr" \
	"$(INTDIR)\JDFAutoResourcePullParams.sbr" \
	"$(INTDIR)\JDFAutoResourceQuParams.sbr" \
	"$(INTDIR)\JDFAutoResponse.sbr" \
	"$(INTDIR)\JDFAutoResubmissionParams.sbr" \
	"$(INTDIR)\JDFAutoReturnQueueEntryParams.sbr" \
	"$(INTDIR)\JDFAutoShutDownCmdParams.sbr" \
	"$(INTDIR)\JDFAutoSignal.sbr" \
	"$(INTDIR)\JDFAutoStatusQuParams.sbr" \
	"$(INTDIR)\JDFAutoStopPersChParams.sbr" \
	"$(INTDIR)\JDFAutoSubmissionMethods.sbr" \
	"$(INTDIR)\JDFAutoSubscription.sbr" \
	"$(INTDIR)\JDFAutoTrackFilter.sbr" \
	"$(INTDIR)\JDFAutoTrackResult.sbr" \
	"$(INTDIR)\JDFAutoTrigger.sbr" \
	"$(INTDIR)\JDFAutoWakeUpCmdParams.sbr" \
	"$(INTDIR)\JDFAutoArtDeliveryIntent.sbr" \
	"$(INTDIR)\JDFAutoBindingIntent.sbr" \
	"$(INTDIR)\JDFAutoColorIntent.sbr" \
	"$(INTDIR)\JDFAutoDeliveryIntent.sbr" \
	"$(INTDIR)\JDFAutoEmbossingIntent.sbr" \
	"$(INTDIR)\JDFAutoFoldingIntent.sbr" \
	"$(INTDIR)\JDFAutoHoleMakingIntent.sbr" \
	"$(INTDIR)\JDFAutoInsertingIntent.sbr" \
	"$(INTDIR)\JDFAutoLaminatingIntent.sbr" \
	"$(INTDIR)\JDFAutoLayoutIntent.sbr" \
	"$(INTDIR)\JDFAutoMediaIntent.sbr" \
	"$(INTDIR)\JDFAutoNumberingIntent.sbr" \
	"$(INTDIR)\JDFAutoPackingIntent.sbr" \
	"$(INTDIR)\JDFAutoProductionIntent.sbr" \
	"$(INTDIR)\JDFAutoProofingIntent.sbr" \
	"$(INTDIR)\JDFAutoScreeningIntent.sbr" \
	"$(INTDIR)\JDFAutoShapeCuttingIntent.sbr" \
	"$(INTDIR)\JDFAutoSizeIntent.sbr" \
	"$(INTDIR)\JDFAutoAdhesiveBinding.sbr" \
	"$(INTDIR)\JDFAutoArtDelivery.sbr" \
	"$(INTDIR)\JDFAutoBindItem.sbr" \
	"$(INTDIR)\JDFAutoBindList.sbr" \
	"$(INTDIR)\JDFAutoBookCase.sbr" \
	"$(INTDIR)\JDFAutoChannelBinding.sbr" \
	"$(INTDIR)\JDFAutoCoilBinding.sbr" \
	"$(INTDIR)\JDFAutoColorsUsed.sbr" \
	"$(INTDIR)\JDFAutoCreditCard.sbr" \
	"$(INTDIR)\JDFAutoDropIntent.sbr" \
	"$(INTDIR)\JDFAutoDropItemIntent.sbr" \
	"$(INTDIR)\JDFAutoEdgeGluing.sbr" \
	"$(INTDIR)\JDFAutoEmbossingItem.sbr" \
	"$(INTDIR)\JDFAutoHardCoverBinding.sbr" \
	"$(INTDIR)\JDFAutoHoleList.sbr" \
	"$(INTDIR)\JDFAutoInsert.sbr" \
	"$(INTDIR)\JDFAutoInsertList.sbr" \
	"$(INTDIR)\JDFAutoNumberItem.sbr" \
	"$(INTDIR)\JDFAutoPayment.sbr" \
	"$(INTDIR)\JDFAutoPlasticCombBinding.sbr" \
	"$(INTDIR)\JDFAutoPricing.sbr" \
	"$(INTDIR)\JDFAutoProofItem.sbr" \
	"$(INTDIR)\JDFAutoRingBinding.sbr" \
	"$(INTDIR)\JDFAutoSaddleStitching.sbr" \
	"$(INTDIR)\JDFAutoShapeCut.sbr" \
	"$(INTDIR)\JDFAutoSideSewing.sbr" \
	"$(INTDIR)\JDFAutoSideStitching.sbr" \
	"$(INTDIR)\JDFAutoSoftCoverBinding.sbr" \
	"$(INTDIR)\JDFAutoStripBinding.sbr" \
	"$(INTDIR)\JDFAutoTabs.sbr" \
	"$(INTDIR)\JDFAutoTape.sbr" \
	"$(INTDIR)\JDFAutoThreadSealing.sbr" \
	"$(INTDIR)\JDFAutoThreadSewing.sbr" \
	"$(INTDIR)\JDFAutoWireCombBinding.sbr" \
	"$(INTDIR)\JDFAutoAddress.sbr" \
	"$(INTDIR)\JDFAutoAdhesiveBindingParams.sbr" \
	"$(INTDIR)\JDFAutoApprovalParams.sbr" \
	"$(INTDIR)\JDFAutoApprovalSuccess.sbr" \
	"$(INTDIR)\JDFAutoAssembly.sbr" \
	"$(INTDIR)\JDFAutoAssetListCreationParams.sbr" \
	"$(INTDIR)\JDFAutoAutomatedOverprintParams.sbr" \
	"$(INTDIR)\JDFAutoBinderySignature.sbr" \
	"$(INTDIR)\JDFAutoBlockPreparationParams.sbr" \
	"$(INTDIR)\JDFAutoBoxPackingParams.sbr" \
	"$(INTDIR)\JDFAutoBufferParams.sbr" \
	"$(INTDIR)\JDFAutoBundle.sbr" \
	"$(INTDIR)\JDFAutoBundlingParams.sbr" \
	"$(INTDIR)\JDFAutoByteMap.sbr" \
	"$(INTDIR)\JDFAutoCaseMakingParams.sbr" \
	"$(INTDIR)\JDFAutoCasingInParams.sbr" \
	"$(INTDIR)\JDFAutoChannelBindingParams.sbr" \
	"$(INTDIR)\JDFAutoCIELABMeasuringField.sbr" \
	"$(INTDIR)\JDFAutoCoilBindingParams.sbr" \
	"$(INTDIR)\JDFAutoCollectingParams.sbr" \
	"$(INTDIR)\JDFAutoColor.sbr" \
	"$(INTDIR)\JDFAutoColorantAlias.sbr" \
	"$(INTDIR)\JDFAutoColorantControl.sbr" \
	"$(INTDIR)\JDFAutoColorControlStrip.sbr" \
	"$(INTDIR)\JDFAutoColorCorrectionParams.sbr" \
	"$(INTDIR)\JDFAutoColorMeasurementConditions.sbr" \
	"$(INTDIR)\JDFAutoColorPool.sbr" \
	"$(INTDIR)\JDFAutoColorSpaceConversionOp.sbr" \
	"$(INTDIR)\JDFAutoColorSpaceConversionParams.sbr" \
	"$(INTDIR)\JDFAutoComChannel.sbr" \
	"$(INTDIR)\JDFAutoCompany.sbr" \
	"$(INTDIR)\JDFAutoComponent.sbr" \
	"$(INTDIR)\JDFAutoContact.sbr" \
	"$(INTDIR)\JDFAutoContactCopyParams.sbr" \
	"$(INTDIR)\JDFAutoConventionalPrintingParams.sbr" \
	"$(INTDIR)\JDFAutoCostCenter.sbr" \
	"$(INTDIR)\JDFAutoCoverApplicationParams.sbr" \
	"$(INTDIR)\JDFAutoCreasingParams.sbr" \
	"$(INTDIR)\JDFAutoCutBlock.sbr" \
	"$(INTDIR)\JDFAutoCutMark.sbr" \
	"$(INTDIR)\JDFAutoCuttingParams.sbr" \
	"$(INTDIR)\JDFAutoDBMergeParams.sbr" \
	"$(INTDIR)\JDFAutoDBRules.sbr" \
	"$(INTDIR)\JDFAutoDBSchema.sbr" \
	"$(INTDIR)\JDFAutoDBSelection.sbr" \
	"$(INTDIR)\JDFAutoDeliveryParams.sbr" \
	"$(INTDIR)\JDFAutoDensityMeasuringField.sbr" \
	"$(INTDIR)\JDFAutoDevelopingParams.sbr" \
	"$(INTDIR)\JDFAutoDevice.sbr" \
	"$(INTDIR)\JDFAutoDeviceMark.sbr" \
	"$(INTDIR)\JDFAutoDeviceNSpace.sbr" \
	"$(INTDIR)\JDFAutoDigitalDeliveryParams.sbr" \
	"$(INTDIR)\JDFAutoDigitalMedia.sbr" \
	"$(INTDIR)\JDFAutoDigitalPrintingParams.sbr" \
	"$(INTDIR)\JDFAutoDisjointing.sbr" \
	"$(INTDIR)\JDFAutoDisposition.sbr" \
	"$(INTDIR)\JDFAutoDividingParams.sbr" \
	"$(INTDIR)\JDFAutoElementColorParams.sbr" \
	"$(INTDIR)\JDFAutoEmbossingParams.sbr" \
	"$(INTDIR)\JDFAutoEmployee.sbr" \
	"$(INTDIR)\JDFAutoEndSheetGluingParams.sbr" \
	"$(INTDIR)\JDFAutoExposedMedia.sbr" \
	"$(INTDIR)\JDFAutoFeedingParams.sbr" \
	"$(INTDIR)\JDFAutoFileSpec.sbr" \
	"$(INTDIR)\JDFAutoFitPolicy.sbr" \
	"$(INTDIR)\JDFAutoFold.sbr" \
	"$(INTDIR)\JDFAutoFoldingParams.sbr" \
	"$(INTDIR)\JDFAutoFontParams.sbr" \
	"$(INTDIR)\JDFAutoFontPolicy.sbr" \
	"$(INTDIR)\JDFAutoFormatConversionParams.sbr" \
	"$(INTDIR)\JDFAutoGatheringParams.sbr" \
	"$(INTDIR)\JDFAutoGlueApplication.sbr" \
	"$(INTDIR)\JDFAutoGlueLine.sbr" \
	"$(INTDIR)\JDFAutoGluingParams.sbr" \
	"$(INTDIR)\JDFAutoHeadBandApplicationParams.sbr" \
	"$(INTDIR)\JDFAutoHole.sbr" \
	"$(INTDIR)\JDFAutoHoleLine.sbr" \
	"$(INTDIR)\JDFAutoHoleMakingParams.sbr" \
	"$(INTDIR)\JDFAutoIdentificationField.sbr" \
	"$(INTDIR)\JDFAutoIDPrintingParams.sbr" \
	"$(INTDIR)\JDFAutoImageCompressionParams.sbr" \
	"$(INTDIR)\JDFAutoImageReplacementParams.sbr" \
	"$(INTDIR)\JDFAutoImageSetterParams.sbr" \
	"$(INTDIR)\JDFAutoInk.sbr" \
	"$(INTDIR)\JDFAutoInkZoneCalculationParams.sbr" \
	"$(INTDIR)\JDFAutoInkZoneProfile.sbr" \
	"$(INTDIR)\JDFAutoInsertingParams.sbr" \
	"$(INTDIR)\JDFAutoInsertSheet.sbr" \
	"$(INTDIR)\JDFAutoInterpretedPDLData.sbr" \
	"$(INTDIR)\JDFAutoInterpretingParams.sbr" \
	"$(INTDIR)\JDFAutoJacketingParams.sbr" \
	"$(INTDIR)\JDFAutoJobField.sbr" \
	"$(INTDIR)\JDFAutoLabelingParams.sbr" \
	"$(INTDIR)\JDFAutoLaminatingParams.sbr" \
	"$(INTDIR)\JDFAutoLayout.sbr" \
	"$(INTDIR)\JDFAutoLayoutElement.sbr" \
	"$(INTDIR)\JDFAutoLayoutPreparationParams.sbr" \
	"$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.sbr" \
	"$(INTDIR)\JDFAutoManualLaborParams.sbr" \
	"$(INTDIR)\JDFAutoMedia.sbr" \
	"$(INTDIR)\JDFAutoMediaSource.sbr" \
	"$(INTDIR)\JDFAutoMISDetails.sbr" \
	"$(INTDIR)\JDFAutoNumberingParams.sbr" \
	"$(INTDIR)\JDFAutoObjectResolution.sbr" \
	"$(INTDIR)\JDFAutoOrderingParams.sbr" \
	"$(INTDIR)\JDFAutoPackingParams.sbr" \
	"$(INTDIR)\JDFAutoPageList.sbr" \
	"$(INTDIR)\JDFAutoPallet.sbr" \
	"$(INTDIR)\JDFAutoPalletizingParams.sbr" \
	"$(INTDIR)\JDFAutoPDFToPSConversionParams.sbr" \
	"$(INTDIR)\JDFAutoPDLResourceAlias.sbr" \
	"$(INTDIR)\JDFAutoPerforatingParams.sbr" \
	"$(INTDIR)\JDFAutoPerson.sbr" \
	"$(INTDIR)\JDFAutoPlaceHolderResource.sbr" \
	"$(INTDIR)\JDFAutoPlasticCombBindingParams.sbr" \
	"$(INTDIR)\JDFAutoPlateCopyParams.sbr" \
	"$(INTDIR)\JDFAutoPreflightAnalysis.sbr" \
	"$(INTDIR)\JDFAutoPreflightInventory.sbr" \
	"$(INTDIR)\JDFAutoPreflightParams.sbr" \
	"$(INTDIR)\JDFAutoPreflightProfile.sbr" \
	"$(INTDIR)\JDFAutoPreflightReport.sbr" \
	"$(INTDIR)\JDFAutoPreflightReportRulePool.sbr" \
	"$(INTDIR)\JDFAutoPreview.sbr" \
	"$(INTDIR)\JDFAutoPreviewGenerationParams.sbr" \
	"$(INTDIR)\JDFAutoPrintCondition.sbr" \
	"$(INTDIR)\JDFAutoPrintRollingParams.sbr" \
	"$(INTDIR)\JDFAutoProofingParams.sbr" \
	"$(INTDIR)\JDFAutoPSToPDFConversionParams.sbr" \
	"$(INTDIR)\JDFAutoQualityControlParams.sbr" \
	"$(INTDIR)\JDFAutoQualityControlResult.sbr" \
	"$(INTDIR)\JDFAutoRegisterMark.sbr" \
	"$(INTDIR)\JDFAutoRegisterRibbon.sbr" \
	"$(INTDIR)\JDFAutoRenderingParams.sbr" \
	"$(INTDIR)\JDFAutoResourceDefinitionParams.sbr" \
	"$(INTDIR)\JDFAutoRingBindingParams.sbr" \
	"$(INTDIR)\JDFAutoRollStand.sbr" \
	"$(INTDIR)\JDFAutoRunList.sbr" \
	"$(INTDIR)\JDFAutoSaddleStitchingParams.sbr" \
	"$(INTDIR)\JDFAutoScanParams.sbr" \
	"$(INTDIR)\JDFAutoScavengerArea.sbr" \
	"$(INTDIR)\JDFAutoScreeningParams.sbr" \
	"$(INTDIR)\JDFAutoSeparationControlParams.sbr" \
	"$(INTDIR)\JDFAutoSeparationSpec.sbr" \
	"$(INTDIR)\JDFAutoShapeCuttingParams.sbr" \
	"$(INTDIR)\JDFAutoSheet.sbr" \
	"$(INTDIR)\JDFAutoShrinkingParams.sbr" \
	"$(INTDIR)\JDFAutoSideSewingParams.sbr" \
	"$(INTDIR)\JDFAutoSpinePreparationParams.sbr" \
	"$(INTDIR)\JDFAutoSpineTapingParams.sbr" \
	"$(INTDIR)\JDFAutoStackingParams.sbr" \
	"$(INTDIR)\JDFAutoStitchingParams.sbr" \
	"$(INTDIR)\JDFAutoStrap.sbr" \
	"$(INTDIR)\JDFAutoStrappingParams.sbr" \
	"$(INTDIR)\JDFAutoStripBindingParams.sbr" \
	"$(INTDIR)\JDFAutoStrippingParams.sbr" \
	"$(INTDIR)\JDFAutoSurface.sbr" \
	"$(INTDIR)\JDFAutoThreadSealingParams.sbr" \
	"$(INTDIR)\JDFAutoThreadSewingParams.sbr" \
	"$(INTDIR)\JDFAutoTile.sbr" \
	"$(INTDIR)\JDFAutoTool.sbr" \
	"$(INTDIR)\JDFAutoTransferCurve.sbr" \
	"$(INTDIR)\JDFAutoTransferCurvePool.sbr" \
	"$(INTDIR)\JDFAutoTransferFunctionControl.sbr" \
	"$(INTDIR)\JDFAutoTrappingDetails.sbr" \
	"$(INTDIR)\JDFAutoTrappingParams.sbr" \
	"$(INTDIR)\JDFAutoTrapRegion.sbr" \
	"$(INTDIR)\JDFAutoTrimmingParams.sbr" \
	"$(INTDIR)\JDFAutoVerificationParams.sbr" \
	"$(INTDIR)\JDFAutoWireCombBindingParams.sbr" \
	"$(INTDIR)\JDFAutoWrappingParams.sbr" \
	"$(INTDIR)\JDFArgumentValue.sbr" \
	"$(INTDIR)\JDFAutoAdvancedParams.sbr" \
	"$(INTDIR)\JDFAutoApprovalPerson.sbr" \
	"$(INTDIR)\JDFAutoArgumentValue.sbr" \
	"$(INTDIR)\JDFAutoAssemblySection.sbr" \
	"$(INTDIR)\JDFAutoBand.sbr" \
	"$(INTDIR)\JDFAutoBasicPreflightTest.sbr" \
	"$(INTDIR)\JDFAutoBindingQualityParams.sbr" \
	"$(INTDIR)\JDFAutoBoxArgument.sbr" \
	"$(INTDIR)\JDFAutoBoxToBoxDifference.sbr" \
	"$(INTDIR)\JDFAutoBundleItem.sbr" \
	"$(INTDIR)\JDFAutoCCITTFaxParams.sbr" \
	"$(INTDIR)\JDFAutoCollatingItem.sbr" \
	"$(INTDIR)\JDFAutoColorantZoneDetails.sbr" \
	"$(INTDIR)\JDFAutoColorCorrectionOp.sbr" \
	"$(INTDIR)\JDFAutoColorSpaceSubstitute.sbr" \
	"$(INTDIR)\JDFAutoContainer.sbr" \
	"$(INTDIR)\JDFAutoContentObject.sbr" \
	"$(INTDIR)\JDFAutoCrease.sbr" \
	"$(INTDIR)\JDFAutoCut.sbr" \
	"$(INTDIR)\JDFAutoDCTParams.sbr" \
	"$(INTDIR)\JDFAutoDependencies.sbr" \
	"$(INTDIR)\JDFAutoDeviceNColor.sbr" \
	"$(INTDIR)\JDFAutoDrop.sbr" \
	"$(INTDIR)\JDFAutoDropItem.sbr" \
	"$(INTDIR)\JDFAutoDynamicField.sbr" \
	"$(INTDIR)\JDFAutoDynamicInput.sbr" \
	"$(INTDIR)\JDFAutoEmboss.sbr" \
	"$(INTDIR)\JDFAutoEndSheet.sbr" \
	"$(INTDIR)\JDFAutoFeeder.sbr" \
	"$(INTDIR)\JDFAutoFeederQualityParams.sbr" \
	"$(INTDIR)\JDFAutoFileAlias.sbr" \
	"$(INTDIR)\JDFAutoFlateParams.sbr" \
	"$(INTDIR)\JDFAutoGlue.sbr" \
	"$(INTDIR)\JDFAutoIcon.sbr" \
	"$(INTDIR)\JDFAutoIconList.sbr" \
	"$(INTDIR)\JDFAutoIDPCover.sbr" \
	"$(INTDIR)\JDFAutoIDPFinishing.sbr" \
	"$(INTDIR)\JDFAutoIDPFolding.sbr" \
	"$(INTDIR)\JDFAutoIDPHoleMaking.sbr" \
	"$(INTDIR)\JDFAutoIDPImageShift.sbr" \
	"$(INTDIR)\JDFAutoIDPJobSheet.sbr" \
	"$(INTDIR)\JDFAutoIDPLayout.sbr" \
	"$(INTDIR)\JDFAutoIDPStitching.sbr" \
	"$(INTDIR)\JDFAutoIDPTrimming.sbr" \
	"$(INTDIR)\JDFAutoImageCompression.sbr" \
	"$(INTDIR)\JDFAutoImageShift.sbr" \
	"$(INTDIR)\JDFAutoLayerDetails.sbr" \
	"$(INTDIR)\JDFAutoLayerList.sbr" \
	"$(INTDIR)\JDFAutoLongFold.sbr" \
	"$(INTDIR)\JDFAutoLongGlue.sbr" \
	"$(INTDIR)\JDFAutoLongPerforate.sbr" \
	"$(INTDIR)\JDFAutoLongSlit.sbr" \
	"$(INTDIR)\JDFAutoLZWParams.sbr" \
	"$(INTDIR)\JDFAutoMarkObject.sbr" \
	"$(INTDIR)\JDFAutoNumberingParam.sbr" \
	"$(INTDIR)\JDFAutoPageCell.sbr" \
	"$(INTDIR)\JDFAutoPageData.sbr" \
	"$(INTDIR)\JDFAutoPDFInterpretingParams.sbr" \
	"$(INTDIR)\JDFAutoPDFXParams.sbr" \
	"$(INTDIR)\JDFAutoPerforate.sbr" \
	"$(INTDIR)\JDFAutoPixelColorant.sbr" \
	"$(INTDIR)\JDFAutoPosition.sbr" \
	"$(INTDIR)\JDFAutoPreflightAction.sbr" \
	"$(INTDIR)\JDFAutoPreflightArgument.sbr" \
	"$(INTDIR)\JDFAutoPreflightConstraint.sbr" \
	"$(INTDIR)\JDFAutoPreflightDetail.sbr" \
	"$(INTDIR)\JDFAutoPreflightInstance.sbr" \
	"$(INTDIR)\JDFAutoPreflightInstanceDetail.sbr" \
	"$(INTDIR)\JDFAutoPreflightValue.sbr" \
	"$(INTDIR)\JDFAutoPRError.sbr" \
	"$(INTDIR)\JDFAutoPRGroup.sbr" \
	"$(INTDIR)\JDFAutoPrintConditionColor.sbr" \
	"$(INTDIR)\JDFAutoPRItem.sbr" \
	"$(INTDIR)\JDFAutoPROccurence.sbr" \
	"$(INTDIR)\JDFAutoProperties.sbr" \
	"$(INTDIR)\JDFAutoPRRule.sbr" \
	"$(INTDIR)\JDFAutoPRRuleAttr.sbr" \
	"$(INTDIR)\JDFAutoQualityMeasurement.sbr" \
	"$(INTDIR)\JDFAutoResourceParam.sbr" \
	"$(INTDIR)\JDFAutoScore.sbr" \
	"$(INTDIR)\JDFAutoScreenSelector.sbr" \
	"$(INTDIR)\JDFAutoShapeElement.sbr" \
	"$(INTDIR)\JDFAutoSignature.sbr" \
	"$(INTDIR)\JDFAutoSignatureCell.sbr" \
	"$(INTDIR)\JDFAutoStringListValue.sbr" \
	"$(INTDIR)\JDFAutoStripCellParams.sbr" \
	"$(INTDIR)\JDFAutoThinPDFParams.sbr" \
	"$(INTDIR)\JDFAutoTIFFEmbeddedFile.sbr" \
	"$(INTDIR)\JDFAutoTIFFFormatParams.sbr" \
	"$(INTDIR)\JDFAutoTIFFtag.sbr" \
	"$(INTDIR)\JDFAutoTransferCurveSet.sbr" \
	"$(INTDIR)\JDFAutoTrappingOrder.sbr" \
	"$(INTDIR)\JDFAutoAction.sbr" \
	"$(INTDIR)\JDFAutoActionPool.sbr" \
	"$(INTDIR)\JDFAutoand.sbr" \
	"$(INTDIR)\JDFAutocall.sbr" \
	"$(INTDIR)\JDFAutochoice.sbr" \
	"$(INTDIR)\JDFAutoDevCap.sbr" \
	"$(INTDIR)\JDFAutoDevCaps.sbr" \
	"$(INTDIR)\JDFAutoDeviceCap.sbr" \
	"$(INTDIR)\JDFAutoDisplayGroup.sbr" \
	"$(INTDIR)\JDFAutoDisplayGroupPool.sbr" \
	"$(INTDIR)\JDFAutoFeatureAttribute.sbr" \
	"$(INTDIR)\JDFAutoFeaturePool.sbr" \
	"$(INTDIR)\JDFAutoLoc.sbr" \
	"$(INTDIR)\JDFAutomacro.sbr" \
	"$(INTDIR)\JDFAutoMacroPool.sbr" \
	"$(INTDIR)\JDFAutonot.sbr" \
	"$(INTDIR)\JDFAutoor.sbr" \
	"$(INTDIR)\JDFAutootherwise.sbr" \
	"$(INTDIR)\JDFAutoPerformance.sbr" \
	"$(INTDIR)\JDFAutoset.sbr" \
	"$(INTDIR)\JDFAutoTest.sbr" \
	"$(INTDIR)\JDFAutoTestPool.sbr" \
	"$(INTDIR)\JDFAutoTestRef.sbr" \
	"$(INTDIR)\JDFAutoValue.sbr" \
	"$(INTDIR)\JDFAutoValueLoc.sbr" \
	"$(INTDIR)\JDFAutowhen.sbr" \
	"$(INTDIR)\JDFAutoxor.sbr" \
	"$(INTDIR)\JDFAutoEnumerationSpan.sbr" \
	"$(INTDIR)\JDFAutoPRGroupOccurence.sbr" \
	"$(INTDIR)\JDFAutoPRGroupOccurenceBase.sbr" \
	"$(INTDIR)\JDFPreflightConstraintsPool.sbr" \
	"$(INTDIR)\JDFPreflightResultsPool.sbr" \
	"$(INTDIR)\JDFPRGroupOccurence.sbr" \
	"$(INTDIR)\JDFPRGroupOccurenceBase.sbr" \
	"$(INTDIR)\JDFDateTimeRange.sbr" \
	"$(INTDIR)\JDFDateTimeRangeList.sbr" \
	"$(INTDIR)\JDFDurationRange.sbr" \
	"$(INTDIR)\JDFDurationRangeList.sbr" \
	"$(INTDIR)\JDFIntegerRange.sbr" \
	"$(INTDIR)\JDFIntegerRangeList.sbr" \
	"$(INTDIR)\JDFNameRangeList.sbr" \
	"$(INTDIR)\JDFNumberRangeList.sbr" \
	"$(INTDIR)\JDFNumTypeList.sbr" \
	"$(INTDIR)\JDFParser.sbr" \
	"$(INTDIR)\JDFRange.sbr" \
	"$(INTDIR)\JDFRangeList.sbr" \
	"$(INTDIR)\JDFXYPairRangeList.sbr" \
	"$(INTDIR)\KElement.sbr" \
	"$(INTDIR)\KElementStrings.sbr" \
	"$(INTDIR)\MyDate.sbr" \
	"$(INTDIR)\vElement.sbr" \
	"$(INTDIR)\XMLDoc.sbr" \
	"$(INTDIR)\XMLDocUserData.sbr"

"$(OUTDIR)\JDFWrapperLib.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=xilink6.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\JDFWrapperLib_D.lib" 
LIB32_OBJS= \
	"$(INTDIR)\JDFAmountPool.obj" \
	"$(INTDIR)\JDFAncestor.obj" \
	"$(INTDIR)\JDFAncestorPool.obj" \
	"$(INTDIR)\JDFAudit.obj" \
	"$(INTDIR)\JDFAuditPool.obj" \
	"$(INTDIR)\JDFBarcode.obj" \
	"$(INTDIR)\JDFBusinessInfo.obj" \
	"$(INTDIR)\JDFComment.obj" \
	"$(INTDIR)\JDFCounterReset.obj" \
	"$(INTDIR)\JDFCreated.obj" \
	"$(INTDIR)\JDFCustomerInfo.obj" \
	"$(INTDIR)\JDFCustomerMessage.obj" \
	"$(INTDIR)\JDFDeleted.obj" \
	"$(INTDIR)\JDFError.obj" \
	"$(INTDIR)\JDFEvent.obj" \
	"$(INTDIR)\JDFFCNKey.obj" \
	"$(INTDIR)\JDFLocation.obj" \
	"$(INTDIR)\JDFMerged.obj" \
	"$(INTDIR)\JDFModified.obj" \
	"$(INTDIR)\JDFModulePhase.obj" \
	"$(INTDIR)\JDFNode.obj" \
	"$(INTDIR)\JDFNodeInfo.obj" \
	"$(INTDIR)\JDFNotification.obj" \
	"$(INTDIR)\JDFPart.obj" \
	"$(INTDIR)\JDFPartAmount.obj" \
	"$(INTDIR)\JDFPartStatus.obj" \
	"$(INTDIR)\JDFPhaseTime.obj" \
	"$(INTDIR)\JDFProcessRun.obj" \
	"$(INTDIR)\JDFResourceAudit.obj" \
	"$(INTDIR)\JDFResourceLinkPool.obj" \
	"$(INTDIR)\JDFResourcePool.obj" \
	"$(INTDIR)\JDFSpawned.obj" \
	"$(INTDIR)\JDFStatusPool.obj" \
	"$(INTDIR)\JDFSystemTimeSet.obj" \
	"$(INTDIR)\JDFAcknowledge.obj" \
	"$(INTDIR)\JDFAdded.obj" \
	"$(INTDIR)\JDFChangedAttribute.obj" \
	"$(INTDIR)\JDFChangedPath.obj" \
	"$(INTDIR)\JDFCommand.obj" \
	"$(INTDIR)\JDFDeviceFilter.obj" \
	"$(INTDIR)\JDFDeviceInfo.obj" \
	"$(INTDIR)\JDFDeviceList.obj" \
	"$(INTDIR)\JDFEmployeeDef.obj" \
	"$(INTDIR)\JDFFlushedResources.obj" \
	"$(INTDIR)\JDFFlushQueueParams.obj" \
	"$(INTDIR)\JDFFlushResourceParams.obj" \
	"$(INTDIR)\JDFIDInfo.obj" \
	"$(INTDIR)\JDFJDFController.obj" \
	"$(INTDIR)\JDFJDFService.obj" \
	"$(INTDIR)\JDFJMF.obj" \
	"$(INTDIR)\JDFJobPhase.obj" \
	"$(INTDIR)\JDFKnownMsgQuParams.obj" \
	"$(INTDIR)\JDFMessage.obj" \
	"$(INTDIR)\JDFMessageElement.obj" \
	"$(INTDIR)\JDFMessageService.obj" \
	"$(INTDIR)\JDFModuleStatus.obj" \
	"$(INTDIR)\JDFMsgFilter.obj" \
	"$(INTDIR)\JDFNewJDFCmdParams.obj" \
	"$(INTDIR)\JDFNewJDFQuParams.obj" \
	"$(INTDIR)\JDFNodeInfoCmdParams.obj" \
	"$(INTDIR)\JDFNodeInfoQuParams.obj" \
	"$(INTDIR)\JDFNodeInfoResp.obj" \
	"$(INTDIR)\JDFNotificationDef.obj" \
	"$(INTDIR)\JDFNotificationFilter.obj" \
	"$(INTDIR)\JDFObservationTarget.obj" \
	"$(INTDIR)\JDFOccupation.obj" \
	"$(INTDIR)\JDFPipeParams.obj" \
	"$(INTDIR)\JDFQuery.obj" \
	"$(INTDIR)\JDFQueue.obj" \
	"$(INTDIR)\JDFQueueEntry.obj" \
	"$(INTDIR)\JDFQueueEntryDef.obj" \
	"$(INTDIR)\JDFQueueEntryDefList.obj" \
	"$(INTDIR)\JDFQueueEntryPosParams.obj" \
	"$(INTDIR)\JDFQueueEntryPriParams.obj" \
	"$(INTDIR)\JDFQueueFilter.obj" \
	"$(INTDIR)\JDFQueueSubmissionParams.obj" \
	"$(INTDIR)\JDFRemoved.obj" \
	"$(INTDIR)\JDFRequestQueueEntryParams.obj" \
	"$(INTDIR)\JDFResourceCmdParams.obj" \
	"$(INTDIR)\JDFResourceInfo.obj" \
	"$(INTDIR)\JDFResourcePullParams.obj" \
	"$(INTDIR)\JDFResourceQuParams.obj" \
	"$(INTDIR)\JDFResponse.obj" \
	"$(INTDIR)\JDFResubmissionParams.obj" \
	"$(INTDIR)\JDFReturnQueueEntryParams.obj" \
	"$(INTDIR)\JDFShutDownCmdParams.obj" \
	"$(INTDIR)\JDFSignal.obj" \
	"$(INTDIR)\JDFStatusQuParams.obj" \
	"$(INTDIR)\JDFStopPersChParams.obj" \
	"$(INTDIR)\JDFSubmissionMethods.obj" \
	"$(INTDIR)\JDFSubscription.obj" \
	"$(INTDIR)\JDFTrackFilter.obj" \
	"$(INTDIR)\JDFTrackResult.obj" \
	"$(INTDIR)\JDFTrigger.obj" \
	"$(INTDIR)\JDFWakeUpCmdParams.obj" \
	"$(INTDIR)\JDFArtDeliveryIntent.obj" \
	"$(INTDIR)\JDFBindingIntent.obj" \
	"$(INTDIR)\JDFColorIntent.obj" \
	"$(INTDIR)\JDFDeliveryIntent.obj" \
	"$(INTDIR)\JDFEmbossingIntent.obj" \
	"$(INTDIR)\JDFFoldingIntent.obj" \
	"$(INTDIR)\JDFHoleMakingIntent.obj" \
	"$(INTDIR)\JDFInsertingIntent.obj" \
	"$(INTDIR)\JDFIntentResource.obj" \
	"$(INTDIR)\JDFLaminatingIntent.obj" \
	"$(INTDIR)\JDFLayoutIntent.obj" \
	"$(INTDIR)\JDFMediaIntent.obj" \
	"$(INTDIR)\JDFNumberingIntent.obj" \
	"$(INTDIR)\JDFPackingIntent.obj" \
	"$(INTDIR)\JDFProductionIntent.obj" \
	"$(INTDIR)\JDFProofingIntent.obj" \
	"$(INTDIR)\JDFScreeningIntent.obj" \
	"$(INTDIR)\JDFShapeCuttingIntent.obj" \
	"$(INTDIR)\JDFSizeIntent.obj" \
	"$(INTDIR)\JDFSpan.obj" \
	"$(INTDIR)\JDFAdhesiveBinding.obj" \
	"$(INTDIR)\JDFArtDelivery.obj" \
	"$(INTDIR)\JDFBindItem.obj" \
	"$(INTDIR)\JDFBindList.obj" \
	"$(INTDIR)\JDFBookCase.obj" \
	"$(INTDIR)\JDFChannelBinding.obj" \
	"$(INTDIR)\JDFCoilBinding.obj" \
	"$(INTDIR)\JDFColorsUsed.obj" \
	"$(INTDIR)\JDFCreditCard.obj" \
	"$(INTDIR)\JDFDropIntent.obj" \
	"$(INTDIR)\JDFDropItemIntent.obj" \
	"$(INTDIR)\JDFEdgeGluing.obj" \
	"$(INTDIR)\JDFEmbossingItem.obj" \
	"$(INTDIR)\JDFHardCoverBinding.obj" \
	"$(INTDIR)\JDFHoleList.obj" \
	"$(INTDIR)\JDFInsert.obj" \
	"$(INTDIR)\JDFInsertList.obj" \
	"$(INTDIR)\JDFNumberItem.obj" \
	"$(INTDIR)\JDFPayment.obj" \
	"$(INTDIR)\JDFPlasticCombBinding.obj" \
	"$(INTDIR)\JDFPricing.obj" \
	"$(INTDIR)\JDFProofItem.obj" \
	"$(INTDIR)\JDFRingBinding.obj" \
	"$(INTDIR)\JDFSaddleStitching.obj" \
	"$(INTDIR)\JDFShapeCut.obj" \
	"$(INTDIR)\JDFSideSewing.obj" \
	"$(INTDIR)\JDFSideStitching.obj" \
	"$(INTDIR)\JDFSoftCoverBinding.obj" \
	"$(INTDIR)\JDFStripBinding.obj" \
	"$(INTDIR)\JDFTabs.obj" \
	"$(INTDIR)\JDFTape.obj" \
	"$(INTDIR)\JDFThreadSealing.obj" \
	"$(INTDIR)\JDFThreadSewing.obj" \
	"$(INTDIR)\JDFWireCombBinding.obj" \
	"$(INTDIR)\JDFAddress.obj" \
	"$(INTDIR)\JDFAdhesiveBindingParams.obj" \
	"$(INTDIR)\JDFApprovalParams.obj" \
	"$(INTDIR)\JDFApprovalSuccess.obj" \
	"$(INTDIR)\JDFAssembly.obj" \
	"$(INTDIR)\JDFAssetListCreationParams.obj" \
	"$(INTDIR)\JDFAutomatedOverprintParams.obj" \
	"$(INTDIR)\JDFBinderySignature.obj" \
	"$(INTDIR)\JDFBlockPreparationParams.obj" \
	"$(INTDIR)\JDFBoxPackingParams.obj" \
	"$(INTDIR)\JDFBufferParams.obj" \
	"$(INTDIR)\JDFBundle.obj" \
	"$(INTDIR)\JDFBundlingParams.obj" \
	"$(INTDIR)\JDFByteMap.obj" \
	"$(INTDIR)\JDFCaseMakingParams.obj" \
	"$(INTDIR)\JDFCasingInParams.obj" \
	"$(INTDIR)\JDFChannelBindingParams.obj" \
	"$(INTDIR)\JDFCIELABMeasuringField.obj" \
	"$(INTDIR)\JDFCoilBindingParams.obj" \
	"$(INTDIR)\JDFCollectingParams.obj" \
	"$(INTDIR)\JDFColor.obj" \
	"$(INTDIR)\JDFColorantAlias.obj" \
	"$(INTDIR)\JDFColorantControl.obj" \
	"$(INTDIR)\JDFColorControlStrip.obj" \
	"$(INTDIR)\JDFColorCorrectionParams.obj" \
	"$(INTDIR)\JDFColorMeasurementConditions.obj" \
	"$(INTDIR)\JDFColorPool.obj" \
	"$(INTDIR)\JDFColorSpaceConversionOp.obj" \
	"$(INTDIR)\JDFColorSpaceConversionParams.obj" \
	"$(INTDIR)\JDFComChannel.obj" \
	"$(INTDIR)\JDFCompany.obj" \
	"$(INTDIR)\JDFComponent.obj" \
	"$(INTDIR)\JDFContact.obj" \
	"$(INTDIR)\JDFContactCopyParams.obj" \
	"$(INTDIR)\JDFConventionalPrintingParams.obj" \
	"$(INTDIR)\JDFCostCenter.obj" \
	"$(INTDIR)\JDFCoverApplicationParams.obj" \
	"$(INTDIR)\JDFCreasingParams.obj" \
	"$(INTDIR)\JDFCutBlock.obj" \
	"$(INTDIR)\JDFCutMark.obj" \
	"$(INTDIR)\JDFCuttingParams.obj" \
	"$(INTDIR)\JDFDBMergeParams.obj" \
	"$(INTDIR)\JDFDBRules.obj" \
	"$(INTDIR)\JDFDBSchema.obj" \
	"$(INTDIR)\JDFDBSelection.obj" \
	"$(INTDIR)\JDFDeliveryParams.obj" \
	"$(INTDIR)\JDFDensityMeasuringField.obj" \
	"$(INTDIR)\JDFDevelopingParams.obj" \
	"$(INTDIR)\JDFDevice.obj" \
	"$(INTDIR)\JDFDeviceMark.obj" \
	"$(INTDIR)\JDFDeviceNSpace.obj" \
	"$(INTDIR)\JDFDigitalDeliveryParams.obj" \
	"$(INTDIR)\JDFDigitalMedia.obj" \
	"$(INTDIR)\JDFDigitalPrintingParams.obj" \
	"$(INTDIR)\JDFDisjointing.obj" \
	"$(INTDIR)\JDFDisposition.obj" \
	"$(INTDIR)\JDFDividingParams.obj" \
	"$(INTDIR)\JDFElementColorParams.obj" \
	"$(INTDIR)\JDFEmbossingParams.obj" \
	"$(INTDIR)\JDFEmployee.obj" \
	"$(INTDIR)\JDFEndSheetGluingParams.obj" \
	"$(INTDIR)\JDFExposedMedia.obj" \
	"$(INTDIR)\JDFFeedingParams.obj" \
	"$(INTDIR)\JDFFileSpec.obj" \
	"$(INTDIR)\JDFFitPolicy.obj" \
	"$(INTDIR)\JDFFold.obj" \
	"$(INTDIR)\JDFFoldingParams.obj" \
	"$(INTDIR)\JDFFontParams.obj" \
	"$(INTDIR)\JDFFontPolicy.obj" \
	"$(INTDIR)\JDFFormatConversionParams.obj" \
	"$(INTDIR)\JDFGatheringParams.obj" \
	"$(INTDIR)\JDFGlueApplication.obj" \
	"$(INTDIR)\JDFGlueLine.obj" \
	"$(INTDIR)\JDFGluingParams.obj" \
	"$(INTDIR)\JDFHeadBandApplicationParams.obj" \
	"$(INTDIR)\JDFHole.obj" \
	"$(INTDIR)\JDFHoleLine.obj" \
	"$(INTDIR)\JDFHoleMakingParams.obj" \
	"$(INTDIR)\JDFIdentificationField.obj" \
	"$(INTDIR)\JDFIDPrintingParams.obj" \
	"$(INTDIR)\JDFImageCompressionParams.obj" \
	"$(INTDIR)\JDFImageReplacementParams.obj" \
	"$(INTDIR)\JDFImageSetterParams.obj" \
	"$(INTDIR)\JDFInk.obj" \
	"$(INTDIR)\JDFInkZoneCalculationParams.obj" \
	"$(INTDIR)\JDFInkZoneProfile.obj" \
	"$(INTDIR)\JDFInsertingParams.obj" \
	"$(INTDIR)\JDFInsertSheet.obj" \
	"$(INTDIR)\JDFInterpretedPDLData.obj" \
	"$(INTDIR)\JDFInterpretingParams.obj" \
	"$(INTDIR)\JDFJacketingParams.obj" \
	"$(INTDIR)\JDFJobField.obj" \
	"$(INTDIR)\JDFLabelingParams.obj" \
	"$(INTDIR)\JDFLaminatingParams.obj" \
	"$(INTDIR)\JDFLayout.obj" \
	"$(INTDIR)\JDFLayoutElement.obj" \
	"$(INTDIR)\JDFLayoutPreparationParams.obj" \
	"$(INTDIR)\JDFLongitudinalRibbonOperationParams.obj" \
	"$(INTDIR)\JDFManualLaborParams.obj" \
	"$(INTDIR)\JDFMedia.obj" \
	"$(INTDIR)\JDFMediaSource.obj" \
	"$(INTDIR)\JDFMISDetails.obj" \
	"$(INTDIR)\JDFNumberingParams.obj" \
	"$(INTDIR)\JDFObjectResolution.obj" \
	"$(INTDIR)\JDFOrderingParams.obj" \
	"$(INTDIR)\JDFPackingParams.obj" \
	"$(INTDIR)\JDFPageList.obj" \
	"$(INTDIR)\JDFPallet.obj" \
	"$(INTDIR)\JDFPalletizingParams.obj" \
	"$(INTDIR)\JDFPDFToPSConversionParams.obj" \
	"$(INTDIR)\JDFPDLResourceAlias.obj" \
	"$(INTDIR)\JDFPerforatingParams.obj" \
	"$(INTDIR)\JDFPerson.obj" \
	"$(INTDIR)\JDFPlaceHolderResource.obj" \
	"$(INTDIR)\JDFPlasticCombBindingParams.obj" \
	"$(INTDIR)\JDFPlateCopyParams.obj" \
	"$(INTDIR)\JDFPreflightAnalysis.obj" \
	"$(INTDIR)\JDFPreflightInventory.obj" \
	"$(INTDIR)\JDFPreflightParams.obj" \
	"$(INTDIR)\JDFPreflightProfile.obj" \
	"$(INTDIR)\JDFPreflightReport.obj" \
	"$(INTDIR)\JDFPreflightReportRulePool.obj" \
	"$(INTDIR)\JDFPreview.obj" \
	"$(INTDIR)\JDFPreviewGenerationParams.obj" \
	"$(INTDIR)\JDFPrintCondition.obj" \
	"$(INTDIR)\JDFPrintRollingParams.obj" \
	"$(INTDIR)\JDFProofingParams.obj" \
	"$(INTDIR)\JDFPSToPDFConversionParams.obj" \
	"$(INTDIR)\JDFQualityControlParams.obj" \
	"$(INTDIR)\JDFQualityControlResult.obj" \
	"$(INTDIR)\JDFRegisterMark.obj" \
	"$(INTDIR)\JDFRegisterRibbon.obj" \
	"$(INTDIR)\JDFRenderingParams.obj" \
	"$(INTDIR)\JDFResourceDefinitionParams.obj" \
	"$(INTDIR)\JDFRingBindingParams.obj" \
	"$(INTDIR)\JDFRollStand.obj" \
	"$(INTDIR)\JDFRunList.obj" \
	"$(INTDIR)\JDFSaddleStitchingParams.obj" \
	"$(INTDIR)\JDFScanParams.obj" \
	"$(INTDIR)\JDFScavengerArea.obj" \
	"$(INTDIR)\JDFScreeningParams.obj" \
	"$(INTDIR)\JDFSeparationControlParams.obj" \
	"$(INTDIR)\JDFSeparationSpec.obj" \
	"$(INTDIR)\JDFShapeCuttingParams.obj" \
	"$(INTDIR)\JDFSheet.obj" \
	"$(INTDIR)\JDFShrinkingParams.obj" \
	"$(INTDIR)\JDFSideSewingParams.obj" \
	"$(INTDIR)\JDFSpinePreparationParams.obj" \
	"$(INTDIR)\JDFSpineTapingParams.obj" \
	"$(INTDIR)\JDFStackingParams.obj" \
	"$(INTDIR)\JDFStitchingParams.obj" \
	"$(INTDIR)\JDFStrap.obj" \
	"$(INTDIR)\JDFStrappingParams.obj" \
	"$(INTDIR)\JDFStripBindingParams.obj" \
	"$(INTDIR)\JDFStrippingParams.obj" \
	"$(INTDIR)\JDFSurface.obj" \
	"$(INTDIR)\JDFThreadSealingParams.obj" \
	"$(INTDIR)\JDFThreadSewingParams.obj" \
	"$(INTDIR)\JDFTile.obj" \
	"$(INTDIR)\JDFTool.obj" \
	"$(INTDIR)\JDFTransferCurve.obj" \
	"$(INTDIR)\JDFTransferCurvePool.obj" \
	"$(INTDIR)\JDFTransferFunctionControl.obj" \
	"$(INTDIR)\JDFTrappingDetails.obj" \
	"$(INTDIR)\JDFTrappingParams.obj" \
	"$(INTDIR)\JDFTrapRegion.obj" \
	"$(INTDIR)\JDFTrimmingParams.obj" \
	"$(INTDIR)\JDFVerificationParams.obj" \
	"$(INTDIR)\JDFWireCombBindingParams.obj" \
	"$(INTDIR)\JDFWrappingParams.obj" \
	"$(INTDIR)\JDFAdvancedParams.obj" \
	"$(INTDIR)\JDFApprovalPerson.obj" \
	"$(INTDIR)\JDFAssemblySection.obj" \
	"$(INTDIR)\JDFBand.obj" \
	"$(INTDIR)\JDFBasicPreflightTest.obj" \
	"$(INTDIR)\JDFBindingQualityParams.obj" \
	"$(INTDIR)\JDFBoxArgument.obj" \
	"$(INTDIR)\JDFBoxToBoxDifference.obj" \
	"$(INTDIR)\JDFBundleItem.obj" \
	"$(INTDIR)\JDFCCITTFaxParams.obj" \
	"$(INTDIR)\JDFCollatingItem.obj" \
	"$(INTDIR)\JDFColorantZoneDetails.obj" \
	"$(INTDIR)\JDFColorCorrectionOp.obj" \
	"$(INTDIR)\JDFColorSpaceSubstitute.obj" \
	"$(INTDIR)\JDFContainer.obj" \
	"$(INTDIR)\JDFContentObject.obj" \
	"$(INTDIR)\JDFCrease.obj" \
	"$(INTDIR)\JDFCut.obj" \
	"$(INTDIR)\JDFDCTParams.obj" \
	"$(INTDIR)\JDFDependencies.obj" \
	"$(INTDIR)\JDFDeviceNColor.obj" \
	"$(INTDIR)\JDFDrop.obj" \
	"$(INTDIR)\JDFDropItem.obj" \
	"$(INTDIR)\JDFDynamicField.obj" \
	"$(INTDIR)\JDFDynamicInput.obj" \
	"$(INTDIR)\JDFEmboss.obj" \
	"$(INTDIR)\JDFEndSheet.obj" \
	"$(INTDIR)\JDFFeeder.obj" \
	"$(INTDIR)\JDFFeederQualityParams.obj" \
	"$(INTDIR)\JDFFileAlias.obj" \
	"$(INTDIR)\JDFFlateParams.obj" \
	"$(INTDIR)\JDFGlue.obj" \
	"$(INTDIR)\JDFIcon.obj" \
	"$(INTDIR)\JDFIconList.obj" \
	"$(INTDIR)\JDFIDPCover.obj" \
	"$(INTDIR)\JDFIDPFinishing.obj" \
	"$(INTDIR)\JDFIDPFolding.obj" \
	"$(INTDIR)\JDFIDPHoleMaking.obj" \
	"$(INTDIR)\JDFIDPImageShift.obj" \
	"$(INTDIR)\JDFIDPJobSheet.obj" \
	"$(INTDIR)\JDFIDPLayout.obj" \
	"$(INTDIR)\JDFIDPStitching.obj" \
	"$(INTDIR)\JDFIDPTrimming.obj" \
	"$(INTDIR)\JDFImageCompression.obj" \
	"$(INTDIR)\JDFImageShift.obj" \
	"$(INTDIR)\JDFLayerDetails.obj" \
	"$(INTDIR)\JDFLayerList.obj" \
	"$(INTDIR)\JDFLongFold.obj" \
	"$(INTDIR)\JDFLongGlue.obj" \
	"$(INTDIR)\JDFLongPerforate.obj" \
	"$(INTDIR)\JDFLongSlit.obj" \
	"$(INTDIR)\JDFLZWParams.obj" \
	"$(INTDIR)\JDFMarkObject.obj" \
	"$(INTDIR)\JDFNumberingParam.obj" \
	"$(INTDIR)\JDFPageCell.obj" \
	"$(INTDIR)\JDFPageData.obj" \
	"$(INTDIR)\JDFPDFInterpretingParams.obj" \
	"$(INTDIR)\JDFPDFXParams.obj" \
	"$(INTDIR)\JDFPerforate.obj" \
	"$(INTDIR)\JDFPixelColorant.obj" \
	"$(INTDIR)\JDFPosition.obj" \
	"$(INTDIR)\JDFPreflightAction.obj" \
	"$(INTDIR)\JDFPreflightArgument.obj" \
	"$(INTDIR)\JDFPreflightConstraint.obj" \
	"$(INTDIR)\JDFPreflightDetail.obj" \
	"$(INTDIR)\JDFPreflightInstance.obj" \
	"$(INTDIR)\JDFPreflightInstanceDetail.obj" \
	"$(INTDIR)\JDFPreflightValue.obj" \
	"$(INTDIR)\JDFPRError.obj" \
	"$(INTDIR)\JDFPRGroup.obj" \
	"$(INTDIR)\JDFPrintConditionColor.obj" \
	"$(INTDIR)\JDFPRItem.obj" \
	"$(INTDIR)\JDFPROccurence.obj" \
	"$(INTDIR)\JDFProperties.obj" \
	"$(INTDIR)\JDFPRRule.obj" \
	"$(INTDIR)\JDFPRRuleAttr.obj" \
	"$(INTDIR)\JDFQualityMeasurement.obj" \
	"$(INTDIR)\JDFResourceParam.obj" \
	"$(INTDIR)\JDFScore.obj" \
	"$(INTDIR)\JDFScreenSelector.obj" \
	"$(INTDIR)\JDFShapeElement.obj" \
	"$(INTDIR)\JDFSignature.obj" \
	"$(INTDIR)\JDFSignatureCell.obj" \
	"$(INTDIR)\JDFStringListValue.obj" \
	"$(INTDIR)\JDFStripCellParams.obj" \
	"$(INTDIR)\JDFThinPDFParams.obj" \
	"$(INTDIR)\JDFTIFFEmbeddedFile.obj" \
	"$(INTDIR)\JDFTIFFFormatParams.obj" \
	"$(INTDIR)\JDFTIFFtag.obj" \
	"$(INTDIR)\JDFTransferCurveSet.obj" \
	"$(INTDIR)\JDFTrappingOrder.obj" \
	"$(INTDIR)\JDFAction.obj" \
	"$(INTDIR)\JDFActionPool.obj" \
	"$(INTDIR)\JDFand.obj" \
	"$(INTDIR)\JDFBooleanEvaluation.obj" \
	"$(INTDIR)\JDFBooleanState.obj" \
	"$(INTDIR)\JDFcall.obj" \
	"$(INTDIR)\JDFchoice.obj" \
	"$(INTDIR)\JDFDateTimeEvaluation.obj" \
	"$(INTDIR)\JDFDateTimeState.obj" \
	"$(INTDIR)\JDFDevCap.obj" \
	"$(INTDIR)\JDFDevCaps.obj" \
	"$(INTDIR)\JDFDeviceCap.obj" \
	"$(INTDIR)\JDFDisplayGroup.obj" \
	"$(INTDIR)\JDFDisplayGroupPool.obj" \
	"$(INTDIR)\JDFDurationEvaluation.obj" \
	"$(INTDIR)\JDFDurationState.obj" \
	"$(INTDIR)\JDFEnumerationEvaluation.obj" \
	"$(INTDIR)\JDFEnumerationState.obj" \
	"$(INTDIR)\JDFEvaluation.obj" \
	"$(INTDIR)\JDFFeatureAttribute.obj" \
	"$(INTDIR)\JDFFeaturePool.obj" \
	"$(INTDIR)\JDFIntegerEvaluation.obj" \
	"$(INTDIR)\JDFIntegerState.obj" \
	"$(INTDIR)\JDFIsPresentEvaluation.obj" \
	"$(INTDIR)\JDFLoc.obj" \
	"$(INTDIR)\JDFmacro.obj" \
	"$(INTDIR)\JDFMacroPool.obj" \
	"$(INTDIR)\JDFMatrixEvaluation.obj" \
	"$(INTDIR)\JDFMatrixState.obj" \
	"$(INTDIR)\JDFNameEvaluation.obj" \
	"$(INTDIR)\JDFNameState.obj" \
	"$(INTDIR)\JDFnot.obj" \
	"$(INTDIR)\JDFNumberEvaluation.obj" \
	"$(INTDIR)\JDFNumberState.obj" \
	"$(INTDIR)\JDFor.obj" \
	"$(INTDIR)\JDFotherwise.obj" \
	"$(INTDIR)\JDFPDFPathEvaluation.obj" \
	"$(INTDIR)\JDFPDFPathState.obj" \
	"$(INTDIR)\JDFPerformance.obj" \
	"$(INTDIR)\JDFRectangleEvaluation.obj" \
	"$(INTDIR)\JDFRectangleState.obj" \
	"$(INTDIR)\JDFset.obj" \
	"$(INTDIR)\JDFShapeEvaluation.obj" \
	"$(INTDIR)\JDFShapeState.obj" \
	"$(INTDIR)\JDFState.obj" \
	"$(INTDIR)\JDFStringEvaluation.obj" \
	"$(INTDIR)\JDFStringState.obj" \
	"$(INTDIR)\JDFTest.obj" \
	"$(INTDIR)\JDFTestPool.obj" \
	"$(INTDIR)\JDFTestRef.obj" \
	"$(INTDIR)\JDFValue.obj" \
	"$(INTDIR)\JDFValueLoc.obj" \
	"$(INTDIR)\JDFwhen.obj" \
	"$(INTDIR)\JDFxor.obj" \
	"$(INTDIR)\JDFXYPairEvaluation.obj" \
	"$(INTDIR)\JDFXYPairState.obj" \
	"$(INTDIR)\JDFDoc.obj" \
	"$(INTDIR)\JDFElement.obj" \
	"$(INTDIR)\JDFFactory.obj" \
	"$(INTDIR)\JDFNodeFactory.obj" \
	"$(INTDIR)\JDFParamsFactory.obj" \
	"$(INTDIR)\JDFPool.obj" \
	"$(INTDIR)\JDFRefElement.obj" \
	"$(INTDIR)\JDFResource.obj" \
	"$(INTDIR)\JDFResourceLink.obj" \
	"$(INTDIR)\JDFRunElement.obj" \
	"$(INTDIR)\JDFSeparationList.obj" \
	"$(INTDIR)\JDFStrings.obj" \
	"$(INTDIR)\JDFAutoAmountPool.obj" \
	"$(INTDIR)\JDFAutoAncestor.obj" \
	"$(INTDIR)\JDFAutoAncestorPool.obj" \
	"$(INTDIR)\JDFAutoBarcode.obj" \
	"$(INTDIR)\JDFAutoBusinessInfo.obj" \
	"$(INTDIR)\JDFAutoComment.obj" \
	"$(INTDIR)\JDFAutoCounterReset.obj" \
	"$(INTDIR)\JDFAutoCreated.obj" \
	"$(INTDIR)\JDFAutoCustomerInfo.obj" \
	"$(INTDIR)\JDFAutoCustomerMessage.obj" \
	"$(INTDIR)\JDFAutoDeleted.obj" \
	"$(INTDIR)\JDFAutoError.obj" \
	"$(INTDIR)\JDFAutoEvent.obj" \
	"$(INTDIR)\JDFAutoFCNKey.obj" \
	"$(INTDIR)\JDFAutoLocation.obj" \
	"$(INTDIR)\JDFAutoMerged.obj" \
	"$(INTDIR)\JDFAutoModified.obj" \
	"$(INTDIR)\JDFAutoModulePhase.obj" \
	"$(INTDIR)\JDFAutoNodeInfo.obj" \
	"$(INTDIR)\JDFAutoNotification.obj" \
	"$(INTDIR)\JDFAutoPart.obj" \
	"$(INTDIR)\JDFAutoPartStatus.obj" \
	"$(INTDIR)\JDFAutoPhaseTime.obj" \
	"$(INTDIR)\JDFAutoProcessRun.obj" \
	"$(INTDIR)\JDFAutoResourceAudit.obj" \
	"$(INTDIR)\JDFAutoSpawned.obj" \
	"$(INTDIR)\JDFAutoStatusPool.obj" \
	"$(INTDIR)\JDFAutoSystemTimeSet.obj" \
	"$(INTDIR)\JDFAutoAcknowledge.obj" \
	"$(INTDIR)\JDFAutoAdded.obj" \
	"$(INTDIR)\JDFAutoChangedAttribute.obj" \
	"$(INTDIR)\JDFAutoChangedPath.obj" \
	"$(INTDIR)\JDFAutoCommand.obj" \
	"$(INTDIR)\JDFAutoDeviceFilter.obj" \
	"$(INTDIR)\JDFAutoDeviceInfo.obj" \
	"$(INTDIR)\JDFAutoDeviceList.obj" \
	"$(INTDIR)\JDFAutoEmployeeDef.obj" \
	"$(INTDIR)\JDFAutoFlushedResources.obj" \
	"$(INTDIR)\JDFAutoFlushQueueParams.obj" \
	"$(INTDIR)\JDFAutoFlushResourceParams.obj" \
	"$(INTDIR)\JDFAutoIDInfo.obj" \
	"$(INTDIR)\JDFAutoJDFController.obj" \
	"$(INTDIR)\JDFAutoJDFService.obj" \
	"$(INTDIR)\JDFAutoJMF.obj" \
	"$(INTDIR)\JDFAutoJobPhase.obj" \
	"$(INTDIR)\JDFAutoKnownMsgQuParams.obj" \
	"$(INTDIR)\JDFAutoMessage.obj" \
	"$(INTDIR)\JDFAutoMessageService.obj" \
	"$(INTDIR)\JDFAutoModuleStatus.obj" \
	"$(INTDIR)\JDFAutoMsgFilter.obj" \
	"$(INTDIR)\JDFAutoNewJDFCmdParams.obj" \
	"$(INTDIR)\JDFAutoNewJDFQuParams.obj" \
	"$(INTDIR)\JDFAutoNodeInfoCmdParams.obj" \
	"$(INTDIR)\JDFAutoNodeInfoQuParams.obj" \
	"$(INTDIR)\JDFAutoNodeInfoResp.obj" \
	"$(INTDIR)\JDFAutoNotificationDef.obj" \
	"$(INTDIR)\JDFAutoNotificationFilter.obj" \
	"$(INTDIR)\JDFAutoObservationTarget.obj" \
	"$(INTDIR)\JDFAutoOccupation.obj" \
	"$(INTDIR)\JDFAutoPipeParams.obj" \
	"$(INTDIR)\JDFAutoQuery.obj" \
	"$(INTDIR)\JDFAutoQueue.obj" \
	"$(INTDIR)\JDFAutoQueueEntry.obj" \
	"$(INTDIR)\JDFAutoQueueEntryDef.obj" \
	"$(INTDIR)\JDFAutoQueueEntryDefList.obj" \
	"$(INTDIR)\JDFAutoQueueEntryPosParams.obj" \
	"$(INTDIR)\JDFAutoQueueEntryPriParams.obj" \
	"$(INTDIR)\JDFAutoQueueFilter.obj" \
	"$(INTDIR)\JDFAutoQueueSubmissionParams.obj" \
	"$(INTDIR)\JDFAutoRemoved.obj" \
	"$(INTDIR)\JDFAutoRequestQueueEntryParams.obj" \
	"$(INTDIR)\JDFAutoResourceCmdParams.obj" \
	"$(INTDIR)\JDFAutoResourceInfo.obj" \
	"$(INTDIR)\JDFAutoResourcePullParams.obj" \
	"$(INTDIR)\JDFAutoResourceQuParams.obj" \
	"$(INTDIR)\JDFAutoResponse.obj" \
	"$(INTDIR)\JDFAutoResubmissionParams.obj" \
	"$(INTDIR)\JDFAutoReturnQueueEntryParams.obj" \
	"$(INTDIR)\JDFAutoShutDownCmdParams.obj" \
	"$(INTDIR)\JDFAutoSignal.obj" \
	"$(INTDIR)\JDFAutoStatusQuParams.obj" \
	"$(INTDIR)\JDFAutoStopPersChParams.obj" \
	"$(INTDIR)\JDFAutoSubmissionMethods.obj" \
	"$(INTDIR)\JDFAutoSubscription.obj" \
	"$(INTDIR)\JDFAutoTrackFilter.obj" \
	"$(INTDIR)\JDFAutoTrackResult.obj" \
	"$(INTDIR)\JDFAutoTrigger.obj" \
	"$(INTDIR)\JDFAutoWakeUpCmdParams.obj" \
	"$(INTDIR)\JDFAutoArtDeliveryIntent.obj" \
	"$(INTDIR)\JDFAutoBindingIntent.obj" \
	"$(INTDIR)\JDFAutoColorIntent.obj" \
	"$(INTDIR)\JDFAutoDeliveryIntent.obj" \
	"$(INTDIR)\JDFAutoEmbossingIntent.obj" \
	"$(INTDIR)\JDFAutoFoldingIntent.obj" \
	"$(INTDIR)\JDFAutoHoleMakingIntent.obj" \
	"$(INTDIR)\JDFAutoInsertingIntent.obj" \
	"$(INTDIR)\JDFAutoLaminatingIntent.obj" \
	"$(INTDIR)\JDFAutoLayoutIntent.obj" \
	"$(INTDIR)\JDFAutoMediaIntent.obj" \
	"$(INTDIR)\JDFAutoNumberingIntent.obj" \
	"$(INTDIR)\JDFAutoPackingIntent.obj" \
	"$(INTDIR)\JDFAutoProductionIntent.obj" \
	"$(INTDIR)\JDFAutoProofingIntent.obj" \
	"$(INTDIR)\JDFAutoScreeningIntent.obj" \
	"$(INTDIR)\JDFAutoShapeCuttingIntent.obj" \
	"$(INTDIR)\JDFAutoSizeIntent.obj" \
	"$(INTDIR)\JDFAutoAdhesiveBinding.obj" \
	"$(INTDIR)\JDFAutoArtDelivery.obj" \
	"$(INTDIR)\JDFAutoBindItem.obj" \
	"$(INTDIR)\JDFAutoBindList.obj" \
	"$(INTDIR)\JDFAutoBookCase.obj" \
	"$(INTDIR)\JDFAutoChannelBinding.obj" \
	"$(INTDIR)\JDFAutoCoilBinding.obj" \
	"$(INTDIR)\JDFAutoColorsUsed.obj" \
	"$(INTDIR)\JDFAutoCreditCard.obj" \
	"$(INTDIR)\JDFAutoDropIntent.obj" \
	"$(INTDIR)\JDFAutoDropItemIntent.obj" \
	"$(INTDIR)\JDFAutoEdgeGluing.obj" \
	"$(INTDIR)\JDFAutoEmbossingItem.obj" \
	"$(INTDIR)\JDFAutoHardCoverBinding.obj" \
	"$(INTDIR)\JDFAutoHoleList.obj" \
	"$(INTDIR)\JDFAutoInsert.obj" \
	"$(INTDIR)\JDFAutoInsertList.obj" \
	"$(INTDIR)\JDFAutoNumberItem.obj" \
	"$(INTDIR)\JDFAutoPayment.obj" \
	"$(INTDIR)\JDFAutoPlasticCombBinding.obj" \
	"$(INTDIR)\JDFAutoPricing.obj" \
	"$(INTDIR)\JDFAutoProofItem.obj" \
	"$(INTDIR)\JDFAutoRingBinding.obj" \
	"$(INTDIR)\JDFAutoSaddleStitching.obj" \
	"$(INTDIR)\JDFAutoShapeCut.obj" \
	"$(INTDIR)\JDFAutoSideSewing.obj" \
	"$(INTDIR)\JDFAutoSideStitching.obj" \
	"$(INTDIR)\JDFAutoSoftCoverBinding.obj" \
	"$(INTDIR)\JDFAutoStripBinding.obj" \
	"$(INTDIR)\JDFAutoTabs.obj" \
	"$(INTDIR)\JDFAutoTape.obj" \
	"$(INTDIR)\JDFAutoThreadSealing.obj" \
	"$(INTDIR)\JDFAutoThreadSewing.obj" \
	"$(INTDIR)\JDFAutoWireCombBinding.obj" \
	"$(INTDIR)\JDFAutoAddress.obj" \
	"$(INTDIR)\JDFAutoAdhesiveBindingParams.obj" \
	"$(INTDIR)\JDFAutoApprovalParams.obj" \
	"$(INTDIR)\JDFAutoApprovalSuccess.obj" \
	"$(INTDIR)\JDFAutoAssembly.obj" \
	"$(INTDIR)\JDFAutoAssetListCreationParams.obj" \
	"$(INTDIR)\JDFAutoAutomatedOverprintParams.obj" \
	"$(INTDIR)\JDFAutoBinderySignature.obj" \
	"$(INTDIR)\JDFAutoBlockPreparationParams.obj" \
	"$(INTDIR)\JDFAutoBoxPackingParams.obj" \
	"$(INTDIR)\JDFAutoBufferParams.obj" \
	"$(INTDIR)\JDFAutoBundle.obj" \
	"$(INTDIR)\JDFAutoBundlingParams.obj" \
	"$(INTDIR)\JDFAutoByteMap.obj" \
	"$(INTDIR)\JDFAutoCaseMakingParams.obj" \
	"$(INTDIR)\JDFAutoCasingInParams.obj" \
	"$(INTDIR)\JDFAutoChannelBindingParams.obj" \
	"$(INTDIR)\JDFAutoCIELABMeasuringField.obj" \
	"$(INTDIR)\JDFAutoCoilBindingParams.obj" \
	"$(INTDIR)\JDFAutoCollectingParams.obj" \
	"$(INTDIR)\JDFAutoColor.obj" \
	"$(INTDIR)\JDFAutoColorantAlias.obj" \
	"$(INTDIR)\JDFAutoColorantControl.obj" \
	"$(INTDIR)\JDFAutoColorControlStrip.obj" \
	"$(INTDIR)\JDFAutoColorCorrectionParams.obj" \
	"$(INTDIR)\JDFAutoColorMeasurementConditions.obj" \
	"$(INTDIR)\JDFAutoColorPool.obj" \
	"$(INTDIR)\JDFAutoColorSpaceConversionOp.obj" \
	"$(INTDIR)\JDFAutoColorSpaceConversionParams.obj" \
	"$(INTDIR)\JDFAutoComChannel.obj" \
	"$(INTDIR)\JDFAutoCompany.obj" \
	"$(INTDIR)\JDFAutoComponent.obj" \
	"$(INTDIR)\JDFAutoContact.obj" \
	"$(INTDIR)\JDFAutoContactCopyParams.obj" \
	"$(INTDIR)\JDFAutoConventionalPrintingParams.obj" \
	"$(INTDIR)\JDFAutoCostCenter.obj" \
	"$(INTDIR)\JDFAutoCoverApplicationParams.obj" \
	"$(INTDIR)\JDFAutoCreasingParams.obj" \
	"$(INTDIR)\JDFAutoCutBlock.obj" \
	"$(INTDIR)\JDFAutoCutMark.obj" \
	"$(INTDIR)\JDFAutoCuttingParams.obj" \
	"$(INTDIR)\JDFAutoDBMergeParams.obj" \
	"$(INTDIR)\JDFAutoDBRules.obj" \
	"$(INTDIR)\JDFAutoDBSchema.obj" \
	"$(INTDIR)\JDFAutoDBSelection.obj" \
	"$(INTDIR)\JDFAutoDeliveryParams.obj" \
	"$(INTDIR)\JDFAutoDensityMeasuringField.obj" \
	"$(INTDIR)\JDFAutoDevelopingParams.obj" \
	"$(INTDIR)\JDFAutoDevice.obj" \
	"$(INTDIR)\JDFAutoDeviceMark.obj" \
	"$(INTDIR)\JDFAutoDeviceNSpace.obj" \
	"$(INTDIR)\JDFAutoDigitalDeliveryParams.obj" \
	"$(INTDIR)\JDFAutoDigitalMedia.obj" \
	"$(INTDIR)\JDFAutoDigitalPrintingParams.obj" \
	"$(INTDIR)\JDFAutoDisjointing.obj" \
	"$(INTDIR)\JDFAutoDisposition.obj" \
	"$(INTDIR)\JDFAutoDividingParams.obj" \
	"$(INTDIR)\JDFAutoElementColorParams.obj" \
	"$(INTDIR)\JDFAutoEmbossingParams.obj" \
	"$(INTDIR)\JDFAutoEmployee.obj" \
	"$(INTDIR)\JDFAutoEndSheetGluingParams.obj" \
	"$(INTDIR)\JDFAutoExposedMedia.obj" \
	"$(INTDIR)\JDFAutoFeedingParams.obj" \
	"$(INTDIR)\JDFAutoFileSpec.obj" \
	"$(INTDIR)\JDFAutoFitPolicy.obj" \
	"$(INTDIR)\JDFAutoFold.obj" \
	"$(INTDIR)\JDFAutoFoldingParams.obj" \
	"$(INTDIR)\JDFAutoFontParams.obj" \
	"$(INTDIR)\JDFAutoFontPolicy.obj" \
	"$(INTDIR)\JDFAutoFormatConversionParams.obj" \
	"$(INTDIR)\JDFAutoGatheringParams.obj" \
	"$(INTDIR)\JDFAutoGlueApplication.obj" \
	"$(INTDIR)\JDFAutoGlueLine.obj" \
	"$(INTDIR)\JDFAutoGluingParams.obj" \
	"$(INTDIR)\JDFAutoHeadBandApplicationParams.obj" \
	"$(INTDIR)\JDFAutoHole.obj" \
	"$(INTDIR)\JDFAutoHoleLine.obj" \
	"$(INTDIR)\JDFAutoHoleMakingParams.obj" \
	"$(INTDIR)\JDFAutoIdentificationField.obj" \
	"$(INTDIR)\JDFAutoIDPrintingParams.obj" \
	"$(INTDIR)\JDFAutoImageCompressionParams.obj" \
	"$(INTDIR)\JDFAutoImageReplacementParams.obj" \
	"$(INTDIR)\JDFAutoImageSetterParams.obj" \
	"$(INTDIR)\JDFAutoInk.obj" \
	"$(INTDIR)\JDFAutoInkZoneCalculationParams.obj" \
	"$(INTDIR)\JDFAutoInkZoneProfile.obj" \
	"$(INTDIR)\JDFAutoInsertingParams.obj" \
	"$(INTDIR)\JDFAutoInsertSheet.obj" \
	"$(INTDIR)\JDFAutoInterpretedPDLData.obj" \
	"$(INTDIR)\JDFAutoInterpretingParams.obj" \
	"$(INTDIR)\JDFAutoJacketingParams.obj" \
	"$(INTDIR)\JDFAutoJobField.obj" \
	"$(INTDIR)\JDFAutoLabelingParams.obj" \
	"$(INTDIR)\JDFAutoLaminatingParams.obj" \
	"$(INTDIR)\JDFAutoLayout.obj" \
	"$(INTDIR)\JDFAutoLayoutElement.obj" \
	"$(INTDIR)\JDFAutoLayoutPreparationParams.obj" \
	"$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.obj" \
	"$(INTDIR)\JDFAutoManualLaborParams.obj" \
	"$(INTDIR)\JDFAutoMedia.obj" \
	"$(INTDIR)\JDFAutoMediaSource.obj" \
	"$(INTDIR)\JDFAutoMISDetails.obj" \
	"$(INTDIR)\JDFAutoNumberingParams.obj" \
	"$(INTDIR)\JDFAutoObjectResolution.obj" \
	"$(INTDIR)\JDFAutoOrderingParams.obj" \
	"$(INTDIR)\JDFAutoPackingParams.obj" \
	"$(INTDIR)\JDFAutoPageList.obj" \
	"$(INTDIR)\JDFAutoPallet.obj" \
	"$(INTDIR)\JDFAutoPalletizingParams.obj" \
	"$(INTDIR)\JDFAutoPDFToPSConversionParams.obj" \
	"$(INTDIR)\JDFAutoPDLResourceAlias.obj" \
	"$(INTDIR)\JDFAutoPerforatingParams.obj" \
	"$(INTDIR)\JDFAutoPerson.obj" \
	"$(INTDIR)\JDFAutoPlaceHolderResource.obj" \
	"$(INTDIR)\JDFAutoPlasticCombBindingParams.obj" \
	"$(INTDIR)\JDFAutoPlateCopyParams.obj" \
	"$(INTDIR)\JDFAutoPreflightAnalysis.obj" \
	"$(INTDIR)\JDFAutoPreflightInventory.obj" \
	"$(INTDIR)\JDFAutoPreflightParams.obj" \
	"$(INTDIR)\JDFAutoPreflightProfile.obj" \
	"$(INTDIR)\JDFAutoPreflightReport.obj" \
	"$(INTDIR)\JDFAutoPreflightReportRulePool.obj" \
	"$(INTDIR)\JDFAutoPreview.obj" \
	"$(INTDIR)\JDFAutoPreviewGenerationParams.obj" \
	"$(INTDIR)\JDFAutoPrintCondition.obj" \
	"$(INTDIR)\JDFAutoPrintRollingParams.obj" \
	"$(INTDIR)\JDFAutoProofingParams.obj" \
	"$(INTDIR)\JDFAutoPSToPDFConversionParams.obj" \
	"$(INTDIR)\JDFAutoQualityControlParams.obj" \
	"$(INTDIR)\JDFAutoQualityControlResult.obj" \
	"$(INTDIR)\JDFAutoRegisterMark.obj" \
	"$(INTDIR)\JDFAutoRegisterRibbon.obj" \
	"$(INTDIR)\JDFAutoRenderingParams.obj" \
	"$(INTDIR)\JDFAutoResourceDefinitionParams.obj" \
	"$(INTDIR)\JDFAutoRingBindingParams.obj" \
	"$(INTDIR)\JDFAutoRollStand.obj" \
	"$(INTDIR)\JDFAutoRunList.obj" \
	"$(INTDIR)\JDFAutoSaddleStitchingParams.obj" \
	"$(INTDIR)\JDFAutoScanParams.obj" \
	"$(INTDIR)\JDFAutoScavengerArea.obj" \
	"$(INTDIR)\JDFAutoScreeningParams.obj" \
	"$(INTDIR)\JDFAutoSeparationControlParams.obj" \
	"$(INTDIR)\JDFAutoSeparationSpec.obj" \
	"$(INTDIR)\JDFAutoShapeCuttingParams.obj" \
	"$(INTDIR)\JDFAutoSheet.obj" \
	"$(INTDIR)\JDFAutoShrinkingParams.obj" \
	"$(INTDIR)\JDFAutoSideSewingParams.obj" \
	"$(INTDIR)\JDFAutoSpinePreparationParams.obj" \
	"$(INTDIR)\JDFAutoSpineTapingParams.obj" \
	"$(INTDIR)\JDFAutoStackingParams.obj" \
	"$(INTDIR)\JDFAutoStitchingParams.obj" \
	"$(INTDIR)\JDFAutoStrap.obj" \
	"$(INTDIR)\JDFAutoStrappingParams.obj" \
	"$(INTDIR)\JDFAutoStripBindingParams.obj" \
	"$(INTDIR)\JDFAutoStrippingParams.obj" \
	"$(INTDIR)\JDFAutoSurface.obj" \
	"$(INTDIR)\JDFAutoThreadSealingParams.obj" \
	"$(INTDIR)\JDFAutoThreadSewingParams.obj" \
	"$(INTDIR)\JDFAutoTile.obj" \
	"$(INTDIR)\JDFAutoTool.obj" \
	"$(INTDIR)\JDFAutoTransferCurve.obj" \
	"$(INTDIR)\JDFAutoTransferCurvePool.obj" \
	"$(INTDIR)\JDFAutoTransferFunctionControl.obj" \
	"$(INTDIR)\JDFAutoTrappingDetails.obj" \
	"$(INTDIR)\JDFAutoTrappingParams.obj" \
	"$(INTDIR)\JDFAutoTrapRegion.obj" \
	"$(INTDIR)\JDFAutoTrimmingParams.obj" \
	"$(INTDIR)\JDFAutoVerificationParams.obj" \
	"$(INTDIR)\JDFAutoWireCombBindingParams.obj" \
	"$(INTDIR)\JDFAutoWrappingParams.obj" \
	"$(INTDIR)\JDFArgumentValue.obj" \
	"$(INTDIR)\JDFAutoAdvancedParams.obj" \
	"$(INTDIR)\JDFAutoApprovalPerson.obj" \
	"$(INTDIR)\JDFAutoArgumentValue.obj" \
	"$(INTDIR)\JDFAutoAssemblySection.obj" \
	"$(INTDIR)\JDFAutoBand.obj" \
	"$(INTDIR)\JDFAutoBasicPreflightTest.obj" \
	"$(INTDIR)\JDFAutoBindingQualityParams.obj" \
	"$(INTDIR)\JDFAutoBoxArgument.obj" \
	"$(INTDIR)\JDFAutoBoxToBoxDifference.obj" \
	"$(INTDIR)\JDFAutoBundleItem.obj" \
	"$(INTDIR)\JDFAutoCCITTFaxParams.obj" \
	"$(INTDIR)\JDFAutoCollatingItem.obj" \
	"$(INTDIR)\JDFAutoColorantZoneDetails.obj" \
	"$(INTDIR)\JDFAutoColorCorrectionOp.obj" \
	"$(INTDIR)\JDFAutoColorSpaceSubstitute.obj" \
	"$(INTDIR)\JDFAutoContainer.obj" \
	"$(INTDIR)\JDFAutoContentObject.obj" \
	"$(INTDIR)\JDFAutoCrease.obj" \
	"$(INTDIR)\JDFAutoCut.obj" \
	"$(INTDIR)\JDFAutoDCTParams.obj" \
	"$(INTDIR)\JDFAutoDependencies.obj" \
	"$(INTDIR)\JDFAutoDeviceNColor.obj" \
	"$(INTDIR)\JDFAutoDrop.obj" \
	"$(INTDIR)\JDFAutoDropItem.obj" \
	"$(INTDIR)\JDFAutoDynamicField.obj" \
	"$(INTDIR)\JDFAutoDynamicInput.obj" \
	"$(INTDIR)\JDFAutoEmboss.obj" \
	"$(INTDIR)\JDFAutoEndSheet.obj" \
	"$(INTDIR)\JDFAutoFeeder.obj" \
	"$(INTDIR)\JDFAutoFeederQualityParams.obj" \
	"$(INTDIR)\JDFAutoFileAlias.obj" \
	"$(INTDIR)\JDFAutoFlateParams.obj" \
	"$(INTDIR)\JDFAutoGlue.obj" \
	"$(INTDIR)\JDFAutoIcon.obj" \
	"$(INTDIR)\JDFAutoIconList.obj" \
	"$(INTDIR)\JDFAutoIDPCover.obj" \
	"$(INTDIR)\JDFAutoIDPFinishing.obj" \
	"$(INTDIR)\JDFAutoIDPFolding.obj" \
	"$(INTDIR)\JDFAutoIDPHoleMaking.obj" \
	"$(INTDIR)\JDFAutoIDPImageShift.obj" \
	"$(INTDIR)\JDFAutoIDPJobSheet.obj" \
	"$(INTDIR)\JDFAutoIDPLayout.obj" \
	"$(INTDIR)\JDFAutoIDPStitching.obj" \
	"$(INTDIR)\JDFAutoIDPTrimming.obj" \
	"$(INTDIR)\JDFAutoImageCompression.obj" \
	"$(INTDIR)\JDFAutoImageShift.obj" \
	"$(INTDIR)\JDFAutoLayerDetails.obj" \
	"$(INTDIR)\JDFAutoLayerList.obj" \
	"$(INTDIR)\JDFAutoLongFold.obj" \
	"$(INTDIR)\JDFAutoLongGlue.obj" \
	"$(INTDIR)\JDFAutoLongPerforate.obj" \
	"$(INTDIR)\JDFAutoLongSlit.obj" \
	"$(INTDIR)\JDFAutoLZWParams.obj" \
	"$(INTDIR)\JDFAutoMarkObject.obj" \
	"$(INTDIR)\JDFAutoNumberingParam.obj" \
	"$(INTDIR)\JDFAutoPageCell.obj" \
	"$(INTDIR)\JDFAutoPageData.obj" \
	"$(INTDIR)\JDFAutoPDFInterpretingParams.obj" \
	"$(INTDIR)\JDFAutoPDFXParams.obj" \
	"$(INTDIR)\JDFAutoPerforate.obj" \
	"$(INTDIR)\JDFAutoPixelColorant.obj" \
	"$(INTDIR)\JDFAutoPosition.obj" \
	"$(INTDIR)\JDFAutoPreflightAction.obj" \
	"$(INTDIR)\JDFAutoPreflightArgument.obj" \
	"$(INTDIR)\JDFAutoPreflightConstraint.obj" \
	"$(INTDIR)\JDFAutoPreflightDetail.obj" \
	"$(INTDIR)\JDFAutoPreflightInstance.obj" \
	"$(INTDIR)\JDFAutoPreflightInstanceDetail.obj" \
	"$(INTDIR)\JDFAutoPreflightValue.obj" \
	"$(INTDIR)\JDFAutoPRError.obj" \
	"$(INTDIR)\JDFAutoPRGroup.obj" \
	"$(INTDIR)\JDFAutoPrintConditionColor.obj" \
	"$(INTDIR)\JDFAutoPRItem.obj" \
	"$(INTDIR)\JDFAutoPROccurence.obj" \
	"$(INTDIR)\JDFAutoProperties.obj" \
	"$(INTDIR)\JDFAutoPRRule.obj" \
	"$(INTDIR)\JDFAutoPRRuleAttr.obj" \
	"$(INTDIR)\JDFAutoQualityMeasurement.obj" \
	"$(INTDIR)\JDFAutoResourceParam.obj" \
	"$(INTDIR)\JDFAutoScore.obj" \
	"$(INTDIR)\JDFAutoScreenSelector.obj" \
	"$(INTDIR)\JDFAutoShapeElement.obj" \
	"$(INTDIR)\JDFAutoSignature.obj" \
	"$(INTDIR)\JDFAutoSignatureCell.obj" \
	"$(INTDIR)\JDFAutoStringListValue.obj" \
	"$(INTDIR)\JDFAutoStripCellParams.obj" \
	"$(INTDIR)\JDFAutoThinPDFParams.obj" \
	"$(INTDIR)\JDFAutoTIFFEmbeddedFile.obj" \
	"$(INTDIR)\JDFAutoTIFFFormatParams.obj" \
	"$(INTDIR)\JDFAutoTIFFtag.obj" \
	"$(INTDIR)\JDFAutoTransferCurveSet.obj" \
	"$(INTDIR)\JDFAutoTrappingOrder.obj" \
	"$(INTDIR)\JDFAutoAction.obj" \
	"$(INTDIR)\JDFAutoActionPool.obj" \
	"$(INTDIR)\JDFAutoand.obj" \
	"$(INTDIR)\JDFAutocall.obj" \
	"$(INTDIR)\JDFAutochoice.obj" \
	"$(INTDIR)\JDFAutoDevCap.obj" \
	"$(INTDIR)\JDFAutoDevCaps.obj" \
	"$(INTDIR)\JDFAutoDeviceCap.obj" \
	"$(INTDIR)\JDFAutoDisplayGroup.obj" \
	"$(INTDIR)\JDFAutoDisplayGroupPool.obj" \
	"$(INTDIR)\JDFAutoFeatureAttribute.obj" \
	"$(INTDIR)\JDFAutoFeaturePool.obj" \
	"$(INTDIR)\JDFAutoLoc.obj" \
	"$(INTDIR)\JDFAutomacro.obj" \
	"$(INTDIR)\JDFAutoMacroPool.obj" \
	"$(INTDIR)\JDFAutonot.obj" \
	"$(INTDIR)\JDFAutoor.obj" \
	"$(INTDIR)\JDFAutootherwise.obj" \
	"$(INTDIR)\JDFAutoPerformance.obj" \
	"$(INTDIR)\JDFAutoset.obj" \
	"$(INTDIR)\JDFAutoTest.obj" \
	"$(INTDIR)\JDFAutoTestPool.obj" \
	"$(INTDIR)\JDFAutoTestRef.obj" \
	"$(INTDIR)\JDFAutoValue.obj" \
	"$(INTDIR)\JDFAutoValueLoc.obj" \
	"$(INTDIR)\JDFAutowhen.obj" \
	"$(INTDIR)\JDFAutoxor.obj" \
	"$(INTDIR)\JDFAutoEnumerationSpan.obj" \
	"$(INTDIR)\JDFAutoPRGroupOccurence.obj" \
	"$(INTDIR)\JDFAutoPRGroupOccurenceBase.obj" \
	"$(INTDIR)\JDFPreflightConstraintsPool.obj" \
	"$(INTDIR)\JDFPreflightResultsPool.obj" \
	"$(INTDIR)\JDFPRGroupOccurence.obj" \
	"$(INTDIR)\JDFPRGroupOccurenceBase.obj" \
	"$(INTDIR)\JDFDateTimeRange.obj" \
	"$(INTDIR)\JDFDateTimeRangeList.obj" \
	"$(INTDIR)\JDFDurationRange.obj" \
	"$(INTDIR)\JDFDurationRangeList.obj" \
	"$(INTDIR)\JDFIntegerRange.obj" \
	"$(INTDIR)\JDFIntegerRangeList.obj" \
	"$(INTDIR)\JDFNameRangeList.obj" \
	"$(INTDIR)\JDFNumberRangeList.obj" \
	"$(INTDIR)\JDFNumTypeList.obj" \
	"$(INTDIR)\JDFParser.obj" \
	"$(INTDIR)\JDFRange.obj" \
	"$(INTDIR)\JDFRangeList.obj" \
	"$(INTDIR)\JDFXYPairRangeList.obj" \
	"$(INTDIR)\KElement.obj" \
	"$(INTDIR)\KElementStrings.obj" \
	"$(INTDIR)\MyDate.obj" \
	"$(INTDIR)\vElement.obj" \
	"$(INTDIR)\XMLDoc.obj" \
	"$(INTDIR)\XMLDocUserData.obj"

"$(OUTDIR)\JDFWrapperLib_D.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("JDFWrapperLib.dep")
!INCLUDE "JDFWrapperLib.dep"
!ELSE 
!MESSAGE Warning: cannot find "JDFWrapperLib.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "JDFWrapperLib - Win32 Release DLL" || "$(CFG)" == "JDFWrapperLib - Win32 Debug DLL" || "$(CFG)" == "JDFWrapperLib - Win32 Debug" || "$(CFG)" == "JDFWrapperLib - Win32 Release" || "$(CFG)" == "JDFWrapperLib - Win32 Debug LineOnly"
SOURCE=..\..\..\src\jdf\wrapper\JDFAmountPool.cpp

"$(INTDIR)\JDFAmountPool.obj"	"$(INTDIR)\JDFAmountPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFAncestor.cpp

"$(INTDIR)\JDFAncestor.obj"	"$(INTDIR)\JDFAncestor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFAncestorPool.cpp

"$(INTDIR)\JDFAncestorPool.obj"	"$(INTDIR)\JDFAncestorPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFAudit.cpp

"$(INTDIR)\JDFAudit.obj"	"$(INTDIR)\JDFAudit.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFAuditPool.cpp

"$(INTDIR)\JDFAuditPool.obj"	"$(INTDIR)\JDFAuditPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBarcode.cpp

"$(INTDIR)\JDFBarcode.obj"	"$(INTDIR)\JDFBarcode.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBusinessInfo.cpp

"$(INTDIR)\JDFBusinessInfo.obj"	"$(INTDIR)\JDFBusinessInfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFComment.cpp

"$(INTDIR)\JDFComment.obj"	"$(INTDIR)\JDFComment.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCounterReset.cpp

"$(INTDIR)\JDFCounterReset.obj"	"$(INTDIR)\JDFCounterReset.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCreated.cpp

"$(INTDIR)\JDFCreated.obj"	"$(INTDIR)\JDFCreated.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCustomerInfo.cpp

"$(INTDIR)\JDFCustomerInfo.obj"	"$(INTDIR)\JDFCustomerInfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCustomerMessage.cpp

"$(INTDIR)\JDFCustomerMessage.obj"	"$(INTDIR)\JDFCustomerMessage.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDeleted.cpp

"$(INTDIR)\JDFDeleted.obj"	"$(INTDIR)\JDFDeleted.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFError.cpp

"$(INTDIR)\JDFError.obj"	"$(INTDIR)\JDFError.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFEvent.cpp

"$(INTDIR)\JDFEvent.obj"	"$(INTDIR)\JDFEvent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFCNKey.cpp

"$(INTDIR)\JDFFCNKey.obj"	"$(INTDIR)\JDFFCNKey.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFLocation.cpp

"$(INTDIR)\JDFLocation.obj"	"$(INTDIR)\JDFLocation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFMerged.cpp

"$(INTDIR)\JDFMerged.obj"	"$(INTDIR)\JDFMerged.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFModified.cpp

"$(INTDIR)\JDFModified.obj"	"$(INTDIR)\JDFModified.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFModulePhase.cpp

"$(INTDIR)\JDFModulePhase.obj"	"$(INTDIR)\JDFModulePhase.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNode.cpp

"$(INTDIR)\JDFNode.obj"	"$(INTDIR)\JDFNode.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInfo.cpp

"$(INTDIR)\JDFNodeInfo.obj"	"$(INTDIR)\JDFNodeInfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNotification.cpp

"$(INTDIR)\JDFNotification.obj"	"$(INTDIR)\JDFNotification.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPart.cpp

"$(INTDIR)\JDFPart.obj"	"$(INTDIR)\JDFPart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPartAmount.cpp

"$(INTDIR)\JDFPartAmount.obj"	"$(INTDIR)\JDFPartAmount.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPartStatus.cpp

"$(INTDIR)\JDFPartStatus.obj"	"$(INTDIR)\JDFPartStatus.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPhaseTime.cpp

"$(INTDIR)\JDFPhaseTime.obj"	"$(INTDIR)\JDFPhaseTime.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFProcessRun.cpp

"$(INTDIR)\JDFProcessRun.obj"	"$(INTDIR)\JDFProcessRun.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFResourceAudit.cpp

"$(INTDIR)\JDFResourceAudit.obj"	"$(INTDIR)\JDFResourceAudit.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFResourceLinkPool.cpp

"$(INTDIR)\JDFResourceLinkPool.obj"	"$(INTDIR)\JDFResourceLinkPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFResourcePool.cpp

"$(INTDIR)\JDFResourcePool.obj"	"$(INTDIR)\JDFResourcePool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSpawned.cpp

"$(INTDIR)\JDFSpawned.obj"	"$(INTDIR)\JDFSpawned.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFStatusPool.cpp

"$(INTDIR)\JDFStatusPool.obj"	"$(INTDIR)\JDFStatusPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSystemTimeSet.cpp

"$(INTDIR)\JDFSystemTimeSet.obj"	"$(INTDIR)\JDFSystemTimeSet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFAcknowledge.cpp

"$(INTDIR)\JDFAcknowledge.obj"	"$(INTDIR)\JDFAcknowledge.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFAdded.cpp

"$(INTDIR)\JDFAdded.obj"	"$(INTDIR)\JDFAdded.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFChangedAttribute.cpp

"$(INTDIR)\JDFChangedAttribute.obj"	"$(INTDIR)\JDFChangedAttribute.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFChangedPath.cpp

"$(INTDIR)\JDFChangedPath.obj"	"$(INTDIR)\JDFChangedPath.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCommand.cpp

"$(INTDIR)\JDFCommand.obj"	"$(INTDIR)\JDFCommand.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceFilter.cpp

"$(INTDIR)\JDFDeviceFilter.obj"	"$(INTDIR)\JDFDeviceFilter.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceInfo.cpp

"$(INTDIR)\JDFDeviceInfo.obj"	"$(INTDIR)\JDFDeviceInfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceList.cpp

"$(INTDIR)\JDFDeviceList.obj"	"$(INTDIR)\JDFDeviceList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFEmployeeDef.cpp

"$(INTDIR)\JDFEmployeeDef.obj"	"$(INTDIR)\JDFEmployeeDef.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFlushedResources.cpp

"$(INTDIR)\JDFFlushedResources.obj"	"$(INTDIR)\JDFFlushedResources.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFlushQueueParams.cpp

"$(INTDIR)\JDFFlushQueueParams.obj"	"$(INTDIR)\JDFFlushQueueParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFlushResourceParams.cpp

"$(INTDIR)\JDFFlushResourceParams.obj"	"$(INTDIR)\JDFFlushResourceParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIDInfo.cpp

"$(INTDIR)\JDFIDInfo.obj"	"$(INTDIR)\JDFIDInfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFJDFController.cpp

"$(INTDIR)\JDFJDFController.obj"	"$(INTDIR)\JDFJDFController.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFJDFService.cpp

"$(INTDIR)\JDFJDFService.obj"	"$(INTDIR)\JDFJDFService.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFJMF.cpp

"$(INTDIR)\JDFJMF.obj"	"$(INTDIR)\JDFJMF.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFJobPhase.cpp

"$(INTDIR)\JDFJobPhase.obj"	"$(INTDIR)\JDFJobPhase.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFKnownMsgQuParams.cpp

"$(INTDIR)\JDFKnownMsgQuParams.obj"	"$(INTDIR)\JDFKnownMsgQuParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFMessage.cpp

"$(INTDIR)\JDFMessage.obj"	"$(INTDIR)\JDFMessage.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFMessageElement.cpp

"$(INTDIR)\JDFMessageElement.obj"	"$(INTDIR)\JDFMessageElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFMessageService.cpp

"$(INTDIR)\JDFMessageService.obj"	"$(INTDIR)\JDFMessageService.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFModuleStatus.cpp

"$(INTDIR)\JDFModuleStatus.obj"	"$(INTDIR)\JDFModuleStatus.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFMsgFilter.cpp

"$(INTDIR)\JDFMsgFilter.obj"	"$(INTDIR)\JDFMsgFilter.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNewJDFCmdParams.cpp

"$(INTDIR)\JDFNewJDFCmdParams.obj"	"$(INTDIR)\JDFNewJDFCmdParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNewJDFQuParams.cpp

"$(INTDIR)\JDFNewJDFQuParams.obj"	"$(INTDIR)\JDFNewJDFQuParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInfoCmdParams.cpp

"$(INTDIR)\JDFNodeInfoCmdParams.obj"	"$(INTDIR)\JDFNodeInfoCmdParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInfoQuParams.cpp

"$(INTDIR)\JDFNodeInfoQuParams.obj"	"$(INTDIR)\JDFNodeInfoQuParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInfoResp.cpp

"$(INTDIR)\JDFNodeInfoResp.obj"	"$(INTDIR)\JDFNodeInfoResp.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNotificationDef.cpp

"$(INTDIR)\JDFNotificationDef.obj"	"$(INTDIR)\JDFNotificationDef.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNotificationFilter.cpp

"$(INTDIR)\JDFNotificationFilter.obj"	"$(INTDIR)\JDFNotificationFilter.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFObservationTarget.cpp

"$(INTDIR)\JDFObservationTarget.obj"	"$(INTDIR)\JDFObservationTarget.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFOccupation.cpp

"$(INTDIR)\JDFOccupation.obj"	"$(INTDIR)\JDFOccupation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPipeParams.cpp

"$(INTDIR)\JDFPipeParams.obj"	"$(INTDIR)\JDFPipeParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFQuery.cpp

"$(INTDIR)\JDFQuery.obj"	"$(INTDIR)\JDFQuery.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFQueue.cpp

"$(INTDIR)\JDFQueue.obj"	"$(INTDIR)\JDFQueue.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntry.cpp

"$(INTDIR)\JDFQueueEntry.obj"	"$(INTDIR)\JDFQueueEntry.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntryDef.cpp

"$(INTDIR)\JDFQueueEntryDef.obj"	"$(INTDIR)\JDFQueueEntryDef.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntryDefList.cpp

"$(INTDIR)\JDFQueueEntryDefList.obj"	"$(INTDIR)\JDFQueueEntryDefList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntryPosParams.cpp

"$(INTDIR)\JDFQueueEntryPosParams.obj"	"$(INTDIR)\JDFQueueEntryPosParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntryPriParams.cpp

"$(INTDIR)\JDFQueueEntryPriParams.obj"	"$(INTDIR)\JDFQueueEntryPriParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFQueueFilter.cpp

"$(INTDIR)\JDFQueueFilter.obj"	"$(INTDIR)\JDFQueueFilter.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFQueueSubmissionParams.cpp

"$(INTDIR)\JDFQueueSubmissionParams.obj"	"$(INTDIR)\JDFQueueSubmissionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFRemoved.cpp

"$(INTDIR)\JDFRemoved.obj"	"$(INTDIR)\JDFRemoved.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFRequestQueueEntryParams.cpp

"$(INTDIR)\JDFRequestQueueEntryParams.obj"	"$(INTDIR)\JDFRequestQueueEntryParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFResourceCmdParams.cpp

"$(INTDIR)\JDFResourceCmdParams.obj"	"$(INTDIR)\JDFResourceCmdParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFResourceInfo.cpp

"$(INTDIR)\JDFResourceInfo.obj"	"$(INTDIR)\JDFResourceInfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFResourcePullParams.cpp

"$(INTDIR)\JDFResourcePullParams.obj"	"$(INTDIR)\JDFResourcePullParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFResourceQuParams.cpp

"$(INTDIR)\JDFResourceQuParams.obj"	"$(INTDIR)\JDFResourceQuParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFResponse.cpp

"$(INTDIR)\JDFResponse.obj"	"$(INTDIR)\JDFResponse.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFResubmissionParams.cpp

"$(INTDIR)\JDFResubmissionParams.obj"	"$(INTDIR)\JDFResubmissionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFReturnQueueEntryParams.cpp

"$(INTDIR)\JDFReturnQueueEntryParams.obj"	"$(INTDIR)\JDFReturnQueueEntryParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFShutDownCmdParams.cpp

"$(INTDIR)\JDFShutDownCmdParams.obj"	"$(INTDIR)\JDFShutDownCmdParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSignal.cpp

"$(INTDIR)\JDFSignal.obj"	"$(INTDIR)\JDFSignal.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFStatusQuParams.cpp

"$(INTDIR)\JDFStatusQuParams.obj"	"$(INTDIR)\JDFStatusQuParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFStopPersChParams.cpp

"$(INTDIR)\JDFStopPersChParams.obj"	"$(INTDIR)\JDFStopPersChParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSubmissionMethods.cpp

"$(INTDIR)\JDFSubmissionMethods.obj"	"$(INTDIR)\JDFSubmissionMethods.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSubscription.cpp

"$(INTDIR)\JDFSubscription.obj"	"$(INTDIR)\JDFSubscription.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTrackFilter.cpp

"$(INTDIR)\JDFTrackFilter.obj"	"$(INTDIR)\JDFTrackFilter.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTrackResult.cpp

"$(INTDIR)\JDFTrackResult.obj"	"$(INTDIR)\JDFTrackResult.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTrigger.cpp

"$(INTDIR)\JDFTrigger.obj"	"$(INTDIR)\JDFTrigger.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFWakeUpCmdParams.cpp

"$(INTDIR)\JDFWakeUpCmdParams.obj"	"$(INTDIR)\JDFWakeUpCmdParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFArtDeliveryIntent.cpp

"$(INTDIR)\JDFArtDeliveryIntent.obj"	"$(INTDIR)\JDFArtDeliveryIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBindingIntent.cpp

"$(INTDIR)\JDFBindingIntent.obj"	"$(INTDIR)\JDFBindingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFColorIntent.cpp

"$(INTDIR)\JDFColorIntent.obj"	"$(INTDIR)\JDFColorIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDeliveryIntent.cpp

"$(INTDIR)\JDFDeliveryIntent.obj"	"$(INTDIR)\JDFDeliveryIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFEmbossingIntent.cpp

"$(INTDIR)\JDFEmbossingIntent.obj"	"$(INTDIR)\JDFEmbossingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFoldingIntent.cpp

"$(INTDIR)\JDFFoldingIntent.obj"	"$(INTDIR)\JDFFoldingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFHoleMakingIntent.cpp

"$(INTDIR)\JDFHoleMakingIntent.obj"	"$(INTDIR)\JDFHoleMakingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFInsertingIntent.cpp

"$(INTDIR)\JDFInsertingIntent.obj"	"$(INTDIR)\JDFInsertingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIntentResource.cpp

"$(INTDIR)\JDFIntentResource.obj"	"$(INTDIR)\JDFIntentResource.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFLaminatingIntent.cpp

"$(INTDIR)\JDFLaminatingIntent.obj"	"$(INTDIR)\JDFLaminatingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFLayoutIntent.cpp

"$(INTDIR)\JDFLayoutIntent.obj"	"$(INTDIR)\JDFLayoutIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFMediaIntent.cpp

"$(INTDIR)\JDFMediaIntent.obj"	"$(INTDIR)\JDFMediaIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNumberingIntent.cpp

"$(INTDIR)\JDFNumberingIntent.obj"	"$(INTDIR)\JDFNumberingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPackingIntent.cpp

"$(INTDIR)\JDFPackingIntent.obj"	"$(INTDIR)\JDFPackingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFProductionIntent.cpp

"$(INTDIR)\JDFProductionIntent.obj"	"$(INTDIR)\JDFProductionIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFProofingIntent.cpp

"$(INTDIR)\JDFProofingIntent.obj"	"$(INTDIR)\JDFProofingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFScreeningIntent.cpp

"$(INTDIR)\JDFScreeningIntent.obj"	"$(INTDIR)\JDFScreeningIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFShapeCuttingIntent.cpp

"$(INTDIR)\JDFShapeCuttingIntent.obj"	"$(INTDIR)\JDFShapeCuttingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSizeIntent.cpp

"$(INTDIR)\JDFSizeIntent.obj"	"$(INTDIR)\JDFSizeIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSpan.cpp

"$(INTDIR)\JDFSpan.obj"	"$(INTDIR)\JDFSpan.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFAdhesiveBinding.cpp

"$(INTDIR)\JDFAdhesiveBinding.obj"	"$(INTDIR)\JDFAdhesiveBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFArtDelivery.cpp

"$(INTDIR)\JDFArtDelivery.obj"	"$(INTDIR)\JDFArtDelivery.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBindItem.cpp

"$(INTDIR)\JDFBindItem.obj"	"$(INTDIR)\JDFBindItem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBindList.cpp

"$(INTDIR)\JDFBindList.obj"	"$(INTDIR)\JDFBindList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBookCase.cpp

"$(INTDIR)\JDFBookCase.obj"	"$(INTDIR)\JDFBookCase.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFChannelBinding.cpp

"$(INTDIR)\JDFChannelBinding.obj"	"$(INTDIR)\JDFChannelBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCoilBinding.cpp

"$(INTDIR)\JDFCoilBinding.obj"	"$(INTDIR)\JDFCoilBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFColorsUsed.cpp

"$(INTDIR)\JDFColorsUsed.obj"	"$(INTDIR)\JDFColorsUsed.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCreditCard.cpp

"$(INTDIR)\JDFCreditCard.obj"	"$(INTDIR)\JDFCreditCard.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDropIntent.cpp

"$(INTDIR)\JDFDropIntent.obj"	"$(INTDIR)\JDFDropIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDropItemIntent.cpp

"$(INTDIR)\JDFDropItemIntent.obj"	"$(INTDIR)\JDFDropItemIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFEdgeGluing.cpp

"$(INTDIR)\JDFEdgeGluing.obj"	"$(INTDIR)\JDFEdgeGluing.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFEmbossingItem.cpp

"$(INTDIR)\JDFEmbossingItem.obj"	"$(INTDIR)\JDFEmbossingItem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFHardCoverBinding.cpp

"$(INTDIR)\JDFHardCoverBinding.obj"	"$(INTDIR)\JDFHardCoverBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFHoleList.cpp

"$(INTDIR)\JDFHoleList.obj"	"$(INTDIR)\JDFHoleList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFInsert.cpp

"$(INTDIR)\JDFInsert.obj"	"$(INTDIR)\JDFInsert.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFInsertList.cpp

"$(INTDIR)\JDFInsertList.obj"	"$(INTDIR)\JDFInsertList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNumberItem.cpp

"$(INTDIR)\JDFNumberItem.obj"	"$(INTDIR)\JDFNumberItem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPayment.cpp

"$(INTDIR)\JDFPayment.obj"	"$(INTDIR)\JDFPayment.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPlasticCombBinding.cpp

"$(INTDIR)\JDFPlasticCombBinding.obj"	"$(INTDIR)\JDFPlasticCombBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPricing.cpp

"$(INTDIR)\JDFPricing.obj"	"$(INTDIR)\JDFPricing.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFProofItem.cpp

"$(INTDIR)\JDFProofItem.obj"	"$(INTDIR)\JDFProofItem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFRingBinding.cpp

"$(INTDIR)\JDFRingBinding.obj"	"$(INTDIR)\JDFRingBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSaddleStitching.cpp

"$(INTDIR)\JDFSaddleStitching.obj"	"$(INTDIR)\JDFSaddleStitching.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFShapeCut.cpp

"$(INTDIR)\JDFShapeCut.obj"	"$(INTDIR)\JDFShapeCut.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSideSewing.cpp

"$(INTDIR)\JDFSideSewing.obj"	"$(INTDIR)\JDFSideSewing.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSideStitching.cpp

"$(INTDIR)\JDFSideStitching.obj"	"$(INTDIR)\JDFSideStitching.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSoftCoverBinding.cpp

"$(INTDIR)\JDFSoftCoverBinding.obj"	"$(INTDIR)\JDFSoftCoverBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFStripBinding.cpp

"$(INTDIR)\JDFStripBinding.obj"	"$(INTDIR)\JDFStripBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTabs.cpp

"$(INTDIR)\JDFTabs.obj"	"$(INTDIR)\JDFTabs.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTape.cpp

"$(INTDIR)\JDFTape.obj"	"$(INTDIR)\JDFTape.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSealing.cpp

"$(INTDIR)\JDFThreadSealing.obj"	"$(INTDIR)\JDFThreadSealing.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSewing.cpp

"$(INTDIR)\JDFThreadSewing.obj"	"$(INTDIR)\JDFThreadSewing.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFWireCombBinding.cpp

"$(INTDIR)\JDFWireCombBinding.obj"	"$(INTDIR)\JDFWireCombBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFAddress.cpp

"$(INTDIR)\JDFAddress.obj"	"$(INTDIR)\JDFAddress.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFAdhesiveBindingParams.cpp

"$(INTDIR)\JDFAdhesiveBindingParams.obj"	"$(INTDIR)\JDFAdhesiveBindingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFApprovalParams.cpp

"$(INTDIR)\JDFApprovalParams.obj"	"$(INTDIR)\JDFApprovalParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFApprovalSuccess.cpp

"$(INTDIR)\JDFApprovalSuccess.obj"	"$(INTDIR)\JDFApprovalSuccess.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFAssembly.cpp

"$(INTDIR)\JDFAssembly.obj"	"$(INTDIR)\JDFAssembly.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFAssetListCreationParams.cpp

"$(INTDIR)\JDFAssetListCreationParams.obj"	"$(INTDIR)\JDFAssetListCreationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFAutomatedOverprintParams.cpp

"$(INTDIR)\JDFAutomatedOverprintParams.obj"	"$(INTDIR)\JDFAutomatedOverprintParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBinderySignature.cpp

"$(INTDIR)\JDFBinderySignature.obj"	"$(INTDIR)\JDFBinderySignature.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBlockPreparationParams.cpp

"$(INTDIR)\JDFBlockPreparationParams.obj"	"$(INTDIR)\JDFBlockPreparationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBoxPackingParams.cpp

"$(INTDIR)\JDFBoxPackingParams.obj"	"$(INTDIR)\JDFBoxPackingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBufferParams.cpp

"$(INTDIR)\JDFBufferParams.obj"	"$(INTDIR)\JDFBufferParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBundle.cpp

"$(INTDIR)\JDFBundle.obj"	"$(INTDIR)\JDFBundle.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBundlingParams.cpp

"$(INTDIR)\JDFBundlingParams.obj"	"$(INTDIR)\JDFBundlingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFByteMap.cpp

"$(INTDIR)\JDFByteMap.obj"	"$(INTDIR)\JDFByteMap.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCaseMakingParams.cpp

"$(INTDIR)\JDFCaseMakingParams.obj"	"$(INTDIR)\JDFCaseMakingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCasingInParams.cpp

"$(INTDIR)\JDFCasingInParams.obj"	"$(INTDIR)\JDFCasingInParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFChannelBindingParams.cpp

"$(INTDIR)\JDFChannelBindingParams.obj"	"$(INTDIR)\JDFChannelBindingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCIELABMeasuringField.cpp

"$(INTDIR)\JDFCIELABMeasuringField.obj"	"$(INTDIR)\JDFCIELABMeasuringField.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCoilBindingParams.cpp

"$(INTDIR)\JDFCoilBindingParams.obj"	"$(INTDIR)\JDFCoilBindingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCollectingParams.cpp

"$(INTDIR)\JDFCollectingParams.obj"	"$(INTDIR)\JDFCollectingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFColor.cpp

"$(INTDIR)\JDFColor.obj"	"$(INTDIR)\JDFColor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFColorantAlias.cpp

"$(INTDIR)\JDFColorantAlias.obj"	"$(INTDIR)\JDFColorantAlias.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFColorantControl.cpp

"$(INTDIR)\JDFColorantControl.obj"	"$(INTDIR)\JDFColorantControl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFColorControlStrip.cpp

"$(INTDIR)\JDFColorControlStrip.obj"	"$(INTDIR)\JDFColorControlStrip.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFColorCorrectionParams.cpp

"$(INTDIR)\JDFColorCorrectionParams.obj"	"$(INTDIR)\JDFColorCorrectionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFColorMeasurementConditions.cpp

"$(INTDIR)\JDFColorMeasurementConditions.obj"	"$(INTDIR)\JDFColorMeasurementConditions.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFColorPool.cpp

"$(INTDIR)\JDFColorPool.obj"	"$(INTDIR)\JDFColorPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFColorSpaceConversionOp.cpp

"$(INTDIR)\JDFColorSpaceConversionOp.obj"	"$(INTDIR)\JDFColorSpaceConversionOp.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFColorSpaceConversionParams.cpp

"$(INTDIR)\JDFColorSpaceConversionParams.obj"	"$(INTDIR)\JDFColorSpaceConversionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFComChannel.cpp

"$(INTDIR)\JDFComChannel.obj"	"$(INTDIR)\JDFComChannel.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCompany.cpp

"$(INTDIR)\JDFCompany.obj"	"$(INTDIR)\JDFCompany.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFComponent.cpp

"$(INTDIR)\JDFComponent.obj"	"$(INTDIR)\JDFComponent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFContact.cpp

"$(INTDIR)\JDFContact.obj"	"$(INTDIR)\JDFContact.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFContactCopyParams.cpp

"$(INTDIR)\JDFContactCopyParams.obj"	"$(INTDIR)\JDFContactCopyParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFConventionalPrintingParams.cpp

"$(INTDIR)\JDFConventionalPrintingParams.obj"	"$(INTDIR)\JDFConventionalPrintingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCostCenter.cpp

"$(INTDIR)\JDFCostCenter.obj"	"$(INTDIR)\JDFCostCenter.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCoverApplicationParams.cpp

"$(INTDIR)\JDFCoverApplicationParams.obj"	"$(INTDIR)\JDFCoverApplicationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCreasingParams.cpp

"$(INTDIR)\JDFCreasingParams.obj"	"$(INTDIR)\JDFCreasingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCutBlock.cpp

"$(INTDIR)\JDFCutBlock.obj"	"$(INTDIR)\JDFCutBlock.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCutMark.cpp

"$(INTDIR)\JDFCutMark.obj"	"$(INTDIR)\JDFCutMark.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCuttingParams.cpp

"$(INTDIR)\JDFCuttingParams.obj"	"$(INTDIR)\JDFCuttingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDBMergeParams.cpp

"$(INTDIR)\JDFDBMergeParams.obj"	"$(INTDIR)\JDFDBMergeParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDBRules.cpp

"$(INTDIR)\JDFDBRules.obj"	"$(INTDIR)\JDFDBRules.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDBSchema.cpp

"$(INTDIR)\JDFDBSchema.obj"	"$(INTDIR)\JDFDBSchema.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDBSelection.cpp

"$(INTDIR)\JDFDBSelection.obj"	"$(INTDIR)\JDFDBSelection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDeliveryParams.cpp

"$(INTDIR)\JDFDeliveryParams.obj"	"$(INTDIR)\JDFDeliveryParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDensityMeasuringField.cpp

"$(INTDIR)\JDFDensityMeasuringField.obj"	"$(INTDIR)\JDFDensityMeasuringField.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDevelopingParams.cpp

"$(INTDIR)\JDFDevelopingParams.obj"	"$(INTDIR)\JDFDevelopingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDevice.cpp

"$(INTDIR)\JDFDevice.obj"	"$(INTDIR)\JDFDevice.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceMark.cpp

"$(INTDIR)\JDFDeviceMark.obj"	"$(INTDIR)\JDFDeviceMark.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceNSpace.cpp

"$(INTDIR)\JDFDeviceNSpace.obj"	"$(INTDIR)\JDFDeviceNSpace.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDigitalDeliveryParams.cpp

"$(INTDIR)\JDFDigitalDeliveryParams.obj"	"$(INTDIR)\JDFDigitalDeliveryParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDigitalMedia.cpp

"$(INTDIR)\JDFDigitalMedia.obj"	"$(INTDIR)\JDFDigitalMedia.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDigitalPrintingParams.cpp

"$(INTDIR)\JDFDigitalPrintingParams.obj"	"$(INTDIR)\JDFDigitalPrintingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDisjointing.cpp

"$(INTDIR)\JDFDisjointing.obj"	"$(INTDIR)\JDFDisjointing.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDisposition.cpp

"$(INTDIR)\JDFDisposition.obj"	"$(INTDIR)\JDFDisposition.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDividingParams.cpp

"$(INTDIR)\JDFDividingParams.obj"	"$(INTDIR)\JDFDividingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFElementColorParams.cpp

"$(INTDIR)\JDFElementColorParams.obj"	"$(INTDIR)\JDFElementColorParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFEmbossingParams.cpp

"$(INTDIR)\JDFEmbossingParams.obj"	"$(INTDIR)\JDFEmbossingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFEmployee.cpp

"$(INTDIR)\JDFEmployee.obj"	"$(INTDIR)\JDFEmployee.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFEndSheetGluingParams.cpp

"$(INTDIR)\JDFEndSheetGluingParams.obj"	"$(INTDIR)\JDFEndSheetGluingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFExposedMedia.cpp

"$(INTDIR)\JDFExposedMedia.obj"	"$(INTDIR)\JDFExposedMedia.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFeedingParams.cpp

"$(INTDIR)\JDFFeedingParams.obj"	"$(INTDIR)\JDFFeedingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFileSpec.cpp

"$(INTDIR)\JDFFileSpec.obj"	"$(INTDIR)\JDFFileSpec.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFitPolicy.cpp

"$(INTDIR)\JDFFitPolicy.obj"	"$(INTDIR)\JDFFitPolicy.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFold.cpp

"$(INTDIR)\JDFFold.obj"	"$(INTDIR)\JDFFold.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFoldingParams.cpp

"$(INTDIR)\JDFFoldingParams.obj"	"$(INTDIR)\JDFFoldingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFontParams.cpp

"$(INTDIR)\JDFFontParams.obj"	"$(INTDIR)\JDFFontParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFontPolicy.cpp

"$(INTDIR)\JDFFontPolicy.obj"	"$(INTDIR)\JDFFontPolicy.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFormatConversionParams.cpp

"$(INTDIR)\JDFFormatConversionParams.obj"	"$(INTDIR)\JDFFormatConversionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFGatheringParams.cpp

"$(INTDIR)\JDFGatheringParams.obj"	"$(INTDIR)\JDFGatheringParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFGlueApplication.cpp

"$(INTDIR)\JDFGlueApplication.obj"	"$(INTDIR)\JDFGlueApplication.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFGlueLine.cpp

"$(INTDIR)\JDFGlueLine.obj"	"$(INTDIR)\JDFGlueLine.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFGluingParams.cpp

"$(INTDIR)\JDFGluingParams.obj"	"$(INTDIR)\JDFGluingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFHeadBandApplicationParams.cpp

"$(INTDIR)\JDFHeadBandApplicationParams.obj"	"$(INTDIR)\JDFHeadBandApplicationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFHole.cpp

"$(INTDIR)\JDFHole.obj"	"$(INTDIR)\JDFHole.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFHoleLine.cpp

"$(INTDIR)\JDFHoleLine.obj"	"$(INTDIR)\JDFHoleLine.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFHoleMakingParams.cpp

"$(INTDIR)\JDFHoleMakingParams.obj"	"$(INTDIR)\JDFHoleMakingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIdentificationField.cpp

"$(INTDIR)\JDFIdentificationField.obj"	"$(INTDIR)\JDFIdentificationField.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIDPrintingParams.cpp

"$(INTDIR)\JDFIDPrintingParams.obj"	"$(INTDIR)\JDFIDPrintingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFImageCompressionParams.cpp

"$(INTDIR)\JDFImageCompressionParams.obj"	"$(INTDIR)\JDFImageCompressionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFImageReplacementParams.cpp

"$(INTDIR)\JDFImageReplacementParams.obj"	"$(INTDIR)\JDFImageReplacementParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFImageSetterParams.cpp

"$(INTDIR)\JDFImageSetterParams.obj"	"$(INTDIR)\JDFImageSetterParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFInk.cpp

"$(INTDIR)\JDFInk.obj"	"$(INTDIR)\JDFInk.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFInkZoneCalculationParams.cpp

"$(INTDIR)\JDFInkZoneCalculationParams.obj"	"$(INTDIR)\JDFInkZoneCalculationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFInkZoneProfile.cpp

"$(INTDIR)\JDFInkZoneProfile.obj"	"$(INTDIR)\JDFInkZoneProfile.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFInsertingParams.cpp

"$(INTDIR)\JDFInsertingParams.obj"	"$(INTDIR)\JDFInsertingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFInsertSheet.cpp

"$(INTDIR)\JDFInsertSheet.obj"	"$(INTDIR)\JDFInsertSheet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFInterpretedPDLData.cpp

"$(INTDIR)\JDFInterpretedPDLData.obj"	"$(INTDIR)\JDFInterpretedPDLData.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFInterpretingParams.cpp

"$(INTDIR)\JDFInterpretingParams.obj"	"$(INTDIR)\JDFInterpretingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFJacketingParams.cpp

"$(INTDIR)\JDFJacketingParams.obj"	"$(INTDIR)\JDFJacketingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFJobField.cpp

"$(INTDIR)\JDFJobField.obj"	"$(INTDIR)\JDFJobField.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFLabelingParams.cpp

"$(INTDIR)\JDFLabelingParams.obj"	"$(INTDIR)\JDFLabelingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFLaminatingParams.cpp

"$(INTDIR)\JDFLaminatingParams.obj"	"$(INTDIR)\JDFLaminatingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFLayout.cpp

"$(INTDIR)\JDFLayout.obj"	"$(INTDIR)\JDFLayout.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFLayoutElement.cpp

"$(INTDIR)\JDFLayoutElement.obj"	"$(INTDIR)\JDFLayoutElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFLayoutPreparationParams.cpp

"$(INTDIR)\JDFLayoutPreparationParams.obj"	"$(INTDIR)\JDFLayoutPreparationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFLongitudinalRibbonOperationParams.cpp

"$(INTDIR)\JDFLongitudinalRibbonOperationParams.obj"	"$(INTDIR)\JDFLongitudinalRibbonOperationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFManualLaborParams.cpp

"$(INTDIR)\JDFManualLaborParams.obj"	"$(INTDIR)\JDFManualLaborParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFMedia.cpp

"$(INTDIR)\JDFMedia.obj"	"$(INTDIR)\JDFMedia.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFMediaSource.cpp

"$(INTDIR)\JDFMediaSource.obj"	"$(INTDIR)\JDFMediaSource.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFMISDetails.cpp

"$(INTDIR)\JDFMISDetails.obj"	"$(INTDIR)\JDFMISDetails.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNumberingParams.cpp

"$(INTDIR)\JDFNumberingParams.obj"	"$(INTDIR)\JDFNumberingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFObjectResolution.cpp

"$(INTDIR)\JDFObjectResolution.obj"	"$(INTDIR)\JDFObjectResolution.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFOrderingParams.cpp

"$(INTDIR)\JDFOrderingParams.obj"	"$(INTDIR)\JDFOrderingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPackingParams.cpp

"$(INTDIR)\JDFPackingParams.obj"	"$(INTDIR)\JDFPackingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPageList.cpp

"$(INTDIR)\JDFPageList.obj"	"$(INTDIR)\JDFPageList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPallet.cpp

"$(INTDIR)\JDFPallet.obj"	"$(INTDIR)\JDFPallet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPalletizingParams.cpp

"$(INTDIR)\JDFPalletizingParams.obj"	"$(INTDIR)\JDFPalletizingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPDFToPSConversionParams.cpp

"$(INTDIR)\JDFPDFToPSConversionParams.obj"	"$(INTDIR)\JDFPDFToPSConversionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPDLResourceAlias.cpp

"$(INTDIR)\JDFPDLResourceAlias.obj"	"$(INTDIR)\JDFPDLResourceAlias.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPerforatingParams.cpp

"$(INTDIR)\JDFPerforatingParams.obj"	"$(INTDIR)\JDFPerforatingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPerson.cpp

"$(INTDIR)\JDFPerson.obj"	"$(INTDIR)\JDFPerson.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPlaceHolderResource.cpp

"$(INTDIR)\JDFPlaceHolderResource.obj"	"$(INTDIR)\JDFPlaceHolderResource.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPlasticCombBindingParams.cpp

"$(INTDIR)\JDFPlasticCombBindingParams.obj"	"$(INTDIR)\JDFPlasticCombBindingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPlateCopyParams.cpp

"$(INTDIR)\JDFPlateCopyParams.obj"	"$(INTDIR)\JDFPlateCopyParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightAnalysis.cpp

"$(INTDIR)\JDFPreflightAnalysis.obj"	"$(INTDIR)\JDFPreflightAnalysis.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightInventory.cpp

"$(INTDIR)\JDFPreflightInventory.obj"	"$(INTDIR)\JDFPreflightInventory.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightParams.cpp

"$(INTDIR)\JDFPreflightParams.obj"	"$(INTDIR)\JDFPreflightParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightProfile.cpp

"$(INTDIR)\JDFPreflightProfile.obj"	"$(INTDIR)\JDFPreflightProfile.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightReport.cpp

"$(INTDIR)\JDFPreflightReport.obj"	"$(INTDIR)\JDFPreflightReport.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightReportRulePool.cpp

"$(INTDIR)\JDFPreflightReportRulePool.obj"	"$(INTDIR)\JDFPreflightReportRulePool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPreview.cpp

"$(INTDIR)\JDFPreview.obj"	"$(INTDIR)\JDFPreview.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPreviewGenerationParams.cpp

"$(INTDIR)\JDFPreviewGenerationParams.obj"	"$(INTDIR)\JDFPreviewGenerationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPrintCondition.cpp

"$(INTDIR)\JDFPrintCondition.obj"	"$(INTDIR)\JDFPrintCondition.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPrintRollingParams.cpp

"$(INTDIR)\JDFPrintRollingParams.obj"	"$(INTDIR)\JDFPrintRollingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFProofingParams.cpp

"$(INTDIR)\JDFProofingParams.obj"	"$(INTDIR)\JDFProofingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPSToPDFConversionParams.cpp

"$(INTDIR)\JDFPSToPDFConversionParams.obj"	"$(INTDIR)\JDFPSToPDFConversionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFQualityControlParams.cpp

"$(INTDIR)\JDFQualityControlParams.obj"	"$(INTDIR)\JDFQualityControlParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFQualityControlResult.cpp

"$(INTDIR)\JDFQualityControlResult.obj"	"$(INTDIR)\JDFQualityControlResult.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFRegisterMark.cpp

"$(INTDIR)\JDFRegisterMark.obj"	"$(INTDIR)\JDFRegisterMark.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFRegisterRibbon.cpp

"$(INTDIR)\JDFRegisterRibbon.obj"	"$(INTDIR)\JDFRegisterRibbon.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFRenderingParams.cpp

"$(INTDIR)\JDFRenderingParams.obj"	"$(INTDIR)\JDFRenderingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFResourceDefinitionParams.cpp

"$(INTDIR)\JDFResourceDefinitionParams.obj"	"$(INTDIR)\JDFResourceDefinitionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFRingBindingParams.cpp

"$(INTDIR)\JDFRingBindingParams.obj"	"$(INTDIR)\JDFRingBindingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFRollStand.cpp

"$(INTDIR)\JDFRollStand.obj"	"$(INTDIR)\JDFRollStand.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFRunList.cpp

"$(INTDIR)\JDFRunList.obj"	"$(INTDIR)\JDFRunList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSaddleStitchingParams.cpp

"$(INTDIR)\JDFSaddleStitchingParams.obj"	"$(INTDIR)\JDFSaddleStitchingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFScanParams.cpp

"$(INTDIR)\JDFScanParams.obj"	"$(INTDIR)\JDFScanParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFScavengerArea.cpp

"$(INTDIR)\JDFScavengerArea.obj"	"$(INTDIR)\JDFScavengerArea.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFScreeningParams.cpp

"$(INTDIR)\JDFScreeningParams.obj"	"$(INTDIR)\JDFScreeningParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSeparationControlParams.cpp

"$(INTDIR)\JDFSeparationControlParams.obj"	"$(INTDIR)\JDFSeparationControlParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSeparationSpec.cpp

"$(INTDIR)\JDFSeparationSpec.obj"	"$(INTDIR)\JDFSeparationSpec.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFShapeCuttingParams.cpp

"$(INTDIR)\JDFShapeCuttingParams.obj"	"$(INTDIR)\JDFShapeCuttingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSheet.cpp

"$(INTDIR)\JDFSheet.obj"	"$(INTDIR)\JDFSheet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFShrinkingParams.cpp

"$(INTDIR)\JDFShrinkingParams.obj"	"$(INTDIR)\JDFShrinkingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSideSewingParams.cpp

"$(INTDIR)\JDFSideSewingParams.obj"	"$(INTDIR)\JDFSideSewingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSpinePreparationParams.cpp

"$(INTDIR)\JDFSpinePreparationParams.obj"	"$(INTDIR)\JDFSpinePreparationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSpineTapingParams.cpp

"$(INTDIR)\JDFSpineTapingParams.obj"	"$(INTDIR)\JDFSpineTapingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFStackingParams.cpp

"$(INTDIR)\JDFStackingParams.obj"	"$(INTDIR)\JDFStackingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFStitchingParams.cpp

"$(INTDIR)\JDFStitchingParams.obj"	"$(INTDIR)\JDFStitchingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFStrap.cpp

"$(INTDIR)\JDFStrap.obj"	"$(INTDIR)\JDFStrap.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFStrappingParams.cpp

"$(INTDIR)\JDFStrappingParams.obj"	"$(INTDIR)\JDFStrappingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFStripBindingParams.cpp

"$(INTDIR)\JDFStripBindingParams.obj"	"$(INTDIR)\JDFStripBindingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFStrippingParams.cpp

"$(INTDIR)\JDFStrippingParams.obj"	"$(INTDIR)\JDFStrippingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSurface.cpp

"$(INTDIR)\JDFSurface.obj"	"$(INTDIR)\JDFSurface.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSealingParams.cpp

"$(INTDIR)\JDFThreadSealingParams.obj"	"$(INTDIR)\JDFThreadSealingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSewingParams.cpp

"$(INTDIR)\JDFThreadSewingParams.obj"	"$(INTDIR)\JDFThreadSewingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTile.cpp

"$(INTDIR)\JDFTile.obj"	"$(INTDIR)\JDFTile.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTool.cpp

"$(INTDIR)\JDFTool.obj"	"$(INTDIR)\JDFTool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTransferCurve.cpp

"$(INTDIR)\JDFTransferCurve.obj"	"$(INTDIR)\JDFTransferCurve.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTransferCurvePool.cpp

"$(INTDIR)\JDFTransferCurvePool.obj"	"$(INTDIR)\JDFTransferCurvePool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTransferFunctionControl.cpp

"$(INTDIR)\JDFTransferFunctionControl.obj"	"$(INTDIR)\JDFTransferFunctionControl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTrappingDetails.cpp

"$(INTDIR)\JDFTrappingDetails.obj"	"$(INTDIR)\JDFTrappingDetails.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTrappingParams.cpp

"$(INTDIR)\JDFTrappingParams.obj"	"$(INTDIR)\JDFTrappingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTrapRegion.cpp

"$(INTDIR)\JDFTrapRegion.obj"	"$(INTDIR)\JDFTrapRegion.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTrimmingParams.cpp

"$(INTDIR)\JDFTrimmingParams.obj"	"$(INTDIR)\JDFTrimmingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFVerificationParams.cpp

"$(INTDIR)\JDFVerificationParams.obj"	"$(INTDIR)\JDFVerificationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFWireCombBindingParams.cpp

"$(INTDIR)\JDFWireCombBindingParams.obj"	"$(INTDIR)\JDFWireCombBindingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFWrappingParams.cpp

"$(INTDIR)\JDFWrappingParams.obj"	"$(INTDIR)\JDFWrappingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFAdvancedParams.cpp

"$(INTDIR)\JDFAdvancedParams.obj"	"$(INTDIR)\JDFAdvancedParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFApprovalPerson.cpp

"$(INTDIR)\JDFApprovalPerson.obj"	"$(INTDIR)\JDFApprovalPerson.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFAssemblySection.cpp

"$(INTDIR)\JDFAssemblySection.obj"	"$(INTDIR)\JDFAssemblySection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBand.cpp

"$(INTDIR)\JDFBand.obj"	"$(INTDIR)\JDFBand.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBasicPreflightTest.cpp

"$(INTDIR)\JDFBasicPreflightTest.obj"	"$(INTDIR)\JDFBasicPreflightTest.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBindingQualityParams.cpp

"$(INTDIR)\JDFBindingQualityParams.obj"	"$(INTDIR)\JDFBindingQualityParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBoxArgument.cpp

"$(INTDIR)\JDFBoxArgument.obj"	"$(INTDIR)\JDFBoxArgument.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBoxToBoxDifference.cpp

"$(INTDIR)\JDFBoxToBoxDifference.obj"	"$(INTDIR)\JDFBoxToBoxDifference.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBundleItem.cpp

"$(INTDIR)\JDFBundleItem.obj"	"$(INTDIR)\JDFBundleItem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCCITTFaxParams.cpp

"$(INTDIR)\JDFCCITTFaxParams.obj"	"$(INTDIR)\JDFCCITTFaxParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCollatingItem.cpp

"$(INTDIR)\JDFCollatingItem.obj"	"$(INTDIR)\JDFCollatingItem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFColorantZoneDetails.cpp

"$(INTDIR)\JDFColorantZoneDetails.obj"	"$(INTDIR)\JDFColorantZoneDetails.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFColorCorrectionOp.cpp

"$(INTDIR)\JDFColorCorrectionOp.obj"	"$(INTDIR)\JDFColorCorrectionOp.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFColorSpaceSubstitute.cpp

"$(INTDIR)\JDFColorSpaceSubstitute.obj"	"$(INTDIR)\JDFColorSpaceSubstitute.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFContainer.cpp

"$(INTDIR)\JDFContainer.obj"	"$(INTDIR)\JDFContainer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFContentObject.cpp

"$(INTDIR)\JDFContentObject.obj"	"$(INTDIR)\JDFContentObject.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCrease.cpp

"$(INTDIR)\JDFCrease.obj"	"$(INTDIR)\JDFCrease.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFCut.cpp

"$(INTDIR)\JDFCut.obj"	"$(INTDIR)\JDFCut.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDCTParams.cpp

"$(INTDIR)\JDFDCTParams.obj"	"$(INTDIR)\JDFDCTParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDependencies.cpp

"$(INTDIR)\JDFDependencies.obj"	"$(INTDIR)\JDFDependencies.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceNColor.cpp

"$(INTDIR)\JDFDeviceNColor.obj"	"$(INTDIR)\JDFDeviceNColor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDrop.cpp

"$(INTDIR)\JDFDrop.obj"	"$(INTDIR)\JDFDrop.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDropItem.cpp

"$(INTDIR)\JDFDropItem.obj"	"$(INTDIR)\JDFDropItem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDynamicField.cpp

"$(INTDIR)\JDFDynamicField.obj"	"$(INTDIR)\JDFDynamicField.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDynamicInput.cpp

"$(INTDIR)\JDFDynamicInput.obj"	"$(INTDIR)\JDFDynamicInput.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFEmboss.cpp

"$(INTDIR)\JDFEmboss.obj"	"$(INTDIR)\JDFEmboss.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFEndSheet.cpp

"$(INTDIR)\JDFEndSheet.obj"	"$(INTDIR)\JDFEndSheet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFeeder.cpp

"$(INTDIR)\JDFFeeder.obj"	"$(INTDIR)\JDFFeeder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFeederQualityParams.cpp

"$(INTDIR)\JDFFeederQualityParams.obj"	"$(INTDIR)\JDFFeederQualityParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFileAlias.cpp

"$(INTDIR)\JDFFileAlias.obj"	"$(INTDIR)\JDFFileAlias.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFlateParams.cpp

"$(INTDIR)\JDFFlateParams.obj"	"$(INTDIR)\JDFFlateParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFGlue.cpp

"$(INTDIR)\JDFGlue.obj"	"$(INTDIR)\JDFGlue.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIcon.cpp

"$(INTDIR)\JDFIcon.obj"	"$(INTDIR)\JDFIcon.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIconList.cpp

"$(INTDIR)\JDFIconList.obj"	"$(INTDIR)\JDFIconList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIDPCover.cpp

"$(INTDIR)\JDFIDPCover.obj"	"$(INTDIR)\JDFIDPCover.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIDPFinishing.cpp

"$(INTDIR)\JDFIDPFinishing.obj"	"$(INTDIR)\JDFIDPFinishing.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIDPFolding.cpp

"$(INTDIR)\JDFIDPFolding.obj"	"$(INTDIR)\JDFIDPFolding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIDPHoleMaking.cpp

"$(INTDIR)\JDFIDPHoleMaking.obj"	"$(INTDIR)\JDFIDPHoleMaking.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIDPImageShift.cpp

"$(INTDIR)\JDFIDPImageShift.obj"	"$(INTDIR)\JDFIDPImageShift.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIDPJobSheet.cpp

"$(INTDIR)\JDFIDPJobSheet.obj"	"$(INTDIR)\JDFIDPJobSheet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIDPLayout.cpp

"$(INTDIR)\JDFIDPLayout.obj"	"$(INTDIR)\JDFIDPLayout.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIDPStitching.cpp

"$(INTDIR)\JDFIDPStitching.obj"	"$(INTDIR)\JDFIDPStitching.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIDPTrimming.cpp

"$(INTDIR)\JDFIDPTrimming.obj"	"$(INTDIR)\JDFIDPTrimming.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFImageCompression.cpp

"$(INTDIR)\JDFImageCompression.obj"	"$(INTDIR)\JDFImageCompression.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFImageShift.cpp

"$(INTDIR)\JDFImageShift.obj"	"$(INTDIR)\JDFImageShift.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFLayerDetails.cpp

"$(INTDIR)\JDFLayerDetails.obj"	"$(INTDIR)\JDFLayerDetails.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFLayerList.cpp

"$(INTDIR)\JDFLayerList.obj"	"$(INTDIR)\JDFLayerList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFLongFold.cpp

"$(INTDIR)\JDFLongFold.obj"	"$(INTDIR)\JDFLongFold.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFLongGlue.cpp

"$(INTDIR)\JDFLongGlue.obj"	"$(INTDIR)\JDFLongGlue.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFLongPerforate.cpp

"$(INTDIR)\JDFLongPerforate.obj"	"$(INTDIR)\JDFLongPerforate.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFLongSlit.cpp

"$(INTDIR)\JDFLongSlit.obj"	"$(INTDIR)\JDFLongSlit.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFLZWParams.cpp

"$(INTDIR)\JDFLZWParams.obj"	"$(INTDIR)\JDFLZWParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFMarkObject.cpp

"$(INTDIR)\JDFMarkObject.obj"	"$(INTDIR)\JDFMarkObject.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNumberingParam.cpp

"$(INTDIR)\JDFNumberingParam.obj"	"$(INTDIR)\JDFNumberingParam.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPageCell.cpp

"$(INTDIR)\JDFPageCell.obj"	"$(INTDIR)\JDFPageCell.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPageData.cpp

"$(INTDIR)\JDFPageData.obj"	"$(INTDIR)\JDFPageData.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPDFInterpretingParams.cpp

"$(INTDIR)\JDFPDFInterpretingParams.obj"	"$(INTDIR)\JDFPDFInterpretingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPDFXParams.cpp

"$(INTDIR)\JDFPDFXParams.obj"	"$(INTDIR)\JDFPDFXParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPerforate.cpp

"$(INTDIR)\JDFPerforate.obj"	"$(INTDIR)\JDFPerforate.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPixelColorant.cpp

"$(INTDIR)\JDFPixelColorant.obj"	"$(INTDIR)\JDFPixelColorant.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPosition.cpp

"$(INTDIR)\JDFPosition.obj"	"$(INTDIR)\JDFPosition.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightAction.cpp

"$(INTDIR)\JDFPreflightAction.obj"	"$(INTDIR)\JDFPreflightAction.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightArgument.cpp

"$(INTDIR)\JDFPreflightArgument.obj"	"$(INTDIR)\JDFPreflightArgument.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightConstraint.cpp

"$(INTDIR)\JDFPreflightConstraint.obj"	"$(INTDIR)\JDFPreflightConstraint.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightDetail.cpp

"$(INTDIR)\JDFPreflightDetail.obj"	"$(INTDIR)\JDFPreflightDetail.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightInstance.cpp

"$(INTDIR)\JDFPreflightInstance.obj"	"$(INTDIR)\JDFPreflightInstance.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightInstanceDetail.cpp

"$(INTDIR)\JDFPreflightInstanceDetail.obj"	"$(INTDIR)\JDFPreflightInstanceDetail.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightValue.cpp

"$(INTDIR)\JDFPreflightValue.obj"	"$(INTDIR)\JDFPreflightValue.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPRError.cpp

"$(INTDIR)\JDFPRError.obj"	"$(INTDIR)\JDFPRError.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPRGroup.cpp

"$(INTDIR)\JDFPRGroup.obj"	"$(INTDIR)\JDFPRGroup.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPrintConditionColor.cpp

"$(INTDIR)\JDFPrintConditionColor.obj"	"$(INTDIR)\JDFPrintConditionColor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPRItem.cpp

"$(INTDIR)\JDFPRItem.obj"	"$(INTDIR)\JDFPRItem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPROccurence.cpp

"$(INTDIR)\JDFPROccurence.obj"	"$(INTDIR)\JDFPROccurence.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFProperties.cpp

"$(INTDIR)\JDFProperties.obj"	"$(INTDIR)\JDFProperties.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPRRule.cpp

"$(INTDIR)\JDFPRRule.obj"	"$(INTDIR)\JDFPRRule.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPRRuleAttr.cpp

"$(INTDIR)\JDFPRRuleAttr.obj"	"$(INTDIR)\JDFPRRuleAttr.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFQualityMeasurement.cpp

"$(INTDIR)\JDFQualityMeasurement.obj"	"$(INTDIR)\JDFQualityMeasurement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFResourceParam.cpp

"$(INTDIR)\JDFResourceParam.obj"	"$(INTDIR)\JDFResourceParam.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFScore.cpp

"$(INTDIR)\JDFScore.obj"	"$(INTDIR)\JDFScore.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFScreenSelector.cpp

"$(INTDIR)\JDFScreenSelector.obj"	"$(INTDIR)\JDFScreenSelector.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFShapeElement.cpp

"$(INTDIR)\JDFShapeElement.obj"	"$(INTDIR)\JDFShapeElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSignature.cpp

"$(INTDIR)\JDFSignature.obj"	"$(INTDIR)\JDFSignature.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSignatureCell.cpp

"$(INTDIR)\JDFSignatureCell.obj"	"$(INTDIR)\JDFSignatureCell.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFStringListValue.cpp

"$(INTDIR)\JDFStringListValue.obj"	"$(INTDIR)\JDFStringListValue.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFStripCellParams.cpp

"$(INTDIR)\JDFStripCellParams.obj"	"$(INTDIR)\JDFStripCellParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFThinPDFParams.cpp

"$(INTDIR)\JDFThinPDFParams.obj"	"$(INTDIR)\JDFThinPDFParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTIFFEmbeddedFile.cpp

"$(INTDIR)\JDFTIFFEmbeddedFile.obj"	"$(INTDIR)\JDFTIFFEmbeddedFile.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTIFFFormatParams.cpp

"$(INTDIR)\JDFTIFFFormatParams.obj"	"$(INTDIR)\JDFTIFFFormatParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTIFFtag.cpp

"$(INTDIR)\JDFTIFFtag.obj"	"$(INTDIR)\JDFTIFFtag.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTransferCurveSet.cpp

"$(INTDIR)\JDFTransferCurveSet.obj"	"$(INTDIR)\JDFTransferCurveSet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTrappingOrder.cpp

"$(INTDIR)\JDFTrappingOrder.obj"	"$(INTDIR)\JDFTrappingOrder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFAction.cpp

"$(INTDIR)\JDFAction.obj"	"$(INTDIR)\JDFAction.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFActionPool.cpp

"$(INTDIR)\JDFActionPool.obj"	"$(INTDIR)\JDFActionPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFand.cpp

"$(INTDIR)\JDFand.obj"	"$(INTDIR)\JDFand.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBooleanEvaluation.cpp

"$(INTDIR)\JDFBooleanEvaluation.obj"	"$(INTDIR)\JDFBooleanEvaluation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFBooleanState.cpp

"$(INTDIR)\JDFBooleanState.obj"	"$(INTDIR)\JDFBooleanState.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFcall.cpp

"$(INTDIR)\JDFcall.obj"	"$(INTDIR)\JDFcall.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFchoice.cpp

"$(INTDIR)\JDFchoice.obj"	"$(INTDIR)\JDFchoice.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDateTimeEvaluation.cpp

"$(INTDIR)\JDFDateTimeEvaluation.obj"	"$(INTDIR)\JDFDateTimeEvaluation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDateTimeState.cpp

"$(INTDIR)\JDFDateTimeState.obj"	"$(INTDIR)\JDFDateTimeState.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDevCap.cpp

"$(INTDIR)\JDFDevCap.obj"	"$(INTDIR)\JDFDevCap.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDevCaps.cpp

"$(INTDIR)\JDFDevCaps.obj"	"$(INTDIR)\JDFDevCaps.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceCap.cpp

"$(INTDIR)\JDFDeviceCap.obj"	"$(INTDIR)\JDFDeviceCap.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDisplayGroup.cpp

"$(INTDIR)\JDFDisplayGroup.obj"	"$(INTDIR)\JDFDisplayGroup.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDisplayGroupPool.cpp

"$(INTDIR)\JDFDisplayGroupPool.obj"	"$(INTDIR)\JDFDisplayGroupPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDurationEvaluation.cpp

"$(INTDIR)\JDFDurationEvaluation.obj"	"$(INTDIR)\JDFDurationEvaluation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDurationState.cpp

"$(INTDIR)\JDFDurationState.obj"	"$(INTDIR)\JDFDurationState.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFEnumerationEvaluation.cpp

"$(INTDIR)\JDFEnumerationEvaluation.obj"	"$(INTDIR)\JDFEnumerationEvaluation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFEnumerationState.cpp

"$(INTDIR)\JDFEnumerationState.obj"	"$(INTDIR)\JDFEnumerationState.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFEvaluation.cpp

"$(INTDIR)\JDFEvaluation.obj"	"$(INTDIR)\JDFEvaluation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFeatureAttribute.cpp

"$(INTDIR)\JDFFeatureAttribute.obj"	"$(INTDIR)\JDFFeatureAttribute.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFeaturePool.cpp

"$(INTDIR)\JDFFeaturePool.obj"	"$(INTDIR)\JDFFeaturePool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerEvaluation.cpp

"$(INTDIR)\JDFIntegerEvaluation.obj"	"$(INTDIR)\JDFIntegerEvaluation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerState.cpp

"$(INTDIR)\JDFIntegerState.obj"	"$(INTDIR)\JDFIntegerState.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIsPresentEvaluation.cpp

"$(INTDIR)\JDFIsPresentEvaluation.obj"	"$(INTDIR)\JDFIsPresentEvaluation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFLoc.cpp

"$(INTDIR)\JDFLoc.obj"	"$(INTDIR)\JDFLoc.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFmacro.cpp

"$(INTDIR)\JDFmacro.obj"	"$(INTDIR)\JDFmacro.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFMacroPool.cpp

"$(INTDIR)\JDFMacroPool.obj"	"$(INTDIR)\JDFMacroPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFMatrixEvaluation.cpp

"$(INTDIR)\JDFMatrixEvaluation.obj"	"$(INTDIR)\JDFMatrixEvaluation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFMatrixState.cpp

"$(INTDIR)\JDFMatrixState.obj"	"$(INTDIR)\JDFMatrixState.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNameEvaluation.cpp

"$(INTDIR)\JDFNameEvaluation.obj"	"$(INTDIR)\JDFNameEvaluation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNameState.cpp

"$(INTDIR)\JDFNameState.obj"	"$(INTDIR)\JDFNameState.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFnot.cpp

"$(INTDIR)\JDFnot.obj"	"$(INTDIR)\JDFnot.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNumberEvaluation.cpp

"$(INTDIR)\JDFNumberEvaluation.obj"	"$(INTDIR)\JDFNumberEvaluation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNumberState.cpp

"$(INTDIR)\JDFNumberState.obj"	"$(INTDIR)\JDFNumberState.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFor.cpp

"$(INTDIR)\JDFor.obj"	"$(INTDIR)\JDFor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFotherwise.cpp

"$(INTDIR)\JDFotherwise.obj"	"$(INTDIR)\JDFotherwise.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPDFPathEvaluation.cpp

"$(INTDIR)\JDFPDFPathEvaluation.obj"	"$(INTDIR)\JDFPDFPathEvaluation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPDFPathState.cpp

"$(INTDIR)\JDFPDFPathState.obj"	"$(INTDIR)\JDFPDFPathState.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPerformance.cpp

"$(INTDIR)\JDFPerformance.obj"	"$(INTDIR)\JDFPerformance.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFRectangleEvaluation.cpp

"$(INTDIR)\JDFRectangleEvaluation.obj"	"$(INTDIR)\JDFRectangleEvaluation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFRectangleState.cpp

"$(INTDIR)\JDFRectangleState.obj"	"$(INTDIR)\JDFRectangleState.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFset.cpp

"$(INTDIR)\JDFset.obj"	"$(INTDIR)\JDFset.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFShapeEvaluation.cpp

"$(INTDIR)\JDFShapeEvaluation.obj"	"$(INTDIR)\JDFShapeEvaluation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFShapeState.cpp

"$(INTDIR)\JDFShapeState.obj"	"$(INTDIR)\JDFShapeState.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFState.cpp

"$(INTDIR)\JDFState.obj"	"$(INTDIR)\JDFState.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFStringEvaluation.cpp

"$(INTDIR)\JDFStringEvaluation.obj"	"$(INTDIR)\JDFStringEvaluation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFStringState.cpp

"$(INTDIR)\JDFStringState.obj"	"$(INTDIR)\JDFStringState.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTest.cpp

"$(INTDIR)\JDFTest.obj"	"$(INTDIR)\JDFTest.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTestPool.cpp

"$(INTDIR)\JDFTestPool.obj"	"$(INTDIR)\JDFTestPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFTestRef.cpp

"$(INTDIR)\JDFTestRef.obj"	"$(INTDIR)\JDFTestRef.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFValue.cpp

"$(INTDIR)\JDFValue.obj"	"$(INTDIR)\JDFValue.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFValueLoc.cpp

"$(INTDIR)\JDFValueLoc.obj"	"$(INTDIR)\JDFValueLoc.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFwhen.cpp

"$(INTDIR)\JDFwhen.obj"	"$(INTDIR)\JDFwhen.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFxor.cpp

"$(INTDIR)\JDFxor.obj"	"$(INTDIR)\JDFxor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFXYPairEvaluation.cpp

"$(INTDIR)\JDFXYPairEvaluation.obj"	"$(INTDIR)\JDFXYPairEvaluation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFXYPairState.cpp

"$(INTDIR)\JDFXYPairState.obj"	"$(INTDIR)\JDFXYPairState.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDoc.cpp

"$(INTDIR)\JDFDoc.obj"	"$(INTDIR)\JDFDoc.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFElement.cpp

"$(INTDIR)\JDFElement.obj"	"$(INTDIR)\JDFElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFFactory.cpp

"$(INTDIR)\JDFFactory.obj"	"$(INTDIR)\JDFFactory.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNodeFactory.cpp

"$(INTDIR)\JDFNodeFactory.obj"	"$(INTDIR)\JDFNodeFactory.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFParamsFactory.cpp

"$(INTDIR)\JDFParamsFactory.obj"	"$(INTDIR)\JDFParamsFactory.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPool.cpp

"$(INTDIR)\JDFPool.obj"	"$(INTDIR)\JDFPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFRefElement.cpp

"$(INTDIR)\JDFRefElement.obj"	"$(INTDIR)\JDFRefElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFResource.cpp

"$(INTDIR)\JDFResource.obj"	"$(INTDIR)\JDFResource.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFResourceLink.cpp

"$(INTDIR)\JDFResourceLink.obj"	"$(INTDIR)\JDFResourceLink.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFRunElement.cpp

"$(INTDIR)\JDFRunElement.obj"	"$(INTDIR)\JDFRunElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFSeparationList.cpp

"$(INTDIR)\JDFSeparationList.obj"	"$(INTDIR)\JDFSeparationList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFStrings.cpp

"$(INTDIR)\JDFStrings.obj"	"$(INTDIR)\JDFStrings.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAmountPool.cpp

"$(INTDIR)\JDFAutoAmountPool.obj"	"$(INTDIR)\JDFAutoAmountPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAncestor.cpp

"$(INTDIR)\JDFAutoAncestor.obj"	"$(INTDIR)\JDFAutoAncestor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAncestorPool.cpp

"$(INTDIR)\JDFAutoAncestorPool.obj"	"$(INTDIR)\JDFAutoAncestorPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBarcode.cpp

"$(INTDIR)\JDFAutoBarcode.obj"	"$(INTDIR)\JDFAutoBarcode.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBusinessInfo.cpp

"$(INTDIR)\JDFAutoBusinessInfo.obj"	"$(INTDIR)\JDFAutoBusinessInfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoComment.cpp

"$(INTDIR)\JDFAutoComment.obj"	"$(INTDIR)\JDFAutoComment.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCounterReset.cpp

"$(INTDIR)\JDFAutoCounterReset.obj"	"$(INTDIR)\JDFAutoCounterReset.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCreated.cpp

"$(INTDIR)\JDFAutoCreated.obj"	"$(INTDIR)\JDFAutoCreated.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCustomerInfo.cpp

"$(INTDIR)\JDFAutoCustomerInfo.obj"	"$(INTDIR)\JDFAutoCustomerInfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCustomerMessage.cpp

"$(INTDIR)\JDFAutoCustomerMessage.obj"	"$(INTDIR)\JDFAutoCustomerMessage.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeleted.cpp

"$(INTDIR)\JDFAutoDeleted.obj"	"$(INTDIR)\JDFAutoDeleted.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoError.cpp

"$(INTDIR)\JDFAutoError.obj"	"$(INTDIR)\JDFAutoError.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEvent.cpp

"$(INTDIR)\JDFAutoEvent.obj"	"$(INTDIR)\JDFAutoEvent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFCNKey.cpp

"$(INTDIR)\JDFAutoFCNKey.obj"	"$(INTDIR)\JDFAutoFCNKey.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLocation.cpp

"$(INTDIR)\JDFAutoLocation.obj"	"$(INTDIR)\JDFAutoLocation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMerged.cpp

"$(INTDIR)\JDFAutoMerged.obj"	"$(INTDIR)\JDFAutoMerged.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoModified.cpp

"$(INTDIR)\JDFAutoModified.obj"	"$(INTDIR)\JDFAutoModified.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoModulePhase.cpp

"$(INTDIR)\JDFAutoModulePhase.obj"	"$(INTDIR)\JDFAutoModulePhase.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInfo.cpp

"$(INTDIR)\JDFAutoNodeInfo.obj"	"$(INTDIR)\JDFAutoNodeInfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNotification.cpp

"$(INTDIR)\JDFAutoNotification.obj"	"$(INTDIR)\JDFAutoNotification.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPart.cpp

"$(INTDIR)\JDFAutoPart.obj"	"$(INTDIR)\JDFAutoPart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPartStatus.cpp

"$(INTDIR)\JDFAutoPartStatus.obj"	"$(INTDIR)\JDFAutoPartStatus.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPhaseTime.cpp

"$(INTDIR)\JDFAutoPhaseTime.obj"	"$(INTDIR)\JDFAutoPhaseTime.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProcessRun.cpp

"$(INTDIR)\JDFAutoProcessRun.obj"	"$(INTDIR)\JDFAutoProcessRun.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceAudit.cpp

"$(INTDIR)\JDFAutoResourceAudit.obj"	"$(INTDIR)\JDFAutoResourceAudit.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSpawned.cpp

"$(INTDIR)\JDFAutoSpawned.obj"	"$(INTDIR)\JDFAutoSpawned.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStatusPool.cpp

"$(INTDIR)\JDFAutoStatusPool.obj"	"$(INTDIR)\JDFAutoStatusPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSystemTimeSet.cpp

"$(INTDIR)\JDFAutoSystemTimeSet.obj"	"$(INTDIR)\JDFAutoSystemTimeSet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAcknowledge.cpp

"$(INTDIR)\JDFAutoAcknowledge.obj"	"$(INTDIR)\JDFAutoAcknowledge.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdded.cpp

"$(INTDIR)\JDFAutoAdded.obj"	"$(INTDIR)\JDFAutoAdded.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoChangedAttribute.cpp

"$(INTDIR)\JDFAutoChangedAttribute.obj"	"$(INTDIR)\JDFAutoChangedAttribute.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoChangedPath.cpp

"$(INTDIR)\JDFAutoChangedPath.obj"	"$(INTDIR)\JDFAutoChangedPath.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCommand.cpp

"$(INTDIR)\JDFAutoCommand.obj"	"$(INTDIR)\JDFAutoCommand.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceFilter.cpp

"$(INTDIR)\JDFAutoDeviceFilter.obj"	"$(INTDIR)\JDFAutoDeviceFilter.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceInfo.cpp

"$(INTDIR)\JDFAutoDeviceInfo.obj"	"$(INTDIR)\JDFAutoDeviceInfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceList.cpp

"$(INTDIR)\JDFAutoDeviceList.obj"	"$(INTDIR)\JDFAutoDeviceList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmployeeDef.cpp

"$(INTDIR)\JDFAutoEmployeeDef.obj"	"$(INTDIR)\JDFAutoEmployeeDef.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFlushedResources.cpp

"$(INTDIR)\JDFAutoFlushedResources.obj"	"$(INTDIR)\JDFAutoFlushedResources.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFlushQueueParams.cpp

"$(INTDIR)\JDFAutoFlushQueueParams.obj"	"$(INTDIR)\JDFAutoFlushQueueParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFlushResourceParams.cpp

"$(INTDIR)\JDFAutoFlushResourceParams.obj"	"$(INTDIR)\JDFAutoFlushResourceParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDInfo.cpp

"$(INTDIR)\JDFAutoIDInfo.obj"	"$(INTDIR)\JDFAutoIDInfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJDFController.cpp

"$(INTDIR)\JDFAutoJDFController.obj"	"$(INTDIR)\JDFAutoJDFController.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJDFService.cpp

"$(INTDIR)\JDFAutoJDFService.obj"	"$(INTDIR)\JDFAutoJDFService.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMF.cpp

"$(INTDIR)\JDFAutoJMF.obj"	"$(INTDIR)\JDFAutoJMF.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJobPhase.cpp

"$(INTDIR)\JDFAutoJobPhase.obj"	"$(INTDIR)\JDFAutoJobPhase.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoKnownMsgQuParams.cpp

"$(INTDIR)\JDFAutoKnownMsgQuParams.obj"	"$(INTDIR)\JDFAutoKnownMsgQuParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMessage.cpp

"$(INTDIR)\JDFAutoMessage.obj"	"$(INTDIR)\JDFAutoMessage.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMessageService.cpp

"$(INTDIR)\JDFAutoMessageService.obj"	"$(INTDIR)\JDFAutoMessageService.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoModuleStatus.cpp

"$(INTDIR)\JDFAutoModuleStatus.obj"	"$(INTDIR)\JDFAutoModuleStatus.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMsgFilter.cpp

"$(INTDIR)\JDFAutoMsgFilter.obj"	"$(INTDIR)\JDFAutoMsgFilter.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNewJDFCmdParams.cpp

"$(INTDIR)\JDFAutoNewJDFCmdParams.obj"	"$(INTDIR)\JDFAutoNewJDFCmdParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNewJDFQuParams.cpp

"$(INTDIR)\JDFAutoNewJDFQuParams.obj"	"$(INTDIR)\JDFAutoNewJDFQuParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInfoCmdParams.cpp

"$(INTDIR)\JDFAutoNodeInfoCmdParams.obj"	"$(INTDIR)\JDFAutoNodeInfoCmdParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInfoQuParams.cpp

"$(INTDIR)\JDFAutoNodeInfoQuParams.obj"	"$(INTDIR)\JDFAutoNodeInfoQuParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInfoResp.cpp

"$(INTDIR)\JDFAutoNodeInfoResp.obj"	"$(INTDIR)\JDFAutoNodeInfoResp.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNotificationDef.cpp

"$(INTDIR)\JDFAutoNotificationDef.obj"	"$(INTDIR)\JDFAutoNotificationDef.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNotificationFilter.cpp

"$(INTDIR)\JDFAutoNotificationFilter.obj"	"$(INTDIR)\JDFAutoNotificationFilter.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoObservationTarget.cpp

"$(INTDIR)\JDFAutoObservationTarget.obj"	"$(INTDIR)\JDFAutoObservationTarget.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoOccupation.cpp

"$(INTDIR)\JDFAutoOccupation.obj"	"$(INTDIR)\JDFAutoOccupation.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPipeParams.cpp

"$(INTDIR)\JDFAutoPipeParams.obj"	"$(INTDIR)\JDFAutoPipeParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQuery.cpp

"$(INTDIR)\JDFAutoQuery.obj"	"$(INTDIR)\JDFAutoQuery.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueue.cpp

"$(INTDIR)\JDFAutoQueue.obj"	"$(INTDIR)\JDFAutoQueue.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntry.cpp

"$(INTDIR)\JDFAutoQueueEntry.obj"	"$(INTDIR)\JDFAutoQueueEntry.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntryDef.cpp

"$(INTDIR)\JDFAutoQueueEntryDef.obj"	"$(INTDIR)\JDFAutoQueueEntryDef.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntryDefList.cpp

"$(INTDIR)\JDFAutoQueueEntryDefList.obj"	"$(INTDIR)\JDFAutoQueueEntryDefList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntryPosParams.cpp

"$(INTDIR)\JDFAutoQueueEntryPosParams.obj"	"$(INTDIR)\JDFAutoQueueEntryPosParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntryPriParams.cpp

"$(INTDIR)\JDFAutoQueueEntryPriParams.obj"	"$(INTDIR)\JDFAutoQueueEntryPriParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueFilter.cpp

"$(INTDIR)\JDFAutoQueueFilter.obj"	"$(INTDIR)\JDFAutoQueueFilter.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueSubmissionParams.cpp

"$(INTDIR)\JDFAutoQueueSubmissionParams.obj"	"$(INTDIR)\JDFAutoQueueSubmissionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRemoved.cpp

"$(INTDIR)\JDFAutoRemoved.obj"	"$(INTDIR)\JDFAutoRemoved.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRequestQueueEntryParams.cpp

"$(INTDIR)\JDFAutoRequestQueueEntryParams.obj"	"$(INTDIR)\JDFAutoRequestQueueEntryParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceCmdParams.cpp

"$(INTDIR)\JDFAutoResourceCmdParams.obj"	"$(INTDIR)\JDFAutoResourceCmdParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceInfo.cpp

"$(INTDIR)\JDFAutoResourceInfo.obj"	"$(INTDIR)\JDFAutoResourceInfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourcePullParams.cpp

"$(INTDIR)\JDFAutoResourcePullParams.obj"	"$(INTDIR)\JDFAutoResourcePullParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceQuParams.cpp

"$(INTDIR)\JDFAutoResourceQuParams.obj"	"$(INTDIR)\JDFAutoResourceQuParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResponse.cpp

"$(INTDIR)\JDFAutoResponse.obj"	"$(INTDIR)\JDFAutoResponse.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResubmissionParams.cpp

"$(INTDIR)\JDFAutoResubmissionParams.obj"	"$(INTDIR)\JDFAutoResubmissionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoReturnQueueEntryParams.cpp

"$(INTDIR)\JDFAutoReturnQueueEntryParams.obj"	"$(INTDIR)\JDFAutoReturnQueueEntryParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShutDownCmdParams.cpp

"$(INTDIR)\JDFAutoShutDownCmdParams.obj"	"$(INTDIR)\JDFAutoShutDownCmdParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSignal.cpp

"$(INTDIR)\JDFAutoSignal.obj"	"$(INTDIR)\JDFAutoSignal.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStatusQuParams.cpp

"$(INTDIR)\JDFAutoStatusQuParams.obj"	"$(INTDIR)\JDFAutoStatusQuParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStopPersChParams.cpp

"$(INTDIR)\JDFAutoStopPersChParams.obj"	"$(INTDIR)\JDFAutoStopPersChParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSubmissionMethods.cpp

"$(INTDIR)\JDFAutoSubmissionMethods.obj"	"$(INTDIR)\JDFAutoSubmissionMethods.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSubscription.cpp

"$(INTDIR)\JDFAutoSubscription.obj"	"$(INTDIR)\JDFAutoSubscription.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrackFilter.cpp

"$(INTDIR)\JDFAutoTrackFilter.obj"	"$(INTDIR)\JDFAutoTrackFilter.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrackResult.cpp

"$(INTDIR)\JDFAutoTrackResult.obj"	"$(INTDIR)\JDFAutoTrackResult.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrigger.cpp

"$(INTDIR)\JDFAutoTrigger.obj"	"$(INTDIR)\JDFAutoTrigger.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWakeUpCmdParams.cpp

"$(INTDIR)\JDFAutoWakeUpCmdParams.obj"	"$(INTDIR)\JDFAutoWakeUpCmdParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoArtDeliveryIntent.cpp

"$(INTDIR)\JDFAutoArtDeliveryIntent.obj"	"$(INTDIR)\JDFAutoArtDeliveryIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBindingIntent.cpp

"$(INTDIR)\JDFAutoBindingIntent.obj"	"$(INTDIR)\JDFAutoBindingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorIntent.cpp

"$(INTDIR)\JDFAutoColorIntent.obj"	"$(INTDIR)\JDFAutoColorIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeliveryIntent.cpp

"$(INTDIR)\JDFAutoDeliveryIntent.obj"	"$(INTDIR)\JDFAutoDeliveryIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmbossingIntent.cpp

"$(INTDIR)\JDFAutoEmbossingIntent.obj"	"$(INTDIR)\JDFAutoEmbossingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFoldingIntent.cpp

"$(INTDIR)\JDFAutoFoldingIntent.obj"	"$(INTDIR)\JDFAutoFoldingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHoleMakingIntent.cpp

"$(INTDIR)\JDFAutoHoleMakingIntent.obj"	"$(INTDIR)\JDFAutoHoleMakingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertingIntent.cpp

"$(INTDIR)\JDFAutoInsertingIntent.obj"	"$(INTDIR)\JDFAutoInsertingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLaminatingIntent.cpp

"$(INTDIR)\JDFAutoLaminatingIntent.obj"	"$(INTDIR)\JDFAutoLaminatingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayoutIntent.cpp

"$(INTDIR)\JDFAutoLayoutIntent.obj"	"$(INTDIR)\JDFAutoLayoutIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMediaIntent.cpp

"$(INTDIR)\JDFAutoMediaIntent.obj"	"$(INTDIR)\JDFAutoMediaIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNumberingIntent.cpp

"$(INTDIR)\JDFAutoNumberingIntent.obj"	"$(INTDIR)\JDFAutoNumberingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPackingIntent.cpp

"$(INTDIR)\JDFAutoPackingIntent.obj"	"$(INTDIR)\JDFAutoPackingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProductionIntent.cpp

"$(INTDIR)\JDFAutoProductionIntent.obj"	"$(INTDIR)\JDFAutoProductionIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProofingIntent.cpp

"$(INTDIR)\JDFAutoProofingIntent.obj"	"$(INTDIR)\JDFAutoProofingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScreeningIntent.cpp

"$(INTDIR)\JDFAutoScreeningIntent.obj"	"$(INTDIR)\JDFAutoScreeningIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShapeCuttingIntent.cpp

"$(INTDIR)\JDFAutoShapeCuttingIntent.obj"	"$(INTDIR)\JDFAutoShapeCuttingIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSizeIntent.cpp

"$(INTDIR)\JDFAutoSizeIntent.obj"	"$(INTDIR)\JDFAutoSizeIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdhesiveBinding.cpp

"$(INTDIR)\JDFAutoAdhesiveBinding.obj"	"$(INTDIR)\JDFAutoAdhesiveBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoArtDelivery.cpp

"$(INTDIR)\JDFAutoArtDelivery.obj"	"$(INTDIR)\JDFAutoArtDelivery.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBindItem.cpp

"$(INTDIR)\JDFAutoBindItem.obj"	"$(INTDIR)\JDFAutoBindItem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBindList.cpp

"$(INTDIR)\JDFAutoBindList.obj"	"$(INTDIR)\JDFAutoBindList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBookCase.cpp

"$(INTDIR)\JDFAutoBookCase.obj"	"$(INTDIR)\JDFAutoBookCase.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoChannelBinding.cpp

"$(INTDIR)\JDFAutoChannelBinding.obj"	"$(INTDIR)\JDFAutoChannelBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCoilBinding.cpp

"$(INTDIR)\JDFAutoCoilBinding.obj"	"$(INTDIR)\JDFAutoCoilBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorsUsed.cpp

"$(INTDIR)\JDFAutoColorsUsed.obj"	"$(INTDIR)\JDFAutoColorsUsed.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCreditCard.cpp

"$(INTDIR)\JDFAutoCreditCard.obj"	"$(INTDIR)\JDFAutoCreditCard.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDropIntent.cpp

"$(INTDIR)\JDFAutoDropIntent.obj"	"$(INTDIR)\JDFAutoDropIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDropItemIntent.cpp

"$(INTDIR)\JDFAutoDropItemIntent.obj"	"$(INTDIR)\JDFAutoDropItemIntent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEdgeGluing.cpp

"$(INTDIR)\JDFAutoEdgeGluing.obj"	"$(INTDIR)\JDFAutoEdgeGluing.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmbossingItem.cpp

"$(INTDIR)\JDFAutoEmbossingItem.obj"	"$(INTDIR)\JDFAutoEmbossingItem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHardCoverBinding.cpp

"$(INTDIR)\JDFAutoHardCoverBinding.obj"	"$(INTDIR)\JDFAutoHardCoverBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHoleList.cpp

"$(INTDIR)\JDFAutoHoleList.obj"	"$(INTDIR)\JDFAutoHoleList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsert.cpp

"$(INTDIR)\JDFAutoInsert.obj"	"$(INTDIR)\JDFAutoInsert.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertList.cpp

"$(INTDIR)\JDFAutoInsertList.obj"	"$(INTDIR)\JDFAutoInsertList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNumberItem.cpp

"$(INTDIR)\JDFAutoNumberItem.obj"	"$(INTDIR)\JDFAutoNumberItem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPayment.cpp

"$(INTDIR)\JDFAutoPayment.obj"	"$(INTDIR)\JDFAutoPayment.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlasticCombBinding.cpp

"$(INTDIR)\JDFAutoPlasticCombBinding.obj"	"$(INTDIR)\JDFAutoPlasticCombBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPricing.cpp

"$(INTDIR)\JDFAutoPricing.obj"	"$(INTDIR)\JDFAutoPricing.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProofItem.cpp

"$(INTDIR)\JDFAutoProofItem.obj"	"$(INTDIR)\JDFAutoProofItem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRingBinding.cpp

"$(INTDIR)\JDFAutoRingBinding.obj"	"$(INTDIR)\JDFAutoRingBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSaddleStitching.cpp

"$(INTDIR)\JDFAutoSaddleStitching.obj"	"$(INTDIR)\JDFAutoSaddleStitching.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShapeCut.cpp

"$(INTDIR)\JDFAutoShapeCut.obj"	"$(INTDIR)\JDFAutoShapeCut.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSideSewing.cpp

"$(INTDIR)\JDFAutoSideSewing.obj"	"$(INTDIR)\JDFAutoSideSewing.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSideStitching.cpp

"$(INTDIR)\JDFAutoSideStitching.obj"	"$(INTDIR)\JDFAutoSideStitching.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSoftCoverBinding.cpp

"$(INTDIR)\JDFAutoSoftCoverBinding.obj"	"$(INTDIR)\JDFAutoSoftCoverBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStripBinding.cpp

"$(INTDIR)\JDFAutoStripBinding.obj"	"$(INTDIR)\JDFAutoStripBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTabs.cpp

"$(INTDIR)\JDFAutoTabs.obj"	"$(INTDIR)\JDFAutoTabs.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTape.cpp

"$(INTDIR)\JDFAutoTape.obj"	"$(INTDIR)\JDFAutoTape.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSealing.cpp

"$(INTDIR)\JDFAutoThreadSealing.obj"	"$(INTDIR)\JDFAutoThreadSealing.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSewing.cpp

"$(INTDIR)\JDFAutoThreadSewing.obj"	"$(INTDIR)\JDFAutoThreadSewing.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWireCombBinding.cpp

"$(INTDIR)\JDFAutoWireCombBinding.obj"	"$(INTDIR)\JDFAutoWireCombBinding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAddress.cpp

"$(INTDIR)\JDFAutoAddress.obj"	"$(INTDIR)\JDFAutoAddress.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdhesiveBindingParams.cpp

"$(INTDIR)\JDFAutoAdhesiveBindingParams.obj"	"$(INTDIR)\JDFAutoAdhesiveBindingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoApprovalParams.cpp

"$(INTDIR)\JDFAutoApprovalParams.obj"	"$(INTDIR)\JDFAutoApprovalParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoApprovalSuccess.cpp

"$(INTDIR)\JDFAutoApprovalSuccess.obj"	"$(INTDIR)\JDFAutoApprovalSuccess.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAssembly.cpp

"$(INTDIR)\JDFAutoAssembly.obj"	"$(INTDIR)\JDFAutoAssembly.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAssetListCreationParams.cpp

"$(INTDIR)\JDFAutoAssetListCreationParams.obj"	"$(INTDIR)\JDFAutoAssetListCreationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAutomatedOverprintParams.cpp

"$(INTDIR)\JDFAutoAutomatedOverprintParams.obj"	"$(INTDIR)\JDFAutoAutomatedOverprintParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBinderySignature.cpp

"$(INTDIR)\JDFAutoBinderySignature.obj"	"$(INTDIR)\JDFAutoBinderySignature.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBlockPreparationParams.cpp

"$(INTDIR)\JDFAutoBlockPreparationParams.obj"	"$(INTDIR)\JDFAutoBlockPreparationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBoxPackingParams.cpp

"$(INTDIR)\JDFAutoBoxPackingParams.obj"	"$(INTDIR)\JDFAutoBoxPackingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBufferParams.cpp

"$(INTDIR)\JDFAutoBufferParams.obj"	"$(INTDIR)\JDFAutoBufferParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBundle.cpp

"$(INTDIR)\JDFAutoBundle.obj"	"$(INTDIR)\JDFAutoBundle.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBundlingParams.cpp

"$(INTDIR)\JDFAutoBundlingParams.obj"	"$(INTDIR)\JDFAutoBundlingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoByteMap.cpp

"$(INTDIR)\JDFAutoByteMap.obj"	"$(INTDIR)\JDFAutoByteMap.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCaseMakingParams.cpp

"$(INTDIR)\JDFAutoCaseMakingParams.obj"	"$(INTDIR)\JDFAutoCaseMakingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCasingInParams.cpp

"$(INTDIR)\JDFAutoCasingInParams.obj"	"$(INTDIR)\JDFAutoCasingInParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoChannelBindingParams.cpp

"$(INTDIR)\JDFAutoChannelBindingParams.obj"	"$(INTDIR)\JDFAutoChannelBindingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCIELABMeasuringField.cpp

"$(INTDIR)\JDFAutoCIELABMeasuringField.obj"	"$(INTDIR)\JDFAutoCIELABMeasuringField.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCoilBindingParams.cpp

"$(INTDIR)\JDFAutoCoilBindingParams.obj"	"$(INTDIR)\JDFAutoCoilBindingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCollectingParams.cpp

"$(INTDIR)\JDFAutoCollectingParams.obj"	"$(INTDIR)\JDFAutoCollectingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColor.cpp

"$(INTDIR)\JDFAutoColor.obj"	"$(INTDIR)\JDFAutoColor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantAlias.cpp

"$(INTDIR)\JDFAutoColorantAlias.obj"	"$(INTDIR)\JDFAutoColorantAlias.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantControl.cpp

"$(INTDIR)\JDFAutoColorantControl.obj"	"$(INTDIR)\JDFAutoColorantControl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorControlStrip.cpp

"$(INTDIR)\JDFAutoColorControlStrip.obj"	"$(INTDIR)\JDFAutoColorControlStrip.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorCorrectionParams.cpp

"$(INTDIR)\JDFAutoColorCorrectionParams.obj"	"$(INTDIR)\JDFAutoColorCorrectionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorMeasurementConditions.cpp

"$(INTDIR)\JDFAutoColorMeasurementConditions.obj"	"$(INTDIR)\JDFAutoColorMeasurementConditions.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorPool.cpp

"$(INTDIR)\JDFAutoColorPool.obj"	"$(INTDIR)\JDFAutoColorPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorSpaceConversionOp.cpp

"$(INTDIR)\JDFAutoColorSpaceConversionOp.obj"	"$(INTDIR)\JDFAutoColorSpaceConversionOp.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorSpaceConversionParams.cpp

"$(INTDIR)\JDFAutoColorSpaceConversionParams.obj"	"$(INTDIR)\JDFAutoColorSpaceConversionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoComChannel.cpp

"$(INTDIR)\JDFAutoComChannel.obj"	"$(INTDIR)\JDFAutoComChannel.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCompany.cpp

"$(INTDIR)\JDFAutoCompany.obj"	"$(INTDIR)\JDFAutoCompany.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoComponent.cpp

"$(INTDIR)\JDFAutoComponent.obj"	"$(INTDIR)\JDFAutoComponent.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContact.cpp

"$(INTDIR)\JDFAutoContact.obj"	"$(INTDIR)\JDFAutoContact.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContactCopyParams.cpp

"$(INTDIR)\JDFAutoContactCopyParams.obj"	"$(INTDIR)\JDFAutoContactCopyParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoConventionalPrintingParams.cpp

"$(INTDIR)\JDFAutoConventionalPrintingParams.obj"	"$(INTDIR)\JDFAutoConventionalPrintingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCostCenter.cpp

"$(INTDIR)\JDFAutoCostCenter.obj"	"$(INTDIR)\JDFAutoCostCenter.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCoverApplicationParams.cpp

"$(INTDIR)\JDFAutoCoverApplicationParams.obj"	"$(INTDIR)\JDFAutoCoverApplicationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCreasingParams.cpp

"$(INTDIR)\JDFAutoCreasingParams.obj"	"$(INTDIR)\JDFAutoCreasingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCutBlock.cpp

"$(INTDIR)\JDFAutoCutBlock.obj"	"$(INTDIR)\JDFAutoCutBlock.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCutMark.cpp

"$(INTDIR)\JDFAutoCutMark.obj"	"$(INTDIR)\JDFAutoCutMark.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCuttingParams.cpp

"$(INTDIR)\JDFAutoCuttingParams.obj"	"$(INTDIR)\JDFAutoCuttingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDBMergeParams.cpp

"$(INTDIR)\JDFAutoDBMergeParams.obj"	"$(INTDIR)\JDFAutoDBMergeParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDBRules.cpp

"$(INTDIR)\JDFAutoDBRules.obj"	"$(INTDIR)\JDFAutoDBRules.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDBSchema.cpp

"$(INTDIR)\JDFAutoDBSchema.obj"	"$(INTDIR)\JDFAutoDBSchema.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDBSelection.cpp

"$(INTDIR)\JDFAutoDBSelection.obj"	"$(INTDIR)\JDFAutoDBSelection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeliveryParams.cpp

"$(INTDIR)\JDFAutoDeliveryParams.obj"	"$(INTDIR)\JDFAutoDeliveryParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDensityMeasuringField.cpp

"$(INTDIR)\JDFAutoDensityMeasuringField.obj"	"$(INTDIR)\JDFAutoDensityMeasuringField.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDevelopingParams.cpp

"$(INTDIR)\JDFAutoDevelopingParams.obj"	"$(INTDIR)\JDFAutoDevelopingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDevice.cpp

"$(INTDIR)\JDFAutoDevice.obj"	"$(INTDIR)\JDFAutoDevice.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceMark.cpp

"$(INTDIR)\JDFAutoDeviceMark.obj"	"$(INTDIR)\JDFAutoDeviceMark.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceNSpace.cpp

"$(INTDIR)\JDFAutoDeviceNSpace.obj"	"$(INTDIR)\JDFAutoDeviceNSpace.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDigitalDeliveryParams.cpp

"$(INTDIR)\JDFAutoDigitalDeliveryParams.obj"	"$(INTDIR)\JDFAutoDigitalDeliveryParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDigitalMedia.cpp

"$(INTDIR)\JDFAutoDigitalMedia.obj"	"$(INTDIR)\JDFAutoDigitalMedia.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDigitalPrintingParams.cpp

"$(INTDIR)\JDFAutoDigitalPrintingParams.obj"	"$(INTDIR)\JDFAutoDigitalPrintingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDisjointing.cpp

"$(INTDIR)\JDFAutoDisjointing.obj"	"$(INTDIR)\JDFAutoDisjointing.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDisposition.cpp

"$(INTDIR)\JDFAutoDisposition.obj"	"$(INTDIR)\JDFAutoDisposition.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDividingParams.cpp

"$(INTDIR)\JDFAutoDividingParams.obj"	"$(INTDIR)\JDFAutoDividingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoElementColorParams.cpp

"$(INTDIR)\JDFAutoElementColorParams.obj"	"$(INTDIR)\JDFAutoElementColorParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmbossingParams.cpp

"$(INTDIR)\JDFAutoEmbossingParams.obj"	"$(INTDIR)\JDFAutoEmbossingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmployee.cpp

"$(INTDIR)\JDFAutoEmployee.obj"	"$(INTDIR)\JDFAutoEmployee.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEndSheetGluingParams.cpp

"$(INTDIR)\JDFAutoEndSheetGluingParams.obj"	"$(INTDIR)\JDFAutoEndSheetGluingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoExposedMedia.cpp

"$(INTDIR)\JDFAutoExposedMedia.obj"	"$(INTDIR)\JDFAutoExposedMedia.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFeedingParams.cpp

"$(INTDIR)\JDFAutoFeedingParams.obj"	"$(INTDIR)\JDFAutoFeedingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFileSpec.cpp

"$(INTDIR)\JDFAutoFileSpec.obj"	"$(INTDIR)\JDFAutoFileSpec.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFitPolicy.cpp

"$(INTDIR)\JDFAutoFitPolicy.obj"	"$(INTDIR)\JDFAutoFitPolicy.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFold.cpp

"$(INTDIR)\JDFAutoFold.obj"	"$(INTDIR)\JDFAutoFold.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFoldingParams.cpp

"$(INTDIR)\JDFAutoFoldingParams.obj"	"$(INTDIR)\JDFAutoFoldingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFontParams.cpp

"$(INTDIR)\JDFAutoFontParams.obj"	"$(INTDIR)\JDFAutoFontParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFontPolicy.cpp

"$(INTDIR)\JDFAutoFontPolicy.obj"	"$(INTDIR)\JDFAutoFontPolicy.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFormatConversionParams.cpp

"$(INTDIR)\JDFAutoFormatConversionParams.obj"	"$(INTDIR)\JDFAutoFormatConversionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGatheringParams.cpp

"$(INTDIR)\JDFAutoGatheringParams.obj"	"$(INTDIR)\JDFAutoGatheringParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGlueApplication.cpp

"$(INTDIR)\JDFAutoGlueApplication.obj"	"$(INTDIR)\JDFAutoGlueApplication.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGlueLine.cpp

"$(INTDIR)\JDFAutoGlueLine.obj"	"$(INTDIR)\JDFAutoGlueLine.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGluingParams.cpp

"$(INTDIR)\JDFAutoGluingParams.obj"	"$(INTDIR)\JDFAutoGluingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHeadBandApplicationParams.cpp

"$(INTDIR)\JDFAutoHeadBandApplicationParams.obj"	"$(INTDIR)\JDFAutoHeadBandApplicationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHole.cpp

"$(INTDIR)\JDFAutoHole.obj"	"$(INTDIR)\JDFAutoHole.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHoleLine.cpp

"$(INTDIR)\JDFAutoHoleLine.obj"	"$(INTDIR)\JDFAutoHoleLine.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHoleMakingParams.cpp

"$(INTDIR)\JDFAutoHoleMakingParams.obj"	"$(INTDIR)\JDFAutoHoleMakingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIdentificationField.cpp

"$(INTDIR)\JDFAutoIdentificationField.obj"	"$(INTDIR)\JDFAutoIdentificationField.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPrintingParams.cpp

"$(INTDIR)\JDFAutoIDPrintingParams.obj"	"$(INTDIR)\JDFAutoIDPrintingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoImageCompressionParams.cpp

"$(INTDIR)\JDFAutoImageCompressionParams.obj"	"$(INTDIR)\JDFAutoImageCompressionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoImageReplacementParams.cpp

"$(INTDIR)\JDFAutoImageReplacementParams.obj"	"$(INTDIR)\JDFAutoImageReplacementParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoImageSetterParams.cpp

"$(INTDIR)\JDFAutoImageSetterParams.obj"	"$(INTDIR)\JDFAutoImageSetterParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInk.cpp

"$(INTDIR)\JDFAutoInk.obj"	"$(INTDIR)\JDFAutoInk.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInkZoneCalculationParams.cpp

"$(INTDIR)\JDFAutoInkZoneCalculationParams.obj"	"$(INTDIR)\JDFAutoInkZoneCalculationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInkZoneProfile.cpp

"$(INTDIR)\JDFAutoInkZoneProfile.obj"	"$(INTDIR)\JDFAutoInkZoneProfile.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertingParams.cpp

"$(INTDIR)\JDFAutoInsertingParams.obj"	"$(INTDIR)\JDFAutoInsertingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertSheet.cpp

"$(INTDIR)\JDFAutoInsertSheet.obj"	"$(INTDIR)\JDFAutoInsertSheet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInterpretedPDLData.cpp

"$(INTDIR)\JDFAutoInterpretedPDLData.obj"	"$(INTDIR)\JDFAutoInterpretedPDLData.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInterpretingParams.cpp

"$(INTDIR)\JDFAutoInterpretingParams.obj"	"$(INTDIR)\JDFAutoInterpretingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJacketingParams.cpp

"$(INTDIR)\JDFAutoJacketingParams.obj"	"$(INTDIR)\JDFAutoJacketingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJobField.cpp

"$(INTDIR)\JDFAutoJobField.obj"	"$(INTDIR)\JDFAutoJobField.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLabelingParams.cpp

"$(INTDIR)\JDFAutoLabelingParams.obj"	"$(INTDIR)\JDFAutoLabelingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLaminatingParams.cpp

"$(INTDIR)\JDFAutoLaminatingParams.obj"	"$(INTDIR)\JDFAutoLaminatingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayout.cpp

"$(INTDIR)\JDFAutoLayout.obj"	"$(INTDIR)\JDFAutoLayout.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayoutElement.cpp

"$(INTDIR)\JDFAutoLayoutElement.obj"	"$(INTDIR)\JDFAutoLayoutElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayoutPreparationParams.cpp

"$(INTDIR)\JDFAutoLayoutPreparationParams.obj"	"$(INTDIR)\JDFAutoLayoutPreparationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLongitudinalRibbonOperationParams.cpp

"$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.obj"	"$(INTDIR)\JDFAutoLongitudinalRibbonOperationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoManualLaborParams.cpp

"$(INTDIR)\JDFAutoManualLaborParams.obj"	"$(INTDIR)\JDFAutoManualLaborParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMedia.cpp

"$(INTDIR)\JDFAutoMedia.obj"	"$(INTDIR)\JDFAutoMedia.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMediaSource.cpp

"$(INTDIR)\JDFAutoMediaSource.obj"	"$(INTDIR)\JDFAutoMediaSource.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMISDetails.cpp

"$(INTDIR)\JDFAutoMISDetails.obj"	"$(INTDIR)\JDFAutoMISDetails.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNumberingParams.cpp

"$(INTDIR)\JDFAutoNumberingParams.obj"	"$(INTDIR)\JDFAutoNumberingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoObjectResolution.cpp

"$(INTDIR)\JDFAutoObjectResolution.obj"	"$(INTDIR)\JDFAutoObjectResolution.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoOrderingParams.cpp

"$(INTDIR)\JDFAutoOrderingParams.obj"	"$(INTDIR)\JDFAutoOrderingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPackingParams.cpp

"$(INTDIR)\JDFAutoPackingParams.obj"	"$(INTDIR)\JDFAutoPackingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPageList.cpp

"$(INTDIR)\JDFAutoPageList.obj"	"$(INTDIR)\JDFAutoPageList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPallet.cpp

"$(INTDIR)\JDFAutoPallet.obj"	"$(INTDIR)\JDFAutoPallet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPalletizingParams.cpp

"$(INTDIR)\JDFAutoPalletizingParams.obj"	"$(INTDIR)\JDFAutoPalletizingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDFToPSConversionParams.cpp

"$(INTDIR)\JDFAutoPDFToPSConversionParams.obj"	"$(INTDIR)\JDFAutoPDFToPSConversionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDLResourceAlias.cpp

"$(INTDIR)\JDFAutoPDLResourceAlias.obj"	"$(INTDIR)\JDFAutoPDLResourceAlias.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPerforatingParams.cpp

"$(INTDIR)\JDFAutoPerforatingParams.obj"	"$(INTDIR)\JDFAutoPerforatingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPerson.cpp

"$(INTDIR)\JDFAutoPerson.obj"	"$(INTDIR)\JDFAutoPerson.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlaceHolderResource.cpp

"$(INTDIR)\JDFAutoPlaceHolderResource.obj"	"$(INTDIR)\JDFAutoPlaceHolderResource.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlasticCombBindingParams.cpp

"$(INTDIR)\JDFAutoPlasticCombBindingParams.obj"	"$(INTDIR)\JDFAutoPlasticCombBindingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlateCopyParams.cpp

"$(INTDIR)\JDFAutoPlateCopyParams.obj"	"$(INTDIR)\JDFAutoPlateCopyParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightAnalysis.cpp

"$(INTDIR)\JDFAutoPreflightAnalysis.obj"	"$(INTDIR)\JDFAutoPreflightAnalysis.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightInventory.cpp

"$(INTDIR)\JDFAutoPreflightInventory.obj"	"$(INTDIR)\JDFAutoPreflightInventory.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightParams.cpp

"$(INTDIR)\JDFAutoPreflightParams.obj"	"$(INTDIR)\JDFAutoPreflightParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightProfile.cpp

"$(INTDIR)\JDFAutoPreflightProfile.obj"	"$(INTDIR)\JDFAutoPreflightProfile.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightReport.cpp

"$(INTDIR)\JDFAutoPreflightReport.obj"	"$(INTDIR)\JDFAutoPreflightReport.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightReportRulePool.cpp

"$(INTDIR)\JDFAutoPreflightReportRulePool.obj"	"$(INTDIR)\JDFAutoPreflightReportRulePool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreview.cpp

"$(INTDIR)\JDFAutoPreview.obj"	"$(INTDIR)\JDFAutoPreview.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreviewGenerationParams.cpp

"$(INTDIR)\JDFAutoPreviewGenerationParams.obj"	"$(INTDIR)\JDFAutoPreviewGenerationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPrintCondition.cpp

"$(INTDIR)\JDFAutoPrintCondition.obj"	"$(INTDIR)\JDFAutoPrintCondition.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPrintRollingParams.cpp

"$(INTDIR)\JDFAutoPrintRollingParams.obj"	"$(INTDIR)\JDFAutoPrintRollingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProofingParams.cpp

"$(INTDIR)\JDFAutoProofingParams.obj"	"$(INTDIR)\JDFAutoProofingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPSToPDFConversionParams.cpp

"$(INTDIR)\JDFAutoPSToPDFConversionParams.obj"	"$(INTDIR)\JDFAutoPSToPDFConversionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQualityControlParams.cpp

"$(INTDIR)\JDFAutoQualityControlParams.obj"	"$(INTDIR)\JDFAutoQualityControlParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQualityControlResult.cpp

"$(INTDIR)\JDFAutoQualityControlResult.obj"	"$(INTDIR)\JDFAutoQualityControlResult.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRegisterMark.cpp

"$(INTDIR)\JDFAutoRegisterMark.obj"	"$(INTDIR)\JDFAutoRegisterMark.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRegisterRibbon.cpp

"$(INTDIR)\JDFAutoRegisterRibbon.obj"	"$(INTDIR)\JDFAutoRegisterRibbon.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRenderingParams.cpp

"$(INTDIR)\JDFAutoRenderingParams.obj"	"$(INTDIR)\JDFAutoRenderingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceDefinitionParams.cpp

"$(INTDIR)\JDFAutoResourceDefinitionParams.obj"	"$(INTDIR)\JDFAutoResourceDefinitionParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRingBindingParams.cpp

"$(INTDIR)\JDFAutoRingBindingParams.obj"	"$(INTDIR)\JDFAutoRingBindingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRollStand.cpp

"$(INTDIR)\JDFAutoRollStand.obj"	"$(INTDIR)\JDFAutoRollStand.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRunList.cpp

"$(INTDIR)\JDFAutoRunList.obj"	"$(INTDIR)\JDFAutoRunList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSaddleStitchingParams.cpp

"$(INTDIR)\JDFAutoSaddleStitchingParams.obj"	"$(INTDIR)\JDFAutoSaddleStitchingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScanParams.cpp

"$(INTDIR)\JDFAutoScanParams.obj"	"$(INTDIR)\JDFAutoScanParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScavengerArea.cpp

"$(INTDIR)\JDFAutoScavengerArea.obj"	"$(INTDIR)\JDFAutoScavengerArea.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScreeningParams.cpp

"$(INTDIR)\JDFAutoScreeningParams.obj"	"$(INTDIR)\JDFAutoScreeningParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSeparationControlParams.cpp

"$(INTDIR)\JDFAutoSeparationControlParams.obj"	"$(INTDIR)\JDFAutoSeparationControlParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSeparationSpec.cpp

"$(INTDIR)\JDFAutoSeparationSpec.obj"	"$(INTDIR)\JDFAutoSeparationSpec.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShapeCuttingParams.cpp

"$(INTDIR)\JDFAutoShapeCuttingParams.obj"	"$(INTDIR)\JDFAutoShapeCuttingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSheet.cpp

"$(INTDIR)\JDFAutoSheet.obj"	"$(INTDIR)\JDFAutoSheet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShrinkingParams.cpp

"$(INTDIR)\JDFAutoShrinkingParams.obj"	"$(INTDIR)\JDFAutoShrinkingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSideSewingParams.cpp

"$(INTDIR)\JDFAutoSideSewingParams.obj"	"$(INTDIR)\JDFAutoSideSewingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSpinePreparationParams.cpp

"$(INTDIR)\JDFAutoSpinePreparationParams.obj"	"$(INTDIR)\JDFAutoSpinePreparationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSpineTapingParams.cpp

"$(INTDIR)\JDFAutoSpineTapingParams.obj"	"$(INTDIR)\JDFAutoSpineTapingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStackingParams.cpp

"$(INTDIR)\JDFAutoStackingParams.obj"	"$(INTDIR)\JDFAutoStackingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStitchingParams.cpp

"$(INTDIR)\JDFAutoStitchingParams.obj"	"$(INTDIR)\JDFAutoStitchingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStrap.cpp

"$(INTDIR)\JDFAutoStrap.obj"	"$(INTDIR)\JDFAutoStrap.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStrappingParams.cpp

"$(INTDIR)\JDFAutoStrappingParams.obj"	"$(INTDIR)\JDFAutoStrappingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStripBindingParams.cpp

"$(INTDIR)\JDFAutoStripBindingParams.obj"	"$(INTDIR)\JDFAutoStripBindingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStrippingParams.cpp

"$(INTDIR)\JDFAutoStrippingParams.obj"	"$(INTDIR)\JDFAutoStrippingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSurface.cpp

"$(INTDIR)\JDFAutoSurface.obj"	"$(INTDIR)\JDFAutoSurface.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSealingParams.cpp

"$(INTDIR)\JDFAutoThreadSealingParams.obj"	"$(INTDIR)\JDFAutoThreadSealingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSewingParams.cpp

"$(INTDIR)\JDFAutoThreadSewingParams.obj"	"$(INTDIR)\JDFAutoThreadSewingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTile.cpp

"$(INTDIR)\JDFAutoTile.obj"	"$(INTDIR)\JDFAutoTile.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTool.cpp

"$(INTDIR)\JDFAutoTool.obj"	"$(INTDIR)\JDFAutoTool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferCurve.cpp

"$(INTDIR)\JDFAutoTransferCurve.obj"	"$(INTDIR)\JDFAutoTransferCurve.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferCurvePool.cpp

"$(INTDIR)\JDFAutoTransferCurvePool.obj"	"$(INTDIR)\JDFAutoTransferCurvePool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferFunctionControl.cpp

"$(INTDIR)\JDFAutoTransferFunctionControl.obj"	"$(INTDIR)\JDFAutoTransferFunctionControl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrappingDetails.cpp

"$(INTDIR)\JDFAutoTrappingDetails.obj"	"$(INTDIR)\JDFAutoTrappingDetails.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrappingParams.cpp

"$(INTDIR)\JDFAutoTrappingParams.obj"	"$(INTDIR)\JDFAutoTrappingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrapRegion.cpp

"$(INTDIR)\JDFAutoTrapRegion.obj"	"$(INTDIR)\JDFAutoTrapRegion.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrimmingParams.cpp

"$(INTDIR)\JDFAutoTrimmingParams.obj"	"$(INTDIR)\JDFAutoTrimmingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoVerificationParams.cpp

"$(INTDIR)\JDFAutoVerificationParams.obj"	"$(INTDIR)\JDFAutoVerificationParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWireCombBindingParams.cpp

"$(INTDIR)\JDFAutoWireCombBindingParams.obj"	"$(INTDIR)\JDFAutoWireCombBindingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWrappingParams.cpp

"$(INTDIR)\JDFAutoWrappingParams.obj"	"$(INTDIR)\JDFAutoWrappingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFArgumentValue.cpp

"$(INTDIR)\JDFArgumentValue.obj"	"$(INTDIR)\JDFArgumentValue.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdvancedParams.cpp

"$(INTDIR)\JDFAutoAdvancedParams.obj"	"$(INTDIR)\JDFAutoAdvancedParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoApprovalPerson.cpp

"$(INTDIR)\JDFAutoApprovalPerson.obj"	"$(INTDIR)\JDFAutoApprovalPerson.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoArgumentValue.cpp

"$(INTDIR)\JDFAutoArgumentValue.obj"	"$(INTDIR)\JDFAutoArgumentValue.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAssemblySection.cpp

"$(INTDIR)\JDFAutoAssemblySection.obj"	"$(INTDIR)\JDFAutoAssemblySection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBand.cpp

"$(INTDIR)\JDFAutoBand.obj"	"$(INTDIR)\JDFAutoBand.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBasicPreflightTest.cpp

"$(INTDIR)\JDFAutoBasicPreflightTest.obj"	"$(INTDIR)\JDFAutoBasicPreflightTest.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBindingQualityParams.cpp

"$(INTDIR)\JDFAutoBindingQualityParams.obj"	"$(INTDIR)\JDFAutoBindingQualityParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBoxArgument.cpp

"$(INTDIR)\JDFAutoBoxArgument.obj"	"$(INTDIR)\JDFAutoBoxArgument.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBoxToBoxDifference.cpp

"$(INTDIR)\JDFAutoBoxToBoxDifference.obj"	"$(INTDIR)\JDFAutoBoxToBoxDifference.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBundleItem.cpp

"$(INTDIR)\JDFAutoBundleItem.obj"	"$(INTDIR)\JDFAutoBundleItem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCCITTFaxParams.cpp

"$(INTDIR)\JDFAutoCCITTFaxParams.obj"	"$(INTDIR)\JDFAutoCCITTFaxParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCollatingItem.cpp

"$(INTDIR)\JDFAutoCollatingItem.obj"	"$(INTDIR)\JDFAutoCollatingItem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantZoneDetails.cpp

"$(INTDIR)\JDFAutoColorantZoneDetails.obj"	"$(INTDIR)\JDFAutoColorantZoneDetails.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorCorrectionOp.cpp

"$(INTDIR)\JDFAutoColorCorrectionOp.obj"	"$(INTDIR)\JDFAutoColorCorrectionOp.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorSpaceSubstitute.cpp

"$(INTDIR)\JDFAutoColorSpaceSubstitute.obj"	"$(INTDIR)\JDFAutoColorSpaceSubstitute.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContainer.cpp

"$(INTDIR)\JDFAutoContainer.obj"	"$(INTDIR)\JDFAutoContainer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContentObject.cpp

"$(INTDIR)\JDFAutoContentObject.obj"	"$(INTDIR)\JDFAutoContentObject.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCrease.cpp

"$(INTDIR)\JDFAutoCrease.obj"	"$(INTDIR)\JDFAutoCrease.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCut.cpp

"$(INTDIR)\JDFAutoCut.obj"	"$(INTDIR)\JDFAutoCut.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDCTParams.cpp

"$(INTDIR)\JDFAutoDCTParams.obj"	"$(INTDIR)\JDFAutoDCTParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDependencies.cpp

"$(INTDIR)\JDFAutoDependencies.obj"	"$(INTDIR)\JDFAutoDependencies.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceNColor.cpp

"$(INTDIR)\JDFAutoDeviceNColor.obj"	"$(INTDIR)\JDFAutoDeviceNColor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDrop.cpp

"$(INTDIR)\JDFAutoDrop.obj"	"$(INTDIR)\JDFAutoDrop.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDropItem.cpp

"$(INTDIR)\JDFAutoDropItem.obj"	"$(INTDIR)\JDFAutoDropItem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDynamicField.cpp

"$(INTDIR)\JDFAutoDynamicField.obj"	"$(INTDIR)\JDFAutoDynamicField.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDynamicInput.cpp

"$(INTDIR)\JDFAutoDynamicInput.obj"	"$(INTDIR)\JDFAutoDynamicInput.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmboss.cpp

"$(INTDIR)\JDFAutoEmboss.obj"	"$(INTDIR)\JDFAutoEmboss.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEndSheet.cpp

"$(INTDIR)\JDFAutoEndSheet.obj"	"$(INTDIR)\JDFAutoEndSheet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFeeder.cpp

"$(INTDIR)\JDFAutoFeeder.obj"	"$(INTDIR)\JDFAutoFeeder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFeederQualityParams.cpp

"$(INTDIR)\JDFAutoFeederQualityParams.obj"	"$(INTDIR)\JDFAutoFeederQualityParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFileAlias.cpp

"$(INTDIR)\JDFAutoFileAlias.obj"	"$(INTDIR)\JDFAutoFileAlias.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFlateParams.cpp

"$(INTDIR)\JDFAutoFlateParams.obj"	"$(INTDIR)\JDFAutoFlateParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGlue.cpp

"$(INTDIR)\JDFAutoGlue.obj"	"$(INTDIR)\JDFAutoGlue.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIcon.cpp

"$(INTDIR)\JDFAutoIcon.obj"	"$(INTDIR)\JDFAutoIcon.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIconList.cpp

"$(INTDIR)\JDFAutoIconList.obj"	"$(INTDIR)\JDFAutoIconList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPCover.cpp

"$(INTDIR)\JDFAutoIDPCover.obj"	"$(INTDIR)\JDFAutoIDPCover.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPFinishing.cpp

"$(INTDIR)\JDFAutoIDPFinishing.obj"	"$(INTDIR)\JDFAutoIDPFinishing.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPFolding.cpp

"$(INTDIR)\JDFAutoIDPFolding.obj"	"$(INTDIR)\JDFAutoIDPFolding.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPHoleMaking.cpp

"$(INTDIR)\JDFAutoIDPHoleMaking.obj"	"$(INTDIR)\JDFAutoIDPHoleMaking.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPImageShift.cpp

"$(INTDIR)\JDFAutoIDPImageShift.obj"	"$(INTDIR)\JDFAutoIDPImageShift.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPJobSheet.cpp

"$(INTDIR)\JDFAutoIDPJobSheet.obj"	"$(INTDIR)\JDFAutoIDPJobSheet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPLayout.cpp

"$(INTDIR)\JDFAutoIDPLayout.obj"	"$(INTDIR)\JDFAutoIDPLayout.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPStitching.cpp

"$(INTDIR)\JDFAutoIDPStitching.obj"	"$(INTDIR)\JDFAutoIDPStitching.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPTrimming.cpp

"$(INTDIR)\JDFAutoIDPTrimming.obj"	"$(INTDIR)\JDFAutoIDPTrimming.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoImageCompression.cpp

"$(INTDIR)\JDFAutoImageCompression.obj"	"$(INTDIR)\JDFAutoImageCompression.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoImageShift.cpp

"$(INTDIR)\JDFAutoImageShift.obj"	"$(INTDIR)\JDFAutoImageShift.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayerDetails.cpp

"$(INTDIR)\JDFAutoLayerDetails.obj"	"$(INTDIR)\JDFAutoLayerDetails.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayerList.cpp

"$(INTDIR)\JDFAutoLayerList.obj"	"$(INTDIR)\JDFAutoLayerList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLongFold.cpp

"$(INTDIR)\JDFAutoLongFold.obj"	"$(INTDIR)\JDFAutoLongFold.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLongGlue.cpp

"$(INTDIR)\JDFAutoLongGlue.obj"	"$(INTDIR)\JDFAutoLongGlue.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLongPerforate.cpp

"$(INTDIR)\JDFAutoLongPerforate.obj"	"$(INTDIR)\JDFAutoLongPerforate.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLongSlit.cpp

"$(INTDIR)\JDFAutoLongSlit.obj"	"$(INTDIR)\JDFAutoLongSlit.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLZWParams.cpp

"$(INTDIR)\JDFAutoLZWParams.obj"	"$(INTDIR)\JDFAutoLZWParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMarkObject.cpp

"$(INTDIR)\JDFAutoMarkObject.obj"	"$(INTDIR)\JDFAutoMarkObject.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNumberingParam.cpp

"$(INTDIR)\JDFAutoNumberingParam.obj"	"$(INTDIR)\JDFAutoNumberingParam.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPageCell.cpp

"$(INTDIR)\JDFAutoPageCell.obj"	"$(INTDIR)\JDFAutoPageCell.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPageData.cpp

"$(INTDIR)\JDFAutoPageData.obj"	"$(INTDIR)\JDFAutoPageData.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDFInterpretingParams.cpp

"$(INTDIR)\JDFAutoPDFInterpretingParams.obj"	"$(INTDIR)\JDFAutoPDFInterpretingParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDFXParams.cpp

"$(INTDIR)\JDFAutoPDFXParams.obj"	"$(INTDIR)\JDFAutoPDFXParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPerforate.cpp

"$(INTDIR)\JDFAutoPerforate.obj"	"$(INTDIR)\JDFAutoPerforate.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPixelColorant.cpp

"$(INTDIR)\JDFAutoPixelColorant.obj"	"$(INTDIR)\JDFAutoPixelColorant.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPosition.cpp

"$(INTDIR)\JDFAutoPosition.obj"	"$(INTDIR)\JDFAutoPosition.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightAction.cpp

"$(INTDIR)\JDFAutoPreflightAction.obj"	"$(INTDIR)\JDFAutoPreflightAction.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightArgument.cpp

"$(INTDIR)\JDFAutoPreflightArgument.obj"	"$(INTDIR)\JDFAutoPreflightArgument.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightConstraint.cpp

"$(INTDIR)\JDFAutoPreflightConstraint.obj"	"$(INTDIR)\JDFAutoPreflightConstraint.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightDetail.cpp

"$(INTDIR)\JDFAutoPreflightDetail.obj"	"$(INTDIR)\JDFAutoPreflightDetail.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightInstance.cpp

"$(INTDIR)\JDFAutoPreflightInstance.obj"	"$(INTDIR)\JDFAutoPreflightInstance.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightInstanceDetail.cpp

"$(INTDIR)\JDFAutoPreflightInstanceDetail.obj"	"$(INTDIR)\JDFAutoPreflightInstanceDetail.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightValue.cpp

"$(INTDIR)\JDFAutoPreflightValue.obj"	"$(INTDIR)\JDFAutoPreflightValue.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRError.cpp

"$(INTDIR)\JDFAutoPRError.obj"	"$(INTDIR)\JDFAutoPRError.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRGroup.cpp

"$(INTDIR)\JDFAutoPRGroup.obj"	"$(INTDIR)\JDFAutoPRGroup.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPrintConditionColor.cpp

"$(INTDIR)\JDFAutoPrintConditionColor.obj"	"$(INTDIR)\JDFAutoPrintConditionColor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRItem.cpp

"$(INTDIR)\JDFAutoPRItem.obj"	"$(INTDIR)\JDFAutoPRItem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPROccurence.cpp

"$(INTDIR)\JDFAutoPROccurence.obj"	"$(INTDIR)\JDFAutoPROccurence.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProperties.cpp

"$(INTDIR)\JDFAutoProperties.obj"	"$(INTDIR)\JDFAutoProperties.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRRule.cpp

"$(INTDIR)\JDFAutoPRRule.obj"	"$(INTDIR)\JDFAutoPRRule.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRRuleAttr.cpp

"$(INTDIR)\JDFAutoPRRuleAttr.obj"	"$(INTDIR)\JDFAutoPRRuleAttr.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQualityMeasurement.cpp

"$(INTDIR)\JDFAutoQualityMeasurement.obj"	"$(INTDIR)\JDFAutoQualityMeasurement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceParam.cpp

"$(INTDIR)\JDFAutoResourceParam.obj"	"$(INTDIR)\JDFAutoResourceParam.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScore.cpp

"$(INTDIR)\JDFAutoScore.obj"	"$(INTDIR)\JDFAutoScore.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScreenSelector.cpp

"$(INTDIR)\JDFAutoScreenSelector.obj"	"$(INTDIR)\JDFAutoScreenSelector.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShapeElement.cpp

"$(INTDIR)\JDFAutoShapeElement.obj"	"$(INTDIR)\JDFAutoShapeElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSignature.cpp

"$(INTDIR)\JDFAutoSignature.obj"	"$(INTDIR)\JDFAutoSignature.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSignatureCell.cpp

"$(INTDIR)\JDFAutoSignatureCell.obj"	"$(INTDIR)\JDFAutoSignatureCell.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStringListValue.cpp

"$(INTDIR)\JDFAutoStringListValue.obj"	"$(INTDIR)\JDFAutoStringListValue.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStripCellParams.cpp

"$(INTDIR)\JDFAutoStripCellParams.obj"	"$(INTDIR)\JDFAutoStripCellParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThinPDFParams.cpp

"$(INTDIR)\JDFAutoThinPDFParams.obj"	"$(INTDIR)\JDFAutoThinPDFParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTIFFEmbeddedFile.cpp

"$(INTDIR)\JDFAutoTIFFEmbeddedFile.obj"	"$(INTDIR)\JDFAutoTIFFEmbeddedFile.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTIFFFormatParams.cpp

"$(INTDIR)\JDFAutoTIFFFormatParams.obj"	"$(INTDIR)\JDFAutoTIFFFormatParams.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTIFFtag.cpp

"$(INTDIR)\JDFAutoTIFFtag.obj"	"$(INTDIR)\JDFAutoTIFFtag.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferCurveSet.cpp

"$(INTDIR)\JDFAutoTransferCurveSet.obj"	"$(INTDIR)\JDFAutoTransferCurveSet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrappingOrder.cpp

"$(INTDIR)\JDFAutoTrappingOrder.obj"	"$(INTDIR)\JDFAutoTrappingOrder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAction.cpp

"$(INTDIR)\JDFAutoAction.obj"	"$(INTDIR)\JDFAutoAction.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoActionPool.cpp

"$(INTDIR)\JDFAutoActionPool.obj"	"$(INTDIR)\JDFAutoActionPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoand.cpp

"$(INTDIR)\JDFAutoand.obj"	"$(INTDIR)\JDFAutoand.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutocall.cpp

"$(INTDIR)\JDFAutocall.obj"	"$(INTDIR)\JDFAutocall.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutochoice.cpp

"$(INTDIR)\JDFAutochoice.obj"	"$(INTDIR)\JDFAutochoice.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDevCap.cpp

"$(INTDIR)\JDFAutoDevCap.obj"	"$(INTDIR)\JDFAutoDevCap.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDevCaps.cpp

"$(INTDIR)\JDFAutoDevCaps.obj"	"$(INTDIR)\JDFAutoDevCaps.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceCap.cpp

"$(INTDIR)\JDFAutoDeviceCap.obj"	"$(INTDIR)\JDFAutoDeviceCap.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDisplayGroup.cpp

"$(INTDIR)\JDFAutoDisplayGroup.obj"	"$(INTDIR)\JDFAutoDisplayGroup.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDisplayGroupPool.cpp

"$(INTDIR)\JDFAutoDisplayGroupPool.obj"	"$(INTDIR)\JDFAutoDisplayGroupPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFeatureAttribute.cpp

"$(INTDIR)\JDFAutoFeatureAttribute.obj"	"$(INTDIR)\JDFAutoFeatureAttribute.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFeaturePool.cpp

"$(INTDIR)\JDFAutoFeaturePool.obj"	"$(INTDIR)\JDFAutoFeaturePool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLoc.cpp

"$(INTDIR)\JDFAutoLoc.obj"	"$(INTDIR)\JDFAutoLoc.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutomacro.cpp

"$(INTDIR)\JDFAutomacro.obj"	"$(INTDIR)\JDFAutomacro.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMacroPool.cpp

"$(INTDIR)\JDFAutoMacroPool.obj"	"$(INTDIR)\JDFAutoMacroPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutonot.cpp

"$(INTDIR)\JDFAutonot.obj"	"$(INTDIR)\JDFAutonot.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoor.cpp

"$(INTDIR)\JDFAutoor.obj"	"$(INTDIR)\JDFAutoor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutootherwise.cpp

"$(INTDIR)\JDFAutootherwise.obj"	"$(INTDIR)\JDFAutootherwise.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPerformance.cpp

"$(INTDIR)\JDFAutoPerformance.obj"	"$(INTDIR)\JDFAutoPerformance.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoset.cpp

"$(INTDIR)\JDFAutoset.obj"	"$(INTDIR)\JDFAutoset.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTest.cpp

"$(INTDIR)\JDFAutoTest.obj"	"$(INTDIR)\JDFAutoTest.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTestPool.cpp

"$(INTDIR)\JDFAutoTestPool.obj"	"$(INTDIR)\JDFAutoTestPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTestRef.cpp

"$(INTDIR)\JDFAutoTestRef.obj"	"$(INTDIR)\JDFAutoTestRef.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoValue.cpp

"$(INTDIR)\JDFAutoValue.obj"	"$(INTDIR)\JDFAutoValue.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoValueLoc.cpp

"$(INTDIR)\JDFAutoValueLoc.obj"	"$(INTDIR)\JDFAutoValueLoc.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutowhen.cpp

"$(INTDIR)\JDFAutowhen.obj"	"$(INTDIR)\JDFAutowhen.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoxor.cpp

"$(INTDIR)\JDFAutoxor.obj"	"$(INTDIR)\JDFAutoxor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEnumerationSpan.cpp

"$(INTDIR)\JDFAutoEnumerationSpan.obj"	"$(INTDIR)\JDFAutoEnumerationSpan.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRGroupOccurence.cpp

"$(INTDIR)\JDFAutoPRGroupOccurence.obj"	"$(INTDIR)\JDFAutoPRGroupOccurence.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRGroupOccurenceBase.cpp

"$(INTDIR)\JDFAutoPRGroupOccurenceBase.obj"	"$(INTDIR)\JDFAutoPRGroupOccurenceBase.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightConstraintsPool.cpp

"$(INTDIR)\JDFPreflightConstraintsPool.obj"	"$(INTDIR)\JDFPreflightConstraintsPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightResultsPool.cpp

"$(INTDIR)\JDFPreflightResultsPool.obj"	"$(INTDIR)\JDFPreflightResultsPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPRGroupOccurence.cpp

"$(INTDIR)\JDFPRGroupOccurence.obj"	"$(INTDIR)\JDFPRGroupOccurence.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFPRGroupOccurenceBase.cpp

"$(INTDIR)\JDFPRGroupOccurenceBase.obj"	"$(INTDIR)\JDFPRGroupOccurenceBase.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDateTimeRange.cpp

"$(INTDIR)\JDFDateTimeRange.obj"	"$(INTDIR)\JDFDateTimeRange.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDateTimeRangeList.cpp

"$(INTDIR)\JDFDateTimeRangeList.obj"	"$(INTDIR)\JDFDateTimeRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDurationRange.cpp

"$(INTDIR)\JDFDurationRange.obj"	"$(INTDIR)\JDFDurationRange.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFDurationRangeList.cpp

"$(INTDIR)\JDFDurationRangeList.obj"	"$(INTDIR)\JDFDurationRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerRange.cpp

"$(INTDIR)\JDFIntegerRange.obj"	"$(INTDIR)\JDFIntegerRange.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerRangeList.cpp

"$(INTDIR)\JDFIntegerRangeList.obj"	"$(INTDIR)\JDFIntegerRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNameRangeList.cpp

"$(INTDIR)\JDFNameRangeList.obj"	"$(INTDIR)\JDFNameRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNumberRangeList.cpp

"$(INTDIR)\JDFNumberRangeList.obj"	"$(INTDIR)\JDFNumberRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFNumTypeList.cpp

"$(INTDIR)\JDFNumTypeList.obj"	"$(INTDIR)\JDFNumTypeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrappercore\JDFParser.cpp

"$(INTDIR)\JDFParser.obj"	"$(INTDIR)\JDFParser.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFRange.cpp

"$(INTDIR)\JDFRange.obj"	"$(INTDIR)\JDFRange.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFRangeList.cpp

"$(INTDIR)\JDFRangeList.obj"	"$(INTDIR)\JDFRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrapper\JDFXYPairRangeList.cpp

"$(INTDIR)\JDFXYPairRangeList.obj"	"$(INTDIR)\JDFXYPairRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrappercore\KElement.cpp

"$(INTDIR)\KElement.obj"	"$(INTDIR)\KElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrappercore\KElementStrings.cpp

"$(INTDIR)\KElementStrings.obj"	"$(INTDIR)\KElementStrings.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrappercore\MyDate.cpp

"$(INTDIR)\MyDate.obj"	"$(INTDIR)\MyDate.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrappercore\vElement.cpp

"$(INTDIR)\vElement.obj"	"$(INTDIR)\vElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrappercore\XMLDoc.cpp

"$(INTDIR)\XMLDoc.obj"	"$(INTDIR)\XMLDoc.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\src\jdf\wrappercore\XMLDocUserData.cpp

"$(INTDIR)\XMLDocUserData.obj"	"$(INTDIR)\XMLDocUserData.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

