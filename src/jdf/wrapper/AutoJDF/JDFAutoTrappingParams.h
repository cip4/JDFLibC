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

 
#if !defined _JDFAutoTrappingParams_H_
#define _JDFAutoTrappingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFColorantZoneDetails;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoTrappingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoTrappingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFTrappingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoTrappingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoTrappingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoTrappingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoTrappingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoTrappingParams(){};
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
* Enumeration for attribute ImageTrapPlacement
*/

	enum EnumImageTrapPlacement{ImageTrapPlacement_Unknown,ImageTrapPlacement_Center,ImageTrapPlacement_Choke,ImageTrapPlacement_Normal,ImageTrapPlacement_Spread};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute MinimumBlackWidth
*@param double value: the value to set the attribute to
*/
	virtual void SetMinimumBlackWidth(double value);
/**
* Get double attribute MinimumBlackWidth
* @return double the vaue of the attribute ; defaults to 0
*/
	virtual double GetMinimumBlackWidth() const;
/**
* Typesafe attribute validation of MinimumBlackWidth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMinimumBlackWidth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrapEndStyle
*@param WString value: the value to set the attribute to
*/
	virtual void SetTrapEndStyle(const WString& value);
/**
* Get string attribute TrapEndStyle
* @return WString the vaue of the attribute ; defaults to Miter
*/
	virtual WString GetTrapEndStyle() const;
/**
* Typesafe attribute validation of TrapEndStyle
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrapEndStyle(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrapJoinStyle
*@param WString value: the value to set the attribute to
*/
	virtual void SetTrapJoinStyle(const WString& value);
/**
* Get string attribute TrapJoinStyle
* @return WString the vaue of the attribute ; defaults to Miter
*/
	virtual WString GetTrapJoinStyle() const;
/**
* Typesafe attribute validation of TrapJoinStyle
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrapJoinStyle(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BlackColorLimit
*@param double value: the value to set the attribute to
*/
	virtual void SetBlackColorLimit(double value);
/**
* Get double attribute BlackColorLimit
* @return double the vaue of the attribute 
*/
	virtual double GetBlackColorLimit() const;
/**
* Typesafe attribute validation of BlackColorLimit
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBlackColorLimit(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BlackDensityLimit
*@param double value: the value to set the attribute to
*/
	virtual void SetBlackDensityLimit(double value);
/**
* Get double attribute BlackDensityLimit
* @return double the vaue of the attribute 
*/
	virtual double GetBlackDensityLimit() const;
/**
* Typesafe attribute validation of BlackDensityLimit
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBlackDensityLimit(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BlackWidth
*@param double value: the value to set the attribute to
*/
	virtual void SetBlackWidth(double value);
/**
* Get double attribute BlackWidth
* @return double the vaue of the attribute 
*/
	virtual double GetBlackWidth() const;
/**
* Typesafe attribute validation of BlackWidth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBlackWidth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Enabled
*@param bool value: the value to set the attribute to
*/
	virtual void SetEnabled(bool value);
/**
* Get bool attribute Enabled
* @return bool the vaue of the attribute 
*/
	virtual bool GetEnabled() const;
/**
* Typesafe attribute validation of Enabled
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEnabled(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HalftoneName
*@param WString value: the value to set the attribute to
*/
	virtual void SetHalftoneName(const WString& value);
/**
* Get string attribute HalftoneName
* @return WString the vaue of the attribute 
*/
	virtual WString GetHalftoneName() const;
/**
* Typesafe attribute validation of HalftoneName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHalftoneName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImageInternalTrapping
*@param bool value: the value to set the attribute to
*/
	virtual void SetImageInternalTrapping(bool value);
/**
* Get bool attribute ImageInternalTrapping
* @return bool the vaue of the attribute 
*/
	virtual bool GetImageInternalTrapping() const;
/**
* Typesafe attribute validation of ImageInternalTrapping
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageInternalTrapping(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImageResolution
*@param int value: the value to set the attribute to
*/
	virtual void SetImageResolution(int value);
/**
* Get integer attribute ImageResolution
* @return int the vaue of the attribute 
*/
	virtual int GetImageResolution() const;
/**
* Typesafe attribute validation of ImageResolution
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageResolution(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImageMaskTrapping
*@param bool value: the value to set the attribute to
*/
	virtual void SetImageMaskTrapping(bool value);
/**
* Get bool attribute ImageMaskTrapping
* @return bool the vaue of the attribute 
*/
	virtual bool GetImageMaskTrapping() const;
