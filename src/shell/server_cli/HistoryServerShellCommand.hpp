#include "./ShellCommand.hpp"

class HistoryServerShellCOmmand: public ShellCOmmand{
    void execute();
    std::string toString();
};