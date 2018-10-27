// Z_BufferEliView.cpp : implementation of the CZ_BufferEliView class
//

#include "stdafx.h"
#include "Z_BufferEli.h"

#include "Z_BufferEliDoc.h"
#include "Z_BufferEliView.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZ_BufferEliView

IMPLEMENT_DYNCREATE(CZ_BufferEliView, CView)

BEGIN_MESSAGE_MAP(CZ_BufferEliView, CView)
	//{{AFX_MSG_MAP(CZ_BufferEliView)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZ_BufferEliView construction/destruction

CZ_BufferEliView::CZ_BufferEliView():P1(-100,100,100),P2(100,100,100),P3(100,100,-100),P4(-100,100,-100),
P5(-100,-100,100),P6(100,-100,100),P7(100,-100,-100),P8(100,-100,-100)
{

		// 初始化帧缓存和Z缓存
	angle=float(3.1415926/3);
	for (int i=0;i<400;i++)
	{
		for (int j=0;j<400;++j)
		{
			color[i][j]=RGB(255,255,255);//
			z_distance[i][j]=-1000;
		}
	}
	n=0;
}

CZ_BufferEliView::~CZ_BufferEliView()
{
}

BOOL CZ_BufferEliView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CZ_BufferEliView drawing

void CZ_BufferEliView::OnDraw(CDC* pDC)
{
	CZ_BufferEliDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
		pDC->TextOut(0,0,"按“X”、“Y”、“Z”键从各方位观看图形");
	// TODO: Add your message handler code here
	CRect rect;
	GetClientRect(&rect);
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	//每次重绘前重新初始化帧缓存和Z缓存
	for (int i=0;i<400;++i)
	{
		for (int j=0;j<400;++j)
		{
			color[i][j]=RGB(255,255,255);
			z_distance[i][j]=-1000;
		}
	}
	FaceBuffer(P1,P4,P3,P2,RGB(255,0,0),pDC);
	FaceBuffer(P5,P8,P7,P6,RGB(0,255,0),pDC);
	FaceBuffer(P1,P2,P6,P5,RGB(0,0,255),pDC);
	FaceBuffer(P4,P3,P7,P8,RGB(255,255,0),pDC);
	FaceBuffer(P1,P4,P8,P5,RGB(255,0,255),pDC);
	FaceBuffer(P2,P3,P7,P6,RGB(0,255,255),pDC);
	for (int y=-200;y<200;++y)
	{
		for (int x=-200;x<200;++x)
		{
			pDC->SetPixel(x,y,color[x+200][y+200]);
		}
	}
	
   P1=DPoint(-100,100,100);P2=DPoint(100,100,100);
   P3=DPoint(100,100,-100);P4=DPoint(-100,100,-100);
   P5=DPoint(-100,-100,100);P6=DPoint(100,-100,100);
   P7=DPoint(100,-100,-100);P8=DPoint(-100,-100,-100);
}

/////////////////////////////////////////////////////////////////////////////
// CZ_BufferEliView printing

BOOL CZ_BufferEliView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CZ_BufferEliView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CZ_BufferEliView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CZ_BufferEliView diagnostics

#ifdef _DEBUG
void CZ_BufferEliView::AssertValid() const
{
	CView::AssertValid();
}

