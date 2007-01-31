/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2006 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoStrippingParams_H_
#define _JDFAutoStrippingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFBinderySignature;
class JDFDevice;
class JDFExternalImpositionTemplate;
class JDFMedia;
class JDFPosition;
class JDFStripCellParams;
class JDFStripMark;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoStrippingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoStrippingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFStrippingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoStrippingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoStrippingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoStrippingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoStrippingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoStrippingParams(){};
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
* Enumeration for attribute WorkStyle
*/

	enum EnumWorkStyle{WorkStyle_Unknown,WorkStyle_Simplex,WorkStyle_WorkAndBack,WorkStyle_Perfecting,WorkStyle_WorkAndTurn,WorkStyle_WorkAndTumble,WorkStyle_WorkAndTwist};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute AssemblyID
*@param WString value: the value to set the attribute to
*/
	virtual void SetAssemblyID(const WString& value);
/**
* Get string attribute AssemblyID
* @return WString the vaue of the attribute 
*/
	virtual WString GetAssemblyID() const;
/**
* Typesafe attribute validation of AssemblyID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAssemblyID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AssemblyIDs
*@param vWString value: the value to set the attribute to
*/
	virtual void SetAssemblyIDs(const vWString& value);
/**
* Get string attribute AssemblyIDs
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetAssemblyIDs() const;
/**
* Typesafe attribute validation of AssemblyIDs
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAssemblyIDs(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	virtual void SetJobID(const WString& value);
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	virtual WString GetJobID() const;
/**
* Typesafe attribute validation of JobID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidJobID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SectionList
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetSectionList(const JDFIntegerList& value);
/**
* Get string attribute SectionList
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetSectionList() const;
/**
* Typesafe attribute validation of SectionList
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSectionList(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for WorkStyle
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& WorkStyleString();
/**
* Enumeration string for enum value
* @param EnumWorkStyle value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString WorkStyleString(EnumWorkStyle value);
/**
* Set attribute WorkStyle
* @param EnumWorkStyle value the value to set the attribute to
*/
	virtual void SetWorkStyle( EnumWorkStyle value);

/**
* Typesafe enumerated attribute WorkStyle
* @return EnumWorkStylethe enumeration value of the attribute
*/
	virtual EnumWorkStyle GetWorkStyle() const;

/**
* Typesafe attribute validation of WorkStyle
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidWorkStyle(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element BinderySignature
* 
* @param int iSkip number of elements to skip
* @return JDFBinderySignature The element
*/
	JDFBinderySignature GetCreateBinderySignature(int iSkip=0);

/**
* const get element BinderySignature
* @param int iSkip number of elements to skip
* @return JDFBinderySignature The element
*/
	JDFBinderySignature GetBinderySignature(int iSkip=0)const;
/**
* Append element BinderySignature
 */
	JDFBinderySignature AppendBinderySignature();
/**
* create inter-resource link to refTarget
* @param JDFBinderySignature& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefBinderySignature(JDFBinderySignature& refTarget);

/** Get Element Device
* 
* @param int iSkip number of elements to skip
* @return JDFDevice The element
*/
	JDFDevice GetCreateDevice(int iSkip=0);

/**
* const get element Device
* @param int iSkip number of elements to skip
* @return JDFDevice The element
*/
	JDFDevice GetDevice(int iSkip=0)const;
/**
* Append element Device
 */
	JDFDevice AppendDevice();
/**
* create inter-resource link to refTarget
* @param JDFDevice& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefDevice(JDFDevice& refTarget);

/** Get Element ExternalImpositionTemplate
* 
* @param int iSkip number of elements to skip
* @return JDFExternalImpositionTemplate The element
*/
	JDFExternalImpositionTemplate GetCreateExternalImpositionTemplate(int iSkip=0);

/**
* const get element ExternalImpositionTemplate
* @param int iSkip number of elements to skip
* @return JDFExternalImpositionTemplate The element
*/
	JDFExternalImpositionTemplate GetExternalImpositionTemplate(int iSkip=0)const;
/**
* Append element ExternalImpositionTemplate
 */
	JDFExternalImpositionTemplate AppendExternalImpositionTemplate();
/**
* create inter-resource link to refTarget
* @param JDFExternalImpositionTemplate& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefExternalImpositionTemplate(JDFExternalImpositionTemplate& refTarget);

/** Get Element Media
* 
* @param int iSkip number of elements to skip
* @return JDFMedia The element
*/
	JDFMedia GetCreateMedia(int iSkip=0);

/**
* const get element Media
* @param int iSkip number of elements to skip
* @return JDFMedia The element
*/
	JDFMedia GetMedia(int iSkip=0)const;
/**
* Append element Media
 */
	JDFMedia AppendMedia();
/**
* create inter-resource link to refTarget
* @param JDFMedia& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefMedia(JDFMedia& refTarget);

/** Get Element Position
* 
* @param int iSkip number of elements to skip
* @return JDFPosition The element
*/
	JDFPosition GetCreatePosition(int iSkip=0);

/**
* const get element Position
* @param int iSkip number of elements to skip
* @return JDFPosition The element
*/
	JDFPosition GetPosition(int iSkip=0)const;
/**
* Append element Position
 */
	JDFPosition AppendPosition();

/** Get Element StripCellParams
* 
* @param int iSkip number of elements to skip
* @return JDFStripCellParams The element
*/
	JDFStripCellParams GetCreateStripCellParams(int iSkip=0);

/**
* const get element StripCellParams
* @param int iSkip number of elements to skip
* @return JDFStripCellParams The element
*/
	JDFStripCellParams GetStripCellParams(int iSkip=0)const;
/**
* Append element StripCellParams
 */
	JDFStripCellParams AppendStripCellParams();

/** Get Element StripMark
* 
* @param int iSkip number of elements to skip
* @return JDFStripMark The element
*/
	JDFStripMark GetCreateStripMark(int iSkip=0);

/**
* const get element StripMark
* @param int iSkip number of elements to skip
* @return JDFStripMark The element
*/
	JDFStripMark GetStripMark(int iSkip=0)const;
/**
* Append element StripMark
 */
	JDFStripMark AppendStripMark();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoStrippingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoStrippingParams_H_
