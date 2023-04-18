#include "TextureManager.h"
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <filesystem>

#include "AssetLoaderThread.h"



TextureManager* TextureManager::sharedInstance = NULL;

TextureManager::TextureManager()
{
	texManager_ThreadPool = new ThreadPool("texManagerThreadPool", 16);
	if (texManager_ThreadPool)
		std::cout << "Texmanagerthreadpool is created" << std::endl;

	this->texManager_ThreadPool->StartScheduler();
}

TextureManager* TextureManager::getInstance()
{
	//initialize only when we need it
	if (sharedInstance == NULL) 
	{
		sharedInstance = new TextureManager();
	}
	return sharedInstance;
}

void TextureManager::loadAll()
{
	//BG TEXTURE
	loadTexture("desert_bg", "Media/Textures/Desert.png", false);
	sf::Texture* bgTex;
	bgTex = getTexture("desert_bg");
	bgTex->setRepeated(true);

	//ADD ALL TEXTURES TO LOAD BELOW
	for(int tileIdx = 0; tileIdx < 480; tileIdx++)
	{
		if(tileIdx < 10)
		{
			std::string idx = "tile00";
			loadTexture(idx + std::to_string(tileIdx), "Media/Streaming/" + idx + std::to_string(tileIdx) + ".png", false);
		}
			
		else if (tileIdx < 100)
		{
			std::string idx = "tile0";
			loadTexture(idx + std::to_string(tileIdx), "Media/Streaming/" + idx + std::to_string(tileIdx) + ".png", false);
		}
			
		else
		{
			std::string idx = "tile";
			loadTexture(idx + std::to_string(tileIdx), "Media/Streaming/" + idx + std::to_string(tileIdx) + ".png", false);
		}
			
	}
	
}

void TextureManager::loadTexture(std::string key, std::string path, bool isStreaming)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	this->textureMap[key].push_back(texture);

	if (isStreaming)
	{
		this->stream_textureList.push_back(texture);
	}
	else
	{
		this->base_textureList.push_back(texture);
	}
}



void TextureManager::loadSingleStreamAsset(int index, IExecutionEvent* execution_event)
{
	
	int file_num = 0;

	for(const auto& entry : std::filesystem::directory_iterator("Media/Streaming/"))
	{
		if(index == file_num)
		{
			std::string path = entry.path().generic_string();
			AssetLoaderThread* asset_loader_thread_action = new AssetLoaderThread(path, execution_event);
			texManager_ThreadPool->ScheduleTask(asset_loader_thread_action);
			break;
		}
		file_num++;
	}
	
}


sf::Texture* TextureManager::getTexture(std::string key)
{
	/*
	if (textureMap[key] != NULL) 
	{
		return textureMap[key];
	}
	else 
	{
		std::cout << "No texture found for " << key;
		return NULL;
	}
	*/
	return NULL;
}

void TextureManager::testFunction()
{
	std::cout << "Hi, I'm single-ton ;D";
}

sf::Texture* TextureManager::getFromTextureMap(const std::string assetName, int frameIndex)
{
	if (!this->textureMap[assetName].empty()) {
		return this->textureMap[assetName][frameIndex];
	}
	else {
		std::cout << "[TextureManager] No texture found for " << assetName << std::endl;
		return NULL;
	}
}

sf::Texture* TextureManager::getStreamTextureFromList(const int index)
{
	return this->stream_textureList[index];
}


