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

#ifndef I_JDF_URI_H
#define I_JDF_URI_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <jdf/lang/WString.h>
#include <jdf/lang/AutoPtr.h>

namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 

class URL;

/******************************************************************************
 *	Defines and constants
 ******************************************************************************/ 


/******************************************************************************
 *	Typedefs
 ******************************************************************************/ 


/******************************************************************************
 *	Classes
 ******************************************************************************/ 


class JDFTOOLS_EXPORT URI
{
public:

    /**
     * Construct a new URI from a URI specification string.
     *
     * If the specification follows the "generic URI" syntax, (two slashes
     * following the first colon), the specification will be parsed
     * accordingly - setting the
     *                           scheme,
     *                           userinfo,
     *                           host,
     *                           port,
     *                           path,
     *                           querystring and
     *                           fragment
     * fields as necessary.
     *
     * If the specification does not follow the "generic URI" syntax,
     * the specification is parsed into a
     *                           scheme and
     *                           scheme-specific part (stored as the path) only.
     *
     * @param uriSpec the URI specification string (cannot be  empty)
     */
	URI(const WString& uriSpec);

    /**
     * Construct a new URI from a base URI and a URI specification string.
     * The URI specification string may be a relative URI.
     *
     * @param baseURI the base URI (cannot be empty)
     * @param uriSpec the URI specification string (cannot be empty)
     */
	URI(const URI& baseURI,const WString& uriSpec);

    /**
     * Copy constructor
     */
	URI(const URI& uri);
	URI& operator=(const URI& uri);

	virtual ~URI();

    /**
     * Returns the content of this URI as a string.
     *
     * If this URI was created by invoking one of the constructors in this
     * class then a string equivalent to the original input string, or to the
     * string computed from the originally-given components, as appropriate, is
     * returned.  Otherwise this URI was created by normalization, resolution,
     * or relativization, and so a string is constructed from this URI's
     * components according to the rules specified in <a
     * href="http://www.ietf.org/rfc/rfc2396.txt">RFC&nbsp;2396</a>,
     * section&nbsp;5.2, step&nbsp;7.
     *
     * @return  The string form of this URI
     */
	WString toString() const;

// component access methods

    /**
     * Returns the scheme component of this URI.
     *
     * The scheme component of a URI, if defined, only contains characters
     * in the <i>alphanum</i> category and in the string <tt>"-.+"</tt>.  A
     * scheme always starts with an <i>alpha</i> character. 
     *
     * The scheme component of a URI cannot contain escaped octets, hence this
     * method does not perform any decoding.  
     *
     * @return  The scheme component of this URI,
     *          or <code>null</code> if the scheme is undefined
     */
	WString getScheme() const;

    /**
     * Tells whether or not this URI is absolute.
     *
     * A URI is absolute if, and only if, it has a scheme component.
     *
     * @return  <code>true</code> if, and only if, this URI is absolute
     */
    bool isAbsolute() const;

   /**
     * Tells whether or not this URI is opaque.
     *
     * An opaque URI is not parsed beyond the scheme component.  
	 * The remainder of an opaque URI may be retrieved via the 
     * <code>getSchemeSpecificPart()</code> all other components are undefined.
     *
     * @return  <code>true</code> if, and only if, this URI is opaque
     */
	bool isOpaque() const;


    /**
     * Returns the raw scheme-specific part of this URI.  The scheme-specific
     * part is never undefined, though it may be empty.
     * 
     * The scheme-specific part of a URI only contains legal URI
     * characters.
     *
     * @return  The raw scheme-specific part of this URI
     *  
     */
    WString getRawSchemeSpecificPart() const;


    /**
     * Returns the decoded scheme-specific part of this URI.
     *
     * The string returned by this method is equal to that returned by the
     * <code>getRawSchemeSpecificPart()</code> method
     * except that all sequences of escaped octets are decoded.
     *
     * @return  The decoded scheme-specific part of this URI
     */
    WString getSchemeSpecificPart() const;

    /**
     * Returns the raw user-information component of this URI.
     *
     * The user-information component of a URI, if defined, only contains
     * characters in the <i>unreserved</i>, <i>punct</i>, <i>escaped</i>, and
     * <i>other</i> categories. </p>
     *
     * @return  The raw user-information component of this URI,
     *          or an empty string if the user information is undefined
     */
    WString getRawUserInfo() const;

    /**
     * Returns the decoded user-information component of this URI.
     *
     * The string returned by this method is equal to that returned by the
     * <code>getRawUserInfo()</code> method except that all
     * sequences of escaped octets are decoded
     *
     * @return  The decoded user-information component of this URI,
     *          or an empty string if the user information is undefined
     */
	WString getUserInfo() const;

