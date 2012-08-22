//
//  Rect.h
//  Engine
//
//  Created by Skyler Burwell on 8/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Engine_Rect_h
#define Engine_Rect_h

#include "Vector.h"

struct Rect {
    float x, y, width, height;
    
    Rect(float x, float y, float width, float height);
    Rect();
};

Rect newRect(float x, float y, float width, float height);

struct Rectv {
    Vector2f pos;
    float width, height;
    
    Rectv(Vector2f pos, float width, float height);
    Rectv();
};

Rectv newRect(Vector2f pos, float width, float height);

#endif
