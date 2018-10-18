#include "Object.h"
Object::Object(Vec3 pos, Vec3 scale, Vec3 rot) : pos(pos), scale(scale), rot(rot), angle(0) {
}

void Object::Translate(Vec3 tr) {
    pos += tr;
}

void Object::Scale(Vec3 sc) {
    scale *= sc;
}

void Object::Rotate(GLfloat ang, Vec3 r) {
    angle += ang;
    rot += r;
}
