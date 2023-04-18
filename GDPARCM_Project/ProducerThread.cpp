#include "ProducerThread.h"

ProducerThread::ProducerThread(SharedDataBuffer* inDataBuffer, int threadID)
{
	this->dataBuffer = inDataBuffer;
	this->threadID = threadID;
}

ProducerThread::~ProducerThread()
{
}

void ProducerThread::Run()
{
	while(true)
	{
		// attempt to acquire a producer semaphore to allow thread to run
		this->dataBuffer->producerSem->acquire();

		// attempt to acquire the shared mutex to access critical section
		this->dataBuffer->mutexSem->acquire();

		// critical section
		this->dataBuffer->addItem(this->threadID, this->threadID);

		// when adding item is done, indicate to the consumer that they are allowed to consume
		this->dataBuffer->consumerSem->release();

		// release to give others access to the critical section
		this->dataBuffer->mutexSem->release();
	}
	
}
