#pragma once

#include "ThreadObject.h"
#include "SearchInsertDeleteObject.h"
#include "ArrowIndicatorObject.h"

class SearchInsertDeleteObject;

class DeleterThread : public ThreadObject
{
public:
	DeleterThread(SearchInsertDeleteObject* SID_Object, int ID);
	~DeleterThread();

	void Run() override;

private:
	SearchInsertDeleteObject* SID_Object;
	int threadID = 0;

	ArrowIndicatorObject* arrowIndicator;


	void deleteFromList();
};

