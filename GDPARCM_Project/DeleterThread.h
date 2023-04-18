#pragma once

#include "ThreadObject.h"

class DeleterThread : public ThreadObject
{
public:
	DeleterThread();
	~DeleterThread();

	void Run() override;
};

