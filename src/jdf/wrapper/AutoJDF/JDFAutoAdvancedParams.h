/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoAdvancedParams_H_
#define _JDFAutoAdvancedParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoAdvancedParams : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoAdvancedParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFAdvancedParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoAdvancedParams : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoAdvancedParams():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoAdvancedParams(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoAdvancedParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoAdvancedParams(){};
public:

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid attribute names
*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

protected:
/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	virtual WString ValidNodeNames()const;
public:

/**
* Checks if the node is abstract, i.e. is not completely described
* utility used by GetUnknownElements, GetUnknownAttributes
* @return boolean: true, if the node is abstract
*/
	virtual bool IsAbstract()const;


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */

/**
* Enumeration for attribute TransferFunctionInfo
*/

	enum EnumTransferFunctionInfo{TransferFunctionInfo_Unknown,TransferFunctionInfo_Preserve,TransferFunctionInfo_Remove,TransferFunctionInfo_Apply};
/**
* Enumeration for attribute UCRandBGInfo
*/

	enum EnumUCRandBGInfo{UCRandBGInfo_Unknown,UCRandBGInfo_Preserve,UCRandBGInfo_Remove};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute AllowPSXObjects
*@param bool value: the value to set the attribute to
*/
	virtual void SetAllowPSXObjects(bool value);
/**
* Get bool attribute AllowPSXObjects
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetAllowPSXObjects() const;
/**
* Typesafe attribute validation of AllowPSXObjects
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAllowPSXObjects(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AllowTransparency
*@param bool value: the value to set the attribute to
*/
	virtual void SetAllowTransparency(bool value);
/**
* Get bool attribute AllowTransparency
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetAllowTransparency() const;
/**
* Typesafe attribute validation of AllowTransparency
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAllowTransparency(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AutoPositionEPSInfo
*@param bool value: the value to set the attribute to
*/
	virtual void SetAutoPositionEPSInfo(bool value);
/**
* Get bool attribute AutoPositionEPSInfo
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetAutoPositionEPSInfo() const;
/**
* Typesafe attribute validation of AutoPositionEPSInfo
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAutoPositionEPSInfo(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EmbedJobOptions
*@param bool value: the value to set the attribute to
*/
	virtual void SetEmbedJobOptions(bool value);
/**
* Get bool attribute EmbedJobOptions
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetEmbedJobOptions() const;
/**
* Typesafe attribute validation of EmbedJobOptions
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEmbedJobOptions(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EmitDSCWarnings
*@param bool value: the value to set the attribute to
*/
	virtual void SetEmitDSCWarnings(bool value);
/**
* Get bool attribute EmitDSCWarnings
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetEmitDSCWarnings() const;
/**
* Typesafe attribute validation of EmitDSCWarnings
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEmitDSCWarnings(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LockDistillerParams
*@param bool value: the value to set the attribute to
*/
	virtual void SetLockDistillerParams(bool value);
/**
* Get bool attribute LockDistillerParams
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetLockDistillerParams() const;
/**
* Typesafe attribute validation of LockDistillerParams
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLockDistillerParams(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ParseDSCComments
*@param bool value: the value to set the attribute to
*/
	virtual void SetParseDSCComments(bool value);
/**
* Get bool attribute ParseDSCComments
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetParseDSCComments() const;
/**
* Typesafe attribute validation of ParseDSCComments
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidParseDSCComments(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ParseDSCCommentsForDocInfo
*@param bool value: the value to set the attribute to
*/
	virtual void SetParseDSCCommentsForDocInfo(bool value);
/**
* Get bool attribute ParseDSCCommentsForDocInfo
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetParseDSCCommentsForDocInfo() const;
/**
* Typesafe attribute validation of ParseDSCCommentsForDocInfo
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidParseDSCCommentsForDocInfo(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PassThroughJPEGImages
*@param bool value: the value to set the attribute to
*/
	virtual void SetPassThroughJPEGImages(bool value);
/**
* Get bool attribute PassThroughJPEGImages
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetPassThroughJPEGImages() const;
/**
* Typesafe attribute validation of PassThroughJPEGImages
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPassThroughJPEGImages(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PreserveCopyPage
*@param bool value: the value to set the attribute to
*/
	virtual void SetPreserveCopyPage(bool value);
/**
* Get bool attribute PreserveCopyPage
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetPreserveCopyPage() const;
/**
* Typesafe attribute validation of PreserveCopyPage
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPreserveCopyPage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PreserveEPSInfo
*@param bool value: the value to set the attribute to
*/
	virtual void SetPreserveEPSInfo(bool value);
/**
* Get bool attribute PreserveEPSInfo
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetPreserveEPSInfo() const;
/**
* Typesafe attribute validation of PreserveEPSInfo
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPreserveEPSInfo(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PreserveHalftoneInfo
*@param bool value: the value to set the attribute to
*/
	virtual void SetPreserveHalftoneInfo(bool value);
/**
* Get bool attribute PreserveHalftoneInfo
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetPreserveHalftoneInfo() const;
/**
* Typesafe attribute validation of PreserveHalftoneInfo
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPreserveHalftoneInfo(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PreserveOverprintSettings
*@param bool value: the value to set the attribute to
*/
	virtual void SetPreserveOverprintSettings(bool value);
/**
* Get bool attribute PreserveOverprintSettings
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetPreserveOverprintSettings() const;
/**
* Typesafe attribute validation of PreserveOverprintSettings
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPreserveOverprintSettings(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PreserveOPIComments
*@param bool value: the value to set the attribute to
*/
	virtual void SetPreserveOPIComments(bool value);
/**
* Get bool attribute PreserveOPIComments
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetPreserveOPIComments() const;
/**
* Typesafe attribute validation of PreserveOPIComments
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPreserveOPIComments(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for TransferFunctionInfo
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& TransferFunctionInfoString();
/**
* Enumeration string for enum value
* @param EnumTransferFunctionInfo value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString TransferFunctionInfoString(EnumTransferFunctionInfo value);
/**
* Set attribute TransferFunctionInfo
* @param EnumTransferFunctionInfo value the value to set the attribute to
*/
	virtual void SetTransferFunctionInfo( EnumTransferFunctionInfo value);

/**
* Typesafe enumerated attribute TransferFunctionInfo; defaults to Preserve
* @return EnumTransferFunctionInfothe enumeration value of the attribute
*/
	virtual EnumTransferFunctionInfo GetTransferFunctionInfo() const;

/**
* Typesafe attribute validation of TransferFunctionInfo
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidTransferFunctionInfo(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for UCRandBGInfo
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& UCRandBGInfoString();
/**
* Enumeration string for enum value
* @param EnumUCRandBGInfo value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString UCRandBGInfoString(EnumUCRandBGInfo value);
/**
* Set attribute UCRandBGInfo
* @param EnumUCRandBGInfo value the value to set the attribute to
*/
	virtual void SetUCRandBGInfo( EnumUCRandBGInfo value);

/**
* Typesafe enumerated attribute UCRandBGInfo; defaults to Preserve
* @return EnumUCRandBGInfothe enumeration value of the attribute
*/
	virtual EnumUCRandBGInfo GetUCRandBGInfo() const;

/**
* Typesafe attribute validation of UCRandBGInfo
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidUCRandBGInfo(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute UsePrologue
*@param bool value: the value to set the attribute to
*/
	virtual void SetUsePrologue(bool value);
/**
* Get bool attribute UsePrologue
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetUsePrologue() const;
/**
* Typesafe attribute validation of UsePrologue
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidUsePrologue(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoAdvancedParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoAdvancedParams_H_
