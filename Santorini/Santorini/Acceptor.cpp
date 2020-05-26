#include "Acceptor.h"

void Acceptor::ConnectionAccepted()
{
	sf::TcpListener listener;
	if (listener.listen(PORT) != sf::Socket::Done)
		return;
	std::cout << "server is listening to port: " << PORT << "waiting for connections" << std::endl;

	while (true)
	{
		bool connectMsg = false;

		std::shared_ptr<sf::TcpSocket> client = std::make_shared<sf::TcpSocket>();

		if (listener.accept(*client) != sf::Socket::Done)
			return;
		unsigned short clientPort = client->getRemotePort();
		std::cout << "Client connected. Client IP is: " << client->getRemoteAddress()<< "client port: " << clientPort << std::endl;

		connectMsg = true;

		if (connectMsg)
		{
			const char out[] = "I am the server";
			if (client->send(out, sizeof(out)) != sf::Socket::Done)
				return;
				connectMsg = false;
		}
		std::shared_ptr<Receiver>receiver = std::make_shared<Receiver>(client, queue);
		std::thread(&Receiver::MsgReceive, receiver).detach();
	}
}