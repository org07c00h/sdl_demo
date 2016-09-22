template<typename T>
void ActionMap<T>::map(const T& t_key, const Action& t_action)
{
    m_map.emplace(t_key, t_action);
}
template<typename T>
const Action& ActionMap<T>::get(const T& t_key) const
{
    return m_map.at(t_key);
}
