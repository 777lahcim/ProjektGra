#include "Game.h"

Game game;

int main()
{
    std::srand(time(NULL));
    while (game.running())
    {
        //update
        game.update();
        //render
        game.render();
    }

    return 0;
}