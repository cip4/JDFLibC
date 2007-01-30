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

/*******************************************************************************
 * 
 * Description:
 *
 * This test program tests HTTP PUT by sending a user entered string to
 * the cgi-script http://java.sun.com/cgi-bin/backwards 
 * The server will send the string back backwards.
 *
 ******************************************************************************/


/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <jdf/util/PlatformUtils.h>
#include <util/PlatformUtils.hpp>
#include "jdf\util\Exception.h"
#include <jdf/net/url.h>
#include <jdf/net/URLConnection.h>
#include <jdf/net/HttpURLConnection.h>
#include <jdf/io/ByteArrayOutputStream.h>
#include <jdf/io/InputStream.h>
#include <iostream>
using namespace JDF;

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

/**
 * This is a test authenticator that prompts up a dialog box to the user
 * and requests a username and password
 * Note that the actual password encoding (BASIC,DIGEST,..)
 * is done inside the JDFTOOLS layer
 */
//class MyAuthenticator : public JDF::Authenticator
//{
//public:
//
//	JDF::PasswordAuthentication* getPasswordAuthentication()
//	{
//		JDF::WString userName, passwd;
//		bool ok = getUserNameAndPassword(userName, passwd,getRequestingPrompt(),getRequestingSite().getHostName());
//
//		if (ok)
//			return new JDF::PasswordAuthentication(userName,passwd);
//		return false;
//	}
//};


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

	// The following properties can be set to control HTTP proxy settings
	// To make this example really useful, we should make these settings
	// command line arguments

	// http.proxyHost  : The name of the HTTP proxyserver
	// http.proxyPort  : The port number of HTTP proxyserver
	// http.nonProxyHosts: List of addresses that don't use a
	//					   proxyserver (regular expressions are allowed)
	//					   ex. *.eps.agfa.be
	// https.proxyHost : The name of the HTTPS secure proxyserver
	// https.proxyPort : The port number of the HTTPS proxyserver

	// optional properties of https
	// https.ssl_version : SSL version to use for secure connections (SSLv23, SSLv2,SSLv3 or TLSv1
	//					   default is SSLv23
	// https.ssl_cert_file : SSL certificate pem file to use
	// https.ssl_key_file  : SSL certificate key file
	// https.ssl_cert_passwd : SSL certificate password

	// example: only set a proxyserver for HTTP

//	JDF::PlatformUtils::setProperty("http.proxyHost","proxy");
//	JDF::PlatformUtils::setProperty("http.proxyPort","8080");
//	JDF::PlatformUtils::setProperty("http.nonProxyHosts","godzilla");
	//std::cout<< "proxyport:"<<JDF::PlatformUtils::getProperty("http.proxyPort")<<std::endl;
//	JDF::PlatformUtils::setProperty("http.proxyHost",SET_THE_NAME_OF_PROXYSERVER_HERE);
//	JDF::PlatformUtils::setProperty("http.proxyPort",PROXY_PORTNUMBER);
//	JDF::PlatformUtils::setProperty("http.nonProxyHosts",NON_PROXYLIST);
//	JDF::PlatformUtils::setProperty("https.ssl_version",SSL_VERSION);
//	JDF::PlatformUtils::setProperty("https.ssl_cert_file",PATH_TO_CERT_FILE);
//	JDF::PlatformUtils::setProperty("https.ssl_key_file",PATH_TO_CERT_KEYFILE);
//	JDF::PlatformUtils::setProperty("https.ssl_cert_passwd",CERT_PASSWD);

	// install the new authenticator
	// with password handling
//	JDF::Authenticator::setDefault(new MyAuthenticator());

	char* theURL  = "http://intra.heidelberg.com";

	std::cout << "Enter any string:";

	char line[256];
	gets(line);
	// create a URL

	JDF::URL u;

	try
	{
		// create the URL for the server
		u.create(theURL);
		std::cout << "Connecting to:" <<theURL<< std::endl;
		// open up the connection
		JDF::HttpURLConnection* con = (JDF::HttpURLConnection*) u.openConnection();
		if ( con == NULL)
			std::cout << "test 1 equal null" << std::endl;
		else
			std::cout << "test 1 not equal null" << con << std::endl;
		// we want to send something to the server
		con->setRequestMethod("GET");
		std::cout << "test 2" << std::endl;
		// we will have to enable output explicitly
		con->setDoOutput(true);
		// now send the user string
		std::cout << "test 3" << std::endl;

		JDF::OutputStream& out = con->getOutputStream();
		std::cout << "test 4" << std::endl;
		std::string s("string=");
		s.append(&line[0]);
		std::cout << "test 5" << std::endl;
		out.write((char*)s.data(),s.length());
		std::cout << "test 6" << std::endl;
		// read back the reply we get from the server
		JDF::InputStream& in = con->getInputStream();
		std::cout << "test 7" << std::endl;
		JDF::ByteArrayOutputStream bout;
		const int size = 1024*10;
		char buf[size];
		int nread;
		while ((nread = in.read(buf,size)) != -1)
		{
			bout.write(buf,nread);
		}
		std::cout << "test 8" << std::endl;
		// show the result
		JDF::WString reserved =  bout.toString();
		std::cout << "test 9" << std::endl;
		//char* reservedBytes = reserved.getBytes();
		//JDF::ArrayJanitor<char> reservedBytesJanitor(reservedBytes);
		std::cout << reserved.getBytes() << std::endl;
		std::cout << "test 10" << std::endl;
		delete con;
		std::cout << "test 11" << std::endl;
	}
	catch (JDF::Exception& e)
	{
		char* reason = e.toString().getBytes();
		std::cout << "test 12" << std::endl;
//		JDF::ArrayJanitor<char> reasonJanitor(reason);
		std::cout << "ExceptionCaught " << reason << std::endl;
	}
	try
	{
		std::cout << "test 13" << std::endl;
		JDF::PlatformUtils::Terminate();
	} catch (const JDF::Exception&)
	{
		return 1;
	}

    try
	{
	std::cout << "test 14" << std::endl;
        XMLPlatformUtils::Terminate();
    }
	catch(const XMLException&)
	{
        return 1;
    }

	return 0;
}
