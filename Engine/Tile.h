//
//  Tile.h
//  Engine
//
//  Created by Skyler Burwell on 7/27/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_Tile_h
#define Engine_Tile_h

#include "Define.h"

enum {
    TILE_TYPE_NONE = 0,
    TILE_TYPE_NORMAL,
    TILE_TYPE_BLOCK
};

class Tile {
public:
    int tileID;
    int typeID;
    
    Tile();
};

#endif
