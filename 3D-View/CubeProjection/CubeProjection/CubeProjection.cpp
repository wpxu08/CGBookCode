// Projection.cpp : Defines the entry point for the console application.
//
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

struct Matrix
{
	double p[4][4];
	Matrix(int val = 1);//默认val =1 为单位阵，val =0 为零阵
};

double lx = 0, ly = 0, lz = -1;
double phi = 0;
double d = 5;
Matrix mT, mR, mP, mTemp, mA;
int flag = 1; // display cube with wireframe 1 or face mode 2

GLfloat vertices0[8][3] = { {-1.0, -1.0, 1.0},{-1.0, 1.0, 1.0},{1.0,1.0, 1.0},{1.0,-1.0,1.0},  
{-1.0,-1.0,-1.0}, {-1.0,1.0,-1.0},{1.0,1.0,-1.0}, {1.0,-1.0,-1.0} };

GLfloat vertices1[8][2] = { {-1.0,-1.0},{1.0,-1.0},{1.0,1.0},{-1.0,1.0},
{-1.0,-1.0},{1.0,-1.0},{1.0,1.0},{-1.0,1.0} };

GLfloat colors[6][3] = { {1.0,1.0,1.0}, {1.0,0.0,0.0}, {1.0,1.0,0.0},
{0.0,0.0,1.0}, {1.0,0.0,1.0}, {0.0,1.0,1.0} };

Matrix::Matrix(int val)
{
	for (long i = 0; i < 4; i++) {
		for (long j = 0; j < 4; j++) {
			if (i == j) p[i][j] = val;
			else p[i][j] = 0;
		}
	}
}

Matrix Multiply(Matrix& m1, Matrix& m2)
{
	Matrix m(0);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				m.p[i][j] += (m1.p[i][k] * m2.p[k][j]);

	return m;
}

void InitParameter()//初始化参数
{
	mT.p[3][0] = lx; mT.p[3][1] = ly; mT.p[3][2] = lz;
	mR.p[0][0] = cos(phi); mR.p[0][2] = -sin(phi); mR.p[2][0] = sin(phi); mR.p[2][2] = cos(phi);

	mP.p[2][2] = 0;
	mP.p[2][3] = -1 / d;

	mTemp = Multiply(mT, mR);
	mA = Multiply(mTemp, mP);
}

void Project(int num, GLfloat vertices0[][3], GLfloat vertices1[][2])//透视变换
{
	for (int i = 0; i < num; i++)
	{
		GLfloat ptH[4] = { vertices0[i][0], vertices0[i][1], vertices0[i][2], 1 };//齐次坐标
		GLfloat res[4] = {0, 0, 0, 0};

		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				res[j] += (ptH[k] * mA.p[k][j]);

		vertices1[i][0] = res[0] / res[3];
		vertices1[i][1] = res[1] / res[3];
	}
}

void Polygon(int clr, int a, int b, int c, int d)
{
	glColor3fv(colors[clr]);
	if (flag == 1)
		glBegin(GL_LINE_LOOP);
	else
		glBegin(GL_POLYGON);

	glVertex2fv(vertices1[a]);
	glVertex2fv(vertices1[b]);
	glVertex2fv(vertices1[c]);
	glVertex2fv(vertices1[d]);
	glEnd();
}

void ColorCube(void)
{
	Polygon(0, 0, 3, 2, 1);
	Polygon(1, 2, 3, 7, 6);
	Polygon(2, 0, 4, 7, 3);
	Polygon(3, 1, 2, 6, 5);
	Polygon(4, 4, 5, 6, 7);
	Polygon(5, 0, 1, 5, 4);
	//Polygon(0, 0, 3, 2, 1);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	InitParameter();

	Project(8, vertices0, vertices1);
	ColorCube();

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
	glOrtho(-5, 5, -5, 5, -10, 10);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1':
		flag = 1;
		glutPostRedisplay();
		break;
	case '2':
		flag = 2;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Hello World!");

	glutDisplayFunc(myDisplay);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}