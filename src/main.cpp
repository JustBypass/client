
#include "./shell/Shell.hpp"
#include "./client/client.hpp"
class ShellCommand;

std::map<std::string,ShellCommand*> allCommands;
std::list<std::string> history;

//tcp::acceptor acceptor(service, tcp::endpoint(tcp::v4(),9090));
boost::asio::io_service IOservice;

tcp::endpoint ep(ip::address::from_string("127.0.0.1"),8125);

client cli(IOservice,ep);

int main(){
	try{
        Shell shell;
        shell.launch();
	}catch(std::exception& ex){
		std::cout<< "Exception";
	}
	return 0;
}