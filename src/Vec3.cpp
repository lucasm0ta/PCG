#include "Vec3.h"

#include <cmath>
Vec3::Vec3() : x(0), y(0), z(0){
}
Vec3::Vec3(std::initializer_list<GLfloat> initList) {
    if (initList.size() == 3) {
        x = initList.begin()[0];
        y = initList.begin()[1];
        z = initList.begin()[2];
    }
}

Vec3::Vec3 (GLfloat _x, GLfloat _y, GLfloat _z) : x(_x), y(_y), z(_z){
}

GLfloat Vec3::X() const {
    return x;
}

GLfloat Vec3::Y() const {
    return y;
}

GLfloat Vec3::Z() const {
    return z;
}

void Vec3::Set(GLfloat _x, GLfloat _y, GLfloat _z) {
    x = _x;
    y = _y;
    z = _z;
}

Vec3 Vec3::operator+(const Vec3 &a) const {
    return Vec3(a.x + x, a.y + y, a.z + z);
}

Vec3 Vec3::operator+(const Vec3 &&a) const {
    return Vec3(a.x + x, a.y + y, a.z + z);
}

Vec3 Vec3::operator-(const Vec3 &a) const {
    return Vec3(x - a.x, y - a.y, z - a.z);
}

Vec3 Vec3::operator-(const Vec3 &&a) const {
    return Vec3(x - a.x, y - a. y, z - a.z);
}

Vec3 Vec3::operator-() const {
    return Vec3(-x, -y, -z);
}

Vec3& Vec3::operator+=(const Vec3 &a) {
    x += a.x;
    y += a.y;
    z += a.z;
    return *this;
}

Vec3& Vec3::operator+=(const Vec3 &&a) {
    x += a.x;
    y += a.y;
    z += a.z;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3 &a) {
    x -= a.x;
    y -= a.y;
    z -= a.z;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3 &&a) {
    x -= a.x;
    y -= a.y;
    z -= a.z;
    return *this;
}

Vec3& Vec3::operator*=(const Vec3 &a) {
    x *= a.x;
    y *= a.y;
    z *= a.z;
    return *this;
}

Vec3& Vec3::operator*=(const Vec3 &&a) {
    x *= a.x;
    y *= a.y;
    z *= a.z;
    return *this;
}

Vec3& Vec3::operator*=(float f) {
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

bool Vec3::operator==(const Vec3 &a) {
    return (x == a.x && y == a.y && z == a.z);
}

Vec3  Vec3::operator*(float f) const {
    return Vec3(x * f, y * f, z * f);
}

Vec3  Vec3::operator/(float f) const {
    if (f != 0) {
        return Vec3(x / f, y / f, z / f);
    } else {
        return Vec3(x, y, z);
    }
}

std::ostream& operator<<(std::ostream& os, const Vec3& a) {
    os << '(' << a.x << ',' << a.y << ',' << a.z << ')';
    return os;
}
