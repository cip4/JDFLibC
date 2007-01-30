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

#ifndef I_JDF_STRINGTOKENIZER_H
#define I_JDF_STRINGTOKENIZER_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <jdf/lang/WString.h>


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
 * The string tokenizer class allows an application to break a string into tokens. 
 * The <code>StringTokenizer</code> methods do not distinguish among identifiers, numbers, 
 * and quoted strings, nor do they recognize and skip comments. 
 * <p>
 * The set of delimiters (the characters that separate tokens) may be specified either at
 * creation time or on a per-token basis. 
 * <p>
 * An instance of <code>StringTokenizer</code> behaves in one of two ways, depending on
 * whether it was created with the <code>returnTokens</code> flag having the value <code>true</code> or <code>false</code>: 
 * <p>
 * <ul>
 * <li>If the flag is <code>false</code>, delimiter characters serve to separate tokens.
 * A token is a maximal sequence of consecutive characters that are not delimiters. 
 * <li>If the flag is <code>true</code>, delimiter characters are themselves considered 
 * to be tokens. A token is thus either one delimiter character, or a maximal sequence of 
 * consecutive characters that are not delimiters. 
 * </li></ul><p>
 * A <code>StringTokenizer</code> object internally maintains a current position within 
 * the string to be tokenized. Some operations advance this current position past the 
 * characters processed.
 * <p>
 * A token is returned by taking a substring of the string that was used to create the
 * <code>StringTokenizer</code> object. 
 * <p>
 * The following is one example of the use of the tokenizer. The code: 
 * <p><blockquote><pre>
 *    StringTokenizer st = new StringTokenizer("this is a test");
 *    while (st.hasMoreTokens()) {
 *         std::cout<< st.nextToken() << std::endl;
 *    }
 * </pre></blockquote><p>
 * prints the following output: 
 * <p><blockquote><pre>
 *    this
 *    is
 *    a
 *    test
 * </pre></blockquote><p>
 *
 * @author nverbove     
 * @ingroup util
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT StringTokenizer
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * Constructs a string tokenizer for the specified string.
	 * All characters in the delim argument are the delimiters for separating tokens. 
	 * <p>
	 * If the <code>returnTokens</code> flag is <code>true</code>, then the delimiter characters are 
	 * also returned as tokens. Each delimiter is returned as a string of length one.
	 * If the flag is <code>false</code>, the delimiter characters are skipped and only 
	 * serve as separators between tokens.
	 * <p>
	 * By default, the tokenizer uses the default delimiter set, which is "\t\n\r\f": 
	 * the space character, the tab character, the newline character, the carriage-return 
	 * character, and the form-feed character. Delimiter characters themselves will not be
	 * treated as tokens.
 	 * 
	 * @param str a string to be parsed.
	 * @param delim the delimiters.
	 * @param returnTokens flag indicating whether to return the delimiters as tokens.
	 */

	StringTokenizer(WString str, WString delim = " \t\n\r\f", bool returnTokens = false);

/*@}*/ 

	/**
	 * Calculates the number of times that this tokenizer's nextToken method can be 
	 * called before it generates an exception. The current position is not advanced.
	 * 
	 * @return the number of tokens remaining in the string using the current delimiter set.
	 * @see StringTokenizer#nextToken()
	 */

	int countTokens();

	/**
	 * Tests if there are more tokens available from this tokenizer's string. 
	 * If this method returns <code>true</code>, then a subsequent call to <code>nextToken</code>
	 * with no argument will successfully return a token.
	 * 
	 * @return <code>true</code> if and only if there is at least one token in the string after the current position; <code>false</code> otherwise.
	 */

	bool hasMoreTokens();

	/**
	 * Returns the next token from this string tokenizer.
	 * 
	 * @return the next token from this string tokenizer.
	 * @exception NoSuchElementException if there are no more tokens in this tokenizer's string.
	 */

	WString nextToken();

	/**
	 * Returns the next token in this string tokenizer's string. First, the set of characters 
	 * considered to be delimiters by this <code>StringTokenizer</code> object is changed 
	 * to be the characters in the string delim. Then the next token in the string after
	 * the current position is returned. The current position is advanced beyond the 
	 * recognized token. The new delimiter set remains the default after this call.
	 * 
	 * @return the next token, after switching to the new delimiter set.
	 * @param delim the new delimiters.
	 * @exception NoSuchElementException if there are no more tokens in this tokenizer's string.
	 */

	WString nextToken(WString delim);

private:

	void skipDelimiters();

	int		 currentPosition;
	int		 maxPosition;
	WString	 str;	
	WString	 delimiters;
	bool	 retTokens;
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_STRINGTOKENIZER_H */


/* end of file */
