#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>


void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  
  glBegin(GL_POLYGON);
  for (GLfloat i = -2.5; i <= 2.5; i += 0.25) {
  	glColor3f(0.0, 1.0, 0.0);
    glVertex3f(i, 1, 2.5); 
    
    glColor3f(1.0, 0.0, 1.0);
	glVertex3f(i, 2, -2.5);
	
	glColor3f(0.0, 1.0, 1.0);
    glVertex3f(2.5, 2, i); 
    
    glColor3f(0.20, 0.56, 1.0);
	glVertex3f(-2.5, 1, i);
	
  	
  }
  glEnd();


  glBegin(GL_LINES);
  for (GLfloat i = -2.5; i <= 2.5; i += 0.25) {
  	glColor3f(1.0, 0.0, 1.0);
    glVertex3f(i, 0, 2.5); 
    
    glColor3f(1.0, 1.0, 1.0);
	glVertex3f(i, 0, -2.5);
	
	glColor3f(0.0, 0.0, 1.0);
    glVertex3f(2.5, 0, i); 
    
    glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-2.5, 0, i);
  	
  }
  glEnd();  
  
                      

  glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0, 0, 1); 
	glVertex3f(0, 2, 0);
	
    glColor3f(0, 1, 0); 
	glVertex3f(-1, 0, 1);
    
	glColor3f(0, 1, 0); 
	glVertex3f(1, 0, 1);
    
    glColor3f(1, 0, 1); 
	glVertex3f(0, -2, -4);
	
    glColor3f(1, 0, 1); 
	glVertex3f(0, 2, 0);
	
    glColor3f(1, 1, 0); 
	glVertex3f(-1, 0, 1);
  glEnd();

  glFlush();
}

void init() {
  glClearColor(0.43, 0.34, 0.84, 0.0);
  
  glColor3f(1.0, 1.0, 1.0);


  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-2, 2, -1.5, 1.5, 1, 40);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0, 0, -3);
  glRotatef(30, 1, 0, 0);
  glRotatef(40, 0, 1, 0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(60, 60);
  glutInitWindowSize(800, 600);
  glutCreateWindow("A Simple Tetrahedron");
  glutDisplayFunc(display);
  init();         
  glutMainLoop();
}
