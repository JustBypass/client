#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <vector>
#include <deque>

using namespace boost ;
using namespace boost::asio ;
using namespace boost::asio::ip ;

typedef boost::shared_ptr<tcp::socket> socket_ptr;
typedef boost::shared_ptr<std::string> string_ptr;

class client{
private:
    tcp::endpoint endpoint;
    enum request_flag_type{
        FILE,
        MSG,
        REQ_ONLINE,
        REQ_ALL,
        CONNECT,
        EXIT,
        SET_NICKNAME
    };
    enum responce_flag_type{
        ERROR,
        ONLINE,
        MSG_TYPE_EXCEPTION
    };

public:
    std::string name = "db";
    socket_ptr sock;
public:
    std::string get_name();
public:
    void send(std::vector<std::string>);
    void send(std::string);
public:
    client(io_service& ioservice);
public:
    void connect(std::string ip,int port);
    void disconnect(); 
public:
    std::vector<std::string> get_online_users();
private:
    static void handle_connect(const boost::system::error_code& error);
public:
    std::string message_now;
    size_t sizes[4];
    size_t level_now;
private:
    std::deque<std::string> messages;
};
