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

/*******************************************************************************
* 
* Description:
*
*
******************************************************************************/

#ifndef I_JDF_FILE_H
#define I_JDF_FILE_H

/******************************************************************************
*	Includes
******************************************************************************/ 

#include <jdf/lang/WString.h>

#include <list>


namespace JDF
{

	/******************************************************************************
	*	Forward declarations
	******************************************************************************/ 

	class FileNameFilter;
	class FileFilter;
	class FileSystem;
	class URL;
	class URI;
	class PlatformUtils;

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
	* An abstract representation of file and directory pathnames. 
	* <p>
	* User interfaces and operating systems use system-dependent <i>pathname strings</i> to 
	* name files and directories. This class presents an abstract, system-independent 
	* view of hierarchical pathnames. An <i>abstract pathname</i> has two components: 
	* <p>
	* <ol>
	* <li>An optional system-dependent <i>prefix string</i>, such as a disk-drive specifier, 
	* "/" for the UNIX root directory, or "\\" for a Win32 UNC pathname, and 
	* <li>A sequence of zero or more string <i>names</i>. 
	* </li></ol>
	* <p>
	* Each name in an abstract pathname except for the last denotes a directory;
	* the last name may denote either a directory or a file. The <i>empty</i> abstract pathname 
	* has no prefix and an empty name sequence. 
	* <p>
	* The conversion of a pathname string to or from an abstract pathname is inherently 
	* system-dependent. When an abstract pathname is converted into a pathname string,
	* each name is separated from the next by a single copy of the <i>default separator
	* character</i>. The default name-separator character is made available in the public 
	* static fields <code>separator</code> and
	* <code>separatorChar</code> of this class. When a pathname string is converted into 
	* an abstract pathname, the names within it may be separated by the default name-separator 
	* character or by any other name-separator character that is supported by the underlying
	* system. 
	* <p>
	* A pathname, whether abstract or in string form, may be either <i>absolute</i> or <i>relative</i>.
	* An absolute pathname is complete in that no other information is required in order 
	* to locate the file that it denotes. A relative pathname, in contrast, must be 
	* interpreted in terms of information taken from some other pathname. By default the
	* classes in the io package always resolve relative pathnames against 
	* the current user directory. This directory is typically the directory in which the
	* user application was invoked. 
	* <p>
	* The prefix concept is used to handle root directories on UNIX platforms, 
	* and drive specifiers, root directories and UNC pathnames on Win32 platforms,
	* as follows: 
	* <ul>
	* <li>For UNIX platforms, the prefix of an absolute pathname is always "/". Relative 
	* pathnames have no prefix. The abstract pathname denoting the root directory has the
	* prefix "/" and an empty name sequence. 
	* <li>For Win32 platforms, the prefix of a pathname that contains a drive specifier 
	* consists of the drive letter followed by ":" and possibly followed by "\" if the 
	* pathname is absolute. The prefix of a UNC pathname is "\\"; the hostname and 
	* the share name are the first two names in the name sequence. A relative pathname that
	* does not specify a drive has no prefix. 
	* </li></ul>
	*
	* Instances of the <code>File</code> class are immutable; that is, once created, 
	* the abstract pathname represented by a <code>File</code> object will never change. 
	*
	* @author nverbove     
	* @ingroup io
	* @nosubgrouping
	*/

	class JDFTOOLS_EXPORT File
	{

	public:

		/**
		* The system-dependent path-separator character, represented as a string for 
		* convenience. This string contains a single character, namely <code>pathSeparatorChar</code>.
		*/

		static const WString	pathSeparator();

		/**
		* The system-dependent path-separator character.
		* This field is initialized to contain the first character of the value of the 
		* system property <code>path.separator</code>. This character is used to separate filenames 
		* in a sequence of files given as a <i>path list</i>. On UNIX systems, this character 
		* is ':'; on Win32 systems it is ';'.
		*/

		static const JDFCh		pathSeparatorChar();

		/**
		* The system-dependent default name-separator character, represented as a string
		* for convenience. This string contains a single character, namely <code>separatorChar</code>.
		*/

		static const WString	separator();

