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
// 将位图对象oBitmap,以(x,y)为坐标显示在设备CDC上
{
	// 擦去旧位图
	RECT rect;							// 矩形结构
	BITMAP bm;						// 位图结构
	oBitmap.GetObject(sizeof(BITMAP), &bm);	// 得到位图结构
	rect.left = oldx;						// rect左上角x坐标
	rect.top = oldy;						// rect左上角y坐标
	rect.right = rect.left + bm.bmWidth;		// rect右下角x坐标	
	rect.bottom = rect.top + bm.bmHeight;		// rect右下角y坐标	
	CBrush brush(GetSysColor(COLOR_WINDOW));	
		// 得到窗口系统色的画刷 GetSysColor为SDK函数,前面不能加this->
	pDC->FillRect(&rect, &brush);			// 擦去原来的位图
	
	// 重绘新位图
	CDC memDC;						// 内存上的设备
	memDC.CreateCompatibleDC(pDC);		// 生成与pDC兼容的内存设备memDC
	CBitmap *pOldBitmap = memDC.SelectObject(&oBitmap);	
		// 将memDC与oBitmap对象相关
//	BITMAP bm;						// 位图结构
//	oBitmap.GetObject(sizeof(BITMAP), &bm);	// 得到位图结构
	pDC->BitBlt(newx, newy, bm.bmWidth, bm.bmHeight, &memDC, 0, 0, SRCCOPY);	// 显示位图
	memDC.SelectObject(pOldBitmap);		// 恢复memDC原来关联的位图对象
}

