//#include "../../tools/Common.hpp"
#include "./ServerShell.hpp"
//#include "../../client/client.hpp"
 //#include <boost/asio.hpp>

ServerShell::ServerShell(std::map<std::string,ShellCommand*> _map,std::list<std::string>  _history):Shell(_map,_history){
    
}
void ServerShell::work_after(client& client){
  //  client.sock->shutdown(boost::asio::ip::tcp::socket::shutdown_both);
	//client.sock->close();	
}
