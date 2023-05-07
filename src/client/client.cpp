#include "./client.hpp"
#include "../tools/Common.hpp"
#include <boost/thread/thread.hpp>
#include <boost/asio.hpp>
#include "../shell/server_cli/ServerShell.hpp"
#include <regex>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include "..//tools/Flags.hpp"
#include <ofstream>
#include <filesystem>

std::pair<std::string,std::string> decode(std::string data){
    return std::make_pair("","");
}

void print_new(std::string message,client& _client){
    std::cout << message; // decorate

    std::regex rgx1("from:(.*)\\n");
    std::regex rgx2("data:'(.*)'");
    std::regex rgx3("flag:(.*)\\n");

    size_t flag;
    std::string from;
    std::string data;
    
    std::smatch match;
    if (std::regex_search(message, match, rgx1) && std::regex_search(message, match, rgx2) && std::regex_search(message, match, rgx3)) {
        
        flag = reinterpret_cast<szie_t>(std:::string(match[3]));
        from = std::string(match[1]);
        data = std::string(match[2]);

        switch(flag){
            case(Flags::Request::_FILE):{

                auto decoded_data = decode(data);

                std::string file_name = decoded_data.first();
                std::string file_data = decoded_data.second();

                std::experimental::filesystem::path file_path("~/" + file_name);
                std::ofstream file(file_name);
                if(!file.is_open()){
                    file.open(file_path,std::ios::binary);
                    file << file_data;
                    file.close();
                    std::cout << from + " sent you 1 file["  + file_path + "]\n"; // add date
                }
            }
            case(Flags::Request::_MSG):{
                std::cout << from + ": " + data + '\n';
            }
        }
    }
}


void start_handle_new(client& _client);

void finish_handle_new(int i,client& _client){
    boost::asio::async_read(*cli.sock,
    boost::asio::buffer(cli.message_now, cli.sizes[i]),
    [](boost::system::error_code& err,size_t transferred){
        if(!err){
            if(i<4){
                finish_handle_new(i++,_client);
            }
            else{
                print_new(cli.message_now,_client);
                start_handle_new(_client);
            }
        }
    }
    );
}

void start_handle_new(client& client){
    client.message_now.clear();

    boost::asio::async_read(*cli.sock,
        boost::asio::buffer(cli.sizes, 8*4),
        [&client](boost::system::error_code& err,size_t transferred){
            if(!err){
                finish_handle_new(0,client);
            }
    }
    );
    IOservice.run();
}

void server_shell_loop(){
    ServerShell shell(allServerCommands,serverHistory);
    shell.launch();
}


void client::connect(std::string ip,int port){
   try{     
        boost::thread_group threads;

        cli.sock->connect(ip,port);

        threads.create_thread(boost::bind(&start_handle_new,this));
        threads.create_thread(boost::bind(&server_shell_loop));
        threads.join_all();
      
        IOservice.run();
   }
   catch(boost::system::system_error& err){
        std::cout << err.what() <<std::endl;
   }
}

client::client(io_service& ioservice):sock(new tcp::socket(ioservice)){}