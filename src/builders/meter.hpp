#include <string>
#include <set>

class meter{
public:
    meter(){}
    int* get_sizes(std::string from,
                    std::string to,
                    std::string body);
    std::string greetingMessage(std::string nickname);
    std::string convert(std::string from,std::string to,int flag,std::string body);
};