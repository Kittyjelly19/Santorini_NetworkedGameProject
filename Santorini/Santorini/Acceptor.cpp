#include "Acceptor.h"


//Constructor.
Acceptor::Acceptor(Queue<Message>& q) : queue(q)
{
}

//Connecting a client to the server. 
void Acceptor::ConnectionAccepted()
{
	sf::TcpListener listener;
	if (listener.listen(S_PORT) != sf::Socket::Done)
		return;
	std::cout << "server is listening... " <<  std::endl;

	while (true)
	{
		bool connectionMsg = false;

		std::shared_ptr<sf::TcpSocket> client = std::make_shared<sf::TcpSocket>();

		if (listener.accept(*client) != sf::Socket::Done)
			return;
		//Get the port of the client and display in output window if connection successful.
		unsigned short cPort = client->getRemotePort();
		std::cout << "Client Successfully Connected. Client IP address is: " << client->getRemoteAddress()<< "and they're on port: " << cPort << std::endl;

		connectionMsg = true;

		std::shared_ptr<Receiver>receiver = std::make_shared<Receiver>(client, queue);
		std::thread(&Receiver::MsgReceive, receiver).detach();
	}
}