#include <windows.h>
#include <GL/glut.h>

void Inicio();
void pantalla();
 
int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(1080, 720); //Ancho, Largo pantalla
	glutInitWindowPosition(100,100); //Posición de la ventana creada
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //Atributos de pantalla
	glutCreateWindow("Hola");
	
	Inicio();
	glutDisplayFunc(pantalla); //Limpiar y refrescar la pantalla
	glutMainLoop();
	
	return EXIT_SUCCESS;
	
}

void Inicio()
{
	glMatrixMode(GL_PROJECTION); //Uso de pantalla
	gluOrtho2D(-6,6,-6,6);
	glClearColor(0.0,0.0,0.0,0.0);
}

void pantalla()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
