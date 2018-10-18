#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <vector>

#include "Sphere.h"
#include "Cube.h"

float theta = 0.1;
int win_id = 0;
std::vector<Object*> objArray;
GLfloat px = 0, py = 0, pz = 0;

void ortoProjection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.0f, 4.0f, -4.0f, 4.0f, -4.0f, 4.0f);
}
void perspectProjection() {
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);

    // glPushMatrix();
    glLoadIdentity();
    gluLookAt(px, py, pz, 0, 0, 0, 0, 0, 1);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100, 1, 0.001, 100);

    // glPopMatrix();
}

void createScene(void) {

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 1);
    // ortoProjection();
    perspectProjection();
    glColor3f(1, 0, 0);
    // glMatrixMode(GL_MODELVIEW);

    // glPushMatrix();
    // glutWireCube(0.5f);
    // glPopMatri();
    for (Object *obj: objArray) {
        obj->Render();
    }
    // glPopMatrix();
    // glFlush();
    // glutPostRedisplay();

    // theta += 0.1;
}
void keyboard_special_keypress(int  key, int x, int y) {
    switch (key) {
        case GLUT_KEY_RIGHT:
            std::cout<<"Para direita:" << py <<"\n";
            py += 0.05;
            break;
        case GLUT_KEY_LEFT:
            std::cout<<"Para esquerda:" << py <<"\n";
            py -= 0.05;
            break;
        case GLUT_KEY_UP:
            std::cout<<"Para cima:" << pz <<"\n";
            pz += 0.05;
            break;
        case GLUT_KEY_DOWN:
            std::cout<<"Para baixo:" << pz <<"\n";
            pz -= 0.05;
            break;

    }
}
void keyboard_keypress(unsigned char key, int x, int y )
{
    switch (key) {
        case 27: // Escape key
            std::cout<<"ESC\n";
            glutDestroyWindow (win_id);
            exit (0);
            break;
        case 'r':
            std::cout<<"Apertou R\n";
            break;
        case 'a':
            std::cout<<"Apertou A" << px << "\n";
            px += 0.05;
            break;
        case 'd':
            std::cout<<"Apertou D" << px << "\n";
            px -= 0.05;
            break;
    }
    glutPostRedisplay();
}
void rotating() {
    // glRotatef(0.01, 1, 0, 0);
    // for (Object *obj: objArray) {
    //     // obj->Rotate(0.01, {1, 0, 1});
    //     // obj->Translate({0.0001, 0, 0});
    // }
    glFlush();
    glutPostRedisplay();
}

void resize(int w, int h)
{
    // if (!h)
	//     h = 1;
    // glViewport(0, 0, w, h);
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // gluPerspective(90.0, 1.0 * w / h, 0.1, 100.0);
}

void init(void)
{
    // Sphere *sp = new Sphere(1, {0, 0, 0});
    // sp->Scale({5, 5, 5});
    // sp->Translate({0, 0, -3});
    // // static_cast<Object>(sp);
    // objArray.push_back(sp);

    Cube *cb = new Cube(0.5, {0, 0, 0});
    // cb->Scale({5, 5, 5});
    // cb->Translate({0, 0, -3});
    objArray.push_back(cb);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    win_id = glutCreateWindow("Janelinha");

    glutDisplayFunc(createScene);

    glutSpecialFunc(&keyboard_special_keypress);
    glutKeyboardFunc(&keyboard_keypress);
    glutIdleFunc(&rotating);
    // glutReshapeFunc(resize);

    init();

    glutMainLoop();
}