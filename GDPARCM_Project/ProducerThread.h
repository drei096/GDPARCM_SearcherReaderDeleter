#pragma once

#include "ThreadObject.h"
#include "SemaphoreObject.h"
#include "SharedDataBuffer.h"

class ProducerThread : public ThreadObject
{
public:
	ProducerThread(SharedDataBuffer* inDataBuffer, int threadID);
	~ProducerThread();

	void Run() override;

private:
	int threadID;
	SharedDataBuffer* dataBuffer;
};

