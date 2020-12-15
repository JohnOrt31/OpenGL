#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void Inicio();
void pantalla();

float Px1 = 10, Py1 = 0, radio1 = 10;
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
	gluOrtho2D(-40,40,-40,40);//(x1,x2,y1,y2)
	glClearColor(-50,50,-50,50); //(R,G,B,A)
}

void pantalla()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(-1.0,-1.0,-1.0);
	glBegin(GL_POINTS);
	
	for(double i=-100; i<100; i+=0.001)
	{
		calx1 = radio1*cos(i);
		caly1 = radio1*sin(i);
		glVertex2f(calx1,caly1);
	}
	
	
	
	glEnd();
	glFlush();
}


