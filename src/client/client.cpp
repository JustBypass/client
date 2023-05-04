#include "./client.hpp"
#include "../tools/Common.hpp"
#include <boost/thread/thread.hpp>
#include <boost/asio.hpp>
#include "../shell/Shell.hpp"

void print_new(){

}


void handle_new(std::string message_now){
 /*   boost::asio::async_read(*cli.sock,
    boost::asio::buffer(message_now, message_now.size()),
    [](boost::system::error_code& err,size_t transferred){
        if(!err){
            std::cout << transferred <<std::endl;
            // add to deque
            print_new();
        }
    }
    );
    IOservice.run();*/
}

void server_shell_loop(){
 //   while(true){// Use template method pattern to create new ServerShell
        // here is specifical shell
    //    std::cout << "server_shell_loop()\n";
        Shell shell;
        shell.launch();
    //    boost::this_thread::sleep_for(boost::chrono::seconds(2));
   // }
}


 void client::handle_connect(const boost::system::error_code& error){
    if(error){
        std::cout<<error.message();
        return;
    }
    return;
}

void client::connect(){
   try{     
        boost::thread_group threads;

        threads.create_thread(boost::bind(&handle_new,message_now));
        threads.create_thread(boost::bind(&server_shell_loop));
        threads.join_all();
      
        IOservice.run();
   }
   catch(boost::system::system_error& err){
        std::cout << err.what() <<std::endl;
   }
}

client::client(io_service& ioservice,tcp::endpoint& ep){
    socket_ptr nsock(new tcp::socket(ioservice));
    
    endpoint = ep;
    sock = nsock;
}