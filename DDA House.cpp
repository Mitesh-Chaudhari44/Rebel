#include <GL/glut.h>
#include <cmath>
#include <iostream>
// Function to implement the DDA Line Drawing Algorithm
void drawLine(int x1, int y1, int x2, int y2) {
int dx = x2 - x1;
int dy = y2 - y1;
int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

 float Xinc = dx / (float) steps;

 float Yinc = dy / (float) steps;

 float x = x1;
    float y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {
        glVertex2i(round(x), round(y));
        x += Xinc;
        y += Yinc;
    }
    glEnd();
    glFlush();
}

// Function to draw a house
void drawHouse() {
    // Draw the base of the house
    drawLine(100, 100, 300, 100); // Bottom side
    drawLine(100, 100, 100, 200); // Left side
    drawLine(300, 100, 300, 200); // Right side
    drawLine(100, 200, 300, 200); // Top side

    // Draw the roof
    drawLine(100, 200, 200, 300); // Left slope of the roof
    drawLine(300, 200, 200, 300); // Right slope of the roof

    // Draw the door
    drawLine(175, 100, 175, 150); // Left side of the door
    drawLine(225, 100, 225, 150); // Right side of the door
    drawLine(175, 150, 225, 150); // Top side of the door

    // Draw a window on the left
    drawLine(120, 130, 150, 130); // Bottom side of window
    drawLine(120, 130, 120, 160); // Left side of window
    drawLine(150, 130, 150, 160); // Right side of window
    drawLine(120, 160, 150, 160); // Top side of window
    drawLine(135, 130, 135, 160); // Vertical middle line of window
    drawLine(120, 145, 150, 145); // Horizontal middle line of window

    // Draw a window on the right
    drawLine(250, 130, 280, 130); // Bottom side of window
    drawLine(250, 130, 250, 160); // Left side of window
    drawLine(280, 130, 280, 160); // Right side of window
    drawLine(250, 160, 280, 160); // Top side of window
    drawLine(265, 130, 265, 160); // Vertical middle line of window
    drawLine(250, 145, 280, 145); // Horizontal middle line of window
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // White color

    drawHouse(); // Draw the house

    glFlush();
}

// Initialization function
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glColor3f(1.0, 1.0, 1.0);         // White drawing color
    glPointSize(2.0);                 // Point size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400);       // Coordinate system for drawing
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing - House");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
