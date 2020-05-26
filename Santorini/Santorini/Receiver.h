#pragma once
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Server.h"
#include "Queue.h"


class Receiver
{
private:
	Queue<Message>& queue;
	std::shared_ptr<sf::TcpSocket> client;
	std::map<unsigned short, std::shared_ptr<sf::TcpSocket>> clients;

public:
	Receiver(std::shared_ptr<sf::TcpSocket> clientSocket, Queue<Message>& q);

	void MsgReceive();
};

