//NAMA	: Izzatu Khoirul Fata
//NIM	: 24060124120039

#include <GL/glut.h>

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.0f, 0.0f, 1.0f);

   glBegin(GL_TRIANGLE_FAN);
       glVertex2f(0.0f, -0.5f);
       glVertex2f(-0.8f, 0.0f);
       glVertex2f(-0.4f, 0.5f);
       glVertex2f(0.0f,  0.7f);
       glVertex2f(0.4f,  0.5f);
       glVertex2f(0.8f,  0.0f);
   glEnd();

   glColor3f(0.0f, 0.0f, 0.0f);
   glLineWidth(2.0f);

   glBegin(GL_LINE_LOOP);
       glVertex2f(-0.8f, 0.0f);
       glVertex2f(-0.4f, 0.5f);
       glVertex2f(0.0f,  0.7f);
       glVertex2f(0.4f,  0.5f);
       glVertex2f(0.8f,  0.0f);
       glVertex2f(0.0f, -0.5f);
   glEnd();

   glBegin(GL_LINES);
       glVertex2f(0.0f, -0.5f); glVertex2f(-0.8f, 0.0f);
       glVertex2f(0.0f, -0.5f); glVertex2f(-0.4f, 0.5f);
       glVertex2f(0.0f, -0.5f); glVertex2f(0.0f,  0.7f);
       glVertex2f(0.0f, -0.5f); glVertex2f(0.4f,  0.5f);
       glVertex2f(0.0f, -0.5f); glVertex2f(0.8f,  0.0f);
   glEnd();

   glFlush();
}

void init() {
   glClearColor(1.0, 1.0, 1.0, 1.0);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(600, 600);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("GL_TRIANGLE_FAN");
   init();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
