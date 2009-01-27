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

#include "JDFFactory.h"






#include "JDFAcknowledge.h"
#include "JDFAction.h"
#include "JDFAdded.h"
#include "JDFAddress.h"
#include "JDFAdhesiveBinding.h"
#include "JDFAncestor.h"
#include "JDFand.h"
#include "JDFApprovalDetails.h"
#include "JDFApprovalPerson.h"
#include "JDFApprovalSuccess.h"
#include "JDFArgumentValue.h"
#include "JDFArtDelivery.h"
#include "JDFAssembly.h"
#include "JDFAssemblySection.h"
#include "JDFAudit.h"
#include "JDFAuthenticationResp.h"

#include "JDFBand.h"
#include "JDFBarcode.h"
#include "JDFBarcodeDetails.h"
#include "JDFBasicPreflightTest.h"
#include "JDFBindItem.h"
#include "JDFBindList.h"
#include "JDFBinderySignature.h"
#include "JDFBooleanEvaluation.h"
#include "JDFBooleanState.h"
#include "JDFBookCase.h"
#include "JDFBoxArgument.h"
#include "JDFBoxApplication.h"
#include "JDFBoxFoldAction.h"
#include "JDFBoxToBoxDifference.h"
#include "JDFBundle.h"
#include "JDFBusinessInfo.h"
#include "JDFByteMap.h"


#include "JDFcall.h"
#include "JDFChangedAttribute.h"
#include "JDFChannelBinding.h"
#include "JDFchoice.h"
#include "JDFCIELABMeasuringField.h"
#include "JDFCoilBinding.h"
#include "JDFCollatingItem.h"
#include "JDFColor.h"
#include "JDFColorantAlias.h"
#include "JDFColorantControl.h"
#include "JDFColorantZoneDetails.h"
#include "JDFColorControlStrip.h"
#include "JDFColorCorrectionOp.h"
#include "JDFColorMeasurementConditions.h"
#include "JDFColorSpaceConversionOp.h"
#include "JDFColorSpaceSubstitute.h"
#include "JDFColorsUsed.h"
#include "JDFComChannel.h"
#include "JDFCommand.h"
#include "JDFComment.h"
#include "JDFCompany.h"
#include "JDFComponent.h"
#include "JDFContact.h"
#include "JDFContainer.h"
#include "JDFContentData.h"
#include "JDFContentList.h"
#include "JDFContentMetaData.h"
#include "JDFContentObject.h"
#include "JDFControllerFilter.h"
#include "JDFConvertingConfig.h"
#include "JDFCostCenter.h"
#include "JDFIDPCover.h"
#include "JDFCounterReset.h"
#include "JDFCrease.h"
#include "JDFCreateResource.h"
#include "JDFCreated.h"
#include "JDFCreditCard.h"
#include "JDFCut.h"
#include "JDFCutBlock.h"
#include "JDFCutMark.h"
#include "JDFCustomerInfo.h"
#include "JDFCylinderPosition.h"


#include "JDFDateTimeEvaluation.h"
#include "JDFDateTimeState.h"
#include "JDFDBRules.h"
#include "JDFDBSchema.h"
#include "JDFDBSelection.h"
#include "JDFDeleted.h"
#include "JDFDependencies.h"
#include "JDFDensityMeasuringField.h"
#include "JDFDevCap.h"
#include "JDFDevCapPool.h"
#include "JDFDevCaps.h"
#include "JDFDevice.h"
#include "JDFDeviceCap.h"
#include "JDFDeviceFilter.h"
#include "JDFDeviceInfo.h"
#include "JDFDeviceList.h"
#include "JDFDeviceMark.h"
#include "JDFDeviceNColor.h"
#include "JDFDeviceNSpace.h"
#include "JDFDieLayout.h"
#include "JDFDigitalMedia.h"
#include "JDFDisjointing.h"
#include "JDFDisplayGroup.h"
#include "JDFDisposition.h"
#include "JDFDrop.h"
#include "JDFDropItem.h"
#include "JDFDurationEvaluation.h"
#include "JDFDurationState.h"
#include "JDFDynamicField.h"
#include "JDFDynamicInput.h"

#include "JDFEdgeGluing.h"
#include "JDFElement.h"
#include "JDFEmboss.h"
#include "JDFEmbossingItem.h"
#include "JDFEmployee.h"
#include "JDFEmployeeDef.h"
#include "JDFEndSheet.h"
#include "JDFEnumerationEvaluation.h"
#include "JDFEnumerationState.h"
#include "JDFError.h"
#include "JDFExposedMedia.h"
#include "JDFExternalImpositionTemplate.h"

#include "JDFFCNKey.h"
#include "JDFFeatureAttribute.h"
#include "JDFFeeder.h"
#include "JDFFileAlias.h"
#include "JDFFileSpec.h"
#include "JDFFitPolicy.h"
#include "JDFFlushedResources.h"
#include "JDFFold.h"
#include "JDFFolderProduction.h"
#include "JDFFontPolicy.h"

#include "JDFGlue.h"
#include "JDFGlueApplication.h"
#include "JDFGlueLine.h"
#include "JDFGangCmdFilter.h"
#include "JDFGangInfo.h"
#include "JDFGangQuFilter.h"

#include "JDFHardCoverBinding.h"
#include "JDFHole.h"
#include "JDFHoleLine.h"
#include "JDFHoleList.h"


#include "JDFIcon.h"
#include "JDFIconList.h"
#include "JDFIdentificationField.h"
#include "JDFIDInfo.h"
#include "JDFIDPFinishing.h"
#include "JDFIDPFolding.h"
#include "JDFIDPJobSheet.h"
#include "JDFIDPHoleMaking.h"
#include "JDFIDPLayout.h"
#include "JDFIDPStitching.h"
#include "JDFIDPTrimming.h"
#include "JDFImageCompression.h"
#include "JDFImageShift.h"
#include "JDFInk.h"
#include "JDFInkZoneProfile.h"
#include "JDFInsert.h"
#include "JDFInsertList.h"
#include "JDFInsertSheet.h"
#include "JDFIntegerEvaluation.h"
#include "JDFIntegerState.h"
#include "JDFInterpretedPDLData.h"
#include "JDFIntentResource.h"
#include "JDFIsPresentEvaluation.h"

