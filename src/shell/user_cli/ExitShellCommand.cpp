   #include "./ExitShellCommand.hpp"

   void ExitShellCommand::execute(){
        throw ClosedSession(toString());
    }
    std::string ExitShellCommand::toString(){
        return "Connection Closed\n";
    }