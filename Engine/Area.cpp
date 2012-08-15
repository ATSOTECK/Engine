//
//  Area.cpp
//  Engine
//
//  Created by Skyler Burwell on 7/27/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include "Area.h"

Area Area::areaControl;

Area::Area() {
    areaSize = 0;
}

bool Area::onLoad(std::string file) {
    mapList.clear();
    
    FILE *fileHandle = fopen(file.c_str(), "r");
    
    if (fileHandle == NULL) {
        Debug::error(Debug::ENGINE, Debug::CRITICAL, "Could not load %s!", file.c_str());
        return false;
    }
    
    char tilesetFile[255];
    
    fscanf(fileHandle, "%s\n", &tilesetFile);
    
    texture = Texture::loadTexture(tilesetFile);
    
    fscanf(fileHandle, "%d\n", &areaSize);
    
    for (int x = 0; x < areaSize; x++) {
        for (int y = 0; y < areaSize; y++) {
            char mapFile[255];
            
            fscanf(fileHandle, "%s", mapFile);
            
            Map tempMap;
            
            if (tempMap.onLoad(mapFile) == false) {
                fclose(fileHandle);
                
                return false;
            }
            
            tempMap.texture = texture;
            glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &tempMap.tilesetWidth);
            glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &tempMap.tilesetHeight);
            
            mapList.push_back(tempMap);
        }
        fscanf(fileHandle, "\n");
    }
    fclose(fileHandle);
    
    return true;
}

void Area::onRender(int camreaX, int cameraY) {
    int mapWidth = MAP_WIDTH * TILE_SIZE;
    int mapHeight = MAP_HEIGHT * TILE_SIZE;
    
    int firstID = -camreaX / mapWidth;
    firstID += ((-cameraY / mapHeight) * areaSize);
    
    for (int i = 0; i < 4; i++) {
        int ID = firstID + ((i / 2) * areaSize) + (i % 2);
        
        if (ID < 0 || ID > mapList.size()) {
            continue;
        }
        
        int x = ((ID % areaSize) * mapWidth) + camreaX;
        int y = ((ID / areaSize) * mapHeight) + cameraY;
        
        mapList[ID].onRender(x, y);
    }
}

void Area::onRender(Vector2f cameraPos) {
    onRender(cameraPos.x, cameraPos.y);
}

Map *Area::getMap(int x, int y) {
    int mapWidth = MAP_WIDTH * TILE_SIZE;
    int mapHeight = MAP_HEIGHT * TILE_SIZE;
    
    int ID = x / mapWidth;
    ID += ((y / mapHeight) *areaSize);
    
    if (ID < 0 || ID >= mapList.size()) {
        return NULL;
    }
    
    return &mapList[ID];
}

Map *Area::getMap(Vector2i pos) {
    return getMap(pos.x, pos.y);
}

Tile *Area::getTile(int x, int y) {
    int mapWidth = MAP_WIDTH * TILE_SIZE;
    int mapHeight = MAP_WIDTH * TILE_SIZE;
    
    Map *map = getMap(x, y);
    
    x %= mapWidth;
    y %= mapHeight;
    
    return map->getTile(x, y);
}

Tile *Area::getTile(Vector2i pos) {
    return getTile(pos.x, pos.y);
}

void Area::onCleanup() {
    glDeleteTextures(1, &texture);
    
    mapList.clear();
}