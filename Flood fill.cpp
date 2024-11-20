#include <GL/glut.h>

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(0, 500, 0, 500);
}

void setPixel(int x, int y, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void getPixelData(int x, int y, float* color) {
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
}

void floodFill(int x, int y, float fillColor[3], float oldColor[3]) {
    float color[3];
    getPixelData(x, y, color);

    // Check if current pixel matches the old color
    if (color[0] == oldColor[0] && color[1] == oldColor[1] && color[2] == oldColor[2]) {
        setPixel(x, y, fillColor[0], fillColor[1], fillColor[2]);

        // Recursive calls with boundary checks
        if (x + 1 < 500) floodFill(x + 1, y, fillColor, oldColor);
        if (x - 1 >= 0) floodFill(x - 1, y, fillColor, oldColor);
        if (y + 1 < 500) floodFill(x, y + 1, fillColor, oldColor);
        if (y - 1 >= 0) floodFill(x, y - 1, fillColor, oldColor);
    }
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);

    // Draw a proper closed polygon
    glBegin(GL_LINE_LOOP);
    glVertex2i(200, 200);
    glVertex2i(300, 200);
    glVertex2i(300, 100);
    glVertex2i(200, 100);
    glEnd();

    float fillColor[] = {0.0, 1.0, 0.0};
    float oldColor[] = {0.0, 0.0, 0.0};

    // Start flood fill inside the closed shape
    floodFill(200, 101, fillColor, oldColor);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Flood Fill - Closed Polygon");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
