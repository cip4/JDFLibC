/******************************************************************************
 *                     Copyright 2001 Agfa-Gevaert N.V.                       *
 *                           All rights reserved                              *
 *                                                                            *
 * The material contained herein may not be reproduced in whole or in part,   *
 *        without the prior written consent of Agfa-Gevaert N.V.              *
 *                                                                            *
 ******************************************************************************/

#ifndef I_JDF_MIMELOCALRESOURCEFACTORY_H
#define I_JDF_MIMELOCALRESOURCEFACTORY_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <jdf/lang/JDFToolsDefs.h>
#include <jdf/mime/MIMEResourceFactory.h>
#include <jdf/io/File.h>

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

class JDFTOOLS_EXPORT MIMELocalResourceFactory : public MIMEResourceFactory
{
public:

	MIMELocalResourceFactory(const File& targetDir);

	MIMEResource* createResource(const WString& res);

private:

	File mTargetDir;
	int  mCount;
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_MIMELOCALRESOURCEFACTORY_H */

/* end of file */
