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

#ifndef I_JDF_URL_H
#define I_JDF_URL_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include "URLStreamHandler.h"

#include <jdf/lang/WString.h>
#include <jdf/lang/AutoPtr.h>

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
class URLStreamHandlerFactory;
class URLConnection;
class URI;

/**
 * Class <code>URL</code> represents a Uniform Resource 
 * Locator, a pointer to a "resource" on the World 
 * Wide Web. A resource can be something as simple as a file or a 
 * directory, or it can be a reference to a more complicated object, 
 * such as a query to a database or to a search engine. More 
 * information on the types of URLs and their formats can be found at:
 * <blockquote><pre>
 *     http://www.ncsa.uiuc.edu/demoweb/url-primer.html
 * </pre></blockquote>
 * <p>
 * In general, a URL can be broken into several parts. The previous 
 * example of a URL indicates that the protocol to use is 
 * <code>http</code> (HyperText Transfer Protocol) and that the 
 * information resides on a host machine named 
 * <code>www.ncsa.uiuc.edu</code>. The information on that host 
 * machine is named <code>/demoweb/url-primer.html</code>. The exact 
 * meaning of this name on the host machine is both protocol 
 * dependent and host dependent. The information normally resides in 
 * a file, but it could be generated on the fly. This component of 
 * the URL is called the <i>path</i> component.
 * <p>
 * A URL can optionally specify a "port", which is the 
 * port number to which the TCP connection is made on the remote host 
 * machine. If the port is not specified, the default port for 
 * the protocol is used instead. For example, the default port for 
 * <code>http</code> is <code>80</code>. An alternative port could be 
 * specified as: 
 * <blockquote><pre>
 *     http://www.ncsa.uiuc.edu:8080/demoweb/url-primer.html
 * </pre></blockquote>
 * <p>
 * A URL may have appended to it a "fragment", also known 
 * as a "ref" or a "reference". The fragment is indicated by the sharp
 * sign character "#" followed by more characters. For example, 
 * <blockquote><pre>
 *     http://java.sun.com/index.html#chapter1
 * </pre></blockquote>
 * <p>
 * This fragment is not technically part of the URL. Rather, it 
 * indicates that after the specified resource is retrieved, the 
 * application is specifically interested in that part of the 
 * document that has the tag <code>chapter1</code> attached to it. The 
 * meaning of a tag is resource specific. 
 * <p>
 * An application can also specify a "relative URL", 
 * which contains only enough information to reach the resource 
 * relative to another URL. Relative URLs are frequently used within 
 * HTML pages. For example, if the contents of the URL:
 * <blockquote><pre>
 *     http://java.sun.com/index.html
 * </pre></blockquote>
 * contained within it the relative URL:
 * <blockquote><pre>
 *     FAQ.html
 * </pre></blockquote>
 * it would be a shorthand for:
 * <blockquote><pre>
 *     http://java.sun.com/FAQ.html
 * </pre></blockquote>
 * <p>
 * The relative URL need not specify all the components of a URL. If 
 * the protocol, host name, or port number is missing, the value is 
 * inherited from the fully specified URL. The file component must be 
 * specified. The optional fragment is not inherited. 
 * <p>
 * The URL class does not itself encode or decode any URL components according 
 * to the escaping mechanism defined in RFC2396. It is the responsibility of the 
 * caller to encode any fields, which need to be escaped prior to calling URL, 
 * and also to decode any escaped fields, that are returned from URL. 
 * Furthermore, because URL has no knowledge of URL escaping, 
 * it does not recognise equivalence between the encoded or decoded form of the same URL.
 * For example, the two URLs:
 * <blockquote><pre>
 *
 *   http://foo.com/hello world/ and http://foo.com/hello%20world
 * </pre></blockquote>
 * would be considered not equal to each other. 
 * <p>
 * Note, the URI class does perform escaping of its component
 * fields in certain circumstances. The recommended way to manage the encoding 
 * and decoding of URLs is to use URI, and to convert between these two classes 
 * using toURI() and URI::toURL(). 
 *
 * @ingroup net
 * @author  nverbove
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT URL
{
public:


/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * Creates an uninitialized URL
	 */
	URL();


    /**
     * Creates a <code>URL</code> object from the <code>WString</code>
     * representation. 
     *
     * @param      spec   the <code>std::string</code> to parse as a URL.
     * @exception  MalformedURLException  If the string specifies an
     *               unknown protocol.
     */

	URL(const WString& url);

    /** 
     * Creates a URL by parsing the given spec within a specified context. 
     *
     * The new URL is created from the given context URL and the spec
     * argument as described in RFC2396 &quot;Uniform Resource Identifiers : Generic
     * Syntax&quot; :
     * <blockquote><pre>
     *          &lt;scheme&gt;://&lt;authority&gt;&lt;path&gt;?&lt;query&gt;#&lt;fragment&gt;
     * </pre></blockquote>
     * The reference is parsed into the scheme, authority, path, query and
     * fragment parts. If the path component is empty and the scheme,
     * authority, and query components are undefined, then the new URL is a
     * reference to the current document. Otherwise the any fragment and query
     * parts present in the spec are used in the new URL.
     * 
     * If the scheme component is defined in the given spec and does not match
     * the scheme of the context, then the new URL is created as an absolute
     * URL based on the spec alone. Otherwise the scheme component is inherited
     * from the context URL.
     *
     * If the authority component is present in the spec then the spec is
     * treated as absolute and the spec authority and path will replace the
     * context authority and path. If the authority component is absent in the
     * spec then the authority of the new URL will be inherited from the
     * context.
     *
     * If the spec's path component begins with a slash character &quot;/&quot; then the
     * path is treated as absolute and the spec path replaces the context path.
     * Otherwise the path is treated as a relative path and is appended to the
     * context path. The path is canonicalized through the removal of directory
     * changes made by occurrences of &quot;..&quot; and &quot;.&quot;.
     * 
     * For a more detailed description of URL parsing, refer to RFC2396.
     *
     * @param      context   the context in which to parse the specification.
     * @param      spec      the <code>WString</code> to parse as a URL.
     * @exception  MalformedURLException  if no protocol is specified, or an
     *               unknown protocol is found.
     */

	URL(const WString& baseURL, const WString& relativeURL);

    /** 
     * Creates a URL by parsing the given spec within a specified context. 
     *
     * The new URL is created from the given context URL and the spec
     * argument as described in RFC2396 &quot;Uniform Resource Identifiers : Generic
     * Syntax&quot; :
     * <blockquote><pre>
     *          &lt;scheme&gt;://&lt;authority&gt;&lt;path&gt;?&lt;query&gt;#&lt;fragment&gt;
     * </pre></blockquote>
     * The reference is parsed into the scheme, authority, path, query and
     * fragment parts. If the path component is empty and the scheme,
     * authority, and query components are undefined, then the new URL is a
     * reference to the current document. Otherwise the any fragment and query
     * parts present in the spec are used in the new URL.
     * 
     * If the scheme component is defined in the given spec and does not match
     * the scheme of the context, then the new URL is created as an absolute
     * URL based on the spec alone. Otherwise the scheme component is inherited
     * from the context URL.
     *
     * If the authority component is present in the spec then the spec is
     * treated as absolute and the spec authority and path will replace the
     * context authority and path. If the authority component is absent in the
     * spec then the authority of the new URL will be inherited from the
     * context.
     *
     * If the spec's path component begins with a slash character &quot;/&quot; then the
     * path is treated as absolute and the spec path replaces the context path.
     * Otherwise the path is treated as a relative path and is appended to the
     * context path. The path is canonicalized through the removal of directory
     * changes made by occurrences of &quot;..&quot; and &quot;.&quot;.
     * 
     * For a more detailed description of URL parsing, refer to RFC2396.
     *
     * @param      context   the context in which to parse the specification.
     * @param      spec      the <code>WString</code> to parse as a URL.
     * @exception  MalformedURLException  if no protocol is specified, or an
     *               unknown protocol is found.
     */

	URL(const URL& baseURL, const WString& relativeURL);

	/**
	 * copy constructor
	 */
	URL(const URL& url);

	/**
	 * Assignment operator
	 */
	URL& operator=(const URL& url);

    /** 
     * Creates a <code>URL</code> object from the specified 
     * <code>protocol</code>, <code>host</code>, <code>port</code> 
     * number, and <code>file</code>. Specifying a <code>port</code> 
     * number of <code>-1</code> indicates that the URL should use 
     * the default port for the protocol. 
     * <p>
     * If this is the first URL object being created with the specified 
     * protocol, a <i>stream protocol handler</i> object, an instance of 
     * class <code>URLStreamHandler</code>, is created for that protocol:
     * <ol>
     * <li>If the application has previously set up an instance of
     *     <code>URLStreamHandlerFactory</code> as the stream handler factory,
     *     then the <code>createURLStreamHandler</code> method of that instance
     *     is called with the protocol string as an argument to create the
     *     stream protocol handler.
     * </ol>
     *
     * @param      protocol   the name of the protocol to use.
     * @param      host       the name of the host.
     * @param      port       the port number on the host.
     * @param      file       the file on the host
     * @exception  MalformedURLException  if an unknown protocol is specified.
     * @see        PlatformUtils#getProperty()
     * @see        URL#setURLStreamHandlerFactory(URLStreamHandlerFactory*)
     * @see        URLStreamHandler
     * @see        URLStreamHandlerFactory#createURLStreamHandler(WString)
     */

	URL(WString protocol, WString host, int port, WString file);

    /** 
     * Creates a <code>URL</code> object from the specified 
     * <code>protocol</code>, <code>host</code>, <code>port</code> 
     * number, <code>file</code>, and <code>handler</code>. Specifying
     * a <code>port</code> number of <code>-1</code> indicates that
     * the URL should use the default port for the protocol. Specifying
     * a <code>handler</code> of <code>null</code> indicates that the URL
     * should use a default stream handler for the protocol, as outlined
     * for:
     *     create(WString, WString, int, WString)
     *
     * @param      protocol   the name of the protocol to use.
     * @param      host       the name of the host.
     * @param      port       the port number on the host.
     * @param      file       the file on the host
     * @param	   handler    the stream handler for the URL.
     * @see        PlatformUtils#getProperty()
     * @see        URL#setURLStreamHandlerFactory(URLStreamHandlerFactory*)
     * @see        URLStreamHandler
     * @see        URLStreamHandlerFactory#createURLStreamHandler(WString)
     */
	URL(WString protocol, WString host, int port,WString file, URLStreamHandler* handler);

    /** 
     * Creates a URL from the specified <code>protocol</code> 
     * name, <code>host</code> name, and <code>file</code> name. The 
     * default port for the specified protocol is used. 
     * <p>
     * This method is equivalent to calling the four-argument 
     * create with the arguments being <code>protocol</code>, 
     * <code>host</code>, <code>-1</code>, and <code>file</code>. 
     *
     * @param      protocol   the name of the protocol to use.
     * @param      host       the name of the host.
     * @param      file       the file on the host.
     * @exception  MalformedURLException  if an unknown protocol is specified.
     * @see URL#create(WString, WString, int, WString)
     */

	URL(WString protocol, WString host, WString file);

