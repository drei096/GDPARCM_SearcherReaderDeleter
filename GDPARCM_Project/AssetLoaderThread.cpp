#include "AssetLoaderThread.h"

#include "GameObjectManager.h"
#include "IExecutionEvent.h"
#include "TextureManager.h"
#include "TileIconObject.h"
#include "StringUtils.h"



AssetLoaderThread::AssetLoaderThread(std::string path, IExecutionEvent* execution_event)
{
	asset_path = path;
	executionEvent = execution_event;
}

AssetLoaderThread::~AssetLoaderThread()
{
}

void AssetLoaderThread::OnStartTask()
{
	ThreadObject::Sleep(200);

	std::vector<std::string> tokens = StringUtils::split(asset_path, '/');
	std::string assetName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];
	TextureManager::getInstance()->loadTexture(assetName, asset_path, true);


	this->executionEvent->OnFinishedExecution();

	delete this;
}

/*
 * USED WHEN THE CLASS INHERITS THE THREAD OBJECT CLASS
 *
void AssetLoaderThread::Run()
{
	ThreadObject::Sleep(200);

	std::vector<std::string> tokens = StringUtils::split(asset_path, '/');
	std::string assetName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];
	TextureManager::getInstance()->loadTexture(assetName, asset_path, true);
	

	this->executionEvent->OnFinishedExecution();

	delete this;
}
*/
