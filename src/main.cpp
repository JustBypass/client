#include "./shell/user_cli/UserShell.hpp"
#include "./client/client.hpp"
#include "./user_cli/HistoryShellCommand.hpp"
#include "./user_cli/HelpShellCommand.hpp"
#include "./user_cli/ExitShellCommand.hpp"
#include "./user_cli/ConnectShellCommand.hpp"
#include "./server_cli/DisconnectShellCommand.hpp"
#include "./server_cli/SendMessageShellCommand.hpp"
#include <list>

class ShellCommand;

std::map<std::string,ShellCommand*> allUserCommands;
std::list<std::string> userHistory;

std::map<std::string,ShellCommand*> allServerCommands;
std::list<std::string> serverHistory;

[&](){
	allUserCommands.insert(std::make_pair(std::string("help"),new HelpShellCommand()));
    allUserCommands.insert(std::make_pair(std::string("exit"),new ExitShellCommand()));
    allUserCommands.insert(std::make_pair(std::string("connect"),new ConnectShellCommand()));
    allUserCommands.insert(std::make_pair(std::string("disconnect"),new ConnectShellCommand()));
    allUserCommands.insert(std::make_pair(std::string("messages"),new ConnectShellCommand()));
    allUserCommands.insert(std::make_pair(std::string("history"),new HistoryShellCommand()));
    allUserCommands.insert(std::make_pair(std::string("online"),new ConnectShellCommand()));

	allServerCommands.insert(std::make_pair(std::string("create"),new SendMessageShellCommand()));
    allServerCommands.insert(std::make_pair(std::string("online_count"),new DisconnectShellCommand()));
    allServerCommands.insert(std::make_pair(std::string("change_room"),new HistoryServerShellCommand()));
    allServerCommands.insert(std::make_pair(std::string("disconnect"),new DisconnectShellCommand()));
}();

boost::asio::io_service IOservice;

//tcp::endpoint ep(ip::address::from_string("127.0.0.1"),8125);

client cli(IOservice);

int main(){
	try{
        UserShell shell(allUserCommands,userHistory);
        shell.launch();
	}catch(std::exception& ex){
		std::cout<< "Exception";
	}
	return 0;
}