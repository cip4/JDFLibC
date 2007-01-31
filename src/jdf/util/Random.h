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

#ifndef I_JDF_RANDOM_H
#define I_JDF_RANDOM_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <jdf/lang/JDFToolsDefs.h>

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

/**
 * An instance of this class is used to generate a stream of pseudorandom numbers.
 * The class uses a 48-bit seed, which is modified using a linear congruential formula. 
 * (See <i>Donald Knuth, The Art of Computer Programming, Volume 2</i>, Section 3.2.1.) 
 * <p>
 * If two instances of <code>Random</code> are created with the same seed, 
 * and the same sequence of method calls is made for each, they will
 * generate and return identical sequences of numbers. In order to guarantee 
 * this property, particular algorithms are specified for the class <code>Random</code>. 
 * However, subclasses of class <code>Random</code> are permitted to use other algorithms, 
 * so long as they adhere to the general contracts for all the methods. 
 * <p>
 * The algorithms implemented by class <code>Random</code> use three state variables,
 * which are <code>protected</code>. They also use a protected utility method that on
 * each invocation can supply up to 32 pseudorandomly generated bits. 
 * @ingroup util
 *
 * @author nverbove     
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT Random
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * Creates a new random number generator. 
	 * Its seed is initialized to a value based on the current time 
	 */

	Random();

	/**
	 * Creates a new random number generator using a single long seed.
	 * Used by method <code>next</code> to hold the state of the pseudorandom number generator.
	 * 
	 * @param seed the initial seed.
	 * @see Random#setSeed()    
	 */

	Random(JDFUInt64 seed);
