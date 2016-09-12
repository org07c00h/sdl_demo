#pragma once
#include <SDL2/SDL.h>

class Game
{
public:
    bool init(const char* title, int x, int y, int width, int height,
        bool fullscreen);

    void update();
    void handleEvents();
    void render();
    void clean();

    bool isRunning();
    static Game& getInstance();
private:
    Game();
    ~Game();

    bool m_running;
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    static Game* m_instance;
};

#define theGame Game::getInstance()
