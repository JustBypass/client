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
    
    std::string enter;
    std::cin >> enter;
    cli.name = enter;
    try{
        cli.connect();
        // socket->write_some() send header LOGIN with your name
       // boost::thread_group threads;
       
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