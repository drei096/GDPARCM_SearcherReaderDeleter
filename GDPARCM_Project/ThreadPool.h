#pragma once

#include <queue>
#include <unordered_map>

#include "IFinishedTask.h"
#include "ThreadObject.h"

class PoolWorkerThread;
class IWorkerAction;
class IFinishedTask;

class ThreadPool : public ThreadObject, public IFinishedTask
{
private:
	std::string name;
	bool isRunning = false;
	int workerCount = 0;
	std::unordered_map<int, PoolWorkerThread*> ActiveThreadMap;
	std::queue<PoolWorkerThread*> InactiveThreadQueue;
	std::queue<IWorkerAction*> PendingActionsQueue;

public:
	ThreadPool(std::string name, int workerCount);
	~ThreadPool();

	void StartScheduler();
	void StopScheduler();
	void ScheduleTask(IWorkerAction* action);

private:
	void Run() override;
	void OnFinishedTask(int threadID) override;

};

