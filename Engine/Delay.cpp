//
//  Delay.cpp
//  Engine
//
//  Created by Skyler Burwell on 9/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Main.h"

Uint32 delayReolution = 10; 

void Engine::delay(Uint32 delayTime) {
    Uint32 startTime = SDL_GetTicks();
    Sint32 burnTime = delayTime;
    Uint32 safeDelayTime;
    
    if (delayTime >= delayReolution) {
        safeDelayTime = delayTime - (delayTime % delayReolution);
        SDL_Delay(safeDelayTime);
        burnTime = Sint32 (delayTime - (SDL_GetTicks() - startTime));
    }
    
    while (burnTime > 0) {
        burnTime = delayTime - (SDL_GetTicks() - startTime);
    }
}

Uint32 Engine::initDelay() {
    SDL_Delay(10);
    delayReolution = SDL_GetTicks();
    SDL_Delay(1);
    delayReolution = SDL_GetTicks() - delayReolution;
    
    return delayReolution;
}