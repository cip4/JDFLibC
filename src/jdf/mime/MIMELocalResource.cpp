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

#include <jdf/mime/MIMELocalResource.h>
#include <jdf/io/FileInputStream.h>
#include <jdf/io/FileOutputStream.h>
#include <jdf/io/BufferedOutputStream.h>
#include <jdf/io/BufferedInputStream.h>

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


MIMELocalResource::MIMELocalResource(const File& file) :
	mResFile(file)
{
}

MIMELocalResource::~MIMELocalResource()
{
}

InputStream* MIMELocalResource::getInputStream()
{
	return new BufferedInputStream(new FileInputStream(mResFile));
}

OutputStream* MIMELocalResource::getOutputStream()
{
	return new BufferedOutputStream(new FileOutputStream(mResFile));
}

} // namespace JDF

/* end of file */
