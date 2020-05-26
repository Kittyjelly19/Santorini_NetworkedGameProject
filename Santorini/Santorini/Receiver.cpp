#include "Receiver.h"

Receiver::Receiver(std::shared_ptr<sf::TcpSocket> clientSocket, Queue<Message>& q) : client(clientSocket), queue(q)
{
}

void Receiver::MsgReceive()
{
	while (true)
	{
		sf::Packet packet;
		if (client->receive(packet) != sf::Socket::Done)
		{
			std::cerr << "failed to recieve packet." << std::endl;
		}
		Message m(packet, client);
		std::cout << "received:" << packet << std::endl;
		queue.push(m);
	}
}

