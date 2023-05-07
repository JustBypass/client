#include "../Shell.hpp"
#include <map>
#include <string>
#include <list>

class ShellCommand;

class ServerShell : public Shell{
public:
    ServerShell::ServerShell(std::map<std::string,ShellCommand*> _map,std::list<std::string>  _history);

};