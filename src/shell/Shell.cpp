#include "./Shell.hpp" 
#include "./user_cli/HelpShellCommand.hpp"
#include "./user_cli/ExitShellCommand.hpp"
#include "./user_cli/ConnectShellCommand.hpp"
#include "../client/client.hpp"
#include "../tools/Common.hpp"
#include "./user_cli/HistoryShellCommand.hpp"

void Shell::launch(){
  
   // HelpShellCommand a(); 
    allCommands.insert(std::make_pair(std::string("help"),new HelpShellCommand()));
    allCommands.insert(std::make_pair(std::string("exit"),new ExitShellCommand()));
    allCommands.insert(std::make_pair(std::string("connect"),new ConnectShellCommand()));
    allCommands.insert(std::make_pair(std::string("disconnect"),new ConnectShellCommand()));
    allCommands.insert(std::make_pair(std::string("messages"),new ConnectShellCommand()));
    allCommands.insert(std::make_pair(std::string("history"),new HistoryShellCommand()));
    allCommands.insert(std::make_pair(std::string("online"),new ConnectShellCommand()));

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
                if(allCommands.count(str) <= 0){
                    std::cout << std::string("Command '"  + str +"' not found\n");
                }
                else {
                    history.push_back(str);                  
                    allCommands[str]->execute();
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