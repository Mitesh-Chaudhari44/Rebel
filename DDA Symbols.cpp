#include <GL/glut.h>
#include <cmath>
#include <iostream>

// Function to implement the DDA Line Drawing Algorithm
void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;

    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        glVertex2i(round(x), round(y));
        x += Xinc;
        y += Yinc;
    }
    glEnd();
    glFlush();
}

// Function to draw the '+' symbol
void drawPlusSymbol()
{
    // Vertical line of '+'
    drawLine(150, 200, 150, 250);
    // Horizontal line of '+'
    drawLine(125, 225, 175, 225);
}

// Function to draw the '-' symbol
void drawMinusSymbol()
{
    drawLine(125, 150, 175, 150);
}

// Function to draw the '<' symbol
void drawLessThanSymbol()
{
    drawLine(100, 100, 150, 125);
    drawLine(100, 100, 150, 75);
}

// Display function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // White color

    drawPlusSymbol();
    drawMinusSymbol();
    drawLessThanSymbol();

    glFlush();
}

// Initialization function
void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glColor3f(1.0, 1.0, 1.0);         // White drawing color
    glPointSize(2.0);                 // Point size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 300, 0, 300);       // Coordinate system for drawing
}

// Main function
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing - Arithmetic and Comparison Symbols");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
