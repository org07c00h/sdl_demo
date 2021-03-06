#include <SDL2/SDL.h>
#include <string>
#include "GameObject.hpp"
#include "TextureManager.hpp"
#include "Action.hpp"
#include "ActionTarget.hpp"

class Player : public GameObject, public ActionTarget<int>
{
public:
    Player(int x, int y);
    ~Player();
    void draw();
    void update();
    void clean();

    void startAnimation();
static ActionMap<int> playerInputs;
private:
    bool start;
    std::string m_textureId;
    SDL_Rect m_srcRect;
    int mTicks;
    uint mCurrentAnimation;
    SDL_Rect m_destRect;

};
