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

#ifndef I_JDF_PosixSOCKETIMPL_H
#define I_JDF_PosixSOCKETIMPL_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <jdf/lang/JDFToolsDefs.h>
#include <jdf/net/InetAddress.h>
#include <jdf/net/SocketImpl.h>
#include <jdf/lang/Exception.h>
#include <jdf/net/Platforms/Posix/SocketProxy.h>

namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 

class PosixSocketImplInputStream;
class PosixSocketImplOutputStream;

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
 * Implementation of Socket for Windows based on BSD socket 
 *
 * @author nverbove     
 * @internal
 */

class JDFTOOLS_EXPORT PosixSocketImpl : public SocketImpl
{
public:

	///////////////////////////////////////////////////////////////////////////
	// Public Constructors
	///////////////////////////////////////////////////////////////////////////

	         PosixSocketImpl();
	virtual ~PosixSocketImpl();

public:

	///////////////////////////////////////////////////////////////////////////
	// Protected Instance Methods
	///////////////////////////////////////////////////////////////////////////


	virtual size_t available();// throws IOException;
	virtual void close(); // throws IOException

	virtual SocketImpl*   accept(); // throws IOException;
	virtual void          bind(const InetAddress& host, int port); // throws IOException;
	virtual void		  connect(const WString& host, int port); // throws IOException
	virtual void		  connect(const InetAddress& address, int port); // throws IOException
	virtual void		  create(bool stream); // throws IOException
	virtual void		  listen(int count); // throws IOException
	virtual InputStream&  getInputStream();
	virtual OutputStream& getOutputStream();
	virtual SocketOption  getOption(int optID); // throw SocketException
	virtual void          setOption(int optID, const SocketOption& value);
    
	typedef enum {

			WAITFORREAD,	// accept or read socket
			WAITFORWRITE    // write socket

	} SocketWaitCondition;

	// wait on a network condition
	// if cond is 0 wait on a read condition, (accept or read socket)
	// if cond is 1 wait on a write condition ( write socket)

	void doWait(int timeout,SocketWaitCondition cond);

protected:

	///////////////////////////////////////////////////////////////////////////
	// Protected Instance Variables
	///////////////////////////////////////////////////////////////////////////

	int			  mSocketTimeout;
	bool		  mSocketTimeoutEnabled;
	InputStream*  mInputStream;
	OutputStream* mOutputStream;

private:

	//
	// Hide copy constructor and assignment operator.
	//

	PosixSocketImpl(const PosixSocketImpl&);
	PosixSocketImpl& operator=(const PosixSocketImpl&);

    friend class PosixSocketImplInputStream;
    friend class PosixSocketImplOutputStream;
};


/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_PosixSOCKETIMPL_H */


/* end of file */