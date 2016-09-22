#pragma once
#include <unordered_map>
#include "Action.hpp"

template<typename T = int>
class ActionMap
{
public:
    ActionMap(const ActionMap<T>&) = delete;
    ActionMap<T>& operator = (const ActionMap<T>&) = delete;
    ActionMap() = default;
    void map(const T& t_key, const Action& t_action);
    const Action& get(const T& t_key) const;
private:
    std::unordered_map<T, Action> m_map;
};
#include "ActionMap.tpl"
