#include<glut.h>
#include <math.h>
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslated(100, 100, 0);
	glScaled(20, 1, 1);
	glTranslated(-100, -100, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex2f(100, 100);
	glVertex2f(200, 100);
	glVertex2f(200, 200);
	glVertex2f(100, 200);
	glEnd();
	glPopMatrix();
	glFlush();
}
void main() {
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("tringles");
	glutDisplayFunc(display);
	glClearColor(0, 0, 0, 0);
	gluOrtho2D(0, 600, 0, 600);
	glutMainLoop();

}
