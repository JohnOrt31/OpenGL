#include <windows.h>
#include <GL/glut.h>
#include <cmath>


void Inicio() {
    glMatrixMode(GL_PROJECTION); //Uso de pantalla
    gluOrtho2D(-0, 500, -0, 500); // (x1, x2, y1, y2) x,y
    glClearColor(0.4, 0.4, 0.4, 0.0); //(R, G, B, A)
}

void dibujo() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_QUADS);
	glColor3f(0.94,0.77,0.06);
	glVertex2f(100, 150);
	glVertex2f(300, 150);
	glVertex2f(300, 350);
	glVertex2f(100, 350);
	
	glColor3f(0.94,0.60,0.06);
	glVertex2f(200, 100);
	glVertex2f(400, 100);
	glVertex2f(300, 150);
	glVertex2f(100, 150);
	
	glColor3f(0.94,0.60,0.06);
	glVertex2f(100, 150);
	glVertex2f(200, 100);
	glVertex2f(200, 300);
	glVertex2f(100, 350);
	
	glColor3f(0.94,0.60,0.06);
	glVertex2f(300, 150);
	glVertex2f(400, 100);
	glVertex2f(400, 300);
	glVertex2f(300, 350);
	
	glColor3f(0.94,0.60,0.06);
	glVertex2f(200, 300);
	glVertex2f(400, 300);
	glVertex2f(300, 350);
	glVertex2f(100, 350);
	
	glColor3f(0.94,0.77,0.06);
	glVertex2f(200, 100);
	glVertex2f(400, 100);
	glVertex2f(400, 300);
	glVertex2f(200, 300);
	
	glColor3f(0.0,0.0,0.0);
	glVertex2f(200, 260);
	glVertex2f(280, 260);
	glVertex2f(280, 240);
	glVertex2f(200, 240);
	
	glColor3f(0.0,0.0,0.0);
	glVertex2f(320, 260);
	glVertex2f(400, 260);
	glVertex2f(400, 240);
	glVertex2f(320, 240);
	
	glColor3f(0.0,0.0,0.0);
	glVertex2f(200, 240);
	glVertex2f(220, 240);
	glVertex2f(220, 180);
	glVertex2f(200, 180);
	
	
	glColor3f(0.0,0.0,0.0);
	glVertex2f(380, 240);
	glVertex2f(400, 240);
	glVertex2f(400, 180);
	glVertex2f(380, 180);

	
	
	glColor3f(1.0,1.0,1.0);
	glVertex2f(220, 240);
	glVertex2f(280, 240);
	glVertex2f(280, 180);
	glVertex2f(220, 180);
	
	glColor3f(1.0,1.0,1.0);
	glVertex2f(320, 240);
	glVertex2f(380, 240);
	glVertex2f(380, 180);
	glVertex2f(320, 180);
	
	glColor3f(0.94,0.60,0.06);
	glVertex2f(240, 220);
	glVertex2f(360, 220);
	glVertex2f(360, 160);
	glVertex2f(240, 160);
	
	glColor3f(0.94,0.60,0.06);
	glVertex2f(240, 160);
	glVertex2f(270, 160);
	glVertex2f(270, 140);
	glVertex2f(240, 140);
	
	glColor3f(0.94,0.60,0.06);
	glVertex2f(330, 160);
	glVertex2f(360, 160);
	glVertex2f(360, 140);
	glVertex2f(330, 140);
	
	glColor3f(0.0,0.0,0.0);
	glVertex2f(270, 200);
	glVertex2f(330, 200);
	glVertex2f(330, 180);
	glVertex2f(270, 180);
	
	glColor3f(1.0,1.0,1.0);
	glVertex2f(270, 180);
	glVertex2f(330, 180);
	glVertex2f(330, 160);
	glVertex2f(270, 160);
	
	
	glColor3f(0.96,0.58,0.81);
	glVertex2f(280, 160);
	glVertex2f(320, 160);
	glVertex2f(320, 140);
	glVertex2f(280, 140);
	
	
	glColor3f(0.94,0.60,0.06);
	glVertex2f(100, 150);
	glVertex2f(200, 100);
	glVertex2f(200, 300);
	glVertex2f(100, 350);
	
	
	glColor3f(0.0,0.0,0.0);
	glVertex2f(200, 300);
	glVertex2f(400, 300);
	glVertex2f(400, 360);
	glVertex2f(200, 360);
	
	glColor3f(0.0,0.0,0.0);
	glVertex2f(200, 360);
	glVertex2f(400, 360);
	glVertex2f(350, 380);
	glVertex2f(150, 380);
	
	glEnd();
    glFlush();
}

int main(int argc, char **argv) {
    
    glutInit(&argc, argv); // Inicia OpenGL
    glutInitWindowSize(500, 500); //Ancho y largo pantalla
    glutInitWindowPosition(10, 10); // Posicion de la ventana creada
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH); // Atributos de pantalla
    glutCreateWindow("Dibujando lineas");
    Inicio();
    glutDisplayFunc(dibujo); // Mandar a llamar la pantalla para limpiar y refrescar la pantalla
    glutIdleFunc(dibujo);
    
    glutMainLoop();
    return EXIT_SUCCESS;
}
