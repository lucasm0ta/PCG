#include "Cube.h"

Cube::Cube(GLfloat size, Vec3 pos) : Object(), size(size){
    glEnable(GL_DEPTH_TEST);
    obj = gluNewQuadric();
    // glEnable(GL_TEXTURE_2D);
}

void Cube::Render() {
    
    glPushMatrix();

    // glClearColor(0.5, 0.5, 1.0, 1);
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // std::cout << "angle:"<< angle <<'\n';
    glRotatef(angle, rot.X(), rot.Y(), rot.Z());
    glScalef(scale.X(), scale.Y(), scale.Z());
    glTranslatef(pos.X(), pos.Y(), pos.Z());
    glutWireCube(size);


    glColor3f(0.0, 1.0, 0.0);
    // gluQuadricDrawStyle(obj, GLU_FILL);
    // glBindTexture(GL_TEXTURE_2D, tex);
    // gluQuadricTexture(obj, GL_TRUE);
    // gluQuadricNormals(obj, GLU_SMOOTH);
    // gluSphere(obj, 1.0, 32, 16);

    glPopMatrix();

 
    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();
    // glTranslatef(0.0, 0.0,-2.0);
    // glRotatef(45, 0, 1, 0);
 
    // glColor3f(0.0,1.0,0.0);
    // gluQuadricDrawStyle(obj, GLU_FILL);
    // glBindTexture(GL_TEXTURE_2D, tex);
    // gluQuadricTexture(obj, GL_TRUE);
    // gluQuadricNormals(obj, GLU_SMOOTH);
    // gluSphere(obj, 1.0, 32, 16);
 
    // glutSwapBuffers();
}