CPlaneView::CPlaneView()
{
	// TODO: add construction code here

	this->planex = 100; this->planey = 100;			// 飞机初始位置
	this->m_plane.LoadBitmap(IDB_BITMAP1);		// 装载飞机位图
	
	this->stone1x = rand() % 500;  this->stone1y = 10;	// 陨石1初始位置
	this->m_stone1.LoadBitmap(IDB_BITMAP2);	// 装载陨石1位图

	this->stone2x = rand() % 500;  this->stone2y = 10;	// 陨石2初始位置
	this->m_stone2.LoadBitmap(IDB_BITMAP3);	// 装载陨石2位图

	this->stone3x = rand() % 500;  this->stone3y = 10;	// 陨石3初始位置
	this->m_stone3.LoadBitmap(IDB_BITMAP4);	// 装载陨石3位图

	this->stone4x = rand() % 500;  this->stone4y = 10;	// 陨石4初始位置
	this->m_stone4.LoadBitmap(IDB_BITMAP5);	// 装载陨石4位图

	this->stone5x = rand() % 500;  this->stone5y = 10;	// 陨石5初始位置
	this->m_stone5.LoadBitmap(IDB_BITMAP6);	// 装载陨石5位图

	this->stone6x = rand() % 500;  this->stone6y = 10;	// 陨石6初始位置
	this->m_stone6.LoadBitmap(IDB_BITMAP7);	// 装载陨石6位图

	this->stone7x = rand() % 500;  this->stone7y = 10;	// 陨石7初始位置
	this->m_stone7.LoadBitmap(IDB_BITMAP8);	// 装载陨石1位图

	this->stone8x = rand() % 500;  this->stone8y = 10;	// 陨石8初始位置
	this->m_stone8.LoadBitmap(IDB_BITMAP9);	// 装载陨石8位图

	this->stone9x = rand() % 500;  this->stone9y = 10;	// 陨石9初始位置
	this->m_stone9.LoadBitmap(IDB_BITMAP10);	// 装载陨石9位图



	this->speed = 500;//初始陨石下落速度

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
	DrawBitmap(pDC, m_plane, planex, planey, planex, planey);// 绘制飞机



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
	CClientDC ClientDC(this);				// 得到当前客户区域设备
	int oldx, int oldy, int newx, int newy;

	oldx = planex; oldy = planey;			// 旧飞机位置

	if (nChar == VK_UP)
	{	// 按↑
		newx = oldx;	
		newy = oldy - 30;		
	}
	else if (nChar == VK_LEFT) 
	{	// 按←
		newx = oldx - 30;	
		newy = oldy;
	}
	else if (nChar == VK_RIGHT)
	{	// 按→
		newx = oldx + 30;
		newy = oldy;
	}
	else if (nChar == VK_DOWN)
	{	// 按↓
		newx = oldx;
		newy = oldy + 30;	
	}
	DrawBitmap(&ClientDC, m_plane, oldx, oldy, newx, newy);	
		// 绘制飞机
	
	planex = newx; planey = newy;			// 新飞机位置
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CPlaneView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

	
	switch(nIDEvent)
	{
	case 1:
		{
			
			CClientDC ClientDC(this);			// 得到当前客户区域设备
		RECT ClientRect;					// 矩形结构
		this->GetClientRect(&ClientRect);	// 得到当前客户区域矩形
	
		int oldx, oldy, newx, newy;			// 新旧位置

		

		oldx = stone1x; oldy = stone1y;		// 旧石头1位置
		newx = oldx; newy = oldy + 10;		// 新石头1位置
		if (newy > ClientRect.bottom) 
		{	// 重新生成石头1新位置
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone1, oldx, oldy, newx, newy);// 绘制石头1
		stone1x = newx; stone1y = newy;		// 新石头1位置
	
		oldx = stone2x; oldy = stone2y;		// 旧石头2位置
		newx = oldx; newy = oldy + 13;		// 新石头2位置
		if (newy > ClientRect.bottom) 
		{	// 重新生成石头2新位置
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone2, oldx, oldy, newx, newy);// 绘制石头2
		stone2x = newx; stone2y = newy;		// 新石头2位置
	
		oldx = stone3x; oldy = stone3y;		// 旧石头3位置
		newx = oldx; newy = oldy + 16;		// 新石头3位置
		if (newy > ClientRect.bottom) 
		{	// 重新生成石头3新位置
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone3, oldx, oldy, newx, newy);// 绘制石头3
		stone3x = newx; stone3y = newy;		// 新石头3位置

		oldx = stone4x; oldy = stone4y;		// 旧石头4位置
		newx = oldx; newy = oldy + 10;		// 新石头4位置
		if (newy > ClientRect.bottom) 
		{	// 重新生成石头4新位置
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone4, oldx, oldy, newx, newy);// 绘制石头4
		stone4x = newx; stone4y = newy;		// 新石头4位置
	
		oldx = stone5x; oldy = stone5y;		// 旧石头5位置
		newx = oldx; newy = oldy + 13;		// 新石头5位置
		if (newy > ClientRect.bottom) 
		{	// 重新生成石头5新位置
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone5, oldx, oldy, newx, newy);// 绘制石头5
		stone5x = newx; stone5y = newy;		// 新石头5位置
	
		oldx = stone6x; oldy = stone6y;		// 旧石头6位置
		newx = oldx; newy = oldy + 16;		// 新石头6位置
		if (newy > ClientRect.bottom) 
		{	// 重新生成石头6新位置
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone6, oldx, oldy, newx, newy);// 绘制石头6
		stone6x = newx; stone6y = newy;		// 新石头6位置

		oldx = stone7x; oldy = stone7y;		// 旧石头7位置
		newx = oldx; newy = oldy + 10;		// 新石头7位置
		if (newy > ClientRect.bottom) 
		{	// 重新生成石头7新位置
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone7, oldx, oldy, newx, newy);// 绘制石头7
		stone7x = newx; stone7y = newy;		// 新石头7位置
	
		oldx = stone8x; oldy = stone8y;		// 旧石头8位置
		newx = oldx; newy = oldy + 13;		// 新石头8位置
		if (newy > ClientRect.bottom) 
		{	// 重新生成石头8新位置
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone8, oldx, oldy, newx, newy);// 绘制石头8
		stone8x = newx; stone8y = newy;		// 新石头8位置
	
		oldx = stone9x; oldy = stone9y;		// 旧石头9位置
		newx = oldx; newy = oldy + 16;		// 新石头9位置
		if (newy > ClientRect.bottom) 
		{	// 重新生成石头9新位置
			newx = rand() % 1000; newy = 0;
		}
		DrawBitmap(&ClientDC, m_stone9, oldx, oldy, newx, newy);// 绘制石头9
		stone9x = newx; stone9y = newy;		// 新石头9位置
		

		break;
		
		}

	case 2:
		{
		
		SetTimer(1,speed,NULL);//重置定时器1
		if(speed > 300)
			speed -=10;//陨石下落速度加快
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



	this->SetTimer(1, 500, NULL);	// 设备定时器触发的间隔为200毫秒
	this->SetTimer(2,1000,NULL);
	
	return 0;
}