/*@}*/ 
	///////////////////////////////////////////////////////////////////////////
	// Public Instance Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Generates a user specified number of random bytes.
	 */

	virtual void   nextBytes(char* b, int blen);

	/**
	 * Returns the next pseudorandom, uniformly distributed <code>boolean</code> value from 
	 * this random number generator's sequence. The general contract of <code>nextBoolean</code>
	 * is that one <code>boolean</code> value is pseudorandomly generated and returned. 
	 * The values <code>true</code> and <code>false</code> are produced with (approximately)
	 * equal probability. 
	 * 
	 * @return the next pseudorandom, uniformly distributed.
	 */

	virtual	bool   nextBoolean(void);

	/**
	 * Returns the next pseudorandom, uniformly distributed <code>double</code> value between <code>0.0</code> and <code>1.0</code> from this random number generator's sequence. 
	 * <p>
	 * The general contract of <code>nextDouble</code> is that one <code>double</code> value, chosen (approximately) uniformly from the range <code>0.0d</code> (inclusive) to <code>1.0d</code> (exclusive), 
	 * is pseudorandomly generated and returned. All 2^53 possible <code>float</code> values of the 
	 * form <i>m</i> x 2^53 , where <i>m</i> is a positive integer less than 2^53, are produced with 
	 * (approximately) equal probability.
	 * The hedge "approximately" is used in the foregoing description only because the <code>next</code>
	 * method is only approximately an unbiased source of independently chosen bits.
	 * If it were a perfect source or randomly chosen bits, then the algorithm shown 
	 * would choose <code>double</code> values from the stated range with perfect uniformity. 
	 * 
	 * @return the next pseudorandom, uniformly distributed <code>double</code> value between <code>0.0</code> and <code>1.0</code> from this random number generator's sequence.
	 */

	virtual double nextDouble(void);

	/**
	 * Returns the next pseudorandom, uniformly distributed <code>float</code> value between <code>0.0</code> and <code>1.0</code> from this random number generator's sequence. 
	 * <p>
	 * The general contract of <code>nextFloat</code> is that one <code>float</code> value, chosen (approximately) uniformly from the range <code>0.0f</code> (inclusive) to <code>1.0f</code> (exclusive), 
	 * is pseudorandomly generated and returned. All 2^53 possible <co4de>float</code> values of the 
	 * form <i>m</i> x 2^24 , where <i>m</i> is a positive integer less than 2^24, are produced with 
	 * (approximately) equal probability.
	 * The hedge "approximately" is used in the foregoing description only because the <code>next</code>
	 * method is only approximately an unbiased source of independently chosen bits.
	 * If it were a perfect source or randomly chosen bits, then the algorithm shown 
	 * would choose <code>double</code> values from the stated range with perfect uniformity. 
	 * 
	 * @return the next pseudorandom, uniformly distributed <code>float</code> value between <code>0.0</code> and <code>1.0</code> from this random number generator's sequence.
	 */

	virtual	float  nextFloat(void);

	/**
	 * Returns the next pseudorandom, Gaussian ("normally") distributed <code>double</code> value with mean <code>0.0</code> and standard deviation <code>1.0</code> from this random number generator's sequence. 
	 * <p>
	 * The general contract of <code>nextGaussian</code> is that one <code>double</code> value, 
	 * chosen from (approximately) the usual normal distribution with mean <code>0.0</code> and
	 * standard deviation <code>1.0</code>, is pseudorandomly generated and returned. The method 
	 * <code>setSeed</code> is implemented by class <code>Random</code> as follows: 
	 * <p><blockquote><pre>
     *   public double nextGaussian() {
     *    if (haveNextNextGaussian) {
     *           haveNextNextGaussian = false;
     *           return nextNextGaussian;
     *    } else {
     *           double v1, v2, s;
     *           do { 
     *                   v1 = 2 * nextDouble() - 1;   // between -1.0 and 1.0
     *                   v2 = 2 * nextDouble() - 1;   // between -1.0 and 1.0
     *                   s = v1 * v1 + v2 * v2;
     *           } while (s >= 1);
     *           double norm = sqrt(-2 * log(s)/s);
     *           nextNextGaussian = v2 * multiplier;
     *           haveNextNextGaussian = true;
     *           return v1 * multiplier;
     *   }
     *  }
	 * </pre></blockquote><p>
	 * This uses the <i>polar method</i> of G. E. P. Box, M. E. Muller, and G. Marsaglia, 
	 * as described by Donald E. Knuth in <i>The Art of Computer Programming</i>, Volume 2: 
	 * <i>Seminumerical Algorithms</i>, section 3.4.1, subsection C, algorithm P. 
	 * Note that it generates two independent values at the cost of only one call 
	 * to <code>log</code> and one call to <code>sqrt</code>.
	 * 
	 * @return the next pseudorandom, Gaussian ("normally") distributed <code>double</code? value with mean <code>0.0</code> and standard deviation <code>1.0</code> from this random number generator's sequence.
	 */

	virtual	double nextGaussian(void);

	/**
	 * Returns the next pseudorandom, uniformly distributed <code>int</code> value from this random number generator's sequence. 
	 * <p>
	 * The general contract of <code>nextInt</code> is that one <code>int</code> value is pseudorandomly generated and returned. 
	 * All 2^32 possible <code>int</code> values are produced with (approximately) equal probability. 
	 * The method <code>nextInt</code> is implemented by class <code>Random</code> as follows:
	 * <code>
	 * public int nextInt() {  return next(32); }
	 * </code>
	 * 
	 * @return the next pseudorandom, uniformly distributed <code>int</code> value from this random number generator's sequence.
	 */

	virtual	unsigned long nextInt(void);

	/**
	 * Returns a pseudorandom, uniformly distributed <code>int</code> value between 0 
	 * (inclusive) and the specified value (exclusive), drawn from this '
	 * random number generator's sequence. 
	 * <p>
	 * The general contract of <code>nextInt</code>
	 * is that one <code>int</code> value in the specified range is pseudorandomly 
	 * generated and returned. All <code>n</code> possible <code>int</code> values are produced with 
	 * (approximately) equal probability. The method <code>nextInt(int n)</code> is
	 * implemented by class <code>Random</code> as follows: 
	 * <p><blockquote><pre>
     *   public int nextInt(int n) {
     *       if (n<=0)
     *          throw new IllegalArgumentException("n must be positive");
     *
     *       if ((n & -n) == n)  // i.e., n is a power of 2
     *           return (int)((n * (long)next(31)) >> 31);
     *
     *       int bits, val;
     *       do {
     *           bits = next(31);
     *           val = bits % n;
     *       } while(bits - val + (n-1) < 0);
     *       return val;
     *   }
	 * </pre></blockquote><p>
	 * The hedge "approximately" is used in the foregoing description only because the next 
	 * method is only approximately an unbiased source of independently chosen bits.
	 * If it were a perfect source of randomly chosen bits, then the algorithm shown 
	 * would choose <code>int</code> values from the stated range with perfect uniformity. 
	 * <p>  
	 * The algorithm is slightly tricky. It rejects values that would result in an uneven
	 * distribution (due to the fact that 2^31 is not divisible by n). The probability of
	 * a value being rejected depends on n. The worst case is n=2^30+1, 
	 * for which the probability of a reject is 1/2, and the expected number of 
	 * iterations before the loop terminates is 2. 
	 * <p>	
	 * The algorithm treats the case where n is a power of two specially: it returns
	 * the correct number of high-order bits from the underlying pseudo-random number 
	 * generator. In the absence of special treatment, the correct number of <i>low-order </i>
	 * bits would be returned. Linear congruential pseudo-random number generators such as
	 * the one implemented by this class are known to have short periods in the sequence 
	 * of values of their low-order bits. Thus, this special case greatly increases the 
	 * length of the sequence of values returned by successive calls to this method if n 
	 * is a small power of two.
	 * 
	 * @return a pseudorandom, uniformly distributed <code>int</code> value between 0 (inclusive) and n (exclusive).
	 */

	virtual	unsigned long nextInt(unsigned long);

	/**
	 * Returns the next pseudorandom, uniformly distributed <code>short</code> value from this random number generator's sequence. 
	 * <p>
	 * The general contract of <code>nextShort</code> is that one <code>short</code> value is pseudorandomly generated and returned. 
	 * All 2^16 possible <code>short</code> values are produced with (approximately) equal probability. 
	 * The method <code>nextShort</code> is implemented by class <code>Random</code> as follows:
	 * <code>
	 * public int nextInt() {  return next(16); }
	 * </code>
	 * 
	 * @return the next pseudorandom, uniformly distributed <code>short</code> value from this random number generator's sequence.
	 */

	virtual	unsigned short nextShort(void);

	/**
	 * Returns the next pseudorandom, uniformly distributed <code>long</code> value from this random number generator's sequence. 
	 * The general contract of <code>nextLong</code> is that one long value is pseudorandomly generated 
	 * and returned. All 2^64 possible <code>long</code> values are produced with (approximately) equal 
	 * 
	 * @return the next pseudorandom, uniformly distributed <code>long</code> value from this random number generator's sequence.
	 */

	virtual	JDFUInt64   nextLong(void);

	/**
	 * Sets the seed of this random number generator using a single <code>long</code> seed. 
	 * The general contract of <code>setSeed</code> is that it alters the state of this 
	 * random number generator object so as to be in exactly the same state 
	 * as if it had just been created with the argument seed as a seed. 
	 * The implementation of <code>setSeed</code> by class <code>Random</code> happens to use
	 * only 48 bits
	 * of the given seed. In general, however, an overriding method may use all 64 
	 * bits of the long argument as a seed value.
	 * 
	 * @param seed the initial seed
	 */

	virtual	void   setSeed(JDFUInt64 seed);

