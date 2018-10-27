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


	double Pt[9][3];	//存储立方体的8个顶点坐标，Pt[0][3]保留不用，为了和面号相对应
	int Face[7][4];		//存储立方体的6个面对应的顶点,Face[0][4]保留不用，为了和顶点号相对应
	double tmpPt[9][3];		//存储投影变换之后的坐标值
	int alpha1,beta1;		//定义绕Z轴旋转alpha角，绕X轴旋转beta角


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
