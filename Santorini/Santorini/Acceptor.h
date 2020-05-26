#pragma once
#include "Server.h"
#include "Receiver.h"
#include "Queue.h"
class Acceptor
{
private:
	Queue<Message>& queue;
public:
	Acceptor(Queue < Message>& q);


	void ConnectionAccepted();
};

