// OutNormalView.h : interface of the COutNormalView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OUTNORMALVIEW_H__53F36A91_8DE3_4BBA_A318_822C0B06C8A3__INCLUDED_)
#define AFX_OUTNORMALVIEW_H__53F36A91_8DE3_4BBA_A318_822C0B06C8A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COutNormalView : public CView
{
protected: // create from serialization only
	COutNormalView();
	DECLARE_DYNCREATE(COutNormalView)

// Attributes
public:
	COutNormalDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutNormalView)
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


	double Pt[9][3];	//�洢�������8���������꣬Pt[0][3]�������ã�Ϊ�˺�������Ӧ
	int Face[7][4];		//�洢�������6�����Ӧ�Ķ���,Face[0][4]�������ã�Ϊ�˺Ͷ�������Ӧ
	double tmpPt[9][3];		//�洢ͶӰ�任֮�������ֵ
	int alpha1,beta1;		//������Z����תalpha�ǣ���X����תbeta��


	void DrawFace(CDC *pDC, int nIndex);
	void DrawHidedCube();

	virtual ~COutNormalView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COutNormalView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OutNormalView.cpp
inline COutNormalDoc* COutNormalView::GetDocument()
   { return (COutNormalDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTNORMALVIEW_H__53F36A91_8DE3_4BBA_A318_822C0B06C8A3__INCLUDED_)
