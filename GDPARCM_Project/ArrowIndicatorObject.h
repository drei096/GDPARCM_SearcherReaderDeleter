#pragma once

#include "AGameObject.h"

class ArrowIndicatorObject : public AGameObject
{
public:
	ArrowIndicatorObject(std::string name);
	void initialize();
	void processInput(sf::Event evnet) override;
	void update(sf::Time deltaTime) override;

private:
	std::string tileName;
	int tileIndex = 0;

public:
	const static int IMAGE_HEIGHT = 68;
	const static int IMAGE_WIDTH = 68;
};

