// Projection.cpp : Defines the entry point for the console application.
//
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

struct Matrix
{
	double p[4][4];

	Matrix operator*(Matrix &);
	Matrix();//单位矩阵
};

Matrix::Matrix()
{
	for (long i = 0; i < 4; i++) {
		for (long j = 0; j < 4; j++) {
			if (i == j) p[i][j] = 1;
			else p[i][j] = 0;
		}
	}
}

Matrix Multiply(Matrix& m1, Matrix& m2)
{
	Matrix m;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				m.p[i][j] += (m1.p[i][k] * m2.p[k][j]);

	return m;
}

struct Pt2D {
	int x, y;
	Pt2D() { x = 0; y = 0; };
	Pt2D(int px, int py) { x = px; y = py; };
};

struct Pt3D
{
	float x, y, z;

	Pt3D() { x = 0; y = 0; z = 0; };
	Pt3D(float px, float py, float pz) { x = px; y = py; z = pz; };
};


struct FaceInfo {//第一列为每个面的顶点数；其余列为面的顶点编号
	int num, idx1, idx2, idx3, idx4;
	FaceInfo() { num = 0; idx1 = 0; idx2 = 0; idx3 = 0; idx4 = 0; };
	FaceInfo(int fnum, int fidx1, int fidx2, int fidx3, int fidx4)
	{
		num = fnum; idx1 = fidx1; idx2 = fidx2; idx3 = fidx3; idx4 = fidx4;
	};
};

int bl = 100;//box length
//double lx = 0, ly = 0, lz = -50;
double lx = 600, ly = 600, lz = -50;
//double phi = -30;
double phi = 0;
double d = 500;
Matrix mT, mR, mP, mTemp, mA;
Pt3D boxPt[8];
Pt2D boxPt2d[8];
FaceInfo fInfo[6];

void InitParameter()//初始化参数
{
	mT.p[3][0] = lx; mT.p[3][1] = ly; mT.p[3][2] = lz;
	mR.p[0][0] = cos(phi); mR.p[0][2] = -sin(phi); mR.p[2][0] = sin(phi); mR.p[2][2] = cos(phi);

	mP.p[2][2] = 0;
	mP.p[2][3] = -1/d;

	mTemp = Multiply(mT, mR);
	mA = Multiply(mTemp, mP);
}

void Project(Pt3D pt, Pt2D &pt2D)//透视变换
{
	double ptH[4];
	ptH[0] = pt.x;//
	ptH[1] = pt.y;
	ptH[2] = pt.z;
	ptH[3] = 1;

	double res[4];
	for (int i = 0; i < 4; i++)
		res[i] = 0;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			res[i] += (ptH[j] * mA.p[j][i]);

	pt2D = Pt2D(res[0] / res[3], res[1] / res[3]);
}

void LineGL(Pt2D pt0, Pt2D pt1)
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(pt0.x, pt0.y);
	glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(pt1.x, pt1.y);
	glEnd();
}

int GetPtIdx(FaceInfo fInfo, int ptIdx)
{
	int idx = 0;
	switch (ptIdx)
	{
	case 1:
		idx = fInfo.idx1;
		break;
	case 2:
		idx = fInfo.idx2;
		break;
	case 3:
		idx = fInfo.idx3;
		break;
	case 4:
		idx = fInfo.idx4;
		break;
	default:
		break;
	}
	return idx;
}

void BoxProject()
{
	int ptIdx;
	Pt2D pt2D;
	for (int face = 0; face < 6; face++)
	{
		int num = fInfo[face].num;//面的总边数
		for (int i = 0; i < num; i++)//边循环
		{
			ptIdx = GetPtIdx(fInfo[face], i);//面的顶点号
			Project(boxPt[ptIdx], pt2D);
			boxPt2d[ptIdx] = pt2D;
		}
	}
}

void DrawBox()
{
	int ptIdx[4];
	for (int face = 0; face < 4; face++)
	{
		int num = fInfo[face].num;//面的总顶点数
		for (int i = 0; i < num; i++)//循环
		{
			ptIdx[i] = GetPtIdx(fInfo[face], i + 1);//面的顶点号			
		}

		for (int j = 0; j < 4; j++)
		{
			int idx0 = ptIdx[j];
			int idx1 = ((j == 3) ? ptIdx[0] : ptIdx[j + 1]);
			LineGL(boxPt2d[idx0], boxPt2d[idx1]);
		}
	}
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	InitParameter();
	BoxProject();
	DrawBox();

	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.0f, 0.0f);
	glEnd();

	glPointSize(3);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(50.0f, 50.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(boxPt2d[2].x, boxPt2d[2].y);
	glEnd();

	glutSwapBuffers();
}

void Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);

	printf("Hello Cube!\n");
}

void Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'x':
		//exit(0);
		break;
	default:
		break;
	}
}

void ReadPoint()//读入8个顶点坐标
{
	boxPt[0] = Pt3D(-bl / 2, -bl / 2, -bl / 2);
	boxPt[1] = Pt3D(-bl / 2, bl / 2, -bl / 2);
	boxPt[2] = Pt3D(-bl / 2, bl / 2, bl / 2);
	boxPt[3] = Pt3D(-bl / 2, -bl / 2, bl / 2);

	boxPt[4] = Pt3D(bl / 2, -bl / 2, -bl / 2);
	boxPt[5] = Pt3D(bl / 2, bl / 2, -bl / 2);
	boxPt[6] = Pt3D(bl / 2, bl / 2, bl / 2);
	boxPt[7] = Pt3D(bl / 2, -bl / 2, bl / 2);
}

void ReadFace()//读入6个面坐标
{
	fInfo[0] = FaceInfo(4, 0, 1, 2, 3);
	fInfo[1] = FaceInfo(4, 0, 3, 7, 4);
	fInfo[2] = FaceInfo(4, 4, 5, 6, 7);

	fInfo[3] = FaceInfo(4, 5, 1, 2, 6);
	fInfo[4] = FaceInfo(4, 7, 6, 2, 3);
	fInfo[5] = FaceInfo(4, 4, 5, 1, 0);
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Hello World!");

	ReadPoint();
	ReadFace();

	glutDisplayFunc(myDisplay);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}