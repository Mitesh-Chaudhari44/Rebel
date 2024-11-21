#include<GL/glut.h>
using namespace std;

void init(){
    gluOrtho2D(-500 , 500 , -500 ,500);
}


void draw_pixel(int x , int y){
    glBegin(GL_POINTS);
        glVertex2i(x , y);
    glEnd();
    glFlush();
}

void draw_line(int x1 , int y1 , int x2 ,int y2){

    int dx , dy , p , x,y;
    int incx ,incy,inc1,inc2;

    dx = x2 - x1;
    dy = y2 -y1;

    if(dx <0) dx = -dx;
    if(dy <0) dy = -dy;


    incx = (x2 > x1) ? 1 : -1;
    incy = (y2 > y1) ? 1 : -1;

    x = x1;
    y = y1;

    if(dx > dy){

        draw_pixel(x , y);
        p = 2*dy - dx;

        for(int i =0 ; i < dx ; i++){
            if(p >= 0){
                y += incy;
                p += 2*(dy-dx);
            }
            else{
                p += 2*dy;
            }
            x += incx;
            draw_pixel(x , y);
        }
    }
    else{

        draw_pixel(x , y);
        p = 2*dx - dy;

        for(int i =0 ; i <dy ; i++){
            if(p >= 0){
                x += incx;
                y += incy;
                p += 2*(dy-dx);
            }
            else{
                y += incy;
                p += 2*dx;
            }
            draw_pixel(x , y);
        }
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    //draw_line(50,50,200,150);

    // Square
    //draw_line(100, 100, 200, 100);
    //draw_line(200, 100, 200, 200);
    //draw_line(200, 200, 100, 200);
    //draw_line(100, 200, 100, 100);

    // Doctor
    draw_line(-100 , -300 , 100 , -300);
    draw_line(100 , -300 , 100 , -100);
    draw_line(100 , -100 , 300 , -100);
    draw_line(300 , -100 , 300 , 100);
    draw_line(300 , 100 , 100 , 100);
    draw_line(100 , 100 , 100 , 300);
    draw_line(100 , 300 , -100 , 300);
    draw_line(-100 , 300 , -100 , 100);
    draw_line(-100 , 100 , -300 , 100);
    draw_line(-300 , 100 , -300 , -100);
    draw_line(-300 , -100 , -100 , -100);
    draw_line(-100 , -100 , -100 , -300);
}

int main(int argc , char ** argv){

    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Window");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}






















