#include "./SendMessageShellCommand.hpp"
#include "../../tools/Common.hpp"
#include <iterator>
#include <boost/asio.hpp>
#include "../../client/client.hpp"
#include "../../tools/Flags.hpp"
#include "../../builders/meter.hpp"
#include <fstream>
#include <iostream>

void SendMessageShellCommand::execute(){
    boost::shared_ptr<meter> _meter(new meter());
    std::string input;
        std::cout << "What type of message? [F/M]";
    std::cin >> input;
    
    std::string to;
    std::string from = cli.name;
    std::string _body;
    size_t flag;
    if(input == "F")            
    { 
        std::cout << "Enter absolete path of file: ";
        std::cin >> input;
        std::ifstream ifs(input);

        std::string body(std::istreambuf_iterator<char>{ifs},{}) ;

        _body = body;
        flag = Flags::Request::_FILE;    
        ifs.close();   
    }
    else
    {
        std::cout << "Enter your message: ";
        std::cin >> input;
        _body = input;     
        flag = Flags::Request::_MSG;
    }
    
    std::cout << "Enter consumers[comma-separated]: ";
    std::cin >> input;
    to = input;
    if(to == "*"){
        to = "";
        flag = Flags::Request::_MSG_ALL;
    }
    std::string result = _meter->convert(from,to,flag,_body);
    std::cout <<"result= "<<result.size() <<std::endl;
    cli.sock->async_write_some(boost::asio::buffer(result,result.size()),[&](const boost::system::error_code& error,size_t bytes){
        if(!error){
            std::cout << "Message delivered![";// + std::string(bytes) + " bytes]\n";
        }
        else{
            std::cout << "Some error whilw delivering\n";
        }
    });
}


std::string SendMessageShellCommand::toString(){
    return "";
}