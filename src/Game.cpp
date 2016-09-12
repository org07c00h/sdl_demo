#include <iostream>
#include "Game.hpp"

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
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init successful" << std::endl;
        int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;

        m_window = SDL_CreateWindow(title, x, y, width, height, flags);
        if (m_window != 0)
        {
            std::cout << "window created successful" << std::endl;
            m_renderer = SDL_CreateRenderer(m_window, -1,
                SDL_RENDERER_ACCELERATED);
            if (m_renderer != 0)
            {
                std::cout << "renderer created successful" << std::endl;
            }
            else
            {
                std::cout << "renderer init failed" << std::endl;
                return false;
            }
        }
        else
        {
            std::cout << "window init failed" << std::endl;
            return false;
        }
    }
    else
    {
        std::cout << "SDL init failed" << std::endl;
        return false;
    }
    m_running = true;

    return true;
}


void Game::render()
{
    SDL_RenderClear(m_renderer);

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
