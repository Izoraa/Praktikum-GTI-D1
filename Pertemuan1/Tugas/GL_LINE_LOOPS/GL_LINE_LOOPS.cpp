//NAMA	: Izzatu Khoirul Fata
//NIM		: 24060124120039

#include <windows.h>
#include <GL/glut.h>

void display() {
   glClear(GL_COLOR_BUFFER_BIT);

   glBegin(GL_LINE_LOOP);
       glVertex2f(0.0f, 0.7f);
       glVertex2f(0.6f, 0.2f);
       glVertex2f(0.4f, -0.6f);
       glVertex2f(-0.4f, -0.6f);
       glVertex2f(-0.6f, 0.2f);
   glEnd();

   glFlush();
}

void init() {
   glClearColor(1.0, 1.0, 1.0, 1.0);
   glColor3f(0.8, 0.0, 0.0);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutCreateWindow("GL_LINE_LOOP");

   init();
   glutDisplayFunc(display);
   glutMainLoop();

   return 0;
}
