#include <GL/glut.h>
#include <iostream>
using namespace std;

// Initialize OpenGL settings
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Black background
    gluOrtho2D(0, 500, 0, 500);       // Set the coordinate system
}

// Function to set a pixel's color
void setPixel(int x, int y, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

// Function to get a pixel's color
void getPixelData(int x, int y, float* color) {
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
}

// 8-connected boundary fill algorithm
void boundaryFill(int x, int y, float fillColor[3], float boundaryColor[3]) {
    float color[3];
    getPixelData(x, y, color);

    // Only proceed if the current pixel isn't already filled or part of the boundary
    if ((color[0] != boundaryColor[0] || color[1] != boundaryColor[1] || color[2] != boundaryColor[2]) &&
        (color[0] != fillColor[0] || color[1] != fillColor[1] || color[2] != fillColor[2])) {

        setPixel(x, y, fillColor[0], fillColor[1], fillColor[2]);

        // Recursively fill all 8-connected neighbors
        boundaryFill(x + 1, y, fillColor, boundaryColor);     // Right
        boundaryFill(x - 1, y, fillColor, boundaryColor);     // Left
        boundaryFill(x, y + 1, fillColor, boundaryColor);     // Up
        boundaryFill(x, y - 1, fillColor, boundaryColor);     // Down
//        boundaryFill(x + 1, y + 1, fillColor, boundaryColor); // Bottom-right diagonal
//        boundaryFill(x - 1, y + 1, fillColor, boundaryColor); // Bottom-left diagonal
//        boundaryFill(x + 1, y - 1, fillColor, boundaryColor); // Top-right diagonal
//        boundaryFill(x - 1, y - 1, fillColor, boundaryColor); // Top-left diagonal
    }
}

// Function to draw a boundary (triangle in this case)
void draw() {
    glColor3f(1.0, 1.0, 0.0); // Yellow color for the boundary
    glBegin(GL_LINE_LOOP);
    glVertex2i(150, 400);    // Top vertex
    glVertex2i(50, 200);    // Bottom-left vertex
    glVertex2i(250, 200);    // Bottom-right vertex
    glEnd();
    glFlush();
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    draw();

    float fillColor[] = {1.0, 0.0, 0.0};     // Red fill color
    float boundaryColor[] = {1.0, 1.0, 0.0}; // Yellow boundary color

    boundaryFill(52, 202, fillColor, boundaryColor); // Start filling at (153, 202)
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500); // Set window size
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("8-Connected Boundary Fill (OpenGL)");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
