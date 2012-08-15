//
//  Camera.h
//  Engine
//
//  Created by Skyler Burwell on 7/27/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_Camera_h
#define Engine_Camera_h

#include "SDL.h"
#include "Define.h"
#include "Vector.h"

enum {
    TARGET_MODE_NORMAL = 0,
    TARGET_MODE_CENTER
};

class Camera {
private:
    Vector2i pos;
    int x;
    int y;
    
    Vector2f *targetPos;
    float *targetX;
    float *targetY;
    
public:
    static Camera cameraControl;
    
    int targetMode;
    
    Camera();
    
    void onMove(int moveX, int moveY);
    void onMove(Vector2i newPos);
    
    Vector2f getPosition();
    Vector2f getNegativePos();
    int getX();
    int getY();
    
    void setPos(int x, int y);
    void setPos(Vector2i pos);
    
    void setTarget(float *x, float *y);
    void setTarget(Vector2f *targetPos);
};

#endif
