// Bresenham house
#include <GL/glut.h>
int x1, x2, y1, y2;
void myInit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}
void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
void draw_line(int x1, int x2, int y1, int y2)
{
    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x, y;
    dx = x2 - x1;
    dy = y2 - y1;
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    incx = 1;
    if (x2 < x1)
        incx = -1;
    incy = 1;
    if (y2 < y1)
        incy = -1;
    x = x1;
    y = y1;
    if (dx > dy)
    {
        draw_pixel(x, y);
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        for (i = 0; i < dx; i++)
        {
            if (e >= 0)
            {
                y += incy;
                e += inc1;
            }
            else
            {
                e += inc2;
                x += incx;
                draw_pixel(x, y);
            }
        }
    }
    else
    {
        draw_pixel(x, y);
        e = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;
        for (i = 0; i < dy; i++)
        {
            if (e >= 0)
            {
                x += incx;
                e += inc1;
            }
            else
            {
                e += inc2;
                y += incy;
                draw_pixel(x, y);
            }
        }
    }
}
void display()
{
    draw_line(x1, x2, y1, y2);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(200, 300);
    glVertex2i(120, 300);
    glVertex2i(120, 50);
    glVertex2i(200, 50);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(120, 300);
    glVertex2i(160, 400);
    glVertex2i(200, 300);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(160, 400);
    glVertex2i(380, 400);
    glVertex2i(430, 300);
    glVertex2i(200, 300);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(430, 300);
    glVertex2i(430, 50);
    glVertex2i(120, 50);
    glVertex2i(120, 300);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(130, 50);
    glVertex2i(130, 150);
    glVertex2i(180, 150);
    glVertex2i(180, 50);
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Bresenham Line (house)");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
