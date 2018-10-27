// OutNormalDoc.cpp : implementation of the COutNormalDoc class
//

#include "stdafx.h"
#include "OutNormal.h"

#include "OutNormalDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutNormalDoc

IMPLEMENT_DYNCREATE(COutNormalDoc, CDocument)

BEGIN_MESSAGE_MAP(COutNormalDoc, CDocument)
	//{{AFX_MSG_MAP(COutNormalDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutNormalDoc construction/destruction

COutNormalDoc::COutNormalDoc()
{
	// TODO: add one-time construction code here

}

COutNormalDoc::~COutNormalDoc()
{
}

BOOL COutNormalDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COutNormalDoc serialization

void COutNormalDoc::Serialize(CArchive& ar)
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
// COutNormalDoc diagnostics

#ifdef _DEBUG
void COutNormalDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COutNormalDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COutNormalDoc commands
