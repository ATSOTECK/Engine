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
    GLuint texture;
    
public:
    static Area areaControl;
    
    std::vector<Map> mapList;
    
    Area();
    
    bool onLoad(std::string file);
    void onRender(int cameraX, int cameraY);
    void onRender(Vector2f cameraPos);
    void onCleanup();
    
    Map *getMap(int x, int y);
    Map *getMap(Vector2i pos);
    
    Tile *getTile(int x, int y);
    Tile *getTile(Vector2i pos);
};

#endif
