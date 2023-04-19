#include "SearchInsertDeleteObject.h"
#include "TileIconObjectManager.h"

SearchInsertDeleteObject::SearchInsertDeleteObject(std::string name, std::string fileName) : AGameObject(name), outputFile(fileName)
{
}

SearchInsertDeleteObject::~SearchInsertDeleteObject()
{
}

void SearchInsertDeleteObject::initialize()
{
	TileIconObjectManager::getInstance()->loadAllIcons();


	this->mutexSem = new SemaphoreObject(1);
	this->turnStile = new SemaphoreObject(1);
	this->roomEmpty = new SemaphoreObject(1);
	this->inserterTurnstile = new SemaphoreObject(0);

	for (int i = 0; i < this->maxDeletersCount; i++)
	{
		DeleterThread* d_thread = new DeleterThread(this, i);
		d_thread->ScheduleThreadForExecution();
	}
	for (int i = 0; i < this->maxInsertersCount; i++)
	{
		InserterThread* i_thread = new InserterThread(this, i);
		i_thread->ScheduleThreadForExecution();
	}
	for(int i = 0; i < this->maxSearchersCount; i++)
	{
		SearcherThread* s_thread = new SearcherThread(this, i);
		s_thread->ScheduleThreadForExecution();
	}
	
	
}

void SearchInsertDeleteObject::processInput(sf::Event evnet)
{
}

void SearchInsertDeleteObject::update(sf::Time deltaTime)
{
}




