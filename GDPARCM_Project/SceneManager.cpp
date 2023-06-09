#include "SceneManager.h"
#include <iostream>

string SceneManager::NON_THREADED_SCENE_NAME = "NonThreadedScene";
string SceneManager::THREADED_SCENE_1_NAME = "ThreadedScene_1";

SceneManager* SceneManager::sharedInstance = NULL;

using namespace std;
SceneManager* SceneManager::getInstance()
{
	if (sharedInstance == NULL) {
		sharedInstance = new SceneManager();
	}

	return sharedInstance;
}

void SceneManager::registerScene(AScene* scene)
{
	//std::cout << scene->getSceneName() << " registered! \n";
	this->storedScenes[scene->getSceneName()] = scene;
}


void SceneManager::checkLoadScene() {
	if (this->isLoading) {
		this->unloadScene();
		this->activeScene = this->storedScenes[this->toLoadSceneName];
		this->activeScene->onLoadResources();
		this->activeScene->onLoadObjects();
		this->isLoading = false;

	}
}

void SceneManager::loadScene(string name)
{
	this->isLoading = true;
	this->toLoadSceneName = name;
	//put a loading screen!

}

void SceneManager::unloadScene()
{
	if (this->activeScene != NULL) {
		this->activeScene->onUnloadObjects();
		this->activeScene->onUnloadResources();
	}
}

bool SceneManager::isSceneLoaded(string name)
{
	return this->activeScene->getSceneName() == name;
}


/*void SceneManager::unloadAllActiveScenes()
{
	SceneList activeList;
	activeList.reserve(this->activeScenes.size());
	for (auto kv : this->activeScenes) {
		activeList.push_back(kv.first);
	}
	for (int i = 0; i < activeList.size(); i++) {
		this->unloadScene(activeList[i]);
	}
}*/