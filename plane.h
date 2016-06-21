// plane.h : main header file for the PLANE application
//

#if !defined(AFX_PLANE_H__EDDA8618_D2DF_405D_B19A_87E63B593646__INCLUDED_)
#define AFX_PLANE_H__EDDA8618_D2DF_405D_B19A_87E63B593646__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPlaneApp:
// See plane.cpp for the implementation of this class
//

class CPlaneApp : public CWinApp
{
public:
	CPlaneApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlaneApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPlaneApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLANE_H__EDDA8618_D2DF_405D_B19A_87E63B593646__INCLUDED_)
