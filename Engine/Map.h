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

class Map {
private:
    std::vector<Tile> tileList;
    
public:
    SDL_Surface *tilesetSurface;
    GLuint texture;
    
    Map();
    
    bool onLoad(char *file);
    void onRender(SDL_Surface *display, int mapx, int mapy);
    
    Tile *getTile(int x, int y);
};

#endif
