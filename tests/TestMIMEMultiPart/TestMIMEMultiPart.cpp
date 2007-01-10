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
 *	Includes
 ******************************************************************************/ 

/*******************************************************************************
 * 
 * Description:
 *
 * This test program creates a MIME Multipart Message consisting of three
 * parts: a Basic part with a simple text, a BasicPart containing an 
 * encoded (BASE64 or QP) file and an BasicPart referencing an external file.
 * The test program output the Miltipart message to an file named
 * 'MsgWithMultiPart.out' in the default system temp directory.
 *
 ******************************************************************************/

#include <util/PlatformUtils.hpp>
#include <jdf/util/PlatformUtils.h>
#include <jdf/io/File.h>
#include <jdf/io/FileInputStream.h>
#include <jdf/io/FileOutputStream.h>
#include <jdf/io/BufferedOutputStream.h>
#include <jdf/lang/WString.h>
#include <jdf/mime/MIMEMessage.h>
#include <jdf/mime/MIMEMessagePart.h>
#include <jdf/mime/MIMEBasicPart.h>
#include <jdf/mime/MIMEMultiPart.h>
#include <jdf/mime/FileMIMEType.h>
#include <jdf/net/URLConnection.h>
#include <iostream>

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

class MessageWithAttachments
{
public:

	MessageWithAttachments();

	void setText(char* text);
	void attachFile(const std::string& filename, int encoding);
	void attachExternalLocalFile(const std::string& filename);

private:

	JDF::MIMEMessage* msg;
};

MessageWithAttachments::MessageWithAttachments()
{
}


void setOtherHeaders(JDF::MIMEMessage* mmsg)
{
	 try
	 {
		 mmsg->setHeader (JDF::MIMEHeader::FROM, "John Doe <john.doe@usenet.net>");
		 mmsg->setHeader (JDF::MIMEHeader::TO, "John Smith <jsmith@yahoo.net>");
		 mmsg->setHeader (JDF::MIMEHeader::REPLY_TO, "John Doe <john.doe@usenet.net>");
		 mmsg->setHeader ("X-MyTest-Header", "Test-Header-1");
	 }
	 catch (JDF::Exception& )
	 {
		 std::cout << "setOtherHeaders> Caught exception: ";
	 }
}


JDF::MIMEMessagePart* createMsgPartExt()
{
	JDF::MIMEMessagePart* l_msgpart;

	try
	{
		// create a message part
		l_msgpart = new JDF::MIMEMessagePart();

		// set the attributes of the messagePart
		l_msgpart->setContentSubType("external-body");
		l_msgpart->setContentTypeParams("access-type=local-file;name=\"e:\\share\\png1.png");
		l_msgpart->setContentEncoding(JDF::MIMEBodyPart::E7BIT);

		// set ext-part headers
		l_msgpart->setExtBodyHeader("Content-Type","image/png");
		return l_msgpart;
	}
	catch (JDF::Exception& )
	{
		std::cout << "createMsgPartExt> Caught exception: ";
		delete l_msgpart;
		return NULL;
	}
}

// create a text-part
JDF::MIMEBasicPart* createTextPart(std::string inText)
{
	JDF::MIMEBasicPart* l_mbp = NULL;
	
	try
	{
		l_mbp = new JDF::MIMEBasicPart (JDF::MIMEBasicPart::TEXT);
		l_mbp->setContentSubType ("plain");
		l_mbp->setContentTypeParams ("charset=us-ascii");
		l_mbp->setContentID("Text_BasicPart_ContentID");
		l_mbp->setContentDisposition(JDF::MIMEBodyPart::INLINE);
		//l_mbp.setContentDisposition(MIMEBodyPart.ATTACHMENT); // if you like
		l_mbp->setContentDispParams("TextPart Disp-Params");
		l_mbp->setContentDispParams("Some_Params");
		l_mbp->setHeader ("X-TextPartHeader-1", "myValue-1");
		l_mbp->setHeader ("X-TextPartHeader-2", "myValue-2");
		l_mbp->setBodyData (inText);
		return l_mbp;
	}
	catch (JDF::Exception& )
	{
		std::cout << "createTextPart> Caught exception: ";
		delete l_mbp;
		return NULL;
	}
}

