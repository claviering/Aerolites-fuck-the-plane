// planeDoc.h : interface of the CPlaneDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANEDOC_H__0A90C2BD_0848_4A06_A99F_D3E7312CA30D__INCLUDED_)
#define AFX_PLANEDOC_H__0A90C2BD_0848_4A06_A99F_D3E7312CA30D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPlaneDoc : public CDocument
{
protected: // create from serialization only
	CPlaneDoc();
	DECLARE_DYNCREATE(CPlaneDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlaneDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPlaneDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPlaneDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLANEDOC_H__0A90C2BD_0848_4A06_A99F_D3E7312CA30D__INCLUDED_)
