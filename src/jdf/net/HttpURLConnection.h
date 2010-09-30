/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2010 The International Cooperation for the Integration of 
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

#ifndef I_JDF_HTTPURLCONNECTION_H
#define I_JDF_HTTPURLCONNECTION_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 
#include "URLConnection.h"


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

/**
 * An URLConnection with support for HTTP-specific features. See
 * <A HREF="http://www.w3.org/pub/WWW/Protocols/"> the spec </A> for
 * details.
 * <p>
 * 
 * Each HttpURLConnection instance is used to make a single request  
 * but the underlying network connection to the HTTP server may be
 * transparently shared by other instances. Calling the close() methods
 * on the InputStream or OutputStream of an HttpURLConnection
 * after a request may free network resources associated with this
 * instance but has no effect on any shared persistent connection.
 * Calling the disconnect() method may close the underlying socket
 * if a persistent connection is otherwise idle at that time.
 * @ingroup net
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT HttpURLConnection : public URLConnection
{
public:

/** 
 * @name Constructors
 */
/*@{*/

    /**
     * Constructor for the URLStreamHandler.
     * @param u the URL
     */

	HttpURLConnection(const URL& url);
	virtual ~HttpURLConnection();
/*@}*/ 
    /**
     * Sets whether HTTP redirects  (requests with response code 3xx) should 
     * be automatically followed by this class.  True by default.  
     * 
     * @param set a <code>bool</code> indicating whether or not
     * to follow HTTP redirects.
     * @see HttpURLConnection#getFollowRedirects()
     */

    static void setFollowRedirects(bool set);

    /**
     * Returns a <code>boolean</code> indicating
     * whether or not HTTP redirects (3xx) should
     * be automatically followed.
     *
     * @return <code>true</code> if HTTP redirects should
     * be automatically followed, <tt>false</tt> if not.
     * @see #setFollowRedirects(bool)
     */

    static bool getFollowRedirects();

    /**
     * Sets whether HTTP redirects (requests with response code 3xx) should
     * be automatically followed by this <code>HttpURLConnection</code> 
     * instance.
     * <p>
     * The default value comes from followRedirects, which defaults to
     * true.
     *
     * @param followRedirects a <code>boolean</code> indicating 
     * whether or not to follow HTTP redirects.
     *
     * @see HttpURLConnection#instanceFollowRedirects
     * @see HttpURLConnection#getInstanceFollowRedirects()
     */

    void setInstanceFollowRedirects(bool followRedirects);

     /**
     * Returns the value of this <code>HttpURLConnection</code>'s
     * <code>instanceFollowRedirects</code> field.
     *
     * @return  the value of this <code>HttpURLConnection</code>'s
     *          <code>instanceFollowRedirects</code> field.
     * @see HttpURLConnection#instanceFollowRedirects
     * @see HttpURLConnection#setInstanceFollowRedirects(bool)
     */

    bool getInstanceFollowRedirects();

    /**
     * Set the method for the URL request, one of:
     * <UL>
     *  <LI>GET
     *  <LI>POST
     *  <LI>HEAD
     *  <LI>OPTIONS
     *  <LI>PUT
     *  <LI>DELETE
     *  <LI>TRACE
     * </UL> are legal, subject to protocol restrictions.  The default
     * method is GET.
     * 
     * @param method the HTTP method
     * @exception ProtocolException if the method cannot be reset or if
     *              the requested method isn't valid for HTTP.
     * @see HttpURLConnection#getRequestMethod()
     */

    void setRequestMethod(const WString& method);

	/**
     * Get the request method.
     * @return the HTTP request method
     * @see HttpURLConnection#setRequestMethod(std::string)
     */
    
	WString getRequestMethod();

    /**
     * Gets HTTP response status from responses like:
     * <PRE>
     * HTTP/1.0 200 OK
     * HTTP/1.0 401 Unauthorized
     * </PRE>
     * Extracts the ints 200 and 401 respectively.
     * Returns -1 if none can be discerned
     * from the response (i.e., the response is not valid HTTP).
     * @throws IOException if an error occurred connecting to the server.
     * @return the HTTP Status-Code
     */

    int getResponseCode();

    /**
     * Gets the HTTP response message, if any, returned along with the
     * response code from a server.  From responses like:
     * <PRE>
     * HTTP/1.0 200 OK
     * HTTP/1.0 404 Not Found
     * </PRE>
     * Extracts the Strings "OK" and "Not Found" respectively.
     * Returns null if none could be discerned from the responses 
     * (the result was not valid HTTP).
     * @throws IOException if an error occurred connecting to the server.
     * @return the HTTP response message, or <code>null</code>
     */

	WString getResponseMessage();



    long getHeaderFieldDate(const WString& name, long Default);

    /**
     * Indicates that other requests to the server
     * are unlikely in the near future. Calling disconnect() 
     * should not imply that this HttpURLConnection 
     * instance can be reused for other requests.
     */

    virtual void disconnect() = 0;

    /**
     * Indicates if the connection is going through a proxy.
     * @return a boolean indicating if the connection is
     * using a proxy.
     */
    virtual bool usingProxy() = 0;

    //InputStream& getErrorStream();

