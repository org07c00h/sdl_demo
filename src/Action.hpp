#pragma once
#include <SDL2/SDL.h>
//#include "ActionTarget.hpp"
class Action
{
public:
    enum Type
    {
        RealTime = 1,
        Pressed = 1 << 1,
        Released = 1 << 2
    };
    Action(const SDL_KeyboardEvent& key,
        int type = Type::RealTime | Type::Pressed);
    Action(const SDL_MouseButtonEvent& button,
        int type = Type::RealTime | Type::Pressed);
    bool test() const;
    bool operator==(const SDL_Event& event) const;
    bool operator==(const Action& other) const;
private:
    template<typename> friend class ActionTarget;
    SDL_Event m_event;
    int m_type;
};
