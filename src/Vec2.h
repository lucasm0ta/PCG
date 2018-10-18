#ifndef VEC2_H
#define VEC2_H

#include <GL/glut.h>
#include <iostream>
#include <initializer_list>

class Vec2 {
public:
    Vec2();
    Vec2(std::initializer_list<GLfloat> list);
    Vec2(GLfloat x, GLfloat y);
    void Rotate(GLfloat rad);
    Vec2 GetRotated(GLfloat rad) const;
    GLfloat Mag() const;
    GLfloat L0Mag() const;
    void SetMag(GLfloat mag);
    static GLfloat EuclidianDist(const Vec2 &a, const Vec2 &b);
    static GLfloat ManhattamDist(const Vec2 &a, const Vec2 &b);
    static GLfloat Angle(const Vec2 &a, const Vec2 &b);

    GLfloat GetX() const;
    GLfloat GetY() const;
    void Set(GLfloat x, GLfloat y);

    Vec2 operator+(const Vec2 &a) const;
    Vec2 operator+(const Vec2 &&a) const;
    Vec2 operator-(const Vec2 &a) const;
    Vec2 operator-(const Vec2 &&a) const;
    Vec2 operator-() const;
    Vec2 operator*(GLfloat f) const;
    Vec2 operator/(GLfloat f) const;

    Vec2& operator=(const Vec2 &a) = default;
    Vec2& operator+=(const Vec2 &a);
    Vec2& operator+=(const Vec2 &&a);
    Vec2& operator-=(const Vec2 &a);
    Vec2& operator-=(const Vec2 &&a);
    Vec2& operator*=(GLfloat f);
    bool operator==(const Vec2 &a);
    friend std::ostream& operator<<(std::ostream& os, const Vec2& a);

private:
    GLfloat x;
    GLfloat y;
};

#endif /* VEC2_H */
