#include "../ShellCommand.hpp"
class DisconnectShellCommand: public ShellCommand{
    void execute();
    std::string toString();
};