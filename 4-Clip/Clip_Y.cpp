#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

void LineGL(int x0,int  y0,int x1,int y1)
{
	glBegin (GL_LINES);
	glColor3f (1.0f, 0.0f, 0.0f);   glVertex2f (x0,y0);
	glColor3f (0.0f, 1.0f, 0.0f);   glVertex2f (x1,y1);	
	glEnd ();
}

struct outcode
{
	unsigned all;
	unsigned left,right,top,bottom;
};

struct Rectangle
{
	float xmin,xmax,ymin,ymax;
};

Rectangle  rect;
int x0,y0,x1,y1;
GLboolean bClip = false;

void compoutcode(float x,float y,Rectangle rect,outcode *outcode)
{
	outcode->all=0;
	outcode->top=outcode->bottom=0;
	if(y>(float)rect.ymax)
	{
		outcode->top=1;    
		outcode->all+=1;
	}
	else if(y<(float)rect.ymin)
	{
		outcode->bottom=1;
		outcode->all+=1;
	}
	outcode->right=outcode->left=0;
	if(x>(float)rect.xmax)
	{ 
		outcode->right=1;
		outcode->all+=1;
	}
	else if(x<(float)rect.xmin)
	{
		outcode->left=1;
		outcode->all+=1;
	}
}

int cohensutherlandlineclip(Rectangle  rect, int &x0,int & y0,int &x1,int &y1)
{
	int accept,done;
	outcode outcode0,outcode1;
	outcode * outcodeout;
	float x,y;
	accept=0;
	done=0;
	compoutcode(x0,y0,rect,&outcode0);
	compoutcode(x1,y1,rect,&outcode1);
	do{
		if(outcode0.all==0&&outcode1.all==0)
		{
			accept=1;
			done=1;
		}
		else if(outcode0.all&outcode1.all!=0)
			done=1;
		else
		{   
			if(outcode0.all!=0)
				outcodeout=&outcode0;
			else
				outcodeout=&outcode1;

			if(outcodeout->left)
			{
				y=y0+(y1-y0)*(rect.xmin-x0)/(x1-x0);
				x=(float)rect.xmin;
			}
			else if(outcodeout->top)
			{
				x=x0+(x1-x0)*(rect.ymax-y0)/(y1-y0);
				y=(float)rect.ymax;
			}
			else if(outcodeout->right)
			{
				y=y0+(y1-y0)*(rect.xmax-x0)/(x1-x0);
				x=(float)rect.xmax;
			}
			else if(outcodeout->bottom)
			{
				x=x0+(x1-x0)*(rect.ymin-y0)/(y1-y0);
				y=(float)rect.ymin; 
			}
			if(outcodeout->all==outcode0.all)
			{ 
				x0=x;y0=y;compoutcode(x0,y0,rect,&outcode0);
			}
			else
			{
				x1=x;y1=y;
				compoutcode(x1,y1,rect,&outcode1); 
			}
		}
	}while(!done);

	if(accept)
		LineGL(x0,y0,x1,y1); 
	return accept;
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f (1.0f, 0.0f, 0.0f); 
	glRectf(rect.xmin,rect.ymin,rect.xmax,rect.ymax);

	if (!bClip)
		LineGL(x0,y0,x1,y1);
	else
		cohensutherlandlineclip(rect, x0,y0,x1,y1);	

	glFlush();
}

void Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);

	rect.xmin=100; //窗口的大小
	rect.xmax=300; 
	rect.ymin=100; 
	rect.ymax=300;

	x0 = 450,y0 = 0, x1 = 0, y1 = 450;//裁剪前的直线端点
	printf("Press key 'c' to Clip!\nPress key 'r' to Restore!\n");
}

void Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w,  (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'c':
		bClip = true;
		glutPostRedisplay();//重画
		break;
	case 'r':
		bClip = false;
		Init();
		glutPostRedisplay();//
		break;
	case 'x':
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Hello World!");

	Init();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
