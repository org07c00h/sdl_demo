#include "TextureManager.hpp"
#include "GameException.hpp"
#include "Game.hpp"

TextureManager* TextureManager::m_instance = nullptr;

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{

}

TextureManager& TextureManager::getInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new TextureManager();
    }
    return *m_instance;
}

void TextureManager::load(std::string fileName, std::string id)
{
    SDL_Surface* image = IMG_Load(fileName.c_str());
    if (!image)
    {
        throw GameException(IMG_GetError());
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(theGame.getRenderer(),
        image);
    if (texture == 0)
    {
        throw GameException("Failed to create texture");
    }
    m_textureMap[id] = texture;
    SDL_FreeSurface(image);
}

void TextureManager::draw(std::string id, SDL_Rect* srcRect, SDL_Rect* destRect,
    SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(theGame.getRenderer(), m_textureMap[id], srcRect,
        destRect, 0, 0, flip);
}

void TextureManager::draw(std::string id, int x, int y, int width, int height,
    SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;

    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(theGame.getRenderer(), m_textureMap[id], &srcRect,
        &destRect, 0, 0, flip);
}
