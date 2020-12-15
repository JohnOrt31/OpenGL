#include <windows.h>
#include <GL/glut.h>
#include <cmath>

double rotar_x = 0;
double rotar_y = 0;

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

void rotar(int key, int x, int y){

    if (key == GLUT_KEY_RIGHT){
        rotar_y += 10;
    }
    else if(key == GLUT_KEY_LEFT){
        rotar_y -= 5;
    }
    else if( key == GLUT_KEY_UP){
        rotar_x += 10;
    }
    else if(key == GLUT_KEY_DOWN){
        rotar_x -= 5;
    }
    glutPostRedisplay();
}


void dibujo() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(rotar_x, 1.0, 0.0, 0.0);
    glRotatef(rotar_y, 0.0, 1.0, 0.0);
    glScalef(1.0/3, 1.0/3, 1.0/3);
    glTranslatef(1.0, 0,0);

    glutWireDodecahedron();

    glBegin(GL_POLYGON);
    glColor3f(0.79,0.8,0); glVertex3f(0.5,-0.5,0);
    glColor3f(1,1,0); glVertex3f(0.5,0.5,0);
    glColor3f(0,1,0); glVertex3f(-0.5,0.5,0);
    glColor3f(1,0,1); glVertex3f(-0.5,-0.5,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,.4,0); glVertex3f(0.5,-0.5,0);
    glColor3f(0.79,0.8,0); glVertex3f(0,0,0.5);
    glColor3f(1.0,0,0.5); glVertex3f(-0.5,-0.5,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,0,1.0); glVertex3f(0.5,-0.5,0);
    glColor3f(0,0,1.0); glVertex3f(0,0,0.5);
    glColor3f(1.0,0,0.6); glVertex3f(0.5,0.5,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,1,0); glVertex3f(0.5,0.5,0);
    glColor3f(0,0.89,1.0); glVertex3f(0,0,0.5);
    glColor3f(1.0,0,0); glVertex3f(-0.5,0.5,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,1,0); glVertex3f(-0.5, 0.5, 0);
    glColor3f(0,0,1.0); glVertex3f(0, 0, 0.5);
    glColor3f(1.0,0,0); glVertex3f(-0.5,-0.5, 0);
    glEnd();

   
    

    glBegin(GL_POLYGON);
    glColor3f(0.79,0.8,0); 
    glColor3f(0,0,1.0);
    glColor3f(0.79,0.8,0);
    glEnd();

    // glBegin(GL_POLYGON);
    // glColor3f(1.0,1,0); glVertex3f(0.5, -0.5, -0.5);
    // glColor3f(0,0,1.0); glVertex3f(0.5, -0.5, 0.5);
    // glColor3f(1.0,1,0); glVertex3f(-0.5, -0.5, 0.5);
    // glColor3f(1,0,1.0); glVertex3f(-0.5, -0.5, -0.5);
    // glEnd();



    glFlush();
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    
    glutInit(&argc, argv); // Inicia OpenGL
    glutInitWindowSize(500, 500); //Ancho y largo pantalla
    glutInitWindowPosition(10, 10); // Posicion de la ventana creada
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH); // Atributos de pantalla
    glutCreateWindow("Dibujando lineas");
    Inicio();
    glutDisplayFunc(dibujo); // Mandar a llamar la pantalla para limpiar y refrescar la pantalla
    glutSpecialFunc(rotar);
    glutIdleFunc(dibujo);
    
    glutMainLoop();
    return EXIT_SUCCESS;
}
