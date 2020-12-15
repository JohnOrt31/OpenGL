#include <windows.h>
#include <GL/glut.h>
#include <cmath>

float a = 6.15;
float b = 9.25;
float c = 9.25;
float aj = 8.15;
float bj = 8.15;
float xj = 1.0;
float yj = 1.0;
float yj2 = 1.0;

void Inicio() {
    glMatrixMode(GL_PROJECTION); //Uso de pantalla
    gluOrtho2D(-500, 500, -500, 500); // (x1, x2, y1, y2) x,y
    glClearColor(0.0, 0.0, 0.0, 0.0); //(R, G, B, A)
}

void Circulo(float x, float y, float radio) {
    float angulo = 0.0;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);

    
    for(angulo = 0.0; angulo <= 360.0; angulo += 6.0) {
        glVertex2f(x + sin(angulo) * radio, y + cos(angulo) * radio);
    }
    glEnd();
} // Circulo

void letraC(float x, float y, float radio) {
    float angulo = 0.0;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x,y);
	for(angulo=0.2; angulo<=80; angulo+=6){
		glVertex2f(x+sin(angulo)*radio, y+cos(angulo)*radio);
	}
	glEnd();
} 

void letraJ1(float x, float y, float radio){
	float angulo = 0.0;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x,y);
	for(angulo=4.5; angulo<=75; angulo+=6){
		glVertex2f(x+sin(angulo)*radio, y+cos(angulo)*radio);
	}
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.3, 11.0, 0.0);
	glVertex3f(-50,400,0);
	
	glColor3f(0.3, 11.0, 0.0);
	glVertex3f(-30,400,0);
	
	glColor3f(0.3, 11.0, 0.0);
	glVertex3f(-30,300,0);
	
	glColor3f(0.3, 11.0, 0.0);
	glVertex3f(-50,300,0);
	glEnd();
}

void letraJ2(float x, float y, float radio){
	float angulo = 0.0;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x,y);
	for(angulo=4.5; angulo<=75; angulo+=6){
		glVertex2f(x+sin(angulo)*radio, y+cos(angulo)*radio);
	}
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.1, 0.8);
	glVertex3f(-250,400,0);
	
	glColor3f(0.3, 0.1, 0.8);
	glVertex3f(-230,400,0);
	
	glColor3f(0.3, 0.1, 0.8);
	glVertex3f(-230,300,0);
	
	glColor3f(0.3, 0.1, 0.8);
	glVertex3f(-250,300,0);
	glEnd();
}

void dibujo() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Letra J (Jonathan) ----------------------------------
    glColor3f(0.3, 0.1, 0.8);
	letraJ2(-300, 300, 70);
	glColor3f(0.0,0.0,0.0);

	letraJ2(-300, 300, 50);
	
	glColor3f(0.3, 0.1, 0.8);
	Circulo(-357, 282, 10);
	
	glColor3f(120.0, 0.0, 50.0);
	
	if(yj >= 1.0 && yj < 100.0)
	{
		glColor3f(120.0, 0.0, 50.0);
		Circulo(-240.0, 390.0-yj, 10.0);
		yj = yj + 0.1;	
	}
	else if(yj >= 100.0 && aj < 10.8 )
	{
	
		glColor3f(120.0, 0.0, 50.0);
		Circulo(-300-sin(aj)*-60, 300+cos(aj)*60, 10);
		aj=aj+0.001;
		
			
	}
	else if( aj >= 10.8 && bj < 10.8)
	{
		
		glColor3f(120.0, 0.0, 50.0);
		Circulo(-300+sin(bj)*-60, 300+cos(bj)*60, 10);
		bj=bj+0.001;
	}
	else if( bj >= 10.8 && yj2 < 95.0)
	{
		glColor3f(120.0, 0.0, 50.0);
		Circulo(-240.0, 300.0+yj2, 10.0);
		yj2 = yj2 + 0.1;			
	}
	else
	{
		aj = 8.15;
		bj = 8.15;
		yj = 1.0;
		yj2 = 1.0;
		
	}

	//Letra J (Joel) ----------------------------------
    glColor3f(0.3, 11.0, 0.0);
	//circulo(300, 300, 70);
	letraJ1(-100, 300, 70);
	glColor3f(0.0,0.0,0.0);
	//circulo(300, 300, 50);
	letraJ1(-100, 300, 50);
	glColor3f(0.3, 11.0, 0.0);
	Circulo(-156, 282, 10);
	
	glColor3f(120.0, 0.0, 50.0);
	
	
	
	if(yj >= 1.0 && yj < 100.0)
	{
		glColor3f(0.78, 0.45, 0.26);
		Circulo(-40.0, 390.0-yj, 10.0);
		yj = yj + 0.1;	
	}
	
	else if(yj >= 100.0 && aj < 10.8 )
	{
	
		glColor3f(0.78, 0.45, 0.26);
		Circulo(-100-sin(aj)*-60, 300+cos(aj)*60, 10);
		aj=aj+0.001;
		
			
	}
	
	else if( aj >= 10.8 && bj < 10.8)
	{
		
		glColor3f(0.78, 0.45, 0.26);
		Circulo(-100+sin(bj)*-60, 300+cos(bj)*60, 10);
		bj=bj+0.001;
	}
	else if( bj >= 10.8 && yj2 < 95.0)
	{
		glColor3f(0.78, 0.45, 0.26);
		Circulo(-40.0, 300.0+yj2, 10.0);
		yj2 = yj2 + 0.1;			
	}
	else
	{
		aj = 8.15;
		bj = 8.15;
		yj = 1.0;
		yj2 = 1.0;
		
	}
	
    //Letra C ---------------------------------
    glColor3f(1.0, 0.0, 0.0);
    letraC(100, 300, 70); 
    glColor3f(0.0, 0.0, 0.0);
    Circulo(100, 300, 50);
   	
   	
   	glColor3f(1.0, 0.0, 0.0);
	Circulo(111, 359, 10);
	Circulo(115, 242, 10);
   	
   	
   	glColor3f(0.13, 0.54, 0.10);
	if ( b >= 9.25 && b <= 12.82) {
        Circulo(100+sin(b)*60, 300-cos(b)*60, 10);
        b = b + 0.001;
	}
		    
	else {
        Circulo(100+sin(c)*60, 300-cos(c)*(-60), 10);
        c = c + 0.001;
    
        if (c > 12.82)
        {
            b = 9.25;
            c = 9.25;
        }
 	}	
    
    //Letra O--------------------------------------
    glColor3f(0.91, 0.53, 0.60);
    Circulo(300, 300, 70);
    
    //glColor3f(0.0, 1.0, 0.9);
    
    glColor3f(0.0, 0.0, 0.0);
    Circulo(300, 300, 50);
    
    
   glColor3f(0.64, 0.007, 0.78); 
    
	if ( a >= 6.15 && a <= 12.4) {
        Circulo(300+sin(a)*60, 300-cos(a)*60, 10);
        a = a + 0.001;
	}
		    
	else {
        Circulo(300+sin(a)*60, 300-cos(a)*60, 10);
        a = a + 0.001;
    
        if (a > 12.4)
        {
            a = 6.15;
            
        }
	}
    
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
