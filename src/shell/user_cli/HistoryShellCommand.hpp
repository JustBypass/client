#include "../ShellCommand.hpp"
class HistoryShellCommand :public ShellCommand{
public:
     void execute();
     std::string toString();
};