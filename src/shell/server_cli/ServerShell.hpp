#ifndef __SERVERSHELL_H__
#define __SERVERSHELL_H__

#include "../Shell.hpp"


class ServerShell : public Shell{
public:
    ServerShell(std::map<std::string,ShellCommand*> _map,std::list<std::string>  _history);
public:
    void work_after(client& client);
};

#endif