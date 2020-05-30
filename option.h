#ifndef OPTION_H
#define OPTION_H

#include <string>
#include "point.h"

class Option
{
public:
    Option() = default;
    Option(std::string str, Point pos) :content(str), head_pos(pos) {}
    Option choose(void) const;
    Option unchoose(void) const;
    Option clear(void) const;
private:
    Point head_pos;
    std::string content;
    static constexpr int CHOSEN_CONTENT_COLOR_ID = 0;
    static constexpr int CHOSEN_BACK_COLOR_ID = 7;
    static constexpr int UNCHOSEN_CONTENT_COLOR_ID = 7;
    static constexpr int UNCHOSEN_BACK_COLOR_ID = 0;
};

#endif