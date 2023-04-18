#include "ThreadPool.h"

#include "PoolWorkerThread.h"

ThreadPool::ThreadPool(std::string name, int workerCount)
{
	this->name = name;
	this->workerCount = workerCount;

	for(int i = 0; i < workerCount; i++)
	{
		PoolWorkerThread* temp = new PoolWorkerThread(i, this);
		this->InactiveThreadQueue.push(temp);
	}
}

ThreadPool::~ThreadPool()
{
	StopScheduler();
	ActiveThreadMap.clear();
	while (!InactiveThreadQueue.empty())
		InactiveThreadQueue.pop();

}

void ThreadPool::StartScheduler()
{
	this->isRunning = true;
	this->ScheduleThreadForExecution();
}

void ThreadPool::StopScheduler()
{
	this->isRunning = false;
}

void ThreadPool::ScheduleTask(IWorkerAction* action)
{
	this->PendingActionsQueue.push(action);
}

void ThreadPool::Run()
{
	while(this->isRunning)
	{
		if(this->PendingActionsQueue.empty() == false && this->InactiveThreadQueue.empty() == false)
		{
			PoolWorkerThread* newPoolWorkerThread = this->InactiveThreadQueue.front();
			newPoolWorkerThread->assignTask(this->PendingActionsQueue.front());
			this->ActiveThreadMap[newPoolWorkerThread->getThreadID()] = newPoolWorkerThread;

			this->InactiveThreadQueue.pop();
			this->PendingActionsQueue.pop();

			newPoolWorkerThread->ScheduleThreadForExecution();
		}
	}
}

void ThreadPool::OnFinishedTask(int threadID)
{
	if(this->ActiveThreadMap[threadID] != nullptr)
	{
		this->ActiveThreadMap.erase(threadID);
		delete this->ActiveThreadMap[threadID];

		PoolWorkerThread* newPoolWorkerThread = new PoolWorkerThread(threadID, this);
		this->InactiveThreadQueue.push(newPoolWorkerThread);
		
	}
}
