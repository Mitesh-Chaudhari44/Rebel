#include <GL/glut.h>
#include <algorithm>
void myInit()
{
    glClearColor(1, 1, 1, 1); // Set background color to white
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480);
}
void drawPolygon()
{
    glColor3f(1, 0, 0); // Red boundary color
    glBegin(GL_LINE_LOOP);
    glVertex2i(100, 100);
    glVertex2i(100, 300);
    glVertex2i(300, 300);
    glVertex2i(300, 100);
    glEnd();
}
void scanLineFill()
{
    int yMin = 100, yMax = 300; // Define minimum and maximum y-values for filling
    glColor3f(0, 0, 1);         // Set fill color to blue
    for (int y = yMin; y <= yMax; ++y)
    {
        for (int x = 100; x <= 300; ++x)
        {
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
            glFlush();
        }
    }
}
void display()
{
    drawPolygon();
    scanLineFill();
}
int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Scan Line Fill Algorithm");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
