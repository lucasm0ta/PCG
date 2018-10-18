#ifndef CUBE_H
#define CUBE_H

#include "Object.h"

class Cube : public Object {
public:
    Cube(GLfloat size, Vec3 pos);

    void Render() override;

    GLfloat size;
};

#endif /* CUBE_H */