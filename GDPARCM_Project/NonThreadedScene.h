#pragma once
#include "AScene.h"


class NonThreadedScene : public AScene
{
public:
	NonThreadedScene();
	~NonThreadedScene();

	void onLoadResources();
	void onLoadObjects();

	void onUnloadResources();
};

