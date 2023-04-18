#include "ArrowIndicatorObject.h"

#include "Renderer.h"
#include "TextureManager.h"

ArrowIndicatorObject::ArrowIndicatorObject(std::string name) : AGameObject(name)
{
}

void ArrowIndicatorObject::initialize()
{
	//assign texture
	sf::Sprite* sprite = new sf::Sprite();

	sf::Texture* texture = TextureManager::getInstance()->getTexture(this->name);
	sprite->setTexture(*texture);


	Renderer* renderer = new Renderer(tileName + "_renderer");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);
}

void ArrowIndicatorObject::processInput(sf::Event evnet)
{
}

void ArrowIndicatorObject::update(sf::Time deltaTime)
{
}
