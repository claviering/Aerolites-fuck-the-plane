// planeDoc.cpp : implementation of the CPlaneDoc class
//

#include "stdafx.h"
#include "plane.h"

#include "planeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlaneDoc

IMPLEMENT_DYNCREATE(CPlaneDoc, CDocument)

BEGIN_MESSAGE_MAP(CPlaneDoc, CDocument)
	//{{AFX_MSG_MAP(CPlaneDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlaneDoc construction/destruction

CPlaneDoc::CPlaneDoc()
{
	// TODO: add one-time construction code here

}

CPlaneDoc::~CPlaneDoc()
{
}

BOOL CPlaneDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPlaneDoc serialization

void CPlaneDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPlaneDoc diagnostics

#ifdef _DEBUG
void CPlaneDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPlaneDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPlaneDoc commands
