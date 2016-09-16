#pragma once
#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager
{
public:
    static TextureManager& getInstance();
    void load(std::string fileName, std::string id, SDL_Renderer* renderer);
    void draw(std::string id, int x, int y, int width, int height,
        SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
    TextureManager();
    ~TextureManager();

    static TextureManager* m_instance;
    std::map<std::string, SDL_Texture*> m_textureMap;
};

#define theTextureManager TextureManager::getInstance()
