//
//  Map.cpp
//  Engine
//
//  Created by Skyler Burwell on 7/27/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#include <stdio.h>
#include "Map.h"

Map::Map() {
    tilesetSurface = NULL;
}

bool Map::onLoad(char *file) {
    tileList.clear();
    
    FILE *fileHandle = fopen(file, "r");
    
    if (fileHandle == NULL) {
        fprintf(stderr, "Could not load %s!", file);
        return false;
    }
    
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            Tile tempTile;
            
            fscanf(fileHandle, "%d:%d", &tempTile.tileID, &tempTile.typeID);
            
            tileList.push_back(tempTile);
        }
        fscanf(fileHandle, "\n");
    }
    fclose(fileHandle);
    
    return true;
}

void Map::onRender(SDL_Surface *display, int mapx, int mapy) {
    if (tilesetSurface == NULL) {
        return;
    }
    
    int tilesetWidth = tilesetSurface->w / TILE_SIZE;
    int tilesetHeight = tilesetSurface->h / TILE_SIZE;
    
    int ID = 0;
    
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (tileList[ID].typeID == TILE_TYPE_NONE) {
                ID++;
                continue;
            }
            
            int tx = mapx + (x * TILE_SIZE);
            int ty = mapy + (y * TILE_SIZE);
            
            int tilesetX = (tileList[ID].tileID % tilesetWidth) * TILE_SIZE;
            int tilesetY = (tileList[ID].tileID / tilesetHeight) * TILE_SIZE;
            
            Surface::onDraw(display, tilesetSurface, tx, ty, tilesetX, tilesetY, TILE_SIZE, TILE_SIZE);
            
            ID++;
        }
    }
}

Tile *Map::getTile(int x, int y) {
    int ID = 0;
    
    ID = x / TILE_SIZE;
    ID += (MAP_WIDTH * (y /TILE_SIZE));
    
    if (ID < 0 || ID >= tileList.size()) {
        return NULL;
    }
    
    return &tileList[ID];
}
