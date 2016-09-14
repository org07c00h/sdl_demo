#pragma once
#include <exception>
#include <string>

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
