#pragma once

#include "ThreadObject.h"
#include "IWorkerAction.h"

class IExecutionEvent;

class AssetLoaderThread : public IWorkerAction
{
public:
	AssetLoaderThread(std::string path, IExecutionEvent* execution_event);
	~AssetLoaderThread();

	//void Run() override;

private:
	std::string asset_path;
	IExecutionEvent* executionEvent;

private:
	void OnStartTask() override;
};

