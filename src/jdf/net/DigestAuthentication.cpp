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

#include "DigestAuthentication.h"

#include "PasswordAuthentication.h"
#include "HeaderParser.h"
#include "PlainHttpURLConnection.h"

#include "md5.h"


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

#define MD5_HASHLEN 16

DigestAuthentication::DigestAuthentication(const URL& url, WString realm, WString authMethod,
										   PasswordAuthentication* pw) :

	AuthenticationInfo(SERVER_AUTHENTICATION, url.getHost(), url.getPort(), realm)
{
	mURL                  = url;
	mPasswordAuth         = pw;
	mAuthenticationMethod = authMethod;
}

bool DigestAuthentication::setHeaders(PlainHttpURLConnection* conn, HeaderParser& p)
{
	HeaderParser::value_pair nonce = p.findValue("nonce");
	HeaderParser::value_pair opaque = p.findValue("opaque");
	WString uri = mURL.getFile();

	HeaderParser::value_pair algorithm = p.findValue("algorithm");

	// check mAuthenticationMethod
	if (algorithm.first)
	{
		if (algorithm.second != "MD5")
			return false;
	}
	else
		algorithm.second = "MD5";

		// problems, we only support MD5
	WString& passwd = mPasswordAuth->getPassword();
	WString response = computeDigest(mPasswordAuth->getUserName(), passwd,realm,
						conn->getRequestMethod(), uri, nonce.second,algorithm.second);


	WString value = mAuthenticationMethod 
			+ " username=\"" + mPasswordAuth->getUserName() 
			+ "\", realm=\"" +realm 
			+ "\", nonce=\"" +nonce.second
			+ "\", uri=\"" +uri
			+ "\", response=\"" + response
			+ "\"";
    if (opaque.first)
    {
		value += ", opaque=\"" + opaque.second + "\"";
	}
	conn->setAuthenticationProperty("Authorization",value);
	return true;
}

/* Response value needs to be in lowercase, so we cannot use HEXD2ASC
   from url.h.  See RFC 2069 2.1.2 for the syntax of response-digest.  */
#define HEXD2asc(x) (((x) < 10) ? ((x) + '0') : ((x) - 10 + 'a'))

/* Dump the hexadecimal representation of HASH to BUF.  HASH should be
   an array of 16 bytes containing the hash keys, and BUF should be a
   buffer of 33 writable characters (32 for hex digits plus one for
   zero termination).  */
static void
dump_hash (unsigned char *buf, const unsigned char *hash)
{
  int i;

  for (i = 0; i < MD5_HASHLEN; i++, hash++)
    {
      *buf++ = HEXD2asc (*hash >> 4);
      *buf++ = HEXD2asc (*hash & 0xf);
    }
  *buf = '\0';
}


AuthenticationInfo* DigestAuthentication::copy() 
{
	DigestAuthentication* a = new DigestAuthentication();
	a->type = type;
	a->host = host;
	a->port = port;
	a->realm = realm;
	a->path = path;
	a->mPasswordAuth   =  mPasswordAuth;
	a->mAuthenticationMethod = mAuthenticationMethod;
	a->mURL = mURL;
	return a;
}

WString DigestAuthentication::computeDigest(const WString& userName, const WString& password,
						  const WString& realm,
						  const WString& connMethod, const WString& requestURI,
						  const WString& nonceString, const WString& algorithm)

{

	char* l_user   = userName.getBytes();
	char* l_realm  = realm.getBytes();
	char* l_method = connMethod.getBytes();
	char* l_path   = requestURI.getBytes();
	char* l_passwd = password.getBytes();
	char* l_nonce  = nonceString.getBytes();

  /* Calculate the digest value.  */
  {
    struct md5_ctx ctx;
    unsigned char hash[MD5_HASHLEN];
    unsigned char a1buf[MD5_HASHLEN * 2 + 1], a2buf[MD5_HASHLEN * 2 + 1];
    unsigned char response_digest[MD5_HASHLEN * 2 + 1];

    /* A1BUF = H(user ":" realm ":" password) */
    md5_init_ctx (&ctx);
    md5_process_bytes (l_user, strlen (l_user), &ctx);
    md5_process_bytes (":", 1, &ctx);
    md5_process_bytes (l_realm, strlen (l_realm), &ctx);
    md5_process_bytes (":", 1, &ctx);
    md5_process_bytes (l_passwd, strlen (l_passwd), &ctx);
    md5_finish_ctx (&ctx, hash);
    dump_hash (a1buf, hash);

    /* A2BUF = H(method ":" path) */
    md5_init_ctx (&ctx);
    md5_process_bytes (l_method, strlen (l_method), &ctx);
    md5_process_bytes (":", 1, &ctx);
    md5_process_bytes (l_path, strlen (l_path), &ctx);
    md5_finish_ctx (&ctx, hash);
    dump_hash (a2buf, hash);

    /* RESPONSE_DIGEST = H(A1BUF ":" nonce ":" A2BUF) */
    md5_init_ctx (&ctx);
    md5_process_bytes (a1buf, MD5_HASHLEN * 2, &ctx);
    md5_process_bytes (":", 1, &ctx);
    md5_process_bytes (l_nonce, strlen (l_nonce), &ctx);
    md5_process_bytes (":", 1, &ctx);
    md5_process_bytes (a2buf, MD5_HASHLEN * 2, &ctx);
    md5_finish_ctx (&ctx, hash);
    dump_hash (response_digest, hash);
	return WString((char*)response_digest);
  }

}

/*
    sprintf (res, "Authorization: Digest \
username=\"%s\", realm=\"%s\", nonce=\"%s\", uri=\"%s\", response=\"%s\"",
	     user, realm, nonce, path, response_digest);
    if (opaque)
      {
	char *p = res + strlen (res);
	strcat (p, ", opaque=\"");
	strcat (p, opaque);
	strcat (p, "\"");
      }
    strcat (res, "\r\n");
  }
  return res;
}
*/

} // namespace JDF
