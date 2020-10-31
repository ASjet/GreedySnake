#include <deque>
#include "point.h"
#include "snake.h"
////////////////////////////////////////////////////////////////////////////////
Snake Snake::initialize(void)
{
    face = LEFT;
    alive = true;
    for (int i = 0; i < length; ++i)
        body.push_back(Point(head_x + i, head_y));
    printBody();
    return *this;
}
////////////////////////////////////////////////////////////////////////////////
Snake Snake::printBody(void) const
{
    for (auto i = body.begin(); i != body.end(); ++i)
        i->print();
    return *this;
}
////////////////////////////////////////////////////////////////////////////////
Snake Snake::turn(char ch)
{
    switch (ch)
    {
    case 72: // UP
        if (face != DOWN)
            face = UP;
        break;
    case 80: // DOWN
        if (face != UP)
            face = DOWN;
        break;
    case 75: // LEFT
        if (face != RIGHT)
            face = LEFT;
        break;
    case 77: // RIGHT
        if (face != LEFT)
            face = RIGHT;
        break;
    default:
        break;
    }
    return *this;
}
////////////////////////////////////////////////////////////////////////////////
Snake Snake::move(void)
{
    switch (face)
    {
    case UP:
        --head_y;
        break;
    case DOWN:
        ++head_y;
        break;
    case LEFT:
        --head_x;
        break;
    case RIGHT:
        ++head_x;
        break;
    default:
        break;
    }
    
    if (hitWall() || hitBody())
    {
        alive = false;
        return *this;
    }

    // Insert new head
    body.push_front(Point(head_x, head_y).print());

    // clear tail
    while (body.size() > length)
    {
        body.back().clear();
        body.pop_back();
    }
    return *this;
}
////////////////////////////////////////////////////////////////////////////////
Snake Snake::eat(void)
{
    ++length;
    move();
    return *this;
}
////////////////////////////////////////////////////////////////////////////////
bool Snake::inBody(Point pos, int head_distance) const
{
    auto iter = body.begin();
    while (head_distance--)
        ++iter;
    while (iter != body.end())
    {
        if (*iter == pos)
            return true;
        else
            ++iter;
    }
    return false;
}
////////////////////////////////////////////////////////////////////////////////
bool Snake::hitWall(void) const
{
    if (head_x < 1 || head_y < 1 || head_x > width || head_y > height)
        return true;
    else
        return false;
}
////////////////////////////////////////////////////////////////////////////////
bool Snake::hitBody(void) const
{
    if (inBody(Point(head_x, head_y), 1))
        return true;
    else
        return false;
}
////////////////////////////////////////////////////////////////////////////////
bool Snake::meetFood(Point food_pos) const
{
    if (Point(head_x, head_y) == food_pos)
        return true;
    else
        return false;
}