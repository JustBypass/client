 class Flags{
public:
    enum Request{
        _FILE,
        _MSG,
        _REQ_ONLINE,
        _REQ_ALL,
        _CONNECT,
        _EXIT,
        _SET_NICKNAME,
        _MSG_ALL
    };
    enum Response{
        ERROR,
        ONLINE,
        MSG_TYPE_EXCEPTION,
        UNKNOWN_FORMAT
    };
};