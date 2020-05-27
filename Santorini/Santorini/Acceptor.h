#pragma once
#include "Server.h"
#include "Receiver.h"
#include "Queue.h"
class Acceptor
{
private:
	 
	Queue<Message>& queue;
public:
	//Queue for storing accepted messages
	Acceptor(Queue < Message>& msgq);


	void ConnectionAccepted();
};