		/**
		* The system-dependent default name-separator character. This field is initialized 
		* to contain the first character of the value of the system property file.separator.
		* On UNIX systems the value of this field is '/'; on Win32 systems it is '\'.
		*/

		static const JDFCh		separatorChar();

	public:

		/** 
		* @name Constructors
		*/
		/*@{*/

		/**
		* Creates a new <code>File</code> instance by converting the given pathname string into an
		* abstract pathname. If the given string is the empty string, then the result 
		* is the empty abstract pathname.
		* 
		* @param pathname A pathname string
		*/

		File(const WString& pathname=WString::emptyStr);

		/**
		* Creates a new File instance from a parent pathname string and a child pathname 
		* string. 
		* <p>
		* If parent is an empty string then the new <code>File</code> instance is created as 
		* if by invoking the single-argument <code>File</code> constructor on the given child pathname
		* string. 
		* <p>
		* Otherwise the parent pathname string is taken to denote a directory, and the child 
		* pathname string is taken to denote either a directory or a file. If the child 
		* pathname string is absolute then it is converted into a relative pathname in a 
		* system-dependent way. If parent is the empty string then the new <code>File</code> instance
		* is created by converting child into an abstract pathname and resolving the result
		* against a system-dependent default directory. Otherwise each pathname string is 
		* converted into an abstract pathname and the child abstract pathname is resolved
		* against the parent.
		* 
		* @param parent The parent pathname string
		* @param child The child pathname string
		*/

		File(const WString& parent, const WString& child);

		/**
		* Creates a new <code>File</code> instance from a parent abstract pathname and a child pathname 
		* string. 
		* If parent is an empty string then the new <code>File</code> instance is created as if by 
		* invoking the single-argument File constructor on the given child pathname string. 
		* <p>
		* Otherwise the parent abstract pathname is taken to denote a directory, and the 
		* child pathname string is taken to denote either a directory or a file. If the
		* child pathname string is absolute then it is converted into a relative pathname 
		* in a system-dependent way. If parent is the empty abstract pathname then the new 
		* <code>File</code> instance is created by converting child into an abstract 
		* pathname and resolving the result against a system-dependent default directory. 
		* Otherwise each pathname string is converted into an abstract pathname and the 
		* child abstract pathname is resolved against the parent.
		* 
		* @param parent The parent abstract pathname
		* @param child The child pathname string
		*/

		File(const File& parent, const WString& child);

		/**
		* Creates a new <tt>File</tt> instance by converting the given
		* <tt>file:</tt> URI into an abstract pathname.
		*
		* <p> The exact form of a <tt>file:</tt> URI is system-dependent, hence
		* the transformation performed by this constructor is also
		* system-dependent.
		*
		* <p> For a given abstract pathname <i>f</i> it is guaranteed that
		*
		* <blockquote><tt>
		* new File(</tt><i>&nbsp;f</i><tt>.{@link #toURI() toURI}()).equals(</tt><i>&nbsp;f</i><tt>)
		* </tt></blockquote>
		*
		* so long as the original abstract pathname, the URI, and the new abstract
		* pathname are all created in (possibly different invocations of) the same
		* Java virtual machine.  This relationship typically does not hold,
		* however, when a <tt>file:</tt> URI that is created in a virtual machine
		* on one operating system is converted into an abstract pathname in a
		* virtual machine on a different operating system.
		*
		* @param  uri
		*         An absolute, hierarchical URI with a scheme equal to
		*         <tt>"file"</tt>, a non-empty path component, and undefined
		*         authority, query, and fragment components
		*
		* @throws  NullPointerException
		*          If <tt>uri</tt> is <tt>null</tt>
		*
		* @throws  IllegalArgumentException
		*          If the preconditions on the parameter do not hold
		*
		* @see toURI()
		* @since 1.4
		*/
		File(const URI& url);
		File(const URL& url);

		/**
		* Creates a new File instance from an existing abstract pathname.
		* The new <code>File</code> instance makes a copy of the abstact pathname <code>file</code>.
		* 
		* @param file the File to copy the abstract pathname from.
		*/

		File(const File& file);

