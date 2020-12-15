#include <windows.h>
#include <GL/glut.h>
#include <cmath>


float x = 1.0;

float y = 1.0;
float a = 6.15;
float b = 6.15;

void Inicio() {
    glMatrixMode(GL_PROJECTION); //Uso de pantalla
    gluOrtho2D(-120, 120, -120, 120); // (x1, x2, y1, y2) x,y
    glClearColor(0.0, 1.0, 0.0, 0.0); //(R, G, B, A)
    glClearColor(0.0, 1.0, 1.0, 0.0); //(R, G, B, A)
   
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




void dibujo() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
	glVertex2f(20+x,100-y);
	glVertex2f(50+x,100-y);
	glVertex2f(50+x,90-y);
	glVertex2f(20+x,90-y);
	x = x+0.001;
	y = y+0.001;
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(50+x,90-y);
    glVertex2f(40+x,90-y);
    glVertex2f(40+x,70-y);
	glVertex2f(50+x,70-y);
	x = x+0.001;
	y = y+0.001;
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(30+x,70-y);
    glVertex2f(40+x,70-y);
    glVertex2f(40+x,60-y);
	glVertex2f(30+x,60-y);
	y = y+0.001;
	x = x+0.001;
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(20+x,60-y);
    glVertex2f(30+x,60-y);
    glVertex2f(30+x,50-y);
	glVertex2f(20+x,50-y);
	y = y+0.001;
	x = x+0.001;
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(10+x,50-y);
    glVertex2f(20+x,50-y);
    glVertex2f(20+x,40-y);
	glVertex2f(10+x,40-y);
	y = y+0.001;
	x = x+0.001;
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(0+x,40-y);
    glVertex2f(10+x,40-y);
    glVertex2f(10+x,30-y);
	glVertex2f(0+x,30-y);
	y = y+0.001;
	x = x+0.001;
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-10+x,30-y);
    glVertex2f(0+x,30-y);
    glVertex2f(0+x,20-y);
	glVertex2f(-10+x,20-y);
	y = y+0.001;
	x = x+0.001;
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-20+x,20-y);
    glVertex2f(-10+x,20-y);
    glVertex2f(-10+x,10-y);
	glVertex2f(-20+x,10-y);
	y = y+0.001;
	x = x+0.001;
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-30+x,10-y);
    glVertex2f(-20+x,10-y);
    glVertex2f(-20+x,0-y);
	glVertex2f(-30+x,0-y);
	y = y+0.001;
	x = x+0.001;
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(10+x,90-y);
    glVertex2f(20+x,90-y);
    glVertex2f(20+x,80-y);
	glVertex2f(10+x,80-y);
	y = y+0.001;
	x = x+0.001;
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(0+x,80-y);
    glVertex2f(10+x,80-y);
    glVertex2f(10+x,70-y);
	glVertex2f(0+x,70-y);
	y = y+0.001;
	x = x+0.001;
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-10+x,70-y);
    glVertex2f(0+x,70-y);
    glVertex2f(0+x,60-y);
	glVertex2f(-10+x,60-y);
	y = y+0.001;
	x = x+0.001;
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-20+x,60-y);
    glVertex2f(-10+x,60-y);
    glVertex2f(-10+x,50-y);
	glVertex2f(-20+x,50-y);
	y = y+0.001;
	x = x+0.001;
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-30+x,50-y);
    glVertex2f(-20+x,50-y);
    glVertex2f(-20+x,40-y);
	glVertex2f(-30+x,40-y);
	y = y+0.001;
	x = x+0.001;
    glEnd();

	glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-40+x,40-y);
    glVertex2f(-30+x,40-y);
    glVertex2f(-30+x,30-y);
	glVertex2f(-40+x,30-y);
	y = y+0.001;
	x = x+0.001;
    glEnd();    
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-50+x,30-y);
    glVertex2f(-40+x,30-y);
    glVertex2f(-40+x,20-y);
	glVertex2f(-50+x,20-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-60+x,20-y);
    glVertex2f(-60+x,0-y);
    glVertex2f(-50+x,0-y);
	glVertex2f(-50+x,20-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-80+x,20-y);
    glVertex2f(-80+x,0-y);
    glVertex2f(-70+x,0-y);
	glVertex2f(-70+x,20-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-70+x,30-y);
    glVertex2f(-70+x,20-y);
    glVertex2f(-60+x,20-y);
	glVertex2f(-60+x,30-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-70+x,0-y);
    glVertex2f(-70+x,-10-y);
    glVertex2f(-60+x,-10-y);
	glVertex2f(-60+x,0-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-90+x,40-y);
    glVertex2f(-90+x,20-y);
    glVertex2f(-80+x,20-y);
	glVertex2f(-80+x,40-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-70+x,30-y);
    glVertex2f(-70+x,20-y);
    glVertex2f(-60+x,20-y);
	glVertex2f(-60+x,30-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-80+x,40-y);
    glVertex2f(-80+x,30-y);
    glVertex2f(-70+x,30-y);
	glVertex2f(-70+x,40-y);
	x = x+0.001;
	y = y+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-50+x,0-y);
    glVertex2f(-50+x,-10-y);
    glVertex2f(-30+x,-10-y);
	glVertex2f(-30+x, 0-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-60+x,-10-y);
    glVertex2f(-60+x,-20-y);
    glVertex2f(-50+x,-20-y);
	glVertex2f(-50+x,-10-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-50+x,-20-y);
    glVertex2f(-50+x,-30-y);
    glVertex2f(-30+x,-30-y);
	glVertex2f(-30+x, -20-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-30+x,-10-y);
    glVertex2f(-30+x,-20-y);
    glVertex2f(-20+x,-20-y);
	glVertex2f(-20+x, -10-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-20+x,-20-y);
    glVertex2f(-20+x,-30-y);
    glVertex2f(-10+x,-30-y);
	glVertex2f(-10+x, -20-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-30+x,-30-y);
    glVertex2f(-30+x,-40-y);
    glVertex2f(-10+x,-40-y);
	glVertex2f(-10+x, -30-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(-80+x,-10-y);
    glVertex2f(-80+x,-20-y);
    glVertex2f(-70+x,-20-y);
	glVertex2f(-70+x, -10-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(-90+x,-20-y);
    glVertex2f(-90+x,-30-y);
    glVertex2f(-80+x,-30-y);
	glVertex2f(-80+x,-20-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(-70+x,-20-y);
    glVertex2f(-70+x,-30-y);
    glVertex2f(-60+x,-30-y);
	glVertex2f(-60+x,-20-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(-80+x,-30-y);
    glVertex2f(-80+x,-40-y);
    glVertex2f(-70+x,-40-y);
	glVertex2f(-70+x, -30-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-110+x,-30-y);
    glVertex2f(-110+x,-40-y);
    glVertex2f(-90+x,-40-y);
	glVertex2f(-90+x, -30-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-110+x,-50-y);
    glVertex2f(-110+x,-60-y);
    glVertex2f(-90+x,-60-y);
	glVertex2f(-90+x, -50-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-110+x,-40-y);
    glVertex2f(-110+x,-50-y);
    glVertex2f(-100+x,-50-y);
	glVertex2f(-100+x, -40-y);
	y = y+0.001;
	x = x+0.001;
    glEnd(); 
    
    glBegin(GL_QUADS);
    glColor3f(0.0,0.70,0.37);
    glVertex2f(-100+x,-40-y);
    glVertex2f(-100+x,-50-y);
    glVertex2f(-90+x,-50-y);
	glVertex2f(-90+x, -40-y);
	y = y+0.001;
	x = x+0.001;
    glEnd();
	
	glBegin(GL_QUADS);
    glColor3f(0.0,0.45,0.37);
    glVertex2f(-90+x,-40-y);
    glVertex2f(-90+x,-50-y);
    glVertex2f(-80+x,-50-y);
	glVertex2f(-80+x, -40-y);
	y = y+0.001;
	x = x+0.001;
    glEnd();  
    
    glBegin(GL_QUADS);
    glColor3f(0.50,0.32,0.037);
    glVertex2f(-90+x,-30-y);
    glVertex2f(-90+x,-40-y);
    glVertex2f(-80+x,-40-y);
	glVertex2f(-80+x, -30-y);
	y = y+0.001;
	x = x+0.001;
    glEnd();  
    
    glBegin(GL_QUADS);
    glColor3f(0.50,0.32,0.037);
    glVertex2f(-80+x,-20-y);
    glVertex2f(-80+x,-30-y);
    glVertex2f(-70+x,-30-y);
	glVertex2f(-70+x, -20-y);
	x = x+0.001;
    glEnd(); 
    
	glBegin(GL_QUADS);
    glColor3f(0.50,0.32,0.037);
    glVertex2f(-70+x,-10-y);
    glVertex2f(-70+x,-20-y);
    glVertex2f(-60+x,-20-y);
	glVertex2f(-60+x, -10-y);
	x = x+0.001;
    glEnd();   
    
    
    if( x> 100 ){
    	x = 1.0;
    	y = 1.0;
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
