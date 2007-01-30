/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2006 The International Cooperation for the Integration of 
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

#ifndef I_JDF_PLATFORMUTILS_H
#define I_JDF_PLATFORMUTILS_H


/******************************************************************************
*	Includes
******************************************************************************/ 

#include <utility>

#include <jdf/lang/JDFToolsDefs.h>
#include <jdf/lang/WString.h>



namespace JDF
{

	/******************************************************************************
	*	Forward declarations
	******************************************************************************/ 
	class WString;
	class Mutex;
	class SocketFactoryService;
	class FileSystem;
	class InetAddressImpl;

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
	* Utilities that must be implemented in a platform-specific way.
	*
	* This class contains methods that must be implemented in a platform
	* specific manner. 
	* @ingroup util
	*/
	class JDFTOOLS_EXPORT PlatformUtils
	{
	public:
		typedef std::pair<bool,WString> value_pair;

		/**
		* Perform per-process JDF Toolkit initialization
		* also initializes xerces in case it is not yet initialized
		*
		* Initialization <b>must</b> be called first in any client code.
		* 
		* @since 050628 a reference counter counts the number of initializations
		*/
		static void Initialize();

		/** 
		* Perform per-process parser termination if the initialization reference counter is 0
		* 
		* Cleans up allocates resources
		* @since 050628 a reference counter counts the number of terminations
		*/
		static void Terminate();

		/**
		* Singleton mutex which is shared by different classes
		* This mutex can be used for looking access to a singleton.
		*/
		static Mutex& gSingletonMutex();

		static void reinitSingletonMutex();

		/**
		* The platform specific socket factory service
		*
		*/
		static SocketFactoryService* fgSocketFactoryService;

		/**
		* Interrupts the current thread by the specified time in milliseconds
		*/
		static void sleep(int millis);

		/** Gets the system time in milliseconds
		*
		* This must be implemented by the per-platform driver, which should
		* use local services to return the current value of a running
		* millisecond timer. Note that the value returned is only as accurate
		* as the millisecond time of the underyling host system.
		*
		* @return Returns the system time as an unsigned long
		*/
		static unsigned long getCurrentMillis();

		/**
		* defined here for now since missing in  Xerces transservice.
		*/

		static void lowerCase(JDFCh* const toLowerCase);

		/** 
		* Get the current file position
		*
		* This must be implemented by the per-platform driver, which should
		* use local file services to deterine the current position within
		* the passed file.
		*
		* Since the file API provided here only reads, if the host platform
		* supports separate read/write positions, only the read position is
		* of any interest, and hence should be the one returned.
		*
		* @param theFile The file handle
		*/
		static unsigned int curFilePos(JDFFileHandle theFile);

		/** Closes the file handle
		*
		* This must be implemented by the per-platform driver, which should
		* use local file services to close the passed file handle, and to
		* destroy the passed file handle and any allocated data or system
		* resources it contains.
		*
		* @param theFile The file handle to close
		*/
		static void closeFile(JDFFileHandle theFile);

		/** 
		* Returns the file size
		*
		* This must be implemented by the per-platform driver, which should
		* use local file services to determine the current size of the file
		* represented by the passed handle.
		*
		* @param theFile The file handle whose size you want
		*
		* @return Returns the size of the file in bytes
		*/
		static unsigned int fileSize(JDFFileHandle theFile);

		/** 
		* Opens the file
		*
		* This must be implemented by the per-platform driver, which should
		* use local file services to open passed file. If it fails, a
		* null handle pointer should be returned.
		*
		* @param fileName The string containing the name of the file
		*
		* @return The file handle of the opened file
		*/
		static JDFFileHandle openFile(const char* const fileName);

		/** Opens a named file
		*
		* This must be implemented by the per-platform driver, which should
		* use local file services to open the passed file. If it fails, a
		* null handle pointer should be returned.
		*
		* @param fileName The string containing the name of the file
		*
		* @return The file handle of the opened file
		*/
		static JDFFileHandle openFile(const WString& fileName);

		/** 
		* Creates a named file
		*
		* This must be implemented by the per-platform driver, which should
		* use local file services to create the passed file. If it fails, a
		* null handle pointer should be returned.
		*
		* @param fileName The string containing the name of the file
		*
		* @return The file handle of the created file
		*/

		static JDFFileHandle createFile(const WString& fileName);

		/** 
		* Creates the file
		*
		* This must be implemented by the per-platform driver, which should
		* use local file services to create passed file. If it fails, a
		* null handle pointer should be returned.
		*
		* @param fileName The string containing the name of the file
		*
		* @return The file handle of the created file
		*/
		static JDFFileHandle createFile(const char* const fileName);

		/** 
		* Seeks in an opened file
		*
		* This must be implemented by the per-platform driver, which should
		* use local file services to seek in the passed file. If it fails, a
		* null handle pointer should be returned.
		* @param theFile handle of the opened file
		* @param pos number of bytes to move
		* @param movemethod relative position to move from, 1 means relative 
		* from the beginning of the file;
		* 2 means relative from the end of the file 
		* and 3 is relative from the current file postion
		* @return The file handle of the created file
		*/
		static void seekFile(JDFFileHandle theFile, unsigned int pos, int movemethod);

