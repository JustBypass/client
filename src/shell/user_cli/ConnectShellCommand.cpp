#include "./ConnectShellCommand.hpp"
#include <termios.h>
#include <boost/thread/thread.hpp>
#include <boost/chrono/chrono.hpp>

#include <boost/version.hpp>
#include <boost/thread/mutex.hpp>
#include "../../tools/Common.hpp"
#include "../../client/client.hpp"

void ConnectShellCommand::execute(){
    std::cout<<"Enter your nickname:";
    
    std::string ip;
    int port;

    std::string enter;
    std::cin >> enter;
        cli.name = enter;
    std::cout << "Enter ip number:";
    std::cin >> enter;
        ip = enter;
    std::cout << "Enter port number:";
    std::cin >> enter;
      port = std::atoi(enter.c_str());

    try{
        cli.connect(ip,port);       
    }catch(std::exception& ex){
        std::cout<<ex.what()<<'\n';
    }
    // do async
}
std::string ConnectShellCommand::toString(){
    return "Connection Closed\n";
}

void callback(boost::system::error_code& error,size_t bytes){

}