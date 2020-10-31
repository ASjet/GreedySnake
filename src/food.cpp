#include <cstdlib>
#include <ctime>
#include "point.h"
#include "food.h"
#include "snake.h"
////////////////////////////////////////////////////////////////////////////////
Food Food::print(void) const
{
    pos.print();
    return *this;
}
////////////////////////////////////////////////////////////////////////////////
Food Food::fresh(Snake snake)
{
    srand((unsigned)time(NULL));
    do
        pos.setPos((rand() % width) + 1, (rand() % height) + 1);
    while (snake.inBody(pos, 0));
    pos.print("■");
    return *this;
}