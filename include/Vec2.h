#ifndef VEC2_H
#define VEC2_H

class Vec2 {
public:
    float x, y;
    explicit Vec2(const float x = 0, const float y = 0) : x(x), y(y) {}
    Vec2& operator=(const Vec2& other);
    Vec2 operator+(const Vec2& other) const;
    Vec2& operator+=(const Vec2& other);
    Vec2 operator-(const Vec2& other) const;
    Vec2& operator-=(const Vec2& other);
    Vec2 operator*(float scalar) const;
    float Magnitude() const;
    Vec2 Normalized() const;
    float Distance(const Vec2& other) const;
    float Inclination() const;
    static float InclinationBetween(const Vec2& v1, const Vec2& v2) ;
    Vec2 Rotate(float angle) const;
};

#endif