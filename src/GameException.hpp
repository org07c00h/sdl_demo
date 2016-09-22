#pragma once
#include <exception>
#include <string>

enum ErrorType {INIT_ERROR, WINDOW_ERROR, RENDER_ERROR, IMAGE_LOAD_ERROR};

class GameException : public std::exception
{
public:
    GameException(const char* message): msg(message) {}
    GameException(const std::string message): msg(message) {}

    virtual ~GameException() throw() {}
    const char* what() { return msg.c_str(); }
private:
    std::string msg;
};
