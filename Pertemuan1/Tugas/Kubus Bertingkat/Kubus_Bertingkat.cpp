//NAMA	: Izzatu Khoirul Fata
//NIM	: 24060124120039

#include <GL/glut.h>
void cube(float x, float y, float size){
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    float s = 0.18;
    glColor3f(0.2, 0.7, 0.4);

    cube(-0.5, -0.6, s);
    cube(-0.25, -0.6, s);
    cube(0.0, -0.6, s);
    cube(0.25, -0.6, s);

    cube(-0.375, -0.35, s);
    cube(-0.125, -0.35, s);
    cube(0.125, -0.35, s);

    cube(-0.25, -0.1, s);
    cube(0.0, -0.1, s);

    cube(-0.125, 0.15, s);

    glFlush();
}

void init(){
    glClearColor(1,1,1,1);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Kubus Bertingkat");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
