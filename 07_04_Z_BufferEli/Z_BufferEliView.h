// Z_BufferEliView.h : interface of the CZ_BufferEliView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_Z_BUFFERELIVIEW_H__0838D729_A0D8_42B2_98E2_32E4CEAFB256__INCLUDED_)
#define AFX_Z_BUFFERELIVIEW_H__0838D729_A0D8_42B2_98E2_32E4CEAFB256__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MyFace.h"
#include "Matrix.h"


class CZ_BufferEliView : public CView
{
protected: // create from serialization only
	CZ_BufferEliView();
	DECLARE_DYNCREATE(CZ_BufferEliView)

// Attributes
public:
	CZ_BufferEliDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZ_BufferEliView)
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
    int n;
	int num[1000];
	COLORREF color[400][400];//帧缓存
	double z_distance[400][400];//z缓存
	float angle;//旋转角度
	DPoint P1,P2,P3,P4,P5,P6,P7,P8;//立方体的八个顶点
	
	
	int IsInSide(CPoint Px,CPoint P1,CPoint P2,CPoint P3,CPoint P4);//判断一个点是否在多边形内
	void FaceBuffer(DPoint P1,DPoint P2,DPoint P3,DPoint P4,COLORREF m_clr,CDC*pDC);
	
	
	virtual ~CZ_BufferEliView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CZ_BufferEliView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Z_BufferEliView.cpp
inline CZ_BufferEliDoc* CZ_BufferEliView::GetDocument()
   { return (CZ_BufferEliDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_Z_BUFFERELIVIEW_H__0838D729_A0D8_42B2_98E2_32E4CEAFB256__INCLUDED_)
