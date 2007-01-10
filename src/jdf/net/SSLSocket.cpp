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
#include "SSLSocket.h"

#include "SocketImpl.h"
#include "SSLSocketInputStream.h"
#include "SSLSocketOutputStream.h"

#include <jdf/util/PlatformUtils.h>
#include <jdf/lang/Synchronized.h>

#ifdef JDF_USESSL
#include <openssl/rsa.h>
#include <openssl/crypto.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#endif


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

SSLSocket::SSLSocket()
{
#ifdef JDF_USESSL
	ssl_ctx = NULL;
	ssl_con = NULL;
#endif
	mUseSSL = false;
	mOut = NULL;
	mIn = NULL;
}

SSLSocket::~SSLSocket()
{
	delete mIn;
	delete mOut;
}

void SSLSocket::close()
{
#ifdef JDF_USESSL
	if (mUseSSL && ssl_con)
	{
		SSL_shutdown(ssl_con);
	}
#endif
	Socket::close();
#ifdef JDF_USESSL
	if (mUseSSL && ssl_con)
	{
		SSL_free(ssl_con);
		SSL_CTX_free(ssl_ctx);
		ssl_con = NULL;
		ssl_ctx = NULL;
	}
#endif
}

void SSLSocket::connect(const WString& host, int port)
{
	Socket::connect(host,port);
//	mSocketImpl->setOption(SocketOptions::SO_IONBIO_OPT,true);
}

void SSLSocket::connect(const InetAddress& address, int port)
{
	Socket::connect(address,port);
//	mSocketImpl->setOption(SocketOptions::SO_IONBIO_OPT,true);
}

void SSLSocket::connect(const WString& host, int port, const InetAddress& localAddress, int localPort)
{
	Socket::connect(host,port,localAddress,localPort);
//	mSocketImpl->setOption(SocketOptions::SO_IONBIO_OPT,true);
}

void SSLSocket::connect(const InetAddress& address, int port, const InetAddress& localAddress, int localPort)
{
	Socket::connect(address,port,localAddress,localPort);
//	mSocketImpl->setOption(SocketOptions::SO_IONBIO_OPT,true);
}


InputStream& SSLSocket::getInputStream()
{
	if (mIn == NULL)
	{
		Synchronized sync(PlatformUtils::gSingletonMutex());
		if (mIn == NULL)
			mIn = new SSLSocketInputStream(*this,Socket::getInputStream());
	}
	return *mIn;
}

OutputStream& SSLSocket::getOutputStream()
{
	if (mOut == NULL)
	{
		Synchronized sync(PlatformUtils::gSingletonMutex());
		if (mOut == NULL)
			mOut = new SSLSocketOutputStream(*this,Socket::getOutputStream());
	}
	return *mOut;
}

WString SSLSocket::toString()
{
	return "SSLSocket" + mSocketImpl->toString();
}


#ifdef JDF_USESSL
int cert_verify_callback(int ok, X509_STORE_CTX *ctx)
{
  X509 *err_cert;
  char buf[256];

  err_cert=X509_STORE_CTX_get_current_cert(ctx);
  X509_NAME_oneline(X509_get_subject_name(err_cert),buf,256);

  return 1;
}

static int my_ssl_passwd_callback(char *buf, int num, int verify,void* userData)
{
	if(verify)
	{
		//xprintf(1, "%s\n", buf);
	}
	else
	{
		char* passwd = (char*) userData;
		if(num > strlen(passwd))
		{
			strcpy(buf, passwd);
			return strlen(buf);
		}
		/*
		PlatformUtils::value_pair certPassword = PlatformUtils::getProperty("https.ssl_cert_passwd");
		if (certPassword.first)
		{
			char* pwd = certPassword.second.getBytes();
			if(num > strlen(pwd))
			{
				strcpy(buf, pwd);
				delete[] pwd;
				return strlen(buf);
			}
			delete[] pwd;
		}
		*/
	}
	return 0;
}
#endif



