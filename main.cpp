#include <math.h>
#include <GL/glut.h>
#include <iostream>
#include <string>

#include "h.h"

void initValues(t_badprog *bp)
{
    bp->screenPositionX = 100;
    bp->screenPositionY = 100;

    bp->bgRed            = 0;
    bp->bgGreen        = 0;
    bp->bgBlue            = 0;
    bp->bgAlpha        = 0;

    bp->drawRed        = 0;
    bp->drawGreen        = 1;
    bp->drawBlue        = 0;

    bp->side            = 3;
    bp->hyp            = bp->side;
    bp->sideHalf        = bp->hyp / 2;

    bp->sideToFind        = pow(bp->hyp, 2) - pow(bp->sideHalf, 2);
    bp->sideToFind        = sqrt(bp->sideToFind);
    bp->ratio            = pow(bp->sideHalf, 2) / 2;

    bp->z                = -8;

    bp->x1                = -1.5;
    bp->x2                = 0;
    bp->x3                = 1.5;

    bp->y1                = 0 - bp->ratio;
    bp->y2                = bp->sideToFind - bp->ratio;
    bp->y3                = 0 - bp->ratio;
}

void initProgram(t_badprog *bp)
{
    initValues(bp);
    glClearColor(bp->bgRed, bp->bgGreen, bp->bgBlue, bp->bgAlpha);
    glColor3f(bp->drawRed, bp->drawGreen, bp->drawBlue);
}

void managerDisplay(void)
{
    t_badprog bp;
    float var = 5;
    float newAngle = 0;
    int i = 0;

    initProgram(&bp);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -30.0f);

    while (i < 90)
    {
        // Green X
            glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.0f);
                glRotatef(newAngle += i, 1.0f, 0.0f, 0.0f);
                glColor3f(0, 1, 0);
                glBegin(GL_TRIANGLES);
                    glVertex3f(bp.x1, bp.y1, bp.z);
                    glVertex3f(bp.x2, bp.y2, bp.z);
                    glVertex3f(bp.x3, bp.y3, bp.z);
                glEnd();
            glPopMatrix();

            // Blue Y
            newAngle -= i;
            glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.0f);
                glRotatef(newAngle += i, 0.0f, 1.0f, 0.0f);
                glColor3f(0, 0, 1);
                glBegin(GL_TRIANGLES);
                    glVertex3f(bp.x1, bp.y1, bp.z);
                    glVertex3f(bp.x2, bp.y2, bp.z);
                    glVertex3f(bp.x3, bp.y3, bp.z);
                glEnd();
            glPopMatrix();

            // Red Z
            newAngle -= i;
            glPushMatrix();
                glTranslatef(0.0f, 0.0f, 0.0f);
                glRotatef(newAngle += i, 0.0f, 0.0f, 1.0f);
                glColor3f(1, 0, 0);
                glBegin(GL_TRIANGLES);
                    glVertex3f(bp.x1 + var, bp.y1, bp.z);
                    glVertex3f(bp.x2 + var, bp.y2, bp.z);
                    glVertex3f(bp.x3 + var, bp.y3, bp.z);
                glEnd();
            glPopMatrix();
        ++i;
    }
    glutSwapBuffers();
}

void managerKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
        {
            exit(0);
        }
    }
    (void)(x);
    (void)(y);
}

void managerResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void init(int ac, char *av[])
{
  glutInit(&ac, av);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
  glutInitWindowPosition(SCREEN_POSITION_X, SCREEN_POSITION_Y);

  glutCreateWindow(SCREEN_TITLE);

  glEnable(GL_DEPTH_TEST);

  glutDisplayFunc(managerDisplay);
  glutKeyboardFunc(managerKeyboard);
  glutReshapeFunc(managerResize);

  glutMainLoop();
}

int  main(int ac, char *av[])
{
  init(ac, av);
  return 0;
}
