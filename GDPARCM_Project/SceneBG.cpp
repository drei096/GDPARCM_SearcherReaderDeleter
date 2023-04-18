#include "SceneBG.h"
#include <string>
#include <iostream>
#include "TextureManager.h"
#include "Application.h"
#include "Renderer.h"

SceneBG::SceneBG(std::string name) : AGameObject(name) {}

void SceneBG::initialize()
{
	std::cout << "Declared as " << this->getName() << "\n";

	//assign texture
	sf::Sprite* sprite = new sf::Sprite();
	sf::Texture* texture = new sf::Texture();
	TextureManager::getInstance()->loadTexture("desert_bg", "Media/Textures/Desert.png", false);
	texture = TextureManager::getInstance()->getFromTextureMap("desert_bg", 0);

	sprite->setTexture(*texture);
	


	Renderer* renderer = new Renderer("BG");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);
}