#include<GL/glut.h>
#include<iostream>
using namespace std;
//coordinates=-110 -130 50 60
//Line 2: -130 0 80 0

int cminx = -100, cminy = -100, cmaxx = 100, cmaxy = 100;
int ominx = 150, ominy = 150, omaxx = 350, omaxy = 350;
const int INSIDE = 0, LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;

int lineCoordinates[2][4];

int getRegionCode(int x, int y) {
    int code = INSIDE;
    if (x < cminx) code |= LEFT;
    else if (x > cmaxx) code |= RIGHT;
    if (y < cminy) code |= BOTTOM;
    else if (y > cmaxy) code |= TOP;
    return code;
}

void clipLine(int x1, int y1, int x2,int y2) {
    int code1 = getRegionCode(x1, y1), code2 = getRegionCode(x2, y2);
    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = true;
            break;
        }
        else if (code1 & code2)
            break;

        else {
            int codeOut, x, y;
            if (code1 != 0) codeOut = code1;
            else codeOut = code2;

            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (cmaxy - y1) / (y2 - y1);
                y = cmaxy;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (cminy - y1) / (y2 - y1);
                y = cminy;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (cmaxx - x1) / (x2 - x1);
                x = cmaxx;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (cminx - x1) / (x2 - x1);
                x = cminx;
            }

            if (codeOut == code1) {
                x1 = x; y1 = y;
                code1 = getRegionCode(x1, y1);
            } else {
                x2 = x; y2 = y;
                code2 = getRegionCode(x2, y2);
            }
        }
    }

    if (accept) {
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
        glVertex2i(x1, y1);
        glVertex2i(x2, y2);
        glEnd();
        glFlush();
    }
}

void drawLineNoClip(int x1, int y1, int x2, int y2) {
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    cout << "Enter coordinates for two lines in the format x1 y1 x2 y2:\n";
    for (int i = 0; i < 2; i++) {
        cout << "Line " << i + 1 << ": ";
        cin >> lineCoordinates[i][0] >> lineCoordinates[i][1] >> lineCoordinates[i][2] >> lineCoordinates[i][3];
    }

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(cminx, cminy);
    glVertex2i(cmaxx, cminy);
    glVertex2i(cmaxx, cmaxy);
    glVertex2i(cminx, cmaxy);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(ominx, ominy);
    glVertex2i(omaxx, ominy);
    glVertex2i(omaxx, omaxy);
    glVertex2i(ominx, omaxy);
    glEnd();

    for (int i = 0; i < 2; i++) {
        drawLineNoClip(lineCoordinates[i][0] + 250, lineCoordinates[i][1] + 250, lineCoordinates[i][2] + 250, lineCoordinates[i][3] + 250);
        clipLine(lineCoordinates[i][0], lineCoordinates[i][1], lineCoordinates[i][2], lineCoordinates[i][3]);
    }

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300, 500, -300, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Cohen-Sutherland Line Clipping - User Input Example");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
