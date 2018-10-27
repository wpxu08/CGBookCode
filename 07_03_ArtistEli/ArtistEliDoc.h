// ArtistEliDoc.h : interface of the CArtistEliDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARTISTELIDOC_H__ECA60663_F8C9_4980_A8D0_DD2F525A1FBA__INCLUDED_)
#define AFX_ARTISTELIDOC_H__ECA60663_F8C9_4980_A8D0_DD2F525A1FBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CArtistEliDoc : public CDocument
{
protected: // create from serialization only
	CArtistEliDoc();
	DECLARE_DYNCREATE(CArtistEliDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CArtistEliDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CArtistEliDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CArtistEliDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ARTISTELIDOC_H__ECA60663_F8C9_4980_A8D0_DD2F525A1FBA__INCLUDED_)