/*@}*/ 

/** 
 * @name Create methods - the same as constructors. 
 * 
 * Used for compatibility with the previous versions
 */
/*@{*/

	 /**
     * Creates a <code>URL</code> object from the <code>WString</code>
     * representation. 
     *
     * @param      url   the <code>std::string</code> to parse as a URL.
     * @exception  MalformedURLException  If the string specifies an
     *               unknown protocol.
     */

	 void create(const WString& url);

	 /** 
     * Creates a <code>URL</code> object from the specified 
     * <code>protocol</code>, <code>host</code>, <code>port</code> 
     * number, and <code>file</code>. Specifying a <code>port</code> 
     * number of <code>-1</code> indicates that the URL should use 
     * the default port for the protocol. 
     * <p>
     * If this is the first URL object being created with the specified 
     * protocol, a <i>stream protocol handler</i> object, an instance of 
     * class <code>URLStreamHandler</code>, is created for that protocol:
     * <ol>
     * <li>If the application has previously set up an instance of
     *     <code>URLStreamHandlerFactory</code> as the stream handler factory,
     *     then the <code>createURLStreamHandler</code> method of that instance
     *     is called with the protocol string as an argument to create the
     *     stream protocol handler.
     * </ol>
     *
     * @param      protocol   the name of the protocol to use.
     * @param      host       the name of the host.
     * @param      port       the port number on the host.
     * @param      file       the file on the host
     * @exception  MalformedURLException  if an unknown protocol is specified.
     * @see        PlatformUtils#getProperty()
     * @see        URL#setURLStreamHandlerFactory(URLStreamHandlerFactory*)
     * @see        URLStreamHandler
     * @see        URLStreamHandlerFactory#createURLStreamHandler(WString)
     */

	void create(WString protocol, WString host, int port, WString file);

    /** 
     * Creates a <code>URL</code> object from the specified 
     * <code>protocol</code>, <code>host</code>, <code>port</code> 
     * number, <code>file</code>, and <code>handler</code>. Specifying
     * a <code>port</code> number of <code>-1</code> indicates that
     * the URL should use the default port for the protocol. Specifying
     * a <code>handler</code> of <code>null</code> indicates that the URL
     * should use a default stream handler for the protocol, as outlined
     * for:
     *     create(WString, WString, int, WString)
     *
     * @param      protocol   the name of the protocol to use.
     * @param      host       the name of the host.
     * @param      port       the port number on the host.
     * @param      file       the file on the host
     * @param	   handler    the stream handler for the URL.
     * @see        PlatformUtils#getProperty()
     * @see        URL#setURLStreamHandlerFactory(URLStreamHandlerFactory*)
     * @see        URLStreamHandler
     * @see        URLStreamHandlerFactory#createURLStreamHandler(WString)
     */
	void create(WString protocol, WString host, int port,WString file, URLStreamHandler* handler);

    /** 
     * Creates a URL from the specified <code>protocol</code> 
     * name, <code>host</code> name, and <code>file</code> name. The 
     * default port for the specified protocol is used. 
     * <p>
     * This method is equivalent to calling the four-argument 
     * create with the arguments being <code>protocol</code>, 
     * <code>host</code>, <code>-1</code>, and <code>file</code>. 
     *
     * @param      protocol   the name of the protocol to use.
     * @param      host       the name of the host.
     * @param      file       the file on the host.
     * @exception  MalformedURLException  if an unknown protocol is specified.
     * @see URL#create(WString, WString, int, WString)
     */

	void create(WString protocol, WString host, WString file);

