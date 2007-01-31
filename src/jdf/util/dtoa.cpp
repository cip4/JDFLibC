/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2005 The International Cooperation for the Integration of 
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


#include "dtoa.h"

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

// This file is copied from a unix implementation.
// It is used to make sure the formatting of doubles is not influenced by locale settings.

#include "string.h"
#include "ctype.h"
#include "math.h"
#include "float.h"



#if defined(__GNUC__) || defined(__MWERKS__)
	#define JDF_IS_FINITE(arg)	isfinite(arg)
	#define JDF_IS_NAN(arg)	isnan(arg)
#else
	#define JDF_IS_FINITE(arg)	_finite(arg)
	#define JDF_IS_NAN(arg)	_isnan(arg)
#endif

/*
 * Floating point output, cvt() onward lifted from BSD sources:
 *
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */


#define MAX_FCONVERSION 512     /* largest possible real conversion     */
#define MAX_EXPT        5       /* largest possible exponent field */
#define MAX_FRACT       39      /* largest possible fraction field */

#define TESTFLAG(x)     0


typedef double rtype;

#define to_char(n)      ((n) + '0')
#define to_digit(c)     ((c) - '0')

static int cvt (rtype arg, int prec, char *signp, int fmtch,
                char *startp, char *endp);
static char *round (double fract, int *exp, char *start, char *end, 
                    char ch, char *signp);
static char *exponent(char *p, int exp, int fmtch);


int dtoa (char *dbuf, double arg, int fmtch, int width, int prec)
{
    char        buf[MAX_FCONVERSION+1], *cp;
    char        sign;
    int         size;

    if( !JDF_IS_FINITE(arg) ) {
        if( JDF_IS_NAN(arg) )
          strcpy (dbuf, "NaN");
        else if( arg < 0) 
          strcpy (dbuf, "-Infinity");
        else
          strcpy (dbuf, "Infinity");
        return strlen(dbuf);
    }

    if (prec == 0)
      prec = 6;
    else if (prec > MAX_FRACT)
      prec = MAX_FRACT;

    /* leave room for sign at start of buffer */
    cp = buf + 1;

    /*
     * cvt may have to round up before the "start" of
     * its buffer, i.e. ``intf("%.2f", (double)9.999);'';
     * if the first character is still NUL, it did.
     * softsign avoids negative 0 if _double < 0 but
     * no significant digits will be shown.
     */
    *cp = '\0';
    size = cvt (arg, prec, &sign, fmtch, cp, buf + sizeof(buf));
    if (*cp == '\0')
      cp++;

    if (sign)
      *--cp = sign, size++;

    cp[size] = 0;
    memcpy (dbuf, cp, size + 1);
	return size;
}


