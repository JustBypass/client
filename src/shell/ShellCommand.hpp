#include <iostream>
#include <string>
#include <map>
#ifndef __SHELLCOMMAND_H__
#define __SHELLCOMMAND_H__

class ShellCommand{
public:
    virtual void execute() = 0;
   // virtual void execute(std::map<std::string,std::string> args) ; 
    //virtual void execute(std::string args);

   // virtual void cancel();   
    virtual std::string toString() = 0;
    virtual ~ShellCommand(){}
};

#endif