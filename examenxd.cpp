#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>


namespace Cube {

	const int NUM_VERTICES = 8;
	const int NUM_FACES = 6;
	
	GLint vertices[NUM_VERTICES][3] = {
	  {0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1},
	  {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}};
	
	GLint faces[NUM_FACES][4] = {
	  {1, 5, 7, 3}, {5, 4, 6, 7}, {4, 0, 2, 6},
	  {3, 7, 6, 2}, {0, 1, 3, 2}, {0, 4, 5, 1}};
	
	GLfloat vertexColors[NUM_VERTICES][3] = {
	  {1.0, 0.79, 0.23}, {0.88, 0.34, 1.0}, {0.23, 1.0, 0.0}, {0.0, 1.0, 1.0},
	  {1.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {1.0, 1.0, 0.0}, {1.0, 1.0, 1.0}};
	
	void draw() {
	  glBegin(GL_QUADS);
	  for (int i = 0; i < NUM_FACES; i++) {
	    for (int j = 0; j < 4; j++) {
	      glColor3fv((GLfloat*)&vertexColors[faces[i][j]]);
	      glVertex3iv((GLint*)&vertices[faces[i][j]]);
	    }
	  }
	  glEnd();
	}
}


void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  Cube::draw();
  glFlush();
  glutSwapBuffers();
}

void timer(int v) {
  static GLfloat u = 0.0;
  u += 0.01;
  glLoadIdentity();
  gluLookAt(2*cos(u), 3*cos(u)-1, 8*cos(u/3)+5, .34, .65, .12, 1-cos(u), 1, 1);
  glutPostRedisplay();
  glutTimerFunc(1000/60.0, timer, v);
}


void reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, GLfloat(w) / GLfloat(h), 0.5, 40.0);
  glMatrixMode(GL_MODELVIEW);
}


void init() {
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
}


int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("The RGB Color Cube");
  glutReshapeFunc(reshape);
  glutTimerFunc(100, timer, 0);
  glutDisplayFunc(display);
  init();
  glutMainLoop();
}
