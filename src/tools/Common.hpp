#ifndef COMMON_HPP
#define COMMON_HPP

#include <map>
#include <string>
#include <list>
#include <boost/asio.hpp>
class ShellCommand;
class client;

    extern std::map<std::string,ShellCommand*> allUserCommands;
    extern std::list<std::string> userHistory;

    extern std::map<std::string,ShellCommand*> allServerCommands;
    extern std::list<std::string> serverHistory;

    extern client cli;
    extern boost::asio::io_context IOservice;
#endif