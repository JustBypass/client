#include "./client.hpp"
#include "../tools/Common.hpp"
#include <boost/thread/thread.hpp>
#include <boost/asio.hpp>
#include "../shell/server_cli/ServerShell.hpp"
#include <regex>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include "..//tools/Flags.hpp"

void encode(){

}

void decode(){

}

void print_new(std::string message){
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
                // open file and decode s
            }
            case()Flags::Request::_MSG:{
                /// decode and read
            }
        }
    }
    /// Or collect logs
}


void start_handle_new(client& client);

void finish_handle_new(int i,client& client){
    boost::asio::async_read(*cli.sock,
    boost::asio::buffer(cli.message_now, cli.sizes[i]),
    [](boost::system::error_code& err,size_t transferred){
        if(!err){
            if(i<4){
                finish_handle_new(i++,client);
            }
            else{
                print_new(cli.message_now);
                start_handle_new(client);
            }
        }
    }
    );
}

void start_handle_new(client& client){
    client.message_now = "";
    boost::asio::async_read(*cli.sock,
    boost::asio::buffer(cli.sizes, 8*4),
    [&client](boost::system::error_code& err,size_t transferred){
        if(!err){
            finish_handle_new(0,client);
            //std::cout << transferred <<std::endl;
            // add to deque
           // print_new();
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

client::client(io_service& ioservice,){
    socket_ptr nsock(new tcp::socket(ioservice));
    
    sock = nsock;
}