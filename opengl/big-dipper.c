/*
 * Author: Li Mingyi
 * Filename: big-dipper.c
 * Version: 1.00
 * Date: 2012.9.12
 * Description: Use OpenGL API to draw big-dipper. It is a very simple examples
 * 		of drawing points by OpenGL.
 */

#include <GL/glut.h>

void display(void);
void reshape(int width, int height);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 200);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Big Dipper");

	glClearColor(0.0, 0.0, 0.0 ,0.0);
	glShadeModel(GL_FLAT);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();

	return 0;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	

	glBegin(GL_LINE_STRIP);
		glVertex2f(50 , 100);
		glVertex2f(65 , 50 );
		glVertex2f(125, 50 );
		glVertex2f(135, 95 );
		glVertex2f(185, 115);
		glVertex2f(235, 130);
		glVertex2f(285, 140);
		glVertex2f(330, 120);
	glEnd();

	glBegin(GL_LINES);
		glVertex2f(50 , 100);
		glVertex2f(135, 95 );
	glEnd();

	glPointSize(6.0);
	glBegin(GL_POINTS);
		glVertex2f(50 , 100);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(65 , 50 );
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(125, 50 );
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(135, 95 );
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(185, 115);
		glColor3f(1.0, 0.0, 1.0);
		glVertex2f(235, 130);
		glColor3f(0.0, 1.0, 1.0);
		glVertex2f(285, 140);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(330, 120);
	glEnd();

	glFlush();
}

void reshape(int width, int height)
{
	glViewport (0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, (GLdouble) width, 0.0, (GLdouble) height);
}
