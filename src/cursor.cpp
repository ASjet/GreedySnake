#include <windows.h>
#include <iostream>
#include <initializer_list>
#include <conio.h>
#include "option.h"
#include "cursor.h"
#include "point.h"
////////////////////////////////////////////////////////////////////////////////
void SetCursorPosition(const int x, const int y)
{
    COORD position;
    position.X = x * 2;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
////////////////////////////////////////////////////////////////////////////////
void SetColor(int colorID)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}
////////////////////////////////////////////////////////////////////////////////
void SetBackColor(void)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        FOREGROUND_BLUE |
        BACKGROUND_BLUE |
        BACKGROUND_GREEN |
        BACKGROUND_RED);
}
////////////////////////////////////////////////////////////////////////////////
void PrintStr(const char* str, const int x, const int y, const int colorID)
{
    if (!colorID)
        SetBackColor();
    SetCursorPosition(x, y);
    SetColor(colorID);
    std::cout << str;
}
void PrintStr(const char* str, Point pos, const int colorID)
{
    if (!colorID)
        SetBackColor();
    pos.setCursorHere();
    SetColor(colorID);
    std::cout << str;
}
void PrintStr(std::string str, Point pos, const int colorID)
{
    if (!colorID)
        SetBackColor();
    pos.setCursorHere();
    SetColor(colorID);
    std::cout << str;
}
////////////////////////////////////////////////////////////////////////////////
int Selector(std::initializer_list<Option> opt)
{
    int choice_cnt = opt.size(); // Number of options
    auto last = opt.begin(), next = opt.begin();
    auto back = opt.begin();
    for(int i = 1; i < choice_cnt; ++i)
        ++back;
    char ch = 0;       // Input from keyboard
    bool flag = false; // Flag of chosen

    for (auto i = opt.begin(); i != opt.end(); ++i)
        i->unchoose();

    do
    {
        switch (ch)
        {
        case 72: // UP
        case 75: //RIGHT
            (last != opt.begin()) ? next = last - 1 : next = back;
            break;
        case 80: // DOWN
        case 77: // LEFT
            (last != opt.begin() + choice_cnt - 1) ? next = last + 1 : next = opt.begin();
            break;
        case 13: // ENTER
            flag = true;
            break;
        default:
            break;
        }
        if (flag)
            break;
        last->unchoose();
        next->choose();
        last = next;
    } while (ch = _getch());

    for (auto i = opt.begin(); i != opt.end(); ++i)
        i->clear();

    return last - opt.begin();
}
