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

 
#if !defined _JDFAutoColorMeasurementConditions_H_
#define _JDFAutoColorMeasurementConditions_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoColorMeasurementConditions : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoColorMeasurementConditions class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFColorMeasurementConditions should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoColorMeasurementConditions : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoColorMeasurementConditions():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoColorMeasurementConditions(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoColorMeasurementConditions &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoColorMeasurementConditions(){};
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
* Enumeration for attribute DensityStandard
*/

	enum EnumDensityStandard{DensityStandard_Unknown,DensityStandard_ANSIA,DensityStandard_ANSIE,DensityStandard_ANSII,DensityStandard_ANSIT,DensityStandard_DIN16536,DensityStandard_DIN16536NB};
/**
* Enumeration for attribute Illumination
*/

	enum EnumIllumination{Illumination_Unknown,Illumination_D50,Illumination_D65};
/**
* Enumeration for attribute InkState
*/

	enum EnumInkState{InkState_Unknown,InkState_Dry,InkState_Wet,InkState_NA};
/**
* Enumeration for attribute MeasurementFilter
*/

	enum EnumMeasurementFilter{MeasurementFilter_Unknown,MeasurementFilter_None,MeasurementFilter_Pol,MeasurementFilter_UV};
/**
* Enumeration for attribute SampleBacking
*/

	enum EnumSampleBacking{SampleBacking_Unknown,SampleBacking_Black,SampleBacking_White,SampleBacking_NA};
/**
* Enumeration for attribute WhiteBase
*/

	enum EnumWhiteBase{WhiteBase_Unknown,WhiteBase_Absolute,WhiteBase_Paper};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for DensityStandard
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& DensityStandardString();
/**
* Enumeration string for enum value
* @param EnumDensityStandard value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString DensityStandardString(EnumDensityStandard value);
/**
* Set attribute DensityStandard
* @param EnumDensityStandard value the value to set the attribute to
*/
	virtual void SetDensityStandard( EnumDensityStandard value);

/**
* Typesafe enumerated attribute DensityStandard; defaults to ANSIT
* @return EnumDensityStandardthe enumeration value of the attribute
*/
	virtual EnumDensityStandard GetDensityStandard() const;

/**
* Typesafe attribute validation of DensityStandard
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidDensityStandard(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Illumination
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& IlluminationString();
/**
* Enumeration string for enum value
* @param EnumIllumination value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString IlluminationString(EnumIllumination value);
/**
* Set attribute Illumination
* @param EnumIllumination value the value to set the attribute to
*/
	virtual void SetIllumination( EnumIllumination value);

/**
* Typesafe enumerated attribute Illumination; defaults to D50
* @return EnumIlluminationthe enumeration value of the attribute
*/
	virtual EnumIllumination GetIllumination() const;

/**
* Typesafe attribute validation of Illumination
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidIllumination(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Observer
*@param int value: the value to set the attribute to
*/
	virtual void SetObserver(int value);
/**
* Get integer attribute Observer
* @return int the vaue of the attribute ; defaults to 2
*/
	virtual int GetObserver() const;
/**
* Typesafe attribute validation of Observer
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidObserver(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Instrumentation
*@param WString value: the value to set the attribute to
*/
	virtual void SetInstrumentation(const WString& value);
/**
* Get string attribute Instrumentation
* @return WString the vaue of the attribute 
*/
	virtual WString GetInstrumentation() const;
/**
* Typesafe attribute validation of Instrumentation
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidInstrumentation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for InkState
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& InkStateString();
/**
* Enumeration string for enum value
* @param EnumInkState value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString InkStateString(EnumInkState value);
/**
* Set attribute InkState
* @param EnumInkState value the value to set the attribute to
*/
	virtual void SetInkState( EnumInkState value);

/**
* Typesafe enumerated attribute InkState
* @return EnumInkStatethe enumeration value of the attribute
*/
	virtual EnumInkState GetInkState() const;

/**
* Typesafe attribute validation of InkState
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidInkState(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for MeasurementFilter
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& MeasurementFilterString();
/**
* Enumeration string for enum value
* @param EnumMeasurementFilter value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString MeasurementFilterString(EnumMeasurementFilter value);
/**
* Set attribute MeasurementFilter
* @param EnumMeasurementFilter value the value to set the attribute to
*/
	virtual void SetMeasurementFilter( EnumMeasurementFilter value);

/**
* Typesafe enumerated attribute MeasurementFilter
* @return EnumMeasurementFilterthe enumeration value of the attribute
*/
	virtual EnumMeasurementFilter GetMeasurementFilter() const;

/**
* Typesafe attribute validation of MeasurementFilter
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMeasurementFilter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for SampleBacking
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SampleBackingString();
/**
* Enumeration string for enum value
* @param EnumSampleBacking value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SampleBackingString(EnumSampleBacking value);
/**
* Set attribute SampleBacking
* @param EnumSampleBacking value the value to set the attribute to
*/
	virtual void SetSampleBacking( EnumSampleBacking value);

/**
* Typesafe enumerated attribute SampleBacking
* @return EnumSampleBackingthe enumeration value of the attribute
*/
	virtual EnumSampleBacking GetSampleBacking() const;

/**
* Typesafe attribute validation of SampleBacking
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSampleBacking(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for WhiteBase
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& WhiteBaseString();
/**
* Enumeration string for enum value
* @param EnumWhiteBase value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString WhiteBaseString(EnumWhiteBase value);
/**
* Set attribute WhiteBase
* @param EnumWhiteBase value the value to set the attribute to
*/
	virtual void SetWhiteBase( EnumWhiteBase value);

/**
* Typesafe enumerated attribute WhiteBase
* @return EnumWhiteBasethe enumeration value of the attribute
*/
	virtual EnumWhiteBase GetWhiteBase() const;

/**
* Typesafe attribute validation of WhiteBase
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidWhiteBase(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoColorMeasurementConditions

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoColorMeasurementConditions_H_
