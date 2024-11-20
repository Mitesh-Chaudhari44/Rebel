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

// Function to draw the specified characters
void drawCharacter(char ch) {
    switch (ch) {
        case 'A':
            drawLine(50, 50, 70, 100); // Left diagonal
            drawLine(70, 100, 90, 50); // Right diagonal
            drawLine(60, 75, 80, 75);  // Middle bar
            break;
        case 'E':
            drawLine(100, 50, 100, 100); // Vertical line
            drawLine(100, 100, 130, 100); // Top horizontal
            drawLine(100, 75, 125, 75);   // Middle horizontal
            drawLine(100, 50, 130, 50);   // Bottom horizontal
            break;
        case 'F':
            drawLine(150, 50, 150, 100); // Vertical line
            drawLine(150, 100, 180, 100); // Top horizontal
            drawLine(150, 75, 170, 75);   // Middle horizontal
            break;
        case 'H':
            drawLine(200, 50, 200, 100); // Left vertical
            drawLine(230, 50, 230, 100); // Right vertical
            drawLine(200, 75, 230, 75);  // Middle horizontal
            break;
        case 'I':
            drawLine(250, 50, 280, 50);  // Bottom horizontal
            drawLine(265, 50, 265, 100); // Vertical line
            drawLine(250, 100, 280, 100); // Top horizontal
            break;
        case 'K':
            drawLine(300, 50, 300, 100); // Vertical line
            drawLine(300, 75, 330, 100); // Upper diagonal
            drawLine(300, 75, 330, 50);  // Lower diagonal
            break;
        case 'L':
            drawLine(350, 50, 350, 100); // Vertical line
            drawLine(350, 50, 380, 50);  // Bottom horizontal
            break;
        case 'M':
            drawLine(400, 50, 400, 100); // Left vertical
            drawLine(400, 100, 425, 75); // Middle diagonal
            drawLine(425, 75, 450, 100); // Middle diagonal
            drawLine(450, 100, 450, 50); // Right vertical
            break;
        case 'N':
            drawLine(470, 50, 470, 100); // Left vertical
            drawLine(470, 100, 500, 50); // Diagonal
            drawLine(500, 50, 500, 100); // Right vertical
            break;
        case 'T':
            drawLine(520, 100, 560, 100); // Top horizontal
            drawLine(540, 50, 540, 100);  // Vertical line
            break;
        case 'V':
            drawLine(580, 100, 600, 50); // Left diagonal
            drawLine(600, 50, 620, 100); // Right diagonal
            break;
        case 'W':
            drawLine(640, 100, 660, 50);  // Left diagonal
            drawLine(660, 50, 680, 75);   // Middle line
            drawLine(680, 75, 700, 50);   // Middle line
            drawLine(700, 50, 720, 100);  // Right diagonal
            break;
        case 'X':
            drawLine(740, 50, 780, 100); // Diagonal from bottom-left to top-right
            drawLine(740, 100, 780, 50); // Diagonal from top-left to bottom-right
            break;
        case 'Y':
            drawLine(800, 100, 820, 75); // Upper left diagonal
            drawLine(820, 75, 840, 100); // Upper right diagonal
            drawLine(820, 75, 820, 50);  // Vertical line
            break;
        case 'Z':
            drawLine(860, 100, 900, 100); // Top horizontal
            drawLine(900, 100, 860, 50);  // Diagonal
            drawLine(860, 50, 900, 50);   // Bottom horizontal
            break;
    }
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // White color

    // Draw all the characters
    drawCharacter('A');
    drawCharacter('E');
    drawCharacter('F');
    drawCharacter('H');
    drawCharacter('I');
    drawCharacter('K');
    drawCharacter('L');
    drawCharacter('M');
    drawCharacter('N');
    drawCharacter('T');
    drawCharacter('V');
    drawCharacter('W');
    drawCharacter('X');
    drawCharacter('Y');
    drawCharacter('Z');

    glFlush();
}

// Initialization function
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glColor3f(1.0, 1.0, 1.0);         // White drawing color
    glPointSize(2.0);                 // Point size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 300);      // Coordinate system for drawing
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing - Characters");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
