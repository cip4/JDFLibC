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

 
#if !defined _JDFAutoFileSpec_H_
#define _JDFAutoFileSpec_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFContainer;
class JDFDisposition;
class JDFFileAlias;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoFileSpec : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoFileSpec class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFFileSpec should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoFileSpec : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoFileSpec():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoFileSpec(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoFileSpec &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoFileSpec(){};
public:

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid attribute names
*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid element names
*/
	virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;

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
 * Typesafe attribute validation of Class
* @return true if class is valid
*/
virtual bool ValidClass(EnumValidationLevel level) const;

/** 
 * Typesafe initialization
 * @return true if succcessful
*/
virtual bool init();

/**
* Enumeration for attribute Disposition
*/

	enum EnumDisposition{Disposition_Unknown,Disposition_Unlink,Disposition_Delete,Disposition_Retain};
/**
* Enumeration for attribute OverwritePolicy
*/

	enum EnumOverwritePolicy{OverwritePolicy_Unknown,OverwritePolicy_Overwrite,OverwritePolicy_RenameNew,OverwritePolicy_RenameOld,OverwritePolicy_NewVersion,OverwritePolicy_OperatorIntervention,OverwritePolicy_Abort};
/**
* Enumeration for attribute PageOrder
*/

	enum EnumPageOrder{PageOrder_Unknown,PageOrder_Ascending,PageOrder_Descending};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute Compression
*@param WString value: the value to set the attribute to
*/
	virtual void SetCompression(const WString& value);
/**
* Get string attribute Compression
* @return WString the vaue of the attribute ; defaults to None
*/
	virtual WString GetCompression() const;
/**
* Typesafe attribute validation of Compression
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCompression(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Application
*@param WString value: the value to set the attribute to
*/
	virtual void SetApplication(const WString& value);
/**
* Get string attribute Application
* @return WString the vaue of the attribute 
*/
	virtual WString GetApplication() const;
/**
* Typesafe attribute validation of Application
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidApplication(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AppOS
*@param WString value: the value to set the attribute to
*/
	virtual void SetAppOS(const WString& value);
/**
* Get string attribute AppOS
* @return WString the vaue of the attribute 
*/
	virtual WString GetAppOS() const;
/**
* Typesafe attribute validation of AppOS
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAppOS(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AppVersion
*@param WString value: the value to set the attribute to
*/
	virtual void SetAppVersion(const WString& value);
/**
* Get string attribute AppVersion
* @return WString the vaue of the attribute 
*/
	virtual WString GetAppVersion() const;
/**
* Typesafe attribute validation of AppVersion
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAppVersion(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CheckSum
*@param WString value: the value to set the attribute to
*/
	virtual void SetCheckSum(const WString& value);
/**
* Get string attribute CheckSum
* @return WString the vaue of the attribute 
*/
	virtual WString GetCheckSum() const;
/**
* Typesafe attribute validation of CheckSum
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCheckSum(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Disposition
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& DispositionString();
/**
* Enumeration string for enum value
* @param EnumDisposition value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString DispositionString(EnumDisposition value);
/**
* Set attribute Disposition
* @param EnumDisposition value the value to set the attribute to
*/
	virtual void SetDisposition( EnumDisposition value);

/**
* Typesafe enumerated attribute Disposition
* @return EnumDispositionthe enumeration value of the attribute
*/
	virtual EnumDisposition GetDisposition() const;

/**
* Typesafe attribute validation of Disposition
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidDisposition(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DocumentNaturalLang
*@param WString value: the value to set the attribute to
*/
	virtual void SetDocumentNaturalLang(const WString& value);
/**
* Get string attribute DocumentNaturalLang
* @return WString the vaue of the attribute 
*/
	virtual WString GetDocumentNaturalLang() const;
/**
* Typesafe attribute validation of DocumentNaturalLang
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDocumentNaturalLang(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Encoding
*@param WString value: the value to set the attribute to
*/
	virtual void SetEncoding(const WString& value);
/**
* Get string attribute Encoding
* @return WString the vaue of the attribute 
*/
	virtual WString GetEncoding() const;
/**
* Typesafe attribute validation of Encoding
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEncoding(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FileFormat
*@param WString value: the value to set the attribute to
*/
	virtual void SetFileFormat(const WString& value);
/**
* Get string attribute FileFormat
* @return WString the vaue of the attribute 
*/
	virtual WString GetFileFormat() const;
/**
* Typesafe attribute validation of FileFormat
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFileFormat(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FileSize
*@param JDFInt64 value: the value to set the attribute to
*/
	virtual void SetFileSize(JDFInt64 value);
/**
* Get string attribute FileSize
* @return JDFInt64 the vaue of the attribute 
*/
	virtual JDFInt64 GetFileSize() const;
/**
* Typesafe attribute validation of FileSize
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFileSize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FileTargetDeviceModel
*@param WString value: the value to set the attribute to
*/
	virtual void SetFileTargetDeviceModel(const WString& value);
/**
* Get string attribute FileTargetDeviceModel
* @return WString the vaue of the attribute 
*/
	virtual WString GetFileTargetDeviceModel() const;
/**
* Typesafe attribute validation of FileTargetDeviceModel
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFileTargetDeviceModel(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FileTemplate
*@param WString value: the value to set the attribute to
*/
	virtual void SetFileTemplate(const WString& value);
/**
* Get string attribute FileTemplate
* @return WString the vaue of the attribute 
*/
	virtual WString GetFileTemplate() const;
/**
* Typesafe attribute validation of FileTemplate
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFileTemplate(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FileVersion
*@param WString value: the value to set the attribute to
*/
	virtual void SetFileVersion(const WString& value);
/**
* Get string attribute FileVersion
* @return WString the vaue of the attribute 
*/
	virtual WString GetFileVersion() const;
/**
* Typesafe attribute validation of FileVersion
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFileVersion(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MimeType
*@param WString value: the value to set the attribute to
*/
	virtual void SetMimeType(const WString& value);
/**
* Get string attribute MimeType
* @return WString the vaue of the attribute 
*/
	virtual WString GetMimeType() const;
/**
* Typesafe attribute validation of MimeType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMimeType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MimeTypeVersion
*@param WString value: the value to set the attribute to
*/
	virtual void SetMimeTypeVersion(const WString& value);
/**
* Get string attribute MimeTypeVersion
* @return WString the vaue of the attribute 
*/
	virtual WString GetMimeTypeVersion() const;
/**
* Typesafe attribute validation of MimeTypeVersion
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMimeTypeVersion(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for OverwritePolicy
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& OverwritePolicyString();
/**
* Enumeration string for enum value
* @param EnumOverwritePolicy value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString OverwritePolicyString(EnumOverwritePolicy value);
/**
* Set attribute OverwritePolicy
* @param EnumOverwritePolicy value the value to set the attribute to
*/
	virtual void SetOverwritePolicy( EnumOverwritePolicy value);

/**
* Typesafe enumerated attribute OverwritePolicy
* @return EnumOverwritePolicythe enumeration value of the attribute
*/
	virtual EnumOverwritePolicy GetOverwritePolicy() const;

/**
* Typesafe attribute validation of OverwritePolicy
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidOverwritePolicy(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OSVersion
*@param WString value: the value to set the attribute to
*/
	virtual void SetOSVersion(const WString& value);
/**
* Get string attribute OSVersion
* @return WString the vaue of the attribute 
*/
	virtual WString GetOSVersion() const;
/**
* Typesafe attribute validation of OSVersion
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOSVersion(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PageOrder
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PageOrderString();
/**
* Enumeration string for enum value
* @param EnumPageOrder value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PageOrderString(EnumPageOrder value);
/**
* Set attribute PageOrder
* @param EnumPageOrder value the value to set the attribute to
*/
	virtual void SetPageOrder( EnumPageOrder value);

/**
* Typesafe enumerated attribute PageOrder
* @return EnumPageOrderthe enumeration value of the attribute
*/
	virtual EnumPageOrder GetPageOrder() const;

/**
* Typesafe attribute validation of PageOrder
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPageOrder(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Password
*@param WString value: the value to set the attribute to
*/
	virtual void SetPassword(const WString& value);
/**
* Get string attribute Password
* @return WString the vaue of the attribute 
*/
	virtual WString GetPassword() const;
/**
* Typesafe attribute validation of Password
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPassword(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RequestQuality
*@param double value: the value to set the attribute to
*/
	virtual void SetRequestQuality(double value);
/**
* Get double attribute RequestQuality
* @return double the vaue of the attribute 
*/
	virtual double GetRequestQuality() const;
/**
* Typesafe attribute validation of RequestQuality
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRequestQuality(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ResourceUsage
*@param WString value: the value to set the attribute to
*/
	virtual void SetResourceUsage(const WString& value);
/**
* Get string attribute ResourceUsage
* @return WString the vaue of the attribute 
*/
	virtual WString GetResourceUsage() const;
/**
* Typesafe attribute validation of ResourceUsage
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidResourceUsage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SearchDepth
*@param int value: the value to set the attribute to
*/
	virtual void SetSearchDepth(int value);
/**
* Get integer attribute SearchDepth
* @return int the vaue of the attribute 
*/
	virtual int GetSearchDepth() const;
/**
* Typesafe attribute validation of SearchDepth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSearchDepth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute UID
*@param WString value: the value to set the attribute to
*/
	virtual void SetUID(const WString& value);
/**
* Get string attribute UID
* @return WString the vaue of the attribute 
*/
	virtual WString GetUID() const;
/**
* Typesafe attribute validation of UID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidUID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute URL
*@param WString value: the value to set the attribute to
*/
	virtual void SetURL(const WString& value);
/**
* Get string attribute URL
* @return WString the vaue of the attribute 
*/
	virtual WString GetURL() const;
/**
* Typesafe attribute validation of URL
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidURL(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute UserFileName
*@param WString value: the value to set the attribute to
*/
	virtual void SetUserFileName(const WString& value);
/**
* Get string attribute UserFileName
* @return WString the vaue of the attribute 
*/
	virtual WString GetUserFileName() const;
/**
* Typesafe attribute validation of UserFileName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidUserFileName(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Container
* 
* @return JDFContainer The element
*/
	JDFContainer GetCreateContainer();

/**
* const get element Container
*@return  JDFContainer The element
*/
	JDFContainer GetContainer()const;
/**
* Append element Container
 * 
*/
	JDFContainer AppendContainer();

/** Get Element Disposition
* 
* @return JDFDisposition The element
*/
	JDFDisposition GetCreateDispositionElem();

/**
* const get element Disposition
*@return  JDFDisposition The element
*/
	JDFDisposition GetDispositionElem()const;
/**
* Append element Disposition
 * 
*/
	JDFDisposition AppendDispositionElem();

/** Get Element FileAlias
* 
* @param int iSkip number of elements to skip
* @return JDFFileAlias The element
*/
	JDFFileAlias GetCreateFileAlias(int iSkip=0);

/**
* const get element FileAlias
* @param int iSkip number of elements to skip
* @return JDFFileAlias The element
*/
	JDFFileAlias GetFileAlias(int iSkip=0)const;
/**
* Append element FileAlias
 */
	JDFFileAlias AppendFileAlias();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoFileSpec

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoFileSpec_H_
