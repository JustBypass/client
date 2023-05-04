#include "./HistoryShellCommand.hpp"
#include "../../tools/Common.hpp"
void HistoryShellCommand::execute()
{
    std::cout << toString();
}

std::string HistoryShellCommand::toString()
{   
    std::string str = "history: \n";
    int i = 1;
    for(std::list<std::string>::const_iterator iter = history.begin();iter != history.end();++iter){
       // str += '\t'+(i++)+". " + (iter) + '\n';
        str += '\t';
        str += i++;
        str += ". ";
        str += *iter;
        str += '\n';
    }
    return str;
}