#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void Inicio();
void cuadrado();

void pantalla();

float Px1 = 10, Py1 = 0, radio1 = 30;
float Px2 = 0, Py2 = 0, radio2 = 15;
float Px3 = 0, Py3 = 0, radio3 = 20;
float calx1 = 0, caly1 = 0;
float calx2 = 0, caly2 = 0;
float calx3 = 0, caly3 = 0;

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
	gluOrtho2D(-150,150,-150,150);//(x1,x2,y1,y2)
	glClearColor(0,0,0,0); //(R,G,B,A)
}


void pantalla()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-90.0, 80.0);
	glVertex2f(-40.0, 80.0);
	glVertex2f(-40.0, 70.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-60.0, 70.0);
	glVertex2f(-60.0, 30.0);
	glVertex2f(-80.0, 10.0);
	glVertex2f(-90.0, 10.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-90.0, 20.0);
	glVertex2f(-80.0, 20.0);
	glVertex2f(-70.0, 30.0);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(-70.0, 70.0);
	glVertex2f(-90.0, 70.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-90.0, 70.0);
	glVertex2f(-70.0, 70.0);
	glVertex2f(-70.0, 30.0);
	glVertex2f(-80.0, 20.0);
	glVertex2f(-90.0, 20.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-30.0, 80.0);
	glVertex2f(20.0, 80.0);
	glVertex2f(20.0, 70.0);
	glVertex2f(0.0, 70.0);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0.0, 30.0);
	glVertex2f(-20.0, 10.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-30.0, 10.0);
	glVertex2f(-30.0, 20.0);
	glVertex2f(-20.0, 20.0);
	glVertex2f(-10.0, 30.0);
	glVertex2f(-10.0, 70.0);
	glVertex2f(-30.0, 70.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-30.0, 70.0);
	glVertex2f(-10.0, 70.0);
	glVertex2f(-10.0, 30.0);
	glVertex2f(-20.0, 20.0);
	glVertex2f(-30.0, 20.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(30.0, 80.0);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(70.0, 80.0);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(70.0, 70.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(40.0, 70.0);
	
	glVertex2f(40.0, 20.0);
	glVertex2f(70.0, 20.0);
	glVertex2f(70.0, 10.0);
	
	glVertex2f(30.0, 10.0);
	
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(70.0, 70.0);
	glVertex2f(40.0, 70.0);
	glVertex2f(40.0, 20.0);
	glVertex2f(70.0, 20.0);
	

	glEnd();
	
	
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POINTS);
	
	for(double i=-100; i<100; i+=0.001)
	{
		calx1 = radio1*cos(i)+90;
		caly1 = radio1*sin(i)+50;
		glVertex2f(calx1,caly1);
	}
	glEnd();
	glFlush();
}
