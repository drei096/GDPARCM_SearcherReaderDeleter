#include "SearchInsertDeleteObject.h"

SearchInsertDeleteObject::SearchInsertDeleteObject(std::string name) : AGameObject(name)
{
}

SearchInsertDeleteObject::~SearchInsertDeleteObject()
{
}

void SearchInsertDeleteObject::initialize()
{
	std::cout << "Declared as " << this->getName() << "\n";
}

void SearchInsertDeleteObject::processInput(sf::Event evnet)
{
}

void SearchInsertDeleteObject::update(sf::Time deltaTime)
{
}




