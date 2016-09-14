#include <iostream>
#include "Game.hpp"
#include "GameException.hpp"

Game* Game::m_instance = nullptr;

Game::Game()
{
    m_running = false;
    m_window = nullptr;
    m_renderer = nullptr;

}

Game& Game::getInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new Game();
    }
    return *m_instance;
}

bool Game::init(const char* title, int x, int y, int width, int height,
    bool fullscreen)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        throw GameException("SDL init failed");
    }

    std::cout << "SDL init successful" << std::endl;
    int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;

    m_window = SDL_CreateWindow(title, x, y, width, height, flags);
    if (m_window == NULL)
    {
        throw GameException("window init failed");
    }
    std::cout << "window created successful" << std::endl;
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (m_renderer == NULL)
    {
        throw GameException("renderer init failed");
    }

    if (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG != IMG_INIT_PNG)
    {
        throw GameException(IMG_GetError());
    }

    SDL_Surface* image = IMG_Load("./data/1.png");
    if (!image)
    {
        std::cout << "img load" << std::endl;
    }
    m_texture = SDL_CreateTextureFromSurface(m_renderer, image);
    if (m_texture == NULL)
    {
        std::cout << "img load2" << std::endl;
    }
    SDL_FreeSurface(image);
    SDL_SetRenderDrawColor(m_renderer, 155,155,155,255);
    int w = 160;
    int h = 128;
    if (SDL_QueryTexture(m_texture, NULL, NULL, &w, &h) != 0)
    {
        std::cout << "Error" << std::endl;
    }
    m_running = true;

    return true;
}


void Game::render()
{
    SDL_RenderClear(m_renderer);
    SDL_Rect texr;
    texr.x = 100; texr.y = 50; texr.w = 160; texr.h = 128;
    SDL_RenderCopy(m_renderer, m_texture, NULL, &texr);

    SDL_RenderPresent(m_renderer);
}

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type) {
            case SDL_QUIT:
                m_running = false;
            break;

            default:
            break;
        }
    }
}

void Game::clean()
{
    std::cout << "cleaning game" << std::endl;
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
}

void Game::update()
{

}

bool Game::isRunning()
{
    return m_running;
}
