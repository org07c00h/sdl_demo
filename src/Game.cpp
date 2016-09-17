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
    int img_flags = IMG_INIT_PNG;
    int initted = IMG_Init(img_flags) & img_flags;
    if (initted != img_flags)
    {
        throw GameException(IMG_GetError());
    }

    loadTextures();
    initGameObject();

    m_running = true;

    return true;
}


void Game::render()
{
    SDL_RenderClear(m_renderer);

    theTextureManager.draw("icons", 20, 30, 60, 128);
    m_player->draw();

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

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_SPACE:
                        m_player->startAnimation();
                    break;

                    default:
                    break;
                }

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
    IMG_Quit();
    SDL_Quit();
}

void Game::update()
{
    m_player->update();
}

bool Game::isRunning()
{
    return m_running;
}

SDL_Renderer* Game::getRenderer()
{
    return m_renderer;
}

void Game::loadTextures()
{
    theTextureManager.load("./data/1.png", "icons");
    theTextureManager.load("./data/something.png", "magic");
}

void Game::initGameObject()
{
    m_player = new Player(20, 200);
}
