#include <GL/glut.h>
void init()
{
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Draw Plus (+)
    glBegin(GL_LINES);
    glVertex2f(-10, 0);
    glVertex2f(10, 0);
    glVertex2f(0, 10);
    glVertex2f(0, -10);
    glEnd();
    // Draw Minus (-)
    glBegin(GL_LINES);
    glVertex2f(-30, -40);
    glVertex2f(-10, -40);
    glEnd();
    // Draw Multiplication (*)
    glBegin(GL_LINES);
    glVertex2f(10, -20);
    glVertex2f(30, -40);
    glVertex2f(30, -20);
    glVertex2f(10, -40);
    glEnd();
    // Draw Division (/)
    glBegin(GL_LINES);
    glVertex2f(40, -20);
    glVertex2f(60, -40);
    glEnd();
    // Draw Less than (<)
    glBegin(GL_LINES);
    glVertex2f(-60, 40);
    glVertex2f(-40, 20);
    glVertex2f(-40, 20);
    glVertex2f(-60, 0);
    glEnd();
    // Draw Greater than (>)
    glBegin(GL_LINES);
    glVertex2f(60, 40);
    glVertex2f(40, 20);
    glVertex2f(40, 20);
    glVertex2f(60, 0);
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Arithmetic Symbols and Comparison Operators");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
