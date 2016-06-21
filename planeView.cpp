// planeView.cpp : implementation of the CPlaneView class
//

#include "stdafx.h"
#include "plane.h"

#include "planeDoc.h"
#include "planeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlaneView

IMPLEMENT_DYNCREATE(CPlaneView, CView)

BEGIN_MESSAGE_MAP(CPlaneView, CView)
	//{{AFX_MSG_MAP(CPlaneView)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlaneView construction/destruction

void CPlaneView::DrawBitmap(CDC *pDC, CBitmap &oBitmap, int oldx, int oldy, int newx, int newy)
// ��λͼ����oBitmap,��(x,y)Ϊ������ʾ���豸CDC��
{
	// ��ȥ��λͼ
	RECT rect;							// ���νṹ
	BITMAP bm;						// λͼ�ṹ
	oBitmap.GetObject(sizeof(BITMAP), &bm);	// �õ�λͼ�ṹ
	rect.left = oldx;						// rect���Ͻ�x����
	rect.top = oldy;						// rect���Ͻ�y����
	rect.right = rect.left + bm.bmWidth;		// rect���½�x����	
	rect.bottom = rect.top + bm.bmHeight;		// rect���½�y����	
	CBrush brush(GetSysColor(COLOR_WINDOW));	
		// �õ�����ϵͳɫ�Ļ�ˢ GetSysColorΪSDK����,ǰ�治�ܼ�this->
	pDC->FillRect(&rect, &brush);			// ��ȥԭ����λͼ
	
	// �ػ���λͼ
	CDC memDC;						// �ڴ��ϵ��豸
	memDC.CreateCompatibleDC(pDC);		// ������pDC���ݵ��ڴ��豸memDC
	CBitmap *pOldBitmap = memDC.SelectObject(&oBitmap);	
		// ��memDC��oBitmap�������
//	BITMAP bm;						// λͼ�ṹ
//	oBitmap.GetObject(sizeof(BITMAP), &bm);	// �õ�λͼ�ṹ
	pDC->BitBlt(newx, newy, bm.bmWidth, bm.bmHeight, &memDC, 0, 0, SRCCOPY);	// ��ʾλͼ
	memDC.SelectObject(pOldBitmap);		// �ָ�memDCԭ��������λͼ����
}

CPlaneView::CPlaneView()
{
	// TODO: add construction code here

	this->planex = 100; this->planey = 100;			// �ɻ���ʼλ��
	this->m_plane.LoadBitmap(IDB_BITMAP1);		// װ�طɻ�λͼ
	
	this->stone1x = rand() % 500;  this->stone1y = 10;	// ��ʯ1��ʼλ��
	this->m_stone1.LoadBitmap(IDB_BITMAP2);	// װ����ʯ1λͼ

	this->stone2x = rand() % 500;  this->stone2y = 10;	// ��ʯ2��ʼλ��
	this->m_stone2.LoadBitmap(IDB_BITMAP3);	// װ����ʯ2λͼ

	this->stone3x = rand() % 500;  this->stone3y = 10;	// ��ʯ3��ʼλ��
	this->m_stone3.LoadBitmap(IDB_BITMAP4);	// װ����ʯ3λͼ

	this->stone4x = rand() % 500;  this->stone4y = 10;	// ��ʯ4��ʼλ��
	this->m_stone4.LoadBitmap(IDB_BITMAP5);	// װ����ʯ4λͼ

	this->stone5x = rand() % 500;  this->stone5y = 10;	// ��ʯ5��ʼλ��
	this->m_stone5.LoadBitmap(IDB_BITMAP6);	// װ����ʯ5λͼ

	this->stone6x = rand() % 500;  this->stone6y = 10;	// ��ʯ6��ʼλ��
	this->m_stone6.LoadBitmap(IDB_BITMAP7);	// װ����ʯ6λͼ

	this->stone7x = rand() % 500;  this->stone7y = 10;	// ��ʯ7��ʼλ��
	this->m_stone7.LoadBitmap(IDB_BITMAP8);	// װ����ʯ1λͼ

	this->stone8x = rand() % 500;  this->stone8y = 10;	// ��ʯ8��ʼλ��
	this->m_stone8.LoadBitmap(IDB_BITMAP9);	// װ����ʯ8λͼ

	this->stone9x = rand() % 500;  this->stone9y = 10;	// ��ʯ9��ʼλ��
	this->m_stone9.LoadBitmap(IDB_BITMAP10);	// װ����ʯ9λͼ



	this->speed = 500;//��ʼ��ʯ�����ٶ�

}

CPlaneView::~CPlaneView()
{
}

BOOL CPlaneView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPlaneView drawing

void CPlaneView::OnDraw(CDC* pDC)
{
	CPlaneDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	DrawBitmap(pDC, m_plane, planex, planey, planex, planey);// ���Ʒɻ�



}

/////////////////////////////////////////////////////////////////////////////
// CPlaneView printing

BOOL CPlaneView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPlaneView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPlaneView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPlaneView diagnostics

#ifdef _DEBUG
void CPlaneView::AssertValid() const
{
	CView::AssertValid();
}

