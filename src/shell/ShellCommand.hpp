#include <iostream>
#include <string>

#ifndef __SHELLCOMMAND_H__
#define __SHELLCOMMAND_H__
class ShellCommand{
public:
    virtual void execute() = 0;
   // virtual void cancel();   
    virtual std::string toString() = 0;
    virtual ~ShellCommand(){}
};

#endif