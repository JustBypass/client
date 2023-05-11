#include "./meter.hpp"


int* meter::get_sizes(std::string from,
                std::string to,
                std::string body)
{
    int* arr = new int(4);
    
    
    arr[2] = 5*1 + 8;
    arr[1] = 5 + from.size() + 1;
    arr[2] = to.size() + 1;
    arr[3] = body.size() + 7;
    return arr;
}

