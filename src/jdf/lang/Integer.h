/*
 * The CIP4 Software License, Version 0.1
 *
 *
 * Copyright (c) 2001 The International Cooperation for the Integration of 
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
/******************************************************************************
 *                     Copyright 1998 Agfa-Gevaert N.V.                       *
 *                           All rights reserved                              *
 *                                                                            *
 * The material contained herein may not be reproduced in whole or in part,   *
 *        without the prior written consent of Agfa-Gevaert N.V.              *
 *                                                                            *
 ******************************************************************************/

/*******************************************************************************
 * 
 * Description:
 *
 *
 ******************************************************************************/

#ifndef I_JDF_INTEGER_H
#define I_JDF_INTEGER_H


/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include "JDFToolsDefs.h"

namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 
	class WString;

/******************************************************************************
 *	Defines and constants
 ******************************************************************************/ 


/******************************************************************************
 *	Typedefs
 ******************************************************************************/ 


/******************************************************************************
 *	Classes
 ******************************************************************************/ 

/**
 * The Integer class wraps a value of the primitive type <code>int</code> in an
 * object. An object of type <code>Integer</code> contains a single field whose
 * type is <code>int</code>
 * <p>
 * In addition, this class provides several methods for converting an <code>
 * int</code> to a <code>WString</code> and a <code>WString</code> to an <code>int</code>,
 * as well as other constants and methods useful when dealing with an <code>int</code>
 * @ingroup lang
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT Integer
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * Constructs a newly allocated <code>Integer</code> object that represents the
	 * primitive <code>int</code> argument.
	 * @param value the value to be represented by the <code>Integer</code>.
	 */
	Integer(int value);

	/**
	 * Constructs a newly allocated <code>Integer</code> that represents the value
	 * represented by the string. The string is converted to an <code>int</code> in
	 * exactly the manner used by the <code>parseInt</code> method for radix 10.
	 * @param s the <code>WString</code> to be converted to an <code>Integer</code>.
	 */
	Integer(const WString& s);

	/**
	 * Constructs a newly allocated <code>Integer</code> that represent the same
	 * value as the given <code>Integer</code> argument.
	 */
	Integer(const Integer& i);

/*@}*/ 

	/**
	 * Compares this object to the specified object
	 * @param i the <code>Integer</code> object to compare with
	 */
	bool operator==(const Integer& i);

    /**
	 * Compares this object to the specified object
	 * @param i the <code>Integer</code> object to compare with
     */
	bool operator!=(const Integer& i);

	/**
	 * Returns the value of this Integer as a byte.
	 */
	char   byteValue();

	/**
	 * Returns the value of this Integer as a double.
	 */
	double doubleValue();

	/**
	 * Returns the value of this Integer as a float.
	 */
	float  floatValue();

	/**
	 * Returns the value of this Integer as an int.
	 */
	int    intValue();

	/**
	 * Returns the value of this Integer as a long.
	 */
	long   longValue();

	/**
	 * Returns the value of this Integer as a short.
	 */
	short  shortValue();

	/**
	 * Returns the value of this Integer as a int64.
	 */
	JDFInt64    int64Value();

	/**
	 * Parses the WString argument as a signed decimal integer.
	 * The characters in the WString must all be decimal digits, except
	 * that the first character may be an ASCII minus sign to indicate a 
	 * negative value. 
	 * @param s a string
	 * @return the integer represented by the argument in decimal.
	 */
	static int parseInt(const WString& s);

	/** 
	 * Constructs a string representation of the integer argument as an
	 * unsigned integer in base 2.
	 * @param i an integer
	 * @return the integer represented by the argument in binary (base 2)
	 */
	static WString toBinaryString(int i);

	/** 
	 * Constructs a string representation of the integer argument as an
	 * unsigned integer in base 16.
	 * @param i an integer
	 * @return the integer represented by the argument in hex (base 16)
	 */
	static WString toHexString(int i);

	/** 
	 * Constructs a string representation of the integer argument as an
	 * unsigned integer in base 8.
	 * @param i an integer
	 * @return the integer represented by the argument in binary (base 8)
	 */
	static WString toOctalString(int i);

	/**
	 * Returns a new WString object that represents the specified integer.
	 * The argument is converted to signed decimal representation and returned
	 * as a string
	 * @param i an integer to be converted
	 * @return a string representation of the argument in base 10.
	 */
	static WString toString(int i);

	/**
	 * Creates a WString representation of the first argument in the radix 
	 * specified by the second argument.
	 * @param i an integer to be converted
	 * @param radix the radix
	 * @return a string representation of the argument in the specified radix.
	 */
	static WString toString(int i, int radix);

	/**
	 * Returns a new Integer object initialized to the value of the specified 
	 * WString. The argument is interpreted as representing a signed decimal
	 * integer.
	 * @param s the string to be parsed.
	 * @return a newly constructed <code>Integer</code> initialized to the 
	 * value represented by the string argument.
	 */
 	static Integer valueOf(const WString& s);

	/**
	 * Returns a new Integer object initialized to the value of the specified
	 * WString. The argument is interpreted as representing a signed decimal
	 * integer.
	 * @param s the string to be parsed.
	 * @return a newly constructed <code>Integer</code> initialized to the 
	 * value represented by the string argument.
	 */
	WString toString();

private:

	int iValue;
};


/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_INTEGER_H */
