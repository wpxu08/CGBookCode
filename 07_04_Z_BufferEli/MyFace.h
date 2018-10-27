////////////////////////////////点类
class DPoint
{
public:
	DPoint(){x=0;y=0;z=0;}            //默认构造函数
	DPoint(int a,int b,int c):x(a),y(b),z(c){}   //构造函数
	DPoint(const DPoint&p):x(p.x),y(p.y),z(p.z){}  //复制构造函数
	DPoint&operator=(const DPoint&rhs)           //赋值操作
	{
		x=rhs.x;y=rhs.y;z=rhs.z;
		return *this;
	}
	friend inline int operator==(const DPoint&p1,const DPoint&p2)  //判断点是否相等,是返回1,否则返回0
	{
		if (p1.x==p2.x&&p1.y==p2.y&&p1.z==p2.z)
		{
			return 1;
		}
		else
			return 0;
	}
	friend inline int operator!=(const DPoint&p1,const DPoint&p2)  //判断点是否不相等,是返回0,否则返回1
	{
		if ((p1.x!=p2.x)||(p1.y!=p2.y)||(p1.z!=p2.z)) 
		{
			return 1;
		}
		else
			return 0;
	}
	void setx(int a)
	{
		x=a;
	}
	void sety(int b)
	{
		y=b;
	}
	void setz(int c)
	{
		z=c;
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
	int getz()
	{
		return z;
	}
protected:
public:
	int x;
	int y;
	int z;
};


/////////////////////////////////////////////线类
class DLine
{
public:
	DLine(int a,int b,int c,int d,int e,int f):p1(a,b,c),p2(d,e,f){}     //构造函数
	DLine():p1(0,0,0),p2(0,0,0){}                            //默认构造函数
	DLine(DPoint x,DPoint y):p1(x),p2(y){}
	DPoint getp1()
	{
		return p1;
	}
	DPoint getp2()
	{
		return p2;
	}
	DLine(const DLine&l)                                 //复制构造函数
	{
		p1=l.p1;
		p2=l.p2;
	}
	DLine&operator=(const DLine&rhs)                     //赋值操作
	{
		p1=rhs.p1;p2=rhs.p2;
		return *this;
	}

	friend int intersect(const DLine&l1,const DLine&l2)         //判断线段是否有公共点,有返回1,否则返回0
	{
		if ((l1.p1==l2.p1)||(l1.p1==l2.p2)||(l1.p2==l2.p1)||(l1.p2==l2.p2))
		{
			return 1;
		}
		else 
			return 0;
	}
protected:
private:
	DPoint p1;
	DPoint p2;
};

////////////////////////////面类
class DFace
{
public:
	DFace():p1(0,0,0),p2(0,0,0),p3(0,0,0),p4(0,0,0),L1(0,0,0,0,0,0),L2(0,0,0,0,0,0),L3(0,0,0,0,0,0),L4(0,0,0,0,0,0),a(0),b(0),c(0),d(0)
	{
//		a=b=c=d=0;
	}  //默认构造函数
	DFace(DPoint x,DPoint y,DPoint z,DPoint w):p1(x),p2(y),p3(z),p4(w),L1(x,y),L2(y,z),L3(z,w),L4(w,x)   //构造函数
	{
		int x1=x.getx(),y1=x.gety(),z1=x.getz();
		int x2=y.getx(),y2=y.gety(),z2=y.getz();
		int x3=z.getx(),y3=z.gety(),z3=z.getz();
		int x4=w.getx(),y4=w.gety(),z4=w.getz();
		a=(int)((y1-y2)*(z1+z2)+(y2-y3)*(z2+z3)+(y3-y4)*(z3+z4)+(y4-y1)*(z4+z1));
		b=(int)((z1-z2)*(x1+x2)+(z2-z3)*(x2+x3)+(z3-z4)*(x3+x4)+(z4-z1)*(x4+x1));
		c=(int)((x1-x2)*(y1+y2)+(x2-x3)*(y2+y3)+(x3-x4)*(y3+y4)+(x4-x1)*(y4+y1));
		d=(int)(-(a*x1+b*y1+c*z1));
	}
	int geta()
	{
		return a;
	}
	int getb()
	{
		return b;
	}
	int getcc()
	{
		return c;
	}
	int getd()
	{
		return d;
	}

private:
	DPoint p1,p2,p3,p4;
	DLine L1,L2,L3,L4;
	int a;
	int b;
	int c;
	int d;
};