#pragma once

#include <vector>
#include "SemaphoreObject.h"
#include "ConsoleSynchronizer.h"

class SharedDataBuffer
{
public:
	SharedDataBuffer(int numProducers, int numConsumers, ConsoleSynchronizer* syncer);
	~SharedDataBuffer();

	void addItem(int item, int threadID);
	void consumeItem(int threadID);

private:
	std::vector<int> data;
	int numProds;
	int numCons;
	ConsoleSynchronizer* consoleSynchronizer = nullptr;

public:
	SemaphoreObject* mutexSem;
	SemaphoreObject* producerSem;
	SemaphoreObject* consumerSem;
};

