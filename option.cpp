#include <iostream>
#include <string>
#include "option.h"
#include "point.h"
#include "cursor.h"
////////////////////////////////////////////////////////////////////////////////
Option Option::choose(void) const
{
    head_pos.setCursorHere();
    SetBackColor();
    std::cout << content;
    return *this;
}
Option Option::unchoose(void) const
{
    head_pos.setCursorHere();
    SetColor(UNCHOSEN_CONTENT_COLOR_ID);
    std::cout << content;
    return *this;
}
Option Option::clear(void) const
{
    head_pos.setCursorHere();
    SetColor(UNCHOSEN_CONTENT_COLOR_ID);
    std::cout << std::string(content.size(), ' ');
    return *this;
}