JDF::MIMEBasicPart* createFilePart(const std::string& filename, int encoding)
{
	JDF::MIMEBasicPart* l_filePart = NULL;
	JDF::FileInputStream* l_fis;
	JDF::FileMIMEType l_fmt;

	try
	{
		// get the mime-type info on the file passed
		l_fmt = JDF::URLConnection::getFileNameMap()->getContentTypeFor(filename);

		l_filePart = new JDF::MIMEBasicPart(l_fmt.content_type);
		l_filePart->setContentSubType(l_fmt.content_subtype);

		if (l_fmt.content_params.length())
			l_filePart->setContentTypeParams(l_fmt.content_params);
		else
			l_filePart->setContentTypeParams(JDF::WString("name=")+l_fmt.file_shortname);
		if (encoding == -1)
			l_filePart->setContentEncoding(l_fmt.mime_encoding);
		else
			l_filePart->setContentEncoding(encoding);

		l_filePart->setContentDispParams(JDF::WString("filename=")+l_fmt.file_shortname);
		l_filePart->setContentDescription(l_fmt.file_shortname);
		// open input-stream to the file
		l_fis = new JDF::FileInputStream(filename);
		// set the stream as body-data
		l_filePart->setBodyData(l_fis);
		// all done. Return the part
		return l_filePart;
	}
	catch (JDF::Exception& )
	{
		std::cout << "createFilePart> Caught exception: ";
		delete l_filePart;
		return NULL;
	}
}
 
 

int main(int argc, char* argv[])
{
	  // Initialize the XML4C2 system
    try
	{
        XMLPlatformUtils::Initialize();
    }
	catch(const XMLException&)
	{
        return 1;
    }
	
	// Initialize the JDFTools system
	try
	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)
	{
		return 1;
	}


	JDF::MIMEMessage* mmsg = NULL;
	JDF::MIMEMultiPart* mmp;
	JDF::MIMEBasicPart* bpText;
	JDF::MIMEBasicPart* bpFile;
	JDF::MIMEMessagePart* mmsgpart;
	JDF::FileOutputStream* fos = NULL;
	std::string filename;
	int encoding = -1;
	
	if (argc < 2)
	{
		std::cout << "usage: TestMIMEMultiPartMessage <file-name> <B|Q>" << std::endl;
	}
	else
	{
		filename = argv[1];

		JDF::FileInputStream fin2(filename);
		JDF::InputStream& fin2ref = fin2;

		char buf[2048];
		int bytesRead;

		while ((bytesRead=fin2.read(buf,2048)) != -1)
		{
	//		std::cout << std::string(buf,bytesRead);
		}

		if (argc > 2)
		{
			if (JDF::WString(argv[2]).equalsIgnoreCase("B"))
				encoding = JDF::MIMEBodyPart::BASE64;
			else if (JDF::WString(argv[2]).equalsIgnoreCase("Q"))
				encoding = JDF::MIMEBodyPart::QP;
		}

		try
		{
			// Create the MultiPart w/ mixed subtype
			mmp = new JDF::MIMEMultiPart();
			mmp->setContentSubType("mixed");
			mmp->setContentTypeParams("test-params");

			// create a text-part (basic-part) and add it to the multi-part
			bpText = createTextPart("Hello this is a simple text part");
			if (bpText != NULL)
				mmp->addBodyPart(bpText, false); // false->don't clone it

			// create a basic part from the file-name passed and add it 
			// to the multi-part
			bpFile = createFilePart(filename,encoding);
			if (bpFile != NULL)
				mmp->addBodyPart(bpFile, false); // false->don't clone it

			// create a message part (external-body)
			mmsgpart = createMsgPartExt();
			if (mmsgpart != NULL)
				mmp->addBodyPart(mmsgpart, false); // false->don't clone it

			// ok we now have a multi-part w/ three parts
			// make a MIMEMessage out of it
			mmsg = new JDF::MIMEMessage();
			mmsg->setBody(mmp,false);

			// Set need headers of the new Message
			mmsg->setHeader("Subject","Test Message w/ MultiPart content");

			// Set other headers of the Message
			setOtherHeaders(mmsg);

			// Now the message is completely built!
			// Encode it in MIME canonical form
			fos = new JDF::FileOutputStream(JDF::File(JDF::File::getTempDirectory(),"MsgWithMultiPart.out"));
			JDF::BufferedOutputStream bout(*fos,4096);
			mmsg->putByteStream(bout);
			delete fos;
			delete mmsg;
		} catch (JDF::Exception& )
		{
			std::cout << "createTextPart> Caught exception: ";
			delete mmsg;
			delete fos;
		}
	}
	try
	{
		JDF::PlatformUtils::Terminate();
	} catch (const JDF::Exception&)
	{
		return 1;
	}

    try
	{
        XMLPlatformUtils::Terminate();
    }
	catch(const XMLException&)
	{
        return 1;
    }
	return 0;

} // main()