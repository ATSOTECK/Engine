//
//  Player.h
//  Engine
//
//  Created by Skyler Burwell on 8/1/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_Player_h
#define Engine_Player_h

#include <string.h>
#include "Entity.h"

class Player : public Entity {
public:
    Player();
    
    bool onLoad(std::string file, int width, int height, int maxFrames);
    void onLoop();
    void onRender(SDL_Surface *displaySurface);
    void onCleanup();
    void onAnimate();
    bool onCollision(Entity *entity);
};

#endif
