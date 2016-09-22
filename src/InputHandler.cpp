#include <SDL2/SDL.h>

class InputHandler
{
public:
    static InputHandler& getInstance();

private:
    InputHandler();

    static InputHandler* m_instance;
};