/*@}*/ 


/** 
 * @name Setter methods
 */
/*@{*/


	/**
     * Sets this URL to the URL specified by the <code>WString</code>
     * representation. 
     *
     * @param      spec   the <code>std::string</code> to parse as a URL.
     * @exception  MalformedURLException  If the string specifies an
     *               unknown protocol.
     */

	void setURL(const WString& url);

    /** 
     * Sets this URL by parsing the given spec within a specified context. 
     *
     * The new URL is created from the given context URL and the spec
     * argument as described in RFC2396 &quot;Uniform Resource Identifiers : Generic
     * Syntax&quot; :
     * <blockquote><pre>
     *          &lt;scheme&gt;://&lt;authority&gt;&lt;path&gt;?&lt;query&gt;#&lt;fragment&gt;
     * </pre></blockquote>
     * The reference is parsed into the scheme, authority, path, query and
     * fragment parts. If the path component is empty and the scheme,
     * authority, and query components are undefined, then the new URL is a
     * reference to the current document. Otherwise the any fragment and query
     * parts present in the spec are used in the new URL.
     * 
     * If the scheme component is defined in the given spec and does not match
     * the scheme of the context, then the new URL is created as an absolute
     * URL based on the spec alone. Otherwise the scheme component is inherited
     * from the context URL.
     *
     * If the authority component is present in the spec then the spec is
     * treated as absolute and the spec authority and path will replace the
     * context authority and path. If the authority component is absent in the
     * spec then the authority of the new URL will be inherited from the
     * context.
     *
     * If the spec's path component begins with a slash character &quot;/&quot; then the
     * path is treated as absolute and the spec path replaces the context path.
     * Otherwise the path is treated as a relative path and is appended to the
     * context path. The path is canonicalized through the removal of directory
     * changes made by occurrences of &quot;..&quot; and &quot;.&quot;.
     * 
     * For a more detailed description of URL parsing, refer to RFC2396.
     *
     * @param      baseURL     the context in which to parse the specification.
     * @param      relativeURL the <code>WString</code> to parse as a URL.
     * @exception  MalformedURLException  if no protocol is specified, or an
     *               unknown protocol is found.
     */
	void setURL(const WString& baseURL, const WString& relativeURL);


	    /** 
     * Sets this URL by parsing the given spec within a specified context. 
     *
     * The new URL is created from the given context URL and the spec
     * argument as described in RFC2396 &quot;Uniform Resource Identifiers : Generic
     * Syntax&quot; :
     * <blockquote><pre>
     *          &lt;scheme&gt;://&lt;authority&gt;&lt;path&gt;?&lt;query&gt;#&lt;fragment&gt;
     * </pre></blockquote>
     * The reference is parsed into the scheme, authority, path, query and
     * fragment parts. If the path component is empty and the scheme,
     * authority, and query components are undefined, then the new URL is a
     * reference to the current document. Otherwise the any fragment and query
     * parts present in the spec are used in the new URL.
     * 
     * If the scheme component is defined in the given spec and does not match
     * the scheme of the context, then the new URL is created as an absolute
     * URL based on the spec alone. Otherwise the scheme component is inherited
     * from the context URL.
     *
     * If the authority component is present in the spec then the spec is
     * treated as absolute and the spec authority and path will replace the
     * context authority and path. If the authority component is absent in the
     * spec then the authority of the new URL will be inherited from the
     * context.
     *
     * If the spec's path component begins with a slash character &quot;/&quot; then the
     * path is treated as absolute and the spec path replaces the context path.
     * Otherwise the path is treated as a relative path and is appended to the
     * context path. The path is canonicalized through the removal of directory
     * changes made by occurrences of &quot;..&quot; and &quot;.&quot;.
     * 
     * For a more detailed description of URL parsing, refer to RFC2396.
     *
     * @param      baseURL     the URL context in which to parse the specification.
     * @param      relativeURL the <code>WString</code> to parse as a URL.
     * @exception  MalformedURLException  if no protocol is specified, or an
     *               unknown protocol is found.
     */
	void setURL(const URL& baseURL, const WString& relativeURL);

