//Nama		: Izzatu Khoirul Fata
//NIM			: 24060124120039
//Lab			: D1

#include <GL/glut.h>
#include <math.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    float x, y;
    float radius = 0.3;
    int i;

    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(3);

    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 360; i++) {
        float angle = i * 3.14159 / 180;
        x = -0.5 + radius * cos(angle);
        y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.5, 0.0);
        for(i = 0; i <= 360; i++) {
            float angle = i * 3.14159 / 180;
            x = 0.5 + radius * cos(angle);
            y = radius * sin(angle);
            glVertex2f(x, y);
        }
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.6, 0.6, 0.6, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Membuat Lingkaran");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