public:

	/**
     * The response codes for HTTP, as of version 1.1.
     */

    // REMIND: do we want all these??
    // Others not here that we do want??

    /* 2XX: generally "OK" */

    /**
     * HTTP Status-Code 200: OK.
     */
    static const int HTTP_OK;

    /**
     * HTTP Status-Code 201: Created.
     */
    static const int  HTTP_CREATED;

    /**
     * HTTP Status-Code 202: Accepted.
     */
    static const int  HTTP_ACCEPTED;

    /**
     * HTTP Status-Code 203: Non-Authoritative Information.
     */    
    static const int  HTTP_NOT_AUTHORITATIVE; 

    /**
     * HTTP Status-Code 204: No Content.
     */
    static const int  HTTP_NO_CONTENT;

    /**
     * HTTP Status-Code 205: Reset Content.
     */
    static const int  HTTP_RESET;

    /**
     * HTTP Status-Code 206: Partial Content.
     */
    static const int  HTTP_PARTIAL;

    /* 3XX: relocation/redirect */

    /**
     * HTTP Status-Code 300: Multiple Choices.
     */
    static const int HTTP_MULT_CHOICE;

    /**
     * HTTP Status-Code 301: Moved Permanently.
     */
    static const int HTTP_MOVED_PERM;

    /**
     * HTTP Status-Code 302: Temporary Redirect.
     */
    static const int HTTP_MOVED_TEMP;
 
    /**
     * HTTP Status-Code 303: See Other.
     */
    static const int HTTP_SEE_OTHER;

    /**
     * HTTP Status-Code 304: Not Modified.
     */
    static const int HTTP_NOT_MODIFIED;

    /**
     * HTTP Status-Code 305: Use Proxy.
     */
    static const int HTTP_USE_PROXY;

    /* 4XX: client error */

    /**
     * HTTP Status-Code 400: Bad Request.
     */
    static const int HTTP_BAD_REQUEST;

    /**
     * HTTP Status-Code 401: Unauthorized.
     */
    static const int HTTP_UNAUTHORIZED;

    /**
     * HTTP Status-Code 402: Payment Required.
     */
    static const int HTTP_PAYMENT_REQUIRED;

    /**
     * HTTP Status-Code 403: Forbidden.
     */
    static const int HTTP_FORBIDDEN;

    /**
     * HTTP Status-Code 404: Not Found.
     */
    static const int HTTP_NOT_FOUND;

    /**
     * HTTP Status-Code 405: Method Not Allowed.
     */
    static const int HTTP_BAD_METHOD;

    /**
     * HTTP Status-Code 406: Not Acceptable.
     */
    static const int HTTP_NOT_ACCEPTABLE;

    /**
     * HTTP Status-Code 407: Proxy Authentication Required.
     */
    static const int HTTP_PROXY_AUTH;

    /**
     * HTTP Status-Code 408: Request Time-Out.
     */
    static const int HTTP_CLIENT_TIMEOUT;

    /**
     * HTTP Status-Code 409: Conflict.
     */
    static const int HTTP_CONFLICT;

    /**
     * HTTP Status-Code 410: Gone.
     */
    static const int HTTP_GONE;

    /**
     * HTTP Status-Code 411: Length Required.
     */
    static const int HTTP_LENGTH_REQUIRED;

    /**
     * HTTP Status-Code 412: Precondition Failed.
     */
    static const int HTTP_PRECON_FAILED;

    /**
     * HTTP Status-Code 413: Request Entity Too Large.
     */
    static const int HTTP_ENTITY_TOO_LARGE;

    /**
     * HTTP Status-Code 414: Request-URI Too Large.
     */
    static const int HTTP_REQ_TOO_LONG;

    /**
     * HTTP Status-Code 415: Unsupported Media Type.
     */
    static const int HTTP_UNSUPPORTED_TYPE;
    
    /* 5XX: server error */

    /** 
     * HTTP Status-Code 500: Internal Server Error. 
     */
    static const int HTTP_INTERNAL_ERROR;

    /** 
     * HTTP Status-Code 501: Not Implemented.
     */
    static const int HTTP_NOT_IMPLEMENTED;

    /**
     * HTTP Status-Code 502: Bad Gateway.
     */
    static const int HTTP_BAD_GATEWAY;

    /**
     * HTTP Status-Code 503: Service Unavailable.
     */
    static const int HTTP_UNAVAILABLE;

    /**
     * HTTP Status-Code 504: Gateway Timeout.
     */
    static const int HTTP_GATEWAY_TIMEOUT;

    /**
     * HTTP Status-Code 505: HTTP Version Not Supported.
     */
    static const int HTTP_VERSION;

protected:

    /**
     * The HTTP method (GET,POST,PUT,etc.). 
     */
	WString method;

    /**
     * An <code>int</code> representing the three digit HTTP Status-Code.
     * <ul>
     * <li> 1xx: Informational
     * <li> 2xx: Success
     * <li> 3xx: Redirection
     * <li> 4xx: Client Error
     * <li> 5xx: Server Error
     * </ul>
     */
    int responseCode;

    /**
     * The HTTP response message.
     */
    WString responseMessage;

    /**
     * If <code>true</code>, the protocol will automatically follow redirects.
     * If <code>false</code>, the protocol will not automatically follow 
     * redirects.
     * <p>
     * This field is set by the <code>setInstanceFollowRedirects</code> 
     * method. Its value is returned by the <code>getInstanceFollowRedirects</code> 
     * method.
     * <p>
     * Its default value is based on the value of the static followRedirects 
     * at HttpURLConnection construction time.
     *
     * @see HttpURLConnection#setInstanceFollowRedirects(boolean)
     * @see HttpURLConnection#getInstanceFollowRedirects()
     * @see HttpURLConnection#setFollowRedirects(boolean)
     */
     bool instanceFollowRedirects;


private:
 
    /**
	 * do we automatically follow redirects? The default is true. 
	 */

	static bool followRedirects;
};


/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_HTTPURLCONNECTION_H */
