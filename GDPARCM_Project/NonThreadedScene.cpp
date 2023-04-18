#include "NonThreadedScene.h"

#include "GameObjectManager.h"
#include "TextureManager.h"
#include "SceneBG.h"
#include "TileIconObject.h"
#include "IconLoader.h"

NonThreadedScene::NonThreadedScene() : AScene("NonThreadedScene")
{
}

NonThreadedScene::~NonThreadedScene()
{
}

void NonThreadedScene::onLoadResources()
{
    TextureManager::getInstance()->loadAll();
}

void NonThreadedScene::onLoadObjects()
{

    SceneBG* bgObject = new SceneBG("BGObject");
    this->registerObject(bgObject);

    IconLoader* loader = new IconLoader();
    this->registerObject(loader);


}

void NonThreadedScene::onUnloadResources()
{
    GameObjectManager::getInstance()->deleteAllObjectsInScene();
}