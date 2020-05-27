#include "Message.h"
#include "World.h"

//Overload operator definitions for Message type.
sf::Packet& operator << (sf::Packet& packet, const MessageType mtype)
{
	sf::Uint8 r = static_cast<sf::Uint8>(mtype);
	return packet << r;
}

sf::Packet& operator >> (sf::Packet& packet, MessageType& mtype)
{
	sf::Uint8 r;
	packet >> r;
	mtype = static_cast<MessageType>(r);
	return packet;
}

//Overload operator definitions for Message construction. 
sf::Packet& operator << (sf::Packet& packet, const MsgConstruct msg)
{
	return packet << msg.msgtype << msg.id << msg.data;
}

sf::Packet& operator >> (sf::Packet& packet, MsgConstruct& msg)
{
	return packet >> msg.msgtype >> msg.id >> msg.data;
}


//Overload operator definitions for Registration message. 
sf::Packet& operator << (sf::Packet& packet, const RegistrationMsg msg)
{
	return packet << msg.msgtype << msg.id << msg.username;
}

sf::Packet& operator >> (sf::Packet& packet, RegistrationMsg& msg)
{
	return packet >> msg.msgtype >> msg.id >> msg.username;
}

//Overload operator definitions for StartGame message.
sf::Packet& operator << (sf::Packet& packet, const StartGameMsg msg)
{
	return packet << msg.msgtype;
}

sf::Packet& operator >> (sf::Packet& packet, StartGameMsg& msg)
{
	return packet >> msg.msgtype;
}

//Reading different message types.
void ReadMessage(Message m, MsgConstruct& msg)
{
	RegistrationMsg* m_registration;
	std::stringstream ss;

	m.first >> msg.msgtype;
		switch (msg.msgtype)
		{
			//Register message type.
		case MessageType::RegisterMsg:
			m_registration = new RegistrationMsg();
			if (m.first >> m_registration->id >> m_registration->username)
			{
				std::memcpy(&msg, m_registration, sizeof(RegistrationMsg));
			}
			else
			{
				ss << "Register message not understood" << std::endl;
			}
			delete m_registration;
			break;
			//Start game message type. 
		case MessageType::StartGameMsg:
			Game* Setup();
			break;
			
		}
}
