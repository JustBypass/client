#include "./meter.hpp"
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <cstring>
int* meter::get_sizes(std::string from,
                std::string to,
                std::string body)
{
    std::cout <<"get_sizes\n";
    int* arr = new int(4);
    
    arr[0] = 7 + from.size();;
    arr[1] = to.size() + 5;
    arr[2] = 8;
    arr[3] = body.size() + 7;

    std::cout <<"~get_sizes\n";
    return arr;
}

std::string meter::greetingMessage(std::string nickname){
    return convert(nickname,"",4,nickname);
}

std::string meter::convert(std::string from,std::string to,int flag,std::string body){
    std::cout << "convert()\n";
    int* arr = get_sizes(from,to,body);

    unsigned char* bytes = reinterpret_cast<unsigned char*>(arr);
    for (int i = 0; i < 4 * sizeof(int); i++) {
        std::cout << static_cast<int>(bytes[i]) << " ";
    }
    std::string str(reinterpret_cast<char*>(bytes), 4 * sizeof(int));

    int new_arr[4];
    for (int i = 0; i < 4; i++) {
        new_arr[i] = *reinterpret_cast<int*>(&str[i * sizeof(int)]);
    }

    delete(arr);

    std::cout <<"~convert()\n";
    return str + std::string("from:'") + from + 
                                        "'"
                                        +std::string("to:'") + 
                                                to + 
                                        "'" + 
                                        std::string("flag:'") +  
                                                        std::to_string(flag) + "'" +
                                                            std::string("data:'") + 
                                                                    body + "'";

}

