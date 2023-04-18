#pragma once

#include <iostream>
#include <thread>

class ThreadObject
{
public:
	ThreadObject();
	~ThreadObject();

	void ScheduleThreadForExecution();
	static void Sleep(int milliseconds);

protected:
	virtual void Run() = 0;
};

