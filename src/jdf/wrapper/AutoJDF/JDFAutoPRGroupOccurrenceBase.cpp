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


///////////////////////////////////////////////////////////////////

 
#include "jdf/wrapper/AutoJDF/JDFAutoPRGroupOccurrenceBase.h"
#include "jdf/wrapper/JDFQualityControlResult.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPRGroupOccurrenceBase : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPRGroupOccurrenceBase& JDFAutoPRGroupOccurrenceBase::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPRGroupOccurrenceBase: "+other.GetNodeName());
	return *this;
};

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPRGroupOccurrenceBase::ValidNodeNames()const{
	return L"*:,PRGroupOccurrenceBase";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPRGroupOccurrenceBase::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",PageNumber,AnnotationPrintFlag,AnnotationType,TrapnetAnnotationPDFX,BoundingBox,DifferentBoxSize,InsideBox,OutsideBox,ClassName,PropertyList,AliasSeparations,AmbiguousSeparations,InkCoverage,SeparationList,Author,Binding,CreationDate,CreationDateInDocument,CreationID")
	+WString(L",Creator,DocumentCompression,DocumentCorruption,DocumentEncoding,DocumentIsGoodCompression,EncryptedDocument,EncryptionFilter,EncryptionLength,EncryptionRestrictions,EncryptionSubFilter,EncryptionV,FileName,FileSize,Keywords,Linearized,ModificationDate,ModificationDateInDocument,ModificationID,NumberOfPages")
	+WString(L",OutputIntentColorSpace,OutputIntentStandard,PagesHaveSameOrientation,PDFXVersion,DocumentPDLType,PDLVersion,Producer,SeparationFlag,Subject,Title,TrappedKey,FillColorName,FillColorType,HasFillColor,EmbeddingRestrictionFlag,FontCorrupted,FontCreator,FontEmbedded,FontIsStandardLatin")
	+WString(L",FontName,FontNotUsed,FontSubset,FontType,FontVendor,IsDoubleByteFont,IsFontScreenOnly,PSFontName,AlphaIsShape,AlternateColorSpace,BelongsToAnnotation,BlackGeneration,BlendMode,ColorSpace,EmbeddedPS,Flatness,HasSoftMask,HalfTone,HalfTonePhase")
	+WString(L",HasColorLUT,NumberOfColorsInLUT,OverPrintFlag,OverPrintMode,RenderingIntent,Smoothness,TransferFunction,TransparencyFlag,UnderColorRemoval,AlternateImages,BitsPerSample,CompressionRatio,CompressionTypes,EffectiveResolution,EstimatedJPEGQuality,ImageFlipped,ImageMaskType,ImageRotation,ImageScalingRatio")
	+WString(L",ImageSkew,OriginalResolution,PixelHeight,PixelWidth,Count,PageBoxType,BlankPage,BlendColorSpace,PageHasOptionalContent,PageHasUnknownObjects,PageScalingFactor,ReversePageNumber,PDLObjectType,ExternalReferenceMissing,HasExternalReference,HasOPI,OPIMissing,OPIType,OPIVersion")
	+WString(L",ShadingType,HasStrokeColor,StrokeAlternateColorSpace,StrokeColorName,StrokeColorSpace,StrokeColorType,StrokeOverprintFlag,StrokeShadingType,StrokeThickness,CharacterProblem,MissingPrinterFont,MissingScreenFont,TextSize,UseArtificialTextEffect,NumberOfPathPoints");
};

