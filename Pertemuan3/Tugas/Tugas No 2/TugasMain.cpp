//Nama	: Izzatu Khoirul Fata
//NIM		: 24060124120039

#include <stdlib.h>
#include <GL/glut.h>

static int shoulder = 0, elbow = 0;

static int thumbBase = 20, thumbTip = 0;

static int telunjukBase = 0, telunjukMid = 0, telunjukTip = 0;
static int tengahBase   = 0, tengahMid   = 0, tengahTip   = 0;
static int manisBase    = 0, manisMid    = 0, manisTip    = 0;
static int kelingkingBase = 0, kelingkingMid = 0, kelingkingTip = 0;

void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void drawBox(float sx, float sy, float sz) {
    glPushMatrix();
        glScalef(sx, sy, sz);
        glutWireCube(1.0);
    glPopMatrix();
}

void drawFingerSegment(float length, float width, float depth) {
    glPushMatrix();
        glTranslatef(0.0, length / 2.0, 0.0);
        drawBox(width, length, depth);
    glPopMatrix();
}

void drawFinger3(float baseX, float baseY,
                 float a1, float a2, float a3,
                 float l1, float l2, float l3,
                 float w) {
    glPushMatrix();
        glTranslatef(baseX, baseY, 0.0);

        glRotatef(a1, 0.0, 0.0, 1.0);
        drawFingerSegment(l1, w, 0.20);

        glTranslatef(0.0, l1, 0.0);
        glRotatef(a2, 0.0, 0.0, 1.0);
        drawFingerSegment(l2, w * 0.90f, 0.18);

        glTranslatef(0.0, l2, 0.0);
        glRotatef(a3, 0.0, 0.0, 1.0);
        drawFingerSegment(l3, w * 0.80f, 0.16);
    glPopMatrix();
}

void drawThumb(float baseX, float baseY, float a1, float a2) {
    glPushMatrix();
        glTranslatef(baseX, baseY, 0.0);

        glRotatef(-45.0, 0.0, 0.0, 1.0);
        glRotatef(a1, 0.0, 0.0, 1.0);
        drawFingerSegment(0.45, 0.18, 0.18);

        glTranslatef(0.0, 0.45, 0.0);
        glRotatef(a2, 0.0, 0.0, 1.0);
        drawFingerSegment(0.32, 0.15, 0.15);
    glPopMatrix();
}

