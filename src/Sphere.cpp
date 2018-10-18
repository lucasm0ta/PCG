#include "Sphere.h"

Sphere::Sphere(GLfloat radius, Vec3 pos) : Object(), radius(radius) {
    glEnable(GL_DEPTH_TEST);
    make_tex(tex);
    obj = gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
}

void Sphere::make_tex(GLuint &tex)
{
    unsigned char data[256][256][3];
    for (int y = 0; y < 255; y++) {
        for (int x = 0; x < 255; x++) {
            unsigned char *p = data[y][x];
            p[0] = p[1] = p[2] = (x ^ y) & 8 ? 255 : 0;
        }
    }
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, (const GLvoid *) data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Sphere::Render() {
    
    glPushMatrix();

    // glClearColor(0.5, 0.5, 1.0, 1);
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glRotatef(angle, rot.X(), rot.Y(), rot.Z());
    glScalef(scale.X(), scale.Y(), scale.Z());
    glTranslatef(pos.X(), pos.Y(), pos.Z());
    glutSolidSphere(radius, 50, 50);


    glColor3f(0.0, 1.0, 0.0);
    gluQuadricDrawStyle(obj, GLU_FILL);
    glBindTexture(GL_TEXTURE_2D, tex);
    gluQuadricTexture(obj, GL_TRUE);
    gluQuadricNormals(obj, GLU_SMOOTH);
    gluSphere(obj, 1.0, 32, 16);

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