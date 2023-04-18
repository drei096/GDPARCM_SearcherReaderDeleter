#pragma once

#include "ThreadObject.h"

class IWorkerAction;
class IFinishedTask;


class PoolWorkerThread : public ThreadObject
{
public:
	PoolWorkerThread(int id, IFinishedTask* finishedTask);
	~PoolWorkerThread();

	int getThreadID();
	void assignTask(IWorkerAction* action);

private:
	void Run() override;

private:
	int id = 0;
	IWorkerAction* action;
	IFinishedTask* finishedTask;
};

