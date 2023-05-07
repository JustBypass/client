#include <iostream>
#include <string>
class ClosedSession:public std::runtime_error{
public:
    ClosedSession(std::string e):std::runtime_error(e){}
};