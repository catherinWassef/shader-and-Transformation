#include <iostream>
#include <cmath>
#include <gl/glut.h>

void init() {
	glClearColor(1.0, 1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glColor3f(0.0f, 0.0f, 0.0f);
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

typedef struct {
	double x;
	double y;
} Point;

Point p1 = { 70.0, 480.0 };
Point p2 = { 140.0, 480.0 };
Point p3 = { 210.0, 480.0 };
Point p4 = { 280.0, 480.0 };
Point p5 = { 350.0, 480.0 };
Point p6 = { 420.0, 480.0 };
Point p7 = { 490.0, 480.0 };
Point p8 = { 560.0, 480.0 };
Point p9 = { 630.0, 480.0 };

double time1 = 0.0;
double time2 = 0.0;
double time3 = 0.0;
double time4 = 0.0;
double time5 = 0.0;
double time6 = 0.0;
double time7 = 0.0;
double time8 = 0.0;
double time9 = 0.0;

void calc() {
	time1 += 0.1;
	time2 += 0.1;
	time3 += 0.1;
	time4 += 0.1;
	time5 += 0.1;
	time6 += 0.1;
	time7 += 0.1;
	time8 += 0.1;
	time9 += 0.1;


	p1.y = (-0.5*9.8)*(time1*time1) + 0 + 480;
	p2.y = (-0.5*1.6)*(time2*time2) + 0 + 480;
	p3.y = (-0.5*7.6)*(time3*time3) + 0 + 480;
	p4.y = (-0.5*4.6)*(time4*time4) + 0 + 480;
	p5.y = (-0.5*8.6)*(time5*time5) + 0 + 480;
	p6.y = (-0.5*3.6)*(time6*time6) + 0 + 480;
	p7.y = (-0.5*6.2)*(time7*time7) + 0 + 480;
	p8.y = (-0.5*5.2)*(time8*time8) + 0 + 480;
	p9.y = (-0.5*2.2)*(time9*time9) + 0 + 480;

	if (p1.y < 0.0) {
		p1.y = 0;
		
	}
	if (p2.y < 0.0) {
		p2.y = 0;

	}
	if (p3.y < 0.0) {
		p3.y = 0;
	
	}
	if (p4.y < 0.0) {
		p4.y = 0;
		
	}
	if (p5.y < 0.0) {
		p5.y = 0;
	
	}
	if (p6.y < 0.0) {
		p6.y = 0;
	
	}
	if (p7.y < 0.0) {
		p7.y = 0;
	
	}
	if (p8.y < 0.0) {
		p8.y = 0;
	
	}
	if (p9.y < 0.0) {
		p9.y = 0;
	
	}
}

void display() {
	calc();
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(90.0);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2d(p1.x, p1.y);
	glEnd();

	glPointSize(10.0);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2d(p2.x, p2.y);
	glEnd();

	glPointSize(70.0);
	glBegin(GL_POINTS);
	glColor3f(0.9f, 0.0f, 0.2f);
	glVertex2d(p3.x, p3.y);
	glEnd();

	glPointSize(40.0);
	glBegin(GL_POINTS);
	glColor3f(0.7f, 1.0f, 1.0f);
	glVertex2d(p4.x, p4.y);
	glEnd();

	glPointSize(80.0);
	glBegin(GL_POINTS);
	glColor3f(0.7f, 0.3f, 0.7f);
	glVertex2d(p5.x, p5.y);
	glEnd();

	glPointSize(30.0);
	glBegin(GL_POINTS);
	glColor3f(0.5f, 0.1f, 0.2f);
	glVertex2d(p6.x, p6.y);
	glEnd();

	glPointSize(60.0);
	glBegin(GL_POINTS);
	glColor3f(0.4f, 0.9f, 0.2f);
	glVertex2d(p7.x, p7.y);
	glEnd();

	glPointSize(50.0);
	glBegin(GL_POINTS);
	glColor3f(0.5f, 0.1f, 0.5f);
	glVertex2d(p8.x, p8.y);
	glEnd();

	glPointSize(20.0);
	glBegin(GL_POINTS);
	glColor3f(0.7f, 0.5f, 1.0f);
	glVertex2d(p9.x, p9.y);
	glEnd();
	glFlush();
}

void Timer(int value) {
	glutTimerFunc(3000/ 60, Timer, value);
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 480);
	glutCreateWindow("OpenGL");
	init();
	Timer(0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}