    /**
     * Returns the host component of this URI.
     *
     * The host component of a URI, if defined, will have one of the
     * following forms: 
     *
     * <ul type=disc>
     *
     *   <li><p> A domain name consisting of one or more <i>labels</i>
     *   separated by period characters (<tt>'.'</tt>), optionally followed by
     *   a period character.  Each label consists of <i>alphanum</i> characters
     *   as well as hyphen characters (<tt>'-'</tt>), though hyphens never
     *   occur as the first or last characters in a label.  The last, or only,
     *   label in a domain name begins with an <i>alpha</i>
     *   character. </p></li>
     *
     *   <li><p> A dotted-quad IPv4 address of the form
     *   <i>digit</i><tt>+.</tt><i>digit</i><tt>+.</tt><i>digit</i><tt>+.</tt><i>digit</i><tt>+</tt>,
     *   where no <i>digit</i> sequence is longer than three characters and no
     *   sequence has a value larger than 255. </p></li>
     *
     *   <li><p> An IPv6 address enclosed in square brackets (<tt>'['</tt> and
     *   <tt>']'</tt>) and consisting of hexadecimal digits, colon characters
     *   (<tt>':'</tt>), and possibly an embedded IPv4 address.  The full
     *   syntax of IPv6 addresses is specified in <a
     *   href="http://www.ietf.org/rfc/rfc2373.txt"><i>RFC&nbsp;2373: IPv6
     *   Addressing Architecture</i></a>.  </p></li>
     *
     * </ul>
     *
     * The host component of a URI cannot contain escaped octets, hence this
     * method does not perform any decoding.  
     *
     * @return  The host component of this URI,
     *          or an empty string if the host is undefined
     */
    WString getHost() const;

	WString getRawHost() const;

    /**
     * Returns the port number of this URI.
     *
     * The port component of a URI, if defined, is a non-negative
     * integer.
     *
     * @return  The port component of this URI,
     *          or <code>-1</code> if the port is undefined
     */
	int getPort() const;

    /**
     * Returns the raw path component of this URI.
     *
     * The path component of a URI, if defined, only contains the slash
     * character (<code>'/'</code>), the commercial-at character (<code>'@'</code>),
     * and characters in the <i>unreserved</i>, <i>punct</i>, <i>escaped</i>,
     * and <i>other</i> categories. </p>
     *
     * @return  The path component of this URI,
     *          or an empty string if the path is undefined
     */
    WString getRawPath() const;

    /**
     * Returns the decoded path component of this URI.
     *
     * The string returned by this method is equal to that returned by the
     * <code>getRawPath()</code> method except that all sequences of
     * escaped octets are decoded
     *
     * @return  The decoded path component of this URI,
     *          or an empty string if the path is undefined
     */
    WString getPath() const;

    /**
     * Returns the raw query component of this URI.
     *
     * The query component of a URI, if defined, only contains legal URI
     * characters.
     *
     * @return  The raw query component of this URI,
     *          or an empty string if the query is undefined
     */
    WString getRawQuery() const;

    /**
     * Returns the decoded query component of this URI.
     *
     * The string returned by this method is equal to that returned by the
     * getRawQuery() method except that all sequences of escaped octets are
	 * decoded.
     *
     * @return  The decoded query component of this URI,
     *          or an empty string if the query is undefined
     */
    WString getQuery() const;

    /**
     * Returns the raw fragment component of this URI.
     *
     * The fragment component of a URI, if defined, only contains legal URI
     * characters.
     *
     * @return  The raw fragment component of this URI,
     *          or an empty string if the fragment is undefined
     */
    WString getRawFragment() const;

    /**
     * Returns the decoded fragment component of this URI.
     *
     * The string returned by this method is equal to that returned by the
     * <code>getRawFragment()</code> method except that all
     * sequences of escaped octets are decoded.
     *
     * @return  The decoded fragment component of this URI,
     *          or an empty string if the fragment is undefined
     */
    WString getFragment() const;

    /**
     * Get the registry based authority for this URI.
     * 
     * @return the registry based authority or an empty string if the fragment is undefined
     */

	WString getRawRegBasedAuthority() const;

    /**
     * Get the decoded registry based authority for this URI.
     * 
     * @return the decoded registry based authority or an empty string if the fragment is undefined
     */
    WString getRegBasedAuthority() const;

    /**
     * Set the scheme for this URI. The scheme is converted to lowercase
     * before it is set.
     *
     * @param newScheme the scheme for this URI (cannot be null)
     *
     */
    void setScheme(const WString&  newScheme);

    /**
     * Set the userinfo for this URI. If a non-null value is passed in and
     * the host value is null, then an exception is thrown.
     *
     * @param newUserInfo the userinfo for this URI
     *
     */
    void setUserInfo(const WString& newUserInfo);

    /**
     * Set the host for this URI. If null is passed in, the userinfo
     * field is also set to null and the port is set to -1.
     *
     * @param newHost the host for this URI
     *
     */
    void setHost(const WString&  newHost);

