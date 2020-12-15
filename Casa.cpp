#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void Inicio();
void pantalla();
float Px = 0, Py = 0, radio = 30;
float calx = 0, caly = 0;

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
	gluOrtho2D(-200,200,-200,200);//(x1,x2,y1,y2)
	glClearColor(0,0,0,0); //(R,G,B,A)
}

void pantalla()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.36,0.61,1);
	glBegin(GL_QUADS);
	glVertex2f(-200,200);
	glVertex2f(200,200);
	glVertex2f(200,0);
	glVertex2f(-200,0);	
	glEnd();
	
	glColor3f(0,0.92,0.24);
	glBegin(GL_QUADS);
	glVertex2f(-200,0);
	glVertex2f(200,0);
	glVertex2f(200,-200);
	glVertex2f(-200,-200);	
	glEnd();
	
	glColor3f(0.76,0.56,0.01);
	glBegin(GL_QUADS);
	glVertex2f(-120,30);
	glVertex2f(120,30);
	glVertex2f(120,-80);
	glVertex2f(-120,-80);	
	glEnd();
	
	glColor3f(0.76,0.56,0.01);
	glBegin(GL_QUADS);
	glVertex2f(-120,100);
	glVertex2f(-80,100);
	glVertex2f(-80,30);
	glVertex2f(-120,30);	
	glEnd();
	
	glColor3f(0.76,0.56,0.01);
	glBegin(GL_QUADS);
	glVertex2f(120,100);
	glVertex2f(80,100);
	glVertex2f(80,30);
	glVertex2f(120,30);	
	glEnd();
	
	glColor3f(0.50,0.007,0.96);
	glBegin(GL_TRIANGLES);
	glVertex2f(-130,100);
	glVertex2f(-70,100);
	glVertex2f(-100,130);	
	glEnd();
	
	glColor3f(0.50,0.007,0.96);
	glBegin(GL_TRIANGLES);
	glVertex2f(130,100);
	glVertex2f(70,100);
	glVertex2f(100,130);	
	glEnd();
	
	
	glColor3f(0.34,0.17,0.03);
	glBegin(GL_QUADS);
	glVertex2f(-20,-20);
	glVertex2f(20,-20);
	glVertex2f(20,-80);
	glVertex2f(-20,-80);	
	glEnd();
	
	glColor3f(-1.0,-1.0,-1.0);
	glBegin(GL_POINTS);
	
	for(double i=0; i<1000; i++)
	{
		calx = radio*cos(i)+150;
		caly = radio*sin(i)+150;
		glVertex2f(calx,caly);
	}
	glEnd();
	
	
	
	
	

	glFlush();
	
}
