#include "SearcherThread.h"

#include <random>

#include "Application.h"
#include "GameObjectManager.h"
#include "TileIconObjectManager.h"
#include "Utils.h"

SearcherThread::SearcherThread(SearchInsertDeleteObject* SID_Object, int ID)
{
	this->SID_Object = SID_Object;
	this->threadID = ID;

	arrowIndicator = new ArrowIndicatorObject("searcher_icon");
	arrowIndicator->setPosition(TileIconObjectManager::getInstance()->displayedIconObjectsList[0]->getTransformable()->getPosition().x, 68 * (2 + threadID));
	GameObjectManager::getInstance()->addObject(arrowIndicator);
}

SearcherThread::~SearcherThread()
{
}

void SearcherThread::Run()
{
	while(true)
	{
		ThreadObject::Sleep(100);

		/*
		this->SID_Object->turnStile->acquire();
		this->SID_Object->turnStile->release();

		this->SID_Object->mutexSem->acquire();
		this->SID_Object->currSearchersCount++;
		if (this->SID_Object->currSearchersCount == 1)
			this->SID_Object->roomEmpty->acquire();
		this->SID_Object->mutexSem->release();
		*/

		//call search here
		searchList();
		this->currSearchIndex = 0;

		/*
		this->SID_Object->mutexSem->acquire();
		this->SID_Object->currSearchersCount--;
		if (this->SID_Object->currSearchersCount == 0)
			this->SID_Object->roomEmpty->release();
		this->SID_Object->mutexSem->release();
		*/

		
	}
}

void SearcherThread::searchList()
{
	srand((unsigned)time(NULL));

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, TileIconObjectManager::getInstance()->maxDisplayedIconsCount);

	int randomIdx = dist(gen);

	while(this->currSearchIndex != randomIdx)
	{
		arrowIndicator->setPosition(TileIconObjectManager::getInstance()->displayedIconObjectsPositionList[currSearchIndex].x, 68 * (2 + threadID));
		

		this->currSearchIndex++;



		
		ThreadObject::Sleep(100);
	}
}
