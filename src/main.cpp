#include "./shell/user_cli/UserShell.hpp"
#include "./client/client.hpp"
#include "./shell/user_cli/HistoryShellCommand.hpp"
#include "./shell/user_cli/HelpShellCommand.hpp"
#include "./shell/user_cli/ExitShellCommand.hpp"
#include "./shell/user_cli/ConnectShellCommand.hpp"
#include "./shell/server_cli/DisconnectShellCommand.hpp"
#include "./shell/server_cli/SendMessageShellCommand.hpp"
#include "./shell/server_cli/OnlineUsersShellCommand.hpp"
#include <list>

class ShellCommand;

std::map<std::string,ShellCommand*> allUserCommands;
std::list<std::string> userHistory;

std::map<std::string,ShellCommand*> allServerCommands;
std::list<std::string> serverHistory;

void init(){
	allUserCommands.insert(std::make_pair(std::string("help"),new HelpShellCommand()));
    allUserCommands.insert(std::make_pair(std::string("exit"),new ExitShellCommand()));
    allUserCommands.insert(std::make_pair(std::string("cn"),new ConnectShellCommand()));
    allUserCommands.insert(std::make_pair(std::string("disconnect"),new ConnectShellCommand()));
    allUserCommands.insert(std::make_pair(std::string("msgs"),new ConnectShellCommand()));
    allUserCommands.insert(std::make_pair(std::string("hist"),new HistoryShellCommand()));
    allUserCommands.insert(std::make_pair(std::string("online"),new ConnectShellCommand()));

	allServerCommands.insert(std::make_pair(std::string("cr"),new SendMessageShellCommand()));
    allServerCommands.insert(std::make_pair(std::string("onl"),new OnlineUsersShellCommand()));
    //allServerCommands.insert(std::make_pair(std::string("onl"),new DisconnectShellCommand()));
   // allServerCommands.insert(std::make_pair(std::string("ch"),new HistoryServerShellCommand()));
   // allServerCommands.insert(std::make_pair(std::string("dis"),new DisconnectShellCommand()));
};



boost::asio::io_context IOservice;

//tcp::endpoint ep(ip::address::from_string("127.0.0.1"),8125);

client cli(IOservice);

int main(){
	try{
        init();
        UserShell shell(allUserCommands,userHistory);
        shell.launch();
	}catch(std::exception& ex){
		std::cout<< "Exception";
	}
	return 0;
}