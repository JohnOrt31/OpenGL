#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void Inicio();
void pantalla();

int main(int argc, char**argv)
{
	glutInit(&argc,argv); //Inicia Opengl
	glutInitWindowSize(600,600); // Ancho,largo pantalla
	glutInitWindowPosition(100,100); // Posicion de la ventana creada
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Atributos de pantalla
	glutCreateWindow("Dibujando circulo");
	Inicio();
	glutDisplayFunc(pantalla);//Para limpiar y refrescar la pantalla
	glutMainLoop();
	
	return EXIT_SUCCESS;
}//Main

void Inicio()
{
	glMatrixMode(GL_PROJECTION); //Uso de pantalla
	gluOrtho2D(-40,40,-40,40);//(x1,x2,y1,y2)
	glClearColor(-50,50,-50,50); //(R,G,B,A)
}

void pantalla()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.45,0.23,0.79);
	glBegin(GL_QUADS);
	glVertex2f(-40,-10);
	glVertex2f(40,-10);
	glVertex2f(40,-40);
	glVertex2f(-40,-40);	
	glEnd();
	
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_QUADS);
	glVertex2f(-40,-30);
	glVertex2f(40,-30);
	glVertex2f(40,-40);
	glVertex2f(-40,-40);	
	glEnd();
	glFlush();
}


