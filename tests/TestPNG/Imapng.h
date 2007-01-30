/*
 * File:	ImaPNG.h
 * Purpose:	Declaration of the PNG Image Class
 * Author:	Alejandro Aguilar Sierra
 * Created:	1995
 * Copyright:	(c) 1995, Alejandro Aguilar Sierra <asierra@servidor.unam.mx>
 *
 *
 */
#if !defined(__ImaPNG_h)
#define __ImaPNG_h

#include "imafile.h"

#if CIMAGE_SUPPORT_PNG
class CImagePNG: public CFileImageImpl
{
protected:
  CImageImpl *imabg;

public:
  CImagePNG(const CImagePNG * ima): CFileImageImpl(ima) { imabg=0; }
  CImagePNG(const CString& imageFileName ): CFileImageImpl(imageFileName) { imabg=0; }
  ~CImagePNG() {};

  BOOL ReadFile(const CString& imageFileName="");
  BOOL SaveFile(const CString& imageFileName="");

//  SetBackground(int r, int g, int b);
  void SetBackground(CImageImpl* bg) { imabg = bg; }
};

#endif

#endif

