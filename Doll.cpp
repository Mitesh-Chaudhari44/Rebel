#include <GL/glut.h>
void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    gluOrtho2D(0, 500, 0, 500);
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
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    bresenhamCircle(260, 150, 120);
    bresenhamCircle(250, 350, 80);
    bresenhamCircle(190, 440, 30);
    bresenhamCircle(310, 440, 30);
    bresenhamCircle(250, 320, 30);
    bresenhamCircle(220, 360, 15);
    bresenhamCircle(280, 360, 15);
    bresenhamCircle(250, 330, 8);
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham's Circle Drawing(doll)");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}