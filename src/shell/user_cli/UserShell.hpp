#ifndef __USERSHELL_H__
#define __USERSHELL_H__

#include <list>
#include <vector>
#include <map>
#include "../Shell.hpp"
class ShellCommand;

class UserShell: public Shell{
public:
  UserShell(std::map<std::string,ShellCommand*> _map,std::list<std::string>  _history);
};
#endif