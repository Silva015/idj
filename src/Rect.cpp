# include "Rect.h"
# include "Vec2.h"

Rect& Rect::operator=(const Rect& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        w = other.w;
        h = other.h;
    }
    return *this;
}

Rect Rect::operator+ (const Vec2& other) const {
    return Rect(x + other.x, y + other.y, w, h);
}

Rect &Rect::operator+=(const Vec2 &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Rect Rect::operator-(const Vec2 &other) const {
    return Rect(x - other.x, y - other.y, w, h);
}

Rect &Rect::operator-=(const Vec2 &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2 Rect::Center() const {
    return Vec2(x + w / 2, y + h / 2);
}

float Rect::DistanceToOtherRectCenter(const Rect& other) const {
    const Vec2 center1 = this->Center();
    const Vec2 center2 = other.Center();
    return center1.Distance(center2);
}

bool Rect::Contains(const Vec2& other) const {
    return (other.x >= x && other.x <= x + w && other.y >= y && other.y <= y + h);
}