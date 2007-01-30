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

// 020405 RP made all appropriate File& references const
// 050628 RP added exists


/*******************************************************************************
* 
* Description:
*
*
******************************************************************************/

#ifndef I_JDF_FILESYSTEM_H
#define I_JDF_FILESYSTEM_H

/******************************************************************************
*	Includes
******************************************************************************/ 

#include <jdf/lang/JDFToolsDefs.h>

#include <list>


namespace JDF
{

	/******************************************************************************
	*	Forward declarations
	******************************************************************************/ 
	class WString;
	class File;

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
	* @ingroup io
	*/
	class JDFTOOLS_EXPORT FileSystem
	{
	public:

		virtual ~FileSystem() {}
		virtual WString canonicalize(const WString& s) = 0; // throw IOException

		virtual bool checkAccess(const File& file, bool flag) = 0;
		virtual int  compare(const File& f1, const File& f2) = 0;
		virtual bool createDirectory(const File& file) = 0;
		virtual bool createFileExclusively(WString s) = 0; //throw IOException
		virtual bool deleteFile(const File& file) = 0;
		virtual bool deleteDirectory(const File& file) = 0;
		virtual bool deleteOnExit(const File& file) = 0;
		virtual File tempFilePath() = 0;
		virtual File createAliasFile(const File& path, const File& file) = 0;
		virtual File resolveAliasFile(const File& file) = 0;
		virtual JDFUInt32  getBooleanAttributes(const File& file) = 0;
		virtual bool checkAliasFile(const File& file) = 0;
		virtual WString getDefaultParent() = 0;

		// singleton instance
		static FileSystem* getFileSystem();

		virtual JDFUInt64   getLastModifiedTime(const File& file) = 0;
		virtual JDFUInt64   getCreationTime(const File& file) = 0;
		virtual JDFUInt64   getLastAccessedTime(const File& file) = 0;
		virtual JDFUInt64   getLength(const File& file) = 0;
		virtual JDFCh     getPathSeparator() = 0;
		virtual JDFCh     getSeparator() = 0;
		//	virtual int	    hashCode(const File& file) = 0;
		virtual bool     isAbsolute(const File& file) = 0;
		virtual std::list<WString> list(const File& file) = 0;
		virtual std::list<File>   listRoots() = 0;
		virtual WString	normalize(const WString& s) = 0;
		virtual int prefixLength(const WString& s) = 0 ;
		virtual bool  rename(File& src, File& target) = 0;
		virtual WString resolve(const File& file) = 0;
		virtual WString resolve(const WString& s1, const WString& s2) = 0;
		virtual WString fromURIPath(const WString& host,const WString& path) = 0;
		virtual bool setLastModifiedTime(const File& file, JDFUInt64 l) = 0;
		virtual bool setReadOnly(const File& file) = 0;
		virtual bool makeWritable(const File& file) = 0;
		virtual bool copyTo(const File& src, const File& dst) = 0;
		virtual bool moveTo(const File& src, const File& dst) = 0;
		virtual bool isRoot(const File& file) = 0;
		
		/**
		* checks whether the file specified in File exists
		* the default implementation opens the file so that it is recommended to overwrite
		* see Win32FileSystem for an example
		* @param File file the file to check for existance
		* @return bool true if file exists
		*/
		virtual bool exists(const File& file);


	public:

		static int BA_EXISTS ;
		static int BA_REGULAR;
		static int BA_DIRECTORY;
		static int BA_HIDDEN;
		static int BA_ALIAS;

	protected:

		int getPrefixLength(const File& f);

	};


	/******************************************************************************
	*	Prototypes
	******************************************************************************/ 


	/******************************************************************************
	*	Implementation
	******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_FILESYSTEM_H */


/* end of file */