/**
 typesafe validator
*/
	vWString JDFAutoPRGroupOccurrenceBase::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidPageNumber(level)) {
			vAtts.push_back(atr_PageNumber);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAnnotationPrintFlag(level)) {
			vAtts.push_back(atr_AnnotationPrintFlag);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAnnotationType(level)) {
			vAtts.push_back(atr_AnnotationType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrapnetAnnotationPDFX(level)) {
			vAtts.push_back(atr_TrapnetAnnotationPDFX);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBoundingBox(level)) {
			vAtts.push_back(atr_BoundingBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDifferentBoxSize(level)) {
			vAtts.push_back(atr_DifferentBoxSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidInsideBox(level)) {
			vAtts.push_back(atr_InsideBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOutsideBox(level)) {
			vAtts.push_back(atr_OutsideBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidClassName(level)) {
			vAtts.push_back(atr_ClassName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPropertyList(level)) {
			vAtts.push_back(atr_PropertyList);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAliasSeparations(level)) {
			vAtts.push_back(atr_AliasSeparations);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAmbiguousSeparations(level)) {
			vAtts.push_back(atr_AmbiguousSeparations);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidInkCoverage(level)) {
			vAtts.push_back(atr_InkCoverage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSeparationList(level)) {
			vAtts.push_back(atr_SeparationList);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAuthor(level)) {
			vAtts.push_back(atr_Author);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBinding(level)) {
			vAtts.push_back(atr_Binding);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCreationDate(level)) {
			vAtts.push_back(atr_CreationDate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCreationDateInDocument(level)) {
			vAtts.push_back(atr_CreationDateInDocument);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCreationID(level)) {
			vAtts.push_back(atr_CreationID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCreator(level)) {
			vAtts.push_back(atr_Creator);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDocumentCompression(level)) {
			vAtts.push_back(atr_DocumentCompression);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDocumentCorruption(level)) {
			vAtts.push_back(atr_DocumentCorruption);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDocumentEncoding(level)) {
			vAtts.push_back(atr_DocumentEncoding);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDocumentIsGoodCompression(level)) {
			vAtts.push_back(atr_DocumentIsGoodCompression);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEncryptedDocument(level)) {
			vAtts.push_back(atr_EncryptedDocument);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEncryptionFilter(level)) {
			vAtts.push_back(atr_EncryptionFilter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEncryptionLength(level)) {
			vAtts.push_back(atr_EncryptionLength);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEncryptionRestrictions(level)) {
			vAtts.push_back(atr_EncryptionRestrictions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEncryptionSubFilter(level)) {
			vAtts.push_back(atr_EncryptionSubFilter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEncryptionV(level)) {
			vAtts.push_back(atr_EncryptionV);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFileName(level)) {
			vAtts.push_back(atr_FileName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFileSize(level)) {
			vAtts.push_back(atr_FileSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidKeywords(level)) {
			vAtts.push_back(atr_Keywords);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLinearized(level)) {
			vAtts.push_back(atr_Linearized);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModificationDate(level)) {
			vAtts.push_back(atr_ModificationDate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModificationDateInDocument(level)) {
			vAtts.push_back(atr_ModificationDateInDocument);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModificationID(level)) {
			vAtts.push_back(atr_ModificationID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNumberOfPages(level)) {
			vAtts.push_back(atr_NumberOfPages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOutputIntentColorSpace(level)) {
			vAtts.push_back(atr_OutputIntentColorSpace);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOutputIntentStandard(level)) {
			vAtts.push_back(atr_OutputIntentStandard);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPagesHaveSameOrientation(level)) {
			vAtts.push_back(atr_PagesHaveSameOrientation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPDFXVersion(level)) {
			vAtts.push_back(atr_PDFXVersion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDocumentPDLType(level)) {
			vAtts.push_back(atr_DocumentPDLType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPDLVersion(level)) {
			vAtts.push_back(atr_PDLVersion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProducer(level)) {
			vAtts.push_back(atr_Producer);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSeparationFlag(level)) {
			vAtts.push_back(atr_SeparationFlag);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSubject(level)) {
			vAtts.push_back(atr_Subject);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTitle(level)) {
			vAtts.push_back(atr_Title);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrappedKey(level)) {
			vAtts.push_back(atr_TrappedKey);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFillColorName(level)) {
			vAtts.push_back(atr_FillColorName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFillColorType(level)) {
			vAtts.push_back(atr_FillColorType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHasFillColor(level)) {
			vAtts.push_back(atr_HasFillColor);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEmbeddingRestrictionFlag(level)) {
			vAtts.push_back(atr_EmbeddingRestrictionFlag);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFontCorrupted(level)) {
			vAtts.push_back(atr_FontCorrupted);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFontCreator(level)) {
			vAtts.push_back(atr_FontCreator);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFontEmbedded(level)) {
			vAtts.push_back(atr_FontEmbedded);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFontIsStandardLatin(level)) {
			vAtts.push_back(atr_FontIsStandardLatin);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFontName(level)) {
			vAtts.push_back(atr_FontName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFontNotUsed(level)) {
			vAtts.push_back(atr_FontNotUsed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFontSubset(level)) {
			vAtts.push_back(atr_FontSubset);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFontType(level)) {
			vAtts.push_back(atr_FontType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFontVendor(level)) {
			vAtts.push_back(atr_FontVendor);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIsDoubleByteFont(level)) {
			vAtts.push_back(atr_IsDoubleByteFont);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIsFontScreenOnly(level)) {
			vAtts.push_back(atr_IsFontScreenOnly);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPSFontName(level)) {
			vAtts.push_back(atr_PSFontName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAlphaIsShape(level)) {
			vAtts.push_back(atr_AlphaIsShape);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAlternateColorSpace(level)) {
			vAtts.push_back(atr_AlternateColorSpace);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBelongsToAnnotation(level)) {
			vAtts.push_back(atr_BelongsToAnnotation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlackGeneration(level)) {
			vAtts.push_back(atr_BlackGeneration);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlendMode(level)) {
			vAtts.push_back(atr_BlendMode);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidColorSpace(level)) {
			vAtts.push_back(atr_ColorSpace);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEmbeddedPS(level)) {
			vAtts.push_back(atr_EmbeddedPS);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFlatness(level)) {
			vAtts.push_back(atr_Flatness);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHasSoftMask(level)) {
			vAtts.push_back(atr_HasSoftMask);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHalfTone(level)) {
			vAtts.push_back(atr_HalfTone);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHalfTonePhase(level)) {
			vAtts.push_back(atr_HalfTonePhase);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHasColorLUT(level)) {
			vAtts.push_back(atr_HasColorLUT);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNumberOfColorsInLUT(level)) {
			vAtts.push_back(atr_NumberOfColorsInLUT);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOverPrintFlag(level)) {
			vAtts.push_back(atr_OverPrintFlag);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOverPrintMode(level)) {
			vAtts.push_back(atr_OverPrintMode);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRenderingIntent(level)) {
			vAtts.push_back(atr_RenderingIntent);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSmoothness(level)) {
			vAtts.push_back(atr_Smoothness);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTransferFunction(level)) {
			vAtts.push_back(atr_TransferFunction);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTransparencyFlag(level)) {
			vAtts.push_back(atr_TransparencyFlag);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUnderColorRemoval(level)) {
			vAtts.push_back(atr_UnderColorRemoval);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAlternateImages(level)) {
			vAtts.push_back(atr_AlternateImages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBitsPerSample(level)) {
			vAtts.push_back(atr_BitsPerSample);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCompressionRatio(level)) {
			vAtts.push_back(atr_CompressionRatio);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCompressionTypes(level)) {
			vAtts.push_back(atr_CompressionTypes);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEffectiveResolution(level)) {
			vAtts.push_back(atr_EffectiveResolution);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEstimatedJPEGQuality(level)) {
			vAtts.push_back(atr_EstimatedJPEGQuality);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageFlipped(level)) {
			vAtts.push_back(atr_ImageFlipped);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageMaskType(level)) {
			vAtts.push_back(atr_ImageMaskType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageRotation(level)) {
			vAtts.push_back(atr_ImageRotation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageScalingRatio(level)) {
			vAtts.push_back(atr_ImageScalingRatio);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageSkew(level)) {
			vAtts.push_back(atr_ImageSkew);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOriginalResolution(level)) {
			vAtts.push_back(atr_OriginalResolution);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPixelHeight(level)) {
			vAtts.push_back(atr_PixelHeight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPixelWidth(level)) {
			vAtts.push_back(atr_PixelWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCount(level)) {
			vAtts.push_back(atr_Count);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageBoxType(level)) {
			vAtts.push_back(atr_PageBoxType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlankPage(level)) {
			vAtts.push_back(atr_BlankPage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlendColorSpace(level)) {
			vAtts.push_back(atr_BlendColorSpace);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageHasOptionalContent(level)) {
			vAtts.push_back(atr_PageHasOptionalContent);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageHasUnknownObjects(level)) {
			vAtts.push_back(atr_PageHasUnknownObjects);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageScalingFactor(level)) {
			vAtts.push_back(atr_PageScalingFactor);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidReversePageNumber(level)) {
			vAtts.push_back(atr_ReversePageNumber);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPDLObjectType(level)) {
			vAtts.push_back(atr_PDLObjectType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidExternalReferenceMissing(level)) {
			vAtts.push_back(atr_ExternalReferenceMissing);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHasExternalReference(level)) {
			vAtts.push_back(atr_HasExternalReference);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHasOPI(level)) {
			vAtts.push_back(atr_HasOPI);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOPIMissing(level)) {
			vAtts.push_back(atr_OPIMissing);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOPIType(level)) {
			vAtts.push_back(atr_OPIType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOPIVersion(level)) {
			vAtts.push_back(atr_OPIVersion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShadingType(level)) {
			vAtts.push_back(atr_ShadingType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHasStrokeColor(level)) {
			vAtts.push_back(atr_HasStrokeColor);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStrokeAlternateColorSpace(level)) {
			vAtts.push_back(atr_StrokeAlternateColorSpace);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStrokeColorName(level)) {
			vAtts.push_back(atr_StrokeColorName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStrokeColorSpace(level)) {
			vAtts.push_back(atr_StrokeColorSpace);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStrokeColorType(level)) {
			vAtts.push_back(atr_StrokeColorType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStrokeOverprintFlag(level)) {
			vAtts.push_back(atr_StrokeOverprintFlag);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStrokeShadingType(level)) {
			vAtts.push_back(atr_StrokeShadingType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStrokeThickness(level)) {
			vAtts.push_back(atr_StrokeThickness);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCharacterProblem(level)) {
			vAtts.push_back(atr_CharacterProblem);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMissingPrinterFont(level)) {
			vAtts.push_back(atr_MissingPrinterFont);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMissingScreenFont(level)) {
			vAtts.push_back(atr_MissingScreenFont);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTextSize(level)) {
			vAtts.push_back(atr_TextSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUseArtificialTextEffect(level)) {
			vAtts.push_back(atr_UseArtificialTextEffect);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNumberOfPathPoints(level)) {
			vAtts.push_back(atr_NumberOfPathPoints);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute PageNumber
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetPageNumber(int value){
	SetAttribute(atr_PageNumber,WString::valueOf(value));
};
/**
* Get integer attribute PageNumber
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRGroupOccurrenceBase::GetPageNumber() const {
	return GetIntAttribute(atr_PageNumber,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidPageNumber(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageNumber,AttributeType_integer,false);
	};
/**
* Set attribute AnnotationPrintFlag
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetAnnotationPrintFlag(bool value){
	SetAttribute(atr_AnnotationPrintFlag,WString::valueOf(value));
};
/**
* Get bool attribute AnnotationPrintFlag
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetAnnotationPrintFlag() const {return GetBoolAttribute(atr_AnnotationPrintFlag,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidAnnotationPrintFlag(EnumValidationLevel level) const {
		return ValidAttribute(atr_AnnotationPrintFlag,AttributeType_boolean,false);
	};
/**
* Set attribute AnnotationType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetAnnotationType(const WString& value){
	SetAttribute(atr_AnnotationType,value);
};
/**
* Get string attribute AnnotationType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetAnnotationType() const {
	return GetAttribute(atr_AnnotationType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidAnnotationType(EnumValidationLevel level) const {
		return ValidAttribute(atr_AnnotationType,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute TrapnetAnnotationPDFX
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetTrapnetAnnotationPDFX(const vWString& value){
	SetAttribute(atr_TrapnetAnnotationPDFX,value);
};
/**
* Get string attribute TrapnetAnnotationPDFX
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPRGroupOccurrenceBase::GetTrapnetAnnotationPDFX() const {
	return GetAttribute(atr_TrapnetAnnotationPDFX,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidTrapnetAnnotationPDFX(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrapnetAnnotationPDFX,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute BoundingBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetBoundingBox(const JDFRectangle& value){
	SetAttribute(atr_BoundingBox,value);
};
/**
* Get string attribute BoundingBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoPRGroupOccurrenceBase::GetBoundingBox() const {
	return GetAttribute(atr_BoundingBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidBoundingBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_BoundingBox,AttributeType_rectangle,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::DifferentBoxSizeString(){
		static const WString enums=WString(L"Unknown,ArtBox,BleedBox,CropBox,MarginsBox,MediaBox,SlugBox,TrimBox");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::DifferentBoxSizeString(EnumDifferentBoxSize value){
		return DifferentBoxSizeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetDifferentBoxSize( EnumDifferentBoxSize value){
	SetEnumAttribute(atr_DifferentBoxSize,value,DifferentBoxSizeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumDifferentBoxSize JDFAutoPRGroupOccurrenceBase:: GetDifferentBoxSize() const {
	return (EnumDifferentBoxSize) GetEnumAttribute(atr_DifferentBoxSize,DifferentBoxSizeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidDifferentBoxSize(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DifferentBoxSize,DifferentBoxSizeString(),false);
	};
/**
* Set attribute InsideBox
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetInsideBox(bool value){
	SetAttribute(atr_InsideBox,WString::valueOf(value));
};
/**
* Get bool attribute InsideBox
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetInsideBox() const {return GetBoolAttribute(atr_InsideBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidInsideBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_InsideBox,AttributeType_boolean,false);
	};
/**
* Set attribute OutsideBox
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetOutsideBox(bool value){
	SetAttribute(atr_OutsideBox,WString::valueOf(value));
};
/**
* Get bool attribute OutsideBox
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetOutsideBox() const {return GetBoolAttribute(atr_OutsideBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidOutsideBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_OutsideBox,AttributeType_boolean,false);
	};
/**
* Set attribute ClassName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetClassName(const WString& value){
	SetAttribute(atr_ClassName,value);
};
/**
* Get string attribute ClassName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetClassName() const {
	return GetAttribute(atr_ClassName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidClassName(EnumValidationLevel level) const {
		return ValidAttribute(atr_ClassName,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::PropertyListString(){
		static const WString enums=WString(L"Unknown,Annotation,Box,Class,Colorant,Document,Fill,Font,Graphic,Image")
	+WString(L",Logical,Page,PageBox,PDLObject,Reference,Shading,Stroke,Text,Vector");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::PropertyListString(EnumPropertyList value){
		return PropertyListString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoPRGroupOccurrenceBase::AddPropertyList( EnumPropertyList value){
	return AddEnumerationsAttribute(atr_PropertyList,value,PropertyListString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoPRGroupOccurrenceBase::RemovePropertyList( EnumPropertyList value){
	return RemoveEnumerationsAttribute(atr_PropertyList,value,PropertyListString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoPRGroupOccurrenceBase::GetPropertyList() const {
	return GetEnumerationsAttribute(atr_PropertyList,PropertyListString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetPropertyList( EnumPropertyList value){
	SetEnumAttribute(atr_PropertyList,value,PropertyListString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetPropertyList( const vint& value){
	SetEnumerationsAttribute(atr_PropertyList,value,PropertyListString());
};
/**
* Typesafe attribute validation of PropertyList
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidPropertyList(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_PropertyList,PropertyListString(),false);
	};
/**
* Set attribute AliasSeparations
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetAliasSeparations(bool value){
	SetAttribute(atr_AliasSeparations,WString::valueOf(value));
};
/**
* Get bool attribute AliasSeparations
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetAliasSeparations() const {return GetBoolAttribute(atr_AliasSeparations,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidAliasSeparations(EnumValidationLevel level) const {
		return ValidAttribute(atr_AliasSeparations,AttributeType_boolean,false);
	};
/**
* Set attribute AmbiguousSeparations
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetAmbiguousSeparations(bool value){
	SetAttribute(atr_AmbiguousSeparations,WString::valueOf(value));
};
/**
* Get bool attribute AmbiguousSeparations
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetAmbiguousSeparations() const {return GetBoolAttribute(atr_AmbiguousSeparations,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidAmbiguousSeparations(EnumValidationLevel level) const {
		return ValidAttribute(atr_AmbiguousSeparations,AttributeType_boolean,false);
	};
/**
* Set attribute InkCoverage
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetInkCoverage(double value){
	SetAttribute(atr_InkCoverage,WString::valueOf(value));
};
/**
* Get double attribute InkCoverage
* @return double the vaue of the attribute 
*/
	 double JDFAutoPRGroupOccurrenceBase::GetInkCoverage() const {
	return GetRealAttribute(atr_InkCoverage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidInkCoverage(EnumValidationLevel level) const {
		return ValidAttribute(atr_InkCoverage,AttributeType_double,false);
	};
/**
* Set attribute SeparationList
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetSeparationList(const WString& value){
	SetAttribute(atr_SeparationList,value);
};
/**
* Get string attribute SeparationList
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetSeparationList() const {
	return GetAttribute(atr_SeparationList,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidSeparationList(EnumValidationLevel level) const {
		return ValidAttribute(atr_SeparationList,AttributeType_string,false);
	};
/**
* Set attribute Author
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetAuthor(const WString& value){
	SetAttribute(atr_Author,value);
};
/**
* Get string attribute Author
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetAuthor() const {
	return GetAttribute(atr_Author,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidAuthor(EnumValidationLevel level) const {
		return ValidAttribute(atr_Author,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::BindingString(){
		static const WString enums=WString(L"Unknown,Left,Right");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::BindingString(EnumBinding value){
		return BindingString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetBinding( EnumBinding value){
	SetEnumAttribute(atr_Binding,value,BindingString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumBinding JDFAutoPRGroupOccurrenceBase:: GetBinding() const {
	return (EnumBinding) GetEnumAttribute(atr_Binding,BindingString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidBinding(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Binding,BindingString(),false);
	};
/**
* Set attribute CreationDate
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetCreationDate(JDFDate value){
	SetAttribute(atr_CreationDate,value.DateTimeISO());
};
/**
* Get string attribute CreationDate
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoPRGroupOccurrenceBase::GetCreationDate() const {
	return GetAttribute(atr_CreationDate,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidCreationDate(EnumValidationLevel level) const {
		return ValidAttribute(atr_CreationDate,AttributeType_dateTime,false);
	};
/**
* Set attribute CreationDateInDocument
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetCreationDateInDocument(JDFDate value){
	SetAttribute(atr_CreationDateInDocument,value.DateTimeISO());
};
/**
* Get string attribute CreationDateInDocument
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoPRGroupOccurrenceBase::GetCreationDateInDocument() const {
	return GetAttribute(atr_CreationDateInDocument,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidCreationDateInDocument(EnumValidationLevel level) const {
		return ValidAttribute(atr_CreationDateInDocument,AttributeType_dateTime,false);
	};
/**
* Set attribute CreationID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetCreationID(const WString& value){
	SetAttribute(atr_CreationID,value);
};
/**
* Get string attribute CreationID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetCreationID() const {
	return GetAttribute(atr_CreationID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidCreationID(EnumValidationLevel level) const {
		return ValidAttribute(atr_CreationID,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Creator
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetCreator(const WString& value){
	SetAttribute(atr_Creator,value);
};
/**
* Get string attribute Creator
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetCreator() const {
	return GetAttribute(atr_Creator,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidCreator(EnumValidationLevel level) const {
		return ValidAttribute(atr_Creator,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::DocumentCompressionString(){
		static const WString enums=WString(L"Unknown,ASCII85,ASCIIHex,CCITT,JBIG2,JPEG,JPEG2000,LZW,None,RunLength")
	+WString(L",ZIP");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::DocumentCompressionString(EnumDocumentCompression value){
		return DocumentCompressionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoPRGroupOccurrenceBase::AddDocumentCompression( EnumDocumentCompression value){
	return AddEnumerationsAttribute(atr_DocumentCompression,value,DocumentCompressionString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoPRGroupOccurrenceBase::RemoveDocumentCompression( EnumDocumentCompression value){
	return RemoveEnumerationsAttribute(atr_DocumentCompression,value,DocumentCompressionString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoPRGroupOccurrenceBase::GetDocumentCompression() const {
	return GetEnumerationsAttribute(atr_DocumentCompression,DocumentCompressionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetDocumentCompression( EnumDocumentCompression value){
	SetEnumAttribute(atr_DocumentCompression,value,DocumentCompressionString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetDocumentCompression( const vint& value){
	SetEnumerationsAttribute(atr_DocumentCompression,value,DocumentCompressionString());
};
/**
* Typesafe attribute validation of DocumentCompression
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidDocumentCompression(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_DocumentCompression,DocumentCompressionString(),false);
	};
/**
* Set attribute DocumentCorruption
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetDocumentCorruption(const vWString& value){
	SetAttribute(atr_DocumentCorruption,value);
};
/**
* Get string attribute DocumentCorruption
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPRGroupOccurrenceBase::GetDocumentCorruption() const {
	return GetAttribute(atr_DocumentCorruption,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidDocumentCorruption(EnumValidationLevel level) const {
		return ValidAttribute(atr_DocumentCorruption,AttributeType_NMTOKENS,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::DocumentEncodingString(){
		static const WString enums=WString(L"Unknown,ASCII,Binary");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::DocumentEncodingString(EnumDocumentEncoding value){
		return DocumentEncodingString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetDocumentEncoding( EnumDocumentEncoding value){
	SetEnumAttribute(atr_DocumentEncoding,value,DocumentEncodingString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumDocumentEncoding JDFAutoPRGroupOccurrenceBase:: GetDocumentEncoding() const {
	return (EnumDocumentEncoding) GetEnumAttribute(atr_DocumentEncoding,DocumentEncodingString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidDocumentEncoding(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DocumentEncoding,DocumentEncodingString(),false);
	};
/**
* Set attribute DocumentIsGoodCompression
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetDocumentIsGoodCompression(bool value){
	SetAttribute(atr_DocumentIsGoodCompression,WString::valueOf(value));
};
/**
* Get bool attribute DocumentIsGoodCompression
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetDocumentIsGoodCompression() const {return GetBoolAttribute(atr_DocumentIsGoodCompression,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidDocumentIsGoodCompression(EnumValidationLevel level) const {
		return ValidAttribute(atr_DocumentIsGoodCompression,AttributeType_boolean,false);
	};
/**
* Set attribute EncryptedDocument
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetEncryptedDocument(bool value){
	SetAttribute(atr_EncryptedDocument,WString::valueOf(value));
};
/**
* Get bool attribute EncryptedDocument
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetEncryptedDocument() const {return GetBoolAttribute(atr_EncryptedDocument,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidEncryptedDocument(EnumValidationLevel level) const {
		return ValidAttribute(atr_EncryptedDocument,AttributeType_boolean,false);
	};
/**
* Set attribute EncryptionFilter
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetEncryptionFilter(const WString& value){
	SetAttribute(atr_EncryptionFilter,value);
};
/**
* Get string attribute EncryptionFilter
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetEncryptionFilter() const {
	return GetAttribute(atr_EncryptionFilter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidEncryptionFilter(EnumValidationLevel level) const {
		return ValidAttribute(atr_EncryptionFilter,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute EncryptionLength
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetEncryptionLength(int value){
	SetAttribute(atr_EncryptionLength,WString::valueOf(value));
};
/**
* Get integer attribute EncryptionLength
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRGroupOccurrenceBase::GetEncryptionLength() const {
	return GetIntAttribute(atr_EncryptionLength,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidEncryptionLength(EnumValidationLevel level) const {
		return ValidAttribute(atr_EncryptionLength,AttributeType_integer,false);
	};
/**
* Set attribute EncryptionRestrictions
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetEncryptionRestrictions(const vWString& value){
	SetAttribute(atr_EncryptionRestrictions,value);
};
/**
* Get string attribute EncryptionRestrictions
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPRGroupOccurrenceBase::GetEncryptionRestrictions() const {
	return GetAttribute(atr_EncryptionRestrictions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidEncryptionRestrictions(EnumValidationLevel level) const {
		return ValidAttribute(atr_EncryptionRestrictions,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute EncryptionSubFilter
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetEncryptionSubFilter(const WString& value){
	SetAttribute(atr_EncryptionSubFilter,value);
};
/**
* Get string attribute EncryptionSubFilter
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetEncryptionSubFilter() const {
	return GetAttribute(atr_EncryptionSubFilter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidEncryptionSubFilter(EnumValidationLevel level) const {
		return ValidAttribute(atr_EncryptionSubFilter,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute EncryptionV
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetEncryptionV(int value){
	SetAttribute(atr_EncryptionV,WString::valueOf(value));
};
/**
* Get integer attribute EncryptionV
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRGroupOccurrenceBase::GetEncryptionV() const {
	return GetIntAttribute(atr_EncryptionV,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidEncryptionV(EnumValidationLevel level) const {
		return ValidAttribute(atr_EncryptionV,AttributeType_integer,false);
	};
/**
* Set attribute FileName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetFileName(const WString& value){
	SetAttribute(atr_FileName,value);
};
/**
* Get string attribute FileName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetFileName() const {
	return GetAttribute(atr_FileName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidFileName(EnumValidationLevel level) const {
		return ValidAttribute(atr_FileName,AttributeType_string,false);
	};
/**
* Set attribute FileSize
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetFileSize(int value){
	SetAttribute(atr_FileSize,WString::valueOf(value));
};
/**
* Get integer attribute FileSize
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRGroupOccurrenceBase::GetFileSize() const {
	return GetIntAttribute(atr_FileSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidFileSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_FileSize,AttributeType_integer,false);
	};
/**
* Set attribute Keywords
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetKeywords(const WString& value){
	SetAttribute(atr_Keywords,value);
};
/**
* Get string attribute Keywords
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetKeywords() const {
	return GetAttribute(atr_Keywords,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidKeywords(EnumValidationLevel level) const {
		return ValidAttribute(atr_Keywords,AttributeType_string,false);
	};
/**
* Set attribute Linearized
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetLinearized(bool value){
	SetAttribute(atr_Linearized,WString::valueOf(value));
};
/**
* Get bool attribute Linearized
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetLinearized() const {return GetBoolAttribute(atr_Linearized,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidLinearized(EnumValidationLevel level) const {
		return ValidAttribute(atr_Linearized,AttributeType_boolean,false);
	};
/**
* Set attribute ModificationDate
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetModificationDate(JDFDate value){
	SetAttribute(atr_ModificationDate,value.DateTimeISO());
};
/**
* Get string attribute ModificationDate
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoPRGroupOccurrenceBase::GetModificationDate() const {
	return GetAttribute(atr_ModificationDate,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidModificationDate(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModificationDate,AttributeType_dateTime,false);
	};
/**
* Set attribute ModificationDateInDocument
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetModificationDateInDocument(JDFDate value){
	SetAttribute(atr_ModificationDateInDocument,value.DateTimeISO());
};
/**
* Get string attribute ModificationDateInDocument
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoPRGroupOccurrenceBase::GetModificationDateInDocument() const {
	return GetAttribute(atr_ModificationDateInDocument,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidModificationDateInDocument(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModificationDateInDocument,AttributeType_dateTime,false);
	};
/**
* Set attribute ModificationID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetModificationID(const WString& value){
	SetAttribute(atr_ModificationID,value);
};
/**
* Get string attribute ModificationID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetModificationID() const {
	return GetAttribute(atr_ModificationID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidModificationID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModificationID,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute NumberOfPages
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetNumberOfPages(int value){
	SetAttribute(atr_NumberOfPages,WString::valueOf(value));
};
/**
* Get integer attribute NumberOfPages
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRGroupOccurrenceBase::GetNumberOfPages() const {
	return GetIntAttribute(atr_NumberOfPages,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidNumberOfPages(EnumValidationLevel level) const {
		return ValidAttribute(atr_NumberOfPages,AttributeType_integer,false);
	};
/**
* Set attribute OutputIntentColorSpace
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetOutputIntentColorSpace(const WString& value){
	SetAttribute(atr_OutputIntentColorSpace,value);
};
/**
* Get string attribute OutputIntentColorSpace
* @return WString the vaue of the attribute ; defaults to None
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetOutputIntentColorSpace() const {
	return GetAttribute(atr_OutputIntentColorSpace,WString::emptyStr,L"None");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidOutputIntentColorSpace(EnumValidationLevel level) const {
		return ValidAttribute(atr_OutputIntentColorSpace,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute OutputIntentStandard
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetOutputIntentStandard(const WString& value){
	SetAttribute(atr_OutputIntentStandard,value);
};
/**
* Get string attribute OutputIntentStandard
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetOutputIntentStandard() const {
	return GetAttribute(atr_OutputIntentStandard,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidOutputIntentStandard(EnumValidationLevel level) const {
		return ValidAttribute(atr_OutputIntentStandard,AttributeType_string,false);
	};
/**
* Set attribute PagesHaveSameOrientation
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetPagesHaveSameOrientation(bool value){
	SetAttribute(atr_PagesHaveSameOrientation,WString::valueOf(value));
};
/**
* Get bool attribute PagesHaveSameOrientation
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetPagesHaveSameOrientation() const {return GetBoolAttribute(atr_PagesHaveSameOrientation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidPagesHaveSameOrientation(EnumValidationLevel level) const {
		return ValidAttribute(atr_PagesHaveSameOrientation,AttributeType_boolean,false);
	};
/**
* Set attribute PDFXVersion
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetPDFXVersion(const WString& value){
	SetAttribute(atr_PDFXVersion,value);
};
/**
* Get string attribute PDFXVersion
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetPDFXVersion() const {
	return GetAttribute(atr_PDFXVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidPDFXVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_PDFXVersion,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute DocumentPDLType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetDocumentPDLType(const WString& value){
	SetAttribute(atr_DocumentPDLType,value);
};
/**
* Get string attribute DocumentPDLType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetDocumentPDLType() const {
	return GetAttribute(atr_DocumentPDLType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidDocumentPDLType(EnumValidationLevel level) const {
		return ValidAttribute(atr_DocumentPDLType,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute PDLVersion
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetPDLVersion(const WString& value){
	SetAttribute(atr_PDLVersion,value);
};
/**
* Get string attribute PDLVersion
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetPDLVersion() const {
	return GetAttribute(atr_PDLVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidPDLVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_PDLVersion,AttributeType_string,false);
	};
/**
* Set attribute Producer
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetProducer(const WString& value){
	SetAttribute(atr_Producer,value);
};
/**
* Get string attribute Producer
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetProducer() const {
	return GetAttribute(atr_Producer,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidProducer(EnumValidationLevel level) const {
		return ValidAttribute(atr_Producer,AttributeType_string,false);
	};
/**
* Set attribute SeparationFlag
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetSeparationFlag(bool value){
	SetAttribute(atr_SeparationFlag,WString::valueOf(value));
};
/**
* Get bool attribute SeparationFlag
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetSeparationFlag() const {return GetBoolAttribute(atr_SeparationFlag,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidSeparationFlag(EnumValidationLevel level) const {
		return ValidAttribute(atr_SeparationFlag,AttributeType_boolean,false);
	};
/**
* Set attribute Subject
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetSubject(const WString& value){
	SetAttribute(atr_Subject,value);
};
/**
* Get string attribute Subject
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetSubject() const {
	return GetAttribute(atr_Subject,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidSubject(EnumValidationLevel level) const {
		return ValidAttribute(atr_Subject,AttributeType_string,false);
	};
/**
* Set attribute Title
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetTitle(const WString& value){
	SetAttribute(atr_Title,value);
};
/**
* Get string attribute Title
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetTitle() const {
	return GetAttribute(atr_Title,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidTitle(EnumValidationLevel level) const {
		return ValidAttribute(atr_Title,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::TrappedKeyString(){
		static const WString enums=WString(L"Unknown,True,False");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::TrappedKeyString(EnumTrappedKey value){
		return TrappedKeyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetTrappedKey( EnumTrappedKey value){
	SetEnumAttribute(atr_TrappedKey,value,TrappedKeyString(),WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumTrappedKey JDFAutoPRGroupOccurrenceBase:: GetTrappedKey() const {
	return (EnumTrappedKey) GetEnumAttribute(atr_TrappedKey,TrappedKeyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidTrappedKey(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_TrappedKey,TrappedKeyString(),false,WString::emptyStr,true);
	};
/**
* Set attribute FillColorName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetFillColorName(const WString& value){
	SetAttribute(atr_FillColorName,value);
};
/**
* Get string attribute FillColorName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetFillColorName() const {
	return GetAttribute(atr_FillColorName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidFillColorName(EnumValidationLevel level) const {
		return ValidAttribute(atr_FillColorName,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::FillColorTypeString(){
		static const WString enums=WString(L"Unknown,CMYGray,CMYBlack,Other,PureBlack,PureGray,RegistrationBlack,RegistrationGray,RichBlack,White");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::FillColorTypeString(EnumFillColorType value){
		return FillColorTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetFillColorType( EnumFillColorType value){
	SetEnumAttribute(atr_FillColorType,value,FillColorTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumFillColorType JDFAutoPRGroupOccurrenceBase:: GetFillColorType() const {
	return (EnumFillColorType) GetEnumAttribute(atr_FillColorType,FillColorTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidFillColorType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_FillColorType,FillColorTypeString(),false);
	};
/**
* Set attribute HasFillColor
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetHasFillColor(bool value){
	SetAttribute(atr_HasFillColor,WString::valueOf(value));
};
/**
* Get bool attribute HasFillColor
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetHasFillColor() const {return GetBoolAttribute(atr_HasFillColor,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidHasFillColor(EnumValidationLevel level) const {
		return ValidAttribute(atr_HasFillColor,AttributeType_boolean,false);
	};
/**
* Set attribute EmbeddingRestrictionFlag
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetEmbeddingRestrictionFlag(bool value){
	SetAttribute(atr_EmbeddingRestrictionFlag,WString::valueOf(value));
};
/**
* Get bool attribute EmbeddingRestrictionFlag
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetEmbeddingRestrictionFlag() const {return GetBoolAttribute(atr_EmbeddingRestrictionFlag,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidEmbeddingRestrictionFlag(EnumValidationLevel level) const {
		return ValidAttribute(atr_EmbeddingRestrictionFlag,AttributeType_boolean,false);
	};
/**
* Set attribute FontCorrupted
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetFontCorrupted(bool value){
	SetAttribute(atr_FontCorrupted,WString::valueOf(value));
};
/**
* Get bool attribute FontCorrupted
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetFontCorrupted() const {return GetBoolAttribute(atr_FontCorrupted,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidFontCorrupted(EnumValidationLevel level) const {
		return ValidAttribute(atr_FontCorrupted,AttributeType_boolean,false);
	};
/**
* Set attribute FontCreator
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetFontCreator(const WString& value){
	SetAttribute(atr_FontCreator,value);
};
/**
* Get string attribute FontCreator
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetFontCreator() const {
	return GetAttribute(atr_FontCreator,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidFontCreator(EnumValidationLevel level) const {
		return ValidAttribute(atr_FontCreator,AttributeType_string,false);
	};
/**
* Set attribute FontEmbedded
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetFontEmbedded(bool value){
	SetAttribute(atr_FontEmbedded,WString::valueOf(value));
};
/**
* Get bool attribute FontEmbedded
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetFontEmbedded() const {return GetBoolAttribute(atr_FontEmbedded,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidFontEmbedded(EnumValidationLevel level) const {
		return ValidAttribute(atr_FontEmbedded,AttributeType_boolean,false);
	};
/**
* Set attribute FontIsStandardLatin
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetFontIsStandardLatin(bool value){
	SetAttribute(atr_FontIsStandardLatin,WString::valueOf(value));
};
/**
* Get bool attribute FontIsStandardLatin
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetFontIsStandardLatin() const {return GetBoolAttribute(atr_FontIsStandardLatin,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidFontIsStandardLatin(EnumValidationLevel level) const {
		return ValidAttribute(atr_FontIsStandardLatin,AttributeType_boolean,false);
	};
/**
* Set attribute FontName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetFontName(const WString& value){
	SetAttribute(atr_FontName,value);
};
/**
* Get string attribute FontName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetFontName() const {
	return GetAttribute(atr_FontName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidFontName(EnumValidationLevel level) const {
		return ValidAttribute(atr_FontName,AttributeType_string,false);
	};
/**
* Set attribute FontNotUsed
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetFontNotUsed(bool value){
	SetAttribute(atr_FontNotUsed,WString::valueOf(value));
};
/**
* Get bool attribute FontNotUsed
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetFontNotUsed() const {return GetBoolAttribute(atr_FontNotUsed,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidFontNotUsed(EnumValidationLevel level) const {
		return ValidAttribute(atr_FontNotUsed,AttributeType_boolean,false);
	};
/**
* Set attribute FontSubset
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetFontSubset(bool value){
	SetAttribute(atr_FontSubset,WString::valueOf(value));
};
/**
* Get bool attribute FontSubset
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetFontSubset() const {return GetBoolAttribute(atr_FontSubset,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidFontSubset(EnumValidationLevel level) const {
		return ValidAttribute(atr_FontSubset,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::FontTypeString(){
		static const WString enums=WString(L"Unknown,CIDFontType0,CIDFontType1,CIDFontType2,CIDFontType3,CIDFontType4,OpenType,TrueType,Type0,Type1")
	+WString(L",Type1MultipleMaster,Type2C,Type3,PDFType3,Type42,Other");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::FontTypeString(EnumFontType value){
		return FontTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetFontType( EnumFontType value){
	SetEnumAttribute(atr_FontType,value,FontTypeString(),WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumFontType JDFAutoPRGroupOccurrenceBase:: GetFontType() const {
	return (EnumFontType) GetEnumAttribute(atr_FontType,FontTypeString(),WString::emptyStr,FontType_Other);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidFontType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_FontType,FontTypeString(),false,WString::emptyStr,true);
	};
/**
* Set attribute FontVendor
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetFontVendor(const WString& value){
	SetAttribute(atr_FontVendor,value);
};
/**
* Get string attribute FontVendor
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetFontVendor() const {
	return GetAttribute(atr_FontVendor,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidFontVendor(EnumValidationLevel level) const {
		return ValidAttribute(atr_FontVendor,AttributeType_string,false);
	};
/**
* Set attribute IsDoubleByteFont
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetIsDoubleByteFont(bool value){
	SetAttribute(atr_IsDoubleByteFont,WString::valueOf(value));
};
/**
* Get bool attribute IsDoubleByteFont
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetIsDoubleByteFont() const {return GetBoolAttribute(atr_IsDoubleByteFont,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidIsDoubleByteFont(EnumValidationLevel level) const {
		return ValidAttribute(atr_IsDoubleByteFont,AttributeType_boolean,false);
	};
/**
* Set attribute IsFontScreenOnly
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetIsFontScreenOnly(bool value){
	SetAttribute(atr_IsFontScreenOnly,WString::valueOf(value));
};
/**
* Get bool attribute IsFontScreenOnly
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetIsFontScreenOnly() const {return GetBoolAttribute(atr_IsFontScreenOnly,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidIsFontScreenOnly(EnumValidationLevel level) const {
		return ValidAttribute(atr_IsFontScreenOnly,AttributeType_boolean,false);
	};
/**
* Set attribute PSFontName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetPSFontName(const WString& value){
	SetAttribute(atr_PSFontName,value);
};
/**
* Get string attribute PSFontName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetPSFontName() const {
	return GetAttribute(atr_PSFontName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidPSFontName(EnumValidationLevel level) const {
		return ValidAttribute(atr_PSFontName,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute AlphaIsShape
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetAlphaIsShape(bool value){
	SetAttribute(atr_AlphaIsShape,WString::valueOf(value));
};
/**
* Get bool attribute AlphaIsShape
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetAlphaIsShape() const {return GetBoolAttribute(atr_AlphaIsShape,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidAlphaIsShape(EnumValidationLevel level) const {
		return ValidAttribute(atr_AlphaIsShape,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::AlternateColorSpaceString(){
		static const WString enums=WString(L"Unknown,CalGray,CalRGB,CIEBasedA,CIEBasedABC,CIEBasedDEFG,DeviceCMYK,DeviceGray,DeviceN,DeviceRGB")
	+WString(L",ICCBased,Lab");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::AlternateColorSpaceString(EnumAlternateColorSpace value){
		return AlternateColorSpaceString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetAlternateColorSpace( EnumAlternateColorSpace value){
	SetEnumAttribute(atr_AlternateColorSpace,value,AlternateColorSpaceString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumAlternateColorSpace JDFAutoPRGroupOccurrenceBase:: GetAlternateColorSpace() const {
	return (EnumAlternateColorSpace) GetEnumAttribute(atr_AlternateColorSpace,AlternateColorSpaceString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidAlternateColorSpace(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_AlternateColorSpace,AlternateColorSpaceString(),false);
	};
/**
* Set attribute BelongsToAnnotation
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetBelongsToAnnotation(bool value){
	SetAttribute(atr_BelongsToAnnotation,WString::valueOf(value));
};
/**
* Get bool attribute BelongsToAnnotation
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetBelongsToAnnotation() const {return GetBoolAttribute(atr_BelongsToAnnotation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidBelongsToAnnotation(EnumValidationLevel level) const {
		return ValidAttribute(atr_BelongsToAnnotation,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::BlackGenerationString(){
		static const WString enums=WString(L"Unknown,Identity,Custom");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::BlackGenerationString(EnumBlackGeneration value){
		return BlackGenerationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetBlackGeneration( EnumBlackGeneration value){
	SetEnumAttribute(atr_BlackGeneration,value,BlackGenerationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumBlackGeneration JDFAutoPRGroupOccurrenceBase:: GetBlackGeneration() const {
	return (EnumBlackGeneration) GetEnumAttribute(atr_BlackGeneration,BlackGenerationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidBlackGeneration(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BlackGeneration,BlackGenerationString(),false);
	};
/**
* Set attribute BlendMode
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetBlendMode(const WString& value){
	SetAttribute(atr_BlendMode,value);
};
/**
* Get string attribute BlendMode
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetBlendMode() const {
	return GetAttribute(atr_BlendMode,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidBlendMode(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlendMode,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::ColorSpaceString(){
		static const WString enums=WString(L"Unknown,CalGray,CalRGB,CIEBasedA,CIEBasedABC,CIEBasedDEFG,DeviceCMYK,DeviceGray,DeviceN,DeviceRGB")
	+WString(L",ICCBased,Lab");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::ColorSpaceString(EnumColorSpace value){
		return ColorSpaceString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetColorSpace( EnumColorSpace value){
	SetEnumAttribute(atr_ColorSpace,value,ColorSpaceString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumColorSpace JDFAutoPRGroupOccurrenceBase:: GetColorSpace() const {
	return (EnumColorSpace) GetEnumAttribute(atr_ColorSpace,ColorSpaceString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidColorSpace(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ColorSpace,ColorSpaceString(),false);
	};
/**
* Set attribute EmbeddedPS
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetEmbeddedPS(bool value){
	SetAttribute(atr_EmbeddedPS,WString::valueOf(value));
};
/**
* Get bool attribute EmbeddedPS
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetEmbeddedPS() const {return GetBoolAttribute(atr_EmbeddedPS,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidEmbeddedPS(EnumValidationLevel level) const {
		return ValidAttribute(atr_EmbeddedPS,AttributeType_boolean,false);
	};
/**
* Set attribute Flatness
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetFlatness(double value){
	SetAttribute(atr_Flatness,WString::valueOf(value));
};
/**
* Get double attribute Flatness
* @return double the vaue of the attribute 
*/
	 double JDFAutoPRGroupOccurrenceBase::GetFlatness() const {
	return GetRealAttribute(atr_Flatness,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidFlatness(EnumValidationLevel level) const {
		return ValidAttribute(atr_Flatness,AttributeType_double,false);
	};
/**
* Set attribute HasSoftMask
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetHasSoftMask(bool value){
	SetAttribute(atr_HasSoftMask,WString::valueOf(value));
};
/**
* Get bool attribute HasSoftMask
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetHasSoftMask() const {return GetBoolAttribute(atr_HasSoftMask,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidHasSoftMask(EnumValidationLevel level) const {
		return ValidAttribute(atr_HasSoftMask,AttributeType_boolean,false);
	};
/**
* Set attribute HalfTone
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetHalfTone(const WString& value){
	SetAttribute(atr_HalfTone,value);
};
/**
* Get string attribute HalfTone
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetHalfTone() const {
	return GetAttribute(atr_HalfTone,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidHalfTone(EnumValidationLevel level) const {
		return ValidAttribute(atr_HalfTone,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute HalfTonePhase
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetHalfTonePhase(const JDFXYPair& value){
	SetAttribute(atr_HalfTonePhase,value);
};
/**
* Get string attribute HalfTonePhase
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPRGroupOccurrenceBase::GetHalfTonePhase() const {
	return GetAttribute(atr_HalfTonePhase,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidHalfTonePhase(EnumValidationLevel level) const {
		return ValidAttribute(atr_HalfTonePhase,AttributeType_XYPair,false);
	};
/**
* Set attribute HasColorLUT
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetHasColorLUT(bool value){
	SetAttribute(atr_HasColorLUT,WString::valueOf(value));
};
/**
* Get bool attribute HasColorLUT
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetHasColorLUT() const {return GetBoolAttribute(atr_HasColorLUT,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidHasColorLUT(EnumValidationLevel level) const {
		return ValidAttribute(atr_HasColorLUT,AttributeType_boolean,false);
	};
/**
* Set attribute NumberOfColorsInLUT
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetNumberOfColorsInLUT(int value){
	SetAttribute(atr_NumberOfColorsInLUT,WString::valueOf(value));
};
/**
* Get integer attribute NumberOfColorsInLUT
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRGroupOccurrenceBase::GetNumberOfColorsInLUT() const {
	return GetIntAttribute(atr_NumberOfColorsInLUT,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidNumberOfColorsInLUT(EnumValidationLevel level) const {
		return ValidAttribute(atr_NumberOfColorsInLUT,AttributeType_integer,false);
	};
/**
* Set attribute OverPrintFlag
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetOverPrintFlag(bool value){
	SetAttribute(atr_OverPrintFlag,WString::valueOf(value));
};
/**
* Get bool attribute OverPrintFlag
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetOverPrintFlag() const {return GetBoolAttribute(atr_OverPrintFlag,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidOverPrintFlag(EnumValidationLevel level) const {
		return ValidAttribute(atr_OverPrintFlag,AttributeType_boolean,false);
	};
/**
* Set attribute OverPrintMode
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetOverPrintMode(int value){
	SetAttribute(atr_OverPrintMode,WString::valueOf(value));
};
/**
* Get integer attribute OverPrintMode
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRGroupOccurrenceBase::GetOverPrintMode() const {
	return GetIntAttribute(atr_OverPrintMode,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidOverPrintMode(EnumValidationLevel level) const {
		return ValidAttribute(atr_OverPrintMode,AttributeType_integer,false);
	};
/**
* Set attribute RenderingIntent
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetRenderingIntent(const WString& value){
	SetAttribute(atr_RenderingIntent,value);
};
/**
* Get string attribute RenderingIntent
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetRenderingIntent() const {
	return GetAttribute(atr_RenderingIntent,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidRenderingIntent(EnumValidationLevel level) const {
		return ValidAttribute(atr_RenderingIntent,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Smoothness
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetSmoothness(double value){
	SetAttribute(atr_Smoothness,WString::valueOf(value));
};
/**
* Get double attribute Smoothness
* @return double the vaue of the attribute 
*/
	 double JDFAutoPRGroupOccurrenceBase::GetSmoothness() const {
	return GetRealAttribute(atr_Smoothness,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidSmoothness(EnumValidationLevel level) const {
		return ValidAttribute(atr_Smoothness,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::TransferFunctionString(){
		static const WString enums=WString(L"Unknown,Identity,Custom");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::TransferFunctionString(EnumTransferFunction value){
		return TransferFunctionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetTransferFunction( EnumTransferFunction value){
	SetEnumAttribute(atr_TransferFunction,value,TransferFunctionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumTransferFunction JDFAutoPRGroupOccurrenceBase:: GetTransferFunction() const {
	return (EnumTransferFunction) GetEnumAttribute(atr_TransferFunction,TransferFunctionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidTransferFunction(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_TransferFunction,TransferFunctionString(),false);
	};
/**
* Set attribute TransparencyFlag
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetTransparencyFlag(bool value){
	SetAttribute(atr_TransparencyFlag,WString::valueOf(value));
};
/**
* Get bool attribute TransparencyFlag
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetTransparencyFlag() const {return GetBoolAttribute(atr_TransparencyFlag,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidTransparencyFlag(EnumValidationLevel level) const {
		return ValidAttribute(atr_TransparencyFlag,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::UnderColorRemovalString(){
		static const WString enums=WString(L"Unknown,Identity,Custom");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::UnderColorRemovalString(EnumUnderColorRemoval value){
		return UnderColorRemovalString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetUnderColorRemoval( EnumUnderColorRemoval value){
	SetEnumAttribute(atr_UnderColorRemoval,value,UnderColorRemovalString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumUnderColorRemoval JDFAutoPRGroupOccurrenceBase:: GetUnderColorRemoval() const {
	return (EnumUnderColorRemoval) GetEnumAttribute(atr_UnderColorRemoval,UnderColorRemovalString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidUnderColorRemoval(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_UnderColorRemoval,UnderColorRemovalString(),false);
	};
/**
* Set attribute AlternateImages
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetAlternateImages(const vWString& value){
	SetAttribute(atr_AlternateImages,value);
};
/**
* Get string attribute AlternateImages
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPRGroupOccurrenceBase::GetAlternateImages() const {
	return GetAttribute(atr_AlternateImages,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidAlternateImages(EnumValidationLevel level) const {
		return ValidAttribute(atr_AlternateImages,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute BitsPerSample
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetBitsPerSample(int value){
	SetAttribute(atr_BitsPerSample,WString::valueOf(value));
};
/**
* Get integer attribute BitsPerSample
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRGroupOccurrenceBase::GetBitsPerSample() const {
	return GetIntAttribute(atr_BitsPerSample,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidBitsPerSample(EnumValidationLevel level) const {
		return ValidAttribute(atr_BitsPerSample,AttributeType_integer,false);
	};
/**
* Set attribute CompressionRatio
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetCompressionRatio(double value){
	SetAttribute(atr_CompressionRatio,WString::valueOf(value));
};
/**
* Get double attribute CompressionRatio
* @return double the vaue of the attribute 
*/
	 double JDFAutoPRGroupOccurrenceBase::GetCompressionRatio() const {
	return GetRealAttribute(atr_CompressionRatio,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidCompressionRatio(EnumValidationLevel level) const {
		return ValidAttribute(atr_CompressionRatio,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::CompressionTypesString(){
		static const WString enums=WString(L"Unknown,ASCII85,ASCIIHex,CCITT,JBIG2,JPEG,JPEG2000,LZW,None,RunLength")
	+WString(L",ZIP");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::CompressionTypesString(EnumCompressionTypes value){
		return CompressionTypesString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoPRGroupOccurrenceBase::AddCompressionTypes( EnumCompressionTypes value){
	return AddEnumerationsAttribute(atr_CompressionTypes,value,CompressionTypesString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoPRGroupOccurrenceBase::RemoveCompressionTypes( EnumCompressionTypes value){
	return RemoveEnumerationsAttribute(atr_CompressionTypes,value,CompressionTypesString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoPRGroupOccurrenceBase::GetCompressionTypes() const {
	return GetEnumerationsAttribute(atr_CompressionTypes,CompressionTypesString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetCompressionTypes( EnumCompressionTypes value){
	SetEnumAttribute(atr_CompressionTypes,value,CompressionTypesString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetCompressionTypes( const vint& value){
	SetEnumerationsAttribute(atr_CompressionTypes,value,CompressionTypesString());
};
/**
* Typesafe attribute validation of CompressionTypes
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidCompressionTypes(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_CompressionTypes,CompressionTypesString(),false);
	};
/**
* Set attribute EffectiveResolution
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetEffectiveResolution(const JDFXYPair& value){
	SetAttribute(atr_EffectiveResolution,value);
};
/**
* Get string attribute EffectiveResolution
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPRGroupOccurrenceBase::GetEffectiveResolution() const {
	return GetAttribute(atr_EffectiveResolution,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidEffectiveResolution(EnumValidationLevel level) const {
		return ValidAttribute(atr_EffectiveResolution,AttributeType_XYPair,false);
	};
/**
* Set attribute EstimatedJPEGQuality
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetEstimatedJPEGQuality(int value){
	SetAttribute(atr_EstimatedJPEGQuality,WString::valueOf(value));
};
/**
* Get integer attribute EstimatedJPEGQuality
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRGroupOccurrenceBase::GetEstimatedJPEGQuality() const {
	return GetIntAttribute(atr_EstimatedJPEGQuality,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidEstimatedJPEGQuality(EnumValidationLevel level) const {
		return ValidAttribute(atr_EstimatedJPEGQuality,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::ImageFlippedString(){
		static const WString enums=WString(L"Unknown,Horizontal,Vertical,None");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::ImageFlippedString(EnumImageFlipped value){
		return ImageFlippedString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetImageFlipped( EnumImageFlipped value){
	SetEnumAttribute(atr_ImageFlipped,value,ImageFlippedString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumImageFlipped JDFAutoPRGroupOccurrenceBase:: GetImageFlipped() const {
	return (EnumImageFlipped) GetEnumAttribute(atr_ImageFlipped,ImageFlippedString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidImageFlipped(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ImageFlipped,ImageFlippedString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::ImageMaskTypeString(){
		static const WString enums=WString(L"Unknown,NoMask,BitmapMask,ColorKeyMask");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::ImageMaskTypeString(EnumImageMaskType value){
		return ImageMaskTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetImageMaskType( EnumImageMaskType value){
	SetEnumAttribute(atr_ImageMaskType,value,ImageMaskTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumImageMaskType JDFAutoPRGroupOccurrenceBase:: GetImageMaskType() const {
	return (EnumImageMaskType) GetEnumAttribute(atr_ImageMaskType,ImageMaskTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidImageMaskType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ImageMaskType,ImageMaskTypeString(),false);
	};
/**
* Set attribute ImageRotation
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetImageRotation(int value){
	SetAttribute(atr_ImageRotation,WString::valueOf(value));
};
/**
* Get integer attribute ImageRotation
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRGroupOccurrenceBase::GetImageRotation() const {
	return GetIntAttribute(atr_ImageRotation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidImageRotation(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageRotation,AttributeType_integer,false);
	};
/**
* Set attribute ImageScalingRatio
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetImageScalingRatio(double value){
	SetAttribute(atr_ImageScalingRatio,WString::valueOf(value));
};
/**
* Get double attribute ImageScalingRatio
* @return double the vaue of the attribute 
*/
	 double JDFAutoPRGroupOccurrenceBase::GetImageScalingRatio() const {
	return GetRealAttribute(atr_ImageScalingRatio,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidImageScalingRatio(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageScalingRatio,AttributeType_double,false);
	};
/**
* Set attribute ImageSkew
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetImageSkew(double value){
	SetAttribute(atr_ImageSkew,WString::valueOf(value));
};
/**
* Get double attribute ImageSkew
* @return double the vaue of the attribute 
*/
	 double JDFAutoPRGroupOccurrenceBase::GetImageSkew() const {
	return GetRealAttribute(atr_ImageSkew,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidImageSkew(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageSkew,AttributeType_double,false);
	};
/**
* Set attribute OriginalResolution
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetOriginalResolution(const JDFXYPair& value){
	SetAttribute(atr_OriginalResolution,value);
};
/**
* Get string attribute OriginalResolution
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPRGroupOccurrenceBase::GetOriginalResolution() const {
	return GetAttribute(atr_OriginalResolution,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidOriginalResolution(EnumValidationLevel level) const {
		return ValidAttribute(atr_OriginalResolution,AttributeType_XYPair,false);
	};
/**
* Set attribute PixelHeight
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetPixelHeight(int value){
	SetAttribute(atr_PixelHeight,WString::valueOf(value));
};
/**
* Get integer attribute PixelHeight
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRGroupOccurrenceBase::GetPixelHeight() const {
	return GetIntAttribute(atr_PixelHeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidPixelHeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_PixelHeight,AttributeType_integer,false);
	};
/**
* Set attribute PixelWidth
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetPixelWidth(int value){
	SetAttribute(atr_PixelWidth,WString::valueOf(value));
};
/**
* Get integer attribute PixelWidth
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRGroupOccurrenceBase::GetPixelWidth() const {
	return GetIntAttribute(atr_PixelWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidPixelWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_PixelWidth,AttributeType_integer,false);
	};
/**
* Set attribute Count
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetCount(int value){
	SetAttribute(atr_Count,WString::valueOf(value));
};
/**
* Get integer attribute Count
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRGroupOccurrenceBase::GetCount() const {
	return GetIntAttribute(atr_Count,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidCount(EnumValidationLevel level) const {
		return ValidAttribute(atr_Count,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::PageBoxTypeString(){
		static const WString enums=WString(L"Unknown,ArtBox,BleedBox,CropBox,MarginsBox,MediaBox,SlugBox,TrimBox");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::PageBoxTypeString(EnumPageBoxType value){
		return PageBoxTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetPageBoxType( EnumPageBoxType value){
	SetEnumAttribute(atr_PageBoxType,value,PageBoxTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumPageBoxType JDFAutoPRGroupOccurrenceBase:: GetPageBoxType() const {
	return (EnumPageBoxType) GetEnumAttribute(atr_PageBoxType,PageBoxTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidPageBoxType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PageBoxType,PageBoxTypeString(),false);
	};
/**
* Set attribute BlankPage
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetBlankPage(bool value){
	SetAttribute(atr_BlankPage,WString::valueOf(value));
};
/**
* Get bool attribute BlankPage
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetBlankPage() const {return GetBoolAttribute(atr_BlankPage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidBlankPage(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlankPage,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::BlendColorSpaceString(){
		static const WString enums=WString(L"Unknown,CalGray,CalRGB,CIEBasedA,CIEBasedABC,CIEBasedDEFG,DeviceCMYK,DeviceGray,DeviceN,DeviceRGB")
	+WString(L",ICCBased,Lab");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::BlendColorSpaceString(EnumBlendColorSpace value){
		return BlendColorSpaceString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetBlendColorSpace( EnumBlendColorSpace value){
	SetEnumAttribute(atr_BlendColorSpace,value,BlendColorSpaceString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumBlendColorSpace JDFAutoPRGroupOccurrenceBase:: GetBlendColorSpace() const {
	return (EnumBlendColorSpace) GetEnumAttribute(atr_BlendColorSpace,BlendColorSpaceString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidBlendColorSpace(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BlendColorSpace,BlendColorSpaceString(),false);
	};
/**
* Set attribute PageHasOptionalContent
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetPageHasOptionalContent(bool value){
	SetAttribute(atr_PageHasOptionalContent,WString::valueOf(value));
};
/**
* Get bool attribute PageHasOptionalContent
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetPageHasOptionalContent() const {return GetBoolAttribute(atr_PageHasOptionalContent,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidPageHasOptionalContent(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageHasOptionalContent,AttributeType_boolean,false);
	};
/**
* Set attribute PageHasUnknownObjects
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetPageHasUnknownObjects(bool value){
	SetAttribute(atr_PageHasUnknownObjects,WString::valueOf(value));
};
/**
* Get bool attribute PageHasUnknownObjects
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetPageHasUnknownObjects() const {return GetBoolAttribute(atr_PageHasUnknownObjects,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidPageHasUnknownObjects(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageHasUnknownObjects,AttributeType_boolean,false);
	};
/**
* Set attribute PageScalingFactor
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetPageScalingFactor(double value){
	SetAttribute(atr_PageScalingFactor,WString::valueOf(value));
};
/**
* Get double attribute PageScalingFactor
* @return double the vaue of the attribute 
*/
	 double JDFAutoPRGroupOccurrenceBase::GetPageScalingFactor() const {
	return GetRealAttribute(atr_PageScalingFactor,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidPageScalingFactor(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageScalingFactor,AttributeType_double,false);
	};
/**
* Set attribute ReversePageNumber
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetReversePageNumber(int value){
	SetAttribute(atr_ReversePageNumber,WString::valueOf(value));
};
/**
* Get integer attribute ReversePageNumber
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRGroupOccurrenceBase::GetReversePageNumber() const {
	return GetIntAttribute(atr_ReversePageNumber,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidReversePageNumber(EnumValidationLevel level) const {
		return ValidAttribute(atr_ReversePageNumber,AttributeType_integer,false);
	};
/**
* Set attribute PDLObjectType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetPDLObjectType(const WString& value){
	SetAttribute(atr_PDLObjectType,value);
};
/**
* Get string attribute PDLObjectType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetPDLObjectType() const {
	return GetAttribute(atr_PDLObjectType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidPDLObjectType(EnumValidationLevel level) const {
		return ValidAttribute(atr_PDLObjectType,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute ExternalReferenceMissing
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetExternalReferenceMissing(bool value){
	SetAttribute(atr_ExternalReferenceMissing,WString::valueOf(value));
};
/**
* Get bool attribute ExternalReferenceMissing
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetExternalReferenceMissing() const {return GetBoolAttribute(atr_ExternalReferenceMissing,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidExternalReferenceMissing(EnumValidationLevel level) const {
		return ValidAttribute(atr_ExternalReferenceMissing,AttributeType_boolean,false);
	};
/**
* Set attribute HasExternalReference
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetHasExternalReference(bool value){
	SetAttribute(atr_HasExternalReference,WString::valueOf(value));
};
/**
* Get bool attribute HasExternalReference
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetHasExternalReference() const {return GetBoolAttribute(atr_HasExternalReference,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidHasExternalReference(EnumValidationLevel level) const {
		return ValidAttribute(atr_HasExternalReference,AttributeType_boolean,false);
	};
/**
* Set attribute HasOPI
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetHasOPI(bool value){
	SetAttribute(atr_HasOPI,WString::valueOf(value));
};
/**
* Get bool attribute HasOPI
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetHasOPI() const {return GetBoolAttribute(atr_HasOPI,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidHasOPI(EnumValidationLevel level) const {
		return ValidAttribute(atr_HasOPI,AttributeType_boolean,false);
	};
/**
* Set attribute OPIMissing
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetOPIMissing(bool value){
	SetAttribute(atr_OPIMissing,WString::valueOf(value));
};
/**
* Get bool attribute OPIMissing
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetOPIMissing() const {return GetBoolAttribute(atr_OPIMissing,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidOPIMissing(EnumValidationLevel level) const {
		return ValidAttribute(atr_OPIMissing,AttributeType_boolean,false);
	};
/**
* Set attribute OPIType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetOPIType(const WString& value){
	SetAttribute(atr_OPIType,value);
};
/**
* Get string attribute OPIType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetOPIType() const {
	return GetAttribute(atr_OPIType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidOPIType(EnumValidationLevel level) const {
		return ValidAttribute(atr_OPIType,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute OPIVersion
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetOPIVersion(const vWString& value){
	SetAttribute(atr_OPIVersion,value);
};
/**
* Get string attribute OPIVersion
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPRGroupOccurrenceBase::GetOPIVersion() const {
	return GetAttribute(atr_OPIVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidOPIVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_OPIVersion,AttributeType_NMTOKENS,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::ShadingTypeString(){
		static const WString enums=WString(L"Unknown,Smooth,Vector");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::ShadingTypeString(EnumShadingType value){
		return ShadingTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetShadingType( EnumShadingType value){
	SetEnumAttribute(atr_ShadingType,value,ShadingTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumShadingType JDFAutoPRGroupOccurrenceBase:: GetShadingType() const {
	return (EnumShadingType) GetEnumAttribute(atr_ShadingType,ShadingTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidShadingType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ShadingType,ShadingTypeString(),false);
	};
/**
* Set attribute HasStrokeColor
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetHasStrokeColor(bool value){
	SetAttribute(atr_HasStrokeColor,WString::valueOf(value));
};
/**
* Get bool attribute HasStrokeColor
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetHasStrokeColor() const {return GetBoolAttribute(atr_HasStrokeColor,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidHasStrokeColor(EnumValidationLevel level) const {
		return ValidAttribute(atr_HasStrokeColor,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::StrokeAlternateColorSpaceString(){
		static const WString enums=WString(L"Unknown,CalGray,CalRGB,CIEBasedA,CIEBasedABC,CIEBasedDEFG,DeviceCMYK,DeviceGray,DeviceN,DeviceRGB")
	+WString(L",ICCBased,Lab");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::StrokeAlternateColorSpaceString(EnumStrokeAlternateColorSpace value){
		return StrokeAlternateColorSpaceString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetStrokeAlternateColorSpace( EnumStrokeAlternateColorSpace value){
	SetEnumAttribute(atr_StrokeAlternateColorSpace,value,StrokeAlternateColorSpaceString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumStrokeAlternateColorSpace JDFAutoPRGroupOccurrenceBase:: GetStrokeAlternateColorSpace() const {
	return (EnumStrokeAlternateColorSpace) GetEnumAttribute(atr_StrokeAlternateColorSpace,StrokeAlternateColorSpaceString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidStrokeAlternateColorSpace(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_StrokeAlternateColorSpace,StrokeAlternateColorSpaceString(),false);
	};
/**
* Set attribute StrokeColorName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetStrokeColorName(const WString& value){
	SetAttribute(atr_StrokeColorName,value);
};
/**
* Get string attribute StrokeColorName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRGroupOccurrenceBase::GetStrokeColorName() const {
	return GetAttribute(atr_StrokeColorName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidStrokeColorName(EnumValidationLevel level) const {
		return ValidAttribute(atr_StrokeColorName,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::StrokeColorSpaceString(){
		static const WString enums=WString(L"Unknown,CalGray,CalRGB,CIEBasedA,CIEBasedABC,CIEBasedDEFG,DeviceCMYK,DeviceGray,DeviceN,DeviceRGB")
	+WString(L",ICCBased,Lab");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::StrokeColorSpaceString(EnumStrokeColorSpace value){
		return StrokeColorSpaceString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetStrokeColorSpace( EnumStrokeColorSpace value){
	SetEnumAttribute(atr_StrokeColorSpace,value,StrokeColorSpaceString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumStrokeColorSpace JDFAutoPRGroupOccurrenceBase:: GetStrokeColorSpace() const {
	return (EnumStrokeColorSpace) GetEnumAttribute(atr_StrokeColorSpace,StrokeColorSpaceString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidStrokeColorSpace(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_StrokeColorSpace,StrokeColorSpaceString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::StrokeColorTypeString(){
		static const WString enums=WString(L"Unknown,CMYGray,CMYBlack,Other,PureBlack,PureGray,RegistrationBlack,RegistrationGray,RichBlack,White");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::StrokeColorTypeString(EnumStrokeColorType value){
		return StrokeColorTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetStrokeColorType( EnumStrokeColorType value){
	SetEnumAttribute(atr_StrokeColorType,value,StrokeColorTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumStrokeColorType JDFAutoPRGroupOccurrenceBase:: GetStrokeColorType() const {
	return (EnumStrokeColorType) GetEnumAttribute(atr_StrokeColorType,StrokeColorTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidStrokeColorType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_StrokeColorType,StrokeColorTypeString(),false);
	};
/**
* Set attribute StrokeOverprintFlag
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetStrokeOverprintFlag(bool value){
	SetAttribute(atr_StrokeOverprintFlag,WString::valueOf(value));
};
/**
* Get bool attribute StrokeOverprintFlag
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetStrokeOverprintFlag() const {return GetBoolAttribute(atr_StrokeOverprintFlag,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidStrokeOverprintFlag(EnumValidationLevel level) const {
		return ValidAttribute(atr_StrokeOverprintFlag,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::StrokeShadingTypeString(){
		static const WString enums=WString(L"Unknown,Smooth,Vector");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::StrokeShadingTypeString(EnumStrokeShadingType value){
		return StrokeShadingTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetStrokeShadingType( EnumStrokeShadingType value){
	SetEnumAttribute(atr_StrokeShadingType,value,StrokeShadingTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumStrokeShadingType JDFAutoPRGroupOccurrenceBase:: GetStrokeShadingType() const {
	return (EnumStrokeShadingType) GetEnumAttribute(atr_StrokeShadingType,StrokeShadingTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidStrokeShadingType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_StrokeShadingType,StrokeShadingTypeString(),false);
	};
/**
* Set attribute StrokeThickness
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetStrokeThickness(double value){
	SetAttribute(atr_StrokeThickness,WString::valueOf(value));
};
/**
* Get double attribute StrokeThickness
* @return double the vaue of the attribute 
*/
	 double JDFAutoPRGroupOccurrenceBase::GetStrokeThickness() const {
	return GetRealAttribute(atr_StrokeThickness,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidStrokeThickness(EnumValidationLevel level) const {
		return ValidAttribute(atr_StrokeThickness,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::CharacterProblemString(){
		static const WString enums=WString(L"Unknown,Corrupted,IncorrectEncoding,Missing,Others");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::CharacterProblemString(EnumCharacterProblem value){
		return CharacterProblemString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetCharacterProblem( EnumCharacterProblem value){
	SetEnumAttribute(atr_CharacterProblem,value,CharacterProblemString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumCharacterProblem JDFAutoPRGroupOccurrenceBase:: GetCharacterProblem() const {
	return (EnumCharacterProblem) GetEnumAttribute(atr_CharacterProblem,CharacterProblemString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidCharacterProblem(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_CharacterProblem,CharacterProblemString(),false);
	};
/**
* Set attribute MissingPrinterFont
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetMissingPrinterFont(bool value){
	SetAttribute(atr_MissingPrinterFont,WString::valueOf(value));
};
/**
* Get bool attribute MissingPrinterFont
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetMissingPrinterFont() const {return GetBoolAttribute(atr_MissingPrinterFont,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidMissingPrinterFont(EnumValidationLevel level) const {
		return ValidAttribute(atr_MissingPrinterFont,AttributeType_boolean,false);
	};
/**
* Set attribute MissingScreenFont
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetMissingScreenFont(bool value){
	SetAttribute(atr_MissingScreenFont,WString::valueOf(value));
};
/**
* Get bool attribute MissingScreenFont
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPRGroupOccurrenceBase::GetMissingScreenFont() const {return GetBoolAttribute(atr_MissingScreenFont,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidMissingScreenFont(EnumValidationLevel level) const {
		return ValidAttribute(atr_MissingScreenFont,AttributeType_boolean,false);
	};
/**
* Set attribute TextSize
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetTextSize(double value){
	SetAttribute(atr_TextSize,WString::valueOf(value));
};
/**
* Get double attribute TextSize
* @return double the vaue of the attribute 
*/
	 double JDFAutoPRGroupOccurrenceBase::GetTextSize() const {
	return GetRealAttribute(atr_TextSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidTextSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_TextSize,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPRGroupOccurrenceBase::UseArtificialTextEffectString(){
		static const WString enums=WString(L"Unknown,Bold,Italic,Outline,Shadow,Underline");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPRGroupOccurrenceBase::UseArtificialTextEffectString(EnumUseArtificialTextEffect value){
		return UseArtificialTextEffectString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPRGroupOccurrenceBase::SetUseArtificialTextEffect( EnumUseArtificialTextEffect value){
	SetEnumAttribute(atr_UseArtificialTextEffect,value,UseArtificialTextEffectString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPRGroupOccurrenceBase::EnumUseArtificialTextEffect JDFAutoPRGroupOccurrenceBase:: GetUseArtificialTextEffect() const {
	return (EnumUseArtificialTextEffect) GetEnumAttribute(atr_UseArtificialTextEffect,UseArtificialTextEffectString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidUseArtificialTextEffect(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_UseArtificialTextEffect,UseArtificialTextEffectString(),false);
	};
/**
* Set attribute NumberOfPathPoints
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRGroupOccurrenceBase::SetNumberOfPathPoints(int value){
	SetAttribute(atr_NumberOfPathPoints,WString::valueOf(value));
};
/**
* Get integer attribute NumberOfPathPoints
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRGroupOccurrenceBase::GetNumberOfPathPoints() const {
	return GetIntAttribute(atr_NumberOfPathPoints,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRGroupOccurrenceBase::ValidNumberOfPathPoints(EnumValidationLevel level) const {
		return ValidAttribute(atr_NumberOfPathPoints,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFQualityControlResult JDFAutoPRGroupOccurrenceBase::GetQualityControlResult(int iSkip)const{
	JDFQualityControlResult e=GetElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoPRGroupOccurrenceBase::GetCreateQualityControlResult(int iSkip){
	JDFQualityControlResult e=GetCreateElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoPRGroupOccurrenceBase::AppendQualityControlResult(){
	JDFQualityControlResult e=AppendElement(elm_QualityControlResult);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPRGroupOccurrenceBase::RefQualityControlResult(JDFQualityControlResult& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPRGroupOccurrenceBase::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_QualityControlResult);

		for(i=0;i<nElem;i++){
			if (!GetQualityControlResult(i).IsValid(level)) {
				vElem.AppendUnique(elm_QualityControlResult);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoPRGroupOccurrenceBase::OptionalElements()const{
		return JDFElement::OptionalElements()+L",QualityControlResult";
	};
}; // end namespace JDF