		/**
		* Makes a copy of an existing abstract pathname
		* The new <code>File</code> instance makes a copy of the abstact pathname <code>file</code>.
		* 
		* @param file the File to copy the abstract pathname from.
		*/

		File& operator=(const File& t);

		/*@}*/ 

		virtual ~File();

		/**
		* Returns the name of the file or directory denoted by this abstract pathname. 
		* This is just the last name in the pathname's name sequence. If the pathname's 
		* name sequence is empty, then the empty string is returned.
		* 
		* @return The name of the file or directory denoted by this abstract pathname, or the empty string if this pathname's name sequence is empty
		*/

		WString getName() const;

		/**
		* Returns the pathname string of this abstract pathname's parent, or an empty string 
		* if this pathname does not name a parent directory. 
		* <p>
		* The <i>parent</i> of an abstract pathname consists of the pathname's prefix, if any, and 
		* each name in the pathname's name sequence except for the last. If the name sequence 
		* is empty then the pathname does not name a parent directory.
		* 
		* @return The pathname string of the parent directory named by this abstract pathname, or an empty string if this pathname does not name a parent
		*/


		WString getParent()const;

		/**
		* Returns the the root file of this abstract pathname.
		* If the path does not denote a root then an empty file object is returned, for example
		* when this abstract path is not a relative file.
		*
		* @return The root file of this abstract pathname, or an empty file if this this pathname does not have a root.
		*/

		File getRootFile();

		/**
		* Returns the pathname string of this abstract pathname's root, or an empty string 
		* if this pathname does not name a root directory. 
		* 
		* @return The pathname string of the parent directory named by this abstract pathname, or an empty string if this pathname does not name a root
		*/

		WString getRoot();

		/**
		* Returns the abstract pathname of the default temporary-file directory
		* 
		* @return An abstract pathname denoting the default temporary file-directory.
		*/

		static File getTempDirectory();

		/**
		* Tests whether the file denoted by this abstract pathname is a root volume.
		* Whether a file is a root volume is system-dependent. On Windows NT a 
		* file is a root if the path is of the form <code>X:\</code>. The backslash is optional.
		*
		* @return <code>true</code> if and only if the file denoted by this abstract pathname is a root; <code>false</code> otherwise.
		*/

		bool isRoot();

		/**
		* Returns the abstract pathname of this abstract pathname's parent, or en empty File if this pathname does not name a parent.
		* The parent of an abstract pathname consists of the pathname's prefix, 
		* if any, and each name in the pathname's name sequence except for the last.
		* If the name sequence is empty then the pathname does not name a parent directory.
		*
		* @return The abstract pathname of the parent directory named by this abstract pathname, or an empty File if this pathname does not name a parent 
		*/

		File getParentFile()const;

		/**
		* Converts this abstract pathname into a pathname string. 
		* The resulting string uses the default name-separator character to 
		* separate the names in the name sequence.
		* 
		* @return The string form of this abstract pathname
		*/

		WString getPath() const;

		/**
		* Returns the absolute pathname string of this abstract pathname. 
		* If this abstract pathname is already absolute, then the pathname string is 
		* simply returned as if by the <code>getPath()</code> method. If this abstract pathname is 
		* the empty abstract pathname then the pathname string of the current user directory,
		* which is named by the system property user.dir, is returned. Otherwise this 
		* pathname is resolved in a system-dependent way. On UNIX systems, a relative 
		* pathname is made absolute by resolving it against the current user directory.
		* On Win32 systems, a relative pathname is made absolute by resolving it against 
		* the current directory of the drive named by the pathname, if any; if not, 
		* it is resolved against the current user directory.
		* 
		* @return The absolute pathname string denoting the same file or directory as this abstract pathname
		* @see File#isAbsolute()     
		*/

		WString getAbsolutePath() const;

		/**
		* Returns the absolute form of this abstract pathname.
		* Equivalent to new <code>File(this.getAbsolutePath()())</code>.
		* 
		* @return The absolute abstract pathname denoting the same file or directory as this abstract pathname 
		*/

		File	getAbsoluteFile();