protected:

	///////////////////////////////////////////////////////////////////////////
	// Protected Constructors
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Generates the next pseudorandom number. 
	 * Subclass should override this, as this is used by all other methods.
	 * <p>
	 * The general contract of <code>next</code> is that it returns an <code>int</code>
	 * value and if the argument bits is between <code>1</code> and <code>32</code> 
	 * (inclusive), then that many low-order bits of the returned value will be 
	 * (approximately) independently chosen bit values, each of which is (approximately)
	 * equally likely to be <code>0</code> or <code>1</code>. The method <code>next</code> 
	 * is implemented by class <code>Random</code> as follows: 
	 * <p><blockquote><pre>
     * synchronized protected int next(int bits) 
	 * {
     *      seed = (seed * 0x5DEECE66DL + 0xBL) & ((1L << 48) - 1);
     *      return (int)(seed >>> (48 - bits));
     * }
     * </pre></blockquote><p>
	 * This is a linear congruential pseudorandom number generator, as defined
	 * by D. H. Lehmer and described by Donald E. Knuth in <code>The Art of Computer Programming</code>, Volume 2: 
	 * <code>Seminumerical Algorithms</code>, section 3.2.1.
	 * 
	 * @return the next pseudorandom value from this random number generator's sequence.
	 * @param bits random bits.
	 * @see     
	 */

	virtual unsigned long next(long bits);

	///////////////////////////////////////////////////////////////////////////
	// Protected Instance Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * The seed value for generating random numbers.
	 */

	JDFUInt64 mSeed;

	/**
	 * True if next Gaussian value is available; false otherwise
	 * @see nextGaussian
	 */

	bool	mHaveNextGaussian;

	/**
     * next Gaussian value. 
	 */

	double  mNextGaussian;
};

} // namespace JDF

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 


#endif /* I_JDF_RANDOM_H */


/* end of file */
