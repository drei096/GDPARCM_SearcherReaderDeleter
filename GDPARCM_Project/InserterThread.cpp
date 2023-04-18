#include "InserterThread.h"

#include <random>
#include <fstream>

#include "GameObjectManager.h"
#include "TileIconObjectManager.h"

InserterThread::InserterThread(SearchInsertDeleteObject* SID_Object, int ID)
{
	this->SID_Object = SID_Object;
	this->threadID = ID;

	arrowIndicator = new ArrowIndicatorObject("inserter_icon");
	arrowIndicator->setPosition(TileIconObjectManager::getInstance()->displayedIconObjectsList[0]->getTransformable()->getPosition().x, 68 * (7 + threadID));
	GameObjectManager::getInstance()->addObject(arrowIndicator);
}

InserterThread::~InserterThread()
{
}

void InserterThread::Run()
{
	while (true)
	{
		ThreadObject::Sleep(100);

		this->SID_Object->inserterTurnstile->acquire();
		this->SID_Object->mutexSem->acquire();

		insertToList();

		this->SID_Object->mutexSem->release();

		
	}
}

void InserterThread::insertToList()
{
	srand((unsigned)time(NULL));

	auto tileIconManager = TileIconObjectManager::getInstance();

	if(this->SID_Object->deletedIndexQueue.empty() == false)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(0, TileIconObjectManager::getInstance()->maxDisplayedIconsCount);

		int randomIdx = dist(gen);


		int insertIndex = this->SID_Object->deletedIndexQueue.front();
		this->SID_Object->deletedIndexQueue.pop();

		arrowIndicator->setPosition(tileIconManager->displayedIconObjectsPositionList[insertIndex].x, 68 * (7 + threadID));

		//place the front of the icon bank to the deleted area
		tileIconManager->displayedIconObjectsList.emplace(tileIconManager->displayedIconObjectsList.begin() + insertIndex, tileIconManager->iconObjectBank.front());
		tileIconManager->displayedIconObjectsList[insertIndex]->setPosition(tileIconManager->displayedIconObjectsPositionList[insertIndex].x, tileIconManager->displayedIconObjectsPositionList[insertIndex].y);
		std::cout << "Inserter thread " << threadID << " inserted at index: " << insertIndex << std::endl;
		this->SID_Object->outputFile << "Inserter thread " << threadID << " inserted at index: " << insertIndex << std::endl;

		//delete the front of the icon bank
		tileIconManager->iconObjectBank.erase(tileIconManager->iconObjectBank.begin());

		//push to back of icon bank yung deleted icon from display
		tileIconManager->iconObjectBank.push_back(tileIconManager->deletedIconList.front());

		//pop the front of the deleted icon list queue
		tileIconManager->deletedIconList.pop();
	}
	

	
	
		

	ThreadObject::Sleep(100);
}
