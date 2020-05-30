#ifndef FOOD_H
#define FOOD_H

#include "point.h"
#include "snake.h"
class Food
{
public:
    Food() = default;
    Food(int wid, int hei) : width(wid), height(hei), pos(Point(1,1)){}
    Food(int x, int y, int wid, int hei) : pos(Point(x, y)), width(wid), height(hei) {}
    Food print(void) const;
    Food fresh(Snake snake);
    Point pos;

private:
    int width, height;
};

#endif