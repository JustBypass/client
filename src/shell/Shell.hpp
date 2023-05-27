#include <map>
#include <string>
#include <list>

class ShellCommand;
class client;

class Shell{
public:
    void launch();
public:
    Shell(std::map<std::string,ShellCommand*> _cmd,std::list<std::string> _hist):cmd(_cmd),hist(_hist){};
    virtual void mode();

    virtual void work_after(client& client) = 0;
    virtual ~Shell(){}
private:
    std::map<std::string,ShellCommand*> cmd;
    std::list<std::string> hist;
};
