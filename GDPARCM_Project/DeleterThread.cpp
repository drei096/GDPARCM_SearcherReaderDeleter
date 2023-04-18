#include "DeleterThread.h"

#include <random>
#include <fstream>

#include "GameObjectManager.h"
#include "TileIconObjectManager.h"

DeleterThread::DeleterThread(SearchInsertDeleteObject* SID_Object, int ID)
{
	this->SID_Object = SID_Object;
	this->threadID = ID;

	arrowIndicator = new ArrowIndicatorObject("deleter_icon");
	arrowIndicator->setPosition(TileIconObjectManager::getInstance()->displayedIconObjectsList[0]->getTransformable()->getPosition().x, 68 * (6 + threadID));
	GameObjectManager::getInstance()->addObject(arrowIndicator);
}

DeleterThread::~DeleterThread()
{
}

void DeleterThread::Run()
{
	while(true)
	{
		ThreadObject::Sleep(100);

		/*
		SID_Object->turnStile->acquire();
		SID_Object->roomEmpty->acquire();
		SID_Object->mutexSem->acquire();
		*/

		//SID_Object->deleterTurnstile->acquire();
		//SID_Object->deleterTurnstile->release();
		SID_Object->mutexSem->acquire();

		deleteFromList();

		SID_Object->inserterTurnstile->release();
		SID_Object->mutexSem->release();
		
		/*
		SID_Object->inserterTurnstile->release();
		SID_Object->turnStile->release();
		SID_Object->roomEmpty->release();
		SID_Object->mutexSem->release();
		*/

		
	}
}

void DeleterThread::deleteFromList()
{
	srand((unsigned)time(NULL));

	auto tileIconManager = TileIconObjectManager::getInstance();

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, tileIconManager->displayedIconObjectsList.size() - 1);

	int randomIdx = dist(gen);


	if(tileIconManager->displayedIconObjectsList[randomIdx] != nullptr)
	{
		//assign arrow to specific idx
		arrowIndicator->setPosition(tileIconManager->displayedIconObjectsList[randomIdx]->getTransformable()->getPosition().x, 68 * (6 + threadID));

		//push back the icon object to the deleted icon list
		tileIconManager->deletedIconList.emplace(tileIconManager->displayedIconObjectsList[randomIdx]);

		//erase the icon object from the displayedIconList
		tileIconManager->displayedIconObjectsList.erase(tileIconManager->displayedIconObjectsList.begin() + randomIdx);
		std::cout << "Deleter thread " << threadID << " deleted at index: " << randomIdx << std::endl;
		this->SID_Object->outputFile << "Deleter thread " << threadID << " deleted at index: " << randomIdx << std::endl;

		//put the idx to the deletedIdx queue
		this->SID_Object->deletedIndexQueue.push(randomIdx);

	}
		

	ThreadObject::Sleep(100);
}
