#include <GL/glut.h>
void demo()
{
    gluOrtho2D(100, 500, 100, 500);
}
void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(150, 150);
    glVertex2i(350, 150);
    glVertex2i(350, 350);
    glVertex2i(150, 350);
    glEnd();
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2i(150, 350);
    glVertex2i(350, 350);
    glVertex2i(250, 450);
    glEnd();
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(200, 150);
    glVertex2i(300, 150);
    glVertex2i(300, 250);
    glVertex2i(200, 250);
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("House");
    demo();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