/**
* Typesafe attribute validation of ImageMaskTrapping
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageMaskTrapping(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImageToImageTrapping
*@param bool value: the value to set the attribute to
*/
	virtual void SetImageToImageTrapping(bool value);
/**
* Get bool attribute ImageToImageTrapping
* @return bool the vaue of the attribute 
*/
	virtual bool GetImageToImageTrapping() const;
/**
* Typesafe attribute validation of ImageToImageTrapping
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageToImageTrapping(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImageToObjectTrapping
*@param bool value: the value to set the attribute to
*/
	virtual void SetImageToObjectTrapping(bool value);
/**
* Get bool attribute ImageToObjectTrapping
* @return bool the vaue of the attribute 
*/
	virtual bool GetImageToObjectTrapping() const;
/**
* Typesafe attribute validation of ImageToObjectTrapping
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageToObjectTrapping(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ImageTrapPlacement
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ImageTrapPlacementString();
/**
* Enumeration string for enum value
* @param EnumImageTrapPlacement value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ImageTrapPlacementString(EnumImageTrapPlacement value);
/**
* Set attribute ImageTrapPlacement
* @param EnumImageTrapPlacement value the value to set the attribute to
*/
	virtual void SetImageTrapPlacement( EnumImageTrapPlacement value);

/**
* Typesafe enumerated attribute ImageTrapPlacement
* @return EnumImageTrapPlacementthe enumeration value of the attribute
*/
	virtual EnumImageTrapPlacement GetImageTrapPlacement() const;

/**
* Typesafe attribute validation of ImageTrapPlacement
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidImageTrapPlacement(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImageTrapWidth
*@param double value: the value to set the attribute to
*/
	virtual void SetImageTrapWidth(double value);
/**
* Get double attribute ImageTrapWidth
* @return double the vaue of the attribute 
*/
	virtual double GetImageTrapWidth() const;
/**
* Typesafe attribute validation of ImageTrapWidth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageTrapWidth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImageTrapWidthY
*@param double value: the value to set the attribute to
*/
	virtual void SetImageTrapWidthY(double value);
/**
* Get double attribute ImageTrapWidthY
* @return double the vaue of the attribute 
*/
	virtual double GetImageTrapWidthY() const;
/**
* Typesafe attribute validation of ImageTrapWidthY
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageTrapWidthY(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SlidingTrapLimit
*@param double value: the value to set the attribute to
*/
	virtual void SetSlidingTrapLimit(double value);
/**
* Get double attribute SlidingTrapLimit
* @return double the vaue of the attribute 
*/
	virtual double GetSlidingTrapLimit() const;
/**
* Typesafe attribute validation of SlidingTrapLimit
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSlidingTrapLimit(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StepLimit
*@param double value: the value to set the attribute to
*/
	virtual void SetStepLimit(double value);
/**
* Get double attribute StepLimit
* @return double the vaue of the attribute 
*/
	virtual double GetStepLimit() const;
/**
* Typesafe attribute validation of StepLimit
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStepLimit(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrapColorScaling
*@param double value: the value to set the attribute to
*/
	virtual void SetTrapColorScaling(double value);
/**
* Get double attribute TrapColorScaling
* @return double the vaue of the attribute 
*/
	virtual double GetTrapColorScaling() const;
/**
* Typesafe attribute validation of TrapColorScaling
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrapColorScaling(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrapWidth
*@param double value: the value to set the attribute to
*/
	virtual void SetTrapWidth(double value);
/**
* Get double attribute TrapWidth
* @return double the vaue of the attribute 
*/
	virtual double GetTrapWidth() const;
/**
* Typesafe attribute validation of TrapWidth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrapWidth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrapWidthY
*@param double value: the value to set the attribute to
*/
	virtual void SetTrapWidthY(double value);
/**
* Get double attribute TrapWidthY
* @return double the vaue of the attribute 
*/
	virtual double GetTrapWidthY() const;
/**
* Typesafe attribute validation of TrapWidthY
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrapWidthY(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element ColorantZoneDetails
* 
* @param int iSkip number of elements to skip
* @return JDFColorantZoneDetails The element
*/
	JDFColorantZoneDetails GetCreateColorantZoneDetails(int iSkip=0);

/**
* const get element ColorantZoneDetails
* @param int iSkip number of elements to skip
* @return JDFColorantZoneDetails The element
*/
	JDFColorantZoneDetails GetColorantZoneDetails(int iSkip=0)const;
/**
* Append element ColorantZoneDetails
 */
	JDFColorantZoneDetails AppendColorantZoneDetails();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoTrappingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoTrappingParams_H_
