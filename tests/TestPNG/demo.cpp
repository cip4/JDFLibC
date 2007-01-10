// demo.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "demo.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "demoDoc.h"
#include "demoView.h"
#include "cimage.h"
#include <jdf/util/PlatformUtils.h>
#include <util/PlatformUtils.hpp>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define NUM_DOC_TYPES 4
DocType doctypes[NUM_DOC_TYPES] =
{
	{ CIMAGE_FORMAT_PNG, TRUE, TRUE, "PNG files", "png" }/*,

	{ CIMAGE_FORMAT_GIF, TRUE, FALSE, "GIF files", "gif" },
	{ CIMAGE_FORMAT_JPEG, TRUE, TRUE, "JPEG files", "jpg" },
	{ CIMAGE_FORMAT_BMP, TRUE, TRUE, "BMP files", "bmp" }
	//*/
};


/////////////////////////////////////////////////////////////////////////////
// CDemoApp

BEGIN_MESSAGE_MAP(CDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CDemoApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_IMAGE_FROM_BITMAP, OnImageFromBitmap)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CDemoApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoApp construction

CDemoApp::CDemoApp()
{
	m_nFilterIndex = 1;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDemoApp object

CDemoApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDemoApp initialization

BOOL CDemoApp::InitInstance()
{
	  // Initialize the XML4C2 system
    try
	{
        XMLPlatformUtils::Initialize();
    }
	catch(const XMLException&)
	{
        return 1;
    }
	
	// Initialize the JDFTools system
	try
	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)
	{
		return 1;
	}


	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
/*
	doctypes[0].nID = CIMAGE_FORMAT_GIF;
	doctypes[0].bRead = TRUE;
	doctypes[0].bWrite = FALSE;
	doctypes[0].description = "GIF files";
	doctypes[0].ext =".gif";

	doctypes[1].nID = CIMAGE_FORMAT_JPEG;
	doctypes[1].bRead = TRUE;
	doctypes[1].bWrite = TRUE;
	doctypes[1].description = "JPEG files";
	doctypes[1].ext =".jpg";

	doctypes[2].nID = CIMAGE_FORMAT_PNG;
	doctypes[2].bRead = TRUE;
	doctypes[2].bWrite = TRUE;
	doctypes[2].description = "PNG files";
	doctypes[2].ext =".png";

	doctypes[3].nID = CIMAGE_FORMAT_BMP;
	doctypes[3].bRead = TRUE;
	doctypes[3].bWrite = TRUE;
	doctypes[3].description = "BMP files";
	doctypes[3].ext =".bmp";
*/

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	LoadStdProfileSettings(9);  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_DEMOTYPE,
		RUNTIME_CLASS(CDemoDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CDemoView));
	demoTemplate = pDocTemplate;
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
    // Alter behaviour to not open window immediately
    cmdInfo.m_nShellCommand = CCommandLineInfo::FileNothing;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The main window has been initialized, so show and update it.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CDemoApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

void CDemoApp::OnFileOpen() 
{
	// prompt the user (with all document templates)
	CString newName;
	int nType = CIMAGE_FORMAT_GIF;
	if (!PromptForFileName(newName, AFX_IDS_OPENFILE,
	  OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, TRUE, &nType))
		return; // open cancelled

	OpenDocumentFile(newName);
}

