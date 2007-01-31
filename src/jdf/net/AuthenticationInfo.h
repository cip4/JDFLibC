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
 *
 ******************************************************************************/

#ifndef I_JDF_AUTHENTICATIONINFO_H
#define I_JDF_AUTHENTICATIONINFO_H

/******************************************************************************
 *	Includes
 ******************************************************************************/

#include <jdf/lang/WString.h>


namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 
	class URL;
	class HeaderParser;
	class PlainHttpURLConnection;

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
 * AuthenticationInfo: Encapsulate the information needed to
 * authenticate a user to a server.
 * @nosubgrouping
 */

// REMIND:  It would be nice if this class understood about partial matching.
//	If you're authorized for foo.com, chances are high you're also
//	authorized for baz.foo.com.
// NB:  When this gets implemented, be careful about the uncaching
//	policy in HttpURLConnection.  A failure on baz.foo.com shouldn't
//	uncache foo.com!


class AuthenticationInfo
{
public:

/** 
 * @name Constructors
 */
/*@{*/

    AuthenticationInfo(char type, WString host, int port, WString realm);

    /*
     * Constructor used to limit the authorization to the path within
     * the URL
     */
    AuthenticationInfo(char type, const URL& url, WString realm);

/*@}*/ 
    /**
     * Returns info for the URL, for an HTTP server auth.  Used when we 
     * don't yet know the realm
     * (i.e. when we're preemptively setting the auth).
     */
    static AuthenticationInfo* getServerAuth(const URL& url); 

    /**
     * Returns info for the URL, for an HTTP server auth.  Used when we 
     * do know the realm (i.e. when we're responding to a challenge)
     */
    static AuthenticationInfo* getServerAuth(const URL& url, WString realm); 


private:

    /**
     * Return the AuthenticationInfo object from the cache if it's path is
     * a substring of the supplied URLs path.
     */
    static AuthenticationInfo* getAuth(WString key, const URL& url);

public:

    /**
     * Returns a firewall authentication, for the given host/port.  Used
     * for preemptive header-setting.
     */
    static AuthenticationInfo* getProxyAuth(WString host, int port); 

    /**
     * Returns a firewall authentication, for the given host/port and realm.
     * Used in response to a challenge.
     */
    static AuthenticationInfo* getProxyAuth(WString host, int port, WString realm); 

    /**
     * Add this authentication to the cache
     */
    void addToCache();

    /**
     * Remove this authentication from the cache
     */
    void removeFromCache();

	virtual AuthenticationInfo* copy() = 0;

    /**
     * @return true if this authentication supports preemptive authorization
     */
    virtual bool supportsPreemptiveAuthorization() = 0;

    /**
     * @return the name of the HTTP header this authentication wants set.
     *		This is used for preemptive authorization.
     */
    virtual WString getHeaderName() = 0;

    /**
     * @return the value of the HTTP header this authentication wants set.
     *		Used for preemptive authorization.
     */
    virtual WString getHeaderValue() = 0;

    /**
     * Set header(s) on the given connection.  Subclasses should override to
     * set more than one header.  This will only be called for
     * definitive (i.e. non-preemptive) authorization.
     * @param conn The connection to apply the header(s) to
     * @param p A source of header values for this connection, if needed.
     * @return true if all goes well, false if no headers were set.
     */
    virtual bool setHeaders(PlainHttpURLConnection* conn, HeaderParser& p);

    /** 
     * Give a key for hash table lookups.
     * @param includeRealm if you want the realm considered.  Preemptively
     *		setting an authorization is done before the realm is known.
     */
	WString cacheKey(bool includeRealm);

	static void reinitAuthenticationInfoCache();
	static void reinitAuthenticationInfoMutex();

protected:

	AuthenticationInfo() {};
    // Constants saying what kind of authroization this is.  This determines
    // the namespace in the hash table lookup.

    static const char SERVER_AUTHENTICATION;
    static const char PROXY_AUTHENTICATION;

    /** The type of authentication this is.  Used for key lookup */
    char type;

    /** The host we're authenticating against. */
	WString host;

    /** The port on the host we're authenticating against. */
    int port;

    /** The realm we're authenticating against. */
	WString realm;

    /** The shortest path from the URL we authenticated against. */
	WString path;
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_AUTHENTICATIONINFO_H */
