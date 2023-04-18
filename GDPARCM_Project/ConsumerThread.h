#pragma once

#include "ThreadObject.h"
#include "SemaphoreObject.h"
#include "SharedDataBuffer.h"

class ConsumerThread : public ThreadObject
{
public:
	ConsumerThread(SharedDataBuffer* inDataBuffer, int threadID);
	~ConsumerThread();

	void Run() override;

private:
	int threadID;
	SharedDataBuffer* dataBuffer;
};

