#include "./UserShell.hpp" 

UserShell::UserShell(std::map<std::string,ShellCommand*> _map,std::list<std::string>  _history):Shell(_map,_history){
    
}
 