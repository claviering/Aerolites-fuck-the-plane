// planeView.h : interface of the CPlaneView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANEVIEW_H__CF79B933_ADF8_4CEA_8203_ABF9DD6B3A72__INCLUDED_)
#define AFX_PLANEVIEW_H__CF79B933_ADF8_4CEA_8203_ABF9DD6B3A72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPlaneView : public CView
{
protected: // create from serialization only
	CPlaneView();
	DECLARE_DYNCREATE(CPlaneView)

// Attributes
public:
	CPlaneDoc* GetDocument();

	CBitmap m_plane;					// 飞机
	CBitmap m_stone1, m_stone2, m_stone3,m_stone4, m_stone5, m_stone6,m_stone7, m_stone8, m_stone9;	// 陨石



	int planex, planey;					// 飞机坐标
	int stone1x, stone1y;					// 陨石1坐标 
	int stone2x, stone2y;					// 陨石2坐标 
	int stone3x, stone3y;					// 陨石3坐标 
	int stone4x, stone4y;					// 陨石4坐标 
	int stone5x, stone5y;					// 陨石5坐标 
	int stone6x, stone6y;					// 陨石6坐标 
	int stone7x, stone7y;					// 陨石7坐标 
	int stone8x, stone8y;					// 陨石8坐标 
	int stone9x, stone9y;					// 陨石9坐标 

	int speed;						//陨石初始下落速度

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlaneView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPlaneView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPlaneView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void DrawBitmap(CDC *pDC, CBitmap &oBitmap, int oldx, int oldy, int newx, int newy);
};

#ifndef _DEBUG  // debug version in planeView.cpp
inline CPlaneDoc* CPlaneView::GetDocument()
   { return (CPlaneDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLANEVIEW_H__CF79B933_ADF8_4CEA_8203_ABF9DD6B3A72__INCLUDED_)
