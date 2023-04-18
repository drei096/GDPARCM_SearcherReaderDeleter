#pragma once
class IFinishedTask
{
public:
	virtual void OnFinishedTask(int threadID) = 0;
};

