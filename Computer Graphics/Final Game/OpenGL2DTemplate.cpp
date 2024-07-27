#include<Windows.h>
#include<MMSystem.h>
#include<glut.h>
#include<math.h>

bool lose = false;
bool win = false;
int zombie1Move = 0;
int enemy1Health = 100;
int enemy2Health = 100;
int enemy3Health = 100;
int enemy4Health = 100;
int zombie4Move = 0;
int zombie2Move = 0;
int zombie3Move = 0;
int characterMove = 0;
bool tal2 = false;
int tal2X = 0;
int score = 0;
int speed1 = 0;
int speed2 = 0;
int speed3 = 0;
int speed4 = 0;
char scoreText[10] = { '0' };

GLUquadricObj* gl = gluNewQuadric();


void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	if (win) {
		glClearColor(0, 0, 0, 0);
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
		glTranslated(200, 295, 0);
		glRotated(-45, 0, 0, 1);
		glTranslated(-200, -295, 0);
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
		glColor3f(0, 0, 0);
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
	}
	else if (lose) {
		glClearColor(1, 0, 0,0);
		glPushMatrix();
		glColor3ub(0, 0, 0);
		glRasterPos3f(700, 500, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scoreText[0]);
		glRasterPos3f(720, 500, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scoreText[1]);
		glPopMatrix();
		glPushMatrix();
		glRasterPos3f(620, 400, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'G');
		glRasterPos3f(660, 400, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'a');
		glRasterPos3f(690, 400, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'm');
		glRasterPos3f(730, 400, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'e');
		glRasterPos3f(760, 400, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');
		glRasterPos3f(800, 400, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'v');
		glRasterPos3f(830, 400, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'e');
		glRasterPos3f(850, 400, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'r');
		glPopMatrix();
	}
	else {
		glPushMatrix();

		glBegin(GL_QUADS);//ground
		glColor3f(0, 0, 0);
		glVertex2f(0, 0);
		glVertex2f(1500, 0);
		glVertex2f(1500, 50);
		glVertex2f(0, 50);
		glEnd();

		glBegin(GL_QUADS);//ground1
		glColor3f(1, 0.9, 0);
		glVertex2f(0, 0);
		glVertex2f(150, 0);
		glVertex2f(150, 50);
		glVertex2f(0, 50);
		glEnd();

		glBegin(GL_QUADS);//ground2
		glColor3f(1, 0.9, 0);
		glVertex2f(300, 0);
		glVertex2f(450, 0);
		glVertex2f(450, 50);
		glVertex2f(300, 50);
		glEnd();

		glPushMatrix();
		glTranslated(600, 0, 0);
		glBegin(GL_QUADS);//ground1
		glColor3f(1, 0.9, 0);
		glVertex2f(0, 0);
		glVertex2f(150, 0);
		glVertex2f(150, 50);
		glVertex2f(0, 50);
		glEnd();

		glBegin(GL_QUADS);//ground2
		glColor3f(1, 0.9, 0);
		glVertex2f(300, 0);
		glVertex2f(450, 0);
		glVertex2f(450, 50);
		glVertex2f(300, 50);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glTranslated(1200, 0, 0);
		glBegin(GL_QUADS);//ground1
		glColor3f(1, 0.9, 0);
		glVertex2f(0, 0);
		glVertex2f(150, 0);
		glVertex2f(150, 50);
		glVertex2f(0, 50);
		glEnd();

		glBegin(GL_QUADS);//ground2
		glColor3f(1, 0.9, 0);
		glVertex2f(300, 0);
		glVertex2f(450, 0);
		glVertex2f(450, 50);
		glVertex2f(300, 50);
		glEnd();
		glPopMatrix();
		glPopMatrix();



		glPushMatrix();
		glBegin(GL_QUADS);//body
		glColor3f(1, 1, 1);
		glVertex2f(80, 190);
		glVertex2f(125, 190);
		glVertex2f(125, 290);
		glVertex2f(80, 290);
		glEnd();

		glBegin(GL_QUADS);//neck
		glColor3f(0.8, 0.5, 0.3);
		glVertex2f(100, 290);
		glVertex2f(110, 290);
		glVertex2f(110, 315);
		glVertex2f(100, 315);
		glEnd();

		glBegin(GL_QUADS);//rigthhand
		glColor3f(1, 1, 1);
		glVertex2f(100, 272.5);
		glVertex2f(190, 272.5);
		glVertex2f(190, 290);
		glVertex2f(100, 290);
		glEnd();

		glPushMatrix();//gun3
		glTranslated(tal2X, 0, 0);
		glColor3f(0.2, 0.2, 0.2);
		glTranslated(216, 302.5, 0);
		gluDisk(gl, 0, 4, 50, 50);
		glPopMatrix();

		glBegin(GL_QUADS);//gun1
		glColor3f(0, 0, 0);
		glVertex2f(180, 272.5);
		glVertex2f(190, 272.5);
		glVertex2f(190, 310);
		glVertex2f(180, 310);
		glEnd();

		glBegin(GL_QUADS);//gun2
		glColor3f(0, 0, 0);
		glVertex2f(180, 293.5);
		glVertex2f(220, 293.5);
		glVertex2f(220, 310);
		glVertex2f(180, 310);
		glEnd();



		glPushMatrix();//head
		glColor3f(0.8, 0.5, 0.3);
		glTranslated(105, 330, 0);
		gluDisk(gl, 0, 27, 50, 50);
		glPopMatrix();

		glPushMatrix();//eye
		glColor3f(0, 0, 0);
		glTranslated(115, 330, 0);
		gluDisk(gl, 0, 4, 50, 50);
		glPopMatrix();


		glBegin(GL_QUADS);//feetfront
		glColor3f(0, 0, 0);
		glVertex2f(110, 50);
		glVertex2f(140, 50);
		glVertex2f(140, 65);
		glVertex2f(110, 65);
		glEnd();

		glBegin(GL_QUADS);//legfront1.1
		glColor3f(0, 0, 0);
		glVertex2f(100, 50);
		glVertex2f(115, 50);
		glVertex2f(135, 145);
		glVertex2f(120, 145);
		glEnd();

		glBegin(GL_QUADS);//legfront1.2
		glColor3f(0, 0, 0);
		glVertex2f(120, 145);
		glVertex2f(135, 145);
		glVertex2f(125, 190);
		glVertex2f(110, 190);
		glEnd();

		glBegin(GL_QUADS);//feetback
		glColor3f(0, 0, 0);
		glVertex2f(65, 50);
		glVertex2f(95, 50);
		glVertex2f(95, 65);
		glVertex2f(65, 65);
		glEnd();

		glBegin(GL_QUADS);//legback1.1
		glColor3f(0, 0, 0);
		glVertex2f(60, 50);
		glVertex2f(75, 50);
		glVertex2f(95, 145);
		glVertex2f(80, 145);
		glEnd();

		glBegin(GL_QUADS);//legback1.2
		glColor3f(0, 0, 0);
		glVertex2f(80, 145);
		glVertex2f(95, 145);
		glVertex2f(95, 190);
		glVertex2f(80, 190);
		glEnd();

		glPopMatrix();

		//////////////////////////////////////////////////////////////////////////////////////////////
		glPushMatrix();//character2
		glTranslated(zombie1Move , 0, 0);
		glTranslated(400, 0, 0);

		glBegin(GL_QUADS); //body char2
		glColor3f(0.1, 0.1, 0.1);
		glVertex2f(590, 190);
		glVertex2f(545, 190);
		glVertex2f(545, 290);
		glVertex2f(590, 290);
		glEnd();

		glPushMatrix(); //head
		glColor3f(0, 0.5, 0);
		glTranslated(567.5, 330, 0);
		gluDisk(gl, 0, 27, 50, 50);
		glPopMatrix();

		glPushMatrix(); //eye 
		glColor3f(0, 0, 0);
		glTranslated(550, 330, 0);
		gluDisk(gl, 0, 4, 50, 50);
		glPopMatrix();

		glBegin(GL_QUADS); //neck char2
		glColor3f(0, 0.5, 0);
		glVertex2f(562.5, 290);
		glVertex2f(572.5, 290);
		glVertex2f(572.5, 315);
		glVertex2f(562.5, 315);
		glEnd();

		glBegin(GL_QUADS); //rigth hand
		glColor3f(0.1, 0.1, 0.1);
		glVertex2f(490, 272.5);
		glVertex2f(545, 272.5);
		glVertex2f(545, 290);
		glVertex2f(490, 290);
		glEnd();

		glBegin(GL_QUADS); //left hand
		glColor3f(0.1, 0.1, 0.1);
		glVertex2f(490, 240);
		glVertex2f(545, 262.5);
		glVertex2f(545, 280);
		glVertex2f(490, 260);
		glEnd();
		glLineWidth(20);
		glBegin(GL_LINES); //leg right
		glColor3f(0, 0, 0);
		glVertex2f(580, 190);
		glVertex2f(580, 50);
		glEnd();
		glBegin(GL_LINES); //leg left
		glColor3f(0, 0, 0);
		glVertex2f(555, 190);
		glVertex2f(555, 50);
		glEnd();
		glLineWidth(10);
		glBegin(GL_LINES); //gazmaaaa left
		glColor3f(1020, 0, 0);
		glVertex2f(570, 50);
		glVertex2f(530, 50);
		glEnd();
		glBegin(GL_LINES); //gazmaaaa right
		glColor3f(1020, 0, 0);
		glVertex2f(560, 50);
		glVertex2f(590, 50);
		glEnd();


		glPopMatrix();
		glPushMatrix();//character2
		glTranslated(zombie2Move, 0, 0);
		glTranslated(600, 0, 0);

		glBegin(GL_QUADS); //body char2
		glColor3f(0.1, 0.1, 0.1);
		glVertex2f(590, 190);
		glVertex2f(545, 190);
		glVertex2f(545, 290);
		glVertex2f(590, 290);
		glEnd();

		glPushMatrix(); //head
		glColor3f(0, 0.5, 0);
		glTranslated(567.5, 330, 0);
		gluDisk(gl, 0, 27, 50, 50);
		glPopMatrix();

		glPushMatrix(); //eye 
		glColor3f(0, 0, 0);
		glTranslated(550, 330, 0);
		gluDisk(gl, 0, 4, 50, 50);
		glPopMatrix();

		glBegin(GL_QUADS); //neck char2
		glColor3f(0, 0.5, 0);
		glVertex2f(562.5, 290);
		glVertex2f(572.5, 290);
		glVertex2f(572.5, 315);
		glVertex2f(562.5, 315);
		glEnd();

		glBegin(GL_QUADS); //rigth hand
		glColor3f(0.1, 0.1, 0.1);
		glVertex2f(490, 272.5);
		glVertex2f(545, 272.5);
		glVertex2f(545, 290);
		glVertex2f(490, 290);
		glEnd();

		glBegin(GL_QUADS); //left hand
		glColor3f(0.1, 0.1, 0.1);
		glVertex2f(490, 240);
		glVertex2f(545, 262.5);
		glVertex2f(545, 280);
		glVertex2f(490, 260);
		glEnd();
		glLineWidth(20);
		glBegin(GL_LINES); //leg right
		glColor3f(0, 0, 0);
		glVertex2f(580, 190);
		glVertex2f(580, 50);
		glEnd();
		glBegin(GL_LINES); //leg left
		glColor3f(0, 0, 0);
		glVertex2f(555, 190);
		glVertex2f(555, 50);
		glEnd();
		glLineWidth(10);
		glBegin(GL_LINES); //gazmaaaa left
		glColor3f(1020, 0, 0);
		glVertex2f(570, 50);
		glVertex2f(530, 50);
		glEnd();
		glBegin(GL_LINES); //gazmaaaa right
		glColor3f(1020, 0, 0);
		glVertex2f(560, 50);
		glVertex2f(590, 50);
		glEnd();


		glPopMatrix();
		glPushMatrix();//character2
		glTranslated(zombie3Move , 0, 0);
		glTranslated(800, 0, 0);

		glBegin(GL_QUADS); //body char2
		glColor3f(0.1, 0.1, 0.1);
		glVertex2f(590, 190);
		glVertex2f(545, 190);
		glVertex2f(545, 290);
		glVertex2f(590, 290);
		glEnd();

		glPushMatrix(); //head
		glColor3f(0, 0.5, 0);
		glTranslated(567.5, 330, 0);
		gluDisk(gl, 0, 27, 50, 50);
		glPopMatrix();

		glPushMatrix(); //eye 
		glColor3f(0, 0, 0);
		glTranslated(550, 330, 0);
		gluDisk(gl, 0, 4, 50, 50);
		glPopMatrix();

		glBegin(GL_QUADS); //neck char2
		glColor3f(0, 0.5, 0);
		glVertex2f(562.5, 290);
		glVertex2f(572.5, 290);
		glVertex2f(572.5, 315);
		glVertex2f(562.5, 315);
		glEnd();

		glBegin(GL_QUADS); //rigth hand
		glColor3f(0.1, 0.1, 0.1);
		glVertex2f(490, 272.5);
		glVertex2f(545, 272.5);
		glVertex2f(545, 290);
		glVertex2f(490, 290);
		glEnd();

		glBegin(GL_QUADS); //left hand
		glColor3f(0.1, 0.1, 0.1);
		glVertex2f(490, 240);
		glVertex2f(545, 262.5);
		glVertex2f(545, 280);
		glVertex2f(490, 260);
		glEnd();
		glLineWidth(20);
		glBegin(GL_LINES); //leg right
		glColor3f(0, 0, 0);
		glVertex2f(580, 190);
		glVertex2f(580, 50);
		glEnd();
		glBegin(GL_LINES); //leg left
		glColor3f(0, 0, 0);
		glVertex2f(555, 190);
		glVertex2f(555, 50);
		glEnd();
		glLineWidth(10);
		glBegin(GL_LINES); //gazmaaaa left
		glColor3f(1020, 0, 0);
		glVertex2f(570, 50);
		glVertex2f(530, 50);
		glEnd();
		glBegin(GL_LINES); //gazmaaaa right
		glColor3f(1020, 0, 0);
		glVertex2f(560, 50);
		glVertex2f(590, 50);
		glEnd();


		glPopMatrix();
		glPushMatrix();//character2
		glTranslated(zombie4Move , 0, 0);
		glTranslated(1000, 0, 0);

		glBegin(GL_QUADS); //body char2
		glColor3f(0.1, 0.1, 0.1);
		glVertex2f(590, 190);
		glVertex2f(545, 190);
		glVertex2f(545, 290);
		glVertex2f(590, 290);
		glEnd();

		glPushMatrix(); //head
		glColor3f(0, 0.5, 0);
		glTranslated(567.5, 330, 0);
		gluDisk(gl, 0, 27, 50, 50);
		glPopMatrix();

		glPushMatrix(); //eye 
		glColor3f(0, 0, 0);
		glTranslated(550, 330, 0);
		gluDisk(gl, 0, 4, 50, 50);
		glPopMatrix();

		glBegin(GL_QUADS); //neck char2
		glColor3f(0, 0.5, 0);
		glVertex2f(562.5, 290);
		glVertex2f(572.5, 290);
		glVertex2f(572.5, 315);
		glVertex2f(562.5, 315);
		glEnd();

		glBegin(GL_QUADS); //rigth hand
		glColor3f(0.1, 0.1, 0.1);
		glVertex2f(490, 272.5);
		glVertex2f(545, 272.5);
		glVertex2f(545, 290);
		glVertex2f(490, 290);
		glEnd();

		glBegin(GL_QUADS); //left hand
		glColor3f(0.1, 0.1, 0.1);
		glVertex2f(490, 240);
		glVertex2f(545, 262.5);
		glVertex2f(545, 280);
		glVertex2f(490, 260);
		glEnd();
		glLineWidth(20);
		glBegin(GL_LINES); //leg right
		glColor3f(0, 0, 0);
		glVertex2f(580, 190);
		glVertex2f(580, 50);
		glEnd();
		glBegin(GL_LINES); //leg left
		glColor3f(0, 0, 0);
		glVertex2f(555, 190);
		glVertex2f(555, 50);
		glEnd();
		glLineWidth(10);
		glBegin(GL_LINES); //gazmaaaa left
		glColor3f(1020, 0, 0);
		glVertex2f(570, 50);
		glVertex2f(530, 50);
		glEnd();
		glBegin(GL_LINES); //gazmaaaa right
		glColor3f(1020, 0, 0);
		glVertex2f(560, 50);
		glVertex2f(590, 50);
		glEnd();


		glPopMatrix();
		glPopMatrix();
		glPushMatrix();
		glColor3ub(255, 0, 0);
		glRasterPos3f(1100, 900, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scoreText[0]);
		glRasterPos3f(1120, 900, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scoreText[1]);
		glRasterPos3f(980, 900, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 's');
		glRasterPos3f(1000, 900, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'c');
		glColor3ub(255, 0, 0);
		glRasterPos3f(1020, 900, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'o');
		glRasterPos3f(1040, 900, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'r');
		glColor3ub(255, 0, 0);
		glRasterPos3f(1060, 900, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'e');
		glRasterPos3f(1080, 900, 1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ':');
		glPopMatrix();
	}
	
	glFlush();

}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'z':
		if (!tal2) {
			tal2 = true;
		}
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void setScore(int point) {
	score += point;
	itoa(score, scoreText, 10);
	glutPostRedisplay();
}
void keyup(unsigned char key, int x, int y) {
	switch (key)
	{
	default:
		break;
	}
	glutPostRedisplay();
}
void timer(int val) {
	zombie1Move -= (20 + speed1);
	zombie2Move -= (20 + speed2);
	zombie3Move -= (20 + speed3);
	zombie4Move -= (20 + speed4);
	
	glutPostRedisplay();
	glutTimerFunc(100, timer, 0);
}
void idle() {
	if (tal2 && tal2X > (750 + zombie1Move)&&!win) {
		enemy1Health -= 50;
		if (enemy1Health <= 0) {
			setScore(1);
			speed1+=5;
			enemy1Health = 100;
			zombie1Move = 800;
		}
		tal2 = false;
		tal2X = 0;
	}
	if (tal2 && tal2X > (950 + zombie2Move) && !win) {
		enemy2Health -= 50;
		if (enemy2Health <= 0) {
			setScore(1);
			speed2+=5;
			enemy2Health = 100;
			zombie2Move = 600;
		}
		tal2 = false;
		tal2X = 0;
	}
	if (tal2 && tal2X > (1150 + zombie3Move) && !win) {
		enemy3Health -= 50;
		if (enemy3Health <= 0) {
			setScore(1);
			speed3+=5;
			enemy3Health = 100;
			zombie3Move = 400;
		}
		tal2 = false;
		tal2X = 0;
	}
	if (tal2 && tal2X > (1350 + zombie4Move) && !win) {
		enemy4Health -= 50;
		if (enemy4Health <= 0) {
			setScore(1);
			speed4+=5;
			enemy4Health = 100;
			zombie4Move = 200;
		}
		tal2 = false;
		tal2X = 0;
	}
	if ((zombie1Move <= -750 || zombie2Move <= -950 || zombie3Move <= -1150) && !win) {
		lose = true;
		win = false;
	}
	if (score >= 30) {
		lose = false;
		win = true;
	}
	glutPostRedisplay();
}
void timer2(int val) {
	if (tal2) {
		tal2X += 20;
	}
	
	
	glutPostRedisplay();
	glutTimerFunc(30, timer2, 0);
}
void main() {
	glutInitWindowSize(700, 600);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("MohamedAdel20200233&&Abdelrahmanfathy20210723&&ismailelhussein20200092");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyup);
	glutIdleFunc(idle);
	glClearColor(0, 0.8, 0.9, 0);
	glutTimerFunc(100, timer, 0);
	glutTimerFunc(30, timer2, 0);
	gluOrtho2D(0, 1500, 0, 1000);
	glutMainLoop();

}
