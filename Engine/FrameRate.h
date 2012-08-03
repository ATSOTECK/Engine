//
//  FrameRate.h
//  Engine
//
//  Created by Skyler Burwell on 7/31/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_FrameRate_h
#define Engine_FrameRate_h

#include "SDL.h"

class FrameRate {
private:
    int oldTime;
    int lastTime;
    
    float speedFactor;
    
    int numFrames;
    int frames;
    
public:
    static FrameRate FPSControl;
    
    FrameRate();
    
    void onLoop();
    
    int getFPS();
    
    float getSpeedFactor();
};

#endif