#include "JDFJDFController.h"
#include "JDFJDFService.h"
#include "JDFJobField.h"
#include "JDFJobPhase.h"

#include "JDFLayerDetails.h"
#include "JDFLayerList.h"
#include "JDFLayout.h"
#include "JDFLayoutElement.h"
#include "JDFLayoutElementPart.h"
#include "JDFLayoutShift.h"
#include "JDFLoc.h"
#include "JDFLocation.h"
#include "JDFLongFold.h"
#include "JDFLongGlue.h"
#include "JDFLongPerforate.h"
#include "JDFLongSlit.h"

#include "JDFObjectResolution.h"

#include "JDFmacro.h"
#include "JDFMarkObject.h"
#include "JDFMarkActivation.h"
#include "JDFMatrixEvaluation.h"
#include "JDFMatrixState.h"
#include "JDFMedia.h"
#include "JDFMediaLayers.h"
#include "JDFMediaSource.h"
#include "JDFMerged.h"
#include "JDFMessageService.h"
#include "JDFMessage.h"
#include "JDFMessageElement.h"
#include "JDFMetadataMap.h"
#include "JDFMilestone.h"
#include "JDFMISDetails.h"
#include "JDFModified.h"
#include "JDFModule.h"
#include "JDFModuleCap.h"
#include "JDFModulePhase.h"
#include "JDFModulePool.h"
#include "JDFModuleStatus.h"
#include "JDFMoveResource.h"
#include "JDFMsgFilter.h"

#include "JDFNameEvaluation.h"
#include "JDFNameState.h"
#include "JDFNewComment.h"
#include "JDFNode.h"
#include "JDFNodeInfo.h"
#include "JDFNodeInfoResp.h"
#include "JDFnot.h"
#include "JDFNotification.h"
#include "JDFNotificationDef.h"
#include "JDFNotificationFilter.h"
#include "JDFNumberEvaluation.h"
#include "JDFNumberState.h"
#include "JDFNumberingParam.h"
#include "JDFNumberItem.h"

#include "JDFObjectModel.h"
#include "JDFObjectResolution.h"
#include "JDFObservationTarget.h"
#include "JDFOccupation.h"
#include "JDFOCGControl.h"
#include "JDFor.h"
#include "JDFotherwise.h"

#include "JDFPageAssignedList.h"
#include "JDFPageCell.h"
#include "JDFPageCondition.h"
#include "JDFPageData.h"
#include "JDFPageElement.h"
#include "JDFPageList.h"
#include "JDFPallet.h"
#include "JDFPart.h"
#include "JDFPartAmount.h"
#include "JDFPartStatus.h"
#include "JDFPayment.h"
#include "JDFPDFPathEvaluation.h"
#include "JDFPDFPathState.h"
#include "JDFPDLResourceAlias.h"
#include "JDFPerforate.h"
#include "JDFPerformance.h"
#include "JDFPerson.h"
#include "JDFPhaseTime.h"
#include "JDFPixelColorant.h"
#include "JDFPlaceHolderResource.h"
#include "JDFPlasticCombBinding.h"
#include "JDFPosition.h"
#include "JDFPositionObj.h"
#include "JDFPreflightAction.h"
#include "JDFPreflightAnalysis.h"
#include "JDFPreflightArgument.h"
#include "JDFPreflightConstraint.h"
#include "JDFPreflightConstraintsPool.h"
#include "JDFPreflightDetail.h"
#include "JDFPreflightInstance.h"
#include "JDFPreflightInstanceDetail.h"
#include "JDFPreflightInventory.h"
#include "JDFPreflightProfile.h"
#include "JDFPreflightReport.h"
#include "JDFPreflightReportRulePool.h"
#include "JDFPreflightResultsPool.h"
#include "JDFPreflightValue.h"
#include "JDFPRError.h"
#include "JDFPreview.h"
#include "JDFPricing.h"
#include "JDFPrintCondition.h"
#include "JDFPRItem.h"
#include "JDFPRGroupOccurrence.h"
#include "JDFProductionPath.h"
#include "JDFProductionSubPath.h"
#include "JDFPROccurrence.h"
#include "JDFProcessRun.h"
#include "JDFProofItem.h"
#include "JDFPRRule.h"
#include "JDFPRRuleAttr.h"

#include "JDFQualityControlResult.h"
#include "JDFQualityMeasurement.h"
#include "JDFQuery.h"
#include "JDFQueue.h"
#include "JDFQueueEntry.h"
#include "JDFQueueEntryDef.h"
#include "JDFQueueEntryDefList.h"
#include "JDFQueueFilter.h"

#include "JDFRange.h"
#include "JDFRectangleEvaluation.h"
#include "JDFRectangleState.h"
#include "JDFRefAnchor.h"
#include "JDFRefElement.h"
#include "JDFRegisterRibbon.h"
#include "JDFRegisterMark.h"
#include "JDFRemoved.h"
#include "JDFRepeatDesc.h"
#include "JDFResourceAudit.h"
#include "JDFResourceInfo.h"
#include "JDFResourceLink.h"
#include "JDFResourceParam.h"
#include "JDFResponse.h"
#include "JDFRingBinding.h"
#include "JDFRollStand.h"
#include "JDFRuleLength.h"
#include "JDFRunList.h"

