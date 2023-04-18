#include "SceneBGMovement.h"
#include "Application.h"
#include "AGameObject.h"
SceneBGMovement::SceneBGMovement(string name) : AComponent(name, Script)
{

}

SceneBGMovement::~SceneBGMovement()
{
	AComponent::~AComponent();
}

void SceneBGMovement::perform()
{
	//make BG scroll slowly
	sf::Vector2f offset(0.0f, 0.0f);
	offset.y += SPEED_MULTIPLIER;
	this->getOwner()->getTransformable()->move(offset * deltaTime.asSeconds());


	sf::Vector2f localPos = this->getOwner()->getTransformable()->getPosition();
	if (localPos.y * deltaTime.asSeconds() > 0) {
		//reset position
		this->getOwner()->getTransformable()->setPosition(0, -Application::WINDOW_HEIGHT * 7);
	}

}