#include "./UserShell.hpp" 
#include "../../client/client.hpp"
UserShell::UserShell(std::map<std::string,ShellCommand*> _map,std::list<std::string>  _history):Shell(_map,_history){
    
}
void UserShell::work_after(client& client){
}
