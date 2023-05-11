#ifndef __USERSHELL_H__
#define __USERSHELL_H__

#include "../Shell.hpp"


class UserShell: public Shell{
public:
    UserShell(std::map<std::string,ShellCommand*> _map,std::list<std::string>  _history);
public:
    void work_after(client& client);
};
#endif