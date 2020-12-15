#include <windows.h>
#include <GL/glut.h>
#include <math.h>

GLsizei winWidth = 500 , winHeight = 500 ; //Tamañ o inicia l d e l a ventan a d e
//visualización .
void init(void)
{
	glClearColor(1.0 , 1.0 , 1.0 , 0.0); // Ventana de visualización en blanco
}

void displayWirePolyhedra(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // Borra la ventana de visualización .
	glColor3f(0.0 , 0.0 , 1.0); // Establece el color de las líneas en azul
	/* Establec e l a transformación d e visionado . */
	gluLookAt (5.0 , 5.0 , 5.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0);
	/* Cambia de escala un cubo y lo muestra como paralelepípedo alámbrico . */
	glScalef(1.5 , 2.0 , 1.0); 
	glutWireCube(1.0); 
	/* Cambia d e escala , traslada , y muestr a u n dodecaedr o alámbrico . */
	glScalef(0.8 , 0.5 , 0.8);
	glTranslatef(-6.0 , -5.0 , 0.0);
	glutWireDodecahedron() ;
	/* Traslada y muestra un tetraedro en modelo alámbrico . */
	glTranslatef(6.6, 6.6, 2.0);
	glutWireTetrahedron( ) ;
	/* TraBlada y visualiza un octaedro en modelo alámbrico . */
	glTranslatef (-3.0 , -1.0 , 0.0 );
	glutWireOctahedron( ); 
	/* Cambia de escala , traslada y muestra un icosaedro en modelo alámbrico . */
	glScalef (0.8 , 0.6 , 1.0) ;
	glTranslatef(4.3 , -2.0 , 0.5 ) ;
	glutWireIcosahedron();
	glFlush();
	
}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glViewport(0 , 0 , newWidth, newHeight) ;
	glMatrixMode(GL_PROJECTION);
	glFrustum(-1.0 , 1.0 , -1.0 , 1.0 , 2.0 , 20.0);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT); 
}
	

int main(int argc, char** argv)
{
		glutInit(&argc, argv);
		glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
		glutInitWindowPosition (100, 100) ;
		glutInitWindowSize (winWidth , winHeight);
		glutCreateWindow("Poliedros en modelo alámbrico");
		init( );
		glutDisplayFunc(displayWirePolyhedra) ;
		glutReshapeFunc(winReshapeFcn) ;
		glutMainLoop( );
		return EXIT_SUCCESS; 
}


