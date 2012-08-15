//
//  Map.h
//  Engine
//
//  Created by Skyler Burwell on 7/27/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_Map_h
#define Engine_Map_h

#include "SDL.h"
#include "SDL_opengl.h"
#include <vector>

#include "Tile.h"
#include "Surface.h"
#include "Texture.h"
#include "Vector.h"

class Map {
private:
    std::vector<Tile> tileList;
    
public:
    GLuint texture;
    
    int tilesetWidth, tilesetHeight;
    
    Map();
    
    bool onLoad(char *file);
    void onRender(int mapx, int mapy);
    void onRender(Vector2i mapPos);
    
    Tile *getTile(int x, int y);
    Tile *getTile(Vector2i pos);
};

#endif
