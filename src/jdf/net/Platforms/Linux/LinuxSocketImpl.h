/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2004 The International Cooperation for the Integration of 
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
 * copyright (c) 2004, Heidelberger Druckmaschinen AG 
 * copyright (c) 2004, Agfa-Gevaert N.V. 
 *  
 * For more information on The International Cooperation for the 
 * Integration of Processes in  Prepress, Press and Postpress , please see
 * <http://www.cip4.org/>.
 *  
 * 
 */

/******************************************************************************
 *              Copyright 2004 Heidelberger Druckmaschinen AG                 *
 *                           All rights reserved                              *
 *                                                                            *
 * The material contained herein may not be reproduced in whole or in part,   *
 *   without the prior written consent of Heidelberger Druckmaschinen AG      *
 *                                                                            *
 ******************************************************************************/

#ifndef I_JDF_LINUXSOCKETIMPL_H
#define I_JDF_LINUXSOCKETIMPL_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <jdf/lang/JDFToolsDefs.h>
#include <jdf/net/InetAddress.h>
#include <jdf/net/Exception.h>
#include <jdf/net/SocketImpl.h>
#include <jdf/net/Platforms/Linux/SocketProxy.h>


namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 

class LinuxSocketImplInputStream;
class LinuxSocketImplOutputStream;

/******************************************************************************
 *	Classes
 ******************************************************************************/ 

class JDFTOOLS_EXPORT LinuxSocketImpl : public SocketImpl
{
public:
    typedef enum 
    {
        WAITFORREAD,	// accept or read socket
        WAITFORWRITE    // write socket
	} SocketWaitCondition;

public:
	LinuxSocketImpl();
	virtual ~LinuxSocketImpl();

public:
	virtual int  available(); // throws IOException;
	virtual void close(); // throws IOException

	virtual SocketImpl*   accept(); // throws IOException;
	virtual void          bind(const InetAddress& host, int port); // throws IOException;
	virtual void		  connect(const WString& host, int port); // throws IOException
	virtual void		  connect(const InetAddress& address, int port); // throws IOException
	virtual void		  create(bool stream); // throws IOException
	virtual void		  listen(int count); // throws IOException
    virtual int           getFileDescriptor();
	virtual InputStream&  getInputStream();
	virtual OutputStream& getOutputStream();
	virtual SocketOption  getOption(int optID); // throw SocketException
	virtual void          setOption(int optID, const SocketOption& value);

	// wait on a network condition
	// if cond is WAITFORREAD  wait on a read  condition (accept or read socket)
	// if cond is WAITFORWRITE wait on a write condition (write socket)

	void doWait(int timeout, SocketWaitCondition cond);

protected:
	bool		  m_bSocketTimeoutEnabled;
	InputStream*  m_pInputStream;
	int			  m_iSocketTimeout;
	OutputStream* m_pOutputStream;

private:
	LinuxSocketImpl(const LinuxSocketImpl&);
	LinuxSocketImpl& operator=(const LinuxSocketImpl&);
};

} // namespace JDF

#endif /* I_JDF_LINUXSOCKETIMPL_H */

/* end of file */