		/**
		* Returns the time that the file denoted by this abstract pathname was last modified.
		* 
		* @return A 64-bit long value representing the time the file was last modified, measured in milliseconds since the epoch (00:00:00 GMT, January 1, 1970), or 0L if the file does not exist or if an I/O error occurs.
		*/

		JDFUInt64 lastModified();

		/**
		* Returns the time that the file denoted by this abstract pathname was last accessed.
		* If the underlying file system does not support this time member, the last access time is zero. 
		* 
		* @return A 64-bit long value representing the time the file was last accessed, measured in milliseconds since the epoch (00:00:00 GMT, January 1, 1970), or 0L if the file does not exist, the underlying file system does not support last access time or if an I/O error occurs.
		*/

		JDFUInt64 lastAccessed();

		/**
		* Returns the time that the file denoted by this abstract pathname was created.
		* 
		* @return A 64-bit long value representing the time the file was created, measured in milliseconds since the epoch (00:00:00 GMT, January 1, 1970), or 0L if the file does not exist or if an I/O error occurs.
		*/

		JDFUInt64 created();

		/**
		* Returns the length of the file denoted by this abstract pathname.
		* 
		* @return The length, in bytes, of the file denoted by this abstract pathname, or 0L if the file does not exist.
		*/

		JDFUInt64 length();

		/**
		* Tests whether the file denoted by this abstract pathname exists.
		* @since 050628 returns true if the file exists but is not read accessible
		*	the prior version only reported readable files as existing
		*
		* @return <code>true</code> if and only if the file denoted by this abstract pathname exists; <code>false</code> otherwise
		*/
		bool exists();

		/**
		* Tests whether the application can read the file denoted by this abstract pathname.
		* 
		* @return <code>true</code> if and only if the file specified by this abstract pathname exists and can be read by the application; <code>false</code> otherwise
		*/
		bool canRead();

		/**
		* Tests whether the application can modify to the file denoted by this abstract pathname.
		* 
		* @return <code>true</code> if and only if the file system actually contains a file denoted by this abstract pathname and the application is allowed to write to the file; <code>false</code> otherwise.
		*/
		bool canWrite();

		/**
		* Tests whether this abstract pathname is absolute. 
		* The definition of absolute pathname is system dependent. 
		* On UNIX systems, a pathname is absolute if its prefix is "/". 
		* On Win32 systems, a pathname is absolute if its prefix is a drive specifier
		* followed by "\\", or if its prefix is "\\".
		* 
		* @return <code>true</code> if this abstract pathname is absolute, <code>false</code> otherwise
		*/

		bool isAbsolute();

		/**
		* Tests whether the file denoted by this abstract pathname is a directory.
		* 
		* @return <code>true</code> if and only if the file denoted by this abstract pathname exists and is a directory; <code>false</code> otherwise
		*/

		bool isDirectory();

		/**
		* Tests whether the file denoted by this abstract pathname is a normal file.
		* A file is normal if it is not a directory and, in addition, satisfies 
		* other system-dependent criteria. 
		* 
		* @return <code>true</code> if and only if the file denoted by this abstract pathname exists and is a normal file; <code>false</code> otherwise
		*/

		bool isFile();

		/**
		* Tests whether the file denoted by this abstract pathname is an alias to another file or directory..
		* 
		* @return <code>true</code> if and only if the file denoted by this abstract pathname exists and is an alias file; <code>false</code> otherwise
		*/

		bool isAlias();

		/**
		* Tests whether the file named by this abstract pathname is a hidden file. 
		* The exact definition of hidden is system-dependent. On UNIX systems,
		* a file is considered to be hidden if its name begins with a period character ('.').
		* On Win32 systems, a file is considered to be hidden if it has been marked as 
		* such in the filesystem.
		*
		* @return <code>true</code> if and only if the file denoted by this abstract pathname is hidden according to the conventions of the underlying platform.
		*/

		bool isHidden();

		/**
		* Tests whether this abstract pathname is considered to be in the UNC form.
		* 
		* @return <code>true</code> if this path is UNC
		*/

		bool isUNC() const;


		/**
		* Returns the pathname string of this abstract pathname. 
		* This is just the string returned by the <code>getPath()</code> method.
		* 
		* @return The string form of this abstract pathname
		*/

