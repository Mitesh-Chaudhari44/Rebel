#include <GL/glut.h>
#include <iostream>

const int width = 8;
const int height = 8;
GLubyte checkerboard[width][height][3];

void createCheckerboardTexture(){
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            int color = ((i & 1) == (j & 1)) ? 255 : 0;
            checkerboard[i][j][0] = (GLubyte)color;
            checkerboard[i][j][1] = (GLubyte)color;
            checkerboard[i][j][2] = (GLubyte)color;
        }
    }
}

void initOpenGL(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);  // Fixed here: changed glBlindTexture to glBindTexture

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    createCheckerboardTexture();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, checkerboard);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
        glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
        glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
        glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);  // Fixed coordinates: changed to 1.0
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Checker Board");  // Fixed here: added missing semicolon
    initOpenGL();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
