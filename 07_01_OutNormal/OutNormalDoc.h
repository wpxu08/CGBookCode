// OutNormalDoc.h : interface of the COutNormalDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OUTNORMALDOC_H__DCC3E6B2_EB8C_4BBF_9992_E55EB6116444__INCLUDED_)
#define AFX_OUTNORMALDOC_H__DCC3E6B2_EB8C_4BBF_9992_E55EB6116444__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COutNormalDoc : public CDocument
{
protected: // create from serialization only
	COutNormalDoc();
	DECLARE_DYNCREATE(COutNormalDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutNormalDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COutNormalDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COutNormalDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTNORMALDOC_H__DCC3E6B2_EB8C_4BBF_9992_E55EB6116444__INCLUDED_)
