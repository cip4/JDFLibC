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

#include <jdf/mime/MIMEMemResourceFactory.h>
#include <jdf/mime/MIMEMemResource.h>
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

MIMEMemResourceFactory::MIMEMemResourceFactory() 
{
}

MIMEResource* MIMEMemResourceFactory::createResource(const WString& res)
{
	return new MIMEMemResource(res);
}

} // namespace JDF

/* end of file */
