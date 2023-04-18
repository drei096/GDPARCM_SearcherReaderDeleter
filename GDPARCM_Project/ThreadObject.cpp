#include "ThreadObject.h"

ThreadObject::ThreadObject()
{
}

ThreadObject::~ThreadObject()
{
}

void ThreadObject::ScheduleThreadForExecution()
{
	//std::thread(&ThreadObject::Run, this).join();

	std::thread(&ThreadObject::Run, this).detach(); //detach thread for independent execution. without this, join() function must be called.
}

void ThreadObject::Sleep(int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

