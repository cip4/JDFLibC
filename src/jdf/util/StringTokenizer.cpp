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

#include <jdf/lang/Exception.h>

#include <jdf/util/StringTokenizer.h>


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


	StringTokenizer::StringTokenizer(WString s, WString delim, bool flag) 
	{
		currentPosition = 0;
		str             = s;
		maxPosition     = s.length();
		delimiters      = delim;
		retTokens       = flag;

	}

	int StringTokenizer::countTokens()
	{
		int i = 0;

		for(int j = currentPosition; j < maxPosition;)
		{
			int pos = delimiters.find_first_of(str.at(j));
			while(!retTokens && j < maxPosition && pos >= 0) 
			{
				j++;
				if (j<maxPosition)
					pos = delimiters.find_first_of(str.at(j));
			}

			if(j >= maxPosition)
				break;
			int k = j;
			pos = delimiters.find_first_of(str.at(j));
			while(j < maxPosition && pos  < 0) 
			{
				j++;
				if (j<maxPosition)
					pos = delimiters.find_first_of(str.at(j));
			}

			if(retTokens && k == j)
			{
				pos = delimiters.find_first_of(str.at(j));
				if (pos >= 0)
				{
					j++;
					if (j<maxPosition)
						delimiters.find_first_of(str.at(j));
				}
			}
			i++;
		}

		return i;
	}


	bool StringTokenizer::hasMoreTokens()
	{
		skipDelimiters();
		return currentPosition < maxPosition;
	}

	WString StringTokenizer::nextToken()
	{
		skipDelimiters();
		if(currentPosition >= maxPosition)
			throw NoSuchElementException();

		int i = currentPosition;
		int pos  = delimiters.find_first_of(str.at(currentPosition));

		while (currentPosition < maxPosition && pos < 0)
		{
			currentPosition++;
			if (currentPosition < maxPosition)
				pos  = delimiters.find_first_of(str.at(currentPosition));
		}

		if (retTokens && i==currentPosition)
			if (delimiters.find_first_of(str.at(currentPosition)) >= 0)
				currentPosition++;

		WString s = str.substr(i, currentPosition-i); 
		return s;
	}

	WString StringTokenizer::nextToken(WString delim)
	{
		delimiters = delim;
		return nextToken();
	}

	void StringTokenizer::skipDelimiters()
	{
		if (!retTokens && (currentPosition < maxPosition))
		{
			int pos = delimiters.find_first_of(str.at(currentPosition),0);

			for(; !retTokens && (currentPosition < maxPosition) && (pos >= 0);)
			{
				currentPosition++;
				if (currentPosition < maxPosition)
					pos = delimiters.find_first_of(str.at(currentPosition),0);
			}
		}
	}


} // namespace JDF

/* end of file */
