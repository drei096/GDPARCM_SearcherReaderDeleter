#include "SharedDataBuffer.h"

#include <iostream>
#include <string>

SharedDataBuffer::SharedDataBuffer(int numProducers, int numConsumers, ConsoleSynchronizer* syncer)
{
	this->numProds = numProducers;
	this->numCons = numConsumers;

	this->mutexSem = new SemaphoreObject(1);
	this->producerSem = new SemaphoreObject(this->numProds);
	this->consumerSem = new SemaphoreObject(0);

	this->consoleSynchronizer = syncer;
}

SharedDataBuffer::~SharedDataBuffer()
{
}

void SharedDataBuffer::addItem(int item, int threadID)
{
	data.push_back(item);
	std::string newMessage = "Producer " + std::to_string(threadID) + " successfully added item: " + std::to_string(item) + " to the list. List size: " + std::to_string(data.size());
	//std::cout << "Producer " << threadID << " successfully added item: " << item << " to the list. List size:" << data.size() << std::endl;

	consoleSynchronizer->UpdateMessage(newMessage);
	consoleSynchronizer->Update();
}

void SharedDataBuffer::consumeItem(int threadID)
{
	std::string newMessage = "Consumer " + std::to_string(threadID) + " consumed an item:" + std::to_string(data.front()) + " from the list. ";
	//std::cout << "Consumer " << threadID << " consumed an item: " << data.front() << " to the list.";
	data.erase(data.begin());
	data.shrink_to_fit();
	newMessage = newMessage + "List size: " + std::to_string(data.size());
	//std::cout << " List size : " << data.size() << std::endl;
	
	consoleSynchronizer->UpdateMessage(newMessage);
	consoleSynchronizer->Update();
}
