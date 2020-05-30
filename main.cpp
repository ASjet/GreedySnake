/*
* Greedy Snake
* Fri May 29 23:32:37 CST 2020
* @Version 1.1
* @Environment Win10/VSC/VS2019(v142)
* @Auther Aryan Sun
* @Email Aryan.ITFS@iCloud.com
* @License MIT License
* @Copyright © 2020, Aryan Sun
*/
#include <iostream>
#include "game.h"
////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    std::ios::sync_with_stdio(false);
    Game game;
    game.initialize();
    game.menu();
    return 0;
}