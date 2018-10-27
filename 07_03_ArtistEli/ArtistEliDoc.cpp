// ArtistEliDoc.cpp : implementation of the CArtistEliDoc class
//

#include "stdafx.h"
#include "ArtistEli.h"

#include "ArtistEliDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CArtistEliDoc

IMPLEMENT_DYNCREATE(CArtistEliDoc, CDocument)

BEGIN_MESSAGE_MAP(CArtistEliDoc, CDocument)
	//{{AFX_MSG_MAP(CArtistEliDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CArtistEliDoc construction/destruction

CArtistEliDoc::CArtistEliDoc()
{
	// TODO: add one-time construction code here

}

CArtistEliDoc::~CArtistEliDoc()
{
}

BOOL CArtistEliDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CArtistEliDoc serialization

void CArtistEliDoc::Serialize(CArchive& ar)
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
// CArtistEliDoc diagnostics

#ifdef _DEBUG
void CArtistEliDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CArtistEliDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CArtistEliDoc commands
