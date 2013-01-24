/*
 * Author: Li Mingyi
 * Filename: mandelbrot-set.c
 * Version: 1.00
 * Date: 2012.9.12
 * Description: Using OpenGL API to draw mandelbrot set.
 */

#include <stdio.h>
#include <GL/glut.h>

#define N 1000
#define WIDTH 640
#define HEIGHT 480

typedef struct complexs
{
	double re;
	double im;
}complex_t;

complex_t add(const complex_t *a, const complex_t *b);
complex_t mul(const complex_t *a, const complex_t *b);
complex_t mandel_ifs(const complex_t *z, const complex_t *c);

int dwell(complex_t c);
void display(void);
void reshape(int width, int height);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(200, 200);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);

	glutCreateWindow("Mandelbrot Set");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();

	return 0;
}

complex_t add(const complex_t *a, const complex_t *b)
{
	complex_t tmp;

	tmp.re = a->re + b->re;
	tmp.im = a->im + b->im;

	return tmp;
}

complex_t mul(const complex_t *a, const complex_t *b)
{
	complex_t tmp;

	tmp.re = a->re * b->re - a->im * b->im;
	tmp.im = a->re * b->im + a->im * b->re;

	return tmp;
}

complex_t mandel_ifs(const complex_t *z, const complex_t *c)
{
	complex_t tmp,result;

	tmp = mul(z, z);
	result = add(&tmp, c);

	return result;
}

void display(void)
{
	int x, y, d;
	complex_t c,z;
	
	z.re = 0;
	z.im = 0;
	c.re = -2;
	c.im = -1.5;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);


	glBegin(GL_POINTS);

	for(y=0; y<HEIGHT; y++)
	{
		for(x=0; x<WIDTH; x++)
		{
			complex_t c;
			c.re = -2.0 + (2.0 - (-2.0)) / WIDTH * x;
			c.im = -1.5 + (1.5 - (-1.5)) / HEIGHT * y;
			d = dwell(c);
			if(d == N+1)
				glColor3f(1.0, 1.0, 1.0);
			else
			{
				d = d % 6;
				switch(d)
				{
					case 1: glColor3f(1.0, 0.0, 0.0);break;
					case 2: glColor3f(0.0, 1.0, 0.0);break;
					case 3: glColor3f(0.0, 0.0, 1.0);break;
					case 4: glColor3f(1.0, 1.0, 0.0);break;
					case 5: glColor3f(1.0, 0.0, 1.0);break;
					case 6: glColor3f(0.0, 1.0, 1.0);break;
				}
			}
			glVertex2d(x,y);
		}
	}
	glEnd();

	glFlush();
}

void reshape(int width, int height)
{
	glViewport(0,0, (GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) width, 0.0, (GLdouble) height);
}

int dwell(complex_t c)
{
	complex_t z;
	int count = 0;

	z.re = 0;
	z.im = 0;

	while (count++ < N)
	{
		z = mul(&z, &z);
		z = add(&z, &c);
		if ( z.re*z.re + z.im*z.im > 4.0 )
			break;
	}
	return count;
}

