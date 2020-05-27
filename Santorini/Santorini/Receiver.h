#pragma once
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Server.h"
#include "Queue.h"


class Receiver
{
private:
	//Received message queue.
	Queue<Message>& queue;
	std::shared_ptr<sf::TcpSocket> client;
	
	//map of client tcp sockets. 
	std::map<unsigned short, std::shared_ptr<sf::TcpSocket>> clients;

public:
	//Recieving the message
	Receiver(std::shared_ptr<sf::TcpSocket> clientSocket, Queue<Message>& q);

	
	void MsgReceive();
};