void CZ_BufferEliView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZ_BufferEliDoc* CZ_BufferEliView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZ_BufferEliDoc)));
	return (CZ_BufferEliDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CZ_BufferEliView message handlers

void CZ_BufferEliView::FaceBuffer(DPoint P1, DPoint P2, DPoint P3, DPoint P4, COLORREF m_clr,CDC *pDC)
{
	CPoint p[4];int xleft,xright,ytop,ybottom;
	DFace f(P1,P2,P3,P4);
	int a=f.geta(),b=f.getb(),c=f.getcc(),d=f.getd();
	p[0].x=P1.getx();p[0].y=P1.gety();
	p[1].x=P2.getx();p[1].y=P2.gety();
	p[2].x=P3.getx();p[2].y=P3.gety();
	p[3].x=P4.getx();p[3].y=P4.gety();
	//确定平面的X,Y范围
	xleft=xright=p[0].x;ytop=ybottom=p[0].y;
	for (int i=0;i<4;++i)
	{
		if (p[i].x<xleft)
		{
			xleft=p[i].x;
		}
		if (p[i].x>xright)
		{
			xright=p[i].x;
		}
		if (p[i].y<ybottom) 
		{
			ybottom=p[i].y;
		}
		if (p[i].y>ytop)
		{
			ytop=p[i].y;
		}
	}
	//对XY范围内的点逐个判断是否在多边形内
	for (int y=ybottom;y<=ytop;++y)
	{
		for (int x=xleft;x<=xright;++x)
		{
			CPoint mid(x,y);
			if (IsInSide(mid,p[0],p[1],p[2],p[3])) 
			{
				if (c!=0)
				{	
					double z=((double)(-d-a*x-b*y))/c;
					//z缓冲的过程
					if (z>=z_distance[x+200][y+200])
					{
						color[x+200][y+200]=m_clr;
						z_distance[x+200][y+200]=z;
					}
				}
			}
		}
	}
}


//判断一个点是否在多边形内部
int CZ_BufferEliView::IsInSide(CPoint Px, CPoint P1, CPoint P2, CPoint P3, CPoint P4)
{
	double a1,b1,a2,b2,a3,b3,a4,b4;
	int m=0;	int x=(P1.x+P3.x)/2,y=(P1.y+P3.y)/2;//P1P3中点坐标
	if ((P1.x!=P2.x)&&(P1.x!=P4.x)) 
	{	
		a1=((double)(P2.y-P1.y))/(P2.x-P1.x);//P1P2斜率
		b1=P1.y-a1*P1.x;//P1P2截距
		a2=((double)(P3.y-P2.y))/(P3.x-P2.x);
		b2=P2.y-a2*P2.x;
		a3=a1;
		b3=P3.y-a1*P3.x;
		a4=a2;
		b4=P1.y-a4*P1.x;
		if (((a1*Px.x+b1-Px.y)*(a1*x+b1-y)>0)&&((a3*Px.x+b3-Px.y)*(a3*x+b3-y)>0)&&((a2*Px.x+b2-Px.y)*(a2*x+b2-y)>0)&&((a4*Px.x+b4-Px.y)*(a4*x+b4-y)>0))
		{
			m++;
		}
	}
	else if (P1.x==P2.x)//水平边的处理
	{
		a2=((double)(P3.y-P2.y))/(P3.x-P2.x);
		b2=P2.y-a2*P2.x;
		a4=a2;
		b4=P1.y-a4*P1.x;
		if (P4.x>P1.x)
		{	
			if (((a2*x+b2-y)*(a2*Px.x+b2-Px.y)>0)&&((a4*x+b4-y)*(a4*Px.x+b4-Px.y)>0)&&(P1.x<Px.x)&&(Px.x<P4.x))
			{
				m++;
			}
		}
		else
		{
			if (((a2*x+b2-y)*(a2*Px.x+b2-Px.y)>0)&&((a4*x+b4-y)*(a4*Px.x+b4-Px.y)>0)&&(P4.x<Px.x)&&(Px.x<P1.x))
			{
				m++;
			}
		}
	
	}
	else if (P1.x==P4.x)//水平边的处理
	{
		a1=((double)(P2.y-P1.y))/(P2.x-P1.x);
		b1=P1.y-a1*P1.x;
		a3=a1;
		b3=P3.y-a1*P3.x;
		if (P2.x>P1.x)
		{
			if (((a1*x+b1-y)*(a1*Px.x+b1-Px.y)>0)&&((a3*x+b3-y)*(a3*Px.x+b3-Px.y)>0)&&(P1.x<Px.x)&&(Px.x<P2.x))
			{
				m++;
			}
		}
		else
		{
			if (((a1*x+b1-y)*(a1*Px.x+b1-Px.y)>0)&&((a3*x+b3-y)*(a3*Px.x+b3-Px.y)>0)&&(P2.x<Px.x)&&(Px.x<P1.x))
			{
				m++;
			}
		}
	}
	return m;
}


void CZ_BufferEliView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	double A[16]={1,0,0,0,0,cos(angle),-sin(angle),0,0,sin(angle),cos(angle),0,0,0,0,1};
	Matrix RX(4,4,A,16);

	double B[16]={cos(angle),0,sin(angle),0,0,1,0,0,-sin(angle),0,cos(angle),0,0,0,0,1};
	Matrix RY(4,4,B,16);

	double C[16]={cos(angle),-sin(angle),0,0,sin(angle),cos(angle),0,0,0,0,1,0,0,0,0,1};
	Matrix RZ(4,4,C,16);

	double D[16]={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
	Matrix M(4,4,D,16);
switch(nChar){			
	case 88://按下X,Y,Z键 图形绕三个轴旋转
		num[n]=1;
		break;
	case 89:
		num[n]=2;
		break;
	case 90:
		num[n]=3;
		break;

	default:
		break;
	}
 //保证多次旋转仍能正确显示
  for (int j=0;j<=n;++j)
	{
		if (num[j]==1)
		{
			M=RX*M;
		}
		if (num[j]==2)
		{
			M=RY*M;
		}
		if (num[j]==3)
		{
			M=RZ*M;
		}		
	}
	n++;
	DPoint p[8];
	p[0]=P1;p[1]=P2;p[2]=P3;p[3]=P4;
	p[4]=P5;p[5]=P6;p[6]=P7;p[7]=P8;
	for (int i=0;i<8;++i)
	{
		double x,y,z;
		x=M.p[0][0]*p[i].x+M.p[0][1]*p[i].y+M.p[0][2]*p[i].z+M.p[0][3];
		y=M.p[1][0]*p[i].x+M.p[1][1]*p[i].y+M.p[1][2]*p[i].z+M.p[1][3];
		z=M.p[2][0]*p[i].x+M.p[2][1]*p[i].y+M.p[2][2]*p[i].z+M.p[2][3];
		p[i].x=(int)(x);p[i].y=(int)(y);p[i].z=(int)(z);
	}
	P1=p[0];P2=p[1];P3=p[2];P4=p[3];
	P5=p[4];P6=p[5];P7=p[6];P8=p[7];
	Invalidate();		
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