void CPlaneView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlaneDoc* CPlaneView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlaneDoc)));
	return (CPlaneDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPlaneView message handlers

void CPlaneView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC ClientDC(this);				// �õ���ǰ�ͻ������豸
	int oldx, int oldy, int newx, int newy;

	oldx = planex; oldy = planey;			// �ɷɻ�λ��

	if (nChar == VK_UP)
	{	// ����
		newx = oldx;	
		newy = oldy - 30;		
	}
	else if (nChar == VK_LEFT) 
	{	// ����
		newx = oldx - 30;	
		newy = oldy;
	}
	else if (nChar == VK_RIGHT)
	{	// ����
		newx = oldx + 30;
		newy = oldy;
	}
	else if (nChar == VK_DOWN)
	{	// ����
		newx = oldx;
		newy = oldy + 30;	
	}
	DrawBitmap(&ClientDC, m_plane, oldx, oldy, newx, newy);	
		// ���Ʒɻ�
	
	planex = newx; planey = newy;			// �·ɻ�λ��
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CPlaneView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

	
	switch(nIDEvent)
	{
	case 1:
		{
			
			CClientDC ClientDC(this);			// �õ���ǰ�ͻ������豸
		RECT ClientRect;					// ���νṹ
		this->GetClientRect(&ClientRect);	// �õ���ǰ�ͻ��������
	
		int oldx, oldy, newx, newy;			// �¾�λ��

		

		oldx = stone1x; oldy = stone1y;		// ��ʯͷ1λ��
		newx = oldx; newy = oldy + 10;		// ��ʯͷ1λ��
		if (newy > ClientRect.bottom) 
		{	// ��������ʯͷ1��λ��
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone1, oldx, oldy, newx, newy);// ����ʯͷ1
		stone1x = newx; stone1y = newy;		// ��ʯͷ1λ��
	
		oldx = stone2x; oldy = stone2y;		// ��ʯͷ2λ��
		newx = oldx; newy = oldy + 13;		// ��ʯͷ2λ��
		if (newy > ClientRect.bottom) 
		{	// ��������ʯͷ2��λ��
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone2, oldx, oldy, newx, newy);// ����ʯͷ2
		stone2x = newx; stone2y = newy;		// ��ʯͷ2λ��
	
		oldx = stone3x; oldy = stone3y;		// ��ʯͷ3λ��
		newx = oldx; newy = oldy + 16;		// ��ʯͷ3λ��
		if (newy > ClientRect.bottom) 
		{	// ��������ʯͷ3��λ��
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone3, oldx, oldy, newx, newy);// ����ʯͷ3
		stone3x = newx; stone3y = newy;		// ��ʯͷ3λ��

		oldx = stone4x; oldy = stone4y;		// ��ʯͷ4λ��
		newx = oldx; newy = oldy + 10;		// ��ʯͷ4λ��
		if (newy > ClientRect.bottom) 
		{	// ��������ʯͷ4��λ��
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone4, oldx, oldy, newx, newy);// ����ʯͷ4
		stone4x = newx; stone4y = newy;		// ��ʯͷ4λ��
	
		oldx = stone5x; oldy = stone5y;		// ��ʯͷ5λ��
		newx = oldx; newy = oldy + 13;		// ��ʯͷ5λ��
		if (newy > ClientRect.bottom) 
		{	// ��������ʯͷ5��λ��
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone5, oldx, oldy, newx, newy);// ����ʯͷ5
		stone5x = newx; stone5y = newy;		// ��ʯͷ5λ��
	
		oldx = stone6x; oldy = stone6y;		// ��ʯͷ6λ��
		newx = oldx; newy = oldy + 16;		// ��ʯͷ6λ��
		if (newy > ClientRect.bottom) 
		{	// ��������ʯͷ6��λ��
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone6, oldx, oldy, newx, newy);// ����ʯͷ6
		stone6x = newx; stone6y = newy;		// ��ʯͷ6λ��

		oldx = stone7x; oldy = stone7y;		// ��ʯͷ7λ��
		newx = oldx; newy = oldy + 10;		// ��ʯͷ7λ��
		if (newy > ClientRect.bottom) 
		{	// ��������ʯͷ7��λ��
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone7, oldx, oldy, newx, newy);// ����ʯͷ7
		stone7x = newx; stone7y = newy;		// ��ʯͷ7λ��
	
		oldx = stone8x; oldy = stone8y;		// ��ʯͷ8λ��
		newx = oldx; newy = oldy + 13;		// ��ʯͷ8λ��
		if (newy > ClientRect.bottom) 
		{	// ��������ʯͷ8��λ��
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone8, oldx, oldy, newx, newy);// ����ʯͷ8
		stone8x = newx; stone8y = newy;		// ��ʯͷ8λ��
	
		oldx = stone9x; oldy = stone9y;		// ��ʯͷ9λ��
		newx = oldx; newy = oldy + 16;		// ��ʯͷ9λ��
		if (newy > ClientRect.bottom) 
		{	// ��������ʯͷ9��λ��
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone9, oldx, oldy, newx, newy);// ����ʯͷ9
		stone9x = newx; stone9y = newy;		// ��ʯͷ9λ��
		

		break;
		
		}

	case 2:
		{
		
		SetTimer(1,speed,NULL);//���ö�ʱ��1
		if(speed > 300)
			speed -=10;//��ʯ�����ٶȼӿ�
		else if (speed > 200)
			speed -=5;
		else if (speed > 100)
			speed -= 2;
		else
			speed -= 1;
		break;
		}
	default:
		break;
	}
	
	

	CView::OnTimer(nIDEvent);
}

int CPlaneView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here



	this->SetTimer(1, 500, NULL);	// �豸��ʱ�������ļ��Ϊ200����
	this->SetTimer(2,1000,NULL);
	
	return 0;
}






