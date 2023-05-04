#include "../ClosedSession.hpp"
#include "../ShellCommand.hpp"
class ExitShellCommand : public ShellCommand{
public:
    void execute();
    std::string toString();
    ~ExitShellCommand(){}

};