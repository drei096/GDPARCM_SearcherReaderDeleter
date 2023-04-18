#include "ThreadedScene_1.h"
#include "GameObjectManager.h"
#include "TextureManager.h"
#include "SceneBG.h"
#include "TileIconObject.h"
#include "IconLoader.h"
#include "AssetLoaderThread.h"

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

    IconLoader* icon_loader = new IconLoader();
    this->registerObject(icon_loader);
}

void ThreadedScene_1::onUnloadResources()
{
    GameObjectManager::getInstance()->deleteAllObjectsInScene();
}