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

	CBitmap m_plane;					// �ɻ�
	CBitmap m_stone1, m_stone2, m_stone3,m_stone4, m_stone5, m_stone6,m_stone7, m_stone8, m_stone9;	// ��ʯ



	int planex, planey;					// �ɻ�����
	int stone1x, stone1y;					// ��ʯ1���� 
	int stone2x, stone2y;					// ��ʯ2���� 
	int stone3x, stone3y;					// ��ʯ3���� 
	int stone4x, stone4y;					// ��ʯ4���� 
	int stone5x, stone5y;					// ��ʯ5���� 
	int stone6x, stone6y;					// ��ʯ6���� 
	int stone7x, stone7y;					// ��ʯ7���� 
	int stone8x, stone8y;					// ��ʯ8���� 
	int stone9x, stone9y;					// ��ʯ9���� 

	int speed;						//��ʯ��ʼ�����ٶ�

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
