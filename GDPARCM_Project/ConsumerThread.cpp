#include "ConsumerThread.h"

ConsumerThread::ConsumerThread(SharedDataBuffer* inDataBuffer, int threadID)
{
	this->dataBuffer = inDataBuffer;
	this->threadID = threadID;
}

ConsumerThread::~ConsumerThread()
{
}

void ConsumerThread::Run()
{
	while(true)
	{
		// when the producer releases a consumerSem, attempt to acquire a consumerSem to allow thread to run
		this->dataBuffer->consumerSem->acquire();

		// attempt to acquire mutex sem to gain access to critical section
		this->dataBuffer->mutexSem->acquire();

		// critical section
		this->dataBuffer->consumeItem(this->threadID);

		// after consuming, indicate to the producer that it is able to produce again
		this->dataBuffer->producerSem->release();

		// release mutex to give others access to critical section
		this->dataBuffer->mutexSem->release();
	}
	
}
