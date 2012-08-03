//
//  Area.h
//  Engine
//
//  Created by Skyler Burwell on 7/27/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_Area_h
#define Engine_Area_h

#include <string.h>
#include "Map.h"

class Area {
private:
    int areaSize;
    SDL_Surface *tilesetSurface;
    
public:
    static Area areaControl;
    
    std::vector<Map> mapList;
    
    Area();
    
    bool onLoad(std::string file);
    void onRender(SDL_Surface *display, int cameraX, int cameraY);
    void onCleanup();
    
    Map *getMap(int x, int y);
    Tile *getTile(int x, int y);
};

#endif
