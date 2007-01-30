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

#include "File.h"

#include "FileSystem.h"
#include "FileFilter.h"
#include "FileNameFilter.h"

#include <jdf/lang/Exception.h>
#include "jdf/net/URL.h"
#include "jdf/net/URI.h"
#include "jdf/net/URLEncoder.h"
#include <jdf/lang/Exception.h>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLUniDefs.hpp>
#include <string>

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

	FileSystem* File::fs = NULL;

	const WString File::pathSeparator()
	{
		return WString(1,fs->getSeparator());
	}

	const JDFCh File::pathSeparatorChar()
	{
		return fs->getPathSeparator();
	}

	const WString File::separator()
	{
		return WString(1,fs->getSeparator());
	}

	const JDFCh File::separatorChar()
	{
		return fs->getSeparator();
	}

	void File::initFile(FileSystem* filesystem)
	{
		fs = filesystem;
	}

	void File::terminate()
	{
		if (fs != NULL){
			delete fs;
			fs=0;
		}

	}


	File::File(const WString& s)
	{
		path         = fs->normalize(s);
		prefixLength = fs->prefixLength(path);
	}

	File::File(const WString& parent, const WString& child)
	{
		if(parent == "")
			path = fs->resolve(fs->getDefaultParent(), fs->normalize(child));
		else
			path = fs->resolve(fs->normalize(parent), fs->normalize(child));

		prefixLength = fs->prefixLength(path);
	}

	File::File(const File& parent, const WString& s)
	{
		if(parent.path == "")
			path = fs->resolve(fs->getDefaultParent(), fs->normalize(s));
		else
			path = fs->resolve(parent.path, fs->normalize(s));

		prefixLength = fs->prefixLength(path);
	}

	File::File(const WString& s, int i)
	{
		path = s;
		prefixLength = i;
	}

	File::File(const File& f)
	{
		path = f.path;
		prefixLength = f.prefixLength;
	}

	File& File::operator=(const File& f)
	{
		path = f.path;
		prefixLength = f.prefixLength;
		return *this;
	}

	File::File(const URL& url) 
	{
		URI uri = url.toURI();
		WString p = uri.getPath();
		p = fs->fromURIPath(uri.getHost(),p);
		if (separatorChar() != chForwardSlash)
			p.replaceChar(chForwardSlash,File::separatorChar());
		path = fs->normalize(p);
		prefixLength = fs->prefixLength(path);

	}

	File::File(const URI& uri)
	{
		// todo validation
		WString p = uri.getPath();
		p = fs->fromURIPath(uri.getHost(),p);
		if (separatorChar() != chForwardSlash)
			p.replaceChar(chForwardSlash,File::separatorChar());
		path = fs->normalize(p);
		prefixLength = fs->prefixLength(path);

	}


	File::~File()
	{
	}

	bool File::canRead()
	{
		return fs->checkAccess(*this, false);
	}

	bool File::canWrite()
	{
		return fs->checkAccess(*this, true);
	}

	int File::compareTo(const File& file)
	{
		return fs->compare(*this,file);
	}

	bool File::createNewFile()
	{
		return fs->createFileExclusively(path);
	}

	File File::createTempFile(File directory, WString prefix, WString suffix)
	{
		// PRE  prefix is at least 3 characters long

		int prefix_length = prefix.length();
		int suffix_length = suffix.length();

		if (prefix_length < 3) 
			throw IllegalArgumentException("Prefix string too short");

		// dont use MAX_PATH
		int max = 255-5; //  prefix + 5 internal characters 

		// what's the space for the random generated name

		int lengthsuffix = suffix_length;

		// make sure we can keep the suffix 

		if (lengthsuffix >= 4)
		{
			if (suffix[0] == '.') 
				lengthsuffix = 4; // keep first four characters of suffix;
			else
				lengthsuffix = 3;
		}

		// if longer than max skip character from prefix and suffix
		if ((prefix_length + suffix_length) > max)
		{

			int diff = (prefix_length + suffix_length) - max;

			while (diff)
			{
				if (prefix_length > 3) 
				{
					prefix_length--;
					diff--;
				}
				if (diff)
				{
					if (suffix_length > lengthsuffix)
					{
						suffix_length--;
						diff--;
					}
				}
			}
			prefix = prefix.substr(0,prefix_length);
			suffix = suffix.substr(0,suffix_length);
		}

		File f;
		WString buffer;
		JDFUInt32 millis = XMLPlatformUtils::getCurrentMillis();
		do 
		{
			buffer = WString::valueOf(millis);
			f = File(directory,prefix+buffer+suffix);
			millis++;
		} while (f.exists() == true);

		// create the temporary file

		f.createNewFile();

		return f;
	}

	File File::createTempFile(WString prefix,WString suffix)
	{
		return createTempFile(fs->tempFilePath(), prefix, suffix);
	}

	File File::createAliasTo(File directory)
	{
		return fs->createAliasFile(directory,*this);
	}

	File File::resolveAliasFile()
	{
		if (isAlias() == false)
			throw IOException("this file is not an alias");

		return fs->resolveAliasFile(*this);
	}

	bool File::operator==(const File& f)
	{
		return (compareTo(f) != 0);
	}

	bool File::remove()
	{
		if (isFile())
			return fs->deleteFile(*this);
		else if (isDirectory())
			return fs->deleteDirectory(*this);

		return false;
	}

	bool File::exists()
	{
		return fs->exists(*this);
	}

	File File::getAbsoluteFile()
	{
		return File(getAbsolutePath());
	}

	WString File::getAbsolutePath()
		const 
	{
		return fs->resolve(*this);

	}

	File File::getCanonicalFile()
	{
		return File(getCanonicalPath());
	}

	WString File::getCanonicalPath()
	{
		return fs->canonicalize(fs->resolve(*this));
	}

	WString File::getName()
		const
	{
		int i = path.find_last_of(separatorChar());
		if(i < prefixLength || static_cast<unsigned int>(i) == std::string::npos)
			return path.substr(prefixLength);
		else
			return path.substr(i + 1);
	}

	WString File::getParent()const
	{
		WString absPath = getAbsolutePath();

		int i = absPath.find_last_of(separatorChar());

		if(i < prefixLength)
		{
			if(prefixLength > 0 && static_cast<int>(absPath.length()) > prefixLength)
				return absPath.substr(0, prefixLength);
			else
				return "";
		}
		else
		{
			return absPath.substr(0, i);
		}
	}

	File File::getParentFile()const
	{
		WString s = getParent();
		if(s == "")
			return File("");
		else
			return File(s, prefixLength);
	}

	WString File::getPath() const
	{
		return path;
	}

	int File::getPrefixLength() const
	{
		return prefixLength;
	}

	bool File::isAbsolute()
	{
		return fs->isAbsolute(*this);
	}

	bool File::isDirectory()
	{
		return ((fs->getBooleanAttributes(*this) & FileSystem::BA_DIRECTORY) != 0);
	}


	bool File::isFile()
	{
		return ((fs->getBooleanAttributes(*this) & FileSystem::BA_REGULAR) != 0);
	}

	bool File::isHidden()
	{
		return ((fs->getBooleanAttributes(*this) & FileSystem::BA_HIDDEN) != 0);
	}

	bool File::isUNC() const
	{
		if (path.length() >= 2)
		{
			if (path[0] == chBackSlash && path[1] == chBackSlash)
				return true;
		}
		return false;
	}

	bool File::isAlias()
	{
		return fs->checkAliasFile(*this);
	}

	//bool File::isVolume()
	//{

	//}

	JDFUInt64 File::lastModified()
	{
		return fs->getLastModifiedTime(*this);
	}

	JDFUInt64 File::length()
	{
		return (fs->getLength(*this));
	}

	std::list<WString> File::list()
	{
		return fs->list(*this);
	}

	std::list<WString> File::list(FileNameFilter& filenamefilter)
	{
		std::list<WString> as = list();
		std::list<WString> filteredList;

		std::list<WString>::iterator it;

		for (it = as.begin(); it != as.end(); it++)
		{
			if (filenamefilter.accept(*this, *it))
			{
				filteredList.push_back(*it);
			}
		}
		return filteredList;
	}

	std::list<File> File::listFiles()
	{
		std::list<WString> as = list();
		std::list<File> fileList;

		std::list<WString>::iterator it;

		for (it = as.begin(); it != as.end(); it++)
		{
			fileList.push_back(File(path,*it));
		}
		return fileList;
	}

	std::list<File> File::listFiles(FileNameFilter& filenamefilter)
	{
		std::list<WString> as = list();
		std::list<File> fileList;

		std::list<WString>::iterator it;

		for (it = as.begin(); it != as.end(); it++)
		{
			if (filenamefilter.accept(*this, *it))
			{
				fileList.push_back(File(path,*it));
			}
		}
		return fileList;
	}

	std::list<File> File::listFiles(FileFilter& filter)
	{
		std::list<WString> as = list();
		std::list<File> fileList;

		std::list<WString>::iterator it;

		for (it = as.begin(); it != as.end(); it++)
		{
			File file(path,*it);
			if (filter.accept(file))
			{
				fileList.push_back(file);
			}
		}
		return fileList;
	}

	std::list<File> File::listRoots()
	{
		return fs->listRoots();
	}

	bool File::mkdir()
	{
		return fs->createDirectory(*this);
	}

	bool File::mkdirs()
	{
		if (exists())
			return false;

		if (mkdir()){
			return true;
		}
		else
		{
			WString s = getParent();
			return s != L"" && (File(s)).mkdirs() && mkdir();
		}
	}

	bool File::renameTo(File file)
	{
		return fs->rename(*this, file);
	}

	bool File::copyTo(File dest)
	{
		return fs->copyTo(*this, dest);
	}

	bool File::moveTo(File dest)
	{
		return fs->moveTo(*this, dest);
	}

	bool File::setLastModified(JDFUInt64 l)
	{
		return fs->setLastModifiedTime(*this, l);
	}

	bool File::setReadOnly()
	{
		return fs->setReadOnly(*this);
	}

	bool File::makeWritable()
	{
		return fs->makeWritable(*this);
	}

	WString File::toString() const
	{
		return getPath(); 
	}

	JDFUInt64 File::created()
	{
		return fs->getCreationTime(*this);
	}

	JDFUInt64 File::lastAccessed()
	{
		return fs->getLastAccessedTime(*this);
	}

	File File::getTempDirectory()
	{
		return fs->tempFilePath();
	}

	bool File::isRoot()
	{
		return fs->isRoot(*this);
	}

	File File::getRootFile()
	{
		if (path.length() > 2 && path[0] == chForwardSlash && path[1] == chForwardSlash)
		{
			WString pathSep(chForwardSlash);
			if (static_cast<int>(path.find("\\", path.find(pathSep, 2) + 1)) != WString::npos)
			{
				WString root = path.substr(0, path.find(pathSep, path.find(pathSep, 2) + 1)) + pathSep;
				return File(root);
			}
			else
				return File(path);
		}
		else
		{
			File tmp(WString(path.c_str(),prefixLength));
			if (tmp.isRoot())
				return tmp;
			else
				return File("");
		}
	}

	WString File::getRoot()
	{
		return getRootFile().toString();
	}

	WString File::slashify(WString p, bool isDirectory) 
	{
		if (File::separatorChar() != chForwardSlash)
			p = p.replaceChar(File::separatorChar(), chForwardSlash);
		//	if (!p.startsWith(chForwardSlash))
		p = chForwardSlash + p;
		if (!p.endsWith(chForwardSlash) && isDirectory)
			p = p + chForwardSlash;
		return p;
	}

	URI File::toURI()
	{
		//	WString s = slashify(getPath(),isDirectory());
		WString p = getPath();
		bool addprefix = false;
		// Windows fix
		if (p.length() >= 2) 
		{
			if (p.at(1) == chColon) 
				addprefix = true;

		}
		WString s = URLEncoder::encodePath(p);
		if (!isAbsolute())
		{
			return URI(s);
		}
		if (addprefix)
			s = JDFStrL("/") + s;

		if (!s.startsWith(JDFStrL("//")))
			s = JDFStrL("//") + s;

		s = JDFStrL("file:") + s;

		if (!s.endsWith(chForwardSlash) && isDirectory())
			s = s + chForwardSlash;

		// done

		return URI(s);
	}

	URL File::toURL()
	{
		//	WString s = slashify(getPath(),isDirectory());
		WString p = getPath();
		bool addprefix = false;
		// Windows fix
		if (p.length() >= 2) 
		{
			if (p.at(1) == chColon) 
				addprefix = true;

		}
		WString s = URLEncoder::encodePath(p);
		if (!isAbsolute())
		{
			return URL(s);
		}
		if (addprefix)
			s = JDFStrL("/") + s;

		if (!s.startsWith(JDFStrL("//")))
			s = JDFStrL("//") + s;

		s = JDFStrL("file:") + s;

		if (!s.endsWith(chForwardSlash) && isDirectory())
			s = s + chForwardSlash;

		// done
		return URL(s);

	}


} // namespace JDF


/* end of file */
