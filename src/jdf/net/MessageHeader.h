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

// 170903 RP removed nKey and replaced with mKeys.size()

#ifndef I_JDF_MESSAGEHEADER_H
#define I_JDF_MESSAGEHEADER_H

/******************************************************************************
*	Includes
******************************************************************************/ 
#include <jdf/lang/JDFToolsDefs.h>

#include <utility>
#include <vector>


namespace JDF
{
	
/******************************************************************************
*	Forward declarations
	******************************************************************************/ 
	class WString;
	class PrintStream;
	class InputStream;
	
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
	* An RFC 844 or MIME message header.  Includes methods
	* for parsing headers from incoming streams, fetching
	* values, setting values, and printing headers.
	* Key values of null are legal: they indicate lines in
	* the header that don't have a valid key, but do have
	* a value (this isn't legal according to the standard,
	* but lines like this are everywhere). 
	* @nosubgrouping
	*/
	
	class JDFTOOLS_EXPORT MessageHeader
	{
	public:
		
		typedef std::pair<bool,WString> value_pair;
		
		/** 
		* @name Constructors
		*/
		/*@{*/
		
		MessageHeader();
		MessageHeader(InputStream& is);
		virtual	~MessageHeader();

		
		/*@}*/ 
		
		MessageHeader& operator=(const MessageHeader& header);
		
		/**
		* Find the value that corresponds to this key.
		* It finds only the first occurrence of the key.
		* @param k the key to find.
		* @return (false,"") if not found, (true,value) otherwise
		*/
		
		value_pair findValue(const WString& k);
		
		value_pair getKey(int n);
		value_pair getValue(int n);
		
		/** Find the next value that corresponds to this key.
		*	It finds the first value that follows v. To iterate
		*	over all the values of a key use:
		*	<pre>
		*		for(value_pair v=h.findValue(k); v.first; v=h.findNextValue(k, v)) {
		*		    ...
		*		}
		*	</pre>
		*/
		
		value_pair findNextValue(const WString& k, const WString& v);
		
		/** 
		* Prints the key-value pairs represented by this
		* header.  Also prints the RFC required blank line
		* at the end. Omits pairs with a null key.
		*/
		
		void print(PrintStream& p);
		
		/** 
		* Adds a key value pair to the end of the
		* header.  Duplicates are allowed 
		*/
		
		void add(const WString& k, const WString& v);
		
		/** 
		* Prepends a key value pair to the beginning of the
		* header.  Duplicates are allowed 
		*/
		
		void prepend(const WString& k, const WString& v);
		
		
		/** 
		* Overwrite the previous key/val pair at location 'i'
		* with the new k/v.  If the index didn't exist before
		* the key/val is simply tacked onto the end.
		*/
		
		void set(int i, const WString& k, const WString& v);
		
		/** 
		* Sets the value of a key.  If the key already
		* exists in the header, it's value will be
		* changed.  Otherwise a new key/value pair will
		* be added to the end of the header. 
		*/
		
		void set(const WString& k, const WString& v);
		
		/** 
		* Set's the value of a key only if there is no key with that value already.
		*/
		
		void setIfNotSet(const WString& k, const WString& v);
		
		/** 
		* Convert a message-id string to canonical form (strips off leading and trailing s) 
		*/
		
		static WString canonicalID(const WString& id);
		
		/** 
		* Parse a MIME header from an input stream. 
		*/
		
		void parseHeader(InputStream& is);
		
		/** 
		* Parse and merge a MIME header from an input stream. 
		*/
		
		void mergeHeader(InputStream& is);
		
		/**
		* Empty message header
		*/
		void clear();
		
private:
	
    void grow();
	
#   pragma warning(disable: 4251)
	std::vector<WString> mKeys;
	std::vector<WString> mValues;
#   pragma warning(default: 4251)
};

/******************************************************************************
*	Prototypes
******************************************************************************/ 


/******************************************************************************
*	Implementation
******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_MESSAGEHEADER_H */
