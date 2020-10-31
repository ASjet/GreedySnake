#ifndef POINT_H
#define POINT_H

#include <string>
using std::string;

class Point
{
public:
    Point() = default;
    Point(int px, int py) : x(px), y(py)
    {
        if (x < 1)
            x = 1;
        if (y < 1)
            y = 1;
    }
    friend bool
        operator==(const Point&, const Point&);
    friend bool
        operator!=(const Point&, const Point&);
    Point setPos(int px, const int py);
    Point print(string str = string("■")) const;
    Point clear(void) const;
    Point setCursorHere(void) const;
    Point move(int movement_x, int movement_y);

private:
    int x, y;
    // x ∈[1,40], y ∈[1,32]
};

inline bool
operator==(const Point& p1, const Point& p2)
{
    return p1.x == p2.x &&
        p1.y == p2.y;
}
inline bool
operator!=(const Point& p1, const Point& p2)
{
    return p1.x != p2.x ||
        p1.y != p2.y;
}

#endif