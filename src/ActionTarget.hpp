#pragma once
#include <functional>
#include <list>
#include <utility>
#include <SDL2/SDL.h>
#include <iostream>
//#include "Action.hpp"
#include "ActionMap.hpp"
template<typename T = int>
class ActionTarget
{
public:
    ActionTarget(const ActionTarget<T>&) = delete;
    ActionTarget<T>& operator = (const ActionTarget<T>&) = delete;
    using FuncType = std::function<void(const SDL_Event&)>;
    //ActionTarget() = default;
    ActionTarget(const ActionMap<T>& map);
    bool processEvent(const SDL_Event& event) const;
    void processEvents() const;
    void bind(const Action& t_action, const FuncType& t_callback);
    void unbind(const Action& t_action);
private:
    std::list<std::pair<Action, FuncType>> m_eventsRealTime;
    std::list<std::pair<Action, FuncType>> m_eventsPoll;
    const ActionMap<T>& m_actionMap;
};
#include "ActionTarget.tpl"
