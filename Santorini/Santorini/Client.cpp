#include "Client.h"
#include <iostream>
#include <sstream>
#include <thread>


Client::Client()
{
}

Client::~Client()
{
}





bool Client::RunningClient(unsigned short port)
{

	//Requesting input of server address while the client is not connected. 

	sf::IpAddress serverName;
	do
	{
		cout << "Please Enter The Server Address: ";
		cin >> serverName;
	} while (serverName == sf::IpAddress::None);


	////Connecting to server and notifying success status. 

	//if (clientSocket.connect(serverName, port) != sf::Socket::Done)
	//{
	//	return false;
	//	cout << "Connection to server: " << serverName << "Successful." << endl;
	//}

	//else
	//{
	//	cout << "Failed to connect to server: " << serverName << endl;
	//};


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
	return true;
}