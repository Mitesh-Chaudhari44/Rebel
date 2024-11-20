#include <GL/glut.h>
void init()
{
    gluOrtho2D(-300.0, 300.0, -300.0, 300.0);
}
// Function to draw the character 'A'
void draw_A()
{
    glBegin(GL_LINES);
    glVertex2f(-10, -20);
    glVertex2f(0, 20);
    glVertex2f(0, 20);
    glVertex2f(10, -20);
    glVertex2f(-5, 0);
    glVertex2f(5, 0);
    glEnd();
}
// Function to draw the character 'E'
void draw_E()
{
    glBegin(GL_LINES);
    glVertex2f(-10, 20);
    glVertex2f(-10, -20);
    glVertex2f(-10, 20);
    glVertex2f(10, 20);
    glVertex2f(-10, 0);
    glVertex2f(5, 0);
    glVertex2f(-10, -20);
    glVertex2f(10, -20);
    glEnd();
}
// Function to draw the character 'F'
void draw_F()
{
    glBegin(GL_LINES);
    glVertex2f(-10, 20);
    glVertex2f(-10, -20);
    glVertex2f(-10, 20);
    glVertex2f(10, 20);
    glVertex2f(-10, 0);
    glVertex2f(5, 0);
    glEnd();
}
// Function to draw the character 'H'
void draw_H()
{
    glBegin(GL_LINES);
    glVertex2f(-10, 20);
    glVertex2f(-10, -20);
    glVertex2f(10, 20);
    glVertex2f(10, -20);
    glVertex2f(-10, 0);
    glVertex2f(10, 0);
    glEnd();
}
// Function to draw the character 'I'
void draw_I()
{
    glBegin(GL_LINES);
    glVertex2f(0, 20);
    glVertex2f(0, -20);
    glVertex2f(-5, 20);
    glVertex2f(5, 20);
    glVertex2f(-5, -20);
    glVertex2f(5, -20);
    glEnd();
}
// Function to draw the character 'K'
void draw_K()
{
    glBegin(GL_LINES);
    glVertex2f(-10, 20);
    glVertex2f(-10, -20);
    glVertex2f(10, 20);
    glVertex2f(-10, 0);
    glVertex2f(-10, 0);
    glVertex2f(10, -20);
    glEnd();
}
// Function to draw the character 'L'
void draw_L()
{
    glBegin(GL_LINES);
    glVertex2f(-10, 20);
    glVertex2f(-10, -20);
    glVertex2f(-10, -20);
    glVertex2f(10, -20);
    glEnd();
}
// Function to draw the character 'M'
void draw_M()
{
    glBegin(GL_LINES);
    glVertex2f(-10, -20);
    glVertex2f(-10, 20);
    glVertex2f(-10, 20);
    glVertex2f(0, 0);
    glVertex2f(0, 0);
    glVertex2f(10, 20);
    glVertex2f(10, 20);
    glVertex2f(10, -20);
    glEnd();
}
// Function to draw the character 'N'
void draw_N()
{
    glBegin(GL_LINES);
    glVertex2f(-10, -20);
    glVertex2f(-10, 20);
    glVertex2f(-10, 20);
    glVertex2f(10, -20);
    glVertex2f(10, -20);
    glVertex2f(10, 20);
    glEnd();
}
// Function to draw the character 'T'
void draw_T()
{
    glBegin(GL_LINES);
    glVertex2f(-10, 20);
    glVertex2f(10, 20);
    glVertex2f(0, 20);
    glVertex2f(0, -20);
    glEnd();
}
// Function to draw the character 'V'
void draw_V()
{
    glBegin(GL_LINES);
    glVertex2f(-10, 20);
    glVertex2f(0, -20);
    glVertex2f(0, -20);
    glVertex2f(10, 20);
    glEnd();
}
// Function to draw the character 'W'
void draw_W()
{
    glBegin(GL_LINES);
    glVertex2f(-15, 20);
    glVertex2f(-10, -20);
    glVertex2f(-10, -20);
    glVertex2f(0, 0);
    glVertex2f(0, 0);
    glVertex2f(10, -20);
    glVertex2f(10, -20);
    glVertex2f(15, 20);
    glEnd();
}
// Function to draw the character 'X'
void draw_X()
{
    glBegin(GL_LINES);
    glVertex2f(-10, 20);
    glVertex2f(10, -20);
    glVertex2f(10, 20);
    glVertex2f(-10, -20);
    glEnd();
}
// Function to draw the character 'Y'
void draw_Y()
{
    glBegin(GL_LINES);
    glVertex2f(-10, 20);
    glVertex2f(0, 0);
    glVertex2f(10, 20);
    glVertex2f(0, 0);
    glVertex2f(0, 0);
    glVertex2f(0, -20);
    glEnd();
}
// Function to draw the character 'Z'
void draw_Z()
{
    glBegin(GL_LINES);
    glVertex2f(-10, 20);
    glVertex2f(10, 20);
    glVertex2f(10, 20);
    glVertex2f(-10, -20);
    glVertex2f(-10, -20);
    glVertex2f(10, -20);
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Draw each character
    glPushMatrix();
    glTranslatef(-250, 150, 0);
    draw_A();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-200, 150, 0);
    draw_E();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-150, 150, 0);
    draw_F();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-100, 150, 0);
    draw_H();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-50, 150, 0);
    draw_I();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 150, 0);
    draw_K();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(50, 150, 0);
    draw_L();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(100, 150, 0);
    draw_M();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(150, 150, 0);
    draw_N();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-250, 50, 0);
    draw_T();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-200, 50, 0);
    draw_V();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-150, 50, 0);
    draw_W();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-100, 50, 0);
    draw_X();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-50, 50, 0);
    draw_Y();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 50, 0);
    draw_Z();
    glPopMatrix();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Characters Display using OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
