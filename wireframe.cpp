#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h> 
 
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height; 
 
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0); 
 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
} 
 
static void display(void)
{ 
 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,1); 
    
    
 
    //Dodecahedron 
    glPushMatrix();
        glTranslated(-3.0, 1.5, -6.0);
        glScaled(0.5, 0.5, 0.5);
        glutWireDodecahedron();
    glPopMatrix(); 
    

    
    glPushMatrix();
        glTranslated(-1.0, -1.2, -6.0);
        glutWireTorus(0.2, 1.0, 5, 6);
    glPopMatrix();
 
    //Octahedron 
 
    glPushMatrix();
        glTranslated(-1.0, 1.5, -6.0);
        glutWireOctahedron();
    glPopMatrix(); 
 	
	 glPushMatrix();
        glTranslated(3.0, -1.2, -6.0);
        glutWireIcosahedron();
    glPopMatrix(); 
    //Tetrahedron 
 
    glPushMatrix();
        glTranslated(1.0, 1.5, -6.0);
        glutWireTetrahedron();
    glPopMatrix(); 
 
    //Icosahedrons

 
    glPushMatrix();
        glTranslated(3.0, 1.5, -6.0);
        glutWireIcosahedron();
    glPopMatrix(); 
    
    
 
    glutSwapBuffers();
} 
 
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f }; 
 
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f }; 
 
/* Program entry point */
 
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
 
    glutCreateWindow("Programming Techniques - 3D regular solids"); 
 
    glutReshapeFunc(resize);
    glutDisplayFunc(display); 
 
    glClearColor(1,1,1,1);
  

 
    glutMainLoop(); 
 
    return EXIT_SUCCESS;
}
