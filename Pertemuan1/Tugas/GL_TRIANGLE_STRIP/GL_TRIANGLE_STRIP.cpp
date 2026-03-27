//NAMA	: Izzatu Khoirul Fata
//NIM	: 24060124120039

#include <GL/glut.h>

void display() {
   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(0.0f, 0.0f, 1.0f);
   glBegin(GL_TRIANGLE_STRIP);
       glVertex3f(-5.0f, -5.0f, 0.0f);
       glVertex3f( 0.0f,  5.0f, 0.0f);
       glVertex3f( 5.0f, -5.0f, 0.0f);
       glVertex3f(10.0f,  5.0f, 0.0f);
       glVertex3f(15.0f, -5.0f, 0.0f);
       glVertex3f(20.0f,  5.0f, 0.0f);
   glEnd();

   glColor3f(0.0f, 0.0f, 0.0f);
   glLineWidth(2.0f);

   glBegin(GL_LINE_STRIP);
       glVertex3f(-5.0f, -5.0f, 0.0f);
       glVertex3f( 0.0f,  5.0f, 0.0f);
       glVertex3f( 5.0f, -5.0f, 0.0f);
       glVertex3f(10.0f,  5.0f, 0.0f);
       glVertex3f(15.0f, -5.0f, 0.0f);
       glVertex3f(20.0f,  5.0f, 0.0f);
   glEnd();

   glBegin(GL_LINES);
       glVertex3f(-5.0f, -5.0f, 0.0f); glVertex3f(15.0f, -5.0f, 0.0f);
       glVertex3f( 0.0f,  5.0f, 0.0f); glVertex3f(20.0f,  5.0f, 0.0f);
   glEnd();

   glFlush();
}

void init() {
   glClearColor(1.0, 1.0, 1.0, 1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-10.0, 25.0, -10.0, 10.0);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(800, 400);
   glutCreateWindow("GL_TRIANGLE_STRIP");
   init();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