void display(void) {
    glClear (GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        glTranslatef (-1.0, 0.0, 0.0);
        glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
        glTranslatef (1.0, 0.0, 0.0);

        glPushMatrix();
            glScalef (2.0, 0.4, 1.0);
            glutWireCube (1.0);
        glPopMatrix();

        glTranslatef (1.0, 0.0, 0.0);
        glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
        glTranslatef (1.0, 0.0, 0.0);

        glPushMatrix();
            glScalef (2.0, 0.4, 1.0);
            glutWireCube (1.0);
        glPopMatrix();


        glTranslatef(1.0, 0.0, 0.0);

        glPushMatrix();

            glRotatef(-5.0, 0.0, 0.0, 1.0);

            glPushMatrix();
                glTranslatef(0.18, 0.02, 0.0);
                drawBox(0.62, 0.95, 0.35);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-0.05, -0.22, 0.0);
                drawBox(0.36, 0.34, 0.30);
            glPopMatrix();

            drawFinger3(-0.02, 0.46,
                        telunjukBase, telunjukMid, telunjukTip,
                        0.36, 0.26, 0.20, 0.11);

            drawFinger3(0.12, 0.52,
                        tengahBase, tengahMid, tengahTip,
                        0.42, 0.30, 0.22, 0.12);

            drawFinger3(0.26, 0.48,
                        manisBase, manisMid, manisTip,
                        0.38, 0.28, 0.21, 0.11);

            drawFinger3(0.38, 0.40,
                        kelingkingBase, kelingkingMid, kelingkingTip,
                        0.30, 0.22, 0.16, 0.10);

            drawThumb(-0.20, -0.05, thumbBase, thumbTip);

        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's':
            shoulder = (shoulder + 5) % 360;
            glutPostRedisplay();
            break;
        case 'S':
            shoulder = (shoulder - 5 + 360) % 360;
            glutPostRedisplay();
            break;
        case 'e':
            elbow = (elbow + 5) % 360;
            glutPostRedisplay();
            break;
        case 'E':
            elbow = (elbow - 5 + 360) % 360;
            glutPostRedisplay();
            break;

        //ibu jari
        case 'q':
            thumbBase = (thumbBase + 5) % 360;
            glutPostRedisplay();
            break;
        case 'Q':
            thumbBase = (thumbBase - 5 + 360) % 360;
            glutPostRedisplay();
            break;
        case 'w':
            thumbTip = (thumbTip + 5) % 360;
            glutPostRedisplay();
            break;
        case 'W':
            thumbTip = (thumbTip - 5 + 360) % 360;
            glutPostRedisplay();
            break;

        //telunjuk
        case 'a':
            telunjukBase = (telunjukBase + 5) % 360;
            glutPostRedisplay();
            break;
        case 'A':
            telunjukBase = (telunjukBase - 5 + 360) % 360;
            glutPostRedisplay();
            break;
        case 'z':
            telunjukMid = (telunjukMid + 5) % 360;
            glutPostRedisplay();
            break;
        case 'Z':
            telunjukMid = (telunjukMid - 5 + 360) % 360;
            glutPostRedisplay();
            break;
        case 'x':
            telunjukTip = (telunjukTip + 5) % 360;
            glutPostRedisplay();
            break;
        case 'X':
            telunjukTip = (telunjukTip - 5 + 360) % 360;
            glutPostRedisplay();
            break;

        //jari tengah
        case 'd':
            tengahBase = (tengahBase + 5) % 360;
            glutPostRedisplay();
            break;
        case 'D':
            tengahBase = (tengahBase - 5 + 360) % 360;
            glutPostRedisplay();
            break;
        case 'c':
            tengahMid = (tengahMid + 5) % 360;
            glutPostRedisplay();
            break;
        case 'C':
            tengahMid = (tengahMid - 5 + 360) % 360;
            glutPostRedisplay();
            break;
        case 'v':
            tengahTip = (tengahTip + 5) % 360;
            glutPostRedisplay();
            break;
        case 'V':
            tengahTip = (tengahTip - 5 + 360) % 360;
            glutPostRedisplay();
            break;

        //jari manis
        case 'f':
            manisBase = (manisBase + 5) % 360;
            glutPostRedisplay();
            break;
        case 'F':
            manisBase = (manisBase - 5 + 360) % 360;
            glutPostRedisplay();
            break;
        case 'g':
            manisMid = (manisMid + 5) % 360;
            glutPostRedisplay();
            break;
        case 'G':
            manisMid = (manisMid - 5 + 360) % 360;
            glutPostRedisplay();
            break;
        case 'h':
            manisTip = (manisTip + 5) % 360;
            glutPostRedisplay();
            break;
        case 'H':
            manisTip = (manisTip - 5 + 360) % 360;
            glutPostRedisplay();
            break;

        //kelingking
        case 'j':
            kelingkingBase = (kelingkingBase + 5) % 360;
            glutPostRedisplay();
            break;
        case 'J':
            kelingkingBase = (kelingkingBase - 5 + 360) % 360;
            glutPostRedisplay();
            break;
        case 'k':
            kelingkingMid = (kelingkingMid + 5) % 360;
            glutPostRedisplay();
            break;
        case 'K':
            kelingkingMid = (kelingkingMid - 5 + 360) % 360;
            glutPostRedisplay();
            break;
        case 'l':
            kelingkingTip = (kelingkingTip + 5) % 360;
            glutPostRedisplay();
            break;
        case 'L':
            kelingkingTip = (kelingkingTip - 5 + 360) % 360;
            glutPostRedisplay();
            break;

        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (700, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
