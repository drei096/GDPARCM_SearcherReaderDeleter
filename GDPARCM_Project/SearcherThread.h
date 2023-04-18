#pragma once

#include "ThreadObject.h"
#include "SearchInsertDeleteObject.h"
#include "ArrowIndicatorObject.h"

class SearchInsertDeleteObject;

class SearcherThread : public ThreadObject
{
public:
	SearcherThread(SearchInsertDeleteObject* SID_Object, int ID);
	~SearcherThread();

	void Run() override;

private:
	SearchInsertDeleteObject* SID_Object;
	int threadID = 0;
	int currSearchIndex = 0;

	ArrowIndicatorObject* arrowIndicator;

	void searchList();
};

