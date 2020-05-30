#ifndef GAME_H
#define GAME_H

class Game
{
public:
    enum Game_Status
    {
        NEW = 1,
        CONTINUE
    };
    Game() = default;
    void initialize(void);
    void printFrame(void) const;
    void menu(void);
    void setting(void);
    void quit(void);
    void start(void);
    void pause(void);

private:
    int width, height;
    int speed, snake_length;
};

#endif