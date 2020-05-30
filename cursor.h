#ifndef CURSOR_H
#define CURSOR_H

#include <initializer_list>
#include "option.h"
void SetCursorPosition(const int x, const int y);
void SetColor(int colorID);
void SetBackColor(void);
void PrintStr(const char* str, const int x, const int y, const int colorID);
void PrintStr(const char* str, Point pos, const int colorID);
void PrintStr(std::string str, Point pos, const int colorID = 3);
int Selector(std::initializer_list<Option> opt);

#endif