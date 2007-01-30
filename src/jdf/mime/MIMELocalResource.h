/******************************************************************************
 *                     Copyright 2001 Agfa-Gevaert N.V.                       *
 *                           All rights reserved                              *
 *                                                                            *
 * The material contained herein may not be reproduced in whole or in part,   *
 *        without the prior written consent of Agfa-Gevaert N.V.              *
 *                                                                            *
 ******************************************************************************/

#ifndef I_JDF_MIMELOCALRESOURCE_H
#define I_JDF_MIMELOCALRESOURCE_H


/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <jdf/lang/JDFToolsDefs.h>
#include <jdf/mime/MIMEResource.h>
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

class JDFTOOLS_EXPORT MIMELocalResource : public MIMEResource
{
public:

	MIMELocalResource(const File& f); 
	~MIMELocalResource();

	InputStream* getInputStream();
	OutputStream* getOutputStream();

private:

	File mResFile;
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_MIMELOCALRESOURCE_H */

/* end of file */
