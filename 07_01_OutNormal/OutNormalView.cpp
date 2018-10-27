// OutNormalView.cpp : implementation of the COutNormalView class
//

#include "stdafx.h"
#include "OutNormal.h"
#include "math.h"
#define PI 3.1415926

#include "OutNormalDoc.h"
#include "OutNormalView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutNormalView

IMPLEMENT_DYNCREATE(COutNormalView, CView)

BEGIN_MESSAGE_MAP(COutNormalView, CView)
	//{{AFX_MSG_MAP(COutNormalView)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutNormalView construction/destruction

COutNormalView::COutNormalView()
{
    alpha1 = 45;//绕Z轴旋转的角度		
	beta1 = 30;//绕X轴旋转的角度
}

COutNormalView::~COutNormalView()
{
}

BOOL COutNormalView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// COutNormalView drawing

void COutNormalView::OnDraw(CDC* pDC)
{
	COutNormalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
    pDC->TextOut(20,10,"请按键盘上的 “上”“下”“左”“右” 箭头可从各方位观察立方体");
	DrawHidedCube();//""上"、"下"、"左"、"右"键头可从各方位观察立方体"
}

/////////////////////////////////////////////////////////////////////////////
// COutNormalView printing

BOOL COutNormalView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COutNormalView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COutNormalView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// COutNormalView diagnostics

#ifdef _DEBUG
void COutNormalView::AssertValid() const
{
	CView::AssertValid();
}

void COutNormalView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COutNormalDoc* COutNormalView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COutNormalDoc)));
	return (COutNormalDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COutNormalView message handlers

void COutNormalView::DrawHidedCube()
{
	Pt[1][0] = 0; Pt[1][1] = 100; Pt[1][2] = 0;
	Pt[2][0] = -50; Pt[2][1] = 0; Pt[2][2] = 50;
	Pt[3][0] = 50; Pt[3][1] = 0; Pt[3][2] = 50;
	Pt[4][0] = 0; Pt[4][1] = 0; Pt[4][2] = -50;


	int nNumFaces = 4;
	Face[1][0] = 0; Face[1][1] = 1; Face[1][2] = 2; 
	Face[2][0] = 0; Face[2][1] = 2; Face[2][2] = 3; 
	Face[3][0] = 0; Face[3][1] = 3; Face[3][2] = 1;
	Face[4][0] = 1; Face[4][1] = 2; Face[4][2] = 3; 

	double alpha = alpha1 * PI / 180.0;	//绕Z轴旋转的角度
	double beta = beta1 * PI / 180.0;		//绕X轴旋转的角度
	//计算变换投影之后的坐标
	int tx,ty,tz;
	tx = 600;
	ty = tz = 300;
	for(int i=1; i<9; i++)
	{
		Pt[i][0] -= tx;
		Pt[i][1] -= ty;
		Pt[i][2] -= tz;					//将立方体的8个顶点进行平移变换
	}
for(i=1; i<9; i++)
	{
		tmpPt[i][0] = Pt[i][0]* cos(alpha) - Pt[i][1]*sin(alpha) + tx;
		tmpPt[i][1] = Pt[i][0]*sin(alpha)*cos(beta) + Pt[i][1]*cos(alpha)*cos(beta) - Pt[i][2]*sin(beta) + ty;
		tmpPt[i][2] = Pt[i][0]*sin(alpha)*sin(beta) + Pt[i][1]*cos(alpha)*sin(beta) + Pt[i][2]*cos(beta) + tz ;
	}	
int p[4];
	double xn,yn,zn,vn;
	CDC *pDC = this->GetDC();
	CPen pen1(PS_SOLID,5,RGB(0,100,0));
	CPen pen2(PS_DOT,1, RGB(0,0,0));
	CPen *pOldPen = pDC->SelectObject(&pen1);
	for(i=1; i<nNumFaces+1; i++)
	{
		for(int j=0; j<4; j++)
		{
			p[j] = Face[i][j];
		}
		double x1 = tmpPt[p[0]][0];
		double y1 = tmpPt[p[0]][1];
		double z1 = tmpPt[p[0]][2];
		double x2 = tmpPt[p[1]][0];
		double y2 = tmpPt[p[1]][1];
		double z2 = tmpPt[p[1]][2];
		double x3 = tmpPt[p[2]][0];
		double y3 = tmpPt[p[2]][1];
		double z3 = tmpPt[p[2]][2];
		
		//计算面的外法向量
		/*
		|  i      j      k   |
		|x2-x1  y2-y1  z2-z1 |
		|x3-x2  y3-y2  z3-z2 |
		*/
		xn = (y2 - y1)*(z3-z2) - (y3-y2)*(z2-z1);
		yn = -(x2-x1)*(z3-z2) + (x3-x2)*(z2-z1);
		zn = (x2-x1)*(y3-y2) - (x3-x2)*(y2-y1);		//计算每个面的法矢
		vn = sqrt(xn*xn + yn*yn + zn*zn);
		xn = xn/vn; yn = yn/vn; zn = zn/vn;			//视点方向在(0,0,1000)处
		if(zn >= 0.0)		//视线方向与Z轴同向，当法矢的Z方向分量大于0时，与实现方向成小于90度的角，面可见
		{
			pDC->SelectObject(&pen1);
			
			DrawFace(pDC,i);		//以5个象素宽度的实线，绘制可见面
		}
		
		pDC->SelectObject(pOldPen);
	}
	this->ReleaseDC(pDC);
}

void COutNormalView::DrawFace(CDC *pDC, int nIndex)
{
	int p[3];
	for(int j=0; j<3; j++)
	{
		p[j] = Face[nIndex][j];
	}
	pDC->MoveTo(tmpPt[p[0]][0],tmpPt[p[0]][1]);
	pDC->LineTo(tmpPt[p[1]][0],tmpPt[p[1]][1]);
	pDC->LineTo(tmpPt[p[2]][0],tmpPt[p[2]][1]);
	pDC->LineTo(tmpPt[p[3]][0],tmpPt[p[3]][1]);
	//pDC->LineTo(tmpPt[p[0]][0],tmpPt[p[0]][1]);
}

void COutNormalView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
switch(nChar)
	{
	case VK_UP:
		beta1 += 5;
		Invalidate();
		break;
	case VK_DOWN:
		beta1 -= 5;
		Invalidate();
		break;
	case VK_LEFT:
		alpha1 += 5;
		Invalidate();
		break;
	case VK_RIGHT:
		alpha1 -= 5;
		Invalidate();
		break;
	default:
		break;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
