#include<windows.h>
#include<GL/glut.h>
#include<math.h>

float rotar_y = 0.0,rotar_x = 0.0;

void inicio()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
    glClearColor(1.0, 0.56, 0.56,0.0);
}

void rotar(int key,int x,int y)
{
    if(key==GLUT_KEY_RIGHT)
    {
        rotar_y+=10;
    }
    else
    {
        if(key==GLUT_KEY_LEFT)
        {
            rotar_y-=5;
        }
        else
        {
            if(key==GLUT_KEY_UP)
            {
                rotar_x+=10;
            }
            else
            {
                if(key==GLUT_KEY_DOWN)
                {
                    rotar_x-=5;
                }
            }
        }
    }
    glutPostRedisplay();
}
void pantalla()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(rotar_x,1.0,0.0,0.0);
    glRotatef(rotar_y,0.0,1.0,0.0);
    
    glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.5, 0.5, -0.5);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.5, 0.5, -0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.5, -0.5, 0.5);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.5, 0.5, 0.5);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, 0.5, 0.5);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();
	
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, -0.5, -0.5);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.5, 0.5, -0.5);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, 0.5, 0.5);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.5, 0.5, 0.5);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5, 0.5, -0.5);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.5, 0.5, 0.5);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.5, 0.5, -0.5);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-0.5, 0.5, -0.5);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.5, -0.5, 0.5);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-0.5, -0.5, -0.5);

	
	glEnd();
    
    
    
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(0.5,0.5,0.0);
    glVertex3f(-0.5,0.5,0.0);
    glVertex3f(-0.5,-0.5,0.0);
    glVertex3f(-0.5,0.5,0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex3f(0.5,0.5,0.0);
    glVertex3f(-0.5,0.5,0.0);
    glVertex3f(0.0,0.0,0.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(0.5,0.5,0.0);
    glVertex3f(0.5,-0.5,0.0);
    glVertex3f(0.0,0.0,0.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex3f(-0.5,0.5,0.0);
    glVertex3f(-0.5,-0.5,0.0);
    glVertex3f(0.0,0.0,0.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.5,0.2);
    glVertex3f(-0.5,-0.5,0.0);
    glVertex3f(0.5,-0.5,0.0);
    glVertex3f(0.0,0.0,0.8);
    glEnd();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutCreateWindow("EXAMEN");
    inicio();
    glutDisplayFunc(pantalla);
    glutSpecialFunc(rotar);
    glutMainLoop();

    return EXIT_SUCCESS;
}
