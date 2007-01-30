/*
 * File:	imapng.cc
 * Purpose:	Platform Independent JPEG Image Class
 * Author:	Alejandro Aguilar Sierra
 * Created:	1995
 * Copyright: (c) 1995, Alejandro Aguilar Sierra <asierra@servidor.unam.mx>
 *
 *      logjmp
 */

// #include "stdafx.h"

#include "imapng.h"
#if CIMAGE_SUPPORT_PNG

#include "imaiter.h"
#include <jdf/png/PNGFile.h>
#include <jdf/png/PNGFile.h>
#include <jdf/io/FileInputStream.h>
#include <jdf/io/FileOutputStream.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


BOOL
CImagePNG::ReadFile(const CString& imageFileName)
{
	JDF::PNGFile     pngFile;
	JDF::FileInputStream fin((char *const )((LPCTSTR) imageFileName));

	pngFile.open(fin);

	void *row_pointers;

	JDF::PNGInfo pngInfo=pngFile.getInfo();

	Create(pngInfo.m_imageWidth, pngInfo.m_imageHeight, pngInfo.m_bitDepth ,-1);
	
	CImageIterator iter(this);
	iter.Upset();
	
	row_pointers = pngFile.allocRow();

	do	{
		pngFile.readRow((void*&)row_pointers);
		iter.SetRow((unsigned char*) row_pointers, pngInfo.rowSize());
	} while(iter.PrevRow());

	if (row_pointers) delete[] row_pointers;


	return TRUE;
}

/* write a png file */

BOOL CImagePNG::SaveFile(const CString& imageFileName)
{
	if (imageFileName != "")
		filename = imageFileName;

	JDF::FileOutputStream  fout((char *const )((LPCTSTR) imageFileName));

	JDF::PNGInfo pngInfo;            
//	pngInfo.m_bytesPerRow = GetWidth() * ((GetDepth()+7)>>3);
	pngInfo.m_imageWidth  = GetWidth();
	pngInfo.m_imageHeight = GetHeight();
	pngInfo.m_bitDepth    = GetDepth(); //  /=Channels

	JDF::PNGFile pngFile;
	pngFile.open(fout,pngInfo);

	unsigned char *row_pointers = (unsigned char *) pngFile.allocRow();
	
	CImageIterator iter(this);
  	iter.Upset();
	do	
	{
	  iter.GetRow(row_pointers, pngInfo.rowSize());
	  pngFile.writeRow(row_pointers);
	} 
	while(iter.PrevRow());
    delete [] row_pointers;

	return TRUE;
}


#endif // CIMAGE_SUPPORT_PNG

