#include <iostream>
#include <vector>
#include <algorithm>
#include <GL/glut.h>
using namespace std;

vector<int> pointsX = { 100, 300, 300, 100 };
vector<int> pointsY = { 100, 100, 250, 250 };

// Initialize OpenGL
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // Set background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);  // Set the coordinate system
}

// Function to draw a point at (x, y) with a specified color
void drawPoint(int x, int y, float* color) {
    glColor3fv(color);  // Set the color for the point
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

// Function to fill the polygon using the scan-line algorithm
void fillShape(float* fillColor) {
    int numPoints = pointsX.size();
    int highestY = 0;

    // Find the highest Y value of the polygon's vertices
    for (int i = 0; i < numPoints; i++) {
        if (pointsY[i] > highestY) {
            highestY = pointsY[i];
        }
    }

    // Process each scan line
    for (int scanY = 0; scanY <= highestY; scanY++) {
        vector<float> fillX;

        // Find intersections of the scan line with the edges of the polygon
        for (int i = 0; i < numPoints; i++) {
            int y1 = pointsY[i];
            int y2 = pointsY[(i + 1) % numPoints];
            int x1 = pointsX[i];
            int x2 = pointsX[(i + 1) % numPoints];

            // Check if the scan line intersects the edge
            if ((y1 <= scanY && y2 > scanY) || (y2 <= scanY && y1 > scanY)) {
                float intersectionX = x1 + (float)(scanY - y1) * (x2 - x1) / (y2 - y1);
                fillX.push_back(intersectionX);
            }
        }

        // Sort intersection points
        sort(fillX.begin(), fillX.end());

        // Fill between pairs of intersection points
        for (size_t i = 0; i < fillX.size(); i += 2) {
            for (int fillInt = static_cast<int>(fillX[i]); fillInt <= static_cast<int>(fillX[i + 1]); fillInt++) {
                drawPoint(fillInt, scanY, fillColor);
            }
        }
    }
}

// Display function that draws the polygon and fills it
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the polygon outline
    glColor3f(0.0f, 0.0f, 1.0f);  // Blue color for polygon outline
    glBegin(GL_LINE_LOOP);
    for (size_t i = 0; i < pointsX.size(); i++) {
        glVertex2i(pointsX[i], pointsY[i]);
    }
    glEnd();

    // Fill the polygon with red color
    float redColor[3] = { 1.0f, 0.0f, 0.0f };  // Red color
    fillShape(redColor);

    glFlush();
}

// Main function to set up OpenGL and GLUT
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Scan Line Fill");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
