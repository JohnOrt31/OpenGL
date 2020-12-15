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
	glColor3f(1.0,1.0,1.0);//color de linea
	glBegin(GL_LINES);//Dibuja lineas
	glVertex2i(3,-2);//Inicio
	glVertex2i(-4,3); //Final
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);//color de linea
	glBegin(GL_LINES);//Dibuja lineas
	glVertex2f(-3.5,-2.5);//Inicio
	glVertex2f(4.5,3.5); //Final
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);//color de linea
	glBegin(GL_LINES);//Dibuja lineas
	glVertex3f(-4.5,-5.5,-2.5);//Inicio
	glVertex3f(4.5,3.5,2.5); //Final
	
	
	
	glEnd();
	glFlush();
}