/*@}*/ 

	void makeRelativeTo(const WString&  baseURL);
	void makeRelativeTo(const URL& baseURL);

    /**
     * Returns the authority part of this <code>URL</code>.
     *
     * @return  the authority part of this <code>URL</code>.
     */

	WString getAuthority() const;

    /**
     * Returns the file name of this <code>URL</code>.
     *
     * @return  the file name of this <code>URL</code>.
     */

	WString getFile() const;

    /**
     * Returns the host name of this <code>URL</code>, if applicable.
     *
     * @return  the host name of this <code>URL</code>.
     */

	WString getHost() const;

    /**
     * Returns the path part of this <code>URL</code>.
     *
     * @return  the path part of this <code>URL</code>.
     */

	WString getPath() const;

    /**
     * Returns the port number of this <code>URL</code>.
     * Returns -1 if the port is not set.
     *
     * @return  the port number
     */

	int getPort() const;

    /**
     * Returns the protocol name of this <code>URL</code>.
     *
     * @return  the protocol of this <code>URL</code>.
     */

	WString getProtocol() const;

    /**
     * Returns the query part of this <code>URL</code>.
     *
     * @return  the query part of this <code>URL</code>.
     */

	WString getQuery() const;

    /**
     * Returns the anchor (also known as the "reference") of this
     * <code>URL</code>.
     *
     * @return  the anchor (also known as the "reference") of this
     *          <code>URL</code>.
     */

	WString getRef() const;

    /**
     * Returns the user part of this <code>URL</code>.
     *
     * @return  the user part of this <code>URL</code>.
     */

	WString getUser() const;

	    /**
     * Returns the password part of this <code>URL</code>.
     *
     * @return  the user part of this <code>URL</code>.
     */

	WString getPassword() const;


    /** 
     * Returns a <code>URLConnection</code> object that represents a 
     * connection to the remote object referred to by the <code>URL</code>.
     *
     * <p>A new connection is opened every time by calling the
     * <code>openConnection</code> method of the protocol handler for
     * this URL.
     *
     * @return a <code>URLConnection</code> to the URL.
     * @exception  IOException  if an I/O exception occurs.
     * @see URL#create(WString, WString, int, WString)
     * @see URLConnection
     * @see URLStreamHandler#openConnection(URL*) 
     */

	URLConnection* openConnection();

    /**
     * Compares two URLs, excluding the "ref" fields.
     * Returns <code>true</code> if this <code>URL</code> and the 
     * <code>other</code> argument both refer to the same resource.
     * The two <code>URL</code>s might not both contain the same anchor. 
     *
     * @param   other   the <code>URL</code> to compare against.
     * @return  <code>true</code> if they reference the same remote object;
     *          <code>false</code> otherwise.
     */
	bool sameFile(const URL& other);

    /** 
     * Compares two URLs.  The result is <code>true</code> if and
     * only if the argument  is a
     * <code>URL</code> object that represents the same
     * <code>URL</code> as this object. Two URL objects are equal if
     * they have the same protocol and reference the same host, the
     * same port number on the host, and the same file and anchor on
     * the host.
     *
     * @param   obj   the URL to compare against.
     * @return  <code>true</code> if the objects are the same;
     *          <code>false</code> otherwise.
     */
	bool operator==(const URL& url);


    /**
     * Constructs a string representation of this <code>URL</code>. The 
     * string is created by calling the <code>toExternalForm</code> 
     * method of the stream protocol handler for this object. 
     *
     * @return  a string representation of this object.
     * @see  URL#create(WString,WString, int, WString)
     * @see  URLStreamHandler#toExternalForm(URL)
     */
	WString toExternalForm() const ;

    /**
     * Constructs a string representation of this <code>URL</code>. The 
     * string is created by calling the <code>toExternalForm</code> 
     * method of the stream protocol handler for this object. 
     *
     * @return  a string representation of this object.
     * @see  URL#create(WString,WString, int, WString)
     * @see  URLStreamHandler#toExternalForm(URL)
     */
	WString toString() const;

	/**
	 * Tests whether this URL is relative.                                                                      
	 */
	bool isRelative() const;

    /**
	 * Returns a URI equivalent to this URL. 
	 * This method functions in the same way as new URI (this.toString()). 
     *
     * Note, any URL instance that complies with RFC 2396 can be converted to a URI.
	 * However, some URLs that are not strictly in compliance can not be converted to 
	 * a URI. 
	 *
     * @return  A URI constructed from this URL
     *
     * @exception  IllegalArgumentException
     *             If this URL is not absolute
     *
     * @exception  MalformedURLException
     *             If some other error occurred while constructing the URI
     */	
	URI toURI() const;

    /**
     * Sets an application's <code>URLStreamHandlerFactory</code>.
     * This method can be called at most once in a given Java Virtual
     * Machine.
     *
     *<p> The <code>URLStreamHandlerFactory</code> instance is used to
     *construct a stream protocol handler from a protocol name.
     * 
     *
     * @param      fac   the desired factory.
     * @exception  Error  if the application has already set a factory.
     * @see        URL#create(std::string, std::string, 
     *             int, std::string)
     * @see        URLStreamHandlerFactory
     */

	static void setURLStreamHandlerFactory(URLStreamHandlerFactory* fac);


