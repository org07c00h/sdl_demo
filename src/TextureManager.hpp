#pragma once
#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager
{
public:
    static TextureManager& getInstance();
    void load(std::string fileName, std::string id);
    void draw(std::string id, int x, int y, int width, int height,
        SDL_RendererFlip flip = SDL_FLIP_NONE);
    void draw(std::string id, SDL_Rect* srcRect, SDL_Rect* destRect,
        SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
    TextureManager();
    ~TextureManager();

    static TextureManager* m_instance;
    std::map<std::string, SDL_Texture*> m_textureMap;
};

#define theTextureManager TextureManager::getInstance()
