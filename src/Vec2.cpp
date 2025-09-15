#include "Vec2.h"
#include <cmath>

Vec2& Vec2::operator=(const Vec2& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Vec2 Vec2::operator+(const Vec2& other) const {
    return Vec2(x + other.x, y + other.y);
}

Vec2& Vec2::operator+=(const Vec2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vec2 Vec2::operator-(const Vec2& other) const {
    return Vec2(x - other.x, y - other.y);
}

Vec2& Vec2::operator-=(const Vec2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2 Vec2::operator*(const float scalar) const {
    return Vec2(x * scalar, y * scalar);
}

float Vec2::Magnitude() const {
    return sqrt(x * x + y * y);
}

Vec2 Vec2::Normalized() const {
    const float mag = Magnitude();
    if (mag == 0) return Vec2(0, 0);
    return Vec2(x / mag, y / mag);
}

float Vec2::Distance(const Vec2& other) const {
    return (*this - other).Magnitude();
}

float Vec2::Inclination() const {
    return atan2(y, x);
}

float Vec2::InclinationBetween(const Vec2& v1, const Vec2& v2) {
    const Vec2 diff = v2 - v1;
    return diff.Inclination();
}

Vec2 Vec2::Rotate(const float angle) const {
    const float cosA = cos(angle);
    const float sinA = sin(angle);
    return Vec2(x * cosA - y * sinA, x * sinA + y * cosA);
}