#include <iostream>

#include "Game.hpp"
#include "GameException.hpp"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char** argv)
{
    uint frameStart;
    uint frameTime;

    try
    {
        theGame.init("We need a Villan", 50, 50, 640, 480, false);
    }
    catch(GameException& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    while(theGame.isRunning())
    {
        frameStart = SDL_GetTicks();
        ///////////////////////////
        theGame.handleEvents();
        theGame.update();
        theGame.render();
        ///////////////////////////
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < DELAY_TIME)
        {
            SDL_Delay((int)(DELAY_TIME - frameTime));
        }
    }

    std::cout << "Game Closing" << std::endl;
    theGame.clean();

    return 0;
}
