#pragma once

#include "ThreadObject.h"

class InserterThread : public ThreadObject
{
public:
	InserterThread();
	~InserterThread();

	void Run() override;
};

