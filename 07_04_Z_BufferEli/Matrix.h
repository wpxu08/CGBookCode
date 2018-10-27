
class Matrix
{
public:
	int ROW;                       //行数
	int COL;                       //列数
	double **p; 
public:
	Matrix(int m=0,int n=0,double *A=NULL,int k=0)//;	       //矩阵的构造函数
	{
		ROW=m;                         //指定行数
		COL=n;                         //指定列数                             
		p=new double*[ROW];               //生成元素为指针,长度为ROW的数组
		for(int i=0;i<ROW;++i)
		{
			p[i]=new double[COL];         //p[i]是长度为COL的数组的指针
			for (int j=0;j<COL;++j)
			{
				p[i][j]=A[i*n+j];          //用一维数组构造二维数
			}	
		}
	}
	~Matrix()//;                     //矩阵的析构函数
	{
		for(int i=0;i<ROW;++i)
		{
			delete []p[i];             //释放数组 
		}
	}

	Matrix&operator=(Matrix&s)//;     //赋值运算符重载
	{
		ROW=s.ROW;
		COL=s.COL;
		p=new double*[ROW];               //生成元素为指针,长度为ROW的数组
		for(int i=0;i<ROW;++i)
		{
			p[i]=new double[COL];         //p[i]是长度为COL的数组的指针
			for (int j=0;j<COL;++j)
			{
				p[i][j]=s.p[i][j];          //用一维数组构造二维数
			}	
		}
		return *this;
	}
	Matrix&operator*(Matrix&t)//;       //用友元声明乘法运算符重载
	{
		int m=ROW,n=COL,k=t.COL;
		Matrix result;
		result.ROW=m;result.COL=k;
		result.p=new double*[m];
		for(int i=0;i<m;++i)
		{	
			result.p[i]=new double[k]; 
			for(int j=0;j<k;++j)
			{
				result.p[i][j]=0;
				for(int l=0;l<n;++l)
				result.p[i][j]+=p[i][l]*t.p[l][j];
			}
		}
		ROW=result.ROW;COL=result.COL;
		for (i=0;i<ROW;++i)
		{
			for (int j=0;j<COL;++j)
			{
				p[i][j]=result.p[i][j];
			}
		}
		return *this;	
	}
  
};