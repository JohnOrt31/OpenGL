#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>

void display(void) {
       glClear(GL_COLOR_BUFFER_BIT);

       //draw box no:1 (top right)
       glColor3f(0.117647, 0.564706, 1);      //(red, green, blue)
       glBegin(GL_POLYGON);

       //A
       glVertex3f(0.0, 12.0, 0.0);
       //B
       glVertex3f(12.0, 15.0, 0.0);
       //C
       glVertex3f(12.0, 0.5, 0.0);
       //D
       glVertex3f(0.0, 0.5, 0.0);
      
      


       glEnd();
       glFlush();


       //draw box No: 2 (top left)
       glColor3f(0.117647, 0.564706, 1);      //(red, green, blue)
       glBegin(GL_POLYGON);

       //A
       glVertex3f(-10.0, 10.0, 0.0);
       //B
       glVertex3f(-0.5, 12.0, 0.0);
       //C
       glVertex3f(-0.5, 0.5, 0.0);
       //D
       glVertex3f(-10.0, 0.5, 0.0);


       glEnd();
       glFlush();


      
       //draw box No: 3 (bottom left)
       glColor3f(0.117647, 0.564706, 1);      //(red, green, blue)
       glBegin(GL_POLYGON);

       //A
       glVertex3f(-10.0, -0.5, 0.0);
       //B
       glVertex3f(-0.5, -0.5, 0.0);
       //C
       glVertex3f(-0.5, -12.0, 0.0);
       //D
       glVertex3f(-10.0, -10.0, 0.0);


       glEnd();
       glFlush();



       //draw box No: 4 (bottom right)
       glColor3f(0.117647, 0.564706, 1);      //(red, green, blue)
       glBegin(GL_POLYGON);

       //A
       glVertex3f(0.0, -0.5, 0.0);
       //B
       glVertex3f(12.0, -0.5, 0.0);
       //C
       glVertex3f(12.0, -15.0, 0.0);
       //D
       glVertex3f(0.0, -12.0, 0.0);


       glEnd();
       glFlush();


}


void init(void) {
       // select background color
       glClearColor(1.0, 1.0, 1.0, 1.0); // (red, green, blue, alpha), used by glClear

       // Define world coordinate frame
       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       glOrtho(-30.0, 30.0, -30.0, 30.0, -30.0, 30.0); // model in real word units
       // (left, right, bottom, top, near, far)
}


int main(int argc, char** argv) {
       //Step#1 Create and initialize glut windowing system
       glutInit(&argc, argv);
       glutInitWindowSize(600, 400);
       glutInitWindowPosition(100, 100);
       glutCreateWindow("Windows 10 Logo by glut");
       //Step#2 Do Open GL related initializations
       init();
       //Step#3 Register Call back methods or Event Handler methods
       glutDisplayFunc(display);
       //Step#4 Enter in  main loop (an infinite loop listening to registered events and then call their registered methods if any)
       glutMainLoop();
       return 0;

}
