// Cube.cpp : Defines the entry point for the console application.
//
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

int flag = 1;
GLfloat vertices[8][3] = { {-1.0, -1.0, 1.0},{-1.0, 1.0, 1.0},{1.0,1.0, 1.0},{1.0,-1.0,1.0},
{-1.0,-1.0,-1.0}, {-1.0,1.0,-1.0},{1.0,1.0,-1.0}, {1.0,-1.0,-1.0} };

GLfloat colors[6][3] = { {1.0,1.0,1.0}, {1.0,0.0,0.0}, {1.0,1.0,0.0},
{0.0,0.0,1.0}, {1.0,0.0,1.0}, {0.0,1.0,1.0} };

void Polygon(int clr, int a, int b, int c, int d)
{
	glColor3fv(colors[clr]);
	if (flag == 1)
		glBegin(GL_LINE_LOOP);
	else
		glBegin(GL_POLYGON);

	glVertex3fv(vertices[a]);
	glVertex3fv(vertices[b]);
	glVertex3fv(vertices[c]);
	glVertex3fv(vertices[d]);
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
	//glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(1.0f, 0.0f, 0.0f);

	//InitParameter();

	//Project(8, vertices0, vertices1);
	//ColorCube();

	//glutSwapBuffers();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//gluLookAt(3, 3, 3, 0, 0, 0, 0, 1, 0);
	glTranslatef(1.5f, 0.0f, -6.0f);	//平移到右侧
	//glRotatef(rquad, 1.0f, 0.0f, 0.0f);	//旋转一个角度
	//glTranslatef(10, 0, 0);
	//glRotatef(theta[0], 1.0, 0.0, 0.0);
	//glRotatef(theta[1], 0.0, 1.0, 0.0);
	//glRotatef(theta[2], 0.0, 0.0, 1.0);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//flag = 0;
	ColorCube();  //绘制彩色立方体

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//flag = 1;
	//colorcube();  //绘制彩色立方体

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
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//定义正交投影观察体
	//if (w <= h)
	//	glOrtho(-4.0, 4.0, -4.0*(GLfloat)h / (GLfloat)w, 4.0*(GLfloat)h / (GLfloat)w, -100.0, 100.0);
	//else
	//	glOrtho(-4.0*(GLfloat)w / (GLfloat)h, 4.0*(GLfloat)w / (GLfloat)h, -4.0, 4.0, -100.0, 100.0);

	//gluPerspective(120,w/h,1,60);   //定义透视投影投影观察体
	gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, -100.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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