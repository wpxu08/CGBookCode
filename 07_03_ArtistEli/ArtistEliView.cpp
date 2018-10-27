// ArtistEliView.cpp : implementation of the CArtistEliView class
//

#include "stdafx.h"
#include "ArtistEli.h"
#include "math.h"
#include "ArtistEliDoc.h"
#include "ArtistEliView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CArtistEliView

IMPLEMENT_DYNCREATE(CArtistEliView, CView)

BEGIN_MESSAGE_MAP(CArtistEliView, CView)
	//{{AFX_MSG_MAP(CArtistEliView)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CArtistEliView construction/destruction

CArtistEliView::CArtistEliView()
{

}

CArtistEliView::~CArtistEliView()
{
}

BOOL CArtistEliView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CArtistEliView drawing

void CArtistEliView::OnDraw(CDC* pDC)
{
	CArtistEliDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
   OnCircleFace();
}

/////////////////////////////////////////////////////////////////////////////
// CArtistEliView printing

BOOL CArtistEliView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CArtistEliView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CArtistEliView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CArtistEliView diagnostics

#ifdef _DEBUG
void CArtistEliView::AssertValid() const
{
	CView::AssertValid();
}

void CArtistEliView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CArtistEliDoc* CArtistEliView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CArtistEliDoc)));
	return (CArtistEliDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CArtistEliView message handlers

void CArtistEliView::OnCircleFace()
{
    CClientDC *pdc=new CClientDC(this);
	CPen *pen1=new CPen(PS_SOLID,1,RGB(0,0,0));
	CPen *pen2=new CPen(PS_SOLID,5,RGB(100,0,0));
	CPen *OldPen=pdc->SelectObject(pen1);

	CBrush brush;
    brush.CreateSolidBrush(RGB(0,255,255));
    CBrush *oldbrush=(CBrush*)pdc->SelectObject(&brush);
	int k1,k2,n,m,p;
	int xs1,xs2,xs3,xs4,ys1,ys2,ys3,ys4,lastp;
	double x,y,z,th1,yw,zw,xw,thx,thy,th2;
	double PI,zzw,ppw;
	double xs[50][50],zs[50][50],ys[50][50],zc[50][50],x1,y1;
	int zz[500],pp[500];
    PI=3.14159;
    k1=20;k2=10;
	n=0;
	thx=0.8;

	//计算顶点坐标值
	for(th1=0; th1<=2*PI+0.01;th1+=2*PI/k1)
	{
        n=n+1; m=0;
       for(th2=0;th2<=2*PI+0.01;th2+=2*PI/k2)
	   {
        m=m+1;
        x=200+60*cos(th2);
		y=60*sin(th2);
		z=0;
		thy=th1;
		//绕Y轴旋转
		zw=z; xw=x;
		x=zw*cos(thy)-xw*sin(thy);
		z=zw*sin(thy)+xw*cos(thy);
		// 绕X轴旋转
	    yw=y; zw=z;
		y=yw*cos(thx)-zw*sin(thx);
		z=yw*sin(thx)+zw*cos(thx);
	    //平行投影
        xs[n][m]=x;
        ys[n][m]=y;
        zs[n][m]=z;
	   }
	}
	//对n*m个面片，计算center值
	p=0;
    for(n=1;n<=k1;n+=1)
	  for(m=1;m<=k2;m+=1)
	  {
		zc[n][m]=int((zs[n][m]+zs[n+1][m+1])/2);
        zz[p]=zc[n][m];
        pp[p]=p;
        p=p+1;
	  }

    lastp=p-1;
   //对n*m个面片,按照Z坐标从小到大排序排序
   for(int i=2;i<=lastp;i++)
    for(int j=i-1;j>=0;j--)
	{
		 if(zz[j]>zz[j+1]) 
		 {
           zzw=zz[j];
           zz[j]=zz[j+1];
           zz[j+1]=zzw;
           ppw=pp[j];
           pp[j]=pp[j+1];//面片号
           pp[j+1]=ppw;
		 }
	}
 
  //绘图,平行投影，直接去x,y坐标来绘制
	 for(p=0;p<=lastp;p+=1)
	 {
	  n=int(pp[p]/k2)+1;
	  m=pp[p]%k2+1;
	  if(n!=(k1+1))
	  {
	  xs1=int(xs[n][m]);      ys1=int(ys[n][m]);
	  xs2=int(xs[n+1][m]);    ys2=int(ys[n+1][m]);
	  xs3=int(xs[n+1][m+1]);  ys3=int(ys[n+1][m+1]);
	  xs4=int(xs[n][m+1]);    ys4=int(ys[n][m+1]);
	  //若面片的面积>0，用选定的画刷填充面片
	  if (2*abs(ys1*(xs2-xs3)+ys2*(xs3-xs1)+ys3*(xs1-xs2))>0)
	  {	  
	  pdc->MoveTo(xs1+300,ys1+300);
	  pdc->SelectObject(pen1);
	  pdc->LineTo(xs2+300,ys2+300);
      pdc->LineTo(xs3+300,ys3+300);
      pdc->LineTo(xs4+300,ys4+300);
      pdc->LineTo(xs1+300,ys1+300);
	  //选定种子
      x=(xs[n][m]+xs[n+1][m+1])/2;
      y=(ys[n][m]+ys[n+1][m+1])/2;
      x1=int(x+300);
      y1=int(y+300);
	  //调用种子填充函数
      pdc->ExtFloodFill(x1,y1,RGB(0,0,0),0);
	  }
      //绘制面片的边框
      pdc->MoveTo(xs1+300,ys1+300);
      pdc->SelectObject(pen2);
	  pdc->LineTo(xs2+300,ys2+300);
      pdc->LineTo(xs3+300,ys3+300);
      pdc->LineTo(xs4+300,ys4+300);
      pdc->LineTo(xs1+300,ys1+300);
	  }
	 }
   pdc->SelectObject(OldPen);
   delete pen1;
   delete pen2;
   pdc->DeleteDC();	
}

