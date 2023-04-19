#pragma once

#include "AGameObject.h"
#include "SearcherThread.h"
#include "InserterThread.h"
#include "DeleterThread.h"
#include "SemaphoreObject.h"
#include <queue>
#include <fstream>

class SearchInsertDeleteObject : public AGameObject
{
public:
	SearchInsertDeleteObject(std::string name, std::string fileName);
	~SearchInsertDeleteObject();

	//no need to call manually
	void initialize() override;
	void processInput(sf::Event evnet) override;
	void update(sf::Time deltaTime) override;

private:
	int maxSearchersCount = 4;
	int maxInsertersCount = 2;
	int maxDeletersCount = 1;

public:
	int currSearchersCount = 0;
	int currInsertersCount = 0;
	int currDeletersCount = 0;

	SemaphoreObject* mutexSem;
	SemaphoreObject* turnStile;
	SemaphoreObject* roomEmpty;
	SemaphoreObject* inserterTurnstile;

	std::queue<int> deletedIndexQueue;
	std::queue<int> deletedBankIndexQueue;

	std::ofstream outputFile;
};

