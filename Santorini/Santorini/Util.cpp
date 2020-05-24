#include "Util.h"
#include <iostream>
#include <cstring>

#define BUFFER_SIZE 1024
std::string receive(sf::UdpSocket& socket, sf::IpAddress sender, unsigned short& port)
{
	char buffer[BUFFER_SIZE];
	std::size_t received;

	std::memset(buffer, 0, BUFFER_SIZE);
	if (socket.receive(buffer, BUFFER_SIZE, received, sender, port) != sf::Socket::Done)
	{
		std::cerr << "Error Receiving!" << std::endl;
		perror("receive");
		exit(0);
	}
	std::cout << "Received \"" << std::string(buffer) << "\" from " << sender << "on" << port << std::endl;
	return std::string(buffer);
}

void UtilRun(std::function<sf::Socket::Status(void)> f, std::string utilerror)
{
	sf::Socket::Status socketStatus = f();

	if (socketStatus != sf::Socket::Done)
	{
		std::cerr << "Could not " << utilerror << " : " << socketStatus << std::endl;
		perror(utilerror.c_str());
		exit(0);
	}

}
