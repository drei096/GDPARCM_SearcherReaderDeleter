#include "SceneBG.h"
#include <string>
#include <iostream>
#include "TextureManager.h"
#include "Application.h"
#include "Renderer.h"

SceneBG::SceneBG(std::string name) : AGameObject(name) {}

void SceneBG::initialize()
{

	//assign texture
	sf::Sprite* sprite = new sf::Sprite();
	sf::Texture* texture = new sf::Texture();
	texture = TextureManager::getInstance()->getTexture("desert_bg");

	sprite->setTexture(*texture);
	


	Renderer* renderer = new Renderer("BG");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);
}