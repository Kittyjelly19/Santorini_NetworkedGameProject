#include "Client.h"
#include "Util.h"
#include <iostream>
#include <sstream>
#include <thread>


Client::Client()
{
}

Client::~Client()
{
}

bool Client::StartClient(sf::IpAddress& ip)
{
	sf::IpAddress server;
	server = ip;

	if (socket.connect(server, PORT) != sf::Socket::Done)
	{
		return false;
		std::cout << "Connected to server" << server << socket.getRemotePort() << std::endl;
		return true;
	}
		
	
}

void Client::FindClients()
{
	sf::Packet packet;
	int RegMsg = 1;
	packet << RegMsg;
	socket.send(packet);
}

void Client::SendMsg()
{
	sf::Uint32 id = socket.getLocalPort();
	MsgConstruct msg;
	msg.id = id;
	/*std::memcpy(msg.data, msg.msgtype)*/
	sf::Packet packet;
	packet << msg;

	if (socket.send(packet) != sf::Socket::Done)
	{
		std::cerr << "Message send failure :( " << std::endl;
		return;
	}
	std::cout << "Message send success :)" << std::endl;
}

bool Client::ReceiveMsg()
{
	return true;
}



//void Client::RunClientListener()
//{
//	std::thread clientListenerThread([&]() {
//		sf::Packet packet;
//
//		c_socket->receive(packet);
//
//		});
//}
//
//void Client::ConnectClientToHost()
//{
//	isHostingLocally = true;
//	using namespace std::literals::chrono_literals;
//
//	std::thread TcpConnectionThread([&]() {
//		std::this_thread::sleep_for(1s);
//
//		sf::IpAddress ipAddress(sf::IpAddress::LocalHost);
//		c_socket = makeUPtr<sf::TcpSocket>();
//		sf::Packet packet;
//
//		packet.clear();
//		c_socket->setBlocking(true);
//		}
//}




























//bool Client::RunningClient(unsigned short port)
//{
//
//	//Requesting input of server address while the client is not connected. 
//
//	sf::IpAddress serverName;
//	do
//	{
//		cout << "Please Enter The Server Address: ";
//		cin >> serverName;
//	} while (serverName == sf::IpAddress::None);
//
//
//	//Connecting to server and notifying success status. 
//
//	if (clientSocket.connect(serverName, port) != sf::Socket::Done)
//	{
//		return false;
//		cout << "Connection to server: " << serverName << "Successful." << endl;
//	}
//
//	else
//	{
//		cout << "Failed to connect to server: " << serverName << endl;
//	};
//
//
//	//Recieving message from server.
//
//	char in[128];
//	size_t serverReceived;
//
//	if (clientSocket.receive(in, sizeof(in), serverReceived) != sf::Socket::Done)
//	{
//		return false;
//
//		cout << "Received Message from server: \"" << in << "\"" << endl;
//	};
//
//
//	//Replying to server.
//
//	const char out[] = "I am Client 1";
//	if (clientSocket.send(out, sizeof(out)) != sf::Socket::Done)
//	{
//		return false;
//
//		cout << "Message Successfully Sent to server: " << serverName << endl;
//	};
//	return true;
//}