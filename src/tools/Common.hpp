#ifndef COMMON_HPP
#define COMMON_HPP

#include <map>
#include <string>
#include <list>
#include <boost/asio.hpp>
class ShellCommand;
class client;

extern std::map<std::string,ShellCommand*> allCommands;
extern std::list<std::string> history;
extern client cli;
extern boost::asio::io_service IOservice;
#endif