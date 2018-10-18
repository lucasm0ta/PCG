#ifndef VEC3_H
#define VEC3_H

#include <GL/glut.h>
#include <iostream>
#include <initializer_list>

class Vec3 {
public:
    Vec3();
    Vec3(std::initializer_list<GLfloat> list);
    Vec3(GLfloat x, GLfloat y, GLfloat z);

    // void Rotate(GLfloat rad);
    // Vec3 GetRotated(GLfloat rad) const;
    // GLfloat Mag() const;
    // GLfloat L0Mag() const;
    // void SetMag(GLfloat mag);
    // static GLfloat EuclidianDist(const Vec3 &a, const Vec3 &b);
    // static GLfloat ManhattamDist(const Vec3 &a, const Vec3 &b);
    // static GLfloat Angle(const Vec3 &a, const Vec3 &b);

    GLfloat X() const;
    GLfloat Y() const;
    GLfloat Z() const;
    void Set(GLfloat x, GLfloat y, GLfloat z);

    Vec3 operator+(const Vec3 &a) const;
    Vec3 operator+(const Vec3 &&a) const;
    Vec3 operator-(const Vec3 &a) const;
    Vec3 operator-(const Vec3 &&a) const;
    Vec3 operator-() const;
    Vec3 operator*(GLfloat f) const;
    Vec3 operator/(GLfloat f) const;

    Vec3& operator=(const Vec3 &a) = default;
    Vec3& operator+=(const Vec3 &a);
    Vec3& operator+=(const Vec3 &&a);
    Vec3& operator-=(const Vec3 &a);
    Vec3& operator-=(const Vec3 &&a);
    Vec3& operator*=(const Vec3 &a);
    Vec3& operator*=(const Vec3 &&a);
    Vec3& operator*=(GLfloat f);
    bool operator==(const Vec3 &a);
    friend std::ostream& operator<<(std::ostream& os, const Vec3& a);

private:
    GLfloat x;
    GLfloat y;
    GLfloat z;
};

#endif /* VEC3_H */