    /**
     * Set the port for this URI. -1 is used to indicate that the port is
     * not specified, otherwise valid port numbers are  between 0 and 65535.
     * If a valid port number is passed in and the host field is null,
     * an exception is thrown.
     *
     * @param newPort the port number for this URI
     *
     */
	void setPort(int newPort);

    /**
     * Set the query string for this URI. A non-null value is valid only
     * if this is an URI conforming to the generic URI syntax and
     * the path value is not null.
     *
     * @param newQueryString the query string for this URI
     *
     */
     void setQueryString(const WString& newQueryString);

    /**
     * Set the fragment for this URI. A non-null value is valid only
     * if this is a URI conforming to the generic URI syntax and
     * the path value is not null.
     *
     * @param newFragment the fragment for this URI
     *
     */
     void setFragment(const WString& newFragment);


    /**
     * Sets the registry based authority for this URI.
     * 
     * Note: This method overwrites server based authority
     * if it previously existed in this URI.
     * 
     * @param newRegAuth the registry based authority for this URI
     */
     void setRegBasedAuthority(const WString& newRegAuth);

    /**
     * Set the path for this URI.
     *
     * If the supplied path is null, then the
     * query string and fragment are set to null as well.
     *
     * If the supplied path includes a query string and/or fragment,
     * these fields will be parsed and set as well.
     *
     * Note:
     *
     * For URIs following the "generic URI" syntax, the path
     * specified should start with a slash.
     *
     * For URIs that do not follow the generic URI syntax, this method
     * sets the scheme-specific part.
     *
     * @param newPath the path for this URI (may be null)
     *
     */
     void setPath(const WString& newPath);

    /**
     * Constructs a URL from this URI.
     *
     * <p> This convenience method works as if invoking it were equivalent to
     * evaluating the expression <tt>new&nbsp;URL(this.toString())</tt> after
     * first checking that this URI is absolute. </p>
     *
     * @return  A URL constructed from this URI
     *
     * @throws  IllegalArgumentException
     *          If this URL is not absolute
     *
     * @throws  MalformedURLException
     *          If a protocol handler for the URL could not be found,
     *          or if some other error occurred while constructing the URL
     */
	URL toURL() const;

private:

    static const JDFCh RESERVED_CHARACTERS[];
    static const JDFCh MARK_CHARACTERS[];
	static const JDFCh MARK_OR_RESERVED_CHARACTERS[];
    static const JDFCh SCHEME_CHARACTERS[];
    static const JDFCh USERINFO_CHARACTERS[];
	static const JDFCh REG_NAME_CHARACTERS[];
	static const JDFCh PATH_CHARACTERS[];


	void buildFullText();


    /**
     * Initialize all fields of this URI from another URI.
     *
     * @param src the URI to copy 
     */
    void initialize(const URI& src);

   /**
     * Initializes this URI from a base URI and a URI specification string.
     * See RFC 2396 Section 4 and Appendix B for specifications on parsing
     * the URI and Section 5 for specifications on resolving relative URIs
     * and relative paths.
     *
     * @param baseURI the base URI (may be null if uriSpec is an absolute
     *               URI)
     *
     * @param uriSpec the URI spec string which may be an absolute or
     *                  relative URI (can only be /empty if base
     *                  is not NULL)
     *
     */
    void initialize(const URI* const baseURI
                   , const WString& uriSpec);

	/**
     * Determine whether a character is a reserved character:
     *
     * @return true if the string contains any reserved characters
     */
	static bool isReservedCharacter(const JDFCh ch);

    /**
     * Determine whether a character is a path character:
     *
     * @return true if the character is path character
     */
    static bool isPathCharacter(const JDFCh theChar);

    /**
     * Determine whether a char is an unreserved character.
     *
     * @return true if the char is unreserved, false otherwise
     */
	static bool isUnreservedCharacter(const JDFCh theChar);

    /**
     * Determine whether a char is an reserved or unreserved character.
     *
     * @return true if the char is reserved or unreserved, false otherwise
     */                
    static bool isReservedOrUnreservedCharacter(const JDFCh theChar);

   /**
     * Initialize the scheme for this URI from a URI string spec.
     *
     * @param uriSpec the URI specification (cannot be null)
     *
     */
	void initializeScheme(const WString& uriSpec);

    /**
     * Initialize the authority (userinfo, host and port) for this
     * URI from a URI string spec.
     *
     * @param uriSpec the URI specification (cannot be null)
     *
     */
	void initializeAuthority(const WString& uriSpec);

    /**
     * Initialize the path for this URI from a URI string spec.
     *
     * @param uriSpec the URI specification (cannot be null)
     *
     */
    void initializePath(const WString& uriSpec);

	void initializeSchemeSpecificPart(const WString&  uriSpec);

