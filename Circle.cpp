#include <windows.h>
#include <GL/glut.h>
#include <cmath>

void Inicio();
void cuadrado();
void circulo();
void dibujo();

int x = 1;
int y = 1;
int z = 1;
int w = 1;


int main(int argc, char**argv)
{
	glutInit(&argc,argv); //Inicia Opengl
	glutInitWindowSize(650,650); // Ancho,largo pantalla
	glutInitWindowPosition(10,10); // Posicion de la ventana creada
	glutInitDisplayMode(GLUT_RGB |GLUT_DEPTH); // Atributos de pantalla
	glutCreateWindow("Dibujando circulo");
	Inicio();
	glutDisplayFunc(dibujo);//Para limpiar y refrescar la pantalla
	glutIdleFunc(dibujo);
	glutMainLoop();
	
	return EXIT_SUCCESS;
}//Main

void Inicio()
{
	glMatrixMode(GL_PROJECTION); //Uso de pantalla
	gluOrtho2D(-1000,1000,-1000,1000);//(x1,x2,y1,y2)
	glClearColor(0,0,0,0); //(R,G,B,A)
}

void circulo(int x, int y, int radio)
{
	float angulo = 1;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(x,y);
	glColor3f(1.1, 1.1, 1.1);
	
	for(angulo = 0;angulo<=360;angulo+=5)
	{
		glVertex2f(x+sin(angulo)*radio,y+cos(angulo)*radio);
	}
	glEnd();
}

void dibujo()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	/*
	if(x >= 1 && x<800)
	{
		circulo(10+x,100,80);
		x++;
		
	}
	
	if(x==800 && y>=1 && y < 800)
	{
		circulo(850,100+y,80);
		y++;
	}
	
	if(y==800 && z>=1 && z<800)
	{
		circulo(850-z,900,80);
		z++;
	}
	
	if(z==800 && w>=1 && w < 800)
	{
		circulo(50,900-w,80);
		w++;
		if(w == 800)
		{
			x = 1;
			y = 1;
			z = 1;
			w = 1;
		}
	}*/
	
	
	if(x >= 1 && x<800)
	{
		circulo(10-x,100,80);
		x++;
		
	}
	
	if(x==800 && y>=1 && y < 800)
	{
		circulo(-850,100+y,80);
		y++;
	}
	
	if(y==800 && z>=1 && z<800)
	{
		circulo(-850+z,900,80);
		z++;
	}
	
	if(z==800 && w>=1 && w < 800)
	{
		circulo(-50,900-w,80);
		w++;
		if(w == 800)
		{
			x = 1;
			y = 1;
			z = 1;
			w = 1;
		}
	}
	
	
	
	
	
	glFlush();

}
