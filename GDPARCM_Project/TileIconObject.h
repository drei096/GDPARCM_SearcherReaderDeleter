#pragma once
#include "AGameObject.h"


class TileIconObject : public AGameObject
{
public:
	TileIconObject(std::string name, int tileID);
	void initialize();
	void processInput(sf::Event evnet) override;
	void update(sf::Time deltaTime) override;

private:
	std::string tileName;
	int tileIndex = 0;
};

