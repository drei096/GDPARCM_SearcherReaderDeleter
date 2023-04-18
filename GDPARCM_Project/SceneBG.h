#pragma once
#include "AGameObject.h"
class SceneBG : public AGameObject
{
public:
	SceneBG(std::string name);
	void initialize();
private:
	const float SPEED_MULTIPLIER = 100.0f;
};

