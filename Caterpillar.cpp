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
    // Draw the body circles
    bresenhamCircle(220, 250, 50);
    bresenhamCircle(300, 250, 50);
    bresenhamCircle(390, 250, 50);
    bresenhamCircle(475, 250, 50);
    // head
    bresenhamCircle(125, 250, 50);
    // eyes
    bresenhamCircle(110, 275, 10);
    bresenhamCircle(140, 275, 10);
    // antennae
    drawLine(110, 300, 90, 340);
    drawLine(140, 300, 160, 340);
    // tips of antennae
    bresenhamCircle(90, 340, 10);
    bresenhamCircle(160, 340, 10);
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
    glutCreateWindow("Bresenham's Circle Drawing Caterpillar");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
