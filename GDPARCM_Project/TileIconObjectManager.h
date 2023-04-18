#pragma once

#include "TextureManager.h"
#include "TileIconObject.h"
#include "ArrowIndicatorObject.h"

class TileIconObjectManager
{
public:
    static TileIconObjectManager* getInstance();

private:
    // set constructor to private
    TileIconObjectManager();
    // set copy contructor to private
    TileIconObjectManager(TileIconObjectManager const&) {};
    // assignment operator is private
    TileIconObjectManager& operator=(TileIconObjectManager const&) {};
    static TileIconObjectManager* sharedInstance;

public:
    int maxDisplayedIconsCount = 10;
    int maxIconBankCount = 10;

    std::vector<TileIconObject*> displayedIconObjectsList;
    std::vector<TileIconObject*> iconObjectBank;
    std::vector<ArrowIndicatorObject*> arrowIndicatorList;

    std::queue<TileIconObject*> deletedIconList;

    std::vector<sf::Vector2f> displayedIconObjectsPositionList;
    std::vector<sf::Vector2f> iconObjectBankPositionList;

public:
    void loadAllIcons();
    void drawAllIcons(sf::RenderWindow* window);

private:
    int currColumn = 0;
};

