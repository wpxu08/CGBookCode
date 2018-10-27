// ArtistEliView.h : interface of the CArtistEliView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARTISTELIVIEW_H__52BAC455_4E62_4742_B529_3E5658761C8F__INCLUDED_)
#define AFX_ARTISTELIVIEW_H__52BAC455_4E62_4742_B529_3E5658761C8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CArtistEliView : public CView
{
protected: // create from serialization only
	CArtistEliView();
	DECLARE_DYNCREATE(CArtistEliView)

// Attributes
public:
	CArtistEliDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CArtistEliView)
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

	void OnCircleFace();
	virtual ~CArtistEliView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CArtistEliView)
	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ArtistEliView.cpp
inline CArtistEliDoc* CArtistEliView::GetDocument()
   { return (CArtistEliDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ARTISTELIVIEW_H__52BAC455_4E62_4742_B529_3E5658761C8F__INCLUDED_)
