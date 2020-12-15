#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <windows.h>

using namespace std;

struct screenPt
{
    GLint x;
    GLint y;
};

typedef enum { limacon = 1, cardioid, threeLeaf, fourLeaf, spiral } curveName;

GLsizei winWidth = 600, winHeight = 500;

void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment ( screenPt pt1, screenPt pt2){
    glBegin(GL_LINES);
        glVertex2i( pt1.x, pt1.y);
        glVertex2i( pt2.x, pt2.y);
    glEnd();
}

void drawCurve (GLint curveNum)
{
    const GLdouble two_Pi = 6.283185 ;
    const GLint a = 175 , b = 60 ;
    GLfloat r , theta , dtheta = 0.001; // float ta.
    GLint x0 = 200 , y0 = 250 ; // Establece r posició n inicia l e n l a pantalla .
    screenPt curvePt[2] ;
    glColor3f (0.0 , 0.0 , 0.0) ; // Selecciona r negr o como colo r d e curva .
    curvePt[0].x = x0 ; // inicial !
    curvePt[0].y = y0; 

    switch (curveNum)
    {
        case limacon: curvePt[0].x += a + b; break;
        case cardioid: curvePt[0].x += a + b;  break;
        case threeLeaf: curvePt[0].x += a; break;
        case fourLeaf: curvePt[0].x += a; break;
        case spiral: break;    
        default: break;
    }

    theta = dtheta;

    while(theta < two_Pi){
        switch (curveNum)
        {
        case limacon:
            r = a * cos(theta) + b;
            break;
        case cardioid:
            r = a * ( 1 + cos(theta));
            break;
        case threeLeaf:
            r = a * cos(3 * theta); 
            break;
        case fourLeaf:
            r = a * cos(2 * theta);
            break;
        case spiral:
            r = (a / 4.0) * theta;
        default:
            break;
        }

        curvePt[1].x = x0 + r * cos(theta);
        curvePt[1].y = y0 + r * sin(theta);
        lineSegment (curvePt[0], curvePt[1]);

        curvePt[0].x = curvePt[1].x;
        curvePt[0].y = curvePt[1].y;
        theta += dtheta;
        
    }
}

void displayFcn(void)
{
    GLint curveNum;
    glClear(GL_COLOR_BUFFER_BIT);
    cout << "\nEnter the integer value corresponding to\n";
    cout << "one of the following curve names.\n";
    cout << "Press any other key to exit.\n";
    cout << "\ni-limacon , 2-cardioid , 3-threaLeaf , 4-fourLeaf , 5-spiral\n";
    cin >> curveNum;

    if(curveNum >= 1 && curveNum <= 5 ){
        drawCurve(curveNum);
    } 
    else
    {
        exit(0);
    }
    glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)newWidth, 0.0, (GLdouble)newHeight);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Draw curves");
    init();
    glutDisplayFunc(displayFcn);
    glutReshapeFunc(winReshapeFcn);
    glutMainLoop();
    return EXIT_SUCCESS;
}