		WString toString() const;

		/**
		* Sets the last-modified time of the file or directory named by this abstract pathname. 
		* <p>
		* All platforms support file-modification times to the nearest second, but some provide more precision. 
		* The argument will be truncated to fit the supported precision. If the operation succeeds and no 
		* intervening operations on the file take place, then the next invocation of the lastModified() method 
		* will return the (possibly truncated) time argument that was passed to this method.
		* 
		* @return <code>true</code> if successful, <code>false</code> otherwise. 
		* @param time The new last-modified time, measured in milliseconds since the epoch (00:00:00 GMT, January 1, 1970)
		*/

		bool setLastModified(JDFUInt64 time);

		/**
		* Marks the file or directory named by this abstract pathname so that only read operations are allowed. 
		* After invoking this method the file or directory is guaranteed not to change 
		* until it is either deleted or marked to allow write access. 
		* Whether or not a read-only file or directory may be deleted depends upon the underlying system.
		* 
		* @return <code>true</code> if successful, <code>false</code> otherwise. 
		*/

		bool setReadOnly();

		/**
		* Marks the file or directory named by this abstract pathname so that write operations are allowed. 
		* After invoking this method changes to the file or directory or allowed
		* until it is either deleted or marked to allow only read access. 
		* 
		* @return <code>true</code> if successful, <code>false</code> otherwise. 
		*/

		bool makeWritable();

		/**
		* Creates the directory named by this abstract pathname.
		* 
		* @return <code>true</code> if and only if the directory was created; <code>false</code> otherwise.
		*/

		bool mkdir();

		/**
		* Creates the directory named by this abstract pathname, including any necessary but nonexistent parent directories.
		* Note that if this operation fails it may have succeeded in creating some of 
		* the necessary parent directories.
		* 
		* @return <code>true</code> if and only if the directory was created, along with all necessary parent directories; <code>false</code> otherwise
		*/

		bool mkdirs();

		/**
		* Deletes the file or directory denoted by this abstract pathname. 
		* If this pathname denotes a directory, then the directory must be empty in order
		* to be deleted.
		* 
		* @return <code>true</code> if and only if the file or directory is successfully deleted; <code>false</code> otherwise
		*/

		bool remove();

		/**
		* Renames the file denoted by this abstract pathname.
		* The destination file has to be in the same parent directory.
		* 
		* @return <code>true</code> if and only if the renaming succeeded; <code>false</code> otherwise
		* @param  dest The new abstract pathname for the named file.
		*/

		bool renameTo(File dest);

		/**
		* Copies the file denoted by this abstract pathname.
		*
		* @return <code>true</code>  if and only if the copying succeeded; <code>false</code> otherwise
		* @param dest The abstract pathname where this file is to be copied to
		*/

		bool copyTo(File dest);

		/** 
		* Moves the file denoted by this abstract pathname
		*
		* @return <code>true</code> if and only if the moving succeeded; <code>false</code> otherwise
		* @param dest The abstract pathname where this file is to be copied to
		*/

		bool moveTo(File dest);

		/**
		* Returns an array of strings naming the files and directories in the directory denoted by this abstract pathname. 
		* <p>
		* If this abstract pathname does not denote a directory, then this method returns an empty list. 
		* Otherwise an array of strings is returned, one for each file or directory in the 
		* directory. Names denoting the directory itself and the directory's parent directory
		* are not included in the result. Each string is a file name rather than a complete
		* path. 
		* <p>
		* There is no guarantee that the name strings in the resulting array will appear in
		* any specific order; they are not, in particular, guaranteed to appear in
		* alphabetical order.
		* 
		* @return An array of strings naming the files and directories in the directory denoted by this abstract pathname. The array will be empty if the directory is empty. Returns null if this abstract pathname does not denote a directory, or if an I/O error occurs.
		*/

		std::list<WString> list();

