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

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include "Random.h"

#include "PlatformUtils.h"

#include <cmath>

namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 


/******************************************************************************
 *	Defines and constants
 ******************************************************************************/ 


/******************************************************************************
 *	Typedefs
 ******************************************************************************/ 


/******************************************************************************
 *	Classes
 ******************************************************************************/ 

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

Random::Random()
{
	// initial seed value is current time in millis since 
	// the user started windows

	setSeed(PlatformUtils::getCurrentMillis());
}

Random::Random(JDFUInt64 seed)
{
	setSeed(seed);
}

void Random::setSeed(JDFUInt64 seed)
{
	JDFUInt64 pow48 = 1;
	pow48 <<= 48;
	pow48 -= 1;
#ifndef _WIN32
	JDFUInt64 t = 0x5DEECE66;// 0x5DEECE66D;
	t<<= 4;
	t^= 0xD;
	mSeed = (seed ^ t) & pow48;
#else
	mSeed = (seed ^ 0x5DEECE66DL) & pow48;
#endif
    mHaveNextGaussian = false;
}

unsigned long Random::next(long bits)
{
    	JDFUInt64 pow48 = 1;
	pow48 <<= 48;
	pow48 -= 1;
#ifndef _WIN32
	JDFUInt64 t = 0x5DEECE66;// 0x5DEECE66D;
	t<<= 4;
	t^= 0xD;
	mSeed = (mSeed * t + 0xBL) & pow48;
#else
	mSeed = (mSeed * 0x5DEECE66DL + 0xBL) & pow48;
#endif
   return (unsigned long)(mSeed >> (48 - bits));
}

unsigned long Random::nextInt(void)
{
	return next(32);
}

unsigned long Random::nextInt(unsigned long n) 
{
     if ((n & -n) == n)  // i.e., n is a power of 2
         return (int)((n * (long)next(31)) >> 31);

     unsigned long bits, val;

     do 
	 {
         bits = next(31);
         val = bits % n;
     } while(bits - val + (n-1) < 0);
     return val;
}

unsigned short Random::nextShort(void)
{
	return (unsigned short) next(16);
}

JDFUInt64 Random::nextLong(void)
{
	
       return ((JDFUInt64)next(32) << 32) + (JDFUInt64)next(32);
}

void Random::nextBytes(char* b, int blen)
{
	while (blen)
	{
		*b = (char) next(8);
		++b;
		blen--;
	}
}

bool Random::nextBoolean(void)
{
	return next(1) != 0;
}

double Random::nextDouble(void)
{
	  JDFInt64 l = 1;
	  l <<= 53;
      return (((JDFInt64)next(26) << 27) + next(27))
          / (double)(l);
}

float Random::nextFloat(void)
{
	return next(24) / ((float)(1 << 24));
}
 
double Random::nextGaussian(void)
{

    if (mHaveNextGaussian) 
	{
            mHaveNextGaussian = false;
            return mNextGaussian;
    } 
	else 
	{
            double v1, v2, s;
            do { 
                    v1 = 2 * nextDouble() - 1;   // between -1.0 and 1.0
                    v2 = 2 * nextDouble() - 1;   // between -1.0 and 1.0
                    s = v1 * v1 + v2 * v2;
            } while (s >= 1);
            double norm = std::sqrt(-2 * std::log(s)/s);
            mNextGaussian = v2 * norm;
            mHaveNextGaussian = true;
            return v1 * norm;
    }
 
}

} // namespace JDF

 
/* end of file */
