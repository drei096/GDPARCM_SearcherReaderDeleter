#include "ConsoleSynchronizer.h"

#include <iostream>

void ConsoleSynchronizer::Update()
{
	std::cout << consoleMessage << std::endl;
}

void ConsoleSynchronizer::UpdateMessage(std::string message)
{
	this->mutex->acquire();
	this->consoleMessage += message + "\n";
	this->mutex->release();
}
