#pragma once
#include <SFML/Network.hpp>
#include <cstring>
#include <string>
#include <iostream>
#include <memory>
#include <sstream>
#include "Util.h"

enum class MessageType : sf::Uint8
{
	RegisterMsg = 1,
	StartGameMsg = 2,
	PlaceMsg = 4,
	SelectMsg = 8,
	MoveMsg = 16,
	BuildMsg = 32,
	Undefined = 64
};

//Overload operators for message type. 
sf::Packet& operator << (sf::Packet& packet, const MessageType mtype);
sf::Packet& operator >> (sf::Packet& packet, MessageType& mtype);

//Message Construction.
struct MsgConstruct
{
	MessageType msgtype = MessageType::Undefined;
	sf::Uint32 id;
	char data[216];
};

//Overload operators for message construction. 
sf::Packet& operator << (sf::Packet& packet, const MsgConstruct msg);
sf::Packet& operator >> (sf::Packet& packet, MsgConstruct& msg);

//Structure of Registration message contents. 
struct RegistrationMsg
{
	MessageType msgtype = MessageType::RegisterMsg;
	sf::Uint32 id = 0;
	std::string username;
	RegistrationMsg() {}
	RegistrationMsg(sf::Uint32 id_, std::string s) : id(id_), username(s) {}
};

//Overload operators for registration message structure. 
sf::Packet& operator << (sf::Packet& packet, const RegistrationMsg msg);
sf::Packet& operator >> (sf::Packet& packet, RegistrationMsg& msg);

struct StartGameMsg
{
	MessageType msgtype = MessageType::StartGameMsg;

};

sf::Packet& operator << (sf::Packet& packet, const StartGameMsg msg);
sf::Packet& operator >> (sf::Packet& packet, StartGameMsg& msg);

typedef std::pair<sf::Packet, std::shared_ptr<sf::TcpSocket>> Message;

void ReadMessage(Message m, MsgConstruct& msg);


//class Message
//{
//private:
//public:
//	Message();
//	~Message();
//
//	sf::Packet packet;
//	std::shared_ptr<sf::TcpSocket> client;
//	
//	//default message type is undefined. 
//	MessageType messageType = MessageType::Undefined;
//};

