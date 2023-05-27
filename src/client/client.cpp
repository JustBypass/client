#include "./client.hpp"
#include "../tools/Common.hpp"
#include <boost/thread/thread.hpp>
#include <boost/asio.hpp>
#include "../shell/server_cli/ServerShell.hpp"
#include <regex>
#include "..//tools/Flags.hpp"
#include <experimental/filesystem>
#include <fstream>
#include <utility>
#include "../builders/meter.hpp"
#include <boost/shared_ptr.hpp>

auto decode(std::string data)
{
    std::string file_name;
    std::string body;

    std::regex rgx1("name:(.*),");
    std::regex rgx2("'(.*)'");

    std::smatch match;
    if (std::regex_search(data, match, rgx1) && std::regex_search(data, match, rgx2))
    {
        file_name = std::string(match[1]);
        body = std::string(match[2]);
    }

    return std::make_pair(file_name, body);
}

void client::print_new()
{
    std::cout << "print_new()\n"; // decorate
    std::string message = message_now;
    std::regex rgx1("from:(.*)\\n");
    std::regex rgx2("data:'(.*)'");
    std::regex rgx3("flag:(.*)\\n");

    size_t flag;
    std::string from;
    std::string data;

    std::smatch match;
    if (std::regex_search(message, match, rgx1) && std::regex_search(message, match, rgx2) && std::regex_search(message, match, rgx3))
    {

        flag = std::stoi(std::string(match[3])); // reinterpret_cast<int>(std::string(match[3]));
        from = std::string(match[1]);
        data = std::string(match[2]);

        switch (flag)
        {
        case (Flags::Request::_FILE):
        {

            std::pair<std::string, std::string> decoded_data = decode(data);

            std::string file_name = decoded_data.first;
            std::string file_data = decoded_data.second;

            std::experimental::filesystem::path file_path(std::string("~/") + file_name);
            std::ofstream file(file_name);
            if (!file.is_open())
            {
                file.open(file_path, std::ios::binary);
                file << file_data;
                file.close();
                std::cout << from + " sent you 1 file[" + file_name + "]\n"; // add date
            }
        }
        case (Flags::Request::_MSG):
        {
            std::cout << from + ": " + data + '\n';
        }
        }
    }
}

void client::start_handle_new()
{
    message_now.clear();
    boost::asio::async_read(*sock, boost::asio::buffer(sizes, 16),
                            boost::bind(&client::header, this, boost::asio::placeholders::error));

    IOservice.run();
}

void client::read_body(const boost::system::error_code &ec)
{
    std::cout << "read body()\n";

    if (!ec) // check the length of header
    {
        std::cout << message_now.data() << std::endl;
        print_new();

        boost::asio::async_read(*sock, boost::asio::buffer(sizes, 16),
                                boost::bind(&client::header, this, boost::asio::placeholders::error));
    }
}

void client::header(const boost::system::error_code &ec)
{
    if (!ec)
    {
        std::cout << "header()" << std::endl;

        int size = sizes[0] + sizes[1] + sizes[2] + sizes[3];
        std::cout << size << std::endl;
        message_now.resize(size);

        boost::asio::async_read(*sock, boost::asio::buffer(message_now.data(), size),
                                boost::bind(&client::read_body, this, boost::asio::placeholders::error));
    }

    std::cout << "~header()\n";
}

void server_shell_loop()
{
    ServerShell shell(allServerCommands, serverHistory);
    shell.launch();
}

void client::connect(std::string ip, int port)
{
    try
    {
        boost::thread_group threads;

        tcp::resolver res(IOservice);

        boost::shared_ptr<meter> _meter(new meter());

        tcp::resolver::results_type endpoints = res.resolve(ip, std::to_string(port));
        boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string(ip), port);
        boost::asio::connect(*cli.sock, endpoints);
        auto greeting = _meter->greetingMessage(cli.name);
        cli.sock->send(boost::asio::buffer(greeting, greeting.size()));

        std::cout << "Greeting message sent!\n";

        threads.create_thread(boost::bind(&client::start_handle_new,this));
        threads.create_thread(boost::bind(server_shell_loop));
        threads.join_all();

        IOservice.run();
    }
    catch (const boost::system::system_error &err)
    {
        std::cout << err.what() << std::endl;
    }
}

client::client(io_context &s) : sock(new tcp::socket(s)) {}