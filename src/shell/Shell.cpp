#include "./Shel.hpp"
#include <iostream>
#include "./ClosedSession.hpp"
#include <boost/system>
#include "../tools/Common.hpp"
#include "../client/client.hpp"

void Shell::launch(){
     printf("\033c");
    std::cout<< "░█░█░█░█▀▀▀░█░░░░█▀▀▀░█▀▀█░█▀█▀█░█▀▀▀░\n"<<
                "░█░█░█░█▀▀▀░█░░░░█░░░░█░░█░█░█░█░█▀▀▀░\n"
             << "░▀▀▀▀▀░▀▀▀▀░▀▀▀▀░▀▀▀▀░▀▀▀▀░▀░▀░▀░▀▀▀▀░\n";
    try
    {
        while(1){

            std::cout<< cli.name + " << ";

            std::string str;
            std::cin >> str;

            [&str](){
                if(cmd.count(str) <= 0){
                    std::cout << std::string("Command '"  + str +"' not found\n");
                }
                else {
                    hist.push_back(str);                  
                    cmd[str]->execute();
                }
            }() ;  
        }
    }
    catch(const ClosedSession& e)
    {
        std::cerr << e.what() << '\n';
       // cli.sock->shutdown(boost::asio::ip::tcp::socket::shutdown_both);
		//cli.sock->close();	
    }
    catch(boost::system::system_error& err){
        std::cout << err.what() <<std::endl;
    }
}