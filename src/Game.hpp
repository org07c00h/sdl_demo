#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "TextureManager.hpp"

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
    SDL_Renderer* getRenderer();
private:
    Game();
    ~Game();

    bool m_running;
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;
    static Game* m_instance;
};

#define theGame Game::getInstance()
