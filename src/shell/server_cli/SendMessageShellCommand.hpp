#include "../ShellCommand.hpp"

class SendMessageShellCommand : public ShellCommand{
public:
    void execute();
    std::string toString();
};