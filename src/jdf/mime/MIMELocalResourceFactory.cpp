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

#include <jdf/mime/MIMELocalResourceFactory.h>
#include <jdf/mime/MIMELocalResource.h>
#include <jdf/lang/Integer.h>

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

MIMELocalResourceFactory::MIMELocalResourceFactory(const File& targetDir) :
	mTargetDir(targetDir),
	mCount(0)
{
}

MIMEResource* MIMELocalResourceFactory::createResource(const WString& res)
{
	File resFile;
	do
	{
		resFile = File(mTargetDir,WString("part") + Integer::toString(mCount++));
	}
	while (resFile.exists() == true);
	return new MIMELocalResource(resFile);
}

} // namespace JDF

/* end of file */
