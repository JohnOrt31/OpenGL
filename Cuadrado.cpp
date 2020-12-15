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
	gluOrtho2D(-20,20,-20,20);//(x1,x2,y1,y2)
	glClearColor(0,0,0,0); //(R,G,B,A)
}
void cuadrado(float x, float y, float tan, float R, float G, float B)
{
	tan /= 2;
	glColor3f(R,G,B);
	glBegin(GL_QUADS);
	glVertex2f(x+tan, y+tan);
	glVertex2f(x-tan, y+tan);
	glVertex2f(x-tan, y-tan);
	glVertex2f(x+tan, y-tan);
	glEnd();
	glFlush();
}

void pantalla()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(0.45,0.23,0.79);
	 /*
	glBegin(GL_QUADS);
	cuadrado(0, 0, 5, 1.0, 1.0, 1.0);
	cuadrado(-6, 3, 3, 0.79, 0.68, 0.12);
	*/
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.0, 4.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(4.0, 7.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(8.0, 4.0);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(6.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(2.0, 0.0);
	glEnd();
	
	glBegin(GL_TRIANGLES);	
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-8.0, -4.0);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-2.0, -4.0);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-5.0, -6.0);
	glEnd();
	
	
	glBegin(GL_TRIANGLES);	
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-5.0, -2.0);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-7.0, -7.0);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-4.0, -5.5);
	glEnd();
	
	glBegin(GL_TRIANGLES);	
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-5.0, -2.0);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-6.4, -5.5);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-3.0, -7.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-6.0, 2.0);
	
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-4.0, 2.0);
	
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-3.0, 1.0);
	
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(-3.0, -1.0);
	
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-4.0, -2.0);
	
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-6.0, -2.0);
	
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-7.0, -1.0);
	
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-7.0, 1.0);
	glEnd();
	
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(4.0, -5.0);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(7.0, -5.0);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(7.0, -8.0);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(4.0, -8.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(4.0, -5.0);
	
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(5.0, -4.0);
	
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(8.0, -4.0);
	
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(7.0, -5.0);
	
	glEnd();
	
	
	glBegin(GL_POLYGON);
	
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(7.0, -5.0);
	
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(8.0, -4.0);
	
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(8.0, -7.0);
	
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(7.0, -8.0);
	
	
	
	
	
	glEnd();
	
	
	glFlush();
}


	
