#include "IconLoader.h"

#include "GameObjectManager.h"
#include "TileIconObject.h"
#include "AssetLoaderThread.h"
#include "TextureManager.h"

IconLoader::IconLoader() : AGameObject("IconDisplayer")
{
}

void IconLoader::initialize()
{
	
}

void IconLoader::update(sf::Time deltaTime)
{
	this->loadTicks += deltaTime.asMilliseconds();

	if(this->loadTicks > 30.0f)
	{
		this->loadTicks = 0.0f;
		TextureManager::getInstance()->loadSingleStreamAsset(this->tileIdx, this);
		this->tileIdx++;
	}
	
}

void IconLoader::OnFinishedExecution()
{
	this->displayIcon();
}

void IconLoader::displayIcon()
{
	std::string tileIconName = "Icon_" + std::to_string(this->tileIconList.size());
	TileIconObject* temp = new TileIconObject(tileIconName, this->tileIconList.size());
	tileIconList.push_back(temp);

	int IMG_WIDTH = 68; int IMG_HEIGHT = 68;
	float x = this->columnGrid * IMG_WIDTH;
	float y = this->rowGrid * IMG_HEIGHT;
	temp->setPosition(x, y);


	this->columnGrid++;
	if (this->columnGrid == this->maxColumns)
	{
		this->columnGrid = 0;
		this->rowGrid++;
	}

	GameObjectManager::getInstance()->addObject(temp);
	
	

		
}

void IconLoader::createIconObjects(sf::Time deltaTime, float loadTicks)
{
	/*
	if(loadTicks > 200.0f)
	{
		if (tileIdx < 480)
		{

			if (tileIdx < 10)
			{
				std::string idx = "tile00";
				TileIconObject* temp = new TileIconObject(idx + std::to_string(tileIdx), idx + std::to_string(tileIdx));

				int IMG_WIDTH = 68; int IMG_HEIGHT = 68;
				float x = this->columnGrid * IMG_WIDTH;
				float y = this->rowGrid * IMG_HEIGHT;
				temp->setPosition(x, y);


				this->columnGrid++;
				if (this->columnGrid == this->maxColumns)
				{
					this->columnGrid = 0;
					this->rowGrid++;
				}

				GameObjectManager::getInstance()->addObject(temp);
				tileIconList.push_back(temp);


			}

			else if (tileIdx < 100)
			{
				std::string idx = "tile0";
				TileIconObject* temp = new TileIconObject(idx + std::to_string(tileIdx), idx + std::to_string(tileIdx));

				int IMG_WIDTH = 68; int IMG_HEIGHT = 68;
				float x = this->columnGrid * IMG_WIDTH;
				float y = this->rowGrid * IMG_HEIGHT;
				temp->setPosition(x, y);


				this->columnGrid++;
				if (this->columnGrid == this->maxColumns)
				{
					this->columnGrid = 0;
					this->rowGrid++;
				}

				GameObjectManager::getInstance()->addObject(temp);
				tileIconList.push_back(temp);


			}

			else
			{
				std::string idx = "tile";
				TileIconObject* temp = new TileIconObject(idx + std::to_string(tileIdx), idx + std::to_string(tileIdx));


				int IMG_WIDTH = 68; int IMG_HEIGHT = 68;
				float x = this->columnGrid * IMG_WIDTH;
				float y = this->rowGrid * IMG_HEIGHT;
				temp->setPosition(x, y);


				this->columnGrid++;
				if (this->columnGrid == this->maxColumns)
				{
					this->columnGrid = 0;
					this->rowGrid++;
				}

				GameObjectManager::getInstance()->addObject(temp);
				tileIconList.push_back(temp);


			}

			this->loadTicks = 0.0f;
			tileIdx++;
		}
	}
	*/
	
}
