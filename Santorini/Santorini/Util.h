#pragma once
#include<SFML/Network.hpp>
#include <functional>
#include<memory>

#define PORT 5000
#define UPORT 5100

//#define uPtr std::unique_ptr
//#define makeUPtr std::make_unique

using Message = std::pair<sf::Packet, std::shared_ptr<sf::TcpSocket>>;
void UtilRun(std::function<sf::Socket::Status(void)> f, std::string utilerror);

class Util
{
};

