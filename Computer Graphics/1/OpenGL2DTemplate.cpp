#include<glut.h>
#include <math.h>
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	glColor3f(0.56, 0.56, 0);
	glVertex2f(75, 400); // left
	glVertex2f(225, 575); //up 
	glVertex2f(400, 400); // right
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(75, 100); //left down
	glVertex2f(400, 100);  // right down
	glVertex2f(400, 400); // right up 
	glVertex2f(75, 400); // left up
	glEnd();

	glBegin(GL_QUADS);
	//window1
	glColor3f(0.56, 0.56, 0);
	glVertex2f(100, 250); //left down
	glVertex2f(175, 250); // right down
	glVertex2f(175, 325); // right up 
	glVertex2f(100, 325); // left up
	glEnd();

	glBegin(GL_QUADS);
	//window2
	glColor3f(0.56, 0.56, 0);
	glVertex2f(300, 250); // left down
	glVertex2f(375, 250); // right down
	glVertex2f(375, 325); // right up 
	glVertex2f(300, 325); // left up
	glEnd();

	glBegin(GL_QUADS);
	//window1.1
	glColor3f(0, 0, 0);
	glVertex2f(137.5, 250); //left down
	glVertex2f(142.5, 250); // right down
	glVertex2f(142.5, 325); // right up 
	glVertex2f(137.5, 325); // left up
	glEnd();

	glBegin(GL_QUADS);
	//window1.2
	glColor3f(0, 0, 0);
	glVertex2f(100, 287.5); //left down
	glVertex2f(100, 292.5); // right down
	glVertex2f(175, 292.5); // right up 
	glVertex2f(175, 287.5); // left up
	glEnd();

	glBegin(GL_QUADS);
	//window2.1
	glColor3f(0, 0, 0);
	glVertex2f(337.5, 250); // left down
	glVertex2f(342.5, 250); // right down
	glVertex2f(342.5, 325); // right up 
	glVertex2f(337.5, 325); // left up
	glEnd();

	glBegin(GL_QUADS);
	//window2.2
	glColor3f(0, 0, 0);
	glVertex2f(300, 287.5); // left down
	glVertex2f(300, 292.5); // right down
	glVertex2f(375, 292.5); // right up 
	glVertex2f(375, 287.5); // left up
	glEnd();


	glBegin(GL_QUADS);
	//door
	glColor3f(0.56, 0.56, 0);
	glVertex2f(200, 100); // left down
	glVertex2f(275, 100); // right down
	glVertex2f(275, 225); // right up 
	glVertex2f(200, 225); // left up
	glEnd();

	glBegin(GL_QUADS);
	//road
	glColor3f(0.1, 0.1, 0.1);
	glVertex2f(200, 0); // left down
	glVertex2f(275, 0); // right down
	glVertex2f(275, 100); // right up 
	glVertex2f(200, 100); // left up
	glEnd();

	glBegin(GL_QUADS);
	//road2
	glColor3f(1, 1, 1);
	glVertex2f(237.5, 0); // left down
	glVertex2f(242.5, 0); // right down
	glVertex2f(242.5, 100); // right up 
	glVertex2f(237.5, 100); // left up
	glEnd();

	glPopMatrix();
	glFlush();
}
void main() {
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Mohamed Adel 20200233");
	glutDisplayFunc(display);
	glClearColor(0, 0, 0, 0);
	gluOrtho2D(0, 600, 0, 600);
	glutMainLoop();

}
