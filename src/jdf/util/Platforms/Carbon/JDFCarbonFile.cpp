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
 * For ease of viewing, please set your tabs and indents to 3                 *
 * Tabs and indents are set correctly if the following two vertical bars      *
 * appear in the same column                                                  *
 *                                      |                                     *
 *                                      |                                     *
 ******************************************************************************/


/*******************************************************************************
 * 
 * Description:
 *
 *
 ******************************************************************************/


/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <xercesc/util/Janitor.hpp>

#include <jdf/util/Platforms/Carbon/JDFCarbonFile.h>


//XERCES_CPP_NAMESPACE_BEGIN


namespace JDF
{


XMLCarbonFile::XMLCarbonFile(FILE* file)
{
    setFileHandle(file);
}

    
FILE* XMLCarbonFile::getFileHandle() const
{
    return mFile;
}


void XMLCarbonFile::setFileHandle(FILE* file)
{
    if (mFile != NULL)
    {
       close(); mFile = NULL;
    }

    mFile = file;
}


bool XMLCarbonFile::isValid() const
{
    return (mFile != NULL);
}


//----------------------------------------------------------------------------
// JDFCarbonFile implementation
//----------------------------------------------------------------------------

JDFCarbonFile::JDFCarbonFile(FILE* file)
    : m_file(file)
{
}


FILE* JDFCarbonFile::getFileHandle()
{
    return m_file.getFileHandle();
}


void JDFCarbonFile::setFileHandle(FILE* file)
{
    m_file.setFileHandle(file);
}


unsigned int JDFCarbonFile::currPos()
{
    return m_file.currPos();
}


void JDFCarbonFile::close()
{
    m_file.close();
}


unsigned int JDFCarbonFile::size()
{
    return m_file.size();
}


void JDFCarbonFile::open(const XMLCh* const fileName)
{
    if (m_file.isValid())
        ThrowXML(XMLPlatformUtilsException, XMLExcepts::File_CouldNotOpenFile);

    // Check to make sure the file system is in a state where we can use it
    if (!gFileSystemCompatible)
        ThrowXML1(XMLPlatformUtilsException, XMLExcepts::File_CouldNotOpenFile, fileName);

    // John.Klippenstein - this line compiles with Xerces 2.5 but not 2.7
    // But the object being constructed is never used!!
    //Janitor<XMLMacAbstractFile> file(XMLMakeMacFile());

    if (!m_file.open(fileName, false))
        ThrowXML1(XMLPlatformUtilsException, XMLExcepts::File_CouldNotOpenFile, fileName);
}


unsigned int JDFCarbonFile::read(const unsigned int toRead, XMLByte* const toFill)
{
    return m_file.read(toRead, toFill);
}


void JDFCarbonFile::reset()
{
    m_file.reset();
}


} // namespace JDF

