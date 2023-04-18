#include "PoolWorkerThread.h"

#include "IFinishedTask.h"
#include "IWorkerAction.h"

PoolWorkerThread::PoolWorkerThread(int id, IFinishedTask* finishedTask)
{
	this->id = id;
	this->finishedTask = finishedTask;
}

PoolWorkerThread::~PoolWorkerThread()
{
}

int PoolWorkerThread::getThreadID()
{
	return id;
}

void PoolWorkerThread::assignTask(IWorkerAction* action)
{
	this->action = action;
}

void PoolWorkerThread::Run()
{
	this->action->OnStartTask();
	this->finishedTask->OnFinishedTask(this->id);
}
