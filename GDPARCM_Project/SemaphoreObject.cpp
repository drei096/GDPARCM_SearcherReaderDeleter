#include "SemaphoreObject.h"

SemaphoreObject::SemaphoreObject(int available)
{
	this->semaphore = new Semaphore(available);
}

SemaphoreObject::~SemaphoreObject()
{
	delete this->semaphore;
}

void SemaphoreObject::acquire() const
{
	this->semaphore->acquire();
}

void SemaphoreObject::acquire(int permits) const
{
	for(int i = 0; i < permits; i++)
	{
		this->semaphore->acquire();
	}
}

void SemaphoreObject::release() const
{
	this->semaphore->release();
}

void SemaphoreObject::release(int permits) const
{
	this->semaphore->release(permits);
}
