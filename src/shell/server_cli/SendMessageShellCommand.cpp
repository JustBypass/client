#include "./SendMessageShellCommand.hpp"
#include "../../tools/Common.hpp"
#include <iterator>
#include <boost/asio.hpp>
#include "../../client/client.hpp"
#include "../../Flags.hpp"


std::string convert(std::string from,std::string to,size_t flag,std::string body){
    return "";
}

void SendMessageShellCommand::execute(){
    std::string input;
        std::cout << "What type of message? [F/M]"
    std::cin >> input;
    
    std::string to;
    std::string from = cli.get_name();
    std::string _body;
    size_t flag;
    switch(input){
        case("F"):{
            std::cout << "Enter absolete path of file: ";
            std::cin >> input;
            std::ifstream ifs(input);

            std::string body(std::istreambuf_iterator<char>{ifs},{}) ;

            _body = body;
            flag = Flags::Request::_FILE;
            
        }
        case("M"):{
            std::cout << "Enter your message: ";
            std::cin >> input;
            _body = input;     
            flag = Flags::Request::_MSG;
        }
    }

    std::cout << "Enter consumers[comma-separated]: ";
    std::cin >> input;
    to = input;

    std::string result = convert(from,to,flag,_body);
    cli.sock->async_write_some(boost::asio::buffer(result,result.size(),[](boost::system::error_code& error,size_t bytes){
        if(!error){
            std::cout << "Message delivered![" + bytes + " bytes]\n";
        }
    }));
}