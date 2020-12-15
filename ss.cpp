import time

start_time = time.time()

def display():

    t = time.time() - start_time
    year_period = 5.0                  # 5 seconds for simulating one year 
    year     = (t / year_period)
    day      = 365 * year
    moon_sid = (365 / 27.3) * year

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT )
    glEnable( GL_DEPTH_TEST )

    glColor4f (1.0, 1.0, 0, 1)
    glPushMatrix()
    glutSolidSphere(1.0, 20, 16)             # sun

    glRotatef(year*360.0, 0.0, 1.0, 0.0)     # earth rotation around the sun 
    glTranslatef(3.0, 0.0, 0.0)              # earth location

    glPushMatrix()                           # push earth system 

    glPushMatrix()
    glRotatef(day*360.0, 0.0, 1.0, 0.0)      # earth spinn
    glRotatef(90-23.4, 1.0, 0.0, 0.0)        # earth axis
    glColor3f (0, 0, 1)                      # blue
    glutWireSphere(0.3, 10, 8)               # earth
    glPopMatrix()

    glPushMatrix()
    glRotatef(moon_sid*360.0, 0.0, 1.0, 0.0) # moon sidereal
    glTranslatef(1.0, 0.0, 0.0)              # distance moon to earth
    glRotatef(90, 1.0, 0.0, 0.0)
    glColor4f (0.4, 0.5, 0.6, 1)                         
    glutWireSphere(0.1, 10, 8)               # moon
    glPopMatrix()

    glPopMatrix()                            # pop earth system 

    glPopMatrix()
    glutSwapBuffers()