#include "JDFSaddleStitching.h"
#include "JDFScavengerArea.h"
#include "JDFScore.h"
#include "JDFScreenSelector.h"
#include "JDFSeparationList.h"
#include "JDFSeparationSpec.h"
#include "JDFset.h"
#include "JDFShapeCut.h"
#include "JDFShapeDef.h"
#include "JDFShapeElement.h"
#include "JDFShapeEvaluation.h"
#include "JDFShapeState.h"
#include "JDFShapeTemplate.h"
#include "JDFSheet.h"
#include "JDFShiftPoint.h"
#include "JDFSideSewing.h"
#include "JDFSideStitching.h"
#include "JDFSignal.h"
#include "JDFSignature.h"
#include "JDFSignatureCell.h"
#include "JDFSoftCoverBinding.h"
#include "JDFSpawned.h"
#include "JDFState.h"
#include "JDFStaticBlockingParams.h"
#include "JDFStrap.h"
#include "JDFStation.h"
#include "JDFStripMark.h"
#include "JDFStringEvaluation.h"
#include "JDFStringListValue.h"
#include "JDFStringState.h"
#include "JDFStripBinding.h"
#include "JDFSubmissionMethods.h"
#include "JDFSubscription.h"
#include "JDFSubscriptionFilter.h"
#include "JDFSubscriptionInfo.h"
#include "JDFSurface.h"
#include "JDFSystemTimeSet.h"

#include "JDFTabs.h"
#include "JDFTabDimensions.h"
#include "JDFTape.h"
#include "JDFTest.h"
#include "JDFTestRef.h"
#include "JDFThreadSealing.h"
#include "JDFThreadSewing.h"
#include "JDFTIFFEmbeddedFile.h"
#include "JDFTIFFtag.h"
#include "JDFTile.h"
#include "JDFTool.h"
#include "JDFTrackFilter.h"
#include "JDFTrackResult.h"
#include "JDFTransferCurve.h"
#include "JDFTransferCurveSet.h"
#include "JDFTransferFunctionControl.h"
#include "JDFTrappingDetails.h"
#include "JDFTrappingOrder.h"
#include "JDFTrapRegion.h"
#include "JDFTrigger.h"

#include "JDFValue.h"
#include "JDFValueLoc.h"

#include "JDFwhen.h"
#include "JDFWireCombBinding.h"

#include "JDFxor.h"
#include "JDFXYPairEvaluation.h"
#include "JDFXYPairState.h"

//







using namespace std;
namespace JDF{
	//////////////////////////////////////////////////////////////////////
	//
	// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
	//      ALL RIGHTS RESERVED 
	//
	//  Author: Dr. Rainer Prosi
	// 
	// Revision history:
	// created  Mar.2001
	//
	//
	//////////////////////////////////////////////////////////////////////
	
	
	
	/// default ctor
	JDFFactory::JDFFactory(){
		pE=0;
	}
	/// dtor
	JDFFactory::~JDFFactory(){
		delete pE;
	};
	
	/// copy ctor
	JDFFactory::JDFFactory(const JDFElement & other){
		pE=init(other);
	};
	/// copy ctor
	JDFFactory::JDFFactory(const JDFFactory& other){
		pE=0;
		if(other.pE)
			pE=init(*(other.pE));
	};
	/// copy ctor
	JDFFactory::JDFFactory(const WString &resName, const WString &typ, const JDFElement& part){
		pE=init(resName,typ, part);
	};
	/// yacctor
	JDFFactory& JDFFactory::operator =(const JDFElement& other){
		delete pE;
		pE=init(other);
		return *this;
	}
	JDFFactory& JDFFactory::operator =(const JDFFactory& other){
		pE=0;
		if(other.pE)
			pE=init(*(other.pE));
		return *this;
	}
	
	JDFElement* JDFFactory::init(const JDFElement &part){
		if(part.isNull()) 
			return new JDFElement();
		
		if(part.IsRefElement()){
			JDFRefElement re=part;
			KElement target=re.GetTarget();
			// dangling ref-> return a ref
			if(target.isNull()) 
				return new JDFRefElement(part);
			return init(target); // 
		}
		WString resName=part.GetLocalName();
		WString typ;
		if(resName==JDFElement::elm_JDF){
			typ=part.GetAttribute(JDFElement::atr_Type);
		}else{
			typ=part.GetAttribute(JDFElement::atr_DataType);
		}
		return init(resName,typ, part);
	}
	
	
		
		
	JDFElement* JDFFactory::initRest(const WString &resName, const WString &typ, const JDFElement &part){
		
		
		if(resName.empty())
			return 0;
		
		const JDFCh* pcResName=resName.c_str();
		JDFCh c=*pcResName;
		
		JDFElement*pE=0;
		
		if(c==L'A'||c==L'a'){
			
			pE=initRestA(pcResName,typ,part);
			
		}else if (c==L'B'||c==L'b'){
			
			pE=initRestB(pcResName,typ,part);
			
		}else if (c==L'C'||c==L'c'){
			
			pE=initRestC(pcResName,typ,part);
		
		}else if (c==L'D'){

			pE=initRestD(pcResName,typ,part);
			
		}else if (c==L'E'){
			
			pE=initRestE(pcResName,typ,part);
			
		}else if (c==L'F'){

			pE=initRestF(pcResName,typ,part);

		}else if (c==L'G'){
			
			pE=initRestG(pcResName,typ,part);
			
		}else if (c==L'H'){
			
			pE=initRestH(pcResName,typ,part);
			
		}else if (c==L'I'){
			
			pE=initRestI(pcResName,typ,part);
			
		}else if (c==L'J'){
			
			pE=initRestJ(pcResName,typ,part);
			
		}else if (c==L'K'){
			
			
		}else if (c==L'L'){
			
			pE=initRestL(pcResName,typ,part);
			
		}else if (c==L'm'||c==L'M'){

			pE=initRestM(pcResName,typ,part);
		
		}else if (c==L'n'||c==L'N'){
			
			pE=initRestN(pcResName,typ,part);
			
		}else if (c==L'o'||c==L'O'){
			
			pE=initRestO(pcResName,typ,part);
			
		}else if (c==L'P'){

			pE=initRestP(pcResName,typ,part);

		}else if (c==L'Q'){
			
			pE=initRestQ(pcResName,typ,part);

		}else if (c==L'R'){

			pE=initRestR(pcResName,typ,part);
			
		}else if (c==L's'||c==L'S'){	

			pE=initRestS(pcResName,typ,part);
			
		}else if (c==L'T'){

			pE=initRestT(pcResName,typ,part);
			
		}else if (c==L'U'){
			
		}else if (c==L'V'){

			pE=initRestV(pcResName,typ,part);
	
		}else if (c==L'w'||c==L'W'){

			pE=initRestW(pcResName,typ,part);

		}else if (c==L'x'||c==L'X'){
			
			pE=initRestX(pcResName,typ,part);
			
		}else if (c==L'Y'){
			
		}else if (c==L'Z'){
		}
		
		
			
		// found something in a-z
		if(pE){
			if(!pE->isNull())
				return pE;
		}
		
		
		// tbd define a generic text element class
		if(WString(L"ExtendedAddress,OrganizationalUnit").HasToken(resName,WString::comma)){
			return new JDFElement(part);
		};
		
		if(WString(L"ColorsUsed,ColorantOrder,DeviceColorantOrder,ColorantParams").HasToken(resName,WString::comma)){
			return new JDFSeparationList(part);
		};
		
		return initSpan(resName,typ,part);
		
	};

