/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2006 The International Cooperation for the Integration of 
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

#ifndef I_JDF_URLCONNECTION_H
#define I_JDF_URLCONNECTION_H


/******************************************************************************
 *	Includes
 ******************************************************************************/ 
#include "URL.h"


namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 
	class InputStream;
	class OutputStream;
	class FileNameMap;

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
 * The abstract class <code>URLConnection</code> is the superclass 
 * of all classes that represent a communications link between the 
 * application and a URL. Instances of this class can be used both to 
 * read from and to write to the resource referenced by the URL. In 
 * general, creating a connection to a URL is a multistep process: 
 * <p>
 * <center><table border=2>
 * <tr><th><code>openConnection()</code></th>
 *     <th><code>connect()</code></th></tr>
 * <tr><td>Manipulate parameters that affect the connection to the remote 
 *         resource.</td>
 *     <td>Interact with the resource; query header fields and
 *         contents.</td></tr>
 * </table>
 * ----------------------------&gt;
 * <br>time</center>
 *
 * <ol>
 * <li>The connection object is created by invoking the
 *     <code>openConnection</code> method on a URL.
 * <li>The setup parameters and general request properties are manipulated.
 * <li>The actual connection to the remote object is made, using the
 *    <code>connect</code> method.
 * <li>The remote object becomes available. The header fields and the contents
 *     of the remote object can be accessed.
 * </ol>
 * <p>
 * The setup parameters are modified using the following methods: 
 * <ul>
 *   <li><code>setAllowUserInteraction</code>
 *   <li><code>setDoInput</code>
 *   <li><code>setDoOutput</code>
 *   <li><code>setIfModifiedSince</code>
 *   <li><code>setUseCaches</code>
 * </ul>
 * <p>
 * and the general request properties are modified using the method:
 * <ul>
 *   <li><code>setRequestProperty</code>
 * </ul>
 * <p>
 * Default values for the <code>AllowUserInteraction</code> and 
 * <code>UseCaches</code> parameters can be set using the methods 
 * <code>setDefaultAllowUserInteraction</code> and 
 * <code>setDefaultUseCaches</code>.
 * <p>
 * Each of the above <code>set</code> methods has a corresponding 
 * <code>get</code> method to retrieve the value of the parameter or 
 * general request property. The specific parameters and general 
 * request properties that are applicable are protocol specific. 
 * <p>
 * The following methods are used to access the header fields and 
 * the contents after the connection is made to the remote object:
 * <ul>
 *   <li><code>getContent</code>
 *   <li><code>getHeaderField</code>
 *   <li><code>getInputStream</code>
 *   <li><code>getOutputStream</code>
 * </ul>
 * <p>
 * Certain header fields are accessed frequently. The methods:
 * <ul>
 *   <li><code>getContentEncoding</code>
 *   <li><code>getContentLength</code>
 *   <li><code>getContentType</code>
 *   <li><code>getDate</code>
 *   <li><code>getExpiration</code>
 *   <li><code>getLastModifed</code>
 * </ul>
 * <p>
 * provide convenient access to these fields. The 
 * <code>getContentType</code> method is used by the 
 * <code>getContent</code> method to determine the type of the remote 
 * object; subclasses may find it convenient to override the 
 * <code>getContentType</code> method. 
 * <p>
 * In the common case, all of the pre-connection parameters and 
 * general request properties can be ignored: the pre-connection 
 * parameters and request properties default to sensible values. For 
 * most clients of this interface, there are only two interesting 
 * methods: <code>getInputStream</code> and <code>getObject</code>, 
 * which are mirrored in the <code>URL</code> class by convenience methods.
 * <p>
 * More information on the request properties and header fields of 
 * an <code>http</code> connection can be found at:
 * <blockquote><pre>
 * <a href="http://www.ietf.org/rfc/rfc2068.txt">http://www.ietf.org/rfc/rfc2068.txt</a>
 * </pre></blockquote>
 *
 * @ingroup net
 * @author  nverbove
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT URLConnection
{
protected:

/** 
 * @name Constructors
 */
/*@{*/
    /**
     * Constructs a URL connection to the specified URL. A connection to 
     * the object referenced by the URL is not created. 
     *
     * @param url the specified URL.
     */

	URLConnection(const URL& url);

/*@}*/ 

public:

	virtual ~URLConnection();

	typedef std::pair<bool, WString> value_pair;

    /**
     * Opens a communications link to the resource referenced by this 
     * URL, if such a connection has not already been established. 
     * <p>
     * If the <code>connect</code> method is called when the connection 
     * has already been opened (indicated by the <code>connected</code> 
     * field having the value <code>true</code>), the call is ignored. 
     * <p>
     * URLConnection objects go through two phases: first they are
     * created, then they are connected.  After being created, and
     * before being connected, various options can be specified
     * (e.g., doInput and UseCaches).  After connecting, it is an
     * error to try to set them.  Operations that depend on being
     * connected, like getContentLength, will implicitly perform the
     * connection, if necessary.
     *
     * @exception  IOException  if an I/O error occurs while opening the
     *               connection.
     * @see URLConnection#connected 
	 */

	virtual void connect() = 0;

    /**
     * Returns the value of the <code>allowUserInteraction</code> field for
     * this object.
     *
     * @return  the value of the <code>allowUserInteraction</code> field for
     *          this object.
     * @see     URLConnection#setAllowUserInteraction(bool)
     */

	virtual bool getAllowUserInteraction();

    /**
     * Returns the value of the <code>content-encoding</code> header field.
     *
     * @return  the content encoding of the resource that the URL references,
     *          or <code>null</code> if not known.
     * @see     URLConnection#getHeaderField(WString)
     */
	virtual WString getContentEncoding();

    /**
     * Returns the value of the <code>content-length</code> header field.
     *
     * @return  the content length of the resource that this connection's URL
     *          references, or <code>-1</code> if the content length is
     *          not known.
     */

	virtual int getContentLength();

    /**
     * Returns the value of the <code>content-type</code> header field.
     *
     * @return  the content type of the resource that the URL references,
     *          or <code>null</code> if not known.
     * @see  URLConnection#getHeaderField(WString)
     */

	virtual WString getContentType();

    /**
     * Returns the value of the <code>date</code> header field. 
     *
     * @return  the sending date of the resource that the URL references,
     *          or <code>0</code> if not known. The value returned is the
     *          number of milliseconds since January 1, 1970 GMT.
     * @see URLConnection#getHeaderField(std::string)
     */

	virtual long getDate();

    /**
     * Sets the default value of the 
     * <code>allowUserInteraction</code> field for all future 
     * <code>URLConnection</code> objects to the specified value. 
     *
     * @param   defaultallowuserinteraction   the new value.
     * @see URLConnection#getDefaultAllowUserInteraction()
     */
	static bool getDefaultAllowUserInteraction();

   /**
     * Returns the default value of a <code>URLConnection</code>'s
     * <code>useCaches</code> flag.
     * <p>
     * Ths default is "sticky", being a part of the static state of all
     * URLConnections.  This flag applies to the next, and all following
     * URLConnections that are created.
     *
     * @return  the default value of a <code>URLConnection</code>'s
     *          <code>useCaches</code> flag.
     * @see URLConnection#setDefaultUseCaches(bool)
     */

	virtual bool getDefaultUseCaches();

    /**
     * Returns the value of this <code>URLConnection</code>'s
     * <code>doInput</code> flag.
     *
     * @return  the value of this <code>URLConnection</code>'s
     *          <code>doInput</code> flag.
     * @see URLConnection#setDoInput(bool)
     */

	virtual bool getDoInput();

    /**
     * Returns the value of this <code>URLConnection</code>'s
     * <code>doOutput</code> flag.
     *
     * @return  the value of this <code>URLConnection</code>'s
     *          <code>doOutput</code> flag.
     * @see URLConnections#setDoOutput(bool)
     */

	virtual bool getDoOutput();


    /**
     * Returns the value of the <code>expires</code> header field. 
     *
     * @return  the expiration date of the resource that this URL references,
     *          or 0 if not known. The value is the number of milliseconds since
     *          January 1, 1970 GMT.
     * @see URLConnection#getHeaderField(WString)
     */

	virtual long getExpiration();

    /**
     * Returns the value for the <code>n</code><sup>th</sup> header field. 
     * It returns <code>(false,"")</code> if there are fewer than 
     * <code>n</code> fields. 
     * <p>
     * This method can be used in conjunction with the 
     * <code>getHeaderFieldKey</code> method to iterate through all 
     * the headers in the message. 
     *
     * @param   n   an index.
     * @return  (true,value) containing the value of the <code>n</code><sup>th</sup> header field.
     * @see  URLConnection#getHeaderFieldKey(int)
     */

	virtual value_pair getHeaderField(int n);

    /**
     * Returns the value of the specified header field.
     *
     * @param   name   the name of a header field.
     * @return  (true,value) containing the named header field, or <code>(false,"")</code>
     *          if there is no such field in the header.
     */

	virtual value_pair getHeaderField(const WString& name);

    /**
     * Returns the key for the <code>n</code><sup>th</sup> header field.
     *
     * @param   n   an index.
     * @return  (true,key) containing the key for the <code>n</code><sup>th</sup> header field,
     *          or <code>(false,"")</code> if there are fewer than <code>n</code>
     *          fields.
     */
	virtual value_pair getHeaderFieldKey(int n);

    /**
     * Returns the value of the named field parsed as a number.
     * <p>
     * This form of <code>getHeaderField</code> exists because some 
     * connection types (e.g., <code>http-ng</code>) have pre-parsed 
     * headers. Classes for that connection type can override this method 
     * and short-circuit the parsing. 
     *
     * @param   name      the name of the header field.
     * @param   Default   the default value.
     * @return  the value of the named field, parsed as an integer. The
     *          <code>Default</code> value is returned if the field is
     *          missing or malformed.
     */

	int getHeaderFieldInt(const WString& name, int Default);

    /**
     * Returns the value of this object's <code>ifModifiedSince</code> field.
     *
     * @return  the value of this object's <code>ifModifiedSince</code> field.
     * @see URLConnection#setIfModifiedSince(long)
     */

	virtual long getIfModifiedSince();


    /**
     * Returns an input stream that reads from this open connection.
     *
     * @return     an input stream that reads from this open connection.
     * @exception  IOException if an I/O error occurs while
     *               creating the input stream.
     * @exception  UnknownServiceException  if the protocol does not support
     *               input.
     */
	virtual InputStream& getInputStream();

    /**
     * Returns an output stream that writes to this connection.
     *
     * @return     an output stream that writes to this connection.
     * @exception  IOException if an I/O error occurs while
     *               creating the output stream.
     * @exception  UnknownServiceException  if the protocol does not support
     *               output.
     */

	virtual OutputStream& getOutputStream();

    /**
     * Returns the value of the <code>last-modified</code> header field. 
     * The result is the number of milliseconds since January 1, 1970 GMT.
     *
     * @return  the date the resource referenced by this
     *          <code>URLConnection</code> was last modified, or 0 if not known.
     * @see URLConnection#getHeaderField(std::string)
     */

	virtual long getLastModified();

    /**
     * Returns the value of the named general request property for this
     * connection.
     *
     * @param key the keyword by which the request is known (e.g., "accept").
     * @return  the value of the named general request property for this
     *           connection.
     * @see URLConnection#setRequestProperty(WString, WString)
     */

	virtual WString getRequestProperty(const WString& key);

    /**
     * Returns the value of this <code>URLConnection</code>'s <code>URL</code>
     * field.
     *
     * @return  the value of this <code>URLConnection</code>'s <code>URL</code>
     *          field.
     * @see URLConnection#url
     */

	virtual URL getURL();

    /**
     * Returns the value of this <code>URLConnection</code>'s
     * <code>useCaches</code> field.
     *
     * @return  the value of this <code>URLConnection</code>'s
     *          <code>useCaches</code> field.
     * @see URLConnection#setUseCaches(bool)
     */

	virtual bool getUseCaches();

    /**
     * Set the value of the <code>allowUserInteraction</code> field of 
     * this <code>URLConnection</code>. 
     *
     * @param   allowuserinteraction   the new value.
     * @see URLConnection#getAllowUserInteraction()
     */

	virtual void setAllowUserInteraction(bool allowUserInteraction);

    /**
     * Sets the value of the <code>doInput</code> field for this 
     * <code>URLConnection</code> to the specified value. 
     * <p>
     * A URL connection can be used for input and/or output.  Set the DoInput
     * flag to true if you intend to use the URL connection for input,
     * false if not.  The default is true unless DoOutput is explicitly
     * set to true, in which case DoInput defaults to false.
     *
     * @param   doinput   the new value.
     * @see     URLConnection#doInput
     * @see URLConnection#getDoInput()
     */

	virtual void setDoInput(bool doinput);

    /**
     * Sets the value of the <code>doOutput</code> field for this 
     * <code>URLConnection</code> to the specified value. 
     * <p>
     * A URL connection can be used for input and/or output.  Set the DoOutput
     * flag to true if you intend to use the URL connection for output,
     * false if not.  The default is false.
     *
     * @param   dooutput   the new value.
     * @see URLConnection#getDoOutput()
     */

	virtual void setDoOutput(bool dooutput);

    /**
     * Sets the value of the <code>ifModifiedSince</code> field of 
     * this <code>URLConnection</code> to the specified value.
     *
     * @param   ifmodifiedsince   the new value.
     * @see URLConnection#getIfModifiedSince()
     */

	virtual void setIfModifiedSince(long ifmodifiedsince);

    /**
     * Sets the general request property. If a property with the key already
     * exists, overwrite its value with the new value.
     *
     * <p> NOTE: HTTP requires all request properties which can
     * legally have multiple instances with the same key
     * to use a comma-seperated list syntax which enables multiple
     * properties to be appended into a single property.
     *
     * @param   key     the keyword by which the request is known
     *                  (e.g., "<code>accept</code>").
     * @param   value   the value associated with it.
     * @see URLConnection#getRequestProperty(WString)
     */
	virtual void setRequestProperty(const WString& key, const WString& value);

    /**
     * Sets the value of the <code>useCaches</code> field of this 
     * <code>URLConnection</code> to the specified value. 
     * <p>
     * Some protocols do caching of documents.  Occasionally, it is important
     * to be able to "tunnel through" and ignore the caches (e.g., the
     * "reload" button in a browser).  If the UseCaches flag on a connection
     * is true, the connection is allowed to use whatever caches it can.
     *  If false, caches are to be ignored.
     *  The default value comes from DefaultUseCaches, which defaults to
     * true.
     *
     * @param usecaches a <code>boolean</code> indicating whether 
     * or not to allow caching
     * @see URLConnection#getUseCaches()
     */
	virtual void setUseCaches(bool usecaches);

	/**
	 * Sets a timeout on the URL Connection in milliseconds
	 * With this option set to a non-zero timeout, a <code>read()</code> call
	 * on the <code>UInputStream</code> associated with this URL will block for only 
	 * this amount of time. If the timeout expires, an <b>InterruptedIOException</b>
	 * is raised, though the URL is still valid.
	 * The option <b>must</b> be enabled prior to entering the blocking 
	 * operation to have effect. The timeout <b>must</b> be > 0. 
	 * A timeout of zero is interpreted as an infinite timeout.
	 * @param timeout timeout value in milliseconds
	 */
	virtual void setTimeout(int millis);

	/**
	 * Returns setting for timeout.
	 * 0 returns implies that the option is disabled (i.e., timeout of infinity).
	 */
	virtual int getTimeout();


    /**
     * Returns a <code>String</code> representation of this URL connection.
     *
     * @return a string representation of this <code>URLConnection</code>.
     */

	virtual WString toString();

    /**
     * Sets the default value of the 
     * <code>allowUserInteraction</code> field for all future 
     * <code>URLConnection</code> objects to the specified value. 
     *
     * @param   defaultallowuserinteraction   the new value.
     * @see URLConnection#getDefaultAllowUserInteraction()
     */

	static void setDefaultAllowUserInteraction(bool defaultallowuserinteraction);

   /**
     * Sets the default value of the <code>useCaches</code> field to the 
     * specified value. 
     *
     * @param   defaultusecaches   the new value.
     * @see     #getDefaultUseCaches()
     */

	static void setDefaultUseCaches(bool defaultusecaches);

    /**
     * Loads filename map (a mimetable) from a data file. It will
     * first try to load the user-specific table, defined
     * by &quot;content.types.user.table&quot; property. If that fails,
     * it tries to load the default built-in table .
     *
     * @return the FileNameMap
     * @see URLConnection#setFileNameMap
     */

    static FileNameMap* getFileNameMap();

    /**
     * Sets the FileNameMap.
     *
     * @param map the FileNameMap to be set
     * @see URLConnection#getFileNameMap()
     */
    static void setFileNameMap(FileNameMap* map);

    /**
     * Tries to determine the type of an input stream based on the 
     * characters at the beginning of the input stream. This method can 
     * be used by subclasses that override the 
     * <code>getContentType</code> method. 
     * <p>
     * Ideally, this routine would not be needed. But many 
     * <code>http</code> servers return the incorrect content type; in 
     * addition, there are many nonstandard extensions. Direct inspection 
     * of the bytes to determine the content type is often more accurate 
     * than believing the content type claimed by the <code>http</code> server.
     *
     * @param      is   an input stream that supports marks.
     * @return     a guess at the content type, or an empty string if none
     *             can be determined.
     * @exception  IOException  if an I/O error occurs while reading the
     *               input stream.
     * @see        InputStream#mark(int)
     * @see        InputStream#markSupported()
     * @see        URLConnection#getContentType()
     */

	static WString guessContentTypeFromStream(InputStream& is);

    /**
     * Tries to determine the content type of an object, based 
     * on the specified "file" component of a URL.
     * This is a convenience method that can be used by 
     * subclasses that override the <code>getContentType</code> method. 
     *
     * @param   fname   a filename.
     * @return  a guess as to what the content type of the object is,
     *          based upon its file name.
     * @see     URLConnection#getContentType()
     */
	static WString guessContentTypeFromName(WString fname);

protected:

   /**
     * If <code>true</code>, this <code>URL</code> is being examined in 
     * a context in which it makes sense to allow user interactions such 
     * as popping up an authentication dialog. If <code>false</code>, 
     * then no user interaction is allowed. 
     * <p>
     * The value of this field can be set by the 
     * <code>setAllowUserInteraction</code> method.
     * Its value is returned by the 
     * <code>getAllowUserInteraction</code> method.
     * Its default value is the value of the argument in the last invocation 
     * of the <code>setDefaultAllowUserInteraction</code> method. 
     *
     * @see URLConnection#getAllowUserInteraction()
     * @see URLConnection#setAllowUserInteraction(bool)
     * @see URLConnection#setDefaultAllowUserInteraction(bool)
     */

	bool allowUserInteraction;

   /**
     * If <code>false</code>, this connection object has not created a 
     * communications link to the specified URL. If <code>true</code>, 
     * the communications link has been established. 
     */

	bool connected;

   /**
     * This variable is set by the <code>setDoInput</code> method. Its 
     * value is returned by the <code>getDoInput</code> method. 
     * <p>
     * A URL connection can be used for input and/or output. Setting the 
     * <code>doInput</code> flag to <code>true</code> indicates that 
     * the application intends to read data from the URL connection. 
     * <p>
     * The default value of this field is <code>true</code>. 
     *
     * @see URLConnection#getDoInput()
     * @see URLConnection#setDoInput(bool)
     */

	bool doInput;

   /**
     * This variable is set by the <code>setDoOutput</code> method. Its 
     * value is returned by the <code>getDoInput</code> method. 
     * <p>
     * A URL connection can be used for input and/or output. Setting the 
     * <code>doOutput</code> flag to <code>true</code> indicates 
     * that the application intends to write data to the URL connection. 
     * <p>
     * The default value of this field is <code>false</code>. 
     *
     * @see URLConnection#getDoOutput()
     * @see URLConnection#setDoOutput(bool)
     */

	bool doOutput;

   /**
     * Some protocols support skipping the fetching of the object unless 
     * the object has been modified more recently than a certain time. 
     * <p>
     * A nonzero value gives a time as the number of milliseconds since 
     * January 1, 1970, GMT. The object is fetched only if it has been 
     * modified more recently than that time. 
     * <p>
     * This variable is set by the <code>setIfModifiedSince</code> 
     * method. Its value is returned by the 
     * <code>getIfModifiedSince</code> method.
     * <p>
     * The default value of this field is <code>0</code>, indicating 
     * that the fetching must always occur. 
     *
     * @see URLConnection#getIfModifiedSince()
     * @see URLConnection#setIfModifiedSince(long)
     */

	long ifModifiedSince;

	/**
     * The URL represents the remote object on the World Wide Web to 
     * which this connection is opened. 
     * <p>
     * The value of this field can be accessed by the 
     * <code>getURL</code> method. 
     * <p>
     * The default value of this variable is the value of the URL 
     * argument in the <code>URLConnection</code> constructor. 
     *
     * @see URLConnection#getURL()
     */

	URL  url;

   /**
     * If <code>true</code>, the protocol is allowed to use caching 
     * whenever it can. If <code>false</code>, the protocol must always 
     * try to get a fresh copy of the object. 
     * <p>
     * This field is set by the <code>setUseCaches</code> method. Its 
     * value is returned by the <code>getUseCaches</code> method.
     * <p>
     * Its default value is the value given in the last invocation of the 
     * <code>setDefaultUseCaches</code> method. 
     *
     * @see URLConnection#setUseCaches(bool)
     * @see URLConnection#getUseCaches()
     * @see URLConnection#setDefaultUseCaches(bool)
     */

	bool useCaches;

	static void terminate();

private:

	static bool defaultAllowUserInteraction;
	static bool defaultUseCaches;
	static FileNameMap* fileNameMap;

	friend class PlatformUtils;
};


/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_URLCONNECTION_H */
