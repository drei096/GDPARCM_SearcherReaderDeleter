#pragma once

#include "TextureManager.h"
#include "TileIconObject.h"

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
};

