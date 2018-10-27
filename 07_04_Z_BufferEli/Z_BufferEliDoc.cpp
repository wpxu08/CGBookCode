// Z_BufferEliDoc.cpp : implementation of the CZ_BufferEliDoc class
//

#include "stdafx.h"
#include "Z_BufferEli.h"

#include "Z_BufferEliDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZ_BufferEliDoc

IMPLEMENT_DYNCREATE(CZ_BufferEliDoc, CDocument)

BEGIN_MESSAGE_MAP(CZ_BufferEliDoc, CDocument)
	//{{AFX_MSG_MAP(CZ_BufferEliDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZ_BufferEliDoc construction/destruction

CZ_BufferEliDoc::CZ_BufferEliDoc()
{
	// TODO: add one-time construction code here

}

CZ_BufferEliDoc::~CZ_BufferEliDoc()
{
}

BOOL CZ_BufferEliDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CZ_BufferEliDoc serialization

void CZ_BufferEliDoc::Serialize(CArchive& ar)
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
// CZ_BufferEliDoc diagnostics

#ifdef _DEBUG
void CZ_BufferEliDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CZ_BufferEliDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CZ_BufferEliDoc commands