		JDFElement* JDFFactory::initRestA(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{

		if(!wcscmp(pcResName,JDFElement::elm_Acknowledge.c_str())){
			return new JDFAcknowledge(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Action.c_str())){
			return new JDFAction(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Added.c_str())){
			return new JDFAdded(part);				
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Address.c_str())){
			return new JDFAddress(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_AdhesiveBinding.c_str())){
			return new JDFAdhesiveBinding(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Ancestor.c_str())){
			return new JDFAncestor(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_and.c_str())){
			return new JDFand(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_ApprovalPerson.c_str())){
			return new JDFApprovalPerson(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ApprovalDetails.c_str())){
			return new JDFApprovalDetails(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ApprovalSuccess.c_str())){
			return new JDFApprovalSuccess(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ArgumentValue.c_str())){
			return new JDFArgumentValue(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ArtDelivery.c_str())){
			return new JDFArtDelivery(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Assembly.c_str())){
			return new JDFAssembly(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_AssemblySection.c_str())){
			return new JDFAssemblySection(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Audit.c_str())){
			return new JDFAudit(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_AuthenticationResp.c_str())){
			return new JDFAuthenticationResp(part);
		};
		return 0; 
	}

		
	JDFElement* JDFFactory::initRestB(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		
		if(!wcscmp(pcResName,JDFElement::elm_Band.c_str())){
			return new JDFBand(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Barcode.c_str())){
			return new JDFBarcode(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_BarcodeDetails.c_str())){
			return new JDFBarcodeDetails(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_BasicPreflightTest.c_str())){
			return new JDFBasicPreflightTest(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_BindItem.c_str())){
			return new JDFBindItem(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_BindList.c_str())){
			return new JDFBindList(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_BinderySignature.c_str())){
			return new JDFBinderySignature(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_BookCase.c_str())){
			return new JDFBookCase(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_BooleanEvaluation.c_str())){
			return new JDFBooleanEvaluation(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_BooleanState.c_str())){
			return new JDFBooleanState(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_BoxApplication.c_str())){
			return new JDFBoxApplication(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_BoxArgument.c_str())){
			return new JDFBoxArgument(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_BoxFoldAction.c_str())){
			return new JDFBoxFoldAction(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_BoxToBoxDifference.c_str())){
			return new JDFBoxToBoxDifference(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Bundle.c_str())){
			return new JDFBundle(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_BusinessInfo.c_str())){
			return new JDFBusinessInfo(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ByteMap.c_str())){
			return new JDFByteMap(part);
		};

		return 0; 
	}

	
	JDFElement* JDFFactory::initRestC(const  JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		if(!wcscmp(pcResName,JDFElement::elm_call.c_str())){
			return new JDFcall(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_ChangedAttribute.c_str())){
			return new JDFChangedAttribute(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ChannelBinding.c_str())){
			return new JDFChannelBinding(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_choice.c_str())){
			return new JDFchoice(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_CIELABMeasuringField.c_str())){
			return new JDFCIELABMeasuringField(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_CoilBinding.c_str())){
			return new JDFCoilBinding(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_CollatingItem.c_str())){
			return new JDFCollatingItem(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Color.c_str())){
			return new JDFColor(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ColorantAlias.c_str())){
			return new JDFColorantAlias(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_ColorantControl.c_str())){
			return new JDFColorantControl(part);
		};
				
		if(!wcscmp(pcResName,JDFElement::elm_ColorantZoneDetails.c_str())){
			return new JDFColorantZoneDetails(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ColorControlStrip.c_str())){
			return new JDFColorControlStrip(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ColorCorrectionOp.c_str())){
			return new JDFColorCorrectionOp(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ColorMeasurementConditions.c_str())){
			return new JDFColorMeasurementConditions(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ColorSpaceConversionOp.c_str())){
			return new JDFColorSpaceConversionOp(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ColorSpaceSubstitute.c_str())){
			return new JDFColorSpaceSubstitute(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ColorsUsed.c_str())){
			return new JDFColorsUsed(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_ComChannel.c_str())){
			return new JDFComChannel(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Command.c_str())){
			return new JDFCommand(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Comment.c_str())){
			return new JDFComment(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Company.c_str())){
			return new JDFCompany(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Component.c_str())){
			return new JDFComponent(part);
		};
		
		// ConstraintValue elements are arbitrarily void, therefore use only JDFElement
		if(!wcscmp(pcResName,JDFElement::elm_ConstraintValue.c_str())){
			return new JDFElement(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Contact.c_str())){
			return new JDFContact(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Container.c_str())){
			return new JDFContainer(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ContentList.c_str())){
			return new JDFContentList(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ContentData.c_str())){
			return new JDFContentData(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ContentMetaData.c_str())){
			return new JDFContentMetaData(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ContentObject.c_str())){
			return new JDFContentObject(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ControllerFilter.c_str())){
			return new JDFControllerFilter(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_ConvertingConfig.c_str())){
			return new JDFConvertingConfig(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_CostCenter.c_str())){
			return new JDFCostCenter(part);
		};
		
		
		if(!wcscmp(pcResName,JDFElement::elm_Cover.c_str())){
			if(part.GetParentNode().GetLocalName()==JDFElement::elm_ChannelBinding.c_str()){
				return new JDFOptionSpan(part);
			}else{
				return new JDFIDPCover(part);
			}
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_CounterReset.c_str())){
			return new JDFCounterReset(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Crease.c_str())){
			return new JDFCrease(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Created.c_str())){
			return new JDFCreated(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_CreateResource.c_str())){
			return new JDFCreateResource(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_CreditCard.c_str())){
			return new JDFCreditCard(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_CustomerInfo.c_str())){
			return new JDFCustomerInfo(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Cut.c_str())){
			return new JDFCut(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_CutBlock.c_str())){
			return new JDFCutBlock(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_CutMark.c_str())){
			return new JDFCutMark(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_CylinderPosition.c_str())){
			return new JDFCylinderPosition(part);
		};

