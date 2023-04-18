#pragma once

#include "SemaphoreObject.h"	

class ConsoleSynchronizer
{
private:
	SemaphoreObject* mutex = new SemaphoreObject(1);
	std::string consoleMessage;

public:
	void Update();
	void UpdateMessage(std::string message);
};

