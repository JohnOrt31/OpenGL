#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>

GLint winWidth = 600, winHeight = 600; // Initial display-window size.
GLfloat x0 = 100.0, y0 = 50.0, z0 = 50.0; // Viewing-coordinate origin.
GLfloat xref = 50.0, yref = 50.0, zref = 0.0; // Look-at point.
GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0; // View-up vector.
/* Set coordinate limits for the clipping window: */
GLfloat xwMin = -40.0, ywMin = -60.0, xwMax = 40.0, ywMax = 60.0;
/* Set positions for near and far clipping planes: */
GLfloat dnear = 25.0, dfar = 125.0;

void init (void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode (GL_MODELVIEW);
	gluLookAt (x0, y0, z0, xref, yref, zref, Vx, Vy, Vz);
	glMatrixMode (GL_PROJECTION);
	glFrustum (xwMin, xwMax, ywMin, ywMax, dnear, dfar);
}
void displayFcn (void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	/* Set parameters for a square fill area. */
	 // Set fill color to green.
	
	glColor3f(0.117647, 0.564706, 1);
	glPolygonMode (GL_FRONT, GL_FILL);
	glPolygonMode (GL_BACK, GL_LINE); // Wire-frame back face.
	glBegin (GL_QUADS);
	
	glVertex3f (0.0, 0.0, 0.0);
	glVertex3f (45.0, 0.0, 0.0);
	glVertex3f (45.0, 45.0, 0.0);
	glVertex3f (0.0, 45.0, 0.0);
	glEnd ( );
	
	glPolygonMode (GL_FRONT, GL_FILL);
	glPolygonMode (GL_BACK, GL_LINE); // Wire-frame back face.
	glBegin (GL_QUADS);
	
	glVertex3f (50.0, 0.0, 0.0);
	glVertex3f (95.0, 0.0, 0.0);
	glVertex3f (95.0, 45.0, 0.0);
	glVertex3f (50.0, 45.0, 0.0);
	glEnd ( );
	
	glPolygonMode (GL_FRONT, GL_FILL);
	glPolygonMode (GL_BACK, GL_LINE); // Wire-frame back face.
	glBegin (GL_QUADS);
	
	glVertex3f (0.0, 50.0, 0.0);
	glVertex3f (45.0, 50.0, 0.0);
	glVertex3f (45.0, 95.0, 0.0);
	glVertex3f (0.0, 95.0, 0.0);
	glEnd ( );
	
	glPolygonMode (GL_FRONT, GL_FILL);
	glPolygonMode (GL_BACK, GL_LINE); // Wire-frame back face.
	glBegin (GL_QUADS);
	
	glVertex3f (50.0, 50.0, 0.0);
	glVertex3f (95.0, 50.0, 0.0);
	glVertex3f (95.0, 95.0, 0.0);
	glVertex3f (50.0, 95.0, 0.0);
	glEnd ( );
	
	glFlush ( );
}
void reshapeFcn (GLint newWidth, GLint newHeight)
{
	glViewport (0, 0, newWidth, newHeight);
	winWidth = newWidth;
	winHeight = newHeight;
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition (50, 50);
	glutInitWindowSize (winWidth, winHeight);
	glutCreateWindow ("Perspective View of A Square");
	init ( );
	glutDisplayFunc (displayFcn);
	glutReshapeFunc (reshapeFcn);
	glutMainLoop ( );
	return EXIT_SUCCESS; 
}