		return 0; 
	}	


	JDFElement* JDFFactory::initRestD(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		
		if(!wcscmp(pcResName,JDFElement::elm_DateTimeEvaluation.c_str())){
	//		return new JDFDateTimeEvaluation(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_DateTimeState.c_str())){
			return new JDFDateTimeState(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_DBRules.c_str())){
			return new JDFDBRules(part);
		};
			
		if(!wcscmp(pcResName,JDFElement::elm_DBSchema.c_str())){
			return new JDFDBSchema(part);
		};
			
		if(!wcscmp(pcResName,JDFElement::elm_DBSelection.c_str())){
			return new JDFDBSelection(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Deleted.c_str())){
			return new JDFDeleted(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Dependencies.c_str())){
			return new JDFDependencies(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_DensityMeasuringField.c_str())){
			return new JDFDensityMeasuringField(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_DevCap.c_str())){
			return new JDFDevCap(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_DevCapPool.c_str())){
			return new JDFDevCapPool(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_DevCaps.c_str())){
			return new JDFDevCaps(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Device.c_str())){
			return new JDFDevice(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_DeviceCap.c_str())){
			return new JDFDeviceCap(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_DeviceFilter.c_str())){
			return new JDFDeviceFilter(part);				
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_DeviceInfo.c_str())){
			return new JDFDeviceInfo(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_DeviceList.c_str())){
			return new JDFDeviceList(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_DeviceMark.c_str())){
			return new JDFDeviceMark(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_DeviceNColor.c_str())){
			return new JDFDeviceNColor(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_DeviceNSpace.c_str())){
			return new JDFDeviceNSpace(part);
		};			

		if(!wcscmp(pcResName,JDFElement::elm_DieLayout.c_str())){
			return new JDFDieLayout(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_DigitalMedia.c_str())){
			return new JDFDigitalMedia(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Disjointing.c_str())){
			return new JDFDisjointing(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_DisplayGroup.c_str())){
			return new JDFDisplayGroup(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Disposition.c_str())){
			return new JDFDisposition(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Drop.c_str())){
			return new JDFDrop(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_DropItem.c_str())){
			return new JDFDropItem(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_DurationEvaluation.c_str())){
			return new JDFDurationEvaluation(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_DurationState.c_str())){
			return new JDFDurationState(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_DynamicField.c_str())){
			return new JDFDynamicField(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_DynamicInput.c_str())){
			return new JDFDynamicInput(part);
		};

		return 0; 
	}	


	JDFElement* JDFFactory::initRestE(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		if(!wcscmp(pcResName,JDFElement::elm_EdgeGluing.c_str())){
			return new JDFEdgeGluing(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Emboss.c_str())){
			return new JDFEmboss(part);
		};
					
		if(!wcscmp(pcResName,JDFElement::elm_EmbossingItem.c_str())){
			return new JDFEmbossingItem(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Employee.c_str())){
			return new JDFEmployee(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_EmployeeDef.c_str())){
			return new JDFEmployeeDef(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_EndSheet.c_str())){
			return new JDFEndSheet(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_EnumerationEvaluation.c_str())){
			return new JDFEnumerationEvaluation(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_EnumerationState.c_str())){
			return new JDFEnumerationState(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Error.c_str())){
			return new JDFError(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ExposedMedia.c_str())){
			return new JDFExposedMedia(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_ExtendedAddress.c_str())){
			return new JDFComment(part); // this is not a typo!
		};

		if(!wcscmp(pcResName,JDFElement::elm_ExternalImpositionTemplate.c_str())){
			return new JDFExternalImpositionTemplate(part);
		};

		return 0; 
	}	


	JDFElement* JDFFactory::initRestF(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		
		if(!wcscmp(pcResName,JDFElement::elm_FCNKey.c_str())){
			return new JDFFCNKey(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_FeatureAttribute.c_str())){
			return new JDFFeatureAttribute(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Feeder.c_str())){
			return new JDFFeeder(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_FileAlias.c_str())){
			return new JDFFileAlias(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_FileSpec.c_str())){
			return new JDFFileSpec(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_FitPolicy.c_str())){
			return new JDFFitPolicy(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_FlushedResources.c_str())){
			return new JDFFlushedResources(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Fold.c_str())){
			return new JDFFold(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_FolderProduction.c_str())){
			return new JDFFolderProduction(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_FontPolicy.c_str())){
			return new JDFFontPolicy(part);
		};
	
		return 0;
	}


	JDFElement* JDFFactory::initRestG(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		if(!wcscmp(pcResName,JDFElement::elm_Glue.c_str())){
			return new JDFGlue(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_GlueApplication.c_str())){
			return new JDFGlueApplication(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_GlueLine.c_str())){
			return new JDFGlueLine(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_GangCmdFilter.c_str())){
			return new JDFGangCmdFilter(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_GangInfo.c_str())){
			return new JDFGangInfo(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_GangQuFilter.c_str())){
			return new JDFGangQuFilter(part);
		};
		
		return 0;
	}	


	JDFElement* JDFFactory::initRestH(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		if(!wcscmp(pcResName,JDFElement::elm_HardCoverBinding.c_str())){
			return new JDFHardCoverBinding(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Hole.c_str())){
			return new JDFHole(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_HoleLine.c_str())){
			return new JDFHoleLine(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_HoleList.c_str())){
			return new JDFHoleList(part);
		};

		return 0;
	}	


	JDFElement* JDFFactory::initRestI(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		
		if(!wcscmp(pcResName,JDFElement::elm_Icon.c_str())){
			return new JDFIcon(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_IconList.c_str())){
			return new JDFIconList(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_IdentificationField.c_str())){
			return new JDFIdentificationField(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_IDInfo.c_str())){
			return new JDFIDInfo(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_IDPFinishing.c_str())){
			return new JDFIDPFinishing(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_IDPFolding.c_str())){
			return new JDFIDPFolding(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_IDPHoleMaking.c_str())){
			return new JDFIDPHoleMaking(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_IDPLayout.c_str())){
			return new JDFIDPLayout(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_IDPStitching.c_str())){
			return new JDFIDPStitching(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_IDPTrimming.c_str())){
			return new JDFIDPTrimming(part);
		};
	
		if(!wcscmp(pcResName,JDFElement::elm_ImageCompression.c_str())){
			return new JDFImageCompression(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ImageShift.c_str())){
			return new JDFImageShift(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Ink.c_str())){
			return new JDFInk(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_InkZoneProfile.c_str())){
			return new JDFInkZoneProfile(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Insert.c_str())){
			return new JDFInsert(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_InsertList.c_str())){
			return new JDFInsertList(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_InsertSheet.c_str())){
			return new JDFInsertSheet(part);
		};
					
		if(!wcscmp(pcResName,JDFElement::elm_IntegerEvaluation.c_str())){
			return new JDFIntegerEvaluation(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_IntegerState.c_str())){
			return new JDFIntegerState(part);
		};
					
		if(!wcscmp(pcResName,JDFElement::elm_InterpretedPDLData.c_str())){
			return new JDFInterpretedPDLData(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_IsPresentEvaluation.c_str())){
			return new JDFIsPresentEvaluation(part);
		};

		return 0;
	}	


	JDFElement* JDFFactory::initRestJ(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		if(!wcscmp(pcResName,JDFElement::elm_JDFController.c_str())){
			return new JDFJDFController(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_JDFService.c_str())){
			return new JDFJDFService(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_JDFSystemTimeSet.c_str())){
			return new JDFSystemTimeSet(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_JobField.c_str())){
			return new JDFJobField(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_JobPhase.c_str())){
			return new JDFJobPhase(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_JobSheet.c_str())){
			return new JDFIDPJobSheet(part);
		};

		return 0;
	}


	JDFElement* JDFFactory::initRestL(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		if(!wcscmp(pcResName,JDFElement::elm_LayerDetails.c_str())){
			return new JDFLayerDetails(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_LayerList.c_str())){
			return new JDFLayerList(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Layout.c_str())){
			return new JDFLayout(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_LayoutElement.c_str())){
			return new JDFLayoutElement(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_LayoutElementPart.c_str())){
			return new JDFLayoutElementPart(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_LayoutShift.c_str())){
			return new JDFLayoutShift(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Loc.c_str())){
			return new JDFLoc(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Location.c_str())){
			return new JDFLocation(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_LongFold.c_str())){
			return new JDFLongFold(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_LongGlue.c_str())){
			return new JDFLongGlue(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_LongPerforate.c_str())){
			return new JDFLongPerforate(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_LongSlit.c_str())){
			return new JDFLongSlit(part);
		};
		

		return 0;
	}


	JDFElement* JDFFactory::initRestM(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		if(!wcscmp(pcResName,JDFElement::elm_macro.c_str())){
			return new JDFmacro(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_MarkObject.c_str())){
			return new JDFMarkObject(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_MarkActivation.c_str())){
			return new JDFMarkActivation(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_MatrixEvaluation.c_str())){
			return new JDFMatrixEvaluation(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_MatrixState.c_str())){
			return new JDFMatrixState(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Media.c_str())){
			return new JDFMedia(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_MediaLayers.c_str())){
			return new JDFMediaLayers(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_MediaSource.c_str())){
			return new JDFMediaSource(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Merged.c_str())){
			return new JDFMerged(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_MetadataMap.c_str())){
			return new JDFMetadataMap(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_MessageService.c_str())){
			return new JDFMessageService(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Milestone.c_str())){
			return new JDFMilestone(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_MISDetails.c_str())){
			return new JDFMISDetails(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Modified.c_str())){
			return new JDFModified(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Module.c_str())){
			return new JDFModule(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ModuleCap.c_str())){
			return new JDFModuleCap(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ModulePhase.c_str())){
			return new JDFModulePhase(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ModulePool.c_str())){
			return new JDFModulePool(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_ModuleStatus.c_str())){
			return new JDFModuleStatus(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_MoveResource.c_str())){
			return new JDFMoveResource(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_MsgFilter.c_str())){
			return new JDFMsgFilter(part);
		};

		return 0;
	}


	JDFElement* JDFFactory::initRestN(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{

		if(!wcscmp(pcResName,JDFElement::elm_not.c_str())){
			return new JDFnot(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_NameEvaluation.c_str())){
			return new JDFNameEvaluation(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_NameState.c_str())){
			return new JDFNameState(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_NewComment.c_str())){
			return new JDFNewComment(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_NodeInfo.c_str())){
			return new JDFNodeInfo(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_NodeInfoResp.c_str())){
			return new JDFNodeInfoResp(part);
		};
	
		if(!wcscmp(pcResName,JDFElement::elm_Notification.c_str())){
			return new JDFNotification(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_NotificationDef.c_str())){
			return new JDFNotificationDef(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_NotificationFilter.c_str())){
			return new JDFNotificationFilter(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_NumberEvaluation.c_str())){
			return new JDFNumberEvaluation(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_NumberState.c_str())){
			return new JDFNumberState(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_NumberingParam.c_str())){
			return new JDFNumberingParam(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_NumberItem.c_str())){
			return new JDFNumberItem(part);
		};
		
		return 0;
	}

// OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO

	JDFElement* JDFFactory::initRestO(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		if(!wcscmp(pcResName,JDFElement::elm_or.c_str())){
			return new JDFor(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_otherwise.c_str())){
			return new JDFotherwise(part);
		};
	
		if(!wcscmp(pcResName,JDFElement::elm_ObjectResolution.c_str())){
			return new JDFObjectResolution(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ObjectModel.c_str())){
			return new JDFObjectModel(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ObservationTarget.c_str())){
			return new JDFObservationTarget(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Occupation.c_str())){
			return new JDFOccupation(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_OCGControl.c_str())){
			return new JDFOCGControl(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_OrganizationalUnit.c_str())){
			return new JDFComment(part);
		};

		return 0;
	}

	// PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP

	JDFElement* JDFFactory::initRestP(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		if(!wcscmp(pcResName,JDFElement::elm_PageAssignedList.c_str())){
			return new JDFPageAssignedList(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_PageList.c_str())){
			return new JDFPageList(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_PageCell.c_str())){
			return new JDFPageCell(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_PageCondition.c_str())){
			return new JDFPageCondition(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_PageData.c_str())){
			return new JDFPageData(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_PageElement.c_str())){
			return new JDFPageElement(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Pallet.c_str())){
			return new JDFPallet(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Part.c_str())){
			return new JDFPart(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_PartAmount.c_str())){
			return new JDFPartAmount(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_PartStatus.c_str())){
			return new JDFPartStatus(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Path.c_str())){
			return new JDFProductionSubPath(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Payment.c_str())){
			return new JDFPayment(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PayTerm.c_str())){
			return new JDFComment(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PDFPathEvaluation.c_str())){
			return new JDFPDFPathEvaluation(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PDFPathState.c_str())){
			return new JDFPDFPathState(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PDLResourceAlias.c_str())){
			return new JDFPDLResourceAlias(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Perforate.c_str())){
			return new JDFPerforate(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Performance.c_str())){
			return new JDFPerformance(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Person.c_str())){
			return new JDFPerson(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_PhaseTime.c_str())){
			return new JDFPhaseTime(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_PixelColorant.c_str())){
			return new JDFPixelColorant(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_PlaceHolderResource.c_str())){
			return new JDFPlaceHolderResource(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PlasticCombBinding.c_str())){
			return new JDFPlasticCombBinding(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Position.c_str())){
			return new JDFPosition(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PositionObj.c_str())){
			return new JDFPositionObj(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PreflightAction.c_str())){
			return new JDFPreflightAction(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_PreflightAnalysis.c_str())){
			return new JDFPreflightAnalysis(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PreflightArgument.c_str())){
			return new JDFPreflightArgument(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PreflightConstraint.c_str())){
			return new JDFPreflightConstraint(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PreflightConstraintsPool.c_str())){
			return new JDFPreflightConstraintsPool(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PreflightDetail.c_str())){
			return new JDFPreflightDetail(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PreflightInstance.c_str())){
			return new JDFPreflightInstance(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PreflightInstanceDetail.c_str())){
			return new JDFPreflightInstanceDetail(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PreflightInventory.c_str())){
			return new JDFPreflightInventory(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PreflightProfile.c_str())){
			return new JDFPreflightProfile(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PreflightReport.c_str())){
			return new JDFPreflightReport(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_PreflightReportRulePool.c_str())){
			return new JDFPreflightReportRulePool(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PreflightResultsPool.c_str())){
			return new JDFPreflightResultsPool(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PreflightValue.c_str())){
			return new JDFPreflightValue(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_PRError.c_str())){
			return new JDFPRError(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Preview.c_str())){
			return new JDFPreview(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Pricing.c_str())){
			return new JDFPricing(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PrintCondition.c_str())){
			return new JDFPrintCondition(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PRItem.c_str())){
			return new JDFPRItem(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PRGroupOccurrence.c_str())){
			return new JDFPRGroupOccurrence(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_PROccurrence.c_str())){
			return new JDFPROccurrence(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_ProcessRun.c_str())){
			return new JDFProcessRun(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_ProductionPath.c_str())){
			return new JDFProductionPath(part);
		};
					
		if(!wcscmp(pcResName,JDFElement::elm_ProofItem.c_str())){
			return new JDFProofItem(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_PRRule.c_str())){
			return new JDFPRRule(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_PRRuleAttr.c_str())){
			return new JDFPRRuleAttr(part);
		};

		return 0;
	}


	JDFElement* JDFFactory::initRestQ(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		if(!wcscmp(pcResName,JDFElement::elm_QualityControlResult.c_str())){
			return new JDFQualityControlResult(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_QualityMeasurement.c_str())){
			return new JDFQualityMeasurement(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Query.c_str())){
			return new JDFQuery(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Queue.c_str())){
			return new JDFQueue(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_QueueEntry.c_str())){
			return new JDFQueueEntry(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_QueueEntryDef.c_str())){
			return new JDFQueueEntryDef(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_QueueEntryDefList.c_str())){
			return new JDFQueueEntryDefList(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_QueueFilter.c_str())){
			return new JDFQueueFilter(part);
		};
		
		return 0;
	}


	JDFElement* JDFFactory::initRestR(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		if(!wcscmp(pcResName,JDFElement::elm_RectangleEvaluation.c_str())){
			return new JDFRectangleEvaluation(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_RectangleState.c_str())){
			return new JDFRectangleState(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_RefAnchor.c_str())){
			return new JDFRefAnchor(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_RegisterRibbon.c_str())){
			return new JDFRegisterRibbon(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_RegisterMark.c_str())){
			return new JDFRegisterMark(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Removed.c_str())){
			return new JDFRemoved(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_RepeatDesc.c_str())){
			return new JDFRepeatDesc(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ResourceAudit.c_str())){
			return new JDFResourceAudit(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ResourceInfo.c_str())){
			return new JDFResourceInfo(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ResourceParam.c_str())){
			return new JDFResourceParam(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Response.c_str())){
			return new JDFResponse(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_RingBinding.c_str())){
			return new JDFRingBinding(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_RollStand.c_str())){
			return new JDFRollStand(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_RuleLength.c_str())){
			return new JDFRuleLength(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_RunList.c_str())){
			return new JDFRunList(part);
		};
	
		return 0;
	}


	JDFElement* JDFFactory::initRestS(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		if(!wcscmp(pcResName,JDFElement::elm_set.c_str())){
			return new JDFset(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_SaddleStitching.c_str())){
			return new JDFSaddleStitching(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ScavengerArea.c_str())){
			return new JDFScavengerArea(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Score.c_str())){
			return new JDFScore(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ScreenSelector.c_str())){
			return new JDFScreenSelector(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_SeparationSpec.c_str())){
			return new JDFSeparationSpec(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ShapeCut.c_str())){
			return new JDFShapeCut(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ShapeDef.c_str())){
			return new JDFShapeDef(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ShapeElement.c_str())){
			return new JDFShapeElement(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ShapeEvaluation.c_str())){
			return new JDFShapeEvaluation(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_ShapeState.c_str())){
			return new JDFShapeState(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_ShapeTemplate.c_str())){
			return new JDFShapeTemplate(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Sheet.c_str())){
			return new JDFSheet(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_ShiftPoint.c_str())){
			return new JDFShiftPoint(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_SideSewing.c_str())){
			return new JDFSideSewing(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_SideStitching.c_str())){
			return new JDFSideStitching(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Signal.c_str())){
			return new JDFSignal(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Signature.c_str())){
			return new JDFSignature(part);
		};
			
		if(!wcscmp(pcResName,JDFElement::elm_SignatureCell.c_str())){
			return new JDFSignatureCell(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_SoftCoverBinding.c_str())){
			return new JDFSoftCoverBinding(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Spawned.c_str())){
			return new JDFSpawned(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_StaticBlockingParams.c_str())){
			return new JDFStaticBlockingParams(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Station.c_str())){
			return new JDFStation(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Strap.c_str())){
			return new JDFStrap(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_StripMark.c_str())){
			return new JDFStripMark(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_StringEvaluation.c_str())){
			return new JDFStringEvaluation(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_StringListValue.c_str())){
			return new JDFStringListValue(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_StringState.c_str())){
			return new JDFStringState(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_StripBinding.c_str())){
			return new JDFStripBinding(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_SubmissionMethods.c_str())){
			return new JDFSubmissionMethods(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Subscription.c_str())){
			return new JDFSubscription(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_SubscriptionFilter.c_str())){
			return new JDFSubscriptionFilter(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_SubscriptionInfo.c_str())){
			return new JDFSubscriptionInfo(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Surface.c_str())){
			return new JDFSurface(part);
		};

		return 0;
	}



	JDFElement* JDFFactory::initRestT(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		if(!wcscmp(pcResName,JDFElement::elm_TabDimensions.c_str())){
			return new JDFTabDimensions(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Tabs.c_str())){
			return new JDFTabs(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Tape.c_str())){
			return new JDFTape(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_Test.c_str())){
			return new JDFTest(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_TestRef.c_str())){
			return new JDFTestRef(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_ThreadSealing.c_str())){
			return new JDFThreadSealing(part);
		};
		if(!wcscmp(pcResName,JDFElement::elm_ThreadSewing.c_str())){
			return new JDFThreadSewing(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_TIFFEmbeddedFile.c_str())){
			return new JDFTIFFEmbeddedFile(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_TIFFtag.c_str())){
			return new JDFTIFFtag(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Tile.c_str())){
			return new JDFTile(part);
		};
					
		if(!wcscmp(pcResName,JDFElement::elm_Tool.c_str())){
			return new JDFTool(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_TrackFilter.c_str())){
			return new JDFTrackFilter(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_TrackResult.c_str())){
			return new JDFTrackResult(part);
		};
					
		if(!wcscmp(pcResName,JDFElement::elm_TransferCurve.c_str())){
			return new JDFTransferCurve(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_TransferCurveSet.c_str())){
			return new JDFTransferCurveSet(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_TransferFunctionControl.c_str())){
			return new JDFTransferFunctionControl(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_TrappingDetails.c_str())){
			return new JDFTrappingDetails(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_TrappingOrder.c_str())){
			return new JDFTrappingOrder(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_TrapRegion.c_str())){
			return new JDFTrapRegion(part);
		};
		
		if(!wcscmp(pcResName,JDFElement::elm_Trigger.c_str())){
			return new JDFTrigger(part);
		};
		
		return 0;
	}


	JDFElement* JDFFactory::initRestV(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
		if(!wcscmp(pcResName,JDFElement::elm_Value.c_str())){
			return new JDFValue(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_ValueLoc.c_str())){
			return new JDFValueLoc(part);
		};

		return 0;
	}



	JDFElement* JDFFactory::initRestW(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{

		if(!wcscmp(pcResName,JDFElement::elm_when.c_str())){
			return new JDFwhen(part);
		};
					
		if(!wcscmp(pcResName,JDFElement::elm_WireCombBinding.c_str())){
			return new JDFWireCombBinding(part);
		};

		return 0;
	}



	JDFElement* JDFFactory::initRestX(const JDFCh* pcResName, const WString &typ, const JDFElement &part)
	{
			
		if(!wcscmp(pcResName,JDFElement::elm_xor.c_str())){
			return new JDFxor(part);
		};
	
		if(!wcscmp(pcResName,JDFElement::elm_XYPairEvaluation.c_str())){
			return new JDFXYPairEvaluation(part);
		};

		if(!wcscmp(pcResName,JDFElement::elm_XYPairState.c_str())){
			return new JDFXYPairState(part);
		};

		return 0;
	}
}
