// Z_BufferEliDoc.h : interface of the CZ_BufferEliDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_Z_BUFFERELIDOC_H__2E052842_556D_45E0_B850_83DFD977FEED__INCLUDED_)
#define AFX_Z_BUFFERELIDOC_H__2E052842_556D_45E0_B850_83DFD977FEED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CZ_BufferEliDoc : public CDocument
{
protected: // create from serialization only
	CZ_BufferEliDoc();
	DECLARE_DYNCREATE(CZ_BufferEliDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZ_BufferEliDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CZ_BufferEliDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CZ_BufferEliDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_Z_BUFFERELIDOC_H__2E052842_556D_45E0_B850_83DFD977FEED__INCLUDED_)
