#include <glut.h>
GLUquadricObj* gl = gluNewQuadric();
int k = 0;
void Display() {
	
	if (k == 0) {
		glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex2f(200, 340);
		glVertex2f(335, 420);
		glVertex2f(255, 470);
		glVertex2f(270, 420);
		glVertex2f(180, 455);
		glVertex2f(190, 380);
		glVertex2f(155, 390);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glTranslated(1000, 0, 0);
		glScaled(-1, 1, 1);
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex2f(200, 340);
		glVertex2f(335, 420);
		glVertex2f(255, 470);
		glVertex2f(270, 420);
		glVertex2f(180, 455);
		glVertex2f(190, 380);
		glVertex2f(155, 390);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glTranslated(200, 295,0);
		glRotated(-45, 0, 0, 1);
		glTranslated(-200, -295,0);
		glScaled(2, 2, 1);
		glTranslated(-100, -60, 0);
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex2f(200, 295);
		glVertex2f(335, 420);
		glVertex2f(255, 470);
		glVertex2f(270, 420);
		glVertex2f(180, 455);
		glVertex2f(190, 380);
		glVertex2f(155, 390);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glBegin(GL_QUADS);
		glVertex2f(200, 340);
		glVertex2f(800, 340);
		glVertex2f(800, 420);
		glVertex2f(200, 420);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslated(285, 275, 0);
		gluDisk(gl, 0, 100, 50, 50);
		glPopMatrix();

		glPushMatrix();
		glColor3f(1, 1, 1);
		glTranslated(285, 240, 0);
		gluDisk(gl, 0, 80, 50, 50);
		glPopMatrix();
		glPushMatrix();
		glColor3f(0,0, 0);
		glTranslated(295, 240, 0);
		gluDisk(gl, 0, 75, 50, 50);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslated(725, 275, 0);
		gluDisk(gl, 0, 100, 50, 50);
		glPopMatrix();

		glPushMatrix();
		glColor3f(1, 1, 1);
		glTranslated(725, 240, 0);
		gluDisk(gl, 0, 80, 50, 50);
		glPopMatrix();
		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslated(735, 240, 0);
		gluDisk(gl, 0, 75, 50, 50);
		glPopMatrix();

		glPushMatrix();
		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex2f(550, 370);
		glVertex2f(450, 370);
		glVertex2f(450, 200);
		glVertex2f(550, 200);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex2f(525, 310);
		glVertex2f(475, 310);
		glVertex2f(475, 160);
		glVertex2f(525, 160);
		glEnd();
		glPopMatrix();


		glFlush();
	}
	else {
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
	}
}
void specialInput(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_UP:
		k = 0;
		break;
	case GLUT_KEY_DOWN:
		k = 1;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void main(int argc, char** argr) {
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("mahmoud sanad 20200211");
	glutDisplayFunc(Display);
	glutSpecialFunc(specialInput);
	glClearColor(0, 0, 0, 0);
	gluOrtho2D(0, 1000, 0, 1000);
	glutMainLoop();
}