		/**
		* Returns an array of strings naming the files and directories in the directory 
		* denoted by this abstract pathname that satisfy the specified filter. 
		* The behavior of this method is the same as that of the <code>list()</code> method,
		* except that the strings in the returned array must satisfy the filter. 
		* A name satisfies the filter if and only if the value <code>true</code> results
		* when the <code>FilenameFilter.accept(JDF::File, WString)</code> method 
		* of the filter is invoked on this abstract pathname and the name of a file or 
		* directory in the directory that it denotes.
		* 
		* @return An array of strings naming the files and directories in the directory denoted by this abstract pathname that were accepted by the given filter. The array will be empty if the directory is empty or if no names were accepted by the filter. Returns an empty list if this abstract pathname does not denote a directory, or if an I/O error occurs.
		* @param filter A filename filter
		*/

		std::list<WString> list(FileNameFilter& filter);

		/**
		* Returns an array of abstract pathnames denoting the files in the directory denoted
		* by this abstract pathname. 
		* If this abstract pathname does not denote a directory, then this method returns 
		* an empty list. 
		* Otherwise an array of <code>File</code> objects is returned, one for each file 
		* or directory in the directory. Pathnames denoting the directory itself and the 
		* directory's parent directory are not included in the result. Each resulting 
		* abstract pathname is constructed from this abstract pathname using the 
		* <code>File(File, string)</code> constructor. Therefore if this pathname is 
		* absolute then each resulting pathname is absolute; if this pathname is 
		* relative then each resulting pathname will be relative to the same directory. 
		* <p>
		* There is no guarantee that the name strings in the resulting array will appear 
		* in any specific order; they are not, in particular, guaranteed to appear 
		* in alphabetical order.
		* 
		* @return An array of abstract pathnames denoting the files and directories in the directory denoted by this abstract pathname. The array will be empty if the directory is empty. Returns an empty if this abstract pathname does not denote a directory, or if an I/O error occurs.
		*/

		std::list<File>	listFiles();

		/**
		* Returns an array of abstract pathnames denoting the files and directories 
		* in the directory denoted by this abstract pathname that satisfy the specified
		* filter. The behavior of this method is the same as that of the <code>listFiles()</code> method,
		* except that the pathnames in the returned array must satisfy the filter. 
		* A pathname satisfies the filter if and only if the value <code>true</code> results when 
		* the <code>FileFilter.accept(File)</code> method of the filter is invoked on the pathname.
		* 
		* @return An array of abstract pathnames denoting the files and directories in the directory denoted by this abstract pathname. The array will be empty if the directory is empty. Returns an empty list if this abstract pathname does not denote a directory, or if an I/O error occurs.
		* @param filter A File filter
		*/

		std::list<File> listFiles(FileFilter& filter);

		/**
		* Returns an array of abstract pathnames denoting the files and directories in 
		* the directory denoted by this abstract pathname that satisfy the specified filter.
		* The behavior of this method is the same as that of the <code>listFiles()</code> 
		* method, except that the pathnames in the returned array must satisfy the filter. 
		* A pathname satisfies the filter if and only if the value <code>true</code> 
		* results when the <code>FilenameFilter.accept(File, std::string)</code> method 
		* of the filter is invoked on this abstract pathname and the name of a file or 
		* directory in the directory that it denotes.
		*
		* @param filter A filename filter
		* @return An array of abstract pathnames denoting the files and directories in the directory denoted by this abstract pathname. The array will be empty if the directory is empty. Returns an empty list if this abstract pathname does not denote a directory, or if an I/O error occurs.
		*/

		std::list<File> listFiles(FileNameFilter& filter);

		/**
		* Creates an empty file in the default temporary-file directory, using the given prefix and suffix to generate its name. 
		* <p>
		* This method has the same effect as calling <code>createTempFile(prefix,suffix,dir)</code> with the system default directory.
		* The default temporary-file directory is specified by the system property io.tmpdir. On UNIX systems the default value 
		* of this property is typically <code>"/tmp"</code> or <code>"/var/tmp"</code>; on Win32 systems
		* it is typically <code>"c:\\temp"</code>.
		* 
		* @return An abstract pathname denoting a newly-created empty file
		* @param prefix The prefix string to be used in generating the file's name; must be at least three characters long.
		* @param suffix string to be used in generating the file's name; the suffix ".tmp" will be used by default.
		* @exception IllegalArgumentException If the prefix argument contains fewer than three characters
		* @exception IOException If a file could not be created
		*/

