#pragma once
#include "AComponent.h"

class SceneBGMovement : public AComponent
{
public:
	SceneBGMovement(string name);
	~SceneBGMovement();
	void perform();

private:
	const float SPEED_MULTIPLIER = 300.0f;
};

