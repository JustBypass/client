#include "./SendMessageShellCommand.hpp"
#include "../../tools/Common.hpp"
#include <iterator>
#include <boost/asio.hpp>
#include "../../client/client.hpp"
#include "../../tools/Flags.hpp"
#include "../../builders/meter.hpp"
#include <fstream>

std::string convert(std::string from,std::string to,size_t flag,std::string body){
    meter _meter;

    auto arr =  (new meter)->get_sizes(from,to,body);
    char buffer[4*sizeof(int)];
    memcpy(buffer,arr,4*sizeof(int));

    auto foo = std::string(reinterpret_cast<const char*>(buffer),4*sizeof(int));
     
    delete(arr);

    return foo + std::string("from:") + from + 
                                        '\n'+std::string("to:") + 
                                                to + 
                                        '\n' + 
                                        std::string("flag:") +  
                                                        std::string((char*)&flag,sizeof(int)) + '\n' +
                                                            std::string("data:'") + 
                                                                    body + "'";

}

void SendMessageShellCommand::execute(){
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

    std::string result = convert(from,to,flag,_body);
    cli.sock->async_write_some(boost::asio::buffer(result,result.size()),[&](const boost::system::error_code& error,size_t bytes){
        if(!error){
            std::cout << "Message delivered![";// + std::string(bytes) + " bytes]\n";
        }
    });
}


std::string SendMessageShellCommand::toString(){
    return "";
}