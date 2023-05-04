     #include "./HelpShellCommand.hpp"
     void HelpShellCommand::execute(){
        std::cout<<toString();
        std::cin.get();
       // printf("\033c");
    }
    std::string HelpShellCommand::toString(){
        return "Usage: \n\tmy_program command --option <argument>\n\tmy_program [<optional-argument>]\n\tmmy_program --another-option=<with-argument>\n\tmmy_program (--either-that-option | <or-this-argument>)\n\tmmy_program <repeating-argument> <repeating-argument>...\n";
    }