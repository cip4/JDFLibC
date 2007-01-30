/******************************************************************************
 *                     Copyright 2001 Agfa-Gevaert N.V.                       *
 *                           All rights reserved                              *
 *                                                                            *
 * The material contained herein may not be reproduced in whole or in part,   *
 *        without the prior written consent of Agfa-Gevaert N.V.              *
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <jdf/mime/MIMEMemResource.h>
#include <jdf/io/ByteArrayInputStream.h>
#include <jdf/io/ByteArrayOutputStream.h>
#include <jdf/lang/ByteBuffer.h>

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

class MIMEByteArrayOutputStream : public ByteArrayOutputStream
{
public:

	MIMEByteArrayOutputStream() {}
	MIMEByteArrayOutputStream(unsigned int size);
	void write(int b);
	void write(const char* b, int blen);
	void write(const char* b, int blen, int off, int len);
	ByteBuffer* byteArray();
};


/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

MIMEByteArrayOutputStream::MIMEByteArrayOutputStream(unsigned int size) :
	ByteArrayOutputStream(size)
{
}

void MIMEByteArrayOutputStream::write(int b)
{
	ByteArrayOutputStream::write(b);
}

void MIMEByteArrayOutputStream::write(const char* b, int blen)
{
	ByteArrayOutputStream::write(b,blen);
}

void MIMEByteArrayOutputStream::write(const char* b, int blen, int off, int len)
{
	ByteArrayOutputStream::write(b,blen,off,len);
}

ByteBuffer* MIMEByteArrayOutputStream::byteArray()
{
	// transfer of ownership
	ByteBuffer* tmp = mBuf;
	mBuf = NULL;
	return tmp;
}


MIMEMemResource::MIMEMemResource(const File& file) :
	mOut(NULL)
{
}

MIMEMemResource::~MIMEMemResource()
{
}

InputStream* MIMEMemResource::getInputStream()
{
	if (mOut == NULL)
		return NULL;

	ByteBuffer* buffer = mOut->byteArray();

	// pass ownership fo the byte buffer to this stream
	InputStream* stm = new ByteArrayInputStream(buffer->bytes(),buffer->size(),true);
	// clear ownership on the bytebuffer
	buffer->orphan();
	delete buffer;
	return stm;
}

OutputStream* MIMEMemResource::getOutputStream()
{
	mOut = new MIMEByteArrayOutputStream(64*1024);
	return mOut;
}

} // namespace JDF

/* end of file */

