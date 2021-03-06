/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2007 The International Cooperation for the Integration of 
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
#include <jdf/util/PlatformUtils.h>
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "jdf/net/URLEncoder.h"
#include "jdf/net/URL.h"
#include "jdf/net/URLConnection.h"
#include "jdf/net/URI.h"
#include "jdf/io/File.h"
#include "jdf/io/FileInputStream.h"
#include "jdf/io/FileOutputStream.h"
#include "jdf/io/OutputStream.h"
#include "jdf/util/MyWalker.h"
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/dom/DOMElement.hpp>





#include <iostream>
#include <locale.h>



#include <jdf/util/PlatformUtils.h>
#include <jdf/util/MyTime.h>
#include <jdf/io/File.h>
#include <jdf/io/InputStream.h>
#include <jdf/io/FileInputStream.h>
#include <jdf/io/FileOutputStream.h>
#include <jdf/io/BufferedOutputStream.h>
#include <jdf/Wrapper/jdf.h>

#include <jdf/lang/Exception.h>
#include <jdf/lang/WString.h>

#include <jdf/mime/MIMEMessage.h>
#include <jdf/mime/MIMEMultiPart.h>
#include <jdf/mime/MIMEParser.h>
#include <jdf/mime/MIMEBasicPart.h>
#include <jdf/mime/MIMELocalResourceFactory.h>
#include <iostream>
#include "../TestWrapper/MyTime.h"

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

void testGetParts(JDF::MIMEMessage* msg)
{
	{
		assert( msg->getBodyType() == JDF::MIMEMessage::MULTIPART);
		JDF::MIMEMultiPart* mmp  = (JDF::MIMEMultiPart*) msg->getBody(false);
		int l=mmp->getBodyPartCount();
		std::cout<<l<<std::endl;
		for (int i=0;i<l;i++)
		{
					JDF::MIMEBasicPart* part = (JDF::MIMEBasicPart*) mmp->getBodyPart(i,false);
				JDF::InputStream& in = part->getBodyData();
				if(i==0)
				{
					JDF::JDFDoc doc;
					doc.StreamParse(in);
					std::cout<<"xml:\n"<<doc<<std::endl;
				}

				JDF::WString fname("c:\\tmp\\mimetest");
				char buf2[20];
				fname.append(itoa(i,buf2,10));
				fname.append(".txt");
				std::cout<<i<<fname<<std::endl;
				JDF::FileOutputStream out4(fname);
				char buf[2048];
				int nread;
				while ((nread = in.read(buf,2048)) != -1)
				{
					out4.write(buf,nread);
				}
		}
	}
}

int main(int argc, char* argv[])
{
	// Initialize the XML4C2 system
	try
	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)
	{
		return 1;
	}

	if (argc < 3)
	{
		std::cout << "usage: TestMIMEParser <in-file-name> <out-file-name>" << std::endl;
		std::cout << "Parsers a MIME Message and writes it back out."<< std::endl;
	}
	else
	{
		JDF::File f(argv[1]);
		JDF::FileInputStream fin(f);
		// parse the entire file
		//JDF::MIMEParser parser;
		JDF::MIMELocalResourceFactory mimeFileFactory(JDF::File(L"C:\\tmp")); 
		JDF::MIMEParser parser(&mimeFileFactory); 
		MyTime t1("Read");
		std::cout << "Reading MIME message..." << std::endl;
		JDF::MIMEMessage* msg = parser.parseEntireMessage(fin);
		t1.Stop();


		if (msg)
		{
			MyTime t2("Write");
//			testGetParts(msg);
			t2.Stop();
			std::cout << "Writing MIME message..." << std::endl;
			// write the parsed msg back to a file
			MyTime t3("Write 2");
			JDF::FileOutputStream fos (argv[2]);
			JDF::BufferedOutputStream bos(fos,10000);
			msg->putByteStream(bos);
			bos.flush();
			fos.flush();
			fos.close();
			delete msg;
		}
		else
		{
			std::cout << "failed to parse file" << std::endl;
		}
	}

	try
	{
		JDF::PlatformUtils::Terminate();
	} catch (const JDF::Exception&)
	{
		return 1;
	}


	return 0;

} // main()