// prompt for file name - used for open and save as
// static function called from app
BOOL CDemoApp::PromptForFileName(CString& fileName, UINT nIDSTitle, 
	DWORD dwFlags, BOOL bOpenFileDialog, int* pType)
{
	CFileDialog dlgFile(bOpenFileDialog);
	CString title("Open bitmap file");

	dlgFile.m_ofn.Flags |= dwFlags;
//	dlgFile.m_ofn.Flags &= ~OFN_SHOWHELP;

	int nIndex = m_nFilterIndex;
	if (!bOpenFileDialog)
	{
		int nDocType = (pType != NULL) ? *pType : CIMAGE_FORMAT_BMP;
		nIndex = GetIndexFromType(nDocType, bOpenFileDialog);
		if (nIndex == -1)
			nIndex = 1;
		ASSERT(nIndex != -1);
		nIndex++;
	}
	dlgFile.m_ofn.nFilterIndex = nIndex;
	// strDefExt is necessary to hold onto the memory from GetExtFromType
	CString strDefExt = GetExtFromType(GetTypeFromIndex(nIndex-1, bOpenFileDialog));
	dlgFile.m_ofn.lpstrDefExt = strDefExt;
		

	CString strFilter = GetFileTypes(bOpenFileDialog);
	dlgFile.m_ofn.lpstrFilter = strFilter;
	dlgFile.m_ofn.lpstrTitle = title;
	dlgFile.m_ofn.lpstrFile = fileName.GetBuffer(_MAX_PATH);

	BOOL bRet = (dlgFile.DoModal() == IDOK) ? TRUE : FALSE;
	fileName.ReleaseBuffer();
	if (bRet)
	{
		if (bOpenFileDialog)
			m_nFilterIndex = dlgFile.m_ofn.nFilterIndex;
		if (pType != NULL)
		{
			int nIndex = (int)dlgFile.m_ofn.nFilterIndex - 1;
			ASSERT(nIndex >= 0);
			*pType = GetTypeFromIndex(nIndex, bOpenFileDialog);
		}
	}
	return bRet;
}

int CDemoApp::GetIndexFromType(int nDocType, BOOL bOpenFileDialog)
{
	int nCnt = 0;
	for (int i=0;i<NUM_DOC_TYPES;i++)
	{
		if (bOpenFileDialog ? doctypes[i].bRead : doctypes[i].bWrite)
		{
			if (doctypes[i].nID == nDocType)
				return nCnt;
			nCnt++;
		}
	}
	return -1;
}

int CDemoApp::GetTypeFromIndex(int nIndex, BOOL bOpenFileDialog)
{
	int nCnt = 0;
	for (int i=0;i<NUM_DOC_TYPES;i++)
	{
		if (bOpenFileDialog ? doctypes[i].bRead : doctypes[i].bWrite)
		{
			if (nCnt == nIndex)
                // PJO - Buglet ?
//              return i;
                return doctypes[i].nID;
			nCnt++;
		}
	}
	ASSERT(FALSE);
	return -1;
}

CString CDemoApp::GetExtFromType(int nDocType)
{
	for (int i=0;i<NUM_DOC_TYPES;i++)
	{
		if (doctypes[i].nID == nDocType)
			return doctypes[i].ext;
	}
	return CString("");
}

BOOL CDemoApp::GetWritableType(int nDocType)
{
	for (int i=0;i<NUM_DOC_TYPES;i++)
	{
		if (doctypes[i].nID == nDocType)
			return doctypes[i].bWrite;
	}
	return FALSE;
}

CString CDemoApp::GetFileTypes(BOOL bOpenFileDialog)
{
	CString str;
	for (int i=0;i<NUM_DOC_TYPES;i++)
	{
		if (bOpenFileDialog && doctypes[i].bRead)
		{
			str += doctypes[i].description;
			str += (TCHAR)NULL;
            str += "*";
			str += doctypes[i].ext;
			str += (TCHAR)NULL;
		}
		else if (!bOpenFileDialog && doctypes[i].bWrite)
		{
			str += doctypes[i].description;
			str += (TCHAR)NULL;
            str += "*";
			str += doctypes[i].ext;
			str += (TCHAR)NULL;
		}
	}
	return str;
}

/////////////////////////////////////////////////////////////////////////////
// CDemoApp commands


void CDemoApp::OnImageFromBitmap() 
{
	CBitmap bitmap;
	if (!bitmap.LoadBitmap(IDB_TEST_BITMAP))
	{
		AfxMessageBox("Could not load bitmap from resource");
		return;
	}
	CDemoDoc *doc = (CDemoDoc *)demoTemplate->OpenDocumentFile(NULL);
	if (doc)
	{
		CImage *newImage = new CImage(&bitmap);
		if (!newImage->IsOK())
		{
			AfxMessageBox("Could not create CImage");
			delete newImage;
			return;
		}
		doc->image = newImage;
	}
}
