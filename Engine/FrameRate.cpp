//
//  FrameRate.cpp
//  Engine
//
//  Created by Skyler Burwell on 7/31/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "FrameRate.h"

FrameRate FrameRate::FPSControl;

FrameRate::FrameRate() {
    oldTime = 0;
    lastTime = 0;
    
    speedFactor = 0;
    
    frames = 0;
    numFrames = 0;
}

void FrameRate::onLoop() {
    if (oldTime + 1000 < SDL_GetTicks()) {
        oldTime = SDL_GetTicks();
        
        numFrames = frames;
        
        frames = 0;
    }
    
    speedFactor = ((SDL_GetTicks() -lastTime) / 1000.0f) * 60.0f;
    
    lastTime = SDL_GetTicks();
    
    frames++;
}

int FrameRate::getFPS() {
    return numFrames;
}

float FrameRate::getSpeedFactor() {
    //return 0.0f;
    return speedFactor;
}