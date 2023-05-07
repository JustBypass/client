//#include "../../tools/Common.hpp"
#include "./ServerShell.hpp"

ServerShell::ServerShell(std::map<std::string,ShellCommand*> _map,std::list<std::string>  _history):Shell(_map,_history){}