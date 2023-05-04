#include <string>

class processor{
public:
    std::string processed_message(std::string);
     enum request_flag_type{
        _FILE,
        _MSG,
        _REQ_ONLINE,
        _REQ_ALL,
        _CONNECT,
        _EXIT,
        _SET_NICKNAME
    };
    enum responce_flag_type{
        ERROR,
        ONLINE,
        MSG_TYPE_EXCEPTION
    };

};