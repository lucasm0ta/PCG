#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"

class Sphere : public Object {
public:
    Sphere(GLfloat radius, Vec3 pos);

    void Render() override;
    
    void make_tex(GLuint &tex);

    GLfloat radius;
};

#endif /* SPHERE_H */