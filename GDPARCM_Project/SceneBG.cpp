#include "SceneBG.h"
#include <string>
#include <iostream>
#include "TextureManager.h"
#include "Application.h"
#include "Renderer.h"
#include "SceneBGMovement.h"

SceneBG::SceneBG(std::string name) : AGameObject(name) {}

void SceneBG::initialize()
{
	std::cout << "Declared as " << this->getName() << "\n";

	//assign texture
	sf::Sprite* sprite = new sf::Sprite();
	sf::Texture* texture = new sf::Texture();
	TextureManager::getInstance()->loadTexture("desert_bg", "Media/Textures/Desert.png", false);
	texture = TextureManager::getInstance()->getFromTextureMap("desert_bg", 0);
	texture->setRepeated(true);
	//TextureManager::getInstance()->getTexture("desert_bg")->setRepeated(true);

	sprite->setTexture(*texture);
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	//make BG height x k to emulate repeating BG.
	sprite->setTextureRect(sf::IntRect(0, 0, Application::WINDOW_WIDTH, Application::WINDOW_HEIGHT * 8));
	getTransformable()->setPosition(0, -Application::WINDOW_HEIGHT * 7);

	SceneBGMovement* movement = new SceneBGMovement("BG_Movement");
	this->attachComponent(movement);

	Renderer* renderer = new Renderer("BG");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);
}