protected:

	void initialize(WString protocol, WString host, int port, WString file, URLStreamHandler* handler);

	static void terminate();

private:

	void parse(WString url);
	bool conglomerateWithBase(const URL& baseURL);

    /**
     * A  private constructor that takes all URL components.
     *
     * No validation of the inputs is performed by this constructor.
     *
     * @param   protocol  Protocol name
     * @param   opaquePart
     * @param   userInfo  User name and authorization information
     * @param   host      Host name
     * @param   port      Port number
     * @param   path      Path
     * @param   query     Query
     * @param   ref       Fragment
     * @exception  MalformedURLException  if an unknown protocol is specified.
     */
	URL(WString protocol, WString opaquePart, WString userInfo, WString host, int port, WString path, WString query, WString fragment, URLStreamHandler* handler);

    /*
     * Returns true if specified string is a valid protocol name.
     */

	bool isValidProtocol(WString protocol);

    /** 
     * The protocol to use (ftp, http, nntp, ... etc.) . 
     */

	WString mProtocol;

    /** 
     * The host name in which to connect to. 
     */

	WString mHost;

    /** 
     * The protocol port to connect to. 
     */

	int mPort;

    /** 
     * The specified file name on that host. 
     */

	WString mFile;

    /** 
     * The query part of this URL. 
     */

	WString mQuery;

    /** 
     * The authority part of this URL. 
     */

	WString mAuthority;

    /** 
     * The path part of this URL. 
     */

	WString mPath;

    /** 
     * The userinfo part of this URL. 
     */

	WString mUser;

    /** 
     * The password part of this URL. 
     */

	WString mPassword;

    /** 
     * # reference. 
     */

	WString mFragment;

    /**
     * The URLStreamHandler for this URL.
	 * Stored as a AutoPtr, since the same handler can be shared between different
	 * URL's
     */

	AutoPtr<URLStreamHandler> mHandler;

   /**
     * The URLStreamHandler factory.
     */
	static URLStreamHandlerFactory* mFactory;

    /**
     * Returns the Stream Handler.
     * @param protocol the protocol to use
     */

	static URLStreamHandler* getURLStreamHandler(WString protocol);

	friend class URLStreamHandler;
	friend class URI;
	friend class PlatformUtils; 
};

/** @example TestURL.cpp
 * This is an example of how to use the URL to read an URL resource 
 * and write it out to disk. This example shows how you can change
 * the Authenticator for a URL and open a URLConnection.
 */


/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_URL_H */
