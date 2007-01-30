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
	return new FileInputStream(mResFile);
}

OutputStream* MIMELocalResource::getOutputStream()
{
	return new FileOutputStream(mResFile);
}

} // namespace JDF

/* end of file */
