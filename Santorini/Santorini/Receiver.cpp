#include "Receiver.h"

Receiver::Receiver(std::shared_ptr<sf::TcpSocket> clientSocket, Queue<Message>& q) : client(clientSocket), queue(q)
{
}

//Recieving packets. 
void Receiver::MsgReceive()
{
	while (true)
	{
		sf::Packet packet;
		if (client->receive(packet) != sf::Socket::Done)
		{
			std::cerr << "Error- Could not recieve packet!" << std::endl;
		}
		Message m(packet, client);
		std::cout << "Packet successfully received: " << packet << std::endl;
		//Pushing message into queue. 
		queue.push(m);
	}
}

