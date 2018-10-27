#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Vector
{
	float fx, fy, fz;
};

struct Color
{
	float Ir, Ig, Ib;
};

float KaIa;
float Kd, n;
Vector H,light;
Color mLight, mColor;

void Init()
{
	float mo;
	Vector eye;
	mLight.Ir = 0;
	mLight.Ig = 175;
	mLight.Ib = 0;
	KaIa=100;
	Kd = 0.7;
	n = 20;

	light.fx=0.50;light.fy=0.50;
	light.fz = sqrt(1-(light.fx*light.fx)-(light.fy*light.fy));
	eye.fx=0;eye.fy=0;eye.fz=1;
	H.fx=light.fx+eye.fx;
	H.fy=light.fy+eye.fy;
	H.fz=light.fz+eye.fz;
	mo=sqrt(H.fx*H.fx+H.fy*H.fy+H.fz*H.fz);
	H.fx=(H.fx/mo);H.fy=(H.fy/mo);H.fz=(H.fz/mo);
	H.fx=(H.fx/mo);H.fy=(H.fy/mo);H.fz=(H.fz/mo);

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_SMOOTH);
}

Color Phong(int x0, int y0, int r, int x, int y)
{
	Vector N;
	float z,alpha,theta,Ks;
	Ks=1.0-Kd;
	z=sqrt((float)(r*r-(x-x0)*(x-x0)-(y-y0)*(y-y0)));
	N.fx=(x-x0)*1.0/r;
	N.fy=(y-y0)*1.0/r;
	N.fz = z*1.0/r;
	theta = N.fx * light.fx + N.fy * light.fy + N.fz * light.fz;
	if(theta<0)
		theta=0;
	alpha=H.fx*N.fx+H.fy*N.fy+H.fx*N.fz;
	if(alpha<0)
		alpha=0;
	mColor.Ir=KaIa+mLight.Ir*Kd*theta+mLight.Ir*Ks*pow(alpha,n);
	mColor.Ig=KaIa+mLight.Ig*Kd*theta+mLight.Ig*Ks*pow(alpha,n);
	mColor.Ib=KaIa+mLight.Ib*Kd*theta+mLight.Ib*Ks*pow(alpha,n);
	return mColor;
}

void MidCircle(int x0, int y0, int r)
{
	int x,y,deltax,deltay,d;
	x = 0;
	y = r;
	deltax = 3;
	deltay = 5-r-r;
	d = 1-r;

	glBegin(GL_POINTS);
		{
			for(int i=-x;i<=x;i++)
			{
				mColor=Phong(x0,y0,r,i+x0,y+y0);
				glColor3ub (mColor.Ir, mColor.Ig, mColor.Ib);   glVertex2i (i+x0,y+y0);
				glColor3ub (mColor.Ir, mColor.Ig, mColor.Ib);   glVertex2i (i+x0,-y+y0);
			}
			for(i=-y;i<=y;i++)
			{
				mColor=Phong(x0,y0,r,i+x0,x+y0);
				glColor3ub (mColor.Ir, mColor.Ig, mColor.Ib);   glVertex2i (i+x0,x+y0);
				glColor3ub (mColor.Ir, mColor.Ig, mColor.Ib);   glVertex2i (i+x0,-x+y0);
			}

			while(x<y)
			{
				if(d<0)
				{
					d += deltax;
					deltax += 2;
					deltay += 2;
					x++;
				}
				else
				{
					d += deltay;
					deltax += 2;
					deltay += 4;
					x++;
					y--;
				}

				for(i=-x;i<=x;i++)
				{
					mColor=Phong(x0,y0,r,i+x0,y+y0);
					glColor3ub (mColor.Ir, mColor.Ig, mColor.Ib);   glVertex2i (i+x0,y+y0);
					glColor3ub (mColor.Ir, mColor.Ig, mColor.Ib);   glVertex2i (i+x0,-y+y0);
				}
				for(i=-y;i<=y;i++)
				{
					mColor=Phong(x0,y0,r,i+x0,x+y0);
					glColor3ub (mColor.Ir, mColor.Ig, mColor.Ib);   glVertex2i (i+x0,x+y0);
					glColor3ub (mColor.Ir, mColor.Ig, mColor.Ib);   glVertex2i (i+x0,-x+y0);
				}
			}
		}
	glEnd();
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f (1.0f, 1.0f, 1.0f); 
	MidCircle(250, 250, 60);

	glFlush();
}

void Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w,  (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);
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
	glutMainLoop();
	return 0;
}
