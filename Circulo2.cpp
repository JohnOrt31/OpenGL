#include <windows.h>
#include <GL/glut.h>
#include <cmath>


int x = 1;
int y = 1;
int z = 1;
int w = 1;
float a = 6.15;
float b = 6.15;

void Inicio() {
    glMatrixMode(GL_PROJECTION); //Uso de pantalla
    gluOrtho2D(-0, 500, -0, 500); // (x1, x2, y1, y2) x,y
    glClearColor(0.0, 0.0, 0.0, 0.0); //(R, G, B, A)
}

void Circulo(float x, float y, float radio) {
    int angulo = 0;
    glBegin(GL_TRIANGLE_FAN);
    //glColor3f(0.0, 0.0, 0.0);
    glVertex2f(x, y);
    //glColor3f(1.1, 1.1, 1.1);
    //glColor3f(1.0, 1.0, 1.0);
    
    for(angulo = 0; angulo <= 360; angulo += 6) {
        glVertex2f(x + sin(angulo) * radio, y + cos(angulo) * radio);
    }
    glEnd();
} // Circulo



void dibujo() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.3, 11.0, 0.0);
    Circulo(300, 300, 70);
    Circulo(300, 180, 70);
    //glColor3f(0.0, 1.0, 0.9);
    
    glColor3f(0.0, 0.0, 0.0);
    Circulo(300, 300, 50);
    Circulo(300, 180, 50);
    
    glColor3f(120.0, 0.0, 50.0);
    Circulo(300, 300, 10);
    Circulo(300, 180, 10);
    
    if ( a >= 6.15 && a <= 12.4) {
        Circulo(300+sin(a)*60, 300-cos(a)*60, 10);
        a = a + 0.001;
    }
    
    else {
        Circulo(300+sin(b)*60, 180-cos(b)* (-60), 10);
        b = b + 0.001;
        
        if (b > 12.4)
        {
            a = 6.15;
            b = 6.15;
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
