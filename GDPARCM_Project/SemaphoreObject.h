#pragma once

#include <semaphore>
#include <mutex>

class SemaphoreObject
{
public:
	SemaphoreObject(int available);
	~SemaphoreObject();

	void acquire() const;
	void acquire(int permits) const;
	void release() const;
	void release(int permits) const;

private:
	const static int GLOBAL_MAX_PERMITS = 1000;
	typedef std::counting_semaphore<GLOBAL_MAX_PERMITS> Semaphore;
	Semaphore* semaphore;
};

