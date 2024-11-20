#include <GL/glut.h>

// Initialization function to set up the coordinate system
void init() {
    // Set the 2D orthographic projection (coordinate system)
    gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
}

// Display function to render the graphics primitives
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    // Draw a Point (GL_POINTS)
    glPointSize(5);
    glColor3f(1.0, 0.0, 0.0); // Red color
    glBegin(GL_POINTS);
        glVertex2f(-40, 40);
    glEnd();

    // Draw a Line (GL_LINES)
    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 0.0); // Yellow color
        glVertex2f(-30, 40);
        glVertex2f(-10, 40);
    glEnd();

    // Draw a Line Strip (GL_LINE_STRIP)
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0, 0.0, 1.0); // Blue color
        glVertex2f(0, 40);
        glVertex2f(10, 40);
        glVertex2f(10, 30);
        glVertex2f(20, 30);
    glEnd();

    // Draw a Line Loop (GL_LINE_LOOP)
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0, 0.0, 1.0); // Magenta color
        glVertex2f(30, 40);
        glVertex2f(40, 40);
        glVertex2f(40, 30);
        glVertex2f(30, 30);
    glEnd();

    // Draw a Triangle (GL_TRIANGLES)
    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 1.0, 0.0); // Green color
        glVertex2f(-40, 20);
        glVertex2f(-30, 10);
        glVertex2f(-50, 10);
    glEnd();

    // Draw a Quadrilateral (GL_QUADS)
    glBegin(GL_QUADS);
        glColor3f(0.0, 1.0, 1.0); // Cyan color
        glVertex2f(30, 20);
        glVertex2f(40, 20);
        glVertex2f(40, 10);
        glVertex2f(30, 10);
    glEnd();

    // Draw a Polygon (GL_POLYGON)
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 1.0); // Magenta color
        glVertex2f(-40, -10);
        glVertex2f(-30, -5);
        glVertex2f(-20, -10);
        glVertex2f(-25, -20);
        glVertex2f(-35, -20);
    glEnd();

    glFlush();  // Render the graphics
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("All Shapes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
