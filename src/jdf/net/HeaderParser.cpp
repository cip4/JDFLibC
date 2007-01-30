/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2002 The International Cooperation for the Integration of 
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

#include "HeaderParser.h"

#include <jdf/lang/Integer.h>

#include <xercesc/util/XMLUniDefs.hpp>


XERCES_CPP_NAMESPACE_USE

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

HeaderParser::HeaderParser(const WString& raw)
{
	this->raw = raw;
	tab.resize(10);
	parse();
}

void HeaderParser::parse()
{
	int beg      = 0;
	int end      = 0;
	unsigned int i        = 0;
	bool inKey   = true;
	bool inQuote = false;
	int len      = raw.length();

	raw = raw.trim();

	while (end < len)
	{
		char c = raw[end];
		if (c == chEqual)
		{
			if (i == tab.capacity())
				tab.reserve(tab.capacity()+5);
			tab[i].first = WString(raw,beg,end-beg).toLowerCase();
			inKey = false;
			end++;
			beg = end;
		}
		else if (c == chDoubleQuote) 
		{
			if (inQuote)
			{
				tab[i++].second = WString(raw,beg,end-beg);
				inQuote=false;
				do 
				{
				    end++;
				} while (end < len && (raw[end] == chSpace || raw[end] == chComma));
				inKey=true;
				beg=end;
			} 
			else 
			{
				inQuote=true;
				end++;
				beg=end;
		    }
		} 
		else if (c == chSpace || c == chComma)
		{ // end key/val, of whatever we're in
		    if (inQuote) 
			{
				end++;
				continue;
		    } 
			else if (inKey) 
			{
				tab[i++].first = WString(raw, beg, end-beg).toLowerCase();
		    } 
			else 
			{
				tab[i++].second = WString(raw, beg, end-beg);
		    }
		    while (end < len && (raw[end] == chSpace || raw[end] == chComma)) 
			{
				end++;
		    }
		    inKey = true;
		    beg   = end;
		}
		else {
		    end++;
		}
	}
	// get last key/val, if any
	if (--end > beg) 
	{
		if (!inKey) 
		{
			if (raw[end] == chDoubleQuote) 
			{
				tab[i++].second = WString(raw, beg, end-beg);
			} else 
			{
				tab[i++].second = WString(raw, beg, end-beg+1);
			}
		}
		else 
		{
			tab[i].first = WString(raw, beg, end-beg+1).toLowerCase();
		}
	} 
	else if (end == beg) 
	{
		if (!inKey) 
		{
			if (raw[end] == chDoubleQuote) 
				tab[i++].second = WString(1,raw[end-1]);
			else 
				tab[i++].second = WString(1,raw[end]);
		}
		else 
			tab[i].first = WString(1,raw[end]).toLowerCase();
	} 
}


HeaderParser::value_pair HeaderParser::findKey(int i)
{
	// maximum 10?
	if (i<0 || static_cast<unsigned int>(i)>tab.size())
		return value_pair(false,"");

	return value_pair(true,tab[i].first);
}

HeaderParser::value_pair HeaderParser::findValue(int i)
{
	if (i<0 || static_cast<unsigned int>(i)>tab.size())
		return value_pair(false,"");

	return value_pair(true,tab[i].second);
}

HeaderParser::value_pair HeaderParser::findValue(const WString& key)
{
	WString l_key = key.toLowerCase();

	for (unsigned int i=0;i<tab.size();i++)
	{
		if (tab[i].first == key)
			return value_pair(true,tab[i].second);
	}
	return value_pair(false,"");
}

HeaderParser::value_pair HeaderParser::findValue(const WString& key, const WString& Default)
{
	WString l_key = key.toLowerCase();

	for (unsigned int i=0;i<tab.size();i++)
	{
		if (tab[i].first == l_key)
			return value_pair(true,tab[i].second);
	}
	return value_pair(true,Default);
}

int HeaderParser::findInt(const WString& k, int Default)
{
	return Integer::parseInt(findValue(k, WString::valueOf(Default)).second);
}

} // namespace JDF
