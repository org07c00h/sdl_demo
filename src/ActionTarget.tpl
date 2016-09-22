template<typename T>
ActionTarget<T>::ActionTarget(const ActionMap<T>& t_map):
    m_actionMap(t_map)
{

}
template<typename T>
bool ActionTarget<T>::processEvent(const SDL_Event& event) const
{
    bool res = false;
    for (auto& action : m_eventsPoll)
    {
        if (action.first == event)
        {
            action.second(event);
            res = true;
            break;
        }
    }
    return res;
}
template<typename T>
void ActionTarget<T>::processEvents() const
{
    for (auto& action : m_eventsRealTime)
    {
        if (action.first.test())
        {
            std::cout << "Hello processEvents" << m_eventsRealTime.size() << std::endl;
            action.second(action.first.m_event);
        }
    }
}
template<typename T>
void ActionTarget<T>::bind(const Action& t_action, const FuncType& t_callback)
{
    std::cout << "Hello bind" << std::endl;
    if (t_action.m_type & Action::Type::RealTime)
    {
        m_eventsRealTime.emplace_back(t_action, t_callback);
    }
    else
    {
        m_eventsPoll.emplace_back(t_action, t_callback);
    }
}
template<typename T>
void ActionTarget<T>::unbind(const Action& t_action)
{
    auto remove_func = [&t_action](const std::pair<Action,
         FuncType>& pair) -> bool
    {
        return pair.first == t_action;
    };
    if (t_action.m_type & Action::Type::RealTime)
    {
        m_eventsRealTime.remove_if(remove_func);
    }
    else
    {
        m_eventsPoll.remove_if(remove_func);
    }
}