    /**
     * Determine whether a scheme conforms to the rules for a scheme name.
     * A scheme is conformant if it starts with an alphanumeric, and
     * contains only alphanumerics, '+','-' and '.'.
     *
     * @return true if the scheme is conformant, false otherwise
     */
    static bool isConformantSchemeName(const WString& scheme);

    /**
     * Determine whether a userInfo conforms to the rules for a userinfo.
     *
     * @return true if the scheme is conformant, false otherwise
     */
    static void isConformantUserInfo(const WString& userInfo);

    /**
     * Determines whether the components host, port, and user info
     * are valid as a server authority.
     *
     * @return true if the given host, port, and userinfo compose
     * a valid server authority
     */
    static bool isValidServerBasedAuthority(const WString& host
                                           , const int port
                                           , const WString& userinfo);

      
   /**
    * Determines whether the given string is a registry based authority.
    * 
    * @param authority the authority component of a URI
    * 
    * @return true if the given string is a registry based authority
    */
    static bool isValidRegistryBasedAuthority(const WString& authority);

    /**
     * Determine whether a string is syntactically capable of representing
     * a valid IPv4 address or the domain name of a network host.
     *
     * A valid IPv4 address consists of four decimal digit groups
     * separated by a '.'.
     *
     * A hostname consists of domain labels (each of which must begin and
     * end with an alphanumeric but may contain '-') separated by a '.'.
     * See RFC 2396 Section 3.2.2.
     *
     * @return true if the string is a syntactically valid IPv4 address
     *              or hostname
     */
    static bool isWellFormedAddress(const WString& addr);

    /**
     * Determines whether a string is an IPv4 address as defined by 
     * RFC 2373, and under the further constraint that it must be a 32-bit
     * address. Though not expressed in the grammar, in order to satisfy 
     * the 32-bit address constraint, each segment of the address cannot 
     * be greater than 255 (8 bits of information).
     *
     * @return true if the string is a syntactically valid IPv4 address
     */
     static bool isWellFormedIPv4Address(const JDFCh* const addr, const int length);
     
    /**
     * Determines whether a string is an IPv6 reference as defined
     * by RFC 2732, where IPv6address is defined in RFC 2373. The 
     * IPv6 address is parsed according to Section 2.2 of RFC 2373,
     * with the additional constraint that the address be composed of
     * 128 bits of information.
     *
     * Note: The BNF expressed in RFC 2373 Appendix B does not 
     * accurately describe section 2.2, and was in fact removed from
     * RFC 3513, the successor of RFC 2373.
     *
     * @return true if the string is a syntactically valid IPv6 reference
     */
     static bool isWellFormedIPv6Reference(const JDFCh* const addr, const int length);
     
    /**
     * Helper function for isWellFormedIPv6Reference which scans the 
     * hex sequences of an IPv6 address. It returns the index of the 
     * next character to scan in the address, or -1 if the string 
     * cannot match a valid IPv6 address. 
     *
     * @param address the string to be scanned
     * @param index the beginning index (inclusive)
     * @param end the ending index (exclusive)
     * @param counter a counter for the number of 16-bit sections read
     * in the address
     *
     * @return the index of the next character to scan, or -1 if the
     * string cannot match a valid IPv6 address
     */
     static int scanHexSequence (const JDFCh* const addr, int index, int end, int& counter);

    /**
     * Determine whether a given string contains only URI characters (also
     * called "uric" in RFC 2396). uric consist of all reserved
     * characters, unreserved characters and escaped characters.
     *
     * @return true if the string is comprised of uric, false otherwise
     */
    static bool isURIString(const WString& uric);

   /**
     * Get the indicator as to whether this URI uses the "generic URI"
     * syntax.
     *
     * @return true if this URI uses the "generic URI" syntax, false
     *         otherwise
     */
     bool isGenericURI() const;


	WString	mScheme; 
	WString mUserInfo;
	WString mHost;    
	unsigned int  mPort;    
	WString mPath;	 
	WString mQueryString;
	WString mFragment;
	WString mSchemeSpecificPart;
	WString mRegAuth;

	mutable WString mDecodedUserInfo;
	mutable WString mDecodedHost;
	mutable WString mDecodedPath;
	mutable WString mDecodedQueryString;
	mutable WString mDecodedFragment;
	mutable WString mDecodedSchemeSpecificPart;
	mutable WString mDecodedRegAuth;

	WString mURIText;
};

inline int URI::getPort() const
{
	return mPort;
}



inline WString URI::toString() const
{
    //
    //  Fault it in if not already. Since this is a const method and we
    //  can't use mutable members due the compilers we have to support,
    //  we have to cast off the constness.
    //
    if (mURIText.length() == 0)
        ((URI*)this)->buildFullText();

    return mURIText;
}


/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_URI_H */
