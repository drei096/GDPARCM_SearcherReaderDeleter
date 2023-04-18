#pragma once

#include "ThreadObject.h"

class SearcherThread : public ThreadObject
{
public:
	SearcherThread();
	~SearcherThread();

	void Run() override;
};

