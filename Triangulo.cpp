#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void Inicio();
void cuadrado();

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
	gluOrtho2D(-100,100,-100,100);//(x1,x2,y1,y2)
	glClearColor(0,0,0,0); //(R,G,B,A)
}


void pantalla()
{
	glClear(GL_COLOR_BUFFER_BIT);
	/*
	glBegin(GL_TRIANGLES);
	glVertex3f(0,0,0);
	glVertex3f(50,0,0);
	glVertex3f(25,50,0);
	glVertex3f(25,50,0);
	glVertex3f(75,50,0);
	glVertex3f(50,100,0);*/
	
	/*
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0,0,0);
	glVertex3f(50,0,0);
	glVertex3f(25,50,0);
	
	glVertex3f(75,50,0);
	glVertex3f(50,100,0);
	*/
	
	glBegin(GL_TRIANGLE_FAN);
	
	
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(25,50,0);
	glVertex3f(0,0,0);
	glVertex3f(50,0,0);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(75,50,0);
	glColor3f(1.0, 1.0, 0.79);
	glVertex3f(50,100,0);
	glEnd();
	glFlush();
}


	