		/** 
		* Opens the standard input as a file
		*
		* This must be implemented by the per-platform driver, which should
		* use local file services to open a handle to the standard input.
		* It should be a copy of the standard input handle, since it will
		* be closed later!
		*
		* @return The file handle of the standard input stream
		*/
		static JDFFileHandle openStdInHandle();

		/** 
		* Opens the standard output as a file
		*
		* This must be implemented by the per-platform driver, which should
		* use local file services to open a handle to the standard input.
		* It should be a copy of the standard output handle, since it will
		* be closed later!
		*
		* @return The file handle of the standard input stream
		*/

		static JDFFileHandle openStdOutHandle();


		/** 
		* Reads the file buffer
		*
		* This must be implemented by the per-platform driver, which should
		* use local file services to read up to 'toRead' bytes of data from
		* the passed file, and return those bytes in the 'toFill' buffer. It
		* is not an error not to read the requested number of bytes. When the
		* end of file is reached, zero should be returned.
		*
		* @param theFile The file handle to be read from.
		* @param toRead The maximum number of byte to read from the current
		* position
		* @param toFill The byte buffer to fill
		*
		* @return Returns the number of bytes read from the stream or file
		*/
		static unsigned int readFileBuffer
			(
			JDFFileHandle   theFile
			, const unsigned int    toRead
			,       JDFByte* const  toFill
			);

		static unsigned int writeFileBuffer(
			JDFFileHandle   theFile
			, const unsigned int    toWrite
			,		JDFByte* const  buffer
			);

		static void flushFile(JDFFileHandle theFile);

		/** Resets the file handle
		*
		* This must be implemented by the per-platform driver which will use
		* local file services to reset the file position to the start of the
		* the file.
		*
		* @param theFile The file handle that you want to reset
		*/
		static void resetFile(FileHandle theFile);

		/**
		* Gets the JDF system property indicated by the specified key.
		* @param key the name of the JDF system property
		* @return a value pair with first set to <code>true</code> and second set to the value
		* of the property if the key is found; if not found a value pair with the
		* first field set to <code>false</code> is returned
		*/
		static value_pair getProperty(const WString& key);

		/**
		* Gets the JDF system property indicated by the specified key.
		* @param key the name of the JDF system property
		* @param def a default value
		* @return a value pair with first set to <code>true</code> and second set to the value
		* of the property if the key is found; if not found a value pair with the
		* first field set to <code>true</code> and the second field is set to the 
		* default value.
		*/
		static value_pair getProperty(const WString& key, const WString& def);

		/**
		* Sets a JDF system property indicated by the specified key.
		* @param key the name of the JDF system property
		* @param value the value of the JDF system property
		*/
		static void setProperty(WString key, WString value);

		/** Utility to join two paths
		*
		* This must be implemented by the per-platform driver, and should
		* weave the relative path part together with the base part and return
		* a new path that represents this combination.
		*
		* If the relative part turns out to be fully qualified, it will be
		* returned as is. If it is not, then it will be woven onto the
		* passed base path, by removing one path component for each leading
		* "../" (or whatever is the equivalent in the local system) in the
		* relative path.
		*
		* @param basePath The string containing the base path
		* @param relativePath The string containing the relative path
		*
		* @return Returns a string containing the 'woven' path. It should
		* be dynamically allocated and becomes the responsibility of the
		* caller to delete.
		*/
		static WString weavePaths(const WString&  basePath
			, const WString&  relativePath);

		static WString createUID();


	private:

		static FileSystem* fs;

		static void SystemPropertiesInit();

		/** Does initialization for a particular platform
		*
		* Each per-platform driver must implement this to do any low level
		* system initialization required. It <b>cannot</b> use any 
		* utility services!
		*/
		static void platformInit();

		/** Does termination for a particular platform
		*
		* Each per-platform driver must implement this to do any low level
		* system resource cleanup required. It <b>cannot</b> use any XML
		* parser or utilities services!
		*/
		static void platformTerm();

		/** 
		* Creates a SocketFactory service
		*
		* Each per-platform driver must implement this method and return some
		* derivative of the SocketFactoryService class. This object serves as the
		* socket factory for this process. The object must be dynamically
		* allocated and the caller is responsible for cleaning it up.
		*
		* @return A dynamically allocated object of some class derived from
		*         the SocketFactoryService class.
		*/
		static SocketFactoryService* makeSocketFactoryService();


		/** Creates a InetAddressImpl
		*
		* Each per-platform driver must implement this method and return some
		* derivative of the InetAddressImpl class. This object serves as the
		* socket factory for this process. The object must be dynamically
		* allocated and the caller is responsible for cleaning it up.
		*
		* @return A dynamically allocated object of some class derived from
		*         the InetAddressImpl class.
		*/
		static InetAddressImpl* makeInetAddressImpl();

		/** Creates a FileSystem
		*
		* Each per-platform driver must implement this method and return some
		* derivative of the FileSystem class. This object serves as the
		* socket factory for this process. The object must be dynamically
		* allocated and the caller is responsible for cleaning it up.
		*
		* @return A dynamically allocated object of some class derived from
		*         the FileSystem class.
		*/
		static FileSystem* makeFileSystem();
	};

	/******************************************************************************
	*	Prototypes
	******************************************************************************/ 


	/******************************************************************************
	*	Implementation
	******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_PLATFORMUTILS_H */