		static File createTempFile(WString prefix, WString suffix = ".tmp");


		/**
		* Creates a new empty file in the specified directory, using the given prefix 
		* and suffix strings to generate its name. If this method returns successfully
		* then it is guaranteed that: 
		* <ol>
		* <li> The file denoted by the returned abstract pathname did not exist before 
		* this method was invoked, and 
		* <li> Neither this method nor any of its variants will return the same abstract 
		* pathname again in the current invocation of the virtual machine. 
		* </li></ol>
		* This method provides only part of a temporary-file facility. 
		* To arrange for a file created by this method to be deleted automatically, 
		* use the <code>deleteOnExit()</code> method. 
		* <p>
		* The <code>prefix</code> argument must be at least three characters long. 
		* It is recommended that the prefix be a short, meaningful string such as 
		* <code>"hjb"</code> or <code>"mail"</code>. The suffix argument may be omitted, 
		* in which case the suffix <code>".tmp"</code> will be used. 
		* <p>	
		* To create the new file, the prefix and the suffix may first be adjusted to fit 
		* the limitations of the underlying platform. If the prefix is too long then it
		* will be truncated, but its first three characters will always be preserved. 
		* If the suffix is too long then it too will be truncated, but if it begins with a
		* period character ('.') then the period and the first three characters following
		* it will always be preserved. Once these adjustments have been made the name of 
		* the new file will be generated by concatenating the prefix, five or more 
		* internally-generated characters, and the suffix. 
		* 
		* @return An abstract pathname denoting a newly-created empty file.
		* @param directory The directory in which the file is to be created.
		* @param prefix The prefix string to be used in generating the file's name; must be at least three characters long.
		* @param suffix The suffix string to be used in generating the file's name; may be omitted, in which case the suffix ".tmp" will be used
		* @exception IllegalArgumentException If the prefix argument contains fewer than three characters
		* @exception IOException If a file could not be created
		*/

		static File createTempFile(File directory, WString prefix, WString suffix = ".tmp");

		bool createNewFile();
		/**
		* List the available filesystem roots. 
		* <p>
		* A particular platform may support zero or more hierarchically-organized file 
		* systems. Each file system has a root directory from which all other files in that
		* file system can be reached. Windows platforms, for example, have a root directory 
		* for each active drive; UNIX platforms have a single root directory, namely "/". 
		* The set of available filesystem roots is affected by various system-level operations
		* such the insertion or ejection of removable media and the disconnecting or
		* unmounting of physical or virtual disk drives. 
		* <p>
		* This method returns an array of <code>File</code> objects that denote the root directories of 
		* the available filesystem roots. It is guaranteed that the canonical pathname of
		* any file physically present on the local machine will begin with one of the roots 
		* returned by this method. 
		* <p> 
		* The canonical pathname of a file that resides on some other machine and is accessed
		* via a remote-filesystem protocol such as SMB or NFS may or may not begin with one 
		* of the roots returned by this method. If the pathname of a remote file is 
		* syntactically indistinguishable from the pathname of a local file then it will 
		* begin with one of the roots returned by this method. Thus, for example, 
		* <code>File</code> objects denoting the <code>root</code> directories of the mapped network drives of
		* a Windows platform will be returned by this method, while <code>File</code> objects 
		* containing UNC pathnames will not be returned by this method. 
		* 
		* @return An array of <code>File</code> objects denoting the available filesystem roots, or an empty list if the set of roots could not be determined. The array will be empty if there are no filesystem roots.
		*/

		static std::list<File> listRoots();

		/**
		* Creates an alias to a given file in the specified directory.
		* <p>
		* If the directory does not exist or the alias could not be created an <code>IOException</code>
		* will be thrown. If there exists already an alias in the specified directory then this
		* method will succeed. 
		* <p>
		* The referenced file of the alias can always be retrieved with <code>resolveAliasFile</code>.
		* 
		* @return An abstract pathname denoting an alias to the file.
		* @param directory The directory in which the file is to be created.
		* @see File#resolveAliasFile()
		*/

