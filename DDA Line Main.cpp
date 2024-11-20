#include<GL/glut.h>
#include<cmath>

void init(){
    glClearColor(0.0,0.0,0.0,1.0);
    gluOrtho2D(0,600,0,600);
}

void draw(int x1,int y1){
    glBegin(GL_POINTS);
    glVertex2i(x1,y1);
    glEnd();
}

void dda_line(int x1,int y1,int x2, int y2){
    float dx,dy,incx,incy,x,y;
    int steps;

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)>abs(dy))
        steps=abs(dx);
    else{
        steps=abs(dy);
    }

    incx=dx/steps;
    incy=dy/steps;

    x=x1;
    y=y1;

    for(int i=0;i<=steps;i++){
        draw(round(x),round(y));
        x+=incx;
        y+=incy;
    }
    glFlush();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    dda_line(100,100,300,300);
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("DDA Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}
