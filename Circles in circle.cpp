#include <GL/glut.h>
void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    gluOrtho2D(0, 600, 0, 600);
}
void plot(int x, int y, int xc, int yc)
{
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
    glEnd();
}
void bresenhamCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (y >= x)
    {
        plot(x, y, xc, yc);
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
        {
            d = d + 4 * x + 6;
        }
        plot(x, y, xc, yc);
    }
}
void drawLine(int x1, int y1, int x2, int y2)
{
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
}
void draw()
{
    bresenhamCircle(220, 105, 10);
    bresenhamCircle(220, 109, 15);
    bresenhamCircle(220, 110, 20);
    bresenhamCircle(220, 115, 25);
    bresenhamCircle(220, 118, 30);
    bresenhamCircle(220, 120, 35);
    bresenhamCircle(220, 125, 40);
    bresenhamCircle(220, 128, 45);
    bresenhamCircle(220, 134, 50);
    bresenhamCircle(220, 135, 55);
    bresenhamCircle(220, 139, 60);
    bresenhamCircle(220, 146, 65);
    bresenhamCircle(220, 148, 70);
    bresenhamCircle(220, 152, 75);
    bresenhamCircle(220, 156, 80);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    draw();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow(" Bresenham's Circle ");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
