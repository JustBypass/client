#include "../ShellCommand.hpp"


class OnlineUsersShellCommand : public ShellCommand{
    void execute();
    std::string toString();
};