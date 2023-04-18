#include "TileIconObjectManager.h"
#include <cstddef>
#include <iostream>
#include <iomanip>

#include "Application.h"
#include "GameObjectManager.h"

TileIconObjectManager* TileIconObjectManager::sharedInstance = NULL;

TileIconObjectManager::TileIconObjectManager()
{
}

void TileIconObjectManager::loadAllIcons()
{
	//for icon bank
	for(int i = 0; i < maxIconBankCount; i++)
	{
		std::string idxName;
		if (i < 10)
			idxName = "tile00";
		else if (i < 100)
			idxName = "tile0";
		else
			idxName = "tile";

		TileIconObject* new_temp = new TileIconObject(idxName + std::to_string(i), i + 1);
		new_temp->setPosition(currColumn * new_temp->IMAGE_WIDTH + new_temp->IMAGE_WIDTH, 0);
		iconObjectBankPositionList.push_back(new_temp->getTransformable()->getPosition());

		if (currColumn == maxIconBankCount - 1)
			currColumn = 0;
		else
			currColumn++;
		

		iconObjectBank.push_back(new_temp);
		new_temp->initialize();
	}

	//for display icons
	for (int i = maxIconBankCount; i < maxDisplayedIconsCount + maxIconBankCount; i++)
	{
		std::string idxName;
		if (i < 10)
			idxName = "tile00";
		else if (i < 100)
			idxName = "tile0";
		else
			idxName = "tile";

		TileIconObject* new_temp = new TileIconObject(idxName + std::to_string(i), i + 1);
		new_temp->setPosition(currColumn * new_temp->IMAGE_WIDTH + new_temp->IMAGE_WIDTH, new_temp->IMAGE_HEIGHT * 1);
		displayedIconObjectsPositionList.push_back(new_temp->getTransformable()->getPosition());

		if (currColumn == maxIconBankCount - 1)
			currColumn = 0;
		else
			currColumn++;

		
		displayedIconObjectsList.push_back(new_temp);
		new_temp->initialize();
	}
}

void TileIconObjectManager::drawAllIcons(sf::RenderWindow* window)
{
	for (int i = 0; i < displayedIconObjectsList.size(); i++) 
	{
		displayedIconObjectsList[i]->draw(window, sf::RenderStates::Default);
	}
	/*
	for (int i = 0; i < iconObjectBank.size(); i++)
	{
		iconObjectBank[i]->draw(window, sf::RenderStates::Default);
	}
	*/
	for (int i = 0; i < arrowIndicatorList.size(); i++)
	{
		arrowIndicatorList[i]->draw(window, sf::RenderStates::Default);
	}
}

TileIconObjectManager* TileIconObjectManager::getInstance()
{
	//initialize only when we need it
	if (sharedInstance == NULL)
	{
		sharedInstance = new TileIconObjectManager();
	}
	return sharedInstance;
}
