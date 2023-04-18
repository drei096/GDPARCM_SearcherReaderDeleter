#include "TileIconObject.h"
#include <string>
#include <iostream>
#include "TextureManager.h"
#include "Application.h"
#include "Renderer.h"
#include "ThreadObject.h"

TileIconObject::TileIconObject(std::string name, int tileID) : AGameObject(name)
{
	this->tileIndex = tileID;
}

void TileIconObject::initialize()
{
	std::cout << "Declared as " << this->getName() << "\n";

	//assign texture
	sf::Sprite* sprite = new sf::Sprite();

	sf::Texture* texture = TextureManager::getInstance()->getStreamTextureFromList(this->tileIndex);
	sprite->setTexture(*texture);
	

	Renderer* renderer = new Renderer(tileName + "_renderer");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);
}

void TileIconObject::processInput(sf::Event evnet)
{
	
}

void TileIconObject::update(sf::Time deltaTime)
{
	
}
