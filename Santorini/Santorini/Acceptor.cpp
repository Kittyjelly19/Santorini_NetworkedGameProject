#include "Acceptor.h"



Acceptor::Acceptor(Queue<Message>& q) : queue(q)
{
}

//Connecting a client to the server. 
void Acceptor::ConnectionAccepted()
{
	sf::TcpListener listener;
	if (listener.listen(S_PORT) != sf::Socket::Done)
		return;
	std::cout << "server is listening to port: " << C_PORT << "waiting for connections" << std::endl;

	while (true)
	{
		bool connectionMsg = false;

		std::shared_ptr<sf::TcpSocket> client = std::make_shared<sf::TcpSocket>();

		if (listener.accept(*client) != sf::Socket::Done)
			return;
		//Get the port of the client and display in output window. 
		unsigned short clientPort = client->getRemotePort();
		std::cout << "Client connected. Client IP is: " << client->getRemoteAddress()<< "client port: " << clientPort << std::endl;

		connectionMsg = true;

		std::shared_ptr<Receiver>receiver = std::make_shared<Receiver>(client, queue);
		std::thread(&Receiver::MsgReceive, receiver).detach();
	}
}