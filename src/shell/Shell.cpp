#include "./Shell.hpp"
#include <iostream>
#include "./ClosedSession.hpp"
//#include <boost/system>
#include "../tools/Common.hpp"
#include "../client/client.hpp"
#include <regex>
#include <boost/asio.hpp>
#include "./ShellCommand.hpp"


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
            std::regex rgx("");
            // choose 1st part, and pass the 2nd part to the argument as string to the cmd execute(std::string args) method 
            // or create map and execute(std::map<std::string,std::string>);
            /// here we need to split our command with

            [&](){
                if(cmd.count(str) <= 0){
                    std::cout << std::string("Command '"  + str +"' not found\n");
                }
                else {
                    // add flags pass mechanism
                    /// here we need to split our command with
                    hist.push_back(str);                  
                    cmd[str]->execute();// pass flags
                }
            }() ;  
        }
    }
    catch(const ClosedSession& e)
    {
        std::cerr << e.what() << '\n'; // override here
        work_after(cli);
    }
    catch(boost::system::system_error& err){
        std::cout << err.what() <<std::endl;
    }
}