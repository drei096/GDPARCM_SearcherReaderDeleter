#pragma once

#include "ThreadObject.h"
#include "SearchInsertDeleteObject.h"
#include "ArrowIndicatorObject.h"

class SearchInsertDeleteObject;

class InserterThread : public ThreadObject
{
public:
	InserterThread(SearchInsertDeleteObject* SID_Object, int ID);
	~InserterThread();

	void Run() override;

private:
	SearchInsertDeleteObject* SID_Object;
	int threadID = 0;

	ArrowIndicatorObject* arrowIndicator;

	void insertToList();
};

