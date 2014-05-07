/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2014 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoBinderySignature_H_
#define _JDFAutoBinderySignature_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFDieLayout;
class JDFFold;
class JDFSignatureCell;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoBinderySignature : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoBinderySignature class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFBinderySignature should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoBinderySignature : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoBinderySignature():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoBinderySignature(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoBinderySignature &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoBinderySignature(){};
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
* Enumeration for attribute BinderySignatureType
*/

	enum EnumBinderySignatureType{BinderySignatureType_Unknown,BinderySignatureType_Die,BinderySignatureType_Fold,BinderySignatureType_Grid};
/**
* Enumeration for attribute BindingEdge
*/

	enum EnumBindingEdge{BindingEdge_Unknown,BindingEdge_Left,BindingEdge_Right,BindingEdge_Top,BindingEdge_Bottom,BindingEdge_None};
/**
* Enumeration for attribute JogEdge
*/

	enum EnumJogEdge{JogEdge_Unknown,JogEdge_Left,JogEdge_Right,JogEdge_Top,JogEdge_Bottom,JogEdge_None};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for BinderySignatureType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& BinderySignatureTypeString();
/**
* Enumeration string for enum value
* @param EnumBinderySignatureType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString BinderySignatureTypeString(EnumBinderySignatureType value);
/**
* Set attribute BinderySignatureType
* @param EnumBinderySignatureType value the value to set the attribute to
*/
	virtual void SetBinderySignatureType( EnumBinderySignatureType value);

/**
* Typesafe enumerated attribute BinderySignatureType; defaults to Fold
* @return EnumBinderySignatureTypethe enumeration value of the attribute
*/
	virtual EnumBinderySignatureType GetBinderySignatureType() const;

/**
* Typesafe attribute validation of BinderySignatureType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBinderySignatureType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for BindingEdge
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& BindingEdgeString();
/**
* Enumeration string for enum value
* @param EnumBindingEdge value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString BindingEdgeString(EnumBindingEdge value);
/**
* Set attribute BindingEdge
* @param EnumBindingEdge value the value to set the attribute to
*/
	virtual void SetBindingEdge( EnumBindingEdge value);

/**
* Typesafe enumerated attribute BindingEdge; defaults to Left
* @return EnumBindingEdgethe enumeration value of the attribute
*/
	virtual EnumBindingEdge GetBindingEdge() const;

/**
* Typesafe attribute validation of BindingEdge
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBindingEdge(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for JogEdge
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& JogEdgeString();
/**
* Enumeration string for enum value
* @param EnumJogEdge value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString JogEdgeString(EnumJogEdge value);
/**
* Set attribute JogEdge
* @param EnumJogEdge value the value to set the attribute to
*/
	virtual void SetJogEdge( EnumJogEdge value);

/**
* Typesafe enumerated attribute JogEdge; defaults to Top
* @return EnumJogEdgethe enumeration value of the attribute
*/
	virtual EnumJogEdge GetJogEdge() const;

/**
* Typesafe attribute validation of JogEdge
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidJogEdge(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NumberUp
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetNumberUp(const JDFXYPair& value);
/**
* Get string attribute NumberUp
* @return JDFXYPair the vaue of the attribute ; defaults to 1 1
*/
	virtual JDFXYPair GetNumberUp() const;
/**
* Typesafe attribute validation of NumberUp
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNumberUp(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AlignmentReferenceWeb
*@param WString value: the value to set the attribute to
*/
	virtual void SetAlignmentReferenceWeb(const WString& value);
/**
* Get string attribute AlignmentReferenceWeb
* @return WString the vaue of the attribute 
*/
	virtual WString GetAlignmentReferenceWeb() const;
/**
* Typesafe attribute validation of AlignmentReferenceWeb
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAlignmentReferenceWeb(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BindingOrientation
* @param EnumOrientation value the value to set the attribute to
*/
	virtual void SetBindingOrientation( EnumOrientation value);

/**
* Typesafe enumerated attribute BindingOrientation
* @return EnumBindingOrientationthe enumeration value of the attribute
*/
	virtual EnumOrientation GetBindingOrientation() const;

/**
* Typesafe attribute validation of BindingOrientation
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBindingOrientation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BleedBottom
*@param double value: the value to set the attribute to
*/
	virtual void SetBleedBottom(double value);
/**
* Get double attribute BleedBottom
* @return double the vaue of the attribute 
*/
	virtual double GetBleedBottom() const;
/**
* Typesafe attribute validation of BleedBottom
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBleedBottom(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BleedLeft
*@param double value: the value to set the attribute to
*/
	virtual void SetBleedLeft(double value);
/**
* Get double attribute BleedLeft
* @return double the vaue of the attribute 
*/
	virtual double GetBleedLeft() const;
/**
* Typesafe attribute validation of BleedLeft
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBleedLeft(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BleedRight
*@param double value: the value to set the attribute to
*/
	virtual void SetBleedRight(double value);
/**
* Get double attribute BleedRight
* @return double the vaue of the attribute 
*/
	virtual double GetBleedRight() const;
/**
* Typesafe attribute validation of BleedRight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBleedRight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BleedTop
*@param double value: the value to set the attribute to
*/
	virtual void SetBleedTop(double value);
/**
* Get double attribute BleedTop
* @return double the vaue of the attribute 
*/
	virtual double GetBleedTop() const;
/**
* Typesafe attribute validation of BleedTop
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBleedTop(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FoldCatalog
*@param WString value: the value to set the attribute to
*/
	virtual void SetFoldCatalog(const WString& value);
/**
* Get string attribute FoldCatalog
* @return WString the vaue of the attribute 
*/
	virtual WString GetFoldCatalog() const;
/**
* Typesafe attribute validation of FoldCatalog
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFoldCatalog(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FoldLay
* @param EnumOrientation value the value to set the attribute to
*/
	virtual void SetFoldLay( EnumOrientation value);

/**
* Typesafe enumerated attribute FoldLay
* @return EnumFoldLaythe enumeration value of the attribute
*/
	virtual EnumOrientation GetFoldLay() const;

/**
* Typesafe attribute validation of FoldLay
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidFoldLay(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OutsideGutter
*@param bool value: the value to set the attribute to
*/
	virtual void SetOutsideGutter(bool value);
/**
* Get bool attribute OutsideGutter
* @return bool the vaue of the attribute 
*/
	virtual bool GetOutsideGutter() const;
/**
* Typesafe attribute validation of OutsideGutter
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOutsideGutter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StaggerColumns
*@param JDFNumberList value: the value to set the attribute to
*/
	virtual void SetStaggerColumns(const JDFNumberList& value);
/**
* Get string attribute StaggerColumns
* @return JDFNumberList the vaue of the attribute 
*/
	virtual JDFNumberList GetStaggerColumns() const;
/**
* Typesafe attribute validation of StaggerColumns
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStaggerColumns(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StaggerContinuous
*@param bool value: the value to set the attribute to
*/
	virtual void SetStaggerContinuous(bool value);
/**
* Get bool attribute StaggerContinuous
* @return bool the vaue of the attribute 
*/
	virtual bool GetStaggerContinuous() const;
/**
* Typesafe attribute validation of StaggerContinuous
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStaggerContinuous(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StaggerRows
*@param JDFNumberList value: the value to set the attribute to
*/
	virtual void SetStaggerRows(const JDFNumberList& value);
/**
* Get string attribute StaggerRows
* @return JDFNumberList the vaue of the attribute 
*/
	virtual JDFNumberList GetStaggerRows() const;
/**
* Typesafe attribute validation of StaggerRows
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStaggerRows(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrimBottom
*@param double value: the value to set the attribute to
*/
	virtual void SetTrimBottom(double value);
/**
* Get double attribute TrimBottom
* @return double the vaue of the attribute 
*/
	virtual double GetTrimBottom() const;
/**
* Typesafe attribute validation of TrimBottom
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrimBottom(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrimLeft
*@param double value: the value to set the attribute to
*/
	virtual void SetTrimLeft(double value);
/**
* Get double attribute TrimLeft
* @return double the vaue of the attribute 
*/
	virtual double GetTrimLeft() const;
/**
* Typesafe attribute validation of TrimLeft
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrimLeft(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrimRight
*@param double value: the value to set the attribute to
*/
	virtual void SetTrimRight(double value);
/**
* Get double attribute TrimRight
* @return double the vaue of the attribute 
*/
	virtual double GetTrimRight() const;
/**
* Typesafe attribute validation of TrimRight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrimRight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrimTop
*@param double value: the value to set the attribute to
*/
	virtual void SetTrimTop(double value);
/**
* Get double attribute TrimTop
* @return double the vaue of the attribute 
*/
	virtual double GetTrimTop() const;
/**
* Typesafe attribute validation of TrimTop
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrimTop(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute WebCellAlignment
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetWebCellAlignment(const JDFXYPair& value);
/**
* Get string attribute WebCellAlignment
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetWebCellAlignment() const;
/**
* Typesafe attribute validation of WebCellAlignment
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWebCellAlignment(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element DieLayout
* 
* @return JDFDieLayout The element
*/
	JDFDieLayout GetCreateDieLayout();

/**
* const get element DieLayout
*@return  JDFDieLayout The element
*/
	JDFDieLayout GetDieLayout()const;
/**
* Append element DieLayout
 * 
*/
	JDFDieLayout AppendDieLayout();
/**
* create inter-resource link to refTarget
* @param JDFDieLayout& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefDieLayout(JDFDieLayout& refTarget);

/** Get Element Fold
* 
* @param int iSkip number of elements to skip
* @return JDFFold The element
*/
	JDFFold GetCreateFold(int iSkip=0);

/**
* const get element Fold
* @param int iSkip number of elements to skip
* @return JDFFold The element
*/
	JDFFold GetFold(int iSkip=0)const;
/**
* Append element Fold
 */
	JDFFold AppendFold();

/** Get Element SignatureCell
* 
* @param int iSkip number of elements to skip
* @return JDFSignatureCell The element
*/
	JDFSignatureCell GetCreateSignatureCell(int iSkip=0);

/**
* const get element SignatureCell
* @param int iSkip number of elements to skip
* @return JDFSignatureCell The element
*/
	JDFSignatureCell GetSignatureCell(int iSkip=0)const;
/**
* Append element SignatureCell
 */
	JDFSignatureCell AppendSignatureCell();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoBinderySignature

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoBinderySignature_H_
