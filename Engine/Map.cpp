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
    texture = NULL;
    tilesetWidth = tilesetHeight = 0;
}

bool Map::onLoad(char *file) {
    tileList.clear();
    
    FILE *fileHandle = fopen(file, "r");
    
    if (fileHandle == NULL) {
        Debug::error(Debug::ENGINE, Debug::MILD, "Could not load %s!", file);
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

void Map::onRender(int mapx, int mapy) {
    int ID = 0;
    //inneficiant, work on map rendering
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (tileList[ID].typeID == TILE_TYPE_NONE) {
                ID++;
                continue;
            }
            
            int tx = mapx + (x * TILE_SIZE);
            int ty = mapy + (y * TILE_SIZE);
            
            int tempWidth = tilesetWidth / TILE_SIZE;
            int tempHeight = tilesetHeight / TILE_SIZE;
            
            int tilesetX = (tileList[ID].tileID % tempWidth) * TILE_SIZE;
            int tilesetY = (tileList[ID].tileID / tempHeight) * TILE_SIZE;
            
            Texture::onDraw(texture, tx, ty, tilesetWidth, tilesetHeight, tilesetX, tilesetY, TILE_SIZE, TILE_SIZE);
            
            ID++;
        }
    }
}

void Map::onRender(Vector2i mapPos) {
    onRender(mapPos.x, mapPos.y);
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

Tile *Map::getTile(Vector2i pos) {
    return getTile(pos.x, pos.y);
}
