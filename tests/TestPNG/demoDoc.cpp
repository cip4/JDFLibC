// demoDoc.cpp : implementation of the CDemoDoc class
//

#include "stdafx.h"
#include "demo.h"

#include "demoDoc.h"
#include "cimage.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc

IMPLEMENT_DYNCREATE(CDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CDemoDoc)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, OnUpdateFileSaveAs)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_COMMAND(ID_STRETCH_MODE, OnStretchMode)
	ON_UPDATE_COMMAND_UI(ID_STRETCH_MODE, OnUpdateStretchMode)
	ON_COMMAND(ID_TRANSFORM_ELLIPSE, OnTransformEllipse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc construction/destruction

CDemoDoc::CDemoDoc()
{
	image = NULL;
	stretchMode = FALSE;
}

CDemoDoc::~CDemoDoc()
{
	delete image;
}

BOOL CDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	image = NULL;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc serialization

void CDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc diagnostics

#ifdef _DEBUG
void CDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoDoc commands

static CString FindExtension(const CString& name)
{
	int len = name.GetLength();
	int i;
	for (i = len-1; i >= 0; i--)
	{
		if (name[i] == '.')
		{
			return name.Mid(i+1);
		}
	}
	return CString("");
}

BOOL CDemoDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	CString filename(lpszPathName);
	CString ext(FindExtension(filename));
	ext.MakeLower();
	if (ext == "")
		return FALSE;

	int type = 0;
	if (ext == "jpg" || ext == "jpeg")
	{
		type = CIMAGE_FORMAT_JPEG;
	}
	else if (ext == "gif")
	{
		type = CIMAGE_FORMAT_GIF;
	}
	else if (ext == "png")
	{
		type = CIMAGE_FORMAT_PNG;
	}
	else if (ext == "bmp")
	{
		type = CIMAGE_FORMAT_BMP;
	}
	else
		return FALSE;

	image = new CImage(filename, type);
	if (image->GetWidth() <= 0 || image->GetHeight() <= 0)
	{
		delete image;
		image = NULL;
		return FALSE;
	}

	return TRUE;
}

BOOL CDemoDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	CString filename(lpszPathName);
	CString ext(FindExtension(filename));
	ext.MakeLower();
	if (ext == "")
		return FALSE;

	int type = 0;
	if (ext == "jpg" || ext == "jpeg")
	{
		type = CIMAGE_FORMAT_JPEG;
	}
	else if (ext == "gif")
	{
		type = CIMAGE_FORMAT_GIF;
	}
	else if (ext == "png")
	{
		type = CIMAGE_FORMAT_PNG;
	}
	else if (ext == "bmp")
	{
		type = CIMAGE_FORMAT_BMP;
	}
	else
		return FALSE;

	if (image)
		return image->SaveFile(filename, type);
	else
		return FALSE;
}

BOOL CDemoDoc::DoSave(LPCTSTR pszPathName, BOOL bReplace /*=TRUE*/)
{
	if (!image)
		return FALSE;

	CString newName = pszPathName;
	BOOL bModified = IsModified();

	BOOL bSaveAs = FALSE;
	if (newName.IsEmpty())
		bSaveAs = TRUE;
	else if (!theApp.GetWritableType(image->GetFileType()))
		bSaveAs = TRUE;

	if (bSaveAs)
	{
		newName = m_strPathName;
		if (bReplace && newName.IsEmpty())
		{
			newName = m_strTitle;
			int iBad = newName.FindOneOf(_T(" #%;/\\"));    // dubious filename
			if (iBad != -1)
				newName.ReleaseBuffer(iBad);

			// append the default suffix if there is one
			newName += theApp.GetExtFromType(image->GetFileType());
		}

		int nDocType = image->GetFileType();
		if (!theApp.PromptForFileName(newName, 
			bReplace ? AFX_IDS_SAVEFILE : AFX_IDS_SAVEFILECOPY,
			OFN_HIDEREADONLY | OFN_PATHMUSTEXIST, FALSE, &nDocType))
		{
			return FALSE;       // don't even try to save
		}
	}

	BeginWaitCursor();
	if (!OnSaveDocument(newName))
	{
		if (pszPathName == NULL)
		{
			// be sure to delete the file
			TRY 
			{
				CFile::Remove(newName);
			}
			CATCH_ALL(e)
			{
				TRACE0("Warning: failed to delete file after failed SaveAs\n");
			}
			END_CATCH_ALL
		}
		EndWaitCursor();
		return FALSE;
	}

	EndWaitCursor();
	if (bReplace)
	{
		// Reset the title and change the document name
		SetPathName(newName, TRUE);
		ASSERT(m_strPathName == newName);       // must be set
	}
	else // SaveCopyAs
	{
		SetModifiedFlag(bModified);
	}
	return TRUE;        // success
}


#define EPSILON (0.0000001)

int CDemoDoc::ComputePixel(float x, float y, float &x1, float &y1)
{
  float r, nn;

  if (x==0 && y==0) {
	 x1 = x;
	 y1 = y;
	 return 1;
  }

  nn = (float)sqrt(x*x + y*y);
  r = (float) (fabs(x) > fabs(y)) ? fabs(nn/x): fabs(nn/y);

  x1 = (r*x);
  y1 = (r*y);

  return 1;
}

void CDemoDoc::ComputeNewImage(void)
{
  CWaitCursor wait;
  int x, y, x1, y1;
  float fx, fy, xmid, ymid, ar;
  CImage *image2 = new CImage(image);

  xmid = (float) (image->GetWidth()/2.0);
  ymid = (float) (image->GetHeight()/2.0);
  ar = (float)(image->GetHeight())/(float)(image->GetWidth());
  for (y=0; y<image->GetHeight(); y++) {
	 for (x=0; x<image->GetWidth(); x++) {
		ComputePixel(ar*(x-xmid), y-ymid, fx, fy);
		x1 = (int)(xmid+fx/ar);
		y1 = (int)(ymid+fy);
		if (image->Inside(x1, y1))
		  image2->SetIndex(x, y, image->GetIndex(x1, y1));
		else
		  image2->SetIndex(x, y, 0);
	 }
  }
  delete image;
  image = image2;
  UpdateAllViews(NULL);
}

void CDemoDoc::OnUpdateFileSaveAs(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((image != NULL));
}

void CDemoDoc::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((image != NULL) &&
		theApp.GetWritableType(image->GetFileType()));
}

void CDemoDoc::OnStretchMode() 
{
	stretchMode = !stretchMode;
	UpdateAllViews(NULL);
}

void CDemoDoc::OnUpdateStretchMode(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(stretchMode);
	pCmdUI->Enable(TRUE);
}

void CDemoDoc::OnTransformEllipse() 
{
	ComputeNewImage();
	UpdateAllViews(NULL);
}
