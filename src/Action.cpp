#include "Action.hpp"
#include <iostream>

Action::Action(const SDL_KeyboardEvent& key, int type) : m_type(type)
{

    m_event.key = key;
    m_event.key.type = SDL_KEYDOWN;
    std::cout << "Action::Contructor " << m_event.key.type << std::endl;
}
Action::Action(const SDL_MouseButtonEvent& button, int type) : m_type(type)
{
    m_event.type = SDL_MOUSEBUTTONDOWN;
    m_event.button = button;
}
bool Action::operator==(const SDL_Event &event) const
{
    bool res = false;
    switch (event.type) {
        case SDL_KEYDOWN:
        {
            if (m_type & Type::Pressed && m_event.type == SDL_KEYDOWN)
            {
                res = event.key.keysym.sym == m_event.key.keysym.sym;
            }
        }
        break;
        case SDL_KEYUP:
        {
            if (m_type & Type::Released && m_event.type == SDL_KEYDOWN)
            {
                res = event.key.keysym.sym == m_event.key.keysym.sym;
            }
        }
        break;
        // TODO: Handle mouse events
    }
    return res;
}
bool Action::operator==(const Action &other) const
{
    // TODO: Handle correctly events
    return m_type == other.m_type;
}
bool Action::test() const
{
    bool res = false;

    if (m_event.key.type == SDL_KEYDOWN)
    {
        if (m_type & Type::Pressed)
        {
            std::cout << "Action::test() = " << m_event.key.type << " " << SDL_KEYDOWN << std::endl;
            const Uint8* state = SDL_GetKeyboardState(NULL);
            res = state[m_event.key.keysym.scancode] != 0;

        }
    }
    return res;
}
