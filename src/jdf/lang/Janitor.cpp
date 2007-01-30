/******************************************************************************
 *                     Copyright 1998 Agfa-Gevaert N.V.                       *
 *                           All rights reserved                              *
 *                                                                            *
 * The material contained herein may not be reproduced in whole or in part,   *
 *        without the prior written consent of Agfa-Gevaert N.V.              *
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#if defined(JDF_TMPLSINC)
#include <jdf/lang/JDFToolsDefs.h>
#include <jdf/lang/Janitor.h>
#endif

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
#if 0
template <class T> Janitor<T>::Janitor(T* const objToDelete) :  fData(objToDelete)
{
}

template <class T> Janitor<T>::~Janitor()
{
    delete fData;
}

template <class T> void Janitor<T>::orphan()
{
    fData = 0;
}

template <class T> ArrayJanitor<T>::ArrayJanitor(T* const objToDelete) :

    fData(objToDelete)
{
}

template <class T> ArrayJanitor<T>::~ArrayJanitor()
{
    delete [] fData;
}


template <class T> void ArrayJanitor<T>::orphan()
{
    fData = 0;
}
#endif


} //namespace JDF

