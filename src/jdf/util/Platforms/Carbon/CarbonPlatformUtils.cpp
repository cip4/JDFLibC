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

/******************************************************************************
 *  Includes
 ******************************************************************************/ 

#include <unistd.h>
#include <iostream.h>
#include <time.h>

#include <xercesc/util/XMLUniDefs.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/Platforms/MacOS/MacCarbonFile.hpp>
#include <xercesc/util/XMLString.hpp>

#include <jdf/util/PlatformUtils.h>
#include <jdf/util/Platforms/Carbon/JDFCarbonFile.h>
#include <jdf/lang/Janitor.h>
//John.Klippenstein@kodak.com - Exception.h has moved to a new location
#include <jdf/lang/Exception.h>
#include <jdf/io/File.h>
#include <jdf/io/Platforms/Carbon/CarbonFileSystem.h>
#include <jdf/net/Platforms/Carbon/CarbonSocketFactoryService.h>
#include <jdf/net/Platforms/Carbon/CarbonInetAddressImpl.h>



namespace JDF
{

/******************************************************************************
 *  Forward declarations
 ******************************************************************************/


/******************************************************************************
 *  Defines and constants
 ******************************************************************************/


/******************************************************************************
 *  Typedefs
 ******************************************************************************/


/******************************************************************************
 *  Classes
 ******************************************************************************/

/******************************************************************************
 *  Prototypes
 ******************************************************************************/


/******************************************************************************
 *  Implementation
 ******************************************************************************/


SocketFactoryService* PlatformUtils::makeSocketFactoryService()
{
    return new CarbonSocketFactoryService();
}


InetAddressImpl* PlatformUtils::makeInetAddressImpl()
{
    return new CarbonInetAddressImpl();
}


FileSystem* PlatformUtils::makeFileSystem()
{
    return new CarbonFileSystem();
}


void PlatformUtils::platformInit()
{
}


void PlatformUtils::platformTerm()
{
}


void PlatformUtils::SystemPropertiesInit()
{
    setProperty(JDFStrL("line.separator"),JDFStrL("\r\n"));

    {
        unsigned int endianTest = 0xff000000;
        if (((char*)(&endianTest))[0] != 0)
        {
            setProperty(JDFStrL("cpu.endianness"),JDFStrL("big"));
        } else
        {
            setProperty(JDFStrL("cpu.endianness"),JDFStrL("little"));
        }
    }

}


unsigned int PlatformUtils::curFilePos(JDFFileHandle theFile)
{
    try
    {
        return XMLPlatformUtils::curFilePos(theFile);
    }
    catch (XMLException&)
    {
        throw IOException("Failed to get current file position");
    }
}


void PlatformUtils::seekFile(JDFFileHandle theFile, unsigned int pos, int movemethod)
{
    unsigned int res = 0xFFFFFFFF;

    try
    {
        int whence = 0;

        switch (movemethod)
        {
            case 1  : whence = SEEK_SET; break;
            case 2  : whence = SEEK_CUR; break;
            case 3  : whence = SEEK_END; break;
            default : throw IOException("Illegal movemethod");
        }

        res = fseek(((XMLCarbonFile*) theFile)->getFileHandle(), pos, whence);
    }
    catch (XMLException&)
    {
    }

    if (res == 0xFFFFFFFF)
        throw IOException("Failed to set file position");
}


void PlatformUtils::closeFile(JDFFileHandle theFile)
{
    try
    {
        fclose(((XMLCarbonFile*) theFile)->getFileHandle());

    } catch (XMLException&)
    {
        throw IOException("Failed to open file");
    }
}

unsigned int PlatformUtils::fileSize(JDFFileHandle theFile)
{
    return XMLPlatformUtils::fileSize(theFile);
}


JDFFileHandle PlatformUtils::openFile(const char* const fileName)
{
    JDFFileHandle handle =  XMLPlatformUtils::openFile(fileName);

    return handle;
}


JDFFileHandle PlatformUtils::openFile(const WString& fileName)
{
    JDFFileHandle handle = XMLPlatformUtils::openFile(fileName.c_str());

    return handle;
}


JDFFileHandle PlatformUtils::createFile(const char* const fileName)
{
    FILE* t= fopen(fileName, "w+");

    if (t == 0)
    {
//        cout<<"Cannot create file"<<endl;
        return 0;
    }

    JDFFileHandle n= new JDFCarbonFile(t);

    return n;
}


JDFFileHandle PlatformUtils::createFile(const WString& fileName)
{
    JDF::File file(fileName);

    JDF::ArrayJanitor<const char> path(file.getAbsolutePath().getBytes());

    FILE* f = fopen(path.get(), "w+");

    if (!f)
        return 0;

    return new JDFCarbonFile(f);
}


JDFFileHandle PlatformUtils::openStdOutHandle()
{
    throw PlatformUtilsException("openStdOutHandle() not implemented!");

    return NULL;
}


JDFFileHandle PlatformUtils::openStdInHandle()
{
    try
    {
        return XMLPlatformUtils::openStdInHandle();
    }
    catch (XMLPlatformUtilsException&)
    {
        throw PlatformUtilsException("Failed to open stdinhandle");
    }
}


unsigned int PlatformUtils::readFileBuffer(      JDFFileHandle  theFile,
                                           const unsigned int   toRead,
                                                 JDFByte* const toFill)
{
    int bytesRead = 0;

    try
    {
        bytesRead = XMLPlatformUtils::readFileBuffer(theFile,toRead,toFill);
    }
    catch (XMLException&)
    {
        throw IOException("Failed to read from file");
    }

    return ((bytesRead != 0) ? bytesRead : -1);
}


unsigned int PlatformUtils::writeFileBuffer(      JDFFileHandle   theFile,
                                            const unsigned int    toWrite,
                                                  JDFByte* const  buffer)
{
    size_t bytesWritten = 0;

    bytesWritten = fwrite((void*) buffer, toWrite, 1, ((JDFCarbonFile*) theFile)->getFileHandle());
//    if (!::WriteFile(theFile, buffer, toWrite, &bytesWritten, 0))
//    {
//        //
//        //  Check specially for a broken pipe error. If we get this, it just
//        //  means no more data from the pipe, so return zero.
//        //
//        if (::GetLastError() != ERROR_BROKEN_PIPE)
//          throw IOException("Failed to write to file");
//    }
    return (unsigned int) bytesWritten;
}

void PlatformUtils::resetFile(FileHandle theFile)
{
    try
    {
        XMLPlatformUtils::resetFile(theFile);
    }
    catch (XMLException&)
    {
        throw IOException("resetFile() failed!");
    }
}

void PlatformUtils::flushFile(JDFFileHandle theFile)
{
    //FlushFileBuffers(theFile);
    fflush((FILE*)theFile);
}


void PlatformUtils::lowerCase(JDFCh* const toLowerCase)
{
    _wcslwr(toLowerCase);
}


void PlatformUtils::sleep(int millis)
{
//  struct timespec requestedTime;
//  struct timespec remainingTime;
//  requestedTime.tv_sec = 0;
//  requestedTime.tv_nsec = millis*1000;
//  remainingTime.tv_sec = 0;
//  remainingTime.tv_nsec = 0;
//  nanosleep(&requestedTime, &remainingTime);  // or use : select with empty fds and waiting for timeout

}

// John.Klippenstein@kodak.com - borrow this implementation from the macosPlatformUtils.  
// It's not really platform specific at the jdf level,  they should all just echo it through to the Xerces level.
WString PlatformUtils::weavePaths(const WString&  basePath
							    , const WString&  relativePath)
{
	XMLCh* tmp = XMLPlatformUtils::weavePaths(basePath.c_str(),relativePath.c_str());
	WString res (tmp);
	XMLString::release(&tmp);
	return res;
}

} // namespace JDF
