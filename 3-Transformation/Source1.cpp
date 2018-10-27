#include <GL/glut.h>

#include <stdlib.h>

GLfloat   rtri;//��������ת�Ƕ�



void init(void) 

{

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glShadeModel(GL_SMOOTH);//��Ϊsmooth����ʽ��ע�⿴����

	glEnable(GL_DEPTH_TEST);//������Ȳ���

}



void display(void)

{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    //�����ɫ�������Ȼ���

	glLoadIdentity();

	glTranslatef(-1.5f,0.0f,-6.0f);//�볢���޸Ĵ˺������������÷����������

	glRotatef(rtri,0.0f,1.0f,0.0f);//�볢���޸Ĵ˺������������÷����������

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f,0.0f,0.0f);

	glVertex3f( 0.0f, 1.0f, 0.0f);

	glColor3f(0.0f,1.0f,0.0f);

	glVertex3f(-1.0f,-1.0f, 1.0f);

	glColor3f(0.0f,0.0f,1.0f);

	glVertex3f( 1.0f,-1.0f, 1.0f);



	glColor3f(1.0f,0.0f,0.0f);

	glVertex3f( 0.0f, 1.0f, 0.0f);

	glColor3f(0.0f,0.0f,1.0f);

	glVertex3f( 1.0f,-1.0f, 1.0f);

	glColor3f(0.0f,1.0f,0.0f);

	glVertex3f( 1.0f,-1.0f, -1.0f);



	glColor3f(1.0f,0.0f,0.0f);

	glVertex3f( 0.0f, 1.0f, 0.0f);

	glColor3f(0.0f,1.0f,0.0f);

	glVertex3f( 1.0f,-1.0f, -1.0f);

	glColor3f(0.0f,0.0f,1.0f);

	glVertex3f(-1.0f,-1.0f, -1.0f);



	glColor3f(1.0f,0.0f,0.0f);

	glVertex3f( 0.0f, 1.0f, 0.0f);

	glColor3f(0.0f,0.0f,1.0f);

	glVertex3f(-1.0f,-1.0f,-1.0f);

	glColor3f(0.0f,1.0f,0.0f);

	glVertex3f(-1.0f,-1.0f, 1.0f);

	glEnd();





	rtri+=0.1f;//��һ���Ƕ�

	glutSwapBuffers();//����˫����

}



void reshape (int width, int height)

{

	glViewport(0, 0, width, height); 

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

}



void keyboard(unsigned char key, int x, int y)

{//��ο����任ʾ���ο���һ�ģ�������Ӽ����������ʽ�����ƽ���������ת

	switch (key)

	{

	case ��x��:

		exit(0);

		break;

	default:

		break;

	}

}



int main(int argc, char** argv)

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//ʹ��˫����ģʽ����Ȼ���

	glutInitWindowSize(640, 480); 

	glutInitWindowPosition(100, 100);

	glutCreateWindow("Transform2");

	init();

	glutDisplayFunc(display); 

	glutReshapeFunc(reshape);

	glutKeyboardFunc(keyboard);

	glutIdleFunc(display);//���ÿ���ʱ���õĺ���

	glutMainLoop();

	return 0;

}

