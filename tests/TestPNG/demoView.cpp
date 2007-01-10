// demoView.cpp : implementation of the CDemoView class
//

#include "stdafx.h"
#include "cimage.h"
#include "MainFrm.h"
#include "demo.h"

#include "demoDoc.h"
#include "demoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoView

IMPLEMENT_DYNCREATE(CDemoView, CScrollView)

BEGIN_MESSAGE_MAP(CDemoView, CScrollView)
	//{{AFX_MSG_MAP(CDemoView)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView()
{
	SetScrollSizes(MM_TEXT, CSize(0, 0));
	m_lastX = 0;
	m_lastY = 0;

}

CDemoView::~CDemoView()
{
}

BOOL CDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView drawing

void CDemoView::OnDraw(CDC* pDC)
{
	CDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CPoint pos(GetScrollPosition());
	CRect rect;
	GetClientRect(&rect);
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	if (pDoc->GetImage())
	{
		int x = -pos.x;
		int y = -pos.y;
		if (width >= pDoc->GetImage()->GetWidth())
			x = (width - pDoc->GetImage()->GetWidth())/2;
		if (height >= pDoc->GetImage()->GetHeight())
			y = (height - pDoc->GetImage()->GetHeight())/2;

		CDC *dc = GetDC();
		CPalette *hOldPal = 0;
		if (pDoc->GetImage()->GetPalette())
		{
			hOldPal = dc->SelectPalette(pDoc->GetImage()->GetPalette(), TRUE);
			dc->RealizePalette();
		}

		if (pDoc->GetStretchMode())
		{
			m_lastX = 0;
			m_lastY = 0;
			SetScrollSizes(MM_TEXT,
				CSize(0,0));
			pDoc->GetImage()->Stretch(dc, 0, 0, width, height);
		}
		else
		{
			m_lastX = x;
			m_lastY = y;
			SetScrollSizes(MM_TEXT,
				CSize(pDoc->GetImage()->GetWidth(), pDoc->GetImage()->GetHeight()));
			pDoc->GetImage()->Draw(dc, x, y);
		}

//		dc->SelectPalette(hOldPal, TRUE);
		ReleaseDC(dc);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView printing

BOOL CDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView diagnostics

#ifdef _DEBUG
void CDemoView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDemoView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDemoDoc* CDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoDoc)));
	return (CDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView message handlers

void CDemoView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();
	
	if (GetDocument()->GetImage())
		SetScrollSizes(MM_TEXT,
		  CSize(GetDocument()->GetImage()->GetWidth(), GetDocument()->GetImage()->GetHeight()));
}

void CDemoView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// We get the RGB values at the point the user selects

	char s[80];
	byte r = 0, g = 0, b = 0;
	float x = point.x;
	float y = point.y;
	
	CPoint pos(GetScrollPosition());
/* Commented out on suggestion of Scott Chen <scott_chen@mintsystems.com>
	// Subtract scroll position
	x -= pos.x;
	y -= pos.y;
*/

	// Subtract the position that the image is being drawn
	// at - not necessarily (0, 0)
	x -= m_lastX;
	y -= m_lastY;

	CRect rect;
	GetClientRect(&rect);
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	CDemoDoc* pDoc = GetDocument();
	if (!pDoc->GetImage())
		return;
	
	if (pDoc->GetStretchMode())
	{
		x *= pDoc->GetImage()->GetWidth()/(float)width;
		y *= pDoc->GetImage()->GetHeight()/(float)height;
	}
	if (pDoc->GetImage()->Inside((int)x, (int)y))
	{
		sprintf(s,"X = %.0f Y = %.0f  Idx=%d", x, y, pDoc->GetImage()->GetIndex((int)x, (int)(pDoc->GetImage()->GetHeight() - y)));
		if (pDoc->GetImage()->GetRGB((int)x, (int)(pDoc->GetImage()->GetHeight() - y), &r, &g, &b))
			sprintf(&s[strlen(s)],"  RGB = (%d, %d, %d)", r, g, b);
	} else strcpy(s," ");
	
	CStatusBar& statusBar = ((CMainFrame *)(AfxGetApp()->m_pMainWnd))->GetStatusBar();
	statusBar.SetPaneText(0, s);
	
	
	CScrollView::OnMouseMove(nFlags, point);
}
