#include "ThreadedScene_1.h"
#include "GameObjectManager.h"
#include "TextureManager.h"
#include "SceneBG.h"
#include "TileIconObjectManager.h"

ThreadedScene_1::ThreadedScene_1() : AScene("ThreadedScene_1")
{
}

ThreadedScene_1::~ThreadedScene_1()
{
}

void ThreadedScene_1::onLoadResources()
{
    
}

void ThreadedScene_1::onLoadObjects()
{
    SceneBG* bgObject = new SceneBG("BGObject");
    this->registerObject(bgObject);

}

void ThreadedScene_1::onUnloadResources()
{
    GameObjectManager::getInstance()->deleteAllObjectsInScene();
}