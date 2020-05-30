#include <iostream>
#include <windows.h>
#include <cstdio>
#include <conio.h>
#include <string>
#include "game.h"
#include "point.h"
#include "cursor.h"
#include "option.h"
#include "snake.h"
#include "food.h"
////////////////////////////////////////////////////////////////////////////////
using std::cin;
using std::cout;
using std::endl;
using std::string;
////////////////////////////////////////////////////////////////////////////////
void Game::initialize(void)
{
    speed = 100;
    width = 40;
    height = 32;
    snake_length = 5;
    system("title GreedySnake");
    system("chcp 65001");
    system("cls");
    printFrame();
}
////////////////////////////////////////////////////////////////////////////////
void Game::printFrame(void) const
{
    SetColor(7);
    char cmd[30];
    sprintf(cmd, "mode con cols=%d lines=%d", 2 * width + 4, height + 2);
    system(cmd);
    string block("■");
    string board(block + block);
    string body(block + string(width * 2, ' ') + block);
    int i = width;
    while (i--)
        board += block;

    cout << board;

    i = height;
    while (i--)
        cout << body;

    cout << board;
}
////////////////////////////////////////////////////////////////////////////////
void Game::menu(void)
{
    while (true)
    {
        printFrame();
        switch (Selector({Option(string("Start  Game"), Point((width / 2) - 2, (height / 2) - 2)),
                          Option(string("Setting"), Point((width / 2) - 1, height / 2)),
                          Option(string("Quit   Game"), Point((width / 2) - 2, (height / 2) + 2))}))
        {
        case 0:
            start();
            break;
        case 1:
            setting();
            break;
        case 2:
            quit();
            break;
        default:
            break;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
void Game::setting(void)
{
    printFrame();
    switch (Selector({Option(string("Resize  Game"), Point((width / 2) - 2, (height / 2) - 2)),
                      Option(string("Change Speed/ms"), Point((width / 2) - 3, (height / 2))),
                      Option(string("Back"), Point((width / 2), (height / 2) + 2))}))
    {
    case 0:
        Option(string("Input New Size:\n"), Point((width / 2) - 3, (height / 2) - 1)).unchoose();
        SetCursorPosition((width / 2) - 2, height / 2);
        cin >> width >> height;
        if (width < 20)
            width = 20;
        if (height < 20)
            height = 20;
        SetCursorPosition(0, height / 2);
        // Clear input line
        cout << string("■") + string(width * 2, ' ') + string("■");
        SetCursorPosition((width / 2) - 2, (height / 2) - 1);
        cout << "Size Changed" << speed;
        SetCursorPosition((width / 2) - 5, (height / 2) + 1);
        cout << "Press ENTER back to menu";
        break;
    case 1:
        Option(string("Input Speed:\n"), Point((width / 2) - 2, (height / 2) - 1)).unchoose();
        SetCursorPosition((width / 2) - 2, height / 2);
        cin >> speed;
        SetCursorPosition(0, height / 2);
        // Clear input line
        cout << string("■") + string(width * 2, ' ') + string("■");
        SetCursorPosition((width / 2) - 4, (height / 2) - 1);
        cout << "Speed changed to " << speed;
        SetCursorPosition((width / 2) - 5, (height / 2) + 1);
        cout << "Press ENTER back to menu";
        break;
    case 2:
    default:
        break;
    }
}
////////////////////////////////////////////////////////////////////////////////
void Game::quit(void)
{
    printFrame();
    SetCursorPosition((width / 2) - 4, (height / 2) - 1);
    cout << "ARE YOU SURE TO QUIT?";
    if (Selector(
            {Option(string("YES"), Point((width / 2) - 2, (height / 2) + 1)),
             Option(string("NO"), Point((width / 2) + 1, (height / 2) + 1))}) == 0)
        exit(0);
}
////////////////////////////////////////////////////////////////////////////////
void Game::start(void)
{
    printFrame();
    Snake snake(snake_length, width / 2, height / 2, width, height);
    Food food(width, height);
    snake.initialize();
    food.fresh(snake);

    while (snake.alive)
    {
        char key = 0;
        if (_kbhit())
        { // Judging keyboard pressed
            key = _getch();
            switch (key)
            {
            case -32: // Arrow Key
                key = _getch();
                snake.turn(key);
                break;
            case 27: // ESC
                pause();
                // Back to current game
                printFrame();
                snake.printBody();
                food.print();
                char tit[30];
                for(int i = 5; i > 0; --i)
                {
                    sprintf(tit,"title Ready(%.1fs)",i/10.0);
                    system(tit);
                    Sleep(100);
                }
                system("title GreedySnake");
                break;
            default:
                break;
            }
        }

        if (snake.meetFood(food.pos))
        {
            snake.eat();
            food.fresh(snake);
        }
        else
            snake.move();

        Sleep(speed);
    }
    printFrame();
    SetCursorPosition((width / 2) - 2, (height / 2) - 4);
    cout << "GAME    OVER";
    if (Selector(
            {Option(string("Replay"), Point((width / 2) - 1, (height / 2) - 1)),
             Option(string("Back to Main Menu"), Point((width / 2) - 3, (height / 2) + 1))}) == 0)
        start();
}
////////////////////////////////////////////////////////////////////////////////
void Game::pause(void)
{
    printFrame();
    SetCursorPosition((width / 2) - 2, (height / 2) - 4);
    cout << "Game   Pause";
    switch (Selector(
        {Option(string("Continue"), Point((width / 2) - 1, (height / 2) - 2)),
         Option(string("Setting"), Point((width / 2) - 1, height / 2)),
         Option(string("Back to Menu"), Point((width / 2) - 2, (height / 2) + 2))}))
    {
    case 0:
        break;
    case 1:
        setting();
        pause();
        break;
    case 2:
        menu();
    default:
        break;
    }
}