		File createAliasTo(File directory);

		/**
		* Returns the abstract pathname of the real file referenced by this alias.
		* 
		* @return An abstract pathname denoting the real file referenced by this alias.
		*/

		File resolveAliasFile();

		/**
		* Returns the canonical pathname string of this abstract pathname. 
		* <p>
		* The precise definition of canonical form is system-dependent, but 
		* canonical forms are always absolute. Thus if this abstract pathname is relative
		* it will be converted to absolute form as if by the <code>getAbsoluteFile()</code> method. 
		* <p>	
		* Every pathname that denotes an existing file or directory has a unique 
		* canonical form. Every pathname that denotes a nonexistent file or directory 
		* also has a unique canonical form. The canonical form of the pathname of a
		* nonexistent file or directory may be different from the canonical form of the 
		* same pathname after the file or directory is created. Similarly, the canonical
		* form of the pathname of an existing file or directory may be different from
		* the canonical form of the same pathname after the file or directory is deleted.
		* 
		* @return The canonical pathname string denoting the same file or directory as this abstract pathname.
		* @exception IOException If an I/O error occurs, which is possible because the construction of the canonical pathname may require filesystem queries
		*/

		WString getCanonicalPath();

		/**
		* Returns the canonical form of this abstract pathname.
		* Equivalent to  <code>File(this.getCanonicalPath()())</code>.
		* 
		* @return The canonical pathname string denoting the same file or directory as this abstract pathname
		* @exception IOException If an I/O error occurs, which is possible because the construction of the canonical pathname may require filesystem queries
		*/

		File        getCanonicalFile();

		/**
		* Tests this abstract pathname for equality with the given object.
		* Returns <code>true</code> if and only if the argument is an abstract pathname that denotes 
		* the same file or directory as this abstract pathname. 
		* Whether or not two abstract pathnames are equal depends upon the 
		* underlying system. On UNIX systems, alphabetic case is significant in 
		* comparing pathnames; on Win32 systems it is not.
		* 
		* @return <code>true</code> if and only if the objects are the same; <code>false</code> otherwise
		* @param f The  abstract pathname to be compared with this abstract pathname
		*/

		bool operator==(const File& f);

		/**
		* Compares two abstract pathnames lexicographically.
		* <p>
		* The ordering defined by this method depends upon the underlying system. 
		* On UNIX systems, alphabetic case is significant in comparing pathnames; 
		* on Win32 systems it is not.
		* 
		* @return Zero if the argument is equal to this abstract pathname, a value less than zero 
		* if this abstract pathname is lexicographically less than the argument, 
		* or a value greater than zero if this abstract pathname is lexicographically
		* greater than the argument
		* @param  pathname - The abstract pathname to be compared to this abstract pathname
		* @see     
		*/

		int compareTo(const File& pathname);

		/**
		* Converts this abstract pathname into a file: URL. The exact form of 
		* the URL is system-dependent. If it can be determined that the file
		* denoted by this abstract pathname is a directory, then the resulting
		* URL will end with a slash.
		* This method will do the proper escaping of reserved URL characters in the file path.
		* @return a URL object representing the equivalent file URL
		*/

		URL toURL();

		/**
		* Converts this abstract pathname into a file: URI. The exact form of 
		* the URI is system-dependent. If it can be determined that the file
		* denoted by this abstract pathname is a directory, then the resulting
		* URI will end with a slash.
		* This method will do the proper escaping of reserved URI characters in the file path.
		* @return a URL object representing the equivalent file URI.
		*/

		URI toURI();


	protected:

		File(const WString& s, int i);

		int getPrefixLength() const;
		WString slashify(WString path, bool isDirectory);
	private:

		static void initFile(FileSystem* fs);
		static void terminate();

		WString path;
		int prefixLength;

		static FileSystem* fs;
		friend class FileSystem;
		friend class PlatformUtils;

	};


	/******************************************************************************
	*	Prototypes
	******************************************************************************/ 


	/******************************************************************************
	*	Implementation
	******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_FILE_H */


/* end of file */
