// game.h
#ifndef game_H
#define game_H

class game
{
private:
    /* data */
public:
    static void Current_Position();
    static void Move();
    static void Updated_Position();
    static void Previous_Position();
    static void Reset();
    static void checkmate();
    static void check();
    static bool Istrue();
    game(/* args */);
    bool istrue;
    ~game();
};

game::game(/* args */)
{
}

game::~game()
{
}


#endif // game.h