static int cvt (rtype number, int prec, char *signp, int fmtch,
                char *startp, char *endp)
{
        register char *p, *t;
        register double fract;
        double integer, tmp;
        int dotrim, expcnt, gformat;

        dotrim = expcnt = gformat = 0;
        if (number < 0) {
                number = -number;
                *signp = '-';
        } else
                *signp = 0;

        fract = modf(number, &integer);

        /* get an extra slot for rounding. */
        t = ++startp;

        /*
         * get integer portion of number; put into the end of the buffer; the
         * .01 is added for modf(356.0 / 10, &integer) returning .59999999...
         */
        for (p = endp - 1; integer; ++expcnt) {
                tmp = modf(integer / 10, &integer);
                *p-- = to_char((int)((tmp + .01) * 10));
        }
        switch (fmtch) {
        case 'f':
                /* reverse integer into beginning of buffer */
                if (expcnt)
                        while (++p < endp) *t++ = *p;
                else
                        *t++ = '0';
                /* if requires more precision and some fraction left */
                if (fract) 
					 {
                         *t++ = '.'; //decimal point
                        size_t zerocount = 0;
								if (prec)
									  do 
									  {
												 fract = modf(fract * 10, &tmp);
												 if (tmp)
													 zerocount = 0;
												else
													zerocount++;
												 *t++ = to_char((int)tmp);
									  } while (--prec && fract);
                        if (fract)
                             startp = round(fract, (int *)NULL, startp,t - 1, (char)0, signp);
								if (*(t-1) != '0')
									zerocount = 0;
								t -= zerocount;

                }
					 else
					 {
						/* pschelle: output integer part only.
						*t++ = '.';
						*t++ = '0';
						*/
					 }
                break;
        case 'e':
        case 'E':
eformat:        if (expcnt) {
                        *t++ = *++p;
                        if (prec || TESTFLAG(ALTERNATE_FORM))
                                *t++ = '.';
                        /* if requires more precision and some integer left */
                        for (; prec && ++p < endp; --prec)
                                *t++ = *p;
                        /*
                         * if done precision and more of the integer component,
                         * round using it; adjust fract so we don't re-round
                         * later.
                         */
                        if (!prec && ++p < endp) {
                                fract = 0;
                                startp = round((double)0, &expcnt, startp,
                                    t - 1, *p, signp);
                        }
                        /* adjust expcnt for digit in front of decimal */
                        --expcnt;
                }
                /* until first fractional digit, decrement exponent */
                else if (fract) {
                        /* adjust expcnt for digit in front of decimal */
                        for (expcnt = -1;; --expcnt) {
                                fract = modf(fract * 10, &tmp);
                                if (tmp)
                                        break;
                        }
                        *t++ = to_char((int)tmp);
                        if (prec || TESTFLAG(ALTERNATE_FORM))
                                *t++ = '.';
                }
                else {
                        *t++ = '0';
                        if (prec || TESTFLAG(ALTERNATE_FORM))
                                *t++ = '.';
                }
                /* if requires more precision and some fraction left */
                if (fract) {
                        if (prec)
                                do {
                                        fract = modf(fract * 10, &tmp);
                                        *t++ = to_char((int)tmp);
                                } while (--prec && fract);
                        if (fract)
                                startp = round(fract, &expcnt, startp,
                                    t - 1, (char)0, signp);
                }
                /* if requires more precision */
                while (prec--) *t++ = '0';

                /* unless alternate flag, trim any g/G format trailing 0's */
                if (gformat && !TESTFLAG(ALTERNATE_FORM)) {
                        while (t > startp && *--t == '0') {}
                        if (*t == '.')
                                --t;
                        ++t;
                }
                t = exponent(t, expcnt, fmtch);
                break;
        case 'g':
        case 'G':
                /* a precision of 0 is treated as a precision of 1. */
                if (!prec)
                        ++prec;
                /*
                 * ``The style used depends on the value converted; style e
                 * will be used only if the exponent resulting from the
                 * conversion is less than -4 or greater than the precision.''
                 *      -- ANSI X3J11
                 */
                if (expcnt > prec || !expcnt && fract && fract < .0001) {
                        /*
                         * g/G format counts "significant digits, not digits of
                         * precision; for the e/E format, this just causes an
                         * off-by-one problem, i.e. g/G considers the digit
                         * before the decimal point significant and e/E doesn't
                         * count it as precision.
                         */
                        --prec;
                        fmtch -= 2;             /* G->E, g->e */
                        gformat = 1;
                        goto eformat;
                }
                /*
                 * reverse integer into beginning of buffer,
                 * note, decrement precision
                 */
                if (expcnt)
                        while(++p < endp) { *t++ = *p; --prec;}
                else
                        *t++ = '0';
                /*
                 * if precision required or alternate flag set, add in a
                 * decimal point.  If no digits yet, add in leading 0.
                 */
                if (prec || TESTFLAG(ALTERNATE_FORM)) {
                        dotrim = 1;
                        *t++ = '.';
                }
                else
                        dotrim = 0;
                /* if requires more precision and some fraction left */
                if (fract) {
                        if (prec) {
                                do {
                                    fract = modf(fract * 10, &tmp);
                                    *t++ = to_char((int)tmp);
                                } while(!tmp && !expcnt);
                                while (--prec && fract) {
                                        fract = modf(fract * 10, &tmp);
                                        *t++ = to_char((int)tmp);
                                }
                        }
                        if (fract)
                                startp = round(fract, (int *)NULL, startp,
                                    t - 1, (char)0, signp);
                }
                /* alternate format, adds 0's for precision, else trim 0's */
                if (TESTFLAG(ALTERNATE_FORM))
                        while(prec--)  *t++ = '0';
                else if (dotrim) {
                        while (t > startp && *--t == '0') {}
                        if (*t != '.')
                                ++t;
                }
        }
        return (t - startp);
}


static char *
round(double fract, int *exp, char *start, char *end, char ch, char *signp)
{
        double tmp;

        if (fract)
                (void)modf(fract * 10, &tmp);
        else
                tmp = to_digit(ch);
        if (tmp > 4)
                for (;; --end) {
                        if (*end == '.')
                                --end;
                        if (++*end <= '9')
                                break;
                        *end = '0';
                        if (end == start) {
                                if (exp) {      /* e/E; increment exponent */
                                        *end = '1';
                                        ++*exp;
                                }
                                else {          /* f; add extra digit */
                                *--end = '1';
                                --start;
                                }
                                break;
                        }
                }
        /* ``"%.3f", (double)-0.0004'' gives you a negative 0. */
        else if (*signp == '-')
                for (;; --end) {
                        if (*end == '.')
                                --end;
                        if (*end != '0')
                                break;
                        if (end == start)
                                *signp = 0;
                }
        return (start);
}

static char *
exponent(char *p, int exp, int fmtch)
{
        register char *t;
        char expbuf[MAX_FCONVERSION];

        *p++ = fmtch;
        if (exp < 0) {
                exp = -exp;
                *p++ = '-';
        }
        else
                *p++ = '+';
        t = expbuf + MAX_FCONVERSION;
        if (exp > 9) {
                do {
                        *--t = to_char(exp % 10);
                } while ((exp /= 10) > 9);
                *--t = to_char(exp);
                while(t < expbuf + MAX_FCONVERSION) *p++ = *t++;
        }
        else {
                *p++ = '0';
                *p++ = to_char(exp);
        }
        return (p);
}



