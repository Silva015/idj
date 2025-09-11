#ifndef RECT_H
#define RECT_H
#include "Vec2.h"

class Rect {
public:
    float x, y, w, h;
    explicit Rect(float x = 0, float y = 0, float w = 0, float h = 0) : x(x), y(y), w(w), h(h) {}
    Rect& operator=(const Rect& other);
    Rect operator+ (const Vec2& other) const;
    Rect& operator+= (const Vec2& other);
    Rect operator- (const Vec2& other) const;
    Rect& operator-= (const Vec2& other);
    Vec2 Center() const;
    float DistanceToOtherRectCenter(const Rect& other) const;
    bool Contains(const Vec2& other) const;
};

#endif