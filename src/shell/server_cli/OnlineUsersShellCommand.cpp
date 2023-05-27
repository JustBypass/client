#include "./OnlineUsersShellCommand.hpp"
#include "../../tools/Common.hpp"
#include "../../builders/meter.hpp"
#include "../../client/client.hpp"

#include "../../parser/iparser.hpp"

void OnlineUsersShellCommand::execute(){
    boost::shared_ptr<meter> _meter(new meter());
    boost::shared_ptr<iparser> parser(new iparser());

    std::string res = _meter->convert(cli.name,cli.name,2,"");
    std::cout <<std::string("Send str = " )+ res <<std::endl;
    cli.sock->write_some(boost::asio::buffer(res));
    std::cout <<"write_some passed\n";

    int sizes[4];
    cli.sock->read_some(boost::asio::buffer(sizes,16));
    std::cout <<"read_some passed\n";

    int sum = sizes[0] +sizes[1] +sizes[2]+sizes[3];


    std::string read;
    read.resize(sum);
    cli.sock->read_some(boost::asio::buffer(read,sum));
    std::cout <<"another read_some passed\n";


    std::cout <<read<<std::endl;
  //  std::cout <<parser->parseBody(read);

}

std::string OnlineUsersShellCommand::toString(){
    return "";
}