void SSLSocket::SSLConnect()
{
#ifdef JDF_USESSL
	// todo error control

	SSL_METHOD* ssl_method;
	BIO *ssl_bio;
	int rv;

	SSL_load_error_strings();
	
	// initialize SSL Method

	PlatformUtils::value_pair method = PlatformUtils::getProperty("https.ssl_version");
	if (method.first)
	{
		if (method.second == "SSLv23")
			ssl_method = SSLv23_client_method();
		else if (method.second == "SSLv2")
			ssl_method = SSLv2_client_method();
		else if (method.second == "SSLv3")
			ssl_method = SSLv3_client_method();
#ifdef JDF_SSL_TLS1
		else if (method.second == "TLSv1")
			ssl_method = TLSv1_client_method();
#endif
	}
	else
		ssl_method = SSLv23_client_method();
	SSLeay_add_ssl_algorithms();

    RAND_screen();

	ssl_ctx = SSL_CTX_new(ssl_method);

	// set preferred Cipher list

	PlatformUtils::value_pair cipherList = PlatformUtils::getProperty("https.ssl_cipher_list");
	if (cipherList.first)
	{
		char* cipherListBytes = cipherList.second.getBytes();
		SSL_CTX_set_cipher_list(ssl_ctx, cipherListBytes);
		delete[] cipherListBytes;
	}
	
	// SSL Certification stuff 
	PlatformUtils::value_pair certFile = PlatformUtils::getProperty("https.ssl_cert_file");

	if (certFile.first)
	{
		SSL *ssl;
		X509 *x509;

		PlatformUtils::value_pair certPassword = PlatformUtils::getProperty("https.ssl_cert_passwd");

		if (certPassword.first)
		{
			SSL_CTX_set_default_passwd_cb(ssl_ctx , my_ssl_passwd_callback);
		}

		char* certFileBytes = certFile.second.getBytes();
		ArrayJanitor<char> certFileJanitor(certFileBytes);

		if (SSL_CTX_use_certificate_file(ssl_ctx , certFileBytes,
				SSL_FILETYPE_PEM) <= 0)
		{
			//xprintf(1 , gettext("Unable to set certificate file (wrong password?)\n"));
			return;// FALSE;
		}

		PlatformUtils::value_pair certKeyFile = PlatformUtils::getProperty("https.ssl_key_file");
		char* certKeyFileBytes;
		if (certKeyFile.first == false)
		{
			certKeyFileBytes = strdup(certFileBytes);
		}
		else
		{
			certKeyFileBytes = certKeyFile.second.getBytes();
		}

		ArrayJanitor<char> certKeyJanitor(certKeyFileBytes);

		if (SSL_CTX_use_PrivateKey_file(ssl_ctx , certKeyFileBytes,
				SSL_FILETYPE_PEM) <= 0) 
		{
			//xprintf(1, gettext("Unable to set public key file\n"));
			return;// FALSE;
		}


		ssl = SSL_new(ssl_ctx);
	    
		x509 = SSL_get_certificate(ssl);
    
		if (x509 != NULL)
			EVP_PKEY_copy_parameters(X509_get_pubkey(x509),
			SSL_get_privatekey(ssl));

		SSL_free(ssl);

		if (!SSL_CTX_check_private_key(ssl_ctx))
		{
			//xprintf(1, gettext("Private key does not match the certificate public key\n"));
			return;// FALSE;
		}    
	}	
/* End SSL Certification stuff */
	
	ssl_con = SSL_new(ssl_ctx);
	ssl_bio = BIO_new_socket(mSocketImpl->getFileDescriptor(), BIO_NOCLOSE);
	SSL_set_bio(ssl_con ,ssl_bio , ssl_bio);
	SSL_set_connect_state(ssl_con);
	SSL_do_handshake(ssl_con);

	while((rv = SSL_in_init(ssl_con)) && 
		SSL_get_error(ssl_con , rv) == SSL_ERROR_WANT_CONNECT)
	{
		PlatformUtils::sleep(2);
	}

	if (rv < 0)
	{
//		if (cfg.unique_sslid)
//		{
//			SSL_set_shutdown(*ssl_con, SSL_SENT_SHUTDOWN | SSL_RECEIVED_SHUTDOWN);
//		}
//		else
		{
			SSL_free(ssl_con);
			SSL_CTX_free(ssl_ctx);
			ssl_con = NULL;
			ssl_ctx = NULL;
		}
		return; // FALSE;
	}
	mUseSSL = true;
	return; // TRUE

#endif

}


} // namespace JDF
