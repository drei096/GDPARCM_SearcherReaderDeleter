#pragma once

#include "AGameObject.h"
#include "IExecutionEvent.h"

class TileIconObject;

class IconLoader : public AGameObject, public IExecutionEvent
{
public:
	IconLoader();
	void initialize();
	void update(sf::Time deltaTime);
	void OnFinishedExecution() override;

private:
	std::vector<TileIconObject*> tileIconList;
	int maxColumns = 28;
	int maxRows = 22;
	int columnGrid = 0;
	int rowGrid = 0;
	float loadTicks = 0.0f;
	int tileIdx = 0;


private:
	void displayIcon();
	void createIconObjects(sf::Time deltaTime, float loadTicks);
};

