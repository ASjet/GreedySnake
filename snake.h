#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "point.h"
class Snake
{
public:
    enum Direction
    {
        UP = 1,
        DOWN = 2,
        LEFT = 3,
        RIGHT = 4
    };
    Snake() = default;
    Snake(int len, int x, int y, int wid, int hei) : length(len), face(LEFT), head_x(x), head_y(y), width(wid), height(hei), alive(true)
    {
        if (len < 2)
            length = 2;
        if (len >= 8)
            length = 8;
    }
    Snake initialize(void);
    Snake printBody(void) const;
    Snake turn(char ch);
    Snake move(void);
    Snake eat(void);
    bool inBody(Point pos, int head_distance) const;
    bool hitWall(void) const;
    bool hitBody(void) const;
    bool meetFood(Point food_pos) const;
    bool alive;

private:
    int length, head_x, head_y;
    int width, height;
    Direction face;
    std::deque<Point> body;
};

#endif