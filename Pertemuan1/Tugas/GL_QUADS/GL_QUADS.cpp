//NAMA	: Izzatu Khoirul Fata
//NIM	: 24060124120039


#include <windows.h>
#include <GL/glut.h>

void display() {
   glClear(GL_COLOR_BUFFER_BIT);

   glBegin(GL_QUADS);

       glColor3f(0.0, 0.0, 1.0);

       glVertex2f(-0.5f, 0.5f);
       glVertex2f(0.5f, 0.5f);
       glVertex2f(0.5f, -0.5f);
       glVertex2f(-0.5f, -0.5f);

   glEnd();

   glFlush();
}

void init() {
   glClearColor(1,1,1,1);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(600,600);
   glutCreateWindow("GL_QUADS");

   init();
   glutDisplayFunc(display);
   glutMainLoop();
}
