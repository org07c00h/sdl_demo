#include "Player.hpp"
#include <iostream>
ActionMap<int> Player::playerInputs;
Player::Player(int x, int  y) : ActionTarget(playerInputs)
{
    m_x = x;
    m_y = y;

    m_textureId = "magic";
    m_srcRect.x = 16;
    m_srcRect.y = 48;
    m_srcRect.w = 16;
    m_srcRect.h = 16;

    m_destRect.x = m_x;
    m_destRect.y = m_y;
    m_destRect.w = 16 * 2;
    m_destRect.h = 16 * 2;
    mTicks = 0;
    mCurrentAnimation = 0;

    start = false;
    SDL_KeyboardEvent key;
    //key.t
    key.keysym.sym = SDLK_DOWN;
    key.keysym.scancode = SDL_SCANCODE_DOWN;
    bind(Action(key), [this](const SDL_Event& event) {
        std::cout << "HELLO" << std::endl;
        start = !start;
    });
}


Player::~Player()
{

}

void Player::draw()
{
    theTextureManager.draw(m_textureId, &m_srcRect, &m_destRect, SDL_FLIP_HORIZONTAL);
}

void Player::update()
{
    if (start)
    {
        m_x += 1;
        m_destRect.x = m_x;
        mTicks = (mTicks + 1) % 8;
        if (mTicks == 0)
        {
            mCurrentAnimation = (mCurrentAnimation + 1) % 6;
            m_srcRect.x = 16 * (mCurrentAnimation + 1);
        }
    }
    ActionTarget::processEvents();
}

void Player::startAnimation()
{
    start = !start;
    m_x = 40;
}

void Player::clean()
{

}
