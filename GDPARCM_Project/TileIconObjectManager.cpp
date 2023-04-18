#include "TileIconObjectManager.h"
#include <cstddef>
#include <iostream>
#include <iomanip>

TileIconObjectManager* TileIconObjectManager::sharedInstance = NULL;

TileIconObjectManager::TileIconObjectManager()
{
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
