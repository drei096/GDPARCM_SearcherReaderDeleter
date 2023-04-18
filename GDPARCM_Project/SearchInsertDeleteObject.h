#pragma once

#include "AGameObject.h"
#include "SearcherThread.h"
#include "InserterThread.h"
#include "DeleterThread.h"
#include "SemaphoreObject.h"

class SearchInsertDeleteObject : public AGameObject
{
public:
	SearchInsertDeleteObject(std::string name);
	~SearchInsertDeleteObject();

	//no need to call manually
	void initialize() override;
	void processInput(sf::Event evnet) override;
	void update(sf::Time deltaTime) override;

private:
	int maxSearchersCount = 4;
	int maxInsertersCount = 2;
	int maxDeletersCount = 1;

	int currSearchersCount = 0;
	int currInsertersCount = 0;
	int currDeletersCount = 0;
};

