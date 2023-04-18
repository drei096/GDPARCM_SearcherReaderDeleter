#include "TextureManager.h"
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <filesystem>

#include "AssetLoaderThread.h"



TextureManager* TextureManager::sharedInstance = NULL;

TextureManager::TextureManager()
{
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
	loadTexture("desert_bg", "Media/Textures/Desert.png");

	//SEARCHER, INSERTER, DELETER ICONS
	loadTexture("searcher_icon", "Media/Textures/searcher_icon.png");
	loadTexture("inserter_icon", "Media/Textures/inserter_icon.png");
	loadTexture("deleter_icon", "Media/Textures/deleter_icon.png");
	
	//ADD ALL TEXTURES TO LOAD BELOW
	for(int tileIdx = 0; tileIdx < 480; tileIdx++)
	{
		if(tileIdx < 10)
		{
			std::string idx = "tile00";
			loadTexture(idx + std::to_string(tileIdx), "Media/Streaming/" + idx + std::to_string(tileIdx) + ".png");
		}
			
		else if (tileIdx < 100)
		{
			std::string idx = "tile0";
			loadTexture(idx + std::to_string(tileIdx), "Media/Streaming/" + idx + std::to_string(tileIdx) + ".png");
		}
			
		else
		{
			std::string idx = "tile";
			loadTexture(idx + std::to_string(tileIdx), "Media/Streaming/" + idx + std::to_string(tileIdx) + ".png");
		}
	}
	
}

void TextureManager::loadTexture(std::string key, std::string path)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);

	this->base_textureList.push_back(texture);
	textureMap[key] = texture;
}



void TextureManager::loadSingleStreamAsset(int index, IExecutionEvent* execution_event)
{
	/*
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
	*/

}


sf::Texture* TextureManager::getTexture(std::string key)
{
	
	if (textureMap[key] != nullptr) 
	{
		return textureMap[key];
	}
	else 
	{
		std::cout << "No texture found for " << key;
		return nullptr;
	}
}




