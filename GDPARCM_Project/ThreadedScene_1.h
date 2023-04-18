#pragma once

#include "AScene.h"

class ThreadedScene_1 : public AScene
{
public:
	ThreadedScene_1();
	~ThreadedScene_1();

	void onLoadResources();
	void onLoadObjects();

	void onUnloadResources();
};

