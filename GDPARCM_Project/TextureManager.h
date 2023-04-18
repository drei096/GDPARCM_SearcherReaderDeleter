#pragma once
#include <SFML/Graphics.hpp>;
#include <unordered_map>
#include "ThreadPool.h"

class IExecutionEvent;

class TextureManager
{
public:
    static TextureManager* getInstance();

    void loadAll();
    sf::Texture* getTexture(std::string key);


private:
    // set constructor to private
    TextureManager();
    // set copy contructor to private
    TextureManager(TextureManager const&) {};
    // assignment operator is private
    TextureManager& operator=(TextureManager const&) {};
    static TextureManager* sharedInstance;


    std::vector<sf::Texture*> base_textureList;
    std::unordered_map<std::string, sf::Texture*> textureMap;

    


public:
    void loadTexture(std::string key, std::string path);
    void loadSingleStreamAsset(int index, IExecutionEvent* execution_event);

public:
    int maxColumns = 28;
    int maxRows = 22;
    int columnGrid = 0;
    int rowGrid = 0;
};

