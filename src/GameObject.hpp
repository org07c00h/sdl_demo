class GameObject
{
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
protected:
    int m_x;
    int m_y;
};
