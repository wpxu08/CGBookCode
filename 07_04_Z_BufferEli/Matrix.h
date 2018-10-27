
class Matrix
{
public:
	int ROW;                       //����
	int COL;                       //����
	double **p; 
public:
	Matrix(int m=0,int n=0,double *A=NULL,int k=0)//;	       //����Ĺ��캯��
	{
		ROW=m;                         //ָ������
		COL=n;                         //ָ������                             
		p=new double*[ROW];               //����Ԫ��Ϊָ��,����ΪROW������
		for(int i=0;i<ROW;++i)
		{
			p[i]=new double[COL];         //p[i]�ǳ���ΪCOL�������ָ��
			for (int j=0;j<COL;++j)
			{
				p[i][j]=A[i*n+j];          //��һά���鹹���ά��
			}	
		}
	}
	~Matrix()//;                     //�������������
	{
		for(int i=0;i<ROW;++i)
		{
			delete []p[i];             //�ͷ����� 
		}
	}

	Matrix&operator=(Matrix&s)//;     //��ֵ���������
	{
		ROW=s.ROW;
		COL=s.COL;
		p=new double*[ROW];               //����Ԫ��Ϊָ��,����ΪROW������
		for(int i=0;i<ROW;++i)
		{
			p[i]=new double[COL];         //p[i]�ǳ���ΪCOL�������ָ��
			for (int j=0;j<COL;++j)
			{
				p[i][j]=s.p[i][j];          //��һά���鹹���ά��
			}	
		}
		return *this;
	}
	Matrix&operator*(Matrix&t)//;       //����Ԫ�����˷����������
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