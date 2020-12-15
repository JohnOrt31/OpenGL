# include <windows.h>
#include <GL/glut.h>

void Inicio();
void pantalla();

int main(int argc, char**argv)
{
	glutInit(&argc,argv); //Inicia Opengl
	glutInitWindowSize(600,600); // Ancho,largo pantalla
	glutInitWindowPosition(500,500); // Posicion de la ventana creada
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Atributos de pantalla
	glutCreateWindow("Dibujando triangulo");
	Inicio();
	glutDisplayFunc(pantalla);//Para limpiar y refrescar la pantalla
	glutMainLoop();
	
	return EXIT_SUCCESS;
}//Main

void Inicio()
{
	glMatrixMode(GL_PROJECTION); //Uso de pantalla
	gluOrtho2D(-5,15,-5,15);//(x1,x2,y1,y2)
	glClearColor(0.0,0.0,0.0,0.0); //(R,G,B,A)
}

void pantalla()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	//color de linea
	/*
	glBegin(GL_LINES);//Dibuja lineas
	glVertex2f(1.5,2);
	glVertex2i(-1,1);
	glVertex2i(-1,1);
	glVertex2i(3,-1);
	glVertex2i(3,-1);
	glVertex2f(1.5,2);*/
	
	/*
	glBegin(GL_LINE_STRIP);
	glVertex2f(1.5,2);
	glVertex2i(-1,-1);
	glVertex2i(3,-1);
	glVertex2f(1.5,2);
	*/
	
	//glBegin(GL_LINE_LOOP);
	/*glVertex2f(1.5,2);
	glVertex2i(-1,-1);
	glVertex2i(3,-1);*/
	
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
	glVertex2i(3,7);
	glVertex2i(4,8);
	glVertex2i(6,8);
	glVertex2i(7,7);
	glVertex2i(7,5);
	glVertex2i(6,4);
	glVertex2i(4,4);
	glVertex2i(3,5);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,1.0);
	glVertex2i(5,7);
	glVertex2i(6,6);
	glVertex2i(5,5);
	glVertex2i(4,6);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,1.0,1.0);
	glVertex2i(4,4);
	glVertex2i(3,3);
	glVertex2i(7,3);
	glVertex2i(10,6);
	glVertex2i(10,7);
	glVertex2i(9,7);
	glVertex2i(7,5);
	glVertex2i(6,4);	
	glEnd();
	
	
	glBegin(GL_LINES);
	glColor3f(0.0,1.0,1.0);
	glVertex2i(9,7);
	glVertex2i(8,8);
	glVertex2i(10,7);
	glVertex2i(11,8);
		
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0.0,1.0,1.0);
	glVertex2f(9.2,6.2);
	glVertex2f(9.8,6.2);	
	glEnd();
	
	
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,1.0);
	glVertex2f(9.2,6.6);
	glVertex2f(9.4,6.6);
	glVertex2f(9.2,6.8);
	glVertex2f(9.4,6.8);	
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,1.0);
	glVertex2f(9.5,6.6);
	glVertex2f(9.7,6.6);
	glVertex2f(9.5,6.8);
	glVertex2f(9.7,6.8);	
	glEnd();
	
	
	

	
	glFlush();
}


