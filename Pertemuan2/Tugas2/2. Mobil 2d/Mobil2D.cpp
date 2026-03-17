//Nama	: Izzatu Khoirul Fata
//NIM		: 24060124120039
//Lab		: D1

#include <GL/glut.h>
#include <cmath>

float wheelAngle = 0.0f;


void drawCircle(float x, float y, float radius, int segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1415926f * i / segments;
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void drawWheel(float x, float y) {

    glPushMatrix();
    glTranslatef(x, y, 0);
    glRotatef(wheelAngle, 0, 0, 1);

    glColor3f(0.1f,0.1f,0.1f);
    drawCircle(0,0,3,30);

    glColor3f(0.7f,0.7f,0.7f);
    drawCircle(0,0,1.5,30);

    glColor3f(0.2f,0.2f,0.2f);
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0,0); glVertex2f(3,0);
        glVertex2f(0,0); glVertex2f(-3,0);
        glVertex2f(0,0); glVertex2f(0,3);
        glVertex2f(0,0); glVertex2f(0,-3);
        glVertex2f(0,0); glVertex2f(2,2);
        glVertex2f(0,0); glVertex2f(-2,2);
        glVertex2f(0,0); glVertex2f(2,-2);
        glVertex2f(0,0); glVertex2f(-2,-2);
    glEnd();

    glPopMatrix();
}

void drawCloud(float x, float y) {

    glColor3f(1,1,1);

    drawCircle(x,y,3,20);
    drawCircle(x+3,y+1,3,20);
    drawCircle(x+6,y,3,20);
    drawCircle(x+2,y-1,3,20);
    drawCircle(x+4,y-1,3,20);
}

void update(int value) {

    wheelAngle -= 5;

    if (wheelAngle < -360)
        wheelAngle = 0;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.4f,0.7f,1);
    glBegin(GL_QUADS);
        glVertex2f(0,40); glVertex2f(100,40);
        glVertex2f(100,100); glVertex2f(0,100);
    glEnd();

    glColor3f(1,0.9,0);
    drawCircle(45,85,6,30);

    drawCloud(10,85);
    drawCloud(65,80);
    drawCloud(80,88);

    glColor3f(0.5f,0.8f,0.2f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-10,40); glVertex2f(35,80); glVertex2f(80,40);
        glVertex2f(30,40); glVertex2f(75,90); glVertex2f(120,40);
    glEnd();

    glColor3f(0.8f,0.5f,0);
    glBegin(GL_QUADS);
        glVertex2f(0,30); glVertex2f(100,30);
        glVertex2f(100,40); glVertex2f(0,40);
    glEnd();

    glColor3f(0.2f,0.2f,0.3f);
    glBegin(GL_QUADS);
        glVertex2f(0,10); glVertex2f(100,10);
        glVertex2f(100,30); glVertex2f(0,30);
    glEnd();

    glColor3f(1,1,1);
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(0,20); glVertex2f(100,20);
    glEnd();

    glColor3f(0.5f,0.9f,0.3f);
    glBegin(GL_QUADS);
        glVertex2f(0,0); glVertex2f(100,0);
        glVertex2f(100,10); glVertex2f(0,10);
    glEnd();

	glColor3f(0.3f,0.3f,0.3f);
	glRectf(83,30,84,45);

	glColor3f(1,0.5,0.1);
	glRectf(78,45,88,55);

    glColor3f(0.8f,0.1f,0.1f);
    glRectf(15,25,35,45);

    glColor3f(1,0.6,0.2);
    glBegin(GL_QUADS);
        glVertex2f(35,25); glVertex2f(45,25);
        glVertex2f(43,38); glVertex2f(35,38);
    glEnd();

    glColor3f(0.6f,0.9f,1);
    glBegin(GL_QUADS);
        glVertex2f(36,30); glVertex2f(42,30);
        glVertex2f(41,36); glVertex2f(36,36);
    glEnd();

    drawWheel(18,25);
    drawWheel(24,25);
    drawWheel(38,25);

    glFlush();
}

void init() {

    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,100,0,100);
}

int main(int argc, char** argv) {

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,450);
    glutCreateWindow("Mobil 2D");

    init();
    glutDisplayFunc(display);

    glutTimerFunc(0, update, 0);

    glutMainLoop();
}
