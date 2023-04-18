#pragma once
#include <SFML/Graphics.hpp>;
#include <unordered_map>
#include "ThreadPool.h"

class IExecutionEvent;

class TextureManager
{
public:
    static TextureManager* getInstance();
    void testFunction();

    void loadAll();
    sf::Texture* getTexture(std::string);
    sf::Texture* getFromTextureMap(const std::string assetName, int frameIndex);
    sf::Texture* getStreamTextureFromList(const int index);

private:
    ThreadPool* texManager_ThreadPool = nullptr;

private:
    // set constructor to private
    TextureManager();
    // set copy contructor to private
    TextureManager(TextureManager const&) {};
    // assignment operator is private
    TextureManager& operator=(TextureManager const&) {};
    static TextureManager* sharedInstance;


    std::vector<sf::Texture*> base_textureList;
    std::vector<sf::Texture*> stream_textureList;
    std::unordered_map<std::string, std::vector<sf::Texture*>> textureMap;

    


public:
    void loadTexture(std::string, std::string, bool isStreaming);
    void loadSingleStreamAsset(int index, IExecutionEvent* execution_event);

public:
    int maxColumns = 28;
    int maxRows = 22;
    int columnGrid = 0;
    int rowGrid = 0;
};

