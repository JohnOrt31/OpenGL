#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
const double TWO_PI = 6.2831853;
GLsizei winWidth = 500, winHeight = 500; // Initial display window size.
GLuint regHex; // Define name for display list.
static GLfloat rotTheta = 0.0;

class scrPt {
	public:
	GLint x, y;
};

static void init(void)
{
	scrPt hexVertex;
	GLdouble hexTheta;
	GLint k;
	glClearColor (0.0, 0.0, 0.0, 0.0);
	/* Set up a display list for a red regular hexagon.
	* Vertices for the hexagon are six equally spaced
	* points around the circumference of a circle.
	*/
	regHex = glGenLists (1);
	glNewList (regHex, GL_COMPILE);
	glColor3f (1.0, 0.0, 0.0);
	glBegin (GL_POLYGON);
	for (k = 0; k < 100; k++) {
		hexTheta = TWO_PI * k / 100;
		hexVertex.x = 150 + 10 * cos (hexTheta);
		hexVertex.y = 150 + 10 * sin (hexTheta);
		glVertex2i (hexVertex.x, hexVertex.y);
	}
	glEnd ( );
	
	glColor3f (0.54, 0.45, 0.0);
	glBegin (GL_POLYGON);
	for (k = 0; k < 100; k++) {
		hexTheta = TWO_PI * k / 100;
		hexVertex.x = -150 + 10 * cos (hexTheta);
		hexVertex.y = -150 + 10 * sin (hexTheta);
		glVertex2i (hexVertex.x, hexVertex.y);
	}
	glEnd ( );
	

	
	
	glColor3f (1.0, 1.0, 1.0);
	glBegin (GL_POLYGON);
	for (k = 0; k < 100; k++) {
		hexTheta = (TWO_PI+1.0) * k / 100;
		hexVertex.x = 200 + 30 * cos (hexTheta);
		hexVertex.y = 200 + 30 * sin (hexTheta);
		glVertex2i (hexVertex.x, hexVertex.y);
	}
	glEnd ( );
	
	glColor3f (1.0, 0.0, 0.0);
	glBegin (GL_POLYGON);
	for (k = 0; k < 100; k++) {
		hexTheta = (TWO_PI+1.0) * k / 100;
		hexVertex.x = -200 + 30 * cos (hexTheta);
		hexVertex.y = -200 + 30 * sin (hexTheta);
		glVertex2i (hexVertex.x, hexVertex.y);
	}
	glEnd ( );
	
	glColor3f (1.0, 0.0, 1.0);
	glBegin (GL_POLYGON);
	for (k = 0; k < 100; k++) {
		hexTheta = (TWO_PI) * k / 100;
		hexVertex.x = 100 + 20 * cos (hexTheta);
		hexVertex.y = 100 + 20 * sin (hexTheta);
		glVertex2i (hexVertex.x, hexVertex.y);
	}
	glEnd ( );
	
	glColor3f (0.0, 1.0, 1.0);
	glBegin (GL_POLYGON);
	for (k = 0; k < 100; k++) {
		hexTheta = (TWO_PI) * k / 100;
		hexVertex.x = -100 + 20 * cos (hexTheta);
		hexVertex.y = -100 + 20 * sin (hexTheta);
		glVertex2i (hexVertex.x, hexVertex.y);
	}
	glEnd ( );
	
	glColor3f (1.0, 1.0, 0.0);
	glBegin (GL_POLYGON);
	for (k = 0; k < 100; k++) {
		hexTheta = TWO_PI * k / 100;
		hexVertex.x = 0 + 60 * cos (hexTheta);
		hexVertex.y = 0 + 60 * sin (hexTheta);
		glVertex2i (hexVertex.x, hexVertex.y);
	}
	glEnd ( );
	

	
	
	
	
	glEndList ( );
	
	
}

void displayHex (void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glPushMatrix ( );
	glRotatef (rotTheta, 0.0, 0.0, 1.0);
	glCallList (regHex);
	glPopMatrix ( );
	glutSwapBuffers ( );
	glFlush ( );
}
void rotateHex (void)
{
	rotTheta -= 0.2;
	if (rotTheta < 360.0)
		rotTheta += 360.0;
	glutPostRedisplay ( );
}

void rotateHex2 (void)
{
	rotTheta += 0.5;
	if (rotTheta > 360.0)
		rotTheta -= 360.0;
	glutPostRedisplay ( );
}
void winReshapeFcn (GLint newWidth, GLint newHeight)
{
	glViewport (0, 0, (GLsizei) newWidth, (GLsizei) newHeight);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ( );
	gluOrtho2D (-320.0, 320.0, -320.0, 320.0);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ( );
	glClear (GL_COLOR_BUFFER_BIT);
}
void mouseFcn (GLint button, GLint action, GLint x, GLint y)
{
	switch(button) {
		case GLUT_LEFT_BUTTON: // Start the rotation.
			if (action == GLUT_DOWN){
				glutIdleFunc (rotateHex);	
			}
			break;
		
		case GLUT_RIGHT_BUTTON: // Stop the rotation.
			if (action == GLUT_DOWN)
			{
				glutIdleFunc (rotateHex2);	
			}	
			break;
		
		default:
			break;
	}
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition (150, 150);
	glutInitWindowSize (winWidth, winHeight);
	glutCreateWindow ("Animation Example");
	init( );
	glutDisplayFunc (displayHex);
	glutReshapeFunc (winReshapeFcn);
	glutMouseFunc (mouseFcn);
	glutMainLoop ( );
	return EXIT_SUCCESS; 
}
